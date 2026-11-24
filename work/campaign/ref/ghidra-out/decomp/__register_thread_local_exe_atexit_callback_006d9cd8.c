
/* Library Function - Single Match
    __register_thread_local_exe_atexit_callback
   
   Library: Visual Studio 2019 Release */

void __register_thread_local_exe_atexit_callback(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined *puVar3;
  
  if (DAT_00769b50 == DAT_0076700c) {
    DAT_00769b50 = __crt_fast_encode_pointer<>(param_1);
    return;
  }
  puVar3 = &DAT_007635a8;
  FUN_006cf3b0(&DAT_007635a8,8);
  iVar2 = ___acrt_getptd();
  pcVar1 = *(code **)(iVar2 + 0xc);
  if (pcVar1 != (code *)0x0) {
    guard_check_icall(puVar3,0);
    (*pcVar1)();
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}

