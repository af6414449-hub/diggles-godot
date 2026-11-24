
/* Library Function - Single Match
    __int64 __cdecl common_lseek<__int64>(int,__int64,int)
   
   Library: Visual Studio 2019 Release */

__int64 __cdecl common_lseek<__int64>(int param_1,__int64 param_2,int param_3)

{
  uint uVar1;
  ulong *puVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  __int64 _Var5;
  undefined *puVar6;
  
  puVar6 = &DAT_00763500;
  FUN_006cf3b0(&DAT_00763500,0x18);
  uVar1 = *(uint *)(unaff_EBP + 8);
  if (uVar1 == 0xfffffffe) {
    puVar2 = ___doserrno();
    *puVar2 = 0;
    piVar3 = __errno();
    *piVar3 = 9;
  }
  else {
    if ((-1 < (int)uVar1) && (uVar1 < DAT_00769f80)) {
      *(int *)(unaff_EBP + -0x1c) = (int)uVar1 >> 6;
      iVar4 = (uVar1 & 0x3f) * 0x38;
      *(int *)(unaff_EBP + -0x20) = iVar4;
      if ((*(byte *)((&DAT_00769d80)[(int)uVar1 >> 6] + 0x28 + iVar4) & 1) != 0) {
        ___acrt_lowio_lock_fh(uVar1);
        *(undefined4 *)(unaff_EBP + -0x28) = 0xffffffff;
        _Var5 = -1;
        *(undefined4 *)(unaff_EBP + -0x24) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if ((*(byte *)((&DAT_00769d80)[*(int *)(unaff_EBP + -0x1c)] + 0x28 +
                      *(int *)(unaff_EBP + -0x20)) & 1) == 0) {
          piVar3 = __errno();
          *piVar3 = 9;
          puVar2 = ___doserrno();
          *puVar2 = 0;
        }
        else {
          _Var5 = common_lseek_nolock<__int64>(uVar1,*(__int64 *)(unaff_EBP + 0x10),(int)puVar6);
          *(__int64 *)(unaff_EBP + -0x28) = _Var5;
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
        FUN_006df9be();
        goto LAB_006df9e3;
      }
    }
    puVar2 = ___doserrno();
    *puVar2 = 0;
    piVar3 = __errno();
    *piVar3 = 9;
    FUN_006e510d();
  }
  _Var5 = -1;
LAB_006df9e3:
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return _Var5;
}

