
/* Library Function - Single Match
    _ValidateLocalCookies
   
   Library: Visual Studio 2019 Release */

void _ValidateLocalCookies(int *param_1,int param_2)

{
  if (*param_1 != -2) {
    __security_check_cookie(param_1[1] + param_2 ^ *(uint *)(*param_1 + param_2));
  }
  __security_check_cookie(param_1[3] + param_2 ^ *(uint *)(param_1[2] + param_2));
  return;
}

