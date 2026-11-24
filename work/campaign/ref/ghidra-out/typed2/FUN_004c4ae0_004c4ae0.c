
void __thiscall FUN_004c4ae0(CSceneRenderer *this)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 *in_stack_00000004;
  uint in_stack_00000008;
  uint in_stack_0000000c;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int in_stack_00000018;
  uint in_stack_0000001c;
  char in_stack_00000024;
  
  if (in_stack_00000018 == 1) {
    *in_stack_00000004 = 0;
    uVar6 = in_stack_00000010;
    uVar2 = in_stack_00000010;
    in_stack_0000000c = in_stack_00000014;
LAB_004c4b4b:
    uVar3 = uVar6 & 0xffffff00;
    in_stack_00000008 = uVar6;
    in_stack_00000010 = uVar2;
  }
  else {
    if (in_stack_00000018 == 2) {
      uVar3 = in_stack_0000001c & 0x80000003;
      if ((int)uVar3 < 0) {
        uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
      }
      *in_stack_00000004 = 0;
      uVar6 = in_stack_0000000c;
      uVar2 = in_stack_00000014;
      if (uVar3 == 0) {
        uVar6 = in_stack_00000008;
        uVar2 = in_stack_00000010;
        in_stack_00000014 = in_stack_00000010;
        in_stack_0000000c = in_stack_00000008;
      }
      goto LAB_004c4b4b;
    }
    *in_stack_00000004 = 0;
    uVar3 = in_stack_00000008 & 0xffffff00;
    if (in_stack_00000018 == 0) goto LAB_004c4b5b;
  }
  if (in_stack_00000024 != '\0') {
    uVar3 = 0;
  }
LAB_004c4b5b:
  uVar2 = (((in_stack_00000014 & 3) * 3 + (in_stack_00000010 & 3)) * 3 + (in_stack_0000000c & 3)) *
          3 + (in_stack_00000008 & 3);
  uVar6 = uVar2 & 0xff;
  if ((int)uVar6 < this->textureCount) {
    puVar5 = this->variants;
    if (uVar6 < 0x52) {
      puVar4 = puVar5 + uVar6;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = puVar5;
    }
    if (*puVar4 != 0) {
      if (uVar6 < 0x52) {
        uVar1 = puVar5[uVar6];
        puVar5 = this->textureIndex + uVar6;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar1 = *puVar5;
        puVar5 = this->textureIndex;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar6 = *puVar5 + ((int)(uVar2 | uVar3) >> 8) % (int)uVar1;
      if ((uint)this->textureCount <= uVar6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *in_stack_00000004 = *(undefined4 *)((int)this->textures + uVar6 * 4);
    }
  }
  return;
}

