
/* protected: long __thiscall CPlayer::CloseSession(void) */

long __thiscall CPlayer::CloseSession(CPlayer *this)

{
  int *piVar1;
  DWORD DVar2;
  int iVar3;
  
                    /* 0xd780  108  ?CloseSession@CPlayer@@IAEJXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  piVar1 = *(int **)(this + 0x10);
  iVar3 = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(this + 0x10) = 0;
  }
  piVar1 = *(int **)(this + 8);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(this + 0x1c) = 6;
    iVar3 = (**(code **)(*piVar1 + 0x30))(piVar1);
    if (iVar3 < 0) goto LAB_1000d801;
    DVar2 = WaitForSingleObject(*(HANDLE *)(this + 0x20),5000);
    if (DVar2 == 0x102) {
      _wassert(L"FALSE",L"C:\\dev\\wiggles\\port\\src\\PortVideoPlayer.cpp",0x223);
    }
  }
  piVar1 = *(int **)(this + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))(piVar1);
  }
  piVar1 = *(int **)(this + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x34))(piVar1);
  }
LAB_1000d801:
  piVar1 = *(int **)(this + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(this + 0xc) = 0;
  }
  piVar1 = *(int **)(this + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(this + 8) = 0;
  }
  *(undefined4 *)(this + 0x1c) = 0;
  return iVar3;
}

