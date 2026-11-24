
/* Library Function - Single Match
    enum SLD_STATUS __cdecl __crt_strtox::assemble_floating_point_value_from_big_integer(struct
   __crt_strtox::big_integer const &,unsigned int,bool,bool,class __crt_strtox::floating_point_value
   const &)
   
   Library: Visual Studio 2019 Release */

SLD_STATUS __cdecl
__crt_strtox::assemble_floating_point_value_from_big_integer
          (big_integer *param_1,uint param_2,bool param_3,bool param_4,floating_point_value *param_5
          )

{
  big_integer *pbVar1;
  big_integer *pbVar2;
  uint uVar3;
  __uint64 _Var4;
  bool bVar5;
  SLD_STATUS SVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  
  iVar9 = ((param_5[4] == (floating_point_value)0x0) - 1 & 0x1d) + 0x17;
  if (param_2 < 0x41) {
    if (*(int *)param_1 == 0) {
      uVar10 = 0;
    }
    else {
      uVar10 = *(undefined4 *)(param_1 + 4);
    }
    if (*(uint *)param_1 < 2) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined4 *)(param_1 + 8);
    }
    _Var4 = CONCAT44(uVar7,uVar10);
    bVar5 = !param_4;
  }
  else {
    uVar8 = param_2 & 0x1f;
    iVar11 = (param_2 >> 5) - 2;
    uVar3 = *(uint *)(param_1 + iVar11 * 4 + 4);
    pbVar1 = param_1 + (param_2 >> 5) * 4;
    if (uVar8 == 0) {
      iVar9 = iVar11 * 0x20 + iVar9;
      pbVar2 = param_1 + iVar11 * 4 + 4;
      bVar5 = !param_4;
      for (; _Var4 = CONCAT44(*(undefined4 *)pbVar1,*(undefined4 *)pbVar2), iVar11 != 0;
          iVar11 = iVar11 + -1) {
        param_1 = param_1 + 4;
        bVar5 = (bool)(bVar5 & (*(int *)param_1 != 0) - 1U);
      }
    }
    else {
      bVar5 = true;
      iVar9 = iVar11 * 0x20 + uVar8 + iVar9;
      lVar12 = __allshl();
      lVar13 = __allshl();
      lVar14 = __aullshr();
      _Var4 = lVar12 + lVar13 + lVar14;
      if ((param_4) || (((1 << (sbyte)uVar8) - 1U & uVar3) != 0)) {
        bVar5 = false;
      }
      for (; iVar11 != 0; iVar11 = iVar11 + -1) {
        param_1 = param_1 + 4;
        bVar5 = (bool)(bVar5 & (*(int *)param_1 != 0) - 1U);
      }
    }
  }
  SVar6 = assemble_floating_point_value(_Var4,iVar9,param_3,bVar5,param_5);
  return SVar6;
}

