
/* Library Function - Single Match
    char * __cdecl common_fgets<char>(char * const,int,class __crt_stdio_stream)
   
   Library: Visual Studio 2019 Release */

char * __cdecl common_fgets<char>(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  int unaff_EBP;
  char *pcVar6;
  
  FUN_006cf3b0(&DAT_00763300,0x18);
  iVar1 = *(int *)(unaff_EBP + 0xc);
  if ((((*(int *)(unaff_EBP + 8) == 0) && (iVar1 != 0)) || (iVar1 < 0)) ||
     (*(int *)(unaff_EBP + 0x10) == 0)) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_006e510d();
  }
  else if (iVar1 != 0) {
    pcVar4 = (char *)0x0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    __lock_file(*(FILE **)(unaff_EBP + 0x10));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    bVar2 = __acrt_stdio_char_traits<char>::validate_stream_is_ansi_if_required
                      (*(_iobuf **)(unaff_EBP + 0x10));
    if (bVar2) {
      pcVar6 = *(char **)(unaff_EBP + 8);
      *(char **)(unaff_EBP + -0x24) = pcVar6;
      iVar5 = 1;
      while (*(int *)(unaff_EBP + -0x1c) = iVar5, iVar5 != iVar1) {
        iVar5 = FUN_006df7cb(*(undefined4 *)(unaff_EBP + 0x10));
        *(int *)(unaff_EBP + -0x28) = iVar5;
        if (iVar5 == -1) {
          if (pcVar6 == *(char **)(unaff_EBP + 8)) goto LAB_006d4c66;
          break;
        }
        *pcVar6 = (char)iVar5;
        pcVar6 = pcVar6 + 1;
        *(char **)(unaff_EBP + -0x24) = pcVar6;
        if ((char)iVar5 == '\n') break;
        iVar5 = *(int *)(unaff_EBP + -0x1c) + 1;
      }
      *pcVar6 = '\0';
      pcVar4 = *(char **)(unaff_EBP + 8);
      *(char **)(unaff_EBP + -0x20) = pcVar4;
    }
LAB_006d4c66:
    *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
    FUN_006d4c97();
    goto LAB_006d4c74;
  }
  pcVar4 = (char *)0x0;
LAB_006d4c74:
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return pcVar4;
}

