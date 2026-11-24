
/* Library Function - Single Match
    int __cdecl dllmain_crt_process_attach(struct HINSTANCE__ * const,void * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl dllmain_crt_process_attach(HINSTANCE__ *param_1,void *param_2)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  int *piVar6;
  int unaff_EBP;
  
  FUN_10040d70(&DAT_1004a158,0x10);
  cVar3 = ___scrt_initialize_crt(0);
  if (cVar3 != '\0') {
    uVar4 = ___scrt_acquire_startup_lock();
    *(undefined1 *)(unaff_EBP + -0x1d) = uVar4;
    bVar2 = true;
    *(undefined1 *)(unaff_EBP + -0x19) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (DAT_100508b8 != 0) {
      ___scrt_fastfail(7);
      pcVar1 = (code *)swi(3);
      iVar5 = (*pcVar1)();
      return iVar5;
    }
    DAT_100508b8 = 1;
    cVar3 = ___scrt_dllmain_before_initialize_c();
    if (cVar3 != '\0') {
      __RTC_Initialize();
      FUN_10040e87();
      ___scrt_initialize_default_local_stdio_options();
      iVar5 = initterm_e(&DAT_100432f8,&DAT_10043300);
      if (iVar5 == 0) {
        cVar3 = ___scrt_dllmain_after_initialize_c();
        if (cVar3 != '\0') {
          initterm(&DAT_10043298,&DAT_100432f4);
          DAT_100508b8 = 2;
          bVar2 = false;
          *(undefined1 *)(unaff_EBP + -0x19) = 0;
        }
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
    FUN_100405e7();
    if (!bVar2) {
      piVar6 = (int *)FUN_10040ec2();
      if (*piVar6 != 0) {
        cVar3 = ___scrt_is_nonwritable_in_current_image(piVar6);
        if (cVar3 != '\0') {
          pcVar1 = (code *)*piVar6;
          guard_check_icall(*(undefined4 *)(unaff_EBP + 8),2,*(undefined4 *)(unaff_EBP + 0xc));
          (*pcVar1)();
        }
      }
      DAT_100508dc = DAT_100508dc + 1;
      iVar5 = 1;
      goto LAB_100405f3;
    }
  }
  iVar5 = 0;
LAB_100405f3:
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar5;
}

