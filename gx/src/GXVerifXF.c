/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void CountTextureTypes(void)
{
  byte bVar1;
  code *pcVar2;
  uint uVar3;
  
  numRegularTextures = 0;
  numBumpmapTextures = 0;
  numColor0Textures = 0;
  numColor1Textures = 0;
  for (pcVar2 = (code *)0x0; pcVar2 < ppcRam00000000[0x41]; pcVar2 = pcVar2 + 1) {
    bVar1 = *(byte *)((int)ppcRam00000000 + (int)(pcVar2 + 0x40) * 4 + 0xb) >> 4;
    uVar3 = bVar1 & 7;
    if ((bVar1 & 7) == 0) {
      numRegularTextures = numRegularTextures + 1;
    }
    else if (uVar3 == 1) {
      numBumpmapTextures = numBumpmapTextures + 1;
    }
    else if (uVar3 == 2) {
      numColor0Textures = numColor0Textures + 1;
    }
    else if (uVar3 == 3) {
      numColor1Textures = numColor1Textures + 1;
    }
    else if (_DAT_000150d0 <= (int)ppcRam00000000[1]) {
      sprintf(&__gxvDummyStr,_DAT_000150d8,uVar3,pcVar2);
      (**ppcRam00000000)(_DAT_000150d0,0x34,&__gxvDummyStr);
    }
  }
  numColorTextures = numColor0Textures + numColor1Textures;
  return;
}

void InitializeXFVerifyData(void)
{
  CountTextureTypes();
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void CheckDirty(int param_1,undefined4 param_2)
{
  if ((*(char *)((int)ppcRam00000000 + param_1 + 200) == '\0') &&
     (_DAT_000150d4 <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_DAT_000150dc,param_1,param_2);
    (**ppcRam00000000)(_DAT_000150d4,0x35,&__gxvDummyStr);
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void CheckClean(int param_1,undefined4 param_2)
{
  if ((*(char *)((int)ppcRam00000000 + param_1 + 200) != '\0') &&
     (_DAT_000150d8 <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_DAT_000150e0,param_1,param_2);
    (**ppcRam00000000)(_DAT_000150d8,0x36,&__gxvDummyStr);
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void CheckCTGColors(void)
{
  if ((2 < (*(byte *)((int)ppcRam00000000 + 0x2f) & 3)) && (_DAT_000150e0 <= (int)ppcRam00000000[1])
     ) {
    sprintf(&__gxvDummyStr,_DAT_000150e8,*(byte *)((int)ppcRam00000000 + 0x2f) & 3);
    (**ppcRam00000000)(_DAT_000150e0,0x38,&__gxvDummyStr);
  }
  return;
}

bool __GXVertexPacketHas(undefined4 param_1)
{
  bool bVar1;
  
  switch(param_1) {
  case 0:
    return (*(uint *)(iRam00000000 + 0x14) & 1) != 0;
  case 1:
    return (*(uint *)(iRam00000000 + 0x14) >> 1 & 1) != 0;
  case 2:
    return (*(uint *)(iRam00000000 + 0x14) >> 2 & 1) != 0;
  case 3:
    return (*(uint *)(iRam00000000 + 0x14) >> 3 & 1) != 0;
  case 4:
    return (*(uint *)(iRam00000000 + 0x14) >> 4 & 1) != 0;
  case 5:
    return (*(uint *)(iRam00000000 + 0x14) >> 5 & 1) != 0;
  case 6:
    return (*(uint *)(iRam00000000 + 0x14) >> 6 & 1) != 0;
  case 7:
    return (*(uint *)(iRam00000000 + 0x14) >> 7 & 1) != 0;
  case 8:
    return (*(uint *)(iRam00000000 + 0x14) >> 8 & 1) != 0;
  case 9:
    return (*(uint *)(iRam00000000 + 0x14) >> 9 & 3) != 0;
  case 10:
    if (*(char *)(iRam00000000 + 0x41c) == '\0') {
      bVar1 = false;
    }
    else {
      bVar1 = (*(uint *)(iRam00000000 + 0x14) >> 0xb & 3) != 0;
    }
    break;
  case 0xb:
    return (*(uint *)(iRam00000000 + 0x14) >> 0xd & 3) != 0;
  case 0xc:
    return (*(uint *)(iRam00000000 + 0x14) >> 0xf & 3) != 0;
  case 0xd:
    return (*(uint *)(iRam00000000 + 0x18) & 3) != 0;
  case 0xe:
    return (*(uint *)(iRam00000000 + 0x18) >> 2 & 3) != 0;
  case 0xf:
    return (*(uint *)(iRam00000000 + 0x18) >> 4 & 3) != 0;
  case 0x10:
    return (*(uint *)(iRam00000000 + 0x18) >> 6 & 3) != 0;
  case 0x11:
    return (*(uint *)(iRam00000000 + 0x18) >> 8 & 3) != 0;
  case 0x12:
    return (*(uint *)(iRam00000000 + 0x18) >> 10 & 3) != 0;
  case 0x13:
    return (*(uint *)(iRam00000000 + 0x18) >> 0xc & 3) != 0;
  case 0x14:
    return (*(uint *)(iRam00000000 + 0x18) >> 0xe & 3) != 0;
  default:
    return false;
  case 0x19:
    if (*(char *)(iRam00000000 + 0x41d) == '\0') {
      bVar1 = false;
    }
    else {
      bVar1 = (*(uint *)(iRam00000000 + 0x14) >> 0xb & 3) != 0;
    }
    return bVar1;
  }
  return bVar1;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void CheckVertexPacket(void)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  cVar1 = __GXVertexPacketHas(9);
  if (cVar1 == '\0') {
    if (_DAT_000150e4 <= (int)ppcRam00000000[1]) {
      (**ppcRam00000000)(_DAT_000150e4,0x39,_DAT_000150ec);
    }
  }
  if ((*(byte *)((int)ppcRam00000000 + 0x2b) & 3) == 0) {
    cVar1 = __GXVertexPacketHas(0xb);
    if (cVar1 == '\0') {
      cVar1 = __GXVertexPacketHas(0xc);
      if (cVar1 == '\0') goto LAB_000109ac;
    }
    if (_DAT_000150e8 <= (int)ppcRam00000000[1]) {
      (**ppcRam00000000)(_DAT_000150e8,0x3a,_DAT_000150f0);
    }
  }
  else if ((*(byte *)((int)ppcRam00000000 + 0x2b) & 3) == 1) {
    cVar1 = __GXVertexPacketHas(0xb);
    if (cVar1 == '\0') {
      if (_DAT_000150ec <= (int)ppcRam00000000[1]) {
        (**ppcRam00000000)(_DAT_000150ec,0x3b,_DAT_000150f4);
      }
    }
    cVar1 = __GXVertexPacketHas(0xc);
    if (cVar1 != '\0') {
      if (_DAT_000150f0 <= (int)ppcRam00000000[1]) {
        (**ppcRam00000000)(_DAT_000150f0,0x3c,_DAT_000150f8);
      }
    }
  }
  else if ((*(byte *)((int)ppcRam00000000 + 0x2b) & 3) == 2) {
    cVar1 = __GXVertexPacketHas(0xb);
    if (cVar1 == '\0') {
      if (_DAT_000150f4 <= (int)ppcRam00000000[1]) {
        (**ppcRam00000000)(_DAT_000150f4,0x3d,_DAT_000150fc);
      }
    }
    cVar1 = __GXVertexPacketHas(0xc);
    if (cVar1 == '\0') {
      if (_DAT_000150f8 <= (int)ppcRam00000000[1]) {
        (**ppcRam00000000)(_DAT_000150f8,0x3e,_DAT_00015100);
      }
    }
  }
  else if (_DAT_000150fc <= (int)ppcRam00000000[1]) {
    sprintf(&__gxvDummyStr,_DAT_00015104,*(byte *)((int)ppcRam00000000 + 0x2b) & 3);
    (**ppcRam00000000)(_DAT_000150fc,0x3f,&__gxvDummyStr);
  }
LAB_000109ac:
  if ((*(byte *)((int)ppcRam00000000 + 0x2b) >> 2 & 3) == 0) {
    cVar1 = __GXVertexPacketHas(10);
    if (cVar1 != '\0') {
      if (_DAT_00015100 <= (int)ppcRam00000000[1]) {
        (**ppcRam00000000)(_DAT_00015100,0x40,_DAT_00015108);
      }
    }
    cVar1 = __GXVertexPacketHas(0x19);
    if ((cVar1 != '\0') && ((int)_DAT_00015104 <= (int)ppcRam00000000[1])) {
      (**ppcRam00000000)(_DAT_00015104,0x41,_DAT_0001510c);
    }
  }
  else if ((*(byte *)((int)ppcRam00000000 + 0x2b) >> 2 & 3) == 1) {
    cVar1 = __GXVertexPacketHas(10);
    if (cVar1 == '\0') {
      if (_DAT_00015108 <= (int)ppcRam00000000[1]) {
        (**ppcRam00000000)(_DAT_00015108,0x42,_DAT_00015110);
      }
    }
    cVar1 = __GXVertexPacketHas(0x19);
    if ((cVar1 != '\0') && (_DAT_0001510c <= (int)ppcRam00000000[1])) {
      (**ppcRam00000000)(_DAT_0001510c,0x43,_DAT_00015114);
    }
  }
  else if ((*(byte *)((int)ppcRam00000000 + 0x2b) >> 2 & 3) == 2) {
    cVar1 = __GXVertexPacketHas(10);
    if (cVar1 != '\0') {
      if (_DAT_00015110 <= (int)ppcRam00000000[1]) {
        (**ppcRam00000000)(_DAT_00015110,0x44,_DAT_00015118);
      }
    }
    cVar1 = __GXVertexPacketHas(0x19);
    if ((cVar1 == '\0') && (_DAT_00015114 <= (int)ppcRam00000000[1])) {
      (**ppcRam00000000)(_DAT_00015114,0x45,_DAT_0001511c);
    }
  }
  else if (_DAT_00015118 <= (int)ppcRam00000000[1]) {
    sprintf(&__gxvDummyStr,_DAT_00015120,*(byte *)((int)ppcRam00000000 + 0x2b) >> 2 & 3);
    (**ppcRam00000000)(_DAT_00015118,0x46,&__gxvDummyStr);
  }
  uVar3 = 0;
  for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1) {
    cVar1 = __GXVertexPacketHas(*(undefined4 *)(TextureEnums + uVar2 * 4));
    if (cVar1 != '\0') {
      uVar3 = uVar3 + 1;
    }
  }
  if ((uVar3 != *(byte *)((int)ppcRam00000000 + 0x2b) >> 4) &&
     (_DAT_0001511c <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_DAT_00015124,*(byte *)((int)ppcRam00000000 + 0x2b) >> 4,uVar3);
    (**ppcRam00000000)(_DAT_0001511c,0x47,&__gxvDummyStr);
  }
  return;
}

/* WARNING: Removing unreachable block (ram,0x00010d88) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void CheckSourceRows(void)
{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  
  for (uVar3 = 0; uVar3 < numRegularTextures; uVar3 = uVar3 + 1) {
    uVar1 = *(ushort *)((int)ppcRam00000000 + (uVar3 + 0x40) * 4 + 10) >> 7 & 0x1f;
    if (uVar1 == 2) {
      cVar2 = __GXVertexPacketHas(0xb);
      if ((cVar2 == '\0') && ((int)_DAT_00015128 <= (int)ppcRam00000000[1])) {
        sprintf(&__gxvDummyStr,_DAT_00015130,uVar3);
        (**ppcRam00000000)(_DAT_00015128,0x4a,&__gxvDummyStr);
      }
      cVar2 = __GXVertexPacketHas(0xc);
      if ((cVar2 == '\0') && ((int)_DAT_0001512c <= (int)ppcRam00000000[1])) {
        sprintf(&__gxvDummyStr,_DAT_00015134,uVar3);
        (**ppcRam00000000)(_DAT_0001512c,0x4b,&__gxvDummyStr);
      }
    }
    else if (uVar1 < 2) {
      if (uVar1 == 0) {
        cVar2 = __GXVertexPacketHas(9);
        if ((cVar2 == '\0') && (_DAT_00015120 <= (int)ppcRam00000000[1])) {
          sprintf(&__gxvDummyStr,_DAT_00015128,uVar3);
          (**ppcRam00000000)(_DAT_00015120,0x48,&__gxvDummyStr);
        }
      }
      else {
        cVar2 = __GXVertexPacketHas(10);
        if (((cVar2 == '\0') && (cVar2 = __GXVertexPacketHas(0x19), cVar2 == '\0')) &&
           (_DAT_00015124 <= (int)ppcRam00000000[1])) {
          sprintf(&__gxvDummyStr,_DAT_0001512c,uVar3);
          (**ppcRam00000000)(_DAT_00015124,0x49,&__gxvDummyStr);
        }
      }
    }
    else if (uVar1 < 0xd) {
      if (uVar1 < 5) {
        cVar2 = __GXVertexPacketHas(0x19);
        if ((cVar2 == '\0') && ((int)_DAT_00015130 <= (int)ppcRam00000000[1])) {
          sprintf(&__gxvDummyStr,_DAT_00015138,uVar3);
          (**ppcRam00000000)(_DAT_00015130,0x4c,&__gxvDummyStr);
        }
      }
      else {
        cVar2 = __GXVertexPacketHas(*(undefined4 *)
                                     (TextureEnums +
                                     ((*(ushort *)((int)ppcRam00000000 + (uVar3 + 0x40) * 4 + 10) >>
                                       7 & 0x1f) - 5) * 4));
        if ((cVar2 == '\0') && ((int)_DAT_00015134 <= (int)ppcRam00000000[1])) {
          sprintf(&__gxvDummyStr,_DAT_0001513c,uVar3,
                  (*(ushort *)((int)ppcRam00000000 + (uVar3 + 0x40) * 4 + 10) >> 7 & 0x1f) - 5);
          (**ppcRam00000000)(_DAT_00015134,0x4d,&__gxvDummyStr);
        }
      }
    }
    else if ((int)_DAT_00015138 <= (int)ppcRam00000000[1]) {
      sprintf(&__gxvDummyStr,_DAT_00015140,uVar3,
              *(ushort *)((int)ppcRam00000000 + (uVar3 + 0x40) * 4 + 10) >> 7 & 0x1f);
      (**ppcRam00000000)(_DAT_00015138,0x4e,&__gxvDummyStr);
    }
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void CheckTextureOrder(void)
{
  bool bVar1;
  code *pcVar2;
  
  bVar1 = false;
  pcVar2 = (code *)0x0;
  while (!bVar1) {
    if ((pcVar2 == ppcRam00000000[0x41]) ||
       ((*(byte *)((int)ppcRam00000000 + (int)(pcVar2 + 0x40) * 4 + 0xb) >> 4 & 7) != 0)) {
      bVar1 = true;
    }
    else {
      pcVar2 = pcVar2 + 1;
    }
  }
  bVar1 = false;
  while (!bVar1) {
    if (pcVar2 == ppcRam00000000[0x41]) {
      bVar1 = true;
    }
    else if ((*(byte *)((int)ppcRam00000000 + (int)(pcVar2 + 0x40) * 4 + 0xb) >> 4 & 7) == 1) {
      pcVar2 = pcVar2 + 1;
    }
    else {
      if ((*(byte *)((int)ppcRam00000000 + (int)(pcVar2 + 0x40) * 4 + 0xb) >> 4 & 7) == 0) {
        if (_DAT_0001513c <= (int)ppcRam00000000[1]) {
          (**ppcRam00000000)(_DAT_0001513c,0x4f,_DAT_00015144);
        }
      }
      bVar1 = true;
    }
  }
  bVar1 = false;
  do {
    while( true ) {
      while( true ) {
        if (bVar1) {
          return;
        }
        if (pcVar2 != ppcRam00000000[0x41]) break;
        bVar1 = true;
      }
      if ((*(byte *)((int)ppcRam00000000 + (int)(pcVar2 + 0x40) * 4 + 0xb) >> 4 & 7) != 0) break;
LAB_000112d4:
      if (_DAT_0001513c <= (int)ppcRam00000000[1]) {
        (**ppcRam00000000)(_DAT_0001513c,0x4f,_DAT_00015144);
      }
      bVar1 = true;
    }
    if ((*(byte *)((int)ppcRam00000000 + (int)(pcVar2 + 0x40) * 4 + 0xb) >> 4 & 7) == 1)
    goto LAB_000112d4;
    pcVar2 = pcVar2 + 1;
  } while( true );
}

void CheckRAM(char param_1,uint param_2,int param_3,int param_4,undefined4 param_5)
{
  char cVar1;
  bool bVar2;
  uint uVar3;
  
  bVar2 = false;
  for (uVar3 = param_2; uVar3 < param_2 + param_3; uVar3 = uVar3 + 1) {
    if (param_1 == '\0') {
      cVar1 = *(char *)((int)ppcRam00000000 + uVar3 + 0x1118);
    }
    else {
      cVar1 = *(char *)((int)ppcRam00000000 + uVar3 + 0xe18);
    }
    if ((cVar1 == '\0') && (!bVar2)) {
      if (*(int *)(&__gxvWarnLev + param_4 * 4) <= (int)ppcRam00000000[1]) {
        (**ppcRam00000000)(*(undefined4 *)(&__gxvWarnLev + param_4 * 4),param_4,param_5);
      }
      bVar2 = true;
    }
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void CheckBumpmapTextures(void)
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char acStack_110 [256];
  
  cVar1 = __GXVertexPacketHas(0);
  if (cVar1 == '\0') {
    if ((0x1e < (*(byte *)((int)ppcRam00000000 + 0x6b) & 0x3f)) &&
       (_DAT_00015140 <= (int)ppcRam00000000[1])) {
      sprintf(&__gxvDummyStr,_DAT_00015148,*(byte *)((int)ppcRam00000000 + 0x6b) & 0x3f);
      (**ppcRam00000000)(_DAT_00015140,0x50,&__gxvDummyStr);
    }
    sprintf(acStack_110,_DAT_000151b0,*(byte *)((int)ppcRam00000000 + 0x6b) & 0x3f);
    CheckRAM(1,(*(byte *)((int)ppcRam00000000 + 0x6b) & 0x3f) * 3 + 0x400,9,0x6a,acStack_110);
  }
  uVar3 = 0;
  while( true ) {
    if (numBumpmapTextures <= uVar3) break;
    uVar2 = *(byte *)((int)ppcRam00000000 + (numRegularTextures + uVar3 + 0x40) * 4 + 10) >> 4 & 7;
    if (((*(byte *)((int)ppcRam00000000 + (uVar2 + 0x40) * 4 + 0xb) >> 4 & 7) != 0) &&
       (_DAT_00015144 <= (int)ppcRam00000000[1])) {
      sprintf(&__gxvDummyStr,_DAT_0001514c,uVar3 + numRegularTextures,uVar2);
      (**ppcRam00000000)(_DAT_00015144,0x51,&__gxvDummyStr);
    }
    uVar2 = (uint)ppcRam00000000[numRegularTextures + uVar3 + 0x42] >> 0xf & 7;
    if ((*(char *)((int)ppcRam00000000 + uVar2 * 0x10 + 0x1382) == '\0') &&
       ((int)_DAT_00015148 <= (int)ppcRam00000000[1])) {
      sprintf(&__gxvDummyStr,_DAT_00015150,uVar3 + numRegularTextures,uVar2,&@280);
      (**ppcRam00000000)(_DAT_00015148,0x52,&__gxvDummyStr);
    }
    if ((*(char *)((int)ppcRam00000000 + uVar2 * 0x10 + 0x1383) == '\0') &&
       ((int)_DAT_00015148 <= (int)ppcRam00000000[1])) {
      sprintf(&__gxvDummyStr,_DAT_00015150,uVar3 + numRegularTextures,uVar2,&@281);
      (**ppcRam00000000)(_DAT_00015148,0x52,&__gxvDummyStr);
    }
    if (*(char *)(ppcRam00000000 + uVar2 * 4 + 0x4e1) == '\0') {
      if ((int)_DAT_00015148 <= (int)ppcRam00000000[1]) {
        sprintf(&__gxvDummyStr,_DAT_00015150,uVar3 + numRegularTextures,uVar2,&@282);
        (**ppcRam00000000)(_DAT_00015148,0x52,&__gxvDummyStr);
      }
    }
    cVar1 = __GXVertexPacketHas(0x19);
    if ((cVar1 == '\0') && ((int)_DAT_0001514c <= (int)ppcRam00000000[1])) {
      sprintf(&__gxvDummyStr,_DAT_00015154,uVar3);
      (**ppcRam00000000)(_DAT_0001514c,0x53,&__gxvDummyStr);
    }
    uVar3 = uVar3 + 1;
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void CheckTextureTransformMatrices(void)
{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint unaff_r29;
  uint unaff_r30;
  char acStack_118 [260];
  
  for (uVar3 = 0; uVar3 < numRegularTextures; uVar3 = uVar3 + 1) {
    cVar1 = '\0';
    switch(uVar3) {
    case 0:
      unaff_r30 = *(ushort *)((int)ppcRam00000000 + 0x6a) >> 4 & 0xfc;
      unaff_r29 = *(ushort *)((int)ppcRam00000000 + 0x6a) >> 6 & 0x3f;
      cVar1 = __GXVertexPacketHas(1);
      break;
    case 1:
      unaff_r30 = (uint)ppcRam00000000[0x1a] >> 10 & 0xfc;
      unaff_r29 = (uint)ppcRam00000000[0x1a] >> 0xc & 0x3f;
      cVar1 = __GXVertexPacketHas(2);
      break;
    case 2:
      unaff_r30 = *(byte *)((int)ppcRam00000000 + 0x69) & 0xfc;
      unaff_r29 = (uint)(*(byte *)((int)ppcRam00000000 + 0x69) >> 2);
      cVar1 = __GXVertexPacketHas(3);
      break;
    case 3:
      unaff_r30 = (*(byte *)(ppcRam00000000 + 0x1a) & 0x3f) << 2;
      unaff_r29 = *(byte *)(ppcRam00000000 + 0x1a) & 0x3f;
      cVar1 = __GXVertexPacketHas(4);
      break;
    case 4:
      unaff_r30 = (*(byte *)((int)ppcRam00000000 + 0x6f) & 0x3f) << 2;
      unaff_r29 = *(byte *)((int)ppcRam00000000 + 0x6f) & 0x3f;
      cVar1 = __GXVertexPacketHas(5);
      break;
    case 5:
      unaff_r30 = *(ushort *)((int)ppcRam00000000 + 0x6e) >> 4 & 0xfc;
      unaff_r29 = *(ushort *)((int)ppcRam00000000 + 0x6e) >> 6 & 0x3f;
      cVar1 = __GXVertexPacketHas(6);
      break;
    case 6:
      unaff_r30 = (uint)ppcRam00000000[0x1b] >> 10 & 0xfc;
      unaff_r29 = (uint)ppcRam00000000[0x1b] >> 0xc & 0x3f;
      cVar1 = __GXVertexPacketHas(7);
      break;
    case 7:
      unaff_r30 = *(byte *)((int)ppcRam00000000 + 0x6d) & 0xfc;
      unaff_r29 = (uint)(*(byte *)((int)ppcRam00000000 + 0x6d) >> 2);
      cVar1 = __GXVertexPacketHas(8);
      break;
    default:
      if (_DAT_00015150 <= (int)ppcRam00000000[1]) {
        sprintf(&__gxvDummyStr,_DAT_00015158,uVar3);
        (**ppcRam00000000)(_DAT_00015150,0x54,&__gxvDummyStr);
      }
    }
    if (cVar1 == '\0') {
      sprintf(acStack_118,_DAT_000151b4,uVar3,uVar3,unaff_r29);
      if ((*(byte *)((int)ppcRam00000000 + (uVar3 + 0x40) * 4 + 0xb) >> 1 & 1) == 0) {
        uVar2 = 8;
      }
      else {
        uVar2 = 0xc;
      }
      CheckRAM(0,unaff_r30,uVar2,0x6b,acStack_118);
    }
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void CheckInputForms(void)
{
  ushort uVar1;
  uint uVar2;
  
  for (uVar2 = 0; uVar2 < numRegularTextures; uVar2 = uVar2 + 1) {
    uVar1 = *(ushort *)((int)ppcRam00000000 + (uVar2 + 0x40) * 4 + 10) >> 7 & 0x1f;
    if ((((uVar1 < 0xd) && (4 < uVar1)) &&
        ((*(byte *)((int)ppcRam00000000 + (uVar2 + 0x40) * 4 + 0xb) >> 2 & 1) != 0)) &&
       (_DAT_00015154 <= (int)ppcRam00000000[1])) {
      sprintf(&__gxvDummyStr,_DAT_0001515c,uVar2,
              *(ushort *)((int)ppcRam00000000 + (uVar2 + 0x40) * 4 + 10) >> 7 & 0x1f);
      (**ppcRam00000000)(_DAT_00015154,0x55,&__gxvDummyStr);
    }
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void CheckLight(int param_1)
{
  bool bVar1;
  uint uVar2;
  
  bVar1 = false;
  for (uVar2 = 0; uVar2 < 0xd; uVar2 = uVar2 + 1) {
    if ((*(char *)((int)ppcRam00000000 + param_1 * 0x10 + uVar2 + 0x137b) == '\0') && (!bVar1)) {
      if (_DAT_000151b0 <= (int)ppcRam00000000[1]) {
        sprintf(&__gxvDummyStr,_DAT_000151b8,param_1);
        (**ppcRam00000000)(_DAT_000151b0,0x6c,&__gxvDummyStr);
      }
      bVar1 = true;
    }
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void CheckColor0(void)
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  char acStack_110 [260];
  
  if (((*(byte *)((int)ppcRam00000000 + 0x2f) & 3) == 0) && (numColorTextures == 0)) {
    return;
  }
  if ((*(char *)((int)ppcRam00000000 + 0x10d6) == '\0') && (_DAT_00015158 <= (int)ppcRam00000000[1])
     ) {
    sprintf(&__gxvDummyStr,_DAT_00015160,0x100e,@431);
    (**ppcRam00000000)(_DAT_00015158,0x56,&__gxvDummyStr);
  }
  if ((*(char *)(ppcRam00000000 + 0x436) == '\0') && (_DAT_00015158 <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_DAT_00015160,0x1010,@432);
    (**ppcRam00000000)(_DAT_00015158,0x56,&__gxvDummyStr);
  }
  if ((((*(byte *)((int)ppcRam00000000 + 0x43) & 1) == 0) &&
      (*(char *)(ppcRam00000000 + 0x435) == '\0')) && (_DAT_0001515c <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_DAT_00015164,0,0,0x100c);
    (**ppcRam00000000)(_DAT_0001515c,0x57,&__gxvDummyStr);
  }
  if ((((*(byte *)((int)ppcRam00000000 + 0x43) >> 6 & 1) == 0) &&
      (*(char *)((int)ppcRam00000000 + 0x10d2) == '\0')) &&
     ((int)_DAT_00015160 <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_DAT_00015168,0,0,0x100a);
    (**ppcRam00000000)(_DAT_00015160,0x58,&__gxvDummyStr);
  }
  if (((*(byte *)((int)ppcRam00000000 + 0x43) >> 1 & 1) != 1) &&
     ((*(byte *)((int)ppcRam00000000 + 0x4b) >> 1 & 1) != 1)) {
    return;
  }
  bVar2 = false;
  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1) {
    bVar1 = false;
    switch(uVar4) {
    case 0:
      if (((*(byte *)((int)ppcRam00000000 + 0x43) >> 2 & 1) != 0) ||
         ((*(byte *)((int)ppcRam00000000 + 0x4b) >> 2 & 1) != 0)) {
        bVar1 = true;
      }
      break;
    case 1:
      if (((*(byte *)((int)ppcRam00000000 + 0x43) >> 3 & 1) != 0) ||
         ((*(byte *)((int)ppcRam00000000 + 0x4b) >> 3 & 1) != 0)) {
        bVar1 = true;
      }
      break;
    case 2:
      if (((*(byte *)((int)ppcRam00000000 + 0x43) >> 4 & 1) != 0) ||
         ((*(byte *)((int)ppcRam00000000 + 0x4b) >> 4 & 1) != 0)) {
        bVar1 = true;
      }
      break;
    case 3:
      if (((*(byte *)((int)ppcRam00000000 + 0x43) >> 5 & 1) != 0) ||
         ((*(byte *)((int)ppcRam00000000 + 0x4b) >> 5 & 1) != 0)) {
        bVar1 = true;
      }
      break;
    case 4:
      if (((*(byte *)((int)ppcRam00000000 + 0x42) >> 3 & 1) != 0) ||
         ((*(byte *)((int)ppcRam00000000 + 0x4a) >> 3 & 1) != 0)) {
        bVar1 = true;
      }
      break;
    case 5:
      if (((*(byte *)((int)ppcRam00000000 + 0x42) >> 4 & 1) != 0) ||
         ((*(byte *)((int)ppcRam00000000 + 0x4a) >> 4 & 1) != 0)) {
        bVar1 = true;
      }
      break;
    case 6:
      if (((*(byte *)((int)ppcRam00000000 + 0x42) >> 5 & 1) != 0) ||
         ((*(byte *)((int)ppcRam00000000 + 0x4a) >> 5 & 1) != 0)) {
        bVar1 = true;
      }
      break;
    case 7:
      if (((*(byte *)((int)ppcRam00000000 + 0x42) >> 6 & 1) != 0) ||
         ((*(byte *)((int)ppcRam00000000 + 0x4a) >> 6 & 1) != 0)) {
        bVar1 = true;
      }
    }
    if (bVar1) {
      CheckLight(uVar4);
      bVar2 = true;
    }
  }
  if (!bVar2) {
    return;
  }
  if ((((*(byte *)((int)ppcRam00000000 + 0x42) >> 2 & 1) == 0) &&
      ((*(ushort *)((int)ppcRam00000000 + 0x42) >> 7 & 3) != 0)) &&
     ((int)_DAT_00015164 <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_DAT_0001516c,@433,@433);
    (**ppcRam00000000)(_DAT_00015164,0x59,&__gxvDummyStr);
  }
  if ((((*(byte *)((int)ppcRam00000000 + 0x4a) >> 2 & 1) == 0) &&
      ((*(ushort *)((int)ppcRam00000000 + 0x4a) >> 7 & 3) != 0)) &&
     ((int)_DAT_00015164 <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_DAT_0001516c,@434,@434);
    (**ppcRam00000000)(_DAT_00015164,0x59,&__gxvDummyStr);
  }
  if ((((*(ushort *)((int)ppcRam00000000 + 0x42) >> 7 & 3) == 0) &&
      (((*(byte *)((int)ppcRam00000000 + 0x42) >> 1 & 1) == 0 ||
       ((*(byte *)((int)ppcRam00000000 + 0x42) >> 2 & 1) != 1)))) &&
     ((*(ushort *)((int)ppcRam00000000 + 0x4a) >> 7 & 3) == 0)) {
    if ((*(byte *)((int)ppcRam00000000 + 0x4a) >> 1 & 1) == 0) {
      return;
    }
    if ((*(byte *)((int)ppcRam00000000 + 0x4a) >> 2 & 1) != 1) {
      return;
    }
  }
  cVar3 = __GXVertexPacketHas(10);
  if (((cVar3 == '\0') && (cVar3 = __GXVertexPacketHas(0x19), cVar3 == '\0')) &&
     ((int)_DAT_00015168 <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_DAT_00015170,0);
    (**ppcRam00000000)(_DAT_00015168,0x5a,&__gxvDummyStr);
  }
  cVar3 = __GXVertexPacketHas(0);
  if (cVar3 == '\0') {
    if ((0x1e < (*(byte *)((int)ppcRam00000000 + 0x6b) & 0x3f)) &&
       ((int)_DAT_0001516c <= (int)ppcRam00000000[1])) {
      sprintf(&__gxvDummyStr,_DAT_00015174,0,*(byte *)((int)ppcRam00000000 + 0x6b) & 0x3f);
      (**ppcRam00000000)(_DAT_0001516c,0x5b,&__gxvDummyStr);
    }
    sprintf(acStack_110,_DAT_000151bc,0,*(byte *)((int)ppcRam00000000 + 0x6b) & 0x3f);
    CheckRAM(1,(*(byte *)((int)ppcRam00000000 + 0x6b) & 0x3f) * 3 + 0x400,9,0x6d,acStack_110);
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void CheckColor1(void)
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  char acStack_110 [256];
  
  if ((numColorTextures < 2) ||
     ((*(byte *)((int)ppcRam00000000 + (numRegularTextures + numBumpmapTextures + 0x41) * 4 + 0xb)
       >> 4 & 7) != 3)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((*(byte *)((int)ppcRam00000000 + 0x2f) & 3) != 2) && (!bVar1)) {
    return;
  }
  if ((*(char *)((int)ppcRam00000000 + 0x10d7) == '\0') && (_DAT_00015158 <= (int)ppcRam00000000[1])
     ) {
    sprintf(&__gxvDummyStr,_DAT_00015160,0x100f,@535);
    (**ppcRam00000000)(_DAT_00015158,0x56,&__gxvDummyStr);
  }
  if ((*(char *)((int)ppcRam00000000 + 0x10d9) == '\0') && (_DAT_00015158 <= (int)ppcRam00000000[1])
     ) {
    sprintf(&__gxvDummyStr,_DAT_00015160,0x1011,@536);
    (**ppcRam00000000)(_DAT_00015158,0x56,&__gxvDummyStr);
  }
  if ((((*(byte *)((int)ppcRam00000000 + 0x47) & 1) == 0) &&
      (*(char *)((int)ppcRam00000000 + 0x10d5) == '\0')) &&
     (_DAT_0001515c <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_DAT_00015164,1,1,0x100d);
    (**ppcRam00000000)(_DAT_0001515c,0x57,&__gxvDummyStr);
  }
  if ((((*(byte *)((int)ppcRam00000000 + 0x47) >> 6 & 1) == 0) &&
      (*(char *)((int)ppcRam00000000 + 0x10d3) == '\0')) &&
     ((int)_DAT_00015160 <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_DAT_00015168,1,1,0x100b);
    (**ppcRam00000000)(_DAT_00015160,0x58,&__gxvDummyStr);
  }
  if (((*(byte *)((int)ppcRam00000000 + 0x47) >> 1 & 1) != 1) &&
     ((*(byte *)((int)ppcRam00000000 + 0x4f) >> 1 & 1) != 1)) {
    return;
  }
  bVar1 = false;
  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1) {
    bVar2 = false;
    switch(uVar4) {
    case 0:
      if (((*(byte *)((int)ppcRam00000000 + 0x47) >> 2 & 1) != 0) ||
         ((*(byte *)((int)ppcRam00000000 + 0x4f) >> 2 & 1) != 0)) {
        bVar2 = true;
      }
      break;
    case 1:
      if (((*(byte *)((int)ppcRam00000000 + 0x47) >> 3 & 1) != 0) ||
         ((*(byte *)((int)ppcRam00000000 + 0x4f) >> 3 & 1) != 0)) {
        bVar2 = true;
      }
      break;
    case 2:
      if (((*(byte *)((int)ppcRam00000000 + 0x47) >> 4 & 1) != 0) ||
         ((*(byte *)((int)ppcRam00000000 + 0x4f) >> 4 & 1) != 0)) {
        bVar2 = true;
      }
      break;
    case 3:
      if (((*(byte *)((int)ppcRam00000000 + 0x47) >> 5 & 1) != 0) ||
         ((*(byte *)((int)ppcRam00000000 + 0x4f) >> 5 & 1) != 0)) {
        bVar2 = true;
      }
      break;
    case 4:
      if (((*(byte *)((int)ppcRam00000000 + 0x46) >> 3 & 1) != 0) ||
         ((*(byte *)((int)ppcRam00000000 + 0x4e) >> 3 & 1) != 0)) {
        bVar2 = true;
      }
      break;
    case 5:
      if (((*(byte *)((int)ppcRam00000000 + 0x46) >> 4 & 1) != 0) ||
         ((*(byte *)((int)ppcRam00000000 + 0x4e) >> 4 & 1) != 0)) {
        bVar2 = true;
      }
      break;
    case 6:
      if (((*(byte *)((int)ppcRam00000000 + 0x46) >> 5 & 1) != 0) ||
         ((*(byte *)((int)ppcRam00000000 + 0x4e) >> 5 & 1) != 0)) {
        bVar2 = true;
      }
      break;
    case 7:
      if (((*(byte *)((int)ppcRam00000000 + 0x46) >> 6 & 1) != 0) ||
         ((*(byte *)((int)ppcRam00000000 + 0x4e) >> 6 & 1) != 0)) {
        bVar2 = true;
      }
    }
    if (bVar2) {
      CheckLight(uVar4);
      bVar1 = true;
    }
  }
  if (!bVar1) {
    return;
  }
  if ((((*(byte *)((int)ppcRam00000000 + 0x46) >> 2 & 1) == 0) &&
      ((*(ushort *)((int)ppcRam00000000 + 0x46) >> 7 & 3) != 0)) &&
     ((int)_DAT_00015164 <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_DAT_0001516c,@537,@537);
    (**ppcRam00000000)(_DAT_00015164,0x59,&__gxvDummyStr);
  }
  if ((((*(byte *)((int)ppcRam00000000 + 0x4e) >> 2 & 1) == 0) &&
      ((*(ushort *)((int)ppcRam00000000 + 0x4e) >> 7 & 3) != 0)) &&
     ((int)_DAT_00015164 <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_DAT_0001516c,@538,@538);
    (**ppcRam00000000)(_DAT_00015164,0x59,&__gxvDummyStr);
  }
  if ((((*(ushort *)((int)ppcRam00000000 + 0x46) >> 7 & 3) == 0) &&
      (((*(byte *)((int)ppcRam00000000 + 0x46) >> 1 & 1) == 0 ||
       ((*(byte *)((int)ppcRam00000000 + 0x46) >> 2 & 1) != 1)))) &&
     ((*(ushort *)((int)ppcRam00000000 + 0x4e) >> 7 & 3) == 0)) {
    if ((*(byte *)((int)ppcRam00000000 + 0x4e) >> 1 & 1) == 0) {
      return;
    }
    if ((*(byte *)((int)ppcRam00000000 + 0x4e) >> 2 & 1) != 1) {
      return;
    }
  }
  cVar3 = __GXVertexPacketHas(10);
  if (((cVar3 == '\0') && (cVar3 = __GXVertexPacketHas(0x19), cVar3 == '\0')) &&
     ((int)_DAT_00015168 <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_DAT_00015170,1);
    (**ppcRam00000000)(_DAT_00015168,0x5a,&__gxvDummyStr);
  }
  cVar3 = __GXVertexPacketHas(0);
  if (cVar3 == '\0') {
    if ((0x1e < (*(byte *)((int)ppcRam00000000 + 0x6b) & 0x3f)) &&
       ((int)_DAT_0001516c <= (int)ppcRam00000000[1])) {
      sprintf(&__gxvDummyStr,_DAT_00015174,1,*(byte *)((int)ppcRam00000000 + 0x6b) & 0x3f);
      (**ppcRam00000000)(_DAT_0001516c,0x5b,&__gxvDummyStr);
    }
    sprintf(acStack_110,_DAT_000151bc,1,*(byte *)((int)ppcRam00000000 + 0x6b) & 0x3f);
    CheckRAM(1,(*(byte *)((int)ppcRam00000000 + 0x6b) & 0x3f) * 3 + 0x400,9,0x6d,acStack_110);
  }
  return;
}

void ComputeSignExponentMantissa(double param_1,uint *param_2,uint *param_3,uint *param_4)
{
  float fVar1;
  
  fVar1 = (float)param_1;
  *param_2 = (uint)fVar1 >> 0x1f;
  *param_3 = (uint)fVar1 >> 0x17 & 0xff;
  *param_4 = (uint)fVar1 & 0x7fffff;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void CheckFloatingPointValue(char param_1,float param_2,undefined4 param_3)
{
  int local_18;
  uint local_14;
  int local_10 [3];
  
  if (param_1 != '\0') {
    ComputeSignExponentMantissa((double)param_2,local_10,&local_14,&local_18);
    if ((local_14 != 0) || (local_18 != 0)) {
      if (local_14 == 0xff) {
        if (1 < (int)ppcRam00000000[1]) {
          if (local_18 == 0) {
            if (local_10[0] == 0) {
              if (_DAT_00015170 <= (int)ppcRam00000000[1]) {
                sprintf(&__gxvDummyStr,_DAT_00015178,param_3,&@577,param_2);
                (**ppcRam00000000)(_DAT_00015170,0x5c,&__gxvDummyStr);
              }
            }
            else if (_DAT_00015170 <= (int)ppcRam00000000[1]) {
              sprintf(&__gxvDummyStr,_DAT_00015178,param_3,&@576,param_2);
              (**ppcRam00000000)(_DAT_00015170,0x5c,&__gxvDummyStr);
            }
          }
          else if (_DAT_00015174 <= (int)ppcRam00000000[1]) {
            sprintf(&__gxvDummyStr,_DAT_0001517c,param_3,param_2);
            (**ppcRam00000000)(_DAT_00015174,0x5d,&__gxvDummyStr);
          }
        }
      }
      else if (2 < (int)ppcRam00000000[1]) {
        if (local_14 < 0x6b) {
          if ((int)_DAT_00015178 <= (int)ppcRam00000000[1]) {
            sprintf(&__gxvDummyStr,_DAT_00015180,(double)param_2,param_3,param_2);
            (**ppcRam00000000)(_DAT_00015178,0x5e,&__gxvDummyStr);
          }
        }
        else if ((0x96 < local_14) && ((int)_DAT_0001517c <= (int)ppcRam00000000[1])) {
          sprintf(&__gxvDummyStr,_DAT_00015184,(double)param_2,param_3,param_2);
          (**ppcRam00000000)(_DAT_0001517c,0x5f,&__gxvDummyStr);
        }
      }
    }
  }
  return;
}

void CheckMatrixRAMRanges(void)
{
  uint uVar1;
  char acStack_108 [260];
  
  for (uVar1 = 0; uVar1 < 0x100; uVar1 = uVar1 + 1) {
    sprintf(acStack_108,@584,uVar1);
    CheckFloatingPointValue
              (*(undefined *)(iRam00000000 + uVar1 + 0x1118),
               *(undefined4 *)(iRam00000000 + uVar1 * 4 + 0x148),acStack_108);
  }
  return;
}

void CheckNormalRAMRanges(void)
{
  uint uVar1;
  char acStack_108 [260];
  
  for (uVar1 = 0x400; uVar1 < 0x460; uVar1 = uVar1 + 1) {
    sprintf(acStack_108,@591,uVar1);
    CheckFloatingPointValue
              (*(undefined *)(uVar1 + iRam00000000 + 0xe18),
               *(undefined4 *)(iRam00000000 + (uVar1 - 0x400) * 4 + 0x548),acStack_108);
  }
  return;
}

void CheckDMatrixRAMRanges(void)
{
  uint uVar1;
  char acStack_108 [260];
  
  for (uVar1 = 0x500; uVar1 < 0x600; uVar1 = uVar1 + 1) {
    sprintf(acStack_108,@598,uVar1);
    CheckFloatingPointValue
              (*(undefined *)(uVar1 + iRam00000000 + 0xd78),
               *(undefined4 *)(iRam00000000 + (uVar1 - 0x500) * 4 + 0x6c8),acStack_108);
  }
  return;
}

void CheckLightRAMRanges(void)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char acStack_110 [260];
  
  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1) {
    for (uVar3 = 1; uVar3 < 0xd; uVar3 = uVar3 + 1) {
      iVar1 = uVar4 * 0x10 + uVar3;
      iVar2 = iVar1 + 0x603;
      sprintf(acStack_110,@610,uVar4,lightRegisterNames + uVar3 * 0x100,iVar2);
      CheckFloatingPointValue
                (*(undefined *)(iVar2 + iRam00000000 + 0xd78),
                 *(undefined4 *)(iRam00000000 + (iVar1 + 3) * 4 + 0xac8),acStack_110);
    }
  }
  return;
}

void CheckControlRAMRanges(void)
{
  CheckFloatingPointValue
            (*(undefined *)(iRam00000000 + 0x10e2),*(undefined4 *)(iRam00000000 + 0x70),@612);
  CheckFloatingPointValue
            (*(undefined *)(iRam00000000 + 0x10e3),*(undefined4 *)(iRam00000000 + 0x74),@613);
  CheckFloatingPointValue
            (*(undefined *)(iRam00000000 + 0x10e4),*(undefined4 *)(iRam00000000 + 0x78),@614);
  CheckFloatingPointValue
            (*(undefined *)(iRam00000000 + 0x10e5),*(undefined4 *)(iRam00000000 + 0x7c),@615);
  CheckFloatingPointValue
            (*(undefined *)(iRam00000000 + 0x10e6),*(undefined4 *)(iRam00000000 + 0x80),@616);
  CheckFloatingPointValue
            (*(undefined *)(iRam00000000 + 0x10e7),*(undefined4 *)(iRam00000000 + 0x84),@617);
  CheckFloatingPointValue
            (*(undefined *)(iRam00000000 + 0x10e8),*(undefined4 *)(iRam00000000 + 0x88),@618);
  CheckFloatingPointValue
            (*(undefined *)(iRam00000000 + 0x10e9),*(undefined4 *)(iRam00000000 + 0x8c),@619);
  CheckFloatingPointValue
            (*(undefined *)(iRam00000000 + 0x10ea),*(undefined4 *)(iRam00000000 + 0x90),@620);
  CheckFloatingPointValue
            (*(undefined *)(iRam00000000 + 0x10eb),*(undefined4 *)(iRam00000000 + 0x94),@621);
  CheckFloatingPointValue
            (*(undefined *)(iRam00000000 + 0x10ec),*(undefined4 *)(iRam00000000 + 0x98),@622);
  CheckFloatingPointValue
            (*(undefined *)(iRam00000000 + 0x10ed),*(undefined4 *)(iRam00000000 + 0x9c),@623);
  return;
}

void CheckFloatingPointRanges(void)
{
  CheckMatrixRAMRanges();
  CheckNormalRAMRanges();
  CheckDMatrixRAMRanges();
  CheckLightRAMRanges();
  CheckControlRAMRanges();
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void CheckMatrixIndices(void)
{
  char cVar1;
  
  cVar1 = __GXVertexPacketHas(0);
  if ((((cVar1 == '\0') || (cVar1 = __GXVertexPacketHas(1), cVar1 == '\0')) ||
      (cVar1 = __GXVertexPacketHas(2), cVar1 == '\0')) ||
     ((cVar1 = __GXVertexPacketHas(3), cVar1 == '\0' ||
      (cVar1 = __GXVertexPacketHas(4), cVar1 == '\0')))) {
    CheckDirty(0x1018,@647);
  }
  if ((0 < (int)ppcRam00000000[1]) && (cVar1 = __GXVertexPacketHas(0), cVar1 == '\0')) {
    CheckRAM(0,(*(byte *)((int)ppcRam00000000 + 0x6b) & 0x3f) << 2,0xc,0x6e,_DAT_000151c0);
  }
  cVar1 = __GXVertexPacketHas(5);
  if ((((cVar1 != '\0') && (cVar1 = __GXVertexPacketHas(6), cVar1 != '\0')) &&
      (cVar1 = __GXVertexPacketHas(7), cVar1 != '\0')) &&
     (cVar1 = __GXVertexPacketHas(8), cVar1 != '\0')) {
    return;
  }
  if (((4 < numRegularTextures) && (0 < (int)ppcRam00000000[1])) &&
     ((*(char *)((int)ppcRam00000000 + 0x10e1) == '\0' && (_DAT_00015180 <= (int)ppcRam00000000[1]))
     )) {
    sprintf(&__gxvDummyStr,_DAT_00015188,numRegularTextures,0x1019);
    (**ppcRam00000000)(_DAT_00015180,0x60,&__gxvDummyStr);
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void CheckErrors(void)
{
  code *pcVar1;
  char acStack_58 [80];
  
  CheckDirty(0x103f,@688);
  CheckDirty(0x1009,@689);
  CheckDirty(0x1008,@690);
  CheckDirty(0x101a,@691);
  CheckDirty(0x101b,@692);
  CheckDirty(0x101c,@693);
  CheckDirty(0x101d,@694);
  CheckDirty(0x101e,@695);
  CheckDirty(0x101f,@696);
  CheckDirty(0x1020,@697);
  CheckDirty(0x1021,@698);
  CheckDirty(0x1022,@699);
  CheckDirty(0x1023,@700);
  CheckDirty(0x1024,@701);
  CheckDirty(0x1025,@702);
  CheckDirty(0x1026,@703);
  CheckMatrixIndices();
  if (0 < (int)ppcRam00000000[1]) {
    CheckCTGColors();
    if ((code *)0x8 < ppcRam00000000[0x41]) {
      if (_DAT_00015190 <= (int)ppcRam00000000[1]) {
        sprintf(&__gxvDummyStr,_DAT_00015198,ppcRam00000000[0x41],8);
        (**ppcRam00000000)(_DAT_00015190,100,&__gxvDummyStr);
      }
    }
    if (8 < numRegularTextures) {
      if (_DAT_00015194 <= (int)ppcRam00000000[1]) {
        sprintf(&__gxvDummyStr,_DAT_0001519c,numRegularTextures,8);
        (**ppcRam00000000)(_DAT_00015194,0x65,&__gxvDummyStr);
      }
    }
    if (3 < numBumpmapTextures) {
      if ((int)_DAT_00015198 <= (int)ppcRam00000000[1]) {
        sprintf(&__gxvDummyStr,_DAT_000151a0,numBumpmapTextures,3);
        (**ppcRam00000000)(_DAT_00015198,0x66,&__gxvDummyStr);
      }
    }
    if (2 < numColorTextures) {
      if ((int)_DAT_0001519c <= (int)ppcRam00000000[1]) {
        sprintf(&__gxvDummyStr,_DAT_000151a4,numColorTextures,2);
        (**ppcRam00000000)(_DAT_0001519c,0x67,&__gxvDummyStr);
      }
    }
    if (1 < numColor0Textures) {
      if ((int)_DAT_000151a4 <= (int)ppcRam00000000[1]) {
        sprintf(&__gxvDummyStr,_DAT_000151ac,0);
        (**ppcRam00000000)(_DAT_000151a4,0x69,&__gxvDummyStr);
      }
    }
    if (1 < numColor1Textures) {
      if ((int)_DAT_000151a4 <= (int)ppcRam00000000[1]) {
        sprintf(&__gxvDummyStr,_DAT_000151ac,1);
        (**ppcRam00000000)(_DAT_000151a4,0x69,&__gxvDummyStr);
      }
    }
    CheckVertexPacket();
    for (pcVar1 = (code *)0x0; pcVar1 < ppcRam00000000[0x41]; pcVar1 = pcVar1 + 1) {
      sprintf(acStack_58,@704,pcVar1);
      CheckDirty(pcVar1 + 0x1040,acStack_58);
    }
    CheckSourceRows();
    CheckTextureOrder();
    if (numBumpmapTextures != 0) {
      CheckBumpmapTextures();
    }
    CheckTextureTransformMatrices();
    if (numColorTextures != 0) {
      if ((*(byte *)((int)ppcRam00000000 +
                    (numRegularTextures + numBumpmapTextures + 0x40) * 4 + 0xb) >> 4 & 7) != 2) {
        if ((int)_DAT_000151a0 <= (int)ppcRam00000000[1]) {
          (**ppcRam00000000)(_DAT_000151a0,0x68,_DAT_000151a8);
        }
      }
    }
    CheckColor0();
    CheckColor1();
  }
  return;
}

void CheckWarnings(void)
{
  if (0 < *(int *)(iRam00000000 + 4)) {
    CheckInputForms();
  }
  CheckClean(0x1000,@710);
  CheckClean(0x1001,@711);
  CheckClean(0x1002,@712);
  CheckClean(0x1003,@713);
  CheckClean(0x1004,@714);
  if (1 < *(int *)(iRam00000000 + 4)) {
    CheckFloatingPointRanges();
  }
  return;
}

void __GXVerifyXF(void)
{
  if (internalDebug != '\0') {
    DumpXFRegisters();
  }
  InitializeXFVerifyData();
  CheckErrors();
  CheckWarnings();
  DumpCount = DumpCount + 1;
  return;
}
