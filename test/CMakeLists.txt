
IF(CMAKE_COMPILER_IS_GNUCC)
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fmessage-length=0")
ENDIF(CMAKE_COMPILER_IS_GNUCC)
IF(CMAKE_COMPILER_IS_GNUCXX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmessage-length=0")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

IF(WIN32)
	SET(BASEDIR /cygdrive/c/U-TEST/software)
	SET(VSDIR ${BASEDIR}/VS)
	SET(RTCDIR ${BASEDIR}/RTC)
	SET(UTESTDIR ${BASEDIR}/Commons)
ELSE(WIN32)
	SET(BASEDIR /opt)
	SET(VSDIR ${BASEDIR}/vs)
	SET(RTCDIR ${BASEDIR}/gc)
	SET(UTESTDIR ${BASEDIR}/utest/common)
ENDIF(WIN32)


ADD_LIBRARY(test SHARED test.cc
            api_c_extern/hdf.cc
            api_c_extern/Threads.cc)

INCLUDE_DIRECTORIES(
	${UTESTDIR}/include
    ${RTCDIR}/include
    ${RTCDIR}/include/base
    ${RTCDIR}/include/modules/uc
    ${RTCDIR}/include/modules/uc/toolkits
    ${VSDIR}/include
    api_c_extern
)

INSTALL(
	TARGETS test
	RUNTIME DESTINATION .
	LIBRARY DESTINATION lib
)

ADD_DEFINITIONS("-DOCL_DLL_EXPORT -DOROCOS_TARGET=gnulinux")

### USE -O3 OPTIMIZATION
ADD_DEFINITIONS ("-O3")

