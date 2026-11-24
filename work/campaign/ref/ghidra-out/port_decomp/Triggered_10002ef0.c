
/* public: void __thiscall AchievementManager::Triggered(enum Achievements::AchID) */

void __thiscall AchievementManager::Triggered(AchievementManager *this,AchID param_1)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined1 auStack_1c [4];
  AchID AStack_18;
  uint uStack_14;
  AchID AStack_10;
  uint local_c;
  
                    /* 0x2ef0  267  ?Triggered@AchievementManager@@QAEXW4AchID@Achievements@@@Z */
  local_c = DAT_1005000c ^ (uint)auStack_1c;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  FUN_100028b0(&DAT_1416eae8,0x80,"AchievementManager::Triggered %s, value : %d \n",
               (&PTR_s_ACH_WELCOME_10043800)[param_1],*(undefined4 *)(this + param_1 * 4));
  OutputDebugStringA(&DAT_1416eae8);
  if ((g_pServiceManager != (IServicesManager *)0x0) &&
     (ServiceState::g_StatsAndAchievementsRetrieved != false)) {
    if (param_1 == 10) {
      uStack_14 = 0;
      AStack_18 = param_1;
      puVar3 = (undefined4 *)FUN_10003880(&AStack_18);
      uVar1 = *puVar3;
      cVar2 = (**(code **)(*(int *)g_pServiceManager + 0x3c))(uVar1,&uStack_14,0xffffffff);
      if (cVar2 != '\0') {
        *(uint *)(this + 0x28) = *(uint *)(this + 0x28) | uStack_14;
        AStack_10 = *(AchID *)(this + 0x28);
        (**(code **)(*(int *)g_pServiceManager + 0x2c))(uVar1,&AStack_10,0xffffffff);
        __security_check_cookie(AStack_18 ^ (uint)&stack0xffffffd8);
        return;
      }
    }
    else if (param_1 == 9) {
      uStack_14 = 0;
      AStack_10 = param_1;
      puVar3 = (undefined4 *)FUN_10003880(&AStack_10);
      uVar1 = *puVar3;
      cVar2 = (**(code **)(*(int *)g_pServiceManager + 0x3c))(uVar1,&uStack_14,0xffffffff);
      if (cVar2 != '\0') {
        if ((int)uStack_14 < (int)*(uint *)(this + 0x24)) {
          uStack_14 = *(uint *)(this + 0x24);
          (**(code **)(*(int *)g_pServiceManager + 0x2c))(uVar1,&uStack_14,0xffffffff);
        }
        else {
          *(uint *)(this + 0x24) = uStack_14;
        }
      }
      FUN_100028b0(&DAT_1416eae8,0x80,"Gog: Time played - %d hours, %d minutes, %d seconds \n",
                   (int)uStack_14 / 0xe10,((int)uStack_14 % 0xe10) / 0x3c,(int)uStack_14 % 0x3c);
      OutputDebugStringA(&DAT_1416eae8);
    }
  }
  __security_check_cookie(local_c ^ (uint)auStack_1c);
  return;
}

