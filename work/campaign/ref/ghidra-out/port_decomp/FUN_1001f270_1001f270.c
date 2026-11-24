
void FUN_1001f270(byte param_1)

{
  void *_Memory;
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *in_ECX;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10042210;
  local_10 = ExceptionList;
  uVar2 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = SoLoud::WavStreamInstance::vftable;
  switch(*(undefined4 *)(in_ECX[0x70] + 0x68)) {
  case 0:
    if (in_ECX[0x73] == 0) break;
    FUN_10029b50();
    uVar5 = 0x178;
    iVar3 = in_ECX[0x73];
    goto LAB_1001f35a;
  case 1:
    _Memory = (void *)in_ECX[0x73];
    if ((_Memory != (void *)0x0) && (FUN_1003eea0(), *(int *)((int)_Memory + 0x5c) == 0)) {
      free(_Memory);
    }
    break;
  case 2:
    iVar3 = in_ECX[0x73];
    if (((iVar3 != 0) && ((undefined4 *)(iVar3 + 8) != (undefined4 *)0x0)) &&
       (*(code **)(iVar3 + 0x14) != (code *)0x0)) {
      (**(code **)(iVar3 + 0x14))(iVar3,*(undefined4 *)(iVar3 + 8));
    }
    break;
  case 3:
    iVar3 = in_ECX[0x73];
    if (iVar3 == 0) break;
    if (((*(int *)(iVar3 + 0x52b0) != 0) && ((undefined4 *)(iVar3 + 0x1a34) != (undefined4 *)0x0))
       && (*(code **)(iVar3 + 0x1a40) != (code *)0x0)) {
      (**(code **)(iVar3 + 0x1a40))(*(int *)(iVar3 + 0x52b0),*(undefined4 *)(iVar3 + 0x1a34),uVar2);
      iVar3 = in_ECX[0x73];
    }
    uVar5 = 0x52c8;
LAB_1001f35a:
    FUN_100402ac(iVar3,uVar5);
    in_ECX[0x73] = 0;
  }
  puVar1 = (undefined4 *)in_ECX[0x72];
  if ((puVar1 != *(undefined4 **)(in_ECX[0x70] + 0x74)) && (puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(1);
  }
  *in_ECX = SoLoud::AudioSourceInstance::vftable;
  piVar4 = in_ECX + 0x61;
  iVar3 = 8;
  do {
    if ((int *)*piVar4 != (int *)0x0) {
      (**(code **)(*(int *)*piVar4 + 0x20))(1);
    }
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if ((param_1 & 1) != 0) {
    FUN_100402ac();
  }
  ExceptionList = local_10;
  return;
}

