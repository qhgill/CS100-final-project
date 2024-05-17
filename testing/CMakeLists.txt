cmake_minimum_required(VERSION 3.20)
project(finalProject)


add_executable(runEnemyTests
    enemyTesting.cpp
    ../source/enemy.cpp
)

add_executable(runWeaponTests
    weaponTesting.cpp
    ../source/weapon.cpp
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

target_link_libraries(runCharacterTests gmock gtest gtest_main)
target_link_libraries(runSpellTests gmock gtest gtest_main)
target_link_libraries(runScreenTests gmock gtest gtest_main)

target_link_libraries(runEnemyTests gmock gtest gtest_main)


target_link_libraries(runWeaponTests gmock gtest gtest_main)

target_link_libraries(runRogueTests gtest gtest_main)

