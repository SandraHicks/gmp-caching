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
	${OBJECTDIR}/_ext/5c0/hash_table_array.o \
	${OBJECTDIR}/_ext/5c0/hash_table_double_linked_sorted.o \
	${OBJECTDIR}/_ext/5c0/hash_table_linked.o \
	${OBJECTDIR}/_ext/5c0/hash_table_linked_sorted.o \
	${OBJECTDIR}/_ext/5c0/hash_table_memory_alloc.o \
	${OBJECTDIR}/_ext/5c0/master_cache_integer.o \
	${OBJECTDIR}/_ext/5c0/master_cache_rational.o


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

${OBJECTDIR}/_ext/5c0/hash_table_array.o: ../hash_table_array.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/hash_table_array.o ../hash_table_array.c

${OBJECTDIR}/_ext/5c0/hash_table_double_linked_sorted.o: ../hash_table_double_linked_sorted.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/hash_table_double_linked_sorted.o ../hash_table_double_linked_sorted.c

${OBJECTDIR}/_ext/5c0/hash_table_linked.o: ../hash_table_linked.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/hash_table_linked.o ../hash_table_linked.c

${OBJECTDIR}/_ext/5c0/hash_table_linked_sorted.o: ../hash_table_linked_sorted.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/hash_table_linked_sorted.o ../hash_table_linked_sorted.c

${OBJECTDIR}/_ext/5c0/hash_table_memory_alloc.o: ../hash_table_memory_alloc.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/hash_table_memory_alloc.o ../hash_table_memory_alloc.c

${OBJECTDIR}/_ext/5c0/master_cache_integer.o: ../master_cache_integer.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/master_cache_integer.o ../master_cache_integer.c

${OBJECTDIR}/_ext/5c0/master_cache_rational.o: ../master_cache_rational.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/master_cache_rational.o ../master_cache_rational.c

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
