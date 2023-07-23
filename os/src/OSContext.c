                             //
                             // .text 
                             // SHT_PROGBITS  [0x0 - 0x9b3]
                             // ram:00010000-ram:000109b3
                             //
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __OSLoadFPUContext()
             undefined         r3:1           <RETURN>
                             __OSLoadFPUContext                              XREF[3]:     OSLoadFPUContext:00010250(c), 
                                                                                          OSSwitchFPUContext:000107f8(c), 
                                                                                          _elfSectionHeaders::00000034(*)  
        00010000 a0 a4 01 a2     lhz        r5,0x1a2(r4)
        00010004 54 a5 07 ff     rlwinm.    r5,r5,0x0,0x1f,0x1f
        00010008 41 82 01 18     beq        LAB_00010120
        0001000c c8 04 01 90     lfd        f0,0x190(r4)
        00010010 fd fe 05 8e     mtfsf      0xff,f0
        00010014 7c b8 e2 a6     mfspr      r5,spr398
        00010018 54 a5 1f ff     rlwinm.    r5,r5,0x3,0x1f,0x1f
        0001001c 41 82 00 84     beq        LAB_000100a0
        00010020 e0              ??         E0h
        00010021 04              ??         04h
        00010022 01              ??         01h
        00010023 c8              ??         C8h
        00010024 e0              ??         E0h
        00010025 24              ??         24h    $
        00010026 01              ??         01h
        00010027 d0              ??         D0h
        00010028 e0              ??         E0h
        00010029 44              ??         44h    D
        0001002a 01              ??         01h
        0001002b d8              ??         D8h
        0001002c e0              ??         E0h
        0001002d 64              ??         64h    d
        0001002e 01              ??         01h
        0001002f e0              ??         E0h
        00010030 e0              ??         E0h
        00010031 84              ??         84h
        00010032 01              ??         01h
        00010033 e8              ??         E8h
        00010034 e0              ??         E0h
        00010035 a4              ??         A4h
        00010036 01              ??         01h
        00010037 f0              ??         F0h
        00010038 e0              ??         E0h
        00010039 c4              ??         C4h
        0001003a 01              ??         01h
        0001003b f8              ??         F8h
        0001003c e0              ??         E0h
        0001003d e4              ??         E4h
        0001003e 02              ??         02h
        0001003f 00              ??         00h
        00010040 e1              ??         E1h
        00010041 04              ??         04h
        00010042 02              ??         02h
        00010043 08              ??         08h
        00010044 e1              ??         E1h
        00010045 24              ??         24h    $
        00010046 02              ??         02h
        00010047 10              ??         10h
        00010048 e1              ??         E1h
        00010049 44              ??         44h    D
        0001004a 02              ??         02h
        0001004b 18              ??         18h
        0001004c e1              ??         E1h
        0001004d 64              ??         64h    d
        0001004e 02              ??         02h
        0001004f 20              ??         20h     
        00010050 e1              ??         E1h
        00010051 84              ??         84h
        00010052 02              ??         02h
        00010053 28              ??         28h    (
        00010054 e1              ??         E1h
        00010055 a4              ??         A4h
        00010056 02              ??         02h
        00010057 30              ??         30h    0
        00010058 e1              ??         E1h
        00010059 c4              ??         C4h
        0001005a 02              ??         02h
        0001005b 38              ??         38h    8
        0001005c e1              ??         E1h
        0001005d e4              ??         E4h
        0001005e 02              ??         02h
        0001005f 40              ??         40h    @
        00010060 e2              ??         E2h
        00010061 04              ??         04h
        00010062 02              ??         02h
        00010063 48              ??         48h    H
        00010064 e2              ??         E2h
        00010065 24              ??         24h    $
        00010066 02              ??         02h
        00010067 50              ??         50h    P
        00010068 e2              ??         E2h
        00010069 44              ??         44h    D
        0001006a 02              ??         02h
        0001006b 58              ??         58h    X
        0001006c e2              ??         E2h
        0001006d 64              ??         64h    d
        0001006e 02              ??         02h
        0001006f 60              ??         60h    `
        00010070 e2              ??         E2h
        00010071 84              ??         84h
        00010072 02              ??         02h
        00010073 68              ??         68h    h
        00010074 e2              ??         E2h
        00010075 a4              ??         A4h
        00010076 02              ??         02h
        00010077 70              ??         70h    p
        00010078 e2              ??         E2h
        00010079 c4              ??         C4h
        0001007a 02              ??         02h
        0001007b 78              ??         78h    x
        0001007c e2              ??         E2h
        0001007d e4              ??         E4h
        0001007e 02              ??         02h
        0001007f 80              ??         80h
        00010080 e3              ??         E3h
        00010081 04              ??         04h
        00010082 02              ??         02h
        00010083 88              ??         88h
        00010084 e3              ??         E3h
        00010085 24              ??         24h    $
        00010086 02              ??         02h
        00010087 90              ??         90h
        00010088 e3              ??         E3h
        00010089 44              ??         44h    D
        0001008a 02              ??         02h
        0001008b 98              ??         98h
        0001008c e3              ??         E3h
        0001008d 64              ??         64h    d
        0001008e 02              ??         02h
        0001008f a0              ??         A0h
        00010090 e3              ??         E3h
        00010091 84              ??         84h
        00010092 02              ??         02h
        00010093 a8              ??         A8h
        00010094 e3              ??         E3h
        00010095 a4              ??         A4h
        00010096 02              ??         02h
        00010097 b0              ??         B0h
        00010098 e3              ??         E3h
        00010099 c4              ??         C4h
        0001009a 02              ??         02h
        0001009b b8              ??         B8h
        0001009c e3              ??         E3h
        0001009d e4              ??         E4h
        0001009e 02              ??         02h
        0001009f c0              ??         C0h
                             LAB_000100a0                                    XREF[1]:     0001001c(j)  
        000100a0 c8 04 00 90     lfd        f0,0x90(r4)
        000100a4 c8 24 00 98     lfd        f1,0x98(r4)
        000100a8 c8 44 00 a0     lfd        f2,0xa0(r4)
        000100ac c8 64 00 a8     lfd        f3,0xa8(r4)
        000100b0 c8 84 00 b0     lfd        f4,0xb0(r4)
        000100b4 c8 a4 00 b8     lfd        f5,0xb8(r4)
        000100b8 c8 c4 00 c0     lfd        f6,0xc0(r4)
        000100bc c8 e4 00 c8     lfd        f7,0xc8(r4)
        000100c0 c9 04 00 d0     lfd        f8,0xd0(r4)
        000100c4 c9 24 00 d8     lfd        f9,0xd8(r4)
        000100c8 c9 44 00 e0     lfd        f10,0xe0(r4)
        000100cc c9 64 00 e8     lfd        f11,0xe8(r4)
        000100d0 c9 84 00 f0     lfd        f12,0xf0(r4)
        000100d4 c9 a4 00 f8     lfd        f13,0xf8(r4)
        000100d8 c9 c4 01 00     lfd        f14,0x100(r4)
        000100dc c9 e4 01 08     lfd        f15,0x108(r4)
        000100e0 ca 04 01 10     lfd        f16,0x110(r4)
        000100e4 ca 24 01 18     lfd        f17,0x118(r4)
        000100e8 ca 44 01 20     lfd        f18,0x120(r4)
        000100ec ca 64 01 28     lfd        f19,0x128(r4)
        000100f0 ca 84 01 30     lfd        f20,0x130(r4)
        000100f4 ca a4 01 38     lfd        f21,0x138(r4)
        000100f8 ca c4 01 40     lfd        f22,0x140(r4)
        000100fc ca e4 01 48     lfd        f23,0x148(r4)
        00010100 cb 04 01 50     lfd        f24,0x150(r4)
        00010104 cb 24 01 58     lfd        f25,0x158(r4)
        00010108 cb 44 01 60     lfd        f26,0x160(r4)
        0001010c cb 64 01 68     lfd        f27,0x168(r4)
        00010110 cb 84 01 70     lfd        f28,0x170(r4)
        00010114 cb a4 01 78     lfd        f29,0x178(r4)
        00010118 cb c4 01 80     lfd        f30,0x180(r4)
        0001011c cb e4 01 88     lfd        f31,0x188(r4)
                             LAB_00010120                                    XREF[1]:     00010008(j)  
        00010120 4e 80 00 20     blr



                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __OSSaveFPUContext()
             undefined         r3:1           <RETURN>
                             __OSSaveFPUContext                              XREF[2]:     OSSaveFPUContext:00010258(c), 
                                                                                          OSSwitchFPUContext:000107f4(c)  
        00010124 a0 65 01 a2     lhz        r3,0x1a2(r5)
        00010128 60 63 00 01     ori        r3,r3,0x1
        0001012c b0 65 01 a2     sth        r3,0x1a2(r5)
        00010130 d8 05 00 90     stfd       f0,0x90(r5)
        00010134 d8 25 00 98     stfd       f1,0x98(r5)
        00010138 d8 45 00 a0     stfd       f2,0xa0(r5)
        0001013c d8 65 00 a8     stfd       f3,0xa8(r5)
        00010140 d8 85 00 b0     stfd       f4,0xb0(r5)
        00010144 d8 a5 00 b8     stfd       f5,0xb8(r5)
        00010148 d8 c5 00 c0     stfd       f6,0xc0(r5)
        0001014c d8 e5 00 c8     stfd       f7,0xc8(r5)
        00010150 d9 05 00 d0     stfd       f8,0xd0(r5)
        00010154 d9 25 00 d8     stfd       f9,0xd8(r5)
        00010158 d9 45 00 e0     stfd       f10,0xe0(r5)
        0001015c d9 65 00 e8     stfd       f11,0xe8(r5)
        00010160 d9 85 00 f0     stfd       f12,0xf0(r5)
        00010164 d9 a5 00 f8     stfd       f13,0xf8(r5)
        00010168 d9 c5 01 00     stfd       f14,0x100(r5)
        0001016c d9 e5 01 08     stfd       f15,0x108(r5)
        00010170 da 05 01 10     stfd       f16,0x110(r5)
        00010174 da 25 01 18     stfd       f17,0x118(r5)
        00010178 da 45 01 20     stfd       f18,0x120(r5)
        0001017c da 65 01 28     stfd       f19,0x128(r5)
        00010180 da 85 01 30     stfd       f20,0x130(r5)
        00010184 da a5 01 38     stfd       f21,0x138(r5)
        00010188 da c5 01 40     stfd       f22,0x140(r5)
        0001018c da e5 01 48     stfd       f23,0x148(r5)
        00010190 db 05 01 50     stfd       f24,0x150(r5)
        00010194 db 25 01 58     stfd       f25,0x158(r5)
        00010198 db 45 01 60     stfd       f26,0x160(r5)
        0001019c db 65 01 68     stfd       f27,0x168(r5)
        000101a0 db 85 01 70     stfd       f28,0x170(r5)
        000101a4 db a5 01 78     stfd       f29,0x178(r5)
        000101a8 db c5 01 80     stfd       f30,0x180(r5)
        000101ac db e5 01 88     stfd       f31,0x188(r5)
        000101b0 fc 00 04 8e     mffs       f0
        000101b4 d8 05 01 90     stfd       f0,0x190(r5)
        000101b8 c8 05 00 90     lfd        f0,0x90(r5)
        000101bc 7c 78 e2 a6     mfspr      r3,spr398
        000101c0 54 63 1f ff     rlwinm.    r3,r3,0x3,0x1f,0x1f
        000101c4 41 82 00 84     beq        LAB_00010248
        000101c8 f0              ??         F0h
        000101c9 05              ??         05h
        000101ca 01              ??         01h
        000101cb c8              ??         C8h
        000101cc f0              ??         F0h
        000101cd 25              ??         25h    %
        000101ce 01              ??         01h
        000101cf d0              ??         D0h
        000101d0 f0              ??         F0h
        000101d1 45              ??         45h    E
        000101d2 01              ??         01h
        000101d3 d8              ??         D8h
        000101d4 f0              ??         F0h
        000101d5 65              ??         65h    e
        000101d6 01              ??         01h
        000101d7 e0              ??         E0h
        000101d8 f0              ??         F0h
        000101d9 85              ??         85h
        000101da 01              ??         01h
        000101db e8              ??         E8h
        000101dc f0              ??         F0h
        000101dd a5              ??         A5h
        000101de 01              ??         01h
        000101df f0              ??         F0h
        000101e0 f0              ??         F0h
        000101e1 c5              ??         C5h
        000101e2 01              ??         01h
        000101e3 f8              ??         F8h
        000101e4 f0              ??         F0h
        000101e5 e5              ??         E5h
        000101e6 02              ??         02h
        000101e7 00              ??         00h
        000101e8 f1              ??         F1h
        000101e9 05              ??         05h
        000101ea 02              ??         02h
        000101eb 08              ??         08h
        000101ec f1              ??         F1h
        000101ed 25              ??         25h    %
        000101ee 02              ??         02h
        000101ef 10              ??         10h
        000101f0 f1              ??         F1h
        000101f1 45              ??         45h    E
        000101f2 02              ??         02h
        000101f3 18              ??         18h
        000101f4 f1              ??         F1h
        000101f5 65              ??         65h    e
        000101f6 02              ??         02h
        000101f7 20              ??         20h     
        000101f8 f1              ??         F1h
        000101f9 85              ??         85h
        000101fa 02              ??         02h
        000101fb 28              ??         28h    (
        000101fc f1              ??         F1h
        000101fd a5              ??         A5h
        000101fe 02              ??         02h
        000101ff 30              ??         30h    0
        00010200 f1              ??         F1h
        00010201 c5              ??         C5h
        00010202 02              ??         02h
        00010203 38              ??         38h    8
        00010204 f1              ??         F1h
        00010205 e5              ??         E5h
        00010206 02              ??         02h
        00010207 40              ??         40h    @
        00010208 f2              ??         F2h
        00010209 05              ??         05h
        0001020a 02              ??         02h
        0001020b 48              ??         48h    H
        0001020c f2              ??         F2h
        0001020d 25              ??         25h    %
        0001020e 02              ??         02h
        0001020f 50              ??         50h    P
        00010210 f2              ??         F2h
        00010211 45              ??         45h    E
        00010212 02              ??         02h
        00010213 58              ??         58h    X
        00010214 f2              ??         F2h
        00010215 65              ??         65h    e
        00010216 02              ??         02h
        00010217 60              ??         60h    `
        00010218 f2              ??         F2h
        00010219 85              ??         85h
        0001021a 02              ??         02h
        0001021b 68              ??         68h    h
        0001021c f2              ??         F2h
        0001021d a5              ??         A5h
        0001021e 02              ??         02h
        0001021f 70              ??         70h    p
        00010220 f2              ??         F2h
        00010221 c5              ??         C5h
        00010222 02              ??         02h
        00010223 78              ??         78h    x
        00010224 f2              ??         F2h
        00010225 e5              ??         E5h
        00010226 02              ??         02h
        00010227 80              ??         80h
        00010228 f3              ??         F3h
        00010229 05              ??         05h
        0001022a 02              ??         02h
        0001022b 88              ??         88h
        0001022c f3              ??         F3h
        0001022d 25              ??         25h    %
        0001022e 02              ??         02h
        0001022f 90              ??         90h
        00010230 f3              ??         F3h
        00010231 45              ??         45h    E
        00010232 02              ??         02h
        00010233 98              ??         98h
        00010234 f3              ??         F3h
        00010235 65              ??         65h    e
        00010236 02              ??         02h
        00010237 a0              ??         A0h
        00010238 f3              ??         F3h
        00010239 85              ??         85h
        0001023a 02              ??         02h
        0001023b a8              ??         A8h
        0001023c f3              ??         F3h
        0001023d a5              ??         A5h
        0001023e 02              ??         02h
        0001023f b0              ??         B0h
        00010240 f3              ??         F3h
        00010241 c5              ??         C5h
        00010242 02              ??         02h
        00010243 b8              ??         B8h
        00010244 f3              ??         F3h
        00010245 e5              ??         E5h
        00010246 02              ??         02h
        00010247 c0              ??         C0h
                             LAB_00010248                                    XREF[1]:     000101c4(j)  
        00010248 4e 80 00 20     blr


void OSLoadFPUContext(undefined4 param_1)
{
  __OSLoadFPUContext(param_1,param_1);
  return;
}

void OSSaveFPUContext(undefined4 param_1,undefined4 param_2)
{
  __OSSaveFPUContext(param_1,param_2,param_1);
  return;
}

void OSSetCurrentContext(uint param_1)
{
  _DAT_800000c0 = param_1 & 0x3fffffff;
  _DAT_800000d4 = param_1;
  if (_DAT_800000d8 == param_1) {
    *(uint *)(param_1 + 0x19c) = *(uint *)(param_1 + 0x19c) | 0x2000;
    return;
  }
  *(uint *)(param_1 + 0x19c) = *(uint *)(param_1 + 0x19c) & 0xffffdfff;
  instructionSynchronize();
  return;
}

undefined4 OSGetCurrentContext(void)
{
  return _DAT_800000d4;
}

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined OSSaveContext()
             undefined         r3:1           <RETURN>
                             OSSaveContext                                   XREF[1]:     Entry Point(*)  
        000102c4 bd a3 00 34     stmw       r13,0x34(r3)
        000102c8 7c 11 e2 a6     mfspr      r0,spr391
        000102cc 90 03 01 a8     stw        r0,0x1a8(r3)
        000102d0 7c 12 e2 a6     mfspr      r0,spr392
        000102d4 90 03 01 ac     stw        r0,0x1ac(r3)
        000102d8 7c 13 e2 a6     mfspr      r0,spr393
        000102dc 90 03 01 b0     stw        r0,0x1b0(r3)
        000102e0 7c 14 e2 a6     mfspr      r0,spr394
        000102e4 90 03 01 b4     stw        r0,0x1b4(r3)
        000102e8 7c 15 e2 a6     mfspr      r0,spr395
        000102ec 90 03 01 b8     stw        r0,0x1b8(r3)
        000102f0 7c 16 e2 a6     mfspr      r0,spr396
        000102f4 90 03 01 bc     stw        r0,0x1bc(r3)
        000102f8 7c 17 e2 a6     mfspr      r0,spr397
        000102fc 90 03 01 c0     stw        r0,0x1c0(r3)
        00010300 7c 00 00 26     mfcr       r0
        00010304 90 03 00 80     stw        r0,0x80(r3)
        00010308 7c 08 02 a6     mfspr      r0,LR
        0001030c 90 03 00 84     stw        r0,0x84(r3)
        00010310 90 03 01 98     stw        r0,0x198(r3)
        00010314 7c 00 00 a6     mfmsr      r0
        00010318 90 03 01 9c     stw        r0,0x19c(r3)
        0001031c 7c 09 02 a6     mfspr      r0,CTR
        00010320 90 03 00 88     stw        r0,0x88(r3)
        00010324 7c 01 02 a6     mfspr      r0,XER
        00010328 90 03 00 8c     stw        r0,0x8c(r3)
        0001032c 90 23 00 04     stw        r1,0x4(r3)
        00010330 90 43 00 08     stw        r2,0x8(r3)
        00010334 38 00 00 01     li         r0,0x1
        00010338 90 03 00 0c     stw        r0,0xc(r3)
        0001033c 38 60 00 00     li         r3,0x0
        00010340 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined OSLoadContext()
             undefined         r3:1           <RETURN>
                             OSLoadContext                                   XREF[1]:     Entry Point(*)  
        00010344 3c 80 00 01     lis        r4,0x1
        00010348 80 c3 01 98     lwz        r6,0x198(r3)
        0001034c 38 a4 10 00     addi       r5,r4,0x1000
        00010350 7c 06 28 40     cmplw      r6,r5
        00010354 41 80 00 18     blt        LAB_0001036c
        00010358 3c 80 00 01     lis        r4,0x1
        0001035c 38 04 10 04     addi       r0,r4,0x1004
        00010360 7c 06 00 40     cmplw      r6,r0
        00010364 41 81 00 08     bgt        LAB_0001036c
        00010368 90 a3 01 98     stw        r5=>__RAS_OSDisableInterrupts_begin,0x198(r3)    = ??
                             LAB_0001036c                                    XREF[2]:     00010354(j), 00010364(j)  
        0001036c 80 03 00 00     lwz        r0,0x0(r3)
        00010370 80 23 00 04     lwz        r1,0x4(r3)
        00010374 80 43 00 08     lwz        r2,0x8(r3)
        00010378 a0 83 01 a2     lhz        r4,0x1a2(r3)
        0001037c 54 85 07 bd     rlwinm.    r5,r4,0x0,0x1e,0x1e
        00010380 41 82 00 14     beq        LAB_00010394
        00010384 54 84 07 fa     rlwinm     r4,r4,0x0,0x1f,0x1d
        00010388 b0 83 01 a2     sth        r4,0x1a2(r3)
        0001038c b8 a3 00 14     lmw        r5,0x14(r3)
        00010390 48 00 00 08     b          LAB_00010398
                             LAB_00010394                                    XREF[1]:     00010380(j)  
        00010394 b9 a3 00 34     lmw        r13,0x34(r3)
                             LAB_00010398                                    XREF[1]:     00010390(j)  
        00010398 80 83 01 a8     lwz        r4,0x1a8(r3)
        0001039c 7c 91 e3 a6     mtspr      spr391,r4
        000103a0 80 83 01 ac     lwz        r4,0x1ac(r3)
        000103a4 7c 92 e3 a6     mtspr      spr392,r4
        000103a8 80 83 01 b0     lwz        r4,0x1b0(r3)
        000103ac 7c 93 e3 a6     mtspr      spr393,r4
        000103b0 80 83 01 b4     lwz        r4,0x1b4(r3)
        000103b4 7c 94 e3 a6     mtspr      spr394,r4
        000103b8 80 83 01 b8     lwz        r4,0x1b8(r3)
        000103bc 7c 95 e3 a6     mtspr      spr395,r4
        000103c0 80 83 01 bc     lwz        r4,0x1bc(r3)
        000103c4 7c 96 e3 a6     mtspr      spr396,r4
        000103c8 80 83 01 c0     lwz        r4,0x1c0(r3)
        000103cc 7c 97 e3 a6     mtspr      spr397,r4
        000103d0 80 83 00 80     lwz        r4,0x80(r3)
        000103d4 7c 8f f1 20     mtcrf      0xff,r4
        000103d8 80 83 00 84     lwz        r4,0x84(r3)
        000103dc 7c 88 03 a6     mtspr      LR,r4
        000103e0 80 83 00 88     lwz        r4,0x88(r3)
        000103e4 7c 89 03 a6     mtspr      CTR,r4
        000103e8 80 83 00 8c     lwz        r4,0x8c(r3)
        000103ec 7c 81 03 a6     mtspr      XER,r4
        000103f0 7c 80 00 a6     mfmsr      r4
        000103f4 54 84 04 5e     rlwinm     r4,r4,0x0,0x11,0xf
        000103f8 54 84 07 fa     rlwinm     r4,r4,0x0,0x1f,0x1d
        000103fc 7c 80 01 24     mtmsr      r4,0
        00010400 80 83 01 98     lwz        r4,0x198(r3)
        00010404 7c 9a 03 a6     mtspr      SRR0,r4
        00010408 80 83 01 9c     lwz        r4,0x19c(r3)
        0001040c 7c 9b 03 a6     mtspr      SRR1,r4
        00010410 80 83 00 10     lwz        r4,0x10(r3)
        00010414 80 63 00 0c     lwz        r3,0xc(r3)
        00010418 4c 00 00 64     rfi

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined OSGetStackPointer()
             undefined         r3:1           <RETURN>
                             OSGetStackPointer                               XREF[1]:     Entry Point(*)  
        0001041c 7c 23 0b 78     or         r3,r1,r1
        00010420 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined OSSwitchStack()
             undefined         r3:1           <RETURN>
                             OSSwitchStack                                   XREF[1]:     Entry Point(*)  
        00010424 7c 25 0b 78     or         r5,r1,r1
        00010428 7c 61 1b 78     or         r1,r3,r3
        0001042c 7c a3 2b 78     or         r3,r5,r5
        00010430 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined OSSwitchFiber()
             undefined         r3:1           <RETURN>
             undefined4        Stack[0x4]:4   local_res4                              XREF[2]:     00010444(W), 
                                                                                                   00010454(R)  
                             OSSwitchFiber                                   XREF[1]:     Entry Point(*)  
        00010434 7c 08 02 a6     mfspr      r0,LR
        00010438 7c 25 0b 78     or         r5,r1,r1
        0001043c 94 a4 ff f8     stwu       r5,-0x8(r4)
        00010440 7c 81 23 78     or         r1,r4,r4
        00010444 90 05 00 04     stw        r0,local_res4(r5)
        00010448 7c 68 03 a6     mtspr      LR,r3
        0001044c 4e 80 00 21     blrl
        00010450 80 a1 00 00     lwz        r5,0x0(r1)
        00010454 80 05 00 04     lwz        r0,local_res4(r5)
        00010458 7c 08 03 a6     mtspr      LR,r0
        0001045c 7c a1 2b 78     or         r1,r5,r5
        00010460 4e 80 00 20     blr


void OSClearContext(int param_1)
{
  *(undefined2 *)(param_1 + 0x1a0) = 0;
  *(undefined2 *)(param_1 + 0x1a2) = 0;
  if (param_1 == _DAT_800000d8) {
    _DAT_800000d8 = 0;
  }
  return;
}

void OSInitContext(int param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 unaff_r2;
  undefined4 unaff_r13;

  *(undefined4 *)(param_1 + 0x198) = param_2;
  *(undefined4 *)(param_1 + 4) = param_3;
  *(undefined4 *)(param_1 + 0x19c) = 0x9032;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 8) = unaff_r2;
  *(undefined4 *)(param_1 + 0x34) = unaff_r13;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x1a4) = 0;
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  *(undefined4 *)(param_1 + 0x1ac) = 0;
  *(undefined4 *)(param_1 + 0x1b0) = 0;
  *(undefined4 *)(param_1 + 0x1b4) = 0;
  *(undefined4 *)(param_1 + 0x1b8) = 0;
  *(undefined4 *)(param_1 + 0x1bc) = 0;
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  OSClearContext();
  return;
}

void OSDumpContext(int param_1)
{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined auStack_2e8 [716];
  
  OSReport(...data.0,param_1);
  for (uVar7 = 0; uVar7 < 0x10; uVar7 = uVar7 + 1) {
    OSReport(@43,uVar7,*(undefined4 *)(param_1 + uVar7 * 4),*(undefined4 *)(param_1 + uVar7 * 4),
             uVar7 + 0x10,*(undefined4 *)(param_1 + (uVar7 + 0x10) * 4),
             *(undefined4 *)(param_1 + (uVar7 + 0x10) * 4));
  }
  OSReport(@44,*(undefined4 *)(param_1 + 0x84),*(undefined4 *)(param_1 + 0x80));
  OSReport(@45,*(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x19c));
  OSReport(@46);
  for (uVar7 = 0; uVar7 < 4; uVar7 = uVar7 + 1) {
    OSReport(@47,uVar7,*(undefined4 *)(param_1 + uVar7 * 4 + 0x1a4),uVar7 + 4,
             *(undefined4 *)(param_1 + (uVar7 + 4) * 4 + 0x1a4));
  }
  if ((*(ushort *)(param_1 + 0x1a2) & 1) != 0) {
    uVar2 = OSDisableInterrupts();
    uVar3 = OSGetCurrentContext();
    OSClearContext(auStack_2e8);
    OSSetCurrentContext(auStack_2e8);
    OSReport(@48);
    for (uVar7 = 0; uVar7 < 0x20; uVar7 = uVar7 + 2) {
      uVar4 = __cvt_fp2unsigned(*(undefined8 *)(param_1 + (uVar7 + 1) * 8 + 0x90));
      uVar5 = __cvt_fp2unsigned(*(undefined8 *)(param_1 + uVar7 * 8 + 0x90));
      OSReport(@49,uVar7,uVar5,uVar7 + 1,uVar4);
    }
    OSReport(@50);
    for (uVar7 = 0; uVar7 < 0x20; uVar7 = uVar7 + 2) {
      uVar4 = __cvt_fp2unsigned(*(undefined8 *)(param_1 + (uVar7 + 1) * 8 + 0x1c8));
      uVar5 = __cvt_fp2unsigned(*(undefined8 *)(param_1 + uVar7 * 8 + 0x1c8));
      OSReport(@51,uVar7,uVar5,uVar7 + 1,uVar4);
    }
    OSClearContext(auStack_2e8);
    OSSetCurrentContext(uVar3);
    OSRestoreInterrupts(uVar2);
  }
  OSReport(@52);
  uVar7 = 0;
  puVar6 = *(undefined4 **)(param_1 + 4);
  while (((puVar6 != (undefined4 *)0x0 && (puVar6 != (undefined4 *)0xffffffff)) &&
         (bVar1 = uVar7 < 0x10, uVar7 = uVar7 + 1, bVar1))) {
    OSReport(@53,puVar6,*puVar6,puVar6[1]);
    puVar6 = (undefined4 *)*puVar6;
  }
  return;
}

undefined8 OSSwitchFPUContext(undefined4 param_1,int param_2)
{
  bool bVar1;
  int iVar2;
  int extraout_r4;
  uint uVar3;
  uint in_MSR;
  uint uVar4;
  
  uVar3 = in_MSR >> 0xe & 1;
  uVar4 = in_MSR & 0x9030 |
          in_MSR & 0xffff6fcf | 0x2000 | (in_MSR >> 0xf & 1 | uVar3) << 0xf |
          ((in_MSR & 0x20) >> 5 | uVar3) << 5 | ((in_MSR & 0x10) >> 4 | uVar3) << 4;
  instructionSynchronize();
  uVar3 = *(uint *)(param_2 + 0x19c) | 0x2000;
  iVar2 = param_2;
  if (_DAT_800000d8 != param_2) {
    bVar1 = _DAT_800000d8 != 0;
    _DAT_800000d8 = param_2;
    if (bVar1) {
      __OSSaveFPUContext();
    }
    __OSLoadFPUContext();
    param_2 = extraout_r4;
    iVar2 = _DAT_800000d8;
  }
  _DAT_800000d8 = iVar2;
  *(ushort *)(param_2 + 0x1a2) = *(ushort *)(param_2 + 0x1a2) & 0xfffd;
  returnFromInterrupt(uVar4,uVar3);
  return *(undefined8 *)(param_2 + 0xc);
}

void __OSContextInit(void)
{
  __OSSetExceptionHandler(7,OSSwitchFPUContext);
  _DAT_800000d8 = 0;
  DBPrintf(@57);
  return;
}

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined OSFillFPUContext()
             undefined         r3:1           <RETURN>
                             OSFillFPUContext                                XREF[1]:     Entry Point(*)  
        00010888 7c a0 00 a6     mfmsr      r5
        0001088c 60 a5 20 00     ori        r5,r5,0x2000
        00010890 7c a0 01 24     mtmsr      r5,0
        00010894 4c 00 01 2c     isync
        00010898 d8 03 00 90     stfd       f0,0x90(r3)
        0001089c d8 23 00 98     stfd       f1,0x98(r3)
        000108a0 d8 43 00 a0     stfd       f2,0xa0(r3)
        000108a4 d8 63 00 a8     stfd       f3,0xa8(r3)
        000108a8 d8 83 00 b0     stfd       f4,0xb0(r3)
        000108ac d8 a3 00 b8     stfd       f5,0xb8(r3)
        000108b0 d8 c3 00 c0     stfd       f6,0xc0(r3)
        000108b4 d8 e3 00 c8     stfd       f7,0xc8(r3)
        000108b8 d9 03 00 d0     stfd       f8,0xd0(r3)
        000108bc d9 23 00 d8     stfd       f9,0xd8(r3)
        000108c0 d9 43 00 e0     stfd       f10,0xe0(r3)
        000108c4 d9 63 00 e8     stfd       f11,0xe8(r3)
        000108c8 d9 83 00 f0     stfd       f12,0xf0(r3)
        000108cc d9 a3 00 f8     stfd       f13,0xf8(r3)
        000108d0 d9 c3 01 00     stfd       f14,0x100(r3)
        000108d4 d9 e3 01 08     stfd       f15,0x108(r3)
        000108d8 da 03 01 10     stfd       f16,0x110(r3)
        000108dc da 23 01 18     stfd       f17,0x118(r3)
        000108e0 da 43 01 20     stfd       f18,0x120(r3)
        000108e4 da 63 01 28     stfd       f19,0x128(r3)
        000108e8 da 83 01 30     stfd       f20,0x130(r3)
        000108ec da a3 01 38     stfd       f21,0x138(r3)
        000108f0 da c3 01 40     stfd       f22,0x140(r3)
        000108f4 da e3 01 48     stfd       f23,0x148(r3)
        000108f8 db 03 01 50     stfd       f24,0x150(r3)
        000108fc db 23 01 58     stfd       f25,0x158(r3)
        00010900 db 43 01 60     stfd       f26,0x160(r3)
        00010904 db 63 01 68     stfd       f27,0x168(r3)
        00010908 db 83 01 70     stfd       f28,0x170(r3)
        0001090c db a3 01 78     stfd       f29,0x178(r3)
        00010910 db c3 01 80     stfd       f30,0x180(r3)
        00010914 db e3 01 88     stfd       f31,0x188(r3)
        00010918 fc 00 04 8e     mffs       f0
        0001091c d8 03 01 90     stfd       f0,0x190(r3)
        00010920 c8 03 00 90     lfd        f0,0x90(r3)
        00010924 7c b8 e2 a6     mfspr      r5,spr398
        00010928 54 a5 1f ff     rlwinm.    r5,r5,0x3,0x1f,0x1f
        0001092c 41 82 00 84     beq        LAB_000109b0
        00010930 f0              ??         F0h
        00010931 03              ??         03h
        00010932 01              ??         01h
        00010933 c8              ??         C8h
        00010934 f0              ??         F0h
        00010935 23              ??         23h    #
        00010936 01              ??         01h
        00010937 d0              ??         D0h
        00010938 f0              ??         F0h
        00010939 43              ??         43h    C
        0001093a 01              ??         01h
        0001093b d8              ??         D8h
        0001093c f0              ??         F0h
        0001093d 63              ??         63h    c
        0001093e 01              ??         01h
        0001093f e0              ??         E0h
        00010940 f0              ??         F0h
        00010941 83              ??         83h
        00010942 01              ??         01h
        00010943 e8              ??         E8h
        00010944 f0              ??         F0h
        00010945 a3              ??         A3h
        00010946 01              ??         01h
        00010947 f0              ??         F0h
        00010948 f0              ??         F0h
        00010949 c3              ??         C3h
        0001094a 01              ??         01h
        0001094b f8              ??         F8h
        0001094c f0              ??         F0h
        0001094d e3              ??         E3h
        0001094e 02              ??         02h
        0001094f 00              ??         00h
        00010950 f1              ??         F1h
        00010951 03              ??         03h
        00010952 02              ??         02h
        00010953 08              ??         08h
        00010954 f1              ??         F1h
        00010955 23              ??         23h    #
        00010956 02              ??         02h
        00010957 10              ??         10h
        00010958 f1              ??         F1h
        00010959 43              ??         43h    C
        0001095a 02              ??         02h
        0001095b 18              ??         18h
        0001095c f1              ??         F1h
        0001095d 63              ??         63h    c
        0001095e 02              ??         02h
        0001095f 20              ??         20h     
        00010960 f1              ??         F1h
        00010961 83              ??         83h
        00010962 02              ??         02h
        00010963 28              ??         28h    (
        00010964 f1              ??         F1h
        00010965 a3              ??         A3h
        00010966 02              ??         02h
        00010967 30              ??         30h    0
        00010968 f1              ??         F1h
        00010969 c3              ??         C3h
        0001096a 02              ??         02h
        0001096b 38              ??         38h    8
        0001096c f1              ??         F1h
        0001096d e3              ??         E3h
        0001096e 02              ??         02h
        0001096f 40              ??         40h    @
        00010970 f2              ??         F2h
        00010971 03              ??         03h
        00010972 02              ??         02h
        00010973 48              ??         48h    H
        00010974 f2              ??         F2h
        00010975 23              ??         23h    #
        00010976 02              ??         02h
        00010977 50              ??         50h    P
        00010978 f2              ??         F2h
        00010979 43              ??         43h    C
        0001097a 02              ??         02h
        0001097b 58              ??         58h    X
        0001097c f2              ??         F2h
        0001097d 63              ??         63h    c
        0001097e 02              ??         02h
        0001097f 60              ??         60h    `
        00010980 f2              ??         F2h
        00010981 83              ??         83h
        00010982 02              ??         02h
        00010983 68              ??         68h    h
        00010984 f2              ??         F2h
        00010985 a3              ??         A3h
        00010986 02              ??         02h
        00010987 70              ??         70h    p
        00010988 f2              ??         F2h
        00010989 c3              ??         C3h
        0001098a 02              ??         02h
        0001098b 78              ??         78h    x
        0001098c f2              ??         F2h
        0001098d e3              ??         E3h
        0001098e 02              ??         02h
        0001098f 80              ??         80h
        00010990 f3              ??         F3h
        00010991 03              ??         03h
        00010992 02              ??         02h
        00010993 88              ??         88h
        00010994 f3              ??         F3h
        00010995 23              ??         23h    #
        00010996 02              ??         02h
        00010997 90              ??         90h
        00010998 f3              ??         F3h
        00010999 43              ??         43h    C
        0001099a 02              ??         02h
        0001099b 98              ??         98h
        0001099c f3              ??         F3h
        0001099d 63              ??         63h    c
        0001099e 02              ??         02h
        0001099f a0              ??         A0h
        000109a0 f3              ??         F3h
        000109a1 83              ??         83h
        000109a2 02              ??         02h
        000109a3 a8              ??         A8h
        000109a4 f3              ??         F3h
        000109a5 a3              ??         A3h
        000109a6 02              ??         02h
        000109a7 b0              ??         B0h
        000109a8 f3              ??         F3h
        000109a9 c3              ??         C3h
        000109aa 02              ??         02h
        000109ab b8              ??         B8h
        000109ac f3              ??         F3h
        000109ad e3              ??         E3h
        000109ae 02              ??         02h
        000109af c0              ??         C0h
                             LAB_000109b0                                    XREF[1]:     0001092c(j)  
        000109b0 4e 80 00 20     blr
