cmake_minimum_required(VERSION 3.5.0)
project(homeWork09_01 VERSION 0.1.0 LANGUAGES C CXX)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage")

add_subdirectory(googletest)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif()

add_compile_options(-Wall -Wextra -pedantic -Werror)

#########################################

# homeWork09_01 executable
add_executable(homeWork09_01 homeWork09_01/main.cpp homeWork09_01/lib.cpp)
target_include_directories(homeWork09_01 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/homeWork09_01)

# homeWork09_01 Unit tests executable
add_executable(tests09_01 homeWork09_01/tests.cpp homeWork09_01/lib.cpp    )
add_dependencies(tests09_01 homeWork09_01)
target_include_directories(tests09_01 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/homeWork09_01)
target_link_libraries(tests09_01 gtest gtest_main)

# homeWork09_01 Unit tests runner
add_custom_target(run_all_tests09_01 ALL
    COMMAND ./tests09_01
    DEPENDS tests09_01
)

#########################################

# homeWork09_02 executable
add_executable(homeWork09_02 homeWork09_02/main.cpp homeWork09_02/lib.cpp)
target_include_directories(homeWork09_02 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/homeWork09_02)

# homeWork09_02 Unit tests executable
add_executable(tests09_02 homeWork09_02/tests.cpp homeWork09_02/lib.cpp
)
add_dependencies(tests09_02 homeWork09_02)
target_include_directories(tests09_02 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/homeWork09_02)
target_link_libraries(tests09_02 gtest gtest_main)

# homeWork09_02 Unit tests runner
add_custom_target(run_all_tests09_02 ALL
    COMMAND ./tests09_02
    DEPENDS tests09_02
)

#########################################

# homeWork09_03 executable
add_executable(homeWork09_03 homeWork09_03/main.cpp homeWork09_03/lib.cpp)
target_include_directories(homeWork09_03 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/homeWork09_03)

# homeWork09_03 Unit tests executable
add_executable(tests09_03 homeWork09_03/tests.cpp homeWork09_03/lib.cpp
)
add_dependencies(tests09_03 homeWork09_03)
target_include_directories(tests09_03 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/homeWork09_03)
target_link_libraries(tests09_03 gtest gtest_main)

# homeWork09_03 Unit tests runner
add_custom_target(run_all_tests09_03 ALL
    COMMAND ./tests09_03
    DEPENDS tests09_03
)

#########################################

# homeWork09_04 executable
add_executable(homeWork09_04 homeWork09_04/main.cpp homeWork09_04/lib.cpp)
target_include_directories(homeWork09_04 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/homeWork09_04)

# homeWork09_04 Unit tests executable
add_executable(tests09_04 homeWork09_04/tests.cpp homeWork09_04/lib.cpp
)
add_dependencies(tests09_04 homeWork09_04)
target_include_directories(tests09_04 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/homeWork09_04)
target_link_libraries(tests09_04 gtest gtest_main)

# homeWork09_04 Unit tests runner
add_custom_target(run_all_tests09_04 ALL
    COMMAND ./tests09_04
    DEPENDS tests09_04
)

#########################################

# homeWork09_05 executable
add_executable(homeWork09_05 homeWork09_05/main.cpp homeWork09_05/lib.cpp)
target_include_directories(homeWork09_05 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/homeWork09_05)

# homeWork09_05 Unit tests executable
add_executable(tests09_05 homeWork09_05/tests.cpp homeWork09_05/lib.cpp
)
add_dependencies(tests09_05 homeWork09_05)
target_include_directories(tests09_05 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/homeWork09_05)
target_link_libraries(tests09_05 gtest gtest_main)

# homeWork09_05 Unit tests runner
add_custom_target(run_all_tests09_05 ALL
    COMMAND ./tests09_05
    DEPENDS tests09_05
)

#########################################

# homeWork10_01 executable
add_executable(homeWork10_01 homeWork10_01/main.cpp)

#########################################

# homeWork11_01 executable
add_executable(homeWork11_01 homeWork11_01/main.cpp homeWork11_01/lib.cpp)
target_include_directories(homeWork11_01 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/homeWork11_01)

# homeWork11_01 Unit tests executable
add_executable(tests11_01 homeWork11_01/tests.cpp homeWork11_01/lib.cpp
)
add_dependencies(tests11_01 homeWork11_01)
target_include_directories(tests11_01 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/homeWork11_01)
target_link_libraries(tests11_01 gtest gtest_main)

# homeWork11_01 Unit tests runner
add_custom_target(run_all_tests11_01 ALL
    COMMAND ./tests11_01
    DEPENDS tests11_01
)

#########################################

# homeWork11_02 executable
add_executable(homeWork11_02 homeWork11_02/main.cpp homeWork11_02/lib.cpp)
target_include_directories(homeWork11_02 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/homeWork11_02)

# homeWork11_02 Unit tests executable
add_executable(tests11_02 homeWork11_02/tests.cpp homeWork11_02/lib.cpp
)
add_dependencies(tests11_02 homeWork11_02)
target_include_directories(tests11_02 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/homeWork11_02)
target_link_libraries(tests11_02 gtest gtest_main)

# homeWork11_02 Unit tests runner
add_custom_target(run_all_tests11_02 ALL
    COMMAND ./tests11_02
    DEPENDS tests11_02
)

#########################################

# ======== Coverage =========
add_custom_target(coverage ALL)

add_custom_command(TARGET coverage
    POST_BUILD
    COMMAND  ${CMAKE_CURRENT_SOURCE_DIR}/coverage_local.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_dependencies(coverage run_all_tests09_01 run_all_tests09_02 run_all_tests09_03 run_all_tests09_04 run_all_tests09_05 run_all_tests11_01 run_all_tests11_02)
