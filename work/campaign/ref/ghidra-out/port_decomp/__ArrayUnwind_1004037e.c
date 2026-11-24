
/* Library Function - Single Match
    void __stdcall __ArrayUnwind(void *,unsigned int,unsigned int,void (__thiscall*)(void *))
   
   Library: Visual Studio 2019 Release */

void __ArrayUnwind(void *param_1,uint param_2,uint param_3,_func_void_void_ptr *param_4)

{
  int unaff_EBP;
  int iVar1;
  int iVar2;
  
  FUN_10040d70(&DAT_1004a118,0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = *(int *)(unaff_EBP + 8);
  for (iVar1 = 0; *(int *)(unaff_EBP + -0x24) = iVar1, iVar1 != *(int *)(unaff_EBP + 0x10);
      iVar1 = iVar1 + 1) {
    iVar2 = iVar2 - *(int *)(unaff_EBP + 0xc);
    *(int *)(unaff_EBP + 8) = iVar2;
    guard_check_icall();
    (**(code **)(unaff_EBP + 0x14))();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

