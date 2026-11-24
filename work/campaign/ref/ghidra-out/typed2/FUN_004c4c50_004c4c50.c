
void __thiscall FUN_004c4c50(CSceneRenderer *this)

{
  ushort uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  ushort in_stack_00000004;
  uint *in_stack_00000008;
  uint *in_stack_0000000c;
  int in_stack_00000010;
  
  uVar7 = 0;
  uVar2 = in_stack_00000004 >> 5 & 7;
  iVar4 = 0;
  while( true ) {
    uVar1 = in_stack_00000004 >> ((char)iVar4 + 8U & 0x1f) & 3;
    if (uVar1 == 0) {
      uVar7 = 0;
      goto LAB_004c4c99;
    }
    if (uVar1 == 2) break;
    iVar4 = iVar4 + 2;
    if (7 < iVar4) {
LAB_004c4c99:
      uVar6 = 0;
      uVar5 = 0;
      do {
        if ((in_stack_00000004 >> (((char)uVar5 + '\x04') * '\x02' & 0x1fU) & 3) != uVar7) {
          uVar6 = uVar6 | 1 << (uVar5 & 0x1f);
        }
        uVar5 = uVar5 + 1;
      } while ((int)uVar5 < 4);
      if (in_stack_00000010 == 1) {
        uVar5 = uVar6 & 0xfffffffb | 4;
        if ((uVar6 & 1) == 0) {
          uVar5 = uVar6 & 0xfffffffb;
        }
        uVar6 = uVar5 & 0xfffffff7;
        if ((uVar5 & 2) != 0) {
          uVar6 = uVar6 | 8;
        }
      }
      else if (in_stack_00000010 == 2) {
        uVar5 = uVar6 & 0xfffffffe | 1;
        if ((uVar6 & 2) == 0) {
          uVar5 = uVar6 & 0xfffffffe;
        }
        uVar6 = uVar5 & 0xfffffffb;
        if ((uVar5 & 8) != 0) {
          uVar6 = uVar6 | 4;
        }
      }
      if (uVar6 != 0) {
        puVar8 = this->maskGroups + uVar2 * 0x81 + uVar7 * 0x40;
        *in_stack_00000008 = this->maskGroups[uVar2 * 0x81 + 0x80];
        if (uVar6 < 0x10) {
          puVar3 = puVar8 + uVar6 * 4;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar3 = puVar8;
        }
        if (puVar3[1] != 0) {
          uVar2 = (uint)((longlong)(ulonglong)(in_stack_00000004 & 0x1f) % (longlong)(int)puVar3[1])
          ;
          if (uVar6 < 0x10) {
            puVar8 = puVar8 + uVar6 * 4;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          if (puVar8[1] <= uVar2) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *in_stack_0000000c = *(uint *)(*puVar8 + uVar2 * 4);
          return;
        }
        *in_stack_0000000c = this->defaultTexture;
        return;
      }
      *in_stack_00000008 = 0x12;
      *in_stack_0000000c = this->defaultTexture;
      return;
    }
  }
  uVar7 = 1;
  goto LAB_004c4c99;
}

