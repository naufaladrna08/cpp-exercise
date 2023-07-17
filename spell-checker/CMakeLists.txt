set(SOURCE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/words.txt)
set(DESTINATION_DIR ${CMAKE_CURRENT_BINARY_DIR}/)

add_executable(
  spell-checker
  main.cpp
)

# Create a custom target for file copying
add_custom_command(
  TARGET spell-checker POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${SOURCE_FILE} ${DESTINATION_DIR} 
  DEPENDS ${SOURCE_FILE}
)