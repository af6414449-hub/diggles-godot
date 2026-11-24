
/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_0076700c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}

