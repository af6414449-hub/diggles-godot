
/* Library Function - Multiple Matches With Different Base Names
    ___stdio_common_vfprintf
    ___stdio_common_vfprintf_p
    ___stdio_common_vfprintf_s
    ___stdio_common_vfwprintf
     6 names - too many to list
   
   Library: Visual Studio 2019 Release */

undefined4
FID_conflict____stdio_common_vfprintf
          (undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
          undefined4 param_6)

{
  int *piVar1;
  undefined4 uVar2;
  int *local_3c;
  undefined4 *local_38;
  undefined4 *local_34;
  int *local_30;
  undefined4 *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  int local_c [2];
  
  local_18 = param_6;
  local_10 = param_5;
  local_28 = param_1;
  local_14 = param_4;
  local_c[0] = param_3;
  local_24 = param_2;
  if ((param_3 != 0) && (param_4 != 0)) {
    local_3c = local_c;
    local_1c = param_3;
    local_38 = &local_10;
    local_34 = &local_28;
    local_30 = &local_14;
    local_2c = &local_18;
    local_20 = param_3;
    uVar2 = operator()<>(&local_20,&local_3c,&local_1c);
    return uVar2;
  }
  piVar1 = __errno();
  *piVar1 = 0x16;
  FUN_006e510d();
  return 0xffffffff;
}

