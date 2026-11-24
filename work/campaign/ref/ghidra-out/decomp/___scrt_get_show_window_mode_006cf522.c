
/* Library Function - Single Match
    ___scrt_get_show_window_mode
   
   Library: Visual Studio 2019 Release */

WORD ___scrt_get_show_window_mode(void)

{
  _STARTUPINFOW local_48;
  
  _memset(&local_48,0,0x44);
  GetStartupInfoW(&local_48);
  if (((byte)local_48.dwFlags & 1) != 0) {
    return local_48.wShowWindow;
  }
  return 10;
}

