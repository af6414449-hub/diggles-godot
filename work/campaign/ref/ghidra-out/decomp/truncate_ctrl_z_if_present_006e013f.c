
/* Library Function - Single Match
    int __cdecl truncate_ctrl_z_if_present(int)
   
   Library: Visual Studio 2019 Release */

int __cdecl truncate_ctrl_z_if_present(int param_1)

{
  byte bVar1;
  ulong *puVar2;
  int *piVar3;
  int iVar4;
  int unaff_EDI;
  longlong lVar5;
  uint local_8;
  
  bVar1 = *(byte *)((&DAT_00769d80)[param_1 >> 6] + 0x28 + (param_1 & 0x3fU) * 0x38);
  if (((bVar1 & 0x48) == 0) && ((char)bVar1 < '\0')) {
    lVar5 = __lseeki64_nolock(param_1,0x2ffffffff,unaff_EDI);
    if (lVar5 == -1) {
      puVar2 = ___doserrno();
      if (*puVar2 == 0x83) goto LAB_006e01e2;
    }
    else {
      local_8 = local_8 & 0xffff0000;
      iVar4 = __read_nolock(param_1,&local_8,1);
      if ((iVar4 == 0) && ((short)local_8 == 0x1a)) {
        iVar4 = __chsize_nolock(param_1,CONCAT44(unaff_EDI,(int)((ulonglong)lVar5 >> 0x20)));
        if (iVar4 == -1) goto LAB_006e0194;
      }
      lVar5 = __lseeki64_nolock(param_1,0,unaff_EDI);
      if (lVar5 != -1) goto LAB_006e01e2;
    }
LAB_006e0194:
    piVar3 = __errno();
    iVar4 = *piVar3;
  }
  else {
LAB_006e01e2:
    iVar4 = 0;
  }
  return iVar4;
}

