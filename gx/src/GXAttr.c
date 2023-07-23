/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __GXXfVtxSpecs(void)
{
  int iVar1;
  
  if (*(char *)(iRam00000000 + 0x41d) == '\0') {
    if (*(char *)(iRam00000000 + 0x41c) == '\0') {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  else {
    iVar1 = 2;
  }
  _DAT_cc008000 =
       ((uint)((*(uint *)(iRam00000000 + 0x18) & 3) != 0) +
        (uint)((*(uint *)(iRam00000000 + 0x18) >> 2 & 3) != 0) +
        (uint)((*(uint *)(iRam00000000 + 0x18) >> 4 & 3) != 0) +
        (uint)((*(uint *)(iRam00000000 + 0x18) >> 6 & 3) != 0) +
        (uint)((*(uint *)(iRam00000000 + 0x18) >> 8 & 3) != 0) +
        (uint)((*(uint *)(iRam00000000 + 0x18) >> 10 & 3) != 0) +
        (uint)((*(uint *)(iRam00000000 + 0x18) >> 0xc & 3) != 0) +
       (uint)((*(uint *)(iRam00000000 + 0x18) >> 0xe & 3) != 0)) * 0x10 |
       (uint)((*(uint *)(iRam00000000 + 0x14) >> 0xd & 3) != 0) +
       (uint)((*(uint *)(iRam00000000 + 0x14) >> 0xf & 3) != 0) | iVar1 << 2;
  *(uint *)(iRam00000000 + 0x28) = _DAT_cc008000;
  *(undefined *)(iRam00000000 + 0x10d0) = 1;
  *(undefined2 *)(iRam00000000 + 2) = 1;
  return;
}

void GXSetVtxDesc(int param_1,int param_2)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0xe2,@46);
  }
  if ((param_1 < 0) || (0x19 < param_1)) {
    OSPanic(...data.0,0xe5,@47);
  }
  if ((param_2 < 0) || (3 < param_2)) {
    OSPanic(...data.0,0xe7,@48);
  }
  SETVCDATTR(param_1,param_2);
  if ((*(char *)(iRam00000000 + 0x41c) == '\0') && (*(char *)(iRam00000000 + 0x41d) == '\0')) {
    *(uint *)(iRam00000000 + 0x14) = *(uint *)(iRam00000000 + 0x14) & 0xffffe7ff;
  }
  else {
    if ((*(uint *)(iRam00000000 + 0x418) & 0xfffffffc) != 0) {
      OSPanic(...data.0,0xed,@49);
    }
    *(uint *)(iRam00000000 + 0x14) =
         *(uint *)(iRam00000000 + 0x14) & 0xffffe7ff | *(int *)(iRam00000000 + 0x418) << 0xb;
  }
  *(uint *)(iRam00000000 + 0x4f4) = *(uint *)(iRam00000000 + 0x4f4) | 8;
  return;
}

void SETVCDATTR(undefined4 param_1,uint param_2)
{
  switch(param_1) {
  case 0:
    if ((param_2 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0xae,@49);
    }
    *(uint *)(iRam00000000 + 0x14) = *(uint *)(iRam00000000 + 0x14) & 0xfffffffe | param_2;
    break;
  case 1:
    if ((param_2 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0xaf,@49);
    }
    *(uint *)(iRam00000000 + 0x14) = *(uint *)(iRam00000000 + 0x14) & 0xfffffffd | param_2 << 1;
    break;
  case 2:
    if ((param_2 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0xb0,@49);
    }
    *(uint *)(iRam00000000 + 0x14) = *(uint *)(iRam00000000 + 0x14) & 0xfffffffb | param_2 << 2;
    break;
  case 3:
    if ((param_2 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0xb1,@49);
    }
    *(uint *)(iRam00000000 + 0x14) = *(uint *)(iRam00000000 + 0x14) & 0xfffffff7 | param_2 << 3;
    break;
  case 4:
    if ((param_2 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0xb2,@49);
    }
    *(uint *)(iRam00000000 + 0x14) = *(uint *)(iRam00000000 + 0x14) & 0xffffffef | param_2 << 4;
    break;
  case 5:
    if ((param_2 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0xb3,@49);
    }
    *(uint *)(iRam00000000 + 0x14) = *(uint *)(iRam00000000 + 0x14) & 0xffffffdf | param_2 << 5;
    break;
  case 6:
    if ((param_2 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0xb4,@49);
    }
    *(uint *)(iRam00000000 + 0x14) = *(uint *)(iRam00000000 + 0x14) & 0xffffffbf | param_2 << 6;
    break;
  case 7:
    if ((param_2 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0xb5,@49);
    }
    *(uint *)(iRam00000000 + 0x14) = *(uint *)(iRam00000000 + 0x14) & 0xffffff7f | param_2 << 7;
    break;
  case 8:
    if ((param_2 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0xb6,@49);
    }
    *(uint *)(iRam00000000 + 0x14) = *(uint *)(iRam00000000 + 0x14) & 0xfffffeff | param_2 << 8;
    break;
  case 9:
    if ((param_2 & 0xfffffffc) != 0) {
      OSPanic(...data.0,0xb7,@49);
    }
    *(uint *)(iRam00000000 + 0x14) = *(uint *)(iRam00000000 + 0x14) & 0xfffff9ff | param_2 << 9;
    break;
  case 10:
    if (param_2 == 0) {
      *(undefined *)(iRam00000000 + 0x41c) = 0;
    }
    else {
      *(undefined *)(iRam00000000 + 0x41c) = 1;
      *(undefined *)(iRam00000000 + 0x41d) = 0;
      *(uint *)(iRam00000000 + 0x418) = param_2;
    }
    break;
  case 0xb:
    if ((param_2 & 0xfffffffc) != 0) {
      OSPanic(...data.0,0xd0,@49);
    }
    *(uint *)(iRam00000000 + 0x14) = *(uint *)(iRam00000000 + 0x14) & 0xffff9fff | param_2 << 0xd;
    break;
  case 0xc:
    if ((param_2 & 0xfffffffc) != 0) {
      OSPanic(...data.0,0xd1,@49);
    }
    *(uint *)(iRam00000000 + 0x14) = *(uint *)(iRam00000000 + 0x14) & 0xfffe7fff | param_2 << 0xf;
    break;
  case 0xd:
    if ((param_2 & 0xfffffffc) != 0) {
      OSPanic(...data.0,0xd2,@49);
    }
    *(uint *)(iRam00000000 + 0x18) = *(uint *)(iRam00000000 + 0x18) & 0xfffffffc | param_2;
    break;
  case 0xe:
    if ((param_2 & 0xfffffffc) != 0) {
      OSPanic(...data.0,0xd3,@49);
    }
    *(uint *)(iRam00000000 + 0x18) = *(uint *)(iRam00000000 + 0x18) & 0xfffffff3 | param_2 << 2;
    break;
  case 0xf:
    if ((param_2 & 0xfffffffc) != 0) {
      OSPanic(...data.0,0xd4,@49);
    }
    *(uint *)(iRam00000000 + 0x18) = *(uint *)(iRam00000000 + 0x18) & 0xffffffcf | param_2 << 4;
    break;
  case 0x10:
    if ((param_2 & 0xfffffffc) != 0) {
      OSPanic(...data.0,0xd5,@49);
    }
    *(uint *)(iRam00000000 + 0x18) = *(uint *)(iRam00000000 + 0x18) & 0xffffff3f | param_2 << 6;
    break;
  case 0x11:
    if ((param_2 & 0xfffffffc) != 0) {
      OSPanic(...data.0,0xd6,@49);
    }
    *(uint *)(iRam00000000 + 0x18) = *(uint *)(iRam00000000 + 0x18) & 0xfffffcff | param_2 << 8;
    break;
  case 0x12:
    if ((param_2 & 0xfffffffc) != 0) {
      OSPanic(...data.0,0xd7,@49);
    }
    *(uint *)(iRam00000000 + 0x18) = *(uint *)(iRam00000000 + 0x18) & 0xfffff3ff | param_2 << 10;
    break;
  case 0x13:
    if ((param_2 & 0xfffffffc) != 0) {
      OSPanic(...data.0,0xd8,@49);
    }
    *(uint *)(iRam00000000 + 0x18) = *(uint *)(iRam00000000 + 0x18) & 0xffffcfff | param_2 << 0xc;
    break;
  case 0x14:
    if ((param_2 & 0xfffffffc) != 0) {
      OSPanic(...data.0,0xd9,@49);
    }
    *(uint *)(iRam00000000 + 0x18) = *(uint *)(iRam00000000 + 0x18) & 0xffff3fff | param_2 << 0xe;
    break;
  case 0x19:
    if (param_2 == 0) {
      *(undefined *)(iRam00000000 + 0x41d) = 0;
    }
    else {
      *(undefined *)(iRam00000000 + 0x41d) = 1;
      *(undefined *)(iRam00000000 + 0x41c) = 0;
      *(uint *)(iRam00000000 + 0x418) = param_2;
    }
  }
  return;
}

void GXSetVtxDescv(int *param_1)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x10b,@86);
  }
  if (param_1 == (int *)0x0) {
    OSPanic(...data.0,0x10c,@87);
  }
  for (; *param_1 != 0xff; param_1 = param_1 + 2) {
    if ((*param_1 < 0) || (0x19 < *param_1)) {
      OSPanic(...data.0,0x111,@47);
    }
    if ((param_1[1] < 0) || (3 < param_1[1])) {
      OSPanic(...data.0,0x114,@48);
    }
    SETVCDATTR(*param_1,param_1[1]);
  }
  if ((*(char *)(iRam00000000 + 0x41c) == '\0') && (*(char *)(iRam00000000 + 0x41d) == '\0')) {
    *(uint *)(iRam00000000 + 0x14) = *(uint *)(iRam00000000 + 0x14) & 0xffffe7ff;
  }
  else {
    if ((*(uint *)(iRam00000000 + 0x418) & 0xfffffffc) != 0) {
      OSPanic(...data.0,0x11d,@49);
    }
    *(uint *)(iRam00000000 + 0x14) =
         *(uint *)(iRam00000000 + 0x14) & 0xffffe7ff | *(int *)(iRam00000000 + 0x418) << 0xb;
  }
  *(uint *)(iRam00000000 + 0x4f4) = *(uint *)(iRam00000000 + 0x4f4) | 8;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __GXSetVCD(void)
{
  uint uVar1;
  uint uVar2;
  
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x18);
  __GXXfVtxSpecs();
  if (*(short *)(iRam00000000 + 4) != 0) {
    uVar2 = *(uint *)(iRam00000000 + 0x14);
    uVar1 = *(uint *)(iRam00000000 + 0x18);
    *(ushort *)(iRam00000000 + 6) =
         ((ushort)uVar2 & 1) + ((ushort)(uVar2 >> 1) & 1) + ((ushort)(uVar2 >> 2) & 1) +
         ((ushort)(uVar2 >> 3) & 1) + ((ushort)(uVar2 >> 4) & 1) + ((ushort)(uVar2 >> 5) & 1) +
         ((ushort)(uVar2 >> 6) & 1) + ((ushort)(uVar2 >> 7) & 1) + ((ushort)(uVar2 >> 8) & 1) +
         (ushort)*(byte *)((int)&tbl3$114 + (uVar2 >> 9 & 3)) +
         (ushort)*(byte *)((int)&tbl3$114 + (uVar2 >> 0xb & 3)) *
         ((ushort)*(byte *)(iRam00000000 + 0x41d) * 2 + 1) +
         (ushort)*(byte *)((int)&tbl1$112 + (uVar2 >> 0xd & 3)) +
         (ushort)*(byte *)((int)&tbl1$112 + (uVar2 >> 0xf & 3)) +
         (ushort)*(byte *)((int)&tbl2$113 + (uVar1 & 3)) +
         (ushort)*(byte *)((int)&tbl2$113 + (uVar1 >> 2 & 3)) +
         (ushort)*(byte *)((int)&tbl2$113 + (uVar1 >> 4 & 3)) +
         (ushort)*(byte *)((int)&tbl2$113 + (uVar1 >> 6 & 3)) +
         (ushort)*(byte *)((int)&tbl2$113 + (uVar1 >> 8 & 3)) +
         (ushort)*(byte *)((int)&tbl2$113 + (uVar1 >> 10 & 3)) +
         (ushort)*(byte *)((int)&tbl2$113 + (uVar1 >> 0xc & 3)) +
         (ushort)*(byte *)((int)&tbl2$113 + (uVar1 >> 0xe & 3));
  }
  return;
}

void GXGetVtxDesc(int param_1,uint *param_2)
{
  uint uVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x19b,@141);
  }
  if ((param_1 < 0) || (0x19 < param_1)) {
    OSPanic(...data.0,0x19d,@47);
  }
  switch(param_1) {
  case 0:
    uVar1 = *(uint *)(iRam00000000 + 0x14) & 1;
    break;
  case 1:
    uVar1 = *(uint *)(iRam00000000 + 0x14) >> 1 & 1;
    break;
  case 2:
    uVar1 = *(uint *)(iRam00000000 + 0x14) >> 2 & 1;
    break;
  case 3:
    uVar1 = *(uint *)(iRam00000000 + 0x14) >> 3 & 1;
    break;
  case 4:
    uVar1 = *(uint *)(iRam00000000 + 0x14) >> 4 & 1;
    break;
  case 5:
    uVar1 = *(uint *)(iRam00000000 + 0x14) >> 5 & 1;
    break;
  case 6:
    uVar1 = *(uint *)(iRam00000000 + 0x14) >> 6 & 1;
    break;
  case 7:
    uVar1 = *(uint *)(iRam00000000 + 0x14) >> 7 & 1;
    break;
  case 8:
    uVar1 = *(uint *)(iRam00000000 + 0x14) >> 8 & 1;
    break;
  case 9:
    uVar1 = *(uint *)(iRam00000000 + 0x14) >> 9 & 3;
    break;
  case 10:
    if (*(char *)(iRam00000000 + 0x41c) == '\0') {
      uVar1 = 0;
    }
    else {
      uVar1 = *(uint *)(iRam00000000 + 0x14) >> 0xb & 3;
    }
    break;
  case 0xb:
    uVar1 = *(uint *)(iRam00000000 + 0x14) >> 0xd & 3;
    break;
  case 0xc:
    uVar1 = *(uint *)(iRam00000000 + 0x14) >> 0xf & 3;
    break;
  case 0xd:
    uVar1 = *(uint *)(iRam00000000 + 0x18) & 3;
    break;
  case 0xe:
    uVar1 = *(uint *)(iRam00000000 + 0x18) >> 2 & 3;
    break;
  case 0xf:
    uVar1 = *(uint *)(iRam00000000 + 0x18) >> 4 & 3;
    break;
  case 0x10:
    uVar1 = *(uint *)(iRam00000000 + 0x18) >> 6 & 3;
    break;
  case 0x11:
    uVar1 = *(uint *)(iRam00000000 + 0x18) >> 8 & 3;
    break;
  case 0x12:
    uVar1 = *(uint *)(iRam00000000 + 0x18) >> 10 & 3;
    break;
  case 0x13:
    uVar1 = *(uint *)(iRam00000000 + 0x18) >> 0xc & 3;
    break;
  case 0x14:
    uVar1 = *(uint *)(iRam00000000 + 0x18) >> 0xe & 3;
    break;
  default:
    uVar1 = 0;
    break;
  case 0x19:
    if (*(char *)(iRam00000000 + 0x41d) == '\0') {
      uVar1 = 0;
    }
    else {
      uVar1 = *(uint *)(iRam00000000 + 0x14) >> 0xb & 3;
    }
  }
  *param_2 = uVar1;
  return;
}

void GXGetVtxDescv(int param_1)
{
  int iVar1;
  
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x1d0,@149);
  }
  if (param_1 == 0) {
    OSPanic(...data.0,0x1d2,@87);
  }
  for (iVar1 = 0; iVar1 < 0x1a; iVar1 = iVar1 + 1) {
    *(int *)(param_1 + iVar1 * 8) = iVar1;
    GXGetVtxDesc(iVar1,param_1 + iVar1 * 8 + 4);
  }
  *(undefined4 *)(param_1 + iVar1 * 8) = 0xff;
  return;
}

void GXClearVtxDesc(void)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x1e9,@151);
  }
  *(undefined4 *)(iRam00000000 + 0x14) = 0;
  *(uint *)(iRam00000000 + 0x14) = *(uint *)(iRam00000000 + 0x14) & 0xfffff9ff | 0x200;
  *(undefined4 *)(iRam00000000 + 0x18) = 0;
  *(undefined *)(iRam00000000 + 0x41c) = 0;
  *(undefined *)(iRam00000000 + 0x41d) = 0;
  *(uint *)(iRam00000000 + 0x4f4) = *(uint *)(iRam00000000 + 0x4f4) | 8;
  return;
}

void GXSetVtxAttrFmt(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,uint param_5)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x268,@171);
  }
  if (7 < (int)param_1) {
    OSPanic(...data.0,0x269,@172);
  }
  if ((param_2 < 9) || (0x1a < param_2)) {
    OSPanic(...data.0,0x26b,@173);
  }
  if (0x1f < (param_5 & 0xff)) {
    OSPanic(...data.0,0x26c,@174);
  }
  SETVAT(iRam00000000 + param_1 * 4 + 0x1c,iRam00000000 + param_1 * 4 + 0x3c,
         iRam00000000 + param_1 * 4 + 0x5c,param_2,param_3,param_4,param_5);
  *(uint *)(iRam00000000 + 0x4f4) = *(uint *)(iRam00000000 + 0x4f4) | 0x10;
  *(byte *)(iRam00000000 + 0x4f2) = *(byte *)(iRam00000000 + 0x4f2) | (byte)(1 << (param_1 & 0x3f));
  return;
}

void SETVAT(uint *param_1,uint *param_2,uint *param_3,undefined4 param_4,uint param_5,uint param_6,
           uint param_7)
{
  switch(param_4) {
  case 9:
    if ((param_5 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0x215,@49);
    }
    *param_1 = *param_1 & 0xfffffffe | param_5;
    if ((param_6 & 0xfffffff8) != 0) {
      OSPanic(...data.0,0x216,@49);
    }
    *param_1 = *param_1 & 0xfffffff1 | param_6 << 1;
    if ((param_7 & 0xe0) != 0) {
      OSPanic(...data.0,0x217,@49);
    }
    *param_1 = *param_1 & 0xfffffe0f | (param_7 & 0xff) << 4;
    break;
  case 10:
  case 0x19:
    if ((param_6 & 0xfffffff8) != 0) {
      OSPanic(...data.0,0x21f,@49);
    }
    *param_1 = *param_1 & 0xffffe3ff | param_6 << 10;
    if (param_5 == 2) {
      *param_1 = *param_1 & 0xfffffdff | 0x200;
      *param_1 = *param_1 & 0x7fffffff | 0x80000000;
    }
    else {
      if ((param_5 & 0xfffffffe) != 0) {
        OSPanic(...data.0,0x225,@49);
      }
      *param_1 = *param_1 & 0xfffffdff | param_5 << 9;
      *param_1 = *param_1 & 0x7fffffff;
    }
    break;
  case 0xb:
    if ((param_5 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0x22b,@49);
    }
    *param_1 = *param_1 & 0xffffdfff | param_5 << 0xd;
    if ((param_6 & 0xfffffff8) != 0) {
      OSPanic(...data.0,0x22c,@49);
    }
    *param_1 = *param_1 & 0xfffe3fff | param_6 << 0xe;
    break;
  case 0xc:
    if ((param_5 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0x22f,@49);
    }
    *param_1 = *param_1 & 0xfffdffff | param_5 << 0x11;
    if ((param_6 & 0xfffffff8) != 0) {
      OSPanic(...data.0,0x230,@49);
    }
    *param_1 = *param_1 & 0xffe3ffff | param_6 << 0x12;
    break;
  case 0xd:
    if ((param_5 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0x233,@49);
    }
    *param_1 = *param_1 & 0xffdfffff | param_5 << 0x15;
    if ((param_6 & 0xfffffff8) != 0) {
      OSPanic(...data.0,0x234,@49);
    }
    *param_1 = *param_1 & 0xfe3fffff | param_6 << 0x16;
    if ((param_7 & 0xe0) != 0) {
      OSPanic(...data.0,0x235,@49);
    }
    *param_1 = *param_1 & 0xc1ffffff | param_7 << 0x19;
    break;
  case 0xe:
    if ((param_5 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0x238,@49);
    }
    *param_2 = *param_2 & 0xfffffffe | param_5;
    if ((param_6 & 0xfffffff8) != 0) {
      OSPanic(...data.0,0x239,@49);
    }
    *param_2 = *param_2 & 0xfffffff1 | param_6 << 1;
    if ((param_7 & 0xe0) != 0) {
      OSPanic(...data.0,0x23a,@49);
    }
    *param_2 = *param_2 & 0xfffffe0f | (param_7 & 0xff) << 4;
    break;
  case 0xf:
    if ((param_5 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0x23d,@49);
    }
    *param_2 = *param_2 & 0xfffffdff | param_5 << 9;
    if ((param_6 & 0xfffffff8) != 0) {
      OSPanic(...data.0,0x23e,@49);
    }
    *param_2 = *param_2 & 0xffffe3ff | param_6 << 10;
    if ((param_7 & 0xe0) != 0) {
      OSPanic(...data.0,0x23f,@49);
    }
    *param_2 = *param_2 & 0xfffc1fff | (param_7 & 0xff) << 0xd;
    break;
  case 0x10:
    if ((param_5 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0x242,@49);
    }
    *param_2 = *param_2 & 0xfffbffff | param_5 << 0x12;
    if ((param_6 & 0xfffffff8) != 0) {
      OSPanic(...data.0,0x243,@49);
    }
    *param_2 = *param_2 & 0xffc7ffff | param_6 << 0x13;
    if ((param_7 & 0xe0) != 0) {
      OSPanic(...data.0,0x244,@49);
    }
    *param_2 = *param_2 & 0xf83fffff | (param_7 & 0xff) << 0x16;
    break;
  case 0x11:
    if ((param_5 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0x247,@49);
    }
    *param_2 = *param_2 & 0xf7ffffff | param_5 << 0x1b;
    if ((param_6 & 0xfffffff8) != 0) {
      OSPanic(...data.0,0x248,@49);
    }
    *param_2 = *param_2 & 0x8fffffff | param_6 << 0x1c;
    if ((param_7 & 0xe0) != 0) {
      OSPanic(...data.0,0x249,@49);
    }
    *param_3 = *param_3 & 0xffffffe0 | param_7 & 0xff;
    break;
  case 0x12:
    if ((param_5 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0x24c,@49);
    }
    *param_3 = *param_3 & 0xffffffdf | param_5 << 5;
    if ((param_6 & 0xfffffff8) != 0) {
      OSPanic(...data.0,0x24d,@49);
    }
    *param_3 = *param_3 & 0xfffffe3f | param_6 << 6;
    if ((param_7 & 0xe0) != 0) {
      OSPanic(...data.0,0x24e,@49);
    }
    *param_3 = *param_3 & 0xffffc1ff | (param_7 & 0xff) << 9;
    break;
  case 0x13:
    if ((param_5 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0x251,@49);
    }
    *param_3 = *param_3 & 0xffffbfff | param_5 << 0xe;
    if ((param_6 & 0xfffffff8) != 0) {
      OSPanic(...data.0,0x252,@49);
    }
    *param_3 = *param_3 & 0xfffc7fff | param_6 << 0xf;
    if ((param_7 & 0xe0) != 0) {
      OSPanic(...data.0,0x253,@49);
    }
    *param_3 = *param_3 & 0xff83ffff | (param_7 & 0xff) << 0x12;
    break;
  case 0x14:
    if ((param_5 & 0xfffffffe) != 0) {
      OSPanic(...data.0,0x256,@49);
    }
    *param_3 = *param_3 & 0xff7fffff | param_5 << 0x17;
    if ((param_6 & 0xfffffff8) != 0) {
      OSPanic(...data.0,599,@49);
    }
    *param_3 = *param_3 & 0xf8ffffff | param_6 << 0x18;
    if ((param_7 & 0xe0) != 0) {
      OSPanic(...data.0,600,@49);
    }
    *param_3 = *param_3 & 0x7ffffff | param_7 << 0x1b;
  }
  return;
}

void GXSetVtxAttrFmtv(uint param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x291,@197);
  }
  if (param_2 == (int *)0x0) {
    OSPanic(...data.0,0x292,@198);
  }
  if (7 < (int)param_1) {
    OSPanic(...data.0,0x293,@172);
  }
  iVar3 = iRam00000000 + param_1 * 4 + 0x1c;
  iVar2 = iRam00000000 + param_1 * 4 + 0x3c;
  iVar1 = iRam00000000 + param_1 * 4 + 0x5c;
  for (; *param_2 != 0xff; param_2 = param_2 + 4) {
    if ((*param_2 < 9) || (0x1a < *param_2)) {
      OSPanic(...data.0,0x29c,@173);
    }
    if (0x1f < *(byte *)(param_2 + 3)) {
      OSPanic(...data.0,0x29d,@174);
    }
    SETVAT(iVar3,iVar2,iVar1,*param_2,param_2[1],param_2[2],*(undefined *)(param_2 + 3));
  }
  *(uint *)(iRam00000000 + 0x4f4) = *(uint *)(iRam00000000 + 0x4f4) | 0x10;
  *(byte *)(iRam00000000 + 0x4f2) = *(byte *)(iRam00000000 + 0x4f2) | (byte)(1 << (param_1 & 0x3f));
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __GXSetVAT(void)
{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (7 < (uVar1 & 0xff)) break;
    if (((uint)*(byte *)(iRam00000000 + 0x4f2) & 1 << (uVar1 & 0x3f)) != 0) {
      _DAT_cc008000 = *(undefined4 *)(iRam00000000 + (uVar1 & 0xff) * 4 + 0x5c);
    }
    uVar1 = uVar1 + 1;
  }
  *(undefined *)(iRam00000000 + 0x4f2) = 0;
  return;
}

void GXGetVtxAttrFmt(int param_1,undefined4 param_2,uint *param_3,uint *param_4,byte *param_5)
{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x2e5,@259);
  }
  if (7 < param_1) {
    OSPanic(...data.0,0x2e6,@172);
  }
  puVar3 = (uint *)(iRam00000000 + param_1 * 4 + 0x1c);
  puVar2 = (uint *)(iRam00000000 + param_1 * 4 + 0x3c);
  puVar1 = (uint *)(iRam00000000 + param_1 * 4 + 0x5c);
  switch(param_2) {
  case 9:
    *param_3 = *puVar3 & 1;
    *param_4 = *puVar3 >> 1 & 7;
    *param_5 = (byte)(*puVar3 >> 4) & 0x1f;
    break;
  case 10:
  case 0x19:
    *param_3 = *puVar3 >> 9 & 1;
    if ((*param_3 == 1) && ((int)*puVar3 < 0)) {
      *param_3 = 2;
    }
    *param_4 = *puVar3 >> 10 & 7;
    *param_5 = 0;
    break;
  case 0xb:
    *param_3 = *puVar3 >> 0xd & 1;
    *param_4 = *puVar3 >> 0xe & 7;
    *param_5 = 0;
    break;
  case 0xc:
    *param_3 = *puVar3 >> 0x11 & 1;
    *param_4 = *puVar3 >> 0x12 & 7;
    *param_5 = 0;
    break;
  case 0xd:
    *param_3 = *puVar3 >> 0x15 & 1;
    *param_4 = *puVar3 >> 0x16 & 7;
    *param_5 = (byte)(*puVar3 >> 0x19) & 0x1f;
    break;
  case 0xe:
    *param_3 = *puVar2 & 1;
    *param_4 = *puVar2 >> 1 & 7;
    *param_5 = (byte)(*puVar2 >> 4) & 0x1f;
    break;
  case 0xf:
    *param_3 = *puVar2 >> 9 & 1;
    *param_4 = *puVar2 >> 10 & 7;
    *param_5 = (byte)(*puVar2 >> 0xd) & 0x1f;
    break;
  case 0x10:
    *param_3 = *puVar2 >> 0x12 & 1;
    *param_4 = *puVar2 >> 0x13 & 7;
    *param_5 = (byte)(*puVar2 >> 0x16) & 0x1f;
    break;
  case 0x11:
    *param_3 = *puVar2 >> 0x1b & 1;
    *param_4 = *puVar2 >> 0x1c & 7;
    *param_5 = (byte)*puVar1 & 0x1f;
    break;
  case 0x12:
    *param_3 = *puVar1 >> 5 & 1;
    *param_4 = *puVar1 >> 6 & 7;
    *param_5 = (byte)(*puVar1 >> 9) & 0x1f;
    break;
  case 0x13:
    *param_3 = *puVar1 >> 0xe & 1;
    *param_4 = *puVar1 >> 0xf & 7;
    *param_5 = (byte)(*puVar1 >> 0x12) & 0x1f;
    break;
  case 0x14:
    *param_3 = *puVar1 >> 0x17 & 1;
    *param_4 = *puVar1 >> 0x18 & 7;
    *param_5 = (byte)(*puVar1 >> 0x1b);
    break;
  default:
    *param_3 = 1;
    *param_4 = 0;
    *param_5 = 0;
  }
  return;
}

void GXGetVtxAttrFmtv(int param_1,int *param_2)
{
  int iVar1;
  
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x346,@267);
  }
  if (param_2 == (int *)0x0) {
    OSPanic(...data.0,0x347,@198);
  }
  if (7 < param_1) {
    OSPanic(...data.0,0x348,@172);
  }
  for (iVar1 = 9; iVar1 < 0x1a; iVar1 = iVar1 + 1) {
    *param_2 = iVar1;
    GXGetVtxAttrFmt(param_1,iVar1,param_2 + 1,param_2 + 2,param_2 + 3);
    param_2 = param_2 + 4;
  }
  *param_2 = 0xff;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetArray(int param_1,uint param_2,uint param_3)
{
  int iVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x365,@291);
  }
  if (param_1 == 0x19) {
    param_1 = 10;
  }
  if ((param_1 < 9) || (0x18 < param_1)) {
    OSPanic(...data.0,0x368,@292);
  }
  iVar1 = param_1 + -0x15;
  if ((-1 < iVar1) && (iVar1 < 4)) {
    *(uint *)(iRam00000000 + iVar1 * 4 + 0x88) = param_2 & 0x3fffffff;
  }
  _DAT_cc008000 = param_3 & 0xff;
  param_1 = param_1 + -0x15;
  if ((-1 < param_1) && (param_1 < 4)) {
    *(uint *)(iRam00000000 + param_1 * 4 + 0x98) = param_3 & 0xff;
  }
  return;
}

void GXInvalidateVtxCache(void)
{
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x37e,@294);
  }
  DAT_cc008000 = 0x48;
  return;
}

/* WARNING: Removing unreachable block (ram,0x000120ac) */
/* WARNING: Removing unreachable block (ram,0x0001218c) */
/* WARNING: Removing unreachable block (ram,0x000121bc) */
/* WARNING: Removing unreachable block (ram,0x0001224c) */
/* WARNING: Removing unreachable block (ram,0x0001210c) */
/* WARNING: Removing unreachable block (ram,0x000120d8) */
/* WARNING: Removing unreachable block (ram,0x00012138) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetTexCoordGen2(int param_1,int param_2,int param_3,uint param_4,uint param_5,int param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x3a8,@350);
  }
  if (7 < param_1) {
    OSPanic(...data.0,0x3a9,@351);
  }
  iVar1 = 0;
  iVar2 = 5;
  switch(param_3) {
  case 0:
    iVar2 = 0;
    iVar1 = 1;
    break;
  case 1:
    iVar2 = 1;
    iVar1 = 1;
    break;
  case 2:
    iVar2 = 3;
    iVar1 = 1;
    break;
  case 3:
    iVar2 = 4;
    iVar1 = 1;
    break;
  case 4:
    iVar2 = 5;
    break;
  case 5:
    iVar2 = 6;
    break;
  case 6:
    iVar2 = 7;
    break;
  case 7:
    iVar2 = 8;
    break;
  case 8:
    iVar2 = 9;
    break;
  case 9:
    iVar2 = 10;
    break;
  case 10:
    iVar2 = 0xb;
    break;
  case 0xb:
    iVar2 = 0xc;
    break;
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    break;
  case 0xf:
    break;
  case 0x10:
    break;
  case 0x11:
    break;
  case 0x12:
    break;
  case 0x13:
    iVar2 = 2;
    break;
  case 0x14:
    iVar2 = 2;
    break;
  default:
    OSPanic(...data.0,0x3c5,@352);
  }
  if (param_2 == 1) {
    uVar3 = iVar1 << 2 | iVar2 << 7;
    goto LAB_000122a8;
  }
  if (param_2 < 1) {
    if (-1 < param_2) {
      uVar3 = iVar1 << 2 | 2U | iVar2 << 7;
      goto LAB_000122a8;
    }
  }
  else {
    if (param_2 == 10) {
      if (param_3 == 0x13) {
        uVar3 = iVar1 << 2 | 0x20;
      }
      else {
        uVar3 = iVar1 << 2 | 0x30;
      }
      uVar3 = uVar3 | 0x100;
      goto LAB_000122a8;
    }
    if (param_2 < 10) {
      if ((param_3 < 0xc) || (0x12 < param_3)) {
        OSPanic(...data.0,0x3e5,@353);
      }
      if ((param_3 - 0xcU & 0xfffffff8) != 0) {
        OSPanic(...data.0,0x3ea,@49);
      }
      if ((param_2 - 2U & 0xfffffff8) != 0) {
        OSPanic(...data.0,0x3eb,@49);
      }
      uVar3 = iVar1 << 2 | 0x10U | iVar2 << 7 | (param_3 + -0xc) * 0x1000 & 0xfffc7000U |
              (param_2 + -2) * 0x8000;
      goto LAB_000122a8;
    }
  }
  OSPanic(...data.0,0x3fb,@354);
LAB_000122a8:
  iVar1 = param_1 + 0x40;
  _DAT_cc008000 = uVar3;
  if ((-1 < iVar1) && (iVar1 < 0x50)) {
    *(uint *)(iRam00000000 + iVar1 * 4 + 8) = uVar3;
    *(undefined *)(iRam00000000 + param_1 + 0x1108) = 1;
  }
  if ((param_6 - 0x40U & 0xffffffc0) != 0) {
    OSPanic(...data.0,0x40e,@49);
  }
  if ((param_5 & 0xfe) != 0) {
    OSPanic(...data.0,0x40f,@49);
  }
  _DAT_cc008000 = param_6 - 0x40U & 0xfffffeff | (param_5 & 0xff) << 8;
  iVar1 = param_1 + 0x50;
  if ((-1 < iVar1) && (iVar1 < 0x50)) {
    *(uint *)(iRam00000000 + iVar1 * 4 + 8) = _DAT_cc008000;
    *(undefined *)(iRam00000000 + param_1 + 0x1118) = 1;
  }
  switch(param_1) {
  case 0:
    if ((param_4 & 0xffffffc0) != 0) {
      OSPanic(...data.0,0x418,@49);
    }
    *(uint *)(iRam00000000 + 0x80) = *(uint *)(iRam00000000 + 0x80) & 0xfffff03f | param_4 << 6;
    break;
  case 1:
    if ((param_4 & 0xffffffc0) != 0) {
      OSPanic(...data.0,0x419,@49);
    }
    *(uint *)(iRam00000000 + 0x80) = *(uint *)(iRam00000000 + 0x80) & 0xfffc0fff | param_4 << 0xc;
    break;
  case 2:
    if ((param_4 & 0xffffffc0) != 0) {
      OSPanic(...data.0,0x41a,@49);
    }
    *(uint *)(iRam00000000 + 0x80) = *(uint *)(iRam00000000 + 0x80) & 0xff03ffff | param_4 << 0x12;
    break;
  case 3:
    if ((param_4 & 0xffffffc0) != 0) {
      OSPanic(...data.0,0x41b,@49);
    }
    *(uint *)(iRam00000000 + 0x80) = *(uint *)(iRam00000000 + 0x80) & 0xc0ffffff | param_4 << 0x18;
    break;
  case 4:
    if ((param_4 & 0xffffffc0) != 0) {
      OSPanic(...data.0,0x41c,@49);
    }
    *(uint *)(iRam00000000 + 0x84) = *(uint *)(iRam00000000 + 0x84) & 0xffffffc0 | param_4;
    break;
  case 5:
    if ((param_4 & 0xffffffc0) != 0) {
      OSPanic(...data.0,0x41d,@49);
    }
    *(uint *)(iRam00000000 + 0x84) = *(uint *)(iRam00000000 + 0x84) & 0xfffff03f | param_4 << 6;
    break;
  case 6:
    if ((param_4 & 0xffffffc0) != 0) {
      OSPanic(...data.0,0x41e,@49);
    }
    *(uint *)(iRam00000000 + 0x84) = *(uint *)(iRam00000000 + 0x84) & 0xfffc0fff | param_4 << 0xc;
    break;
  default:
    if ((param_4 & 0xffffffc0) != 0) {
      OSPanic(...data.0,0x41f,@49);
    }
    *(uint *)(iRam00000000 + 0x84) = *(uint *)(iRam00000000 + 0x84) & 0xff03ffff | param_4 << 0x12;
  }
  __GXSetMatrixIndex(param_1 + 1);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetNumTexGens(uint param_1)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x431,@361);
  }
  if ((param_1 & 0xf0) != 0) {
    OSPanic(...data.0,0x433,@49);
  }
  *(uint *)(iRam00000000 + 0x204) = *(uint *)(iRam00000000 + 0x204) & 0xfffffff0 | param_1 & 0xff;
  _DAT_cc008000 = param_1 & 0xff;
  *(uint *)(iRam00000000 + 0x104) = param_1 & 0xff;
  *(undefined *)(iRam00000000 + 0x1107) = 1;
  *(uint *)(iRam00000000 + 0x4f4) = *(uint *)(iRam00000000 + 0x4f4) | 4;
  return;
}
