
void FUN_1000bc30(void)

{
  code *pcVar1;
  int iVar2;
  void *_Dst;
  undefined8 *puVar3;
  int *piVar4;
  int *in_ECX;
  undefined4 in_EDX;
  int *piVar5;
  undefined1 local_4c [12];
  undefined8 local_40;
  undefined4 local_34;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100420d5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  *in_ECX = 0;
  in_ECX[1] = 0;
  iVar2 = FUN_1003ff62(0x18);
  *(int *)iVar2 = iVar2;
  *(int *)(iVar2 + 4) = iVar2;
  *(int *)(iVar2 + 8) = iVar2;
  *(undefined2 *)(iVar2 + 0xc) = 0x101;
  *in_ECX = iVar2;
  local_8._1_3_ = 0;
  in_ECX[10] = -1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  local_14 = DAT_10050ec0;
  if (DAT_10050ebc != DAT_10050ec0) {
    local_34 = 0;
    piVar5 = DAT_10050ebc;
    do {
      local_8._0_1_ = 0;
      _Dst = (void *)FUN_1003ff62(0x84);
      memset(_Dst,0,0x84);
      iVar2 = FUN_10009500(piVar5 + 1,piVar5 + 7,*piVar5);
      local_24 = *piVar5;
      local_8._0_1_ = 2;
      local_20 = iVar2;
      local_1c = iVar2;
      local_18 = local_24;
      puVar3 = (undefined8 *)FUN_1000c730(local_4c,&local_24);
      local_40 = *puVar3;
      if ((*(char *)(*(int *)(puVar3 + 1) + 0xd) == '\0') &&
         (*(int *)(*(int *)(puVar3 + 1) + 0x10) <= local_18)) {
        if (iVar2 != 0) {
          FUN_100095b0();
          FUN_100402ac(iVar2,0x84);
        }
      }
      else {
        if (in_ECX[1] == 0xaaaaaaa) {
          FUN_10002ad0();
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        iVar2 = *in_ECX;
        local_8._0_1_ = 3;
        local_28 = 0;
        piVar4 = (int *)FUN_1003ff62(0x18);
        local_20 = 0;
        local_28 = 0;
        piVar4[4] = local_18;
        piVar4[5] = local_1c;
        *piVar4 = iVar2;
        piVar4[1] = iVar2;
        piVar4[2] = iVar2;
        *(undefined2 *)(piVar4 + 3) = 0;
        FUN_10003d60((undefined4)local_40,local_40._4_4_,piVar4);
      }
      piVar5 = piVar5 + 10;
    } while (piVar5 != local_14);
  }
  ExceptionList = local_10;
  return;
}

