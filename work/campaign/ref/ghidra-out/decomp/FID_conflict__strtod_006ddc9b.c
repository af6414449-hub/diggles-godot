
/* Library Function - Multiple Matches With Different Base Names
    _strtod
    _strtold
    _wcstod
    _wcstold
   
   Library: Visual Studio 2019 Release */

double __cdecl FID_conflict__strtod(wchar_t *_Str,wchar_t **_EndPtr)

{
  float10 fVar1;
  
  fVar1 = (float10)common_strtod_l<>(_Str,_EndPtr,0);
  return (double)fVar1;
}

