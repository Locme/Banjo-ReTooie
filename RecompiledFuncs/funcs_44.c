#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void mlwave_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080010C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800110: swc1        $f12, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f12.u32l;
    // 0x80800114: jr          $ra
    // 0x80800118: swc1        $f14, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x80800118: swc1        $f14, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_80800388_chworlddoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800388: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080038C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800390: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800394: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800398: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080039C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808003A0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808003A4: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x808003A8: beq         $at, $zero, L_80800694
    if (ctx->r1 == 0) {
        // 0x808003AC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800694;
    }
    // 0x808003AC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808003B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2476, 0X95C) << 16);
    // 0x808003B4: addu        $at, $at, $t8
    gpr jr_addend_808003BC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808003B8: lw          $t8, 0x95C($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2476, 0X95C));
    // 0x808003BC: jr          $t8
    // 0x808003C0: nop

    switch (jr_addend_808003BC >> 2) {
        case 0: goto L_808003C4; break;
        case 1: goto L_80800494; break;
        case 2: goto L_80800554; break;
        case 3: goto L_8080063C; break;
        case 4: goto L_8080065C; break;
        case 5: goto L_8080067C; break;
        default: switch_error(__func__, 0x808003BC, 0x8080095C);
    }
    // 0x808003C0: nop

L_808003C4:
    // 0x808003C4: jal         0x80085730
    // 0x808003C8: nop

    _capod_entrypoint_18(rdram, ctx);
        goto after_0;
    // 0x808003C8: nop

    after_0:
    // 0x808003CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2476, 0X974) << 16);
    // 0x808003D0: lwc1        $f4, 0x974($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2476, 0X974));
    // 0x808003D4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x808003D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2476, 0X978) << 16);
    // 0x808003DC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808003E0: nop

    // 0x808003E4: bc1fl       L_808003F8
    if (!c1cs) {
        // 0x808003E8: lw          $v1, 0x24($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X24);
            goto L_808003F8;
    }
    goto skip_0;
    // 0x808003E8: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x808003EC: lwc1        $f6, 0x978($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2476, 0X978));
    // 0x808003F0: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x808003F4: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
L_808003F8:
    // 0x808003F8: bnel        $v1, $zero, L_80800424
    if (ctx->r3 != 0) {
        // 0x808003FC: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80800424;
    }
    goto skip_1;
    // 0x808003FC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_1:
    // 0x80800400: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800404: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800408: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080040C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800410: jal         0x800E15CC
    // 0x80800414: nop

    func_800E15CC(rdram, ctx);
        goto after_1;
    // 0x80800414: nop

    after_1:
    // 0x80800418: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8080041C: sw          $v1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r3;
    // 0x80800420: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_80800424:
    // 0x80800424: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800428: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080042C: addiu       $a0, $v1, -0x1
    ctx->r4 = ADD32(ctx->r3, -0X1);
    // 0x80800430: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800434: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800438: jal         0x800E13F0
    // 0x8080043C: nop

    func_800E13F0(rdram, ctx);
        goto after_2;
    // 0x8080043C: nop

    after_2:
    // 0x80800440: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2476, 0X9E8) << 16);
    // 0x80800444: addiu       $a3, $a3, 0x9E8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2476, 0X9E8));
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080044C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800450: jal         0x80089D50
    // 0x80800454: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800454: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80800458: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2476, 0X97C) << 16);
    // 0x8080045C: lwc1        $f18, 0x97C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2476, 0X97C));
    // 0x80800460: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800464: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800468: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8080046C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80800470: jal         0x800C4B70
    // 0x80800474: nop

    func_800C4B70(rdram, ctx);
        goto after_4;
    // 0x80800474: nop

    after_4:
    // 0x80800478: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8080047C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800480: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800484: jal         0x80018820
    // 0x80800488: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80018820(rdram, ctx);
        goto after_5;
    // 0x80800488: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x8080048C: b           L_80800698
    // 0x80800490: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800698;
    // 0x80800490: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800494:
    // 0x80800494: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800498: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2476, 0X9E8) << 16);
    // 0x8080049C: addiu       $a3, $a3, 0x9E8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2476, 0X9E8));
    // 0x808004A0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A8: jal         0x80089D50
    // 0x808004AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x808004AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x808004B0: jal         0x800C4B70
    // 0x808004B4: addiu       $a0, $zero, 0x5DC0
    ctx->r4 = ADD32(0, 0X5DC0);
    func_800C4B70(rdram, ctx);
        goto after_7;
    // 0x808004B4: addiu       $a0, $zero, 0x5DC0
    ctx->r4 = ADD32(0, 0X5DC0);
    after_7:
    // 0x808004B8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x808004BC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808004C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004C4: jal         0x80018820
    // 0x808004C8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80018820(rdram, ctx);
        goto after_8;
    // 0x808004C8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_8:
    // 0x808004CC: jal         0x800D90A4
    // 0x808004D0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_9;
    // 0x808004D0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_9:
    // 0x808004D4: beq         $v0, $zero, L_808004FC
    if (ctx->r2 == 0) {
        // 0x808004D8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808004FC;
    }
    // 0x808004D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E0: jal         0x80800214
    // 0x808004E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800214_chworlddoors(rdram, ctx);
        goto after_10;
    // 0x808004E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x808004E8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808004EC: jal         0x800EE7F8
    // 0x808004F0: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x808004F0: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_11:
    // 0x808004F4: b           L_80800534
    // 0x808004F8: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
        goto L_80800534;
    // 0x808004F8: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
L_808004FC:
    // 0x808004FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800500: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800504: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800508: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080050C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800510: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800514: jal         0x800F10B4
    // 0x80800518: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_12;
    // 0x80800518: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x8080051C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800520: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800524: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800528: jal         0x800EFE50
    // 0x8080052C: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    func_800EFE50(rdram, ctx);
        goto after_13;
    // 0x8080052C: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    after_13:
    // 0x80800530: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
L_80800534:
    // 0x80800534: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2476, 0X9D8) << 16);
    // 0x80800538: addiu       $a3, $a3, 0x9D8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2476, 0X9D8));
    // 0x8080053C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800540: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800544: jal         0x80089D68
    // 0x80800548: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_14;
    // 0x80800548: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x8080054C: b           L_80800694
    // 0x80800550: sb          $v0, 0x34($s0)
    MEM_B(0X34, ctx->r16) = ctx->r2;
        goto L_80800694;
    // 0x80800550: sb          $v0, 0x34($s0)
    MEM_B(0X34, ctx->r16) = ctx->r2;
L_80800554:
    // 0x80800554: jal         0x800D90A4
    // 0x80800558: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_15;
    // 0x80800558: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_15:
    // 0x8080055C: beq         $v0, $zero, L_8080058C
    if (ctx->r2 == 0) {
        // 0x80800560: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080058C;
    }
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800568: jal         0x80800214
    // 0x8080056C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800214_chworlddoors(rdram, ctx);
        goto after_16;
    // 0x8080056C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_16:
    // 0x80800570: jal         0x80089D48
    // 0x80800574: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_17;
    // 0x80800574: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    after_17:
    // 0x80800578: sb          $v0, 0x34($s0)
    MEM_B(0X34, ctx->r16) = ctx->r2;
    // 0x8080057C: jal         0x80089D40
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800584: b           L_80800698
    // 0x80800588: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800698;
    // 0x80800588: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080058C:
    // 0x8080058C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800590: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2476, 0X9E8) << 16);
    // 0x80800594: addiu       $a3, $a3, 0x9E8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2476, 0X9E8));
    // 0x80800598: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080059C: jal         0x80089D50
    // 0x808005A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_19;
    // 0x808005A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_19:
    // 0x808005A4: jal         0x800C4B70
    // 0x808005A8: addiu       $a0, $zero, 0x5DC0
    ctx->r4 = ADD32(0, 0X5DC0);
    func_800C4B70(rdram, ctx);
        goto after_20;
    // 0x808005A8: addiu       $a0, $zero, 0x5DC0
    ctx->r4 = ADD32(0, 0X5DC0);
    after_20:
    // 0x808005AC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x808005B0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808005B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005B8: jal         0x80018820
    // 0x808005BC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80018820(rdram, ctx);
        goto after_21;
    // 0x808005BC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_21:
    // 0x808005C0: jal         0x80800000
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chworlddoors(rdram, ctx);
        goto after_22;
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808005C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2476, 0X980) << 16);
    // 0x808005CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808005D0: lwc1        $f14, 0x980($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2476, 0X980));
    // 0x808005D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2476, 0X984) << 16);
    // 0x808005D8: lwc1        $f16, 0x984($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2476, 0X984));
    // 0x808005DC: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808005E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808005E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808005E8: jal         0x800F10B4
    // 0x808005EC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_23;
    // 0x808005EC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_23:
    // 0x808005F0: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x808005F4: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    // 0x808005F8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2476, 0X9D8) << 16);
    // 0x808005FC: addiu       $a3, $a3, 0x9D8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2476, 0X9D8));
    // 0x80800600: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800604: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800608: jal         0x80089D68
    // 0x8080060C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_24;
    // 0x8080060C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_24:
    // 0x80800610: sb          $v0, 0x34($s0)
    MEM_B(0X34, ctx->r16) = ctx->r2;
    // 0x80800614: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2476, 0X9E8) << 16);
    // 0x80800618: addiu       $a3, $a3, 0x9E8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2476, 0X9E8));
    // 0x8080061C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800624: jal         0x80089D50
    // 0x80800628: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_25;
    // 0x80800628: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_25:
    // 0x8080062C: jal         0x800C4B70
    // 0x80800630: addiu       $a0, $zero, 0x5DC0
    ctx->r4 = ADD32(0, 0X5DC0);
    func_800C4B70(rdram, ctx);
        goto after_26;
    // 0x80800630: addiu       $a0, $zero, 0x5DC0
    ctx->r4 = ADD32(0, 0X5DC0);
    after_26:
    // 0x80800634: b           L_80800698
    // 0x80800638: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800698;
    // 0x80800638: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080063C:
    // 0x8080063C: jal         0x800D90A4
    // 0x80800640: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_27;
    // 0x80800640: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_27:
    // 0x80800644: beq         $v0, $zero, L_80800694
    if (ctx->r2 == 0) {
        // 0x80800648: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800694;
    }
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080064C: jal         0x80800214
    // 0x80800650: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800214_chworlddoors(rdram, ctx);
        goto after_28;
    // 0x80800650: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_28:
    // 0x80800654: b           L_80800698
    // 0x80800658: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800698;
    // 0x80800658: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080065C:
    // 0x8080065C: jal         0x800D90A4
    // 0x80800660: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_29;
    // 0x80800660: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_29:
    // 0x80800664: beq         $v0, $zero, L_80800694
    if (ctx->r2 == 0) {
        // 0x80800668: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800694;
    }
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080066C: jal         0x80800214
    // 0x80800670: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800214_chworlddoors(rdram, ctx);
        goto after_30;
    // 0x80800670: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_30:
    // 0x80800674: b           L_80800698
    // 0x80800678: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800698;
    // 0x80800678: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080067C:
    // 0x8080067C: jal         0x800D90A4
    // 0x80800680: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_31;
    // 0x80800680: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_31:
    // 0x80800684: beql        $v0, $zero, L_80800698
    if (ctx->r2 == 0) {
        // 0x80800688: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800698;
    }
    goto skip_2;
    // 0x80800688: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8080068C: jal         0x80088830
    // 0x80800690: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_32;
    // 0x80800690: nop

    after_32:
L_80800694:
    // 0x80800694: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800698:
    // 0x80800698: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080069C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808006A0: jr          $ra
    // 0x808006A4: nop

    return;
    // 0x808006A4: nop

;}
RECOMP_FUNC void func_808004F8_chboxingglove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800500: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800504: jal         0x800DA298
    // 0x80800508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8080050C: beql        $v0, $zero, L_80800534
    if (ctx->r2 == 0) {
        // 0x80800510: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800534;
    }
    goto skip_0;
    // 0x80800510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800514: jal         0x800FFAB0
    // 0x80800518: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800518: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080051C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800520: jal         0x800FFA88
    // 0x80800524: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    func_800FFA88(rdram, ctx);
        goto after_2;
    // 0x80800524: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    after_2:
    // 0x80800528: b           L_80800534
    // 0x8080052C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800534;
    // 0x8080052C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800534:
    // 0x80800534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080053C: jr          $ra
    // 0x80800540: nop

    return;
    // 0x80800540: nop

;}
RECOMP_FUNC void _bskazdie_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800833D8: syscall     58
    recomp_syscall_handler(rdram, ctx, 0x800833D8);
    return;
    // 0x800833DC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808000EC_chminegrill2switches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F4: addiu       $a1, $zero, 0xA28
    ctx->r5 = ADD32(0, 0XA28);
    // 0x808000F8: jal         0x80800000
    // 0x808000FC: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    func_80800000_chminegrill2switches(rdram, ctx);
        goto after_0;
    // 0x808000FC: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    after_0:
    // 0x80800100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800108: jr          $ra
    // 0x8080010C: nop

    return;
    // 0x8080010C: nop

;}
RECOMP_FUNC void func_80800684_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800684: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800688: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080068C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800690: sw          $a3, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r7;
    // 0x80800694: sw          $a2, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r6;
    // 0x80800698: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x8080069C: swc1        $f12, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f12.u32l;
    // 0x808006A0: jr          $ra
    // 0x808006A4: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x808006A4: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_808012F0_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012F8: jal         0x80085148
    // 0x808012FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _baspin_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808012FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801300: jal         0x808008D8
    // 0x80801304: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808008D8_bssub(rdram, ctx);
        goto after_1;
    // 0x80801304: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080130C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801310: jr          $ra
    // 0x80801314: nop

    return;
    // 0x80801314: nop

;}
RECOMP_FUNC void func_800EF1B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF1B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EF1BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EF1C0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800EF1C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800EF1C8: jal         0x800137F4
    // 0x800EF1CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800137F4(rdram, ctx);
        goto after_0;
    // 0x800EF1CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800EF1D0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EF1D4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800EF1D8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800EF1DC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EF1E0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800EF1E4: jal         0x80013788
    // 0x800EF1E8: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    func_80013788(rdram, ctx);
        goto after_1;
    // 0x800EF1E8: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    after_1:
    // 0x800EF1EC: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EF1F0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800EF1F4: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800EF1F8: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800EF1FC: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800EF200: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800EF204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EF208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EF20C: jr          $ra
    // 0x800EF210: nop

    return;
    // 0x800EF210: nop

;}
RECOMP_FUNC void func_800D3934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3934: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D3938: lbu         $v0, -0x4C0E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4C0E);
    // 0x800D393C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800D3940: jr          $ra
    // 0x800D3944: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    return;
    // 0x800D3944: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_8080015C_chidgoldhorde(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800160: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800164: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800168: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080016C: jal         0x80100094
    // 0x80800170: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800170: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800174: jal         0x800DC0C0
    // 0x80800178: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x80800178: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x8080017C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800180: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800184: nop

    // 0x80800188: bc1fl       L_808001D0
    if (!c1cs) {
        // 0x8080018C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001D0;
    }
    goto skip_0;
    // 0x8080018C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800190: jal         0x800BEA88
    // 0x80800194: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_2;
    // 0x80800194: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800198: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8080019C: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x808001A0: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x808001A4: jal         0x800DC128
    // 0x808001A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DC128(rdram, ctx);
        goto after_3;
    // 0x808001A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x808001AC: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x808001B0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808001B4: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x808001B8: addiu       $a2, $a2, 0x5A10
    ctx->r6 = ADD32(ctx->r6, 0X5A10);
    // 0x808001BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001C0: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x808001C4: jal         0x80088678
    // 0x808001C8: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    _glid_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x808001C8: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    after_4:
    // 0x808001CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001D0:
    // 0x808001D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001D8: jr          $ra
    // 0x808001DC: nop

    return;
    // 0x808001DC: nop

;}
RECOMP_FUNC void _gcdialogcamera_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088080: syscall     669
    recomp_syscall_handler(rdram, ctx, 0x80088080);
    return;
    // 0x80088084: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800F8358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8358: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F835C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F8360: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8368: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800F836C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F8370: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F8374: jal         0x80084950
    // 0x800F8378: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _baduo_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x800F8378: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x800F837C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8384: jr          $ra
    // 0x800F8388: nop

    return;
    // 0x800F8388: nop

;}
RECOMP_FUNC void func_80800C4C_chfloaty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C54: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800C58: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800C5C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800C60: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800C64: bgez        $t8, L_80800C90
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800C68: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800C90;
    }
    // 0x80800C68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C6C: addiu       $a2, $zero, 0x7D0
    ctx->r6 = ADD32(0, 0X7D0);
    // 0x80800C70: jal         0x800FCAE0
    // 0x80800C74: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800FCAE0(rdram, ctx);
        goto after_0;
    // 0x80800C74: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800C78: jal         0x800FCA90
    // 0x80800C7C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800FCA90(rdram, ctx);
        goto after_1;
    // 0x80800C7C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_1:
    // 0x80800C80: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800C84: lbu         $t9, 0x65($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X65);
    // 0x80800C88: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x80800C8C: sb          $t0, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r8;
L_80800C90:
    // 0x80800C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C98: jr          $ra
    // 0x80800C9C: nop

    return;
    // 0x80800C9C: nop

;}
RECOMP_FUNC void func_808005BC_gccollectDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005C4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808005C8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808005CC: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x808005D0: addiu       $a0, $zero, 0x21F
    ctx->r4 = ADD32(0, 0X21F);
    // 0x808005D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005D8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x808005DC: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x808005E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808005E4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x808005E8: lh          $t9, 0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4);
    // 0x808005EC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x808005F0: jal         0x80108C90
    // 0x808005F4: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    func_80108C90(rdram, ctx);
        goto after_0;
    // 0x808005F4: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    after_0:
    // 0x808005F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808005FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800600: jal         0x800D053C
    // 0x80800604: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D053C(rdram, ctx);
        goto after_1;
    // 0x80800604: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800608: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8080060C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800610: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800614: jal         0x800D05E4
    // 0x80800618: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    func_800D05E4(rdram, ctx);
        goto after_2;
    // 0x80800618: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    after_2:
    // 0x8080061C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800620: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800624: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800628: jal         0x800CFBC8
    // 0x8080062C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800CFBC8(rdram, ctx);
        goto after_3;
    // 0x8080062C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80800630: jal         0x80088458
    // 0x80800634: nop

    _glreflight_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800634: nop

    after_4:
    // 0x80800638: andi        $t1, $v0, 0xFF
    ctx->r9 = ctx->r2 & 0XFF;
    // 0x8080063C: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x80800640: beql        $t1, $at, L_80800654
    if (ctx->r9 == ctx->r1) {
        // 0x80800644: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800654;
    }
    goto skip_0;
    // 0x80800644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800648: jal         0x8010A570
    // 0x8080064C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8010A570(rdram, ctx);
        goto after_5;
    // 0x8080064C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80800650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800654:
    // 0x80800654: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800658: jr          $ra
    // 0x8080065C: nop

    return;
    // 0x8080065C: nop

;}
RECOMP_FUNC void func_8080198C_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080198C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801994: jal         0x80084C58
    // 0x80801998: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bafly_entrypoint_18(rdram, ctx);
        goto after_0;
    // 0x80801998: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080199C: jal         0x80800188
    // 0x808019A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800188_bskazfly(rdram, ctx);
        goto after_1;
    // 0x808019A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808019A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808019A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808019AC: jr          $ra
    // 0x808019B0: nop

    return;
    // 0x808019B0: nop

;}
RECOMP_FUNC void func_80092750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092750: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092754: sb          $a1, 0x89($t6)
    MEM_B(0X89, ctx->r14) = ctx->r5;
    // 0x80092758: lw          $t7, 0x50($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X50);
    // 0x8009275C: sb          $a2, 0x8A($t7)
    MEM_B(0X8A, ctx->r15) = ctx->r6;
    // 0x80092760: lw          $t8, 0x50($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X50);
    // 0x80092764: sb          $a3, 0x8B($t8)
    MEM_B(0X8B, ctx->r24) = ctx->r7;
    // 0x80092768: lw          $t0, 0x50($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X50);
    // 0x8009276C: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x80092770: jr          $ra
    // 0x80092774: sb          $t9, 0x8C($t0)
    MEM_B(0X8C, ctx->r8) = ctx->r25;
    return;
    // 0x80092774: sb          $t9, 0x8C($t0)
    MEM_B(0X8C, ctx->r8) = ctx->r25;
;}
RECOMP_FUNC void func_808000DC_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E0: beq         $a1, $zero, L_80800100
    if (ctx->r5 == 0) {
        // 0x808000E4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800100;
    }
    // 0x808000E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E8: lui         $a2, 0x3F75
    ctx->r6 = S32(0X3F75 << 16);
    // 0x808000EC: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x808000F0: jal         0x8009DE38
    // 0x808000F4: addiu       $a1, $zero, 0x4433
    ctx->r5 = ADD32(0, 0X4433);
    func_8009DE38(rdram, ctx);
        goto after_0;
    // 0x808000F4: addiu       $a1, $zero, 0x4433
    ctx->r5 = ADD32(0, 0X4433);
    after_0:
    // 0x808000F8: b           L_80800114
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800114;
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800100:
    // 0x80800100: lui         $a2, 0x3F85
    ctx->r6 = S32(0X3F85 << 16);
    // 0x80800104: ori         $a2, $a2, 0x1EB8
    ctx->r6 = ctx->r6 | 0X1EB8;
    // 0x80800108: jal         0x8009DE38
    // 0x8080010C: addiu       $a1, $zero, 0x4433
    ctx->r5 = ADD32(0, 0X4433);
    func_8009DE38(rdram, ctx);
        goto after_1;
    // 0x8080010C: addiu       $a1, $zero, 0x4433
    ctx->r5 = ADD32(0, 0X4433);
    after_1:
    // 0x80800110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800114:
    // 0x80800114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800118: jr          $ra
    // 0x8080011C: nop

    return;
    // 0x8080011C: nop

;}
RECOMP_FUNC void _bamum_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F18: syscall     142
    recomp_syscall_handler(rdram, ctx, 0x80084F18);
    return;
    // 0x80084F1C: xori        $t0, $zero, 0x8
    ctx->r8 = 0 ^ 0X8;
;}
RECOMP_FUNC void func_8010B71C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B71C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8010B720: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010B724: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010B728: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010B72C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8010B730: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8010B734: jal         0x8010C460
    // 0x8010B738: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    func_8010C460(rdram, ctx);
        goto after_0;
    // 0x8010B738: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010B73C: jal         0x800D8FF8
    // 0x8010B740: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8010B740: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8010B744: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8010B748: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8010B74C: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8010B750: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8010B754: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8010B758: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8010B75C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010B760: addiu       $a2, $a2, 0x6F40
    ctx->r6 = ADD32(ctx->r6, 0X6F40);
    // 0x8010B764: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010B768: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8010B76C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x8010B770: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8010B774: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x8010B778: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8010B77C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8010B780: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8010B784: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8010B788: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8010B78C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8010B790: jal         0x800BEF00
    // 0x8010B794: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800BEF00(rdram, ctx);
        goto after_2;
    // 0x8010B794: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x8010B798: beq         $v0, $zero, L_8010B7D4
    if (ctx->r2 == 0) {
        // 0x8010B79C: lwc1        $f16, 0x2C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_8010B7D4;
    }
    // 0x8010B79C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8010B7A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8010B7A4: lh          $t6, 0x8E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8E);
    // 0x8010B7A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010B7AC: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x8010B7B0: beq         $t6, $zero, L_8010B7CC
    if (ctx->r14 == 0) {
        // 0x8010B7B4: swc1        $f0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
            goto L_8010B7CC;
    }
    // 0x8010B7B4: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8010B7B8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010B7BC: addiu       $a1, $a1, 0x6F40
    ctx->r5 = ADD32(ctx->r5, 0X6F40);
    // 0x8010B7C0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8010B7C4: jal         0x801045AC
    // 0x8010B7C8: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    func_801045AC(rdram, ctx);
        goto after_3;
    // 0x8010B7C8: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    after_3:
L_8010B7CC:
    // 0x8010B7CC: b           L_8010B7EC
    // 0x8010B7D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010B7EC;
    // 0x8010B7D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010B7D4:
    // 0x8010B7D4: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8010B7D8: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8010B7DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010B7E0: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8010B7E4: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8010B7E8: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
L_8010B7EC:
    // 0x8010B7EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010B7F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010B7F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8010B7F8: jr          $ra
    // 0x8010B7FC: nop

    return;
    // 0x8010B7FC: nop

;}
RECOMP_FUNC void func_80800024_chmole_lagoon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800030: jal         0x800899D0
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sumole_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080003C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800040: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80800044: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800048: addiu       $t8, $t6, -0x32
    ctx->r24 = ADD32(ctx->r14, -0X32);
    // 0x8080004C: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x80800050: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
    // 0x80800054: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80800058: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8080005C: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x80800060: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80800064: sh          $t2, 0x76($a0)
    MEM_H(0X76, ctx->r4) = ctx->r10;
    // 0x80800068: bgez        $t4, L_8080007C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8080006C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080007C;
    }
    // 0x8080006C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800070: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800074: nop

    // 0x80800078: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8080007C:
    // 0x8080007C: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void func_8009DB04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DB04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009DB08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009DB0C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8009DB10: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8009DB14: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8009DB18: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8009DB1C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8009DB20: jal         0x8009DAAC
    // 0x8009DB24: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8009DAAC(rdram, ctx);
        goto after_0;
    // 0x8009DB24: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x8009DB28: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8009DB2C: jal         0x8009C128
    // 0x8009DB30: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x8009DB30: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8009DB34: jal         0x8009D3D8
    // 0x8009DB38: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8009D3D8(rdram, ctx);
        goto after_2;
    // 0x8009DB38: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8009DB3C: beq         $v0, $zero, L_8009DB78
    if (ctx->r2 == 0) {
        // 0x8009DB40: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_8009DB78;
    }
    // 0x8009DB40: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8009DB44: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8009DB48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009DB4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DB50: lwc1        $f6, 0x5390($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5390);
    // 0x8009DB54: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8009DB58: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8009DB5C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8009DB60: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x8009DB64: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8009DB68: jal         0x800C4208
    // 0x8009DB6C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C4208(rdram, ctx);
        goto after_3;
    // 0x8009DB6C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8009DB70: b           L_8009DBA4
    // 0x8009DB74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009DBA4;
    // 0x8009DB74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DB78:
    // 0x8009DB78: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8009DB7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009DB80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DB84: lwc1        $f10, 0x5394($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5394);
    // 0x8009DB88: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8009DB8C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8009DB90: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x8009DB94: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8009DB98: jal         0x800C4244
    // 0x8009DB9C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800C4244(rdram, ctx);
        goto after_4;
    // 0x8009DB9C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x8009DBA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DBA4:
    // 0x8009DBA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8009DBA8: jr          $ra
    // 0x8009DBAC: nop

    return;
    // 0x8009DBAC: nop

;}
RECOMP_FUNC void babackpack_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E8: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x808000EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000F0: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x808000F4: beq         $a1, $zero, L_8080010C
    if (ctx->r5 == 0) {
        // 0x808000F8: nop
    
            goto L_8080010C;
    }
    // 0x808000F8: nop

    // 0x808000FC: jal         0x800D674C
    // 0x80800100: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x80800100: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800104: b           L_80800110
    // 0x80800108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800110;
    // 0x80800108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080010C:
    // 0x8080010C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800110:
    // 0x80800110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800114: jr          $ra
    // 0x80800118: nop

    return;
    // 0x80800118: nop

;}
RECOMP_FUNC void has_free_block_after(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AC9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001ACA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001ACA4: jal         0x8001AAE4
    // 0x8001ACA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    find_free_block(rdram, ctx);
        goto after_0;
    // 0x8001ACA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8001ACAC: beq         $v0, $zero, L_8001ACBC
    if (ctx->r2 == 0) {
        // 0x8001ACB0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001ACBC;
    }
    // 0x8001ACB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001ACB4: b           L_8001ACC0
    // 0x8001ACB8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8001ACC0;
    // 0x8001ACB8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001ACBC:
    // 0x8001ACBC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001ACC0:
    // 0x8001ACC0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001ACC4: jr          $ra
    // 0x8001ACC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001ACC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8080373C_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080373C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803740: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803744: jal         0x80100094
    // 0x80803748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080374C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80803750: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803754: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80803758: sh          $t6, 0xAC($v0)
    MEM_H(0XAC, ctx->r2) = ctx->r14;
    // 0x8080375C: swc1        $f4, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->f4.u32l;
    // 0x80803760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803768: jr          $ra
    // 0x8080376C: nop

    return;
    // 0x8080376C: nop

;}
RECOMP_FUNC void func_8010F384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010F384: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8010F388: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8010F38C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010F390: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8010F394: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8010F398: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8010F39C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8010F3A0: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8010F3A4: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8010F3A8: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8010F3AC: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8010F3B0: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8010F3B4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8010F3B8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8010F3BC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010F3C0: bgez        $a1, L_8010F3D0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8010F3C4: sw          $a2, 0xC0($sp)
        MEM_W(0XC0, ctx->r29) = ctx->r6;
            goto L_8010F3D0;
    }
    // 0x8010F3C4: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    // 0x8010F3C8: b           L_8010F3D4
    // 0x8010F3CC: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
        goto L_8010F3D4;
    // 0x8010F3CC: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
L_8010F3D0:
    // 0x8010F3D0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8010F3D4:
    // 0x8010F3D4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010F3D8: addiu       $v1, $v1, 0x7240
    ctx->r3 = ADD32(ctx->r3, 0X7240);
    // 0x8010F3DC: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x8010F3E0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8010F3E4: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8010F3E8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8010F3EC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8010F3F0: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x8010F3F4: jal         0x800DF8B4
    // 0x8010F3F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DF8B4(rdram, ctx);
        goto after_0;
    // 0x8010F3F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8010F3FC: addiu       $s1, $sp, 0xA8
    ctx->r17 = ADD32(ctx->r29, 0XA8);
    // 0x8010F400: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8010F404: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010F408: jal         0x800B237C
    // 0x8010F40C: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    func_800B237C(rdram, ctx);
        goto after_1;
    // 0x8010F40C: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    after_1:
    // 0x8010F410: jal         0x800DF8C4
    // 0x8010F414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DF8C4(rdram, ctx);
        goto after_2;
    // 0x8010F414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8010F418: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8010F41C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010F420: jal         0x80019224
    // 0x8010F424: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80019224(rdram, ctx);
        goto after_3;
    // 0x8010F424: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x8010F428: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8010F42C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010F430: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8010F434: jal         0x800DF900
    // 0x8010F438: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    func_800DF900(rdram, ctx);
        goto after_4;
    // 0x8010F438: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x8010F43C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8010F440: jal         0x800C8760
    // 0x8010F444: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C8760(rdram, ctx);
        goto after_5;
    // 0x8010F444: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8010F448: beq         $v0, $zero, L_8010F624
    if (ctx->r2 == 0) {
        // 0x8010F44C: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8010F624;
    }
    // 0x8010F44C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8010F450: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x8010F454: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8010F458: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8010F45C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8010F460: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010F464: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8010F468: addiu       $s6, $sp, 0x88
    ctx->r22 = ADD32(ctx->r29, 0X88);
    // 0x8010F46C: addiu       $s5, $sp, 0x74
    ctx->r21 = ADD32(ctx->r29, 0X74);
    // 0x8010F470: addiu       $s4, $sp, 0x64
    ctx->r20 = ADD32(ctx->r29, 0X64);
    // 0x8010F474: addiu       $s3, $sp, 0x7C
    ctx->r19 = ADD32(ctx->r29, 0X7C);
L_8010F478:
    // 0x8010F478: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8010F47C: jal         0x800C8800
    // 0x8010F480: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800C8800(rdram, ctx);
        goto after_6;
    // 0x8010F480: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_6:
    // 0x8010F484: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8010F488: jal         0x800C883C
    // 0x8010F48C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800C883C(rdram, ctx);
        goto after_7;
    // 0x8010F48C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_7:
    // 0x8010F490: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8010F494: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8010F498: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8010F49C: lwc1        $f18, 0xAC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8010F4A0: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8010F4A4: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8010F4A8: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8010F4AC: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8010F4B0: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8010F4B4: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x8010F4B8: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010F4BC: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8010F4C0: swc1        $f2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f2.u32l;
    // 0x8010F4C4: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8010F4C8: swc1        $f14, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f14.u32l;
    // 0x8010F4CC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010F4D0: jal         0x8002DCA0
    // 0x8010F4D4: add.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8010F4D4: add.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f16.fl;
    after_8:
    // 0x8010F4D8: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8010F4DC: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8010F4E0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8010F4E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8010F4E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010F4EC: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8010F4F0: nop

    // 0x8010F4F4: bc1tl       L_8010F610
    if (c1cs) {
        // 0x8010F4F8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8010F610;
    }
    goto skip_0;
    // 0x8010F4F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x8010F4FC: jal         0x800C8900
    // 0x8010F500: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800C8900(rdram, ctx);
        goto after_9;
    // 0x8010F500: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_9:
    // 0x8010F504: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8010F508: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8010F50C: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8010F510: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8010F514: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8010F518: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x8010F51C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8010F520: div.s       $f4, $f20, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f20.fl, ctx->f16.fl);
    // 0x8010F524: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8010F528: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8010F52C: nop

    // 0x8010F530: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010F534: sub.s       $f6, $f24, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x8010F538: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8010F53C: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8010F540: mfc1        $s1, $f16
    ctx->r17 = (int32_t)ctx->f16.u32l;
    // 0x8010F544: jal         0x8010F280
    // 0x8010F548: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010F280(rdram, ctx);
        goto after_10;
    // 0x8010F548: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8010F54C: beq         $v0, $zero, L_8010F60C
    if (ctx->r2 == 0) {
        // 0x8010F550: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8010F60C;
    }
    // 0x8010F550: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8010F554: sw          $s1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r17;
    // 0x8010F558: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8010F55C: jal         0x800193C4
    // 0x8010F560: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800193C4(rdram, ctx);
        goto after_11;
    // 0x8010F560: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_11:
    // 0x8010F564: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8010F568: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8010F56C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8010F570: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8010F574: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8010F578: nop

    // 0x8010F57C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8010F580: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8010F584: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8010F588: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8010F58C: nop

    // 0x8010F590: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x8010F594: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8010F598: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8010F59C: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x8010F5A0: nop

    // 0x8010F5A4: sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
    // 0x8010F5A8: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8010F5AC: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8010F5B0: div.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8010F5B4: div.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8010F5B8: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x8010F5BC: mul.s       $f18, $f8, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x8010F5C0: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8010F5C4: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x8010F5C8: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x8010F5CC: nop

    // 0x8010F5D0: sw          $t2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r10;
    // 0x8010F5D4: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8010F5D8: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8010F5DC: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8010F5E0: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8010F5E4: nop

    // 0x8010F5E8: sw          $t4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r12;
    // 0x8010F5EC: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8010F5F0: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8010F5F4: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8010F5F8: div.s       $f4, $f28, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f28.fl, ctx->f16.fl);
    // 0x8010F5FC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8010F600: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8010F604: jal         0x800EE830
    // 0x8010F608: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    func_800EE830(rdram, ctx);
        goto after_12;
    // 0x8010F608: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    after_12:
L_8010F60C:
    // 0x8010F60C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8010F610:
    // 0x8010F610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010F614: jal         0x800C878C
    // 0x8010F618: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800C878C(rdram, ctx);
        goto after_13;
    // 0x8010F618: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_13:
    // 0x8010F61C: bne         $v0, $zero, L_8010F478
    if (ctx->r2 != 0) {
        // 0x8010F620: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8010F478;
    }
    // 0x8010F620: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8010F624:
    // 0x8010F624: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010F628: addiu       $v0, $v0, 0x7240
    ctx->r2 = ADD32(ctx->r2, 0X7240);
    // 0x8010F62C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x8010F630: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8010F634: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x8010F638: addiu       $t9, $t8, -0x10
    ctx->r25 = ADD32(ctx->r24, -0X10);
    // 0x8010F63C: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x8010F640: mflo        $t0
    ctx->r8 = lo;
    // 0x8010F644: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8010F648: jal         0x80018DAC
    // 0x8010F64C: nop

    mlMtxPop(rdram, ctx);
        goto after_14;
    // 0x8010F64C: nop

    after_14:
    // 0x8010F650: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8010F654: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010F658: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8010F65C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8010F660: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8010F664: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8010F668: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8010F66C: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8010F670: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8010F674: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8010F678: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8010F67C: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8010F680: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8010F684: jr          $ra
    // 0x8010F688: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x8010F688: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_80802170_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802170: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802178: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080217C: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x80802180: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80802184: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80802188: bnel        $t8, $at, L_8080219C
    if (ctx->r24 != ctx->r1) {
        // 0x8080218C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080219C;
    }
    goto skip_0;
    // 0x8080218C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80802190: jal         0x800904C8
    // 0x80802194: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800904C8(rdram, ctx);
        goto after_0;
    // 0x80802194: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_0:
    // 0x80802198: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8080219C:
    // 0x8080219C: jal         0x80100094
    // 0x808021A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808021A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808021A4: beq         $v0, $zero, L_808021B4
    if (ctx->r2 == 0) {
        // 0x808021A8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808021B4;
    }
    // 0x808021A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808021AC: jal         0x800897C8
    // 0x808021B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x808021B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_808021B4:
    // 0x808021B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808021B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808021BC: jr          $ra
    // 0x808021C0: nop

    return;
    // 0x808021C0: nop

;}
RECOMP_FUNC void _fxkern_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B20: syscall     724
    recomp_syscall_handler(rdram, ctx, 0x80088B20);
    return;
    // 0x80088B24: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800AA180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA180: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800AA184: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AA188: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800AA18C: jr          $ra
    // 0x800AA190: lh          $v0, 0x778C($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X778C);
    return;
    // 0x800AA190: lh          $v0, 0x778C($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X778C);
;}
RECOMP_FUNC void func_800F6D24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6D24: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6D28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6D2C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6D30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6D34: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6D38: jal         0x8008E124
    // 0x800F6D3C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8008E124(rdram, ctx);
        goto after_0;
    // 0x800F6D3C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F6D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6D44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F6D48: jr          $ra
    // 0x800F6D4C: nop

    return;
    // 0x800F6D4C: nop

;}
RECOMP_FUNC void _bsvan_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084168: syscall     105
    recomp_syscall_handler(rdram, ctx, 0x80084168);
    return;
    // 0x8008416C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800000_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800010: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800014: jal         0x8008E40C
    // 0x80800018: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_8008E40C(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080001C: beq         $v0, $zero, L_8080002C
    if (ctx->r2 == 0) {
        // 0x80800020: nop
    
            goto L_8080002C;
    }
    // 0x80800020: nop

    // 0x80800024: b           L_80800060
    // 0x80800028: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_80800060;
    // 0x80800028: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_8080002C:
    // 0x8080002C: jal         0x8008E3E8
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E3E8(rdram, ctx);
        goto after_1;
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800034: beq         $v0, $zero, L_80800044
    if (ctx->r2 == 0) {
        // 0x80800038: nop
    
            goto L_80800044;
    }
    // 0x80800038: nop

    // 0x8080003C: b           L_80800060
    // 0x80800040: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_80800060;
    // 0x80800040: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_80800044:
    // 0x80800044: jal         0x8008E430
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E430(rdram, ctx);
        goto after_2;
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080004C: beql        $v0, $zero, L_80800060
    if (ctx->r2 == 0) {
        // 0x80800050: lw          $v0, 0x1C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X1C);
            goto L_80800060;
    }
    goto skip_0;
    // 0x80800050: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800054: b           L_80800060
    // 0x80800058: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_80800060;
    // 0x80800058: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8080005C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80800060:
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void func_808000D4_chfoodwarn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808000D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000E4: jal         0x800D1A04
    // 0x808000E8: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    func_800D1A04(rdram, ctx);
        goto after_0;
    // 0x808000E8: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_0:
    // 0x808000EC: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x808000F0: bne         $v1, $zero, L_80800108
    if (ctx->r3 != 0) {
        // 0x808000F4: sw          $v1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r3;
            goto L_80800108;
    }
    // 0x808000F4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x808000F8: jal         0x800D1A04
    // 0x808000FC: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    func_800D1A04(rdram, ctx);
        goto after_1;
    // 0x808000FC: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_1:
    // 0x80800100: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800104: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_80800108:
    // 0x80800108: jal         0x8010D254
    // 0x8080010C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8010D254(rdram, ctx);
        goto after_2;
    // 0x8080010C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80800110: jal         0x8010C500
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_3;
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800118: beq         $v0, $zero, L_80800154
    if (ctx->r2 == 0) {
        // 0x8080011C: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_80800154;
    }
    // 0x8080011C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800120: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x8080012C: bnel        $t8, $zero, L_80800158
    if (ctx->r24 != 0) {
        // 0x80800130: lw          $t5, 0x30($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X30);
            goto L_80800158;
    }
    goto skip_0;
    // 0x80800130: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x80800134: jal         0x80800074
    // 0x80800138: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80800074_chfoodwarn(rdram, ctx);
        goto after_4;
    // 0x80800138: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x8080013C: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80800140: sll         $t0, $v0, 4
    ctx->r8 = S32(ctx->r2 << 4);
    // 0x80800144: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x80800148: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x8080014C: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80800150: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_80800154:
    // 0x80800154: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
L_80800158:
    // 0x80800158: beql        $t5, $zero, L_808001CC
    if (ctx->r13 == 0) {
        // 0x8080015C: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_808001CC;
    }
    goto skip_1;
    // 0x8080015C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    skip_1:
    // 0x80800160: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080016C: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800170: bgez        $t8, L_808001C0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800174: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(2084, 0X28C) << 16);
            goto L_808001C0;
    }
    // 0x80800174: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2084, 0X28C) << 16);
    // 0x80800178: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    // 0x8080017C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80800180: andi        $t0, $t9, 0x1FF
    ctx->r8 = ctx->r25 & 0X1FF;
    // 0x80800184: bne         $t0, $zero, L_808001C0
    if (ctx->r8 != 0) {
        // 0x80800188: nop
    
            goto L_808001C0;
    }
    // 0x80800188: nop

    // 0x8080018C: beq         $t2, $zero, L_808001C0
    if (ctx->r10 == 0) {
        // 0x80800190: nop
    
            goto L_808001C0;
    }
    // 0x80800190: nop

    // 0x80800194: lhu         $t1, 0x76($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X76);
    // 0x80800198: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2084, 0X270) << 16);
    // 0x8080019C: addiu       $a2, $a2, 0x270
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2084, 0X270));
    // 0x808001A0: srl         $t3, $t1, 7
    ctx->r11 = S32(U32(ctx->r9) >> 7);
    // 0x808001A4: addiu       $t4, $t3, 0x541
    ctx->r12 = ADD32(ctx->r11, 0X541);
    // 0x808001A8: sh          $t4, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r12;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B0: jal         0x8008A1E8
    // 0x808001B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x808001B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x808001B8: b           L_808001CC
    // 0x808001BC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
        goto L_808001CC;
    // 0x808001BC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_808001C0:
    // 0x808001C0: jal         0x8008A1E8
    // 0x808001C4: addiu       $a2, $a2, 0x28C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2084, 0X28C));
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x808001C4: addiu       $a2, $a2, 0x28C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2084, 0X28C));
    after_6:
    // 0x808001C8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_808001CC:
    // 0x808001CC: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x808001D0: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x808001D4: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x808001D8: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x808001DC: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    // 0x808001E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808001EC: jr          $ra
    // 0x808001F0: nop

    return;
    // 0x808001F0: nop

;}
RECOMP_FUNC void _suexpression_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800897C0: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x800897C0);
    return;
    // 0x800897C4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void vpwibble_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800270: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800274: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800278: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080027C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800280: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800284: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    // 0x80800288: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8080028C: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80800290: jal         0x8001ACCC
    // 0x80800294: addiu       $a0, $t7, 0x38
    ctx->r4 = ADD32(ctx->r15, 0X38);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x80800294: addiu       $a0, $t7, 0x38
    ctx->r4 = ADD32(ctx->r15, 0X38);
    after_0:
    // 0x80800298: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8080029C: addiu       $a0, $s1, 0x14
    ctx->r4 = ADD32(ctx->r17, 0X14);
    // 0x808002A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808002A4: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x808002A8: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x808002AC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x808002B0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x808002B4: addu        $a1, $t0, $s1
    ctx->r5 = ADD32(ctx->r8, ctx->r17);
    // 0x808002B8: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    // 0x808002BC: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x808002C0: beql        $at, $zero, L_8080030C
    if (ctx->r1 == 0) {
        // 0x808002C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080030C;
    }
    goto skip_0;
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808002C8: lhu         $t1, 0x2($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X2);
L_808002CC:
    // 0x808002CC: beql        $t1, $zero, L_808002FC
    if (ctx->r9 == 0) {
        // 0x808002D0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_808002FC;
    }
    goto skip_1;
    // 0x808002D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_1:
    // 0x808002D4: lw          $t4, 0x34($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X34);
    // 0x808002D8: subu        $t2, $v1, $a0
    ctx->r10 = SUB32(ctx->r3, ctx->r4);
    // 0x808002DC: sra         $t3, $t2, 2
    ctx->r11 = S32(SIGNED(ctx->r10) >> 2);
    // 0x808002E0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x808002E4: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x808002E8: sh          $t3, 0x38($t6)
    MEM_H(0X38, ctx->r14) = ctx->r11;
    // 0x808002EC: lw          $t7, 0x34($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X34);
    // 0x808002F0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x808002F4: sw          $t8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r24;
    // 0x808002F8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_808002FC:
    // 0x808002FC: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x80800300: bnel        $at, $zero, L_808002CC
    if (ctx->r1 != 0) {
        // 0x80800304: lhu         $t1, 0x2($v1)
        ctx->r9 = MEM_HU(ctx->r3, 0X2);
            goto L_808002CC;
    }
    goto skip_2;
    // 0x80800304: lhu         $t1, 0x2($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X2);
    skip_2:
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080030C:
    // 0x8080030C: jal         0x800EE88C
    // 0x80800310: addiu       $a1, $s1, 0x8
    ctx->r5 = ADD32(ctx->r17, 0X8);
    func_800EE88C(rdram, ctx);
        goto after_1;
    // 0x80800310: addiu       $a1, $s1, 0x8
    ctx->r5 = ADD32(ctx->r17, 0X8);
    after_1:
    // 0x80800314: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x80800318: jal         0x800EE88C
    // 0x8080031C: addiu       $a1, $s1, 0xE
    ctx->r5 = ADD32(ctx->r17, 0XE);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x8080031C: addiu       $a1, $s1, 0xE
    ctx->r5 = ADD32(ctx->r17, 0XE);
    after_2:
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800324: jal         0x808000B0
    // 0x80800328: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_808000B0_vpwibble(rdram, ctx);
        goto after_3;
    // 0x80800328: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x8080032C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800330: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800334: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800338: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080033C: jr          $ra
    // 0x80800340: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800340: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _choildrill_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087708: syscall     611
    recomp_syscall_handler(rdram, ctx, 0x80087708);
    return;
    // 0x8008770C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080037C_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080037C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800384: jal         0x80800000
    // 0x80800388: nop

    func_80800000_bsbansnooze(rdram, ctx);
        goto after_0;
    // 0x80800388: nop

    after_0:
    // 0x8080038C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800390: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800394: jr          $ra
    // 0x80800398: nop

    return;
    // 0x80800398: nop

;}
RECOMP_FUNC void susubgame_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080050C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800510: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800514: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80800518: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8080051C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800520: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800524: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800528: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x8080052C: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80800530: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800534: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800538: bne         $s3, $zero, L_80800544
    if (ctx->r19 != 0) {
        // 0x8080053C: sw          $s1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r17;
            goto L_80800544;
    }
    // 0x8080053C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800540: lw          $s3, 0x0($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X0);
L_80800544:
    // 0x80800544: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80800548: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080054C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800550: beq         $v0, $zero, L_80800578
    if (ctx->r2 == 0) {
        // 0x80800554: nop
    
            goto L_80800578;
    }
    // 0x80800554: nop

    // 0x80800558: beq         $v0, $at, L_80800580
    if (ctx->r2 == ctx->r1) {
        // 0x8080055C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800580;
    }
    // 0x8080055C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800560: beq         $v0, $at, L_80800580
    if (ctx->r2 == ctx->r1) {
        // 0x80800564: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800580;
    }
    // 0x80800564: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800568: beql        $v0, $at, L_8080058C
    if (ctx->r2 == ctx->r1) {
        // 0x8080056C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8080058C;
    }
    goto skip_0;
    // 0x8080056C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_0:
    // 0x80800570: b           L_808005CC
    // 0x80800574: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808005CC;
    // 0x80800574: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800578:
    // 0x80800578: jal         0x80800814
    // 0x8080057C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_80800814_susubgame(rdram, ctx);
        goto after_0;
    // 0x8080057C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_0:
L_80800580:
    // 0x80800580: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800584: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80800588: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8080058C:
    // 0x8080058C: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
L_80800590:
    // 0x80800590: jal         0x808008DC
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008DC_susubgame(rdram, ctx);
        goto after_1;
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800598: beq         $v0, $zero, L_808005BC
    if (ctx->r2 == 0) {
        // 0x8080059C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005BC;
    }
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A0: jal         0x800A93E4
    // 0x808005A4: ori         $s1, $s4, 0x800
    ctx->r17 = ctx->r20 | 0X800;
    func_800A93E4(rdram, ctx);
        goto after_2;
    // 0x808005A4: ori         $s1, $s4, 0x800
    ctx->r17 = ctx->r20 | 0X800;
    after_2:
    // 0x808005A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005AC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808005B0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x808005B4: jal         0x800895C0
    // 0x808005B8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    _ncpod_entrypoint_32(rdram, ctx);
        goto after_3;
    // 0x808005B8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_3:
L_808005BC:
    // 0x808005BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808005C0: bne         $s0, $s2, L_80800590
    if (ctx->r16 != ctx->r18) {
        // 0x808005C4: nop
    
            goto L_80800590;
    }
    // 0x808005C4: nop

    // 0x808005C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808005CC:
    // 0x808005CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808005D0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808005D4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808005D8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808005DC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x808005E0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808005E4: jr          $ra
    // 0x808005E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808005E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _bsfirstp_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084340: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084340);
    return;
    // 0x80084344: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void func_808005A0_chanemone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808005B0: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x808005B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005BC: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x808005C0: bnel        $t7, $at, L_80800638
    if (ctx->r15 != ctx->r1) {
        // 0x808005C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800638;
    }
    goto skip_0;
    // 0x808005C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808005C8: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808005CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D4: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x808005D8: beq         $t8, $at, L_808005F0
    if (ctx->r24 == ctx->r1) {
        // 0x808005DC: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_808005F0;
    }
    // 0x808005DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808005E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808005E4: beq         $t8, $at, L_80800624
    if (ctx->r24 == ctx->r1) {
        // 0x808005E8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800624;
    }
    // 0x808005E8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808005EC: bne         $t8, $at, L_80800634
    if (ctx->r24 != ctx->r1) {
        // 0x808005F0: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1032, 0X954) << 16);
            goto L_80800634;
    }
L_808005F0:
    // 0x808005F0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1032, 0X954) << 16);
    // 0x808005F4: jal         0x80089D18
    // 0x808005F8: addiu       $a2, $a2, 0x954
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1032, 0X954));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808005F8: addiu       $a2, $a2, 0x954
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1032, 0X954));
    after_0:
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800600: jal         0x80102424
    // 0x80800604: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800604: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080060C: jal         0x8008A4B0
    // 0x80800610: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800610: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800614: jal         0x8010A570
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080061C: b           L_80800638
    // 0x80800620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800638;
    // 0x80800620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800624:
    // 0x80800624: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800628: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080062C: nop

    // 0x80800630: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800634:
    // 0x80800634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800638:
    // 0x80800638: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080063C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800640: jr          $ra
    // 0x80800644: nop

    return;
    // 0x80800644: nop

;}
RECOMP_FUNC void func_808001D8_bsmummove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001E0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808001E4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808001E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808001F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001F4: jal         0x8009D2F0
    // 0x808001F8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_0;
    // 0x808001F8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x808001FC: lui         $a1, 0x3EF0
    ctx->r5 = S32(0X3EF0 << 16);
    // 0x80800200: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: jal         0x800A2CE8
    // 0x8080020C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_1;
    // 0x8080020C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80800210: lui         $a1, 0x3F78
    ctx->r5 = S32(0X3F78 << 16);
    // 0x80800214: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x800A2CE8
    // 0x80800220: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_2;
    // 0x80800220: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80800224: jal         0x80083860
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsmum_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080022C: jal         0x8009EF10
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_4;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800234: beq         $v0, $zero, L_8080024C
    if (ctx->r2 == 0) {
        // 0x80800238: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8080024C;
    }
    // 0x80800238: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080023C: beq         $v0, $at, L_80800268
    if (ctx->r2 == ctx->r1) {
        // 0x80800240: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800268;
    }
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: b           L_8080027C
    // 0x80800248: nop

        goto L_8080027C;
    // 0x80800248: nop

L_8080024C:
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800250: jal         0x8009BCD4
    // 0x80800254: lui         $a1, 0x4190
    ctx->r5 = S32(0X4190 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_5;
    // 0x80800254: lui         $a1, 0x4190
    ctx->r5 = S32(0X4190 << 16);
    after_5:
    // 0x80800258: beq         $v0, $zero, L_8080027C
    if (ctx->r2 == 0) {
        // 0x8080025C: nop
    
            goto L_8080027C;
    }
    // 0x8080025C: nop

    // 0x80800260: b           L_8080027C
    // 0x80800264: addiu       $s1, $zero, 0xE5
    ctx->r17 = ADD32(0, 0XE5);
        goto L_8080027C;
    // 0x80800264: addiu       $s1, $zero, 0xE5
    ctx->r17 = ADD32(0, 0XE5);
L_80800268:
    // 0x80800268: jal         0x8009BCD4
    // 0x8080026C: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_6;
    // 0x8080026C: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    after_6:
    // 0x80800270: beq         $v0, $zero, L_8080027C
    if (ctx->r2 == 0) {
        // 0x80800274: nop
    
            goto L_8080027C;
    }
    // 0x80800274: nop

    // 0x80800278: addiu       $s1, $zero, 0xE6
    ctx->r17 = ADD32(0, 0XE6);
L_8080027C:
    // 0x8080027C: jal         0x8008DD04
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_7;
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800284: beq         $v0, $zero, L_80800290
    if (ctx->r2 == 0) {
        // 0x80800288: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800290;
    }
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: addiu       $s1, $zero, 0xE9
    ctx->r17 = ADD32(0, 0XE9);
L_80800290:
    // 0x80800290: jal         0x80091A58
    // 0x80800294: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_8;
    // 0x80800294: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_8:
    // 0x80800298: beq         $v0, $zero, L_808002A4
    if (ctx->r2 == 0) {
        // 0x8080029C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A4;
    }
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A0: addiu       $s1, $zero, 0xF7
    ctx->r17 = ADD32(0, 0XF7);
L_808002A4:
    // 0x808002A4: jal         0x80091A58
    // 0x808002A8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_9;
    // 0x808002A8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_9:
    // 0x808002AC: beq         $v0, $zero, L_808002B8
    if (ctx->r2 == 0) {
        // 0x808002B0: nop
    
            goto L_808002B8;
    }
    // 0x808002B0: nop

    // 0x808002B4: addiu       $s1, $zero, 0xE8
    ctx->r17 = ADD32(0, 0XE8);
L_808002B8:
    // 0x808002B8: jal         0x8008E148
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_10;
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808002C0: beq         $v0, $zero, L_808002D4
    if (ctx->r2 == 0) {
        // 0x808002C4: nop
    
            goto L_808002D4;
    }
    // 0x808002C4: nop

    // 0x808002C8: jal         0x800848B0
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_11;
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808002D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_808002D4:
    // 0x808002D4: jal         0x8008E35C
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_12;
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808002DC: beq         $v0, $zero, L_808002E8
    if (ctx->r2 == 0) {
        // 0x808002E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002E8;
    }
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E4: addiu       $s1, $zero, 0xF0
    ctx->r17 = ADD32(0, 0XF0);
L_808002E8:
    // 0x808002E8: jal         0x8009E5C8
    // 0x808002EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_13;
    // 0x808002EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_13:
    // 0x808002F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808002F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808002FC: jr          $ra
    // 0x80800300: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800300: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void chcauldronenergybars_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2024, 0X2D4) << 16);
    // 0x808002A8: jr          $ra
    // 0x808002AC: addiu       $v0, $v0, 0x2D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2024, 0X2D4));
    return;
    // 0x808002AC: addiu       $v0, $v0, 0x2D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2024, 0X2D4));
;}
RECOMP_FUNC void func_808004FC_chnicecavemenguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800500: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800504: jal         0x801015D0
    // 0x80800508: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_801015D0(rdram, ctx);
        goto after_0;
    // 0x80800508: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080050C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800510: jal         0x800DF744
    // 0x80800514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80800514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800518: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8080051C: jal         0x800DF744
    // 0x80800520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80800520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800524: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800528: jal         0x800DF744
    // 0x8080052C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x8080052C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800530: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800534: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800538: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x8080053C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800540: beq         $t6, $at, L_8080056C
    if (ctx->r14 == ctx->r1) {
        // 0x80800544: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8080056C;
    }
    // 0x80800544: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800548: bne         $t6, $at, L_808005AC
    if (ctx->r14 != ctx->r1) {
        // 0x8080054C: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_808005AC;
    }
    // 0x8080054C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800550: jal         0x800DF744
    // 0x80800554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x80800554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800558: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8080055C: jal         0x800DF744
    // 0x80800560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_5;
    // 0x80800560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800564: b           L_808005C8
    // 0x80800568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808005C8;
    // 0x80800568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080056C:
    // 0x8080056C: jal         0x80101F24
    // 0x80800570: nop

    func_80101F24(rdram, ctx);
        goto after_6;
    // 0x80800570: nop

    after_6:
    // 0x80800574: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1272, 0X8A8) << 16);
    // 0x80800578: lwc1        $f4, 0x8A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1272, 0X8A8));
    // 0x8080057C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800580: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800584: nop

    // 0x80800588: bc1fl       L_808005B0
    if (!c1cs) {
        // 0x8080058C: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_808005B0;
    }
    goto skip_0;
    // 0x8080058C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    skip_0:
    // 0x80800590: jal         0x800DF744
    // 0x80800594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_7;
    // 0x80800594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800598: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8080059C: jal         0x800DF744
    // 0x808005A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_8;
    // 0x808005A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808005A4: b           L_808005C8
    // 0x808005A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808005C8;
    // 0x808005A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005AC:
    // 0x808005AC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_808005B0:
    // 0x808005B0: jal         0x800DF744
    // 0x808005B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_9;
    // 0x808005B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808005B8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x808005BC: jal         0x800DF744
    // 0x808005C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_10;
    // 0x808005C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x808005C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005C8:
    // 0x808005C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005CC: jr          $ra
    // 0x808005D0: nop

    return;
    // 0x808005D0: nop

;}
RECOMP_FUNC void func_8080187C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080187C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801880: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801884: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801888: jal         0x800A5090
    // 0x8080188C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A5090(rdram, ctx);
        goto after_0;
    // 0x8080188C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801890: bnel        $v0, $zero, L_808018D0
    if (ctx->r2 != 0) {
        // 0x80801894: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808018D0;
    }
    goto skip_0;
    // 0x80801894: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801898: jal         0x800A5004
    // 0x8080189C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A5004(rdram, ctx);
        goto after_1;
    // 0x8080189C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808018A0: jal         0x800A5090
    // 0x808018A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A5090(rdram, ctx);
        goto after_2;
    // 0x808018A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808018A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808018AC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808018B0: jal         0x800CA6C0
    // 0x808018B4: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    func_800CA6C0(rdram, ctx);
        goto after_3;
    // 0x808018B4: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    after_3:
    // 0x808018B8: jal         0x80801640
    // 0x808018BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801640_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x808018BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808018C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808018C4: jal         0x80801668
    // 0x808018C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801668_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x808018C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808018CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808018D0:
    // 0x808018D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808018D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808018D8: jr          $ra
    // 0x808018DC: nop

    return;
    // 0x808018DC: nop

;}
RECOMP_FUNC void func_80801320_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801320: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80801324: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80801328: jr          $ra
    // 0x8080132C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x8080132C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void func_80800268_chweldarbossfusebox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080026C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800274: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800278: beq         $a1, $at, L_80800294
    if (ctx->r5 == ctx->r1) {
        // 0x8080027C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800294;
    }
    // 0x8080027C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800280: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800284: beq         $a1, $at, L_80800300
    if (ctx->r5 == ctx->r1) {
        // 0x80800288: nop
    
            goto L_80800300;
    }
    // 0x80800288: nop

    // 0x8080028C: b           L_8080031C
    // 0x80800290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080031C;
    // 0x80800290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800294:
    // 0x80800294: lw          $t6, 0x6C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X6C);
    // 0x80800298: lhu         $t9, 0x6E($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X6E);
    // 0x8080029C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002A0: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x808002A4: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x808002A8: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x808002AC: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x808002B0: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x808002B4: bne         $t7, $at, L_80800318
    if (ctx->r15 != ctx->r1) {
        // 0x808002B8: sh          $t1, 0x6E($a3)
        MEM_H(0X6E, ctx->r7) = ctx->r9;
            goto L_80800318;
    }
    // 0x808002B8: sh          $t1, 0x6E($a3)
    MEM_H(0X6E, ctx->r7) = ctx->r9;
    // 0x808002BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808002C0: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x808002C4: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x808002C8: jal         0x80086670
    // 0x808002CC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808002CC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x808002D0: addiu       $a0, $zero, 0x465
    ctx->r4 = ADD32(0, 0X465);
    // 0x808002D4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808002D8: jal         0x80101180
    // 0x808002DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_1;
    // 0x808002DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808002E0: addiu       $a0, $zero, 0x3B3
    ctx->r4 = ADD32(0, 0X3B3);
    // 0x808002E4: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    // 0x808002E8: jal         0x80101180
    // 0x808002EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_2;
    // 0x808002EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808002F0: jal         0x80800384
    // 0x808002F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800384_chweldarbossfusebox(rdram, ctx);
        goto after_3;
    // 0x808002F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808002F8: b           L_8080031C
    // 0x808002FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080031C;
    // 0x808002FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800300:
    // 0x80800300: jal         0x8080032C
    // 0x80800304: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8080032C_chweldarbossfusebox(rdram, ctx);
        goto after_4;
    // 0x80800304: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x80800308: b           L_8080031C
    // 0x8080030C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080031C;
    // 0x8080030C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800310: b           L_8080031C
    // 0x80800314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080031C;
    // 0x80800314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800318:
    // 0x80800318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080031C:
    // 0x8080031C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800324: jr          $ra
    // 0x80800328: nop

    return;
    // 0x80800328: nop

;}
RECOMP_FUNC void _bawobble_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085448: syscall     162
    recomp_syscall_handler(rdram, ctx, 0x80085448);
    return;
    // 0x8008544C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chegggolden_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087208: syscall     536
    recomp_syscall_handler(rdram, ctx, 0x80087208);
    return;
    // 0x8008720C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chpowerhutwitchy_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086088: syscall     275
    recomp_syscall_handler(rdram, ctx, 0x80086088);
    return;
    // 0x8008608C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void basub_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800574: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
    // 0x80800578: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080057C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800580: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800584: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800588: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080058C: nop

    // 0x80800590: bc1t        L_808005B0
    if (c1cs) {
        // 0x80800594: nop
    
            goto L_808005B0;
    }
    // 0x80800594: nop

    // 0x80800598: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x8080059C: lw          $t6, 0x130($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X130);
    // 0x808005A0: swc1        $f14, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f14.u32l;
    // 0x808005A4: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
    // 0x808005A8: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808005AC: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
L_808005B0:
    // 0x808005B0: jr          $ra
    // 0x808005B4: nop

    return;
    // 0x808005B4: nop

;}
RECOMP_FUNC void _bafpctrl_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084CA0: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084CA0);
    return;
    // 0x80084CA4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
