
void FUN_100210b0(int *param_1)

{
  int iVar1;
  LPWAVEHDR pwh;
  code *pcVar2;
  undefined4 *puVar3;
  int local_8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if (*(HANDLE *)(iVar1 + 0x5c) != (HANDLE)0x0) {
      SetEvent(*(HANDLE *)(iVar1 + 0x5c));
    }
    if (*(HANDLE *)(iVar1 + 0x58) != (HANDLE)0x0) {
      SetEvent(*(HANDLE *)(iVar1 + 0x58));
    }
    pcVar2 = CloseHandle_exref;
    if (*(undefined4 **)(iVar1 + 0x68) != (undefined4 *)0x0) {
      WaitForSingleObject((HANDLE)**(undefined4 **)(iVar1 + 0x68),0xffffffff);
      puVar3 = *(undefined4 **)(iVar1 + 0x68);
      CloseHandle((HANDLE)*puVar3);
      FUN_100402ac(puVar3,4);
    }
    if (*(HWAVEOUT *)(iVar1 + 0x54) != (HWAVEOUT)0x0) {
      waveOutReset(*(HWAVEOUT *)(iVar1 + 0x54));
      puVar3 = (undefined4 *)(iVar1 + 0xc);
      local_8 = 2;
      pwh = (LPWAVEHDR)(iVar1 + 0x14);
      do {
        waveOutUnprepareHeader(*(HWAVEOUT *)(iVar1 + 0x54),pwh,0x20);
        if ((void *)*puVar3 != (void *)0x0) {
          free((void *)*puVar3);
        }
        puVar3 = puVar3 + 1;
        pwh = pwh + 1;
        local_8 = local_8 + -1;
      } while (local_8 != 0);
      waveOutClose(*(HWAVEOUT *)(iVar1 + 0x54));
      pcVar2 = CloseHandle_exref;
    }
    if (*(int *)(iVar1 + 0x5c) != 0) {
      (*pcVar2)(*(int *)(iVar1 + 0x5c));
    }
    if (*(int *)(iVar1 + 0x58) != 0) {
      (*pcVar2)(*(int *)(iVar1 + 0x58));
    }
    free(*(void **)(iVar1 + 4));
    FUN_100402ac(iVar1,0x6c);
    *param_1 = 0;
  }
  return;
}

