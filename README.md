# Pokémon Heliodor

[***Discord Link***](https://discord.gg/zsZEsa5q7D)

This is a modification of Pokémon Emerald intended to be a massive upgrade and comprehensive source of Pokémon, items, and moves to be transferred to official games while also being a greatly enjoyable game to play standalone for players not intererested in complex software ecologies.

The highest design priorities are 100% compatibility in terms of:
* Multiplayer
  * No changes made should interfere with any link capability with Pokémon Ruby, Pokémon Sapphire, Pokémon FireRed, Pokémon LeafGreen, Pokémon Emerald, Pokémon Box Ruby & Sapphire, Pokémon Colosseum, or Pokémon XD: Gale of Darkness.
* Inter-generational Transfer
  * Every Pokémon obtained should be completely legal (indistinguishable from a Pokémon obtained in an official game, using [***PKHeX***](https://github.com/kwsch/PKHeX)'s legality checker as the reference as opposed to Game Freak's) once transferred to a Generation 4 game, with one outlier.
  * The exception to this will technically be illegal until it enters a Generation 7 game (assuming no Ribbons are obtained for it that are "before its time"), but there should be no issues transferring it through Poké Transporter to Pokémon Bank.
* Save Files
  * There should be no issues importing your save file from Pokémon Ruby, Pokémon Sapphire, or Pokémon Emerald to Pokémon Heliodor.
  * This allows Pokémon Heliodor to, in effect, be treated similar to an expansion pack in which if a player has already completed one of the Generation 3 Hoenn games, this can be used to "unlock" extra content/features for that playthrough.

### Changes

* All 386 Pokémon available within Generation 3 are obtainable.
  * Pokémon not normally found in Pokémon Emerald are generated with different game IDs, languages, and pseudo-random number generation methods to replicate the encounters in which they can normally be found in other games.
* An Egg Incubator is available for use that relies upon the real-time clock instead of the step counter.
* Pokémon are able to learn every move they would be capable of learning in Generations 3, 4, and 5 one way or another.
* All items are available and are not finite.
  * Many items from newer games have also been added.
* For Pokémon Colosseum and Pokémon XD: Gale of Darkness players, Poké Coupons that have been transferred to the cartridge can be used to purchase rare items.
  * Poké Coupons can also be obtained by trading in Battle Points at the Battle Frontier.
* Rumble functionality has been added, both for cartridges housing the appropriate hardware as well as when playing on the Nintendo Game Boy Player.
* e-Reader functionality has been restored with version and language restrictions removed.
  * The Legendary Titan dolls can be obtained without issue.
  * e-Card berries can be obtained, although Japanese berries will (obviously) have text errors.
    * The Game Boy Kid in the Cove Lily Motel has an e-Card to scan, allowing an e-Card berry to be obtained without having access to an e-Reader.
  * The Eon Ticket can be obtained, but the event text is slightly garbled.
    * The Eon Ticket can also be obtained during normal gameplay after defeating the Elite Four for the first time.
  * Ruby/Sapphire e-Card trainers can be battled in Sootopolis.
* The Pokémon summary screen now shows correct information for all locations in Pokémon Ruby, Pokémon Sapphire, Pokémon Colosseum, and Pokémon XD: Gale of Darkness.
* Breeding mechanics have been changed.
  * Both parents can now pass down Nature and moves.
  * The "Masuda Method" is implemented.
  * A bug affecting IV inheritance has been fixed.
* Methods to aid in obtaining Shiny Pokémon have been added.
  * As mentioned above, the [***Masuda Method***](https://bulbapedia.bulbagarden.net/wiki/Masuda_method) is implemented.
  * The [***Shiny Charm***](https://bulbapedia.bulbagarden.net/wiki/Shiny_Charm) has been added.
  * Successively encountering the same species of Pokémon in succession will increase the odds of encountering a Shiny Pokémon.
* Many mechanics have been updated to match the changes made in newer games.
* Legendary Pokémon (and Sudowoodo) that have been defeated without being caught will respawn when the Elite Four is defeated.
  * The respawn will only trigger if the Pokémon is not registered as "caught" in the Pokédex, so trading over a legendary Pokémon will interfere with this.
  * Roaming Pokémon will respawn instantly somewhere in the region when knocked out.
  * After every 10 Elite Four victories, all Legendary and Mythical Pokémon (and Sudowoodo) will respawn regardless of whether they have been caught.
* The clock offset can be changed by pressing 'B', 'Left', and 'Select' on the title screen.
* Secret Power, Cut, Surf, Strength, Rock Smash, Waterfall, and Dive can be used as long as one of the party members is capable of learning the move.
  * The respective badge is still required.
* EVs are capped at 252 per stat instead of 255.
  * The cap on EVs able to be earned through vitamins has been removed as well.
* Many encounter mechanics have been modified.
* Catching a Pokémon yields experience points.
* HM moves can be forgotten without the use of the Move Deleter.
* Trade evolutions can be triggered be leveling up in the Union Room.
  * The Union Room can be entered without the Wireless Adapter connected.
* Level-up evolutions can be triggered at level 100 by using a Rare Candy.
* The IV Judge at the Battle Frontier gives specific numbers for all stats.
  * Next door, there is an EV Judge as well as an EV Reseter.
  * An IV Judge is also at the Day Care on Route 117.
* A clock has been added to the start menu.
* Pokémon have slight differences in coloration that varies with the individual.
* Eggs are colored based on the Type(s) of the Pokémon inside.
* A system similar to Pass/O/Rotom Power has been added and can be accessed through the Power Pad, a Key Item found in the Bag by default.
* The Trainer Card can be customized at a terminal in Pokémon Centers.
    * When linking with Pokémon Ruby, Pokémon Sapphire, Pokémon FireRed, and Pokémon LeafGreen other player's Trainer Cards are displayed exactly as they are in the player's game.
* Numerous aspects of the graphical style including text, interfaces, tiles, and sprites have been changed.
* Event tickets can be shared with other players of Pokémon Ruby, Pokémon Sapphire, Pokémon FireRed, Pokémon LeafGreen, Pokémon Emerald, and Pokémon Heliodor via Mystery Gift and Record Mixing.
* Units of measurement can be displayed in Metric.
* Text box frame color and font are customizable.
* The real-time clock effects the world visually.
* The option to skip giving a nickname to newly obtained Pokémon has been added.
* Trading restrictions with all Generation 3 games besides Pokémon XD: Gale of Darkness have been removed.
* A Premier Ball can be obtained as a gift for every 10 Poké Balls (of any kind) purchased at the Poké Mart.
* After a Repel's effect wears off, and if the player has more Repels in their Bag, they will be asked if they would like to use another immediately without having to go into the menu.
* Holding 'B' while surfing will cause a movement speed increase.
* The Bag inventory can be sorted.
* Two more Key Items can be registered to 'L' and 'R' to be used in the field.
* Numerous small features and graphics have been changed/added and bugs have been fixed.

## Instructions

The release patch can be applied to a dump of Pokémon Emerald with a sha1 sum of f3ae088181bf583e55daf962a92bb46f4f1d07b7 using a program such as [***beat***](https://github.com/Screwtapello/beat) or [***Floating IPS***](https://github.com/Alcaro/Flips).

## Building

To build this yourself, you'll need `git`, `build-essential`, `binutils-arm-none-eabi`, and `libpng-dev` or equivilant non-Debian packages.
Simply run `make` to build a `.gba` image or `make patch` to build a `.bps` patch.
For more detailed compilation instructions, see [INSTALL.md](docs/INSTALL.md).

## Credits

* Alistair: FRLG-styled tilesets
* AsparagusEduardo: Modified white out penalty
* Avatar: NPC OW Sprites
* veontrainer: NPC OW Sprites
* Buffel Salt: Give NPCs different Poké Balls based on Class; Stop Berry Trees from dying
* Delta231: NPC OW sprites
* DizzyEgg: Repel renewal prompt; Double wild encounters
* Farore: NPC OW sprites
* ghoulslash: Item sorting in Bag; Additional item registration slots; Poké Ball quick-use function
* hyo: FRLG-styled Player Character OW sprites and NPC OW sprites
* ipatix: Improved audio mixer
* Jaizu: Partnered to design new Summary Screen; inserting FRLG-styled OW sprites and tilesets
* kalarie: NPC OW sprites
* LOuroboros: Headbutt event script
* m.vit: NPC OW sprites
* MrDollSteak: NPC OW sprites
* Robloxmaster342: NPC OW sprites
* Spherical_Ice: NPC OW sprites
* Ulithium_Dragon: NPC OW Sprites
* Poffin_Case: FRLG-styled Hoenn NPC OW sprites
* Sierraffinity: RTC-based environmental tinting system; translated e-Reader strings; time-based Nurse greetings

## Special Thanks

* aldelaro5
* Bulbapedia
* Deokishisu
* DRayX
* Jaizu
* The PKHeX team
* pret
* Project Pokémon
* Serebii
* ShinyDragonHunter
