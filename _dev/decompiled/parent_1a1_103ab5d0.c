
void __cdecl FUN_103ab5d0(undefined4 *param_1,int **param_2)

{
  char cVar1;
  undefined4 ***_Mode;
  void **ppvVar2;
  int **ppiVar3;
  undefined4 ***local_40;
  undefined4 local_3c;
  undefined4 ***local_38 [5];
  uint local_24;
  undefined4 ***local_20 [4];
  undefined4 local_10;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_10a76ad0 ^ (uint)&stack0xfffffffc;
  local_c = 0xf;
  local_10 = 0;
  local_20[0] = (undefined4 ***)((uint)local_20[0] & 0xffffff00);
  if (*(char *)param_2 == '\0') {
    ppvVar2 = (void **)0x0;
  }
  else {
    ppiVar3 = param_2;
    do {
      cVar1 = *(char *)ppiVar3;
      ppiVar3 = (int **)((int)ppiVar3 + 1);
    } while (cVar1 != '\0');
    ppvVar2 = (void **)((int)ppiVar3 - ((int)param_2 + 1));
  }
  FUN_1000a8e0(local_20,param_2,ppvVar2);
  local_40 = local_20;
  if (0xf < local_c) {
    local_40 = local_20[0];
  }
  local_3c = local_10;
  FUN_103aa000((undefined2 *)local_38,(char **)&local_40);
  if (0xf < local_c) {
    FID_conflict__free(local_20[0]);
  }
  _Mode = local_38;
  if (7 < local_24) {
    _Mode = local_38[0];
  }
  if (7 < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  __wfsopen((wchar_t *)param_1,(wchar_t *)_Mode,0x40);
  if (7 < local_24) {
    FID_conflict__free(local_38[0]);
  }
  FUN_10704e34(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

