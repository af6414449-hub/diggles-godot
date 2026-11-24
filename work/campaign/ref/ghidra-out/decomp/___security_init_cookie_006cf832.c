
/* Library Function - Single Match
    ___security_init_cookie
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___security_init_cookie(void)

{
  if ((DAT_0076700c == 0xbb40e64e) || ((DAT_0076700c & 0xffff0000) == 0)) {
    DAT_0076700c = ___get_entropy();
    if (DAT_0076700c == 0xbb40e64e) {
      DAT_0076700c = 0xbb40e64f;
    }
    else if ((DAT_0076700c & 0xffff0000) == 0) {
      DAT_0076700c = DAT_0076700c | (DAT_0076700c | 0x4711) << 0x10;
    }
  }
  DAT_00767008 = ~DAT_0076700c;
  return;
}

