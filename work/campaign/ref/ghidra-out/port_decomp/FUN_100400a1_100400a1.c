
void FUN_100400a1(void)

{
  int iVar1;
  
  iVar1 = ___scrt_is_ucrt_dll_in_use();
  if (iVar1 != 0) {
    execute_onexit_table(&DAT_100508c4);
    return;
  }
  iVar1 = FUN_10040fb3();
  if (iVar1 != 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x10040f92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _cexit();
  return;
}

