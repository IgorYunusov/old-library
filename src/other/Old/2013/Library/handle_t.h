/****
 *ROLLRAT KERNEL STF
 *V1.0.0	// MAKE:214B7E
 */

#ifndef _handle_t
#define _handle_t

#include <Windows.h>

#ifndef _KERNEL_BASENO
//	OS Kernel HANDLE
typedef void * KERNEL_HANDLE;
#else
//	OS Kernel HANDLE
#define KERNEL_HANDLE	DWORD
#endif

//	Function
typedef void * FUNCTION;

#define R_INVALID_HANDLE		(-1)

//	OS Kernel CONTEXT
typedef struct _kernel_context
{
	KERNEL_HANDLE	errornt;
	FUNCTION		supervisor;
	BYTE			escape;
	FUNCTION		readvise;
}	KERNEL_CONTEXT, *PKERNEL_CONTEXT;




#endif