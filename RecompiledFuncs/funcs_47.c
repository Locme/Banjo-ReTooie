#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800D053C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D053C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D0540: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D0544: bne         $a1, $at, L_800D0584
    if (ctx->r5 != ctx->r1) {
        // 0x800D0548: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800D0584;
    }
    // 0x800D0548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D054C: jal         0x800CFC5C
    // 0x800D0550: nop

    func_800CFC5C(rdram, ctx);
        goto after_0;
    // 0x800D0550: nop

    after_0:
    // 0x800D0554: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D0558: beql        $v0, $at, L_800D0588
    if (ctx->r2 == ctx->r1) {
        // 0x800D055C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D0588;
    }
    goto skip_0;
    // 0x800D055C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D0560: jal         0x800EA05C
    // 0x800D0564: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x800D0564: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800D0568: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800D056C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D0570: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800D0574: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x800D0578: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D057C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800D0580: sh          $v0, -0x4E70($at)
    MEM_H(-0X4E70, ctx->r1) = ctx->r2;
L_800D0584:
    // 0x800D0584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D0588:
    // 0x800D0588: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D058C: jr          $ra
    // 0x800D0590: nop

    return;
    // 0x800D0590: nop

;}
RECOMP_FUNC void _sucoaster_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A160: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A160);
    return;
    // 0x8008A164: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void _gztrace_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A950: syscall     878
    recomp_syscall_handler(rdram, ctx, 0x8008A950);
    return;
    // 0x8008A954: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800E13F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E13F0: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800E13F4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800E13F8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800E13FC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E1400: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E1404: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800E1408: jr          $ra
    // 0x800E140C: swc1        $f12, -0x3048($at)
    MEM_W(-0X3048, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x800E140C: swc1        $f12, -0x3048($at)
    MEM_W(-0X3048, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_808008A8_chbubbleelevator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008B0: lbu         $t6, 0x79($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X79);
    // 0x808008B4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808008B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2368, 0XC2C) << 16);
    // 0x808008BC: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x808008C0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808008C4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x808008C8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x808008CC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808008D0: lwc1        $f4, 0xC2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2368, 0XC2C));
    // 0x808008D4: lwc1        $f12, 0x58($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X58);
    // 0x808008D8: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x808008DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808008E0: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x808008E4: jal         0x800F12D4
    // 0x808008E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_0;
    // 0x808008E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x808008EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008F0: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x808008F4: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x808008F8: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x808008FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800900: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800904: jr          $ra
    // 0x80800908: nop

    return;
    // 0x80800908: nop

;}
RECOMP_FUNC void func_80800240_chiciclebits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800240: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800244: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800248: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8080024C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800250: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800254: beq         $a1, $at, L_80800278
    if (ctx->r5 == ctx->r1) {
        // 0x80800258: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800278;
    }
    // 0x80800258: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080025C: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x80800260: beq         $a1, $at, L_8080031C
    if (ctx->r5 == ctx->r1) {
        // 0x80800264: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_8080031C;
    }
    // 0x80800264: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800268: beq         $a1, $at, L_80800338
    if (ctx->r5 == ctx->r1) {
        // 0x8080026C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800338;
    }
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: b           L_80800374
    // 0x80800274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800374;
    // 0x80800274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800278:
    // 0x80800278: addiu       $a0, $zero, 0x41C
    ctx->r4 = ADD32(0, 0X41C);
    // 0x8080027C: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x80800280: jal         0x80101180
    // 0x80800284: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x80800284: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800288: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8080028C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1228, 0X4B8) << 16);
    // 0x80800290: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80800294: addiu       $a2, $a2, 0x4B8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1228, 0X4B8));
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080029C: jal         0x80089D18
    // 0x808002A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808002A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808002A4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1228, 0X4C8) << 16);
    // 0x808002A8: addiu       $a2, $a2, 0x4C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1228, 0X4C8));
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B0: jal         0x80089D18
    // 0x808002B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808002B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808002B8: jal         0x8010A570
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C4: jal         0x80101FDC
    // 0x808002C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808002C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D0: jal         0x80103110
    // 0x808002D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_5;
    // 0x808002D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808002D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808002DC: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x808002E0: jal         0x80018820
    // 0x808002E4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_80018820(rdram, ctx);
        goto after_6;
    // 0x808002E4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_6:
    // 0x808002E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1228, 0X398) << 16);
    // 0x808002EC: lwc1        $f4, 0x398($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1228, 0X398));
    // 0x808002F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808002F8: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x808002FC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800300: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    // 0x80800304: beql        $t7, $zero, L_80800374
    if (ctx->r15 == 0) {
        // 0x80800308: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800374;
    }
    goto skip_0;
    // 0x80800308: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8080030C: jal         0x80085708
    // 0x80800310: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_7;
    // 0x80800310: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x80800314: b           L_80800374
    // 0x80800318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800374;
    // 0x80800318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080031C:
    // 0x8080031C: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x80800320: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800324: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800328: bnel        $t9, $at, L_80800374
    if (ctx->r25 != ctx->r1) {
        // 0x8080032C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800374;
    }
    goto skip_1;
    // 0x8080032C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800330: b           L_80800374
    // 0x80800334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800374;
    // 0x80800334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800338:
    // 0x80800338: lw          $t0, 0x28($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X28);
    // 0x8080033C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80800340: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1228, 0X3F0) << 16);
    // 0x80800344: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80800348: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8080034C: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80800350: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x80800354: lhu         $a1, 0x3F0($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1228, 0X3F0));
    // 0x80800358: jal         0x80103140
    // 0x8080035C: lhu         $a2, 0x16($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X16);
    func_80103140(rdram, ctx);
        goto after_8;
    // 0x8080035C: lhu         $a2, 0x16($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X16);
    after_8:
    // 0x80800360: b           L_80800374
    // 0x80800364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800374;
    // 0x80800364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800368: b           L_80800374
    // 0x8080036C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800374;
    // 0x8080036C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800374:
    // 0x80800374: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800378: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080037C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800380: jr          $ra
    // 0x80800384: nop

    return;
    // 0x80800384: nop

    // 0x80800388: nop

    // 0x8080038C: nop

;}
RECOMP_FUNC void _gcboundDll_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087EF0: syscall     661
    recomp_syscall_handler(rdram, ctx, 0x80087EF0);
    return;
    // 0x80087EF4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80015CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015CC0: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x80015CC4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80015CC8: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x80015CCC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80015CD0: lh          $t8, 0x8($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X8);
    // 0x80015CD4: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80015CD8: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x80015CDC: lh          $t9, 0xA($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XA);
    // 0x80015CE0: jr          $ra
    // 0x80015CE4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    return;
    // 0x80015CE4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
;}
RECOMP_FUNC void func_80801464_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801464: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801468: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080146C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801470: jal         0x8009BF5C
    // 0x80801474: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_0;
    // 0x80801474: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x80801478: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080147C: jal         0x8009C4CC
    // 0x80801480: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_1;
    // 0x80801480: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80801484: jal         0x80800E54
    // 0x80801488: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstnt_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80801488: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080148C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801490: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801494: jr          $ra
    // 0x80801498: nop

    return;
    // 0x80801498: nop

;}
RECOMP_FUNC void inflate_stored_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C904: mfc1        $t2, $f17
    ctx->r10 = (int32_t)ctx->f_odd[(17 - 1) * 2];
    // 0x8001C908: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8001C90C: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8001C910: andi        $t3, $fp, 0x7
    ctx->r11 = ctx->r30 & 0X7;
    // 0x8001C914: srlv        $gp, $gp, $t3
    ctx->r28 = S32(U32(ctx->r28) >> (ctx->r11 & 31));
    // 0x8001C918: subu        $fp, $fp, $t3
    ctx->r30 = SUB32(ctx->r30, ctx->r11);
    // 0x8001C91C: slti        $at, $fp, 0x10
    ctx->r1 = SIGNED(ctx->r30) < 0X10 ? 1 : 0;
    // 0x8001C920: beq         $at, $zero, L_8001C948
    if (ctx->r1 == 0) {
        // 0x8001C924: nop
    
            goto L_8001C948;
    }
    // 0x8001C924: nop

    // 0x8001C928: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_8001C92C:
    // 0x8001C92C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001C930: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x8001C934: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x8001C938: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x8001C93C: slti        $at, $fp, 0x10
    ctx->r1 = SIGNED(ctx->r30) < 0X10 ? 1 : 0;
    // 0x8001C940: bnel        $at, $zero, L_8001C92C
    if (ctx->r1 != 0) {
        // 0x8001C944: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_8001C92C;
    }
    goto skip_0;
    // 0x8001C944: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_0:
L_8001C948:
    // 0x8001C948: andi        $t3, $gp, 0xFFFF
    ctx->r11 = ctx->r28 & 0XFFFF;
    // 0x8001C94C: srl         $gp, $gp, 16
    ctx->r28 = S32(U32(ctx->r28) >> 16);
    // 0x8001C950: addiu       $fp, $fp, -0x10
    ctx->r30 = ADD32(ctx->r30, -0X10);
    // 0x8001C954: slti        $at, $fp, 0x10
    ctx->r1 = SIGNED(ctx->r30) < 0X10 ? 1 : 0;
    // 0x8001C958: beq         $at, $zero, L_8001C980
    if (ctx->r1 == 0) {
        // 0x8001C95C: nop
    
            goto L_8001C980;
    }
    // 0x8001C95C: nop

    // 0x8001C960: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_8001C964:
    // 0x8001C964: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001C968: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x8001C96C: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x8001C970: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x8001C974: slti        $at, $fp, 0x10
    ctx->r1 = SIGNED(ctx->r30) < 0X10 ? 1 : 0;
    // 0x8001C978: bnel        $at, $zero, L_8001C964
    if (ctx->r1 != 0) {
        // 0x8001C97C: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_8001C964;
    }
    goto skip_1;
    // 0x8001C97C: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_1:
L_8001C980:
    // 0x8001C980: nor         $t5, $gp, $zero
    ctx->r13 = ~(ctx->r28 | 0);
    // 0x8001C984: andi        $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 & 0XFFFF;
    // 0x8001C988: bne         $t3, $t5, L_8001CA24
    if (ctx->r11 != ctx->r13) {
        // 0x8001C98C: srl         $gp, $gp, 16
        ctx->r28 = S32(U32(ctx->r28) >> 16);
            goto L_8001CA24;
    }
    // 0x8001C98C: srl         $gp, $gp, 16
    ctx->r28 = S32(U32(ctx->r28) >> 16);
    // 0x8001C990: addiu       $fp, $fp, -0x10
    ctx->r30 = ADD32(ctx->r30, -0X10);
    // 0x8001C994: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x8001C998: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001C99C: beq         $at, $zero, L_8001CA24
    if (ctx->r1 == 0) {
        // 0x8001C9A0: addu        $t5, $t7, $t2
        ctx->r13 = ADD32(ctx->r15, ctx->r10);
            goto L_8001CA24;
    }
    // 0x8001C9A0: addu        $t5, $t7, $t2
    ctx->r13 = ADD32(ctx->r15, ctx->r10);
    // 0x8001C9A4: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x8001C9A8: beq         $t3, $zero, L_8001CA18
    if (ctx->r11 == 0) {
        // 0x8001C9AC: addiu       $t3, $t3, -0x1
        ctx->r11 = ADD32(ctx->r11, -0X1);
            goto L_8001CA18;
    }
    // 0x8001C9AC: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
L_8001C9B0:
    // 0x8001C9B0: slti        $at, $fp, 0x8
    ctx->r1 = SIGNED(ctx->r30) < 0X8 ? 1 : 0;
    // 0x8001C9B4: beq         $at, $zero, L_8001C9DC
    if (ctx->r1 == 0) {
        // 0x8001C9B8: nop
    
            goto L_8001C9DC;
    }
    // 0x8001C9B8: nop

    // 0x8001C9BC: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_8001C9C0:
    // 0x8001C9C0: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001C9C4: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x8001C9C8: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x8001C9CC: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x8001C9D0: slti        $at, $fp, 0x8
    ctx->r1 = SIGNED(ctx->r30) < 0X8 ? 1 : 0;
    // 0x8001C9D4: bnel        $at, $zero, L_8001C9C0
    if (ctx->r1 != 0) {
        // 0x8001C9D8: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_8001C9C0;
    }
    goto skip_2;
    // 0x8001C9D8: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_2:
L_8001C9DC:
    // 0x8001C9DC: sb          $gp, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r28;
    // 0x8001C9E0: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8001C9E4: lw          $v0, 0xA84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA84);
    // 0x8001C9E8: andi        $v1, $gp, 0xFF
    ctx->r3 = ctx->r28 & 0XFF;
    // 0x8001C9EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001C9F0: sw          $v0, 0xA84($sp)
    MEM_W(0XA84, ctx->r29) = ctx->r2;
    // 0x8001C9F4: andi        $v0, $v0, 0x17
    ctx->r2 = ctx->r2 & 0X17;
    // 0x8001C9F8: sllv        $v1, $v1, $v0
    ctx->r3 = S32(ctx->r3 << (ctx->r2 & 31));
    // 0x8001C9FC: lw          $v0, 0xA88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA88);
    // 0x8001CA00: xor         $v0, $v0, $v1
    ctx->r2 = ctx->r2 ^ ctx->r3;
    // 0x8001CA04: sw          $v0, 0xA88($sp)
    MEM_W(0XA88, ctx->r29) = ctx->r2;
    // 0x8001CA08: srl         $gp, $gp, 8
    ctx->r28 = S32(U32(ctx->r28) >> 8);
    // 0x8001CA0C: addiu       $fp, $fp, -0x8
    ctx->r30 = ADD32(ctx->r30, -0X8);
    // 0x8001CA10: bne         $t3, $zero, L_8001C9B0
    if (ctx->r11 != 0) {
        // 0x8001CA14: addiu       $t3, $t3, -0x1
        ctx->r11 = ADD32(ctx->r11, -0X1);
            goto L_8001C9B0;
    }
    // 0x8001CA14: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
L_8001CA18:
    // 0x8001CA18: mtc1        $t2, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r10;
    // 0x8001CA1C: jr          $ra
    // 0x8001CA20: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    return;
    // 0x8001CA20: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
L_8001CA24:
    // 0x8001CA24: jr          $ra
    // 0x8001CA28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8001CA28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void _glid_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088668: syscall     697
    recomp_syscall_handler(rdram, ctx, 0x80088668);
    return;
    // 0x8008866C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800CB45C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB45C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CB460: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CB464: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800CB468: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800CB46C: addiu       $t8, $t8, -0x5490
    ctx->r24 = ADD32(ctx->r24, -0X5490);
    // 0x800CB470: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800CB474: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800CB478: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800CB47C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB480: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800CB484: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800CB488: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800CB48C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800CB490: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800CB494: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800CB498: jal         0x800EE7F8
    // 0x800CB49C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800CB49C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800CB4A0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB4A4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800CB4A8: lh          $t9, 0x18($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X18);
    // 0x800CB4AC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800CB4B0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB4B4: lh          $t1, 0x1A($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1A);
    // 0x800CB4B8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800CB4BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB4C0: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800CB4C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CB4C8: jr          $ra
    // 0x800CB4CC: nop

    return;
    // 0x800CB4CC: nop

;}
RECOMP_FUNC void _chskeletonexplode_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086DE8: syscall     459
    recomp_syscall_handler(rdram, ctx, 0x80086DE8);
    return;
    // 0x80086DEC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bafly_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C18: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084C18);
    return;
    // 0x80084C1C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _vpglow_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089068: syscall     758
    recomp_syscall_handler(rdram, ctx, 0x80089068);
    return;
    // 0x8008906C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _glsavegame_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088540: syscall     692
    recomp_syscall_handler(rdram, ctx, 0x80088540);
    return;
    // 0x80088544: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _chdodgemcontrol_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D00: syscall     445
    recomp_syscall_handler(rdram, ctx, 0x80086D00);
    return;
    // 0x80086D04: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800DA944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA944: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DA948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DA94C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DA950: jal         0x800DA564
    // 0x800DA954: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x800DA954: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800DA958: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x800DA95C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DA960: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DA964: jal         0x800DA7A8
    // 0x800DA968: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800DA7A8(rdram, ctx);
        goto after_1;
    // 0x800DA968: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800DA96C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DA970: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA974: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DA978: jr          $ra
    // 0x800DA97C: nop

    return;
    // 0x800DA97C: nop

;}
RECOMP_FUNC void func_80106F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106F38: lw          $v0, 0x94($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X94);
    // 0x80106F3C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106F40: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80106F44: srl         $v0, $t6, 22
    ctx->r2 = S32(U32(ctx->r14) >> 22);
    // 0x80106F48: bne         $v0, $zero, L_80106F58
    if (ctx->r2 != 0) {
        // 0x80106F4C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80106F58;
    }
    // 0x80106F4C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80106F50: b           L_80106F60
    // 0x80106F54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80106F60;
    // 0x80106F54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80106F58:
    // 0x80106F58: jal         0x800B301C
    // 0x80106F5C: lw          $a0, 0x6F00($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6F00);
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x80106F5C: lw          $a0, 0x6F00($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6F00);
    after_0:
L_80106F60:
    // 0x80106F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80106F64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106F68: jr          $ra
    // 0x80106F6C: nop

    return;
    // 0x80106F6C: nop

;}
RECOMP_FUNC void func_80800FEC_chwumbawigwam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800FF0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800FF4: beq         $a1, $at, L_80801050
    if (ctx->r5 == ctx->r1) {
        // 0x80800FF8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80801050;
    }
    // 0x80800FF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FFC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80801000: beq         $a1, $at, L_80801048
    if (ctx->r5 == ctx->r1) {
        // 0x80801004: addiu       $at, $zero, 0x4B
        ctx->r1 = ADD32(0, 0X4B);
            goto L_80801048;
    }
    // 0x80801004: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x80801008: bne         $a1, $at, L_80801060
    if (ctx->r5 != ctx->r1) {
        // 0x8080100C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801060;
    }
    // 0x8080100C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801010: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80801014: bne         $a2, $at, L_80801040
    if (ctx->r6 != ctx->r1) {
        // 0x80801018: nop
    
            goto L_80801040;
    }
    // 0x80801018: nop

    // 0x8080101C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80801020: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801024: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x80801028: beq         $at, $zero, L_80801040
    if (ctx->r1 == 0) {
        // 0x8080102C: nop
    
            goto L_80801040;
    }
    // 0x8080102C: nop

    // 0x80801030: jal         0x80800B9C
    // 0x80801034: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800B9C_chwumbawigwam(rdram, ctx);
        goto after_0;
    // 0x80801034: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80801038: b           L_80801060
    // 0x8080103C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801060;
    // 0x8080103C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801040:
    // 0x80801040: b           L_80801060
    // 0x80801044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801060;
    // 0x80801044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801048:
    // 0x80801048: b           L_80801060
    // 0x8080104C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801060;
    // 0x8080104C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801050:
    // 0x80801050: jal         0x800DA524
    // 0x80801054: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA524(rdram, ctx);
        goto after_1;
    // 0x80801054: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_1:
    // 0x80801058: b           L_80801060
    // 0x8080105C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80801060;
    // 0x8080105C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80801060:
    // 0x80801060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801068: jr          $ra
    // 0x8080106C: nop

    return;
    // 0x8080106C: nop

;}
RECOMP_FUNC void func_800E0A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0A28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E0A2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E0A30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E0A34: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800E0A38: jal         0x8001B798
    // 0x800E0A3C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x800E0A3C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x800E0A40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E0A44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E0A48: jr          $ra
    // 0x800E0A4C: nop

    return;
    // 0x800E0A4C: nop

;}
RECOMP_FUNC void func_80800000_chpotogoldbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80085808
    // 0x80800010: addiu       $a1, $zero, 0xA2D
    ctx->r5 = ADD32(0, 0XA2D);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a1, $zero, 0xA2D
    ctx->r5 = ADD32(0, 0XA2D);
    after_0:
    // 0x80800014: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800018: jal         0x80085810
    // 0x8080001C: addiu       $a1, $zero, 0x601
    ctx->r5 = ADD32(0, 0X601);
    _chswitch_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x8080001C: addiu       $a1, $zero, 0x601
    ctx->r5 = ADD32(0, 0X601);
    after_1:
    // 0x80800020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800028: jr          $ra
    // 0x8080002C: nop

    return;
    // 0x8080002C: nop

;}
RECOMP_FUNC void func_80800600_chnicecavemenguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800600: jr          $ra
    // 0x80800604: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800604: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800DC8_chnewshovel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800DD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DD4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1516, 0X10B0) << 16);
    // 0x80800DD8: jal         0x80101074
    // 0x80800DDC: addiu       $a0, $a0, 0x10B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1516, 0X10B0));
    func_80101074(rdram, ctx);
        goto after_0;
    // 0x80800DDC: addiu       $a0, $a0, 0x10B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1516, 0X10B0));
    after_0:
    // 0x80800DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DE8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80800DEC: jr          $ra
    // 0x80800DF0: nop

    return;
    // 0x80800DF0: nop

    // 0x80800DF4: nop

    // 0x80800DF8: nop

    // 0x80800DFC: nop

;}
RECOMP_FUNC void func_808006A4_sudeflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808006A8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808006AC: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x808006B0: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x808006B4: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x808006B8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x808006BC: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x808006C0: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
    // 0x808006C4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808006C8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808006CC: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x808006D0: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x808006D4: lui         $s5, 0x8080
    ctx->r21 = S32(RELOC_HI16(3222, 0X1020) << 16);
    // 0x808006D8: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x808006DC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x808006E0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x808006E4: lw          $s5, 0x1020($s5)
    ctx->r21 = MEM_W(ctx->r21, (int16_t)RELOC_LO16(3222, 0X1020));
    // 0x808006E8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808006EC: jal         0x800EE7F8
    // 0x808006F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808006F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x808006F4: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808006F8: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x808006FC: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80800700: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x80800704: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x80800708: beql        $a0, $zero, L_808007C8
    if (ctx->r4 == 0) {
        // 0x8080070C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_808007C8;
    }
    goto skip_0;
    // 0x8080070C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x80800710: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800714: nop

L_80800718:
    // 0x80800718: jal         0x800E9E88
    // 0x8080071C: nop

    func_800E9E88(rdram, ctx);
        goto after_1;
    // 0x8080071C: nop

    after_1:
    // 0x80800720: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800724: jal         0x800E9EB4
    // 0x80800728: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_2;
    // 0x80800728: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    after_2:
    // 0x8080072C: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80800730: beq         $at, $zero, L_808007B4
    if (ctx->r1 == 0) {
        // 0x80800734: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_808007B4;
    }
    // 0x80800734: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800738: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
L_8080073C:
    // 0x8080073C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80800740: beql        $t7, $zero, L_808007A8
    if (ctx->r15 == 0) {
        // 0x80800744: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_808007A8;
    }
    goto skip_1;
    // 0x80800744: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_1:
    // 0x80800748: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8080074C: jal         0x8008A340
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmisc_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800754: beql        $v0, $zero, L_808007A8
    if (ctx->r2 == 0) {
        // 0x80800758: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_808007A8;
    }
    goto skip_2;
    // 0x80800758: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_2:
    // 0x8080075C: jal         0x80106790
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800764: lw          $t8, 0x64($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X64);
    // 0x80800768: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080076C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800770: sll         $t0, $t8, 14
    ctx->r8 = S32(ctx->r24 << 14);
    // 0x80800774: bltzl       $t0, L_808007A8
    if (SIGNED(ctx->r8) < 0) {
        // 0x80800778: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_808007A8;
    }
    goto skip_3;
    // 0x80800778: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_3:
    // 0x8080077C: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80800780: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800784: jal         0x800F0008
    // 0x80800788: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    func_800F0008(rdram, ctx);
        goto after_5;
    // 0x80800788: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    after_5:
    // 0x8080078C: beq         $v0, $zero, L_808007A4
    if (ctx->r2 == 0) {
        // 0x80800790: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007A4;
    }
    // 0x80800790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800794: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800798: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080079C: jal         0x8010108C
    // 0x808007A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_6;
    // 0x808007A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
L_808007A4:
    // 0x808007A4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_808007A8:
    // 0x808007A8: sltu        $at, $s1, $s3
    ctx->r1 = ctx->r17 < ctx->r19 ? 1 : 0;
    // 0x808007AC: bnel        $at, $zero, L_8080073C
    if (ctx->r1 != 0) {
        // 0x808007B0: lw          $t6, 0x8($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X8);
            goto L_8080073C;
    }
    goto skip_4;
    // 0x808007B0: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    skip_4:
L_808007B4:
    // 0x808007B4: lw          $a0, 0x4($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X4);
    // 0x808007B8: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x808007BC: bne         $a0, $zero, L_80800718
    if (ctx->r4 != 0) {
        // 0x808007C0: nop
    
            goto L_80800718;
    }
    // 0x808007C0: nop

    // 0x808007C4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_808007C8:
    // 0x808007C8: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x808007CC: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x808007D0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808007D4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x808007D8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x808007DC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x808007E0: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x808007E4: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x808007E8: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x808007EC: jr          $ra
    // 0x808007F0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x808007F0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8001D800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D804: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001D808: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8001D80C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8001D810: addiu       $a2, $a2, -0x2E90
    ctx->r6 = ADD32(ctx->r6, -0X2E90);
    // 0x8001D814: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8001D818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D81C: addiu       $t1, $zero, -0x8
    ctx->r9 = ADD32(0, -0X8);
    // 0x8001D820: addiu       $t0, $zero, 0xD
    ctx->r8 = ADD32(0, 0XD);
    // 0x8001D824: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8001D828: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8001D82C: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_8001D830:
    // 0x8001D830: beq         $v1, $a0, L_8001D858
    if (ctx->r3 == ctx->r4) {
        // 0x8001D834: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8001D858;
    }
    // 0x8001D834: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8001D838: beq         $a0, $a1, L_8001D878
    if (ctx->r4 == ctx->r5) {
        // 0x8001D83C: slti        $at, $v0, 0x20
        ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
            goto L_8001D878;
    }
    // 0x8001D83C: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x8001D840: beql        $a0, $a3, L_8001D8EC
    if (ctx->r4 == ctx->r7) {
        // 0x8001D844: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8001D8EC;
    }
    goto skip_0;
    // 0x8001D844: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_0:
    // 0x8001D848: beql        $a0, $t0, L_8001D900
    if (ctx->r4 == ctx->r8) {
        // 0x8001D84C: sw          $zero, 0x690($a2)
        MEM_W(0X690, ctx->r6) = 0;
            goto L_8001D900;
    }
    goto skip_1;
    // 0x8001D84C: sw          $zero, 0x690($a2)
    MEM_W(0X690, ctx->r6) = 0;
    skip_1:
    // 0x8001D850: b           L_8001D910
    // 0x8001D854: nop

        goto L_8001D910;
    // 0x8001D854: nop

L_8001D858:
    // 0x8001D858: lw          $t7, 0x690($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X690);
    // 0x8001D85C: addiu       $t8, $t7, 0x7
    ctx->r24 = ADD32(ctx->r15, 0X7);
    // 0x8001D860: and         $t9, $t8, $t1
    ctx->r25 = ctx->r24 & ctx->r9;
    // 0x8001D864: slti        $at, $t9, 0x38
    ctx->r1 = SIGNED(ctx->r25) < 0X38 ? 1 : 0;
    // 0x8001D868: bne         $at, $zero, L_8001D95C
    if (ctx->r1 != 0) {
        // 0x8001D86C: sw          $t9, 0x690($a2)
        MEM_W(0X690, ctx->r6) = ctx->r25;
            goto L_8001D95C;
    }
    // 0x8001D86C: sw          $t9, 0x690($a2)
    MEM_W(0X690, ctx->r6) = ctx->r25;
    // 0x8001D870: b           L_8001D830
    // 0x8001D874: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
        goto L_8001D830;
    // 0x8001D874: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_8001D878:
    // 0x8001D878: lw          $t3, 0x694($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X694);
    // 0x8001D87C: sw          $zero, 0x690($a2)
    MEM_W(0X690, ctx->r6) = 0;
    // 0x8001D880: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001D884: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8001D888: slti        $at, $t4, 0x1E
    ctx->r1 = SIGNED(ctx->r12) < 0X1E ? 1 : 0;
    // 0x8001D88C: bne         $at, $zero, L_8001D8A0
    if (ctx->r1 != 0) {
        // 0x8001D890: sw          $t4, 0x694($a2)
        MEM_W(0X694, ctx->r6) = ctx->r12;
            goto L_8001D8A0;
    }
    // 0x8001D890: sw          $t4, 0x694($a2)
    MEM_W(0X694, ctx->r6) = ctx->r12;
    // 0x8001D894: addiu       $t5, $t4, -0x1E
    ctx->r13 = ADD32(ctx->r12, -0X1E);
    // 0x8001D898: sw          $t5, 0x694($a2)
    MEM_W(0X694, ctx->r6) = ctx->r13;
    // 0x8001D89C: sw          $t6, 0x698($a2)
    MEM_W(0X698, ctx->r6) = ctx->r14;
L_8001D8A0:
    // 0x8001D8A0: lw          $t7, 0x698($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X698);
    // 0x8001D8A4: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x8001D8A8: beql        $t7, $zero, L_8001D960
    if (ctx->r15 == 0) {
        // 0x8001D8AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001D960;
    }
    goto skip_2;
    // 0x8001D8AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8001D8B0: lw          $t8, 0x69C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X69C);
    // 0x8001D8B4: lw          $v0, 0x694($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X694);
    // 0x8001D8B8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8001D8BC: bgez        $t9, L_8001D8CC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8001D8C0: sw          $t9, 0x69C($a2)
        MEM_W(0X69C, ctx->r6) = ctx->r25;
            goto L_8001D8CC;
    }
    // 0x8001D8C0: sw          $t9, 0x69C($a2)
    MEM_W(0X69C, ctx->r6) = ctx->r25;
    // 0x8001D8C4: addiu       $t2, $t9, 0x1E
    ctx->r10 = ADD32(ctx->r25, 0X1E);
    // 0x8001D8C8: sw          $t2, 0x69C($a2)
    MEM_W(0X69C, ctx->r6) = ctx->r10;
L_8001D8CC:
    // 0x8001D8CC: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x8001D8D0: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x8001D8D4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8001D8D8: jal         0x8002D6E0
    // 0x8001D8DC: addu        $a0, $a2, $t3
    ctx->r4 = ADD32(ctx->r6, ctx->r11);
    _bzero(rdram, ctx);
        goto after_0;
    // 0x8001D8DC: addu        $a0, $a2, $t3
    ctx->r4 = ADD32(ctx->r6, ctx->r11);
    after_0:
    // 0x8001D8E0: b           L_8001D960
    // 0x8001D8E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001D960;
    // 0x8001D8E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D8E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_8001D8EC:
    // 0x8001D8EC: jal         0x8002D6E0
    // 0x8001D8F0: addiu       $a1, $zero, 0x690
    ctx->r5 = ADD32(0, 0X690);
    _bzero(rdram, ctx);
        goto after_1;
    // 0x8001D8F0: addiu       $a1, $zero, 0x690
    ctx->r5 = ADD32(0, 0X690);
    after_1:
    // 0x8001D8F4: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8001D8F8: addiu       $a2, $a2, -0x2E90
    ctx->r6 = ADD32(ctx->r6, -0X2E90);
    // 0x8001D8FC: sw          $zero, 0x690($a2)
    MEM_W(0X690, ctx->r6) = 0;
L_8001D900:
    // 0x8001D900: sw          $zero, 0x694($a2)
    MEM_W(0X694, ctx->r6) = 0;
    // 0x8001D904: sw          $zero, 0x69C($a2)
    MEM_W(0X69C, ctx->r6) = 0;
    // 0x8001D908: b           L_8001D95C
    // 0x8001D90C: sw          $zero, 0x698($a2)
    MEM_W(0X698, ctx->r6) = 0;
        goto L_8001D95C;
    // 0x8001D90C: sw          $zero, 0x698($a2)
    MEM_W(0X698, ctx->r6) = 0;
L_8001D910:
    // 0x8001D910: bne         $at, $zero, L_8001D95C
    if (ctx->r1 != 0) {
        // 0x8001D914: slti        $at, $v0, 0x7F
        ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
            goto L_8001D95C;
    }
    // 0x8001D914: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x8001D918: beql        $at, $zero, L_8001D960
    if (ctx->r1 == 0) {
        // 0x8001D91C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001D960;
    }
    goto skip_3;
    // 0x8001D91C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8001D920: lw          $t4, 0x694($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X694);
    // 0x8001D924: lw          $t7, 0x690($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X690);
    // 0x8001D928: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8001D92C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8001D930: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8001D934: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x8001D938: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001D93C: sb          $a0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r4;
    // 0x8001D940: lw          $t9, 0x690($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X690);
    // 0x8001D944: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x8001D948: slti        $at, $t2, 0x38
    ctx->r1 = SIGNED(ctx->r10) < 0X38 ? 1 : 0;
    // 0x8001D94C: bne         $at, $zero, L_8001D95C
    if (ctx->r1 != 0) {
        // 0x8001D950: sw          $t2, 0x690($a2)
        MEM_W(0X690, ctx->r6) = ctx->r10;
            goto L_8001D95C;
    }
    // 0x8001D950: sw          $t2, 0x690($a2)
    MEM_W(0X690, ctx->r6) = ctx->r10;
    // 0x8001D954: b           L_8001D830
    // 0x8001D958: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
        goto L_8001D830;
    // 0x8001D958: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_8001D95C:
    // 0x8001D95C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001D960:
    // 0x8001D960: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001D964: jr          $ra
    // 0x8001D968: nop

    return;
    // 0x8001D968: nop

;}
RECOMP_FUNC void baeggcursor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080001C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800020: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800024: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800028: jal         0x800A89F8
    // 0x8080002C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x8080002C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800030: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800034: jal         0x800A4C68
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_1;
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080003C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800040: bnel        $v0, $t6, L_80800100
    if (ctx->r2 != ctx->r14) {
        // 0x80800044: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800100;
    }
    goto skip_0;
    // 0x80800044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800048: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
    // 0x8080004C: lbu         $t7, 0x8($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X8);
    // 0x80800050: beql        $t7, $zero, L_80800100
    if (ctx->r15 == 0) {
        // 0x80800054: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800100;
    }
    goto skip_1;
    // 0x80800054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800058: lbu         $t8, 0xA($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XA);
    // 0x8080005C: beql        $t8, $zero, L_80800100
    if (ctx->r24 == 0) {
        // 0x80800060: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800100;
    }
    goto skip_2;
    // 0x80800060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800064: jal         0x800A9C98
    // 0x80800068: nop

    func_800A9C98(rdram, ctx);
        goto after_2;
    // 0x80800068: nop

    after_2:
    // 0x8080006C: bnel        $v0, $zero, L_80800100
    if (ctx->r2 != 0) {
        // 0x80800070: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800100;
    }
    goto skip_3;
    // 0x80800070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800074: lw          $t9, 0x68($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X68);
    // 0x80800078: jal         0x800E253C
    // 0x8080007C: lwc1        $f12, 0x18($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X18);
    func_800E253C(rdram, ctx);
        goto after_3;
    // 0x8080007C: lwc1        $f12, 0x18($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X18);
    after_3:
    // 0x80800080: lw          $t0, 0x68($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X68);
    // 0x80800084: jal         0x800E257C
    // 0x80800088: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    func_800E257C(rdram, ctx);
        goto after_4;
    // 0x80800088: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    after_4:
    // 0x8080008C: jal         0x800E2434
    // 0x80800090: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E2434(rdram, ctx);
        goto after_5;
    // 0x80800090: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80800094: jal         0x800E24CC
    // 0x80800098: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E24CC(rdram, ctx);
        goto after_6;
    // 0x80800098: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8080009C: lw          $t1, 0x68($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X68);
    // 0x808000A0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808000A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808000A8: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x808000AC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808000B0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808000B4: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x808000B8: nop

    // 0x808000BC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x808000C0: lw          $t4, 0x68($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X68);
    // 0x808000C4: lwc1        $f10, 0x4($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X4);
    // 0x808000C8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x808000CC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808000D0: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x808000D4: jal         0x800A7180
    // 0x808000D8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    func_800A7180(rdram, ctx);
        goto after_7;
    // 0x808000D8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    after_7:
    // 0x808000DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808000E0: jal         0x800D674C
    // 0x808000E4: addiu       $a0, $zero, 0x64E
    ctx->r4 = ADD32(0, 0X64E);
    func_800D674C(rdram, ctx);
        goto after_8;
    // 0x808000E4: addiu       $a0, $zero, 0x64E
    ctx->r4 = ADD32(0, 0X64E);
    after_8:
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808000F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000F4: jal         0x800E30E0
    // 0x808000F8: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_800E30E0(rdram, ctx);
        goto after_9;
    // 0x808000F8: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_9:
    // 0x808000FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800100:
    // 0x80800100: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800104: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800108: jr          $ra
    // 0x8080010C: nop

    return;
    // 0x8080010C: nop

;}
RECOMP_FUNC void func_8080043C_chmrsicecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080043C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800444: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800448: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080044C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800450: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800454: jal         0x80089C20
    // 0x80800458: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800458: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8080045C: beq         $v0, $zero, L_80800478
    if (ctx->r2 == 0) {
        // 0x80800460: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800478;
    }
    // 0x80800460: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800464: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800468: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x8080046C: jal         0x800EE7F8
    // 0x80800470: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800470: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800474: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80800478:
    // 0x80800478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080047C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800480: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800484: jr          $ra
    // 0x80800488: nop

    return;
    // 0x80800488: nop

;}
RECOMP_FUNC void func_808021D4_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808021D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808021DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808021E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808021E4: jal         0x80106790
    // 0x808021E8: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808021E8: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808021EC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808021F0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x808021F4: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x808021F8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808021FC: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80802200: srl         $t8, $t7, 22
    ctx->r24 = S32(U32(ctx->r15) >> 22);
    // 0x80802204: bnel        $t8, $at, L_80802254
    if (ctx->r24 != ctx->r1) {
        // 0x80802208: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802254;
    }
    goto skip_0;
    // 0x80802208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080220C: jal         0x80802324
    // 0x80802210: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80802324_chcollballcontrol(rdram, ctx);
        goto after_1;
    // 0x80802210: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80802214: jal         0x80802A50
    // 0x80802218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802A50_chcollballcontrol(rdram, ctx);
        goto after_2;
    // 0x80802218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080221C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1840, 0X4C64) << 16);
    // 0x80802220: addiu       $a2, $a2, 0x4C64
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1840, 0X4C64));
    // 0x80802224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802228: jal         0x80089D18
    // 0x8080222C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x8080222C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80802230: jal         0x80089CA8
    // 0x80802234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80802234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80802238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080223C: jal         0x80801764
    // 0x80802240: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80801764_chcollballcontrol(rdram, ctx);
        goto after_5;
    // 0x80802240: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x80802244: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80802248: jal         0x80800BF0
    // 0x8080224C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80800BF0_chcollballcontrol(rdram, ctx);
        goto after_6;
    // 0x8080224C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80802250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802254:
    // 0x80802254: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802258: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080225C: jr          $ra
    // 0x80802260: nop

    return;
    // 0x80802260: nop

;}
RECOMP_FUNC void func_800A328C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A328C: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3290: jr          $ra
    // 0x800A3294: lwc1        $f0, 0x48($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X48);
    return;
    // 0x800A3294: lwc1        $f0, 0x48($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X48);
;}
RECOMP_FUNC void func_80800D80_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D80: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800D84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D90: jal         0x8008E35C
    // 0x80800D94: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    player_inWater(rdram, ctx);
        goto after_0;
    // 0x80800D94: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800D98: beq         $v0, $zero, L_80800DA4
    if (ctx->r2 == 0) {
        // 0x80800D9C: addiu       $t6, $zero, 0x4C
        ctx->r14 = ADD32(0, 0X4C);
            goto L_80800DA4;
    }
    // 0x80800D9C: addiu       $t6, $zero, 0x4C
    ctx->r14 = ADD32(0, 0X4C);
    // 0x80800DA0: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
L_80800DA4:
    // 0x80800DA4: jal         0x8008E078
    // 0x80800DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_1;
    // 0x80800DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800DAC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800DB0: jal         0x8009650C
    // 0x80800DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009650C(rdram, ctx);
        goto after_2;
    // 0x80800DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800DB8: bne         $v0, $zero, L_80800DD0
    if (ctx->r2 != 0) {
        // 0x80800DBC: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80800DD0;
    }
    // 0x80800DBC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800DC0: bnel        $t7, $zero, L_80800DD4
    if (ctx->r15 != 0) {
        // 0x80800DC4: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_80800DD4;
    }
    goto skip_0;
    // 0x80800DC4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800DC8: b           L_80800EFC
    // 0x80800DCC: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
        goto L_80800EFC;
    // 0x80800DCC: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_80800DD0:
    // 0x80800DD0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_80800DD4:
    // 0x80800DD4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DDC: beq         $t8, $zero, L_80800DFC
    if (ctx->r24 == 0) {
        // 0x80800DE0: nop
    
            goto L_80800DFC;
    }
    // 0x80800DE0: nop

    // 0x80800DE4: jal         0x800963C0
    // 0x80800DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800963C0(rdram, ctx);
        goto after_3;
    // 0x80800DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800DEC: jal         0x80096628
    // 0x80800DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096628(rdram, ctx);
        goto after_4;
    // 0x80800DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800DF4: b           L_80800E10
    // 0x80800DF8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_80800E10;
    // 0x80800DF8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80800DFC:
    // 0x80800DFC: jal         0x80096440
    // 0x80800E00: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80096440(rdram, ctx);
        goto after_5;
    // 0x80800E00: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_5:
    // 0x80800E04: jal         0x80096434
    // 0x80800E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096434(rdram, ctx);
        goto after_6;
    // 0x80800E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800E0C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80800E10:
    // 0x80800E10: lw          $a1, 0x188($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X188);
    // 0x80800E14: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800E18: jal         0x800EE7F8
    // 0x80800E1C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80800E1C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_7:
    // 0x80800E20: jal         0x800EF2A0
    // 0x80800E24: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EF2A0(rdram, ctx);
        goto after_8;
    // 0x80800E24: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_8:
    // 0x80800E28: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800E2C: jal         0x800EEAA4
    // 0x80800E30: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EEAA4(rdram, ctx);
        goto after_9;
    // 0x80800E30: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_9:
    // 0x80800E34: jal         0x800F2100
    // 0x80800E38: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_10;
    // 0x80800E38: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_10:
    // 0x80800E3C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80800E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E44: jal         0x80095738
    // 0x80800E48: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    baflag_isTrue(rdram, ctx);
        goto after_11;
    // 0x80800E48: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_11:
    // 0x80800E4C: bne         $v0, $zero, L_80800E60
    if (ctx->r2 != 0) {
        // 0x80800E50: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_80800E60;
    }
    // 0x80800E50: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800E54: andi        $t0, $t9, 0x80
    ctx->r8 = ctx->r25 & 0X80;
    // 0x80800E58: beq         $t0, $zero, L_80800E74
    if (ctx->r8 == 0) {
        // 0x80800E5C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(96, 0X1D04) << 16);
            goto L_80800E74;
    }
    // 0x80800E5C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(96, 0X1D04) << 16);
L_80800E60:
    // 0x80800E60: jal         0x808009D0
    // 0x80800E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009D0_bsbfly(rdram, ctx);
        goto after_12;
    // 0x80800E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800E68: addiu       $t1, $zero, 0x18
    ctx->r9 = ADD32(0, 0X18);
    // 0x80800E6C: b           L_80800EF8
    // 0x80800E70: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
        goto L_80800EF8;
    // 0x80800E70: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
L_80800E74:
    // 0x80800E74: lwc1        $f4, 0x1D04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(96, 0X1D04));
    // 0x80800E78: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800E7C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(96, 0X1D08) << 16);
    // 0x80800E80: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800E84: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800E88: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80800E8C: bc1f        L_80800EEC
    if (!c1cs) {
        // 0x80800E90: nop
    
            goto L_80800EEC;
    }
    // 0x80800E90: nop

    // 0x80800E94: lwc1        $f10, 0x1D08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(96, 0X1D08));
    // 0x80800E98: addiu       $t4, $zero, 0x58
    ctx->r12 = ADD32(0, 0X58);
    // 0x80800E9C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800EA0: nop

    // 0x80800EA4: bc1f        L_80800EE4
    if (!c1cs) {
        // 0x80800EA8: nop
    
            goto L_80800EE4;
    }
    // 0x80800EA8: nop

    // 0x80800EAC: jal         0x808009D0
    // 0x80800EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009D0_bsbfly(rdram, ctx);
        goto after_13;
    // 0x80800EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EB8: jal         0x800A17A8
    // 0x80800EBC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800A17A8(rdram, ctx);
        goto after_14;
    // 0x80800EBC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_14:
    // 0x80800EC0: jal         0x800A1718
    // 0x80800EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_15;
    // 0x80800EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800EC8: beq         $v0, $zero, L_80800EDC
    if (ctx->r2 == 0) {
        // 0x80800ECC: addiu       $t3, $zero, 0x41
        ctx->r11 = ADD32(0, 0X41);
            goto L_80800EDC;
    }
    // 0x80800ECC: addiu       $t3, $zero, 0x41
    ctx->r11 = ADD32(0, 0X41);
    // 0x80800ED0: addiu       $t2, $zero, 0x59
    ctx->r10 = ADD32(0, 0X59);
    // 0x80800ED4: b           L_80800EF8
    // 0x80800ED8: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
        goto L_80800EF8;
    // 0x80800ED8: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
L_80800EDC:
    // 0x80800EDC: b           L_80800EF8
    // 0x80800EE0: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
        goto L_80800EF8;
    // 0x80800EE0: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
L_80800EE4:
    // 0x80800EE4: b           L_80800EF8
    // 0x80800EE8: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
        goto L_80800EF8;
    // 0x80800EE8: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
L_80800EEC:
    // 0x80800EEC: beq         $t5, $zero, L_80800EF8
    if (ctx->r13 == 0) {
        // 0x80800EF0: addiu       $t6, $zero, 0x58
        ctx->r14 = ADD32(0, 0X58);
            goto L_80800EF8;
    }
    // 0x80800EF0: addiu       $t6, $zero, 0x58
    ctx->r14 = ADD32(0, 0X58);
    // 0x80800EF4: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
L_80800EF8:
    // 0x80800EF8: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_80800EFC:
    // 0x80800EFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F04: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800F08: jr          $ra
    // 0x80800F0C: nop

    return;
    // 0x80800F0C: nop

;}
RECOMP_FUNC void func_800DA0B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA0B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DA0B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DA0BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800DA0C0: jal         0x800DA054
    // 0x800DA0C4: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    func_800DA054(rdram, ctx);
        goto after_0;
    // 0x800DA0C4: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    after_0:
    // 0x800DA0C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DA0CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DA0D0: jr          $ra
    // 0x800DA0D4: nop

    return;
    // 0x800DA0D4: nop

;}
RECOMP_FUNC void func_80800A2C_chflysaucercrate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800A38: jal         0x80102B2C
    // 0x80800A3C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102B2C(rdram, ctx);
        goto after_0;
    // 0x80800A3C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_0:
    // 0x80800A40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800A44: jal         0x80102B6C
    // 0x80800A48: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102B6C(rdram, ctx);
        goto after_1;
    // 0x80800A48: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_1:
    // 0x80800A4C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80800A50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800A54: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCD4) << 16);
    // 0x80800A58: lwc1        $f0, 0x4C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x80800A5C: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x80800A60: nop

    // 0x80800A64: bc1tl       L_80800A7C
    if (c1cs) {
        // 0x80800A68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800A7C;
    }
    goto skip_0;
    // 0x80800A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800A6C: lwc1        $f6, 0xCD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCD4));
    // 0x80800A70: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800A74: swc1        $f8, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f8.u32l;
    // 0x80800A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A7C:
    // 0x80800A7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A80: jr          $ra
    // 0x80800A84: nop

    return;
    // 0x80800A84: nop

;}
RECOMP_FUNC void bafly_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C04: jal         0x8009BC6C
    // 0x80800C08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x80800C08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C0C: jal         0x8008E95C
    // 0x80800C10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E95C(rdram, ctx);
        goto after_1;
    // 0x80800C10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C1C: jr          $ra
    // 0x80800C20: nop

    return;
    // 0x80800C20: nop

;}
RECOMP_FUNC void func_80801728_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801728: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080172C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801730: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801734: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801738: jal         0x800DA298
    // 0x8080173C: addiu       $a0, $zero, 0x343
    ctx->r4 = ADD32(0, 0X343);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080173C: addiu       $a0, $zero, 0x343
    ctx->r4 = ADD32(0, 0X343);
    after_0:
    // 0x80801740: bne         $v0, $zero, L_808017A0
    if (ctx->r2 != 0) {
        // 0x80801744: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_808017A0;
    }
    // 0x80801744: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801748: addiu       $a1, $zero, 0x2EE
    ctx->r5 = ADD32(0, 0X2EE);
    // 0x8080174C: jal         0x8010CA74
    // 0x80801750: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8010CA74(rdram, ctx);
        goto after_1;
    // 0x80801750: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x80801754: beql        $v0, $zero, L_808017A4
    if (ctx->r2 == 0) {
        // 0x80801758: lw          $t9, 0x74($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X74);
            goto L_808017A4;
    }
    goto skip_0;
    // 0x80801758: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    skip_0:
    // 0x8080175C: jal         0x80800480
    // 0x80801760: nop

    func_80800480_chfactorybattery(rdram, ctx);
        goto after_2;
    // 0x80801760: nop

    after_2:
    // 0x80801764: jal         0x800DA298
    // 0x80801768: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80801768: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8080176C: bnel        $v0, $zero, L_808017A4
    if (ctx->r2 != 0) {
        // 0x80801770: lw          $t9, 0x74($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X74);
            goto L_808017A4;
    }
    goto skip_1;
    // 0x80801770: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    skip_1:
    // 0x80801774: jal         0x800DA544
    // 0x80801778: addiu       $a0, $zero, 0x343
    ctx->r4 = ADD32(0, 0X343);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x80801778: addiu       $a0, $zero, 0x343
    ctx->r4 = ADD32(0, 0X343);
    after_4:
    // 0x8080177C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801780: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801784: addiu       $a1, $zero, 0x1352
    ctx->r5 = ADD32(0, 0X1352);
    // 0x80801788: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8080178C: jal         0x8008A208
    // 0x80801790: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80801790: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80801794: lbu         $t7, 0x74($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X74);
    // 0x80801798: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x8080179C: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
L_808017A0:
    // 0x808017A0: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
L_808017A4:
    // 0x808017A4: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x808017A8: bltz        $t1, L_808017E8
    if (SIGNED(ctx->r9) < 0) {
        // 0x808017AC: nop
    
            goto L_808017E8;
    }
    // 0x808017AC: nop

    // 0x808017B0: jal         0x80800480
    // 0x808017B4: nop

    func_80800480_chfactorybattery(rdram, ctx);
        goto after_6;
    // 0x808017B4: nop

    after_6:
    // 0x808017B8: jal         0x800DA298
    // 0x808017BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808017BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x808017C0: beq         $v0, $zero, L_808017E8
    if (ctx->r2 == 0) {
        // 0x808017C4: addiu       $a1, $zero, 0x1353
        ctx->r5 = ADD32(0, 0X1353);
            goto L_808017E8;
    }
    // 0x808017C4: addiu       $a1, $zero, 0x1353
    ctx->r5 = ADD32(0, 0X1353);
    // 0x808017C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808017CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808017D0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808017D4: jal         0x8008A208
    // 0x808017D8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x808017D8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x808017DC: lbu         $t3, 0x74($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X74);
    // 0x808017E0: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x808017E4: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
L_808017E8:
    // 0x808017E8: jal         0x80086240
    // 0x808017EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdoor_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x808017EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808017F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808017F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808017F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808017FC: jr          $ra
    // 0x80801800: nop

    return;
    // 0x80801800: nop

;}
RECOMP_FUNC void func_80800164_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800164: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080016C: jal         0x8009EF1C
    // 0x80800170: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x80800170: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800174: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800178: jal         0x8009EF10
    // 0x8080017C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x8080017C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800180: bne         $v0, $zero, L_8080019C
    if (ctx->r2 != 0) {
        // 0x80800184: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_8080019C;
    }
    // 0x80800184: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800188: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080018C: jal         0x8009B9B0
    // 0x80800190: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800190: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800194: b           L_808001BC
    // 0x80800198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808001BC;
    // 0x80800198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080019C:
    // 0x8080019C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808001A0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001A4: jal         0x800F1214
    // 0x808001A8: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x808001A8: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    after_3:
    // 0x808001AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001B0: jal         0x8009B9B0
    // 0x808001B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x808001B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808001B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001BC:
    // 0x808001BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001C0: jr          $ra
    // 0x808001C4: nop

    return;
    // 0x808001C4: nop

;}
RECOMP_FUNC void func_808005D0_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005D8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1300, 0XF20) << 16);
    // 0x808005DC: lui         $a3, 0x3DA3
    ctx->r7 = S32(0X3DA3 << 16);
    // 0x808005E0: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x808005E4: addiu       $a2, $a2, 0xF20
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1300, 0XF20));
    // 0x808005E8: jal         0x80089D20
    // 0x808005EC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808005EC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x808005F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005F8: jr          $ra
    // 0x808005FC: nop

    return;
    // 0x808005FC: nop

;}
RECOMP_FUNC void _chstarspinnerctrl_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E08: syscall     245
    recomp_syscall_handler(rdram, ctx, 0x80085E08);
    return;
    // 0x80085E0C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080000C_chdiggerbossbattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080001C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800020: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800024: jal         0x800EE7F8
    // 0x80800028: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x8080002C: jal         0x800EFD24
    // 0x80800030: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x80800030: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800038: jal         0x80102FDC
    // 0x8080003C: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_80102FDC(rdram, ctx);
        goto after_2;
    // 0x8080003C: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_2:
    // 0x80800040: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800044: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800048: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8080004C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800050: jal         0x800DC178
    // 0x80800054: nop

    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800054: nop

    after_3:
    // 0x80800058: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x8080005C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800060: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x80800064: jal         0x800DA298
    // 0x80800068: addiu       $a0, $t6, 0xA1D
    ctx->r4 = ADD32(ctx->r14, 0XA1D);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800068: addiu       $a0, $t6, 0xA1D
    ctx->r4 = ADD32(ctx->r14, 0XA1D);
    after_4:
    // 0x8080006C: beql        $v0, $zero, L_80800080
    if (ctx->r2 == 0) {
        // 0x80800070: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800080;
    }
    goto skip_0;
    // 0x80800070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800074: jal         0x800FFAB0
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080007C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800080:
    // 0x80800080: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800084: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void func_80800534_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800534: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800538: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080053C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800540: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800544: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800548: jal         0x80800934
    // 0x8080054C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80800934_chtiptup(rdram, ctx);
        goto after_0;
    // 0x8080054C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_0:
    // 0x80800550: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80800554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800558: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080055C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800560: jal         0x800D1000
    // 0x80800564: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_1;
    // 0x80800564: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80800568: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080056C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800570: jr          $ra
    // 0x80800574: nop

    return;
    // 0x80800574: nop

;}
RECOMP_FUNC void func_80801638_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080163C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801640: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80801644: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80801648: bgezl       $t8, L_80801690
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080164C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801690;
    }
    goto skip_0;
    // 0x8080164C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801650: beq         $a1, $zero, L_80801674
    if (ctx->r5 == 0) {
        // 0x80801654: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80801674;
    }
    // 0x80801654: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801658: jal         0x808014D8
    // 0x8080165C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808014D8_chhandcart(rdram, ctx);
        goto after_0;
    // 0x8080165C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801660: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801664: jal         0x808014D8
    // 0x80801668: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808014D8_chhandcart(rdram, ctx);
        goto after_1;
    // 0x80801668: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080166C: b           L_80801690
    // 0x80801670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801690;
    // 0x80801670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801674:
    // 0x80801674: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801678: jal         0x808014D8
    // 0x8080167C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808014D8_chhandcart(rdram, ctx);
        goto after_2;
    // 0x8080167C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80801680: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801684: jal         0x808014D8
    // 0x80801688: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808014D8_chhandcart(rdram, ctx);
        goto after_3;
    // 0x80801688: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x8080168C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801690:
    // 0x80801690: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801694: jr          $ra
    // 0x80801698: nop

    return;
    // 0x80801698: nop

;}
RECOMP_FUNC void capod_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    if (tooie_test_room_quiet()) { ctx->r2 = 0; return; }
    // 0x808001F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001FC: jal         0x8008FFE8
    // 0x80800200: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x80800200: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800204: beq         $v0, $zero, L_80800218
    if (ctx->r2 == 0) {
        // 0x80800208: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800218;
    }
    // 0x80800208: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080020C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800210: jal         0x80089568
    // 0x80800214: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    _ncpod_entrypoint_21(rdram, ctx);
        goto after_1;
    // 0x80800214: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_80800218:
    // 0x80800218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080021C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800220: jr          $ra
    // 0x80800224: nop

    return;
    // 0x80800224: nop

;}
RECOMP_FUNC void func_80808678_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808678: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080867C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80808680: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80808684: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80808688: jal         0x808086B0
    // 0x8080868C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808086B0_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x8080868C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80808690: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x80808694: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80808698: jal         0x8080633C
    // 0x8080869C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080633C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x8080869C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808086A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808086A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808086A8: jr          $ra
    // 0x808086AC: nop

    return;
    // 0x808086AC: nop

;}
RECOMP_FUNC void func_80800020_inantab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x3C8
    ctx->r29 = ADD32(ctx->r29, -0X3C8);
    // 0x80800024: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x80800028: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8080002C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80800030: sw          $a2, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r6;
    // 0x80800034: sltiu       $at, $t6, 0x6B
    ctx->r1 = ctx->r14 < 0X6B ? 1 : 0;
    // 0x80800038: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8080003C: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80800040: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80800048: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8080004C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800050: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800054: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800058: beq         $at, $zero, L_80805788
    if (ctx->r1 == 0) {
        // 0x8080005C: sw          $a2, 0x3D0($sp)
        MEM_W(0X3D0, ctx->r29) = ctx->r6;
            goto L_80805788;
    }
    // 0x8080005C: sw          $a2, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r6;
    // 0x80800060: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800064: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6740) << 16);
    // 0x80800068: addu        $at, $at, $t6
    gpr jr_addend_80800070 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080006C: lw          $t6, 0x6740($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6740));
    // 0x80800070: jr          $t6
    // 0x80800074: nop

    switch (jr_addend_80800070 >> 2) {
        case 0: goto L_80800078; break;
        case 1: goto L_80805790; break;
        case 2: goto L_80805790; break;
        case 3: goto L_80805790; break;
        case 4: goto L_80805790; break;
        case 5: goto L_80805790; break;
        case 6: goto L_80800D4C; break;
        case 7: goto L_80800DA8; break;
        case 8: goto L_80800EAC; break;
        case 9: goto L_80801C58; break;
        case 10: goto L_80801CF0; break;
        case 11: goto L_80802400; break;
        case 12: goto L_80802F2C; break;
        case 13: goto L_808031C8; break;
        case 14: goto L_80803270; break;
        case 15: goto L_80803DFC; break;
        case 16: goto L_80803F7C; break;
        case 17: goto L_80804098; break;
        case 18: goto L_808041D8; break;
        case 19: goto L_80804204; break;
        case 20: goto L_80804230; break;
        case 21: goto L_808042D8; break;
        case 22: goto L_808043F0; break;
        case 23: goto L_80804F7C; break;
        case 24: goto L_80801CB4; break;
        case 25: goto L_80804114; break;
        case 26: goto L_80804FD8; break;
        case 27: goto L_80805328; break;
        case 28: goto L_80802670; break;
        case 29: goto L_80802824; break;
        case 30: goto L_80805470; break;
        case 31: goto L_80805510; break;
        case 32: goto L_80805558; break;
        case 33: goto L_808055A0; break;
        case 34: goto L_80805660; break;
        case 35: goto L_808056A8; break;
        case 36: goto L_80805788; break;
        case 37: goto L_80805788; break;
        case 38: goto L_80805788; break;
        case 39: goto L_80805034; break;
        case 40: goto L_80805070; break;
        case 41: goto L_808050CC; break;
        case 42: goto L_80800914; break;
        case 43: goto L_8080096C; break;
        case 44: goto L_808009C4; break;
        case 45: goto L_80800A1C; break;
        case 46: goto L_80800A74; break;
        case 47: goto L_80800ACC; break;
        case 48: goto L_80800B2C; break;
        case 49: goto L_80800B8C; break;
        case 50: goto L_80800BEC; break;
        case 51: goto L_80801DD8; break;
        case 52: goto L_80801EC0; break;
        case 53: goto L_80802090; break;
        case 54: goto L_80805788; break;
        case 55: goto L_80801FA8; break;
        case 56: goto L_80805790; break;
        case 57: goto L_80805108; break;
        case 58: goto L_80805144; break;
        case 59: goto L_80805180; break;
        case 60: goto L_808051BC; break;
        case 61: goto L_808051F8; break;
        case 62: goto L_80805788; break;
        case 63: goto L_80805788; break;
        case 64: goto L_80805788; break;
        case 65: goto L_80805788; break;
        case 66: goto L_80805788; break;
        case 67: goto L_80805234; break;
        case 68: goto L_80805270; break;
        case 69: goto L_808052CC; break;
        case 70: goto L_80805788; break;
        case 71: goto L_80805788; break;
        case 72: goto L_80805788; break;
        case 73: goto L_80802C9C; break;
        case 74: goto L_80802D78; break;
        case 75: goto L_80805788; break;
        case 76: goto L_80805788; break;
        case 77: goto L_80805788; break;
        case 78: goto L_80805788; break;
        case 79: goto L_80805788; break;
        case 80: goto L_80804288; break;
        case 81: goto L_808042B0; break;
        case 82: goto L_80802E54; break;
        case 83: goto L_80805788; break;
        case 84: goto L_80805788; break;
        case 85: goto L_808029D8; break;
        case 86: goto L_80802B34; break;
        case 87: goto L_80805384; break;
        case 88: goto L_80802A6C; break;
        case 89: goto L_80800C4C; break;
        case 90: goto L_80800CDC; break;
        case 91: goto L_80802494; break;
        case 92: goto L_80802520; break;
        case 93: goto L_808053E0; break;
        case 94: goto L_80805428; break;
        case 95: goto L_808031F4; break;
        case 96: goto L_80805788; break;
        case 97: goto L_80802170; break;
        case 98: goto L_8080321C; break;
        case 99: goto L_80802BC0; break;
        case 100: goto L_80802E84; break;
        case 101: goto L_80802EE0; break;
        case 102: goto L_80805788; break;
        case 103: goto L_80805788; break;
        case 104: goto L_80805788; break;
        case 105: goto L_80802250; break;
        case 106: goto L_80802328; break;
        default: switch_error(__func__, 0x80800070, 0x80806740);
    }
    // 0x80800074: nop

L_80800078:
    // 0x80800078: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F80) << 16);
    // 0x8080007C: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80800080: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X6F8C) << 16);
    // 0x80800084: addiu       $s1, $s1, 0x6F8C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X6F8C));
    // 0x80800088: addiu       $s0, $s0, -0x330
    ctx->r16 = ADD32(ctx->r16, -0X330);
    // 0x8080008C: addiu       $v0, $v0, 0x6F80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F80));
    // 0x80800090: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80800094:
    // 0x80800094: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800098: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080009C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808000A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808000A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808000A8: jal         0x80082628
    // 0x808000AC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808000AC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_0:
    // 0x808000B0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808000B4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808000B8: bnel        $v0, $s1, L_80800094
    if (ctx->r2 != ctx->r17) {
        // 0x808000BC: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80800094;
    }
    goto skip_0;
    // 0x808000BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_0:
    // 0x808000C0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F8C) << 16);
    // 0x808000C4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X6F98) << 16);
    // 0x808000C8: addiu       $s1, $s1, 0x6F98
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X6F98));
    // 0x808000CC: addiu       $v0, $v0, 0x6F8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F8C));
    // 0x808000D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808000D4:
    // 0x808000D4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808000D8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808000DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808000E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808000E4: jal         0x80082628
    // 0x808000E8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808000E8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_1:
    // 0x808000EC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808000F0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808000F4: bnel        $v0, $s1, L_808000D4
    if (ctx->r2 != ctx->r17) {
        // 0x808000F8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808000D4;
    }
    goto skip_1;
    // 0x808000F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x808000FC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F80) << 16);
    // 0x80800100: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X6F8C) << 16);
    // 0x80800104: addiu       $s1, $s1, 0x6F8C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X6F8C));
    // 0x80800108: addiu       $v0, $v0, 0x6F80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F80));
    // 0x8080010C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_80800110:
    // 0x80800110: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800114: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800118: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080011C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800120: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80800124: jal         0x80082628
    // 0x80800128: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800128: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_2:
    // 0x8080012C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800130: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800134: bnel        $v0, $s1, L_80800110
    if (ctx->r2 != ctx->r17) {
        // 0x80800138: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80800110;
    }
    goto skip_2;
    // 0x80800138: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    skip_2:
    // 0x8080013C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F8C) << 16);
    // 0x80800140: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X6F98) << 16);
    // 0x80800144: addiu       $s1, $s1, 0x6F98
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X6F98));
    // 0x80800148: addiu       $v0, $v0, 0x6F8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F8C));
    // 0x8080014C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800150:
    // 0x80800150: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800154: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800158: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8080015C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800160: jal         0x80082628
    // 0x80800164: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800164: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800168: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080016C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800170: bnel        $v0, $s1, L_80800150
    if (ctx->r2 != ctx->r17) {
        // 0x80800174: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800150;
    }
    goto skip_3;
    // 0x80800174: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_3:
    // 0x80800178: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F80) << 16);
    // 0x8080017C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X6F8C) << 16);
    // 0x80800180: addiu       $s1, $s1, 0x6F8C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X6F8C));
    // 0x80800184: addiu       $v0, $v0, 0x6F80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F80));
    // 0x80800188: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_8080018C:
    // 0x8080018C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800190: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800194: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800198: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080019C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808001A0: jal         0x80082628
    // 0x808001A4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808001A4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_4:
    // 0x808001A8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808001AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808001B0: bnel        $v0, $s1, L_8080018C
    if (ctx->r2 != ctx->r17) {
        // 0x808001B4: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8080018C;
    }
    goto skip_4;
    // 0x808001B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    skip_4:
    // 0x808001B8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F8C) << 16);
    // 0x808001BC: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X6F98) << 16);
    // 0x808001C0: addiu       $s1, $s1, 0x6F98
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X6F98));
    // 0x808001C4: addiu       $v0, $v0, 0x6F8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F8C));
    // 0x808001C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808001CC:
    // 0x808001CC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808001D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808001D4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808001D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808001DC: jal         0x80082628
    // 0x808001E0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x808001E0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_5:
    // 0x808001E4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808001E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808001EC: bnel        $v0, $s1, L_808001CC
    if (ctx->r2 != ctx->r17) {
        // 0x808001F0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808001CC;
    }
    goto skip_5;
    // 0x808001F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_5:
    // 0x808001F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F98) << 16);
    // 0x808001F8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X6FA4) << 16);
    // 0x808001FC: addiu       $s1, $s1, 0x6FA4
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X6FA4));
    // 0x80800200: addiu       $v0, $v0, 0x6F98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F98));
    // 0x80800204: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80800208:
    // 0x80800208: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8080020C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800210: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800214: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800218: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8080021C: jal         0x80082628
    // 0x80800220: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800220: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_6:
    // 0x80800224: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800228: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080022C: bnel        $v0, $s1, L_80800208
    if (ctx->r2 != ctx->r17) {
        // 0x80800230: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80800208;
    }
    goto skip_6;
    // 0x80800230: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    skip_6:
    // 0x80800234: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6FA4) << 16);
    // 0x80800238: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X6FB0) << 16);
    // 0x8080023C: addiu       $s1, $s1, 0x6FB0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X6FB0));
    // 0x80800240: addiu       $v0, $v0, 0x6FA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6FA4));
    // 0x80800244: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800248:
    // 0x80800248: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080024C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800250: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80800254: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800258: jal         0x80082628
    // 0x8080025C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x8080025C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_7:
    // 0x80800260: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800264: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800268: bnel        $v0, $s1, L_80800248
    if (ctx->r2 != ctx->r17) {
        // 0x8080026C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800248;
    }
    goto skip_7;
    // 0x8080026C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_7:
    // 0x80800270: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F98) << 16);
    // 0x80800274: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X6FA4) << 16);
    // 0x80800278: addiu       $s1, $s1, 0x6FA4
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X6FA4));
    // 0x8080027C: addiu       $v0, $v0, 0x6F98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F98));
    // 0x80800280: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80800284:
    // 0x80800284: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800288: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080028C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800290: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800294: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80800298: jal         0x80082628
    // 0x8080029C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x8080029C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_8:
    // 0x808002A0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808002A4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808002A8: bnel        $v0, $s1, L_80800284
    if (ctx->r2 != ctx->r17) {
        // 0x808002AC: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80800284;
    }
    goto skip_8;
    // 0x808002AC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_8:
    // 0x808002B0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6FA4) << 16);
    // 0x808002B4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X6FB0) << 16);
    // 0x808002B8: addiu       $s1, $s1, 0x6FB0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X6FB0));
    // 0x808002BC: addiu       $v0, $v0, 0x6FA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6FA4));
    // 0x808002C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808002C4:
    // 0x808002C4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808002C8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808002CC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x808002D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808002D4: jal         0x80082628
    // 0x808002D8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x808002D8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_9:
    // 0x808002DC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808002E0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808002E4: bnel        $v0, $s1, L_808002C4
    if (ctx->r2 != ctx->r17) {
        // 0x808002E8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808002C4;
    }
    goto skip_9;
    // 0x808002E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_9:
    // 0x808002EC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F98) << 16);
    // 0x808002F0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X6FA4) << 16);
    // 0x808002F4: addiu       $s1, $s1, 0x6FA4
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X6FA4));
    // 0x808002F8: addiu       $v0, $v0, 0x6F98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F98));
    // 0x808002FC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80800300:
    // 0x80800300: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800304: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800308: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080030C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800310: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80800314: jal         0x80082628
    // 0x80800318: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800318: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_10:
    // 0x8080031C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800320: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800324: bnel        $v0, $s1, L_80800300
    if (ctx->r2 != ctx->r17) {
        // 0x80800328: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80800300;
    }
    goto skip_10;
    // 0x80800328: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_10:
    // 0x8080032C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6FA4) << 16);
    // 0x80800330: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X6FB0) << 16);
    // 0x80800334: addiu       $s1, $s1, 0x6FB0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X6FB0));
    // 0x80800338: addiu       $v0, $v0, 0x6FA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6FA4));
    // 0x8080033C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800340:
    // 0x80800340: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800344: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800348: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x8080034C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800350: jal         0x80082628
    // 0x80800354: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800354: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_11:
    // 0x80800358: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080035C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800360: bnel        $v0, $s1, L_80800340
    if (ctx->r2 != ctx->r17) {
        // 0x80800364: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800340;
    }
    goto skip_11;
    // 0x80800364: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_11:
    // 0x80800368: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F80) << 16);
    // 0x8080036C: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x80800370: lui         $s4, 0x7CCB
    ctx->r20 = S32(0X7CCB << 16);
    // 0x80800374: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X6F8C) << 16);
    // 0x80800378: addiu       $s3, $s3, 0x6F8C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X6F8C));
    // 0x8080037C: ori         $s4, $s4, 0xFF00
    ctx->r20 = ctx->r20 | 0XFF00;
    // 0x80800380: addiu       $s1, $s1, -0x7078
    ctx->r17 = ADD32(ctx->r17, -0X7078);
    // 0x80800384: addiu       $v0, $v0, 0x6F80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F80));
    // 0x80800388: lui         $s0, 0x1
    ctx->r16 = S32(0X1 << 16);
    // 0x8080038C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800390:
    // 0x80800390: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800394: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800398: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8080039C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x808003A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808003A4: jal         0x80082630
    // 0x808003A8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x808003A8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_12:
    // 0x808003AC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808003B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808003B4: bnel        $v0, $s3, L_80800390
    if (ctx->r2 != ctx->r19) {
        // 0x808003B8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800390;
    }
    goto skip_12;
    // 0x808003B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_12:
    // 0x808003BC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F8C) << 16);
    // 0x808003C0: lui         $s3, 0x6D87
    ctx->r19 = S32(0X6D87 << 16);
    // 0x808003C4: ori         $s3, $s3, 0xFF00
    ctx->r19 = ctx->r19 | 0XFF00;
    // 0x808003C8: addiu       $v0, $v0, 0x6F8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F8C));
    // 0x808003CC: addiu       $t3, $zero, 0x19
    ctx->r11 = ADD32(0, 0X19);
L_808003D0:
    // 0x808003D0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808003D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808003D8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808003DC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808003E0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808003E4: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x808003E8: jal         0x80082630
    // 0x808003EC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x808003EC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_13:
    // 0x808003F0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808003F4: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2958, 0X6F98) << 16);
    // 0x808003F8: addiu       $t4, $t4, 0x6F98
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2958, 0X6F98));
    // 0x808003FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800400: bnel        $v0, $t4, L_808003D0
    if (ctx->r2 != ctx->r12) {
        // 0x80800404: addiu       $t3, $zero, 0x19
        ctx->r11 = ADD32(0, 0X19);
            goto L_808003D0;
    }
    goto skip_13;
    // 0x80800404: addiu       $t3, $zero, 0x19
    ctx->r11 = ADD32(0, 0X19);
    skip_13:
    // 0x80800408: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F98) << 16);
    // 0x8080040C: addiu       $v0, $v0, 0x6F98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F98));
    // 0x80800410: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800414:
    // 0x80800414: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800418: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8080041C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80800420: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80800424: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800428: jal         0x80082630
    // 0x8080042C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_14;
    // 0x8080042C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_14:
    // 0x80800430: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800434: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2958, 0X6FA4) << 16);
    // 0x80800438: addiu       $t5, $t5, 0x6FA4
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2958, 0X6FA4));
    // 0x8080043C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800440: bnel        $v0, $t5, L_80800414
    if (ctx->r2 != ctx->r13) {
        // 0x80800444: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800414;
    }
    goto skip_14;
    // 0x80800444: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_14:
    // 0x80800448: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6FA4) << 16);
    // 0x8080044C: addiu       $v0, $v0, 0x6FA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6FA4));
    // 0x80800450: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
L_80800454:
    // 0x80800454: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800458: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080045C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800460: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800464: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80800468: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8080046C: jal         0x80082630
    // 0x80800470: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x80800470: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_15:
    // 0x80800474: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800478: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2958, 0X6FB0) << 16);
    // 0x8080047C: addiu       $t7, $t7, 0x6FB0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2958, 0X6FB0));
    // 0x80800480: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800484: bnel        $v0, $t7, L_80800454
    if (ctx->r2 != ctx->r15) {
        // 0x80800488: addiu       $t6, $zero, 0x19
        ctx->r14 = ADD32(0, 0X19);
            goto L_80800454;
    }
    goto skip_15;
    // 0x80800488: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    skip_15:
    // 0x8080048C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F80) << 16);
    // 0x80800490: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X6F8C) << 16);
    // 0x80800494: addiu       $s3, $s3, 0x6F8C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X6F8C));
    // 0x80800498: addiu       $v0, $v0, 0x6F80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F80));
    // 0x8080049C: lui         $s0, 0x2
    ctx->r16 = S32(0X2 << 16);
    // 0x808004A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808004A4:
    // 0x808004A4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808004A8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808004AC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808004B0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x808004B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808004B8: jal         0x80082630
    // 0x808004BC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x808004BC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_16:
    // 0x808004C0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808004C4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808004C8: bnel        $v0, $s3, L_808004A4
    if (ctx->r2 != ctx->r19) {
        // 0x808004CC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808004A4;
    }
    goto skip_16;
    // 0x808004CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_16:
    // 0x808004D0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F8C) << 16);
    // 0x808004D4: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X6F98) << 16);
    // 0x808004D8: addiu       $s3, $s3, 0x6F98
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X6F98));
    // 0x808004DC: addiu       $v0, $v0, 0x6F8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F8C));
    // 0x808004E0: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
L_808004E4:
    // 0x808004E4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808004E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808004EC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808004F0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808004F4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808004F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808004FC: jal         0x80082630
    // 0x80800500: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_17;
    // 0x80800500: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_17:
    // 0x80800504: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800508: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080050C: bnel        $v0, $s3, L_808004E4
    if (ctx->r2 != ctx->r19) {
        // 0x80800510: addiu       $t8, $zero, 0x19
        ctx->r24 = ADD32(0, 0X19);
            goto L_808004E4;
    }
    goto skip_17;
    // 0x80800510: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
    skip_17:
    // 0x80800514: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F98) << 16);
    // 0x80800518: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X6FA4) << 16);
    // 0x8080051C: addiu       $s3, $s3, 0x6FA4
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X6FA4));
    // 0x80800520: addiu       $v0, $v0, 0x6F98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F98));
    // 0x80800524: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800528:
    // 0x80800528: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080052C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800530: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80800534: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80800538: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8080053C: jal         0x80082630
    // 0x80800540: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_18;
    // 0x80800540: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_18:
    // 0x80800544: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800548: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080054C: bnel        $v0, $s3, L_80800528
    if (ctx->r2 != ctx->r19) {
        // 0x80800550: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800528;
    }
    goto skip_18;
    // 0x80800550: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_18:
    // 0x80800554: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6FA4) << 16);
    // 0x80800558: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X6FB0) << 16);
    // 0x8080055C: addiu       $s3, $s3, 0x6FB0
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X6FB0));
    // 0x80800560: addiu       $v0, $v0, 0x6FA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6FA4));
    // 0x80800564: addiu       $t9, $zero, 0x19
    ctx->r25 = ADD32(0, 0X19);
L_80800568:
    // 0x80800568: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8080056C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800570: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800574: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800578: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8080057C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800580: jal         0x80082630
    // 0x80800584: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_19;
    // 0x80800584: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_19:
    // 0x80800588: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080058C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800590: bnel        $v0, $s3, L_80800568
    if (ctx->r2 != ctx->r19) {
        // 0x80800594: addiu       $t9, $zero, 0x19
        ctx->r25 = ADD32(0, 0X19);
            goto L_80800568;
    }
    goto skip_19;
    // 0x80800594: addiu       $t9, $zero, 0x19
    ctx->r25 = ADD32(0, 0X19);
    skip_19:
    // 0x80800598: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F80) << 16);
    // 0x8080059C: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X6F8C) << 16);
    // 0x808005A0: addiu       $s3, $s3, 0x6F8C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X6F8C));
    // 0x808005A4: addiu       $v0, $v0, 0x6F80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F80));
    // 0x808005A8: lui         $s0, 0x3
    ctx->r16 = S32(0X3 << 16);
    // 0x808005AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808005B0:
    // 0x808005B0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808005B4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808005B8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808005BC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x808005C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808005C4: jal         0x80082630
    // 0x808005C8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_20;
    // 0x808005C8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_20:
    // 0x808005CC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808005D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808005D4: bnel        $v0, $s3, L_808005B0
    if (ctx->r2 != ctx->r19) {
        // 0x808005D8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808005B0;
    }
    goto skip_20;
    // 0x808005D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_20:
    // 0x808005DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F8C) << 16);
    // 0x808005E0: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X6F98) << 16);
    // 0x808005E4: addiu       $s3, $s3, 0x6F98
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X6F98));
    // 0x808005E8: addiu       $v0, $v0, 0x6F8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F8C));
    // 0x808005EC: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
L_808005F0:
    // 0x808005F0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808005F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808005F8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808005FC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800600: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80800604: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800608: jal         0x80082630
    // 0x8080060C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_21;
    // 0x8080060C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_21:
    // 0x80800610: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800614: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800618: bnel        $v0, $s3, L_808005F0
    if (ctx->r2 != ctx->r19) {
        // 0x8080061C: addiu       $t0, $zero, 0x19
        ctx->r8 = ADD32(0, 0X19);
            goto L_808005F0;
    }
    goto skip_21;
    // 0x8080061C: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
    skip_21:
    // 0x80800620: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F98) << 16);
    // 0x80800624: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X6FA4) << 16);
    // 0x80800628: addiu       $s3, $s3, 0x6FA4
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X6FA4));
    // 0x8080062C: addiu       $v0, $v0, 0x6F98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F98));
    // 0x80800630: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800634:
    // 0x80800634: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800638: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8080063C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80800640: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80800644: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800648: jal         0x80082630
    // 0x8080064C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_22;
    // 0x8080064C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_22:
    // 0x80800650: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800654: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800658: bnel        $v0, $s3, L_80800634
    if (ctx->r2 != ctx->r19) {
        // 0x8080065C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800634;
    }
    goto skip_22;
    // 0x8080065C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_22:
    // 0x80800660: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6FA4) << 16);
    // 0x80800664: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X6FB0) << 16);
    // 0x80800668: addiu       $s3, $s3, 0x6FB0
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X6FB0));
    // 0x8080066C: addiu       $v0, $v0, 0x6FA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6FA4));
    // 0x80800670: addiu       $t1, $zero, 0x19
    ctx->r9 = ADD32(0, 0X19);
L_80800674:
    // 0x80800674: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80800678: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080067C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800680: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800684: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80800688: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080068C: jal         0x80082630
    // 0x80800690: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x80800690: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_23:
    // 0x80800694: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800698: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080069C: bnel        $v0, $s3, L_80800674
    if (ctx->r2 != ctx->r19) {
        // 0x808006A0: addiu       $t1, $zero, 0x19
        ctx->r9 = ADD32(0, 0X19);
            goto L_80800674;
    }
    goto skip_23;
    // 0x808006A0: addiu       $t1, $zero, 0x19
    ctx->r9 = ADD32(0, 0X19);
    skip_23:
    // 0x808006A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F80) << 16);
    // 0x808006A8: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X6F8C) << 16);
    // 0x808006AC: addiu       $s3, $s3, 0x6F8C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X6F8C));
    // 0x808006B0: addiu       $v0, $v0, 0x6F80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F80));
    // 0x808006B4: lui         $s0, 0x4
    ctx->r16 = S32(0X4 << 16);
    // 0x808006B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808006BC:
    // 0x808006BC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808006C0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808006C4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808006C8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x808006CC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808006D0: jal         0x80082630
    // 0x808006D4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_24;
    // 0x808006D4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_24:
    // 0x808006D8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808006DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808006E0: bnel        $v0, $s3, L_808006BC
    if (ctx->r2 != ctx->r19) {
        // 0x808006E4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808006BC;
    }
    goto skip_24;
    // 0x808006E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_24:
    // 0x808006E8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F8C) << 16);
    // 0x808006EC: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X6F98) << 16);
    // 0x808006F0: addiu       $s3, $s3, 0x6F98
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X6F98));
    // 0x808006F4: addiu       $v0, $v0, 0x6F8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F8C));
    // 0x808006F8: addiu       $t2, $zero, 0x19
    ctx->r10 = ADD32(0, 0X19);
L_808006FC:
    // 0x808006FC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80800700: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800704: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800708: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8080070C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80800710: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800714: jal         0x80082630
    // 0x80800718: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_25;
    // 0x80800718: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_25:
    // 0x8080071C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800720: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800724: bnel        $v0, $s3, L_808006FC
    if (ctx->r2 != ctx->r19) {
        // 0x80800728: addiu       $t2, $zero, 0x19
        ctx->r10 = ADD32(0, 0X19);
            goto L_808006FC;
    }
    goto skip_25;
    // 0x80800728: addiu       $t2, $zero, 0x19
    ctx->r10 = ADD32(0, 0X19);
    skip_25:
    // 0x8080072C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F98) << 16);
    // 0x80800730: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X6FA4) << 16);
    // 0x80800734: addiu       $s3, $s3, 0x6FA4
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X6FA4));
    // 0x80800738: addiu       $v0, $v0, 0x6F98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F98));
    // 0x8080073C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800740:
    // 0x80800740: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800744: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800748: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8080074C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80800750: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800754: jal         0x80082630
    // 0x80800758: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_26;
    // 0x80800758: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_26:
    // 0x8080075C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800760: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800764: bnel        $v0, $s3, L_80800740
    if (ctx->r2 != ctx->r19) {
        // 0x80800768: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800740;
    }
    goto skip_26;
    // 0x80800768: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_26:
    // 0x8080076C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6FA4) << 16);
    // 0x80800770: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X6FB0) << 16);
    // 0x80800774: addiu       $s3, $s3, 0x6FB0
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X6FB0));
    // 0x80800778: addiu       $v0, $v0, 0x6FA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6FA4));
    // 0x8080077C: addiu       $t3, $zero, 0x19
    ctx->r11 = ADD32(0, 0X19);
L_80800780:
    // 0x80800780: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80800784: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800788: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080078C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800790: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80800794: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800798: jal         0x80082630
    // 0x8080079C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_27;
    // 0x8080079C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_27:
    // 0x808007A0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808007A4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808007A8: bnel        $v0, $s3, L_80800780
    if (ctx->r2 != ctx->r19) {
        // 0x808007AC: addiu       $t3, $zero, 0x19
        ctx->r11 = ADD32(0, 0X19);
            goto L_80800780;
    }
    goto skip_27;
    // 0x808007AC: addiu       $t3, $zero, 0x19
    ctx->r11 = ADD32(0, 0X19);
    skip_27:
    // 0x808007B0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F80) << 16);
    // 0x808007B4: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X6F8C) << 16);
    // 0x808007B8: addiu       $s3, $s3, 0x6F8C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X6F8C));
    // 0x808007BC: addiu       $v0, $v0, 0x6F80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F80));
    // 0x808007C0: lui         $s0, 0x7
    ctx->r16 = S32(0X7 << 16);
    // 0x808007C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808007C8:
    // 0x808007C8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808007CC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808007D0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808007D4: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x808007D8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808007DC: jal         0x80082630
    // 0x808007E0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_28;
    // 0x808007E0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_28:
    // 0x808007E4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808007E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808007EC: bnel        $v0, $s3, L_808007C8
    if (ctx->r2 != ctx->r19) {
        // 0x808007F0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808007C8;
    }
    goto skip_28;
    // 0x808007F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_28:
    // 0x808007F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F8C) << 16);
    // 0x808007F8: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X6F98) << 16);
    // 0x808007FC: addiu       $s3, $s3, 0x6F98
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X6F98));
    // 0x80800800: addiu       $v0, $v0, 0x6F8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F8C));
    // 0x80800804: addiu       $t4, $zero, 0x19
    ctx->r12 = ADD32(0, 0X19);
L_80800808:
    // 0x80800808: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8080080C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800810: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800814: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800818: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8080081C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800820: jal         0x80082630
    // 0x80800824: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_29;
    // 0x80800824: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_29:
    // 0x80800828: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080082C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800830: bnel        $v0, $s3, L_80800808
    if (ctx->r2 != ctx->r19) {
        // 0x80800834: addiu       $t4, $zero, 0x19
        ctx->r12 = ADD32(0, 0X19);
            goto L_80800808;
    }
    goto skip_29;
    // 0x80800834: addiu       $t4, $zero, 0x19
    ctx->r12 = ADD32(0, 0X19);
    skip_29:
    // 0x80800838: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6F98) << 16);
    // 0x8080083C: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X6FA4) << 16);
    // 0x80800840: addiu       $s3, $s3, 0x6FA4
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X6FA4));
    // 0x80800844: addiu       $v0, $v0, 0x6F98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6F98));
    // 0x80800848: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8080084C:
    // 0x8080084C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800850: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800854: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80800858: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8080085C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800860: jal         0x80082630
    // 0x80800864: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_30;
    // 0x80800864: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_30:
    // 0x80800868: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080086C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800870: bnel        $v0, $s3, L_8080084C
    if (ctx->r2 != ctx->r19) {
        // 0x80800874: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080084C;
    }
    goto skip_30;
    // 0x80800874: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_30:
    // 0x80800878: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6FA4) << 16);
    // 0x8080087C: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X6FB0) << 16);
    // 0x80800880: addiu       $s3, $s3, 0x6FB0
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X6FB0));
    // 0x80800884: addiu       $v0, $v0, 0x6FA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6FA4));
    // 0x80800888: addiu       $t5, $zero, 0x19
    ctx->r13 = ADD32(0, 0X19);
L_8080088C:
    // 0x8080088C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80800890: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800894: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800898: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8080089C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808008A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808008A4: jal         0x80082630
    // 0x808008A8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_31;
    // 0x808008A8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_31:
    // 0x808008AC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808008B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808008B4: bnel        $v0, $s3, L_8080088C
    if (ctx->r2 != ctx->r19) {
        // 0x808008B8: addiu       $t5, $zero, 0x19
        ctx->r13 = ADD32(0, 0X19);
            goto L_8080088C;
    }
    goto skip_31;
    // 0x808008B8: addiu       $t5, $zero, 0x19
    ctx->r13 = ADD32(0, 0X19);
    skip_31:
    // 0x808008BC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X6FD8) << 16);
    // 0x808008C0: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808008C4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X6FE0) << 16);
    // 0x808008C8: addiu       $s1, $s1, 0x6FE0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X6FE0));
    // 0x808008CC: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x808008D0: addiu       $v0, $v0, 0x6FD8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X6FD8));
    // 0x808008D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_808008D8:
    // 0x808008D8: addiu       $t7, $zero, -0x2
    ctx->r15 = ADD32(0, -0X2);
    // 0x808008DC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808008E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808008E4: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x808008E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808008EC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808008F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808008F4: jal         0x80082630
    // 0x808008F8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_32;
    // 0x808008F8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_32:
    // 0x808008FC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800900: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800904: bnel        $v0, $s1, L_808008D8
    if (ctx->r2 != ctx->r17) {
        // 0x80800908: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808008D8;
    }
    goto skip_32;
    // 0x80800908: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_32:
    // 0x8080090C: b           L_80805794
    // 0x80800910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80800910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800914:
    // 0x80800914: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800918: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080091C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80800920: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800924: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80800928: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080092C: jal         0x80085998
    // 0x80800930: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_33;
    // 0x80800930: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_33:
    // 0x80800934: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800938: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x8080093C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800940: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80800944: jal         0x80085998
    // 0x80800948: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_34;
    // 0x80800948: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_34:
    // 0x8080094C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800950: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800954: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800958: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8080095C: jal         0x80085998
    // 0x80800960: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_35;
    // 0x80800960: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_35:
    // 0x80800964: b           L_80805794
    // 0x80800968: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80800968: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080096C:
    // 0x8080096C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800970: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800974: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80800978: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080097C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80800980: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800984: jal         0x80085998
    // 0x80800988: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_36;
    // 0x80800988: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_36:
    // 0x8080098C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800990: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800994: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800998: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x8080099C: jal         0x80085998
    // 0x808009A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_37;
    // 0x808009A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_37:
    // 0x808009A4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808009A8: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808009AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808009B0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x808009B4: jal         0x80085998
    // 0x808009B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_38;
    // 0x808009B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_38:
    // 0x808009BC: b           L_80805794
    // 0x808009C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x808009C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009C4:
    // 0x808009C4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808009C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808009CC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808009D0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808009D4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x808009D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808009DC: jal         0x80085998
    // 0x808009E0: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_39;
    // 0x808009E0: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_39:
    // 0x808009E4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808009E8: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808009EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808009F0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x808009F4: jal         0x80085998
    // 0x808009F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_40;
    // 0x808009F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_40:
    // 0x808009FC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800A00: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800A04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800A08: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80800A0C: jal         0x80085998
    // 0x80800A10: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_41;
    // 0x80800A10: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_41:
    // 0x80800A14: b           L_80805794
    // 0x80800A18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80800A18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A1C:
    // 0x80800A1C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800A20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800A24: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80800A28: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800A2C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80800A30: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800A34: jal         0x80085998
    // 0x80800A38: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_42;
    // 0x80800A38: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_42:
    // 0x80800A3C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800A40: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800A44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800A48: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80800A4C: jal         0x80085998
    // 0x80800A50: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_43;
    // 0x80800A50: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_43:
    // 0x80800A54: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800A58: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800A5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800A60: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80800A64: jal         0x80085998
    // 0x80800A68: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_44;
    // 0x80800A68: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_44:
    // 0x80800A6C: b           L_80805794
    // 0x80800A70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80800A70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A74:
    // 0x80800A74: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800A78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800A7C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80800A80: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800A84: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80800A88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800A8C: jal         0x80085998
    // 0x80800A90: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_45;
    // 0x80800A90: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_45:
    // 0x80800A94: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800A98: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800A9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800AA0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80800AA4: jal         0x80085998
    // 0x80800AA8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_46;
    // 0x80800AA8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_46:
    // 0x80800AAC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800AB0: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800AB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800AB8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80800ABC: jal         0x80085998
    // 0x80800AC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_47;
    // 0x80800AC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_47:
    // 0x80800AC4: b           L_80805794
    // 0x80800AC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80800AC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800ACC:
    // 0x80800ACC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800AD0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800AD4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800AD8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800ADC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800AE0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80800AE4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80800AE8: jal         0x80085998
    // 0x80800AEC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_48;
    // 0x80800AEC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_48:
    // 0x80800AF0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800AF4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800AF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800AFC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80800B00: jal         0x80085998
    // 0x80800B04: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_49;
    // 0x80800B04: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_49:
    // 0x80800B08: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800B0C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800B10: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800B14: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800B18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800B1C: jal         0x80085998
    // 0x80800B20: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_50;
    // 0x80800B20: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_50:
    // 0x80800B24: b           L_80805794
    // 0x80800B28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80800B28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B2C:
    // 0x80800B2C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800B30: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800B34: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800B38: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800B3C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800B40: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80800B44: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80800B48: jal         0x80085998
    // 0x80800B4C: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_51;
    // 0x80800B4C: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_51:
    // 0x80800B50: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800B54: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800B58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800B5C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80800B60: jal         0x80085998
    // 0x80800B64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_52;
    // 0x80800B64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_52:
    // 0x80800B68: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800B6C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800B70: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800B74: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800B78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800B7C: jal         0x80085998
    // 0x80800B80: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_53;
    // 0x80800B80: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_53:
    // 0x80800B84: b           L_80805794
    // 0x80800B88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80800B88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B8C:
    // 0x80800B8C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800B90: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800B94: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800B98: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800B9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800BA0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80800BA4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80800BA8: jal         0x80085998
    // 0x80800BAC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_54;
    // 0x80800BAC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_54:
    // 0x80800BB0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800BB4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800BB8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800BBC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80800BC0: jal         0x80085998
    // 0x80800BC4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_55;
    // 0x80800BC4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_55:
    // 0x80800BC8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800BCC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800BD0: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800BD4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800BD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800BDC: jal         0x80085998
    // 0x80800BE0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_56;
    // 0x80800BE0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_56:
    // 0x80800BE4: b           L_80805794
    // 0x80800BE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80800BE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BEC:
    // 0x80800BEC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800BF0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800BF4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800BF8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800BFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800C00: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80800C04: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80800C08: jal         0x80085998
    // 0x80800C0C: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_57;
    // 0x80800C0C: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_57:
    // 0x80800C10: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800C14: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800C18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800C1C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80800C20: jal         0x80085998
    // 0x80800C24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_58;
    // 0x80800C24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_58:
    // 0x80800C28: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800C2C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800C30: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800C34: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800C38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800C3C: jal         0x80085998
    // 0x80800C40: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_59;
    // 0x80800C40: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_59:
    // 0x80800C44: b           L_80805794
    // 0x80800C48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80800C48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C4C:
    // 0x80800C4C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800C50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800C54: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80800C58: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800C5C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80800C60: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800C64: jal         0x80085998
    // 0x80800C68: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_60;
    // 0x80800C68: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_60:
    // 0x80800C6C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800C70: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800C74: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800C78: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80800C7C: jal         0x80085998
    // 0x80800C80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_61;
    // 0x80800C80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_61:
    // 0x80800C84: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800C88: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800C8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800C90: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80800C94: jal         0x80085998
    // 0x80800C98: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_62;
    // 0x80800C98: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_62:
    // 0x80800C9C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800CA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800CA4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800CA8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800CAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800CB0: jal         0x80085998
    // 0x80800CB4: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_63;
    // 0x80800CB4: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_63:
    // 0x80800CB8: lui         $a1, 0x3F7A
    ctx->r5 = S32(0X3F7A << 16);
    // 0x80800CBC: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800CC0: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    // 0x80800CC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800CC8: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    // 0x80800CCC: jal         0x80085998
    // 0x80800CD0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_64;
    // 0x80800CD0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_64:
    // 0x80800CD4: b           L_80805794
    // 0x80800CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80800CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CDC:
    // 0x80800CDC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800CE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800CE4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80800CE8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800CEC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80800CF0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800CF4: jal         0x80085998
    // 0x80800CF8: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_65;
    // 0x80800CF8: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_65:
    // 0x80800CFC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800D00: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800D04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800D08: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80800D0C: jal         0x80085998
    // 0x80800D10: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_66;
    // 0x80800D10: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_66:
    // 0x80800D14: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800D18: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800D1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800D20: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80800D24: jal         0x80085998
    // 0x80800D28: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_67;
    // 0x80800D28: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_67:
    // 0x80800D2C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800D30: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800D34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800D38: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    // 0x80800D3C: jal         0x80085998
    // 0x80800D40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_68;
    // 0x80800D40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_68:
    // 0x80800D44: b           L_80805794
    // 0x80800D48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80800D48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D4C:
    // 0x80800D4C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80800D50: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7038) << 16);
    // 0x80800D54: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7040) << 16);
    // 0x80800D58: addiu       $s1, $s1, 0x7040
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7040));
    // 0x80800D5C: addiu       $v0, $v0, 0x7038
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7038));
    // 0x80800D60: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80800D64: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    // 0x80800D68: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_80800D6C:
    // 0x80800D6C: addiu       $t8, $zero, -0x2
    ctx->r24 = ADD32(0, -0X2);
    // 0x80800D70: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800D74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800D78: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800D7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800D80: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800D84: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800D88: jal         0x80082630
    // 0x80800D8C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_69;
    // 0x80800D8C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_69:
    // 0x80800D90: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800D94: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800D98: bnel        $v0, $s1, L_80800D6C
    if (ctx->r2 != ctx->r17) {
        // 0x80800D9C: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80800D6C;
    }
    goto skip_33;
    // 0x80800D9C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    skip_33:
    // 0x80800DA0: b           L_80805794
    // 0x80800DA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80800DA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DA8:
    // 0x80800DA8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7040) << 16);
    // 0x80800DAC: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2958, 0X704C) << 16);
    // 0x80800DB0: addiu       $s0, $s0, 0x704C
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2958, 0X704C));
    // 0x80800DB4: addiu       $v0, $v0, 0x7040
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7040));
    // 0x80800DB8: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    // 0x80800DBC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_80800DC0:
    // 0x80800DC0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800DC4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800DC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800DCC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800DD0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800DD4: jal         0x80085998
    // 0x80800DD8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_70;
    // 0x80800DD8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_70:
    // 0x80800DDC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800DE0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800DE4: bnel        $v0, $s0, L_80800DC0
    if (ctx->r2 != ctx->r16) {
        // 0x80800DE8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80800DC0;
    }
    goto skip_34;
    // 0x80800DE8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    skip_34:
    // 0x80800DEC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X704C) << 16);
    // 0x80800DF0: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2958, 0X7058) << 16);
    // 0x80800DF4: addiu       $s0, $s0, 0x7058
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2958, 0X7058));
    // 0x80800DF8: addiu       $v0, $v0, 0x704C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X704C));
    // 0x80800DFC: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
L_80800E00:
    // 0x80800E00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800E04: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800E08: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800E0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800E10: jal         0x80085998
    // 0x80800E14: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_71;
    // 0x80800E14: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_71:
    // 0x80800E18: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800E1C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800E20: bnel        $v0, $s0, L_80800E00
    if (ctx->r2 != ctx->r16) {
        // 0x80800E24: lw          $a2, 0x3D0($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X3D0);
            goto L_80800E00;
    }
    goto skip_35;
    // 0x80800E24: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    skip_35:
    // 0x80800E28: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7058) << 16);
    // 0x80800E2C: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2958, 0X7064) << 16);
    // 0x80800E30: addiu       $s0, $s0, 0x7064
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2958, 0X7064));
    // 0x80800E34: addiu       $v0, $v0, 0x7058
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7058));
    // 0x80800E38: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80800E3C:
    // 0x80800E3C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800E40: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80800E44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800E48: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800E4C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800E50: jal         0x80085998
    // 0x80800E54: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_72;
    // 0x80800E54: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_72:
    // 0x80800E58: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800E5C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800E60: bnel        $v0, $s0, L_80800E3C
    if (ctx->r2 != ctx->r16) {
        // 0x80800E64: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80800E3C;
    }
    goto skip_36;
    // 0x80800E64: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    skip_36:
    // 0x80800E68: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7064) << 16);
    // 0x80800E6C: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2958, 0X7070) << 16);
    // 0x80800E70: addiu       $s0, $s0, 0x7070
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2958, 0X7070));
    // 0x80800E74: addiu       $v0, $v0, 0x7064
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7064));
    // 0x80800E78: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
L_80800E7C:
    // 0x80800E7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800E80: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800E84: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800E88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800E8C: jal         0x80085998
    // 0x80800E90: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_73;
    // 0x80800E90: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_73:
    // 0x80800E94: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800E98: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800E9C: bnel        $v0, $s0, L_80800E7C
    if (ctx->r2 != ctx->r16) {
        // 0x80800EA0: lw          $a2, 0x3D0($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X3D0);
            goto L_80800E7C;
    }
    goto skip_37;
    // 0x80800EA0: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    skip_37:
    // 0x80800EA4: b           L_80805794
    // 0x80800EA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80800EA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EAC:
    // 0x80800EAC: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80800EB0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7070) << 16);
    // 0x80800EB4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x80800EB8: addiu       $s1, $s1, 0x707C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x80800EBC: addiu       $v0, $v0, 0x7070
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7070));
    // 0x80800EC0: addiu       $s0, $s0, -0x330
    ctx->r16 = ADD32(ctx->r16, -0X330);
    // 0x80800EC4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80800EC8:
    // 0x80800EC8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800ECC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800ED0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800ED4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800ED8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800EDC: jal         0x80082628
    // 0x80800EE0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_74;
    // 0x80800EE0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_74:
    // 0x80800EE4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800EE8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800EEC: bnel        $v0, $s1, L_80800EC8
    if (ctx->r2 != ctx->r17) {
        // 0x80800EF0: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80800EC8;
    }
    goto skip_38;
    // 0x80800EF0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_38:
    // 0x80800EF4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x80800EF8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80800EFC: addiu       $s1, $s1, 0x7088
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x80800F00: addiu       $v0, $v0, 0x707C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x80800F04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800F08:
    // 0x80800F08: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800F0C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800F10: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800F14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800F18: jal         0x80082628
    // 0x80800F1C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_75;
    // 0x80800F1C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_75:
    // 0x80800F20: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800F24: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800F28: bnel        $v0, $s1, L_80800F08
    if (ctx->r2 != ctx->r17) {
        // 0x80800F2C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800F08;
    }
    goto skip_39;
    // 0x80800F2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_39:
    // 0x80800F30: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7070) << 16);
    // 0x80800F34: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x80800F38: addiu       $s1, $s1, 0x707C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x80800F3C: addiu       $v0, $v0, 0x7070
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7070));
    // 0x80800F40: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80800F44:
    // 0x80800F44: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800F48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800F4C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800F50: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800F54: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80800F58: jal         0x80082628
    // 0x80800F5C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_76;
    // 0x80800F5C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_76:
    // 0x80800F60: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800F64: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800F68: bnel        $v0, $s1, L_80800F44
    if (ctx->r2 != ctx->r17) {
        // 0x80800F6C: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80800F44;
    }
    goto skip_40;
    // 0x80800F6C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_40:
    // 0x80800F70: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x80800F74: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80800F78: addiu       $s1, $s1, 0x7088
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x80800F7C: addiu       $v0, $v0, 0x707C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x80800F80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800F84:
    // 0x80800F84: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800F88: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800F8C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80800F90: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800F94: jal         0x80082628
    // 0x80800F98: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_77;
    // 0x80800F98: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_77:
    // 0x80800F9C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800FA0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800FA4: bnel        $v0, $s1, L_80800F84
    if (ctx->r2 != ctx->r17) {
        // 0x80800FA8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800F84;
    }
    goto skip_41;
    // 0x80800FA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_41:
    // 0x80800FAC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7070) << 16);
    // 0x80800FB0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x80800FB4: addiu       $s1, $s1, 0x707C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x80800FB8: addiu       $v0, $v0, 0x7070
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7070));
    // 0x80800FBC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80800FC0:
    // 0x80800FC0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800FC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800FC8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800FCC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800FD0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800FD4: jal         0x80082628
    // 0x80800FD8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_78;
    // 0x80800FD8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_78:
    // 0x80800FDC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800FE0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800FE4: bnel        $v0, $s1, L_80800FC0
    if (ctx->r2 != ctx->r17) {
        // 0x80800FE8: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80800FC0;
    }
    goto skip_42;
    // 0x80800FE8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    skip_42:
    // 0x80800FEC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x80800FF0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80800FF4: addiu       $s1, $s1, 0x7088
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x80800FF8: addiu       $v0, $v0, 0x707C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x80800FFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80801000:
    // 0x80801000: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801004: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801008: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8080100C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801010: jal         0x80082628
    // 0x80801014: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_79;
    // 0x80801014: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_79:
    // 0x80801018: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080101C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801020: bnel        $v0, $s1, L_80801000
    if (ctx->r2 != ctx->r17) {
        // 0x80801024: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801000;
    }
    goto skip_43;
    // 0x80801024: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_43:
    // 0x80801028: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7070) << 16);
    // 0x8080102C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x80801030: addiu       $s1, $s1, 0x707C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x80801034: addiu       $v0, $v0, 0x7070
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7070));
    // 0x80801038: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8080103C:
    // 0x8080103C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80801040: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801044: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801048: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080104C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80801050: jal         0x80082628
    // 0x80801054: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_80;
    // 0x80801054: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_80:
    // 0x80801058: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080105C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801060: bnel        $v0, $s1, L_8080103C
    if (ctx->r2 != ctx->r17) {
        // 0x80801064: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8080103C;
    }
    goto skip_44;
    // 0x80801064: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    skip_44:
    // 0x80801068: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x8080106C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80801070: addiu       $s1, $s1, 0x7088
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x80801074: addiu       $v0, $v0, 0x707C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x80801078: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8080107C:
    // 0x8080107C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801080: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801084: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80801088: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080108C: jal         0x80082628
    // 0x80801090: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_81;
    // 0x80801090: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_81:
    // 0x80801094: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801098: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080109C: bnel        $v0, $s1, L_8080107C
    if (ctx->r2 != ctx->r17) {
        // 0x808010A0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080107C;
    }
    goto skip_45;
    // 0x808010A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_45:
    // 0x808010A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7070) << 16);
    // 0x808010A8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x808010AC: addiu       $s1, $s1, 0x707C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x808010B0: addiu       $v0, $v0, 0x7070
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7070));
    // 0x808010B4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_808010B8:
    // 0x808010B8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808010BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808010C0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808010C4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808010C8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x808010CC: jal         0x80082628
    // 0x808010D0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_82;
    // 0x808010D0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_82:
    // 0x808010D4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808010D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808010DC: bnel        $v0, $s1, L_808010B8
    if (ctx->r2 != ctx->r17) {
        // 0x808010E0: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_808010B8;
    }
    goto skip_46;
    // 0x808010E0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_46:
    // 0x808010E4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x808010E8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x808010EC: addiu       $s1, $s1, 0x7088
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x808010F0: addiu       $v0, $v0, 0x707C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x808010F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808010F8:
    // 0x808010F8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808010FC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801100: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80801104: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801108: jal         0x80082628
    // 0x8080110C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_83;
    // 0x8080110C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_83:
    // 0x80801110: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801114: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801118: bnel        $v0, $s1, L_808010F8
    if (ctx->r2 != ctx->r17) {
        // 0x8080111C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808010F8;
    }
    goto skip_47;
    // 0x8080111C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_47:
    // 0x80801120: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7070) << 16);
    // 0x80801124: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x80801128: addiu       $s1, $s1, 0x707C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x8080112C: addiu       $v0, $v0, 0x7070
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7070));
    // 0x80801130: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_80801134:
    // 0x80801134: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801138: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080113C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801140: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801144: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80801148: jal         0x80082628
    // 0x8080114C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_84;
    // 0x8080114C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_84:
    // 0x80801150: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801154: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801158: bnel        $v0, $s1, L_80801134
    if (ctx->r2 != ctx->r17) {
        // 0x8080115C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80801134;
    }
    goto skip_48;
    // 0x8080115C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_48:
    // 0x80801160: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x80801164: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80801168: addiu       $s1, $s1, 0x7088
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x8080116C: addiu       $v0, $v0, 0x707C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x80801170: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80801174:
    // 0x80801174: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801178: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080117C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80801180: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801184: jal         0x80082628
    // 0x80801188: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_85;
    // 0x80801188: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_85:
    // 0x8080118C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801190: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801194: bnel        $v0, $s1, L_80801174
    if (ctx->r2 != ctx->r17) {
        // 0x80801198: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801174;
    }
    goto skip_49;
    // 0x80801198: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_49:
    // 0x8080119C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x808011A0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x808011A4: addiu       $s1, $s1, 0x7094
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x808011A8: addiu       $v0, $v0, 0x7088
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x808011AC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_808011B0:
    // 0x808011B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808011B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808011B8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808011BC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808011C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808011C4: jal         0x80082628
    // 0x808011C8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_86;
    // 0x808011C8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_86:
    // 0x808011CC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808011D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808011D4: bnel        $v0, $s1, L_808011B0
    if (ctx->r2 != ctx->r17) {
        // 0x808011D8: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_808011B0;
    }
    goto skip_50;
    // 0x808011D8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_50:
    // 0x808011DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x808011E0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X70A0) << 16);
    // 0x808011E4: addiu       $s1, $s1, 0x70A0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X70A0));
    // 0x808011E8: addiu       $v0, $v0, 0x7094
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x808011EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808011F0:
    // 0x808011F0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808011F4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808011F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808011FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801200: jal         0x80082628
    // 0x80801204: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_87;
    // 0x80801204: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_87:
    // 0x80801208: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080120C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801210: bnel        $v0, $s1, L_808011F0
    if (ctx->r2 != ctx->r17) {
        // 0x80801214: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808011F0;
    }
    goto skip_51;
    // 0x80801214: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_51:
    // 0x80801218: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x8080121C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x80801220: addiu       $s1, $s1, 0x7094
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x80801224: addiu       $v0, $v0, 0x7088
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x80801228: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_8080122C:
    // 0x8080122C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801230: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801234: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801238: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080123C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80801240: jal         0x80082628
    // 0x80801244: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_88;
    // 0x80801244: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_88:
    // 0x80801248: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080124C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801250: bnel        $v0, $s1, L_8080122C
    if (ctx->r2 != ctx->r17) {
        // 0x80801254: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8080122C;
    }
    goto skip_52;
    // 0x80801254: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    skip_52:
    // 0x80801258: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x8080125C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X70A0) << 16);
    // 0x80801260: addiu       $s1, $s1, 0x70A0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X70A0));
    // 0x80801264: addiu       $v0, $v0, 0x7094
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x80801268: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8080126C:
    // 0x8080126C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801270: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801274: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80801278: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080127C: jal         0x80082628
    // 0x80801280: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_89;
    // 0x80801280: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_89:
    // 0x80801284: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801288: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080128C: bnel        $v0, $s1, L_8080126C
    if (ctx->r2 != ctx->r17) {
        // 0x80801290: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080126C;
    }
    goto skip_53;
    // 0x80801290: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_53:
    // 0x80801294: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80801298: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x8080129C: addiu       $s1, $s1, 0x7094
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x808012A0: addiu       $v0, $v0, 0x7088
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x808012A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_808012A8:
    // 0x808012A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808012AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808012B0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808012B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808012B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808012BC: jal         0x80082628
    // 0x808012C0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_90;
    // 0x808012C0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_90:
    // 0x808012C4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808012C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808012CC: bnel        $v0, $s1, L_808012A8
    if (ctx->r2 != ctx->r17) {
        // 0x808012D0: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_808012A8;
    }
    goto skip_54;
    // 0x808012D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    skip_54:
    // 0x808012D4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x808012D8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X70A0) << 16);
    // 0x808012DC: addiu       $s1, $s1, 0x70A0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X70A0));
    // 0x808012E0: addiu       $v0, $v0, 0x7094
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x808012E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808012E8:
    // 0x808012E8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808012EC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808012F0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808012F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808012F8: jal         0x80082628
    // 0x808012FC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_91;
    // 0x808012FC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_91:
    // 0x80801300: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801304: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801308: bnel        $v0, $s1, L_808012E8
    if (ctx->r2 != ctx->r17) {
        // 0x8080130C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808012E8;
    }
    goto skip_55;
    // 0x8080130C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_55:
    // 0x80801310: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80801314: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x80801318: addiu       $s1, $s1, 0x7094
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x8080131C: addiu       $v0, $v0, 0x7088
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x80801320: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80801324:
    // 0x80801324: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801328: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080132C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801330: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801334: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80801338: jal         0x80082628
    // 0x8080133C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_92;
    // 0x8080133C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_92:
    // 0x80801340: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801344: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801348: bnel        $v0, $s1, L_80801324
    if (ctx->r2 != ctx->r17) {
        // 0x8080134C: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80801324;
    }
    goto skip_56;
    // 0x8080134C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    skip_56:
    // 0x80801350: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x80801354: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X70A0) << 16);
    // 0x80801358: addiu       $s1, $s1, 0x70A0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X70A0));
    // 0x8080135C: addiu       $v0, $v0, 0x7094
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x80801360: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80801364:
    // 0x80801364: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801368: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080136C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80801370: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801374: jal         0x80082628
    // 0x80801378: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_93;
    // 0x80801378: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_93:
    // 0x8080137C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801380: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801384: bnel        $v0, $s1, L_80801364
    if (ctx->r2 != ctx->r17) {
        // 0x80801388: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801364;
    }
    goto skip_57;
    // 0x80801388: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_57:
    // 0x8080138C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80801390: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x80801394: addiu       $s1, $s1, 0x7094
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x80801398: addiu       $v0, $v0, 0x7088
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x8080139C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_808013A0:
    // 0x808013A0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808013A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808013A8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808013AC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808013B0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x808013B4: jal         0x80082628
    // 0x808013B8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_94;
    // 0x808013B8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_94:
    // 0x808013BC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808013C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808013C4: bnel        $v0, $s1, L_808013A0
    if (ctx->r2 != ctx->r17) {
        // 0x808013C8: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_808013A0;
    }
    goto skip_58;
    // 0x808013C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_58:
    // 0x808013CC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x808013D0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X70A0) << 16);
    // 0x808013D4: addiu       $s1, $s1, 0x70A0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X70A0));
    // 0x808013D8: addiu       $v0, $v0, 0x7094
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x808013DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808013E0:
    // 0x808013E0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808013E4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808013E8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x808013EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808013F0: jal         0x80082628
    // 0x808013F4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_95;
    // 0x808013F4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_95:
    // 0x808013F8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808013FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801400: bnel        $v0, $s1, L_808013E0
    if (ctx->r2 != ctx->r17) {
        // 0x80801404: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808013E0;
    }
    goto skip_59;
    // 0x80801404: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_59:
    // 0x80801408: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x8080140C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x80801410: addiu       $s1, $s1, 0x7094
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x80801414: addiu       $v0, $v0, 0x7088
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x80801418: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8080141C:
    // 0x8080141C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801420: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801424: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801428: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080142C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80801430: jal         0x80082628
    // 0x80801434: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_96;
    // 0x80801434: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_96:
    // 0x80801438: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080143C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801440: bnel        $v0, $s1, L_8080141C
    if (ctx->r2 != ctx->r17) {
        // 0x80801444: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8080141C;
    }
    goto skip_60;
    // 0x80801444: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_60:
    // 0x80801448: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x8080144C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X70A0) << 16);
    // 0x80801450: addiu       $s1, $s1, 0x70A0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X70A0));
    // 0x80801454: addiu       $v0, $v0, 0x7094
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x80801458: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8080145C:
    // 0x8080145C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801460: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801464: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80801468: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080146C: jal         0x80082628
    // 0x80801470: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_97;
    // 0x80801470: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_97:
    // 0x80801474: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801478: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080147C: bnel        $v0, $s1, L_8080145C
    if (ctx->r2 != ctx->r17) {
        // 0x80801480: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080145C;
    }
    goto skip_61;
    // 0x80801480: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_61:
    // 0x80801484: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x80801488: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7070) << 16);
    // 0x8080148C: lui         $s5, 0x95AF
    ctx->r21 = S32(0X95AF << 16);
    // 0x80801490: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x80801494: addiu       $s3, $s3, 0x707C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x80801498: ori         $s5, $s5, 0xFF00
    ctx->r21 = ctx->r21 | 0XFF00;
    // 0x8080149C: addiu       $v0, $v0, 0x7070
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7070));
    // 0x808014A0: addiu       $s1, $s1, -0x7078
    ctx->r17 = ADD32(ctx->r17, -0X7078);
    // 0x808014A4: lui         $s0, 0x1
    ctx->r16 = S32(0X1 << 16);
    // 0x808014A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808014AC:
    // 0x808014AC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808014B0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808014B4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808014B8: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x808014BC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808014C0: jal         0x80082630
    // 0x808014C4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_98;
    // 0x808014C4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_98:
    // 0x808014C8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808014CC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808014D0: bnel        $v0, $s3, L_808014AC
    if (ctx->r2 != ctx->r19) {
        // 0x808014D4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808014AC;
    }
    goto skip_62;
    // 0x808014D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_62:
    // 0x808014D8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x808014DC: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x808014E0: lui         $s3, 0x6D87
    ctx->r19 = S32(0X6D87 << 16);
    // 0x808014E4: ori         $s3, $s3, 0xFF00
    ctx->r19 = ctx->r19 | 0XFF00;
    // 0x808014E8: addiu       $s4, $s4, 0x7088
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x808014EC: addiu       $v0, $v0, 0x707C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x808014F0: addiu       $t3, $zero, 0x19
    ctx->r11 = ADD32(0, 0X19);
L_808014F4:
    // 0x808014F4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808014F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808014FC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801500: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801504: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801508: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8080150C: jal         0x80082630
    // 0x80801510: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_99;
    // 0x80801510: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_99:
    // 0x80801514: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801518: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080151C: bnel        $v0, $s4, L_808014F4
    if (ctx->r2 != ctx->r20) {
        // 0x80801520: addiu       $t3, $zero, 0x19
        ctx->r11 = ADD32(0, 0X19);
            goto L_808014F4;
    }
    goto skip_63;
    // 0x80801520: addiu       $t3, $zero, 0x19
    ctx->r11 = ADD32(0, 0X19);
    skip_63:
    // 0x80801524: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80801528: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x8080152C: addiu       $s4, $s4, 0x7094
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x80801530: addiu       $v0, $v0, 0x7088
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x80801534: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80801538:
    // 0x80801538: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080153C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801540: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801544: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80801548: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8080154C: jal         0x80082630
    // 0x80801550: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_100;
    // 0x80801550: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_100:
    // 0x80801554: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801558: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080155C: bnel        $v0, $s4, L_80801538
    if (ctx->r2 != ctx->r20) {
        // 0x80801560: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801538;
    }
    goto skip_64;
    // 0x80801560: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_64:
    // 0x80801564: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x80801568: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X70A0) << 16);
    // 0x8080156C: addiu       $s4, $s4, 0x70A0
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X70A0));
    // 0x80801570: addiu       $v0, $v0, 0x7094
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x80801574: addiu       $t4, $zero, 0x19
    ctx->r12 = ADD32(0, 0X19);
L_80801578:
    // 0x80801578: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8080157C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801580: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801584: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801588: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8080158C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80801590: jal         0x80082630
    // 0x80801594: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_101;
    // 0x80801594: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_101:
    // 0x80801598: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080159C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808015A0: bnel        $v0, $s4, L_80801578
    if (ctx->r2 != ctx->r20) {
        // 0x808015A4: addiu       $t4, $zero, 0x19
        ctx->r12 = ADD32(0, 0X19);
            goto L_80801578;
    }
    goto skip_65;
    // 0x808015A4: addiu       $t4, $zero, 0x19
    ctx->r12 = ADD32(0, 0X19);
    skip_65:
    // 0x808015A8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7070) << 16);
    // 0x808015AC: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x808015B0: addiu       $s4, $s4, 0x707C
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x808015B4: addiu       $v0, $v0, 0x7070
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7070));
    // 0x808015B8: lui         $s0, 0x2
    ctx->r16 = S32(0X2 << 16);
    // 0x808015BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808015C0:
    // 0x808015C0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808015C4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808015C8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808015CC: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x808015D0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808015D4: jal         0x80082630
    // 0x808015D8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_102;
    // 0x808015D8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_102:
    // 0x808015DC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808015E0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808015E4: bnel        $v0, $s4, L_808015C0
    if (ctx->r2 != ctx->r20) {
        // 0x808015E8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808015C0;
    }
    goto skip_66;
    // 0x808015E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_66:
    // 0x808015EC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x808015F0: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x808015F4: addiu       $s4, $s4, 0x7088
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x808015F8: addiu       $v0, $v0, 0x707C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x808015FC: addiu       $t5, $zero, 0x19
    ctx->r13 = ADD32(0, 0X19);
L_80801600:
    // 0x80801600: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80801604: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801608: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080160C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801610: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801614: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80801618: jal         0x80082630
    // 0x8080161C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_103;
    // 0x8080161C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_103:
    // 0x80801620: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801624: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801628: bnel        $v0, $s4, L_80801600
    if (ctx->r2 != ctx->r20) {
        // 0x8080162C: addiu       $t5, $zero, 0x19
        ctx->r13 = ADD32(0, 0X19);
            goto L_80801600;
    }
    goto skip_67;
    // 0x8080162C: addiu       $t5, $zero, 0x19
    ctx->r13 = ADD32(0, 0X19);
    skip_67:
    // 0x80801630: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80801634: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x80801638: addiu       $s4, $s4, 0x7094
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x8080163C: addiu       $v0, $v0, 0x7088
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x80801640: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80801644:
    // 0x80801644: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801648: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8080164C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801650: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80801654: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80801658: jal         0x80082630
    // 0x8080165C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_104;
    // 0x8080165C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_104:
    // 0x80801660: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801664: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801668: bnel        $v0, $s4, L_80801644
    if (ctx->r2 != ctx->r20) {
        // 0x8080166C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801644;
    }
    goto skip_68;
    // 0x8080166C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_68:
    // 0x80801670: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x80801674: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X70A0) << 16);
    // 0x80801678: addiu       $s4, $s4, 0x70A0
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X70A0));
    // 0x8080167C: addiu       $v0, $v0, 0x7094
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x80801680: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
L_80801684:
    // 0x80801684: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80801688: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080168C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801690: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801694: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801698: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8080169C: jal         0x80082630
    // 0x808016A0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_105;
    // 0x808016A0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_105:
    // 0x808016A4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808016A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808016AC: bnel        $v0, $s4, L_80801684
    if (ctx->r2 != ctx->r20) {
        // 0x808016B0: addiu       $t6, $zero, 0x19
        ctx->r14 = ADD32(0, 0X19);
            goto L_80801684;
    }
    goto skip_69;
    // 0x808016B0: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    skip_69:
    // 0x808016B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7070) << 16);
    // 0x808016B8: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x808016BC: addiu       $s4, $s4, 0x707C
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x808016C0: addiu       $v0, $v0, 0x7070
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7070));
    // 0x808016C4: lui         $s0, 0x3
    ctx->r16 = S32(0X3 << 16);
    // 0x808016C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808016CC:
    // 0x808016CC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808016D0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808016D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808016D8: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x808016DC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808016E0: jal         0x80082630
    // 0x808016E4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_106;
    // 0x808016E4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_106:
    // 0x808016E8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808016EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808016F0: bnel        $v0, $s4, L_808016CC
    if (ctx->r2 != ctx->r20) {
        // 0x808016F4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808016CC;
    }
    goto skip_70;
    // 0x808016F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_70:
    // 0x808016F8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x808016FC: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80801700: addiu       $s4, $s4, 0x7088
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x80801704: addiu       $v0, $v0, 0x707C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x80801708: addiu       $t7, $zero, 0x19
    ctx->r15 = ADD32(0, 0X19);
L_8080170C:
    // 0x8080170C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801710: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801714: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801718: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8080171C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801720: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80801724: jal         0x80082630
    // 0x80801728: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_107;
    // 0x80801728: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_107:
    // 0x8080172C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801730: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801734: bnel        $v0, $s4, L_8080170C
    if (ctx->r2 != ctx->r20) {
        // 0x80801738: addiu       $t7, $zero, 0x19
        ctx->r15 = ADD32(0, 0X19);
            goto L_8080170C;
    }
    goto skip_71;
    // 0x80801738: addiu       $t7, $zero, 0x19
    ctx->r15 = ADD32(0, 0X19);
    skip_71:
    // 0x8080173C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80801740: lui         $s4, 0xAECB
    ctx->r20 = S32(0XAECB << 16);
    // 0x80801744: ori         $s4, $s4, 0xFF00
    ctx->r20 = ctx->r20 | 0XFF00;
    // 0x80801748: addiu       $v0, $v0, 0x7088
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x8080174C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80801750:
    // 0x80801750: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801754: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801758: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8080175C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80801760: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80801764: jal         0x80082630
    // 0x80801768: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_108;
    // 0x80801768: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_108:
    // 0x8080176C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801770: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x80801774: addiu       $t8, $t8, 0x7094
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x80801778: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080177C: bnel        $v0, $t8, L_80801750
    if (ctx->r2 != ctx->r24) {
        // 0x80801780: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801750;
    }
    goto skip_72;
    // 0x80801780: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_72:
    // 0x80801784: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x80801788: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X70A0) << 16);
    // 0x8080178C: addiu       $s4, $s4, 0x70A0
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X70A0));
    // 0x80801790: addiu       $v0, $v0, 0x7094
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x80801794: addiu       $t9, $zero, 0x19
    ctx->r25 = ADD32(0, 0X19);
L_80801798:
    // 0x80801798: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8080179C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808017A0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808017A4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808017A8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808017AC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x808017B0: jal         0x80082630
    // 0x808017B4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_109;
    // 0x808017B4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_109:
    // 0x808017B8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808017BC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808017C0: bnel        $v0, $s4, L_80801798
    if (ctx->r2 != ctx->r20) {
        // 0x808017C4: addiu       $t9, $zero, 0x19
        ctx->r25 = ADD32(0, 0X19);
            goto L_80801798;
    }
    goto skip_73;
    // 0x808017C4: addiu       $t9, $zero, 0x19
    ctx->r25 = ADD32(0, 0X19);
    skip_73:
    // 0x808017C8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7070) << 16);
    // 0x808017CC: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x808017D0: addiu       $s4, $s4, 0x707C
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x808017D4: addiu       $v0, $v0, 0x7070
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7070));
    // 0x808017D8: lui         $s0, 0x4
    ctx->r16 = S32(0X4 << 16);
    // 0x808017DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808017E0:
    // 0x808017E0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808017E4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808017E8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808017EC: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x808017F0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808017F4: jal         0x80082630
    // 0x808017F8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_110;
    // 0x808017F8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_110:
    // 0x808017FC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801800: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801804: bnel        $v0, $s4, L_808017E0
    if (ctx->r2 != ctx->r20) {
        // 0x80801808: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808017E0;
    }
    goto skip_74;
    // 0x80801808: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_74:
    // 0x8080180C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x80801810: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80801814: addiu       $s4, $s4, 0x7088
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x80801818: addiu       $v0, $v0, 0x707C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x8080181C: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
L_80801820:
    // 0x80801820: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80801824: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801828: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080182C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801830: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801834: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80801838: jal         0x80082630
    // 0x8080183C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_111;
    // 0x8080183C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_111:
    // 0x80801840: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801844: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801848: bnel        $v0, $s4, L_80801820
    if (ctx->r2 != ctx->r20) {
        // 0x8080184C: addiu       $t0, $zero, 0x19
        ctx->r8 = ADD32(0, 0X19);
            goto L_80801820;
    }
    goto skip_75;
    // 0x8080184C: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
    skip_75:
    // 0x80801850: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80801854: lui         $s4, 0x7CCB
    ctx->r20 = S32(0X7CCB << 16);
    // 0x80801858: ori         $s4, $s4, 0xFF00
    ctx->r20 = ctx->r20 | 0XFF00;
    // 0x8080185C: addiu       $v0, $v0, 0x7088
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x80801860: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80801864:
    // 0x80801864: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801868: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8080186C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801870: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80801874: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80801878: jal         0x80082630
    // 0x8080187C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_112;
    // 0x8080187C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_112:
    // 0x80801880: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801884: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x80801888: addiu       $t1, $t1, 0x7094
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x8080188C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801890: bnel        $v0, $t1, L_80801864
    if (ctx->r2 != ctx->r9) {
        // 0x80801894: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801864;
    }
    goto skip_76;
    // 0x80801894: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_76:
    // 0x80801898: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x8080189C: addiu       $v0, $v0, 0x7094
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x808018A0: addiu       $t2, $zero, 0x19
    ctx->r10 = ADD32(0, 0X19);
L_808018A4:
    // 0x808018A4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x808018A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808018AC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808018B0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808018B4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808018B8: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x808018BC: jal         0x80082630
    // 0x808018C0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_113;
    // 0x808018C0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_113:
    // 0x808018C4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808018C8: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2958, 0X70A0) << 16);
    // 0x808018CC: addiu       $t3, $t3, 0x70A0
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(2958, 0X70A0));
    // 0x808018D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808018D4: bnel        $v0, $t3, L_808018A4
    if (ctx->r2 != ctx->r11) {
        // 0x808018D8: addiu       $t2, $zero, 0x19
        ctx->r10 = ADD32(0, 0X19);
            goto L_808018A4;
    }
    goto skip_77;
    // 0x808018D8: addiu       $t2, $zero, 0x19
    ctx->r10 = ADD32(0, 0X19);
    skip_77:
    // 0x808018DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7070) << 16);
    // 0x808018E0: addiu       $v0, $v0, 0x7070
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7070));
    // 0x808018E4: lui         $s0, 0x5
    ctx->r16 = S32(0X5 << 16);
    // 0x808018E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808018EC:
    // 0x808018EC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808018F0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808018F4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808018F8: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x808018FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80801900: jal         0x80082630
    // 0x80801904: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_114;
    // 0x80801904: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_114:
    // 0x80801908: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080190C: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x80801910: addiu       $t4, $t4, 0x707C
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x80801914: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801918: bnel        $v0, $t4, L_808018EC
    if (ctx->r2 != ctx->r12) {
        // 0x8080191C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808018EC;
    }
    goto skip_78;
    // 0x8080191C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_78:
    // 0x80801920: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x80801924: addiu       $v0, $v0, 0x707C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x80801928: addiu       $t5, $zero, 0x19
    ctx->r13 = ADD32(0, 0X19);
L_8080192C:
    // 0x8080192C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80801930: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801934: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801938: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8080193C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801940: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80801944: jal         0x80082630
    // 0x80801948: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_115;
    // 0x80801948: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_115:
    // 0x8080194C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801950: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80801954: addiu       $t6, $t6, 0x7088
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x80801958: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080195C: bnel        $v0, $t6, L_8080192C
    if (ctx->r2 != ctx->r14) {
        // 0x80801960: addiu       $t5, $zero, 0x19
        ctx->r13 = ADD32(0, 0X19);
            goto L_8080192C;
    }
    goto skip_79;
    // 0x80801960: addiu       $t5, $zero, 0x19
    ctx->r13 = ADD32(0, 0X19);
    skip_79:
    // 0x80801964: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80801968: addiu       $v0, $v0, 0x7088
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x8080196C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80801970:
    // 0x80801970: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801974: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801978: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8080197C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80801980: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80801984: jal         0x80082630
    // 0x80801988: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_116;
    // 0x80801988: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_116:
    // 0x8080198C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801990: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x80801994: addiu       $t7, $t7, 0x7094
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x80801998: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080199C: bnel        $v0, $t7, L_80801970
    if (ctx->r2 != ctx->r15) {
        // 0x808019A0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801970;
    }
    goto skip_80;
    // 0x808019A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_80:
    // 0x808019A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x808019A8: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X70A0) << 16);
    // 0x808019AC: addiu       $s4, $s4, 0x70A0
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X70A0));
    // 0x808019B0: addiu       $v0, $v0, 0x7094
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x808019B4: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
L_808019B8:
    // 0x808019B8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808019BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808019C0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808019C4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808019C8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808019CC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x808019D0: jal         0x80082630
    // 0x808019D4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_117;
    // 0x808019D4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_117:
    // 0x808019D8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808019DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808019E0: bnel        $v0, $s4, L_808019B8
    if (ctx->r2 != ctx->r20) {
        // 0x808019E4: addiu       $t8, $zero, 0x19
        ctx->r24 = ADD32(0, 0X19);
            goto L_808019B8;
    }
    goto skip_81;
    // 0x808019E4: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
    skip_81:
    // 0x808019E8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7070) << 16);
    // 0x808019EC: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x808019F0: addiu       $s4, $s4, 0x707C
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x808019F4: addiu       $v0, $v0, 0x7070
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7070));
    // 0x808019F8: lui         $s0, 0x7
    ctx->r16 = S32(0X7 << 16);
    // 0x808019FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80801A00:
    // 0x80801A00: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801A04: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801A08: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801A0C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80801A10: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80801A14: jal         0x80082630
    // 0x80801A18: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_118;
    // 0x80801A18: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_118:
    // 0x80801A1C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801A20: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801A24: bnel        $v0, $s4, L_80801A00
    if (ctx->r2 != ctx->r20) {
        // 0x80801A28: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801A00;
    }
    goto skip_82;
    // 0x80801A28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_82:
    // 0x80801A2C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x80801A30: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80801A34: addiu       $s4, $s4, 0x7088
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x80801A38: addiu       $v0, $v0, 0x707C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x80801A3C: addiu       $t9, $zero, 0x19
    ctx->r25 = ADD32(0, 0X19);
L_80801A40:
    // 0x80801A40: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80801A44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801A48: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801A4C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801A50: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801A54: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80801A58: jal         0x80082630
    // 0x80801A5C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_119;
    // 0x80801A5C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_119:
    // 0x80801A60: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801A64: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801A68: bnel        $v0, $s4, L_80801A40
    if (ctx->r2 != ctx->r20) {
        // 0x80801A6C: addiu       $t9, $zero, 0x19
        ctx->r25 = ADD32(0, 0X19);
            goto L_80801A40;
    }
    goto skip_83;
    // 0x80801A6C: addiu       $t9, $zero, 0x19
    ctx->r25 = ADD32(0, 0X19);
    skip_83:
    // 0x80801A70: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80801A74: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x80801A78: addiu       $s4, $s4, 0x7094
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x80801A7C: addiu       $v0, $v0, 0x7088
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x80801A80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80801A84:
    // 0x80801A84: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801A88: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801A8C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801A90: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80801A94: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80801A98: jal         0x80082630
    // 0x80801A9C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_120;
    // 0x80801A9C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_120:
    // 0x80801AA0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801AA4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801AA8: bnel        $v0, $s4, L_80801A84
    if (ctx->r2 != ctx->r20) {
        // 0x80801AAC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801A84;
    }
    goto skip_84;
    // 0x80801AAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_84:
    // 0x80801AB0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x80801AB4: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X70A0) << 16);
    // 0x80801AB8: addiu       $s4, $s4, 0x70A0
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X70A0));
    // 0x80801ABC: addiu       $v0, $v0, 0x7094
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x80801AC0: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
L_80801AC4:
    // 0x80801AC4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80801AC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801ACC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801AD0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801AD4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801AD8: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80801ADC: jal         0x80082630
    // 0x80801AE0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_121;
    // 0x80801AE0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_121:
    // 0x80801AE4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801AE8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801AEC: bnel        $v0, $s4, L_80801AC4
    if (ctx->r2 != ctx->r20) {
        // 0x80801AF0: addiu       $t0, $zero, 0x19
        ctx->r8 = ADD32(0, 0X19);
            goto L_80801AC4;
    }
    goto skip_85;
    // 0x80801AF0: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
    skip_85:
    // 0x80801AF4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7070) << 16);
    // 0x80801AF8: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x80801AFC: addiu       $s4, $s4, 0x707C
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x80801B00: addiu       $v0, $v0, 0x7070
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7070));
    // 0x80801B04: lui         $s0, 0x8
    ctx->r16 = S32(0X8 << 16);
    // 0x80801B08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80801B0C:
    // 0x80801B0C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801B10: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801B14: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801B18: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80801B1C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80801B20: jal         0x80082630
    // 0x80801B24: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_122;
    // 0x80801B24: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_122:
    // 0x80801B28: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801B2C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801B30: bnel        $v0, $s4, L_80801B0C
    if (ctx->r2 != ctx->r20) {
        // 0x80801B34: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801B0C;
    }
    goto skip_86;
    // 0x80801B34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_86:
    // 0x80801B38: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X707C) << 16);
    // 0x80801B3C: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80801B40: addiu       $s4, $s4, 0x7088
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x80801B44: addiu       $v0, $v0, 0x707C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X707C));
    // 0x80801B48: addiu       $t1, $zero, 0x19
    ctx->r9 = ADD32(0, 0X19);
L_80801B4C:
    // 0x80801B4C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80801B50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801B54: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801B58: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801B5C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801B60: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80801B64: jal         0x80082630
    // 0x80801B68: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_123;
    // 0x80801B68: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_123:
    // 0x80801B6C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801B70: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801B74: bnel        $v0, $s4, L_80801B4C
    if (ctx->r2 != ctx->r20) {
        // 0x80801B78: addiu       $t1, $zero, 0x19
        ctx->r9 = ADD32(0, 0X19);
            goto L_80801B4C;
    }
    goto skip_87;
    // 0x80801B78: addiu       $t1, $zero, 0x19
    ctx->r9 = ADD32(0, 0X19);
    skip_87:
    // 0x80801B7C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7088) << 16);
    // 0x80801B80: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x80801B84: addiu       $s4, $s4, 0x7094
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x80801B88: addiu       $v0, $v0, 0x7088
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7088));
    // 0x80801B8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80801B90:
    // 0x80801B90: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801B94: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801B98: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801B9C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80801BA0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80801BA4: jal         0x80082630
    // 0x80801BA8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_124;
    // 0x80801BA8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_124:
    // 0x80801BAC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801BB0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801BB4: bnel        $v0, $s4, L_80801B90
    if (ctx->r2 != ctx->r20) {
        // 0x80801BB8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801B90;
    }
    goto skip_88;
    // 0x80801BB8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_88:
    // 0x80801BBC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7094) << 16);
    // 0x80801BC0: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X70A0) << 16);
    // 0x80801BC4: addiu       $s4, $s4, 0x70A0
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X70A0));
    // 0x80801BC8: addiu       $v0, $v0, 0x7094
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7094));
    // 0x80801BCC: addiu       $t2, $zero, 0x19
    ctx->r10 = ADD32(0, 0X19);
L_80801BD0:
    // 0x80801BD0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80801BD4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801BD8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801BDC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801BE0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801BE4: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80801BE8: jal         0x80082630
    // 0x80801BEC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_125;
    // 0x80801BEC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_125:
    // 0x80801BF0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801BF4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801BF8: bnel        $v0, $s4, L_80801BD0
    if (ctx->r2 != ctx->r20) {
        // 0x80801BFC: addiu       $t2, $zero, 0x19
        ctx->r10 = ADD32(0, 0X19);
            goto L_80801BD0;
    }
    goto skip_89;
    // 0x80801BFC: addiu       $t2, $zero, 0x19
    ctx->r10 = ADD32(0, 0X19);
    skip_89:
    // 0x80801C00: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80801C04: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X70C8) << 16);
    // 0x80801C08: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X70D0) << 16);
    // 0x80801C0C: addiu       $s1, $s1, 0x70D0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X70D0));
    // 0x80801C10: addiu       $v0, $v0, 0x70C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X70C8));
    // 0x80801C14: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80801C18: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80801C1C:
    // 0x80801C1C: addiu       $t4, $zero, -0x2
    ctx->r12 = ADD32(0, -0X2);
    // 0x80801C20: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80801C24: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80801C28: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801C2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801C30: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801C34: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801C38: jal         0x80082630
    // 0x80801C3C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_126;
    // 0x80801C3C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_126:
    // 0x80801C40: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801C44: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801C48: bnel        $v0, $s1, L_80801C1C
    if (ctx->r2 != ctx->r17) {
        // 0x80801C4C: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80801C1C;
    }
    goto skip_90;
    // 0x80801C4C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    skip_90:
    // 0x80801C50: b           L_80805794
    // 0x80801C54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80801C54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801C58:
    // 0x80801C58: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x80801C5C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X70D0) << 16);
    // 0x80801C60: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X70D4) << 16);
    // 0x80801C64: addiu       $s4, $s4, 0x70D4
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X70D4));
    // 0x80801C68: addiu       $v0, $v0, 0x70D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X70D0));
    // 0x80801C6C: addiu       $s1, $s1, -0x7078
    ctx->r17 = ADD32(ctx->r17, -0X7078);
    // 0x80801C70: lui         $s3, 0xFF
    ctx->r19 = S32(0XFF << 16);
    // 0x80801C74: lui         $s0, 0x6
    ctx->r16 = S32(0X6 << 16);
    // 0x80801C78: addiu       $t5, $zero, 0x100
    ctx->r13 = ADD32(0, 0X100);
L_80801C7C:
    // 0x80801C7C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80801C80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801C84: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801C88: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801C8C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801C90: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80801C94: jal         0x80082630
    // 0x80801C98: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_127;
    // 0x80801C98: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_127:
    // 0x80801C9C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80801CA0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801CA4: bnel        $v0, $s4, L_80801C7C
    if (ctx->r2 != ctx->r20) {
        // 0x80801CA8: addiu       $t5, $zero, 0x100
        ctx->r13 = ADD32(0, 0X100);
            goto L_80801C7C;
    }
    goto skip_91;
    // 0x80801CA8: addiu       $t5, $zero, 0x100
    ctx->r13 = ADD32(0, 0X100);
    skip_91:
    // 0x80801CAC: b           L_80805794
    // 0x80801CB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80801CB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801CB4:
    // 0x80801CB4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X68EC) << 16);
    // 0x80801CB8: lwc1        $f20, 0x68EC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X68EC));
    // 0x80801CBC: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80801CC0: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80801CC4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80801CC8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801CCC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801CD0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801CD4: addiu       $a2, $a2, -0x7088
    ctx->r6 = ADD32(ctx->r6, -0X7088);
    // 0x80801CD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801CDC: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80801CE0: jal         0x80082630
    // 0x80801CE4: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_128;
    // 0x80801CE4: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_128:
    // 0x80801CE8: b           L_80805794
    // 0x80801CEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80801CEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801CF0:
    // 0x80801CF0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X68F0) << 16);
    // 0x80801CF4: lwc1        $f20, 0x68F0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X68F0));
    // 0x80801CF8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801CFC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801D00: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801D04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801D08: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80801D0C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80801D10: jal         0x80085998
    // 0x80801D14: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_129;
    // 0x80801D14: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_129:
    // 0x80801D18: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801D1C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80801D20: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801D24: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801D28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801D2C: jal         0x80085998
    // 0x80801D30: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_130;
    // 0x80801D30: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_130:
    // 0x80801D34: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801D38: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801D3C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801D40: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801D44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801D48: jal         0x80085998
    // 0x80801D4C: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_131;
    // 0x80801D4C: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_131:
    // 0x80801D50: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801D54: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801D58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801D5C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80801D60: jal         0x80085998
    // 0x80801D64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_132;
    // 0x80801D64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_132:
    // 0x80801D68: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801D6C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801D70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801D74: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x80801D78: jal         0x80085998
    // 0x80801D7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_133;
    // 0x80801D7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_133:
    // 0x80801D80: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801D84: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80801D88: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801D8C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80801D90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801D94: jal         0x80085998
    // 0x80801D98: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_134;
    // 0x80801D98: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_134:
    // 0x80801D9C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801DA0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80801DA4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801DA8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801DAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801DB0: jal         0x80085998
    // 0x80801DB4: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_135;
    // 0x80801DB4: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_135:
    // 0x80801DB8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801DBC: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801DC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801DC4: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80801DC8: jal         0x80085998
    // 0x80801DCC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_136;
    // 0x80801DCC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_136:
    // 0x80801DD0: b           L_80805794
    // 0x80801DD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80801DD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801DD8:
    // 0x80801DD8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X68F4) << 16);
    // 0x80801DDC: lwc1        $f20, 0x68F4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X68F4));
    // 0x80801DE0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80801DE4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80801DE8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801DEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801DF0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80801DF4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80801DF8: jal         0x80085998
    // 0x80801DFC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_137;
    // 0x80801DFC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_137:
    // 0x80801E00: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801E04: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80801E08: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801E0C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80801E10: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801E14: jal         0x80085998
    // 0x80801E18: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_138;
    // 0x80801E18: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_138:
    // 0x80801E1C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801E20: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80801E24: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801E28: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80801E2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801E30: jal         0x80085998
    // 0x80801E34: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_139;
    // 0x80801E34: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_139:
    // 0x80801E38: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801E3C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801E40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801E44: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80801E48: jal         0x80085998
    // 0x80801E4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_140;
    // 0x80801E4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_140:
    // 0x80801E50: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801E54: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801E58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801E5C: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x80801E60: jal         0x80085998
    // 0x80801E64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_141;
    // 0x80801E64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_141:
    // 0x80801E68: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801E6C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801E70: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801E74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801E78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801E7C: jal         0x80085998
    // 0x80801E80: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_142;
    // 0x80801E80: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_142:
    // 0x80801E84: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801E88: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801E8C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801E90: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801E94: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801E98: jal         0x80085998
    // 0x80801E9C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_143;
    // 0x80801E9C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_143:
    // 0x80801EA0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801EA4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801EA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801EAC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80801EB0: jal         0x80085998
    // 0x80801EB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_144;
    // 0x80801EB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_144:
    // 0x80801EB8: b           L_80805794
    // 0x80801EBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80801EBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801EC0:
    // 0x80801EC0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X68F8) << 16);
    // 0x80801EC4: lwc1        $f20, 0x68F8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X68F8));
    // 0x80801EC8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801ECC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801ED0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801ED4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801ED8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80801EDC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80801EE0: jal         0x80085998
    // 0x80801EE4: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_145;
    // 0x80801EE4: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_145:
    // 0x80801EE8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801EEC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80801EF0: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801EF4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801EF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801EFC: jal         0x80085998
    // 0x80801F00: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_146;
    // 0x80801F00: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_146:
    // 0x80801F04: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801F08: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801F0C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801F10: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801F14: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801F18: jal         0x80085998
    // 0x80801F1C: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_147;
    // 0x80801F1C: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_147:
    // 0x80801F20: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801F24: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801F28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801F2C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80801F30: jal         0x80085998
    // 0x80801F34: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_148;
    // 0x80801F34: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_148:
    // 0x80801F38: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801F3C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801F40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801F44: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x80801F48: jal         0x80085998
    // 0x80801F4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_149;
    // 0x80801F4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_149:
    // 0x80801F50: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801F54: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80801F58: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801F5C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80801F60: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801F64: jal         0x80085998
    // 0x80801F68: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_150;
    // 0x80801F68: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_150:
    // 0x80801F6C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801F70: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80801F74: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801F78: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801F7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801F80: jal         0x80085998
    // 0x80801F84: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_151;
    // 0x80801F84: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_151:
    // 0x80801F88: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801F8C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801F90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801F94: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80801F98: jal         0x80085998
    // 0x80801F9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_152;
    // 0x80801F9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_152:
    // 0x80801FA0: b           L_80805794
    // 0x80801FA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80801FA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801FA8:
    // 0x80801FA8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X68FC) << 16);
    // 0x80801FAC: lwc1        $f20, 0x68FC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X68FC));
    // 0x80801FB0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80801FB4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80801FB8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801FBC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801FC0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80801FC4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80801FC8: jal         0x80085998
    // 0x80801FCC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_153;
    // 0x80801FCC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_153:
    // 0x80801FD0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801FD4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80801FD8: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801FDC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80801FE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801FE4: jal         0x80085998
    // 0x80801FE8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_154;
    // 0x80801FE8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_154:
    // 0x80801FEC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801FF0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80801FF4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80801FF8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80801FFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802000: jal         0x80085998
    // 0x80802004: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_155;
    // 0x80802004: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_155:
    // 0x80802008: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080200C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802010: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802014: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80802018: jal         0x80085998
    // 0x8080201C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_156;
    // 0x8080201C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_156:
    // 0x80802020: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802024: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802028: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080202C: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x80802030: jal         0x80085998
    // 0x80802034: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_157;
    // 0x80802034: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_157:
    // 0x80802038: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080203C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80802040: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802044: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802048: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080204C: jal         0x80085998
    // 0x80802050: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_158;
    // 0x80802050: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_158:
    // 0x80802054: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802058: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080205C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802060: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802064: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802068: jal         0x80085998
    // 0x8080206C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_159;
    // 0x8080206C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_159:
    // 0x80802070: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802074: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802078: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080207C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80802080: jal         0x80085998
    // 0x80802084: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_160;
    // 0x80802084: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_160:
    // 0x80802088: b           L_80805794
    // 0x8080208C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x8080208C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802090:
    // 0x80802090: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6900) << 16);
    // 0x80802094: lwc1        $f20, 0x6900($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6900));
    // 0x80802098: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8080209C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808020A0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808020A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808020A8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808020AC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808020B0: jal         0x80085998
    // 0x808020B4: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_161;
    // 0x808020B4: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_161:
    // 0x808020B8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808020BC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808020C0: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808020C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808020C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808020CC: jal         0x80085998
    // 0x808020D0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_162;
    // 0x808020D0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_162:
    // 0x808020D4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808020D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808020DC: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808020E0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808020E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808020E8: jal         0x80085998
    // 0x808020EC: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_163;
    // 0x808020EC: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_163:
    // 0x808020F0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808020F4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808020F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808020FC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80802100: jal         0x80085998
    // 0x80802104: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_164;
    // 0x80802104: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_164:
    // 0x80802108: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080210C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802110: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802114: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x80802118: jal         0x80085998
    // 0x8080211C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_165;
    // 0x8080211C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_165:
    // 0x80802120: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802124: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802128: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080212C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80802130: jal         0x80085998
    // 0x80802134: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_166;
    // 0x80802134: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_166:
    // 0x80802138: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080213C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802140: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802144: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80802148: jal         0x80085998
    // 0x8080214C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_167;
    // 0x8080214C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_167:
    // 0x80802150: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802154: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802158: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080215C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80802160: jal         0x80085998
    // 0x80802164: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_168;
    // 0x80802164: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_168:
    // 0x80802168: b           L_80805794
    // 0x8080216C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x8080216C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802170:
    // 0x80802170: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80802174: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80802178: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8080217C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802180: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802184: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80802188: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8080218C: jal         0x80085998
    // 0x80802190: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_169;
    // 0x80802190: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_169:
    // 0x80802194: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802198: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8080219C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808021A0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808021A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808021A8: jal         0x80085998
    // 0x808021AC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_170;
    // 0x808021AC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_170:
    // 0x808021B0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808021B4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808021B8: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808021BC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808021C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808021C4: jal         0x80085998
    // 0x808021C8: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_171;
    // 0x808021C8: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_171:
    // 0x808021CC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808021D0: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808021D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808021D8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x808021DC: jal         0x80085998
    // 0x808021E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_172;
    // 0x808021E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_172:
    // 0x808021E4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808021E8: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808021EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808021F0: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x808021F4: jal         0x80085998
    // 0x808021F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_173;
    // 0x808021F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_173:
    // 0x808021FC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802200: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802204: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802208: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8080220C: jal         0x80085998
    // 0x80802210: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_174;
    // 0x80802210: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_174:
    // 0x80802214: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802218: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x8080221C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802220: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80802224: jal         0x80085998
    // 0x80802228: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_175;
    // 0x80802228: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_175:
    // 0x8080222C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802230: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80802234: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802238: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8080223C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802240: jal         0x80085998
    // 0x80802244: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_176;
    // 0x80802244: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_176:
    // 0x80802248: b           L_80805794
    // 0x8080224C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x8080224C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802250:
    // 0x80802250: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6904) << 16);
    // 0x80802254: lwc1        $f20, 0x6904($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6904));
    // 0x80802258: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8080225C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80802260: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802264: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802268: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8080226C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80802270: jal         0x80085998
    // 0x80802274: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_177;
    // 0x80802274: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_177:
    // 0x80802278: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080227C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80802280: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802284: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802288: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080228C: jal         0x80085998
    // 0x80802290: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_178;
    // 0x80802290: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_178:
    // 0x80802294: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802298: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080229C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808022A0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808022A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808022A8: jal         0x80085998
    // 0x808022AC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_179;
    // 0x808022AC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_179:
    // 0x808022B0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808022B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808022B8: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808022BC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808022C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808022C4: jal         0x80085998
    // 0x808022C8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_180;
    // 0x808022C8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_180:
    // 0x808022CC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808022D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808022D4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808022D8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808022DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808022E0: jal         0x80085998
    // 0x808022E4: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_181;
    // 0x808022E4: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_181:
    // 0x808022E8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808022EC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808022F0: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808022F4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808022F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808022FC: jal         0x80085998
    // 0x80802300: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_182;
    // 0x80802300: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_182:
    // 0x80802304: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802308: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8080230C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802310: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80802314: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802318: jal         0x80085998
    // 0x8080231C: addiu       $a3, $zero, 0x33
    ctx->r7 = ADD32(0, 0X33);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_183;
    // 0x8080231C: addiu       $a3, $zero, 0x33
    ctx->r7 = ADD32(0, 0X33);
    after_183:
    // 0x80802320: b           L_80805794
    // 0x80802324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80802324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802328:
    // 0x80802328: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6908) << 16);
    // 0x8080232C: lwc1        $f20, 0x6908($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6908));
    // 0x80802330: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80802334: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80802338: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080233C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802340: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80802344: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80802348: jal         0x80085998
    // 0x8080234C: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_184;
    // 0x8080234C: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_184:
    // 0x80802350: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802354: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802358: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080235C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80802360: jal         0x80085998
    // 0x80802364: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_185;
    // 0x80802364: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_185:
    // 0x80802368: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080236C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802370: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802374: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    // 0x80802378: jal         0x80085998
    // 0x8080237C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_186;
    // 0x8080237C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_186:
    // 0x80802380: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802384: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802388: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080238C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80802390: jal         0x80085998
    // 0x80802394: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_187;
    // 0x80802394: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_187:
    // 0x80802398: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080239C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808023A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808023A4: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x808023A8: jal         0x80085998
    // 0x808023AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_188;
    // 0x808023AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_188:
    // 0x808023B0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808023B4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808023B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808023BC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x808023C0: jal         0x80085998
    // 0x808023C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_189;
    // 0x808023C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_189:
    // 0x808023C8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808023CC: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808023D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808023D4: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x808023D8: jal         0x80085998
    // 0x808023DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_190;
    // 0x808023DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_190:
    // 0x808023E0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808023E4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808023E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808023EC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x808023F0: jal         0x80085998
    // 0x808023F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_191;
    // 0x808023F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_191:
    // 0x808023F8: b           L_80805794
    // 0x808023FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x808023FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802400:
    // 0x80802400: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X690C) << 16);
    // 0x80802404: lwc1        $f20, 0x690C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X690C));
    // 0x80802408: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080240C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80802410: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802414: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80802418: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080241C: jal         0x80085998
    // 0x80802420: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_192;
    // 0x80802420: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_192:
    // 0x80802424: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802428: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8080242C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802430: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80802434: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802438: jal         0x80085998
    // 0x8080243C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_193;
    // 0x8080243C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_193:
    // 0x80802440: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802444: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802448: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080244C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80802450: jal         0x80085998
    // 0x80802454: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_194;
    // 0x80802454: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_194:
    // 0x80802458: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080245C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80802460: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802464: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80802468: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080246C: jal         0x80085998
    // 0x80802470: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_195;
    // 0x80802470: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_195:
    // 0x80802474: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802478: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x8080247C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802480: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80802484: jal         0x80085998
    // 0x80802488: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_196;
    // 0x80802488: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_196:
    // 0x8080248C: b           L_80805794
    // 0x80802490: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80802490: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802494:
    // 0x80802494: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6910) << 16);
    // 0x80802498: lwc1        $f20, 0x6910($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6910));
    // 0x8080249C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808024A0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808024A4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808024A8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x808024AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808024B0: jal         0x80085998
    // 0x808024B4: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_197;
    // 0x808024B4: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_197:
    // 0x808024B8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808024BC: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808024C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808024C4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808024C8: jal         0x80085998
    // 0x808024CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_198;
    // 0x808024CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_198:
    // 0x808024D0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808024D4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808024D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808024DC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x808024E0: jal         0x80085998
    // 0x808024E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_199;
    // 0x808024E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_199:
    // 0x808024E8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808024EC: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808024F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808024F4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x808024F8: jal         0x80085998
    // 0x808024FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_200;
    // 0x808024FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_200:
    // 0x80802500: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802504: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802508: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080250C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80802510: jal         0x80085998
    // 0x80802514: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_201;
    // 0x80802514: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_201:
    // 0x80802518: b           L_80805794
    // 0x8080251C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x8080251C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802520:
    // 0x80802520: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6914) << 16);
    // 0x80802524: lwc1        $f20, 0x6914($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6914));
    // 0x80802528: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080252C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80802530: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802534: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80802538: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080253C: jal         0x80085998
    // 0x80802540: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_202;
    // 0x80802540: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_202:
    // 0x80802544: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802548: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x8080254C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802550: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80802554: jal         0x80085998
    // 0x80802558: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_203;
    // 0x80802558: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_203:
    // 0x8080255C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802560: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802564: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802568: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8080256C: jal         0x80085998
    // 0x80802570: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_204;
    // 0x80802570: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_204:
    // 0x80802574: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802578: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x8080257C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802580: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80802584: jal         0x80085998
    // 0x80802588: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_205;
    // 0x80802588: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_205:
    // 0x8080258C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802590: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802594: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802598: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x8080259C: jal         0x80085998
    // 0x808025A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_206;
    // 0x808025A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_206:
    // 0x808025A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X70D4) << 16);
    // 0x808025A8: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808025AC: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X70F8) << 16);
    // 0x808025B0: addiu       $s1, $s1, 0x70F8
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X70F8));
    // 0x808025B4: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x808025B8: addiu       $v0, $v0, 0x70D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X70D4));
    // 0x808025BC: addiu       $t5, $zero, 0x17
    ctx->r13 = ADD32(0, 0X17);
L_808025C0:
    // 0x808025C0: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x808025C4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808025C8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808025CC: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x808025D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808025D4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808025D8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808025DC: jal         0x80082630
    // 0x808025E0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_207;
    // 0x808025E0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_207:
    // 0x808025E4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808025E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808025EC: bnel        $v0, $s1, L_808025C0
    if (ctx->r2 != ctx->r17) {
        // 0x808025F0: addiu       $t5, $zero, 0x17
        ctx->r13 = ADD32(0, 0X17);
            goto L_808025C0;
    }
    goto skip_92;
    // 0x808025F0: addiu       $t5, $zero, 0x17
    ctx->r13 = ADD32(0, 0X17);
    skip_92:
    // 0x808025F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X70F8) << 16);
    // 0x808025F8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7120) << 16);
    // 0x808025FC: addiu       $s1, $s1, 0x7120
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7120));
    // 0x80802600: addiu       $v0, $v0, 0x70F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X70F8));
    // 0x80802604: addiu       $t7, $zero, 0x17
    ctx->r15 = ADD32(0, 0X17);
L_80802608:
    // 0x80802608: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8080260C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80802610: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802614: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802618: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080261C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80802620: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802624: jal         0x80082630
    // 0x80802628: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_208;
    // 0x80802628: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_208:
    // 0x8080262C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80802630: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80802634: bnel        $v0, $s1, L_80802608
    if (ctx->r2 != ctx->r17) {
        // 0x80802638: addiu       $t7, $zero, 0x17
        ctx->r15 = ADD32(0, 0X17);
            goto L_80802608;
    }
    goto skip_93;
    // 0x80802638: addiu       $t7, $zero, 0x17
    ctx->r15 = ADD32(0, 0X17);
    skip_93:
    // 0x8080263C: lui         $a1, 0x3F6A
    ctx->r5 = S32(0X3F6A << 16);
    // 0x80802640: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80802644: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80802648: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8080264C: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802650: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80802654: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80802658: addiu       $a2, $a2, -0x7088
    ctx->r6 = ADD32(ctx->r6, -0X7088);
    // 0x8080265C: ori         $a1, $a1, 0x4A8C
    ctx->r5 = ctx->r5 | 0X4A8C;
    // 0x80802660: jal         0x80082630
    // 0x80802664: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_209;
    // 0x80802664: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_209:
    // 0x80802668: b           L_80805794
    // 0x8080266C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x8080266C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802670:
    // 0x80802670: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6918) << 16);
    // 0x80802674: lwc1        $f20, 0x6918($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6918));
    // 0x80802678: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080267C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80802680: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802684: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80802688: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080268C: jal         0x80085998
    // 0x80802690: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_210;
    // 0x80802690: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_210:
    // 0x80802694: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802698: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x8080269C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808026A0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808026A4: jal         0x80085998
    // 0x808026A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_211;
    // 0x808026A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_211:
    // 0x808026AC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808026B0: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808026B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808026B8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x808026BC: jal         0x80085998
    // 0x808026C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_212;
    // 0x808026C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_212:
    // 0x808026C4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808026C8: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808026CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808026D0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x808026D4: jal         0x80085998
    // 0x808026D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_213;
    // 0x808026D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_213:
    // 0x808026DC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808026E0: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808026E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808026E8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x808026EC: jal         0x80085998
    // 0x808026F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_214;
    // 0x808026F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_214:
    // 0x808026F4: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808026F8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7120) << 16);
    // 0x808026FC: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7144) << 16);
    // 0x80802700: addiu       $s1, $s1, 0x7144
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7144));
    // 0x80802704: addiu       $v0, $v0, 0x7120
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7120));
    // 0x80802708: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x8080270C: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
L_80802710:
    // 0x80802710: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x80802714: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80802718: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8080271C: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802720: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802724: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80802728: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080272C: jal         0x80082630
    // 0x80802730: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_215;
    // 0x80802730: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_215:
    // 0x80802734: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80802738: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080273C: bnel        $v0, $s1, L_80802710
    if (ctx->r2 != ctx->r17) {
        // 0x80802740: addiu       $t1, $zero, 0xD
        ctx->r9 = ADD32(0, 0XD);
            goto L_80802710;
    }
    goto skip_94;
    // 0x80802740: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
    skip_94:
    // 0x80802744: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7120) << 16);
    // 0x80802748: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7144) << 16);
    // 0x8080274C: addiu       $s1, $s1, 0x7144
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7144));
    // 0x80802750: addiu       $v0, $v0, 0x7120
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7120));
    // 0x80802754: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
L_80802758:
    // 0x80802758: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x8080275C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80802760: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80802764: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802768: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080276C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80802770: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802774: jal         0x80082630
    // 0x80802778: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_216;
    // 0x80802778: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_216:
    // 0x8080277C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80802780: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80802784: bnel        $v0, $s1, L_80802758
    if (ctx->r2 != ctx->r17) {
        // 0x80802788: addiu       $t3, $zero, 0xD
        ctx->r11 = ADD32(0, 0XD);
            goto L_80802758;
    }
    goto skip_95;
    // 0x80802788: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
    skip_95:
    // 0x8080278C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7144) << 16);
    // 0x80802790: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X716C) << 16);
    // 0x80802794: addiu       $s1, $s1, 0x716C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X716C));
    // 0x80802798: addiu       $v0, $v0, 0x7144
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7144));
    // 0x8080279C: addiu       $t5, $zero, 0xD
    ctx->r13 = ADD32(0, 0XD);
L_808027A0:
    // 0x808027A0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x808027A4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808027A8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808027AC: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x808027B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808027B4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808027B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808027BC: jal         0x80082630
    // 0x808027C0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_217;
    // 0x808027C0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_217:
    // 0x808027C4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808027C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808027CC: bnel        $v0, $s1, L_808027A0
    if (ctx->r2 != ctx->r17) {
        // 0x808027D0: addiu       $t5, $zero, 0xD
        ctx->r13 = ADD32(0, 0XD);
            goto L_808027A0;
    }
    goto skip_96;
    // 0x808027D0: addiu       $t5, $zero, 0xD
    ctx->r13 = ADD32(0, 0XD);
    skip_96:
    // 0x808027D4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7144) << 16);
    // 0x808027D8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X716C) << 16);
    // 0x808027DC: addiu       $s1, $s1, 0x716C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X716C));
    // 0x808027E0: addiu       $v0, $v0, 0x7144
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7144));
    // 0x808027E4: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
L_808027E8:
    // 0x808027E8: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x808027EC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808027F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808027F4: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x808027F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808027FC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80802800: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802804: jal         0x80082630
    // 0x80802808: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_218;
    // 0x80802808: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_218:
    // 0x8080280C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80802810: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80802814: bnel        $v0, $s1, L_808027E8
    if (ctx->r2 != ctx->r17) {
        // 0x80802818: addiu       $t7, $zero, 0xD
        ctx->r15 = ADD32(0, 0XD);
            goto L_808027E8;
    }
    goto skip_97;
    // 0x80802818: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    skip_97:
    // 0x8080281C: b           L_80805794
    // 0x80802820: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80802820: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802824:
    // 0x80802824: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X691C) << 16);
    // 0x80802828: lwc1        $f20, 0x691C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X691C));
    // 0x8080282C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802830: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80802834: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802838: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8080283C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80802840: jal         0x80085998
    // 0x80802844: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_219;
    // 0x80802844: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_219:
    // 0x80802848: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080284C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802850: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802854: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80802858: jal         0x80085998
    // 0x8080285C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_220;
    // 0x8080285C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_220:
    // 0x80802860: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802864: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802868: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080286C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80802870: jal         0x80085998
    // 0x80802874: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_221;
    // 0x80802874: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_221:
    // 0x80802878: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080287C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802880: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802884: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80802888: jal         0x80085998
    // 0x8080288C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_222;
    // 0x8080288C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_222:
    // 0x80802890: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802894: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802898: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080289C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x808028A0: jal         0x80085998
    // 0x808028A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_223;
    // 0x808028A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_223:
    // 0x808028A8: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808028AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X716C) << 16);
    // 0x808028B0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7190) << 16);
    // 0x808028B4: addiu       $s1, $s1, 0x7190
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7190));
    // 0x808028B8: addiu       $v0, $v0, 0x716C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X716C));
    // 0x808028BC: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x808028C0: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
L_808028C4:
    // 0x808028C4: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x808028C8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808028CC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808028D0: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x808028D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808028D8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808028DC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808028E0: jal         0x80082630
    // 0x808028E4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_224;
    // 0x808028E4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_224:
    // 0x808028E8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808028EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808028F0: bnel        $v0, $s1, L_808028C4
    if (ctx->r2 != ctx->r17) {
        // 0x808028F4: addiu       $t9, $zero, 0xD
        ctx->r25 = ADD32(0, 0XD);
            goto L_808028C4;
    }
    goto skip_98;
    // 0x808028F4: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
    skip_98:
    // 0x808028F8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X716C) << 16);
    // 0x808028FC: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7190) << 16);
    // 0x80802900: addiu       $s1, $s1, 0x7190
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7190));
    // 0x80802904: addiu       $v0, $v0, 0x716C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X716C));
    // 0x80802908: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
L_8080290C:
    // 0x8080290C: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80802910: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80802914: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80802918: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x8080291C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802920: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80802924: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802928: jal         0x80082630
    // 0x8080292C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_225;
    // 0x8080292C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_225:
    // 0x80802930: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80802934: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80802938: bnel        $v0, $s1, L_8080290C
    if (ctx->r2 != ctx->r17) {
        // 0x8080293C: addiu       $t1, $zero, 0xD
        ctx->r9 = ADD32(0, 0XD);
            goto L_8080290C;
    }
    goto skip_99;
    // 0x8080293C: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
    skip_99:
    // 0x80802940: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7190) << 16);
    // 0x80802944: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X71B8) << 16);
    // 0x80802948: addiu       $s1, $s1, 0x71B8
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X71B8));
    // 0x8080294C: addiu       $v0, $v0, 0x7190
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7190));
    // 0x80802950: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
L_80802954:
    // 0x80802954: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80802958: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8080295C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80802960: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802964: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802968: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080296C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802970: jal         0x80082630
    // 0x80802974: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_226;
    // 0x80802974: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_226:
    // 0x80802978: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080297C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80802980: bnel        $v0, $s1, L_80802954
    if (ctx->r2 != ctx->r17) {
        // 0x80802984: addiu       $t3, $zero, 0xD
        ctx->r11 = ADD32(0, 0XD);
            goto L_80802954;
    }
    goto skip_100;
    // 0x80802984: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
    skip_100:
    // 0x80802988: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7190) << 16);
    // 0x8080298C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X71B8) << 16);
    // 0x80802990: addiu       $s1, $s1, 0x71B8
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X71B8));
    // 0x80802994: addiu       $v0, $v0, 0x7190
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7190));
    // 0x80802998: addiu       $t5, $zero, 0xD
    ctx->r13 = ADD32(0, 0XD);
L_8080299C:
    // 0x8080299C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x808029A0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808029A4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808029A8: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x808029AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808029B0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808029B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808029B8: jal         0x80082630
    // 0x808029BC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_227;
    // 0x808029BC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_227:
    // 0x808029C0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808029C4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808029C8: bnel        $v0, $s1, L_8080299C
    if (ctx->r2 != ctx->r17) {
        // 0x808029CC: addiu       $t5, $zero, 0xD
        ctx->r13 = ADD32(0, 0XD);
            goto L_8080299C;
    }
    goto skip_101;
    // 0x808029CC: addiu       $t5, $zero, 0xD
    ctx->r13 = ADD32(0, 0XD);
    skip_101:
    // 0x808029D0: b           L_80805794
    // 0x808029D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x808029D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808029D8:
    // 0x808029D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6920) << 16);
    // 0x808029DC: lwc1        $f20, 0x6920($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6920));
    // 0x808029E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808029E4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808029E8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808029EC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x808029F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808029F4: jal         0x80085998
    // 0x808029F8: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_228;
    // 0x808029F8: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_228:
    // 0x808029FC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802A00: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80802A04: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802A08: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802A0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802A10: jal         0x80085998
    // 0x80802A14: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_229;
    // 0x80802A14: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_229:
    // 0x80802A18: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802A1C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80802A20: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802A24: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80802A28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802A2C: jal         0x80085998
    // 0x80802A30: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_230;
    // 0x80802A30: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_230:
    // 0x80802A34: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802A38: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802A3C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802A40: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80802A44: jal         0x80085998
    // 0x80802A48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_231;
    // 0x80802A48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_231:
    // 0x80802A4C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802A50: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802A54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802A58: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80802A5C: jal         0x80085998
    // 0x80802A60: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_232;
    // 0x80802A60: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_232:
    // 0x80802A64: b           L_80805794
    // 0x80802A68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80802A68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802A6C:
    // 0x80802A6C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6924) << 16);
    // 0x80802A70: lwc1        $f20, 0x6924($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6924));
    // 0x80802A74: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802A78: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80802A7C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802A80: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80802A84: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80802A88: jal         0x80085998
    // 0x80802A8C: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_233;
    // 0x80802A8C: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_233:
    // 0x80802A90: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802A94: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802A98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802A9C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80802AA0: jal         0x80085998
    // 0x80802AA4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_234;
    // 0x80802AA4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_234:
    // 0x80802AA8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802AAC: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802AB0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802AB4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80802AB8: jal         0x80085998
    // 0x80802ABC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_235;
    // 0x80802ABC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_235:
    // 0x80802AC0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802AC4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802AC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802ACC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80802AD0: jal         0x80085998
    // 0x80802AD4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_236;
    // 0x80802AD4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_236:
    // 0x80802AD8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802ADC: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802AE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802AE4: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80802AE8: jal         0x80085998
    // 0x80802AEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_237;
    // 0x80802AEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_237:
    // 0x80802AF0: lui         $a1, 0x3DA3
    ctx->r5 = S32(0X3DA3 << 16);
    // 0x80802AF4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80802AF8: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802AFC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80802B00: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80802B04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802B08: jal         0x80085998
    // 0x80802B0C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_238;
    // 0x80802B0C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_238:
    // 0x80802B10: lui         $a1, 0x3F78
    ctx->r5 = S32(0X3F78 << 16);
    // 0x80802B14: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802B18: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x80802B1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802B20: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80802B24: jal         0x80085998
    // 0x80802B28: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_239;
    // 0x80802B28: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_239:
    // 0x80802B2C: b           L_80805794
    // 0x80802B30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80802B30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802B34:
    // 0x80802B34: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80802B38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802B3C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80802B40: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802B44: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80802B48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80802B4C: jal         0x80085998
    // 0x80802B50: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_240;
    // 0x80802B50: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_240:
    // 0x80802B54: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802B58: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802B5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802B60: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80802B64: jal         0x80085998
    // 0x80802B68: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_241;
    // 0x80802B68: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_241:
    // 0x80802B6C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802B70: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802B74: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802B78: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80802B7C: jal         0x80085998
    // 0x80802B80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_242;
    // 0x80802B80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_242:
    // 0x80802B84: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802B88: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802B8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802B90: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80802B94: jal         0x80085998
    // 0x80802B98: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_243;
    // 0x80802B98: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_243:
    // 0x80802B9C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802BA0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80802BA4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802BA8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80802BAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802BB0: jal         0x80085998
    // 0x80802BB4: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_244;
    // 0x80802BB4: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_244:
    // 0x80802BB8: b           L_80805794
    // 0x80802BBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80802BBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802BC0:
    // 0x80802BC0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80802BC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802BC8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80802BCC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802BD0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80802BD4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80802BD8: jal         0x80085998
    // 0x80802BDC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_245;
    // 0x80802BDC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_245:
    // 0x80802BE0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802BE4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802BE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802BEC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80802BF0: jal         0x80085998
    // 0x80802BF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_246;
    // 0x80802BF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_246:
    // 0x80802BF8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802BFC: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802C00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802C04: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80802C08: jal         0x80085998
    // 0x80802C0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_247;
    // 0x80802C0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_247:
    // 0x80802C10: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802C14: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802C18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802C1C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80802C20: jal         0x80085998
    // 0x80802C24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_248;
    // 0x80802C24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_248:
    // 0x80802C28: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802C2C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80802C30: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802C34: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80802C38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802C3C: jal         0x80085998
    // 0x80802C40: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_249;
    // 0x80802C40: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_249:
    // 0x80802C44: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802C48: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X71B8) << 16);
    // 0x80802C4C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X71C0) << 16);
    // 0x80802C50: addiu       $s1, $s1, 0x71C0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X71C0));
    // 0x80802C54: addiu       $v0, $v0, 0x71B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X71B8));
    // 0x80802C58: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x80802C5C: addiu       $t2, $zero, 0x19
    ctx->r10 = ADD32(0, 0X19);
L_80802C60:
    // 0x80802C60: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80802C64: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80802C68: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80802C6C: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802C70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802C74: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80802C78: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802C7C: jal         0x80082630
    // 0x80802C80: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_250;
    // 0x80802C80: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_250:
    // 0x80802C84: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80802C88: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80802C8C: bnel        $v0, $s1, L_80802C60
    if (ctx->r2 != ctx->r17) {
        // 0x80802C90: addiu       $t2, $zero, 0x19
        ctx->r10 = ADD32(0, 0X19);
            goto L_80802C60;
    }
    goto skip_102;
    // 0x80802C90: addiu       $t2, $zero, 0x19
    ctx->r10 = ADD32(0, 0X19);
    skip_102:
    // 0x80802C94: b           L_80805794
    // 0x80802C98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80802C98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802C9C:
    // 0x80802C9C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6928) << 16);
    // 0x80802CA0: lwc1        $f20, 0x6928($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6928));
    // 0x80802CA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802CA8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80802CAC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802CB0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80802CB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80802CB8: jal         0x80085998
    // 0x80802CBC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_251;
    // 0x80802CBC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_251:
    // 0x80802CC0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802CC4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802CC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802CCC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80802CD0: jal         0x80085998
    // 0x80802CD4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_252;
    // 0x80802CD4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_252:
    // 0x80802CD8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802CDC: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802CE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802CE4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80802CE8: jal         0x80085998
    // 0x80802CEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_253;
    // 0x80802CEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_253:
    // 0x80802CF0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802CF4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802CF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802CFC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80802D00: jal         0x80085998
    // 0x80802D04: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_254;
    // 0x80802D04: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_254:
    // 0x80802D08: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802D0C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80802D10: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802D14: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80802D18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802D1C: jal         0x80085998
    // 0x80802D20: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_255;
    // 0x80802D20: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_255:
    // 0x80802D24: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802D28: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80802D2C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802D30: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80802D34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802D38: jal         0x80085998
    // 0x80802D3C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_256;
    // 0x80802D3C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_256:
    // 0x80802D40: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802D44: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802D48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802D4C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80802D50: jal         0x80085998
    // 0x80802D54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_257;
    // 0x80802D54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_257:
    // 0x80802D58: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802D5C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802D60: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802D64: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80802D68: jal         0x80085998
    // 0x80802D6C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_258;
    // 0x80802D6C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_258:
    // 0x80802D70: b           L_80805794
    // 0x80802D74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80802D74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802D78:
    // 0x80802D78: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80802D7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802D80: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80802D84: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802D88: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80802D8C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80802D90: jal         0x80085998
    // 0x80802D94: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_259;
    // 0x80802D94: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_259:
    // 0x80802D98: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802D9C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802DA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802DA4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80802DA8: jal         0x80085998
    // 0x80802DAC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_260;
    // 0x80802DAC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_260:
    // 0x80802DB0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802DB4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802DB8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802DBC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80802DC0: jal         0x80085998
    // 0x80802DC4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_261;
    // 0x80802DC4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_261:
    // 0x80802DC8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802DCC: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802DD0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802DD4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80802DD8: jal         0x80085998
    // 0x80802DDC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_262;
    // 0x80802DDC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_262:
    // 0x80802DE0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802DE4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80802DE8: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802DEC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802DF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802DF4: jal         0x80085998
    // 0x80802DF8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_263;
    // 0x80802DF8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_263:
    // 0x80802DFC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802E00: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80802E04: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802E08: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802E0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802E10: jal         0x80085998
    // 0x80802E14: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_264;
    // 0x80802E14: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_264:
    // 0x80802E18: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802E1C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802E20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802E24: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80802E28: jal         0x80085998
    // 0x80802E2C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_265;
    // 0x80802E2C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_265:
    // 0x80802E30: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802E34: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80802E38: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802E3C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80802E40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802E44: jal         0x80085998
    // 0x80802E48: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_266;
    // 0x80802E48: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_266:
    // 0x80802E4C: b           L_80805794
    // 0x80802E50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80802E50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802E54:
    // 0x80802E54: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X692C) << 16);
    // 0x80802E58: lwc1        $f20, 0x692C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X692C));
    // 0x80802E5C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80802E60: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80802E64: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802E68: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802E6C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80802E70: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80802E74: jal         0x80085998
    // 0x80802E78: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_267;
    // 0x80802E78: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_267:
    // 0x80802E7C: b           L_80805794
    // 0x80802E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80802E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802E84:
    // 0x80802E84: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802E88: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X71C0) << 16);
    // 0x80802E8C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X71C8) << 16);
    // 0x80802E90: addiu       $s1, $s1, 0x71C8
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X71C8));
    // 0x80802E94: addiu       $v0, $v0, 0x71C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X71C0));
    // 0x80802E98: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x80802E9C: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    // 0x80802EA0: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
L_80802EA4:
    // 0x80802EA4: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80802EA8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80802EAC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80802EB0: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802EB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802EB8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80802EBC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802EC0: jal         0x80082630
    // 0x80802EC4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_268;
    // 0x80802EC4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_268:
    // 0x80802EC8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80802ECC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80802ED0: bnel        $v0, $s1, L_80802EA4
    if (ctx->r2 != ctx->r17) {
        // 0x80802ED4: addiu       $t0, $zero, 0x19
        ctx->r8 = ADD32(0, 0X19);
            goto L_80802EA4;
    }
    goto skip_103;
    // 0x80802ED4: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
    skip_103:
    // 0x80802ED8: b           L_80805794
    // 0x80802EDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80802EDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802EE0:
    // 0x80802EE0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6930) << 16);
    // 0x80802EE4: lwc1        $f20, 0x6930($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6930));
    // 0x80802EE8: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802EEC: addiu       $s0, $s0, -0x70A0
    ctx->r16 = ADD32(ctx->r16, -0X70A0);
    // 0x80802EF0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80802EF4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802EF8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80802EFC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802F00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802F04: jal         0x80082628
    // 0x80802F08: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _anseq_entrypoint_2(rdram, ctx);
        goto after_269;
    // 0x80802F08: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_269:
    // 0x80802F0C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80802F10: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802F14: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802F18: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80802F1C: jal         0x80082628
    // 0x80802F20: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_270;
    // 0x80802F20: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_270:
    // 0x80802F24: b           L_80805794
    // 0x80802F28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80802F28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802F2C:
    // 0x80802F2C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802F30: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X71C8) << 16);
    // 0x80802F34: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7238) << 16);
    // 0x80802F38: addiu       $s1, $s1, 0x7238
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7238));
    // 0x80802F3C: addiu       $v0, $v0, 0x71C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X71C8));
    // 0x80802F40: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x80802F44: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    // 0x80802F48: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80802F4C:
    // 0x80802F4C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80802F50: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80802F54: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80802F58: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802F5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802F60: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80802F64: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802F68: jal         0x80082630
    // 0x80802F6C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_271;
    // 0x80802F6C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_271:
    // 0x80802F70: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80802F74: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80802F78: bnel        $v0, $s1, L_80802F4C
    if (ctx->r2 != ctx->r17) {
        // 0x80802F7C: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80802F4C;
    }
    goto skip_104;
    // 0x80802F7C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    skip_104:
    // 0x80802F80: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X71C8) << 16);
    // 0x80802F84: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7238) << 16);
    // 0x80802F88: addiu       $s1, $s1, 0x7238
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7238));
    // 0x80802F8C: addiu       $v0, $v0, 0x71C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X71C8));
    // 0x80802F90: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_80802F94:
    // 0x80802F94: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x80802F98: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80802F9C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80802FA0: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802FA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802FA8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80802FAC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802FB0: jal         0x80082630
    // 0x80802FB4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_272;
    // 0x80802FB4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_272:
    // 0x80802FB8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80802FBC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80802FC0: bnel        $v0, $s1, L_80802F94
    if (ctx->r2 != ctx->r17) {
        // 0x80802FC4: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80802F94;
    }
    goto skip_105;
    // 0x80802FC4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_105:
    // 0x80802FC8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X71C8) << 16);
    // 0x80802FCC: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7238) << 16);
    // 0x80802FD0: addiu       $s1, $s1, 0x7238
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7238));
    // 0x80802FD4: addiu       $v0, $v0, 0x71C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X71C8));
    // 0x80802FD8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
L_80802FDC:
    // 0x80802FDC: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80802FE0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80802FE4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802FE8: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80802FEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802FF0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80802FF4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802FF8: jal         0x80082630
    // 0x80802FFC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_273;
    // 0x80802FFC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_273:
    // 0x80803000: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803004: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803008: bnel        $v0, $s1, L_80802FDC
    if (ctx->r2 != ctx->r17) {
        // 0x8080300C: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_80802FDC;
    }
    goto skip_106;
    // 0x8080300C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    skip_106:
    // 0x80803010: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7238) << 16);
    // 0x80803014: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7248) << 16);
    // 0x80803018: addiu       $s1, $s1, 0x7248
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7248));
    // 0x8080301C: addiu       $v0, $v0, 0x7238
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7238));
    // 0x80803020: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
L_80803024:
    // 0x80803024: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x80803028: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8080302C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80803030: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80803034: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803038: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080303C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803040: jal         0x80082630
    // 0x80803044: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_274;
    // 0x80803044: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_274:
    // 0x80803048: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080304C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803050: bnel        $v0, $s1, L_80803024
    if (ctx->r2 != ctx->r17) {
        // 0x80803054: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_80803024;
    }
    goto skip_107;
    // 0x80803054: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    skip_107:
    // 0x80803058: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7248) << 16);
    // 0x8080305C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7250) << 16);
    // 0x80803060: addiu       $s1, $s1, 0x7250
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7250));
    // 0x80803064: addiu       $v0, $v0, 0x7248
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7248));
    // 0x80803068: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
L_8080306C:
    // 0x8080306C: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80803070: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80803074: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80803078: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x8080307C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803080: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803084: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803088: jal         0x80082630
    // 0x8080308C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_275;
    // 0x8080308C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_275:
    // 0x80803090: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803094: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803098: bnel        $v0, $s1, L_8080306C
    if (ctx->r2 != ctx->r17) {
        // 0x8080309C: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_8080306C;
    }
    goto skip_108;
    // 0x8080309C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    skip_108:
    // 0x808030A0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7250) << 16);
    // 0x808030A4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7260) << 16);
    // 0x808030A8: addiu       $s1, $s1, 0x7260
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7260));
    // 0x808030AC: addiu       $v0, $v0, 0x7250
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7250));
    // 0x808030B0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
L_808030B4:
    // 0x808030B4: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x808030B8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x808030BC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808030C0: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x808030C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808030C8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808030CC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808030D0: jal         0x80082630
    // 0x808030D4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_276;
    // 0x808030D4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_276:
    // 0x808030D8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808030DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808030E0: bnel        $v0, $s1, L_808030B4
    if (ctx->r2 != ctx->r17) {
        // 0x808030E4: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_808030B4;
    }
    goto skip_109;
    // 0x808030E4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    skip_109:
    // 0x808030E8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7260) << 16);
    // 0x808030EC: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X726C) << 16);
    // 0x808030F0: addiu       $s1, $s1, 0x726C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X726C));
    // 0x808030F4: addiu       $v0, $v0, 0x7260
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7260));
    // 0x808030F8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
L_808030FC:
    // 0x808030FC: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80803100: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80803104: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80803108: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x8080310C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803110: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803114: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803118: jal         0x80082630
    // 0x8080311C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_277;
    // 0x8080311C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_277:
    // 0x80803120: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803124: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803128: bnel        $v0, $s1, L_808030FC
    if (ctx->r2 != ctx->r17) {
        // 0x8080312C: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_808030FC;
    }
    goto skip_110;
    // 0x8080312C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    skip_110:
    // 0x80803130: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X726C) << 16);
    // 0x80803134: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7274) << 16);
    // 0x80803138: addiu       $s1, $s1, 0x7274
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7274));
    // 0x8080313C: addiu       $v0, $v0, 0x726C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X726C));
    // 0x80803140: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_80803144:
    // 0x80803144: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x80803148: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8080314C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80803150: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80803154: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803158: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080315C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803160: jal         0x80082630
    // 0x80803164: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_278;
    // 0x80803164: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_278:
    // 0x80803168: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080316C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803170: bnel        $v0, $s1, L_80803144
    if (ctx->r2 != ctx->r17) {
        // 0x80803174: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80803144;
    }
    goto skip_111;
    // 0x80803174: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    skip_111:
    // 0x80803178: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7274) << 16);
    // 0x8080317C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7280) << 16);
    // 0x80803180: addiu       $s1, $s1, 0x7280
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7280));
    // 0x80803184: addiu       $v0, $v0, 0x7274
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7274));
    // 0x80803188: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
L_8080318C:
    // 0x8080318C: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x80803190: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80803194: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80803198: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x8080319C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808031A0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808031A4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808031A8: jal         0x80082630
    // 0x808031AC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_279;
    // 0x808031AC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_279:
    // 0x808031B0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808031B4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808031B8: bnel        $v0, $s1, L_8080318C
    if (ctx->r2 != ctx->r17) {
        // 0x808031BC: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8080318C;
    }
    goto skip_112;
    // 0x808031BC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    skip_112:
    // 0x808031C0: b           L_80805794
    // 0x808031C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x808031C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808031C8:
    // 0x808031C8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808031CC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808031D0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808031D4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808031D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808031DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808031E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808031E4: jal         0x80085998
    // 0x808031E8: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_280;
    // 0x808031E8: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_280:
    // 0x808031EC: b           L_80805794
    // 0x808031F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x808031F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808031F4:
    // 0x808031F4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808031F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808031FC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80803200: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80803204: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80803208: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080320C: jal         0x80085998
    // 0x80803210: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_281;
    // 0x80803210: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_281:
    // 0x80803214: b           L_80805794
    // 0x80803218: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80803218: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080321C:
    // 0x8080321C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80803220: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803224: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80803228: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080322C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80803230: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80803234: jal         0x80085998
    // 0x80803238: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_282;
    // 0x80803238: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_282:
    // 0x8080323C: lui         $a1, 0x3A83
    ctx->r5 = S32(0X3A83 << 16);
    // 0x80803240: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80803244: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80803248: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8080324C: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80803250: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80803254: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80803258: addiu       $a2, $a2, -0x7088
    ctx->r6 = ADD32(ctx->r6, -0X7088);
    // 0x8080325C: ori         $a1, $a1, 0x126F
    ctx->r5 = ctx->r5 | 0X126F;
    // 0x80803260: jal         0x80082630
    // 0x80803264: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_283;
    // 0x80803264: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_283:
    // 0x80803268: b           L_80805794
    // 0x8080326C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x8080326C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803270:
    // 0x80803270: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80803274: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7280) << 16);
    // 0x80803278: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x8080327C: addiu       $s1, $s1, 0x728C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x80803280: addiu       $v0, $v0, 0x7280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7280));
    // 0x80803284: addiu       $s0, $s0, -0x330
    ctx->r16 = ADD32(ctx->r16, -0X330);
    // 0x80803288: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8080328C:
    // 0x8080328C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80803290: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803294: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803298: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080329C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808032A0: jal         0x80082628
    // 0x808032A4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_284;
    // 0x808032A4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_284:
    // 0x808032A8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808032AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808032B0: bnel        $v0, $s1, L_8080328C
    if (ctx->r2 != ctx->r17) {
        // 0x808032B4: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8080328C;
    }
    goto skip_113;
    // 0x808032B4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    skip_113:
    // 0x808032B8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x808032BC: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x808032C0: addiu       $s1, $s1, 0x7298
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x808032C4: addiu       $v0, $v0, 0x728C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x808032C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808032CC:
    // 0x808032CC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808032D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808032D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808032D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808032DC: jal         0x80082628
    // 0x808032E0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_285;
    // 0x808032E0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_285:
    // 0x808032E4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808032E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808032EC: bnel        $v0, $s1, L_808032CC
    if (ctx->r2 != ctx->r17) {
        // 0x808032F0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808032CC;
    }
    goto skip_114;
    // 0x808032F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_114:
    // 0x808032F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7280) << 16);
    // 0x808032F8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x808032FC: addiu       $s1, $s1, 0x728C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x80803300: addiu       $v0, $v0, 0x7280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7280));
    // 0x80803304: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_80803308:
    // 0x80803308: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8080330C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803310: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803314: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803318: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8080331C: jal         0x80082628
    // 0x80803320: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_286;
    // 0x80803320: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_286:
    // 0x80803324: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803328: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080332C: bnel        $v0, $s1, L_80803308
    if (ctx->r2 != ctx->r17) {
        // 0x80803330: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80803308;
    }
    goto skip_115;
    // 0x80803330: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_115:
    // 0x80803334: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x80803338: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x8080333C: addiu       $s1, $s1, 0x7298
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x80803340: addiu       $v0, $v0, 0x728C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x80803344: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803348:
    // 0x80803348: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080334C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803350: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80803354: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80803358: jal         0x80082628
    // 0x8080335C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_287;
    // 0x8080335C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_287:
    // 0x80803360: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803364: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803368: bnel        $v0, $s1, L_80803348
    if (ctx->r2 != ctx->r17) {
        // 0x8080336C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803348;
    }
    goto skip_116;
    // 0x8080336C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_116:
    // 0x80803370: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7280) << 16);
    // 0x80803374: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x80803378: addiu       $s1, $s1, 0x728C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x8080337C: addiu       $v0, $v0, 0x7280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7280));
    // 0x80803380: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_80803384:
    // 0x80803384: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80803388: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080338C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803390: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803394: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80803398: jal         0x80082628
    // 0x8080339C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_288;
    // 0x8080339C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_288:
    // 0x808033A0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808033A4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808033A8: bnel        $v0, $s1, L_80803384
    if (ctx->r2 != ctx->r17) {
        // 0x808033AC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80803384;
    }
    goto skip_117;
    // 0x808033AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_117:
    // 0x808033B0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x808033B4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x808033B8: addiu       $s1, $s1, 0x7298
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x808033BC: addiu       $v0, $v0, 0x728C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x808033C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808033C4:
    // 0x808033C4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808033C8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808033CC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808033D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808033D4: jal         0x80082628
    // 0x808033D8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_289;
    // 0x808033D8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_289:
    // 0x808033DC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808033E0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808033E4: bnel        $v0, $s1, L_808033C4
    if (ctx->r2 != ctx->r17) {
        // 0x808033E8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808033C4;
    }
    goto skip_118;
    // 0x808033E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_118:
    // 0x808033EC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7280) << 16);
    // 0x808033F0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x808033F4: addiu       $s1, $s1, 0x728C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x808033F8: addiu       $v0, $v0, 0x7280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7280));
    // 0x808033FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80803400:
    // 0x80803400: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80803404: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803408: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080340C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803410: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80803414: jal         0x80082628
    // 0x80803418: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_290;
    // 0x80803418: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_290:
    // 0x8080341C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803420: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803424: bnel        $v0, $s1, L_80803400
    if (ctx->r2 != ctx->r17) {
        // 0x80803428: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80803400;
    }
    goto skip_119;
    // 0x80803428: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_119:
    // 0x8080342C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x80803430: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x80803434: addiu       $s1, $s1, 0x7298
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x80803438: addiu       $v0, $v0, 0x728C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x8080343C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803440:
    // 0x80803440: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803444: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803448: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8080344C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80803450: jal         0x80082628
    // 0x80803454: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_291;
    // 0x80803454: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_291:
    // 0x80803458: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080345C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803460: bnel        $v0, $s1, L_80803440
    if (ctx->r2 != ctx->r17) {
        // 0x80803464: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803440;
    }
    goto skip_120;
    // 0x80803464: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_120:
    // 0x80803468: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7280) << 16);
    // 0x8080346C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x80803470: addiu       $s1, $s1, 0x728C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x80803474: addiu       $v0, $v0, 0x7280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7280));
    // 0x80803478: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_8080347C:
    // 0x8080347C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80803480: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803484: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803488: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080348C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80803490: jal         0x80082628
    // 0x80803494: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_292;
    // 0x80803494: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_292:
    // 0x80803498: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080349C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808034A0: bnel        $v0, $s1, L_8080347C
    if (ctx->r2 != ctx->r17) {
        // 0x808034A4: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8080347C;
    }
    goto skip_121;
    // 0x808034A4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    skip_121:
    // 0x808034A8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x808034AC: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x808034B0: addiu       $s1, $s1, 0x7298
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x808034B4: addiu       $v0, $v0, 0x728C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x808034B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808034BC:
    // 0x808034BC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808034C0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808034C4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x808034C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808034CC: jal         0x80082628
    // 0x808034D0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_293;
    // 0x808034D0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_293:
    // 0x808034D4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808034D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808034DC: bnel        $v0, $s1, L_808034BC
    if (ctx->r2 != ctx->r17) {
        // 0x808034E0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808034BC;
    }
    goto skip_122;
    // 0x808034E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_122:
    // 0x808034E4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7280) << 16);
    // 0x808034E8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x808034EC: addiu       $s1, $s1, 0x728C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x808034F0: addiu       $v0, $v0, 0x7280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7280));
    // 0x808034F4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_808034F8:
    // 0x808034F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808034FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803500: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803504: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803508: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x8080350C: jal         0x80082628
    // 0x80803510: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_294;
    // 0x80803510: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_294:
    // 0x80803514: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803518: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080351C: bnel        $v0, $s1, L_808034F8
    if (ctx->r2 != ctx->r17) {
        // 0x80803520: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_808034F8;
    }
    goto skip_123;
    // 0x80803520: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    skip_123:
    // 0x80803524: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x80803528: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x8080352C: addiu       $s1, $s1, 0x7298
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x80803530: addiu       $v0, $v0, 0x728C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x80803534: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803538:
    // 0x80803538: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080353C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803540: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80803544: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80803548: jal         0x80082628
    // 0x8080354C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_295;
    // 0x8080354C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_295:
    // 0x80803550: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803554: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803558: bnel        $v0, $s1, L_80803538
    if (ctx->r2 != ctx->r17) {
        // 0x8080355C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803538;
    }
    goto skip_124;
    // 0x8080355C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_124:
    // 0x80803560: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x80803564: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x80803568: addiu       $s1, $s1, 0x72A4
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x8080356C: addiu       $v0, $v0, 0x7298
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x80803570: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80803574:
    // 0x80803574: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80803578: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080357C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803580: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803584: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80803588: jal         0x80082628
    // 0x8080358C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_296;
    // 0x8080358C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_296:
    // 0x80803590: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803594: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803598: bnel        $v0, $s1, L_80803574
    if (ctx->r2 != ctx->r17) {
        // 0x8080359C: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80803574;
    }
    goto skip_125;
    // 0x8080359C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    skip_125:
    // 0x808035A0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x808035A4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X72B0) << 16);
    // 0x808035A8: addiu       $s1, $s1, 0x72B0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X72B0));
    // 0x808035AC: addiu       $v0, $v0, 0x72A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x808035B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808035B4:
    // 0x808035B4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808035B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808035BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808035C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808035C4: jal         0x80082628
    // 0x808035C8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_297;
    // 0x808035C8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_297:
    // 0x808035CC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808035D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808035D4: bnel        $v0, $s1, L_808035B4
    if (ctx->r2 != ctx->r17) {
        // 0x808035D8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808035B4;
    }
    goto skip_126;
    // 0x808035D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_126:
    // 0x808035DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x808035E0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x808035E4: addiu       $s1, $s1, 0x72A4
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x808035E8: addiu       $v0, $v0, 0x7298
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x808035EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_808035F0:
    // 0x808035F0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808035F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808035F8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808035FC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803600: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80803604: jal         0x80082628
    // 0x80803608: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_298;
    // 0x80803608: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_298:
    // 0x8080360C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803610: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803614: bnel        $v0, $s1, L_808035F0
    if (ctx->r2 != ctx->r17) {
        // 0x80803618: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_808035F0;
    }
    goto skip_127;
    // 0x80803618: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_127:
    // 0x8080361C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x80803620: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X72B0) << 16);
    // 0x80803624: addiu       $s1, $s1, 0x72B0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X72B0));
    // 0x80803628: addiu       $v0, $v0, 0x72A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x8080362C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803630:
    // 0x80803630: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803634: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803638: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8080363C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80803640: jal         0x80082628
    // 0x80803644: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_299;
    // 0x80803644: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_299:
    // 0x80803648: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080364C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803650: bnel        $v0, $s1, L_80803630
    if (ctx->r2 != ctx->r17) {
        // 0x80803654: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803630;
    }
    goto skip_128;
    // 0x80803654: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_128:
    // 0x80803658: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x8080365C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x80803660: addiu       $s1, $s1, 0x72A4
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x80803664: addiu       $v0, $v0, 0x7298
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x80803668: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8080366C:
    // 0x8080366C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80803670: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803674: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803678: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080367C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80803680: jal         0x80082628
    // 0x80803684: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_300;
    // 0x80803684: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_300:
    // 0x80803688: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080368C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803690: bnel        $v0, $s1, L_8080366C
    if (ctx->r2 != ctx->r17) {
        // 0x80803694: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8080366C;
    }
    goto skip_129;
    // 0x80803694: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_129:
    // 0x80803698: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x8080369C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X72B0) << 16);
    // 0x808036A0: addiu       $s1, $s1, 0x72B0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X72B0));
    // 0x808036A4: addiu       $v0, $v0, 0x72A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x808036A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808036AC:
    // 0x808036AC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808036B0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808036B4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808036B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808036BC: jal         0x80082628
    // 0x808036C0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_301;
    // 0x808036C0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_301:
    // 0x808036C4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808036C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808036CC: bnel        $v0, $s1, L_808036AC
    if (ctx->r2 != ctx->r17) {
        // 0x808036D0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808036AC;
    }
    goto skip_130;
    // 0x808036D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_130:
    // 0x808036D4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x808036D8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x808036DC: addiu       $s1, $s1, 0x72A4
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x808036E0: addiu       $v0, $v0, 0x7298
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x808036E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_808036E8:
    // 0x808036E8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808036EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808036F0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808036F4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808036F8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x808036FC: jal         0x80082628
    // 0x80803700: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_302;
    // 0x80803700: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_302:
    // 0x80803704: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803708: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080370C: bnel        $v0, $s1, L_808036E8
    if (ctx->r2 != ctx->r17) {
        // 0x80803710: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_808036E8;
    }
    goto skip_131;
    // 0x80803710: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    skip_131:
    // 0x80803714: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x80803718: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X72B0) << 16);
    // 0x8080371C: addiu       $s1, $s1, 0x72B0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X72B0));
    // 0x80803720: addiu       $v0, $v0, 0x72A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x80803724: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803728:
    // 0x80803728: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080372C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803730: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80803734: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80803738: jal         0x80082628
    // 0x8080373C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_303;
    // 0x8080373C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_303:
    // 0x80803740: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803744: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803748: bnel        $v0, $s1, L_80803728
    if (ctx->r2 != ctx->r17) {
        // 0x8080374C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803728;
    }
    goto skip_132;
    // 0x8080374C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_132:
    // 0x80803750: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x80803754: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x80803758: addiu       $s1, $s1, 0x72A4
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x8080375C: addiu       $v0, $v0, 0x7298
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x80803760: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_80803764:
    // 0x80803764: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80803768: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080376C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803770: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803774: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80803778: jal         0x80082628
    // 0x8080377C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_304;
    // 0x8080377C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_304:
    // 0x80803780: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803784: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803788: bnel        $v0, $s1, L_80803764
    if (ctx->r2 != ctx->r17) {
        // 0x8080378C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80803764;
    }
    goto skip_133;
    // 0x8080378C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    skip_133:
    // 0x80803790: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x80803794: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X72B0) << 16);
    // 0x80803798: addiu       $s1, $s1, 0x72B0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X72B0));
    // 0x8080379C: addiu       $v0, $v0, 0x72A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x808037A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808037A4:
    // 0x808037A4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808037A8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808037AC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x808037B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808037B4: jal         0x80082628
    // 0x808037B8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_305;
    // 0x808037B8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_305:
    // 0x808037BC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808037C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808037C4: bnel        $v0, $s1, L_808037A4
    if (ctx->r2 != ctx->r17) {
        // 0x808037C8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808037A4;
    }
    goto skip_134;
    // 0x808037C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_134:
    // 0x808037CC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x808037D0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x808037D4: addiu       $s1, $s1, 0x72A4
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x808037D8: addiu       $v0, $v0, 0x7298
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x808037DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_808037E0:
    // 0x808037E0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808037E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808037E8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808037EC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808037F0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x808037F4: jal         0x80082628
    // 0x808037F8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_306;
    // 0x808037F8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_306:
    // 0x808037FC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803800: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803804: bnel        $v0, $s1, L_808037E0
    if (ctx->r2 != ctx->r17) {
        // 0x80803808: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_808037E0;
    }
    goto skip_135;
    // 0x80803808: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_135:
    // 0x8080380C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x80803810: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X72B0) << 16);
    // 0x80803814: addiu       $s1, $s1, 0x72B0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X72B0));
    // 0x80803818: addiu       $v0, $v0, 0x72A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x8080381C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803820:
    // 0x80803820: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803824: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803828: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x8080382C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80803830: jal         0x80082628
    // 0x80803834: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_307;
    // 0x80803834: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_307:
    // 0x80803838: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080383C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803840: bnel        $v0, $s1, L_80803820
    if (ctx->r2 != ctx->r17) {
        // 0x80803844: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803820;
    }
    goto skip_136;
    // 0x80803844: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_136:
    // 0x80803848: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8080384C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7280) << 16);
    // 0x80803850: lui         $s5, 0x95AF
    ctx->r21 = S32(0X95AF << 16);
    // 0x80803854: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x80803858: addiu       $s3, $s3, 0x728C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x8080385C: ori         $s5, $s5, 0xFF00
    ctx->r21 = ctx->r21 | 0XFF00;
    // 0x80803860: addiu       $v0, $v0, 0x7280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7280));
    // 0x80803864: addiu       $s1, $s1, -0x7078
    ctx->r17 = ADD32(ctx->r17, -0X7078);
    // 0x80803868: lui         $s0, 0x2
    ctx->r16 = S32(0X2 << 16);
    // 0x8080386C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803870:
    // 0x80803870: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803874: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80803878: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8080387C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80803880: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80803884: jal         0x80082630
    // 0x80803888: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_308;
    // 0x80803888: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_308:
    // 0x8080388C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803890: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803894: bnel        $v0, $s3, L_80803870
    if (ctx->r2 != ctx->r19) {
        // 0x80803898: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803870;
    }
    goto skip_137;
    // 0x80803898: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_137:
    // 0x8080389C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x808038A0: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x808038A4: lui         $s3, 0x6D87
    ctx->r19 = S32(0X6D87 << 16);
    // 0x808038A8: ori         $s3, $s3, 0xFF00
    ctx->r19 = ctx->r19 | 0XFF00;
    // 0x808038AC: addiu       $s4, $s4, 0x7298
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x808038B0: addiu       $v0, $v0, 0x728C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x808038B4: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
L_808038B8:
    // 0x808038B8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808038BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808038C0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808038C4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808038C8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808038CC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x808038D0: jal         0x80082630
    // 0x808038D4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_309;
    // 0x808038D4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_309:
    // 0x808038D8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808038DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808038E0: bnel        $v0, $s4, L_808038B8
    if (ctx->r2 != ctx->r20) {
        // 0x808038E4: addiu       $t6, $zero, 0x19
        ctx->r14 = ADD32(0, 0X19);
            goto L_808038B8;
    }
    goto skip_138;
    // 0x808038E4: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    skip_138:
    // 0x808038E8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x808038EC: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x808038F0: addiu       $s4, $s4, 0x72A4
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x808038F4: addiu       $v0, $v0, 0x7298
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x808038F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808038FC:
    // 0x808038FC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803900: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80803904: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80803908: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x8080390C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80803910: jal         0x80082630
    // 0x80803914: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_310;
    // 0x80803914: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_310:
    // 0x80803918: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080391C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803920: bnel        $v0, $s4, L_808038FC
    if (ctx->r2 != ctx->r20) {
        // 0x80803924: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808038FC;
    }
    goto skip_139;
    // 0x80803924: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_139:
    // 0x80803928: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x8080392C: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X72B0) << 16);
    // 0x80803930: addiu       $s4, $s4, 0x72B0
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X72B0));
    // 0x80803934: addiu       $v0, $v0, 0x72A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x80803938: addiu       $t7, $zero, 0x19
    ctx->r15 = ADD32(0, 0X19);
L_8080393C:
    // 0x8080393C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80803940: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803944: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803948: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8080394C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80803950: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80803954: jal         0x80082630
    // 0x80803958: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_311;
    // 0x80803958: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_311:
    // 0x8080395C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803960: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803964: bnel        $v0, $s4, L_8080393C
    if (ctx->r2 != ctx->r20) {
        // 0x80803968: addiu       $t7, $zero, 0x19
        ctx->r15 = ADD32(0, 0X19);
            goto L_8080393C;
    }
    goto skip_140;
    // 0x80803968: addiu       $t7, $zero, 0x19
    ctx->r15 = ADD32(0, 0X19);
    skip_140:
    // 0x8080396C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7280) << 16);
    // 0x80803970: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x80803974: addiu       $s4, $s4, 0x728C
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x80803978: addiu       $v0, $v0, 0x7280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7280));
    // 0x8080397C: lui         $s0, 0x4
    ctx->r16 = S32(0X4 << 16);
    // 0x80803980: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803984:
    // 0x80803984: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803988: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8080398C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80803990: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80803994: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80803998: jal         0x80082630
    // 0x8080399C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_312;
    // 0x8080399C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_312:
    // 0x808039A0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808039A4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808039A8: bnel        $v0, $s4, L_80803984
    if (ctx->r2 != ctx->r20) {
        // 0x808039AC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803984;
    }
    goto skip_141;
    // 0x808039AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_141:
    // 0x808039B0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x808039B4: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x808039B8: addiu       $s4, $s4, 0x7298
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x808039BC: addiu       $v0, $v0, 0x728C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x808039C0: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
L_808039C4:
    // 0x808039C4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808039C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808039CC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808039D0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808039D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808039D8: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x808039DC: jal         0x80082630
    // 0x808039E0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_313;
    // 0x808039E0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_313:
    // 0x808039E4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808039E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808039EC: bnel        $v0, $s4, L_808039C4
    if (ctx->r2 != ctx->r20) {
        // 0x808039F0: addiu       $t8, $zero, 0x19
        ctx->r24 = ADD32(0, 0X19);
            goto L_808039C4;
    }
    goto skip_142;
    // 0x808039F0: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
    skip_142:
    // 0x808039F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x808039F8: lui         $s4, 0x7CCB
    ctx->r20 = S32(0X7CCB << 16);
    // 0x808039FC: ori         $s4, $s4, 0xFF00
    ctx->r20 = ctx->r20 | 0XFF00;
    // 0x80803A00: addiu       $v0, $v0, 0x7298
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x80803A04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803A08:
    // 0x80803A08: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803A0C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80803A10: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80803A14: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80803A18: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80803A1C: jal         0x80082630
    // 0x80803A20: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_314;
    // 0x80803A20: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_314:
    // 0x80803A24: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803A28: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x80803A2C: addiu       $t9, $t9, 0x72A4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x80803A30: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803A34: bnel        $v0, $t9, L_80803A08
    if (ctx->r2 != ctx->r25) {
        // 0x80803A38: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803A08;
    }
    goto skip_143;
    // 0x80803A38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_143:
    // 0x80803A3C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x80803A40: addiu       $v0, $v0, 0x72A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x80803A44: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
L_80803A48:
    // 0x80803A48: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80803A4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803A50: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803A54: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80803A58: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80803A5C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80803A60: jal         0x80082630
    // 0x80803A64: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_315;
    // 0x80803A64: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_315:
    // 0x80803A68: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803A6C: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2958, 0X72B0) << 16);
    // 0x80803A70: addiu       $t1, $t1, 0x72B0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2958, 0X72B0));
    // 0x80803A74: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803A78: bnel        $v0, $t1, L_80803A48
    if (ctx->r2 != ctx->r9) {
        // 0x80803A7C: addiu       $t0, $zero, 0x19
        ctx->r8 = ADD32(0, 0X19);
            goto L_80803A48;
    }
    goto skip_144;
    // 0x80803A7C: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
    skip_144:
    // 0x80803A80: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7280) << 16);
    // 0x80803A84: addiu       $v0, $v0, 0x7280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7280));
    // 0x80803A88: lui         $s0, 0x5
    ctx->r16 = S32(0X5 << 16);
    // 0x80803A8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803A90:
    // 0x80803A90: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803A94: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80803A98: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80803A9C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80803AA0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80803AA4: jal         0x80082630
    // 0x80803AA8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_316;
    // 0x80803AA8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_316:
    // 0x80803AAC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803AB0: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x80803AB4: addiu       $t2, $t2, 0x728C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x80803AB8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803ABC: bnel        $v0, $t2, L_80803A90
    if (ctx->r2 != ctx->r10) {
        // 0x80803AC0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803A90;
    }
    goto skip_145;
    // 0x80803AC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_145:
    // 0x80803AC4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x80803AC8: addiu       $v0, $v0, 0x728C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x80803ACC: addiu       $t3, $zero, 0x19
    ctx->r11 = ADD32(0, 0X19);
L_80803AD0:
    // 0x80803AD0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80803AD4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803AD8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803ADC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80803AE0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80803AE4: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80803AE8: jal         0x80082630
    // 0x80803AEC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_317;
    // 0x80803AEC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_317:
    // 0x80803AF0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803AF4: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x80803AF8: addiu       $t4, $t4, 0x7298
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x80803AFC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803B00: bnel        $v0, $t4, L_80803AD0
    if (ctx->r2 != ctx->r12) {
        // 0x80803B04: addiu       $t3, $zero, 0x19
        ctx->r11 = ADD32(0, 0X19);
            goto L_80803AD0;
    }
    goto skip_146;
    // 0x80803B04: addiu       $t3, $zero, 0x19
    ctx->r11 = ADD32(0, 0X19);
    skip_146:
    // 0x80803B08: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x80803B0C: addiu       $v0, $v0, 0x7298
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x80803B10: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803B14:
    // 0x80803B14: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803B18: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80803B1C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80803B20: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80803B24: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80803B28: jal         0x80082630
    // 0x80803B2C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_318;
    // 0x80803B2C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_318:
    // 0x80803B30: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803B34: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x80803B38: addiu       $t5, $t5, 0x72A4
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x80803B3C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803B40: bnel        $v0, $t5, L_80803B14
    if (ctx->r2 != ctx->r13) {
        // 0x80803B44: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803B14;
    }
    goto skip_147;
    // 0x80803B44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_147:
    // 0x80803B48: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x80803B4C: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X72B0) << 16);
    // 0x80803B50: addiu       $s4, $s4, 0x72B0
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X72B0));
    // 0x80803B54: addiu       $v0, $v0, 0x72A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x80803B58: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
L_80803B5C:
    // 0x80803B5C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80803B60: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803B64: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803B68: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80803B6C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80803B70: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80803B74: jal         0x80082630
    // 0x80803B78: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_319;
    // 0x80803B78: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_319:
    // 0x80803B7C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803B80: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803B84: bnel        $v0, $s4, L_80803B5C
    if (ctx->r2 != ctx->r20) {
        // 0x80803B88: addiu       $t6, $zero, 0x19
        ctx->r14 = ADD32(0, 0X19);
            goto L_80803B5C;
    }
    goto skip_148;
    // 0x80803B88: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    skip_148:
    // 0x80803B8C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7280) << 16);
    // 0x80803B90: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x80803B94: addiu       $s4, $s4, 0x728C
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x80803B98: addiu       $v0, $v0, 0x7280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7280));
    // 0x80803B9C: lui         $s0, 0x7
    ctx->r16 = S32(0X7 << 16);
    // 0x80803BA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803BA4:
    // 0x80803BA4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803BA8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80803BAC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80803BB0: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80803BB4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80803BB8: jal         0x80082630
    // 0x80803BBC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_320;
    // 0x80803BBC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_320:
    // 0x80803BC0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803BC4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803BC8: bnel        $v0, $s4, L_80803BA4
    if (ctx->r2 != ctx->r20) {
        // 0x80803BCC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803BA4;
    }
    goto skip_149;
    // 0x80803BCC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_149:
    // 0x80803BD0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x80803BD4: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x80803BD8: addiu       $s4, $s4, 0x7298
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x80803BDC: addiu       $v0, $v0, 0x728C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x80803BE0: addiu       $t7, $zero, 0x19
    ctx->r15 = ADD32(0, 0X19);
L_80803BE4:
    // 0x80803BE4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80803BE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803BEC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803BF0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80803BF4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80803BF8: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80803BFC: jal         0x80082630
    // 0x80803C00: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_321;
    // 0x80803C00: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_321:
    // 0x80803C04: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803C08: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803C0C: bnel        $v0, $s4, L_80803BE4
    if (ctx->r2 != ctx->r20) {
        // 0x80803C10: addiu       $t7, $zero, 0x19
        ctx->r15 = ADD32(0, 0X19);
            goto L_80803BE4;
    }
    goto skip_150;
    // 0x80803C10: addiu       $t7, $zero, 0x19
    ctx->r15 = ADD32(0, 0X19);
    skip_150:
    // 0x80803C14: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x80803C18: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x80803C1C: addiu       $s4, $s4, 0x72A4
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x80803C20: addiu       $v0, $v0, 0x7298
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x80803C24: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803C28:
    // 0x80803C28: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803C2C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80803C30: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80803C34: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80803C38: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80803C3C: jal         0x80082630
    // 0x80803C40: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_322;
    // 0x80803C40: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_322:
    // 0x80803C44: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803C48: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803C4C: bnel        $v0, $s4, L_80803C28
    if (ctx->r2 != ctx->r20) {
        // 0x80803C50: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803C28;
    }
    goto skip_151;
    // 0x80803C50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_151:
    // 0x80803C54: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x80803C58: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X72B0) << 16);
    // 0x80803C5C: addiu       $s4, $s4, 0x72B0
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X72B0));
    // 0x80803C60: addiu       $v0, $v0, 0x72A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x80803C64: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
L_80803C68:
    // 0x80803C68: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80803C6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803C70: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803C74: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80803C78: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80803C7C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80803C80: jal         0x80082630
    // 0x80803C84: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_323;
    // 0x80803C84: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_323:
    // 0x80803C88: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803C8C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803C90: bnel        $v0, $s4, L_80803C68
    if (ctx->r2 != ctx->r20) {
        // 0x80803C94: addiu       $t8, $zero, 0x19
        ctx->r24 = ADD32(0, 0X19);
            goto L_80803C68;
    }
    goto skip_152;
    // 0x80803C94: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
    skip_152:
    // 0x80803C98: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7280) << 16);
    // 0x80803C9C: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x80803CA0: addiu       $s4, $s4, 0x728C
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x80803CA4: addiu       $v0, $v0, 0x7280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7280));
    // 0x80803CA8: lui         $s0, 0x8
    ctx->r16 = S32(0X8 << 16);
    // 0x80803CAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803CB0:
    // 0x80803CB0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803CB4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80803CB8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80803CBC: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80803CC0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80803CC4: jal         0x80082630
    // 0x80803CC8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_324;
    // 0x80803CC8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_324:
    // 0x80803CCC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803CD0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803CD4: bnel        $v0, $s4, L_80803CB0
    if (ctx->r2 != ctx->r20) {
        // 0x80803CD8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803CB0;
    }
    goto skip_153;
    // 0x80803CD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_153:
    // 0x80803CDC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X728C) << 16);
    // 0x80803CE0: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x80803CE4: addiu       $s4, $s4, 0x7298
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x80803CE8: addiu       $v0, $v0, 0x728C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X728C));
    // 0x80803CEC: addiu       $t9, $zero, 0x19
    ctx->r25 = ADD32(0, 0X19);
L_80803CF0:
    // 0x80803CF0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80803CF4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803CF8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803CFC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80803D00: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80803D04: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80803D08: jal         0x80082630
    // 0x80803D0C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_325;
    // 0x80803D0C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_325:
    // 0x80803D10: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803D14: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803D18: bnel        $v0, $s4, L_80803CF0
    if (ctx->r2 != ctx->r20) {
        // 0x80803D1C: addiu       $t9, $zero, 0x19
        ctx->r25 = ADD32(0, 0X19);
            goto L_80803CF0;
    }
    goto skip_154;
    // 0x80803D1C: addiu       $t9, $zero, 0x19
    ctx->r25 = ADD32(0, 0X19);
    skip_154:
    // 0x80803D20: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7298) << 16);
    // 0x80803D24: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x80803D28: addiu       $s4, $s4, 0x72A4
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x80803D2C: addiu       $v0, $v0, 0x7298
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7298));
    // 0x80803D30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803D34:
    // 0x80803D34: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803D38: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80803D3C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80803D40: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80803D44: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80803D48: jal         0x80082630
    // 0x80803D4C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_326;
    // 0x80803D4C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_326:
    // 0x80803D50: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803D54: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803D58: bnel        $v0, $s4, L_80803D34
    if (ctx->r2 != ctx->r20) {
        // 0x80803D5C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803D34;
    }
    goto skip_155;
    // 0x80803D5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_155:
    // 0x80803D60: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X72A4) << 16);
    // 0x80803D64: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X72B0) << 16);
    // 0x80803D68: addiu       $s4, $s4, 0x72B0
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X72B0));
    // 0x80803D6C: addiu       $v0, $v0, 0x72A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X72A4));
    // 0x80803D70: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
L_80803D74:
    // 0x80803D74: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80803D78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803D7C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803D80: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80803D84: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80803D88: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80803D8C: jal         0x80082630
    // 0x80803D90: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_327;
    // 0x80803D90: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_327:
    // 0x80803D94: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803D98: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803D9C: bnel        $v0, $s4, L_80803D74
    if (ctx->r2 != ctx->r20) {
        // 0x80803DA0: addiu       $t0, $zero, 0x19
        ctx->r8 = ADD32(0, 0X19);
            goto L_80803D74;
    }
    goto skip_156;
    // 0x80803DA0: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
    skip_156:
    // 0x80803DA4: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80803DA8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X72D8) << 16);
    // 0x80803DAC: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X72E0) << 16);
    // 0x80803DB0: addiu       $s1, $s1, 0x72E0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X72E0));
    // 0x80803DB4: addiu       $v0, $v0, 0x72D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X72D8));
    // 0x80803DB8: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80803DBC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80803DC0:
    // 0x80803DC0: addiu       $t2, $zero, -0x2
    ctx->r10 = ADD32(0, -0X2);
    // 0x80803DC4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80803DC8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80803DCC: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80803DD0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803DD4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803DD8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803DDC: jal         0x80082630
    // 0x80803DE0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_328;
    // 0x80803DE0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_328:
    // 0x80803DE4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803DE8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803DEC: bnel        $v0, $s1, L_80803DC0
    if (ctx->r2 != ctx->r17) {
        // 0x80803DF0: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80803DC0;
    }
    goto skip_157;
    // 0x80803DF0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_157:
    // 0x80803DF4: b           L_80805794
    // 0x80803DF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80803DF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803DFC:
    // 0x80803DFC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80803E00: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80803E04: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80803E08: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80803E0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803E10: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80803E14: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80803E18: jal         0x80085998
    // 0x80803E1C: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_329;
    // 0x80803E1C: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_329:
    // 0x80803E20: lui         $a1, 0x3A83
    ctx->r5 = S32(0X3A83 << 16);
    // 0x80803E24: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80803E28: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80803E2C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80803E30: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80803E34: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80803E38: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80803E3C: addiu       $a2, $a2, -0x7088
    ctx->r6 = ADD32(ctx->r6, -0X7088);
    // 0x80803E40: ori         $a1, $a1, 0x126F
    ctx->r5 = ctx->r5 | 0X126F;
    // 0x80803E44: jal         0x80082630
    // 0x80803E48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_330;
    // 0x80803E48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_330:
    // 0x80803E4C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80803E50: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X72E0) << 16);
    // 0x80803E54: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X730C) << 16);
    // 0x80803E58: addiu       $s1, $s1, 0x730C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X730C));
    // 0x80803E5C: addiu       $v0, $v0, 0x72E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X72E0));
    // 0x80803E60: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x80803E64: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
L_80803E68:
    // 0x80803E68: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80803E6C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80803E70: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80803E74: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80803E78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803E7C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803E80: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803E84: jal         0x80082630
    // 0x80803E88: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_331;
    // 0x80803E88: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_331:
    // 0x80803E8C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803E90: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803E94: bnel        $v0, $s1, L_80803E68
    if (ctx->r2 != ctx->r17) {
        // 0x80803E98: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_80803E68;
    }
    goto skip_158;
    // 0x80803E98: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    skip_158:
    // 0x80803E9C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X730C) << 16);
    // 0x80803EA0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7354) << 16);
    // 0x80803EA4: addiu       $s1, $s1, 0x7354
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7354));
    // 0x80803EA8: addiu       $v0, $v0, 0x730C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X730C));
    // 0x80803EAC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
L_80803EB0:
    // 0x80803EB0: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80803EB4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80803EB8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80803EBC: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80803EC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803EC4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803EC8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803ECC: jal         0x80082630
    // 0x80803ED0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_332;
    // 0x80803ED0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_332:
    // 0x80803ED4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803ED8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803EDC: bnel        $v0, $s1, L_80803EB0
    if (ctx->r2 != ctx->r17) {
        // 0x80803EE0: addiu       $t8, $zero, 0x4
        ctx->r24 = ADD32(0, 0X4);
            goto L_80803EB0;
    }
    goto skip_159;
    // 0x80803EE0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    skip_159:
    // 0x80803EE4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7354) << 16);
    // 0x80803EE8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X73A8) << 16);
    // 0x80803EEC: addiu       $s1, $s1, 0x73A8
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X73A8));
    // 0x80803EF0: addiu       $v0, $v0, 0x7354
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7354));
    // 0x80803EF4: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
L_80803EF8:
    // 0x80803EF8: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80803EFC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80803F00: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80803F04: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80803F08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803F0C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803F10: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803F14: jal         0x80082630
    // 0x80803F18: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_333;
    // 0x80803F18: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_333:
    // 0x80803F1C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803F20: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803F24: bnel        $v0, $s1, L_80803EF8
    if (ctx->r2 != ctx->r17) {
        // 0x80803F28: addiu       $t0, $zero, 0x4
        ctx->r8 = ADD32(0, 0X4);
            goto L_80803EF8;
    }
    goto skip_160;
    // 0x80803F28: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    skip_160:
    // 0x80803F2C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X73A8) << 16);
    // 0x80803F30: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7458) << 16);
    // 0x80803F34: addiu       $s1, $s1, 0x7458
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7458));
    // 0x80803F38: addiu       $v0, $v0, 0x73A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X73A8));
    // 0x80803F3C: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
L_80803F40:
    // 0x80803F40: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80803F44: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80803F48: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80803F4C: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80803F50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803F54: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80803F58: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803F5C: jal         0x80082630
    // 0x80803F60: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_334;
    // 0x80803F60: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_334:
    // 0x80803F64: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80803F68: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803F6C: bnel        $v0, $s1, L_80803F40
    if (ctx->r2 != ctx->r17) {
        // 0x80803F70: addiu       $t2, $zero, 0x5
        ctx->r10 = ADD32(0, 0X5);
            goto L_80803F40;
    }
    goto skip_161;
    // 0x80803F70: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    skip_161:
    // 0x80803F74: b           L_80805794
    // 0x80803F78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80803F78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803F7C:
    // 0x80803F7C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80803F80: addiu       $s0, $s0, -0x7088
    ctx->r16 = ADD32(ctx->r16, -0X7088);
    // 0x80803F84: lui         $a1, 0x3F32
    ctx->r5 = S32(0X3F32 << 16);
    // 0x80803F88: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80803F8C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80803F90: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80803F94: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80803F98: ori         $a1, $a1, 0x6E98
    ctx->r5 = ctx->r5 | 0X6E98;
    // 0x80803F9C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803FA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803FA4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80803FA8: jal         0x80082630
    // 0x80803FAC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_335;
    // 0x80803FAC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_335:
    // 0x80803FB0: lui         $a1, 0x3F7D
    ctx->r5 = S32(0X3F7D << 16);
    // 0x80803FB4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80803FB8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80803FBC: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80803FC0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80803FC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80803FC8: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    // 0x80803FCC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803FD0: jal         0x80082630
    // 0x80803FD4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_336;
    // 0x80803FD4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_336:
    // 0x80803FD8: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80803FDC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7458) << 16);
    // 0x80803FE0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X74AC) << 16);
    // 0x80803FE4: addiu       $s1, $s1, 0x74AC
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X74AC));
    // 0x80803FE8: addiu       $v0, $v0, 0x7458
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7458));
    // 0x80803FEC: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x80803FF0: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
L_80803FF4:
    // 0x80803FF4: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80803FF8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80803FFC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80804000: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80804004: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804008: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080400C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804010: jal         0x80082630
    // 0x80804014: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_337;
    // 0x80804014: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_337:
    // 0x80804018: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080401C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804020: bnel        $v0, $s1, L_80803FF4
    if (ctx->r2 != ctx->r17) {
        // 0x80804024: addiu       $t8, $zero, 0x5
        ctx->r24 = ADD32(0, 0X5);
            goto L_80803FF4;
    }
    goto skip_162;
    // 0x80804024: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    skip_162:
    // 0x80804028: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X74AC) << 16);
    // 0x8080402C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X74DC) << 16);
    // 0x80804030: addiu       $s1, $s1, 0x74DC
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X74DC));
    // 0x80804034: addiu       $v0, $v0, 0x74AC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X74AC));
    // 0x80804038: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
L_8080403C:
    // 0x8080403C: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80804040: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80804044: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80804048: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x8080404C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804050: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804054: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804058: jal         0x80082630
    // 0x8080405C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_338;
    // 0x8080405C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_338:
    // 0x80804060: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804064: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804068: bnel        $v0, $s1, L_8080403C
    if (ctx->r2 != ctx->r17) {
        // 0x8080406C: addiu       $t0, $zero, 0x5
        ctx->r8 = ADD32(0, 0X5);
            goto L_8080403C;
    }
    goto skip_163;
    // 0x8080406C: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    skip_163:
    // 0x80804070: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80804074: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80804078: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x8080407C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80804080: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80804084: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804088: jal         0x80085998
    // 0x8080408C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_339;
    // 0x8080408C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_339:
    // 0x80804090: b           L_80805794
    // 0x80804094: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80804094: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804098:
    // 0x80804098: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8080409C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X74DC) << 16);
    // 0x808040A0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X74E8) << 16);
    // 0x808040A4: addiu       $s1, $s1, 0x74E8
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X74E8));
    // 0x808040A8: addiu       $v0, $v0, 0x74DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X74DC));
    // 0x808040AC: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x808040B0: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    // 0x808040B4: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
L_808040B8:
    // 0x808040B8: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x808040BC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x808040C0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808040C4: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x808040C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808040CC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808040D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808040D4: jal         0x80082630
    // 0x808040D8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_340;
    // 0x808040D8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_340:
    // 0x808040DC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808040E0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808040E4: bnel        $v0, $s1, L_808040B8
    if (ctx->r2 != ctx->r17) {
        // 0x808040E8: addiu       $t3, $zero, 0x5
        ctx->r11 = ADD32(0, 0X5);
            goto L_808040B8;
    }
    goto skip_164;
    // 0x808040E8: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    skip_164:
    // 0x808040EC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808040F0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x808040F4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808040F8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808040FC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80804100: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804104: jal         0x80085998
    // 0x80804108: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_341;
    // 0x80804108: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_341:
    // 0x8080410C: b           L_80805794
    // 0x80804110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80804110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804114:
    // 0x80804114: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80804118: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X74E8) << 16);
    // 0x8080411C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7534) << 16);
    // 0x80804120: addiu       $s1, $s1, 0x7534
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7534));
    // 0x80804124: addiu       $v0, $v0, 0x74E8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X74E8));
    // 0x80804128: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x8080412C: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    // 0x80804130: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
L_80804134:
    // 0x80804134: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80804138: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8080413C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80804140: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80804144: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804148: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080414C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804150: jal         0x80082630
    // 0x80804154: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_342;
    // 0x80804154: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_342:
    // 0x80804158: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080415C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804160: bnel        $v0, $s1, L_80804134
    if (ctx->r2 != ctx->r17) {
        // 0x80804164: addiu       $t6, $zero, 0xA
        ctx->r14 = ADD32(0, 0XA);
            goto L_80804134;
    }
    goto skip_165;
    // 0x80804164: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    skip_165:
    // 0x80804168: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X74E8) << 16);
    // 0x8080416C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7534) << 16);
    // 0x80804170: addiu       $s1, $s1, 0x7534
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7534));
    // 0x80804174: addiu       $v0, $v0, 0x74E8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X74E8));
    // 0x80804178: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
L_8080417C:
    // 0x8080417C: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x80804180: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80804184: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80804188: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x8080418C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804190: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804194: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804198: jal         0x80082630
    // 0x8080419C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_343;
    // 0x8080419C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_343:
    // 0x808041A0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808041A4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808041A8: bnel        $v0, $s1, L_8080417C
    if (ctx->r2 != ctx->r17) {
        // 0x808041AC: addiu       $t8, $zero, 0xA
        ctx->r24 = ADD32(0, 0XA);
            goto L_8080417C;
    }
    goto skip_166;
    // 0x808041AC: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    skip_166:
    // 0x808041B0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808041B4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808041B8: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808041BC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808041C0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808041C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808041C8: jal         0x80085998
    // 0x808041CC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_344;
    // 0x808041CC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_344:
    // 0x808041D0: b           L_80805794
    // 0x808041D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x808041D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808041D8:
    // 0x808041D8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808041DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808041E0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808041E4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808041E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808041EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808041F0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808041F4: jal         0x80085998
    // 0x808041F8: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_345;
    // 0x808041F8: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_345:
    // 0x808041FC: b           L_80805794
    // 0x80804200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80804200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804204:
    // 0x80804204: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80804208: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8080420C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80804210: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80804214: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804218: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8080421C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80804220: jal         0x80085998
    // 0x80804224: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_346;
    // 0x80804224: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_346:
    // 0x80804228: b           L_80805794
    // 0x8080422C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x8080422C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804230:
    // 0x80804230: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80804234: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80804238: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8080423C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80804240: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804244: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80804248: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8080424C: jal         0x80085998
    // 0x80804250: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_347;
    // 0x80804250: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_347:
    // 0x80804254: lui         $a1, 0x3EE1
    ctx->r5 = S32(0X3EE1 << 16);
    // 0x80804258: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8080425C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80804260: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80804264: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80804268: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8080426C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80804270: addiu       $a2, $a2, -0x7088
    ctx->r6 = ADD32(ctx->r6, -0X7088);
    // 0x80804274: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    // 0x80804278: jal         0x80082630
    // 0x8080427C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_348;
    // 0x8080427C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_348:
    // 0x80804280: b           L_80805794
    // 0x80804284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80804284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804288:
    // 0x80804288: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8080428C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804290: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80804294: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80804298: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8080429C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808042A0: jal         0x80085998
    // 0x808042A4: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_349;
    // 0x808042A4: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_349:
    // 0x808042A8: b           L_80805794
    // 0x808042AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x808042AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808042B0:
    // 0x808042B0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808042B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808042B8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808042BC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808042C0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808042C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808042C8: jal         0x80085998
    // 0x808042CC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_350;
    // 0x808042CC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_350:
    // 0x808042D0: b           L_80805794
    // 0x808042D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x808042D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808042D8:
    // 0x808042D8: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808042DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7534) << 16);
    // 0x808042E0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X755C) << 16);
    // 0x808042E4: addiu       $s1, $s1, 0x755C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X755C));
    // 0x808042E8: addiu       $v0, $v0, 0x7534
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7534));
    // 0x808042EC: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x808042F0: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    // 0x808042F4: addiu       $t6, $zero, 0x15
    ctx->r14 = ADD32(0, 0X15);
L_808042F8:
    // 0x808042F8: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x808042FC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80804300: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80804304: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80804308: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080430C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804310: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804314: jal         0x80082630
    // 0x80804318: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_351;
    // 0x80804318: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_351:
    // 0x8080431C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804320: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804324: bnel        $v0, $s1, L_808042F8
    if (ctx->r2 != ctx->r17) {
        // 0x80804328: addiu       $t6, $zero, 0x15
        ctx->r14 = ADD32(0, 0X15);
            goto L_808042F8;
    }
    goto skip_167;
    // 0x80804328: addiu       $t6, $zero, 0x15
    ctx->r14 = ADD32(0, 0X15);
    skip_167:
    // 0x8080432C: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80804330: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80804334: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80804338: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8080433C: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80804340: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80804344: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80804348: addiu       $a2, $a2, -0x7088
    ctx->r6 = ADD32(ctx->r6, -0X7088);
    // 0x8080434C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80804350: jal         0x80082630
    // 0x80804354: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_352;
    // 0x80804354: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_352:
    // 0x80804358: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X755C) << 16);
    // 0x8080435C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7560) << 16);
    // 0x80804360: addiu       $s1, $s1, 0x7560
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7560));
    // 0x80804364: addiu       $v0, $v0, 0x755C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X755C));
    // 0x80804368: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
L_8080436C:
    // 0x8080436C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80804370: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80804374: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80804378: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x8080437C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804380: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804384: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804388: jal         0x80082630
    // 0x8080438C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_353;
    // 0x8080438C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_353:
    // 0x80804390: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804394: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804398: bnel        $v0, $s1, L_8080436C
    if (ctx->r2 != ctx->r17) {
        // 0x8080439C: addiu       $t0, $zero, 0x8
        ctx->r8 = ADD32(0, 0X8);
            goto L_8080436C;
    }
    goto skip_168;
    // 0x8080439C: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    skip_168:
    // 0x808043A0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X755C) << 16);
    // 0x808043A4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7560) << 16);
    // 0x808043A8: addiu       $s1, $s1, 0x7560
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7560));
    // 0x808043AC: addiu       $v0, $v0, 0x755C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X755C));
    // 0x808043B0: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
L_808043B4:
    // 0x808043B4: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x808043B8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808043BC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808043C0: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x808043C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808043C8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808043CC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808043D0: jal         0x80082630
    // 0x808043D4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_354;
    // 0x808043D4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_354:
    // 0x808043D8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808043DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808043E0: bnel        $v0, $s1, L_808043B4
    if (ctx->r2 != ctx->r17) {
        // 0x808043E4: addiu       $t2, $zero, 0x8
        ctx->r10 = ADD32(0, 0X8);
            goto L_808043B4;
    }
    goto skip_169;
    // 0x808043E4: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    skip_169:
    // 0x808043E8: b           L_80805794
    // 0x808043EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x808043EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808043F0:
    // 0x808043F0: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x808043F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7560) << 16);
    // 0x808043F8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x808043FC: addiu       $s1, $s1, 0x756C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x80804400: addiu       $v0, $v0, 0x7560
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7560));
    // 0x80804404: addiu       $s0, $s0, -0x330
    ctx->r16 = ADD32(ctx->r16, -0X330);
    // 0x80804408: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8080440C:
    // 0x8080440C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80804410: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804414: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804418: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080441C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80804420: jal         0x80082628
    // 0x80804424: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_355;
    // 0x80804424: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_355:
    // 0x80804428: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080442C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804430: bnel        $v0, $s1, L_8080440C
    if (ctx->r2 != ctx->r17) {
        // 0x80804434: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8080440C;
    }
    goto skip_170;
    // 0x80804434: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    skip_170:
    // 0x80804438: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x8080443C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x80804440: addiu       $s1, $s1, 0x7578
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x80804444: addiu       $v0, $v0, 0x756C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x80804448: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8080444C:
    // 0x8080444C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804450: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804454: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80804458: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080445C: jal         0x80082628
    // 0x80804460: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_356;
    // 0x80804460: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_356:
    // 0x80804464: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804468: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080446C: bnel        $v0, $s1, L_8080444C
    if (ctx->r2 != ctx->r17) {
        // 0x80804470: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080444C;
    }
    goto skip_171;
    // 0x80804470: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_171:
    // 0x80804474: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7560) << 16);
    // 0x80804478: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x8080447C: addiu       $s1, $s1, 0x756C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x80804480: addiu       $v0, $v0, 0x7560
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7560));
    // 0x80804484: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_80804488:
    // 0x80804488: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8080448C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804490: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804494: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804498: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8080449C: jal         0x80082628
    // 0x808044A0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_357;
    // 0x808044A0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_357:
    // 0x808044A4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808044A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808044AC: bnel        $v0, $s1, L_80804488
    if (ctx->r2 != ctx->r17) {
        // 0x808044B0: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80804488;
    }
    goto skip_172;
    // 0x808044B0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_172:
    // 0x808044B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x808044B8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x808044BC: addiu       $s1, $s1, 0x7578
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x808044C0: addiu       $v0, $v0, 0x756C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x808044C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808044C8:
    // 0x808044C8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808044CC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808044D0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x808044D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808044D8: jal         0x80082628
    // 0x808044DC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_358;
    // 0x808044DC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_358:
    // 0x808044E0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808044E4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808044E8: bnel        $v0, $s1, L_808044C8
    if (ctx->r2 != ctx->r17) {
        // 0x808044EC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808044C8;
    }
    goto skip_173;
    // 0x808044EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_173:
    // 0x808044F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7560) << 16);
    // 0x808044F4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x808044F8: addiu       $s1, $s1, 0x756C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x808044FC: addiu       $v0, $v0, 0x7560
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7560));
    // 0x80804500: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_80804504:
    // 0x80804504: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80804508: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080450C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804510: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804514: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80804518: jal         0x80082628
    // 0x8080451C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_359;
    // 0x8080451C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_359:
    // 0x80804520: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804524: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804528: bnel        $v0, $s1, L_80804504
    if (ctx->r2 != ctx->r17) {
        // 0x8080452C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80804504;
    }
    goto skip_174;
    // 0x8080452C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_174:
    // 0x80804530: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x80804534: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x80804538: addiu       $s1, $s1, 0x7578
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x8080453C: addiu       $v0, $v0, 0x756C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x80804540: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80804544:
    // 0x80804544: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804548: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080454C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80804550: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80804554: jal         0x80082628
    // 0x80804558: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_360;
    // 0x80804558: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_360:
    // 0x8080455C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804560: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804564: bnel        $v0, $s1, L_80804544
    if (ctx->r2 != ctx->r17) {
        // 0x80804568: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80804544;
    }
    goto skip_175;
    // 0x80804568: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_175:
    // 0x8080456C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7560) << 16);
    // 0x80804570: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x80804574: addiu       $s1, $s1, 0x756C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x80804578: addiu       $v0, $v0, 0x7560
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7560));
    // 0x8080457C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80804580:
    // 0x80804580: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80804584: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804588: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080458C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804590: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80804594: jal         0x80082628
    // 0x80804598: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_361;
    // 0x80804598: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_361:
    // 0x8080459C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808045A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808045A4: bnel        $v0, $s1, L_80804580
    if (ctx->r2 != ctx->r17) {
        // 0x808045A8: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80804580;
    }
    goto skip_176;
    // 0x808045A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_176:
    // 0x808045AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x808045B0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x808045B4: addiu       $s1, $s1, 0x7578
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x808045B8: addiu       $v0, $v0, 0x756C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x808045BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808045C0:
    // 0x808045C0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808045C4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808045C8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x808045CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808045D0: jal         0x80082628
    // 0x808045D4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_362;
    // 0x808045D4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_362:
    // 0x808045D8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808045DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808045E0: bnel        $v0, $s1, L_808045C0
    if (ctx->r2 != ctx->r17) {
        // 0x808045E4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808045C0;
    }
    goto skip_177;
    // 0x808045E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_177:
    // 0x808045E8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7560) << 16);
    // 0x808045EC: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x808045F0: addiu       $s1, $s1, 0x756C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x808045F4: addiu       $v0, $v0, 0x7560
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7560));
    // 0x808045F8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_808045FC:
    // 0x808045FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80804600: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804604: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804608: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080460C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80804610: jal         0x80082628
    // 0x80804614: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_363;
    // 0x80804614: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_363:
    // 0x80804618: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080461C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804620: bnel        $v0, $s1, L_808045FC
    if (ctx->r2 != ctx->r17) {
        // 0x80804624: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_808045FC;
    }
    goto skip_178;
    // 0x80804624: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    skip_178:
    // 0x80804628: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x8080462C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x80804630: addiu       $s1, $s1, 0x7578
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x80804634: addiu       $v0, $v0, 0x756C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x80804638: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8080463C:
    // 0x8080463C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804640: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804644: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80804648: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080464C: jal         0x80082628
    // 0x80804650: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_364;
    // 0x80804650: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_364:
    // 0x80804654: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804658: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080465C: bnel        $v0, $s1, L_8080463C
    if (ctx->r2 != ctx->r17) {
        // 0x80804660: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080463C;
    }
    goto skip_179;
    // 0x80804660: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_179:
    // 0x80804664: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7560) << 16);
    // 0x80804668: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x8080466C: addiu       $s1, $s1, 0x756C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x80804670: addiu       $v0, $v0, 0x7560
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7560));
    // 0x80804674: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_80804678:
    // 0x80804678: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080467C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804680: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804684: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804688: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x8080468C: jal         0x80082628
    // 0x80804690: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_365;
    // 0x80804690: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_365:
    // 0x80804694: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804698: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080469C: bnel        $v0, $s1, L_80804678
    if (ctx->r2 != ctx->r17) {
        // 0x808046A0: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80804678;
    }
    goto skip_180;
    // 0x808046A0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    skip_180:
    // 0x808046A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x808046A8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x808046AC: addiu       $s1, $s1, 0x7578
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x808046B0: addiu       $v0, $v0, 0x756C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x808046B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808046B8:
    // 0x808046B8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808046BC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808046C0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x808046C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808046C8: jal         0x80082628
    // 0x808046CC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_366;
    // 0x808046CC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_366:
    // 0x808046D0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808046D4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808046D8: bnel        $v0, $s1, L_808046B8
    if (ctx->r2 != ctx->r17) {
        // 0x808046DC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808046B8;
    }
    goto skip_181;
    // 0x808046DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_181:
    // 0x808046E0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x808046E4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x808046E8: addiu       $s1, $s1, 0x7584
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x808046EC: addiu       $v0, $v0, 0x7578
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x808046F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_808046F4:
    // 0x808046F4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808046F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808046FC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804700: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804704: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80804708: jal         0x80082628
    // 0x8080470C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_367;
    // 0x8080470C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_367:
    // 0x80804710: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804714: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804718: bnel        $v0, $s1, L_808046F4
    if (ctx->r2 != ctx->r17) {
        // 0x8080471C: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_808046F4;
    }
    goto skip_182;
    // 0x8080471C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    skip_182:
    // 0x80804720: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x80804724: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7590) << 16);
    // 0x80804728: addiu       $s1, $s1, 0x7590
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7590));
    // 0x8080472C: addiu       $v0, $v0, 0x7584
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x80804730: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80804734:
    // 0x80804734: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804738: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080473C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80804740: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80804744: jal         0x80082628
    // 0x80804748: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_368;
    // 0x80804748: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_368:
    // 0x8080474C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804750: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804754: bnel        $v0, $s1, L_80804734
    if (ctx->r2 != ctx->r17) {
        // 0x80804758: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80804734;
    }
    goto skip_183;
    // 0x80804758: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_183:
    // 0x8080475C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x80804760: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x80804764: addiu       $s1, $s1, 0x7584
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x80804768: addiu       $v0, $v0, 0x7578
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x8080476C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80804770:
    // 0x80804770: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80804774: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804778: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080477C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804780: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80804784: jal         0x80082628
    // 0x80804788: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_369;
    // 0x80804788: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_369:
    // 0x8080478C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804790: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804794: bnel        $v0, $s1, L_80804770
    if (ctx->r2 != ctx->r17) {
        // 0x80804798: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80804770;
    }
    goto skip_184;
    // 0x80804798: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_184:
    // 0x8080479C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x808047A0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7590) << 16);
    // 0x808047A4: addiu       $s1, $s1, 0x7590
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7590));
    // 0x808047A8: addiu       $v0, $v0, 0x7584
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x808047AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808047B0:
    // 0x808047B0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808047B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808047B8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x808047BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808047C0: jal         0x80082628
    // 0x808047C4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_370;
    // 0x808047C4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_370:
    // 0x808047C8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808047CC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808047D0: bnel        $v0, $s1, L_808047B0
    if (ctx->r2 != ctx->r17) {
        // 0x808047D4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808047B0;
    }
    goto skip_185;
    // 0x808047D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_185:
    // 0x808047D8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x808047DC: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x808047E0: addiu       $s1, $s1, 0x7584
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x808047E4: addiu       $v0, $v0, 0x7578
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x808047E8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_808047EC:
    // 0x808047EC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808047F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808047F4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808047F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808047FC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80804800: jal         0x80082628
    // 0x80804804: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_371;
    // 0x80804804: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_371:
    // 0x80804808: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080480C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804810: bnel        $v0, $s1, L_808047EC
    if (ctx->r2 != ctx->r17) {
        // 0x80804814: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_808047EC;
    }
    goto skip_186;
    // 0x80804814: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_186:
    // 0x80804818: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x8080481C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7590) << 16);
    // 0x80804820: addiu       $s1, $s1, 0x7590
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7590));
    // 0x80804824: addiu       $v0, $v0, 0x7584
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x80804828: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8080482C:
    // 0x8080482C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804830: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804834: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80804838: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080483C: jal         0x80082628
    // 0x80804840: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_372;
    // 0x80804840: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_372:
    // 0x80804844: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804848: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080484C: bnel        $v0, $s1, L_8080482C
    if (ctx->r2 != ctx->r17) {
        // 0x80804850: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080482C;
    }
    goto skip_187;
    // 0x80804850: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_187:
    // 0x80804854: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x80804858: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x8080485C: addiu       $s1, $s1, 0x7584
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x80804860: addiu       $v0, $v0, 0x7578
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x80804864: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80804868:
    // 0x80804868: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8080486C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804870: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804874: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804878: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8080487C: jal         0x80082628
    // 0x80804880: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_373;
    // 0x80804880: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_373:
    // 0x80804884: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804888: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080488C: bnel        $v0, $s1, L_80804868
    if (ctx->r2 != ctx->r17) {
        // 0x80804890: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80804868;
    }
    goto skip_188;
    // 0x80804890: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    skip_188:
    // 0x80804894: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x80804898: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7590) << 16);
    // 0x8080489C: addiu       $s1, $s1, 0x7590
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7590));
    // 0x808048A0: addiu       $v0, $v0, 0x7584
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x808048A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808048A8:
    // 0x808048A8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808048AC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808048B0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x808048B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808048B8: jal         0x80082628
    // 0x808048BC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_374;
    // 0x808048BC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_374:
    // 0x808048C0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808048C4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808048C8: bnel        $v0, $s1, L_808048A8
    if (ctx->r2 != ctx->r17) {
        // 0x808048CC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808048A8;
    }
    goto skip_189;
    // 0x808048CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_189:
    // 0x808048D0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x808048D4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x808048D8: addiu       $s1, $s1, 0x7584
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x808048DC: addiu       $v0, $v0, 0x7578
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x808048E0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_808048E4:
    // 0x808048E4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x808048E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808048EC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808048F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808048F4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x808048F8: jal         0x80082628
    // 0x808048FC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_375;
    // 0x808048FC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_375:
    // 0x80804900: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804904: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804908: bnel        $v0, $s1, L_808048E4
    if (ctx->r2 != ctx->r17) {
        // 0x8080490C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_808048E4;
    }
    goto skip_190;
    // 0x8080490C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    skip_190:
    // 0x80804910: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x80804914: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7590) << 16);
    // 0x80804918: addiu       $s1, $s1, 0x7590
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7590));
    // 0x8080491C: addiu       $v0, $v0, 0x7584
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x80804920: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80804924:
    // 0x80804924: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804928: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080492C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80804930: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80804934: jal         0x80082628
    // 0x80804938: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_376;
    // 0x80804938: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_376:
    // 0x8080493C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804940: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804944: bnel        $v0, $s1, L_80804924
    if (ctx->r2 != ctx->r17) {
        // 0x80804948: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80804924;
    }
    goto skip_191;
    // 0x80804948: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_191:
    // 0x8080494C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x80804950: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x80804954: addiu       $s1, $s1, 0x7584
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x80804958: addiu       $v0, $v0, 0x7578
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x8080495C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_80804960:
    // 0x80804960: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80804964: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804968: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080496C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804970: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80804974: jal         0x80082628
    // 0x80804978: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_377;
    // 0x80804978: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_377:
    // 0x8080497C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804980: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804984: bnel        $v0, $s1, L_80804960
    if (ctx->r2 != ctx->r17) {
        // 0x80804988: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80804960;
    }
    goto skip_192;
    // 0x80804988: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_192:
    // 0x8080498C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x80804990: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7590) << 16);
    // 0x80804994: addiu       $s1, $s1, 0x7590
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7590));
    // 0x80804998: addiu       $v0, $v0, 0x7584
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x8080499C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808049A0:
    // 0x808049A0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808049A4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808049A8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x808049AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808049B0: jal         0x80082628
    // 0x808049B4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_378;
    // 0x808049B4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_378:
    // 0x808049B8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808049BC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808049C0: bnel        $v0, $s1, L_808049A0
    if (ctx->r2 != ctx->r17) {
        // 0x808049C4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808049A0;
    }
    goto skip_193;
    // 0x808049C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_193:
    // 0x808049C8: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x808049CC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7560) << 16);
    // 0x808049D0: lui         $s5, 0x95AF
    ctx->r21 = S32(0X95AF << 16);
    // 0x808049D4: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x808049D8: addiu       $s3, $s3, 0x756C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x808049DC: ori         $s5, $s5, 0xFF00
    ctx->r21 = ctx->r21 | 0XFF00;
    // 0x808049E0: addiu       $v0, $v0, 0x7560
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7560));
    // 0x808049E4: addiu       $s1, $s1, -0x7078
    ctx->r17 = ADD32(ctx->r17, -0X7078);
    // 0x808049E8: lui         $s0, 0x2
    ctx->r16 = S32(0X2 << 16);
    // 0x808049EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808049F0:
    // 0x808049F0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808049F4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808049F8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808049FC: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80804A00: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80804A04: jal         0x80082630
    // 0x80804A08: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_379;
    // 0x80804A08: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_379:
    // 0x80804A0C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804A10: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804A14: bnel        $v0, $s3, L_808049F0
    if (ctx->r2 != ctx->r19) {
        // 0x80804A18: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808049F0;
    }
    goto skip_194;
    // 0x80804A18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_194:
    // 0x80804A1C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x80804A20: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x80804A24: lui         $s3, 0x6D87
    ctx->r19 = S32(0X6D87 << 16);
    // 0x80804A28: ori         $s3, $s3, 0xFF00
    ctx->r19 = ctx->r19 | 0XFF00;
    // 0x80804A2C: addiu       $s4, $s4, 0x7578
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x80804A30: addiu       $v0, $v0, 0x756C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x80804A34: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
L_80804A38:
    // 0x80804A38: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80804A3C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804A40: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804A44: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804A48: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804A4C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80804A50: jal         0x80082630
    // 0x80804A54: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_380;
    // 0x80804A54: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_380:
    // 0x80804A58: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804A5C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804A60: bnel        $v0, $s4, L_80804A38
    if (ctx->r2 != ctx->r20) {
        // 0x80804A64: addiu       $t6, $zero, 0x19
        ctx->r14 = ADD32(0, 0X19);
            goto L_80804A38;
    }
    goto skip_195;
    // 0x80804A64: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    skip_195:
    // 0x80804A68: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x80804A6C: lui         $s4, 0x7CCB
    ctx->r20 = S32(0X7CCB << 16);
    // 0x80804A70: ori         $s4, $s4, 0xFF00
    ctx->r20 = ctx->r20 | 0XFF00;
    // 0x80804A74: addiu       $v0, $v0, 0x7578
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x80804A78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80804A7C:
    // 0x80804A7C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804A80: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804A84: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804A88: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80804A8C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80804A90: jal         0x80082630
    // 0x80804A94: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_381;
    // 0x80804A94: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_381:
    // 0x80804A98: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804A9C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x80804AA0: addiu       $t7, $t7, 0x7584
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x80804AA4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804AA8: bnel        $v0, $t7, L_80804A7C
    if (ctx->r2 != ctx->r15) {
        // 0x80804AAC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80804A7C;
    }
    goto skip_196;
    // 0x80804AAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_196:
    // 0x80804AB0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x80804AB4: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7590) << 16);
    // 0x80804AB8: addiu       $s4, $s4, 0x7590
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7590));
    // 0x80804ABC: addiu       $v0, $v0, 0x7584
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x80804AC0: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
L_80804AC4:
    // 0x80804AC4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80804AC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804ACC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804AD0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804AD4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804AD8: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80804ADC: jal         0x80082630
    // 0x80804AE0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_382;
    // 0x80804AE0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_382:
    // 0x80804AE4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804AE8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804AEC: bnel        $v0, $s4, L_80804AC4
    if (ctx->r2 != ctx->r20) {
        // 0x80804AF0: addiu       $t8, $zero, 0x19
        ctx->r24 = ADD32(0, 0X19);
            goto L_80804AC4;
    }
    goto skip_197;
    // 0x80804AF0: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
    skip_197:
    // 0x80804AF4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7560) << 16);
    // 0x80804AF8: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x80804AFC: addiu       $s4, $s4, 0x756C
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x80804B00: addiu       $v0, $v0, 0x7560
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7560));
    // 0x80804B04: lui         $s0, 0x3
    ctx->r16 = S32(0X3 << 16);
    // 0x80804B08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80804B0C:
    // 0x80804B0C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804B10: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804B14: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804B18: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80804B1C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80804B20: jal         0x80082630
    // 0x80804B24: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_383;
    // 0x80804B24: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_383:
    // 0x80804B28: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804B2C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804B30: bnel        $v0, $s4, L_80804B0C
    if (ctx->r2 != ctx->r20) {
        // 0x80804B34: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80804B0C;
    }
    goto skip_198;
    // 0x80804B34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_198:
    // 0x80804B38: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x80804B3C: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x80804B40: addiu       $s4, $s4, 0x7578
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x80804B44: addiu       $v0, $v0, 0x756C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x80804B48: addiu       $t9, $zero, 0x19
    ctx->r25 = ADD32(0, 0X19);
L_80804B4C:
    // 0x80804B4C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80804B50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804B54: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804B58: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804B5C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804B60: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80804B64: jal         0x80082630
    // 0x80804B68: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_384;
    // 0x80804B68: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_384:
    // 0x80804B6C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804B70: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804B74: bnel        $v0, $s4, L_80804B4C
    if (ctx->r2 != ctx->r20) {
        // 0x80804B78: addiu       $t9, $zero, 0x19
        ctx->r25 = ADD32(0, 0X19);
            goto L_80804B4C;
    }
    goto skip_199;
    // 0x80804B78: addiu       $t9, $zero, 0x19
    ctx->r25 = ADD32(0, 0X19);
    skip_199:
    // 0x80804B7C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x80804B80: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x80804B84: addiu       $s4, $s4, 0x7584
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x80804B88: addiu       $v0, $v0, 0x7578
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x80804B8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80804B90:
    // 0x80804B90: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804B94: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804B98: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804B9C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80804BA0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80804BA4: jal         0x80082630
    // 0x80804BA8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_385;
    // 0x80804BA8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_385:
    // 0x80804BAC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804BB0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804BB4: bnel        $v0, $s4, L_80804B90
    if (ctx->r2 != ctx->r20) {
        // 0x80804BB8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80804B90;
    }
    goto skip_200;
    // 0x80804BB8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_200:
    // 0x80804BBC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x80804BC0: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7590) << 16);
    // 0x80804BC4: addiu       $s4, $s4, 0x7590
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7590));
    // 0x80804BC8: addiu       $v0, $v0, 0x7584
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x80804BCC: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
L_80804BD0:
    // 0x80804BD0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80804BD4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804BD8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804BDC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804BE0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804BE4: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80804BE8: jal         0x80082630
    // 0x80804BEC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_386;
    // 0x80804BEC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_386:
    // 0x80804BF0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804BF4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804BF8: bnel        $v0, $s4, L_80804BD0
    if (ctx->r2 != ctx->r20) {
        // 0x80804BFC: addiu       $t0, $zero, 0x19
        ctx->r8 = ADD32(0, 0X19);
            goto L_80804BD0;
    }
    goto skip_201;
    // 0x80804BFC: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
    skip_201:
    // 0x80804C00: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7560) << 16);
    // 0x80804C04: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x80804C08: addiu       $s4, $s4, 0x756C
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x80804C0C: addiu       $v0, $v0, 0x7560
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7560));
    // 0x80804C10: lui         $s0, 0x4
    ctx->r16 = S32(0X4 << 16);
    // 0x80804C14: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80804C18:
    // 0x80804C18: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804C1C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804C20: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804C24: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80804C28: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80804C2C: jal         0x80082630
    // 0x80804C30: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_387;
    // 0x80804C30: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_387:
    // 0x80804C34: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804C38: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804C3C: bnel        $v0, $s4, L_80804C18
    if (ctx->r2 != ctx->r20) {
        // 0x80804C40: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80804C18;
    }
    goto skip_202;
    // 0x80804C40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_202:
    // 0x80804C44: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x80804C48: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x80804C4C: addiu       $s4, $s4, 0x7578
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x80804C50: addiu       $v0, $v0, 0x756C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x80804C54: addiu       $t1, $zero, 0x19
    ctx->r9 = ADD32(0, 0X19);
L_80804C58:
    // 0x80804C58: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80804C5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804C60: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804C64: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804C68: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804C6C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80804C70: jal         0x80082630
    // 0x80804C74: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_388;
    // 0x80804C74: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_388:
    // 0x80804C78: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804C7C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804C80: bnel        $v0, $s4, L_80804C58
    if (ctx->r2 != ctx->r20) {
        // 0x80804C84: addiu       $t1, $zero, 0x19
        ctx->r9 = ADD32(0, 0X19);
            goto L_80804C58;
    }
    goto skip_203;
    // 0x80804C84: addiu       $t1, $zero, 0x19
    ctx->r9 = ADD32(0, 0X19);
    skip_203:
    // 0x80804C88: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x80804C8C: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x80804C90: addiu       $s4, $s4, 0x7584
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x80804C94: addiu       $v0, $v0, 0x7578
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x80804C98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80804C9C:
    // 0x80804C9C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804CA0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804CA4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804CA8: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80804CAC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80804CB0: jal         0x80082630
    // 0x80804CB4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_389;
    // 0x80804CB4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_389:
    // 0x80804CB8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804CBC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804CC0: bnel        $v0, $s4, L_80804C9C
    if (ctx->r2 != ctx->r20) {
        // 0x80804CC4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80804C9C;
    }
    goto skip_204;
    // 0x80804CC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_204:
    // 0x80804CC8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x80804CCC: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7590) << 16);
    // 0x80804CD0: addiu       $s4, $s4, 0x7590
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7590));
    // 0x80804CD4: addiu       $v0, $v0, 0x7584
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x80804CD8: addiu       $t2, $zero, 0x19
    ctx->r10 = ADD32(0, 0X19);
L_80804CDC:
    // 0x80804CDC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80804CE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804CE4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804CE8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804CEC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804CF0: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80804CF4: jal         0x80082630
    // 0x80804CF8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_390;
    // 0x80804CF8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_390:
    // 0x80804CFC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804D00: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804D04: bnel        $v0, $s4, L_80804CDC
    if (ctx->r2 != ctx->r20) {
        // 0x80804D08: addiu       $t2, $zero, 0x19
        ctx->r10 = ADD32(0, 0X19);
            goto L_80804CDC;
    }
    goto skip_205;
    // 0x80804D08: addiu       $t2, $zero, 0x19
    ctx->r10 = ADD32(0, 0X19);
    skip_205:
    // 0x80804D0C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7560) << 16);
    // 0x80804D10: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x80804D14: addiu       $s4, $s4, 0x756C
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x80804D18: addiu       $v0, $v0, 0x7560
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7560));
    // 0x80804D1C: lui         $s0, 0x5
    ctx->r16 = S32(0X5 << 16);
    // 0x80804D20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80804D24:
    // 0x80804D24: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804D28: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804D2C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804D30: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80804D34: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80804D38: jal         0x80082630
    // 0x80804D3C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_391;
    // 0x80804D3C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_391:
    // 0x80804D40: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804D44: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804D48: bnel        $v0, $s4, L_80804D24
    if (ctx->r2 != ctx->r20) {
        // 0x80804D4C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80804D24;
    }
    goto skip_206;
    // 0x80804D4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_206:
    // 0x80804D50: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x80804D54: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x80804D58: addiu       $s4, $s4, 0x7578
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x80804D5C: addiu       $v0, $v0, 0x756C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x80804D60: addiu       $t3, $zero, 0x19
    ctx->r11 = ADD32(0, 0X19);
L_80804D64:
    // 0x80804D64: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80804D68: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804D6C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804D70: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804D74: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804D78: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80804D7C: jal         0x80082630
    // 0x80804D80: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_392;
    // 0x80804D80: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_392:
    // 0x80804D84: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804D88: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804D8C: bnel        $v0, $s4, L_80804D64
    if (ctx->r2 != ctx->r20) {
        // 0x80804D90: addiu       $t3, $zero, 0x19
        ctx->r11 = ADD32(0, 0X19);
            goto L_80804D64;
    }
    goto skip_207;
    // 0x80804D90: addiu       $t3, $zero, 0x19
    ctx->r11 = ADD32(0, 0X19);
    skip_207:
    // 0x80804D94: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x80804D98: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x80804D9C: addiu       $s4, $s4, 0x7584
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x80804DA0: addiu       $v0, $v0, 0x7578
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x80804DA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80804DA8:
    // 0x80804DA8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804DAC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804DB0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804DB4: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80804DB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80804DBC: jal         0x80082630
    // 0x80804DC0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_393;
    // 0x80804DC0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_393:
    // 0x80804DC4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804DC8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804DCC: bnel        $v0, $s4, L_80804DA8
    if (ctx->r2 != ctx->r20) {
        // 0x80804DD0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80804DA8;
    }
    goto skip_208;
    // 0x80804DD0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_208:
    // 0x80804DD4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x80804DD8: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7590) << 16);
    // 0x80804DDC: addiu       $s4, $s4, 0x7590
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7590));
    // 0x80804DE0: addiu       $v0, $v0, 0x7584
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x80804DE4: addiu       $t4, $zero, 0x19
    ctx->r12 = ADD32(0, 0X19);
L_80804DE8:
    // 0x80804DE8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80804DEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804DF0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804DF4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804DF8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804DFC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80804E00: jal         0x80082630
    // 0x80804E04: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_394;
    // 0x80804E04: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_394:
    // 0x80804E08: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804E0C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804E10: bnel        $v0, $s4, L_80804DE8
    if (ctx->r2 != ctx->r20) {
        // 0x80804E14: addiu       $t4, $zero, 0x19
        ctx->r12 = ADD32(0, 0X19);
            goto L_80804DE8;
    }
    goto skip_209;
    // 0x80804E14: addiu       $t4, $zero, 0x19
    ctx->r12 = ADD32(0, 0X19);
    skip_209:
    // 0x80804E18: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7560) << 16);
    // 0x80804E1C: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x80804E20: addiu       $s4, $s4, 0x756C
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x80804E24: addiu       $v0, $v0, 0x7560
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7560));
    // 0x80804E28: lui         $s0, 0x6
    ctx->r16 = S32(0X6 << 16);
    // 0x80804E2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80804E30:
    // 0x80804E30: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804E34: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804E38: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804E3C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80804E40: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80804E44: jal         0x80082630
    // 0x80804E48: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_395;
    // 0x80804E48: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_395:
    // 0x80804E4C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804E50: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804E54: bnel        $v0, $s4, L_80804E30
    if (ctx->r2 != ctx->r20) {
        // 0x80804E58: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80804E30;
    }
    goto skip_210;
    // 0x80804E58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_210:
    // 0x80804E5C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X756C) << 16);
    // 0x80804E60: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x80804E64: addiu       $s4, $s4, 0x7578
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x80804E68: addiu       $v0, $v0, 0x756C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X756C));
    // 0x80804E6C: addiu       $t5, $zero, 0x19
    ctx->r13 = ADD32(0, 0X19);
L_80804E70:
    // 0x80804E70: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80804E74: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804E78: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804E7C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804E80: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804E84: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80804E88: jal         0x80082630
    // 0x80804E8C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_396;
    // 0x80804E8C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_396:
    // 0x80804E90: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804E94: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804E98: bnel        $v0, $s4, L_80804E70
    if (ctx->r2 != ctx->r20) {
        // 0x80804E9C: addiu       $t5, $zero, 0x19
        ctx->r13 = ADD32(0, 0X19);
            goto L_80804E70;
    }
    goto skip_211;
    // 0x80804E9C: addiu       $t5, $zero, 0x19
    ctx->r13 = ADD32(0, 0X19);
    skip_211:
    // 0x80804EA0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7578) << 16);
    // 0x80804EA4: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x80804EA8: addiu       $s4, $s4, 0x7584
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x80804EAC: addiu       $v0, $v0, 0x7578
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7578));
    // 0x80804EB0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80804EB4:
    // 0x80804EB4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804EB8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804EBC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804EC0: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80804EC4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80804EC8: jal         0x80082630
    // 0x80804ECC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_397;
    // 0x80804ECC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_397:
    // 0x80804ED0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804ED4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804ED8: bnel        $v0, $s4, L_80804EB4
    if (ctx->r2 != ctx->r20) {
        // 0x80804EDC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80804EB4;
    }
    goto skip_212;
    // 0x80804EDC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_212:
    // 0x80804EE0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7584) << 16);
    // 0x80804EE4: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2958, 0X7590) << 16);
    // 0x80804EE8: addiu       $s4, $s4, 0x7590
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2958, 0X7590));
    // 0x80804EEC: addiu       $v0, $v0, 0x7584
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7584));
    // 0x80804EF0: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
L_80804EF4:
    // 0x80804EF4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80804EF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804EFC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804F00: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804F04: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80804F08: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80804F0C: jal         0x80082630
    // 0x80804F10: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_398;
    // 0x80804F10: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_398:
    // 0x80804F14: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804F18: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804F1C: bnel        $v0, $s4, L_80804EF4
    if (ctx->r2 != ctx->r20) {
        // 0x80804F20: addiu       $t6, $zero, 0x19
        ctx->r14 = ADD32(0, 0X19);
            goto L_80804EF4;
    }
    goto skip_213;
    // 0x80804F20: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    skip_213:
    // 0x80804F24: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80804F28: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X75B8) << 16);
    // 0x80804F2C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X75C0) << 16);
    // 0x80804F30: addiu       $s1, $s1, 0x75C0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X75C0));
    // 0x80804F34: addiu       $v0, $v0, 0x75B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X75B8));
    // 0x80804F38: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80804F3C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80804F40:
    // 0x80804F40: addiu       $t8, $zero, -0x2
    ctx->r24 = ADD32(0, -0X2);
    // 0x80804F44: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80804F48: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80804F4C: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80804F50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804F54: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804F58: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804F5C: jal         0x80082630
    // 0x80804F60: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_399;
    // 0x80804F60: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_399:
    // 0x80804F64: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804F68: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804F6C: bnel        $v0, $s1, L_80804F40
    if (ctx->r2 != ctx->r17) {
        // 0x80804F70: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80804F40;
    }
    goto skip_214;
    // 0x80804F70: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_214:
    // 0x80804F74: b           L_80805794
    // 0x80804F78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80804F78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804F7C:
    // 0x80804F7C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80804F80: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X75C0) << 16);
    // 0x80804F84: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X75CC) << 16);
    // 0x80804F88: addiu       $s1, $s1, 0x75CC
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X75CC));
    // 0x80804F8C: addiu       $v0, $v0, 0x75C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X75C0));
    // 0x80804F90: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x80804F94: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    // 0x80804F98: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
L_80804F9C:
    // 0x80804F9C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80804FA0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80804FA4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80804FA8: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80804FAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804FB0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80804FB4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80804FB8: jal         0x80082630
    // 0x80804FBC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_400;
    // 0x80804FBC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_400:
    // 0x80804FC0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80804FC4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80804FC8: bnel        $v0, $s1, L_80804F9C
    if (ctx->r2 != ctx->r17) {
        // 0x80804FCC: addiu       $t9, $zero, 0x9
        ctx->r25 = ADD32(0, 0X9);
            goto L_80804F9C;
    }
    goto skip_215;
    // 0x80804FCC: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    skip_215:
    // 0x80804FD0: b           L_80805794
    // 0x80804FD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80804FD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804FD8:
    // 0x80804FD8: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80804FDC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X75CC) << 16);
    // 0x80804FE0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X75F0) << 16);
    // 0x80804FE4: addiu       $s1, $s1, 0x75F0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X75F0));
    // 0x80804FE8: addiu       $v0, $v0, 0x75CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X75CC));
    // 0x80804FEC: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x80804FF0: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    // 0x80804FF4: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
L_80804FF8:
    // 0x80804FF8: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80804FFC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80805000: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80805004: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80805008: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080500C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80805010: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80805014: jal         0x80082630
    // 0x80805018: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_401;
    // 0x80805018: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_401:
    // 0x8080501C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80805020: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80805024: bnel        $v0, $s1, L_80804FF8
    if (ctx->r2 != ctx->r17) {
        // 0x80805028: addiu       $t1, $zero, 0xB
        ctx->r9 = ADD32(0, 0XB);
            goto L_80804FF8;
    }
    goto skip_216;
    // 0x80805028: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    skip_216:
    // 0x8080502C: b           L_80805794
    // 0x80805030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80805030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805034:
    // 0x80805034: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6934) << 16);
    // 0x80805038: lwc1        $f20, 0x6934($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6934));
    // 0x8080503C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80805040: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80805044: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80805048: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080504C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80805050: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80805054: addiu       $a2, $a2, -0x7088
    ctx->r6 = ADD32(ctx->r6, -0X7088);
    // 0x80805058: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080505C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80805060: jal         0x80082630
    // 0x80805064: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_402;
    // 0x80805064: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_402:
    // 0x80805068: b           L_80805794
    // 0x8080506C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x8080506C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805070:
    // 0x80805070: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80805074: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X75F0) << 16);
    // 0x80805078: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7614) << 16);
    // 0x8080507C: addiu       $s1, $s1, 0x7614
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7614));
    // 0x80805080: addiu       $v0, $v0, 0x75F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X75F0));
    // 0x80805084: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x80805088: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    // 0x8080508C: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
L_80805090:
    // 0x80805090: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80805094: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80805098: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8080509C: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x808050A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808050A4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808050A8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808050AC: jal         0x80082630
    // 0x808050B0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_403;
    // 0x808050B0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_403:
    // 0x808050B4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808050B8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808050BC: bnel        $v0, $s1, L_80805090
    if (ctx->r2 != ctx->r17) {
        // 0x808050C0: addiu       $t5, $zero, 0x10
        ctx->r13 = ADD32(0, 0X10);
            goto L_80805090;
    }
    goto skip_217;
    // 0x808050C0: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    skip_217:
    // 0x808050C4: b           L_80805794
    // 0x808050C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x808050C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808050CC:
    // 0x808050CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6938) << 16);
    // 0x808050D0: lwc1        $f20, 0x6938($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6938));
    // 0x808050D4: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808050D8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x808050DC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x808050E0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808050E4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808050E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808050EC: addiu       $a2, $a2, -0x7088
    ctx->r6 = ADD32(ctx->r6, -0X7088);
    // 0x808050F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808050F4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x808050F8: jal         0x80082630
    // 0x808050FC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_404;
    // 0x808050FC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_404:
    // 0x80805100: b           L_80805794
    // 0x80805104: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80805104: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805108:
    // 0x80805108: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X693C) << 16);
    // 0x8080510C: lwc1        $f20, 0x693C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X693C));
    // 0x80805110: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80805114: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80805118: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8080511C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80805120: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80805124: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80805128: addiu       $a2, $a2, -0x7088
    ctx->r6 = ADD32(ctx->r6, -0X7088);
    // 0x8080512C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805130: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80805134: jal         0x80082630
    // 0x80805138: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_405;
    // 0x80805138: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_405:
    // 0x8080513C: b           L_80805794
    // 0x80805140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80805140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805144:
    // 0x80805144: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6940) << 16);
    // 0x80805148: lwc1        $f20, 0x6940($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6940));
    // 0x8080514C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80805150: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80805154: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80805158: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080515C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80805160: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80805164: addiu       $a2, $a2, -0x7088
    ctx->r6 = ADD32(ctx->r6, -0X7088);
    // 0x80805168: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080516C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80805170: jal         0x80082630
    // 0x80805174: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_406;
    // 0x80805174: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_406:
    // 0x80805178: b           L_80805794
    // 0x8080517C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x8080517C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805180:
    // 0x80805180: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6944) << 16);
    // 0x80805184: lwc1        $f20, 0x6944($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6944));
    // 0x80805188: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8080518C: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80805190: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80805194: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80805198: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8080519C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808051A0: addiu       $a2, $a2, -0x7088
    ctx->r6 = ADD32(ctx->r6, -0X7088);
    // 0x808051A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808051A8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x808051AC: jal         0x80082630
    // 0x808051B0: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_407;
    // 0x808051B0: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_407:
    // 0x808051B4: b           L_80805794
    // 0x808051B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x808051B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808051BC:
    // 0x808051BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6948) << 16);
    // 0x808051C0: lwc1        $f20, 0x6948($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6948));
    // 0x808051C4: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808051C8: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x808051CC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x808051D0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808051D4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808051D8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808051DC: addiu       $a2, $a2, -0x7088
    ctx->r6 = ADD32(ctx->r6, -0X7088);
    // 0x808051E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808051E4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x808051E8: jal         0x80082630
    // 0x808051EC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_408;
    // 0x808051EC: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_408:
    // 0x808051F0: b           L_80805794
    // 0x808051F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x808051F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808051F8:
    // 0x808051F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X694C) << 16);
    // 0x808051FC: lwc1        $f20, 0x694C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X694C));
    // 0x80805200: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80805204: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80805208: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8080520C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80805210: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80805214: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80805218: addiu       $a2, $a2, -0x7088
    ctx->r6 = ADD32(ctx->r6, -0X7088);
    // 0x8080521C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805220: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80805224: jal         0x80082630
    // 0x80805228: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_409;
    // 0x80805228: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_409:
    // 0x8080522C: b           L_80805794
    // 0x80805230: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80805230: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805234:
    // 0x80805234: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6950) << 16);
    // 0x80805238: lwc1        $f20, 0x6950($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6950));
    // 0x8080523C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80805240: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
    // 0x80805244: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80805248: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080524C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80805250: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80805254: addiu       $a2, $a2, -0x7088
    ctx->r6 = ADD32(ctx->r6, -0X7088);
    // 0x80805258: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080525C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80805260: jal         0x80082630
    // 0x80805264: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_410;
    // 0x80805264: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_410:
    // 0x80805268: b           L_80805794
    // 0x8080526C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x8080526C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805270:
    // 0x80805270: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80805274: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7614) << 16);
    // 0x80805278: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7618) << 16);
    // 0x8080527C: addiu       $s1, $s1, 0x7618
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7618));
    // 0x80805280: addiu       $v0, $v0, 0x7614
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7614));
    // 0x80805284: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x80805288: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    // 0x8080528C: addiu       $t1, $zero, 0x11
    ctx->r9 = ADD32(0, 0X11);
L_80805290:
    // 0x80805290: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80805294: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80805298: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8080529C: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x808052A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808052A4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808052A8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808052AC: jal         0x80082630
    // 0x808052B0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_411;
    // 0x808052B0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_411:
    // 0x808052B4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808052B8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808052BC: bnel        $v0, $s1, L_80805290
    if (ctx->r2 != ctx->r17) {
        // 0x808052C0: addiu       $t1, $zero, 0x11
        ctx->r9 = ADD32(0, 0X11);
            goto L_80805290;
    }
    goto skip_218;
    // 0x808052C0: addiu       $t1, $zero, 0x11
    ctx->r9 = ADD32(0, 0X11);
    skip_218:
    // 0x808052C4: b           L_80805794
    // 0x808052C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x808052C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808052CC:
    // 0x808052CC: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808052D0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7618) << 16);
    // 0x808052D4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X761C) << 16);
    // 0x808052D8: addiu       $s1, $s1, 0x761C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X761C));
    // 0x808052DC: addiu       $v0, $v0, 0x7618
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7618));
    // 0x808052E0: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x808052E4: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    // 0x808052E8: addiu       $t3, $zero, 0x12
    ctx->r11 = ADD32(0, 0X12);
L_808052EC:
    // 0x808052EC: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x808052F0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x808052F4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808052F8: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x808052FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805300: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80805304: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80805308: jal         0x80082630
    // 0x8080530C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_412;
    // 0x8080530C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_412:
    // 0x80805310: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80805314: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80805318: bnel        $v0, $s1, L_808052EC
    if (ctx->r2 != ctx->r17) {
        // 0x8080531C: addiu       $t3, $zero, 0x12
        ctx->r11 = ADD32(0, 0X12);
            goto L_808052EC;
    }
    goto skip_219;
    // 0x8080531C: addiu       $t3, $zero, 0x12
    ctx->r11 = ADD32(0, 0X12);
    skip_219:
    // 0x80805320: b           L_80805794
    // 0x80805324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80805324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805328:
    // 0x80805328: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8080532C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X761C) << 16);
    // 0x80805330: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7640) << 16);
    // 0x80805334: addiu       $s1, $s1, 0x7640
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7640));
    // 0x80805338: addiu       $v0, $v0, 0x761C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X761C));
    // 0x8080533C: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x80805340: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    // 0x80805344: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
L_80805348:
    // 0x80805348: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8080534C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80805350: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80805354: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80805358: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080535C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80805360: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80805364: jal         0x80082630
    // 0x80805368: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_413;
    // 0x80805368: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_413:
    // 0x8080536C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80805370: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80805374: bnel        $v0, $s1, L_80805348
    if (ctx->r2 != ctx->r17) {
        // 0x80805378: addiu       $t5, $zero, 0xC
        ctx->r13 = ADD32(0, 0XC);
            goto L_80805348;
    }
    goto skip_220;
    // 0x80805378: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    skip_220:
    // 0x8080537C: b           L_80805794
    // 0x80805380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80805380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805384:
    // 0x80805384: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80805388: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7640) << 16);
    // 0x8080538C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7664) << 16);
    // 0x80805390: addiu       $s1, $s1, 0x7664
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7664));
    // 0x80805394: addiu       $v0, $v0, 0x7640
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7640));
    // 0x80805398: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x8080539C: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    // 0x808053A0: addiu       $t7, $zero, 0x16
    ctx->r15 = ADD32(0, 0X16);
L_808053A4:
    // 0x808053A4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x808053A8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808053AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808053B0: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x808053B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808053B8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808053BC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808053C0: jal         0x80082630
    // 0x808053C4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_414;
    // 0x808053C4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_414:
    // 0x808053C8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808053CC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808053D0: bnel        $v0, $s1, L_808053A4
    if (ctx->r2 != ctx->r17) {
        // 0x808053D4: addiu       $t7, $zero, 0x16
        ctx->r15 = ADD32(0, 0X16);
            goto L_808053A4;
    }
    goto skip_221;
    // 0x808053D4: addiu       $t7, $zero, 0x16
    ctx->r15 = ADD32(0, 0X16);
    skip_221:
    // 0x808053D8: b           L_80805794
    // 0x808053DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x808053DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808053E0:
    // 0x808053E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6954) << 16);
    // 0x808053E4: lwc1        $f20, 0x6954($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6954));
    // 0x808053E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808053EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808053F0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808053F4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x808053F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808053FC: jal         0x80085998
    // 0x80805400: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_415;
    // 0x80805400: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_415:
    // 0x80805404: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80805408: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8080540C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80805410: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80805414: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805418: jal         0x80085998
    // 0x8080541C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_416;
    // 0x8080541C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_416:
    // 0x80805420: b           L_80805794
    // 0x80805424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80805424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805428:
    // 0x80805428: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8080542C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80805430: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80805434: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80805438: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080543C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80805440: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80805444: jal         0x80085998
    // 0x80805448: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_417;
    // 0x80805448: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_417:
    // 0x8080544C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80805450: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80805454: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80805458: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8080545C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805460: jal         0x80085998
    // 0x80805464: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_418;
    // 0x80805464: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_418:
    // 0x80805468: b           L_80805794
    // 0x8080546C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x8080546C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805470:
    // 0x80805470: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6958) << 16);
    // 0x80805474: lwc1        $f20, 0x6958($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6958));
    // 0x80805478: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080547C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80805480: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80805484: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80805488: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080548C: jal         0x80085998
    // 0x80805490: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_419;
    // 0x80805490: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_419:
    // 0x80805494: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80805498: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8080549C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808054A0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808054A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808054A8: jal         0x80085998
    // 0x808054AC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_420;
    // 0x808054AC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_420:
    // 0x808054B0: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808054B4: addiu       $s0, $s0, -0x7088
    ctx->r16 = ADD32(ctx->r16, -0X7088);
    // 0x808054B8: lui         $a1, 0x3EA8
    ctx->r5 = S32(0X3EA8 << 16);
    // 0x808054BC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x808054C0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x808054C4: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x808054C8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x808054CC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808054D0: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x808054D4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808054D8: jal         0x80082630
    // 0x808054DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_421;
    // 0x808054DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_421:
    // 0x808054E0: lui         $a1, 0x3F2B
    ctx->r5 = S32(0X3F2B << 16);
    // 0x808054E4: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x808054E8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x808054EC: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x808054F0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808054F4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808054F8: ori         $a1, $a1, 0x4396
    ctx->r5 = ctx->r5 | 0X4396;
    // 0x808054FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805500: jal         0x80082630
    // 0x80805504: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_422;
    // 0x80805504: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_422:
    // 0x80805508: b           L_80805794
    // 0x8080550C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x8080550C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805510:
    // 0x80805510: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X695C) << 16);
    // 0x80805514: lwc1        $f20, 0x695C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X695C));
    // 0x80805518: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080551C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80805520: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80805524: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80805528: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080552C: jal         0x80085998
    // 0x80805530: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_423;
    // 0x80805530: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_423:
    // 0x80805534: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80805538: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080553C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80805540: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80805544: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805548: jal         0x80085998
    // 0x8080554C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_424;
    // 0x8080554C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_424:
    // 0x80805550: b           L_80805794
    // 0x80805554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80805554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805558:
    // 0x80805558: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6960) << 16);
    // 0x8080555C: lwc1        $f20, 0x6960($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6960));
    // 0x80805560: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805564: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80805568: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080556C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80805570: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80805574: jal         0x80085998
    // 0x80805578: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_425;
    // 0x80805578: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_425:
    // 0x8080557C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80805580: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80805584: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80805588: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8080558C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805590: jal         0x80085998
    // 0x80805594: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_426;
    // 0x80805594: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_426:
    // 0x80805598: b           L_80805794
    // 0x8080559C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x8080559C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808055A0:
    // 0x808055A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6964) << 16);
    // 0x808055A4: lwc1        $f20, 0x6964($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6964));
    // 0x808055A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808055AC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808055B0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808055B4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x808055B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808055BC: jal         0x80085998
    // 0x808055C0: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_427;
    // 0x808055C0: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_427:
    // 0x808055C4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808055C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808055CC: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808055D0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808055D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808055D8: jal         0x80085998
    // 0x808055DC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_428;
    // 0x808055DC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_428:
    // 0x808055E0: lui         $a1, 0x3CF5
    ctx->r5 = S32(0X3CF5 << 16);
    // 0x808055E4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808055E8: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x808055EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808055F0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808055F4: jal         0x80085998
    // 0x808055F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_429;
    // 0x808055F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_429:
    // 0x808055FC: lui         $a1, 0x3EDA
    ctx->r5 = S32(0X3EDA << 16);
    // 0x80805600: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80805604: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80805608: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8080560C: ori         $a1, $a1, 0x1CAC
    ctx->r5 = ctx->r5 | 0X1CAC;
    // 0x80805610: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805614: jal         0x80085998
    // 0x80805618: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_430;
    // 0x80805618: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_430:
    // 0x8080561C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6968) << 16);
    // 0x80805620: lwc1        $f20, 0x6968($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6968));
    // 0x80805624: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80805628: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x8080562C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80805630: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80805634: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805638: jal         0x80085998
    // 0x8080563C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_431;
    // 0x8080563C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_431:
    // 0x80805640: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80805644: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80805648: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080564C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80805650: jal         0x80085998
    // 0x80805654: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_432;
    // 0x80805654: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_432:
    // 0x80805658: b           L_80805794
    // 0x8080565C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x8080565C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805660:
    // 0x80805660: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X696C) << 16);
    // 0x80805664: lwc1        $f20, 0x696C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X696C));
    // 0x80805668: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080566C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80805670: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80805674: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80805678: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080567C: jal         0x80085998
    // 0x80805680: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_433;
    // 0x80805680: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_433:
    // 0x80805684: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80805688: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8080568C: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x80805690: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80805694: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805698: jal         0x80085998
    // 0x8080569C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_434;
    // 0x8080569C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_434:
    // 0x808056A0: b           L_80805794
    // 0x808056A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x808056A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808056A8:
    // 0x808056A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2958, 0X6970) << 16);
    // 0x808056AC: lwc1        $f20, 0x6970($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2958, 0X6970));
    // 0x808056B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808056B4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808056B8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808056BC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x808056C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808056C4: jal         0x80085998
    // 0x808056C8: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    _chanim_entrypoint_4(rdram, ctx);
        goto after_435;
    // 0x808056C8: sw          $s3, 0x3D0($sp)
    MEM_W(0X3D0, ctx->r29) = ctx->r19;
    after_435:
    // 0x808056CC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808056D0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808056D4: lw          $a2, 0x3D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3D0);
    // 0x808056D8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808056DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808056E0: jal         0x80085998
    // 0x808056E4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _chanim_entrypoint_4(rdram, ctx);
        goto after_436;
    // 0x808056E4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_436:
    // 0x808056E8: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808056EC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7664) << 16);
    // 0x808056F0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7684) << 16);
    // 0x808056F4: addiu       $s1, $s1, 0x7684
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7684));
    // 0x808056F8: addiu       $v0, $v0, 0x7664
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7664));
    // 0x808056FC: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x80805700: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
L_80805704:
    // 0x80805704: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80805708: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8080570C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80805710: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x80805714: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805718: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080571C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80805720: jal         0x80082630
    // 0x80805724: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_437;
    // 0x80805724: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_437:
    // 0x80805728: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080572C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80805730: bnel        $v0, $s1, L_80805704
    if (ctx->r2 != ctx->r17) {
        // 0x80805734: addiu       $t4, $zero, 0xE
        ctx->r12 = ADD32(0, 0XE);
            goto L_80805704;
    }
    goto skip_222;
    // 0x80805734: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    skip_222:
    // 0x80805738: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2958, 0X7664) << 16);
    // 0x8080573C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2958, 0X7684) << 16);
    // 0x80805740: addiu       $s1, $s1, 0x7684
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2958, 0X7684));
    // 0x80805744: addiu       $v0, $v0, 0x7664
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2958, 0X7664));
    // 0x80805748: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
L_8080574C:
    // 0x8080574C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80805750: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80805754: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80805758: lw          $a3, 0x3D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3D0);
    // 0x8080575C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80805760: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80805764: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80805768: jal         0x80082630
    // 0x8080576C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_438;
    // 0x8080576C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_438:
    // 0x80805770: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80805774: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80805778: bnel        $v0, $s1, L_8080574C
    if (ctx->r2 != ctx->r17) {
        // 0x8080577C: addiu       $t6, $zero, 0xE
        ctx->r14 = ADD32(0, 0XE);
            goto L_8080574C;
    }
    goto skip_223;
    // 0x8080577C: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    skip_223:
    // 0x80805780: b           L_80805794
    // 0x80805784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80805794;
    // 0x80805784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805788:
    // 0x80805788: b           L_80805794
    // 0x8080578C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80805794;
    // 0x8080578C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80805790:
    // 0x80805790: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805794:
    // 0x80805794: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80805798: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8080579C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x808057A0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x808057A4: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x808057A8: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x808057AC: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x808057B0: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x808057B4: jr          $ra
    // 0x808057B8: addiu       $sp, $sp, 0x3C8
    ctx->r29 = ADD32(ctx->r29, 0X3C8);
    return;
    // 0x808057B8: addiu       $sp, $sp, 0x3C8
    ctx->r29 = ADD32(ctx->r29, 0X3C8);
;}
RECOMP_FUNC void func_808000D8_bsbwhirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000E4: lw          $a3, 0x160($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X160);
    // 0x808000E8: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    // 0x808000EC: beq         $a3, $zero, L_80800104
    if (ctx->r7 == 0) {
        // 0x808000F0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800104;
    }
    // 0x808000F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808000F4: jal         0x800863E8
    // 0x808000F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808000F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x808000FC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800100: sw          $v0, 0x160($t7)
    MEM_W(0X160, ctx->r15) = ctx->r2;
L_80800104:
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080010C: jr          $ra
    // 0x80800110: nop

    return;
    // 0x80800110: nop

;}
RECOMP_FUNC void func_801056EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801056EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801056F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801056F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801056F8: jal         0x80105494
    // 0x801056FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x801056FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80105700: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80105704: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80105708: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8010570C: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x80105710: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x80105714: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80105718: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8010571C: sll         $t6, $a0, 21
    ctx->r14 = S32(ctx->r4 << 21);
    // 0x80105720: sra         $a0, $t6, 22
    ctx->r4 = S32(SIGNED(ctx->r14) >> 22);
    // 0x80105724: jal         0x800D86F0
    // 0x80105728: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800D86F0(rdram, ctx);
        goto after_1;
    // 0x80105728: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_1:
    // 0x8010572C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105730: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105734: jr          $ra
    // 0x80105738: nop

    return;
    // 0x80105738: nop

;}
RECOMP_FUNC void func_80800538_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800538: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080053C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800540: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800544: jal         0x8009E710
    // 0x80800548: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_0;
    // 0x80800548: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800550: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800554: jal         0x8009CA70
    // 0x80800558: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8009CA70(rdram, ctx);
        goto after_1;
    // 0x80800558: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_1:
    // 0x8080055C: bnel        $v0, $zero, L_8080060C
    if (ctx->r2 != 0) {
        // 0x80800560: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080060C;
    }
    goto skip_0;
    // 0x80800560: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800564: jal         0x80085050
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_15(rdram, ctx);
        goto after_2;
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080056C: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x80800570: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800578: jal         0x8009F1C8
    // 0x8080057C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_3;
    // 0x8080057C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800584: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800588: jal         0x8009F1C8
    // 0x8080058C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_4;
    // 0x8080058C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800594: jal         0x800A0CF4
    // 0x80800598: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_5;
    // 0x80800598: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A0: jal         0x800A0CE8
    // 0x808005A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CE8(rdram, ctx);
        goto after_6;
    // 0x808005A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005AC: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808005B0: jal         0x8009BFE4
    // 0x808005B4: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_7;
    // 0x808005B4: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_7:
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005BC: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808005C0: jal         0x8009C554
    // 0x808005C4: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_8;
    // 0x808005C4: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_8:
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005CC: jal         0x80095760
    // 0x808005D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baflag_set(rdram, ctx);
        goto after_9;
    // 0x808005D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x808005D4: lui         $a3, 0x3E75
    ctx->r7 = S32(0X3E75 << 16);
    // 0x808005D8: ori         $a3, $a3, 0xC28F
    ctx->r7 = ctx->r7 | 0XC28F;
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808005E4: jal         0x80094F14
    // 0x808005E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80094F14(rdram, ctx);
        goto after_10;
    // 0x808005E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x808005EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F0: jal         0x800931AC
    // 0x808005F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800931AC(rdram, ctx);
        goto after_11;
    // 0x808005F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x808005F8: jal         0x8009E4AC
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_12;
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800600: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x80800604: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
    // 0x80800608: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080060C:
    // 0x8080060C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800610: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800614: jr          $ra
    // 0x80800618: nop

    return;
    // 0x80800618: nop

;}
RECOMP_FUNC void sccustom_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800890: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800894: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800898: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080089C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808008A0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808008A4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808008A8: jal         0x8080084C
    // 0x808008AC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8080084C_sccustom(rdram, ctx);
        goto after_0;
    // 0x808008AC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808008B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008B4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808008B8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808008BC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808008C0: jal         0x80800000
    // 0x808008C4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80800000_sccustom(rdram, ctx);
        goto after_1;
    // 0x808008C4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x808008C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008D0: jr          $ra
    // 0x808008D4: nop

    return;
    // 0x808008D4: nop

;}
RECOMP_FUNC void func_800AE6FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE6FC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800AE700: jr          $ra
    // 0x800AE704: sh          $a1, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r5;
    return;
    // 0x800AE704: sh          $a1, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_8080013C_bskazstilt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080013C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800140: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800144: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800148: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080014C: jal         0x8009E77C
    // 0x80800150: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x80800150: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80800154: bnel        $v0, $zero, L_80800224
    if (ctx->r2 != 0) {
        // 0x80800158: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800224;
    }
    goto skip_0;
    // 0x80800158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080015C: jal         0x800832E0
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: jal         0x80095774
    // 0x8080016C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    baflag_clear(rdram, ctx);
        goto after_2;
    // 0x8080016C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_2:
    // 0x80800170: jal         0x8009E4AC
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_3;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080017C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800180: jal         0x8009E5A4
    // 0x80800184: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009E5A4(rdram, ctx);
        goto after_4;
    // 0x80800184: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800190: jal         0x8009E55C
    // 0x80800194: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_8009E55C(rdram, ctx);
        goto after_5;
    // 0x80800194: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_5:
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001A0: jal         0x8009E53C
    // 0x808001A4: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    func_8009E53C(rdram, ctx);
        goto after_6;
    // 0x808001A4: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    after_6:
    // 0x808001A8: jal         0x8009EFA8
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_7;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808001B0: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x808001B4: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: jal         0x8009F1C8
    // 0x808001C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_8;
    // 0x808001C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001CC: jal         0x8009F1C8
    // 0x808001D0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_9;
    // 0x808001D0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_9:
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D8: jal         0x800A0CF4
    // 0x808001DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_10;
    // 0x808001DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: jal         0x800A0CE8
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CE8(rdram, ctx);
        goto after_11;
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: jal         0x800A0DD0
    // 0x808001F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0DD0(rdram, ctx);
        goto after_12;
    // 0x808001F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800200: jal         0x8009BFE4
    // 0x80800204: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_13;
    // 0x80800204: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_13:
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800210: jal         0x8009C554
    // 0x80800214: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_14;
    // 0x80800214: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_14:
    // 0x80800218: jal         0x80084428
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baalarm_new(rdram, ctx);
        goto after_15;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800224:
    // 0x80800224: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800228: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080022C: jr          $ra
    // 0x80800230: nop

    return;
    // 0x80800230: nop

;}
