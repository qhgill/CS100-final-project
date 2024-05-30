cmake_minimum_required(VERSION 3.20)
project(finalProject)

add_executable(runEnemyTests
    enemyTesting.cpp
    ../source/enemy.cpp
)

add_executable(runWeaponTests
    weaponTesting.cpp
    ../source/weapon.cpp
    ../source/item.cpp
)

add_executable(runCharacterTests
    characterTests.cpp
    ../source/character.cpp
    ../source/spell.cpp
)

add_executable(runSpellTests
	spellsTests.cpp
	../source/spell.cpp
)

add_executable(runScreenTests
    screensTest.cpp
    ../source/screen.cpp
)

add_executable(runItemTests
    itemTests.cpp 
    ../source/item.cpp
)

add_executable(runRogueTests
    rogueTests.cpp
    ../source/character.cpp
    ../source/enemy.cpp
    ../source/spell.cpp
    ../source/rogue.cpp
    ../source/backstab.cpp
    ../source/pickpocket.cpp
    ../source/cutthroat.cpp
)

add_executable(runWarriorTests
    warriorTests.cpp
    ../source/character.cpp
    ../source/enemy.cpp
    ../source/spell.cpp
    ../source/warrior.cpp
    ../source/slam.cpp
    ../source/shatter.cpp
    ../source/bludgeon.cpp
)

add_executable(runMageTests
    mageTests.cpp
    ../source/character.cpp
    ../source/spell.cpp
    ../source/mage.cpp
    ../source/enemy.cpp
    ../source/arcaneBlast.cpp
    ../source/lifeleech.cpp
    ../source/incinerate.cpp
)

add_executable(runUserTests
    userTests.cpp
    ../source/user.cpp
    ../source/enemy.cpp
    ../source/item.cpp
    ../source/weapon.cpp
    ../source/armor.cpp
    ../source/trinket.cpp
    ../source/character.cpp
    ../source/rogue.cpp
    ../source/spell.cpp
    ../source/backstab.cpp
    ../source/pickpocket.cpp
    ../source/cutthroat.cpp
    ../source/statsManager.cpp
    ../source/itemManager.cpp
    ../source/encounterManager.cpp
)

add_executable(runStatsManagerTests
    statsManagerTests.cpp
    ../source/statsManager.cpp
    ../source/item.cpp
    ../source/weapon.cpp
    ../source/armor.cpp
    ../source/trinket.cpp
    ../source/character.cpp
    ../source/spell.cpp
)

add_executable(runItemManagerTests
    itemManagerTests.cpp
    ../source/itemManager.cpp
    ../source/item.cpp
    ../source/weapon.cpp
    ../source/armor.cpp
    ../source/trinket.cpp
    ../source/character.cpp
)

add_executable(runEncounterManagerTests
    encounterManagerTests.cpp
    ../source/encounterManager.cpp
)

add_executable(runGameTests
    gameTesting.cpp
    ../source/game.cpp
    ../source/user.cpp
    ../source/screen.cpp
    ../source/character.cpp
    ../source/characterSelect.cpp
    ../source/mage.cpp
    ../source/warrior.cpp
    ../source/rogue.cpp
    ../source/spell.cpp
    ../source/slam.cpp
    ../source/shatter.cpp
    ../source/bludgeon.cpp
    ../source/arcaneBlast.cpp
    ../source/incinerate.cpp
    ../source/lifeleech.cpp
    ../source/backstab.cpp
    ../source/pickpocket.cpp
    ../source/cutthroat.cpp
    ../source/enemy.cpp
    ../source/startMenu.cpp
    ../source/statsManager.cpp
    ../source/item.cpp
    ../source/armor.cpp
    ../source/weapon.cpp
    ../source/trinket.cpp
    ../source/encounterManager.cpp
    ../source/itemManager.cpp
)

add_executable(runTravelTests
    travelTests.cpp
    ../source/screen.cpp
    ../source/user.cpp
    ../source/travel.cpp
    ../source/inGameMenu.cpp
    ../source/statsManager.cpp
    ../source/character.cpp
    ../source/item.cpp
    ../source/armor.cpp
    ../source/weapon.cpp
    ../source/trinket.cpp
    ../source/encounterManager.cpp
    ../source/itemManager.cpp
)

add_executable(runCityTests
    cityTests.cpp
    ../source/screen.cpp
    ../source/user.cpp
    ../source/travel.cpp
    ../source/city.cpp
    ../source/statsManager.cpp
    ../source/character.cpp
    ../source/item.cpp
    ../source/weapon.cpp
    ../source/armor.cpp
    ../source/trinket.cpp
    ../source/encounterManager.cpp
    ../source/itemManager.cpp
)

add_executable(runInventoryTests
    inventoryTests.cpp
    ../source/screen.cpp
    ../source/inventory.cpp
    ../source/user.cpp
    ../source/statsManager.cpp
    ../source/inGameMenu.cpp
    ../source/character.cpp
    ../source/item.cpp
    ../source/trinket.cpp
    ../source/armor.cpp
    ../source/weapon.cpp
    ../source/encounterManager.cpp
    ../source/itemManager.cpp
)

add_executable ( runBossTests
    bossTests.cpp
    ../source/enemy.cpp
    ../source/boss.cpp
    ../source/bosspart1.cpp
    ../source/bosspart2.cpp
    ../source/bosspart3.cpp
    ../source/bosspart4.cpp
)

add_executable( runOrcBossTests
    orcBossTests.cpp
    ../source/orcBoss.cpp
    ../source/boss.cpp
    ../source/statsManager.cpp
    ../source/enemy.cpp
    ../source/armor.cpp
    ../source/weapon.cpp
    ../source/trinket.cpp
    ../source/character.cpp
    ../source/spell.cpp
    ../source/item.cpp
)

add_executable( runOrcTests
    orcTests.cpp
    ../source/orc.cpp
    ../source/enemy.cpp
    ../source/statsManager.cpp
    ../source/enemy.cpp
    ../source/armor.cpp
    ../source/weapon.cpp
    ../source/trinket.cpp
    ../source/character.cpp
    ../source/spell.cpp
    ../source/item.cpp
)

add_executable(runCharacterSelectTests
    characterSelectTesting.cpp
    ../source/screen.cpp
    ../source/characterSelect.cpp
    ../source/inGameMenu.cpp
    ../source/enemy.cpp
    ../source/user.cpp
    ../source/statsManager.cpp
    ../source/character.cpp
    ../source/mage.cpp
    ../source/warrior.cpp
    ../source/rogue.cpp
    ../source/itemManager.cpp
    ../source/item.cpp
    ../source/weapon.cpp
    ../source/trinket.cpp
    ../source/armor.cpp
    ../source/spell.cpp
    ../source/slam.cpp
    ../source/shatter.cpp
    ../source/bludgeon.cpp
    ../source/arcaneBlast.cpp
    ../source/incinerate.cpp
    ../source/lifeleech.cpp
    ../source/backstab.cpp
    ../source/pickpocket.cpp
    ../source/cutthroat.cpp
    ../source/encounterManager.cpp
)

target_link_libraries(runCharacterTests gmock gtest gtest_main)
target_link_libraries(runSpellTests gmock gtest gtest_main)
target_link_libraries(runScreenTests gmock gtest gtest_main)
target_link_libraries(runEnemyTests gmock gtest gtest_main)
target_link_libraries(runItemTests gmock gtest gtest_main)
target_link_libraries(runWeaponTests gtest gtest_main)
target_link_libraries(runRogueTests gtest gtest_main)
target_link_libraries(runWarriorTests gtest gtest_main)
target_link_libraries(runMageTests gtest gtest_main)
target_link_libraries(runUserTests gtest gtest_main)
target_link_libraries(runStatsManagerTests gtest gtest_main)
target_link_libraries(runGameTests gtest gtest_main)
target_link_libraries(runItemManagerTests gtest gtest_main)
target_link_libraries(runEncounterManagerTests gtest gtest_main)
target_link_libraries(runTravelTests gtest gtest_main)
target_link_libraries(runInventoryTests gtest gtest_main)
target_link_libraries(runCityTests gtest gtest_main)
target_link_libraries(runBossTests gtest gtest_main)
target_link_libraries(runOrcBossTests gtest gtest_main)
target_link_libraries(runCharacterSelectTests gtest gtest_main)
target_link_libraries(runOrcTests gtest gtest_main)
