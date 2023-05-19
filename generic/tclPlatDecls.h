/*
 * tclPlatDecls.h --
 *
 *	Declarations of platform specific Tcl APIs.
 *
 * Copyright (c) 1998-1999 by Scriptics Corporation.
 * All rights reserved.
 */

#ifndef _TCLPLATDECLS
#define _TCLPLATDECLS

#undef TCL_STORAGE_CLASS
#ifdef BUILD_tcl
#   define TCL_STORAGE_CLASS DLLEXPORT
#else
#   ifdef USE_TCL_STUBS
#      define TCL_STORAGE_CLASS
#   else
#      define TCL_STORAGE_CLASS DLLIMPORT
#   endif
#endif

/*
 * WARNING: This file is automatically generated by the tools/genStubs.tcl
 * script.  Any modifications to the function declarations below should be made
 * in the generic/tcl.decls script.
 */

/*
 * TCHAR is needed here for win32, so if it is not defined yet do it here.
 * This way, we don't need to include <tchar.h> just for one define.
 */
#if (defined(_WIN32) || defined(__CYGWIN__)) && !defined(_TCHAR_DEFINED)
#   if defined(_UNICODE)
	typedef wchar_t TCHAR;
#   else
	typedef char TCHAR;
#   endif
#   define _TCHAR_DEFINED
#endif

#ifndef MODULE_SCOPE
#   ifdef __cplusplus
#	define MODULE_SCOPE extern "C"
#   else
#	define MODULE_SCOPE extern
#   endif
#endif


/* !BEGIN!: Do not edit below this line. */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Exported function declarations:
 */

/* Slot 0 is reserved */
/* 1 */
EXTERN int		Tcl_MacOSXOpenVersionedBundleResources(
				Tcl_Interp *interp, const char *bundleName,
				const char *bundleVersion,
				int hasResourceFile, Tcl_Size maxPathLen,
				char *libraryPath);
/* 2 */
EXTERN void		Tcl_MacOSXNotifierAddRunLoopMode(
				const void *runLoopMode);
/* 3 */
EXTERN void		Tcl_WinConvertError(unsigned errCode);

typedef struct TclPlatStubs {
    int magic;
    void *hooks;

    void (*reserved0)(void);
    int (*tcl_MacOSXOpenVersionedBundleResources) (Tcl_Interp *interp, const char *bundleName, const char *bundleVersion, int hasResourceFile, Tcl_Size maxPathLen, char *libraryPath); /* 1 */
    void (*tcl_MacOSXNotifierAddRunLoopMode) (const void *runLoopMode); /* 2 */
    void (*tcl_WinConvertError) (unsigned errCode); /* 3 */
} TclPlatStubs;

extern const TclPlatStubs *tclPlatStubsPtr;

#ifdef __cplusplus
}
#endif

#if defined(USE_TCL_STUBS)

/*
 * Inline function declarations:
 */

/* Slot 0 is reserved */
#define Tcl_MacOSXOpenVersionedBundleResources \
	(tclPlatStubsPtr->tcl_MacOSXOpenVersionedBundleResources) /* 1 */
#define Tcl_MacOSXNotifierAddRunLoopMode \
	(tclPlatStubsPtr->tcl_MacOSXNotifierAddRunLoopMode) /* 2 */
#define Tcl_WinConvertError \
	(tclPlatStubsPtr->tcl_WinConvertError) /* 3 */

#endif /* defined(USE_TCL_STUBS) */

/* !END!: Do not edit above this line. */


#ifdef MAC_OSX_TCL /* MACOSX */
#undef Tcl_MacOSXOpenBundleResources
#define Tcl_MacOSXOpenBundleResources(a,b,c,d,e) Tcl_MacOSXOpenVersionedBundleResources(a,b,NULL,c,d,e)
#endif

#undef TCL_STORAGE_CLASS
#define TCL_STORAGE_CLASS DLLIMPORT

#ifdef _WIN32
#   undef Tcl_CreateFileHandler
#   undef Tcl_DeleteFileHandler
#   undef Tcl_GetOpenFile
#endif
#ifndef MAC_OSX_TCL
#   undef Tcl_MacOSXOpenVersionedBundleResources
#   undef Tcl_MacOSXNotifierAddRunLoopMode
#endif

#if defined(USE_TCL_STUBS) && (defined(_WIN32) || defined(__CYGWIN__))
#undef Tcl_WinUtfToTChar
#undef Tcl_WinTCharToUtf
#ifdef _WIN32
#define Tcl_WinUtfToTChar(string, len, dsPtr) (Tcl_DStringInit(dsPtr), \
		(TCHAR *)Tcl_UtfToChar16DString((string), (len), (dsPtr)))
#define Tcl_WinTCharToUtf(string, len, dsPtr) (Tcl_DStringInit(dsPtr), \
		(char *)Tcl_Char16ToUtfDString((const unsigned short *)(string), ((((len) + 2) >> 1) - 1), (dsPtr)))
#endif
#endif

#endif /* _TCLPLATDECLS */
