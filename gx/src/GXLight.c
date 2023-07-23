void GXInitLightAttn(double param_1,double param_2,double param_3,double param_4,double param_5,
                    double param_6,int param_7)
{
  if (param_7 == 0) {
    OSPanic(...data.0,0x62,@92);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,99,@93);
  }
  *(float *)(param_7 + 0x10) = (float)param_1;
  *(float *)(param_7 + 0x14) = (float)param_2;
  *(float *)(param_7 + 0x18) = (float)param_3;
  *(float *)(param_7 + 0x1c) = (float)param_4;
  *(float *)(param_7 + 0x20) = (float)param_5;
  *(float *)(param_7 + 0x24) = (float)param_6;
  return;
}

void GXInitLightAttnA(double param_1,double param_2,double param_3,int param_4)
{
  if (param_4 == 0) {
    OSPanic(...data.0,0x70,@92);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x71,@95);
  }
  *(float *)(param_4 + 0x10) = (float)param_1;
  *(float *)(param_4 + 0x14) = (float)param_2;
  *(float *)(param_4 + 0x18) = (float)param_3;
  return;
}

void GXGetLightAttnA(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x7a,@92);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x7b,@97);
  }
  *param_2 = *(undefined4 *)(param_1 + 0x10);
  *param_3 = *(undefined4 *)(param_1 + 0x14);
  *param_4 = *(undefined4 *)(param_1 + 0x18);
  return;
}

void GXInitLightAttnK(double param_1,double param_2,double param_3,int param_4)
{
  if (param_4 == 0) {
    OSPanic(...data.0,0x84,@92);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x85,@99);
  }
  *(float *)(param_4 + 0x1c) = (float)param_1;
  *(float *)(param_4 + 0x20) = (float)param_2;
  *(float *)(param_4 + 0x24) = (float)param_3;
  return;
}

void GXGetLightAttnK(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x8e,@92);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x8f,@101);
  }
  *param_2 = *(undefined4 *)(param_1 + 0x1c);
  *param_3 = *(undefined4 *)(param_1 + 0x20);
  *param_4 = *(undefined4 *)(param_1 + 0x24);
  return;
}

void GXInitLightSpot(void)
{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  double extraout_f1;
  double dVar6;
  undefined8 uVar7;
  float fVar8;
  
  uVar7 = _savefpr_25();
  iVar4 = (int)((ulonglong)uVar7 >> 0x20);
  uVar5 = (undefined4)uVar7;
  dVar6 = extraout_f1;
  if (iVar4 == 0) {
    OSPanic(...data.0,0xa7,@92);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0xa9,@115);
  }
  if ((dVar6 <= (double)@116) || ((double)@117 < dVar6)) {
    uVar5 = 0;
  }
  fVar8 = cosf((float)((double)@118 * dVar6) / @119);
  fVar1 = @122;
  fVar2 = @116;
  fVar3 = @116;
  switch(uVar5) {
  case 1:
    fVar1 = @120 * fVar8;
    fVar2 = @121;
    break;
  case 2:
    fVar1 = -fVar8 / (@122 - fVar8);
    fVar2 = @122 / (@122 - fVar8);
    break;
  case 3:
    fVar1 = @116;
    fVar2 = -fVar8 / (@122 - fVar8);
    fVar3 = @122 / (@122 - fVar8);
    break;
  case 4:
    fVar3 = (@122 - fVar8) * (@122 - fVar8);
    fVar1 = (fVar8 * (fVar8 - @123)) / fVar3;
    fVar2 = @123 / fVar3;
    fVar3 = @124 / fVar3;
    break;
  case 5:
    fVar3 = (@122 - fVar8) * (@122 - fVar8);
    fVar1 = (@125 * fVar8) / fVar3;
    fVar2 = (@126 * (@122 + fVar8)) / fVar3;
    fVar3 = @125 / fVar3;
    break;
  case 6:
    fVar3 = (@122 - fVar8) * (@122 - fVar8);
    fVar1 = @122 - (@123 * fVar8 * fVar8) / fVar3;
    fVar2 = (@126 * fVar8) / fVar3;
    fVar3 = @127 / fVar3;
  }
  *(float *)(iVar4 + 0x10) = fVar1;
  *(float *)(iVar4 + 0x14) = fVar2;
  *(float *)(iVar4 + 0x18) = fVar3;
  _restfpr_25();
  return;
}

void GXInitLightDistAttn(undefined8 param_1,double param_2)
{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  double extraout_f1;
  double dVar5;
  undefined8 uVar6;
  
  uVar6 = _savefpr_27();
  iVar3 = (int)((ulonglong)uVar6 >> 0x20);
  iVar4 = (int)uVar6;
  dVar5 = extraout_f1;
  if (iVar3 == 0) {
    OSPanic(...data.0,0xf2,@92);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0xf4,@141);
  }
  if (dVar5 < (double)@116) {
    iVar4 = 0;
  }
  if ((param_2 <= (double)@116) || ((double)@122 <= param_2)) {
    iVar4 = 0;
  }
  if (iVar4 == 2) {
    fVar1 = (@142 * (float)((double)@122 - param_2)) / (float)(param_2 * dVar5);
    fVar2 = (@142 * (float)((double)@122 - param_2)) /
            (float)(dVar5 * (double)(float)(param_2 * dVar5));
  }
  else {
    fVar1 = @116;
    fVar2 = @116;
    if (iVar4 < 2) {
      if ((iVar4 != 0) && (-1 < iVar4)) {
        fVar1 = (float)((double)@122 - param_2) / (float)(param_2 * dVar5);
      }
    }
    else if (iVar4 < 4) {
      fVar2 = (float)((double)@122 - param_2) / (float)(dVar5 * (double)(float)(param_2 * dVar5));
    }
  }
  *(float *)(iVar3 + 0x1c) = @122;
  *(float *)(iVar3 + 0x20) = fVar1;
  *(float *)(iVar3 + 0x24) = fVar2;
  _restfpr_27();
  return;
}

void GXInitLightPos(double param_1,double param_2,double param_3,int param_4)
{
  if (param_4 == 0) {
    OSPanic(...data.0,0x129,@92);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,299,@144);
  }
  *(float *)(param_4 + 0x28) = (float)param_1;
  *(float *)(param_4 + 0x2c) = (float)param_2;
  *(float *)(param_4 + 0x30) = (float)param_3;
  return;
}

void GXGetLightPos(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x134,@92);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x136,@146);
  }
  *param_2 = *(undefined4 *)(param_1 + 0x28);
  *param_3 = *(undefined4 *)(param_1 + 0x2c);
  *param_4 = *(undefined4 *)(param_1 + 0x30);
  return;
}

void GXInitLightDir(double param_1,double param_2,double param_3,int param_4)
{
  if (param_4 == 0) {
    OSPanic(...data.0,0x149,@92);
  }
  *(float *)(param_4 + 0x34) = -(float)param_1;
  *(float *)(param_4 + 0x38) = -(float)param_2;
  *(float *)(param_4 + 0x3c) = -(float)param_3;
  return;
}

void GXGetLightDir(int param_1,float *param_2,float *param_3,float *param_4)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x155,@92);
  }
  *param_2 = -*(float *)(param_1 + 0x34);
  *param_3 = -*(float *)(param_1 + 0x38);
  *param_4 = -*(float *)(param_1 + 0x3c);
  return;
}

void GXInitSpecularDir(undefined8 param_1,double param_2,double param_3)
{
  int iVar1;
  double extraout_f1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  
  iVar1 = _savefpr_25();
  dVar3 = extraout_f1;
  if (iVar1 == 0) {
    OSPanic(...data.0,0x16f,@92);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x170,@150);
  }
  dVar6 = -dVar3;
  dVar5 = -param_2;
  dVar4 = (double)(float)((double)@122 + -param_3);
  dVar2 = (double)sqrtf__Ff((double)((float)(dVar4 * dVar4) +
                                    (float)(dVar6 * dVar6) + (float)(dVar5 * dVar5)));
  dVar2 = (double)(float)((double)@122 / dVar2);
  *(float *)(iVar1 + 0x34) = (float)(dVar6 * dVar2);
  *(float *)(iVar1 + 0x38) = (float)(dVar5 * dVar2);
  *(float *)(iVar1 + 0x3c) = (float)(dVar4 * dVar2);
  *(float *)(iVar1 + 0x28) = (float)((double)@151 * -dVar3);
  *(float *)(iVar1 + 0x2c) = (float)((double)@151 * -param_2);
  *(float *)(iVar1 + 0x30) = (float)((double)@151 * -param_3);
  _restfpr_25();
  return;
}

void GXInitSpecularDirHA(double param_1,double param_2,double param_3,double param_4,double param_5,
                        double param_6,int param_7)
{
  if (param_7 == 0) {
    OSPanic(...data.0,0x18e,@92);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,399,@157);
  }
  *(float *)(param_7 + 0x34) = (float)param_4;
  *(float *)(param_7 + 0x38) = (float)param_5;
  *(float *)(param_7 + 0x3c) = (float)param_6;
  *(float *)(param_7 + 0x28) = @151 * -(float)param_1;
  *(float *)(param_7 + 0x2c) = @151 * -(float)param_2;
  *(float *)(param_7 + 0x30) = @151 * -(float)param_3;
  return;
}

void GXInitLightColor(int param_1,byte *param_2)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x1a8,@92);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x1a9,@159);
  }
  *(uint *)(param_1 + 0xc) =
       (uint)param_2[3] | (uint)param_2[2] << 8 | (uint)*param_2 << 0x18 | (uint)param_2[1] << 0x10;
  return;
}

void GXGetLightColor(int param_1,undefined *param_2)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x1b2,@92);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x1b3,@161);
  }
  *param_2 = (char)((uint)*(undefined4 *)(param_1 + 0xc) >> 0x18);
  param_2[1] = (char)((uint)*(undefined4 *)(param_1 + 0xc) >> 0x10);
  param_2[2] = (char)((uint)*(undefined4 *)(param_1 + 0xc) >> 8);
  param_2[3] = (char)*(undefined4 *)(param_1 + 0xc);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXLoadLightObjImm(int param_1,int param_2)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int local_48;
  
  if (param_1 == 0) {
    OSPanic(...data.0,0x1c9,@92);
  }
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x1ca,@413);
  }
  if (param_2 == 0x10) {
    local_48 = 4;
    goto LAB_00010db0;
  }
  if (param_2 < 0x10) {
    if (param_2 == 4) {
      local_48 = 2;
      goto LAB_00010db0;
    }
    if (param_2 < 4) {
      if (param_2 == 2) {
        local_48 = 1;
        goto LAB_00010db0;
      }
      if ((param_2 < 2) && (0 < param_2)) {
        local_48 = 0;
        goto LAB_00010db0;
      }
    }
    else if (param_2 == 8) {
      local_48 = 3;
      goto LAB_00010db0;
    }
  }
  else {
    if (param_2 == 0x40) {
      local_48 = 6;
      goto LAB_00010db0;
    }
    if (param_2 < 0x40) {
      if (param_2 == 0x20) {
        local_48 = 5;
        goto LAB_00010db0;
      }
    }
    else if (param_2 == 0x80) {
      local_48 = 7;
      goto LAB_00010db0;
    }
  }
  local_48 = 0;
  OSPanic(...data.0,0x1da,@414);
LAB_00010db0:
  iVar1 = local_48 * 0x10;
  uVar4 = iVar1 + 0x600;
  if (uVar4 < 0x400) {
    *(undefined4 *)(iRam00000000 + uVar4 * 4 + 0x148) = 0;
    *(undefined *)(iRam00000000 + iVar1 + 0x1718) = 1;
  }
  else if (uVar4 < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x200) * 4 + 0x548) = 0;
    *(undefined *)(iRam00000000 + iVar1 + 0x1418) = 1;
  }
  else if (uVar4 < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x100) * 4 + 0x6c8) = 0;
    *(undefined *)(iRam00000000 + iVar1 + 0x1378) = 1;
  }
  else if (uVar4 < 0x680) {
    *(undefined4 *)(iRam00000000 + local_48 * 0x40 + 0xac8) = 0;
    *(undefined *)(iRam00000000 + iVar1 + 0x1378) = 1;
  }
  else {
    iVar3 = iVar1 + -0xa00;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = 0;
      *(undefined *)(iRam00000000 + iVar1 + 0x6c8) = 1;
    }
  }
  if (iVar1 + 0x601U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x601) * 4 + 0x148) = 0;
    *(undefined *)(uVar4 + iRam00000000 + 0x1119) = 1;
  }
  else if (iVar1 + 0x601U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x201) * 4 + 0x548) = 0;
    *(undefined *)(iRam00000000 + iVar1 + 0x1419) = 1;
  }
  else if (iVar1 + 0x601U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x101) * 4 + 0x6c8) = 0;
    *(undefined *)(iRam00000000 + iVar1 + 0x1379) = 1;
  }
  else if (iVar1 + 0x601U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 1) * 4 + 0xac8) = 0;
    *(undefined *)(iRam00000000 + iVar1 + 0x1379) = 1;
  }
  else {
    iVar3 = iVar1 + -0x9ff;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = 0;
      *(undefined *)(iRam00000000 + iVar1 + 0x6c9) = 1;
    }
  }
  if (iVar1 + 0x602U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x602) * 4 + 0x148) = 0;
    *(undefined *)(uVar4 + iRam00000000 + 0x111a) = 1;
  }
  else if (iVar1 + 0x602U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x202) * 4 + 0x548) = 0;
    *(undefined *)(iRam00000000 + iVar1 + 0x141a) = 1;
  }
  else if (iVar1 + 0x602U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x102) * 4 + 0x6c8) = 0;
    *(undefined *)(iRam00000000 + iVar1 + 0x137a) = 1;
  }
  else if (iVar1 + 0x602U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 2) * 4 + 0xac8) = 0;
    *(undefined *)(iRam00000000 + iVar1 + 0x137a) = 1;
  }
  else {
    iVar3 = iVar1 + -0x9fe;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = 0;
      *(undefined *)(iRam00000000 + iVar1 + 0x6ca) = 1;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0xc);
  if (iVar1 + 0x603U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x603) * 4 + 0x148) = uVar2;
    *(undefined *)(uVar4 + iRam00000000 + 0x111b) = 1;
  }
  else if (iVar1 + 0x603U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x203) * 4 + 0x548) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x141b) = 1;
  }
  else if (iVar1 + 0x603U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x103) * 4 + 0x6c8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x137b) = 1;
  }
  else if (iVar1 + 0x603U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 3) * 4 + 0xac8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x137b) = 1;
  }
  else {
    iVar3 = iVar1 + -0x9fd;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar2;
      *(undefined *)(iRam00000000 + iVar1 + 0x6cb) = 1;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  if (iVar1 + 0x604U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x604) * 4 + 0x148) = uVar2;
    *(undefined *)(uVar4 + iRam00000000 + 0x111c) = 1;
  }
  else if (iVar1 + 0x604U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x204) * 4 + 0x548) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x141c) = 1;
  }
  else if (iVar1 + 0x604U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x104) * 4 + 0x6c8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x137c) = 1;
  }
  else if (iVar1 + 0x604U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 4) * 4 + 0xac8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x137c) = 1;
  }
  else {
    iVar3 = iVar1 + -0x9fc;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar2;
      *(undefined *)(iRam00000000 + iVar1 + 0x6cc) = 1;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0x14);
  if (iVar1 + 0x605U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x605) * 4 + 0x148) = uVar2;
    *(undefined *)(uVar4 + iRam00000000 + 0x111d) = 1;
  }
  else if (iVar1 + 0x605U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x205) * 4 + 0x548) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x141d) = 1;
  }
  else if (iVar1 + 0x605U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x105) * 4 + 0x6c8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x137d) = 1;
  }
  else if (iVar1 + 0x605U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 5) * 4 + 0xac8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x137d) = 1;
  }
  else {
    iVar3 = iVar1 + -0x9fb;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar2;
      *(undefined *)(iRam00000000 + iVar1 + 0x6cd) = 1;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  if (iVar1 + 0x606U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x606) * 4 + 0x148) = uVar2;
    *(undefined *)(uVar4 + iRam00000000 + 0x111e) = 1;
  }
  else if (iVar1 + 0x606U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x206) * 4 + 0x548) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x141e) = 1;
  }
  else if (iVar1 + 0x606U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x106) * 4 + 0x6c8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x137e) = 1;
  }
  else if (iVar1 + 0x606U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 6) * 4 + 0xac8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x137e) = 1;
  }
  else {
    iVar3 = iVar1 + -0x9fa;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar2;
      *(undefined *)(iRam00000000 + iVar1 + 0x6ce) = 1;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0x1c);
  if (iVar1 + 0x607U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x607) * 4 + 0x148) = uVar2;
    *(undefined *)(uVar4 + iRam00000000 + 0x111f) = 1;
  }
  else if (iVar1 + 0x607U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x207) * 4 + 0x548) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x141f) = 1;
  }
  else if (iVar1 + 0x607U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x107) * 4 + 0x6c8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x137f) = 1;
  }
  else if (iVar1 + 0x607U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 7) * 4 + 0xac8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x137f) = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f9;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar2;
      *(undefined *)(iRam00000000 + iVar1 + 0x6cf) = 1;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  if (iVar1 + 0x608U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x608) * 4 + 0x148) = uVar2;
    *(undefined *)(uVar4 + iRam00000000 + 0x1120) = 1;
  }
  else if (iVar1 + 0x608U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x208) * 4 + 0x548) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1420) = 1;
  }
  else if (iVar1 + 0x608U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x108) * 4 + 0x6c8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1380) = 1;
  }
  else if (iVar1 + 0x608U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 8) * 4 + 0xac8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1380) = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f8;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar2;
      *(undefined *)(iRam00000000 + iVar1 + 0x6d0) = 1;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0x24);
  if (iVar1 + 0x609U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x609) * 4 + 0x148) = uVar2;
    *(undefined *)(uVar4 + iRam00000000 + 0x1121) = 1;
  }
  else if (iVar1 + 0x609U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x209) * 4 + 0x548) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1421) = 1;
  }
  else if (iVar1 + 0x609U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x109) * 4 + 0x6c8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1381) = 1;
  }
  else if (iVar1 + 0x609U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 9) * 4 + 0xac8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1381) = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f7;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar2;
      *(undefined *)(iRam00000000 + iVar1 + 0x6d1) = 1;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0x28);
  if (iVar1 + 0x60aU < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x60a) * 4 + 0x148) = uVar2;
    *(undefined *)(uVar4 + iRam00000000 + 0x1122) = 1;
  }
  else if (iVar1 + 0x60aU < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x20a) * 4 + 0x548) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1422) = 1;
  }
  else if (iVar1 + 0x60aU < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x10a) * 4 + 0x6c8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1382) = 1;
  }
  else if (iVar1 + 0x60aU < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 10) * 4 + 0xac8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1382) = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f6;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar2;
      *(undefined *)(iRam00000000 + iVar1 + 0x6d2) = 1;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0x2c);
  if (iVar1 + 0x60bU < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x60b) * 4 + 0x148) = uVar2;
    *(undefined *)(uVar4 + iRam00000000 + 0x1123) = 1;
  }
  else if (iVar1 + 0x60bU < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x20b) * 4 + 0x548) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1423) = 1;
  }
  else if (iVar1 + 0x60bU < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x10b) * 4 + 0x6c8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1383) = 1;
  }
  else if (iVar1 + 0x60bU < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0xb) * 4 + 0xac8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1383) = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f5;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar2;
      *(undefined *)(iRam00000000 + iVar1 + 0x6d3) = 1;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0x30);
  if (iVar1 + 0x60cU < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x60c) * 4 + 0x148) = uVar2;
    *(undefined *)(uVar4 + iRam00000000 + 0x1124) = 1;
  }
  else if (iVar1 + 0x60cU < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x20c) * 4 + 0x548) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1424) = 1;
  }
  else if (iVar1 + 0x60cU < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x10c) * 4 + 0x6c8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1384) = 1;
  }
  else if (iVar1 + 0x60cU < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0xc) * 4 + 0xac8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1384) = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f4;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar2;
      *(undefined *)(iRam00000000 + iVar1 + 0x6d4) = 1;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0x34);
  if (iVar1 + 0x60dU < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x60d) * 4 + 0x148) = uVar2;
    *(undefined *)(uVar4 + iRam00000000 + 0x1125) = 1;
  }
  else if (iVar1 + 0x60dU < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x20d) * 4 + 0x548) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1425) = 1;
  }
  else if (iVar1 + 0x60dU < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x10d) * 4 + 0x6c8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1385) = 1;
  }
  else if (iVar1 + 0x60dU < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0xd) * 4 + 0xac8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1385) = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f3;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar2;
      *(undefined *)(iRam00000000 + iVar1 + 0x6d5) = 1;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0x38);
  if (iVar1 + 0x60eU < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x60e) * 4 + 0x148) = uVar2;
    *(undefined *)(uVar4 + iRam00000000 + 0x1126) = 1;
  }
  else if (iVar1 + 0x60eU < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x20e) * 4 + 0x548) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1426) = 1;
  }
  else if (iVar1 + 0x60eU < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x10e) * 4 + 0x6c8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1386) = 1;
  }
  else if (iVar1 + 0x60eU < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0xe) * 4 + 0xac8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1386) = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f2;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar2;
      *(undefined *)(iRam00000000 + iVar1 + 0x6d6) = 1;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0x3c);
  _DAT_cc008000 = *(undefined4 *)(param_1 + 0x3c);
  if (iVar1 + 0x60fU < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x60f) * 4 + 0x148) = uVar2;
    *(undefined *)(uVar4 + iRam00000000 + 0x1127) = 1;
  }
  else if (iVar1 + 0x60fU < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x20f) * 4 + 0x548) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x1427) = 1;
  }
  else if (iVar1 + 0x60fU < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0x10f) * 4 + 0x6c8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 4999) = 1;
  }
  else if (iVar1 + 0x60fU < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar1 + 0xf) * 4 + 0xac8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 4999) = 1;
  }
  else {
    iVar3 = iVar1 + -0x9f1;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar2;
      *(undefined *)(iRam00000000 + iVar1 + 0x6d7) = 1;
    }
  }
  *(undefined2 *)(iRam00000000 + 2) = 1;
  return;
}

/* WARNING: Removing unreachable block (ram,0x00012220) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXLoadLightObjIndx(uint param_1,int param_2)
{
  int iVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x209,@426);
  }
  if (param_2 == 0x10) {
    iVar1 = 4;
    goto LAB_0001220c;
  }
  if (param_2 < 0x10) {
    if (param_2 == 4) {
      iVar1 = 2;
      goto LAB_0001220c;
    }
    if (param_2 < 4) {
      if (param_2 == 2) {
        iVar1 = 1;
        goto LAB_0001220c;
      }
      if ((param_2 < 2) && (0 < param_2)) {
        iVar1 = 0;
        goto LAB_0001220c;
      }
    }
    else if (param_2 == 8) {
      iVar1 = 3;
      goto LAB_0001220c;
    }
  }
  else {
    if (param_2 == 0x40) {
      iVar1 = 6;
      goto LAB_0001220c;
    }
    if (param_2 < 0x40) {
      if (param_2 == 0x20) {
        iVar1 = 5;
        goto LAB_0001220c;
      }
    }
    else if (param_2 == 0x80) {
      iVar1 = 7;
      goto LAB_0001220c;
    }
  }
  iVar1 = 0;
  OSPanic(...data.0,0x216,@427);
LAB_0001220c:
  if ((param_1 & 0xffff0000) != 0) {
    OSPanic(...data.0,0x21e,@428);
  }
  _DAT_cc008000 = param_1 << 0x10 | iVar1 * 0x10 + 0x600U | 0xf000;
  __GXShadowIndexState(7,_DAT_cc008000);
  *(undefined2 *)(iRam00000000 + 2) = 1;
  return;
}

/* WARNING: Removing unreachable block (ram,0x000124b0) */
/* WARNING: Removing unreachable block (ram,0x00012578) */
/* WARNING: Removing unreachable block (ram,0x00012520) */
/* WARNING: Removing unreachable block (ram,0x0001254c) */
/* WARNING: Removing unreachable block (ram,0x000125a4) */
/* WARNING: Removing unreachable block (ram,0x00012630) */
/* WARNING: Removing unreachable block (ram,0x000125d8) */
/* WARNING: Removing unreachable block (ram,0x00012604) */
/* WARNING: Removing unreachable block (ram,0x0001265c) */
/* WARNING: Removing unreachable block (ram,0x00012474) */
/* WARNING: Removing unreachable block (ram,0x0001241c) */
/* WARNING: Removing unreachable block (ram,0x000123f4) */
/* WARNING: Removing unreachable block (ram,0x00012448) */
/* WARNING: Removing unreachable block (ram,0x000123b8) */
/* WARNING: Removing unreachable block (ram,0x00012338) */
/* WARNING: Removing unreachable block (ram,0x0001238c) */
/* WARNING: Removing unreachable block (ram,0x000124ec) */
/* WARNING: Removing unreachable block (ram,0x00012360) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetChanAmbColor(int param_1,uint *param_2)
{
  int iVar1;
  uint uVar2;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x239,@441);
  }
  if (param_1 == 3) {
    uVar2 = *(uint *)(iRam00000000 + 0xac) & 0xffffff00 | (uint)*(byte *)((int)param_2 + 3);
    iVar1 = 1;
  }
  else if (param_1 < 3) {
    if (param_1 == 1) {
      uVar2 = (uint)*(byte *)param_2 << 0x18 |
              (uint)*(byte *)((int)param_2 + 1) << 0x10 |
              (uint)*(byte *)((int)param_2 + 2) << 8 | *(uint *)(iRam00000000 + 0xac) & 0xff;
      iVar1 = 1;
    }
    else if (param_1 < 1) {
      if (param_1 < 0) goto LAB_00012684;
      uVar2 = (uint)*(byte *)param_2 << 0x18 |
              (uint)*(byte *)((int)param_2 + 1) << 0x10 |
              (uint)*(byte *)((int)param_2 + 2) << 8 | *(uint *)(iRam00000000 + 0xa8) & 0xff;
      iVar1 = 0;
    }
    else {
      uVar2 = *(uint *)(iRam00000000 + 0xa8) & 0xffffff00 | (uint)*(byte *)((int)param_2 + 3);
      iVar1 = 0;
    }
  }
  else if (param_1 == 5) {
    uVar2 = *param_2;
    iVar1 = 1;
  }
  else {
    if (4 < param_1) {
LAB_00012684:
      OSPanic(...data.0,0x26b,@442);
      return;
    }
    uVar2 = *param_2;
    iVar1 = 0;
  }
  _DAT_cc008000 = uVar2;
  if (iVar1 + 10U < 0x50) {
    *(uint *)(iRam00000000 + (iVar1 + 10U) * 4 + 8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x10d2) = 1;
  }
  *(undefined2 *)(iRam00000000 + 2) = 1;
  *(uint *)(iRam00000000 + iVar1 * 4 + 0xa8) = uVar2;
  return;
}

/* WARNING: Removing unreachable block (ram,0x00012928) */
/* WARNING: Removing unreachable block (ram,0x000129f0) */
/* WARNING: Removing unreachable block (ram,0x00012998) */
/* WARNING: Removing unreachable block (ram,0x000129c4) */
/* WARNING: Removing unreachable block (ram,0x00012a1c) */
/* WARNING: Removing unreachable block (ram,0x00012aa8) */
/* WARNING: Removing unreachable block (ram,0x00012a50) */
/* WARNING: Removing unreachable block (ram,0x00012a7c) */
/* WARNING: Removing unreachable block (ram,0x00012ad4) */
/* WARNING: Removing unreachable block (ram,0x000128ec) */
/* WARNING: Removing unreachable block (ram,0x00012894) */
/* WARNING: Removing unreachable block (ram,0x0001286c) */
/* WARNING: Removing unreachable block (ram,0x000128c0) */
/* WARNING: Removing unreachable block (ram,0x00012830) */
/* WARNING: Removing unreachable block (ram,0x000127b0) */
/* WARNING: Removing unreachable block (ram,0x00012804) */
/* WARNING: Removing unreachable block (ram,0x00012964) */
/* WARNING: Removing unreachable block (ram,0x000127d8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetChanMatColor(int param_1,uint *param_2)
{
  int iVar1;
  uint uVar2;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x28a,@455);
  }
  if (param_1 == 3) {
    uVar2 = *(uint *)(iRam00000000 + 0xb4) & 0xffffff00 | (uint)*(byte *)((int)param_2 + 3);
    iVar1 = 1;
  }
  else if (param_1 < 3) {
    if (param_1 == 1) {
      uVar2 = (uint)*(byte *)param_2 << 0x18 |
              (uint)*(byte *)((int)param_2 + 1) << 0x10 |
              (uint)*(byte *)((int)param_2 + 2) << 8 | *(uint *)(iRam00000000 + 0xb4) & 0xff;
      iVar1 = 1;
    }
    else if (param_1 < 1) {
      if (param_1 < 0) goto LAB_00012afc;
      uVar2 = (uint)*(byte *)param_2 << 0x18 |
              (uint)*(byte *)((int)param_2 + 1) << 0x10 |
              (uint)*(byte *)((int)param_2 + 2) << 8 | *(uint *)(iRam00000000 + 0xb0) & 0xff;
      iVar1 = 0;
    }
    else {
      uVar2 = *(uint *)(iRam00000000 + 0xb0) & 0xffffff00 | (uint)*(byte *)((int)param_2 + 3);
      iVar1 = 0;
    }
  }
  else if (param_1 == 5) {
    uVar2 = *param_2;
    iVar1 = 1;
  }
  else {
    if (4 < param_1) {
LAB_00012afc:
      OSPanic(...data.0,700,@456);
      return;
    }
    uVar2 = *param_2;
    iVar1 = 0;
  }
  _DAT_cc008000 = uVar2;
  if (iVar1 + 0xcU < 0x50) {
    *(uint *)(iRam00000000 + (iVar1 + 0xcU) * 4 + 8) = uVar2;
    *(undefined *)(iRam00000000 + iVar1 + 0x10d4) = 1;
  }
  *(undefined2 *)(iRam00000000 + 2) = 1;
  *(uint *)(iRam00000000 + iVar1 * 4 + 0xb0) = uVar2;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetNumChans(byte param_1)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x2d5,@461);
  }
  if (2 < param_1) {
    OSPanic(...data.0,0x2d6,@462);
  }
  if ((param_1 & 0xf8) != 0) {
    OSPanic(...data.0,0x2d8,@428);
  }
  *(uint *)(iRam00000000 + 0x204) =
       *(uint *)(iRam00000000 + 0x204) & 0xffffff8f | (uint)param_1 << 4;
  _DAT_cc008000 = (uint)param_1;
  *(uint *)(iRam00000000 + 0x2c) = (uint)param_1;
  *(undefined *)(iRam00000000 + 0x10d1) = 1;
  *(uint *)(iRam00000000 + 0x4f4) = *(uint *)(iRam00000000 + 0x4f4) | 4;
  return;
}

/* WARNING: Removing unreachable block (ram,0x0001300c) */
/* WARNING: Removing unreachable block (ram,0x00012f6c) */
/* WARNING: Removing unreachable block (ram,0x00012ecc) */
/* WARNING: Removing unreachable block (ram,0x00012e2c) */
/* WARNING: Removing unreachable block (ram,0x00012ddc) */
/* WARNING: Removing unreachable block (ram,0x00012e7c) */
/* WARNING: Removing unreachable block (ram,0x00012f1c) */
/* WARNING: Removing unreachable block (ram,0x00012fbc) */
/* WARNING: Removing unreachable block (ram,0x000130e8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetChanCtrl(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
                  int param_7)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x2f8,@484);
  }
  if ((param_1 < 0) || (5 < param_1)) {
    OSPanic(...data.0,0x2fb,@485);
  }
  if (param_1 == 4) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1;
    if (param_1 == 5) {
      iVar2 = 1;
    }
  }
  if ((param_2 & 0xfe) != 0) {
    OSPanic(...data.0,0x302,@428);
  }
  if ((param_4 & 0xfffffffe) != 0) {
    OSPanic(...data.0,0x303,@428);
  }
  if ((param_3 & 0xfffffffe) != 0) {
    OSPanic(...data.0,0x304,@428);
  }
  uVar3 = param_6;
  if (param_7 == 0) {
    uVar3 = 0;
  }
  if ((uVar3 & 0xfffffffc) != 0) {
    OSPanic(...data.0,0x30e,@428);
  }
  if (param_7 == 0) {
    param_6 = 0;
  }
  iVar1 = -param_7 + 2;
  if ((iVar1 + (-(uint)(iVar1 == 0) - (-param_7 + 1)) & 0xfffffffe) != 0) {
    OSPanic(...data.0,0x30f,@428);
  }
  iVar1 = -param_7 + 2;
  uVar3 = ((((((((((param_2 & 0xff) << 1 | param_4) & 0xffffffbb | param_3 << 6 |
                 (uint)((param_5 & 1) != 0) * 4) & 0xfffffff7 | (uint)((param_5 & 2) != 0) * 8) &
                0xffffffef | (uint)((param_5 & 4) != 0) * 0x10) & 0xfffff7df |
               (uint)((param_5 & 8) != 0) * 0x20 | (uint)((param_5 & 0x10) != 0) * 0x800) &
              0xffffefff | (uint)((param_5 & 0x20) != 0) * 0x1000) & 0xffffdfff |
            (uint)((param_5 & 0x40) != 0) * 0x2000) & 0xffffbe7f |
            (uint)((param_5 & 0x80) != 0) * 0x4000 | param_6 << 7) & 0xfffffdff |
          (iVar1 + (-(uint)(iVar1 == 0) - (-param_7 + 1))) * 0x200) & 0xfffffbff |
          (uint)(param_7 != 0) * 0x400;
  iVar1 = iVar2 + 0xe;
  _DAT_cc008000 = uVar3;
  if ((-1 < iVar1) && (iVar1 < 0x50)) {
    *(uint *)(iRam00000000 + iVar1 * 4 + 8) = uVar3;
    *(undefined *)(iRam00000000 + iVar2 + 0x10d6) = 1;
  }
  *(undefined2 *)(iRam00000000 + 2) = 1;
  if (param_1 == 4) {
    _DAT_cc008000 = uVar3;
    *(uint *)(iRam00000000 + 0x48) = uVar3;
    *(undefined *)(iRam00000000 + 0x10d8) = 1;
  }
  else if (param_1 == 5) {
    _DAT_cc008000 = uVar3;
    *(uint *)(iRam00000000 + 0x4c) = uVar3;
    *(undefined *)(iRam00000000 + 0x10d9) = 1;
  }
  return;
}
