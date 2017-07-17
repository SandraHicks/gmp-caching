cmake_minimum_required (VERSION 2.6)

#project name and version
set(PROJECT_NAME "Caching GMP numbers")
set(IPO_VERSION_MAJOR 1)
set(IPO_VERSION_MINOR 0)


INCLUDE_DIRECTORIES(
  ${PROJECT_SOURCE_DIR}
)

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
  ${GMP_CACHING_SRC_DIR}cachedInt.cpp
  ${GMP_CACHING_SRC_DIR}cachedRational.cpp
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
  ${GMP_CACHING_SRC_DIR}cachedInt.h
  ${GMP_CACHING_SRC_DIR}cachedRational.h
)

add_library(gmp-caching STATIC ${GMP_CACHING_SOURCES})
target_link_libraries(gmp-caching gmp)
#target_compile_options(gmp-caching PUBLIC -std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -Wall")

#set(CMAKE_REQUIRED_INCLUDES stdint.h)

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

add_executable(caching-operations-test-many ${TEST_DIR}caching-operations-test-many.c)
include_directories(../src/)
target_link_libraries(caching-operations-test-many gmp)
target_link_libraries(caching-operations-test-many gmp-caching)

add_executable(caching-operations-test-advanced ${TEST_DIR}caching-operations-test-advanced.c)
include_directories(../src/)
target_link_libraries(caching-operations-test-advanced gmp)
target_link_libraries(caching-operations-test-advanced gmp-caching)

add_executable(master-cache-integer-test ${TEST_DIR}master-cache-integer-test.c)
include_directories(../src/)
target_link_libraries(master-cache-integer-test gmp)
target_link_libraries(master-cache-integer-test gmp-caching)

add_executable(master-cache-integer-test-largenum ${TEST_DIR}master-cache-integer-test-largenum.c)
include_directories(../src/)
target_link_libraries(master-cache-integer-test-largenum gmp)
target_link_libraries(master-cache-integer-test-largenum gmp-caching)

add_executable(master-cache-integer-grenzwerte ${TEST_DIR}master-cache-integer-grenzwerte.c)
include_directories(../src/)
target_link_libraries(master-cache-integer-grenzwerte gmp)
target_link_libraries(master-cache-integer-grenzwerte gmp-caching)

add_executable(master-cache-test ${TEST_DIR}master-cache-test.c)
include_directories(../src/)
target_link_libraries(master-cache-test gmp)
target_link_libraries(master-cache-test gmp-caching)

#install(FILES ${GMP_CACHING_HEADERS}                    DESTINATION include/ipo  COMPONENT headers)
#install(TARGETS gmp-caching   ARCHIVE DESTINATION lib   LIBRARY DESTINATION lib   COMPONENT library)
#install(FILES ${GMP_CACHING_HEADERS} DESTINATION include/gmp-caching  COMPONENT headers)
