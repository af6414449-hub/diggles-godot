
/* Library Function - Single Match
    void __stdcall `eh vector destructor iterator'(void *,unsigned int,unsigned int,void
   (__thiscall*)(void *))
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void _eh_vector_destructor_iterator_
               (void *param_1,uint param_2,uint param_3,_func_void_void_ptr *param_4)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  int iVar3;
  
  FUN_10040d70(&DAT_1004a0f8,0xc);
  *(undefined1 *)(unaff_EBP + -0x19) = 0;
  iVar1 = *(int *)(unaff_EBP + 0xc);
  iVar2 = *(int *)(unaff_EBP + 8) + iVar1 * *(int *)(unaff_EBP + 0x10);
  *(int *)(unaff_EBP + 8) = iVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar3 = *(int *)(unaff_EBP + 0x10);
  while( true ) {
    *(int *)(unaff_EBP + 0x10) = iVar3 + -1;
    if (iVar3 == 0) break;
    iVar2 = iVar2 - iVar1;
    *(int *)(unaff_EBP + 8) = iVar2;
    guard_check_icall();
    (**(code **)(unaff_EBP + 0x14))();
    iVar3 = iVar3 + -1;
  }
  *(undefined1 *)(unaff_EBP + -0x19) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_1004036e();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

