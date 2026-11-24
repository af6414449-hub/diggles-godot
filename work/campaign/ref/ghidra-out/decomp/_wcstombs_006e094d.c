
/* Library Function - Single Match
    _wcstombs
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

size_t __cdecl _wcstombs(char *_Dest,wchar_t *_Source,size_t _MaxCount)

{
  uint uVar1;
  
  uVar1 = _wcstombs_l_helper(_Dest,_Source,_MaxCount,(__crt_locale_pointers *)0x0);
  return uVar1;
}

