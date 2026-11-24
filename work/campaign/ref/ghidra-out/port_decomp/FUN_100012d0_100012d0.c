
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100012d0(void)

{
  int iVar1;
  undefined4 in_EDX;
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
  puStack_c = &LAB_100416cf;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  local_2c = "STAT_PLAY_X_HOURS";
  local_28 = 9;
  local_24 = "STAT_FINISH_ALL_QUESTS_MISSIONS";
  local_20 = 10;
  local_1c = "STAT_THIEF_FIGHT";
  local_18 = 1;
  _DAT_10050cd0 = 0;
  iVar1 = FUN_1003ff62(0x18);
  *(int *)iVar1 = iVar1;
  *(int *)(iVar1 + 4) = iVar1;
  *(int *)(iVar1 + 8) = iVar1;
  *(undefined2 *)(iVar1 + 0xc) = 0x101;
  _DAT_10050cd0 = CONCAT44(_DAT_10050cd4,iVar1);
  local_8 = 0;
  FUN_10003b00(&local_2c,&local_14);
  _atexit(FUN_10042ca0);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

