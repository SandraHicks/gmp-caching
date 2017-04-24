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
	${OBJECTDIR}/_ext/5c0/debug.o \
	${OBJECTDIR}/_ext/5c0/hashing.o \
	${OBJECTDIR}/_ext/5c0/hashtable.o \
	${OBJECTDIR}/_ext/5c0/master_cache_integer.o \
	${OBJECTDIR}/_ext/5c0/master_cache_rational.o \
	${OBJECTDIR}/_ext/5c0/mastercache.o \
	${OBJECTDIR}/_ext/5c0/mpz_caching.o \
	${OBJECTDIR}/_ext/5c0/overflow_detection.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/_ext/829ac912/simpletest.o

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

${OBJECTDIR}/_ext/5c0/debug.o: ../debug.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/debug.o ../debug.c

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

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/_ext/829ac912/simpletest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/_ext/829ac912/simpletest.o: ../tests/simpletest.c 
	${MKDIR} -p ${TESTDIR}/_ext/829ac912
	${RM} "$@.d"
	$(COMPILE.c) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/829ac912/simpletest.o ../tests/simpletest.c


${OBJECTDIR}/_ext/5c0/debug_nomain.o: ${OBJECTDIR}/_ext/5c0/debug.o ../debug.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/5c0/debug.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/debug_nomain.o ../debug.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/5c0/debug.o ${OBJECTDIR}/_ext/5c0/debug_nomain.o;\
	fi

${OBJECTDIR}/_ext/5c0/hashing_nomain.o: ${OBJECTDIR}/_ext/5c0/hashing.o ../hashing.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/5c0/hashing.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/hashing_nomain.o ../hashing.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/5c0/hashing.o ${OBJECTDIR}/_ext/5c0/hashing_nomain.o;\
	fi

${OBJECTDIR}/_ext/5c0/hashtable_nomain.o: ${OBJECTDIR}/_ext/5c0/hashtable.o ../hashtable.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/5c0/hashtable.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/hashtable_nomain.o ../hashtable.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/5c0/hashtable.o ${OBJECTDIR}/_ext/5c0/hashtable_nomain.o;\
	fi

${OBJECTDIR}/_ext/5c0/master_cache_integer_nomain.o: ${OBJECTDIR}/_ext/5c0/master_cache_integer.o ../master_cache_integer.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/5c0/master_cache_integer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/master_cache_integer_nomain.o ../master_cache_integer.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/5c0/master_cache_integer.o ${OBJECTDIR}/_ext/5c0/master_cache_integer_nomain.o;\
	fi

${OBJECTDIR}/_ext/5c0/master_cache_rational_nomain.o: ${OBJECTDIR}/_ext/5c0/master_cache_rational.o ../master_cache_rational.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/5c0/master_cache_rational.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/master_cache_rational_nomain.o ../master_cache_rational.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/5c0/master_cache_rational.o ${OBJECTDIR}/_ext/5c0/master_cache_rational_nomain.o;\
	fi

${OBJECTDIR}/_ext/5c0/mastercache_nomain.o: ${OBJECTDIR}/_ext/5c0/mastercache.o ../mastercache.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/5c0/mastercache.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/mastercache_nomain.o ../mastercache.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/5c0/mastercache.o ${OBJECTDIR}/_ext/5c0/mastercache_nomain.o;\
	fi

${OBJECTDIR}/_ext/5c0/mpz_caching_nomain.o: ${OBJECTDIR}/_ext/5c0/mpz_caching.o ../mpz_caching.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/5c0/mpz_caching.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/mpz_caching_nomain.o ../mpz_caching.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/5c0/mpz_caching.o ${OBJECTDIR}/_ext/5c0/mpz_caching_nomain.o;\
	fi

${OBJECTDIR}/_ext/5c0/overflow_detection_nomain.o: ${OBJECTDIR}/_ext/5c0/overflow_detection.o ../overflow_detection.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/5c0/overflow_detection.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/overflow_detection_nomain.o ../overflow_detection.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/5c0/overflow_detection.o ${OBJECTDIR}/_ext/5c0/overflow_detection_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
