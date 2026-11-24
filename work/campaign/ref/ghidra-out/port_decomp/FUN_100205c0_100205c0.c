
void FUN_100205c0(uint param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  int in_ECX;
  uint uVar3;
  CHAR local_d8 [204];
  uint local_c;
  
  local_c = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (0x3ff < param_1) {
    FUN_1001ec20(local_d8,"%s(%d): assert(%s) failed.\n",
                 "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud_core_voiceops.cpp",0x76,
                 "aVoice < VOICE_COUNT");
    OutputDebugStringA(local_d8);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if (*(char *)(in_ECX + 8) == '\0') {
    FUN_1001ec20(local_d8,"%s(%d): assert(%s) failed.\n",
                 "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud_core_voiceops.cpp",0x77,
                 "mInsideAudioThreadMutex");
    OutputDebugStringA(local_d8);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  *(undefined1 *)(in_ECX + 0x1cda8) = 1;
  puVar1 = *(undefined4 **)(in_ECX + 0x40 + param_1 * 4);
  if (puVar1 != (undefined4 *)0x0) {
    uVar3 = 0;
    *(undefined4 *)(in_ECX + 0x40 + param_1 * 4) = 0;
    if (*(int *)(in_ECX + 0x10) != 0) {
      do {
        if (*(undefined4 **)(*(int *)(in_ECX + 0x3c) + uVar3 * 4) == puVar1) {
          *(undefined4 *)(*(int *)(in_ECX + 0x3c) + uVar3 * 4) = 0;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(in_ECX + 0x10));
    }
    (**(code **)*puVar1)(1);
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

