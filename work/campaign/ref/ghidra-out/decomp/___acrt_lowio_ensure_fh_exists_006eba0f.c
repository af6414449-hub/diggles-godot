
/* Library Function - Single Match
    ___acrt_lowio_ensure_fh_exists
   
   Library: Visual Studio 2019 Release */

undefined4 ___acrt_lowio_ensure_fh_exists(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  undefined4 uVar3;
  int iVar4;
  
  FUN_006cf3b0(&DAT_00763888,0x10);
  if (*(uint *)(unaff_EBP + 8) < 0x2000) {
    uVar3 = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    ___acrt_lock(7);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar4 = 0;
    iVar2 = DAT_00769f80;
    while (*(int *)(unaff_EBP + -0x20) = iVar4, iVar2 <= *(int *)(unaff_EBP + 8)) {
      if ((&DAT_00769d80)[iVar4] == 0) {
        iVar2 = ___acrt_lowio_create_handle_array();
        (&DAT_00769d80)[iVar4] = iVar2;
        if (iVar2 == 0) {
          uVar3 = 0xc;
          *(undefined4 *)(unaff_EBP + -0x1c) = 0xc;
          break;
        }
        iVar2 = DAT_00769f80 + 0x40;
        DAT_00769f80 = iVar2;
      }
      iVar4 = iVar4 + 1;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
    FUN_006ebaa4();
  }
  else {
    piVar1 = __errno();
    uVar3 = 9;
    *piVar1 = 9;
    FUN_006e510d();
  }
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return uVar3;
}

