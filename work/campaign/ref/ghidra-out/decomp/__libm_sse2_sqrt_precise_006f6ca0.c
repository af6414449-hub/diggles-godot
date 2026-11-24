
/* Library Function - Single Match
    __libm_sse2_sqrt_precise
   
   Library: Visual Studio 2019 Release */

void __libm_sse2_sqrt_precise(void)

{
  undefined4 uVar1;
  ushort in_FPUControlWord;
  undefined1 in_XMM0 [16];
  ulonglong local_8;
  
  local_8 = in_XMM0._0_8_;
  if (((MXCSR & 0x7f80) != 0x1f80) || ((in_FPUControlWord & 0x7f) != 0x7f)) {
    FUN_006f77b0();
    return;
  }
  if (((in_XMM0._6_2_ & 0x7ff0) == 0x7ff0) &&
     (((((in_XMM0 & (undefined1  [16])0xf000000000000) != (undefined1  [16])0x0 ||
        (in_XMM0._4_2_ != 0)) || (in_XMM0._2_2_ != 0)) || (in_XMM0._0_2_ != 0)))) {
    local_8 = local_8 | 0x8000000000000;
    uVar1 = 0x3f5;
  }
  else {
    if (((in_XMM0 & (undefined1  [16])0x8000000000000000) == (undefined1  [16])0x0) ||
       (((local_8._0_4_ = in_XMM0._0_4_, (int)local_8 == 0 && (in_XMM0._6_2_ == 0x8000)) &&
        (in_XMM0._4_2_ == 0)))) {
      return;
    }
    local_8 = 0xfff8000000000000;
    uVar1 = 0x31;
  }
  ___libm_error_support(&local_8,&local_8,&local_8,uVar1);
  return;
}

