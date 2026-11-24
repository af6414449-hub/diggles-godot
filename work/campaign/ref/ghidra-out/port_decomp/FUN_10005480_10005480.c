
void FUN_10005480(int param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::exception::vftable;
  *(undefined8 *)(in_ECX + 1) = 0;
  __std_exception_copy(param_1 + 4,in_ECX + 1);
  *in_ECX = DX::com_exception::vftable;
  in_ECX[3] = *(undefined4 *)(param_1 + 0xc);
  return;
}

