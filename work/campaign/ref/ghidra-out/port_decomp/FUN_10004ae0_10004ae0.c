
void FUN_10004ae0(void)

{
  undefined4 *puVar1;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  puVar1 = (undefined4 *)SteamInternal_ContextInit(&PTR_FUN_10050048);
                    /* WARNING: Could not recover jumptable at 0x10004aff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)*puVar1 + 4))();
  return;
}

