
/* Library Function - Single Match
    void __cdecl __scrt_uninitialize_type_info(void)
   
   Library: Visual Studio 2019 Release */

void __cdecl __scrt_uninitialize_type_info(void)

{
  __std_type_info_destroy_list(&DAT_10050c10);
  return;
}

