
undefined1 __thiscall FUN_00408d00(CAct_Attack *this)

{
  double dVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int in_stack_00000008;
  int *in_stack_0000000c;
  int *in_stack_00000010;
  int *in_stack_00000014;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f982d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  if (in_stack_00000014 != (int *)0x0) {
    *in_stack_00000014 = *in_stack_00000014 + 1;
  }
  if (in_stack_00000010 != (int *)0x0) {
    *in_stack_00000010 = *in_stack_00000010 + 1;
  }
  if (in_stack_0000000c != (int *)0x0) {
    *in_stack_0000000c = *in_stack_0000000c + 1;
  }
  cVar3 = FUN_00406630((CAct *)this);
  if (((cVar3 == '\0') || (iVar2 = this->i_0c, iVar2 == 0)) || (this->c_51 != '\0')) {
    uVar4 = 0;
  }
  else {
    if ((*(uint *)(iVar2 + 0x3d0) & 0x2000) != 0) {
      this->i_2c = this->i_2c + 1;
      this->i_34 = this->i_34 + 1;
    }
    uVar5 = 0;
    uVar6 = 0;
    if (this->i_30 != -1) {
      FUN_006b49b0(iVar2,this->i_2c,this->i_30);
    }
    uVar4 = 1;
    dVar1 = *(double *)(DAT_00772400 + 0xa088);
    this->i_4c = 0;
    this->d_40 = dVar1 + (double)CONCAT44(uVar6,uVar5);
    *(bool *)(in_stack_00000008 + 0x2b5) = this->c_4a == '\0';
  }
  if ((in_stack_0000000c != (int *)0x0) &&
     (*in_stack_0000000c = *in_stack_0000000c + -1, *in_stack_0000000c < 1)) {
    TclFreeObj();
  }
  if ((in_stack_00000010 != (int *)0x0) &&
     (*in_stack_00000010 = *in_stack_00000010 + -1, *in_stack_00000010 < 1)) {
    TclFreeObj();
  }
  if ((in_stack_00000014 != (int *)0x0) &&
     (*in_stack_00000014 = *in_stack_00000014 + -1, *in_stack_00000014 < 1)) {
    TclFreeObj();
  }
  ExceptionList = local_10;
  return uVar4;
}

