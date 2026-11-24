
undefined4
CDXSound__CSimpleBuffer__Init(int *param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *this;
  float fVar6;
  undefined8 uVar7;
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
    iVar3 = DAT_00783650;
    if (DAT_00c86bd0 == -1) {
      iVar5 = DAT_00783650 * 0x40;
      DAT_00c86bd4 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar5) = "CDXSound::CSimpleBuffer::Init()";
      *(int *)(&DAT_00773650 + iVar5) = iVar3;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00c86bd0);
    }
  }
  iVar5 = DAT_00c86bd4;
  uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00c86bd4 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar2;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar7 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  this->s_0d = 0;
  this->s_09 = 1;
  *(ushort *)((int)this + 0x26) = (byte)param_2 + 1;
  this[10] = param_3;
  *(short *)((int)this + 0x32) = (short)param_4;
  iVar3 = (param_4 & 0xffff) * (uint)*(ushort *)((int)this + 0x26);
  uVar4 = (int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3;
  this->s_0c = (short)uVar4;
  puVar1 = this + 0xe;
  this[0xb] = (uVar4 & 0xffff) * param_3;
  this[0x19] = ((param_2 & 0xff) + 1) * ((int)(param_4 + ((int)param_4 >> 0x1f & 7U)) >> 3) *
                 param_5;
  this[3] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  this[8] = 0;
  *this = 0x24;
  this[1] = 0x480e2;
  *puVar1 = 0;
  this[2] = (uint)this->s_0c * param_5;
  this[4] = this + 9;
  uVar4 = (**(code **)(*param_1 + 0xc))(param_1,this,puVar1,0);
  if (param_2 != uVar4) {
    param_2 = uVar4;
  }
  if ((int)param_2 < 0) {
    FUN_0043fd30();
    ExceptionList = local_10;
    return 0;
  }
  (**(code **)(*(int *)*puVar1 + 0x34))((int *)*puVar1,0);
  fVar6 = 1.0;
  FUN_0040b7e0();
  FUN_0040b7e0();
  DAT_00772dd8 = (int)ROUND(fVar6 * 10000.0);
  (**(code **)(*(int *)*puVar1 + 0x3c))((int *)*puVar1,DAT_00772dd8 + -10000);
  (**(code **)(*(int *)*puVar1 + 0x40))((int *)*puVar1,0);
  this[0x10] = 0;
  this[0x11] = 0;
  this[0x12] = 0;
  this[0x13] = 0;
  this[0xf] = 0x14;
  (**(code **)(*(int *)*puVar1 + 0xc))((int *)*puVar1,this + 0xf);
  this[0x14] = 0;
  this[0x16] = 0;
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

