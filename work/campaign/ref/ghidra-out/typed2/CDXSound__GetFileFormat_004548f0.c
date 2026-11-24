
void __thiscall CDXSound__GetFileFormat(CDXSound *this)

{
  undefined4 uVar1;
  int iVar2;
  HMMIO hmmio;
  MMRESULT MVar3;
  LONG LVar4;
  int iVar5;
  undefined8 uVar6;
  LPSTR in_stack_00000004;
  undefined4 in_stack_00000008;
  undefined4 *in_stack_0000000c;
  uint *in_stack_00000010;
  uint *in_stack_00000014;
  int *in_stack_00000018;
  undefined1 auStack_5c [4];
  int *local_58;
  undefined4 local_54;
  undefined4 *local_50;
  uint *local_4c;
  uint *local_48;
  _MMCKINFO _Stack_44;
  char acStack_30 [2];
  short sStack_2e;
  undefined4 uStack_2c;
  ushort uStack_24;
  ushort uStack_22;
  _MMCKINFO _Stack_20;
  uint local_c;
  
  local_c = DAT_0076700c ^ (uint)auStack_5c;
  local_54 = in_stack_00000008;
  local_50 = in_stack_0000000c;
  local_4c = in_stack_00000010;
  local_48 = in_stack_00000014;
  local_58 = in_stack_00000018;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c86bd8) &&
     (FUN_006cebf4(&DAT_00c86bd8), iVar2 = DAT_00783650, DAT_00c86bd8 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00c86bdc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "CDXSound::GetFileFormat()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00c86bd8);
  }
  iVar5 = DAT_00c86bdc;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00c86bdc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar6 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  hmmio = mmioOpenA(in_stack_00000004,(LPMMIOINFO)0x0,0x10000);
  if (hmmio != (HMMIO)0x0) {
    MVar3 = mmioDescend(hmmio,&_Stack_20,(MMCKINFO *)0x0,0);
    if (MVar3 == 0) {
      _Stack_44.ckid = 0x20746d66;
      MVar3 = mmioDescend(hmmio,&_Stack_44,&_Stack_20,0x10);
      if (((MVar3 == 0) && (0xf < _Stack_44.cksize)) &&
         (LVar4 = mmioRead(hmmio,acStack_30,0x10), LVar4 == 0x10)) {
        _Stack_44.ckid = 0x61746164;
        mmioAscend(hmmio,&_Stack_44,0);
        mmioDescend(hmmio,&_Stack_44,&_Stack_20,0x10);
        LVar4 = mmioSeek(hmmio,0,1);
        *local_58 = LVar4;
        mmioAscend(hmmio,&_Stack_44,0);
        mmioDescend(hmmio,&_Stack_44,&_Stack_20,0x10);
        LVar4 = mmioSeek(hmmio,0,1);
        *(bool *)local_54 = sStack_2e == 2;
        *local_50 = uStack_2c;
        *local_4c = (uint)uStack_22;
        *local_48 = (uint)(LVar4 - *local_58) / (uint)uStack_24;
      }
    }
    mmioClose(hmmio,0);
  }
  FUN_0043fd30();
  __security_check_cookie(local_c ^ (uint)auStack_5c);
  return;
}

