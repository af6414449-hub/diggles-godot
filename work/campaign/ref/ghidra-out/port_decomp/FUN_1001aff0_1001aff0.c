
void FUN_1001aff0(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  code *pcVar1;
  int in_ECX;
  CHAR local_d0 [200];
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (*(char *)(in_ECX + 8) != '\0') {
    FUN_1001ec20(local_d0,"%s(%d): assert(%s) failed.\n",
                 "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud.cpp",0xc0,
                 "!mInsideAudioThreadMutex");
    OutputDebugStringA(local_d0);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  FUN_1001ab50();
  if (*(code **)(in_ECX + 0xc) != (code *)0x0) {
    (**(code **)(in_ECX + 0xc))();
  }
  lpCriticalSection = *(LPCRITICAL_SECTION *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    DeleteCriticalSection(lpCriticalSection);
    FUN_100402ac(lpCriticalSection,0x18);
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

