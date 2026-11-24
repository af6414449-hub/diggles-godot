
void FUN_1001eba0(void)

{
  code *pcVar1;
  int in_ECX;
  CHAR local_d0 [200];
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (*(char *)(in_ECX + 8) == '\0') {
    FUN_1001ec20(local_d0,"%s(%d): assert(%s) failed.\n",
                 "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud.cpp",0x894,
                 "mInsideAudioThreadMutex");
    OutputDebugStringA(local_d0);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  *(undefined1 *)(in_ECX + 8) = 0;
  if (*(LPCRITICAL_SECTION *)(in_ECX + 4) != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(*(LPCRITICAL_SECTION *)(in_ECX + 4));
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

