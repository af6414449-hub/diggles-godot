
void __thiscall FUN_004670d0(CDisplay *this)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  int local_c;
  uint local_8;
  
  iVar2 = FUN_0044d010();
  iVar2 = *(int *)(iVar2 + 0x3c);
  iVar3 = FUN_0044d010();
  puVar1 = &this[1].field_0x64;
  local_c = 0;
  iVar3 = *(int *)(iVar3 + 0x40);
  *(undefined4 *)&this[1].field_0x4 = 0x10000;
  *(undefined4 *)&this[1].field_0x8 = 0x10002;
  *(undefined4 *)&this[1].field_0xc = 0x20003;
  *(undefined4 *)&this[1].field_0x10 = 0x50004;
  *(undefined4 *)&this[1].field_0x14 = 0x50006;
  *(undefined4 *)&this[1].field_0x18 = 0x60007;
  *(undefined4 *)&this[1].field_0x1c = 0x90008;
  *(undefined4 *)&this[1].field_0x20 = 0x9000a;
  *(undefined4 *)&this[1].field_0x24 = 0xa000b;
  *(undefined4 *)&this[1].field_0x28 = 0xd000c;
  *(undefined4 *)&this[1].field_0x2c = 0xd000e;
  *(undefined4 *)&this[1].field_0x30 = 0xe000f;
  *(undefined4 *)&this[1].field_0x34 = 0x40001;
  *(undefined4 *)&this[1].field_0x38 = 0x40003;
  *(undefined4 *)&this[1].field_0x3c = 0x30006;
  *(undefined4 *)&this[1].field_0x40 = 0x30002;
  *(undefined4 *)&this[1].field_0x44 = 0x30008;
  *(undefined4 *)&this[1].field_0x48 = 0x90008;
  *(undefined4 *)&this[1].field_0x4c = 0xc0009;
  *(undefined4 *)&this[1].field_0x50 = 0xc000b;
  *(undefined4 *)&this[1].field_0x54 = 0xb000e;
  *(undefined4 *)&this[1].field_0x58 = 0x70006;
  *(undefined4 *)&this[1].field_0x5c = 0x7000c;
  *(undefined4 *)&this[1].field_0x60 = 0xd000c;
  local_8 = 0;
  do {
    if (local_8 < 0x10) {
      puVar4 = puVar1 + local_c;
      *(undefined4 *)(puVar4 + 8) = 0x3f3fff58;
      *(undefined4 *)(puVar4 + 0xc) = 0x3faaab40;
      *(undefined4 *)(puVar4 + 0x10) = 0xffffffff;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      *(undefined4 *)&this[1].field_0x6c = 0x3f3fff58;
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      *(undefined4 *)&this[1].field_0x70 = 0x3faaab40;
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      *(undefined4 *)&this[1].field_0x74 = 0xffffffff;
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = puVar1;
    }
    *(undefined4 *)(puVar4 + 0x14) = 0xf0000000;
    local_c = local_c + 0x20;
    local_8 = local_8 + 1;
  } while ((int)local_8 < 0x10);
  *(undefined4 *)puVar1 = 0;
  puVar4 = &this[1].field_0x264;
  *(undefined4 *)&this[1].field_0x7c = 0;
  *(undefined4 *)puVar4 = 0;
  *(undefined4 *)&this[1].field_0x80 = 0;
  *(undefined4 *)&this[1].field_0x84 = 0x41c00000;
  *(undefined4 *)&this[1].field_0x9c = 0x3f000000;
  *(undefined4 *)&this[1].field_0x268 = 0;
  *(undefined4 *)&this[1].field_0xa0 = 0;
  *(undefined4 *)&this[1].field_0xa4 = 0;
  *(undefined4 *)&this[1].field_0xbc = 0;
  *(undefined4 *)&this[1].field_0x26c = 0x41c00000;
  *(undefined4 *)&this[1].field_0xc0 = 0x3f000000;
  *(undefined4 *)&this[1].field_0xc4 = 0x41c00000;
  *(undefined4 *)&this[1].field_0xdc = 0x3f000000;
  *(undefined4 *)&this[1].field_0x270 = 0x41c00000;
  *(undefined4 *)&this[1].field_0xe0 = 0x3f000000;
  fVar11 = (float)(iVar2 + -0x18);
  fVar10 = (float)iVar2;
  *(float *)&this[1].field_0xe4 = fVar11;
  *(undefined4 *)&this[1].field_0xfc = 0x3f000000;
  *(undefined4 *)&this[1].field_0x274 = 0;
  *(undefined4 *)&this[1].field_0x100 = 0;
  *(float *)&this[1].field_0x104 = fVar10;
  *(undefined4 *)&this[1].field_0x11c = 0;
  *(undefined4 *)&this[1].field_0x278 = 0;
  *(undefined4 *)&this[1].field_0x120 = 0;
  *(float *)&this[1].field_0x124 = fVar11;
  *(undefined4 *)&this[1].field_0x13c = 0x3f000000;
  *(undefined4 *)&this[1].field_0x27c = 0x41c00000;
  *(undefined4 *)&this[1].field_0x140 = 0x3f000000;
  *(float *)&this[1].field_0x144 = fVar10;
  *(undefined4 *)&this[1].field_0x15c = 0;
  *(undefined4 *)&this[1].field_0x280 = 0x41c00000;
  *(undefined4 *)&this[1].field_0x160 = 0x3f000000;
  *(undefined4 *)&this[1].field_0x164 = 0;
  *(undefined4 *)&this[1].field_0x17c = 0;
  fVar8 = (float)(iVar3 + -0x18);
  local_8 = 0;
  *(float *)&this[1].field_0x284 = fVar8;
  *(undefined4 *)&this[1].field_0x180 = 0x3f000000;
  *(undefined4 *)&this[1].field_0x184 = 0x41c00000;
  *(undefined4 *)&this[1].field_0x19c = 0x3f000000;
  *(float *)&this[1].field_0x288 = fVar8;
  *(undefined4 *)&this[1].field_0x1a0 = 0x3f000000;
  *(undefined4 *)&this[1].field_0x1a4 = 0;
  *(undefined4 *)&this[1].field_0x1bc = 0;
  fVar9 = (float)iVar3;
  *(float *)&this[1].field_0x28c = fVar9;
  *(undefined4 *)&this[1].field_0x1c0 = 0;
  *(undefined4 *)&this[1].field_0x1c4 = 0x41c00000;
  *(undefined4 *)&this[1].field_0x1dc = 0x3f000000;
  *(float *)&this[1].field_0x290 = fVar9;
  *(undefined4 *)&this[1].field_0x1e0 = 0;
  *(float *)&this[1].field_0x1e4 = fVar11;
  *(undefined4 *)&this[1].field_0x1fc = 0x3f000000;
  *(float *)&this[1].field_0x294 = fVar8;
  *(undefined4 *)&this[1].field_0x200 = 0x3f000000;
  *(float *)&this[1].field_0x204 = fVar10;
  *(undefined4 *)&this[1].field_0x21c = 0;
  *(float *)&this[1].field_0x298 = fVar8;
  *(undefined4 *)&this[1].field_0x220 = 0x3f000000;
  *(float *)&this[1].field_0x224 = fVar11;
  *(undefined4 *)&this[1].field_0x23c = 0x3f000000;
  *(float *)&this[1].field_0x29c = fVar9;
  *(undefined4 *)&this[1].field_0x240 = 0;
  *(float *)&this[1].field_0x244 = fVar10;
  *(undefined4 *)&this[1].field_0x25c = 0;
  *(float *)&this[1].field_0x2a0 = fVar9;
  *(undefined4 *)&this[1].field_0x260 = 0;
  uVar7 = 0;
  local_c = 0;
  do {
    if (uVar7 < 0x10) {
      puVar5 = (undefined4 *)(puVar4 + local_c);
      puVar6 = puVar1 + local_8;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = (undefined4 *)puVar4;
      puVar6 = puVar1;
    }
    local_c = local_c + 4;
    *(undefined4 *)(puVar6 + 4) = *puVar5;
    uVar7 = uVar7 + 1;
    local_8 = local_8 + 0x20;
  } while ((int)uVar7 < 0x10);
  return;
}

