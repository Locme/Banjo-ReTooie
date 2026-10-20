# Cheats

One short entry for each cheat in the Cheats tab, with its name as shown in
the menu. Every cheat needs **Enable cheats** on, and every cheat is off by
default. Turning **Enable cheats** off turns all of them off.

**Enable cheats**: turns on the cheat options. Achievements cannot be earned
while it is on. Turning it off resets every cheat.

**Infinite eggs**: blue, fire, ice, grenade, clockwork and mine eggs have no
limit. Limits are restored when the cheat is turned off.

**Infinite feathers**: red and gold feathers have no limit. Same restore rule.

**Infinite Glowbos**: Glowbos have no limit. Same restore rule.

**Infinite ice keys**: ice keys have no limit. Same restore rule.

**Infinite Jumps (Levitate)**: press A again in mid-air to jump again. Hold A
to keep rising, which floats you upwards. It does not work during transformations, swimming, climbing or some
other states the code leaves out, so A keeps its usual job there.

Each Cheato switches on the game's own code of that name, as if you had typed it
in the Code Chamber, with no Code Chamber needed. In this port the effect comes from the game. Turning the cheat off clears only
the flag this port switched on, so a code you typed in the Code Chamber stays on.

- **Cheato: FEATHERS**: doubles your feather capacity. (From fan wiki pages, not checked in this port.)
- **Cheato: EGGS**: doubles your egg capacity. (From fan wiki pages, not checked in this port.)
- **Cheato: FALLPROOF**: no damage from long falls, whatever the height. (From fan wiki pages, not checked in this port.)
- **Cheato: HONEYBACK**: you get one energy unit back every three seconds. (From fan wiki pages, not checked in this port.)
- **Cheato: JUKEBOX**: turns on the Jukebox at Jolly's. (From fan wiki pages, not checked in this port.)
- **Cheato: GETJIGGY**: activates the signs in Jiggywiggy's Temple. (From fan wiki pages, not checked in this port.)
- **Cheato: SUPERBANJO**: Banjo and Kazooie run faster. The handoff report (4.70) also records a headless check where Banjo walked about 1.5 times as far with it on. (From fan wiki pages, not checked in this port.)
- **Cheato: SUPERBADDY**: baddies run faster. (From fan wiki pages, not checked in this port.)
- **Cheato: HONEYKING**: you are invincible. (From fan wiki pages, not checked in this port.)
- **Cheato: NESTKING**: you get infinite eggs and feathers. This is the same effect as the Infinite eggs and Infinite feathers options, which work in this port's code. (From fan wiki pages, not checked in this port.)
- **Cheato: HOMING**: eggs home in on enemies. (From fan wiki pages, not checked in this port.)

**Stop 'n' Swop items**: marks the blue and pink Stop 'n' Swop mystery eggs as
collected, as the Banjo-Kazooie link would, without a Banjo-Kazooie save. The
yellow egg is not affected.

**Unlock all moves**: every move counts as learned while it is on. Your save
file is not changed. Only the moves are changed, not the rest of the game's
progress.

**Learn Every Move**: learns every move for real (the flags the teachers set),
once each time it is switched on, and the area reloads. Saving keeps them, and
switching it off doesn't unlearn them.

**Transformation**: choose a form from the list and the area you are in reloads
with you in it. It comes back in at the entrance you used, not where you were
standing. Some forms break in areas the game never expects them in. Once the
area starts reloading the row goes back to Off by itself (it also does if you
pick the form you already are); pick Banjo-Kazooie (BK) to change back. The list is a
drop-down.

**Enemy spawner** (Enemies): pick an enemy from the drop-down and press Spawn
beside it. Each press puts one in front of Banjo, facing him (while the menu
pauses the game, they appear when it closes). The list is every
enemy in the game's spawn-by-id table. Enemies marked "(own world)" crashed
when spawned outside the world they belong to (they follow routes or use props
that only exist there), so use those in their own world. Gruntlings and other
enemies the game builds from shared data are not in the table, so they are not
in the list. Code: `src/gameplay/enemy_spawner.cpp`.
