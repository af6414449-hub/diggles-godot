
/* public: virtual long __stdcall CPlayer::Invoke(struct IMFAsyncResult *) */

long CPlayer::Invoke(IMFAsyncResult *param_1)

{
  int iVar1;
  long extraout_EAX;
  int **ppiVar2;
  int *local_10;
  int local_c;
  uint local_8;
  
                    /* 0xd3d0  188  ?Invoke@CPlayer@@UAGJPAUIMFAsyncResult@@@Z */
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  ppiVar2 = &local_10;
  local_c = 0;
  local_10 = (int *)0x0;
  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x14))(*(int **)(param_1 + 8));
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_10 + 0x84))(local_10,&local_c);
    if (-1 < iVar1) {
      if (local_c == 0x6a) {
        SetEvent(*(HANDLE *)(param_1 + 0x20));
      }
      else {
        iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))(*(int **)(param_1 + 8),param_1,0);
        if (iVar1 < 0) goto LAB_1000d46a;
      }
      if (*(int *)(param_1 + 0x1c) != 6) {
        (**(code **)(*local_10 + 4))(local_10);
        PostMessageW(*(HWND *)(param_1 + 0x18),0x8001,(WPARAM)local_10,local_c);
      }
    }
  }
LAB_1000d46a:
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10,ppiVar2);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return extraout_EAX;
}

