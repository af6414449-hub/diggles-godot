
void FUN_10010120(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *in_ECX;
  undefined1 local_14 [16];
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if ((-1 < (int)param_2) && (param_2 < *(uint *)(*in_ECX + 0x8c))) {
    iVar2 = *(int *)(*in_ECX + 0x90);
    puVar1 = (undefined4 *)(iVar2 + param_2 * 0x1c);
    uVar3 = puVar1[1];
    uVar4 = puVar1[2];
    uVar5 = puVar1[3];
    iVar2 = iVar2 + param_2 * 0x1c;
    *param_1 = *puVar1;
    param_1[1] = uVar3;
    param_1[2] = uVar4;
    param_1[3] = uVar5;
    *(undefined8 *)(param_1 + 4) = *(undefined8 *)(iVar2 + 0x10);
    param_1[6] = *(undefined4 *)(iVar2 + 0x18);
    return;
  }
  FUN_100053a0(0xffffffff);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_14,(ThrowInfo *)&DAT_1004a24c);
}

