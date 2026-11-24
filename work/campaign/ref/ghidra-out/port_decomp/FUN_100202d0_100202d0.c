
/* WARNING: Removing unreachable block (ram,0x10020412) */
/* WARNING: Removing unreachable block (ram,0x10020476) */

void FUN_100202d0(uint param_1)

{
  code *pcVar1;
  int in_ECX;
  int iVar2;
  double dVar3;
  float fVar4;
  undefined4 in_XMM2_Da;
  float local_e4;
  double local_e0;
  CHAR local_d8 [204];
  uint local_c;
  
  local_c = DAT_1005000c ^ (uint)&local_e4;
  local_e0 = (double)CONCAT44(local_e0._4_4_,in_XMM2_Da);
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (0x3ff < param_1) {
    FUN_1001ec20(local_d8,"%s(%d): assert(%s) failed.\n",
                 "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud_core_voiceops.cpp",0x47,
                 "aVoice < VOICE_COUNT");
    OutputDebugStringA(local_d8);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (*(char *)(in_ECX + 8) != '\0') {
    iVar2 = *(int *)(in_ECX + 0x40 + param_1 * 4);
    if (iVar2 != 0) {
      *(float *)(iVar2 + 0x14) = local_e0._0_4_;
      dVar3 = (double)(local_e0._0_4_ + 1.0) * 3.14159265359 * 0.25;
      local_e0 = dVar3;
      libm_sse2_cos_precise();
      local_e4 = (float)dVar3;
      dVar3 = local_e0;
      libm_sse2_sin_precise();
      fVar4 = (float)dVar3;
      *(float *)(*(int *)(in_ECX + 0x40 + param_1 * 4) + 0x18) = local_e4;
      local_e0 = (double)CONCAT44(local_e0._4_4_,fVar4);
      *(float *)(*(int *)(in_ECX + 0x40 + param_1 * 4) + 0x1c) = fVar4;
      iVar2 = *(int *)(in_ECX + 0x40 + param_1 * 4);
      if (*(int *)(iVar2 + 0x48) == 4) {
        *(float *)(iVar2 + 0x20) = local_e4;
        *(float *)(*(int *)(in_ECX + 0x40 + param_1 * 4) + 0x24) = fVar4;
        iVar2 = *(int *)(in_ECX + 0x40 + param_1 * 4);
      }
      if (*(int *)(iVar2 + 0x48) == 6) {
        *(undefined4 *)(iVar2 + 0x20) = 0x3f3504f3;
        *(undefined4 *)(*(int *)(in_ECX + 0x40 + param_1 * 4) + 0x24) = 0x3f800000;
        *(float *)(*(int *)(in_ECX + 0x40 + param_1 * 4) + 0x28) = local_e4;
        *(float *)(*(int *)(in_ECX + 0x40 + param_1 * 4) + 0x2c) = fVar4;
        iVar2 = *(int *)(in_ECX + 0x40 + param_1 * 4);
      }
      if (*(int *)(iVar2 + 0x48) == 8) {
        *(undefined4 *)(iVar2 + 0x20) = 0x3f3504f3;
        *(undefined4 *)(*(int *)(in_ECX + 0x40 + param_1 * 4) + 0x24) = 0x3f800000;
        *(float *)(*(int *)(in_ECX + 0x40 + param_1 * 4) + 0x28) = local_e4;
        *(float *)(*(int *)(in_ECX + 0x40 + param_1 * 4) + 0x2c) = fVar4;
        *(float *)(*(int *)(in_ECX + 0x40 + param_1 * 4) + 0x30) = local_e4;
        *(float *)(*(int *)(in_ECX + 0x40 + param_1 * 4) + 0x34) = fVar4;
      }
    }
    __security_check_cookie(local_c ^ (uint)&local_e4);
    return;
  }
  FUN_1001ec20(local_d8,"%s(%d): assert(%s) failed.\n",
               "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud_core_voiceops.cpp",0x48,
               "mInsideAudioThreadMutex");
  OutputDebugStringA(local_d8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

