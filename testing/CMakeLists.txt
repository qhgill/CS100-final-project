cmake_minimum_required(VERSION 3.20)
project(finalProject)


add_executable(runEnemyTests
    enemyTesting.cpp
    ../source/enemy.cpp
)

target_link_libraries(runEnemyTests gmock gtest gtest_main)

add_executable(runCharacterTests
    characterTests.cpp
    ../source/character.cpp
)

target_link_libraries(runCharacterTests gmock gtest gtest_main)

