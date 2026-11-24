
/* Library Function - Single Match
    int __cdecl __scrt_common_main_seh(void)
   
   Library: Visual Studio 2019 Release */

int __cdecl __scrt_common_main_seh(void)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  int unaff_EBP;
  int unaff_ESI;
  
  FUN_006cf3b0(&DAT_007630e8,0x14);
  cVar3 = ___scrt_initialize_crt(1);
  if (cVar3 != '\0') {
    bVar2 = false;
    *(undefined1 *)(unaff_EBP + -0x19) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar4 = ___scrt_acquire_startup_lock();
    *(undefined1 *)(unaff_EBP + -0x24) = uVar4;
    if (DAT_00769738 != 1) {
      if (DAT_00769738 == 0) {
        DAT_00769738 = 1;
        iVar6 = __initterm_e(&DAT_00715658,&DAT_00715678);
        if (iVar6 != 0) {
          *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
          unaff_ESI = 0xff;
          goto LAB_006cf375;
        }
        __initterm(&DAT_007155cc,&DAT_00715654);
        DAT_00769738 = 2;
      }
      else {
        bVar2 = true;
        *(undefined1 *)(unaff_EBP + -0x19) = 1;
      }
      ___scrt_release_startup_lock(*(undefined4 *)(unaff_EBP + -0x24));
      piVar7 = (int *)FUN_006cf8d9();
      if (*piVar7 != 0) {
        cVar3 = ___scrt_is_nonwritable_in_current_image(piVar7);
        if (cVar3 != '\0') {
          pcVar1 = (code *)*piVar7;
          guard_check_icall(0,2,0);
          (*pcVar1)();
        }
      }
      piVar7 = (int *)FUN_006cf8df();
      if (*piVar7 != 0) {
        cVar3 = ___scrt_is_nonwritable_in_current_image(piVar7);
        if (cVar3 != '\0') {
          __register_thread_local_exe_atexit_callback(*piVar7);
        }
      }
      uVar5 = ___scrt_get_show_window_mode();
      uVar8 = __get_narrow_winmain_command_line();
      unaff_ESI = FUN_006b7a50(0x400000,0,uVar8,uVar5);
      cVar3 = ___scrt_is_managed_app();
      if (cVar3 != '\0') {
        if (!bVar2) {
          __cexit();
        }
        ___scrt_uninitialize_crt(1,0);
        *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
LAB_006cf375:
        ExceptionList = *(void **)(unaff_EBP + -0x10);
        return unaff_ESI;
      }
      goto LAB_006cf38c;
    }
  }
  ___scrt_fastfail(7);
LAB_006cf38c:
                    /* WARNING: Subroutine does not return */
  _exit(unaff_ESI);
}

