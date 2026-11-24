
/* Library Function - Single Match
    public: bool __thiscall type_info::operator==(class type_info const &)const 
   
   Library: Visual Studio 2019 Release */

bool __thiscall type_info::operator==(type_info *this,type_info *param_1)

{
  int iVar1;
  
  iVar1 = ___std_type_info_compare(this + 4,param_1 + 4);
  return (bool)('\x01' - (iVar1 != 0));
}

