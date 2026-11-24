
int * FUN_10011470(int *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  code *pcVar4;
  int *piVar5;
  int *in_ECX;
  int *piVar6;
  undefined4 in_EDX;
  int *piVar7;
  int *local_28;
  int local_24;
  int local_20;
  int *local_1c;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1004249d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = param_1;
  __CheckForDebuggerJustMyCode(&DAT_14170680,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  FUN_1000c730(&local_28,param_2);
  if ((*(char *)(local_20 + 0xd) == '\0') && (*(int *)(local_20 + 0x10) <= *param_2)) {
    *param_1 = local_20;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return param_1;
  }
  if (in_ECX[1] == 0xaaaaaaa) {
    FUN_10002ad0();
    pcVar4 = (code *)swi(3);
    piVar5 = (int *)(*pcVar4)();
    return piVar5;
  }
  iVar2 = *in_ECX;
  local_8 = 0;
  local_14 = (int *)0x0;
  piVar5 = (int *)FUN_1003ff62(0x18);
  piVar5[4] = *param_2;
  piVar5[5] = 0;
  *piVar5 = iVar2;
  piVar5[1] = iVar2;
  piVar5[2] = iVar2;
  *(undefined2 *)(piVar5 + 3) = 0;
  local_14 = (int *)*in_ECX;
  in_ECX[1] = in_ECX[1] + 1;
  piVar5[1] = (int)local_28;
  if (local_28 == local_14) {
    *local_14 = (int)piVar5;
    local_14[1] = (int)piVar5;
    local_14[2] = (int)piVar5;
    *(undefined1 *)(piVar5 + 3) = 1;
  }
  else {
    if (local_24 == 0) {
      local_28[2] = (int)piVar5;
      if (local_28 == (int *)local_14[2]) {
        local_14[2] = (int)piVar5;
      }
    }
    else {
      *local_28 = (int)piVar5;
      if (local_28 == (int *)*local_14) {
        *local_14 = (int)piVar5;
      }
    }
    cVar1 = *(char *)(piVar5[1] + 0xc);
    piVar7 = piVar5;
    while (cVar1 == '\0') {
      piVar3 = (int *)piVar7[1];
      piVar6 = *(int **)piVar3[1];
      if (piVar3 == piVar6) {
        piVar6 = (int *)((undefined4 *)piVar3[1])[2];
        if ((char)piVar6[3] == '\0') {
LAB_100115ca:
          *(undefined1 *)(piVar3 + 3) = 1;
          *(undefined1 *)(piVar6 + 3) = 1;
          *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0xc) = 0;
          piVar7 = *(int **)(piVar7[1] + 4);
        }
        else {
          if (piVar7 == (int *)piVar3[2]) {
            FUN_10004000(piVar3);
            piVar7 = piVar3;
          }
          *(undefined1 *)(piVar7[1] + 0xc) = 1;
          *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0xc) = 0;
          FUN_10003f90(*(undefined4 *)(piVar7[1] + 4));
        }
      }
      else {
        if ((char)piVar6[3] == '\0') goto LAB_100115ca;
        if (piVar7 == (int *)*piVar3) {
          FUN_10003f90(piVar3);
          piVar7 = piVar3;
        }
        *(undefined1 *)(piVar7[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0xc) = 0;
        FUN_10004000(*(undefined4 *)(piVar7[1] + 4));
      }
      cVar1 = *(char *)(piVar7[1] + 0xc);
    }
    *(undefined1 *)(local_14[1] + 0xc) = 1;
  }
  *local_1c = (int)piVar5;
  *(undefined1 *)(local_1c + 1) = 1;
  ExceptionList = local_10;
  return local_1c;
}

