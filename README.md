# Pokémon Heliodor

This is a modification of Pokémon Emerald intended to be an interpretation of the "definitive" Generation 3 Hoenn concept while still fitting firmly within the official game ecology.

The highest design priorities are 100% compatibility in terms of:
* Multiplayer
  * No changes made should interfere with any link capability with Pokémon Ruby, Pokémon Sapphire, Pokémon FireRed, Pokémon LeafGreen, Pokémon Emerald, Pokémon Box Ruby & Sapphire, Pokémon Colosseum, or Pokémon XD: Gale of Darkness.
* Inter-generational Transfer
  * Every Pokémon obtained should completely be legal (indistinguishable from a Pokémon obtained in an official game, using [***PKHeX***](https://github.com/kwsch/PKHeX)'s legality checker as the reference as opposed to Game Freak's) once transferred to a Generation 4 game, with one outlier.
  * The exception to this will technically be illegal until it enters a Generation 7 game, but there should be no issues transferring it through Poké Transporter to Pokémon Bank.
* Save Files
  * There should be no (significant) issues importing your save file from Pokémon Emerald to Pokémon Heliodor and vice versa.
  * This allows Pokémon Heliodor to, in effect, be treated similar to an expansion pack in which if a player has already completed Pokémon Emerald, this can be used to "unlock" extra content/features for that playthrough.

### Changes

* All 386 Pokémon available within Generation 3 are obtainable.
  * Pokémon not normally found in Pokémon Emerald are generated with different game IDs, languages, and pseudo-random number generation methods to replicate the encounters in which they can normally be found in other games.
  * This includes new wild encounter tables post-National Dex acquisition, additional gifts, in-game trades, and an extended roamer quest.
    * If importing a save file from Pokémon Emerald after capturing/defeating the roaming Latias/Latios, speak to the new NPC at the Weather Institute to force the next roamer to initialize.
  * Trading is still required to get all starter Pokémon, as well as to initiate trade evolutions.
* An egg incubator is available for use that relies upon the real-time clock instead of the step counter.
* All tutor moves found in Generation 3 games are available for purchase at the Battle Frontier.
* Moves learned by level-up exclusively in Pokémon FireRed and Pokémon LeafGreen are added to the learnsets.
* Evolution items and Kanto-exclusive held items are available for purchase at the Battle Frontier.
* The remainder of the Kanto-exclusive items are available at the Lilycove Department Store.
* For Pokémon Colosseum and Pokémon XD: Gale of Darkness players, Poké Coupons that have been transferred to the cartridge can be used to purchase rare items.
  * Poké Coupons can also be obtained by trading in Battle Points at the Battle Frontier.
* e-Reader functionality has been restored with version and language restrictions removed.
  * The Legendary Titan dolls can be obtained without issue.
  * e-Card berries can be obtained, although Japanese berries will (obviously) have text errors.
    * The Game Boy Kid in the Cove Lily Motel has an e-Card to scan, allowing an e-Card berry to be obtained without having access to an e-Reader.
  * The Eon Ticket can be obtained, but the event text is slightly garbled.
    * The Eon Ticket can also be obtained during normal gameplay after defeating the Elite Four for the first time.
  * e-Card trainers will be saved, but can not actually be found to battle.
* The Pokémon summary screen now shows correct information for all locations in Pokémon Ruby, Pokémon Sapphire, Pokémon Colosseum, Pokémon XD: Gale of Darkness, as well as [***Pokémon CrystalDust***](https://github.com/Sierraffinity/CrystalDust).
* Breeding mechanics have been changed.
  * Both parents can now pass down Nature and moves.
  * The "Masuda Method" is implemented.
  * A bug affecting IV inheritance has been fixed.
* If the first member of the party is holding a Scope Lens, only Pokémon of that species will be found in the wild as long as that species is available at that location.
  * There is a 2% chance of failure for this effect.
* Methods to aid in obtaining Shiny Pokémon have been added.
  * As mentioned above, the [***Masuda Method***](https://bulbapedia.bulbagarden.net/wiki/Masuda_method) is implemented.
  * Once the National Dex has been completed, [***Shiny Charm***](https://bulbapedia.bulbagarden.net/wiki/Shiny_Charm) functionality is activated. (no item needs to be obtained for any of the Charm effects)
  * Successively encountering the same species of Pokémon will increase the odds of encountering a Shiny Pokémon.
* Once the Hoenn Dex has been completed, [***Oval Charm***](https://bulbapedia.bulbagarden.net/wiki/Oval_Charm) functionality is activated.
* Once the Elite Four has been defeated, [***Exp. Charm***](https://bulbapedia.bulbagarden.net/wiki/Exp._Charm) functionality is activated.
  * Catch rates are also boosted by 50% at this point.
* Net Ball, Dive Ball, and Repeat Ball mechanics have been updated to match the changes made in Generation 7.
* If any member of the party holds an Exp. Share, the whole party receives experience points from battle.
* Legendary Pokémon (and Sudowoodo) that have been defeated without being caught will respawn when the Elite Four is defeated.
  * The respawn will only trigger if the Pokémon is not registered as "caught" in the Pokédex, so trading over a legendary Pokémon will interfere with this.
  * Roaming Pokémon will respawn instantly somewhere in the region when knocked out.
* The clock offset can be changed by pressing 'B', 'Left', and 'Select' on the title screen.
* Secret Power, Cut, Surf, Strength, Rock Smash, Waterfall, and Dive can be used as long as one of the party members is capable of learning the move.
  * The respective badge is still required.
* EVs are capped at 252 per stat instead of 255.
  * The cap on EVs able to be earned through vitamins has been removed as well.
* The battle and summary screens report the correct type and base power for Hidden Power.
* Synchronize's field effect is 100% effective.
* If the first member of the party has Lightningrod or Flash Fire as its ability, there is a 50% chance of finding a Lightning or Fire-type Pokémon respectively in a wild encounter if an applicable encounter is possible in that area.
* Catching a Pokémon yields experience points.
* All TMs are purchasable.
* HM moves can be forgotten without the use of the Move Deleter.
* Trade evolutions can be triggered be leveling up in the Union Room.
  * The Union Room can be entered without the Wireless Adapter connected.
* Level-up evolutions can be triggered at level 100 by using a Rare Candy.
* The IV Judge at the Battle Frontier gives specific numbers for all stats.
  * Next door, there is an EV Judge as well as an EV Reseter.
  * An IV Judge is also at the Day Care on Route 117.
* A clock has been added to the start menu.
* The real-time clock effects the world visually.
* Trading restrictions with all Generation 3 games besides Pokémon XD: Gale of Darkness have been removed.
* A Premier Ball can be obtained as a gift for every 10 Poké Balls (of any kind) purchased at the Poké Mart.
* After a Repel's effect wears off, and if the player has more Repels in their Bag, they will be asked if they would like to use another immediately without having to go into the menu.
* Holding 'B' while surfing will cause a movement speed increase.
* The Bag inventory can be sorted.
* Two more Key Items can be registered to 'L' and 'R' to be used in the field.
* Numerous small features and graphics have been changed/added and bugs have been fixed.

## Known Issues

* If the game is saved on a map that has contains a new NPC and transferred to Pokémon Emerald, the game will freeze if the now-invisible NPC is spoken to.
  * This should not be a big deal, since leaving the map removes the issue, so it seems unlikely major progress can be lost this way.
* If an e-Card berry is obtained, the description text will be offset by a variable amount when viewed in Pokémon Emerald.  The berry's actual functionality should be unaffected, however.

If you encounter any other issues, especially relating to the three compatibility principles above, please let me know.

## Instructions

The release patch can be applied to a dump of Pokémon Emerald with a sha1 sum of f3ae088181bf583e55daf962a92bb46f4f1d07b7 using a program such as [***beat***](https://github.com/Screwtapello/beat) or [***Floating IPS***](https://github.com/Alcaro/Flips).

To build this yourself, see [INSTALL.md](INSTALL.md).


## Thanks to

* pret
* Project Pokémon
* The PKHeX team
* Bulbapedia
* Serebii
* DRayX
* Deokishisu
* ShinyDragonHunter
* Sierraffinity
* aldelaro5
* ghoulslash
