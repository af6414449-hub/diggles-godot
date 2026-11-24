
/* Library Function - Single Match
    __except1
   
   Library: Visual Studio 2019 Release */

void __except1(undefined4 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
              undefined4 param_5)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_90 [64];
  uint local_50;
  uint local_14;
  
  uVar3 = param_5;
  local_14 = DAT_0076700c ^ (uint)&stack0xfffffff0;
  iVar2 = FUN_006e737c(param_1,&param_4,param_5);
  if (iVar2 == 0) {
    local_50 = local_50 & 0xfffffffe;
    __raise_exc_ex(local_90,&param_5,param_1,param_2,&param_3,&param_4,0);
    uVar3 = param_5;
  }
  iVar2 = __errcode(param_1);
  cVar1 = ___acrt_has_user_matherr();
  if ((cVar1 == '\0') || (iVar2 == 0)) {
    __set_errno_from_matherr(iVar2);
    __ctrlfp();
  }
  else {
    __umatherr(iVar2,param_2,param_3,0,param_4,uVar3);
  }
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffff0);
  return;
}

