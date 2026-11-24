
/* Library Function - Single Match
    void __cdecl store_string(wchar_t const *,wchar_t * * const,unsigned int * const)
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl store_string(wchar_t *param_1,wchar_t **param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3;
  for (; (uVar1 != 0 && (*param_1 != L'\0')); param_1 = param_1 + 1) {
    **param_2 = *param_1;
    *param_2 = *param_2 + 1;
    *param_3 = *param_3 - 1;
    uVar1 = *param_3;
  }
  return;
}

