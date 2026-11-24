
void __thiscall FUN_005094d0(ViWinChat *this)

{
  int iVar1;
  int local_18 [5];
  
  local_18[1] = 0xf;
  local_18[2] = 0;
  local_18[0] = this->i_14 - this->i_0c;
  local_18[3] = (this->i_18 - this->i_10) + -0xf;
  iVar1 = FUN_0054c770(local_18,&PTR_0071ce50);
  this->i_c8 = iVar1;
  if (*(char *)(iVar1 + 0x1c) != '\0') {
    FUN_00504ee0();
    *(undefined1 *)(iVar1 + 0x1c) = 0;
  }
  return;
}

