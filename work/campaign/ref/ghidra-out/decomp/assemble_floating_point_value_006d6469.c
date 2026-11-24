
/* WARNING: Removing unreachable block (ram,0x006d6602) */
/* WARNING: Removing unreachable block (ram,0x006d6722) */
/* Library Function - Single Match
    enum SLD_STATUS __cdecl __crt_strtox::assemble_floating_point_value(unsigned
   __int64,int,bool,bool,class __crt_strtox::floating_point_value const &)
   
   Library: Visual Studio 2019 Release */

SLD_STATUS __cdecl
__crt_strtox::assemble_floating_point_value
          (__uint64 param_1,int param_2,bool param_3,bool param_4,floating_point_value *param_5)

{
  floating_point_value fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  double *pdVar6;
  SLD_STATUS SVar7;
  float *pfVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  longlong lVar12;
  __uint64 _Var13;
  int local_c;
  bool local_5;
  
  uVar9 = 0;
  if (param_1._4_4_ == 0) {
    iVar3 = 0x1f;
    if ((uint)param_1 != 0) {
      for (; (uint)param_1 >> iVar3 == 0; iVar3 = iVar3 + -1) {
      }
    }
    if ((uint)param_1 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = iVar3 + 1;
    }
  }
  else {
    iVar3 = 0x1f;
    if (param_1._4_4_ != 0) {
      for (; param_1._4_4_ >> iVar3 == 0; iVar3 = iVar3 + -1) {
      }
    }
    if (param_1._4_4_ == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = iVar3 + 1;
    }
    iVar3 = iVar3 + 0x20;
  }
  fVar1 = param_5[4];
  iVar3 = (((fVar1 == (floating_point_value)0x0) - 1 & 0x1d) + 0x18) - iVar3;
  local_c = param_2 - iVar3;
  iVar4 = ((fVar1 == (floating_point_value)0x0) - 1 & 0x380) + 0x7f;
  if (iVar4 < local_c) {
LAB_006d6748:
    assemble_floating_point_infinity(param_3,param_5);
    return 3;
  }
  if (local_c < (int)(((fVar1 == (floating_point_value)0x0) - 1 & 0xfffffc80) - 0x7e)) {
    iVar5 = param_2 + -1 + iVar4;
    local_c = -iVar4;
    if (iVar5 < 0) {
      if ((uint)-iVar5 < 0x40) {
        uVar10 = __allshl();
        uVar11 = __allshl();
        local_5 = (param_1 & uVar10) != 0;
        if ((!param_4) || (bVar2 = false, (uVar10 - 1 & param_1) != 0)) {
          bVar2 = true;
        }
        if ((local_5) || (bVar2)) {
          iVar4 = fegetround();
          if (iVar4 == 0) {
            if (((param_1 & uVar10) != 0) && ((bVar2 || ((param_1 & uVar11) != 0)))) {
              uVar9 = 1;
            }
          }
          else if (iVar4 == 0x100) {
            uVar9 = (uint)param_3;
          }
          else if (iVar4 == 0x200) {
            uVar9 = (uint)!param_3;
          }
        }
        lVar12 = __aullshr();
        param_1 = lVar12 + (ulonglong)uVar9;
        if (lVar12 + (ulonglong)uVar9 != 0) {
          _Var13 = floating_point_value::denormal_mantissa_mask(param_5);
          if (_Var13 < param_1) {
            local_c = ((param_2 - iVar5) - iVar3) + -1;
          }
          goto LAB_006d6772;
        }
      }
      assemble_floating_point_zero(param_3,param_5);
      return 2;
    }
  }
  else {
    if (iVar3 < 0) {
      if ((uint)-iVar3 < 0x40) {
        uVar10 = __allshl();
        uVar11 = __allshl();
        local_5 = (uVar10 & param_1) != 0;
        if ((!param_4) || (bVar2 = false, (uVar10 - 1 & param_1) != 0)) {
          bVar2 = true;
        }
        if ((local_5) || (bVar2)) {
          iVar3 = fegetround();
          if (iVar3 == 0) {
            if (((uVar10 & param_1) != 0) && ((bVar2 || ((uVar11 & param_1) != 0)))) {
              uVar9 = 1;
            }
          }
          else if (iVar3 == 0x100) {
            uVar9 = (uint)param_3;
          }
          else if (iVar3 == 0x200) {
            uVar9 = (uint)!param_3;
          }
        }
        lVar12 = __aullshr();
        param_1 = lVar12 + (ulonglong)uVar9;
      }
      else {
        param_1 = 0;
      }
      _Var13 = floating_point_value::normal_mantissa_mask(param_5);
      if (_Var13 < param_1) {
        param_1 = param_1 >> 1;
        local_c = local_c + 1;
        if ((int)(((param_5[4] == (floating_point_value)0x0) - 1 & 0x380) + 0x7f) < local_c)
        goto LAB_006d6748;
      }
      goto LAB_006d6772;
    }
    if (iVar3 < 1) goto LAB_006d6772;
  }
  param_1 = __allshl();
LAB_006d6772:
  _Var13 = floating_point_value::denormal_mantissa_mask(param_5);
  if (param_5[4] == (floating_point_value)0x0) {
    pfVar8 = floating_point_value::as_float(param_5);
    SVar7 = assemble_floating_point_value_t<float>(param_3,local_c,param_1 & _Var13,pfVar8);
  }
  else {
    pdVar6 = floating_point_value::as_double(param_5);
    SVar7 = assemble_floating_point_value_t<double>(param_3,local_c,param_1 & _Var13,pdVar6);
  }
  return SVar7;
}

