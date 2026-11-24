
/* Library Function - Single Match
    ___acrt_eagerly_load_locale_apis
   
   Library: Visual Studio 2019 Release */

void ___acrt_eagerly_load_locale_apis(void)

{
  try_get_AreFileApisANSI();
  try_get_CompareStringEx();
  try_get_EnumSystemLocalesEx();
  try_get_GetDateFormatEx();
  try_get_GetLocaleInfoEx();
  try_get_GetTimeFormatEx();
  try_get_GetUserDefaultLocaleName();
  try_get_IsValidLocaleName();
  try_get_LCMapStringEx();
  try_get_LCIDToLocaleName();
  try_get_LocaleNameToLCID();
  return;
}

