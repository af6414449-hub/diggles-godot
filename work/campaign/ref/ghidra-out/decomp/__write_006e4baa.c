
/* Library Function - Single Match
    __write
   
   Library: Visual Studio 2019 Release */

int __cdecl __write(int _FileHandle,void *_Buf,uint _MaxCharCount)

{
  uint _FileHandle_00;
  ulong *puVar1;
  int *piVar2;
  int iVar3;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007636a8,0x10);
  _FileHandle_00 = *(uint *)(unaff_EBP + 8);
  if (_FileHandle_00 == 0xfffffffe) {
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    *piVar2 = 9;
  }
  else {
    if ((-1 < (int)_FileHandle_00) && (_FileHandle_00 < DAT_00769f80)) {
      iVar3 = (_FileHandle_00 & 0x3f) * 0x38;
      *(int *)(unaff_EBP + -0x20) = iVar3;
      if ((*(byte *)((&DAT_00769d80)[(int)_FileHandle_00 >> 6] + 0x28 + iVar3) & 1) != 0) {
        ___acrt_lowio_lock_fh(_FileHandle_00);
        iVar3 = -1;
        *(undefined4 *)(unaff_EBP + -0x1c) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if ((*(byte *)((&DAT_00769d80)[(int)_FileHandle_00 >> 6] + 0x28 +
                      *(int *)(unaff_EBP + -0x20)) & 1) == 0) {
          piVar2 = __errno();
          *piVar2 = 9;
          puVar1 = ___doserrno();
          *puVar1 = 0;
        }
        else {
          iVar3 = __write_nolock(_FileHandle_00,*(void **)(unaff_EBP + 0xc),
                                 *(uint *)(unaff_EBP + 0x10));
          *(int *)(unaff_EBP + -0x1c) = iVar3;
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
        FUN_006e4c69();
        goto LAB_006e4c8c;
      }
    }
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    *piVar2 = 9;
    FUN_006e510d();
  }
  iVar3 = -1;
LAB_006e4c8c:
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar3;
}

