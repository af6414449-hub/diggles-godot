
/* Library Function - Single Match
    int __cdecl compute_iso_year(int,int,int)
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl compute_iso_year(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = compute_iso_week_internal(param_1,param_2,param_3);
  if (iVar1 == 0) {
    param_1 = param_1 + -1;
  }
  else if (iVar1 < 1) {
    param_1 = param_1 + 1;
  }
  return param_1;
}

