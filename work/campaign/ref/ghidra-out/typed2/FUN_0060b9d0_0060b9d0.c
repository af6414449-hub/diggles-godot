
undefined4 FUN_0060b9d0(void)

{
  int iVar1;
  char cVar2;
  int in_ECX;
  float local_10;
  float local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(in_ECX + 0x1c);
  local_8 = *(undefined4 *)(iVar1 + 0x14);
  local_c = *(float *)(iVar1 + 0x10) + 1.0;
  local_10 = *(float *)(iVar1 + 0xc);
  if ((((PTR_0077241c->x0f + 4.0 <= local_10) && (local_10 < PTR_0077241c->x1f - 4.0)) &&
      (PTR_0077241c->y0f + 4.0 <= local_c)) && (local_c < PTR_0077241c->y1f - 4.0)) {
    cVar2 = FUN_004093f0(PTR_0077241c);
    if (cVar2 == '\v') {
      cVar2 = FUN_004093f0(PTR_0077241c);
      if (cVar2 == '\v') {
        FUN_005cd7e0(&local_10);
        return 1;
      }
    }
  }
  return 0;
}

