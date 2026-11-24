
void FUN_10005070(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CCallbackImpl<152>::vftable;
  if ((*(byte *)(in_ECX + 1) & 1) != 0) {
    SteamAPI_UnregisterCallback();
  }
  if ((param_1 & 1) != 0) {
    FUN_100402ac();
  }
  return;
}

