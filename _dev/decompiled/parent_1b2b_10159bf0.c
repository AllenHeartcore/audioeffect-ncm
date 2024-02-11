
void __thiscall
FUN_10159bf0(void *this,byte *param_1,byte *param_2,uint param_3,byte *param_4,uint param_5)

{
  byte *pbVar1;
  uint uVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  byte *pbVar6;
  int iVar7;
  
  pbVar6 = param_2;
  bVar5 = (byte)param_3;
  if (param_5 >> 3 == 0) {
    param_4 = param_2;
    param_2 = param_1;
  }
  else {
    param_2 = param_1;
    uVar2 = param_5 >> 3;
    do {
      param_4 = (byte *)uVar2;
      cVar4 = (char)param_3;
      bVar5 = *(byte *)((uint)(byte)(cVar4 + 1U) + (int)this);
      *pbVar6 = *(byte *)(((uint)*(byte *)((uint)(byte)(cVar4 + 1U + bVar5) + (int)this) +
                           (uint)bVar5 & 0xff) + (int)this) ^ *param_2;
// *pbVar6 = *(byte *)(
//     (
//         (uint)*(byte *)(
//             (uint)(byte)(cVar4 + 1U + bVar5) + (int)this
//         ) + (uint)bVar5 & 0xff
//     ) + (int)this
// ) ^ *param_2;
      bVar5 = *(byte *)((uint)(byte)(cVar4 + 2U) + (int)this);
      pbVar6[1] = *(byte *)(((uint)*(byte *)((uint)(byte)(cVar4 + 2U + bVar5) + (int)this) +
                             (uint)bVar5 & 0xff) + (int)this) ^ param_2[1];
      bVar5 = *(byte *)((uint)(byte)(cVar4 + 3U) + (int)this);
      pbVar6[2] = *(byte *)(((uint)*(byte *)((uint)(byte)(cVar4 + 3U + bVar5) + (int)this) +
                             (uint)bVar5 & 0xff) + (int)this) ^ param_2[2];
      bVar5 = *(byte *)((uint)(byte)(cVar4 + 4U) + (int)this);
      pbVar6[3] = *(byte *)(((uint)*(byte *)((uint)(byte)(cVar4 + 4U + bVar5) + (int)this) +
                             (uint)bVar5 & 0xff) + (int)this) ^ param_2[3];
      bVar5 = *(byte *)((uint)(byte)(cVar4 + 5U) + (int)this);
      pbVar6[4] = *(byte *)(((uint)*(byte *)((uint)(byte)(cVar4 + 5U + bVar5) + (int)this) +
                             (uint)bVar5 & 0xff) + (int)this) ^ param_2[4];
      bVar5 = *(byte *)((uint)(byte)(cVar4 + 6U) + (int)this);
      pbVar6[5] = *(byte *)(((uint)*(byte *)((uint)(byte)(cVar4 + 6U + bVar5) + (int)this) +
                             (uint)bVar5 & 0xff) + (int)this) ^ param_2[5];
      bVar3 = *(byte *)((uint)(byte)(cVar4 + 7U) + (int)this);
      bVar5 = cVar4 + 8;
      param_3 = (uint)bVar5;
      pbVar6[6] = *(byte *)(((uint)*(byte *)((uint)(byte)(cVar4 + 7U + bVar3) + (int)this) +
                             (uint)bVar3 & 0xff) + (int)this) ^ param_2[6];
      pbVar1 = param_2 + 7;
      param_2 = param_2 + 8;
      pbVar6[7] = *(byte *)(((uint)*(byte *)((param_3 + *(byte *)(param_3 + (int)this) & 0xff) +
                                            (int)this) + (uint)*(byte *)(param_3 + (int)this) & 0xff
                            ) + (int)this) ^ *pbVar1;
      pbVar6 = pbVar6 + 8;
      uVar2 = (int)param_4 - 1;
      param_4 = pbVar6;
    } while (uVar2 != 0);

// Remove type casting
// do {
//     param_4 = uVar2;
//     cVar4 = param_3;
//     bVar5 = *((cVar4 + 1U) + this);
//     *pbVar6 = *((*((cVar4 + 1U + bVar5) + this) + bVar5 & 0xff) + this) ^ *param_2;
//     bVar5 = *((cVar4 + 2U) + this);
//     pbVar6[1] = *((*((cVar4 + 2U + bVar5) + this) + bVar5 & 0xff) + this) ^ param_2[1];
//     bVar5 = *((cVar4 + 3U) + this);
//     pbVar6[2] = *((*((cVar4 + 3U + bVar5) + this) + bVar5 & 0xff) + this) ^ param_2[2];
//     bVar5 = *((cVar4 + 4U) + this);
//     pbVar6[3] = *((*((cVar4 + 4U + bVar5) + this) + bVar5 & 0xff) + this) ^ param_2[3];
//     bVar5 = *((cVar4 + 5U) + this);
//     pbVar6[4] = *((*((cVar4 + 5U + bVar5) + this) + bVar5 & 0xff) + this) ^ param_2[4];
//     bVar5 = *((cVar4 + 6U) + this);
//     pbVar6[5] = *((*((cVar4 + 6U + bVar5) + this) + bVar5 & 0xff) + this) ^ param_2[5];
//     bVar3 = *((cVar4 + 7U) + this);
//     bVar5 = cVar4 + 8;
//     param_3 = bVar5;
//     pbVar6[6] = *((*((cVar4 + 7U + bVar3) + this) + bVar3 & 0xff) + this) ^ param_2[6];
//     pbVar1 = param_2 + 7;
//     param_2 = param_2 + 8;
//     pbVar6[7] = *((*((param_3 + *(param_3 + this) & 0xff) + this) + *(param_3 + this) & 0xff) + this) ^ *pbVar1;
//     pbVar6 = pbVar6 + 8;
//     uVar2 = param_4 - 1;
//     param_4 = pbVar6;
// } while (uVar2 != 0);

// Rewrite pointers to array indexing
// do {
//     param_4 = uVar2;
//     cVar4 = param_3;
//     bVar5 = this[cVar4 + 1U];
//     pbVar6[0] = this[this[cVar4 + 1U + bVar5] + bVar5 & 0xff] ^ param_2[0];
//     bVar5 = this[cVar4 + 2U];
//     pbVar6[1] = this[this[cVar4 + 2U + bVar5] + bVar5 & 0xff] ^ param_2[1];
//     bVar5 = this[cVar4 + 3U];
//     pbVar6[2] = this[this[cVar4 + 3U + bVar5] + bVar5 & 0xff] ^ param_2[2];
//     bVar5 = this[cVar4 + 4U];
//     pbVar6[3] = this[this[cVar4 + 4U + bVar5] + bVar5 & 0xff] ^ param_2[3];
//     bVar5 = this[cVar4 + 5U];
//     pbVar6[4] = this[this[cVar4 + 5U + bVar5] + bVar5 & 0xff] ^ param_2[4];
//     bVar5 = this[cVar4 + 6U];
//     pbVar6[5] = this[this[cVar4 + 6U + bVar5] + bVar5 & 0xff] ^ param_2[5];
//     bVar3 = this[cVar4 + 7U];
//     bVar5 = cVar4 + 8;
//     param_3 = bVar5;
//     pbVar6[6] = this[this[cVar4 + 7U + bVar3] + bVar3 & 0xff] ^ param_2[6];
//     pbVar1 = param_2 + 7;
//     param_2 = param_2 + 8;
//     pbVar6[7] = this[this[param_3 + this[param_3] & 0xff] + this[param_3] & 0xff] ^ *pbVar1;
//     pbVar6 = pbVar6 + 8;
//     uVar2 = param_4 - 1;
//     param_4 = pbVar6;
// } while (uVar2 != 0);

// Remove redundant variables (pbVar6, pbVar1, bVar3, cVar4, param_4)
// do {
//     bVar5 = this[param_3 + 1U];
//     param_2[0] = this[this[param_3 + 1U + bVar5] + bVar5 & 0xff] ^ param_2[0];
//     bVar5 = this[param_3 + 2U];
//     param_2[1] = this[this[param_3 + 2U + bVar5] + bVar5 & 0xff] ^ param_2[1];
//     bVar5 = this[param_3 + 3U];
//     param_2[2] = this[this[param_3 + 3U + bVar5] + bVar5 & 0xff] ^ param_2[2];
//     bVar5 = this[param_3 + 4U];
//     param_2[3] = this[this[param_3 + 4U + bVar5] + bVar5 & 0xff] ^ param_2[3];
//     bVar5 = this[param_3 + 5U];
//     param_2[4] = this[this[param_3 + 5U + bVar5] + bVar5 & 0xff] ^ param_2[4];
//     bVar5 = this[param_3 + 6U];
//     param_2[5] = this[this[param_3 + 6U + bVar5] + bVar5 & 0xff] ^ param_2[5];
//     bVar5 = this[param_3 + 7U];
//     param_2[6] = this[this[param_3 + 7U + bVar5] + bVar5 & 0xff] ^ param_2[6];
//     bVar5 = this[param_3 + 8U];
//     param_2[7] = this[this[param_3 + 8U + bVar5] + bVar5 & 0xff] ^ param_2[7];
//     param_3 = param_3 + 8;
//     param_2 = param_2 + 8;
//     uVar2 = uVar2 - 1;
// } while (uVar2 != 0);

// pack into a loop & cleanup
// while (uVar2-- != 0) {
//     for (uint i = 1; i <= 8; i++) {
//         bVar5 = this[param_3 + i];
//         param_2[i - 1] ^= this[this[param_3 + i + bVar5] + bVar5 & 0xff];
//     }
//     param_3 += 8;
//     param_2 += 8;
// }

  }
  if ((param_5 & 7) != 0) {
    bVar5 = bVar5 + 1;
    *param_4 = *(byte *)(((uint)*(byte *)((uint)(byte)(bVar5 + *(byte *)((uint)bVar5 + (int)this)) +
                                         (int)this) + (uint)*(byte *)((uint)bVar5 + (int)this) &
                         0xff) + (int)this) ^ *param_2;
    for (iVar7 = (param_5 & 7) - 1;
        (((iVar7 != 0 &&
          (bVar3 = *(byte *)((uint)(byte)(bVar5 + 1) + (int)this),
          param_4[1] = *(byte *)(((uint)*(byte *)((uint)(byte)(bVar5 + 1 + bVar3) + (int)this) +
                                  (uint)bVar3 & 0xff) + (int)this) ^ param_2[1], iVar7 != 1)) &&
         (bVar3 = *(byte *)((uint)(byte)(bVar5 + 2) + (int)this),
         param_4[2] = *(byte *)(((uint)*(byte *)((uint)(byte)(bVar5 + 2 + bVar3) + (int)this) +
                                 (uint)bVar3 & 0xff) + (int)this) ^ param_2[2], iVar7 != 2)) &&
        (((bVar3 = *(byte *)((uint)(byte)(bVar5 + 3) + (int)this),
          param_4[3] = *(byte *)(((uint)*(byte *)((uint)(byte)(bVar5 + 3 + bVar3) + (int)this) +
                                  (uint)bVar3 & 0xff) + (int)this) ^ param_2[3], iVar7 != 3 &&
          (bVar3 = *(byte *)((uint)(byte)(bVar5 + 4) + (int)this),
          param_4[4] = *(byte *)(((uint)*(byte *)((uint)(byte)(bVar5 + 4 + bVar3) + (int)this) +
                                  (uint)bVar3 & 0xff) + (int)this) ^ param_2[4], iVar7 != 4)) &&
         ((bVar3 = *(byte *)((uint)(byte)(bVar5 + 5) + (int)this),
          param_4[5] = *(byte *)(((uint)*(byte *)((uint)(byte)(bVar5 + 5 + bVar3) + (int)this) +
                                  (uint)bVar3 & 0xff) + (int)this) ^ param_2[5], iVar7 != 5 &&
          (bVar3 = *(byte *)((uint)(byte)(bVar5 + 6) + (int)this),
          param_4[6] = *(byte *)(((uint)*(byte *)((uint)(byte)(bVar5 + 6 + bVar3) + (int)this) +
                                  (uint)bVar3 & 0xff) + (int)this) ^ param_2[6], iVar7 != 6))))));
        iVar7 = iVar7 + -7) {
      bVar5 = bVar5 + 7;
      *param_4 = *(byte *)(((uint)*(byte *)((uint)(byte)(bVar5 + *(byte *)((uint)bVar5 + (int)this))
                                           + (int)this) + (uint)*(byte *)((uint)bVar5 + (int)this) &
                           0xff) + (int)this) ^ *param_2;
    }
  }
  return;
}

