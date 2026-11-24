
/* public: bool __thiscall SoloudAudioPlayer::OpenFile(char const *) */

HFILE SoloudAudioPlayer::OpenFile(LPCSTR lpFileName,LPOFSTRUCT lpReOpenBuff,UINT uStyle)

{
  char cVar1;
  undefined **ppuVar2;
  undefined4 *_Dst;
  void *_Dst_00;
  int iVar3;
  HFILE extraout_EAX;
  int in_ECX;
  undefined4 in_EDX;
  LPCSTR pCVar4;
  size_t _Size;
  undefined **local_1c;
  FILE *pFStack_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x14740  211  ?OpenFile@SoloudAudioPlayer@@QAE_NPBD@Z */
  local_8 = 0xffffffff;
  puStack_c = &LAB_100427ad;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  _Dst = (undefined4 *)FUN_1003ff62(0x80);
  _local_1c = CONCAT44(_Dst,local_1c);
  memset(_Dst,0,0x80);
  _Dst[0xc] = 0;
  _Dst[0xd] = 0;
  _Dst[0xe] = 0;
  _Dst[0xf] = 0;
  _Dst[0x10] = 0;
  _Dst[0x11] = 0;
  _Dst[0x12] = 0;
  _Dst[0x13] = 0;
  _Dst[2] = 0;
  _Dst[3] = 0x472c4400;
  _Dst[6] = 0;
  _Dst[0x14] = 0;
  _Dst[5] = 1;
  _Dst[7] = 0x3f800000;
  _Dst[8] = 0x49742400;
  _Dst[9] = 0x3f800000;
  _Dst[10] = 0;
  _Dst[0xb] = 0x3f800000;
  _Dst[0x15] = 0;
  _Dst[0x16] = 0;
  _Dst[0x17] = 0;
  _Dst[4] = 0x3f800000;
  *(undefined8 *)(_Dst + 0x18) = 0;
  *_Dst = SoLoud::WavStream::vftable;
  _Dst[0x1b] = 0;
  _Dst[0x1e] = 0;
  _Dst[0x1a] = 0;
  _Dst[0x1c] = 0;
  _Dst[0x1d] = 0;
  *(undefined4 **)(in_ECX + 4) = _Dst;
  free((void *)_Dst[0x1b]);
  if ((undefined4 *)_Dst[0x1c] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)_Dst[0x1c])(1);
  }
  _Dst[0x1c] = 0;
  _Dst[0x1b] = 0;
  _Dst[0x1e] = 0;
  local_1c = SoLoud::DiskFile::vftable;
  ppuVar2 = local_1c;
  local_1c = SoLoud::DiskFile::vftable;
  pFStack_18 = (FILE *)0x0;
  local_8 = 0;
  if ((lpFileName != (LPCSTR)0x0) &&
     (pFStack_18 = fopen(lpFileName,"rb"), ppuVar2 = local_1c, pFStack_18 != (FILE *)0x0)) {
    pCVar4 = lpFileName;
    do {
      cVar1 = *pCVar4;
      pCVar4 = pCVar4 + 1;
    } while (cVar1 != '\0');
    _Size = (int)pCVar4 - (int)(lpFileName + 1);
    _Dst_00 = (void *)FUN_100402f0(_Size + 1);
    _Dst[0x1b] = _Dst_00;
    memcpy(_Dst_00,lpFileName,_Size);
    *(undefined1 *)(_Size + _Dst[0x1b]) = 0;
    iVar3 = FUN_1001fb90(&local_1c);
    if (iVar3 == 0) {
      local_1c = SoLoud::DiskFile::vftable;
      ppuVar2 = local_1c;
      if (pFStack_18 != (FILE *)0x0) {
        fclose(pFStack_18);
        ppuVar2 = local_1c;
      }
    }
    else {
      free((void *)_Dst[0x1b]);
      _Dst[0x1b] = 0;
      local_1c = SoLoud::DiskFile::vftable;
      ppuVar2 = local_1c;
      if (pFStack_18 != (FILE *)0x0) {
        fclose(pFStack_18);
        ppuVar2 = local_1c;
      }
    }
  }
  local_1c = ppuVar2;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return extraout_EAX;
}

