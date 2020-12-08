

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __DemoOCXidl_h__
#define __DemoOCXidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DDemoOCX_FWD_DEFINED__
#define ___DDemoOCX_FWD_DEFINED__
typedef interface _DDemoOCX _DDemoOCX;

#endif 	/* ___DDemoOCX_FWD_DEFINED__ */


#ifndef ___DDemoOCXEvents_FWD_DEFINED__
#define ___DDemoOCXEvents_FWD_DEFINED__
typedef interface _DDemoOCXEvents _DDemoOCXEvents;

#endif 	/* ___DDemoOCXEvents_FWD_DEFINED__ */


#ifndef __DemoOCX_FWD_DEFINED__
#define __DemoOCX_FWD_DEFINED__

#ifdef __cplusplus
typedef class DemoOCX DemoOCX;
#else
typedef struct DemoOCX DemoOCX;
#endif /* __cplusplus */

#endif 	/* __DemoOCX_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_DemoOCX_0000_0000 */
/* [local] */ 

#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(pop)
#pragma warning(pop)
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_DemoOCX_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_DemoOCX_0000_0000_v0_0_s_ifspec;


#ifndef __DemoOCXLib_LIBRARY_DEFINED__
#define __DemoOCXLib_LIBRARY_DEFINED__

/* library DemoOCXLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_DemoOCXLib;

#ifndef ___DDemoOCX_DISPINTERFACE_DEFINED__
#define ___DDemoOCX_DISPINTERFACE_DEFINED__

/* dispinterface _DDemoOCX */
/* [uuid] */ 


EXTERN_C const IID DIID__DDemoOCX;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("69ef3342-2d67-42a0-81ae-987c13c3fc9d")
    _DDemoOCX : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DDemoOCXVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DDemoOCX * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DDemoOCX * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DDemoOCX * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DDemoOCX * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DDemoOCX * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DDemoOCX * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DDemoOCX * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DDemoOCXVtbl;

    interface _DDemoOCX
    {
        CONST_VTBL struct _DDemoOCXVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DDemoOCX_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DDemoOCX_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DDemoOCX_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DDemoOCX_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DDemoOCX_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DDemoOCX_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DDemoOCX_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DDemoOCX_DISPINTERFACE_DEFINED__ */


#ifndef ___DDemoOCXEvents_DISPINTERFACE_DEFINED__
#define ___DDemoOCXEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DDemoOCXEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DDemoOCXEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("f2e2076e-3db1-4ddd-823f-026e7ca17154")
    _DDemoOCXEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DDemoOCXEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DDemoOCXEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DDemoOCXEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DDemoOCXEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DDemoOCXEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DDemoOCXEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DDemoOCXEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DDemoOCXEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DDemoOCXEventsVtbl;

    interface _DDemoOCXEvents
    {
        CONST_VTBL struct _DDemoOCXEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DDemoOCXEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DDemoOCXEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DDemoOCXEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DDemoOCXEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DDemoOCXEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DDemoOCXEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DDemoOCXEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DDemoOCXEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_DemoOCX;

#ifdef __cplusplus

class DECLSPEC_UUID("179ab540-078d-44cb-977e-a778973a5161")
DemoOCX;
#endif
#endif /* __DemoOCXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


