
/* Library Function - Single Match
    _round
   
   Library: Visual Studio 2019 Release */

float10 __cdecl round(undefined8 param_1)

{
  short sVar1;
  
  sVar1 = __d_int(&param_1,1);
  if ((sVar1 < 1) || (2 < sVar1)) {
    sVar1 = __d_int(&param_1,0);
    if (sVar1 != 0) {
      if ((param_1._6_2_ & 0x8000) != 0) {
        return (float10)(double)CONCAT26(param_1._6_2_,(undefined6)param_1) - (float10)1.0;
      }
      return (float10)(double)CONCAT26(param_1._6_2_,(undefined6)param_1) + (float10)1.0;
    }
  }
  return (float10)(double)CONCAT26(param_1._6_2_,(undefined6)param_1);
}

