
void FUN_10004660(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  AchievementManager *this;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  puVar1 = (undefined4 *)SteamInternal_ContextInit(&PTR_FUN_10050030);
  iVar2 = (**(code **)(*(int *)*puVar1 + 0x24))();
  if ((iVar2 == *param_1) && (param_1[1] == 0)) {
    ServiceState::g_StatsAndAchievementsRetrieved = true;
    OutputDebugStringA("Steam: OnUserStatsReceived CALLBACK \n");
    if (param_1[2] == 1) {
      OutputDebugStringA("Steam: Stats and achievements were received\n");
      if (AchievementManager::s_instance == (AchievementManager *)0x0) {
        this = (AchievementManager *)FUN_1003ff62(100);
        AchievementManager::s_instance =
             (AchievementManager *)AchievementManager::AchievementManager(this);
      }
      AchievementManager::Sync(AchievementManager::s_instance);
    }
  }
  return;
}

