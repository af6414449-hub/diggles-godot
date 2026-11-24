
/* WARNING: Removing unreachable block (ram,0x10004866) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100047c0(void)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  char cVar4;
  undefined4 *puVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  int iVar11;
  undefined1 auStack_88 [4];
  uint uStack_84;
  undefined4 uStack_80;
  char *pcStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  uint uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_48;
  undefined4 uStack_40;
  undefined1 auStack_34 [29];
  char acStack_17 [3];
  uint local_14;
  
  local_14 = DAT_1005000c ^ (uint)auStack_88;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if ((*(int *)(*(int *)((int)ThreadLocalStoragePointer + _tls_index * 4) + 4) < DAT_1416ebf8) &&
     (FUN_1003fe8c(&DAT_1416ebf8), DAT_1416ebf8 == -1)) {
    _atexit(FUN_10042cb0);
    FUN_1003fe42(&DAT_1416ebf8);
  }
  if (DAT_10050120 == 0) {
    cVar4 = SteamAPI_Init();
    if (cVar4 == '\0') {
      GaLogger::WriteLogLineToFileA("SteamAPI_Init() failed\n");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    puVar5 = (undefined4 *)SteamInternal_ContextInit(&PTR_FUN_10050048);
    puVar6 = (uint *)(**(code **)(*(int *)*puVar5 + 8))(auStack_34);
    lVar1 = CONCAT44(uStack_40,uStack_74);
    pcVar10 = acStack_17;
    uStack_84 = *puVar6;
    uVar7 = puVar6[1];
    pcStack_7c = pcVar10;
    if (uVar7 != 0) {
      do {
        uStack_78 = (undefined4)((ulonglong)uStack_84 * 0x12e0be82 >> 0x20);
        lVar1 = (ulonglong)uVar7 * 0x12e0be82;
        uVar3 = (ulonglong)uVar7 * 0x6d694b2f + ((ulonglong)uStack_84 * 0x6d694b2f >> 0x20);
        uVar9 = (uint)(uVar3 >> 0x20);
        lVar2 = (ulonglong)uStack_84 * 0x12e0be82 + (uVar3 & 0xffffffff);
        uStack_48 = (undefined4)lVar2;
        uVar8 = (uint)((ulonglong)lVar2 >> 0x20);
        iVar11 = 9;
        lVar2 = lVar1 + (ulonglong)CONCAT14(CARRY4(uVar9,uVar8),uVar9 + uVar8);
        uVar7 = (uVar7 - (int)((ulonglong)lVar2 >> 0x20)) - (uint)(uStack_84 < (uint)lVar2);
        lVar2 = lVar2 + CONCAT44(uVar7 >> 1,uStack_84 - (uint)lVar2 >> 1 | uVar7 * -0x80000000);
        uVar7 = (uint)((ulonglong)lVar2 >> 0x20);
        uVar9 = (uint)lVar2 >> 0x1d | uVar7 * 8;
        uVar7 = uVar7 >> 0x1d;
        uVar8 = uStack_84 + uVar9 * -1000000000;
        do {
          pcStack_7c = pcStack_7c + -1;
          *pcStack_7c = (char)uVar8 + (char)(uVar8 / 10) * -10 + '0';
          iVar11 = iVar11 + -1;
          uVar8 = uVar8 / 10;
        } while (iVar11 != 0);
        uStack_84 = uVar9;
      } while (uVar7 != 0);
      uStack_80 = 0;
      pcVar10 = pcStack_7c;
    }
    do {
      uStack_40 = (undefined4)((ulonglong)lVar1 >> 0x20);
      uStack_74 = (undefined4)lVar1;
      pcVar10 = pcVar10 + -1;
      uStack_60 = uStack_84 / 10;
      *pcVar10 = (char)uStack_84 + (char)uStack_60 * -10 + '0';
      uStack_84 = uStack_60;
    } while (uStack_60 != 0);
    uStack_5c = 0xf;
    uStack_70 = CONCAT31(uStack_70._1_3_,(char)uStack_60);
    if (pcVar10 != acStack_17) {
      FUN_10003a00(pcVar10,(int)acStack_17 - (int)pcVar10);
      lVar1 = CONCAT44(uStack_40,uStack_74);
    }
    uStack_40 = (undefined4)((ulonglong)lVar1 >> 0x20);
    uStack_74 = (undefined4)lVar1;
    if (0xf < DAT_10050124) {
      uVar8 = DAT_10050124 + 1;
      uVar7 = DAT_10050110;
      if (0xfff < uVar8) {
        uVar7 = *(uint *)(DAT_10050110 - 4);
        uVar8 = DAT_10050124 + 0x24;
        if (0x1f < (DAT_10050110 - uVar7) - 4) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
      }
      FUN_100402ac(uVar7,uVar8);
      lVar1 = CONCAT44(uStack_40,uStack_74);
    }
    DAT_10050110 = uStack_70;
    uStack_40 = (undefined4)((ulonglong)lVar1 >> 0x20);
    uStack_74 = (undefined4)lVar1;
    uStack_70 = uStack_70 & 0xffffff00;
    uRam10050114 = uStack_6c;
    uRam10050118 = uStack_68;
    uRam1005011c = uStack_64;
    _DAT_10050120 = CONCAT44(uStack_5c,uStack_60);
    uStack_60 = 0;
    uStack_5c = 0xf;
    FUN_100039a0();
  }
  __security_check_cookie(local_14 ^ (uint)auStack_88);
  return;
}

