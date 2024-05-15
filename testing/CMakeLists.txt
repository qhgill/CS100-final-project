cmake_minimum_required(VERSION 3.20)
project(finalProject)

add_executable(runEnemyTests
    enemyTesting.cpp
    ../source/enemy.cpp
)

target_link_libraries(runEnemyTests gmock gtest gtest_main)