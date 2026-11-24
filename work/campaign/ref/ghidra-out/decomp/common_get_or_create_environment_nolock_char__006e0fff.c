
/* Library Function - Single Match
    char * * __cdecl common_get_or_create_environment_nolock<char>(void)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

char ** __cdecl common_get_or_create_environment_nolock<char>(void)

{
  int iVar1;
  char **ppcVar2;
  
  ppcVar2 = DAT_00769d20;
  if (DAT_00769d20 == (char **)0x0) {
    if (DAT_00769d24 != 0) {
      iVar1 = common_initialize_environment_nolock<char>();
      if (iVar1 == 0) {
        return DAT_00769d20;
      }
      iVar1 = initialize_environment_by_cloning_nolock<char>();
      if (iVar1 == 0) {
        return DAT_00769d20;
      }
    }
    ppcVar2 = (char **)0x0;
  }
  return ppcVar2;
}

