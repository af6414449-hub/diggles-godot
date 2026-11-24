
/* Library Function - Multiple Matches With Different Base Names
    __wtof
    _atof
   
   Library: Visual Studio 2019 Release */

double __cdecl FID_conflict__atof(wchar_t *_Str)

{
  float10 fVar1;
  
  fVar1 = (float10)common_atof_l<>(_Str,0);
  return (double)fVar1;
}

