SET(PACKAGE_NAME ${PROJECT_NAME})

find_package(Doxygen)

IF(NOT DOXYGEN_FOUND)
message(FATAL_ERROR "Doxygen is needed to build the documentation.")
ENDIF()

IF (DOXYGEN_FOUND)
CONFIGURE_FILE(
  ${PROJECT_SOURCE_DIR}/doc/Doxyfile.in
  ${PROJECT_BINARY_DIR}/doc/Doxyfile
  @ONLY
)

add_custom_target(doc ALL
COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
COMMENT "Generating API documentation with Doxygen"
VERBATIM
)
ENDIF(DOXYGEN_FOUND)
