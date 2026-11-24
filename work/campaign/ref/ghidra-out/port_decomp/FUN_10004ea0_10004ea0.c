
void FUN_10004ea0(void)

{
  undefined4 *puVar1;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  puVar1 = (undefined4 *)SteamInternal_ContextInit(&PTR_FUN_10050054);
                    /* WARNING: Could not recover jumptable at 0x10004ebc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)*puVar1 + 0x28))();
  return;
}

