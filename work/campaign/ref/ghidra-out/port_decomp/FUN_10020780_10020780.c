
void FUN_10020780(uint param_1)

{
  int iVar1;
  code *pcVar2;
  int in_ECX;
  CHAR local_d8 [204];
  uint local_c;
  
  local_c = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (0x3ff < param_1) {
    FUN_1001ec20(local_d8,"%s(%d): assert(%s) failed.\n",
                 "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud_core_voiceops.cpp",0x96,
                 "aVoice < VOICE_COUNT");
    OutputDebugStringA(local_d8);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if (*(char *)(in_ECX + 8) == '\0') {
    FUN_1001ec20(local_d8,"%s(%d): assert(%s) failed.\n",
                 "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud_core_voiceops.cpp",0x97,
                 "mInsideAudioThreadMutex");
    OutputDebugStringA(local_d8);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  iVar1 = *(int *)(in_ECX + 0x40 + param_1 * 4);
  *(float *)(iVar1 + 0x3c) = *(float *)(param_1 * 0x68 + 0x1dd8 + in_ECX) * *(float *)(iVar1 + 0x38)
  ;
  iVar1 = *(int *)(in_ECX + 0x40 + param_1 * 4);
  if ((*(byte *)(iVar1 + 0x10) & 4) != 0) {
    *(float *)(iVar1 + 0x15c) = *(float *)(iVar1 + 0x3c) * *(float *)(iVar1 + 0x18);
    iVar1 = *(int *)(in_ECX + 0x40 + param_1 * 4);
    *(float *)(iVar1 + 0x160) = *(float *)(iVar1 + 0x3c) * *(float *)(iVar1 + 0x1c);
    iVar1 = *(int *)(in_ECX + 0x40 + param_1 * 4);
    *(float *)(iVar1 + 0x164) = *(float *)(iVar1 + 0x3c) * *(float *)(iVar1 + 0x20);
    iVar1 = *(int *)(in_ECX + 0x40 + param_1 * 4);
    *(float *)(iVar1 + 0x168) = *(float *)(iVar1 + 0x3c) * *(float *)(iVar1 + 0x24);
    iVar1 = *(int *)(in_ECX + 0x40 + param_1 * 4);
    *(float *)(iVar1 + 0x16c) = *(float *)(iVar1 + 0x3c) * *(float *)(iVar1 + 0x28);
    iVar1 = *(int *)(in_ECX + 0x40 + param_1 * 4);
    *(float *)(iVar1 + 0x170) = *(float *)(iVar1 + 0x3c) * *(float *)(iVar1 + 0x2c);
    iVar1 = *(int *)(in_ECX + 0x40 + param_1 * 4);
    *(float *)(iVar1 + 0x174) = *(float *)(iVar1 + 0x3c) * *(float *)(iVar1 + 0x30);
    iVar1 = *(int *)(in_ECX + 0x40 + param_1 * 4);
    *(float *)(iVar1 + 0x178) = *(float *)(iVar1 + 0x3c) * *(float *)(iVar1 + 0x34);
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

