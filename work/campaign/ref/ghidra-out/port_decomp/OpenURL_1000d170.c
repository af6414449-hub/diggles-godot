
/* public: long __thiscall CPlayer::OpenURL(wchar_t const *) */

long __thiscall CPlayer::OpenURL(CPlayer *this,wchar_t *param_1)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  long extraout_EAX;
  int *piVar4;
  int *local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0xd170  212  ?OpenURL@CPlayer@@QAEJPB_W@Z */
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  piVar4 = (int *)0x0;
  local_1c = (int *)0x0;
  local_14 = (int *)0x0;
  lVar1 = CreateSession(this);
  if (-1 < lVar1) {
    local_c = 2;
    local_10 = (int *)0x0;
    local_18 = (int *)0x0;
    iVar2 = MFCreateSourceResolver(&local_10);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*local_10 + 0xc))(local_10,param_1,1,0,&local_c,&local_18);
      if (-1 < iVar2) {
        iVar2 = (**(code **)*local_18)(local_18,&DAT_100450b8,this + 0xc);
      }
    }
    if (local_10 != (int *)0x0) {
      (**(code **)(*local_10 + 8))(local_10);
      local_10 = (int *)0x0;
    }
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
    if (-1 < iVar2) {
      iVar2 = (**(code **)(**(int **)(this + 0xc) + 0x20))(*(int **)(this + 0xc),&local_14);
      if (-1 < iVar2) {
        iVar2 = FUN_1000dbc0(*(undefined4 *)(this + 0x14),&local_1c);
        piVar4 = local_1c;
        if (-1 < iVar2) {
          iVar2 = (**(code **)(**(int **)(this + 8) + 0x1c))(*(int **)(this + 8),0,local_1c);
          if (-1 < iVar2) {
            uVar3 = 2;
            goto LAB_1000d268;
          }
        }
      }
    }
  }
  uVar3 = 0;
LAB_1000d268:
  *(undefined4 *)(this + 0x1c) = uVar3;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
    local_14 = (int *)0x0;
  }
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return extraout_EAX;
}

