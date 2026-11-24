
/* Library Function - Single Match
    _fputs
   
   Library: Visual Studio 2019 Release */

int __cdecl _fputs(char *_Str,FILE *_File)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  undefined *puVar6;
  undefined *puVar7;
  FILE **local_20;
  char **local_1c;
  int *local_18;
  FILE *local_14;
  FILE *local_10;
  int local_c;
  __crt_seh_guarded_call<int> local_5;
  
  if ((_Str == (char *)0x0) || (_File == (FILE *)0x0)) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    return -1;
  }
  if (((uint)_File->_flag >> 0xc & 1) == 0) {
    uVar3 = __fileno(_File);
    puVar6 = &DAT_007672e0;
    if ((uVar3 == 0xffffffff) || (uVar3 == 0xfffffffe)) {
      puVar7 = &DAT_007672e0;
    }
    else {
      puVar7 = (undefined *)((uVar3 & 0x3f) * 0x38 + (&DAT_00769d80)[(int)uVar3 >> 6]);
    }
    if (puVar7[0x29] == '\0') {
      if ((uVar3 != 0xffffffff) && (uVar3 != 0xfffffffe)) {
        puVar6 = (undefined *)((uVar3 & 0x3f) * 0x38 + (&DAT_00769d80)[(int)uVar3 >> 6]);
      }
      if ((puVar6[0x2d] & 1) == 0) goto LAB_006dc31e;
    }
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    iVar4 = -1;
  }
  else {
LAB_006dc31e:
    pcVar5 = _Str;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    local_20 = &_File;
    local_c = (int)pcVar5 - (int)(_Str + 1);
    local_1c = &_Str;
    local_18 = &local_c;
    local_10 = _File;
    local_14 = _File;
    iVar4 = __crt_seh_guarded_call<int>::
            operator()<class_<lambda_65fd67b065f6eb2f69d2b40e70f741d1>,class_<lambda_0bd0bd1e46f8138169959d81163ebf0c>&,class_<lambda_3dd5c5b82bb549ede7d0dd5b9a094995>_>
                      (&local_5,(<lambda_65fd67b065f6eb2f69d2b40e70f741d1> *)&local_14,
                       (<lambda_0bd0bd1e46f8138169959d81163ebf0c> *)&local_20,
                       (<lambda_3dd5c5b82bb549ede7d0dd5b9a094995> *)&local_10);
  }
  return iVar4;
}

