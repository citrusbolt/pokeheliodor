# Pokémon Heliodor

This is a modification of Pokémon Emerald intended to be an interpretation of the "definitive" Generation 3 Hoenn concept while still fitting firmly within the official game ecology.

The highest design priorities are 100% compatibility in terms of:
* Multiplayer
  * No changes made should interfere with any link capability with Pokémon Ruby, Pokémon Sapphire, Pokémon FireRed, Pokémon LeafGreen, Pokémon Emerald, Pokémon Box Ruby & Sapphire, Pokémon Colosseum, or Pokémon XD: Gales of Darkness.
* Inter-generational Transfer
  * Every Pokémon obtained should completely be legal (indistinguishable from a Pokémon obtained in an offical game, using PKHeX's legality checker as the reference as opposed to Game Freak's) once transfered to a Generation 4 game, with one outlier.
  * The exception to this will technically be illegal until it enters a Generation 7 game, but there should be no issues transfering it through Poké Transporter to Pokémon Bank.
* Save Files
  * There should be no issues importing your save file from Pokémon Emerald and Pokémon Heliodor and vice versa.
  * This allows Pokémon Heliodor to, in effect, be treated similar to an expansion pack in which if a player has already completed Pokémon Emerald, this can be used to "unlock" extra content/features for that playthrough.

### Changes

* All 386 Pokémon available within Generation 3 are obtainable.
  * Pokémon not normally found in Pokémon Emerald are generated with different game IDs, languages, and pseudo-random number generation methods to replicate the encounters in which they can normally be found in other games.
  * This includes new wild encounter tables post-National Dex acquisition, additional gifts, in-game trades, and an extended roamer quest.
    * If importing a save file from Pokémon Emerald after capturing/defeating the roaming Latias/Latios, speak to the new NPC at the Weather Institute to force the next roamer to initialize.
 * Trading is still required to get all starter Pokémon, as well as to initiate trade evolutions.
* An egg incubator is available for use that upon the real time clock instead of the step counter.
* All tutor moves found in Generation 3 games are available for purchase at the Battle Frontier.
* Moves learned by level-up exclusively in Pokémon FireRed and Pokémon LeafGreen are added to the learnsets.
* Evolution items and Kanto-exclusive held items are available for purchase at the Battle Frontier.
* The remainder of the Kanto-exclusive items are available at the Lilycove Department Store.
* For Pokémon Colosseum and Pokémon XD: Gales of Darkness players, Poké Coupon balance can be viewed on the PC
  * This option only appears if Poké Coupons have been transfered at least once so that it doesn't get in the way for players who do not have access to the Gamecube games.
* Altering Cave's wild encounters cycle through the unreleased Mystery Gift tables every day.
* Add new Met Location strings for all locations in Pokémon Ruby, Pokémon Sapphire, Pokémon Colossuem, Pokémon XD: Gales of Darkness, as well as [***Pokémon CrystalDust***](https://github.com/Sierraffinity/CrystalDust).
* Breeding mechanics have been changed.
  * Both parents can now pass down Nature and moves.
  * The "Masuda Method" is implemented.
  * A bug in IV inheritance has been fixed.
* Trading restrictions with all Generation 3 games besides Pokémon XD: Gales of Darkness have been removed.
* Numerous small features have been changed/added and bugs have been fixed.
* And more!

### Issues

* If the game is saved on a map that has contains a new NPC and transfered to Pokémon Emerald, the game will freeze if the now-invisible NPC is spoken to.
  * This should be a big deal, since leaving the map removes the issue, so it seems unlikely major progress can be lost this way.

If you encounter any other issues, especially relating to the three compatibility principles above, please let me know.


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
