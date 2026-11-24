
void FUN_1000b8c0(uint param_1)

{
  uint uVar1;
  size_t _Size;
  uint uVar2;
  code *pcVar3;
  void *pvVar4;
  undefined4 *in_ECX;
  uint uVar5;
  uint uVar6;
  void *pvVar7;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b7b);
  uVar5 = in_ECX[4];
  if (uVar5 <= param_1) {
    uVar2 = in_ECX[5];
    if (uVar2 != param_1) {
      if (uVar2 < param_1) {
        if (0x7ffffffe - uVar5 < param_1 - uVar5) {
          FUN_10002ab0();
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        uVar6 = param_1 | 7;
        if (uVar6 < 0x7fffffff) {
          if (0x7ffffffe - (uVar2 >> 1) < uVar2) {
            uVar6 = 0x7ffffffe;
          }
          else {
            uVar1 = (uVar2 >> 1) + uVar2;
            if (uVar6 < uVar1) {
              uVar6 = uVar1;
            }
          }
        }
        else {
          uVar6 = 0x7ffffffe;
        }
        pvVar4 = (void *)FUN_1000b850(-(uint)(0xfffffffe < uVar6) | uVar6 + 1);
        in_ECX[5] = uVar6;
        in_ECX[4] = param_1;
        _Size = uVar5 * 2 + 2;
        if (uVar2 < 8) {
          memcpy(pvVar4,in_ECX,_Size);
          *in_ECX = pvVar4;
          in_ECX[4] = uVar5;
          return;
        }
        pvVar7 = (void *)*in_ECX;
        memcpy(pvVar4,pvVar7,_Size);
        FUN_1000b710(pvVar7,uVar2 + 1);
        *in_ECX = pvVar4;
        in_ECX[4] = uVar5;
        return;
      }
      if ((param_1 < 8) && (7 < uVar2)) {
        pvVar4 = (void *)*in_ECX;
        memcpy(in_ECX,pvVar4,uVar5 * 2 + 2);
        uVar5 = in_ECX[5] * 2 + 2;
        pvVar7 = pvVar4;
        if (0xfff < uVar5) {
          pvVar7 = *(void **)((int)pvVar4 + -4);
          uVar5 = in_ECX[5] * 2 + 0x25;
          if (0x1f < (uint)((int)pvVar4 + (-4 - (int)pvVar7))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
        }
        FUN_100402ac(pvVar7,uVar5);
        in_ECX[5] = 7;
      }
    }
  }
  return;
}

