
/* Library Function - Single Match
    public: class __crt_unique_heap_ptr<char,struct __crt_internal_free_policy> & __thiscall
   __crt_unique_heap_ptr<char,struct __crt_internal_free_policy>::operator=(class
   __crt_unique_heap_ptr<char,struct __crt_internal_free_policy> &&)
   
   Library: Visual Studio 2019 Release */

__crt_unique_heap_ptr<char,struct___crt_internal_free_policy> * __thiscall
__crt_unique_heap_ptr<char,struct___crt_internal_free_policy>::operator=
          (__crt_unique_heap_ptr<char,struct___crt_internal_free_policy> *this,
          __crt_unique_heap_ptr<char,struct___crt_internal_free_policy> *param_1)

{
  FID_conflict__free(*(void **)this);
  *(undefined4 *)this = 0;
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)param_1 = 0;
  return this;
}

