
/* Library Function - Single Match
    bool __cdecl common_fseek_binary_mode_read_only_fast_track_nolock(class
   __crt_stdio_stream,__int64,int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

bool __cdecl
common_fseek_binary_mode_read_only_fast_track_nolock
          (int *param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  int unaff_EDI;
  longlong lVar4;
  
  if ((((param_4 != 2) && ((param_1[3] & 0x4c0U) != 0)) && ((param_1[3] & 6U) == 0)) &&
     (0 < param_1[2])) {
    uVar3 = param_1[4];
    iVar1 = (uVar3 & 0x3f) * 0x38;
    if (((-1 < *(char *)((&DAT_00769d80)[(int)uVar3 >> 6] + 0x28 + iVar1)) &&
        (*(char *)((&DAT_00769d80)[(int)uVar3 >> 6] + 0x29 + iVar1) == '\0')) &&
       ((param_4 != 0 ||
        ((lVar4 = __lseeki64_nolock(uVar3,0x100000000,unaff_EDI), -1 < lVar4 &&
         (lVar2 = LongLongSub(CONCAT44(param_3,param_2),lVar4 - param_1[2],(__int64 *)&param_2),
         -1 < lVar2)))))) {
      uVar3 = param_1[1] - *param_1;
      iVar1 = (int)uVar3 >> 0x1f;
      if ((iVar1 <= param_3) && ((iVar1 < param_3 || (uVar3 <= param_2)))) {
        iVar1 = param_1[2] >> 0x1f;
        if ((param_3 <= iVar1) && ((param_3 < iVar1 || (param_2 <= (uint)param_1[2])))) {
          *param_1 = *param_1 + param_2;
          param_1[2] = param_1[2] - param_2;
          return true;
        }
      }
    }
  }
  return false;
}

