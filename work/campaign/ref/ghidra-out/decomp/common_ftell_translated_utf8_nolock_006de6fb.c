
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* Library Function - Single Match
    __int64 __cdecl common_ftell_translated_utf8_nolock(class __crt_stdio_stream,__int64)
   
   Library: Visual Studio 2019 Release */

__int64 __cdecl common_ftell_translated_utf8_nolock(FILE *param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  BOOL BVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int unaff_EDI;
  int iVar7;
  bool bVar8;
  longlong lVar9;
  longlong lVar10;
  __int64 _Var11;
  uint local_1014;
  uint local_1010;
  undefined4 local_100c;
  byte local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  uVar1 = __fileno(param_1);
  if (param_1->_base != (char *)0x0) {
    iVar2 = (int)param_1->_ptr - param_1->_cnt;
    lVar9 = __alldiv(iVar2,iVar2 >> 0x1f,2,0);
    iVar5 = (int)((ulonglong)lVar9 >> 0x20);
    local_100c = (uint)lVar9;
    iVar7 = (uVar1 & 0x3f) * 0x38;
    lVar10 = __lseeki64(uVar1,(ulonglong)*(uint *)(iVar7 + 0x24 + (&DAT_00769d80)[(int)uVar1 >> 6]),
                        unaff_EDI);
    iVar6 = (int)((ulonglong)lVar10 >> 0x20);
    local_1010 = (uint)lVar10;
    iVar2 = (&DAT_00769d80)[(int)uVar1 >> 6];
    if (((((local_1010 == *(uint *)(iVar7 + 0x20 + iVar2)) &&
          (iVar6 == *(int *)(iVar7 + 0x24 + iVar2))) &&
         (BVar3 = ReadFile(*(HANDLE *)(iVar7 + 0x18 + iVar2),local_1008,0x1000,&local_1014,
                           (LPOVERLAPPED)0x0), BVar3 != 0)) &&
        ((lVar10 = __lseeki64(uVar1,(ulonglong)param_3,unaff_EDI), -1 < lVar10 &&
         (lVar9 < 0x100000000)))) && ((lVar9 < 0 || (local_100c <= local_1014)))) {
      iVar2 = 0;
      pbVar4 = local_1008;
      uVar1 = 0;
      if ((local_100c != 0) || (iVar5 != 0)) {
        do {
          if (local_1008 + local_1014 <= pbVar4) break;
          if (*pbVar4 == 0xd) {
            if ((pbVar4 < local_1008 + (local_1014 - 1)) && (pbVar4[1] == 10)) {
              pbVar4 = pbVar4 + 1;
            }
          }
          else {
            pbVar4 = pbVar4 + (char)(&DAT_00767110)[*pbVar4];
          }
          bVar8 = 0xfffffffe < uVar1;
          uVar1 = uVar1 + 1;
          iVar2 = iVar2 + (uint)bVar8;
          pbVar4 = pbVar4 + 1;
        } while ((uVar1 != local_100c) || (iVar2 != iVar5));
      }
      param_3 = ((int)pbVar4 - (int)local_1008 >> 0x1f) + iVar6 +
                (uint)CARRY4((int)pbVar4 - (int)local_1008,local_1010);
    }
    else {
      param_3 = 0xffffffff;
    }
  }
  _Var11 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,param_3);
  return _Var11;
}

