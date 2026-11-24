
undefined4 __thiscall CDXSound__CSimpleBuffer__Init(CDXSound *this)

{
  undefined1 *puVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  float fVar7;
  undefined8 uVar8;
  int *in_stack_00000004;
  byte bStack00000008;
  int in_stack_0000000c;
  uint in_stack_00000010;
  int in_stack_00000014;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fc73d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c86bd0) {
    FUN_006cebf4(&DAT_00c86bd0,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar4 = DAT_00783650;
    if (DAT_00c86bd0 == -1) {
      iVar6 = DAT_00783650 * 0x40;
      DAT_00c86bd4 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar6) = "CDXSound::CSimpleBuffer::Init()";
      *(int *)(&DAT_00773650 + iVar6) = iVar4;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00c86bd0);
    }
  }
  iVar6 = DAT_00c86bd4;
  uVar3 = *(undefined4 *)(&DAT_00773650 + DAT_00c86bd4 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar3;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar4 == 0) {
    uVar8 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar4 + 1;
  local_8 = 0;
  *(undefined2 *)&this[3].field_0x1 = 0;
  *(undefined2 *)&this[2].field_0x2 = 1;
  *(ushort *)&this[2].field_0x4 = bStack00000008 + 1;
  *(int *)&this[2].field_0x6 = in_stack_0000000c;
  *(short *)((int)&this[2].s_0c + 1) = (short)in_stack_00000010;
  iVar4 = (in_stack_00000010 & 0xffff) * (uint)*(ushort *)&this[2].field_0x4;
  uVar5 = (int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3;
  *(short *)((int)&this[2].s_0d + 1) = (short)uVar5;
  puVar1 = &this[3].field_0x5;
  *(uint *)((int)&this[2].s_09 + 1) = (uVar5 & 0xffff) * in_stack_0000000c;
  *(uint *)&this[5].s_0c =
       ((_bStack00000008 & 0xff) + 1) *
       ((int)(in_stack_00000010 + ((int)in_stack_00000010 >> 0x1f & 7U)) >> 3) * in_stack_00000014;
  *(undefined4 *)&this->field_0xc = 0;
  *(undefined4 *)&this[1].field_0x3 = 0;
  *(undefined4 *)&this[1].field_0x7 = 0;
  *(undefined4 *)&this[1].field_0xb = 0;
  *(undefined4 *)&this[1].s_0c = 0;
  uVar2 = *(ushort *)((int)&this[2].s_0d + 1);
  *(undefined4 *)this = 0x24;
  *(undefined4 *)&this->field_0x4 = 0x480e2;
  *(undefined4 *)puVar1 = 0;
  *(uint *)&this->field_0x8 = (uint)uVar2 * in_stack_00000014;
  *(undefined1 **)((int)&this->s_0c + 1) = &this[2].field_0x2;
  uVar5 = (**(code **)(*in_stack_00000004 + 0xc))(in_stack_00000004,this,puVar1,0);
  if (_bStack00000008 != uVar5) {
    _bStack00000008 = uVar5;
  }
  if ((int)_bStack00000008 < 0) {
    FUN_0043fd30();
    ExceptionList = local_10;
    return 0;
  }
  (**(code **)(**(int **)puVar1 + 0x34))(*(int **)puVar1,0);
  fVar7 = 1.0;
  FUN_0040b7e0();
  FUN_0040b7e0();
  DAT_00772dd8 = (int)ROUND(fVar7 * 10000.0);
  (**(code **)(**(int **)puVar1 + 0x3c))(*(int **)puVar1,DAT_00772dd8 + -10000);
  (**(code **)(**(int **)puVar1 + 0x40))(*(int **)puVar1,0);
  this[3].s_0d = 0;
  this[3].s_0c = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)&this[4].field_0x4 = 0;
  *(undefined4 *)&this[4].field_0x8 = 0;
  *(undefined4 *)&this[3].s_09 = 0x14;
  (**(code **)(**(int **)puVar1 + 0xc))(*(int **)puVar1,&this[3].s_09);
  *(undefined4 *)&this[4].field_0xc = 0;
  *(undefined4 *)&this[5].field_0x3 = 0;
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

