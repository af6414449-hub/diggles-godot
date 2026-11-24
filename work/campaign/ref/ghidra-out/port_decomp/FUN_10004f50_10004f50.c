
void FUN_10004f50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CCallbackImpl<16>::vftable;
  if ((*(byte *)(in_ECX + 1) & 1) != 0) {
    SteamAPI_UnregisterCallback();
  }
  if ((param_1 & 1) != 0) {
    FUN_100402ac();
  }
  return;
}

