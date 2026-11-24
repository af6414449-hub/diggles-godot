
/* Library Function - Single Match
    int __cdecl dllmain_dispatch(struct HINSTANCE__ * const,unsigned long,void * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl dllmain_dispatch(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  ulong uVar1;
  int iVar2;
  void *pvVar3;
  int unaff_EBP;
  
  FUN_10040d70(&DAT_1004a1a0,0xc);
  uVar1 = *(ulong *)(unaff_EBP + 0xc);
  if ((uVar1 == 0) && (DAT_100508dc < 1)) {
    iVar2 = 0;
    goto LAB_100407b6;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((uVar1 == 1) || (uVar1 == 2)) {
    pvVar3 = *(void **)(unaff_EBP + 0x10);
    iVar2 = dllmain_raw(*(HINSTANCE__ **)(unaff_EBP + 8),uVar1,pvVar3);
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    if (iVar2 != 0) {
      iVar2 = dllmain_crt_dispatch(*(HINSTANCE__ **)(unaff_EBP + 8),uVar1,pvVar3);
      *(int *)(unaff_EBP + -0x1c) = iVar2;
      if (iVar2 != 0) goto LAB_10040721;
    }
  }
  else {
    pvVar3 = *(void **)(unaff_EBP + 0x10);
LAB_10040721:
    iVar2 = _DllMain_12(*(undefined4 *)(unaff_EBP + 8),uVar1,pvVar3);
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    if ((uVar1 == 1) && (iVar2 == 0)) {
      _DllMain_12(*(undefined4 *)(unaff_EBP + 8),0,pvVar3);
      dllmain_crt_process_detach(pvVar3 != (void *)0x0);
      dllmain_raw(*(HINSTANCE__ **)(unaff_EBP + 8),0,pvVar3);
    }
    if ((uVar1 == 0) || (uVar1 == 3)) {
      iVar2 = dllmain_crt_dispatch(*(HINSTANCE__ **)(unaff_EBP + 8),uVar1,pvVar3);
      *(int *)(unaff_EBP + -0x1c) = iVar2;
      if (iVar2 != 0) {
        iVar2 = dllmain_raw(*(HINSTANCE__ **)(unaff_EBP + 8),uVar1,pvVar3);
        *(int *)(unaff_EBP + -0x1c) = iVar2;
      }
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
LAB_100407b6:
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar2;
}

