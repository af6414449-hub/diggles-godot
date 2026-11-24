
void FUN_1003fc20(void)

{
  undefined4 *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *in_ECX = SoLoud::DiskFile::vftable;
  if ((FILE *)in_ECX[1] != (FILE *)0x0) {
    fclose((FILE *)in_ECX[1]);
  }
  *in_ECX = SoLoud::File::vftable;
  return;
}

