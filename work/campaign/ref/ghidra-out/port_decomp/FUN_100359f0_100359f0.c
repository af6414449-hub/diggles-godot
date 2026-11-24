
void FUN_100359f0(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  code *in_ECX;
  char local_c;
  char local_b;
  char local_a;
  char local_9;
  
  uVar2 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  *param_2 = 0;
  iVar3 = (*in_ECX)();
  if (iVar3 == 4) {
    *param_2 = *param_2 + 4;
    while( true ) {
      while( true ) {
        cVar1 = local_a;
        if ((((local_c != 'O') || (local_b != 'g')) || (local_a != 'g')) || (local_9 != 'S')) break;
        *param_3 = 0x5fb0a94f;
        iVar3 = FUN_10035930(param_1,param_2,0x67);
        if (iVar3 == 0) {
          __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
          return;
        }
        if (iVar3 != -0x81) {
          __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
          return;
        }
      }
      local_a = local_9;
      local_c = local_b;
      local_b = cVar1;
      iVar3 = (*in_ECX)();
      if (iVar3 != 1) break;
      *param_2 = *param_2 + 1;
    }
  }
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

