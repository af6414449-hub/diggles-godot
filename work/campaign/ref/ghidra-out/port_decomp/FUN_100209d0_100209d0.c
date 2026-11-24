
void FUN_100209d0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = *param_1;
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x1c) = 0;
    if (*(undefined4 **)(iVar1 + 0x18) != (undefined4 *)0x0) {
      WaitForSingleObject((HANDLE)**(undefined4 **)(iVar1 + 0x18),0xffffffff);
      puVar2 = *(undefined4 **)(iVar1 + 0x18);
      CloseHandle((HANDLE)*puVar2);
      FUN_100402ac(puVar2,4);
    }
    free(*(void **)(iVar1 + 4));
    FUN_100402ac(iVar1,0x20);
    *param_1 = 0;
  }
  return;
}

