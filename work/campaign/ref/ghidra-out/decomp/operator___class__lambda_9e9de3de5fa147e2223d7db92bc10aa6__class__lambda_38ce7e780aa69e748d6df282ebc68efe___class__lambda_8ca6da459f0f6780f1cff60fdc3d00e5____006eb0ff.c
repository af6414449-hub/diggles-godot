
/* Library Function - Single Match
    public: int __thiscall __crt_seh_guarded_call<int>::operator()<class
   <lambda_9e9de3de5fa147e2223d7db92bc10aa6>,class <lambda_38ce7e780aa69e748d6df282ebc68efe> &,class
   <lambda_8ca6da459f0f6780f1cff60fdc3d00e5> >(class <lambda_9e9de3de5fa147e2223d7db92bc10aa6>
   &&,class <lambda_38ce7e780aa69e748d6df282ebc68efe> &,class
   <lambda_8ca6da459f0f6780f1cff60fdc3d00e5> &&)
   
   Library: Visual Studio 2019 Release */

int __thiscall
__crt_seh_guarded_call<int>::
operator()<class_<lambda_9e9de3de5fa147e2223d7db92bc10aa6>,class_<lambda_38ce7e780aa69e748d6df282ebc68efe>&,class_<lambda_8ca6da459f0f6780f1cff60fdc3d00e5>_>
          (__crt_seh_guarded_call<int> *this,<lambda_9e9de3de5fa147e2223d7db92bc10aa6> *param_1,
          <lambda_38ce7e780aa69e748d6df282ebc68efe> *param_2,
          <lambda_8ca6da459f0f6780f1cff60fdc3d00e5> *param_3)

{
  uint _FileHandle;
  HANDLE hFile;
  BOOL BVar1;
  ulong *puVar2;
  DWORD DVar3;
  int *piVar4;
  int unaff_EBP;
  int iVar5;
  
  FUN_006cf3b0(&DAT_00763848,0xc);
  iVar5 = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  ___acrt_lowio_lock_fh(**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  _FileHandle = *(uint *)**(undefined4 **)(unaff_EBP + 0xc);
  if ((*(byte *)((&DAT_00769d80)[(int)_FileHandle >> 6] + 0x28 + (_FileHandle & 0x3f) * 0x38) & 1)
      != 0) {
    hFile = (HANDLE)__get_osfhandle(_FileHandle);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 != 0) goto LAB_006eb16f;
    puVar2 = ___doserrno();
    DVar3 = GetLastError();
    *puVar2 = DVar3;
  }
  piVar4 = __errno();
  *piVar4 = 9;
  iVar5 = -1;
LAB_006eb16f:
  *(int *)(unaff_EBP + -0x1c) = iVar5;
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006eb195();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar5;
}

