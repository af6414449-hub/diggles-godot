
/* protected: virtual long __thiscall CPlayer::OnTopologyStatus(struct IMFMediaEvent *) */

long __thiscall CPlayer::OnTopologyStatus(CPlayer *this,IMFMediaEvent *param_1)

{
  int *piVar1;
  int iVar2;
  long extraout_EAX;
  int local_c;
  uint local_8;
  
                    /* 0xd5a0  209  ?OnTopologyStatus@CPlayer@@MAEJPAUIMFMediaEvent@@@Z */
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar2 = (**(code **)(*(int *)param_1 + 0x1c))(param_1,&DAT_10043490,&local_c);
  if ((-1 < iVar2) && (local_c == 100)) {
    piVar1 = *(int **)(this + 0x10);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(this + 0x10) = 0;
    }
    MFGetService(*(undefined4 *)(this + 8),&DAT_100434c0,&DAT_1004500c,this + 0x10);
    StartPlayback(this);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return extraout_EAX;
}

