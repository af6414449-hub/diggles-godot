
void FUN_1000ba20(char *param_1,char *param_2)

{
  uint uVar1;
  short *psVar2;
  uint uVar3;
  void *_Src;
  code *pcVar4;
  size_t _Size;
  short sVar5;
  undefined4 *puVar6;
  void *_Dst;
  undefined4 *in_ECX;
  undefined4 in_EDX;
  uint uVar7;
  uint uVar8;
  void *pvVar9;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041fcd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170b7b,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (param_1 != param_2) {
    do {
      sVar5 = (short)*param_1;
      uVar3 = in_ECX[5];
      uVar7 = in_ECX[4];
      if (uVar7 < uVar3) {
        in_ECX[4] = uVar7 + 1;
        puVar6 = in_ECX;
        if (7 < uVar3) {
          puVar6 = (undefined4 *)*in_ECX;
        }
        *(short *)((int)puVar6 + uVar7 * 2) = sVar5;
        *(undefined2 *)((int)puVar6 + uVar7 * 2 + 2) = 0;
      }
      else {
        if (uVar7 == 0x7ffffffe) {
          FUN_10002ab0();
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        uVar8 = uVar7 + 1 | 7;
        if (uVar8 < 0x7fffffff) {
          if (0x7ffffffe - (uVar3 >> 1) < uVar3) {
            uVar8 = 0x7ffffffe;
          }
          else {
            uVar1 = (uVar3 >> 1) + uVar3;
            if (uVar8 < uVar1) {
              uVar8 = uVar1;
            }
          }
        }
        else {
          uVar8 = 0x7ffffffe;
        }
        _Dst = (void *)FUN_1000b850(-(uint)(0xfffffffe < uVar8) | uVar8 + 1);
        in_ECX[5] = uVar8;
        in_ECX[4] = uVar7 + 1;
        _Size = uVar7 * 2;
        psVar2 = (short *)(_Size + (int)_Dst);
        if (uVar3 < 8) {
          memcpy(_Dst,in_ECX,_Size);
          *psVar2 = sVar5;
          psVar2[1] = 0;
        }
        else {
          _Src = (void *)*in_ECX;
          memcpy(_Dst,_Src,_Size);
          uVar7 = uVar3 * 2 + 2;
          *psVar2 = sVar5;
          psVar2[1] = 0;
          pvVar9 = _Src;
          if (0xfff < uVar7) {
            pvVar9 = *(void **)((int)_Src + -4);
            uVar7 = uVar3 * 2 + 0x25;
            if (0x1f < (uint)((int)_Src + (-4 - (int)pvVar9))) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
          }
          FUN_100402ac(pvVar9,uVar7);
        }
        *in_ECX = _Dst;
      }
      param_1 = param_1 + 1;
    } while (param_1 != param_2);
  }
  ExceptionList = local_10;
  return;
}

