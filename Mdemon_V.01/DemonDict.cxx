// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME DemonDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "include/Headers.h"
#include "include/HeaderGui.h"
#include "include/HeaderValues.h"
#include "Demondef.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *Values_Dictionary();
   static void Values_TClassManip(TClass*);
   static void *new_Values(void *p = 0);
   static void *newArray_Values(Long_t size, void *p);
   static void delete_Values(void *p);
   static void deleteArray_Values(void *p);
   static void destruct_Values(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Values*)
   {
      ::Values *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Values));
      static ::ROOT::TGenericClassInfo 
         instance("Values", "include/HeaderValues.h", 33,
                  typeid(::Values), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &Values_Dictionary, isa_proxy, 0,
                  sizeof(::Values) );
      instance.SetNew(&new_Values);
      instance.SetNewArray(&newArray_Values);
      instance.SetDelete(&delete_Values);
      instance.SetDeleteArray(&deleteArray_Values);
      instance.SetDestructor(&destruct_Values);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Values*)
   {
      return GenerateInitInstanceLocal((::Values*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Values*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *Values_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Values*)0x0)->GetClass();
      Values_TClassManip(theClass);
   return theClass;
   }

   static void Values_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *Mdemon_Dictionary();
   static void Mdemon_TClassManip(TClass*);
   static void delete_Mdemon(void *p);
   static void deleteArray_Mdemon(void *p);
   static void destruct_Mdemon(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Mdemon*)
   {
      ::Mdemon *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Mdemon));
      static ::ROOT::TGenericClassInfo 
         instance("Mdemon", "include/HeaderGui.h", 37,
                  typeid(::Mdemon), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &Mdemon_Dictionary, isa_proxy, 0,
                  sizeof(::Mdemon) );
      instance.SetDelete(&delete_Mdemon);
      instance.SetDeleteArray(&deleteArray_Mdemon);
      instance.SetDestructor(&destruct_Mdemon);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Mdemon*)
   {
      return GenerateInitInstanceLocal((::Mdemon*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Mdemon*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *Mdemon_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Mdemon*)0x0)->GetClass();
      Mdemon_TClassManip(theClass);
   return theClass;
   }

   static void Mdemon_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_Values(void *p) {
      return  p ? new(p) ::Values : new ::Values;
   }
   static void *newArray_Values(Long_t nElements, void *p) {
      return p ? new(p) ::Values[nElements] : new ::Values[nElements];
   }
   // Wrapper around operator delete
   static void delete_Values(void *p) {
      delete ((::Values*)p);
   }
   static void deleteArray_Values(void *p) {
      delete [] ((::Values*)p);
   }
   static void destruct_Values(void *p) {
      typedef ::Values current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Values

namespace ROOT {
   // Wrapper around operator delete
   static void delete_Mdemon(void *p) {
      delete ((::Mdemon*)p);
   }
   static void deleteArray_Mdemon(void *p) {
      delete [] ((::Mdemon*)p);
   }
   static void destruct_Mdemon(void *p) {
      typedef ::Mdemon current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Mdemon

namespace {
  void TriggerDictionaryInitialization_DemonDict_Impl() {
    static const char* headers[] = {
"include/Headers.h",
"include/HeaderGui.h",
"include/HeaderValues.h",
"Demondef.h",
0
    };
    static const char* includePaths[] = {
"/home/sebastian/software/root/include",
"/home/sebastian/Desktop/SoftwareRegistro/Mdemon/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "DemonDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$include/HeaderGui.h")))  Values;
class __attribute__((annotate("$clingAutoload$include/HeaderGui.h")))  Mdemon;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "DemonDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "include/Headers.h"
#include "include/HeaderGui.h"
#include "include/HeaderValues.h"
#include "Demondef.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Mdemon", payloadCode, "@",
"Values", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("DemonDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_DemonDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_DemonDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_DemonDict() {
  TriggerDictionaryInitialization_DemonDict_Impl();
}
