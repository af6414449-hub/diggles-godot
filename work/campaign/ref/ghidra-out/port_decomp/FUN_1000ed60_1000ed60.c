
void FUN_1000ed60(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 in_EDX;
  int *piVar6;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10042300;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  if (DAT_10050c64 != 0) {
    OutputDebugStringA("Resetting Dex object. \n");
    iVar2 = DAT_10050c64;
    if (DAT_10050c64 != 0) {
      FUN_1000dee0();
      FUN_100402ac(iVar2,0xcbc);
    }
    piVar3 = DAT_10050c68;
    DAT_10050c64 = 0;
    if (DAT_10050c68 != (int *)0x0) {
      local_8 = 0;
      piVar6 = *(int **)*DAT_10050c68;
      if (piVar6 != (int *)*DAT_10050c68) {
        do {
          local_18 = piVar6[4];
          piVar5 = (int *)FUN_10011000(&local_18);
          iVar2 = *piVar5;
          if (iVar2 != 0) {
            FUN_100108b0();
            FUN_100402ac(iVar2,0x24);
          }
          piVar5 = (int *)piVar6[2];
          if (*(char *)((int)piVar5 + 0xd) == '\0') {
            cVar1 = *(char *)(*piVar5 + 0xd);
            piVar6 = piVar5;
            piVar5 = (int *)*piVar5;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar5 + 0xd);
              piVar6 = piVar5;
              piVar5 = (int *)*piVar5;
            }
          }
          else {
            cVar1 = *(char *)(piVar6[1] + 0xd);
            piVar4 = (int *)piVar6[1];
            piVar5 = piVar6;
            while ((piVar6 = piVar4, cVar1 == '\0' && (piVar5 == (int *)piVar6[2]))) {
              cVar1 = *(char *)(piVar6[1] + 0xd);
              piVar4 = (int *)piVar6[1];
              piVar5 = piVar6;
            }
          }
        } while (piVar6 != (int *)*piVar3);
      }
      iVar2 = piVar3[2];
      if (iVar2 != 0) {
        FUN_100108b0();
        FUN_100402ac(iVar2,0x24);
      }
      FUN_10003950();
      local_8 = 0xffffffff;
      FUN_100402ac(piVar3,0xc);
    }
    piVar3 = DAT_10050c6c;
    DAT_10050c68 = (int *)0x0;
    if (DAT_10050c6c != (int *)0x0) {
      local_8 = 1;
      piVar6 = *(int **)*DAT_10050c6c;
      if (piVar6 != (int *)*DAT_10050c6c) {
        do {
          (**(code **)(*(int *)piVar6[5] + 8))((int *)piVar6[5]);
          piVar5 = (int *)piVar6[2];
          if (*(char *)((int)piVar5 + 0xd) == '\0') {
            cVar1 = *(char *)(*piVar5 + 0xd);
            piVar6 = piVar5;
            piVar5 = (int *)*piVar5;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar5 + 0xd);
              piVar6 = piVar5;
              piVar5 = (int *)*piVar5;
            }
          }
          else {
            cVar1 = *(char *)(piVar6[1] + 0xd);
            piVar4 = (int *)piVar6[1];
            piVar5 = piVar6;
            while ((piVar6 = piVar4, cVar1 == '\0' && (piVar5 == (int *)piVar6[2]))) {
              cVar1 = *(char *)(piVar6[1] + 0xd);
              piVar4 = (int *)piVar6[1];
              piVar5 = piVar6;
            }
          }
        } while (piVar6 != (int *)*piVar3);
      }
      FUN_10003950();
      FUN_100402ac(piVar3,8);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

