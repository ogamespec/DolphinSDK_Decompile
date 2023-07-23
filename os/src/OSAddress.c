int OSPhysicalToCached(uint param_1)
{
  if (0xfffffff < param_1) {
    OSPanic(@2,0x2c,@3);
  }
  return param_1 + 0x80000000;
}

int OSPhysicalToUncached(uint param_1)
{
  if (0xfffffff < param_1) {
    OSPanic(@2,0x3b,@5);
  }
  return param_1 + 0xc0000000;
}

int OSCachedToPhysical(uint param_1)
{
  if ((param_1 < 0x80000000) || (0x8fffffff < param_1)) {
    OSPanic(@2,0x4a,@7);
  }
  return param_1 + 0x80000000;
}

int OSUncachedToPhysical(uint param_1)
{
  if ((param_1 < 0xc0000000) || (0xcfffffff < param_1)) {
    OSPanic(@2,0x59,@9);
  }
  return param_1 + 0x40000000;
}

int OSCachedToUncached(uint param_1)
{
  if ((param_1 < 0x80000000) || (0x8fffffff < param_1)) {
    OSPanic(@2,0x68,@11);
  }
  return param_1 + 0x40000000;
}

int OSUncachedToCached(uint param_1)
{
  if ((param_1 < 0xc0000000) || (0xcfffffff < param_1)) {
    OSPanic(@2,0x77,@13);
  }
  return param_1 + 0xc0000000;
}
