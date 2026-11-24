
LPCRITICAL_SECTION FUN_100213c0(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  lpCriticalSection = (LPCRITICAL_SECTION)FUN_1003ff62(0x18);
  InitializeCriticalSectionAndSpinCount(lpCriticalSection,100);
  return lpCriticalSection;
}

