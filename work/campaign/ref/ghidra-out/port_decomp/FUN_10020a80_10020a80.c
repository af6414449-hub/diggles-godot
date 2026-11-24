
void FUN_10020a80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = SoLoud::VoiceCallback::vftable;
  if ((param_1 & 1) != 0) {
    FUN_100402ac();
  }
  return;
}

