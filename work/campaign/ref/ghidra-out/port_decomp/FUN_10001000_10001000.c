
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10001000(void)

{
  int iVar1;
  undefined4 in_EDX;
  char *local_6c;
  undefined4 local_68;
  char *local_64;
  undefined4 local_60;
  char *local_5c;
  undefined4 local_58;
  char *local_54;
  undefined4 local_50;
  char *local_4c;
  undefined4 local_48;
  char *local_44;
  undefined4 local_40;
  char *local_3c;
  undefined4 local_38;
  char *local_34;
  undefined4 local_30;
  char *local_2c;
  undefined4 local_28;
  char *local_24;
  undefined4 local_20;
  char *local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1004164f;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  local_6c = "ACH_WELCOME";
  local_68 = 0;
  local_64 = "ACH_THIEF_FIGHT";
  local_60 = 1;
  local_5c = "ACH_FINISH_TUTORIAL";
  local_58 = 2;
  local_54 = "ACH_END_OF_WORLD_1";
  local_50 = 3;
  local_4c = "ACH_END_OF_WORLD_2";
  local_48 = 4;
  local_44 = "ACH_END_OF_WORLD_3";
  local_40 = 5;
  local_3c = "ACH_END_OF_WORLD_4";
  local_38 = 6;
  local_34 = "ACH_COMPLETE_THE_CAMPAIGN";
  local_30 = 7;
  local_2c = "ACH_WATCH_END_CREDITS_UNTIL_THE_END";
  local_28 = 8;
  local_24 = "ACH_PLAY_X_HOURS";
  local_20 = 9;
  local_1c = "ACH_FINISH_ALL_QUESTS_MISSIONS";
  local_18 = 10;
  _DAT_10050cc0 = 0;
  iVar1 = FUN_1003ff62(0x18);
  *(int *)iVar1 = iVar1;
  *(int *)(iVar1 + 4) = iVar1;
  *(int *)(iVar1 + 8) = iVar1;
  *(undefined2 *)(iVar1 + 0xc) = 0x101;
  _DAT_10050cc0 = CONCAT44(_DAT_10050cc4,iVar1);
  local_8 = 0;
  FUN_10003b00(&local_6c,&local_14);
  _atexit(FUN_10042c80);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

