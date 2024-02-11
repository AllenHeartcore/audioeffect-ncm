
undefined4 __fastcall FUN_1015bde0(int param_1,int param_2,byte *param_3,uint param_4)

{
  uint *this;
  int iVar1;
  
  this = (uint *)FUN_10705677(0x100);
  if (this == (uint *)0x0) {
    return 0xffffffff;
  }
  FUN_10709e90(this,0,0x100);
  iVar1 = FUN_10159ae0(this,param_1,param_2);
  if (iVar1 != 0) {
    FID_conflict__free(this);
    return 0xfffffffe;
  }
  FUN_10159bf0(this,param_3,param_3,0,0,param_4);
  FID_conflict__free(this);
  return 0;
}

