
void __thiscall FUN_0050d9f0(ViWinDecoLineH *this)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *in_stack_00000004;
  
  piVar4 = in_stack_00000004;
  puVar1 = &this->field_0x44;
  if ((((this->i_4c != 0) && (iVar6 = *(int *)puVar1, 0 < iVar6)) && (0 < this->i_48)) &&
     (((this->i_68 != 0 && (0 < this->i_60)) && (0 < this->i_64)))) {
    iVar2 = *in_stack_00000004;
    in_stack_00000004 = (int *)0x0;
    if (*(int *)(iVar2 + 8) != 0) {
      FUN_004ff430(iVar2 + 0xc,&stack0x00000004);
      iVar6 = *(int *)puVar1;
    }
    iVar2 = this->i_14;
    iVar3 = this->i_0c;
    iVar7 = 0;
    in_stack_00000004 = (int *)(iVar6 * 2);
    iVar5 = (int)in_stack_00000004;
    while (iVar5 < iVar2 - iVar3) {
      FUN_004ff900(puVar1,piVar4[2] + iVar7,piVar4[3],*(undefined4 *)puVar1,this->i_48,0,0,0);
      iVar7 = iVar7 + iVar6;
      iVar5 = (int)in_stack_00000004 + iVar7;
    }
    FUN_004ff900(&this->i_60,piVar4[2] + iVar7,piVar4[3],this->i_60,this->i_64,0,0,0);
  }
  return;
}

