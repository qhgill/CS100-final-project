cmake_minimum_required(VERSION 3.20)
project(finalProject)

add_executable(runWeaponTests
    weaponTesting.cpp
    ../source/weapon.cpp
)

target_link_libraries(runWeaponTests gmock gtest gtest_main)