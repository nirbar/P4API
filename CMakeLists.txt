CMAKE_MINIMUM_REQUIRED (VERSION 3.4)

INCLUDE_DIRECTORIES (
	"${CMAKE_CURRENT_SOURCE_DIR}/include/"
	)

PROJECT (p4api)

SET( p4api_HEADERS
	include/p4/charcvt.h
	include/p4/charman.h
	include/p4/charset.h
	include/p4/clientapi.h
	include/p4/clientmerge.h
	include/p4/clientprog.h
	include/p4/clientresolvea.h
	include/p4/clientuser.h
	include/p4/datetime.h
	include/p4/debug.h
	include/p4/diff.h
	include/p4/echoctl.h
	include/p4/enviro.h
	include/p4/error.h
	include/p4/errorlog.h
	include/p4/errornum.h
	include/p4/filesys.h
	include/p4/handler.h
	include/p4/hostenv.h
	include/p4/i18napi.h
	include/p4/ident.h
	include/p4/ignore.h
	include/p4/keepalive.h
	include/p4/macfile.h
	include/p4/mapapi.h
	include/p4/md5.h
	include/p4/msgclient.h
	include/p4/msgdb.h
	include/p4/msgdm.h
	include/p4/msgos.h
	include/p4/msgrpc.h
	include/p4/msgserver.h
	include/p4/msgsupp.h
	include/p4/netbuffer.h
	include/p4/netconnect.h
	include/p4/netportparser.h
	include/p4/ntmangle.h
	include/p4/ntservice.h
	include/p4/options.h
	include/p4/p4api.h
	include/p4/p4tags.h
	include/p4/pathsys.h
	include/p4/runcmd.h
	include/p4/serverhelperapi.h
	include/p4/signaler.h
	include/p4/spec.h
	include/p4/stdhdrs.h
	include/p4/strarray.h
	include/p4/strbuf.h
	include/p4/strdict.h
	include/p4/strops.h
	include/p4/strtable.h
	include/p4/strxml.h
	include/p4/threading.h
	include/p4/ticket.h
	include/p4/validate.h
	include/p4/vararray.h
	include/p4/web822.h
	)

SET( p4api_SOURCES
	src/p4api.cpp
	)

SET ( p4api_LIBS)

IF( MSVC)
	#### Windows- Static binding to CRT
	FOREACH(flag_var
			CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
			CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
		IF(${flag_var} MATCHES "/MD")
			STRING(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
		ENDIF(${flag_var} MATCHES "/MD")
	ENDFOREACH(flag_var)

	IF (MSVC_VERSION EQUAL 1900)
		IF( CMAKE_BUILD_TYPE EQUAL Debug)
			SET ( p4api_LIBS
				${CMAKE_CURRENT_SOURCE_DIR}/Windows/VS2015/lib_x86/Debug/libclient.lib
				${CMAKE_CURRENT_SOURCE_DIR}/Windows/VS2015/lib_x86/Debug/librpc.lib
				${CMAKE_CURRENT_SOURCE_DIR}/Windows/VS2015/lib_x86/Debug/libsupp.lib
				${CMAKE_CURRENT_SOURCE_DIR}/Windows/VS2015/lib_x86/Debug/ssleay32.lib
				${CMAKE_CURRENT_SOURCE_DIR}/Windows/VS2015/lib_x86/Debug/libeay32.lib
				${p4api_LIBS}
				libssh2
				libcmtd.lib
				oldnames.lib
				kernel32.lib
				ws2_32.lib
				advapi32.lib
			)
		ELSE()
			SET ( p4api_LIBS
				${CMAKE_CURRENT_SOURCE_DIR}/Windows/VS2015/lib_x86/Release/libclient.lib
				${CMAKE_CURRENT_SOURCE_DIR}/Windows/VS2015/lib_x86/Release/librpc.lib
				${CMAKE_CURRENT_SOURCE_DIR}/Windows/VS2015/lib_x86/Release/libsupp.lib
				${CMAKE_CURRENT_SOURCE_DIR}/Windows/VS2015/lib_x86/Release/ssleay32.lib
				${CMAKE_CURRENT_SOURCE_DIR}/Windows/VS2015/lib_x86/Release/libeay32.lib
				${p4api_LIBS}
				libssh2
				libcmt.lib
				oldnames.lib
				kernel32.lib
				ws2_32.lib
				advapi32.lib
			)
		ENDIF()
	ENDIF() 
	IF (MSVC_VERSION EQUAL 1800)
		SET ( p4api_LIBS
			${CMAKE_CURRENT_SOURCE_DIR}/Windows/VS2013/lib_x86/libclient.lib
			${CMAKE_CURRENT_SOURCE_DIR}/Windows/VS2013/lib_x86/librpc.lib
			${CMAKE_CURRENT_SOURCE_DIR}/Windows/VS2013/lib_x86/libsupp.lib
			${CMAKE_CURRENT_SOURCE_DIR}/Windows/VS2013/lib_x86/ssleay32.lib
			${CMAKE_CURRENT_SOURCE_DIR}/Windows/VS2013/lib_x86/libeay32.lib
			${p4api_LIBS}
			libssh2
		)
	ENDIF()
ELSE()
	SET ( p4api_LIBS
		${CMAKE_CURRENT_SOURCE_DIR}/Linux/linux26x86/lib/libclient.a
		${CMAKE_CURRENT_SOURCE_DIR}/Linux/linux26x86/lib/librpc.a
		${CMAKE_CURRENT_SOURCE_DIR}/Linux/linux26x86/lib/libsupp.a
		libssl.a
		libcrypto.a
		${p4api_LIBS}
	)
ENDIF()
ADD_LIBRARY(p4api MODULE
	${p4api_SOURCES}
	${p4api_HEADERS}
	)

TARGET_LINK_LIBRARIES (p4api ${p4api_LIBS})
