
void __thiscall FUN_004cca20(CSceneRenderer *this)

{
  void **ppvVar1;
  void **ppvVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  float *in_stack_00000004;
  float *in_stack_00000008;
  float *in_stack_0000000c;
  float *in_stack_00000010;
  
  iVar9 = 0xff;
  if (DAT_0076a334 < 0xff) {
    iVar9 = DAT_0076a334;
  }
  iVar7 = 0xff;
  if (DAT_0076a330 < 0xff) {
    iVar7 = DAT_0076a330;
  }
  uVar4 = this->fogVertexCount;
  uVar5 = this->fogIndexCount;
  uVar8 = 0xff;
  if ((int)DAT_0076a32c < 0xff) {
    uVar8 = DAT_0076a32c;
  }
  uVar8 = (iVar7 << 8 | iVar9 << 0x10) & 0xffff00U | uVar8;
  ppvVar1 = &this->fogVertices;
  FUN_004ce630(uVar4 + 4);
  ppvVar2 = &this->fogIndices;
  FUN_004ce760(this->fogIndexCount + 6);
  fVar3 = *in_stack_00000004;
  if ((uint)this->fogVertexCount <= uVar4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(float *)((int)*ppvVar1 + uVar4 * 0x1c) = fVar3 - 0.01;
  if ((uint)this->fogVertexCount <= uVar4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(float *)((int)*ppvVar1 + uVar4 * 0x1c + 4) = in_stack_00000004[1] - 0.01;
  if ((uint)this->fogVertexCount <= uVar4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)((int)*ppvVar1 + uVar4 * 0x1c + 8) = 0x41680000;
  if ((uint)this->fogVertexCount <= uVar4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)((int)*ppvVar1 + uVar4 * 0x1c + 0x14) = 0;
  if ((uint)this->fogVertexCount <= uVar4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)((int)*ppvVar1 + uVar4 * 0x1c + 0x18) = 0;
  if ((uint)this->fogVertexCount <= uVar4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)((int)*ppvVar1 + uVar4 * 0x1c + 0xc) = 0;
  if ((uint)this->fogVertexCount <= uVar4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(uint *)((int)*ppvVar1 + uVar4 * 0x1c + 0x10) = uVar8;
  uVar11 = uVar4 + 1;
  fVar3 = *in_stack_00000008;
  if ((uint)this->fogVertexCount <= uVar11) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(float *)((int)*ppvVar1 + uVar11 * 0x1c) = fVar3 + 0.01;
  if ((uint)this->fogVertexCount <= uVar11) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(float *)((int)*ppvVar1 + uVar11 * 0x1c + 4) = in_stack_00000008[1] - 0.01;
  if ((uint)this->fogVertexCount <= uVar11) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)((int)*ppvVar1 + uVar11 * 0x1c + 8) = 0x41680000;
  if ((uint)this->fogVertexCount <= uVar11) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)((int)*ppvVar1 + uVar11 * 0x1c + 0x14) = 0;
  if ((uint)this->fogVertexCount <= uVar11) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)((int)*ppvVar1 + uVar11 * 0x1c + 0x18) = 0;
  if ((uint)this->fogVertexCount <= uVar11) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)((int)*ppvVar1 + uVar11 * 0x1c + 0xc) = 0;
  if ((uint)this->fogVertexCount <= uVar11) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  uVar10 = uVar4 + 2;
  *(uint *)((int)*ppvVar1 + uVar11 * 0x1c + 0x10) = uVar8;
  fVar3 = *in_stack_0000000c;
  if ((uint)this->fogVertexCount <= uVar10) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(float *)((int)*ppvVar1 + uVar10 * 0x1c) = fVar3 - 0.01;
  if ((uint)this->fogVertexCount <= uVar10) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(float *)((int)*ppvVar1 + uVar10 * 0x1c + 4) = in_stack_0000000c[1] + 0.01;
  if ((uint)this->fogVertexCount <= uVar10) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)((int)*ppvVar1 + uVar10 * 0x1c + 8) = 0x41680000;
  if ((uint)this->fogVertexCount <= uVar10) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)((int)*ppvVar1 + uVar10 * 0x1c + 0x14) = 0;
  if ((uint)this->fogVertexCount <= uVar10) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)((int)*ppvVar1 + uVar10 * 0x1c + 0x18) = 0;
  if ((uint)this->fogVertexCount <= uVar10) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)((int)*ppvVar1 + uVar10 * 0x1c + 0xc) = 0;
  if ((uint)this->fogVertexCount <= uVar10) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  uVar11 = uVar4 + 3;
  *(uint *)((int)*ppvVar1 + uVar10 * 0x1c + 0x10) = uVar8;
  fVar3 = *in_stack_00000010;
  if ((uint)this->fogVertexCount <= uVar11) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(float *)((int)*ppvVar1 + uVar11 * 0x1c) = fVar3 + 0.01;
  if ((uint)this->fogVertexCount <= uVar11) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(float *)((int)*ppvVar1 + uVar11 * 0x1c + 4) = in_stack_00000010[1] + 0.01;
  if ((uint)this->fogVertexCount <= uVar11) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)((int)*ppvVar1 + uVar11 * 0x1c + 8) = 0x41680000;
  if ((uint)this->fogVertexCount <= uVar11) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)((int)*ppvVar1 + uVar11 * 0x1c + 0x14) = 0;
  if ((uint)this->fogVertexCount <= uVar11) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)((int)*ppvVar1 + uVar11 * 0x1c + 0x18) = 0;
  if ((uint)this->fogVertexCount <= uVar11) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)((int)*ppvVar1 + uVar11 * 0x1c + 0xc) = 0;
  if ((uint)this->fogVertexCount <= uVar11) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(uint *)((int)*ppvVar1 + uVar11 * 0x1c + 0x10) = uVar8;
  if ((uint)this->fogIndexCount <= uVar5) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  sVar6 = (short)uVar4;
  *(short *)((int)*ppvVar2 + uVar5 * 2) = sVar6;
  if ((uint)this->fogIndexCount <= uVar5 + 1) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(short *)((int)*ppvVar2 + uVar5 * 2 + 2) = sVar6 + 1;
  if ((uint)this->fogIndexCount <= uVar5 + 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(short *)((int)*ppvVar2 + (uVar5 + 2) * 2) = sVar6 + 2;
  if ((uint)this->fogIndexCount <= uVar5 + 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(short *)((int)*ppvVar2 + (uVar5 + 3) * 2) = sVar6 + 1;
  if ((uint)this->fogIndexCount <= uVar5 + 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(short *)((int)*ppvVar2 + (uVar5 + 4) * 2) = sVar6 + 3;
  if ((uint)this->fogIndexCount <= uVar5 + 5) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(short *)((int)*ppvVar2 + (uVar5 + 5) * 2) = sVar6 + 2;
  return;
}

