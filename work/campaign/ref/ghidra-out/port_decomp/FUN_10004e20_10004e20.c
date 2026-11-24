
undefined4 FUN_10004e20(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (ServiceState::g_StatsAndAchievementsRetrieved != false) {
    puVar1 = (undefined4 *)SteamInternal_ContextInit(&PTR_FUN_10050030);
                    /* WARNING: Could not recover jumptable at 0x10004e45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)**(undefined4 **)*puVar1)();
    return uVar2;
  }
  return 0;
}

