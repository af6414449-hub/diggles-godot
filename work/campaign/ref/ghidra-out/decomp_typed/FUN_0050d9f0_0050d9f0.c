
void FUN_0050d9f0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int this;
  int iVar6;
  int iVar7;
  
  piVar4 = param_1;
  piVar1 = (int *)(this + 0x44);
  if ((((this->i_4c != 0) && (iVar6 = *piVar1, 0 < iVar6)) &&
      (0 < this->i_48)) &&
     (((this->i_68 != 0 && (0 < this->i_60)) &&
      (0 < this->i_64)))) {
    iVar2 = *param_1;
    param_1 = (int *)0x0;
    if (*(int *)(iVar2 + 8) != 0) {
      FUN_004ff430(iVar2 + 0xc,&param_1);
      iVar6 = *piVar1;
    }
    iVar2 = this->i_14;
    iVar3 = this->i_0c;
    iVar7 = 0;
    param_1 = (int *)(iVar6 * 2);
    iVar5 = (int)param_1;
    while (iVar5 < iVar2 - iVar3) {
      FUN_004ff900(piVar1,piVar4[2] + iVar7,piVar4[3],*piVar1,this->i_48,0,0,0);
      iVar7 = iVar7 + iVar6;
      iVar5 = (int)param_1 + iVar7;
    }
    FUN_004ff900((undefined4 *)(this + 0x60),piVar4[2] + iVar7,piVar4[3],
                 this->i_60,this->i_64,0,0,0);
  }
  return;
}

