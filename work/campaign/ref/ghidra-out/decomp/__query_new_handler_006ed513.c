
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __query_new_handler
   
   Library: Visual Studio 2019 Release */

uint __query_new_handler(void)

{
  byte bVar1;
  int unaff_EBP;
  uint uVar2;
  
  FUN_006cf3b0(&DAT_007638e8,0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  ___acrt_lock(0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  bVar1 = (byte)DAT_0076700c & 0x1f;
  uVar2 = (DAT_0076700c ^ _DAT_0076a214) >> bVar1 | (DAT_0076700c ^ _DAT_0076a214) << 0x20 - bVar1;
  *(uint *)(unaff_EBP + -0x1c) = uVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006ed566();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return uVar2;
}

