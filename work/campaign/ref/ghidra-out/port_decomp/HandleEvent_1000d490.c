
/* public: long __thiscall CPlayer::HandleEvent(unsigned int) */

long __thiscall CPlayer::HandleEvent(CPlayer *this,uint param_1)

{
  long extraout_EAX;
  int iVar1;
  long extraout_EAX_00;
  int local_10;
  int local_c;
  uint local_8;
  
                    /* 0xd490  179  ?HandleEvent@CPlayer@@QAEJI@Z */
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  local_c = 0;
  local_10 = 0;
  if (param_1 != 0) {
    iVar1 = (**(code **)(*(int *)param_1 + 0x84))(param_1,&local_10);
    if (((-1 < iVar1) &&
        (iVar1 = (**(code **)(*(int *)param_1 + 0x8c))(param_1,&local_c), -1 < iVar1)) &&
       (-1 < local_c)) {
      iVar1 = *(int *)this;
      if (local_10 == 0x6f) {
        (**(code **)(iVar1 + 0x18))(param_1);
      }
      else if (local_10 == 0x71) {
        (**(code **)(iVar1 + 0x20))(param_1);
      }
      else if (local_10 == 0xd3) {
        (**(code **)(iVar1 + 0x1c))(param_1);
      }
      else {
        (**(code **)(iVar1 + 0x24))(param_1,local_10);
      }
    }
    (**(code **)(*(int *)param_1 + 8))(param_1);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return extraout_EAX_00;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return extraout_EAX;
}

