cmake_minimum_required(VERSION 3.20)
project(finalProject)

add_executable(runCharacterTests
    characterTests.cpp
    ../source/character.cpp
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

target_link_libraries(runCharacterTests gmock gtest gtest_main)
target_link_libraries(runSpellTests gmock gtest gtest_main)
target_link_libraries(runScreenTests gmock gtest gtest_main)
