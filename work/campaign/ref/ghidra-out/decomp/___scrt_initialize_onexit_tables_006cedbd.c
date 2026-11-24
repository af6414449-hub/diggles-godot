
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___scrt_initialize_onexit_tables
   
   Library: Visual Studio 2019 Release */

undefined4 ___scrt_initialize_onexit_tables(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00769741 != '\0') {
    return 1;
  }
  if ((param_1 != 0) && (param_1 != 1)) {
    ___scrt_fastfail(5);
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  iVar2 = ___scrt_is_ucrt_dll_in_use();
  if ((iVar2 == 0) || (param_1 != 0)) {
    DAT_00769744 = 0xffffffff;
    _DAT_00769748 = 0xffffffff;
    _DAT_0076974c = 0xffffffff;
    _DAT_00769750 = 0xffffffff;
    _DAT_00769754 = 0xffffffff;
    _DAT_00769758 = 0xffffffff;
LAB_006cee30:
    DAT_00769741 = '\x01';
    uVar3 = 1;
  }
  else {
    iVar2 = __initialize_onexit_table(&DAT_00769744);
    if (iVar2 == 0) {
      iVar2 = __initialize_onexit_table(&DAT_00769750);
      if (iVar2 == 0) goto LAB_006cee30;
    }
    uVar3 = 0;
  }
  return uVar3;
}

