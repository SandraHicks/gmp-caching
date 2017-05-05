cmake_minimum_required (VERSION 2.6)
project (gmp-caching)
set(IPO_VERSION_MAJOR 1)
set(IPO_VERSION_MINOR 0)




INCLUDE_DIRECTORIES(
  ${PROJECT_SOURCE_DIR}
)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
#SET(CMAKE_MODULE_PATH gmp-caching/cmake/)

set(TEST_DIR ../Tests/)

set(GMP_CACHING_SOURCES
  ${GMP_CACHING_SRC_DIR}caching_operations.c
  ${GMP_CACHING_SRC_DIR}debug.c
  ${GMP_CACHING_SRC_DIR}hashing.c
  ${GMP_CACHING_SRC_DIR}hashtable.c
  ${GMP_CACHING_SRC_DIR}mastercache.c
  ${GMP_CACHING_SRC_DIR}master_cache_integer.c
  ${GMP_CACHING_SRC_DIR}master_cache_rational.c
  ${GMP_CACHING_SRC_DIR}mpz_caching.c
  ${GMP_CACHING_SRC_DIR}overflow_detection.c
)

set(GMP_CACHING_HEADERS
  ${GMP_CACHING_SRC_DIR}caching_operations.h
  ${GMP_CACHING_SRC_DIR}config.h
  ${GMP_CACHING_SRC_DIR}debug.h
  ${GMP_CACHING_SRC_DIR}defines.h
  ${GMP_CACHING_SRC_DIR}hashing.h
  ${GMP_CACHING_SRC_DIR}hashtable.h
  ${GMP_CACHING_SRC_DIR}mastercache.h
  ${GMP_CACHING_SRC_DIR}master_cache_integer.h
  ${GMP_CACHING_SRC_DIR}master_cache_rational.h
  ${GMP_CACHING_SRC_DIR}mpz_caching.h
  ${GMP_CACHING_SRC_DIR}overflow_detection.h
)

add_library(gmp-caching STATIC ${GMP_CACHING_SOURCES})
target_link_libraries(gmp-caching gmp)

#### TESTS ####

add_executable(hash-test ${TEST_DIR}hash-test.c)
include_directories(../src/)
target_link_libraries(hash-test gmp)
target_link_libraries(hash-test gmp-caching)

add_executable(hashtable-test ${TEST_DIR}hashtable-test.c)
include_directories(../src/)
target_link_libraries(hashtable-test gmp)
target_link_libraries(hashtable-test gmp-caching)

add_executable(mpz-cache-test ${TEST_DIR}mpz-cache-test.c)
include_directories(../src/)
target_link_libraries(mpz-cache-test gmp)
target_link_libraries(mpz-cache-test gmp-caching)

add_executable(caching-operations-test ${TEST_DIR}caching-operations-test.c)
include_directories(../src/)
target_link_libraries(caching-operations-test gmp)
target_link_libraries(caching-operations-test gmp-caching)
set (CMAKE_C_FLAGS "-fPIC")

#### DOXYGEN ####

find_package(Doxygen)
IF (DOXYGEN_FOUND)
SET(DOXYGEN_INPUT src/Doxyfile)

ADD_CUSTOM_TARGET(
COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT}
COMMAND ${CMAKE_COMMAND} -E echo "Done."
WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
DEPENDS ${DOXYGEN_INPUT}
)

ENDIF(DOXYGEN_FOUND)

#install(TARGETS gmp-caching   ARCHIVE DESTINATION lib   LIBRARY DESTINATION lib   COMPONENT library)
#install(FILES ${GMP_CACHING_HEADERS} DESTINATION include/gmp-caching  COMPONENT headers)
