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
    ../source/city.cpp
    ../source/user.cpp
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
)
add_executable(runItemTests
    ../source/item.cpp
    armorTests.cpp
)

add_executable(runRogueTests
    rogueTests.cpp
    ../source/character.cpp
    ../source/spell.cpp
    ../source/rogue.cpp
    ../source/backstab.cpp
    ../source/pickpocket.cpp
    ../source/cutthroat.cpp
)

add_executable(runUserTests
    userTests.cpp
    ../source/user.cpp
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
)

add_executable(runGameTests
    gameTesting.cpp
    ../source/game.cpp
    ../source/user.cpp
    ../source/screen.cpp
    ../source/character.cpp
    ../source/startMenu.cpp
)

target_link_libraries(runCharacterTests gmock gtest gtest_main)
target_link_libraries(runSpellTests gmock gtest gtest_main)
target_link_libraries(runScreenTests gmock gtest gtest_main)
target_link_libraries(runEnemyTests gmock gtest gtest_main)
target_link_libraries(runItemTests gmock gtest gtest_main)
target_link_libraries(runWeaponTests gtest gtest_main)
target_link_libraries(runRogueTests gtest gtest_main)
target_link_libraries(runUserTests gtest gtest_main)
target_link_libraries(runGameTests gtest gtest_main)
