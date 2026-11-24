
void __thiscall FUN_0053bc10(ViWinSpeechText *this)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  float fVar4;
  int local_1c;
  int *local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fb0a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(double *)(DAT_00772400 + 0xa088) < this->d_50 ||
      *(double *)(DAT_00772400 + 0xa088) == this->d_50) {
    piVar1 = *(int **)&this->field_0x20;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_18 = piVar1;
    cVar3 = FUN_006b97f0(&local_18);
    local_11 = cVar3 == '\0';
    local_8 = 0;
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
      FUN_006ba940();
    }
    local_8 = 0xffffffff;
    if (local_11 == '\0') {
      iVar2 = this->i_34;
      fVar4 = (float)(*(int *)(iVar2 + 0x18) - *(int *)(iVar2 + 0x10));
      local_18 = (int *)(int)(fVar4 - (fVar4 - fVar4 * 9.0 * 0.0625) * 0.5);
      local_1c = (((*(int *)(iVar2 + 0x14) - this->i_14) - *(int *)(iVar2 + 0xc)) + this->i_0c) / 2;
      FUN_00504a70(&local_1c);
      piVar1 = *(int **)&this->field_0x20;
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      local_18 = piVar1;
      cVar3 = FUN_006b97f0(&local_18);
      local_8 = 1;
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
        FUN_006ba940();
      }
      if (cVar3 != '\0') {
        ExceptionList = local_10;
        return;
      }
    }
    local_8 = 0xffffffff;
    FUN_0053b760();
  }
  else if (this->c_1c != '\0') {
    FUN_00504ee0(DAT_0076700c ^ (uint)&stack0xfffffffc);
    this->c_1c = '\0';
    ExceptionList = local_10;
    return;
  }
  ExceptionList = local_10;
  return;
}

