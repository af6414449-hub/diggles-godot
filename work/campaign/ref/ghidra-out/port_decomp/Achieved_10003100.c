
/* WARNING: Type propagation algorithm not settling */
/* public: void __thiscall AchievementManager::Achieved(enum Achievements::AchID) */

void __thiscall AchievementManager::Achieved(AchievementManager *this,AchID param_1)

{
  undefined4 *puVar1;
  int local_10 [3];
  
                    /* 0x3100  96  ?Achieved@AchievementManager@@QAEXW4AchID@Achievements@@@Z */
  local_10[2] = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (this[param_1 + 0x58] == (AchievementManager)0x0) {
    local_10[0] = param_1 * 4;
    FUN_100028b0(&DAT_1416eb70,0x80,"AchievementManager::Achieved %s, value : %d \n",
                 (&PTR_s_ACH_WELCOME_10043800)[param_1],*(undefined4 *)(this + local_10[0]));
    OutputDebugStringA(&DAT_1416eb70);
    if ((g_pServiceManager != (IServicesManager *)0x0) &&
       (ServiceState::g_StatsAndAchievementsRetrieved != false)) {
      if (param_1 == 1) {
        local_10[0] = 1;
        puVar1 = (undefined4 *)FUN_10003880(local_10);
        local_10[1] = 1;
        (**(code **)(*(int *)g_pServiceManager + 0x2c))(*puVar1,local_10 + 1,0xffffffff);
      }
      else {
        (**(code **)(*(int *)g_pServiceManager + 0x1c))
                  (*(undefined4 *)((int)&PTR_s_ACH_WELCOME_10043800 + local_10[0]),1,0xffffffff);
      }
      this[param_1 + 0x58] = (AchievementManager)0x1;
    }
  }
  __security_check_cookie(local_10[2] ^ (uint)&stack0xfffffffc);
  return;
}

