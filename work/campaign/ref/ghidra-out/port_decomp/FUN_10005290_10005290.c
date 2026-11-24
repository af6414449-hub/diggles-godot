
int FUN_10005290(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b70);
  puVar1 = (undefined4 *)FUN_10002850();
  iVar2 = __stdio_common_vsprintf_s(*puVar1,puVar1[1]);
  if (iVar2 < 0) {
    iVar2 = -1;
  }
  return iVar2;
}

