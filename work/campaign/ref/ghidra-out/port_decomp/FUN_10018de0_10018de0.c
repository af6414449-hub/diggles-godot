
void FUN_10018de0(int *param_1)

{
  int iVar1;
  int iVar2;
  ID3D11Texture2D *pIVar3;
  int *piVar4;
  void *_Dst;
  int *in_ECX;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int aiStack_164 [24];
  undefined4 uStack_104;
  int *piStack_100;
  ChunkedTexture local_c8 [180];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10042b3a;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (DAT_10050c64 == (int *)0x0) {
    _Dst = (void *)FUN_1003ff62();
    local_8 = 0;
    memset(_Dst,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
  }
  piVar4 = DAT_10050c64;
  iVar1 = in_ECX[0xd];
  iVar2 = in_ECX[0xe];
  if (param_1 == (int *)0x0) {
    if ((in_ECX[0x43] != iVar2) || (in_ECX[0x42] != iVar1)) goto LAB_10018eba;
  }
  else if ((*param_1 != in_ECX[0x40]) ||
          (((param_1[1] != in_ECX[0x41] || (param_1[2] != in_ECX[0x42])) ||
           (param_1[3] != in_ECX[0x43])))) goto LAB_10018eba;
  (**(code **)(*in_ECX + 0x78))();
  pIVar3 = (ID3D11Texture2D *)in_ECX[0x11];
  memset(local_c8,0,0xb4);
  piVar6 = in_ECX + 0x14;
  piVar7 = aiStack_164;
  for (iVar5 = 0x1f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar7 = *piVar6;
    piVar6 = piVar6 + 1;
    piVar7 = piVar7 + 1;
  }
  Texture::ChunkedTexture::ChunkedTexture(local_c8,in_ECX[0x33]);
  piStack_100 = (int *)0x10018f49;
  Texture::ChunkedTexture::updateRealTexture(local_c8,pIVar3,0,0,iVar1,iVar2);
  piVar6 = *(int **)(*piVar4 + 4);
  if (in_ECX[0x11] != 0) {
    piVar7 = (int *)in_ECX[0x12];
    if (piVar7 != (int *)0x0) {
      in_ECX[0x12] = 0;
      (**(code **)(*piVar7 + 8))();
    }
    (**(code **)(*piVar6 + 0x1c))();
    FUN_10005440();
    piStack_100 = *(int **)(*piVar4 + 8);
    uStack_104 = 0x10018fa6;
    (**(code **)(*piStack_100 + 0xd8))();
  }
LAB_10018eba:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

