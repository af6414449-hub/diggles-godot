
void FUN_10005400(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::exception::vftable;
  __std_exception_destroy(in_ECX + 1);
  if ((param_1 & 1) != 0) {
    FUN_100402ac();
  }
  return;
}

