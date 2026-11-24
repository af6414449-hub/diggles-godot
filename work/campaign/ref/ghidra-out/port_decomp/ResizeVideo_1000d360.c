
/* public: long __thiscall CPlayer::ResizeVideo(unsigned short,unsigned short) */

long __thiscall CPlayer::ResizeVideo(CPlayer *this,ushort param_1,ushort param_2)

{
  int *piVar1;
  long extraout_EAX;
  long extraout_EAX_00;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
                    /* 0xd360  225  ?ResizeVideo@CPlayer@@QAEJGG@Z */
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  piVar1 = *(int **)(this + 0x10);
  if (piVar1 != (int *)0x0) {
    local_10 = (uint)param_1;
    local_c = (uint)param_2;
    local_18 = 0;
    local_14 = 0;
    (**(code **)(*piVar1 + 0x14))(piVar1,0,&local_18);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return extraout_EAX;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return extraout_EAX_00;
}

