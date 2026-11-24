
void FUN_10006900(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *in_ECX;
  undefined4 in_EDX;
  undefined1 local_15c [16];
  undefined4 *local_14c;
  undefined1 local_148 [256];
  undefined4 local_48;
  undefined4 local_44;
  byte local_24;
  int *local_20;
  int *local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041965;
  local_10 = ExceptionList;
  local_18 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14c = param_1;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_18);
  *param_1 = 0;
  local_1c = (int *)0x0;
  local_20 = (int *)0x0;
  local_8 = 1;
  iVar3 = (*(code *)**(undefined4 **)*in_ECX)((undefined4 *)*in_ECX,&DAT_100447a8,&local_20);
  if (-1 < iVar3) {
    iVar3 = 0;
    while( true ) {
      piVar2 = local_1c;
      piVar1 = local_20;
      if (local_1c != (int *)0x0) {
        local_1c = (int *)0x0;
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      iVar4 = (**(code **)(*piVar1 + 0x74))(piVar1,iVar3,2,&DAT_10044748,&local_1c);
      if (iVar4 < 0) goto LAB_100069fe;
      iVar4 = (**(code **)(*local_1c + 0x28))(local_1c,local_148);
      if (iVar4 < 0) goto LAB_10006ad8;
      if ((local_24 & 2) == 0) break;
      iVar3 = iVar3 + 1;
    }
    FUN_100028b0(&DAT_1416e410,0x100,"Direct3D Adapter (bygpu) (%u): VID:%04X, PID:%04X - %ls\n",
                 iVar3,local_48,local_44,local_148);
    OutputDebugStringA(&DAT_1416e410);
  }
LAB_100069fe:
  if (local_1c == (int *)0x0) {
    iVar3 = 0;
    do {
      piVar2 = local_1c;
      piVar1 = (int *)*in_ECX;
      if (local_1c != (int *)0x0) {
        local_1c = (int *)0x0;
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      iVar4 = (**(code **)(*piVar1 + 0x30))(piVar1,iVar3,&local_1c);
      if (iVar4 < 0) break;
      iVar4 = (**(code **)(*local_1c + 0x28))(local_1c,local_148);
      if (iVar4 < 0) {
LAB_10006ad8:
        FUN_100053a0(iVar4);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_15c,(ThrowInfo *)&DAT_1004a24c);
      }
      if ((local_24 & 2) == 0) goto LAB_10006a4c;
      iVar3 = iVar3 + 1;
    } while( true );
  }
LAB_10006a7c:
  piVar2 = local_1c;
  piVar1 = local_20;
  local_8 = local_8 & 0xffffff00;
  local_1c = (int *)0x0;
  *local_14c = piVar2;
  if (local_20 != (int *)0x0) {
    local_20 = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = local_1c;
  local_8 = 0xffffffff;
  if (local_1c != (int *)0x0) {
    local_1c = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
LAB_10006a4c:
  FUN_100028b0(&DAT_1416e710,0x100,"Direct3D Adapter (enum1) (%u): VID:%04X, PID:%04X - %ls\n",iVar3
               ,local_48,local_44,local_148);
  OutputDebugStringA(&DAT_1416e710);
  goto LAB_10006a7c;
}

