
void FUN_10021420(void)

{
  undefined4 *puVar1;
  HANDLE pvVar2;
  undefined4 in_ECX;
  undefined4 in_EDX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  puVar1 = (undefined4 *)FUN_1003ff62(8);
  *puVar1 = in_ECX;
  puVar1[1] = in_EDX;
  pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_100213f0,puVar1,0,(LPDWORD)0x0);
  if (pvVar2 == (HANDLE)0x0) {
    return;
  }
  puVar1 = (undefined4 *)FUN_1003ff62(4);
  *puVar1 = pvVar2;
  return;
}

