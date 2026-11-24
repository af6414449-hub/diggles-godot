
/* Library Function - Single Match
    __read
   
   Library: Visual Studio 2019 Release */

int __cdecl __read(int _FileHandle,void *_DstBuf,uint _MaxCharCount)

{
  uint _FileHandle_00;
  ulong *puVar1;
  int *piVar2;
  int iVar3;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763668,0x10);
  _FileHandle_00 = *(uint *)(unaff_EBP + 8);
  if (_FileHandle_00 == 0xfffffffe) {
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    *piVar2 = 9;
  }
  else {
    if (((int)_FileHandle_00 < 0) || (DAT_00769f80 <= _FileHandle_00)) {
LAB_006e3ea1:
      puVar1 = ___doserrno();
      *puVar1 = 0;
      piVar2 = __errno();
      *piVar2 = 9;
    }
    else {
      iVar3 = (_FileHandle_00 & 0x3f) * 0x38;
      *(int *)(unaff_EBP + -0x20) = iVar3;
      if ((*(byte *)(iVar3 + 0x28 + (&DAT_00769d80)[(int)_FileHandle_00 >> 6]) & 1) == 0)
      goto LAB_006e3ea1;
      if (*(uint *)(unaff_EBP + 0x10) < 0x80000000) {
        ___acrt_lowio_lock_fh(_FileHandle_00);
        iVar3 = -1;
        *(undefined4 *)(unaff_EBP + -0x1c) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if ((*(byte *)(*(int *)(unaff_EBP + -0x20) + 0x28 +
                      (&DAT_00769d80)[(int)_FileHandle_00 >> 6]) & 1) == 0) {
          piVar2 = __errno();
          *piVar2 = 9;
          puVar1 = ___doserrno();
          *puVar1 = 0;
        }
        else {
          iVar3 = __read_nolock(_FileHandle_00,*(void **)(unaff_EBP + 0xc),
                                *(uint *)(unaff_EBP + 0x10));
          *(int *)(unaff_EBP + -0x1c) = iVar3;
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
        FUN_006e3e99();
        goto LAB_006e3ebc;
      }
      puVar1 = ___doserrno();
      *puVar1 = 0;
      piVar2 = __errno();
      *piVar2 = 0x16;
    }
    FUN_006e510d();
  }
  iVar3 = -1;
LAB_006e3ebc:
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar3;
}

