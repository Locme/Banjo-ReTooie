#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bsstonehead_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004B0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x808004B4: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x808004B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808004BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004C0: beq         $v0, $at, L_808004E4
    if (ctx->r2 == ctx->r1) {
        // 0x808004C4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808004E4;
    }
    // 0x808004C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004C8: beq         $v0, $at, L_80800504
    if (ctx->r2 == ctx->r1) {
        // 0x808004CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800504;
    }
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808004D4: beq         $v0, $at, L_8080056C
    if (ctx->r2 == ctx->r1) {
        // 0x808004D8: addiu       $a0, $s0, 0x16C
        ctx->r4 = ADD32(ctx->r16, 0X16C);
            goto L_8080056C;
    }
    // 0x808004D8: addiu       $a0, $s0, 0x16C
    ctx->r4 = ADD32(ctx->r16, 0X16C);
    // 0x808004DC: b           L_808005C0
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808005C0;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004E4:
    // 0x808004E4: jal         0x8008CAEC
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_0;
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808004EC: beq         $v0, $zero, L_808005BC
    if (ctx->r2 == 0) {
        // 0x808004F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005BC;
    }
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F4: jal         0x80800194
    // 0x808004F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800194_bsstonehead(rdram, ctx);
        goto after_1;
    // 0x808004F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808004FC: b           L_808005C0
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808005C0;
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800504:
    // 0x80800504: jal         0x800852F0
    // 0x80800508: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_2;
    // 0x80800508: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080050C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800510: jal         0x80085330
    // 0x80800514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_isZero(rdram, ctx);
        goto after_3;
    // 0x80800514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800518: beq         $v0, $zero, L_808005BC
    if (ctx->r2 == 0) {
        // 0x8080051C: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_808005BC;
    }
    // 0x8080051C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800520: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800524: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080052C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800530: swc1        $f8, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f8.u32l;
    // 0x80800534: jal         0x8009B9B0
    // 0x80800538: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800538: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_4:
    // 0x8080053C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800540: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800544: lwc1        $f10, 0x16C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080054C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800550: nop

    // 0x80800554: bc1fl       L_808005C0
    if (!c1cs) {
        // 0x80800558: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005C0;
    }
    goto skip_0;
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080055C: jal         0x80800194
    // 0x80800560: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800194_bsstonehead(rdram, ctx);
        goto after_5;
    // 0x80800560: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80800564: b           L_808005C0
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808005C0;
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080056C:
    // 0x8080056C: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800570: jal         0x800F1574
    // 0x80800574: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_800F1574(rdram, ctx);
        goto after_6;
    // 0x80800574: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_6:
    // 0x80800578: jal         0x8008CAEC
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_7;
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800580: beq         $v0, $zero, L_8080058C
    if (ctx->r2 == 0) {
        // 0x80800584: addiu       $t6, $zero, 0xB3
        ctx->r14 = ADD32(0, 0XB3);
            goto L_8080058C;
    }
    // 0x80800584: addiu       $t6, $zero, 0xB3
    ctx->r14 = ADD32(0, 0XB3);
    // 0x80800588: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8080058C:
    // 0x8080058C: jal         0x8008CAC8
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_8;
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800594: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(376, 0X1610) << 16);
    // 0x80800598: lwc1        $f18, 0x1610($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(376, 0X1610));
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A0: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x808005A4: nop

    // 0x808005A8: bc1fl       L_808005C0
    if (!c1cs) {
        // 0x808005AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005C0;
    }
    goto skip_1;
    // 0x808005AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808005B0: jal         0x808003F4
    // 0x808005B4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808003F4_bsstonehead(rdram, ctx);
        goto after_9;
    // 0x808005B4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x808005B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_808005BC:
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808005C0:
    // 0x808005C0: jal         0x8009E5C8
    // 0x808005C4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_10;
    // 0x808005C4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x808005C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005D4: jr          $ra
    // 0x808005D8: nop

    return;
    // 0x808005D8: nop

;}
RECOMP_FUNC void gcdialogexec_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801998: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080199C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808019A0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808019A4: lhu         $t6, 0x160($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X160);
    // 0x808019A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808019AC: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x808019B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808019B4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x808019B8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808019BC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x808019C0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808019C4: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x808019C8: lw          $t9, 0x1A0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X1A0);
    // 0x808019CC: lw          $a3, 0x194($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X194);
    // 0x808019D0: lhu         $a2, 0x186($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0X186);
    // 0x808019D4: lh          $a1, 0x184($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X184);
    // 0x808019D8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808019DC: lw          $t0, 0x1A4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X1A4);
    // 0x808019E0: addiu       $v1, $v1, 0x184
    ctx->r3 = ADD32(ctx->r3, 0X184);
    // 0x808019E4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808019E8: lw          $t1, 0x24($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X24);
    // 0x808019EC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x808019F0: lh          $t2, 0x14($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X14);
    // 0x808019F4: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x808019F8: jal         0x80801268
    // 0x808019FC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    func_80801268_gcdialogexec(rdram, ctx);
        goto after_0;
    // 0x808019FC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    after_0:
    // 0x80801A00: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80801A04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801A08: lw          $t3, 0x18($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X18);
    // 0x80801A0C: sw          $t3, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->r11;
    // 0x80801A10: lw          $t4, 0x28($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X28);
    // 0x80801A14: jal         0x800FEC60
    // 0x80801A18: sw          $t4, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = ctx->r12;
    func_800FEC60(rdram, ctx);
        goto after_1;
    // 0x80801A18: sw          $t4, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = ctx->r12;
    after_1:
    // 0x80801A1C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80801A20: lhu         $t5, 0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X2);
    // 0x80801A24: andi        $t6, $t5, 0x8
    ctx->r14 = ctx->r13 & 0X8;
    // 0x80801A28: beql        $t6, $zero, L_80801AF8
    if (ctx->r14 == 0) {
        // 0x80801A2C: lhu         $t3, 0x160($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X160);
            goto L_80801AF8;
    }
    goto skip_0;
    // 0x80801A2C: lhu         $t3, 0x160($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X160);
    skip_0:
    // 0x80801A30: jal         0x800A9C98
    // 0x80801A34: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_800A9C98(rdram, ctx);
        goto after_2;
    // 0x80801A34: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80801A38: beq         $v0, $zero, L_80801A50
    if (ctx->r2 == 0) {
        // 0x80801A3C: lw          $v1, 0x3C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X3C);
            goto L_80801A50;
    }
    // 0x80801A3C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80801A40: lw          $t7, 0x15C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X15C);
    // 0x80801A44: sll         $t9, $t7, 20
    ctx->r25 = S32(ctx->r15 << 20);
    // 0x80801A48: bltzl       $t9, L_80801AF8
    if (SIGNED(ctx->r25) < 0) {
        // 0x80801A4C: lhu         $t3, 0x160($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X160);
            goto L_80801AF8;
    }
    goto skip_1;
    // 0x80801A4C: lhu         $t3, 0x160($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X160);
    skip_1:
L_80801A50:
    // 0x80801A50: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    // 0x80801A54: jal         0x800F6438
    // 0x80801A58: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_800F6438(rdram, ctx);
        goto after_3;
    // 0x80801A58: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_3:
    // 0x80801A5C: beq         $v0, $zero, L_80801A78
    if (ctx->r2 == 0) {
        // 0x80801A60: lw          $v1, 0x3C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X3C);
            goto L_80801A78;
    }
    // 0x80801A60: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80801A64: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    // 0x80801A68: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80801A6C: jal         0x800F82D4
    // 0x80801A70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_4;
    // 0x80801A70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80801A74: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
L_80801A78:
    // 0x80801A78: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    // 0x80801A7C: jal         0x800EEEA8
    // 0x80801A80: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    func_800EEEA8(rdram, ctx);
        goto after_5;
    // 0x80801A80: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_5:
    // 0x80801A84: beq         $v0, $zero, L_80801AC4
    if (ctx->r2 == 0) {
        // 0x80801A88: nop
    
            goto L_80801AC4;
    }
    // 0x80801A88: nop

    // 0x80801A8C: jal         0x800F6438
    // 0x80801A90: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    func_800F6438(rdram, ctx);
        goto after_6;
    // 0x80801A90: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    after_6:
    // 0x80801A94: beql        $v0, $zero, L_80801AF8
    if (ctx->r2 == 0) {
        // 0x80801A98: lhu         $t3, 0x160($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X160);
            goto L_80801AF8;
    }
    goto skip_2;
    // 0x80801A98: lhu         $t3, 0x160($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X160);
    skip_2:
    // 0x80801A9C: lh          $t0, 0x11A($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X11A);
    // 0x80801AA0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801AA4: bgez        $t0, L_80801AB4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80801AA8: nop
    
            goto L_80801AB4;
    }
    // 0x80801AA8: nop

    // 0x80801AAC: b           L_80801AB4
    // 0x80801AB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80801AB4;
    // 0x80801AB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80801AB4:
    // 0x80801AB4: jal         0x800F82D4
    // 0x80801AB8: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    func_800F82D4(rdram, ctx);
        goto after_7;
    // 0x80801AB8: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    after_7:
    // 0x80801ABC: b           L_80801AF8
    // 0x80801AC0: lhu         $t3, 0x160($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X160);
        goto L_80801AF8;
    // 0x80801AC0: lhu         $t3, 0x160($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X160);
L_80801AC4:
    // 0x80801AC4: jal         0x800F6438
    // 0x80801AC8: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    func_800F6438(rdram, ctx);
        goto after_8;
    // 0x80801AC8: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    after_8:
    // 0x80801ACC: beq         $v0, $zero, L_80801AF4
    if (ctx->r2 == 0) {
        // 0x80801AD0: lw          $a2, 0x34($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X34);
            goto L_80801AF4;
    }
    // 0x80801AD0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80801AD4: lh          $t1, 0x11A($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X11A);
    // 0x80801AD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801ADC: bgez        $t1, L_80801AEC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80801AE0: nop
    
            goto L_80801AEC;
    }
    // 0x80801AE0: nop

    // 0x80801AE4: b           L_80801AEC
    // 0x80801AE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80801AEC;
    // 0x80801AE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80801AEC:
    // 0x80801AEC: jal         0x800F8300
    // 0x80801AF0: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    func_800F8300(rdram, ctx);
        goto after_9;
    // 0x80801AF0: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    after_9:
L_80801AF4:
    // 0x80801AF4: lhu         $t3, 0x160($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X160);
L_80801AF8:
    // 0x80801AF8: lbu         $t6, 0x161($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X161);
    // 0x80801AFC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80801B00: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x80801B04: andi        $t7, $t6, 0xFFF0
    ctx->r15 = ctx->r14 & 0XFFF0;
    // 0x80801B08: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80801B0C: sb          $t8, 0x161($s0)
    MEM_B(0X161, ctx->r16) = ctx->r24;
    // 0x80801B10: lhu         $v0, 0x160($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X160);
    // 0x80801B14: andi        $t4, $t8, 0xF0
    ctx->r12 = ctx->r24 & 0XF0;
    // 0x80801B18: andi        $t9, $v0, 0xF
    ctx->r25 = ctx->r2 & 0XF;
    // 0x80801B1C: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80801B20: bne         $at, $zero, L_80801B34
    if (ctx->r1 != 0) {
        // 0x80801B24: addiu       $t1, $t9, -0x4
        ctx->r9 = ADD32(ctx->r25, -0X4);
            goto L_80801B34;
    }
    // 0x80801B24: addiu       $t1, $t9, -0x4
    ctx->r9 = ADD32(ctx->r25, -0X4);
    // 0x80801B28: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x80801B2C: or          $t6, $t2, $t4
    ctx->r14 = ctx->r10 | ctx->r12;
    // 0x80801B30: sb          $t6, 0x161($s0)
    MEM_B(0X161, ctx->r16) = ctx->r14;
L_80801B34:
    // 0x80801B34: lbu         $v0, 0x161($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X161);
    // 0x80801B38: srl         $t5, $v0, 4
    ctx->r13 = S32(U32(ctx->r2) >> 4);
    // 0x80801B3C: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x80801B40: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x80801B44: andi        $t0, $v0, 0xFF0F
    ctx->r8 = ctx->r2 & 0XFF0F;
    // 0x80801B48: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x80801B4C: sb          $t1, 0x161($s0)
    MEM_B(0X161, ctx->r16) = ctx->r9;
    // 0x80801B50: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801B54: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80801B58: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801B5C: jr          $ra
    // 0x80801B60: nop

    return;
    // 0x80801B60: nop

;}
RECOMP_FUNC void func_80800228_glsplinecs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080022C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800230: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800234: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800238: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8080023C: jal         0x80105494
    // 0x80800240: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x80800240: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800244: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800248: lbu         $t0, 0x44($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X44);
    // 0x8080024C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800250: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80800254: andi        $t9, $t8, 0x60
    ctx->r25 = ctx->r24 & 0X60;
    // 0x80800258: andi        $t1, $t0, 0xFF9F
    ctx->r9 = ctx->r8 & 0XFF9F;
    // 0x8080025C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800260: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800264: sb          $t2, 0x44($v0)
    MEM_B(0X44, ctx->r2) = ctx->r10;
    // 0x80800268: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8080026C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80800270: ori         $at, $at, 0x6
    ctx->r1 = ctx->r1 | 0X6;
    // 0x80800274: bnel        $v1, $at, L_808002B4
    if (ctx->r3 != ctx->r1) {
        // 0x80800278: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_808002B4;
    }
    goto skip_0;
    // 0x80800278: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    skip_0:
    // 0x8080027C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80800280: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2698, 0X15E0) << 16);
    // 0x80800284: andi        $t5, $t2, 0x7F
    ctx->r13 = ctx->r10 & 0X7F;
    // 0x80800288: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x8080028C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80800290: lwc1        $f10, 0x15E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2698, 0X15E0));
    // 0x80800294: sb          $t5, 0x44($v0)
    MEM_B(0X44, ctx->r2) = ctx->r13;
    // 0x80800298: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8080029C: nop

    // 0x808002A0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808002A4: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808002A8: b           L_80800300
    // 0x808002AC: swc1        $f16, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f16.u32l;
        goto L_80800300;
    // 0x808002AC: swc1        $f16, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f16.u32l;
    // 0x808002B0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
L_808002B4:
    // 0x808002B4: ori         $at, $at, 0x5
    ctx->r1 = ctx->r1 | 0X5;
    // 0x808002B8: bnel        $v1, $at, L_80800304
    if (ctx->r3 != ctx->r1) {
        // 0x808002BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800304;
    }
    goto skip_1;
    // 0x808002BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808002C0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x808002C4: lwc1        $f18, 0x190($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X190);
    // 0x808002C8: lbu         $t3, 0x44($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X44);
    // 0x808002CC: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x808002D0: srl         $t8, $t7, 19
    ctx->r24 = S32(U32(ctx->r15) >> 19);
    // 0x808002D4: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x808002D8: addu        $t9, $a0, $t0
    ctx->r25 = ADD32(ctx->r4, ctx->r8);
    // 0x808002DC: swc1        $f18, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f18.u32l;
    // 0x808002E0: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x808002E4: lwc1        $f8, 0x190($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X190);
    // 0x808002E8: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x808002EC: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x808002F0: sb          $t4, 0x44($v0)
    MEM_B(0X44, ctx->r2) = ctx->r12;
    // 0x808002F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808002F8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808002FC: swc1        $f10, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f10.u32l;
L_80800300:
    // 0x80800300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800304:
    // 0x80800304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800308: jr          $ra
    // 0x8080030C: nop

    return;
    // 0x8080030C: nop

;}
RECOMP_FUNC void func_80800224_fxkern(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800224: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800228: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8080022C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800230: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800234: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80800238: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8080023C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800240: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800244: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80800248: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080024C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800250: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80800254: jal         0x800B8C98
    // 0x80800258: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B8C98(rdram, ctx);
        goto after_0;
    // 0x80800258: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8080025C: jal         0x800B7F14
    // 0x80800260: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800B7F14(rdram, ctx);
        goto after_1;
    // 0x80800260: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x80800264: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x80800268: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2854, 0X488) << 16);
    // 0x8080026C: addiu       $t7, $t7, 0x488
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2854, 0X488));
    // 0x80800270: bltz        $v0, L_808002E0
    if (SIGNED(ctx->r2) < 0) {
        // 0x80800274: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_808002E0;
    }
    // 0x80800274: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80800278: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8080027C: mtc1        $s2, $f18
    ctx->f18.u32l = ctx->r18;
    // 0x80800280: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80800284: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80800288: cvt.s.w     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8080028C: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2854, 0X488) << 16);
    // 0x80800290: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80800294: addu        $s1, $t9, $v0
    ctx->r17 = ADD32(ctx->r25, ctx->r2);
    // 0x80800298: addiu       $s2, $s2, 0x488
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2854, 0X488));
    // 0x8080029C: cvt.s.w     $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    ctx->f22.fl = CVT_S_W(ctx->f16.u32l);
L_808002A0:
    // 0x808002A0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808002A4: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808002A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808002AC: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x808002B0: lbu         $a3, 0x0($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X0);
    // 0x808002B4: add.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x808002B8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808002BC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808002C0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x808002C4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808002C8: jal         0x800B8DEC
    // 0x808002CC: nop

    func_800B8DEC(rdram, ctx);
        goto after_2;
    // 0x808002CC: nop

    after_2:
    // 0x808002D0: addiu       $s0, $s0, -0x8
    ctx->r16 = ADD32(ctx->r16, -0X8);
    // 0x808002D4: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x808002D8: beq         $at, $zero, L_808002A0
    if (ctx->r1 == 0) {
        // 0x808002DC: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_808002A0;
    }
    // 0x808002DC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_808002E0:
    // 0x808002E0: jal         0x800B811C
    // 0x808002E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800B811C(rdram, ctx);
        goto after_3;
    // 0x808002E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x808002E8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808002EC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808002F0: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x808002F4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x808002F8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x808002FC: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800300: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80800304: jr          $ra
    // 0x80800308: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800308: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _chintrotext_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086198: syscall     285
    recomp_syscall_handler(rdram, ctx, 0x80086198);
    return;
    // 0x8008619C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80111198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111198: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8011119C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801111A0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801111A4: jal         0x800136E4
    // 0x801111A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x801111A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801111AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801111B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801111B4: jal         0x80115DEC
    // 0x801111B8: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    func_80115DEC(rdram, ctx);
        goto after_1;
    // 0x801111B8: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    after_1:
    // 0x801111BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801111C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801111C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801111C8: jr          $ra
    // 0x801111CC: nop

    return;
    // 0x801111CC: nop

;}
RECOMP_FUNC void func_808036D8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808036D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808036DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808036E0: jal         0x80088520
    // 0x808036E4: nop

    _glsavegame_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808036E4: nop

    after_0:
    // 0x808036E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808036EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808036F0: jr          $ra
    // 0x808036F4: nop

    return;
    // 0x808036F4: nop

;}
RECOMP_FUNC void bsbswim_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801414: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801418: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(120, 0X1EE0) << 16);
    // 0x8080141C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801420: jr          $ra
    // 0x80801424: lw          $v0, 0x1EE0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1EE0));
    return;
    // 0x80801424: lw          $v0, 0x1EE0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1EE0));
;}
RECOMP_FUNC void func_80800214_chdiggerground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800214: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800218: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8080021C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80800220: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800224: addiu       $s5, $sp, 0x6C
    ctx->r21 = ADD32(ctx->r29, 0X6C);
    // 0x80800228: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8080022C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80800230: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80800234: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80800238: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8080023C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80800240: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800244: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800248: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8080024C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800250: jal         0x800EE7F8
    // 0x80800254: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800254: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x80800258: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8080025C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800260: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800264: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800268: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x8080026C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800270: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800274: jal         0x800EF1B8
    // 0x80800278: nop

    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x80800278: nop

    after_1:
    // 0x8080027C: addiu       $s6, $sp, 0x60
    ctx->r22 = ADD32(ctx->r29, 0X60);
    // 0x80800280: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800284: jal         0x800EE7F8
    // 0x80800288: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800288: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_2:
    // 0x8080028C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800290: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800294: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80800298: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8080029C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808002A0: jal         0x800B53A4
    // 0x808002A4: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    func_800B53A4(rdram, ctx);
        goto after_3;
    // 0x808002A4: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x808002A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002AC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808002B0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808002B4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808002B8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808002BC: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(856, 0X450) << 16);
    // 0x808002C0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808002C4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808002C8: addiu       $s3, $s3, 0x450
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(856, 0X450));
    // 0x808002CC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808002D0: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x808002D4: addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
    // 0x808002D8: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_808002DC:
    // 0x808002DC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808002E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808002E8: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x808002EC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808002F0: jal         0x800EEB9C
    // 0x808002F4: nop

    func_800EEB9C(rdram, ctx);
        goto after_4;
    // 0x808002F4: nop

    after_4:
    // 0x808002F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002FC: jal         0x800EF04C
    // 0x80800300: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80800300: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_5:
    // 0x80800304: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800308: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080030C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800310: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800314: jal         0x800BABB8
    // 0x80800318: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x80800318: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_6:
    // 0x8080031C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800320: bnel        $s0, $s4, L_808002DC
    if (ctx->r16 != ctx->r20) {
        // 0x80800324: mtc1        $s0, $f4
        ctx->f4.u32l = ctx->r16;
            goto L_808002DC;
    }
    goto skip_0;
    // 0x80800324: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    skip_0:
    // 0x80800328: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8080032C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800330: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800334: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800338: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8080033C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80800340: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80800344: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80800348: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8080034C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80800350: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80800354: jr          $ra
    // 0x80800358: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80800358: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x8080035C: nop

;}
RECOMP_FUNC void func_80800298_chhillbilly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080029C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808002A4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x808002A8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808002AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808002B0: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x808002B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002B8: sll         $t9, $t7, 18
    ctx->r25 = S32(ctx->r15 << 18);
    // 0x808002BC: bgez        $t9, L_808002CC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808002C0: nop
    
            goto L_808002CC;
    }
    // 0x808002C0: nop

    // 0x808002C4: b           L_808002CC
    // 0x808002C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_808002CC;
    // 0x808002C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_808002CC:
    // 0x808002CC: jal         0x800DF744
    // 0x808002D0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x808002D0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808002D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002D8: jal         0x8008A198
    // 0x808002DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _sucoaster_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x808002DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808002E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002E8: jr          $ra
    // 0x808002EC: nop

    return;
    // 0x808002EC: nop

;}
RECOMP_FUNC void func_800A4D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4D6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4D70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4D74: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A4D78: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x800A4D7C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A4D80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800A4D84: swc1        $f12, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f12.u32l;
    // 0x800A4D88: lw          $t7, 0x38($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X38);
    // 0x800A4D8C: jal         0x800A3BA8
    // 0x800A4D90: swc1        $f14, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f14.u32l;
    func_800A3BA8(rdram, ctx);
        goto after_0;
    // 0x800A4D90: swc1        $f14, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f14.u32l;
    after_0:
    // 0x800A4D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4D98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4D9C: jr          $ra
    // 0x800A4DA0: nop

    return;
    // 0x800A4DA0: nop

;}
RECOMP_FUNC void _bssub_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D60: syscall     93
    recomp_syscall_handler(rdram, ctx, 0x80083D60);
    return;
    // 0x80083D64: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void chnewfreezy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013C4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808013C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808013CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808013D0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x808013D4: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x808013D8: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x808013DC: jal         0x80106790
    // 0x808013E0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808013E0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    after_0:
    // 0x808013E4: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x808013E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808013EC: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x808013F0: jal         0x8010108C
    // 0x808013F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_1;
    // 0x808013F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808013F8: bgtz        $v0, L_80801408
    if (SIGNED(ctx->r2) > 0) {
        // 0x808013FC: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_80801408;
    }
    // 0x808013FC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80801400: b           L_808016A0
    // 0x80801404: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808016A0;
    // 0x80801404: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801408:
    // 0x80801408: jal         0x80101080
    // 0x8080140C: nop

    func_80101080(rdram, ctx);
        goto after_2;
    // 0x8080140C: nop

    after_2:
    // 0x80801410: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80801414: addiu       $a0, $zero, 0x2FF
    ctx->r4 = ADD32(0, 0X2FF);
    // 0x80801418: jal         0x801084B0
    // 0x8080141C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_801084B0(rdram, ctx);
        goto after_3;
    // 0x8080141C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_3:
    // 0x80801420: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80801424: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801428: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    // 0x8080142C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80801430: nop

    // 0x80801434: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801438: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x8080143C: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80801440: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80801444: nop

    // 0x80801448: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080144C: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
    // 0x80801450: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80801454: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80801458: nop

    // 0x8080145C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80801460: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80801464: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    // 0x80801468: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8080146C: lwc1        $f4, 0x44($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X44);
    // 0x80801470: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    // 0x80801474: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80801478: lwc1        $f6, 0x48($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X48);
    // 0x8080147C: swc1        $f6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f6.u32l;
    // 0x80801480: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80801484: lwc1        $f8, 0x4C($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X4C);
    // 0x80801488: swc1        $f8, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f8.u32l;
    // 0x8080148C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80801490: lwc1        $f10, 0x38($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X38);
    // 0x80801494: swc1        $f16, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f16.u32l;
    // 0x80801498: swc1        $f10, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f10.u32l;
    // 0x8080149C: jal         0x80103DFC
    // 0x808014A0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    func_80103DFC(rdram, ctx);
        goto after_4;
    // 0x808014A0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_4:
    // 0x808014A4: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x808014A8: jal         0x801039E4
    // 0x808014AC: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    func_801039E4(rdram, ctx);
        goto after_5;
    // 0x808014AC: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_5:
    // 0x808014B0: jal         0x800B27E0
    // 0x808014B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27E0(rdram, ctx);
        goto after_6;
    // 0x808014B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x808014B8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x808014BC: jal         0x80087A08
    // 0x808014C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _dbskeleton_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x808014C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x808014C4: lhu         $t6, 0x6E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X6E);
    // 0x808014C8: andi        $t5, $v0, 0x1FF
    ctx->r13 = ctx->r2 & 0X1FF;
    // 0x808014CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014D0: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x808014D4: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x808014D8: sh          $t8, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r24;
    // 0x808014DC: lw          $a2, 0x6C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X6C);
    // 0x808014E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808014E4: andi        $t9, $a2, 0x1FF
    ctx->r25 = ctx->r6 & 0X1FF;
    // 0x808014E8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x808014EC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x808014F0: jal         0x80100074
    // 0x808014F4: sll         $a2, $t0, 5
    ctx->r6 = S32(ctx->r8 << 5);
    func_80100074(rdram, ctx);
        goto after_8;
    // 0x808014F4: sll         $a2, $t0, 5
    ctx->r6 = S32(ctx->r8 << 5);
    after_8:
    // 0x808014F8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x808014FC: lh          $t2, 0x10($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X10);
    // 0x80801500: bne         $t2, $zero, L_80801518
    if (ctx->r10 != 0) {
        // 0x80801504: nop
    
            goto L_80801518;
    }
    // 0x80801504: nop

    // 0x80801508: jal         0x800AE020
    // 0x8080150C: nop

    func_800AE020(rdram, ctx);
        goto after_9;
    // 0x8080150C: nop

    after_9:
    // 0x80801510: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80801514: sh          $v0, 0x10($t3)
    MEM_H(0X10, ctx->r11) = ctx->r2;
L_80801518:
    // 0x80801518: jal         0x80104248
    // 0x8080151C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    func_80104248(rdram, ctx);
        goto after_10;
    // 0x8080151C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_10:
    // 0x80801520: jal         0x8008B4D4
    // 0x80801524: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B4D4(rdram, ctx);
        goto after_11;
    // 0x80801524: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x80801528: jal         0x800DF41C
    // 0x8080152C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF41C(rdram, ctx);
        goto after_12;
    // 0x8080152C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x80801530: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80801534: addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    // 0x80801538: jal         0x8010108C
    // 0x8080153C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_13;
    // 0x8080153C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80801540: blezl       $v0, L_8080156C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801544: lw          $t6, 0x40($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X40);
            goto L_8080156C;
    }
    goto skip_0;
    // 0x80801544: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x80801548: jal         0x80101038
    // 0x8080154C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_80101038(rdram, ctx);
        goto after_14;
    // 0x8080154C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_14:
    // 0x80801550: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801554: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80801558: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8080155C: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x80801560: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80801564: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80801568: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
L_8080156C:
    // 0x8080156C: beql        $t6, $zero, L_80801584
    if (ctx->r14 == 0) {
        // 0x80801570: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801584;
    }
    goto skip_1;
    // 0x80801570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80801574: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801578: jal         0x808011A8
    // 0x8080157C: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    func_808011A8_chnewfreezy(rdram, ctx);
        goto after_15;
    // 0x8080157C: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    after_15:
    // 0x80801580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801584:
    // 0x80801584: jal         0x80800974
    // 0x80801588: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80800974_chnewfreezy(rdram, ctx);
        goto after_16;
    // 0x80801588: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_16:
    // 0x8080158C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801590: jal         0x80800AA4
    // 0x80801594: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80800AA4_chnewfreezy(rdram, ctx);
        goto after_17;
    // 0x80801594: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_17:
    // 0x80801598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080159C: jal         0x80800BFC
    // 0x808015A0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80800BFC_chnewfreezy(rdram, ctx);
        goto after_18;
    // 0x808015A0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_18:
    // 0x808015A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015A8: jal         0x80800D28
    // 0x808015AC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80800D28_chnewfreezy(rdram, ctx);
        goto after_19;
    // 0x808015AC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_19:
    // 0x808015B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015B4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x808015B8: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x808015BC: jal         0x80800E74
    // 0x808015C0: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    func_80800E74_chnewfreezy(rdram, ctx);
        goto after_20;
    // 0x808015C0: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    after_20:
    // 0x808015C4: jal         0x808012F8
    // 0x808015C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808012F8_chnewfreezy(rdram, ctx);
        goto after_21;
    // 0x808015C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808015CC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x808015D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808015D4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x808015D8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808015DC: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x808015E0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x808015E4: nop

    // 0x808015E8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x808015EC: beql        $t7, $zero, L_8080163C
    if (ctx->r15 == 0) {
        // 0x808015F0: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_8080163C;
    }
    goto skip_2;
    // 0x808015F0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x808015F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808015F8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808015FC: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80801600: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80801604: nop

    // 0x80801608: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8080160C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80801610: nop

    // 0x80801614: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80801618: bne         $t7, $zero, L_80801630
    if (ctx->r15 != 0) {
        // 0x8080161C: nop
    
            goto L_80801630;
    }
    // 0x8080161C: nop

    // 0x80801620: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80801624: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801628: b           L_80801648
    // 0x8080162C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80801648;
    // 0x8080162C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80801630:
    // 0x80801630: b           L_80801648
    // 0x80801634: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80801648;
    // 0x80801634: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80801638: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_8080163C:
    // 0x8080163C: nop

    // 0x80801640: bltz        $t7, L_80801630
    if (SIGNED(ctx->r15) < 0) {
        // 0x80801644: nop
    
            goto L_80801630;
    }
    // 0x80801644: nop

L_80801648:
    // 0x80801648: lhu         $t1, 0x76($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X76);
    // 0x8080164C: sll         $t0, $t7, 7
    ctx->r8 = S32(ctx->r15 << 7);
    // 0x80801650: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80801654: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x80801658: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x8080165C: sh          $t3, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r11;
    // 0x80801660: jal         0x800EC708
    // 0x80801664: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800EC708(rdram, ctx);
        goto after_22;
    // 0x80801664: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_22:
    // 0x80801668: lhu         $t4, 0x76($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X76);
    // 0x8080166C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80801670: srl         $t6, $t4, 7
    ctx->r14 = S32(U32(ctx->r12) >> 7);
    // 0x80801674: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80801678: bgez        $t6, L_8080168C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8080167C: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8080168C;
    }
    // 0x8080167C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80801680: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801684: nop

    // 0x80801688: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8080168C:
    // 0x8080168C: div.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80801690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801694: jal         0x80089B80
    // 0x80801698: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
    _sufreezy_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x80801698: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
    after_23:
    // 0x8080169C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_808016A0:
    // 0x808016A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808016A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808016A8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x808016AC: jr          $ra
    // 0x808016B0: nop

    return;
    // 0x808016B0: nop

;}
RECOMP_FUNC void func_80801004_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801004: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080100C: jal         0x800845D0
    // 0x80801010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801014: jal         0x80800448
    // 0x80801018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstrexsmall_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80801018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080101C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801024: jr          $ra
    // 0x80801028: nop

    return;
    // 0x80801028: nop

;}
RECOMP_FUNC void func_80094C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094C64: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80094C68: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80094C6C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80094C70: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80094C74: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80094C78: lw          $t9, 0x7E30($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7E30);
    // 0x80094C7C: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x80094C80: jr          $ra
    // 0x80094C84: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    return;
    // 0x80094C84: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
;}
RECOMP_FUNC void func_800F8A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8A50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F8A54: jr          $ra
    // 0x800F8A58: lwc1        $f0, 0x550C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X550C);
    return;
    // 0x800F8A58: lwc1        $f0, 0x550C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X550C);
;}
RECOMP_FUNC void func_80800338_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800338: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080033C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800340: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800344: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x80800348: ori         $t6, $a2, 0x4
    ctx->r14 = ctx->r6 | 0X4;
    // 0x8080034C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800350: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x80800354: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80800358: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8080035C: jal         0x8008A208
    // 0x80800360: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80800360: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    after_0:
    // 0x80800364: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80800368: lbu         $t0, 0x74($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X74);
    // 0x8080036C: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x80800370: sb          $t1, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r9;
    // 0x80800374: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800378: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080037C: jr          $ra
    // 0x80800380: nop

    return;
    // 0x80800380: nop

;}
RECOMP_FUNC void func_800A1870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A1874: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1878: lw          $t6, 0x158($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X158);
    // 0x800A187C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A1880: beql        $t6, $zero, L_800A189C
    if (ctx->r14 == 0) {
        // 0x800A1884: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800A189C;
    }
    goto skip_0;
    // 0x800A1884: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_0:
    // 0x800A1888: jal         0x800F9F2C
    // 0x800A188C: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    func_800F9F2C(rdram, ctx);
        goto after_0;
    // 0x800A188C: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    after_0:
    // 0x800A1890: b           L_800A18BC
    // 0x800A1894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A18BC;
    // 0x800A1894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A1898: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_800A189C:
    // 0x800A189C: jal         0x800A3274
    // 0x800A18A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800A3274(rdram, ctx);
        goto after_1;
    // 0x800A18A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x800A18A4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800A18A8: jal         0x800D4FB8
    // 0x800A18AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D4FB8(rdram, ctx);
        goto after_2;
    // 0x800A18AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800A18B0: jal         0x800A1294
    // 0x800A18B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A1294(rdram, ctx);
        goto after_3;
    // 0x800A18B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800A18B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A18BC:
    // 0x800A18BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A18C0: jr          $ra
    // 0x800A18C4: nop

    return;
    // 0x800A18C4: nop

;}
RECOMP_FUNC void func_80806D84_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806D84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80806D88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806D8C: jal         0x80100094
    // 0x80806D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80806D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80806D94: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    // 0x80806D98: beql        $t6, $zero, L_80806DB4
    if (ctx->r14 == 0) {
        // 0x80806D9C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80806DB4;
    }
    goto skip_0;
    // 0x80806D9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80806DA0: jal         0x80106790
    // 0x80806DA4: lw          $a0, 0x64($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X64);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80806DA4: lw          $a0, 0x64($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X64);
    after_1:
    // 0x80806DA8: b           L_80806DB8
    // 0x80806DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80806DB8;
    // 0x80806DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80806DB4:
    // 0x80806DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806DB8:
    // 0x80806DB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80806DBC: jr          $ra
    // 0x80806DC0: nop

    return;
    // 0x80806DC0: nop

;}
RECOMP_FUNC void func_800E8870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8874: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E8878: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x800E887C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8880: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800E8884: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E8888: lw          $a0, -0x2A00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A00);
    // 0x800E888C: jal         0x800B301C
    // 0x800E8890: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x800E8890: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800E8894: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800E8898: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800E889C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E88A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E88A4: jr          $ra
    // 0x800E88A8: nop

    return;
    // 0x800E88A8: nop

;}
RECOMP_FUNC void func_808004AC_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808004B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004BC: jal         0x8008CABC
    // 0x808004C0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808004C0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x808004C4: lui         $a1, 0x3E94
    ctx->r5 = S32(0X3E94 << 16);
    // 0x808004C8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808004CC: ori         $a1, $a1, 0x7AE1
    ctx->r5 = ctx->r5 | 0X7AE1;
    // 0x808004D0: jal         0x8008B348
    // 0x808004D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x808004D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808004D8: beq         $v0, $zero, L_80800508
    if (ctx->r2 == 0) {
        // 0x808004DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800508;
    }
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E0: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x808004E4: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x808004E8: addiu       $t6, $zero, 0x55F0
    ctx->r14 = ADD32(0, 0X55F0);
    // 0x808004EC: addiu       $t7, $zero, 0x55F0
    ctx->r15 = ADD32(0, 0X55F0);
    // 0x808004F0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808004F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808004F8: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x808004FC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800500: jal         0x8009DEC0
    // 0x80800504: addiu       $a1, $zero, 0x583
    ctx->r5 = ADD32(0, 0X583);
    func_8009DEC0(rdram, ctx);
        goto after_2;
    // 0x80800504: addiu       $a1, $zero, 0x583
    ctx->r5 = ADD32(0, 0X583);
    after_2:
L_80800508:
    // 0x80800508: lui         $a1, 0x3F3D
    ctx->r5 = S32(0X3F3D << 16);
    // 0x8080050C: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    // 0x80800510: jal         0x8008B348
    // 0x80800514: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x80800514: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800518: beq         $v0, $zero, L_80800548
    if (ctx->r2 == 0) {
        // 0x8080051C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800548;
    }
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800520: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80800524: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x80800528: addiu       $t8, $zero, 0x55F0
    ctx->r24 = ADD32(0, 0X55F0);
    // 0x8080052C: addiu       $t9, $zero, 0x55F0
    ctx->r25 = ADD32(0, 0X55F0);
    // 0x80800530: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800534: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800538: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x8080053C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800540: jal         0x8009DEC0
    // 0x80800544: addiu       $a1, $zero, 0x584
    ctx->r5 = ADD32(0, 0X584);
    func_8009DEC0(rdram, ctx);
        goto after_4;
    // 0x80800544: addiu       $a1, $zero, 0x584
    ctx->r5 = ADD32(0, 0X584);
    after_4:
L_80800548:
    // 0x80800548: lui         $a1, 0x3E0A
    ctx->r5 = S32(0X3E0A << 16);
    // 0x8080054C: ori         $a1, $a1, 0x57A8
    ctx->r5 = ctx->r5 | 0X57A8;
    // 0x80800550: jal         0x8008CB10
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_5;
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800558: beq         $v0, $zero, L_80800568
    if (ctx->r2 == 0) {
        // 0x8080055C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800568;
    }
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800560: jal         0x8009BA58
    // 0x80800564: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_6;
    // 0x80800564: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    after_6:
L_80800568:
    // 0x80800568: lui         $a1, 0x3F2C
    ctx->r5 = S32(0X3F2C << 16);
    // 0x8080056C: ori         $a1, $a1, 0xFAAD
    ctx->r5 = ctx->r5 | 0XFAAD;
    // 0x80800570: jal         0x8008CB10
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_7;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800578: beq         $v0, $zero, L_80800594
    if (ctx->r2 == 0) {
        // 0x8080057C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800594;
    }
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800580: jal         0x80084538
    // 0x80800584: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babackpack_set_state(rdram, ctx);
        goto after_8;
    // 0x80800584: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080058C: jal         0x800A0CD0
    // 0x80800590: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CD0(rdram, ctx);
        goto after_9;
    // 0x80800590: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
L_80800594:
    // 0x80800594: jal         0x8008CAEC
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_10;
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080059C: beq         $v0, $zero, L_808005AC
    if (ctx->r2 == 0) {
        // 0x808005A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005AC;
    }
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808005A8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_808005AC:
    // 0x808005AC: jal         0x8009E5C8
    // 0x808005B0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_11;
    // 0x808005B0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_11:
    // 0x808005B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808005C0: jr          $ra
    // 0x808005C4: nop

    return;
    // 0x808005C4: nop

;}
RECOMP_FUNC void func_80800B68_chfloaty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B68: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80800B6C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800B70: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800B74: addiu       $v0, $t6, -0x32
    ctx->r2 = ADD32(ctx->r14, -0X32);
    // 0x80800B78: beql        $v0, $zero, L_80800BA0
    if (ctx->r2 == 0) {
        // 0x80800B7C: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80800BA0;
    }
    goto skip_0;
    // 0x80800B7C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80800B80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B84: beq         $v0, $at, L_80800BA8
    if (ctx->r2 == ctx->r1) {
        // 0x80800B88: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800BA8;
    }
    // 0x80800B88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B8C: beql        $v0, $at, L_80800BBC
    if (ctx->r2 == ctx->r1) {
        // 0x80800B90: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_80800BBC;
    }
    goto skip_1;
    // 0x80800B90: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    skip_1:
    // 0x80800B94: b           L_80800BC8
    // 0x80800B98: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
        goto L_80800BC8;
    // 0x80800B98: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800B9C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80800BA0:
    // 0x80800BA0: jr          $ra
    // 0x80800BA4: nop

    return;
    // 0x80800BA4: nop

L_80800BA8:
    // 0x80800BA8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800BAC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800BB0: jr          $ra
    // 0x80800BB4: nop

    return;
    // 0x80800BB4: nop

    // 0x80800BB8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
L_80800BBC:
    // 0x80800BBC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800BC0: jr          $ra
    // 0x80800BC4: nop

    return;
    // 0x80800BC4: nop

L_80800BC8:
    // 0x80800BC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800BCC: nop

    // 0x80800BD0: jr          $ra
    // 0x80800BD4: nop

    return;
    // 0x80800BD4: nop

;}
RECOMP_FUNC void func_800A7A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7A90: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A7A94: addiu       $v0, $v0, 0x7630
    ctx->r2 = ADD32(ctx->r2, 0X7630);
    // 0x800A7A98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7A9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7AA0: sb          $a0, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r4;
    // 0x800A7AA4: beq         $a0, $zero, L_800A7AC4
    if (ctx->r4 == 0) {
        // 0x800A7AA8: sb          $zero, 0x17($v0)
        MEM_B(0X17, ctx->r2) = 0;
            goto L_800A7AC4;
    }
    // 0x800A7AA8: sb          $zero, 0x17($v0)
    MEM_B(0X17, ctx->r2) = 0;
    // 0x800A7AAC: jal         0x800C9510
    // 0x800A7AB0: nop

    func_800C9510(rdram, ctx);
        goto after_0;
    // 0x800A7AB0: nop

    after_0:
    // 0x800A7AB4: bnel        $v0, $zero, L_800A7AC8
    if (ctx->r2 != 0) {
        // 0x800A7AB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A7AC8;
    }
    goto skip_0;
    // 0x800A7AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A7ABC: jal         0x800C9610
    // 0x800A7AC0: nop

    func_800C9610(rdram, ctx);
        goto after_1;
    // 0x800A7AC0: nop

    after_1:
L_800A7AC4:
    // 0x800A7AC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7AC8:
    // 0x800A7AC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A7ACC: jr          $ra
    // 0x800A7AD0: nop

    return;
    // 0x800A7AD0: nop

;}
RECOMP_FUNC void sujiggy_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800854: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800858: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080085C: addiu       $a0, $zero, 0xC0D
    ctx->r4 = ADD32(0, 0XC0D);
    // 0x80800860: jal         0x800DA564
    // 0x80800864: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x80800864: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80800868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080086C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800870: jr          $ra
    // 0x80800874: nop

    return;
    // 0x80800874: nop

;}
RECOMP_FUNC void func_808010FC_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801100: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801104: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801108: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x8080110C: jal         0x8008FE68
    // 0x80801110: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_8008FE68(rdram, ctx);
        goto after_0;
    // 0x80801110: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80801114: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80801118: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080111C: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80801120: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80801124: nop

    // 0x80801128: bc1f        L_808011DC
    if (!c1cs) {
        // 0x8080112C: nop
    
            goto L_808011DC;
    }
    // 0x8080112C: nop

    // 0x80801130: lw          $t6, 0x64($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X64);
    // 0x80801134: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80801138: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x8080113C: bltzl       $t8, L_80801164
    if (SIGNED(ctx->r24) < 0) {
        // 0x80801140: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80801164;
    }
    goto skip_0;
    // 0x80801140: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_0:
    // 0x80801144: jal         0x800FEC60
    // 0x80801148: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_800FEC60(rdram, ctx);
        goto after_1;
    // 0x80801148: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_1:
    // 0x8080114C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80801150: lbu         $t0, 0x65($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X65);
    // 0x80801154: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80801158: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x8080115C: sb          $t1, 0x65($a1)
    MEM_B(0X65, ctx->r5) = ctx->r9;
    // 0x80801160: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80801164:
    // 0x80801164: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80801168: lui         $a2, 0x44FA
    ctx->r6 = S32(0X44FA << 16);
    // 0x8080116C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80801170: sub.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80801174: jal         0x800F10B4
    // 0x80801178: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80801178: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x8080117C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80801180: jal         0x800FEC1C
    // 0x80801184: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800FEC1C(rdram, ctx);
        goto after_3;
    // 0x80801184: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x80801188: jal         0x800FCCD4
    // 0x8080118C: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    func_800FCCD4(rdram, ctx);
        goto after_4;
    // 0x8080118C: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_4:
    // 0x80801190: bnel        $v0, $zero, L_808011A4
    if (ctx->r2 != 0) {
        // 0x80801194: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808011A4;
    }
    goto skip_1;
    // 0x80801194: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x80801198: jal         0x800FC6B0
    // 0x8080119C: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    func_800FC6B0(rdram, ctx);
        goto after_5;
    // 0x8080119C: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_5:
    // 0x808011A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_808011A4:
    // 0x808011A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808011A8: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808011AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1236, 0X1260) << 16);
    // 0x808011B0: lwc1        $f18, 0x1260($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1236, 0X1260));
    // 0x808011B4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x808011B8: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // 0x808011BC: addiu       $a2, $zero, 0x7D0
    ctx->r6 = ADD32(0, 0X7D0);
    // 0x808011C0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808011C4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808011C8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808011CC: jal         0x800FCAE0
    // 0x808011D0: nop

    func_800FCAE0(rdram, ctx);
        goto after_6;
    // 0x808011D0: nop

    after_6:
    // 0x808011D4: b           L_808011E8
    // 0x808011D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808011E8;
    // 0x808011D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808011DC:
    // 0x808011DC: jal         0x8080102C
    // 0x808011E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8080102C_chbanjoctrl(rdram, ctx);
        goto after_7;
    // 0x808011E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_7:
    // 0x808011E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808011E8:
    // 0x808011E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808011EC: jr          $ra
    // 0x808011F0: nop

    return;
    // 0x808011F0: nop

;}
RECOMP_FUNC void bstnt_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011B8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808011BC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(404, 0X254C) << 16);
    // 0x808011C0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808011C4: jr          $ra
    // 0x808011C8: lw          $v0, 0x254C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X254C));
    return;
    // 0x808011C8: lw          $v0, 0x254C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X254C));
;}
RECOMP_FUNC void chelectricfence_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002AC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808002B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808002B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808002BC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x808002C0: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x808002C4: jal         0x800DC298
    // 0x808002C8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    func_800DC298(rdram, ctx);
        goto after_0;
    // 0x808002C8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    after_0:
    // 0x808002CC: beql        $v0, $zero, L_808002E8
    if (ctx->r2 == 0) {
        // 0x808002D0: lw          $t7, 0x70($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X70);
            goto L_808002E8;
    }
    goto skip_0;
    // 0x808002D0: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    skip_0:
    // 0x808002D4: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x808002D8: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x808002DC: b           L_808002F0
    // 0x808002E0: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
        goto L_808002F0;
    // 0x808002E0: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x808002E4: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
L_808002E8:
    // 0x808002E8: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x808002EC: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
L_808002F0:
    // 0x808002F0: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x808002F4: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x808002F8: lwc1        $f12, 0x0($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X0);
    // 0x808002FC: jal         0x800DC178
    // 0x80800300: lwc1        $f14, 0x0($t9)
    ctx->f14.u32l = MEM_W(ctx->r25, 0X0);
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800300: lwc1        $f14, 0x0($t9)
    ctx->f14.u32l = MEM_W(ctx->r25, 0X0);
    after_1:
    // 0x80800304: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x80800308: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8080030C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800310: lwc1        $f12, 0x4($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80800314: jal         0x800DC178
    // 0x80800318: lwc1        $f14, 0x4($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X4);
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800318: lwc1        $f14, 0x4($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X4);
    after_2:
    // 0x8080031C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800320: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80800324: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800328: jal         0x800EFA4C
    // 0x8080032C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x8080032C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x80800330: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x80800334: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80800338: lwc1        $f12, 0x0($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8080033C: jal         0x800DC178
    // 0x80800340: lwc1        $f14, 0x0($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, 0X0);
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800340: lwc1        $f14, 0x0($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, 0X0);
    after_4:
    // 0x80800344: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x80800348: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x8080034C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800350: lwc1        $f12, 0x4($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80800354: jal         0x800DC178
    // 0x80800358: lwc1        $f14, 0x4($t5)
    ctx->f14.u32l = MEM_W(ctx->r13, 0X4);
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800358: lwc1        $f14, 0x4($t5)
    ctx->f14.u32l = MEM_W(ctx->r13, 0X4);
    after_5:
    // 0x8080035C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800360: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800364: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800368: jal         0x800EFA4C
    // 0x8080036C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_800EFA4C(rdram, ctx);
        goto after_6;
    // 0x8080036C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_6:
    // 0x80800370: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80800374: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80800378: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080037C: jal         0x800EF934
    // 0x80800380: lw          $a2, 0x48($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X48);
    func_800EF934(rdram, ctx);
        goto after_7;
    // 0x80800380: lw          $a2, 0x48($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X48);
    after_7:
    // 0x80800384: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80800388: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x8080038C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800390: jal         0x800EF04C
    // 0x80800394: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x80800394: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_8:
    // 0x80800398: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8080039C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808003A0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808003A4: jal         0x800EF934
    // 0x808003A8: lw          $a2, 0x48($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X48);
    func_800EF934(rdram, ctx);
        goto after_9;
    // 0x808003A8: lw          $a2, 0x48($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X48);
    after_9:
    // 0x808003AC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808003B0: jal         0x800EF04C
    // 0x808003B4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EF04C(rdram, ctx);
        goto after_10;
    // 0x808003B4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x808003B8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808003BC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x808003C0: jal         0x800EFB24
    // 0x808003C4: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_800EFB24(rdram, ctx);
        goto after_11;
    // 0x808003C4: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_11:
    // 0x808003C8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808003CC: jal         0x800EF368
    // 0x808003D0: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    func_800EF368(rdram, ctx);
        goto after_12;
    // 0x808003D0: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_12:
    // 0x808003D4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808003D8: jal         0x800EEAD4
    // 0x808003DC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_800EEAD4(rdram, ctx);
        goto after_13;
    // 0x808003DC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_13:
    // 0x808003E0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808003E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808003E8: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x808003EC: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808003F0: jal         0x800B5BE4
    // 0x808003F4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    func_800B5BE4(rdram, ctx);
        goto after_14;
    // 0x808003F4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_14:
    // 0x808003F8: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1180, 0X5A4) << 16);
    // 0x808003FC: addiu       $t8, $t8, 0x5A4
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1180, 0X5A4));
    // 0x80800400: lui         $a3, 0x3FE6
    ctx->r7 = S32(0X3FE6 << 16);
    // 0x80800404: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800408: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x8080040C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800410: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800414: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80800418: jal         0x800BABB8
    // 0x8080041C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_15;
    // 0x8080041C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x80800420: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800424: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800428: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080042C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800430: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800434: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800438: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080043C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800440: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800444: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x80800448: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8080044C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800450: sll         $t3, $a2, 16
    ctx->r11 = S32(ctx->r6 << 16);
    // 0x80800454: sra         $a2, $t3, 16
    ctx->r6 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80800458: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x8080045C: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80800460: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80800464: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x80800468: jal         0x800BA930
    // 0x8080046C: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    func_800BA930(rdram, ctx);
        goto after_16;
    // 0x8080046C: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    after_16:
    // 0x80800470: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800474: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800478: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080047C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800480: jal         0x800BA8F8
    // 0x80800484: nop

    func_800BA8F8(rdram, ctx);
        goto after_17;
    // 0x80800484: nop

    after_17:
    // 0x80800488: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8080048C: jal         0x800BA22C
    // 0x80800490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_18;
    // 0x80800490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80800494: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800498: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8080049C: jr          $ra
    // 0x808004A0: nop

    return;
    // 0x808004A0: nop

    // 0x808004A4: nop

    // 0x808004A8: nop

    // 0x808004AC: nop

;}
RECOMP_FUNC void _chstonedartgunhead_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F20: syscall     475
    recomp_syscall_handler(rdram, ctx, 0x80086F20);
    return;
    // 0x80086F24: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080051C_chintrotext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080051C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800520: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800524: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800528: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080052C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800530: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80800534: jal         0x80100094
    // 0x80800538: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800538: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080053C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800544: jal         0x80101FDC
    // 0x80800548: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800548: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080054C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800550: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800554: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800558: beq         $a2, $at, L_80800584
    if (ctx->r6 == ctx->r1) {
        // 0x8080055C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800584;
    }
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800560: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800564: beq         $a2, $at, L_8080059C
    if (ctx->r6 == ctx->r1) {
        // 0x80800568: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080059C;
    }
    // 0x80800568: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080056C: beq         $a2, $at, L_808005B8
    if (ctx->r6 == ctx->r1) {
        // 0x80800570: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_808005B8;
    }
    // 0x80800570: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800574: beq         $a2, $at, L_808005D4
    if (ctx->r6 == ctx->r1) {
        // 0x80800578: addiu       $a0, $zero, 0x6AD
        ctx->r4 = ADD32(0, 0X6AD);
            goto L_808005D4;
    }
    // 0x80800578: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    // 0x8080057C: b           L_808005FC
    // 0x80800580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808005FC;
    // 0x80800580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800584:
    // 0x80800584: jal         0x80089C98
    // 0x80800588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080058C: jal         0x800DA544
    // 0x80800590: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800590: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_3:
    // 0x80800594: b           L_808005FC
    // 0x80800598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808005FC;
    // 0x80800598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080059C:
    // 0x8080059C: lbu         $t6, 0x3F($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3F);
    // 0x808005A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1120, 0X7A0) << 16);
    // 0x808005A4: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x808005A8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808005AC: lwc1        $f4, 0x7A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1120, 0X7A0));
    // 0x808005B0: b           L_808005F8
    // 0x808005B4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_808005F8;
    // 0x808005B4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808005B8:
    // 0x808005B8: lbu         $t8, 0x3F($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3F);
    // 0x808005BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1120, 0X7A4) << 16);
    // 0x808005C0: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x808005C4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808005C8: lwc1        $f6, 0x7A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1120, 0X7A4));
    // 0x808005CC: b           L_808005F8
    // 0x808005D0: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_808005F8;
    // 0x808005D0: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_808005D4:
    // 0x808005D4: jal         0x800DA524
    // 0x808005D8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800DA524(rdram, ctx);
        goto after_4;
    // 0x808005D8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x808005DC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808005E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1120, 0X7A8) << 16);
    // 0x808005E4: lbu         $t0, 0x3F($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X3F);
    // 0x808005E8: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x808005EC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x808005F0: lwc1        $f8, 0x7A8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1120, 0X7A8));
    // 0x808005F4: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_808005F8:
    // 0x808005F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005FC:
    // 0x808005FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800600: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800604: jr          $ra
    // 0x80800608: nop

    return;
    // 0x80800608: nop

;}
RECOMP_FUNC void func_80801758_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080175C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801760: jal         0x80106790
    // 0x80801764: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801764: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801768: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080176C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801770: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801774: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80801778: jal         0x80801338
    // 0x8080177C: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    func_80801338_chgameselect(rdram, ctx);
        goto after_1;
    // 0x8080177C: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    after_1:
    // 0x80801780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801788: jr          $ra
    // 0x8080178C: nop

    return;
    // 0x8080178C: nop

;}
RECOMP_FUNC void gcmapsects_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080094C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800954: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800958: jal         0x800BF704
    // 0x8080095C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800BF704(rdram, ctx);
        goto after_0;
    // 0x8080095C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800960: lh          $t0, 0x1A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X1A);
    // 0x80800964: lw          $a2, 0x68($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X68);
    // 0x80800968: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x8080096C: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80800970: subu        $t6, $t6, $t0
    ctx->r14 = SUB32(ctx->r14, ctx->r8);
    // 0x80800974: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800978: subu        $t6, $t6, $t0
    ctx->r14 = SUB32(ctx->r14, ctx->r8);
    // 0x8080097C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80800980: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800984: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80800988: addu        $a0, $a2, $t6
    ctx->r4 = ADD32(ctx->r6, ctx->r14);
L_8080098C:
    // 0x8080098C: lbu         $t7, 0x38($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X38);
    // 0x80800990: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800994: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80800998: bne         $a1, $t7, L_808009B0
    if (ctx->r5 != ctx->r15) {
        // 0x8080099C: nop
    
            goto L_808009B0;
    }
    // 0x8080099C: nop

    // 0x808009A0: sb          $a3, 0x38($a0)
    MEM_B(0X38, ctx->r4) = ctx->r7;
    // 0x808009A4: lw          $a2, 0x68($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X68);
    // 0x808009A8: b           L_808009BC
    // 0x808009AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_808009BC;
    // 0x808009AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_808009B0:
    // 0x808009B0: bne         $at, $zero, L_8080098C
    if (ctx->r1 != 0) {
        // 0x808009B4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8080098C;
    }
    // 0x808009B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x808009B8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_808009BC:
    // 0x808009BC: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x808009C0: subu        $t8, $t8, $a3
    ctx->r24 = SUB32(ctx->r24, ctx->r7);
    // 0x808009C4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808009C8: subu        $t8, $t8, $a3
    ctx->r24 = SUB32(ctx->r24, ctx->r7);
    // 0x808009CC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x808009D0: addu        $a0, $a2, $t8
    ctx->r4 = ADD32(ctx->r6, ctx->r24);
    // 0x808009D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_808009D8:
    // 0x808009D8: lbu         $t9, 0x38($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X38);
    // 0x808009DC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808009E0: bne         $a1, $t9, L_808009F0
    if (ctx->r5 != ctx->r25) {
        // 0x808009E4: nop
    
            goto L_808009F0;
    }
    // 0x808009E4: nop

    // 0x808009E8: b           L_808009F8
    // 0x808009EC: sb          $t0, 0x38($a0)
    MEM_B(0X38, ctx->r4) = ctx->r8;
        goto L_808009F8;
    // 0x808009EC: sb          $t0, 0x38($a0)
    MEM_B(0X38, ctx->r4) = ctx->r8;
L_808009F0:
    // 0x808009F0: bne         $v1, $a2, L_808009D8
    if (ctx->r3 != ctx->r6) {
        // 0x808009F4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_808009D8;
    }
    // 0x808009F4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_808009F8:
    // 0x808009F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A00: jr          $ra
    // 0x80800A04: nop

    return;
    // 0x80800A04: nop

;}
RECOMP_FUNC void func_80803EFC_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803EFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803F00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80803F04: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80803F08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803F0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80803F10: lw          $a1, 0x64($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X64);
    // 0x80803F14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80803F18: sll         $t7, $a1, 11
    ctx->r15 = S32(ctx->r5 << 11);
    // 0x80803F1C: jal         0x800DF744
    // 0x80803F20: srl         $a1, $t7, 31
    ctx->r5 = S32(U32(ctx->r15) >> 31);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x80803F20: srl         $a1, $t7, 31
    ctx->r5 = S32(U32(ctx->r15) >> 31);
    after_0:
    // 0x80803F24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80803F28: jal         0x80101870
    // 0x80803F2C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x80803F2C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80803F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803F34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803F38: jr          $ra
    // 0x80803F3C: nop

    return;
    // 0x80803F3C: nop

;}
RECOMP_FUNC void func_808007A4_chswampplatform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007A8: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x808007AC: bne         $a1, $at, L_808007F0
    if (ctx->r5 != ctx->r1) {
        // 0x808007B0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808007F0;
    }
    // 0x808007B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007B4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808007B8: bne         $a2, $at, L_808007E8
    if (ctx->r6 != ctx->r1) {
        // 0x808007BC: nop
    
            goto L_808007E8;
    }
    // 0x808007BC: nop

    // 0x808007C0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808007C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007C8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808007CC: bne         $t7, $zero, L_808007E8
    if (ctx->r15 != 0) {
        // 0x808007D0: nop
    
            goto L_808007E8;
    }
    // 0x808007D0: nop

    // 0x808007D4: jal         0x80101FDC
    // 0x808007D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x808007D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808007DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808007E0: jal         0x80103110
    // 0x808007E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x808007E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_808007E8:
    // 0x808007E8: b           L_808007F4
    // 0x808007EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007F4;
    // 0x808007EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007F0:
    // 0x808007F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007F4:
    // 0x808007F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007FC: jr          $ra
    // 0x80800800: nop

    return;
    // 0x80800800: nop

;}
RECOMP_FUNC void glsplinefuncs_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800318: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8080031C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80800320: sw          $a0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r4;
    // 0x80800324: sra         $t7, $a1, 12
    ctx->r15 = S32(SIGNED(ctx->r5) >> 12);
    // 0x80800328: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080032C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80800330: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80800334: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80800338: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x8080033C: andi        $a0, $a1, 0xFFF
    ctx->r4 = ctx->r5 & 0XFFF;
    // 0x80800340: addiu       $t0, $sp, 0x38
    ctx->r8 = ADD32(ctx->r29, 0X38);
    // 0x80800344: addiu       $t1, $sp, 0x34
    ctx->r9 = ADD32(ctx->r29, 0X34);
    // 0x80800348: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x8080034C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80800350: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800354: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80800358: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8080035C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x80800360: jal         0x80800000
    // 0x80800364: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    glsplinefuncs_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800364: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x80800368: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080036C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80800370: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800374: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800378: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8080037C: jal         0x80108474
    // 0x80800380: nop

    func_80108474(rdram, ctx);
        goto after_1;
    // 0x80800380: nop

    after_1:
    // 0x80800384: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800388: jal         0x80105494
    // 0x8080038C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_80105494(rdram, ctx);
        goto after_2;
    // 0x8080038C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800390: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80800394: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80800398: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8080039C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x808003A0: andi        $t7, $t6, 0x7FE
    ctx->r15 = ctx->r14 & 0X7FE;
    // 0x808003A4: andi        $t9, $t8, 0xF801
    ctx->r25 = ctx->r24 & 0XF801;
    // 0x808003A8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x808003AC: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x808003B0: sh          $t0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r8;
    // 0x808003B4: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808003B8: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x808003BC: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808003C0: lbu         $t2, 0x77($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X77);
    // 0x808003C4: swc1        $f10, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f10.u32l;
    // 0x808003C8: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808003CC: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x808003D0: sb          $t3, 0x77($a2)
    MEM_B(0X77, ctx->r6) = ctx->r11;
    // 0x808003D4: beq         $a1, $zero, L_808003E4
    if (ctx->r5 == 0) {
        // 0x808003D8: swc1        $f16, 0x44($a2)
        MEM_W(0X44, ctx->r6) = ctx->f16.u32l;
            goto L_808003E4;
    }
    // 0x808003D8: swc1        $f16, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f16.u32l;
    // 0x808003DC: jal         0x800D87D4
    // 0x808003E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800D87D4(rdram, ctx);
        goto after_3;
    // 0x808003E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
L_808003E4:
    // 0x808003E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003E8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x808003EC: jr          $ra
    // 0x808003F0: nop

    return;
    // 0x808003F0: nop

    // 0x808003F4: nop

    // 0x808003F8: nop

    // 0x808003FC: nop

;}
RECOMP_FUNC void func_80800000_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80100094
    // 0x80800010: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800014: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800018: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8080001C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1732, 0X4790) << 16);
    // 0x80800020: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800024: addiu       $t9, $t9, 0x4790
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1732, 0X4790));
    // 0x80800028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080002C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800030: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80800034: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80800038: lw          $t0, -0x630($v1)
    ctx->r8 = MEM_W(ctx->r3, -0X630);
    // 0x8080003C: lh          $a2, -0x63A($v1)
    ctx->r6 = MEM_H(ctx->r3, -0X63A);
    // 0x80800040: jal         0x800897C0
    // 0x80800044: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800044: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_1:
    // 0x80800048: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8080004C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800050: sll         $t2, $t1, 13
    ctx->r10 = S32(ctx->r9 << 13);
    // 0x80800054: bgezl       $t2, L_80800078
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800058: lw          $t3, 0x44($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X44);
            goto L_80800078;
    }
    goto skip_0;
    // 0x80800058: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8080005C: jal         0x80100094
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800064: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800068: lui         $a1, 0x4320
    ctx->r5 = S32(0X4320 << 16);
    // 0x8080006C: jal         0x800897E8
    // 0x80800070: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80800070: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    after_3:
    // 0x80800074: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
L_80800078:
    // 0x80800078: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    // 0x8080007C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800080: andi        $t4, $t3, 0x2000
    ctx->r12 = ctx->r11 & 0X2000;
    // 0x80800084: beq         $t4, $zero, L_808000EC
    if (ctx->r12 == 0) {
        // 0x80800088: addiu       $a2, $sp, 0x3C
        ctx->r6 = ADD32(ctx->r29, 0X3C);
            goto L_808000EC;
    }
    // 0x80800088: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x8080008C: jal         0x800897A0
    // 0x80800090: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    _suexpression_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800090: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    after_4:
    // 0x80800094: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80800098: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8080009C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x808000A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000A4: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x808000A8: jal         0x8001B668
    // 0x808000AC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    func_8001B668(rdram, ctx);
        goto after_5;
    // 0x808000AC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_5:
    // 0x808000B0: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x808000B4: sh          $v0, 0xC6($v1)
    MEM_H(0XC6, ctx->r3) = ctx->r2;
    // 0x808000B8: jal         0x8001B798
    // 0x808000BC: lh          $a0, 0xC6($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XC6);
    func_8001B798(rdram, ctx);
        goto after_6;
    // 0x808000BC: lh          $a0, 0xC6($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XC6);
    after_6:
    // 0x808000C0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x808000C4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808000C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000CC: addiu       $a1, $zero, 0x7B
    ctx->r5 = ADD32(0, 0X7B);
    // 0x808000D0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x808000D4: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x808000D8: jal         0x800897B8
    // 0x808000DC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _suexpression_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x808000DC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_7:
    // 0x808000E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808000E4: jal         0x800897B0
    // 0x808000E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _suexpression_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x808000E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
L_808000EC:
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808000F4: jr          $ra
    // 0x808000F8: nop

    return;
    // 0x808000F8: nop

;}
RECOMP_FUNC void func_80800204_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800204: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800208: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080020C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80800210: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800214: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800218: beq         $a1, $at, L_808002C8
    if (ctx->r5 == ctx->r1) {
        // 0x8080021C: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_808002C8;
    }
    // 0x8080021C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800220: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800224: beq         $a1, $at, L_80800264
    if (ctx->r5 == ctx->r1) {
        // 0x80800228: addiu       $v1, $sp, 0x30
        ctx->r3 = ADD32(ctx->r29, 0X30);
            goto L_80800264;
    }
    // 0x80800228: addiu       $v1, $sp, 0x30
    ctx->r3 = ADD32(ctx->r29, 0X30);
    // 0x8080022C: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800230: beq         $a1, $at, L_8080027C
    if (ctx->r5 == ctx->r1) {
        // 0x80800234: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_8080027C;
    }
    // 0x80800234: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800238: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x8080023C: beq         $a1, $at, L_808002F0
    if (ctx->r5 == ctx->r1) {
        // 0x80800240: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(868, 0XE50) << 16);
            goto L_808002F0;
    }
    // 0x80800240: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(868, 0XE50) << 16);
    // 0x80800244: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x80800248: beq         $a1, $at, L_80800314
    if (ctx->r5 == ctx->r1) {
        // 0x8080024C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800314;
    }
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800250: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800254: beql        $a1, $at, L_80800308
    if (ctx->r5 == ctx->r1) {
        // 0x80800258: lbu         $t1, 0x65($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X65);
            goto L_80800308;
    }
    goto skip_0;
    // 0x80800258: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    skip_0:
    // 0x8080025C: b           L_80800348
    // 0x80800260: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800348;
    // 0x80800260: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800264:
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800268: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x8080026C: jal         0x80800434
    // 0x80800270: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    func_80800434_chcheato(rdram, ctx);
        goto after_0;
    // 0x80800270: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    after_0:
    // 0x80800274: b           L_80800348
    // 0x80800278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800348;
    // 0x80800278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080027C:
    // 0x8080027C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800280: bne         $t6, $at, L_80800344
    if (ctx->r14 != ctx->r1) {
        // 0x80800284: addiu       $a1, $zero, 0x1143
        ctx->r5 = ADD32(0, 0X1143);
            goto L_80800344;
    }
    // 0x80800284: addiu       $a1, $zero, 0x1143
    ctx->r5 = ADD32(0, 0X1143);
    // 0x80800288: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x8080028C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800290: addiu       $t0, $zero, 0x37
    ctx->r8 = ADD32(0, 0X37);
    // 0x80800294: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80800298: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    // 0x8080029C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808002A0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x808002A4: jal         0x8008A208
    // 0x808002A8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808002A8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x808002AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808002B8: jal         0x80085708
    // 0x808002BC: addiu       $a3, $zero, 0x830
    ctx->r7 = ADD32(0, 0X830);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x808002BC: addiu       $a3, $zero, 0x830
    ctx->r7 = ADD32(0, 0X830);
    after_2:
    // 0x808002C0: b           L_80800348
    // 0x808002C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800348;
    // 0x808002C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002C8:
    // 0x808002C8: jal         0x80101080
    // 0x808002CC: nop

    func_80101080(rdram, ctx);
        goto after_3;
    // 0x808002CC: nop

    after_3:
    // 0x808002D0: addiu       $v1, $sp, 0x30
    ctx->r3 = ADD32(ctx->r29, 0X30);
    // 0x808002D4: lh          $a2, 0x0($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X0);
    // 0x808002D8: lh          $a3, 0x2($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X2);
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E0: jal         0x80800AB4
    // 0x808002E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800AB4_chcheato(rdram, ctx);
        goto after_4;
    // 0x808002E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x808002E8: b           L_80800348
    // 0x808002EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800348;
    // 0x808002EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002F0:
    // 0x808002F0: addiu       $a0, $a0, 0xE50
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(868, 0XE50));
    // 0x808002F4: jal         0x80088090
    // 0x808002F8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808002F8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x808002FC: b           L_80800348
    // 0x80800300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800348;
    // 0x80800300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800304: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
L_80800308:
    // 0x80800308: andi        $t2, $t1, 0xFFEF
    ctx->r10 = ctx->r9 & 0XFFEF;
    // 0x8080030C: b           L_80800344
    // 0x80800310: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
        goto L_80800344;
    // 0x80800310: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_80800314:
    // 0x80800314: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800318: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8080031C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800320: andi        $t3, $a1, 0xFFFF
    ctx->r11 = ctx->r5 & 0XFFFF;
    // 0x80800324: and         $t4, $a2, $at
    ctx->r12 = ctx->r6 & ctx->r1;
    // 0x80800328: srl         $a2, $t4, 16
    ctx->r6 = S32(U32(ctx->r12) >> 16);
    // 0x8080032C: jal         0x80800C64
    // 0x80800330: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_80800C64_chcheato(rdram, ctx);
        goto after_6;
    // 0x80800330: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_6:
    // 0x80800334: b           L_8080034C
    // 0x80800338: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080034C;
    // 0x80800338: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080033C: b           L_80800348
    // 0x80800340: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800348;
    // 0x80800340: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800344:
    // 0x80800344: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800348:
    // 0x80800348: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080034C:
    // 0x8080034C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800350: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800354: jr          $ra
    // 0x80800358: nop

    return;
    // 0x80800358: nop

;}
RECOMP_FUNC void chevilmumbo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1676, 0X4460) << 16);
    // 0x80803004: jr          $ra
    // 0x80803008: addiu       $v0, $v0, 0x4460
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1676, 0X4460));
    return;
    // 0x80803008: addiu       $v0, $v0, 0x4460
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1676, 0X4460));
;}
RECOMP_FUNC void func_8009BA9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BA9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BAA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BAA4: beq         $a1, $zero, L_8009BAC0
    if (ctx->r5 == 0) {
        // 0x8009BAA8: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8009BAC0;
    }
    // 0x8009BAA8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8009BAAC: lw          $a0, 0xC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC8);
    // 0x8009BAB0: jal         0x800EE7F8
    // 0x8009BAB4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009BAB4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x8009BAB8: b           L_8009BAD0
    // 0x8009BABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8009BAD0;
    // 0x8009BABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009BAC0:
    // 0x8009BAC0: lw          $a0, 0xC8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XC8);
    // 0x8009BAC4: jal         0x800EFD24
    // 0x8009BAC8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x8009BAC8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_1:
    // 0x8009BACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009BAD0:
    // 0x8009BAD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BAD4: jr          $ra
    // 0x8009BAD8: nop

    return;
    // 0x8009BAD8: nop

;}
RECOMP_FUNC void func_80801AC0_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AC0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80801AC4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80801AC8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80801ACC: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80801AD0: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80801AD4: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80801AD8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80801ADC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80801AE0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80801AE4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80801AE8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80801AEC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80801AF0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80801AF4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80801AF8: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x80801AFC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80801B00: addiu       $s0, $a0, 0xC
    ctx->r16 = ADD32(ctx->r4, 0XC);
    // 0x80801B04: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80801B08: addiu       $s2, $a1, 0x4
    ctx->r18 = ADD32(ctx->r5, 0X4);
    // 0x80801B0C: addiu       $s3, $a2, 0x4
    ctx->r19 = ADD32(ctx->r6, 0X4);
    // 0x80801B10: addiu       $s6, $zero, 0x9
    ctx->r22 = ADD32(0, 0X9);
L_80801B14:
    // 0x80801B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B18: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80801B1C: jal         0x800EEB9C
    // 0x80801B20: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    func_800EEB9C(rdram, ctx);
        goto after_0;
    // 0x80801B20: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    after_0:
    // 0x80801B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B28: jal         0x800EF04C
    // 0x80801B2C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x80801B2C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_1:
    // 0x80801B30: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x80801B34: lwc1        $f6, 0x70($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X70);
    // 0x80801B38: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80801B3C: lw          $a3, 0x4($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X4);
    // 0x80801B40: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80801B44: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80801B48: jal         0x800F10B4
    // 0x80801B4C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80801B4C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_2:
    // 0x80801B50: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801B54: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80801B58: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80801B5C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80801B60: bne         $s1, $s6, L_80801B14
    if (ctx->r17 != ctx->r22) {
        // 0x80801B64: swc1        $f0, -0x8($s0)
        MEM_W(-0X8, ctx->r16) = ctx->f0.u32l;
            goto L_80801B14;
    }
    // 0x80801B64: swc1        $f0, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80801B68: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80801B6C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80801B70: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80801B74: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80801B78: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80801B7C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80801B80: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80801B84: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80801B88: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80801B8C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80801B90: jr          $ra
    // 0x80801B94: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80801B94: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800070_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800078: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080007C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800080: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800084: jal         0x8008E40C
    // 0x80800088: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_8008E40C(rdram, ctx);
        goto after_0;
    // 0x80800088: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080008C: beq         $v0, $zero, L_8080009C
    if (ctx->r2 == 0) {
        // 0x80800090: nop
    
            goto L_8080009C;
    }
    // 0x80800090: nop

    // 0x80800094: b           L_808000CC
    // 0x80800098: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
        goto L_808000CC;
    // 0x80800098: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
L_8080009C:
    // 0x8080009C: jal         0x8008E3E8
    // 0x808000A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E3E8(rdram, ctx);
        goto after_1;
    // 0x808000A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808000A4: beq         $v0, $zero, L_808000B4
    if (ctx->r2 == 0) {
        // 0x808000A8: nop
    
            goto L_808000B4;
    }
    // 0x808000A8: nop

    // 0x808000AC: b           L_808000CC
    // 0x808000B0: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
        goto L_808000CC;
    // 0x808000B0: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
L_808000B4:
    // 0x808000B4: jal         0x8008E430
    // 0x808000B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E430(rdram, ctx);
        goto after_2;
    // 0x808000B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808000BC: beq         $v0, $zero, L_808000CC
    if (ctx->r2 == 0) {
        // 0x808000C0: lwc1        $f0, 0x1C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_808000CC;
    }
    // 0x808000C0: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808000C4: b           L_808000CC
    // 0x808000C8: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
        goto L_808000CC;
    // 0x808000C8: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
L_808000CC:
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D4: jr          $ra
    // 0x808000D8: nop

    return;
    // 0x808000D8: nop

;}
RECOMP_FUNC void func_80800C9C_cadbfunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CA4: jal         0x800A587C
    // 0x80800CA8: nop

    func_800A587C(rdram, ctx);
        goto after_0;
    // 0x80800CA8: nop

    after_0:
    // 0x80800CAC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80800CB0: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x80800CB4: beq         $at, $zero, L_80800D30
    if (ctx->r1 == 0) {
        // 0x80800CB8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800D30;
    }
    // 0x80800CB8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800CBC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(672, 0X1020) << 16);
    // 0x80800CC0: addu        $at, $at, $t6
    gpr jr_addend_80800CC8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800CC4: lw          $t6, 0x1020($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(672, 0X1020));
    // 0x80800CC8: jr          $t6
    // 0x80800CCC: nop

    switch (jr_addend_80800CC8 >> 2) {
        case 0: goto L_80800CF0; break;
        case 1: goto L_80800D30; break;
        case 2: goto L_80800CE0; break;
        case 3: goto L_80800CD0; break;
        case 4: goto L_80800D00; break;
        case 5: goto L_80800D10; break;
        case 6: goto L_80800D30; break;
        case 7: goto L_80800D20; break;
        default: switch_error(__func__, 0x80800CC8, 0x80801020);
    }
    // 0x80800CCC: nop

L_80800CD0:
    // 0x80800CD0: jal         0x800A586C
    // 0x80800CD4: nop

    func_800A586C(rdram, ctx);
        goto after_1;
    // 0x80800CD4: nop

    after_1:
    // 0x80800CD8: b           L_80800D34
    // 0x80800CDC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
        goto L_80800D34;
    // 0x80800CDC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80800CE0:
    // 0x80800CE0: jal         0x800A586C
    // 0x80800CE4: nop

    func_800A586C(rdram, ctx);
        goto after_2;
    // 0x80800CE4: nop

    after_2:
    // 0x80800CE8: b           L_80800D34
    // 0x80800CEC: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
        goto L_80800D34;
    // 0x80800CEC: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
L_80800CF0:
    // 0x80800CF0: jal         0x800A586C
    // 0x80800CF4: nop

    func_800A586C(rdram, ctx);
        goto after_3;
    // 0x80800CF4: nop

    after_3:
    // 0x80800CF8: b           L_80800D34
    // 0x80800CFC: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
        goto L_80800D34;
    // 0x80800CFC: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
L_80800D00:
    // 0x80800D00: jal         0x800A586C
    // 0x80800D04: nop

    func_800A586C(rdram, ctx);
        goto after_4;
    // 0x80800D04: nop

    after_4:
    // 0x80800D08: b           L_80800D34
    // 0x80800D0C: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
        goto L_80800D34;
    // 0x80800D0C: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
L_80800D10:
    // 0x80800D10: jal         0x800A586C
    // 0x80800D14: nop

    func_800A586C(rdram, ctx);
        goto after_5;
    // 0x80800D14: nop

    after_5:
    // 0x80800D18: b           L_80800D34
    // 0x80800D1C: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
        goto L_80800D34;
    // 0x80800D1C: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
L_80800D20:
    // 0x80800D20: jal         0x800A586C
    // 0x80800D24: nop

    func_800A586C(rdram, ctx);
        goto after_6;
    // 0x80800D24: nop

    after_6:
    // 0x80800D28: b           L_80800D34
    // 0x80800D2C: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
        goto L_80800D34;
    // 0x80800D2C: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
L_80800D30:
    // 0x80800D30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D34:
    // 0x80800D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D3C: jr          $ra
    // 0x80800D40: nop

    return;
    // 0x80800D40: nop

;}
RECOMP_FUNC void gldialog_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80800034: addiu       $v0, $v0, 0x7600
    ctx->r2 = ADD32(ctx->r2, 0X7600);
    // 0x80800038: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8080003C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80800040: jr          $ra
    // 0x80800044: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    return;
    // 0x80800044: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void _chnicecavemenguard_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086450: syscall     324
    recomp_syscall_handler(rdram, ctx, 0x80086450);
    return;
    // 0x80086454: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void cadbfunc_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080066C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800670: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800674: jal         0x808005B8
    // 0x80800678: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_808005B8_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800678: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8080067C: bne         $v0, $zero, L_8080068C
    if (ctx->r2 != 0) {
        // 0x80800680: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080068C;
    }
    // 0x80800680: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800684: b           L_80800698
    // 0x80800688: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800698;
    // 0x80800688: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080068C:
    // 0x8080068C: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800694: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
L_80800698:
    // 0x80800698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080069C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006A0: jr          $ra
    // 0x808006A4: nop

    return;
    // 0x808006A4: nop

;}
RECOMP_FUNC void gsproplookup_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080001C: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80800020: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2886, 0XF4) << 16);
    // 0x80800024: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x80800028: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8080002C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80800030: jr          $ra
    // 0x80800034: lh          $v0, 0xF4($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(2886, 0XF4));
    return;
    // 0x80800034: lh          $v0, 0xF4($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(2886, 0XF4));
    // 0x80800038: nop

    // 0x8080003C: nop

;}
RECOMP_FUNC void chballoonburst_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1008, 0X1C88) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x1C88
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1008, 0X1C88));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x1C88
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1008, 0X1C88));
;}
RECOMP_FUNC void _sufreezy_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B90: syscall     804
    recomp_syscall_handler(rdram, ctx, 0x80089B90);
    return;
    // 0x80089B94: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80028DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028DF0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80028DF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80028DF8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80028DFC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80028E00: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80028E04: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80028E08: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80028E0C: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x80028E10: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80028E14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80028E18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80028E1C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80028E20: jal         0x80020EE4
    // 0x80028E24: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_0;
    // 0x80028E24: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80028E28: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80028E2C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80028E30: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80028E34: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80028E38: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80028E3C: lh          $t0, 0x42($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X42);
    // 0x80028E40: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80028E44: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80028E48: lbu         $t2, 0x1C($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1C);
    // 0x80028E4C: bne         $t2, $at, L_80028E7C
    if (ctx->r10 != ctx->r1) {
        // 0x80028E50: nop
    
            goto L_80028E7C;
    }
    // 0x80028E50: nop

    // 0x80028E54: b           L_80028E5C
    // 0x80028E58: nop

        goto L_80028E5C;
    // 0x80028E58: nop

L_80028E5C:
    // 0x80028E5C: lh          $t4, 0x42($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X42);
    // 0x80028E60: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80028E64: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80028E68: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80028E6C: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x80028E70: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80028E74: b           L_80028E90
    // 0x80028E78: nop

        goto L_80028E90;
    // 0x80028E78: nop

L_80028E7C:
    // 0x80028E7C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80028E80: addiu       $t8, $t8, 0x1268
    ctx->r24 = ADD32(ctx->r24, 0X1268);
    // 0x80028E84: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80028E88: b           L_80028E90
    // 0x80028E8C: nop

        goto L_80028E90;
    // 0x80028E8C: nop

L_80028E90:
    // 0x80028E90: sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
    // 0x80028E94: lhu         $t0, 0x34($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X34);
    // 0x80028E98: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80028E9C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80028EA0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80028EA4: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80028EA8: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80028EAC: sb          $t4, 0x8($t3)
    MEM_B(0X8, ctx->r11) = ctx->r12;
    // 0x80028EB0: lhu         $t5, 0x34($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X34);
    // 0x80028EB4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80028EB8: sh          $t6, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r14;
    // 0x80028EBC: lhu         $t8, 0x34($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X34);
    // 0x80028EC0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80028EC4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80028EC8: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80028ECC: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x80028ED0: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80028ED4: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80028ED8: lhu         $t4, 0x34($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X34);
    // 0x80028EDC: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80028EE0: sh          $t3, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r11;
    // 0x80028EE4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80028EE8: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x80028EEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80028EF0: lbu         $a3, 0x8($t5)
    ctx->r7 = MEM_BU(ctx->r13, 0X8);
    // 0x80028EF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80028EF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80028EFC: jal         0x80020EE4
    // 0x80028F00: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_80020EE4(rdram, ctx);
        goto after_1;
    // 0x80028F00: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x80028F04: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80028F08: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x80028F0C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80028F10: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80028F14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80028F18: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    // 0x80028F1C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80028F20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80028F24: jal         0x80020EE4
    // 0x80028F28: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_80020EE4(rdram, ctx);
        goto after_2;
    // 0x80028F28: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x80028F2C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80028F30: sw          $v0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->r2;
    // 0x80028F34: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80028F38: lw          $t2, 0x20($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X20);
    // 0x80028F3C: sw          $t2, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r10;
    // 0x80028F40: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80028F44: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80028F48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80028F4C: lw          $a3, 0x0($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X0);
    // 0x80028F50: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80028F54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80028F58: jal         0x80020EE4
    // 0x80028F5C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_80020EE4(rdram, ctx);
        goto after_3;
    // 0x80028F5C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_3:
    // 0x80028F60: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80028F64: sw          $v0, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r2;
    // 0x80028F68: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80028F6C: lw          $t8, 0x24($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X24);
    // 0x80028F70: sw          $t8, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r24;
    // 0x80028F74: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80028F78: sh          $zero, 0x32($sp)
    MEM_H(0X32, ctx->r29) = 0;
    // 0x80028F7C: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x80028F80: beq         $t0, $zero, L_80028FE8
    if (ctx->r8 == 0) {
        // 0x80028F84: nop
    
            goto L_80028FE8;
    }
    // 0x80028F84: nop

L_80028F88:
    // 0x80028F88: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80028F8C: lhu         $t1, 0x32($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X32);
    // 0x80028F90: lw          $t2, 0x24($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X24);
    // 0x80028F94: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x80028F98: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x80028F9C: sh          $zero, 0x0($t3)
    MEM_H(0X0, ctx->r11) = 0;
    // 0x80028FA0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80028FA4: lhu         $t6, 0x32($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X32);
    // 0x80028FA8: lw          $t8, 0x24($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X24);
    // 0x80028FAC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80028FB0: lw          $t1, 0x20($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X20);
    // 0x80028FB4: addu        $t0, $t8, $t7
    ctx->r8 = ADD32(ctx->r24, ctx->r15);
    // 0x80028FB8: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x80028FBC: addu        $t2, $t1, $t7
    ctx->r10 = ADD32(ctx->r9, ctx->r15);
    // 0x80028FC0: sh          $t9, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r25;
    // 0x80028FC4: lhu         $t4, 0x32($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X32);
    // 0x80028FC8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80028FCC: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80028FD0: sh          $t3, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r11;
    // 0x80028FD4: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80028FD8: andi        $t6, $t3, 0xFFFF
    ctx->r14 = ctx->r11 & 0XFFFF;
    // 0x80028FDC: sltu        $at, $t6, $t0
    ctx->r1 = ctx->r14 < ctx->r8 ? 1 : 0;
    // 0x80028FE0: bne         $at, $zero, L_80028F88
    if (ctx->r1 != 0) {
        // 0x80028FE4: nop
    
            goto L_80028F88;
    }
    // 0x80028FE4: nop

L_80028FE8:
    // 0x80028FE8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80028FEC: sh          $zero, 0x36($sp)
    MEM_H(0X36, ctx->r29) = 0;
    // 0x80028FF0: lbu         $t1, 0x8($t5)
    ctx->r9 = MEM_BU(ctx->r13, 0X8);
    // 0x80028FF4: blez        $t1, L_8002939C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80028FF8: nop
    
            goto L_8002939C;
    }
    // 0x80028FF8: nop

L_80028FFC:
    // 0x80028FFC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80029000: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
    // 0x80029004: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80029008: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x8002900C: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x80029010: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80029014: addu        $t3, $t9, $t4
    ctx->r11 = ADD32(ctx->r25, ctx->r12);
    // 0x80029018: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8002901C: lhu         $t6, 0x34($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X34);
    // 0x80029020: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80029024: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80029028: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x8002902C: addu        $t5, $t8, $t0
    ctx->r13 = ADD32(ctx->r24, ctx->r8);
    // 0x80029030: lw          $t1, 0x0($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X0);
    // 0x80029034: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x80029038: lhu         $t2, 0x34($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X34);
    // 0x8002903C: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x80029040: sh          $t9, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r25;
    // 0x80029044: lhu         $t3, 0x34($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X34);
    // 0x80029048: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8002904C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80029050: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80029054: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x80029058: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8002905C: sw          $t0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r8;
    // 0x80029060: lhu         $t1, 0x34($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X34);
    // 0x80029064: addiu       $t7, $t1, 0x1
    ctx->r15 = ADD32(ctx->r9, 0X1);
    // 0x80029068: sh          $t7, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r15;
    // 0x8002906C: lhu         $t9, 0x34($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X34);
    // 0x80029070: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80029074: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80029078: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x8002907C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80029080: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80029084: sh          $t6, 0xA($t8)
    MEM_H(0XA, ctx->r24) = ctx->r14;
    // 0x80029088: lhu         $t0, 0x34($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X34);
    // 0x8002908C: addiu       $t5, $t0, 0x1
    ctx->r13 = ADD32(ctx->r8, 0X1);
    // 0x80029090: sh          $t5, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r13;
    // 0x80029094: lhu         $t7, 0x34($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X34);
    // 0x80029098: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8002909C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800290A0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800290A4: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x800290A8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800290AC: sh          $t3, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r11;
    // 0x800290B0: lhu         $t6, 0x34($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X34);
    // 0x800290B4: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800290B8: sh          $t8, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r24;
    // 0x800290BC: lhu         $t5, 0x34($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X34);
    // 0x800290C0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800290C4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800290C8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800290CC: addu        $t1, $t0, $t7
    ctx->r9 = ADD32(ctx->r8, ctx->r15);
    // 0x800290D0: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800290D4: sh          $t9, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r25;
    // 0x800290D8: lhu         $t3, 0x34($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X34);
    // 0x800290DC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800290E0: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x800290E4: lhu         $t8, 0x34($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X34);
    // 0x800290E8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800290EC: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x800290F0: addu        $t0, $t6, $t5
    ctx->r8 = ADD32(ctx->r14, ctx->r13);
    // 0x800290F4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800290F8: beq         $t7, $zero, L_80029274
    if (ctx->r15 == 0) {
        // 0x800290FC: nop
    
            goto L_80029274;
    }
    // 0x800290FC: nop

    // 0x80029100: lhu         $t9, 0x34($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X34);
    // 0x80029104: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80029108: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8002910C: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80029110: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80029114: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80029118: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002911C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80029120: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80029124: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80029128: lw          $t6, 0x18($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X18);
    // 0x8002912C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80029130: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80029134: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80029138: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8002913C: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80029140: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80029144: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80029148: div.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8002914C: swc1        $f8, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->f8.u32l;
    // 0x80029150: lhu         $t0, 0x34($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X34);
    // 0x80029154: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x80029158: sh          $t7, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r15;
    // 0x8002915C: lhu         $t1, 0x34($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X34);
    // 0x80029160: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80029164: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80029168: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8002916C: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80029170: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80029174: lw          $t6, 0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X4);
    // 0x80029178: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x8002917C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80029180: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80029184: subu        $t0, $t6, $t5
    ctx->r8 = SUB32(ctx->r14, ctx->r13);
    // 0x80029188: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002918C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80029190: lwc1        $f4, 0x1D28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1D28);
    // 0x80029194: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80029198: bgez        $t0, L_800291B0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8002919C: div.s       $f18, $f16, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
            goto L_800291B0;
    }
    // 0x8002919C: div.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800291A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800291A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800291A8: nop

    // 0x800291AC: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800291B0:
    // 0x800291B0: mul.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800291B4: swc1        $f16, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f16.u32l;
    // 0x800291B8: lhu         $t7, 0x34($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X34);
    // 0x800291BC: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x800291C0: sh          $t1, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r9;
    // 0x800291C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800291C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800291CC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800291D0: swc1        $f4, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f4.u32l;
    // 0x800291D4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800291D8: sw          $zero, 0x18($t2)
    MEM_W(0X18, ctx->r10) = 0;
    // 0x800291DC: addiu       $t3, $zero, 0x38
    ctx->r11 = ADD32(0, 0X38);
    // 0x800291E0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800291E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800291E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800291EC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800291F0: jal         0x80020EE4
    // 0x800291F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_4;
    // 0x800291F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x800291F8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800291FC: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    // 0x80029200: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80029204: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80029208: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002920C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80029210: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80029214: jal         0x80020EE4
    // 0x80029218: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_5;
    // 0x80029218: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x8002921C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80029220: lw          $t0, 0x24($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X24);
    // 0x80029224: sw          $v0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r2;
    // 0x80029228: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8002922C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80029230: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80029234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80029238: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8002923C: jal         0x80020EE4
    // 0x80029240: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_6;
    // 0x80029240: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x80029244: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80029248: lw          $t1, 0x24($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X24);
    // 0x8002924C: sw          $v0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r2;
    // 0x80029250: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80029254: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80029258: lw          $t2, 0x24($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X24);
    // 0x8002925C: swc1        $f6, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f6.u32l;
    // 0x80029260: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80029264: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80029268: lw          $t6, 0x24($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X24);
    // 0x8002926C: b           L_80029294
    // 0x80029270: sw          $t3, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r11;
        goto L_80029294;
    // 0x80029270: sw          $t3, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r11;
L_80029274:
    // 0x80029274: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80029278: sw          $zero, 0x24($t5)
    MEM_W(0X24, ctx->r13) = 0;
    // 0x8002927C: lhu         $t0, 0x34($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X34);
    // 0x80029280: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x80029284: sh          $t8, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r24;
    // 0x80029288: lhu         $t7, 0x34($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X34);
    // 0x8002928C: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x80029290: sh          $t1, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r9;
L_80029294:
    // 0x80029294: lhu         $t2, 0x34($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X34);
    // 0x80029298: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8002929C: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800292A0: addu        $t3, $t9, $t4
    ctx->r11 = ADD32(ctx->r25, ctx->r12);
    // 0x800292A4: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x800292A8: beq         $t6, $zero, L_80029364
    if (ctx->r14 == 0) {
        // 0x800292AC: nop
    
            goto L_80029364;
    }
    // 0x800292AC: nop

    // 0x800292B0: addiu       $t5, $zero, 0x38
    ctx->r13 = ADD32(0, 0X38);
    // 0x800292B4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800292B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800292BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800292C0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800292C4: jal         0x80020EE4
    // 0x800292C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_7;
    // 0x800292C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x800292CC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800292D0: sw          $v0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r2;
    // 0x800292D4: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x800292D8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800292DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800292E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800292E4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800292E8: jal         0x80020EE4
    // 0x800292EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_8;
    // 0x800292EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x800292F0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800292F4: lw          $t1, 0x20($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X20);
    // 0x800292F8: sw          $v0, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->r2;
    // 0x800292FC: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80029300: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80029304: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80029308: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002930C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80029310: jal         0x80020EE4
    // 0x80029314: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_9;
    // 0x80029314: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
    // 0x80029318: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8002931C: lw          $t4, 0x20($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X20);
    // 0x80029320: sw          $v0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r2;
    // 0x80029324: lhu         $t6, 0x34($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X34);
    // 0x80029328: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8002932C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80029330: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x80029334: addu        $t0, $t3, $t5
    ctx->r8 = ADD32(ctx->r11, ctx->r13);
    // 0x80029338: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8002933C: lw          $t1, 0x20($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X20);
    // 0x80029340: sh          $t8, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r24;
    // 0x80029344: lhu         $t2, 0x34($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X34);
    // 0x80029348: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x8002934C: sh          $t9, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r25;
    // 0x80029350: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80029354: jal         0x80028A24
    // 0x80029358: lw          $a0, 0x20($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X20);
    func_80028A24(rdram, ctx);
        goto after_10;
    // 0x80029358: lw          $a0, 0x20($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X20);
    after_10:
    // 0x8002935C: b           L_80029378
    // 0x80029360: nop

        goto L_80029378;
    // 0x80029360: nop

L_80029364:
    // 0x80029364: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80029368: sw          $zero, 0x20($t6)
    MEM_W(0X20, ctx->r14) = 0;
    // 0x8002936C: lhu         $t3, 0x34($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X34);
    // 0x80029370: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x80029374: sh          $t5, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r13;
L_80029378:
    // 0x80029378: lhu         $t0, 0x36($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X36);
    // 0x8002937C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80029380: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x80029384: sh          $t7, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r15;
    // 0x80029388: lbu         $t2, 0x8($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X8);
    // 0x8002938C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80029390: slt         $at, $t8, $t2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80029394: bne         $at, $zero, L_80028FFC
    if (ctx->r1 != 0) {
        // 0x80029398: nop
    
            goto L_80028FFC;
    }
    // 0x80029398: nop

L_8002939C:
    // 0x8002939C: b           L_800293A4
    // 0x800293A0: nop

        goto L_800293A4;
    // 0x800293A0: nop

L_800293A4:
    // 0x800293A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800293A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800293AC: jr          $ra
    // 0x800293B0: nop

    return;
    // 0x800293B0: nop

;}
RECOMP_FUNC void func_8080011C_chnewmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800124: jal         0x800DA298
    // 0x80800128: addiu       $a0, $zero, 0x9C5
    ctx->r4 = ADD32(0, 0X9C5);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800128: addiu       $a0, $zero, 0x9C5
    ctx->r4 = ADD32(0, 0X9C5);
    after_0:
    // 0x8080012C: bne         $v0, $zero, L_8080013C
    if (ctx->r2 != 0) {
        // 0x80800130: nop
    
            goto L_8080013C;
    }
    // 0x80800130: nop

    // 0x80800134: b           L_80800200
    // 0x80800138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800200;
    // 0x80800138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080013C:
    // 0x8080013C: jal         0x800EA05C
    // 0x80800140: nop

    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x80800140: nop

    after_1:
    // 0x80800144: slti        $at, $v0, 0x13F
    ctx->r1 = SIGNED(ctx->r2) < 0X13F ? 1 : 0;
    // 0x80800148: bne         $at, $zero, L_80800180
    if (ctx->r1 != 0) {
        // 0x8080014C: addiu       $at, $zero, 0x13F
        ctx->r1 = ADD32(0, 0X13F);
            goto L_80800180;
    }
    // 0x8080014C: addiu       $at, $zero, 0x13F
    ctx->r1 = ADD32(0, 0X13F);
    // 0x80800150: beq         $v0, $at, L_808001EC
    if (ctx->r2 == ctx->r1) {
        // 0x80800154: addiu       $at, $zero, 0x156
        ctx->r1 = ADD32(0, 0X156);
            goto L_808001EC;
    }
    // 0x80800154: addiu       $at, $zero, 0x156
    ctx->r1 = ADD32(0, 0X156);
    // 0x80800158: beq         $v0, $at, L_808001F4
    if (ctx->r2 == ctx->r1) {
        // 0x8080015C: addiu       $at, $zero, 0x171
        ctx->r1 = ADD32(0, 0X171);
            goto L_808001F4;
    }
    // 0x8080015C: addiu       $at, $zero, 0x171
    ctx->r1 = ADD32(0, 0X171);
    // 0x80800160: beq         $v0, $at, L_808001D4
    if (ctx->r2 == ctx->r1) {
        // 0x80800164: addiu       $at, $zero, 0x172
        ctx->r1 = ADD32(0, 0X172);
            goto L_808001D4;
    }
    // 0x80800164: addiu       $at, $zero, 0x172
    ctx->r1 = ADD32(0, 0X172);
    // 0x80800168: beq         $v0, $at, L_808001DC
    if (ctx->r2 == ctx->r1) {
        // 0x8080016C: addiu       $at, $zero, 0x176
        ctx->r1 = ADD32(0, 0X176);
            goto L_808001DC;
    }
    // 0x8080016C: addiu       $at, $zero, 0x176
    ctx->r1 = ADD32(0, 0X176);
    // 0x80800170: beq         $v0, $at, L_808001C4
    if (ctx->r2 == ctx->r1) {
        // 0x80800174: nop
    
            goto L_808001C4;
    }
    // 0x80800174: nop

    // 0x80800178: b           L_80800200
    // 0x8080017C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800200;
    // 0x8080017C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800180:
    // 0x80800180: addiu       $at, $zero, 0xB7
    ctx->r1 = ADD32(0, 0XB7);
    // 0x80800184: beq         $v0, $at, L_808001B4
    if (ctx->r2 == ctx->r1) {
        // 0x80800188: addiu       $at, $zero, 0xD9
        ctx->r1 = ADD32(0, 0XD9);
            goto L_808001B4;
    }
    // 0x80800188: addiu       $at, $zero, 0xD9
    ctx->r1 = ADD32(0, 0XD9);
    // 0x8080018C: beq         $v0, $at, L_808001BC
    if (ctx->r2 == ctx->r1) {
        // 0x80800190: addiu       $at, $zero, 0xEF
        ctx->r1 = ADD32(0, 0XEF);
            goto L_808001BC;
    }
    // 0x80800190: addiu       $at, $zero, 0xEF
    ctx->r1 = ADD32(0, 0XEF);
    // 0x80800194: beq         $v0, $at, L_808001CC
    if (ctx->r2 == ctx->r1) {
        // 0x80800198: addiu       $at, $zero, 0x134
        ctx->r1 = ADD32(0, 0X134);
            goto L_808001CC;
    }
    // 0x80800198: addiu       $at, $zero, 0x134
    ctx->r1 = ADD32(0, 0X134);
    // 0x8080019C: beq         $v0, $at, L_808001E4
    if (ctx->r2 == ctx->r1) {
        // 0x808001A0: addiu       $at, $zero, 0x13E
        ctx->r1 = ADD32(0, 0X13E);
            goto L_808001E4;
    }
    // 0x808001A0: addiu       $at, $zero, 0x13E
    ctx->r1 = ADD32(0, 0X13E);
    // 0x808001A4: beq         $v0, $at, L_808001EC
    if (ctx->r2 == ctx->r1) {
        // 0x808001A8: nop
    
            goto L_808001EC;
    }
    // 0x808001A8: nop

    // 0x808001AC: b           L_80800200
    // 0x808001B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800200;
    // 0x808001B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001B4:
    // 0x808001B4: b           L_80800200
    // 0x808001B8: addiu       $v0, $zero, 0x37F
    ctx->r2 = ADD32(0, 0X37F);
        goto L_80800200;
    // 0x808001B8: addiu       $v0, $zero, 0x37F
    ctx->r2 = ADD32(0, 0X37F);
L_808001BC:
    // 0x808001BC: b           L_80800200
    // 0x808001C0: addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
        goto L_80800200;
    // 0x808001C0: addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
L_808001C4:
    // 0x808001C4: b           L_80800200
    // 0x808001C8: addiu       $v0, $zero, 0x381
    ctx->r2 = ADD32(0, 0X381);
        goto L_80800200;
    // 0x808001C8: addiu       $v0, $zero, 0x381
    ctx->r2 = ADD32(0, 0X381);
L_808001CC:
    // 0x808001CC: b           L_80800200
    // 0x808001D0: addiu       $v0, $zero, 0x382
    ctx->r2 = ADD32(0, 0X382);
        goto L_80800200;
    // 0x808001D0: addiu       $v0, $zero, 0x382
    ctx->r2 = ADD32(0, 0X382);
L_808001D4:
    // 0x808001D4: b           L_80800200
    // 0x808001D8: addiu       $v0, $zero, 0x383
    ctx->r2 = ADD32(0, 0X383);
        goto L_80800200;
    // 0x808001D8: addiu       $v0, $zero, 0x383
    ctx->r2 = ADD32(0, 0X383);
L_808001DC:
    // 0x808001DC: b           L_80800200
    // 0x808001E0: addiu       $v0, $zero, 0x387
    ctx->r2 = ADD32(0, 0X387);
        goto L_80800200;
    // 0x808001E0: addiu       $v0, $zero, 0x387
    ctx->r2 = ADD32(0, 0X387);
L_808001E4:
    // 0x808001E4: b           L_80800200
    // 0x808001E8: addiu       $v0, $zero, 0x384
    ctx->r2 = ADD32(0, 0X384);
        goto L_80800200;
    // 0x808001E8: addiu       $v0, $zero, 0x384
    ctx->r2 = ADD32(0, 0X384);
L_808001EC:
    // 0x808001EC: b           L_80800200
    // 0x808001F0: addiu       $v0, $zero, 0x385
    ctx->r2 = ADD32(0, 0X385);
        goto L_80800200;
    // 0x808001F0: addiu       $v0, $zero, 0x385
    ctx->r2 = ADD32(0, 0X385);
L_808001F4:
    // 0x808001F4: b           L_80800200
    // 0x808001F8: addiu       $v0, $zero, 0x386
    ctx->r2 = ADD32(0, 0X386);
        goto L_80800200;
    // 0x808001F8: addiu       $v0, $zero, 0x386
    ctx->r2 = ADD32(0, 0X386);
    // 0x808001FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800200:
    // 0x80800200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800208: jr          $ra
    // 0x8080020C: nop

    return;
    // 0x8080020C: nop

;}
RECOMP_FUNC void func_80800E3C_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E44: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800E48: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1012, 0X1144) << 16);
    // 0x80800E4C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1012, 0X1154) << 16);
    // 0x80800E50: addiu       $a3, $a3, 0x1154
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1012, 0X1154));
    // 0x80800E54: addiu       $a2, $a2, 0x1144
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1012, 0X1144));
    // 0x80800E58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800E5C: jal         0x80089D28
    // 0x80800E60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800E60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800E64: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1012, 0X114C) << 16);
    // 0x80800E68: addiu       $a2, $a2, 0x114C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1012, 0X114C));
    // 0x80800E6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800E70: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E74: jal         0x80089D20
    // 0x80800E78: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800E78: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_1:
    // 0x80800E7C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1012, 0X114C) << 16);
    // 0x80800E80: lui         $a3, 0x3F5E
    ctx->r7 = S32(0X3F5E << 16);
    // 0x80800E84: ori         $a3, $a3, 0xB852
    ctx->r7 = ctx->r7 | 0XB852;
    // 0x80800E88: addiu       $a2, $a2, 0x114C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1012, 0X114C));
    // 0x80800E8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800E90: jal         0x80089D20
    // 0x80800E94: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800E94: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800EA0: jr          $ra
    // 0x80800EA4: nop

    return;
    // 0x80800EA4: nop

    // 0x80800EA8: nop

    // 0x80800EAC: nop

;}
