cmake_minimum_required(VERSION 3.20)
project(finalProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")

add_executable(mainExecutable
    main.cpp
    arcaneBlast.cpp
    armor.cpp
    backstab.cpp
    bludgeon.cpp
    boss.cpp
    character.cpp
    characterSelect.cpp
    city.cpp
    combat.cpp
    cutthroat.cpp
    encounterManager.cpp
    enemy.cpp
    finalBoss.cpp
    game.cpp
    incinerate.cpp
    inGameMenu.cpp
    inventory.cpp
    item.cpp
    itemManager.cpp
    lifeleech.cpp
    mage.cpp
    orc.cpp
    orcBoss.cpp
    pickpocket.cpp
    pirate.cpp
    pirateBoss.cpp
    rogue.cpp
    royalGuard.cpp
    screen.cpp
    shatter.cpp
    slam.cpp
    spell.cpp
    startMenu.cpp
    statsManager.cpp
    travel.cpp
    trinket.cpp
    user.cpp
    warrior.cpp
    weapon.cpp
    goblin.cpp
    goblinBoss.cpp
)