
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10042d10(void)

{
  _g_SteamManager = CSteamServicesManager::vftable;
  _DAT_10050d04 = CCallbackImpl<152>::vftable;
  if ((DAT_10050d08 & 1) != 0) {
    SteamAPI_UnregisterCallback(&DAT_10050d04);
  }
  _DAT_10050cf0 = CCallbackImpl<16>::vftable;
  if ((DAT_10050cf4 & 1) != 0) {
    SteamAPI_UnregisterCallback(&DAT_10050cf0);
  }
  _DAT_10050cdc = CCallbackImpl<24>::vftable;
  if ((DAT_10050ce0 & 1) != 0) {
    SteamAPI_UnregisterCallback(&DAT_10050cdc);
  }
  return;
}

