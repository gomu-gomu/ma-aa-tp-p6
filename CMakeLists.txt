cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(src)
add_executable(diviser_pour_regner src/diviser_pour_regner.c)
add_executable(methodes_gloytonnes src/methodes_gloytonnes.c)
add_executable(programmation_dynamique src/programmation_dynamique.c)

set_target_properties(diviser_pour_regner methodes_gloytonnes programmation_dynamique
                      PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/out")

add_custom_target(run_diviser_pour_regner
                  COMMAND diviser_pour_regner
                  DEPENDS diviser_pour_regner
                  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

add_custom_target(run_methodes_gloytonnes
                  COMMAND methodes_gloytonnes
                  DEPENDS methodes_gloytonnes
                  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

add_custom_target(run_programmation_dynamique
                  COMMAND programmation_dynamique
                  DEPENDS programmation_dynamique
                  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})