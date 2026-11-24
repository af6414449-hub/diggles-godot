
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100211a0(DWORD param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  LPWAVEHDR pwVar3;
  HANDLE pvVar4;
  MMRESULT MVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  LPWAVEHDR pwh;
  undefined4 *local_20;
  WAVEFORMATEX local_1c;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  puVar2 = (undefined4 *)FUN_1003ff62(0x6c);
  iVar8 = 2;
  pwh = (LPWAVEHDR)(puVar2 + 5);
  puVar2[1] = 0;
  local_20 = puVar2 + 3;
  *puVar2 = 0;
  puVar2[2] = 0;
  pwVar3 = pwh;
  puVar7 = local_20;
  do {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
    pwVar3->lpData = (LPSTR)0x0;
    pwVar3->dwBufferLength = 0;
    pwVar3->dwBytesRecorded = 0;
    pwVar3->dwUser = 0;
    pwVar3->dwFlags = 0;
    pwVar3->dwLoops = 0;
    pwVar3->lpNext = (wavehdr_tag *)0x0;
    pwVar3->reserved = 0;
    iVar8 = iVar8 + -1;
    pwVar3 = pwVar3 + 1;
  } while (iVar8 != 0);
  puVar2[0x15] = 0;
  puVar2[0x16] = 0;
  puVar2[0x17] = 0;
  puVar2[0x18] = 0;
  puVar2[0x19] = 0;
  puVar2[0x1a] = 0;
  _DAT_1005111c = FUN_100210b0;
  _DAT_10051110 = puVar2;
  puVar2[0x19] = param_2;
  puVar2[0x18] = &DAT_10051110;
  pvVar4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  puVar2[0x16] = pvVar4;
  if (pvVar4 != (HANDLE)0x0) {
    pvVar4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    puVar2[0x17] = pvVar4;
    if (pvVar4 != (HANDLE)0x0) {
      local_1c.nSamplesPerSec = param_1;
      local_1c.nAvgBytesPerSec = param_1 << 2;
      local_1c.wBitsPerSample = 0x10;
      local_1c.cbSize = 0;
      local_1c.wFormatTag = 1;
      local_1c.nChannels = 2;
      local_1c.nBlockAlign = 4;
      MVar5 = waveOutOpen((LPHWAVEOUT)(puVar2 + 0x15),0xffffffff,&local_1c,puVar2[0x16],0,0x50000);
      if (MVar5 == 0) {
        FUN_1001ac60(((uint)local_1c._0_4_ >> 0x10) * puVar2[0x19]);
        iVar8 = 0;
        do {
          lVar1 = (ulonglong)(((uint)local_1c._0_4_ >> 0x10) * puVar2[0x19]) * 2;
          uVar6 = FUN_100402f0(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
          *local_20 = uVar6;
          pwh->lpData = (LPSTR)0x0;
          pwh->dwBufferLength = 0;
          pwh->dwBytesRecorded = 0;
          pwh->dwUser = 0;
          uVar6 = 0x20;
          pwh->dwFlags = 0;
          pwh->dwLoops = 0;
          pwh->lpNext = (wavehdr_tag *)0x0;
          pwh->reserved = 0;
          pwh->dwBufferLength = ((uint)local_1c._0_4_ >> 0x10) * puVar2[0x19] * 2;
          pwh->lpData = (LPSTR)*local_20;
          pwVar3 = pwh;
          MVar5 = waveOutPrepareHeader((HWAVEOUT)puVar2[0x15],pwh,0x20);
          if (MVar5 != 0) goto LAB_10021362;
          local_20 = local_20 + 1;
          iVar8 = iVar8 + 1;
          pwh = pwh + 1;
        } while (iVar8 < 2);
        FUN_1001b250(param_1,((uint)local_1c._0_4_ >> 0x10) * puVar2[0x19],pwVar3,uVar6);
        puVar7 = (undefined4 *)FUN_1003ff62(8);
        *puVar7 = FUN_10020f90;
        puVar7[1] = puVar2;
        pvVar4 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_100213f0,puVar7,0,(LPDWORD)0x0);
        if (pvVar4 == (HANDLE)0x0) {
          puVar2[0x1a] = 0;
        }
        else {
          puVar7 = (undefined4 *)FUN_1003ff62(4);
          *puVar7 = pvVar4;
          puVar2[0x1a] = puVar7;
          if (puVar7 != (undefined4 *)0x0) {
            _DAT_1005215c = "WinMM";
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
            return;
          }
        }
      }
    }
  }
LAB_10021362:
  FUN_100210b0(&DAT_10051110);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

