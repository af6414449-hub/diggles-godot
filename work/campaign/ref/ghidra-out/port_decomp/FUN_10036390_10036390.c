
void FUN_10036390(void)

{
  uint *puVar1;
  char cVar2;
  char cVar4;
  int iVar3;
  undefined4 *in_ECX;
  uint uVar5;
  uint uVar6;
  int *in_stack_00000010;
  undefined4 in_stack_00000014;
  undefined1 local_14 [2];
  char cStack_12;
  char cStack_11;
  undefined1 local_10;
  byte local_f;
  uint local_e;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  if (in_ECX != (undefined4 *)0x0) {
    memset(in_ECX,0,0x11b8);
    *in_ECX = FUN_1001ec50;
    in_ECX[1] = FUN_1001ec70;
    in_ECX[3] = 2;
    in_ECX[4] = in_stack_00000010;
    in_ECX[5] = in_stack_00000014;
    in_ECX[0x10] = FUN_1001ec50;
    in_ECX[0x11] = FUN_1001ec70;
    in_ECX[0x12] = in_stack_00000010;
    FUN_1002d430();
    iVar3 = (**(code **)(*in_stack_00000010 + 8))(local_14,4);
    if (iVar3 == 4) {
      while( true ) {
        puVar1 = in_ECX + 0xc;
        uVar6 = *puVar1;
        *puVar1 = *puVar1 + 4;
        in_ECX[0xd] = in_ECX[0xd] + (uint)(0xfffffffb < uVar6);
        cVar2 = (char)_local_14;
        cVar4 = (char)((uint)_local_14 >> 8);
        if (cVar2 != 'I') break;
        if ((cVar4 != 'D') || (cStack_12 != '3')) goto LAB_100364b2;
        iVar3 = (**(code **)(*in_stack_00000010 + 8))(&local_10,6);
        if (iVar3 != 6) goto LAB_100364b2;
        puVar1 = in_ECX + 0xc;
        uVar6 = *puVar1;
        *puVar1 = *puVar1 + 6;
        in_ECX[0xd] = in_ECX[0xd] + (uint)(0xfffffff9 < uVar6);
        uVar5 = ((((local_e & 0x7f) << 0x18) >> 1 | (local_e & 0x7f00) << 8) >> 1 |
                (local_e & 0xff0000) >> 8 & 0x7f00) >> 1 | local_e >> 0x18 & 0x7f;
        uVar6 = uVar5 + 10;
        if ((local_f & 0x10) == 0) {
          uVar6 = uVar5;
        }
        iVar3 = (**(code **)(*in_stack_00000010 + 0x14))();
        (**(code **)(*in_stack_00000010 + 0x10))(iVar3 + uVar6);
        puVar1 = in_ECX + 0xc;
        uVar5 = *puVar1;
        *puVar1 = *puVar1 + uVar6;
        in_ECX[0xd] = in_ECX[0xd] + (uint)CARRY4(uVar5,uVar6);
        iVar3 = (**(code **)(*in_stack_00000010 + 8))(local_14,4);
        if (iVar3 != 4) goto LAB_100364b2;
      }
      if (cVar2 == 'f') {
        if (((cVar4 == 'L') && (cStack_12 == 'a')) && (cStack_11 == 'C')) {
          FUN_100357d0();
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
      }
      else if ((((cVar2 == 'O') && (cVar4 == 'g')) && (cStack_12 == 'g')) && (cStack_11 == 'S')) {
        FUN_10036080();
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
LAB_100364b2:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

