
/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 2019 Release */

_onexit_t __cdecl __onexit(_onexit_t _Func)

{
  int iVar1;
  
  if (DAT_100508c4 == -1) {
    iVar1 = crt_atexit();
  }
  else {
    iVar1 = register_onexit_function(&DAT_100508c4,_Func);
  }
  return (_onexit_t)(~-(uint)(iVar1 != 0) & (uint)_Func);
}

