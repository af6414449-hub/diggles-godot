
/* Library Function - Single Match
    __87except
   
   Library: Visual Studio 2019 Release */

void __87except(int param_1,int *param_2,ushort *param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_94;
  undefined1 local_90 [48];
  undefined8 local_60;
  uint local_50;
  uint local_14;
  
  local_14 = DAT_0076700c ^ (uint)&stack0xfffffff0;
  local_94 = (uint)*param_3;
  iVar2 = *param_2;
  if (iVar2 == 1) {
LAB_006f35a7:
    uVar3 = 8;
LAB_006f35a9:
    iVar2 = FUN_006e737c(uVar3,param_2 + 6,local_94);
    if (iVar2 == 0) {
      if (((param_1 == 0x10) || (param_1 == 0x16)) || (param_1 == 0x1d)) {
        local_60 = *(undefined8 *)(param_2 + 4);
        local_50 = local_50 & 0xffffffe3 | 3;
      }
      else {
        local_50 = local_50 & 0xfffffffe;
      }
      __raise_exc(local_90,&local_94,uVar3,param_1,param_2 + 2,param_2 + 6);
    }
  }
  else {
    if (iVar2 == 2) {
      uVar3 = 4;
      goto LAB_006f35a9;
    }
    if (iVar2 == 3) {
      uVar3 = 0x11;
      goto LAB_006f35a9;
    }
    if (iVar2 == 4) {
      uVar3 = 0x12;
      goto LAB_006f35a9;
    }
    if (iVar2 == 5) goto LAB_006f35a7;
    if (iVar2 == 8) {
      uVar3 = 0x10;
      goto LAB_006f35a9;
    }
  }
  __ctrlfp(local_94,0xffff);
  if (*param_2 != 8) {
    cVar1 = ___acrt_has_user_matherr();
    if (cVar1 != '\0') {
      iVar2 = ___acrt_invoke_user_matherr(param_2);
      if (iVar2 != 0) goto LAB_006f3636;
    }
  }
  __set_errno_from_matherr(*param_2);
LAB_006f3636:
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffff0);
  return;
}

