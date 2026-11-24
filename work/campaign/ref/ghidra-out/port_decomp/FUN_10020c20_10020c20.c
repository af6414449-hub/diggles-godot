
void FUN_10020c20(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  void *_Memory;
  int iVar4;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = *param_1;
  if (iVar1 != 0) {
    SetEvent(*(HANDLE *)(iVar1 + 0x18));
    SetEvent(*(HANDLE *)(iVar1 + 0x14));
    WaitForSingleObject((HANDLE)**(undefined4 **)(iVar1 + 0x20),0xffffffff);
    puVar2 = *(undefined4 **)(iVar1 + 0x20);
    CloseHandle((HANDLE)*puVar2);
    FUN_100402ac(puVar2,4);
    piVar3 = *(int **)(iVar1 + 0x10);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x50))(piVar3,0,0);
      (**(code **)(**(int **)(iVar1 + 0x10) + 0x58))(*(int **)(iVar1 + 0x10));
    }
    piVar3 = *(int **)(iVar1 + 8);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(piVar3);
    }
    piVar3 = *(int **)(iVar1 + 0x10);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x48))(piVar3);
    }
    if (*(int **)(iVar1 + 0x1c) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0x1c) + 0x1c))(1);
    }
    piVar3 = *(int **)(iVar1 + 0xc);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x48))(piVar3);
    }
    piVar3 = *(int **)(iVar1 + 8);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    iVar4 = 0;
    do {
      _Memory = *(void **)(iVar1 + iVar4 * 4);
      if (_Memory != (void *)0x0) {
        free(_Memory);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    CloseHandle(*(HANDLE *)(iVar1 + 0x14));
    CloseHandle(*(HANDLE *)(iVar1 + 0x18));
    FUN_100402ac(iVar1,0x30);
    *param_1 = 0;
                    /* WARNING: Could not recover jumptable at 0x10020d0b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    CoUninitialize();
    return;
  }
  return;
}

