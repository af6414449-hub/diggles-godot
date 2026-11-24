
void FUN_1001fa20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = SoLoud::WavStream::vftable;
  FUN_10020020();
  free((void *)in_ECX[0x1b]);
  if ((undefined4 *)in_ECX[0x1c] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x1c])(1);
  }
  *in_ECX = SoLoud::AudioSource::vftable;
  FUN_10020020();
  if ((param_1 & 1) != 0) {
    FUN_100402ac();
  }
  return;
}

