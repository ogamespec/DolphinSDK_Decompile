uint GetFontCode(uint param_1)
{
  short sVar1;
  int iVar2;
  
  sVar1 = OSGetFontEncode();
  if (sVar1 == 1) {
    if ((0x1f < (param_1 & 0xffff)) && ((param_1 & 0xffff) < 0xe0)) {
      return (uint)*(ushort *)(HankakuToCode + ((param_1 & 0xffff) - 0x20) * 2);
    }
    if ((0x889e < (param_1 & 0xffff)) && ((param_1 & 0xffff) < 0x9873)) {
      iVar2 = (param_1 & 0xff) - 0x40;
      if (0x3f < iVar2) {
        iVar2 = (param_1 & 0xff) - 0x41;
      }
      if (0xbb < iVar2) {
        return 0;
      }
      return ((param_1 >> 8 & 0xff) - 0x88) * 0xbc + iVar2 + 0x2be;
    }
    if ((0x813f < (param_1 & 0xffff)) && ((param_1 & 0xffff) < 0x879e)) {
      iVar2 = (param_1 & 0xff) - 0x40;
      if (0x3f < iVar2) {
        iVar2 = (param_1 & 0xff) - 0x41;
      }
      if (0xbb < iVar2) {
        return 0;
      }
      return (uint)*(ushort *)(&Zenkaku2Code + (((param_1 >> 8 & 0xff) - 0x81) * 0xbc + iVar2) * 2);
    }
  }
  else if ((0x20 < (param_1 & 0xffff)) && ((param_1 & 0xffff) < 0x100)) {
    return (param_1 & 0xffff) - 0x20;
  }
  return 0;
}

void Decode(int param_1,int param_2)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  uint unaff_r22;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar3 = *(int *)(param_1 + 4);
  iVar9 = *(int *)(param_1 + 8);
  iVar4 = *(int *)(param_1 + 0xc);
  iVar11 = 0;
  iVar8 = 0;
  iVar5 = 0x10;
  do {
    if (iVar8 == 0) {
      unaff_r22 = *(uint *)(param_1 + iVar5);
      iVar5 = iVar5 + 4;
      iVar8 = 0x20;
    }
    if ((unaff_r22 & 0x80000000) == 0) {
      pbVar2 = (byte *)(param_1 + iVar9);
      bVar1 = *(byte *)(iVar9 + param_1 + 1);
      iVar9 = iVar9 + 2;
      iVar6 = iVar11 - ((*pbVar2 & 0xf) << 8 | (uint)bVar1);
      iVar10 = (int)(uint)CONCAT11(*pbVar2,bVar1) >> 0xc;
      if (iVar10 == 0) {
        iVar10 = *(byte *)(param_1 + iVar4) + 0x12;
        iVar4 = iVar4 + 1;
      }
      else {
        iVar10 = iVar10 + 2;
      }
      for (iVar7 = 0; iVar7 < iVar10; iVar7 = iVar7 + 1) {
        *(undefined *)(param_2 + iVar11) = *(undefined *)(iVar6 + param_2 + -1);
        iVar11 = iVar11 + 1;
        iVar6 = iVar6 + 1;
      }
    }
    else {
      *(undefined *)(param_2 + iVar11) = *(undefined *)(param_1 + iVar4);
      iVar4 = iVar4 + 1;
      iVar11 = iVar11 + 1;
    }
    unaff_r22 = unaff_r22 << 1;
    iVar8 = iVar8 + -1;
  } while (iVar11 < iVar3);
  return;
}

undefined4 GetFontSize(char *param_1)
{
  if (((*param_1 == 'Y') && (param_1[1] == 'a')) && (param_1[2] == 'y')) {
    return *(undefined4 *)(param_1 + 4);
  }
  return 0;
}

ushort OSGetFontEncode(void)
{
  int *piVar1;
  
  if (1 < fontEncode$55) {
    piVar1 = (int *)OSPhysicalToCached(0xcc);
    if (*piVar1 == 0) {
      fontEncode$55 = (ushort)((_DAT_cc00206e & 2) != 0);
    }
    else {
      fontEncode$55 = 0;
    }
  }
  return fontEncode$55;
}

void ReadROM(int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  while (0 < param_2) {
    iVar2 = param_2;
    if (0x100 < param_2) {
      iVar2 = 0x100;
    }
    param_2 = param_2 - iVar2;
    do {
      iVar1 = __OSReadROM(param_1,iVar2,param_3);
    } while (iVar1 == 0);
    param_3 = param_3 + iVar2;
    param_1 = param_1 + iVar2;
  }
  return;
}

void ReadFont(undefined4 param_1)
{
  short sVar1;
  
  sVar1 = OSGetFontEncode();
  if (sVar1 == 1) {
    ReadROM(param_1,0x4d000,0x1aff00);
  }
  else {
    ReadROM(param_1,0x3000,0x1fcf00);
  }
  GetFontSize(param_1);
  return;
}

int OSLoadFont(int param_1,undefined4 param_2)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  short sVar6;
  int iVar4;
  uint uVar5;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined2 *puVar11;
  int iVar12;
  undefined4 local_38;
  undefined4 local_34;
  
  SheetImage = 0;
  iVar3 = ReadFont(param_2);
  if (iVar3 != 0) {
    Decode(param_2,param_1);
    WidthTable = param_1 + (uint)*(ushort *)(param_1 + 0x22);
    CharsInSheet = (uint)*(ushort *)(param_1 + 0x1a) * (uint)*(ushort *)(param_1 + 0x1c);
    FontData = param_1;
    sVar6 = OSGetFontEncode();
    if (sVar6 == 1) {
      local_38 = @81._0_4_;
      local_34 = @81._4_4_;
      iVar4 = GetFontCode(0x54);
      iVar7 = iVar4 / CharsInSheet;
      iVar4 = iVar4 - iVar7 * CharsInSheet;
      iVar9 = iVar4 / (int)(uint)*(ushort *)(FontData + 0x1a);
      iVar10 = iVar9 * (uint)*(ushort *)(FontData + 0x12);
      uVar8 = (iVar4 - iVar9 * (uint)*(ushort *)(FontData + 0x1a)) *
              (uint)*(ushort *)(FontData + 0x10);
      iVar9 = FontData + *(int *)(FontData + 0x24);
      iVar4 = *(int *)(FontData + 0x14);
      for (iVar12 = 4; iVar12 < 8; iVar12 = iVar12 + 1) {
        uVar1 = iVar10 + iVar12;
        uVar5 = iVar10 + iVar12;
        uVar2 = uVar8 + (((int)uVar8 >> 3) + (uint)((int)uVar8 < 0 && (uVar8 & 7) != 0)) * -8;
        puVar11 = (undefined2 *)
                  (iVar9 + ((uint)(iVar7 * iVar4) >> 1) +
                   (((int)(uint)*(ushort *)(FontData + 0x1e) >> 3) * 0x20 >> 1) *
                   (((int)uVar1 >> 3) + (uint)((int)uVar1 < 0 && (uVar1 & 7) != 0)) +
                   (((int)uVar8 >> 3) + (uint)((int)uVar8 < 0 && (uVar8 & 7) != 0)) * 0x10 +
                   (uVar5 + (((int)uVar5 >> 3) + (uint)((int)uVar5 < 0 && (uVar5 & 7) != 0)) * -8) *
                   2 + ((int)uVar2 >> 2) + (uint)((int)uVar2 < 0 && (uVar2 & 3) != 0));
        *puVar11 = *(undefined2 *)((int)&local_38 + (iVar12 + -4) * 2);
        DCStoreRange(puVar11,2);
      }
    }
  }
  return iVar3;
}

byte * OSGetFontTexel(byte *param_1,int param_2,int param_3,uint param_4,uint *param_5)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  short sVar11;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  byte bVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  byte *pbVar18;
  uint uVar19;
  int iVar20;
  ushort uVar21;
  
  if ((FontData == 0) || (SheetImage != 0)) {
    OSPanic(@111,0x25a,@112);
  }
  bVar12 = *param_1;
  uVar21 = (ushort)bVar12;
  if (bVar12 != 0) {
    pbVar18 = param_1 + 1;
    sVar11 = OSGetFontEncode();
    if (((sVar11 == 1) &&
        (((0x7f < bVar12 && (bVar12 < 0xa0)) || ((0xdf < bVar12 && (bVar12 < 0x100)))))) &&
       (*pbVar18 != 0)) {
      uVar21 = CONCAT11(bVar12,*pbVar18);
      pbVar18 = param_1 + 2;
    }
    param_1 = pbVar18;
    iVar1 = FontData + 0x2c;
    if (*(short *)(FontData + 0x18) != 0) {
      OSPanic(@111,0x26d,@113);
    }
    iVar7 = GetFontCode(uVar21);
    iVar14 = iVar7 / CharsInSheet;
    iVar13 = iVar7 - iVar14 * CharsInSheet;
    iVar16 = iVar13 / (int)(uint)*(ushort *)(FontData + 0x1a);
    iVar17 = iVar16 * (uint)*(ushort *)(FontData + 0x12);
    iVar15 = (iVar13 - iVar16 * (uint)*(ushort *)(FontData + 0x1a)) *
             (uint)*(ushort *)(FontData + 0x10);
    iVar16 = FontData + *(int *)(FontData + 0x24);
    iVar13 = *(int *)(FontData + 0x14);
    for (uVar19 = 0; (int)uVar19 < (int)(uint)*(ushort *)(FontData + 0x12); uVar19 = uVar19 + 1) {
      for (iVar20 = 0; iVar20 < (int)(uint)*(ushort *)(FontData + 0x10); iVar20 = iVar20 + 1) {
        uVar2 = iVar17 + uVar19;
        uVar3 = iVar15 + iVar20;
        uVar8 = iVar17 + uVar19;
        uVar9 = iVar15 + iVar20;
        uVar9 = uVar9 + (((int)uVar9 >> 3) + (uint)((int)uVar9 < 0 && (uVar9 & 7) != 0)) * -8;
        uVar4 = iVar15 + iVar20;
        uVar6 = param_4 << 2 | param_4 >> 0x1e;
        uVar5 = param_3 + iVar20;
        uVar10 = param_3 + iVar20;
        uVar10 = uVar10 + (((int)uVar10 >> 3) + (uint)((int)uVar10 < 0 && (uVar10 & 7) != 0)) * -8;
        pbVar18 = (byte *)(param_2 + (((int)uVar19 >> 3) +
                                     (uint)((int)uVar19 < 0 && (uVar19 & 7) != 0)) *
                                     (((int)uVar6 >> 3) +
                                     (uint)((int)uVar6 < 0 && (param_4 << 2 & 4) != 0)) * 0x20 +
                           (((int)uVar5 >> 3) + (uint)((int)uVar5 < 0 && (uVar5 & 7) != 0)) * 0x20 +
                           (uVar19 + (((int)uVar19 >> 3) +
                                     (uint)((int)uVar19 < 0 && (uVar19 & 7) != 0)) * -8) * 4 +
                          ((int)uVar10 >> 1) + (uint)((int)uVar10 < 0 && (uVar10 & 1) != 0));
        uVar6 = param_3 + iVar20;
        if (uVar6 == (((int)uVar6 >> 1) + (uint)((int)uVar6 < 0 && (uVar6 & 1) != 0)) * 2) {
          bVar12 = 0xf0;
        }
        else {
          bVar12 = 0xf;
        }
        *pbVar18 = *pbVar18 |
                   *(byte *)(iVar1 + ((int)(uint)*(byte *)(iVar16 + ((uint)(iVar14 * iVar13) >> 1) +
                                                           (((int)(uint)*(ushort *)(FontData + 0x1e)
                                                            >> 3) * 0x20 >> 1) *
                                                           (((int)uVar2 >> 3) +
                                                           (uint)((int)uVar2 < 0 && (uVar2 & 7) != 0
                                                                 )) +
                                                           (((int)uVar3 >> 3) +
                                                           (uint)((int)uVar3 < 0 && (uVar3 & 7) != 0
                                                                 )) * 0x10 +
                                                           (uVar8 + (((int)uVar8 >> 3) +
                                                                    (uint)((int)uVar8 < 0 &&
                                                                          (uVar8 & 7) != 0)) * -8) *
                                                           2 + ((int)uVar9 >> 2) +
                                                               (uint)((int)uVar9 < 0 &&
                                                                     (uVar9 & 3) != 0)) >>
                                      ((uVar4 + (((int)uVar4 >> 2) +
                                                (uint)((int)uVar4 < 0 && (uVar4 & 3) != 0)) * -4) *
                                       -2 + 6 & 0x3f) & 3U)) & bVar12;
      }
    }
    if (param_5 != (uint *)0x0) {
      *param_5 = (uint)*(byte *)(WidthTable + iVar7);
    }
  }
  return param_1;
}

void ExpandFontSheet(int param_1,int param_2)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = FontData + 0x2c;
  if (*(short *)(FontData + 0x18) == 0) {
    uVar1 = *(uint *)(FontData + 0x28);
    iVar2 = ((int)uVar1 >> 1) + (uint)((int)uVar1 < 0 && (uVar1 & 1) != 0);
    while (iVar2 = iVar2 + -1, -1 < iVar2) {
      *(byte *)(param_2 + iVar2 * 2) =
           *(byte *)(iVar3 + (uint)(*(byte *)(param_1 + iVar2) >> 6)) & 0xf0 |
           *(byte *)(iVar3 + (*(byte *)(param_1 + iVar2) >> 4 & 3)) & 0xf;
      *(byte *)(iVar2 * 2 + param_2 + 1) =
           *(byte *)(iVar3 + (*(byte *)(param_1 + iVar2) >> 2 & 3)) & 0xf0 |
           *(byte *)(iVar3 + (*(byte *)(param_1 + iVar2) & 3)) & 0xf;
    }
  }
  else if (*(short *)(FontData + 0x18) == 2) {
    uVar1 = *(uint *)(FontData + 0x28);
    iVar2 = ((int)uVar1 >> 2) + (uint)((int)uVar1 < 0 && (uVar1 & 3) != 0);
    while (iVar2 = iVar2 + -1, -1 < iVar2) {
      *(undefined *)(param_2 + iVar2 * 4) =
           *(undefined *)(iVar3 + (uint)(*(byte *)(param_1 + iVar2) >> 6));
      *(undefined *)(iVar2 * 4 + param_2 + 1) =
           *(undefined *)(iVar3 + (*(byte *)(param_1 + iVar2) >> 4 & 3));
      *(undefined *)(iVar2 * 4 + param_2 + 2) =
           *(undefined *)(iVar3 + (*(byte *)(param_1 + iVar2) >> 2 & 3));
      *(undefined *)(iVar2 * 4 + param_2 + 3) =
           *(undefined *)(iVar3 + (*(byte *)(param_1 + iVar2) & 3));
    }
  }
  DCStoreRange(param_2,*(undefined4 *)(FontData + 0x28));
  return;
}

bool OSInitFont(int param_1)
{
  short sVar2;
  int iVar1;
  uint uVar3;
  
  sVar2 = OSGetFontEncode();
  if (sVar2 == 1) {
    uVar3 = param_1 + 0xd3f00;
  }
  else {
    uVar3 = param_1 + 0x1d120;
  }
  iVar1 = OSLoadFont(param_1,uVar3 & 0xffffffe0);
  if (iVar1 != 0) {
    SheetImage = FontData + *(int *)(FontData + 0x24) + 0x1fU & 0xffffffe0;
    ExpandFontSheet(FontData + *(int *)(FontData + 0x24),SheetImage);
  }
  return iVar1 != 0;
}

byte * OSGetFontTexture(byte *param_1,int *param_2,int *param_3,int *param_4,uint *param_5)
{
  byte bVar1;
  short sVar3;
  int iVar2;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  ushort uVar7;
  
  if (SheetImage == 0) {
    OSPanic(@111,0x2f7,@149);
  }
  if (WidthTable == 0) {
    OSPanic(@111,0x2f8,@150);
  }
  bVar1 = *param_1;
  uVar7 = (ushort)bVar1;
  if (bVar1 == 0) {
    *param_2 = 0;
  }
  else {
    pbVar6 = param_1 + 1;
    sVar3 = OSGetFontEncode();
    if (((sVar3 == 1) && (((0x7f < bVar1 && (bVar1 < 0xa0)) || ((0xdf < bVar1 && (bVar1 < 0x100)))))
        ) && (*pbVar6 != 0)) {
      uVar7 = CONCAT11(bVar1,*pbVar6);
      pbVar6 = param_1 + 2;
    }
    param_1 = pbVar6;
    iVar2 = GetFontCode(uVar7);
    iVar5 = iVar2 / CharsInSheet;
    *param_2 = SheetImage + *(int *)(FontData + 0x14) * iVar5;
    iVar4 = iVar2 - iVar5 * CharsInSheet;
    iVar5 = iVar4 / (int)(uint)*(ushort *)(FontData + 0x1a);
    *param_3 = (iVar4 - iVar5 * (uint)*(ushort *)(FontData + 0x1a)) *
               (uint)*(ushort *)(FontData + 0x10);
    *param_4 = iVar5 * (uint)*(ushort *)(FontData + 0x12);
    if (param_5 != (uint *)0x0) {
      *param_5 = (uint)*(byte *)(WidthTable + iVar2);
    }
  }
  return param_1;
}

byte * OSGetFontWidth(byte *param_1,uint *param_2)
{
  byte bVar1;
  short sVar3;
  int iVar2;
  byte *pbVar4;
  ushort uVar5;
  
  if (WidthTable == 0) {
    OSPanic(@111,0x328,@150);
  }
  bVar1 = *param_1;
  uVar5 = (ushort)bVar1;
  if (bVar1 != 0) {
    pbVar4 = param_1 + 1;
    sVar3 = OSGetFontEncode();
    if (((sVar3 == 1) && (((0x7f < bVar1 && (bVar1 < 0xa0)) || ((0xdf < bVar1 && (bVar1 < 0x100)))))
        ) && (*pbVar4 != 0)) {
      uVar5 = CONCAT11(bVar1,*pbVar4);
      pbVar4 = param_1 + 2;
    }
    param_1 = pbVar4;
    if (param_2 != (uint *)0x0) {
      iVar2 = GetFontCode(uVar5);
      *param_2 = (uint)*(byte *)(WidthTable + iVar2);
    }
  }
  return param_1;
}
