set(SOURCE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/file.txt)
set(DESTINATION_DIR ${CMAKE_CURRENT_BINARY_DIR}/)

add_executable(
  word-frequency-counter 
  main.cpp
)

# Create a custom target for file copying
add_custom_command(
  TARGET word-frequency-counter POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${SOURCE_FILE} ${DESTINATION_DIR} 
  DEPENDS ${SOURCE_FILE}
)