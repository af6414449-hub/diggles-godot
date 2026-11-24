
int FUN_10002860(void)

{
  uint *puVar1;
  int iVar2;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b70);
  puVar1 = (uint *)FUN_10002850();
  iVar2 = __stdio_common_vsprintf(*puVar1 | 2,puVar1[1]);
  if (iVar2 < 0) {
    iVar2 = -1;
  }
  return iVar2;
}

