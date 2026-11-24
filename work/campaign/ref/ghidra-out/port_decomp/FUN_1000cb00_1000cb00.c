
int * FUN_1000cb00(int *param_1,uint *param_2)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  code *pcVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 in_EDX;
  undefined4 *puVar10;
  int *local_2c;
  int iStack_28;
  undefined1 local_20 [4];
  undefined4 *local_1c;
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100421ed;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = param_1;
  __CheckForDebuggerJustMyCode(&DAT_14170b81,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  puVar6 = (undefined8 *)FUN_1000ccf0(local_20,param_2);
  piVar8 = DAT_10051090;
  iVar3 = *(int *)(puVar6 + 1);
  uVar1 = *puVar6;
  if ((*(char *)(iVar3 + 0xd) == '\0') && (*(uint *)(iVar3 + 0x10) <= *param_2)) {
    *param_1 = iVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return param_1;
  }
  if (DAT_10051094 == 0xccccccc) {
    FUN_10002ad0();
    pcVar5 = (code *)swi(3);
    piVar8 = (int *)(*pcVar5)();
    return piVar8;
  }
  local_1c = &DAT_10051090;
  local_8 = 0;
  local_18 = 0;
  puVar7 = (undefined4 *)FUN_1003ff62(0x14);
  local_2c = (int *)uVar1;
  puVar7[4] = *param_2;
  *puVar7 = piVar8;
  puVar7[1] = piVar8;
  puVar7[2] = piVar8;
  *(undefined2 *)(puVar7 + 3) = 0;
  piVar8 = DAT_10051090;
  DAT_10051094 = DAT_10051094 + 1;
  puVar7[1] = local_2c;
  if (local_2c == piVar8) {
    *piVar8 = (int)puVar7;
    piVar8[1] = (int)puVar7;
    piVar8[2] = (int)puVar7;
    *(undefined1 *)(puVar7 + 3) = 1;
  }
  else {
    iStack_28 = (int)((ulonglong)uVar1 >> 0x20);
    if (iStack_28 == 0) {
      local_2c[2] = (int)puVar7;
      if (local_2c == (int *)piVar8[2]) {
        piVar8[2] = (int)puVar7;
      }
    }
    else {
      *local_2c = (int)puVar7;
      if (local_2c == (int *)*piVar8) {
        *piVar8 = (int)puVar7;
      }
    }
    cVar2 = *(char *)(puVar7[1] + 0xc);
    puVar10 = puVar7;
    while (cVar2 == '\0') {
      puVar4 = (undefined4 *)puVar10[1];
      puVar9 = *(undefined4 **)puVar4[1];
      if (puVar4 == puVar9) {
        puVar9 = (undefined4 *)((undefined4 *)puVar4[1])[2];
        if (*(char *)(puVar9 + 3) == '\0') {
LAB_1000cc65:
          *(undefined1 *)(puVar4 + 3) = 1;
          *(undefined1 *)(puVar9 + 3) = 1;
          *(undefined1 *)(*(int *)(puVar10[1] + 4) + 0xc) = 0;
          puVar10 = *(undefined4 **)(puVar10[1] + 4);
        }
        else {
          if (puVar10 == (undefined4 *)puVar4[2]) {
            FUN_10004000(puVar4);
            puVar10 = puVar4;
          }
          *(undefined1 *)(puVar10[1] + 0xc) = 1;
          *(undefined1 *)(*(int *)(puVar10[1] + 4) + 0xc) = 0;
          FUN_10003f90(*(undefined4 *)(puVar10[1] + 4));
        }
      }
      else {
        if (*(char *)(puVar9 + 3) == '\0') goto LAB_1000cc65;
        if (puVar10 == (undefined4 *)*puVar4) {
          FUN_10003f90(puVar4);
          puVar10 = puVar4;
        }
        *(undefined1 *)(puVar10[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(puVar10[1] + 4) + 0xc) = 0;
        FUN_10004000(*(undefined4 *)(puVar10[1] + 4));
      }
      cVar2 = *(char *)(puVar10[1] + 0xc);
    }
    *(undefined1 *)(piVar8[1] + 0xc) = 1;
  }
  *local_14 = (int)puVar7;
  *(undefined1 *)(local_14 + 1) = 1;
  ExceptionList = local_10;
  return local_14;
}

