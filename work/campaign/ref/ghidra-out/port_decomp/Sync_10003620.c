
/* WARNING: Type propagation algorithm not settling */
/* public: void __thiscall AchievementManager::Sync(void) */

void __thiscall AchievementManager::Sync(AchievementManager *this)

{
  undefined4 uVar1;
  uint uVar2;
  code *pcVar3;
  char cVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  undefined4 in_EDX;
  int iVar8;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  undefined4 *local_3c;
  undefined4 local_38;
  int local_34;
  int local_30 [6];
  char local_15;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x3620  265  ?Sync@AchievementManager@@QAEXXZ */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1004174d;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  if (g_pServiceManager != (IServicesManager *)0x0) {
    iVar8 = 0;
    do {
      local_15 = '\0';
      local_30[1] = 0;
      if (iVar8 == 1) {
        local_30[5] = 1;
        FUN_10004070(&local_48,local_30 + 5);
        uVar1 = DAT_10050cc8;
        if ((*(char *)(local_40 + 0xd) != '\0') ||
           (iVar7 = local_40, local_30[5] < *(int *)(local_40 + 0x10))) {
          if (DAT_10050ccc == 0xaaaaaaa) {
            FUN_10002ad0();
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          local_3c = &DAT_10050cc8;
          local_8 = 0;
          local_38 = 0;
          puVar5 = (undefined4 *)FUN_1003ff62(0x18);
          local_8 = 0xffffffff;
          local_38 = 0;
          puVar5[4] = local_30[5];
          puVar5[5] = 0;
          *puVar5 = uVar1;
          puVar5[1] = uVar1;
          puVar5[2] = uVar1;
          *(undefined2 *)(puVar5 + 3) = 0;
          iVar7 = FUN_10003d60(local_48,local_44,puVar5);
        }
        local_30[2] = 0;
        cVar4 = (**(code **)(*(int *)g_pServiceManager + 0x3c))
                          (*(undefined4 *)(iVar7 + 0x14),local_30 + 2,0xffffffff);
        if (cVar4 != '\0') {
          *(uint *)(this + 4) = *(uint *)(this + 4) | local_30[2];
        }
      }
      else {
        (**(code **)(*(int *)g_pServiceManager + 0x50))
                  ((&PTR_s_ACH_WELCOME_10043800)[iVar8],&local_15,local_30 + 1,0xffffffff);
        if (local_15 == '\0') {
          if (iVar8 == 9) {
            local_30[5] = *(int *)(this + 0x24);
            local_30[0] = iVar8;
            puVar5 = (undefined4 *)FUN_10003880(local_30);
            uVar1 = *puVar5;
            local_30[3] = 0;
            cVar4 = (**(code **)(*(int *)g_pServiceManager + 0x3c))(uVar1,local_30 + 3,0xffffffff);
            if (cVar4 != '\0') {
              if (local_30[5] < local_30[3]) {
                *(int *)(this + 0x24) = local_30[3];
              }
              else {
                (**(code **)(*(int *)g_pServiceManager + 0x2c))(uVar1,local_30 + 5,0xffffffff);
              }
            }
          }
          else if (iVar8 == 10) {
            uVar2 = *(uint *)(this + 0x28);
            local_34 = iVar8;
            piVar6 = (int *)FUN_10003880(&local_34);
            local_30[5] = *piVar6;
            local_30[4] = 0;
            cVar4 = (**(code **)(*(int *)g_pServiceManager + 0x3c))
                              (local_30[5],local_30 + 4,0xffffffff);
            if ((cVar4 != '\0') && (local_30[4] != uVar2)) {
              *(uint *)(this + 0x28) = *(uint *)(this + 0x28) | local_30[4];
              local_30[4] = *(int *)(this + 0x28);
              (**(code **)(*(int *)g_pServiceManager + 0x2c))(local_30[5],local_30 + 4,0xffffffff);
              break;
            }
          }
        }
        else {
          *(uint *)(this + iVar8 * 4) =
               *(uint *)(this + iVar8 * 4) | *(uint *)(this + iVar8 * 4 + 0x2c);
          this[iVar8 + 0x58] = (AchievementManager)((byte)this[iVar8 + 0x58] | 1);
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < 0xb);
    SendAllReached(this);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

