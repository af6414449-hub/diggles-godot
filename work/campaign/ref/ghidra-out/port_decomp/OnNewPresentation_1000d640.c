
/* protected: virtual long __thiscall CPlayer::OnNewPresentation(struct IMFMediaEvent *) */

long __thiscall CPlayer::OnNewPresentation(CPlayer *this,IMFMediaEvent *param_1)

{
  int *piVar1;
  int iVar2;
  long extraout_EAX;
  int *local_20;
  short local_1c [4];
  undefined4 *local_14;
  int *local_c;
  uint local_8;
  
                    /* 0xd640  206  ?OnNewPresentation@CPlayer@@MAEJPAUIMFMediaEvent@@@Z */
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  local_20 = (int *)0x0;
  local_c = (int *)0x0;
  iVar2 = (**(code **)(*(int *)param_1 + 0x90))(param_1,local_1c);
  if (-1 < iVar2) {
    if (local_1c[0] == 0xd) {
      iVar2 = (**(code **)*local_14)(local_14,&DAT_10045098,&local_c);
      PropVariantClear((PROPVARIANT *)local_1c);
      if (-1 < iVar2) {
        iVar2 = FUN_1000dbc0(*(undefined4 *)(this + 0x14),&local_20);
        piVar1 = local_20;
        if (-1 < iVar2) {
          iVar2 = (**(code **)(**(int **)(this + 8) + 0x1c))(*(int **)(this + 8),0,local_20);
          if (-1 < iVar2) {
            *(undefined4 *)(this + 0x1c) = 2;
          }
        }
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
        }
      }
    }
    else {
      PropVariantClear((PROPVARIANT *)local_1c);
    }
  }
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return extraout_EAX;
}

