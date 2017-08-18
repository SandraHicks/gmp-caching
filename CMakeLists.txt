CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
project(gmp-caching)
set(PROJECT_NAME "Caching GMP numbers")

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

add_custom_target(documentary ALL
COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/doc
COMMENT "Generating API documentation with Doxygen"
VERBATIM
)
ENDIF(DOXYGEN_FOUND)

IF(CMAKE_COMPILER_IS_GNUCXX)
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)


set(TEST_DIR Tests/)

set(GMP_CACHING_SOURCES
  ${GMP_CACHING_SRC_DIR}src/caching_operations.c
  ${GMP_CACHING_SRC_DIR}src/debug.c
  ${GMP_CACHING_SRC_DIR}src/hashing.c
  ${GMP_CACHING_SRC_DIR}src/hashtable.c
  ${GMP_CACHING_SRC_DIR}src/mastercache.c
  ${GMP_CACHING_SRC_DIR}src/master_cache_integer.c
  ${GMP_CACHING_SRC_DIR}src/master_cache_rational.c
  ${GMP_CACHING_SRC_DIR}src/mpz_caching.c
  ${GMP_CACHING_SRC_DIR}src/overflow_detection.c
  ${GMP_CACHING_SRC_DIR}src/cachedInt.cpp
  ${GMP_CACHING_SRC_DIR}src/cachedRational.cpp
  ${GMP_CACHING_SRC_DIR}src/gmpcachingxx.cpp
)

set(GMP_CACHING_HEADERS
  ${GMP_CACHING_SRC_DIR}src/caching_operations.h
  ${GMP_CACHING_SRC_DIR}src/config.h
  ${GMP_CACHING_SRC_DIR}src/debug.h
  ${GMP_CACHING_SRC_DIR}src/defines.h
  ${GMP_CACHING_SRC_DIR}src/hashing.h
  ${GMP_CACHING_SRC_DIR}src/hashtable.h
  ${GMP_CACHING_SRC_DIR}src/mastercache.h
  ${GMP_CACHING_SRC_DIR}src/master_cache_integer.h
  ${GMP_CACHING_SRC_DIR}src/master_cache_rational.h
  ${GMP_CACHING_SRC_DIR}src/mpz_caching.h
  ${GMP_CACHING_SRC_DIR}src/overflow_detection.h
  ${GMP_CACHING_SRC_DIR}src/cachedInt.h
  ${GMP_CACHING_SRC_DIR}src/cachedRational.h
  ${GMP_CACHING_SRC_DIR}src/gmpcachingxx.h
)

IF(DEFINED ${CACHE_SIZE})
add_definitions(-DGMPCACHING_CACHESIZE=${CACHE_SIZE})
ELSE(DEFINED ${CACHE_SIZE})
set(CACHE_SIZE 400)
add_definitions(-DGMPCACHING_CACHESIZE=${CACHE_SIZE})
ENDIF(DEFINED ${CACHE_SIZE})



add_library(gmp-caching STATIC ${GMP_CACHING_SOURCES})
target_link_libraries(gmp-caching gmp)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -Wall")

#set(CMAKE_REQUIRED_INCLUDES stdint.h)

#### TESTS ####

add_executable(hash-test ${TEST_DIR}hash-test.c)
include_directories(src/)
target_link_libraries(hash-test gmp)
target_link_libraries(hash-test gmp-caching)

add_executable(hashtable-test ${TEST_DIR}hashtable-test.c)
include_directories(src/)
target_link_libraries(hashtable-test gmp)
target_link_libraries(hashtable-test gmp-caching)

add_executable(mpz-cache-test ${TEST_DIR}mpz-cache-test.c)
include_directories(src/)
target_link_libraries(mpz-cache-test gmp)
target_link_libraries(mpz-cache-test gmp-caching)

add_executable(caching-operations-test ${TEST_DIR}caching-operations-test.c)
include_directories(src/)
target_link_libraries(caching-operations-test gmp)
target_link_libraries(caching-operations-test gmp-caching)
set (CMAKE_C_FLAGS "-fPIC")

add_executable(caching-operations-test-many ${TEST_DIR}caching-operations-test-many.c)
include_directories(src/)
target_link_libraries(caching-operations-test-many gmp)
target_link_libraries(caching-operations-test-many gmp-caching)

add_executable(caching-operations-test-advanced ${TEST_DIR}caching-operations-test-advanced.c)
include_directories(src/)
target_link_libraries(caching-operations-test-advanced gmp)
target_link_libraries(caching-operations-test-advanced gmp-caching)

add_executable(master-cache-integer-test ${TEST_DIR}master-cache-integer-test.c)
include_directories(src/)
target_link_libraries(master-cache-integer-test gmp)
target_link_libraries(master-cache-integer-test gmp-caching)

add_executable(master-cache-integer-test-largenum ${TEST_DIR}master-cache-integer-test-largenum.c)
include_directories(src/)
target_link_libraries(master-cache-integer-test-largenum gmp)
target_link_libraries(master-cache-integer-test-largenum gmp-caching)

add_executable(master-cache-integer-grenzwerte ${TEST_DIR}master-cache-integer-grenzwerte.c)
include_directories(src/)
target_link_libraries(master-cache-integer-grenzwerte gmp)
target_link_libraries(master-cache-integer-grenzwerte gmp-caching)

add_executable(master-cache-test ${TEST_DIR}master-cache-test.c)
include_directories(src/)
target_link_libraries(master-cache-test gmp)
target_link_libraries(master-cache-test gmp-caching)

INCLUDE_DIRECTORIES(
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_BINARY_DIR}
)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

#install(FILES ${GMP_CACHING_HEADERS}                    DESTINATION include/ipo  COMPONENT headers)
#install(TARGETS gmp-caching   ARCHIVE DESTINATION lib   LIBRARY DESTINATION lib   COMPONENT library)
#install(FILES ${GMP_CACHING_HEADERS} DESTINATION include/gmp-caching  COMPONENT headers)
