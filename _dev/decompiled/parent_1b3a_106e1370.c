
int __cdecl FUN_106e1370(int param_1,uint param_2,char *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if (((param_3 == (char *)0x0) || (*param_3 != '1')) || (param_4 != 0x3c)) {
    return -6;
  }
  if (param_1 == 0) {
    return -2;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  if (*(int *)(param_1 + 0x20) == 0) {
    *(code **)(param_1 + 0x20) = FUN_106e2610;
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    *(code **)(param_1 + 0x24) = FUN_102a8fd0;
  }
  iVar1 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x1bcc);
  if (iVar1 == 0) {
    return -4;
  }
  *(int *)(param_1 + 0x1c) = iVar1;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  iVar2 = FUN_106e1500(param_1,param_2);
  if (iVar2 != 0) {
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),iVar1);
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return iVar2;
}

