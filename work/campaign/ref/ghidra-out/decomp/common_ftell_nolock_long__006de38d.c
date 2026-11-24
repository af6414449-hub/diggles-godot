
/* Library Function - Single Match
    long __cdecl common_ftell_nolock<long>(class __crt_stdio_stream)
   
   Library: Visual Studio 2019 Release */

long __cdecl common_ftell_nolock<long>(undefined4 param_1)

{
  int *piVar1;
  uint uVar2;
  __int64 _Var3;
  
  _Var3 = common_ftell_nolock<__int64>(param_1);
  uVar2 = (uint)_Var3;
  if ((-1 < _Var3) && (((int)((ulonglong)_Var3 >> 0x20) != 0 && -1 < _Var3 || (0x7fffffff < uVar2)))
     ) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

