
/* Library Function - Single Match
    int __cdecl common_expand_argv_wildcards<char>(char * * const,char * * * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl common_expand_argv_wildcards<char>(char **param_1,char ***param_2)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 *puVar4;
  char **ppcVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *_Memory;
  undefined4 *local_2c;
  undefined4 *local_28;
  undefined4 local_24;
  undefined4 *local_20;
  char **local_1c;
  char *local_18;
  char *local_14;
  char **local_10;
  undefined4 *local_c;
  undefined4 local_8;
  
  if (param_2 == (char ***)0x0) {
    piVar2 = __errno();
    puVar4 = (undefined4 *)0x16;
    *piVar2 = 0x16;
    FUN_006e510d();
  }
  else {
    pcVar8 = (char *)0x0;
    *param_2 = (char **)0x0;
    pcVar3 = *param_1;
    local_2c = (undefined4 *)0x0;
    local_28 = (undefined4 *)0x0;
    local_24 = 0;
    puVar10 = local_2c;
    while (local_2c = puVar10, pcVar3 != (char *)0x0) {
      uVar9 = (uint)local_8 >> 0x18;
      local_8 = (char *)CONCAT13((char)uVar9,0x3f2a);
      pcVar3 = _strpbrk(pcVar3,(char *)&local_8);
      if (pcVar3 == (char *)0x0) {
        puVar4 = (undefined4 *)
                 copy_and_add_argument_to_buffer<char>
                           (*param_1,(char *)0x0,0,(argument_list<char> *)&local_2c);
      }
      else {
        puVar4 = (undefined4 *)
                 expand_argument_wildcards<char>(*param_1,pcVar3,(argument_list<char> *)&local_2c);
      }
      puVar10 = local_2c;
      local_c = puVar4;
      if (puVar4 != (undefined4 *)0x0) goto LAB_006ec315;
      param_1 = param_1 + 1;
      local_c = (undefined4 *)0x0;
      pcVar3 = *param_1;
    }
    local_8 = (char *)0x0;
    local_10 = (char **)(((int)local_28 - (int)puVar10 >> 2) + 1);
    uVar9 = ~-(uint)(local_28 < puVar10) & ((int)local_28 - (int)puVar10) + 3U >> 2;
    local_c = puVar10;
    if (uVar9 != 0) {
      uVar7 = 0;
      do {
        pcVar3 = (char *)*local_c;
        local_14 = pcVar3 + 1;
        do {
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        pcVar8 = pcVar3 + (int)(pcVar8 + (1 - (int)local_14));
        local_c = local_c + 1;
        uVar7 = uVar7 + 1;
        local_8 = pcVar8;
      } while (uVar7 != uVar9);
    }
    ppcVar5 = (char **)___acrt_allocate_buffer_for_argv(local_10,local_8,1);
    if (ppcVar5 == (char **)0x0) {
      puVar4 = (undefined4 *)0xffffffff;
      local_c = (undefined4 *)0xffffffff;
    }
    else {
      local_10 = ppcVar5 + (int)local_10;
      local_1c = local_10;
      if (puVar10 != local_28) {
        local_20 = (undefined4 *)((int)ppcVar5 - (int)puVar10);
        local_c = puVar10;
        do {
          local_18 = (char *)*local_c;
          local_14 = local_18;
          do {
            cVar1 = *local_14;
            local_14 = local_14 + 1;
          } while (cVar1 != '\0');
          local_14 = local_14 + (1 - (int)(local_18 + 1));
          iVar6 = FUN_006e9950(local_10,(char *)((int)local_1c + ((int)local_8 - (int)local_10)),
                               local_18,local_14);
          if (iVar6 != 0) {
                    /* WARNING: Subroutine does not return */
            __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
          *(char ***)((int)local_20 + (int)local_c) = local_10;
          local_c = local_c + 1;
          local_10 = (char **)((int)local_10 + (int)local_14);
        } while (local_c != local_28);
      }
      local_c = (undefined4 *)0x0;
      *param_2 = ppcVar5;
      puVar4 = (undefined4 *)0x0;
    }
    FID_conflict__free((void *)0x0);
LAB_006ec315:
    uVar7 = 0;
    uVar9 = ~-(uint)(local_28 < puVar10) & (uint)((int)local_28 + (3 - (int)puVar10)) >> 2;
    _Memory = puVar10;
    local_20 = puVar10;
    local_1c = (char **)uVar9;
    if (uVar9 != 0) {
      do {
        FID_conflict__free((void *)*puVar10);
        uVar7 = uVar7 + 1;
        puVar10 = puVar10 + 1;
        puVar4 = local_c;
        _Memory = local_2c;
      } while (uVar7 != uVar9);
    }
    FID_conflict__free(_Memory);
  }
  return (int)puVar4;
}

