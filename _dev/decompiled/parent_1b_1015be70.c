
void __fastcall FUN_1015be70(char *param_1,uint param_2,int **param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 ****ppppuVar3;
  uint ****ppppuVar4;
  undefined4 ****local_44 [4];
  int local_34;
  uint local_30;
  uint ****local_2c [4];
  uint local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1081b5d0;
  local_10 = ExceptionList;
  local_14 = DAT_10a76ad0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30 = 0xf;
  local_34 = 0;
  local_44[0] = (undefined4 ****)((uint)local_44[0] & 0xffffff00);
  local_18 = 0xf;
  local_1c = 0;
  local_2c[0] = (uint ****)((uint)local_2c[0] & 0xffffff00);
  local_8 = 1;
  if ((((param_1 != (char *)0x0) && (param_2 != 0)) &&
      (iVar2 = FUN_1015bb40(param_1,param_2,local_44,local_2c,param_4), uVar1 = local_1c, iVar2 == 0
      )) && (param_3 != (int **)0x0)) {
    ppppuVar4 = (uint ****)local_2c;
    if (0xf < local_18) {
      ppppuVar4 = local_2c[0];
    }
    ppppuVar3 = local_44;
    if (0xf < local_30) {
      ppppuVar3 = local_44[0];
    }
    iVar2 = FUN_1015bde0((int)ppppuVar3,local_34,(byte *)ppppuVar4,local_1c);
    if (iVar2 == 0) {
      FUN_1015bbe0((uint *)ppppuVar4,uVar1,param_3);
    }
  }
  if (0xf < local_18) {
    FID_conflict__free(local_2c[0]);
  }
  local_18 = 0xf;
  local_1c = 0;
  local_2c[0] = (uint ****)((uint)local_2c[0] & 0xffffff00);
  if (0xf < local_30) {
    FID_conflict__free(local_44[0]);
  }
  ExceptionList = local_10;
  FUN_10704e34(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

