
/* Library Function - Single Match
    __umatherr
   
   Library: Visual Studio 2019 Release */

float10 __umatherr(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                  undefined4 param_9)

{
  int iVar1;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_20 = 0;
  iVar1 = 0;
  do {
    if ((&DAT_00717900)[iVar1 * 2] == param_2) {
      local_20 = *(int *)(&UNK_00717904 + iVar1 * 8);
      break;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1d);
  if (local_20 == 0) {
    __ctrlfp(param_9,0xffff);
    __set_errno_from_matherr(param_1);
    return (float10)(double)CONCAT44(param_8,param_7);
  }
  local_1c = param_3;
  local_18 = param_4;
  local_14 = param_5;
  local_10 = param_6;
  local_c = param_7;
  local_24 = param_1;
  uStack_8 = param_8;
  __ctrlfp(param_9,0xffff);
  iVar1 = ___acrt_invoke_user_matherr(&local_24);
  if (iVar1 == 0) {
    __set_errno_from_matherr(param_1);
  }
  return (float10)(double)CONCAT44(uStack_8,local_c);
}

