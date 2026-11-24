
void FUN_10038ec0(void)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int in_ECX;
  char local_b;
  char local_a;
  char local_9;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  iVar4 = *(int *)(in_ECX + 0x570);
  while( true ) {
    if (iVar4 != -1) {
      *(undefined4 *)(in_ECX + 0x574) = 0;
      *(undefined4 *)(in_ECX + 0x580) = 0;
      *(undefined4 *)(in_ECX + 0x584) = 0;
      *(undefined1 *)(in_ECX + 0x56c) = 0;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    pcVar1 = *(char **)(in_ECX + 0x2c);
    if (pcVar1 == (char *)0x0) break;
    if (*(char **)(in_ECX + 0x34) <= pcVar1) goto LAB_10039044;
    cVar3 = *pcVar1;
    *(char **)(in_ECX + 0x2c) = pcVar1 + 1;
LAB_10038f2e:
    if (cVar3 != 'O') goto LAB_1003904b;
    pcVar1 = *(char **)(in_ECX + 0x2c);
    if (pcVar1 == (char *)0x0) {
      piVar2 = *(int **)(in_ECX + 0x20);
      iVar4 = (**(code **)(*piVar2 + 4))();
      if (iVar4 == 0) {
        local_a = '\0';
        (**(code **)(*piVar2 + 8))(&local_a,1);
        cVar3 = local_a;
        goto LAB_10038f75;
      }
      goto LAB_10039044;
    }
    if (*(char **)(in_ECX + 0x34) <= pcVar1) goto LAB_10039044;
    cVar3 = *pcVar1;
    *(char **)(in_ECX + 0x2c) = pcVar1 + 1;
LAB_10038f75:
    if (cVar3 != 'g') goto LAB_1003904b;
    pcVar1 = *(char **)(in_ECX + 0x2c);
    if (pcVar1 == (char *)0x0) {
      piVar2 = *(int **)(in_ECX + 0x20);
      iVar4 = (**(code **)(*piVar2 + 4))();
      if (iVar4 != 0) goto LAB_10039044;
      local_b = '\0';
      (**(code **)(*piVar2 + 8))(&local_b,1);
      cVar3 = local_b;
    }
    else {
      if (*(char **)(in_ECX + 0x34) <= pcVar1) goto LAB_10039044;
      cVar3 = *pcVar1;
      *(char **)(in_ECX + 0x2c) = pcVar1 + 1;
    }
    if ((cVar3 != 'g') || (cVar3 = FUN_10038a40(), cVar3 != 'S')) goto LAB_1003904b;
    iVar4 = FUN_10038c50();
    if (iVar4 == 0) goto LAB_10039052;
    if ((*(byte *)(in_ECX + 0x56b) & 1) != 0) {
      *(undefined4 *)(in_ECX + 0x70) = 0x20;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    iVar4 = *(int *)(in_ECX + 0x570);
  }
  piVar2 = *(int **)(in_ECX + 0x20);
  iVar4 = (**(code **)(*piVar2 + 4))();
  if (iVar4 == 0) {
    local_9 = '\0';
    (**(code **)(*piVar2 + 8))(&local_9,1);
    cVar3 = local_9;
    goto LAB_10038f2e;
  }
LAB_10039044:
  *(undefined4 *)(in_ECX + 0x6c) = 1;
LAB_1003904b:
  *(undefined4 *)(in_ECX + 0x70) = 0x1e;
LAB_10039052:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

