
void FUN_10004bc0(void)

{
  undefined4 *puVar1;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  puVar1 = (undefined4 *)SteamInternal_ContextInit(&PTR_FUN_1005003c);
                    /* WARNING: Could not recover jumptable at 0x10004bdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)*puVar1 + 0x14))();
  return;
}

