
void FUN_005cd520(void)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070882d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((PTR_0077241c != (CMap *)0x0) && ((char)PTR_0077241c->mapFlags != '\0')) {
    fVar1 = *(float *)(in_ECX + 0xc);
    fVar2 = *(float *)(in_ECX + 0x10);
    iVar4 = _rand();
    iVar5 = _rand();
    iVar5 = (int)ROUND((((float)iVar5 * 3.0517578e-05 - 0.5) + fVar1) * 8.0);
    DAT_00772dd8 = (int)ROUND(((fVar2 - 0.2) - (float)iVar4 * 3.0517578e-05) * 8.0);
    if (((PTR_0077241c->x0_8 <= iVar5) &&
        (((iVar5 < PTR_0077241c->x1_8 && (PTR_0077241c->y0_8 <= DAT_00772dd8)) &&
         (DAT_00772dd8 < PTR_0077241c->y1_8)))) && (bVar3 = FUN_004093f0(PTR_0077241c), bVar3 < 0xf)
       ) {
      FUN_004093f0(PTR_0077241c);
      FUN_004093f0(PTR_0077241c);
      FUN_004093f0(PTR_0077241c);
      FUN_004093f0(PTR_0077241c);
      local_8 = 0;
      FUN_00592d70();
      local_8 = 0xffffffff;
      FUN_005912a0();
    }
  }
  ExceptionList = local_10;
  return;
}

