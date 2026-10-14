#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>



int FUN_1015bad0(uint8_t *param_1,int param_2,uint8_t *param_3)

{
    uint8_t bVar1;
    int uVar2;
    uint8_t local_5;

    if ((param_2 - 1 & 3) == 0) {
        bVar1 = *(param_1 + 4);
        uVar2 = 0;
        if (param_2 != 0) {
            do {
                if ((uVar2 != 4) && (local_5 = *(uVar2 + param_1) ^ bVar1, param_3 != (uint8_t *)0x0))
                {
                    *(param_3++) = local_5;
                }
                uVar2 = uVar2 + 1;
            } while (uVar2 < param_2);
        }
        return 0;
    }
    return 0xffffffff;
}



int FUN_10159ae0(uint8_t *this,uint8_t *param_1,int param_2)

{
    uint8_t bVar1;
    int uVar2;
    uint8_t *pbVar3;
    int iVar4;
    int iVar5;
    int local_10;
    int local_c;

    local_c = 0;
    uVar2 = 0;
    do {
        *(char *)(uVar2 + this) = (char)uVar2;
        uVar2 = uVar2 + 1;
    } while (uVar2 < 0x100);
    pbVar3 = (this + 1);
    local_10 = 0x40;
    iVar4 = 0;
    do {

        bVar1 = pbVar3[-1];
        iVar5 = iVar4 + 1;
        uVar2 = bVar1 + *(iVar4 + param_1) + local_c & 0xff;
        if (iVar5 == param_2) {
            iVar5 = 0;
        }
        pbVar3[-1] = *(uVar2 + this);
        *(uVar2 + this) = bVar1;

        bVar1 = *pbVar3;
        iVar4 = iVar5 + 1;
        uVar2 = bVar1 + *(iVar5 + param_1) + uVar2 & 0xff;
        if (iVar4 == param_2) {
            iVar4 = 0;
        }
        *pbVar3 = *(uVar2 + this);
        *(uVar2 + this) = bVar1;

        bVar1 = pbVar3[1];
        iVar5 = iVar4 + 1;
        uVar2 = bVar1 + *(iVar4 + param_1) + uVar2 & 0xff;
        if (iVar5 == param_2) {
            iVar5 = 0;
        }
        pbVar3[1] = *(uVar2 + this);
        *(uVar2 + this) = bVar1;

        bVar1 = pbVar3[2];
        iVar4 = iVar5 + 1;
        local_c = bVar1 + *(iVar5 + param_1) + uVar2 & 0xff;
        if (iVar4 == param_2) {
            iVar4 = 0;
        }
        pbVar3[2] = *(local_c + this);
        *(local_c + this) = bVar1;

        pbVar3 = pbVar3 + 4;
        local_10 = local_10 + -1;
    } while (local_10 != 0);

    return 0;
}



void FUN_10159bf0(uint8_t *this,uint8_t *param_1,uint8_t *param_2,int param_3,uint8_t *param_4,int param_5)

{
    uint8_t *pbVar1;
    int uVar2;
    uint8_t bVar3;
    char cVar4;
    uint8_t bVar5;
    uint8_t *pbVar6;
    int iVar7;
    
    pbVar6 = param_2;
    bVar5 = (uint8_t)param_3;
    if (param_5 >> 3 == 0) {
        param_4 = param_2;
        param_2 = param_1;
    }
    else {
        param_2 = param_1;
        uVar2 = param_5 >> 3;
        do {
            param_4 = (uint8_t *)uVar2;
            cVar4 = (char)param_3;
            bVar5 = *(uint8_t *)((int)(uint8_t)(cVar4 + 1U) + this);
            *pbVar6 = *(uint8_t *)(((int)*(uint8_t *)((int)(uint8_t)(cVar4 + 1U + bVar5) + this) + (int)bVar5 & 0xff) + this) ^ *param_2;
            bVar5 = *(uint8_t *)((int)(uint8_t)(cVar4 + 2U) + this);
            pbVar6[1] = *(uint8_t *)(((int)*(uint8_t *)((int)(uint8_t)(cVar4 + 2U + bVar5) + this) + (int)bVar5 & 0xff) + this) ^ param_2[1];
            bVar5 = *(uint8_t *)((int)(uint8_t)(cVar4 + 3U) + this);
            pbVar6[2] = *(uint8_t *)(((int)*(uint8_t *)((int)(uint8_t)(cVar4 + 3U + bVar5) + this) + (int)bVar5 & 0xff) + this) ^ param_2[2];
            bVar5 = *(uint8_t *)((int)(uint8_t)(cVar4 + 4U) + this);
            pbVar6[3] = *(uint8_t *)(((int)*(uint8_t *)((int)(uint8_t)(cVar4 + 4U + bVar5) + this) + (int)bVar5 & 0xff) + this) ^ param_2[3];
            bVar5 = *(uint8_t *)((int)(uint8_t)(cVar4 + 5U) + this);
            pbVar6[4] = *(uint8_t *)(((int)*(uint8_t *)((int)(uint8_t)(cVar4 + 5U + bVar5) + this) + (int)bVar5 & 0xff) + this) ^ param_2[4];
            bVar5 = *(uint8_t *)((int)(uint8_t)(cVar4 + 6U) + this);
            pbVar6[5] = *(uint8_t *)(((int)*(uint8_t *)((int)(uint8_t)(cVar4 + 6U + bVar5) + this) + (int)bVar5 & 0xff) + this) ^ param_2[5];
            bVar3 = *(uint8_t *)((int)(uint8_t)(cVar4 + 7U) + this);
            bVar5 = cVar4 + 8;
            param_3 = (int)bVar5;
            pbVar6[6] = *(uint8_t *)(((int)*(uint8_t *)((int)(uint8_t)(cVar4 + 7U + bVar3) + this) + (int)bVar3 & 0xff) + this) ^ param_2[6];
            pbVar1 = param_2 + 7;
            param_2 = param_2 + 8;
            pbVar6[7] = *(uint8_t *)(((int)*(uint8_t *)((param_3 + *(uint8_t *)(param_3 + this) & 0xff) + this) + (int)*(uint8_t *)(param_3 + this) & 0xff) + this) ^ *pbVar1;
            pbVar6 = pbVar6 + 8;
            uVar2 = (int)param_4 - 1;
            param_4 = pbVar6;
        } while (uVar2 != 0);

    }
    if ((param_5 & 7) != 0) {
        bVar5 = bVar5 + 1;
        *param_4 = *(uint8_t *)(((int)*(uint8_t *)((int)(uint8_t)(bVar5 + *(uint8_t *)((int)bVar5 + this)) + this) + (int)*(uint8_t *)((int)bVar5 + this) & 0xff) + this) ^ *param_2;
        for (iVar7 = (param_5 & 7) - 1;
                (((iVar7 != 0 &&
                    (bVar3 = *(uint8_t *)((int)(uint8_t)(bVar5 + 1) + this),
                    param_4[1] = *(uint8_t *)(((int)*(uint8_t *)((int)(uint8_t)(bVar5 + 1 + bVar3) + this) + (int)bVar3 & 0xff) + this) ^ param_2[1], iVar7 != 1)) &&
                 (bVar3 = *(uint8_t *)((int)(uint8_t)(bVar5 + 2) + this),
                 param_4[2] = *(uint8_t *)(((int)*(uint8_t *)((int)(uint8_t)(bVar5 + 2 + bVar3) + this) + (int)bVar3 & 0xff) + this) ^ param_2[2], iVar7 != 2)) &&
                (((bVar3 = *(uint8_t *)((int)(uint8_t)(bVar5 + 3) + this),
                    param_4[3] = *(uint8_t *)(((int)*(uint8_t *)((int)(uint8_t)(bVar5 + 3 + bVar3) + this) + (int)bVar3 & 0xff) + this) ^ param_2[3], iVar7 != 3 &&
                    (bVar3 = *(uint8_t *)((int)(uint8_t)(bVar5 + 4) + this),
                    param_4[4] = *(uint8_t *)(((int)*(uint8_t *)((int)(uint8_t)(bVar5 + 4 + bVar3) + this) + (int)bVar3 & 0xff) + this) ^ param_2[4], iVar7 != 4)) &&
                 ((bVar3 = *(uint8_t *)((int)(uint8_t)(bVar5 + 5) + this),
                    param_4[5] = *(uint8_t *)(((int)*(uint8_t *)((int)(uint8_t)(bVar5 + 5 + bVar3) + this) + (int)bVar3 & 0xff) + this) ^ param_2[5], iVar7 != 5 &&
                    (bVar3 = *(uint8_t *)((int)(uint8_t)(bVar5 + 6) + this),
                    param_4[6] = *(uint8_t *)(((int)*(uint8_t *)((int)(uint8_t)(bVar5 + 6 + bVar3) + this) + (int)bVar3 & 0xff) + this) ^ param_2[6], iVar7 != 6))))));
                iVar7 = iVar7 + -7) {
            bVar5 = bVar5 + 7;
            *param_4 = *(uint8_t *)(((int)*(uint8_t *)((int)(uint8_t)(bVar5 + *(uint8_t *)((int)bVar5 + this)) + this) + (int)*(uint8_t *)((int)bVar5 + this) & 0xff) + this) ^ *param_2;
        }
    }
    return;
}



int main() {

    FILE *fin = fopen("raw/360°环绕.ncae", "rb");
    assert(fin != NULL);

    char magic[5];
    fread(magic, 1, 4, fin);
    magic[4] = 0;
    assert(strcmp(magic, "NCAE") == 0);

    int ldata;
    fread(&ldata, 4, 1, fin);

    fseek(fin, 6, SEEK_CUR);

    short short_;
    fread(&short_, 2, 1, fin);

    int lkey = fgetc(fin) - 1;
    assert(lkey % 4 == 0);

    uint8_t *key0 = malloc(lkey + 1);
    fread(key0, 1, lkey + 1, fin);
    // for (int i = 0; i < lkey + 1; i++) {
    //     printf("%d ", key0[i]);
    // }
    // printf("\n");

    uint8_t *key = malloc(lkey + 1);
    FUN_1015bad0(key0, lkey + 1, key);
    free(key0);
    // for (int i = 0; i < lkey; i++) {
    //     printf("%d ", key[i]);
    // }
    // printf("\n");

    uint8_t *arr = malloc(0x100);
    FUN_10159ae0(arr, key, lkey);
    // for (int i = 0; i < 0x100; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    uint8_t *data = malloc(ldata);
    fread(data, 1, ldata, fin);
    for (int i = 0; i < ldata; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    FUN_10159bf0(arr, data, data, 0, NULL, ldata);
    for (int i = 0; i < ldata; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");

    fclose(fin);
    free(data);
    free(key);
    return 0;
}
