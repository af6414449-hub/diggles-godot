
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10001150(void)

{
  char *pcVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined8 *puVar5;
  int *piVar6;
  undefined4 in_EDX;
  char **ppcVar7;
  undefined1 local_4c [12];
  char *local_40 [7];
  undefined4 local_24;
  undefined8 local_20;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041697;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  local_40[0] = (char *)0x9;
  ppcVar7 = local_40;
  local_40[1] = "STAT_PLAY_X_HOURS";
  local_40[2] = (char *)0xa;
  local_40[3] = "STAT_FINISH_ALL_QUESTS_MISSIONS";
  local_40[4] = (char *)0x1;
  local_40[5] = "STAT_THIEF_FIGHT";
  _DAT_10050cc8 = 0;
  iVar4 = FUN_1003ff62(0x18);
  *(int *)iVar4 = iVar4;
  *(int *)(iVar4 + 4) = iVar4;
  *(int *)(iVar4 + 8) = iVar4;
  *(undefined2 *)(iVar4 + 0xc) = 0x101;
  local_8 = 0;
  DAT_10050cc8 = iVar4;
  if (ppcVar7 != local_40 + 6) {
    do {
      puVar5 = (undefined8 *)FUN_10004120(local_4c,iVar4,ppcVar7);
      iVar3 = DAT_10050cc8;
      local_20 = *puVar5;
      local_18 = *(undefined4 *)(puVar5 + 1);
      if ((char)local_18 == '\0') {
        if (DAT_10050ccc == 0xaaaaaaa) {
          FUN_10002ad0();
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        local_40[6] = (char *)&DAT_10050cc8;
        local_8._0_1_ = 1;
        local_24 = 0;
        piVar6 = (int *)FUN_1003ff62(0x18);
        local_8 = (uint)local_8._1_3_ << 8;
        pcVar1 = ppcVar7[1];
        piVar6[4] = (int)*ppcVar7;
        piVar6[5] = (int)pcVar1;
        *piVar6 = iVar3;
        piVar6[1] = iVar3;
        piVar6[2] = iVar3;
        *(undefined2 *)(piVar6 + 3) = 0;
        local_24 = 0;
        FUN_10003d60((undefined4)local_20,local_20._4_4_,piVar6);
      }
      ppcVar7 = ppcVar7 + 2;
    } while (ppcVar7 != local_40 + 6);
  }
  _atexit(FUN_10042c90);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

