
undefined4 __thiscall FUN_10159ae0(void *this,int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int local_10;
  uint local_c;
  
  local_c = 0;
  uVar2 = 0;
  do {
    *(char *)(uVar2 + (int)this) = (char)uVar2;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  pbVar3 = (byte *)((int)this + 1);
  local_10 = 0x40;
  iVar4 = 0;
  do {

    bVar1 = pbVar3[-1];
    iVar5 = iVar4 + 1;
    uVar2 = (uint)bVar1 + *(byte *)(iVar4 + param_1) + local_c & 0xff;
    if (iVar5 == param_2) {
      iVar5 = 0;
    }
    pbVar3[-1] = *(byte *)(uVar2 + (int)this);
    *(byte *)(uVar2 + (int)this) = bVar1;

    bVar1 = *pbVar3;
    iVar4 = iVar5 + 1;
    uVar2 = (uint)bVar1 + *(byte *)(iVar5 + param_1) + uVar2 & 0xff;
    if (iVar4 == param_2) {
      iVar4 = 0;
    }
    *pbVar3 = *(byte *)(uVar2 + (int)this);
    *(byte *)(uVar2 + (int)this) = bVar1;

    bVar1 = pbVar3[1];
    iVar5 = iVar4 + 1;
    uVar2 = (uint)bVar1 + *(byte *)(iVar4 + param_1) + uVar2 & 0xff;
    if (iVar5 == param_2) {
      iVar5 = 0;
    }
    pbVar3[1] = *(byte *)(uVar2 + (int)this);
    *(byte *)(uVar2 + (int)this) = bVar1;

    bVar1 = pbVar3[2];
    iVar4 = iVar5 + 1;
    local_c = (uint)bVar1 + *(byte *)(iVar5 + param_1) + uVar2 & 0xff;
    if (iVar4 == param_2) {
      iVar4 = 0;
    }
    pbVar3[2] = *(byte *)(local_c + (int)this);
    *(byte *)(local_c + (int)this) = bVar1;

    pbVar3 = pbVar3 + 4;
    local_10 = local_10 + -1;
  } while (local_10 != 0);

// iVar = 0;
// for (uint j = 0; j < 0x100; j++) {
//     this[j] = j;
// }
// for (uint j = 0; j < 0x100; j++) {
//     bVar1 = this[j];
//     uVar2 = bVar1 + param_1[iVar] + uVar2 & 0xff;
//     iVar++;
//     if (iVar == param_2) iVar = 0;
//     this[iVar] = this[uVar2];
//     this[uVar2] = bVar1;
// }

// for (uint j = 0; j < 0x100; j++) {
//     this[j] = j;
// }
// for (uint j = 0; j < 0x100; j++) {
//     bVar1 = this[j];
//     uVar2 = bVar1 + param_1[j % param_2] + uVar2 & 0xff;
//     this[j] = this[uVar2];
//     this[uVar2] = bVar1;
// }

  return 0;
}

