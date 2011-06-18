/******************************************************************************

    mamedriv.c

    Copyright Nicola Salmoria and the MAME Team.
    Visit http://mamedev.org for licensing and usage restrictions.

    The list of all available drivers. Drivers have to be included here to be
    recognized by the executable.

    To save some typing, we use a hack here. This file is recursively #included
    twice, with different definitions of the DRIVER() macro. The first one
    declares external references to the drivers; the second one builds an array
    storing all the drivers.

******************************************************************************/

#include "emu.h"

#ifndef DRIVER_RECURSIVE
#include "pinball.lh"

#define DRIVER_RECURSIVE

/* step 1: declare all external references */
#define DRIVER(NAME) GAME_EXTERN(NAME);
#include "mamedriv.c"

/* step 2: define the drivers[] array */
#undef DRIVER
#define DRIVER(NAME) &GAME_NAME(NAME),
const game_driver * const drivers[] =
{
#include "mamedriv.c"
	0	/* end of array */
};

#else	/* DRIVER_RECURSIVE */

#ifdef PS3_SET_1
//SET: puckman
		DRIVER(puckman) //t:puckman f:pacman.c r: c:
		DRIVER(puckmana) //t:puckmana f:pacman.c r:puckman c:puckman
		DRIVER(puckmanf) //t:puckmanf f:pacman.c r:puckman c:puckman
		DRIVER(puckmanh) //t:puckmanh f:pacman.c r:puckman c:puckman
		DRIVER(pacman) //t:pacman f:pacman.c r:puckman c:puckman
		DRIVER(pacmanf) //t:pacmanf f:pacman.c r:puckman c:puckman
		DRIVER(puckmod) //t:puckmod f:pacman.c r:puckman c:puckman
		DRIVER(pacmod) //t:pacmod f:pacman.c r:puckman c:puckman
		DRIVER(newpuc2) //t:newpuc2 f:pacman.c r:puckman c:puckman
		DRIVER(newpuc2b) //t:newpuc2b f:pacman.c r:puckman c:puckman
		DRIVER(newpuckx) //t:newpuckx f:pacman.c r:puckman c:puckman
		DRIVER(pacheart) //t:pacheart f:pacman.c r:puckman c:puckman
		DRIVER(bucaner) //t:bucaner f:pacman.c r:puckman c:puckman
		DRIVER(hangly) //t:hangly f:pacman.c r:puckman c:puckman
		DRIVER(hangly2) //t:hangly2 f:pacman.c r:puckman c:puckman
		DRIVER(hangly3) //t:hangly3 f:pacman.c r:puckman c:puckman
		DRIVER(popeyeman) //t:popeyeman f:pacman.c r:puckman c:puckman
		DRIVER(piranhah) //t:piranhah f:pacman.c r:puckman c:puckman
		DRIVER(abscam) //t:abscam f:pacman.c r:puckman c:puckman
		DRIVER(joyman) //t:joyman f:pacman.c r:puckman c:puckman
		DRIVER(ctrpllrp) //t:ctrpllrp f:pacman.c r:puckman c:puckman
		DRIVER(piranha) //t:piranha f:pacman.c r:puckman c:puckman
		DRIVER(piranhao) //t:piranhao f:pacman.c r:puckman c:puckman
		DRIVER(pacmanbl) //t:pacmanbl f:galdrvr.c r:puckman c:puckman
		DRIVER(pacmanbla) //t:pacmanbla f:galdrvr.c r:puckman c:puckman
//SET: crush
		DRIVER(crush) //t:crush f:pacman.c r: c:
		DRIVER(crushbl) //t:crushbl f:pacman.c r:crush c:crush
		DRIVER(crushbl2) //t:crushbl2 f:pacman.c r:crush c:crush
		DRIVER(crush2) //t:crush2 f:pacman.c r:crush c:crush
		DRIVER(crush3) //t:crush3 f:pacman.c r:crush c:crush
		DRIVER(crush4) //t:crush4 f:pacman.c r:crush c:crush
		DRIVER(maketrax) //t:maketrax f:pacman.c r:crush c:crush
		DRIVER(maketrxb) //t:maketrxb f:pacman.c r:crush c:crush
		DRIVER(korosuke) //t:korosuke f:pacman.c r:crush c:crush
		DRIVER(mbrush) //t:mbrush f:pacman.c r:crush c:crush
		DRIVER(paintrlr) //t:paintrlr f:pacman.c r:crush c:crush
		DRIVER(crushs) //t:crushs f:pacman.c r:crush c:crush
//SET: pacplus
		DRIVER(pacplus) //t:pacplus f:pacman.c r: c:
//SET: eyes
		DRIVER(eyes) //t:eyes f:pacman.c r: c:
		DRIVER(eyes2) //t:eyes2 f:pacman.c r:eyes c:eyes
		DRIVER(eyeszac) //t:eyeszac f:pacman.c r:eyes c:eyes
//SET: mrtnt
		DRIVER(mrtnt) //t:mrtnt f:pacman.c r: c:
		DRIVER(gorkans) //t:gorkans f:pacman.c r:mrtnt c:mrtnt
//SET: eggor
		DRIVER(eggor) //t:eggor f:pacman.c r: c:
//SET: jumpshot
		DRIVER(jumpshot) //t:jumpshot f:pacman.c r: c:
		DRIVER(jumpshotp) //t:jumpshotp f:pacman.c r:jumpshot c:jumpshot
//SET: shootbul
		DRIVER(shootbul) //t:shootbul f:pacman.c r: c:
//SET: nmouse
		DRIVER(nmouse) //t:nmouse f:pacman.c r: c:
		DRIVER(nmouseb) //t:nmouseb f:pacman.c r:nmouse c:nmouse
//SET: mspacman
		DRIVER(mspacman) //t:mspacman f:pacman.c r: c:
		DRIVER(mspacmnf) //t:mspacmnf f:pacman.c r:mspacman c:mspacman
		DRIVER(mspacmat) //t:mspacmat f:pacman.c r:mspacman c:mspacman
		DRIVER(mspacmab) //t:mspacmab f:pacman.c r:mspacman c:mspacman
		DRIVER(mspacmbe) //t:mspacmbe f:pacman.c r:mspacman c:mspacman
		DRIVER(pacgal) //t:pacgal f:pacman.c r:mspacman c:mspacman
		DRIVER(mspacpls) //t:mspacpls f:pacman.c r:mspacman c:mspacman
		DRIVER(mschamp) //t:mschamp f:pacman.c r:mspacman c:mspacman
		DRIVER(mschamps) //t:mschamps f:pacman.c r:mspacman c:mspacman
//SET: woodpeck
		DRIVER(woodpeck) //t:woodpeck f:pacman.c r: c:
		DRIVER(woodpeca) //t:woodpeca f:pacman.c r:woodpeck c:woodpeck
//SET: ponpoko
		DRIVER(ponpoko) //t:ponpoko f:pacman.c r: c:
		DRIVER(ponpokov) //t:ponpokov f:pacman.c r:ponpoko c:ponpoko
//SET: lizwiz
		DRIVER(lizwiz) //t:lizwiz f:pacman.c r: c:
//SET: alibaba
		DRIVER(alibaba) //t:alibaba f:pacman.c r: c:
//SET: dremshpr
		DRIVER(dremshpr) //t:dremshpr f:pacman.c r: c:
//SET: vanvan
		DRIVER(vanvan) //t:vanvan f:pacman.c r: c:
		DRIVER(vanvank) //t:vanvank f:pacman.c r:vanvan c:vanvan
		DRIVER(vanvanb) //t:vanvanb f:pacman.c r:vanvan c:vanvan
//SET: bwcasino
		DRIVER(bwcasino) //t:bwcasino f:pacman.c r: c:
		DRIVER(acitya) //t:acitya f:pacman.c r:bwcasino c:bwcasino
//SET: rocktrv2
		DRIVER(rocktrv2) //t:rocktrv2 f:pacman.c r: c:
//SET: bigbucks
		DRIVER(bigbucks) //t:bigbucks f:pacman.c r: c:
//SET: cannonbp
		DRIVER(cannonbp) //t:cannonbp f:pacman.c r: c:
		DRIVER(cannonb) //t:cannonb f:cclimber.c r:cannonbp c:cannonbp
		DRIVER(cannonb2) //t:cannonb2 f:cclimber.c r:cannonbp c:cannonbp
		DRIVER(cannonb3) //t:cannonb3 f:cclimber.c r:cannonbp c:cannonbp
//SET: drivfrcp
		DRIVER(drivfrcp) //t:drivfrcp f:pacman.c r: c:
		DRIVER(drivfrcg) //t:drivfrcg f:galaxold.c r:drivfrcp c:drivfrcp
		DRIVER(drivfrcb) //t:drivfrcb f:galaxold.c r:drivfrcp c:drivfrcp
//SET: porky
		DRIVER(porky) //t:porky f:pacman.c r: c:
//SET: pengo
		DRIVER(pengo) //t:pengo f:pengo.c r: c:
		DRIVER(pengo2) //t:pengo2 f:pengo.c r:pengo c:pengo
		DRIVER(pengo2u) //t:pengo2u f:pengo.c r:pengo c:pengo
		DRIVER(pengo3u) //t:pengo3u f:pengo.c r:pengo c:pengo
		DRIVER(pengo4) //t:pengo4 f:pengo.c r:pengo c:pengo
		DRIVER(pengob) //t:pengob f:pengo.c r:pengo c:pengo
		DRIVER(penta) //t:penta f:pengo.c r:pengo c:pengo
//SET: jrpacman
		DRIVER(jrpacman) //t:jrpacman f:jrpacman.c r: c:
		DRIVER(jrpacmbl) //t:jrpacmbl f:pengo.c r:jrpacman c:jrpacman
//SET: megadon
		DRIVER(megadon) //t:megadon f:epos.c r: c:
//SET: catapult
		DRIVER(catapult) //t:catapult f:epos.c r: c:
//SET: suprglob
		DRIVER(suprglob) //t:suprglob f:epos.c r: c:
		DRIVER(theglobp) //t:theglobp f:pacman.c r:suprglob c:suprglob
		DRIVER(sprglobp) //t:sprglobp f:pacman.c r:suprglob c:suprglob
		DRIVER(sprglbpg) //t:sprglbpg f:pacman.c r:suprglob c:suprglob
		DRIVER(beastf) //t:beastf f:pacman.c r:suprglob c:suprglob
		DRIVER(theglob) //t:theglob f:epos.c r:suprglob c:suprglob
		DRIVER(theglob2) //t:theglob2 f:epos.c r:suprglob c:suprglob
		DRIVER(theglob3) //t:theglob3 f:epos.c r:suprglob c:suprglob
//SET: igmo
		DRIVER(igmo) //t:igmo f:epos.c r: c:
//SET: dealer
		DRIVER(dealer) //t:dealer f:epos.c r: c:
//SET: revenger
		DRIVER(revenger) //t:revenger f:epos.c r: c:
//SET: galaxian
		DRIVER(galaxian) //t:galaxian f:galdrvr.c r: c:
		DRIVER(galaxiana) //t:galaxiana f:galdrvr.c r:galaxian c:galaxian
		DRIVER(galaxianm) //t:galaxianm f:galdrvr.c r:galaxian c:galaxian
		DRIVER(galaxianmo) //t:galaxianmo f:galdrvr.c r:galaxian c:galaxian
		DRIVER(galaxiant) //t:galaxiant f:galdrvr.c r:galaxian c:galaxian
		DRIVER(superg) //t:superg f:galdrvr.c r:galaxian c:galaxian
		DRIVER(galapx) //t:galapx f:galdrvr.c r:galaxian c:galaxian
		DRIVER(moonaln) //t:moonaln f:galdrvr.c r:galaxian c:galaxian
		DRIVER(galap1) //t:galap1 f:galdrvr.c r:galaxian c:galaxian
		DRIVER(galap4) //t:galap4 f:galdrvr.c r:galaxian c:galaxian
		DRIVER(galturbo) //t:galturbo f:galdrvr.c r:galaxian c:galaxian
		DRIVER(swarm) //t:swarm f:galdrvr.c r:galaxian c:galaxian
		DRIVER(zerotime) //t:zerotime f:galdrvr.c r:galaxian c:galaxian
		DRIVER(starfght) //t:starfght f:galdrvr.c r:galaxian c:galaxian
		DRIVER(galaxbsf) //t:galaxbsf f:galdrvr.c r:galaxian c:galaxian
		DRIVER(kamakazi3) //t:kamakazi3 f:galdrvr.c r:galaxian c:galaxian
		DRIVER(tst_galx) //t:tst_galx f:galdrvr.c r:galaxian c:galaxian
		DRIVER(moonal2) //t:moonal2 f:galdrvr.c r:galaxian c:galaxian
		DRIVER(moonal2b) //t:moonal2b f:galdrvr.c r:galaxian c:galaxian
		DRIVER(supergx) //t:supergx f:galdrvr.c r:galaxian c:galaxian
//SET: gmgalax
		DRIVER(gmgalax) //t:gmgalax f:galdrvr.c r: c:
//SET: pisces
		DRIVER(pisces) //t:pisces f:galdrvr.c r: c:
		DRIVER(piscesb) //t:piscesb f:galdrvr.c r:pisces c:pisces
		DRIVER(omni) //t:omni f:galdrvr.c r:pisces c:pisces
//SET: uniwars
		DRIVER(uniwars) //t:uniwars f:galdrvr.c r: c:
		DRIVER(gteikoku) //t:gteikoku f:galdrvr.c r:uniwars c:uniwars
		DRIVER(gteikokb) //t:gteikokb f:galdrvr.c r:uniwars c:uniwars
		DRIVER(gteikob2) //t:gteikob2 f:galdrvr.c r:uniwars c:uniwars
		DRIVER(spacbatt) //t:spacbatt f:galdrvr.c r:uniwars c:uniwars
		DRIVER(spacbat2) //t:spacbat2 f:galdrvr.c r:uniwars c:uniwars
		DRIVER(spacempr) //t:spacempr f:galdrvr.c r:uniwars c:uniwars
		DRIVER(skyraidr) //t:skyraidr f:galdrvr.c r:uniwars c:uniwars
//SET: warofbug
		DRIVER(warofbug) //t:warofbug f:galdrvr.c r: c:
		DRIVER(warofbugg) //t:warofbugg f:galdrvr.c r:warofbug c:warofbug
//SET: redufo
		DRIVER(redufo) //t:redufo f:galdrvr.c r: c:
		DRIVER(redufob) //t:redufob f:galdrvr.c r:redufo c:redufo
		DRIVER(exodus) //t:exodus f:galdrvr.c r:redufo c:redufo
//SET: streakng
		DRIVER(streakng) //t:streakng f:galdrvr.c r: c:
		DRIVER(streaknga) //t:streaknga f:galdrvr.c r:streakng c:streakng
//SET: tenspot
		DRIVER(tenspot) //t:tenspot f:galdrvr.c r: c:
//SET: zigzag
		DRIVER(zigzag) //t:zigzag f:galdrvr.c r: c:
		DRIVER(zigzag2) //t:zigzag2 f:galdrvr.c r:zigzag c:zigzag
//SET: jumpbug
		DRIVER(jumpbug) //t:jumpbug f:galdrvr.c r: c:
		DRIVER(jumpbugb) //t:jumpbugb f:galdrvr.c r:jumpbug c:jumpbug
//SET: levers
		DRIVER(levers) //t:levers f:galdrvr.c r: c:
//SET: azurian
		DRIVER(azurian) //t:azurian f:galdrvr.c r: c:
//SET: orbitron
		DRIVER(orbitron) //t:orbitron f:galdrvr.c r: c:
//SET: mooncrst
		DRIVER(mooncrst) //t:mooncrst f:galdrvr.c r: c:
		DRIVER(mooncrgx) //t:mooncrgx f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(mooncrstu) //t:mooncrstu f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(mooncrsto) //t:mooncrsto f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(mooncrstg) //t:mooncrstg f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(mooncrstuk) //t:mooncrstuk f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(smooncrs) //t:smooncrs f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(sstarcrs) //t:sstarcrs f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(mooncmw) //t:mooncmw f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(mooncrsb) //t:mooncrsb f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(mooncrs2) //t:mooncrs2 f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(spcdrag) //t:spcdrag f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(stera) //t:stera f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(spcdraga) //t:spcdraga f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(mooncrs3) //t:mooncrs3 f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(fantazia) //t:fantazia f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(eagle) //t:eagle f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(eagle2) //t:eagle2 f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(eagle3) //t:eagle3 f:galdrvr.c r:mooncrst c:mooncrst
		DRIVER(spctbird) //t:spctbird f:galdrvr.c r:mooncrst c:mooncrst
//SET: moonqsr
		DRIVER(moonqsr) //t:moonqsr f:galdrvr.c r: c:
//SET: mshuttle
		DRIVER(mshuttle) //t:mshuttle f:galdrvr.c r: c:
		DRIVER(mshuttle2) //t:mshuttle2 f:galdrvr.c r:mshuttle c:mshuttle
		DRIVER(mshuttlej) //t:mshuttlej f:galdrvr.c r:mshuttle c:mshuttle
		DRIVER(mshuttlej2) //t:mshuttlej2 f:galdrvr.c r:mshuttle c:mshuttle
//SET: skybase
		DRIVER(skybase) //t:skybase f:galdrvr.c r: c:
//SET: checkman
		DRIVER(checkman) //t:checkman f:galdrvr.c r: c:
		DRIVER(checkmanj) //t:checkmanj f:galdrvr.c r:checkman c:checkman
//SET: dingo
		DRIVER(dingo) //t:dingo f:galdrvr.c r: c:
		DRIVER(dingoe) //t:dingoe f:galdrvr.c r:dingo c:dingo
//SET: blkhole
		DRIVER(blkhole) //t:blkhole f:galdrvr.c r: c:
//SET: kingball
		DRIVER(kingball) //t:kingball f:galdrvr.c r: c:
		DRIVER(kingballj) //t:kingballj f:galdrvr.c r:kingball c:kingball
//SET: 4in1
		DRIVER(4in1) //t:4in1 f:galaxold.c r: c:
//SET: ozon1
		DRIVER(ozon1) //t:ozon1 f:galaxold.c r: c:
//SET: bongo
		DRIVER(bongo) //t:bongo f:galaxold.c r: c:
//SET: harem
		DRIVER(harem) //t:harem f:galaxold.c r: c:
//SET: racknrol
		DRIVER(racknrol) //t:racknrol f:galaxold.c r: c:
		DRIVER(hexpool) //t:hexpool f:galaxold.c r:racknrol c:racknrol
		DRIVER(hexpoola) //t:hexpoola f:galaxold.c r:racknrol c:racknrol
//SET: trvchlng
		DRIVER(trvchlng) //t:trvchlng f:galaxold.c r: c:
//SET: luctoday
		DRIVER(luctoday) //t:luctoday f:galdrvr.c r: c:
		DRIVER(chewing) //t:chewing f:galdrvr.c r:luctoday c:luctoday
//SET: catacomb
		DRIVER(catacomb) //t:catacomb f:galdrvr.c r: c:
//SET: vstars
		DRIVER(vstars) //t:vstars f:galaxold.c r: c:
//SET: tdpgal
		DRIVER(tdpgal) //t:tdpgal f:galdrvr.c r: c:
//SET: rockclim
		DRIVER(rockclim) //t:rockclim f:galaxold.c r: c:
//SET: scramble
		DRIVER(scramble) //t:scramble f:galdrvr.c r: c:
		DRIVER(scrambles) //t:scrambles f:galdrvr.c r:scramble c:scramble
		DRIVER(scramblebf) //t:scramblebf f:galdrvr.c r:scramble c:scramble
		DRIVER(scramblebb) //t:scramblebb f:galdrvr.c r:scramble c:scramble
		DRIVER(scramblb) //t:scramblb f:galaxold.c r:scramble c:scramble
		DRIVER(scramb2) //t:scramb2 f:galaxold.c r:scramble c:scramble
		DRIVER(explorer) //t:explorer f:galdrvr.c r:scramble c:scramble
		DRIVER(strfbomb) //t:strfbomb f:galdrvr.c r:scramble c:scramble
//SET: atlantis
		DRIVER(atlantis) //t:atlantis f:galdrvr.c r: c:
		DRIVER(atlantisb) //t:atlantisb f:galdrvr.c r:atlantis c:atlantis
		DRIVER(atlantis2) //t:atlantis2 f:galdrvr.c r:atlantis c:atlantis
//SET: theend
		DRIVER(theend) //t:theend f:galdrvr.c r: c:
		DRIVER(theends) //t:theends f:galdrvr.c r:theend c:theend
		DRIVER(omega) //t:omega f:galdrvr.c r:theend c:theend
//SET: triplep
		DRIVER(triplep) //t:triplep f:scramble.c r: c:
		DRIVER(knockout) //t:knockout f:scramble.c r:triplep c:triplep
//SET: mariner
		DRIVER(mariner) //t:mariner f:scramble.c r: c:
		DRIVER(800fath) //t:800fath f:scramble.c r:mariner c:mariner
//SET: mars
		DRIVER(mars) //t:mars f:scramble.c r: c:
//SET: devilfsh
		DRIVER(devilfsh) //t:devilfsh f:scramble.c r: c:
		DRIVER(devilfsg) //t:devilfsg f:galdrvr.c r:devilfsh c:devilfsh
//SET: newsin7
		DRIVER(newsin7) //t:newsin7 f:scramble.c r: c:
//SET: mrkougar
		DRIVER(mrkougar) //t:mrkougar f:scramble.c r: c:
		DRIVER(mrkougar2) //t:mrkougar2 f:scramble.c r:mrkougar c:mrkougar
		DRIVER(mrkougb) //t:mrkougb f:scramble.c r:mrkougar c:mrkougar
		DRIVER(mrkougb2) //t:mrkougb2 f:scramble.c r:mrkougar c:mrkougar
//SET: hotshock
		DRIVER(hotshock) //t:hotshock f:scramble.c r: c:
		DRIVER(hotshockb) //t:hotshockb f:scramble.c r:hotshock c:hotshock
//SET: conquer
		DRIVER(conquer) //t:conquer f:scramble.c r: c:
//SET: cavelon
		DRIVER(cavelon) //t:cavelon f:scramble.c r: c:
//SET: sfx
		DRIVER(sfx) //t:sfx f:galdrvr.c r: c:
		DRIVER(skelagon) //t:skelagon f:galdrvr.c r:sfx c:sfx
//SET: monsterz
		DRIVER(monsterz) //t:monsterz f:galdrvr.c r: c:
//SET: mimonkey
		DRIVER(mimonkey) //t:mimonkey f:scobra.c r: c:
		DRIVER(mimonscr) //t:mimonscr f:scramble.c r:mimonkey c:mimonkey
		DRIVER(mimonsco) //t:mimonsco f:scobra.c r:mimonkey c:mimonkey
//SET: scobra
		DRIVER(scobra) //t:scobra f:galdrvr.c r: c:
		DRIVER(scobras) //t:scobras f:galdrvr.c r:scobra c:scobra
		DRIVER(scobrase) //t:scobrase f:galdrvr.c r:scobra c:scobra
		DRIVER(scobrab) //t:scobrab f:galdrvr.c r:scobra c:scobra
		DRIVER(suprheli) //t:suprheli f:galdrvr.c r:scobra c:scobra
//SET: stratgyx
		DRIVER(stratgyx) //t:stratgyx f:scobra.c r: c:
		DRIVER(stratgys) //t:stratgys f:scobra.c r:stratgyx c:stratgyx
		DRIVER(strongx) //t:strongx f:scobra.c r:stratgyx c:stratgyx
//SET: armorcar
		DRIVER(armorcar) //t:armorcar f:galdrvr.c r: c:
		DRIVER(armorcar2) //t:armorcar2 f:galdrvr.c r:armorcar c:armorcar
//SET: moonwar
		DRIVER(moonwar) //t:moonwar f:galdrvr.c r: c:
		DRIVER(moonwara) //t:moonwara f:galdrvr.c r:moonwar c:moonwar
//SET: spdcoin
		DRIVER(spdcoin) //t:spdcoin f:galdrvr.c r: c:
//SET: darkplnt
		DRIVER(darkplnt) //t:darkplnt f:scobra.c r: c:
//SET: tazmania
		DRIVER(tazmania) //t:tazmania f:galdrvr.c r: c:
		DRIVER(tazzmang) //t:tazzmang f:galaxold.c r:tazmania c:tazmania
		DRIVER(tazmani2) //t:tazmani2 f:scobra.c r:tazmania c:tazmania
//SET: calipso
		DRIVER(calipso) //t:calipso f:galdrvr.c r: c:
//SET: anteater
		DRIVER(anteater) //t:anteater f:galdrvr.c r: c:
		DRIVER(anteaterg) //t:anteaterg f:galdrvr.c r:anteater c:anteater
		DRIVER(anteateruk) //t:anteateruk f:galdrvr.c r:anteater c:anteater
//SET: rescue
		DRIVER(rescue) //t:rescue f:scobra.c r: c:
		DRIVER(aponow) //t:aponow f:scobra.c r:rescue c:rescue
//SET: minefld
		DRIVER(minefld) //t:minefld f:scobra.c r: c:
//SET: losttomb
		DRIVER(losttomb) //t:losttomb f:galdrvr.c r: c:
		DRIVER(losttombh) //t:losttombh f:galdrvr.c r:losttomb c:losttomb
//SET: superbon
		DRIVER(superbon) //t:superbon f:galdrvr.c r: c:
//SET: hustler
		DRIVER(hustler) //t:hustler f:scobra.c r: c:
		DRIVER(vpool) //t:vpool f:galaxold.c r:hustler c:hustler
		DRIVER(hustlerd) //t:hustlerd f:scobra.c r:hustler c:hustler
		DRIVER(billiard) //t:billiard f:scobra.c r:hustler c:hustler
		DRIVER(hustlerb) //t:hustlerb f:scobra.c r:hustler c:hustler
		DRIVER(hustlerb2) //t:hustlerb2 f:scobra.c r:hustler c:hustler
//SET: frogger
		DRIVER(frogger) //t:frogger f:galdrvr.c r: c:
		DRIVER(frogg) //t:frogg f:galdrvr.c r:frogger c:frogger
		DRIVER(froggers) //t:froggers f:galdrvr.c r:frogger c:frogger
		DRIVER(frogf) //t:frogf f:galdrvr.c r:frogger c:frogger
		DRIVER(froggers1) //t:froggers1 f:galdrvr.c r:frogger c:frogger
		DRIVER(froggers2) //t:froggers2 f:galdrvr.c r:frogger c:frogger
		DRIVER(froggermc) //t:froggermc f:galdrvr.c r:frogger c:frogger
//SET: amidar
		DRIVER(amidar) //t:amidar f:galdrvr.c r: c:
		DRIVER(amidars) //t:amidars f:galdrvr.c r:amidar c:amidar
		DRIVER(amidaru) //t:amidaru f:galdrvr.c r:amidar c:amidar
		DRIVER(amidaro) //t:amidaro f:galdrvr.c r:amidar c:amidar
		DRIVER(amidarb) //t:amidarb f:galdrvr.c r:amidar c:amidar
		DRIVER(amigo) //t:amigo f:galdrvr.c r:amidar c:amidar
//SET: turtles
		DRIVER(turtles) //t:turtles f:galdrvr.c r: c:
		DRIVER(turpin) //t:turpin f:galdrvr.c r:turtles c:turtles
		DRIVER(600) //t:600 f:galdrvr.c r:turtles c:turtles
		DRIVER(turpins) //t:turpins f:scramble.c r:turtles c:turtles
//SET: flyboy
		DRIVER(flyboy) //t:flyboy f:fastfred.c r: c:
		DRIVER(flyboyb) //t:flyboyb f:fastfred.c r:flyboy c:flyboy
		DRIVER(fastfred) //t:fastfred f:fastfred.c r:flyboy c:flyboy
//SET: jumpcoas
		DRIVER(jumpcoas) //t:jumpcoas f:fastfred.c r: c:
		DRIVER(jumpcoast) //t:jumpcoast f:fastfred.c r:jumpcoas c:jumpcoas
//SET: boggy84
		DRIVER(boggy84) //t:boggy84 f:fastfred.c r: c:
		DRIVER(boggy84b) //t:boggy84b f:fastfred.c r:boggy84 c:boggy84
//SET: redrobin
		DRIVER(redrobin) //t:redrobin f:fastfred.c r: c:
//SET: imago
		DRIVER(imago) //t:imago f:fastfred.c r: c:
		DRIVER(imagoa) //t:imagoa f:fastfred.c r:imago c:imago
//SET: scorpion
		DRIVER(scorpion) //t:scorpion f:galdrvr.c r: c:
		DRIVER(scorpionmc) //t:scorpionmc f:galdrvr.c r:scorpion c:scorpion
		DRIVER(scorpiona) //t:scorpiona f:galdrvr.c r:scorpion c:scorpion
		DRIVER(scorpionb) //t:scorpionb f:galdrvr.c r:scorpion c:scorpion
		DRIVER(aracnis) //t:aracnis f:galdrvr.c r:scorpion c:scorpion
//SET: ad2083
		DRIVER(ad2083) //t:ad2083 f:scramble.c r: c:
//SET: cclimber
		DRIVER(cclimber) //t:cclimber f:cclimber.c r: c:
		DRIVER(cclimberj) //t:cclimberj f:cclimber.c r:cclimber c:cclimber
		DRIVER(ccboot) //t:ccboot f:cclimber.c r:cclimber c:cclimber
		DRIVER(ccboot2) //t:ccboot2 f:cclimber.c r:cclimber c:cclimber
//SET: ckong
		DRIVER(ckong) //t:ckong f:cclimber.c r: c:
		DRIVER(ckongg) //t:ckongg f:galaxold.c r:ckong c:ckong
		DRIVER(ckongmc) //t:ckongmc f:galaxold.c r:ckong c:ckong
		DRIVER(ckongs) //t:ckongs f:scramble.c r:ckong c:ckong
		DRIVER(ckongo) //t:ckongo f:cclimber.c r:ckong c:ckong
		DRIVER(ckongalc) //t:ckongalc f:cclimber.c r:ckong c:ckong
		DRIVER(bigkong) //t:bigkong f:cclimber.c r:ckong c:ckong
		DRIVER(monkeyd) //t:monkeyd f:cclimber.c r:ckong c:ckong
//SET: ckongpt2
		DRIVER(ckongpt2) //t:ckongpt2 f:cclimber.c r: c:
		DRIVER(ckongpt2a) //t:ckongpt2a f:cclimber.c r:ckongpt2 c:ckongpt2
		DRIVER(ckongpt2j) //t:ckongpt2j f:cclimber.c r:ckongpt2 c:ckongpt2
		DRIVER(ckongpt2jeu) //t:ckongpt2jeu f:cclimber.c r:ckongpt2 c:ckongpt2
		DRIVER(ckongpt2b) //t:ckongpt2b f:cclimber.c r:ckongpt2 c:ckongpt2
//SET: rpatrol
		DRIVER(rpatrol) //t:rpatrol f:cclimber.c r: c:
		DRIVER(rpatrolb) //t:rpatrolb f:cclimber.c r:rpatrol c:rpatrol
		DRIVER(silvland) //t:silvland f:cclimber.c r:rpatrol c:rpatrol
//SET: yamato
		DRIVER(yamato) //t:yamato f:cclimber.c r: c:
		DRIVER(yamato2) //t:yamato2 f:cclimber.c r:yamato c:yamato
//SET: toprollr
		DRIVER(toprollr) //t:toprollr f:cclimber.c r: c:
//SET: swimmer
		DRIVER(swimmer) //t:swimmer f:cclimber.c r: c:
		DRIVER(swimmera) //t:swimmera f:cclimber.c r:swimmer c:swimmer
		DRIVER(swimmerb) //t:swimmerb f:cclimber.c r:swimmer c:swimmer
//SET: guzzler
		DRIVER(guzzler) //t:guzzler f:cclimber.c r: c:
//SET: gomoku
		DRIVER(gomoku) //t:gomoku f:gomoku.c r: c:
//SET: wiping
		DRIVER(wiping) //t:wiping f:wiping.c r: c:
		DRIVER(rugrats) //t:rugrats f:wiping.c r:wiping c:wiping
//SET: dacholer
		DRIVER(dacholer) //t:dacholer f:dacholer.c r: c:
//SET: kickboy
		DRIVER(kickboy) //t:kickboy f:dacholer.c r: c:
//SET: friskyt
		DRIVER(friskyt) //t:friskyt f:seicross.c r: c:
		DRIVER(friskyta) //t:friskyta f:seicross.c r:friskyt c:friskyt
//SET: radrad
		DRIVER(radrad) //t:radrad f:seicross.c r: c:
//SET: seicross
		DRIVER(seicross) //t:seicross f:seicross.c r: c:
		DRIVER(sectrzon) //t:sectrzon f:seicross.c r:seicross c:seicross
//SET: firebatl
		DRIVER(firebatl) //t:firebatl f:clshroad.c r: c:
//SET: clshroad
		DRIVER(clshroad) //t:clshroad f:clshroad.c r: c:
		DRIVER(clshroads) //t:clshroads f:clshroad.c r:clshroad c:clshroad
		DRIVER(clshroadd) //t:clshroadd f:clshroad.c r:clshroad c:clshroad
//SET: tubep
		DRIVER(tubep) //t:tubep f:tubep.c r: c:
		DRIVER(tubepb) //t:tubepb f:tubep.c r:tubep c:tubep
//SET: rjammer
		DRIVER(rjammer) //t:rjammer f:tubep.c r: c:
//SET: magmax
		DRIVER(magmax) //t:magmax f:magmax.c r: c:
#endif

#ifdef PS3_SET_2
//SET: cop01
		DRIVER(cop01) //t:cop01 f:cop01.c r: c:
		DRIVER(cop01a) //t:cop01a f:cop01.c r:cop01 c:cop01
//SET: mightguy
		DRIVER(mightguy) //t:mightguy f:cop01.c r: c:
//SET: terracre
		DRIVER(terracre) //t:terracre f:terracre.c r: c:
		DRIVER(terracreo) //t:terracreo f:terracre.c r:terracre c:terracre
		DRIVER(terracrea) //t:terracrea f:terracre.c r:terracre c:terracre
		DRIVER(terracren) //t:terracren f:terracre.c r:terracre c:terracre
//SET: amazon
		DRIVER(amazon) //t:amazon f:terracre.c r: c:
		DRIVER(amatelas) //t:amatelas f:terracre.c r:amazon c:amazon
//SET: horekid
		DRIVER(horekid) //t:horekid f:terracre.c r: c:
		DRIVER(horekidb) //t:horekidb f:terracre.c r:horekid c:horekid
		DRIVER(boobhack) //t:boobhack f:terracre.c r:horekid c:horekid
//SET: galivan
		DRIVER(galivan) //t:galivan f:galivan.c r: c:
		DRIVER(galivan2) //t:galivan2 f:galivan.c r:galivan c:galivan
//SET: dangar
		DRIVER(dangar) //t:dangar f:galivan.c r: c:
		DRIVER(dangar2) //t:dangar2 f:galivan.c r:dangar c:dangar
		DRIVER(dangarb) //t:dangarb f:galivan.c r:dangar c:dangar
//SET: ninjemak
		DRIVER(ninjemak) //t:ninjemak f:galivan.c r: c:
		DRIVER(youma) //t:youma f:galivan.c r:ninjemak c:ninjemak
		DRIVER(youma2) //t:youma2 f:galivan.c r:ninjemak c:ninjemak
		DRIVER(youmab) //t:youmab f:galivan.c r:ninjemak c:ninjemak
		DRIVER(youmab2) //t:youmab2 f:galivan.c r:ninjemak c:ninjemak
//SET: legion
		DRIVER(legion) //t:legion f:armedf.c r: c:
		DRIVER(legiono) //t:legiono f:armedf.c r:legion c:legion
//SET: terraf
		DRIVER(terraf) //t:terraf f:armedf.c r: c:
		DRIVER(terrafb) //t:terrafb f:armedf.c r:terraf c:terraf
		DRIVER(terrafa) //t:terrafa f:armedf.c r:terraf c:terraf
		DRIVER(terrafu) //t:terrafu f:armedf.c r:terraf c:terraf
//SET: kodure
		DRIVER(kodure) //t:kodure f:armedf.c r: c:
//SET: armedf
		DRIVER(armedf) //t:armedf f:armedf.c r: c:
		DRIVER(armedff) //t:armedff f:armedf.c r:armedf c:armedf
//SET: cclimbr2
		DRIVER(cclimbr2) //t:cclimbr2 f:armedf.c r: c:
		DRIVER(cclimbr2a) //t:cclimbr2a f:armedf.c r:cclimbr2 c:cclimbr2
//SET: skyrobo
		DRIVER(skyrobo) //t:skyrobo f:bigfghtr.c r: c:
		DRIVER(bigfghtr) //t:bigfghtr f:bigfghtr.c r:skyrobo c:skyrobo
//SET: hyhoo
		DRIVER(hyhoo) //t:hyhoo f:hyhoo.c r: c:
//SET: hyhoo2
		DRIVER(hyhoo2) //t:hyhoo2 f:hyhoo.c r: c:
//SET: jangou
		DRIVER(jangou) //t:jangou f:jangou.c r: c:
//SET: macha
		DRIVER(macha) //t:macha f:jangou.c r: c:
//SET: jngolady
		DRIVER(jngolady) //t:jngolady f:jangou.c r: c:
//SET: cntrygrl
		DRIVER(cntrygrl) //t:cntrygrl f:jangou.c r: c:
		DRIVER(cntrygrla) //t:cntrygrla f:jangou.c r:cntrygrl c:cntrygrl
		DRIVER(fruitbun) //t:fruitbun f:jangou.c r:cntrygrl c:cntrygrl
//SET: roylcrdn
		DRIVER(roylcrdn) //t:roylcrdn f:jangou.c r: c:
//SET: luckygrl
		DRIVER(luckygrl) //t:luckygrl f:jangou.c r: c:
//SET: nightgal
		DRIVER(nightgal) //t:nightgal f:nightgal.c r: c:
//SET: ngtbunny
		DRIVER(ngtbunny) //t:ngtbunny f:nightgal.c r: c:
		DRIVER(royalngt) //t:royalngt f:nightgal.c r:ngtbunny c:ngtbunny
//SET: royalqn
		DRIVER(royalqn) //t:royalqn f:nightgal.c r: c:
//SET: sexygal
		DRIVER(sexygal) //t:sexygal f:nightgal.c r: c:
		DRIVER(sweetgal) //t:sweetgal f:nightgal.c r:sexygal c:sexygal
//SET: ngalsumr
		DRIVER(ngalsumr) //t:ngalsumr f:nightgal.c r: c:
//SET: pastelg
		DRIVER(pastelg) //t:pastelg f:pastelg.c r: c:
//SET: 3ds
		DRIVER(3ds) //t:3ds f:pastelg.c r: c:
		DRIVER(galds) //t:galds f:pastelg.c r:3ds c:3ds
//SET: crystalg
		DRIVER(crystalg) //t:crystalg f:nbmj8688.c r: c:
//SET: crystal2
		DRIVER(crystal2) //t:crystal2 f:nbmj8688.c r: c:
//SET: nightlov
		DRIVER(nightlov) //t:nightlov f:nbmj8688.c r: c:
//SET: citylove
		DRIVER(citylove) //t:citylove f:nbmj8688.c r: c:
		DRIVER(mcitylov) //t:mcitylov f:nbmj8688.c r:citylove c:citylove
//SET: apparel
		DRIVER(apparel) //t:apparel f:nbmj8688.c r: c:
//SET: secolove
		DRIVER(secolove) //t:secolove f:nbmj8688.c r: c:
//SET: barline
		DRIVER(barline) //t:barline f:nbmj8688.c r: c:
//SET: housemnq
		DRIVER(housemnq) //t:housemnq f:nbmj8688.c r: c:
//SET: housemn2
		DRIVER(housemn2) //t:housemn2 f:nbmj8688.c r: c:
//SET: livegal
		DRIVER(livegal) //t:livegal f:nbmj8688.c r: c:
//SET: seiha
		DRIVER(seiha) //t:seiha f:nbmj8688.c r: c:
		DRIVER(seiham) //t:seiham f:nbmj8688.c r:seiha c:seiha
//SET: mjgaiden
		DRIVER(mjgaiden) //t:mjgaiden f:nbmj8688.c r: c:
//SET: bijokkoy
		DRIVER(bijokkoy) //t:bijokkoy f:nbmj8688.c r: c:
//SET: iemoto
		DRIVER(iemoto) //t:iemoto f:nbmj8688.c r: c:
		DRIVER(iemotom) //t:iemotom f:nbmj8688.c r:iemoto c:iemoto
		DRIVER(ryuuha) //t:ryuuha f:nbmj8688.c r:iemoto c:iemoto
//SET: ojousan
		DRIVER(ojousan) //t:ojousan f:nbmj8688.c r: c:
		DRIVER(ojousanm) //t:ojousanm f:nbmj8688.c r:ojousan c:ojousan
//SET: bijokkog
		DRIVER(bijokkog) //t:bijokkog f:nbmj8688.c r: c:
//SET: orangec
		DRIVER(orangec) //t:orangec f:nbmj8688.c r: c:
		DRIVER(orangeci) //t:orangeci f:nbmj8688.c r:orangec c:orangec
		DRIVER(vipclub) //t:vipclub f:nbmj8688.c r:orangec c:orangec
//SET: korinai
		DRIVER(korinai) //t:korinai f:nbmj8688.c r: c:
		DRIVER(korinaim) //t:korinaim f:nbmj8688.c r:korinai c:korinai
//SET: kaguya
		DRIVER(kaguya) //t:kaguya f:nbmj8688.c r: c:
//SET: kaguya2
		DRIVER(kaguya2) //t:kaguya2 f:nbmj8688.c r: c:
		DRIVER(kaguya2f) //t:kaguya2f f:nbmj8688.c r:kaguya2 c:kaguya2
//SET: otonano
		DRIVER(otonano) //t:otonano f:nbmj8688.c r: c:
//SET: kanatuen
		DRIVER(kanatuen) //t:kanatuen f:nbmj8688.c r: c:
		DRIVER(kyuhito) //t:kyuhito f:nbmj8688.c r:kanatuen c:kanatuen
//SET: mjsikaku
		DRIVER(mjsikaku) //t:mjsikaku f:nbmj8688.c r: c:
		DRIVER(mjsikakb) //t:mjsikakb f:nbmj8688.c r:mjsikaku c:mjsikaku
		DRIVER(mjsikakc) //t:mjsikakc f:nbmj8688.c r:mjsikaku c:mjsikaku
		DRIVER(mjsikakd) //t:mjsikakd f:nbmj8688.c r:mjsikaku c:mjsikaku
		DRIVER(mmsikaku) //t:mmsikaku f:nbmj8688.c r:mjsikaku c:mjsikaku
//SET: mjcamera
		DRIVER(mjcamera) //t:mjcamera f:nbmj8688.c r: c:
//SET: msjiken
		DRIVER(msjiken) //t:msjiken f:nbmj8891.c r: c:
//SET: hanamomo
		DRIVER(hanamomo) //t:hanamomo f:nbmj8891.c r: c:
		DRIVER(hanamomb) //t:hanamomb f:nbmj8891.c r:hanamomo c:hanamomo
//SET: telmahjn
		DRIVER(telmahjn) //t:telmahjn f:nbmj8891.c r: c:
//SET: taiwanmb
		DRIVER(taiwanmb) //t:taiwanmb f:nbmj8891.c r: c:
//SET: gionbana
		DRIVER(gionbana) //t:gionbana f:nbmj8891.c r: c:
//SET: idhimitu
		DRIVER(idhimitu) //t:idhimitu f:nbmj8688.c r: c:
//SET: mgion
		DRIVER(mgion) //t:mgion f:nbmj8891.c r: c:
//SET: mjcamerb
		DRIVER(mjcamerb) //t:mjcamerb f:nbmj8891.c r: c:
		DRIVER(mmcamera) //t:mmcamera f:nbmj8891.c r:mjcamerb c:mjcamerb
//SET: omotesnd
		DRIVER(omotesnd) //t:omotesnd f:nbmj8891.c r: c:
//SET: abunai
		DRIVER(abunai) //t:abunai f:nbmj8891.c r: c:
//SET: mjfocus
		DRIVER(mjfocus) //t:mjfocus f:nbmj8891.c r: c:
		DRIVER(mjfocusm) //t:mjfocusm f:nbmj8891.c r:mjfocus c:mjfocus
		DRIVER(peepshow) //t:peepshow f:nbmj8891.c r:mjfocus c:mjfocus
//SET: scandal
		DRIVER(scandal) //t:scandal f:nbmj8891.c r: c:
		DRIVER(scandalm) //t:scandalm f:nbmj8891.c r:scandal c:scandal
//SET: mgmen89
		DRIVER(mgmen89) //t:mgmen89 f:nbmj8891.c r: c:
//SET: mjnanpas
		DRIVER(mjnanpas) //t:mjnanpas f:nbmj8891.c r: c:
		DRIVER(mjnanpaa) //t:mjnanpaa f:nbmj8891.c r:mjnanpas c:mjnanpas
		DRIVER(mjnanpau) //t:mjnanpau f:nbmj8891.c r:mjnanpas c:mjnanpas
//SET: pairsnb
		DRIVER(pairsnb) //t:pairsnb f:nbmj8891.c r: c:
		DRIVER(pairsten) //t:pairsten f:nbmj8891.c r:pairsnb c:pairsnb
//SET: bananadr
		DRIVER(bananadr) //t:bananadr f:nbmj8891.c r: c:
//SET: mladyhtr
		DRIVER(mladyhtr) //t:mladyhtr f:nbmj8891.c r: c:
//SET: chinmoku
		DRIVER(chinmoku) //t:chinmoku f:nbmj8891.c r: c:
//SET: maiko
		DRIVER(maiko) //t:maiko f:nbmj8891.c r: c:
//SET: mmaiko
		DRIVER(mmaiko) //t:mmaiko f:nbmj8891.c r: c:
//SET: hnageman
		DRIVER(hnageman) //t:hnageman f:nbmj8891.c r: c:
//SET: hnxmasev
		DRIVER(hnxmasev) //t:hnxmasev f:nbmj8891.c r: c:
//SET: club90s
		DRIVER(club90s) //t:club90s f:nbmj8891.c r: c:
		DRIVER(club90sa) //t:club90sa f:nbmj8891.c r:club90s c:club90s
		DRIVER(lovehous) //t:lovehous f:nbmj8891.c r:club90s c:club90s
//SET: hanaoji
		DRIVER(hanaoji) //t:hanaoji f:nbmj8891.c r: c:
//SET: pstadium
		DRIVER(pstadium) //t:pstadium f:nbmj8991.c r: c:
//SET: triplew1
		DRIVER(triplew1) //t:triplew1 f:nbmj8991.c r: c:
//SET: triplew2
		DRIVER(triplew2) //t:triplew2 f:nbmj8991.c r: c:
//SET: ntopstar
		DRIVER(ntopstar) //t:ntopstar f:nbmj8991.c r: c:
//SET: mjlstory
		DRIVER(mjlstory) //t:mjlstory f:nbmj8991.c r: c:
//SET: vanilla
		DRIVER(vanilla) //t:vanilla f:nbmj8991.c r: c:
		DRIVER(finalbny) //t:finalbny f:nbmj8991.c r:vanilla c:vanilla
//SET: qmhayaku
		DRIVER(qmhayaku) //t:qmhayaku f:nbmj8991.c r: c:
//SET: mjgottub
		DRIVER(mjgottub) //t:mjgottub f:nbmj8991.c r: c:
//SET: galkoku
		DRIVER(galkoku) //t:galkoku f:nbmj8991.c r: c:
		DRIVER(hyouban) //t:hyouban f:nbmj8991.c r:galkoku c:galkoku
//SET: galkaika
		DRIVER(galkaika) //t:galkaika f:nbmj8991.c r: c:
//SET: tokyogal
		DRIVER(tokyogal) //t:tokyogal f:nbmj8991.c r: c:
		DRIVER(tokimbsj) //t:tokimbsj f:nbmj8991.c r:tokyogal c:tokyogal
//SET: mcontest
		DRIVER(mcontest) //t:mcontest f:nbmj8991.c r: c:
//SET: uchuuai
		DRIVER(uchuuai) //t:uchuuai f:nbmj8991.c r: c:
//SET: av2mj1bb
		DRIVER(av2mj1bb) //t:av2mj1bb f:nbmj8991.c r: c:
//SET: av2mj2rg
		DRIVER(av2mj2rg) //t:av2mj2rg f:nbmj8991.c r: c:
//SET: ohpaipee
		DRIVER(ohpaipee) //t:ohpaipee f:nbmj8900.c r: c:
//SET: togenkyo
		DRIVER(togenkyo) //t:togenkyo f:nbmj8900.c r: c:
//SET: mjuraden
		DRIVER(mjuraden) //t:mjuraden f:nbmj9195.c r: c:
//SET: koinomp
		DRIVER(koinomp) //t:koinomp f:nbmj9195.c r: c:
//SET: patimono
		DRIVER(patimono) //t:patimono f:nbmj9195.c r: c:
//SET: janbari
		DRIVER(janbari) //t:janbari f:nbmj9195.c r: c:
		DRIVER(mjanbari) //t:mjanbari f:nbmj9195.c r:janbari c:janbari
//SET: ultramhm
		DRIVER(ultramhm) //t:ultramhm f:nbmj9195.c r: c:
//SET: gal10ren
		DRIVER(gal10ren) //t:gal10ren f:nbmj9195.c r: c:
//SET: renaiclb
		DRIVER(renaiclb) //t:renaiclb f:nbmj9195.c r: c:
//SET: mjlaman
		DRIVER(mjlaman) //t:mjlaman f:nbmj9195.c r: c:
//SET: mkeibaou
		DRIVER(mkeibaou) //t:mkeibaou f:nbmj9195.c r: c:
//SET: pachiten
		DRIVER(pachiten) //t:pachiten f:nbmj9195.c r: c:
//SET: sailorws
		DRIVER(sailorws) //t:sailorws f:nbmj9195.c r: c:
		DRIVER(sailorwa) //t:sailorwa f:nbmj9195.c r:sailorws c:sailorws
		DRIVER(sailorwr) //t:sailorwr f:nbmj9195.c r:sailorws c:sailorws
//SET: wcatcher
		DRIVER(wcatcher) //t:wcatcher f:nbmj9195.c r: c:
//SET: jituroku
		DRIVER(jituroku) //t:jituroku f:nbmj9195.c r: c:
//SET: yosimoto
		DRIVER(yosimoto) //t:yosimoto f:nbmj9195.c r: c:
//SET: psailor1
		DRIVER(psailor1) //t:psailor1 f:nbmj9195.c r: c:
//SET: psailor2
		DRIVER(psailor2) //t:psailor2 f:nbmj9195.c r: c:
//SET: otatidai
		DRIVER(otatidai) //t:otatidai f:nbmj9195.c r: c:
//SET: ngpgal
		DRIVER(ngpgal) //t:ngpgal f:nbmj9195.c r: c:
//SET: mjgottsu
		DRIVER(mjgottsu) //t:mjgottsu f:nbmj9195.c r: c:
		DRIVER(bakuhatu) //t:bakuhatu f:nbmj9195.c r:mjgottsu c:mjgottsu
//SET: cmehyou
		DRIVER(cmehyou) //t:cmehyou f:nbmj9195.c r: c:
//SET: mmehyou
		DRIVER(mmehyou) //t:mmehyou f:nbmj9195.c r: c:
//SET: mjkoiura
		DRIVER(mjkoiura) //t:mjkoiura f:nbmj9195.c r: c:
		DRIVER(mkoiuraa) //t:mkoiuraa f:nbmj9195.c r:mjkoiura c:mjkoiura
//SET: imekura
		DRIVER(imekura) //t:imekura f:nbmj9195.c r: c:
//SET: mscoutm
		DRIVER(mscoutm) //t:mscoutm f:nbmj9195.c r: c:
//SET: mjegolf
		DRIVER(mjegolf) //t:mjegolf f:nbmj9195.c r: c:
//SET: mhhonban
		DRIVER(mhhonban) //t:mhhonban f:niyanpai.c r: c:
//SET: 4psimasy
		DRIVER(4psimasy) //t:4psimasy f:niyanpai.c r: c:
//SET: musobana
		DRIVER(musobana) //t:musobana f:niyanpai.c r: c:
//SET: niyanpai
		DRIVER(niyanpai) //t:niyanpai f:niyanpai.c r: c:
//SET: jyunai
		DRIVER(jyunai) //t:jyunai f:csplayh5.c r: c:
//SET: csplayh5
		DRIVER(csplayh5) //t:csplayh5 f:csplayh5.c r: c:
//SET: bikiniko
		DRIVER(bikiniko) //t:bikiniko f:csplayh5.c r: c:
//SET: safarir
		DRIVER(safarir) //t:safarir f:safarir.c r: c:
//SET: phoenix
		DRIVER(phoenix) //t:phoenix f:phoenix.c r: c:
		DRIVER(batman2) //t:batman2 f:galdrvr.c r:phoenix c:phoenix
		DRIVER(phoenxp2) //t:phoenxp2 f:galdrvr.c r:phoenix c:phoenix
		DRIVER(phoenixa) //t:phoenixa f:phoenix.c r:phoenix c:phoenix
		DRIVER(phoenixb) //t:phoenixb f:phoenix.c r:phoenix c:phoenix
		DRIVER(phoenixt) //t:phoenixt f:phoenix.c r:phoenix c:phoenix
		DRIVER(phoenixj) //t:phoenixj f:phoenix.c r:phoenix c:phoenix
		DRIVER(phoenix3) //t:phoenix3 f:phoenix.c r:phoenix c:phoenix
		DRIVER(phoenixc) //t:phoenixc f:phoenix.c r:phoenix c:phoenix
		DRIVER(condor) //t:condor f:phoenix.c r:phoenix c:phoenix
		DRIVER(fenix) //t:fenix f:phoenix.c r:phoenix c:phoenix
		DRIVER(falcon) //t:falcon f:phoenix.c r:phoenix c:phoenix
		DRIVER(vautour) //t:vautour f:phoenix.c r:phoenix c:phoenix
		DRIVER(falconz) //t:falconz f:phoenix.c r:phoenix c:phoenix
		DRIVER(vautourz) //t:vautourz f:phoenix.c r:phoenix c:phoenix
		DRIVER(griffon) //t:griffon f:phoenix.c r:phoenix c:phoenix
		DRIVER(nextfase) //t:nextfase f:phoenix.c r:phoenix c:phoenix
//SET: pleiads
		DRIVER(pleiads) //t:pleiads f:phoenix.c r: c:
		DRIVER(pleiadbl) //t:pleiadbl f:phoenix.c r:pleiads c:pleiads
		DRIVER(pleiadce) //t:pleiadce f:phoenix.c r:pleiads c:pleiads
		DRIVER(capitol) //t:capitol f:phoenix.c r:pleiads c:pleiads
//SET: survival
		DRIVER(survival) //t:survival f:phoenix.c r: c:
//SET: naughtyb
		DRIVER(naughtyb) //t:naughtyb f:naughtyb.c r: c:
		DRIVER(naughtyba) //t:naughtyba f:naughtyb.c r:naughtyb c:naughtyb
		DRIVER(naughtybc) //t:naughtybc f:naughtyb.c r:naughtyb c:naughtyb
//SET: popflame
		DRIVER(popflame) //t:popflame f:naughtyb.c r: c:
		DRIVER(popflamea) //t:popflamea f:naughtyb.c r:popflame c:popflame
		DRIVER(popflameb) //t:popflameb f:naughtyb.c r:popflame c:popflame
		DRIVER(popflamen) //t:popflamen f:naughtyb.c r:popflame c:popflame
//SET: trvmstr
		DRIVER(trvmstr) //t:trvmstr f:naughtyb.c r: c:
		DRIVER(trvmstra) //t:trvmstra f:naughtyb.c r:trvmstr c:trvmstr
		DRIVER(trvmstrb) //t:trvmstrb f:naughtyb.c r:trvmstr c:trvmstr
		DRIVER(trvmstrc) //t:trvmstrc f:naughtyb.c r:trvmstr c:trvmstr
		DRIVER(trvgns) //t:trvgns f:naughtyb.c r:trvmstr c:trvmstr
//SET: geebee
		DRIVER(geebee) //t:geebee f:warpwarp.c r: c:
		DRIVER(geebeeb) //t:geebeeb f:warpwarp.c r:geebee c:geebee
		DRIVER(geebeeg) //t:geebeeg f:warpwarp.c r:geebee c:geebee
//SET: bombbee
		DRIVER(bombbee) //t:bombbee f:warpwarp.c r: c:
//SET: cutieq
		DRIVER(cutieq) //t:cutieq f:warpwarp.c r: c:
//SET: navarone
		DRIVER(navarone) //t:navarone f:warpwarp.c r: c:
//SET: kaitei
		DRIVER(kaitei) //t:kaitei f:warpwarp.c r: c:
		DRIVER(kaitein) //t:kaitein f:warpwarp.c r:kaitei c:kaitei
//SET: sos
		DRIVER(sos) //t:sos f:warpwarp.c r: c:
//SET: tankbatt
		DRIVER(tankbatt) //t:tankbatt f:tankbatt.c r: c:
//SET: warpwarp
		DRIVER(warpwarp) //t:warpwarp f:warpwarp.c r: c:
		DRIVER(warpwarpr) //t:warpwarpr f:warpwarp.c r:warpwarp c:warpwarp
		DRIVER(warpwarpr2) //t:warpwarpr2 f:warpwarp.c r:warpwarp c:warpwarp
//SET: rallyx
		DRIVER(rallyx) //t:rallyx f:rallyx.c r: c:
		DRIVER(rallyxa) //t:rallyxa f:rallyx.c r:rallyx c:rallyx
		DRIVER(rallyxm) //t:rallyxm f:rallyx.c r:rallyx c:rallyx
//SET: nrallyx
		DRIVER(nrallyx) //t:nrallyx f:rallyx.c r: c:
		DRIVER(nrallyxb) //t:nrallyxb f:rallyx.c r:nrallyx c:nrallyx
//SET: jungler
		DRIVER(jungler) //t:jungler f:rallyx.c r: c:
		DRIVER(junglers) //t:junglers f:rallyx.c r:jungler c:jungler
//SET: tactcian
		DRIVER(tactcian) //t:tactcian f:rallyx.c r: c:
		DRIVER(tactcian2) //t:tactcian2 f:rallyx.c r:tactcian c:tactcian
//SET: locomotn
		DRIVER(locomotn) //t:locomotn f:rallyx.c r: c:
		DRIVER(gutangtn) //t:gutangtn f:rallyx.c r:locomotn c:locomotn
		DRIVER(cottong) //t:cottong f:rallyx.c r:locomotn c:locomotn
		DRIVER(locoboot) //t:locoboot f:rallyx.c r:locomotn c:locomotn
//SET: commsega
		DRIVER(commsega) //t:commsega f:rallyx.c r: c:
//SET: bosco
		DRIVER(bosco) //t:bosco f:galaga.c r: c:
		DRIVER(boscoo) //t:boscoo f:galaga.c r:bosco c:bosco
		DRIVER(boscoo2) //t:boscoo2 f:galaga.c r:bosco c:bosco
		DRIVER(boscomd) //t:boscomd f:galaga.c r:bosco c:bosco
		DRIVER(boscomdo) //t:boscomdo f:galaga.c r:bosco c:bosco
//SET: galaga
		DRIVER(galaga) //t:galaga f:galaga.c r: c:
		DRIVER(galagao) //t:galagao f:galaga.c r:galaga c:galaga
		DRIVER(galagamw) //t:galagamw f:galaga.c r:galaga c:galaga
		DRIVER(galagamk) //t:galagamk f:galaga.c r:galaga c:galaga
		DRIVER(galagamf) //t:galagamf f:galaga.c r:galaga c:galaga
		DRIVER(gallag) //t:gallag f:galaga.c r:galaga c:galaga
		DRIVER(gatsbee) //t:gatsbee f:galaga.c r:galaga c:galaga
//SET: digdug
		DRIVER(digdug) //t:digdug f:galaga.c r: c:
		DRIVER(digdug1) //t:digdug1 f:galaga.c r:digdug c:digdug
		DRIVER(digdugat) //t:digdugat f:galaga.c r:digdug c:digdug
		DRIVER(digdugat1) //t:digdugat1 f:galaga.c r:digdug c:digdug
		DRIVER(dzigzag) //t:dzigzag f:galaga.c r:digdug c:digdug
		DRIVER(digsid) //t:digsid f:galaga.c r:digdug c:digdug
//SET: xevious
		DRIVER(xevious) //t:xevious f:galaga.c r: c:
		DRIVER(xeviousa) //t:xeviousa f:galaga.c r:xevious c:xevious
		DRIVER(xeviousb) //t:xeviousb f:galaga.c r:xevious c:xevious
		DRIVER(xeviousc) //t:xeviousc f:galaga.c r:xevious c:xevious
		DRIVER(xevios) //t:xevios f:galaga.c r:xevious c:xevious
		DRIVER(battles) //t:battles f:galaga.c r:xevious c:xevious
		DRIVER(sxevious) //t:sxevious f:galaga.c r:xevious c:xevious
		DRIVER(sxeviousj) //t:sxeviousj f:galaga.c r:xevious c:xevious
//SET: superpac
		DRIVER(superpac) //t:superpac f:mappy.c r: c:
		DRIVER(superpacm) //t:superpacm f:mappy.c r:superpac c:superpac
//SET: pacnpal
		DRIVER(pacnpal) //t:pacnpal f:mappy.c r: c:
		DRIVER(pacnpal2) //t:pacnpal2 f:mappy.c r:pacnpal c:pacnpal
		DRIVER(pacnchmp) //t:pacnchmp f:mappy.c r:pacnpal c:pacnpal
//SET: phozon
		DRIVER(phozon) //t:phozon f:mappy.c r: c:
//SET: mappy
		DRIVER(mappy) //t:mappy f:mappy.c r: c:
		DRIVER(mappyj) //t:mappyj f:mappy.c r:mappy c:mappy
//SET: digdug2
		DRIVER(digdug2) //t:digdug2 f:mappy.c r: c:
		DRIVER(digdug2o) //t:digdug2o f:mappy.c r:digdug2 c:digdug2
//SET: todruaga
		DRIVER(todruaga) //t:todruaga f:mappy.c r: c:
		DRIVER(todruagao) //t:todruagao f:mappy.c r:todruaga c:todruaga
		DRIVER(todruagas) //t:todruagas f:mappy.c r:todruaga c:todruaga
//SET: motos
		DRIVER(motos) //t:motos f:mappy.c r: c:
//SET: grobda
		DRIVER(grobda) //t:grobda f:mappy.c r: c:
		DRIVER(grobda2) //t:grobda2 f:mappy.c r:grobda c:grobda
		DRIVER(grobda3) //t:grobda3 f:mappy.c r:grobda c:grobda
//SET: gaplus
		DRIVER(gaplus) //t:gaplus f:gaplus.c r: c:
		DRIVER(gaplusa) //t:gaplusa f:gaplus.c r:gaplus c:gaplus
		DRIVER(gapluso) //t:gapluso f:gaplus.c r:gaplus c:gaplus
		DRIVER(galaga3) //t:galaga3 f:gaplus.c r:gaplus c:gaplus
		DRIVER(galaga3m) //t:galaga3m f:gaplus.c r:gaplus c:gaplus
		DRIVER(galaga3a) //t:galaga3a f:gaplus.c r:gaplus c:gaplus
#endif

#ifdef PS3_SET_3
//SET: liblrabl
		DRIVER(liblrabl) //t:liblrabl f:toypop.c r: c:
//SET: toypop
		DRIVER(toypop) //t:toypop f:toypop.c r: c:
//SET: polepos
		DRIVER(polepos) //t:polepos f:polepos.c r: c:
		DRIVER(poleposa) //t:poleposa f:polepos.c r:polepos c:polepos
		DRIVER(polepos1) //t:polepos1 f:polepos.c r:polepos c:polepos
		DRIVER(topracer) //t:topracer f:polepos.c r:polepos c:polepos
		DRIVER(topracera) //t:topracera f:polepos.c r:polepos c:polepos
		DRIVER(topracern) //t:topracern f:polepos.c r:polepos c:polepos
//SET: polepos2
		DRIVER(polepos2) //t:polepos2 f:polepos.c r: c:
		DRIVER(polepos2a) //t:polepos2a f:polepos.c r:polepos2 c:polepos2
		DRIVER(polepos2b) //t:polepos2b f:polepos.c r:polepos2 c:polepos2
		DRIVER(polepos2bi) //t:polepos2bi f:polepos.c r:polepos2 c:polepos2
//SET: pacland
		DRIVER(pacland) //t:pacland f:pacland.c r: c:
		DRIVER(paclandj) //t:paclandj f:pacland.c r:pacland c:pacland
		DRIVER(paclandjo) //t:paclandjo f:pacland.c r:pacland c:pacland
		DRIVER(paclandjo2) //t:paclandjo2 f:pacland.c r:pacland c:pacland
		DRIVER(paclandm) //t:paclandm f:pacland.c r:pacland c:pacland
//SET: drgnbstr
		DRIVER(drgnbstr) //t:drgnbstr f:skykid.c r: c:
//SET: skykid
		DRIVER(skykid) //t:skykid f:skykid.c r: c:
		DRIVER(skykido) //t:skykido f:skykid.c r:skykid c:skykid
		DRIVER(skykidd) //t:skykidd f:skykid.c r:skykid c:skykid
		DRIVER(skykids) //t:skykids f:skykid.c r:skykid c:skykid
//SET: aliensec
		DRIVER(aliensec) //t:aliensec f:baraduke.c r: c:
		DRIVER(baraduke) //t:baraduke f:baraduke.c r:aliensec c:aliensec
//SET: metrocrs
		DRIVER(metrocrs) //t:metrocrs f:baraduke.c r: c:
		DRIVER(metrocrsa) //t:metrocrsa f:baraduke.c r:metrocrs c:metrocrs
//SET: hopmappy
		DRIVER(hopmappy) //t:hopmappy f:namcos86.c r: c:
//SET: skykiddx
		DRIVER(skykiddx) //t:skykiddx f:namcos86.c r: c:
		DRIVER(skykiddxo) //t:skykiddxo f:namcos86.c r:skykiddx c:skykiddx
//SET: roishtar
		DRIVER(roishtar) //t:roishtar f:namcos86.c r: c:
//SET: genpeitd
		DRIVER(genpeitd) //t:genpeitd f:namcos86.c r: c:
//SET: rthunder
		DRIVER(rthunder) //t:rthunder f:namcos86.c r: c:
		DRIVER(rthundero) //t:rthundero f:namcos86.c r:rthunder c:rthunder
//SET: wndrmomo
		DRIVER(wndrmomo) //t:wndrmomo f:namcos86.c r: c:
//SET: tceptor
		DRIVER(tceptor) //t:tceptor f:tceptor.c r: c:
		DRIVER(tceptor2) //t:tceptor2 f:tceptor.c r:tceptor c:tceptor
//SET: kungfur
		DRIVER(kungfur) //t:kungfur f:kungfur.c r: c:
//SET: shadowld
		DRIVER(shadowld) //t:shadowld f:namcos1.c r: c:
		DRIVER(youkaidk) //t:youkaidk f:namcos1.c r:shadowld c:shadowld
		DRIVER(youkaidko) //t:youkaidko f:namcos1.c r:shadowld c:shadowld
//SET: dspirit
		DRIVER(dspirit) //t:dspirit f:namcos1.c r: c:
		DRIVER(dspirito) //t:dspirito f:namcos1.c r:dspirit c:dspirit
		DRIVER(dspirita) //t:dspirita f:namcos1.c r:dspirit c:dspirit
//SET: blazer
		DRIVER(blazer) //t:blazer f:namcos1.c r: c:
//SET: quester
		DRIVER(quester) //t:quester f:namcos1.c r: c:
		DRIVER(questers) //t:questers f:namcos1.c r:quester c:quester
//SET: pacmania
		DRIVER(pacmania) //t:pacmania f:namcos1.c r: c:
		DRIVER(pacmaniaj) //t:pacmaniaj f:namcos1.c r:pacmania c:pacmania
//SET: galaga88
		DRIVER(galaga88) //t:galaga88 f:namcos1.c r: c:
		DRIVER(galaga88j) //t:galaga88j f:namcos1.c r:galaga88 c:galaga88
//SET: ws
		DRIVER(ws) //t:ws f:namcos1.c r: c:
		DRIVER(ws89) //t:ws89 f:namcos1.c r:ws c:ws
		DRIVER(ws90) //t:ws90 f:namcos1.c r:ws c:ws
//SET: berabohm
		DRIVER(berabohm) //t:berabohm f:namcos1.c r: c:
		DRIVER(berabohmo) //t:berabohmo f:namcos1.c r:berabohm c:berabohm
//SET: mmaze
		DRIVER(mmaze) //t:mmaze f:namcos1.c r: c:
//SET: bakutotu
		DRIVER(bakutotu) //t:bakutotu f:namcos1.c r: c:
//SET: wldcourt
		DRIVER(wldcourt) //t:wldcourt f:namcos1.c r: c:
//SET: splatter
		DRIVER(splatter) //t:splatter f:namcos1.c r: c:
		DRIVER(splattero) //t:splattero f:namcos1.c r:splatter c:splatter
		DRIVER(splatterj) //t:splatterj f:namcos1.c r:splatter c:splatter
//SET: faceoff
		DRIVER(faceoff) //t:faceoff f:namcos1.c r: c:
//SET: rompers
		DRIVER(rompers) //t:rompers f:namcos1.c r: c:
		DRIVER(romperso) //t:romperso f:namcos1.c r:rompers c:rompers
//SET: blastoff
		DRIVER(blastoff) //t:blastoff f:namcos1.c r: c:
//SET: dangseed
		DRIVER(dangseed) //t:dangseed f:namcos1.c r: c:
//SET: pistoldm
		DRIVER(pistoldm) //t:pistoldm f:namcos1.c r: c:
//SET: boxyboy
		DRIVER(boxyboy) //t:boxyboy f:namcos1.c r: c:
		DRIVER(soukobdx) //t:soukobdx f:namcos1.c r:boxyboy c:boxyboy
//SET: puzlclub
		DRIVER(puzlclub) //t:puzlclub f:namcos1.c r: c:
//SET: tankfrce
		DRIVER(tankfrce) //t:tankfrce f:namcos1.c r: c:
		DRIVER(tankfrce4) //t:tankfrce4 f:namcos1.c r:tankfrce c:tankfrce
		DRIVER(tankfrcej) //t:tankfrcej f:namcos1.c r:tankfrce c:tankfrce
//SET: finallap
		DRIVER(finallap) //t:finallap f:namcos2.c r: c:
		DRIVER(finallapd) //t:finallapd f:namcos2.c r:finallap c:finallap
		DRIVER(finallapc) //t:finallapc f:namcos2.c r:finallap c:finallap
		DRIVER(finallapjc) //t:finallapjc f:namcos2.c r:finallap c:finallap
		DRIVER(finallapjb) //t:finallapjb f:namcos2.c r:finallap c:finallap
//SET: assault
		DRIVER(assault) //t:assault f:namcos2.c r: c:
		DRIVER(assaultj) //t:assaultj f:namcos2.c r:assault c:assault
		DRIVER(assaultp) //t:assaultp f:namcos2.c r:assault c:assault
//SET: metlhawk
		DRIVER(metlhawk) //t:metlhawk f:namcos2.c r: c:
		DRIVER(metlhawkj) //t:metlhawkj f:namcos2.c r:metlhawk c:metlhawk
//SET: ordyne
		DRIVER(ordyne) //t:ordyne f:namcos2.c r: c:
		DRIVER(ordynej) //t:ordynej f:namcos2.c r:ordyne c:ordyne
//SET: mirninja
		DRIVER(mirninja) //t:mirninja f:namcos2.c r: c:
//SET: phelios
		DRIVER(phelios) //t:phelios f:namcos2.c r: c:
//SET: dirtfoxj
		DRIVER(dirtfoxj) //t:dirtfoxj f:namcos2.c r: c:
//SET: fourtrax
		DRIVER(fourtrax) //t:fourtrax f:namcos2.c r: c:
//SET: valkyrie
		DRIVER(valkyrie) //t:valkyrie f:namcos2.c r: c:
//SET: finehour
		DRIVER(finehour) //t:finehour f:namcos2.c r: c:
//SET: burnforc
		DRIVER(burnforc) //t:burnforc f:namcos2.c r: c:
		DRIVER(burnforco) //t:burnforco f:namcos2.c r:burnforc c:burnforc
//SET: marvland
		DRIVER(marvland) //t:marvland f:namcos2.c r: c:
		DRIVER(marvlandj) //t:marvlandj f:namcos2.c r:marvland c:marvland
//SET: kyukaidk
		DRIVER(kyukaidk) //t:kyukaidk f:namcos2.c r: c:
		DRIVER(kyukaidko) //t:kyukaidko f:namcos2.c r:kyukaidk c:kyukaidk
//SET: dsaber
		DRIVER(dsaber) //t:dsaber f:namcos2.c r: c:
		DRIVER(dsaberj) //t:dsaberj f:namcos2.c r:dsaber c:dsaber
//SET: finalap2
		DRIVER(finalap2) //t:finalap2 f:namcos2.c r: c:
		DRIVER(finalap2j) //t:finalap2j f:namcos2.c r:finalap2 c:finalap2
//SET: gollygho
		DRIVER(gollygho) //t:gollygho f:namcos2.c r: c:
//SET: rthun2
		DRIVER(rthun2) //t:rthun2 f:namcos2.c r: c:
		DRIVER(rthun2j) //t:rthun2j f:namcos2.c r:rthun2 c:rthun2
//SET: sgunner
		DRIVER(sgunner) //t:sgunner f:namcos2.c r: c:
		DRIVER(sgunnerj) //t:sgunnerj f:namcos2.c r:sgunner c:sgunner
//SET: sgunner2
		DRIVER(sgunner2) //t:sgunner2 f:namcos2.c r: c:
		DRIVER(sgunner2j) //t:sgunner2j f:namcos2.c r:sgunner2 c:sgunner2
//SET: cosmogng
		DRIVER(cosmogng) //t:cosmogng f:namcos2.c r: c:
		DRIVER(cosmogngj) //t:cosmogngj f:namcos2.c r:cosmogng c:cosmogng
//SET: bubbletr
		DRIVER(bubbletr) //t:bubbletr f:namcos2.c r: c:
//SET: finalap3
		DRIVER(finalap3) //t:finalap3 f:namcos2.c r: c:
		DRIVER(finalap3a) //t:finalap3a f:namcos2.c r:finalap3 c:finalap3
		DRIVER(finalap3j) //t:finalap3j f:namcos2.c r:finalap3 c:finalap3
		DRIVER(finalap3jc) //t:finalap3jc f:namcos2.c r:finalap3 c:finalap3
//SET: luckywld
		DRIVER(luckywld) //t:luckywld f:namcos2.c r: c:
		DRIVER(luckywldj) //t:luckywldj f:namcos2.c r:luckywld c:luckywld
//SET: suzuka8h
		DRIVER(suzuka8h) //t:suzuka8h f:namcos2.c r: c:
		DRIVER(suzuka8hj) //t:suzuka8hj f:namcos2.c r:suzuka8h c:suzuka8h
//SET: sws
		DRIVER(sws) //t:sws f:namcos2.c r: c:
//SET: sws92
		DRIVER(sws92) //t:sws92 f:namcos2.c r: c:
		DRIVER(sws92g) //t:sws92g f:namcos2.c r:sws92 c:sws92
//SET: suzuk8h2
		DRIVER(suzuk8h2) //t:suzuk8h2 f:namcos2.c r: c:
//SET: sws93
		DRIVER(sws93) //t:sws93 f:namcos2.c r: c:
//SET: speedrcr
		DRIVER(speedrcr) //t:speedrcr f:namcofl.c r: c:
//SET: finalapr
		DRIVER(finalapr) //t:finalapr f:namcofl.c r: c:
		DRIVER(finalaprj) //t:finalaprj f:namcofl.c r:finalapr c:finalapr
		DRIVER(finalapro) //t:finalapro f:namcofl.c r:finalapr c:finalapr
//SET: bkrtmaq
		DRIVER(bkrtmaq) //t:bkrtmaq f:namcona1.c r: c:
//SET: cgangpzl
		DRIVER(cgangpzl) //t:cgangpzl f:namcona1.c r: c:
		DRIVER(cgangpzlj) //t:cgangpzlj f:namcona1.c r:cgangpzl c:cgangpzl
//SET: exvania
		DRIVER(exvania) //t:exvania f:namcona1.c r: c:
//SET: fghtatck
		DRIVER(fghtatck) //t:fghtatck f:namcona1.c r: c:
		DRIVER(fa) //t:fa f:namcona1.c r:fghtatck c:fghtatck
//SET: knckhead
		DRIVER(knckhead) //t:knckhead f:namcona1.c r: c:
		DRIVER(knckheadj) //t:knckheadj f:namcona1.c r:knckhead c:knckhead
//SET: swcourt
		DRIVER(swcourt) //t:swcourt f:namcona1.c r: c:
		DRIVER(swcourtj) //t:swcourtj f:namcona1.c r:swcourt c:swcourt
//SET: emeralda
		DRIVER(emeralda) //t:emeralda f:namcona1.c r: c:
		DRIVER(emeraldaj) //t:emeraldaj f:namcona1.c r:emeralda c:emeralda
		DRIVER(emeraldaja) //t:emeraldaja f:namcona1.c r:emeralda c:emeralda
//SET: numanath
		DRIVER(numanath) //t:numanath f:namcona1.c r: c:
		DRIVER(numanathj) //t:numanathj f:namcona1.c r:numanath c:numanath
//SET: quiztou
		DRIVER(quiztou) //t:quiztou f:namcona1.c r: c:
//SET: tinklpit
		DRIVER(tinklpit) //t:tinklpit f:namcona1.c r: c:
//SET: xday2
		DRIVER(xday2) //t:xday2 f:namcona1.c r: c:
//SET: nebulray
		DRIVER(nebulray) //t:nebulray f:namconb1.c r: c:
		DRIVER(nebulrayj) //t:nebulrayj f:namconb1.c r:nebulray c:nebulray
//SET: ptblank
		DRIVER(ptblank) //t:ptblank f:namconb1.c r: c:
		DRIVER(gunbuletj) //t:gunbuletj f:namconb1.c r:ptblank c:ptblank
		DRIVER(gunbuletw) //t:gunbuletw f:namconb1.c r:ptblank c:ptblank
//SET: gslugrsj
		DRIVER(gslugrsj) //t:gslugrsj f:namconb1.c r: c:
//SET: gslgr94u
		DRIVER(gslgr94u) //t:gslgr94u f:namconb1.c r: c:
		DRIVER(gslgr94j) //t:gslgr94j f:namconb1.c r:gslgr94u c:gslgr94u
//SET: sws95
		DRIVER(sws95) //t:sws95 f:namconb1.c r: c:
//SET: sws96
		DRIVER(sws96) //t:sws96 f:namconb1.c r: c:
//SET: sws97
		DRIVER(sws97) //t:sws97 f:namconb1.c r: c:
//SET: vshoot
		DRIVER(vshoot) //t:vshoot f:namconb1.c r: c:
//SET: outfxies
		DRIVER(outfxies) //t:outfxies f:namconb1.c r: c:
		DRIVER(outfxiesj) //t:outfxiesj f:namconb1.c r:outfxies c:outfxies
//SET: machbrkr
		DRIVER(machbrkr) //t:machbrkr f:namconb1.c r: c:
//SET: ncv1
		DRIVER(ncv1) //t:ncv1 f:namcond1.c r: c:
		DRIVER(ncv1j) //t:ncv1j f:namcond1.c r:ncv1 c:ncv1
		DRIVER(ncv1j2) //t:ncv1j2 f:namcond1.c r:ncv1 c:ncv1
//SET: ncv2
		DRIVER(ncv2) //t:ncv2 f:namcond1.c r: c:
		DRIVER(ncv2j) //t:ncv2j f:namcond1.c r:ncv2 c:ncv2
//SET: winrun
		DRIVER(winrun) //t:winrun f:namcos21.c r: c:
//SET: winrun91
		DRIVER(winrun91) //t:winrun91 f:namcos21.c r: c:
//SET: solvalou
		DRIVER(solvalou) //t:solvalou f:namcos21.c r: c:
//SET: starblad
		DRIVER(starblad) //t:starblad f:namcos21.c r: c:
//SET: driveyes
		DRIVER(driveyes) //t:driveyes f:namcos21.c r: c:
//SET: aircomb
		DRIVER(aircomb) //t:aircomb f:namcos21.c r: c:
		DRIVER(aircombj) //t:aircombj f:namcos21.c r:aircomb c:aircomb
//SET: cybsled
		DRIVER(cybsled) //t:cybsled f:namcos21.c r: c:
		DRIVER(cybsledj) //t:cybsledj f:namcos21.c r:cybsled c:cybsled
//SET: gal3
		DRIVER(gal3) //t:gal3 f:gal3.c r: c:
//SET: ridgerac
		DRIVER(ridgerac) //t:ridgerac f:namcos22.c r: c:
		DRIVER(ridgeracb) //t:ridgeracb f:namcos22.c r:ridgerac c:ridgerac
		DRIVER(ridgeracj) //t:ridgeracj f:namcos22.c r:ridgerac c:ridgerac
		DRIVER(ridgerac3) //t:ridgerac3 f:namcos22.c r:ridgerac c:ridgerac
		DRIVER(rrf) //t:rrf f:namcos22.c r:ridgerac c:ridgerac
//SET: acedrvrw
		DRIVER(acedrvrw) //t:acedrvrw f:namcos22.c r: c:
//SET: alpinerd
		DRIVER(alpinerd) //t:alpinerd f:namcos22.c r: c:
		DRIVER(alpinerc) //t:alpinerc f:namcos22.c r:alpinerd c:alpinerd
//SET: ridgera2
		DRIVER(ridgera2) //t:ridgera2 f:namcos22.c r: c:
		DRIVER(ridgera2j) //t:ridgera2j f:namcos22.c r:ridgera2 c:ridgera2
		DRIVER(ridgera2ja) //t:ridgera2ja f:namcos22.c r:ridgera2 c:ridgera2
//SET: raveracw
		DRIVER(raveracw) //t:raveracw f:namcos22.c r: c:
		DRIVER(raveracj) //t:raveracj f:namcos22.c r:raveracw c:raveracw
		DRIVER(raveracja) //t:raveracja f:namcos22.c r:raveracw c:raveracw
//SET: airco22b
		DRIVER(airco22b) //t:airco22b f:namcos22.c r: c:
//SET: alpinr2b
		DRIVER(alpinr2b) //t:alpinr2b f:namcos22.c r: c:
		DRIVER(alpinr2a) //t:alpinr2a f:namcos22.c r:alpinr2b c:alpinr2b
//SET: cybrcomm
		DRIVER(cybrcomm) //t:cybrcomm f:namcos22.c r: c:
//SET: cybrcycc
		DRIVER(cybrcycc) //t:cybrcycc f:namcos22.c r: c:
//SET: timecris
		DRIVER(timecris) //t:timecris f:namcos22.c r: c:
		DRIVER(timecrisa) //t:timecrisa f:namcos22.c r:timecris c:timecris
//SET: dirtdash
		DRIVER(dirtdash) //t:dirtdash f:namcos22.c r: c:
//SET: victlapw
		DRIVER(victlapw) //t:victlapw f:namcos22.c r: c:
//SET: alpinesa
		DRIVER(alpinesa) //t:alpinesa f:namcos22.c r: c:
//SET: propcycl
		DRIVER(propcycl) //t:propcycl f:namcos22.c r: c:
//SET: tokyowar
		DRIVER(tokyowar) //t:tokyowar f:namcos22.c r: c:
//SET: aquajet
		DRIVER(aquajet) //t:aquajet f:namcos22.c r: c:
//SET: finlflng
		DRIVER(finlflng) //t:finlflng f:namcos23.c r: c:
//SET: motoxgo
		DRIVER(motoxgo) //t:motoxgo f:namcos23.c r: c:
//SET: rapidrvr
		DRIVER(rapidrvr) //t:rapidrvr f:namcos23.c r: c:
		DRIVER(rapidrvr2) //t:rapidrvr2 f:namcos23.c r:rapidrvr c:rapidrvr
//SET: downhill
		DRIVER(downhill) //t:downhill f:namcos23.c r: c:
//SET: timecrs2
		DRIVER(timecrs2) //t:timecrs2 f:namcos23.c r: c:
		DRIVER(timecrs2b) //t:timecrs2b f:namcos23.c r:timecrs2 c:timecrs2
		DRIVER(timecrs2c) //t:timecrs2c f:namcos23.c r:timecrs2 c:timecrs2
//SET: panicprk
		DRIVER(panicprk) //t:panicprk f:namcos23.c r: c:
//SET: raceon
		DRIVER(raceon) //t:raceon f:namcos23.c r: c:
//SET: gunwars
		DRIVER(gunwars) //t:gunwars f:namcos23.c r: c:
//SET: 500gp
		DRIVER(500gp) //t:500gp f:namcos23.c r: c:
//SET: finfurl2
		DRIVER(finfurl2) //t:finfurl2 f:namcos23.c r: c:
		DRIVER(finfurl2j) //t:finfurl2j f:namcos23.c r:finfurl2 c:finfurl2
//SET: crszone
		DRIVER(crszone) //t:crszone f:namcos23.c r: c:
		DRIVER(crszonea) //t:crszonea f:namcos23.c r:crszone c:crszone
		DRIVER(crszoneb) //t:crszoneb f:namcos23.c r:crszone c:crszone
//SET: sys246
		DRIVER(sys246) //t:sys246 f:namcops2.c r: c:
//SET: rrvac
		DRIVER(rrvac) //t:rrvac f:namcops2.c r:sys246 c:
//SET: dragchrn
		DRIVER(dragchrn) //t:dragchrn f:namcops2.c r:sys246 c:
//SET: netchu02
		DRIVER(netchu02) //t:netchu02 f:namcops2.c r:sys246 c:
//SET: scptour
		DRIVER(scptour) //t:scptour f:namcops2.c r:sys246 c:
//SET: soulclb2
		DRIVER(soulclb2) //t:soulclb2 f:namcops2.c r:sys246 c:
		DRIVER(soulcl2a) //t:soulcl2a f:namcops2.c r:soulclb2 c:soulclb2
		DRIVER(soulcl2b) //t:soulcl2b f:namcops2.c r:soulclb2 c:soulclb2
//SET: tekken4
		DRIVER(tekken4) //t:tekken4 f:namcops2.c r:sys246 c:
		DRIVER(tekken4a) //t:tekken4a f:namcops2.c r:tekken4 c:tekken4
		DRIVER(tekken4b) //t:tekken4b f:namcops2.c r:tekken4 c:tekken4
//SET: timecrs3
		DRIVER(timecrs3) //t:timecrs3 f:namcops2.c r:sys246 c:
//SET: zgundm
		DRIVER(zgundm) //t:zgundm f:namcops2.c r:sys246 c:
//SET: fghtjam
		DRIVER(fghtjam) //t:fghtjam f:namcops2.c r:sys246 c:
//SET: sukuinuf
		DRIVER(sukuinuf) //t:sukuinuf f:namcops2.c r:sys246 c:
//SET: zgundmdx
		DRIVER(zgundmdx) //t:zgundmdx f:namcops2.c r:sys246 c:
//SET: gundzaft
		DRIVER(gundzaft) //t:gundzaft f:namcops2.c r:sys246 c:
//SET: soulclb3
		DRIVER(soulclb3) //t:soulclb3 f:namcops2.c r:sys246 c:
//SET: sys256
		DRIVER(sys256) //t:sys256 f:namcops2.c r: c:
//SET: tekken51
		DRIVER(tekken51) //t:tekken51 f:namcops2.c r:sys256 c:
//SET: kinniku
		DRIVER(kinniku) //t:kinniku f:namcops2.c r:sys256 c:
//SET: taiko9
		DRIVER(taiko9) //t:taiko9 f:namcops2.c r:sys256 c:
//SET: taiko10
		DRIVER(taiko10) //t:taiko10 f:namcops2.c r:sys256 c:
//SET: 25pacman
		DRIVER(25pacman) //t:25pacman f:20pacgal.c r: c:
//SET: 20pacgal
		DRIVER(20pacgal) //t:20pacgal f:20pacgal.c r: c:
		DRIVER(20pacgalr4) //t:20pacgalr4 f:20pacgal.c r:20pacgal c:20pacgal
		DRIVER(20pacgalr3) //t:20pacgalr3 f:20pacgal.c r:20pacgal c:20pacgal
		DRIVER(20pacgalr2) //t:20pacgalr2 f:20pacgal.c r:20pacgal c:20pacgal
		DRIVER(20pacgalr1) //t:20pacgalr1 f:20pacgal.c r:20pacgal c:20pacgal
		DRIVER(20pacgalr0) //t:20pacgalr0 f:20pacgal.c r:20pacgal c:20pacgal
//SET: turrett
		DRIVER(turrett) //t:turrett f:turrett.c r: c:
//SET: cosmicg
		DRIVER(cosmicg) //t:cosmicg f:cosmic.c r: c:
//SET: cosmica
		DRIVER(cosmica) //t:cosmica f:cosmic.c r: c:
		DRIVER(cosmica1) //t:cosmica1 f:cosmic.c r:cosmica c:cosmica
		DRIVER(cosmica2) //t:cosmica2 f:cosmic.c r:cosmica c:cosmica
//SET: nomnlnd
		DRIVER(nomnlnd) //t:nomnlnd f:cosmic.c r: c:
		DRIVER(nomnlndg) //t:nomnlndg f:cosmic.c r:nomnlnd c:nomnlnd
//SET: magspot
		DRIVER(magspot) //t:magspot f:cosmic.c r: c:
//SET: magspot2
		DRIVER(magspot2) //t:magspot2 f:cosmic.c r: c:
//SET: panic
		DRIVER(panic) //t:panic f:cosmic.c r: c:
		DRIVER(panic2) //t:panic2 f:cosmic.c r:panic c:panic
		DRIVER(panic3) //t:panic3 f:cosmic.c r:panic c:panic
		DRIVER(panich) //t:panich f:cosmic.c r:panic c:panic
		DRIVER(panicger) //t:panicger f:cosmic.c r:panic c:panic
//SET: devzone
		DRIVER(devzone) //t:devzone f:cosmic.c r: c:
		DRIVER(devzone2) //t:devzone2 f:cosmic.c r:devzone c:devzone
//SET: cheekyms
		DRIVER(cheekyms) //t:cheekyms f:cheekyms.c r: c:
//SET: zerohour
		DRIVER(zerohour) //t:zerohour f:redclash.c r: c:
		DRIVER(zerohoura) //t:zerohoura f:redclash.c r:zerohour c:zerohour
//SET: redclash
		DRIVER(redclash) //t:redclash f:redclash.c r: c:
		DRIVER(redclasha) //t:redclasha f:redclash.c r:redclash c:redclash
		DRIVER(redclashk) //t:redclashk f:redclash.c r:redclash c:redclash
//SET: cavenger
		DRIVER(cavenger) //t:cavenger f:ladybug.c r: c:
//SET: ladybug
		DRIVER(ladybug) //t:ladybug f:ladybug.c r: c:
		DRIVER(ladybugg) //t:ladybugg f:galaxold.c r:ladybug c:ladybug
		DRIVER(ladybugb) //t:ladybugb f:ladybug.c r:ladybug c:ladybug
		DRIVER(ladybgb2) //t:ladybgb2 f:ladybug.c r:ladybug c:ladybug
//SET: snapjack
		DRIVER(snapjack) //t:snapjack f:ladybug.c r: c:
//SET: sraider
		DRIVER(sraider) //t:sraider f:ladybug.c r: c:
//SET: dorodon
		DRIVER(dorodon) //t:dorodon f:ladybug.c r: c:
		DRIVER(dorodon2) //t:dorodon2 f:ladybug.c r:dorodon c:dorodon
//SET: mrdo
		DRIVER(mrdo) //t:mrdo f:mrdo.c r: c:
		DRIVER(mrdoy) //t:mrdoy f:mrdo.c r:mrdo c:mrdo
		DRIVER(mrdot) //t:mrdot f:mrdo.c r:mrdo c:mrdo
		DRIVER(mrdofix) //t:mrdofix f:mrdo.c r:mrdo c:mrdo
		DRIVER(mrlo) //t:mrlo f:mrdo.c r:mrdo c:mrdo
		DRIVER(mrdu) //t:mrdu f:mrdo.c r:mrdo c:mrdo
		DRIVER(yankeedo) //t:yankeedo f:mrdo.c r:mrdo c:mrdo
//SET: docastle
		DRIVER(docastle) //t:docastle f:docastle.c r: c:
		DRIVER(docastle2) //t:docastle2 f:docastle.c r:docastle c:docastle
		DRIVER(docastleo) //t:docastleo f:docastle.c r:docastle c:docastle
		DRIVER(douni) //t:douni f:docastle.c r:docastle c:docastle
//SET: dorunrun
		DRIVER(dorunrun) //t:dorunrun f:docastle.c r: c:
		DRIVER(dorunrun2) //t:dorunrun2 f:docastle.c r:dorunrun c:dorunrun
		DRIVER(dorunrunc) //t:dorunrunc f:docastle.c r:dorunrun c:dorunrun
		DRIVER(dorunrunca) //t:dorunrunca f:docastle.c r:dorunrun c:dorunrun
		DRIVER(spiero) //t:spiero f:docastle.c r:dorunrun c:dorunrun
//SET: dowild
		DRIVER(dowild) //t:dowild f:docastle.c r: c:
//SET: jjack
		DRIVER(jjack) //t:jjack f:docastle.c r: c:
//SET: kickridr
		DRIVER(kickridr) //t:kickridr f:docastle.c r: c:
//SET: idsoccer
		DRIVER(idsoccer) //t:idsoccer f:docastle.c r: c:
		DRIVER(idsoccera) //t:idsoccera f:docastle.c r:idsoccer c:idsoccer
		DRIVER(asoccer) //t:asoccer f:docastle.c r:idsoccer c:idsoccer
//SET: superdq
		DRIVER(superdq) //t:superdq f:superdq.c r: c:
		DRIVER(superdqs) //t:superdqs f:superdq.c r:superdq c:superdq
		DRIVER(superdqa) //t:superdqa f:superdq.c r:superdq c:superdq
//SET: spacefev
		DRIVER(spacefev) //t:spacefev f:n8080.c r: c:
		DRIVER(spacefevo) //t:spacefevo f:n8080.c r:spacefev c:spacefev
		DRIVER(spacefevo2) //t:spacefevo2 f:n8080.c r:spacefev c:spacefev
//SET: highsplt
		DRIVER(highsplt) //t:highsplt f:n8080.c r: c:
		DRIVER(highsplta) //t:highsplta f:n8080.c r:highsplt c:highsplt
		DRIVER(highspltb) //t:highspltb f:n8080.c r:highsplt c:highsplt
//SET: spacelnc
		DRIVER(spacelnc) //t:spacelnc f:n8080.c r: c:
//SET: sheriff
		DRIVER(sheriff) //t:sheriff f:n8080.c r: c:
		DRIVER(bandido) //t:bandido f:n8080.c r:sheriff c:sheriff
//SET: helifire
		DRIVER(helifire) //t:helifire f:n8080.c r: c:
		DRIVER(helifirea) //t:helifirea f:n8080.c r:helifire c:helifire
//SET: radarscp
		DRIVER(radarscp) //t:radarscp f:dkong.c r: c:
		DRIVER(radarscp1) //t:radarscp1 f:dkong.c r:radarscp c:radarscp
//SET: dkong
		DRIVER(dkong) //t:dkong f:dkong.c r: c:
		DRIVER(dkongo) //t:dkongo f:dkong.c r:dkong c:dkong
		DRIVER(dkongj) //t:dkongj f:dkong.c r:dkong c:dkong
		DRIVER(dkongjo) //t:dkongjo f:dkong.c r:dkong c:dkong
		DRIVER(dkongjo1) //t:dkongjo1 f:dkong.c r:dkong c:dkong
		DRIVER(dkongf) //t:dkongf f:dkong.c r:dkong c:dkong
		DRIVER(dkongx) //t:dkongx f:dkong.c r:dkong c:dkong
		DRIVER(dkongx11) //t:dkongx11 f:dkong.c r:dkong c:dkong
//SET: dkongjr
		DRIVER(dkongjr) //t:dkongjr f:dkong.c r: c:
		DRIVER(dkongjrm) //t:dkongjrm f:galaxold.c r:dkongjr c:dkongjr
		DRIVER(dkongjrj) //t:dkongjrj f:dkong.c r:dkongjr c:dkongjr
		DRIVER(dkongjnrj) //t:dkongjnrj f:dkong.c r:dkongjr c:dkongjr
		DRIVER(dkongjrb) //t:dkongjrb f:dkong.c r:dkongjr c:dkongjr
		DRIVER(jrking) //t:jrking f:dkong.c r:dkongjr c:dkongjr
		DRIVER(dkongjre) //t:dkongjre f:dkong.c r:dkongjr c:dkongjr
//SET: dkong3
		DRIVER(dkong3) //t:dkong3 f:dkong.c r: c:
		DRIVER(dkong3j) //t:dkong3j f:dkong.c r:dkong3 c:dkong3
		DRIVER(dkong3b) //t:dkong3b f:dkong.c r:dkong3 c:dkong3
//SET: mario
		DRIVER(mario) //t:mario f:mario.c r: c:
		DRIVER(marioe) //t:marioe f:mario.c r:mario c:mario
		DRIVER(marioo) //t:marioo f:mario.c r:mario c:mario
		DRIVER(marioj) //t:marioj f:mario.c r:mario c:mario
		DRIVER(masao) //t:masao f:mario.c r:mario c:mario
		DRIVER(pestplce) //t:pestplce f:dkong.c r:mario c:mario
//SET: spclforc
		DRIVER(spclforc) //t:spclforc f:dkong.c r: c:
//SET: spcfrcii
		DRIVER(spcfrcii) //t:spcfrcii f:dkong.c r: c:
//SET: 8ballact
		DRIVER(8ballact) //t:8ballact f:dkong.c r: c:
		DRIVER(8bpm) //t:8bpm f:pacman.c r:8ballact c:8ballact
		DRIVER(8ballact2) //t:8ballact2 f:dkong.c r:8ballact c:8ballact
//SET: shootgal
		DRIVER(shootgal) //t:shootgal f:dkong.c r: c:
//SET: drakton
		DRIVER(drakton) //t:drakton f:dkong.c r: c:
		DRIVER(drktnjr) //t:drktnjr f:dkong.c r:drakton c:drakton
//SET: strtheat
		DRIVER(strtheat) //t:strtheat f:dkong.c r: c:
//SET: skyskipr
		DRIVER(skyskipr) //t:skyskipr f:popeye.c r: c:
//SET: popeye
		DRIVER(popeye) //t:popeye f:popeye.c r: c:
		DRIVER(popeyeu) //t:popeyeu f:popeye.c r:popeye c:popeye
		DRIVER(popeyef) //t:popeyef f:popeye.c r:popeye c:popeye
		DRIVER(popeyebl) //t:popeyebl f:popeye.c r:popeye c:popeye
//SET: punchout
		DRIVER(punchout) //t:punchout f:punchout.c r: c:
		DRIVER(punchita) //t:punchita f:punchout.c r:punchout c:punchout
//SET: spnchout
		DRIVER(spnchout) //t:spnchout f:punchout.c r: c:
		DRIVER(spnchoutj) //t:spnchoutj f:punchout.c r:spnchout c:spnchout
//SET: armwrest
		DRIVER(armwrest) //t:armwrest f:punchout.c r: c:
//SET: playch10
		DRIVER(playch10) //t:playch10 f:playch10.c r: c:
//SET: pc_tenis
		DRIVER(pc_tenis) //t:pc_tenis f:playch10.c r:playch10 c:
//SET: pc_mario
		DRIVER(pc_mario) //t:pc_mario f:playch10.c r:playch10 c:
//SET: pc_bball
		DRIVER(pc_bball) //t:pc_bball f:playch10.c r:playch10 c:
//SET: pc_bfght
		DRIVER(pc_bfght) //t:pc_bfght f:playch10.c r:playch10 c:
//SET: pc_ebike
		DRIVER(pc_ebike) //t:pc_ebike f:playch10.c r:playch10 c:
//SET: pc_golf
		DRIVER(pc_golf) //t:pc_golf f:playch10.c r:playch10 c:
//SET: pc_kngfu
		DRIVER(pc_kngfu) //t:pc_kngfu f:playch10.c r:playch10 c:
//SET: pc_1942
		DRIVER(pc_1942) //t:pc_1942 f:playch10.c r:playch10 c:
//SET: pc_smb
		DRIVER(pc_smb) //t:pc_smb f:playch10.c r:playch10 c:
//SET: pc_vball
		DRIVER(pc_vball) //t:pc_vball f:playch10.c r:playch10 c:
//SET: pc_duckh
		DRIVER(pc_duckh) //t:pc_duckh f:playch10.c r:playch10 c:
//SET: pc_hgaly
		DRIVER(pc_hgaly) //t:pc_hgaly f:playch10.c r:playch10 c:
//SET: pc_wgnmn
		DRIVER(pc_wgnmn) //t:pc_wgnmn f:playch10.c r:playch10 c:
//SET: pc_grdus
		DRIVER(pc_grdus) //t:pc_grdus f:playch10.c r:playch10 c:
		DRIVER(pc_grdue) //t:pc_grdue f:playch10.c r:pc_grdus c:pc_grdus
//SET: pc_tkfld
		DRIVER(pc_tkfld) //t:pc_tkfld f:playch10.c r:playch10 c:
//SET: pc_pwrst
		DRIVER(pc_pwrst) //t:pc_pwrst f:playch10.c r:playch10 c:
//SET: pc_trjan
		DRIVER(pc_trjan) //t:pc_trjan f:playch10.c r:playch10 c:
//SET: pc_cvnia
		DRIVER(pc_cvnia) //t:pc_cvnia f:playch10.c r:playch10 c:
//SET: pc_dbldr
		DRIVER(pc_dbldr) //t:pc_dbldr f:playch10.c r:playch10 c:
//SET: pc_rnatk
		DRIVER(pc_rnatk) //t:pc_rnatk f:playch10.c r:playch10 c:
//SET: pc_rygar
		DRIVER(pc_rygar) //t:pc_rygar f:playch10.c r:playch10 c:
//SET: pc_cntra
		DRIVER(pc_cntra) //t:pc_cntra f:playch10.c r:playch10 c:
//SET: pc_goons
		DRIVER(pc_goons) //t:pc_goons f:playch10.c r:playch10 c:
//SET: pc_mtoid
		DRIVER(pc_mtoid) //t:pc_mtoid f:playch10.c r:playch10 c:
//SET: pc_radrc
		DRIVER(pc_radrc) //t:pc_radrc f:playch10.c r:playch10 c:
//SET: pc_miket
		DRIVER(pc_miket) //t:pc_miket f:playch10.c r:playch10 c:
//SET: pc_rcpam
		DRIVER(pc_rcpam) //t:pc_rcpam f:playch10.c r:playch10 c:
//SET: pc_ngaid
		DRIVER(pc_ngaid) //t:pc_ngaid f:playch10.c r:playch10 c:
//SET: pc_tmnt
		DRIVER(pc_tmnt) //t:pc_tmnt f:playch10.c r:playch10 c:
//SET: pc_ftqst
		DRIVER(pc_ftqst) //t:pc_ftqst f:playch10.c r:playch10 c:
//SET: pc_bstar
		DRIVER(pc_bstar) //t:pc_bstar f:playch10.c r:playch10 c:
//SET: pc_tbowl
		DRIVER(pc_tbowl) //t:pc_tbowl f:playch10.c r:playch10 c:
//SET: pc_drmro
		DRIVER(pc_drmro) //t:pc_drmro f:playch10.c r:playch10 c:
//SET: pc_ynoid
		DRIVER(pc_ynoid) //t:pc_ynoid f:playch10.c r:playch10 c:
//SET: pc_rrngr
		DRIVER(pc_rrngr) //t:pc_rrngr f:playch10.c r:playch10 c:
//SET: pc_ddrgn
		DRIVER(pc_ddrgn) //t:pc_ddrgn f:playch10.c r:playch10 c:
//SET: pc_gntlt
		DRIVER(pc_gntlt) //t:pc_gntlt f:playch10.c r:playch10 c:
//SET: pc_smb2
		DRIVER(pc_smb2) //t:pc_smb2 f:playch10.c r:playch10 c:
//SET: pc_smb3
		DRIVER(pc_smb3) //t:pc_smb3 f:playch10.c r:playch10 c:
//SET: pc_mman3
		DRIVER(pc_mman3) //t:pc_mman3 f:playch10.c r:playch10 c:
//SET: pc_radr2
		DRIVER(pc_radr2) //t:pc_radr2 f:playch10.c r:playch10 c:
//SET: pc_suprc
		DRIVER(pc_suprc) //t:pc_suprc f:playch10.c r:playch10 c:
//SET: pc_tmnt2
		DRIVER(pc_tmnt2) //t:pc_tmnt2 f:playch10.c r:playch10 c:
//SET: pc_wcup
		DRIVER(pc_wcup) //t:pc_wcup f:playch10.c r:playch10 c:
//SET: pc_ngai2
		DRIVER(pc_ngai2) //t:pc_ngai2 f:playch10.c r:playch10 c:
//SET: pc_ngai3
		DRIVER(pc_ngai3) //t:pc_ngai3 f:playch10.c r:playch10 c:
//SET: pc_pwbld
		DRIVER(pc_pwbld) //t:pc_pwbld f:playch10.c r:playch10 c:
//SET: pc_rkats
		DRIVER(pc_rkats) //t:pc_rkats f:playch10.c r:playch10 c:
//SET: pc_pinbt
		DRIVER(pc_pinbt) //t:pc_pinbt f:playch10.c r:playch10 c:
//SET: pc_cshwk
		DRIVER(pc_cshwk) //t:pc_cshwk f:playch10.c r:playch10 c:
//SET: pc_sjetm
		DRIVER(pc_sjetm) //t:pc_sjetm f:playch10.c r:playch10 c:
//SET: pc_moglf
		DRIVER(pc_moglf) //t:pc_moglf f:playch10.c r:playch10 c:
//SET: btlecity
		DRIVER(btlecity) //t:btlecity f:vsnes.c r: c:
//SET: starlstr
		DRIVER(starlstr) //t:starlstr f:vsnes.c r: c:
//SET: cstlevna
		DRIVER(cstlevna) //t:cstlevna f:vsnes.c r: c:
//SET: cluclu
		DRIVER(cluclu) //t:cluclu f:vsnes.c r: c:
//SET: drmario
		DRIVER(drmario) //t:drmario f:vsnes.c r: c:
//SET: duckhunt
		DRIVER(duckhunt) //t:duckhunt f:vsnes.c r: c:
//SET: excitebk
		DRIVER(excitebk) //t:excitebk f:vsnes.c r: c:
		DRIVER(excitebkj) //t:excitebkj f:vsnes.c r:excitebk c:excitebk
//SET: goonies
		DRIVER(goonies) //t:goonies f:vsnes.c r: c:
//SET: hogalley
		DRIVER(hogalley) //t:hogalley f:vsnes.c r: c:
//SET: iceclimb
		DRIVER(iceclimb) //t:iceclimb f:vsnes.c r: c:
		DRIVER(iceclimbj) //t:iceclimbj f:vsnes.c r:iceclimb c:iceclimb
//SET: machridr
		DRIVER(machridr) //t:machridr f:vsnes.c r: c:
		DRIVER(machridrj) //t:machridrj f:vsnes.c r:machridr c:machridr
//SET: rbibb
		DRIVER(rbibb) //t:rbibb f:vsnes.c r: c:
		DRIVER(rbibba) //t:rbibba f:vsnes.c r:rbibb c:rbibb
//SET: suprmrio
		DRIVER(suprmrio) //t:suprmrio f:vsnes.c r: c:
		DRIVER(suprmrioa) //t:suprmrioa f:vsnes.c r:suprmrio c:suprmrio
		DRIVER(suprmriobl) //t:suprmriobl f:vsnes.c r:suprmrio c:suprmrio
		DRIVER(suprmriobl2) //t:suprmriobl2 f:vsnes.c r:suprmrio c:suprmrio
		DRIVER(skatekds) //t:skatekds f:vsnes.c r:suprmrio c:suprmrio
//SET: vsskykid
		DRIVER(vsskykid) //t:vsskykid f:vsnes.c r: c:
//SET: tkoboxng
		DRIVER(tkoboxng) //t:tkoboxng f:vsnes.c r: c:
//SET: smgolf
		DRIVER(smgolf) //t:smgolf f:vsnes.c r: c:
		DRIVER(ladygolf) //t:ladygolf f:vsnes.c r:smgolf c:smgolf
		DRIVER(ladygolfe) //t:ladygolfe f:vsnes.c r:smgolf c:smgolf
		DRIVER(smgolfj) //t:smgolfj f:vsnes.c r:smgolf c:smgolf
		DRIVER(smgolfb) //t:smgolfb f:vsnes.c r:smgolf c:smgolf
//SET: vspinbal
		DRIVER(vspinbal) //t:vspinbal f:vsnes.c r: c:
		DRIVER(vspinbalj) //t:vspinbalj f:vsnes.c r:vspinbal c:vspinbal
//SET: vsslalom
		DRIVER(vsslalom) //t:vsslalom f:vsnes.c r: c:
//SET: vssoccer
		DRIVER(vssoccer) //t:vssoccer f:vsnes.c r: c:
		DRIVER(vssoccerj) //t:vssoccerj f:vsnes.c r:vssoccer c:vssoccer
//SET: vsgradus
		DRIVER(vsgradus) //t:vsgradus f:vsnes.c r: c:
//SET: platoon
		DRIVER(platoon) //t:platoon f:vsnes.c r: c:
//SET: vstetris
		DRIVER(vstetris) //t:vstetris f:vsnes.c r: c:
//SET: mightybj
		DRIVER(mightybj) //t:mightybj f:vsnes.c r: c:
//SET: jajamaru
		DRIVER(jajamaru) //t:jajamaru f:vsnes.c r: c:
//SET: topgun
		DRIVER(topgun) //t:topgun f:vsnes.c r: c:
//SET: bnglngby
		DRIVER(bnglngby) //t:bnglngby f:vsnes.c r: c:
//SET: vstennis
		DRIVER(vstennis) //t:vstennis f:vsnes.c r: c:
		DRIVER(vstennisj) //t:vstennisj f:vsnes.c r:vstennis c:vstennis
//SET: wrecking
		DRIVER(wrecking) //t:wrecking f:vsnes.c r: c:
//SET: balonfgt
		DRIVER(balonfgt) //t:balonfgt f:vsnes.c r: c:
//SET: vsmahjng
		DRIVER(vsmahjng) //t:vsmahjng f:vsnes.c r: c:
//SET: vsbball
		DRIVER(vsbball) //t:vsbball f:vsnes.c r: c:
		DRIVER(vsbballj) //t:vsbballj f:vsnes.c r:vsbball c:vsbball
		DRIVER(vsbballja) //t:vsbballja f:vsnes.c r:vsbball c:vsbball
		DRIVER(vsbballjb) //t:vsbballjb f:vsnes.c r:vsbball c:vsbball
//SET: iceclmrj
		DRIVER(iceclmrj) //t:iceclmrj f:vsnes.c r: c:
//SET: vsgshoe
		DRIVER(vsgshoe) //t:vsgshoe f:vsnes.c r: c:
//SET: supxevs
		DRIVER(supxevs) //t:supxevs f:vsnes.c r: c:
//SET: vsfdf
		DRIVER(vsfdf) //t:vsfdf f:vsnes.c r: c:
//SET: multigam
		DRIVER(multigam) //t:multigam f:multigam.c r: c:
		DRIVER(multigmb) //t:multigmb f:multigam.c r:multigam c:multigam
//SET: multigm2
		DRIVER(multigm2) //t:multigm2 f:multigam.c r: c:
//SET: multigm3
		DRIVER(multigm3) //t:multigm3 f:multigam.c r: c:
//SET: multigmt
		DRIVER(multigmt) //t:multigmt f:multigam.c r: c:
//SET: supergm3
		DRIVER(supergm3) //t:supergm3 f:multigam.c r: c:
//SET: cham24
		DRIVER(cham24) //t:cham24 f:cham24.c r: c:
//SET: nss
		DRIVER(nss) //t:nss f:nss.c r: c:
//SET: nss_ssoc
		DRIVER(nss_ssoc) //t:nss_ssoc f:nss.c r:nss c:
//SET: nss_actr
		DRIVER(nss_actr) //t:nss_actr f:nss.c r:nss c:
//SET: nss_con3
		DRIVER(nss_con3) //t:nss_con3 f:nss.c r:nss c:
//SET: nss_adam
		DRIVER(nss_adam) //t:nss_adam f:nss.c r:nss c:
//SET: nss_aten
		DRIVER(nss_aten) //t:nss_aten f:nss.c r:nss c:
//SET: nss_rob3
		DRIVER(nss_rob3) //t:nss_rob3 f:nss.c r:nss c:
//SET: nss_ncaa
		DRIVER(nss_ncaa) //t:nss_ncaa f:nss.c r:nss c:
//SET: nss_skin
		DRIVER(nss_skin) //t:nss_skin f:nss.c r:nss c:
//SET: nss_lwep
		DRIVER(nss_lwep) //t:nss_lwep f:nss.c r:nss c:
//SET: nss_smw
		DRIVER(nss_smw) //t:nss_smw f:nss.c r:nss c:
//SET: nss_fzer
		DRIVER(nss_fzer) //t:nss_fzer f:nss.c r:nss c:
//SET: nss_sten
		DRIVER(nss_sten) //t:nss_sten f:nss.c r:nss c:
//SET: sfcbox
		DRIVER(sfcbox) //t:sfcbox f:sfcbox.c r: c:
//SET: pss62
		DRIVER(pss62) //t:pss62 f:sfcbox.c r:sfcbox c:
//SET: kinstb
		DRIVER(kinstb) //t:kinstb f:snesb.c r: c:
//SET: ffight2b
		DRIVER(ffight2b) //t:ffight2b f:snesb.c r: c:
//SET: sblast2b
		DRIVER(sblast2b) //t:sblast2b f:snesb.c r: c:
//SET: iron
		DRIVER(iron) //t:iron f:snesb.c r: c:
//SET: endless
		DRIVER(endless) //t:endless f:snesb.c r: c:
//SET: denseib
		DRIVER(denseib) //t:denseib f:snesb.c r: c:
#endif

#ifdef PS3_SET_4
//SET: seawolf
		DRIVER(seawolf) //t:seawolf f:mw8080bw.c r: c:
		DRIVER(seawolfo) //t:seawolfo f:mw8080bw.c r:seawolf c:seawolf
//SET: gunfight
		DRIVER(gunfight) //t:gunfight f:mw8080bw.c r: c:
		DRIVER(gunfighto) //t:gunfighto f:mw8080bw.c r:gunfight c:gunfight
//SET: tornbase
		DRIVER(tornbase) //t:tornbase f:mw8080bw.c r: c:
//SET: 280zzzap
		DRIVER(280zzzap) //t:280zzzap f:mw8080bw.c r: c:
//SET: maze
		DRIVER(maze) //t:maze f:mw8080bw.c r: c:
//SET: boothill
		DRIVER(boothill) //t:boothill f:mw8080bw.c r: c:
//SET: checkmat
		DRIVER(checkmat) //t:checkmat f:mw8080bw.c r: c:
//SET: desertgu
		DRIVER(desertgu) //t:desertgu f:mw8080bw.c r: c:
		DRIVER(roadrunm) //t:roadrunm f:mw8080bw.c r:desertgu c:desertgu
//SET: dplay
		DRIVER(dplay) //t:dplay f:mw8080bw.c r: c:
//SET: lagunar
		DRIVER(lagunar) //t:lagunar f:mw8080bw.c r: c:
//SET: gmissile
		DRIVER(gmissile) //t:gmissile f:mw8080bw.c r: c:
//SET: m4
		DRIVER(m4) //t:m4 f:mw8080bw.c r: c:
//SET: clowns
		DRIVER(clowns) //t:clowns f:mw8080bw.c r: c:
		DRIVER(clowns1) //t:clowns1 f:mw8080bw.c r:clowns c:clowns
//SET: spacwalk
		DRIVER(spacwalk) //t:spacwalk f:mw8080bw.c r: c:
//SET: einning
		DRIVER(einning) //t:einning f:mw8080bw.c r: c:
//SET: shuffle
		DRIVER(shuffle) //t:shuffle f:mw8080bw.c r: c:
//SET: dogpatch
		DRIVER(dogpatch) //t:dogpatch f:mw8080bw.c r: c:
//SET: spcenctr
		DRIVER(spcenctr) //t:spcenctr f:mw8080bw.c r: c:
//SET: phantom2
		DRIVER(phantom2) //t:phantom2 f:mw8080bw.c r: c:
//SET: bowler
		DRIVER(bowler) //t:bowler f:mw8080bw.c r: c:
//SET: invaders
		DRIVER(invaders) //t:invaders f:mw8080bw.c r: c:
		DRIVER(searthin) //t:searthin f:8080bw.c r:invaders c:invaders
		DRIVER(searthina) //t:searthina f:8080bw.c r:invaders c:invaders
		DRIVER(invadrmr) //t:invadrmr f:8080bw.c r:invaders c:invaders
		DRIVER(spaceatt) //t:spaceatt f:8080bw.c r:invaders c:invaders
		DRIVER(spaceat2) //t:spaceat2 f:8080bw.c r:invaders c:invaders
		DRIVER(sinvzen) //t:sinvzen f:8080bw.c r:invaders c:invaders
		DRIVER(superinv) //t:superinv f:8080bw.c r:invaders c:invaders
		DRIVER(invasion) //t:invasion f:8080bw.c r:invaders c:invaders
		DRIVER(invasiona) //t:invasiona f:8080bw.c r:invaders c:invaders
		DRIVER(invasionb) //t:invasionb f:8080bw.c r:invaders c:invaders
		DRIVER(invasionrz) //t:invasionrz f:8080bw.c r:invaders c:invaders
		DRIVER(invasionrza) //t:invasionrza f:8080bw.c r:invaders c:invaders
		DRIVER(sinvemag) //t:sinvemag f:8080bw.c r:invaders c:invaders
		DRIVER(jspecter) //t:jspecter f:8080bw.c r:invaders c:invaders
		DRIVER(jspecter2) //t:jspecter2 f:8080bw.c r:invaders c:invaders
		DRIVER(cosmicmo) //t:cosmicmo f:8080bw.c r:invaders c:invaders
		DRIVER(cosmicm2) //t:cosmicm2 f:8080bw.c r:invaders c:invaders
		DRIVER(alieninv) //t:alieninv f:8080bw.c r:invaders c:invaders
		DRIVER(alieninvp2) //t:alieninvp2 f:8080bw.c r:invaders c:invaders
		DRIVER(tst_invd) //t:tst_invd f:8080bw.c r:invaders c:invaders
		DRIVER(sitv) //t:sitv f:8080bw.c r:invaders c:invaders
		DRIVER(sicv) //t:sicv f:8080bw.c r:invaders c:invaders
		DRIVER(sisv) //t:sisv f:8080bw.c r:invaders c:invaders
		DRIVER(sisv2) //t:sisv2 f:8080bw.c r:invaders c:invaders
		DRIVER(spacewr3) //t:spacewr3 f:8080bw.c r:invaders c:invaders
		DRIVER(invaderl) //t:invaderl f:8080bw.c r:invaders c:invaders
		DRIVER(invader4) //t:invader4 f:8080bw.c r:invaders c:invaders
		DRIVER(spceking) //t:spceking f:8080bw.c r:invaders c:invaders
		DRIVER(spcewars) //t:spcewars f:8080bw.c r:invaders c:invaders
		DRIVER(darthvdr) //t:darthvdr f:8080bw.c r:invaders c:invaders
//SET: blueshrk
		DRIVER(blueshrk) //t:blueshrk f:mw8080bw.c r: c:
//SET: invad2ct
		DRIVER(invad2ct) //t:invad2ct f:mw8080bw.c r: c:
//SET: invadpt2
		DRIVER(invadpt2) //t:invadpt2 f:8080bw.c r: c:
		DRIVER(invaddlx) //t:invaddlx f:8080bw.c r:invadpt2 c:invadpt2
		DRIVER(moonbase) //t:moonbase f:8080bw.c r:invadpt2 c:invadpt2
		DRIVER(moonbasea) //t:moonbasea f:8080bw.c r:invadpt2 c:invadpt2
//SET: vortex
		DRIVER(vortex) //t:vortex f:8080bw.c r: c:
//SET: modelr
		DRIVER(modelr) //t:modelr f:8080bw.c r: c:
//SET: sstrangr
		DRIVER(sstrangr) //t:sstrangr f:sstrangr.c r: c:
		DRIVER(sstrangr2) //t:sstrangr2 f:sstrangr.c r:sstrangr c:sstrangr
//SET: invrvnge
		DRIVER(invrvnge) //t:invrvnge f:8080bw.c r: c:
		DRIVER(invrvngea) //t:invrvngea f:8080bw.c r:invrvnge c:invrvnge
//SET: galxwars
		DRIVER(galxwars) //t:galxwars f:8080bw.c r: c:
		DRIVER(galxwars2) //t:galxwars2 f:8080bw.c r:galxwars c:galxwars
		DRIVER(galxwarst) //t:galxwarst f:8080bw.c r:galxwars c:galxwars
		DRIVER(starw) //t:starw f:8080bw.c r:galxwars c:galxwars
//SET: lrescue
		DRIVER(lrescue) //t:lrescue f:8080bw.c r: c:
		DRIVER(mlander) //t:mlander f:8080bw.c r:lrescue c:lrescue
		DRIVER(lrescuem) //t:lrescuem f:8080bw.c r:lrescue c:lrescue
		DRIVER(grescue) //t:grescue f:8080bw.c r:lrescue c:lrescue
		DRIVER(desterth) //t:desterth f:8080bw.c r:lrescue c:lrescue
//SET: rollingc
		DRIVER(rollingc) //t:rollingc f:8080bw.c r: c:
//SET: ozmawars
		DRIVER(ozmawars) //t:ozmawars f:8080bw.c r: c:
		DRIVER(ozmawars2) //t:ozmawars2 f:8080bw.c r:ozmawars c:ozmawars
		DRIVER(solfight) //t:solfight f:8080bw.c r:ozmawars c:ozmawars
		DRIVER(spaceph) //t:spaceph f:8080bw.c r:ozmawars c:ozmawars
//SET: galactic
		DRIVER(galactic) //t:galactic f:8080bw.c r: c:
		DRIVER(spacmiss) //t:spacmiss f:8080bw.c r:galactic c:galactic
//SET: schaser
		DRIVER(schaser) //t:schaser f:8080bw.c r: c:
		DRIVER(schasercv) //t:schasercv f:8080bw.c r:schaser c:schaser
//SET: lupin3
		DRIVER(lupin3) //t:lupin3 f:8080bw.c r: c:
		DRIVER(lupin3a) //t:lupin3a f:8080bw.c r:lupin3 c:lupin3
//SET: spclaser
		DRIVER(spclaser) //t:spclaser f:8080bw.c r: c:
		DRIVER(intruder) //t:intruder f:8080bw.c r:spclaser c:spclaser
		DRIVER(laser) //t:laser f:8080bw.c r:spclaser c:spclaser
		DRIVER(spcewarl) //t:spcewarl f:8080bw.c r:spclaser c:spclaser
//SET: polaris
		DRIVER(polaris) //t:polaris f:8080bw.c r: c:
		DRIVER(polarisa) //t:polarisa f:8080bw.c r:polaris c:polaris
		DRIVER(polariso) //t:polariso f:8080bw.c r:polaris c:polaris
//SET: ballbomb
		DRIVER(ballbomb) //t:ballbomb f:8080bw.c r: c:
//SET: indianbt
		DRIVER(indianbt) //t:indianbt f:8080bw.c r: c:
//SET: steelwkr
		DRIVER(steelwkr) //t:steelwkr f:8080bw.c r: c:
//SET: m79amb
		DRIVER(m79amb) //t:m79amb f:m79amb.c r: c:
//SET: yosakdon
		DRIVER(yosakdon) //t:yosakdon f:8080bw.c r: c:
		DRIVER(yosakdona) //t:yosakdona f:8080bw.c r:yosakdon c:yosakdon
//SET: astropal
		DRIVER(astropal) //t:astropal f:8080bw.c r: c:
//SET: cosmo
		DRIVER(cosmo) //t:cosmo f:8080bw.c r: c:
//SET: 18w
		DRIVER(18w) //t:18w f:mw18w.c r: c:
		DRIVER(18w2) //t:18w2 f:mw18w.c r:18w c:18w
//SET: sspeedr
		DRIVER(sspeedr) //t:sspeedr f:sspeedr.c r: c:
//SET: sflush
		DRIVER(sflush) //t:sflush f:8080bw.c r: c:
//SET: lazercmd
		DRIVER(lazercmd) //t:lazercmd f:lazercmd.c r: c:
//SET: bbonk
		DRIVER(bbonk) //t:bbonk f:lazercmd.c r: c:
//SET: deadeye
		DRIVER(deadeye) //t:deadeye f:meadows.c r: c:
//SET: bowl3d
		DRIVER(bowl3d) //t:bowl3d f:meadows.c r: c:
//SET: gypsyjug
		DRIVER(gypsyjug) //t:gypsyjug f:meadows.c r: c:
//SET: minferno
		DRIVER(minferno) //t:minferno f:meadows.c r: c:
//SET: medlanes
		DRIVER(medlanes) //t:medlanes f:lazercmd.c r: c:
//SET: cosmos
		DRIVER(cosmos) //t:cosmos f:cvs.c r: c:
//SET: darkwar
		DRIVER(darkwar) //t:darkwar f:cvs.c r: c:
//SET: spacefrt
		DRIVER(spacefrt) //t:spacefrt f:cvs.c r: c:
//SET: 8ball
		DRIVER(8ball) //t:8ball f:cvs.c r: c:
		DRIVER(8ball1) //t:8ball1 f:cvs.c r:8ball c:8ball
//SET: logger
		DRIVER(logger) //t:logger f:cvs.c r: c:
//SET: dazzler
		DRIVER(dazzler) //t:dazzler f:cvs.c r: c:
//SET: diggerc
		DRIVER(diggerc) //t:diggerc f:cvs.c r: c:
//SET: wallst
		DRIVER(wallst) //t:wallst f:cvs.c r: c:
//SET: radarzon
		DRIVER(radarzon) //t:radarzon f:cvs.c r: c:
		DRIVER(radarzon1) //t:radarzon1 f:cvs.c r:radarzon c:radarzon
		DRIVER(radarzont) //t:radarzont f:cvs.c r:radarzon c:radarzon
		DRIVER(outline) //t:outline f:cvs.c r:radarzon c:radarzon
//SET: goldbug
		DRIVER(goldbug) //t:goldbug f:cvs.c r: c:
//SET: heartatk
		DRIVER(heartatk) //t:heartatk f:cvs.c r: c:
//SET: hunchbak
		DRIVER(hunchbak) //t:hunchbak f:cvs.c r: c:
		DRIVER(hunchbkg) //t:hunchbkg f:galaxold.c r:hunchbak c:hunchbak
		DRIVER(hunchbks) //t:hunchbks f:scramble.c r:hunchbak c:hunchbak
		DRIVER(hunchbkd) //t:hunchbkd f:dkong.c r:hunchbak c:hunchbak
		DRIVER(hunchbaka) //t:hunchbaka f:cvs.c r:hunchbak c:hunchbak
//SET: superbik
		DRIVER(superbik) //t:superbik f:cvs.c r: c:
		DRIVER(sbdk) //t:sbdk f:dkong.c r:superbik c:superbik
//SET: raiders
		DRIVER(raiders) //t:raiders f:cvs.c r: c:
//SET: hero
		DRIVER(hero) //t:hero f:cvs.c r: c:
		DRIVER(herodk) //t:herodk f:dkong.c r:hero c:hero
		DRIVER(herodku) //t:herodku f:dkong.c r:hero c:hero
//SET: huncholy
		DRIVER(huncholy) //t:huncholy f:cvs.c r: c:
		DRIVER(hncholms) //t:hncholms f:scramble.c r:huncholy c:huncholy
		DRIVER(herbiedk) //t:herbiedk f:dkong.c r:huncholy c:huncholy
//SET: quasar
		DRIVER(quasar) //t:quasar f:quasar.c r: c:
		DRIVER(quasara) //t:quasara f:quasar.c r:quasar c:quasar
//SET: seawolf2
		DRIVER(seawolf2) //t:seawolf2 f:astrocde.c r: c:
//SET: spacezap
		DRIVER(spacezap) //t:spacezap f:astrocde.c r: c:
//SET: ebases
		DRIVER(ebases) //t:ebases f:astrocde.c r: c:
//SET: wow
		DRIVER(wow) //t:wow f:astrocde.c r: c:
		DRIVER(wowg) //t:wowg f:astrocde.c r:wow c:wow
//SET: gorf
		DRIVER(gorf) //t:gorf f:astrocde.c r: c:
		DRIVER(gorfpgm1) //t:gorfpgm1 f:astrocde.c r:gorf c:gorf
		DRIVER(gorfpgm1g) //t:gorfpgm1g f:astrocde.c r:gorf c:gorf
//SET: robby
		DRIVER(robby) //t:robby f:astrocde.c r: c:
//SET: demndrgn
		DRIVER(demndrgn) //t:demndrgn f:astrocde.c r: c:
//SET: profpac
		DRIVER(profpac) //t:profpac f:astrocde.c r: c:
//SET: tenpindx
		DRIVER(tenpindx) //t:tenpindx f:astrocde.c r: c:
//SET: solarfox
		DRIVER(solarfox) //t:solarfox f:mcr.c r: c:
//SET: kick
		DRIVER(kick) //t:kick f:mcr.c r: c:
		DRIVER(kickman) //t:kickman f:mcr.c r:kick c:kick
		DRIVER(kickc) //t:kickc f:mcr.c r:kick c:kick
//SET: shollow
		DRIVER(shollow) //t:shollow f:mcr.c r: c:
		DRIVER(shollow2) //t:shollow2 f:mcr.c r:shollow c:shollow
//SET: tron
		DRIVER(tron) //t:tron f:mcr.c r: c:
		DRIVER(tron2) //t:tron2 f:mcr.c r:tron c:tron
		DRIVER(tron3) //t:tron3 f:mcr.c r:tron c:tron
		DRIVER(tron4) //t:tron4 f:mcr.c r:tron c:tron
//SET: kroozr
		DRIVER(kroozr) //t:kroozr f:mcr.c r: c:
//SET: domino
		DRIVER(domino) //t:domino f:mcr.c r: c:
//SET: wacko
		DRIVER(wacko) //t:wacko f:mcr.c r: c:
//SET: twotiger
		DRIVER(twotiger) //t:twotiger f:mcr.c r: c:
		DRIVER(twotigerc) //t:twotigerc f:mcr.c r:twotiger c:twotiger
//SET: journey
		DRIVER(journey) //t:journey f:mcr.c r: c:
//SET: tapper
		DRIVER(tapper) //t:tapper f:mcr.c r: c:
		DRIVER(tappera) //t:tappera f:mcr.c r:tapper c:tapper
		DRIVER(sutapper) //t:sutapper f:mcr.c r:tapper c:tapper
		DRIVER(rbtapper) //t:rbtapper f:mcr.c r:tapper c:tapper
//SET: timber
		DRIVER(timber) //t:timber f:mcr.c r: c:
//SET: dotron
		DRIVER(dotron) //t:dotron f:mcr.c r: c:
		DRIVER(dotrona) //t:dotrona f:mcr.c r:dotron c:dotron
		DRIVER(dotrone) //t:dotrone f:mcr.c r:dotron c:dotron
//SET: nflfoot
		DRIVER(nflfoot) //t:nflfoot f:mcr.c r: c:
//SET: demoderb
		DRIVER(demoderb) //t:demoderb f:mcr.c r: c:
		DRIVER(demoderm) //t:demoderm f:mcr3.c r:demoderb c:demoderb
//SET: sarge
		DRIVER(sarge) //t:sarge f:mcr3.c r: c:
//SET: rampage
		DRIVER(rampage) //t:rampage f:mcr3.c r: c:
		DRIVER(rampage2) //t:rampage2 f:mcr3.c r:rampage c:rampage
//SET: powerdrv
		DRIVER(powerdrv) //t:powerdrv f:mcr3.c r: c:
//SET: stargrds
		DRIVER(stargrds) //t:stargrds f:mcr3.c r: c:
//SET: maxrpm
		DRIVER(maxrpm) //t:maxrpm f:mcr3.c r: c:
//SET: spyhunt
		DRIVER(spyhunt) //t:spyhunt f:mcr3.c r: c:
		DRIVER(spyhuntp) //t:spyhuntp f:mcr3.c r:spyhunt c:spyhunt
//SET: turbotag
		DRIVER(turbotag) //t:turbotag f:mcr3.c r: c:
//SET: crater
		DRIVER(crater) //t:crater f:mcr3.c r: c:
//SET: zwackery
		DRIVER(zwackery) //t:zwackery f:mcr68.c r: c:
//SET: xenophob
		DRIVER(xenophob) //t:xenophob f:mcr68.c r: c:
//SET: spyhunt2
		DRIVER(spyhunt2) //t:spyhunt2 f:mcr68.c r: c:
		DRIVER(spyhunt2a) //t:spyhunt2a f:mcr68.c r:spyhunt2 c:spyhunt2
//SET: blasted
		DRIVER(blasted) //t:blasted f:mcr68.c r: c:
		DRIVER(intlaser) //t:intlaser f:mcr68.c r:blasted c:blasted
//SET: archrivl
		DRIVER(archrivl) //t:archrivl f:mcr68.c r: c:
		DRIVER(archrivl2) //t:archrivl2 f:mcr68.c r:archrivl c:archrivl
//SET: trisport
		DRIVER(trisport) //t:trisport f:mcr68.c r: c:
//SET: pigskin
		DRIVER(pigskin) //t:pigskin f:mcr68.c r: c:
		DRIVER(pigskina) //t:pigskina f:mcr68.c r:pigskin c:pigskin
//SET: sentetst
		DRIVER(sentetst) //t:sentetst f:balsente.c r: c:
//SET: cshift
		DRIVER(cshift) //t:cshift f:balsente.c r: c:
//SET: gghost
		DRIVER(gghost) //t:gghost f:balsente.c r: c:
//SET: hattrick
		DRIVER(hattrick) //t:hattrick f:balsente.c r: c:
//SET: otwalls
		DRIVER(otwalls) //t:otwalls f:balsente.c r: c:
//SET: snakepit
		DRIVER(snakepit) //t:snakepit f:balsente.c r: c:
//SET: snakjack
		DRIVER(snakjack) //t:snakjack f:balsente.c r: c:
//SET: stocker
		DRIVER(stocker) //t:stocker f:balsente.c r: c:
//SET: triviag1
		DRIVER(triviag1) //t:triviag1 f:balsente.c r: c:
//SET: trivia12
		DRIVER(trivia12) //t:trivia12 f:balsente.c r: c:
//SET: triviag2
		DRIVER(triviag2) //t:triviag2 f:balsente.c r: c:
//SET: triviasp
		DRIVER(triviasp) //t:triviasp f:balsente.c r: c:
//SET: triviayp
		DRIVER(triviayp) //t:triviayp f:balsente.c r: c:
//SET: triviabb
		DRIVER(triviabb) //t:triviabb f:balsente.c r: c:
//SET: triviaes
		DRIVER(triviaes) //t:triviaes f:balsente.c r: c:
//SET: gimeabrk
		DRIVER(gimeabrk) //t:gimeabrk f:balsente.c r: c:
//SET: minigolf
		DRIVER(minigolf) //t:minigolf f:balsente.c r: c:
		DRIVER(minigolf2) //t:minigolf2 f:balsente.c r:minigolf c:minigolf
//SET: toggle
		DRIVER(toggle) //t:toggle f:balsente.c r: c:
//SET: nametune
		DRIVER(nametune) //t:nametune f:balsente.c r: c:
		DRIVER(nametune2) //t:nametune2 f:balsente.c r:nametune c:nametune
//SET: nstocker
		DRIVER(nstocker) //t:nstocker f:balsente.c r: c:
		DRIVER(nstocker2) //t:nstocker2 f:balsente.c r:nstocker c:nstocker
//SET: sfootbal
		DRIVER(sfootbal) //t:sfootbal f:balsente.c r: c:
//SET: spiker
		DRIVER(spiker) //t:spiker f:balsente.c r: c:
//SET: stompin
		DRIVER(stompin) //t:stompin f:balsente.c r: c:
//SET: rescraid
		DRIVER(rescraid) //t:rescraid f:balsente.c r: c:
		DRIVER(rescraida) //t:rescraida f:balsente.c r:rescraid c:rescraid
//SET: grudge
		DRIVER(grudge) //t:grudge f:balsente.c r: c:
//SET: shrike
		DRIVER(shrike) //t:shrike f:balsente.c r: c:
//SET: gridlee
		DRIVER(gridlee) //t:gridlee f:gridlee.c r: c:
//SET: andromed
		DRIVER(andromed) //t:andromed f:m10.c r: c:
//SET: ipminvad
		DRIVER(ipminvad) //t:ipminvad f:m10.c r: c:
		DRIVER(ipminvad1) //t:ipminvad1 f:m10.c r:ipminvad c:ipminvad
//SET: ptrmj
		DRIVER(ptrmj) //t:ptrmj f:m14.c r: c:
//SET: skychut
		DRIVER(skychut) //t:skychut f:m10.c r: c:
//SET: spacbeam
		DRIVER(spacbeam) //t:spacbeam f:m10.c r: c:
//SET: greenber
		DRIVER(greenber) //t:greenber f:m10.c r: c:
//SET: headoni
		DRIVER(headoni) //t:headoni f:m10.c r: c:
//SET: panther
		DRIVER(panther) //t:panther f:redalert.c r: c:
//SET: redalert
		DRIVER(redalert) //t:redalert f:redalert.c r: c:
//SET: demoneye
		DRIVER(demoneye) //t:demoneye f:redalert.c r: c:
//SET: ww3
		DRIVER(ww3) //t:ww3 f:redalert.c r: c:
//SET: olibochu
		DRIVER(olibochu) //t:olibochu f:olibochu.c r: c:
//SET: mpatrol
		DRIVER(mpatrol) //t:mpatrol f:m52.c r: c:
		DRIVER(mpatrolw) //t:mpatrolw f:m52.c r:mpatrol c:mpatrol
//SET: alpha1v
		DRIVER(alpha1v) //t:alpha1v f:m52.c r: c:
//SET: troangel
		DRIVER(troangel) //t:troangel f:m57.c r: c:
		DRIVER(newtangl) //t:newtangl f:m57.c r:troangel c:troangel
//SET: 10yard
		DRIVER(10yard) //t:10yard f:m58.c r: c:
		DRIVER(10yardj) //t:10yardj f:m58.c r:10yard c:10yard
		DRIVER(vs10yard) //t:vs10yard f:m58.c r:10yard c:10yard
		DRIVER(vs10yardj) //t:vs10yardj f:m58.c r:10yard c:10yard
		DRIVER(vs10yardu) //t:vs10yardu f:m58.c r:10yard c:10yard
		DRIVER(10yard85) //t:10yard85 f:m58.c r:10yard c:10yard
//SET: travrusa
		DRIVER(travrusa) //t:travrusa f:travrusa.c r: c:
		DRIVER(motorace) //t:motorace f:travrusa.c r:travrusa c:travrusa
//SET: shtrider
		DRIVER(shtrider) //t:shtrider f:travrusa.c r: c:
		DRIVER(shtridera) //t:shtridera f:travrusa.c r:shtrider c:shtrider
//SET: wilytowr
		DRIVER(wilytowr) //t:wilytowr f:m63.c r: c:
		DRIVER(atomboy) //t:atomboy f:m63.c r:wilytowr c:wilytowr
		DRIVER(atomboya) //t:atomboya f:m63.c r:wilytowr c:wilytowr
//SET: fghtbskt
		DRIVER(fghtbskt) //t:fghtbskt f:m63.c r: c:
//SET: kungfum
		DRIVER(kungfum) //t:kungfum f:m62.c r: c:
		DRIVER(kungfumd) //t:kungfumd f:m62.c r:kungfum c:kungfum
		DRIVER(spartanx) //t:spartanx f:m62.c r:kungfum c:kungfum
		DRIVER(kungfub) //t:kungfub f:m62.c r:kungfum c:kungfum
		DRIVER(kungfub2) //t:kungfub2 f:m62.c r:kungfum c:kungfum
//SET: battroad
		DRIVER(battroad) //t:battroad f:m62.c r: c:
//SET: ldrun
		DRIVER(ldrun) //t:ldrun f:m62.c r: c:
		DRIVER(ldruna) //t:ldruna f:m62.c r:ldrun c:ldrun
//SET: ldrun2
		DRIVER(ldrun2) //t:ldrun2 f:m62.c r: c:
//SET: ldrun3
		DRIVER(ldrun3) //t:ldrun3 f:m62.c r: c:
		DRIVER(ldrun3j) //t:ldrun3j f:m62.c r:ldrun3 c:ldrun3
//SET: ldrun4
		DRIVER(ldrun4) //t:ldrun4 f:m62.c r: c:
//SET: lotlot
		DRIVER(lotlot) //t:lotlot f:m62.c r: c:
//SET: kidniki
		DRIVER(kidniki) //t:kidniki f:m62.c r: c:
		DRIVER(kidnikiu) //t:kidnikiu f:m62.c r:kidniki c:kidniki
		DRIVER(yanchamr) //t:yanchamr f:m62.c r:kidniki c:kidniki
		DRIVER(lithero) //t:lithero f:m62.c r:kidniki c:kidniki
//SET: spelunkr
		DRIVER(spelunkr) //t:spelunkr f:m62.c r: c:
		DRIVER(spelunkrj) //t:spelunkrj f:m62.c r:spelunkr c:spelunkr
//SET: spelunk2
		DRIVER(spelunk2) //t:spelunk2 f:m62.c r: c:
//SET: horizon
		DRIVER(horizon) //t:horizon f:m62.c r: c:
//SET: youjyudn
		DRIVER(youjyudn) //t:youjyudn f:m62.c r: c:
//SET: vigilant
		DRIVER(vigilant) //t:vigilant f:vigilant.c r: c:
		DRIVER(vigilant1) //t:vigilant1 f:vigilant.c r:vigilant c:vigilant
		DRIVER(vigilantu) //t:vigilantu f:vigilant.c r:vigilant c:vigilant
		DRIVER(vigilantj) //t:vigilantj f:vigilant.c r:vigilant c:vigilant
//SET: kikcubic
		DRIVER(kikcubic) //t:kikcubic f:vigilant.c r: c:
		DRIVER(kikcubicb) //t:kikcubicb f:vigilant.c r:kikcubic c:kikcubic
//SET: buccanrs
		DRIVER(buccanrs) //t:buccanrs f:vigilant.c r: c:
		DRIVER(buccanrsa) //t:buccanrsa f:vigilant.c r:buccanrs c:buccanrs
//SET: rtype
		DRIVER(rtype) //t:rtype f:m72.c r: c:
		DRIVER(rtypej) //t:rtypej f:m72.c r:rtype c:rtype
		DRIVER(rtypejp) //t:rtypejp f:m72.c r:rtype c:rtype
		DRIVER(rtypeu) //t:rtypeu f:m72.c r:rtype c:rtype
		DRIVER(rtypeb) //t:rtypeb f:m72.c r:rtype c:rtype
//SET: bchopper
		DRIVER(bchopper) //t:bchopper f:m72.c r: c:
		DRIVER(mrheli) //t:mrheli f:m72.c r:bchopper c:bchopper
//SET: nspirit
		DRIVER(nspirit) //t:nspirit f:m72.c r: c:
		DRIVER(nspiritj) //t:nspiritj f:m72.c r:nspirit c:nspirit
//SET: imgfight
		DRIVER(imgfight) //t:imgfight f:m72.c r: c:
		DRIVER(imgfighto) //t:imgfighto f:m72.c r:imgfight c:imgfight
//SET: loht
		DRIVER(loht) //t:loht f:m72.c r: c:
		DRIVER(lohtj) //t:lohtj f:m72.c r:loht c:loht
		DRIVER(lohtb) //t:lohtb f:m72.c r:loht c:loht
		DRIVER(lohtb2) //t:lohtb2 f:m72.c r:loht c:loht
//SET: xmultipl
		DRIVER(xmultipl) //t:xmultipl f:m72.c r: c:
		DRIVER(xmultiplm72) //t:xmultiplm72 f:m72.c r:xmultipl c:xmultipl
//SET: dbreed
		DRIVER(dbreed) //t:dbreed f:m72.c r: c:
		DRIVER(dbreedm72) //t:dbreedm72 f:m72.c r:dbreed c:dbreed
//SET: rtype2
		DRIVER(rtype2) //t:rtype2 f:m72.c r: c:
		DRIVER(rtype2j) //t:rtype2j f:m72.c r:rtype2 c:rtype2
		DRIVER(rtype2jc) //t:rtype2jc f:m72.c r:rtype2 c:rtype2
//SET: majtitle
		DRIVER(majtitle) //t:majtitle f:m72.c r: c:
		DRIVER(majtitlej) //t:majtitlej f:m72.c r:majtitle c:majtitle
//SET: hharry
		DRIVER(hharry) //t:hharry f:m72.c r: c:
		DRIVER(hharryu) //t:hharryu f:m72.c r:hharry c:hharry
		DRIVER(dkgensan) //t:dkgensan f:m72.c r:hharry c:hharry
		DRIVER(dkgensanm72) //t:dkgensanm72 f:m72.c r:hharry c:hharry
//SET: poundfor
		DRIVER(poundfor) //t:poundfor f:m72.c r: c:
		DRIVER(poundforj) //t:poundforj f:m72.c r:poundfor c:poundfor
		DRIVER(poundforu) //t:poundforu f:m72.c r:poundfor c:poundfor
//SET: airduel
		DRIVER(airduel) //t:airduel f:m72.c r: c:
//SET: cosmccop
		DRIVER(cosmccop) //t:cosmccop f:m72.c r: c:
		DRIVER(gallop) //t:gallop f:m72.c r:cosmccop c:cosmccop
//SET: kengo
		DRIVER(kengo) //t:kengo f:m72.c r: c:
//SET: matchit
		DRIVER(matchit) //t:matchit f:shisen.c r: c:
		DRIVER(sichuan2) //t:sichuan2 f:shisen.c r:matchit c:matchit
		DRIVER(sichuan2a) //t:sichuan2a f:shisen.c r:matchit c:matchit
		DRIVER(shisen) //t:shisen f:shisen.c r:matchit c:matchit
//SET: hasamu
		DRIVER(hasamu) //t:hasamu f:m90.c r: c:
//SET: dynablst
		DRIVER(dynablst) //t:dynablst f:m90.c r: c:
		DRIVER(dynablstb) //t:dynablstb f:m90.c r:dynablst c:dynablst
		DRIVER(bombrman) //t:bombrman f:m90.c r:dynablst c:dynablst
		DRIVER(atompunk) //t:atompunk f:m90.c r:dynablst c:dynablst
//SET: bbmanw
		DRIVER(bbmanw) //t:bbmanw f:m90.c r: c:
		DRIVER(bbmanwj) //t:bbmanwj f:m90.c r:bbmanw c:bbmanw
		DRIVER(bomblord) //t:bomblord f:m90.c r:bbmanw c:bbmanw
		DRIVER(newapunk) //t:newapunk f:m90.c r:bbmanw c:bbmanw
//SET: quizf1
		DRIVER(quizf1) //t:quizf1 f:m90.c r: c:
//SET: riskchal
		DRIVER(riskchal) //t:riskchal f:m90.c r: c:
		DRIVER(gussun) //t:gussun f:m90.c r:riskchal c:riskchal
//SET: matchit2
		DRIVER(matchit2) //t:matchit2 f:m90.c r: c:
		DRIVER(shisen2) //t:shisen2 f:m90.c r:matchit2 c:matchit2
//SET: gunforce
		DRIVER(gunforce) //t:gunforce f:m92.c r: c:
		DRIVER(gunforceu) //t:gunforceu f:m92.c r:gunforce c:gunforce
		DRIVER(gunforcej) //t:gunforcej f:m92.c r:gunforce c:gunforce
//SET: bmaster
		DRIVER(bmaster) //t:bmaster f:m92.c r: c:
		DRIVER(crossbld) //t:crossbld f:m92.c r:bmaster c:bmaster
//SET: lethalth
		DRIVER(lethalth) //t:lethalth f:m92.c r: c:
		DRIVER(thndblst) //t:thndblst f:m92.c r:lethalth c:lethalth
//SET: uccops
		DRIVER(uccops) //t:uccops f:m92.c r: c:
		DRIVER(uccopsu) //t:uccopsu f:m92.c r:uccops c:uccops
		DRIVER(uccopsar) //t:uccopsar f:m92.c r:uccops c:uccops
		DRIVER(uccopsj) //t:uccopsj f:m92.c r:uccops c:uccops
//SET: mysticri
		DRIVER(mysticri) //t:mysticri f:m92.c r: c:
		DRIVER(mysticrib) //t:mysticrib f:m92.c r:mysticri c:mysticri
		DRIVER(gunhohki) //t:gunhohki f:m92.c r:mysticri c:mysticri
//SET: majtitl2
		DRIVER(majtitl2) //t:majtitl2 f:m92.c r: c:
		DRIVER(majtitl2j) //t:majtitl2j f:m92.c r:majtitl2 c:majtitl2
		DRIVER(skingame) //t:skingame f:m92.c r:majtitl2 c:majtitl2
		DRIVER(skingame2) //t:skingame2 f:m92.c r:majtitl2 c:majtitl2
//SET: hook
		DRIVER(hook) //t:hook f:m92.c r: c:
		DRIVER(hooku) //t:hooku f:m92.c r:hook c:hook
		DRIVER(hookj) //t:hookj f:m92.c r:hook c:hook
		DRIVER(ppan) //t:ppan f:m92.c r:hook c:hook
//SET: rtypeleo
		DRIVER(rtypeleo) //t:rtypeleo f:m92.c r: c:
		DRIVER(rtypeleoj) //t:rtypeleoj f:m92.c r:rtypeleo c:rtypeleo
//SET: inthunt
		DRIVER(inthunt) //t:inthunt f:m92.c r: c:
		DRIVER(inthuntu) //t:inthuntu f:m92.c r:inthunt c:inthunt
		DRIVER(kaiteids) //t:kaiteids f:m92.c r:inthunt c:inthunt
//SET: nbbatman
		DRIVER(nbbatman) //t:nbbatman f:m92.c r: c:
		DRIVER(leaguemn) //t:leaguemn f:m92.c r:nbbatman c:nbbatman
//SET: ssoldier
		DRIVER(ssoldier) //t:ssoldier f:m92.c r: c:
		DRIVER(psoldier) //t:psoldier f:m92.c r:ssoldier c:ssoldier
//SET: gunforc2
		DRIVER(gunforc2) //t:gunforc2 f:m92.c r: c:
		DRIVER(geostorm) //t:geostorm f:m92.c r:gunforc2 c:gunforc2
//SET: firebarr
		DRIVER(firebarr) //t:firebarr f:m107.c r: c:
//SET: dsoccr94
		DRIVER(dsoccr94) //t:dsoccr94 f:m107.c r: c:
		DRIVER(dsoccr94j) //t:dsoccr94j f:m92.c r:dsoccr94 c:dsoccr94
//SET: wpksoc
		DRIVER(wpksoc) //t:wpksoc f:m107.c r: c:
		DRIVER(kftgoal) //t:kftgoal f:m107.c r:wpksoc c:wpksoc
//SET: reactor
		DRIVER(reactor) //t:reactor f:gottlieb.c r: c:
//SET: mplanets
		DRIVER(mplanets) //t:mplanets f:gottlieb.c r: c:
		DRIVER(mplanetsuk) //t:mplanetsuk f:gottlieb.c r:mplanets c:mplanets
//SET: qbert
		DRIVER(qbert) //t:qbert f:gottlieb.c r: c:
		DRIVER(qberta) //t:qberta f:gottlieb.c r:qbert c:qbert
		DRIVER(qbertj) //t:qbertj f:gottlieb.c r:qbert c:qbert
		DRIVER(myqbert) //t:myqbert f:gottlieb.c r:qbert c:qbert
		DRIVER(qberttst) //t:qberttst f:gottlieb.c r:qbert c:qbert
		DRIVER(qbtrktst) //t:qbtrktst f:gottlieb.c r:qbert c:qbert
//SET: insector
		DRIVER(insector) //t:insector f:gottlieb.c r: c:
//SET: tylz
		DRIVER(tylz) //t:tylz f:gottlieb.c r: c:
//SET: argusg
		DRIVER(argusg) //t:argusg f:gottlieb.c r: c:
//SET: krull
		DRIVER(krull) //t:krull f:gottlieb.c r: c:
//SET: kngtmare
		DRIVER(kngtmare) //t:kngtmare f:gottlieb.c r: c:
//SET: sqbert
		DRIVER(sqbert) //t:sqbert f:gottlieb.c r: c:
//SET: mach3
		DRIVER(mach3) //t:mach3 f:gottlieb.c r: c:
//SET: usvsthem
		DRIVER(usvsthem) //t:usvsthem f:gottlieb.c r: c:
//SET: 3stooges
		DRIVER(3stooges) //t:3stooges f:gottlieb.c r: c:
//SET: qbertqub
		DRIVER(qbertqub) //t:qbertqub f:gottlieb.c r: c:
//SET: screwloo
		DRIVER(screwloo) //t:screwloo f:gottlieb.c r: c:
//SET: curvebal
		DRIVER(curvebal) //t:curvebal f:gottlieb.c r: c:
//SET: vidvince
		DRIVER(vidvince) //t:vidvince f:gottlieb.c r: c:
//SET: wizwarz
		DRIVER(wizwarz) //t:wizwarz f:gottlieb.c r: c:
//SET: qix
		DRIVER(qix) //t:qix f:qix.c r: c:
		DRIVER(qixa) //t:qixa f:qix.c r:qix c:qix
		DRIVER(qixb) //t:qixb f:qix.c r:qix c:qix
		DRIVER(qixo) //t:qixo f:qix.c r:qix c:qix
		DRIVER(qix2) //t:qix2 f:qix.c r:qix c:qix
//SET: sdungeon
		DRIVER(sdungeon) //t:sdungeon f:qix.c r: c:
//SET: elecyoyo
		DRIVER(elecyoyo) //t:elecyoyo f:qix.c r: c:
		DRIVER(elecyoyo2) //t:elecyoyo2 f:qix.c r:elecyoyo c:elecyoyo
//SET: kram
		DRIVER(kram) //t:kram f:qix.c r: c:
		DRIVER(kram2) //t:kram2 f:qix.c r:kram c:kram
		DRIVER(kram3) //t:kram3 f:qix.c r:kram c:kram
//SET: zookeep
		DRIVER(zookeep) //t:zookeep f:qix.c r: c:
		DRIVER(zookeep2) //t:zookeep2 f:qix.c r:zookeep c:zookeep
		DRIVER(zookeep3) //t:zookeep3 f:qix.c r:zookeep c:zookeep
//SET: slither
		DRIVER(slither) //t:slither f:qix.c r: c:
		DRIVER(slithera) //t:slithera f:qix.c r:slither c:slither
//SET: complexx
		DRIVER(complexx) //t:complexx f:qix.c r: c:
//SET: spaceskr
		DRIVER(spaceskr) //t:spaceskr f:taitosj.c r: c:
//SET: spacecr
		DRIVER(spacecr) //t:spacecr f:taitosj.c r: c:
//SET: junglek
		DRIVER(junglek) //t:junglek f:taitosj.c r: c:
		DRIVER(junglekj2) //t:junglekj2 f:taitosj.c r:junglek c:junglek
		DRIVER(jungleh) //t:jungleh f:taitosj.c r:junglek c:junglek
		DRIVER(junglehbr) //t:junglehbr f:taitosj.c r:junglek c:junglek
		DRIVER(piratpet) //t:piratpet f:taitosj.c r:junglek c:junglek
		DRIVER(jungleby) //t:jungleby f:taitosj.c r:junglek c:junglek
//SET: alpine
		DRIVER(alpine) //t:alpine f:taitosj.c r: c:
		DRIVER(alpinea) //t:alpinea f:taitosj.c r:alpine c:alpine
//SET: timetunl
		DRIVER(timetunl) //t:timetunl f:taitosj.c r: c:
//SET: wwestern
		DRIVER(wwestern) //t:wwestern f:taitosj.c r: c:
		DRIVER(wwestern1) //t:wwestern1 f:taitosj.c r:wwestern c:wwestern
//SET: frontlin
		DRIVER(frontlin) //t:frontlin f:taitosj.c r: c:
//SET: elevator
		DRIVER(elevator) //t:elevator f:taitosj.c r: c:
		DRIVER(elevatorb) //t:elevatorb f:taitosj.c r:elevator c:elevator
//SET: tinstar
		DRIVER(tinstar) //t:tinstar f:taitosj.c r: c:
		DRIVER(tinstar2) //t:tinstar2 f:taitosj.c r:tinstar c:tinstar
//SET: waterski
		DRIVER(waterski) //t:waterski f:taitosj.c r: c:
//SET: bioatack
		DRIVER(bioatack) //t:bioatack f:taitosj.c r: c:
//SET: hwrace
		DRIVER(hwrace) //t:hwrace f:taitosj.c r: c:
//SET: sfposeid
		DRIVER(sfposeid) //t:sfposeid f:taitosj.c r: c:
//SET: kikstart
		DRIVER(kikstart) //t:kikstart f:taitosj.c r: c:
//SET: fgoal
		DRIVER(fgoal) //t:fgoal f:fgoal.c r: c:
		DRIVER(fgoala) //t:fgoala f:fgoal.c r:fgoal c:fgoal
//SET: crbaloon
		DRIVER(crbaloon) //t:crbaloon f:crbaloon.c r: c:
		DRIVER(crbaloon2) //t:crbaloon2 f:crbaloon.c r:crbaloon c:crbaloon
//SET: sbowling
		DRIVER(sbowling) //t:sbowling f:sbowling.c r: c:
//SET: grchamp
		DRIVER(grchamp) //t:grchamp f:grchamp.c r: c:
//SET: marinedt
		DRIVER(marinedt) //t:marinedt f:marinedt.c r: c:
//SET: changela
		DRIVER(changela) //t:changela f:changela.c r: c:
//SET: fspiderb
		DRIVER(fspiderb) //t:fspiderb f:jollyjgr.c r: c:
//SET: jollyjgr
		DRIVER(jollyjgr) //t:jollyjgr f:jollyjgr.c r: c:
//SET: bking
		DRIVER(bking) //t:bking f:bking.c r: c:
//SET: bking2
		DRIVER(bking2) //t:bking2 f:bking.c r: c:
//SET: bking3
		DRIVER(bking3) //t:bking3 f:bking.c r: c:
//SET: chaknpop
		DRIVER(chaknpop) //t:chaknpop f:chaknpop.c r: c:
//SET: josvolly
		DRIVER(josvolly) //t:josvolly f:gsword.c r: c:
//SET: gsword
		DRIVER(gsword) //t:gsword f:gsword.c r: c:
		DRIVER(gsword2) //t:gsword2 f:gsword.c r:gsword c:gsword
//SET: cyclemb
		DRIVER(cyclemb) //t:cyclemb f:cyclemb.c r: c:
//SET: pitnrun
		DRIVER(pitnrun) //t:pitnrun f:pitnrun.c r: c:
		DRIVER(pitnruna) //t:pitnruna f:pitnrun.c r:pitnrun c:pitnrun
//SET: lkage
		DRIVER(lkage) //t:lkage f:lkage.c r: c:
		DRIVER(lkageo) //t:lkageo f:lkage.c r:lkage c:lkage
		DRIVER(lkageoo) //t:lkageoo f:lkage.c r:lkage c:lkage
		DRIVER(lkageb) //t:lkageb f:lkage.c r:lkage c:lkage
		DRIVER(lkageb2) //t:lkageb2 f:lkage.c r:lkage c:lkage
		DRIVER(lkageb3) //t:lkageb3 f:lkage.c r:lkage c:lkage
//SET: bygone
		DRIVER(bygone) //t:bygone f:lkage.c r: c:
//SET: msisaac
		DRIVER(msisaac) //t:msisaac f:msisaac.c r: c:
//SET: retofinv
		DRIVER(retofinv) //t:retofinv f:retofinv.c r: c:
		DRIVER(retofinv1) //t:retofinv1 f:retofinv.c r:retofinv c:retofinv
		DRIVER(retofinv2) //t:retofinv2 f:retofinv.c r:retofinv c:retofinv
//SET: fightrol
		DRIVER(fightrol) //t:fightrol f:rollrace.c r: c:
		DRIVER(rollace) //t:rollace f:rollrace.c r:fightrol c:fightrol
		DRIVER(rollace2) //t:rollace2 f:rollrace.c r:fightrol c:fightrol
//SET: lgp
		DRIVER(lgp) //t:lgp f:lgp.c r: c:
//SET: vsgongf
		DRIVER(vsgongf) //t:vsgongf f:tsamurai.c r: c:
		DRIVER(ringfgt) //t:ringfgt f:tsamurai.c r:vsgongf c:vsgongf
		DRIVER(ringfgt2) //t:ringfgt2 f:tsamurai.c r:vsgongf c:vsgongf
//SET: fieldday
		DRIVER(fieldday) //t:fieldday f:40love.c r: c:
		DRIVER(undoukai) //t:undoukai f:40love.c r:fieldday c:fieldday
//SET: 40love
		DRIVER(40love) //t:40love f:40love.c r: c:
//SET: tsamurai
		DRIVER(tsamurai) //t:tsamurai f:tsamurai.c r: c:
		DRIVER(tsamurai2) //t:tsamurai2 f:tsamurai.c r:tsamurai c:tsamurai
		DRIVER(tsamuraih) //t:tsamuraih f:tsamurai.c r:tsamurai c:tsamurai
//SET: ladymstr
		DRIVER(ladymstr) //t:ladymstr f:tsamurai.c r: c:
		DRIVER(nunchaku) //t:nunchaku f:tsamurai.c r:ladymstr c:ladymstr
//SET: yamagchi
		DRIVER(yamagchi) //t:yamagchi f:tsamurai.c r: c:
//SET: m660
		DRIVER(m660) //t:m660 f:tsamurai.c r: c:
		DRIVER(m660j) //t:m660j f:tsamurai.c r:m660 c:m660
		DRIVER(m660b) //t:m660b f:tsamurai.c r:m660 c:m660
		DRIVER(alphaxz) //t:alphaxz f:tsamurai.c r:m660 c:m660
//SET: buggychl
		DRIVER(buggychl) //t:buggychl f:buggychl.c r: c:
		DRIVER(buggychlt) //t:buggychlt f:buggychl.c r:buggychl c:buggychl
//SET: ssrj
		DRIVER(ssrj) //t:ssrj f:ssrj.c r: c:
//SET: bigevglf
		DRIVER(bigevglf) //t:bigevglf f:bigevglf.c r: c:
		DRIVER(bigevglfj) //t:bigevglfj f:bigevglf.c r:bigevglf c:bigevglf
//SET: flstory
		DRIVER(flstory) //t:flstory f:flstory.c r: c:
		DRIVER(flstoryj) //t:flstoryj f:flstory.c r:flstory c:flstory
//SET: onna34ro
		DRIVER(onna34ro) //t:onna34ro f:flstory.c r: c:
		DRIVER(onna34roa) //t:onna34roa f:flstory.c r:onna34ro c:onna34ro
//SET: victnine
		DRIVER(victnine) //t:victnine f:flstory.c r: c:
//SET: rumba
		DRIVER(rumba) //t:rumba f:flstory.c r: c:
//SET: gladiatr
		DRIVER(gladiatr) //t:gladiatr f:gladiatr.c r: c:
		DRIVER(ogonsiro) //t:ogonsiro f:gladiatr.c r:gladiatr c:gladiatr
		DRIVER(greatgur) //t:greatgur f:gladiatr.c r:gladiatr c:gladiatr
//SET: ppking
		DRIVER(ppking) //t:ppking f:gladiatr.c r: c:
//SET: nycaptor
		DRIVER(nycaptor) //t:nycaptor f:nycaptor.c r: c:
		DRIVER(colt) //t:colt f:nycaptor.c r:nycaptor c:nycaptor
//SET: cyclshtg
		DRIVER(cyclshtg) //t:cyclshtg f:nycaptor.c r: c:
		DRIVER(bronx) //t:bronx f:nycaptor.c r:cyclshtg c:cyclshtg
//SET: ksayakyu
		DRIVER(ksayakyu) //t:ksayakyu f:ksayakyu.c r: c:
//SET: benberob
		DRIVER(benberob) //t:benberob f:halleys.c r: c:
//SET: halleys
		DRIVER(halleys) //t:halleys f:halleys.c r: c:
		DRIVER(halleysc) //t:halleysc f:halleys.c r:halleys c:halleys
		DRIVER(halleycj) //t:halleycj f:halleys.c r:halleys c:halleys
		DRIVER(halley87) //t:halley87 f:halleys.c r:halleys c:halleys
//SET: lsasquad
		DRIVER(lsasquad) //t:lsasquad f:lsasquad.c r: c:
		DRIVER(storming) //t:storming f:lsasquad.c r:lsasquad c:lsasquad
//SET: daikaiju
		DRIVER(daikaiju) //t:daikaiju f:lsasquad.c r: c:
//SET: tokio
		DRIVER(tokio) //t:tokio f:bublbobl.c r: c:
		DRIVER(tokioo) //t:tokioo f:bublbobl.c r:tokio c:tokio
		DRIVER(tokiou) //t:tokiou f:bublbobl.c r:tokio c:tokio
		DRIVER(tokiob) //t:tokiob f:bublbobl.c r:tokio c:tokio
//SET: bublbobl
		DRIVER(bublbobl) //t:bublbobl f:bublbobl.c r: c:
		DRIVER(bublbobl1) //t:bublbobl1 f:bublbobl.c r:bublbobl c:bublbobl
		DRIVER(bublboblr) //t:bublboblr f:bublbobl.c r:bublbobl c:bublbobl
		DRIVER(bublboblr1) //t:bublboblr1 f:bublbobl.c r:bublbobl c:bublbobl
		DRIVER(boblbobl) //t:boblbobl f:bublbobl.c r:bublbobl c:bublbobl
		DRIVER(sboblboa) //t:sboblboa f:bublbobl.c r:bublbobl c:bublbobl
		DRIVER(sboblbob) //t:sboblbob f:bublbobl.c r:bublbobl c:bublbobl
		DRIVER(bub68705) //t:bub68705 f:bublbobl.c r:bublbobl c:bublbobl
		DRIVER(dland) //t:dland f:bublbobl.c r:bublbobl c:bublbobl
//SET: missb2
		DRIVER(missb2) //t:missb2 f:missb2.c r: c:
		DRIVER(bublpong) //t:bublpong f:missb2.c r:missb2 c:missb2
//SET: kikikai
		DRIVER(kikikai) //t:kikikai f:mexico86.c r: c:
		DRIVER(knightb) //t:knightb f:mexico86.c r:kikikai c:kikikai
//SET: kicknrun
		DRIVER(kicknrun) //t:kicknrun f:mexico86.c r: c:
		DRIVER(kicknrunu) //t:kicknrunu f:mexico86.c r:kicknrun c:kicknrun
		DRIVER(mexico86) //t:mexico86 f:mexico86.c r:kicknrun c:kicknrun
//SET: darius
		DRIVER(darius) //t:darius f:darius.c r: c:
		DRIVER(dariusj) //t:dariusj f:darius.c r:darius c:darius
		DRIVER(dariuso) //t:dariuso f:darius.c r:darius c:darius
		DRIVER(dariuse) //t:dariuse f:darius.c r:darius c:darius
//SET: rastan
		DRIVER(rastan) //t:rastan f:rastan.c r: c:
		DRIVER(rastanu) //t:rastanu f:rastan.c r:rastan c:rastan
		DRIVER(rastanu2) //t:rastanu2 f:rastan.c r:rastan c:rastan
		DRIVER(rastsaga) //t:rastsaga f:rastan.c r:rastan c:rastan
		DRIVER(rastsaga1) //t:rastsaga1 f:rastan.c r:rastan c:rastan
//SET: topspeed
		DRIVER(topspeed) //t:topspeed f:topspeed.c r: c:
		DRIVER(topspeedu) //t:topspeedu f:topspeed.c r:topspeed c:topspeed
		DRIVER(fullthrl) //t:fullthrl f:topspeed.c r:topspeed c:topspeed
//SET: opwolf
		DRIVER(opwolf) //t:opwolf f:opwolf.c r: c:
		DRIVER(opwolfa) //t:opwolfa f:opwolf.c r:opwolf c:opwolf
		DRIVER(opwolfj) //t:opwolfj f:opwolf.c r:opwolf c:opwolf
		DRIVER(opwolfu) //t:opwolfu f:opwolf.c r:opwolf c:opwolf
		DRIVER(opwolfb) //t:opwolfb f:opwolf.c r:opwolf c:opwolf
//SET: othunder
		DRIVER(othunder) //t:othunder f:othunder.c r: c:
		DRIVER(othunderu) //t:othunderu f:othunder.c r:othunder c:othunder
		DRIVER(othunderuo) //t:othunderuo f:othunder.c r:othunder c:othunder
		DRIVER(othunderj) //t:othunderj f:othunder.c r:othunder c:othunder
//SET: rainbow
		DRIVER(rainbow) //t:rainbow f:rainbow.c r: c:
		DRIVER(rainbowo) //t:rainbowo f:rainbow.c r:rainbow c:rainbow
		DRIVER(rainbowe) //t:rainbowe f:rainbow.c r:rainbow c:rainbow
		DRIVER(jumping) //t:jumping f:rainbow.c r:rainbow c:rainbow
//SET: arkanoid
		DRIVER(arkanoid) //t:arkanoid f:arkanoid.c r: c:
		DRIVER(arkanoidu) //t:arkanoidu f:arkanoid.c r:arkanoid c:arkanoid
		DRIVER(arkanoiduo) //t:arkanoiduo f:arkanoid.c r:arkanoid c:arkanoid
		DRIVER(arkanoidj) //t:arkanoidj f:arkanoid.c r:arkanoid c:arkanoid
		DRIVER(arkmcubl) //t:arkmcubl f:arkanoid.c r:arkanoid c:arkanoid
		DRIVER(ark1ball) //t:ark1ball f:arkanoid.c r:arkanoid c:arkanoid
		DRIVER(arkangc) //t:arkangc f:arkanoid.c r:arkanoid c:arkanoid
		DRIVER(arkangc2) //t:arkangc2 f:arkanoid.c r:arkanoid c:arkanoid
		DRIVER(arkblock) //t:arkblock f:arkanoid.c r:arkanoid c:arkanoid
		DRIVER(arkbloc2) //t:arkbloc2 f:arkanoid.c r:arkanoid c:arkanoid
		DRIVER(arkbloc3) //t:arkbloc3 f:arkanoid.c r:arkanoid c:arkanoid
		DRIVER(arkgcbl) //t:arkgcbl f:arkanoid.c r:arkanoid c:arkanoid
		DRIVER(arkgcbla) //t:arkgcbla f:arkanoid.c r:arkanoid c:arkanoid
		DRIVER(paddle2) //t:paddle2 f:arkanoid.c r:arkanoid c:arkanoid
		DRIVER(block2) //t:block2 f:arkanoid.c r:arkanoid c:arkanoid
		DRIVER(arkatayt) //t:arkatayt f:arkanoid.c r:arkanoid c:arkanoid
		DRIVER(arktayt2) //t:arktayt2 f:arkanoid.c r:arkanoid c:arkanoid
		DRIVER(arkatour) //t:arkatour f:arkanoid.c r:arkanoid c:arkanoid
//SET: tetrsark
		DRIVER(tetrsark) //t:tetrsark f:arkanoid.c r: c:
//SET: hexa
		DRIVER(hexa) //t:hexa f:arkanoid.c r: c:
//SET: sqix
		DRIVER(sqix) //t:sqix f:superqix.c r: c:
		DRIVER(sqixr1) //t:sqixr1 f:superqix.c r:sqix c:sqix
		DRIVER(sqixu) //t:sqixu f:superqix.c r:sqix c:sqix
		DRIVER(sqixb1) //t:sqixb1 f:superqix.c r:sqix c:sqix
		DRIVER(sqixb2) //t:sqixb2 f:superqix.c r:sqix c:sqix
//SET: perestro
		DRIVER(perestro) //t:perestro f:superqix.c r: c:
		DRIVER(perestrof) //t:perestrof f:superqix.c r:perestro c:perestro
//SET: pbillian
		DRIVER(pbillian) //t:pbillian f:superqix.c r: c:
//SET: hotsmash
		DRIVER(hotsmash) //t:hotsmash f:superqix.c r: c:
//SET: exzisus
		DRIVER(exzisus) //t:exzisus f:exzisus.c r: c:
		DRIVER(exzisusa) //t:exzisusa f:exzisus.c r:exzisus c:exzisus
//SET: minivadr
		DRIVER(minivadr) //t:minivadr f:minivadr.c r: c:
//SET: volfied
		DRIVER(volfied) //t:volfied f:volfied.c r: c:
		DRIVER(volfiedu) //t:volfiedu f:volfied.c r:volfied c:volfied
		DRIVER(volfiedj) //t:volfiedj f:volfied.c r:volfied c:volfied
		DRIVER(volfiedjo) //t:volfiedjo f:volfied.c r:volfied c:volfied
//SET: bonzeadv
		DRIVER(bonzeadv) //t:bonzeadv f:asuka.c r: c:
		DRIVER(bonzeadvo) //t:bonzeadvo f:asuka.c r:bonzeadv c:bonzeadv
		DRIVER(bonzeadvu) //t:bonzeadvu f:asuka.c r:bonzeadv c:bonzeadv
		DRIVER(jigkmgri) //t:jigkmgri f:asuka.c r:bonzeadv c:bonzeadv
//SET: asuka
		DRIVER(asuka) //t:asuka f:asuka.c r: c:
		DRIVER(asukaj) //t:asukaj f:asuka.c r:asuka c:asuka
//SET: mofflott
		DRIVER(mofflott) //t:mofflott f:asuka.c r: c:
//SET: cadash
		DRIVER(cadash) //t:cadash f:asuka.c r: c:
		DRIVER(cadashj) //t:cadashj f:asuka.c r:cadash c:cadash
		DRIVER(cadashu) //t:cadashu f:asuka.c r:cadash c:cadash
		DRIVER(cadashi) //t:cadashi f:asuka.c r:cadash c:cadash
		DRIVER(cadashf) //t:cadashf f:asuka.c r:cadash c:cadash
		DRIVER(cadashg) //t:cadashg f:asuka.c r:cadash c:cadash
//SET: parentj
		DRIVER(parentj) //t:parentj f:taito_o.c r: c:
//SET: galmedes
		DRIVER(galmedes) //t:galmedes f:asuka.c r: c:
//SET: earthjkr
		DRIVER(earthjkr) //t:earthjkr f:asuka.c r: c:
//SET: eto
		DRIVER(eto) //t:eto f:asuka.c r: c:
//SET: wgp
		DRIVER(wgp) //t:wgp f:wgp.c r: c:
		DRIVER(wgpj) //t:wgpj f:wgp.c r:wgp c:wgp
		DRIVER(wgpjoy) //t:wgpjoy f:wgp.c r:wgp c:wgp
		DRIVER(wgpjoya) //t:wgpjoya f:wgp.c r:wgp c:wgp
		DRIVER(wgp2) //t:wgp2 f:wgp.c r:wgp c:wgp
//SET: galastrm
		DRIVER(galastrm) //t:galastrm f:galastrm.c r: c:
//SET: slapshot
		DRIVER(slapshot) //t:slapshot f:slapshot.c r: c:
//SET: opwolf3
		DRIVER(opwolf3) //t:opwolf3 f:slapshot.c r: c:
		DRIVER(opwolf3u) //t:opwolf3u f:slapshot.c r:opwolf3 c:opwolf3
//SET: scessjoe
		DRIVER(scessjoe) //t:scessjoe f:ashnojoe.c r: c:
		DRIVER(ashnojoe) //t:ashnojoe f:ashnojoe.c r:scessjoe c:scessjoe
//SET: ninjaw
		DRIVER(ninjaw) //t:ninjaw f:ninjaw.c r: c:
		DRIVER(ninjawj) //t:ninjawj f:ninjaw.c r:ninjaw c:ninjaw
//SET: darius2
		DRIVER(darius2) //t:darius2 f:ninjaw.c r: c:
		DRIVER(darius2d) //t:darius2d f:warriorb.c r:darius2 c:darius2
		DRIVER(darius2do) //t:darius2do f:warriorb.c r:darius2 c:darius2
//SET: warriorb
		DRIVER(warriorb) //t:warriorb f:warriorb.c r: c:
//SET: superman
		DRIVER(superman) //t:superman f:taito_x.c r: c:
		DRIVER(supermanj) //t:supermanj f:taito_x.c r:superman c:superman
//SET: twinhawk
		DRIVER(twinhawk) //t:twinhawk f:taito_x.c r: c:
		DRIVER(twinhawku) //t:twinhawku f:taito_x.c r:twinhawk c:twinhawk
		DRIVER(daisenpu) //t:daisenpu f:taito_x.c r:twinhawk c:twinhawk
//SET: gigandes
		DRIVER(gigandes) //t:gigandes f:taito_x.c r: c:
		DRIVER(gigandesj) //t:gigandesj f:taito_x.c r:gigandes c:gigandes
//SET: kyustrkr
		DRIVER(kyustrkr) //t:kyustrkr f:taito_x.c r: c:
//SET: ballbros
		DRIVER(ballbros) //t:ballbros f:taito_x.c r: c:
//SET: plumppop
		DRIVER(plumppop) //t:plumppop f:tnzs.c r: c:
//SET: jpopnics
		DRIVER(jpopnics) //t:jpopnics f:tnzs.c r: c:
//SET: extrmatn
		DRIVER(extrmatn) //t:extrmatn f:tnzs.c r: c:
		DRIVER(extrmatnu) //t:extrmatnu f:tnzs.c r:extrmatn c:extrmatn
		DRIVER(extrmatnj) //t:extrmatnj f:tnzs.c r:extrmatn c:extrmatn
//SET: arknoid2
		DRIVER(arknoid2) //t:arknoid2 f:tnzs.c r: c:
		DRIVER(arknoid2u) //t:arknoid2u f:tnzs.c r:arknoid2 c:arknoid2
		DRIVER(arknoid2j) //t:arknoid2j f:tnzs.c r:arknoid2 c:arknoid2
//SET: drtoppel
		DRIVER(drtoppel) //t:drtoppel f:tnzs.c r: c:
		DRIVER(drtoppelu) //t:drtoppelu f:tnzs.c r:drtoppel c:drtoppel
		DRIVER(drtoppelj) //t:drtoppelj f:tnzs.c r:drtoppel c:drtoppel
//SET: kageki
		DRIVER(kageki) //t:kageki f:tnzs.c r: c:
		DRIVER(kagekij) //t:kagekij f:tnzs.c r:kageki c:kageki
		DRIVER(kagekih) //t:kagekih f:tnzs.c r:kageki c:kageki
//SET: chukatai
		DRIVER(chukatai) //t:chukatai f:tnzs.c r: c:
		DRIVER(chukataiu) //t:chukataiu f:tnzs.c r:chukatai c:chukatai
		DRIVER(chukataij) //t:chukataij f:tnzs.c r:chukatai c:chukatai
//SET: kabukiz
		DRIVER(kabukiz) //t:kabukiz f:tnzs.c r: c:
		DRIVER(kabukizj) //t:kabukizj f:tnzs.c r:kabukiz c:kabukiz
//SET: tnzs
		DRIVER(tnzs) //t:tnzs f:tnzs.c r: c:
		DRIVER(tnzsj) //t:tnzsj f:tnzs.c r:tnzs c:tnzs
		DRIVER(tnzsjo) //t:tnzsjo f:tnzs.c r:tnzs c:tnzs
		DRIVER(tnzso) //t:tnzso f:tnzs.c r:tnzs c:tnzs
		DRIVER(tnzsop) //t:tnzsop f:tnzs.c r:tnzs c:tnzs
//SET: insectx
		DRIVER(insectx) //t:insectx f:tnzs.c r: c:
		DRIVER(insectxj) //t:insectxj f:tnzs.c r:insectx c:insectx
//SET: cchance
		DRIVER(cchance) //t:cchance f:cchance.c r: c:
//SET: champbwl
		DRIVER(champbwl) //t:champbwl f:champbwl.c r: c:
//SET: raimais
		DRIVER(raimais) //t:raimais f:taito_l.c r: c:
		DRIVER(raimaisj) //t:raimaisj f:taito_l.c r:raimais c:raimais
		DRIVER(raimaisjo) //t:raimaisjo f:taito_l.c r:raimais c:raimais
//SET: kurikint
		DRIVER(kurikint) //t:kurikint f:taito_l.c r: c:
		DRIVER(kurikintu) //t:kurikintu f:taito_l.c r:kurikint c:kurikint
		DRIVER(kurikintj) //t:kurikintj f:taito_l.c r:kurikint c:kurikint
		DRIVER(kurikinta) //t:kurikinta f:taito_l.c r:kurikint c:kurikint
//SET: evilston
		DRIVER(evilston) //t:evilston f:taito_l.c r: c:
//SET: fhawk
		DRIVER(fhawk) //t:fhawk f:taito_l.c r: c:
		DRIVER(fhawkj) //t:fhawkj f:taito_l.c r:fhawk c:fhawk
//SET: plotting
		DRIVER(plotting) //t:plotting f:taito_l.c r: c:
		DRIVER(plottingu) //t:plottingu f:taito_l.c r:plotting c:plotting
		DRIVER(plottinga) //t:plottinga f:taito_l.c r:plotting c:plotting
		DRIVER(plottingb) //t:plottingb f:taito_l.c r:plotting c:plotting
		DRIVER(flipull) //t:flipull f:taito_l.c r:plotting c:plotting
//SET: champwr
		DRIVER(champwr) //t:champwr f:taito_l.c r: c:
		DRIVER(champwru) //t:champwru f:taito_l.c r:champwr c:champwr
		DRIVER(champwrj) //t:champwrj f:taito_l.c r:champwr c:champwr
//SET: puzznic
		DRIVER(puzznic) //t:puzznic f:taito_l.c r: c:
		DRIVER(puzznicj) //t:puzznicj f:taito_l.c r:puzznic c:puzznic
		DRIVER(puzznici) //t:puzznici f:taito_l.c r:puzznic c:puzznic
//SET: horshoes
		DRIVER(horshoes) //t:horshoes f:taito_l.c r: c:
//SET: palamed
		DRIVER(palamed) //t:palamed f:taito_l.c r: c:
//SET: cachat
		DRIVER(cachat) //t:cachat f:taito_l.c r: c:
		DRIVER(tubeit) //t:tubeit f:taito_l.c r:cachat c:cachat
//SET: cubybop
		DRIVER(cubybop) //t:cubybop f:taito_l.c r: c:
//SET: plgirls
		DRIVER(plgirls) //t:plgirls f:taito_l.c r: c:
		DRIVER(lagirl) //t:lagirl f:taito_l.c r:plgirls c:plgirls
//SET: plgirls2
		DRIVER(plgirls2) //t:plgirls2 f:taito_l.c r: c:
//SET: syvalion
		DRIVER(syvalion) //t:syvalion f:taito_h.c r: c:
//SET: recordbr
		DRIVER(recordbr) //t:recordbr f:taito_h.c r: c:
		DRIVER(gogold) //t:gogold f:taito_h.c r:recordbr c:recordbr
//SET: dleague
		DRIVER(dleague) //t:dleague f:taito_h.c r: c:
//SET: masterw
		DRIVER(masterw) //t:masterw f:taito_b.c r: c:
		DRIVER(masterwu) //t:masterwu f:taito_b.c r:masterw c:masterw
		DRIVER(masterwj) //t:masterwj f:taito_b.c r:masterw c:masterw
//SET: nastar
		DRIVER(nastar) //t:nastar f:taito_b.c r: c:
		DRIVER(nastarw) //t:nastarw f:taito_b.c r:nastar c:nastar
		DRIVER(rastsag2) //t:rastsag2 f:taito_b.c r:nastar c:nastar
//SET: rambo3
		DRIVER(rambo3) //t:rambo3 f:taito_b.c r: c:
		DRIVER(rambo3ae) //t:rambo3ae f:taito_b.c r:rambo3 c:rambo3
		DRIVER(rambo3a) //t:rambo3a f:taito_b.c r:rambo3 c:rambo3
//SET: crimec
		DRIVER(crimec) //t:crimec f:taito_b.c r: c:
		DRIVER(crimecu) //t:crimecu f:taito_b.c r:crimec c:crimec
		DRIVER(crimecj) //t:crimecj f:taito_b.c r:crimec c:crimec
//SET: viofight
		DRIVER(viofight) //t:viofight f:taito_b.c r: c:
		DRIVER(viofightu) //t:viofightu f:taito_b.c r:viofight c:viofight
		DRIVER(viofightj) //t:viofightj f:taito_b.c r:viofight c:viofight
//SET: ashura
		DRIVER(ashura) //t:ashura f:taito_b.c r: c:
		DRIVER(ashuraj) //t:ashuraj f:taito_b.c r:ashura c:ashura
		DRIVER(ashurau) //t:ashurau f:taito_b.c r:ashura c:ashura
//SET: hitice
		DRIVER(hitice) //t:hitice f:taito_b.c r: c:
		DRIVER(hiticej) //t:hiticej f:taito_b.c r:hitice c:hitice
//SET: sbm
		DRIVER(sbm) //t:sbm f:taito_b.c r: c:
//SET: selfeena
		DRIVER(selfeena) //t:selfeena f:taito_b.c r: c:
//SET: silentd
		DRIVER(silentd) //t:silentd f:taito_b.c r: c:
		DRIVER(silentdu) //t:silentdu f:taito_b.c r:silentd c:silentd
		DRIVER(silentdj) //t:silentdj f:taito_b.c r:silentd c:silentd
//SET: ryujin
		DRIVER(ryujin) //t:ryujin f:taito_b.c r: c:
//SET: qzshowby
		DRIVER(qzshowby) //t:qzshowby f:taito_b.c r: c:
//SET: pbobble
		DRIVER(pbobble) //t:pbobble f:taito_b.c r: c:
//SET: spacedx
		DRIVER(spacedx) //t:spacedx f:taito_b.c r: c:
		DRIVER(spacedxj) //t:spacedxj f:taito_b.c r:spacedx c:spacedx
		DRIVER(spacedxo) //t:spacedxo f:taito_b.c r:spacedx c:spacedx
		DRIVER(spcinvdj) //t:spcinvdj f:taito_f3.c r:spacedx c:spacedx
//SET: contcirc
		DRIVER(contcirc) //t:contcirc f:taito_z.c r: c:
		DRIVER(contcircu) //t:contcircu f:taito_z.c r:contcirc c:contcirc
		DRIVER(contcircua) //t:contcircua f:taito_z.c r:contcirc c:contcirc
//SET: chasehq
		DRIVER(chasehq) //t:chasehq f:taito_z.c r: c:
		DRIVER(chasehqj) //t:chasehqj f:taito_z.c r:chasehq c:chasehq
		DRIVER(chasehqu) //t:chasehqu f:taito_z.c r:chasehq c:chasehq
//SET: enforce
		DRIVER(enforce) //t:enforce f:taito_z.c r: c:
//SET: nightstr
		DRIVER(nightstr) //t:nightstr f:taito_z.c r: c:
		DRIVER(nightstrj) //t:nightstrj f:taito_z.c r:nightstr c:nightstr
		DRIVER(nightstru) //t:nightstru f:taito_z.c r:nightstr c:nightstr
//SET: sci
		DRIVER(sci) //t:sci f:taito_z.c r: c:
		DRIVER(scia) //t:scia f:taito_z.c r:sci c:sci
		DRIVER(scij) //t:scij f:taito_z.c r:sci c:sci
		DRIVER(sciu) //t:sciu f:taito_z.c r:sci c:sci
		DRIVER(scin) //t:scin f:taito_z.c r:sci c:sci
//SET: bshark
		DRIVER(bshark) //t:bshark f:taito_z.c r: c:
		DRIVER(bsharkj) //t:bsharkj f:taito_z.c r:bshark c:bshark
//SET: aquajack
		DRIVER(aquajack) //t:aquajack f:taito_z.c r: c:
		DRIVER(aquajackj) //t:aquajackj f:taito_z.c r:aquajack c:aquajack
//SET: spacegun
		DRIVER(spacegun) //t:spacegun f:taito_z.c r: c:
//SET: dblaxle
		DRIVER(dblaxle) //t:dblaxle f:taito_z.c r: c:
		DRIVER(pwheelsj) //t:pwheelsj f:taito_z.c r:dblaxle c:dblaxle
//SET: racingb
		DRIVER(racingb) //t:racingb f:taito_z.c r: c:
//SET: topland
		DRIVER(topland) //t:topland f:taitoair.c r: c:
//SET: ainferno
		DRIVER(ainferno) //t:ainferno f:taitoair.c r: c:
//SET: mlanding
		DRIVER(mlanding) //t:mlanding f:mlanding.c r: c:
//SET: gunbustr
		DRIVER(gunbustr) //t:gunbustr f:gunbustr.c r: c:
//SET: superchs
		DRIVER(superchs) //t:superchs f:superchs.c r: c:
//SET: groundfx
		DRIVER(groundfx) //t:groundfx f:groundfx.c r: c:
//SET: undrfire
		DRIVER(undrfire) //t:undrfire f:undrfire.c r: c:
		DRIVER(undrfireu) //t:undrfireu f:undrfire.c r:undrfire c:undrfire
		DRIVER(undrfirej) //t:undrfirej f:undrfire.c r:undrfire c:undrfire
//SET: cbombers
		DRIVER(cbombers) //t:cbombers f:undrfire.c r: c:
//SET: finalb
		DRIVER(finalb) //t:finalb f:taito_f2.c r: c:
		DRIVER(finalbj) //t:finalbj f:taito_f2.c r:finalb c:finalb
		DRIVER(finalbu) //t:finalbu f:taito_f2.c r:finalb c:finalb
//SET: dondokod
		DRIVER(dondokod) //t:dondokod f:taito_f2.c r: c:
		DRIVER(dondokodu) //t:dondokodu f:taito_f2.c r:dondokod c:dondokod
		DRIVER(dondokodj) //t:dondokodj f:taito_f2.c r:dondokod c:dondokod
//SET: megablst
		DRIVER(megablst) //t:megablst f:taito_f2.c r: c:
		DRIVER(megablstu) //t:megablstu f:taito_f2.c r:megablst c:megablst
		DRIVER(megablstj) //t:megablstj f:taito_f2.c r:megablst c:megablst
//SET: thundfox
		DRIVER(thundfox) //t:thundfox f:taito_f2.c r: c:
		DRIVER(thundfoxu) //t:thundfoxu f:taito_f2.c r:thundfox c:thundfox
		DRIVER(thundfoxj) //t:thundfoxj f:taito_f2.c r:thundfox c:thundfox
//SET: cameltry
		DRIVER(cameltry) //t:cameltry f:taito_f2.c r: c:
		DRIVER(cameltrya) //t:cameltrya f:taito_f2.c r:cameltry c:cameltry
		DRIVER(cameltryau) //t:cameltryau f:taito_f2.c r:cameltry c:cameltry
		DRIVER(cameltryj) //t:cameltryj f:taito_f2.c r:cameltry c:cameltry
//SET: qtorimon
		DRIVER(qtorimon) //t:qtorimon f:taito_f2.c r: c:
//SET: liquidk
		DRIVER(liquidk) //t:liquidk f:taito_f2.c r: c:
		DRIVER(liquidku) //t:liquidku f:taito_f2.c r:liquidk c:liquidk
		DRIVER(mizubaku) //t:mizubaku f:taito_f2.c r:liquidk c:liquidk
//SET: quizhq
		DRIVER(quizhq) //t:quizhq f:taito_f2.c r: c:
//SET: ssi
		DRIVER(ssi) //t:ssi f:taito_f2.c r: c:
		DRIVER(ssia) //t:ssia f:taito_f2.c r:ssi c:ssi
		DRIVER(majest12) //t:majest12 f:taito_f2.c r:ssi c:ssi
//SET: gunfront
		DRIVER(gunfront) //t:gunfront f:taito_f2.c r: c:
		DRIVER(gunfrontj) //t:gunfrontj f:taito_f2.c r:gunfront c:gunfront
//SET: growl
		DRIVER(growl) //t:growl f:taito_f2.c r: c:
		DRIVER(growlu) //t:growlu f:taito_f2.c r:growl c:growl
		DRIVER(runark) //t:runark f:taito_f2.c r:growl c:growl
//SET: mjnquest
		DRIVER(mjnquest) //t:mjnquest f:taito_f2.c r: c:
		DRIVER(mjnquestb) //t:mjnquestb f:taito_f2.c r:mjnquest c:mjnquest
//SET: footchmp
		DRIVER(footchmp) //t:footchmp f:taito_f2.c r: c:
		DRIVER(footchmpbl) //t:footchmpbl f:taito_f2.c r:footchmp c:footchmp
		DRIVER(hthero) //t:hthero f:taito_f2.c r:footchmp c:footchmp
		DRIVER(euroch92) //t:euroch92 f:taito_f2.c r:footchmp c:footchmp
//SET: koshien
		DRIVER(koshien) //t:koshien f:taito_f2.c r: c:
//SET: yuyugogo
		DRIVER(yuyugogo) //t:yuyugogo f:taito_f2.c r: c:
//SET: ninjak
		DRIVER(ninjak) //t:ninjak f:taito_f2.c r: c:
		DRIVER(ninjakj) //t:ninjakj f:taito_f2.c r:ninjak c:ninjak
		DRIVER(ninjaku) //t:ninjaku f:taito_f2.c r:ninjak c:ninjak
//SET: solfigtr
		DRIVER(solfigtr) //t:solfigtr f:taito_f2.c r: c:
//SET: qzquest
		DRIVER(qzquest) //t:qzquest f:taito_f2.c r: c:
//SET: pulirula
		DRIVER(pulirula) //t:pulirula f:taito_f2.c r: c:
		DRIVER(pulirulaj) //t:pulirulaj f:taito_f2.c r:pulirula c:pulirula
//SET: metalb
		DRIVER(metalb) //t:metalb f:taito_f2.c r: c:
		DRIVER(metalbj) //t:metalbj f:taito_f2.c r:metalb c:metalb
//SET: qzchikyu
		DRIVER(qzchikyu) //t:qzchikyu f:taito_f2.c r: c:
//SET: yesnoj
		DRIVER(yesnoj) //t:yesnoj f:taito_f2.c r: c:
//SET: deadconx
		DRIVER(deadconx) //t:deadconx f:taito_f2.c r: c:
		DRIVER(deadconxj) //t:deadconxj f:taito_f2.c r:deadconx c:deadconx
//SET: dinorex
		DRIVER(dinorex) //t:dinorex f:taito_f2.c r: c:
		DRIVER(dinorexj) //t:dinorexj f:taito_f2.c r:dinorex c:dinorex
		DRIVER(dinorexu) //t:dinorexu f:taito_f2.c r:dinorex c:dinorex
//SET: qjinsei
		DRIVER(qjinsei) //t:qjinsei f:taito_f2.c r: c:
//SET: qcrayon
		DRIVER(qcrayon) //t:qcrayon f:taito_f2.c r: c:
//SET: qcrayon2
		DRIVER(qcrayon2) //t:qcrayon2 f:taito_f2.c r: c:
//SET: driftout
		DRIVER(driftout) //t:driftout f:taito_f2.c r: c:
		DRIVER(driveout) //t:driveout f:taito_f2.c r:driftout c:driftout
//SET: ringrage
		DRIVER(ringrage) //t:ringrage f:taito_f3.c r: c:
		DRIVER(ringragej) //t:ringragej f:taito_f3.c r:ringrage c:ringrage
		DRIVER(ringrageu) //t:ringrageu f:taito_f3.c r:ringrage c:ringrage
//SET: arabianm
		DRIVER(arabianm) //t:arabianm f:taito_f3.c r: c:
		DRIVER(arabianmj) //t:arabianmj f:taito_f3.c r:arabianm c:arabianm
		DRIVER(arabianmu) //t:arabianmu f:taito_f3.c r:arabianm c:arabianm
//SET: ridingf
		DRIVER(ridingf) //t:ridingf f:taito_f3.c r: c:
		DRIVER(ridingfj) //t:ridingfj f:taito_f3.c r:ridingf c:ridingf
		DRIVER(ridingfu) //t:ridingfu f:taito_f3.c r:ridingf c:ridingf
//SET: gseeker
		DRIVER(gseeker) //t:gseeker f:taito_f3.c r: c:
		DRIVER(gseekerj) //t:gseekerj f:taito_f3.c r:gseeker c:gseeker
		DRIVER(gseekeru) //t:gseekeru f:taito_f3.c r:gseeker c:gseeker
//SET: cupfinal
		DRIVER(cupfinal) //t:cupfinal f:taito_f3.c r: c:
		DRIVER(hthero93) //t:hthero93 f:taito_f3.c r:cupfinal c:cupfinal
//SET: trstar
		DRIVER(trstar) //t:trstar f:taito_f3.c r: c:
		DRIVER(trstarj) //t:trstarj f:taito_f3.c r:trstar c:trstar
		DRIVER(prmtmfgt) //t:prmtmfgt f:taito_f3.c r:trstar c:trstar
		DRIVER(prmtmfgto) //t:prmtmfgto f:taito_f3.c r:trstar c:trstar
		DRIVER(trstaro) //t:trstaro f:taito_f3.c r:trstar c:trstar
		DRIVER(trstaroj) //t:trstaroj f:taito_f3.c r:trstar c:trstar
//SET: gunlock
		DRIVER(gunlock) //t:gunlock f:taito_f3.c r: c:
		DRIVER(rayforcej) //t:rayforcej f:taito_f3.c r:gunlock c:gunlock
		DRIVER(rayforce) //t:rayforce f:taito_f3.c r:gunlock c:gunlock
//SET: scfinals
		DRIVER(scfinals) //t:scfinals f:taito_f3.c r: c:
//SET: intcup94
		DRIVER(intcup94) //t:intcup94 f:taito_f3.c r: c:
		DRIVER(hthero94) //t:hthero94 f:taito_f3.c r:intcup94 c:intcup94
//SET: lightbr
		DRIVER(lightbr) //t:lightbr f:taito_f3.c r: c:
		DRIVER(lightbrj) //t:lightbrj f:taito_f3.c r:lightbr c:lightbr
		DRIVER(dungeonm) //t:dungeonm f:taito_f3.c r:lightbr c:lightbr
		DRIVER(dungeonmu) //t:dungeonmu f:taito_f3.c r:lightbr c:lightbr
//SET: kaiserkn
		DRIVER(kaiserkn) //t:kaiserkn f:taito_f3.c r: c:
		DRIVER(kaiserknj) //t:kaiserknj f:taito_f3.c r:kaiserkn c:kaiserkn
		DRIVER(gblchmp) //t:gblchmp f:taito_f3.c r:kaiserkn c:kaiserkn
		DRIVER(dankuga) //t:dankuga f:taito_f3.c r:kaiserkn c:kaiserkn
//SET: dariusg
		DRIVER(dariusg) //t:dariusg f:taito_f3.c r: c:
		DRIVER(dariusgj) //t:dariusgj f:taito_f3.c r:dariusg c:dariusg
		DRIVER(dariusgu) //t:dariusgu f:taito_f3.c r:dariusg c:dariusg
		DRIVER(dariusgx) //t:dariusgx f:taito_f3.c r:dariusg c:dariusg
//SET: bublbob2
		DRIVER(bublbob2) //t:bublbob2 f:taito_f3.c r: c:
		DRIVER(bubsymphe) //t:bubsymphe f:taito_f3.c r:bublbob2 c:bublbob2
		DRIVER(bubsymphu) //t:bubsymphu f:taito_f3.c r:bublbob2 c:bublbob2
		DRIVER(bubsymphj) //t:bubsymphj f:taito_f3.c r:bublbob2 c:bublbob2
		DRIVER(bubsymphb) //t:bubsymphb f:taito_f3.c r:bublbob2 c:bublbob2
//SET: pwrgoal
		DRIVER(pwrgoal) //t:pwrgoal f:taito_f3.c r: c:
		DRIVER(hthero95) //t:hthero95 f:taito_f3.c r:pwrgoal c:pwrgoal
		DRIVER(hthero95u) //t:hthero95u f:taito_f3.c r:pwrgoal c:pwrgoal
//SET: qtheater
		DRIVER(qtheater) //t:qtheater f:taito_f3.c r: c:
//SET: elvactr
		DRIVER(elvactr) //t:elvactr f:taito_f3.c r: c:
		DRIVER(elvactrj) //t:elvactrj f:taito_f3.c r:elvactr c:elvactr
		DRIVER(elvact2u) //t:elvact2u f:taito_f3.c r:elvactr c:elvactr
//SET: spcinv95
		DRIVER(spcinv95) //t:spcinv95 f:taito_f3.c r: c:
		DRIVER(spcinv95u) //t:spcinv95u f:taito_f3.c r:spcinv95 c:spcinv95
		DRIVER(akkanvdr) //t:akkanvdr f:taito_f3.c r:spcinv95 c:spcinv95
//SET: twinqix
		DRIVER(twinqix) //t:twinqix f:taito_f3.c r: c:
//SET: quizhuhu
		DRIVER(quizhuhu) //t:quizhuhu f:taito_f3.c r: c:
//SET: pbobble2
		DRIVER(pbobble2) //t:pbobble2 f:taito_f3.c r: c:
		DRIVER(pbobble2o) //t:pbobble2o f:taito_f3.c r:pbobble2 c:pbobble2
		DRIVER(pbobble2j) //t:pbobble2j f:taito_f3.c r:pbobble2 c:pbobble2
		DRIVER(pbobble2u) //t:pbobble2u f:taito_f3.c r:pbobble2 c:pbobble2
		DRIVER(pbobble2x) //t:pbobble2x f:taito_f3.c r:pbobble2 c:pbobble2
//SET: gekiridn
		DRIVER(gekiridn) //t:gekiridn f:taito_f3.c r: c:
		DRIVER(gekiridnj) //t:gekiridnj f:taito_f3.c r:gekiridn c:gekiridn
//SET: tcobra2
		DRIVER(tcobra2) //t:tcobra2 f:taito_f3.c r: c:
		DRIVER(tcobra2u) //t:tcobra2u f:taito_f3.c r:tcobra2 c:tcobra2
		DRIVER(ktiger2) //t:ktiger2 f:taito_f3.c r:tcobra2 c:tcobra2
//SET: bubblem
		DRIVER(bubblem) //t:bubblem f:taito_f3.c r: c:
		DRIVER(bubblemj) //t:bubblemj f:taito_f3.c r:bubblem c:bubblem
//SET: cleopatr
		DRIVER(cleopatr) //t:cleopatr f:taito_f3.c r: c:
//SET: pbobble3
		DRIVER(pbobble3) //t:pbobble3 f:taito_f3.c r: c:
		DRIVER(pbobble3u) //t:pbobble3u f:taito_f3.c r:pbobble3 c:pbobble3
		DRIVER(pbobble3j) //t:pbobble3j f:taito_f3.c r:pbobble3 c:pbobble3
//SET: arkretrn
		DRIVER(arkretrn) //t:arkretrn f:taito_f3.c r: c:
//SET: kirameki
		DRIVER(kirameki) //t:kirameki f:taito_f3.c r: c:
//SET: puchicar
		DRIVER(puchicar) //t:puchicar f:taito_f3.c r: c:
		DRIVER(puchicarj) //t:puchicarj f:taito_f3.c r:puchicar c:puchicar
//SET: pbobble4
		DRIVER(pbobble4) //t:pbobble4 f:taito_f3.c r: c:
		DRIVER(pbobble4j) //t:pbobble4j f:taito_f3.c r:pbobble4 c:pbobble4
		DRIVER(pbobble4u) //t:pbobble4u f:taito_f3.c r:pbobble4 c:pbobble4
//SET: popnpop
		DRIVER(popnpop) //t:popnpop f:taito_f3.c r: c:
		DRIVER(popnpopj) //t:popnpopj f:taito_f3.c r:popnpop c:popnpop
		DRIVER(popnpopu) //t:popnpopu f:taito_f3.c r:popnpop c:popnpop
//SET: landmakr
		DRIVER(landmakr) //t:landmakr f:taito_f3.c r: c:
		DRIVER(landmakrp) //t:landmakrp f:taito_f3.c r:landmakr c:landmakr
//SET: recalh
		DRIVER(recalh) //t:recalh f:taito_f3.c r: c:
//SET: commandw
		DRIVER(commandw) //t:commandw f:taito_f3.c r: c:
//SET: dangcurv
		DRIVER(dangcurv) //t:dangcurv f:taitojc.c r: c:
//SET: landgear
		DRIVER(landgear) //t:landgear f:taitojc.c r: c:
//SET: sidebs
		DRIVER(sidebs) //t:sidebs f:taitojc.c r: c:
//SET: dendeg
		DRIVER(dendeg) //t:dendeg f:taitojc.c r: c:
		DRIVER(dendegx) //t:dendegx f:taitojc.c r:dendeg c:dendeg
//SET: sidebs2
		DRIVER(sidebs2) //t:sidebs2 f:taitojc.c r: c:
		DRIVER(sidebs2j) //t:sidebs2j f:taitojc.c r:sidebs2 c:sidebs2
//SET: dendeg2
		DRIVER(dendeg2) //t:dendeg2 f:taitojc.c r: c:
		DRIVER(dendeg2x) //t:dendeg2x f:taitojc.c r:dendeg2 c:dendeg2
//SET: pf2012
		DRIVER(pf2012) //t:pf2012 f:taitowlf.c r: c:
//SET: optiger
		DRIVER(optiger) //t:optiger f:taitopjc.c r: c:
//SET: taitotz
		DRIVER(taitotz) //t:taitotz f:taitotz.c r: c:
//SET: batlgear
		DRIVER(batlgear) //t:batlgear f:taitotz.c r:taitotz c:
//SET: landhigh
		DRIVER(landhigh) //t:landhigh f:taitotz.c r:taitotz c:
//SET: batlgr2
		DRIVER(batlgr2) //t:batlgr2 f:taitotz.c r:taitotz c:
//SET: perfrman
		DRIVER(perfrman) //t:perfrman f:slapfght.c r: c:
		DRIVER(perfrmanu) //t:perfrmanu f:slapfght.c r:perfrman c:perfrman
//SET: tigerh
		DRIVER(tigerh) //t:tigerh f:slapfght.c r: c:
		DRIVER(tigerhj) //t:tigerhj f:slapfght.c r:tigerh c:tigerh
		DRIVER(tigerhb1) //t:tigerhb1 f:slapfght.c r:tigerh c:tigerh
		DRIVER(tigerhb2) //t:tigerhb2 f:slapfght.c r:tigerh c:tigerh
		DRIVER(tigerhb3) //t:tigerhb3 f:slapfght.c r:tigerh c:tigerh
//SET: alcon
		DRIVER(alcon) //t:alcon f:slapfght.c r: c:
		DRIVER(slapfigh) //t:slapfigh f:slapfght.c r:alcon c:alcon
		DRIVER(slapfigha) //t:slapfigha f:slapfght.c r:alcon c:alcon
		DRIVER(slapfighb1) //t:slapfighb1 f:slapfght.c r:alcon c:alcon
		DRIVER(slapfighb2) //t:slapfighb2 f:slapfght.c r:alcon c:alcon
		DRIVER(slapfighb3) //t:slapfighb3 f:slapfght.c r:alcon c:alcon
//SET: getstar
		DRIVER(getstar) //t:getstar f:slapfght.c r: c:
		DRIVER(getstarj) //t:getstarj f:slapfght.c r:getstar c:getstar
		DRIVER(gtstarb1) //t:gtstarb1 f:slapfght.c r:getstar c:getstar
		DRIVER(gtstarb2) //t:gtstarb2 f:slapfght.c r:getstar c:getstar
//SET: mjsister
		DRIVER(mjsister) //t:mjsister f:mjsister.c r: c:
//SET: fshark
		DRIVER(fshark) //t:fshark f:twincobr.c r: c:
		DRIVER(skyshark) //t:skyshark f:twincobr.c r:fshark c:fshark
		DRIVER(hishouza) //t:hishouza f:twincobr.c r:fshark c:fshark
		DRIVER(fsharkbt) //t:fsharkbt f:twincobr.c r:fshark c:fshark
//SET: wardner
		DRIVER(wardner) //t:wardner f:wardner.c r: c:
		DRIVER(pyros) //t:pyros f:wardner.c r:wardner c:wardner
		DRIVER(wardnerj) //t:wardnerj f:wardner.c r:wardner c:wardner
//SET: twincobr
		DRIVER(twincobr) //t:twincobr f:twincobr.c r: c:
		DRIVER(twincobru) //t:twincobru f:twincobr.c r:twincobr c:twincobr
		DRIVER(ktiger) //t:ktiger f:twincobr.c r:twincobr c:twincobr
//SET: gulfwar2
		DRIVER(gulfwar2) //t:gulfwar2 f:twincobr.c r: c:
//SET: rallybik
		DRIVER(rallybik) //t:rallybik f:toaplan1.c r: c:
//SET: truxton
		DRIVER(truxton) //t:truxton f:toaplan1.c r: c:
//SET: hellfire
		DRIVER(hellfire) //t:hellfire f:toaplan1.c r: c:
		DRIVER(hellfire1) //t:hellfire1 f:toaplan1.c r:hellfire c:hellfire
		DRIVER(hellfire2) //t:hellfire2 f:toaplan1.c r:hellfire c:hellfire
		DRIVER(hellfire3) //t:hellfire3 f:toaplan1.c r:hellfire c:hellfire
//SET: zerowing
		DRIVER(zerowing) //t:zerowing f:toaplan1.c r: c:
		DRIVER(zerowing2) //t:zerowing2 f:toaplan1.c r:zerowing c:zerowing
//SET: demonwld
		DRIVER(demonwld) //t:demonwld f:toaplan1.c r: c:
		DRIVER(demonwld1) //t:demonwld1 f:toaplan1.c r:demonwld c:demonwld
		DRIVER(demonwld2) //t:demonwld2 f:toaplan1.c r:demonwld c:demonwld
		DRIVER(demonwld3) //t:demonwld3 f:toaplan1.c r:demonwld c:demonwld
		DRIVER(demonwld4) //t:demonwld4 f:toaplan1.c r:demonwld c:demonwld
//SET: fireshrk
		DRIVER(fireshrk) //t:fireshrk f:toaplan1.c r: c:
		DRIVER(fireshrkd) //t:fireshrkd f:toaplan1.c r:fireshrk c:fireshrk
		DRIVER(fireshrkdh) //t:fireshrkdh f:toaplan1.c r:fireshrk c:fireshrk
		DRIVER(samesame) //t:samesame f:toaplan1.c r:fireshrk c:fireshrk
		DRIVER(samesame2) //t:samesame2 f:toaplan1.c r:fireshrk c:fireshrk
//SET: outzone
		DRIVER(outzone) //t:outzone f:toaplan1.c r: c:
		DRIVER(outzonea) //t:outzonea f:toaplan1.c r:outzone c:outzone
		DRIVER(outzoneb) //t:outzoneb f:toaplan1.c r:outzone c:outzone
		DRIVER(outzonec) //t:outzonec f:toaplan1.c r:outzone c:outzone
		DRIVER(outzoned) //t:outzoned f:toaplan1.c r:outzone c:outzone
//SET: vimana
		DRIVER(vimana) //t:vimana f:toaplan1.c r: c:
		DRIVER(vimana1) //t:vimana1 f:toaplan1.c r:vimana c:vimana
		DRIVER(vimanan) //t:vimanan f:toaplan1.c r:vimana c:vimana
//SET: snowbros
		DRIVER(snowbros) //t:snowbros f:snowbros.c r: c:
		DRIVER(snowbrosa) //t:snowbrosa f:snowbros.c r:snowbros c:snowbros
		DRIVER(snowbrosb) //t:snowbrosb f:snowbros.c r:snowbros c:snowbros
		DRIVER(snowbrosc) //t:snowbrosc f:snowbros.c r:snowbros c:snowbros
		DRIVER(snowbrosj) //t:snowbrosj f:snowbros.c r:snowbros c:snowbros
		DRIVER(snowbrosd) //t:snowbrosd f:snowbros.c r:snowbros c:snowbros
		DRIVER(wintbob) //t:wintbob f:snowbros.c r:snowbros c:snowbros
		DRIVER(snowbros3) //t:snowbros3 f:snowbros.c r:snowbros c:snowbros
//SET: honeydol
		DRIVER(honeydol) //t:honeydol f:snowbros.c r: c:
//SET: twinadv
		DRIVER(twinadv) //t:twinadv f:snowbros.c r: c:
		DRIVER(twinadvk) //t:twinadvk f:snowbros.c r:twinadv c:twinadv
//SET: hyperpac
		DRIVER(hyperpac) //t:hyperpac f:snowbros.c r: c:
		DRIVER(hyperpacb) //t:hyperpacb f:snowbros.c r:hyperpac c:hyperpac
//SET: toppyrap
		DRIVER(toppyrap) //t:toppyrap f:snowbros.c r: c:
//SET: cookbib2
		DRIVER(cookbib2) //t:cookbib2 f:snowbros.c r: c:
//SET: cookbib3
		DRIVER(cookbib3) //t:cookbib3 f:snowbros.c r: c:
//SET: twinkle
		DRIVER(twinkle) //t:twinkle f:snowbros.c r: c:
//SET: pzlbreak
		DRIVER(pzlbreak) //t:pzlbreak f:snowbros.c r: c:
//SET: 3in1semi
		DRIVER(3in1semi) //t:3in1semi f:snowbros.c r: c:
//SET: moremore
		DRIVER(moremore) //t:moremore f:snowbros.c r: c:
//SET: moremorp
		DRIVER(moremorp) //t:moremorp f:snowbros.c r: c:
//SET: 4in1boot
		DRIVER(4in1boot) //t:4in1boot f:snowbros.c r: c:
//SET: finalttr
		DRIVER(finalttr) //t:finalttr f:snowbros.c r: c:
//SET: tekipaki
		DRIVER(tekipaki) //t:tekipaki f:toaplan2.c r: c:
//SET: ghox
		DRIVER(ghox) //t:ghox f:toaplan2.c r: c:
		DRIVER(ghoxj) //t:ghoxj f:toaplan2.c r:ghox c:ghox
//SET: dogyuun
		DRIVER(dogyuun) //t:dogyuun f:toaplan2.c r: c:
		DRIVER(dogyuuna) //t:dogyuuna f:toaplan2.c r:dogyuun c:dogyuun
		DRIVER(dogyuunt) //t:dogyuunt f:toaplan2.c r:dogyuun c:dogyuun
//SET: kbash
		DRIVER(kbash) //t:kbash f:toaplan2.c r: c:
//SET: kbash2
		DRIVER(kbash2) //t:kbash2 f:toaplan2.c r: c:
//SET: truxton2
		DRIVER(truxton2) //t:truxton2 f:toaplan2.c r: c:
//SET: pipibibs
		DRIVER(pipibibs) //t:pipibibs f:toaplan2.c r: c:
		DRIVER(pipibibsa) //t:pipibibsa f:toaplan2.c r:pipibibs c:pipibibs
		DRIVER(whoopee) //t:whoopee f:toaplan2.c r:pipibibs c:pipibibs
		DRIVER(pipibibsbl) //t:pipibibsbl f:toaplan2.c r:pipibibs c:pipibibs
//SET: fixeight
		DRIVER(fixeight) //t:fixeight f:toaplan2.c r: c:
		DRIVER(fixeightt) //t:fixeightt f:toaplan2.c r:fixeight c:fixeight
		DRIVER(fixeightkt) //t:fixeightkt f:toaplan2.c r:fixeight c:fixeight
		DRIVER(fixeightk) //t:fixeightk f:toaplan2.c r:fixeight c:fixeight
		DRIVER(fixeightht) //t:fixeightht f:toaplan2.c r:fixeight c:fixeight
		DRIVER(fixeighth) //t:fixeighth f:toaplan2.c r:fixeight c:fixeight
		DRIVER(fixeighttwt) //t:fixeighttwt f:toaplan2.c r:fixeight c:fixeight
		DRIVER(fixeighttw) //t:fixeighttw f:toaplan2.c r:fixeight c:fixeight
		DRIVER(fixeightat) //t:fixeightat f:toaplan2.c r:fixeight c:fixeight
		DRIVER(fixeighta) //t:fixeighta f:toaplan2.c r:fixeight c:fixeight
		DRIVER(fixeightu) //t:fixeightu f:toaplan2.c r:fixeight c:fixeight
		DRIVER(fixeightut) //t:fixeightut f:toaplan2.c r:fixeight c:fixeight
		DRIVER(fixeightj) //t:fixeightj f:toaplan2.c r:fixeight c:fixeight
		DRIVER(fixeightjt) //t:fixeightjt f:toaplan2.c r:fixeight c:fixeight
		DRIVER(fixeightbl) //t:fixeightbl f:toaplan2.c r:fixeight c:fixeight
//SET: grindstm
		DRIVER(grindstm) //t:grindstm f:toaplan2.c r: c:
		DRIVER(grindstma) //t:grindstma f:toaplan2.c r:grindstm c:grindstm
		DRIVER(vfive) //t:vfive f:toaplan2.c r:grindstm c:grindstm
//SET: batsugun
		DRIVER(batsugun) //t:batsugun f:toaplan2.c r: c:
		DRIVER(batsuguna) //t:batsuguna f:toaplan2.c r:batsugun c:batsugun
		DRIVER(batsugunsp) //t:batsugunsp f:toaplan2.c r:batsugun c:batsugun
//SET: snowbro2
		DRIVER(snowbro2) //t:snowbro2 f:toaplan2.c r: c:
//SET: sstriker
		DRIVER(sstriker) //t:sstriker f:toaplan2.c r: c:
		DRIVER(sstrikera) //t:sstrikera f:toaplan2.c r:sstriker c:sstriker
		DRIVER(mahoudai) //t:mahoudai f:toaplan2.c r:sstriker c:sstriker
//SET: kingdmgp
		DRIVER(kingdmgp) //t:kingdmgp f:toaplan2.c r: c:
		DRIVER(shippumd) //t:shippumd f:toaplan2.c r:kingdmgp c:kingdmgp
//SET: bgaregga
		DRIVER(bgaregga) //t:bgaregga f:toaplan2.c r: c:
		DRIVER(bgareggahk) //t:bgareggahk f:toaplan2.c r:bgaregga c:bgaregga
		DRIVER(bgareggatw) //t:bgareggatw f:toaplan2.c r:bgaregga c:bgaregga
		DRIVER(bgaregganv) //t:bgaregganv f:toaplan2.c r:bgaregga c:bgaregga
		DRIVER(bgareggat2) //t:bgareggat2 f:toaplan2.c r:bgaregga c:bgaregga
		DRIVER(bgareggacn) //t:bgareggacn f:toaplan2.c r:bgaregga c:bgaregga
//SET: batrider
		DRIVER(batrider) //t:batrider f:toaplan2.c r: c:
		DRIVER(batrideru) //t:batrideru f:toaplan2.c r:batrider c:batrider
		DRIVER(batriderc) //t:batriderc f:toaplan2.c r:batrider c:batrider
		DRIVER(batriderj) //t:batriderj f:toaplan2.c r:batrider c:batrider
		DRIVER(batriderk) //t:batriderk f:toaplan2.c r:batrider c:batrider
		DRIVER(batriderja) //t:batriderja f:toaplan2.c r:batrider c:batrider
		DRIVER(batridert) //t:batridert f:toaplan2.c r:batrider c:batrider
//SET: bbakraid
		DRIVER(bbakraid) //t:bbakraid f:toaplan2.c r: c:
		DRIVER(bbakraidj) //t:bbakraidj f:toaplan2.c r:bbakraid c:bbakraid
		DRIVER(bbakraidja) //t:bbakraidja f:toaplan2.c r:bbakraid c:bbakraid
//SET: pwrinst2
		DRIVER(pwrinst2) //t:pwrinst2 f:cave.c r: c:
		DRIVER(pwrinst2j) //t:pwrinst2j f:cave.c r:pwrinst2 c:pwrinst2
//SET: plegends
		DRIVER(plegends) //t:plegends f:cave.c r: c:
		DRIVER(plegendsj) //t:plegendsj f:cave.c r:plegends c:plegends
//SET: mazinger
		DRIVER(mazinger) //t:mazinger f:cave.c r: c:
		DRIVER(mazingerj) //t:mazingerj f:cave.c r:mazinger c:mazinger
//SET: donpachi
		DRIVER(donpachi) //t:donpachi f:cave.c r: c:
		DRIVER(donpachij) //t:donpachij f:cave.c r:donpachi c:donpachi
		DRIVER(donpachikr) //t:donpachikr f:cave.c r:donpachi c:donpachi
		DRIVER(donpachihk) //t:donpachihk f:cave.c r:donpachi c:donpachi
//SET: metmqstr
		DRIVER(metmqstr) //t:metmqstr f:cave.c r: c:
		DRIVER(nmaster) //t:nmaster f:cave.c r:metmqstr c:metmqstr
//SET: sailormn
		DRIVER(sailormn) //t:sailormn f:cave.c r: c:
		DRIVER(sailormnu) //t:sailormnu f:cave.c r:sailormn c:sailormn
		DRIVER(sailormnj) //t:sailormnj f:cave.c r:sailormn c:sailormn
		DRIVER(sailormnk) //t:sailormnk f:cave.c r:sailormn c:sailormn
		DRIVER(sailormnt) //t:sailormnt f:cave.c r:sailormn c:sailormn
		DRIVER(sailormnh) //t:sailormnh f:cave.c r:sailormn c:sailormn
		DRIVER(sailormno) //t:sailormno f:cave.c r:sailormn c:sailormn
		DRIVER(sailormnou) //t:sailormnou f:cave.c r:sailormn c:sailormn
		DRIVER(sailormnoj) //t:sailormnoj f:cave.c r:sailormn c:sailormn
		DRIVER(sailormnok) //t:sailormnok f:cave.c r:sailormn c:sailormn
		DRIVER(sailormnot) //t:sailormnot f:cave.c r:sailormn c:sailormn
		DRIVER(sailormnoh) //t:sailormnoh f:cave.c r:sailormn c:sailormn
//SET: agallet
		DRIVER(agallet) //t:agallet f:cave.c r: c:
		DRIVER(agalletu) //t:agalletu f:cave.c r:agallet c:agallet
		DRIVER(agalletj) //t:agalletj f:cave.c r:agallet c:agallet
		DRIVER(agalletk) //t:agalletk f:cave.c r:agallet c:agallet
		DRIVER(agallett) //t:agallett f:cave.c r:agallet c:agallet
		DRIVER(agalleth) //t:agalleth f:cave.c r:agallet c:agallet
//SET: hotdogst
		DRIVER(hotdogst) //t:hotdogst f:cave.c r: c:
//SET: pacslot
		DRIVER(pacslot) //t:pacslot f:cave.c r: c:
//SET: ddonpach
		DRIVER(ddonpach) //t:ddonpach f:cave.c r: c:
		DRIVER(ddonpachj) //t:ddonpachj f:cave.c r:ddonpach c:ddonpach
//SET: feversos
		DRIVER(feversos) //t:feversos f:cave.c r: c:
		DRIVER(dfeveron) //t:dfeveron f:cave.c r:feversos c:feversos
//SET: esprade
		DRIVER(esprade) //t:esprade f:cave.c r: c:
		DRIVER(espradej) //t:espradej f:cave.c r:esprade c:esprade
		DRIVER(espradejo) //t:espradejo f:cave.c r:esprade c:esprade
//SET: uopoko
		DRIVER(uopoko) //t:uopoko f:cave.c r: c:
		DRIVER(uopokoj) //t:uopokoj f:cave.c r:uopoko c:uopoko
//SET: guwange
		DRIVER(guwange) //t:guwange f:cave.c r: c:
//SET: gaia
		DRIVER(gaia) //t:gaia f:cave.c r: c:
//SET: theroes
		DRIVER(theroes) //t:theroes f:cave.c r: c:
//SET: korokoro
		DRIVER(korokoro) //t:korokoro f:cave.c r: c:
//SET: crusherm
		DRIVER(crusherm) //t:crusherm f:cave.c r: c:
//SET: tjumpman
		DRIVER(tjumpman) //t:tjumpman f:cave.c r: c:
#endif

#ifdef PS3_SET_5
//SET: gyrodine
		DRIVER(gyrodine) //t:gyrodine f:kyugo.c r: c:
		DRIVER(gyrodinet) //t:gyrodinet f:kyugo.c r:gyrodine c:gyrodine
		DRIVER(buzzard) //t:buzzard f:kyugo.c r:gyrodine c:gyrodine
//SET: repulse
		DRIVER(repulse) //t:repulse f:kyugo.c r: c:
		DRIVER(99lstwar) //t:99lstwar f:kyugo.c r:repulse c:repulse
		DRIVER(99lstwara) //t:99lstwara f:kyugo.c r:repulse c:repulse
		DRIVER(99lstwark) //t:99lstwark f:kyugo.c r:repulse c:repulse
		DRIVER(sonofphx) //t:sonofphx f:kyugo.c r:repulse c:repulse
//SET: flashgal
		DRIVER(flashgal) //t:flashgal f:kyugo.c r: c:
		DRIVER(flashgala) //t:flashgala f:kyugo.c r:flashgal c:flashgal
//SET: srdmissn
		DRIVER(srdmissn) //t:srdmissn f:kyugo.c r: c:
		DRIVER(fx) //t:fx f:kyugo.c r:srdmissn c:srdmissn
//SET: legend
		DRIVER(legend) //t:legend f:kyugo.c r: c:
		DRIVER(legendb) //t:legendb f:kyugo.c r:legend c:legend
//SET: airwolf
		DRIVER(airwolf) //t:airwolf f:kyugo.c r: c:
		DRIVER(airwolfa) //t:airwolfa f:kyugo.c r:airwolf c:airwolf
		DRIVER(skywolf) //t:skywolf f:kyugo.c r:airwolf c:airwolf
		DRIVER(skywolf2) //t:skywolf2 f:kyugo.c r:airwolf c:airwolf
		DRIVER(skywolf3) //t:skywolf3 f:kyugo.c r:airwolf c:airwolf
//SET: defender
		DRIVER(defender) //t:defender f:williams.c r: c:
		DRIVER(defenderg) //t:defenderg f:williams.c r:defender c:defender
		DRIVER(defenderb) //t:defenderb f:williams.c r:defender c:defender
		DRIVER(defenderw) //t:defenderw f:williams.c r:defender c:defender
		DRIVER(defndjeu) //t:defndjeu f:williams.c r:defender c:defender
		DRIVER(tornado1) //t:tornado1 f:williams.c r:defender c:defender
		DRIVER(tornado2) //t:tornado2 f:williams.c r:defender c:defender
		DRIVER(zero) //t:zero f:williams.c r:defender c:defender
		DRIVER(zero2) //t:zero2 f:williams.c r:defender c:defender
		DRIVER(defcmnd) //t:defcmnd f:williams.c r:defender c:defender
		DRIVER(defence) //t:defence f:williams.c r:defender c:defender
		DRIVER(startrkd) //t:startrkd f:williams.c r:defender c:defender
//SET: mayday
		DRIVER(mayday) //t:mayday f:williams.c r: c:
		DRIVER(maydaya) //t:maydaya f:williams.c r:mayday c:mayday
		DRIVER(maydayb) //t:maydayb f:williams.c r:mayday c:mayday
//SET: colony7
		DRIVER(colony7) //t:colony7 f:williams.c r: c:
		DRIVER(colony7a) //t:colony7a f:williams.c r:colony7 c:colony7
//SET: jin
		DRIVER(jin) //t:jin f:williams.c r: c:
//SET: stargate
		DRIVER(stargate) //t:stargate f:williams.c r: c:
//SET: robotron
		DRIVER(robotron) //t:robotron f:williams.c r: c:
		DRIVER(robotronyo) //t:robotronyo f:williams.c r:robotron c:robotron
//SET: joust
		DRIVER(joust) //t:joust f:williams.c r: c:
		DRIVER(joustr) //t:joustr f:williams.c r:joust c:joust
		DRIVER(joustwr) //t:joustwr f:williams.c r:joust c:joust
//SET: bubbles
		DRIVER(bubbles) //t:bubbles f:williams.c r: c:
		DRIVER(bubblesr) //t:bubblesr f:williams.c r:bubbles c:bubbles
		DRIVER(bubblesp) //t:bubblesp f:williams.c r:bubbles c:bubbles
//SET: splat
		DRIVER(splat) //t:splat f:williams.c r: c:
//SET: sinistar
		DRIVER(sinistar) //t:sinistar f:williams.c r: c:
		DRIVER(sinistar1) //t:sinistar1 f:williams.c r:sinistar c:sinistar
		DRIVER(sinistar2) //t:sinistar2 f:williams.c r:sinistar c:sinistar
//SET: playball
		DRIVER(playball) //t:playball f:williams.c r: c:
//SET: blaster
		DRIVER(blaster) //t:blaster f:williams.c r: c:
		DRIVER(blaster30) //t:blaster30 f:williams.c r:blaster c:blaster
		DRIVER(blasterkit) //t:blasterkit f:williams.c r:blaster c:blaster
//SET: spdball
		DRIVER(spdball) //t:spdball f:williams.c r: c:
//SET: alienar
		DRIVER(alienar) //t:alienar f:williams.c r: c:
		DRIVER(alienaru) //t:alienaru f:williams.c r:alienar c:alienar
//SET: mysticm
		DRIVER(mysticm) //t:mysticm f:williams.c r: c:
//SET: tshoot
		DRIVER(tshoot) //t:tshoot f:williams.c r: c:
//SET: inferno
		DRIVER(inferno) //t:inferno f:williams.c r: c:
//SET: joust2
		DRIVER(joust2) //t:joust2 f:williams.c r: c:
//SET: lottofun
		DRIVER(lottofun) //t:lottofun f:williams.c r: c:
//SET: vulgus
		DRIVER(vulgus) //t:vulgus f:vulgus.c r: c:
		DRIVER(vulgus2) //t:vulgus2 f:vulgus.c r:vulgus c:vulgus
		DRIVER(vulgusj) //t:vulgusj f:vulgus.c r:vulgus c:vulgus
//SET: sonson
		DRIVER(sonson) //t:sonson f:sonson.c r: c:
		DRIVER(sonsonj) //t:sonsonj f:sonson.c r:sonson c:sonson
//SET: higemaru
		DRIVER(higemaru) //t:higemaru f:higemaru.c r: c:
//SET: 1942
		DRIVER(1942) //t:1942 f:1942.c r: c:
		DRIVER(1942a) //t:1942a f:1942.c r:1942 c:1942
		DRIVER(1942abl) //t:1942abl f:1942.c r:1942 c:1942
		DRIVER(1942b) //t:1942b f:1942.c r:1942 c:1942
		DRIVER(1942w) //t:1942w f:1942.c r:1942 c:1942
//SET: exedexes
		DRIVER(exedexes) //t:exedexes f:exedexes.c r: c:
		DRIVER(savgbees) //t:savgbees f:exedexes.c r:exedexes c:exedexes
//SET: commando
		DRIVER(commando) //t:commando f:commando.c r: c:
		DRIVER(commandou) //t:commandou f:commando.c r:commando c:commando
		DRIVER(commandoj) //t:commandoj f:commando.c r:commando c:commando
		DRIVER(commandob) //t:commandob f:commando.c r:commando c:commando
		DRIVER(sinvasn) //t:sinvasn f:commando.c r:commando c:commando
		DRIVER(sinvasnb) //t:sinvasnb f:commando.c r:commando c:commando
//SET: gng
		DRIVER(gng) //t:gng f:gng.c r: c:
		DRIVER(gnga) //t:gnga f:gng.c r:gng c:gng
		DRIVER(gngbl) //t:gngbl f:gng.c r:gng c:gng
		DRIVER(gngblita) //t:gngblita f:gng.c r:gng c:gng
		DRIVER(gngc) //t:gngc f:gng.c r:gng c:gng
		DRIVER(gngt) //t:gngt f:gng.c r:gng c:gng
		DRIVER(makaimur) //t:makaimur f:gng.c r:gng c:gng
		DRIVER(makaimurc) //t:makaimurc f:gng.c r:gng c:gng
		DRIVER(makaimurg) //t:makaimurg f:gng.c r:gng c:gng
//SET: diamond
		DRIVER(diamond) //t:diamond f:gng.c r: c:
//SET: gunsmoke
		DRIVER(gunsmoke) //t:gunsmoke f:gunsmoke.c r: c:
		DRIVER(gunsmokeu) //t:gunsmokeu f:gunsmoke.c r:gunsmoke c:gunsmoke
		DRIVER(gunsmokeua) //t:gunsmokeua f:gunsmoke.c r:gunsmoke c:gunsmoke
		DRIVER(gunsmokej) //t:gunsmokej f:gunsmoke.c r:gunsmoke c:gunsmoke
//SET: sectionz
		DRIVER(sectionz) //t:sectionz f:lwings.c r: c:
		DRIVER(sectionza) //t:sectionza f:lwings.c r:sectionz c:sectionz
//SET: trojan
		DRIVER(trojan) //t:trojan f:lwings.c r: c:
		DRIVER(trojanr) //t:trojanr f:lwings.c r:trojan c:trojan
		DRIVER(trojanj) //t:trojanj f:lwings.c r:trojan c:trojan
//SET: srumbler
		DRIVER(srumbler) //t:srumbler f:srumbler.c r: c:
		DRIVER(srumbler2) //t:srumbler2 f:srumbler.c r:srumbler c:srumbler
		DRIVER(rushcrsh) //t:rushcrsh f:srumbler.c r:srumbler c:srumbler
//SET: lwings
		DRIVER(lwings) //t:lwings f:lwings.c r: c:
		DRIVER(lwings2) //t:lwings2 f:lwings.c r:lwings c:lwings
		DRIVER(lwingsj) //t:lwingsj f:lwings.c r:lwings c:lwings
		DRIVER(lwingsb) //t:lwingsb f:lwings.c r:lwings c:lwings
//SET: sidearms
		DRIVER(sidearms) //t:sidearms f:sidearms.c r: c:
		DRIVER(sidearmsr) //t:sidearmsr f:sidearms.c r:sidearms c:sidearms
		DRIVER(sidearmsj) //t:sidearmsj f:sidearms.c r:sidearms c:sidearms
//SET: turtship
		DRIVER(turtship) //t:turtship f:sidearms.c r: c:
		DRIVER(turtshipj) //t:turtshipj f:sidearms.c r:turtship c:turtship
		DRIVER(turtshipk) //t:turtshipk f:sidearms.c r:turtship c:turtship
//SET: dyger
		DRIVER(dyger) //t:dyger f:sidearms.c r: c:
		DRIVER(dygera) //t:dygera f:sidearms.c r:dyger c:dyger
//SET: twinfalc
		DRIVER(twinfalc) //t:twinfalc f:sidearms.c r: c:
		DRIVER(whizz) //t:whizz f:sidearms.c r:twinfalc c:twinfalc
//SET: avengers
		DRIVER(avengers) //t:avengers f:lwings.c r: c:
		DRIVER(avengers2) //t:avengers2 f:lwings.c r:avengers c:avengers
		DRIVER(buraiken) //t:buraiken f:lwings.c r:avengers c:avengers
//SET: bionicc
		DRIVER(bionicc) //t:bionicc f:bionicc.c r: c:
		DRIVER(bionicc1) //t:bionicc1 f:bionicc.c r:bionicc c:bionicc
		DRIVER(bionicc2) //t:bionicc2 f:bionicc.c r:bionicc c:bionicc
		DRIVER(topsecrt) //t:topsecrt f:bionicc.c r:bionicc c:bionicc
//SET: 1943
		DRIVER(1943) //t:1943 f:1943.c r: c:
		DRIVER(1943u) //t:1943u f:1943.c r:1943 c:1943
		DRIVER(1943j) //t:1943j f:1943.c r:1943 c:1943
		DRIVER(1943b) //t:1943b f:1943.c r:1943 c:1943
//SET: blktiger
		DRIVER(blktiger) //t:blktiger f:blktiger.c r: c:
		DRIVER(blktigera) //t:blktigera f:blktiger.c r:blktiger c:blktiger
		DRIVER(blktigerb1) //t:blktigerb1 f:blktiger.c r:blktiger c:blktiger
		DRIVER(blktigerb2) //t:blktigerb2 f:blktiger.c r:blktiger c:blktiger
		DRIVER(blkdrgon) //t:blkdrgon f:blktiger.c r:blktiger c:blktiger
		DRIVER(blkdrgonb) //t:blkdrgonb f:blktiger.c r:blktiger c:blktiger
//SET: sf
		DRIVER(sf) //t:sf f:sf.c r: c:
		DRIVER(sfu) //t:sfu f:sf.c r:sf c:sf
		DRIVER(sfua) //t:sfua f:sf.c r:sf c:sf
		DRIVER(sfj) //t:sfj f:sf.c r:sf c:sf
		DRIVER(sfp) //t:sfp f:sf.c r:sf c:sf
//SET: tigeroad
		DRIVER(tigeroad) //t:tigeroad f:tigeroad.c r: c:
		DRIVER(toramich) //t:toramich f:tigeroad.c r:tigeroad c:tigeroad
		DRIVER(tigeroadb) //t:tigeroadb f:tigeroad.c r:tigeroad c:tigeroad
//SET: f1dream
		DRIVER(f1dream) //t:f1dream f:tigeroad.c r: c:
		DRIVER(f1dreamb) //t:f1dreamb f:tigeroad.c r:f1dream c:f1dream
//SET: 1943kai
		DRIVER(1943kai) //t:1943kai f:1943.c r: c:
//SET: lastduel
		DRIVER(lastduel) //t:lastduel f:lastduel.c r: c:
		DRIVER(lastduelo) //t:lastduelo f:lastduel.c r:lastduel c:lastduel
		DRIVER(lastduelj) //t:lastduelj f:lastduel.c r:lastduel c:lastduel
		DRIVER(lastduelb) //t:lastduelb f:lastduel.c r:lastduel c:lastduel
//SET: madgear
		DRIVER(madgear) //t:madgear f:lastduel.c r: c:
		DRIVER(madgearj) //t:madgearj f:lastduel.c r:madgear c:madgear
		DRIVER(ledstorm) //t:ledstorm f:lastduel.c r:madgear c:madgear
		DRIVER(ledstorm2) //t:ledstorm2 f:lastduel.c r:madgear c:madgear
//SET: forgottn
		DRIVER(forgottn) //t:forgottn f:cps1.c r: c:
		DRIVER(forgottnu) //t:forgottnu f:cps1.c r:forgottn c:forgottn
		DRIVER(forgottnua) //t:forgottnua f:cps1.c r:forgottn c:forgottn
		DRIVER(lostwrld) //t:lostwrld f:cps1.c r:forgottn c:forgottn
		DRIVER(lostwrldo) //t:lostwrldo f:cps1.c r:forgottn c:forgottn
//SET: ghouls
		DRIVER(ghouls) //t:ghouls f:cps1.c r: c:
		DRIVER(ghoulsu) //t:ghoulsu f:cps1.c r:ghouls c:ghouls
		DRIVER(daimakai) //t:daimakai f:cps1.c r:ghouls c:ghouls
		DRIVER(daimakair) //t:daimakair f:cps1.c r:ghouls c:ghouls
//SET: strider
		DRIVER(strider) //t:strider f:cps1.c r: c:
		DRIVER(striderua) //t:striderua f:cps1.c r:strider c:strider
		DRIVER(striderj) //t:striderj f:cps1.c r:strider c:strider
		DRIVER(striderjr) //t:striderjr f:cps1.c r:strider c:strider
//SET: dynwar
		DRIVER(dynwar) //t:dynwar f:cps1.c r: c:
		DRIVER(dynwara) //t:dynwara f:cps1.c r:dynwar c:dynwar
		DRIVER(dynwarj) //t:dynwarj f:cps1.c r:dynwar c:dynwar
		DRIVER(dynwarjr) //t:dynwarjr f:cps1.c r:dynwar c:dynwar
//SET: willow
		DRIVER(willow) //t:willow f:cps1.c r: c:
		DRIVER(willowo) //t:willowo f:cps1.c r:willow c:willow
		DRIVER(willowj) //t:willowj f:cps1.c r:willow c:willow
//SET: unsquad
		DRIVER(unsquad) //t:unsquad f:cps1.c r: c:
		DRIVER(area88) //t:area88 f:cps1.c r:unsquad c:unsquad
		DRIVER(area88r) //t:area88r f:cps1.c r:unsquad c:unsquad
//SET: ffight
		DRIVER(ffight) //t:ffight f:cps1.c r: c:
		DRIVER(ffightu) //t:ffightu f:cps1.c r:ffight c:ffight
		DRIVER(ffightua) //t:ffightua f:cps1.c r:ffight c:ffight
		DRIVER(ffightub) //t:ffightub f:cps1.c r:ffight c:ffight
		DRIVER(ffightj) //t:ffightj f:cps1.c r:ffight c:ffight
		DRIVER(ffightj1) //t:ffightj1 f:cps1.c r:ffight c:ffight
		DRIVER(ffightj2) //t:ffightj2 f:cps1.c r:ffight c:ffight
		DRIVER(ffightjh) //t:ffightjh f:cps1.c r:ffight c:ffight
		DRIVER(fcrash) //t:fcrash f:fcrash.c r:ffight c:ffight
//SET: 1941
		DRIVER(1941) //t:1941 f:cps1.c r: c:
		DRIVER(1941u) //t:1941u f:cps1.c r:1941 c:1941
		DRIVER(1941j) //t:1941j f:cps1.c r:1941 c:1941
//SET: mercs
		DRIVER(mercs) //t:mercs f:cps1.c r: c:
		DRIVER(mercsu) //t:mercsu f:cps1.c r:mercs c:mercs
		DRIVER(mercsur1) //t:mercsur1 f:cps1.c r:mercs c:mercs
		DRIVER(mercsj) //t:mercsj f:cps1.c r:mercs c:mercs
//SET: mtwins
		DRIVER(mtwins) //t:mtwins f:cps1.c r: c:
		DRIVER(chikij) //t:chikij f:cps1.c r:mtwins c:mtwins
//SET: msword
		DRIVER(msword) //t:msword f:cps1.c r: c:
		DRIVER(mswordr1) //t:mswordr1 f:cps1.c r:msword c:msword
		DRIVER(mswordu) //t:mswordu f:cps1.c r:msword c:msword
		DRIVER(mswordj) //t:mswordj f:cps1.c r:msword c:msword
//SET: cawing
		DRIVER(cawing) //t:cawing f:cps1.c r: c:
		DRIVER(cawingr1) //t:cawingr1 f:cps1.c r:cawing c:cawing
		DRIVER(cawingu) //t:cawingu f:cps1.c r:cawing c:cawing
		DRIVER(cawingj) //t:cawingj f:cps1.c r:cawing c:cawing
//SET: nemo
		DRIVER(nemo) //t:nemo f:cps1.c r: c:
		DRIVER(nemoj) //t:nemoj f:cps1.c r:nemo c:nemo
//SET: sf2
		DRIVER(sf2) //t:sf2 f:cps1.c r: c:
		DRIVER(sf2eb) //t:sf2eb f:cps1.c r:sf2 c:sf2
		DRIVER(sf2ee) //t:sf2ee f:cps1.c r:sf2 c:sf2
		DRIVER(sf2ebbl) //t:sf2ebbl f:cps1.c r:sf2 c:sf2
		DRIVER(sf2ua) //t:sf2ua f:cps1.c r:sf2 c:sf2
		DRIVER(sf2ub) //t:sf2ub f:cps1.c r:sf2 c:sf2
		DRIVER(sf2ud) //t:sf2ud f:cps1.c r:sf2 c:sf2
		DRIVER(sf2ue) //t:sf2ue f:cps1.c r:sf2 c:sf2
		DRIVER(sf2uf) //t:sf2uf f:cps1.c r:sf2 c:sf2
		DRIVER(sf2ui) //t:sf2ui f:cps1.c r:sf2 c:sf2
		DRIVER(sf2uk) //t:sf2uk f:cps1.c r:sf2 c:sf2
		DRIVER(sf2j) //t:sf2j f:cps1.c r:sf2 c:sf2
		DRIVER(sf2ja) //t:sf2ja f:cps1.c r:sf2 c:sf2
		DRIVER(sf2jc) //t:sf2jc f:cps1.c r:sf2 c:sf2
		DRIVER(sf2qp1) //t:sf2qp1 f:cps1.c r:sf2 c:sf2
		DRIVER(sf2thndr) //t:sf2thndr f:cps1.c r:sf2 c:sf2
//SET: 3wonders
		DRIVER(3wonders) //t:3wonders f:cps1.c r: c:
		DRIVER(3wondersu) //t:3wondersu f:cps1.c r:3wonders c:3wonders
		DRIVER(wonder3) //t:wonder3 f:cps1.c r:3wonders c:3wonders
		DRIVER(3wondersh) //t:3wondersh f:cps1.c r:3wonders c:3wonders
//SET: kod
		DRIVER(kod) //t:kod f:cps1.c r: c:
		DRIVER(kodr1) //t:kodr1 f:cps1.c r:kod c:kod
		DRIVER(kodu) //t:kodu f:cps1.c r:kod c:kod
		DRIVER(kodj) //t:kodj f:cps1.c r:kod c:kod
		DRIVER(kodja) //t:kodja f:cps1.c r:kod c:kod
		DRIVER(kodb) //t:kodb f:fcrash.c r:kod c:kod
//SET: captcomm
		DRIVER(captcomm) //t:captcomm f:cps1.c r: c:
		DRIVER(captcommr1) //t:captcommr1 f:cps1.c r:captcomm c:captcomm
		DRIVER(captcommu) //t:captcommu f:cps1.c r:captcomm c:captcomm
		DRIVER(captcommj) //t:captcommj f:cps1.c r:captcomm c:captcomm
		DRIVER(captcommjr1) //t:captcommjr1 f:cps1.c r:captcomm c:captcomm
		DRIVER(captcommb) //t:captcommb f:cps1.c r:captcomm c:captcomm
//SET: knights
		DRIVER(knights) //t:knights f:cps1.c r: c:
		DRIVER(knightsu) //t:knightsu f:cps1.c r:knights c:knights
		DRIVER(knightsj) //t:knightsj f:cps1.c r:knights c:knights
		DRIVER(knightsja) //t:knightsja f:cps1.c r:knights c:knights
		DRIVER(knightsb) //t:knightsb f:cps1.c r:knights c:knights
//SET: sf2ce
		DRIVER(sf2ce) //t:sf2ce f:cps1.c r: c:
		DRIVER(sf2ceea) //t:sf2ceea f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2ceua) //t:sf2ceua f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2ceub) //t:sf2ceub f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2ceuc) //t:sf2ceuc f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2cej) //t:sf2cej f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2rb) //t:sf2rb f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2rb2) //t:sf2rb2 f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2rb3) //t:sf2rb3 f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2red) //t:sf2red f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2v004) //t:sf2v004 f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2acc) //t:sf2acc f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2accp2) //t:sf2accp2 f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2dkot2) //t:sf2dkot2 f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2m1) //t:sf2m1 f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2m2) //t:sf2m2 f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2m3) //t:sf2m3 f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2m4) //t:sf2m4 f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2m5) //t:sf2m5 f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2m6) //t:sf2m6 f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2m7) //t:sf2m7 f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2yyc) //t:sf2yyc f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2koryu) //t:sf2koryu f:cps1.c r:sf2ce c:sf2ce
		DRIVER(sf2mdt) //t:sf2mdt f:cps1.c r:sf2ce c:sf2ce
//SET: cworld2j
		DRIVER(cworld2j) //t:cworld2j f:cps1.c r: c:
//SET: varth
		DRIVER(varth) //t:varth f:cps1.c r: c:
		DRIVER(varthr1) //t:varthr1 f:cps1.c r:varth c:varth
		DRIVER(varthu) //t:varthu f:cps1.c r:varth c:varth
		DRIVER(varthj) //t:varthj f:cps1.c r:varth c:varth
//SET: qad
		DRIVER(qad) //t:qad f:cps1.c r: c:
		DRIVER(qadj) //t:qadj f:cps1.c r:qad c:qad
//SET: wof
		DRIVER(wof) //t:wof f:cps1.c r: c:
		DRIVER(wofu) //t:wofu f:cps1.c r:wof c:wof
		DRIVER(wofa) //t:wofa f:cps1.c r:wof c:wof
		DRIVER(wofj) //t:wofj f:cps1.c r:wof c:wof
		DRIVER(wofhfh) //t:wofhfh f:cps1.c r:wof c:wof
//SET: sf2hf
		DRIVER(sf2hf) //t:sf2hf f:cps1.c r: c:
		DRIVER(sf2hfu) //t:sf2hfu f:cps1.c r:sf2hf c:sf2hf
		DRIVER(sf2hfj) //t:sf2hfj f:cps1.c r:sf2hf c:sf2hf
//SET: dino
		DRIVER(dino) //t:dino f:cps1.c r: c:
		DRIVER(dinou) //t:dinou f:cps1.c r:dino c:dino
		DRIVER(dinoj) //t:dinoj f:cps1.c r:dino c:dino
		DRIVER(dinopic) //t:dinopic f:cps1.c r:dino c:dino
		DRIVER(dinopic2) //t:dinopic2 f:cps1.c r:dino c:dino
		DRIVER(dinohunt) //t:dinohunt f:cps1.c r:dino c:dino
//SET: punisher
		DRIVER(punisher) //t:punisher f:cps1.c r: c:
		DRIVER(punisheru) //t:punisheru f:cps1.c r:punisher c:punisher
		DRIVER(punisherj) //t:punisherj f:cps1.c r:punisher c:punisher
		DRIVER(punipic) //t:punipic f:cps1.c r:punisher c:punisher
		DRIVER(punipic2) //t:punipic2 f:cps1.c r:punisher c:punisher
		DRIVER(punipic3) //t:punipic3 f:cps1.c r:punisher c:punisher
		DRIVER(punisherbz) //t:punisherbz f:cps1.c r:punisher c:punisher
//SET: slammast
		DRIVER(slammast) //t:slammast f:cps1.c r: c:
		DRIVER(slammastu) //t:slammastu f:cps1.c r:slammast c:slammast
		DRIVER(mbomberj) //t:mbomberj f:cps1.c r:slammast c:slammast
//SET: mbombrd
		DRIVER(mbombrd) //t:mbombrd f:cps1.c r: c:
		DRIVER(mbombrdj) //t:mbombrdj f:cps1.c r:mbombrd c:mbombrd
//SET: pnickj
		DRIVER(pnickj) //t:pnickj f:cps1.c r: c:
//SET: qtono2j
		DRIVER(qtono2j) //t:qtono2j f:cps1.c r: c:
//SET: pang3
		DRIVER(pang3) //t:pang3 f:cps1.c r: c:
		DRIVER(pang3n) //t:pang3n f:cps1.c r:pang3 c:pang3
		DRIVER(pang3j) //t:pang3j f:cps1.c r:pang3 c:pang3
//SET: megaman
		DRIVER(megaman) //t:megaman f:cps1.c r: c:
		DRIVER(megamana) //t:megamana f:cps1.c r:megaman c:megaman
		DRIVER(rockmanj) //t:rockmanj f:cps1.c r:megaman c:megaman
		DRIVER(mmancp2u) //t:mmancp2u f:cps2.c r:megaman c:megaman
		DRIVER(rmancp2j) //t:rmancp2j f:cps2.c r:megaman c:megaman
//SET: ssf2
		DRIVER(ssf2) //t:ssf2 f:cps2.c r: c:
		DRIVER(ssf2u) //t:ssf2u f:cps2.c r:ssf2 c:ssf2
		DRIVER(ssf2a) //t:ssf2a f:cps2.c r:ssf2 c:ssf2
		DRIVER(ssf2ar1) //t:ssf2ar1 f:cps2.c r:ssf2 c:ssf2
		DRIVER(ssf2j) //t:ssf2j f:cps2.c r:ssf2 c:ssf2
		DRIVER(ssf2jr1) //t:ssf2jr1 f:cps2.c r:ssf2 c:ssf2
		DRIVER(ssf2jr2) //t:ssf2jr2 f:cps2.c r:ssf2 c:ssf2
		DRIVER(ssf2h) //t:ssf2h f:cps2.c r:ssf2 c:ssf2
		DRIVER(ssf2tb) //t:ssf2tb f:cps2.c r:ssf2 c:ssf2
		DRIVER(ssf2tbr1) //t:ssf2tbr1 f:cps2.c r:ssf2 c:ssf2
		DRIVER(ssf2tbj) //t:ssf2tbj f:cps2.c r:ssf2 c:ssf2
		DRIVER(ssf2ud) //t:ssf2ud f:cps2.c r:ssf2 c:ssf2
		DRIVER(ssf2tbd) //t:ssf2tbd f:cps2.c r:ssf2 c:ssf2
//SET: ecofghtr
		DRIVER(ecofghtr) //t:ecofghtr f:cps2.c r: c:
		DRIVER(ecofghtru) //t:ecofghtru f:cps2.c r:ecofghtr c:ecofghtr
		DRIVER(ecofghtru1) //t:ecofghtru1 f:cps2.c r:ecofghtr c:ecofghtr
		DRIVER(ecofghtra) //t:ecofghtra f:cps2.c r:ecofghtr c:ecofghtr
		DRIVER(ecofghtrh) //t:ecofghtrh f:cps2.c r:ecofghtr c:ecofghtr
		DRIVER(uecology) //t:uecology f:cps2.c r:ecofghtr c:ecofghtr
		DRIVER(ecofghtrd) //t:ecofghtrd f:cps2.c r:ecofghtr c:ecofghtr
//SET: ddtod
		DRIVER(ddtod) //t:ddtod f:cps2.c r: c:
		DRIVER(ddtodr1) //t:ddtodr1 f:cps2.c r:ddtod c:ddtod
		DRIVER(ddtodu) //t:ddtodu f:cps2.c r:ddtod c:ddtod
		DRIVER(ddtodur1) //t:ddtodur1 f:cps2.c r:ddtod c:ddtod
		DRIVER(ddtodj) //t:ddtodj f:cps2.c r:ddtod c:ddtod
		DRIVER(ddtodjr1) //t:ddtodjr1 f:cps2.c r:ddtod c:ddtod
		DRIVER(ddtodjr2) //t:ddtodjr2 f:cps2.c r:ddtod c:ddtod
		DRIVER(ddtoda) //t:ddtoda f:cps2.c r:ddtod c:ddtod
		DRIVER(ddtodh) //t:ddtodh f:cps2.c r:ddtod c:ddtod
		DRIVER(ddtodhr1) //t:ddtodhr1 f:cps2.c r:ddtod c:ddtod
		DRIVER(ddtodhr2) //t:ddtodhr2 f:cps2.c r:ddtod c:ddtod
		DRIVER(ddtodd) //t:ddtodd f:cps2.c r:ddtod c:ddtod
//SET: ssf2t
		DRIVER(ssf2t) //t:ssf2t f:cps2.c r: c:
		DRIVER(ssf2tu) //t:ssf2tu f:cps2.c r:ssf2t c:ssf2t
		DRIVER(ssf2tur1) //t:ssf2tur1 f:cps2.c r:ssf2t c:ssf2t
		DRIVER(ssf2ta) //t:ssf2ta f:cps2.c r:ssf2t c:ssf2t
		DRIVER(ssf2xj) //t:ssf2xj f:cps2.c r:ssf2t c:ssf2t
		DRIVER(ssf2xjd) //t:ssf2xjd f:cps2.c r:ssf2t c:ssf2t
//SET: avsp
		DRIVER(avsp) //t:avsp f:cps2.c r: c:
		DRIVER(avspu) //t:avspu f:cps2.c r:avsp c:avsp
		DRIVER(avspj) //t:avspj f:cps2.c r:avsp c:avsp
		DRIVER(avspa) //t:avspa f:cps2.c r:avsp c:avsp
		DRIVER(avsph) //t:avsph f:cps2.c r:avsp c:avsp
		DRIVER(avspd) //t:avspd f:cps2.c r:avsp c:avsp
//SET: dstlk
		DRIVER(dstlk) //t:dstlk f:cps2.c r: c:
		DRIVER(dstlku) //t:dstlku f:cps2.c r:dstlk c:dstlk
		DRIVER(dstlkur1) //t:dstlkur1 f:cps2.c r:dstlk c:dstlk
		DRIVER(dstlka) //t:dstlka f:cps2.c r:dstlk c:dstlk
		DRIVER(dstlkh) //t:dstlkh f:cps2.c r:dstlk c:dstlk
		DRIVER(vampj) //t:vampj f:cps2.c r:dstlk c:dstlk
		DRIVER(vampja) //t:vampja f:cps2.c r:dstlk c:dstlk
		DRIVER(vampjr1) //t:vampjr1 f:cps2.c r:dstlk c:dstlk
		DRIVER(dstlku1d) //t:dstlku1d f:cps2.c r:dstlk c:dstlk
//SET: ringdest
		DRIVER(ringdest) //t:ringdest f:cps2.c r: c:
		DRIVER(ringdesta) //t:ringdesta f:cps2.c r:ringdest c:ringdest
		DRIVER(smbomb) //t:smbomb f:cps2.c r:ringdest c:ringdest
		DRIVER(smbombr1) //t:smbombr1 f:cps2.c r:ringdest c:ringdest
		DRIVER(ringdstd) //t:ringdstd f:cps2.c r:ringdest c:ringdest
//SET: armwar
		DRIVER(armwar) //t:armwar f:cps2.c r: c:
		DRIVER(armwarr1) //t:armwarr1 f:cps2.c r:armwar c:armwar
		DRIVER(armwaru) //t:armwaru f:cps2.c r:armwar c:armwar
		DRIVER(armwaru1) //t:armwaru1 f:cps2.c r:armwar c:armwar
		DRIVER(pgear) //t:pgear f:cps2.c r:armwar c:armwar
		DRIVER(pgearr1) //t:pgearr1 f:cps2.c r:armwar c:armwar
		DRIVER(armwara) //t:armwara f:cps2.c r:armwar c:armwar
		DRIVER(armwar1d) //t:armwar1d f:cps2.c r:armwar c:armwar
//SET: xmcota
		DRIVER(xmcota) //t:xmcota f:cps2.c r: c:
		DRIVER(xmcotau) //t:xmcotau f:cps2.c r:xmcota c:xmcota
		DRIVER(xmcotah) //t:xmcotah f:cps2.c r:xmcota c:xmcota
		DRIVER(xmcotahr1) //t:xmcotahr1 f:cps2.c r:xmcota c:xmcota
		DRIVER(xmcotaj) //t:xmcotaj f:cps2.c r:xmcota c:xmcota
		DRIVER(xmcotaj1) //t:xmcotaj1 f:cps2.c r:xmcota c:xmcota
		DRIVER(xmcotaj2) //t:xmcotaj2 f:cps2.c r:xmcota c:xmcota
		DRIVER(xmcotaj3) //t:xmcotaj3 f:cps2.c r:xmcota c:xmcota
		DRIVER(xmcotaa) //t:xmcotaa f:cps2.c r:xmcota c:xmcota
		DRIVER(xmcotaar1) //t:xmcotaar1 f:cps2.c r:xmcota c:xmcota
		DRIVER(xmcotajr) //t:xmcotajr f:cps2.c r:xmcota c:xmcota
		DRIVER(xmcotad) //t:xmcotad f:cps2.c r:xmcota c:xmcota
//SET: nwarr
		DRIVER(nwarr) //t:nwarr f:cps2.c r: c:
		DRIVER(nwarru) //t:nwarru f:cps2.c r:nwarr c:nwarr
		DRIVER(nwarrh) //t:nwarrh f:cps2.c r:nwarr c:nwarr
		DRIVER(nwarrb) //t:nwarrb f:cps2.c r:nwarr c:nwarr
		DRIVER(nwarra) //t:nwarra f:cps2.c r:nwarr c:nwarr
		DRIVER(vhuntj) //t:vhuntj f:cps2.c r:nwarr c:nwarr
		DRIVER(vhuntjr1) //t:vhuntjr1 f:cps2.c r:nwarr c:nwarr
		DRIVER(vhuntjr2) //t:vhuntjr2 f:cps2.c r:nwarr c:nwarr
		DRIVER(nwarrud) //t:nwarrud f:cps2.c r:nwarr c:nwarr
//SET: cybots
		DRIVER(cybots) //t:cybots f:cps2.c r: c:
		DRIVER(cybotsu) //t:cybotsu f:cps2.c r:cybots c:cybots
		DRIVER(cybotsj) //t:cybotsj f:cps2.c r:cybots c:cybots
		DRIVER(cybotsud) //t:cybotsud f:cps2.c r:cybots c:cybots
//SET: sfa
		DRIVER(sfa) //t:sfa f:cps2.c r: c:
		DRIVER(sfar1) //t:sfar1 f:cps2.c r:sfa c:sfa
		DRIVER(sfar2) //t:sfar2 f:cps2.c r:sfa c:sfa
		DRIVER(sfar3) //t:sfar3 f:cps2.c r:sfa c:sfa
		DRIVER(sfau) //t:sfau f:cps2.c r:sfa c:sfa
		DRIVER(sfza) //t:sfza f:cps2.c r:sfa c:sfa
		DRIVER(sfzj) //t:sfzj f:cps2.c r:sfa c:sfa
		DRIVER(sfzjr1) //t:sfzjr1 f:cps2.c r:sfa c:sfa
		DRIVER(sfzjr2) //t:sfzjr2 f:cps2.c r:sfa c:sfa
		DRIVER(sfzh) //t:sfzh f:cps2.c r:sfa c:sfa
		DRIVER(sfzhr1) //t:sfzhr1 f:cps2.c r:sfa c:sfa
		DRIVER(sfzb) //t:sfzb f:cps2.c r:sfa c:sfa
		DRIVER(sfzbr1) //t:sfzbr1 f:cps2.c r:sfa c:sfa
		DRIVER(sfad) //t:sfad f:cps2.c r:sfa c:sfa
//SET: msh
		DRIVER(msh) //t:msh f:cps2.c r: c:
		DRIVER(mshu) //t:mshu f:cps2.c r:msh c:msh
		DRIVER(mshj) //t:mshj f:cps2.c r:msh c:msh
		DRIVER(mshjr1) //t:mshjr1 f:cps2.c r:msh c:msh
		DRIVER(msha) //t:msha f:cps2.c r:msh c:msh
		DRIVER(mshh) //t:mshh f:cps2.c r:msh c:msh
		DRIVER(mshb) //t:mshb f:cps2.c r:msh c:msh
		DRIVER(mshud) //t:mshud f:cps2.c r:msh c:msh
//SET: 19xx
		DRIVER(19xx) //t:19xx f:cps2.c r: c:
		DRIVER(19xxj) //t:19xxj f:cps2.c r:19xx c:19xx
		DRIVER(19xxjr1) //t:19xxjr1 f:cps2.c r:19xx c:19xx
		DRIVER(19xxa) //t:19xxa f:cps2.c r:19xx c:19xx
		DRIVER(19xxh) //t:19xxh f:cps2.c r:19xx c:19xx
		DRIVER(19xxb) //t:19xxb f:cps2.c r:19xx c:19xx
		DRIVER(19xxd) //t:19xxd f:cps2.c r:19xx c:19xx
//SET: ddsom
		DRIVER(ddsom) //t:ddsom f:cps2.c r: c:
		DRIVER(ddsomr1) //t:ddsomr1 f:cps2.c r:ddsom c:ddsom
		DRIVER(ddsomr2) //t:ddsomr2 f:cps2.c r:ddsom c:ddsom
		DRIVER(ddsomr3) //t:ddsomr3 f:cps2.c r:ddsom c:ddsom
		DRIVER(ddsomu) //t:ddsomu f:cps2.c r:ddsom c:ddsom
		DRIVER(ddsomur1) //t:ddsomur1 f:cps2.c r:ddsom c:ddsom
		DRIVER(ddsomjr1) //t:ddsomjr1 f:cps2.c r:ddsom c:ddsom
		DRIVER(ddsomj) //t:ddsomj f:cps2.c r:ddsom c:ddsom
		DRIVER(ddsoma) //t:ddsoma f:cps2.c r:ddsom c:ddsom
		DRIVER(ddsomh) //t:ddsomh f:cps2.c r:ddsom c:ddsom
		DRIVER(ddsomb) //t:ddsomb f:cps2.c r:ddsom c:ddsom
		DRIVER(ddsomud) //t:ddsomud f:cps2.c r:ddsom c:ddsom
//SET: sfa2
		DRIVER(sfa2) //t:sfa2 f:cps2.c r: c:
		DRIVER(sfa2u) //t:sfa2u f:cps2.c r:sfa2 c:sfa2
		DRIVER(sfa2ur1) //t:sfa2ur1 f:cps2.c r:sfa2 c:sfa2
		DRIVER(sfz2j) //t:sfz2j f:cps2.c r:sfa2 c:sfa2
		DRIVER(sfz2a) //t:sfz2a f:cps2.c r:sfa2 c:sfa2
		DRIVER(sfz2b) //t:sfz2b f:cps2.c r:sfa2 c:sfa2
		DRIVER(sfz2br1) //t:sfz2br1 f:cps2.c r:sfa2 c:sfa2
		DRIVER(sfz2h) //t:sfz2h f:cps2.c r:sfa2 c:sfa2
		DRIVER(sfz2n) //t:sfz2n f:cps2.c r:sfa2 c:sfa2
		DRIVER(sfz2ad) //t:sfz2ad f:cps2.c r:sfa2 c:sfa2
		DRIVER(sfz2jd) //t:sfz2jd f:cps2.c r:sfa2 c:sfa2
//SET: spf2t
		DRIVER(spf2t) //t:spf2t f:cps2.c r: c:
		DRIVER(spf2xj) //t:spf2xj f:cps2.c r:spf2t c:spf2t
		DRIVER(spf2ta) //t:spf2ta f:cps2.c r:spf2t c:spf2t
		DRIVER(spf2th) //t:spf2th f:cps2.c r:spf2t c:spf2t
		DRIVER(spf2td) //t:spf2td f:cps2.c r:spf2t c:spf2t
		DRIVER(spf2xjd) //t:spf2xjd f:cps2.c r:spf2t c:spf2t
//SET: megaman2
		DRIVER(megaman2) //t:megaman2 f:cps2.c r: c:
		DRIVER(megaman2a) //t:megaman2a f:cps2.c r:megaman2 c:megaman2
		DRIVER(rockman2j) //t:rockman2j f:cps2.c r:megaman2 c:megaman2
		DRIVER(megaman2h) //t:megaman2h f:cps2.c r:megaman2 c:megaman2
		DRIVER(gigamn2) //t:gigamn2 f:cps2.c r:megaman2 c:megaman2
		DRIVER(megamn2d) //t:megamn2d f:cps2.c r:megaman2 c:megaman2
//SET: sfz2al
		DRIVER(sfz2al) //t:sfz2al f:cps2.c r: c:
		DRIVER(sfz2alj) //t:sfz2alj f:cps2.c r:sfz2al c:sfz2al
		DRIVER(sfz2alh) //t:sfz2alh f:cps2.c r:sfz2al c:sfz2al
		DRIVER(sfz2alb) //t:sfz2alb f:cps2.c r:sfz2al c:sfz2al
		DRIVER(sfz2ald) //t:sfz2ald f:cps2.c r:sfz2al c:sfz2al
//SET: qndream
		DRIVER(qndream) //t:qndream f:cps2.c r: c:
//SET: xmvsf
		DRIVER(xmvsf) //t:xmvsf f:cps2.c r: c:
		DRIVER(xmvsfr1) //t:xmvsfr1 f:cps2.c r:xmvsf c:xmvsf
		DRIVER(xmvsfu) //t:xmvsfu f:cps2.c r:xmvsf c:xmvsf
		DRIVER(xmvsfur1) //t:xmvsfur1 f:cps2.c r:xmvsf c:xmvsf
		DRIVER(xmvsfj) //t:xmvsfj f:cps2.c r:xmvsf c:xmvsf
		DRIVER(xmvsfjr1) //t:xmvsfjr1 f:cps2.c r:xmvsf c:xmvsf
		DRIVER(xmvsfjr2) //t:xmvsfjr2 f:cps2.c r:xmvsf c:xmvsf
		DRIVER(xmvsfa) //t:xmvsfa f:cps2.c r:xmvsf c:xmvsf
		DRIVER(xmvsfar1) //t:xmvsfar1 f:cps2.c r:xmvsf c:xmvsf
		DRIVER(xmvsfar2) //t:xmvsfar2 f:cps2.c r:xmvsf c:xmvsf
		DRIVER(xmvsfh) //t:xmvsfh f:cps2.c r:xmvsf c:xmvsf
		DRIVER(xmvsfb) //t:xmvsfb f:cps2.c r:xmvsf c:xmvsf
		DRIVER(xmvsfu1d) //t:xmvsfu1d f:cps2.c r:xmvsf c:xmvsf
//SET: batcir
		DRIVER(batcir) //t:batcir f:cps2.c r: c:
		DRIVER(batcirj) //t:batcirj f:cps2.c r:batcir c:batcir
		DRIVER(batcira) //t:batcira f:cps2.c r:batcir c:batcir
		DRIVER(batcird) //t:batcird f:cps2.c r:batcir c:batcir
//SET: vsav
		DRIVER(vsav) //t:vsav f:cps2.c r: c:
		DRIVER(vsavu) //t:vsavu f:cps2.c r:vsav c:vsav
		DRIVER(vsavj) //t:vsavj f:cps2.c r:vsav c:vsav
		DRIVER(vsava) //t:vsava f:cps2.c r:vsav c:vsav
		DRIVER(vsavh) //t:vsavh f:cps2.c r:vsav c:vsav
		DRIVER(vsavd) //t:vsavd f:cps2.c r:vsav c:vsav
//SET: mshvsf
		DRIVER(mshvsf) //t:mshvsf f:cps2.c r: c:
		DRIVER(mshvsfu) //t:mshvsfu f:cps2.c r:mshvsf c:mshvsf
		DRIVER(mshvsfu1) //t:mshvsfu1 f:cps2.c r:mshvsf c:mshvsf
		DRIVER(mshvsfj) //t:mshvsfj f:cps2.c r:mshvsf c:mshvsf
		DRIVER(mshvsfj1) //t:mshvsfj1 f:cps2.c r:mshvsf c:mshvsf
		DRIVER(mshvsfj2) //t:mshvsfj2 f:cps2.c r:mshvsf c:mshvsf
		DRIVER(mshvsfh) //t:mshvsfh f:cps2.c r:mshvsf c:mshvsf
		DRIVER(mshvsfa) //t:mshvsfa f:cps2.c r:mshvsf c:mshvsf
		DRIVER(mshvsfa1) //t:mshvsfa1 f:cps2.c r:mshvsf c:mshvsf
		DRIVER(mshvsfb) //t:mshvsfb f:cps2.c r:mshvsf c:mshvsf
		DRIVER(mshvsfb1) //t:mshvsfb1 f:cps2.c r:mshvsf c:mshvsf
		DRIVER(mshvsfu1d) //t:mshvsfu1d f:cps2.c r:mshvsf c:mshvsf
//SET: csclub
		DRIVER(csclub) //t:csclub f:cps2.c r: c:
		DRIVER(csclub1) //t:csclub1 f:cps2.c r:csclub c:csclub
		DRIVER(csclubj) //t:csclubj f:cps2.c r:csclub c:csclub
		DRIVER(cscluba) //t:cscluba f:cps2.c r:csclub c:csclub
		DRIVER(csclubh) //t:csclubh f:cps2.c r:csclub c:csclub
		DRIVER(csclub1d) //t:csclub1d f:cps2.c r:csclub c:csclub
//SET: sgemf
		DRIVER(sgemf) //t:sgemf f:cps2.c r: c:
		DRIVER(pfghtj) //t:pfghtj f:cps2.c r:sgemf c:sgemf
		DRIVER(sgemfa) //t:sgemfa f:cps2.c r:sgemf c:sgemf
		DRIVER(sgemfh) //t:sgemfh f:cps2.c r:sgemf c:sgemf
		DRIVER(sgemfd) //t:sgemfd f:cps2.c r:sgemf c:sgemf
//SET: vhunt2
		DRIVER(vhunt2) //t:vhunt2 f:cps2.c r: c:
		DRIVER(vhunt2r1) //t:vhunt2r1 f:cps2.c r:vhunt2 c:vhunt2
		DRIVER(vhunt2d) //t:vhunt2d f:cps2.c r:vhunt2 c:vhunt2
//SET: vsav2
		DRIVER(vsav2) //t:vsav2 f:cps2.c r: c:
		DRIVER(vsav2d) //t:vsav2d f:cps2.c r:vsav2 c:vsav2
//SET: mvsc
		DRIVER(mvsc) //t:mvsc f:cps2.c r: c:
		DRIVER(mvscr1) //t:mvscr1 f:cps2.c r:mvsc c:mvsc
		DRIVER(mvscu) //t:mvscu f:cps2.c r:mvsc c:mvsc
		DRIVER(mvscur1) //t:mvscur1 f:cps2.c r:mvsc c:mvsc
		DRIVER(mvscj) //t:mvscj f:cps2.c r:mvsc c:mvsc
		DRIVER(mvscjr1) //t:mvscjr1 f:cps2.c r:mvsc c:mvsc
		DRIVER(mvsca) //t:mvsca f:cps2.c r:mvsc c:mvsc
		DRIVER(mvscar1) //t:mvscar1 f:cps2.c r:mvsc c:mvsc
		DRIVER(mvsch) //t:mvsch f:cps2.c r:mvsc c:mvsc
		DRIVER(mvscb) //t:mvscb f:cps2.c r:mvsc c:mvsc
		DRIVER(mvscud) //t:mvscud f:cps2.c r:mvsc c:mvsc
//SET: sfa3
		DRIVER(sfa3) //t:sfa3 f:cps2.c r: c:
		DRIVER(sfa3u) //t:sfa3u f:cps2.c r:sfa3 c:sfa3
		DRIVER(sfa3ur1) //t:sfa3ur1 f:cps2.c r:sfa3 c:sfa3
		DRIVER(sfa3h) //t:sfa3h f:cps2.c r:sfa3 c:sfa3
		DRIVER(sfa3hr1) //t:sfa3hr1 f:cps2.c r:sfa3 c:sfa3
		DRIVER(sfa3b) //t:sfa3b f:cps2.c r:sfa3 c:sfa3
		DRIVER(sfz3j) //t:sfz3j f:cps2.c r:sfa3 c:sfa3
		DRIVER(sfz3jr1) //t:sfz3jr1 f:cps2.c r:sfa3 c:sfa3
		DRIVER(sfz3jr2) //t:sfz3jr2 f:cps2.c r:sfa3 c:sfa3
		DRIVER(sfz3a) //t:sfz3a f:cps2.c r:sfa3 c:sfa3
		DRIVER(sfz3ar1) //t:sfz3ar1 f:cps2.c r:sfa3 c:sfa3
		DRIVER(sfa3ud) //t:sfa3ud f:cps2.c r:sfa3 c:sfa3
		DRIVER(sfz3jr2d) //t:sfz3jr2d f:cps2.c r:sfa3 c:sfa3
//SET: gigawing
		DRIVER(gigawing) //t:gigawing f:cps2.c r: c:
		DRIVER(gigawingj) //t:gigawingj f:cps2.c r:gigawing c:gigawing
		DRIVER(gigawinga) //t:gigawinga f:cps2.c r:gigawing c:gigawing
		DRIVER(gigawingh) //t:gigawingh f:cps2.c r:gigawing c:gigawing
		DRIVER(gigawingb) //t:gigawingb f:cps2.c r:gigawing c:gigawing
		DRIVER(gigawingd) //t:gigawingd f:cps2.c r:gigawing c:gigawing
		DRIVER(gigawingjd) //t:gigawingjd f:cps2.c r:gigawing c:gigawing
//SET: jyangoku
		DRIVER(jyangoku) //t:jyangoku f:cps2.c r: c:
//SET: dimahoo
		DRIVER(dimahoo) //t:dimahoo f:cps2.c r: c:
		DRIVER(dimahoou) //t:dimahoou f:cps2.c r:dimahoo c:dimahoo
		DRIVER(gmahou) //t:gmahou f:cps2.c r:dimahoo c:dimahoo
		DRIVER(dimahoud) //t:dimahoud f:cps2.c r:dimahoo c:dimahoo
//SET: mmatrix
		DRIVER(mmatrix) //t:mmatrix f:cps2.c r: c:
		DRIVER(mmatrixj) //t:mmatrixj f:cps2.c r:mmatrix c:mmatrix
		DRIVER(mmatrixd) //t:mmatrixd f:cps2.c r:mmatrix c:mmatrix
//SET: 1944
		DRIVER(1944) //t:1944 f:cps2.c r: c:
		DRIVER(1944j) //t:1944j f:cps2.c r:1944 c:1944
		DRIVER(1944d) //t:1944d f:cps2.c r:1944 c:1944
//SET: mpang
		DRIVER(mpang) //t:mpang f:cps2.c r: c:
		DRIVER(mpangr1) //t:mpangr1 f:cps2.c r:mpang c:mpang
		DRIVER(mpangu) //t:mpangu f:cps2.c r:mpang c:mpang
		DRIVER(mpangj) //t:mpangj f:cps2.c r:mpang c:mpang
//SET: progear
		DRIVER(progear) //t:progear f:cps2.c r: c:
		DRIVER(progearj) //t:progearj f:cps2.c r:progear c:progear
		DRIVER(progeara) //t:progeara f:cps2.c r:progear c:progear
		DRIVER(progearud) //t:progearud f:cps2.c r:progear c:progear
		DRIVER(progearjd) //t:progearjd f:cps2.c r:progear c:progear
		DRIVER(progearjbl) //t:progearjbl f:cps2.c r:progear c:progear
//SET: pzloop2
		DRIVER(pzloop2) //t:pzloop2 f:cps2.c r: c:
		DRIVER(pzloop2j) //t:pzloop2j f:cps2.c r:pzloop2 c:pzloop2
//SET: choko
		DRIVER(choko) //t:choko f:cps2.c r: c:
//SET: hsf2
		DRIVER(hsf2) //t:hsf2 f:cps2.c r: c:
		DRIVER(hsf2j) //t:hsf2j f:cps2.c r:hsf2 c:hsf2
		DRIVER(hsf2a) //t:hsf2a f:cps2.c r:hsf2 c:hsf2
		DRIVER(hsf2d) //t:hsf2d f:cps2.c r:hsf2 c:hsf2
//SET: redearth
		DRIVER(redearth) //t:redearth f:cps3.c r: c:
		DRIVER(redeartha) //t:redeartha f:cps3.c r:redearth c:redearth
		DRIVER(warzard) //t:warzard f:cps3.c r:redearth c:redearth
		DRIVER(warzarda) //t:warzarda f:cps3.c r:redearth c:redearth
//SET: sfiii
		DRIVER(sfiii) //t:sfiii f:cps3.c r: c:
		DRIVER(sfiiij) //t:sfiiij f:cps3.c r:sfiii c:sfiii
		DRIVER(sfiiin) //t:sfiiin f:cps3.c r:sfiii c:sfiii
//SET: sfiii2
		DRIVER(sfiii2) //t:sfiii2 f:cps3.c r: c:
		DRIVER(sfiii2j) //t:sfiii2j f:cps3.c r:sfiii2 c:sfiii2
		DRIVER(sfiii2n) //t:sfiii2n f:cps3.c r:sfiii2 c:sfiii2
//SET: jojo
		DRIVER(jojo) //t:jojo f:cps3.c r: c:
		DRIVER(jojoa) //t:jojoa f:cps3.c r:jojo c:jojo
		DRIVER(jojoj) //t:jojoj f:cps3.c r:jojo c:jojo
		DRIVER(jojoaj) //t:jojoaj f:cps3.c r:jojo c:jojo
		DRIVER(jojon) //t:jojon f:cps3.c r:jojo c:jojo
		DRIVER(jojoan) //t:jojoan f:cps3.c r:jojo c:jojo
//SET: sfiii3
		DRIVER(sfiii3) //t:sfiii3 f:cps3.c r: c:
		DRIVER(sfiii3a) //t:sfiii3a f:cps3.c r:sfiii3 c:sfiii3
		DRIVER(sfiii3n) //t:sfiii3n f:cps3.c r:sfiii3 c:sfiii3
		DRIVER(sfiii3an) //t:sfiii3an f:cps3.c r:sfiii3 c:sfiii3
//SET: jojoba
		DRIVER(jojoba) //t:jojoba f:cps3.c r: c:
		DRIVER(jojoban) //t:jojoban f:cps3.c r:jojoba c:jojoba
		DRIVER(jojobane) //t:jojobane f:cps3.c r:jojoba c:jojoba
//SET: cpzn1
		DRIVER(cpzn1) //t:cpzn1 f:zn.c r: c:
//SET: ts2
		DRIVER(ts2) //t:ts2 f:zn.c r:cpzn1 c:
		DRIVER(ts2j) //t:ts2j f:zn.c r:ts2 c:ts2
//SET: starglad
		DRIVER(starglad) //t:starglad f:zn.c r:cpzn1 c:
		DRIVER(stargladj) //t:stargladj f:zn.c r:starglad c:starglad
//SET: sfex
		DRIVER(sfex) //t:sfex f:zn.c r:cpzn1 c:
		DRIVER(sfexu) //t:sfexu f:zn.c r:sfex c:sfex
		DRIVER(sfexa) //t:sfexa f:zn.c r:sfex c:sfex
		DRIVER(sfexj) //t:sfexj f:zn.c r:sfex c:sfex
//SET: glpracr
		DRIVER(glpracr) //t:glpracr f:zn.c r:cpzn1 c:
//SET: sfexp
		DRIVER(sfexp) //t:sfexp f:zn.c r:cpzn1 c:
		DRIVER(sfexpu1) //t:sfexpu1 f:zn.c r:sfexp c:sfexp
		DRIVER(sfexpj) //t:sfexpj f:zn.c r:sfexp c:sfexp
//SET: cpzn2
		DRIVER(cpzn2) //t:cpzn2 f:zn.c r: c:
//SET: rvschool
		DRIVER(rvschool) //t:rvschool f:zn.c r:cpzn2 c:
		DRIVER(rvschoola) //t:rvschoola f:zn.c r:rvschool c:rvschool
		DRIVER(jgakuen) //t:jgakuen f:zn.c r:rvschool c:rvschool
//SET: sfex2
		DRIVER(sfex2) //t:sfex2 f:zn.c r:cpzn2 c:
		DRIVER(sfex2j) //t:sfex2j f:zn.c r:sfex2 c:sfex2
		DRIVER(sfex2a) //t:sfex2a f:zn.c r:sfex2 c:sfex2
		DRIVER(sfex2h) //t:sfex2h f:zn.c r:sfex2 c:sfex2
//SET: plsmaswd
		DRIVER(plsmaswd) //t:plsmaswd f:zn.c r:cpzn2 c:
		DRIVER(stargld2) //t:stargld2 f:zn.c r:plsmaswd c:plsmaswd
		DRIVER(plsmaswda) //t:plsmaswda f:zn.c r:plsmaswd c:plsmaswd
//SET: tgmj
		DRIVER(tgmj) //t:tgmj f:zn.c r:cpzn2 c:
//SET: techromn
		DRIVER(techromn) //t:techromn f:zn.c r:cpzn2 c:
		DRIVER(techromnu) //t:techromnu f:zn.c r:techromn c:techromn
		DRIVER(kikaioh) //t:kikaioh f:zn.c r:techromn c:techromn
//SET: sfex2p
		DRIVER(sfex2p) //t:sfex2p f:zn.c r:cpzn2 c:
		DRIVER(sfex2pa) //t:sfex2pa f:zn.c r:sfex2p c:sfex2p
		DRIVER(sfex2pj) //t:sfex2pj f:zn.c r:sfex2p c:sfex2p
//SET: strider2
		DRIVER(strider2) //t:strider2 f:zn.c r:cpzn2 c:
		DRIVER(strider2a) //t:strider2a f:zn.c r:strider2 c:strider2
		DRIVER(shiryu2) //t:shiryu2 f:zn.c r:strider2 c:strider2
//SET: tps
		DRIVER(tps) //t:tps f:zn.c r: c:
//SET: glpracr2
		DRIVER(glpracr2) //t:glpracr2 f:zn.c r:tps c:
		DRIVER(glpracr2j) //t:glpracr2j f:zn.c r:glpracr2 c:glpracr2
		DRIVER(glpracr2l) //t:glpracr2l f:zn.c r:glpracr2 c:glpracr2
//SET: doapp
		DRIVER(doapp) //t:doapp f:zn.c r:tps c:
//SET: cbaj
		DRIVER(cbaj) //t:cbaj f:zn.c r:tps c:
//SET: shngmtkb
		DRIVER(shngmtkb) //t:shngmtkb f:zn.c r:tps c:
//SET: tondemo
		DRIVER(tondemo) //t:tondemo f:zn.c r:tps c:
//SET: glpracr3
		DRIVER(glpracr3) //t:glpracr3 f:zn.c r:tps c:
#endif

#ifdef PS3_SET_6
//SET: flamegun
		DRIVER(flamegun) //t:flamegun f:zn.c r:tps c:
		DRIVER(flamegunj) //t:flamegunj f:zn.c r:flamegun c:flamegun
//SET: lpadv
		DRIVER(lpadv) //t:lpadv f:zn.c r:tps c:
//SET: tblkkuzu
		DRIVER(tblkkuzu) //t:tblkkuzu f:zn.c r:tps c:
//SET: 1on1gov
		DRIVER(1on1gov) //t:1on1gov f:zn.c r:tps c:
//SET: tecmowcm
		DRIVER(tecmowcm) //t:tecmowcm f:zn.c r:tps c:
//SET: mfjump
		DRIVER(mfjump) //t:mfjump f:zn.c r:tps c:
//SET: atluspsx
		DRIVER(atluspsx) //t:atluspsx f:zn.c r: c:
//SET: hvnsgate
		DRIVER(hvnsgate) //t:hvnsgate f:zn.c r:atluspsx c:
//SET: psarc95
		DRIVER(psarc95) //t:psarc95 f:zn.c r: c:
//SET: beastrzr
		DRIVER(beastrzr) //t:beastrzr f:zn.c r:psarc95 c:
		DRIVER(bldyroar) //t:bldyroar f:zn.c r:beastrzr c:beastrzr
//SET: beastrzb
		DRIVER(beastrzb) //t:beastrzb f:zn.c r:psarc95 c:
//SET: bldyror2
		DRIVER(bldyror2) //t:bldyror2 f:zn.c r:psarc95 c:
		DRIVER(bldyror2u) //t:bldyror2u f:zn.c r:bldyror2 c:bldyror2
		DRIVER(bldyror2a) //t:bldyror2a f:zn.c r:bldyror2 c:bldyror2
		DRIVER(bldyror2j) //t:bldyror2j f:zn.c r:bldyror2 c:bldyror2
//SET: brvblade
		DRIVER(brvblade) //t:brvblade f:zn.c r:tps c:
		DRIVER(brvbladeu) //t:brvbladeu f:zn.c r:brvblade c:brvblade
		DRIVER(brvbladea) //t:brvbladea f:zn.c r:brvblade c:brvblade
		DRIVER(brvbladej) //t:brvbladej f:zn.c r:brvblade c:brvblade
//SET: bam2
		DRIVER(bam2) //t:bam2 f:zn.c r:psarc95 c:
//SET: atpsx
		DRIVER(atpsx) //t:atpsx f:zn.c r: c:
//SET: primrag2
		DRIVER(primrag2) //t:primrag2 f:zn.c r:atpsx c:
//SET: acpsx
		DRIVER(acpsx) //t:acpsx f:zn.c r: c:
//SET: nbajamex
		DRIVER(nbajamex) //t:nbajamex f:zn.c r:acpsx c:
//SET: jdredd
		DRIVER(jdredd) //t:jdredd f:zn.c r:acpsx c:
		DRIVER(jdreddb) //t:jdreddb f:zn.c r:jdredd c:jdredd
//SET: vspsx
		DRIVER(vspsx) //t:vspsx f:zn.c r: c:
//SET: aerofgts
		DRIVER(aerofgts) //t:aerofgts f:zn.c r:vspsx c:
		DRIVER(sncwgltd) //t:sncwgltd f:zn.c r:aerofgts c:aerofgts
//SET: taitofx1
		DRIVER(taitofx1) //t:taitofx1 f:zn.c r: c:
//SET: sfchamp
		DRIVER(sfchamp) //t:sfchamp f:zn.c r:taitofx1 c:
		DRIVER(sfchamp24o) //t:sfchamp24o f:zn.c r:sfchamp c:sfchamp
		DRIVER(sfchampj) //t:sfchampj f:zn.c r:sfchamp c:sfchamp
//SET: psyforce
		DRIVER(psyforce) //t:psyforce f:zn.c r:taitofx1 c:
		DRIVER(psyforcej) //t:psyforcej f:zn.c r:psyforce c:psyforce
		DRIVER(psyforcex) //t:psyforcex f:zn.c r:psyforce c:psyforce
//SET: mgcldtex
		DRIVER(mgcldtex) //t:mgcldtex f:zn.c r:taitofx1 c:
		DRIVER(mgcldate) //t:mgcldate f:zn.c r:mgcldtex c:mgcldtex
//SET: raystorm
		DRIVER(raystorm) //t:raystorm f:zn.c r:taitofx1 c:
		DRIVER(raystormj) //t:raystormj f:zn.c r:raystorm c:raystorm
//SET: ftimpcta
		DRIVER(ftimpcta) //t:ftimpcta f:zn.c r:taitofx1 c:
		DRIVER(ftimpact) //t:ftimpact f:zn.c r:ftimpcta c:ftimpcta
		DRIVER(ftimpactj) //t:ftimpactj f:zn.c r:ftimpcta c:ftimpcta
//SET: gdarius2
		DRIVER(gdarius2) //t:gdarius2 f:zn.c r:taitofx1 c:
		DRIVER(gdarius) //t:gdarius f:zn.c r:gdarius2 c:gdarius2
		DRIVER(gdariusb) //t:gdariusb f:zn.c r:gdarius2 c:gdarius2
//SET: taitogn
		DRIVER(taitogn) //t:taitogn f:taitogn.c r: c:
//SET: chaoshea
		DRIVER(chaoshea) //t:chaoshea f:taitogn.c r:taitogn c:
		DRIVER(chaosheaj) //t:chaosheaj f:taitogn.c r:chaoshea c:chaoshea
//SET: raycris
		DRIVER(raycris) //t:raycris f:taitogn.c r:taitogn c:
//SET: otenamih
		DRIVER(otenamih) //t:otenamih f:taitogn.c r:taitogn c:
//SET: otenamhf
		DRIVER(otenamhf) //t:otenamhf f:taitogn.c r:taitogn c:
//SET: spuzbobl
		DRIVER(spuzbobl) //t:spuzbobl f:taitogn.c r:taitogn c:
		DRIVER(spuzboblj) //t:spuzboblj f:taitogn.c r:spuzbobl c:spuzbobl
//SET: gobyrc
		DRIVER(gobyrc) //t:gobyrc f:taitogn.c r:taitogn c:
		DRIVER(rcdego) //t:rcdego f:taitogn.c r:gobyrc c:gobyrc
//SET: flipmaze
		DRIVER(flipmaze) //t:flipmaze f:taitogn.c r:taitogn c:
//SET: mahjngoh
		DRIVER(mahjngoh) //t:mahjngoh f:taitogn.c r:taitogn c:
//SET: psyvaria
		DRIVER(psyvaria) //t:psyvaria f:taitogn.c r:taitogn c:
//SET: shanghss
		DRIVER(shanghss) //t:shanghss f:taitogn.c r:taitogn c:
//SET: psyvarrv
		DRIVER(psyvarrv) //t:psyvarrv f:taitogn.c r:taitogn c:
//SET: zokuoten
		DRIVER(zokuoten) //t:zokuoten f:taitogn.c r:taitogn c:
//SET: soutenry
		DRIVER(soutenry) //t:soutenry f:taitogn.c r:taitogn c:
//SET: nightrai
		DRIVER(nightrai) //t:nightrai f:taitogn.c r:taitogn c:
//SET: shikigam
		DRIVER(shikigam) //t:shikigam f:taitogn.c r:taitogn c:
//SET: otenki
		DRIVER(otenki) //t:otenki f:taitogn.c r:taitogn c:
//SET: usagi
		DRIVER(usagi) //t:usagi f:taitogn.c r:taitogn c:
//SET: shangtou
		DRIVER(shangtou) //t:shangtou f:taitogn.c r:taitogn c:
//SET: xiistag
		DRIVER(xiistag) //t:xiistag f:taitogn.c r:taitogn c:
//SET: sianniv
		DRIVER(sianniv) //t:sianniv f:taitogn.c r:taitogn c:
//SET: kollon
		DRIVER(kollon) //t:kollon f:taitogn.c r:taitogn c:
		DRIVER(kollonc) //t:kollonc f:taitogn.c r:kollon c:kollon
//SET: zooo
		DRIVER(zooo) //t:zooo f:taitogn.c r:taitogn c:
//SET: tekken
		DRIVER(tekken) //t:tekken f:namcos11.c r: c:
		DRIVER(tekkena) //t:tekkena f:namcos11.c r:tekken c:tekken
		DRIVER(tekkenb) //t:tekkenb f:namcos11.c r:tekken c:tekken
		DRIVER(tekkenc) //t:tekkenc f:namcos11.c r:tekken c:tekken
//SET: tekken2
		DRIVER(tekken2) //t:tekken2 f:namcos11.c r: c:
		DRIVER(tekken2a) //t:tekken2a f:namcos11.c r:tekken2 c:tekken2
		DRIVER(tekken2b) //t:tekken2b f:namcos11.c r:tekken2 c:tekken2
//SET: primglex
		DRIVER(primglex) //t:primglex f:namcos11.c r: c:
//SET: xevi3dg
		DRIVER(xevi3dg) //t:xevi3dg f:namcos11.c r: c:
//SET: souledge
		DRIVER(souledge) //t:souledge f:namcos11.c r: c:
		DRIVER(souledge1) //t:souledge1 f:namcos11.c r:souledge c:souledge
		DRIVER(souledge1j) //t:souledge1j f:namcos11.c r:souledge c:souledge
		DRIVER(souledgea) //t:souledgea f:namcos11.c r:souledge c:souledge
//SET: dunkmnia
		DRIVER(dunkmnia) //t:dunkmnia f:namcos11.c r: c:
		DRIVER(dunkmniaj) //t:dunkmniaj f:namcos11.c r:dunkmnia c:dunkmnia
//SET: danceyes
		DRIVER(danceyes) //t:danceyes f:namcos11.c r: c:
//SET: pocketrc
		DRIVER(pocketrc) //t:pocketrc f:namcos11.c r: c:
//SET: starswep
		DRIVER(starswep) //t:starswep f:namcos11.c r: c:
//SET: myangel3
		DRIVER(myangel3) //t:myangel3 f:namcos11.c r: c:
//SET: tekken3
		DRIVER(tekken3) //t:tekken3 f:namcos12.c r: c:
		DRIVER(tekken3a) //t:tekken3a f:namcos12.c r:tekken3 c:tekken3
		DRIVER(tekken3b) //t:tekken3b f:namcos12.c r:tekken3 c:tekken3
		DRIVER(tekken3c) //t:tekken3c f:namcos12.c r:tekken3 c:tekken3
//SET: lbgrande
		DRIVER(lbgrande) //t:lbgrande f:namcos12.c r: c:
//SET: toukon3
		DRIVER(toukon3) //t:toukon3 f:namcos12.c r: c:
//SET: ehrgeiz
		DRIVER(ehrgeiz) //t:ehrgeiz f:namcos12.c r: c:
		DRIVER(ehrgeiza) //t:ehrgeiza f:namcos12.c r:ehrgeiz c:ehrgeiz
		DRIVER(ehrgeizj) //t:ehrgeizj f:namcos12.c r:ehrgeiz c:ehrgeiz
//SET: sws98
		DRIVER(sws98) //t:sws98 f:namcos12.c r: c:
//SET: soulclbr
		DRIVER(soulclbr) //t:soulclbr f:namcos12.c r: c:
		DRIVER(soulclbrb) //t:soulclbrb f:namcos12.c r:soulclbr c:soulclbr
		DRIVER(soulclbrj) //t:soulclbrj f:namcos12.c r:soulclbr c:soulclbr
		DRIVER(soulclbrb2) //t:soulclbrb2 f:namcos12.c r:soulclbr c:soulclbr
		DRIVER(soulclbrjb) //t:soulclbrjb f:namcos12.c r:soulclbr c:soulclbr
		DRIVER(soulclbrja) //t:soulclbrja f:namcos12.c r:soulclbr c:soulclbr
//SET: mdhorse
		DRIVER(mdhorse) //t:mdhorse f:namcos12.c r: c:
//SET: tenkomor
		DRIVER(tenkomor) //t:tenkomor f:namcos12.c r: c:
		DRIVER(tenkomorj) //t:tenkomorj f:namcos12.c r:tenkomor c:tenkomor
//SET: pacapp
		DRIVER(pacapp) //t:pacapp f:namcos12.c r: c:
//SET: fgtlayer
		DRIVER(fgtlayer) //t:fgtlayer f:namcos12.c r: c:
//SET: ptblank2
		DRIVER(ptblank2) //t:ptblank2 f:namcos12.c r: c:
		DRIVER(ptblank2a) //t:ptblank2a f:namcos11.c r:ptblank2 c:ptblank2
//SET: sws99
		DRIVER(sws99) //t:sws99 f:namcos12.c r: c:
//SET: ghlpanic
		DRIVER(ghlpanic) //t:ghlpanic f:namcos12.c r: c:
//SET: pacapp2
		DRIVER(pacapp2) //t:pacapp2 f:namcos12.c r: c:
//SET: tektagt
		DRIVER(tektagt) //t:tektagt f:namcos12.c r: c:
		DRIVER(tektagta) //t:tektagta f:namcos12.c r:tektagt c:tektagt
		DRIVER(tektagtb) //t:tektagtb f:namcos12.c r:tektagt c:tektagt
		DRIVER(tektagtc) //t:tektagtc f:namcos12.c r:tektagt c:tektagt
//SET: mrdrillr
		DRIVER(mrdrillr) //t:mrdrillr f:namcos12.c r: c:
//SET: pacappsp
		DRIVER(pacappsp) //t:pacappsp f:namcos12.c r: c:
//SET: kaiunqz
		DRIVER(kaiunqz) //t:kaiunqz f:namcos12.c r: c:
//SET: aquarush
		DRIVER(aquarush) //t:aquarush f:namcos12.c r: c:
//SET: golgo13
		DRIVER(golgo13) //t:golgo13 f:namcos12.c r: c:
//SET: sws2000
		DRIVER(sws2000) //t:sws2000 f:namcos12.c r: c:
		DRIVER(sws2001) //t:sws2001 f:namcos12.c r:sws2000 c:sws2000
//SET: truckk
		DRIVER(truckk) //t:truckk f:namcos12.c r: c:
//SET: g13knd
		DRIVER(g13knd) //t:g13knd f:namcos12.c r: c:
//SET: mrdrilr2
		DRIVER(mrdrilr2) //t:mrdrilr2 f:namcos10.c r: c:
		DRIVER(mrdrlr2a) //t:mrdrlr2a f:namcos10.c r:mrdrilr2 c:mrdrilr2
//SET: ptblank3
		DRIVER(ptblank3) //t:ptblank3 f:namcos10.c r: c:
//SET: mrdrilrg
		DRIVER(mrdrilrg) //t:mrdrilrg f:namcos10.c r: c:
//SET: knpuzzle
		DRIVER(knpuzzle) //t:knpuzzle f:namcos10.c r: c:
//SET: gjspace
		DRIVER(gjspace) //t:gjspace f:namcos10.c r: c:
//SET: startrgn
		DRIVER(startrgn) //t:startrgn f:namcos10.c r: c:
//SET: gamshara
		DRIVER(gamshara) //t:gamshara f:namcos10.c r: c:
//SET: chocovdr
		DRIVER(chocovdr) //t:chocovdr f:namcos10.c r: c:
//SET: cryptklr
		DRIVER(cryptklr) //t:cryptklr f:konamigq.c r: c:
//SET: konamigv
		DRIVER(konamigv) //t:konamigv f:konamigv.c r: c:
//SET: kdeadeye
		DRIVER(kdeadeye) //t:kdeadeye f:konamigv.c r:konamigv c:
//SET: pbball96
		DRIVER(pbball96) //t:pbball96 f:konamigv.c r:konamigv c:
//SET: hyperath
		DRIVER(hyperath) //t:hyperath f:konamigv.c r:konamigv c:
//SET: susume
		DRIVER(susume) //t:susume f:konamigv.c r:konamigv c:
//SET: btchamp
		DRIVER(btchamp) //t:btchamp f:konamigv.c r:konamigv c:
//SET: weddingr
		DRIVER(weddingr) //t:weddingr f:konamigv.c r:konamigv c:
//SET: tokimosh
		DRIVER(tokimosh) //t:tokimosh f:konamigv.c r:konamigv c:
//SET: tokimosp
		DRIVER(tokimosp) //t:tokimosp f:konamigv.c r:konamigv c:
//SET: nagano98
		DRIVER(nagano98) //t:nagano98 f:konamigv.c r:konamigv c:
//SET: simpbowl
		DRIVER(simpbowl) //t:simpbowl f:konamigv.c r:konamigv c:
//SET: sys573
		DRIVER(sys573) //t:sys573 f:ksys573.c r: c:
//SET: darkhleg
		DRIVER(darkhleg) //t:darkhleg f:ksys573.c r:sys573 c:
//SET: fbaitbc
		DRIVER(fbaitbc) //t:fbaitbc f:ksys573.c r:sys573 c:
		DRIVER(bassangl) //t:bassangl f:ksys573.c r:fbaitbc c:fbaitbc
//SET: pbballex
		DRIVER(pbballex) //t:pbballex f:ksys573.c r:sys573 c:
//SET: konam80s
		DRIVER(konam80s) //t:konam80s f:ksys573.c r:sys573 c:
		DRIVER(konam80u) //t:konam80u f:ksys573.c r:konam80s c:konam80s
		DRIVER(konam80j) //t:konam80j f:ksys573.c r:konam80s c:konam80s
		DRIVER(konam80a) //t:konam80a f:ksys573.c r:konam80s c:konam80s
		DRIVER(konam80k) //t:konam80k f:ksys573.c r:konam80s c:konam80s
//SET: dstage
		DRIVER(dstage) //t:dstage f:ksys573.c r:sys573 c:
		DRIVER(ddru) //t:ddru f:ksys573.c r:dstage c:dstage
		DRIVER(ddrj) //t:ddrj f:ksys573.c r:dstage c:dstage
		DRIVER(ddrja) //t:ddrja f:ksys573.c r:dstage c:dstage
		DRIVER(ddrjb) //t:ddrjb f:ksys573.c r:dstage c:dstage
		DRIVER(ddra) //t:ddra f:ksys573.c r:dstage c:dstage
//SET: fbait2bc
		DRIVER(fbait2bc) //t:fbait2bc f:ksys573.c r:sys573 c:
		DRIVER(bassang2) //t:bassang2 f:ksys573.c r:fbait2bc c:fbait2bc
//SET: drmn
		DRIVER(drmn) //t:drmn f:ksys573.c r:sys573 c:
//SET: gtrfrks
		DRIVER(gtrfrks) //t:gtrfrks f:ksys573.c r:sys573 c:
		DRIVER(gtrfrksu) //t:gtrfrksu f:ksys573.c r:gtrfrks c:gtrfrks
		DRIVER(gtrfrksj) //t:gtrfrksj f:ksys573.c r:gtrfrks c:gtrfrks
		DRIVER(gtrfrksa) //t:gtrfrksa f:ksys573.c r:gtrfrks c:gtrfrks
//SET: fbaitmc
		DRIVER(fbaitmc) //t:fbaitmc f:ksys573.c r:sys573 c:
		DRIVER(fbaitmcu) //t:fbaitmcu f:ksys573.c r:fbaitmc c:fbaitmc
		DRIVER(fbaitmcj) //t:fbaitmcj f:ksys573.c r:fbaitmc c:fbaitmc
		DRIVER(fbaitmca) //t:fbaitmca f:ksys573.c r:fbaitmc c:fbaitmc
//SET: ddr2m
		DRIVER(ddr2m) //t:ddr2m f:ksys573.c r:sys573 c:
		DRIVER(ddr2ml) //t:ddr2ml f:ksys573.c r:ddr2m c:ddr2m
		DRIVER(ddr2mla) //t:ddr2mla f:ksys573.c r:ddr2m c:ddr2m
		DRIVER(ddrbocd) //t:ddrbocd f:ksys573.c r:ddr2m c:ddr2m
		DRIVER(ddr2mc) //t:ddr2mc f:ksys573.c r:ddr2m c:ddr2m
		DRIVER(ddr2mc2) //t:ddr2mc2 f:ksys573.c r:ddr2m c:ddr2m
//SET: gtrfrk2m
		DRIVER(gtrfrk2m) //t:gtrfrk2m f:ksys573.c r:sys573 c:
//SET: dsftkd
		DRIVER(dsftkd) //t:dsftkd f:ksys573.c r:sys573 c:
//SET: cr589fw
		DRIVER(cr589fw) //t:cr589fw f:ksys573.c r:sys573 c:
//SET: cr589fwa
		DRIVER(cr589fwa) //t:cr589fwa f:ksys573.c r:sys573 c:
//SET: ddr3mk
		DRIVER(ddr3mk) //t:ddr3mk f:ksys573.c r:sys573 c:
		DRIVER(ddr3mka) //t:ddr3mka f:ksys573.c r:ddr3mk c:ddr3mk
		DRIVER(ddr3ma) //t:ddr3ma f:ksys573.c r:ddr3mk c:ddr3mk
		DRIVER(ddr3mj) //t:ddr3mj f:ksys573.c r:ddr3mk c:ddr3mk
//SET: ddrsbm
		DRIVER(ddrsbm) //t:ddrsbm f:ksys573.c r:sys573 c:
//SET: ddrs2k
		DRIVER(ddrs2k) //t:ddrs2k f:ksys573.c r:sys573 c:
		DRIVER(ddrs2kj) //t:ddrs2kj f:ksys573.c r:ddrs2k c:ddrs2k
//SET: hyperbbc
		DRIVER(hyperbbc) //t:hyperbbc f:ksys573.c r:sys573 c:
		DRIVER(hyperbbck) //t:hyperbbck f:ksys573.c r:hyperbbc c:hyperbbc
//SET: dsfdct
		DRIVER(dsfdct) //t:dsfdct f:ksys573.c r:sys573 c:
		DRIVER(dsfdcta) //t:dsfdcta f:ksys573.c r:dsfdct c:dsfdct
//SET: drmn2m
		DRIVER(drmn2m) //t:drmn2m f:ksys573.c r:sys573 c:
		DRIVER(drmn2mpu) //t:drmn2mpu f:ksys573.c r:drmn2m c:drmn2m
//SET: dncfrks
		DRIVER(dncfrks) //t:dncfrks f:ksys573.c r:sys573 c:
		DRIVER(dmx) //t:dmx f:ksys573.c r:dncfrks c:dncfrks
//SET: gunmania
		DRIVER(gunmania) //t:gunmania f:ksys573.c r:sys573 c:
//SET: fghtmn
		DRIVER(fghtmn) //t:fghtmn f:ksys573.c r:sys573 c:
		DRIVER(fghtmna) //t:fghtmna f:ksys573.c r:fghtmn c:fghtmn
		DRIVER(pnchmn) //t:pnchmn f:ksys573.c r:fghtmn c:fghtmn
		DRIVER(pnchmna) //t:pnchmna f:ksys573.c r:fghtmn c:fghtmn
		DRIVER(fghtmnk) //t:fghtmnk f:ksys573.c r:fghtmn c:fghtmn
		DRIVER(fghtmnu) //t:fghtmnu f:ksys573.c r:fghtmn c:fghtmn
//SET: dsem
		DRIVER(dsem) //t:dsem f:ksys573.c r:sys573 c:
//SET: gtrfrk3m
		DRIVER(gtrfrk3m) //t:gtrfrk3m f:ksys573.c r:sys573 c:
		DRIVER(gtfrk3ma) //t:gtfrk3ma f:ksys573.c r:gtrfrk3m c:gtrfrk3m
		DRIVER(gtfrk3mb) //t:gtfrk3mb f:ksys573.c r:gtrfrk3m c:gtrfrk3m
//SET: pnchmn2
		DRIVER(pnchmn2) //t:pnchmn2 f:ksys573.c r:sys573 c:
//SET: salarymc
		DRIVER(salarymc) //t:salarymc f:ksys573.c r:sys573 c:
//SET: ddr3mp
		DRIVER(ddr3mp) //t:ddr3mp f:ksys573.c r:sys573 c:
//SET: pcnfrk3m
		DRIVER(pcnfrk3m) //t:pcnfrk3m f:ksys573.c r:sys573 c:
		DRIVER(drmn3m) //t:drmn3m f:ksys573.c r:pcnfrk3m c:pcnfrk3m
//SET: gtrfrk4m
		DRIVER(gtrfrk4m) //t:gtrfrk4m f:ksys573.c r:sys573 c:
//SET: drmn4m
		DRIVER(drmn4m) //t:drmn4m f:ksys573.c r:sys573 c:
//SET: ddr4m
		DRIVER(ddr4m) //t:ddr4m f:ksys573.c r:sys573 c:
		DRIVER(ddr4mj) //t:ddr4mj f:ksys573.c r:ddr4m c:ddr4m
//SET: ddr4ms
		DRIVER(ddr4ms) //t:ddr4ms f:ksys573.c r:sys573 c:
		DRIVER(ddr4msj) //t:ddr4msj f:ksys573.c r:ddr4ms c:ddr4ms
//SET: dsfdr
		DRIVER(dsfdr) //t:dsfdr f:ksys573.c r:sys573 c:
//SET: ddrusa
		DRIVER(ddrusa) //t:ddrusa f:ksys573.c r:sys573 c:
//SET: ddr4mp
		DRIVER(ddr4mp) //t:ddr4mp f:ksys573.c r:sys573 c:
//SET: ddr4mps
		DRIVER(ddr4mps) //t:ddr4mps f:ksys573.c r:sys573 c:
//SET: dmx2m
		DRIVER(dmx2m) //t:dmx2m f:ksys573.c r:sys573 c:
//SET: gtrfrk5m
		DRIVER(gtrfrk5m) //t:gtrfrk5m f:ksys573.c r:sys573 c:
//SET: ddr5m
		DRIVER(ddr5m) //t:ddr5m f:ksys573.c r:sys573 c:
//SET: dmx2majp
		DRIVER(dmx2majp) //t:dmx2majp f:ksys573.c r:sys573 c:
//SET: mamboagg
		DRIVER(mamboagg) //t:mamboagg f:ksys573.c r:sys573 c:
//SET: drmn5m
		DRIVER(drmn5m) //t:drmn5m f:ksys573.c r:sys573 c:
//SET: gtrfrk6m
		DRIVER(gtrfrk6m) //t:gtrfrk6m f:ksys573.c r:sys573 c:
//SET: drmn6m
		DRIVER(drmn6m) //t:drmn6m f:ksys573.c r:sys573 c:
//SET: gtrfrk7m
		DRIVER(gtrfrk7m) //t:gtrfrk7m f:ksys573.c r:sys573 c:
//SET: ddrmax
		DRIVER(ddrmax) //t:ddrmax f:ksys573.c r:sys573 c:
//SET: ddrmax2
		DRIVER(ddrmax2) //t:ddrmax2 f:ksys573.c r:sys573 c:
//SET: mrtlbeat
		DRIVER(mrtlbeat) //t:mrtlbeat f:ksys573.c r:sys573 c:
//SET: drmn7m
		DRIVER(drmn7m) //t:drmn7m f:ksys573.c r:sys573 c:
		DRIVER(drmn7ma) //t:drmn7ma f:ksys573.c r:drmn7m c:drmn7m
//SET: gtrfrk8m
		DRIVER(gtrfrk8m) //t:gtrfrk8m f:ksys573.c r:sys573 c:
		DRIVER(gtrfrk8ma) //t:gtrfrk8ma f:ksys573.c r:gtrfrk8m c:gtrfrk8m
//SET: dsem2
		DRIVER(dsem2) //t:dsem2 f:ksys573.c r:sys573 c:
//SET: ddrextrm
		DRIVER(ddrextrm) //t:ddrextrm f:ksys573.c r:sys573 c:
//SET: drmn8m
		DRIVER(drmn8m) //t:drmn8m f:ksys573.c r:sys573 c:
//SET: gtrfrk9m
		DRIVER(gtrfrk9m) //t:gtrfrk9m f:ksys573.c r:sys573 c:
//SET: drmn9m
		DRIVER(drmn9m) //t:drmn9m f:ksys573.c r:sys573 c:
//SET: gtfrk10m
		DRIVER(gtfrk10m) //t:gtfrk10m f:ksys573.c r:sys573 c:
		DRIVER(gtfrk10ma) //t:gtfrk10ma f:ksys573.c r:gtfrk10m c:gtfrk10m
		DRIVER(gtfrk10mb) //t:gtfrk10mb f:ksys573.c r:gtfrk10m c:gtfrk10m
//SET: gtfrk11m
		DRIVER(gtfrk11m) //t:gtfrk11m f:ksys573.c r:sys573 c:
//SET: drmn10m
		DRIVER(drmn10m) //t:drmn10m f:ksys573.c r:sys573 c:
//SET: gq863
		DRIVER(gq863) //t:gq863 f:twinkle.c r: c:
//SET: bmiidx
		DRIVER(bmiidx) //t:bmiidx f:twinkle.c r:gq863 c:
//SET: bmiidxc
		DRIVER(bmiidxc) //t:bmiidxc f:twinkle.c r:gq863 c:
		DRIVER(bmiidxca) //t:bmiidxca f:twinkle.c r:bmiidxc c:bmiidxc
//SET: bmiidxc2
		DRIVER(bmiidxc2) //t:bmiidxc2 f:twinkle.c r:gq863 c:
//SET: bmiidx3
		DRIVER(bmiidx3) //t:bmiidx3 f:twinkle.c r:gq863 c:
//SET: bmiidx4
		DRIVER(bmiidx4) //t:bmiidx4 f:twinkle.c r:gq863 c:
//SET: bmiidx6
		DRIVER(bmiidx6) //t:bmiidx6 f:twinkle.c r:gq863 c:
//SET: bmiidx7
		DRIVER(bmiidx7) //t:bmiidx7 f:twinkle.c r:gq863 c:
//SET: bmiidx8
		DRIVER(bmiidx8) //t:bmiidx8 f:twinkle.c r:gq863 c:
//SET: kviper
		DRIVER(kviper) //t:kviper f:viper.c r: c:
//SET: ppp2nd
		DRIVER(ppp2nd) //t:ppp2nd f:viper.c r:kviper c:
//SET: boxingm
		DRIVER(boxingm) //t:boxingm f:viper.c r:kviper c:
//SET: code1d
		DRIVER(code1d) //t:code1d f:viper.c r:kviper c:
		DRIVER(code1db) //t:code1db f:viper.c r:code1d c:code1d
//SET: gticlub2
		DRIVER(gticlub2) //t:gticlub2 f:viper.c r:kviper c:
		DRIVER(gticlub2ea) //t:gticlub2ea f:viper.c r:gticlub2 c:gticlub2
//SET: jpark3
		DRIVER(jpark3) //t:jpark3 f:viper.c r:kviper c:
//SET: mocapglf
		DRIVER(mocapglf) //t:mocapglf f:viper.c r:kviper c:
//SET: mocapb
		DRIVER(mocapb) //t:mocapb f:viper.c r:kviper c:
		DRIVER(mocapbj) //t:mocapbj f:viper.c r:mocapb c:mocapb
//SET: p911
		DRIVER(p911) //t:p911 f:viper.c r:kviper c:
		DRIVER(p911uc) //t:p911uc f:viper.c r:p911 c:p911
		DRIVER(p911kc) //t:p911kc f:viper.c r:p911 c:p911
		DRIVER(p911e) //t:p911e f:viper.c r:p911 c:p911
		DRIVER(p911j) //t:p911j f:viper.c r:p911 c:p911
//SET: p9112
		DRIVER(p9112) //t:p9112 f:viper.c r:kviper c:
//SET: popn9
		DRIVER(popn9) //t:popn9 f:viper.c r:kviper c:
//SET: sscopex
		DRIVER(sscopex) //t:sscopex f:viper.c r:kviper c:
		DRIVER(sogeki) //t:sogeki f:viper.c r:sscopex c:sscopex
//SET: thrild2
		DRIVER(thrild2) //t:thrild2 f:viper.c r:kviper c:
		DRIVER(thrild2a) //t:thrild2a f:viper.c r:thrild2 c:thrild2
		DRIVER(thrild2c) //t:thrild2c f:viper.c r:thrild2 c:thrild2
//SET: tsurugi
		DRIVER(tsurugi) //t:tsurugi f:viper.c r:kviper c:
		DRIVER(tsurugij) //t:tsurugij f:viper.c r:tsurugi c:tsurugi
//SET: wcombat
		DRIVER(wcombat) //t:wcombat f:viper.c r:kviper c:
		DRIVER(wcombatk) //t:wcombatk f:viper.c r:wcombat c:wcombat
		DRIVER(wcombatj) //t:wcombatj f:viper.c r:wcombat c:wcombat
//SET: xtrial
		DRIVER(xtrial) //t:xtrial f:viper.c r:kviper c:
//SET: mfightc
		DRIVER(mfightc) //t:mfightc f:viper.c r:kviper c:
		DRIVER(mfightcc) //t:mfightcc f:viper.c r:mfightc c:mfightc
//SET: mgakuen
		DRIVER(mgakuen) //t:mgakuen f:mitchell.c r: c:
		DRIVER(7toitsu) //t:7toitsu f:mitchell.c r:mgakuen c:mgakuen
//SET: mgakuen2
		DRIVER(mgakuen2) //t:mgakuen2 f:mitchell.c r: c:
//SET: pkladies
		DRIVER(pkladies) //t:pkladies f:mitchell.c r: c:
		DRIVER(pkladiesl) //t:pkladiesl f:mitchell.c r:pkladies c:pkladies
		DRIVER(pkladiesla) //t:pkladiesla f:mitchell.c r:pkladies c:pkladies
		DRIVER(pkladiesbl) //t:pkladiesbl f:mitchell.c r:pkladies c:pkladies
//SET: dokaben
		DRIVER(dokaben) //t:dokaben f:mitchell.c r: c:
//SET: pang
		DRIVER(pang) //t:pang f:mitchell.c r: c:
		DRIVER(pangb) //t:pangb f:mitchell.c r:pang c:pang
		DRIVER(pangbold) //t:pangbold f:mitchell.c r:pang c:pang
		DRIVER(pangba) //t:pangba f:mitchell.c r:pang c:pang
		DRIVER(bbros) //t:bbros f:mitchell.c r:pang c:pang
		DRIVER(pompingw) //t:pompingw f:mitchell.c r:pang c:pang
//SET: cbasebal
		DRIVER(cbasebal) //t:cbasebal f:cbasebal.c r: c:
//SET: cworld
		DRIVER(cworld) //t:cworld f:mitchell.c r: c:
//SET: hatena
		DRIVER(hatena) //t:hatena f:mitchell.c r: c:
//SET: spang
		DRIVER(spang) //t:spang f:mitchell.c r: c:
		DRIVER(spangj) //t:spangj f:mitchell.c r:spang c:spang
		DRIVER(spangbl) //t:spangbl f:mitchell.c r:spang c:spang
		DRIVER(sbbros) //t:sbbros f:mitchell.c r:spang c:spang
//SET: marukin
		DRIVER(marukin) //t:marukin f:mitchell.c r: c:
//SET: qtono1
		DRIVER(qtono1) //t:qtono1 f:mitchell.c r: c:
//SET: qsangoku
		DRIVER(qsangoku) //t:qsangoku f:mitchell.c r: c:
//SET: block
		DRIVER(block) //t:block f:mitchell.c r: c:
		DRIVER(blockj) //t:blockj f:mitchell.c r:block c:block
		DRIVER(blockjoy) //t:blockjoy f:mitchell.c r:block c:block
		DRIVER(blockbl) //t:blockbl f:mitchell.c r:block c:block
//SET: capbowl
		DRIVER(capbowl) //t:capbowl f:capbowl.c r: c:
		DRIVER(capbowl2) //t:capbowl2 f:capbowl.c r:capbowl c:capbowl
		DRIVER(capbowl3) //t:capbowl3 f:capbowl.c r:capbowl c:capbowl
		DRIVER(capbowl4) //t:capbowl4 f:capbowl.c r:capbowl c:capbowl
		DRIVER(clbowl) //t:clbowl f:capbowl.c r:capbowl c:capbowl
//SET: bowlrama
		DRIVER(bowlrama) //t:bowlrama f:capbowl.c r: c:
//SET: wfortune
		DRIVER(wfortune) //t:wfortune f:itech8.c r: c:
		DRIVER(wfortunea) //t:wfortunea f:itech8.c r:wfortune c:wfortune
//SET: grmatch
		DRIVER(grmatch) //t:grmatch f:itech8.c r: c:
//SET: stratab
		DRIVER(stratab) //t:stratab f:itech8.c r: c:
		DRIVER(stratab1) //t:stratab1 f:itech8.c r:stratab c:stratab
//SET: sstrike
		DRIVER(sstrike) //t:sstrike f:itech8.c r: c:
//SET: gtg
		DRIVER(gtg) //t:gtg f:itech8.c r: c:
		DRIVER(gtgt) //t:gtgt f:itech8.c r:gtg c:gtg
		DRIVER(gtgt1) //t:gtgt1 f:itech8.c r:gtg c:gtg
//SET: hstennis
		DRIVER(hstennis) //t:hstennis f:itech8.c r: c:
		DRIVER(hstennis10) //t:hstennis10 f:itech8.c r:hstennis c:hstennis
//SET: slikshot
		DRIVER(slikshot) //t:slikshot f:itech8.c r: c:
		DRIVER(slikshot17) //t:slikshot17 f:itech8.c r:slikshot c:slikshot
		DRIVER(slikshot16) //t:slikshot16 f:itech8.c r:slikshot c:slikshot
//SET: dynobop
		DRIVER(dynobop) //t:dynobop f:itech8.c r: c:
//SET: arlingtn
		DRIVER(arlingtn) //t:arlingtn f:itech8.c r: c:
//SET: peggle
		DRIVER(peggle) //t:peggle f:itech8.c r: c:
		DRIVER(pegglet) //t:pegglet f:itech8.c r:peggle c:peggle
//SET: pokrdice
		DRIVER(pokrdice) //t:pokrdice f:itech8.c r: c:
//SET: rimrockn
		DRIVER(rimrockn) //t:rimrockn f:itech8.c r: c:
		DRIVER(rimrockn20) //t:rimrockn20 f:itech8.c r:rimrockn c:rimrockn
		DRIVER(rimrockn16) //t:rimrockn16 f:itech8.c r:rimrockn c:rimrockn
		DRIVER(rimrockn12) //t:rimrockn12 f:itech8.c r:rimrockn c:rimrockn
//SET: ninclown
		DRIVER(ninclown) //t:ninclown f:itech8.c r: c:
//SET: gpgolf
		DRIVER(gpgolf) //t:gpgolf f:itech8.c r: c:
//SET: gtg2
		DRIVER(gtg2) //t:gtg2 f:itech8.c r: c:
		DRIVER(gtg2t) //t:gtg2t f:itech8.c r:gtg2 c:gtg2
		DRIVER(gtg2j) //t:gtg2j f:itech8.c r:gtg2 c:gtg2
//SET: neckneck
		DRIVER(neckneck) //t:neckneck f:itech8.c r: c:
//SET: timekill
		DRIVER(timekill) //t:timekill f:itech32.c r: c:
		DRIVER(timekill131) //t:timekill131 f:itech32.c r:timekill c:timekill
		DRIVER(timekill121) //t:timekill121 f:itech32.c r:timekill c:timekill
//SET: hardyard
		DRIVER(hardyard) //t:hardyard f:itech32.c r: c:
		DRIVER(hardyard10) //t:hardyard10 f:itech32.c r:hardyard c:hardyard
//SET: bloodstm
		DRIVER(bloodstm) //t:bloodstm f:itech32.c r: c:
		DRIVER(bloodstm22) //t:bloodstm22 f:itech32.c r:bloodstm c:bloodstm
		DRIVER(bloodstm21) //t:bloodstm21 f:itech32.c r:bloodstm c:bloodstm
		DRIVER(bloodstm11) //t:bloodstm11 f:itech32.c r:bloodstm c:bloodstm
//SET: pairs
		DRIVER(pairs) //t:pairs f:itech32.c r: c:
		DRIVER(pairsa) //t:pairsa f:itech32.c r:pairs c:pairs
		DRIVER(hotmemry) //t:hotmemry f:itech32.c r:pairs c:pairs
		DRIVER(hotmemry11) //t:hotmemry11 f:itech32.c r:pairs c:pairs
//SET: drivedge
		DRIVER(drivedge) //t:drivedge f:itech32.c r: c:
//SET: wcbowl
		DRIVER(wcbowl) //t:wcbowl f:itech32.c r: c:
		DRIVER(wcbowl165) //t:wcbowl165 f:itech32.c r:wcbowl c:wcbowl
		DRIVER(wcbowl161) //t:wcbowl161 f:itech32.c r:wcbowl c:wcbowl
		DRIVER(wcbowl16) //t:wcbowl16 f:itech32.c r:wcbowl c:wcbowl
		DRIVER(wcbowl15) //t:wcbowl15 f:itech32.c r:wcbowl c:wcbowl
		DRIVER(wcbowl14) //t:wcbowl14 f:itech32.c r:wcbowl c:wcbowl
		DRIVER(wcbowl13) //t:wcbowl13 f:itech32.c r:wcbowl c:wcbowl
		DRIVER(wcbowl12) //t:wcbowl12 f:itech32.c r:wcbowl c:wcbowl
//SET: sftm
		DRIVER(sftm) //t:sftm f:itech32.c r: c:
		DRIVER(sftm110) //t:sftm110 f:itech32.c r:sftm c:sftm
		DRIVER(sftm111) //t:sftm111 f:itech32.c r:sftm c:sftm
		DRIVER(sftmj) //t:sftmj f:itech32.c r:sftm c:sftm
//SET: shufshot
		DRIVER(shufshot) //t:shufshot f:itech32.c r: c:
		DRIVER(shufshot139) //t:shufshot139 f:itech32.c r:shufshot c:shufshot
		DRIVER(shufshot137) //t:shufshot137 f:itech32.c r:shufshot c:shufshot
//SET: wcbowldx
		DRIVER(wcbowldx) //t:wcbowldx f:itech32.c r: c:
		DRIVER(wcbowl140) //t:wcbowl140 f:itech32.c r:wcbowldx c:wcbowldx
//SET: gt3d
		DRIVER(gt3d) //t:gt3d f:itech32.c r: c:
		DRIVER(gt3dl192) //t:gt3dl192 f:itech32.c r:gt3d c:gt3d
		DRIVER(gt3dl191) //t:gt3dl191 f:itech32.c r:gt3d c:gt3d
		DRIVER(gt3ds192) //t:gt3ds192 f:itech32.c r:gt3d c:gt3d
		DRIVER(gt3dv18) //t:gt3dv18 f:itech32.c r:gt3d c:gt3d
		DRIVER(gt3dv17) //t:gt3dv17 f:itech32.c r:gt3d c:gt3d
		DRIVER(gt3dv16) //t:gt3dv16 f:itech32.c r:gt3d c:gt3d
		DRIVER(gt3dv15) //t:gt3dv15 f:itech32.c r:gt3d c:gt3d
		DRIVER(gt3dv14) //t:gt3dv14 f:itech32.c r:gt3d c:gt3d
		DRIVER(gt3dt231) //t:gt3dt231 f:itech32.c r:gt3d c:gt3d
		DRIVER(gt3dt211) //t:gt3dt211 f:itech32.c r:gt3d c:gt3d
//SET: gt97
		DRIVER(gt97) //t:gt97 f:itech32.c r: c:
		DRIVER(gt97v122) //t:gt97v122 f:itech32.c r:gt97 c:gt97
		DRIVER(gt97v121) //t:gt97v121 f:itech32.c r:gt97 c:gt97
		DRIVER(gt97s121) //t:gt97s121 f:itech32.c r:gt97 c:gt97
		DRIVER(gt97v120) //t:gt97v120 f:itech32.c r:gt97 c:gt97
		DRIVER(gt97t240) //t:gt97t240 f:itech32.c r:gt97 c:gt97
		DRIVER(gt97t243) //t:gt97t243 f:itech32.c r:gt97 c:gt97
//SET: gt98
		DRIVER(gt98) //t:gt98 f:itech32.c r: c:
		DRIVER(gt98v100) //t:gt98v100 f:itech32.c r:gt98 c:gt98
		DRIVER(gt98s100) //t:gt98s100 f:itech32.c r:gt98 c:gt98
		DRIVER(gt98t303) //t:gt98t303 f:itech32.c r:gt98 c:gt98
//SET: gt99
		DRIVER(gt99) //t:gt99 f:itech32.c r: c:
		DRIVER(gt99s100) //t:gt99s100 f:itech32.c r:gt99 c:gt99
		DRIVER(gt99t400) //t:gt99t400 f:itech32.c r:gt99 c:gt99
		DRIVER(gtroyal) //t:gtroyal f:itech32.c r:gt99 c:gt99
//SET: gt2k
		DRIVER(gt2k) //t:gt2k f:itech32.c r: c:
		DRIVER(gt2kp100) //t:gt2kp100 f:itech32.c r:gt2k c:gt2k
		DRIVER(gt2ks100) //t:gt2ks100 f:itech32.c r:gt2k c:gt2k
		DRIVER(gt2kt500) //t:gt2kt500 f:itech32.c r:gt2k c:gt2k
		DRIVER(gtsuprem) //t:gtsuprem f:itech32.c r:gt2k c:gt2k
//SET: gtclassc
		DRIVER(gtclassc) //t:gtclassc f:itech32.c r: c:
		DRIVER(gtclasscp) //t:gtclasscp f:itech32.c r:gtclassc c:gtclassc
		DRIVER(gtclasscs) //t:gtclasscs f:itech32.c r:gtclassc c:gtclassc
//SET: cerberus
		DRIVER(cerberus) //t:cerberus f:leland.c r: c:
//SET: mayhem
		DRIVER(mayhem) //t:mayhem f:leland.c r: c:
//SET: powrplay
		DRIVER(powrplay) //t:powrplay f:leland.c r: c:
//SET: wseries
		DRIVER(wseries) //t:wseries f:leland.c r: c:
//SET: alleymas
		DRIVER(alleymas) //t:alleymas f:leland.c r: c:
//SET: upyoural
		DRIVER(upyoural) //t:upyoural f:leland.c r: c:
//SET: dangerz
		DRIVER(dangerz) //t:dangerz f:leland.c r: c:
//SET: basebal2
		DRIVER(basebal2) //t:basebal2 f:leland.c r: c:
//SET: dblplay
		DRIVER(dblplay) //t:dblplay f:leland.c r: c:
//SET: strkzone
		DRIVER(strkzone) //t:strkzone f:leland.c r: c:
//SET: redlin2p
		DRIVER(redlin2p) //t:redlin2p f:leland.c r: c:
//SET: quarterb
		DRIVER(quarterb) //t:quarterb f:leland.c r: c:
		DRIVER(quarterba) //t:quarterba f:leland.c r:quarterb c:quarterb
//SET: viper
		DRIVER(viper) //t:viper f:leland.c r: c:
//SET: teamqb
		DRIVER(teamqb) //t:teamqb f:leland.c r: c:
		DRIVER(teamqb2) //t:teamqb2 f:leland.c r:teamqb c:teamqb
//SET: aafb
		DRIVER(aafb) //t:aafb f:leland.c r: c:
		DRIVER(aafbd2p) //t:aafbd2p f:leland.c r:aafb c:aafb
		DRIVER(aafbc) //t:aafbc f:leland.c r:aafb c:aafb
		DRIVER(aafbb) //t:aafbb f:leland.c r:aafb c:aafb
//SET: offroad
		DRIVER(offroad) //t:offroad f:leland.c r: c:
//SET: offroadt
		DRIVER(offroadt) //t:offroadt f:leland.c r: c:
		DRIVER(offroadt2p) //t:offroadt2p f:leland.c r:offroadt c:offroadt
//SET: pigout
		DRIVER(pigout) //t:pigout f:leland.c r: c:
		DRIVER(pigouta) //t:pigouta f:leland.c r:pigout c:pigout
//SET: ataxx
		DRIVER(ataxx) //t:ataxx f:ataxx.c r: c:
		DRIVER(ataxxa) //t:ataxxa f:ataxx.c r:ataxx c:ataxx
		DRIVER(ataxxe) //t:ataxxe f:ataxx.c r:ataxx c:ataxx
		DRIVER(ataxxj) //t:ataxxj f:ataxx.c r:ataxx c:ataxx
//SET: wsf
		DRIVER(wsf) //t:wsf f:ataxx.c r: c:
//SET: indyheat
		DRIVER(indyheat) //t:indyheat f:ataxx.c r: c:
//SET: brutforc
		DRIVER(brutforc) //t:brutforc f:ataxx.c r: c:
//SET: asylum
		DRIVER(asylum) //t:asylum f:ataxx.c r: c:
//SET: blockade
		DRIVER(blockade) //t:blockade f:blockade.c r: c:
//SET: comotion
		DRIVER(comotion) //t:comotion f:blockade.c r: c:
//SET: hustle
		DRIVER(hustle) //t:hustle f:blockade.c r: c:
//SET: blasto
		DRIVER(blasto) //t:blasto f:blockade.c r: c:
//SET: mineswpr
		DRIVER(mineswpr) //t:mineswpr f:blockade.c r: c:
		DRIVER(mineswpr4) //t:mineswpr4 f:blockade.c r:mineswpr c:mineswpr
//SET: depthch
		DRIVER(depthch) //t:depthch f:vicdual.c r: c:
		DRIVER(depthcho) //t:depthcho f:vicdual.c r:depthch c:depthch
		DRIVER(subhunt) //t:subhunt f:vicdual.c r:depthch c:depthch
//SET: safari
		DRIVER(safari) //t:safari f:vicdual.c r: c:
		DRIVER(safaria) //t:safaria f:vicdual.c r:safari c:safari
//SET: frogs
		DRIVER(frogs) //t:frogs f:vicdual.c r: c:
//SET: sspaceat
		DRIVER(sspaceat) //t:sspaceat f:vicdual.c r: c:
		DRIVER(sspaceat2) //t:sspaceat2 f:vicdual.c r:sspaceat c:sspaceat
		DRIVER(sspaceat3) //t:sspaceat3 f:vicdual.c r:sspaceat c:sspaceat
		DRIVER(sspaceatc) //t:sspaceatc f:vicdual.c r:sspaceat c:sspaceat
//SET: sspacaho
		DRIVER(sspacaho) //t:sspacaho f:vicdual.c r: c:
//SET: headon
		DRIVER(headon) //t:headon f:vicdual.c r: c:
		DRIVER(headonb) //t:headonb f:vicdual.c r:headon c:headon
		DRIVER(headons) //t:headons f:vicdual.c r:headon c:headon
		DRIVER(headonsa) //t:headonsa f:vicdual.c r:headon c:headon
		DRIVER(supcrash) //t:supcrash f:vicdual.c r:headon c:headon
//SET: headon2
		DRIVER(headon2) //t:headon2 f:vicdual.c r: c:
		DRIVER(headon2s) //t:headon2s f:vicdual.c r:headon2 c:headon2
		DRIVER(car2) //t:car2 f:vicdual.c r:headon2 c:headon2
//SET: invho2
		DRIVER(invho2) //t:invho2 f:vicdual.c r: c:
//SET: nsub
		DRIVER(nsub) //t:nsub f:vicdual.c r: c:
//SET: samurai
		DRIVER(samurai) //t:samurai f:vicdual.c r: c:
//SET: invinco
		DRIVER(invinco) //t:invinco f:vicdual.c r: c:
//SET: invds
		DRIVER(invds) //t:invds f:vicdual.c r: c:
//SET: tranqgun
		DRIVER(tranqgun) //t:tranqgun f:vicdual.c r: c:
//SET: spacetrk
		DRIVER(spacetrk) //t:spacetrk f:vicdual.c r: c:
		DRIVER(spacetrkc) //t:spacetrkc f:vicdual.c r:spacetrk c:spacetrk
//SET: carnival
		DRIVER(carnival) //t:carnival f:vicdual.c r: c:
		DRIVER(carnivalc) //t:carnivalc f:vicdual.c r:carnival c:carnival
		DRIVER(carnivalh) //t:carnivalh f:vicdual.c r:carnival c:carnival
		DRIVER(carnivalha) //t:carnivalha f:vicdual.c r:carnival c:carnival
//SET: brdrline
		DRIVER(brdrline) //t:brdrline f:vicdual.c r: c:
		DRIVER(starrkr) //t:starrkr f:vicdual.c r:brdrline c:brdrline
		DRIVER(brdrlins) //t:brdrlins f:vicdual.c r:brdrline c:brdrline
		DRIVER(brdrlinb) //t:brdrlinb f:vicdual.c r:brdrline c:brdrline
//SET: digger
		DRIVER(digger) //t:digger f:vicdual.c r: c:
//SET: pulsar
		DRIVER(pulsar) //t:pulsar f:vicdual.c r: c:
//SET: heiankyo
		DRIVER(heiankyo) //t:heiankyo f:vicdual.c r: c:
//SET: alphaho
		DRIVER(alphaho) //t:alphaho f:vicdual.c r: c:
//SET: spacfury
		DRIVER(spacfury) //t:spacfury f:segag80v.c r: c:
		DRIVER(spacfurya) //t:spacfurya f:segag80v.c r:spacfury c:spacfury
		DRIVER(spacfuryb) //t:spacfuryb f:segag80v.c r:spacfury c:spacfury
//SET: zektor
		DRIVER(zektor) //t:zektor f:segag80v.c r: c:
//SET: tacscan
		DRIVER(tacscan) //t:tacscan f:segag80v.c r: c:
//SET: elim2
		DRIVER(elim2) //t:elim2 f:segag80v.c r: c:
		DRIVER(elim2a) //t:elim2a f:segag80v.c r:elim2 c:elim2
		DRIVER(elim2c) //t:elim2c f:segag80v.c r:elim2 c:elim2
		DRIVER(elim4) //t:elim4 f:segag80v.c r:elim2 c:elim2
		DRIVER(elim4p) //t:elim4p f:segag80v.c r:elim2 c:elim2
//SET: startrek
		DRIVER(startrek) //t:startrek f:segag80v.c r: c:
//SET: astrob
		DRIVER(astrob) //t:astrob f:segag80r.c r: c:
		DRIVER(astrob2) //t:astrob2 f:segag80r.c r:astrob c:astrob
		DRIVER(astrob2a) //t:astrob2a f:segag80r.c r:astrob c:astrob
		DRIVER(astrob1) //t:astrob1 f:segag80r.c r:astrob c:astrob
		DRIVER(astrobg) //t:astrobg f:segag80r.c r:astrob c:astrob
//SET: 005
		DRIVER(005) //t:005 f:segag80r.c r: c:
//SET: monsterb
		DRIVER(monsterb) //t:monsterb f:segag80r.c r: c:
		DRIVER(monsterb2) //t:monsterb2 f:segag80r.c r:monsterb c:monsterb
//SET: spaceod
		DRIVER(spaceod) //t:spaceod f:segag80r.c r: c:
		DRIVER(spaceod2) //t:spaceod2 f:segag80r.c r:spaceod c:spaceod
//SET: pignewt
		DRIVER(pignewt) //t:pignewt f:segag80r.c r: c:
		DRIVER(pignewta) //t:pignewta f:segag80r.c r:pignewt c:pignewt
//SET: sindbadm
		DRIVER(sindbadm) //t:sindbadm f:segag80r.c r: c:
//SET: zaxxon
		DRIVER(zaxxon) //t:zaxxon f:zaxxon.c r: c:
		DRIVER(zaxxonj) //t:zaxxonj f:zaxxon.c r:zaxxon c:zaxxon
		DRIVER(zaxxon2) //t:zaxxon2 f:zaxxon.c r:zaxxon c:zaxxon
		DRIVER(zaxxon3) //t:zaxxon3 f:zaxxon.c r:zaxxon c:zaxxon
		DRIVER(zaxxonb) //t:zaxxonb f:zaxxon.c r:zaxxon c:zaxxon
//SET: szaxxon
		DRIVER(szaxxon) //t:szaxxon f:zaxxon.c r: c:
//SET: futspy
		DRIVER(futspy) //t:futspy f:zaxxon.c r: c:
//SET: razmataz
		DRIVER(razmataz) //t:razmataz f:zaxxon.c r: c:
//SET: ixion
		DRIVER(ixion) //t:ixion f:zaxxon.c r: c:
//SET: congo
		DRIVER(congo) //t:congo f:zaxxon.c r: c:
		DRIVER(tiptop) //t:tiptop f:zaxxon.c r:congo c:congo
//SET: astron
		DRIVER(astron) //t:astron f:segald.c r: c:
		DRIVER(astronp) //t:astronp f:segald.c r:astron c:astron
		DRIVER(cobraseg) //t:cobraseg f:segald.c r:astron c:astron
//SET: galaxyr
		DRIVER(galaxyr) //t:galaxyr f:segald.c r: c:
		DRIVER(galaxyrp) //t:galaxyrp f:segald.c r:galaxyr c:galaxyr
		DRIVER(sblazerp) //t:sblazerp f:segald.c r:galaxyr c:galaxyr
//SET: gpworld
		DRIVER(gpworld) //t:gpworld f:gpworld.c r: c:
//SET: timetrv
		DRIVER(timetrv) //t:timetrv f:timetrv.c r: c:
//SET: chboxing
		DRIVER(chboxing) //t:chboxing f:sg1000a.c r: c:
//SET: chwrestl
		DRIVER(chwrestl) //t:chwrestl f:sg1000a.c r: c:
//SET: dokidoki
		DRIVER(dokidoki) //t:dokidoki f:sg1000a.c r: c:
//SET: starjack
		DRIVER(starjack) //t:starjack f:system1.c r: c:


		DRIVER(starjacks) //t:starjacks f:system1.c r:starjack c:starjack
//SET: regulus
		DRIVER(regulus) //t:regulus f:system1.c r: c:
		DRIVER(reguluso) //t:reguluso f:system1.c r:regulus c:regulus
		DRIVER(regulusu) //t:regulusu f:system1.c r:regulus c:regulus
//SET: upndown
		DRIVER(upndown) //t:upndown f:system1.c r: c:
		DRIVER(upndownu) //t:upndownu f:system1.c r:upndown c:upndown
//SET: mrviking
		DRIVER(mrviking) //t:mrviking f:system1.c r: c:
		DRIVER(mrvikingj) //t:mrvikingj f:system1.c r:mrviking c:mrviking
//SET: swat
		DRIVER(swat) //t:swat f:system1.c r: c:
//SET: flicky
		DRIVER(flicky) //t:flicky f:system1.c r: c:
		DRIVER(flickys2) //t:flickys2 f:system1.c r:flicky c:flicky
		DRIVER(flickyo) //t:flickyo f:system1.c r:flicky c:flicky
		DRIVER(flickys1) //t:flickys1 f:system1.c r:flicky c:flicky
//SET: wmatch
		DRIVER(wmatch) //t:wmatch f:system1.c r: c:
//SET: bullfgt
		DRIVER(bullfgt) //t:bullfgt f:system1.c r: c:
		DRIVER(thetogyu) //t:thetogyu f:system1.c r:bullfgt c:bullfgt
//SET: spatter
		DRIVER(spatter) //t:spatter f:system1.c r: c:
		DRIVER(ssanchan) //t:ssanchan f:system1.c r:spatter c:spatter
#endif

#ifdef PS3_SET_7
//SET: pitfall2
		DRIVER(pitfall2) //t:pitfall2 f:system1.c r: c:
		DRIVER(pitfall2a) //t:pitfall2a f:system1.c r:pitfall2 c:pitfall2
		DRIVER(pitfall2u) //t:pitfall2u f:system1.c r:pitfall2 c:pitfall2
//SET: seganinj
		DRIVER(seganinj) //t:seganinj f:system1.c r: c:
		DRIVER(seganinju) //t:seganinju f:system1.c r:seganinj c:seganinj
		DRIVER(ninja) //t:ninja f:system1.c r:seganinj c:seganinj
		DRIVER(nprinces) //t:nprinces f:system1.c r:seganinj c:seganinj
		DRIVER(nprinceso) //t:nprinceso f:system1.c r:seganinj c:seganinj
		DRIVER(nprincesu) //t:nprincesu f:system1.c r:seganinj c:seganinj
		DRIVER(nprincesb) //t:nprincesb f:system1.c r:seganinj c:seganinj
//SET: imsorry
		DRIVER(imsorry) //t:imsorry f:system1.c r: c:
		DRIVER(imsorryj) //t:imsorryj f:system1.c r:imsorry c:imsorry
//SET: teddybb
		DRIVER(teddybb) //t:teddybb f:system1.c r: c:
		DRIVER(teddybbo) //t:teddybbo f:system1.c r:teddybb c:teddybb
//SET: hvymetal
		DRIVER(hvymetal) //t:hvymetal f:system1.c r: c:
//SET: myhero
		DRIVER(myhero) //t:myhero f:system1.c r: c:
		DRIVER(sscandal) //t:sscandal f:system1.c r:myhero c:myhero
		DRIVER(myherok) //t:myherok f:system1.c r:myhero c:myhero
//SET: shtngmst
		DRIVER(shtngmst) //t:shtngmst f:system1.c r: c:
		DRIVER(shtngmste) //t:shtngmste f:system1.c r:shtngmst c:shtngmst
//SET: choplift
		DRIVER(choplift) //t:choplift f:system1.c r: c:
		DRIVER(chopliftu) //t:chopliftu f:system1.c r:choplift c:choplift
		DRIVER(chopliftbl) //t:chopliftbl f:system1.c r:choplift c:choplift
//SET: 4dwarrio
		DRIVER(4dwarrio) //t:4dwarrio f:system1.c r: c:
//SET: brain
		DRIVER(brain) //t:brain f:system1.c r: c:
//SET: raflesia
		DRIVER(raflesia) //t:raflesia f:system1.c r: c:
//SET: wboy
		DRIVER(wboy) //t:wboy f:system1.c r: c:
		DRIVER(wboyo) //t:wboyo f:system1.c r:wboy c:wboy
		DRIVER(wboy2) //t:wboy2 f:system1.c r:wboy c:wboy
		DRIVER(wboy2u) //t:wboy2u f:system1.c r:wboy c:wboy
		DRIVER(wboy3) //t:wboy3 f:system1.c r:wboy c:wboy
		DRIVER(wboy4) //t:wboy4 f:system1.c r:wboy c:wboy
		DRIVER(wboyu) //t:wboyu f:system1.c r:wboy c:wboy
		DRIVER(wbdeluxe) //t:wbdeluxe f:system1.c r:wboy c:wboy
		DRIVER(wboysys2) //t:wboysys2 f:system1.c r:wboy c:wboy
//SET: gardia
		DRIVER(gardia) //t:gardia f:system1.c r: c:
		DRIVER(gardiab) //t:gardiab f:system1.c r:gardia c:gardia
//SET: nob
		DRIVER(nob) //t:nob f:system1.c r: c:
		DRIVER(nobb) //t:nobb f:system1.c r:nob c:nob
//SET: blockgal
		DRIVER(blockgal) //t:blockgal f:system1.c r: c:
		DRIVER(blockgalb) //t:blockgalb f:system1.c r:blockgal c:blockgal
//SET: tokisens
		DRIVER(tokisens) //t:tokisens f:system1.c r: c:
//SET: wbml
		DRIVER(wbml) //t:wbml f:system1.c r: c:
		DRIVER(wbmljo) //t:wbmljo f:system1.c r:wbml c:wbml
		DRIVER(wbmljb) //t:wbmljb f:system1.c r:wbml c:wbml
		DRIVER(wbmlb) //t:wbmlb f:system1.c r:wbml c:wbml
		DRIVER(wbmlbg) //t:wbmlbg f:system1.c r:wbml c:wbml
//SET: dakkochn
		DRIVER(dakkochn) //t:dakkochn f:system1.c r: c:
//SET: ufosensi
		DRIVER(ufosensi) //t:ufosensi f:system1.c r: c:
		DRIVER(ufosensib) //t:ufosensib f:system1.c r:ufosensi c:ufosensi
//SET: hangonjr
		DRIVER(hangonjr) //t:hangonjr f:segae.c r: c:
//SET: transfrm
		DRIVER(transfrm) //t:transfrm f:segae.c r: c:
		DRIVER(astrofl) //t:astrofl f:segae.c r:transfrm c:transfrm
//SET: ridleofp
		DRIVER(ridleofp) //t:ridleofp f:segae.c r: c:
//SET: fantzn2
		DRIVER(fantzn2) //t:fantzn2 f:segae.c r: c:
//SET: opaopa
		DRIVER(opaopa) //t:opaopa f:segae.c r: c:
//SET: tetrisse
		DRIVER(tetrisse) //t:tetrisse f:segae.c r: c:
//SET: turbo
		DRIVER(turbo) //t:turbo f:turbo.c r: c:
		DRIVER(turboa) //t:turboa f:turbo.c r:turbo c:turbo
		DRIVER(turbob) //t:turbob f:turbo.c r:turbo c:turbo
//SET: subroc3d
		DRIVER(subroc3d) //t:subroc3d f:turbo.c r: c:
//SET: buckrog
		DRIVER(buckrog) //t:buckrog f:turbo.c r: c:
		DRIVER(buckrogn) //t:buckrogn f:turbo.c r:buckrog c:buckrog
		DRIVER(buckrogn2) //t:buckrogn2 f:turbo.c r:buckrog c:buckrog
		DRIVER(zoom909) //t:zoom909 f:turbo.c r:buckrog c:buckrog
//SET: kopunch
		DRIVER(kopunch) //t:kopunch f:kopunch.c r: c:
//SET: suprloco
		DRIVER(suprloco) //t:suprloco f:suprloco.c r: c:
		DRIVER(suprlocoa) //t:suprlocoa f:suprloco.c r:suprloco c:suprloco
//SET: dotrikun
		DRIVER(dotrikun) //t:dotrikun f:dotrikun.c r: c:
		DRIVER(dotrikun2) //t:dotrikun2 f:dotrikun.c r:dotrikun c:dotrikun
//SET: spcpostn
		DRIVER(spcpostn) //t:spcpostn f:angelkds.c r: c:
//SET: angelkds
		DRIVER(angelkds) //t:angelkds f:angelkds.c r: c:
//SET: calorie
		DRIVER(calorie) //t:calorie f:calorie.c r: c:
		DRIVER(calorieb) //t:calorieb f:calorie.c r:calorie c:calorie
//SET: bingoc
		DRIVER(bingoc) //t:bingoc f:bingoc.c r: c:
//SET: enduror
		DRIVER(enduror) //t:enduror f:segahang.c r: c:
		DRIVER(enduror1) //t:enduror1 f:segahang.c r:enduror c:enduror
		DRIVER(endurob2) //t:endurob2 f:segahang.c r:enduror c:enduror
		DRIVER(endurobl) //t:endurobl f:segahang.c r:enduror c:enduror
//SET: hangon
		DRIVER(hangon) //t:hangon f:segahang.c r: c:
		DRIVER(hangon1) //t:hangon1 f:segahang.c r:hangon c:hangon
//SET: sharrier
		DRIVER(sharrier) //t:sharrier f:segahang.c r: c:
		DRIVER(sharrier1) //t:sharrier1 f:segahang.c r:sharrier c:sharrier
//SET: bodyslam
		DRIVER(bodyslam) //t:bodyslam f:segas16a.c r: c:
		DRIVER(dumpmtmt) //t:dumpmtmt f:segas16a.c r:bodyslam c:bodyslam
//SET: mjleague
		DRIVER(mjleague) //t:mjleague f:segas16a.c r: c:
//SET: quartet
		DRIVER(quartet) //t:quartet f:segas16a.c r: c:
		DRIVER(quarteta) //t:quarteta f:segas16a.c r:quartet c:quartet
		DRIVER(quartet2) //t:quartet2 f:segas16a.c r:quartet c:quartet
		DRIVER(quartet2a) //t:quartet2a f:segas16a.c r:quartet c:quartet
//SET: afighter
		DRIVER(afighter) //t:afighter f:segas16a.c r: c:
//SET: alexkidd
		DRIVER(alexkidd) //t:alexkidd f:segas16a.c r: c:
		DRIVER(alexkidd1) //t:alexkidd1 f:segas16a.c r:alexkidd c:alexkidd
//SET: fantzone
		DRIVER(fantzone) //t:fantzone f:segas16a.c r: c:
		DRIVER(fantzone1) //t:fantzone1 f:segas16a.c r:fantzone c:fantzone
		DRIVER(fantzonep) //t:fantzonep f:segas16a.c r:fantzone c:fantzone
//SET: sdi
		DRIVER(sdi) //t:sdi f:segas16a.c r: c:
		DRIVER(sdib) //t:sdib f:segas16b.c r:sdi c:sdi
		DRIVER(sdibl) //t:sdibl f:segas16b.c r:sdi c:sdi
		DRIVER(defense) //t:defense f:segas16b.c r:sdi c:sdi
//SET: shinobi
		DRIVER(shinobi) //t:shinobi f:segas16a.c r: c:
		DRIVER(shinobi1) //t:shinobi1 f:segas16a.c r:shinobi c:shinobi
		DRIVER(shinobls) //t:shinobls f:segas16a.c r:shinobi c:shinobi
		DRIVER(shinobi5) //t:shinobi5 f:segas16b.c r:shinobi c:shinobi
		DRIVER(shinobi4) //t:shinobi4 f:segas16b.c r:shinobi c:shinobi
		DRIVER(shinobi3) //t:shinobi3 f:segas16b.c r:shinobi c:shinobi
		DRIVER(shinobi2) //t:shinobi2 f:segas16b.c r:shinobi c:shinobi
		DRIVER(shinoblb) //t:shinoblb f:segas16a.c r:shinobi c:shinobi
		DRIVER(shinobld) //t:shinobld f:system16.c r:shinobi c:shinobi
//SET: tetris
		DRIVER(tetris) //t:tetris f:segas16a.c r: c:
		DRIVER(tetrist) //t:tetrist f:taito_b.c r:tetris c:tetris
		DRIVER(tetrista) //t:tetrista f:taito_b.c r:tetris c:tetris
		DRIVER(tetris3) //t:tetris3 f:segas16a.c r:tetris c:tetris
		DRIVER(tetris2) //t:tetris2 f:segas16b.c r:tetris c:tetris
		DRIVER(tetris1) //t:tetris1 f:segas16b.c r:tetris c:tetris
		DRIVER(tetrisbl) //t:tetrisbl f:system16.c r:tetris c:tetris
//SET: aceattac
		DRIVER(aceattac) //t:aceattac f:segas16b.c r: c:
		DRIVER(aceattaca) //t:aceattaca f:segas16a.c r:aceattac c:aceattac
//SET: aliensyn
		DRIVER(aliensyn) //t:aliensyn f:segas16b.c r: c:
		DRIVER(aliensynjo) //t:aliensynjo f:segas16a.c r:aliensyn c:aliensyn
		DRIVER(aliensyn2) //t:aliensyn2 f:segas16a.c r:aliensyn c:aliensyn
		DRIVER(aliensyn5) //t:aliensyn5 f:segas16a.c r:aliensyn c:aliensyn
		DRIVER(aliensyn3) //t:aliensyn3 f:segas16b.c r:aliensyn c:aliensyn
		DRIVER(aliensynj) //t:aliensynj f:segas16b.c r:aliensyn c:aliensyn
//SET: altbeast
		DRIVER(altbeast) //t:altbeast f:segas16b.c r: c:
		DRIVER(altbeastj) //t:altbeastj f:segas16b.c r:altbeast c:altbeast
		DRIVER(altbeast5) //t:altbeast5 f:segas16b.c r:altbeast c:altbeast
		DRIVER(altbeast4) //t:altbeast4 f:segas16b.c r:altbeast c:altbeast
		DRIVER(altbeast2) //t:altbeast2 f:segas16b.c r:altbeast c:altbeast
		DRIVER(altbeastj1) //t:altbeastj1 f:segas16b.c r:altbeast c:altbeast
		DRIVER(altbeastj2) //t:altbeastj2 f:segas16b.c r:altbeast c:altbeast
		DRIVER(altbeastj3) //t:altbeastj3 f:segas16b.c r:altbeast c:altbeast
//SET: aurail
		DRIVER(aurail) //t:aurail f:segas16b.c r: c:
		DRIVER(aurail1) //t:aurail1 f:segas16b.c r:aurail c:aurail
		DRIVER(aurailj) //t:aurailj f:segas16b.c r:aurail c:aurail
//SET: bayroute
		DRIVER(bayroute) //t:bayroute f:segas16b.c r: c:
		DRIVER(bayroutej) //t:bayroutej f:segas16b.c r:bayroute c:bayroute
		DRIVER(bayroute1) //t:bayroute1 f:segas16b.c r:bayroute c:bayroute
		DRIVER(bayrouteb1) //t:bayrouteb1 f:system16.c r:bayroute c:bayroute
		DRIVER(bayrouteb2) //t:bayrouteb2 f:system16.c r:bayroute c:bayroute
//SET: bullet
		DRIVER(bullet) //t:bullet f:segas16b.c r: c:
//SET: cotton
		DRIVER(cotton) //t:cotton f:segas16b.c r: c:
		DRIVER(cottonu) //t:cottonu f:segas16b.c r:cotton c:cotton
		DRIVER(cottonj) //t:cottonj f:segas16b.c r:cotton c:cotton
//SET: ddux
		DRIVER(ddux) //t:ddux f:segas16b.c r: c:
		DRIVER(ddux1) //t:ddux1 f:segas16b.c r:ddux c:ddux
		DRIVER(dduxbl) //t:dduxbl f:system16.c r:ddux c:ddux
//SET: dunkshot
		DRIVER(dunkshot) //t:dunkshot f:segas16b.c r: c:
//SET: eswat
		DRIVER(eswat) //t:eswat f:segas16b.c r: c:
		DRIVER(eswatu) //t:eswatu f:segas16b.c r:eswat c:eswat
		DRIVER(eswatj) //t:eswatj f:segas16b.c r:eswat c:eswat
		DRIVER(eswatbl) //t:eswatbl f:system16.c r:eswat c:eswat
//SET: exctleag
		DRIVER(exctleag) //t:exctleag f:segas16b.c r: c:
//SET: fpoint
		DRIVER(fpoint) //t:fpoint f:segas16b.c r: c:
		DRIVER(fpoint1) //t:fpoint1 f:segas16b.c r:fpoint c:fpoint
		DRIVER(fpointbl) //t:fpointbl f:system16.c r:fpoint c:fpoint
		DRIVER(fpointbj) //t:fpointbj f:system16.c r:fpoint c:fpoint
//SET: goldnaxe
		DRIVER(goldnaxe) //t:goldnaxe f:segas16b.c r: c:
		DRIVER(goldnaxeu) //t:goldnaxeu f:segas16b.c r:goldnaxe c:goldnaxe
		DRIVER(goldnaxej) //t:goldnaxej f:segas16b.c r:goldnaxe c:goldnaxe
		DRIVER(goldnaxe3) //t:goldnaxe3 f:segas16b.c r:goldnaxe c:goldnaxe
		DRIVER(goldnaxe2) //t:goldnaxe2 f:segas16b.c r:goldnaxe c:goldnaxe
		DRIVER(goldnaxe1) //t:goldnaxe1 f:segas16b.c r:goldnaxe c:goldnaxe
		DRIVER(goldnaxeb1) //t:goldnaxeb1 f:system16.c r:goldnaxe c:goldnaxe
		DRIVER(goldnaxeb2) //t:goldnaxeb2 f:system16.c r:goldnaxe c:goldnaxe
//SET: hwchamp
		DRIVER(hwchamp) //t:hwchamp f:segas16b.c r: c:
		DRIVER(hwchampj) //t:hwchampj f:segas16b.c r:hwchamp c:hwchamp
//SET: mvp
		DRIVER(mvp) //t:mvp f:segas16b.c r: c:
		DRIVER(mvpj) //t:mvpj f:segas16b.c r:mvp c:mvp
//SET: passsht
		DRIVER(passsht) //t:passsht f:segas16b.c r: c:
		DRIVER(passsht16a) //t:passsht16a f:segas16a.c r:passsht c:passsht
		DRIVER(passshta) //t:passshta f:segas16b.c r:passsht c:passsht
		DRIVER(passshtj) //t:passshtj f:segas16b.c r:passsht c:passsht
		DRIVER(passht4b) //t:passht4b f:system16.c r:passsht c:passsht
		DRIVER(passshtb) //t:passshtb f:system16.c r:passsht c:passsht
//SET: riotcity
		DRIVER(riotcity) //t:riotcity f:segas16b.c r: c:
//SET: ryukyu
		DRIVER(ryukyu) //t:ryukyu f:segas16b.c r: c:
//SET: sonicbom
		DRIVER(sonicbom) //t:sonicbom f:segas16b.c r: c:
//SET: sjryuko
		DRIVER(sjryuko) //t:sjryuko f:segas16b.c r: c:
		DRIVER(sjryuko1) //t:sjryuko1 f:segas16a.c r:sjryuko c:sjryuko
//SET: suprleag
		DRIVER(suprleag) //t:suprleag f:segas16b.c r: c:
//SET: timescan
		DRIVER(timescan) //t:timescan f:segas16b.c r: c:
		DRIVER(timescan1) //t:timescan1 f:segas16a.c r:timescan c:timescan
//SET: toryumon
		DRIVER(toryumon) //t:toryumon f:segas16b.c r: c:
//SET: tturf
		DRIVER(tturf) //t:tturf f:segas16b.c r: c:
		DRIVER(tturfu) //t:tturfu f:segas16b.c r:tturf c:tturf
		DRIVER(tturfbl) //t:tturfbl f:system16.c r:tturf c:tturf
//SET: wb3
		DRIVER(wb3) //t:wb3 f:segas16b.c r: c:
		DRIVER(wb31) //t:wb31 f:segas16a.c r:wb3 c:wb3
		DRIVER(wb35) //t:wb35 f:segas16a.c r:wb3 c:wb3
		DRIVER(wb35a) //t:wb35a f:segas16a.c r:wb3 c:wb3
		DRIVER(wb34) //t:wb34 f:segas16b.c r:wb3 c:wb3
		DRIVER(wb33) //t:wb33 f:segas16b.c r:wb3 c:wb3
		DRIVER(wb32) //t:wb32 f:segas16b.c r:wb3 c:wb3
		DRIVER(wb3bbl) //t:wb3bbl f:system16.c r:wb3 c:wb3
//SET: wrestwar
		DRIVER(wrestwar) //t:wrestwar f:segas16b.c r: c:
		DRIVER(wrestwar2) //t:wrestwar2 f:segas16b.c r:wrestwar c:wrestwar
		DRIVER(wrestwar1) //t:wrestwar1 f:segas16b.c r:wrestwar c:wrestwar
//SET: atomicp
		DRIVER(atomicp) //t:atomicp f:segas16b.c r: c:
//SET: snapper
		DRIVER(snapper) //t:snapper f:segas16b.c r: c:
//SET: beautyb
		DRIVER(beautyb) //t:beautyb f:system16.c r: c:
//SET: iqpipe
		DRIVER(iqpipe) //t:iqpipe f:system16.c r: c:
//SET: isgsm
		DRIVER(isgsm) //t:isgsm f:segas16b.c r: c:
//SET: tetrbx
		DRIVER(tetrbx) //t:tetrbx f:segas16b.c r:isgsm c:
//SET: shinfz
		DRIVER(shinfz) //t:shinfz f:segas16b.c r:isgsm c:
//SET: shdancer
		DRIVER(shdancer) //t:shdancer f:segas18.c r: c:
		DRIVER(shdancerj) //t:shdancerj f:segas18.c r:shdancer c:shdancer
		DRIVER(shdancer1) //t:shdancer1 f:segas18.c r:shdancer c:shdancer
		DRIVER(shdancbl) //t:shdancbl f:system16.c r:shdancer c:shdancer
//SET: bloxeed
		DRIVER(bloxeed) //t:bloxeed f:segas18.c r: c:
		DRIVER(bloxeedc) //t:bloxeedc f:segac2.c r:bloxeed c:bloxeed
		DRIVER(bloxeedu) //t:bloxeedu f:segac2.c r:bloxeed c:bloxeed
//SET: astorm
		DRIVER(astorm) //t:astorm f:segas18.c r: c:
		DRIVER(astormu) //t:astormu f:segas18.c r:astorm c:astorm
		DRIVER(astormj) //t:astormj f:segas18.c r:astorm c:astorm
		DRIVER(astorm3) //t:astorm3 f:segas18.c r:astorm c:astorm
		DRIVER(astormbl) //t:astormbl f:system16.c r:astorm c:astorm
		DRIVER(astormb2) //t:astormb2 f:system16.c r:astorm c:astorm
//SET: mwalk
		DRIVER(mwalk) //t:mwalk f:segas18.c r: c:
		DRIVER(mwalku) //t:mwalku f:segas18.c r:mwalk c:mwalk
		DRIVER(mwalkj) //t:mwalkj f:segas18.c r:mwalk c:mwalk
		DRIVER(mwalkbl) //t:mwalkbl f:system16.c r:mwalk c:mwalk
//SET: lghost
		DRIVER(lghost) //t:lghost f:segas18.c r: c:
		DRIVER(lghostu) //t:lghostu f:segas18.c r:lghost c:lghost
//SET: cltchitr
		DRIVER(cltchitr) //t:cltchitr f:segas18.c r: c:
		DRIVER(cltchitrj) //t:cltchitrj f:segas18.c r:cltchitr c:cltchitr
//SET: ddcrew
		DRIVER(ddcrew) //t:ddcrew f:segas18.c r: c:
		DRIVER(ddcrewj) //t:ddcrewj f:segas18.c r:ddcrew c:ddcrew
		DRIVER(ddcrewu) //t:ddcrewu f:segas18.c r:ddcrew c:ddcrew
		DRIVER(ddcrew2) //t:ddcrew2 f:segas18.c r:ddcrew c:ddcrew
		DRIVER(ddcrew1) //t:ddcrew1 f:segas18.c r:ddcrew c:ddcrew
//SET: wwallyj
		DRIVER(wwallyj) //t:wwallyj f:segas18.c r: c:
		DRIVER(wwallyja) //t:wwallyja f:segas18.c r:wwallyj c:wwallyj
//SET: desertbr
		DRIVER(desertbr) //t:desertbr f:segas18.c r: c:
		DRIVER(desertbrj) //t:desertbrj f:segas18.c r:desertbr c:desertbr
//SET: pontoon
		DRIVER(pontoon) //t:pontoon f:segas18.c r: c:
//SET: outrun
		DRIVER(outrun) //t:outrun f:segaorun.c r: c:
		DRIVER(outrunra) //t:outrunra f:segaorun.c r:outrun c:outrun
		DRIVER(outruno) //t:outruno f:segaorun.c r:outrun c:outrun
		DRIVER(outrundx) //t:outrundx f:segaorun.c r:outrun c:outrun
		DRIVER(outrunb) //t:outrunb f:segaorun.c r:outrun c:outrun
//SET: shangon
		DRIVER(shangon) //t:shangon f:segaorun.c r: c:
		DRIVER(shangonro) //t:shangonro f:segahang.c r:shangon c:shangon
		DRIVER(shangonrb) //t:shangonrb f:segahang.c r:shangon c:shangon
		DRIVER(shangon3) //t:shangon3 f:segaorun.c r:shangon c:shangon
		DRIVER(shangon2) //t:shangon2 f:segaorun.c r:shangon c:shangon
		DRIVER(shangon1) //t:shangon1 f:segaorun.c r:shangon c:shangon
		DRIVER(shangonle) //t:shangonle f:segaorun.c r:shangon c:shangon
//SET: toutrun
		DRIVER(toutrun) //t:toutrun f:segaorun.c r: c:
		DRIVER(toutrun3) //t:toutrun3 f:segaorun.c r:toutrun c:toutrun
		DRIVER(toutrun2) //t:toutrun2 f:segaorun.c r:toutrun c:toutrun
		DRIVER(toutrun1) //t:toutrun1 f:segaorun.c r:toutrun c:toutrun
//SET: aburner2
		DRIVER(aburner2) //t:aburner2 f:segaxbd.c r: c:
		DRIVER(aburner) //t:aburner f:segaxbd.c r:aburner2 c:aburner2
//SET: thndrbld
		DRIVER(thndrbld) //t:thndrbld f:segaxbd.c r: c:
		DRIVER(thndrbld1) //t:thndrbld1 f:segaxbd.c r:thndrbld c:thndrbld
//SET: smgp
		DRIVER(smgp) //t:smgp f:segaxbd.c r: c:
		DRIVER(smgpj) //t:smgpj f:segaxbd.c r:smgp c:smgp
		DRIVER(smgpja) //t:smgpja f:segaxbd.c r:smgp c:smgp
		DRIVER(smgp6) //t:smgp6 f:segaxbd.c r:smgp c:smgp
		DRIVER(smgp5) //t:smgp5 f:segaxbd.c r:smgp c:smgp
		DRIVER(smgpu) //t:smgpu f:segaxbd.c r:smgp c:smgp
		DRIVER(smgpu3) //t:smgpu3 f:segaxbd.c r:smgp c:smgp
		DRIVER(smgpu2) //t:smgpu2 f:segaxbd.c r:smgp c:smgp
		DRIVER(smgpu1) //t:smgpu1 f:segaxbd.c r:smgp c:smgp
//SET: loffire
		DRIVER(loffire) //t:loffire f:segaxbd.c r: c:
		DRIVER(loffirej) //t:loffirej f:segaxbd.c r:loffire c:loffire
		DRIVER(loffireu) //t:loffireu f:segaxbd.c r:loffire c:loffire
//SET: rachero
		DRIVER(rachero) //t:rachero f:segaxbd.c r: c:
//SET: abcop
		DRIVER(abcop) //t:abcop f:segaxbd.c r: c:
//SET: gprider
		DRIVER(gprider) //t:gprider f:segaxbd.c r: c:
		DRIVER(gprider1) //t:gprider1 f:segaxbd.c r:gprider c:gprider
//SET: gforce2
		DRIVER(gforce2) //t:gforce2 f:segaybd.c r: c:
		DRIVER(gforce2j) //t:gforce2j f:segaybd.c r:gforce2 c:gforce2
		DRIVER(gforce2ja) //t:gforce2ja f:segaybd.c r:gforce2 c:gforce2
//SET: pdrift
		DRIVER(pdrift) //t:pdrift f:segaybd.c r: c:
		DRIVER(pdriftj) //t:pdriftj f:segaybd.c r:pdrift c:pdrift
		DRIVER(pdrifta) //t:pdrifta f:segaybd.c r:pdrift c:pdrift
		DRIVER(pdrifte) //t:pdrifte f:segaybd.c r:pdrift c:pdrift
//SET: gloc
		DRIVER(gloc) //t:gloc f:segaybd.c r: c:
		DRIVER(glocr360) //t:glocr360 f:segaybd.c r:gloc c:gloc
//SET: strkfgtr
		DRIVER(strkfgtr) //t:strkfgtr f:segaybd.c r: c:
//SET: rchase
		DRIVER(rchase) //t:rchase f:segaybd.c r: c:
		DRIVER(rchasej) //t:rchasej f:segaybd.c r:rchase c:rchase
//SET: hotrod
		DRIVER(hotrod) //t:hotrod f:segas24.c r: c:
		DRIVER(hotrodj) //t:hotrodj f:segas24.c r:hotrod c:hotrod
		DRIVER(hotroda) //t:hotroda f:segas24.c r:hotrod c:hotrod
//SET: sspirits
		DRIVER(sspirits) //t:sspirits f:segas24.c r: c:
		DRIVER(sspiritj) //t:sspiritj f:segas24.c r:sspirits c:sspirits
		DRIVER(sspirtfc) //t:sspirtfc f:segas24.c r:sspirits c:sspirits
//SET: gground
		DRIVER(gground) //t:gground f:segas24.c r: c:
		DRIVER(ggroundj) //t:ggroundj f:segas24.c r:gground c:gground
//SET: crkdown
		DRIVER(crkdown) //t:crkdown f:segas24.c r: c:
		DRIVER(crkdownj) //t:crkdownj f:segas24.c r:crkdown c:crkdown
		DRIVER(crkdownu) //t:crkdownu f:segas24.c r:crkdown c:crkdown
//SET: sgmast
		DRIVER(sgmast) //t:sgmast f:segas24.c r: c:
		DRIVER(sgmastj) //t:sgmastj f:segas24.c r:sgmast c:sgmast
		DRIVER(sgmastc) //t:sgmastc f:segas24.c r:sgmast c:sgmast
//SET: roughrac
		DRIVER(roughrac) //t:roughrac f:segas24.c r: c:
//SET: bnzabros
		DRIVER(bnzabros) //t:bnzabros f:segas24.c r: c:
		DRIVER(bnzabrosj) //t:bnzabrosj f:segas24.c r:bnzabros c:bnzabros
//SET: qsww
		DRIVER(qsww) //t:qsww f:segas24.c r: c:
//SET: dcclub
		DRIVER(dcclub) //t:dcclub f:segas24.c r: c:
		DRIVER(dcclubfd) //t:dcclubfd f:segas24.c r:dcclub c:dcclub
		DRIVER(dcclubj) //t:dcclubj f:segas24.c r:dcclub c:dcclub
//SET: qrouka
		DRIVER(qrouka) //t:qrouka f:segas24.c r: c:
//SET: mahmajn
		DRIVER(mahmajn) //t:mahmajn f:segas24.c r: c:
//SET: quizmeku
		DRIVER(quizmeku) //t:quizmeku f:segas24.c r: c:
//SET: mahmajn2
		DRIVER(mahmajn2) //t:mahmajn2 f:segas24.c r: c:
//SET: qgh
		DRIVER(qgh) //t:qgh f:segas24.c r: c:
//SET: radm
		DRIVER(radm) //t:radm f:segas32.c r: c:
		DRIVER(radmu) //t:radmu f:segas32.c r:radm c:radm
//SET: radr
		DRIVER(radr) //t:radr f:segas32.c r: c:
		DRIVER(radru) //t:radru f:segas32.c r:radr c:radr
//SET: spidman
		DRIVER(spidman) //t:spidman f:segas32.c r: c:
		DRIVER(spidmanu) //t:spidmanu f:segas32.c r:spidman c:spidman
//SET: f1en
		DRIVER(f1en) //t:f1en f:segas32.c r: c:
//SET: arabfgt
		DRIVER(arabfgt) //t:arabfgt f:segas32.c r: c:
		DRIVER(arabfgtu) //t:arabfgtu f:segas32.c r:arabfgt c:arabfgt
		DRIVER(arabfgtj) //t:arabfgtj f:segas32.c r:arabfgt c:arabfgt
//SET: arescue
		DRIVER(arescue) //t:arescue f:segas32.c r: c:
//SET: ga2
		DRIVER(ga2) //t:ga2 f:segas32.c r: c:
		DRIVER(ga2u) //t:ga2u f:segas32.c r:ga2 c:ga2
		DRIVER(ga2j) //t:ga2j f:segas32.c r:ga2 c:ga2
//SET: holo
		DRIVER(holo) //t:holo f:segas32.c r: c:
//SET: darkedge
		DRIVER(darkedge) //t:darkedge f:segas32.c r: c:
		DRIVER(darkedgej) //t:darkedgej f:segas32.c r:darkedge c:darkedge
//SET: brival
		DRIVER(brival) //t:brival f:segas32.c r: c:
		DRIVER(brivalj) //t:brivalj f:segas32.c r:brival c:brival
//SET: f1lap
		DRIVER(f1lap) //t:f1lap f:segas32.c r: c:
//SET: alien3
		DRIVER(alien3) //t:alien3 f:segas32.c r: c:
		DRIVER(alien3u) //t:alien3u f:segas32.c r:alien3 c:alien3
//SET: sonic
		DRIVER(sonic) //t:sonic f:segas32.c r: c:
		DRIVER(sonicp) //t:sonicp f:segas32.c r:sonic c:sonic
//SET: kokoroj2
		DRIVER(kokoroj2) //t:kokoroj2 f:segas32.c r: c:
//SET: jpark
		DRIVER(jpark) //t:jpark f:segas32.c r: c:
//SET: dbzvrvs
		DRIVER(dbzvrvs) //t:dbzvrvs f:segas32.c r: c:
//SET: svf
		DRIVER(svf) //t:svf f:segas32.c r: c:
		DRIVER(jleague) //t:jleague f:segas32.c r:svf c:svf
		DRIVER(svs) //t:svs f:segas32.c r:svf c:svf
//SET: slipstrm
		DRIVER(slipstrm) //t:slipstrm f:segas32.c r: c:
		DRIVER(slipstrmh) //t:slipstrmh f:segas32.c r:slipstrm c:slipstrm
//SET: orunners
		DRIVER(orunners) //t:orunners f:segas32.c r: c:
		DRIVER(orunnersu) //t:orunnersu f:segas32.c r:orunners c:orunners
//SET: harddunk
		DRIVER(harddunk) //t:harddunk f:segas32.c r: c:
		DRIVER(harddunkj) //t:harddunkj f:segas32.c r:harddunk c:harddunk
//SET: titlef
		DRIVER(titlef) //t:titlef f:segas32.c r: c:
		DRIVER(titlefu) //t:titlefu f:segas32.c r:titlef c:titlef
//SET: scross
		DRIVER(scross) //t:scross f:segas32.c r: c:
		DRIVER(scrossu) //t:scrossu f:segas32.c r:scross c:scross
//SET: vr
		DRIVER(vr) //t:vr f:model1.c r: c:
		DRIVER(vformula) //t:vformula f:model1.c r:vr c:vr
//SET: vf
		DRIVER(vf) //t:vf f:model1.c r: c:
//SET: swa
		DRIVER(swa) //t:swa f:model1.c r: c:
//SET: wingwar
		DRIVER(wingwar) //t:wingwar f:model1.c r: c:
		DRIVER(wingwarj) //t:wingwarj f:model1.c r:wingwar c:wingwar
		DRIVER(wingwaru) //t:wingwaru f:model1.c r:wingwar c:wingwar
//SET: coolridr
		DRIVER(coolridr) //t:coolridr f:coolridr.c r: c:
//SET: stvbios
		DRIVER(stvbios) //t:stvbios f:stv.c r: c:
//SET: gaxeduel
		DRIVER(gaxeduel) //t:gaxeduel f:stv.c r:stvbios c:
//SET: suikoenb
		DRIVER(suikoenb) //t:suikoenb f:stv.c r:stvbios c:
//SET: bakubaku
		DRIVER(bakubaku) //t:bakubaku f:stv.c r:stvbios c:
//SET: vfremix
		DRIVER(vfremix) //t:vfremix f:stv.c r:stvbios c:
//SET: ejihon
		DRIVER(ejihon) //t:ejihon f:stv.c r:stvbios c:
//SET: shanhigw
		DRIVER(shanhigw) //t:shanhigw f:stv.c r:stvbios c:
//SET: sandor
		DRIVER(sandor) //t:sandor f:stv.c r:stvbios c:
		DRIVER(thunt) //t:thunt f:stv.c r:sandor c:sandor
		DRIVER(thuntk) //t:thuntk f:stv.c r:sandor c:sandor
//SET: kiwames
		DRIVER(kiwames) //t:kiwames f:stv.c r:stvbios c:
//SET: sfish2
		DRIVER(sfish2) //t:sfish2 f:stv.c r: c:
		DRIVER(sfish2j) //t:sfish2j f:stv.c r:sfish2 c:sfish2
//SET: critcrsh
		DRIVER(critcrsh) //t:critcrsh f:stv.c r:stvbios c:
//SET: batmanfr
		DRIVER(batmanfr) //t:batmanfr f:stv.c r:stvbios c:
//SET: fhboxers
		DRIVER(fhboxers) //t:fhboxers f:stv.c r:stvbios c:
//SET: vfkids
		DRIVER(vfkids) //t:vfkids f:stv.c r:stvbios c:
//SET: pblbeach
		DRIVER(pblbeach) //t:pblbeach f:stv.c r:stvbios c:
//SET: introdon
		DRIVER(introdon) //t:introdon f:stv.c r:stvbios c:
//SET: smleague
		DRIVER(smleague) //t:smleague f:stv.c r:stvbios c:
		DRIVER(finlarch) //t:finlarch f:stv.c r:smleague c:smleague
//SET: decathlt
		DRIVER(decathlt) //t:decathlt f:stv.c r:stvbios c:
		DRIVER(decathlto) //t:decathlto f:stv.c r:decathlt c:decathlt
//SET: mausuke
		DRIVER(mausuke) //t:mausuke f:stv.c r:stvbios c:
//SET: diehard
		DRIVER(diehard) //t:diehard f:stv.c r:stvbios c:
		DRIVER(dnmtdeka) //t:dnmtdeka f:stv.c r:diehard c:diehard
//SET: sokyugrt
		DRIVER(sokyugrt) //t:sokyugrt f:stv.c r:stvbios c:
//SET: prikura
		DRIVER(prikura) //t:prikura f:stv.c r:stvbios c:
//SET: magzun
		DRIVER(magzun) //t:magzun f:stv.c r:stvbios c:
//SET: puyosun
		DRIVER(puyosun) //t:puyosun f:stv.c r:stvbios c:
//SET: colmns97
		DRIVER(colmns97) //t:colmns97 f:stv.c r:stvbios c:
//SET: shienryu
		DRIVER(shienryu) //t:shienryu f:stv.c r:stvbios c:
//SET: vmahjong
		DRIVER(vmahjong) //t:vmahjong f:stv.c r:stvbios c:
//SET: groovef
		DRIVER(groovef) //t:groovef f:stv.c r:stvbios c:
//SET: nclubv3
		DRIVER(nclubv3) //t:nclubv3 f:stv.c r:stvbios c:
//SET: pclub2
		DRIVER(pclub2) //t:pclub2 f:stv.c r:stvbios c:
		DRIVER(pclub2v3) //t:pclub2v3 f:stv.c r:pclub2 c:pclub2
//SET: winterht
		DRIVER(winterht) //t:winterht f:stv.c r:stvbios c:
//SET: cotton2
		DRIVER(cotton2) //t:cotton2 f:stv.c r:stvbios c:
//SET: hanagumi
		DRIVER(hanagumi) //t:hanagumi f:stv.c r:stvbios c:
//SET: findlove
		DRIVER(findlove) //t:findlove f:stv.c r:stvbios c:
//SET: maruchan
		DRIVER(maruchan) //t:maruchan f:stv.c r:stvbios c:
//SET: techbowl
		DRIVER(techbowl) //t:techbowl f:stv.c r:stvbios c:
//SET: znpwfv
		DRIVER(znpwfv) //t:znpwfv f:stv.c r:stvbios c:
//SET: seabass
		DRIVER(seabass) //t:seabass f:stv.c r:stvbios c:
//SET: sasissu
		DRIVER(sasissu) //t:sasissu f:stv.c r:stvbios c:
		DRIVER(sanjeon) //t:sanjeon f:stv.c r:sasissu c:sasissu
//SET: twcup98
		DRIVER(twcup98) //t:twcup98 f:stv.c r:stvbios c:
//SET: grdforce
		DRIVER(grdforce) //t:grdforce f:stv.c r:stvbios c:
//SET: rsgun
		DRIVER(rsgun) //t:rsgun f:stv.c r:stvbios c:
//SET: astrass
		DRIVER(astrass) //t:astrass f:stv.c r:stvbios c:
//SET: myfairld
		DRIVER(myfairld) //t:myfairld f:stv.c r:stvbios c:
//SET: othellos
		DRIVER(othellos) //t:othellos f:stv.c r:stvbios c:
//SET: cottonbm
		DRIVER(cottonbm) //t:cottonbm f:stv.c r:stvbios c:
//SET: stress
		DRIVER(stress) //t:stress f:stv.c r:stvbios c:
//SET: elandore
		DRIVER(elandore) //t:elandore f:stv.c r:stvbios c:
//SET: sss
		DRIVER(sss) //t:sss f:stv.c r:stvbios c:
//SET: micrombc
		DRIVER(micrombc) //t:micrombc f:stv.c r:stvbios c:
//SET: danchih
		DRIVER(danchih) //t:danchih f:stv.c r:stvbios c:
//SET: ffreveng
		DRIVER(ffreveng) //t:ffreveng f:stv.c r:stvbios c:
//SET: pclubpok
		DRIVER(pclubpok) //t:pclubpok f:stv.c r:stvbios c:
//SET: danchiq
		DRIVER(danchiq) //t:danchiq f:stv.c r:stvbios c:
//SET: daytona
		DRIVER(daytona) //t:daytona f:model2.c r: c:
		DRIVER(daytona93) //t:daytona93 f:model2.c r:daytona c:daytona
		DRIVER(daytonas) //t:daytonas f:model2.c r:daytona c:daytona
		DRIVER(daytonat) //t:daytonat f:model2.c r:daytona c:daytona
		DRIVER(daytonam) //t:daytonam f:model2.c r:daytona c:daytona
//SET: desert
		DRIVER(desert) //t:desert f:model2.c r: c:
//SET: vcop
		DRIVER(vcop) //t:vcop f:model2.c r: c:
//SET: srallyc
		DRIVER(srallyc) //t:srallyc f:model2.c r: c:
		DRIVER(srallycb) //t:srallycb f:model2.c r:srallyc c:srallyc
//SET: vcop2
		DRIVER(vcop2) //t:vcop2 f:model2.c r: c:
//SET: vf2
		DRIVER(vf2) //t:vf2 f:model2.c r: c:
		DRIVER(vf2o) //t:vf2o f:model2.c r:vf2 c:vf2
		DRIVER(vf2a) //t:vf2a f:model2.c r:vf2 c:vf2
		DRIVER(vf2b) //t:vf2b f:model2.c r:vf2 c:vf2
//SET: manxtt
		DRIVER(manxtt) //t:manxtt f:model2.c r: c:
//SET: motoraid
		DRIVER(motoraid) //t:motoraid f:model2.c r: c:
//SET: dynamcop
		DRIVER(dynamcop) //t:dynamcop f:model2.c r: c:
		DRIVER(dyndeka2) //t:dyndeka2 f:model2.c r:dynamcop c:dynamcop
		DRIVER(dyndeka2b) //t:dyndeka2b f:model2.c r:dynamcop c:dynamcop
		DRIVER(dynamcopb) //t:dynamcopb f:model2.c r:dynamcop c:dynamcop
		DRIVER(dynamcopc) //t:dynamcopc f:model2.c r:dynamcop c:dynamcop
//SET: vstriker
		DRIVER(vstriker) //t:vstriker f:model2.c r: c:
		DRIVER(vstrikero) //t:vstrikero f:model2.c r:vstriker c:vstriker
//SET: rchase2
		DRIVER(rchase2) //t:rchase2 f:model2.c r: c:
//SET: indy500
		DRIVER(indy500) //t:indy500 f:model2.c r: c:
		DRIVER(indy500d) //t:indy500d f:model2.c r:indy500 c:indy500
		DRIVER(indy500to) //t:indy500to f:model2.c r:indy500 c:indy500
//SET: skytargt
		DRIVER(skytargt) //t:skytargt f:model2.c r: c:
//SET: fvipers
		DRIVER(fvipers) //t:fvipers f:model2.c r: c:
//SET: von
		DRIVER(von) //t:von f:model2.c r: c:
		DRIVER(vonj) //t:vonj f:model2.c r:von c:von
//SET: gunblade
		DRIVER(gunblade) //t:gunblade f:model2.c r: c:
//SET: schamp
		DRIVER(schamp) //t:schamp f:model2.c r: c:
		DRIVER(sfight) //t:sfight f:model2.c r:schamp c:schamp
//SET: lastbrnx
		DRIVER(lastbrnx) //t:lastbrnx f:model2.c r: c:
		DRIVER(lastbrnxj) //t:lastbrnxj f:model2.c r:lastbrnx c:lastbrnx
//SET: sgt24h
		DRIVER(sgt24h) //t:sgt24h f:model2.c r: c:
//SET: dynabb
		DRIVER(dynabb) //t:dynabb f:model2.c r: c:
//SET: doa
		DRIVER(doa) //t:doa f:model2.c r: c:
		DRIVER(doaa) //t:doaa f:model2.c r:doa c:doa
//SET: zerogun
		DRIVER(zerogun) //t:zerogun f:model2.c r: c:
		DRIVER(zeroguna) //t:zeroguna f:model2.c r:zerogun c:zerogun
		DRIVER(zerogunj) //t:zerogunj f:model2.c r:zerogun c:zerogun
//SET: pltkids
		DRIVER(pltkids) //t:pltkids f:model2.c r: c:
		DRIVER(pltkidsa) //t:pltkidsa f:model2.c r:pltkids c:pltkids
//SET: skisuprg
		DRIVER(skisuprg) //t:skisuprg f:model2.c r: c:
//SET: stcc
		DRIVER(stcc) //t:stcc f:model2.c r: c:
		DRIVER(stcca) //t:stcca f:model2.c r:stcc c:stcc
		DRIVER(stccb) //t:stccb f:model2.c r:stcc c:stcc
//SET: waverunr
		DRIVER(waverunr) //t:waverunr f:model2.c r: c:
//SET: hotd
		DRIVER(hotd) //t:hotd f:model2.c r: c:
//SET: topskatr
		DRIVER(topskatr) //t:topskatr f:model2.c r: c:
		DRIVER(topskatru) //t:topskatru f:model2.c r:topskatr c:topskatr
		DRIVER(topskatrj) //t:topskatrj f:model2.c r:topskatr c:topskatr
//SET: overrev
		DRIVER(overrev) //t:overrev f:model2.c r: c:
//SET: segawski
		DRIVER(segawski) //t:segawski f:model2.c r: c:
//SET: bel
		DRIVER(bel) //t:bel f:model2.c r: c:
//SET: vf3
		DRIVER(vf3) //t:vf3 f:model3.c r: c:
		DRIVER(vf3a) //t:vf3a f:model3.c r:vf3 c:vf3
		DRIVER(vf3tb) //t:vf3tb f:model3.c r:vf3 c:vf3
//SET: bass
		DRIVER(bass) //t:bass f:model3.c r: c:
		DRIVER(getbass) //t:getbass f:model3.c r:bass c:bass
//SET: scud
		DRIVER(scud) //t:scud f:model3.c r: c:
		DRIVER(scudj) //t:scudj f:model3.c r:scud c:scud
		DRIVER(scuda) //t:scuda f:model3.c r:scud c:scud
		DRIVER(scudp) //t:scudp f:model3.c r:scud c:scud
//SET: lostwsga
		DRIVER(lostwsga) //t:lostwsga f:model3.c r: c:
//SET: lemans24
		DRIVER(lemans24) //t:lemans24 f:model3.c r: c:
//SET: vs2
		DRIVER(vs2) //t:vs2 f:model3.c r: c:
		DRIVER(vs215) //t:vs215 f:model3.c r:vs2 c:vs2
//SET: harley
		DRIVER(harley) //t:harley f:model3.c r: c:
//SET: skichamp
		DRIVER(skichamp) //t:skichamp f:model3.c r: c:
//SET: srally2
		DRIVER(srally2) //t:srally2 f:model3.c r: c:
//SET: srally2x
		DRIVER(srally2x) //t:srally2x f:model3.c r: c:
//SET: von2
		DRIVER(von2) //t:von2 f:model3.c r: c:
		DRIVER(von254g) //t:von254g f:model3.c r:von2 c:von2
//SET: fvipers2
		DRIVER(fvipers2) //t:fvipers2 f:model3.c r: c:
//SET: vs298
		DRIVER(vs298) //t:vs298 f:model3.c r: c:
		DRIVER(vs29815) //t:vs29815 f:model3.c r:vs298 c:vs298
//SET: vs2v991
		DRIVER(vs2v991) //t:vs2v991 f:model3.c r: c:
		DRIVER(vs299) //t:vs299 f:model3.c r:vs2v991 c:vs2v991
		DRIVER(vs299b) //t:vs299b f:model3.c r:vs2v991 c:vs2v991
		DRIVER(vs299a) //t:vs299a f:model3.c r:vs2v991 c:vs2v991
//SET: daytona2
		DRIVER(daytona2) //t:daytona2 f:model3.c r: c:
//SET: oceanhun
		DRIVER(oceanhun) //t:oceanhun f:model3.c r: c:
//SET: spikeout
		DRIVER(spikeout) //t:spikeout f:model3.c r: c:
//SET: dirtdvls
		DRIVER(dirtdvls) //t:dirtdvls f:model3.c r: c:
		DRIVER(dirtdvlsa) //t:dirtdvlsa f:model3.c r:dirtdvls c:dirtdvls
//SET: swtrilgy
		DRIVER(swtrilgy) //t:swtrilgy f:model3.c r: c:
		DRIVER(swtrilgya) //t:swtrilgya f:model3.c r:swtrilgy c:swtrilgy
//SET: lamachin
		DRIVER(lamachin) //t:lamachin f:model3.c r: c:
//SET: dayto2pe
		DRIVER(dayto2pe) //t:dayto2pe f:model3.c r: c:
//SET: spikeofe
		DRIVER(spikeofe) //t:spikeofe f:model3.c r: c:
//SET: magtruck
		DRIVER(magtruck) //t:magtruck f:model3.c r: c:
//SET: eca
		DRIVER(eca) //t:eca f:model3.c r: c:
		DRIVER(ecax) //t:ecax f:model3.c r:eca c:eca
//SET: logicpro
		DRIVER(logicpro) //t:logicpro f:deniam.c r: c:
		DRIVER(croquis) //t:croquis f:deniam.c r:logicpro c:logicpro
//SET: karianx
		DRIVER(karianx) //t:karianx f:deniam.c r: c:
//SET: logicpr2
		DRIVER(logicpr2) //t:logicpr2 f:deniam.c r: c:
//SET: columns
		DRIVER(columns) //t:columns f:segac2.c r: c:
		DRIVER(columnsu) //t:columnsu f:segac2.c r:columns c:columns
		DRIVER(columnsj) //t:columnsj f:segac2.c r:columns c:columns
//SET: columns2
		DRIVER(columns2) //t:columns2 f:segac2.c r: c:
		DRIVER(column2j) //t:column2j f:segac2.c r:columns2 c:columns2
//SET: borench
		DRIVER(borench) //t:borench f:segac2.c r: c:
//SET: tfrceac
		DRIVER(tfrceac) //t:tfrceac f:segac2.c r: c:
		DRIVER(tfrceacj) //t:tfrceacj f:segac2.c r:tfrceac c:tfrceac
		DRIVER(tfrceacb) //t:tfrceacb f:segac2.c r:tfrceac c:tfrceac
//SET: twinsqua
		DRIVER(twinsqua) //t:twinsqua f:segac2.c r: c:
//SET: ribbit
		DRIVER(ribbit) //t:ribbit f:segac2.c r: c:
//SET: tantr
		DRIVER(tantr) //t:tantr f:segac2.c r: c:
		DRIVER(tantrkor) //t:tantrkor f:segac2.c r:tantr c:tantr
		DRIVER(tantrbl) //t:tantrbl f:segac2.c r:tantr c:tantr
		DRIVER(tantrbl2) //t:tantrbl2 f:segac2.c r:tantr c:tantr
		DRIVER(tantrbl3) //t:tantrbl3 f:segac2.c r:tantr c:tantr
//SET: puyo
		DRIVER(puyo) //t:puyo f:segac2.c r: c:
		DRIVER(puyobl) //t:puyobl f:segac2.c r:puyo c:puyo
		DRIVER(puyoj) //t:puyoj f:segac2.c r:puyo c:puyo
		DRIVER(puyoja) //t:puyoja f:segac2.c r:puyo c:puyo
//SET: ichir
		DRIVER(ichir) //t:ichir f:segac2.c r: c:
		DRIVER(ichirk) //t:ichirk f:segac2.c r:ichir c:ichir
		DRIVER(ichirj) //t:ichirj f:segac2.c r:ichir c:ichir
		DRIVER(ichirjbl) //t:ichirjbl f:segac2.c r:ichir c:ichir
//SET: stkclmns
		DRIVER(stkclmns) //t:stkclmns f:segac2.c r: c:
		DRIVER(stkclmnsj) //t:stkclmnsj f:segac2.c r:stkclmns c:stkclmns
//SET: puyopuy2
		DRIVER(puyopuy2) //t:puyopuy2 f:segac2.c r: c:
//SET: potopoto
		DRIVER(potopoto) //t:potopoto f:segac2.c r: c:
//SET: zunkyou
		DRIVER(zunkyou) //t:zunkyou f:segac2.c r: c:
//SET: pclubj
		DRIVER(pclubj) //t:pclubj f:segac2.c r: c:
		DRIVER(pclubjv2) //t:pclubjv2 f:segac2.c r:pclubj c:pclubj
		DRIVER(pclubjv4) //t:pclubjv4 f:segac2.c r:pclubj c:pclubj
		DRIVER(pclubjv5) //t:pclubjv5 f:segac2.c r:pclubj c:pclubj
//SET: puckpkmn
		DRIVER(puckpkmn) //t:puckpkmn f:puckpkmn.c r: c:
		DRIVER(puckpkmna) //t:puckpkmna f:puckpkmn.c r:puckpkmn c:puckpkmn
//SET: topshoot
		DRIVER(topshoot) //t:topshoot f:megadrvb.c r: c:
//SET: megatech
		DRIVER(megatech) //t:megatech f:megatech.c r: c:
//SET: mt_beast
		DRIVER(mt_beast) //t:mt_beast f:megatech.c r:megatech c:
//SET: mt_shar2
		DRIVER(mt_shar2) //t:mt_shar2 f:megatech.c r:megatech c:
//SET: mt_stbld
		DRIVER(mt_stbld) //t:mt_stbld f:megatech.c r:megatech c:
//SET: mt_ggolf
		DRIVER(mt_ggolf) //t:mt_ggolf f:megatech.c r:megatech c:
//SET: mt_gsocr
		DRIVER(mt_gsocr) //t:mt_gsocr f:megatech.c r:megatech c:
//SET: mt_orun
		DRIVER(mt_orun) //t:mt_orun f:megatech.c r:megatech c:
//SET: mt_asyn
		DRIVER(mt_asyn) //t:mt_asyn f:megatech.c r:megatech c:
//SET: mt_shnbi
		DRIVER(mt_shnbi) //t:mt_shnbi f:megatech.c r:megatech c:
//SET: mt_fz
		DRIVER(mt_fz) //t:mt_fz f:megatech.c r:megatech c:
//SET: mt_aftrb
		DRIVER(mt_aftrb) //t:mt_aftrb f:megatech.c r:megatech c:
//SET: mt_tfor2
		DRIVER(mt_tfor2) //t:mt_tfor2 f:megatech.c r:megatech c:
//SET: mt_astro
		DRIVER(mt_astro) //t:mt_astro f:megatech.c r:megatech c:
//SET: mt_gfoot
		DRIVER(mt_gfoot) //t:mt_gfoot f:megatech.c r:megatech c:
//SET: mt_lastb
		DRIVER(mt_lastb) //t:mt_lastb f:megatech.c r:megatech c:
//SET: mt_wcsoc
		DRIVER(mt_wcsoc) //t:mt_wcsoc f:megatech.c r:megatech c:
//SET: mt_tetri
		DRIVER(mt_tetri) //t:mt_tetri f:megatech.c r:megatech c:
//SET: mt_gng
		DRIVER(mt_gng) //t:mt_gng f:megatech.c r:megatech c:
//SET: mt_shang
		DRIVER(mt_shang) //t:mt_shang f:megatech.c r:megatech c:
//SET: mt_gaxe
		DRIVER(mt_gaxe) //t:mt_gaxe f:megatech.c r:megatech c:
//SET: mt_fwrld
		DRIVER(mt_fwrld) //t:mt_fwrld f:megatech.c r:megatech c:
//SET: mt_mystd
		DRIVER(mt_mystd) //t:mt_mystd f:megatech.c r:megatech c:
//SET: mt_revsh
		DRIVER(mt_revsh) //t:mt_revsh f:megatech.c r:megatech c:
//SET: mt_parlg
		DRIVER(mt_parlg) //t:mt_parlg f:megatech.c r:megatech c:
//SET: mt_tgolf
		DRIVER(mt_tgolf) //t:mt_tgolf f:megatech.c r:megatech c:
//SET: mt_srbb
		DRIVER(mt_srbb) //t:mt_srbb f:megatech.c r:megatech c:
//SET: mt_tlbba
		DRIVER(mt_tlbba) //t:mt_tlbba f:megatech.c r:megatech c:
//SET: mt_cols
		DRIVER(mt_cols) //t:mt_cols f:megatech.c r:megatech c:
//SET: mt_eswat
		DRIVER(mt_eswat) //t:mt_eswat f:megatech.c r:megatech c:
//SET: mt_smgp
		DRIVER(mt_smgp) //t:mt_smgp f:megatech.c r:megatech c:
//SET: mt_mwalk
		DRIVER(mt_mwalk) //t:mt_mwalk f:megatech.c r:megatech c:
//SET: mt_crack
		DRIVER(mt_crack) //t:mt_crack f:megatech.c r:megatech c:
//SET: mt_shado
		DRIVER(mt_shado) //t:mt_shado f:megatech.c r:megatech c:
//SET: mt_arrow
		DRIVER(mt_arrow) //t:mt_arrow f:megatech.c r:megatech c:
//SET: mt_astrm
		DRIVER(mt_astrm) //t:mt_astrm f:megatech.c r:megatech c:
//SET: mt_wwar
		DRIVER(mt_wwar) //t:mt_wwar f:megatech.c r:megatech c:
//SET: mt_bbros
		DRIVER(mt_bbros) //t:mt_bbros f:megatech.c r:megatech c:
//SET: mt_srage
		DRIVER(mt_srage) //t:mt_srage f:megatech.c r:megatech c:
//SET: mt_sonic
		DRIVER(mt_sonic) //t:mt_sonic f:megatech.c r:megatech c:
		DRIVER(mt_sonia) //t:mt_sonia f:megatech.c r:mt_sonic c:mt_sonic
//SET: mt_fshrk
		DRIVER(mt_fshrk) //t:mt_fshrk f:megatech.c r:megatech c:
//SET: mt_spman
		DRIVER(mt_spman) //t:mt_spman f:megatech.c r:megatech c:
//SET: mt_calga
		DRIVER(mt_calga) //t:mt_calga f:megatech.c r:megatech c:
//SET: mt_gaxe2
		DRIVER(mt_gaxe2) //t:mt_gaxe2 f:megatech.c r:megatech c:
//SET: mt_stf
		DRIVER(mt_stf) //t:mt_stf f:megatech.c r:megatech c:
//SET: mt_mlh
		DRIVER(mt_mlh) //t:mt_mlh f:megatech.c r:megatech c:
//SET: mt_kcham
		DRIVER(mt_kcham) //t:mt_kcham f:megatech.c r:megatech c:
//SET: mt_tout
		DRIVER(mt_tout) //t:mt_tout f:megatech.c r:megatech c:
//SET: mt_soni2
		DRIVER(mt_soni2) //t:mt_soni2 f:megatech.c r:megatech c:
//SET: megaplay
		DRIVER(megaplay) //t:megaplay f:megaplay.c r: c:
//SET: mp_sonic
		DRIVER(mp_sonic) //t:mp_sonic f:megaplay.c r:megaplay c:
//SET: mp_gaxe2
		DRIVER(mp_gaxe2) //t:mp_gaxe2 f:megaplay.c r:megaplay c:
//SET: mp_gslam
		DRIVER(mp_gslam) //t:mp_gslam f:megaplay.c r:megaplay c:
//SET: mp_twc
		DRIVER(mp_twc) //t:mp_twc f:megaplay.c r:megaplay c:
//SET: mp_sor2
		DRIVER(mp_sor2) //t:mp_sor2 f:megaplay.c r:megaplay c:
//SET: mp_bio
		DRIVER(mp_bio) //t:mp_bio f:megaplay.c r:megaplay c:
//SET: mp_soni2
		DRIVER(mp_soni2) //t:mp_soni2 f:megaplay.c r:megaplay c:
//SET: mp_shnb3
		DRIVER(mp_shnb3) //t:mp_shnb3 f:megaplay.c r:megaplay c:
//SET: mp_mazin
		DRIVER(mp_mazin) //t:mp_mazin f:megaplay.c r:megaplay c:
//SET: mp_col3
		DRIVER(mp_col3) //t:mp_col3 f:megaplay.c r:megaplay c:
//SET: ssf2mdb
		DRIVER(ssf2mdb) //t:ssf2mdb f:megadrvb.c r: c:
//SET: aladmdb
		DRIVER(aladmdb) //t:aladmdb f:megadrvb.c r: c:
//SET: mk3mdb
		DRIVER(mk3mdb) //t:mk3mdb f:megadrvb.c r: c:
//SET: srmdb
		DRIVER(srmdb) //t:srmdb f:megadrvb.c r: c:
#endif

#ifdef PS3_SET_8 //NAOMI
//SET: naomi
		DRIVER(naomi) //t:naomi f:naomi.c r: c:
//SET: naomigd
		DRIVER(naomigd) //t:naomigd f:naomi.c r: c:
//SET: naomi2
		DRIVER(naomi2) //t:naomi2 f:naomi.c r: c:
//SET: hod2bios
		DRIVER(hod2bios) //t:hod2bios f:naomi.c r: c:
//SET: hotd2
		DRIVER(hotd2) //t:hotd2 f:naomi.c r:hod2bios c:
		DRIVER(hotd2o) //t:hotd2o f:naomi.c r:hotd2 c:hotd2
//SET: dybbnao
		DRIVER(dybbnao) //t:dybbnao f:naomi.c r:naomi c:
//SET: smlg99
		DRIVER(smlg99) //t:smlg99 f:naomi.c r:naomi c:
//SET: pstone
		DRIVER(pstone) //t:pstone f:naomi.c r:naomi c:
//SET: crzytaxi
		DRIVER(crzytaxi) //t:crzytaxi f:naomi.c r:naomi c:
//SET: zombrvn
		DRIVER(zombrvn) //t:zombrvn f:naomi.c r:naomi c:
//SET: airlbios
		DRIVER(airlbios) //t:airlbios f:naomi.c r: c:
//SET: alpiltdx
		DRIVER(alpiltdx) //t:alpiltdx f:naomi.c r:airlbios c:
		DRIVER(alpilota) //t:alpilota f:naomi.c r:alpiltdx c:alpiltdx
//SET: ggram2
		DRIVER(ggram2) //t:ggram2 f:naomi.c r:naomi c:
//SET: ringout
		DRIVER(ringout) //t:ringout f:naomi.c r:naomi c:
//SET: f355bios
		DRIVER(f355bios) //t:f355bios f:naomi.c r: c:
//SET: f355
		DRIVER(f355) //t:f355 f:naomi.c r:f355bios c:
//SET: f355twin
		DRIVER(f355twin) //t:f355twin f:naomi.c r:f355bios c:
//SET: shangril
		DRIVER(shangril) //t:shangril f:naomi.c r:naomi c:
//SET: vs2_2k
		DRIVER(vs2_2k) //t:vs2_2k f:naomi.c r:naomi c:
//SET: suchie3
		DRIVER(suchie3) //t:suchie3 f:naomi.c r:naomi c:
//SET: toyfight
		DRIVER(toyfight) //t:toyfight f:naomi.c r:naomi c:
//SET: jambo
		DRIVER(jambo) //t:jambo f:naomi.c r:naomi c:
//SET: sgtetris
		DRIVER(sgtetris) //t:sgtetris f:naomi.c r:naomi c:
//SET: derbyoc
		DRIVER(derbyoc) //t:derbyoc f:naomi.c r:naomi c:
//SET: doa2
		DRIVER(doa2) //t:doa2 f:naomi.c r:naomi c:
		DRIVER(doa2m) //t:doa2m f:naomi.c r:doa2 c:doa2
//SET: otrigger
		DRIVER(otrigger) //t:otrigger f:naomi.c r:naomi c:
//SET: dybb99
		DRIVER(dybb99) //t:dybb99 f:naomi.c r:naomi c:
//SET: samba
		DRIVER(samba) //t:samba f:naomi.c r:naomi c:
//SET: vtennis
		DRIVER(vtennis) //t:vtennis f:naomi.c r:naomi c:
//SET: vtennisg
		DRIVER(vtennisg) //t:vtennisg f:naomi.c r:naomigd c:
//SET: puyoda
		DRIVER(puyoda) //t:puyoda f:naomi.c r:naomi c:
//SET: 18wheelr
		DRIVER(18wheelr) //t:18wheelr f:naomi.c r:naomi c:
//SET: totd
		DRIVER(totd) //t:totd f:naomi.c r:naomi c:
//SET: spawn
		DRIVER(spawn) //t:spawn f:naomi.c r:naomi c:
//SET: virnba
		DRIVER(virnba) //t:virnba f:naomi.c r:naomi c:
		DRIVER(virnbao) //t:virnbao f:naomi.c r:virnba c:virnba
//SET: mvsc2
		DRIVER(mvsc2) //t:mvsc2 f:naomi.c r:naomi c:
//SET: smarinef
		DRIVER(smarinef) //t:smarinef f:naomi.c r:naomi c:
//SET: wldkicks
		DRIVER(wldkicks) //t:wldkicks f:naomi.c r:naomi c:
//SET: pstone2
		DRIVER(pstone2) //t:pstone2 f:naomi.c r:naomi c:
//SET: qmegamis
		DRIVER(qmegamis) //t:qmegamis f:naomi.c r:naomi c:
//SET: vonot
		DRIVER(vonot) //t:vonot f:naomi.c r:naomi c:
//SET: derbyo2k
		DRIVER(derbyo2k) //t:derbyo2k f:naomi.c r:naomi c:
//SET: ggx
		DRIVER(ggx) //t:ggx f:naomi.c r:naomi c:
//SET: slasho
		DRIVER(slasho) //t:slasho f:naomi.c r:naomi c:
//SET: slashout
		DRIVER(slashout) //t:slashout f:naomi.c r:naomigd c:
//SET: capsnk
		DRIVER(capsnk) //t:capsnk f:naomi.c r:naomi c:
		DRIVER(capsnka) //t:capsnka f:naomi.c r:capsnk c:capsnk
//SET: gram2000
		DRIVER(gram2000) //t:gram2000 f:naomi.c r:naomi c:
//SET: crackndj
		DRIVER(crackndj) //t:crackndj f:naomi.c r:naomi c:
//SET: cspike
		DRIVER(cspike) //t:cspike f:naomi.c r:naomi c:
//SET: sstrkfgt
		DRIVER(sstrkfgt) //t:sstrkfgt f:naomi.c r:naomi c:
//SET: deathcox
		DRIVER(deathcox) //t:deathcox f:naomi.c r:naomi c:
//SET: confmiss
		DRIVER(confmiss) //t:confmiss f:naomi.c r:naomigd c:
//SET: shaktamb
		DRIVER(shaktamb) //t:shaktamb f:naomi.c r:naomigd c:
//SET: wwfroyal
		DRIVER(wwfroyal) //t:wwfroyal f:naomi.c r:naomi c:
//SET: pjustic
		DRIVER(pjustic) //t:pjustic f:naomi.c r:naomi c:
//SET: samba2k
		DRIVER(samba2k) //t:samba2k f:naomi.c r:naomi c:
//SET: sprtjam
		DRIVER(sprtjam) //t:sprtjam f:naomi.c r:naomigd c:
//SET: derbyocw
		DRIVER(derbyocw) //t:derbyocw f:naomi.c r:naomi c:
		DRIVER(drbyocwc) //t:drbyocwc f:naomi.c r:derbyocw c:derbyocw
//SET: f355twn2
		DRIVER(f355twn2) //t:f355twn2 f:naomi.c r:f355bios c:
//SET: gwing2
		DRIVER(gwing2) //t:gwing2 f:naomi.c r:naomi c:
//SET: csmash
		DRIVER(csmash) //t:csmash f:naomi.c r:naomi c:
		DRIVER(csmasho) //t:csmasho f:naomi.c r:csmash c:csmash
//SET: sfz3ugd
		DRIVER(sfz3ugd) //t:sfz3ugd f:naomi.c r:naomigd c:
//SET: gundmgd
		DRIVER(gundmgd) //t:gundmgd f:naomi.c r:naomigd c:
//SET: gundmct
		DRIVER(gundmct) //t:gundmct f:naomi.c r:naomi c:
//SET: dygolf
		DRIVER(dygolf) //t:dygolf f:naomi.c r:naomigd c:
//SET: zerogu2
		DRIVER(zerogu2) //t:zerogu2 f:naomi.c r:naomi c:
//SET: monkeyba
		DRIVER(monkeyba) //t:monkeyba f:naomi.c r:naomigd c:
//SET: cvsgd
		DRIVER(cvsgd) //t:cvsgd f:naomi.c r:naomigd c:
//SET: wsbbgd
		DRIVER(wsbbgd) //t:wsbbgd f:naomi.c r:naomigd c:
//SET: spkrbtl
		DRIVER(spkrbtl) //t:spkrbtl f:naomi.c r:naomigd c:
//SET: gunsur2
		DRIVER(gunsur2) //t:gunsur2 f:naomi.c r:naomi c:
//SET: starseek
		DRIVER(starseek) //t:starseek f:naomi.c r:naomigd c:
//SET: cvs2gd
		DRIVER(cvs2gd) //t:cvs2gd f:naomi.c r:naomigd c:
//SET: wrungp
		DRIVER(wrungp) //t:wrungp f:naomi.c r:naomi c:
//SET: gundmxgd
		DRIVER(gundmxgd) //t:gundmxgd f:naomi.c r:naomigd c:
//SET: hmgeo
		DRIVER(hmgeo) //t:hmgeo f:naomi.c r:naomi c:
//SET: inunoos
		DRIVER(inunoos) //t:inunoos f:naomi.c r:naomi c:
//SET: derbyoc2
		DRIVER(derbyoc2) //t:derbyoc2 f:naomi.c r:naomi c:
//SET: vtennis2
		DRIVER(vtennis2) //t:vtennis2 f:naomi.c r:naomigd c:
//SET: vtenis2c
		DRIVER(vtenis2c) //t:vtenis2c f:naomi.c r:naomi c:
//SET: keyboard
		DRIVER(keyboard) //t:keyboard f:naomi.c r:naomigd c:
//SET: ikaruga
		DRIVER(ikaruga) //t:ikaruga f:naomi.c r:naomigd c:
//SET: lupinsho
		DRIVER(lupinsho) //t:lupinsho f:naomi.c r:naomigd c:
//SET: vathlete
		DRIVER(vathlete) //t:vathlete f:naomi.c r:naomigd c:
//SET: luptype
		DRIVER(luptype) //t:luptype f:naomi.c r:naomigd c:
//SET: ggxx
		DRIVER(ggxx) //t:ggxx f:naomi.c r:naomigd c:
//SET: mok
		DRIVER(mok) //t:mok f:naomi.c r:naomigd c:
//SET: cleoftp
		DRIVER(cleoftp) //t:cleoftp f:naomi.c r:naomigd c:
//SET: chocomk
		DRIVER(chocomk) //t:chocomk f:naomi.c r:naomigd c:
//SET: azumanga
		DRIVER(azumanga) //t:azumanga f:naomi.c r:naomigd c:
//SET: moeru
		DRIVER(moeru) //t:moeru f:naomi.c r:naomigd c:
//SET: quizqgd
		DRIVER(quizqgd) //t:quizqgd f:naomi.c r:naomigd c:
//SET: ggxxrl
		DRIVER(ggxxrl) //t:ggxxrl f:naomi.c r:naomigd c:
//SET: shikgam2
		DRIVER(shikgam2) //t:shikgam2 f:naomi.c r:naomigd c:
//SET: bdrdown
		DRIVER(bdrdown) //t:bdrdown f:naomi.c r:naomigd c:
//SET: usagui
		DRIVER(usagui) //t:usagui f:naomi.c r:naomigd c:
//SET: oinori
		DRIVER(oinori) //t:oinori f:naomi.c r:naomi c:
//SET: psyvar2
		DRIVER(psyvar2) //t:psyvar2 f:naomi.c r:naomigd c:
//SET: puyofev
		DRIVER(puyofev) //t:puyofev f:naomi.c r:naomigd c:
//SET: shootopl
		DRIVER(shootopl) //t:shootopl f:naomi.c r:naomi c:
//SET: shootpl
		DRIVER(shootpl) //t:shootpl f:naomi.c r:naomi c:
//SET: shootplm
		DRIVER(shootplm) //t:shootplm f:naomi.c r:naomi c:
//SET: kick4csh
		DRIVER(kick4csh) //t:kick4csh f:naomi.c r:naomi c:
//SET: tetkiwam
		DRIVER(tetkiwam) //t:tetkiwam f:naomi.c r:naomigd c:
//SET: cfield
		DRIVER(cfield) //t:cfield f:naomi.c r:naomigd c:
//SET: trizeal
		DRIVER(trizeal) //t:trizeal f:naomi.c r:naomigd c:
//SET: ss2005
		DRIVER(ss2005) //t:ss2005 f:naomi.c r:naomigd c:
		DRIVER(ss2005a) //t:ss2005a f:naomi.c r:ss2005 c:ss2005
//SET: senko
		DRIVER(senko) //t:senko f:naomi.c r:naomigd c:
		DRIVER(senkoo) //t:senkoo f:naomi.c r:senko c:senko
//SET: meltybld
		DRIVER(meltybld) //t:meltybld f:naomi.c r:naomigd c:
//SET: ggxxsla
		DRIVER(ggxxsla) //t:ggxxsla f:naomi.c r:naomigd c:
//SET: radirgy
		DRIVER(radirgy) //t:radirgy f:naomi.c r:naomigd c:
//SET: undefeat
		DRIVER(undefeat) //t:undefeat f:naomi.c r:naomigd c:
//SET: kurucham
		DRIVER(kurucham) //t:kurucham f:naomi.c r:naomigd c:
//SET: trgheart
		DRIVER(trgheart) //t:trgheart f:naomi.c r:naomigd c:
//SET: senkosp
		DRIVER(senkosp) //t:senkosp f:naomi.c r:naomigd c:
//SET: jingystm
		DRIVER(jingystm) //t:jingystm f:naomi.c r:naomigd c:
//SET: karous
		DRIVER(karous) //t:karous f:naomi.c r:naomigd c:
//SET: ggxxac
		DRIVER(ggxxac) //t:ggxxac f:naomi.c r:naomigd c:
//SET: meltyb
		DRIVER(meltyb) //t:meltyb f:naomi.c r:naomigd c:
		DRIVER(meltyba) //t:meltyba f:naomi.c r:meltyb c:meltyb
//SET: takoron
		DRIVER(takoron) //t:takoron f:naomi.c r:naomigd c:
//SET: ngdup23a
		DRIVER(ngdup23a) //t:ngdup23a f:naomi.c r:naomigd c:
//SET: ngdup23c
		DRIVER(ngdup23c) //t:ngdup23c f:naomi.c r:naomigd c:
//SET: vstrik3c
		DRIVER(vstrik3c) //t:vstrik3c f:naomi.c r:naomi2 c:
		DRIVER(vstrik3cb) //t:vstrik3cb f:naomi.c r:vstrik3c c:vstrik3c
//SET: vstrik3
		DRIVER(vstrik3) //t:vstrik3 f:naomi.c r:naomi2 c:
//SET: wldrider
		DRIVER(wldrider) //t:wldrider f:naomi.c r:naomi2 c:
//SET: beachspi
		DRIVER(beachspi) //t:beachspi f:naomi.c r:naomi2 c:
//SET: vf4cart
		DRIVER(vf4cart) //t:vf4cart f:naomi.c r:naomi2 c:
//SET: vf4
		DRIVER(vf4) //t:vf4 f:naomi.c r:naomi2 c:
		DRIVER(vf4b) //t:vf4b f:naomi.c r:vf4 c:vf4
		DRIVER(vf4c) //t:vf4c f:naomi.c r:vf4 c:vf4
//SET: kingrt66
		DRIVER(kingrt66) //t:kingrt66 f:naomi.c r:naomi2 c:
//SET: initd
		DRIVER(initd) //t:initd f:naomi.c r:naomi2 c:
//SET: initdexp
		DRIVER(initdexp) //t:initdexp f:naomi.c r:naomi2 c:
//SET: clubkrte
		DRIVER(clubkrte) //t:clubkrte f:naomi.c r:naomi2 c:
//SET: vf4evoct
		DRIVER(vf4evoct) //t:vf4evoct f:naomi.c r:naomi2 c:
//SET: initdv2j
		DRIVER(initdv2j) //t:initdv2j f:naomi.c r:naomigd c:
		DRIVER(initdv2jo) //t:initdv2jo f:naomi.c r:initdv2j c:initdv2j
//SET: initdv2e
		DRIVER(initdv2e) //t:initdv2e f:naomi.c r:naomigd c:
//SET: vf4evo
		DRIVER(vf4evo) //t:vf4evo f:naomi.c r:naomi2 c:
		DRIVER(vf4evoa) //t:vf4evoa f:naomi.c r:vf4evo c:vf4evo
//SET: initdv3j
		DRIVER(initdv3j) //t:initdv3j f:naomi.c r:naomigd c:
		DRIVER(initdv3jb) //t:initdv3jb f:naomi.c r:initdv3j c:initdv3j
//SET: vf4tuned
		DRIVER(vf4tuned) //t:vf4tuned f:naomi.c r:naomi2 c:
		DRIVER(vf4tuneda) //t:vf4tuneda f:naomi.c r:vf4tuned c:vf4tuned
		DRIVER(vf4tunedd) //t:vf4tunedd f:naomi.c r:vf4tuned c:vf4tuned
//SET: awbios
		DRIVER(awbios) //t:awbios f:naomi.c r: c:
//SET: maxspeed
		DRIVER(maxspeed) //t:maxspeed f:naomi.c r:awbios c:
//SET: sprtshot
		DRIVER(sprtshot) //t:sprtshot f:naomi.c r:awbios c:
//SET: ggx15
		DRIVER(ggx15) //t:ggx15 f:naomi.c r:awbios c:
//SET: demofist
		DRIVER(demofist) //t:demofist f:naomi.c r:awbios c:
//SET: dolphin
		DRIVER(dolphin) //t:dolphin f:naomi.c r:awbios c:
//SET: ggisuka
		DRIVER(ggisuka) //t:ggisuka f:naomi.c r:awbios c:
//SET: rumblef
		DRIVER(rumblef) //t:rumblef f:naomi.c r:awbios c:
//SET: rangrmsn
		DRIVER(rangrmsn) //t:rangrmsn f:naomi.c r:awbios c:
//SET: salmankt
		DRIVER(salmankt) //t:salmankt f:naomi.c r:awbios c:
//SET: kofnw
		DRIVER(kofnw) //t:kofnw f:naomi.c r:awbios c:
		DRIVER(kofnwj) //t:kofnwj f:naomi.c r:kofnw c:kofnw
//SET: xtrmhunt
		DRIVER(xtrmhunt) //t:xtrmhunt f:naomi.c r:awbios c:
//SET: dirtypig
		DRIVER(dirtypig) //t:dirtypig f:naomi.c r:awbios c:
//SET: ftspeed
		DRIVER(ftspeed) //t:ftspeed f:naomi.c r:awbios c:
//SET: kov7sprt
		DRIVER(kov7sprt) //t:kov7sprt f:naomi.c r:awbios c:
//SET: vfurlong
		DRIVER(vfurlong) //t:vfurlong f:naomi.c r:awbios c:
//SET: rumblef2
		DRIVER(rumblef2) //t:rumblef2 f:naomi.c r:awbios c:
//SET: ngbc
		DRIVER(ngbc) //t:ngbc f:naomi.c r:awbios c:
//SET: samsptk
		DRIVER(samsptk) //t:samsptk f:naomi.c r:awbios c:
//SET: kofxi
		DRIVER(kofxi) //t:kofxi f:naomi.c r:awbios c:
//SET: fotns
		DRIVER(fotns) //t:fotns f:naomi.c r:awbios c:
//SET: mslug6
		DRIVER(mslug6) //t:mslug6 f:naomi.c r:awbios c:
//SET: xtrmhnt2
		DRIVER(xtrmhnt2) //t:xtrmhnt2 f:naomi.c r:awbios c:
#endif

#ifdef PS3_SET_9
//SET: hikaru
		DRIVER(hikaru) //t:hikaru f:hikaru.c r: c:
//SET: braveff
		DRIVER(braveff) //t:braveff f:hikaru.c r:hikaru c:
//SET: podrace
		DRIVER(podrace) //t:podrace f:hikaru.c r:hikaru c:
//SET: sgnascar
		DRIVER(sgnascar) //t:sgnascar f:hikaru.c r:hikaru c:
//SET: pharrier
		DRIVER(pharrier) //t:pharrier f:hikaru.c r:hikaru c:
//SET: airtrix
		DRIVER(airtrix) //t:airtrix f:hikaru.c r:hikaru c:
//SET: triforce
		DRIVER(triforce) //t:triforce f:triforce.c r: c:
//SET: vs2002j
		DRIVER(vs2002j) //t:vs2002j f:triforce.c r:triforce c:
//SET: vs2002ex
		DRIVER(vs2002ex) //t:vs2002ex f:triforce.c r:triforce c:
//SET: avalons
		DRIVER(avalons) //t:avalons f:triforce.c r:triforce c:
//SET: gekpurya
		DRIVER(gekpurya) //t:gekpurya f:triforce.c r:triforce c:
//SET: avalon13
		DRIVER(avalon13) //t:avalon13 f:triforce.c r:triforce c:
//SET: vs4
		DRIVER(vs4) //t:vs4 f:triforce.c r:triforce c:
//SET: vs4j
		DRIVER(vs4j) //t:vs4j f:triforce.c r:triforce c:
//SET: avalon20
		DRIVER(avalon20) //t:avalon20 f:triforce.c r:triforce c:
//SET: vs42006
		DRIVER(vs42006) //t:vs42006 f:triforce.c r:triforce c:
//SET: tfupdate
		DRIVER(tfupdate) //t:tfupdate f:triforce.c r:triforce c:
//SET: chihiro
		DRIVER(chihiro) //t:chihiro f:chihiro.c r: c:
//SET: hotd3
		DRIVER(hotd3) //t:hotd3 f:chihiro.c r:chihiro c:
//SET: crtaxihr
		DRIVER(crtaxihr) //t:crtaxihr f:chihiro.c r:chihiro c:
//SET: vcop3
		DRIVER(vcop3) //t:vcop3 f:chihiro.c r:chihiro c:
//SET: outr2
		DRIVER(outr2) //t:outr2 f:chihiro.c r:chihiro c:
//SET: ollie
		DRIVER(ollie) //t:ollie f:chihiro.c r:chihiro c:
//SET: wangmid
		DRIVER(wangmid) //t:wangmid f:chihiro.c r:chihiro c:
//SET: mj2
		DRIVER(mj2) //t:mj2 f:chihiro.c r:chihiro c:
//SET: outr2st
		DRIVER(outr2st) //t:outr2st f:chihiro.c r:chihiro c:
//SET: ghostsqu
		DRIVER(ghostsqu) //t:ghostsqu f:chihiro.c r:chihiro c:
//SET: gundamos
		DRIVER(gundamos) //t:gundamos f:chihiro.c r:chihiro c:
//SET: wangmid2
		DRIVER(wangmid2) //t:wangmid2 f:chihiro.c r:chihiro c:
//SET: wangmd2b
		DRIVER(wangmd2b) //t:wangmd2b f:chihiro.c r:chihiro c:
//SET: mj3
		DRIVER(mj3) //t:mj3 f:chihiro.c r:chihiro c:
//SET: scg06nt
		DRIVER(scg06nt) //t:scg06nt f:chihiro.c r:chihiro c:
//SET: hshavoc
		DRIVER(hshavoc) //t:hshavoc f:hshavoc.c r: c:
//SET: lnc
		DRIVER(lnc) //t:lnc f:btime.c r: c:
//SET: zoar
		DRIVER(zoar) //t:zoar f:btime.c r: c:
//SET: btime
		DRIVER(btime) //t:btime f:btime.c r: c:
		DRIVER(btime2) //t:btime2 f:btime.c r:btime c:btime
		DRIVER(btimem) //t:btimem f:btime.c r:btime c:btime
		DRIVER(cookrace) //t:cookrace f:btime.c r:btime c:btime
//SET: tisland
		DRIVER(tisland) //t:tisland f:btime.c r: c:
//SET: protennb
		DRIVER(protennb) //t:protennb f:btime.c r: c:
//SET: wtennis
		DRIVER(wtennis) //t:wtennis f:btime.c r: c:
//SET: brubber
		DRIVER(brubber) //t:brubber f:btime.c r: c:
		DRIVER(bnj) //t:bnj f:btime.c r:brubber c:brubber
		DRIVER(caractn) //t:caractn f:btime.c r:brubber c:brubber
//SET: disco
		DRIVER(disco) //t:disco f:btime.c r: c:
		DRIVER(discof) //t:discof f:btime.c r:disco c:disco
//SET: sdtennis
		DRIVER(sdtennis) //t:sdtennis f:btime.c r: c:
//SET: mmonkey
		DRIVER(mmonkey) //t:mmonkey f:btime.c r: c:
//SET: decocass
		DRIVER(decocass) //t:decocass f:decocass.c r: c:
//SET: ctsttape
		DRIVER(ctsttape) //t:ctsttape f:decocass.c r:decocass c:
//SET: chwy
		DRIVER(chwy) //t:chwy f:decocass.c r:decocass c:
//SET: cterrani
		DRIVER(cterrani) //t:cterrani f:decocass.c r:decocass c:
//SET: castfant
		DRIVER(castfant) //t:castfant f:decocass.c r:decocass c:
//SET: csuperas
		DRIVER(csuperas) //t:csuperas f:decocass.c r:decocass c:
//SET: clocknch
		DRIVER(clocknch) //t:clocknch f:decocass.c r:decocass c:
//SET: cprogolf
		DRIVER(cprogolf) //t:cprogolf f:decocass.c r:decocass c:
//SET: cluckypo
		DRIVER(cluckypo) //t:cluckypo f:decocass.c r:decocass c:
//SET: ctisland
		DRIVER(ctisland) //t:ctisland f:decocass.c r:decocass c:
		DRIVER(ctisland2) //t:ctisland2 f:decocass.c r:ctisland c:ctisland
		DRIVER(ctisland3) //t:ctisland3 f:decocass.c r:ctisland c:ctisland
//SET: cexplore
		DRIVER(cexplore) //t:cexplore f:decocass.c r:decocass c:
//SET: cdiscon1
		DRIVER(cdiscon1) //t:cdiscon1 f:decocass.c r:decocass c:
		DRIVER(csweetht) //t:csweetht f:decocass.c r:cdiscon1 c:cdiscon1
//SET: ctornado
		DRIVER(ctornado) //t:ctornado f:decocass.c r:decocass c:
//SET: cmissnx
		DRIVER(cmissnx) //t:cmissnx f:decocass.c r:decocass c:
//SET: cptennis
		DRIVER(cptennis) //t:cptennis f:decocass.c r:decocass c:
//SET: cbtime
		DRIVER(cbtime) //t:cbtime f:decocass.c r:decocass c:
//SET: cburnrub
		DRIVER(cburnrub) //t:cburnrub f:decocass.c r:decocass c:
		DRIVER(cburnrub2) //t:cburnrub2 f:decocass.c r:cburnrub c:cburnrub
		DRIVER(cbnj) //t:cbnj f:decocass.c r:cburnrub c:cburnrub
//SET: cgraplop
		DRIVER(cgraplop) //t:cgraplop f:decocass.c r:decocass c:
		DRIVER(cgraplop2) //t:cgraplop2 f:decocass.c r:cgraplop c:cgraplop
//SET: clapapa
		DRIVER(clapapa) //t:clapapa f:decocass.c r:decocass c:
		DRIVER(clapapa2) //t:clapapa2 f:decocass.c r:clapapa c:clapapa
//SET: cprobowl
		DRIVER(cprobowl) //t:cprobowl f:decocass.c r:decocass c:
//SET: cnightst
		DRIVER(cnightst) //t:cnightst f:decocass.c r:decocass c:
		DRIVER(cnightst2) //t:cnightst2 f:decocass.c r:cnightst c:cnightst
//SET: cprosocc
		DRIVER(cprosocc) //t:cprosocc f:decocass.c r:decocass c:
//SET: cflyball
		DRIVER(cflyball) //t:cflyball f:decocass.c r:decocass c:
//SET: czeroize
		DRIVER(czeroize) //t:czeroize f:decocass.c r:decocass c:
//SET: cscrtry
		DRIVER(cscrtry) //t:cscrtry f:decocass.c r:decocass c:
		DRIVER(cscrtry2) //t:cscrtry2 f:decocass.c r:cscrtry c:cscrtry
//SET: cppicf
		DRIVER(cppicf) //t:cppicf f:decocass.c r:decocass c:
		DRIVER(cppicf2) //t:cppicf2 f:decocass.c r:cppicf c:cppicf
//SET: cfghtice
		DRIVER(cfghtice) //t:cfghtice f:decocass.c r:decocass c:
//SET: cbdash
		DRIVER(cbdash) //t:cbdash f:decocass.c r:decocass c:
//SET: begas
		DRIVER(begas) //t:begas f:deco_ld.c r: c:
		DRIVER(begas1) //t:begas1 f:deco_ld.c r:begas c:begas
//SET: cobra
		DRIVER(cobra) //t:cobra f:deco_ld.c r: c:
		DRIVER(cobram3) //t:cobram3 f:gottlieb.c r:cobra c:cobra
//SET: rblaster
		DRIVER(rblaster) //t:rblaster f:deco_ld.c r: c:
//SET: madalien
		DRIVER(madalien) //t:madalien f:madalien.c r: c:
		DRIVER(madaliena) //t:madaliena f:madalien.c r:madalien c:madalien
//SET: astrof
		DRIVER(astrof) //t:astrof f:astrof.c r: c:
		DRIVER(astrof2) //t:astrof2 f:astrof.c r:astrof c:astrof
		DRIVER(astrof3) //t:astrof3 f:astrof.c r:astrof c:astrof
		DRIVER(abattle) //t:abattle f:astrof.c r:astrof c:astrof
		DRIVER(abattle2) //t:abattle2 f:astrof.c r:astrof c:astrof
		DRIVER(afire) //t:afire f:astrof.c r:astrof c:astrof
		DRIVER(acombat) //t:acombat f:astrof.c r:astrof c:astrof
		DRIVER(acombato) //t:acombato f:astrof.c r:astrof c:astrof
		DRIVER(sstarbtl) //t:sstarbtl f:astrof.c r:astrof c:astrof
//SET: spfghmk2
		DRIVER(spfghmk2) //t:spfghmk2 f:astrof.c r: c:
		DRIVER(spfghmk22) //t:spfghmk22 f:astrof.c r:spfghmk2 c:spfghmk2
//SET: tomahawk
		DRIVER(tomahawk) //t:tomahawk f:astrof.c r: c:
		DRIVER(tomahawk1) //t:tomahawk1 f:astrof.c r:tomahawk c:tomahawk
//SET: progolf
		DRIVER(progolf) //t:progolf f:progolf.c r: c:
		DRIVER(progolfa) //t:progolfa f:progolf.c r:progolf c:progolf
//SET: deshoros
		DRIVER(deshoros) //t:deshoros f:deshoros.c r: c:
//SET: prosoccr
		DRIVER(prosoccr) //t:prosoccr f:liberate.c r: c:
//SET: prosport
		DRIVER(prosport) //t:prosport f:liberate.c r: c:
		DRIVER(prosporta) //t:prosporta f:liberate.c r:prosport c:prosport
//SET: boomrang
		DRIVER(boomrang) //t:boomrang f:liberate.c r: c:
		DRIVER(boomranga) //t:boomranga f:liberate.c r:boomrang c:boomrang
//SET: kamikcab
		DRIVER(kamikcab) //t:kamikcab f:liberate.c r: c:
		DRIVER(yellowcbj) //t:yellowcbj f:liberate.c r:kamikcab c:kamikcab
		DRIVER(yellowcbb) //t:yellowcbb f:liberate.c r:kamikcab c:kamikcab
//SET: liberate
		DRIVER(liberate) //t:liberate f:liberate.c r: c:
		DRIVER(dualaslt) //t:dualaslt f:liberate.c r:liberate c:liberate
		DRIVER(liberateb) //t:liberateb f:liberate.c r:liberate c:liberate
//SET: bwings
		DRIVER(bwings) //t:bwings f:bwing.c r: c:
		DRIVER(bwingso) //t:bwingso f:bwing.c r:bwings c:bwings
		DRIVER(bwingsa) //t:bwingsa f:bwing.c r:bwings c:bwings
//SET: zaviga
		DRIVER(zaviga) //t:zaviga f:bwing.c r: c:
		DRIVER(zavigaj) //t:zavigaj f:bwing.c r:zaviga c:zaviga
//SET: kchamp
		DRIVER(kchamp) //t:kchamp f:kchamp.c r: c:
		DRIVER(karatedo) //t:karatedo f:kchamp.c r:kchamp c:kchamp
		DRIVER(kchampvs) //t:kchampvs f:kchamp.c r:kchamp c:kchamp
		DRIVER(kchampvs2) //t:kchampvs2 f:kchamp.c r:kchamp c:kchamp
		DRIVER(karatevs) //t:karatevs f:kchamp.c r:kchamp c:kchamp
//SET: compgolf
		DRIVER(compgolf) //t:compgolf f:compgolf.c r: c:
		DRIVER(compgolfo) //t:compgolfo f:compgolf.c r:compgolf c:compgolf
//SET: cntsteer
		DRIVER(cntsteer) //t:cntsteer f:cntsteer.c r: c:
//SET: zerotrgt
		DRIVER(zerotrgt) //t:zerotrgt f:cntsteer.c r: c:
		DRIVER(zerotrgta) //t:zerotrgta f:cntsteer.c r:zerotrgt c:zerotrgt
		DRIVER(gekitsui) //t:gekitsui f:cntsteer.c r:zerotrgt c:zerotrgt
//SET: tryout
		DRIVER(tryout) //t:tryout f:tryout.c r: c:
//SET: firetrap
		DRIVER(firetrap) //t:firetrap f:firetrap.c r: c:
		DRIVER(firetrapj) //t:firetrapj f:firetrap.c r:firetrap c:firetrap
		DRIVER(firetrapbl) //t:firetrapbl f:firetrap.c r:firetrap c:firetrap
//SET: metlclsh
		DRIVER(metlclsh) //t:metlclsh f:metlclsh.c r: c:
//SET: chanbara
		DRIVER(chanbara) //t:chanbara f:chanbara.c r: c:
//SET: brkthru
		DRIVER(brkthru) //t:brkthru f:brkthru.c r: c:
		DRIVER(brkthruj) //t:brkthruj f:brkthru.c r:brkthru c:brkthru
		DRIVER(forcebrk) //t:forcebrk f:brkthru.c r:brkthru c:brkthru
//SET: darwin
		DRIVER(darwin) //t:darwin f:brkthru.c r: c:
//SET: shootout
		DRIVER(shootout) //t:shootout f:shootout.c r: c:
		DRIVER(shootoutj) //t:shootoutj f:shootout.c r:shootout c:shootout
		DRIVER(shootoutb) //t:shootoutb f:shootout.c r:shootout c:shootout
//SET: sidepckt
		DRIVER(sidepckt) //t:sidepckt f:sidepckt.c r: c:
		DRIVER(sidepcktj) //t:sidepcktj f:sidepckt.c r:sidepckt c:sidepckt
		DRIVER(sidepcktb) //t:sidepcktb f:sidepckt.c r:sidepckt c:sidepckt
//SET: exprraid
		DRIVER(exprraid) //t:exprraid f:exprraid.c r: c:
		DRIVER(exprraida) //t:exprraida f:exprraid.c r:exprraid c:exprraid
		DRIVER(wexpress) //t:wexpress f:exprraid.c r:exprraid c:exprraid
		DRIVER(wexpressb) //t:wexpressb f:exprraid.c r:exprraid c:exprraid
		DRIVER(wexpressb2) //t:wexpressb2 f:exprraid.c r:exprraid c:exprraid
//SET: pcktgal
		DRIVER(pcktgal) //t:pcktgal f:pcktgal.c r: c:
		DRIVER(pcktgalb) //t:pcktgalb f:pcktgal.c r:pcktgal c:pcktgal
		DRIVER(pcktgal2) //t:pcktgal2 f:pcktgal.c r:pcktgal c:pcktgal
		DRIVER(pcktgal2j) //t:pcktgal2j f:pcktgal.c r:pcktgal c:pcktgal
		DRIVER(spool3) //t:spool3 f:pcktgal.c r:pcktgal c:pcktgal
		DRIVER(spool3i) //t:spool3i f:pcktgal.c r:pcktgal c:pcktgal
//SET: pokechmp
		DRIVER(pokechmp) //t:pokechmp f:pokechmp.c r: c:
//SET: battlera
		DRIVER(battlera) //t:battlera f:battlera.c r: c:
		DRIVER(bldwolf) //t:bldwolf f:battlera.c r:battlera c:battlera
		DRIVER(bldwolfj) //t:bldwolfj f:battlera.c r:battlera c:battlera
//SET: actfancr
		DRIVER(actfancr) //t:actfancr f:actfancr.c r: c:
		DRIVER(actfancr1) //t:actfancr1 f:actfancr.c r:actfancr c:actfancr
		DRIVER(actfancrj) //t:actfancrj f:actfancr.c r:actfancr c:actfancr
//SET: triothep
		DRIVER(triothep) //t:triothep f:actfancr.c r: c:
		DRIVER(triothepj) //t:triothepj f:actfancr.c r:triothep c:triothep
//SET: lastmisn
		DRIVER(lastmisn) //t:lastmisn f:dec8.c r: c:
		DRIVER(lastmisno) //t:lastmisno f:dec8.c r:lastmisn c:lastmisn
		DRIVER(lastmisnj) //t:lastmisnj f:dec8.c r:lastmisn c:lastmisn
//SET: shackled
		DRIVER(shackled) //t:shackled f:dec8.c r: c:
		DRIVER(breywood) //t:breywood f:dec8.c r:shackled c:shackled
//SET: csilver
		DRIVER(csilver) //t:csilver f:dec8.c r: c:
		DRIVER(csilverj) //t:csilverj f:dec8.c r:csilver c:csilver
//SET: ghostb
		DRIVER(ghostb) //t:ghostb f:dec8.c r: c:
		DRIVER(ghostb3) //t:ghostb3 f:dec8.c r:ghostb c:ghostb
		DRIVER(meikyuh) //t:meikyuh f:dec8.c r:ghostb c:ghostb
		DRIVER(meikyuha) //t:meikyuha f:dec8.c r:ghostb c:ghostb
//SET: srdarwin
		DRIVER(srdarwin) //t:srdarwin f:dec8.c r: c:
		DRIVER(srdarwinj) //t:srdarwinj f:dec8.c r:srdarwin c:srdarwin
//SET: gondo
		DRIVER(gondo) //t:gondo f:dec8.c r: c:
		DRIVER(makyosen) //t:makyosen f:dec8.c r:gondo c:gondo
//SET: garyoret
		DRIVER(garyoret) //t:garyoret f:dec8.c r: c:
//SET: cobracom
		DRIVER(cobracom) //t:cobracom f:dec8.c r: c:
		DRIVER(cobracomj) //t:cobracomj f:dec8.c r:cobracom c:cobracom
//SET: oscar
		DRIVER(oscar) //t:oscar f:dec8.c r: c:
		DRIVER(oscaru) //t:oscaru f:dec8.c r:oscar c:oscar
		DRIVER(oscarj1) //t:oscarj1 f:dec8.c r:oscar c:oscar
		DRIVER(oscarj2) //t:oscarj2 f:dec8.c r:oscar c:oscar
//SET: karnov
		DRIVER(karnov) //t:karnov f:karnov.c r: c:
		DRIVER(karnovj) //t:karnovj f:karnov.c r:karnov c:karnov
//SET: wndrplnt
		DRIVER(wndrplnt) //t:wndrplnt f:karnov.c r: c:
//SET: chelnov
		DRIVER(chelnov) //t:chelnov f:karnov.c r: c:
		DRIVER(chelnovu) //t:chelnovu f:karnov.c r:chelnov c:chelnov
		DRIVER(chelnovj) //t:chelnovj f:karnov.c r:chelnov c:chelnov
//SET: hbarrel
		DRIVER(hbarrel) //t:hbarrel f:dec0.c r: c:
		DRIVER(hbarrelw) //t:hbarrelw f:dec0.c r:hbarrel c:hbarrel
//SET: baddudes
		DRIVER(baddudes) //t:baddudes f:dec0.c r: c:
		DRIVER(drgninja) //t:drgninja f:dec0.c r:baddudes c:baddudes
//SET: birdtry
		DRIVER(birdtry) //t:birdtry f:dec0.c r: c:
//SET: robocop
		DRIVER(robocop) //t:robocop f:dec0.c r: c:
		DRIVER(robocopw) //t:robocopw f:dec0.c r:robocop c:robocop
		DRIVER(robocopj) //t:robocopj f:dec0.c r:robocop c:robocop
		DRIVER(robocopu) //t:robocopu f:dec0.c r:robocop c:robocop
		DRIVER(robocopu0) //t:robocopu0 f:dec0.c r:robocop c:robocop
		DRIVER(robocopb) //t:robocopb f:dec0.c r:robocop c:robocop
		DRIVER(automat) //t:automat f:dec0.c r:robocop c:robocop
//SET: hippodrm
		DRIVER(hippodrm) //t:hippodrm f:dec0.c r: c:
		DRIVER(ffantasy) //t:ffantasy f:dec0.c r:hippodrm c:hippodrm
		DRIVER(ffantasya) //t:ffantasya f:dec0.c r:hippodrm c:hippodrm
		DRIVER(ffantasybl) //t:ffantasybl f:dec0.c r:hippodrm c:hippodrm
//SET: slyspy
		DRIVER(slyspy) //t:slyspy f:dec0.c r: c:
		DRIVER(slyspy2) //t:slyspy2 f:dec0.c r:slyspy c:slyspy
		DRIVER(secretag) //t:secretag f:dec0.c r:slyspy c:slyspy
		DRIVER(secretab) //t:secretab f:dec0.c r:slyspy c:slyspy
//SET: midres
		DRIVER(midres) //t:midres f:dec0.c r: c:
		DRIVER(midresu) //t:midresu f:dec0.c r:midres c:midres
		DRIVER(midresj) //t:midresj f:dec0.c r:midres c:midres
		DRIVER(midresb) //t:midresb f:dec0.c r:midres c:midres
//SET: bouldash
		DRIVER(bouldash) //t:bouldash f:dec0.c r: c:
		DRIVER(bouldashj) //t:bouldashj f:dec0.c r:bouldash c:bouldash
//SET: stadhero
		DRIVER(stadhero) //t:stadhero f:stadhero.c r: c:
//SET: madmotor
		DRIVER(madmotor) //t:madmotor f:madmotor.c r: c:
//SET: vaportra
		DRIVER(vaportra) //t:vaportra f:vaportra.c r: c:
		DRIVER(vaportra3) //t:vaportra3 f:vaportra.c r:vaportra c:vaportra
		DRIVER(vaportrau) //t:vaportrau f:vaportra.c r:vaportra c:vaportra
		DRIVER(kuhga) //t:kuhga f:vaportra.c r:vaportra c:vaportra
//SET: cbuster
		DRIVER(cbuster) //t:cbuster f:cbuster.c r: c:
		DRIVER(cbusterw) //t:cbusterw f:cbuster.c r:cbuster c:cbuster
		DRIVER(cbusterj) //t:cbusterj f:cbuster.c r:cbuster c:cbuster
		DRIVER(twocrude) //t:twocrude f:cbuster.c r:cbuster c:cbuster
//SET: darkseal
		DRIVER(darkseal) //t:darkseal f:darkseal.c r: c:
		DRIVER(darkseal1) //t:darkseal1 f:darkseal.c r:darkseal c:darkseal
		DRIVER(darksealj) //t:darksealj f:darkseal.c r:darkseal c:darkseal
		DRIVER(gatedoom) //t:gatedoom f:darkseal.c r:darkseal c:darkseal
		DRIVER(gatedoom1) //t:gatedoom1 f:darkseal.c r:darkseal c:darkseal
//SET: edrandy
		DRIVER(edrandy) //t:edrandy f:cninja.c r: c:
		DRIVER(edrandy2) //t:edrandy2 f:cninja.c r:edrandy c:edrandy
		DRIVER(edrandy1) //t:edrandy1 f:cninja.c r:edrandy c:edrandy
		DRIVER(edrandyj) //t:edrandyj f:cninja.c r:edrandy c:edrandy
//SET: supbtime
		DRIVER(supbtime) //t:supbtime f:supbtime.c r: c:
		DRIVER(supbtimea) //t:supbtimea f:supbtime.c r:supbtime c:supbtime
		DRIVER(supbtimej) //t:supbtimej f:supbtime.c r:supbtime c:supbtime
//SET: mutantf
		DRIVER(mutantf) //t:mutantf f:cninja.c r: c:
		DRIVER(mutantf4) //t:mutantf4 f:cninja.c r:mutantf c:mutantf
		DRIVER(mutantf3) //t:mutantf3 f:cninja.c r:mutantf c:mutantf
		DRIVER(deathbrd) //t:deathbrd f:cninja.c r:mutantf c:mutantf
//SET: cninja
		DRIVER(cninja) //t:cninja f:cninja.c r: c:
		DRIVER(cninja1) //t:cninja1 f:cninja.c r:cninja c:cninja
		DRIVER(cninjau) //t:cninjau f:cninja.c r:cninja c:cninja
		DRIVER(joemac) //t:joemac f:cninja.c r:cninja c:cninja
		DRIVER(cninjabl) //t:cninjabl f:cninja.c r:cninja c:cninja
		DRIVER(stoneage) //t:stoneage f:cninja.c r:cninja c:cninja
//SET: robocop2
		DRIVER(robocop2) //t:robocop2 f:cninja.c r: c:
		DRIVER(robocop2u) //t:robocop2u f:cninja.c r:robocop2 c:robocop2
		DRIVER(robocop2j) //t:robocop2j f:cninja.c r:robocop2 c:robocop2
//SET: thndzone
		DRIVER(thndzone) //t:thndzone f:dassault.c r: c:
		DRIVER(dassault) //t:dassault f:dassault.c r:thndzone c:thndzone
		DRIVER(dassault4) //t:dassault4 f:dassault.c r:thndzone c:thndzone
//SET: chinatwn
		DRIVER(chinatwn) //t:chinatwn f:supbtime.c r: c:
//SET: rohga
		DRIVER(rohga) //t:rohga f:rohga.c r: c:
		DRIVER(rohga1) //t:rohga1 f:rohga.c r:rohga c:rohga
		DRIVER(rohga2) //t:rohga2 f:rohga.c r:rohga c:rohga
		DRIVER(rohgah) //t:rohgah f:rohga.c r:rohga c:rohga
		DRIVER(rohgau) //t:rohgau f:rohga.c r:rohga c:rohga
		DRIVER(wolffang) //t:wolffang f:rohga.c r:rohga c:rohga
//SET: schmeisr
		DRIVER(schmeisr) //t:schmeisr f:rohga.c r: c:
//SET: captaven
		DRIVER(captaven) //t:captaven f:deco32.c r: c:
		DRIVER(captavena) //t:captavena f:deco32.c r:captaven c:captaven
		DRIVER(captavene) //t:captavene f:deco32.c r:captaven c:captaven
		DRIVER(captavenu) //t:captavenu f:deco32.c r:captaven c:captaven
		DRIVER(captavenuu) //t:captavenuu f:deco32.c r:captaven c:captaven
		DRIVER(captavenua) //t:captavenua f:deco32.c r:captaven c:captaven
		DRIVER(captavenj) //t:captavenj f:deco32.c r:captaven c:captaven
//SET: tumblep
		DRIVER(tumblep) //t:tumblep f:tumblep.c r: c:
		DRIVER(tumblepj) //t:tumblepj f:tumblep.c r:tumblep c:tumblep
		DRIVER(tumbleb) //t:tumbleb f:tumbleb.c r:tumblep c:tumblep
		DRIVER(tumbleb2) //t:tumbleb2 f:tumbleb.c r:tumblep c:tumblep
//SET: jumpkids
		DRIVER(jumpkids) //t:jumpkids f:tumbleb.c r: c:
//SET: jumppop
		DRIVER(jumppop) //t:jumppop f:tumbleb.c r: c:
//SET: pangpang
		DRIVER(pangpang) //t:pangpang f:tumbleb.c r: c:
//SET: sdfight
		DRIVER(sdfight) //t:sdfight f:tumbleb.c r: c:
//SET: wlstar
		DRIVER(wlstar) //t:wlstar f:tumbleb.c r: c:
//SET: wondl96
		DRIVER(wondl96) //t:wondl96 f:tumbleb.c r: c:
//SET: fncywld
		DRIVER(fncywld) //t:fncywld f:tumbleb.c r: c:
//SET: htchctch
		DRIVER(htchctch) //t:htchctch f:tumbleb.c r: c:
//SET: cookbib
		DRIVER(cookbib) //t:cookbib f:tumbleb.c r: c:
//SET: chokchok
		DRIVER(chokchok) //t:chokchok f:tumbleb.c r: c:
//SET: metlsavr
		DRIVER(metlsavr) //t:metlsavr f:tumbleb.c r: c:
//SET: bcstry
		DRIVER(bcstry) //t:bcstry f:tumbleb.c r: c:
		DRIVER(bcstrya) //t:bcstrya f:tumbleb.c r:bcstry c:bcstry
//SET: semibase
		DRIVER(semibase) //t:semibase f:tumbleb.c r: c:
//SET: dquizgo
		DRIVER(dquizgo) //t:dquizgo f:tumbleb.c r: c:
//SET: suprtrio
		DRIVER(suprtrio) //t:suprtrio f:tumbleb.c r: c:
//SET: lemmings
		DRIVER(lemmings) //t:lemmings f:lemmings.c r: c:
//SET: dragngun
		DRIVER(dragngun) //t:dragngun f:deco32.c r: c:
//SET: wizdfire
		DRIVER(wizdfire) //t:wizdfire f:rohga.c r: c:
		DRIVER(wizdfireu) //t:wizdfireu f:rohga.c r:wizdfire c:wizdfire
		DRIVER(darkseal2) //t:darkseal2 f:rohga.c r:wizdfire c:wizdfire
//SET: funkyjet
		DRIVER(funkyjet) //t:funkyjet f:funkyjet.c r: c:
		DRIVER(funkyjetj) //t:funkyjetj f:funkyjet.c r:funkyjet c:funkyjet
//SET: nitrobal
		DRIVER(nitrobal) //t:nitrobal f:rohga.c r: c:
		DRIVER(gunball) //t:gunball f:rohga.c r:nitrobal c:nitrobal
//SET: dietgo
		DRIVER(dietgo) //t:dietgo f:dietgo.c r: c:
		DRIVER(dietgoe) //t:dietgoe f:dietgo.c r:dietgo c:dietgo
		DRIVER(dietgou) //t:dietgou f:dietgo.c r:dietgo c:dietgo
		DRIVER(dietgoj) //t:dietgoj f:dietgo.c r:dietgo c:dietgo
//SET: pktgaldx
		DRIVER(pktgaldx) //t:pktgaldx f:pktgaldx.c r: c:
		DRIVER(pktgaldxj) //t:pktgaldxj f:pktgaldx.c r:pktgaldx c:pktgaldx
		DRIVER(pktgaldxb) //t:pktgaldxb f:pktgaldx.c r:pktgaldx c:pktgaldx
//SET: boogwing
		DRIVER(boogwing) //t:boogwing f:boogwing.c r: c:
		DRIVER(boogwinga) //t:boogwinga f:boogwing.c r:boogwing c:boogwing
		DRIVER(ragtime) //t:ragtime f:boogwing.c r:boogwing c:boogwing
		DRIVER(ragtimea) //t:ragtimea f:boogwing.c r:boogwing c:boogwing
//SET: dblewing
		DRIVER(dblewing) //t:dblewing f:dblewing.c r: c:
//SET: fghthist
		DRIVER(fghthist) //t:fghthist f:deco32.c r: c:
		DRIVER(fghthistu) //t:fghthistu f:deco32.c r:fghthist c:fghthist
		DRIVER(fghthista) //t:fghthista f:deco32.c r:fghthist c:fghthist
		DRIVER(fghthistj) //t:fghthistj f:deco32.c r:fghthist c:fghthist
//SET: hvysmsh
		DRIVER(hvysmsh) //t:hvysmsh f:deco156.c r: c:
		DRIVER(hvysmsha) //t:hvysmsha f:deco156.c r:hvysmsh c:hvysmsh
		DRIVER(hvysmshj) //t:hvysmshj f:deco156.c r:hvysmsh c:hvysmsh
//SET: nslasher
		DRIVER(nslasher) //t:nslasher f:deco32.c r: c:
		DRIVER(nslasherj) //t:nslasherj f:deco32.c r:nslasher c:nslasher
		DRIVER(nslashers) //t:nslashers f:deco32.c r:nslasher c:nslasher
//SET: lockload
		DRIVER(lockload) //t:lockload f:deco32.c r: c:
		DRIVER(lockloadu) //t:lockloadu f:deco32.c r:lockload c:lockload
//SET: joemacr
		DRIVER(joemacr) //t:joemacr f:simpl156.c r: c:
		DRIVER(joemacra) //t:joemacra f:simpl156.c r:joemacr c:joemacr
//SET: tattass
		DRIVER(tattass) //t:tattass f:deco32.c r: c:
		DRIVER(tattassa) //t:tattassa f:deco32.c r:tattass c:tattass
//SET: charlien
		DRIVER(charlien) //t:charlien f:simpl156.c r: c:
//SET: wcvol95
		DRIVER(wcvol95) //t:wcvol95 f:deco156.c r: c:
//SET: backfire
		DRIVER(backfire) //t:backfire f:backfire.c r: c:
		DRIVER(backfirea) //t:backfirea f:backfire.c r:backfire c:backfire
//SET: prtytime
		DRIVER(prtytime) //t:prtytime f:simpl156.c r: c:
		DRIVER(gangonta) //t:gangonta f:simpl156.c r:prtytime c:prtytime
//SET: chainrec
		DRIVER(chainrec) //t:chainrec f:simpl156.c r: c:
		DRIVER(magdrop) //t:magdrop f:simpl156.c r:chainrec c:chainrec
		DRIVER(magdropp) //t:magdropp f:simpl156.c r:chainrec c:chainrec
//SET: osman
		DRIVER(osman) //t:osman f:simpl156.c r: c:
		DRIVER(candance) //t:candance f:simpl156.c r:osman c:osman
//SET: sotsugyo
		DRIVER(sotsugyo) //t:sotsugyo f:funkyjet.c r: c:
//SET: sshangha
		DRIVER(sshangha) //t:sshangha f:sshangha.c r: c:
		DRIVER(sshanghab) //t:sshanghab f:sshangha.c r:sshangha c:sshangha
//SET: hoops96
		DRIVER(hoops96) //t:hoops96 f:deco_mlc.c r: c:
		DRIVER(ddream95) //t:ddream95 f:deco_mlc.c r:hoops96 c:hoops96
		DRIVER(hoops95) //t:hoops95 f:deco_mlc.c r:hoops96 c:hoops96
//SET: avengrgs
		DRIVER(avengrgs) //t:avengrgs f:deco_mlc.c r: c:
		DRIVER(avengrgsj) //t:avengrgsj f:deco_mlc.c r:avengrgs c:avengrgs
//SET: skullfng
		DRIVER(skullfng) //t:skullfng f:deco_mlc.c r: c:
		DRIVER(skullfngj) //t:skullfngj f:deco_mlc.c r:skullfng c:skullfng
//SET: stadhr96
		DRIVER(stadhr96) //t:stadhr96 f:deco_mlc.c r: c:
		DRIVER(stadhr96j) //t:stadhr96j f:deco_mlc.c r:stadhr96 c:stadhr96
//SET: senjyo
		DRIVER(senjyo) //t:senjyo f:senjyo.c r: c:
//SET: starforc
		DRIVER(starforc) //t:starforc f:senjyo.c r: c:
		DRIVER(starforce) //t:starforce f:senjyo.c r:starforc c:starforc
		DRIVER(starforcb) //t:starforcb f:senjyo.c r:starforc c:starforc
		DRIVER(starforca) //t:starforca f:senjyo.c r:starforc c:starforc
		DRIVER(megaforc) //t:megaforc f:senjyo.c r:starforc c:starforc
//SET: baluba
		DRIVER(baluba) //t:baluba f:senjyo.c r: c:
//SET: bombjack
		DRIVER(bombjack) //t:bombjack f:bombjack.c r: c:
		DRIVER(bombjack2) //t:bombjack2 f:bombjack.c r:bombjack c:bombjack
//SET: pbaction
		DRIVER(pbaction) //t:pbaction f:pbaction.c r: c:
		DRIVER(pbaction2) //t:pbaction2 f:pbaction.c r:pbaction c:pbaction
		DRIVER(pbaction3) //t:pbaction3 f:pbaction.c r:pbaction c:pbaction
		DRIVER(pbaction4) //t:pbaction4 f:pbaction.c r:pbaction c:pbaction
		DRIVER(pbaction5) //t:pbaction5 f:pbaction.c r:pbaction c:pbaction
//SET: ponttehk
		DRIVER(ponttehk) //t:ponttehk f:lvcards.c r: c:
//SET: lvcards
		DRIVER(lvcards) //t:lvcards f:lvcards.c r: c:
		DRIVER(lvpoker) //t:lvpoker f:lvcards.c r:lvcards c:lvcards
//SET: tehkanwc
		DRIVER(tehkanwc) //t:tehkanwc f:tehkanwc.c r: c:
		DRIVER(tehkanwcb) //t:tehkanwcb f:tehkanwc.c r:tehkanwc c:tehkanwc
		DRIVER(tehkanwcc) //t:tehkanwcc f:tehkanwc.c r:tehkanwc c:tehkanwc
//SET: gridiron
		DRIVER(gridiron) //t:gridiron f:tehkanwc.c r: c:
//SET: teedoff
		DRIVER(teedoff) //t:teedoff f:tehkanwc.c r: c:
//SET: solomon
		DRIVER(solomon) //t:solomon f:solomon.c r: c:
		DRIVER(solomonj) //t:solomonj f:solomon.c r:solomon c:solomon
//SET: rygar
		DRIVER(rygar) //t:rygar f:tecmo.c r: c:
		DRIVER(rygar2) //t:rygar2 f:tecmo.c r:rygar c:rygar
		DRIVER(rygar3) //t:rygar3 f:tecmo.c r:rygar c:rygar
		DRIVER(rygarj) //t:rygarj f:tecmo.c r:rygar c:rygar
//SET: gemini
		DRIVER(gemini) //t:gemini f:tecmo.c r: c:
//SET: silkworm
		DRIVER(silkworm) //t:silkworm f:tecmo.c r: c:
		DRIVER(silkworm2) //t:silkworm2 f:tecmo.c r:silkworm c:silkworm
//SET: backfirt
		DRIVER(backfirt) //t:backfirt f:tecmo.c r: c:
//SET: tbowl
		DRIVER(tbowl) //t:tbowl f:tbowl.c r: c:
		DRIVER(tbowlj) //t:tbowlj f:tbowl.c r:tbowl c:tbowl
//SET: shadoww
		DRIVER(shadoww) //t:shadoww f:gaiden.c r: c:
		DRIVER(shadowwa) //t:shadowwa f:gaiden.c r:shadoww c:shadoww
		DRIVER(gaiden) //t:gaiden f:gaiden.c r:shadoww c:shadoww
		DRIVER(ryukendn) //t:ryukendn f:gaiden.c r:shadoww c:shadoww
		DRIVER(ryukendna) //t:ryukendna f:gaiden.c r:shadoww c:shadoww
		DRIVER(mastninj) //t:mastninj f:gaiden.c r:shadoww c:shadoww
//SET: wildfang
		DRIVER(wildfang) //t:wildfang f:gaiden.c r: c:
		DRIVER(wildfangs) //t:wildfangs f:gaiden.c r:wildfang c:wildfang
		DRIVER(tknight) //t:tknight f:gaiden.c r:wildfang c:wildfang
//SET: stratof
		DRIVER(stratof) //t:stratof f:gaiden.c r: c:
		DRIVER(raiga) //t:raiga f:gaiden.c r:stratof c:stratof
//SET: drgnbowl
		DRIVER(drgnbowl) //t:drgnbowl f:gaiden.c r: c:
//SET: wc90
		DRIVER(wc90) //t:wc90 f:wc90.c r: c:
		DRIVER(wc90a) //t:wc90a f:wc90.c r:wc90 c:wc90
		DRIVER(wc90b) //t:wc90b f:wc90.c r:wc90 c:wc90
		DRIVER(wc90t) //t:wc90t f:wc90.c r:wc90 c:wc90
		DRIVER(wc90b1) //t:wc90b1 f:wc90b.c r:wc90 c:wc90
		DRIVER(wc90b2) //t:wc90b2 f:wc90b.c r:wc90 c:wc90
//SET: spbactn
		DRIVER(spbactn) //t:spbactn f:spbactn.c r: c:
		DRIVER(spbactnj) //t:spbactnj f:spbactn.c r:spbactn c:spbactn
//SET: fstarfrc
		DRIVER(fstarfrc) //t:fstarfrc f:tecmo16.c r: c:
		DRIVER(fstarfrcj) //t:fstarfrcj f:tecmo16.c r:fstarfrc c:fstarfrc
//SET: ginkun
		DRIVER(ginkun) //t:ginkun f:tecmo16.c r: c:
//SET: deroon
		DRIVER(deroon) //t:deroon f:tecmosys.c r: c:
//SET: tkdensho
		DRIVER(tkdensho) //t:tkdensho f:tecmosys.c r: c:
		DRIVER(tkdenshoa) //t:tkdenshoa f:tecmosys.c r:tkdensho c:tkdensho
//SET: tutankhm
		DRIVER(tutankhm) //t:tutankhm f:tutankhm.c r: c:
		DRIVER(tutankhms) //t:tutankhms f:tutankhm.c r:tutankhm c:tutankhm
//SET: junofrst
		DRIVER(junofrst) //t:junofrst f:junofrst.c r: c:
		DRIVER(junofrstg) //t:junofrstg f:junofrst.c r:junofrst c:junofrst
//SET: pooyan
		DRIVER(pooyan) //t:pooyan f:pooyan.c r: c:
		DRIVER(pooyans) //t:pooyans f:pooyan.c r:pooyan c:pooyan
		DRIVER(pootan) //t:pootan f:pooyan.c r:pooyan c:pooyan
//SET: timeplt
		DRIVER(timeplt) //t:timeplt f:timeplt.c r: c:
		DRIVER(timepltc) //t:timepltc f:timeplt.c r:timeplt c:timeplt
		DRIVER(timeplta) //t:timeplta f:timeplt.c r:timeplt c:timeplt
		DRIVER(spaceplt) //t:spaceplt f:timeplt.c r:timeplt c:timeplt
//SET: psurge
		DRIVER(psurge) //t:psurge f:timeplt.c r: c:
//SET: megazone
		DRIVER(megazone) //t:megazone f:megazone.c r: c:
		DRIVER(megazonea) //t:megazonea f:megazone.c r:megazone c:megazone
		DRIVER(megazoneb) //t:megazoneb f:megazone.c r:megazone c:megazone
		DRIVER(megazonec) //t:megazonec f:megazone.c r:megazone c:megazone
		DRIVER(megazonei) //t:megazonei f:megazone.c r:megazone c:megazone
//SET: pandoras
		DRIVER(pandoras) //t:pandoras f:pandoras.c r: c:
//SET: gyruss
		DRIVER(gyruss) //t:gyruss f:gyruss.c r: c:
		DRIVER(gyrussce) //t:gyrussce f:gyruss.c r:gyruss c:gyruss
		DRIVER(gyrussb) //t:gyrussb f:gyruss.c r:gyruss c:gyruss
		DRIVER(venus) //t:venus f:gyruss.c r:gyruss c:gyruss
//SET: trackfld
		DRIVER(trackfld) //t:trackfld f:trackfld.c r: c:
		DRIVER(trackfldc) //t:trackfldc f:trackfld.c r:trackfld c:trackfld
		DRIVER(trackfldnz) //t:trackfldnz f:trackfld.c r:trackfld c:trackfld
		DRIVER(hyprolym) //t:hyprolym f:trackfld.c r:trackfld c:trackfld
		DRIVER(hyprolymb) //t:hyprolymb f:trackfld.c r:trackfld c:trackfld
		DRIVER(atlantol) //t:atlantol f:trackfld.c r:trackfld c:trackfld
//SET: wizzquiz
		DRIVER(wizzquiz) //t:wizzquiz f:trackfld.c r: c:
		DRIVER(wizzquiza) //t:wizzquiza f:trackfld.c r:wizzquiz c:wizzquiz
//SET: reaktor
		DRIVER(reaktor) //t:reaktor f:trackfld.c r: c:
//SET: mastkin
		DRIVER(mastkin) //t:mastkin f:trackfld.c r: c:
//SET: rocnrope
		DRIVER(rocnrope) //t:rocnrope f:rocnrope.c r: c:
		DRIVER(rocnropek) //t:rocnropek f:rocnrope.c r:rocnrope c:rocnrope
		DRIVER(ropeman) //t:ropeman f:rocnrope.c r:rocnrope c:rocnrope
//SET: circusc
		DRIVER(circusc) //t:circusc f:circusc.c r: c:
		DRIVER(circusc2) //t:circusc2 f:circusc.c r:circusc c:circusc
		DRIVER(circusc3) //t:circusc3 f:circusc.c r:circusc c:circusc
		DRIVER(circuscc) //t:circuscc f:circusc.c r:circusc c:circusc
		DRIVER(circusce) //t:circusce f:circusc.c r:circusc c:circusc
//SET: tp84
		DRIVER(tp84) //t:tp84 f:tp84.c r: c:
		DRIVER(tp84a) //t:tp84a f:tp84.c r:tp84 c:tp84
		DRIVER(tp84b) //t:tp84b f:tp84.c r:tp84 c:tp84
//SET: hyperspt
		DRIVER(hyperspt) //t:hyperspt f:hyperspt.c r: c:
		DRIVER(hypersptb) //t:hypersptb f:hyperspt.c r:hyperspt c:hyperspt
		DRIVER(hpolym84) //t:hpolym84 f:hyperspt.c r:hyperspt c:hyperspt
//SET: sbasketb
		DRIVER(sbasketb) //t:sbasketb f:sbasketb.c r: c:
		DRIVER(sbasketh) //t:sbasketh f:sbasketb.c r:sbasketb c:sbasketb
		DRIVER(sbasketg) //t:sbasketg f:sbasketb.c r:sbasketb c:sbasketb
		DRIVER(sbaskete) //t:sbaskete f:sbasketb.c r:sbasketb c:sbasketb
//SET: mikie
		DRIVER(mikie) //t:mikie f:mikie.c r: c:
		DRIVER(mikiej) //t:mikiej f:mikie.c r:mikie c:mikie
		DRIVER(mikiehs) //t:mikiehs f:mikie.c r:mikie c:mikie
//SET: roadf
		DRIVER(roadf) //t:roadf f:hyperspt.c r: c:
		DRIVER(roadf2) //t:roadf2 f:hyperspt.c r:roadf c:roadf
//SET: yiear
		DRIVER(yiear) //t:yiear f:yiear.c r: c:
		DRIVER(yiear2) //t:yiear2 f:yiear.c r:yiear c:yiear
		DRIVER(yieartf) //t:yieartf f:trackfld.c r:yiear c:yiear
//SET: kicker
		DRIVER(kicker) //t:kicker f:shaolins.c r: c:
		DRIVER(shaolins) //t:shaolins f:shaolins.c r:kicker c:kicker
		DRIVER(shaolinb) //t:shaolinb f:shaolins.c r:kicker c:kicker
//SET: pingpong
		DRIVER(pingpong) //t:pingpong f:pingpong.c r: c:
//SET: merlinmm
		DRIVER(merlinmm) //t:merlinmm f:pingpong.c r: c:
//SET: cashquiz
		DRIVER(cashquiz) //t:cashquiz f:pingpong.c r: c:
//SET: gberet
		DRIVER(gberet) //t:gberet f:gberet.c r: c:
		DRIVER(rushatck) //t:rushatck f:gberet.c r:gberet c:gberet
		DRIVER(gberetb) //t:gberetb f:gberet.c r:gberet c:gberet
//SET: mrgoemon
		DRIVER(mrgoemon) //t:mrgoemon f:gberet.c r: c:
//SET: jailbrek
		DRIVER(jailbrek) //t:jailbrek f:jailbrek.c r: c:
		DRIVER(manhatan) //t:manhatan f:jailbrek.c r:jailbrek c:jailbrek
		DRIVER(jailbrekb) //t:jailbrekb f:jailbrek.c r:jailbrek c:jailbrek
//SET: scotrsht
		DRIVER(scotrsht) //t:scotrsht f:scotrsht.c r: c:
//SET: finalizr
		DRIVER(finalizr) //t:finalizr f:finalizr.c r: c:
		DRIVER(finalizrb) //t:finalizrb f:finalizr.c r:finalizr c:finalizr
//SET: ironhors
		DRIVER(ironhors) //t:ironhors f:ironhors.c r: c:
		DRIVER(dairesya) //t:dairesya f:ironhors.c r:ironhors c:ironhors
		DRIVER(farwest) //t:farwest f:ironhors.c r:ironhors c:ironhors
//SET: jackal
		DRIVER(jackal) //t:jackal f:jackal.c r: c:
		DRIVER(topgunr) //t:topgunr f:jackal.c r:jackal c:jackal
		DRIVER(jackalj) //t:jackalj f:jackal.c r:jackal c:jackal
		DRIVER(topgunbl) //t:topgunbl f:jackal.c r:jackal c:jackal
//SET: ddribble
		DRIVER(ddribble) //t:ddribble f:ddribble.c r: c:
		DRIVER(ddribblep) //t:ddribblep f:ddribble.c r:ddribble c:ddribble
//SET: contra
		DRIVER(contra) //t:contra f:contra.c r: c:
		DRIVER(contra1) //t:contra1 f:contra.c r:contra c:contra
		DRIVER(contrab) //t:contrab f:contra.c r:contra c:contra
		DRIVER(contraj) //t:contraj f:contra.c r:contra c:contra
		DRIVER(contrajb) //t:contrajb f:contra.c r:contra c:contra
		DRIVER(gryzor) //t:gryzor f:contra.c r:contra c:contra
		DRIVER(gryzora) //t:gryzora f:contra.c r:contra c:contra
//SET: combatsc
		DRIVER(combatsc) //t:combatsc f:combatsc.c r: c:
		DRIVER(combatsct) //t:combatsct f:combatsc.c r:combatsc c:combatsc
		DRIVER(combatscj) //t:combatscj f:combatsc.c r:combatsc c:combatsc
		DRIVER(bootcamp) //t:bootcamp f:combatsc.c r:combatsc c:combatsc
		DRIVER(combatscb) //t:combatscb f:combatsc.c r:combatsc c:combatsc
//SET: rockrage
		DRIVER(rockrage) //t:rockrage f:rockrage.c r: c:
		DRIVER(rockragea) //t:rockragea f:rockrage.c r:rockrage c:rockrage
		DRIVER(rockragej) //t:rockragej f:rockrage.c r:rockrage c:rockrage
//SET: mx5000
		DRIVER(mx5000) //t:mx5000 f:flkatck.c r: c:
		DRIVER(flkatck) //t:flkatck f:flkatck.c r:mx5000 c:mx5000
//SET: fastlane
		DRIVER(fastlane) //t:fastlane f:fastlane.c r: c:
//SET: tricktrp
		DRIVER(tricktrp) //t:tricktrp f:labyrunr.c r: c:
		DRIVER(labyrunr) //t:labyrunr f:labyrunr.c r:tricktrp c:tricktrp
		DRIVER(labyrunrk) //t:labyrunrk f:labyrunr.c r:tricktrp c:tricktrp
//SET: rackemup
		DRIVER(rackemup) //t:rackemup f:battlnts.c r: c:
		DRIVER(thehustl) //t:thehustl f:battlnts.c r:rackemup c:rackemup
		DRIVER(thehustlj) //t:thehustlj f:battlnts.c r:rackemup c:rackemup
//SET: battlnts
		DRIVER(battlnts) //t:battlnts f:battlnts.c r: c:
		DRIVER(battlntsj) //t:battlntsj f:battlnts.c r:battlnts c:battlnts
//SET: bladestl
		DRIVER(bladestl) //t:bladestl f:bladestl.c r: c:
		DRIVER(bladestll) //t:bladestll f:bladestl.c r:bladestl c:bladestl
		DRIVER(bladestle) //t:bladestle f:bladestl.c r:bladestl c:bladestl
//SET: hcastle
		DRIVER(hcastle) //t:hcastle f:hcastle.c r: c:
		DRIVER(hcastleo) //t:hcastleo f:hcastle.c r:hcastle c:hcastle
		DRIVER(hcastlej) //t:hcastlej f:hcastle.c r:hcastle c:hcastle
		DRIVER(hcastljo) //t:hcastljo f:hcastle.c r:hcastle c:hcastle
//SET: ajax
		DRIVER(ajax) //t:ajax f:ajax.c r: c:
		DRIVER(typhoon) //t:typhoon f:ajax.c r:ajax c:ajax
		DRIVER(ajaxj) //t:ajaxj f:ajax.c r:ajax c:ajax
//SET: scontra
		DRIVER(scontra) //t:scontra f:thunderx.c r: c:
		DRIVER(scontraj) //t:scontraj f:thunderx.c r:scontra c:scontra
//SET: thunderx
		DRIVER(thunderx) //t:thunderx f:thunderx.c r: c:
		DRIVER(thunderxa) //t:thunderxa f:thunderx.c r:thunderx c:thunderx
		DRIVER(thunderxb) //t:thunderxb f:thunderx.c r:thunderx c:thunderx
		DRIVER(thunderxj) //t:thunderxj f:thunderx.c r:thunderx c:thunderx
//SET: mainevt
		DRIVER(mainevt) //t:mainevt f:mainevt.c r: c:
		DRIVER(mainevto) //t:mainevto f:mainevt.c r:mainevt c:mainevt
		DRIVER(mainevt2p) //t:mainevt2p f:mainevt.c r:mainevt c:mainevt
		DRIVER(ringohja) //t:ringohja f:mainevt.c r:mainevt c:mainevt
//SET: devstors
		DRIVER(devstors) //t:devstors f:mainevt.c r: c:
		DRIVER(devstors2) //t:devstors2 f:mainevt.c r:devstors c:devstors
		DRIVER(devstors3) //t:devstors3 f:mainevt.c r:devstors c:devstors
		DRIVER(garuka) //t:garuka f:mainevt.c r:devstors c:devstors
//SET: 88games
		DRIVER(88games) //t:88games f:88games.c r: c:
		DRIVER(konami88) //t:konami88 f:88games.c r:88games c:88games
		DRIVER(hypsptsp) //t:hypsptsp f:88games.c r:88games c:88games
//SET: gbusters
		DRIVER(gbusters) //t:gbusters f:gbusters.c r: c:
		DRIVER(gbustersa) //t:gbustersa f:gbusters.c r:gbusters c:gbusters
		DRIVER(crazycop) //t:crazycop f:gbusters.c r:gbusters c:gbusters
//SET: crimfght
		DRIVER(crimfght) //t:crimfght f:crimfght.c r: c:
		DRIVER(crimfght2) //t:crimfght2 f:crimfght.c r:crimfght c:crimfght
		DRIVER(crimfghtj) //t:crimfghtj f:crimfght.c r:crimfght c:crimfght
//SET: spy
		DRIVER(spy) //t:spy f:spy.c r: c:
		DRIVER(spyu) //t:spyu f:spy.c r:spy c:spy
//SET: bottom9
		DRIVER(bottom9) //t:bottom9 f:bottom9.c r: c:
		DRIVER(bottom9n) //t:bottom9n f:bottom9.c r:bottom9 c:bottom9
		DRIVER(mstadium) //t:mstadium f:bottom9.c r:bottom9 c:bottom9
//SET: blockhl
		DRIVER(blockhl) //t:blockhl f:blockhl.c r: c:
		DRIVER(quarth) //t:quarth f:blockhl.c r:blockhl c:blockhl
//SET: aliens
		DRIVER(aliens) //t:aliens f:aliens.c r: c:
		DRIVER(aliens2) //t:aliens2 f:aliens.c r:aliens c:aliens
		DRIVER(aliens3) //t:aliens3 f:aliens.c r:aliens c:aliens
		DRIVER(aliensu) //t:aliensu f:aliens.c r:aliens c:aliens
		DRIVER(aliensj) //t:aliensj f:aliens.c r:aliens c:aliens
		DRIVER(aliensj2) //t:aliensj2 f:aliens.c r:aliens c:aliens
		DRIVER(aliensa) //t:aliensa f:aliens.c r:aliens c:aliens
//SET: suratk
		DRIVER(suratk) //t:suratk f:surpratk.c r: c:
		DRIVER(suratka) //t:suratka f:surpratk.c r:suratk c:suratk
		DRIVER(suratkj) //t:suratkj f:surpratk.c r:suratk c:suratk
//SET: parodius
		DRIVER(parodius) //t:parodius f:parodius.c r: c:
		DRIVER(parodiusa) //t:parodiusa f:parodius.c r:parodius c:parodius
		DRIVER(parodiusj) //t:parodiusj f:parodius.c r:parodius c:parodius
//SET: rollerg
		DRIVER(rollerg) //t:rollerg f:rollerg.c r: c:
		DRIVER(rollergj) //t:rollergj f:rollerg.c r:rollerg c:rollerg
//SET: simpsons
		DRIVER(simpsons) //t:simpsons f:simpsons.c r: c:
		DRIVER(simpsons4pa) //t:simpsons4pa f:simpsons.c r:simpsons c:simpsons
		DRIVER(simpsons2p) //t:simpsons2p f:simpsons.c r:simpsons c:simpsons
		DRIVER(simpsons2p2) //t:simpsons2p2 f:simpsons.c r:simpsons c:simpsons
		DRIVER(simpsons2pa) //t:simpsons2pa f:simpsons.c r:simpsons c:simpsons
		DRIVER(simpsons2pj) //t:simpsons2pj f:simpsons.c r:simpsons c:simpsons
//SET: esckids
		DRIVER(esckids) //t:esckids f:vendetta.c r: c:
		DRIVER(esckidsj) //t:esckidsj f:vendetta.c r:esckids c:esckids
//SET: vendetta
		DRIVER(vendetta) //t:vendetta f:vendetta.c r: c:
		DRIVER(vendettar) //t:vendettar f:vendetta.c r:vendetta c:vendetta
		DRIVER(vendetta2p) //t:vendetta2p f:vendetta.c r:vendetta c:vendetta
		DRIVER(vendetta2pu) //t:vendetta2pu f:vendetta.c r:vendetta c:vendetta
		DRIVER(vendetta2pd) //t:vendetta2pd f:vendetta.c r:vendetta c:vendetta
		DRIVER(vendettaj) //t:vendettaj f:vendetta.c r:vendetta c:vendetta
//SET: mogura
		DRIVER(mogura) //t:mogura f:mogura.c r: c:
//SET: wecleman
		DRIVER(wecleman) //t:wecleman f:wecleman.c r: c:
//SET: hotchase
		DRIVER(hotchase) //t:hotchase f:wecleman.c r: c:
//SET: chqflag
		DRIVER(chqflag) //t:chqflag f:chqflag.c r: c:
		DRIVER(chqflagj) //t:chqflagj f:chqflag.c r:chqflag c:chqflag
//SET: ultraman
		DRIVER(ultraman) //t:ultraman f:ultraman.c r: c:
//SET: hexion
		DRIVER(hexion) //t:hexion f:hexion.c r: c:
//SET: lethalen
		DRIVER(lethalen) //t:lethalen f:lethal.c r: c:
		DRIVER(lethalenua) //t:lethalenua f:lethal.c r:lethalen c:lethalen
		DRIVER(lethalenux) //t:lethalenux f:lethal.c r:lethalen c:lethalen
		DRIVER(lethaleneab) //t:lethaleneab f:lethal.c r:lethalen c:lethalen
		DRIVER(lethaleneae) //t:lethaleneae f:lethal.c r:lethalen c:lethalen
		DRIVER(lethalenj) //t:lethalenj f:lethal.c r:lethalen c:lethalen
//SET: tgtpanic
		DRIVER(tgtpanic) //t:tgtpanic f:tgtpanic.c r: c:
//SET: nemesis
		DRIVER(nemesis) //t:nemesis f:nemesis.c r: c:
		DRIVER(nemesisuk) //t:nemesisuk f:nemesis.c r:nemesis c:nemesis
		DRIVER(gradius) //t:gradius f:nemesis.c r:nemesis c:nemesis
//SET: konamigt
		DRIVER(konamigt) //t:konamigt f:nemesis.c r: c:
		DRIVER(rf2) //t:rf2 f:nemesis.c r:konamigt c:konamigt
//SET: salamand
		DRIVER(salamand) //t:salamand f:nemesis.c r: c:
		DRIVER(salamandj) //t:salamandj f:nemesis.c r:salamand c:salamand
		DRIVER(lifefrce) //t:lifefrce f:nemesis.c r:salamand c:salamand
		DRIVER(lifefrcej) //t:lifefrcej f:nemesis.c r:salamand c:salamand
//SET: blkpnthr
		DRIVER(blkpnthr) //t:blkpnthr f:nemesis.c r: c:
//SET: citybomb
		DRIVER(citybomb) //t:citybomb f:nemesis.c r: c:
		DRIVER(citybombj) //t:citybombj f:nemesis.c r:citybomb c:citybomb
//SET: kittenk
		DRIVER(kittenk) //t:kittenk f:nemesis.c r: c:
		DRIVER(nyanpani) //t:nyanpani f:nemesis.c r:kittenk c:kittenk
//SET: hcrash
		DRIVER(hcrash) //t:hcrash f:nemesis.c r: c:
		DRIVER(hcrashc) //t:hcrashc f:nemesis.c r:hcrash c:hcrash
//SET: twinbee
		DRIVER(twinbee) //t:twinbee f:nemesis.c r: c:
//SET: gwarrior
		DRIVER(gwarrior) //t:gwarrior f:nemesis.c r: c:
//SET: devilw
		DRIVER(devilw) //t:devilw f:twin16.c r: c:
		DRIVER(darkadv) //t:darkadv f:twin16.c r:devilw c:devilw
		DRIVER(majuu) //t:majuu f:twin16.c r:devilw c:devilw
//SET: vulcan
		DRIVER(vulcan) //t:vulcan f:twin16.c r: c:
		DRIVER(vulcana) //t:vulcana f:twin16.c r:vulcan c:vulcan
		DRIVER(vulcanb) //t:vulcanb f:twin16.c r:vulcan c:vulcan
		DRIVER(gradius2) //t:gradius2 f:twin16.c r:vulcan c:vulcan
		DRIVER(gradius2a) //t:gradius2a f:twin16.c r:vulcan c:vulcan
		DRIVER(gradius2b) //t:gradius2b f:twin16.c r:vulcan c:vulcan
//SET: fround
		DRIVER(fround) //t:fround f:twin16.c r: c:
		DRIVER(froundl) //t:froundl f:twin16.c r:fround c:fround
		DRIVER(hpuncher) //t:hpuncher f:twin16.c r:fround c:fround
//SET: cuebrick
		DRIVER(cuebrick) //t:cuebrick f:tmnt.c r: c:
		DRIVER(cuebrickj) //t:cuebrickj f:twin16.c r:cuebrick c:cuebrick
//SET: mia
		DRIVER(mia) //t:mia f:tmnt.c r: c:
		DRIVER(miaj) //t:miaj f:twin16.c r:mia c:mia
		DRIVER(mia2) //t:mia2 f:tmnt.c r:mia c:mia
//SET: tmnt
		DRIVER(tmnt) //t:tmnt f:tmnt.c r: c:
		DRIVER(tmntu) //t:tmntu f:tmnt.c r:tmnt c:tmnt
		DRIVER(tmntua) //t:tmntua f:tmnt.c r:tmnt c:tmnt
		DRIVER(tmht) //t:tmht f:tmnt.c r:tmnt c:tmnt
		DRIVER(tmhta) //t:tmhta f:tmnt.c r:tmnt c:tmnt
		DRIVER(tmntj) //t:tmntj f:tmnt.c r:tmnt c:tmnt
		DRIVER(tmht2p) //t:tmht2p f:tmnt.c r:tmnt c:tmnt
		DRIVER(tmht2pa) //t:tmht2pa f:tmnt.c r:tmnt c:tmnt
		DRIVER(tmnt2pj) //t:tmnt2pj f:tmnt.c r:tmnt c:tmnt
		DRIVER(tmnt2po) //t:tmnt2po f:tmnt.c r:tmnt c:tmnt
//SET: punkshot
		DRIVER(punkshot) //t:punkshot f:tmnt.c r: c:
		DRIVER(punkshot2) //t:punkshot2 f:tmnt.c r:punkshot c:punkshot
		DRIVER(punkshotj) //t:punkshotj f:tmnt.c r:punkshot c:punkshot
//SET: lgtnfght
		DRIVER(lgtnfght) //t:lgtnfght f:tmnt.c r: c:
		DRIVER(lgtnfghta) //t:lgtnfghta f:tmnt.c r:lgtnfght c:lgtnfght
		DRIVER(lgtnfghtu) //t:lgtnfghtu f:tmnt.c r:lgtnfght c:lgtnfght
		DRIVER(trigon) //t:trigon f:tmnt.c r:lgtnfght c:lgtnfght
//SET: blswhstl
		DRIVER(blswhstl) //t:blswhstl f:tmnt.c r: c:
		DRIVER(detatwin) //t:detatwin f:tmnt.c r:blswhstl c:blswhstl
//SET: glfgreat
		DRIVER(glfgreat) //t:glfgreat f:tmnt.c r: c:
		DRIVER(glfgreatj) //t:glfgreatj f:tmnt.c r:glfgreat c:glfgreat
//SET: tmnt2
		DRIVER(tmnt2) //t:tmnt2 f:tmnt.c r: c:
		DRIVER(tmnt2a) //t:tmnt2a f:tmnt.c r:tmnt2 c:tmnt2
		DRIVER(tmht22pe) //t:tmht22pe f:tmnt.c r:tmnt2 c:tmnt2
		DRIVER(tmnt22pu) //t:tmnt22pu f:tmnt.c r:tmnt2 c:tmnt2
//SET: ssriders
		DRIVER(ssriders) //t:ssriders f:tmnt.c r: c:
		DRIVER(ssridersebd) //t:ssridersebd f:tmnt.c r:ssriders c:ssriders
		DRIVER(ssridersebc) //t:ssridersebc f:tmnt.c r:ssriders c:ssriders
		DRIVER(ssridersuda) //t:ssridersuda f:tmnt.c r:ssriders c:ssriders
		DRIVER(ssriderseaa) //t:ssriderseaa f:tmnt.c r:ssriders c:ssriders
		DRIVER(ssridersuac) //t:ssridersuac f:tmnt.c r:ssriders c:ssriders
		DRIVER(ssridersubc) //t:ssridersubc f:tmnt.c r:ssriders c:ssriders
		DRIVER(ssridersabd) //t:ssridersabd f:tmnt.c r:ssriders c:ssriders
		DRIVER(ssridersadd) //t:ssridersadd f:tmnt.c r:ssriders c:ssriders
		DRIVER(ssridersjbd) //t:ssridersjbd f:tmnt.c r:ssriders c:ssriders
		DRIVER(ssridersb) //t:ssridersb f:tmnt.c r:ssriders c:ssriders
		DRIVER(ssriders2) //t:ssriders2 f:tmnt.c r:ssriders c:ssriders
//SET: xmen
		DRIVER(xmen) //t:xmen f:xmen.c r: c:
		DRIVER(xmenj) //t:xmenj f:xmen.c r:xmen c:xmen
		DRIVER(xmene) //t:xmene f:xmen.c r:xmen c:xmen
		DRIVER(xmen2pe) //t:xmen2pe f:xmen.c r:xmen c:xmen
		DRIVER(xmen2pa) //t:xmen2pa f:xmen.c r:xmen c:xmen
		DRIVER(xmen2pj) //t:xmen2pj f:xmen.c r:xmen c:xmen
		DRIVER(xmen6p) //t:xmen6p f:xmen.c r:xmen c:xmen
		DRIVER(xmen6pu) //t:xmen6pu f:xmen.c r:xmen c:xmen
//SET: xexex
		DRIVER(xexex) //t:xexex f:xexex.c r: c:
		DRIVER(xexexa) //t:xexexa f:xexex.c r:xexex c:xexex
		DRIVER(xexexj) //t:xexexj f:xexex.c r:xexex c:xexex
//SET: asterix
		DRIVER(asterix) //t:asterix f:asterix.c r: c:
		DRIVER(asterixeac) //t:asterixeac f:asterix.c r:asterix c:asterix
		DRIVER(asterixeaa) //t:asterixeaa f:asterix.c r:asterix c:asterix
		DRIVER(asterixaad) //t:asterixaad f:asterix.c r:asterix c:asterix
		DRIVER(asterixj) //t:asterixj f:asterix.c r:asterix c:asterix
//SET: gijoe
		DRIVER(gijoe) //t:gijoe f:gijoe.c r: c:
		DRIVER(gijoea) //t:gijoea f:gijoe.c r:gijoe c:gijoe
		DRIVER(gijoeu) //t:gijoeu f:gijoe.c r:gijoe c:gijoe
		DRIVER(gijoej) //t:gijoej f:gijoe.c r:gijoe c:gijoe
//SET: thndrx2
		DRIVER(thndrx2) //t:thndrx2 f:tmnt.c r: c:
		DRIVER(thndrx2a) //t:thndrx2a f:tmnt.c r:thndrx2 c:thndrx2
		DRIVER(thndrx2j) //t:thndrx2j f:tmnt.c r:thndrx2 c:thndrx2
//SET: prmrsocr
		DRIVER(prmrsocr) //t:prmrsocr f:tmnt.c r: c:
		DRIVER(prmrsocrj) //t:prmrsocrj f:tmnt.c r:prmrsocr c:prmrsocr
//SET: qgakumon
		DRIVER(qgakumon) //t:qgakumon f:tmnt.c r: c:
//SET: moomesa
		DRIVER(moomesa) //t:moomesa f:moo.c r: c:
		DRIVER(moomesau) //t:moomesau f:moo.c r:moomesa c:moomesa
		DRIVER(moomesaua) //t:moomesaua f:moo.c r:moomesa c:moomesa
		DRIVER(moomesaa) //t:moomesaa f:moo.c r:moomesa c:moomesa
		DRIVER(moomesabl) //t:moomesabl f:moo.c r:moomesa c:moomesa
//SET: bucky
		DRIVER(bucky) //t:bucky f:moo.c r: c:
		DRIVER(buckyua) //t:buckyua f:moo.c r:bucky c:bucky
		DRIVER(buckyaa) //t:buckyaa f:moo.c r:bucky c:bucky
//SET: gaiapols
		DRIVER(gaiapols) //t:gaiapols f:mystwarr.c r: c:
		DRIVER(gaiapolsu) //t:gaiapolsu f:mystwarr.c r:gaiapols c:gaiapols
		DRIVER(gaiapolsj) //t:gaiapolsj f:mystwarr.c r:gaiapols c:gaiapols
//SET: mystwarr
		DRIVER(mystwarr) //t:mystwarr f:mystwarr.c r: c:
		DRIVER(mystwarru) //t:mystwarru f:mystwarr.c r:mystwarr c:mystwarr
		DRIVER(mystwarrj) //t:mystwarrj f:mystwarr.c r:mystwarr c:mystwarr
		DRIVER(mystwarra) //t:mystwarra f:mystwarr.c r:mystwarr c:mystwarr
//SET: viostorm
		DRIVER(viostorm) //t:viostorm f:mystwarr.c r: c:
		DRIVER(viostormu) //t:viostormu f:mystwarr.c r:viostorm c:viostorm
		DRIVER(viostormub) //t:viostormub f:mystwarr.c r:viostorm c:viostorm
		DRIVER(viostormj) //t:viostormj f:mystwarr.c r:viostorm c:viostorm
		DRIVER(viostorma) //t:viostorma f:mystwarr.c r:viostorm c:viostorm
		DRIVER(viostormab) //t:viostormab f:mystwarr.c r:viostorm c:viostorm
//SET: mmaulers
		DRIVER(mmaulers) //t:mmaulers f:mystwarr.c r: c:
		DRIVER(dadandrn) //t:dadandrn f:mystwarr.c r:mmaulers c:mmaulers
//SET: metamrph
		DRIVER(metamrph) //t:metamrph f:mystwarr.c r: c:
		DRIVER(metamrphu) //t:metamrphu f:mystwarr.c r:metamrph c:metamrph
		DRIVER(metamrphj) //t:metamrphj f:mystwarr.c r:metamrph c:metamrph
//SET: mtlchamp
		DRIVER(mtlchamp) //t:mtlchamp f:mystwarr.c r: c:
		DRIVER(mtlchamp1) //t:mtlchamp1 f:mystwarr.c r:mtlchamp c:mtlchamp
		DRIVER(mtlchampu) //t:mtlchampu f:mystwarr.c r:mtlchamp c:mtlchamp
		DRIVER(mtlchampj) //t:mtlchampj f:mystwarr.c r:mtlchamp c:mtlchamp
		DRIVER(mtlchampa) //t:mtlchampa f:mystwarr.c r:mtlchamp c:mtlchamp
//SET: rungun
		DRIVER(rungun) //t:rungun f:rungun.c r: c:
		DRIVER(runguna) //t:runguna f:rungun.c r:rungun c:rungun
		DRIVER(rungunu) //t:rungunu f:rungun.c r:rungun c:rungun
		DRIVER(rungunua) //t:rungunua f:rungun.c r:rungun c:rungun
		DRIVER(slmdunkj) //t:slmdunkj f:rungun.c r:rungun c:rungun
//SET: dbz
		DRIVER(dbz) //t:dbz f:dbz.c r: c:
//SET: dbz2
		DRIVER(dbz2) //t:dbz2 f:dbz.c r: c:
//SET: bishi
		DRIVER(bishi) //t:bishi f:bishi.c r: c:
//SET: sbishi
		DRIVER(sbishi) //t:sbishi f:bishi.c r: c:
		DRIVER(sbishik) //t:sbishik f:bishi.c r:sbishi c:sbishi
//SET: overdriv
		DRIVER(overdriv) //t:overdriv f:overdriv.c r: c:
//SET: gradius3
		DRIVER(gradius3) //t:gradius3 f:gradius3.c r: c:
		DRIVER(gradius3a) //t:gradius3a f:gradius3.c r:gradius3 c:gradius3
		DRIVER(gradius3e) //t:gradius3e f:gradius3.c r:gradius3 c:gradius3
//SET: plygonet
		DRIVER(plygonet) //t:plygonet f:plygonet.c r: c:
//SET: polynetw
		DRIVER(polynetw) //t:polynetw f:plygonet.c r: c:
//SET: konamigx
		DRIVER(konamigx) //t:konamigx f:konamigx.c r: c:
//SET: racinfrc
		DRIVER(racinfrc) //t:racinfrc f:konamigx.c r:konamigx c:
		DRIVER(racinfrcu) //t:racinfrcu f:konamigx.c r:racinfrc c:racinfrc
//SET: opengolf
		DRIVER(opengolf) //t:opengolf f:konamigx.c r:konamigx c:
		DRIVER(opengolf2) //t:opengolf2 f:konamigx.c r:opengolf c:opengolf
		DRIVER(ggreats2) //t:ggreats2 f:konamigx.c r:opengolf c:opengolf
//SET: le2
		DRIVER(le2) //t:le2 f:konamigx.c r:konamigx c:
		DRIVER(le2u) //t:le2u f:konamigx.c r:le2 c:le2
		DRIVER(le2j) //t:le2j f:konamigx.c r:le2 c:le2
//SET: puzldama
		DRIVER(puzldama) //t:puzldama f:konamigx.c r:konamigx c:
//SET: fantjour
		DRIVER(fantjour) //t:fantjour f:konamigx.c r:konamigx c:
		DRIVER(gokuparo) //t:gokuparo f:konamigx.c r:fantjour c:fantjour
		DRIVER(fantjoura) //t:fantjoura f:konamigx.c r:fantjour c:fantjour
//SET: dragoona
		DRIVER(dragoona) //t:dragoona f:konamigx.c r:konamigx c:
		DRIVER(dragoonj) //t:dragoonj f:konamigx.c r:dragoona c:dragoona
//SET: tbyahhoo
		DRIVER(tbyahhoo) //t:tbyahhoo f:konamigx.c r:konamigx c:
//SET: tkmmpzdm
		DRIVER(tkmmpzdm) //t:tkmmpzdm f:konamigx.c r:konamigx c:
//SET: salmndr2
		DRIVER(salmndr2) //t:salmndr2 f:konamigx.c r:konamigx c:
		DRIVER(salmndr2a) //t:salmndr2a f:konamigx.c r:salmndr2 c:salmndr2
//SET: sexyparo
		DRIVER(sexyparo) //t:sexyparo f:konamigx.c r:konamigx c:
		DRIVER(sexyparoa) //t:sexyparoa f:konamigx.c r:sexyparo c:sexyparo
//SET: daiskiss
		DRIVER(daiskiss) //t:daiskiss f:konamigx.c r:konamigx c:
//SET: tokkae
		DRIVER(tokkae) //t:tokkae f:konamigx.c r:konamigx c:
//SET: winspike
		DRIVER(winspike) //t:winspike f:konamigx.c r:konamigx c:
		DRIVER(winspikej) //t:winspikej f:konamigx.c r:winspike c:winspike
//SET: soccerss
		DRIVER(soccerss) //t:soccerss f:konamigx.c r:konamigx c:
		DRIVER(soccerssj) //t:soccerssj f:konamigx.c r:soccerss c:soccerss
		DRIVER(soccerssja) //t:soccerssja f:konamigx.c r:soccerss c:soccerss
		DRIVER(soccerssa) //t:soccerssa f:konamigx.c r:soccerss c:soccerss
//SET: vsnetscr
		DRIVER(vsnetscr) //t:vsnetscr f:konamigx.c r:konamigx c:
		DRIVER(vsnetscreb) //t:vsnetscreb f:konamigx.c r:vsnetscr c:vsnetscr
		DRIVER(vsnetscru) //t:vsnetscru f:konamigx.c r:vsnetscr c:vsnetscr
		DRIVER(vsnetscra) //t:vsnetscra f:konamigx.c r:vsnetscr c:vsnetscr
		DRIVER(vsnetscrj) //t:vsnetscrj f:konamigx.c r:vsnetscr c:vsnetscr
//SET: rungun2
		DRIVER(rungun2) //t:rungun2 f:konamigx.c r:konamigx c:
		DRIVER(slamdnk2) //t:slamdnk2 f:konamigx.c r:rungun2 c:rungun2
//SET: rushhero
		DRIVER(rushhero) //t:rushhero f:konamigx.c r:konamigx c:
//SET: qdrmfgp
		DRIVER(qdrmfgp) //t:qdrmfgp f:qdrmfgp.c r: c:
//SET: qdrmfgp2
		DRIVER(qdrmfgp2) //t:qdrmfgp2 f:qdrmfgp.c r: c:
//SET: kingtut
		DRIVER(kingtut) //t:kingtut f:kongambl.c r: c:
//SET: moneybnk
		DRIVER(moneybnk) //t:moneybnk f:kongambl.c r: c:
//SET: bm1stmix
		DRIVER(bm1stmix) //t:bm1stmix f:djmain.c r: c:
//SET: bm2ndmix
		DRIVER(bm2ndmix) //t:bm2ndmix f:djmain.c r: c:
		DRIVER(bm2ndmxa) //t:bm2ndmxa f:djmain.c r:bm2ndmix c:bm2ndmix
//SET: bm3rdmix
		DRIVER(bm3rdmix) //t:bm3rdmix f:djmain.c r: c:
//SET: bmcompmx
		DRIVER(bmcompmx) //t:bmcompmx f:djmain.c r: c:
		DRIVER(hmcompmx) //t:hmcompmx f:djmain.c r:bmcompmx c:bmcompmx
//SET: bm4thmix
		DRIVER(bm4thmix) //t:bm4thmix f:djmain.c r: c:
//SET: bm5thmix
		DRIVER(bm5thmix) //t:bm5thmix f:djmain.c r: c:
//SET: bmclubmx
		DRIVER(bmclubmx) //t:bmclubmx f:djmain.c r: c:
//SET: bmcorerm
		DRIVER(bmcorerm) //t:bmcorerm f:djmain.c r: c:
//SET: bmdct
		DRIVER(bmdct) //t:bmdct f:djmain.c r: c:
//SET: bmcompm2
		DRIVER(bmcompm2) //t:bmcompm2 f:djmain.c r: c:
		DRIVER(hmcompm2) //t:hmcompm2 f:djmain.c r:bmcompm2 c:bmcompm2
//SET: bm6thmix
		DRIVER(bm6thmix) //t:bm6thmix f:djmain.c r: c:
//SET: bm7thmix
		DRIVER(bm7thmix) //t:bm7thmix f:djmain.c r: c:
//SET: bmfinal
		DRIVER(bmfinal) //t:bmfinal f:djmain.c r: c:
//SET: popn2
		DRIVER(popn2) //t:popn2 f:djmain.c r: c:
//SET: ppp
		DRIVER(ppp) //t:ppp f:firebeat.c r: c:
//SET: ppd
		DRIVER(ppd) //t:ppd f:firebeat.c r: c:
//SET: ppp11
		DRIVER(ppp11) //t:ppp11 f:firebeat.c r: c:
//SET: kbm
		DRIVER(kbm) //t:kbm f:firebeat.c r: c:
//SET: kbm2nd
		DRIVER(kbm2nd) //t:kbm2nd f:firebeat.c r: c:
//SET: kbm3rd
		DRIVER(kbm3rd) //t:kbm3rd f:firebeat.c r: c:
//SET: popn5
		DRIVER(popn5) //t:popn5 f:firebeat.c r: c:
//SET: popn7
		DRIVER(popn7) //t:popn7 f:firebeat.c r: c:
//SET: fiveside
		DRIVER(fiveside) //t:fiveside f:ultrsprt.c r: c:
//SET: thunderh
		DRIVER(thunderh) //t:thunderh f:gticlub.c r: c:
		DRIVER(thunderhu) //t:thunderhu f:gticlub.c r:thunderh c:thunderh
//SET: slrasslt
		DRIVER(slrasslt) //t:slrasslt f:gticlub.c r: c:
//SET: gticlub
		DRIVER(gticlub) //t:gticlub f:gticlub.c r: c:
		DRIVER(gticluba) //t:gticluba f:gticlub.c r:gticlub c:gticlub
		DRIVER(gticlubj) //t:gticlubj f:gticlub.c r:gticlub c:gticlub
//SET: hangplt
		DRIVER(hangplt) //t:hangplt f:gticlub.c r: c:
//SET: nbapbp
		DRIVER(nbapbp) //t:nbapbp f:hornet.c r: c:
//SET: terabrst
		DRIVER(terabrst) //t:terabrst f:hornet.c r: c:
		DRIVER(terabrsta) //t:terabrsta f:hornet.c r:terabrst c:terabrst
//SET: gradius4
		DRIVER(gradius4) //t:gradius4 f:hornet.c r: c:
//SET: sscope
		DRIVER(sscope) //t:sscope f:hornet.c r: c:
		DRIVER(sscopea) //t:sscopea f:hornet.c r:sscope c:sscope
		DRIVER(sscopeb) //t:sscopeb f:hornet.c r:sscope c:sscope
//SET: sscope2
		DRIVER(sscope2) //t:sscope2 f:hornet.c r: c:
//SET: racingj
		DRIVER(racingj) //t:racingj f:nwk-tr.c r: c:
		DRIVER(racingj2) //t:racingj2 f:nwk-tr.c r:racingj c:racingj
//SET: thrilld
		DRIVER(thrilld) //t:thrilld f:nwk-tr.c r: c:
		DRIVER(thrilldb) //t:thrilldb f:nwk-tr.c r:thrilld c:thrilld
//SET: midnrun
		DRIVER(midnrun) //t:midnrun f:zr107.c r: c:
//SET: windheat
		DRIVER(windheat) //t:windheat f:zr107.c r: c:
		DRIVER(windheatu) //t:windheatu f:zr107.c r:windheat c:windheat
		DRIVER(windheatj) //t:windheatj f:zr107.c r:windheat c:windheat
//SET: waveshrk
		DRIVER(waveshrk) //t:waveshrk f:zr107.c r: c:
//SET: polystar
		DRIVER(polystar) //t:polystar f:konamim2.c r: c:
//SET: totlvice
		DRIVER(totlvice) //t:totlvice f:konamim2.c r: c:
		DRIVER(totlvicj) //t:totlvicj f:konamim2.c r:totlvice c:totlvice
//SET: btltryst
		DRIVER(btltryst) //t:btltryst f:konamim2.c r: c:
//SET: heatof11
		DRIVER(heatof11) //t:heatof11 f:konamim2.c r: c:
//SET: evilngt
		DRIVER(evilngt) //t:evilngt f:konamim2.c r: c:
		DRIVER(evilngte) //t:evilngte f:konamim2.c r:evilngt c:evilngt
		DRIVER(hellngt) //t:hellngt f:konamim2.c r:evilngt c:evilngt
//SET: carpolo
		DRIVER(carpolo) //t:carpolo f:carpolo.c r: c:
//SET: sidetrac
		DRIVER(sidetrac) //t:sidetrac f:exidy.c r: c:
//SET: targ
		DRIVER(targ) //t:targ f:exidy.c r: c:
		DRIVER(targc) //t:targc f:exidy.c r:targ c:targ
//SET: spectar
		DRIVER(spectar) //t:spectar f:exidy.c r: c:
		DRIVER(spectar1) //t:spectar1 f:exidy.c r:spectar c:spectar
		DRIVER(rallys) //t:rallys f:exidy.c r:spectar c:spectar
		DRIVER(panzer) //t:panzer f:exidy.c r:spectar c:spectar
		DRIVER(phantoma) //t:phantoma f:exidy.c r:spectar c:spectar
		DRIVER(phantom) //t:phantom f:exidy.c r:spectar c:spectar
//SET: venture
		DRIVER(venture) //t:venture f:exidy.c r: c:
		DRIVER(venture2) //t:venture2 f:exidy.c r:venture c:venture
		DRIVER(venture4) //t:venture4 f:exidy.c r:venture c:venture
//SET: teetert
		DRIVER(teetert) //t:teetert f:exidy.c r: c:
//SET: mtrap
		DRIVER(mtrap) //t:mtrap f:exidy.c r: c:
		DRIVER(mtrap3) //t:mtrap3 f:exidy.c r:mtrap c:mtrap
		DRIVER(mtrap4) //t:mtrap4 f:exidy.c r:mtrap c:mtrap
//SET: pepper2
		DRIVER(pepper2) //t:pepper2 f:exidy.c r: c:
//SET: hardhat
		DRIVER(hardhat) //t:hardhat f:exidy.c r: c:
//SET: fax
		DRIVER(fax) //t:fax f:exidy.c r: c:
		DRIVER(fax2) //t:fax2 f:exidy.c r:fax c:fax
//SET: circus
		DRIVER(circus) //t:circus f:circus.c r: c:
		DRIVER(circusse) //t:circusse f:circus.c r:circus c:circus
//SET: robotbwl
		DRIVER(robotbwl) //t:robotbwl f:circus.c r: c:
//SET: crash
		DRIVER(crash) //t:crash f:circus.c r: c:
		DRIVER(smash) //t:smash f:circus.c r:crash c:crash
//SET: ripcord
		DRIVER(ripcord) //t:ripcord f:circus.c r: c:
//SET: starfire
		DRIVER(starfire) //t:starfire f:starfire.c r: c:
		DRIVER(starfirea) //t:starfirea f:starfire.c r:starfire c:starfire
//SET: fireone
		DRIVER(fireone) //t:fireone f:starfire.c r: c:
//SET: starfir2
		DRIVER(starfir2) //t:starfir2 f:starfire.c r: c:
//SET: victory
		DRIVER(victory) //t:victory f:victory.c r: c:
		DRIVER(victorba) //t:victorba f:victory.c r:victory c:victory
//SET: topgunnr
		DRIVER(topgunnr) //t:topgunnr f:vertigo.c r: c:
//SET: crossbow
		DRIVER(crossbow) //t:crossbow f:exidy440.c r: c:
//SET: cheyenne
		DRIVER(cheyenne) //t:cheyenne f:exidy440.c r: c:
//SET: combat
		DRIVER(combat) //t:combat f:exidy440.c r: c:
		DRIVER(catch22) //t:catch22 f:exidy440.c r:combat c:combat
//SET: cracksht
		DRIVER(cracksht) //t:cracksht f:exidy440.c r: c:
//SET: claypign
		DRIVER(claypign) //t:claypign f:exidy440.c r: c:
//SET: chiller
		DRIVER(chiller) //t:chiller f:exidy440.c r: c:
//SET: topsecex
		DRIVER(topsecex) //t:topsecex f:exidy440.c r: c:
//SET: hitnmiss
		DRIVER(hitnmiss) //t:hitnmiss f:exidy440.c r: c:
		DRIVER(hitnmiss2) //t:hitnmiss2 f:exidy440.c r:hitnmiss c:hitnmiss
//SET: whodunit
		DRIVER(whodunit) //t:whodunit f:exidy440.c r: c:
//SET: showdown
		DRIVER(showdown) //t:showdown f:exidy440.c r: c:
//SET: yukon
		DRIVER(yukon) //t:yukon f:exidy440.c r: c:
		DRIVER(yukon1) //t:yukon1 f:exidy440.c r:yukon c:yukon
#endif

#ifdef PS3_SET_11
//SET: maxaflex
		DRIVER(maxaflex) //t:maxaflex f:maxaflex.c r: c:
//SET: mf_achas
		DRIVER(mf_achas) //t:mf_achas f:maxaflex.c r:maxaflex c:
//SET: mf_brist
		DRIVER(mf_brist) //t:mf_brist f:maxaflex.c r:maxaflex c:
//SET: mf_flip
		DRIVER(mf_flip) //t:mf_flip f:maxaflex.c r:maxaflex c:
//SET: mf_bdash
		DRIVER(mf_bdash) //t:mf_bdash f:maxaflex.c r:maxaflex c:
//SET: tank8
		DRIVER(tank8) //t:tank8 f:tank8.c r: c:
		DRIVER(tank8a) //t:tank8a f:tank8.c r:tank8 c:tank8
		DRIVER(tank8b) //t:tank8b f:tank8.c r:tank8 c:tank8
		DRIVER(tank8c) //t:tank8c f:tank8.c r:tank8 c:tank8
		DRIVER(tank8d) //t:tank8d f:tank8.c r:tank8 c:tank8
//SET: cball
		DRIVER(cball) //t:cball f:cball.c r: c:
//SET: copsnrob
		DRIVER(copsnrob) //t:copsnrob f:copsnrob.c r: c:
//SET: flyball
		DRIVER(flyball) //t:flyball f:flyball.c r: c:
//SET: sprint4
		DRIVER(sprint4) //t:sprint4 f:sprint4.c r: c:
		DRIVER(sprint4a) //t:sprint4a f:sprint4.c r:sprint4 c:sprint4
//SET: nitedrvr
		DRIVER(nitedrvr) //t:nitedrvr f:nitedrvr.c r: c:
//SET: dominos
		DRIVER(dominos) //t:dominos f:sprint2.c r: c:
//SET: triplhnt
		DRIVER(triplhnt) //t:triplhnt f:triplhnt.c r: c:
//SET: sprint8
		DRIVER(sprint8) //t:sprint8 f:sprint8.c r: c:
		DRIVER(sprint8a) //t:sprint8a f:sprint8.c r:sprint8 c:sprint8
//SET: dragrace
		DRIVER(dragrace) //t:dragrace f:dragrace.c r: c:
//SET: poolshrk
		DRIVER(poolshrk) //t:poolshrk f:poolshrk.c r: c:
//SET: starshp1
		DRIVER(starshp1) //t:starshp1 f:starshp1.c r: c:
		DRIVER(starshpp) //t:starshpp f:starshp1.c r:starshp1 c:starshp1
//SET: superbug
		DRIVER(superbug) //t:superbug f:firetrk.c r: c:
//SET: canyon
		DRIVER(canyon) //t:canyon f:canyon.c r: c:
		DRIVER(canyonp) //t:canyonp f:canyon.c r:canyon c:canyon
//SET: destroyr
		DRIVER(destroyr) //t:destroyr f:destroyr.c r: c:
		DRIVER(destroyr1) //t:destroyr1 f:destroyr.c r:destroyr c:destroyr
//SET: catchp
		DRIVER(catchp) //t:catchp f:avalnche.c r: c:
//SET: sprint1
		DRIVER(sprint1) //t:sprint1 f:sprint2.c r: c:
		DRIVER(sprint2) //t:sprint2 f:sprint2.c r:sprint1 c:sprint1
		DRIVER(sprint2a) //t:sprint2a f:sprint2.c r:sprint1 c:sprint1
//SET: ultratnk
		DRIVER(ultratnk) //t:ultratnk f:ultratnk.c r: c:
//SET: skyraid
		DRIVER(skyraid) //t:skyraid f:skyraid.c r: c:
//SET: tourtabl
		DRIVER(tourtabl) //t:tourtabl f:tourtabl.c r: c:
		DRIVER(tourtab2) //t:tourtab2 f:tourtabl.c r:tourtabl c:tourtabl
//SET: avalnche
		DRIVER(avalnche) //t:avalnche f:avalnche.c r: c:
		DRIVER(cascade) //t:cascade f:avalnche.c r:avalnche c:avalnche
//SET: firetrk
		DRIVER(firetrk) //t:firetrk f:firetrk.c r: c:
//SET: skydiver
		DRIVER(skydiver) //t:skydiver f:skydiver.c r: c:
//SET: sbrkout
		DRIVER(sbrkout) //t:sbrkout f:sbrkout.c r: c:
		DRIVER(sbrkout3) //t:sbrkout3 f:sbrkout.c r:sbrkout c:sbrkout
//SET: atarifb
		DRIVER(atarifb) //t:atarifb f:atarifb.c r: c:
		DRIVER(atarifb1) //t:atarifb1 f:atarifb.c r:atarifb c:atarifb
		DRIVER(atarifb4) //t:atarifb4 f:atarifb.c r:atarifb c:atarifb
//SET: orbit
		DRIVER(orbit) //t:orbit f:orbit.c r: c:
//SET: boxer
		DRIVER(boxer) //t:boxer f:boxer.c r: c:
//SET: wolfpack
		DRIVER(wolfpack) //t:wolfpack f:wolfpack.c r: c:
//SET: mgolf
		DRIVER(mgolf) //t:mgolf f:mgolf.c r: c:
//SET: videopin
		DRIVER(videopin) //t:videopin f:videopin.c r: c:
//SET: subs
		DRIVER(subs) //t:subs f:subs.c r: c:
//SET: bsktball
		DRIVER(bsktball) //t:bsktball f:bsktball.c r: c:
//SET: abaseb
		DRIVER(abaseb) //t:abaseb f:atarifb.c r: c:
		DRIVER(abaseb2) //t:abaseb2 f:atarifb.c r:abaseb c:abaseb
//SET: montecar
		DRIVER(montecar) //t:montecar f:firetrk.c r: c:
//SET: soccer
		DRIVER(soccer) //t:soccer f:atarifb.c r: c:
//SET: missile
		DRIVER(missile) //t:missile f:missile.c r: c:
		DRIVER(missile2) //t:missile2 f:missile.c r:missile c:missile
		DRIVER(suprmatk) //t:suprmatk f:missile.c r:missile c:missile
		DRIVER(suprmatkd) //t:suprmatkd f:missile.c r:missile c:missile
		DRIVER(mcombat) //t:mcombat f:missile.c r:missile c:missile
		DRIVER(mcombata) //t:mcombata f:missile.c r:missile c:missile
//SET: llander
		DRIVER(llander) //t:llander f:asteroid.c r: c:
		DRIVER(llander1) //t:llander1 f:asteroid.c r:llander c:llander
//SET: asteroid
		DRIVER(asteroid) //t:asteroid f:asteroid.c r: c:
		DRIVER(asteroid2) //t:asteroid2 f:asteroid.c r:asteroid c:asteroid
		DRIVER(asteroid1) //t:asteroid1 f:asteroid.c r:asteroid c:asteroid
		DRIVER(asteroidb) //t:asteroidb f:asteroid.c r:asteroid c:asteroid
		DRIVER(asterock) //t:asterock f:asteroid.c r:asteroid c:asteroid
		DRIVER(meteorts) //t:meteorts f:asteroid.c r:asteroid c:asteroid
		DRIVER(meteorho) //t:meteorho f:asteroid.c r:asteroid c:asteroid
//SET: astdelux
		DRIVER(astdelux) //t:astdelux f:asteroid.c r: c:
		DRIVER(astdelux2) //t:astdelux2 f:asteroid.c r:astdelux c:astdelux
		DRIVER(astdelux1) //t:astdelux1 f:asteroid.c r:astdelux c:astdelux
//SET: bzone
		DRIVER(bzone) //t:bzone f:bzone.c r: c:
		DRIVER(bzone2) //t:bzone2 f:bzone.c r:bzone c:bzone
		DRIVER(bzonec) //t:bzonec f:bzone.c r:bzone c:bzone
//SET: bradley
		DRIVER(bradley) //t:bradley f:bzone.c r: c:
//SET: redbaron
		DRIVER(redbaron) //t:redbaron f:bzone.c r: c:
//SET: tempest
		DRIVER(tempest) //t:tempest f:tempest.c r: c:
		DRIVER(tempest1) //t:tempest1 f:tempest.c r:tempest c:tempest
		DRIVER(tempest2) //t:tempest2 f:tempest.c r:tempest c:tempest
		DRIVER(tempest3) //t:tempest3 f:tempest.c r:tempest c:tempest
		DRIVER(temptube) //t:temptube f:tempest.c r:tempest c:tempest
//SET: spacduel
		DRIVER(spacduel) //t:spacduel f:bwidow.c r: c:
//SET: gravitar
		DRIVER(gravitar) //t:gravitar f:bwidow.c r: c:
		DRIVER(gravitar2) //t:gravitar2 f:bwidow.c r:gravitar c:gravitar
		DRIVER(gravp) //t:gravp f:bwidow.c r:gravitar c:gravitar
		DRIVER(lunarbat) //t:lunarbat f:bwidow.c r:gravitar c:gravitar
		DRIVER(lunarba1) //t:lunarba1 f:bwidow.c r:gravitar c:gravitar
//SET: quantum
		DRIVER(quantum) //t:quantum f:quantum.c r: c:
		DRIVER(quantum1) //t:quantum1 f:quantum.c r:quantum c:quantum
		DRIVER(quantump) //t:quantump f:quantum.c r:quantum c:quantum
//SET: bwidow
		DRIVER(bwidow) //t:bwidow f:bwidow.c r: c:
//SET: starwars
		DRIVER(starwars) //t:starwars f:starwars.c r: c:
		DRIVER(starwars1) //t:starwars1 f:starwars.c r:starwars c:starwars
//SET: mhavoc
		DRIVER(mhavoc) //t:mhavoc f:mhavoc.c r: c:
		DRIVER(mhavoc2) //t:mhavoc2 f:mhavoc.c r:mhavoc c:mhavoc
		DRIVER(mhavocp) //t:mhavocp f:mhavoc.c r:mhavoc c:mhavoc
		DRIVER(mhavocrv) //t:mhavocrv f:mhavoc.c r:mhavoc c:mhavoc
		DRIVER(alphaone) //t:alphaone f:mhavoc.c r:mhavoc c:mhavoc
		DRIVER(alphaonea) //t:alphaonea f:mhavoc.c r:mhavoc c:mhavoc
//SET: esb
		DRIVER(esb) //t:esb f:starwars.c r: c:
//SET: tomcat
		DRIVER(tomcat) //t:tomcat f:tomcat.c r: c:
		DRIVER(tomcatsw) //t:tomcatsw f:starwars.c r:tomcat c:tomcat
//SET: warlords
		DRIVER(warlords) //t:warlords f:centiped.c r: c:
//SET: centiped
		DRIVER(centiped) //t:centiped f:centiped.c r: c:
		DRIVER(centiped2) //t:centiped2 f:centiped.c r:centiped c:centiped
		DRIVER(centtime) //t:centtime f:centiped.c r:centiped c:centiped
		DRIVER(centipdb) //t:centipdb f:centiped.c r:centiped c:centiped
		DRIVER(centipdd) //t:centipdd f:centiped.c r:centiped c:centiped
		DRIVER(caterplr) //t:caterplr f:centiped.c r:centiped c:centiped
		DRIVER(millpac) //t:millpac f:centiped.c r:centiped c:centiped
		DRIVER(magworm) //t:magworm f:centiped.c r:centiped c:centiped
//SET: mazeinv
		DRIVER(mazeinv) //t:mazeinv f:centiped.c r: c:
//SET: milliped
		DRIVER(milliped) //t:milliped f:centiped.c r: c:
		DRIVER(millipdd) //t:millipdd f:centiped.c r:milliped c:milliped
//SET: qwak
		DRIVER(qwak) //t:qwak f:runaway.c r: c:
//SET: runaway
		DRIVER(runaway) //t:runaway f:runaway.c r: c:
//SET: bullsdrt
		DRIVER(bullsdrt) //t:bullsdrt f:centiped.c r: c:
//SET: cmmb162
		DRIVER(cmmb162) //t:cmmb162 f:cmmb.c r: c:
//SET: tunhunt
		DRIVER(tunhunt) //t:tunhunt f:tunhunt.c r: c:
		DRIVER(tunhuntc) //t:tunhuntc f:tunhunt.c r:tunhunt c:tunhunt
//SET: liberatr
		DRIVER(liberatr) //t:liberatr f:liberatr.c r: c:
		DRIVER(liberatr2) //t:liberatr2 f:liberatr.c r:liberatr c:liberatr
//SET: foodf
		DRIVER(foodf) //t:foodf f:foodf.c r: c:
		DRIVER(foodf2) //t:foodf2 f:foodf.c r:foodf c:foodf
		DRIVER(foodfc) //t:foodfc f:foodf.c r:foodf c:foodf
//SET: ccastles
		DRIVER(ccastles) //t:ccastles f:ccastles.c r: c:
		DRIVER(ccastlesg) //t:ccastlesg f:ccastles.c r:ccastles c:ccastles
		DRIVER(ccastlesp) //t:ccastlesp f:ccastles.c r:ccastles c:ccastles
		DRIVER(ccastlesf) //t:ccastlesf f:ccastles.c r:ccastles c:ccastles
		DRIVER(ccastles3) //t:ccastles3 f:ccastles.c r:ccastles c:ccastles
		DRIVER(ccastles2) //t:ccastles2 f:ccastles.c r:ccastles c:ccastles
		DRIVER(ccastles1) //t:ccastles1 f:ccastles.c r:ccastles c:ccastles
		DRIVER(ccastlesj) //t:ccastlesj f:ccastles.c r:ccastles c:ccastles
//SET: cloak
		DRIVER(cloak) //t:cloak f:cloak.c r: c:
		DRIVER(cloaksp) //t:cloaksp f:cloak.c r:cloak c:cloak
		DRIVER(cloakfr) //t:cloakfr f:cloak.c r:cloak c:cloak
		DRIVER(cloakgr) //t:cloakgr f:cloak.c r:cloak c:cloak
		DRIVER(agentx4) //t:agentx4 f:cloak.c r:cloak c:cloak
		DRIVER(agentx3) //t:agentx3 f:cloak.c r:cloak c:cloak
		DRIVER(agentx2) //t:agentx2 f:cloak.c r:cloak c:cloak
		DRIVER(agentx1) //t:agentx1 f:cloak.c r:cloak c:cloak
//SET: cloud9
		DRIVER(cloud9) //t:cloud9 f:cloud9.c r: c:
//SET: firebeas
		DRIVER(firebeas) //t:firebeas f:cloud9.c r: c:
//SET: barbball
		DRIVER(barbball) //t:barbball f:bartop52.c r: c:
//SET: firefox
		DRIVER(firefox) //t:firefox f:firefox.c r: c:
		DRIVER(firefoxa) //t:firefoxa f:firefox.c r:firefox c:firefox
//SET: jedi
		DRIVER(jedi) //t:jedi f:jedi.c r: c:
//SET: atarisy1
		DRIVER(atarisy1) //t:atarisy1 f:atarisy1.c r: c:
//SET: peterpak
		DRIVER(peterpak) //t:peterpak f:atarisy1.c r:atarisy1 c:
//SET: marble
		DRIVER(marble) //t:marble f:atarisy1.c r:atarisy1 c:
		DRIVER(marble2) //t:marble2 f:atarisy1.c r:marble c:marble
		DRIVER(marble3) //t:marble3 f:atarisy1.c r:marble c:marble
		DRIVER(marble4) //t:marble4 f:atarisy1.c r:marble c:marble
		DRIVER(marble5) //t:marble5 f:atarisy1.c r:marble c:marble
//SET: indytemp
		DRIVER(indytemp) //t:indytemp f:atarisy1.c r:atarisy1 c:
		DRIVER(indytemp2) //t:indytemp2 f:atarisy1.c r:indytemp c:indytemp
		DRIVER(indytemp3) //t:indytemp3 f:atarisy1.c r:indytemp c:indytemp
		DRIVER(indytemp4) //t:indytemp4 f:atarisy1.c r:indytemp c:indytemp
		DRIVER(indytempd) //t:indytempd f:atarisy1.c r:indytemp c:indytemp
		DRIVER(indytempc) //t:indytempc f:atarisy1.c r:indytemp c:indytemp
//SET: roadrunn
		DRIVER(roadrunn) //t:roadrunn f:atarisy1.c r:atarisy1 c:
		DRIVER(roadrunn2) //t:roadrunn2 f:atarisy1.c r:roadrunn c:roadrunn
		DRIVER(roadrunn1) //t:roadrunn1 f:atarisy1.c r:roadrunn c:roadrunn
//SET: roadblst
		DRIVER(roadblst) //t:roadblst f:atarisy1.c r:atarisy1 c:
		DRIVER(roadblstg) //t:roadblstg f:atarisy1.c r:roadblst c:roadblst
		DRIVER(roadblst3) //t:roadblst3 f:atarisy1.c r:roadblst c:roadblst
		DRIVER(roadblstg2) //t:roadblstg2 f:atarisy1.c r:roadblst c:roadblst
		DRIVER(roadblst2) //t:roadblst2 f:atarisy1.c r:roadblst c:roadblst
		DRIVER(roadblstg1) //t:roadblstg1 f:atarisy1.c r:roadblst c:roadblst
		DRIVER(roadblst1) //t:roadblst1 f:atarisy1.c r:roadblst c:roadblst
		DRIVER(roadblstc) //t:roadblstc f:atarisy1.c r:roadblst c:roadblst
		DRIVER(roadblstcg) //t:roadblstcg f:atarisy1.c r:roadblst c:roadblst
		DRIVER(roadblstc1) //t:roadblstc1 f:atarisy1.c r:roadblst c:roadblst
//SET: paperboy
		DRIVER(paperboy) //t:paperboy f:atarisy2.c r: c:
		DRIVER(paperboyr2) //t:paperboyr2 f:atarisy2.c r:paperboy c:paperboy
		DRIVER(paperboyr1) //t:paperboyr1 f:atarisy2.c r:paperboy c:paperboy
//SET: ssprint
		DRIVER(ssprint) //t:ssprint f:atarisy2.c r: c:
		DRIVER(ssprint3) //t:ssprint3 f:atarisy2.c r:ssprint c:ssprint
		DRIVER(ssprint1) //t:ssprint1 f:atarisy2.c r:ssprint c:ssprint
		DRIVER(ssprintg) //t:ssprintg f:atarisy2.c r:ssprint c:ssprint
		DRIVER(ssprintg1) //t:ssprintg1 f:atarisy2.c r:ssprint c:ssprint
		DRIVER(ssprintf) //t:ssprintf f:atarisy2.c r:ssprint c:ssprint
		DRIVER(ssprints) //t:ssprints f:atarisy2.c r:ssprint c:ssprint
//SET: csprint
		DRIVER(csprint) //t:csprint f:atarisy2.c r: c:
		DRIVER(csprint2) //t:csprint2 f:atarisy2.c r:csprint c:csprint
		DRIVER(csprint1) //t:csprint1 f:atarisy2.c r:csprint c:csprint
		DRIVER(csprintg) //t:csprintg f:atarisy2.c r:csprint c:csprint
		DRIVER(csprintg1) //t:csprintg1 f:atarisy2.c r:csprint c:csprint
		DRIVER(csprintf) //t:csprintf f:atarisy2.c r:csprint c:csprint
		DRIVER(csprints) //t:csprints f:atarisy2.c r:csprint c:csprint
		DRIVER(csprints1) //t:csprints1 f:atarisy2.c r:csprint c:csprint
//SET: 720
		DRIVER(720) //t:720 f:atarisy2.c r: c:
		DRIVER(720r3) //t:720r3 f:atarisy2.c r:720 c:720
		DRIVER(720r2) //t:720r2 f:atarisy2.c r:720 c:720
		DRIVER(720r1) //t:720r1 f:atarisy2.c r:720 c:720
		DRIVER(720g) //t:720g f:atarisy2.c r:720 c:720
		DRIVER(720gr1) //t:720gr1 f:atarisy2.c r:720 c:720
//SET: apb
		DRIVER(apb) //t:apb f:atarisy2.c r: c:
		DRIVER(apb6) //t:apb6 f:atarisy2.c r:apb c:apb
		DRIVER(apb5) //t:apb5 f:atarisy2.c r:apb c:apb
		DRIVER(apb4) //t:apb4 f:atarisy2.c r:apb c:apb
		DRIVER(apb3) //t:apb3 f:atarisy2.c r:apb c:apb
		DRIVER(apb2) //t:apb2 f:atarisy2.c r:apb c:apb
		DRIVER(apb1) //t:apb1 f:atarisy2.c r:apb c:apb
		DRIVER(apbg) //t:apbg f:atarisy2.c r:apb c:apb
		DRIVER(apbf) //t:apbf f:atarisy2.c r:apb c:apb
//SET: irobot
		DRIVER(irobot) //t:irobot f:irobot.c r: c:
//SET: laststar
		DRIVER(laststar) //t:laststar f:atarisy4.c r: c:
//SET: airrace
		DRIVER(airrace) //t:airrace f:atarisy4.c r: c:
//SET: harddriv
		DRIVER(harddriv) //t:harddriv f:harddriv.c r: c:
		DRIVER(harddrivb) //t:harddrivb f:harddriv.c r:harddriv c:harddriv
		DRIVER(harddrivg) //t:harddrivg f:harddriv.c r:harddriv c:harddriv
		DRIVER(harddrivj) //t:harddrivj f:harddriv.c r:harddriv c:harddriv
		DRIVER(harddrivb6) //t:harddrivb6 f:harddriv.c r:harddriv c:harddriv
		DRIVER(harddrivj6) //t:harddrivj6 f:harddriv.c r:harddriv c:harddriv
		DRIVER(harddrivb5) //t:harddrivb5 f:harddriv.c r:harddriv c:harddriv
		DRIVER(harddrivg4) //t:harddrivg4 f:harddriv.c r:harddriv c:harddriv
		DRIVER(harddriv3) //t:harddriv3 f:harddriv.c r:harddriv c:harddriv
		DRIVER(harddriv2) //t:harddriv2 f:harddriv.c r:harddriv c:harddriv
		DRIVER(harddriv1) //t:harddriv1 f:harddriv.c r:harddriv c:harddriv
		DRIVER(harddrivc) //t:harddrivc f:harddriv.c r:harddriv c:harddriv
		DRIVER(harddrivcg) //t:harddrivcg f:harddriv.c r:harddriv c:harddriv
		DRIVER(harddrivcb) //t:harddrivcb f:harddriv.c r:harddriv c:harddriv
		DRIVER(harddrivc1) //t:harddrivc1 f:harddriv.c r:harddriv c:harddriv
//SET: stunrun
		DRIVER(stunrun) //t:stunrun f:harddriv.c r: c:
		DRIVER(stunrunj) //t:stunrunj f:harddriv.c r:stunrun c:stunrun
		DRIVER(stunrun5) //t:stunrun5 f:harddriv.c r:stunrun c:stunrun
		DRIVER(stunrune) //t:stunrune f:harddriv.c r:stunrun c:stunrun
		DRIVER(stunrun4) //t:stunrun4 f:harddriv.c r:stunrun c:stunrun
		DRIVER(stunrun3) //t:stunrun3 f:harddriv.c r:stunrun c:stunrun
		DRIVER(stunrun3e) //t:stunrun3e f:harddriv.c r:stunrun c:stunrun
		DRIVER(stunrun2) //t:stunrun2 f:harddriv.c r:stunrun c:stunrun
		DRIVER(stunrun2e) //t:stunrun2e f:harddriv.c r:stunrun c:stunrun
		DRIVER(stunrun0) //t:stunrun0 f:harddriv.c r:stunrun c:stunrun
		DRIVER(stunrunp) //t:stunrunp f:harddriv.c r:stunrun c:stunrun
//SET: racedriv
		DRIVER(racedriv) //t:racedriv f:harddriv.c r: c:
		DRIVER(racedrivb) //t:racedrivb f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedrivg) //t:racedrivg f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedriv4) //t:racedriv4 f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedrivb4) //t:racedrivb4 f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedrivg4) //t:racedrivg4 f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedriv3) //t:racedriv3 f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedriv2) //t:racedriv2 f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedriv1) //t:racedriv1 f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedrivb1) //t:racedrivb1 f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedrivg1) //t:racedrivg1 f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedrivc) //t:racedrivc f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedrivcb) //t:racedrivcb f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedrivcg) //t:racedrivcg f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedrivc4) //t:racedrivc4 f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedrivcb4) //t:racedrivcb4 f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedrivcg4) //t:racedrivcg4 f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedrivc2) //t:racedrivc2 f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedrivc1) //t:racedrivc1 f:harddriv.c r:racedriv c:racedriv
		DRIVER(racedrivpan) //t:racedrivpan f:harddriv.c r:racedriv c:racedriv
//SET: steeltal
		DRIVER(steeltal) //t:steeltal f:harddriv.c r: c:
		DRIVER(steeltalg) //t:steeltalg f:harddriv.c r:steeltal c:steeltal
		DRIVER(steeltal1) //t:steeltal1 f:harddriv.c r:steeltal c:steeltal
		DRIVER(steeltalp) //t:steeltalp f:harddriv.c r:steeltal c:steeltal
//SET: strtdriv
		DRIVER(strtdriv) //t:strtdriv f:harddriv.c r: c:
//SET: hdrivair
		DRIVER(hdrivair) //t:hdrivair f:harddriv.c r: c:
		DRIVER(hdrivairp) //t:hdrivairp f:harddriv.c r:hdrivair c:hdrivair
//SET: gauntlet
		DRIVER(gauntlet) //t:gauntlet f:gauntlet.c r: c:
		DRIVER(gauntlets) //t:gauntlets f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntletj) //t:gauntletj f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntletg) //t:gauntletg f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntletj12) //t:gauntletj12 f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntletr9) //t:gauntletr9 f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntletgr8) //t:gauntletgr8 f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntletr7) //t:gauntletr7 f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntletgr6) //t:gauntletgr6 f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntletr5) //t:gauntletr5 f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntletr4) //t:gauntletr4 f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntletgr3) //t:gauntletgr3 f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntletr2) //t:gauntletr2 f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntletr1) //t:gauntletr1 f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntlet2p) //t:gauntlet2p f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntlet2pj) //t:gauntlet2pj f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntlet2pg) //t:gauntlet2pg f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntlet2pr3) //t:gauntlet2pr3 f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntlet2pj2) //t:gauntlet2pj2 f:gauntlet.c r:gauntlet c:gauntlet
		DRIVER(gauntlet2pg1) //t:gauntlet2pg1 f:gauntlet.c r:gauntlet c:gauntlet
//SET: gaunt2
		DRIVER(gaunt2) //t:gaunt2 f:gauntlet.c r: c:
		DRIVER(gaunt2g) //t:gaunt2g f:gauntlet.c r:gaunt2 c:gaunt2
		DRIVER(gaunt22p) //t:gaunt22p f:gauntlet.c r:gaunt2 c:gaunt2
		DRIVER(gaunt22p1) //t:gaunt22p1 f:gauntlet.c r:gaunt2 c:gaunt2
		DRIVER(gaunt22pg) //t:gaunt22pg f:gauntlet.c r:gaunt2 c:gaunt2
//SET: vindctr2
		DRIVER(vindctr2) //t:vindctr2 f:gauntlet.c r: c:
		DRIVER(vindctr2r2) //t:vindctr2r2 f:gauntlet.c r:vindctr2 c:vindctr2
		DRIVER(vindctr2r1) //t:vindctr2r1 f:gauntlet.c r:vindctr2 c:vindctr2
//SET: xybots
		DRIVER(xybots) //t:xybots f:xybots.c r: c:
		DRIVER(xybotsg) //t:xybotsg f:xybots.c r:xybots c:xybots
		DRIVER(xybotsf) //t:xybotsf f:xybots.c r:xybots c:xybots
		DRIVER(xybots1) //t:xybots1 f:xybots.c r:xybots c:xybots
		DRIVER(xybots0) //t:xybots0 f:xybots.c r:xybots c:xybots
//SET: blstroid
		DRIVER(blstroid) //t:blstroid f:blstroid.c r: c:
		DRIVER(blstroid3) //t:blstroid3 f:blstroid.c r:blstroid c:blstroid
		DRIVER(blstroid2) //t:blstroid2 f:blstroid.c r:blstroid c:blstroid
		DRIVER(blstroidg) //t:blstroidg f:blstroid.c r:blstroid c:blstroid
		DRIVER(blstroidh) //t:blstroidh f:blstroid.c r:blstroid c:blstroid
//SET: vindictr
		DRIVER(vindictr) //t:vindictr f:vindictr.c r: c:
		DRIVER(vindictre) //t:vindictre f:vindictr.c r:vindictr c:vindictr
		DRIVER(vindictrg) //t:vindictrg f:vindictr.c r:vindictr c:vindictr
		DRIVER(vindictre4) //t:vindictre4 f:vindictr.c r:vindictr c:vindictr
		DRIVER(vindictr4) //t:vindictr4 f:vindictr.c r:vindictr c:vindictr
		DRIVER(vindictre3) //t:vindictre3 f:vindictr.c r:vindictr c:vindictr
		DRIVER(vindictr2) //t:vindictr2 f:vindictr.c r:vindictr c:vindictr
		DRIVER(vindictr1) //t:vindictr1 f:vindictr.c r:vindictr c:vindictr
//SET: toobin
		DRIVER(toobin) //t:toobin f:toobin.c r: c:
		DRIVER(toobine) //t:toobine f:toobin.c r:toobin c:toobin
		DRIVER(toobing) //t:toobing f:toobin.c r:toobin c:toobin
		DRIVER(toobin2) //t:toobin2 f:toobin.c r:toobin c:toobin
		DRIVER(toobin2e) //t:toobin2e f:toobin.c r:toobin c:toobin
		DRIVER(toobin1) //t:toobin1 f:toobin.c r:toobin c:toobin
//SET: cyberbal
		DRIVER(cyberbal) //t:cyberbal f:cyberbal.c r: c:
		DRIVER(cyberbal2) //t:cyberbal2 f:cyberbal.c r:cyberbal c:cyberbal
		DRIVER(cyberbalp) //t:cyberbalp f:cyberbal.c r:cyberbal c:cyberbal
		DRIVER(cyberbal2p) //t:cyberbal2p f:cyberbal.c r:cyberbal c:cyberbal
		DRIVER(cyberbal2p3) //t:cyberbal2p3 f:cyberbal.c r:cyberbal c:cyberbal
		DRIVER(cyberbal2p2) //t:cyberbal2p2 f:cyberbal.c r:cyberbal c:cyberbal
		DRIVER(cyberbal2p1) //t:cyberbal2p1 f:cyberbal.c r:cyberbal c:cyberbal
		DRIVER(cyberbalt) //t:cyberbalt f:cyberbal.c r:cyberbal c:cyberbal
		DRIVER(cyberbalt1) //t:cyberbalt1 f:cyberbal.c r:cyberbal c:cyberbal
//SET: atetris
		DRIVER(atetris) //t:atetris f:atetris.c r: c:
		DRIVER(atetrisc) //t:atetrisc f:atetris.c r:atetris c:atetris
		DRIVER(atetrisc2) //t:atetrisc2 f:atetris.c r:atetris c:atetris
		DRIVER(atetrisa) //t:atetrisa f:atetris.c r:atetris c:atetris
		DRIVER(atetrisb) //t:atetrisb f:atetris.c r:atetris c:atetris
		DRIVER(atetrisb2) //t:atetrisb2 f:atetris.c r:atetris c:atetris
//SET: eprom
		DRIVER(eprom) //t:eprom f:eprom.c r: c:
		DRIVER(eprom2) //t:eprom2 f:eprom.c r:eprom c:eprom
//SET: guts
		DRIVER(guts) //t:guts f:eprom.c r: c:
//SET: skullxbo
		DRIVER(skullxbo) //t:skullxbo f:skullxbo.c r: c:
		DRIVER(skullxbo4) //t:skullxbo4 f:skullxbo.c r:skullxbo c:skullxbo
		DRIVER(skullxbo3) //t:skullxbo3 f:skullxbo.c r:skullxbo c:skullxbo
		DRIVER(skullxbo2) //t:skullxbo2 f:skullxbo.c r:skullxbo c:skullxbo
		DRIVER(skullxbo1) //t:skullxbo1 f:skullxbo.c r:skullxbo c:skullxbo
//SET: badlands
		DRIVER(badlands) //t:badlands f:badlands.c r: c:
		DRIVER(badlandsb) //t:badlandsb f:badlands.c r:badlands c:badlands
//SET: klax
		DRIVER(klax) //t:klax f:klax.c r: c:
		DRIVER(klax2) //t:klax2 f:klax.c r:klax c:klax
		DRIVER(klax3) //t:klax3 f:klax.c r:klax c:klax
		DRIVER(klaxj) //t:klaxj f:klax.c r:klax c:klax
		DRIVER(klaxd) //t:klaxd f:klax.c r:klax c:klax
		DRIVER(klaxp1) //t:klaxp1 f:eprom.c r:klax c:klax
		DRIVER(klaxp2) //t:klaxp2 f:eprom.c r:klax c:klax
//SET: thunderj
		DRIVER(thunderj) //t:thunderj f:thunderj.c r: c:
//SET: hydra
		DRIVER(hydra) //t:hydra f:atarig1.c r: c:
		DRIVER(hydrap) //t:hydrap f:atarig1.c r:hydra c:hydra
		DRIVER(hydrap2) //t:hydrap2 f:atarig1.c r:hydra c:hydra
//SET: pitfight
		DRIVER(pitfight) //t:pitfight f:atarig1.c r: c:
		DRIVER(pitfight7) //t:pitfight7 f:atarig1.c r:pitfight c:pitfight
		DRIVER(pitfight6) //t:pitfight6 f:atarig1.c r:pitfight c:pitfight
		DRIVER(pitfight5) //t:pitfight5 f:atarig1.c r:pitfight c:pitfight
		DRIVER(pitfight4) //t:pitfight4 f:atarig1.c r:pitfight c:pitfight
		DRIVER(pitfight3) //t:pitfight3 f:atarig1.c r:pitfight c:pitfight
		DRIVER(pitfightj) //t:pitfightj f:atarig1.c r:pitfight c:pitfight
		DRIVER(pitfightb) //t:pitfightb f:atarig1.c r:pitfight c:pitfight
//SET: rampart
		DRIVER(rampart) //t:rampart f:rampart.c r: c:
		DRIVER(rampart2p) //t:rampart2p f:rampart.c r:rampart c:rampart
		DRIVER(rampartj) //t:rampartj f:rampart.c r:rampart c:rampart
//SET: shuuz
		DRIVER(shuuz) //t:shuuz f:shuuz.c r: c:
		DRIVER(shuuz2) //t:shuuz2 f:shuuz.c r:shuuz c:shuuz
//SET: batman
		DRIVER(batman) //t:batman f:batman.c r: c:
//SET: roadriot
		DRIVER(roadriot) //t:roadriot f:atarig42.c r: c:
		DRIVER(roadrioto) //t:roadrioto f:atarig42.c r:roadriot c:roadriot
//SET: offtwall
		DRIVER(offtwall) //t:offtwall f:offtwall.c r: c:
		DRIVER(offtwallc) //t:offtwallc f:offtwall.c r:offtwall c:offtwall
//SET: guardian
		DRIVER(guardian) //t:guardian f:atarig42.c r: c:
//SET: relief
		DRIVER(relief) //t:relief f:relief.c r: c:
		DRIVER(relief2) //t:relief2 f:relief.c r:relief c:relief
		DRIVER(relief3) //t:relief3 f:relief.c r:relief c:relief
//SET: arcadecl
		DRIVER(arcadecl) //t:arcadecl f:arcadecl.c r: c:
//SET: sparkz
		DRIVER(sparkz) //t:sparkz f:arcadecl.c r: c:
//SET: motofren
		DRIVER(motofren) //t:motofren f:atarigx2.c r: c:
		DRIVER(motofrenmd) //t:motofrenmd f:atarigx2.c r:motofren c:motofren
		DRIVER(motofrenft) //t:motofrenft f:atarigx2.c r:motofren c:motofren
		DRIVER(motofrenmf) //t:motofrenmf f:atarigx2.c r:motofren c:motofren
//SET: spclords
		DRIVER(spclords) //t:spclords f:atarigx2.c r: c:
		DRIVER(spclordsb) //t:spclordsb f:atarigx2.c r:spclords c:spclords
		DRIVER(spclordsa) //t:spclordsa f:atarigx2.c r:spclords c:spclords
		DRIVER(spclordsg) //t:spclordsg f:atarigx2.c r:spclords c:spclords
//SET: rrreveng
		DRIVER(rrreveng) //t:rrreveng f:atarigx2.c r: c:
		DRIVER(rrrevenga) //t:rrrevenga f:atarigx2.c r:rrreveng c:rrreveng
		DRIVER(rrrevengb) //t:rrrevengb f:atarigx2.c r:rrreveng c:rrreveng
//SET: beathead
		DRIVER(beathead) //t:beathead f:beathead.c r: c:
//SET: tmek
		DRIVER(tmek) //t:tmek f:atarigt.c r: c:
		DRIVER(tmek51p) //t:tmek51p f:atarigt.c r:tmek c:tmek
		DRIVER(tmek45) //t:tmek45 f:atarigt.c r:tmek c:tmek
		DRIVER(tmek44) //t:tmek44 f:atarigt.c r:tmek c:tmek
		DRIVER(tmek20) //t:tmek20 f:atarigt.c r:tmek c:tmek
//SET: primrage
		DRIVER(primrage) //t:primrage f:atarigt.c r: c:
		DRIVER(primrage20) //t:primrage20 f:atarigt.c r:primrage c:primrage
//SET: metalmx
		DRIVER(metalmx) //t:metalmx f:metalmx.c r: c:
//SET: area51
		DRIVER(area51) //t:area51 f:cojag.c r: c:
		DRIVER(area51t) //t:area51t f:cojag.c r:area51 c:area51
		DRIVER(area51a) //t:area51a f:cojag.c r:area51 c:area51
//SET: fishfren
		DRIVER(fishfren) //t:fishfren f:cojag.c r: c:
//SET: freezeat
		DRIVER(freezeat) //t:freezeat f:cojag.c r: c:
		DRIVER(freezeatjp) //t:freezeatjp f:cojag.c r:freezeat c:freezeat
		DRIVER(freezeat2) //t:freezeat2 f:cojag.c r:freezeat c:freezeat
		DRIVER(freezeat3) //t:freezeat3 f:cojag.c r:freezeat c:freezeat
		DRIVER(freezeat4) //t:freezeat4 f:cojag.c r:freezeat c:freezeat
		DRIVER(freezeat5) //t:freezeat5 f:cojag.c r:freezeat c:freezeat
		DRIVER(freezeat6) //t:freezeat6 f:cojag.c r:freezeat c:freezeat
//SET: area51mx
		DRIVER(area51mx) //t:area51mx f:cojag.c r: c:
		DRIVER(a51mxr3k) //t:a51mxr3k f:cojag.c r:area51mx c:area51mx
//SET: maxforce
		DRIVER(maxforce) //t:maxforce f:cojag.c r: c:
		DRIVER(maxf_102) //t:maxf_102 f:cojag.c r:maxforce c:maxforce
		DRIVER(maxf_ng) //t:maxf_ng f:cojag.c r:maxforce c:maxforce
//SET: vcircle
		DRIVER(vcircle) //t:vcircle f:cojag.c r: c:
//SET: a51site4
		DRIVER(a51site4) //t:a51site4 f:mediagx.c r: c:
//SET: sasuke
		DRIVER(sasuke) //t:sasuke f:snk6502.c r: c:
//SET: satansat
		DRIVER(satansat) //t:satansat f:snk6502.c r: c:
		DRIVER(satansata) //t:satansata f:snk6502.c r:satansat c:satansat
		DRIVER(zarzon) //t:zarzon f:snk6502.c r:satansat c:satansat
//SET: vanguard
		DRIVER(vanguard) //t:vanguard f:snk6502.c r: c:
		DRIVER(vanguardc) //t:vanguardc f:snk6502.c r:vanguard c:vanguard
		DRIVER(vanguardj) //t:vanguardj f:snk6502.c r:vanguard c:vanguard
//SET: fantasy
		DRIVER(fantasy) //t:fantasy f:snk6502.c r: c:
		DRIVER(fantasyu) //t:fantasyu f:snk6502.c r:fantasy c:fantasy
		DRIVER(fantasyj) //t:fantasyj f:snk6502.c r:fantasy c:fantasy
//SET: pballoon
		DRIVER(pballoon) //t:pballoon f:snk6502.c r: c:
		DRIVER(pballoonr) //t:pballoonr f:snk6502.c r:pballoon c:pballoon
//SET: nibbler
		DRIVER(nibbler) //t:nibbler f:snk6502.c r: c:
		DRIVER(nibblera) //t:nibblera f:snk6502.c r:nibbler c:nibbler
		DRIVER(nibblerb) //t:nibblerb f:snk6502.c r:nibbler c:nibbler
		DRIVER(nibblero) //t:nibblero f:snk6502.c r:nibbler c:nibbler
//SET: lasso
		DRIVER(lasso) //t:lasso f:lasso.c r: c:
//SET: chameleo
		DRIVER(chameleo) //t:chameleo f:lasso.c r: c:
//SET: wwjgtin
		DRIVER(wwjgtin) //t:wwjgtin f:lasso.c r: c:
		DRIVER(photof) //t:photof f:lasso.c r:wwjgtin c:wwjgtin
//SET: pinbo
		DRIVER(pinbo) //t:pinbo f:lasso.c r: c:
		DRIVER(pinboa) //t:pinboa f:lasso.c r:pinbo c:pinbo
		DRIVER(pinbos) //t:pinbos f:lasso.c r:pinbo c:pinbo
//SET: joyfulr
		DRIVER(joyfulr) //t:joyfulr f:munchmo.c r: c:
		DRIVER(mnchmobl) //t:mnchmobl f:munchmo.c r:joyfulr c:joyfulr
//SET: marvins
		DRIVER(marvins) //t:marvins f:snk.c r: c:
//SET: madcrash
		DRIVER(madcrash) //t:madcrash f:snk.c r: c:
		DRIVER(madcrush) //t:madcrush f:snk.c r:madcrash c:madcrash
//SET: vangrd2
		DRIVER(vangrd2) //t:vangrd2 f:snk.c r: c:
//SET: mainsnk
		DRIVER(mainsnk) //t:mainsnk f:mainsnk.c r: c:
//SET: canvas
		DRIVER(canvas) //t:canvas f:mainsnk.c r: c:
//SET: jcross
		DRIVER(jcross) //t:jcross f:snk.c r: c:
//SET: sgladiat
		DRIVER(sgladiat) //t:sgladiat f:snk.c r: c:
//SET: hal21
		DRIVER(hal21) //t:hal21 f:snk.c r: c:
		DRIVER(hal21j) //t:hal21j f:snk.c r:hal21 c:hal21
//SET: aso
		DRIVER(aso) //t:aso f:snk.c r: c:
		DRIVER(alphamis) //t:alphamis f:snk.c r:aso c:aso
		DRIVER(arian) //t:arian f:snk.c r:aso c:aso
//SET: tnk3
		DRIVER(tnk3) //t:tnk3 f:snk.c r: c:
		DRIVER(tnk3j) //t:tnk3j f:snk.c r:tnk3 c:tnk3
//SET: athena
		DRIVER(athena) //t:athena f:snk.c r: c:
//SET: fitegolf
		DRIVER(fitegolf) //t:fitegolf f:snk.c r: c:
		DRIVER(fitegolfu) //t:fitegolfu f:snk.c r:fitegolf c:fitegolf
//SET: countryc
		DRIVER(countryc) //t:countryc f:snk.c r: c:
//SET: ikari
		DRIVER(ikari) //t:ikari f:snk.c r: c:
		DRIVER(ikaria) //t:ikaria f:snk.c r:ikari c:ikari
		DRIVER(ikarinc) //t:ikarinc f:snk.c r:ikari c:ikari
		DRIVER(ikarijp) //t:ikarijp f:snk.c r:ikari c:ikari
		DRIVER(ikarijpb) //t:ikarijpb f:snk.c r:ikari c:ikari
//SET: victroad
		DRIVER(victroad) //t:victroad f:snk.c r: c:
		DRIVER(dogosoke) //t:dogosoke f:snk.c r:victroad c:victroad
		DRIVER(dogosokb) //t:dogosokb f:snk.c r:victroad c:victroad
//SET: gwar
		DRIVER(gwar) //t:gwar f:snk.c r: c:
		DRIVER(gwarj) //t:gwarj f:snk.c r:gwar c:gwar
		DRIVER(gwara) //t:gwara f:snk.c r:gwar c:gwar
		DRIVER(gwarb) //t:gwarb f:snk.c r:gwar c:gwar
//SET: bermudat
		DRIVER(bermudat) //t:bermudat f:snk.c r: c:
		DRIVER(bermudatj) //t:bermudatj f:snk.c r:bermudat c:bermudat
//SET: worldwar
		DRIVER(worldwar) //t:worldwar f:snk.c r: c:
		DRIVER(bermudata) //t:bermudata f:snk.c r:worldwar c:worldwar
//SET: psychos
		DRIVER(psychos) //t:psychos f:snk.c r: c:
		DRIVER(psychosj) //t:psychosj f:snk.c r:psychos c:psychos
//SET: chopper
		DRIVER(chopper) //t:chopper f:snk.c r: c:
		DRIVER(choppera) //t:choppera f:snk.c r:chopper c:chopper
		DRIVER(chopperb) //t:chopperb f:snk.c r:chopper c:chopper
		DRIVER(legofair) //t:legofair f:snk.c r:chopper c:chopper
//SET: fsoccer
		DRIVER(fsoccer) //t:fsoccer f:snk.c r: c:
		DRIVER(fsoccerj) //t:fsoccerj f:snk.c r:fsoccer c:fsoccer
		DRIVER(fsoccerb) //t:fsoccerb f:snk.c r:fsoccer c:fsoccer
//SET: tdfever
		DRIVER(tdfever) //t:tdfever f:snk.c r: c:
		DRIVER(tdfeverj) //t:tdfeverj f:snk.c r:tdfever c:tdfever
		DRIVER(tdfever2) //t:tdfever2 f:snk.c r:tdfever c:tdfever
//SET: ikari3
		DRIVER(ikari3) //t:ikari3 f:snk68.c r: c:
		DRIVER(ikari3nr) //t:ikari3nr f:snk68.c r:ikari3 c:ikari3
//SET: pow
		DRIVER(pow) //t:pow f:snk68.c r: c:
		DRIVER(powj) //t:powj f:snk68.c r:pow c:pow
//SET: searchar
		DRIVER(searchar) //t:searchar f:snk68.c r: c:
		DRIVER(searcharu) //t:searcharu f:snk68.c r:searchar c:searchar
		DRIVER(searcharj) //t:searcharj f:snk68.c r:searchar c:searchar
//SET: streetsm
		DRIVER(streetsm) //t:streetsm f:snk68.c r: c:
		DRIVER(streetsm1) //t:streetsm1 f:snk68.c r:streetsm c:streetsm
		DRIVER(streetsmw) //t:streetsmw f:snk68.c r:streetsm c:streetsm
		DRIVER(streetsmj) //t:streetsmj f:snk68.c r:streetsm c:streetsm
//SET: prehisle
		DRIVER(prehisle) //t:prehisle f:prehisle.c r: c:
		DRIVER(prehisleu) //t:prehisleu f:prehisle.c r:prehisle c:prehisle
		DRIVER(prehislek) //t:prehislek f:prehisle.c r:prehisle c:prehisle
		DRIVER(gensitou) //t:gensitou f:prehisle.c r:prehisle c:prehisle
//SET: mechatt
		DRIVER(mechatt) //t:mechatt f:bbusters.c r: c:
		DRIVER(mechattu) //t:mechattu f:bbusters.c r:mechatt c:mechatt
//SET: bbusters
		DRIVER(bbusters) //t:bbusters f:bbusters.c r: c:
		DRIVER(bbustersu) //t:bbustersu f:bbusters.c r:bbusters c:bbusters
//SET: dmndrby
		DRIVER(dmndrby) //t:dmndrby f:dmndrby.c r: c:
		DRIVER(dmndrbya) //t:dmndrbya f:dmndrby.c r:dmndrby c:dmndrby
//SET: neogeo
		DRIVER(neogeo) //t:neogeo f:neodrvr.c r: c:
//SET: nam1975
		DRIVER(nam1975) //t:nam1975 f:neodrvr.c r:neogeo c:
//SET: bstars
		DRIVER(bstars) //t:bstars f:neodrvr.c r:neogeo c:
		DRIVER(bstarsh) //t:bstarsh f:neodrvr.c r:bstars c:bstars
//SET: tpgolf
		DRIVER(tpgolf) //t:tpgolf f:neodrvr.c r:neogeo c:
//SET: mahretsu
		DRIVER(mahretsu) //t:mahretsu f:neodrvr.c r:neogeo c:
//SET: maglord
		DRIVER(maglord) //t:maglord f:neodrvr.c r:neogeo c:
		DRIVER(maglordh) //t:maglordh f:neodrvr.c r:maglord c:maglord
//SET: ridhero
		DRIVER(ridhero) //t:ridhero f:neodrvr.c r:neogeo c:
		DRIVER(ridheroh) //t:ridheroh f:neodrvr.c r:ridhero c:ridhero
//SET: alpham2
		DRIVER(alpham2) //t:alpham2 f:neodrvr.c r:neogeo c:
//SET: ncombat
		DRIVER(ncombat) //t:ncombat f:neodrvr.c r:neogeo c:
		DRIVER(ncombath) //t:ncombath f:neodrvr.c r:ncombat c:ncombat
//SET: cyberlip
		DRIVER(cyberlip) //t:cyberlip f:neodrvr.c r:neogeo c:
//SET: superspy
		DRIVER(superspy) //t:superspy f:neodrvr.c r:neogeo c:
//SET: mutnat
		DRIVER(mutnat) //t:mutnat f:neodrvr.c r:neogeo c:
//SET: kotm
		DRIVER(kotm) //t:kotm f:neodrvr.c r:neogeo c:
		DRIVER(kotmh) //t:kotmh f:neodrvr.c r:kotm c:kotm
//SET: sengoku
		DRIVER(sengoku) //t:sengoku f:neodrvr.c r:neogeo c:
		DRIVER(sengokuh) //t:sengokuh f:neodrvr.c r:sengoku c:sengoku
//SET: burningf
		DRIVER(burningf) //t:burningf f:neodrvr.c r:neogeo c:
		DRIVER(burningfh) //t:burningfh f:neodrvr.c r:burningf c:burningf
//SET: lbowling
		DRIVER(lbowling) //t:lbowling f:neodrvr.c r:neogeo c:
//SET: gpilots
		DRIVER(gpilots) //t:gpilots f:neodrvr.c r:neogeo c:
		DRIVER(gpilotsh) //t:gpilotsh f:neodrvr.c r:gpilots c:gpilots
//SET: joyjoy
		DRIVER(joyjoy) //t:joyjoy f:neodrvr.c r:neogeo c:
//SET: bjourney
		DRIVER(bjourney) //t:bjourney f:neodrvr.c r:neogeo c:
//SET: quizdais
		DRIVER(quizdais) //t:quizdais f:neodrvr.c r:neogeo c:
		DRIVER(quizdaisk) //t:quizdaisk f:neodrvr.c r:quizdais c:quizdais
//SET: lresort
		DRIVER(lresort) //t:lresort f:neodrvr.c r:neogeo c:
//SET: eightman
		DRIVER(eightman) //t:eightman f:neodrvr.c r:neogeo c:
//SET: minasan
		DRIVER(minasan) //t:minasan f:neodrvr.c r:neogeo c:
//SET: legendos
		DRIVER(legendos) //t:legendos f:neodrvr.c r:neogeo c:
//SET: 2020bb
		DRIVER(2020bb) //t:2020bb f:neodrvr.c r:neogeo c:
		DRIVER(2020bba) //t:2020bba f:neodrvr.c r:2020bb c:2020bb
		DRIVER(2020bbh) //t:2020bbh f:neodrvr.c r:2020bb c:2020bb
//SET: socbrawl
		DRIVER(socbrawl) //t:socbrawl f:neodrvr.c r:neogeo c:
		DRIVER(socbrawlh) //t:socbrawlh f:neodrvr.c r:socbrawl c:socbrawl
//SET: roboarmy
		DRIVER(roboarmy) //t:roboarmy f:neodrvr.c r:neogeo c:
//SET: fatfury1
		DRIVER(fatfury1) //t:fatfury1 f:neodrvr.c r:neogeo c:
//SET: fbfrenzy
		DRIVER(fbfrenzy) //t:fbfrenzy f:neodrvr.c r:neogeo c:
//SET: bakatono
		DRIVER(bakatono) //t:bakatono f:neodrvr.c r:neogeo c:
//SET: crsword
		DRIVER(crsword) //t:crsword f:neodrvr.c r:neogeo c:
//SET: trally
		DRIVER(trally) //t:trally f:neodrvr.c r:neogeo c:
//SET: kotm2
		DRIVER(kotm2) //t:kotm2 f:neodrvr.c r:neogeo c:
//SET: sengoku2
		DRIVER(sengoku2) //t:sengoku2 f:neodrvr.c r:neogeo c:
//SET: bstars2
		DRIVER(bstars2) //t:bstars2 f:neodrvr.c r:neogeo c:
//SET: quizdai2
		DRIVER(quizdai2) //t:quizdai2 f:neodrvr.c r:neogeo c:
//SET: 3countb
		DRIVER(3countb) //t:3countb f:neodrvr.c r:neogeo c:
//SET: aof
		DRIVER(aof) //t:aof f:neodrvr.c r:neogeo c:
//SET: samsho
		DRIVER(samsho) //t:samsho f:neodrvr.c r:neogeo c:
		DRIVER(samshoh) //t:samshoh f:neodrvr.c r:samsho c:samsho
//SET: tophuntr
		DRIVER(tophuntr) //t:tophuntr f:neodrvr.c r:neogeo c:
		DRIVER(tophuntrh) //t:tophuntrh f:neodrvr.c r:tophuntr c:tophuntr
//SET: fatfury2
		DRIVER(fatfury2) //t:fatfury2 f:neodrvr.c r:neogeo c:
//SET: janshin
		DRIVER(janshin) //t:janshin f:neodrvr.c r:neogeo c:
//SET: androdun
		DRIVER(androdun) //t:androdun f:neodrvr.c r:neogeo c:
//SET: ncommand
		DRIVER(ncommand) //t:ncommand f:neodrvr.c r:neogeo c:
//SET: viewpoin
		DRIVER(viewpoin) //t:viewpoin f:neodrvr.c r:neogeo c:
//SET: ssideki
		DRIVER(ssideki) //t:ssideki f:neodrvr.c r:neogeo c:
//SET: wh1
		DRIVER(wh1) //t:wh1 f:neodrvr.c r:neogeo c:
		DRIVER(wh1h) //t:wh1h f:neodrvr.c r:wh1 c:wh1
		DRIVER(wh1ha) //t:wh1ha f:neodrvr.c r:wh1 c:wh1
//SET: kof94
		DRIVER(kof94) //t:kof94 f:neodrvr.c r:neogeo c:
//SET: aof2
		DRIVER(aof2) //t:aof2 f:neodrvr.c r:neogeo c:
		DRIVER(aof2a) //t:aof2a f:neodrvr.c r:aof2 c:aof2
//SET: wh2
		DRIVER(wh2) //t:wh2 f:neodrvr.c r:neogeo c:
//SET: fatfursp
		DRIVER(fatfursp) //t:fatfursp f:neodrvr.c r:neogeo c:
		DRIVER(fatfurspa) //t:fatfurspa f:neodrvr.c r:fatfursp c:fatfursp
//SET: savagere
		DRIVER(savagere) //t:savagere f:neodrvr.c r:neogeo c:
//SET: fightfev
		DRIVER(fightfev) //t:fightfev f:neodrvr.c r:neogeo c:
		DRIVER(fightfeva) //t:fightfeva f:neodrvr.c r:fightfev c:fightfev
//SET: ssideki2
		DRIVER(ssideki2) //t:ssideki2 f:neodrvr.c r:neogeo c:
//SET: spinmast
		DRIVER(spinmast) //t:spinmast f:neodrvr.c r:neogeo c:
//SET: samsho2
		DRIVER(samsho2) //t:samsho2 f:neodrvr.c r:neogeo c:
		DRIVER(samsho2k) //t:samsho2k f:neodrvr.c r:samsho2 c:samsho2
//SET: wh2j
		DRIVER(wh2j) //t:wh2j f:neodrvr.c r:neogeo c:
//SET: wjammers
		DRIVER(wjammers) //t:wjammers f:neodrvr.c r:neogeo c:
//SET: karnovr
		DRIVER(karnovr) //t:karnovr f:neodrvr.c r:neogeo c:
//SET: gururin
		DRIVER(gururin) //t:gururin f:neodrvr.c r:neogeo c:
//SET: pspikes2
		DRIVER(pspikes2) //t:pspikes2 f:neodrvr.c r:neogeo c:
//SET: fatfury3
		DRIVER(fatfury3) //t:fatfury3 f:neodrvr.c r:neogeo c:
//SET: zupapa
		DRIVER(zupapa) //t:zupapa f:neodrvr.c r:neogeo c:
//SET: panicbom
		DRIVER(panicbom) //t:panicbom f:neodrvr.c r:neogeo c:
//SET: aodk
		DRIVER(aodk) //t:aodk f:neodrvr.c r:neogeo c:
//SET: sonicwi2
		DRIVER(sonicwi2) //t:sonicwi2 f:neodrvr.c r:neogeo c:
//SET: zedblade
		DRIVER(zedblade) //t:zedblade f:neodrvr.c r:neogeo c:
//SET: galaxyfg
		DRIVER(galaxyfg) //t:galaxyfg f:neodrvr.c r:neogeo c:
//SET: strhoop
		DRIVER(strhoop) //t:strhoop f:neodrvr.c r:neogeo c:
//SET: quizkof
		DRIVER(quizkof) //t:quizkof f:neodrvr.c r:neogeo c:
		DRIVER(quizkofk) //t:quizkofk f:neodrvr.c r:quizkof c:quizkof
//SET: ssideki3
		DRIVER(ssideki3) //t:ssideki3 f:neodrvr.c r:neogeo c:
//SET: doubledr
		DRIVER(doubledr) //t:doubledr f:neodrvr.c r:neogeo c:
//SET: pbobblen
		DRIVER(pbobblen) //t:pbobblen f:neodrvr.c r:neogeo c:
		DRIVER(pbobblenb) //t:pbobblenb f:neodrvr.c r:pbobblen c:pbobblen
//SET: kof95
		DRIVER(kof95) //t:kof95 f:neodrvr.c r:neogeo c:
		DRIVER(kof95h) //t:kof95h f:neodrvr.c r:kof95 c:kof95
//SET: tws96
		DRIVER(tws96) //t:tws96 f:neodrvr.c r:neogeo c:
//SET: samsho3
		DRIVER(samsho3) //t:samsho3 f:neodrvr.c r:neogeo c:
		DRIVER(samsho3h) //t:samsho3h f:neodrvr.c r:samsho3 c:samsho3
		DRIVER(fswords) //t:fswords f:neodrvr.c r:samsho3 c:samsho3
//SET: stakwin
		DRIVER(stakwin) //t:stakwin f:neodrvr.c r:neogeo c:
//SET: pulstar
		DRIVER(pulstar) //t:pulstar f:neodrvr.c r:neogeo c:
//SET: whp
		DRIVER(whp) //t:whp f:neodrvr.c r:neogeo c:
//SET: kabukikl
		DRIVER(kabukikl) //t:kabukikl f:neodrvr.c r:neogeo c:
//SET: neobombe
		DRIVER(neobombe) //t:neobombe f:neodrvr.c r:neogeo c:
//SET: gowcaizr
		DRIVER(gowcaizr) //t:gowcaizr f:neodrvr.c r:neogeo c:
//SET: rbff1
		DRIVER(rbff1) //t:rbff1 f:neodrvr.c r:neogeo c:
		DRIVER(rbff1a) //t:rbff1a f:neodrvr.c r:rbff1 c:rbff1
//SET: aof3
		DRIVER(aof3) //t:aof3 f:neodrvr.c r:neogeo c:
		DRIVER(aof3k) //t:aof3k f:neodrvr.c r:aof3 c:aof3
//SET: sonicwi3
		DRIVER(sonicwi3) //t:sonicwi3 f:neodrvr.c r:neogeo c:
//SET: turfmast
		DRIVER(turfmast) //t:turfmast f:neodrvr.c r:neogeo c:
//SET: mslug
		DRIVER(mslug) //t:mslug f:neodrvr.c r:neogeo c:
//SET: puzzledp
		DRIVER(puzzledp) //t:puzzledp f:neodrvr.c r:neogeo c:
		DRIVER(puzzldpr) //t:puzzldpr f:neodrvr.c r:puzzledp c:puzzledp
//SET: mosyougi
		DRIVER(mosyougi) //t:mosyougi f:neodrvr.c r:neogeo c:
//SET: marukodq
		DRIVER(marukodq) //t:marukodq f:neodrvr.c r:neogeo c:
//SET: neomrdo
		DRIVER(neomrdo) //t:neomrdo f:neodrvr.c r:neogeo c:
//SET: sdodgeb
		DRIVER(sdodgeb) //t:sdodgeb f:neodrvr.c r:neogeo c:
//SET: goalx3
		DRIVER(goalx3) //t:goalx3 f:neodrvr.c r:neogeo c:
//SET: zintrckb
		DRIVER(zintrckb) //t:zintrckb f:neodrvr.c r:neogeo c:
//SET: overtop
		DRIVER(overtop) //t:overtop f:neodrvr.c r:neogeo c:
//SET: neodrift
		DRIVER(neodrift) //t:neodrift f:neodrvr.c r:neogeo c:
//SET: kof96
		DRIVER(kof96) //t:kof96 f:neodrvr.c r:neogeo c:
		DRIVER(kof96h) //t:kof96h f:neodrvr.c r:kof96 c:kof96
//SET: ssideki4
		DRIVER(ssideki4) //t:ssideki4 f:neodrvr.c r:neogeo c:
//SET: kizuna
		DRIVER(kizuna) //t:kizuna f:neodrvr.c r:neogeo c:
//SET: ninjamas
		DRIVER(ninjamas) //t:ninjamas f:neodrvr.c r:neogeo c:
//SET: ragnagrd
		DRIVER(ragnagrd) //t:ragnagrd f:neodrvr.c r:neogeo c:
//SET: pgoal
		DRIVER(pgoal) //t:pgoal f:neodrvr.c r:neogeo c:
//SET: magdrop2
		DRIVER(magdrop2) //t:magdrop2 f:neodrvr.c r:neogeo c:
//SET: samsho4
		DRIVER(samsho4) //t:samsho4 f:neodrvr.c r:neogeo c:
		DRIVER(samsho4k) //t:samsho4k f:neodrvr.c r:samsho4 c:samsho4
//SET: rbffspec
		DRIVER(rbffspec) //t:rbffspec f:neodrvr.c r:neogeo c:
		DRIVER(rbffspeck) //t:rbffspeck f:neodrvr.c r:rbffspec c:rbffspec
//SET: twinspri
		DRIVER(twinspri) //t:twinspri f:neodrvr.c r:neogeo c:
//SET: wakuwak7
		DRIVER(wakuwak7) //t:wakuwak7 f:neodrvr.c r:neogeo c:
//SET: stakwin2
		DRIVER(stakwin2) //t:stakwin2 f:neodrvr.c r:neogeo c:
//SET: ghostlop
		DRIVER(ghostlop) //t:ghostlop f:neodrvr.c r:neogeo c:
//SET: breakers
		DRIVER(breakers) //t:breakers f:neodrvr.c r:neogeo c:
//SET: miexchng
		DRIVER(miexchng) //t:miexchng f:neodrvr.c r:neogeo c:
//SET: kof97
		DRIVER(kof97) //t:kof97 f:neodrvr.c r:neogeo c:
		DRIVER(kof97h) //t:kof97h f:neodrvr.c r:kof97 c:kof97
		DRIVER(kof97pls) //t:kof97pls f:neodrvr.c r:kof97 c:kof97
		DRIVER(kog) //t:kog f:neodrvr.c r:kof97 c:kof97
//SET: magdrop3
		DRIVER(magdrop3) //t:magdrop3 f:neodrvr.c r:neogeo c:
//SET: lastblad
		DRIVER(lastblad) //t:lastblad f:neodrvr.c r:neogeo c:
		DRIVER(lastbladh) //t:lastbladh f:neodrvr.c r:lastblad c:lastblad
		DRIVER(lastsold) //t:lastsold f:neodrvr.c r:lastblad c:lastblad
//SET: irrmaze
		DRIVER(irrmaze) //t:irrmaze f:neodrvr.c r:neogeo c:
//SET: popbounc
		DRIVER(popbounc) //t:popbounc f:neodrvr.c r:neogeo c:
//SET: shocktro
		DRIVER(shocktro) //t:shocktro f:neodrvr.c r:neogeo c:
		DRIVER(shocktroa) //t:shocktroa f:neodrvr.c r:shocktro c:shocktro
//SET: blazstar
		DRIVER(blazstar) //t:blazstar f:neodrvr.c r:neogeo c:
//SET: rbff2
		DRIVER(rbff2) //t:rbff2 f:neodrvr.c r:neogeo c:
		DRIVER(rbff2h) //t:rbff2h f:neodrvr.c r:rbff2 c:rbff2
		DRIVER(rbff2k) //t:rbff2k f:neodrvr.c r:rbff2 c:rbff2
//SET: mslug2
		DRIVER(mslug2) //t:mslug2 f:neodrvr.c r:neogeo c:
//SET: kof98
		DRIVER(kof98) //t:kof98 f:neodrvr.c r:neogeo c:
		DRIVER(kof98k) //t:kof98k f:neodrvr.c r:kof98 c:kof98
		DRIVER(kof98ka) //t:kof98ka f:neodrvr.c r:kof98 c:kof98
		DRIVER(kof98h) //t:kof98h f:neodrvr.c r:kof98 c:kof98
//SET: lastbld2
		DRIVER(lastbld2) //t:lastbld2 f:neodrvr.c r:neogeo c:
//SET: neocup98
		DRIVER(neocup98) //t:neocup98 f:neodrvr.c r:neogeo c:
//SET: breakrev
		DRIVER(breakrev) //t:breakrev f:neodrvr.c r:neogeo c:
//SET: shocktr2
		DRIVER(shocktr2) //t:shocktr2 f:neodrvr.c r:neogeo c:
		DRIVER(lans2004) //t:lans2004 f:neodrvr.c r:shocktr2 c:shocktr2
//SET: flipshot
		DRIVER(flipshot) //t:flipshot f:neodrvr.c r:neogeo c:
//SET: pbobbl2n
		DRIVER(pbobbl2n) //t:pbobbl2n f:neodrvr.c r:neogeo c:
//SET: ctomaday
		DRIVER(ctomaday) //t:ctomaday f:neodrvr.c r:neogeo c:
//SET: mslugx
		DRIVER(mslugx) //t:mslugx f:neodrvr.c r:neogeo c:
//SET: kof99
		DRIVER(kof99) //t:kof99 f:neodrvr.c r:neogeo c:
		DRIVER(kof99h) //t:kof99h f:neodrvr.c r:kof99 c:kof99
		DRIVER(kof99e) //t:kof99e f:neodrvr.c r:kof99 c:kof99
		DRIVER(kof99k) //t:kof99k f:neodrvr.c r:kof99 c:kof99
		DRIVER(kof99p) //t:kof99p f:neodrvr.c r:kof99 c:kof99
//SET: ganryu
		DRIVER(ganryu) //t:ganryu f:neodrvr.c r:neogeo c:
//SET: garou
		DRIVER(garou) //t:garou f:neodrvr.c r:neogeo c:
		DRIVER(garouo) //t:garouo f:neodrvr.c r:garou c:garou
		DRIVER(garoup) //t:garoup f:neodrvr.c r:garou c:garou
		DRIVER(garoubl) //t:garoubl f:neodrvr.c r:garou c:garou
//SET: s1945p
		DRIVER(s1945p) //t:s1945p f:neodrvr.c r:neogeo c:
//SET: preisle2
		DRIVER(preisle2) //t:preisle2 f:neodrvr.c r:neogeo c:
//SET: mslug3
		DRIVER(mslug3) //t:mslug3 f:neodrvr.c r:neogeo c:
		DRIVER(mslug3h) //t:mslug3h f:neodrvr.c r:mslug3 c:mslug3
		DRIVER(mslug3b6) //t:mslug3b6 f:neodrvr.c r:mslug3 c:mslug3
//SET: kof2000
		DRIVER(kof2000) //t:kof2000 f:neodrvr.c r:neogeo c:
		DRIVER(kof2000n) //t:kof2000n f:neodrvr.c r:kof2000 c:kof2000
//SET: bangbead
		DRIVER(bangbead) //t:bangbead f:neodrvr.c r:neogeo c:
//SET: nitd
		DRIVER(nitd) //t:nitd f:neodrvr.c r:neogeo c:
		DRIVER(nitdbl) //t:nitdbl f:neodrvr.c r:nitd c:nitd
//SET: sengoku3
		DRIVER(sengoku3) //t:sengoku3 f:neodrvr.c r:neogeo c:
//SET: kof2001
		DRIVER(kof2001) //t:kof2001 f:neodrvr.c r:neogeo c:
		DRIVER(kof2001h) //t:kof2001h f:neodrvr.c r:kof2001 c:kof2001
		DRIVER(cthd2003) //t:cthd2003 f:neodrvr.c r:kof2001 c:kof2001
		DRIVER(ct2k3sp) //t:ct2k3sp f:neodrvr.c r:kof2001 c:kof2001
		DRIVER(ct2k3sa) //t:ct2k3sa f:neodrvr.c r:kof2001 c:kof2001
//SET: mslug4
		DRIVER(mslug4) //t:mslug4 f:neodrvr.c r:neogeo c:
		DRIVER(mslug4h) //t:mslug4h f:neodrvr.c r:mslug4 c:mslug4
		DRIVER(ms4plus) //t:ms4plus f:neodrvr.c r:mslug4 c:mslug4
//SET: rotd
		DRIVER(rotd) //t:rotd f:neodrvr.c r:neogeo c:
//SET: kof2002
		DRIVER(kof2002) //t:kof2002 f:neodrvr.c r:neogeo c:
		DRIVER(kof2002b) //t:kof2002b f:neodrvr.c r:kof2002 c:kof2002
		DRIVER(kf2k2pls) //t:kf2k2pls f:neodrvr.c r:kof2002 c:kof2002
		DRIVER(kf2k2pla) //t:kf2k2pla f:neodrvr.c r:kof2002 c:kof2002
		DRIVER(kf2k2mp) //t:kf2k2mp f:neodrvr.c r:kof2002 c:kof2002
		DRIVER(kf2k2mp2) //t:kf2k2mp2 f:neodrvr.c r:kof2002 c:kof2002
		DRIVER(kof10th) //t:kof10th f:neodrvr.c r:kof2002 c:kof2002
		DRIVER(kf2k5uni) //t:kf2k5uni f:neodrvr.c r:kof2002 c:kof2002
		DRIVER(kf10thep) //t:kf10thep f:neodrvr.c r:kof2002 c:kof2002
		DRIVER(kof2k4se) //t:kof2k4se f:neodrvr.c r:kof2002 c:kof2002
//SET: matrim
		DRIVER(matrim) //t:matrim f:neodrvr.c r:neogeo c:
		DRIVER(matrimbl) //t:matrimbl f:neodrvr.c r:matrim c:matrim
//SET: pnyaa
		DRIVER(pnyaa) //t:pnyaa f:neodrvr.c r:neogeo c:
//SET: ms5pcb
		DRIVER(ms5pcb) //t:ms5pcb f:neodrvr.c r: c:
//SET: mslug5
		DRIVER(mslug5) //t:mslug5 f:neodrvr.c r:neogeo c:
		DRIVER(mslug5h) //t:mslug5h f:neodrvr.c r:mslug5 c:mslug5
		DRIVER(ms5plus) //t:ms5plus f:neodrvr.c r:mslug5 c:mslug5
//SET: svcpcb
		DRIVER(svcpcb) //t:svcpcb f:neodrvr.c r: c:
		DRIVER(svcpcba) //t:svcpcba f:neodrvr.c r:svcpcb c:svcpcb
//SET: svc
		DRIVER(svc) //t:svc f:neodrvr.c r:neogeo c:
		DRIVER(svcboot) //t:svcboot f:neodrvr.c r:svc c:svc
		DRIVER(svcplus) //t:svcplus f:neodrvr.c r:svc c:svc
		DRIVER(svcplusa) //t:svcplusa f:neodrvr.c r:svc c:svc
		DRIVER(svcsplus) //t:svcsplus f:neodrvr.c r:svc c:svc
//SET: samsho5
		DRIVER(samsho5) //t:samsho5 f:neodrvr.c r:neogeo c:
		DRIVER(samsho5h) //t:samsho5h f:neodrvr.c r:samsho5 c:samsho5
		DRIVER(samsho5b) //t:samsho5b f:neodrvr.c r:samsho5 c:samsho5
//SET: kf2k3pcb
		DRIVER(kf2k3pcb) //t:kf2k3pcb f:neodrvr.c r: c:
//SET: kof2003
		DRIVER(kof2003) //t:kof2003 f:neodrvr.c r:neogeo c:
		DRIVER(kof2003h) //t:kof2003h f:neodrvr.c r:kof2003 c:kof2003
		DRIVER(kf2k3bl) //t:kf2k3bl f:neodrvr.c r:kof2003 c:kof2003
		DRIVER(kf2k3bla) //t:kf2k3bla f:neodrvr.c r:kof2003 c:kof2003
		DRIVER(kf2k3pl) //t:kf2k3pl f:neodrvr.c r:kof2003 c:kof2003
		DRIVER(kf2k3upl) //t:kf2k3upl f:neodrvr.c r:kof2003 c:kof2003
//SET: samsh5sp
		DRIVER(samsh5sp) //t:samsh5sp f:neodrvr.c r:neogeo c:
		DRIVER(samsh5sph) //t:samsh5sph f:neodrvr.c r:samsh5sp c:samsh5sp
		DRIVER(samsh5spn) //t:samsh5spn f:neodrvr.c r:samsh5sp c:samsh5sp
//SET: jockeygp
		DRIVER(jockeygp) //t:jockeygp f:neodrvr.c r:neogeo c:
		DRIVER(jockeygpa) //t:jockeygpa f:neodrvr.c r:jockeygp c:jockeygp
//SET: vliner
		DRIVER(vliner) //t:vliner f:neodrvr.c r:neogeo c:
		DRIVER(vlinero) //t:vlinero f:neodrvr.c r:vliner c:vliner
//SET: diggerma
		DRIVER(diggerma) //t:diggerma f:neodrvr.c r:neogeo c:
//SET: hng64
		DRIVER(hng64) //t:hng64 f:hng64.c r: c:
//SET: roadedge
		DRIVER(roadedge) //t:roadedge f:hng64.c r:hng64 c:
//SET: sams64
		DRIVER(sams64) //t:sams64 f:hng64.c r:hng64 c:
//SET: xrally
		DRIVER(xrally) //t:xrally f:hng64.c r:hng64 c:
//SET: bbust2
		DRIVER(bbust2) //t:bbust2 f:hng64.c r:hng64 c:
//SET: sams64_2
		DRIVER(sams64_2) //t:sams64_2 f:hng64.c r:hng64 c:
//SET: fatfurwa
		DRIVER(fatfurwa) //t:fatfurwa f:hng64.c r:hng64 c:
//SET: buriki
		DRIVER(buriki) //t:buriki f:hng64.c r:hng64 c:
//SET: npcartv1
		DRIVER(npcartv1) //t:npcartv1 f:neoprint.c r: c:
//SET: 98best44
		DRIVER(98best44) //t:98best44 f:neoprint.c r: c:
//SET: nprsp
		DRIVER(nprsp) //t:nprsp f:neoprint.c r: c:
//SET: shougi
		DRIVER(shougi) //t:shougi f:shougi.c r: c:
		DRIVER(shougi2) //t:shougi2 f:shougi.c r:shougi c:shougi
//SET: champbas
		DRIVER(champbas) //t:champbas f:champbas.c r: c:
		DRIVER(champbasj) //t:champbasj f:champbas.c r:champbas c:champbas
		DRIVER(champbasja) //t:champbasja f:champbas.c r:champbas c:champbas
//SET: champbb2
		DRIVER(champbb2) //t:champbb2 f:champbas.c r: c:
		DRIVER(champbb2a) //t:champbb2a f:champbas.c r:champbb2 c:champbb2
		DRIVER(champbb2j) //t:champbb2j f:champbas.c r:champbb2 c:champbb2
//SET: exctsccr
		DRIVER(exctsccr) //t:exctsccr f:champbas.c r: c:
		DRIVER(exctsccra) //t:exctsccra f:champbas.c r:exctsccr c:exctsccr
		DRIVER(exctsccrj) //t:exctsccrj f:champbas.c r:exctsccr c:exctsccr
		DRIVER(exctsccrj2) //t:exctsccrj2 f:champbas.c r:exctsccr c:exctsccr
		DRIVER(exctsccrb) //t:exctsccrb f:champbas.c r:exctsccr c:exctsccr
//SET: exctscc2
		DRIVER(exctscc2) //t:exctscc2 f:champbas.c r: c:
//SET: talbot
		DRIVER(talbot) //t:talbot f:champbas.c r: c:
//SET: equites
		DRIVER(equites) //t:equites f:equites.c r: c:
		DRIVER(equitess) //t:equitess f:equites.c r:equites c:equites
//SET: gekisou
		DRIVER(gekisou) //t:gekisou f:equites.c r: c:
//SET: bullfgtr
		DRIVER(bullfgtr) //t:bullfgtr f:equites.c r: c:
		DRIVER(bullfgtrs) //t:bullfgtrs f:equites.c r:bullfgtr c:bullfgtr
//SET: kouyakyu
		DRIVER(kouyakyu) //t:kouyakyu f:equites.c r: c:
//SET: splndrbt
		DRIVER(splndrbt) //t:splndrbt f:equites.c r: c:
//SET: hvoltage
		DRIVER(hvoltage) //t:hvoltage f:equites.c r: c:
//SET: sstingry
		DRIVER(sstingry) //t:sstingry f:alpha68k.c r: c:
//SET: kyros
		DRIVER(kyros) //t:kyros f:alpha68k.c r: c:
		DRIVER(kyrosj) //t:kyrosj f:alpha68k.c r:kyros c:kyros
//SET: jongbou
		DRIVER(jongbou) //t:jongbou f:alpha68k.c r: c:
//SET: paddlema
		DRIVER(paddlema) //t:paddlema f:alpha68k.c r: c:
//SET: timesold
		DRIVER(timesold) //t:timesold f:alpha68k.c r: c:
		DRIVER(timesold1) //t:timesold1 f:alpha68k.c r:timesold c:timesold
		DRIVER(btlfield) //t:btlfield f:alpha68k.c r:timesold c:timesold
		DRIVER(btlfieldb) //t:btlfieldb f:alpha68k.c r:timesold c:timesold
//SET: skysoldr
		DRIVER(skysoldr) //t:skysoldr f:alpha68k.c r: c:
//SET: goldmedl
		DRIVER(goldmedl) //t:goldmedl f:alpha68k.c r: c:
		DRIVER(goldmedla) //t:goldmedla f:alpha68k.c r:goldmedl c:goldmedl
		DRIVER(goldmedlb) //t:goldmedlb f:alpha68k.c r:goldmedl c:goldmedl
//SET: skyadvnt
		DRIVER(skyadvnt) //t:skyadvnt f:alpha68k.c r: c:
		DRIVER(skyadvntu) //t:skyadvntu f:alpha68k.c r:skyadvnt c:skyadvnt
		DRIVER(skyadvntj) //t:skyadvntj f:alpha68k.c r:skyadvnt c:skyadvnt
//SET: gangwars
		DRIVER(gangwars) //t:gangwars f:alpha68k.c r: c:
		DRIVER(gangwarsu) //t:gangwarsu f:alpha68k.c r:gangwars c:gangwars
//SET: sbasebal
		DRIVER(sbasebal) //t:sbasebal f:alpha68k.c r: c:
//SET: tnextspc
		DRIVER(tnextspc) //t:tnextspc f:alpha68k.c r: c:
		DRIVER(tnextspcj) //t:tnextspcj f:alpha68k.c r:tnextspc c:tnextspc
//SET: meijinsn
		DRIVER(meijinsn) //t:meijinsn f:meijinsn.c r: c:
//SET: scregg
		DRIVER(scregg) //t:scregg f:scregg.c r: c:
		DRIVER(eggs) //t:eggs f:scregg.c r:scregg c:scregg
//SET: dommy
		DRIVER(dommy) //t:dommy f:scregg.c r: c:
//SET: bigprowr
		DRIVER(bigprowr) //t:bigprowr f:tagteam.c r: c:
		DRIVER(tagteam) //t:tagteam f:tagteam.c r:bigprowr c:bigprowr
//SET: ssozumo
		DRIVER(ssozumo) //t:ssozumo f:ssozumo.c r: c:
//SET: mystston
		DRIVER(mystston) //t:mystston f:mystston.c r: c:
		DRIVER(myststono) //t:myststono f:mystston.c r:mystston c:mystston
//SET: dogfgt
		DRIVER(dogfgt) //t:dogfgt f:dogfgt.c r: c:
		DRIVER(dogfgtu) //t:dogfgtu f:dogfgt.c r:dogfgt c:dogfgt
		DRIVER(dogfgtj) //t:dogfgtj f:dogfgt.c r:dogfgt c:dogfgt
//SET: bogeyman
		DRIVER(bogeyman) //t:bogeyman f:bogeyman.c r: c:
//SET: matmania
		DRIVER(matmania) //t:matmania f:matmania.c r: c:
		DRIVER(excthour) //t:excthour f:matmania.c r:matmania c:matmania
//SET: maniach
		DRIVER(maniach) //t:maniach f:matmania.c r: c:
		DRIVER(maniach2) //t:maniach2 f:matmania.c r:maniach c:maniach
//SET: renegade
		DRIVER(renegade) //t:renegade f:renegade.c r: c:
		DRIVER(kuniokun) //t:kuniokun f:renegade.c r:renegade c:renegade
		DRIVER(kuniokunb) //t:kuniokunb f:renegade.c r:renegade c:renegade
//SET: xsleena
		DRIVER(xsleena) //t:xsleena f:xain.c r: c:
		DRIVER(xsleenab) //t:xsleenab f:xain.c r:xsleena c:xsleena
		DRIVER(solarwar) //t:solarwar f:xain.c r:xsleena c:xsleena
//SET: battlane
		DRIVER(battlane) //t:battlane f:battlane.c r: c:
		DRIVER(battlane2) //t:battlane2 f:battlane.c r:battlane c:battlane
		DRIVER(battlane3) //t:battlane3 f:battlane.c r:battlane c:battlane
//SET: ddragon
		DRIVER(ddragon) //t:ddragon f:ddragon.c r: c:
		DRIVER(ddragonu) //t:ddragonu f:ddragon.c r:ddragon c:ddragon
		DRIVER(ddragonua) //t:ddragonua f:ddragon.c r:ddragon c:ddragon
		DRIVER(ddragonub) //t:ddragonub f:ddragon.c r:ddragon c:ddragon
		DRIVER(ddragonw) //t:ddragonw f:ddragon.c r:ddragon c:ddragon
		DRIVER(ddragonw1) //t:ddragonw1 f:ddragon.c r:ddragon c:ddragon
		DRIVER(ddragonb) //t:ddragonb f:ddragon.c r:ddragon c:ddragon
		DRIVER(ddragonba) //t:ddragonba f:ddragon.c r:ddragon c:ddragon
		DRIVER(ddragon6809) //t:ddragon6809 f:ddragon.c r:ddragon c:ddragon
		DRIVER(ddragon6809a) //t:ddragon6809a f:ddragon.c r:ddragon c:ddragon
		DRIVER(ddragonb2) //t:ddragonb2 f:ddragon.c r:ddragon c:ddragon
//SET: spdodgeb
		DRIVER(spdodgeb) //t:spdodgeb f:spdodgeb.c r: c:
		DRIVER(nkdodge) //t:nkdodge f:spdodgeb.c r:spdodgeb c:spdodgeb
		DRIVER(nkdodgeb) //t:nkdodgeb f:spdodgeb.c r:spdodgeb c:spdodgeb
//SET: chinagat
		DRIVER(chinagat) //t:chinagat f:chinagat.c r: c:
		DRIVER(saiyugou) //t:saiyugou f:chinagat.c r:chinagat c:chinagat
		DRIVER(saiyugoub1) //t:saiyugoub1 f:chinagat.c r:chinagat c:chinagat
		DRIVER(saiyugoub2) //t:saiyugoub2 f:chinagat.c r:chinagat c:chinagat
//SET: wwfsstar
		DRIVER(wwfsstar) //t:wwfsstar f:wwfsstar.c r: c:
		DRIVER(wwfsstara) //t:wwfsstara f:wwfsstar.c r:wwfsstar c:wwfsstar
		DRIVER(wwfsstaru) //t:wwfsstaru f:wwfsstar.c r:wwfsstar c:wwfsstar
		DRIVER(wwfsstarj) //t:wwfsstarj f:wwfsstar.c r:wwfsstar c:wwfsstar
//SET: vball
		DRIVER(vball) //t:vball f:vball.c r: c:
		DRIVER(vball2pj) //t:vball2pj f:vball.c r:vball c:vball
		DRIVER(vballb) //t:vballb f:vball.c r:vball c:vball
//SET: ddragon2
		DRIVER(ddragon2) //t:ddragon2 f:ddragon.c r: c:
		DRIVER(ddragon2u) //t:ddragon2u f:ddragon.c r:ddragon2 c:ddragon2
//SET: toffy
		DRIVER(toffy) //t:toffy f:ddragon.c r: c:
//SET: stoffy
		DRIVER(stoffy) //t:stoffy f:ddragon.c r: c:
//SET: ddungeon
		DRIVER(ddungeon) //t:ddungeon f:ddragon.c r: c:
		DRIVER(ddungeone) //t:ddungeone f:ddragon.c r:ddungeon c:ddungeon
//SET: darktowr
		DRIVER(darktowr) //t:darktowr f:ddragon.c r: c:
//SET: tstrike
		DRIVER(tstrike) //t:tstrike f:ddragon.c r: c:
		DRIVER(tstrikea) //t:tstrikea f:ddragon.c r:tstrike c:tstrike
//SET: ctribe
		DRIVER(ctribe) //t:ctribe f:ddragon3.c r: c:
		DRIVER(ctribe1) //t:ctribe1 f:ddragon3.c r:ctribe c:ctribe
		DRIVER(ctribej) //t:ctribej f:ddragon3.c r:ctribe c:ctribe
		DRIVER(ctribeb) //t:ctribeb f:ddragon3.c r:ctribe c:ctribe
		DRIVER(ctribeb2) //t:ctribeb2 f:ddragon3.c r:ctribe c:ctribe
//SET: blockout
		DRIVER(blockout) //t:blockout f:blockout.c r: c:
		DRIVER(blockout2) //t:blockout2 f:blockout.c r:blockout c:blockout
		DRIVER(blockoutj) //t:blockoutj f:blockout.c r:blockout c:blockout
//SET: agress
		DRIVER(agress) //t:agress f:blockout.c r: c:
		DRIVER(agressb) //t:agressb f:blockout.c r:agress c:agress
//SET: ddragon3
		DRIVER(ddragon3) //t:ddragon3 f:ddragon3.c r: c:
		DRIVER(ddragon3p) //t:ddragon3p f:ddragon3.c r:ddragon3 c:ddragon3
		DRIVER(ddragon3j) //t:ddragon3j f:ddragon3.c r:ddragon3 c:ddragon3
		DRIVER(ddragon3b) //t:ddragon3b f:ddragon3.c r:ddragon3 c:ddragon3
//SET: wwfwfest
		DRIVER(wwfwfest) //t:wwfwfest f:wwfwfest.c r: c:
		DRIVER(wwfwfesta) //t:wwfwfesta f:wwfwfest.c r:wwfwfest c:wwfwfest
		DRIVER(wwfwfestb) //t:wwfwfestb f:wwfwfest.c r:wwfwfest c:wwfwfest
		DRIVER(wwfwfestj) //t:wwfwfestj f:wwfwfest.c r:wwfwfest c:wwfwfest
//SET: shadfrce
		DRIVER(shadfrce) //t:shadfrce f:shadfrce.c r: c:
		DRIVER(shadfrcej) //t:shadfrcej f:shadfrce.c r:shadfrce c:shadfrce
		DRIVER(shadfrcejv2) //t:shadfrcejv2 f:shadfrce.c r:shadfrce c:shadfrce
//SET: berzerk
		DRIVER(berzerk) //t:berzerk f:berzerk.c r: c:
		DRIVER(berzerk1) //t:berzerk1 f:berzerk.c r:berzerk c:berzerk
		DRIVER(berzerkg) //t:berzerkg f:berzerk.c r:berzerk c:berzerk
//SET: frenzy
		DRIVER(frenzy) //t:frenzy f:berzerk.c r: c:
//SET: moonwarp
		DRIVER(moonwarp) //t:moonwarp f:berzerk.c r: c:
//SET: mazerbla
		DRIVER(mazerbla) //t:mazerbla f:mazerbla.c r: c:
		DRIVER(mazerblaa) //t:mazerblaa f:mazerbla.c r:mazerbla c:mazerbla
//SET: greatgun
		DRIVER(greatgun) //t:greatgun f:mazerbla.c r: c:
//SET: cliffhgr
		DRIVER(cliffhgr) //t:cliffhgr f:cliffhgr.c r: c:
		DRIVER(cliffhgra) //t:cliffhgra f:cliffhgr.c r:cliffhgr c:cliffhgr
//SET: goaltogo
		DRIVER(goaltogo) //t:goaltogo f:cliffhgr.c r: c:
//SET: toratora
		DRIVER(toratora) //t:toratora f:toratora.c r: c:
//SET: megatack
		DRIVER(megatack) //t:megatack f:gameplan.c r: c:
//SET: killcom
		DRIVER(killcom) //t:killcom f:gameplan.c r: c:
//SET: challeng
		DRIVER(challeng) //t:challeng f:gameplan.c r: c:
//SET: kaos
		DRIVER(kaos) //t:kaos f:gameplan.c r: c:
//SET: sia2650
		DRIVER(sia2650) //t:sia2650 f:zac2650.c r: c:
		DRIVER(tinv2650) //t:tinv2650 f:zac2650.c r:sia2650 c:sia2650
//SET: dodgem
		DRIVER(dodgem) //t:dodgem f:zac2650.c r: c:
//SET: galaxia
		DRIVER(galaxia) //t:galaxia f:galaxia.c r: c:
//SET: astrowar
		DRIVER(astrowar) //t:astrowar f:galaxia.c r: c:
//SET: laserbat
		DRIVER(laserbat) //t:laserbat f:laserbat.c r: c:
		DRIVER(lazarian) //t:lazarian f:laserbat.c r:laserbat c:laserbat
//SET: catnmous
		DRIVER(catnmous) //t:catnmous f:laserbat.c r: c:
		DRIVER(catnmousa) //t:catnmousa f:laserbat.c r:catnmous c:catnmous
//SET: monymony
		DRIVER(monymony) //t:monymony f:zaccaria.c r: c:
//SET: jackrabt
		DRIVER(jackrabt) //t:jackrabt f:zaccaria.c r: c:
		DRIVER(jackrabt2) //t:jackrabt2 f:zaccaria.c r:jackrabt c:jackrabt
		DRIVER(jackrabts) //t:jackrabts f:zaccaria.c r:jackrabt c:jackrabt
//SET: mouser
		DRIVER(mouser) //t:mouser f:mouser.c r: c:
		DRIVER(mouserc) //t:mouserc f:mouser.c r:mouser c:mouser
//SET: nova2001
		DRIVER(nova2001) //t:nova2001 f:nova2001.c r: c:
		DRIVER(nova2001u) //t:nova2001u f:nova2001.c r:nova2001 c:nova2001
//SET: ninjakun
		DRIVER(ninjakun) //t:ninjakun f:nova2001.c r: c:
//SET: raiders5
		DRIVER(raiders5) //t:raiders5 f:nova2001.c r: c:
		DRIVER(raiders5t) //t:raiders5t f:nova2001.c r:raiders5 c:raiders5
//SET: pkunwar
		DRIVER(pkunwar) //t:pkunwar f:nova2001.c r: c:
		DRIVER(pkunwarj) //t:pkunwarj f:nova2001.c r:pkunwar c:pkunwar
//SET: xxmissio
		DRIVER(xxmissio) //t:xxmissio f:xxmissio.c r: c:
//SET: ninjakd2
		DRIVER(ninjakd2) //t:ninjakd2 f:ninjakd2.c r: c:
		DRIVER(ninjakd2a) //t:ninjakd2a f:ninjakd2.c r:ninjakd2 c:ninjakd2
		DRIVER(ninjakd2b) //t:ninjakd2b f:ninjakd2.c r:ninjakd2 c:ninjakd2
		DRIVER(rdaction) //t:rdaction f:ninjakd2.c r:ninjakd2 c:ninjakd2
//SET: mnight
		DRIVER(mnight) //t:mnight f:ninjakd2.c r: c:
//SET: arkarea
		DRIVER(arkarea) //t:arkarea f:ninjakd2.c r: c:
//SET: robokid
		DRIVER(robokid) //t:robokid f:ninjakd2.c r: c:
		DRIVER(robokidj) //t:robokidj f:ninjakd2.c r:robokid c:robokid
		DRIVER(robokidj2) //t:robokidj2 f:ninjakd2.c r:robokid c:robokid
//SET: omegaf
		DRIVER(omegaf) //t:omegaf f:ninjakd2.c r: c:
		DRIVER(omegafs) //t:omegafs f:ninjakd2.c r:omegaf c:omegaf
//SET: urashima
		DRIVER(urashima) //t:urashima f:jalmah.c r: c:
//SET: tharrier
		DRIVER(tharrier) //t:tharrier f:nmk16.c r: c:
		DRIVER(tharrierj) //t:tharrierj f:nmk16.c r:tharrier c:tharrier
//SET: mustang
		DRIVER(mustang) //t:mustang f:nmk16.c r: c:
		DRIVER(mustangs) //t:mustangs f:nmk16.c r:mustang c:mustang
		DRIVER(mustangb) //t:mustangb f:nmk16.c r:mustang c:mustang
		DRIVER(mustangb2) //t:mustangb2 f:nmk16.c r:mustang c:mustang
//SET: bioship
		DRIVER(bioship) //t:bioship f:nmk16.c r: c:
		DRIVER(sbsgomo) //t:sbsgomo f:nmk16.c r:bioship c:bioship
//SET: vandyke
		DRIVER(vandyke) //t:vandyke f:nmk16.c r: c:
		DRIVER(vandykejal) //t:vandykejal f:nmk16.c r:vandyke c:vandyke
		DRIVER(vandykejal2) //t:vandykejal2 f:nmk16.c r:vandyke c:vandyke
		DRIVER(vandykeb) //t:vandykeb f:nmk16.c r:vandyke c:vandyke
//SET: blkheart
		DRIVER(blkheart) //t:blkheart f:nmk16.c r: c:
		DRIVER(blkheartj) //t:blkheartj f:nmk16.c r:blkheart c:blkheart
//SET: acrobatm
		DRIVER(acrobatm) //t:acrobatm f:nmk16.c r: c:
//SET: strahl
		DRIVER(strahl) //t:strahl f:nmk16.c r: c:
		DRIVER(strahla) //t:strahla f:nmk16.c r:strahl c:strahl
//SET: bjtwin
		DRIVER(bjtwin) //t:bjtwin f:nmk16.c r: c:
		DRIVER(bjtwina) //t:bjtwina f:nmk16.c r:bjtwin c:bjtwin
		DRIVER(bjtwinp) //t:bjtwinp f:nmk16.c r:bjtwin c:bjtwin
//SET: tdragon2
		DRIVER(tdragon2) //t:tdragon2 f:nmk16.c r: c:
		DRIVER(tdragon2a) //t:tdragon2a f:nmk16.c r:tdragon2 c:tdragon2
		DRIVER(bigbang) //t:bigbang f:nmk16.c r:tdragon2 c:tdragon2
//SET: tdragon
		DRIVER(tdragon) //t:tdragon f:nmk16.c r: c:
		DRIVER(tdragon1) //t:tdragon1 f:nmk16.c r:tdragon c:tdragon
		DRIVER(tdragonb) //t:tdragonb f:nmk16.c r:tdragon c:tdragon
//SET: hachamf
		DRIVER(hachamf) //t:hachamf f:nmk16.c r: c:
//SET: macross
		DRIVER(macross) //t:macross f:nmk16.c r: c:
//SET: riot
		DRIVER(riot) //t:riot f:tecmo16.c r: c:
//SET: gunnail
		DRIVER(gunnail) //t:gunnail f:nmk16.c r: c:
//SET: macross2
		DRIVER(macross2) //t:macross2 f:nmk16.c r: c:
//SET: sabotenb
		DRIVER(sabotenb) //t:sabotenb f:nmk16.c r: c:
		DRIVER(sabotenba) //t:sabotenba f:nmk16.c r:sabotenb c:sabotenb
		DRIVER(cactus) //t:cactus f:nmk16.c r:sabotenb c:sabotenb
//SET: nouryoku
		DRIVER(nouryoku) //t:nouryoku f:nmk16.c r: c:
//SET: raphero
		DRIVER(raphero) //t:raphero f:nmk16.c r: c:
//SET: ssmissin
		DRIVER(ssmissin) //t:ssmissin f:nmk16.c r: c:
//SET: airattck
		DRIVER(airattck) //t:airattck f:nmk16.c r: c:
		DRIVER(airattcka) //t:airattcka f:nmk16.c r:airattck c:airattck
//SET: manybloc
		DRIVER(manybloc) //t:manybloc f:nmk16.c r: c:
//SET: daireika
		DRIVER(daireika) //t:daireika f:jalmah.c r: c:
//SET: mjzoomin
		DRIVER(mjzoomin) //t:mjzoomin f:jalmah.c r: c:
//SET: kakumei
		DRIVER(kakumei) //t:kakumei f:jalmah.c r: c:
//SET: kakumei2
		DRIVER(kakumei2) //t:kakumei2 f:jalmah.c r: c:
//SET: suchipi
		DRIVER(suchipi) //t:suchipi f:jalmah.c r: c:
//SET: ddealer
		DRIVER(ddealer) //t:ddealer f:ddealer.c r: c:
//SET: quizpani
		DRIVER(quizpani) //t:quizpani f:quizpani.c r: c:
//SET: acommand
		DRIVER(acommand) //t:acommand f:acommand.c r: c:
//SET: macrossp
		DRIVER(macrossp) //t:macrossp f:macrossp.c r: c:
//SET: quizmoon
		DRIVER(quizmoon) //t:quizmoon f:macrossp.c r: c:
//SET: gakupara
		DRIVER(gakupara) //t:gakupara f:quizdna.c r: c:
//SET: quizdna
		DRIVER(quizdna) //t:quizdna f:quizdna.c r: c:
//SET: gekiretu
		DRIVER(gekiretu) //t:gekiretu f:quizdna.c r: c:
//SET: cultures
		DRIVER(cultures) //t:cultures f:cultures.c r: c:
//SET: narc
		DRIVER(narc) //t:narc f:midyunit.c r: c:
		DRIVER(narc3) //t:narc3 f:midyunit.c r:narc c:narc
		DRIVER(narc2) //t:narc2 f:midyunit.c r:narc c:narc
//SET: trog
		DRIVER(trog) //t:trog f:midyunit.c r: c:
		DRIVER(trog4) //t:trog4 f:midyunit.c r:trog c:trog
		DRIVER(trog3) //t:trog3 f:midyunit.c r:trog c:trog
		DRIVER(trogpa6) //t:trogpa6 f:midyunit.c r:trog c:trog
		DRIVER(trogpa4) //t:trogpa4 f:midyunit.c r:trog c:trog
//SET: smashtv
		DRIVER(smashtv) //t:smashtv f:midyunit.c r: c:
		DRIVER(smashtv6) //t:smashtv6 f:midyunit.c r:smashtv c:smashtv
		DRIVER(smashtv5) //t:smashtv5 f:midyunit.c r:smashtv c:smashtv
		DRIVER(smashtv4) //t:smashtv4 f:midyunit.c r:smashtv c:smashtv
		DRIVER(smashtv3) //t:smashtv3 f:midyunit.c r:smashtv c:smashtv
//SET: hiimpact
		DRIVER(hiimpact) //t:hiimpact f:midyunit.c r: c:
		DRIVER(hiimpact4) //t:hiimpact4 f:midyunit.c r:hiimpact c:hiimpact
		DRIVER(hiimpact3) //t:hiimpact3 f:midyunit.c r:hiimpact c:hiimpact
		DRIVER(hiimpact2) //t:hiimpact2 f:midyunit.c r:hiimpact c:hiimpact
		DRIVER(hiimpact1) //t:hiimpact1 f:midyunit.c r:hiimpact c:hiimpact
		DRIVER(hiimpactp) //t:hiimpactp f:midyunit.c r:hiimpact c:hiimpact
//SET: shimpact
		DRIVER(shimpact) //t:shimpact f:midyunit.c r: c:
		DRIVER(shimpactp6) //t:shimpactp6 f:midyunit.c r:shimpact c:shimpact
		DRIVER(shimpactp5) //t:shimpactp5 f:midyunit.c r:shimpact c:shimpact
		DRIVER(shimpactp4) //t:shimpactp4 f:midyunit.c r:shimpact c:shimpact
//SET: strkforc
		DRIVER(strkforc) //t:strkforc f:midyunit.c r: c:
//SET: mk
		DRIVER(mk) //t:mk f:midtunit.c r: c:
		DRIVER(mkr4) //t:mkr4 f:midtunit.c r:mk c:mk
		DRIVER(mktturbo) //t:mktturbo f:midtunit.c r:mk c:mk
		DRIVER(mkyturbo) //t:mkyturbo f:midyunit.c r:mk c:mk
		DRIVER(mkprot4) //t:mkprot4 f:midyunit.c r:mk c:mk
		DRIVER(mkprot8) //t:mkprot8 f:midyunit.c r:mk c:mk
		DRIVER(mkprot9) //t:mkprot9 f:midyunit.c r:mk c:mk
		DRIVER(mkla1) //t:mkla1 f:midyunit.c r:mk c:mk
		DRIVER(mkla2) //t:mkla2 f:midyunit.c r:mk c:mk
		DRIVER(mkla3) //t:mkla3 f:midyunit.c r:mk c:mk
		DRIVER(mkla4) //t:mkla4 f:midyunit.c r:mk c:mk
		DRIVER(mkyawdim) //t:mkyawdim f:midyunit.c r:mk c:mk
//SET: term2
		DRIVER(term2) //t:term2 f:midyunit.c r: c:
		DRIVER(term2la3) //t:term2la3 f:midyunit.c r:term2 c:term2
		DRIVER(term2la2) //t:term2la2 f:midyunit.c r:term2 c:term2
		DRIVER(term2la1) //t:term2la1 f:midyunit.c r:term2 c:term2
//SET: totcarn
		DRIVER(totcarn) //t:totcarn f:midyunit.c r: c:
		DRIVER(totcarnp) //t:totcarnp f:midyunit.c r:totcarn c:totcarn
//SET: mk2
		DRIVER(mk2) //t:mk2 f:midtunit.c r: c:
		DRIVER(mk2r31e) //t:mk2r31e f:midtunit.c r:mk2 c:mk2
		DRIVER(mk2r32) //t:mk2r32 f:midtunit.c r:mk2 c:mk2
		DRIVER(mk2r30) //t:mk2r30 f:midtunit.c r:mk2 c:mk2
		DRIVER(mk2r21) //t:mk2r21 f:midtunit.c r:mk2 c:mk2
		DRIVER(mk2r14) //t:mk2r14 f:midtunit.c r:mk2 c:mk2
		DRIVER(mk2r11) //t:mk2r11 f:midtunit.c r:mk2 c:mk2
		DRIVER(mk2r42) //t:mk2r42 f:midtunit.c r:mk2 c:mk2
		DRIVER(mk2r91) //t:mk2r91 f:midtunit.c r:mk2 c:mk2
		DRIVER(mk2chal) //t:mk2chal f:midtunit.c r:mk2 c:mk2
//SET: jdreddp
		DRIVER(jdreddp) //t:jdreddp f:midtunit.c r: c:
//SET: nbajam
		DRIVER(nbajam) //t:nbajam f:midtunit.c r: c:
		DRIVER(nbajamr2) //t:nbajamr2 f:midtunit.c r:nbajam c:nbajam
//SET: nbajamte
		DRIVER(nbajamte) //t:nbajamte f:midtunit.c r: c:
		DRIVER(nbajamt1) //t:nbajamt1 f:midtunit.c r:nbajamte c:nbajamte
		DRIVER(nbajamt2) //t:nbajamt2 f:midtunit.c r:nbajamte c:nbajamte
		DRIVER(nbajamt3) //t:nbajamt3 f:midtunit.c r:nbajamte c:nbajamte
//SET: revx
		DRIVER(revx) //t:revx f:midxunit.c r: c:
//SET: mk3
		DRIVER(mk3) //t:mk3 f:midwunit.c r: c:
		DRIVER(mk3r20) //t:mk3r20 f:midwunit.c r:mk3 c:mk3
		DRIVER(mk3r10) //t:mk3r10 f:midwunit.c r:mk3 c:mk3
		DRIVER(mk3p40) //t:mk3p40 f:midwunit.c r:mk3 c:mk3
//SET: umk3
		DRIVER(umk3) //t:umk3 f:midwunit.c r: c:
		DRIVER(umk3r11) //t:umk3r11 f:midwunit.c r:umk3 c:umk3
		DRIVER(umk3r10) //t:umk3r10 f:midwunit.c r:umk3 c:umk3
//SET: wwfmania
		DRIVER(wwfmania) //t:wwfmania f:midwunit.c r: c:
		DRIVER(wwfmaniab) //t:wwfmaniab f:midwunit.c r:wwfmania c:wwfmania
//SET: openice
		DRIVER(openice) //t:openice f:midwunit.c r: c:
//SET: nbahangt
		DRIVER(nbahangt) //t:nbahangt f:midwunit.c r: c:
		DRIVER(nbamht) //t:nbamht f:midwunit.c r:nbahangt c:nbahangt
		DRIVER(nbamht1) //t:nbamht1 f:midwunit.c r:nbahangt c:nbahangt
//SET: rmpgwt
		DRIVER(rmpgwt) //t:rmpgwt f:midwunit.c r: c:
		DRIVER(rmpgwt11) //t:rmpgwt11 f:midwunit.c r:rmpgwt c:rmpgwt
//SET: crusnusa
		DRIVER(crusnusa) //t:crusnusa f:midvunit.c r: c:
		DRIVER(crusnusa40) //t:crusnusa40 f:midvunit.c r:crusnusa c:crusnusa
		DRIVER(crusnusa21) //t:crusnusa21 f:midvunit.c r:crusnusa c:crusnusa
//SET: crusnwld
		DRIVER(crusnwld) //t:crusnwld f:midvunit.c r: c:
		DRIVER(crusnwld23) //t:crusnwld23 f:midvunit.c r:crusnwld c:crusnwld
		DRIVER(crusnwld20) //t:crusnwld20 f:midvunit.c r:crusnwld c:crusnwld
		DRIVER(crusnwld17) //t:crusnwld17 f:midvunit.c r:crusnwld c:crusnwld
		DRIVER(crusnwld13) //t:crusnwld13 f:midvunit.c r:crusnwld c:crusnwld
//SET: offroadc
		DRIVER(offroadc) //t:offroadc f:midvunit.c r: c:
		DRIVER(offroadc4) //t:offroadc4 f:midvunit.c r:offroadc c:offroadc
		DRIVER(offroadc3) //t:offroadc3 f:midvunit.c r:offroadc c:offroadc
		DRIVER(offroadc1) //t:offroadc1 f:midvunit.c r:offroadc c:offroadc
//SET: wargods
		DRIVER(wargods) //t:wargods f:midvunit.c r: c:
//SET: mk4
		DRIVER(mk4) //t:mk4 f:midzeus.c r: c:
		DRIVER(mk4a) //t:mk4a f:midzeus.c r:mk4 c:mk4
		DRIVER(mk4b) //t:mk4b f:midzeus.c r:mk4 c:mk4
//SET: invasnab
		DRIVER(invasnab) //t:invasnab f:midzeus.c r: c:
		DRIVER(invasnv4) //t:invasnv4 f:midzeus.c r:invasnab c:invasnab
//SET: crusnexo
		DRIVER(crusnexo) //t:crusnexo f:midzeus.c r: c:
		DRIVER(crusnexoa) //t:crusnexoa f:midzeus.c r:crusnexo c:crusnexo
		DRIVER(crusnexob) //t:crusnexob f:midzeus.c r:crusnexo c:crusnexo
//SET: thegrid
		DRIVER(thegrid) //t:thegrid f:midzeus.c r: c:
		DRIVER(thegrida) //t:thegrida f:midzeus.c r:thegrid c:thegrid
//SET: wg3dh
		DRIVER(wg3dh) //t:wg3dh f:seattle.c r: c:
//SET: mace
		DRIVER(mace) //t:mace f:seattle.c r: c:
		DRIVER(macea) //t:macea f:seattle.c r:mace c:mace
//SET: sfrush
		DRIVER(sfrush) //t:sfrush f:seattle.c r: c:
//SET: sfrushrk
		DRIVER(sfrushrk) //t:sfrushrk f:seattle.c r: c:
//SET: calspeed
		DRIVER(calspeed) //t:calspeed f:seattle.c r: c:
		DRIVER(calspeeda) //t:calspeeda f:seattle.c r:calspeed c:calspeed
//SET: vaportrx
		DRIVER(vaportrx) //t:vaportrx f:seattle.c r: c:
		DRIVER(vaportrxp) //t:vaportrxp f:seattle.c r:vaportrx c:vaportrx
//SET: carnevil
		DRIVER(carnevil) //t:carnevil f:seattle.c r: c:
		DRIVER(carnevil1) //t:carnevil1 f:seattle.c r:carnevil c:carnevil
//SET: biofreak
		DRIVER(biofreak) //t:biofreak f:seattle.c r: c:
//SET: blitz
		DRIVER(blitz) //t:blitz f:seattle.c r: c:
		DRIVER(blitz11) //t:blitz11 f:seattle.c r:blitz c:blitz
//SET: blitz99
		DRIVER(blitz99) //t:blitz99 f:seattle.c r: c:
//SET: blitz2k
		DRIVER(blitz2k) //t:blitz2k f:seattle.c r: c:
//SET: hyprdriv
		DRIVER(hyprdriv) //t:hyprdriv f:seattle.c r: c:
#endif

#ifdef PS3_SET_12
//SET: gauntleg
		DRIVER(gauntleg) //t:gauntleg f:vegas.c r: c:
		DRIVER(gauntleg12) //t:gauntleg12 f:vegas.c r:gauntleg c:gauntleg
//SET: tenthdeg
		DRIVER(tenthdeg) //t:tenthdeg f:vegas.c r: c:
//SET: roadburn
		DRIVER(roadburn) //t:roadburn f:vegas.c r: c:
//SET: sf2049
		DRIVER(sf2049) //t:sf2049 f:vegas.c r: c:
		DRIVER(sf2049se) //t:sf2049se f:vegas.c r:sf2049 c:sf2049
		DRIVER(sf2049te) //t:sf2049te f:vegas.c r:sf2049 c:sf2049
//SET: warfa
		DRIVER(warfa) //t:warfa f:vegas.c r: c:
//SET: nbashowt
		DRIVER(nbashowt) //t:nbashowt f:vegas.c r: c:
//SET: nbanfl
		DRIVER(nbanfl) //t:nbanfl f:vegas.c r: c:
//SET: gauntdl
		DRIVER(gauntdl) //t:gauntdl f:vegas.c r: c:
		DRIVER(gauntdl24) //t:gauntdl24 f:vegas.c r:gauntdl c:gauntdl
//SET: cartfury
		DRIVER(cartfury) //t:cartfury f:vegas.c r: c:
//SET: hydrthnd
		DRIVER(hydrthnd) //t:hydrthnd f:midqslvr.c r: c:
//SET: offrthnd
		DRIVER(offrthnd) //t:offrthnd f:midqslvr.c r: c:
//SET: tm
		DRIVER(tm) //t:tm f:tmaster.c r: c:
		DRIVER(tmdo) //t:tmdo f:tmaster.c r:tm c:tm
//SET: tm2k
		DRIVER(tm2k) //t:tm2k f:tmaster.c r: c:
		DRIVER(tm2ka) //t:tm2ka f:tmaster.c r:tm2k c:tm2k
		DRIVER(tm2kb) //t:tm2kb f:tmaster.c r:tm2k c:tm2k
//SET: tm3k
		DRIVER(tm3k) //t:tm3k f:tmaster.c r: c:
		DRIVER(tm3ka) //t:tm3ka f:tmaster.c r:tm3k c:tm3k
//SET: tm4k
		DRIVER(tm4k) //t:tm4k f:tmaster.c r: c:
		DRIVER(tm4ka) //t:tm4ka f:tmaster.c r:tm4k c:tm4k
		DRIVER(tm4kb) //t:tm4kb f:tmaster.c r:tm4k c:tm4k
//SET: tm5k
		DRIVER(tm5k) //t:tm5k f:tmaster.c r: c:
		DRIVER(tm5kca) //t:tm5kca f:tmaster.c r:tm5k c:tm5k
		DRIVER(tm5ka) //t:tm5ka f:tmaster.c r:tm5k c:tm5k
//SET: tm7k
		DRIVER(tm7k) //t:tm7k f:tmaster.c r: c:
		DRIVER(tm7ka) //t:tm7ka f:tmaster.c r:tm7k c:tm7k
		DRIVER(tm7keval) //t:tm7keval f:tmaster.c r:tm7k c:tm7k
//SET: tm8k
		DRIVER(tm8k) //t:tm8k f:tmaster.c r: c:
		DRIVER(tm8k902) //t:tm8k902 f:tmaster.c r:tm8k c:tm8k
//SET: galgbios
		DRIVER(galgbios) //t:galgbios f:tmaster.c r: c:
//SET: galgame2
		DRIVER(galgame2) //t:galgame2 f:tmaster.c r:galgbios c:
//SET: embargo
		DRIVER(embargo) //t:embargo f:embargo.c r: c:
//SET: tripool
		DRIVER(tripool) //t:tripool f:jack.c r: c:
		DRIVER(tripoola) //t:tripoola f:jack.c r:tripool c:tripool
//SET: unclepoo
		DRIVER(unclepoo) //t:unclepoo f:poo.c r: c:
//SET: joinem
		DRIVER(joinem) //t:joinem f:jack.c r: c:
//SET: loverboy
		DRIVER(loverboy) //t:loverboy f:jack.c r: c:
//SET: striv
		DRIVER(striv) //t:striv f:jack.c r: c:
//SET: jack
		DRIVER(jack) //t:jack f:jack.c r: c:
		DRIVER(jack2) //t:jack2 f:jack.c r:jack c:jack
		DRIVER(jack3) //t:jack3 f:jack.c r:jack c:jack
		DRIVER(treahunt) //t:treahunt f:jack.c r:jack c:jack
//SET: zzyzzyxx
		DRIVER(zzyzzyxx) //t:zzyzzyxx f:jack.c r: c:
		DRIVER(zzyzzyxx2) //t:zzyzzyxx2 f:jack.c r:zzyzzyxx c:zzyzzyxx
		DRIVER(brix) //t:brix f:jack.c r:zzyzzyxx c:zzyzzyxx
//SET: freeze
		DRIVER(freeze) //t:freeze f:jack.c r: c:
//SET: sucasino
		DRIVER(sucasino) //t:sucasino f:jack.c r: c:
//SET: spacewar
		DRIVER(spacewar) //t:spacewar f:cinemat.c r: c:
		DRIVER(spaceshp) //t:spaceshp f:cinemat.c r:spacewar c:spacewar
//SET: barrier
		DRIVER(barrier) //t:barrier f:cinemat.c r: c:
//SET: starcas
		DRIVER(starcas) //t:starcas f:cinemat.c r: c:
		DRIVER(starcas1) //t:starcas1 f:cinemat.c r:starcas c:starcas
		DRIVER(starcasp) //t:starcasp f:cinemat.c r:starcas c:starcas
		DRIVER(starcase) //t:starcase f:cinemat.c r:starcas c:starcas
		DRIVER(stellcas) //t:stellcas f:cinemat.c r:starcas c:starcas
		DRIVER(spaceftr) //t:spaceftr f:cinemat.c r:starcas c:starcas
//SET: tailg
		DRIVER(tailg) //t:tailg f:cinemat.c r: c:
//SET: ripoff
		DRIVER(ripoff) //t:ripoff f:cinemat.c r: c:
//SET: armora
		DRIVER(armora) //t:armora f:cinemat.c r: c:
		DRIVER(armorap) //t:armorap f:cinemat.c r:armora c:armora
		DRIVER(armorar) //t:armorar f:cinemat.c r:armora c:armora
//SET: wotw
		DRIVER(wotw) //t:wotw f:cinemat.c r: c:
		DRIVER(wotwc) //t:wotwc f:cinemat.c r:wotw c:wotw
//SET: warrior
		DRIVER(warrior) //t:warrior f:cinemat.c r: c:
//SET: starhawk
		DRIVER(starhawk) //t:starhawk f:cinemat.c r: c:
//SET: solarq
		DRIVER(solarq) //t:solarq f:cinemat.c r: c:
//SET: boxingb
		DRIVER(boxingb) //t:boxingb f:cinemat.c r: c:
//SET: speedfrk
		DRIVER(speedfrk) //t:speedfrk f:cinemat.c r: c:
//SET: sundance
		DRIVER(sundance) //t:sundance f:cinemat.c r: c:
//SET: demon
		DRIVER(demon) //t:demon f:cinemat.c r: c:
//SET: qb3
		DRIVER(qb3) //t:qb3 f:cinemat.c r: c:
//SET: cchasm
		DRIVER(cchasm) //t:cchasm f:cchasm.c r: c:
		DRIVER(cchasm1) //t:cchasm1 f:cchasm.c r:cchasm c:cchasm
//SET: roundup
		DRIVER(roundup) //t:roundup f:thepit.c r: c:
		DRIVER(fitter) //t:fitter f:thepit.c r:roundup c:roundup
		DRIVER(fitterbl) //t:fitterbl f:thepit.c r:roundup c:roundup
//SET: thepit
		DRIVER(thepit) //t:thepit f:thepit.c r: c:
		DRIVER(thepitu1) //t:thepitu1 f:thepit.c r:thepit c:thepit
		DRIVER(thepitu2) //t:thepitu2 f:thepit.c r:thepit c:thepit
		DRIVER(thepitj) //t:thepitj f:thepit.c r:thepit c:thepit
		DRIVER(thepitm) //t:thepitm f:galdrvr.c r:thepit c:thepit
//SET: dockman
		DRIVER(dockman) //t:dockman f:thepit.c r: c:
		DRIVER(porter) //t:porter f:galaxold.c r:dockman c:dockman
		DRIVER(portman) //t:portman f:thepit.c r:dockman c:dockman
//SET: suprmous
		DRIVER(suprmous) //t:suprmous f:thepit.c r: c:
		DRIVER(funnymou) //t:funnymou f:thepit.c r:suprmous c:suprmous
//SET: machomou
		DRIVER(machomou) //t:machomou f:thepit.c r: c:
//SET: intrepid
		DRIVER(intrepid) //t:intrepid f:thepit.c r: c:
		DRIVER(intrepid2) //t:intrepid2 f:thepit.c r:intrepid c:intrepid
//SET: zaryavos
		DRIVER(zaryavos) //t:zaryavos f:thepit.c r: c:
//SET: timelimt
		DRIVER(timelimt) //t:timelimt f:timelimt.c r: c:
//SET: progress
		DRIVER(progress) //t:progress f:timelimt.c r: c:
//SET: koroleva
		DRIVER(koroleva) //t:koroleva f:tiamc1.c r: c:
//SET: rtriv
		DRIVER(rtriv) //t:rtriv f:thepit.c r: c:
//SET: konek
		DRIVER(konek) //t:konek f:tiamc1.c r: c:
//SET: sosterm
		DRIVER(sosterm) //t:sosterm f:tiamc1.c r: c:
//SET: bilyard
		DRIVER(bilyard) //t:bilyard f:tiamc1.c r: c:
//SET: phtetris
		DRIVER(phtetris) //t:phtetris f:photon.c r: c:
//SET: phpython
		DRIVER(phpython) //t:phpython f:photon.c r: c:
//SET: phklad
		DRIVER(phklad) //t:phklad f:photon.c r: c:
//SET: kok
		DRIVER(kok) //t:kok f:photon2.c r: c:
//SET: black
		DRIVER(black) //t:black f:photon2.c r: c:
//SET: brod
		DRIVER(brod) //t:brod f:photon2.c r: c:
//SET: bagman
		DRIVER(bagman) //t:bagman f:bagman.c r: c:
		DRIVER(bagmanmc) //t:bagmanmc f:galaxold.c r:bagman c:bagman
		DRIVER(bagmanf) //t:bagmanf f:cclimber.c r:bagman c:bagman
		DRIVER(bagnard) //t:bagnard f:bagman.c r:bagman c:bagman
		DRIVER(bagnarda) //t:bagnarda f:bagman.c r:bagman c:bagman
		DRIVER(bagmans) //t:bagmans f:bagman.c r:bagman c:bagman
		DRIVER(bagmans2) //t:bagmans2 f:bagman.c r:bagman c:bagman
//SET: pickin
		DRIVER(pickin) //t:pickin f:bagman.c r: c:
//SET: supdrapo
		DRIVER(supdrapo) //t:supdrapo f:supdrapo.c r: c:
		DRIVER(supdrapoa) //t:supdrapoa f:supdrapo.c r:supdrapo c:supdrapo
		DRIVER(supdrapob) //t:supdrapob f:supdrapo.c r:supdrapo c:supdrapo
//SET: sbagman
		DRIVER(sbagman) //t:sbagman f:bagman.c r: c:
		DRIVER(sbagmans) //t:sbagmans f:bagman.c r:sbagman c:sbagman
//SET: botanic
		DRIVER(botanic) //t:botanic f:bagman.c r: c:
//SET: squaitsa
		DRIVER(squaitsa) //t:squaitsa f:bagman.c r: c:
//SET: tankbust
		DRIVER(tankbust) //t:tankbust f:tankbust.c r: c:
//SET: stinger
		DRIVER(stinger) //t:stinger f:wiz.c r: c:
		DRIVER(stinger2) //t:stinger2 f:wiz.c r:stinger c:stinger
//SET: scion
		DRIVER(scion) //t:scion f:wiz.c r: c:
		DRIVER(scionc) //t:scionc f:wiz.c r:scion c:scion
//SET: kungfut
		DRIVER(kungfut) //t:kungfut f:wiz.c r: c:
		DRIVER(kungfuta) //t:kungfuta f:wiz.c r:kungfut c:kungfut
//SET: wiz
		DRIVER(wiz) //t:wiz f:wiz.c r: c:
		DRIVER(wizt) //t:wizt f:wiz.c r:wiz c:wiz
		DRIVER(wizta) //t:wizta f:wiz.c r:wiz c:wiz
//SET: kncljoe
		DRIVER(kncljoe) //t:kncljoe f:kncljoe.c r: c:
		DRIVER(kncljoea) //t:kncljoea f:kncljoe.c r:kncljoe c:kncljoe
		DRIVER(bcrusher) //t:bcrusher f:kncljoe.c r:kncljoe c:kncljoe
//SET: empcity
		DRIVER(empcity) //t:empcity f:stfight.c r: c:
		DRIVER(empcityu) //t:empcityu f:stfight.c r:empcity c:empcity
		DRIVER(empcityj) //t:empcityj f:stfight.c r:empcity c:empcity
		DRIVER(empcityi) //t:empcityi f:stfight.c r:empcity c:empcity
		DRIVER(stfight) //t:stfight f:stfight.c r:empcity c:empcity
		DRIVER(stfighta) //t:stfighta f:stfight.c r:empcity c:empcity
//SET: darkmist
		DRIVER(darkmist) //t:darkmist f:darkmist.c r: c:
//SET: mustache
		DRIVER(mustache) //t:mustache f:mustache.c r: c:
//SET: cshooter
		DRIVER(cshooter) //t:cshooter f:cshooter.c r: c:
		DRIVER(cshootere) //t:cshootere f:cshooter.c r:cshooter c:cshooter
		DRIVER(airraid) //t:airraid f:cshooter.c r:cshooter c:cshooter
//SET: panicr
		DRIVER(panicr) //t:panicr f:panicr.c r: c:
//SET: deadang
		DRIVER(deadang) //t:deadang f:deadang.c r: c:
		DRIVER(leadang) //t:leadang f:deadang.c r:deadang c:deadang
		DRIVER(ghunter) //t:ghunter f:deadang.c r:deadang c:deadang
//SET: dynduke
		DRIVER(dynduke) //t:dynduke f:dynduke.c r: c:
		DRIVER(dyndukef) //t:dyndukef f:dynduke.c r:dynduke c:dynduke
		DRIVER(dbldyn) //t:dbldyn f:dynduke.c r:dynduke c:dynduke
		DRIVER(dbldynf) //t:dbldynf f:dynduke.c r:dynduke c:dynduke
//SET: raiden
		DRIVER(raiden) //t:raiden f:raiden.c r: c:
		DRIVER(raidena) //t:raidena f:raiden.c r:raiden c:raiden
		DRIVER(raidenk) //t:raidenk f:raiden.c r:raiden c:raiden
		DRIVER(raident) //t:raident f:raiden.c r:raiden c:raiden
		DRIVER(raidenu) //t:raidenu f:raiden.c r:raiden c:raiden
		DRIVER(raidenua) //t:raidenua f:raiden.c r:raiden c:raiden
//SET: sdgndmps
		DRIVER(sdgndmps) //t:sdgndmps f:dcon.c r: c:
//SET: dcon
		DRIVER(dcon) //t:dcon f:dcon.c r: c:
//SET: sengokmj
		DRIVER(sengokmj) //t:sengokmj f:sengokmj.c r: c:
//SET: totmejan
		DRIVER(totmejan) //t:totmejan f:goodejan.c r: c:
//SET: goodejan
		DRIVER(goodejan) //t:goodejan f:goodejan.c r: c:
		DRIVER(goodejana) //t:goodejana f:goodejan.c r:goodejan c:goodejan
//SET: raiden2
		DRIVER(raiden2) //t:raiden2 f:raiden2.c r: c:
		DRIVER(raiden2a) //t:raiden2a f:raiden2.c r:raiden2 c:raiden2
		DRIVER(raiden2b) //t:raiden2b f:raiden2.c r:raiden2 c:raiden2
		DRIVER(raiden2c) //t:raiden2c f:raiden2.c r:raiden2 c:raiden2
		DRIVER(raiden2d) //t:raiden2d f:raiden2.c r:raiden2 c:raiden2
		DRIVER(raiden2e) //t:raiden2e f:raiden2.c r:raiden2 c:raiden2
		DRIVER(raiden2f) //t:raiden2f f:raiden2.c r:raiden2 c:raiden2
//SET: raidndx
		DRIVER(raidndx) //t:raidndx f:raiden2.c r: c:
		DRIVER(raidndxj) //t:raidndxj f:raiden2.c r:raidndx c:raidndx
		DRIVER(raidndxu) //t:raidndxu f:raiden2.c r:raidndx c:raidndx
		DRIVER(raidndxa1) //t:raidndxa1 f:raiden2.c r:raidndx c:raidndx
		DRIVER(raidndxa2) //t:raidndxa2 f:raiden2.c r:raidndx c:raidndx
		DRIVER(raidndxg) //t:raidndxg f:raiden2.c r:raidndx c:raidndx
//SET: zeroteam
		DRIVER(zeroteam) //t:zeroteam f:raiden2.c r: c:
		DRIVER(zeroteama) //t:zeroteama f:raiden2.c r:zeroteam c:zeroteam
		DRIVER(zeroteamb) //t:zeroteamb f:raiden2.c r:zeroteam c:zeroteam
		DRIVER(zeroteamc) //t:zeroteamc f:raiden2.c r:zeroteam c:zeroteam
		DRIVER(zeroteams) //t:zeroteams f:raiden2.c r:zeroteam c:zeroteam
		DRIVER(zeroteamsr) //t:zeroteamsr f:raiden2.c r:zeroteam c:zeroteam
		DRIVER(nzerotea) //t:nzerotea f:r2dx_v33.c r:zeroteam c:zeroteam
//SET: xsedae
		DRIVER(xsedae) //t:xsedae f:raiden2.c r: c:
//SET: r2dx_v33
		DRIVER(r2dx_v33) //t:r2dx_v33 f:r2dx_v33.c r: c:
//SET: senkyu
		DRIVER(senkyu) //t:senkyu f:seibuspi.c r: c:
		DRIVER(senkyua) //t:senkyua f:seibuspi.c r:senkyu c:senkyu
		DRIVER(batlball) //t:batlball f:seibuspi.c r:senkyu c:senkyu
		DRIVER(batlballa) //t:batlballa f:seibuspi.c r:senkyu c:senkyu
		DRIVER(batlballu) //t:batlballu f:seibuspi.c r:senkyu c:senkyu
//SET: viprp1
		DRIVER(viprp1) //t:viprp1 f:seibuspi.c r: c:
		DRIVER(viprp1u) //t:viprp1u f:seibuspi.c r:viprp1 c:viprp1
		DRIVER(viprp1j) //t:viprp1j f:seibuspi.c r:viprp1 c:viprp1
		DRIVER(viprp1s) //t:viprp1s f:seibuspi.c r:viprp1 c:viprp1
		DRIVER(viprp1oj) //t:viprp1oj f:seibuspi.c r:viprp1 c:viprp1
		DRIVER(viprp1ot) //t:viprp1ot f:seibuspi.c r:viprp1 c:viprp1
		DRIVER(viprp1hk) //t:viprp1hk f:seibuspi.c r:viprp1 c:viprp1
//SET: ejanhs
		DRIVER(ejanhs) //t:ejanhs f:seibuspi.c r: c:
//SET: rdft
		DRIVER(rdft) //t:rdft f:seibuspi.c r: c:
		DRIVER(rdftu) //t:rdftu f:seibuspi.c r:rdft c:rdft
		DRIVER(rdftau) //t:rdftau f:seibuspi.c r:rdft c:rdft
		DRIVER(rdftj) //t:rdftj f:seibuspi.c r:rdft c:rdft
		DRIVER(rdftadi) //t:rdftadi f:seibuspi.c r:rdft c:rdft
		DRIVER(rdftam) //t:rdftam f:seibuspi.c r:rdft c:rdft
		DRIVER(rdftit) //t:rdftit f:seibuspi.c r:rdft c:rdft
		DRIVER(rdfta) //t:rdfta f:seibuspi.c r:rdft c:rdft
//SET: rdft2
		DRIVER(rdft2) //t:rdft2 f:seibuspi.c r: c:
		DRIVER(rdft2a) //t:rdft2a f:seibuspi.c r:rdft2 c:rdft2
		DRIVER(rdft2a2) //t:rdft2a2 f:seibuspi.c r:rdft2 c:rdft2
		DRIVER(rdft2j) //t:rdft2j f:seibuspi.c r:rdft2 c:rdft2
		DRIVER(rdft2j2) //t:rdft2j2 f:seibuspi.c r:rdft2 c:rdft2
		DRIVER(rdft2t) //t:rdft2t f:seibuspi.c r:rdft2 c:rdft2
		DRIVER(rdft2u) //t:rdft2u f:seibuspi.c r:rdft2 c:rdft2
		DRIVER(rdft2us) //t:rdft2us f:seibuspi.c r:rdft2 c:rdft2
		DRIVER(rdft22kc) //t:rdft22kc f:seibuspi.c r:rdft2 c:rdft2
//SET: rfjet
		DRIVER(rfjet) //t:rfjet f:seibuspi.c r: c:
		DRIVER(rfjetu) //t:rfjetu f:seibuspi.c r:rfjet c:rfjet
		DRIVER(rfjeta) //t:rfjeta f:seibuspi.c r:rfjet c:rfjet
		DRIVER(rfjetj) //t:rfjetj f:seibuspi.c r:rfjet c:rfjet
		DRIVER(rfjets) //t:rfjets f:seibuspi.c r:rfjet c:rfjet
		DRIVER(rfjet2kc) //t:rfjet2kc f:seibuspi.c r:rfjet c:rfjet
//SET: ejsakura
		DRIVER(ejsakura) //t:ejsakura f:seibuspi.c r: c:
		DRIVER(ejsakura12) //t:ejsakura12 f:seibuspi.c r:ejsakura c:ejsakura
//SET: feversoc
		DRIVER(feversoc) //t:feversoc f:feversoc.c r: c:
//SET: cabal
		DRIVER(cabal) //t:cabal f:cabal.c r: c:
		DRIVER(cabala) //t:cabala f:cabal.c r:cabal c:cabal
		DRIVER(cabalbl) //t:cabalbl f:cabal.c r:cabal c:cabal
		DRIVER(cabalbl2) //t:cabalbl2 f:cabal.c r:cabal c:cabal
		DRIVER(cabalus) //t:cabalus f:cabal.c r:cabal c:cabal
		DRIVER(cabalus2) //t:cabalus2 f:cabal.c r:cabal c:cabal
//SET: toki
		DRIVER(toki) //t:toki f:toki.c r: c:
		DRIVER(tokia) //t:tokia f:toki.c r:toki c:toki
		DRIVER(tokiu) //t:tokiu f:toki.c r:toki c:toki
		DRIVER(tokiua) //t:tokiua f:toki.c r:toki c:toki
		DRIVER(tokib) //t:tokib f:toki.c r:toki c:toki
		DRIVER(juju) //t:juju f:toki.c r:toki c:toki
		DRIVER(jujub) //t:jujub f:toki.c r:toki c:toki
//SET: bloodbro
		DRIVER(bloodbro) //t:bloodbro f:bloodbro.c r: c:
		DRIVER(bloodbroa) //t:bloodbroa f:bloodbro.c r:bloodbro c:bloodbro
		DRIVER(bloodbrob) //t:bloodbrob f:bloodbro.c r:bloodbro c:bloodbro
		DRIVER(weststry) //t:weststry f:bloodbro.c r:bloodbro c:bloodbro
//SET: skysmash
		DRIVER(skysmash) //t:skysmash f:bloodbro.c r: c:
//SET: legionna
		DRIVER(legionna) //t:legionna f:legionna.c r: c:
		DRIVER(legionnau) //t:legionnau f:legionna.c r:legionna c:legionna
//SET: heatbrl
		DRIVER(heatbrl) //t:heatbrl f:legionna.c r: c:
		DRIVER(heatbrl2) //t:heatbrl2 f:legionna.c r:heatbrl c:heatbrl
		DRIVER(heatbrlo) //t:heatbrlo f:legionna.c r:heatbrl c:heatbrl
		DRIVER(heatbrlu) //t:heatbrlu f:legionna.c r:heatbrl c:heatbrl
//SET: godzilla
		DRIVER(godzilla) //t:godzilla f:legionna.c r: c:
//SET: denjinmk
		DRIVER(denjinmk) //t:denjinmk f:legionna.c r: c:
//SET: grainbow
		DRIVER(grainbow) //t:grainbow f:legionna.c r: c:
//SET: cupsoc
		DRIVER(cupsoc) //t:cupsoc f:legionna.c r: c:
		DRIVER(cupsoca) //t:cupsoca f:legionna.c r:cupsoc c:cupsoc
		DRIVER(cupsocs) //t:cupsocs f:legionna.c r:cupsoc c:cupsoc
		DRIVER(cupsocs2) //t:cupsocs2 f:legionna.c r:cupsoc c:cupsoc
		DRIVER(cupsocsb) //t:cupsocsb f:legionna.c r:cupsoc c:cupsoc
		DRIVER(cupsocsb2) //t:cupsocsb2 f:legionna.c r:cupsoc c:cupsoc
		DRIVER(olysoc92) //t:olysoc92 f:legionna.c r:cupsoc c:cupsoc
		DRIVER(goal92) //t:goal92 f:goal92.c r:cupsoc c:cupsoc
//SET: exerion
		DRIVER(exerion) //t:exerion f:exerion.c r: c:
		DRIVER(exeriont) //t:exeriont f:exerion.c r:exerion c:exerion
		DRIVER(exerionb) //t:exerionb f:exerion.c r:exerion c:exerion
//SET: fcombat
		DRIVER(fcombat) //t:fcombat f:fcombat.c r: c:
//SET: pturn
		DRIVER(pturn) //t:pturn f:pturn.c r: c:
//SET: ddayjlc
		DRIVER(ddayjlc) //t:ddayjlc f:ddayjlc.c r: c:
		DRIVER(ddayjlca) //t:ddayjlca f:ddayjlc.c r:ddayjlc c:ddayjlc
//SET: formatz
		DRIVER(formatz) //t:formatz f:aeroboto.c r: c:
		DRIVER(aeroboto) //t:aeroboto f:aeroboto.c r:formatz c:formatz
//SET: citycon
		DRIVER(citycon) //t:citycon f:citycon.c r: c:
		DRIVER(citycona) //t:citycona f:citycon.c r:citycon c:citycon
		DRIVER(cruisin) //t:cruisin f:citycon.c r:citycon c:citycon
//SET: momoko
		DRIVER(momoko) //t:momoko f:momoko.c r: c:
//SET: argus
		DRIVER(argus) //t:argus f:argus.c r: c:
//SET: valtric
		DRIVER(valtric) //t:valtric f:argus.c r: c:
//SET: butasan
		DRIVER(butasan) //t:butasan f:argus.c r: c:
//SET: psychic5
		DRIVER(psychic5) //t:psychic5 f:psychic5.c r: c:
		DRIVER(psychic5a) //t:psychic5a f:psychic5.c r:psychic5 c:psychic5
//SET: bombsa
		DRIVER(bombsa) //t:bombsa f:psychic5.c r: c:
//SET: ginganin
		DRIVER(ginganin) //t:ginganin f:ginganin.c r: c:
		DRIVER(ginganina) //t:ginganina f:ginganin.c r:ginganin c:ginganin
//SET: skyfox
		DRIVER(skyfox) //t:skyfox f:skyfox.c r: c:
		DRIVER(exerizer) //t:exerizer f:skyfox.c r:skyfox c:skyfox
		DRIVER(exerizerb) //t:exerizerb f:skyfox.c r:skyfox c:skyfox
//SET: homerun
		DRIVER(homerun) //t:homerun f:homerun.c r: c:
//SET: dynashot
		DRIVER(dynashot) //t:dynashot f:homerun.c r: c:
//SET: bigrun
		DRIVER(bigrun) //t:bigrun f:cischeat.c r: c:
//SET: cischeat
		DRIVER(cischeat) //t:cischeat f:cischeat.c r: c:
//SET: f1gpstar
		DRIVER(f1gpstar) //t:f1gpstar f:cischeat.c r: c:
//SET: armchmp2
		DRIVER(armchmp2) //t:armchmp2 f:cischeat.c r: c:
		DRIVER(armchmp2o) //t:armchmp2o f:cischeat.c r:armchmp2 c:armchmp2
//SET: wildplt
		DRIVER(wildplt) //t:wildplt f:cischeat.c r: c:
//SET: f1gpstr2
		DRIVER(f1gpstr2) //t:f1gpstr2 f:cischeat.c r: c:
//SET: scudhamm
		DRIVER(scudhamm) //t:scudhamm f:cischeat.c r: c:
//SET: tetrisp2
		DRIVER(tetrisp2) //t:tetrisp2 f:tetrisp2.c r: c:
		DRIVER(tetrisp2j) //t:tetrisp2j f:tetrisp2.c r:tetrisp2 c:tetrisp2
		DRIVER(tetrisp2ja) //t:tetrisp2ja f:tetrisp2.c r:tetrisp2 c:tetrisp2
		DRIVER(tp2m32) //t:tp2m32 f:ms32.c r:tetrisp2 c:tetrisp2
//SET: nndmseal
		DRIVER(nndmseal) //t:nndmseal f:tetrisp2.c r: c:
//SET: stepstag
		DRIVER(stepstag) //t:stepstag f:stepstag.c r: c:
//SET: step3
		DRIVER(step3) //t:step3 f:stepstag.c r: c:
//SET: rockn
		DRIVER(rockn) //t:rockn f:tetrisp2.c r: c:
		DRIVER(rockna) //t:rockna f:tetrisp2.c r:rockn c:rockn
//SET: rockn2
		DRIVER(rockn2) //t:rockn2 f:tetrisp2.c r: c:
//SET: rocknms
		DRIVER(rocknms) //t:rocknms f:tetrisp2.c r: c:
//SET: rockn3
		DRIVER(rockn3) //t:rockn3 f:tetrisp2.c r: c:
//SET: rockn4
		DRIVER(rockn4) //t:rockn4 f:tetrisp2.c r: c:
//SET: lomakai
		DRIVER(lomakai) //t:lomakai f:megasys1.c r: c:
		DRIVER(makaiden) //t:makaiden f:megasys1.c r:lomakai c:lomakai
//SET: p47
		DRIVER(p47) //t:p47 f:megasys1.c r: c:
		DRIVER(p47j) //t:p47j f:megasys1.c r:p47 c:p47
//SET: kickoff
		DRIVER(kickoff) //t:kickoff f:megasys1.c r: c:
//SET: tshingen
		DRIVER(tshingen) //t:tshingen f:megasys1.c r: c:
		DRIVER(tshingena) //t:tshingena f:megasys1.c r:tshingen c:tshingen
//SET: kazan
		DRIVER(kazan) //t:kazan f:megasys1.c r: c:
		DRIVER(iganinju) //t:iganinju f:megasys1.c r:kazan c:kazan
//SET: astyanax
		DRIVER(astyanax) //t:astyanax f:megasys1.c r: c:
		DRIVER(lordofk) //t:lordofk f:megasys1.c r:astyanax c:astyanax
//SET: hachoo
		DRIVER(hachoo) //t:hachoo f:megasys1.c r: c:
//SET: jitsupro
		DRIVER(jitsupro) //t:jitsupro f:megasys1.c r: c:
//SET: plusalph
		DRIVER(plusalph) //t:plusalph f:megasys1.c r: c:
//SET: stdragon
		DRIVER(stdragon) //t:stdragon f:megasys1.c r: c:
//SET: rodland
		DRIVER(rodland) //t:rodland f:megasys1.c r: c:
		DRIVER(rodlandj) //t:rodlandj f:megasys1.c r:rodland c:rodland
		DRIVER(rodlandjb) //t:rodlandjb f:megasys1.c r:rodland c:rodland
//SET: avspirit
		DRIVER(avspirit) //t:avspirit f:megasys1.c r: c:
		DRIVER(phantasm) //t:phantasm f:megasys1.c r:avspirit c:avspirit
		DRIVER(monkelf) //t:monkelf f:megasys1.c r:avspirit c:avspirit
//SET: edf
		DRIVER(edf) //t:edf f:megasys1.c r: c:
		DRIVER(edfu) //t:edfu f:megasys1.c r:edf c:edf
		DRIVER(edfbl) //t:edfbl f:megasys1.c r:edf c:edf
//SET: 64street
		DRIVER(64street) //t:64street f:megasys1.c r: c:
		DRIVER(64streetj) //t:64streetj f:megasys1.c r:64street c:64street
//SET: soldam
		DRIVER(soldam) //t:soldam f:megasys1.c r: c:
		DRIVER(soldamj) //t:soldamj f:megasys1.c r:soldam c:soldam
//SET: bigstrik
		DRIVER(bigstrik) //t:bigstrik f:megasys1.c r: c:
		DRIVER(bigstrkb) //t:bigstrkb f:bigstrkb.c r:bigstrik c:bigstrik
		DRIVER(bestleag) //t:bestleag f:bestleag.c r:bigstrik c:bigstrik
		DRIVER(bestleaw) //t:bestleaw f:bestleag.c r:bigstrik c:bigstrik
//SET: chimerab
		DRIVER(chimerab) //t:chimerab f:megasys1.c r: c:
//SET: cybattlr
		DRIVER(cybattlr) //t:cybattlr f:megasys1.c r: c:
//SET: hayaosi1
		DRIVER(hayaosi1) //t:hayaosi1 f:megasys1.c r: c:
//SET: peekaboo
		DRIVER(peekaboo) //t:peekaboo f:megasys1.c r: c:
//SET: hayaosi2
		DRIVER(hayaosi2) //t:hayaosi2 f:ms32.c r: c:
//SET: hayaosi3
		DRIVER(hayaosi3) //t:hayaosi3 f:ms32.c r: c:
//SET: bbbxing
		DRIVER(bbbxing) //t:bbbxing f:ms32.c r: c:
//SET: 47pie2
		DRIVER(47pie2) //t:47pie2 f:ms32.c r: c:
		DRIVER(47pie2o) //t:47pie2o f:ms32.c r:47pie2 c:47pie2
//SET: desertwr
		DRIVER(desertwr) //t:desertwr f:ms32.c r: c:
//SET: gametngk
		DRIVER(gametngk) //t:gametngk f:ms32.c r: c:
//SET: tetrisp
		DRIVER(tetrisp) //t:tetrisp f:ms32.c r: c:
//SET: p47aces
		DRIVER(p47aces) //t:p47aces f:ms32.c r: c:
//SET: akiss
		DRIVER(akiss) //t:akiss f:ms32.c r: c:
//SET: gratia
		DRIVER(gratia) //t:gratia f:ms32.c r: c:
		DRIVER(gratiaa) //t:gratiaa f:ms32.c r:gratia c:gratia
//SET: kirarast
		DRIVER(kirarast) //t:kirarast f:ms32.c r: c:
//SET: wpksocv2
		DRIVER(wpksocv2) //t:wpksocv2 f:ms32.c r: c:
//SET: f1superb
		DRIVER(f1superb) //t:f1superb f:ms32.c r: c:
//SET: bnstars1
		DRIVER(bnstars1) //t:bnstars1 f:bnstars.c r: c:
		DRIVER(bnstars) //t:bnstars f:ms32.c r:bnstars1 c:bnstars1
//SET: rabiolep
		DRIVER(rabiolep) //t:rabiolep f:rpunch.c r: c:
		DRIVER(rpunch) //t:rpunch f:rpunch.c r:rabiolep c:rabiolep
//SET: svolley
		DRIVER(svolley) //t:svolley f:rpunch.c r: c:
		DRIVER(svolleyk) //t:svolleyk f:rpunch.c r:svolley c:svolley
		DRIVER(svolleyu) //t:svolleyu f:rpunch.c r:svolley c:svolley
//SET: tail2nos
		DRIVER(tail2nos) //t:tail2nos f:tail2nos.c r: c:
		DRIVER(sformula) //t:sformula f:tail2nos.c r:tail2nos c:tail2nos
//SET: ojankoc
		DRIVER(ojankoc) //t:ojankoc f:ojankohs.c r: c:
//SET: ojankoy
		DRIVER(ojankoy) //t:ojankoy f:ojankohs.c r: c:
//SET: ojanko2
		DRIVER(ojanko2) //t:ojanko2 f:ojankohs.c r: c:
//SET: ccasino
		DRIVER(ccasino) //t:ccasino f:ojankohs.c r: c:
//SET: ojankohs
		DRIVER(ojankohs) //t:ojankohs f:ojankohs.c r: c:
//SET: nekkyoku
		DRIVER(nekkyoku) //t:nekkyoku f:fromance.c r: c:
//SET: idolmj
		DRIVER(idolmj) //t:idolmj f:fromance.c r: c:
//SET: mjnatsu
		DRIVER(mjnatsu) //t:mjnatsu f:fromance.c r: c:
		DRIVER(natsuiro) //t:natsuiro f:fromance.c r:mjnatsu c:mjnatsu
//SET: mfunclub
		DRIVER(mfunclub) //t:mfunclub f:fromance.c r: c:
//SET: daiyogen
		DRIVER(daiyogen) //t:daiyogen f:fromance.c r: c:
//SET: nmsengen
		DRIVER(nmsengen) //t:nmsengen f:fromance.c r: c:
//SET: fromance
		DRIVER(fromance) //t:fromance f:fromance.c r: c:
//SET: pipedrm
		DRIVER(pipedrm) //t:pipedrm f:pipedrm.c r: c:
		DRIVER(pipedrmu) //t:pipedrmu f:pipedrm.c r:pipedrm c:pipedrm
		DRIVER(pipedrmj) //t:pipedrmj f:pipedrm.c r:pipedrm c:pipedrm
//SET: hatris
		DRIVER(hatris) //t:hatris f:pipedrm.c r: c:
		DRIVER(hatrisj) //t:hatrisj f:pipedrm.c r:hatris c:hatris
//SET: spinlbrk
		DRIVER(spinlbrk) //t:spinlbrk f:aerofgt.c r: c:
		DRIVER(spinlbrku) //t:spinlbrku f:aerofgt.c r:spinlbrk c:spinlbrk
		DRIVER(spinlbrkj) //t:spinlbrkj f:aerofgt.c r:spinlbrk c:spinlbrk
//SET: pspikes
		DRIVER(pspikes) //t:pspikes f:aerofgt.c r: c:
		DRIVER(pspikesk) //t:pspikesk f:aerofgt.c r:pspikes c:pspikes
		DRIVER(svolly91) //t:svolly91 f:aerofgt.c r:pspikes c:pspikes
		DRIVER(pspikesb) //t:pspikesb f:aerofgt.c r:pspikes c:pspikes
		DRIVER(spikes91) //t:spikes91 f:aerofgt.c r:pspikes c:pspikes
		DRIVER(pspikesc) //t:pspikesc f:aerofgt.c r:pspikes c:pspikes
//SET: karatblz
		DRIVER(karatblz) //t:karatblz f:aerofgt.c r: c:
		DRIVER(karatblzu) //t:karatblzu f:aerofgt.c r:karatblz c:karatblz
		DRIVER(karatblzj) //t:karatblzj f:aerofgt.c r:karatblz c:karatblz
//SET: turbofrc
		DRIVER(turbofrc) //t:turbofrc f:aerofgt.c r: c:
//SET: aerofgt
		DRIVER(aerofgt) //t:aerofgt f:aerofgt.c r: c:
		DRIVER(aerofgtb) //t:aerofgtb f:aerofgt.c r:aerofgt c:aerofgt
		DRIVER(aerofgtc) //t:aerofgtc f:aerofgt.c r:aerofgt c:aerofgt
		DRIVER(sonicwi) //t:sonicwi f:aerofgt.c r:aerofgt c:aerofgt
		DRIVER(aerfboot) //t:aerfboot f:aerofgt.c r:aerofgt c:aerofgt
		DRIVER(aerfboo2) //t:aerfboo2 f:aerofgt.c r:aerofgt c:aerofgt
//SET: wbbc97
		DRIVER(wbbc97) //t:wbbc97 f:aerofgt.c r: c:
//SET: welltris
		DRIVER(welltris) //t:welltris f:welltris.c r: c:
		DRIVER(welltrisj) //t:welltrisj f:welltris.c r:welltris c:welltris
//SET: quiz18k
		DRIVER(quiz18k) //t:quiz18k f:welltris.c r: c:
//SET: f1gp
		DRIVER(f1gp) //t:f1gp f:f1gp.c r: c:
		DRIVER(f1gpb) //t:f1gpb f:f1gp.c r:f1gp c:f1gp
//SET: f1gp2
		DRIVER(f1gp2) //t:f1gp2 f:f1gp.c r: c:
//SET: crshrace
		DRIVER(crshrace) //t:crshrace f:crshrace.c r: c:
		DRIVER(crshrace2) //t:crshrace2 f:crshrace.c r:crshrace c:crshrace
//SET: taotaido
		DRIVER(taotaido) //t:taotaido f:taotaido.c r: c:
		DRIVER(taotaidoa) //t:taotaidoa f:taotaido.c r:taotaido c:taotaido
//SET: gstriker
		DRIVER(gstriker) //t:gstriker f:gstriker.c r: c:
		DRIVER(gstrikera) //t:gstrikera f:gstriker.c r:gstriker c:gstriker
//SET: vgoalsoc
		DRIVER(vgoalsoc) //t:vgoalsoc f:gstriker.c r: c:
		DRIVER(vgoalsca) //t:vgoalsca f:gstriker.c r:vgoalsoc c:vgoalsoc
//SET: twrldc94
		DRIVER(twrldc94) //t:twrldc94 f:gstriker.c r: c:
		DRIVER(twrldc94a) //t:twrldc94a f:gstriker.c r:twrldc94 c:twrldc94
//SET: suprslam
		DRIVER(suprslam) //t:suprslam f:suprslam.c r: c:
//SET: fromanc2
		DRIVER(fromanc2) //t:fromanc2 f:fromanc2.c r: c:
//SET: fromancr
		DRIVER(fromancr) //t:fromancr f:fromanc2.c r: c:
//SET: fromanc4
		DRIVER(fromanc4) //t:fromanc4 f:fromanc2.c r: c:
//SET: inufuku
		DRIVER(inufuku) //t:inufuku f:inufuku.c r: c:
//SET: samuraia
		DRIVER(samuraia) //t:samuraia f:psikyo.c r: c:
		DRIVER(sngkace) //t:sngkace f:psikyo.c r:samuraia c:samuraia
//SET: gunbird
		DRIVER(gunbird) //t:gunbird f:psikyo.c r: c:
		DRIVER(gunbirdk) //t:gunbirdk f:psikyo.c r:gunbird c:gunbird
		DRIVER(gunbirdj) //t:gunbirdj f:psikyo.c r:gunbird c:gunbird
//SET: btlkroad
		DRIVER(btlkroad) //t:btlkroad f:psikyo.c r: c:
//SET: s1945
		DRIVER(s1945) //t:s1945 f:psikyo.c r: c:
		DRIVER(s1945a) //t:s1945a f:psikyo.c r:s1945 c:s1945
		DRIVER(s1945j) //t:s1945j f:psikyo.c r:s1945 c:s1945
		DRIVER(s1945jn) //t:s1945jn f:psikyo.c r:s1945 c:s1945
		DRIVER(s1945bl) //t:s1945bl f:psikyo.c r:s1945 c:s1945
		DRIVER(s1945k) //t:s1945k f:psikyo.c r:s1945 c:s1945
//SET: tengai
		DRIVER(tengai) //t:tengai f:psikyo.c r: c:
		DRIVER(tengaij) //t:tengaij f:psikyo.c r:tengai c:tengai
//SET: s1945ii
		DRIVER(s1945ii) //t:s1945ii f:psikyosh.c r: c:
//SET: soldivid
		DRIVER(soldivid) //t:soldivid f:psikyosh.c r: c:
//SET: sbomber
		DRIVER(sbomber) //t:sbomber f:psikyosh.c r: c:
		DRIVER(sbombera) //t:sbombera f:psikyosh.c r:sbomber c:sbomber
//SET: daraku
		DRIVER(daraku) //t:daraku f:psikyosh.c r: c:
//SET: gunbird2
		DRIVER(gunbird2) //t:gunbird2 f:psikyosh.c r: c:
//SET: s1945iii
		DRIVER(s1945iii) //t:s1945iii f:psikyosh.c r: c:
//SET: dragnblz
		DRIVER(dragnblz) //t:dragnblz f:psikyosh.c r: c:
//SET: tgm2
		DRIVER(tgm2) //t:tgm2 f:psikyosh.c r: c:
		DRIVER(tgm2p) //t:tgm2p f:psikyosh.c r:tgm2 c:tgm2
//SET: gnbarich
		DRIVER(gnbarich) //t:gnbarich f:psikyosh.c r: c:
//SET: mjgtaste
		DRIVER(mjgtaste) //t:mjgtaste f:psikyosh.c r: c:
//SET: hotgmck
		DRIVER(hotgmck) //t:hotgmck f:psikyo4.c r: c:
//SET: hgkairak
		DRIVER(hgkairak) //t:hgkairak f:psikyo4.c r: c:
//SET: hotgmck3
		DRIVER(hotgmck3) //t:hotgmck3 f:psikyo4.c r: c:
//SET: hotgm4ev
		DRIVER(hotgm4ev) //t:hotgm4ev f:psikyo4.c r: c:
//SET: hotgmcki
		DRIVER(hotgmcki) //t:hotgmcki f:psikyo4.c r: c:
//SET: loderndf
		DRIVER(loderndf) //t:loderndf f:psikyo4.c r: c:
		DRIVER(loderndfa) //t:loderndfa f:psikyo4.c r:loderndf c:loderndf
//SET: hotdebut
		DRIVER(hotdebut) //t:hotdebut f:psikyo4.c r: c:
//SET: marineb
		DRIVER(marineb) //t:marineb f:marineb.c r: c:
//SET: changes
		DRIVER(changes) //t:changes f:marineb.c r: c:
		DRIVER(changesa) //t:changesa f:marineb.c r:changes c:changes
		DRIVER(looper) //t:looper f:marineb.c r:changes c:changes
//SET: springer
		DRIVER(springer) //t:springer f:marineb.c r: c:
//SET: hoccer
		DRIVER(hoccer) //t:hoccer f:marineb.c r: c:
		DRIVER(hoccer2) //t:hoccer2 f:marineb.c r:hoccer c:hoccer
//SET: bcruzm12
		DRIVER(bcruzm12) //t:bcruzm12 f:marineb.c r: c:
//SET: hopprobo
		DRIVER(hopprobo) //t:hopprobo f:marineb.c r: c:
//SET: wanted
		DRIVER(wanted) //t:wanted f:marineb.c r: c:
//SET: funkybee
		DRIVER(funkybee) //t:funkybee f:funkybee.c r: c:
		DRIVER(funkybeeb) //t:funkybeeb f:funkybee.c r:funkybee c:funkybee
//SET: skylancr
		DRIVER(skylancr) //t:skylancr f:funkybee.c r: c:
		DRIVER(skylancre) //t:skylancre f:funkybee.c r:skylancr c:skylancr
//SET: zodiack
		DRIVER(zodiack) //t:zodiack f:zodiack.c r: c:
//SET: dogfight
		DRIVER(dogfight) //t:dogfight f:zodiack.c r: c:
//SET: moguchan
		DRIVER(moguchan) //t:moguchan f:zodiack.c r: c:
//SET: percuss
		DRIVER(percuss) //t:percuss f:zodiack.c r: c:
//SET: bounty
		DRIVER(bounty) //t:bounty f:zodiack.c r: c:
//SET: espial
		DRIVER(espial) //t:espial f:espial.c r: c:
		DRIVER(espialu) //t:espialu f:espial.c r:espial c:espial
//SET: netwars
		DRIVER(netwars) //t:netwars f:espial.c r: c:
//SET: vastar
		DRIVER(vastar) //t:vastar f:vastar.c r: c:
		DRIVER(vastar2) //t:vastar2 f:vastar.c r:vastar c:vastar
//SET: mastboy
		DRIVER(mastboy) //t:mastboy f:mastboy.c r: c:
		DRIVER(mastboyi) //t:mastboyi f:mastboy.c r:mastboy c:mastboy
//SET: xorworld
		DRIVER(xorworld) //t:xorworld f:xorworld.c r: c:
//SET: bigkarnk
		DRIVER(bigkarnk) //t:bigkarnk f:gaelco.c r: c:
//SET: splash
		DRIVER(splash) //t:splash f:splash.c r: c:
		DRIVER(splash10) //t:splash10 f:splash.c r:splash c:splash
		DRIVER(paintlad) //t:paintlad f:splash.c r:splash c:splash
//SET: roldfrog
		DRIVER(roldfrog) //t:roldfrog f:splash.c r: c:
		DRIVER(roldfroga) //t:roldfroga f:splash.c r:roldfrog c:roldfrog
//SET: rebus
		DRIVER(rebus) //t:rebus f:splash.c r: c:
//SET: funystrp
		DRIVER(funystrp) //t:funystrp f:splash.c r: c:
		DRIVER(puckpepl) //t:puckpepl f:splash.c r:funystrp c:funystrp
//SET: thoop
		DRIVER(thoop) //t:thoop f:gaelco.c r: c:
//SET: squash
		DRIVER(squash) //t:squash f:gaelco.c r: c:
//SET: wrally
		DRIVER(wrally) //t:wrally f:wrally.c r: c:
		DRIVER(wrallya) //t:wrallya f:wrally.c r:wrally c:wrally
		DRIVER(wrallyb) //t:wrallyb f:wrally.c r:wrally c:wrally
//SET: glass
		DRIVER(glass) //t:glass f:glass.c r: c:
		DRIVER(glass10) //t:glass10 f:glass.c r:glass c:glass
		DRIVER(glassbrk) //t:glassbrk f:glass.c r:glass c:glass
//SET: targeth
		DRIVER(targeth) //t:targeth f:targeth.c r: c:
		DRIVER(targetha) //t:targetha f:targeth.c r:targeth c:targeth
//SET: thoop2
		DRIVER(thoop2) //t:thoop2 f:thoop2.c r: c:
//SET: aligator
		DRIVER(aligator) //t:aligator f:gaelco2.c r: c:
		DRIVER(aligatorun) //t:aligatorun f:gaelco2.c r:aligator c:aligator
//SET: biomtoy
		DRIVER(biomtoy) //t:biomtoy f:gaelco.c r: c:
//SET: touchgo
		DRIVER(touchgo) //t:touchgo f:gaelco2.c r: c:
		DRIVER(touchgon) //t:touchgon f:gaelco2.c r:touchgo c:touchgo
		DRIVER(touchgoe) //t:touchgoe f:gaelco2.c r:touchgo c:touchgo
//SET: wrally2
		DRIVER(wrally2) //t:wrally2 f:gaelco2.c r: c:
//SET: maniacsq
		DRIVER(maniacsq) //t:maniacsq f:gaelco2.c r: c:
		DRIVER(maniacsp) //t:maniacsp f:gaelco.c r:maniacsq c:maniacsq
//SET: snowboar
		DRIVER(snowboar) //t:snowboar f:gaelco2.c r: c:
		DRIVER(snowboara) //t:snowboara f:gaelco2.c r:snowboar c:snowboar
//SET: bang
		DRIVER(bang) //t:bang f:gaelco2.c r: c:
		DRIVER(bangj) //t:bangj f:gaelco2.c r:bang c:bang
//SET: grtesoro
		DRIVER(grtesoro) //t:grtesoro f:gaelco2.c r: c:
		DRIVER(grtesoro4) //t:grtesoro4 f:gaelco2.c r:grtesoro c:grtesoro
//SET: speedup
		DRIVER(speedup) //t:speedup f:gaelco3d.c r: c:
//SET: surfplnt
		DRIVER(surfplnt) //t:surfplnt f:gaelco3d.c r: c:
		DRIVER(surfplnt40) //t:surfplnt40 f:gaelco3d.c r:surfplnt c:surfplnt
//SET: radikalb
		DRIVER(radikalb) //t:radikalb f:gaelco3d.c r: c:
//SET: atvtrack
		DRIVER(atvtrack) //t:atvtrack f:atvtrack.c r: c:
		DRIVER(atvtracka) //t:atvtracka f:atvtrack.c r:atvtrack c:atvtrack
//SET: tokyocop
		DRIVER(tokyocop) //t:tokyocop f:tokyocop.c r: c:
//SET: hvyunit
		DRIVER(hvyunit) //t:hvyunit f:hvyunit.c r: c:
		DRIVER(hvyunitj) //t:hvyunitj f:hvyunit.c r:hvyunit c:hvyunit
		DRIVER(hvyunitjo) //t:hvyunitjo f:hvyunit.c r:hvyunit c:hvyunit
		DRIVER(hvyunitu) //t:hvyunitu f:hvyunit.c r:hvyunit c:hvyunit
//SET: djboy
		DRIVER(djboy) //t:djboy f:djboy.c r: c:
		DRIVER(djboyj) //t:djboyj f:djboy.c r:djboy c:djboy
		DRIVER(djboya) //t:djboya f:djboy.c r:djboy c:djboy
//SET: airbustr
		DRIVER(airbustr) //t:airbustr f:airbustr.c r: c:
		DRIVER(airbustrj) //t:airbustrj f:airbustr.c r:airbustr c:airbustr
		DRIVER(airbustrb) //t:airbustrb f:airbustr.c r:airbustr c:airbustr
//SET: galpanic
		DRIVER(galpanic) //t:galpanic f:galpanic.c r: c:
		DRIVER(galpanica) //t:galpanica f:galpanic.c r:galpanic c:galpanic
//SET: galsnew
		DRIVER(galsnew) //t:galsnew f:expro02.c r: c:
		DRIVER(galsnewa) //t:galsnewa f:expro02.c r:galsnew c:galsnew
		DRIVER(galsnewj) //t:galsnewj f:expro02.c r:galsnew c:galsnew
		DRIVER(galsnewk) //t:galsnewk f:expro02.c r:galsnew c:galsnew
//SET: galpani2
		DRIVER(galpani2) //t:galpani2 f:galpani2.c r: c:
		DRIVER(galpani2g) //t:galpani2g f:galpani2.c r:galpani2 c:galpani2
		DRIVER(galpani2t) //t:galpani2t f:galpani2.c r:galpani2 c:galpani2
		DRIVER(galpani2i) //t:galpani2i f:galpani2.c r:galpani2 c:galpani2
		DRIVER(galpani2j) //t:galpani2j f:galpani2.c r:galpani2 c:galpani2
//SET: gp2quiz
		DRIVER(gp2quiz) //t:gp2quiz f:galpani2.c r: c:
//SET: gp2se
		DRIVER(gp2se) //t:gp2se f:galpani2.c r: c:
//SET: jchan
		DRIVER(jchan) //t:jchan f:jchan.c r: c:
//SET: jchan2
		DRIVER(jchan2) //t:jchan2 f:jchan.c r: c:
//SET: galpani3
		DRIVER(galpani3) //t:galpani3 f:galpani3.c r: c:
//SET: berlwall
		DRIVER(berlwall) //t:berlwall f:kaneko16.c r: c:
		DRIVER(berlwallt) //t:berlwallt f:kaneko16.c r:berlwall c:berlwall
//SET: mgcrystl
		DRIVER(mgcrystl) //t:mgcrystl f:kaneko16.c r: c:
		DRIVER(mgcrystlo) //t:mgcrystlo f:kaneko16.c r:mgcrystl c:mgcrystl
		DRIVER(mgcrystlj) //t:mgcrystlj f:kaneko16.c r:mgcrystl c:mgcrystl
//SET: blazeon
		DRIVER(blazeon) //t:blazeon f:kaneko16.c r: c:
//SET: sandscrp
		DRIVER(sandscrp) //t:sandscrp f:sandscrp.c r: c:
		DRIVER(sandscrpa) //t:sandscrpa f:sandscrp.c r:sandscrp c:sandscrp
		DRIVER(sandscrpb) //t:sandscrpb f:sandscrp.c r:sandscrp c:sandscrp
//SET: explbrkr
		DRIVER(explbrkr) //t:explbrkr f:kaneko16.c r: c:
		DRIVER(bakubrkr) //t:bakubrkr f:kaneko16.c r:explbrkr c:explbrkr
//SET: shogwarr
		DRIVER(shogwarr) //t:shogwarr f:kaneko16.c r: c:
		DRIVER(shogwarru) //t:shogwarru f:kaneko16.c r:shogwarr c:shogwarr
		DRIVER(fjbuster) //t:fjbuster f:kaneko16.c r:shogwarr c:shogwarr
//SET: brapboys
		DRIVER(brapboys) //t:brapboys f:kaneko16.c r: c:
		DRIVER(brapboysj) //t:brapboysj f:kaneko16.c r:brapboys c:brapboys
//SET: bloodwar
		DRIVER(bloodwar) //t:bloodwar f:kaneko16.c r: c:
		DRIVER(oedfight) //t:oedfight f:kaneko16.c r:bloodwar c:bloodwar
//SET: bonkadv
		DRIVER(bonkadv) //t:bonkadv f:kaneko16.c r: c:
//SET: gtmr
		DRIVER(gtmr) //t:gtmr f:kaneko16.c r: c:
		DRIVER(gtmra) //t:gtmra f:kaneko16.c r:gtmr c:gtmr
		DRIVER(gtmre) //t:gtmre f:kaneko16.c r:gtmr c:gtmr
		DRIVER(gtmrusa) //t:gtmrusa f:kaneko16.c r:gtmr c:gtmr
//SET: gtmr2
		DRIVER(gtmr2) //t:gtmr2 f:kaneko16.c r: c:
		DRIVER(gtmr2a) //t:gtmr2a f:kaneko16.c r:gtmr2 c:gtmr2
		DRIVER(gtmr2u) //t:gtmr2u f:kaneko16.c r:gtmr2 c:gtmr2
//SET: skns
		DRIVER(skns) //t:skns f:suprnova.c r: c:
//SET: galpani4
		DRIVER(galpani4) //t:galpani4 f:suprnova.c r:skns c:
		DRIVER(galpani4k) //t:galpani4k f:suprnova.c r:galpani4 c:galpani4
//SET: jjparads
		DRIVER(jjparads) //t:jjparads f:suprnova.c r:skns c:
//SET: vblokbrk
		DRIVER(vblokbrk) //t:vblokbrk f:suprnova.c r:skns c:
		DRIVER(sarukani) //t:sarukani f:suprnova.c r:vblokbrk c:vblokbrk
//SET: galpanis
		DRIVER(galpanis) //t:galpanis f:suprnova.c r:skns c:
		DRIVER(galpanisk) //t:galpanisk f:suprnova.c r:galpanis c:galpanis
//SET: sengekis
		DRIVER(sengekis) //t:sengekis f:suprnova.c r:skns c:
		DRIVER(sengekisj) //t:sengekisj f:suprnova.c r:sengekis c:sengekis
//SET: jjparad2
		DRIVER(jjparad2) //t:jjparad2 f:suprnova.c r:skns c:
//SET: cyvern
		DRIVER(cyvern) //t:cyvern f:suprnova.c r:skns c:
		DRIVER(cyvernj) //t:cyvernj f:suprnova.c r:cyvern c:cyvern
//SET: ryouran
		DRIVER(ryouran) //t:ryouran f:suprnova.c r:skns c:
//SET: puzzloop
		DRIVER(puzzloop) //t:puzzloop f:suprnova.c r:skns c:
		DRIVER(puzzloopj) //t:puzzloopj f:suprnova.c r:puzzloop c:puzzloop
		DRIVER(puzzloopa) //t:puzzloopa f:suprnova.c r:puzzloop c:puzzloop
		DRIVER(puzzloopk) //t:puzzloopk f:suprnova.c r:puzzloop c:puzzloop
		DRIVER(puzzloopu) //t:puzzloopu f:suprnova.c r:puzzloop c:puzzloop
//SET: galpans2
		DRIVER(galpans2) //t:galpans2 f:suprnova.c r:skns c:
		DRIVER(galpans2a) //t:galpans2a f:suprnova.c r:galpans2 c:galpans2
		DRIVER(galpansu) //t:galpansu f:suprnova.c r:galpans2 c:galpans2
//SET: senknow
		DRIVER(senknow) //t:senknow f:suprnova.c r:skns c:
//SET: panicstr
		DRIVER(panicstr) //t:panicstr f:suprnova.c r:skns c:
//SET: teljan
		DRIVER(teljan) //t:teljan f:suprnova.c r:skns c:
//SET: gutsn
		DRIVER(gutsn) //t:gutsn f:suprnova.c r:skns c:
//SET: galpans3
		DRIVER(galpans3) //t:galpans3 f:suprnova.c r:skns c:
//SET: hanaawas
		DRIVER(hanaawas) //t:hanaawas f:hanaawas.c r: c:
//SET: speedatk
		DRIVER(speedatk) //t:speedatk f:speedatk.c r: c:
//SET: srmp1
		DRIVER(srmp1) //t:srmp1 f:srmp2.c r: c:
//SET: srmp2
		DRIVER(srmp2) //t:srmp2 f:srmp2.c r: c:
//SET: srmp3
		DRIVER(srmp3) //t:srmp3 f:srmp2.c r: c:
		DRIVER(rmgoldyh) //t:rmgoldyh f:srmp2.c r:srmp3 c:srmp3
//SET: mjyuugi
		DRIVER(mjyuugi) //t:mjyuugi f:srmp2.c r: c:
		DRIVER(mjyuugia) //t:mjyuugia f:srmp2.c r:mjyuugi c:mjyuugi
//SET: ponchin
		DRIVER(ponchin) //t:ponchin f:srmp2.c r: c:
		DRIVER(ponchina) //t:ponchina f:srmp2.c r:ponchin c:ponchin
//SET: tndrcade
		DRIVER(tndrcade) //t:tndrcade f:seta.c r: c:
		DRIVER(tndrcadej) //t:tndrcadej f:seta.c r:tndrcade c:tndrcade
//SET: twineagl
		DRIVER(twineagl) //t:twineagl f:seta.c r: c:
//SET: downtown
		DRIVER(downtown) //t:downtown f:seta.c r: c:
		DRIVER(downtown2) //t:downtown2 f:seta.c r:downtown c:downtown
		DRIVER(downtownj) //t:downtownj f:seta.c r:downtown c:downtown
		DRIVER(downtownp) //t:downtownp f:seta.c r:downtown c:downtown
//SET: usclssic
		DRIVER(usclssic) //t:usclssic f:seta.c r: c:
//SET: calibr50
		DRIVER(calibr50) //t:calibr50 f:seta.c r: c:
//SET: arbalest
		DRIVER(arbalest) //t:arbalest f:seta.c r: c:
//SET: metafox
		DRIVER(metafox) //t:metafox f:seta.c r: c:
//SET: setaroul
		DRIVER(setaroul) //t:setaroul f:seta.c r: c:
//SET: drgnunit
		DRIVER(drgnunit) //t:drgnunit f:seta.c r: c:
//SET: wits
		DRIVER(wits) //t:wits f:seta.c r: c:
//SET: thunderl
		DRIVER(thunderl) //t:thunderl f:seta.c r: c:
		DRIVER(thunderlbl) //t:thunderlbl f:seta.c r:thunderl c:thunderl
//SET: wiggie
		DRIVER(wiggie) //t:wiggie f:seta.c r: c:
		DRIVER(superbar) //t:superbar f:seta.c r:wiggie c:wiggie
//SET: jockeyc
		DRIVER(jockeyc) //t:jockeyc f:seta.c r: c:
		DRIVER(inttoote) //t:inttoote f:seta.c r:jockeyc c:jockeyc
		DRIVER(inttootea) //t:inttootea f:seta.c r:jockeyc c:jockeyc
//SET: rezon
		DRIVER(rezon) //t:rezon f:seta.c r: c:
		DRIVER(rezont) //t:rezont f:seta.c r:rezon c:rezon
//SET: stg
		DRIVER(stg) //t:stg f:seta.c r: c:
//SET: pairlove
		DRIVER(pairlove) //t:pairlove f:seta.c r: c:
//SET: blandia
		DRIVER(blandia) //t:blandia f:seta.c r: c:
		DRIVER(blandiap) //t:blandiap f:seta.c r:blandia c:blandia
//SET: blockcar
		DRIVER(blockcar) //t:blockcar f:seta.c r: c:
//SET: qzkklogy
		DRIVER(qzkklogy) //t:qzkklogy f:seta.c r: c:
//SET: neobattl
		DRIVER(neobattl) //t:neobattl f:seta.c r: c:
//SET: umanclub
		DRIVER(umanclub) //t:umanclub f:seta.c r: c:
//SET: zingzip
		DRIVER(zingzip) //t:zingzip f:seta.c r: c:
		DRIVER(zingzipbl) //t:zingzipbl f:seta.c r:zingzip c:zingzip
//SET: atehate
		DRIVER(atehate) //t:atehate f:seta.c r: c:
//SET: jjsquawk
		DRIVER(jjsquawk) //t:jjsquawk f:seta.c r: c:
		DRIVER(jjsquawkb) //t:jjsquawkb f:seta.c r:jjsquawk c:jjsquawk
//SET: kamenrid
		DRIVER(kamenrid) //t:kamenrid f:seta.c r: c:
//SET: madshark
		DRIVER(madshark) //t:madshark f:seta.c r: c:
//SET: msgundam
		DRIVER(msgundam) //t:msgundam f:seta.c r: c:
		DRIVER(msgundam1) //t:msgundam1 f:seta.c r:msgundam c:msgundam
//SET: daioh
		DRIVER(daioh) //t:daioh f:seta.c r: c:
//SET: oisipuzl
		DRIVER(oisipuzl) //t:oisipuzl f:seta.c r: c:
		DRIVER(triplfun) //t:triplfun f:seta.c r:oisipuzl c:oisipuzl
//SET: utoukond
		DRIVER(utoukond) //t:utoukond f:seta.c r: c:
//SET: qzkklgy2
		DRIVER(qzkklgy2) //t:qzkklgy2 f:seta.c r: c:
//SET: wrofaero
		DRIVER(wrofaero) //t:wrofaero f:seta.c r: c:
//SET: eightfrc
		DRIVER(eightfrc) //t:eightfrc f:seta.c r: c:
//SET: kiwame
		DRIVER(kiwame) //t:kiwame f:seta.c r: c:
//SET: krzybowl
		DRIVER(krzybowl) //t:krzybowl f:seta.c r: c:
//SET: orbs
		DRIVER(orbs) //t:orbs f:seta.c r: c:
//SET: keroppi
		DRIVER(keroppi) //t:keroppi f:seta.c r: c:
//SET: extdwnhl
		DRIVER(extdwnhl) //t:extdwnhl f:seta.c r: c:
//SET: gundhara
		DRIVER(gundhara) //t:gundhara f:seta.c r: c:
//SET: sokonuke
		DRIVER(sokonuke) //t:sokonuke f:seta.c r: c:
//SET: zombraid
		DRIVER(zombraid) //t:zombraid f:seta.c r: c:
//SET: crazyfgt
		DRIVER(crazyfgt) //t:crazyfgt f:seta.c r: c:
//SET: gundamex
		DRIVER(gundamex) //t:gundamex f:seta2.c r: c:
//SET: grdians
		DRIVER(grdians) //t:grdians f:seta2.c r: c:
//SET: mj4simai
		DRIVER(mj4simai) //t:mj4simai f:seta2.c r: c:
//SET: myangel
		DRIVER(myangel) //t:myangel f:seta2.c r: c:
//SET: myangel2
		DRIVER(myangel2) //t:myangel2 f:seta2.c r: c:
//SET: pzlbowl
		DRIVER(pzlbowl) //t:pzlbowl f:seta2.c r: c:
//SET: penbros
		DRIVER(penbros) //t:penbros f:seta2.c r: c:
//SET: deerhunt
		DRIVER(deerhunt) //t:deerhunt f:seta2.c r: c:
		DRIVER(deerhunta) //t:deerhunta f:seta2.c r:deerhunt c:deerhunt
		DRIVER(deerhuntb) //t:deerhuntb f:seta2.c r:deerhunt c:deerhunt
		DRIVER(deerhuntc) //t:deerhuntc f:seta2.c r:deerhunt c:deerhunt
//SET: turkhunt
		DRIVER(turkhunt) //t:turkhunt f:seta2.c r: c:
//SET: wschamp
		DRIVER(wschamp) //t:wschamp f:seta2.c r: c:
		DRIVER(wschampa) //t:wschampa f:seta2.c r:wschamp c:wschamp
//SET: funcube2
		DRIVER(funcube2) //t:funcube2 f:seta2.c r: c:
//SET: funcube4
		DRIVER(funcube4) //t:funcube4 f:seta2.c r: c:
//SET: trophyh
		DRIVER(trophyh) //t:trophyh f:seta2.c r: c:
//SET: reelquak
		DRIVER(reelquak) //t:reelquak f:seta2.c r: c:
//SET: srmp4
		DRIVER(srmp4) //t:srmp4 f:ssv.c r: c:
		DRIVER(srmp4o) //t:srmp4o f:ssv.c r:srmp4 c:srmp4
//SET: twineag2
		DRIVER(twineag2) //t:twineag2 f:ssv.c r: c:
//SET: srmp7
		DRIVER(srmp7) //t:srmp7 f:ssv.c r: c:
//SET: dynagear
		DRIVER(dynagear) //t:dynagear f:ssv.c r: c:
//SET: survarts
		DRIVER(survarts) //t:survarts f:ssv.c r: c:
		DRIVER(survartsu) //t:survartsu f:ssv.c r:survarts c:survarts
//SET: eaglshot
		DRIVER(eaglshot) //t:eaglshot f:ssv.c r: c:
//SET: hypreact
		DRIVER(hypreact) //t:hypreact f:ssv.c r: c:
//SET: meosism
		DRIVER(meosism) //t:meosism f:ssv.c r: c:
//SET: hypreac2
		DRIVER(hypreac2) //t:hypreac2 f:ssv.c r: c:
//SET: sxyreact
		DRIVER(sxyreact) //t:sxyreact f:ssv.c r: c:
//SET: sxyreac2
		DRIVER(sxyreac2) //t:sxyreac2 f:ssv.c r: c:
//SET: cairblad
		DRIVER(cairblad) //t:cairblad f:ssv.c r: c:
//SET: keithlcy
		DRIVER(keithlcy) //t:keithlcy f:ssv.c r: c:
//SET: drifto94
		DRIVER(drifto94) //t:drifto94 f:ssv.c r: c:
//SET: janjans1
		DRIVER(janjans1) //t:janjans1 f:ssv.c r: c:
//SET: stmblade
		DRIVER(stmblade) //t:stmblade f:ssv.c r: c:
//SET: jsk
		DRIVER(jsk) //t:jsk f:ssv.c r: c:
//SET: koikois2
		DRIVER(koikois2) //t:koikois2 f:ssv.c r: c:
//SET: mslider
		DRIVER(mslider) //t:mslider f:ssv.c r: c:
//SET: ryorioh
		DRIVER(ryorioh) //t:ryorioh f:ssv.c r: c:
//SET: janjans2
		DRIVER(janjans2) //t:janjans2 f:ssv.c r: c:
//SET: vasara
		DRIVER(vasara) //t:vasara f:ssv.c r: c:
//SET: vasara2
		DRIVER(vasara2) //t:vasara2 f:ssv.c r: c:
		DRIVER(vasara2a) //t:vasara2a f:ssv.c r:vasara2 c:vasara2
//SET: ultrax
		DRIVER(ultrax) //t:ultrax f:ssv.c r: c:
//SET: gdfs
		DRIVER(gdfs) //t:gdfs f:ssv.c r: c:
//SET: jclub2
		DRIVER(jclub2) //t:jclub2 f:darkhors.c r: c:
		DRIVER(jclub2o) //t:jclub2o f:darkhors.c r:jclub2 c:jclub2
		DRIVER(darkhors) //t:darkhors f:darkhors.c r:jclub2 c:jclub2
//SET: renju
		DRIVER(renju) //t:renju f:st0016.c r: c:
//SET: koikois
		DRIVER(koikois) //t:koikois f:st0016.c r: c:
//SET: nratechu
		DRIVER(nratechu) //t:nratechu f:st0016.c r: c:
//SET: dcrown
		DRIVER(dcrown) //t:dcrown f:st0016.c r: c:
//SET: srmp5
		DRIVER(srmp5) //t:srmp5 f:srmp5.c r: c:
//SET: speglsht
		DRIVER(speglsht) //t:speglsht f:speglsht.c r: c:
//SET: mayjinsn
		DRIVER(mayjinsn) //t:mayjinsn f:st0016.c r: c:
//SET: mayjisn2
		DRIVER(mayjisn2) //t:mayjisn2 f:st0016.c r: c:
//SET: srmp6
		DRIVER(srmp6) //t:srmp6 f:srmp6.c r: c:
//SET: aleck64
		DRIVER(aleck64) //t:aleck64 f:aleck64.c r: c:
//SET: 11beat
		DRIVER(11beat) //t:11beat f:aleck64.c r:aleck64 c:
//SET: mtetrisc
		DRIVER(mtetrisc) //t:mtetrisc f:aleck64.c r:aleck64 c:
//SET: starsldr
		DRIVER(starsldr) //t:starsldr f:aleck64.c r:aleck64 c:
//SET: vivdolls
		DRIVER(vivdolls) //t:vivdolls f:aleck64.c r:aleck64 c:
//SET: srmvs
		DRIVER(srmvs) //t:srmvs f:aleck64.c r:aleck64 c:
//SET: twrshaft
		DRIVER(twrshaft) //t:twrshaft f:aleck64.c r:aleck64 c:
//SET: hipai
		DRIVER(hipai) //t:hipai f:aleck64.c r:aleck64 c:
//SET: doncdoon
		DRIVER(doncdoon) //t:doncdoon f:aleck64.c r:aleck64 c:
//SET: kurufev
		DRIVER(kurufev) //t:kurufev f:aleck64.c r:aleck64 c:
//SET: mayjin3
		DRIVER(mayjin3) //t:mayjin3 f:aleck64.c r:aleck64 c:
//SET: powerins
		DRIVER(powerins) //t:powerins f:powerins.c r: c:
		DRIVER(powerinsj) //t:powerinsj f:powerins.c r:powerins c:powerins
		DRIVER(powerinsa) //t:powerinsa f:powerins.c r:powerins c:powerins
		DRIVER(powerinsb) //t:powerinsb f:powerins.c r:powerins c:powerins
//SET: ohmygod
		DRIVER(ohmygod) //t:ohmygod f:ohmygod.c r: c:
//SET: naname
		DRIVER(naname) //t:naname f:ohmygod.c r: c:
//SET: blmbycar
		DRIVER(blmbycar) //t:blmbycar f:blmbycar.c r: c:
		DRIVER(blmbycaru) //t:blmbycaru f:blmbycar.c r:blmbycar c:blmbycar
//SET: watrball
		DRIVER(watrball) //t:watrball f:blmbycar.c r: c:
//SET: dai3wksi
		DRIVER(dai3wksi) //t:dai3wksi f:dai3wksi.c r: c:
//SET: speakres
		DRIVER(speakres) //t:speakres f:route16.c r: c:
		DRIVER(speakresb) //t:speakresb f:route16.c r:speakres c:speakres
		DRIVER(stratvox) //t:stratvox f:route16.c r:speakres c:speakres
		DRIVER(stratvoxb) //t:stratvoxb f:route16.c r:speakres c:speakres
		DRIVER(spacecho) //t:spacecho f:route16.c r:speakres c:speakres
		DRIVER(spacecho2) //t:spacecho2 f:route16.c r:speakres c:speakres
//SET: route16
		DRIVER(route16) //t:route16 f:route16.c r: c:
		DRIVER(route16a) //t:route16a f:route16.c r:route16 c:route16
		DRIVER(route16b) //t:route16b f:route16.c r:route16 c:route16
		DRIVER(routex) //t:routex f:route16.c r:route16 c:route16
//SET: ttmahjng
		DRIVER(ttmahjng) //t:ttmahjng f:route16.c r: c:
//SET: fnkyfish
		DRIVER(fnkyfish) //t:fnkyfish f:kangaroo.c r: c:
//SET: kangaroo
		DRIVER(kangaroo) //t:kangaroo f:kangaroo.c r: c:
		DRIVER(kangarooa) //t:kangarooa f:kangaroo.c r:kangaroo c:kangaroo
		DRIVER(kangaroob) //t:kangaroob f:kangaroo.c r:kangaroo c:kangaroo
//SET: arabian
		DRIVER(arabian) //t:arabian f:arabian.c r: c:
		DRIVER(arabiana) //t:arabiana f:arabian.c r:arabian c:arabian
//SET: markham
		DRIVER(markham) //t:markham f:markham.c r: c:
//SET: strnskil
		DRIVER(strnskil) //t:strnskil f:strnskil.c r: c:
		DRIVER(guiness) //t:guiness f:strnskil.c r:strnskil c:strnskil
//SET: banbam
		DRIVER(banbam) //t:banbam f:strnskil.c r: c:
		DRIVER(pettanp) //t:pettanp f:strnskil.c r:banbam c:banbam
//SET: ikki
		DRIVER(ikki) //t:ikki f:ikki.c r: c:
		DRIVER(farmer) //t:farmer f:ikki.c r:ikki c:ikki
//SET: shanghai
		DRIVER(shanghai) //t:shanghai f:shanghai.c r: c:
//SET: shangha2
		DRIVER(shangha2) //t:shangha2 f:shanghai.c r: c:
//SET: kothello
		DRIVER(kothello) //t:kothello f:shanghai.c r: c:
//SET: shangha3
		DRIVER(shangha3) //t:shangha3 f:shangha3.c r: c:
//SET: heberpop
		DRIVER(heberpop) //t:heberpop f:shangha3.c r: c:
//SET: blocken
		DRIVER(blocken) //t:blocken f:shangha3.c r: c:
//SET: goindol
		DRIVER(goindol) //t:goindol f:goindol.c r: c:
		DRIVER(goindolu) //t:goindolu f:goindol.c r:goindol c:goindol
		DRIVER(goindolk) //t:goindolk f:goindol.c r:goindol c:goindol
		DRIVER(homo) //t:homo f:goindol.c r:goindol c:goindol
//SET: sranger
		DRIVER(sranger) //t:sranger f:suna8.c r: c:
		DRIVER(rranger) //t:rranger f:suna8.c r:sranger c:sranger
		DRIVER(srangerb) //t:srangerb f:suna8.c r:sranger c:sranger
		DRIVER(srangerw) //t:srangerw f:suna8.c r:sranger c:sranger
//SET: hardhead
		DRIVER(hardhead) //t:hardhead f:suna8.c r: c:
		DRIVER(hardheadb) //t:hardheadb f:suna8.c r:hardhead c:hardhead
		DRIVER(pop_hh) //t:pop_hh f:suna8.c r:hardhead c:hardhead
//SET: sparkman
		DRIVER(sparkman) //t:sparkman f:suna8.c r: c:
		DRIVER(sparkmana) //t:sparkmana f:suna8.c r:sparkman c:sparkman
//SET: starfigh
		DRIVER(starfigh) //t:starfigh f:suna8.c r: c:
//SET: hardhea2
		DRIVER(hardhea2) //t:hardhea2 f:suna8.c r: c:
//SET: brickzn
		DRIVER(brickzn) //t:brickzn f:suna8.c r: c:
		DRIVER(brickzn3) //t:brickzn3 f:suna8.c r:brickzn c:brickzn
//SET: bestbest
		DRIVER(bestbest) //t:bestbest f:suna16.c r: c:
//SET: sunaq
		DRIVER(sunaq) //t:sunaq f:suna16.c r: c:
//SET: bssoccer
		DRIVER(bssoccer) //t:bssoccer f:suna16.c r: c:
//SET: uballoon
		DRIVER(uballoon) //t:uballoon f:suna16.c r: c:
//SET: gundealr
		DRIVER(gundealr) //t:gundealr f:gundealr.c r: c:
		DRIVER(gundealra) //t:gundealra f:gundealr.c r:gundealr c:gundealr
		DRIVER(gundealrt) //t:gundealrt f:gundealr.c r:gundealr c:gundealr
//SET: yamyam
		DRIVER(yamyam) //t:yamyam f:gundealr.c r: c:
		DRIVER(wiseguy) //t:wiseguy f:gundealr.c r:yamyam c:yamyam
//SET: lastday
		DRIVER(lastday) //t:lastday f:dooyong.c r: c:
		DRIVER(lastdaya) //t:lastdaya f:dooyong.c r:lastday c:lastday
//SET: gulfstrm
		DRIVER(gulfstrm) //t:gulfstrm f:dooyong.c r: c:
		DRIVER(gulfstrmm) //t:gulfstrmm f:dooyong.c r:gulfstrm c:gulfstrm
//SET: pollux
		DRIVER(pollux) //t:pollux f:dooyong.c r: c:
		DRIVER(polluxa) //t:polluxa f:dooyong.c r:pollux c:pollux
		DRIVER(polluxa2) //t:polluxa2 f:dooyong.c r:pollux c:pollux
//SET: flytiger
		DRIVER(flytiger) //t:flytiger f:dooyong.c r: c:
//SET: bluehawk
		DRIVER(bluehawk) //t:bluehawk f:dooyong.c r: c:
		DRIVER(bluehawkn) //t:bluehawkn f:dooyong.c r:bluehawk c:bluehawk
//SET: sadari
		DRIVER(sadari) //t:sadari f:dooyong.c r: c:
//SET: gundl94
		DRIVER(gundl94) //t:gundl94 f:dooyong.c r: c:
		DRIVER(primella) //t:primella f:dooyong.c r:gundl94 c:gundl94
//SET: superx
		DRIVER(superx) //t:superx f:dooyong.c r: c:
		DRIVER(superxm) //t:superxm f:dooyong.c r:superx c:superx
//SET: rshark
		DRIVER(rshark) //t:rshark f:dooyong.c r: c:
//SET: popbingo
		DRIVER(popbingo) //t:popbingo f:dooyong.c r: c:
//SET: leprechn
		DRIVER(leprechn) //t:leprechn f:gameplan.c r: c:
		DRIVER(potogold) //t:potogold f:gameplan.c r:leprechn c:leprechn
		DRIVER(leprechp) //t:leprechp f:gameplan.c r:leprechn c:leprechn
//SET: piratetr
		DRIVER(piratetr) //t:piratetr f:gameplan.c r: c:
//SET: beezer
		DRIVER(beezer) //t:beezer f:beezer.c r: c:
		DRIVER(beezer1) //t:beezer1 f:beezer.c r:beezer c:beezer
//SET: pushman
		DRIVER(pushman) //t:pushman f:pushman.c r: c:
		DRIVER(pushmana) //t:pushmana f:pushman.c r:pushman c:pushman
		DRIVER(pushmans) //t:pushmans f:pushman.c r:pushman c:pushman
		DRIVER(pushmant) //t:pushmant f:pushman.c r:pushman c:pushman
//SET: bballs
		DRIVER(bballs) //t:bballs f:pushman.c r: c:
//SET: zerozone
		DRIVER(zerozone) //t:zerozone f:zerozone.c r: c:
//SET: lvgirl94
		DRIVER(lvgirl94) //t:lvgirl94 f:zerozone.c r: c:
//SET: hotpinbl
		DRIVER(hotpinbl) //t:hotpinbl f:galspnbl.c r: c:
//SET: galspnbl
		DRIVER(galspnbl) //t:galspnbl f:galspnbl.c r: c:
//SET: fantasia
		DRIVER(fantasia) //t:fantasia f:expro02.c r: c:
//SET: supmodel
		DRIVER(supmodel) //t:supmodel f:galpanic.c r: c:
//SET: newfant
		DRIVER(newfant) //t:newfant f:galpanic.c r: c:
//SET: fantsy95
		DRIVER(fantsy95) //t:fantsy95 f:galpanic.c r: c:
//SET: zipzap
		DRIVER(zipzap) //t:zipzap f:galpanic.c r: c:
//SET: missw96
		DRIVER(missw96) //t:missw96 f:galpanic.c r: c:
		DRIVER(missmw96) //t:missmw96 f:galpanic.c r:missw96 c:missw96
//SET: fantsia2
		DRIVER(fantsia2) //t:fantsia2 f:galpanic.c r: c:
		DRIVER(fantsia2a) //t:fantsia2a f:galpanic.c r:fantsia2 c:fantsia2
//SET: wownfant
		DRIVER(wownfant) //t:wownfant f:galpanic.c r: c:
//SET: galhustl
		DRIVER(galhustl) //t:galhustl f:galpanic.c r: c:
//SET: sslam
		DRIVER(sslam) //t:sslam f:sslam.c r: c:
		DRIVER(sslama) //t:sslama f:sslam.c r:sslam c:sslam
//SET: powerbal
		DRIVER(powerbal) //t:powerbal f:powerbal.c r: c:
		DRIVER(powerbals) //t:powerbals f:sslam.c r:powerbal c:powerbal
//SET: magicstk
		DRIVER(magicstk) //t:magicstk f:powerbal.c r: c:
//SET: bigtwin
		DRIVER(bigtwin) //t:bigtwin f:playmark.c r: c:
		DRIVER(bigtwinb) //t:bigtwinb f:playmark.c r:bigtwin c:bigtwin
//SET: wbeachvl
		DRIVER(wbeachvl) //t:wbeachvl f:playmark.c r: c:
		DRIVER(wbeachvl2) //t:wbeachvl2 f:playmark.c r:wbeachvl c:wbeachvl
//SET: excelsr
		DRIVER(excelsr) //t:excelsr f:playmark.c r: c:
//SET: hotmind
		DRIVER(hotmind) //t:hotmind f:playmark.c r: c:
		DRIVER(hotminda) //t:hotminda f:powerbal.c r:hotmind c:hotmind
//SET: hrdtimes
		DRIVER(hrdtimes) //t:hrdtimes f:playmark.c r: c:
		DRIVER(hrdtimesa) //t:hrdtimesa f:playmark.c r:hrdtimes c:hrdtimes
//SET: drtomy
		DRIVER(drtomy) //t:drtomy f:drtomy.c r: c:
//SET: sderby
		DRIVER(sderby) //t:sderby f:sderby.c r: c:
//SET: pmroulet
		DRIVER(pmroulet) //t:pmroulet f:sderby.c r: c:
//SET: spacewin
		DRIVER(spacewin) //t:spacewin f:sderby.c r: c:
//SET: sharkatt
		DRIVER(sharkatt) //t:sharkatt f:thief.c r: c:
//SET: thief
		DRIVER(thief) //t:thief f:thief.c r: c:
//SET: natodef
		DRIVER(natodef) //t:natodef f:thief.c r: c:
		DRIVER(natodefa) //t:natodefa f:thief.c r:natodef c:natodef
//SET: mrflea
		DRIVER(mrflea) //t:mrflea f:mrflea.c r: c:
//SET: ambush
		DRIVER(ambush) //t:ambush f:ambush.c r: c:
		DRIVER(ambushj) //t:ambushj f:ambush.c r:ambush c:ambush
		DRIVER(ambushv) //t:ambushv f:ambush.c r:ambush c:ambush
//SET: holeland
		DRIVER(holeland) //t:holeland f:holeland.c r: c:
//SET: crzrally
		DRIVER(crzrally) //t:crzrally f:holeland.c r: c:
		DRIVER(crzrallya) //t:crzrallya f:holeland.c r:crzrally c:crzrally
		DRIVER(crzrallyg) //t:crzrallyg f:holeland.c r:crzrally c:crzrally
//SET: speedbal
		DRIVER(speedbal) //t:speedbal f:speedbal.c r: c:
//SET: sauro
		DRIVER(sauro) //t:sauro f:sauro.c r: c:
//SET: trckydoc
		DRIVER(trckydoc) //t:trckydoc f:sauro.c r: c:
		DRIVER(trckydoca) //t:trckydoca f:sauro.c r:trckydoc c:trckydoc
//SET: karatour
		DRIVER(karatour) //t:karatour f:metro.c r: c:
//SET: ladykill
		DRIVER(ladykill) //t:ladykill f:metro.c r: c:
		DRIVER(moegonta) //t:moegonta f:metro.c r:ladykill c:ladykill
//SET: pangpoms
		DRIVER(pangpoms) //t:pangpoms f:metro.c r: c:
		DRIVER(pangpomsm) //t:pangpomsm f:metro.c r:pangpoms c:pangpoms
//SET: skyalert
		DRIVER(skyalert) //t:skyalert f:metro.c r: c:
//SET: poitto
		DRIVER(poitto) //t:poitto f:metro.c r: c:
//SET: dharma
		DRIVER(dharma) //t:dharma f:metro.c r: c:
		DRIVER(dharmak) //t:dharmak f:metro.c r:dharma c:dharma
//SET: lastfort
		DRIVER(lastfort) //t:lastfort f:metro.c r: c:
		DRIVER(lastforte) //t:lastforte f:metro.c r:lastfort c:lastfort
		DRIVER(lastfortk) //t:lastfortk f:metro.c r:lastfort c:lastfort
		DRIVER(lastfortg) //t:lastfortg f:metro.c r:lastfort c:lastfort
//SET: toride2g
		DRIVER(toride2g) //t:toride2g f:metro.c r: c:
		DRIVER(toride2gg) //t:toride2gg f:metro.c r:toride2g c:toride2g
		DRIVER(toride2j) //t:toride2j f:metro.c r:toride2g c:toride2g
//SET: gunmast
		DRIVER(gunmast) //t:gunmast f:metro.c r: c:
//SET: daitorid
		DRIVER(daitorid) //t:daitorid f:metro.c r: c:
		DRIVER(daitoa) //t:daitoa f:metro.c r:daitorid c:daitorid
//SET: dokyusei
		DRIVER(dokyusei) //t:dokyusei f:metro.c r: c:
//SET: dokyusp
		DRIVER(dokyusp) //t:dokyusp f:metro.c r: c:
//SET: msgogo
		DRIVER(msgogo) //t:msgogo f:metro.c r: c:
//SET: puzzli
		DRIVER(puzzli) //t:puzzli f:metro.c r: c:
//SET: 3kokushi
		DRIVER(3kokushi) //t:3kokushi f:metro.c r: c:
//SET: pururun
		DRIVER(pururun) //t:pururun f:metro.c r: c:
//SET: balcube
		DRIVER(balcube) //t:balcube f:metro.c r: c:
//SET: mouja
		DRIVER(mouja) //t:mouja f:metro.c r: c:
//SET: bangball
		DRIVER(bangball) //t:bangball f:metro.c r: c:
		DRIVER(batlbubl) //t:batlbubl f:metro.c r:bangball c:bangball
//SET: gakusai
		DRIVER(gakusai) //t:gakusai f:metro.c r: c:
//SET: gakusai2
		DRIVER(gakusai2) //t:gakusai2 f:metro.c r: c:
//SET: blzntrnd
		DRIVER(blzntrnd) //t:blzntrnd f:metro.c r: c:
//SET: gstrik2
		DRIVER(gstrik2) //t:gstrik2 f:metro.c r: c:
		DRIVER(gstrik2j) //t:gstrik2j f:metro.c r:gstrik2 c:gstrik2
//SET: hyprduel
		DRIVER(hyprduel) //t:hyprduel f:hyprduel.c r: c:
		DRIVER(hyprduel2) //t:hyprduel2 f:hyprduel.c r:hyprduel c:hyprduel
//SET: magerror
		DRIVER(magerror) //t:magerror f:hyprduel.c r: c:
//SET: puzzlet
		DRIVER(puzzlet) //t:puzzlet f:metro.c r: c:
//SET: spcforce
		DRIVER(spcforce) //t:spcforce f:spcforce.c r: c:
		DRIVER(spcforc2) //t:spcforc2 f:spcforce.c r:spcforce c:spcforce
		DRIVER(meteor) //t:meteor f:spcforce.c r:spcforce c:spcforce
//SET: looping
		DRIVER(looping) //t:looping f:looping.c r: c:
		DRIVER(loopingv) //t:loopingv f:looping.c r:looping c:looping
		DRIVER(loopingva) //t:loopingva f:looping.c r:looping c:looping
//SET: skybump
		DRIVER(skybump) //t:skybump f:looping.c r: c:
//SET: suprridr
		DRIVER(suprridr) //t:suprridr f:suprridr.c r: c:
//SET: paradise
		DRIVER(paradise) //t:paradise f:paradise.c r: c:
//SET: paradlx
		DRIVER(paradlx) //t:paradlx f:paradise.c r: c:
//SET: para2dx
		DRIVER(para2dx) //t:para2dx f:paradise.c r: c:
//SET: tgtball
		DRIVER(tgtball) //t:tgtball f:paradise.c r: c:
		DRIVER(tgtballa) //t:tgtballa f:paradise.c r:tgtball c:tgtball
//SET: torus
		DRIVER(torus) //t:torus f:paradise.c r: c:
//SET: paprazzi
		DRIVER(paprazzi) //t:paprazzi f:yunsun16.c r: c:
//SET: madball
		DRIVER(madball) //t:madball f:paradise.c r: c:
		DRIVER(madballn) //t:madballn f:paradise.c r:madball c:madball
//SET: cannball
		DRIVER(cannball) //t:cannball f:yunsung8.c r: c:
		DRIVER(cannballv) //t:cannballv f:yunsung8.c r:cannball c:cannball
//SET: magix
		DRIVER(magix) //t:magix f:yunsung8.c r: c:
//SET: rocktris
		DRIVER(rocktris) //t:rocktris f:yunsung8.c r: c:
//SET: magicbub
		DRIVER(magicbub) //t:magicbub f:yunsun16.c r: c:
		DRIVER(magicbuba) //t:magicbuba f:yunsun16.c r:magicbub c:magicbub
//SET: shocking
		DRIVER(shocking) //t:shocking f:yunsun16.c r: c:
//SET: bombkick
		DRIVER(bombkick) //t:bombkick f:yunsun16.c r: c:
//SET: nmg5
		DRIVER(nmg5) //t:nmg5 f:nmg5.c r: c:
		DRIVER(nmg5e) //t:nmg5e f:nmg5.c r:nmg5 c:nmg5
//SET: searchey
		DRIVER(searchey) //t:searchey f:nmg5.c r: c:
//SET: searchp2
		DRIVER(searchp2) //t:searchp2 f:nmg5.c r: c:
//SET: pclubys
		DRIVER(pclubys) //t:pclubys f:nmg5.c r: c:
		DRIVER(pclubysa) //t:pclubysa f:nmg5.c r:pclubys c:pclubys
//SET: garogun
		DRIVER(garogun) //t:garogun f:nmg5.c r: c:
//SET: 7ordi
		DRIVER(7ordi) //t:7ordi f:nmg5.c r: c:
//SET: wondstck
		DRIVER(wondstck) //t:wondstck f:nmg5.c r: c:
//SET: blueprnt
		DRIVER(blueprnt) //t:blueprnt f:blueprnt.c r: c:
		DRIVER(blueprntj) //t:blueprntj f:blueprnt.c r:blueprnt c:blueprnt
//SET: saturnzi
		DRIVER(saturnzi) //t:saturnzi f:blueprnt.c r: c:
//SET: gogomile
		DRIVER(gogomile) //t:gogomile f:fuukifg2.c r: c:
		DRIVER(gogomilej) //t:gogomilej f:fuukifg2.c r:gogomile c:gogomile
//SET: pbancho
		DRIVER(pbancho) //t:pbancho f:fuukifg2.c r: c:
//SET: asurabld
		DRIVER(asurabld) //t:asurabld f:fuukifg3.c r: c:
//SET: asurabus
		DRIVER(asurabus) //t:asurabus f:fuukifg3.c r: c:
//SET: drgnmst
		DRIVER(drgnmst) //t:drgnmst f:drgnmst.c r: c:
//SET: burglarx
		DRIVER(burglarx) //t:burglarx f:unico.c r: c:
//SET: zeropnt
		DRIVER(zeropnt) //t:zeropnt f:unico.c r: c:
		DRIVER(zeropnta) //t:zeropnta f:unico.c r:zeropnt c:zeropnt
//SET: zeropnt2
		DRIVER(zeropnt2) //t:zeropnt2 f:unico.c r: c:
//SET: silkroad
		DRIVER(silkroad) //t:silkroad f:silkroad.c r: c:
//SET: aoh
		DRIVER(aoh) //t:aoh f:vamphalf.c r: c:
//SET: twinactn
		DRIVER(twinactn) //t:twinactn f:nmk16.c r: c:
//SET: stagger1
		DRIVER(stagger1) //t:stagger1 f:nmk16.c r: c:
		DRIVER(redhawk) //t:redhawk f:nmk16.c r:stagger1 c:stagger1
		DRIVER(redhawke) //t:redhawke f:nmk16.c r:stagger1 c:stagger1
		DRIVER(redhawki) //t:redhawki f:nmk16.c r:stagger1 c:stagger1
		DRIVER(redhawkb) //t:redhawkb f:nmk16.c r:stagger1 c:stagger1
//SET: grdnstrm
		DRIVER(grdnstrm) //t:grdnstrm f:nmk16.c r: c:
		DRIVER(grdnstrmk) //t:grdnstrmk f:nmk16.c r:grdnstrm c:grdnstrm
//SET: bubl2000
		DRIVER(bubl2000) //t:bubl2000 f:nmk16.c r: c:
		DRIVER(hotbubl) //t:hotbubl f:nmk16.c r:bubl2000 c:bubl2000
//SET: popspops
		DRIVER(popspops) //t:popspops f:nmk16.c r: c:
//SET: firehawk
		DRIVER(firehawk) //t:firehawk f:nmk16.c r: c:
//SET: mangchi
		DRIVER(mangchi) //t:mangchi f:nmk16.c r: c:
//SET: spec2k
		DRIVER(spec2k) //t:spec2k f:nmk16.c r: c:
//SET: multchmp
		DRIVER(multchmp) //t:multchmp f:esd16.c r: c:
		DRIVER(multchmpk) //t:multchmpk f:esd16.c r:multchmp c:multchmp
//SET: mchampdx
		DRIVER(mchampdx) //t:mchampdx f:esd16.c r: c:
		DRIVER(mchampdxa) //t:mchampdxa f:esd16.c r:mchampdx c:mchampdx
		DRIVER(mchampdxb) //t:mchampdxb f:esd16.c r:mchampdx c:mchampdx
//SET: hedpanic
		DRIVER(hedpanic) //t:hedpanic f:esd16.c r: c:
		DRIVER(hedpanicf) //t:hedpanicf f:esd16.c r:hedpanic c:hedpanic
		DRIVER(hedpanico) //t:hedpanico f:esd16.c r:hedpanic c:hedpanic
//SET: tangtang
		DRIVER(tangtang) //t:tangtang f:esd16.c r: c:
//SET: swatpolc
		DRIVER(swatpolc) //t:swatpolc f:esd16.c r: c:
//SET: royalmj
		DRIVER(royalmj) //t:royalmj f:royalmah.c r: c:
		DRIVER(openmj) //t:openmj f:royalmah.c r:royalmj c:royalmj
		DRIVER(royalmah) //t:royalmah f:royalmah.c r:royalmj c:royalmj
		DRIVER(janyoup2) //t:janyoup2 f:royalmah.c r:royalmj c:royalmj
//SET: janputer
		DRIVER(janputer) //t:janputer f:royalmah.c r: c:
//SET: janoh
		DRIVER(janoh) //t:janoh f:royalmah.c r: c:
		DRIVER(janoha) //t:janoha f:royalmah.c r:janoh c:janoh
//SET: jansou
		DRIVER(jansou) //t:jansou f:royalmah.c r: c:
		DRIVER(jansoua) //t:jansoua f:royalmah.c r:jansou c:jansou
//SET: mjsiyoub
		DRIVER(mjsiyoub) //t:mjsiyoub f:royalmah.c r: c:
//SET: mjsenka
		DRIVER(mjsenka) //t:mjsenka f:royalmah.c r: c:
//SET: mjyarou
		DRIVER(mjyarou) //t:mjyarou f:royalmah.c r: c:
//SET: mjclub
		DRIVER(mjclub) //t:mjclub f:royalmah.c r: c:
//SET: daisyari
		DRIVER(daisyari) //t:daisyari f:royalmah.c r: c:
//SET: suzume
		DRIVER(suzume) //t:suzume f:royalmah.c r: c:
//SET: hnayayoi
		DRIVER(hnayayoi) //t:hnayayoi f:hnayayoi.c r: c:
		DRIVER(hnfubuki) //t:hnfubuki f:hnayayoi.c r:hnayayoi c:hnayayoi
//SET: dondenmj
		DRIVER(dondenmj) //t:dondenmj f:royalmah.c r: c:
//SET: ippatsu
		DRIVER(ippatsu) //t:ippatsu f:royalmah.c r: c:
//SET: mjdiplob
		DRIVER(mjdiplob) //t:mjdiplob f:royalmah.c r: c:
//SET: untoucha
		DRIVER(untoucha) //t:untoucha f:hnayayoi.c r: c:
//SET: tontonb
		DRIVER(tontonb) //t:tontonb f:royalmah.c r: c:
//SET: makaijan
		DRIVER(makaijan) //t:makaijan f:royalmah.c r: c:
//SET: majs101b
		DRIVER(majs101b) //t:majs101b f:royalmah.c r: c:
//SET: mjapinky
		DRIVER(mjapinky) //t:mjapinky f:royalmah.c r: c:
//SET: mjdejavu
		DRIVER(mjdejavu) //t:mjdejavu f:royalmah.c r: c:
		DRIVER(mjdejav2) //t:mjdejav2 f:royalmah.c r:mjdejavu c:mjdejavu
//SET: hnkochou
		DRIVER(hnkochou) //t:hnkochou f:dynax.c r: c:
		DRIVER(hanamai) //t:hanamai f:dynax.c r:hnkochou c:hnkochou
//SET: mjderngr
		DRIVER(mjderngr) //t:mjderngr f:royalmah.c r: c:
//SET: drgpunch
		DRIVER(drgpunch) //t:drgpunch f:dynax.c r: c:
		DRIVER(sprtmtch) //t:sprtmtch f:dynax.c r:drgpunch c:drgpunch
//SET: mjfriday
		DRIVER(mjfriday) //t:mjfriday f:dynax.c r: c:
//SET: jantouki
		DRIVER(jantouki) //t:jantouki f:dynax.c r: c:
//SET: gekisha
		DRIVER(gekisha) //t:gekisha f:dynax.c r: c:
//SET: mjifb
		DRIVER(mjifb) //t:mjifb f:royalmah.c r: c:
		DRIVER(mjifb2) //t:mjifb2 f:royalmah.c r:mjifb c:mjifb
		DRIVER(mjifb3) //t:mjifb3 f:royalmah.c r:mjifb c:mjifb
//SET: mjvegasa
		DRIVER(mjvegasa) //t:mjvegasa f:royalmah.c r: c:
		DRIVER(mjvegas) //t:mjvegas f:royalmah.c r:mjvegasa c:mjvegasa
//SET: cafetime
		DRIVER(cafetime) //t:cafetime f:royalmah.c r: c:
//SET: cafedoll
		DRIVER(cafedoll) //t:cafedoll f:royalmah.c r: c:
//SET: janptr96
		DRIVER(janptr96) //t:janptr96 f:royalmah.c r: c:
//SET: janptrsp
		DRIVER(janptrsp) //t:janptrsp f:royalmah.c r: c:
//SET: maya
		DRIVER(maya) //t:maya f:dynax.c r: c:
		DRIVER(mayaa) //t:mayaa f:dynax.c r:maya c:maya
//SET: inca
		DRIVER(inca) //t:inca f:dynax.c r: c:
//SET: blktouch
		DRIVER(blktouch) //t:blktouch f:dynax.c r: c:
//SET: mcnpshnt
		DRIVER(mcnpshnt) //t:mcnpshnt f:dynax.c r: c:
//SET: 7jigen
		DRIVER(7jigen) //t:7jigen f:dynax.c r: c:
//SET: neruton
		DRIVER(neruton) //t:neruton f:dynax.c r: c:
		DRIVER(nerutona) //t:nerutona f:dynax.c r:neruton c:neruton
//SET: mjcomv1
		DRIVER(mjcomv1) //t:mjcomv1 f:dynax.c r: c:
//SET: shpeng
		DRIVER(shpeng) //t:shpeng f:dynax.c r: c:
//SET: tenkai
		DRIVER(tenkai) //t:tenkai f:dynax.c r: c:
		DRIVER(tenkai2b) //t:tenkai2b f:dynax.c r:tenkai c:tenkai
		DRIVER(tenkaibb) //t:tenkaibb f:dynax.c r:tenkai c:tenkai
		DRIVER(tenkaicb) //t:tenkaicb f:dynax.c r:tenkai c:tenkai
		DRIVER(tenkaid) //t:tenkaid f:dynax.c r:tenkai c:tenkai
		DRIVER(tenkaie) //t:tenkaie f:dynax.c r:tenkai c:tenkai
//SET: htengoku
		DRIVER(htengoku) //t:htengoku f:dynax.c r: c:
//SET: mjreach
		DRIVER(mjreach) //t:mjreach f:dynax.c r: c:
//SET: mjdialq2
		DRIVER(mjdialq2) //t:mjdialq2 f:dynax.c r: c:
//SET: yarunara
		DRIVER(yarunara) //t:yarunara f:dynax.c r: c:
//SET: mjangels
		DRIVER(mjangels) //t:mjangels f:dynax.c r: c:
//SET: quiztvqq
		DRIVER(quiztvqq) //t:quiztvqq f:dynax.c r: c:
//SET: mmpanic
		DRIVER(mmpanic) //t:mmpanic f:ddenlovr.c r: c:
//SET: quizchq
		DRIVER(quizchq) //t:quizchq f:ddenlovr.c r: c:
		DRIVER(quizchql) //t:quizchql f:ddenlovr.c r:quizchq c:quizchq
//SET: funkyfig
		DRIVER(funkyfig) //t:funkyfig f:ddenlovr.c r: c:
//SET: animaljr
		DRIVER(animaljr) //t:animaljr f:ddenlovr.c r: c:
		DRIVER(animaljrs) //t:animaljrs f:ddenlovr.c r:animaljr c:animaljr
		DRIVER(animaljrj) //t:animaljrj f:ddenlovr.c r:animaljr c:animaljr
//SET: hginga
		DRIVER(hginga) //t:hginga f:ddenlovr.c r: c:
//SET: mjmyster
		DRIVER(mjmyster) //t:mjmyster f:ddenlovr.c r: c:
		DRIVER(mjmywrld) //t:mjmywrld f:ddenlovr.c r:mjmyster c:mjmyster
//SET: mjmyornt
		DRIVER(mjmyornt) //t:mjmyornt f:ddenlovr.c r: c:
//SET: mjmyuniv
		DRIVER(mjmyuniv) //t:mjmyuniv f:ddenlovr.c r: c:
//SET: quiz365
		DRIVER(quiz365) //t:quiz365 f:ddenlovr.c r: c:
		DRIVER(quiz365t) //t:quiz365t f:ddenlovr.c r:quiz365 c:quiz365
//SET: rongrong
		DRIVER(rongrong) //t:rongrong f:ddenlovr.c r: c:
		DRIVER(rongrongj) //t:rongrongj f:ddenlovr.c r:rongrong c:rongrong
		DRIVER(rongrongg) //t:rongrongg f:ddenlovr.c r:rongrong c:rongrong
//SET: hparadis
		DRIVER(hparadis) //t:hparadis f:ddenlovr.c r: c:
//SET: hgokou
		DRIVER(hgokou) //t:hgokou f:ddenlovr.c r: c:
//SET: mjdchuka
		DRIVER(mjdchuka) //t:mjdchuka f:ddenlovr.c r: c:
//SET: mjtensin
		DRIVER(mjtensin) //t:mjtensin f:royalmah.c r: c:
//SET: nettoqc
		DRIVER(nettoqc) //t:nettoqc f:ddenlovr.c r: c:
//SET: majrjhdx
		DRIVER(majrjhdx) //t:majrjhdx f:dynax.c r: c:
//SET: ddenlovj
		DRIVER(ddenlovj) //t:ddenlovj f:ddenlovr.c r: c:
		DRIVER(ddenlovrk) //t:ddenlovrk f:ddenlovr.c r:ddenlovj c:ddenlovj
		DRIVER(ddenlovr) //t:ddenlovr f:ddenlovr.c r:ddenlovj c:ddenlovj
		DRIVER(ddenlovrb) //t:ddenlovrb f:ddenlovr.c r:ddenlovj c:ddenlovj
//SET: hanakanz
		DRIVER(hanakanz) //t:hanakanz f:ddenlovr.c r: c:
//SET: akamaru
		DRIVER(akamaru) //t:akamaru f:ddenlovr.c r: c:
//SET: sryudens
		DRIVER(sryudens) //t:sryudens f:ddenlovr.c r: c:
//SET: mjflove
		DRIVER(mjflove) //t:mjflove f:ddenlovr.c r: c:
//SET: hkagerou
		DRIVER(hkagerou) //t:hkagerou f:ddenlovr.c r: c:
//SET: realbrk
		DRIVER(realbrk) //t:realbrk f:realbrk.c r: c:
		DRIVER(realbrkk) //t:realbrkk f:realbrk.c r:realbrk c:realbrk
		DRIVER(realbrkj) //t:realbrkj f:realbrk.c r:realbrk c:realbrk
//SET: dai2kaku
		DRIVER(dai2kaku) //t:dai2kaku f:realbrk.c r: c:
//SET: mjchuuka
		DRIVER(mjchuuka) //t:mjchuuka f:ddenlovr.c r: c:
//SET: mjreach1
		DRIVER(mjreach1) //t:mjreach1 f:ddenlovr.c r: c:
//SET: cafebrk
		DRIVER(cafebrk) //t:cafebrk f:royalmah.c r: c:
//SET: jongtei
		DRIVER(jongtei) //t:jongtei f:ddenlovr.c r: c:
//SET: daimyojn
		DRIVER(daimyojn) //t:daimyojn f:ddenlovr.c r: c:
//SET: pkgnsh
		DRIVER(pkgnsh) //t:pkgnsh f:realbrk.c r: c:
//SET: pkgnshdx
		DRIVER(pkgnshdx) //t:pkgnshdx f:realbrk.c r: c:
//SET: hjingi
		DRIVER(hjingi) //t:hjingi f:dynax.c r: c:
		DRIVER(hnoridur) //t:hnoridur f:dynax.c r:hjingi c:hjingi
//SET: hanayara
		DRIVER(hanayara) //t:hanayara f:dynax.c r: c:
//SET: mjelctrn
		DRIVER(mjelctrn) //t:mjelctrn f:dynax.c r: c:
		DRIVER(mjelct3) //t:mjelct3 f:dynax.c r:mjelctrn c:mjelctrn
		DRIVER(mjelct3a) //t:mjelct3a f:dynax.c r:mjelctrn c:mjelctrn
		DRIVER(mjelctrb) //t:mjelctrb f:dynax.c r:mjelctrn c:mjelctrn
//SET: majxtal7
		DRIVER(majxtal7) //t:majxtal7 f:dynax.c r: c:
//SET: nyny
		DRIVER(nyny) //t:nyny f:nyny.c r: c:
		DRIVER(nynyg) //t:nynyg f:nyny.c r:nyny c:nyny
		DRIVER(warcadia) //t:warcadia f:nyny.c r:nyny c:nyny
//SET: r2dtank
		DRIVER(r2dtank) //t:r2dtank f:r2dtank.c r: c:
//SET: spiders
		DRIVER(spiders) //t:spiders f:spiders.c r: c:
		DRIVER(spiders2) //t:spiders2 f:spiders.c r:spiders c:spiders
		DRIVER(spiders3) //t:spiders3 f:spiders.c r:spiders c:spiders
		DRIVER(spinner) //t:spinner f:spiders.c r:spiders c:spiders
//SET: sub
		DRIVER(sub) //t:sub f:sub.c r: c:
//SET: jwildb52
		DRIVER(jwildb52) //t:jwildb52 f:sigmab52.c r: c:
		DRIVER(jwildb52a) //t:jwildb52a f:sigmab52.c r:jwildb52 c:jwildb52
		DRIVER(jwildb52h) //t:jwildb52h f:sigmab52.c r:jwildb52 c:jwildb52
//SET: gegege
		DRIVER(gegege) //t:gegege f:sigmab98.c r: c:
//SET: sammymdl
		DRIVER(sammymdl) //t:sammymdl f:sigmab98.c r: c:
//SET: animalc
		DRIVER(animalc) //t:animalc f:sigmab98.c r:sammymdl c:
//SET: itazuram
		DRIVER(itazuram) //t:itazuram f:sigmab98.c r:sammymdl c:
//SET: pyenaget
		DRIVER(pyenaget) //t:pyenaget f:sigmab98.c r:sammymdl c:
//SET: tdoboon
		DRIVER(tdoboon) //t:tdoboon f:sigmab98.c r:sammymdl c:
//SET: haekaka
		DRIVER(haekaka) //t:haekaka f:sigmab98.c r:sammymdl c:
//SET: goldstar
		DRIVER(goldstar) //t:goldstar f:goldstar.c r: c:
		DRIVER(goldstbl) //t:goldstbl f:goldstar.c r:goldstar c:goldstar
		DRIVER(moonlght) //t:moonlght f:goldstar.c r:goldstar c:goldstar
//SET: chry10
		DRIVER(chry10) //t:chry10 f:goldstar.c r: c:
//SET: chrygld
		DRIVER(chrygld) //t:chrygld f:goldstar.c r: c:
//SET: cabaret
		DRIVER(cabaret) //t:cabaret f:cabaret.c r: c:
//SET: cpoker
		DRIVER(cpoker) //t:cpoker f:igspoker.c r: c:
		DRIVER(cpokert) //t:cpokert f:igspoker.c r:cpoker c:cpoker
//SET: csk227it
		DRIVER(csk227it) //t:csk227it f:igspoker.c r: c:
		DRIVER(csk234it) //t:csk234it f:igspoker.c r:csk227it c:csk227it
//SET: igs_ncs
		DRIVER(igs_ncs) //t:igs_ncs f:igspoker.c r: c:
//SET: igs_ncs2
		DRIVER(igs_ncs2) //t:igs_ncs2 f:igspoker.c r: c:
//SET: spk116it
		DRIVER(spk116it) //t:spk116it f:spoker.c r: c:
		DRIVER(spk115it) //t:spk115it f:spoker.c r:spk116it c:spk116it
//SET: jackie
		DRIVER(jackie) //t:jackie f:jackie.c r: c:
//SET: pktet346
		DRIVER(pktet346) //t:pktet346 f:igspoker.c r: c:
//SET: chleague
		DRIVER(chleague) //t:chleague f:igspoker.c r: c:
		DRIVER(chleagul) //t:chleagul f:igspoker.c r:chleague c:chleague
//SET: number10
		DRIVER(number10) //t:number10 f:igspoker.c r: c:
		DRIVER(numbr10l) //t:numbr10l f:igspoker.c r:number10 c:number10
//SET: cpokerpk
		DRIVER(cpokerpk) //t:cpokerpk f:igspoker.c r: c:
		DRIVER(cpokerpkg) //t:cpokerpkg f:igspoker.c r:cpokerpk c:cpokerpk
		DRIVER(citalcup) //t:citalcup f:igspoker.c r:cpokerpk c:cpokerpk
//SET: stellecu
		DRIVER(stellecu) //t:stellecu f:igspoker.c r: c:
//SET: iqblock
		DRIVER(iqblock) //t:iqblock f:iqblock.c r: c:
		DRIVER(iqblocka) //t:iqblocka f:igs017.c r:iqblock c:iqblock
		DRIVER(iqblockf) //t:iqblockf f:igs017.c r:iqblock c:iqblock
//SET: grndtour
		DRIVER(grndtour) //t:grndtour f:iqblock.c r: c:
//SET: 5clown
		DRIVER(5clown) //t:5clown f:5clown.c r: c:
		DRIVER(5clowna) //t:5clowna f:5clown.c r:5clown c:5clown
		DRIVER(5clownsp) //t:5clownsp f:5clown.c r:5clown c:5clown
//SET: lordgun
		DRIVER(lordgun) //t:lordgun f:lordgun.c r: c:
//SET: aliencha
		DRIVER(aliencha) //t:aliencha f:lordgun.c r: c:
		DRIVER(alienchac) //t:alienchac f:lordgun.c r:aliencha c:aliencha
//SET: jingbell
		DRIVER(jingbell) //t:jingbell f:igs009.c r: c:
//SET: gp98
		DRIVER(gp98) //t:gp98 f:igs009.c r: c:
//SET: lhb
		DRIVER(lhb) //t:lhb f:igs011.c r: c:
		DRIVER(lhbv33c) //t:lhbv33c f:igs011.c r:lhb c:lhb
		DRIVER(ryukobou) //t:ryukobou f:igs011.c r:lhb c:lhb
		DRIVER(dbc) //t:dbc f:igs011.c r:lhb c:lhb
//SET: lhb2
		DRIVER(lhb2) //t:lhb2 f:igs011.c r: c:
		DRIVER(nkishusp) //t:nkishusp f:igs011.c r:lhb2 c:lhb2
//SET: xymg
		DRIVER(xymg) //t:xymg f:igs011.c r: c:
		DRIVER(wlcc) //t:wlcc f:igs011.c r:xymg c:xymg
//SET: vbowl
		DRIVER(vbowl) //t:vbowl f:igs011.c r: c:
		DRIVER(vbowlj) //t:vbowlj f:igs011.c r:vbowl c:vbowl
//SET: drgnwrld
		DRIVER(drgnwrld) //t:drgnwrld f:igs011.c r: c:
		DRIVER(drgnwrldv30) //t:drgnwrldv30 f:igs011.c r:drgnwrld c:drgnwrld
		DRIVER(drgnwrldv21) //t:drgnwrldv21 f:igs011.c r:drgnwrld c:drgnwrld
		DRIVER(drgnwrldv21j) //t:drgnwrldv21j f:igs011.c r:drgnwrld c:drgnwrld
		DRIVER(drgnwrldv20j) //t:drgnwrldv20j f:igs011.c r:drgnwrld c:drgnwrld
		DRIVER(drgnwrldv10c) //t:drgnwrldv10c f:igs011.c r:drgnwrld c:drgnwrld
		DRIVER(drgnwrldv11h) //t:drgnwrldv11h f:igs011.c r:drgnwrld c:drgnwrld
//SET: tjsb
		DRIVER(tjsb) //t:tjsb f:igs017.c r: c:
//SET: sdmg2
		DRIVER(sdmg2) //t:sdmg2 f:igs017.c r: c:
//SET: mgdh
		DRIVER(mgdh) //t:mgdh f:igs017.c r: c:
		DRIVER(mgdha) //t:mgdha f:igs017.c r:mgdh c:mgdh
//SET: mgcs
		DRIVER(mgcs) //t:mgcs f:igs017.c r: c:
//SET: lhzb2
		DRIVER(lhzb2) //t:lhzb2 f:igs017.c r: c:
		DRIVER(lhzb2a) //t:lhzb2a f:igs017.c r:lhzb2 c:lhzb2
//SET: slqz2
		DRIVER(slqz2) //t:slqz2 f:igs017.c r: c:
//SET: tarzan
		DRIVER(tarzan) //t:tarzan f:igs017.c r: c:
		DRIVER(tarzana) //t:tarzana f:igs017.c r:tarzan c:tarzan
//SET: starzan
		DRIVER(starzan) //t:starzan f:igs017.c r: c:
//SET: bigd2
		DRIVER(bigd2) //t:bigd2 f:igs_m027.c r: c:
//SET: sdwx
		DRIVER(sdwx) //t:sdwx f:igs_m027.c r: c:
//SET: sddz
		DRIVER(sddz) //t:sddz f:igs_m027.c r: c:
//SET: lhzb3
		DRIVER(lhzb3) //t:lhzb3 f:igs_m027.c r: c:
//SET: lhzb4
		DRIVER(lhzb4) //t:lhzb4 f:igs_m027.c r: c:
//SET: klxyj
		DRIVER(klxyj) //t:klxyj f:igs_m027.c r: c:
//SET: mgfx
		DRIVER(mgfx) //t:mgfx f:igs_m027.c r: c:
//SET: pgm
		DRIVER(pgm) //t:pgm f:pgm.c r: c:
//SET: orlegend
		DRIVER(orlegend) //t:orlegend f:pgm.c r:pgm c:
		DRIVER(orlegende) //t:orlegende f:pgm.c r:orlegend c:orlegend
		DRIVER(orlegendc) //t:orlegendc f:pgm.c r:orlegend c:orlegend
		DRIVER(orlegendca) //t:orlegendca f:pgm.c r:orlegend c:orlegend
		DRIVER(orlegend111c) //t:orlegend111c f:pgm.c r:orlegend c:orlegend
		DRIVER(orlegend105k) //t:orlegend105k f:pgm.c r:orlegend c:orlegend
//SET: drgw2
		DRIVER(drgw2) //t:drgw2 f:pgm.c r:pgm c:
		DRIVER(dw2v100x) //t:dw2v100x f:pgm.c r:drgw2 c:drgw2
		DRIVER(drgw2c) //t:drgw2c f:pgm.c r:drgw2 c:drgw2
		DRIVER(drgw2j) //t:drgw2j f:pgm.c r:drgw2 c:drgw2
//SET: drgw3
		DRIVER(drgw3) //t:drgw3 f:pgm.c r:pgm c:
		DRIVER(drgw3105) //t:drgw3105 f:pgm.c r:drgw3 c:drgw3
		DRIVER(drgw3100) //t:drgw3100 f:pgm.c r:drgw3 c:drgw3
//SET: dwex
		DRIVER(dwex) //t:dwex f:pgm.c r:pgm c:
//SET: killbld
		DRIVER(killbld) //t:killbld f:pgm.c r:pgm c:
		DRIVER(killbld104) //t:killbld104 f:pgm.c r:killbld c:killbld
//SET: kov
		DRIVER(kov) //t:kov f:pgm.c r:pgm c:
		DRIVER(kov115) //t:kov115 f:pgm.c r:kov c:kov
		DRIVER(kov100) //t:kov100 f:pgm.c r:kov c:kov
//SET: kovplus
		DRIVER(kovplus) //t:kovplus f:pgm.c r:pgm c:
		DRIVER(kovplusa) //t:kovplusa f:pgm.c r:kovplus c:kovplus
//SET: kovsh
		DRIVER(kovsh) //t:kovsh f:pgm.c r:pgm c:
		DRIVER(kovsh103) //t:kovsh103 f:pgm.c r:kovsh c:kovsh
		DRIVER(kovqhsgs) //t:kovqhsgs f:pgm.c r:kovsh c:kovsh
//SET: photoy2k
		DRIVER(photoy2k) //t:photoy2k f:pgm.c r:pgm c:
		DRIVER(photoy2k102) //t:photoy2k102 f:pgm.c r:photoy2k c:photoy2k
		DRIVER(photoy2k104) //t:photoy2k104 f:pgm.c r:photoy2k c:photoy2k
//SET: puzlstar
		DRIVER(puzlstar) //t:puzlstar f:pgm.c r:pgm c:
//SET: olds
		DRIVER(olds) //t:olds f:pgm.c r:pgm c:
		DRIVER(olds100) //t:olds100 f:pgm.c r:olds c:olds
		DRIVER(olds100a) //t:olds100a f:pgm.c r:olds c:olds
//SET: kov2
		DRIVER(kov2) //t:kov2 f:pgm.c r:pgm c:
		DRIVER(kov2106) //t:kov2106 f:pgm.c r:kov2 c:kov2
		DRIVER(kov2103) //t:kov2103 f:pgm.c r:kov2 c:kov2
		DRIVER(kov2102) //t:kov2102 f:pgm.c r:kov2 c:kov2
		DRIVER(kov2101) //t:kov2101 f:pgm.c r:kov2 c:kov2
		DRIVER(kov2100) //t:kov2100 f:pgm.c r:kov2 c:kov2
//SET: kov2p
		DRIVER(kov2p) //t:kov2p f:pgm.c r:pgm c:
		DRIVER(kov2p205) //t:kov2p205 f:pgm.c r:kov2p c:kov2p
//SET: ddp2
		DRIVER(ddp2) //t:ddp2 f:pgm.c r:pgm c:
		DRIVER(ddp2100) //t:ddp2100 f:pgm.c r:ddp2 c:ddp2
		DRIVER(ddp2101) //t:ddp2101 f:pgm.c r:ddp2 c:ddp2
//SET: puzzli2
		DRIVER(puzzli2) //t:puzzli2 f:pgm.c r:pgm c:
//SET: martmast
		DRIVER(martmast) //t:martmast f:pgm.c r:pgm c:
		DRIVER(martmastc) //t:martmastc f:pgm.c r:martmast c:martmast
		DRIVER(martmastc102) //t:martmastc102 f:pgm.c r:martmast c:martmast
//SET: theglad
		DRIVER(theglad) //t:theglad f:pgm.c r:pgm c:
		DRIVER(theglada) //t:theglada f:pgm.c r:theglad c:theglad
//SET: dw2001
		DRIVER(dw2001) //t:dw2001 f:pgm.c r:pgm c:
//SET: py2k2
		DRIVER(py2k2) //t:py2k2 f:pgm.c r:pgm c:
//SET: dmnfrnt
		DRIVER(dmnfrnt) //t:dmnfrnt f:pgm.c r:pgm c:
		DRIVER(dmnfrnta) //t:dmnfrnta f:pgm.c r:dmnfrnt c:dmnfrnt
//SET: kovshp
		DRIVER(kovshp) //t:kovshp f:pgm.c r:pgm c:
		DRIVER(kovlsqh2) //t:kovlsqh2 f:pgm.c r:kovshp c:kovshp
		DRIVER(kovlsjb) //t:kovlsjb f:pgm.c r:kovshp c:kovshp
		DRIVER(kovlsjba) //t:kovlsjba f:pgm.c r:kovshp c:kovshp
//SET: oldsplus
		DRIVER(oldsplus) //t:oldsplus f:pgm.c r:pgm c:
//SET: killbldp
		DRIVER(killbldp) //t:killbldp f:pgm.c r:pgm c:
//SET: happy6
		DRIVER(happy6) //t:happy6 f:pgm.c r:pgm c:
//SET: svg
		DRIVER(svg) //t:svg f:pgm.c r:pgm c:
//SET: ket
		DRIVER(ket) //t:ket f:pgm.c r: c:
		DRIVER(keta) //t:keta f:pgm.c r:ket c:ket
		DRIVER(ketb) //t:ketb f:pgm.c r:ket c:ket
//SET: ddp3
		DRIVER(ddp3) //t:ddp3 f:pgm.c r: c:
		DRIVER(ddp3a) //t:ddp3a f:pgm.c r:ddp3 c:ddp3
		DRIVER(ddp3b) //t:ddp3b f:pgm.c r:ddp3 c:ddp3
		DRIVER(ddp3blk) //t:ddp3blk f:pgm.c r:ddp3 c:ddp3
//SET: espgal
		DRIVER(espgal) //t:espgal f:pgm.c r: c:
//SET: orleg2
		DRIVER(orleg2) //t:orleg2 f:pgm.c r: c:
//SET: dunhuang
		DRIVER(dunhuang) //t:dunhuang f:dunhuang.c r: c:
//SET: hitme
		DRIVER(hitme) //t:hitme f:hitme.c r: c:
		DRIVER(hitme1) //t:hitme1 f:hitme.c r:hitme c:hitme
		DRIVER(m21) //t:m21 f:hitme.c r:hitme c:hitme
//SET: barricad
		DRIVER(barricad) //t:barricad f:hitme.c r: c:
		DRIVER(brickyrd) //t:brickyrd f:hitme.c r:barricad c:barricad
//SET: starcrus
		DRIVER(starcrus) //t:starcrus f:starcrus.c r: c:
//SET: super21
		DRIVER(super21) //t:super21 f:hitme.c r: c:
//SET: shuttlei
		DRIVER(shuttlei) //t:shuttlei f:8080bw.c r: c:
//SET: skylove
		DRIVER(skylove) //t:skylove f:8080bw.c r: c:
//SET: battlex
		DRIVER(battlex) //t:battlex f:battlex.c r: c:
//SET: carjmbre
		DRIVER(carjmbre) //t:carjmbre f:carjmbre.c r: c:
//SET: popper
		DRIVER(popper) //t:popper f:popper.c r: c:
//SET: speedspn
		DRIVER(speedspn) //t:speedspn f:speedspn.c r: c:
//SET: mstworld
		DRIVER(mstworld) //t:mstworld f:mitchell.c r: c:
//SET: kickgoal
		DRIVER(kickgoal) //t:kickgoal f:kickgoal.c r: c:
//SET: actionhw
		DRIVER(actionhw) //t:actionhw f:kickgoal.c r: c:
//SET: usg32
		DRIVER(usg32) //t:usg32 f:usgames.c r: c:
//SET: usg83
		DRIVER(usg83) //t:usg83 f:usgames.c r: c:
		DRIVER(usg82) //t:usg82 f:usgames.c r:usg83 c:usg83
		DRIVER(usg83x) //t:usg83x f:usgames.c r:usg83 c:usg83
//SET: usg182
		DRIVER(usg182) //t:usg182 f:usgames.c r: c:
//SET: usg185
		DRIVER(usg185) //t:usg185 f:usgames.c r: c:
//SET: usg252
		DRIVER(usg252) //t:usg252 f:usgames.c r: c:
//SET: mermaid
		DRIVER(mermaid) //t:mermaid f:mermaid.c r: c:
		DRIVER(yachtmn) //t:yachtmn f:mermaid.c r:mermaid c:mermaid
//SET: rougien
		DRIVER(rougien) //t:rougien f:mermaid.c r: c:
//SET: drmicro
		DRIVER(drmicro) //t:drmicro f:drmicro.c r: c:
//SET: jantotsu
		DRIVER(jantotsu) //t:jantotsu f:jantotsu.c r: c:
//SET: appoooh
		DRIVER(appoooh) //t:appoooh f:appoooh.c r: c:
//SET: robowres
		DRIVER(robowres) //t:robowres f:appoooh.c r: c:
		DRIVER(robowresb) //t:robowresb f:appoooh.c r:robowres c:robowres
//SET: bankp
		DRIVER(bankp) //t:bankp f:bankp.c r: c:
//SET: combh
		DRIVER(combh) //t:combh f:bankp.c r: c:
//SET: mjkjidai
		DRIVER(mjkjidai) //t:mjkjidai f:mjkjidai.c r: c:
//SET: chinsan
		DRIVER(chinsan) //t:chinsan f:chinsan.c r: c:
//SET: mayumi
		DRIVER(mayumi) //t:mayumi f:mayumi.c r: c:
//SET: xtheball
		DRIVER(xtheball) //t:xtheball f:xtheball.c r: c:
//SET: btoads
		DRIVER(btoads) //t:btoads f:btoads.c r: c:
//SET: kinst
		DRIVER(kinst) //t:kinst f:kinst.c r: c:
		DRIVER(kinst14) //t:kinst14 f:kinst.c r:kinst c:kinst
		DRIVER(kinst13) //t:kinst13 f:kinst.c r:kinst c:kinst
		DRIVER(kinstp) //t:kinstp f:kinst.c r:kinst c:kinst
//SET: kinst2
		DRIVER(kinst2) //t:kinst2 f:kinst.c r: c:
		DRIVER(kinst2k4) //t:kinst2k4 f:kinst.c r:kinst2 c:kinst2
		DRIVER(kinst213) //t:kinst213 f:kinst.c r:kinst2 c:kinst2
		DRIVER(kinst2k3) //t:kinst2k3 f:kinst.c r:kinst2 c:kinst2
		DRIVER(kinst211) //t:kinst211 f:kinst.c r:kinst2 c:kinst2
		DRIVER(kinst210) //t:kinst210 f:kinst.c r:kinst2 c:kinst2
//SET: gigas
		DRIVER(gigas) //t:gigas f:freekick.c r: c:
		DRIVER(gigasb) //t:gigasb f:freekick.c r:gigas c:gigas
		DRIVER(oigas) //t:oigas f:freekick.c r:gigas c:gigas
//SET: gigasm2b
		DRIVER(gigasm2b) //t:gigasm2b f:freekick.c r: c:
//SET: pbillrd
		DRIVER(pbillrd) //t:pbillrd f:freekick.c r: c:
		DRIVER(pbillrds) //t:pbillrds f:freekick.c r:pbillrd c:pbillrd
//SET: freekick
		DRIVER(freekick) //t:freekick f:freekick.c r: c:
		DRIVER(freekickb) //t:freekickb f:freekick.c r:freekick c:freekick
		DRIVER(freekickb2) //t:freekickb2 f:freekick.c r:freekick c:freekick
//SET: countrun
		DRIVER(countrun) //t:countrun f:freekick.c r: c:
		DRIVER(countrunb) //t:countrunb f:freekick.c r:countrun c:countrun
		DRIVER(countrunb2) //t:countrunb2 f:freekick.c r:countrun c:countrun
//SET: rmhaihai
		DRIVER(rmhaihai) //t:rmhaihai f:rmhaihai.c r: c:
		DRIVER(rmhaihib) //t:rmhaihib f:rmhaihai.c r:rmhaihai c:rmhaihai
//SET: rmhaijin
		DRIVER(rmhaijin) //t:rmhaijin f:rmhaihai.c r: c:
//SET: rmhaisei
		DRIVER(rmhaisei) //t:rmhaisei f:rmhaihai.c r: c:
//SET: themj
		DRIVER(themj) //t:themj f:rmhaihai.c r: c:
//SET: hanaroku
		DRIVER(hanaroku) //t:hanaroku f:albazc.c r: c:
//SET: yumefuda
		DRIVER(yumefuda) //t:yumefuda f:albazg.c r: c:
//SET: hourouki
		DRIVER(hourouki) //t:hourouki f:homedata.c r: c:
//SET: mhgaiden
		DRIVER(mhgaiden) //t:mhgaiden f:homedata.c r: c:
//SET: mirderby
		DRIVER(mirderby) //t:mirderby f:homedata.c r: c:
//SET: mjhokite
		DRIVER(mjhokite) //t:mjhokite f:homedata.c r: c:
//SET: mjclinic
		DRIVER(mjclinic) //t:mjclinic f:homedata.c r: c:
//SET: mrokumei
		DRIVER(mrokumei) //t:mrokumei f:homedata.c r: c:
//SET: reikaids
		DRIVER(reikaids) //t:reikaids f:homedata.c r: c:
//SET: mjkojink
		DRIVER(mjkojink) //t:mjkojink f:homedata.c r: c:
//SET: vitaminc
		DRIVER(vitaminc) //t:vitaminc f:homedata.c r: c:
//SET: mjyougo
		DRIVER(mjyougo) //t:mjyougo f:homedata.c r: c:
//SET: lemnangl
		DRIVER(lemnangl) //t:lemnangl f:homedata.c r: c:
//SET: mjkinjas
		DRIVER(mjkinjas) //t:mjkinjas f:homedata.c r: c:
//SET: battlcry
		DRIVER(battlcry) //t:battlcry f:homedata.c r: c:
//SET: jogakuen
		DRIVER(jogakuen) //t:jogakuen f:homedata.c r: c:
//SET: mjikaga
		DRIVER(mjikaga) //t:mjikaga f:homedata.c r: c:
//SET: mjprivat
		DRIVER(mjprivat) //t:mjprivat f:homedata.c r: c:
//SET: ultennis
		DRIVER(ultennis) //t:ultennis f:artmagic.c r: c:
		DRIVER(ultennisj) //t:ultennisj f:artmagic.c r:ultennis c:ultennis
//SET: cheesech
		DRIVER(cheesech) //t:cheesech f:artmagic.c r: c:
//SET: stonebal
		DRIVER(stonebal) //t:stonebal f:artmagic.c r: c:
		DRIVER(stonebal2) //t:stonebal2 f:artmagic.c r:stonebal c:stonebal
//SET: shtstar
		DRIVER(shtstar) //t:shtstar f:artmagic.c r: c:
//SET: skeetsht
		DRIVER(skeetsht) //t:skeetsht f:skeetsht.c r: c:
//SET: toursol
		DRIVER(toursol) //t:toursol f:pcat_dyn.c r: c:
		DRIVER(toursol1) //t:toursol1 f:pcat_dyn.c r:toursol c:toursol
//SET: dynamski
		DRIVER(dynamski) //t:dynamski f:shangkid.c r: c:
//SET: chinhero
		DRIVER(chinhero) //t:chinhero f:shangkid.c r: c:
		DRIVER(chinhero2) //t:chinhero2 f:shangkid.c r:chinhero c:chinhero
		DRIVER(chinherot) //t:chinherot f:shangkid.c r:chinhero c:chinhero
//SET: shangkid
		DRIVER(shangkid) //t:shangkid f:shangkid.c r: c:
		DRIVER(hiryuken) //t:hiryuken f:shangkid.c r:shangkid c:shangkid
//SET: kingdrby
		DRIVER(kingdrby) //t:kingdrby f:kingdrby.c r: c:
		DRIVER(cowrace) //t:cowrace f:kingdrby.c r:kingdrby c:kingdrby
		DRIVER(kingdrbb) //t:kingdrbb f:kingdrby.c r:kingdrby c:kingdrby
//SET: tx1
		DRIVER(tx1) //t:tx1 f:tx1.c r: c:
		DRIVER(tx1a) //t:tx1a f:tx1.c r:tx1 c:tx1
//SET: buggyboy
		DRIVER(buggyboy) //t:buggyboy f:tx1.c r: c:
		DRIVER(buggyboyjr) //t:buggyboyjr f:tx1.c r:buggyboy c:buggyboy
//SET: lockon
		DRIVER(lockon) //t:lockon f:lockon.c r: c:
		DRIVER(lockonc) //t:lockonc f:lockon.c r:lockon c:lockon
//SET: apache3
		DRIVER(apache3) //t:apache3 f:tatsumi.c r: c:
		DRIVER(apache3a) //t:apache3a f:tatsumi.c r:apache3 c:apache3
//SET: roundup5
		DRIVER(roundup5) //t:roundup5 f:tatsumi.c r: c:
//SET: cyclwarr
		DRIVER(cyclwarr) //t:cyclwarr f:tatsumi.c r: c:
//SET: bigfight
		DRIVER(bigfight) //t:bigfight f:tatsumi.c r: c:
//SET: mugsmash
		DRIVER(mugsmash) //t:mugsmash f:mugsmash.c r: c:
//SET: stlforce
		DRIVER(stlforce) //t:stlforce f:stlforce.c r: c:
//SET: fantland
		DRIVER(fantland) //t:fantland f:fantland.c r: c:
		DRIVER(fantlanda) //t:fantlanda f:fantland.c r:fantland c:fantland
//SET: wheelrun
		DRIVER(wheelrun) //t:wheelrun f:fantland.c r: c:
//SET: galaxygn
		DRIVER(galaxygn) //t:galaxygn f:fantland.c r: c:
//SET: borntofi
		DRIVER(borntofi) //t:borntofi f:fantland.c r: c:
//SET: diverboy
		DRIVER(diverboy) //t:diverboy f:diverboy.c r: c:
//SET: twinbrat
		DRIVER(twinbrat) //t:twinbrat f:stlforce.c r: c:
		DRIVER(twinbrata) //t:twinbrata f:stlforce.c r:twinbrat c:twinbrat
//SET: ppmast93
		DRIVER(ppmast93) //t:ppmast93 f:ppmast93.c r: c:
//SET: twins
		DRIVER(twins) //t:twins f:twins.c r: c:
		DRIVER(twinsa) //t:twinsa f:twins.c r:twins c:twins
//SET: mwarr
		DRIVER(mwarr) //t:mwarr f:mwarr.c r: c:
//SET: pzletime
		DRIVER(pzletime) //t:pzletime f:pzletime.c r: c:
//SET: ar_bios
		DRIVER(ar_bios) //t:ar_bios f:arcadia.c r: c:
//SET: ar_airh
		DRIVER(ar_airh) //t:ar_airh f:arcadia.c r:ar_bios c:
//SET: ar_airh2
		DRIVER(ar_airh2) //t:ar_airh2 f:arcadia.c r:ar_bios c:
//SET: ar_bowl
		DRIVER(ar_bowl) //t:ar_bowl f:arcadia.c r:ar_bios c:
//SET: ar_dart
		DRIVER(ar_dart) //t:ar_dart f:arcadia.c r:ar_bios c:
		DRIVER(ar_dart2) //t:ar_dart2 f:arcadia.c r:ar_dart c:ar_dart
//SET: ar_fast
		DRIVER(ar_fast) //t:ar_fast f:arcadia.c r:ar_bios c:
//SET: ar_ldrb
		DRIVER(ar_ldrb) //t:ar_ldrb f:arcadia.c r:ar_bios c:
		DRIVER(ar_ldrba) //t:ar_ldrba f:arcadia.c r:ar_ldrb c:ar_ldrb
//SET: ar_ninj
		DRIVER(ar_ninj) //t:ar_ninj f:arcadia.c r:ar_bios c:
		DRIVER(ar_ninj2) //t:ar_ninj2 f:arcadia.c r:ar_ninj c:ar_ninj
//SET: ar_rdwr
		DRIVER(ar_rdwr) //t:ar_rdwr f:arcadia.c r:ar_bios c:
//SET: ar_sdwr
		DRIVER(ar_sdwr) //t:ar_sdwr f:arcadia.c r:ar_bios c:
		DRIVER(ar_sdwr2) //t:ar_sdwr2 f:arcadia.c r:ar_sdwr c:ar_sdwr
//SET: ar_socc
		DRIVER(ar_socc) //t:ar_socc f:arcadia.c r:ar_bios c:
//SET: ar_spot
		DRIVER(ar_spot) //t:ar_spot f:arcadia.c r:ar_bios c:
//SET: ar_sprg
		DRIVER(ar_sprg) //t:ar_sprg f:arcadia.c r:ar_bios c:
//SET: ar_xeon
		DRIVER(ar_xeon) //t:ar_xeon f:arcadia.c r:ar_bios c:
//SET: mquake
		DRIVER(mquake) //t:mquake f:mquake.c r: c:
//SET: upscope
		DRIVER(upscope) //t:upscope f:upscope.c r: c:
//SET: cd32
		DRIVER(cd32) //t:cd32 f:cd32.c r: c:
//SET: cndypuzl
		DRIVER(cndypuzl) //t:cndypuzl f:cd32.c r:cd32 c:
//SET: haremchl
		DRIVER(haremchl) //t:haremchl f:cd32.c r:cd32 c:
//SET: lsrquiz
		DRIVER(lsrquiz) //t:lsrquiz f:cd32.c r:cd32 c:
//SET: lsrquiz2
		DRIVER(lsrquiz2) //t:lsrquiz2 f:cd32.c r:cd32 c:
//SET: mgprem11
		DRIVER(mgprem11) //t:mgprem11 f:cd32.c r:cd32 c:
//SET: lasstixx
		DRIVER(lasstixx) //t:lasstixx f:cd32.c r:cd32 c:
//SET: mgnumber
		DRIVER(mgnumber) //t:mgnumber f:cd32.c r:cd32 c:
//SET: odeontw2
		DRIVER(odeontw2) //t:odeontw2 f:cd32.c r:cd32 c:
//SET: alg_bios
		DRIVER(alg_bios) //t:alg_bios f:alg.c r: c:
//SET: wsjr
		DRIVER(wsjr) //t:wsjr f:alg.c r:alg_bios c:
		DRIVER(wsjr15) //t:wsjr15 f:alg.c r:wsjr c:wsjr
//SET: maddog
		DRIVER(maddog) //t:maddog f:alg.c r:alg_bios c:
		DRIVER(maddoga) //t:maddoga f:alg.c r:maddog c:maddog
//SET: maddog2
		DRIVER(maddog2) //t:maddog2 f:alg.c r:alg_bios c:
		DRIVER(maddog21) //t:maddog21 f:alg.c r:maddog2 c:maddog2
//SET: maddog22
		DRIVER(maddog22) //t:maddog22 f:alg.c r:alg_bios c:
//SET: spacepir
		DRIVER(spacepir) //t:spacepir f:alg.c r:alg_bios c:
//SET: gallgall
		DRIVER(gallgall) //t:gallgall f:alg.c r:alg_bios c:
//SET: crimepat
		DRIVER(crimepat) //t:crimepat f:alg.c r:alg_bios c:
//SET: crimep2
		DRIVER(crimep2) //t:crimep2 f:alg.c r:alg_bios c:
		DRIVER(crimep211) //t:crimep211 f:alg.c r:crimep2 c:crimep2
//SET: lastbh
		DRIVER(lastbh) //t:lastbh f:alg.c r:alg_bios c:
//SET: fastdraw
		DRIVER(fastdraw) //t:fastdraw f:alg.c r:alg_bios c:
//SET: aplatoon
		DRIVER(aplatoon) //t:aplatoon f:alg.c r:alg_bios c:
//SET: zortonbr
		DRIVER(zortonbr) //t:zortonbr f:alg.c r:alg_bios c:
//SET: crysbios
		DRIVER(crysbios) //t:crysbios f:crystal.c r: c:
//SET: crysking
		DRIVER(crysking) //t:crysking f:crystal.c r:crysbios c:
//SET: evosocc
		DRIVER(evosocc) //t:evosocc f:crystal.c r:crysbios c:
//SET: topbladv
		DRIVER(topbladv) //t:topbladv f:crystal.c r:crysbios c:
//SET: officeye
		DRIVER(officeye) //t:officeye f:crystal.c r: c:
//SET: ddz
		DRIVER(ddz) //t:ddz f:ddz.c r: c:
//SET: psattack
		DRIVER(psattack) //t:psattack f:psattack.c r: c:
//SET: inquiztr
		DRIVER(inquiztr) //t:inquiztr f:bfcobra.c r: c:
//SET: escounts
		DRIVER(escounts) //t:escounts f:bfcobra.c r: c:
//SET: trebltop
		DRIVER(trebltop) //t:trebltop f:bfcobra.c r: c:
//SET: beeline
		DRIVER(beeline) //t:beeline f:bfcobra.c r: c:
//SET: quizvadr
		DRIVER(quizvadr) //t:quizvadr f:bfcobra.c r: c:
//SET: qos
		DRIVER(qos) //t:qos f:bfcobra.c r: c:
		DRIVER(qosa) //t:qosa f:bfcobra.c r:qos c:qos
		DRIVER(qosb) //t:qosb f:bfcobra.c r:qos c:qos
//SET: quintoon
		DRIVER(quintoon) //t:quintoon f:bfm_sc2.c r: c:
		DRIVER(quintond) //t:quintond f:bfm_sc2.c r:quintoon c:quintoon
		DRIVER(quintono) //t:quintono f:bfm_sc2.c r:quintoon c:quintoon
//SET: qntoond
		DRIVER(qntoond) //t:qntoond f:bfm_sc2.c r: c:
		DRIVER(qntoondo) //t:qntoondo f:bfm_sc2.c r:qntoond c:qntoond
//SET: pokio
		DRIVER(pokio) //t:pokio f:bfm_sc2.c r: c:
//SET: slotsnl
		DRIVER(slotsnl) //t:slotsnl f:bfm_sc2.c r: c:
//SET: paradice
		DRIVER(paradice) //t:paradice f:bfm_sc2.c r: c:
//SET: pyramid
		DRIVER(pyramid) //t:pyramid f:bfm_sc2.c r: c:
//SET: sltblgtk
		DRIVER(sltblgtk) //t:sltblgtk f:bfm_sc2.c r: c:
//SET: sltblgpo
		DRIVER(sltblgpo) //t:sltblgpo f:bfm_sc2.c r: c:
		DRIVER(sltblgp1) //t:sltblgp1 f:bfm_sc2.c r:sltblgpo c:sltblgpo
//SET: gldncrwn
		DRIVER(gldncrwn) //t:gldncrwn f:bfm_sc2.c r: c:
//SET: mpu4utst
		DRIVER(mpu4utst) //t:mpu4utst f:mpu4.c r: c:
//SET: mpu4tst2
		DRIVER(mpu4tst2) //t:mpu4tst2 f:mpu4.c r: c:
//SET: mpu4met0
		DRIVER(mpu4met0) //t:mpu4met0 f:mpu4.c r: c:
//SET: connect4
		DRIVER(connect4) //t:connect4 f:mpu4.c r: c:
//SET: bctvidbs
		DRIVER(bctvidbs) //t:bctvidbs f:mpu4drvr.c r: c:
//SET: dealem
		DRIVER(dealem) //t:dealem f:mpu4drvr.c r: c:
//SET: adders
		DRIVER(adders) //t:adders f:mpu4drvr.c r:bctvidbs c:
//SET: timemchn
		DRIVER(timemchn) //t:timemchn f:mpu4drvr.c r:bctvidbs c:
//SET: turnover
		DRIVER(turnover) //t:turnover f:mpu4drvr.c r:bctvidbs c:
//SET: skiltrek
		DRIVER(skiltrek) //t:skiltrek f:mpu4drvr.c r:bctvidbs c:
//SET: crmaze
		DRIVER(crmaze) //t:crmaze f:mpu4drvr.c r:bctvidbs c:
		DRIVER(crmazed) //t:crmazed f:mpu4drvr.c r:crmaze c:crmaze
		DRIVER(crmazea) //t:crmazea f:mpu4drvr.c r:crmaze c:crmaze
//SET: crmaze2
		DRIVER(crmaze2) //t:crmaze2 f:mpu4drvr.c r:bctvidbs c:
		DRIVER(crmaze2d) //t:crmaze2d f:mpu4drvr.c r:crmaze2 c:crmaze2
		DRIVER(crmaze2a) //t:crmaze2a f:mpu4drvr.c r:crmaze2 c:crmaze2
//SET: crmaze3
		DRIVER(crmaze3) //t:crmaze3 f:mpu4drvr.c r:bctvidbs c:
		DRIVER(crmaze3d) //t:crmaze3d f:mpu4drvr.c r:crmaze3 c:crmaze3
		DRIVER(crmaze3a) //t:crmaze3a f:mpu4drvr.c r:crmaze3 c:crmaze3
//SET: mating
		DRIVER(mating) //t:mating f:mpu4drvr.c r:bctvidbs c:
		DRIVER(matingd) //t:matingd f:mpu4drvr.c r:mating c:mating
//SET: strikeit
		DRIVER(strikeit) //t:strikeit f:mpu4drvr.c r:bctvidbs c:
		DRIVER(strikeitd) //t:strikeitd f:mpu4drvr.c r:strikeit c:strikeit
		DRIVER(strikeit2) //t:strikeit2 f:mpu4drvr.c r:strikeit c:strikeit
		DRIVER(strikeit2d) //t:strikeit2d f:mpu4drvr.c r:strikeit c:strikeit
//SET: quidgrid
		DRIVER(quidgrid) //t:quidgrid f:mpu4drvr.c r:bctvidbs c:
		DRIVER(quidgridd) //t:quidgridd f:mpu4drvr.c r:quidgrid c:quidgrid
		DRIVER(quidgrid2) //t:quidgrid2 f:mpu4drvr.c r:quidgrid c:quidgrid
		DRIVER(quidgrid2d) //t:quidgrid2d f:mpu4drvr.c r:quidgrid c:quidgrid
//SET: eyesdown
		DRIVER(eyesdown) //t:eyesdown f:mpu4drvr.c r:bctvidbs c:
		DRIVER(eyesdownd) //t:eyesdownd f:mpu4drvr.c r:eyesdown c:eyesdown
//SET: blox
		DRIVER(blox) //t:blox f:mpu4drvr.c r: c:
		DRIVER(bloxd) //t:bloxd f:mpu4drvr.c r:blox c:blox
//SET: bwbtetrs
		DRIVER(bwbtetrs) //t:bwbtetrs f:mpu4drvr.c r: c:
//SET: prizeinv
		DRIVER(prizeinv) //t:prizeinv f:mpu4drvr.c r: c:
//SET: vgpoker
		DRIVER(vgpoker) //t:vgpoker f:mpu4drvr.c r: c:
//SET: renoreel
		DRIVER(renoreel) //t:renoreel f:mpu4drvr.c r: c:
//SET: redhtpkr
		DRIVER(redhtpkr) //t:redhtpkr f:mpu4drvr.c r: c:
//SET: backgamn
		DRIVER(backgamn) //t:backgamn f:adp.c r: c:
//SET: quickjac
		DRIVER(quickjac) //t:quickjac f:adp.c r: c:
//SET: skattv
		DRIVER(skattv) //t:skattv f:adp.c r: c:
		DRIVER(skattva) //t:skattva f:adp.c r:skattv c:skattv
//SET: fashiong
		DRIVER(fashiong) //t:fashiong f:adp.c r: c:
		DRIVER(fashiong2) //t:fashiong2 f:adp.c r:fashiong c:fashiong
//SET: fstation
		DRIVER(fstation) //t:fstation f:adp.c r: c:
//SET: funlddlx
		DRIVER(funlddlx) //t:funlddlx f:adp.c r: c:
//SET: guab
		DRIVER(guab) //t:guab f:guab.c r: c:
		DRIVER(guab3a) //t:guab3a f:guab.c r:guab c:guab
		DRIVER(guab4) //t:guab4 f:guab.c r:guab c:guab
		DRIVER(guab6) //t:guab6 f:guab.c r:guab c:guab
		DRIVER(guab6a) //t:guab6a f:guab.c r:guab c:guab
		DRIVER(guab7) //t:guab7 f:guab.c r:guab c:guab
		DRIVER(guab21) //t:guab21 f:guab.c r:guab c:guab
		DRIVER(guab43) //t:guab43 f:guab.c r:guab c:guab
//SET: crisscrs
		DRIVER(crisscrs) //t:crisscrs f:guab.c r: c:
//SET: tenup
		DRIVER(tenup) //t:tenup f:guab.c r: c:
		DRIVER(tenup3) //t:tenup3 f:guab.c r:tenup c:tenup
//SET: monopoly
		DRIVER(monopoly) //t:monopoly f:jpmsys5.c r: c:
		DRIVER(monoplcl) //t:monoplcl f:jpmsys5.c r:monopoly c:monopoly
//SET: monopldx
		DRIVER(monopldx) //t:monopldx f:jpmsys5.c r: c:
//SET: cluedo
		DRIVER(cluedo) //t:cluedo f:jpmimpct.c r: c:
		DRIVER(cluedo2c) //t:cluedo2c f:jpmimpct.c r:cluedo c:cluedo
		DRIVER(cluedo2) //t:cluedo2 f:jpmimpct.c r:cluedo c:cluedo
//SET: trivialp
		DRIVER(trivialp) //t:trivialp f:jpmimpct.c r: c:
//SET: scrabble
		DRIVER(scrabble) //t:scrabble f:jpmimpct.c r: c:
//SET: hngmnjpm
		DRIVER(hngmnjpm) //t:hngmnjpm f:jpmimpct.c r: c:
//SET: coronatn
		DRIVER(coronatn) //t:coronatn f:jpmimpct.c r: c:
//SET: vega
		DRIVER(vega) //t:vega f:vega.c r: c:
//SET: kamikaze
		DRIVER(kamikaze) //t:kamikaze f:astinvad.c r: c:
		DRIVER(astinvad) //t:astinvad f:astinvad.c r:kamikaze c:kamikaze
		DRIVER(kosmokil) //t:kosmokil f:astinvad.c r:kamikaze c:kamikaze
//SET: spcking2
		DRIVER(spcking2) //t:spcking2 f:astinvad.c r: c:
//SET: spaceint
		DRIVER(spaceint) //t:spaceint f:astinvad.c r: c:
		DRIVER(spaceintj) //t:spaceintj f:astinvad.c r:spaceint c:spaceint
//SET: spacefb
		DRIVER(spacefb) //t:spacefb f:spacefb.c r: c:
		DRIVER(spacefbu) //t:spacefbu f:spacefb.c r:spacefb c:spacefb
		DRIVER(spacefbe) //t:spacefbe f:spacefb.c r:spacefb c:spacefb
		DRIVER(spacefbg) //t:spacefbg f:spacefb.c r:spacefb c:spacefb
		DRIVER(spacefbb) //t:spacefbb f:spacefb.c r:spacefb c:spacefb
		DRIVER(spacebrd) //t:spacebrd f:spacefb.c r:spacefb c:spacefb
		DRIVER(spacedem) //t:spacedem f:spacefb.c r:spacefb c:spacefb
//SET: omegrace
		DRIVER(omegrace) //t:omegrace f:omegrace.c r: c:
		DRIVER(omegrace2) //t:omegrace2 f:omegrace.c r:omegrace c:omegrace
		DRIVER(deltrace) //t:deltrace f:omegrace.c r:omegrace c:omegrace
//SET: monzagp
		DRIVER(monzagp) //t:monzagp f:monzagp.c r: c:
//SET: dday
		DRIVER(dday) //t:dday f:dday.c r: c:
		DRIVER(ddayc) //t:ddayc f:dday.c r:dday c:dday
//SET: stactics
		DRIVER(stactics) //t:stactics f:stactics.c r: c:
//SET: exterm
		DRIVER(exterm) //t:exterm f:exterm.c r: c:
//SET: flower
		DRIVER(flower) //t:flower f:flower.c r: c:
		DRIVER(flowerj) //t:flowerj f:flower.c r:flower c:flower
//SET: kingofb
		DRIVER(kingofb) //t:kingofb f:kingobox.c r: c:
		DRIVER(ringking) //t:ringking f:kingobox.c r:kingofb c:kingofb
		DRIVER(ringking2) //t:ringking2 f:kingobox.c r:kingofb c:kingofb
		DRIVER(ringking3) //t:ringking3 f:kingobox.c r:kingofb c:kingofb
		DRIVER(ringkingw) //t:ringkingw f:kingobox.c r:kingofb c:kingofb
#endif

#ifdef PS3_SET_13
//SET: dlair
		DRIVER(dlair) //t:dlair f:dlair.c r: c:
		DRIVER(dlairf) //t:dlairf f:dlair.c r:dlair c:dlair
		DRIVER(dlaire) //t:dlaire f:dlair.c r:dlair c:dlair
		DRIVER(dlaird) //t:dlaird f:dlair.c r:dlair c:dlair
		DRIVER(dlairc) //t:dlairc f:dlair.c r:dlair c:dlair
		DRIVER(dlairb) //t:dlairb f:dlair.c r:dlair c:dlair
		DRIVER(dlaira) //t:dlaira f:dlair.c r:dlair c:dlair
		DRIVER(dleuro) //t:dleuro f:dlair.c r:dlair c:dlair
		DRIVER(dlital) //t:dlital f:dlair.c r:dlair c:dlair
//SET: spaceace
		DRIVER(spaceace) //t:spaceace f:dlair.c r: c:
		DRIVER(spaceaa2) //t:spaceaa2 f:dlair.c r:spaceace c:spaceace
		DRIVER(spaceaa) //t:spaceaa f:dlair.c r:spaceace c:spaceace
		DRIVER(saeuro) //t:saeuro f:dlair.c r:spaceace c:spaceace
//SET: aztarac
		DRIVER(aztarac) //t:aztarac f:aztarac.c r: c:
//SET: mole
		DRIVER(mole) //t:mole f:mole.c r: c:
//SET: thehand
		DRIVER(thehand) //t:thehand f:gotya.c r: c:
		DRIVER(gotya) //t:gotya f:gotya.c r:thehand c:thehand
//SET: mrjong
		DRIVER(mrjong) //t:mrjong f:mrjong.c r: c:
		DRIVER(crazyblk) //t:crazyblk f:mrjong.c r:mrjong c:mrjong
		DRIVER(blkbustr) //t:blkbustr f:mrjong.c r:mrjong c:mrjong
//SET: polyplay
		DRIVER(polyplay) //t:polyplay f:polyplay.c r: c:
//SET: amspdwy
		DRIVER(amspdwy) //t:amspdwy f:amspdwy.c r: c:
		DRIVER(amspdwya) //t:amspdwya f:amspdwy.c r:amspdwy c:amspdwy
//SET: othldrby
		DRIVER(othldrby) //t:othldrby f:othldrby.c r: c:
//SET: quizpun2
		DRIVER(quizpun2) //t:quizpun2 f:quizpun2.c r: c:
//SET: mosaic
		DRIVER(mosaic) //t:mosaic f:mosaic.c r: c:
		DRIVER(mosaica) //t:mosaica f:mosaic.c r:mosaic c:mosaic
//SET: gfire2
		DRIVER(gfire2) //t:gfire2 f:mosaic.c r: c:
//SET: sprcros2
		DRIVER(sprcros2) //t:sprcros2 f:sprcros2.c r: c:
		DRIVER(sprcros2a) //t:sprcros2a f:sprcros2.c r:sprcros2 c:sprcros2
//SET: d9final
		DRIVER(d9final) //t:d9final f:d9final.c r: c:
//SET: lastbank
		DRIVER(lastbank) //t:lastbank f:lastbank.c r: c:
//SET: gcpinbal
		DRIVER(gcpinbal) //t:gcpinbal f:gcpinbal.c r: c:
//SET: vmetal
		DRIVER(vmetal) //t:vmetal f:vmetal.c r: c:
		DRIVER(vmetaln) //t:vmetaln f:vmetal.c r:vmetal c:vmetal
//SET: aquarium
		DRIVER(aquarium) //t:aquarium f:aquarium.c r: c:
//SET: policetr
		DRIVER(policetr) //t:policetr f:policetr.c r: c:
		DRIVER(policetr11) //t:policetr11 f:policetr.c r:policetr c:policetr
		DRIVER(policetr10) //t:policetr10 f:policetr.c r:policetr c:policetr
		DRIVER(policetr13a) //t:policetr13a f:policetr.c r:policetr c:policetr
		DRIVER(policetr13b) //t:policetr13b f:policetr.c r:policetr c:policetr
//SET: sshooter
		DRIVER(sshooter) //t:sshooter f:policetr.c r: c:
		DRIVER(sshooter12) //t:sshooter12 f:policetr.c r:sshooter c:sshooter
		DRIVER(sshooter11) //t:sshooter11 f:policetr.c r:sshooter c:sshooter
//SET: pass
		DRIVER(pass) //t:pass f:pass.c r: c:
//SET: news
		DRIVER(news) //t:news f:news.c r: c:
		DRIVER(newsa) //t:newsa f:news.c r:news c:news
//SET: taxidrvr
		DRIVER(taxidrvr) //t:taxidrvr f:taxidrvr.c r: c:
//SET: xyonix
		DRIVER(xyonix) //t:xyonix f:xyonix.c r: c:
//SET: gt507uk
		DRIVER(gt507uk) //t:gt507uk f:gei.c r: c:
//SET: gt5
		DRIVER(gt5) //t:gt5 f:gei.c r: c:
//SET: gtsers8
		DRIVER(gtsers8) //t:gtsers8 f:gei.c r: c:
		DRIVER(gtsers9) //t:gtsers9 f:gei.c r:gtsers8 c:gtsers8
		DRIVER(gtsers10) //t:gtsers10 f:gei.c r:gtsers8 c:gtsers8
		DRIVER(gtsers11) //t:gtsers11 f:gei.c r:gtsers8 c:gtsers8
		DRIVER(gt103a1) //t:gt103a1 f:gei.c r:gtsers8 c:gtsers8
		DRIVER(gt103a2) //t:gt103a2 f:gei.c r:gtsers8 c:gtsers8
		DRIVER(gt103a3) //t:gt103a3 f:gei.c r:gtsers8 c:gtsers8
		DRIVER(gt103aa) //t:gt103aa f:gei.c r:gtsers8 c:gtsers8
		DRIVER(gt103asx) //t:gt103asx f:gei.c r:gtsers8 c:gtsers8
//SET: reelfun
		DRIVER(reelfun) //t:reelfun f:gei.c r: c:
		DRIVER(reelfun1) //t:reelfun1 f:gei.c r:reelfun c:reelfun
//SET: findout
		DRIVER(findout) //t:findout f:gei.c r: c:
//SET: quizvid
		DRIVER(quizvid) //t:quizvid f:gei.c r: c:
//SET: quiz
		DRIVER(quiz) //t:quiz f:gei.c r: c:
//SET: quiz211
		DRIVER(quiz211) //t:quiz211 f:gei.c r: c:
//SET: jokpoker
		DRIVER(jokpoker) //t:jokpoker f:gei.c r: c:
		DRIVER(jokpokera) //t:jokpokera f:gei.c r:jokpoker c:jokpoker
		DRIVER(jokpokerb) //t:jokpokerb f:gei.c r:jokpoker c:jokpoker
		DRIVER(jokpokerc) //t:jokpokerc f:gei.c r:jokpoker c:jokpoker
//SET: superbwl
		DRIVER(superbwl) //t:superbwl f:gei.c r: c:
//SET: amuse
		DRIVER(amuse) //t:amuse f:gei.c r: c:
		DRIVER(amuse1) //t:amuse1 f:gei.c r:amuse c:amuse
//SET: gs4002
		DRIVER(gs4002) //t:gs4002 f:gei.c r: c:
		DRIVER(gs4002a) //t:gs4002a f:gei.c r:gs4002 c:gs4002
//SET: gepoker
		DRIVER(gepoker) //t:gepoker f:gei.c r: c:
		DRIVER(gepoker1) //t:gepoker1 f:gei.c r:gepoker c:gepoker
		DRIVER(gepoker2) //t:gepoker2 f:gei.c r:gepoker c:gepoker
//SET: gtsers1
		DRIVER(gtsers1) //t:gtsers1 f:gei.c r: c:
		DRIVER(gtsers2) //t:gtsers2 f:gei.c r:gtsers1 c:gtsers1
		DRIVER(gtsers3) //t:gtsers3 f:gei.c r:gtsers1 c:gtsers1
		DRIVER(gtsers4) //t:gtsers4 f:gei.c r:gtsers1 c:gtsers1
		DRIVER(gtsers5) //t:gtsers5 f:gei.c r:gtsers1 c:gtsers1
		DRIVER(gtsers7) //t:gtsers7 f:gei.c r:gtsers1 c:gtsers1
		DRIVER(gtsersa) //t:gtsersa f:gei.c r:gtsers1 c:gtsers1
		DRIVER(gtsersb) //t:gtsersb f:gei.c r:gtsers1 c:gtsers1
//SET: sextriv1
		DRIVER(sextriv1) //t:sextriv1 f:gei.c r: c:
		DRIVER(sextriv2) //t:sextriv2 f:gei.c r:sextriv1 c:sextriv1
//SET: geimulti
		DRIVER(geimulti) //t:geimulti f:gei.c r: c:
//SET: sprtauth
		DRIVER(sprtauth) //t:sprtauth f:gei.c r: c:
//SET: suprpokr
		DRIVER(suprpokr) //t:suprpokr f:gei.c r: c:
		DRIVER(suprpkr1) //t:suprpkr1 f:gei.c r:suprpokr c:suprpokr
//SET: dribling
		DRIVER(dribling) //t:dribling f:dribling.c r: c:
		DRIVER(driblingo) //t:driblingo f:dribling.c r:dribling c:dribling
//SET: ace
		DRIVER(ace) //t:ace f:ace.c r: c:
//SET: clayshoo
		DRIVER(clayshoo) //t:clayshoo f:clayshoo.c r: c:
//SET: pirates
		DRIVER(pirates) //t:pirates f:pirates.c r: c:
//SET: genix
		DRIVER(genix) //t:genix f:pirates.c r: c:
//SET: fitfight
		DRIVER(fitfight) //t:fitfight f:fitfight.c r: c:
//SET: histryma
		DRIVER(histryma) //t:histryma f:fitfight.c r: c:
//SET: bbprot
		DRIVER(bbprot) //t:bbprot f:fitfight.c r: c:
//SET: beaminv
		DRIVER(beaminv) //t:beaminv f:beaminv.c r: c:
		DRIVER(beaminva) //t:beaminva f:beaminv.c r:beaminv c:beaminv
//SET: mcatadv
		DRIVER(mcatadv) //t:mcatadv f:mcatadv.c r: c:
		DRIVER(mcatadvj) //t:mcatadvj f:mcatadv.c r:mcatadv c:mcatadv
		DRIVER(catt) //t:catt f:mcatadv.c r:mcatadv c:mcatadv
//SET: nost
		DRIVER(nost) //t:nost f:mcatadv.c r: c:
		DRIVER(nostj) //t:nostj f:mcatadv.c r:nost c:nost
		DRIVER(nostk) //t:nostk f:mcatadv.c r:nost c:nost
//SET: 4enraya
		DRIVER(4enraya) //t:4enraya f:4enraya.c r: c:
//SET: oneshot
		DRIVER(oneshot) //t:oneshot f:oneshot.c r: c:
//SET: maddonna
		DRIVER(maddonna) //t:maddonna f:oneshot.c r: c:
		DRIVER(maddonnb) //t:maddonnb f:oneshot.c r:maddonna c:maddonna
//SET: tugboat
		DRIVER(tugboat) //t:tugboat f:tugboat.c r: c:
//SET: noahsark
		DRIVER(noahsark) //t:noahsark f:tugboat.c r: c:
//SET: berenstn
		DRIVER(berenstn) //t:berenstn f:tugboat.c r: c:
//SET: gotcha
		DRIVER(gotcha) //t:gotcha f:gotcha.c r: c:
		DRIVER(ppchamp) //t:ppchamp f:gotcha.c r:gotcha c:gotcha
//SET: amerdart
		DRIVER(amerdart) //t:amerdart f:coolpool.c r: c:
		DRIVER(amerdart2) //t:amerdart2 f:coolpool.c r:amerdart c:amerdart
		DRIVER(amerdart3) //t:amerdart3 f:coolpool.c r:amerdart c:amerdart
//SET: coolpool
		DRIVER(coolpool) //t:coolpool f:coolpool.c r: c:
//SET: 9ballsht
		DRIVER(9ballsht) //t:9ballsht f:coolpool.c r: c:
		DRIVER(9ballsht2) //t:9ballsht2 f:coolpool.c r:9ballsht c:9ballsht
		DRIVER(9ballsht3) //t:9ballsht3 f:coolpool.c r:9ballsht c:9ballsht
		DRIVER(9ballshtc) //t:9ballshtc f:coolpool.c r:9ballsht c:9ballsht
//SET: gumbo
		DRIVER(gumbo) //t:gumbo f:gumbo.c r: c:
		DRIVER(mspuzzleg) //t:mspuzzleg f:gumbo.c r:gumbo c:gumbo
//SET: mspuzzle
		DRIVER(mspuzzle) //t:mspuzzle f:gumbo.c r: c:
		DRIVER(mspuzzlen) //t:mspuzzlen f:gumbo.c r:mspuzzle c:mspuzzle
//SET: msbingo
		DRIVER(msbingo) //t:msbingo f:gumbo.c r: c:
//SET: dblpoint
		DRIVER(dblpoint) //t:dblpoint f:gumbo.c r: c:
		DRIVER(dblpointd) //t:dblpointd f:gumbo.c r:dblpoint c:dblpoint
//SET: statusbj
		DRIVER(statusbj) //t:statusbj f:statriv2.c r: c:
//SET: tripdraw
		DRIVER(tripdraw) //t:tripdraw f:statriv2.c r: c:
//SET: funcsino
		DRIVER(funcsino) //t:funcsino f:statriv2.c r: c:
//SET: hangman
		DRIVER(hangman) //t:hangman f:statriv2.c r: c:
//SET: trivquiz
		DRIVER(trivquiz) //t:trivquiz f:statriv2.c r: c:
//SET: statriv2
		DRIVER(statriv2) //t:statriv2 f:statriv2.c r: c:
		DRIVER(statriv2v) //t:statriv2v f:statriv2.c r:statriv2 c:statriv2
//SET: statriv4
		DRIVER(statriv4) //t:statriv4 f:statriv2.c r: c:
//SET: sextriv
		DRIVER(sextriv) //t:sextriv f:statriv2.c r: c:
//SET: quaquiz2
		DRIVER(quaquiz2) //t:quaquiz2 f:statriv2.c r: c:
//SET: supertr2
		DRIVER(supertr2) //t:supertr2 f:statriv2.c r: c:
//SET: supertr3
		DRIVER(supertr3) //t:supertr3 f:statriv2.c r: c:
//SET: cstripxi
		DRIVER(cstripxi) //t:cstripxi f:statriv2.c r: c:
//SET: tickee
		DRIVER(tickee) //t:tickee f:tickee.c r: c:
//SET: ghoshunt
		DRIVER(ghoshunt) //t:ghoshunt f:tickee.c r: c:
//SET: tutstomb
		DRIVER(tutstomb) //t:tutstomb f:tickee.c r: c:
//SET: mouseatk
		DRIVER(mouseatk) //t:mouseatk f:tickee.c r: c:
//SET: rapidfir
		DRIVER(rapidfir) //t:rapidfir f:tickee.c r: c:
		DRIVER(rapidfire) //t:rapidfire f:tickee.c r:rapidfir c:rapidfir
//SET: maletmad
		DRIVER(maletmad) //t:maletmad f:tickee.c r: c:
//SET: crgolf
		DRIVER(crgolf) //t:crgolf f:crgolf.c r: c:
		DRIVER(crgolfa) //t:crgolfa f:crgolf.c r:crgolf c:crgolf
		DRIVER(crgolfb) //t:crgolfb f:crgolf.c r:crgolf c:crgolf
		DRIVER(crgolfc) //t:crgolfc f:crgolf.c r:crgolf c:crgolf
		DRIVER(crgolfbt) //t:crgolfbt f:crgolf.c r:crgolf c:crgolf
//SET: crgolfhi
		DRIVER(crgolfhi) //t:crgolfhi f:crgolf.c r: c:
//SET: truco
		DRIVER(truco) //t:truco f:truco.c r: c:
//SET: thedeep
		DRIVER(thedeep) //t:thedeep f:thedeep.c r: c:
		DRIVER(rundeep) //t:rundeep f:thedeep.c r:thedeep c:thedeep
//SET: wallc
		DRIVER(wallc) //t:wallc f:wallc.c r: c:
		DRIVER(wallca) //t:wallca f:wallc.c r:wallc c:wallc
//SET: wink
		DRIVER(wink) //t:wink f:wink.c r: c:
		DRIVER(winka) //t:winka f:wink.c r:wink c:wink
//SET: skyarmy
		DRIVER(skyarmy) //t:skyarmy f:skyarmy.c r: c:
//SET: lethalj
		DRIVER(lethalj) //t:lethalj f:lethalj.c r: c:
//SET: eggventr
		DRIVER(eggventr) //t:eggventr f:lethalj.c r: c:
		DRIVER(eggventr8) //t:eggventr8 f:lethalj.c r:eggventr c:eggventr
		DRIVER(eggventr7) //t:eggventr7 f:lethalj.c r:eggventr c:eggventr
		DRIVER(eggventra) //t:eggventra f:lethalj.c r:eggventr c:eggventr
		DRIVER(eggventrd) //t:eggventrd f:lethalj.c r:eggventr c:eggventr
//SET: calchase
		DRIVER(calchase) //t:calchase f:calchase.c r: c:
//SET: ripribit
		DRIVER(ripribit) //t:ripribit f:lethalj.c r: c:
//SET: cfarm
		DRIVER(cfarm) //t:cfarm f:lethalj.c r: c:
//SET: cclownz
		DRIVER(cclownz) //t:cclownz f:lethalj.c r: c:
//SET: rotaryf
		DRIVER(rotaryf) //t:rotaryf f:rotaryf.c r: c:
//SET: portrait
		DRIVER(portrait) //t:portrait f:portrait.c r: c:
		DRIVER(portraita) //t:portraita f:portrait.c r:portrait c:portrait
//SET: enigma2
		DRIVER(enigma2) //t:enigma2 f:enigma2.c r: c:
		DRIVER(enigma2a) //t:enigma2a f:enigma2.c r:enigma2 c:enigma2
		DRIVER(enigma2b) //t:enigma2b f:enigma2.c r:enigma2 c:enigma2
//SET: ltcasino
		DRIVER(ltcasino) //t:ltcasino f:ltcasino.c r: c:
		DRIVER(mv4in1) //t:mv4in1 f:ltcasino.c r:ltcasino c:ltcasino
//SET: ltcasinn
		DRIVER(ltcasinn) //t:ltcasinn f:ltcasino.c r: c:
//SET: coolmini
		DRIVER(coolmini) //t:coolmini f:vamphalf.c r: c:
//SET: suplup
		DRIVER(suplup) //t:suplup f:vamphalf.c r: c:
		DRIVER(luplup) //t:luplup f:vamphalf.c r:suplup c:suplup
		DRIVER(luplup29) //t:luplup29 f:vamphalf.c r:suplup c:suplup
		DRIVER(puzlbang) //t:puzlbang f:vamphalf.c r:suplup c:suplup
//SET: jmpbreak
		DRIVER(jmpbreak) //t:jmpbreak f:vamphalf.c r: c:
//SET: vamphalf
		DRIVER(vamphalf) //t:vamphalf f:vamphalf.c r: c:
		DRIVER(vamphalfk) //t:vamphalfk f:vamphalf.c r:vamphalf c:vamphalf
//SET: dquizgo2
		DRIVER(dquizgo2) //t:dquizgo2 f:vamphalf.c r: c:
//SET: misncrft
		DRIVER(misncrft) //t:misncrft f:vamphalf.c r: c:
//SET: mrdig
		DRIVER(mrdig) //t:mrdig f:vamphalf.c r: c:
//SET: hidnctch
		DRIVER(hidnctch) //t:hidnctch f:eolith.c r: c:
//SET: ironfort
		DRIVER(ironfort) //t:ironfort f:eolith.c r: c:
		DRIVER(ironfortj) //t:ironfortj f:eolith.c r:ironfort c:ironfort
//SET: puzzlekg
		DRIVER(puzzlekg) //t:puzzlekg f:eolith.c r: c:
//SET: hidctch2
		DRIVER(hidctch2) //t:hidctch2 f:eolith.c r: c:
		DRIVER(hidctch2a) //t:hidctch2a f:eolith.c r:hidctch2 c:hidctch2
//SET: nhidctch
		DRIVER(nhidctch) //t:nhidctch f:eolith.c r: c:
//SET: landbrk
		DRIVER(landbrk) //t:landbrk f:eolith.c r: c:
		DRIVER(landbrka) //t:landbrka f:eolith.c r:landbrk c:landbrk
//SET: penfan
		DRIVER(penfan) //t:penfan f:eolith.c r: c:
//SET: raccoon
		DRIVER(raccoon) //t:raccoon f:eolith.c r: c:
//SET: fort2b
		DRIVER(fort2b) //t:fort2b f:eolith.c r: c:
		DRIVER(fort2ba) //t:fort2ba f:eolith.c r:fort2b c:fort2b
//SET: klondkp
		DRIVER(klondkp) //t:klondkp f:eolith16.c r: c:
//SET: hidctch3
		DRIVER(hidctch3) //t:hidctch3 f:eolith.c r: c:
//SET: crazywar
		DRIVER(crazywar) //t:crazywar f:vegaeo.c r: c:
//SET: bballoon
		DRIVER(bballoon) //t:bballoon f:ghosteo.c r: c:
//SET: hapytour
		DRIVER(hapytour) //t:hapytour f:ghosteo.c r: c:
//SET: funkball
		DRIVER(funkball) //t:funkball f:funkball.c r: c:
//SET: xfiles
		DRIVER(xfiles) //t:xfiles f:dgpix.c r: c:
//SET: kdynastg
		DRIVER(kdynastg) //t:kdynastg f:dgpix.c r: c:
//SET: fmaniac3
		DRIVER(fmaniac3) //t:fmaniac3 f:dgpix.c r: c:
//SET: promutrv
		DRIVER(promutrv) //t:promutrv f:ettrivia.c r: c:
		DRIVER(promutrva) //t:promutrva f:ettrivia.c r:promutrv c:promutrv
		DRIVER(promutrvb) //t:promutrvb f:ettrivia.c r:promutrv c:promutrv
		DRIVER(promutrvc) //t:promutrvc f:ettrivia.c r:promutrv c:promutrv
//SET: strvmstr
		DRIVER(strvmstr) //t:strvmstr f:ettrivia.c r: c:
//SET: dorachan
		DRIVER(dorachan) //t:dorachan f:dorachan.c r: c:
//SET: ladyfrog
		DRIVER(ladyfrog) //t:ladyfrog f:ladyfrog.c r: c:
//SET: toucheme
		DRIVER(toucheme) //t:toucheme f:ladyfrog.c r: c:
//SET: rabbit
		DRIVER(rabbit) //t:rabbit f:rabbit.c r: c:
//SET: tmmjprd
		DRIVER(tmmjprd) //t:tmmjprd f:tmmjprd.c r: c:
		DRIVER(tmpdoki) //t:tmpdoki f:tmmjprd.c r:tmmjprd c:tmmjprd
//SET: malzak
		DRIVER(malzak) //t:malzak f:malzak.c r: c:
		DRIVER(malzak2) //t:malzak2 f:malzak.c r:malzak c:malzak
//SET: supertnk
		DRIVER(supertnk) //t:supertnk f:supertnk.c r: c:
//SET: crospang
		DRIVER(crospang) //t:crospang f:crospang.c r: c:
//SET: heuksun
		DRIVER(heuksun) //t:heuksun f:crospang.c r: c:
//SET: bestri
		DRIVER(bestri) //t:bestri f:crospang.c r: c:
//SET: funybubl
		DRIVER(funybubl) //t:funybubl f:funybubl.c r: c:
		DRIVER(funybublc) //t:funybublc f:funybubl.c r:funybubl c:funybubl
//SET: dcheese
		DRIVER(dcheese) //t:dcheese f:dcheese.c r: c:
//SET: lottof2
		DRIVER(lottof2) //t:lottof2 f:dcheese.c r: c:
//SET: fredmem
		DRIVER(fredmem) //t:fredmem f:dcheese.c r: c:
		DRIVER(fredmemus) //t:fredmemus f:dcheese.c r:fredmem c:fredmem
		DRIVER(fredmemuk) //t:fredmemuk f:dcheese.c r:fredmem c:fredmem
		DRIVER(fredmemj) //t:fredmemj f:dcheese.c r:fredmem c:fredmem
		DRIVER(fredmemc) //t:fredmemc f:dcheese.c r:fredmem c:fredmem
		DRIVER(fredmesp) //t:fredmesp f:dcheese.c r:fredmem c:fredmem
//SET: cecmatch
		DRIVER(cecmatch) //t:cecmatch f:dcheese.c r: c:
//SET: f15se
		DRIVER(f15se) //t:f15se f:micro3d.c r: c:
		DRIVER(f15se21) //t:f15se21 f:micro3d.c r:f15se c:f15se
//SET: botss
		DRIVER(botss) //t:botss f:micro3d.c r: c:
		DRIVER(botssa) //t:botssa f:micro3d.c r:botss c:botss
//SET: tankbatl
		DRIVER(tankbatl) //t:tankbatl f:micro3d.c r: c:
//SET: dynadice
		DRIVER(dynadice) //t:dynadice f:dynadice.c r: c:
//SET: atamanot
		DRIVER(atamanot) //t:atamanot f:ssingles.c r: c:
//SET: ssingles
		DRIVER(ssingles) //t:ssingles f:ssingles.c r: c:
//SET: tcl
		DRIVER(tcl) //t:tcl f:tcl.c r: c:
//SET: othello
		DRIVER(othello) //t:othello f:othello.c r: c:
//SET: sothello
		DRIVER(sothello) //t:sothello f:sothello.c r: c:
//SET: quake
		DRIVER(quake) //t:quake f:quakeat.c r: c:
//SET: macsbios
		DRIVER(macsbios) //t:macsbios f:macs.c r: c:
//SET: mac2bios
		DRIVER(mac2bios) //t:mac2bios f:macs.c r: c:

//SET: kisekaem
		DRIVER(kisekaem) //t:kisekaem f:macs.c r:macsbios c:
//SET: kisekaeh
		DRIVER(kisekaeh) //t:kisekaeh f:macs.c r:macsbios c:
//SET: cultname
		DRIVER(cultname) //t:cultname f:macs.c r:macsbios c:
//SET: yuka
		DRIVER(yuka) //t:yuka f:macs.c r:macsbios c:
//SET: yujan
		DRIVER(yujan) //t:yujan f:macs.c r:macsbios c:
//SET: onetwo
		DRIVER(onetwo) //t:onetwo f:onetwo.c r: c:
		DRIVER(onetwoe) //t:onetwoe f:onetwo.c r:onetwo c:onetwo
//SET: 1945kiii
		DRIVER(1945kiii) //t:1945kiii f:1945kiii.c r: c:
//SET: witch
		DRIVER(witch) //t:witch f:witch.c r: c:
		DRIVER(pbchmp95) //t:pbchmp95 f:witch.c r:witch c:witch
//SET: cardline
		DRIVER(cardline) //t:cardline f:cardline.c r: c:
//SET: bmcbowl
		DRIVER(bmcbowl) //t:bmcbowl f:bmcbowl.c r: c:
//SET: koftball
		DRIVER(koftball) //t:koftball f:koftball.c r: c:
//SET: mpoker
		DRIVER(mpoker) //t:mpoker f:mpoker.c r: c:
//SET: pitboss
		DRIVER(pitboss) //t:pitboss f:merit.c r: c:
		DRIVER(pitbossa) //t:pitbossa f:merit.c r:pitboss c:pitboss
		DRIVER(pitbossb) //t:pitbossb f:merit.c r:pitboss c:pitboss
		DRIVER(pitbossc) //t:pitbossc f:merit.c r:pitboss c:pitboss
//SET: casino5
		DRIVER(casino5) //t:casino5 f:merit.c r: c:
//SET: trvwzh
		DRIVER(trvwzh) //t:trvwzh f:merit.c r: c:
		DRIVER(trvwzha) //t:trvwzha f:merit.c r:trvwzh c:trvwzh
		DRIVER(trvwzhb) //t:trvwzhb f:merit.c r:trvwzh c:trvwzh
		DRIVER(trvwzv) //t:trvwzv f:merit.c r:trvwzh c:trvwzh
		DRIVER(trvwzva) //t:trvwzva f:merit.c r:trvwzh c:trvwzh
//SET: trvwz2
		DRIVER(trvwz2) //t:trvwz2 f:merit.c r: c:
		DRIVER(trvwz2a) //t:trvwz2a f:merit.c r:trvwz2 c:trvwz2
//SET: trvwz3h
		DRIVER(trvwz3h) //t:trvwz3h f:merit.c r: c:
		DRIVER(trvwz3ha) //t:trvwz3ha f:merit.c r:trvwz3h c:trvwz3h
		DRIVER(trvwz3v) //t:trvwz3v f:merit.c r:trvwz3h c:trvwz3h
//SET: trvwz4
		DRIVER(trvwz4) //t:trvwz4 f:merit.c r: c:
		DRIVER(trvwz4a) //t:trvwz4a f:merit.c r:trvwz4 c:trvwz4
//SET: dtrvwz5
		DRIVER(dtrvwz5) //t:dtrvwz5 f:merit.c r: c:
//SET: tictac
		DRIVER(tictac) //t:tictac f:merit.c r: c:
		DRIVER(tictacv) //t:tictacv f:merit.c r:tictac c:tictac
//SET: phrcraze
		DRIVER(phrcraze) //t:phrcraze f:merit.c r: c:
		DRIVER(phrcrazea) //t:phrcrazea f:merit.c r:phrcraze c:phrcraze
		DRIVER(phrcrazeb) //t:phrcrazeb f:merit.c r:phrcraze c:phrcraze
		DRIVER(phrcrazec) //t:phrcrazec f:merit.c r:phrcraze c:phrcraze
		DRIVER(phrcrazev) //t:phrcrazev f:merit.c r:phrcraze c:phrcraze
//SET: bigappg
		DRIVER(bigappg) //t:bigappg f:merit.c r: c:
//SET: dodge
		DRIVER(dodge) //t:dodge f:merit.c r: c:
//SET: couple
		DRIVER(couple) //t:couple f:merit.c r: c:
		DRIVER(couplep) //t:couplep f:merit.c r:couple c:couple
		DRIVER(couplei) //t:couplei f:merit.c r:couple c:couple
//SET: pitboss2
		DRIVER(pitboss2) //t:pitboss2 f:meritm.c r: c:
//SET: spitboss
		DRIVER(spitboss) //t:spitboss f:meritm.c r: c:
//SET: pitbosss
		DRIVER(pitbosss) //t:pitbosss f:meritm.c r: c:
//SET: pitbossm
		DRIVER(pitbossm) //t:pitbossm f:meritm.c r: c:
		DRIVER(pitbossma) //t:pitbossma f:meritm.c r:pitbossm c:pitbossm
//SET: pbst30
		DRIVER(pbst30) //t:pbst30 f:meritm.c r: c:
		DRIVER(pbst30b) //t:pbst30b f:meritm.c r:pbst30 c:pbst30
//SET: megat2
		DRIVER(megat2) //t:megat2 f:meritm.c r: c:
		DRIVER(megat2ca) //t:megat2ca f:meritm.c r:megat2 c:megat2
//SET: megat3
		DRIVER(megat3) //t:megat3 f:meritm.c r: c:
		DRIVER(megat3a) //t:megat3a f:meritm.c r:megat3 c:megat3
		DRIVER(megat3ca) //t:megat3ca f:meritm.c r:megat3 c:megat3
		DRIVER(megat3cb) //t:megat3cb f:meritm.c r:megat3 c:megat3
		DRIVER(megat3nj) //t:megat3nj f:meritm.c r:megat3 c:megat3
		DRIVER(megat3te) //t:megat3te f:meritm.c r:megat3 c:megat3
//SET: megat4
		DRIVER(megat4) //t:megat4 f:meritm.c r: c:
		DRIVER(megat4a) //t:megat4a f:meritm.c r:megat4 c:megat4
		DRIVER(megat4b) //t:megat4b f:meritm.c r:megat4 c:megat4
		DRIVER(megat4s) //t:megat4s f:meritm.c r:megat4 c:megat4
		DRIVER(megat4sn) //t:megat4sn f:meritm.c r:megat4 c:megat4
		DRIVER(megat4te) //t:megat4te f:meritm.c r:megat4 c:megat4
		DRIVER(megat4tea) //t:megat4tea f:meritm.c r:megat4 c:megat4
		DRIVER(megat4st) //t:megat4st f:meritm.c r:megat4 c:megat4
		DRIVER(megat4stg) //t:megat4stg f:meritm.c r:megat4 c:megat4
//SET: megat5
		DRIVER(megat5) //t:megat5 f:meritm.c r: c:
		DRIVER(megat5a) //t:megat5a f:meritm.c r:megat5 c:megat5
		DRIVER(megat5nj) //t:megat5nj f:meritm.c r:megat5 c:megat5
		DRIVER(megat5tg) //t:megat5tg f:meritm.c r:megat5 c:megat5
//SET: megat6
		DRIVER(megat6) //t:megat6 f:meritm.c r: c:
//SET: suprgolf
		DRIVER(suprgolf) //t:suprgolf f:suprgolf.c r: c:
//SET: hotblock
		DRIVER(hotblock) //t:hotblock f:hotblock.c r: c:
//SET: pntnpuzl
		DRIVER(pntnpuzl) //t:pntnpuzl f:pntnpuzl.c r: c:
//SET: trucocl
		DRIVER(trucocl) //t:trucocl f:trucocl.c r: c:
//SET: ertictac
		DRIVER(ertictac) //t:ertictac f:ertictac.c r: c:
//SET: poizone
		DRIVER(poizone) //t:poizone f:ertictac.c r: c:
//SET: ssfindo
		DRIVER(ssfindo) //t:ssfindo f:ssfindo.c r: c:
//SET: ppcar
		DRIVER(ppcar) //t:ppcar f:ssfindo.c r: c:
//SET: tetfight
		DRIVER(tetfight) //t:tetfight f:ssfindo.c r: c:
//SET: imolagp
		DRIVER(imolagp) //t:imolagp f:imolagp.c r: c:
//SET: dambustr
		DRIVER(dambustr) //t:dambustr f:dambustr.c r: c:
		DRIVER(dambustra) //t:dambustra f:dambustr.c r:dambustr c:dambustr
		DRIVER(dambustruk) //t:dambustruk f:dambustr.c r:dambustr c:dambustr
//SET: gunpey
		DRIVER(gunpey) //t:gunpey f:gunpey.c r: c:
//SET: spaceg
		DRIVER(spaceg) //t:spaceg f:spaceg.c r: c:
//SET: wldarrow
		DRIVER(wldarrow) //t:wldarrow f:wldarrow.c r: c:
//SET: unkmeyco
		DRIVER(unkmeyco) //t:unkmeyco f:wldarrow.c r: c:
//SET: mdrawpkr
		DRIVER(mdrawpkr) //t:mdrawpkr f:wldarrow.c r: c:
		DRIVER(mdrawpkra) //t:mdrawpkra f:wldarrow.c r:mdrawpkr c:mdrawpkr
//SET: laserbas
		DRIVER(laserbas) //t:laserbas f:laserbas.c r: c:
		DRIVER(laserbasa) //t:laserbasa f:laserbas.c r:laserbas c:laserbas
		DRIVER(futflash) //t:futflash f:laserbas.c r:laserbas c:laserbas
//SET: turbosub
		DRIVER(turbosub) //t:turbosub f:esripsys.c r: c:
		DRIVER(turbosub7) //t:turbosub7 f:esripsys.c r:turbosub c:turbosub
		DRIVER(turbosub6) //t:turbosub6 f:esripsys.c r:turbosub c:turbosub
//SET: pipeline
		DRIVER(pipeline) //t:pipeline f:pipeline.c r: c:
//SET: ttchamp
		DRIVER(ttchamp) //t:ttchamp f:ttchamp.c r: c:
		DRIVER(ttchampa) //t:ttchampa f:ttchamp.c r:ttchamp c:ttchamp
//SET: dreamwld
		DRIVER(dreamwld) //t:dreamwld f:dreamwld.c r: c:
//SET: cybertnk
		DRIVER(cybertnk) //t:cybertnk f:cybertnk.c r: c:
//SET: cubeqst
		DRIVER(cubeqst) //t:cubeqst f:cubeqst.c r: c:
		DRIVER(cubeqsta) //t:cubeqsta f:cubeqst.c r:cubeqst c:cubeqst
//SET: pkscram
		DRIVER(pkscram) //t:pkscram f:pkscram.c r: c:
//SET: magicard
		DRIVER(magicard) //t:magicard f:magicard.c r: c:
		DRIVER(magicarda) //t:magicarda f:magicard.c r:magicard c:magicard
		DRIVER(magicardb) //t:magicardb f:magicard.c r:magicard c:magicard
		DRIVER(magicardj) //t:magicardj f:magicard.c r:magicard c:magicard
//SET: magicle
		DRIVER(magicle) //t:magicle f:magicard.c r: c:
//SET: jollycrd
		DRIVER(jollycrd) //t:jollycrd f:funworld.c r: c:
		DRIVER(jolyc3x3) //t:jolyc3x3 f:funworld.c r:jollycrd c:jollycrd
		DRIVER(jolycmzs) //t:jolycmzs f:funworld.c r:jollycrd c:jollycrd
		DRIVER(jolyc980) //t:jolyc980 f:funworld.c r:jollycrd c:jollycrd
		DRIVER(jolycdev) //t:jolycdev f:funworld.c r:jollycrd c:jollycrd
		DRIVER(jolyccra) //t:jolyccra f:funworld.c r:jollycrd c:jollycrd
		DRIVER(jolyccrb) //t:jolyccrb f:funworld.c r:jollycrd c:jollycrd
		DRIVER(jolycdit) //t:jolycdit f:funworld.c r:jollycrd c:jollycrd
		DRIVER(jolycdib) //t:jolycdib f:funworld.c r:jollycrd c:jollycrd
		DRIVER(sjcd2kx3) //t:sjcd2kx3 f:funworld.c r:jollycrd c:jollycrd
		DRIVER(jolycdab) //t:jolycdab f:funworld.c r:jollycrd c:jollycrd
//SET: bigdeal
		DRIVER(bigdeal) //t:bigdeal f:funworld.c r: c:
		DRIVER(bigdealb) //t:bigdealb f:funworld.c r:bigdeal c:bigdeal
		DRIVER(jolycdat) //t:jolycdat f:funworld.c r:bigdeal c:bigdeal
//SET: cuoreuno
		DRIVER(cuoreuno) //t:cuoreuno f:funworld.c r: c:
//SET: elephfam
		DRIVER(elephfam) //t:elephfam f:funworld.c r: c:
		DRIVER(elephfmb) //t:elephfmb f:funworld.c r:elephfam c:elephfam
//SET: pool10
		DRIVER(pool10) //t:pool10 f:funworld.c r: c:
		DRIVER(pool10b) //t:pool10b f:funworld.c r:pool10 c:pool10
		DRIVER(pool10c) //t:pool10c f:funworld.c r:pool10 c:pool10
		DRIVER(pool10d) //t:pool10d f:funworld.c r:pool10 c:pool10
//SET: tortufam
		DRIVER(tortufam) //t:tortufam f:funworld.c r: c:
//SET: potgame
		DRIVER(potgame) //t:potgame f:funworld.c r: c:
//SET: bottle10
		DRIVER(bottle10) //t:bottle10 f:funworld.c r: c:
		DRIVER(bottl10b) //t:bottl10b f:funworld.c r:bottle10 c:bottle10
//SET: royalcrd
		DRIVER(royalcrd) //t:royalcrd f:funworld.c r: c:
		DRIVER(royalcrda) //t:royalcrda f:funworld.c r:royalcrd c:royalcrd
		DRIVER(royalcrdb) //t:royalcrdb f:funworld.c r:royalcrd c:royalcrd
		DRIVER(royalcrdc) //t:royalcrdc f:funworld.c r:royalcrd c:royalcrd
		DRIVER(royalcrdd) //t:royalcrdd f:funworld.c r:royalcrd c:royalcrd
		DRIVER(royalcrde) //t:royalcrde f:funworld.c r:royalcrd c:royalcrd
		DRIVER(royalcrdf) //t:royalcrdf f:funworld.c r:royalcrd c:royalcrd
		DRIVER(royalcrdt) //t:royalcrdt f:funworld.c r:royalcrd c:royalcrd
		DRIVER(royalcrdp) //t:royalcrdp f:funworld.c r:royalcrd c:royalcrd
		DRIVER(lluck3x3) //t:lluck3x3 f:funworld.c r:royalcrd c:royalcrd
		DRIVER(lluck4x1) //t:lluck4x1 f:funworld.c r:royalcrd c:royalcrd
//SET: magicrd2
		DRIVER(magicrd2) //t:magicrd2 f:funworld.c r: c:
		DRIVER(magicd2a) //t:magicd2a f:funworld.c r:magicrd2 c:magicrd2
		DRIVER(magicd2b) //t:magicd2b f:funworld.c r:magicrd2 c:magicrd2
//SET: vegasslw
		DRIVER(vegasslw) //t:vegasslw f:funworld.c r: c:
		DRIVER(vegasfst) //t:vegasfst f:funworld.c r:vegasslw c:vegasslw
		DRIVER(vegasfte) //t:vegasfte f:funworld.c r:vegasslw c:vegasslw
		DRIVER(vegasmil) //t:vegasmil f:funworld.c r:vegasslw c:vegasslw
//SET: jolyjokr
		DRIVER(jolyjokr) //t:jolyjokr f:funworld.c r: c:
		DRIVER(jolyjokra) //t:jolyjokra f:funworld.c r:jolyjokr c:jolyjokr
		DRIVER(jolyjokrb) //t:jolyjokrb f:funworld.c r:jolyjokr c:jolyjokr
//SET: multiwin
		DRIVER(multiwin) //t:multiwin f:funworld.c r: c:
//SET: jokercrd
		DRIVER(jokercrd) //t:jokercrd f:funworld.c r: c:
//SET: mongolnw
		DRIVER(mongolnw) //t:mongolnw f:funworld.c r: c:
//SET: soccernw
		DRIVER(soccernw) //t:soccernw f:funworld.c r: c:
//SET: saloon
		DRIVER(saloon) //t:saloon f:funworld.c r: c:
//SET: funquiz
		DRIVER(funquiz) //t:funquiz f:funworld.c r: c:
//SET: photoply
		DRIVER(photoply) //t:photoply f:photoply.c r: c:
//SET: snookr10
		DRIVER(snookr10) //t:snookr10 f:snookr10.c r: c:
		DRIVER(tenballs) //t:tenballs f:snookr10.c r:snookr10 c:snookr10
//SET: apple10
		DRIVER(apple10) //t:apple10 f:snookr10.c r: c:
//SET: sbugger
		DRIVER(sbugger) //t:sbugger f:sbugger.c r: c:
		DRIVER(sbuggera) //t:sbuggera f:sbugger.c r:sbugger c:sbugger
//SET: poker41
		DRIVER(poker41) //t:poker41 f:gatron.c r: c:
//SET: pulltabs
		DRIVER(pulltabs) //t:pulltabs f:gatron.c r: c:
//SET: vroulet
		DRIVER(vroulet) //t:vroulet f:vroulet.c r: c:
//SET: rcasino
		DRIVER(rcasino) //t:rcasino f:caswin.c r: c:
		DRIVER(caswin) //t:caswin f:caswin.c r:rcasino c:rcasino
//SET: ampoker2
		DRIVER(ampoker2) //t:ampoker2 f:ampoker2.c r: c:
		DRIVER(piccolop) //t:piccolop f:ampoker2.c r:ampoker2 c:ampoker2
		DRIVER(ampkr2b1) //t:ampkr2b1 f:ampoker2.c r:ampoker2 c:ampoker2
		DRIVER(ampkr2b2) //t:ampkr2b2 f:ampoker2.c r:ampoker2 c:ampoker2
		DRIVER(ampkr2b3) //t:ampkr2b3 f:ampoker2.c r:ampoker2 c:ampoker2
		DRIVER(ampkr2b4) //t:ampkr2b4 f:ampoker2.c r:ampoker2 c:ampoker2
		DRIVER(ampkr228) //t:ampkr228 f:ampoker2.c r:ampoker2 c:ampoker2
		DRIVER(pkrdewin) //t:pkrdewin f:ampoker2.c r:ampoker2 c:ampoker2
		DRIVER(ampkr95) //t:ampkr95 f:ampoker2.c r:ampoker2 c:ampoker2
		DRIVER(videomat) //t:videomat f:ampoker2.c r:ampoker2 c:ampoker2
		DRIVER(rabbitpk) //t:rabbitpk f:ampoker2.c r:ampoker2 c:ampoker2
//SET: sigmapkr
		DRIVER(sigmapkr) //t:sigmapkr f:ampoker2.c r: c:
//SET: sigma2k
		DRIVER(sigma2k) //t:sigma2k f:ampoker2.c r: c:
//SET: sidewndr
		DRIVER(sidewndr) //t:sidewndr f:acefruit.c r: c:
		DRIVER(spellbnd) //t:spellbnd f:acefruit.c r:sidewndr c:sidewndr
//SET: starspnr
		DRIVER(starspnr) //t:starspnr f:acefruit.c r: c:
//SET: acefruit
		DRIVER(acefruit) //t:acefruit f:acefruit.c r: c:
//SET: attckufo
		DRIVER(attckufo) //t:attckufo f:attckufo.c r: c:
//SET: fortecar
		DRIVER(fortecar) //t:fortecar f:fortecar.c r: c:
//SET: jackpool
		DRIVER(jackpool) //t:jackpool f:jackpool.c r: c:
//SET: murogem
		DRIVER(murogem) //t:murogem f:murogem.c r: c:
		DRIVER(murogema) //t:murogema f:murogem.c r:murogem c:murogem
		DRIVER(murogmbl) //t:murogmbl f:murogmbl.c r:murogem c:murogem
		DRIVER(lasvegas) //t:lasvegas f:murogem.c r:murogem c:murogem
//SET: quizmstr
		DRIVER(quizmstr) //t:quizmstr f:coinmstr.c r: c:
//SET: trailblz
		DRIVER(trailblz) //t:trailblz f:coinmstr.c r: c:
//SET: supnudg2
		DRIVER(supnudg2) //t:supnudg2 f:coinmstr.c r: c:
//SET: pokeroul
		DRIVER(pokeroul) //t:pokeroul f:coinmstr.c r: c:
//SET: egghunt
		DRIVER(egghunt) //t:egghunt f:egghunt.c r: c:
//SET: magic10
		DRIVER(magic10) //t:magic10 f:magic10.c r: c:
		DRIVER(magic10a) //t:magic10a f:magic10.c r:magic10 c:magic10
		DRIVER(magic10b) //t:magic10b f:magic10.c r:magic10 c:magic10
//SET: magic102
		DRIVER(magic102) //t:magic102 f:magic10.c r: c:
//SET: suprpool
		DRIVER(suprpool) //t:suprpool f:magic10.c r: c:
//SET: hotslot
		DRIVER(hotslot) //t:hotslot f:magic10.c r: c:
//SET: mcolors
		DRIVER(mcolors) //t:mcolors f:magic10.c r: c:
//SET: sgsafari
		DRIVER(sgsafari) //t:sgsafari f:magic10.c r: c:
//SET: musicsrt
		DRIVER(musicsrt) //t:musicsrt f:magic10.c r: c:
//SET: galaxi
		DRIVER(galaxi) //t:galaxi f:galaxi.c r: c:
//SET: magjoker
		DRIVER(magjoker) //t:magjoker f:galaxi.c r: c:
//SET: dwarfd
		DRIVER(dwarfd) //t:dwarfd f:dwarfd.c r: c:
//SET: quarterh
		DRIVER(quarterh) //t:quarterh f:dwarfd.c r: c:
		DRIVER(quarterha) //t:quarterha f:dwarfd.c r:quarterh c:quarterh
		DRIVER(quarterhb) //t:quarterhb f:dwarfd.c r:quarterh c:quarterh
//SET: qc
		DRIVER(qc) //t:qc f:dwarfd.c r: c:
//SET: trvquest
		DRIVER(trvquest) //t:trvquest f:trvquest.c r: c:
//SET: wheelfir
		DRIVER(wheelfir) //t:wheelfir f:wheelfir.c r: c:
//SET: littlerb
		DRIVER(littlerb) //t:littlerb f:littlerb.c r: c:
//SET: tattack
		DRIVER(tattack) //t:tattack f:tattack.c r: c:
//SET: mosaicf2
		DRIVER(mosaicf2) //t:mosaicf2 f:f-32.c r: c:
//SET: finalgdr
		DRIVER(finalgdr) //t:finalgdr f:vamphalf.c r: c:
//SET: mrkicker
		DRIVER(mrkicker) //t:mrkicker f:vamphalf.c r: c:
//SET: wyvernwg
		DRIVER(wyvernwg) //t:wyvernwg f:vamphalf.c r: c:
//SET: rbmk
		DRIVER(rbmk) //t:rbmk f:rbmk.c r: c:
//SET: go2000
		DRIVER(go2000) //t:go2000 f:go2000.c r: c:
//SET: mirax
		DRIVER(mirax) //t:mirax f:mirax.c r: c:
		DRIVER(miraxa) //t:miraxa f:mirax.c r:mirax c:mirax
//SET: victor5
		DRIVER(victor5) //t:victor5 f:subsino.c r: c:
//SET: victor21
		DRIVER(victor21) //t:victor21 f:subsino.c r: c:
//SET: crsbingo
		DRIVER(crsbingo) //t:crsbingo f:subsino.c r: c:
//SET: tisub
		DRIVER(tisub) //t:tisub f:subsino.c r: c:
		DRIVER(tisuba) //t:tisuba f:subsino.c r:tisub c:tisub
//SET: stisub
		DRIVER(stisub) //t:stisub f:subsino.c r: c:
//SET: victor6
		DRIVER(victor6) //t:victor6 f:subsino.c r: c:
		DRIVER(victor6a) //t:victor6a f:subsino.c r:victor6 c:victor6
		DRIVER(victor6b) //t:victor6b f:subsino.c r:victor6 c:victor6
//SET: sharkpy
		DRIVER(sharkpy) //t:sharkpy f:subsino.c r: c:
		DRIVER(sharkpya) //t:sharkpya f:subsino.c r:sharkpy c:sharkpy
		DRIVER(sharkpye) //t:sharkpye f:subsino.c r:sharkpy c:sharkpy
//SET: smoto20
		DRIVER(smoto20) //t:smoto20 f:subsino.c r: c:
		DRIVER(smoto16) //t:smoto16 f:subsino.c r:smoto20 c:smoto20
//SET: mtrain
		DRIVER(mtrain) //t:mtrain f:subsino2.c r: c:
		DRIVER(mtrainnv) //t:mtrainnv f:subsino.c r:mtrain c:mtrain
//SET: expcard
		DRIVER(expcard) //t:expcard f:subsino2.c r: c:
//SET: saklove
		DRIVER(saklove) //t:saklove f:subsino2.c r: c:
//SET: bishjan
		DRIVER(bishjan) //t:bishjan f:subsino2.c r: c:
//SET: xtrain
		DRIVER(xtrain) //t:xtrain f:subsino2.c r: c:
//SET: lastfght
		DRIVER(lastfght) //t:lastfght f:lastfght.c r: c:
//SET: xplan
		DRIVER(xplan) //t:xplan f:subsino2.c r: c:
//SET: sliver
		DRIVER(sliver) //t:sliver f:sliver.c r: c:
//SET: intrscti
		DRIVER(intrscti) //t:intrscti f:intrscti.c r: c:
//SET: pasha2
		DRIVER(pasha2) //t:pasha2 f:pasha2.c r: c:
//SET: trvmadns
		DRIVER(trvmadns) //t:trvmadns f:trvmadns.c r: c:
//SET: rcorsair
		DRIVER(rcorsair) //t:rcorsair f:rcorsair.c r: c:
//SET: pzlestar
		DRIVER(pzlestar) //t:pzlestar f:sangho.c r: c:
//SET: sexyboom
		DRIVER(sexyboom) //t:sexyboom f:sangho.c r: c:
//SET: sfkick
		DRIVER(sfkick) //t:sfkick f:sfkick.c r: c:
		DRIVER(sfkicka) //t:sfkicka f:sfkick.c r:sfkick c:sfkick
		DRIVER(spinkick) //t:spinkick f:sfkick.c r:sfkick c:sfkick
//SET: 7mezzo
		DRIVER(7mezzo) //t:7mezzo f:magicfly.c r: c:
//SET: magicfly
		DRIVER(magicfly) //t:magicfly f:magicfly.c r: c:
//SET: dynabomb
		DRIVER(dynabomb) //t:dynabomb f:limenko.c r: c:
//SET: legendoh
		DRIVER(legendoh) //t:legendoh f:limenko.c r: c:
//SET: sb2003
		DRIVER(sb2003) //t:sb2003 f:limenko.c r: c:
		DRIVER(sb2003a) //t:sb2003a f:limenko.c r:sb2003 c:sb2003
//SET: spotty
		DRIVER(spotty) //t:spotty f:limenko.c r: c:
//SET: carrera
		DRIVER(carrera) //t:carrera f:carrera.c r: c:
//SET: goldnpkr
		DRIVER(goldnpkr) //t:goldnpkr f:goldnpkr.c r: c:
		DRIVER(goldnpkb) //t:goldnpkb f:goldnpkr.c r:goldnpkr c:goldnpkr
//SET: pottnpkr
		DRIVER(pottnpkr) //t:pottnpkr f:goldnpkr.c r: c:
		DRIVER(potnpkra) //t:potnpkra f:goldnpkr.c r:pottnpkr c:pottnpkr
		DRIVER(potnpkrb) //t:potnpkrb f:goldnpkr.c r:pottnpkr c:pottnpkr
		DRIVER(potnpkrc) //t:potnpkrc f:goldnpkr.c r:pottnpkr c:pottnpkr
		DRIVER(potnpkrd) //t:potnpkrd f:goldnpkr.c r:pottnpkr c:pottnpkr
		DRIVER(potnpkre) //t:potnpkre f:goldnpkr.c r:pottnpkr c:pottnpkr
		DRIVER(goodluck) //t:goodluck f:goldnpkr.c r:pottnpkr c:pottnpkr
		DRIVER(superdbl) //t:superdbl f:goldnpkr.c r:pottnpkr c:pottnpkr
		DRIVER(ngold) //t:ngold f:goldnpkr.c r:pottnpkr c:pottnpkr
		DRIVER(ngolda) //t:ngolda f:goldnpkr.c r:pottnpkr c:pottnpkr
		DRIVER(ngoldb) //t:ngoldb f:goldnpkr.c r:pottnpkr c:pottnpkr
//SET: witchcrd
		DRIVER(witchcrd) //t:witchcrd f:goldnpkr.c r: c:
		DRIVER(witchcda) //t:witchcda f:goldnpkr.c r:witchcrd c:witchcrd
		DRIVER(witchcdb) //t:witchcdb f:goldnpkr.c r:witchcrd c:witchcrd
		DRIVER(witchcdc) //t:witchcdc f:goldnpkr.c r:witchcrd c:witchcrd
		DRIVER(witchcdd) //t:witchcdd f:goldnpkr.c r:witchcrd c:witchcrd
		DRIVER(witchcdf) //t:witchcdf f:goldnpkr.c r:witchcrd c:witchcrd
		DRIVER(witchcdg) //t:witchcdg f:goldnpkr.c r:witchcrd c:witchcrd
		DRIVER(witchcdh) //t:witchcdh f:goldnpkr.c r:witchcrd c:witchcrd
		DRIVER(witchgme) //t:witchgme f:goldnpkr.c r:witchcrd c:witchcrd
		DRIVER(witchjol) //t:witchjol f:goldnpkr.c r:witchcrd c:witchcrd
		DRIVER(wldwitch) //t:wldwitch f:goldnpkr.c r:witchcrd c:witchcrd
//SET: falcnwld
		DRIVER(falcnwld) //t:falcnwld f:goldnpkr.c r: c:
		DRIVER(falcnwlda) //t:falcnwlda f:goldnpkr.c r:falcnwld c:falcnwld
		DRIVER(falcnwldb) //t:falcnwldb f:goldnpkr.c r:falcnwld c:falcnwld
//SET: bsuerte
		DRIVER(bsuerte) //t:bsuerte f:goldnpkr.c r: c:
		DRIVER(bsuertea) //t:bsuertea f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuerteb) //t:bsuerteb f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuertec) //t:bsuertec f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuerted) //t:bsuerted f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuertee) //t:bsuertee f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuertef) //t:bsuertef f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuerteg) //t:bsuerteg f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuerteh) //t:bsuerteh f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuertei) //t:bsuertei f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuertej) //t:bsuertej f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuertek) //t:bsuertek f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuertel) //t:bsuertel f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuertem) //t:bsuertem f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuerten) //t:bsuerten f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuerteo) //t:bsuerteo f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuertep) //t:bsuertep f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuerteq) //t:bsuerteq f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuerter) //t:bsuerter f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuertes) //t:bsuertes f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuertet) //t:bsuertet f:goldnpkr.c r:bsuerte c:bsuerte
		DRIVER(bsuerteu) //t:bsuerteu f:goldnpkr.c r:bsuerte c:bsuerte
//SET: pmpoker
		DRIVER(pmpoker) //t:pmpoker f:goldnpkr.c r: c:
//SET: royale
		DRIVER(royale) //t:royale f:goldnpkr.c r: c:
		DRIVER(royalea) //t:royalea f:goldnpkr.c r:royale c:royale
//SET: sloco93
		DRIVER(sloco93) //t:sloco93 f:goldnpkr.c r: c:
		DRIVER(sloco93a) //t:sloco93a f:goldnpkr.c r:sloco93 c:sloco93
//SET: maverik
		DRIVER(maverik) //t:maverik f:goldnpkr.c r: c:
//SET: brasil86
		DRIVER(brasil86) //t:brasil86 f:goldnpkr.c r: c:
//SET: brasil87
		DRIVER(brasil87) //t:brasil87 f:goldnpkr.c r: c:
//SET: brasil89
		DRIVER(brasil89) //t:brasil89 f:goldnpkr.c r: c:
		DRIVER(brasil89a) //t:brasil89a f:goldnpkr.c r:brasil89 c:brasil89
//SET: brasil93
		DRIVER(brasil93) //t:brasil93 f:goldnpkr.c r: c:
//SET: poker91
		DRIVER(poker91) //t:poker91 f:goldnpkr.c r: c:
//SET: genie
		DRIVER(genie) //t:genie f:goldnpkr.c r: c:
//SET: silverga
		DRIVER(silverga) //t:silverga f:goldnpkr.c r: c:
//SET: pokerdub
		DRIVER(pokerdub) //t:pokerdub f:goldnpkr.c r: c:
//SET: pokerduc
		DRIVER(pokerduc) //t:pokerduc f:goldnpkr.c r: c:
//SET: comg074
		DRIVER(comg074) //t:comg074 f:calomega.c r: c:
//SET: comg076
		DRIVER(comg076) //t:comg076 f:calomega.c r: c:
//SET: comg079
		DRIVER(comg079) //t:comg079 f:calomega.c r: c:
//SET: comg080
		DRIVER(comg080) //t:comg080 f:calomega.c r: c:
//SET: comg094
		DRIVER(comg094) //t:comg094 f:calomega.c r: c:
//SET: comg107
		DRIVER(comg107) //t:comg107 f:calomega.c r: c:
//SET: comg123
		DRIVER(comg123) //t:comg123 f:calomega.c r: c:
//SET: comg125
		DRIVER(comg125) //t:comg125 f:calomega.c r: c:
//SET: comg127
		DRIVER(comg127) //t:comg127 f:calomega.c r: c:
//SET: comg128
		DRIVER(comg128) //t:comg128 f:calomega.c r: c:
//SET: comg134
		DRIVER(comg134) //t:comg134 f:calomega.c r: c:
//SET: comg145
		DRIVER(comg145) //t:comg145 f:calomega.c r: c:
//SET: comg157
		DRIVER(comg157) //t:comg157 f:calomega.c r: c:
//SET: comg159
		DRIVER(comg159) //t:comg159 f:calomega.c r: c:
//SET: comg164
		DRIVER(comg164) //t:comg164 f:calomega.c r: c:
//SET: comg168
		DRIVER(comg168) //t:comg168 f:calomega.c r: c:
//SET: comg172
		DRIVER(comg172) //t:comg172 f:calomega.c r: c:
//SET: comg175
		DRIVER(comg175) //t:comg175 f:calomega.c r: c:
//SET: comg176
		DRIVER(comg176) //t:comg176 f:calomega.c r: c:
//SET: comg181
		DRIVER(comg181) //t:comg181 f:calomega.c r: c:
//SET: comg183
		DRIVER(comg183) //t:comg183 f:calomega.c r: c:
//SET: comg185
		DRIVER(comg185) //t:comg185 f:calomega.c r: c:
//SET: comg186
		DRIVER(comg186) //t:comg186 f:calomega.c r: c:
//SET: comg187
		DRIVER(comg187) //t:comg187 f:calomega.c r: c:
//SET: comg204
		DRIVER(comg204) //t:comg204 f:calomega.c r: c:
//SET: comg208
		DRIVER(comg208) //t:comg208 f:calomega.c r: c:
//SET: comg227
		DRIVER(comg227) //t:comg227 f:calomega.c r: c:
//SET: comg230
		DRIVER(comg230) //t:comg230 f:calomega.c r: c:
//SET: comg236
		DRIVER(comg236) //t:comg236 f:calomega.c r: c:
//SET: comg239
		DRIVER(comg239) //t:comg239 f:calomega.c r: c:
//SET: comg240
		DRIVER(comg240) //t:comg240 f:calomega.c r: c:
//SET: comg246
		DRIVER(comg246) //t:comg246 f:calomega.c r: c:
//SET: comg272a
		DRIVER(comg272a) //t:comg272a f:calomega.c r: c:
//SET: comg272b
		DRIVER(comg272b) //t:comg272b f:calomega.c r: c:
//SET: comg5108
		DRIVER(comg5108) //t:comg5108 f:calomega.c r: c:
//SET: comg903d
		DRIVER(comg903d) //t:comg903d f:calomega.c r: c:
//SET: comg905d
		DRIVER(comg905d) //t:comg905d f:calomega.c r: c:
//SET: elgrande
		DRIVER(elgrande) //t:elgrande f:calomega.c r: c:
//SET: jjpoker
		DRIVER(jjpoker) //t:jjpoker f:calomega.c r: c:
		DRIVER(jjpokerb) //t:jjpokerb f:calomega.c r:jjpoker c:jjpoker
//SET: ssipkr24
		DRIVER(ssipkr24) //t:ssipkr24 f:calomega.c r: c:
		DRIVER(ssipkr30) //t:ssipkr30 f:calomega.c r:ssipkr24 c:ssipkr24
		DRIVER(ssipkr40) //t:ssipkr40 f:calomega.c r:ssipkr24 c:ssipkr24
//SET: altair
		DRIVER(altair) //t:altair f:cidelsa.c r: c:
//SET: destryer
		DRIVER(destryer) //t:destryer f:cidelsa.c r: c:
		DRIVER(destryera) //t:destryera f:cidelsa.c r:destryer c:destryer
//SET: draco
		DRIVER(draco) //t:draco f:cidelsa.c r: c:
//SET: rockduck
		DRIVER(rockduck) //t:rockduck f:scregg.c r: c:
//SET: tetriskr
		DRIVER(tetriskr) //t:tetriskr f:pcxt.c r: c:
//SET: trvhang
		DRIVER(trvhang) //t:trvhang f:sms.c r: c:
//SET: trvhanga
		DRIVER(trvhanga) //t:trvhanga f:sms.c r: c:
//SET: sureshot
		DRIVER(sureshot) //t:sureshot f:sms.c r: c:
//SET: secondch
		DRIVER(secondch) //t:secondch f:sms.c r: c:
//SET: skylncr
		DRIVER(skylncr) //t:skylncr f:skylncr.c r: c:
//SET: butrfly
		DRIVER(butrfly) //t:butrfly f:skylncr.c r: c:
//SET: madzoo
		DRIVER(madzoo) //t:madzoo f:skylncr.c r: c:
//SET: leader
		DRIVER(leader) //t:leader f:skylncr.c r: c:
//SET: livequiz
		DRIVER(livequiz) //t:livequiz f:midas.c r: c:
//SET: hammer
		DRIVER(hammer) //t:hammer f:midas.c r: c:
//SET: discoboy
		DRIVER(discoboy) //t:discoboy f:discoboy.c r: c:
//SET: pangofun
		DRIVER(pangofun) //t:pangofun f:pangofun.c r: c:
//SET: 2mindril
		DRIVER(2mindril) //t:2mindril f:2mindril.c r: c:
//SET: koikoi
		DRIVER(koikoi) //t:koikoi f:koikoi.c r: c:
//SET: good
		DRIVER(good) //t:good f:good.c r: c:
//SET: filetto
		DRIVER(filetto) //t:filetto f:pcxt.c r: c:
//SET: quizo
		DRIVER(quizo) //t:quizo f:quizo.c r: c:
		DRIVER(quizoa) //t:quizoa f:quizo.c r:quizo c:quizo
//SET: gstream
		DRIVER(gstream) //t:gstream f:gstream.c r: c:
//SET: miniboy7
		DRIVER(miniboy7) //t:miniboy7 f:miniboy7.c r: c:
		DRIVER(miniboy7a) //t:miniboy7a f:miniboy7.c r:miniboy7 c:miniboy7
//SET: 39in1
		DRIVER(39in1) //t:39in1 f:39in1.c r: c:
		DRIVER(48in1) //t:48in1 f:39in1.c r:39in1 c:39in1
		DRIVER(48in1a) //t:48in1a f:39in1.c r:39in1 c:39in1
//SET: kingpin
		DRIVER(kingpin) //t:kingpin f:kingpin.c r: c:
//SET: kingpinm
		DRIVER(kingpinm) //t:kingpinm f:kingpin.c r: c:
//SET: thayers
		DRIVER(thayers) //t:thayers f:thayers.c r: c:
		DRIVER(thayersa) //t:thayersa f:thayers.c r:thayers c:thayers
//SET: istellar
		DRIVER(istellar) //t:istellar f:istellar.c r: c:
//SET: esh
		DRIVER(esh) //t:esh f:esh.c r: c:
		DRIVER(esha) //t:esha f:esh.c r:esh c:esh
		DRIVER(eshb) //t:eshb f:esh.c r:esh c:esh
//SET: comebaby
		DRIVER(comebaby) //t:comebaby f:comebaby.c r: c:
//SET: peset038
		DRIVER(peset038) //t:peset038 f:peplus.c r: c:
//SET: pepp0043
		DRIVER(pepp0043) //t:pepp0043 f:peplus.c r: c:
//SET: pepp0065
		DRIVER(pepp0065) //t:pepp0065 f:peplus.c r: c:
//SET: pepp0158
		DRIVER(pepp0158) //t:pepp0158 f:peplus.c r: c:
//SET: pepp0188
		DRIVER(pepp0188) //t:pepp0188 f:peplus.c r: c:
//SET: pepp0250
		DRIVER(pepp0250) //t:pepp0250 f:peplus.c r: c:
//SET: pepp0447
		DRIVER(pepp0447) //t:pepp0447 f:peplus.c r: c:
//SET: pepp0516
		DRIVER(pepp0516) //t:pepp0516 f:peplus.c r: c:
//SET: pebe0014
		DRIVER(pebe0014) //t:pebe0014 f:peplus.c r: c:
//SET: peke1012
		DRIVER(peke1012) //t:peke1012 f:peplus.c r: c:
//SET: peps0014
		DRIVER(peps0014) //t:peps0014 f:peplus.c r: c:
//SET: peps0022
		DRIVER(peps0022) //t:peps0022 f:peplus.c r: c:
//SET: peps0043
		DRIVER(peps0043) //t:peps0043 f:peplus.c r: c:
//SET: peps0045
		DRIVER(peps0045) //t:peps0045 f:peplus.c r: c:
//SET: peps0308
		DRIVER(peps0308) //t:peps0308 f:peplus.c r: c:
//SET: peps0615
		DRIVER(peps0615) //t:peps0615 f:peplus.c r: c:
//SET: peps0716
		DRIVER(peps0716) //t:peps0716 f:peplus.c r: c:
//SET: pex2069p
		DRIVER(pex2069p) //t:pex2069p f:peplus.c r: c:
//SET: pexp0019
		DRIVER(pexp0019) //t:pexp0019 f:peplus.c r: c:
//SET: pexp0112
		DRIVER(pexp0112) //t:pexp0112 f:peplus.c r: c:
//SET: pexs0006
		DRIVER(pexs0006) //t:pexs0006 f:peplus.c r: c:
//SET: pexmp006
		DRIVER(pexmp006) //t:pexmp006 f:peplus.c r: c:
//SET: pexmp017
		DRIVER(pexmp017) //t:pexmp017 f:peplus.c r: c:
//SET: pexmp024
		DRIVER(pexmp024) //t:pexmp024 f:peplus.c r: c:
//SET: mirage
		DRIVER(mirage) //t:mirage f:mirage.c r: c:
//SET: dominob
		DRIVER(dominob) //t:dominob f:dominob.c r: c:
		DRIVER(dominobv2) //t:dominobv2 f:dominob.c r:dominob c:dominob
//SET: jongkyo
		DRIVER(jongkyo) //t:jongkyo f:jongkyo.c r: c:
//SET: gamecstl
		DRIVER(gamecstl) //t:gamecstl f:gamecstl.c r: c:
		DRIVER(gamecst2) //t:gamecst2 f:gamecstl.c r:gamecstl c:gamecstl
//SET: drw80pkr
		DRIVER(drw80pkr) //t:drw80pkr f:drw80pkr.c r: c:
//SET: drw80pk2
		DRIVER(drw80pk2) //t:drw80pk2 f:drw80pkr.c r: c:
//SET: blazlaz
		DRIVER(blazlaz) //t:blazlaz f:uapce.c r: c:
//SET: ggconnie
		DRIVER(ggconnie) //t:ggconnie f:ggconnie.c r: c:
//SET: paranoia
		DRIVER(paranoia) //t:paranoia f:paranoia.c r: c:
//SET: vcombat
		DRIVER(vcombat) //t:vcombat f:vcombat.c r: c:
//SET: shadfgtr
		DRIVER(shadfgtr) //t:shadfgtr f:vcombat.c r: c:
//SET: skimaxx
		DRIVER(skimaxx) //t:skimaxx f:skimaxx.c r: c:
//SET: blackt96
		DRIVER(blackt96) //t:blackt96 f:blackt96.c r: c:
//SET: magictg
		DRIVER(magictg) //t:magictg f:magictg.c r: c:
		DRIVER(magictga) //t:magictga f:magictg.c r:magictg c:magictg
//SET: re900
		DRIVER(re900) //t:re900 f:re900.c r: c:
//SET: bs94
		DRIVER(bs94) //t:bs94 f:re900.c r: c:
//SET: jokrwild
		DRIVER(jokrwild) //t:jokrwild f:jokrwild.c r: c:
//SET: pesadelo
		DRIVER(pesadelo) //t:pesadelo f:forte2.c r: c:
//SET: pengadvb
		DRIVER(pengadvb) //t:pengadvb f:pengadvb.c r: c:
//SET: spool99
		DRIVER(spool99) //t:spool99 f:spool99.c r: c:
		DRIVER(spool99a) //t:spool99a f:spool99.c r:spool99 c:spool99
//SET: vcarn
		DRIVER(vcarn) //t:vcarn f:spool99.c r: c:
//SET: 4roses
		DRIVER(4roses) //t:4roses f:4roses.c r: c:
		DRIVER(4rosesa) //t:4rosesa f:4roses.c r:4roses c:4roses
//SET: big10
		DRIVER(big10) //t:big10 f:big10.c r: c:
//SET: bingor1
		DRIVER(bingor1) //t:bingor1 f:bingor.c r: c:
//SET: bingor2
		DRIVER(bingor2) //t:bingor2 f:bingor.c r: c:
//SET: bingor3
		DRIVER(bingor3) //t:bingor3 f:bingor.c r: c:
//SET: bingor4
		DRIVER(bingor4) //t:bingor4 f:bingor.c r: c:
//SET: bingor5
		DRIVER(bingor5) //t:bingor5 f:bingor.c r: c:
//SET: videopkr
		DRIVER(videopkr) //t:videopkr f:videopkr.c r: c:
		DRIVER(fortune1) //t:fortune1 f:videopkr.c r:videopkr c:videopkr
		DRIVER(blckjack) //t:blckjack f:videopkr.c r:videopkr c:videopkr
		DRIVER(videodad) //t:videodad f:videopkr.c r:videopkr c:videopkr
		DRIVER(videocba) //t:videocba f:videopkr.c r:videopkr c:videopkr
		DRIVER(babypkr) //t:babypkr f:videopkr.c r:videopkr c:videopkr
		DRIVER(babydad) //t:babydad f:videopkr.c r:videopkr c:videopkr
//SET: laperla
		DRIVER(laperla) //t:laperla f:itgamble.c r: c:
//SET: laperlag
		DRIVER(laperlag) //t:laperlag f:itgamble.c r: c:
//SET: capunc
		DRIVER(capunc) //t:capunc f:itgamble.c r: c:
//SET: capcor
		DRIVER(capcor) //t:capcor f:itgamble.c r: c:
//SET: euro2k2
		DRIVER(euro2k2) //t:euro2k2 f:itgamble.c r: c:
		DRIVER(euro2k2a) //t:euro2k2a f:itgamble.c r:euro2k2 c:euro2k2
		DRIVER(euro2k2s) //t:euro2k2s f:itgamble.c r:euro2k2 c:euro2k2
//SET: mnumber
		DRIVER(mnumber) //t:mnumber f:itgamble.c r: c:
//SET: abacus
		DRIVER(abacus) //t:abacus f:itgamble.c r: c:
//SET: bookthr
		DRIVER(bookthr) //t:bookthr f:itgamble.c r: c:
//SET: ntcash
		DRIVER(ntcash) //t:ntcash f:itgambl2.c r: c:
//SET: wizard
		DRIVER(wizard) //t:wizard f:itgambl2.c r: c:
//SET: trstar2k
		DRIVER(trstar2k) //t:trstar2k f:itgambl2.c r: c:
//SET: laser2k1
		DRIVER(laser2k1) //t:laser2k1 f:itgambl2.c r: c:
//SET: mdrink
		DRIVER(mdrink) //t:mdrink f:itgambl2.c r: c:
//SET: te0144
		DRIVER(te0144) //t:te0144 f:itgambl2.c r: c:
//SET: cmagica
		DRIVER(cmagica) //t:cmagica f:itgambl2.c r: c:
//SET: millsun
		DRIVER(millsun) //t:millsun f:itgambl2.c r: c:
//SET: sspac2k1
		DRIVER(sspac2k1) //t:sspac2k1 f:itgambl2.c r: c:
//SET: elvis
		DRIVER(elvis) //t:elvis f:itgambl2.c r: c:
//SET: sstar
		DRIVER(sstar) //t:sstar f:itgambl2.c r: c:
//SET: pirati
		DRIVER(pirati) //t:pirati f:itgambl2.c r: c:
//SET: mnumitg
		DRIVER(mnumitg) //t:mnumitg f:itgambl2.c r: c:
//SET: mclass
		DRIVER(mclass) //t:mclass f:itgambl2.c r: c:
//SET: europass
		DRIVER(europass) //t:europass f:itgambl2.c r: c:
//SET: newmcard
		DRIVER(newmcard) //t:newmcard f:highvdeo.c r: c:
//SET: brasil
		DRIVER(brasil) //t:brasil f:highvdeo.c r: c:
		DRIVER(fashion) //t:fashion f:highvdeo.c r:brasil c:brasil
//SET: ciclone
		DRIVER(ciclone) //t:ciclone f:highvdeo.c r: c:
//SET: tour4000
		DRIVER(tour4000) //t:tour4000 f:highvdeo.c r: c:
//SET: cfever40
		DRIVER(cfever40) //t:cfever40 f:highvdeo.c r: c:
//SET: cfever50
		DRIVER(cfever50) //t:cfever50 f:highvdeo.c r: c:
//SET: tour4010
		DRIVER(tour4010) //t:tour4010 f:highvdeo.c r: c:
//SET: cfever51
		DRIVER(cfever51) //t:cfever51 f:highvdeo.c r: c:
//SET: cfever61
		DRIVER(cfever61) //t:cfever61 f:highvdeo.c r: c:
//SET: cfever1k
		DRIVER(cfever1k) //t:cfever1k f:highvdeo.c r: c:
//SET: girotutt
		DRIVER(girotutt) //t:girotutt f:highvdeo.c r: c:
//SET: mil4000
		DRIVER(mil4000) //t:mil4000 f:mil4000.c r: c:
		DRIVER(mil4000a) //t:mil4000a f:mil4000.c r:mil4000 c:mil4000
		DRIVER(mil4000b) //t:mil4000b f:mil4000.c r:mil4000 c:mil4000
		DRIVER(mil4000c) //t:mil4000c f:mil4000.c r:mil4000 c:mil4000
//SET: ejollyx5
		DRIVER(ejollyx5) //t:ejollyx5 f:itgambl3.c r: c:
//SET: grandprx
		DRIVER(grandprx) //t:grandprx f:itgambl3.c r: c:
//SET: supjolly
		DRIVER(supjolly) //t:supjolly f:itgambl3.c r: c:
//SET: x5jokers
		DRIVER(x5jokers) //t:x5jokers f:itgambl3.c r: c:
//SET: showhand
		DRIVER(showhand) //t:showhand f:astrocorp.c r: c:
		DRIVER(showhanc) //t:showhanc f:astrocorp.c r:showhand c:showhand
//SET: skilldrp
		DRIVER(skilldrp) //t:skilldrp f:astrocorp.c r: c:
//SET: speeddrp
		DRIVER(speeddrp) //t:speeddrp f:astrocorp.c r: c:
//SET: winbingo
		DRIVER(winbingo) //t:winbingo f:astrocorp.c r: c:
		DRIVER(winbingoa) //t:winbingoa f:astrocorp.c r:winbingo c:winbingo
//SET: zoo
		DRIVER(zoo) //t:zoo f:astrocorp.c r: c:
//SET: westvent
		DRIVER(westvent) //t:westvent f:astrocorp.c r: c:
//SET: ncb3
		DRIVER(ncb3) //t:ncb3 f:goldstar.c r: c:
		DRIVER(cb3a) //t:cb3a f:goldstar.c r:ncb3 c:ncb3
		DRIVER(cb3) //t:cb3 f:goldstar.c r:ncb3 c:ncb3
		DRIVER(cb3b) //t:cb3b f:goldstar.c r:ncb3 c:ncb3
		DRIVER(cb3c) //t:cb3c f:goldstar.c r:ncb3 c:ncb3
		DRIVER(cb3d) //t:cb3d f:goldstar.c r:ncb3 c:ncb3
		DRIVER(chryangl) //t:chryangl f:goldstar.c r:ncb3 c:ncb3
//SET: cmv801
		DRIVER(cmv801) //t:cmv801 f:goldstar.c r: c:
//SET: cmv4
		DRIVER(cmv4) //t:cmv4 f:goldstar.c r: c:
		DRIVER(cmv4a) //t:cmv4a f:goldstar.c r:cmv4 c:cmv4
		DRIVER(cmwm) //t:cmwm f:goldstar.c r:cmv4 c:cmv4
		DRIVER(cmfun) //t:cmfun f:goldstar.c r:cmv4 c:cmv4
//SET: cmaster
		DRIVER(cmaster) //t:cmaster f:goldstar.c r: c:
		DRIVER(cmasterb) //t:cmasterb f:goldstar.c r:cmaster c:cmaster
		DRIVER(cmezspin) //t:cmezspin f:goldstar.c r:cmaster c:cmaster
		DRIVER(cmasterc) //t:cmasterc f:goldstar.c r:cmaster c:cmaster
		DRIVER(cmasterbv) //t:cmasterbv f:goldstar.c r:cmaster c:cmaster
		DRIVER(cmasterd) //t:cmasterd f:goldstar.c r:cmaster c:cmaster
		DRIVER(cmastere) //t:cmastere f:goldstar.c r:cmaster c:cmaster
		DRIVER(cmasterf) //t:cmasterf f:goldstar.c r:cmaster c:cmaster
//SET: cmast91
		DRIVER(cmast91) //t:cmast91 f:goldstar.c r: c:
//SET: cmast92
		DRIVER(cmast92) //t:cmast92 f:goldstar.c r: c:
//SET: tonypok
		DRIVER(tonypok) //t:tonypok f:goldstar.c r: c:
//SET: jkrmast
		DRIVER(jkrmast) //t:jkrmast f:goldstar.c r: c:
		DRIVER(pkrmast) //t:pkrmast f:goldstar.c r:jkrmast c:jkrmast
		DRIVER(pkrmasta) //t:pkrmasta f:goldstar.c r:jkrmast c:jkrmast
//SET: cb2001
		DRIVER(cb2001) //t:cb2001 f:cb2001.c r: c:
//SET: scherrym
		DRIVER(scherrym) //t:scherrym f:cb2001.c r: c:
//SET: queen
		DRIVER(queen) //t:queen f:queen.c r: c:
//SET: 86lions
		DRIVER(86lions) //t:86lions f:86lions.c r: c:
//SET: gtroppo
		DRIVER(gtroppo) //t:gtroppo f:aristmk4.c r: c:
//SET: clkwise
		DRIVER(clkwise) //t:clkwise f:aristmk4.c r: c:
//SET: gldnpkr
		DRIVER(gldnpkr) //t:gldnpkr f:aristmk4.c r: c:
//SET: 3bagflvt
		DRIVER(3bagflvt) //t:3bagflvt f:aristmk4.c r: c:
		DRIVER(3bagflnz) //t:3bagflnz f:aristmk4.c r:3bagflvt c:3bagflvt
//SET: eforest
		DRIVER(eforest) //t:eforest f:aristmk4.c r: c:
		DRIVER(eforesta) //t:eforesta f:aristmk4.c r:eforest c:eforest
		DRIVER(eforestb) //t:eforestb f:aristmk4.c r:eforest c:eforest
//SET: cgold2
		DRIVER(cgold2) //t:cgold2 f:aristmk4.c r: c:
//SET: blkrhino
		DRIVER(blkrhino) //t:blkrhino f:aristmk4.c r: c:
//SET: goldenc
		DRIVER(goldenc) //t:goldenc f:aristmk4.c r: c:
//SET: kgbird
		DRIVER(kgbird) //t:kgbird f:aristmk4.c r: c:
		DRIVER(kgbirda) //t:kgbirda f:aristmk4.c r:kgbird c:kgbird
//SET: topgear
		DRIVER(topgear) //t:topgear f:aristmk4.c r: c:
//SET: wtigernz
		DRIVER(wtigernz) //t:wtigernz f:aristmk4.c r: c:
//SET: fhunter
		DRIVER(fhunter) //t:fhunter f:aristmk4.c r: c:
		DRIVER(fhuntera) //t:fhuntera f:aristmk4.c r:fhunter c:fhunter
//SET: arcwins
		DRIVER(arcwins) //t:arcwins f:aristmk4.c r: c:
//SET: wildone
		DRIVER(wildone) //t:wildone f:aristmk4.c r: c:
//SET: phantomp
		DRIVER(phantomp) //t:phantomp f:aristmk4.c r: c:
//SET: swtht2nz
		DRIVER(swtht2nz) //t:swtht2nz f:aristmk4.c r: c:
//SET: ffortune
		DRIVER(ffortune) //t:ffortune f:aristmk4.c r: c:
//SET: autmoon
		DRIVER(autmoon) //t:autmoon f:aristmk4.c r: c:
//SET: coralr2
		DRIVER(coralr2) //t:coralr2 f:aristmk4.c r: c:
//SET: aristmk5
		DRIVER(aristmk5) //t:aristmk5 f:aristmk5.c r: c:
//SET: swthrt2v
		DRIVER(swthrt2v) //t:swthrt2v f:aristmk5.c r:aristmk5 c:
//SET: enchfrst
		DRIVER(enchfrst) //t:enchfrst f:aristmk5.c r:aristmk5 c:
//SET: dolphntr
		DRIVER(dolphntr) //t:dolphntr f:aristmk5.c r:aristmk5 c:
		DRIVER(dolphtra) //t:dolphtra f:aristmk5.c r:dolphntr c:dolphntr
//SET: dmdtouch
		DRIVER(dmdtouch) //t:dmdtouch f:aristmk5.c r:aristmk5 c:
//SET: goldprmd
		DRIVER(goldprmd) //t:goldprmd f:aristmk5.c r:aristmk5 c:
//SET: qotn
		DRIVER(qotn) //t:qotn f:aristmk5.c r:aristmk5 c:
//SET: adonis
		DRIVER(adonis) //t:adonis f:aristmk5.c r:aristmk5 c:
//SET: reelrock
		DRIVER(reelrock) //t:reelrock f:aristmk5.c r:aristmk5 c:
//SET: indiandr
		DRIVER(indiandr) //t:indiandr f:aristmk5.c r:aristmk5 c:
//SET: magicmsk
		DRIVER(magicmsk) //t:magicmsk f:aristmk5.c r:aristmk5 c:
//SET: margmgc
		DRIVER(margmgc) //t:margmgc f:aristmk5.c r:aristmk5 c:
//SET: geishanz
		DRIVER(geishanz) //t:geishanz f:aristmk5.c r:aristmk5 c:
//SET: wtiger
		DRIVER(wtiger) //t:wtiger f:aristmk5.c r:aristmk5 c:
//SET: janshi
		DRIVER(janshi) //t:janshi f:pinkiri8.c r: c:
//SET: ronjan
		DRIVER(ronjan) //t:ronjan f:pinkiri8.c r: c:
//SET: pinkiri8
		DRIVER(pinkiri8) //t:pinkiri8 f:pinkiri8.c r: c:
//SET: slotcarn
		DRIVER(slotcarn) //t:slotcarn f:slotcarn.c r: c:
//SET: lucky74
		DRIVER(lucky74) //t:lucky74 f:lucky74.c r: c:
		DRIVER(lucky74a) //t:lucky74a f:lucky74.c r:lucky74 c:lucky74
//SET: lucky8
		DRIVER(lucky8) //t:lucky8 f:goldstar.c r: c:
		DRIVER(lucky8a) //t:lucky8a f:goldstar.c r:lucky8 c:lucky8
		DRIVER(lucky8b) //t:lucky8b f:goldstar.c r:lucky8 c:lucky8
//SET: luckgrln
		DRIVER(luckgrln) //t:luckgrln f:luckgrln.c r: c:
//SET: luckylad
		DRIVER(luckylad) //t:luckylad f:goldstar.c r: c:
//SET: skill98
		DRIVER(skill98) //t:skill98 f:goldstar.c r: c:
//SET: match98
		DRIVER(match98) //t:match98 f:goldstar.c r: c:
//SET: schery97
		DRIVER(schery97) //t:schery97 f:goldstar.c r: c:
		DRIVER(schery97a) //t:schery97a f:goldstar.c r:schery97 c:schery97
//SET: roypok96
		DRIVER(roypok96) //t:roypok96 f:goldstar.c r: c:
		DRIVER(roypok96a) //t:roypok96a f:goldstar.c r:roypok96 c:roypok96
		DRIVER(roypok96b) //t:roypok96b f:goldstar.c r:roypok96 c:roypok96
//SET: pokonl97
		DRIVER(pokonl97) //t:pokonl97 f:goldstar.c r: c:
//SET: nfb96
		DRIVER(nfb96) //t:nfb96 f:goldstar.c r: c:
		DRIVER(nc96) //t:nc96 f:goldstar.c r:nfb96 c:nfb96
		DRIVER(nc96a) //t:nc96a f:goldstar.c r:nfb96 c:nfb96
		DRIVER(nc96b) //t:nc96b f:goldstar.c r:nfb96 c:nfb96
		DRIVER(nc96c) //t:nc96c f:goldstar.c r:nfb96 c:nfb96
		DRIVER(nc96txt) //t:nc96txt f:goldstar.c r:nfb96 c:nfb96
		DRIVER(nfb96a) //t:nfb96a f:goldstar.c r:nfb96 c:nfb96
		DRIVER(nfb96b) //t:nfb96b f:goldstar.c r:nfb96 c:nfb96
		DRIVER(nfb96c) //t:nfb96c f:goldstar.c r:nfb96 c:nfb96
		DRIVER(nfb96txt) //t:nfb96txt f:goldstar.c r:nfb96 c:nfb96
		DRIVER(nfb96se) //t:nfb96se f:goldstar.c r:nfb96 c:nfb96
		DRIVER(nfb96sea) //t:nfb96sea f:goldstar.c r:nfb96 c:nfb96
		DRIVER(nfb96seb) //t:nfb96seb f:goldstar.c r:nfb96 c:nfb96
		DRIVER(carb2002) //t:carb2002 f:goldstar.c r:nfb96 c:nfb96
		DRIVER(carb2003) //t:carb2003 f:goldstar.c r:nfb96 c:nfb96
//SET: nfm
		DRIVER(nfm) //t:nfm f:goldstar.c r: c:
//SET: unkch1
		DRIVER(unkch1) //t:unkch1 f:goldstar.c r: c:
		DRIVER(unkch2) //t:unkch2 f:goldstar.c r:unkch1 c:unkch1
		DRIVER(unkch3) //t:unkch3 f:goldstar.c r:unkch1 c:unkch1
		DRIVER(unkch4) //t:unkch4 f:goldstar.c r:unkch1 c:unkch1
//SET: ns8lines
		DRIVER(ns8lines) //t:ns8lines f:goldstar.c r: c:
//SET: ns8linew
		DRIVER(ns8linew) //t:ns8linew f:goldstar.c r: c:
//SET: ladylinr
		DRIVER(ladylinr) //t:ladylinr f:goldstar.c r: c:
//SET: kkojnoli
		DRIVER(kkojnoli) //t:kkojnoli f:goldstar.c r: c:
//SET: wcat3
		DRIVER(wcat3) //t:wcat3 f:goldstar.c r: c:
//SET: magodds
		DRIVER(magodds) //t:magodds f:goldstar.c r: c:
		DRIVER(magoddsa) //t:magoddsa f:goldstar.c r:magodds c:magodds
		DRIVER(magoddsb) //t:magoddsb f:goldstar.c r:magodds c:magodds
		DRIVER(magoddsc) //t:magoddsc f:goldstar.c r:magodds c:magodds
		DRIVER(magoddsd) //t:magoddsd f:goldstar.c r:magodds c:magodds
//SET: sfbonus
		DRIVER(sfbonus) //t:sfbonus f:sfbonus.c r: c:
		DRIVER(sfbonusd1) //t:sfbonusd1 f:sfbonus.c r:sfbonus c:sfbonus
		DRIVER(sfbonusv1) //t:sfbonusv1 f:sfbonus.c r:sfbonus c:sfbonus
		DRIVER(sfbonuso) //t:sfbonuso f:sfbonus.c r:sfbonus c:sfbonus
		DRIVER(sfbonuso2) //t:sfbonuso2 f:sfbonus.c r:sfbonus c:sfbonus
//SET: parrot3
		DRIVER(parrot3) //t:parrot3 f:sfbonus.c r: c:
		DRIVER(parrot3b1) //t:parrot3b1 f:sfbonus.c r:parrot3 c:parrot3
		DRIVER(parrot3d1) //t:parrot3d1 f:sfbonus.c r:parrot3 c:parrot3
		DRIVER(parrot3v1) //t:parrot3v1 f:sfbonus.c r:parrot3 c:parrot3
		DRIVER(parrot3o) //t:parrot3o f:sfbonus.c r:parrot3 c:parrot3
//SET: hldspin1
		DRIVER(hldspin1) //t:hldspin1 f:sfbonus.c r: c:
		DRIVER(hldspin1dt) //t:hldspin1dt f:sfbonus.c r:hldspin1 c:hldspin1
		DRIVER(hldspin1vt) //t:hldspin1vt f:sfbonus.c r:hldspin1 c:hldspin1
		DRIVER(hldspin1o) //t:hldspin1o f:sfbonus.c r:hldspin1 c:hldspin1
//SET: hldspin2
		DRIVER(hldspin2) //t:hldspin2 f:sfbonus.c r: c:
		DRIVER(hldspin2d1) //t:hldspin2d1 f:sfbonus.c r:hldspin2 c:hldspin2
		DRIVER(hldspin2v1) //t:hldspin2v1 f:sfbonus.c r:hldspin2 c:hldspin2
		DRIVER(hldspin2o) //t:hldspin2o f:sfbonus.c r:hldspin2 c:hldspin2
//SET: fcnudge
		DRIVER(fcnudge) //t:fcnudge f:sfbonus.c r: c:
		DRIVER(fcnudgeo) //t:fcnudgeo f:sfbonus.c r:fcnudge c:fcnudge
		DRIVER(fcnudgeo2) //t:fcnudgeo2 f:sfbonus.c r:fcnudge c:fcnudge
		DRIVER(fcnudgeo3) //t:fcnudgeo3 f:sfbonus.c r:fcnudge c:fcnudge
//SET: pickwin
		DRIVER(pickwin) //t:pickwin f:sfbonus.c r: c:
		DRIVER(pickwinb1) //t:pickwinb1 f:sfbonus.c r:pickwin c:pickwin
		DRIVER(pickwind1) //t:pickwind1 f:sfbonus.c r:pickwin c:pickwin
		DRIVER(pickwinv1) //t:pickwinv1 f:sfbonus.c r:pickwin c:pickwin
		DRIVER(pickwinbt) //t:pickwinbt f:sfbonus.c r:pickwin c:pickwin
		DRIVER(pickwindt) //t:pickwindt f:sfbonus.c r:pickwin c:pickwin
		DRIVER(pickwinvt) //t:pickwinvt f:sfbonus.c r:pickwin c:pickwin
		DRIVER(pickwino) //t:pickwino f:sfbonus.c r:pickwin c:pickwin
		DRIVER(pickwino2) //t:pickwino2 f:sfbonus.c r:pickwin c:pickwin
//SET: tighook
		DRIVER(tighook) //t:tighook f:sfbonus.c r: c:
		DRIVER(tighookc1) //t:tighookc1 f:sfbonus.c r:tighook c:tighook
		DRIVER(tighookd1) //t:tighookd1 f:sfbonus.c r:tighook c:tighook
		DRIVER(tighookv1) //t:tighookv1 f:sfbonus.c r:tighook c:tighook
		DRIVER(tighookc2) //t:tighookc2 f:sfbonus.c r:tighook c:tighook
		DRIVER(tighookd2) //t:tighookd2 f:sfbonus.c r:tighook c:tighook
		DRIVER(tighookv2) //t:tighookv2 f:sfbonus.c r:tighook c:tighook
		DRIVER(tighooko) //t:tighooko f:sfbonus.c r:tighook c:tighook
		DRIVER(tighooko2) //t:tighooko2 f:sfbonus.c r:tighook c:tighook
//SET: robadv
		DRIVER(robadv) //t:robadv f:sfbonus.c r: c:
		DRIVER(robadvc1) //t:robadvc1 f:sfbonus.c r:robadv c:robadv
		DRIVER(robadvd1) //t:robadvd1 f:sfbonus.c r:robadv c:robadv
		DRIVER(robadvv1) //t:robadvv1 f:sfbonus.c r:robadv c:robadv
		DRIVER(robadvo) //t:robadvo f:sfbonus.c r:robadv c:robadv
//SET: robadv2
		DRIVER(robadv2) //t:robadv2 f:sfbonus.c r: c:
		DRIVER(robadv2c1) //t:robadv2c1 f:sfbonus.c r:robadv2 c:robadv2
		DRIVER(robadv2d1) //t:robadv2d1 f:sfbonus.c r:robadv2 c:robadv2
		DRIVER(robadv2v1) //t:robadv2v1 f:sfbonus.c r:robadv2 c:robadv2
		DRIVER(robadv2c2) //t:robadv2c2 f:sfbonus.c r:robadv2 c:robadv2
		DRIVER(robadv2d2) //t:robadv2d2 f:sfbonus.c r:robadv2 c:robadv2
		DRIVER(robadv2v2) //t:robadv2v2 f:sfbonus.c r:robadv2 c:robadv2
		DRIVER(robadv2c3) //t:robadv2c3 f:sfbonus.c r:robadv2 c:robadv2
		DRIVER(robadv2d3) //t:robadv2d3 f:sfbonus.c r:robadv2 c:robadv2
		DRIVER(robadv2v3) //t:robadv2v3 f:sfbonus.c r:robadv2 c:robadv2
		DRIVER(robadv2o) //t:robadv2o f:sfbonus.c r:robadv2 c:robadv2
		DRIVER(robadv2o2) //t:robadv2o2 f:sfbonus.c r:robadv2 c:robadv2
//SET: pirpok2
		DRIVER(pirpok2) //t:pirpok2 f:sfbonus.c r: c:
		DRIVER(pirpok2b1) //t:pirpok2b1 f:sfbonus.c r:pirpok2 c:pirpok2
		DRIVER(pirpok2d1) //t:pirpok2d1 f:sfbonus.c r:pirpok2 c:pirpok2
		DRIVER(pirpok2v1) //t:pirpok2v1 f:sfbonus.c r:pirpok2 c:pirpok2
		DRIVER(pirpok2o) //t:pirpok2o f:sfbonus.c r:pirpok2 c:pirpok2
//SET: anibonus
		DRIVER(anibonus) //t:anibonus f:sfbonus.c r: c:
		DRIVER(anibonusv1) //t:anibonusv1 f:sfbonus.c r:anibonus c:anibonus
		DRIVER(anibonusv2) //t:anibonusv2 f:sfbonus.c r:anibonus c:anibonus
		DRIVER(anibonusb1) //t:anibonusb1 f:sfbonus.c r:anibonus c:anibonus
		DRIVER(anibonusd1) //t:anibonusd1 f:sfbonus.c r:anibonus c:anibonus
		DRIVER(anibonusb2) //t:anibonusb2 f:sfbonus.c r:anibonus c:anibonus
		DRIVER(anibonusd2) //t:anibonusd2 f:sfbonus.c r:anibonus c:anibonus
		DRIVER(anibonuso) //t:anibonuso f:sfbonus.c r:anibonus c:anibonus
		DRIVER(anibonuso2) //t:anibonuso2 f:sfbonus.c r:anibonus c:anibonus
		DRIVER(anibonuso3) //t:anibonuso3 f:sfbonus.c r:anibonus c:anibonus
		DRIVER(anibonusxo) //t:anibonusxo f:sfbonus.c r:anibonus c:anibonus
		DRIVER(anibonusxo2) //t:anibonusxo2 f:sfbonus.c r:anibonus c:anibonus
		DRIVER(anibonusxo3) //t:anibonusxo3 f:sfbonus.c r:anibonus c:anibonus
//SET: abnudge
		DRIVER(abnudge) //t:abnudge f:sfbonus.c r: c:
		DRIVER(abnudgeb) //t:abnudgeb f:sfbonus.c r:abnudge c:abnudge
		DRIVER(abnudged) //t:abnudged f:sfbonus.c r:abnudge c:abnudge
		DRIVER(abnudgeo) //t:abnudgeo f:sfbonus.c r:abnudge c:abnudge
//SET: dblchal
		DRIVER(dblchal) //t:dblchal f:sfbonus.c r: c:
		DRIVER(dblchalc1) //t:dblchalc1 f:sfbonus.c r:dblchal c:dblchal
		DRIVER(dblchald1) //t:dblchald1 f:sfbonus.c r:dblchal c:dblchal
		DRIVER(dblchalv1) //t:dblchalv1 f:sfbonus.c r:dblchal c:dblchal
		DRIVER(dblchalo) //t:dblchalo f:sfbonus.c r:dblchal c:dblchal
//SET: anithunt
		DRIVER(anithunt) //t:anithunt f:sfbonus.c r: c:
		DRIVER(anithuntd1) //t:anithuntd1 f:sfbonus.c r:anithunt c:anithunt
		DRIVER(anithuntv1) //t:anithuntv1 f:sfbonus.c r:anithunt c:anithunt
		DRIVER(anithunto) //t:anithunto f:sfbonus.c r:anithunt c:anithunt
		DRIVER(anithunto2) //t:anithunto2 f:sfbonus.c r:anithunt c:anithunt
//SET: sfruitb
		DRIVER(sfruitb) //t:sfruitb f:sfbonus.c r: c:
		DRIVER(sfruitbb1) //t:sfruitbb1 f:sfbonus.c r:sfruitb c:sfruitb
		DRIVER(sfruitbd1) //t:sfruitbd1 f:sfbonus.c r:sfruitb c:sfruitb
		DRIVER(sfruitbv1) //t:sfruitbv1 f:sfbonus.c r:sfruitb c:sfruitb
		DRIVER(sfruitbb2) //t:sfruitbb2 f:sfbonus.c r:sfruitb c:sfruitb
		DRIVER(sfruitbd2) //t:sfruitbd2 f:sfbonus.c r:sfruitb c:sfruitb
		DRIVER(sfruitbv2) //t:sfruitbv2 f:sfbonus.c r:sfruitb c:sfruitb
		DRIVER(sfruitbo) //t:sfruitbo f:sfbonus.c r:sfruitb c:sfruitb
		DRIVER(sfruitbo2) //t:sfruitbo2 f:sfbonus.c r:sfruitb c:sfruitb
		DRIVER(sfruitbh) //t:sfruitbh f:sfbonus.c r:sfruitb c:sfruitb
		DRIVER(sfruitbbh) //t:sfruitbbh f:sfbonus.c r:sfruitb c:sfruitb
		DRIVER(sfruitbdh) //t:sfruitbdh f:sfbonus.c r:sfruitb c:sfruitb
		DRIVER(sfruitbvh) //t:sfruitbvh f:sfbonus.c r:sfruitb c:sfruitb
		DRIVER(sfruitboh) //t:sfruitboh f:sfbonus.c r:sfruitb c:sfruitb
//SET: fb2gen
		DRIVER(fb2gen) //t:fb2gen f:sfbonus.c r: c:
		DRIVER(fb2genc1) //t:fb2genc1 f:sfbonus.c r:fb2gen c:fb2gen
		DRIVER(fb2gend1) //t:fb2gend1 f:sfbonus.c r:fb2gen c:fb2gen
		DRIVER(fb2genv1) //t:fb2genv1 f:sfbonus.c r:fb2gen c:fb2gen
		DRIVER(fb2genc2) //t:fb2genc2 f:sfbonus.c r:fb2gen c:fb2gen
		DRIVER(fb2gend2) //t:fb2gend2 f:sfbonus.c r:fb2gen c:fb2gen
		DRIVER(fb2genv2) //t:fb2genv2 f:sfbonus.c r:fb2gen c:fb2gen
		DRIVER(fb2geno) //t:fb2geno f:sfbonus.c r:fb2gen c:fb2gen
		DRIVER(fb2geno2) //t:fb2geno2 f:sfbonus.c r:fb2gen c:fb2gen
//SET: fb2nd
		DRIVER(fb2nd) //t:fb2nd f:sfbonus.c r: c:
		DRIVER(fb2ndd1) //t:fb2ndd1 f:sfbonus.c r:fb2nd c:fb2nd
		DRIVER(fb2ndv1) //t:fb2ndv1 f:sfbonus.c r:fb2nd c:fb2nd
		DRIVER(fb2ndc2) //t:fb2ndc2 f:sfbonus.c r:fb2nd c:fb2nd
		DRIVER(fb2ndd2) //t:fb2ndd2 f:sfbonus.c r:fb2nd c:fb2nd
		DRIVER(fb2ndv2) //t:fb2ndv2 f:sfbonus.c r:fb2nd c:fb2nd
		DRIVER(fb2ndo) //t:fb2ndo f:sfbonus.c r:fb2nd c:fb2nd
//SET: fb4
		DRIVER(fb4) //t:fb4 f:sfbonus.c r: c:
		DRIVER(fb4c1) //t:fb4c1 f:sfbonus.c r:fb4 c:fb4
		DRIVER(fb4d1) //t:fb4d1 f:sfbonus.c r:fb4 c:fb4
		DRIVER(fb4v1) //t:fb4v1 f:sfbonus.c r:fb4 c:fb4
		DRIVER(fb4exp) //t:fb4exp f:sfbonus.c r:fb4 c:fb4
		DRIVER(fb4b2) //t:fb4b2 f:sfbonus.c r:fb4 c:fb4
		DRIVER(fb4c2) //t:fb4c2 f:sfbonus.c r:fb4 c:fb4
		DRIVER(fb4d2) //t:fb4d2 f:sfbonus.c r:fb4 c:fb4
		DRIVER(fb4v2) //t:fb4v2 f:sfbonus.c r:fb4 c:fb4
		DRIVER(fb4o) //t:fb4o f:sfbonus.c r:fb4 c:fb4
		DRIVER(fb4o2) //t:fb4o2 f:sfbonus.c r:fb4 c:fb4
//SET: fb5
		DRIVER(fb5) //t:fb5 f:sfbonus.c r: c:
		DRIVER(fb5c) //t:fb5c f:sfbonus.c r:fb5 c:fb5
		DRIVER(fb5d) //t:fb5d f:sfbonus.c r:fb5 c:fb5
		DRIVER(fb5v) //t:fb5v f:sfbonus.c r:fb5 c:fb5
//SET: fb6
		DRIVER(fb6) //t:fb6 f:sfbonus.c r: c:
		DRIVER(fb6v) //t:fb6v f:sfbonus.c r:fb6 c:fb6
		DRIVER(fb6d1) //t:fb6d1 f:sfbonus.c r:fb6 c:fb6
		DRIVER(fb6s1) //t:fb6s1 f:sfbonus.c r:fb6 c:fb6
		DRIVER(fb6v1) //t:fb6v1 f:sfbonus.c r:fb6 c:fb6
		DRIVER(fb6d2) //t:fb6d2 f:sfbonus.c r:fb6 c:fb6
		DRIVER(fb6s2) //t:fb6s2 f:sfbonus.c r:fb6 c:fb6
		DRIVER(fb6v2) //t:fb6v2 f:sfbonus.c r:fb6 c:fb6
		DRIVER(fb6s3) //t:fb6s3 f:sfbonus.c r:fb6 c:fb6
//SET: fb6se
		DRIVER(fb6se) //t:fb6se f:sfbonus.c r: c:
		DRIVER(fb6sev) //t:fb6sev f:sfbonus.c r:fb6se c:fb6se
		DRIVER(fb6sed1) //t:fb6sed1 f:sfbonus.c r:fb6se c:fb6se
		DRIVER(fb6sev1) //t:fb6sev1 f:sfbonus.c r:fb6se c:fb6se
		DRIVER(fb6sed2) //t:fb6sed2 f:sfbonus.c r:fb6se c:fb6se
		DRIVER(fb6sev2) //t:fb6sev2 f:sfbonus.c r:fb6se c:fb6se
//SET: version4
		DRIVER(version4) //t:version4 f:sfbonus.c r: c:
//SET: bugfever
		DRIVER(bugfever) //t:bugfever f:sfbonus.c r: c:
		DRIVER(bugfevero) //t:bugfevero f:sfbonus.c r:bugfever c:bugfever
		DRIVER(bugfeverd) //t:bugfeverd f:sfbonus.c r:bugfever c:bugfever
		DRIVER(bugfeverv) //t:bugfeverv f:sfbonus.c r:bugfever c:bugfever
		DRIVER(bugfeverv2) //t:bugfeverv2 f:sfbonus.c r:bugfever c:bugfever
//SET: funriver
		DRIVER(funriver) //t:funriver f:sfbonus.c r: c:
		DRIVER(funriverv) //t:funriverv f:sfbonus.c r:funriver c:funriver
//SET: dvisland
		DRIVER(dvisland) //t:dvisland f:sfbonus.c r: c:
		DRIVER(dvislando) //t:dvislando f:sfbonus.c r:dvisland c:dvisland
//SET: atworld
		DRIVER(atworld) //t:atworld f:sfbonus.c r: c:
		DRIVER(atworldd1) //t:atworldd1 f:sfbonus.c r:atworld c:atworld
//SET: amclink
		DRIVER(amclink) //t:amclink f:sfbonus.c r: c:
//SET: fbdeluxe
		DRIVER(fbdeluxe) //t:fbdeluxe f:sfbonus.c r: c:
//SET: act2000
		DRIVER(act2000) //t:act2000 f:sfbonus.c r: c:
		DRIVER(act2000v1) //t:act2000v1 f:sfbonus.c r:act2000 c:act2000
		DRIVER(act2000d1) //t:act2000d1 f:sfbonus.c r:act2000 c:act2000
		DRIVER(act2000b1) //t:act2000b1 f:sfbonus.c r:act2000 c:act2000
		DRIVER(act2000vx) //t:act2000vx f:sfbonus.c r:act2000 c:act2000
		DRIVER(act2000dx) //t:act2000dx f:sfbonus.c r:act2000 c:act2000
		DRIVER(act2000bx) //t:act2000bx f:sfbonus.c r:act2000 c:act2000
		DRIVER(act2000o) //t:act2000o f:sfbonus.c r:act2000 c:act2000
		DRIVER(act2000o2) //t:act2000o2 f:sfbonus.c r:act2000 c:act2000
		DRIVER(act2000o3) //t:act2000o3 f:sfbonus.c r:act2000 c:act2000
//SET: ch2000
		DRIVER(ch2000) //t:ch2000 f:sfbonus.c r: c:
		DRIVER(ch2000b1) //t:ch2000b1 f:sfbonus.c r:ch2000 c:ch2000
		DRIVER(ch2000c1) //t:ch2000c1 f:sfbonus.c r:ch2000 c:ch2000
		DRIVER(ch2000d1) //t:ch2000d1 f:sfbonus.c r:ch2000 c:ch2000
		DRIVER(ch2000v1) //t:ch2000v1 f:sfbonus.c r:ch2000 c:ch2000
		DRIVER(ch2000b2) //t:ch2000b2 f:sfbonus.c r:ch2000 c:ch2000
		DRIVER(ch2000c2) //t:ch2000c2 f:sfbonus.c r:ch2000 c:ch2000
		DRIVER(ch2000d2) //t:ch2000d2 f:sfbonus.c r:ch2000 c:ch2000
		DRIVER(ch2000v2) //t:ch2000v2 f:sfbonus.c r:ch2000 c:ch2000
		DRIVER(ch2000o) //t:ch2000o f:sfbonus.c r:ch2000 c:ch2000
		DRIVER(ch2000o2) //t:ch2000o2 f:sfbonus.c r:ch2000 c:ch2000
		DRIVER(ch2000o3) //t:ch2000o3 f:sfbonus.c r:ch2000 c:ch2000
//SET: pir2001
		DRIVER(pir2001) //t:pir2001 f:sfbonus.c r: c:
		DRIVER(pir2001b1) //t:pir2001b1 f:sfbonus.c r:pir2001 c:pir2001
		DRIVER(pir2001d1) //t:pir2001d1 f:sfbonus.c r:pir2001 c:pir2001
		DRIVER(pir2001v1) //t:pir2001v1 f:sfbonus.c r:pir2001 c:pir2001
		DRIVER(pir2001bx) //t:pir2001bx f:sfbonus.c r:pir2001 c:pir2001
		DRIVER(pir2001dx) //t:pir2001dx f:sfbonus.c r:pir2001 c:pir2001
		DRIVER(pir2001vx) //t:pir2001vx f:sfbonus.c r:pir2001 c:pir2001
		DRIVER(pir2001o) //t:pir2001o f:sfbonus.c r:pir2001 c:pir2001
		DRIVER(pir2001o2) //t:pir2001o2 f:sfbonus.c r:pir2001 c:pir2001
		DRIVER(pir2001o3) //t:pir2001o3 f:sfbonus.c r:pir2001 c:pir2001
//SET: pir2002
		DRIVER(pir2002) //t:pir2002 f:sfbonus.c r: c:
		DRIVER(pir2002b1) //t:pir2002b1 f:sfbonus.c r:pir2002 c:pir2002
		DRIVER(pir2002d1) //t:pir2002d1 f:sfbonus.c r:pir2002 c:pir2002
		DRIVER(pir2002v1) //t:pir2002v1 f:sfbonus.c r:pir2002 c:pir2002
		DRIVER(pir2002bx) //t:pir2002bx f:sfbonus.c r:pir2002 c:pir2002
		DRIVER(pir2002dx) //t:pir2002dx f:sfbonus.c r:pir2002 c:pir2002
		DRIVER(pir2002vx) //t:pir2002vx f:sfbonus.c r:pir2002 c:pir2002
		DRIVER(pir2002o) //t:pir2002o f:sfbonus.c r:pir2002 c:pir2002
		DRIVER(pir2002o2) //t:pir2002o2 f:sfbonus.c r:pir2002 c:pir2002
		DRIVER(pir2002o3) //t:pir2002o3 f:sfbonus.c r:pir2002 c:pir2002
//SET: classice
		DRIVER(classice) //t:classice f:sfbonus.c r: c:
		DRIVER(classicev) //t:classicev f:sfbonus.c r:classice c:classice
		DRIVER(classice1) //t:classice1 f:sfbonus.c r:classice c:classice
		DRIVER(classiced1) //t:classiced1 f:sfbonus.c r:classice c:classice
		DRIVER(classicev1) //t:classicev1 f:sfbonus.c r:classice c:classice
		DRIVER(classice2) //t:classice2 f:sfbonus.c r:classice c:classice
		DRIVER(classiced2) //t:classiced2 f:sfbonus.c r:classice c:classice
		DRIVER(classicev2) //t:classicev2 f:sfbonus.c r:classice c:classice
//SET: seawld
		DRIVER(seawld) //t:seawld f:sfbonus.c r: c:
		DRIVER(seawldd1) //t:seawldd1 f:sfbonus.c r:seawld c:seawld
//SET: moneymac
		DRIVER(moneymac) //t:moneymac f:sfbonus.c r: c:
		DRIVER(moneymacd1) //t:moneymacd1 f:sfbonus.c r:moneymac c:moneymac
		DRIVER(moneymacv1) //t:moneymacv1 f:sfbonus.c r:moneymac c:moneymac
		DRIVER(moneymacd2) //t:moneymacd2 f:sfbonus.c r:moneymac c:moneymac
		DRIVER(moneymacv2) //t:moneymacv2 f:sfbonus.c r:moneymac c:moneymac
//SET: chsuper3
		DRIVER(chsuper3) //t:chsuper3 f:chsuper.c r: c:
		DRIVER(chsuper2) //t:chsuper2 f:chsuper.c r:chsuper3 c:chsuper3
		DRIVER(chmpnum) //t:chmpnum f:chsuper.c r:chsuper3 c:chsuper3
//SET: 3super8
		DRIVER(3super8) //t:3super8 f:3super8.c r: c:
//SET: buster
		DRIVER(buster) //t:buster f:buster.c r: c:
//SET: spielbud
		DRIVER(spielbud) //t:spielbud f:slotcarn.c r: c:
//SET: himesiki
		DRIVER(himesiki) //t:himesiki f:himesiki.c r: c:
//SET: norautp
		DRIVER(norautp) //t:norautp f:norautp.c r: c:
		DRIVER(norautpn) //t:norautpn f:norautp.c r:norautp c:norautp
		DRIVER(norautjp) //t:norautjp f:norautp.c r:norautp c:norautp
//SET: norautdx
		DRIVER(norautdx) //t:norautdx f:norautp.c r: c:
//SET: norautjo
		DRIVER(norautjo) //t:norautjo f:norautp.c r: c:
//SET: norautpl
		DRIVER(norautpl) //t:norautpl f:norautp.c r: c:
//SET: norautrh
		DRIVER(norautrh) //t:norautrh f:norautp.c r: c:
//SET: norautra
		DRIVER(norautra) //t:norautra f:norautp.c r: c:
//SET: norautu
		DRIVER(norautu) //t:norautu f:norautp.c r: c:
//SET: noraut3a
		DRIVER(noraut3a) //t:noraut3a f:norautp.c r: c:
//SET: noraut3b
		DRIVER(noraut3b) //t:noraut3b f:norautp.c r: c:
//SET: norautua
		DRIVER(norautua) //t:norautua f:norautp.c r: c:
//SET: norautub
		DRIVER(norautub) //t:norautub f:norautp.c r: c:
//SET: mainline
		DRIVER(mainline) //t:mainline f:norautp.c r: c:
//SET: df_djpkr
		DRIVER(df_djpkr) //t:df_djpkr f:norautp.c r: c:
//SET: ndxron10
		DRIVER(ndxron10) //t:ndxron10 f:norautp.c r: c:
//SET: cgip30cs
		DRIVER(cgip30cs) //t:cgip30cs f:norautp.c r: c:
//SET: kimblz80
		DRIVER(kimblz80) //t:kimblz80 f:norautp.c r: c:
//SET: pma
		DRIVER(pma) //t:pma f:norautp.c r: c:
//SET: bjpoker
		DRIVER(bjpoker) //t:bjpoker f:norautp.c r: c:
//SET: dphl
		DRIVER(dphl) //t:dphl f:norautp.c r: c:
//SET: dphla
		DRIVER(dphla) //t:dphla f:norautp.c r: c:
//SET: dphljp
		DRIVER(dphljp) //t:dphljp f:norautp.c r: c:
//SET: kimbldhl
		DRIVER(kimbldhl) //t:kimbldhl f:norautp.c r: c:
//SET: gtipoker
		DRIVER(gtipoker) //t:gtipoker f:norautp.c r: c:
//SET: smshilo
		DRIVER(smshilo) //t:smshilo f:norautp.c r: c:
//SET: drhl
		DRIVER(drhl) //t:drhl f:norautp.c r: c:
//SET: drhla
		DRIVER(drhla) //t:drhla f:norautp.c r: c:
//SET: tpoker2
		DRIVER(tpoker2) //t:tpoker2 f:norautp.c r: c:
//SET: ssjkrpkr
		DRIVER(ssjkrpkr) //t:ssjkrpkr f:norautp.c r: c:
//SET: fastdrwp
		DRIVER(fastdrwp) //t:fastdrwp f:norautp.c r: c:
//SET: dphlunka
		DRIVER(dphlunka) //t:dphlunka f:norautp.c r: c:
//SET: dphlunkb
		DRIVER(dphlunkb) //t:dphlunkb f:norautp.c r: c:
//SET: pachifev
		DRIVER(pachifev) //t:pachifev f:pachifev.c r: c:
//SET: bonanza
		DRIVER(bonanza) //t:bonanza f:pcat_nit.c r: c:
		DRIVER(bonanzar2) //t:bonanzar2 f:pcat_nit.c r:bonanza c:bonanza
//SET: streetg
		DRIVER(streetg) //t:streetg f:pcat_nit.c r: c:
		DRIVER(streetgr3) //t:streetgr3 f:pcat_nit.c r:streetg c:streetg
//SET: streetg2
		DRIVER(streetg2) //t:streetg2 f:pcat_nit.c r: c:
		DRIVER(streetg2r5) //t:streetg2r5 f:pcat_nit.c r:streetg2 c:streetg2
//SET: magtouch
		DRIVER(magtouch) //t:magtouch f:magtouch.c r: c:
//SET: colorama
		DRIVER(colorama) //t:colorama f:coinmvga.c r: c:
//SET: cmrltv75
		DRIVER(cmrltv75) //t:cmrltv75 f:coinmvga.c r: c:
//SET: cmkenosp
		DRIVER(cmkenosp) //t:cmkenosp f:coinmvga.c r: c:
		DRIVER(cmkenospa) //t:cmkenospa f:coinmvga.c r:cmkenosp c:cmkenosp
//SET: mfish_3
		DRIVER(mfish_3) //t:mfish_3 f:multfish.c r: c:
		DRIVER(mfish_6) //t:mfish_6 f:multfish.c r:mfish_3 c:mfish_3
		DRIVER(mfish_11) //t:mfish_11 f:multfish.c r:mfish_3 c:mfish_3
		DRIVER(mfish_12) //t:mfish_12 f:multfish.c r:mfish_3 c:mfish_3
		DRIVER(mfish_13) //t:mfish_13 f:multfish.c r:mfish_3 c:mfish_3
		DRIVER(mfish_3a) //t:mfish_3a f:multfish.c r:mfish_3 c:mfish_3
		DRIVER(mfish_12a) //t:mfish_12a f:multfish.c r:mfish_3 c:mfish_3
//SET: crzmon_5
		DRIVER(crzmon_5) //t:crzmon_5 f:multfish.c r: c:
		DRIVER(crzmon_7) //t:crzmon_7 f:multfish.c r:crzmon_5 c:crzmon_5
		DRIVER(crzmon_8) //t:crzmon_8 f:multfish.c r:crzmon_5 c:crzmon_5
		DRIVER(crzmon_9) //t:crzmon_9 f:multfish.c r:crzmon_5 c:crzmon_5
		DRIVER(crzmon_7a) //t:crzmon_7a f:multfish.c r:crzmon_5 c:crzmon_5
		DRIVER(crzmon_7b) //t:crzmon_7b f:multfish.c r:crzmon_5 c:crzmon_5
		DRIVER(crzmon_8a) //t:crzmon_8a f:multfish.c r:crzmon_5 c:crzmon_5
		DRIVER(crzmon_8b) //t:crzmon_8b f:multfish.c r:crzmon_5 c:crzmon_5
		DRIVER(crzmon_8c) //t:crzmon_8c f:multfish.c r:crzmon_5 c:crzmon_5
		DRIVER(crzmon_8d) //t:crzmon_8d f:multfish.c r:crzmon_5 c:crzmon_5
		DRIVER(crzmon_8e) //t:crzmon_8e f:multfish.c r:crzmon_5 c:crzmon_5
		DRIVER(crzmon_8f) //t:crzmon_8f f:multfish.c r:crzmon_5 c:crzmon_5
		DRIVER(crzmon_9a) //t:crzmon_9a f:multfish.c r:crzmon_5 c:crzmon_5
		DRIVER(crzmon_9b) //t:crzmon_9b f:multfish.c r:crzmon_5 c:crzmon_5
		DRIVER(crzmon_9c) //t:crzmon_9c f:multfish.c r:crzmon_5 c:crzmon_5
//SET: fcockt_3
		DRIVER(fcockt_3) //t:fcockt_3 f:multfish.c r: c:
		DRIVER(fcockt_5) //t:fcockt_5 f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_6) //t:fcockt_6 f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_7) //t:fcockt_7 f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_8) //t:fcockt_8 f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_9) //t:fcockt_9 f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_10) //t:fcockt_10 f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_11) //t:fcockt_11 f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_12) //t:fcockt_12 f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_6a) //t:fcockt_6a f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_6b) //t:fcockt_6b f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_6c) //t:fcockt_6c f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_6d) //t:fcockt_6d f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_7a) //t:fcockt_7a f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_7b) //t:fcockt_7b f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_7c) //t:fcockt_7c f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_7d) //t:fcockt_7d f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_7e) //t:fcockt_7e f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_7f) //t:fcockt_7f f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_7g) //t:fcockt_7g f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_7h) //t:fcockt_7h f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_8a) //t:fcockt_8a f:multfish.c r:fcockt_3 c:fcockt_3
		DRIVER(fcockt_8b) //t:fcockt_8b f:multfish.c r:fcockt_3 c:fcockt_3
//SET: lhaunt_2
		DRIVER(lhaunt_2) //t:lhaunt_2 f:multfish.c r: c:
		DRIVER(lhaunt_4) //t:lhaunt_4 f:multfish.c r:lhaunt_2 c:lhaunt_2
		DRIVER(lhaunt_5) //t:lhaunt_5 f:multfish.c r:lhaunt_2 c:lhaunt_2
		DRIVER(lhaunt_6) //t:lhaunt_6 f:multfish.c r:lhaunt_2 c:lhaunt_2
		DRIVER(lhaunt_7) //t:lhaunt_7 f:multfish.c r:lhaunt_2 c:lhaunt_2
		DRIVER(lhaunt_8) //t:lhaunt_8 f:multfish.c r:lhaunt_2 c:lhaunt_2
		DRIVER(lhaunt_4a) //t:lhaunt_4a f:multfish.c r:lhaunt_2 c:lhaunt_2
		DRIVER(lhaunt_5a) //t:lhaunt_5a f:multfish.c r:lhaunt_2 c:lhaunt_2
		DRIVER(lhaunt_6a) //t:lhaunt_6a f:multfish.c r:lhaunt_2 c:lhaunt_2
		DRIVER(lhaunt_6b) //t:lhaunt_6b f:multfish.c r:lhaunt_2 c:lhaunt_2
		DRIVER(lhaunt_6c) //t:lhaunt_6c f:multfish.c r:lhaunt_2 c:lhaunt_2
		DRIVER(lhaunt_6d) //t:lhaunt_6d f:multfish.c r:lhaunt_2 c:lhaunt_2
		DRIVER(lhaunt_6e) //t:lhaunt_6e f:multfish.c r:lhaunt_2 c:lhaunt_2
		DRIVER(lhaunt_6f) //t:lhaunt_6f f:multfish.c r:lhaunt_2 c:lhaunt_2
//SET: rollfr_2
		DRIVER(rollfr_2) //t:rollfr_2 f:multfish.c r: c:
//SET: garage_4
		DRIVER(garage_4) //t:garage_4 f:multfish.c r: c:
		DRIVER(garage_5) //t:garage_5 f:multfish.c r:garage_4 c:garage_4
		DRIVER(garage_6) //t:garage_6 f:multfish.c r:garage_4 c:garage_4
		DRIVER(garage_7) //t:garage_7 f:multfish.c r:garage_4 c:garage_4
		DRIVER(garage_4a) //t:garage_4a f:multfish.c r:garage_4 c:garage_4
		DRIVER(garage_4b) //t:garage_4b f:multfish.c r:garage_4 c:garage_4
		DRIVER(garage_4c) //t:garage_4c f:multfish.c r:garage_4 c:garage_4
		DRIVER(garage_5a) //t:garage_5a f:multfish.c r:garage_4 c:garage_4
		DRIVER(garage_5b) //t:garage_5b f:multfish.c r:garage_4 c:garage_4
		DRIVER(garage_5c) //t:garage_5c f:multfish.c r:garage_4 c:garage_4
		DRIVER(garage_5d) //t:garage_5d f:multfish.c r:garage_4 c:garage_4
		DRIVER(garage_5e) //t:garage_5e f:multfish.c r:garage_4 c:garage_4
//SET: rclimb
		DRIVER(rclimb) //t:rclimb f:multfish.c r: c:
		DRIVER(rclimb_3) //t:rclimb_3 f:multfish.c r:rclimb c:rclimb
		DRIVER(rclimb_4) //t:rclimb_4 f:multfish.c r:rclimb c:rclimb
		DRIVER(rclimb_5) //t:rclimb_5 f:multfish.c r:rclimb c:rclimb
		DRIVER(rclimb_3a) //t:rclimb_3a f:multfish.c r:rclimb c:rclimb
		DRIVER(rclimb_3b) //t:rclimb_3b f:multfish.c r:rclimb c:rclimb
		DRIVER(rclimb_3c) //t:rclimb_3c f:multfish.c r:rclimb c:rclimb
		DRIVER(rclimb_3d) //t:rclimb_3d f:multfish.c r:rclimb c:rclimb
		DRIVER(rclimb_3e) //t:rclimb_3e f:multfish.c r:rclimb c:rclimb
//SET: sweetl
		DRIVER(sweetl) //t:sweetl f:multfish.c r: c:
		DRIVER(sweetl_2) //t:sweetl_2 f:multfish.c r:sweetl c:sweetl
		DRIVER(sweetla) //t:sweetla f:multfish.c r:sweetl c:sweetl
		DRIVER(sweetlb) //t:sweetlb f:multfish.c r:sweetl c:sweetl
//SET: resdnt
		DRIVER(resdnt) //t:resdnt f:multfish.c r: c:
		DRIVER(resdnt_2) //t:resdnt_2 f:multfish.c r:resdnt c:resdnt
		DRIVER(resdnt_3) //t:resdnt_3 f:multfish.c r:resdnt c:resdnt
		DRIVER(resdnt_2a) //t:resdnt_2a f:multfish.c r:resdnt c:resdnt
		DRIVER(resdnt_2b) //t:resdnt_2b f:multfish.c r:resdnt c:resdnt
		DRIVER(resdnt_2c) //t:resdnt_2c f:multfish.c r:resdnt c:resdnt
		DRIVER(resdnt_2d) //t:resdnt_2d f:multfish.c r:resdnt c:resdnt
		DRIVER(resdnt_2e) //t:resdnt_2e f:multfish.c r:resdnt c:resdnt
		DRIVER(resdnt_2f) //t:resdnt_2f f:multfish.c r:resdnt c:resdnt
		DRIVER(resdnt_2g) //t:resdnt_2g f:multfish.c r:resdnt c:resdnt
//SET: island
		DRIVER(island) //t:island f:multfish.c r: c:
		DRIVER(island_2) //t:island_2 f:multfish.c r:island c:island
		DRIVER(islanda) //t:islanda f:multfish.c r:island c:island
		DRIVER(islandb) //t:islandb f:multfish.c r:island c:island
		DRIVER(islandc) //t:islandc f:multfish.c r:island c:island
//SET: pirate_2
		DRIVER(pirate_2) //t:pirate_2 f:multfish.c r: c:
		DRIVER(pirate_3) //t:pirate_3 f:multfish.c r:pirate_2 c:pirate_2
		DRIVER(pirate_4) //t:pirate_4 f:multfish.c r:pirate_2 c:pirate_2
//SET: island2
		DRIVER(island2) //t:island2 f:multfish.c r: c:
		DRIVER(island2_3) //t:island2_3 f:multfish.c r:island2 c:island2
		DRIVER(island2_4) //t:island2_4 f:multfish.c r:island2 c:island2
		DRIVER(island2a) //t:island2a f:multfish.c r:island2 c:island2
		DRIVER(island2b) //t:island2b f:multfish.c r:island2 c:island2
		DRIVER(island2c) //t:island2c f:multfish.c r:island2 c:island2
		DRIVER(island2_3a) //t:island2_3a f:multfish.c r:island2 c:island2
		DRIVER(island2_4a) //t:island2_4a f:multfish.c r:island2 c:island2
//SET: pirate2
		DRIVER(pirate2) //t:pirate2 f:multfish.c r: c:
		DRIVER(pirate2_2) //t:pirate2_2 f:multfish.c r:pirate2 c:pirate2
		DRIVER(pirate2a) //t:pirate2a f:multfish.c r:pirate2 c:pirate2
		DRIVER(pirate2b) //t:pirate2b f:multfish.c r:pirate2 c:pirate2
		DRIVER(pirate2c) //t:pirate2c f:multfish.c r:pirate2 c:pirate2
		DRIVER(pirate2d) //t:pirate2d f:multfish.c r:pirate2 c:pirate2
		DRIVER(pirate2e) //t:pirate2e f:multfish.c r:pirate2 c:pirate2
		DRIVER(pirate2f) //t:pirate2f f:multfish.c r:pirate2 c:pirate2
		DRIVER(pirate2g) //t:pirate2g f:multfish.c r:pirate2 c:pirate2
		DRIVER(pirate2h) //t:pirate2h f:multfish.c r:pirate2 c:pirate2
		DRIVER(pirate2_2a) //t:pirate2_2a f:multfish.c r:pirate2 c:pirate2
//SET: keks
		DRIVER(keks) //t:keks f:multfish.c r: c:
		DRIVER(keks_2) //t:keks_2 f:multfish.c r:keks c:keks
		DRIVER(keks_3) //t:keks_3 f:multfish.c r:keks c:keks
		DRIVER(keksa) //t:keksa f:multfish.c r:keks c:keks
		DRIVER(keksb) //t:keksb f:multfish.c r:keks c:keks
		DRIVER(keksc) //t:keksc f:multfish.c r:keks c:keks
		DRIVER(keks_2a) //t:keks_2a f:multfish.c r:keks c:keks
		DRIVER(keks_2b) //t:keks_2b f:multfish.c r:keks c:keks
		DRIVER(keks_2c) //t:keks_2c f:multfish.c r:keks c:keks
		DRIVER(keks_2d) //t:keks_2d f:multfish.c r:keks c:keks
		DRIVER(keks_2e) //t:keks_2e f:multfish.c r:keks c:keks
		DRIVER(keks_2f) //t:keks_2f f:multfish.c r:keks c:keks
		DRIVER(keks_2g) //t:keks_2g f:multfish.c r:keks c:keks
		DRIVER(keks_3a) //t:keks_3a f:multfish.c r:keks c:keks
		DRIVER(keks_3b) //t:keks_3b f:multfish.c r:keks c:keks
//SET: gnome
		DRIVER(gnome) //t:gnome f:multfish.c r: c:
		DRIVER(gnome_2) //t:gnome_2 f:multfish.c r:gnome c:gnome
		DRIVER(gnomea) //t:gnomea f:multfish.c r:gnome c:gnome
		DRIVER(gnomeb) //t:gnomeb f:multfish.c r:gnome c:gnome
		DRIVER(gnomec) //t:gnomec f:multfish.c r:gnome c:gnome
		DRIVER(gnomed) //t:gnomed f:multfish.c r:gnome c:gnome
		DRIVER(gnomee) //t:gnomee f:multfish.c r:gnome c:gnome
		DRIVER(gnome_2a) //t:gnome_2a f:multfish.c r:gnome c:gnome
//SET: sweetl2
		DRIVER(sweetl2) //t:sweetl2 f:multfish.c r: c:
//SET: cdimono1
		DRIVER(cdimono1) //t:cdimono1 f:cdi.c r: c:
//SET: quizard
		DRIVER(quizard) //t:quizard f:cdi.c r:cdimono1 c:
//SET: quizrd22
		DRIVER(quizrd22) //t:quizrd22 f:cdi.c r:cdimono1 c:
//SET: quizrd17
		DRIVER(quizrd17) //t:quizrd17 f:cdi.c r:cdimono1 c:
//SET: quizrd12
		DRIVER(quizrd12) //t:quizrd12 f:cdi.c r:cdimono1 c:
//SET: quizrr42
		DRIVER(quizrr42) //t:quizrr42 f:cdi.c r:cdimono1 c:
//SET: quizrr41
		DRIVER(quizrr41) //t:quizrr41 f:cdi.c r:cdimono1 c:
//SET: m_brkfst
		DRIVER(m_brkfst) //t:m_brkfst f:bfm_sc2.c r: c:
		DRIVER(m_brkfs1) //t:m_brkfs1 f:bfm_sc2.c r:m_brkfst c:m_brkfst
		DRIVER(m_brkfs2) //t:m_brkfs2 f:bfm_sc2.c r:m_brkfst c:m_brkfst
		DRIVER(m_brkfs3) //t:m_brkfs3 f:bfm_sc2.c r:m_brkfst c:m_brkfst
		DRIVER(m_brkfs4) //t:m_brkfs4 f:bfm_sc2.c r:m_brkfst c:m_brkfst
		DRIVER(m_brkfs5) //t:m_brkfs5 f:bfm_sc2.c r:m_brkfst c:m_brkfst
//SET: m_bdrwho
		DRIVER(m_bdrwho) //t:m_bdrwho f:bfm_sc2.c r: c:
		DRIVER(m_bdrwh1) //t:m_bdrwh1 f:bfm_sc2.c r:m_bdrwho c:m_bdrwho
		DRIVER(m_bdrwh2) //t:m_bdrwh2 f:bfm_sc2.c r:m_bdrwho c:m_bdrwho
		DRIVER(m_bdrwh3) //t:m_bdrwh3 f:bfm_sc2.c r:m_bdrwho c:m_bdrwho
		DRIVER(m_bdrwh4) //t:m_bdrwh4 f:bfm_sc2.c r:m_bdrwho c:m_bdrwho
		DRIVER(m_bdrwh5) //t:m_bdrwh5 f:bfm_sc2.c r:m_bdrwho c:m_bdrwho
		DRIVER(m_bdrwh6) //t:m_bdrwh6 f:bfm_sc2.c r:m_bdrwho c:m_bdrwho
		DRIVER(m_bdrwh7) //t:m_bdrwh7 f:bfm_sc2.c r:m_bdrwho c:m_bdrwho
		DRIVER(m_bdrwh8) //t:m_bdrwh8 f:bfm_sc2.c r:m_bdrwho c:m_bdrwho
		DRIVER(m_bdrwh9) //t:m_bdrwh9 f:bfm_sc2.c r:m_bdrwho c:m_bdrwho
		DRIVER(m_bdrw10) //t:m_bdrw10 f:bfm_sc2.c r:m_bdrwho c:m_bdrwho
		DRIVER(m_bdrw11) //t:m_bdrw11 f:bfm_sc2.c r:m_bdrwho c:m_bdrwho
		DRIVER(m_bdrw12) //t:m_bdrw12 f:bfm_sc2.c r:m_bdrwho c:m_bdrwho
		DRIVER(m_bdrw13) //t:m_bdrw13 f:bfm_sc2.c r:m_bdrwho c:m_bdrwho
		DRIVER(m_bdrw14) //t:m_bdrw14 f:bfm_sc2.c r:m_bdrwho c:m_bdrwho
		DRIVER(m_bdrw15) //t:m_bdrw15 f:bfm_sc2.c r:m_bdrwho c:m_bdrwho
		DRIVER(m_bdrw16) //t:m_bdrw16 f:bfm_sc2.c r:m_bdrwho c:m_bdrwho
		DRIVER(m_bdrw17) //t:m_bdrw17 f:bfm_sc2.c r:m_bdrwho c:m_bdrwho
//SET: m_bfocus
		DRIVER(m_bfocus) //t:m_bfocus f:bfm_sc2.c r: c:
//SET: m_bcgslm
		DRIVER(m_bcgslm) //t:m_bcgslm f:bfm_sc2.c r: c:
//SET: m_luvjub
		DRIVER(m_luvjub) //t:m_luvjub f:bfm_sc2.c r: c:
//SET: m_cpeno1
		DRIVER(m_cpeno1) //t:m_cpeno1 f:bfm_sc2.c r: c:
//SET: m_supcrd
		DRIVER(m_supcrd) //t:m_supcrd f:bfmsys85.c r: c:
//SET: m_tbirds
		DRIVER(m_tbirds) //t:m_tbirds f:jpmimpct.c r: c:
//SET: m_lotsse
		DRIVER(m_lotsse) //t:m_lotsse f:bfm_sc1.c r: c:
//SET: m_roulet
		DRIVER(m_roulet) //t:m_roulet f:bfm_sc1.c r: c:
//SET: m_clattr
		DRIVER(m_clattr) //t:m_clattr f:bfm_sc1.c r: c:
//SET: m_tppokr
		DRIVER(m_tppokr) //t:m_tppokr f:bfm_sc1.c r: c:
//SET: m_sptlgt
		DRIVER(m_sptlgt) //t:m_sptlgt f:maygay1b.c r: c:
//SET: screenpl
		DRIVER(screenpl) //t:screenpl f:maygayv1.c r: c:
		DRIVER(screenp1) //t:screenp1 f:maygayv1.c r:screenpl c:screenpl
		DRIVER(screenp2) //t:screenp2 f:maygayv1.c r:screenpl c:screenpl
//SET: m_oldtmr
		DRIVER(m_oldtmr) //t:m_oldtmr f:mpu4.c r: c:
//SET: m_ccelbr
		DRIVER(m_ccelbr) //t:m_ccelbr f:mpu4.c r: c:
//SET: m_gmball
		DRIVER(m_gmball) //t:m_gmball f:mpu4.c r: c:
//SET: m_grtecp
		DRIVER(m_grtecp) //t:m_grtecp f:mpu4.c r: c:
//SET: m_blsbys
		DRIVER(m_blsbys) //t:m_blsbys f:mpu4.c r: c:
//SET: m_honmon
		DRIVER(m_honmon) //t:m_honmon f:mpu5.c r: c:
//SET: roul
		DRIVER(roul) //t:roul f:roul.c r: c:
//SET: hitpoker
		DRIVER(hitpoker) //t:hitpoker f:hitpoker.c r: c:
//SET: vpoker
		DRIVER(vpoker) //t:vpoker f:vpoker.c r: c:
//SET: 5acespkr
		DRIVER(5acespkr) //t:5acespkr f:vpoker.c r: c:
//SET: jnero
		DRIVER(jnero) //t:jnero f:vp101.c r: c:
//SET: am_uslot
		DRIVER(am_uslot) //t:am_uslot f:amaticmg.c r: c:
//SET: am_mg24
		DRIVER(am_mg24) //t:am_mg24 f:amaticmg.c r: c:
//SET: am_mg3
		DRIVER(am_mg3) //t:am_mg3 f:amaticmg.c r: c:
//SET: neptunp2
		DRIVER(neptunp2) //t:neptunp2 f:neptunp2.c r: c:
//SET: rgum
		DRIVER(rgum) //t:rgum f:rgum.c r: c:
//SET: poker72
		DRIVER(poker72) //t:poker72 f:poker72.c r: c:
//SET: chkun
		DRIVER(chkun) //t:chkun f:timeplt.c r: c:
//SET: megadpkr
		DRIVER(megadpkr) //t:megadpkr f:blitz.c r: c:
		DRIVER(megadpkrb) //t:megadpkrb f:blitz.c r:megadpkr c:megadpkr
//SET: megadblj
		DRIVER(megadblj) //t:megadblj f:blitz68k.c r: c:
//SET: megadble
		DRIVER(megadble) //t:megadble f:blitz68k.c r: c:
//SET: maxidbl
		DRIVER(maxidbl) //t:maxidbl f:blitz68k.c r: c:
//SET: bankrob
		DRIVER(bankrob) //t:bankrob f:blitz68k.c r: c:
		DRIVER(bankroba) //t:bankroba f:blitz68k.c r:bankrob c:bankrob
//SET: poker52
		DRIVER(poker52) //t:poker52 f:blitz68k.c r: c:
//SET: steaser
		DRIVER(steaser) //t:steaser f:blitz68k.c r: c:
//SET: dualgame
		DRIVER(dualgame) //t:dualgame f:blitz68k.c r: c:
//SET: hermit
		DRIVER(hermit) //t:hermit f:blitz68k.c r: c:
//SET: deucesw2
		DRIVER(deucesw2) //t:deucesw2 f:blitz68k.c r: c:
//SET: cjffruit
		DRIVER(cjffruit) //t:cjffruit f:blitz68k.c r: c:
//SET: ilpag
		DRIVER(ilpag) //t:ilpag f:blitz68k.c r: c:
//SET: hotstuff
		DRIVER(hotstuff) //t:hotstuff f:hotstuff.c r: c:
//SET: savquest
		DRIVER(savquest) //t:savquest f:savquest.c r: c:
//SET: xtom3d
		DRIVER(xtom3d) //t:xtom3d f:xtom3d.c r: c:
//SET: jubileep
		DRIVER(jubileep) //t:jubileep f:jubilee.c r: c:
//SET: swisspkr
		DRIVER(swisspkr) //t:swisspkr f:goldngam.c r: c:
//SET: moviecrd
		DRIVER(moviecrd) //t:moviecrd f:goldngam.c r: c:
//SET: nsmpoker
		DRIVER(nsmpoker) //t:nsmpoker f:nsmpoker.c r: c:
//SET: avtsym14
		DRIVER(avtsym14) //t:avtsym14 f:avt.c r: c:
		DRIVER(avtsym25) //t:avtsym25 f:avt.c r:avtsym14 c:avtsym14
//SET: avtbingo
		DRIVER(avtbingo) //t:avtbingo f:avt.c r: c:
//SET: avtnfl
		DRIVER(avtnfl) //t:avtnfl f:avt.c r: c:
//SET: winner82
		DRIVER(winner82) //t:winner82 f:corona.c r: c:
		DRIVER(winner81) //t:winner81 f:corona.c r:winner82 c:winner82
		DRIVER(winner81b) //t:winner81b f:corona.c r:winner82 c:winner82
//SET: re800v1
		DRIVER(re800v1) //t:re800v1 f:corona.c r: c:
		DRIVER(re800ea) //t:re800ea f:corona.c r:re800v1 c:re800v1
//SET: re800v3
		DRIVER(re800v3) //t:re800v3 f:corona.c r: c:
#endif

#ifdef PS3_SET_14
//SET: rcirulet
		DRIVER(rcirulet) //t:rcirulet f:corona.c r: c:
//SET: luckyrlt
		DRIVER(luckyrlt) //t:luckyrlt f:corona.c r: c:
//SET: dfruit
		DRIVER(dfruit) //t:dfruit f:dfruit.c r: c:
//SET: allied
		DRIVER(allied) //t:allied f:allied.c r: c:
//SET: suprpick
		DRIVER(suprpick) //t:suprpick f:allied.c r:allied c:
//SET: royclark
		DRIVER(royclark) //t:royclark f:allied.c r:allied c:
//SET: thndbolt
		DRIVER(thndbolt) //t:thndbolt f:allied.c r:allied c:
//SET: hoedown
		DRIVER(hoedown) //t:hoedown f:allied.c r:allied c:
//SET: takefive
		DRIVER(takefive) //t:takefive f:allied.c r:allied c:
//SET: heartspd
		DRIVER(heartspd) //t:heartspd f:allied.c r:allied c:
//SET: foathens
		DRIVER(foathens) //t:foathens f:allied.c r:allied c:
//SET: disco79
		DRIVER(disco79) //t:disco79 f:allied.c r:allied c:
//SET: erosone
		DRIVER(erosone) //t:erosone f:allied.c r:allied c:
//SET: circa33
		DRIVER(circa33) //t:circa33 f:allied.c r:allied c:
//SET: starshot
		DRIVER(starshot) //t:starshot f:allied.c r:allied c:
//SET: agsoccer
		DRIVER(agsoccer) //t:agsoccer f:alvg.c r: c:
//SET: wrldtour
		DRIVER(wrldtour) //t:wrldtour f:alvg.c r: c:
		DRIVER(wrldtour2) //t:wrldtour2 f:alvg.c r:wrldtour c:wrldtour
//SET: usafootb
		DRIVER(usafootb) //t:usafootb f:alvg.c r: c:
//SET: mystcast
		DRIVER(mystcast) //t:mystcast f:alvg.c r: c:
//SET: pstlpkr
		DRIVER(pstlpkr) //t:pstlpkr f:alvg.c r: c:
//SET: punchy
		DRIVER(punchy) //t:punchy f:alvg.c r: c:
//SET: dinoeggs
		DRIVER(dinoeggs) //t:dinoeggs f:alvg.c r: c:
//SET: atarians
		DRIVER(atarians) //t:atarians f:atari_s1.c r: c:
//SET: time2000
		DRIVER(time2000) //t:time2000 f:atari_s1.c r: c:
//SET: aavenger
		DRIVER(aavenger) //t:aavenger f:atari_s1.c r: c:
//SET: midearth
		DRIVER(midearth) //t:midearth f:atari_s1.c r: c:
//SET: spcrider
		DRIVER(spcrider) //t:spcrider f:atari_s1.c r: c:
//SET: supermap
		DRIVER(supermap) //t:supermap f:atari_s2.c r: c:
//SET: hercules
		DRIVER(hercules) //t:hercules f:atari_s2.c r: c:
//SET: roadrunr
		DRIVER(roadrunr) //t:roadrunr f:atari_s3.c r: c:
//SET: cntinntl
		DRIVER(cntinntl) //t:cntinntl f:bingo.c r: c:
//SET: goldgame
		DRIVER(goldgame) //t:goldgame f:bingo.c r: c:
		DRIVER(goldgam2) //t:goldgam2 f:bingo.c r:goldgame c:goldgame
//SET: blackjck
		DRIVER(blackjck) //t:blackjck f:by17.c r: c:
//SET: bowarrow
		DRIVER(bowarrow) //t:bowarrow f:by17.c r: c:
//SET: eightbll
		DRIVER(eightbll) //t:eightbll f:by17.c r: c:
//SET: evelknie
		DRIVER(evelknie) //t:evelknie f:by17.c r: c:
//SET: freedom
		DRIVER(freedom) //t:freedom f:by17.c r: c:
//SET: matahari
		DRIVER(matahari) //t:matahari f:by17.c r: c:
//SET: nightrdr
		DRIVER(nightrdr) //t:nightrdr f:by17.c r: c:
		DRIVER(nightr20) //t:nightr20 f:by17.c r:nightrdr c:nightrdr
//SET: pwerplay
		DRIVER(pwerplay) //t:pwerplay f:by17.c r: c:
//SET: stk_sprs
		DRIVER(stk_sprs) //t:stk_sprs f:by17.c r: c:
//SET: bullseye
		DRIVER(bullseye) //t:bullseye f:by35.c r: c:
//SET: blakpyra
		DRIVER(blakpyra) //t:blakpyra f:by35.c r: c:
		DRIVER(newwave) //t:newwave f:by35.c r:blakpyra c:blakpyra
//SET: bmx
		DRIVER(bmx) //t:bmx f:by35.c r: c:
//SET: centaur
		DRIVER(centaur) //t:centaur f:by35.c r: c:
//SET: cybrnaut
		DRIVER(cybrnaut) //t:cybrnaut f:by35.c r: c:
		DRIVER(spacehaw) //t:spacehaw f:by35.c r:cybrnaut c:cybrnaut
//SET: dollyptn
		DRIVER(dollyptn) //t:dollyptn f:by35.c r: c:
//SET: eballdlx
		DRIVER(eballdlx) //t:eballdlx f:by35.c r: c:
		DRIVER(eballd14) //t:eballd14 f:by35.c r:eballdlx c:eballdlx
		DRIVER(eballdlxp1) //t:eballdlxp1 f:by68701.c r:eballdlx c:eballdlx
		DRIVER(eballdlxp2) //t:eballdlxp2 f:by68701.c r:eballdlx c:eballdlx
		DRIVER(eballdlxp3) //t:eballdlxp3 f:by68701.c r:eballdlx c:eballdlx
		DRIVER(eballdlxp4) //t:eballdlxp4 f:by68701.c r:eballdlx c:eballdlx
//SET: elektra
		DRIVER(elektra) //t:elektra f:by35.c r: c:
//SET: embryon
		DRIVER(embryon) //t:embryon f:by35.c r: c:
//SET: fathom
		DRIVER(fathom) //t:fathom f:by35.c r: c:
//SET: fbclass
		DRIVER(fbclass) //t:fbclass f:by35.c r: c:
//SET: fball_ii
		DRIVER(fball_ii) //t:fball_ii f:by35.c r: c:
//SET: flashgdn
		DRIVER(flashgdn) //t:flashgdn f:by35.c r: c:
		DRIVER(cosflash) //t:cosflash f:by35.c r:flashgdn c:flashgdn
		DRIVER(flashgdnf) //t:flashgdnf f:by35.c r:flashgdn c:flashgdn
		DRIVER(flashgdnv) //t:flashgdnv f:by35.c r:flashgdn c:flashgdn
		DRIVER(flashgdnp1) //t:flashgdnp1 f:by68701.c r:flashgdn c:flashgdn
		DRIVER(flashgdnp2) //t:flashgdnp2 f:by68701.c r:flashgdn c:flashgdn
//SET: frontier
		DRIVER(frontier) //t:frontier f:by35.c r: c:
//SET: futurspa
		DRIVER(futurspa) //t:futurspa f:by35.c r: c:
//SET: goldball
		DRIVER(goldball) //t:goldball f:by35.c r: c:
		DRIVER(goldballn) //t:goldballn f:by35.c r:goldball c:goldball
//SET: granslam
		DRIVER(granslam) //t:granslam f:by35.c r: c:
		DRIVER(granslam4) //t:granslam4 f:by35.c r:granslam c:granslam
//SET: hglbtrtr
		DRIVER(hglbtrtr) //t:hglbtrtr f:by35.c r: c:
//SET: hotdoggn
		DRIVER(hotdoggn) //t:hotdoggn f:by35.c r: c:
//SET: kosteel
		DRIVER(kosteel) //t:kosteel f:by35.c r: c:
		DRIVER(tigerrag) //t:tigerrag f:by35.c r:kosteel c:kosteel
//SET: kiss
		DRIVER(kiss) //t:kiss f:by35.c r: c:
		DRIVER(kissp) //t:kissp f:kissproto.c r:kiss c:kiss
//SET: lostwrlp
		DRIVER(lostwrlp) //t:lostwrlp f:by35.c r: c:
//SET: medusa
		DRIVER(medusa) //t:medusa f:by35.c r: c:
//SET: m_mpac
		DRIVER(m_mpac) //t:m_mpac f:by35.c r: c:
//SET: mystic
		DRIVER(mystic) //t:mystic f:by35.c r: c:
//SET: myststar
		DRIVER(myststar) //t:myststar f:by35.c r: c:
//SET: ngndshkr
		DRIVER(ngndshkr) //t:ngndshkr f:by35.c r: c:
//SET: paragon
		DRIVER(paragon) //t:paragon f:by35.c r: c:
//SET: playboy
		DRIVER(playboy) //t:playboy f:by35.c r: c:
//SET: rapidfip
		DRIVER(rapidfip) //t:rapidfip f:by35.c r: c:
//SET: rollston
		DRIVER(rollston) //t:rollston f:by35.c r: c:
//SET: slbmania
		DRIVER(slbmania) //t:slbmania f:by35.c r: c:
//SET: skatebll
		DRIVER(skatebll) //t:skatebll f:by35.c r: c:
//SET: spaceinv
		DRIVER(spaceinv) //t:spaceinv f:by35.c r: c:
//SET: speakesy
		DRIVER(speakesy) //t:speakesy f:by35.c r: c:
		DRIVER(speakesy4p) //t:speakesy4p f:by35.c r:speakesy c:speakesy
//SET: spectrm
		DRIVER(spectrm) //t:spectrm f:by35.c r: c:
		DRIVER(spectrm4) //t:spectrm4 f:by35.c r:spectrm c:spectrm
//SET: spyhuntr
		DRIVER(spyhuntr) //t:spyhuntr f:by35.c r: c:
		DRIVER(saturn2) //t:saturn2 f:by35.c r:spyhuntr c:spyhuntr
//SET: startrep
		DRIVER(startrep) //t:startrep f:by35.c r: c:
//SET: sst
		DRIVER(sst) //t:sst f:by35.c r: c:
//SET: smman
		DRIVER(smman) //t:smman f:by35.c r: c:
//SET: vector
		DRIVER(vector) //t:vector f:by35.c r: c:
//SET: viking
		DRIVER(viking) //t:viking f:by35.c r: c:
//SET: voltan
		DRIVER(voltan) //t:voltan f:by35.c r: c:
//SET: xsandos
		DRIVER(xsandos) //t:xsandos f:by35.c r: c:
		DRIVER(suprbowl) //t:suprbowl f:by35.c r:xsandos c:xsandos
//SET: xenon
		DRIVER(xenon) //t:xenon f:by35.c r: c:
		DRIVER(xenonf) //t:xenonf f:by35.c r:xenon c:xenon
//SET: worlddef
		DRIVER(worlddef) //t:worlddef f:by35.c r: c:
//SET: darkshad
		DRIVER(darkshad) //t:darkshad f:by35.c r: c:
//SET: skflight
		DRIVER(skflight) //t:skflight f:by35.c r: c:
//SET: cobrap
		DRIVER(cobrap) //t:cobrap f:by35.c r: c:
//SET: futrquen
		DRIVER(futrquen) //t:futrquen f:by35.c r: c:
//SET: f1gpp
		DRIVER(f1gpp) //t:f1gpp f:by35.c r: c:
//SET: toppin
		DRIVER(toppin) //t:toppin f:by35.c r: c:
//SET: uboat65
		DRIVER(uboat65) //t:uboat65 f:by35.c r: c:
//SET: bbbowlin
		DRIVER(bbbowlin) //t:bbbowlin f:by35.c r: c:
//SET: monrobwl
		DRIVER(monrobwl) //t:monrobwl f:by35.c r: c:
//SET: mdntmrdr
		DRIVER(mdntmrdr) //t:mdntmrdr f:by35.c r: c:
//SET: blbeauty
		DRIVER(blbeauty) //t:blbeauty f:by35.c r: c:
//SET: atlantip
		DRIVER(atlantip) //t:atlantip f:by6803.c r: c:
//SET: beatclck
		DRIVER(beatclck) //t:beatclck f:by6803.c r: c:
//SET: blackblt
		DRIVER(blackblt) //t:blackblt f:by6803.c r: c:
//SET: black100
		DRIVER(black100) //t:black100 f:by6803.c r: c:
		DRIVER(black100s) //t:black100s f:by6803.c r:black100 c:black100
//SET: cityslck
		DRIVER(cityslck) //t:cityslck f:by6803.c r: c:
//SET: dungdrag
		DRIVER(dungdrag) //t:dungdrag f:by6803.c r: c:
//SET: eballchp
		DRIVER(eballchp) //t:eballchp f:by6803.c r: c:
//SET: esclwrld
		DRIVER(esclwrld) //t:esclwrld f:by6803.c r: c:
		DRIVER(esclwrldg) //t:esclwrldg f:by6803.c r:esclwrld c:esclwrld
//SET: hardbody
		DRIVER(hardbody) //t:hardbody f:by6803.c r: c:
		DRIVER(hardbodyg) //t:hardbodyg f:by6803.c r:hardbody c:hardbody
//SET: hvymetap
		DRIVER(hvymetap) //t:hvymetap f:by6803.c r: c:
//SET: ladyluck
		DRIVER(ladyluck) //t:ladyluck f:by6803.c r: c:
//SET: motrdome
		DRIVER(motrdome) //t:motrdome f:by6803.c r: c:
//SET: prtyanim
		DRIVER(prtyanim) //t:prtyanim f:by6803.c r: c:
//SET: specforc
		DRIVER(specforc) //t:specforc f:by6803.c r: c:
//SET: strngsci
		DRIVER(strngsci) //t:strngsci f:by6803.c r: c:
//SET: trucksp3
		DRIVER(trucksp3) //t:trucksp3 f:by6803.c r: c:
		DRIVER(trucksp2) //t:trucksp2 f:by6803.c r:trucksp3 c:trucksp3
//SET: babypac
		DRIVER(babypac) //t:babypac f:byvid.c r: c:
//SET: granny
		DRIVER(granny) //t:granny f:byvid.c r: c:
//SET: abv106
		DRIVER(abv106) //t:abv106 f:capcom.c r: c:
		DRIVER(abv106r) //t:abv106r f:capcom.c r:abv106 c:abv106
//SET: bbb109
		DRIVER(bbb109) //t:bbb109 f:capcom.c r: c:
		DRIVER(bbb108) //t:bbb108 f:capcom.c r:bbb109 c:bbb109
//SET: bsv103
		DRIVER(bsv103) //t:bsv103 f:capcom.c r: c:
		DRIVER(bsv100r) //t:bsv100r f:capcom.c r:bsv103 c:bsv103
		DRIVER(bsv102r) //t:bsv102r f:capcom.c r:bsv103 c:bsv103
		DRIVER(bsb105) //t:bsb105 f:capcom.c r:bsv103 c:bsv103
//SET: ffv104
		DRIVER(ffv104) //t:ffv104 f:capcom.c r: c:
		DRIVER(ffv101) //t:ffv101 f:capcom.c r:ffv104 c:ffv104
//SET: kpv106
		DRIVER(kpv106) //t:kpv106 f:capcom.c r: c:
//SET: pmv112
		DRIVER(pmv112) //t:pmv112 f:capcom.c r: c:
		DRIVER(pmv112r) //t:pmv112r f:capcom.c r:pmv112 c:pmv112
//SET: ghv101
		DRIVER(ghv101) //t:ghv101 f:capcom.c r: c:
//SET: lwar_a83
		DRIVER(lwar_a83) //t:lwar_a83 f:de_1.c r: c:
		DRIVER(lwar_e90) //t:lwar_e90 f:de_1.c r:lwar_a83 c:lwar_a83
//SET: mnfb_c27
		DRIVER(mnfb_c27) //t:mnfb_c27 f:de_2.c r: c:
//SET: poto_a32
		DRIVER(poto_a32) //t:poto_a32 f:de_2.c r: c:
//SET: play_a24
		DRIVER(play_a24) //t:play_a24 f:de_2.c r: c:
//SET: robo_a34
		DRIVER(robo_a34) //t:robo_a34 f:de_2.c r: c:
//SET: ssvc_a26
		DRIVER(ssvc_a26) //t:ssvc_a26 f:de_2.c r: c:
//SET: tmac_a24
		DRIVER(tmac_a24) //t:tmac_a24 f:de_2.c r: c:
		DRIVER(tmac_a18) //t:tmac_a18 f:de_2.c r:tmac_a24 c:tmac_a24
//SET: torp_e21
		DRIVER(torp_e21) //t:torp_e21 f:de_2.c r: c:
//SET: rab_320
		DRIVER(rab_320) //t:rab_320 f:de_3.c r: c:
		DRIVER(rab_130) //t:rab_130 f:de_3.c r:rab_320 c:rab_320
		DRIVER(rab_103) //t:rab_103 f:de_3.c r:rab_320 c:rab_320
//SET: aar_101
		DRIVER(aar_101) //t:aar_101 f:de_3.c r: c:
//SET: bttf_a27
		DRIVER(bttf_a27) //t:bttf_a27 f:de_3.c r: c:
		DRIVER(bttf_a20) //t:bttf_a20 f:de_3.c r:bttf_a27 c:bttf_a27
		DRIVER(bttf_a21) //t:bttf_a21 f:de_3.c r:bttf_a27 c:bttf_a27
		DRIVER(bttf_g27) //t:bttf_g27 f:de_3.c r:bttf_a27 c:bttf_a27
//SET: btmn_103
		DRIVER(btmn_103) //t:btmn_103 f:de_3.c r: c:
		DRIVER(btmn_101) //t:btmn_101 f:de_3.c r:btmn_103 c:btmn_103
		DRIVER(btmn_g13) //t:btmn_g13 f:de_3.c r:btmn_103 c:btmn_103
		DRIVER(btmn_106) //t:btmn_106 f:de_3.c r:btmn_103 c:btmn_103
//SET: ckpt_a17
		DRIVER(ckpt_a17) //t:ckpt_a17 f:de_3.c r: c:
//SET: gnr_300
		DRIVER(gnr_300) //t:gnr_300 f:de_3.c r: c:
//SET: hook_408
		DRIVER(hook_408) //t:hook_408 f:de_3.c r: c:
		DRIVER(hook_401) //t:hook_401 f:de_3.c r:hook_408 c:hook_408
		DRIVER(hook_404) //t:hook_404 f:de_3.c r:hook_408 c:hook_408
//SET: jupk_513
		DRIVER(jupk_513) //t:jupk_513 f:de_3.c r: c:
		DRIVER(jupk_501) //t:jupk_501 f:de_3.c r:jupk_513 c:jupk_513
		DRIVER(jupk_g51) //t:jupk_g51 f:de_3.c r:jupk_513 c:jupk_513
//SET: lah_112
		DRIVER(lah_112) //t:lah_112 f:de_3.c r: c:
		DRIVER(lah_l104) //t:lah_l104 f:de_3.c r:lah_112 c:lah_112
		DRIVER(lah_l108) //t:lah_l108 f:de_3.c r:lah_112 c:lah_112
		DRIVER(lah_110) //t:lah_110 f:de_3.c r:lah_112 c:lah_112
//SET: lw3_208
		DRIVER(lw3_208) //t:lw3_208 f:de_3.c r: c:
		DRIVER(lw3_207) //t:lw3_207 f:de_3.c r:lw3_208 c:lw3_208
		DRIVER(lw3_205) //t:lw3_205 f:de_3.c r:lw3_208 c:lw3_208
		DRIVER(lw3_200) //t:lw3_200 f:de_3.c r:lw3_208 c:lw3_208
//SET: trek_201
		DRIVER(trek_201) //t:trek_201 f:de_3.c r: c:
		DRIVER(trek_200) //t:trek_200 f:de_3.c r:trek_201 c:trek_201
		DRIVER(trek_120) //t:trek_120 f:de_3.c r:trek_201 c:trek_201
		DRIVER(trek_110) //t:trek_110 f:de_3.c r:trek_201 c:trek_201
		DRIVER(trek_11a) //t:trek_11a f:de_3.c r:trek_201 c:trek_201
//SET: stwr_103
		DRIVER(stwr_103) //t:stwr_103 f:de_3.c r: c:
		DRIVER(stwr_g11) //t:stwr_g11 f:de_3.c r:stwr_103 c:stwr_103
		DRIVER(stwr_a14) //t:stwr_a14 f:de_3.c r:stwr_103 c:stwr_103
		DRIVER(stwr_102) //t:stwr_102 f:de_3.c r:stwr_103 c:stwr_103
		DRIVER(stwr_e12) //t:stwr_e12 f:de_3.c r:stwr_103 c:stwr_103
//SET: tftc_303
		DRIVER(tftc_303) //t:tftc_303 f:de_3.c r: c:
		DRIVER(tftc_300) //t:tftc_300 f:de_3.c r:tftc_303 c:tftc_303
		DRIVER(tftc_200) //t:tftc_200 f:de_3.c r:tftc_303 c:tftc_303
		DRIVER(tftc_104) //t:tftc_104 f:de_3.c r:tftc_303 c:tftc_303
//SET: tmnt_104
		DRIVER(tmnt_104) //t:tmnt_104 f:de_3.c r: c:
		DRIVER(tmnt_103) //t:tmnt_103 f:de_3.c r:tmnt_104 c:tmnt_104
//SET: simp_a27
		DRIVER(simp_a27) //t:simp_a27 f:de_3.c r: c:
		DRIVER(simp_a20) //t:simp_a20 f:de_3.c r:simp_a27 c:simp_a27
//SET: tomy_400
		DRIVER(tomy_400) //t:tomy_400 f:de_3.c r: c:
		DRIVER(tomy_h30) //t:tomy_h30 f:de_3.c r:tomy_400 c:tomy_400
//SET: wwfr_106
		DRIVER(wwfr_106) //t:wwfr_106 f:de_3.c r: c:
		DRIVER(wwfr_103) //t:wwfr_103 f:de_3.c r:wwfr_106 c:wwfr_106
//SET: batmanf
		DRIVER(batmanf) //t:batmanf f:de_3b.c r: c:
		DRIVER(batmanf3) //t:batmanf3 f:de_3b.c r:batmanf c:batmanf
		DRIVER(bmf_uk) //t:bmf_uk f:de_3b.c r:batmanf c:batmanf
		DRIVER(bmf_cn) //t:bmf_cn f:de_3b.c r:batmanf c:batmanf
		DRIVER(bmf_no) //t:bmf_no f:de_3b.c r:batmanf c:batmanf
		DRIVER(bmf_sv) //t:bmf_sv f:de_3b.c r:batmanf c:batmanf
		DRIVER(bmf_at) //t:bmf_at f:de_3b.c r:batmanf c:batmanf
		DRIVER(bmf_ch) //t:bmf_ch f:de_3b.c r:batmanf c:batmanf
		DRIVER(bmf_de) //t:bmf_de f:de_3b.c r:batmanf c:batmanf
		DRIVER(bmf_be) //t:bmf_be f:de_3b.c r:batmanf c:batmanf
		DRIVER(bmf_fr) //t:bmf_fr f:de_3b.c r:batmanf c:batmanf
		DRIVER(bmf_nl) //t:bmf_nl f:de_3b.c r:batmanf c:batmanf
		DRIVER(bmf_it) //t:bmf_it f:de_3b.c r:batmanf c:batmanf
		DRIVER(bmf_sp) //t:bmf_sp f:de_3b.c r:batmanf c:batmanf
		DRIVER(bmf_jp) //t:bmf_jp f:de_3b.c r:batmanf c:batmanf
		DRIVER(bmf_time) //t:bmf_time f:de_3b.c r:batmanf c:batmanf
//SET: baywatch
		DRIVER(baywatch) //t:baywatch f:de_3b.c r: c:
//SET: frankst
		DRIVER(frankst) //t:frankst f:de_3b.c r: c:
		DRIVER(frankstg) //t:frankstg f:de_3b.c r:frankst c:frankst
//SET: mav_402
		DRIVER(mav_402) //t:mav_402 f:de_3b.c r: c:
		DRIVER(mav_401) //t:mav_401 f:de_3b.c r:mav_402 c:mav_402
		DRIVER(mav_400) //t:mav_400 f:de_3b.c r:mav_402 c:mav_402
		DRIVER(mav_100) //t:mav_100 f:de_3b.c r:mav_402 c:mav_402
//SET: detest
		DRIVER(detest) //t:detest f:de_3b.c r: c:
//SET: ctcheese
		DRIVER(ctcheese) //t:ctcheese f:de_3b.c r: c:
		DRIVER(ctchzdlx) //t:ctchzdlx f:whitestar.c r:ctcheese c:ctcheese
//SET: flicker
		DRIVER(flicker) //t:flicker f:flicker.c r: c:
//SET: rotation
		DRIVER(rotation) //t:rotation f:g627.c r: c:
//SET: gp_110
		DRIVER(gp_110) //t:gp_110 f:gp_1.c r: c:
//SET: blvelvet
		DRIVER(blvelvet) //t:blvelvet f:gp_1.c r:gp_110 c:
//SET: camlight
		DRIVER(camlight) //t:camlight f:gp_1.c r:gp_110 c:
//SET: chucklck
		DRIVER(chucklck) //t:chucklck f:gp_1.c r:gp_110 c:
//SET: famlyfun
		DRIVER(famlyfun) //t:famlyfun f:gp_1.c r: c:
//SET: foxylady
		DRIVER(foxylady) //t:foxylady f:gp_1.c r:gp_110 c:
//SET: real
		DRIVER(real) //t:real f:gp_1.c r:gp_110 c:
//SET: rio
		DRIVER(rio) //t:rio f:gp_1.c r:gp_110 c:
//SET: startrip
		DRIVER(startrip) //t:startrip f:gp_1.c r: c:
//SET: agent777
		DRIVER(agent777) //t:agent777 f:gp_2.c r: c:
//SET: andromep
		DRIVER(andromep) //t:andromep f:gp_2.c r: c:
		DRIVER(andromepa) //t:andromepa f:gp_2.c r:andromep c:andromep
//SET: attila
		DRIVER(attila) //t:attila f:gp_2.c r: c:
//SET: cpthook
		DRIVER(cpthook) //t:cpthook f:gp_2.c r: c:
//SET: cyclopes
		DRIVER(cyclopes) //t:cyclopes f:gp_2.c r: c:
//SET: gwarfare
		DRIVER(gwarfare) //t:gwarfare f:gp_2.c r: c:
//SET: ladyshot
		DRIVER(ladyshot) //t:ladyshot f:gp_2.c r: c:
//SET: mbossy
		DRIVER(mbossy) //t:mbossy f:gp_2.c r: c:
//SET: coneyis
		DRIVER(coneyis) //t:coneyis f:gp_2.c r: c:
//SET: lizard
		DRIVER(lizard) //t:lizard f:gp_2.c r: c:
//SET: sshootr2
		DRIVER(sshootr2) //t:sshootr2 f:gp_2.c r: c:
//SET: sshootep
		DRIVER(sshootep) //t:sshootep f:gp_2.c r: c:
//SET: suprnova
		DRIVER(suprnova) //t:suprnova f:gp_2.c r: c:
//SET: vegasgp
		DRIVER(vegasgp) //t:vegasgp f:gp_2.c r: c:
//SET: gts1
		DRIVER(gts1) //t:gts1 f:gts1.c r: c:
//SET: gts1s
		DRIVER(gts1s) //t:gts1s f:gts1.c r:gts1 c:
//SET: astannie
		DRIVER(astannie) //t:astannie f:gts1.c r:gts1s c:
//SET: buckrgrs
		DRIVER(buckrgrs) //t:buckrgrs f:gts1.c r:gts1s c:
//SET: charlies
		DRIVER(charlies) //t:charlies f:gts1.c r:gts1 c:
//SET: cleoptra
		DRIVER(cleoptra) //t:cleoptra f:gts1.c r:gts1 c:
//SET: closeenc
		DRIVER(closeenc) //t:closeenc f:gts1.c r:gts1 c:
//SET: countdwn
		DRIVER(countdwn) //t:countdwn f:gts1.c r:gts1 c:
//SET: dragon
		DRIVER(dragon) //t:dragon f:gts1.c r:gts1 c:
//SET: geniep
		DRIVER(geniep) //t:geniep f:gts1.c r:gts1s c:
//SET: jokrpokr
		DRIVER(jokrpokr) //t:jokrpokr f:gts1.c r:gts1 c:
//SET: pinpool
		DRIVER(pinpool) //t:pinpool f:gts1.c r:gts1 c:
//SET: roldisco
		DRIVER(roldisco) //t:roldisco f:gts1.c r:gts1s c:
//SET: sinbad
		DRIVER(sinbad) //t:sinbad f:gts1.c r:gts1 c:
		DRIVER(sinbadn) //t:sinbadn f:gts1.c r:sinbad c:sinbad
//SET: solaride
		DRIVER(solaride) //t:solaride f:gts1.c r:gts1 c:
//SET: hulk
		DRIVER(hulk) //t:hulk f:gts1.c r:gts1s c:
//SET: torch
		DRIVER(torch) //t:torch f:gts1.c r:gts1s c:
//SET: totem
		DRIVER(totem) //t:totem f:gts1.c r:gts1s c:
//SET: hexagone
		DRIVER(hexagone) //t:hexagone f:gts1.c r:gts1s c:
//SET: sys1test
		DRIVER(sys1test) //t:sys1test f:gts1.c r:gts1 c:
//SET: barbwire
		DRIVER(barbwire) //t:barbwire f:gts3.c r: c:
//SET: bellring
		DRIVER(bellring) //t:bellring f:gts3.c r: c:
//SET: brooks
		DRIVER(brooks) //t:brooks f:gts3.c r: c:
//SET: cactjack
		DRIVER(cactjack) //t:cactjack f:gts3.c r: c:
//SET: carhop
		DRIVER(carhop) //t:carhop f:gts3.c r: c:
//SET: ccruise
		DRIVER(ccruise) //t:ccruise f:gts3.c r: c:
//SET: clas1812
		DRIVER(clas1812) //t:clas1812 f:gts3.c r: c:
//SET: cueball
		DRIVER(cueball) //t:cueball f:gts3.c r: c:
//SET: deadweap
		DRIVER(deadweap) //t:deadweap f:gts3.c r: c:
//SET: bighurt
		DRIVER(bighurt) //t:bighurt f:gts3.c r: c:
//SET: freddy
		DRIVER(freddy) //t:freddy f:gts3.c r: c:
		DRIVER(freddy4) //t:freddy4 f:gts3.c r:freddy c:freddy
//SET: gladiatp
		DRIVER(gladiatp) //t:gladiatp f:gts3.c r: c:
//SET: hoops
		DRIVER(hoops) //t:hoops f:gts3.c r: c:
//SET: lca
		DRIVER(lca) //t:lca f:gts3.c r: c:
		DRIVER(lca2) //t:lca2 f:gts3.c r:lca c:lca
//SET: andretti
		DRIVER(andretti) //t:andretti f:gts3.c r: c:
		DRIVER(andretti4) //t:andretti4 f:gts3.c r:andretti c:andretti
//SET: nudgeit
		DRIVER(nudgeit) //t:nudgeit f:gts3.c r: c:
//SET: opthund
		DRIVER(opthund) //t:opthund f:gts3.c r: c:
//SET: rescu911
		DRIVER(rescu911) //t:rescu911 f:gts3.c r: c:
//SET: shaqattq
		DRIVER(shaqattq) //t:shaqattq f:gts3.c r: c:
		DRIVER(shaqattq2) //t:shaqattq2 f:gts3.c r:shaqattq c:shaqattq
//SET: silvslug
		DRIVER(silvslug) //t:silvslug f:gts3.c r: c:
//SET: stargatp
		DRIVER(stargatp) //t:stargatp f:gts3.c r: c:
		DRIVER(stargatp1) //t:stargatp1 f:gts3.c r:stargatp c:stargatp
		DRIVER(stargatp2) //t:stargatp2 f:gts3.c r:stargatp c:stargatp
		DRIVER(stargatp3) //t:stargatp3 f:gts3.c r:stargatp c:stargatp
		DRIVER(stargatp4) //t:stargatp4 f:gts3.c r:stargatp c:stargatp
//SET: sfight2
		DRIVER(sfight2) //t:sfight2 f:gts3.c r: c:
		DRIVER(sfight2a) //t:sfight2a f:gts3.c r:sfight2 c:sfight2
		DRIVER(sfight2b) //t:sfight2b f:gts3.c r:sfight2 c:sfight2
//SET: smb
		DRIVER(smb) //t:smb f:gts3.c r: c:
		DRIVER(smb1) //t:smb1 f:gts3.c r:smb c:smb
		DRIVER(smb2) //t:smb2 f:gts3.c r:smb c:smb
		DRIVER(smb3) //t:smb3 f:gts3.c r:smb c:smb
//SET: smbmush
		DRIVER(smbmush) //t:smbmush f:gts3.c r: c:
//SET: surfnsaf
		DRIVER(surfnsaf) //t:surfnsaf f:gts3.c r: c:
//SET: teedoffp
		DRIVER(teedoffp) //t:teedoffp f:gts3.c r: c:
		DRIVER(teedoffp1) //t:teedoffp1 f:gts3.c r:teedoffp c:teedoffp
		DRIVER(teedoffp3) //t:teedoffp3 f:gts3.c r:teedoffp c:teedoffp
//SET: tfight
		DRIVER(tfight) //t:tfight f:gts3.c r: c:
//SET: vegas
		DRIVER(vegas) //t:vegas f:gts3.c r: c:
//SET: waterwld
		DRIVER(waterwld) //t:waterwld f:gts3.c r: c:
		DRIVER(waterwld2) //t:waterwld2 f:gts3.c r:waterwld c:waterwld
//SET: wipeout
		DRIVER(wipeout) //t:wipeout f:gts3.c r: c:
//SET: wcsoccer
		DRIVER(wcsoccer) //t:wcsoccer f:gts3.c r: c:
		DRIVER(wcsoccerd2) //t:wcsoccerd2 f:gts3.c r:wcsoccer c:wcsoccer
//SET: tt_game
		DRIVER(tt_game) //t:tt_game f:gts3.c r: c:
//SET: snspares
		DRIVER(snspares) //t:snspares f:gts3.c r: c:
		DRIVER(snspares1) //t:snspares1 f:gts3.c r:snspares c:snspares
//SET: blckhole
		DRIVER(blckhole) //t:blckhole f:gts80.c r: c:
		DRIVER(blckhole2) //t:blckhole2 f:gts80.c r:blckhole c:blckhole
//SET: blckhols
		DRIVER(blckhols) //t:blckhols f:gts80.c r: c:
//SET: circusp
		DRIVER(circusp) //t:circusp f:gts80.c r: c:
//SET: cntforce
		DRIVER(cntforce) //t:cntforce f:gts80.c r: c:
//SET: eclipse
		DRIVER(eclipse) //t:eclipse f:gts80.c r: c:
//SET: forceii
		DRIVER(forceii) //t:forceii f:gts80.c r: c:
//SET: hh
		DRIVER(hh) //t:hh f:gts80.c r: c:
		DRIVER(hh_1) //t:hh_1 f:gts80.c r:hh c:hh
//SET: jamesb
		DRIVER(jamesb) //t:jamesb f:gts80.c r: c:
		DRIVER(jamesb2) //t:jamesb2 f:gts80.c r:jamesb c:jamesb
//SET: marsp
		DRIVER(marsp) //t:marsp f:gts80.c r: c:
//SET: panthera
		DRIVER(panthera) //t:panthera f:gts80.c r: c:
//SET: pnkpnthr
		DRIVER(pnkpnthr) //t:pnkpnthr f:gts80.c r: c:
//SET: starrace
		DRIVER(starrace) //t:starrace f:gts80.c r: c:
//SET: spidermn
		DRIVER(spidermn) //t:spidermn f:gts80.c r: c:
//SET: timeline
		DRIVER(timeline) //t:timeline f:gts80.c r: c:
//SET: vlcno_ax
		DRIVER(vlcno_ax) //t:vlcno_ax f:gts80.c r: c:
//SET: vlcno_1b
		DRIVER(vlcno_1b) //t:vlcno_1b f:gts80.c r: c:
		DRIVER(vlcno_1a) //t:vlcno_1a f:gts80.c r:vlcno_1b c:vlcno_1b
//SET: s80tst
		DRIVER(s80tst) //t:s80tst f:gts80.c r: c:
//SET: alienstr
		DRIVER(alienstr) //t:alienstr f:gts80a.c r: c:
//SET: amazonh
		DRIVER(amazonh) //t:amazonh f:gts80a.c r: c:
//SET: caveman
		DRIVER(caveman) //t:caveman f:gts80a.c r: c:
		DRIVER(cavemana) //t:cavemana f:gts80a.c r:caveman c:caveman
//SET: dvlsdre
		DRIVER(dvlsdre) //t:dvlsdre f:gts80a.c r: c:
//SET: dvlsdre2
		DRIVER(dvlsdre2) //t:dvlsdre2 f:gts80a.c r: c:
//SET: eldorado
		DRIVER(eldorado) //t:eldorado f:gts80a.c r: c:
//SET: goinnuts
		DRIVER(goinnuts) //t:goinnuts f:gts80a.c r: c:
//SET: icefever
		DRIVER(icefever) //t:icefever f:gts80a.c r: c:
//SET: jack2opn
		DRIVER(jack2opn) //t:jack2opn f:gts80a.c r: c:
//SET: krullp
		DRIVER(krullp) //t:krullp f:gts80a.c r: c:
//SET: punk
		DRIVER(punk) //t:punk f:gts80a.c r: c:
//SET: qbquest
		DRIVER(qbquest) //t:qbquest f:gts80a.c r: c:
//SET: rackempp
		DRIVER(rackempp) //t:rackempp f:gts80a.c r: c:
//SET: raimfire
		DRIVER(raimfire) //t:raimfire f:gts80a.c r: c:
//SET: rocky
		DRIVER(rocky) //t:rocky f:gts80a.c r: c:
//SET: rflshdlx
		DRIVER(rflshdlx) //t:rflshdlx f:gts80a.c r: c:
//SET: spirit
		DRIVER(spirit) //t:spirit f:gts80a.c r: c:
//SET: striker
		DRIVER(striker) //t:striker f:gts80a.c r: c:
//SET: sorbit
		DRIVER(sorbit) //t:sorbit f:gts80a.c r: c:
//SET: thegames
		DRIVER(thegames) //t:thegames f:gts80a.c r: c:
//SET: touchdn
		DRIVER(touchdn) //t:touchdn f:gts80a.c r: c:
//SET: arena
		DRIVER(arena) //t:arena f:gts80b.c r: c:
//SET: badgirls
		DRIVER(badgirls) //t:badgirls f:gts80b.c r: c:
//SET: bighouse
		DRIVER(bighouse) //t:bighouse f:gts80b.c r: c:
//SET: bonebstr
		DRIVER(bonebstr) //t:bonebstr f:gts80b.c r: c:
//SET: bountyh
		DRIVER(bountyh) //t:bountyh f:gts80b.c r: c:
//SET: triplay
		DRIVER(triplay) //t:triplay f:gts80b.c r: c:
//SET: diamondp
		DRIVER(diamondp) //t:diamondp f:gts80b.c r: c:
//SET: excalibr
		DRIVER(excalibr) //t:excalibr f:gts80b.c r: c:
//SET: genesisp
		DRIVER(genesisp) //t:genesisp f:gts80b.c r: c:
//SET: goldwing
		DRIVER(goldwing) //t:goldwing f:gts80b.c r: c:
//SET: hlywoodh
		DRIVER(hlywoodh) //t:hlywoodh f:gts80b.c r: c:
//SET: hotshots
		DRIVER(hotshots) //t:hotshots f:gts80b.c r: c:
//SET: mntecrlo
		DRIVER(mntecrlo) //t:mntecrlo f:gts80b.c r: c:
//SET: nmoves
		DRIVER(nmoves) //t:nmoves f:gts80b.c r: c:
//SET: raven
		DRIVER(raven) //t:raven f:gts80b.c r: c:
//SET: robowars
		DRIVER(robowars) //t:robowars f:gts80b.c r: c:
//SET: rock
		DRIVER(rock) //t:rock f:gts80b.c r: c:
		DRIVER(rock_enc) //t:rock_enc f:gts80b.c r:rock c:rock
//SET: sprbreak
		DRIVER(sprbreak) //t:sprbreak f:gts80b.c r: c:
		DRIVER(sprbreaks) //t:sprbreaks f:gts80b.c r:sprbreak c:sprbreak
//SET: tagteamp
		DRIVER(tagteamp) //t:tagteamp f:gts80b.c r: c:
		DRIVER(tagteamp2) //t:tagteamp2 f:gts80b.c r:tagteamp c:tagteamp
//SET: txsector
		DRIVER(txsector) //t:txsector f:gts80b.c r: c:
//SET: victoryp
		DRIVER(victoryp) //t:victoryp f:gts80b.c r: c:
//SET: fjholden
		DRIVER(fjholden) //t:fjholden f:hankin.c r: c:
//SET: howzat
		DRIVER(howzat) //t:howzat f:hankin.c r: c:
//SET: orbit1
		DRIVER(orbit1) //t:orbit1 f:hankin.c r: c:
//SET: shark
		DRIVER(shark) //t:shark f:hankin.c r: c:
//SET: empsback
		DRIVER(empsback) //t:empsback f:hankin.c r: c:
//SET: icecold
		DRIVER(icecold) //t:icecold f:icecold.c r: c:
//SET: ind250cc
		DRIVER(ind250cc) //t:ind250cc f:inder.c r: c:
//SET: atleta
		DRIVER(atleta) //t:atleta f:inder.c r: c:
//SET: brvteam
		DRIVER(brvteam) //t:brvteam f:inder.c r: c:
//SET: canasta
		DRIVER(canasta) //t:canasta f:inder.c r: c:
//SET: pinclown
		DRIVER(pinclown) //t:pinclown f:inder.c r: c:
//SET: corsario
		DRIVER(corsario) //t:corsario f:inder.c r: c:
//SET: lapbylap
		DRIVER(lapbylap) //t:lapbylap f:inder.c r: c:
//SET: america
		DRIVER(america) //t:america f:jp.c r: c:
//SET: aqualand
		DRIVER(aqualand) //t:aqualand f:jp.c r: c:
//SET: faeton
		DRIVER(faeton) //t:faeton f:jp.c r: c:
//SET: lortium
		DRIVER(lortium) //t:lortium f:jp.c r: c:
//SET: petaco
		DRIVER(petaco) //t:petaco f:jp.c r: c:
//SET: petaco2
		DRIVER(petaco2) //t:petaco2 f:jp.c r: c:
//SET: olympus
		DRIVER(olympus) //t:olympus f:jp.c r: c:
//SET: escape
		DRIVER(escape) //t:escape f:jvh.c r: c:
//SET: movmastr
		DRIVER(movmastr) //t:movmastr f:jvh.c r: c:
//SET: alcapone
		DRIVER(alcapone) //t:alcapone f:ltd.c r: c:
//SET: atla_ltd
		DRIVER(atla_ltd) //t:atla_ltd f:ltd.c r: c:
//SET: bhol_ltd
		DRIVER(bhol_ltd) //t:bhol_ltd f:ltd.c r: c:
//SET: columbia
		DRIVER(columbia) //t:columbia f:ltd.c r: c:
//SET: cowboy
		DRIVER(cowboy) //t:cowboy f:ltd.c r: c:
//SET: pecmen
		DRIVER(pecmen) //t:pecmen f:ltd.c r: c:
//SET: zephy
		DRIVER(zephy) //t:zephy f:ltd.c r: c:
//SET: pentacup
		DRIVER(pentacup) //t:pentacup f:micropin.c r: c:
		DRIVER(pentacup2) //t:pentacup2 f:micropin.c r:pentacup c:pentacup
//SET: mephistp
		DRIVER(mephistp) //t:mephistp f:mephisto.c r: c:
		DRIVER(mephistp1) //t:mephistp1 f:mephisto.c r:mephistp c:mephistp
//SET: dakar
		DRIVER(dakar) //t:dakar f:mrgame.c r: c:
//SET: motrshow
		DRIVER(motrshow) //t:motrshow f:mrgame.c r: c:
		DRIVER(motrshowa) //t:motrshowa f:mrgame.c r:motrshow c:motrshow
//SET: macattck
		DRIVER(macattck) //t:macattck f:mrgame.c r: c:
//SET: wcup90
		DRIVER(wcup90) //t:wcup90 f:mrgame.c r: c:
//SET: firebird
		DRIVER(firebird) //t:firebird f:nsm.c r: c:
//SET: odisea
		DRIVER(odisea) //t:odisea f:peyper.c r: c:
//SET: wolfman
		DRIVER(wolfman) //t:wolfman f:peyper.c r: c:
//SET: odin_dlx
		DRIVER(odin_dlx) //t:odin_dlx f:peyper.c r: c:
//SET: solarwap
		DRIVER(solarwap) //t:solarwap f:peyper.c r: c:
//SET: poleposn
		DRIVER(poleposn) //t:poleposn f:peyper.c r: c:
//SET: sonstwar
		DRIVER(sonstwar) //t:sonstwar f:peyper.c r: c:
//SET: bigtown
		DRIVER(bigtown) //t:bigtown f:play_1.c r: c:
//SET: chance
		DRIVER(chance) //t:chance f:play_1.c r: c:
//SET: lastlap
		DRIVER(lastlap) //t:lastlap f:play_1.c r: c:
//SET: spcgambl
		DRIVER(spcgambl) //t:spcgambl f:play_1.c r: c:
//SET: party
		DRIVER(party) //t:party f:play_1.c r: c:
//SET: antar
		DRIVER(antar) //t:antar f:play_2.c r: c:
		DRIVER(antar2) //t:antar2 f:play_2.c r:antar c:antar
//SET: evlfight
		DRIVER(evlfight) //t:evlfight f:play_2.c r: c:
//SET: attack
		DRIVER(attack) //t:attack f:play_2.c r: c:
//SET: blkfever
		DRIVER(blkfever) //t:blkfever f:play_2.c r: c:
//SET: cerberup
		DRIVER(cerberup) //t:cerberup f:play_2.c r: c:
//SET: madrace
		DRIVER(madrace) //t:madrace f:play_2.c r: c:
//SET: megaaton
		DRIVER(megaaton) //t:megaaton f:play_3.c r: c:
//SET: spain82
		DRIVER(spain82) //t:spain82 f:play_5.c r: c:
//SET: ufo_x
		DRIVER(ufo_x) //t:ufo_x f:play_5.c r: c:
//SET: kz26
		DRIVER(kz26) //t:kz26 f:play_5.c r: c:
//SET: rock2500
		DRIVER(rock2500) //t:rock2500 f:play_5.c r: c:
//SET: starfirp
		DRIVER(starfirp) //t:starfirp f:play_5.c r: c:
//SET: trailer
		DRIVER(trailer) //t:trailer f:play_5.c r: c:
//SET: heavymtl
		DRIVER(heavymtl) //t:heavymtl f:rowamet.c r: c:
//SET: gmine_l2
		DRIVER(gmine_l2) //t:gmine_l2 f:s11.c r: c:
//SET: grand_l4
		DRIVER(grand_l4) //t:grand_l4 f:s11.c r: c:
//SET: hs_l4
		DRIVER(hs_l4) //t:hs_l4 f:s11.c r: c:
		DRIVER(hs_l3) //t:hs_l3 f:s11.c r:hs_l4 c:hs_l4
//SET: rdkng_l4
		DRIVER(rdkng_l4) //t:rdkng_l4 f:s11.c r: c:
		DRIVER(rdkng_l1) //t:rdkng_l1 f:s11.c r:rdkng_l4 c:rdkng_l4
		DRIVER(rdkng_l2) //t:rdkng_l2 f:s11.c r:rdkng_l4 c:rdkng_l4
		DRIVER(rdkng_l3) //t:rdkng_l3 f:s11.c r:rdkng_l4 c:rdkng_l4
//SET: tdawg_l1
		DRIVER(tdawg_l1) //t:tdawg_l1 f:s11.c r: c:
//SET: shfin_l1
		DRIVER(shfin_l1) //t:shfin_l1 f:s11.c r: c:
//SET: f14_l1
		DRIVER(f14_l1) //t:f14_l1 f:s11a.c r: c:
		DRIVER(f14_p3) //t:f14_p3 f:s11a.c r:f14_l1 c:f14_l1
		DRIVER(f14_p4) //t:f14_p4 f:s11a.c r:f14_l1 c:f14_l1
//SET: fire_l3
		DRIVER(fire_l3) //t:fire_l3 f:s11a.c r: c:
//SET: milln_l3
		DRIVER(milln_l3) //t:milln_l3 f:s11a.c r: c:
//SET: pb_l5
		DRIVER(pb_l5) //t:pb_l5 f:s11a.c r: c:
		DRIVER(pb_l2) //t:pb_l2 f:s11a.c r:pb_l5 c:pb_l5
		DRIVER(pb_l3) //t:pb_l3 f:s11a.c r:pb_l5 c:pb_l5
//SET: bcats_l5
		DRIVER(bcats_l5) //t:bcats_l5 f:s11b.c r: c:
		DRIVER(bcats_l2) //t:bcats_l2 f:s11b.c r:bcats_l5 c:bcats_l5
//SET: bnzai_l3
		DRIVER(bnzai_l3) //t:bnzai_l3 f:s11b.c r: c:
		DRIVER(bnzai_g3) //t:bnzai_g3 f:s11b.c r:bnzai_l3 c:bnzai_l3
		DRIVER(bnzai_l1) //t:bnzai_l1 f:s11b.c r:bnzai_l3 c:bnzai_l3
		DRIVER(bnzai_pa) //t:bnzai_pa f:s11b.c r:bnzai_l3 c:bnzai_l3
//SET: bguns_l8
		DRIVER(bguns_l8) //t:bguns_l8 f:s11b.c r: c:
		DRIVER(bguns_l7) //t:bguns_l7 f:s11b.c r:bguns_l8 c:bguns_l8
		DRIVER(bguns_la) //t:bguns_la f:s11b.c r:bguns_l8 c:bguns_l8
		DRIVER(bguns_p1) //t:bguns_p1 f:s11b.c r:bguns_l8 c:bguns_l8
//SET: bk2k_l4
		DRIVER(bk2k_l4) //t:bk2k_l4 f:s11b.c r: c:
		DRIVER(bk2k_lg1) //t:bk2k_lg1 f:s11b.c r:bk2k_l4 c:bk2k_l4
		DRIVER(bk2k_lg3) //t:bk2k_lg3 f:s11b.c r:bk2k_l4 c:bk2k_l4
		DRIVER(bk2k_pu1) //t:bk2k_pu1 f:s11b.c r:bk2k_l4 c:bk2k_l4
//SET: cycln_l5
		DRIVER(cycln_l5) //t:cycln_l5 f:s11b.c r: c:
		DRIVER(cycln_l4) //t:cycln_l4 f:s11b.c r:cycln_l5 c:cycln_l5
//SET: esha_la3
		DRIVER(esha_la3) //t:esha_la3 f:s11b.c r: c:
		DRIVER(esha_ma3) //t:esha_ma3 f:s11b.c r:esha_la3 c:esha_la3
		DRIVER(esha_pr4) //t:esha_pr4 f:s11b.c r:esha_la3 c:esha_la3
		DRIVER(esha_lg1) //t:esha_lg1 f:s11b.c r:esha_la3 c:esha_la3
		DRIVER(esha_lg2) //t:esha_lg2 f:s11b.c r:esha_la3 c:esha_la3
		DRIVER(esha_la1) //t:esha_la1 f:s11b.c r:esha_la3 c:esha_la3
		DRIVER(esha_pa1) //t:esha_pa1 f:s11b.c r:esha_la3 c:esha_la3
//SET: eatpm_l4
		DRIVER(eatpm_l4) //t:eatpm_l4 f:s11b.c r: c:
		DRIVER(eatpm_l1) //t:eatpm_l1 f:s11b.c r:eatpm_l4 c:eatpm_l4
		DRIVER(eatpm_l2) //t:eatpm_l2 f:s11b.c r:eatpm_l4 c:eatpm_l4
		DRIVER(eatpm_4g) //t:eatpm_4g f:s11b.c r:eatpm_l4 c:eatpm_l4
		DRIVER(eatpm_4u) //t:eatpm_4u f:s11b.c r:eatpm_l4 c:eatpm_l4
		DRIVER(eatpm_p7) //t:eatpm_p7 f:s11b.c r:eatpm_l4 c:eatpm_l4
//SET: jokrz_l6
		DRIVER(jokrz_l6) //t:jokrz_l6 f:s11b.c r: c:
		DRIVER(jokrz_l3) //t:jokrz_l3 f:s11b.c r:jokrz_l6 c:jokrz_l6
//SET: mousn_l4
		DRIVER(mousn_l4) //t:mousn_l4 f:s11b.c r: c:
		DRIVER(mousn_l1) //t:mousn_l1 f:s11b.c r:mousn_l4 c:mousn_l4
		DRIVER(mousn_lu) //t:mousn_lu f:s11b.c r:mousn_l4 c:mousn_l4
		DRIVER(mousn_lx) //t:mousn_lx f:s11b.c r:mousn_l4 c:mousn_l4
//SET: polic_l4
		DRIVER(polic_l4) //t:polic_l4 f:s11b.c r: c:
		DRIVER(polic_l3) //t:polic_l3 f:s11b.c r:polic_l4 c:polic_l4
		DRIVER(polic_l2) //t:polic_l2 f:s11b.c r:polic_l4 c:polic_l4
//SET: spstn_l5
		DRIVER(spstn_l5) //t:spstn_l5 f:s11b.c r: c:
//SET: swrds_l2
		DRIVER(swrds_l2) //t:swrds_l2 f:s11b.c r: c:
//SET: taxi_l4
		DRIVER(taxi_l4) //t:taxi_l4 f:s11b.c r: c:
		DRIVER(taxi_l3) //t:taxi_l3 f:s11b.c r:taxi_l4 c:taxi_l4
		DRIVER(taxi_lg1) //t:taxi_lg1 f:s11b.c r:taxi_l4 c:taxi_l4
//SET: tsptr_l3
		DRIVER(tsptr_l3) //t:tsptr_l3 f:s11b.c r: c:
//SET: whirl_l3
		DRIVER(whirl_l3) //t:whirl_l3 f:s11b.c r: c:
		DRIVER(whirl_l2) //t:whirl_l2 f:s11b.c r:whirl_l3 c:whirl_l3
		DRIVER(whirl_lg3) //t:whirl_lg3 f:s11b.c r:whirl_l3 c:whirl_l3
//SET: bbnny_l2
		DRIVER(bbnny_l2) //t:bbnny_l2 f:s11c.c r: c:
		DRIVER(bbnny_lu) //t:bbnny_lu f:s11c.c r:bbnny_l2 c:bbnny_l2
//SET: diner_l4
		DRIVER(diner_l4) //t:diner_l4 f:s11c.c r: c:
		DRIVER(diner_l3) //t:diner_l3 f:s11c.c r:diner_l4 c:diner_l4
		DRIVER(diner_l1) //t:diner_l1 f:s11c.c r:diner_l4 c:diner_l4
//SET: dd_l2
		DRIVER(dd_l2) //t:dd_l2 f:s11c.c r: c:
		DRIVER(dd_p6) //t:dd_p6 f:s11c.c r:dd_l2 c:dd_l2
		DRIVER(dd_p7) //t:dd_p7 f:wpc_an.c r:dd_l2 c:dd_l2
		DRIVER(dd_p06) //t:dd_p06 f:wpc_an.c r:dd_l2 c:dd_l2
//SET: pool_l7
		DRIVER(pool_l7) //t:pool_l7 f:s11c.c r: c:
		DRIVER(pool_l6) //t:pool_l6 f:s11c.c r:pool_l7 c:pool_l7
		DRIVER(pool_le2) //t:pool_le2 f:s11c.c r:pool_l7 c:pool_l7
		DRIVER(pool_p7) //t:pool_p7 f:s11c.c r:pool_l7 c:pool_l7
//SET: radcl_l1
		DRIVER(radcl_l1) //t:radcl_l1 f:s11c.c r: c:
		DRIVER(radcl_g1) //t:radcl_g1 f:s11c.c r:radcl_l1 c:radcl_l1
		DRIVER(radcl_p3) //t:radcl_p3 f:s11c.c r:radcl_l1 c:radcl_l1
//SET: rvrbt_l3
		DRIVER(rvrbt_l3) //t:rvrbt_l3 f:s11c.c r: c:
//SET: rollr_l2
		DRIVER(rollr_l2) //t:rollr_l2 f:s11c.c r: c:
		DRIVER(rollr_ex) //t:rollr_ex f:s11c.c r:rollr_l2 c:rollr_l2
		DRIVER(rollr_e1) //t:rollr_e1 f:s11c.c r:rollr_l2 c:rollr_l2
		DRIVER(rollr_p2) //t:rollr_p2 f:s11c.c r:rollr_l2 c:rollr_l2
		DRIVER(rollr_l3) //t:rollr_l3 f:s11c.c r:rollr_l2 c:rollr_l2
		DRIVER(rollr_g3) //t:rollr_g3 f:s11c.c r:rollr_l2 c:rollr_l2
//SET: gs_l4
		DRIVER(gs_l4) //t:gs_l4 f:s11c.c r: c:
		DRIVER(gs_l3) //t:gs_l3 f:s11c.c r:gs_l4 c:gs_l4
//SET: strax_p7
		DRIVER(strax_p7) //t:strax_p7 f:s11c.c r: c:
//SET: httip_l1
		DRIVER(httip_l1) //t:httip_l1 f:s3.c r: c:
//SET: lucky_l1
		DRIVER(lucky_l1) //t:lucky_l1 f:s3.c r: c:
//SET: wldcp_l1
		DRIVER(wldcp_l1) //t:wldcp_l1 f:s3.c r: c:
//SET: cntct_l1
		DRIVER(cntct_l1) //t:cntct_l1 f:s3.c r: c:
//SET: disco_l1
		DRIVER(disco_l1) //t:disco_l1 f:s3.c r: c:
//SET: flash_l1
		DRIVER(flash_l1) //t:flash_l1 f:s4.c r: c:
		DRIVER(flash_t1) //t:flash_t1 f:s4.c r:flash_l1 c:flash_l1
//SET: phnix_l1
		DRIVER(phnix_l1) //t:phnix_l1 f:s4.c r: c:
//SET: pkrno_l1
		DRIVER(pkrno_l1) //t:pkrno_l1 f:s4.c r: c:
//SET: stlwr_l2
		DRIVER(stlwr_l2) //t:stlwr_l2 f:s4.c r: c:
//SET: pomp_l1
		DRIVER(pomp_l1) //t:pomp_l1 f:s4.c r: c:
//SET: arist_l1
		DRIVER(arist_l1) //t:arist_l1 f:s4.c r: c:
//SET: topaz_l1
		DRIVER(topaz_l1) //t:topaz_l1 f:s4.c r: c:
//SET: taurs_l1
		DRIVER(taurs_l1) //t:taurs_l1 f:s4.c r: c:
//SET: kingt_l1
		DRIVER(kingt_l1) //t:kingt_l1 f:s4.c r: c:
//SET: omni_l1
		DRIVER(omni_l1) //t:omni_l1 f:s4.c r: c:
//SET: bstrk_l1
		DRIVER(bstrk_l1) //t:bstrk_l1 f:s4.c r: c:
//SET: tstrk_l1
		DRIVER(tstrk_l1) //t:tstrk_l1 f:s4.c r: c:
//SET: blkou_l1
		DRIVER(blkou_l1) //t:blkou_l1 f:s6.c r: c:
		DRIVER(blkou_t1) //t:blkou_t1 f:s6.c r:blkou_l1 c:blkou_l1
		DRIVER(blkou_f1) //t:blkou_f1 f:s6.c r:blkou_l1 c:blkou_l1
//SET: frpwr_l6
		DRIVER(frpwr_l6) //t:frpwr_l6 f:s6.c r: c:
		DRIVER(frpwr_t6) //t:frpwr_t6 f:s6.c r:frpwr_l6 c:frpwr_l6
		DRIVER(frpwr_l2) //t:frpwr_l2 f:s6.c r:frpwr_l6 c:frpwr_l6
//SET: grgar_l1
		DRIVER(grgar_l1) //t:grgar_l1 f:s6.c r: c:
		DRIVER(grgar_t1) //t:grgar_t1 f:s6.c r:grgar_l1 c:grgar_l1
//SET: lzbal_l2
		DRIVER(lzbal_l2) //t:lzbal_l2 f:s6.c r: c:
		DRIVER(lzbal_t2) //t:lzbal_t2 f:s6.c r:lzbal_l2 c:lzbal_l2
//SET: tmwrp_l2
		DRIVER(tmwrp_l2) //t:tmwrp_l2 f:s6.c r: c:
		DRIVER(tmwrp_t2) //t:tmwrp_t2 f:s6.c r:tmwrp_l2 c:tmwrp_l2
//SET: scrpn_l1
		DRIVER(scrpn_l1) //t:scrpn_l1 f:s6.c r: c:
		DRIVER(scrpn_t1) //t:scrpn_t1 f:s6.c r:scrpn_l1 c:scrpn_l1
//SET: trizn_l1
		DRIVER(trizn_l1) //t:trizn_l1 f:s6.c r: c:
		DRIVER(trizn_t1) //t:trizn_t1 f:s6.c r:trizn_l1 c:trizn_l1
//SET: algar_l1
		DRIVER(algar_l1) //t:algar_l1 f:s6a.c r: c:
//SET: alpok_l6
		DRIVER(alpok_l6) //t:alpok_l6 f:s6a.c r: c:
		DRIVER(alpok_l2) //t:alpok_l2 f:s6a.c r:alpok_l6 c:alpok_l6
		DRIVER(alpok_f6) //t:alpok_f6 f:s6a.c r:alpok_l6 c:alpok_l6
//SET: vrkon_l1
		DRIVER(vrkon_l1) //t:vrkon_l1 f:s7.c r: c:
//SET: barra_l1
		DRIVER(barra_l1) //t:barra_l1 f:s7.c r: c:
//SET: bk_l4
		DRIVER(bk_l4) //t:bk_l4 f:s7.c r: c:
		DRIVER(bk_f4) //t:bk_f4 f:s7.c r:bk_l4 c:bk_l4
		DRIVER(bk_l3) //t:bk_l3 f:s7.c r:bk_l4 c:bk_l4
//SET: csmic_l1
		DRIVER(csmic_l1) //t:csmic_l1 f:s7.c r: c:
//SET: dfndr_l4
		DRIVER(dfndr_l4) //t:dfndr_l4 f:s7.c r: c:
//SET: fpwr2_l2
		DRIVER(fpwr2_l2) //t:fpwr2_l2 f:s7.c r: c:
//SET: hypbl_l4
		DRIVER(hypbl_l4) //t:hypbl_l4 f:s7.c r: c:
//SET: jst_l2
		DRIVER(jst_l2) //t:jst_l2 f:s7.c r: c:
//SET: jngld_l2
		DRIVER(jngld_l2) //t:jngld_l2 f:s7.c r: c:
//SET: lsrcu_l2
		DRIVER(lsrcu_l2) //t:lsrcu_l2 f:s7.c r: c:
//SET: pharo_l2
		DRIVER(pharo_l2) //t:pharo_l2 f:s7.c r: c:
//SET: solar_l2
		DRIVER(solar_l2) //t:solar_l2 f:s7.c r: c:
//SET: strlt_l1
		DRIVER(strlt_l1) //t:strlt_l1 f:s7.c r: c:
//SET: tmfnt_l5
		DRIVER(tmfnt_l5) //t:tmfnt_l5 f:s7.c r: c:
//SET: wrlok_l3
		DRIVER(wrlok_l3) //t:wrlok_l3 f:s7.c r: c:
//SET: thund_p1
		DRIVER(thund_p1) //t:thund_p1 f:s7.c r: c:
//SET: ratrc_l1
		DRIVER(ratrc_l1) //t:ratrc_l1 f:s7.c r: c:
//SET: pfevr_l2
		DRIVER(pfevr_l2) //t:pfevr_l2 f:s8.c r: c:
		DRIVER(pfevr_p3) //t:pfevr_p3 f:s8.c r:pfevr_l2 c:pfevr_l2
//SET: comet_l5
		DRIVER(comet_l5) //t:comet_l5 f:s9.c r: c:
		DRIVER(comet_l4) //t:comet_l4 f:s9.c r:comet_l5 c:comet_l5
//SET: sorcr_l2
		DRIVER(sorcr_l2) //t:sorcr_l2 f:s9.c r: c:
		DRIVER(sorcr_l1) //t:sorcr_l1 f:s9.c r:sorcr_l2 c:sorcr_l2
//SET: sshtl_l7
		DRIVER(sshtl_l7) //t:sshtl_l7 f:s9.c r: c:
//SET: alcat_l7
		DRIVER(alcat_l7) //t:alcat_l7 f:s9.c r: c:
//SET: szone_l5
		DRIVER(szone_l5) //t:szone_l5 f:s9.c r: c:
		DRIVER(szone_l2) //t:szone_l2 f:s9.c r:szone_l5 c:szone_l5
//SET: sleicpin
		DRIVER(sleicpin) //t:sleicpin f:sleic.c r: c:
//SET: bushido
		DRIVER(bushido) //t:bushido f:spinb.c r: c:
		DRIVER(bushidoa) //t:bushidoa f:spinb.c r:bushido c:bushido
//SET: jolypark
		DRIVER(jolypark) //t:jolypark f:spinb.c r: c:
//SET: mach2
		DRIVER(mach2) //t:mach2 f:spinb.c r: c:
//SET: princess
		DRIVER(princess) //t:princess f:st_mp100.c r: c:
//SET: dracula
		DRIVER(dracula) //t:dracula f:st_mp100.c r: c:
//SET: hothand
		DRIVER(hothand) //t:hothand f:st_mp100.c r: c:
//SET: lectrono
		DRIVER(lectrono) //t:lectrono f:st_mp100.c r: c:
//SET: magic
		DRIVER(magic) //t:magic f:st_mp100.c r: c:
//SET: memlane
		DRIVER(memlane) //t:memlane f:st_mp100.c r: c:
//SET: nugent
		DRIVER(nugent) //t:nugent f:st_mp100.c r: c:
//SET: pinball
		DRIVER(pinball) //t:pinball f:st_mp100.c r: c:
//SET: stars
		DRIVER(stars) //t:stars f:st_mp100.c r: c:
//SET: stingray
		DRIVER(stingray) //t:stingray f:st_mp100.c r: c:
//SET: trident
		DRIVER(trident) //t:trident f:st_mp100.c r: c:
//SET: wildfyre
		DRIVER(wildfyre) //t:wildfyre f:st_mp100.c r: c:
//SET: ali
		DRIVER(ali) //t:ali f:st_mp200.c r: c:
//SET: biggame
		DRIVER(biggame) //t:biggame f:st_mp200.c r: c:
//SET: catacomp
		DRIVER(catacomp) //t:catacomp f:st_mp200.c r: c:
//SET: cheetah
		DRIVER(cheetah) //t:cheetah f:st_mp200.c r: c:
//SET: dragfist
		DRIVER(dragfist) //t:dragfist f:st_mp200.c r: c:
//SET: flight2k
		DRIVER(flight2k) //t:flight2k f:st_mp200.c r: c:
		DRIVER(gamatron) //t:gamatron f:st_mp200.c r:flight2k c:flight2k
//SET: freefall
		DRIVER(freefall) //t:freefall f:st_mp200.c r: c:
//SET: galaxypi
		DRIVER(galaxypi) //t:galaxypi f:st_mp200.c r: c:
//SET: ironmaid
		DRIVER(ironmaid) //t:ironmaid f:st_mp200.c r: c:
//SET: lazrlord
		DRIVER(lazrlord) //t:lazrlord f:st_mp200.c r: c:
//SET: lightnin
		DRIVER(lightnin) //t:lightnin f:st_mp200.c r: c:
//SET: meteorp
		DRIVER(meteorp) //t:meteorp f:st_mp200.c r: c:
//SET: nineball
		DRIVER(nineball) //t:nineball f:st_mp200.c r: c:
//SET: orbitor1
		DRIVER(orbitor1) //t:orbitor1 f:st_mp200.c r: c:
//SET: quicksil
		DRIVER(quicksil) //t:quicksil f:st_mp200.c r: c:
//SET: seawitch
		DRIVER(seawitch) //t:seawitch f:st_mp200.c r: c:
//SET: splitsec
		DRIVER(splitsec) //t:splitsec f:st_mp200.c r: c:
//SET: stargzr
		DRIVER(stargzr) //t:stargzr f:st_mp200.c r: c:
//SET: viperp
		DRIVER(viperp) //t:viperp f:st_mp200.c r: c:
//SET: blkshpsq
		DRIVER(blkshpsq) //t:blkshpsq f:st_mp200.c r: c:
//SET: st_game
		DRIVER(st_game) //t:st_game f:st_mp200.c r: c:
//SET: taitest
		DRIVER(taitest) //t:taitest f:taito.c r: c:
//SET: cavnegro
		DRIVER(cavnegro) //t:cavnegro f:taito.c r: c:
		DRIVER(cavnegro1) //t:cavnegro1 f:taito.c r:cavnegro c:cavnegro
		DRIVER(cavnegro2) //t:cavnegro2 f:taito.c r:cavnegro c:cavnegro
//SET: cosmic
		DRIVER(cosmic) //t:cosmic f:taito.c r: c:
//SET: drakor
		DRIVER(drakor) //t:drakor f:taito.c r: c:
//SET: fireact
		DRIVER(fireact) //t:fireact f:taito.c r: c:
//SET: fireactd
		DRIVER(fireactd) //t:fireactd f:taito.c r: c:
//SET: gemini2k
		DRIVER(gemini2k) //t:gemini2k f:taito.c r: c:
		DRIVER(gemini2k1) //t:gemini2k1 f:taito.c r:gemini2k c:gemini2k
//SET: gork
		DRIVER(gork) //t:gork f:taito.c r: c:
//SET: hawkman
		DRIVER(hawkman) //t:hawkman f:taito.c r: c:
		DRIVER(hawkman1) //t:hawkman1 f:taito.c r:hawkman c:hawkman
//SET: ladylukt
		DRIVER(ladylukt) //t:ladylukt f:taito.c r: c:
		DRIVER(vegast) //t:vegast f:taito.c r:ladylukt c:ladylukt
//SET: lunelle
		DRIVER(lunelle) //t:lunelle f:taito.c r: c:
//SET: meteort
		DRIVER(meteort) //t:meteort f:taito.c r: c:
//SET: mrblack
		DRIVER(mrblack) //t:mrblack f:taito.c r: c:
		DRIVER(mrblack1) //t:mrblack1 f:taito.c r:mrblack c:mrblack
		DRIVER(mrblkz80) //t:mrblkz80 f:taito.c r:mrblack c:mrblack
//SET: obaoba
		DRIVER(obaoba) //t:obaoba f:taito.c r: c:
		DRIVER(obaoba1) //t:obaoba1 f:taito.c r:obaoba c:obaoba
//SET: polar
		DRIVER(polar) //t:polar f:taito.c r: c:
//SET: rally
		DRIVER(rally) //t:rally f:taito.c r: c:
//SET: sharkt
		DRIVER(sharkt) //t:sharkt f:taito.c r: c:
//SET: shock
		DRIVER(shock) //t:shock f:taito.c r: c:
//SET: snake
		DRIVER(snake) //t:snake f:taito.c r: c:
//SET: sshuttle
		DRIVER(sshuttle) //t:sshuttle f:taito.c r: c:
		DRIVER(sshuttle1) //t:sshuttle1 f:taito.c r:sshuttle c:sshuttle
//SET: stest
		DRIVER(stest) //t:stest f:taito.c r: c:
//SET: sureshop
		DRIVER(sureshop) //t:sureshop f:taito.c r: c:
//SET: titan
		DRIVER(titan) //t:titan f:taito.c r: c:
		DRIVER(titan1) //t:titan1 f:taito.c r:titan c:titan
//SET: voleybal
		DRIVER(voleybal) //t:voleybal f:taito.c r: c:
//SET: vortexp
		DRIVER(vortexp) //t:vortexp f:taito.c r: c:
//SET: zarza
		DRIVER(zarza) //t:zarza f:taito.c r: c:
		DRIVER(zarza1) //t:zarza1 f:taito.c r:zarza c:zarza
//SET: xforce
		DRIVER(xforce) //t:xforce f:techno.c r: c:
//SET: break
		DRIVER(break) //t:break f:vd.c r: c:
//SET: apollo13
		DRIVER(apollo13) //t:apollo13 f:whitestar.c r: c:
//SET: austin
		DRIVER(austin) //t:austin f:whitestar.c r: c:
		DRIVER(aust301) //t:aust301 f:whitestar.c r:austin c:austin
		DRIVER(aust300) //t:aust300 f:whitestar.c r:austin c:austin
		DRIVER(aust201) //t:aust201 f:whitestar.c r:austin c:austin
		DRIVER(austnew) //t:austnew f:whitestar.c r:austin c:austin
		DRIVER(austinf) //t:austinf f:whitestar.c r:austin c:austin
		DRIVER(austing) //t:austing f:whitestar.c r:austin c:austin
		DRIVER(austini) //t:austini f:whitestar.c r:austin c:austin
//SET: godzillp
		DRIVER(godzillp) //t:godzillp f:whitestar.c r: c:
//SET: gldneye
		DRIVER(gldneye) //t:gldneye f:whitestar.c r: c:
//SET: goldcue
		DRIVER(goldcue) //t:goldcue f:whitestar.c r: c:
//SET: harl_a13
		DRIVER(harl_a13) //t:harl_a13 f:whitestar.c r: c:
		DRIVER(harl_a10) //t:harl_a10 f:whitestar.c r:harl_a13 c:harl_a13
		DRIVER(harl_f13) //t:harl_f13 f:whitestar.c r:harl_a13 c:harl_a13
		DRIVER(harl_g13) //t:harl_g13 f:whitestar.c r:harl_a13 c:harl_a13
		DRIVER(harl_i13) //t:harl_i13 f:whitestar.c r:harl_a13 c:harl_a13
		DRIVER(harl_l13) //t:harl_l13 f:whitestar.c r:harl_a13 c:harl_a13
//SET: harl_a30
		DRIVER(harl_a30) //t:harl_a30 f:whitestar.c r: c:
		DRIVER(harl_f30) //t:harl_f30 f:whitestar.c r:harl_a30 c:harl_a30
		DRIVER(harl_g30) //t:harl_g30 f:whitestar.c r:harl_a30 c:harl_a30
		DRIVER(harl_i30) //t:harl_i30 f:whitestar.c r:harl_a30 c:harl_a30
		DRIVER(harl_l30) //t:harl_l30 f:whitestar.c r:harl_a30 c:harl_a30
		DRIVER(harl_a18) //t:harl_a18 f:whitestar.c r:harl_a30 c:harl_a30
		DRIVER(harl_f18) //t:harl_f18 f:whitestar.c r:harl_a30 c:harl_a30
		DRIVER(harl_g18) //t:harl_g18 f:whitestar.c r:harl_a30 c:harl_a30
		DRIVER(harl_i18) //t:harl_i18 f:whitestar.c r:harl_a30 c:harl_a30
		DRIVER(harl_l18) //t:harl_l18 f:whitestar.c r:harl_a30 c:harl_a30
//SET: hirolcas
		DRIVER(hirolcas) //t:hirolcas f:whitestar.c r: c:
		DRIVER(hirolcas_210) //t:hirolcas_210 f:whitestar.c r:hirolcas c:hirolcas
		DRIVER(hironew) //t:hironew f:whitestar.c r:hirolcas c:hirolcas
		DRIVER(hirolcat) //t:hirolcat f:whitestar.c r:hirolcas c:hirolcas
		DRIVER(hirol_fr) //t:hirol_fr f:whitestar.c r:hirolcas c:hirolcas
		DRIVER(hirol_gr) //t:hirol_gr f:whitestar.c r:hirolcas c:hirolcas
		DRIVER(hirol_gr_210) //t:hirol_gr_210 f:whitestar.c r:hirolcas c:hirolcas
		DRIVER(hirol_it) //t:hirol_it f:whitestar.c r:hirolcas c:hirolcas
//SET: id4
		DRIVER(id4) //t:id4 f:whitestar.c r: c:
//SET: lostspc
		DRIVER(lostspc) //t:lostspc f:whitestar.c r: c:
//SET: monopolp
		DRIVER(monopolp) //t:monopolp f:whitestar.c r: c:
		DRIVER(monop303) //t:monop303 f:whitestar.c r:monopolp c:monopolp
		DRIVER(monop301) //t:monop301 f:whitestar.c r:monopolp c:monopolp
		DRIVER(monop251) //t:monop251 f:whitestar.c r:monopolp c:monopolp
		DRIVER(monop233) //t:monop233 f:whitestar.c r:monopolp c:monopolp
		DRIVER(monopolf) //t:monopolf f:whitestar.c r:monopolp c:monopolp
		DRIVER(monopolg) //t:monopolg f:whitestar.c r:monopolp c:monopolp
		DRIVER(monopoli) //t:monopoli f:whitestar.c r:monopolp c:monopolp
		DRIVER(monopoll) //t:monopoll f:whitestar.c r:monopolp c:monopolp
		DRIVER(mononew) //t:mononew f:whitestar.c r:monopolp c:monopolp
//SET: nfl
		DRIVER(nfl) //t:nfl f:whitestar.c r: c:
//SET: playboys
		DRIVER(playboys) //t:playboys f:whitestar.c r: c:
		DRIVER(playboys_401) //t:playboys_401 f:whitestar.c r:playboys c:playboys
		DRIVER(playboys_303) //t:playboys_303 f:whitestar.c r:playboys c:playboys
		DRIVER(playboys_300) //t:playboys_300 f:whitestar.c r:playboys c:playboys
		DRIVER(playboys_203) //t:playboys_203 f:whitestar.c r:playboys c:playboys
		DRIVER(playnew) //t:playnew f:whitestar.c r:playboys c:playboys
//SET: playboyf
		DRIVER(playboyf) //t:playboyf f:whitestar.c r: c:
		DRIVER(playboyf_401) //t:playboyf_401 f:whitestar.c r:playboyf c:playboyf
		DRIVER(playboyf_303) //t:playboyf_303 f:whitestar.c r:playboyf c:playboyf
		DRIVER(playboyf_300) //t:playboyf_300 f:whitestar.c r:playboyf c:playboyf
		DRIVER(playboyf_203) //t:playboyf_203 f:whitestar.c r:playboyf c:playboyf
//SET: playboyg
		DRIVER(playboyg) //t:playboyg f:whitestar.c r: c:
		DRIVER(playboyg_401) //t:playboyg_401 f:whitestar.c r:playboyg c:playboyg
		DRIVER(playboyg_303) //t:playboyg_303 f:whitestar.c r:playboyg c:playboyg
		DRIVER(playboyg_300) //t:playboyg_300 f:whitestar.c r:playboyg c:playboyg
		DRIVER(playboyg_203) //t:playboyg_203 f:whitestar.c r:playboyg c:playboyg
//SET: playboyi
		DRIVER(playboyi) //t:playboyi f:whitestar.c r: c:
		DRIVER(playboyi_401) //t:playboyi_401 f:whitestar.c r:playboyi c:playboyi
		DRIVER(playboyi_303) //t:playboyi_303 f:whitestar.c r:playboyi c:playboyi
		DRIVER(playboyi_300) //t:playboyi_300 f:whitestar.c r:playboyi c:playboyi
		DRIVER(playboyi_203) //t:playboyi_203 f:whitestar.c r:playboyi c:playboyi
//SET: playboyl
		DRIVER(playboyl) //t:playboyl f:whitestar.c r: c:
		DRIVER(playboyl_401) //t:playboyl_401 f:whitestar.c r:playboyl c:playboyl
		DRIVER(playboyl_303) //t:playboyl_303 f:whitestar.c r:playboyl c:playboyl
		DRIVER(playboyl_300) //t:playboyl_300 f:whitestar.c r:playboyl c:playboyl
		DRIVER(playboyl_203) //t:playboyl_203 f:whitestar.c r:playboyl c:playboyl
//SET: rctycn
		DRIVER(rctycn) //t:rctycn f:whitestar.c r: c:
		DRIVER(rctycn_701) //t:rctycn_701 f:whitestar.c r:rctycn c:rctycn
		DRIVER(rctycn_600) //t:rctycn_600 f:whitestar.c r:rctycn c:rctycn
		DRIVER(rctycn_400) //t:rctycn_400 f:whitestar.c r:rctycn c:rctycn
		DRIVER(rctnew) //t:rctnew f:whitestar.c r:rctycn c:rctycn
//SET: rctycng
		DRIVER(rctycng) //t:rctycng f:whitestar.c r: c:
		DRIVER(rctycng_701) //t:rctycng_701 f:whitestar.c r:rctycng c:rctycng
		DRIVER(rctycng_400) //t:rctycng_400 f:whitestar.c r:rctycng c:rctycng
//SET: rctycnf
		DRIVER(rctycnf) //t:rctycnf f:whitestar.c r: c:
		DRIVER(rctycnf_701) //t:rctycnf_701 f:whitestar.c r:rctycnf c:rctycnf
		DRIVER(rctycnf_600) //t:rctycnf_600 f:whitestar.c r:rctycnf c:rctycnf
		DRIVER(rctycnf_400) //t:rctycnf_400 f:whitestar.c r:rctycnf c:rctycnf
//SET: rctycni
		DRIVER(rctycni) //t:rctycni f:whitestar.c r: c:
		DRIVER(rctycni_701) //t:rctycni_701 f:whitestar.c r:rctycni c:rctycni
		DRIVER(rctycni_600) //t:rctycni_600 f:whitestar.c r:rctycni c:rctycni
		DRIVER(rctycni_400) //t:rctycni_400 f:whitestar.c r:rctycni c:rctycni
//SET: rctycnl
		DRIVER(rctycnl) //t:rctycnl f:whitestar.c r: c:
		DRIVER(rctycnl_701) //t:rctycnl_701 f:whitestar.c r:rctycnl c:rctycnl
		DRIVER(rctycnl_600) //t:rctycnl_600 f:whitestar.c r:rctycnl c:rctycnl
		DRIVER(rctycnl_400) //t:rctycnl_400 f:whitestar.c r:rctycnl c:rctycnl
//SET: shrkysht
		DRIVER(shrkysht) //t:shrkysht f:whitestar.c r: c:
		DRIVER(shrky_207) //t:shrky_207 f:whitestar.c r:shrkysht c:shrkysht
		DRIVER(shrknew) //t:shrknew f:whitestar.c r:shrkysht c:shrkysht
		DRIVER(shrkygr) //t:shrkygr f:whitestar.c r:shrkysht c:shrkysht
		DRIVER(shrkygr_207) //t:shrkygr_207 f:whitestar.c r:shrkysht c:shrkysht
		DRIVER(shrkyfr) //t:shrkyfr f:whitestar.c r:shrkysht c:shrkysht
		DRIVER(shrkyfr_207) //t:shrkyfr_207 f:whitestar.c r:shrkysht c:shrkysht
		DRIVER(shrkyit) //t:shrkyit f:whitestar.c r:shrkysht c:shrkysht
		DRIVER(shrkyit_207) //t:shrkyit_207 f:whitestar.c r:shrkysht c:shrkysht
//SET: sprk_103
		DRIVER(sprk_103) //t:sprk_103 f:whitestar.c r: c:
		DRIVER(sprk_090) //t:sprk_090 f:whitestar.c r:sprk_103 c:sprk_103
//SET: spacejam
		DRIVER(spacejam) //t:spacejam f:whitestar.c r: c:
		DRIVER(spacejmg) //t:spacejmg f:whitestar.c r:spacejam c:spacejam
		DRIVER(spacejmf) //t:spacejmf f:whitestar.c r:spacejam c:spacejam
		DRIVER(spacejmi) //t:spacejmi f:whitestar.c r:spacejam c:spacejam
//SET: swtril43
		DRIVER(swtril43) //t:swtril43 f:whitestar.c r: c:
		DRIVER(swtril41) //t:swtril41 f:whitestar.c r:swtril43 c:swtril43
//SET: startrp
		DRIVER(startrp) //t:startrp f:whitestar.c r: c:
//SET: strikext
		DRIVER(strikext) //t:strikext f:whitestar.c r: c:
		DRIVER(strknew) //t:strknew f:whitestar.c r:strikext c:strikext
		DRIVER(strxt_uk) //t:strxt_uk f:whitestar.c r:strikext c:strikext
		DRIVER(strxt_gr) //t:strxt_gr f:whitestar.c r:strikext c:strikext
		DRIVER(strxt_fr) //t:strxt_fr f:whitestar.c r:strikext c:strikext
		DRIVER(strxt_it) //t:strxt_it f:whitestar.c r:strikext c:strikext
		DRIVER(strxt_sp) //t:strxt_sp f:whitestar.c r:strikext c:strikext
//SET: term3
		DRIVER(term3) //t:term3 f:whitestar.c r: c:
		DRIVER(term3_205) //t:term3_205 f:whitestar.c r:term3 c:term3
		DRIVER(t3new) //t:t3new f:whitestar.c r:term3 c:term3
		DRIVER(term3g) //t:term3g f:whitestar.c r:term3 c:term3
		DRIVER(term3l) //t:term3l f:whitestar.c r:term3 c:term3
		DRIVER(term3l_205) //t:term3l_205 f:whitestar.c r:term3 c:term3
		DRIVER(term3f) //t:term3f f:whitestar.c r:term3 c:term3
		DRIVER(term3f_205) //t:term3f_205 f:whitestar.c r:term3 c:term3
		DRIVER(term3i) //t:term3i f:whitestar.c r:term3 c:term3
		DRIVER(term3i_205) //t:term3i_205 f:whitestar.c r:term3 c:term3
//SET: jplstw22
		DRIVER(jplstw22) //t:jplstw22 f:whitestar.c r: c:
		DRIVER(jplstw20) //t:jplstw20 f:whitestar.c r:jplstw22 c:jplstw22
//SET: simpprty
		DRIVER(simpprty) //t:simpprty f:whitestar.c r: c:
		DRIVER(simpprty_400) //t:simpprty_400 f:whitestar.c r:simpprty c:simpprty
		DRIVER(simpprty_204) //t:simpprty_204 f:whitestar.c r:simpprty c:simpprty
		DRIVER(simpnew) //t:simpnew f:whitestar.c r:simpprty c:simpprty
//SET: simpprtg
		DRIVER(simpprtg) //t:simpprtg f:whitestar.c r: c:
		DRIVER(simpprtg_400) //t:simpprtg_400 f:whitestar.c r:simpprtg c:simpprtg
//SET: simpprtl
		DRIVER(simpprtl) //t:simpprtl f:whitestar.c r: c:
		DRIVER(simpprtl_400) //t:simpprtl_400 f:whitestar.c r:simpprtl c:simpprtl
		DRIVER(simpprtl_204) //t:simpprtl_204 f:whitestar.c r:simpprtl c:simpprtl
//SET: simpprtf
		DRIVER(simpprtf) //t:simpprtf f:whitestar.c r: c:
		DRIVER(simpprtf_400) //t:simpprtf_400 f:whitestar.c r:simpprtf c:simpprtf
		DRIVER(simpprtf_204) //t:simpprtf_204 f:whitestar.c r:simpprtf c:simpprtf
//SET: simpprti
		DRIVER(simpprti) //t:simpprti f:whitestar.c r: c:
		DRIVER(simpprti_400) //t:simpprti_400 f:whitestar.c r:simpprti c:simpprti
		DRIVER(simpprti_204) //t:simpprti_204 f:whitestar.c r:simpprti c:simpprti
//SET: xfilesp
		DRIVER(xfilesp) //t:xfilesp f:whitestar.c r: c:
		DRIVER(xfiles2) //t:xfiles2 f:whitestar.c r:xfilesp c:xfilesp
//SET: twst_405
		DRIVER(twst_405) //t:twst_405 f:whitestar.c r: c:
		DRIVER(twst_404) //t:twst_404 f:whitestar.c r:twst_405 c:twst_405
		DRIVER(twst_300) //t:twst_300 f:whitestar.c r:twst_405 c:twst_405
//SET: viprsega
		DRIVER(viprsega) //t:viprsega f:whitestar.c r: c:
//SET: titanic
		DRIVER(titanic) //t:titanic f:whitestar.c r: c:
//SET: monopred
		DRIVER(monopred) //t:monopred f:whitestar.c r: c:
//SET: wackadoo
		DRIVER(wackadoo) //t:wackadoo f:whitestar.c r: c:
//SET: elvisp
		DRIVER(elvisp) //t:elvisp f:white_mod.c r: c:
		DRIVER(elvisp4) //t:elvisp4 f:white_mod.c r:elvisp c:elvisp
		DRIVER(elvisp303) //t:elvisp303 f:white_mod.c r:elvisp c:elvisp
		DRIVER(elvisp302) //t:elvisp302 f:white_mod.c r:elvisp c:elvisp
//SET: elvisl
		DRIVER(elvisl) //t:elvisl f:white_mod.c r: c:
		DRIVER(elvisl4) //t:elvisl4 f:white_mod.c r:elvisl c:elvisl
		DRIVER(elvisl303) //t:elvisl303 f:white_mod.c r:elvisl c:elvisl
		DRIVER(elvisl302) //t:elvisl302 f:white_mod.c r:elvisl c:elvisl
//SET: elvisg
		DRIVER(elvisg) //t:elvisg f:white_mod.c r: c:
		DRIVER(elvisg4) //t:elvisg4 f:white_mod.c r:elvisg c:elvisg
		DRIVER(elvisg303) //t:elvisg303 f:white_mod.c r:elvisg c:elvisg
		DRIVER(elvisg302) //t:elvisg302 f:white_mod.c r:elvisg c:elvisg
//SET: elvisf
		DRIVER(elvisf) //t:elvisf f:white_mod.c r: c:
		DRIVER(elvisf4) //t:elvisf4 f:white_mod.c r:elvisf c:elvisf
		DRIVER(elvisf303) //t:elvisf303 f:white_mod.c r:elvisf c:elvisf
		DRIVER(elvisf302) //t:elvisf302 f:white_mod.c r:elvisf c:elvisf
//SET: elvisi
		DRIVER(elvisi) //t:elvisi f:white_mod.c r: c:
		DRIVER(elvisi4) //t:elvisi4 f:white_mod.c r:elvisi c:elvisi
		DRIVER(elvisi303) //t:elvisi303 f:white_mod.c r:elvisi c:elvisi
		DRIVER(elvisi302) //t:elvisi302 f:white_mod.c r:elvisi c:elvisi
//SET: gprix
		DRIVER(gprix) //t:gprix f:white_mod.c r: c:
		DRIVER(gprix_400) //t:gprix_400 f:white_mod.c r:gprix c:gprix
		DRIVER(gprix_340) //t:gprix_340 f:white_mod.c r:gprix c:gprix
		DRIVER(gprix_301) //t:gprix_301 f:white_mod.c r:gprix c:gprix
//SET: gprixg
		DRIVER(gprixg) //t:gprixg f:white_mod.c r: c:
		DRIVER(gprixg_400) //t:gprixg_400 f:white_mod.c r:gprixg c:gprixg
		DRIVER(gprixg_340) //t:gprixg_340 f:white_mod.c r:gprixg c:gprixg
		DRIVER(gprixg_301) //t:gprixg_301 f:white_mod.c r:gprixg c:gprixg
//SET: gprixl
		DRIVER(gprixl) //t:gprixl f:white_mod.c r: c:
		DRIVER(gprixl_400) //t:gprixl_400 f:white_mod.c r:gprixl c:gprixl
		DRIVER(gprixl_340) //t:gprixl_340 f:white_mod.c r:gprixl c:gprixl
		DRIVER(gprixl_301) //t:gprixl_301 f:white_mod.c r:gprixl c:gprixl
//SET: gprixf
		DRIVER(gprixf) //t:gprixf f:white_mod.c r: c:
		DRIVER(gprixf_400) //t:gprixf_400 f:white_mod.c r:gprixf c:gprixf
		DRIVER(gprixf_340) //t:gprixf_340 f:white_mod.c r:gprixf c:gprixf
		DRIVER(gprixf_301) //t:gprixf_301 f:white_mod.c r:gprixf c:gprixf
//SET: gprixi
		DRIVER(gprixi) //t:gprixi f:white_mod.c r: c:
		DRIVER(gprixi_400) //t:gprixi_400 f:white_mod.c r:gprixi c:gprixi
		DRIVER(gprixi_340) //t:gprixi_340 f:white_mod.c r:gprixi c:gprixi
		DRIVER(gprixi_301) //t:gprixi_301 f:white_mod.c r:gprixi c:gprixi
//SET: nascar
		DRIVER(nascar) //t:nascar f:white_mod.c r: c:
		DRIVER(nascar_400) //t:nascar_400 f:white_mod.c r:nascar c:nascar
		DRIVER(nascar_350) //t:nascar_350 f:white_mod.c r:nascar c:nascar
		DRIVER(nascar_340) //t:nascar_340 f:white_mod.c r:nascar c:nascar
		DRIVER(nascar_301) //t:nascar_301 f:white_mod.c r:nascar c:nascar
//SET: nascarl
		DRIVER(nascarl) //t:nascarl f:white_mod.c r: c:
		DRIVER(nascarl_400) //t:nascarl_400 f:white_mod.c r:nascarl c:nascarl
		DRIVER(nascarl_340) //t:nascarl_340 f:white_mod.c r:nascarl c:nascarl
		DRIVER(nascarl_301) //t:nascarl_301 f:white_mod.c r:nascarl c:nascarl
//SET: ripleys
		DRIVER(ripleys) //t:ripleys f:white_mod.c r: c:
		DRIVER(rip310) //t:rip310 f:white_mod.c r:ripleys c:ripleys
		DRIVER(rip302) //t:rip302 f:white_mod.c r:ripleys c:ripleys
		DRIVER(rip300) //t:rip300 f:white_mod.c r:ripleys c:ripleys
//SET: ripleysf
		DRIVER(ripleysf) //t:ripleysf f:white_mod.c r: c:
		DRIVER(ripf310) //t:ripf310 f:white_mod.c r:ripleysf c:ripleysf
		DRIVER(ripf302) //t:ripf302 f:white_mod.c r:ripleysf c:ripleysf
		DRIVER(ripf300) //t:ripf300 f:white_mod.c r:ripleysf c:ripleysf
//SET: ripleysg
		DRIVER(ripleysg) //t:ripleysg f:white_mod.c r: c:
		DRIVER(ripg310) //t:ripg310 f:white_mod.c r:ripleysg c:ripleysg
		DRIVER(ripg302) //t:ripg302 f:white_mod.c r:ripleysg c:ripleysg
		DRIVER(ripg300) //t:ripg300 f:white_mod.c r:ripleysg c:ripleysg
//SET: ripleysi
		DRIVER(ripleysi) //t:ripleysi f:white_mod.c r: c:
		DRIVER(ripi310) //t:ripi310 f:white_mod.c r:ripleysi c:ripleysi
		DRIVER(ripi302) //t:ripi302 f:white_mod.c r:ripleysi c:ripleysi
		DRIVER(ripi300) //t:ripi300 f:white_mod.c r:ripleysi c:ripleysi
//SET: ripleysl
		DRIVER(ripleysl) //t:ripleysl f:white_mod.c r: c:
		DRIVER(ripl310) //t:ripl310 f:white_mod.c r:ripleysl c:ripleysl
		DRIVER(ripl302) //t:ripl302 f:white_mod.c r:ripleysl c:ripleysl
		DRIVER(ripl300) //t:ripl300 f:white_mod.c r:ripleysl c:ripleysl
//SET: lotr
		DRIVER(lotr) //t:lotr f:white_mod.c r: c:
		DRIVER(lotr9) //t:lotr9 f:white_mod.c r:lotr c:lotr
		DRIVER(lotr8) //t:lotr8 f:white_mod.c r:lotr c:lotr
		DRIVER(lotr7) //t:lotr7 f:white_mod.c r:lotr c:lotr
		DRIVER(lotr401) //t:lotr401 f:white_mod.c r:lotr c:lotr
		DRIVER(lotr_le) //t:lotr_le f:white_mod.c r:lotr c:lotr
//SET: lotr_sp
		DRIVER(lotr_sp) //t:lotr_sp f:white_mod.c r: c:
		DRIVER(lotr_sp9) //t:lotr_sp9 f:white_mod.c r:lotr_sp c:lotr_sp
		DRIVER(lotr_sp8) //t:lotr_sp8 f:white_mod.c r:lotr_sp c:lotr_sp
		DRIVER(lotr_sp7) //t:lotr_sp7 f:white_mod.c r:lotr_sp c:lotr_sp
		DRIVER(lotr_sp401) //t:lotr_sp401 f:white_mod.c r:lotr_sp c:lotr_sp
//SET: lotr_gr
		DRIVER(lotr_gr) //t:lotr_gr f:white_mod.c r: c:
		DRIVER(lotr_gr9) //t:lotr_gr9 f:white_mod.c r:lotr_gr c:lotr_gr
		DRIVER(lotr_gr8) //t:lotr_gr8 f:white_mod.c r:lotr_gr c:lotr_gr
		DRIVER(lotr_gr7) //t:lotr_gr7 f:white_mod.c r:lotr_gr c:lotr_gr
		DRIVER(lotr_gr401) //t:lotr_gr401 f:white_mod.c r:lotr_gr c:lotr_gr
//SET: lotr_fr
		DRIVER(lotr_fr) //t:lotr_fr f:white_mod.c r: c:
		DRIVER(lotr_fr9) //t:lotr_fr9 f:white_mod.c r:lotr_fr c:lotr_fr
		DRIVER(lotr_fr8) //t:lotr_fr8 f:white_mod.c r:lotr_fr c:lotr_fr
		DRIVER(lotr_fr7) //t:lotr_fr7 f:white_mod.c r:lotr_fr c:lotr_fr
		DRIVER(lotr_fr401) //t:lotr_fr401 f:white_mod.c r:lotr_fr c:lotr_fr
//SET: lotr_it
		DRIVER(lotr_it) //t:lotr_it f:white_mod.c r: c:
		DRIVER(lotr_it9) //t:lotr_it9 f:white_mod.c r:lotr_it c:lotr_it
		DRIVER(lotr_it8) //t:lotr_it8 f:white_mod.c r:lotr_it c:lotr_it
		DRIVER(lotr_it7) //t:lotr_it7 f:white_mod.c r:lotr_it c:lotr_it
		DRIVER(lotr_it401) //t:lotr_it401 f:white_mod.c r:lotr_it c:lotr_it
//SET: sopranos
		DRIVER(sopranos) //t:sopranos f:white_mod.c r: c:
		DRIVER(sopranos_300) //t:sopranos_300 f:white_mod.c r:sopranos c:sopranos
		DRIVER(sopranos_204) //t:sopranos_204 f:white_mod.c r:sopranos c:sopranos
//SET: sopranog
		DRIVER(sopranog) //t:sopranog f:white_mod.c r: c:
		DRIVER(sopranog_300) //t:sopranog_300 f:white_mod.c r:sopranog c:sopranog
		DRIVER(sopranog_107) //t:sopranog_107 f:white_mod.c r:sopranog c:sopranog
//SET: sopranof
		DRIVER(sopranof) //t:sopranof f:white_mod.c r: c:
		DRIVER(sopranof_300) //t:sopranof_300 f:white_mod.c r:sopranof c:sopranof
		DRIVER(sopranof_107) //t:sopranof_107 f:white_mod.c r:sopranof c:sopranof
//SET: sopranol
		DRIVER(sopranol) //t:sopranol f:white_mod.c r: c:
		DRIVER(sopranol_300) //t:sopranol_300 f:white_mod.c r:sopranol c:sopranol
		DRIVER(sopranol_107) //t:sopranol_107 f:white_mod.c r:sopranol c:sopranol
//SET: sopranoi
		DRIVER(sopranoi) //t:sopranoi f:white_mod.c r: c:
		DRIVER(sopranoi_300) //t:sopranoi_300 f:white_mod.c r:sopranoi c:sopranoi
		DRIVER(sopranoi_107) //t:sopranoi_107 f:white_mod.c r:sopranoi c:sopranoi
//SET: aftor
		DRIVER(aftor) //t:aftor f:wico.c r: c:
//SET: tf95_12
		DRIVER(tf95_12) //t:tf95_12 f:wpc_95.c r: c:
//SET: afm_113
		DRIVER(afm_113) //t:afm_113 f:wpc_95.c r: c:
		DRIVER(afm_113b) //t:afm_113b f:wpc_95.c r:afm_113 c:afm_113
		DRIVER(afm_11) //t:afm_11 f:wpc_95.c r:afm_113 c:afm_113
		DRIVER(afm_11u) //t:afm_11u f:wpc_95.c r:afm_113 c:afm_113
		DRIVER(afm_10) //t:afm_10 f:wpc_95.c r:afm_113 c:afm_113
//SET: cc_13
		DRIVER(cc_13) //t:cc_13 f:wpc_95.c r: c:
		DRIVER(cc_12) //t:cc_12 f:wpc_95.c r:cc_13 c:cc_13
//SET: cv_14
		DRIVER(cv_14) //t:cv_14 f:wpc_95.c r: c:
		DRIVER(cv_20h) //t:cv_20h f:wpc_95.c r:cv_14 c:cv_14
		DRIVER(cv_10) //t:cv_10 f:wpc_95.c r:cv_14 c:cv_14
		DRIVER(cv_11) //t:cv_11 f:wpc_95.c r:cv_14 c:cv_14
		DRIVER(cv_13) //t:cv_13 f:wpc_95.c r:cv_14 c:cv_14
//SET: congo_21
		DRIVER(congo_21) //t:congo_21 f:wpc_95.c r: c:
		DRIVER(congo_20) //t:congo_20 f:wpc_95.c r:congo_21 c:congo_21
//SET: jy_12
		DRIVER(jy_12) //t:jy_12 f:wpc_95.c r: c:
		DRIVER(jy_11) //t:jy_11 f:wpc_95.c r:jy_12 c:jy_12
		DRIVER(jy_03) //t:jy_03 f:wpc_95.c r:jy_12 c:jy_12
//SET: mm_10
		DRIVER(mm_10) //t:mm_10 f:wpc_95.c r: c:
		DRIVER(mm_10u) //t:mm_10u f:wpc_95.c r:mm_10 c:mm_10
		DRIVER(mm_109) //t:mm_109 f:wpc_95.c r:mm_10 c:mm_10
		DRIVER(mm_109b) //t:mm_109b f:wpc_95.c r:mm_10 c:mm_10
		DRIVER(mm_109c) //t:mm_109c f:wpc_95.c r:mm_10 c:mm_10
		DRIVER(mm_05) //t:mm_05 f:wpc_95.c r:mm_10 c:mm_10
//SET: mb_10
		DRIVER(mb_10) //t:mb_10 f:wpc_95.c r: c:
		DRIVER(mb_106) //t:mb_106 f:wpc_95.c r:mb_10 c:mb_10
		DRIVER(mb_106b) //t:mb_106b f:wpc_95.c r:mb_10 c:mb_10
//SET: nbaf_31
		DRIVER(nbaf_31) //t:nbaf_31 f:wpc_95.c r: c:
		DRIVER(nbaf_31a) //t:nbaf_31a f:wpc_95.c r:nbaf_31 c:nbaf_31
		DRIVER(nbaf_11s) //t:nbaf_11s f:wpc_95.c r:nbaf_31 c:nbaf_31
		DRIVER(nbaf_11) //t:nbaf_11 f:wpc_95.c r:nbaf_31 c:nbaf_31
		DRIVER(nbaf_11a) //t:nbaf_11a f:wpc_95.c r:nbaf_31 c:nbaf_31
		DRIVER(nbaf_115) //t:nbaf_115 f:wpc_95.c r:nbaf_31 c:nbaf_31
		DRIVER(nbaf_21) //t:nbaf_21 f:wpc_95.c r:nbaf_31 c:nbaf_31
		DRIVER(nbaf_22) //t:nbaf_22 f:wpc_95.c r:nbaf_31 c:nbaf_31
		DRIVER(nbaf_23) //t:nbaf_23 f:wpc_95.c r:nbaf_31 c:nbaf_31
//SET: ngg_13
		DRIVER(ngg_13) //t:ngg_13 f:wpc_95.c r: c:
		DRIVER(ngg_p06) //t:ngg_p06 f:wpc_95.c r:ngg_13 c:ngg_13
		DRIVER(ngg_10) //t:ngg_10 f:wpc_95.c r:ngg_13 c:ngg_13
//SET: sc_18
		DRIVER(sc_18) //t:sc_18 f:wpc_95.c r: c:
		DRIVER(sc_18n) //t:sc_18n f:wpc_95.c r:sc_18 c:sc_18
		DRIVER(sc_18s2) //t:sc_18s2 f:wpc_95.c r:sc_18 c:sc_18
		DRIVER(sc_17) //t:sc_17 f:wpc_95.c r:sc_18 c:sc_18
		DRIVER(sc_17n) //t:sc_17n f:wpc_95.c r:sc_18 c:sc_18
		DRIVER(sc_14) //t:sc_14 f:wpc_95.c r:sc_18 c:sc_18
//SET: ss_15
		DRIVER(ss_15) //t:ss_15 f:wpc_95.c r: c:
		DRIVER(ss_14) //t:ss_14 f:wpc_95.c r:ss_15 c:ss_15
		DRIVER(ss_12) //t:ss_12 f:wpc_95.c r:ss_15 c:ss_15
		DRIVER(ss_03) //t:ss_03 f:wpc_95.c r:ss_15 c:ss_15
//SET: totan_14
		DRIVER(totan_14) //t:totan_14 f:wpc_95.c r: c:
		DRIVER(totan_13) //t:totan_13 f:wpc_95.c r:totan_14 c:totan_14
		DRIVER(totan_12) //t:totan_12 f:wpc_95.c r:totan_14 c:totan_14
		DRIVER(totan_04) //t:totan_04 f:wpc_95.c r:totan_14 c:totan_14
//SET: cp_16
		DRIVER(cp_16) //t:cp_16 f:wpc_95.c r: c:
		DRIVER(cp_15) //t:cp_15 f:wpc_95.c r:cp_16 c:cp_16
//SET: ttt_10
		DRIVER(ttt_10) //t:ttt_10 f:wpc_95.c r: c:
//SET: tfa_13
		DRIVER(tfa_13) //t:tfa_13 f:wpc_an.c r: c:
//SET: fh_l9
		DRIVER(fh_l9) //t:fh_l9 f:wpc_an.c r: c:
		DRIVER(fh_l9b) //t:fh_l9b f:wpc_an.c r:fh_l9 c:fh_l9
		DRIVER(fh_905h) //t:fh_905h f:wpc_an.c r:fh_l9 c:fh_l9
		DRIVER(fh_l3) //t:fh_l3 f:wpc_an.c r:fh_l9 c:fh_l9
		DRIVER(fh_l4) //t:fh_l4 f:wpc_an.c r:fh_l9 c:fh_l9
		DRIVER(fh_l5) //t:fh_l5 f:wpc_an.c r:fh_l9 c:fh_l9
//SET: hd_l3
		DRIVER(hd_l3) //t:hd_l3 f:wpc_an.c r: c:
		DRIVER(hd_l1) //t:hd_l1 f:wpc_an.c r:hd_l3 c:hd_l3
//SET: bop_l7
		DRIVER(bop_l7) //t:bop_l7 f:wpc_an.c r: c:
		DRIVER(bop_l6) //t:bop_l6 f:wpc_an.c r:bop_l7 c:bop_l7
		DRIVER(bop_l5) //t:bop_l5 f:wpc_an.c r:bop_l7 c:bop_l7
		DRIVER(bop_l4) //t:bop_l4 f:wpc_an.c r:bop_l7 c:bop_l7
		DRIVER(bop_l3) //t:bop_l3 f:wpc_an.c r:bop_l7 c:bop_l7
		DRIVER(bop_l2) //t:bop_l2 f:wpc_an.c r:bop_l7 c:bop_l7
//SET: dm_lx4
		DRIVER(dm_lx4) //t:dm_lx4 f:wpc_dcs.c r: c:
		DRIVER(dm_pa2) //t:dm_pa2 f:wpc_dcs.c r:dm_lx4 c:dm_lx4
		DRIVER(dm_px5) //t:dm_px5 f:wpc_dcs.c r:dm_lx4 c:dm_lx4
		DRIVER(dm_la1) //t:dm_la1 f:wpc_dcs.c r:dm_lx4 c:dm_lx4
		DRIVER(dm_lx3) //t:dm_lx3 f:wpc_dcs.c r:dm_lx4 c:dm_lx4
		DRIVER(dm_h5) //t:dm_h5 f:wpc_dcs.c r:dm_lx4 c:dm_lx4
		DRIVER(dm_h6) //t:dm_h6 f:wpc_dcs.c r:dm_lx4 c:dm_lx4
//SET: ij_l7
		DRIVER(ij_l7) //t:ij_l7 f:wpc_dcs.c r: c:
		DRIVER(ij_lg7) //t:ij_lg7 f:wpc_dcs.c r:ij_l7 c:ij_l7
		DRIVER(ij_l6) //t:ij_l6 f:wpc_dcs.c r:ij_l7 c:ij_l7
		DRIVER(ij_l5) //t:ij_l5 f:wpc_dcs.c r:ij_l7 c:ij_l7
		DRIVER(ij_l4) //t:ij_l4 f:wpc_dcs.c r:ij_l7 c:ij_l7
		DRIVER(ij_l3) //t:ij_l3 f:wpc_dcs.c r:ij_l7 c:ij_l7
//SET: jd_l7
		DRIVER(jd_l7) //t:jd_l7 f:wpc_dcs.c r: c:
		DRIVER(jd_l1) //t:jd_l1 f:wpc_dcs.c r:jd_l7 c:jd_l7
		DRIVER(jd_l6) //t:jd_l6 f:wpc_dcs.c r:jd_l7 c:jd_l7
//SET: pop_lx5
		DRIVER(pop_lx5) //t:pop_lx5 f:wpc_dcs.c r: c:
		DRIVER(pop_pa3) //t:pop_pa3 f:wpc_dcs.c r:pop_lx5 c:pop_lx5
//SET: sttng_l7
		DRIVER(sttng_l7) //t:sttng_l7 f:wpc_dcs.c r: c:
		DRIVER(sttng_x7) //t:sttng_x7 f:wpc_dcs.c r:sttng_l7 c:sttng_l7
		DRIVER(sttng_p5) //t:sttng_p5 f:wpc_dcs.c r:sttng_l7 c:sttng_l7
		DRIVER(sttng_s7) //t:sttng_s7 f:wpc_dcs.c r:sttng_l7 c:sttng_l7
		DRIVER(sttng_g7) //t:sttng_g7 f:wpc_dcs.c r:sttng_l7 c:sttng_l7
		DRIVER(sttng_l1) //t:sttng_l1 f:wpc_dcs.c r:sttng_l7 c:sttng_l7
		DRIVER(sttng_l2) //t:sttng_l2 f:wpc_dcs.c r:sttng_l7 c:sttng_l7
//SET: afv_l4
		DRIVER(afv_l4) //t:afv_l4 f:wpc_dcs.c r: c:
//SET: tfdmd_l3
		DRIVER(tfdmd_l3) //t:tfdmd_l3 f:wpc_dot.c r: c:
//SET: gi_l9
		DRIVER(gi_l9) //t:gi_l9 f:wpc_dot.c r: c:
		DRIVER(gi_l3) //t:gi_l3 f:wpc_dot.c r:gi_l9 c:gi_l9
		DRIVER(gi_l4) //t:gi_l4 f:wpc_dot.c r:gi_l9 c:gi_l9
		DRIVER(gi_l6) //t:gi_l6 f:wpc_dot.c r:gi_l9 c:gi_l9
//SET: hshot_p8
		DRIVER(hshot_p8) //t:hshot_p8 f:wpc_dot.c r: c:
//SET: hurr_l2
		DRIVER(hurr_l2) //t:hurr_l2 f:wpc_dot.c r: c:
//SET: pz_f4
		DRIVER(pz_f4) //t:pz_f4 f:wpc_dot.c r: c:
		DRIVER(pz_l1) //t:pz_l1 f:wpc_dot.c r:pz_f4 c:pz_f4
		DRIVER(pz_l2) //t:pz_l2 f:wpc_dot.c r:pz_f4 c:pz_f4
		DRIVER(pz_l3) //t:pz_l3 f:wpc_dot.c r:pz_f4 c:pz_f4
//SET: sf_l1
		DRIVER(sf_l1) //t:sf_l1 f:wpc_dot.c r: c:
//SET: t2_l8
		DRIVER(t2_l8) //t:t2_l8 f:wpc_dot.c r: c:
		DRIVER(t2_l6) //t:t2_l6 f:wpc_dot.c r:t2_l8 c:t2_l8
		DRIVER(t2_p2f) //t:t2_p2f f:wpc_dot.c r:t2_l8 c:t2_l8
		DRIVER(t2_l4) //t:t2_l4 f:wpc_dot.c r:t2_l8 c:t2_l8
		DRIVER(t2_l3) //t:t2_l3 f:wpc_dot.c r:t2_l8 c:t2_l8
		DRIVER(t2_l2) //t:t2_l2 f:wpc_dot.c r:t2_l8 c:t2_l8
//SET: taf_l5
		DRIVER(taf_l5) //t:taf_l5 f:wpc_flip1.c r: c:
		DRIVER(taf_p2) //t:taf_p2 f:wpc_flip1.c r:taf_l5 c:taf_l5
		DRIVER(taf_l1) //t:taf_l1 f:wpc_flip1.c r:taf_l5 c:taf_l5
		DRIVER(taf_l2) //t:taf_l2 f:wpc_flip1.c r:taf_l5 c:taf_l5
		DRIVER(taf_l3) //t:taf_l3 f:wpc_flip1.c r:taf_l5 c:taf_l5
		DRIVER(taf_l4) //t:taf_l4 f:wpc_flip1.c r:taf_l5 c:taf_l5
		DRIVER(taf_l7) //t:taf_l7 f:wpc_flip1.c r:taf_l5 c:taf_l5
		DRIVER(taf_l6) //t:taf_l6 f:wpc_flip1.c r:taf_l5 c:taf_l5
		DRIVER(taf_h4) //t:taf_h4 f:wpc_flip1.c r:taf_l5 c:taf_l5
//SET: br_l4
		DRIVER(br_l4) //t:br_l4 f:wpc_flip2.c r: c:
		DRIVER(br_p17) //t:br_p17 f:wpc_flip2.c r:br_l4 c:br_l4
		DRIVER(br_l1) //t:br_l1 f:wpc_flip2.c r:br_l4 c:br_l4
		DRIVER(br_l3) //t:br_l3 f:wpc_flip2.c r:br_l4 c:br_l4
//SET: drac_l1
		DRIVER(drac_l1) //t:drac_l1 f:wpc_flip2.c r: c:
		DRIVER(drac_p11) //t:drac_p11 f:wpc_flip2.c r:drac_l1 c:drac_l1
//SET: cftbl_l4
		DRIVER(cftbl_l4) //t:cftbl_l4 f:wpc_flip2.c r: c:
		DRIVER(cftbl_l3) //t:cftbl_l3 f:wpc_flip2.c r:cftbl_l4 c:cftbl_l4
//SET: dw_l2
		DRIVER(dw_l2) //t:dw_l2 f:wpc_flip2.c r: c:
		DRIVER(dw_l1) //t:dw_l1 f:wpc_flip2.c r:dw_l2 c:dw_l2
		DRIVER(dw_p5) //t:dw_p5 f:wpc_flip2.c r:dw_l2 c:dw_l2
//SET: ft_l5
		DRIVER(ft_l5) //t:ft_l5 f:wpc_flip2.c r: c:
		DRIVER(ft_l3) //t:ft_l3 f:wpc_flip2.c r:ft_l5 c:ft_l5
		DRIVER(ft_l4) //t:ft_l4 f:wpc_flip2.c r:ft_l5 c:ft_l5
		DRIVER(ft_p4) //t:ft_p4 f:wpc_flip2.c r:ft_l5 c:ft_l5
//SET: tafg_lx3
		DRIVER(tafg_lx3) //t:tafg_lx3 f:wpc_flip2.c r: c:
		DRIVER(tafg_h3) //t:tafg_h3 f:wpc_flip2.c r:tafg_lx3 c:tafg_lx3
		DRIVER(tafg_la2) //t:tafg_la2 f:wpc_flip2.c r:tafg_lx3 c:tafg_lx3
		DRIVER(tafg_la3) //t:tafg_la3 f:wpc_flip2.c r:tafg_lx3 c:tafg_lx3
//SET: gw_l5
		DRIVER(gw_l5) //t:gw_l5 f:wpc_flip2.c r: c:
		DRIVER(gw_pc) //t:gw_pc f:wpc_flip2.c r:gw_l5 c:gw_l5
		DRIVER(gw_l1) //t:gw_l1 f:wpc_flip2.c r:gw_l5 c:gw_l5
		DRIVER(gw_l2) //t:gw_l2 f:wpc_flip2.c r:gw_l5 c:gw_l5
		DRIVER(gw_l3) //t:gw_l3 f:wpc_flip2.c r:gw_l5 c:gw_l5
		DRIVER(gw_p7) //t:gw_p7 f:wpc_flip2.c r:gw_l5 c:gw_l5
//SET: tz_92
		DRIVER(tz_92) //t:tz_92 f:wpc_flip2.c r: c:
		DRIVER(tz_94h) //t:tz_94h f:wpc_flip2.c r:tz_92 c:tz_92
		DRIVER(tz_94ch) //t:tz_94ch f:wpc_flip2.c r:tz_92 c:tz_92
		DRIVER(tz_pa1) //t:tz_pa1 f:wpc_flip2.c r:tz_92 c:tz_92
		DRIVER(tz_p3) //t:tz_p3 f:wpc_flip2.c r:tz_92 c:tz_92
		DRIVER(tz_p4) //t:tz_p4 f:wpc_flip2.c r:tz_92 c:tz_92
		DRIVER(tz_l1) //t:tz_l1 f:wpc_flip2.c r:tz_92 c:tz_92
		DRIVER(tz_l2) //t:tz_l2 f:wpc_flip2.c r:tz_92 c:tz_92
		DRIVER(tz_ifpa) //t:tz_ifpa f:wpc_flip2.c r:tz_92 c:tz_92
		DRIVER(tz_l3) //t:tz_l3 f:wpc_flip2.c r:tz_92 c:tz_92
		DRIVER(tz_l4) //t:tz_l4 f:wpc_flip2.c r:tz_92 c:tz_92
		DRIVER(tz_h7) //t:tz_h7 f:wpc_flip2.c r:tz_92 c:tz_92
		DRIVER(tz_h8) //t:tz_h8 f:wpc_flip2.c r:tz_92 c:tz_92
//SET: ww_l5
		DRIVER(ww_l5) //t:ww_l5 f:wpc_flip2.c r: c:
		DRIVER(ww_lh6) //t:ww_lh6 f:wpc_flip2.c r:ww_l5 c:ww_l5
		DRIVER(ww_lh5) //t:ww_lh5 f:wpc_flip2.c r:ww_l5 c:ww_l5
		DRIVER(ww_l4) //t:ww_l4 f:wpc_flip2.c r:ww_l5 c:ww_l5
		DRIVER(ww_l3) //t:ww_l3 f:wpc_flip2.c r:ww_l5 c:ww_l5
		DRIVER(ww_l2) //t:ww_l2 f:wpc_flip2.c r:ww_l5 c:ww_l5
		DRIVER(ww_p8) //t:ww_p8 f:wpc_flip2.c r:ww_l5 c:ww_l5
		DRIVER(ww_p1) //t:ww_p1 f:wpc_flip2.c r:ww_l5 c:ww_l5
//SET: strik_l4
		DRIVER(strik_l4) //t:strik_l4 f:wpc_flip2.c r: c:
//SET: lc_11
		DRIVER(lc_11) //t:lc_11 f:wpc_flip2.c r: c:
//SET: corv_21
		DRIVER(corv_21) //t:corv_21 f:wpc_s.c r: c:
		DRIVER(corv_px4) //t:corv_px4 f:wpc_s.c r:corv_21 c:corv_21
		DRIVER(corv_lx1) //t:corv_lx1 f:wpc_s.c r:corv_21 c:corv_21
//SET: dh_lx2
		DRIVER(dh_lx2) //t:dh_lx2 f:wpc_s.c r: c:
//SET: i500_11r
		DRIVER(i500_11r) //t:i500_11r f:wpc_s.c r: c:
		DRIVER(i500_11b) //t:i500_11b f:wpc_s.c r:i500_11r c:i500_11r
//SET: jb_10r
		DRIVER(jb_10r) //t:jb_10r f:wpc_s.c r: c:
		DRIVER(jb_10b) //t:jb_10b f:wpc_s.c r:jb_10r c:jb_10r
//SET: jm_12r
		DRIVER(jm_12r) //t:jm_12r f:wpc_s.c r: c:
		DRIVER(jm_12b) //t:jm_12b f:wpc_s.c r:jm_12r c:jm_12r
//SET: nf_23x
		DRIVER(nf_23x) //t:nf_23x f:wpc_s.c r: c:
		DRIVER(nf_23) //t:nf_23 f:wpc_s.c r:nf_23x c:nf_23x
		DRIVER(nf_23f) //t:nf_23f f:wpc_s.c r:nf_23x c:nf_23x
		DRIVER(nf_22) //t:nf_22 f:wpc_s.c r:nf_23x c:nf_23x
		DRIVER(nf_20) //t:nf_20 f:wpc_s.c r:nf_23x c:nf_23x
//SET: rs_l6
		DRIVER(rs_l6) //t:rs_l6 f:wpc_s.c r: c:
		DRIVER(rs_la5) //t:rs_la5 f:wpc_s.c r:rs_l6 c:rs_l6
		DRIVER(rs_lx5) //t:rs_lx5 f:wpc_s.c r:rs_l6 c:rs_l6
		DRIVER(rs_la4) //t:rs_la4 f:wpc_s.c r:rs_l6 c:rs_l6
		DRIVER(rs_lx4) //t:rs_lx4 f:wpc_s.c r:rs_l6 c:rs_l6
		DRIVER(rs_lx3) //t:rs_lx3 f:wpc_s.c r:rs_l6 c:rs_l6
		DRIVER(rs_lx2) //t:rs_lx2 f:wpc_s.c r:rs_l6 c:rs_l6
//SET: fs_lx5
		DRIVER(fs_lx5) //t:fs_lx5 f:wpc_s.c r: c:
		DRIVER(fs_lx2) //t:fs_lx2 f:wpc_s.c r:fs_lx5 c:fs_lx5
		DRIVER(fs_sp2) //t:fs_sp2 f:wpc_s.c r:fs_lx5 c:fs_lx5
		DRIVER(fs_lx4) //t:fs_lx4 f:wpc_s.c r:fs_lx5 c:fs_lx5
//SET: ts_lx5
		DRIVER(ts_lx5) //t:ts_lx5 f:wpc_s.c r: c:
		DRIVER(ts_lh6) //t:ts_lh6 f:wpc_s.c r:ts_lx5 c:ts_lx5
		DRIVER(ts_lx4) //t:ts_lx4 f:wpc_s.c r:ts_lx5 c:ts_lx5
		DRIVER(ts_la4) //t:ts_la4 f:wpc_s.c r:ts_lx5 c:ts_lx5
		DRIVER(ts_la2) //t:ts_la2 f:wpc_s.c r:ts_lx5 c:ts_lx5
		DRIVER(ts_pa1) //t:ts_pa1 f:wpc_s.c r:ts_lx5 c:ts_lx5
		DRIVER(ts_lf6) //t:ts_lf6 f:wpc_s.c r:ts_lx5 c:ts_lx5
		DRIVER(ts_lm6) //t:ts_lm6 f:wpc_s.c r:ts_lx5 c:ts_lx5
//SET: tom_13
		DRIVER(tom_13) //t:tom_13 f:wpc_s.c r: c:
		DRIVER(tom_14h) //t:tom_14h f:wpc_s.c r:tom_13 c:tom_13
		DRIVER(tom_12) //t:tom_12 f:wpc_s.c r:tom_13 c:tom_13
		DRIVER(tom_06) //t:tom_06 f:wpc_s.c r:tom_13 c:tom_13
//SET: wd_12
		DRIVER(wd_12) //t:wd_12 f:wpc_s.c r: c:
		DRIVER(wd_12g) //t:wd_12g f:wpc_s.c r:wd_12 c:wd_12
		DRIVER(wd_11) //t:wd_11 f:wpc_s.c r:wd_12 c:wd_12
		DRIVER(wd_10r) //t:wd_10r f:wpc_s.c r:wd_12 c:wd_12
		DRIVER(wd_10g) //t:wd_10g f:wpc_s.c r:wd_12 c:wd_12
		DRIVER(wd_10f) //t:wd_10f f:wpc_s.c r:wd_12 c:wd_12
		DRIVER(wd_03r) //t:wd_03r f:wpc_s.c r:wd_12 c:wd_12
		DRIVER(wd_048r) //t:wd_048r f:wpc_s.c r:wd_12 c:wd_12
//SET: wcs_l2
		DRIVER(wcs_l2) //t:wcs_l2 f:wpc_s.c r: c:
		DRIVER(wcs_p2) //t:wcs_p2 f:wpc_s.c r:wcs_l2 c:wcs_l2
		DRIVER(wcs_p3) //t:wcs_p3 f:wpc_s.c r:wcs_l2 c:wcs_l2
//SET: tfs_12
		DRIVER(tfs_12) //t:tfs_12 f:wpc_s.c r: c:
//SET: ewf
		DRIVER(ewf) //t:ewf f:zac_1.c r: c:
//SET: firemntn
		DRIVER(firemntn) //t:firemntn f:zac_1.c r: c:
//SET: futurwld
		DRIVER(futurwld) //t:futurwld f:zac_1.c r: c:
//SET: hotwheel
		DRIVER(hotwheel) //t:hotwheel f:zac_1.c r: c:
//SET: hod
		DRIVER(hod) //t:hod f:zac_1.c r: c:
//SET: locomotp
		DRIVER(locomotp) //t:locomotp f:zac_1.c r: c:
//SET: strapids
		DRIVER(strapids) //t:strapids f:zac_1.c r: c:
//SET: sshtlzac
		DRIVER(sshtlzac) //t:sshtlzac f:zac_1.c r: c:
//SET: stargod
		DRIVER(stargod) //t:stargod f:zac_1.c r: c:
		DRIVER(stargoda) //t:stargoda f:zac_1.c r:stargod c:stargod
//SET: wsports
		DRIVER(wsports) //t:wsports f:zac_1.c r: c:
//SET: bbeltzac
		DRIVER(bbeltzac) //t:bbeltzac f:zac_2.c r: c:
//SET: clown
		DRIVER(clown) //t:clown f:zac_2.c r: c:
//SET: dvlrider
		DRIVER(dvlrider) //t:dvlrider f:zac_2.c r: c:
		DRIVER(dvlrideri) //t:dvlrideri f:zac_2.c r:dvlrider c:dvlrider
		DRIVER(dvlriderg) //t:dvlriderg f:zac_2.c r:dvlrider c:dvlrider
//SET: farfalla
		DRIVER(farfalla) //t:farfalla f:zac_2.c r: c:
		DRIVER(farfallai) //t:farfallai f:zac_2.c r:farfalla c:farfalla
		DRIVER(farfallag) //t:farfallag f:zac_2.c r:farfalla c:farfalla
//SET: mcastle
		DRIVER(mcastle) //t:mcastle f:zac_2.c r: c:
		DRIVER(mcastlei) //t:mcastlei f:zac_2.c r:mcastle c:mcastle
		DRIVER(mcastleg) //t:mcastleg f:zac_2.c r:mcastle c:mcastle
		DRIVER(mcastlef) //t:mcastlef f:zac_2.c r:mcastle c:mcastle
//SET: mexico
		DRIVER(mexico) //t:mexico f:zac_2.c r: c:
//SET: nstrphnx
		DRIVER(nstrphnx) //t:nstrphnx f:zac_2.c r: c:
//SET: pinchamp
		DRIVER(pinchamp) //t:pinchamp f:zac_2.c r: c:
		DRIVER(pinchampg) //t:pinchampg f:zac_2.c r:pinchamp c:pinchamp
		DRIVER(pinchampi) //t:pinchampi f:zac_2.c r:pinchamp c:pinchamp
		DRIVER(pinchamp7) //t:pinchamp7 f:zac_2.c r:pinchamp c:pinchamp
		DRIVER(pinchamp7g) //t:pinchamp7g f:zac_2.c r:pinchamp c:pinchamp
		DRIVER(pinchamp7i) //t:pinchamp7i f:zac_2.c r:pinchamp c:pinchamp
//SET: poolcham
		DRIVER(poolcham) //t:poolcham f:zac_2.c r: c:
		DRIVER(poolchami) //t:poolchami f:zac_2.c r:poolcham c:poolcham
		DRIVER(poolchama) //t:poolchama f:zac_2.c r:poolcham c:poolcham
//SET: robot
		DRIVER(robot) //t:robot f:zac_2.c r: c:
		DRIVER(roboti) //t:roboti f:zac_2.c r:robot c:robot
		DRIVER(robotg) //t:robotg f:zac_2.c r:robot c:robot
		DRIVER(robotf) //t:robotf f:zac_2.c r:robot c:robot
//SET: scram_tp
		DRIVER(scram_tp) //t:scram_tp f:zac_2.c r: c:
//SET: socrking
		DRIVER(socrking) //t:socrking f:zac_2.c r: c:
		DRIVER(socrkingi) //t:socrkingi f:zac_2.c r:socrking c:socrking
		DRIVER(socrkingg) //t:socrkingg f:zac_2.c r:socrking c:socrking
//SET: spookyp
		DRIVER(spookyp) //t:spookyp f:zac_2.c r: c:
		DRIVER(spookyi) //t:spookyi f:zac_2.c r:spookyp c:spookyp
//SET: strsphnx
		DRIVER(strsphnx) //t:strsphnx f:zac_2.c r: c:
//SET: tmachzac
		DRIVER(tmachzac) //t:tmachzac f:zac_2.c r: c:
		DRIVER(tmachzacg) //t:tmachzacg f:zac_2.c r:tmachzac c:tmachzac
		DRIVER(tmachzacf) //t:tmachzacf f:zac_2.c r:tmachzac c:tmachzac
//SET: zankor
		DRIVER(zankor) //t:zankor f:zac_2.c r: c:
//SET: skijump
		DRIVER(skijump) //t:skijump f:zac_proto.c r: c:
//SET: spacecty
		DRIVER(spacecty) //t:spacecty f:zac_proto.c r: c:
//SET: strike
		DRIVER(strike) //t:strike f:zac_proto.c r: c:
#endif

#endif	/* DRIVER_RECURSIVE */

