
void FUN_10040b34(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[1] = "bad allocation";
  *in_ECX = std::bad_alloc::vftable;
  return;
}

