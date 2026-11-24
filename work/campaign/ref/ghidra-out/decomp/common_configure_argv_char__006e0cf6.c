
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    int __cdecl common_configure_argv<char>(enum _crt_argv_mode)
   
   Library: Visual Studio 2019 Release */

int __cdecl common_configure_argv<char>(_crt_argv_mode param_1)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  char **ppcVar4;
  char **ppcVar5;
  char *local_14;
  uint local_10;
  char **local_c;
  uint local_8;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else if ((param_1 == 2) || (param_1 == 1)) {
    ___acrt_initialize_multibyte();
    iVar2 = 0;
    ___acrt_GetModuleFileNameA(0,&DAT_00769c18,0x104);
    _DAT_0076a1f8 = &DAT_00769c18;
    local_14 = DAT_0076a208;
    if ((DAT_0076a208 == (char *)0x0) || (*DAT_0076a208 == '\0')) {
      local_14 = &DAT_00769c18;
    }
    local_8 = 0;
    local_10 = 0;
    parse_command_line<char>(local_14,(char **)0x0,(char *)0x0,&local_8,&local_10);
    ppcVar4 = (char **)___acrt_allocate_buffer_for_argv(local_8,local_10,1);
    ppcVar5 = ppcVar4;
    if (ppcVar4 == (char **)0x0) {
      piVar3 = __errno();
      iVar2 = 0xc;
      *piVar3 = 0xc;
    }
    else {
      parse_command_line<char>(local_14,ppcVar4,(char *)(ppcVar4 + local_8),&local_8,&local_10);
      if (param_1 == 1) {
        _DAT_0076a1fc = local_8 - 1;
        ppcVar5 = (char **)0x0;
        _DAT_0076a200 = ppcVar4;
      }
      else {
        local_c = (char **)0x0;
        iVar2 = FUN_006ec6f3(ppcVar4,&local_c);
        ppcVar4 = local_c;
        if (iVar2 == 0) {
          _DAT_0076a1fc = 0;
          pcVar1 = *local_c;
          while (pcVar1 != (char *)0x0) {
            local_c = local_c + 1;
            _DAT_0076a1fc = _DAT_0076a1fc + 1;
            pcVar1 = *local_c;
          }
          local_c = (char **)0x0;
          iVar2 = 0;
          _DAT_0076a200 = ppcVar4;
        }
        FID_conflict__free(local_c);
        local_c = (char **)0x0;
      }
    }
    FID_conflict__free(ppcVar5);
  }
  else {
    piVar3 = __errno();
    iVar2 = 0x16;
    *piVar3 = 0x16;
    FUN_006e510d();
  }
  return iVar2;
}

