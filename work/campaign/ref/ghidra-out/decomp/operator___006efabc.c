
/* Library Function - Single Match
    public: unsigned int __thiscall <lambda_3d301b9e52f5099be73030e1f0bf487e>::operator()(char const
   *)const 
   
   Library: Visual Studio 2019 Release */

uint __thiscall
<lambda_3d301b9e52f5099be73030e1f0bf487e>::operator()
          (<lambda_3d301b9e52f5099be73030e1f0bf487e> *this,char *param_1)

{
  uint uVar1;
  
  if (*param_1 == '\0') {
    uVar1 = 1;
  }
  else if (param_1[1] == '\0') {
    uVar1 = 2;
  }
  else {
    uVar1 = (param_1[2] != '\0') + 3;
  }
  return uVar1;
}

