#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/5c0/cachedInt.o \
	${OBJECTDIR}/_ext/5c0/cachedRational.o \
	${OBJECTDIR}/_ext/5c0/caching_operations.o \
	${OBJECTDIR}/_ext/5c0/debug.o \
	${OBJECTDIR}/_ext/5c0/gmpcachingxx.o \
	${OBJECTDIR}/_ext/5c0/hashing.o \
	${OBJECTDIR}/_ext/5c0/hashtable.o \
	${OBJECTDIR}/_ext/5c0/master_cache_integer.o \
	${OBJECTDIR}/_ext/5c0/master_cache_rational.o \
	${OBJECTDIR}/_ext/5c0/mastercache.o \
	${OBJECTDIR}/_ext/5c0/mpz_caching.o \
	${OBJECTDIR}/_ext/5c0/overflow_detection.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgmp-caching.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgmp-caching.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgmp-caching.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgmp-caching.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgmp-caching.a

${OBJECTDIR}/_ext/5c0/cachedInt.o: ../cachedInt.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/cachedInt.o ../cachedInt.cpp

${OBJECTDIR}/_ext/5c0/cachedRational.o: ../cachedRational.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/cachedRational.o ../cachedRational.cpp

${OBJECTDIR}/_ext/5c0/caching_operations.o: ../caching_operations.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/caching_operations.o ../caching_operations.c

${OBJECTDIR}/_ext/5c0/debug.o: ../debug.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/debug.o ../debug.c

${OBJECTDIR}/_ext/5c0/gmpcachingxx.o: ../gmpcachingxx.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/gmpcachingxx.o ../gmpcachingxx.cpp

${OBJECTDIR}/_ext/5c0/hashing.o: ../hashing.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/hashing.o ../hashing.c

${OBJECTDIR}/_ext/5c0/hashtable.o: ../hashtable.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/hashtable.o ../hashtable.c

${OBJECTDIR}/_ext/5c0/master_cache_integer.o: ../master_cache_integer.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/master_cache_integer.o ../master_cache_integer.c

${OBJECTDIR}/_ext/5c0/master_cache_rational.o: ../master_cache_rational.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/master_cache_rational.o ../master_cache_rational.c

${OBJECTDIR}/_ext/5c0/mastercache.o: ../mastercache.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/mastercache.o ../mastercache.c

${OBJECTDIR}/_ext/5c0/mpz_caching.o: ../mpz_caching.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/mpz_caching.o ../mpz_caching.c

${OBJECTDIR}/_ext/5c0/overflow_detection.o: ../overflow_detection.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/overflow_detection.o ../overflow_detection.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
