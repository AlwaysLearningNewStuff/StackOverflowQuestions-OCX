

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for DemoOCX.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_DemoOCXLib,0x02d4cc0d,0x4702,0x4bad,0x8c,0xf9,0x5f,0x87,0x64,0x8a,0x66,0x8d);


MIDL_DEFINE_GUID(IID, DIID__DDemoOCX,0x69ef3342,0x2d67,0x42a0,0x81,0xae,0x98,0x7c,0x13,0xc3,0xfc,0x9d);


MIDL_DEFINE_GUID(IID, DIID__DDemoOCXEvents,0xf2e2076e,0x3db1,0x4ddd,0x82,0x3f,0x02,0x6e,0x7c,0xa1,0x71,0x54);


MIDL_DEFINE_GUID(CLSID, CLSID_DemoOCX,0x179ab540,0x078d,0x44cb,0x97,0x7e,0xa7,0x78,0x97,0x3a,0x51,0x61);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



