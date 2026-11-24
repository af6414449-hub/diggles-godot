
/* public: bool __thiscall SoloudAudioPlayer::Run(void) */

bool __thiscall SoloudAudioPlayer::Run(SoloudAudioPlayer *this)

{
  undefined1 extraout_AL;
  undefined1 extraout_AL_00;
  undefined1 extraout_AL_01;
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 in_stack_ffffffc8;
  int iVar5;
  int iVar6;
  undefined1 auStack_24 [4];
  double local_20;
  uint local_14 [4];
  
                    /* 0x14990  235  ?Run@SoloudAudioPlayer@@QAE_NXZ */
  local_14[2] = DAT_1005000c ^ (uint)auStack_24;
  iVar5 = 0x100149b3;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = *(int *)(this + 4);
  if (iVar1 != 0) {
    iVar6 = *(int *)(this + 8);
    if (iVar6 != -1) {
      in_stack_ffffffc8 = 0x100149d0;
      FUN_1001a9c0(iVar6);
      iVar1 = *(int *)(this + 4);
      iVar5 = iVar6;
    }
    iVar1 = FUN_1001a3d0(iVar1,in_stack_ffffffc8,iVar5);
    *(int *)(this + 8) = iVar1;
    if (iVar1 != -1) {
      if (0.0 < *(double *)(this + 0x10)) {
        FUN_1001a7f0(iVar1);
      }
      if (0.0 < *(double *)(this + 0x18)) {
        local_20 = *(double *)(this + 0x18) - *(double *)(this + 0x10);
        uVar3 = *(uint *)(this + 8);
        iVar1 = *(int *)this;
        if (local_20 <= 0.0) {
          FUN_1001a9c0(uVar3);
          __security_check_cookie(local_14[2] ^ (uint)auStack_24);
          return (bool)extraout_AL;
        }
        local_14[1] = 0;
        local_14[0] = uVar3;
        FUN_1001eb20();
        if (((((uVar3 & 0xfffff000) != 0xfffff000) ||
             (*(uint *)(iVar1 + 0x1bda0) <= (uVar3 & 0xfff))) ||
            (iVar5 = *(int *)(*(int *)(iVar1 + 0x1bd9c) + (uVar3 & 0xfff) * 4), iVar5 == 0)) ||
           (puVar4 = (uint *)(iVar5 + 4), puVar4 == (uint *)0x0)) {
          puVar4 = local_14;
        }
        uVar3 = *puVar4;
        while (uVar3 != 0) {
          if ((((uVar3 & 0xfffff000) == 0xfffff000) &&
              ((uVar3 & 0xfff) < *(uint *)(iVar1 + 0x1bda0))) &&
             ((iVar5 = *(int *)(*(int *)(iVar1 + 0x1bd9c) + (uVar3 & 0xfff) * 4), iVar5 != 0 &&
              (puVar2 = (uint *)(iVar5 + 4), puVar2 != (uint *)0x0)))) {
            uVar3 = *puVar2;
          }
          if (uVar3 != 0) {
            iVar5 = *(int *)(iVar1 + 0x3c + (uVar3 & 0xfff) * 4);
            if (((iVar5 != 0) && ((*(uint *)(iVar5 + 8) & 0xfffff) == uVar3 >> 0xc)) &&
               ((uVar3 & 0xfff) != 0)) {
              *(double *)(iVar5 + 0x140) = *(double *)(iVar5 + 0x58);
              *(undefined4 *)(iVar5 + 0x150) = *(undefined4 *)(iVar5 + 0x128);
              *(undefined4 *)(iVar5 + 0x128) = 0x3f800000;
              *(undefined4 *)(iVar5 + 300) = 0;
              *(double *)(iVar5 + 0x138) = local_20;
              *(undefined4 *)(iVar5 + 0x130) = 0xbf800000;
              *(double *)(iVar5 + 0x148) = *(double *)(iVar5 + 0x58) + local_20;
              *(undefined4 *)(iVar5 + 0x154) = 1;
            }
          }
          puVar2 = puVar4 + 1;
          puVar4 = puVar4 + 1;
          uVar3 = *puVar2;
        }
        FUN_1001eba0();
      }
      __security_check_cookie(local_14[2] ^ (uint)auStack_24);
      return (bool)extraout_AL_00;
    }
  }
  __security_check_cookie(local_14[2] ^ (uint)auStack_24);
  return (bool)extraout_AL_01;
}

