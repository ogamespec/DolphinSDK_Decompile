                             //
                             // .text 
                             // SHT_PROGBITS  [0x0 - 0xb9f]
                             // ram:00010000-ram:00010b9f
                             //
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined OSDisableInterrupts()
                               assume r13 = 0x10f88
             undefined         r3:1           <RETURN>
                             __RAS_OSDisableInterrupts_begin                 XREF[5]:     Entry Point(*), 
                             OSDisableInterrupts                                          OSSetInterruptMask:00010584(c), 
                                                                                          __OSMaskInterrupts:00010608(c), 
                                                                                          __OSUnmaskInterrupts:00010690(c), 
                                                                                          _elfSectionHeaders::00000034(*)  
        00010000 7c 60 00 a6     mfmsr      r3
        00010004 54 64 04 5e     rlwinm     r4,r3,0x0,0x11,0xf
        00010008 7c 80 01 24     mtmsr      r4,0
        0001000c 54 63 8f fe     rlwinm     r3,r3,0x11,0x1f,0x1f
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __RAS_OSDisableInterrupts_end()
                               assume r13 = 0x10f88
             undefined         r3:1           <RETURN>
                             __RAS_OSDisableInterrupts_end                   XREF[1]:     Entry Point(*)  
        00010010 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined OSEnableInterrupts()
                               assume r13 = 0x10f88
             undefined         r3:1           <RETURN>
                             OSEnableInterrupts                              XREF[1]:     Entry Point(*)  
        00010014 7c 60 00 a6     mfmsr      r3
        00010018 60 64 80 00     ori        r4,r3,0x8000
        0001001c 7c 80 01 24     mtmsr      r4,0
        00010020 54 63 8f fe     rlwinm     r3,r3,0x11,0x1f,0x1f
        00010024 4e 80 00 20     blr



                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined OSRestoreInterrupts()
                               assume r13 = 0x10f88
             undefined         r3:1           <RETURN>
                             OSRestoreInterrupts                             XREF[4]:     Entry Point(*), 
                                                                                          OSSetInterruptMask:000105d8(c), 
                                                                                          __OSMaskInterrupts:00010660(c), 
                                                                                          __OSUnmaskInterrupts:000106e8(c)  
        00010028 2c 03 00 00     cmpwi      r3,0x0
        0001002c 7c 80 00 a6     mfmsr      r4
        00010030 41 82 00 0c     beq        LAB_0001003c
        00010034 60 85 80 00     ori        r5,r4,0x8000
        00010038 48 00 00 08     b          LAB_00010040
                             LAB_0001003c                                    XREF[1]:     00010030(j)  
        0001003c 54 85 04 5e     rlwinm     r5,r4,0x0,0x11,0xf
                             LAB_00010040                                    XREF[1]:     00010038(j)  
        00010040 7c a0 01 24     mtmsr      r5,0
        00010044 54 84 8f fe     rlwinm     r4,r4,0x11,0x1f,0x1f
        00010048 4e 80 00 20     blr


undefined4 __OSSetInterruptHandler(short param_1,undefined4 param_2)
{
  undefined4 uVar1;
  
  if (InterruptHandlerTable == 0) {
    OSPanic(@40,399,@41);
  }
  if (0x1f < param_1) {
    OSPanic(@40,0x191,@42);
  }
  uVar1 = *(undefined4 *)(InterruptHandlerTable + param_1 * 4);
  *(undefined4 *)(InterruptHandlerTable + param_1 * 4) = param_2;
  return uVar1;
}

undefined4 __OSGetInterruptHandler(short param_1)
{
  if (InterruptHandlerTable == 0) {
    OSPanic(@40,0x1a5,@44);
  }
  if (0x1f < param_1) {
    OSPanic(@40,0x1a7,@45);
  }
  return *(undefined4 *)(InterruptHandlerTable + param_1 * 4);
}

void __OSInterruptInit(void)
{
  undefined4 *puVar1;
  
  InterruptHandlerTable = (void *)OSPhysicalToCached(0x3040);
  memset(InterruptHandlerTable,0,0x80);
  puVar1 = (undefined4 *)OSPhysicalToCached(0xc4);
  *puVar1 = 0;
  puVar1 = (undefined4 *)OSPhysicalToCached(200);
  *puVar1 = 0;
  _DAT_cc003004 = 0xf0;
  __OSMaskInterrupts(0xffffffe0);
  __OSSetExceptionHandler(4,ExternalInterruptHandler);
  _DAT_cc003000 = 1;
  __OSUnmaskInterrupts(0x100);
  return;
}

uint SetInterruptMask(uint param_1,uint param_2)
{
  uint uVar1;
  
  uVar1 = LZCOUNT(param_1);
  if (uVar1 < 0xc) {
    if (uVar1 == 8) {
      _DAT_cc006c00 = _DAT_cc006c00 & 0xffffffd3;
      if ((param_2 & 0x800000) == 0) {
        _DAT_cc006c00 = _DAT_cc006c00 | 4;
      }
      param_1 = param_1 & 0xff7fffff;
    }
    else if (uVar1 < 8) {
      if (uVar1 < 5) {
        _DAT_cc00401c = (ushort)((param_2 & 0x80000000) == 0);
        if ((param_2 & 0x40000000) == 0) {
          _DAT_cc00401c = _DAT_cc00401c | 2;
        }
        if ((param_2 & 0x20000000) == 0) {
          _DAT_cc00401c = _DAT_cc00401c | 4;
        }
        if ((param_2 & 0x10000000) == 0) {
          _DAT_cc00401c = _DAT_cc00401c | 8;
        }
        if ((param_2 & 0x8000000) == 0) {
          _DAT_cc00401c = _DAT_cc00401c | 0x10;
        }
        param_1 = param_1 & 0x7ffffff;
      }
      else {
        _DAT_cc00500a = _DAT_cc00500a & 0xfe07;
        if ((param_2 & 0x4000000) == 0) {
          _DAT_cc00500a = _DAT_cc00500a | 0x10;
        }
        if ((param_2 & 0x2000000) == 0) {
          _DAT_cc00500a = _DAT_cc00500a | 0x40;
        }
        if ((param_2 & 0x1000000) == 0) {
          _DAT_cc00500a = _DAT_cc00500a | 0x100;
        }
        param_1 = param_1 & 0xf8ffffff;
      }
    }
    else {
      _DAT_cc006800 = _DAT_cc006800 & 0xffffd3f0;
      if ((param_2 & 0x400000) == 0) {
        _DAT_cc006800 = _DAT_cc006800 | 1;
      }
      if ((param_2 & 0x200000) == 0) {
        _DAT_cc006800 = _DAT_cc006800 | 4;
      }
      if ((param_2 & 0x100000) == 0) {
        _DAT_cc006800 = _DAT_cc006800 | 0x400;
      }
      param_1 = param_1 & 0xff8fffff;
    }
  }
  else if (uVar1 < 0x11) {
    if (uVar1 < 0xf) {
      _DAT_cc006814 = _DAT_cc006814 & 0xfffff3f0;
      if ((param_2 & 0x80000) == 0) {
        _DAT_cc006814 = _DAT_cc006814 | 1;
      }
      if ((param_2 & 0x40000) == 0) {
        _DAT_cc006814 = _DAT_cc006814 | 4;
      }
      if ((param_2 & 0x20000) == 0) {
        _DAT_cc006814 = _DAT_cc006814 | 0x400;
      }
      param_1 = param_1 & 0xfff1ffff;
    }
    else {
      _DAT_cc006828 = _DAT_cc006828 & 0xfffffff0;
      if ((param_2 & 0x10000) == 0) {
        _DAT_cc006828 = _DAT_cc006828 | 1;
      }
      if ((param_2 & 0x8000) == 0) {
        _DAT_cc006828 = _DAT_cc006828 | 4;
      }
      param_1 = param_1 & 0xfffe7fff;
    }
  }
  else if (uVar1 < 0x1b) {
    _DAT_cc003004 = 0xf0;
    if ((param_2 & 0x4000) == 0) {
      _DAT_cc003004 = 0x8f0;
    }
    if ((param_2 & 0x800) == 0) {
      _DAT_cc003004 = _DAT_cc003004 | 8;
    }
    if ((param_2 & 0x400) == 0) {
      _DAT_cc003004 = _DAT_cc003004 | 4;
    }
    if ((param_2 & 0x200) == 0) {
      _DAT_cc003004 = _DAT_cc003004 | 2;
    }
    if ((param_2 & 0x100) == 0) {
      _DAT_cc003004 = _DAT_cc003004 | 1;
    }
    if ((param_2 & 0x80) == 0) {
      _DAT_cc003004 = _DAT_cc003004 | 0x100;
    }
    if ((param_2 & 0x40) == 0) {
      _DAT_cc003004 = _DAT_cc003004 | 0x1000;
    }
    if ((param_2 & 0x2000) == 0) {
      _DAT_cc003004 = _DAT_cc003004 | 0x200;
    }
    if ((param_2 & 0x1000) == 0) {
      _DAT_cc003004 = _DAT_cc003004 | 0x400;
    }
    if ((param_2 & 0x20) == 0) {
      _DAT_cc003004 = _DAT_cc003004 | 0x2000;
    }
    param_1 = param_1 & 0xffff801f;
  }
  return param_1;
}

undefined4 OSGetInterruptMask(void)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)OSPhysicalToCached(200);
  return *puVar1;
}

uint OSSetInterruptMask(uint param_1)
{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = OSDisableInterrupts();
  puVar2 = (uint *)OSPhysicalToCached(0xc4);
  uVar4 = *puVar2;
  puVar2 = (uint *)OSPhysicalToCached(200);
  uVar3 = *puVar2;
  puVar2 = (uint *)OSPhysicalToCached(200);
  *puVar2 = param_1;
  for (uVar5 = param_1 ^ (uVar4 | uVar3); uVar5 != 0;
      uVar5 = SetInterruptMask(uVar5,uVar4 | param_1)) {
  }
  OSRestoreInterrupts(uVar1);
  return uVar3;
}

uint __OSMaskInterrupts(uint param_1)
{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = OSDisableInterrupts();
  puVar2 = (uint *)OSPhysicalToCached(0xc4);
  uVar5 = *puVar2;
  puVar2 = (uint *)OSPhysicalToCached(200);
  uVar3 = *puVar2;
  puVar2 = (uint *)OSPhysicalToCached(0xc4);
  *puVar2 = param_1 | uVar5;
  for (uVar4 = param_1 & ~(uVar5 | uVar3); uVar4 != 0;
      uVar4 = SetInterruptMask(uVar4,param_1 | uVar5 | uVar3)) {
  }
  OSRestoreInterrupts(uVar1);
  return uVar5;
}

uint __OSUnmaskInterrupts(uint param_1)
{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = OSDisableInterrupts();
  puVar2 = (uint *)OSPhysicalToCached(0xc4);
  uVar5 = *puVar2;
  puVar2 = (uint *)OSPhysicalToCached(200);
  uVar3 = *puVar2;
  puVar2 = (uint *)OSPhysicalToCached(0xc4);
  *puVar2 = uVar5 & ~param_1;
  for (uVar4 = param_1 & (uVar5 | uVar3); uVar4 != 0;
      uVar4 = SetInterruptMask(uVar4,uVar5 & ~param_1 | uVar3)) {
  }
  OSRestoreInterrupts(uVar1);
  return uVar5;
}

void __OSDispatchInterrupt(undefined4 param_1,int param_2)
{
  uint uVar1;
  ushort uVar2;
  uint *puVar3;
  code *pcVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  bool bVar8;
  
  uVar5 = _DAT_cc003000;
  puVar6 = InterruptPrioTable;
  uVar1 = _DAT_cc003000 & 0xfffeffff;
  if ((uVar1 == 0) || ((uVar1 & _DAT_cc003004) == 0)) {
    bVar8 = 0xfffffffe < __OSSpuriousInterrupts._4_4_;
    __OSSpuriousInterrupts._4_4_ = __OSSpuriousInterrupts._4_4_ + 1;
    __OSSpuriousInterrupts._0_4_ = __OSSpuriousInterrupts._0_4_ + (uint)bVar8;
    OSLoadContext(param_2);
  }
  uVar7 = 0;
  if ((uVar5 & 0x80) != 0) {
    if ((_DAT_cc00401e & 1) != 0) {
      uVar7 = 0x80000000;
    }
    if ((_DAT_cc00401e & 2) != 0) {
      uVar7 = uVar7 | 0x40000000;
    }
    if ((_DAT_cc00401e & 4) != 0) {
      uVar7 = uVar7 | 0x20000000;
    }
    if ((_DAT_cc00401e & 8) != 0) {
      uVar7 = uVar7 | 0x10000000;
    }
    if ((_DAT_cc00401e & 0x10) != 0) {
      uVar7 = uVar7 | 0x8000000;
    }
  }
  if ((uVar5 & 0x40) != 0) {
    if ((_DAT_cc00500a & 8) != 0) {
      uVar7 = uVar7 | 0x4000000;
    }
    if ((_DAT_cc00500a & 0x20) != 0) {
      uVar7 = uVar7 | 0x2000000;
    }
    if ((_DAT_cc00500a & 0x80) != 0) {
      uVar7 = uVar7 | 0x1000000;
    }
  }
  if (((uVar5 & 0x20) != 0) && ((_DAT_cc006c00 & 8) != 0)) {
    uVar7 = uVar7 | 0x800000;
  }
  if ((uVar5 & 0x10) != 0) {
    if ((_DAT_cc006800 & 2) != 0) {
      uVar7 = uVar7 | 0x400000;
    }
    if ((_DAT_cc006800 & 8) != 0) {
      uVar7 = uVar7 | 0x200000;
    }
    if ((_DAT_cc006800 & 0x800) != 0) {
      uVar7 = uVar7 | 0x100000;
    }
    if ((_DAT_cc006814 & 2) != 0) {
      uVar7 = uVar7 | 0x80000;
    }
    if ((_DAT_cc006814 & 8) != 0) {
      uVar7 = uVar7 | 0x40000;
    }
    if ((_DAT_cc006814 & 0x800) != 0) {
      uVar7 = uVar7 | 0x20000;
    }
    if ((_DAT_cc006828 & 2) != 0) {
      uVar7 = uVar7 | 0x10000;
    }
    if ((_DAT_cc006828 & 8) != 0) {
      uVar7 = uVar7 | 0x8000;
    }
  }
  if ((uVar5 & 0x2000) != 0) {
    uVar7 = uVar7 | 0x20;
  }
  if ((uVar5 & 0x1000) != 0) {
    uVar7 = uVar7 | 0x40;
  }
  if ((uVar5 & 0x400) != 0) {
    uVar7 = uVar7 | 0x1000;
  }
  if ((uVar5 & 0x200) != 0) {
    uVar7 = uVar7 | 0x2000;
  }
  if ((uVar5 & 0x100) != 0) {
    uVar7 = uVar7 | 0x80;
  }
  if ((uVar5 & 8) != 0) {
    uVar7 = uVar7 | 0x800;
  }
  if ((uVar5 & 4) != 0) {
    uVar7 = uVar7 | 0x400;
  }
  if ((uVar5 & 2) != 0) {
    uVar7 = uVar7 | 0x200;
  }
  if ((uVar5 & 0x800) != 0) {
    uVar7 = uVar7 | 0x4000;
  }
  if ((uVar5 & 1) != 0) {
    uVar7 = uVar7 | 0x100;
  }
  if ((uVar7 & 0x100) != 0) {
    OSReport(@232);
    OSDumpContext(param_2);
    OSReport(@233,_DAT_cc00301c,_DAT_cc003020);
    _DAT_cc003000 = 1;
    OSReport(@234,(&__OSPIErrors)[_DAT_cc00301c]);
    OSReport(@235,_DAT_cc003020);
  }
  puVar3 = (uint *)OSPhysicalToCached(200);
  uVar5 = *puVar3;
  puVar3 = (uint *)OSPhysicalToCached(0xc4);
  uVar5 = uVar7 & ~(*puVar3 | uVar5);
  if (uVar5 != 0) {
    for (; (uVar5 & *(uint *)puVar6) == 0; puVar6 = (undefined1 *)((int)puVar6 + 4)) {
    }
    uVar2 = (ushort)LZCOUNT(uVar5 & *(uint *)puVar6);
    pcVar4 = (code *)__OSGetInterruptHandler(uVar2);
    if (pcVar4 != (code *)0x0) {
      if (4 < uVar2) {
        __OSLastInterrupt = uVar2;
        __OSLastInterruptTime = OSGetTime();
        __OSLastInterruptSrr0 = *(undefined4 *)(param_2 + 0x198);
      }
      OSDisableScheduler();
      (*pcVar4)(uVar2,param_2);
      OSEnableScheduler();
      __OSReschedule();
      OSLoadContext(param_2);
    }
  }
  OSReport(@236,uVar7,uVar1);
  for (; uVar7 != 0; uVar7 = uVar7 & ~(1 << (0x1fU - LZCOUNT(uVar7) & 0x3f))) {
    OSReport(@237,(&__OSInterruptNames)[(short)LZCOUNT(uVar7)]);
  }
  OSLoadContext(param_2);
  return;
}

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined ExternalInterruptHandler()
                               assume r13 = 0x10f88
             undefined         r3:1           <RETURN>
                             ExternalInterruptHandler                        XREF[1]:     __OSInterruptInit:00010224(*)  
        00010b54 90 04 00 00     stw        r0,0x0(r4)
        00010b58 90 24 00 04     stw        r1,0x4(r4)
        00010b5c 90 44 00 08     stw        r2,0x8(r4)
        00010b60 bc c4 00 18     stmw       r6,0x18(r4)=>@1                                  = "MEM_0"
        00010b64 7c 11 e2 a6     mfspr      r0,spr391
        00010b68 90 04 01 a8     stw        r0,0x1a8(r4)
        00010b6c 7c 12 e2 a6     mfspr      r0,spr392
        00010b70 90 04 01 ac     stw        r0,0x1ac(r4)
        00010b74 7c 13 e2 a6     mfspr      r0,spr393
        00010b78 90 04 01 b0     stw        r0,0x1b0(r4)
        00010b7c 7c 14 e2 a6     mfspr      r0,spr394
        00010b80 90 04 01 b4     stw        r0,0x1b4(r4)
        00010b84 7c 15 e2 a6     mfspr      r0,spr395
        00010b88 90 04 01 b8     stw        r0,0x1b8(r4)
        00010b8c 7c 16 e2 a6     mfspr      r0,spr396
        00010b90 90 04 01 bc     stw        r0,0x1bc(r4)
        00010b94 7c 17 e2 a6     mfspr      r0,spr397
        00010b98 90 04 01 c0     stw        r0,0x1c0(r4)
        00010b9c 4b ff fb 68     b          __OSDispatchInterrupt                            undefined __OSDispatchInterrupt()
                             -- Flow Override: CALL_RETURN (CALL_TERMINATOR)

