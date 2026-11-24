
void FUN_1003fb00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = SoLoud::DiskFile::vftable;
  if ((FILE *)in_ECX[1] != (FILE *)0x0) {
    fclose((FILE *)in_ECX[1]);
  }
  *in_ECX = SoLoud::File::vftable;
  if ((param_1 & 1) != 0) {
    FUN_100402ac();
  }
  return;
}

