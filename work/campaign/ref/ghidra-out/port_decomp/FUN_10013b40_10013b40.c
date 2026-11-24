
void FUN_10013b40(void)

{
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (*(HMODULE *)(in_ECX + 4) != (HMODULE)0x0) {
    FreeLibrary(*(HMODULE *)(in_ECX + 4));
  }
  return;
}

