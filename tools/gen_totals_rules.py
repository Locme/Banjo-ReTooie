#!/usr/bin/env python3
"""Generates src/gameplay/totals_rules.inc, the "what can be got now" rules of the Totals checklist
(src/gameplay/totals_checklist.cpp), from the Banjo-Tooie world of the Archipelago randomizer.

    python3 -I tools/gen_totals_rules.py <AP_Banjo-Tooie>/worlds/banjo_tooie lib/bt-decomp/include/gameflags.h \
        src/gameplay/totals_rules.inc

The Archipelago world (https://github.com/jjjj12212/AP_Banjo-Tooie, MIT licence) describes, for every
collectible, which moves, transformations and areas it needs. Its Python is read, never run: this
script parses Rules.py, Regions.py, Locations.py, Names/*.py and WorldOrder.py with the ast module and
translates the rule methods to C++. The randomizer's options are fixed to the unrandomized game
("intended" logic, nothing randomized), so most option checks fold away. Methods that need the
randomizer's own state (world order, silo costs) are written by hand in totals_checklist.cpp
(names starting o_).
"""

import ast
import os
import re
import sys

ap_dir, gameflags_path, out_path = sys.argv[1:4]


def parse(name):
    with open(os.path.join(ap_dir, name), encoding="utf-8") as f:
        return ast.parse(f.read())


def string_consts(tree):
    out = {}
    for node in tree.body:
        if isinstance(node, ast.Assign) and isinstance(node.value, ast.Constant) and isinstance(node.value.value, str):
            for t in node.targets:
                if isinstance(t, ast.Name):
                    out[t.id] = node.value.value
    return out


item_names = string_consts(parse("Names/itemName.py"))
location_names = string_consts(parse("Names/locationName.py"))
region_names = string_consts(parse("Names/regionName.py"))

# Option enum values (class X: option_y = n) from Options.py.
option_consts = {}
for node in parse("Options.py").body:
    if isinstance(node, ast.ClassDef):
        for st in node.body:
            if isinstance(st, ast.Assign) and isinstance(st.value, ast.Constant) and isinstance(st.targets[0], ast.Name):
                option_consts[f"{node.name}.{st.targets[0].id}"] = st.value.value

# The unrandomized game: nothing shuffled, intended logic, the normal Hag 1 ending.
OPTIONS = {
    "logic_type": 0, "victory_condition": 0, "egg_behaviour": 0, "randomize_bk_moves": 0,
    "randomize_worlds": 0, "randomize_warp_pads": 0, "open_gi_frontdoor": 0, "randomize_tickets": 0,
    "randomize_beans": 0, "nestsanity": 0, "honeyb_rewards": 0, "skip_puzzles": 0, "randomize_signposts": 0,
    "randomize_green_relics": 0, "randomize_chuffy": 0, "cheato_rewards": 0, "backdoors": 0, "skip_klungo": 0,
    "randomize_silos": 0, "randomize_dino_roar": 0, "randomize_boss_loading_zones": 0, "open_hag1": 0,
    "boss_hunt_length": 0, "token_hunt_length": 0, "minigame_hunt_length": 0, "jinjo_family_rescue_length": 0,
    "progressive_beak_buster": 0, "progressive_shoes": 0, "progressive_water_training": 0,
    "progressive_flight": 0, "progressive_egg_aiming": 0, "progressive_bash_attack": 0,
    "randomize_bt_moves": 0, "randomize_stop_n_swap": 0, "randomize_jinjos": 0, "randomize_doubloons": 0,
    "randomize_cheato": 0, "randomize_honeycombs": 0, "randomize_glowbos": 0, "randomize_notes": 0,
    "randomize_treble": 0, "randomize_station_switches": 0, "randomize_world_order": 0,
}

# Rule methods the C++ side writes by hand (they read the randomizer's own world data).
OVERRIDES = {
    "mt_jiggy", "gm_jiggy", "ww_jiggy", "jrl_jiggy", "tdl_jiggy", "gi_jiggy", "hfp_jiggy", "ccl_jiggy",
    "ck_jiggy", "check_notes", "check_solo_moves", "has_BK_move", "set_world_requirement",
}
CONST_METHODS = {"intended_logic": True, "easy_tricks_logic": False, "hard_tricks_logic": False,
                 "glitches_logic": False}

# The collectible kinds the checklist counts: rule dict in BanjoTooieRules.__init__ -> category.
RULE_DICTS = {
    "jiggy_rules": "JIGGY", "honey_rules": "HONEYCOMB", "cheato_rules": "PAGE", "glowbo_rules": "GLOWBO",
    "notes_rules": "NOTES", "treble_clef_rules": "NOTES", "jinjo_rules": "JINJO", "silo_rules": "MOVE",
}
# Location groups (Locations.py) that belong to those kinds, for locations without a rule.
GROUPS = {"Jiggy": "JIGGY", "Honeycomb": "HONEYCOMB", "Cheato Page": "PAGE", "Glowbo": "GLOWBO",
          "Note": "NOTES", "Treble Clef": "NOTES", "Jinjo": "JINJO", "Jamjars Silo": "MOVE"}


class Unsupported(Exception):
    pass


def ident(s):
    return re.sub(r"[^A-Za-z0-9_]", "_", s)


used_items = {}       # python name -> enum
used_regions = {}
needed_methods = []   # methods to translate, in order found
method_set = set()
used_locations = set()


def item_ref(node):
    if isinstance(node, ast.Attribute) and isinstance(node.value, ast.Name) and node.value.id == "itemName":
        used_items[node.attr] = "I_" + node.attr
        return "I_" + node.attr
    raise Unsupported("item " + ast.unparse(node))


def region_ref(node):
    if isinstance(node, ast.Attribute) and isinstance(node.value, ast.Name) and node.value.id == "regionName":
        used_regions[node.attr] = "R_" + node.attr
        return "R_" + node.attr
    raise Unsupported("region " + ast.unparse(node))


def location_ref(node):
    if isinstance(node, ast.Attribute) and isinstance(node.value, ast.Name) and node.value.id == "locationName":
        used_locations.add(node.attr)
        return "L_" + node.attr
    raise Unsupported("location " + ast.unparse(node))


def want_method(name):
    if name not in method_set and name not in OVERRIDES:
        method_set.add(name)
        needed_methods.append(name)


class Expr:
    """A translated expression: a Python constant (folded) or C++ code."""
    def __init__(self, code=None, const=None, is_const=False):
        self.code, self.const, self.is_const = code, const, is_const

    def cpp(self):
        if self.is_const:
            if isinstance(self.const, bool):
                return "true" if self.const else "false"
            if isinstance(self.const, int):
                return str(self.const)
            raise Unsupported(f"constant {self.const!r}")
        return self.code


def C(v):
    return Expr(const=v, is_const=True)


def X(code):
    return Expr(code=code)


def option_value(node):
    # self.world.options.X.value / self.options.X.value
    if isinstance(node, ast.Attribute) and node.attr == "value":
        o = node.value
        if isinstance(o, ast.Attribute) and isinstance(o.value, ast.Attribute) and o.value.attr == "options":
            if o.attr not in OPTIONS:
                raise Unsupported("option " + o.attr)
            return C(OPTIONS[o.attr])
    return None


def is_self_call(func, selfnames):
    return isinstance(func, ast.Attribute) and isinstance(func.value, ast.Name) and func.value.id in selfnames


def tr(node, selfnames, locals_):
    if isinstance(node, ast.Constant):
        if isinstance(node.value, (bool, int)):
            return C(node.value)
        if isinstance(node.value, str):
            return C(node.value)
        raise Unsupported("constant")
    ov = option_value(node)
    if ov is not None:
        return ov
    if isinstance(node, ast.Attribute) and isinstance(node.value, ast.Name) and f"{node.value.id}.{node.attr}" in option_consts:
        return C(option_consts[f"{node.value.id}.{node.attr}"])
    if isinstance(node, ast.Name):
        if node.id in locals_:
            return X(node.id)
        if node.id in ("True", "False"):
            return C(node.id == "True")
        raise Unsupported("name " + node.id)
    if isinstance(node, ast.BoolOp):
        is_and = isinstance(node.op, ast.And)
        parts = []
        for v in node.values:
            e = tr(v, selfnames, locals_)
            if e.is_const:
                if bool(e.const) != is_and:
                    return C(not is_and)   # short-circuits
                continue                    # neutral
            parts.append(e.cpp())
        if not parts:
            return C(is_and)
        if len(parts) == 1:
            return X(parts[0])
        op = " && " if is_and else " || "
        return X("(" + op.join(parts) + ")")
    if isinstance(node, ast.UnaryOp) and isinstance(node.op, ast.Not):
        e = tr(node.operand, selfnames, locals_)
        return C(not e.const) if e.is_const else X("!(" + e.cpp() + ")")
    if isinstance(node, ast.IfExp):
        t = tr(node.test, selfnames, locals_)
        if t.is_const:
            return tr(node.body if t.const else node.orelse, selfnames, locals_)
        return X(f"({t.cpp()} ? {tr(node.body, selfnames, locals_).cpp()} : {tr(node.orelse, selfnames, locals_).cpp()})")
    if isinstance(node, ast.Compare) and len(node.ops) == 1:
        a = tr(node.left, selfnames, locals_)
        b = tr(node.comparators[0], selfnames, locals_)
        op = node.ops[0]
        ops = {ast.Eq: "==", ast.NotEq: "!=", ast.GtE: ">=", ast.Gt: ">", ast.LtE: "<=", ast.Lt: "<"}
        if type(op) not in ops:
            raise Unsupported("compare op")
        if a.is_const and b.is_const:
            return C(eval(f"{a.const!r} {ops[type(op)]} {b.const!r}"))
        return X(f"({a.cpp()} {ops[type(op)]} {b.cpp()})")
    if isinstance(node, ast.BinOp) and isinstance(node.op, (ast.Add, ast.Mult, ast.Sub)):
        a = tr(node.left, selfnames, locals_)
        b = tr(node.right, selfnames, locals_)
        sym = {ast.Add: "+", ast.Mult: "*", ast.Sub: "-"}[type(node.op)]
        if a.is_const and b.is_const:
            return C(eval(f"{a.const!r} {sym} {b.const!r}"))
        return X(f"({a.cpp()} {sym} {b.cpp()})")
    if isinstance(node, ast.Call):
        f = node.func
        # state.has / count / can_reach_region / can_reach_location
        if isinstance(f, ast.Attribute) and isinstance(f.value, ast.Name) and f.value.id == "state":
            args = node.args
            if f.attr == "has":
                it = item_ref(args[0])
                if len(args) >= 3:
                    n = tr(args[2], selfnames, locals_)
                    return X(f"s.has({it}, {n.cpp()})")
                return X(f"s.has({it})")
            if f.attr == "count":
                return X(f"s.count({item_ref(args[0])})")
            if f.attr == "can_reach_region":
                return X(f"s.reach({region_ref(args[0])})")
            if f.attr == "can_reach_location":
                return X(f"reach_location(s, {location_ref(args[0])})")
            raise Unsupported("state." + f.attr)
        if is_self_call(f, selfnames):
            name = f.attr
            if name in CONST_METHODS:
                return C(CONST_METHODS[name])
            extra = []
            for a in node.args[1:]:
                if isinstance(a, ast.Attribute) and isinstance(a.value, ast.Name) and a.value.id == "itemName":
                    extra.append(item_ref(a))
                elif isinstance(a, ast.Attribute) and isinstance(a.value, ast.Name) and a.value.id == "locationName":
                    extra.append(location_ref(a))
                else:
                    extra.append(tr(a, selfnames, locals_).cpp())
            prefix = "o_" if name in OVERRIDES else "r_"
            want_method(name)
            return X(f"{prefix}{name}(" + ", ".join(["s"] + extra) + ")")
        raise Unsupported("call " + ast.unparse(f))
    raise Unsupported(type(node).__name__ + ": " + ast.unparse(node)[:80])


def tr_block(stmts, selfnames, locals_, indent):
    out = []
    pad = "    " * indent
    for st in stmts:
        if isinstance(st, ast.Expr) and isinstance(st.value, ast.Constant):
            continue
        if isinstance(st, ast.Return):
            if st.value is None:
                raise Unsupported("bare return")
            out.append(f"{pad}return {tr(st.value, selfnames, locals_).cpp()};")
            if True:
                return out, True
        elif isinstance(st, ast.If):
            t = tr(st.test, selfnames, locals_)
            if t.is_const:
                body, ret = tr_block(st.body if t.const else st.orelse, selfnames, locals_, indent)
                out += body
                if ret:
                    return out, True
            else:
                body, _ = tr_block(st.body, selfnames, locals_, indent + 1)
                out.append(f"{pad}if ({t.cpp()}) {{")
                out += body
                if st.orelse:
                    els, _ = tr_block(st.orelse, selfnames, locals_, indent + 1)
                    out.append(f"{pad}}} else {{")
                    out += els
                out.append(f"{pad}}}")
        elif isinstance(st, (ast.Assign, ast.AnnAssign)):
            target = st.targets[0] if isinstance(st, ast.Assign) else st.target
            if not isinstance(target, ast.Name):
                raise Unsupported("assign target")
            locals_.add(target.id)
            out.append(f"{pad}{target.id} = {tr(st.value, selfnames, locals_).cpp()};")
        elif isinstance(st, ast.AugAssign) and isinstance(st.op, ast.Add) and isinstance(st.target, ast.Name):
            out.append(f"{pad}{st.target.id} += {tr(st.value, selfnames, locals_).cpp()};")
        else:
            raise Unsupported("statement " + type(st).__name__)
    return out, False


silo_costs = {}
for node in ast.walk(parse("WorldOrder.py")):
    if isinstance(node, ast.FunctionDef) and node.name == "generate_jamjars_costs":
        for st in ast.walk(node):
            if isinstance(st, ast.Assign) and isinstance(st.value, ast.Dict) and not silo_costs:
                for k, v in zip(st.value.keys, st.value.values):
                    silo_costs[k.attr] = v.value
                    used_locations.add(k.attr)

rules_tree = parse("Rules.py")
rules_cls = [n for n in rules_tree.body if isinstance(n, ast.ClassDef) and n.name == "BanjoTooieRules"][0]
methods = {f.name: f for f in rules_cls.body if isinstance(f, ast.FunctionDef)}

# Rule dicts: location python name -> method name.
location_rules = {}
location_category = {}
for st in methods["__init__"].body:
    if isinstance(st, ast.Assign) and isinstance(st.targets[0], ast.Attribute) and st.targets[0].attr in RULE_DICTS:
        cat = RULE_DICTS[st.targets[0].attr]
        for k, v in zip(st.value.keys, st.value.values):
            loc = k.attr
            location_rules[loc] = v.attr
            location_category[loc] = cat
            want_method(v.attr)

# Locations.py: python name -> (memaddr, bit, group).
location_data = {}
for node in ast.walk(parse("Locations.py")):
    if isinstance(node, ast.Dict):
        for k, v in zip(node.keys, node.values):
            if (isinstance(k, ast.Attribute) and isinstance(v, ast.Call) and getattr(v.func, "id", "") == "LocationData"):
                args = [a.value if isinstance(a, ast.Constant) else None for a in v.args]
                group = args[3] if len(args) > 3 else ""
                location_data[k.attr] = (args[1], args[2], group)

# Regions.py: which region each location is in, and the region graph.
regions_tree = parse("Regions.py")
location_region = {}
entrances = []   # (from, to, cpp function body or None)
for node in regions_tree.body:
    if isinstance(node, ast.AnnAssign) and getattr(node.target, "id", "") == "BANJO_TOOIE_REGIONS":
        for k, v in zip(node.value.keys, node.value.values):
            region_ref(k)
            for e in v.elts:
                location_region[e.attr] = k.attr

connect = [n for n in regions_tree.body if isinstance(n, ast.FunctionDef) and n.name == "connect_regions"][0]
region_vars = {}
skipped = []


def region_test(test):
    # hasattr(self.multiworld, "generation_is_fake") is the Universal Tracker: no.
    if isinstance(test, ast.Call) and getattr(test.func, "id", "") == "hasattr":
        return False
    e = tr(test, {"self", "rules"}, set())
    if not e.is_const:
        raise Unsupported("region test " + ast.unparse(test))
    return bool(e.const)


def walk_connect(stmts):
    for st in stmts:
        if isinstance(st, ast.Assign) and isinstance(st.value, ast.Call) and getattr(st.value.func, "attr", "") == "get_region":
            region_vars[st.targets[0].id] = st.value.args[0].attr
        elif isinstance(st, ast.Expr) and isinstance(st.value, ast.Call) and getattr(st.value.func, "attr", "") == "add_exits":
            src = region_vars[st.value.func.value.id]
            dests = st.value.args[0].elts
            conds = {}
            if len(st.value.args) > 1:
                for k, v in zip(st.value.args[1].keys, st.value.args[1].values):
                    conds[k.attr] = v
            for d in dests:
                lam = conds.get(d.attr)
                region_ref(d)
                entrances.append((src, d.attr, lam))
        elif isinstance(st, ast.If):
            try:
                walk_connect(st.body if region_test(st.test) else st.orelse)
            except Unsupported as e:
                skipped.append(f"if at line {st.lineno}: {e}")
        elif isinstance(st, ast.Assign):
            pass
        else:
            skipped.append(f"line {st.lineno}: {ast.unparse(st)[:60]}")


walk_connect(connect.body)

# The world and boss loading zones (the loops over self.loading_zones at the end of connect_regions),
# with each loading zone leading where it does in the unrandomized game. lookup_table is read from
# connect_regions; the conditions are those of the loops.
lookup = {}
for node in ast.walk(connect):
    if isinstance(node, ast.Assign) and getattr(node.targets[0], "id", "") == "lookup_table":
        for k, v in zip(node.value.keys, node.value.values):
            lookup[k.attr] = v.attr
for world in ["MT", "GM", "WW", "JR", "TL", "GIO", "HP", "CC", "CK"]:
    entrances.append((lookup[world], world, None))
    back = ast.parse("lambda state: rules.GGM_to_PL(state)", mode="eval").body if world == "GM" else None
    entrances.append((world, lookup[world], back))
boss_source_rule = {
    "MTBOSS": "rules.has_green_relics(state, 20)",
    "JRBOSS": "((rules.grenade_eggs_item(state) or rules.clockwork_eggs_item(state)) and rules.sub_aqua_egg_aiming(state))"
              " or rules.humbaJRL(state) or rules.talon_torpedo(state)",
    "GIBOSS": "rules.can_enter_gi_repair_depot(state)",
    "HPFBOSS": "rules.flight_pad(state)",
    "HPIBOSS": "rules.can_reach_hfp_ice_crater(state)",
}
boss_room_rule = {
    "MTBOSS": "rules.breegull_blaster(state)",
    "WWBOSS": "rules.can_enter_big_top(state)",
    "JRBOSS": "rules.sub_aqua_egg_aiming(state) and rules.grenade_eggs_item(state)",
    "GIBOSS": "rules.grenade_eggs_item(state)",
    "HPFBOSS": "rules.ice_eggs_item(state)",
}
for boss in ["MTBOSS", "GMBOSS", "WWBOSS", "JRBOSS", "TLBOSS", "GIBOSS", "HPFBOSS", "HPIBOSS", "CCBOSS"]:
    cond = f"({boss_source_rule.get(boss, 'True')}) and ({boss_room_rule.get(boss, 'True')})"
    entrances.append((lookup[boss], boss, ast.parse("lambda state: " + cond, mode="eval").body))
    if boss == "TLBOSS":
        entrances.append((boss, lookup[boss], None))

# Translate entrance conditions.
entrance_funcs = []
entrance_rows = []
for i, (src, dst, lam) in enumerate(entrances):
    region_ref_name = "R_" + src
    used_regions[src] = region_ref_name
    if lam is None:
        entrance_rows.append(f"    {{ R_{src}, R_{dst}, nullptr }},")
        continue
    body = lam.body
    e = tr(body, {"self", "rules"}, set())
    if e.is_const:
        if e.const:
            entrance_rows.append(f"    {{ R_{src}, R_{dst}, nullptr }},")
        continue
    fname = f"e_{i}"
    entrance_funcs.append(f"static bool {fname}(const State& s) {{ return {e.cpp()}; }}")
    entrance_rows.append(f"    {{ R_{src}, R_{dst}, {fname} }},")

# Translate methods (the list grows while translating).
translated = {}
failed = {}
i = 0
while i < len(needed_methods):
    name = needed_methods[i]
    i += 1
    f = methods.get(name)
    if f is None:
        failed[name] = "no such method"
        continue
    params = [a.arg for a in f.args.args][2:]
    locals_ = set(params)
    try:
        body, ret = tr_block(f.body, {"self"}, locals_, 1)
    except Unsupported as e:
        failed[name] = str(e)
        continue
    if not ret:
        body.append("    return false;")
    decls = sorted(locals_ - set(params))
    sig = ", ".join(["const State& s"] + [f"int {p}" for p in params])
    text = [f"static bool r_{name}({sig}) {{"]
    if decls:
        text.append("    int " + ", ".join(f"{d} = 0" for d in decls) + ";")
    text += body
    text.append("}")
    translated[name] = (sig, text)

if failed:
    for k, v in failed.items():
        print(f"untranslated: {k}: {v}", file=sys.stderr)
    sys.exit(1)

# Game flags: N64 flag = memaddr * 8 + bit + 0x28 (the 0x8012C770 bitfield). Check each against the
# decomp's flag names.
flag_names = {}
with open(gameflags_path) as fl:
    for m in re.finditer(r"(FLAG_[0-9A-F]+_\w+)\s*=\s*0x([0-9A-Fa-f]+)", fl.read()):
        flag_names[int(m.group(2), 16)] = m.group(1)
NAME_KIND = {"JIGGY": "_JIGGY_", "HONEYCOMB": "_EMPTY_HONEYCOMB_", "PAGE": "_CHEATO_PAGE_",
             "GLOWBO": "_GLOWBO_", "NOTES": "_NOTE_", "JINJO": "_JINJO_", "MOVE": "_ABILITY_"}

# The game's level ids (Totals pages) by the prefix of the location names.
LEVELS = {"SM": 0x13, "IoH": 0x1A, "MT": 0x10, "GGM": 0x0F, "WW": 0x12, "JRL": 0x14, "TDL": 0x15, "GI": 0x16,
          "HFP": 0x17, "CCL": 0x18, "CK": 0x19}

rows = []
problems = []
all_locs = set(location_category) | {k for k, v in location_data.items() if v[2] in GROUPS}
for loc in sorted(all_locs, key=lambda l: (location_data.get(l, (0, 0, ""))[0] or 0, location_data.get(l, (0, 0, ""))[1] or 0)):
    if loc not in location_data:
        problems.append(f"{loc}: no location data")
        continue
    mem, bit, group = location_data[loc]
    cat = location_category.get(loc) or GROUPS.get(group)
    if mem is None or (mem == 0 and bit == 0):
        problems.append(f"{loc}: no flag")
        continue
    flag = mem * 8 + bit + 0x28
    fname = flag_names.get(flag, "?")
    if NAME_KIND[cat] not in fname and not (cat == "NOTES" and "TREBLE" in fname):
        problems.append(f"{loc}: flag 0x{flag:X} is {fname}, not a {cat}; left out")
        continue
    region = location_region.get(loc)
    if region is None:
        problems.append(f"{loc}: no region")
        continue
    used_regions[region] = "R_" + region
    rule = location_rules.get(loc)
    rule_ref = f"r_{rule}" if rule else "nullptr"
    display = location_names[loc]
    prefix = display.split(":")[0].split(" ")[0]
    level = LEVELS[prefix]
    amount = 20 if "TREBLE" in fname else 5 if cat == "NOTES" else 1
    rows.append(f"    {{ 0x{flag:03X}, C_{cat}, R_{region}, {rule_ref}, 0x{level:02X}, {amount}, \"{display}\" }}, // {fname}")
    used_locations.add(loc)

# can_reach_location targets must be in the table.
location_index = {}
for idx, r in enumerate(rows):
    pass

for p in problems:
    print("note: " + p, file=sys.stderr)

# Items totals_checklist.cpp fills in itself, whether or not a rule asks for them.
for it in item_names:
    if re.fullmatch(r"(WARP(MT|GM|WW|JR|TL|GI|HP|CC|CK)\d|SILOIOH\w\w|HUMBA\w\w|MUMBO\w\w|\w+JINJO|JIGGY|DOUBLOON)", it):
        used_items[it] = "I_" + it
regions = sorted(used_regions)
items = sorted(used_items)

with open(out_path, "w") as out:
    w = out.write
    w("// Generated by tools/gen_totals_rules.py from the Banjo-Tooie world of the Archipelago randomizer\n")
    w("// (https://github.com/jjjj12212/AP_Banjo-Tooie, worlds/banjo_tooie). Do not edit by hand.\n//\n")
    w("// The rules are translated from that project's Rules.py and Regions.py, used under its licence:\n//\n")
    with open(os.path.join(ap_dir, "..", "..", "LICENSE"), encoding="utf-8") as lic:
        for line in lic.read().strip().splitlines():
            w("// " + line + "\n" if line else "//\n")
    w("\n// clang-format off\n\n")
    w("enum Item : int {\n" + "".join(f"    I_{i}, // {item_names.get(i, '')}\n" for i in items) + "    I_COUNT\n};\n\n")
    w("enum Region : int {\n" + "".join(f"    R_{r}, // {region_names.get(r, '')}\n" for r in regions) + "    R_COUNT\n};\n\n")
    w("enum Category : int { C_JIGGY, C_HONEYCOMB, C_PAGE, C_GLOWBO, C_NOTES, C_JINJO, C_MOVE };\n\n")
    loc_list = sorted(used_locations)
    w("enum LocationId : int {\n" + "".join(f"    L_{l},\n" for l in loc_list) + "    L_COUNT\n};\n\n")
    w("struct State;\nstatic bool reach_location(const State& s, int location);\n")
    for name, (sig, _) in translated.items():
        w(f"static bool r_{name}({sig});\n")
    w("\n")
    for name, (sig, text) in translated.items():
        w("\n".join(text) + "\n\n")
    w("\n".join(entrance_funcs) + "\n\n")
    w("struct Entrance {\n    Region from;\n    Region to;\n    bool (*open)(const State&);\n};\n\n")
    w("static const Entrance entrances[] = {\n" + "\n".join(entrance_rows) + "\n};\n\n")
    w("struct Location {\n    int flag;\n    Category category;\n    Region region;\n"
      "    bool (*rule)(const State&);\n    int level;\n    int amount;\n    const char* name;\n};\n\n")
    w("static const Location locations[] = {\n" + "\n".join(rows) + "\n};\n\n")
    # LocationId -> index in locations[] for reach_location (-1: not a checklist location).
    names_in_rows = [re.search(r'"(.*)" }', r).group(1) for r in rows]
    w("static const int location_index[] = {\n")
    for l in loc_list:
        nm = location_names[l]
        w(f"    {names_in_rows.index(nm) if nm in names_in_rows else -1}, // {nm}\n")
    w("};\n\n")
    # Items that are also the name of a location with a flag (moves learned at a silo, train
    # switches, Chuffy): that flag says the player has the item.
    w("static const int item_location_flag[] = {\n")
    for it in items:
        d = location_data.get(it)
        flag = d[0] * 8 + d[1] + 0x28 if d and d[0] else -1
        w(f"    {flag if flag < 0 else hex(flag)}, // {it} {flag_names.get(flag, '')}\n")
    w("};\n\n")
    # Jamjars' prices in notes, in the unrandomized game (WorldOrder.generate_jamjars_costs), by LocationId.
    w("static const int silo_cost[] = {\n")
    for l in loc_list:
        w(f"    {silo_costs.get(l, -1)}, // {l}\n")
    w("};\n")

print(f"{len(translated)} rule methods, {len(entrance_rows)} entrances, {len(rows)} locations, "
      f"{len(items)} items, {len(regions)} regions; skipped in connect_regions: {len(skipped)}", file=sys.stderr)
for s_ in skipped:
    print("skipped: " + s_, file=sys.stderr)
