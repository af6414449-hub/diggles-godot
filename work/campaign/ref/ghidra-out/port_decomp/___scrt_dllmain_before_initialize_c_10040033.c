
/* Library Function - Single Match
    ___scrt_dllmain_before_initialize_c
   
   Library: Visual Studio 2019 Release */

bool ___scrt_dllmain_before_initialize_c(void)

{
  char cVar1;
  
  cVar1 = ___scrt_initialize_onexit_tables(0);
  return cVar1 != '\0';
}

