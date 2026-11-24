
void FUN_100206a0(uint param_1)

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
                 "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud_core_voiceops.cpp",0x8e,
                 "aVoice < VOICE_COUNT");
    OutputDebugStringA(local_d8);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if (*(char *)(in_ECX + 8) == '\0') {
    FUN_1001ec20(local_d8,"%s(%d): assert(%s) failed.\n",
                 "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud_core_voiceops.cpp",0x8f,
                 "mInsideAudioThreadMutex");
    OutputDebugStringA(local_d8);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  iVar1 = *(int *)(in_ECX + 0x40 + param_1 * 4);
  *(float *)(iVar1 + 0x50) = *(float *)(param_1 * 0x68 + 0x1dd4 + in_ECX) * *(float *)(iVar1 + 0x4c)
  ;
  iVar1 = *(int *)(in_ECX + 0x40 + param_1 * 4);
  *(float *)(iVar1 + 0x44) = *(float *)(iVar1 + 0x50) * *(float *)(iVar1 + 0x40);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

