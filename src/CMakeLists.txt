set(target code_lib)

file(GLOB_RECURSE CPPS *.cpp)
file(GLOB_RECURSE HPPS *.hpp)

include_directories(../include)

add_library(${target} ${CPPS} ${HPPS})

add_dependencies(${target} ${target}_lint)

file(GLOB lint_config ${CMAKE_SOURCE_DIR}/CPPLINT.cfg)
add_custom_target(${target}_lint ALL
                  COMMAND ${LINTING_COMMAND} ${CPPS} ${HPPS}
                  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                  SOURCES ${LINTING_APP} ${lint_config})
