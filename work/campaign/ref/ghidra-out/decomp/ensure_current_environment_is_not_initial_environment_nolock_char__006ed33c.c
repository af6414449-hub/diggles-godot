
/* Library Function - Single Match
    void __cdecl ensure_current_environment_is_not_initial_environment_nolock<char>(void)
   
   Library: Visual Studio 2019 Release */

void __cdecl ensure_current_environment_is_not_initial_environment_nolock<char>(void)

{
  if (DAT_00769d20 == DAT_00769d2c) {
    DAT_00769d20 = copy_environment<char>(DAT_00769d20);
  }
  return;
}

