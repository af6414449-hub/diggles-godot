
void FUN_100054c0(int param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::exception::vftable;
  *(undefined8 *)(in_ECX + 1) = 0;
  __std_exception_copy(param_1 + 4,in_ECX + 1);
  *in_ECX = std::logic_error::vftable;
  return;
}

