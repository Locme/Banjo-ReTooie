# Translations

General > Language shows the game's own text (dialogue, menus, level names, signs) in another language. Each language
is two files with the same name:

* `<name>.txt`: the translation, every translated line of the game.
* `<name>.svg`: the language's flag, shown before its name in the Language setting. Optional.

English is the game's own text from your ROM. Its flag, the Union Jack (Banjo-Tooie is a British game), is
`assets/translations/english.svg`.

**Français, Deutsch and Español are Rare's own translations**, read from your own copy of the European (PAL)
Banjo-Tooie: choosing one without it opens a pop-up with **Browse** (pick the ROM file; it is checked and kept as
`bt.n64.eu.z64` in the app-data folder) and **Exit** (back to the language before). Console: `language rom <file>`.
Their files (`french.txt`, `german.txt`, `spanish.txt`) say `@game european 1`, `2` or `3` and hold only the port's own
text (menu, achievements, notices), translated for this port with Rare's official names. Nothing of the European ROM
is in the program.

Other translations are fan-made (by people or drafted by AI), not Rare's, and none ships with the port: they come as
language mods or as your own files.

## Where the files go

* `assets/translations/` in the game folder: translations that ship with the game.
* A language mod in the mods folder: a mod folder (or a .zip of one) with a `mod.json`, a `translations.json` and a
  `translations/` folder of `.txt` and `.svg` files. Its languages count while the mod is on in the Mods menu.
  `translations.json` is `{ "translations": "translations" }`.
* `translations/` in the app-data folder (`language` in the console prints where): your own. A file here wins over a
  shipped or mod one of the same name.

The Language setting lists the files found when the program starts, from the mods on then, so a new file or a mod
just turned on shows after a restart. A mod's language chosen while the mod is off is English until it is on again. Edits to the
chosen file show at once with `language reload` in the console, which also reloads the area.

## Making a translation

1. Start the game and run `language export` in the console. It writes the game's English, from your ROM, to
   `translations/english.txt`. That file is Rare's text: keep it to yourself.
2. Copy it to `translations/<name>.txt`, for example `french.txt`, and change `@name English` at the top to the
   language's own name, for example `@name Français`. The name is shown in the Language setting.
3. Replace each English line with its translation.
4. Put a flag beside it as `<name>.svg` (any size; 3:2 or 2:1 looks best).
5. Restart, choose the language, and run `language check` to find mistakes.

Only the translated lines are yours. Share `<name>.txt` and `<name>.svg` once every line in the `.txt` is your own
words; until then the file still holds Rare's English.

## The format

A UTF-8 text file. Lines before the first `===` are the header: `#` starts a comment, `@name` gives the language's name.

```
@name Français

=== 1863
REPRENDRE LA PARTIE
OBJETS ET OUTILS
JINJOS
VOIR LES TOTAUX
SAUVEGARDER ET QUITTER
ÊTES-VOUS SÛR ?
{87} OUI {86} NON
```

* `=== 1863` starts a text asset (its id, in hex). Under it come the asset's lines in the game's order, one per line.
* An asset must have exactly as many lines as the game's (the export shows how many). One with a different count stays
  English, and `language check` names it. Blank lines at the end of an asset are ignored; `{}` is a line that is
  meant to be empty.
* An asset the file leaves out stays English, so a translation can be done a part at a time.
* Lines starting with `#` inside an asset are comments.
* `{XX}` is a byte as it is, in hex. `{0A}` breaks the line in a text box; `{80}` to `{87}` are button pictures
  (`{86}` and `{87}` are the B and A buttons); keep them where the sentence needs them. Other `{XX}` are control bytes:
  keep them as they are.
* A line holds at most 254 characters.

## Letters

The game's text is all capitals, and lowercase letters are written as capitals. Write the real letters (É, Ø, Å, Ñ...):
the loader turns them into the game's own codes, and `language export` turns them back.

The game's dialogue and menu font already holds Rare's accented capitals (the European version's): Ä Ö Ü ß À Â Ç É È Ê
Ë Î Ï Ô Û Ù Ì Í Ó Ò Ú Ñ Á ¡ ¿ ª º. It has no Æ, Ø or Å, and the big title lettering (Totals, level names) has no
accents at all. So:

* **With no font of your own**, Æ, Ø and Å are written AE, O and A, and the title lettering shows an accented capital
  as its plain letter (É as E).
* **With a font of your own** (below), every letter of that game font is drawn from it, Æ, Ø and Å included, so nothing
  looks out of place.

Curly quotes, dashes and `…` become the plain ASCII ones; `©` is the game's copyright sign. Ã, Õ, Ý and Œ become A, O,
Y and OE. Any other character shows as `?`, and `language check` counts it.

## Fonts

Put a TrueType or OpenType font in the `fonts` folder of the app-data folder:

* `dialogue.ttf` (or `.otf`): dialogue, menus and the pause menu.
* `title.ttf` (or `.otf`): the big title lettering of the Totals and level names, and the Totals checklist.

When one is there, that game font is drawn from it when the game starts, every letter: the capitals as tall as Rare's,
on Rare's baseline, spaced the way the game spaces Rare's letters. An accented capital too tall for the line is drawn a
little smaller, as Rare drew its own. Without one, the game's own font is used. A font change shows after a restart.

Rare's fonts are believed to be **Comicrazy** (Comicraft, 1995) for dialogue and menus and **Lithos** (Adobe) for the
title lettering; the Xbox re-releases are said to use **Andy**. These are commercial fonts: use a copy you own, or any
font you like. Fonts are never shipped with the port. `TOOIE_FONT_DUMP=<folder>` writes the fonts as built
(`font_0C21.bin`, `font_0C22.bin`) for checking.

## One language, two written forms

Files that share `@group` are one choice in the Language setting, named after the group, with a setting of their own
under it to pick the form, shown only while that language is chosen; the file that says `@default` is the form a new
player starts on. Each file names its form with `@variant <form>`; the choice is named after the group. The group's flag
is `<group>.svg` (the group's name in lower case), else the first file's.

## The Esc menu

Every setting's name, description and choices come in a `=== settings` section, `<tab>.<setting>.name`,
`.description` and `.choice.<choice key>`; `language export` writes them all with their English. Changing the language
changes the menu at once. The tab names (`tab.<id>`), section headings (`heading.<English>`) and the search box
(`menu.search`) are in the same section. A long list shown as a drop-down keeps its choices' English names until the
game restarts.

## The port's own text

The achievements (names, descriptions, the unlock pop-up), our pause menu entries and the Totals checklist's labels are
the port's text, not the game's. They come in a `=== port` section at the end of the file, one `key = text` line each:

```
=== port
pause.achievements = PRESTASJONER
achievement.it_lives.name = Den lever!
```

Notices (the small messages in the top-right corner, "Screenshot saved") are `toast.<English> = <translation>` lines in
the same section. A line can also give just the start of a notice that goes on with a name or a number:
`toast.Warping to = Hopper til` turns "Warping to Mayahem Temple" into "Hopper til Mayahem Temple".

`language export` writes every key with its English. A key the file leaves out stays English.

## What stays English

The Totals checklist's hints ("NEEDS ...", "TRAIN AT ..."), the developer tools' notices, the launcher and the
Controls and Mods pages' own wording, and text drawn into textures
(some signs and logos) stay as they are.
