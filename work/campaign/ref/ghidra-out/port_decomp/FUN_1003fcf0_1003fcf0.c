
void FUN_1003fcf0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = SoLoud::MemoryFile::vftable;
  if (*(char *)(in_ECX + 4) != '\0') {
    free((void *)in_ECX[1]);
  }
  *in_ECX = SoLoud::File::vftable;
  if ((param_1 & 1) != 0) {
    FUN_100402ac();
  }
  return;
}

