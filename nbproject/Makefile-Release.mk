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
	${OBJECTDIR}/src/Handler.o \
	${OBJECTDIR}/src/NonblockingServer.o \
	${OBJECTDIR}/src/Processor.o \
	${OBJECTDIR}/src/Protocol.o \
	${OBJECTDIR}/src/ServerSocket.o \
	${OBJECTDIR}/src/SimpleServer.o \
	${OBJECTDIR}/src/Socket.o \
	${OBJECTDIR}/src/ThreadedServer.o \
	${OBJECTDIR}/src/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/client.o

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tcp-server

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tcp-server: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tcp-server ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Handler.o: src/Handler.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Handler.o src/Handler.cpp

${OBJECTDIR}/src/NonblockingServer.o: src/NonblockingServer.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/NonblockingServer.o src/NonblockingServer.cpp

${OBJECTDIR}/src/Processor.o: src/Processor.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Processor.o src/Processor.cpp

${OBJECTDIR}/src/Protocol.o: src/Protocol.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Protocol.o src/Protocol.cpp

${OBJECTDIR}/src/ServerSocket.o: src/ServerSocket.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ServerSocket.o src/ServerSocket.cpp

${OBJECTDIR}/src/SimpleServer.o: src/SimpleServer.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SimpleServer.o src/SimpleServer.cpp

${OBJECTDIR}/src/Socket.o: src/Socket.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Socket.o src/Socket.cpp

${OBJECTDIR}/src/ThreadedServer.o: src/ThreadedServer.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ThreadedServer.o src/ThreadedServer.cpp

${OBJECTDIR}/src/main.o: src/main.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/client.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/tests/client.o: tests/client.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Iinc -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/client.o tests/client.cpp


${OBJECTDIR}/src/Handler_nomain.o: ${OBJECTDIR}/src/Handler.o src/Handler.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Handler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Handler_nomain.o src/Handler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Handler.o ${OBJECTDIR}/src/Handler_nomain.o;\
	fi

${OBJECTDIR}/src/NonblockingServer_nomain.o: ${OBJECTDIR}/src/NonblockingServer.o src/NonblockingServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/NonblockingServer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/NonblockingServer_nomain.o src/NonblockingServer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/NonblockingServer.o ${OBJECTDIR}/src/NonblockingServer_nomain.o;\
	fi

${OBJECTDIR}/src/Processor_nomain.o: ${OBJECTDIR}/src/Processor.o src/Processor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Processor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Processor_nomain.o src/Processor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Processor.o ${OBJECTDIR}/src/Processor_nomain.o;\
	fi

${OBJECTDIR}/src/Protocol_nomain.o: ${OBJECTDIR}/src/Protocol.o src/Protocol.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Protocol.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Protocol_nomain.o src/Protocol.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Protocol.o ${OBJECTDIR}/src/Protocol_nomain.o;\
	fi

${OBJECTDIR}/src/ServerSocket_nomain.o: ${OBJECTDIR}/src/ServerSocket.o src/ServerSocket.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/ServerSocket.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ServerSocket_nomain.o src/ServerSocket.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/ServerSocket.o ${OBJECTDIR}/src/ServerSocket_nomain.o;\
	fi

${OBJECTDIR}/src/SimpleServer_nomain.o: ${OBJECTDIR}/src/SimpleServer.o src/SimpleServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/SimpleServer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SimpleServer_nomain.o src/SimpleServer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/SimpleServer.o ${OBJECTDIR}/src/SimpleServer_nomain.o;\
	fi

${OBJECTDIR}/src/Socket_nomain.o: ${OBJECTDIR}/src/Socket.o src/Socket.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Socket.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Socket_nomain.o src/Socket.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Socket.o ${OBJECTDIR}/src/Socket_nomain.o;\
	fi

${OBJECTDIR}/src/ThreadedServer_nomain.o: ${OBJECTDIR}/src/ThreadedServer.o src/ThreadedServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/ThreadedServer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ThreadedServer_nomain.o src/ThreadedServer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/ThreadedServer.o ${OBJECTDIR}/src/ThreadedServer_nomain.o;\
	fi

${OBJECTDIR}/src/main_nomain.o: ${OBJECTDIR}/src/main.o src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Iinc -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main_nomain.o src/main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/main_nomain.o;\
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
