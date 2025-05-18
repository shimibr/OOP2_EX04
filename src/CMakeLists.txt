file (GLOB_RECURSE MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
target_sources (${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCE_FILES} "../include/Controller.h" "Controller.cpp" "../include/Square.h" "Square.cpp" "../include/Object.h" "Object.cpp" "../include/Enemy.h" "Enemy.cpp")
