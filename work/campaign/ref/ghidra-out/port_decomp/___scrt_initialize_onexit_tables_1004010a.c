
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___scrt_initialize_onexit_tables
   
   Library: Visual Studio 2019 Release */

undefined4 ___scrt_initialize_onexit_tables(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_100508c1 != '\0') {
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
    DAT_100508c4 = 0xffffffff;
    _DAT_100508c8 = 0xffffffff;
    _DAT_100508cc = 0xffffffff;
    _DAT_100508d0 = 0xffffffff;
    _DAT_100508d4 = 0xffffffff;
    _DAT_100508d8 = 0xffffffff;
LAB_1004017d:
    DAT_100508c1 = '\x01';
    uVar3 = 1;
  }
  else {
    iVar2 = initialize_onexit_table(&DAT_100508c4);
    if (iVar2 == 0) {
      iVar2 = initialize_onexit_table(&DAT_100508d0);
      if (iVar2 == 0) goto LAB_1004017d;
    }
    uVar3 = 0;
  }
  return uVar3;
}

