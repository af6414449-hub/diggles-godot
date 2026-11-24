
/* bool __cdecl PStdUtils::AddPtrToWatcher(void *) */

bool __cdecl PStdUtils::AddPtrToWatcher(void *param_1)

{
  undefined1 extraout_AL;
  undefined1 extraout_AL_00;
  undefined1 local_24 [8];
  int local_1c;
  void *local_18;
  void *local_14 [2];
  uint local_c;
  
                    /* 0xc960  97  ?AddPtrToWatcher@PStdUtils@@YA_NPAX@Z */
  local_c = DAT_1005000c ^ (uint)local_24;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  local_18 = param_1;
  local_14[0] = param_1;
  FUN_1000ccf0(local_24,local_14);
  if (((*(char *)(local_1c + 0xd) == '\0') && (*(void **)(local_1c + 0x10) <= param_1)) &&
     (local_1c != DAT_10051090)) {
    __security_check_cookie(local_c ^ (uint)local_24);
    return (bool)extraout_AL;
  }
  FUN_1000cb00(local_14,&local_18);
  __security_check_cookie(local_c ^ (uint)local_24);
  return (bool)extraout_AL_00;
}

