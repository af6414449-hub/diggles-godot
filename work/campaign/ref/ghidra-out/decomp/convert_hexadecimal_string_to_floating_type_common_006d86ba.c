
/* WARNING: Removing unreachable block (ram,0x006d8705) */
/* Library Function - Single Match
    enum SLD_STATUS __cdecl __crt_strtox::convert_hexadecimal_string_to_floating_type_common(struct
   __crt_strtox::floating_point_string const &,class __crt_strtox::floating_point_value const &)
   
   Library: Visual Studio 2019 Release */

SLD_STATUS __cdecl
__crt_strtox::convert_hexadecimal_string_to_floating_type_common
          (floating_point_string *param_1,floating_point_value *param_2)

{
  floating_point_string fVar1;
  int iVar2;
  uint uVar3;
  SLD_STATUS SVar4;
  int iVar5;
  floating_point_string *pfVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  __uint64 _Var10;
  int local_8;
  
  uVar7 = 0;
  pfVar6 = param_1 + 8;
  iVar2 = *(int *)(param_1 + 4);
  local_8 = 0;
  iVar5 = ((param_2[4] == (floating_point_value)0x0) - 1 & 0x1d) + 0x17 + *(int *)param_1;
  for (; (pfVar6 != param_1 + iVar2 + 8 &&
         (_Var10 = floating_point_value::normal_mantissa_mask(param_2),
         CONCAT44(local_8,uVar7) <= _Var10));
      local_8 = (local_8 << 4 | uVar3) + (uint)CARRY4(uVar8,(uint)(byte)fVar1)) {
    fVar1 = *pfVar6;
    uVar3 = uVar7 >> 0x1c;
    uVar8 = uVar7 * 0x10;
    uVar7 = uVar8 + (byte)fVar1;
    pfVar6 = pfVar6 + 1;
    iVar5 = iVar5 + -4;
  }
  bVar9 = true;
  while ((pfVar6 != param_1 + iVar2 + 8 && (bVar9))) {
    fVar1 = *pfVar6;
    pfVar6 = pfVar6 + 1;
    bVar9 = fVar1 == (floating_point_string)0x0;
  }
  SVar4 = assemble_floating_point_value
                    (CONCAT44(local_8,uVar7),iVar5,(bool)param_1[0x308],bVar9,param_2);
  return SVar4;
}

