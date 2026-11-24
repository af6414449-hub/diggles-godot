
/* Library Function - Single Match
    int __cdecl dllmain_crt_process_detach(bool)
   
   Library: Visual Studio 2019 Release */

int __cdecl dllmain_crt_process_detach(bool param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int unaff_EBP;
  
  FUN_10040d70(&DAT_1004a178,0x10);
  if (DAT_100508dc < 1) {
    uVar4 = 0;
  }
  else {
    DAT_100508dc = DAT_100508dc + -1;
    *(undefined4 *)(unaff_EBP + -0x1c) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar2 = ___scrt_acquire_startup_lock();
    *(undefined1 *)(unaff_EBP + -0x20) = uVar2;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (DAT_100508b8 != 2) {
      ___scrt_fastfail(7);
      pcVar1 = (code *)swi(3);
      iVar5 = (*pcVar1)();
      return iVar5;
    }
    FUN_100400a1();
    __scrt_uninitialize_type_info();
    __RTC_Terminate();
    DAT_100508b8 = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_100406a0();
    cVar3 = ___scrt_uninitialize_crt(*(undefined4 *)(unaff_EBP + 8),0);
    uVar4 = -(uint)(cVar3 != '\0') & 1;
    *(uint *)(unaff_EBP + -0x1c) = uVar4;
    *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
    FUN_100406ad();
  }
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return uVar4;
}

