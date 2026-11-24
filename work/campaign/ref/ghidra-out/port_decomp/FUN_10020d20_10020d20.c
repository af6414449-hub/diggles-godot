
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020d20(int param_1,int param_2)

{
  undefined4 *puVar1;
  longlong lVar2;
  HRESULT HVar3;
  void *_Dst;
  HANDLE pvVar4;
  DWORD DVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint local_1c;
  int local_18;
  int local_14;
  undefined2 local_10;
  undefined4 local_e;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  HVar3 = CoInitializeEx((LPVOID)0x0,0);
  if (HVar3 < 0) goto LAB_10020f73;
  _Dst = (void *)FUN_1003ff62(0x30);
  memset(_Dst,0,0x30);
  _DAT_1005111c = FUN_10020c20;
  _DAT_10051110 = _Dst;
  pvVar4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  *(HANDLE *)((int)_Dst + 0x14) = pvVar4;
  if (pvVar4 == (HANDLE)0x0) goto LAB_10020f73;
  pvVar4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  *(HANDLE *)((int)_Dst + 0x18) = pvVar4;
  if (pvVar4 == (HANDLE)0x0) goto LAB_10020f73;
  puVar1 = (undefined4 *)((int)_Dst + 8);
  local_18 = param_1;
  local_14 = param_1 << 3;
  local_e = 0x20;
  local_1c = 0x20003;
  local_10 = 8;
  if (DAT_1416eadc == (HMODULE)0x0) {
    DAT_1416eadc = LoadLibraryExW(L"xaudio2_9.dll",(HANDLE)0x0,0x800);
    if (DAT_1416eadc != (HMODULE)0x0) {
      DAT_1416ead4 = GetProcAddress(DAT_1416eadc,"XAudio2CreateWithVersionInfo");
      if (DAT_1416ead4 != (FARPROC)0x0) goto LAB_10020e49;
      DAT_1416ead8 = GetProcAddress(DAT_1416eadc,"XAudio2Create");
      if (DAT_1416ead8 != (FARPROC)0x0) goto LAB_10020e40;
    }
    DVar5 = GetLastError();
    if (0 < (int)DVar5) {
      DVar5 = DVar5 & 0xffff | 0x80070000;
    }
  }
  else {
LAB_10020e40:
    if (DAT_1416ead4 == (FARPROC)0x0) {
      DVar5 = (*DAT_1416ead8)(puVar1,0,1);
    }
    else {
LAB_10020e49:
      DVar5 = (*DAT_1416ead4)(puVar1,0,1,0xa000007);
    }
  }
  if ((-1 < (int)DVar5) &&
     (iVar6 = (**(code **)(*(int *)*puVar1 + 0x1c))
                        ((int *)*puVar1,(int)_Dst + 0xc,local_1c >> 0x10,param_1,0,0,0,6),
     -1 < iVar6)) {
    puVar7 = (undefined8 *)FUN_1003ff62(8);
    *puVar7 = 0;
    uVar8 = *(undefined4 *)((int)_Dst + 0x14);
    *(undefined4 *)puVar7 = 0;
    *(undefined ***)puVar7 = SoLoud::VoiceCallback::vftable;
    *(undefined4 *)((int)puVar7 + 4) = uVar8;
    *(undefined8 **)((int)_Dst + 0x1c) = puVar7;
    iVar6 = (**(code **)(*(int *)*puVar1 + 0x14))
                      ((int *)*puVar1,(int)_Dst + 0x10,&local_1c,6,0x40000000,puVar7,0,0);
    if (-1 < iVar6) {
      iVar6 = 0;
      *(uint *)((int)_Dst + 0x2c) = (local_1c >> 0x10) * param_2 * 4;
      do {
        lVar2 = (ulonglong)((local_1c >> 0x10) * param_2) * 4;
        uVar9 = -(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2;
        uVar10 = 0x10020f08;
        uVar8 = FUN_100402f0(uVar9);
        *(undefined4 *)((int)_Dst + iVar6 * 4) = uVar8;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 2);
      *(int *)((int)_Dst + 0x28) = param_2;
      *(undefined **)((int)_Dst + 0x24) = &DAT_10051110;
      FUN_1001b250(param_1,(local_1c >> 0x10) * param_2,uVar10,uVar9);
      iVar6 = FUN_10021420();
      *(int *)((int)_Dst + 0x20) = iVar6;
      if (iVar6 != 0) {
        (**(code **)(**(int **)((int)_Dst + 0x10) + 0x4c))(*(int **)((int)_Dst + 0x10),0,0);
        _DAT_1005215c = "XAudio2";
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
LAB_10020f73:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

