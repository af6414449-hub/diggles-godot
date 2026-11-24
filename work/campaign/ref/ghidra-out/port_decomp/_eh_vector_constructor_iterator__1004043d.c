
/* Library Function - Single Match
    void __stdcall `eh vector constructor iterator'(void *,unsigned int,unsigned int,void
   (__thiscall*)(void *),void (__thiscall*)(void *))
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void _eh_vector_constructor_iterator_
               (void *param_1,uint param_2,uint param_3,_func_void_void_ptr *param_4,
               _func_void_void_ptr *param_5)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_10040d70(&DAT_1004a138,0x10);
  iVar1 = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined1 *)(unaff_EBP + -0x19) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  while (iVar1 != *(int *)(unaff_EBP + 0x10)) {
    guard_check_icall();
    (**(code **)(unaff_EBP + 0x14))();
    *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + *(int *)(unaff_EBP + 0xc);
    iVar1 = iVar1 + 1;
    *(int *)(unaff_EBP + -0x20) = iVar1;
  }
  *(undefined1 *)(unaff_EBP + -0x19) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_1004049d();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

