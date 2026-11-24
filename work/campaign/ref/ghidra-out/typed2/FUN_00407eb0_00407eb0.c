
int FUN_00407eb0(float *param_1)

{
  uint3 uVar1;
  float in_XMM2_Da;
  
  uVar1 = (uint3)((uint)PTR_0077241c >> 8);
  if ((((PTR_0077241c->x0f + in_XMM2_Da <= *param_1) && (*param_1 < PTR_0077241c->x1f - in_XMM2_Da))
      && (PTR_0077241c->y0f + in_XMM2_Da <= param_1[1])) &&
     (param_1[1] < PTR_0077241c->y1f - in_XMM2_Da)) {
    return (uint)uVar1 << 8;
  }
  return CONCAT31(uVar1,1);
}

