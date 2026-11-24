
void thunk_FUN_0060fc30(void)

{
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_006f9530;
  pvStack_10 = ExceptionList;
  ExceptionList = &pvStack_10;
  FUN_006ba940(DAT_0076700c ^ (uint)&stack0xfffffffc);
  ExceptionList = pvStack_10;
  return;
}

