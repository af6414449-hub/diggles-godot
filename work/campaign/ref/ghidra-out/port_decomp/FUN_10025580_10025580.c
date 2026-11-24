
void FUN_10025580(float *param_1)

{
  float *in_ECX;
  int in_EDX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  *in_ECX = ((param_1[0x340] + param_1[0x40]) * 213.0 + (param_1[0x380] - *param_1) * 29.0 +
             (param_1[0x300] - param_1[0x80]) * 459.0 + (param_1[0x2c0] + param_1[0xc0]) * 2037.0 +
             (param_1[0x280] - param_1[0x100]) * 5153.0 + (param_1[0x240] + param_1[0x140]) * 6574.0
             + (param_1[0x200] - param_1[0x180]) * 37489.0 + param_1[0x1c0] * 75038.0) *
            3.0517578e-05;
  in_ECX[in_EDX * 0x10] =
       (((((param_1[0x382] * 104.0 + param_1[0x302] * 1567.0 + param_1[0x282] * 9727.0 +
           param_1[0x202] * 64019.0) - param_1[0x182] * 9975.0) - param_1[0x102] * 45.0) +
        param_1[0x82] * 146.0) - param_1[2] * 5.0) * 3.0517578e-05;
  return;
}

