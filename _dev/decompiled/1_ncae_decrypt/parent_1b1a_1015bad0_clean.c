undefined4 __fastcall FUN_1015bad0(byte *src, uint len, byte *dest) 
{
    for (uint i = 0; i < len; i++) {
        if (i == 4) continue;
        byte b = src[i] ^ src[4];
        FUN_10015950(dest, (int **)&b, 1);
    }
    return 0;
}
