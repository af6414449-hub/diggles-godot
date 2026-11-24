
void FUN_10020200(uint param_1)

{
  uint *puVar1;
  int iVar2;
  code *pcVar3;
  int in_ECX;
  CHAR local_d4 [204];
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (0x3ff < param_1) {
    FUN_1001ec20(local_d4,"%s(%d): assert(%s) failed.\n",
                 "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud_core_voiceops.cpp",0x33,
                 "aVoice < VOICE_COUNT");
    OutputDebugStringA(local_d4);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  if (*(char *)(in_ECX + 8) == '\0') {
    FUN_1001ec20(local_d4,"%s(%d): assert(%s) failed.\n",
                 "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud_core_voiceops.cpp",0x34,
                 "mInsideAudioThreadMutex");
    OutputDebugStringA(local_d4);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  *(undefined1 *)(in_ECX + 0x1cda8) = 1;
  iVar2 = *(int *)(in_ECX + 0x40 + param_1 * 4);
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x124) = 0;
    puVar1 = (uint *)(*(int *)(in_ECX + 0x40 + param_1 * 4) + 0x10);
    *puVar1 = *puVar1 | 4;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

