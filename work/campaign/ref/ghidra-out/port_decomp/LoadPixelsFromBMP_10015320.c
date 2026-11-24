
/* int __cdecl Texture::LoadPixelsFromBMP(wchar_t const *,void * *,int &,int &,int &) */

int __cdecl
Texture::LoadPixelsFromBMP(wchar_t *param_1,void **param_2,int *param_3,int *param_4,int *param_5)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  HANDLE hFile;
  int extraout_EAX;
  DWORD DVar4;
  void *lpBuffer;
  void *_Dst;
  int extraout_EAX_00;
  uint uVar5;
  size_t _Size;
  double dVar6;
  int local_28;
  DWORD local_c;
  uint local_8;
  
                    /* 0x15320  202  ?LoadPixelsFromBMP@Texture@@YAHPB_WPAPAXAAH22@Z */
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  hFile = CreateFileW(param_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return extraout_EAX;
  }
  DVar4 = GetFileSize(hFile,(LPDWORD)0x0);
  lpBuffer = (void *)FUN_100402f0(DVar4 - 0xe);
  SetFilePointer(hFile,0xe,(PLONG)0x0,0);
  ReadFile(hFile,lpBuffer,DVar4 - 0xe,&local_c,(LPOVERLAPPED)0x0);
  CloseHandle(hFile);
  local_28 = 0;
  iVar2 = *(int *)((int)lpBuffer + 4);
  iVar3 = *(int *)((int)lpBuffer + 8);
  uVar1 = *(undefined8 *)((int)lpBuffer + 0x20);
  uVar5 = *(uint *)((int)lpBuffer + 0xc) >> 0x10;
  *param_5 = uVar5;
  switch(uVar5) {
  case 1:
  case 4:
  case 8:
    dVar6 = 2.0;
    libm_sse2_pow_precise();
    local_28 = (int)dVar6;
    break;
  case 0x10:
  case 0x18:
  case 0x20:
    local_28 = (int)uVar1;
  }
  *param_3 = iVar2;
  *param_4 = iVar3;
  _Size = (DVar4 + local_28 * -4) - 0x36;
  _Dst = (void *)FUN_100402f0(_Size);
  *param_2 = _Dst;
  memcpy(_Dst,(void *)((int)lpBuffer + local_28 * 4 + 0x28),_Size);
  free(lpBuffer);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return extraout_EAX_00;
}

