void GXProject(undefined8 param_1,double param_2,double param_3,undefined4 param_4,
              undefined4 param_5,float *param_6,float *param_7,float *param_8,float *param_9)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  double extraout_f1;
  double dVar7;
  undefined8 uVar8;
  
  uVar8 = _savefpr_25();
  pfVar5 = (float *)((ulonglong)uVar8 >> 0x20);
  pfVar6 = (float *)uVar8;
  dVar7 = extraout_f1;
  if ((((pfVar6 == (float *)0x0) || (param_6 == (float *)0x0)) || (param_7 == (float *)0x0)) ||
     ((param_8 == (float *)0x0 || (param_9 == (float *)0x0)))) {
    OSPanic(...data.0,0x93,@11);
  }
  fVar1 = pfVar5[3] +
          (float)((double)pfVar5[2] * param_3) +
          (float)((double)*pfVar5 * dVar7) + (float)((double)pfVar5[1] * param_2);
  fVar2 = pfVar5[7] +
          (float)((double)pfVar5[6] * param_3) +
          (float)((double)pfVar5[4] * dVar7) + (float)((double)pfVar5[5] * param_2);
  fVar3 = pfVar5[0xb] +
          (float)((double)pfVar5[10] * param_3) +
          (float)((double)pfVar5[8] * dVar7) + (float)((double)pfVar5[9] * param_2);
  if (@12 == *pfVar6) {
    fVar1 = fVar1 * pfVar6[1] + fVar3 * pfVar6[2];
    fVar2 = fVar2 * pfVar6[3] + fVar3 * pfVar6[4];
    fVar4 = pfVar6[6] + fVar3 * pfVar6[5];
    fVar3 = @13 / -fVar3;
  }
  else {
    fVar1 = pfVar6[2] + fVar1 * pfVar6[1];
    fVar2 = pfVar6[4] + fVar2 * pfVar6[3];
    fVar4 = pfVar6[6] + fVar3 * pfVar6[5];
    fVar3 = @13;
  }
  *param_7 = param_6[2] * @14 + *param_6 + fVar3 * fVar1 * param_6[2] * @14;
  *param_8 = param_6[3] * @14 + param_6[1] + fVar3 * -fVar2 * param_6[3] * @14;
  *param_9 = param_6[5] + fVar3 * fVar4 * (param_6[5] - param_6[4]);
  _restfpr_25();
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetProjection(undefined4 *param_1,int param_2)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0xcd,@124);
  }
  *(int *)(iRam00000000 + 0x420) = param_2;
  *(undefined4 *)(iRam00000000 + 0x424) = *param_1;
  *(undefined4 *)(iRam00000000 + 0x42c) = param_1[5];
  *(undefined4 *)(iRam00000000 + 0x434) = param_1[10];
  *(undefined4 *)(iRam00000000 + 0x438) = param_1[0xb];
  if (param_2 == 1) {
    *(undefined4 *)(iRam00000000 + 0x428) = param_1[3];
    *(undefined4 *)(iRam00000000 + 0x430) = param_1[7];
  }
  else {
    *(undefined4 *)(iRam00000000 + 0x428) = param_1[2];
    *(undefined4 *)(iRam00000000 + 0x430) = param_1[6];
  }
  *(undefined4 *)(iRam00000000 + 0x88) = *(undefined4 *)(iRam00000000 + 0x424);
  *(undefined *)(iRam00000000 + 0x10e8) = 1;
  *(undefined4 *)(iRam00000000 + 0x8c) = *(undefined4 *)(iRam00000000 + 0x428);
  *(undefined *)(iRam00000000 + 0x10e9) = 1;
  *(undefined4 *)(iRam00000000 + 0x90) = *(undefined4 *)(iRam00000000 + 0x42c);
  *(undefined *)(iRam00000000 + 0x10ea) = 1;
  *(undefined4 *)(iRam00000000 + 0x94) = *(undefined4 *)(iRam00000000 + 0x430);
  *(undefined *)(iRam00000000 + 0x10eb) = 1;
  *(undefined4 *)(iRam00000000 + 0x98) = *(undefined4 *)(iRam00000000 + 0x434);
  *(undefined *)(iRam00000000 + 0x10ec) = 1;
  *(undefined4 *)(iRam00000000 + 0x9c) = *(undefined4 *)(iRam00000000 + 0x438);
  *(undefined *)(iRam00000000 + 0x10ed) = 1;
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x420);
  *(undefined4 *)(iRam00000000 + 0xa0) = *(undefined4 *)(iRam00000000 + 0x420);
  *(undefined *)(iRam00000000 + 0x10ee) = 1;
  *(undefined2 *)(iRam00000000 + 2) = 1;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetProjectionv(float *param_1)
{
  undefined4 uVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x109,@231);
  }
  uVar1 = __cvt_fp2unsigned((double)*param_1);
  *(undefined4 *)(iRam00000000 + 0x420) = uVar1;
  *(float *)(iRam00000000 + 0x424) = param_1[1];
  *(float *)(iRam00000000 + 0x428) = param_1[2];
  *(float *)(iRam00000000 + 0x42c) = param_1[3];
  *(float *)(iRam00000000 + 0x430) = param_1[4];
  *(float *)(iRam00000000 + 0x434) = param_1[5];
  *(float *)(iRam00000000 + 0x438) = param_1[6];
  *(undefined4 *)(iRam00000000 + 0x88) = *(undefined4 *)(iRam00000000 + 0x424);
  *(undefined *)(iRam00000000 + 0x10e8) = 1;
  *(undefined4 *)(iRam00000000 + 0x8c) = *(undefined4 *)(iRam00000000 + 0x428);
  *(undefined *)(iRam00000000 + 0x10e9) = 1;
  *(undefined4 *)(iRam00000000 + 0x90) = *(undefined4 *)(iRam00000000 + 0x42c);
  *(undefined *)(iRam00000000 + 0x10ea) = 1;
  *(undefined4 *)(iRam00000000 + 0x94) = *(undefined4 *)(iRam00000000 + 0x430);
  *(undefined *)(iRam00000000 + 0x10eb) = 1;
  *(undefined4 *)(iRam00000000 + 0x98) = *(undefined4 *)(iRam00000000 + 0x434);
  *(undefined *)(iRam00000000 + 0x10ec) = 1;
  *(undefined4 *)(iRam00000000 + 0x9c) = *(undefined4 *)(iRam00000000 + 0x438);
  *(undefined *)(iRam00000000 + 0x10ed) = 1;
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x420);
  *(undefined4 *)(iRam00000000 + 0xa0) = *(undefined4 *)(iRam00000000 + 0x420);
  *(undefined *)(iRam00000000 + 0x10ee) = 1;
  *(undefined2 *)(iRam00000000 + 2) = 1;
  return;
}

void GXGetProjectionv(float *param_1)
{
  if (param_1 == (float *)0x0) {
    OSPanic(...data.0,0x12e,@11);
  }
  *param_1 = (float)((double)CONCAT44(0x43300000,*(undefined4 *)(iRam00000000 + 0x420)) - @234);
  param_1[1] = *(float *)(iRam00000000 + 0x424);
  param_1[2] = *(float *)(iRam00000000 + 0x428);
  param_1[3] = *(float *)(iRam00000000 + 0x42c);
  param_1[4] = *(float *)(iRam00000000 + 0x430);
  param_1[5] = *(float *)(iRam00000000 + 0x434);
  param_1[6] = *(float *)(iRam00000000 + 0x438);
  return;
}

// TODO: WriteMTXPS4x3

// TODO: WriteMTXPS3x3from3x4

// TODO: WriteMTXPS3x3

// TODO: WriteMTXPS4x2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXLoadPosMtxImm(undefined4 *param_1,int param_2)
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x1d8,@416);
  }
  uVar2 = param_2 * 4;
  uVar1 = *param_1;
  if (uVar2 < 0x400) {
    *(undefined4 *)(iRam00000000 + param_2 * 0x10 + 0x148) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0x1118) = 1;
  }
  else if (uVar2 < 0x500) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x400) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xe18) = 1;
  }
  else if (uVar2 < 0x600) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x500) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd78) = 1;
  }
  else if (uVar2 < 0x680) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x600) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd78) = 1;
  }
  else {
    iVar3 = uVar2 - 0x1000;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + uVar2 + 200) = 1;
    }
  }
  uVar1 = param_1[1];
  if (uVar2 + 1 < 0x400) {
    *(undefined4 *)(iRam00000000 + (uVar2 + 1) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar2 + iRam00000000 + 0x1119) = 1;
  }
  else if (uVar2 + 1 < 0x500) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x3ff) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xe19) = 1;
  }
  else if (uVar2 + 1 < 0x600) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x4ff) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd79) = 1;
  }
  else if (uVar2 + 1 < 0x680) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x5ff) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd79) = 1;
  }
  else {
    iVar3 = uVar2 - 0xfff;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + uVar2 + 0xc9) = 1;
    }
  }
  uVar1 = param_1[2];
  if (uVar2 + 2 < 0x400) {
    *(undefined4 *)(iRam00000000 + (uVar2 + 2) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar2 + iRam00000000 + 0x111a) = 1;
  }
  else if (uVar2 + 2 < 0x500) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x3fe) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xe1a) = 1;
  }
  else if (uVar2 + 2 < 0x600) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x4fe) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd7a) = 1;
  }
  else if (uVar2 + 2 < 0x680) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x5fe) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd7a) = 1;
  }
  else {
    iVar3 = uVar2 - 0xffe;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + uVar2 + 0xca) = 1;
    }
  }
  uVar1 = param_1[3];
  if (uVar2 + 3 < 0x400) {
    *(undefined4 *)(iRam00000000 + (uVar2 + 3) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar2 + iRam00000000 + 0x111b) = 1;
  }
  else if (uVar2 + 3 < 0x500) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x3fd) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xe1b) = 1;
  }
  else if (uVar2 + 3 < 0x600) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x4fd) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd7b) = 1;
  }
  else if (uVar2 + 3 < 0x680) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x5fd) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd7b) = 1;
  }
  else {
    iVar3 = uVar2 - 0xffd;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + uVar2 + 0xcb) = 1;
    }
  }
  uVar1 = param_1[4];
  if (uVar2 + 4 < 0x400) {
    *(undefined4 *)(iRam00000000 + (uVar2 + 4) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar2 + iRam00000000 + 0x111c) = 1;
  }
  else if (uVar2 + 4 < 0x500) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x3fc) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xe1c) = 1;
  }
  else if (uVar2 + 4 < 0x600) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x4fc) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd7c) = 1;
  }
  else if (uVar2 + 4 < 0x680) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x5fc) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd7c) = 1;
  }
  else {
    iVar3 = uVar2 - 0xffc;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + uVar2 + 0xcc) = 1;
    }
  }
  uVar1 = param_1[5];
  if (uVar2 + 5 < 0x400) {
    *(undefined4 *)(iRam00000000 + (uVar2 + 5) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar2 + iRam00000000 + 0x111d) = 1;
  }
  else if (uVar2 + 5 < 0x500) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x3fb) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xe1d) = 1;
  }
  else if (uVar2 + 5 < 0x600) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x4fb) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd7d) = 1;
  }
  else if (uVar2 + 5 < 0x680) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x5fb) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd7d) = 1;
  }
  else {
    iVar3 = uVar2 - 0xffb;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + uVar2 + 0xcd) = 1;
    }
  }
  uVar1 = param_1[6];
  if (uVar2 + 6 < 0x400) {
    *(undefined4 *)(iRam00000000 + (uVar2 + 6) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar2 + iRam00000000 + 0x111e) = 1;
  }
  else if (uVar2 + 6 < 0x500) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x3fa) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xe1e) = 1;
  }
  else if (uVar2 + 6 < 0x600) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x4fa) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd7e) = 1;
  }
  else if (uVar2 + 6 < 0x680) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x5fa) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd7e) = 1;
  }
  else {
    iVar3 = uVar2 - 0xffa;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + uVar2 + 0xce) = 1;
    }
  }
  uVar1 = param_1[7];
  if (uVar2 + 7 < 0x400) {
    *(undefined4 *)(iRam00000000 + (uVar2 + 7) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar2 + iRam00000000 + 0x111f) = 1;
  }
  else if (uVar2 + 7 < 0x500) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x3f9) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xe1f) = 1;
  }
  else if (uVar2 + 7 < 0x600) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x4f9) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd7f) = 1;
  }
  else if (uVar2 + 7 < 0x680) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x5f9) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd7f) = 1;
  }
  else {
    iVar3 = uVar2 - 0xff9;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + uVar2 + 0xcf) = 1;
    }
  }
  uVar1 = param_1[8];
  if (uVar2 + 8 < 0x400) {
    *(undefined4 *)(iRam00000000 + (uVar2 + 8) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar2 + iRam00000000 + 0x1120) = 1;
  }
  else if (uVar2 + 8 < 0x500) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x3f8) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xe20) = 1;
  }
  else if (uVar2 + 8 < 0x600) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x4f8) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd80) = 1;
  }
  else if (uVar2 + 8 < 0x680) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x5f8) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd80) = 1;
  }
  else {
    iVar3 = uVar2 - 0xff8;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + uVar2 + 0xd0) = 1;
    }
  }
  uVar1 = param_1[9];
  if (uVar2 + 9 < 0x400) {
    *(undefined4 *)(iRam00000000 + (uVar2 + 9) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar2 + iRam00000000 + 0x1121) = 1;
  }
  else if (uVar2 + 9 < 0x500) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x3f7) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xe21) = 1;
  }
  else if (uVar2 + 9 < 0x600) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x4f7) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd81) = 1;
  }
  else if (uVar2 + 9 < 0x680) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x5f7) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd81) = 1;
  }
  else {
    iVar3 = uVar2 - 0xff7;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + uVar2 + 0xd1) = 1;
    }
  }
  uVar1 = param_1[10];
  if (uVar2 + 10 < 0x400) {
    *(undefined4 *)(iRam00000000 + (uVar2 + 10) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar2 + iRam00000000 + 0x1122) = 1;
  }
  else if (uVar2 + 10 < 0x500) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x3f6) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xe22) = 1;
  }
  else if (uVar2 + 10 < 0x600) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x4f6) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd82) = 1;
  }
  else if (uVar2 + 10 < 0x680) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x5f6) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd82) = 1;
  }
  else {
    iVar3 = uVar2 - 0xff6;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + uVar2 + 0xd2) = 1;
    }
  }
  uVar1 = param_1[0xb];
  _DAT_cc008000 = param_1[0xb];
  if (uVar2 + 0xb < 0x400) {
    *(undefined4 *)(iRam00000000 + (uVar2 + 0xb) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar2 + iRam00000000 + 0x1123) = 1;
  }
  else if (uVar2 + 0xb < 0x500) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x3f5) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xe23) = 1;
  }
  else if (uVar2 + 0xb < 0x600) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x4f5) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd83) = 1;
  }
  else if (uVar2 + 0xb < 0x680) {
    *(undefined4 *)(iRam00000000 + (uVar2 - 0x5f5) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + uVar2 + 0xd83) = 1;
  }
  else {
    iVar3 = uVar2 - 0xff5;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + uVar2 + 0xd3) = 1;
    }
  }
  return;
}

/* WARNING: Removing unreachable block (ram,0x00011958) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXLoadPosMtxIndx(int param_1,int param_2)
{
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x208,@418);
  }
  if ((param_2 << 2 & 0xfffff000U) != 0) {
    OSPanic(...data.0,0x20e,@419);
  }
  _DAT_cc008000 = param_2 << 2 & 0xffcU | 0xb000 | param_1 << 0x10;
  __GXShadowIndexState(4,_DAT_cc008000);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXLoadNrmMtxImm(undefined4 *param_1,int param_2)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x229,@556);
  }
  iVar2 = param_2 * 3;
  uVar4 = iVar2 + 0x400;
  uVar1 = *param_1;
  if (uVar4 < 0x400) {
    *(undefined4 *)(iRam00000000 + uVar4 * 4 + 0x148) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1518) = 1;
  }
  else if (uVar4 < 0x500) {
    *(undefined4 *)(iRam00000000 + param_2 * 0xc + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1218) = 1;
  }
  else if (uVar4 < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x100) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1178) = 1;
  }
  else if (uVar4 < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x200) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1178) = 1;
  }
  else {
    iVar3 = iVar2 + -0xc00;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4c8) = 1;
    }
  }
  uVar1 = param_1[1];
  if (iVar2 + 0x401U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 0x401) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar4 + iRam00000000 + 0x1119) = 1;
  }
  else if (iVar2 + 0x401U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 1) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1219) = 1;
  }
  else if (iVar2 + 0x401U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0xff) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1179) = 1;
  }
  else if (iVar2 + 0x401U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x1ff) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1179) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbff;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4c9) = 1;
    }
  }
  uVar1 = param_1[2];
  if (iVar2 + 0x402U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 0x402) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar4 + iRam00000000 + 0x111a) = 1;
  }
  else if (iVar2 + 0x402U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 2) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x121a) = 1;
  }
  else if (iVar2 + 0x402U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0xfe) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117a) = 1;
  }
  else if (iVar2 + 0x402U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x1fe) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117a) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbfe;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4ca) = 1;
    }
  }
  uVar1 = param_1[4];
  if (iVar2 + 0x403U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 0x403) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar4 + iRam00000000 + 0x111b) = 1;
  }
  else if (iVar2 + 0x403U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 3) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x121b) = 1;
  }
  else if (iVar2 + 0x403U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0xfd) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117b) = 1;
  }
  else if (iVar2 + 0x403U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x1fd) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117b) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbfd;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4cb) = 1;
    }
  }
  uVar1 = param_1[5];
  if (iVar2 + 0x404U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 0x404) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar4 + iRam00000000 + 0x111c) = 1;
  }
  else if (iVar2 + 0x404U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 4) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x121c) = 1;
  }
  else if (iVar2 + 0x404U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0xfc) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117c) = 1;
  }
  else if (iVar2 + 0x404U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x1fc) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117c) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbfc;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4cc) = 1;
    }
  }
  uVar1 = param_1[6];
  if (iVar2 + 0x405U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 0x405) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar4 + iRam00000000 + 0x111d) = 1;
  }
  else if (iVar2 + 0x405U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 5) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x121d) = 1;
  }
  else if (iVar2 + 0x405U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0xfb) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117d) = 1;
  }
  else if (iVar2 + 0x405U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x1fb) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117d) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbfb;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4cd) = 1;
    }
  }
  uVar1 = param_1[8];
  if (iVar2 + 0x406U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 0x406) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar4 + iRam00000000 + 0x111e) = 1;
  }
  else if (iVar2 + 0x406U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 6) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x121e) = 1;
  }
  else if (iVar2 + 0x406U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0xfa) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117e) = 1;
  }
  else if (iVar2 + 0x406U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x1fa) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117e) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbfa;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4ce) = 1;
    }
  }
  uVar1 = param_1[9];
  if (iVar2 + 0x407U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 0x407) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar4 + iRam00000000 + 0x111f) = 1;
  }
  else if (iVar2 + 0x407U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 7) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x121f) = 1;
  }
  else if (iVar2 + 0x407U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0xf9) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117f) = 1;
  }
  else if (iVar2 + 0x407U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x1f9) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117f) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbf9;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4cf) = 1;
    }
  }
  uVar1 = param_1[10];
  _DAT_cc008000 = param_1[10];
  if (iVar2 + 0x408U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 0x408) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar4 + iRam00000000 + 0x1120) = 1;
  }
  else if (iVar2 + 0x408U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 8) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1220) = 1;
  }
  else if (iVar2 + 0x408U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0xf8) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1180) = 1;
  }
  else if (iVar2 + 0x408U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x1f8) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1180) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbf8;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4d0) = 1;
    }
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXLoadNrmMtxImm3x3(undefined4 *param_1,int param_2)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x256,@693);
  }
  iVar2 = param_2 * 3;
  uVar4 = iVar2 + 0x400;
  uVar1 = *param_1;
  if (uVar4 < 0x400) {
    *(undefined4 *)(iRam00000000 + uVar4 * 4 + 0x148) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1518) = 1;
  }
  else if (uVar4 < 0x500) {
    *(undefined4 *)(iRam00000000 + param_2 * 0xc + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1218) = 1;
  }
  else if (uVar4 < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x100) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1178) = 1;
  }
  else if (uVar4 < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x200) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1178) = 1;
  }
  else {
    iVar3 = iVar2 + -0xc00;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4c8) = 1;
    }
  }
  uVar1 = param_1[1];
  if (iVar2 + 0x401U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 0x401) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar4 + iRam00000000 + 0x1119) = 1;
  }
  else if (iVar2 + 0x401U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 1) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1219) = 1;
  }
  else if (iVar2 + 0x401U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0xff) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1179) = 1;
  }
  else if (iVar2 + 0x401U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x1ff) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1179) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbff;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4c9) = 1;
    }
  }
  uVar1 = param_1[2];
  if (iVar2 + 0x402U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 0x402) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar4 + iRam00000000 + 0x111a) = 1;
  }
  else if (iVar2 + 0x402U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 2) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x121a) = 1;
  }
  else if (iVar2 + 0x402U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0xfe) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117a) = 1;
  }
  else if (iVar2 + 0x402U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x1fe) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117a) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbfe;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4ca) = 1;
    }
  }
  uVar1 = param_1[3];
  if (iVar2 + 0x403U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 0x403) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar4 + iRam00000000 + 0x111b) = 1;
  }
  else if (iVar2 + 0x403U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 3) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x121b) = 1;
  }
  else if (iVar2 + 0x403U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0xfd) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117b) = 1;
  }
  else if (iVar2 + 0x403U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x1fd) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117b) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbfd;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4cb) = 1;
    }
  }
  uVar1 = param_1[4];
  if (iVar2 + 0x404U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 0x404) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar4 + iRam00000000 + 0x111c) = 1;
  }
  else if (iVar2 + 0x404U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 4) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x121c) = 1;
  }
  else if (iVar2 + 0x404U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0xfc) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117c) = 1;
  }
  else if (iVar2 + 0x404U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x1fc) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117c) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbfc;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4cc) = 1;
    }
  }
  uVar1 = param_1[5];
  if (iVar2 + 0x405U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 0x405) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar4 + iRam00000000 + 0x111d) = 1;
  }
  else if (iVar2 + 0x405U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 5) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x121d) = 1;
  }
  else if (iVar2 + 0x405U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0xfb) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117d) = 1;
  }
  else if (iVar2 + 0x405U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x1fb) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117d) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbfb;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4cd) = 1;
    }
  }
  uVar1 = param_1[6];
  if (iVar2 + 0x406U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 0x406) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar4 + iRam00000000 + 0x111e) = 1;
  }
  else if (iVar2 + 0x406U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 6) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x121e) = 1;
  }
  else if (iVar2 + 0x406U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0xfa) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117e) = 1;
  }
  else if (iVar2 + 0x406U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x1fa) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117e) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbfa;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4ce) = 1;
    }
  }
  uVar1 = param_1[7];
  if (iVar2 + 0x407U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 0x407) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar4 + iRam00000000 + 0x111f) = 1;
  }
  else if (iVar2 + 0x407U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 7) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x121f) = 1;
  }
  else if (iVar2 + 0x407U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0xf9) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117f) = 1;
  }
  else if (iVar2 + 0x407U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x1f9) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x117f) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbf9;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4cf) = 1;
    }
  }
  uVar1 = param_1[8];
  _DAT_cc008000 = param_1[8];
  if (iVar2 + 0x408U < 0x400) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 0x408) * 4 + 0x148) = uVar1;
    *(undefined *)(uVar4 + iRam00000000 + 0x1120) = 1;
  }
  else if (iVar2 + 0x408U < 0x500) {
    *(undefined4 *)(iRam00000000 + (iVar2 + 8) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1220) = 1;
  }
  else if (iVar2 + 0x408U < 0x600) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0xf8) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1180) = 1;
  }
  else if (iVar2 + 0x408U < 0x680) {
    *(undefined4 *)(iRam00000000 + (iVar2 + -0x1f8) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + iVar2 + 0x1180) = 1;
  }
  else {
    iVar3 = iVar2 + -0xbf8;
    if ((-1 < iVar3) && (iVar3 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar3 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + iVar2 + 0x4d0) = 1;
    }
  }
  return;
}

/* WARNING: Removing unreachable block (ram,0x00013084) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXLoadNrmMtxIndx3x3(int param_1,int param_2)
{
  uint uVar1;
  
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x284,@695);
  }
  uVar1 = param_2 * 3 + 0x400;
  if ((uVar1 & 0xfffff000) != 0) {
    OSPanic(...data.0,0x28a,@419);
  }
  _DAT_cc008000 = uVar1 & 0xfff | 0x8000 | param_1 << 0x10;
  __GXShadowIndexState(5,_DAT_cc008000);
  return;
}

void GXSetCurrentMtx(uint param_1)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x2a1,@697);
  }
  if ((param_1 & 0xffffffc0) != 0) {
    OSPanic(...data.0,0x2a5,@419);
  }
  *(uint *)(iRam00000000 + 0x80) = *(uint *)(iRam00000000 + 0x80) & 0xffffffc0 | param_1;
  __GXSetMatrixIndex(0);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXLoadTexMtxImm(undefined4 *param_1,uint param_2,int param_3)
{
  undefined4 uVar1;
  int iVar2;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x2c2,@884);
  }
  if (param_2 < 0x40) {
    param_2 = param_2 << 2;
  }
  else {
    param_2 = (param_2 - 0x40) * 4 + 0x500;
    if (param_3 != 0) {
      OSPanic(...data.0,0x2cc,@885);
    }
  }
  uVar1 = *param_1;
  if (param_2 < 0x400) {
    *(undefined4 *)(iRam00000000 + param_2 * 4 + 0x148) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0x1118) = 1;
  }
  else if (param_2 < 0x500) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x400) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xe18) = 1;
  }
  else if (param_2 < 0x600) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x500) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xd78) = 1;
  }
  else if (param_2 < 0x680) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x600) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xd78) = 1;
  }
  else {
    iVar2 = param_2 - 0x1000;
    if ((-1 < iVar2) && (iVar2 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar2 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 200) = 1;
    }
  }
  uVar1 = param_1[1];
  if (param_2 + 1 < 0x400) {
    *(undefined4 *)(iRam00000000 + (param_2 + 1) * 4 + 0x148) = uVar1;
    *(undefined *)(param_2 + iRam00000000 + 0x1119) = 1;
  }
  else if (param_2 + 1 < 0x500) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x3ff) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xe19) = 1;
  }
  else if (param_2 + 1 < 0x600) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x4ff) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xd79) = 1;
  }
  else if (param_2 + 1 < 0x680) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x5ff) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xd79) = 1;
  }
  else {
    iVar2 = param_2 - 0xfff;
    if ((-1 < iVar2) && (iVar2 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar2 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xc9) = 1;
    }
  }
  uVar1 = param_1[2];
  if (param_2 + 2 < 0x400) {
    *(undefined4 *)(iRam00000000 + (param_2 + 2) * 4 + 0x148) = uVar1;
    *(undefined *)(param_2 + iRam00000000 + 0x111a) = 1;
  }
  else if (param_2 + 2 < 0x500) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x3fe) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xe1a) = 1;
  }
  else if (param_2 + 2 < 0x600) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x4fe) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xd7a) = 1;
  }
  else if (param_2 + 2 < 0x680) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x5fe) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xd7a) = 1;
  }
  else {
    iVar2 = param_2 - 0xffe;
    if ((-1 < iVar2) && (iVar2 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar2 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xca) = 1;
    }
  }
  uVar1 = param_1[3];
  if (param_2 + 3 < 0x400) {
    *(undefined4 *)(iRam00000000 + (param_2 + 3) * 4 + 0x148) = uVar1;
    *(undefined *)(param_2 + iRam00000000 + 0x111b) = 1;
  }
  else if (param_2 + 3 < 0x500) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x3fd) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xe1b) = 1;
  }
  else if (param_2 + 3 < 0x600) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x4fd) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xd7b) = 1;
  }
  else if (param_2 + 3 < 0x680) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x5fd) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xd7b) = 1;
  }
  else {
    iVar2 = param_2 - 0xffd;
    if ((-1 < iVar2) && (iVar2 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar2 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xcb) = 1;
    }
  }
  uVar1 = param_1[4];
  if (param_2 + 4 < 0x400) {
    *(undefined4 *)(iRam00000000 + (param_2 + 4) * 4 + 0x148) = uVar1;
    *(undefined *)(param_2 + iRam00000000 + 0x111c) = 1;
  }
  else if (param_2 + 4 < 0x500) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x3fc) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xe1c) = 1;
  }
  else if (param_2 + 4 < 0x600) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x4fc) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xd7c) = 1;
  }
  else if (param_2 + 4 < 0x680) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x5fc) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xd7c) = 1;
  }
  else {
    iVar2 = param_2 - 0xffc;
    if ((-1 < iVar2) && (iVar2 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar2 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xcc) = 1;
    }
  }
  uVar1 = param_1[5];
  if (param_2 + 5 < 0x400) {
    *(undefined4 *)(iRam00000000 + (param_2 + 5) * 4 + 0x148) = uVar1;
    *(undefined *)(param_2 + iRam00000000 + 0x111d) = 1;
  }
  else if (param_2 + 5 < 0x500) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x3fb) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xe1d) = 1;
  }
  else if (param_2 + 5 < 0x600) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x4fb) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xd7d) = 1;
  }
  else if (param_2 + 5 < 0x680) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x5fb) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xd7d) = 1;
  }
  else {
    iVar2 = param_2 - 0xffb;
    if ((-1 < iVar2) && (iVar2 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar2 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xcd) = 1;
    }
  }
  uVar1 = param_1[6];
  if (param_2 + 6 < 0x400) {
    *(undefined4 *)(iRam00000000 + (param_2 + 6) * 4 + 0x148) = uVar1;
    *(undefined *)(param_2 + iRam00000000 + 0x111e) = 1;
  }
  else if (param_2 + 6 < 0x500) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x3fa) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xe1e) = 1;
  }
  else if (param_2 + 6 < 0x600) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x4fa) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xd7e) = 1;
  }
  else if (param_2 + 6 < 0x680) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x5fa) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xd7e) = 1;
  }
  else {
    iVar2 = param_2 - 0xffa;
    if ((-1 < iVar2) && (iVar2 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar2 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xce) = 1;
    }
  }
  uVar1 = param_1[7];
  _DAT_cc008000 = param_1[7];
  if (param_2 + 7 < 0x400) {
    *(undefined4 *)(iRam00000000 + (param_2 + 7) * 4 + 0x148) = uVar1;
    *(undefined *)(param_2 + iRam00000000 + 0x111f) = 1;
  }
  else if (param_2 + 7 < 0x500) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x3f9) * 4 + 0x548) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xe1f) = 1;
  }
  else if (param_2 + 7 < 0x600) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x4f9) * 4 + 0x6c8) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xd7f) = 1;
  }
  else if (param_2 + 7 < 0x680) {
    *(undefined4 *)(iRam00000000 + (param_2 - 0x5f9) * 4 + 0xac8) = uVar1;
    *(undefined *)(iRam00000000 + param_2 + 0xd7f) = 1;
  }
  else {
    iVar2 = param_2 - 0xff9;
    if ((-1 < iVar2) && (iVar2 < 0x50)) {
      *(undefined4 *)(iRam00000000 + iVar2 * 4 + 8) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xcf) = 1;
    }
  }
  if (param_3 == 0) {
    uVar1 = param_1[8];
    if (param_2 + 8 < 0x400) {
      *(undefined4 *)(iRam00000000 + (param_2 + 8) * 4 + 0x148) = uVar1;
      *(undefined *)(param_2 + iRam00000000 + 0x1120) = 1;
    }
    else if (param_2 + 8 < 0x500) {
      *(undefined4 *)(iRam00000000 + (param_2 - 0x3f8) * 4 + 0x548) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xe20) = 1;
    }
    else if (param_2 + 8 < 0x600) {
      *(undefined4 *)(iRam00000000 + (param_2 - 0x4f8) * 4 + 0x6c8) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xd80) = 1;
    }
    else if (param_2 + 8 < 0x680) {
      *(undefined4 *)(iRam00000000 + (param_2 - 0x5f8) * 4 + 0xac8) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xd80) = 1;
    }
    else {
      iVar2 = param_2 - 0xff8;
      if ((-1 < iVar2) && (iVar2 < 0x50)) {
        *(undefined4 *)(iRam00000000 + iVar2 * 4 + 8) = uVar1;
        *(undefined *)(iRam00000000 + param_2 + 0xd0) = 1;
      }
    }
    uVar1 = param_1[9];
    if (param_2 + 9 < 0x400) {
      *(undefined4 *)(iRam00000000 + (param_2 + 9) * 4 + 0x148) = uVar1;
      *(undefined *)(param_2 + iRam00000000 + 0x1121) = 1;
    }
    else if (param_2 + 9 < 0x500) {
      *(undefined4 *)(iRam00000000 + (param_2 - 0x3f7) * 4 + 0x548) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xe21) = 1;
    }
    else if (param_2 + 9 < 0x600) {
      *(undefined4 *)(iRam00000000 + (param_2 - 0x4f7) * 4 + 0x6c8) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xd81) = 1;
    }
    else if (param_2 + 9 < 0x680) {
      *(undefined4 *)(iRam00000000 + (param_2 - 0x5f7) * 4 + 0xac8) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xd81) = 1;
    }
    else {
      iVar2 = param_2 - 0xff7;
      if ((-1 < iVar2) && (iVar2 < 0x50)) {
        *(undefined4 *)(iRam00000000 + iVar2 * 4 + 8) = uVar1;
        *(undefined *)(iRam00000000 + param_2 + 0xd1) = 1;
      }
    }
    uVar1 = param_1[10];
    if (param_2 + 10 < 0x400) {
      *(undefined4 *)(iRam00000000 + (param_2 + 10) * 4 + 0x148) = uVar1;
      *(undefined *)(param_2 + iRam00000000 + 0x1122) = 1;
    }
    else if (param_2 + 10 < 0x500) {
      *(undefined4 *)(iRam00000000 + (param_2 - 0x3f6) * 4 + 0x548) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xe22) = 1;
    }
    else if (param_2 + 10 < 0x600) {
      *(undefined4 *)(iRam00000000 + (param_2 - 0x4f6) * 4 + 0x6c8) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xd82) = 1;
    }
    else if (param_2 + 10 < 0x680) {
      *(undefined4 *)(iRam00000000 + (param_2 - 0x5f6) * 4 + 0xac8) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xd82) = 1;
    }
    else {
      iVar2 = param_2 - 0xff6;
      if ((-1 < iVar2) && (iVar2 < 0x50)) {
        *(undefined4 *)(iRam00000000 + iVar2 * 4 + 8) = uVar1;
        *(undefined *)(iRam00000000 + param_2 + 0xd2) = 1;
      }
    }
    uVar1 = param_1[0xb];
    _DAT_cc008000 = param_1[0xb];
    if (param_2 + 0xb < 0x400) {
      *(undefined4 *)(iRam00000000 + (param_2 + 0xb) * 4 + 0x148) = uVar1;
      *(undefined *)(param_2 + iRam00000000 + 0x1123) = 1;
    }
    else if (param_2 + 0xb < 0x500) {
      *(undefined4 *)(iRam00000000 + (param_2 - 0x3f5) * 4 + 0x548) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xe23) = 1;
    }
    else if (param_2 + 0xb < 0x600) {
      *(undefined4 *)(iRam00000000 + (param_2 - 0x4f5) * 4 + 0x6c8) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xd83) = 1;
    }
    else if (param_2 + 0xb < 0x680) {
      *(undefined4 *)(iRam00000000 + (param_2 - 0x5f5) * 4 + 0xac8) = uVar1;
      *(undefined *)(iRam00000000 + param_2 + 0xd83) = 1;
    }
    else {
      iVar2 = param_2 - 0xff5;
      if ((-1 < iVar2) && (iVar2 < 0x50)) {
        *(undefined4 *)(iRam00000000 + iVar2 * 4 + 8) = uVar1;
        *(undefined *)(iRam00000000 + param_2 + 0xd3) = 1;
      }
    }
  }
  return;
}

/* WARNING: Removing unreachable block (ram,0x00014204) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXLoadTexMtxIndx(int param_1,uint param_2,int param_3)
{
  int iVar1;
  
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x30a,@890);
  }
  if (param_2 < 0x40) {
    param_2 = param_2 << 2;
  }
  else {
    param_2 = (param_2 - 0x40) * 4 + 0x500;
    if (param_3 != 0) {
      OSPanic(...data.0,0x314,@885);
    }
  }
  if (param_3 == 1) {
    iVar1 = 8;
  }
  else {
    iVar1 = 0xc;
  }
  if ((param_2 & 0xfffff000) != 0) {
    OSPanic(...data.0,0x31b,@419);
  }
  if ((iVar1 - 1U & 0xfffffff0) != 0) {
    OSPanic(...data.0,0x31c,@419);
  }
  _DAT_cc008000 = (param_2 & 0xffff0fff | (iVar1 + -1) * 0x1000) & 0xffff | param_1 << 0x10;
  __GXShadowIndexState(6,_DAT_cc008000);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetViewportJitter(undefined8 param_1,double param_2,double param_3,double param_4,
                        double param_5,double param_6)
{
  int iVar1;
  double extraout_f1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  iVar1 = _savefpr_18();
  dVar2 = extraout_f1;
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x340,@986);
  }
  if (iVar1 == 0) {
    param_2 = (double)(float)(param_2 - (double)@14);
  }
  dVar8 = (double)(float)(param_3 * (double)@14);
  dVar7 = (double)(float)(-param_4 * (double)@14);
  dVar5 = (double)(@987 + (float)(dVar2 + (double)(float)(param_3 * (double)@14)));
  dVar4 = (double)(@987 + (float)(param_2 + (double)(float)(param_4 * (double)@14)));
  dVar3 = (double)(float)((double)@988 * param_6);
  dVar6 = (double)(float)(dVar3 - (double)(float)((double)@988 * param_5));
  *(float *)(iRam00000000 + 0x43c) = (float)dVar2;
  *(float *)(iRam00000000 + 0x440) = (float)param_2;
  *(float *)(iRam00000000 + 0x444) = (float)param_3;
  *(float *)(iRam00000000 + 0x448) = (float)param_4;
  *(float *)(iRam00000000 + 0x44c) = (float)param_5;
  *(float *)(iRam00000000 + 0x450) = (float)param_6;
  if (*(char *)(iRam00000000 + 0x454) != '\0') {
    __GXSetRange(param_5,(double)*(float *)(iRam00000000 + 0x458));
  }
  *(float *)(iRam00000000 + 0x70) = (float)dVar8;
  *(undefined *)(iRam00000000 + 0x10e2) = 1;
  *(float *)(iRam00000000 + 0x74) = (float)dVar7;
  *(undefined *)(iRam00000000 + 0x10e3) = 1;
  *(float *)(iRam00000000 + 0x78) = (float)dVar6;
  *(undefined *)(iRam00000000 + 0x10e4) = 1;
  *(float *)(iRam00000000 + 0x7c) = (float)dVar5;
  *(undefined *)(iRam00000000 + 0x10e5) = 1;
  *(float *)(iRam00000000 + 0x80) = (float)dVar4;
  *(undefined *)(iRam00000000 + 0x10e6) = 1;
  _DAT_cc008000 = (float)dVar3;
  *(float *)(iRam00000000 + 0x84) = (float)dVar3;
  *(undefined *)(iRam00000000 + 0x10e7) = 1;
  *(undefined2 *)(iRam00000000 + 2) = 1;
  _restfpr_18();
  return;
}

void GXSetViewport(double param_1,double param_2,double param_3,double param_4,double param_5,
                  double param_6)
{
  GXSetViewportJitter((double)(float)param_1,(double)(float)param_2,(double)(float)param_3,
                      (double)(float)param_4,(double)(float)param_5,(double)(float)param_6,1);
  return;
}

void GXGetViewportv(undefined4 *param_1)
{
  if (param_1 == (undefined4 *)0x0) {
    OSPanic(...data.0,0x397,@11);
  }
  *param_1 = *(undefined4 *)(iRam00000000 + 0x43c);
  param_1[1] = *(undefined4 *)(iRam00000000 + 0x440);
  param_1[2] = *(undefined4 *)(iRam00000000 + 0x444);
  param_1[3] = *(undefined4 *)(iRam00000000 + 0x448);
  param_1[4] = *(undefined4 *)(iRam00000000 + 0x44c);
  param_1[5] = *(undefined4 *)(iRam00000000 + 0x450);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetScissor(uint param_1,uint param_2,int param_3,int param_4)
{
  uint uVar1;
  uint uVar2;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x3b4,@992);
  }
  if (0x6a9 < param_1) {
    OSPanic(...data.0,0x3b5,@993);
  }
  if (0x6a9 < param_2) {
    OSPanic(...data.0,0x3b6,@994);
  }
  if (0x6a9 < param_1 + param_3) {
    OSPanic(...data.0,0x3b7,@995);
  }
  if (0x6a9 < param_2 + param_4) {
    OSPanic(...data.0,0x3b8,@996);
  }
  param_2 = param_2 + 0x156;
  param_1 = param_1 + 0x156;
  uVar2 = param_2 + param_4 + -1;
  uVar1 = param_1 + param_3 + -1;
  if ((param_2 & 0xfffff800) != 0) {
    OSPanic(...data.0,0x3bf,@419);
  }
  *(uint *)(iRam00000000 + 0xf8) = *(uint *)(iRam00000000 + 0xf8) & 0xfffff800 | param_2;
  if ((param_1 & 0xfffff800) != 0) {
    OSPanic(...data.0,0x3c0,@419);
  }
  *(uint *)(iRam00000000 + 0xf8) = *(uint *)(iRam00000000 + 0xf8) & 0xff800fff | param_1 * 0x1000;
  if ((uVar2 & 0xfffff800) != 0) {
    OSPanic(...data.0,0x3c2,@419);
  }
  *(uint *)(iRam00000000 + 0xfc) = *(uint *)(iRam00000000 + 0xfc) & 0xfffff800 | uVar2;
  if ((uVar1 & 0xfffff800) != 0) {
    OSPanic(...data.0,0x3c3,@419);
  }
  *(uint *)(iRam00000000 + 0xfc) = *(uint *)(iRam00000000 + 0xfc) & 0xff800fff | uVar1 * 0x1000;
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0xf8) >> 0x18) * 4 + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0xf8);
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0xfc);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0xfc) >> 0x18) * 4 + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0xfc);
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

void GXGetScissor(int *param_1,int *param_2,int *param_3,int *param_4)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) || (param_3 == (int *)0x0)) ||
     (param_4 == (int *)0x0)) {
    OSPanic(...data.0,0x3dd,@11);
  }
  uVar2 = *(uint *)(iRam00000000 + 0xf8) & 0x7ff;
  uVar1 = (*(uint *)(iRam00000000 + 0xf8) & 0x7ff000) >> 0xc;
  uVar3 = *(uint *)(iRam00000000 + 0xfc);
  uVar4 = *(uint *)(iRam00000000 + 0xfc);
  *param_1 = uVar1 - 0x156;
  *param_2 = uVar2 - 0x156;
  *param_3 = (((uVar4 & 0x7ff000) >> 0xc) - uVar1) + 1;
  *param_4 = ((uVar3 & 0x7ff) - uVar2) + 1;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetScissorBoxOffset(int param_1,int param_2)
{
  uint uVar1;
  uint uVar2;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x3fb,@999);
  }
  if (0x7ff < param_1 + 0x156U) {
    OSPanic(...data.0,0x3fe,@1000);
  }
  if (0x7ff < param_2 + 0x156U) {
    OSPanic(...data.0,0x400,@1001);
  }
  uVar1 = param_1 + 0x156U >> 1;
  uVar2 = param_2 + 0x156U >> 1;
  if ((uVar1 & 0x7ffffc00) != 0) {
    OSPanic(...data.0,0x405,@419);
  }
  if ((uVar2 & 0x7ffffc00) != 0) {
    OSPanic(...data.0,0x406,@419);
  }
  _DAT_cc008000 = (uVar1 & 0x7ff003ff | uVar2 << 10) & 0xffffff | 0x59000000;
  *(uint *)(iRam00000000 + 0xe2c) = _DAT_cc008000;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetClipMode(undefined4 param_1)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x41b,@1006);
  }
  _DAT_cc008000 = param_1;
  *(undefined4 *)(iRam00000000 + 0x1c) = param_1;
  *(undefined *)(iRam00000000 + 0x10cd) = 1;
  *(undefined2 *)(iRam00000000 + 2) = 1;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __GXSetMatrixIndex(int param_1)
{
  if (param_1 < 5) {
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x80);
    *(undefined4 *)(iRam00000000 + 0x68) = *(undefined4 *)(iRam00000000 + 0x80);
    *(undefined *)(iRam00000000 + 0x10e0) = 1;
  }
  else {
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x84);
    *(undefined4 *)(iRam00000000 + 0x6c) = *(undefined4 *)(iRam00000000 + 0x84);
    *(undefined *)(iRam00000000 + 0x10e1) = 1;
  }
  *(undefined2 *)(iRam00000000 + 2) = 1;
  return;
}
