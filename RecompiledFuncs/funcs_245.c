#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void suflamefx_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080005C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800060: jal         0x80100074
    // 0x80800064: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x80800064: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080006C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void func_800CAF00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAF00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CAF04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CAF08: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x800CAF0C: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800CAF10: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800CAF14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800CAF18: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x800CAF1C: jal         0x800136E4
    // 0x800CAF20: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x800CAF20: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_0:
    // 0x800CAF24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CAF28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CAF2C: jr          $ra
    // 0x800CAF30: nop

    return;
    // 0x800CAF30: nop

;}
RECOMP_FUNC void func_808046C4_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808046C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808046C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808046CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808046D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808046D4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808046D8: jal         0x80100094
    // 0x808046DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808046DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808046E0: lbu         $t7, 0x64($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X64);
    // 0x808046E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808046E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808046EC: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x808046F0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808046F4: sb          $t8, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r24;
    // 0x808046F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808046FC: jal         0x8010A590
    // 0x80804700: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    func_8010A590(rdram, ctx);
        goto after_1;
    // 0x80804700: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x80804704: jal         0x800EA05C
    // 0x80804708: nop

    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x80804708: nop

    after_2:
    // 0x8080470C: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x80804710: beq         $v0, $at, L_80804764
    if (ctx->r2 == ctx->r1) {
        // 0x80804714: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_80804764;
    }
    // 0x80804714: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80804718: addiu       $at, $zero, 0xC6
    ctx->r1 = ADD32(0, 0XC6);
    // 0x8080471C: beq         $v0, $at, L_8080474C
    if (ctx->r2 == ctx->r1) {
        // 0x80804720: addiu       $at, $zero, 0xC8
        ctx->r1 = ADD32(0, 0XC8);
            goto L_8080474C;
    }
    // 0x80804720: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80804724: beq         $v0, $at, L_80804754
    if (ctx->r2 == ctx->r1) {
        // 0x80804728: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80804754;
    }
    // 0x80804728: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8080472C: addiu       $at, $zero, 0xC9
    ctx->r1 = ADD32(0, 0XC9);
    // 0x80804730: beq         $v0, $at, L_8080475C
    if (ctx->r2 == ctx->r1) {
        // 0x80804734: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_8080475C;
    }
    // 0x80804734: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80804738: addiu       $at, $zero, 0x17F
    ctx->r1 = ADD32(0, 0X17F);
    // 0x8080473C: beq         $v0, $at, L_8080476C
    if (ctx->r2 == ctx->r1) {
        // 0x80804740: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_8080476C;
    }
    // 0x80804740: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80804744: b           L_808047A8
    // 0x80804748: nop

        goto L_808047A8;
    // 0x80804748: nop

L_8080474C:
    // 0x8080474C: b           L_808047A8
    // 0x80804750: sb          $zero, 0x14($s1)
    MEM_B(0X14, ctx->r17) = 0;
        goto L_808047A8;
    // 0x80804750: sb          $zero, 0x14($s1)
    MEM_B(0X14, ctx->r17) = 0;
L_80804754:
    // 0x80804754: b           L_808047A8
    // 0x80804758: sb          $t9, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r25;
        goto L_808047A8;
    // 0x80804758: sb          $t9, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r25;
L_8080475C:
    // 0x8080475C: b           L_808047A8
    // 0x80804760: sb          $t0, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r8;
        goto L_808047A8;
    // 0x80804760: sb          $t0, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r8;
L_80804764:
    // 0x80804764: b           L_808047A8
    // 0x80804768: sb          $t1, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r9;
        goto L_808047A8;
    // 0x80804768: sb          $t1, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r9;
L_8080476C:
    // 0x8080476C: jal         0x80088368
    // 0x80804770: sb          $t2, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r10;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80804770: sb          $t2, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r10;
    after_3:
    // 0x80804774: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x80804778: andi        $t3, $v1, 0x1FF
    ctx->r11 = ctx->r3 & 0X1FF;
    // 0x8080477C: sltu        $at, $t3, $v0
    ctx->r1 = ctx->r11 < ctx->r2 ? 1 : 0;
    // 0x80804780: beq         $at, $zero, L_808047A8
    if (ctx->r1 == 0) {
        // 0x80804784: nop
    
            goto L_808047A8;
    }
    // 0x80804784: nop

    // 0x80804788: lbu         $t5, 0x64($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X64);
    // 0x8080478C: sll         $t8, $t3, 3
    ctx->r24 = S32(ctx->r11 << 3);
    // 0x80804790: andi        $t9, $t8, 0x18
    ctx->r25 = ctx->r24 & 0X18;
    // 0x80804794: ori         $t0, $t5, 0x20
    ctx->r8 = ctx->r13 | 0X20;
    // 0x80804798: andi        $t1, $t0, 0xE7
    ctx->r9 = ctx->r8 & 0XE7;
    // 0x8080479C: sb          $t0, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r8;
    // 0x808047A0: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x808047A4: sb          $t2, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r10;
L_808047A8:
    // 0x808047A8: jal         0x800BD0DC
    // 0x808047AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800BD0DC(rdram, ctx);
        goto after_4;
    // 0x808047AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x808047B0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x808047B4: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x808047B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808047BC: andi        $t3, $a1, 0x1FF
    ctx->r11 = ctx->r5 & 0X1FF;
    // 0x808047C0: jal         0x800BD268
    // 0x808047C4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800BD268(rdram, ctx);
        goto after_5;
    // 0x808047C4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_5:
    // 0x808047C8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x808047CC: jal         0x800BD28C
    // 0x808047D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800BD28C(rdram, ctx);
        goto after_6;
    // 0x808047D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808047D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808047D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808047DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808047E0: jr          $ra
    // 0x808047E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808047E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808013F8_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013F8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808013FC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801400: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801404: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801408: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8080140C: jal         0x8010262C
    // 0x80801410: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8010262C(rdram, ctx);
        goto after_0;
    // 0x80801410: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80801414: beq         $v0, $zero, L_808016A0
    if (ctx->r2 == 0) {
        // 0x80801418: sw          $v0, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r2;
            goto L_808016A0;
    }
    // 0x80801418: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x8080141C: jal         0x800D8FF8
    // 0x80801420: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80801420: nop

    after_1:
    // 0x80801424: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80801428: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x8080142C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801430: slti        $at, $t7, 0x7
    ctx->r1 = SIGNED(ctx->r15) < 0X7 ? 1 : 0;
    // 0x80801434: beql        $at, $zero, L_808016A4
    if (ctx->r1 == 0) {
        // 0x80801438: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808016A4;
    }
    goto skip_0;
    // 0x80801438: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080143C: jal         0x800F54E4
    // 0x80801440: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80801440: nop

    after_2:
    // 0x80801444: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801448: jal         0x800F5A00
    // 0x8080144C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x8080144C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_3:
    // 0x80801450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801454: jal         0x80801740
    // 0x80801458: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_80801740_chfantasyeyeball(rdram, ctx);
        goto after_4;
    // 0x80801458: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_4:
    // 0x8080145C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80801460: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80801464: jal         0x800F18FC
    // 0x80801468: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800F18FC(rdram, ctx);
        goto after_5;
    // 0x80801468: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_5:
    // 0x8080146C: lui         $at, 0x439B
    ctx->r1 = S32(0X439B << 16);
    // 0x80801470: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801474: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80801478: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080147C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80801480: nop

    // 0x80801484: bc1fl       L_808014B4
    if (!c1cs) {
        // 0x80801488: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_808014B4;
    }
    goto skip_1;
    // 0x80801488: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x8080148C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801490: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80801494: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x80801498: nop

    // 0x8080149C: bc1fl       L_808014B4
    if (!c1cs) {
        // 0x808014A0: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_808014B4;
    }
    goto skip_2;
    // 0x808014A0: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_2:
    // 0x808014A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808014A8: nop

    // 0x808014AC: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x808014B0: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_808014B4:
    // 0x808014B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808014B8: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808014BC: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x808014C0: beq         $t8, $at, L_808014D0
    if (ctx->r24 == ctx->r1) {
        // 0x808014C4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808014D0;
    }
    // 0x808014C4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808014C8: bne         $t8, $at, L_808014E8
    if (ctx->r24 != ctx->r1) {
        // 0x808014CC: lwc1        $f10, 0x4C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_808014E8;
    }
    // 0x808014CC: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
L_808014D0:
    // 0x808014D0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808014D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808014D8: jal         0x800136E4
    // 0x808014DC: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_6;
    // 0x808014DC: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_6:
    // 0x808014E0: b           L_808014FC
    // 0x808014E4: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
        goto L_808014FC;
    // 0x808014E4: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
L_808014E8:
    // 0x808014E8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808014EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808014F0: jal         0x800136E4
    // 0x808014F4: sub.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f10.fl;
    func_800136E4(rdram, ctx);
        goto after_7;
    // 0x808014F4: sub.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f10.fl;
    after_7:
    // 0x808014F8: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
L_808014FC:
    // 0x808014FC: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80801500: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801504: jal         0x800136E4
    // 0x80801508: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_8;
    // 0x80801508: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_8:
    // 0x8080150C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80801510: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80801514: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801518: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8080151C: add.s       $f2, $f18, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f18.fl;
    // 0x80801520: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80801524: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80801528: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8080152C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80801530: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80801534: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    // 0x80801538: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8080153C: jal         0x800F1FF0
    // 0x80801540: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_9;
    // 0x80801540: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x80801544: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80801548: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080154C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80801550: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80801554: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80801558: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080155C: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    // 0x80801560: jal         0x800F1FF0
    // 0x80801564: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_10;
    // 0x80801564: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x80801568: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x8080156C: jal         0x800E0ACC
    // 0x80801570: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    func_800E0ACC(rdram, ctx);
        goto after_11;
    // 0x80801570: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    after_11:
    // 0x80801574: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80801578: jal         0x800E0AF0
    // 0x8080157C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800E0AF0(rdram, ctx);
        goto after_12;
    // 0x8080157C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_12:
    // 0x80801580: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801584: lw          $a3, 0x50($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X50);
    // 0x80801588: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8080158C: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80801590: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x80801594: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80801598: jal         0x800E0AFC
    // 0x8080159C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_13;
    // 0x8080159C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x808015A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808015A4: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808015A8: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x808015AC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808015B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808015B4: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x808015B8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x808015BC: jal         0x800E0AFC
    // 0x808015C0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_14;
    // 0x808015C0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_14:
    // 0x808015C4: jal         0x800D90A4
    // 0x808015C8: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    func_800D90A4(rdram, ctx);
        goto after_15;
    // 0x808015C8: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    after_15:
    // 0x808015CC: bne         $v0, $zero, L_808016A0
    if (ctx->r2 != 0) {
        // 0x808015D0: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_808016A0;
    }
    // 0x808015D0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808015D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808015D8: lwc1        $f12, 0x30($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808015DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808015E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808015E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808015E8: jal         0x800F10B4
    // 0x808015EC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_16;
    // 0x808015EC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_16:
    // 0x808015F0: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x808015F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808015F8: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x808015FC: mul.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80801600: jal         0x80013970
    // 0x80801604: nop

    func_80013970(rdram, ctx);
        goto after_17;
    // 0x80801604: nop

    after_17:
    // 0x80801608: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2400, 0X1E20) << 16);
    // 0x8080160C: lwc1        $f8, 0x1E20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2400, 0X1E20));
    // 0x80801610: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80801614: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80801618: mul.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8080161C: jal         0x80013970
    // 0x80801620: nop

    func_80013970(rdram, ctx);
        goto after_18;
    // 0x80801620: nop

    after_18:
    // 0x80801624: lui         $at, 0x4487
    ctx->r1 = S32(0X4487 << 16);
    // 0x80801628: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080162C: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80801630: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80801634: mul.s       $f12, $f10, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80801638: jal         0x80013970
    // 0x8080163C: nop

    func_80013970(rdram, ctx);
        goto after_19;
    // 0x8080163C: nop

    after_19:
    // 0x80801640: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80801644: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80801648: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080164C: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80801650: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801654: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80801658: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080165C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801660: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80801664: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801668: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x8080166C: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80801670: nop

    // 0x80801674: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80801678: add.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8080167C: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80801680: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80801684: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80801688: add.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8080168C: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80801690: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80801694: add.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80801698: jal         0x800E0B8C
    // 0x8080169C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_20;
    // 0x8080169C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_20:
L_808016A0:
    // 0x808016A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808016A4:
    // 0x808016A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808016A8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x808016AC: jr          $ra
    // 0x808016B0: nop

    return;
    // 0x808016B0: nop

;}
RECOMP_FUNC void gcintrotext_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800054: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080005C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800060: bne         $a0, $at, L_80800074
    if (ctx->r4 != ctx->r1) {
        // 0x80800064: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800074;
    }
    // 0x80800064: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800068: jal         0x800EA05C
    // 0x8080006C: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080006C: nop

    after_0:
    // 0x80800070: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80800074:
    // 0x80800074: jal         0x808000C8
    // 0x80800078: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808000C8_gcintrotext(rdram, ctx);
        goto after_1;
    // 0x80800078: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8080007C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800080: bne         $v0, $zero, L_80800090
    if (ctx->r2 != 0) {
        // 0x80800084: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800090;
    }
    // 0x80800084: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800088: b           L_808000B8
    // 0x8080008C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_808000B8;
    // 0x8080008C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800090:
    // 0x80800090: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80800094: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800098: sll         $t7, $t6, 10
    ctx->r15 = S32(ctx->r14 << 10);
    // 0x8080009C: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x808000A0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x808000A4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x808000A8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x808000AC: andi        $t1, $t0, 0x3F
    ctx->r9 = ctx->r8 & 0X3F;
    // 0x808000B0: jal         0x808001AC
    // 0x808000B4: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    func_808001AC_gcintrotext(rdram, ctx);
        goto after_2;
    // 0x808000B4: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    after_2:
L_808000B8:
    // 0x808000B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000C0: jr          $ra
    // 0x808000C4: nop

    return;
    // 0x808000C4: nop

;}
RECOMP_FUNC void gccollectDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080017C: jr          $ra
    // 0x80800180: nop

    return;
    // 0x80800180: nop

;}
RECOMP_FUNC void func_800FE914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE914: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800FE918: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800FE91C: lh          $a2, 0x59CA($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X59CA);
    // 0x800FE920: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800FE924: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800FE928: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FE92C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800FE930: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800FE934: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FE938: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800FE93C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800FE940: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800FE944: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800FE948: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800FE94C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800FE950: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800FE954: addiu       $t0, $t0, 0x42DC
    ctx->r8 = ADD32(ctx->r8, 0X42DC);
    // 0x800FE958: addiu       $a1, $a1, 0x5A10
    ctx->r5 = ADD32(ctx->r5, 0X5A10);
    // 0x800FE95C: addiu       $s0, $s0, 0x5A0C
    ctx->r16 = ADD32(ctx->r16, 0X5A0C);
    // 0x800FE960: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800FE964: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800FE968: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    // 0x800FE96C: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
L_800FE970:
    // 0x800FE970: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800FE974: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800FE978: addiu       $t8, $t8, 0x4314
    ctx->r24 = ADD32(ctx->r24, 0X4314);
    // 0x800FE97C: beq         $t6, $zero, L_800FEA1C
    if (ctx->r14 == 0) {
        // 0x800FE980: sll         $t7, $v1, 3
        ctx->r15 = S32(ctx->r3 << 3);
            goto L_800FEA1C;
    }
    // 0x800FE980: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x800FE984: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800FE988: bne         $v1, $s4, L_800FE9D0
    if (ctx->r3 != ctx->r20) {
        // 0x800FE98C: lwc1        $f12, 0x0($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
            goto L_800FE9D0;
    }
    // 0x800FE98C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800FE990: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800FE994: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE998: lwc1        $f8, 0x59F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X59F0);
    // 0x800FE99C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800FE9A0: mtc1        $s3, $f10
    ctx->f10.u32l = ctx->r19;
    // 0x800FE9A4: nop

    // 0x800FE9A8: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800FE9AC: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800FE9B0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FE9B4: nop

    // 0x800FE9B8: bc1fl       L_800FE9F0
    if (!c1cs) {
        // 0x800FE9BC: lwc1        $f0, 0x0($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
            goto L_800FE9F0;
    }
    goto skip_0;
    // 0x800FE9BC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800FE9C0: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800FE9C4: mfc1        $s3, $f16
    ctx->r19 = (int32_t)ctx->f16.u32l;
    // 0x800FE9C8: b           L_800FE9F0
    // 0x800FE9CC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
        goto L_800FE9F0;
    // 0x800FE9CC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
L_800FE9D0:
    // 0x800FE9D0: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800FE9D4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800FE9D8: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800FE9DC: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800FE9E0: beql        $at, $zero, L_800FE9F0
    if (ctx->r1 == 0) {
        // 0x800FE9E4: lwc1        $f0, 0x0($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
            goto L_800FE9F0;
    }
    goto skip_1;
    // 0x800FE9E4: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    skip_1:
    // 0x800FE9E8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800FE9EC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
L_800FE9F0:
    // 0x800FE9F0: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800FE9F4: nop

    // 0x800FE9F8: bc1fl       L_800FEA08
    if (!c1cs) {
        // 0x800FE9FC: lwc1        $f0, 0x4($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
            goto L_800FEA08;
    }
    goto skip_2;
    // 0x800FE9FC: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    skip_2:
    // 0x800FEA00: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800FEA04: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
L_800FEA08:
    // 0x800FEA08: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800FEA0C: nop

    // 0x800FEA10: bc1fl       L_800FEA20
    if (!c1cs) {
        // 0x800FEA14: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800FEA20;
    }
    goto skip_3;
    // 0x800FEA14: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_3:
    // 0x800FEA18: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_800FEA1C:
    // 0x800FEA1C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800FEA20:
    // 0x800FEA20: bne         $v1, $a3, L_800FE970
    if (ctx->r3 != ctx->r7) {
        // 0x800FEA24: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800FE970;
    }
    // 0x800FEA24: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800FEA28: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FEA2C: lh          $v0, 0x59E4($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X59E4);
    // 0x800FEA30: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800FEA34: addiu       $s1, $s1, 0x3E60
    ctx->r17 = ADD32(ctx->r17, 0X3E60);
    // 0x800FEA38: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800FEA3C: beq         $at, $zero, L_800FEA48
    if (ctx->r1 == 0) {
        // 0x800FEA40: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800FEA48;
    }
    // 0x800FEA40: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FEA44: lwc1        $f20, 0x0($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X0);
L_800FEA48:
    // 0x800FEA48: bne         $s3, $v0, L_800FEA5C
    if (ctx->r19 != ctx->r2) {
        // 0x800FEA4C: nop
    
            goto L_800FEA5C;
    }
    // 0x800FEA4C: nop

    // 0x800FEA50: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800FEA54: beq         $t3, $zero, L_800FEAF0
    if (ctx->r11 == 0) {
        // 0x800FEA58: nop
    
            goto L_800FEAF0;
    }
    // 0x800FEA58: nop

L_800FEA5C:
    // 0x800FEA5C: lh          $a0, 0x59C8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X59C8);
    // 0x800FEA60: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800FEA64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FEA68: beq         $a0, $at, L_800FEAE4
    if (ctx->r4 == ctx->r1) {
        // 0x800FEA6C: addiu       $s1, $s1, 0x3E60
        ctx->r17 = ADD32(ctx->r17, 0X3E60);
            goto L_800FEAE4;
    }
    // 0x800FEA6C: addiu       $s1, $s1, 0x3E60
    ctx->r17 = ADD32(ctx->r17, 0X3E60);
    // 0x800FEA70: jal         0x800FCCD4
    // 0x800FEA74: nop

    func_800FCCD4(rdram, ctx);
        goto after_0;
    // 0x800FEA74: nop

    after_0:
    // 0x800FEA78: bne         $v0, $zero, L_800FEA98
    if (ctx->r2 != 0) {
        // 0x800FEA7C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800FEA98;
    }
    // 0x800FEA7C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FEA80: jal         0x80017764
    // 0x800FEA84: lh          $a0, 0x59C8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X59C8);
    func_80017764(rdram, ctx);
        goto after_1;
    // 0x800FEA84: lh          $a0, 0x59C8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X59C8);
    after_1:
    // 0x800FEA88: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FEA8C: lh          $a0, 0x59C8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X59C8);
    // 0x800FEA90: jal         0x800FC688
    // 0x800FEA94: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800FC688(rdram, ctx);
        goto after_2;
    // 0x800FEA94: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
L_800FEA98:
    // 0x800FEA98: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800FEA9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FEAA0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800FEAA4: beq         $t4, $zero, L_800FEAB8
    if (ctx->r12 == 0) {
        // 0x800FEAA8: or          $a2, $s3, $zero
        ctx->r6 = ctx->r19 | 0;
            goto L_800FEAB8;
    }
    // 0x800FEAA8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800FEAAC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800FEAB0: b           L_800FEAC0
    // 0x800FEAB4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
        goto L_800FEAC0;
    // 0x800FEAB4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
L_800FEAB8:
    // 0x800FEAB8: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x800FEABC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
L_800FEAC0:
    // 0x800FEAC0: jal         0x800FC4B0
    // 0x800FEAC4: lh          $a0, 0x59C8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X59C8);
    func_800FC4B0(rdram, ctx);
        goto after_3;
    // 0x800FEAC4: lh          $a0, 0x59C8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X59C8);
    after_3:
    // 0x800FEAC8: beq         $v0, $zero, L_800FEAE4
    if (ctx->r2 == 0) {
        // 0x800FEACC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800FEAE4;
    }
    // 0x800FEACC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800FEAD0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FEAD4: lh          $a0, 0x59C8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X59C8);
    // 0x800FEAD8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800FEADC: jal         0x800FCB00
    // 0x800FEAE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800FCB00(rdram, ctx);
        goto after_4;
    // 0x800FEAE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
L_800FEAE4:
    // 0x800FEAE4: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x800FEAE8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FEAEC: lh          $v0, 0x59E4($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X59E4);
L_800FEAF0:
    // 0x800FEAF0: bne         $s3, $v0, L_800FEB0C
    if (ctx->r19 != ctx->r2) {
        // 0x800FEAF4: lui         $t5, 0x8013
        ctx->r13 = S32(0X8013 << 16);
            goto L_800FEB0C;
    }
    // 0x800FEAF4: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800FEAF8: lbu         $t5, 0x59D5($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X59D5);
    // 0x800FEAFC: bne         $t5, $zero, L_800FEB0C
    if (ctx->r13 != 0) {
        // 0x800FEB00: nop
    
            goto L_800FEB0C;
    }
    // 0x800FEB00: nop

    // 0x800FEB04: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800FEB08: beq         $t6, $zero, L_800FEBF0
    if (ctx->r14 == 0) {
        // 0x800FEB0C: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800FEBF0;
    }
L_800FEB0C:
    // 0x800FEB0C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800FEB10: lw          $t7, 0x5A40($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5A40);
    // 0x800FEB14: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800FEB18: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800FEB1C: blezl       $t7, L_800FEBE0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800FEB20: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_800FEBE0;
    }
    goto skip_4;
    // 0x800FEB20: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_4:
    // 0x800FEB24: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FEB28: addiu       $s0, $s0, 0x5A20
    ctx->r16 = ADD32(ctx->r16, 0X5A20);
L_800FEB2C:
    // 0x800FEB2C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800FEB30: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FEB34: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x800FEB38: beql        $a0, $zero, L_800FEBC8
    if (ctx->r4 == 0) {
        // 0x800FEB3C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FEBC8;
    }
    goto skip_5;
    // 0x800FEB3C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x800FEB40: lbu         $t8, 0x5A3C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X5A3C);
    // 0x800FEB44: beql        $t8, $zero, L_800FEBC8
    if (ctx->r24 == 0) {
        // 0x800FEB48: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FEBC8;
    }
    goto skip_6;
    // 0x800FEB48: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_6:
    // 0x800FEB4C: jal         0x800FCCD4
    // 0x800FEB50: nop

    func_800FCCD4(rdram, ctx);
        goto after_5;
    // 0x800FEB50: nop

    after_5:
    // 0x800FEB54: beq         $v0, $zero, L_800FEBC4
    if (ctx->r2 == 0) {
        // 0x800FEB58: lw          $t9, 0x38($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X38);
            goto L_800FEBC4;
    }
    // 0x800FEB58: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800FEB5C: beq         $t9, $zero, L_800FEB70
    if (ctx->r25 == 0) {
        // 0x800FEB60: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_800FEB70;
    }
    // 0x800FEB60: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800FEB64: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800FEB68: b           L_800FEBA0
    // 0x800FEB6C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
        goto L_800FEBA0;
    // 0x800FEB6C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
L_800FEB70:
    // 0x800FEB70: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FEB74: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x800FEB78: lwc1        $f0, 0x5A30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A30);
    // 0x800FEB7C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800FEB80: nop

    // 0x800FEB84: bc1fl       L_800FEB98
    if (!c1cs) {
        // 0x800FEB88: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800FEB98;
    }
    goto skip_7;
    // 0x800FEB88: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_7:
    // 0x800FEB8C: b           L_800FEB98
    // 0x800FEB90: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
        goto L_800FEB98;
    // 0x800FEB90: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x800FEB94: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800FEB98:
    // 0x800FEB98: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x800FEB9C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
L_800FEBA0:
    // 0x800FEBA0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800FEBA4: jal         0x800FC4B0
    // 0x800FEBA8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800FC4B0(rdram, ctx);
        goto after_6;
    // 0x800FEBA8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_6:
    // 0x800FEBAC: beq         $v0, $zero, L_800FEBC4
    if (ctx->r2 == 0) {
        // 0x800FEBB0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800FEBC4;
    }
    // 0x800FEBB0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800FEBB4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800FEBB8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800FEBBC: jal         0x800FCB00
    // 0x800FEBC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800FCB00(rdram, ctx);
        goto after_7;
    // 0x800FEBC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_800FEBC4:
    // 0x800FEBC4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800FEBC8:
    // 0x800FEBC8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800FEBCC: bne         $s1, $s4, L_800FEB2C
    if (ctx->r17 != ctx->r20) {
        // 0x800FEBD0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800FEB2C;
    }
    // 0x800FEBD0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800FEBD4: b           L_800FEBE8
    // 0x800FEBD8: nop

        goto L_800FEBE8;
    // 0x800FEBD8: nop

    // 0x800FEBDC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_800FEBE0:
    // 0x800FEBE0: nop

    // 0x800FEBE4: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
L_800FEBE8:
    // 0x800FEBE8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FEBEC: sb          $zero, 0x59D5($at)
    MEM_B(0X59D5, ctx->r1) = 0;
L_800FEBF0:
    // 0x800FEBF0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800FEBF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FEBF8: sh          $s3, 0x59E4($at)
    MEM_H(0X59E4, ctx->r1) = ctx->r19;
    // 0x800FEBFC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800FEC00: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800FEC04: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800FEC08: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800FEC0C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800FEC10: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800FEC14: jr          $ra
    // 0x800FEC18: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800FEC18: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80115610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115610: jr          $ra
    // 0x80115614: addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
    return;
    // 0x80115614: addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_808002F8_cadbfunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800300: jal         0x800A587C
    // 0x80800304: nop

    func_800A587C(rdram, ctx);
        goto after_0;
    // 0x80800304: nop

    after_0:
    // 0x80800308: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080030C: beq         $v0, $at, L_80800324
    if (ctx->r2 == ctx->r1) {
        // 0x80800310: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800324;
    }
    // 0x80800310: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800314: beq         $v0, $at, L_80800334
    if (ctx->r2 == ctx->r1) {
        // 0x80800318: nop
    
            goto L_80800334;
    }
    // 0x80800318: nop

    // 0x8080031C: b           L_80800344
    // 0x80800320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800344;
    // 0x80800320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800324:
    // 0x80800324: jal         0x800A586C
    // 0x80800328: nop

    func_800A586C(rdram, ctx);
        goto after_1;
    // 0x80800328: nop

    after_1:
    // 0x8080032C: b           L_80800344
    // 0x80800330: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
        goto L_80800344;
    // 0x80800330: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_80800334:
    // 0x80800334: jal         0x800A586C
    // 0x80800338: nop

    func_800A586C(rdram, ctx);
        goto after_2;
    // 0x80800338: nop

    after_2:
    // 0x8080033C: b           L_80800344
    // 0x80800340: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
        goto L_80800344;
    // 0x80800340: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_80800344:
    // 0x80800344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800348: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080034C: jr          $ra
    // 0x80800350: nop

    return;
    // 0x80800350: nop

;}
RECOMP_FUNC void func_80801844_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801844: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801848: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080184C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801850: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801854: jal         0x8009D3A8
    // 0x80801858: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_0;
    // 0x80801858: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080185C: jal         0x808005DC
    // 0x80801860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bstrexsmall_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80801860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801864: lui         $a1, 0x3DC2
    ctx->r5 = S32(0X3DC2 << 16);
    // 0x80801868: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x8080186C: jal         0x8008CB10
    // 0x80801870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x80801870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801874: beq         $v0, $zero, L_80801890
    if (ctx->r2 == 0) {
        // 0x80801878: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801890;
    }
    // 0x80801878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080187C: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80801880: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801884: addiu       $a1, $zero, 0x570
    ctx->r5 = ADD32(0, 0X570);
    // 0x80801888: jal         0x8009DF18
    // 0x8080188C: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_3;
    // 0x8080188C: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_3:
L_80801890:
    // 0x80801890: lui         $a1, 0x3F0B
    ctx->r5 = S32(0X3F0B << 16);
    // 0x80801894: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x80801898: jal         0x8008CB10
    // 0x8080189C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x8080189C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808018A0: beq         $v0, $zero, L_808018D0
    if (ctx->r2 == 0) {
        // 0x808018A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808018D0;
    }
    // 0x808018A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018A8: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x808018AC: lui         $a3, 0x3FB3
    ctx->r7 = S32(0X3FB3 << 16);
    // 0x808018B0: addiu       $t6, $zero, 0x4E20
    ctx->r14 = ADD32(0, 0X4E20);
    // 0x808018B4: addiu       $t7, $zero, 0x55F0
    ctx->r15 = ADD32(0, 0X55F0);
    // 0x808018B8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808018BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808018C0: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x808018C4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808018C8: jal         0x8009DEC0
    // 0x808018CC: addiu       $a1, $zero, 0x56F
    ctx->r5 = ADD32(0, 0X56F);
    func_8009DEC0(rdram, ctx);
        goto after_5;
    // 0x808018CC: addiu       $a1, $zero, 0x56F
    ctx->r5 = ADD32(0, 0X56F);
    after_5:
L_808018D0:
    // 0x808018D0: lui         $a1, 0x3F51
    ctx->r5 = S32(0X3F51 << 16);
    // 0x808018D4: ori         $a1, $a1, 0xEB85
    ctx->r5 = ctx->r5 | 0XEB85;
    // 0x808018D8: jal         0x8008CB10
    // 0x808018DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_6;
    // 0x808018DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808018E0: beq         $v0, $zero, L_808018FC
    if (ctx->r2 == 0) {
        // 0x808018E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808018FC;
    }
    // 0x808018E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018E8: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x808018EC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808018F0: addiu       $a1, $zero, 0x570
    ctx->r5 = ADD32(0, 0X570);
    // 0x808018F4: jal         0x8009DF18
    // 0x808018F8: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    func_8009DF18(rdram, ctx);
        goto after_7;
    // 0x808018F8: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    after_7:
L_808018FC:
    // 0x808018FC: lui         $a1, 0x3F6B
    ctx->r5 = S32(0X3F6B << 16);
    // 0x80801900: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x80801904: jal         0x8008CB10
    // 0x80801908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_8;
    // 0x80801908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080190C: beq         $v0, $zero, L_80801928
    if (ctx->r2 == 0) {
        // 0x80801910: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801928;
    }
    // 0x80801910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801914: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x80801918: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x8080191C: addiu       $a1, $zero, 0x570
    ctx->r5 = ADD32(0, 0X570);
    // 0x80801920: jal         0x8009DF18
    // 0x80801924: addiu       $a3, $zero, 0x32C8
    ctx->r7 = ADD32(0, 0X32C8);
    func_8009DF18(rdram, ctx);
        goto after_9;
    // 0x80801924: addiu       $a3, $zero, 0x32C8
    ctx->r7 = ADD32(0, 0X32C8);
    after_9:
L_80801928:
    // 0x80801928: jal         0x808002B8
    // 0x8080192C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002B8_bstrexsmall(rdram, ctx);
        goto after_10;
    // 0x8080192C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801934: jal         0x8080020C
    // 0x80801938: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080020C_bstrexsmall(rdram, ctx);
        goto after_11;
    // 0x80801938: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x8080193C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801940: jal         0x8009E5C8
    // 0x80801944: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_12;
    // 0x80801944: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_12:
    // 0x80801948: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080194C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801950: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801954: jr          $ra
    // 0x80801958: nop

    return;
    // 0x80801958: nop

;}
RECOMP_FUNC void _gcmapsects_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087FA8: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087FA8);
    return;
    // 0x80087FAC: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void bawasher_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800010: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800014: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x80800018: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x8080001C: lw          $t7, 0x14C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14C);
    // 0x80800020: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x80800024: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x80800028: swc1        $f0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f0.u32l;
    // 0x8080002C: lw          $t9, 0x14C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14C);
    // 0x80800030: jr          $ra
    // 0x80800034: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    return;
    // 0x80800034: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_808006B8_chspotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808006C4: jal         0x80100094
    // 0x808006C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006CC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x808006D0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808006D4: beql        $t6, $zero, L_80800724
    if (ctx->r14 == 0) {
        // 0x808006D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800724;
    }
    goto skip_0;
    // 0x808006D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808006DC: lw          $a0, 0x3C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X3C);
    // 0x808006E0: jal         0x80106790
    // 0x808006E4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808006E4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x808006E8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1004, 0X990) << 16);
    // 0x808006EC: addiu       $a2, $a2, 0x990
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1004, 0X990));
    // 0x808006F0: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x808006F4: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x808006F8: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x808006FC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800700: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800704: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800708: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8080070C: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80800710: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800714: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80800718: jal         0x800C8D4C
    // 0x8080071C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    func_800C8D4C(rdram, ctx);
        goto after_2;
    // 0x8080071C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    after_2:
    // 0x80800720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800724:
    // 0x80800724: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800728: jr          $ra
    // 0x8080072C: nop

    return;
    // 0x8080072C: nop

;}
RECOMP_FUNC void chbaddiesetup_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080003C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800040: jal         0x800A5D60
    // 0x80800044: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800A5D60(rdram, ctx);
        goto after_0;
    // 0x80800044: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080004C: jal         0x80800000
    // 0x80800050: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80800000_chbaddiesetup(rdram, ctx);
        goto after_1;
    // 0x80800050: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800054: beq         $v0, $zero, L_80800094
    if (ctx->r2 == 0) {
        // 0x80800058: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800094;
    }
    // 0x80800058: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080005C: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x80800060: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80800064: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800068: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x8080006C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80800070: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80800074: lbu         $t2, 0x4($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X4);
    // 0x80800078: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8080007C: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x80800080: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80800084: sw          $zero, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = 0;
    // 0x80800088: lbu         $t5, 0x4($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X4);
    // 0x8080008C: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x80800090: sb          $t8, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r24;
L_80800094:
    // 0x80800094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800098: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080009C: jr          $ra
    // 0x808000A0: nop

    return;
    // 0x808000A0: nop

;}
RECOMP_FUNC void func_80800F60_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F60: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800F64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F68: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800F6C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800F70: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800F74: jal         0x800EE7F8
    // 0x80800F78: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800F78: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80800F7C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800F80: jal         0x800EE7F8
    // 0x80800F84: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800F84: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x80800F88: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800F8C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800F90: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800F94: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800F98: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80800F9C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800FA0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800FA4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800FA8: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800FAC: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80800FB0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80800FB4: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80800FB8: jal         0x800BEF00
    // 0x80800FBC: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_2;
    // 0x80800FBC: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    after_2:
    // 0x80800FC0: beq         $v0, $zero, L_80800FE8
    if (ctx->r2 == 0) {
        // 0x80800FC4: lwc1        $f16, 0x2C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_80800FE8;
    }
    // 0x80800FC4: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800FC8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80800FCC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800FD0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800FD4: swc1        $f16, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f16.u32l;
    // 0x80800FD8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80800FDC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800FE0: jal         0x800F1B78
    // 0x80800FE4: lw          $a2, 0x48($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X48);
    func_800F1B78(rdram, ctx);
        goto after_3;
    // 0x80800FE4: lw          $a2, 0x48($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X48);
    after_3:
L_80800FE8:
    // 0x80800FE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FEC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800FF0: jr          $ra
    // 0x80800FF4: nop

    return;
    // 0x80800FF4: nop

;}
RECOMP_FUNC void _ncbaspline_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800893B8: syscall     776
    recomp_syscall_handler(rdram, ctx, 0x800893B8);
    return;
    // 0x800893BC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800A5DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5DB0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800A5DB4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A5DB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A5DBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A5DC0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800A5DC4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800A5DC8: jal         0x800EE7F8
    // 0x800A5DCC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800A5DCC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_0:
    // 0x800A5DD0: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800A5DD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A5DD8: lwc1        $f6, 0x55D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X55D0);
    // 0x800A5DDC: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800A5DE0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800A5DE4: lui         $a3, 0x3EDC
    ctx->r7 = S32(0X3EDC << 16);
    // 0x800A5DE8: ori         $a3, $a3, 0x28F6
    ctx->r7 = ctx->r7 | 0X28F6;
    // 0x800A5DEC: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x800A5DF0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800A5DF4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800A5DF8: jal         0x800F10B4
    // 0x800A5DFC: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x800A5DFC: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    after_1:
    // 0x800A5E00: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800A5E04: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x800A5E08: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x800A5E0C: jal         0x800F554C
    // 0x800A5E10: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800F554C(rdram, ctx);
        goto after_2;
    // 0x800A5E10: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_2:
    // 0x800A5E14: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A5E18: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800A5E1C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A5E20: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800A5E24: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A5E28: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x800A5E2C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800A5E30: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x800A5E34: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x800A5E38: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x800A5E3C: jal         0x800F5680
    // 0x800A5E40: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800F5680(rdram, ctx);
        goto after_3;
    // 0x800A5E40: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_3:
    // 0x800A5E44: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800A5E48: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x800A5E4C: jal         0x800F1988
    // 0x800A5E50: addiu       $a2, $s0, 0x48
    ctx->r6 = ADD32(ctx->r16, 0X48);
    func_800F1988(rdram, ctx);
        goto after_4;
    // 0x800A5E50: addiu       $a2, $s0, 0x48
    ctx->r6 = ADD32(ctx->r16, 0X48);
    after_4:
    // 0x800A5E54: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800A5E58: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800A5E5C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800A5E60: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x800A5E64: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800A5E68: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800A5E6C: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800A5E70: jal         0x800EF334
    // 0x800A5E74: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    func_800EF334(rdram, ctx);
        goto after_5;
    // 0x800A5E74: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x800A5E78: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A5E7C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800A5E80: jal         0x800EE780
    // 0x800A5E84: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_800EE780(rdram, ctx);
        goto after_6;
    // 0x800A5E84: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_6:
    // 0x800A5E88: jal         0x800DF830
    // 0x800A5E8C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF830(rdram, ctx);
        goto after_7;
    // 0x800A5E8C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_7:
    // 0x800A5E90: jal         0x800D674C
    // 0x800A5E94: addiu       $a0, $zero, 0x637
    ctx->r4 = ADD32(0, 0X637);
    func_800D674C(rdram, ctx);
        goto after_8;
    // 0x800A5E94: addiu       $a0, $zero, 0x637
    ctx->r4 = ADD32(0, 0X637);
    after_8:
    // 0x800A5E98: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A5E9C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800A5EA0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800A5EA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A5EA8: jal         0x800DE448
    // 0x800A5EAC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800DE448(rdram, ctx);
        goto after_9;
    // 0x800A5EAC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_9:
    // 0x800A5EB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A5EB4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A5EB8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800A5EBC: jr          $ra
    // 0x800A5EC0: nop

    return;
    // 0x800A5EC0: nop

;}
RECOMP_FUNC void _chfiregen_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800869E8: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x800869E8);
    return;
    // 0x800869EC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_800E37E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E37E8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800E37EC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x800E37F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E37F4: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_800E37F8:
    // 0x800E37F8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800E37FC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800E3800: bltz        $v0, L_800E3840
    if (SIGNED(ctx->r2) < 0) {
        // 0x800E3804: nop
    
            goto L_800E3840;
    }
    // 0x800E3804: nop

    // 0x800E3808: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x800E380C: mflo        $t6
    ctx->r14 = lo;
    // 0x800E3810: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800E3814: bne         $a2, $zero, L_800E3820
    if (ctx->r6 != 0) {
        // 0x800E3818: nop
    
            goto L_800E3820;
    }
    // 0x800E3818: nop

    // 0x800E381C: break       7
    do_break(2148415516);
L_800E3820:
    // 0x800E3820: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E3824: bne         $a2, $at, L_800E3838
    if (ctx->r6 != ctx->r1) {
        // 0x800E3828: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E3838;
    }
    // 0x800E3828: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E382C: bne         $v0, $at, L_800E3838
    if (ctx->r2 != ctx->r1) {
        // 0x800E3830: nop
    
            goto L_800E3838;
    }
    // 0x800E3830: nop

    // 0x800E3834: break       6
    do_break(2148415540);
L_800E3838:
    // 0x800E3838: b           L_800E3878
    // 0x800E383C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
        goto L_800E3878;
    // 0x800E383C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
L_800E3840:
    // 0x800E3840: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x800E3844: mflo        $t7
    ctx->r15 = lo;
    // 0x800E3848: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800E384C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800E3850: bne         $a2, $zero, L_800E385C
    if (ctx->r6 != 0) {
        // 0x800E3854: nop
    
            goto L_800E385C;
    }
    // 0x800E3854: nop

    // 0x800E3858: break       7
    do_break(2148415576);
L_800E385C:
    // 0x800E385C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E3860: bne         $a2, $at, L_800E3874
    if (ctx->r6 != ctx->r1) {
        // 0x800E3864: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E3874;
    }
    // 0x800E3864: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E3868: bne         $v0, $at, L_800E3874
    if (ctx->r2 != ctx->r1) {
        // 0x800E386C: nop
    
            goto L_800E3874;
    }
    // 0x800E386C: nop

    // 0x800E3870: break       6
    do_break(2148415600);
L_800E3874:
    // 0x800E3874: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
L_800E3878:
    // 0x800E3878: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800E387C: bltz        $v0, L_800E38BC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800E3880: nop
    
            goto L_800E38BC;
    }
    // 0x800E3880: nop

    // 0x800E3884: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x800E3888: mflo        $t9
    ctx->r25 = lo;
    // 0x800E388C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800E3890: bne         $a2, $zero, L_800E389C
    if (ctx->r6 != 0) {
        // 0x800E3894: nop
    
            goto L_800E389C;
    }
    // 0x800E3894: nop

    // 0x800E3898: break       7
    do_break(2148415640);
L_800E389C:
    // 0x800E389C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E38A0: bne         $a2, $at, L_800E38B4
    if (ctx->r6 != ctx->r1) {
        // 0x800E38A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E38B4;
    }
    // 0x800E38A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E38A8: bne         $v0, $at, L_800E38B4
    if (ctx->r2 != ctx->r1) {
        // 0x800E38AC: nop
    
            goto L_800E38B4;
    }
    // 0x800E38AC: nop

    // 0x800E38B0: break       6
    do_break(2148415664);
L_800E38B4:
    // 0x800E38B4: b           L_800E38F0
    // 0x800E38B8: nop

        goto L_800E38F0;
    // 0x800E38B8: nop

L_800E38BC:
    // 0x800E38BC: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x800E38C0: mflo        $t1
    ctx->r9 = lo;
    // 0x800E38C4: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800E38C8: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800E38CC: bne         $a2, $zero, L_800E38D8
    if (ctx->r6 != 0) {
        // 0x800E38D0: nop
    
            goto L_800E38D8;
    }
    // 0x800E38D0: nop

    // 0x800E38D4: break       7
    do_break(2148415700);
L_800E38D8:
    // 0x800E38D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E38DC: bne         $a2, $at, L_800E38F0
    if (ctx->r6 != ctx->r1) {
        // 0x800E38E0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E38F0;
    }
    // 0x800E38E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E38E4: bne         $v0, $at, L_800E38F0
    if (ctx->r2 != ctx->r1) {
        // 0x800E38E8: nop
    
            goto L_800E38F0;
    }
    // 0x800E38E8: nop

    // 0x800E38EC: break       6
    do_break(2148415724);
L_800E38F0:
    // 0x800E38F0: bne         $v1, $a0, L_800E37F8
    if (ctx->r3 != ctx->r4) {
        // 0x800E38F4: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_800E37F8;
    }
    // 0x800E38F4: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800E38F8: jr          $ra
    // 0x800E38FC: nop

    return;
    // 0x800E38FC: nop

;}
RECOMP_FUNC void heap_resize_block_internal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B0C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001B0CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B0D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001B0D4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8001B0D8: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8001B0DC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8001B0E0: subu        $v1, $t6, $a0
    ctx->r3 = SUB32(ctx->r14, ctx->r4);
    // 0x8001B0E4: subu        $t8, $v1, $a1
    ctx->r24 = SUB32(ctx->r3, ctx->r5);
    // 0x8001B0E8: addiu       $t9, $t8, -0x10
    ctx->r25 = ADD32(ctx->r24, -0X10);
    // 0x8001B0EC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8001B0F0: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x8001B0F4: srl         $t1, $v0, 8
    ctx->r9 = S32(U32(ctx->r2) >> 8);
    // 0x8001B0F8: xor         $t2, $t0, $t1
    ctx->r10 = ctx->r8 ^ ctx->r9;
    // 0x8001B0FC: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x8001B100: xor         $t4, $t3, $v0
    ctx->r12 = ctx->r11 ^ ctx->r2;
    // 0x8001B104: sw          $t4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r12;
    // 0x8001B108: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B10C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8001B110: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8001B114: blez        $t5, L_8001B140
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8001B118: addiu       $a1, $a3, -0x20
        ctx->r5 = ADD32(ctx->r7, -0X20);
            goto L_8001B140;
    }
    // 0x8001B118: addiu       $a1, $a3, -0x20
    ctx->r5 = ADD32(ctx->r7, -0X20);
    // 0x8001B11C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8001B120: jal         0x8001BD30
    // 0x8001B124: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8001BD30(rdram, ctx);
        goto after_0;
    // 0x8001B124: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001B128: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8001B12C: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    // 0x8001B130: subu        $v1, $t6, $a2
    ctx->r3 = SUB32(ctx->r14, ctx->r6);
    // 0x8001B134: subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    // 0x8001B138: b           L_8001B140
    // 0x8001B13C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_8001B140;
    // 0x8001B13C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_8001B140:
    // 0x8001B140: sltiu       $at, $a1, 0x20
    ctx->r1 = ctx->r5 < 0X20 ? 1 : 0;
    // 0x8001B144: bne         $at, $zero, L_8001B1B8
    if (ctx->r1 != 0) {
        // 0x8001B148: subu        $a3, $v1, $a1
        ctx->r7 = SUB32(ctx->r3, ctx->r5);
            goto L_8001B1B8;
    }
    // 0x8001B148: subu        $a3, $v1, $a1
    ctx->r7 = SUB32(ctx->r3, ctx->r5);
    // 0x8001B14C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8001B150: addiu       $v1, $v1, -0x8B0
    ctx->r3 = ADD32(ctx->r3, -0X8B0);
    // 0x8001B154: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8001B158: addu        $a0, $a2, $a3
    ctx->r4 = ADD32(ctx->r6, ctx->r7);
    // 0x8001B15C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8001B160: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x8001B164: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001B168: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x8001B16C: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    // 0x8001B170: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8001B174: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8001B178: sw          $a0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r4;
    // 0x8001B17C: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x8001B180: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    // 0x8001B184: lw          $t1, 0x4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4);
    // 0x8001B188: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B18C: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
    // 0x8001B190: subu        $t2, $t1, $a2
    ctx->r10 = SUB32(ctx->r9, ctx->r6);
    // 0x8001B194: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x8001B198: addiu       $t5, $t4, -0x10
    ctx->r13 = ADD32(ctx->r12, -0X10);
    // 0x8001B19C: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x8001B1A0: srl         $t7, $v0, 8
    ctx->r15 = S32(U32(ctx->r2) >> 8);
    // 0x8001B1A4: xor         $t8, $t6, $t7
    ctx->r24 = ctx->r14 ^ ctx->r15;
    // 0x8001B1A8: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8001B1AC: xor         $t0, $t9, $v0
    ctx->r8 = ctx->r25 ^ ctx->r2;
    // 0x8001B1B0: jal         0x8001A7B0
    // 0x8001B1B4: sw          $t0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r8;
    heap_init_empty_block(rdram, ctx);
        goto after_1;
    // 0x8001B1B4: sw          $t0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r8;
    after_1:
L_8001B1B8:
    // 0x8001B1B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B1BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001B1C0: jr          $ra
    // 0x8001B1C4: nop

    return;
    // 0x8001B1C4: nop

;}
RECOMP_FUNC void _chlakemonster_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086CC8: syscall     444
    recomp_syscall_handler(rdram, ctx, 0x80086CC8);
    return;
    // 0x80086CCC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chmonsterinterior_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086558: syscall     336
    recomp_syscall_handler(rdram, ctx, 0x80086558);
    return;
    // 0x8008655C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800AA8_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AA8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800AAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800AB0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800AB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800AB8: jal         0x80800350
    // 0x80800ABC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    bsstatue_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800ABC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x80800AC0: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80800AC4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800AC8: jal         0x8008CB10
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_1;
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800AD0: beq         $v0, $zero, L_80800AF8
    if (ctx->r2 == 0) {
        // 0x80800AD4: lui         $a2, 0x3F61
        ctx->r6 = S32(0X3F61 << 16);
            goto L_80800AF8;
    }
    // 0x80800AD4: lui         $a2, 0x3F61
    ctx->r6 = S32(0X3F61 << 16);
    // 0x80800AD8: lui         $a3, 0x3F6B
    ctx->r7 = S32(0X3F6B << 16);
    // 0x80800ADC: addiu       $t6, $zero, 0x1B58
    ctx->r14 = ADD32(0, 0X1B58);
    // 0x80800AE0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800AE4: ori         $a3, $a3, 0x851F
    ctx->r7 = ctx->r7 | 0X851F;
    // 0x80800AE8: ori         $a2, $a2, 0x47AE
    ctx->r6 = ctx->r6 | 0X47AE;
    // 0x80800AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF0: jal         0x8009DBB0
    // 0x80800AF4: addiu       $a1, $zero, 0x4A1
    ctx->r5 = ADD32(0, 0X4A1);
    func_8009DBB0(rdram, ctx);
        goto after_2;
    // 0x80800AF4: addiu       $a1, $zero, 0x4A1
    ctx->r5 = ADD32(0, 0X4A1);
    after_2:
L_80800AF8:
    // 0x80800AF8: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80800AFC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800B00: jal         0x8008CB10
    // 0x80800B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_3;
    // 0x80800B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800B08: beq         $v0, $zero, L_80800B30
    if (ctx->r2 == 0) {
        // 0x80800B0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B30;
    }
    // 0x80800B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B10: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80800B14: lui         $a3, 0x3F26
    ctx->r7 = S32(0X3F26 << 16);
    // 0x80800B18: addiu       $t7, $zero, 0x2EE0
    ctx->r15 = ADD32(0, 0X2EE0);
    // 0x80800B1C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800B20: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800B24: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800B28: jal         0x8009DBB0
    // 0x80800B2C: addiu       $a1, $zero, 0x632
    ctx->r5 = ADD32(0, 0X632);
    func_8009DBB0(rdram, ctx);
        goto after_4;
    // 0x80800B2C: addiu       $a1, $zero, 0x632
    ctx->r5 = ADD32(0, 0X632);
    after_4:
L_80800B30:
    // 0x80800B30: lui         $a1, 0x3F59
    ctx->r5 = S32(0X3F59 << 16);
    // 0x80800B34: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800B38: jal         0x8008CB10
    // 0x80800B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_5;
    // 0x80800B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800B40: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x80800B44: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B68;
    }
    // 0x80800B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B48: lui         $a2, 0x3F70
    ctx->r6 = S32(0X3F70 << 16);
    // 0x80800B4C: lui         $a3, 0x3F7A
    ctx->r7 = S32(0X3F7A << 16);
    // 0x80800B50: addiu       $t8, $zero, 0x1770
    ctx->r24 = ADD32(0, 0X1770);
    // 0x80800B54: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800B58: ori         $a3, $a3, 0xE148
    ctx->r7 = ctx->r7 | 0XE148;
    // 0x80800B5C: ori         $a2, $a2, 0xA3D7
    ctx->r6 = ctx->r6 | 0XA3D7;
    // 0x80800B60: jal         0x8009DBB0
    // 0x80800B64: addiu       $a1, $zero, 0x4A1
    ctx->r5 = ADD32(0, 0X4A1);
    func_8009DBB0(rdram, ctx);
        goto after_6;
    // 0x80800B64: addiu       $a1, $zero, 0x4A1
    ctx->r5 = ADD32(0, 0X4A1);
    after_6:
L_80800B68:
    // 0x80800B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B6C: jal         0x8008CB10
    // 0x80800B70: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    baanim_isAt(rdram, ctx);
        goto after_7;
    // 0x80800B70: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_7:
    // 0x80800B74: beq         $v0, $zero, L_80800B84
    if (ctx->r2 == 0) {
        // 0x80800B78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B84;
    }
    // 0x80800B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B7C: jal         0x80095774
    // 0x80800B80: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    baflag_clear(rdram, ctx);
        goto after_8;
    // 0x80800B80: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    after_8:
L_80800B84:
    // 0x80800B84: lui         $a1, 0x3EB8
    ctx->r5 = S32(0X3EB8 << 16);
    // 0x80800B88: ori         $a1, $a1, 0x2A99
    ctx->r5 = ctx->r5 | 0X2A99;
    // 0x80800B8C: jal         0x8008CB10
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_9;
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800B94: beq         $v0, $zero, L_80800BA4
    if (ctx->r2 == 0) {
        // 0x80800B98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BA4;
    }
    // 0x80800B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B9C: jal         0x80095760
    // 0x80800BA0: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    baflag_set(rdram, ctx);
        goto after_10;
    // 0x80800BA0: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    after_10:
L_80800BA4:
    // 0x80800BA4: jal         0x8008CAEC
    // 0x80800BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_11;
    // 0x80800BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800BAC: beq         $v0, $zero, L_80800BBC
    if (ctx->r2 == 0) {
        // 0x80800BB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BBC;
    }
    // 0x80800BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BB4: addiu       $t9, $zero, 0xF9
    ctx->r25 = ADD32(0, 0XF9);
    // 0x80800BB8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_80800BBC:
    // 0x80800BBC: jal         0x8009E5C8
    // 0x80800BC0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_12;
    // 0x80800BC0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_12:
    // 0x80800BC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800BC8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800BCC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800BD0: jr          $ra
    // 0x80800BD4: nop

    return;
    // 0x80800BD4: nop

;}
RECOMP_FUNC void _bskazmove_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800834B8: syscall     63
    recomp_syscall_handler(rdram, ctx, 0x800834B8);
    return;
    // 0x800834BC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800528_cadbmgrDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800528: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080052C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80800530: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800534: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800538: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8080053C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800540: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800544: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800548: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8080054C: lw          $s0, -0x4($t7)
    ctx->r16 = MEM_W(ctx->r15, -0X4);
    // 0x80800550: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800554: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800558: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8080055C: slt         $at, $a2, $s0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80800560: beq         $at, $zero, L_8080058C
    if (ctx->r1 == 0) {
        // 0x80800564: or          $s4, $a2, $zero
        ctx->r20 = ctx->r6 | 0;
            goto L_8080058C;
    }
    // 0x80800564: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
L_80800568:
    // 0x80800568: addiu       $s1, $s0, -0x1
    ctx->r17 = ADD32(ctx->r16, -0X1);
    // 0x8080056C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800570: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800574: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800578: jal         0x808005AC
    // 0x8080057C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_808005AC_cadbmgrDll(rdram, ctx);
        goto after_0;
    // 0x8080057C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_0:
    // 0x80800580: slt         $at, $s4, $s1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80800584: bne         $at, $zero, L_80800568
    if (ctx->r1 != 0) {
        // 0x80800588: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80800568;
    }
    // 0x80800588: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8080058C:
    // 0x8080058C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800590: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800594: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800598: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080059C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808005A0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808005A4: jr          $ra
    // 0x808005A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808005A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800ADC_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800ADC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AE4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800AE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800AEC: jal         0x80100094
    // 0x80800AF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800AF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800AF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800AF8: jal         0x800DA524
    // 0x80800AFC: addiu       $a0, $zero, 0x9D5
    ctx->r4 = ADD32(0, 0X9D5);
    func_800DA524(rdram, ctx);
        goto after_1;
    // 0x80800AFC: addiu       $a0, $zero, 0x9D5
    ctx->r4 = ADD32(0, 0X9D5);
    after_1:
    // 0x80800B00: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800B04: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B08: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800B0C: beql        $t6, $zero, L_80800B28
    if (ctx->r14 == 0) {
        // 0x80800B10: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800B28;
    }
    goto skip_0;
    // 0x80800B10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80800B14: lh          $a1, 0x2C($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X2C);
    // 0x80800B18: addiu       $a0, $zero, 0x9CD
    ctx->r4 = ADD32(0, 0X9CD);
    // 0x80800B1C: jal         0x800DA7A8
    // 0x80800B20: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_800DA7A8(rdram, ctx);
        goto after_2;
    // 0x80800B20: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_2:
    // 0x80800B24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800B28:
    // 0x80800B28: jal         0x80101FDC
    // 0x80800B2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800B2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800B30: jal         0x80088840
    // 0x80800B34: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x80800B34: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_4:
    // 0x80800B38: beql        $v0, $zero, L_80800B4C
    if (ctx->r2 == 0) {
        // 0x80800B3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800B4C;
    }
    goto skip_1;
    // 0x80800B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800B40: jal         0x80088830
    // 0x80800B44: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x80800B44: nop

    after_5:
    // 0x80800B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B4C:
    // 0x80800B4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B50: jr          $ra
    // 0x80800B54: nop

    return;
    // 0x80800B54: nop

;}
RECOMP_FUNC void func_800D52B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D52B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D52B4: addiu       $v0, $v0, -0x4BD0
    ctx->r2 = ADD32(ctx->r2, -0X4BD0);
    // 0x800D52B8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800D52BC: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800D52C0: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x800D52C4: jr          $ra
    // 0x800D52C8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    return;
    // 0x800D52C8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
;}
RECOMP_FUNC void _bsfirstp_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084378: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084378);
    return;
    // 0x8008437C: addi        $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
;}
RECOMP_FUNC void func_800ABB34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABB34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ABB38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ABB3C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800ABB40: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x800ABB44: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800ABB48: addiu       $t7, $t6, 0x4C
    ctx->r15 = ADD32(ctx->r14, 0X4C);
    // 0x800ABB4C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800ABB50: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800ABB54: subu        $t9, $t7, $v1
    ctx->r25 = SUB32(ctx->r15, ctx->r3);
    // 0x800ABB58: addiu       $t0, $t9, -0x10
    ctx->r8 = ADD32(ctx->r25, -0X10);
    // 0x800ABB5C: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x800ABB60: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x800ABB64: mflo        $t1
    ctx->r9 = lo;
    // 0x800ABB68: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800ABB6C: bnel        $at, $zero, L_800ABC00
    if (ctx->r1 != 0) {
        // 0x800ABB70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800ABC00;
    }
    goto skip_0;
    // 0x800ABB70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800ABB74: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x800ABB78: bnel        $a0, $zero, L_800ABBD4
    if (ctx->r4 != 0) {
        // 0x800ABB7C: sw          $a0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r4;
            goto L_800ABBD4;
    }
    goto skip_1;
    // 0x800ABB7C: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    skip_1:
    // 0x800ABB80: addiu       $a0, $zero, 0xEE8
    ctx->r4 = ADD32(0, 0XEE8);
    // 0x800ABB84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800ABB88: jal         0x8001ACCC
    // 0x800ABB8C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800ABB8C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800ABB90: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABB94: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800ABB98: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x800ABB9C: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x800ABBA0: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x800ABBA4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800ABBA8: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x800ABBAC: sw          $v1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r3;
    // 0x800ABBB0: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800ABBB4: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x800ABBB8: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800ABBBC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800ABBC0: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800ABBC4: sw          $t7, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r15;
    // 0x800ABBC8: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x800ABBCC: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    // 0x800ABBD0: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
L_800ABBD4:
    // 0x800ABBD4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800ABBD8: jal         0x8001211C
    // 0x800ABBDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8001211C(rdram, ctx);
        goto after_1;
    // 0x800ABBDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x800ABBE0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABBE4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800ABBE8: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800ABBEC: sw          $v0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r2;
    // 0x800ABBF0: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800ABBF4: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x800ABBF8: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x800ABBFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800ABC00:
    // 0x800ABC00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800ABC04: jr          $ra
    // 0x800ABC08: nop

    return;
    // 0x800ABC08: nop

;}
RECOMP_FUNC void _suegg_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A430: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A430);
    return;
    // 0x8008A434: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void basnowball_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800554: lw          $t6, 0x110($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X110);
    // 0x80800558: jr          $ra
    // 0x8080055C: lwc1        $f0, 0x8($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X8);
    return;
    // 0x8080055C: lwc1        $f0, 0x8($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X8);
;}
RECOMP_FUNC void func_800A4190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4190: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A4194: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A4198: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A419C: jal         0x800A4D40
    // 0x800A41A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A4D40(rdram, ctx);
        goto after_0;
    // 0x800A41A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800A41A4: beql        $v0, $zero, L_800A4328
    if (ctx->r2 == 0) {
        // 0x800A41A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A4328;
    }
    goto skip_0;
    // 0x800A41A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800A41AC: jal         0x800F65D0
    // 0x800A41B0: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F65D0(rdram, ctx);
        goto after_1;
    // 0x800A41B0: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_1:
    // 0x800A41B4: beql        $v0, $zero, L_800A4328
    if (ctx->r2 == 0) {
        // 0x800A41B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A4328;
    }
    goto skip_1;
    // 0x800A41B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800A41BC: jal         0x8009CC68
    // 0x800A41C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009CC68(rdram, ctx);
        goto after_2;
    // 0x800A41C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800A41C4: bnel        $v0, $zero, L_800A4328
    if (ctx->r2 != 0) {
        // 0x800A41C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A4328;
    }
    goto skip_2;
    // 0x800A41C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800A41CC: jal         0x800F3ED0
    // 0x800A41D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F3ED0(rdram, ctx);
        goto after_3;
    // 0x800A41D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800A41D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A41D8: beq         $v0, $at, L_800A4324
    if (ctx->r2 == ctx->r1) {
        // 0x800A41DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A4324;
    }
    // 0x800A41DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A41E0: jal         0x80085300
    // 0x800A41E4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    _batimer_get(rdram, ctx);
        goto after_4;
    // 0x800A41E4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_4:
    // 0x800A41E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A41EC: nop

    // 0x800A41F0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800A41F4: nop

    // 0x800A41F8: bc1fl       L_800A4328
    if (!c1cs) {
        // 0x800A41FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A4328;
    }
    goto skip_3;
    // 0x800A41FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x800A4200: jal         0x80097BB8
    // 0x800A4204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_exit_first_person(rdram, ctx);
        goto after_5;
    // 0x800A4204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800A4208: beql        $v0, $zero, L_800A4328
    if (ctx->r2 == 0) {
        // 0x800A420C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A4328;
    }
    goto skip_4;
    // 0x800A420C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x800A4210: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x800A4214: lbu         $t6, 0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4);
    // 0x800A4218: bnel        $t6, $zero, L_800A4328
    if (ctx->r14 != 0) {
        // 0x800A421C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A4328;
    }
    goto skip_5;
    // 0x800A421C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x800A4220: lbu         $t7, 0x3B($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3B);
    // 0x800A4224: bnel        $t7, $zero, L_800A4328
    if (ctx->r15 != 0) {
        // 0x800A4228: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A4328;
    }
    goto skip_6;
    // 0x800A4228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x800A422C: lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2);
    // 0x800A4230: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A4234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4238: beq         $v1, $at, L_800A425C
    if (ctx->r3 == ctx->r1) {
        // 0x800A423C: addiu       $a1, $zero, 0x488
        ctx->r5 = ADD32(0, 0X488);
            goto L_800A425C;
    }
    // 0x800A423C: addiu       $a1, $zero, 0x488
    ctx->r5 = ADD32(0, 0X488);
    // 0x800A4240: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A4244: beq         $v1, $at, L_800A4280
    if (ctx->r3 == ctx->r1) {
        // 0x800A4248: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A4280;
    }
    // 0x800A4248: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A424C: beq         $v1, $at, L_800A42F0
    if (ctx->r3 == ctx->r1) {
        // 0x800A4250: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A42F0;
    }
    // 0x800A4250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4254: b           L_800A4314
    // 0x800A4258: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
        goto L_800A4314;
    // 0x800A4258: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
L_800A425C:
    // 0x800A425C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800A4260: jal         0x8009DB04
    // 0x800A4264: addiu       $a3, $zero, 0x2EE0
    ctx->r7 = ADD32(0, 0X2EE0);
    func_8009DB04(rdram, ctx);
        goto after_6;
    // 0x800A4264: addiu       $a3, $zero, 0x2EE0
    ctx->r7 = ADD32(0, 0X2EE0);
    after_6:
    // 0x800A4268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A426C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800A4270: jal         0x800A3D78
    // 0x800A4274: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A3D78(rdram, ctx);
        goto after_7;
    // 0x800A4274: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x800A4278: b           L_800A4314
    // 0x800A427C: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
        goto L_800A4314;
    // 0x800A427C: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
L_800A4280:
    // 0x800A4280: lw          $t8, 0x20($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X20);
    // 0x800A4284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4288: addiu       $a1, $zero, 0x487
    ctx->r5 = ADD32(0, 0X487);
    // 0x800A428C: beq         $t8, $zero, L_800A42D0
    if (ctx->r24 == 0) {
        // 0x800A4290: lui         $a2, 0x3F80
        ctx->r6 = S32(0X3F80 << 16);
            goto L_800A42D0;
    }
    // 0x800A4290: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800A4294: lbu         $t9, 0x39($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X39);
    // 0x800A4298: addiu       $a3, $zero, 0x2EE0
    ctx->r7 = ADD32(0, 0X2EE0);
    // 0x800A429C: bne         $t9, $zero, L_800A42D0
    if (ctx->r25 != 0) {
        // 0x800A42A0: nop
    
            goto L_800A42D0;
    }
    // 0x800A42A0: nop

    // 0x800A42A4: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x800A42A8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800A42AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A42B0: jal         0x8009DB04
    // 0x800A42B4: addiu       $a1, $zero, 0x488
    ctx->r5 = ADD32(0, 0X488);
    func_8009DB04(rdram, ctx);
        goto after_8;
    // 0x800A42B4: addiu       $a1, $zero, 0x488
    ctx->r5 = ADD32(0, 0X488);
    after_8:
    // 0x800A42B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A42BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800A42C0: jal         0x800A3D78
    // 0x800A42C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A3D78(rdram, ctx);
        goto after_9;
    // 0x800A42C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x800A42C8: b           L_800A4314
    // 0x800A42CC: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
        goto L_800A4314;
    // 0x800A42CC: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
L_800A42D0:
    // 0x800A42D0: jal         0x8009DB04
    // 0x800A42D4: addiu       $a3, $zero, 0x2EE0
    ctx->r7 = ADD32(0, 0X2EE0);
    func_8009DB04(rdram, ctx);
        goto after_10;
    // 0x800A42D4: addiu       $a3, $zero, 0x2EE0
    ctx->r7 = ADD32(0, 0X2EE0);
    after_10:
    // 0x800A42D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A42DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800A42E0: jal         0x800A3D78
    // 0x800A42E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A3D78(rdram, ctx);
        goto after_11;
    // 0x800A42E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x800A42E8: b           L_800A4314
    // 0x800A42EC: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
        goto L_800A4314;
    // 0x800A42EC: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
L_800A42F0:
    // 0x800A42F0: addiu       $a1, $zero, 0x487
    ctx->r5 = ADD32(0, 0X487);
    // 0x800A42F4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800A42F8: jal         0x8009DB04
    // 0x800A42FC: addiu       $a3, $zero, 0x2EE0
    ctx->r7 = ADD32(0, 0X2EE0);
    func_8009DB04(rdram, ctx);
        goto after_12;
    // 0x800A42FC: addiu       $a3, $zero, 0x2EE0
    ctx->r7 = ADD32(0, 0X2EE0);
    after_12:
    // 0x800A4300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4304: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800A4308: jal         0x800A3D78
    // 0x800A430C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A3D78(rdram, ctx);
        goto after_13;
    // 0x800A430C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x800A4310: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
L_800A4314:
    // 0x800A4314: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800A4318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A431C: jal         0x80085338
    // 0x800A4320: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    _batimer_set(rdram, ctx);
        goto after_14;
    // 0x800A4320: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_14:
L_800A4324:
    // 0x800A4324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A4328:
    // 0x800A4328: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A432C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A4330: jr          $ra
    // 0x800A4334: nop

    return;
    // 0x800A4334: nop

;}
RECOMP_FUNC void func_80016DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016DF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80016DFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80016E00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80016E04: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80016E08: addiu       $s0, $a0, 0x1DDD
    ctx->r16 = ADD32(ctx->r4, 0X1DDD);
    // 0x80016E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80016E10: jal         0x800D73CC
    // 0x80016E14: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800D73CC(rdram, ctx);
        goto after_0;
    // 0x80016E14: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x80016E18: beq         $v0, $zero, L_80016E68
    if (ctx->r2 == 0) {
        // 0x80016E1C: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80016E68;
    }
    // 0x80016E1C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80016E20: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80016E24: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80016E28: addiu       $v1, $v1, -0x51A8
    ctx->r3 = ADD32(ctx->r3, -0X51A8);
    // 0x80016E2C: addiu       $v0, $v0, -0x6060
    ctx->r2 = ADD32(ctx->r2, -0X6060);
    // 0x80016E30: lh          $t6, 0x26C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X26C);
L_80016E34:
    // 0x80016E34: addiu       $v0, $v0, 0x274
    ctx->r2 = ADD32(ctx->r2, 0X274);
    // 0x80016E38: beql        $a1, $t6, L_80016E6C
    if (ctx->r5 == ctx->r14) {
        // 0x80016E3C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80016E6C;
    }
    goto skip_0;
    // 0x80016E3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80016E40: bnel        $v0, $v1, L_80016E34
    if (ctx->r2 != ctx->r3) {
        // 0x80016E44: lh          $t6, 0x26C($v0)
        ctx->r14 = MEM_H(ctx->r2, 0X26C);
            goto L_80016E34;
    }
    goto skip_1;
    // 0x80016E44: lh          $t6, 0x26C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X26C);
    skip_1:
    // 0x80016E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80016E4C: jal         0x800D721C
    // 0x80016E50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D721C(rdram, ctx);
        goto after_1;
    // 0x80016E50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80016E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80016E58: jal         0x800D70F8
    // 0x80016E5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D70F8(rdram, ctx);
        goto after_2;
    // 0x80016E5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80016E60: jal         0x800D6CEC
    // 0x80016E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D6CEC(rdram, ctx);
        goto after_3;
    // 0x80016E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80016E68:
    // 0x80016E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80016E6C:
    // 0x80016E6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80016E70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80016E74: jr          $ra
    // 0x80016E78: nop

    return;
    // 0x80016E78: nop

;}
RECOMP_FUNC void func_80800998_chcoderoombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800998: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080099C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009A0: jal         0x80100094
    // 0x808009A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009A8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1172, 0X11F4) << 16);
    // 0x808009AC: addiu       $v1, $a1, 0x11F4
    ctx->r3 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1172, 0X11F4));
    // 0x808009B0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x808009B4: addiu       $a0, $v0, 0x154
    ctx->r4 = ADD32(ctx->r2, 0X154);
    // 0x808009B8: beql        $t6, $zero, L_808009E8
    if (ctx->r14 == 0) {
        // 0x808009BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808009E8;
    }
    goto skip_0;
    // 0x808009BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808009C0: lbu         $t7, 0xA($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XA);
L_808009C4:
    // 0x808009C4: bnel        $t7, $zero, L_808009D4
    if (ctx->r15 != 0) {
        // 0x808009C8: lw          $t8, 0xC($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XC);
            goto L_808009D4;
    }
    goto skip_1;
    // 0x808009C8: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    skip_1:
    // 0x808009CC: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x808009D0: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
L_808009D4:
    // 0x808009D4: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x808009D8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x808009DC: bnel        $t8, $zero, L_808009C4
    if (ctx->r24 != 0) {
        // 0x808009E0: lbu         $t7, 0xA($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0XA);
            goto L_808009C4;
    }
    goto skip_2;
    // 0x808009E0: lbu         $t7, 0xA($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XA);
    skip_2:
    // 0x808009E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808009E8:
    // 0x808009E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009EC: jr          $ra
    // 0x808009F0: nop

    return;
    // 0x808009F0: nop

;}
RECOMP_FUNC void chjigsawdance_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F4: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x808002F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002FC: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80800300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800304: beq         $at, $zero, L_80800420
    if (ctx->r1 == 0) {
        // 0x80800308: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80800420;
    }
    // 0x80800308: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080030C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800310: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(708, 0X444) << 16);
    // 0x80800314: addu        $at, $at, $t6
    gpr jr_addend_8080031C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800318: lw          $t6, 0x444($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(708, 0X444));
    // 0x8080031C: jr          $t6
    // 0x80800320: nop

    switch (jr_addend_8080031C >> 2) {
        case 0: goto L_80800374; break;
        case 1: goto L_80800360; break;
        case 2: goto L_80800324; break;
        case 3: goto L_80800388; break;
        case 4: goto L_808003F0; break;
        default: switch_error(__func__, 0x8080031C, 0x80800444);
    }
    // 0x80800320: nop

L_80800324:
    // 0x80800324: lhu         $t7, 0x72($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X72);
    // 0x80800328: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080032C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800330: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800334: bne         $t8, $at, L_80800420
    if (ctx->r24 != ctx->r1) {
        // 0x80800338: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80800420;
    }
    // 0x80800338: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080033C: jal         0x80101FDC
    // 0x80800340: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800340: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800344: jal         0x80104248
    // 0x80800348: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80104248(rdram, ctx);
        goto after_1;
    // 0x80800348: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080034C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800350: jal         0x8008B134
    // 0x80800354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_2;
    // 0x80800354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800358: b           L_80800424
    // 0x8080035C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800424;
    // 0x8080035C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800360:
    // 0x80800360: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800364: jal         0x80101FDC
    // 0x80800368: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800368: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x8080036C: b           L_80800424
    // 0x80800370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800424;
    // 0x80800370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800374:
    // 0x80800374: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800378: jal         0x80101FDC
    // 0x8080037C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x8080037C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80800380: b           L_80800424
    // 0x80800384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800424;
    // 0x80800384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800388:
    // 0x80800388: addiu       $a0, $a2, 0x4
    ctx->r4 = ADD32(ctx->r6, 0X4);
    // 0x8080038C: jal         0x8010D254
    // 0x80800390: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8010D254(rdram, ctx);
        goto after_5;
    // 0x80800390: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_5:
    // 0x80800394: jal         0x80090010
    // 0x80800398: nop

    func_80090010(rdram, ctx);
        goto after_6;
    // 0x80800398: nop

    after_6:
    // 0x8080039C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808003A0: jal         0x80104248
    // 0x808003A4: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    func_80104248(rdram, ctx);
        goto after_7;
    // 0x808003A4: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    after_7:
    // 0x808003A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808003AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003B0: jal         0x8008B1A0
    // 0x808003B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_8;
    // 0x808003B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808003B8: jal         0x8008FD20
    // 0x808003BC: nop

    func_8008FD20(rdram, ctx);
        goto after_9;
    // 0x808003BC: nop

    after_9:
    // 0x808003C0: jal         0x8008B2B4
    // 0x808003C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_10;
    // 0x808003C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x808003C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003CC: jal         0x8008B24C
    // 0x808003D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    anctrl_setStart(rdram, ctx);
        goto after_11;
    // 0x808003D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_11:
    // 0x808003D4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808003D8: jal         0x8008B1BC
    // 0x808003DC: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_12;
    // 0x808003DC: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    after_12:
    // 0x808003E0: jal         0x8008B064
    // 0x808003E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    anctrl_start(rdram, ctx);
        goto after_13;
    // 0x808003E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_13:
    // 0x808003E8: b           L_80800424
    // 0x808003EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800424;
    // 0x808003EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003F0:
    // 0x808003F0: lw          $v0, 0x6C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X6C);
    // 0x808003F4: andi        $t9, $v0, 0x1FF
    ctx->r25 = ctx->r2 & 0X1FF;
    // 0x808003F8: beq         $t9, $zero, L_80800418
    if (ctx->r25 == 0) {
        // 0x808003FC: or          $a0, $t9, $zero
        ctx->r4 = ctx->r25 | 0;
            goto L_80800418;
    }
    // 0x808003FC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80800400: jal         0x800C8B84
    // 0x80800404: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800C8B84(rdram, ctx);
        goto after_14;
    // 0x80800404: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_14:
    // 0x80800408: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8080040C: lhu         $t0, 0x6E($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X6E);
    // 0x80800410: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x80800414: sh          $t1, 0x6E($a2)
    MEM_H(0X6E, ctx->r6) = ctx->r9;
L_80800418:
    // 0x80800418: jal         0x800FFA88
    // 0x8080041C: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_15;
    // 0x8080041C: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    after_15:
L_80800420:
    // 0x80800420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800424:
    // 0x80800424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800428: jr          $ra
    // 0x8080042C: nop

    return;
    // 0x8080042C: nop

;}
RECOMP_FUNC void func_80800E0C_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E18: jal         0x80082840
    // 0x80800E1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bsbee_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800E1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E24: jal         0x8009B9B0
    // 0x80800E28: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_1;
    // 0x80800E28: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_1:
    // 0x80800E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E30: jal         0x8009D3A8
    // 0x80800E34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_2;
    // 0x80800E34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800E38: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80800E3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800E40: beq         $v0, $zero, L_80800E6C
    if (ctx->r2 == 0) {
        // 0x80800E44: nop
    
            goto L_80800E6C;
    }
    // 0x80800E44: nop

    // 0x80800E48: beq         $v0, $at, L_80800ED0
    if (ctx->r2 == ctx->r1) {
        // 0x80800E4C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800ED0;
    }
    // 0x80800E4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800E50: beq         $v0, $at, L_80800F24
    if (ctx->r2 == ctx->r1) {
        // 0x80800E54: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_80800F24;
    }
    // 0x80800E54: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80800E58: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800E5C: beql        $v0, $at, L_80800F30
    if (ctx->r2 == ctx->r1) {
        // 0x80800E60: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_80800F30;
    }
    goto skip_0;
    // 0x80800E60: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_0:
    // 0x80800E64: b           L_80800F5C
    // 0x80800E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800F5C;
    // 0x80800E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800E6C:
    // 0x80800E6C: jal         0x8008E078
    // 0x80800E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_3;
    // 0x80800E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800E74: beq         $v0, $zero, L_80800F58
    if (ctx->r2 == 0) {
        // 0x80800E78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F58;
    }
    // 0x80800E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E7C: lui         $a1, 0x3F3E
    ctx->r5 = S32(0X3F3E << 16);
    // 0x80800E80: jal         0x8008CED4
    // 0x80800E84: ori         $a1, $a1, 0xCBFB
    ctx->r5 = ctx->r5 | 0XCBFB;
    baanim_setEnd(rdram, ctx);
        goto after_4;
    // 0x80800E84: ori         $a1, $a1, 0xCBFB
    ctx->r5 = ctx->r5 | 0XCBFB;
    after_4:
    // 0x80800E88: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800E8C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E94: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x80800E98: jal         0x8009DF18
    // 0x80800E9C: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_5;
    // 0x80800E9C: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_5:
    // 0x80800EA0: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80800EA4: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EAC: addiu       $a1, $zero, 0x428
    ctx->r5 = ADD32(0, 0X428);
    // 0x80800EB0: jal         0x8009DF18
    // 0x80800EB4: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_6;
    // 0x80800EB4: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_6:
    // 0x80800EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EBC: jal         0x8009BA58
    // 0x80800EC0: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_7;
    // 0x80800EC0: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_7:
    // 0x80800EC4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800EC8: b           L_80800F58
    // 0x80800ECC: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_80800F58;
    // 0x80800ECC: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80800ED0:
    // 0x80800ED0: jal         0x8008E078
    // 0x80800ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_8;
    // 0x80800ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800ED8: beq         $v0, $zero, L_80800F58
    if (ctx->r2 == 0) {
        // 0x80800EDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F58;
    }
    // 0x80800EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EE0: jal         0x8008CED4
    // 0x80800EE4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEnd(rdram, ctx);
        goto after_9;
    // 0x80800EE4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_9:
    // 0x80800EE8: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800EEC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EF4: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x80800EF8: jal         0x8009DF18
    // 0x80800EFC: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_10;
    // 0x80800EFC: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_10:
    // 0x80800F00: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80800F04: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F0C: addiu       $a1, $zero, 0x428
    ctx->r5 = ADD32(0, 0X428);
    // 0x80800F10: jal         0x8009DF18
    // 0x80800F14: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_11;
    // 0x80800F14: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_11:
    // 0x80800F18: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800F1C: b           L_80800F58
    // 0x80800F20: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_80800F58;
    // 0x80800F20: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_80800F24:
    // 0x80800F24: b           L_80800F58
    // 0x80800F28: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
        goto L_80800F58;
    // 0x80800F28: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
    // 0x80800F2C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_80800F30:
    // 0x80800F30: lwc1        $f0, 0x16C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800F34: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800F38: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80800F3C: nop

    // 0x80800F40: bc1fl       L_80800F5C
    if (!c1cs) {
        // 0x80800F44: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F5C;
    }
    goto skip_1;
    // 0x80800F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800F48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800F4C: jal         0x800F0E00
    // 0x80800F50: sub.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f4.fl;
    func_800F0E00(rdram, ctx);
        goto after_12;
    // 0x80800F50: sub.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f4.fl;
    after_12:
    // 0x80800F54: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
L_80800F58:
    // 0x80800F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F5C:
    // 0x80800F5C: jal         0x800852F0
    // 0x80800F60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_13;
    // 0x80800F60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80800F64: beql        $v0, $zero, L_80800F9C
    if (ctx->r2 == 0) {
        // 0x80800F68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F9C;
    }
    goto skip_2;
    // 0x80800F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800F6C: lw          $t9, 0x160($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X160);
    // 0x80800F70: addiu       $a0, $zero, 0x2C4
    ctx->r4 = ADD32(0, 0X2C4);
    // 0x80800F74: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    // 0x80800F78: beq         $t9, $zero, L_80800F90
    if (ctx->r25 == 0) {
        // 0x80800F7C: nop
    
            goto L_80800F90;
    }
    // 0x80800F7C: nop

    // 0x80800F80: jal         0x80101180
    // 0x80800F84: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    func_80101180(rdram, ctx);
        goto after_14;
    // 0x80800F84: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    after_14:
    // 0x80800F88: b           L_80800F9C
    // 0x80800F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800F9C;
    // 0x80800F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F90:
    // 0x80800F90: jal         0x80085200
    // 0x80800F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_0(rdram, ctx);
        goto after_15;
    // 0x80800F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F9C:
    // 0x80800F9C: jal         0x8009E5C8
    // 0x80800FA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bs_setState(rdram, ctx);
        goto after_16;
    // 0x80800FA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80800FA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800FAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800FB0: jr          $ra
    // 0x80800FB4: nop

    return;
    // 0x80800FB4: nop

;}
RECOMP_FUNC void func_80801804_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801804: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801808: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080180C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801810: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801814: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801818: bne         $a1, $at, L_80801864
    if (ctx->r5 != ctx->r1) {
        // 0x8080181C: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80801864;
    }
    // 0x8080181C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80801820: jal         0x800EA05C
    // 0x80801824: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80801824: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801828: addiu       $at, $zero, 0x101
    ctx->r1 = ADD32(0, 0X101);
    // 0x8080182C: bne         $v0, $at, L_8080184C
    if (ctx->r2 != ctx->r1) {
        // 0x80801830: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_8080184C;
    }
    // 0x80801830: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80801834: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801838: addiu       $a1, $zero, 0x87F
    ctx->r5 = ADD32(0, 0X87F);
    // 0x8080183C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801840: jal         0x80103140
    // 0x80801844: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80103140(rdram, ctx);
        goto after_1;
    // 0x80801844: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80801848: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_8080184C:
    // 0x8080184C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801850: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80801854: jal         0x80086248
    // 0x80801858: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80801858: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8080185C: b           L_80801878
    // 0x80801860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801878;
    // 0x80801860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801864:
    // 0x80801864: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801868: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8080186C: jal         0x80086248
    // 0x80801870: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80801870: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80801874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801878:
    // 0x80801878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080187C: jr          $ra
    // 0x80801880: nop

    return;
    // 0x80801880: nop

;}
RECOMP_FUNC void boot___ull_rshift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002810: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80002814: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80002818: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8000281C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80002820: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x80002824: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x80002828: dsrlv       $v0, $t6, $t7
    ctx->r2 = ctx->r14 >> (ctx->r15 & 63);
    // 0x8000282C: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x80002830: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x80002834: jr          $ra
    // 0x80002838: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x80002838: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void chnutsnbolts_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1304, 0XEB8) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0xEB8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1304, 0XEB8));
    return;
    // 0x80800020: addiu       $v0, $v0, 0xEB8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1304, 0XEB8));
;}
RECOMP_FUNC void func_8002C230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C230: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8002C234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C238: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8002C23C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8002C240: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8002C244: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8002C248: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8002C24C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8002C250: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8002C254: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8002C258: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8002C25C: lui         $t9, 0x200
    ctx->r25 = S32(0X200 << 16);
    // 0x8002C260: ori         $t9, $t9, 0x4E0
    ctx->r25 = ctx->r25 | 0X4E0;
    // 0x8002C264: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8002C268: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8002C26C: addiu       $t1, $zero, 0x2E0
    ctx->r9 = ADD32(0, 0X2E0);
    // 0x8002C270: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8002C274: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8002C278: lw          $t3, 0x11F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X11F4);
    // 0x8002C27C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8002C280: lw          $t4, 0x3C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X3C);
    // 0x8002C284: blez        $t4, L_8002C57C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8002C288: nop
    
            goto L_8002C57C;
    }
    // 0x8002C288: nop

L_8002C28C:
    // 0x8002C28C: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x8002C290: lw          $t5, 0x11F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X11F4);
    // 0x8002C294: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8002C298: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8002C29C: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x8002C2A0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8002C2A4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8002C2A8: jalr        $t9
    // 0x8002C2AC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8002C2AC: nop

    after_0:
    // 0x8002C2B0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8002C2B4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8002C2B8: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8002C2BC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8002C2C0: lbu         $t8, -0x15CD($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X15CD);
    // 0x8002C2C4: beq         $t8, $zero, L_8002C354
    if (ctx->r24 == 0) {
        // 0x8002C2C8: nop
    
            goto L_8002C354;
    }
    // 0x8002C2C8: nop

    // 0x8002C2CC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8002C2D0: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8002C2D4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8002C2D8: lbu         $t1, -0x15CC($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X15CC);
    // 0x8002C2DC: beq         $t1, $zero, L_8002C31C
    if (ctx->r9 == 0) {
        // 0x8002C2E0: nop
    
            goto L_8002C31C;
    }
    // 0x8002C2E0: nop

    // 0x8002C2E4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8002C2E8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8002C2EC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8002C2F0: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x8002C2F4: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8002C2F8: lui         $t4, 0xC00
    ctx->r12 = S32(0XC00 << 16);
    // 0x8002C2FC: ori         $t4, $t4, 0x8000
    ctx->r12 = ctx->r12 | 0X8000;
    // 0x8002C300: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8002C304: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8002C308: lui         $t6, 0x7C0
    ctx->r14 = S32(0X7C0 << 16);
    // 0x8002C30C: ori         $t6, $t6, 0x4E0
    ctx->r14 = ctx->r14 | 0X4E0;
    // 0x8002C310: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x8002C314: b           L_8002C34C
    // 0x8002C318: nop

        goto L_8002C34C;
    // 0x8002C318: nop

L_8002C31C:
    // 0x8002C31C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8002C320: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8002C324: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8002C328: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8002C32C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8002C330: lui         $t0, 0xC00
    ctx->r8 = S32(0XC00 << 16);
    // 0x8002C334: ori         $t0, $t0, 0x7FFF
    ctx->r8 = ctx->r8 | 0X7FFF;
    // 0x8002C338: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8002C33C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8002C340: lui         $t2, 0x7C0
    ctx->r10 = S32(0X7C0 << 16);
    // 0x8002C344: ori         $t2, $t2, 0x650
    ctx->r10 = ctx->r10 | 0X650;
    // 0x8002C348: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
L_8002C34C:
    // 0x8002C34C: b           L_8002C404
    // 0x8002C350: nop

        goto L_8002C404;
    // 0x8002C350: nop

L_8002C354:
    // 0x8002C354: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8002C358: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8002C35C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8002C360: lbu         $t5, -0x15CC($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X15CC);
    // 0x8002C364: beq         $t5, $zero, L_8002C3A4
    if (ctx->r13 == 0) {
        // 0x8002C368: nop
    
            goto L_8002C3A4;
    }
    // 0x8002C368: nop

    // 0x8002C36C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8002C370: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8002C374: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8002C378: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x8002C37C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8002C380: lui         $t7, 0xC00
    ctx->r15 = S32(0XC00 << 16);
    // 0x8002C384: ori         $t7, $t7, 0x8000
    ctx->r15 = ctx->r15 | 0X8000;
    // 0x8002C388: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8002C38C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8002C390: lui         $t0, 0x7C0
    ctx->r8 = S32(0X7C0 << 16);
    // 0x8002C394: ori         $t0, $t0, 0x650
    ctx->r8 = ctx->r8 | 0X650;
    // 0x8002C398: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8002C39C: b           L_8002C3D4
    // 0x8002C3A0: nop

        goto L_8002C3D4;
    // 0x8002C3A0: nop

L_8002C3A4:
    // 0x8002C3A4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8002C3A8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8002C3AC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8002C3B0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8002C3B4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C3B8: lui         $t4, 0xC00
    ctx->r12 = S32(0XC00 << 16);
    // 0x8002C3BC: ori         $t4, $t4, 0x7FFF
    ctx->r12 = ctx->r12 | 0X7FFF;
    // 0x8002C3C0: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8002C3C4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C3C8: lui         $t6, 0x7C0
    ctx->r14 = S32(0X7C0 << 16);
    // 0x8002C3CC: ori         $t6, $t6, 0x650
    ctx->r14 = ctx->r14 | 0X650;
    // 0x8002C3D0: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
L_8002C3D4:
    // 0x8002C3D4: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8002C3D8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8002C3DC: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8002C3E0: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8002C3E4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8002C3E8: lui         $t0, 0xC00
    ctx->r8 = S32(0XC00 << 16);
    // 0x8002C3EC: ori         $t0, $t0, 0x7FFF
    ctx->r8 = ctx->r8 | 0X7FFF;
    // 0x8002C3F0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8002C3F4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8002C3F8: lui         $t2, 0x7C0
    ctx->r10 = S32(0X7C0 << 16);
    // 0x8002C3FC: ori         $t2, $t2, 0x4E0
    ctx->r10 = ctx->r10 | 0X4E0;
    // 0x8002C400: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
L_8002C404:
    // 0x8002C404: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x8002C408: lw          $t4, 0x11F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X11F4);
    // 0x8002C40C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8002C410: lw          $t5, 0x34($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X34);
    // 0x8002C414: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x8002C418: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x8002C41C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8002C420: addu        $t7, $t5, $t9
    ctx->r15 = ADD32(ctx->r13, ctx->r25);
    // 0x8002C424: lw          $t8, 0x44($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X44);
    // 0x8002C428: lh          $t0, 0x2($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X2);
    // 0x8002C42C: blez        $t0, L_8002C558
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8002C430: nop
    
            goto L_8002C558;
    }
    // 0x8002C430: nop

    // 0x8002C434: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8002C438: lw          $t1, 0x11F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X11F4);
    // 0x8002C43C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8002C440: lw          $t2, 0x34($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34);
    // 0x8002C444: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8002C448: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8002C44C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8002C450: addu        $t6, $t2, $t4
    ctx->r14 = ADD32(ctx->r10, ctx->r12);
    // 0x8002C454: lw          $t5, 0x44($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X44);
    // 0x8002C458: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8002C45C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8002C460: lw          $t7, 0x28($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X28);
    // 0x8002C464: beq         $t7, $zero, L_8002C494
    if (ctx->r15 == 0) {
        // 0x8002C468: nop
    
            goto L_8002C494;
    }
    // 0x8002C468: nop

    // 0x8002C46C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002C470: lw          $t8, 0x11F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11F4);
    // 0x8002C474: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002C478: lw          $t0, 0x40($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X40);
    // 0x8002C47C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8002C480: nop

    // 0x8002C484: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002C488: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8002C48C: jal         0x80028C04
    // 0x8002C490: nop

    func_80028C04(rdram, ctx);
        goto after_1;
    // 0x8002C490: nop

    after_1:
L_8002C494:
    // 0x8002C494: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8002C498: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x8002C49C: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8002C4A0: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8002C4A4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8002C4A8: lui         $t2, 0xB00
    ctx->r10 = S32(0XB00 << 16);
    // 0x8002C4AC: ori         $t2, $t2, 0x20
    ctx->r10 = ctx->r10 | 0X20;
    // 0x8002C4B0: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8002C4B4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002C4B8: jal         0x8002E330
    // 0x8002C4BC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x8002C4BC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_2:
    // 0x8002C4C0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8002C4C4: sw          $v0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r2;
    // 0x8002C4C8: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002C4CC: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x8002C4D0: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8002C4D4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8002C4D8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C4DC: lui         $t7, 0xE00
    ctx->r15 = S32(0XE00 << 16);
    // 0x8002C4E0: ori         $t7, $t7, 0x4E0
    ctx->r15 = ctx->r15 | 0X4E0;
    // 0x8002C4E4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8002C4E8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8002C4EC: jal         0x8002E330
    // 0x8002C4F0: lw          $a0, 0x2C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X2C);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x8002C4F0: lw          $a0, 0x2C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X2C);
    after_3:
    // 0x8002C4F4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002C4F8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C4FC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002C500: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x8002C504: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8002C508: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
    // 0x8002C50C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8002C510: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x8002C514: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8002C518: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8002C51C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8002C520: lui         $t5, 0xE00
    ctx->r13 = S32(0XE00 << 16);
    // 0x8002C524: ori         $t5, $t5, 0x650
    ctx->r13 = ctx->r13 | 0X650;
    // 0x8002C528: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x8002C52C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8002C530: jal         0x8002E330
    // 0x8002C534: lw          $a0, 0x30($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X30);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x8002C534: lw          $a0, 0x30($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X30);
    after_4:
    // 0x8002C538: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002C53C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8002C540: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002C544: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x8002C548: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x8002C54C: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8002C550: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8002C554: sw          $zero, 0x28($t3)
    MEM_W(0X28, ctx->r11) = 0;
L_8002C558:
    // 0x8002C558: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8002C55C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002C560: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x8002C564: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x8002C568: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8002C56C: lw          $t5, 0x3C($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X3C);
    // 0x8002C570: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002C574: bne         $at, $zero, L_8002C28C
    if (ctx->r1 != 0) {
        // 0x8002C578: nop
    
            goto L_8002C28C;
    }
    // 0x8002C578: nop

L_8002C57C:
    // 0x8002C57C: b           L_8002C58C
    // 0x8002C580: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
        goto L_8002C58C;
    // 0x8002C580: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8002C584: b           L_8002C58C
    // 0x8002C588: nop

        goto L_8002C58C;
    // 0x8002C588: nop

L_8002C58C:
    // 0x8002C58C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C590: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8002C594: jr          $ra
    // 0x8002C598: nop

    return;
    // 0x8002C598: nop

    // 0x8002C59C: nop

;}
RECOMP_FUNC void func_80800038_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: lh          $t6, 0x8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8);
    // 0x8080003C: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x80800040: subu        $v1, $a1, $t6
    ctx->r3 = SUB32(ctx->r5, ctx->r14);
    // 0x80800044: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800048: bne         $at, $zero, L_80800058
    if (ctx->r1 != 0) {
        // 0x8080004C: nop
    
            goto L_80800058;
    }
    // 0x8080004C: nop

    // 0x80800050: jr          $ra
    // 0x80800054: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80800054: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800058:
    // 0x80800058: bgez        $v1, L_80800068
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8080005C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80800068;
    }
    // 0x8080005C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800060: jr          $ra
    // 0x80800064: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80800064: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800068:
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void func_800DF6BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF6BC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800DF6C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF6C4: sw          $t6, -0x37C4($at)
    MEM_W(-0X37C4, ctx->r1) = ctx->r14;
    // 0x800DF6C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DF6CC: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x800DF6D0: bne         $at, $zero, L_800DF6E0
    if (ctx->r1 != 0) {
        // 0x800DF6D4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800DF6E0;
    }
    // 0x800DF6D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DF6D8: b           L_800DF6E4
    // 0x800DF6DC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_800DF6E4;
    // 0x800DF6DC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800DF6E0:
    // 0x800DF6E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800DF6E4:
    // 0x800DF6E4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800DF6E8: addiu       $v1, $v1, -0x3678
    ctx->r3 = ADD32(ctx->r3, -0X3678);
    // 0x800DF6EC: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x800DF6F0: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x800DF6F4: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x800DF6F8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800DF6FC: jal         0x800DF410
    // 0x800DF700: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800DF410(rdram, ctx);
        goto after_0;
    // 0x800DF700: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800DF704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DF708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DF70C: jr          $ra
    // 0x800DF710: nop

    return;
    // 0x800DF710: nop

;}
RECOMP_FUNC void _dbzone_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087938: syscall     640
    recomp_syscall_handler(rdram, ctx, 0x80087938);
    return;
    // 0x8008793C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800FC508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC508: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FC50C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FC510: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800FC514: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FC518: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800FC51C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800FC520: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800FC524: bne         $a1, $s0, L_800FC538
    if (ctx->r5 != ctx->r16) {
        // 0x800FC528: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_800FC538;
    }
    // 0x800FC528: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800FC52C: jal         0x80017764
    // 0x800FC530: nop

    func_80017764(rdram, ctx);
        goto after_0;
    // 0x800FC530: nop

    after_0:
    // 0x800FC534: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_800FC538:
    // 0x800FC538: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800FC53C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800FC540: bne         $t7, $s0, L_800FC54C
    if (ctx->r15 != ctx->r16) {
        // 0x800FC544: nop
    
            goto L_800FC54C;
    }
    // 0x800FC544: nop

    // 0x800FC548: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_800FC54C:
    // 0x800FC54C: jal         0x800FB5F8
    // 0x800FC550: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FB5F8(rdram, ctx);
        goto after_1;
    // 0x800FC550: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800FC554: beq         $v0, $zero, L_800FC604
    if (ctx->r2 == 0) {
        // 0x800FC558: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FC604;
    }
    // 0x800FC558: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FC55C: lh          $t9, 0x28($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X28);
    // 0x800FC560: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800FC564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FC568: bltz        $t9, L_800FC578
    if (SIGNED(ctx->r25) < 0) {
        // 0x800FC56C: nop
    
            goto L_800FC578;
    }
    // 0x800FC56C: nop

    // 0x800FC570: beql        $t0, $zero, L_800FC5CC
    if (ctx->r8 == 0) {
        // 0x800FC574: lbu         $t5, 0x34($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X34);
            goto L_800FC5CC;
    }
    goto skip_0;
    // 0x800FC574: lbu         $t5, 0x34($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X34);
    skip_0:
L_800FC578:
    // 0x800FC578: jal         0x800FB6E0
    // 0x800FC57C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800FB6E0(rdram, ctx);
        goto after_2;
    // 0x800FC57C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800FC580: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800FC584: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FC588: sh          $zero, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = 0;
    // 0x800FC58C: sb          $zero, 0x31($s0)
    MEM_B(0X31, ctx->r16) = 0;
    // 0x800FC590: sh          $t1, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r9;
    // 0x800FC594: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x800FC598: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800FC59C: jal         0x800FB6C0
    // 0x800FC5A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FB6C0(rdram, ctx);
        goto after_3;
    // 0x800FC5A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800FC5A4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800FC5A8: addiu       $t2, $t2, 0x57D0
    ctx->r10 = ADD32(ctx->r10, 0X57D0);
    // 0x800FC5AC: subu        $a0, $s0, $t2
    ctx->r4 = SUB32(ctx->r16, ctx->r10);
    // 0x800FC5B0: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x800FC5B4: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x800FC5B8: mflo        $t3
    ctx->r11 = lo;
    // 0x800FC5BC: andi        $a0, $t3, 0xFF
    ctx->r4 = ctx->r11 & 0XFF;
    // 0x800FC5C0: jal         0x800172D4
    // 0x800FC5C4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800172D4(rdram, ctx);
        goto after_4;
    // 0x800FC5C4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x800FC5C8: lbu         $t5, 0x34($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X34);
L_800FC5CC:
    // 0x800FC5CC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FC5D0: addiu       $t6, $t6, 0x57D0
    ctx->r14 = ADD32(ctx->r14, 0X57D0);
    // 0x800FC5D4: bne         $t5, $zero, L_800FC5F4
    if (ctx->r13 != 0) {
        // 0x800FC5D8: subu        $a0, $s0, $t6
        ctx->r4 = SUB32(ctx->r16, ctx->r14);
            goto L_800FC5F4;
    }
    // 0x800FC5D8: subu        $a0, $s0, $t6
    ctx->r4 = SUB32(ctx->r16, ctx->r14);
    // 0x800FC5DC: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x800FC5E0: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x800FC5E4: mflo        $t7
    ctx->r15 = lo;
    // 0x800FC5E8: andi        $a0, $t7, 0xFF
    ctx->r4 = ctx->r15 & 0XFF;
    // 0x800FC5EC: jal         0x80017404
    // 0x800FC5F0: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    func_80017404(rdram, ctx);
        goto after_5;
    // 0x800FC5F0: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    after_5:
L_800FC5F4:
    // 0x800FC5F4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800FC5F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FC5FC: jal         0x800FB540
    // 0x800FC600: sw          $t9, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r25;
    func_800FB540(rdram, ctx);
        goto after_6;
    // 0x800FC600: sw          $t9, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r25;
    after_6:
L_800FC604:
    // 0x800FC604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC608: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FC60C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FC610: jr          $ra
    // 0x800FC614: nop

    return;
    // 0x800FC614: nop

;}
RECOMP_FUNC void func_80800000_chmole_maya(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1596, 0X1E0) << 16);
    // 0x8080000C: jal         0x800899E8
    // 0x80800010: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1596, 0X1E0));
    _sumole_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1596, 0X1E0));
    after_0:
    // 0x80800014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080001C: jr          $ra
    // 0x80800020: nop

    return;
    // 0x80800020: nop

;}
RECOMP_FUNC void func_800E6AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6AFC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800E6B00: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x800E6B04: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800E6B08: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800E6B0C: beq         $t7, $zero, L_800E6B24
    if (ctx->r15 == 0) {
        // 0x800E6B10: addiu       $t9, $zero, 0x30
        ctx->r25 = ADD32(0, 0X30);
            goto L_800E6B24;
    }
    // 0x800E6B10: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x800E6B14: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
L_800E6B18:
    // 0x800E6B18: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E6B1C: bnel        $t8, $zero, L_800E6B18
    if (ctx->r24 != 0) {
        // 0x800E6B20: lbu         $t8, 0x1($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X1);
            goto L_800E6B18;
    }
    goto skip_0;
    // 0x800E6B20: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    skip_0:
L_800E6B24:
    // 0x800E6B24: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x800E6B28: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x800E6B2C: sb          $t0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r8;
    // 0x800E6B30: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800E6B34: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800E6B38: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_800E6B3C:
    // 0x800E6B3C: srav        $v0, $v1, $a2
    ctx->r2 = S32(SIGNED(ctx->r3) >> (ctx->r6 & 31));
    // 0x800E6B40: andi        $t1, $v0, 0xF
    ctx->r9 = ctx->r2 & 0XF;
    // 0x800E6B44: slti        $t2, $t1, 0xA
    ctx->r10 = SIGNED(ctx->r9) < 0XA ? 1 : 0;
    // 0x800E6B48: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x800E6B4C: beq         $t3, $zero, L_800E6B60
    if (ctx->r11 == 0) {
        // 0x800E6B50: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_800E6B60;
    }
    // 0x800E6B50: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800E6B54: addiu       $t4, $t1, 0x30
    ctx->r12 = ADD32(ctx->r9, 0X30);
    // 0x800E6B58: b           L_800E6B68
    // 0x800E6B5C: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
        goto L_800E6B68;
    // 0x800E6B5C: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
L_800E6B60:
    // 0x800E6B60: addiu       $t5, $v0, 0x57
    ctx->r13 = ADD32(ctx->r2, 0X57);
    // 0x800E6B64: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
L_800E6B68:
    // 0x800E6B68: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800E6B6C: bgez        $a2, L_800E6B3C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800E6B70: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800E6B3C;
    }
    // 0x800E6B70: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E6B74: jr          $ra
    // 0x800E6B78: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    return;
    // 0x800E6B78: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void bamovespline_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002FC: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x80800300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800304: jal         0x808000F4
    // 0x80800308: sb          $zero, 0x90($t6)
    MEM_B(0X90, ctx->r14) = 0;
    func_808000F4_bamovespline(rdram, ctx);
        goto after_0;
    // 0x80800308: sb          $zero, 0x90($t6)
    MEM_B(0X90, ctx->r14) = 0;
    after_0:
    // 0x8080030C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800314: jr          $ra
    // 0x80800318: nop

    return;
    // 0x80800318: nop

;}
RECOMP_FUNC void func_80800A1C_chcaptainblubber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A1C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80800A20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A24: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800A28: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x80800A2C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800A30: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2228, 0X1654) << 16);
    // 0x80800A34: addiu       $at, $zero, 0x159
    ctx->r1 = ADD32(0, 0X159);
    // 0x80800A38: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800A3C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80800A40: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x80800A44: lhu         $v1, 0x1654($v1)
    ctx->r3 = MEM_HU(ctx->r3, (int16_t)RELOC_LO16(2228, 0X1654));
    // 0x80800A48: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2228, 0X16E8) << 16);
    // 0x80800A4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A50: beq         $v1, $at, L_80800A9C
    if (ctx->r3 == ctx->r1) {
        // 0x80800A54: addiu       $t9, $t9, 0x16E8
        ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2228, 0X16E8));
            goto L_80800A9C;
    }
    // 0x80800A54: addiu       $t9, $t9, 0x16E8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2228, 0X16E8));
    // 0x80800A58: addiu       $at, $zero, 0x15A
    ctx->r1 = ADD32(0, 0X15A);
    // 0x80800A5C: beq         $v1, $at, L_80800DE4
    if (ctx->r3 == ctx->r1) {
        // 0x80800A60: lui         $t2, 0x8080
        ctx->r10 = S32(RELOC_HI16(2228, 0X16F8) << 16);
            goto L_80800DE4;
    }
    // 0x80800A60: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2228, 0X16F8) << 16);
    // 0x80800A64: addiu       $at, $zero, 0x16D
    ctx->r1 = ADD32(0, 0X16D);
    // 0x80800A68: beq         $v1, $at, L_808012B0
    if (ctx->r3 == ctx->r1) {
        // 0x80800A6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808012B0;
    }
    // 0x80800A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A70: addiu       $at, $zero, 0x17B
    ctx->r1 = ADD32(0, 0X17B);
    // 0x80800A74: beq         $v1, $at, L_80801154
    if (ctx->r3 == ctx->r1) {
        // 0x80800A78: lui         $t1, 0x8080
        ctx->r9 = S32(RELOC_HI16(2228, 0X171C) << 16);
            goto L_80801154;
    }
    // 0x80800A78: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2228, 0X171C) << 16);
    // 0x80800A7C: addiu       $at, $zero, 0x1BF
    ctx->r1 = ADD32(0, 0X1BF);
    // 0x80800A80: beq         $v1, $at, L_80801050
    if (ctx->r3 == ctx->r1) {
        // 0x80800A84: lui         $t3, 0x8080
        ctx->r11 = S32(RELOC_HI16(2228, 0X1710) << 16);
            goto L_80801050;
    }
    // 0x80800A84: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2228, 0X1710) << 16);
    // 0x80800A88: addiu       $at, $zero, 0x1C0
    ctx->r1 = ADD32(0, 0X1C0);
    // 0x80800A8C: beq         $v1, $at, L_80800CC8
    if (ctx->r3 == ctx->r1) {
        // 0x80800A90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CC8;
    }
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A94: b           L_808013C8
    // 0x80800A98: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
        goto L_808013C8;
    // 0x80800A98: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
L_80800A9C:
    // 0x80800A9C: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80800AA0: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    // 0x80800AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA8: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80800AAC: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80800AB0: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x80800AB4: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x80800AB8: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x80800ABC: lw          $t1, 0xC($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XC);
    // 0x80800AC0: jal         0x80101E4C
    // 0x80800AC4: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
    func_80101E4C(rdram, ctx);
        goto after_0;
    // 0x80800AC4: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
    after_0:
    // 0x80800AC8: beq         $v0, $zero, L_80800C60
    if (ctx->r2 == 0) {
        // 0x80800ACC: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2228, 0X15E8) << 16);
            goto L_80800C60;
    }
    // 0x80800ACC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X15E8) << 16);
    // 0x80800AD0: lwc1        $f12, 0x15E8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X15E8));
    // 0x80800AD4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X15EC) << 16);
    // 0x80800AD8: jal         0x800DC178
    // 0x80800ADC: lwc1        $f14, 0x15EC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X15EC));
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800ADC: lwc1        $f14, 0x15EC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X15EC));
    after_1:
    // 0x80800AE0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X15F0) << 16);
    // 0x80800AE4: lwc1        $f4, 0x15F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X15F0));
    // 0x80800AE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800AEC: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800AF0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800AF4: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800AF8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800AFC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800B00: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80800B04: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800B08: nop

    // 0x80800B0C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800B10: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800B14: nop

    // 0x80800B18: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800B1C: beql        $a0, $zero, L_80800B6C
    if (ctx->r4 == 0) {
        // 0x80800B20: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_80800B6C;
    }
    goto skip_0;
    // 0x80800B20: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x80800B24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800B28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800B2C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800B30: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800B34: nop

    // 0x80800B38: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80800B3C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800B40: nop

    // 0x80800B44: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800B48: bne         $a0, $zero, L_80800B60
    if (ctx->r4 != 0) {
        // 0x80800B4C: nop
    
            goto L_80800B60;
    }
    // 0x80800B4C: nop

    // 0x80800B50: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80800B54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800B58: b           L_80800B78
    // 0x80800B5C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80800B78;
    // 0x80800B5C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80800B60:
    // 0x80800B60: b           L_80800B78
    // 0x80800B64: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80800B78;
    // 0x80800B64: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800B68: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_80800B6C:
    // 0x80800B6C: nop

    // 0x80800B70: bltz        $a0, L_80800B60
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800B74: nop
    
            goto L_80800B60;
    }
    // 0x80800B74: nop

L_80800B78:
    // 0x80800B78: or          $t3, $a0, $zero
    ctx->r11 = ctx->r4 | 0;
    // 0x80800B7C: lui         $at, 0x11
    ctx->r1 = S32(0X11 << 16);
    // 0x80800B80: ori         $at, $at, 0x9564
    ctx->r1 = ctx->r1 | 0X9564;
    // 0x80800B84: sll         $t4, $t3, 21
    ctx->r12 = S32(ctx->r11 << 21);
    // 0x80800B88: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80800B8C: addu        $a0, $t4, $at
    ctx->r4 = ADD32(ctx->r12, ctx->r1);
    // 0x80800B90: jal         0x800C4140
    // 0x80800B94: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800C4140(rdram, ctx);
        goto after_2;
    // 0x80800B94: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800B98: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X15F4) << 16);
    // 0x80800B9C: lwc1        $f12, 0x15F4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X15F4));
    // 0x80800BA0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X15F8) << 16);
    // 0x80800BA4: jal         0x800DC178
    // 0x80800BA8: lwc1        $f14, 0x15F8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X15F8));
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800BA8: lwc1        $f14, 0x15F8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X15F8));
    after_3:
    // 0x80800BAC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X15FC) << 16);
    // 0x80800BB0: lwc1        $f10, 0x15FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X15FC));
    // 0x80800BB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800BB8: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800BBC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800BC0: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800BC4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800BC8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BCC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80800BD0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800BD4: nop

    // 0x80800BD8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800BDC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800BE0: nop

    // 0x80800BE4: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800BE8: beql        $a0, $zero, L_80800C38
    if (ctx->r4 == 0) {
        // 0x80800BEC: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_80800C38;
    }
    goto skip_1;
    // 0x80800BEC: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x80800BF0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800BF4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800BF8: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800BFC: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800C00: nop

    // 0x80800C04: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80800C08: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800C0C: nop

    // 0x80800C10: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800C14: bne         $a0, $zero, L_80800C2C
    if (ctx->r4 != 0) {
        // 0x80800C18: nop
    
            goto L_80800C2C;
    }
    // 0x80800C18: nop

    // 0x80800C1C: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80800C20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800C24: b           L_80800C44
    // 0x80800C28: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80800C44;
    // 0x80800C28: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80800C2C:
    // 0x80800C2C: b           L_80800C44
    // 0x80800C30: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80800C44;
    // 0x80800C30: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800C34: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_80800C38:
    // 0x80800C38: nop

    // 0x80800C3C: bltz        $a0, L_80800C2C
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800C40: nop
    
            goto L_80800C2C;
    }
    // 0x80800C40: nop

L_80800C44:
    // 0x80800C44: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80800C48: lui         $at, 0x11
    ctx->r1 = S32(0X11 << 16);
    // 0x80800C4C: ori         $at, $at, 0x9614
    ctx->r1 = ctx->r1 | 0X9614;
    // 0x80800C50: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x80800C54: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80800C58: jal         0x800C4140
    // 0x80800C5C: addu        $a0, $t7, $at
    ctx->r4 = ADD32(ctx->r15, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_4;
    // 0x80800C5C: addu        $a0, $t7, $at
    ctx->r4 = ADD32(ctx->r15, ctx->r1);
    after_4:
L_80800C60:
    // 0x80800C60: lui         $a1, 0x3E61
    ctx->r5 = S32(0X3E61 << 16);
    // 0x80800C64: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    // 0x80800C68: jal         0x80101E14
    // 0x80800C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_5;
    // 0x80800C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800C70: beq         $v0, $zero, L_80800C98
    if (ctx->r2 == 0) {
        // 0x80800C74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C98;
    }
    // 0x80800C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C78: lui         $a0, 0x4CB1
    ctx->r4 = S32(0X4CB1 << 16);
    // 0x80800C7C: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800C80: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800C84: ori         $a0, $a0, 0x94E3
    ctx->r4 = ctx->r4 | 0X94E3;
    // 0x80800C88: jal         0x800C4140
    // 0x80800C8C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_6;
    // 0x80800C8C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x80800C90: b           L_808013C8
    // 0x80800C94: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
        goto L_808013C8;
    // 0x80800C94: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
L_80800C98:
    // 0x80800C98: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80800C9C: jal         0x80101E14
    // 0x80800CA0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_7;
    // 0x80800CA0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_7:
    // 0x80800CA4: beq         $v0, $zero, L_808013C4
    if (ctx->r2 == 0) {
        // 0x80800CA8: lui         $a0, 0x4CB1
        ctx->r4 = S32(0X4CB1 << 16);
            goto L_808013C4;
    }
    // 0x80800CA8: lui         $a0, 0x4CB1
    ctx->r4 = S32(0X4CB1 << 16);
    // 0x80800CAC: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800CB0: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800CB4: ori         $a0, $a0, 0x94E4
    ctx->r4 = ctx->r4 | 0X94E4;
    // 0x80800CB8: jal         0x800C4140
    // 0x80800CBC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_8;
    // 0x80800CBC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x80800CC0: b           L_808013C8
    // 0x80800CC4: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
        goto L_808013C8;
    // 0x80800CC4: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
L_80800CC8:
    // 0x80800CC8: lui         $a1, 0x3E0F
    ctx->r5 = S32(0X3E0F << 16);
    // 0x80800CCC: jal         0x80101E14
    // 0x80800CD0: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    func_80101E14(rdram, ctx);
        goto after_9;
    // 0x80800CD0: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    after_9:
    // 0x80800CD4: beq         $v0, $zero, L_80800CFC
    if (ctx->r2 == 0) {
        // 0x80800CD8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CFC;
    }
    // 0x80800CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CDC: lui         $a0, 0x7FF1
    ctx->r4 = S32(0X7FF1 << 16);
    // 0x80800CE0: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800CE4: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800CE8: ori         $a0, $a0, 0x9612
    ctx->r4 = ctx->r4 | 0X9612;
    // 0x80800CEC: jal         0x800C4140
    // 0x80800CF0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_10;
    // 0x80800CF0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_10:
    // 0x80800CF4: b           L_808013C8
    // 0x80800CF8: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
        goto L_808013C8;
    // 0x80800CF8: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
L_80800CFC:
    // 0x80800CFC: lui         $a1, 0x3F0C
    ctx->r5 = S32(0X3F0C << 16);
    // 0x80800D00: jal         0x80101E14
    // 0x80800D04: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_11;
    // 0x80800D04: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_11:
    // 0x80800D08: beq         $v0, $zero, L_808013C4
    if (ctx->r2 == 0) {
        // 0x80800D0C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_808013C4;
    }
    // 0x80800D0C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800D10: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1600) << 16);
    // 0x80800D14: lwc1        $f12, 0x1600($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1600));
    // 0x80800D18: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1604) << 16);
    // 0x80800D1C: sw          $t8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r24;
    // 0x80800D20: jal         0x800DC178
    // 0x80800D24: lwc1        $f14, 0x1604($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1604));
    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x80800D24: lwc1        $f14, 0x1604($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1604));
    after_12:
    // 0x80800D28: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1608) << 16);
    // 0x80800D2C: lwc1        $f4, 0x1608($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1608));
    // 0x80800D30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800D34: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800D38: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800D3C: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800D40: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800D44: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800D48: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80800D4C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800D50: nop

    // 0x80800D54: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800D58: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800D5C: nop

    // 0x80800D60: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800D64: beql        $a0, $zero, L_80800DB4
    if (ctx->r4 == 0) {
        // 0x80800D68: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_80800DB4;
    }
    goto skip_2;
    // 0x80800D68: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x80800D6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800D70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800D74: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800D78: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800D7C: nop

    // 0x80800D80: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80800D84: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800D88: nop

    // 0x80800D8C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800D90: bne         $a0, $zero, L_80800DA8
    if (ctx->r4 != 0) {
        // 0x80800D94: nop
    
            goto L_80800DA8;
    }
    // 0x80800D94: nop

    // 0x80800D98: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80800D9C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800DA0: b           L_80800DC0
    // 0x80800DA4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80800DC0;
    // 0x80800DA4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80800DA8:
    // 0x80800DA8: b           L_80800DC0
    // 0x80800DAC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80800DC0;
    // 0x80800DAC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800DB0: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_80800DB4:
    // 0x80800DB4: nop

    // 0x80800DB8: bltz        $a0, L_80800DA8
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800DBC: nop
    
            goto L_80800DA8;
    }
    // 0x80800DBC: nop

L_80800DC0:
    // 0x80800DC0: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x80800DC4: lui         $at, 0x1B
    ctx->r1 = S32(0X1B << 16);
    // 0x80800DC8: ori         $at, $at, 0x5C50
    ctx->r1 = ctx->r1 | 0X5C50;
    // 0x80800DCC: sll         $t1, $t9, 21
    ctx->r9 = S32(ctx->r25 << 21);
    // 0x80800DD0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80800DD4: jal         0x800C4140
    // 0x80800DD8: addu        $a0, $t1, $at
    ctx->r4 = ADD32(ctx->r9, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_13;
    // 0x80800DD8: addu        $a0, $t1, $at
    ctx->r4 = ADD32(ctx->r9, ctx->r1);
    after_13:
    // 0x80800DDC: b           L_808013C8
    // 0x80800DE0: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
        goto L_808013C8;
    // 0x80800DE0: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
L_80800DE4:
    // 0x80800DE4: addiu       $t2, $t2, 0x16F8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2228, 0X16F8));
    // 0x80800DE8: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80800DEC: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x80800DF0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2228, 0X1704) << 16);
    // 0x80800DF4: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80800DF8: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80800DFC: addiu       $t7, $t7, 0x1704
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2228, 0X1704));
    // 0x80800E00: addiu       $t6, $sp, 0x84
    ctx->r14 = ADD32(ctx->r29, 0X84);
    // 0x80800E04: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x80800E08: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x80800E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E10: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x80800E14: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800E18: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80800E1C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800E20: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800E24: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80800E28: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80800E2C: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    // 0x80800E30: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800E34: srl         $t4, $t1, 10
    ctx->r12 = S32(U32(ctx->r9) >> 10);
    // 0x80800E38: bne         $t4, $at, L_80800F14
    if (ctx->r12 != ctx->r1) {
        // 0x80800E3C: nop
    
            goto L_80800F14;
    }
    // 0x80800E3C: nop

    // 0x80800E40: lui         $a1, 0x3E75
    ctx->r5 = S32(0X3E75 << 16);
    // 0x80800E44: jal         0x80101E14
    // 0x80800E48: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    func_80101E14(rdram, ctx);
        goto after_14;
    // 0x80800E48: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    after_14:
    // 0x80800E4C: beq         $v0, $zero, L_80800F60
    if (ctx->r2 == 0) {
        // 0x80800E50: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2228, 0X160C) << 16);
            goto L_80800F60;
    }
    // 0x80800E50: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X160C) << 16);
    // 0x80800E54: lwc1        $f12, 0x160C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X160C));
    // 0x80800E58: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1610) << 16);
    // 0x80800E5C: jal         0x800DC178
    // 0x80800E60: lwc1        $f14, 0x1610($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1610));
    func_800DC178(rdram, ctx);
        goto after_15;
    // 0x80800E60: lwc1        $f14, 0x1610($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1610));
    after_15:
    // 0x80800E64: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1614) << 16);
    // 0x80800E68: lwc1        $f10, 0x1614($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1614));
    // 0x80800E6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800E70: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800E74: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800E78: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80800E7C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800E80: nop

    // 0x80800E84: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800E88: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800E8C: nop

    // 0x80800E90: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800E94: beql        $a0, $zero, L_80800EE4
    if (ctx->r4 == 0) {
        // 0x80800E98: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_80800EE4;
    }
    goto skip_3;
    // 0x80800E98: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_3:
    // 0x80800E9C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800EA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800EA4: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800EA8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800EAC: nop

    // 0x80800EB0: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80800EB4: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800EB8: nop

    // 0x80800EBC: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800EC0: bne         $a0, $zero, L_80800ED8
    if (ctx->r4 != 0) {
        // 0x80800EC4: nop
    
            goto L_80800ED8;
    }
    // 0x80800EC4: nop

    // 0x80800EC8: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80800ECC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800ED0: b           L_80800EF0
    // 0x80800ED4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80800EF0;
    // 0x80800ED4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80800ED8:
    // 0x80800ED8: b           L_80800EF0
    // 0x80800EDC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80800EF0;
    // 0x80800EDC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800EE0: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_80800EE4:
    // 0x80800EE4: nop

    // 0x80800EE8: bltz        $a0, L_80800ED8
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800EEC: nop
    
            goto L_80800ED8;
    }
    // 0x80800EEC: nop

L_80800EF0:
    // 0x80800EF0: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x80800EF4: lui         $at, 0x9
    ctx->r1 = S32(0X9 << 16);
    // 0x80800EF8: ori         $at, $at, 0xC612
    ctx->r1 = ctx->r1 | 0XC612;
    // 0x80800EFC: sll         $t5, $t2, 21
    ctx->r13 = S32(ctx->r10 << 21);
    // 0x80800F00: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80800F04: jal         0x800C3F48
    // 0x80800F08: addu        $a0, $t5, $at
    ctx->r4 = ADD32(ctx->r13, ctx->r1);
    func_800C3F48(rdram, ctx);
        goto after_16;
    // 0x80800F08: addu        $a0, $t5, $at
    ctx->r4 = ADD32(ctx->r13, ctx->r1);
    after_16:
    // 0x80800F0C: b           L_80800F64
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800F64;
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F14:
    // 0x80800F14: jal         0x80101E4C
    // 0x80800F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_17;
    // 0x80800F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800F1C: beql        $v0, $zero, L_80800F64
    if (ctx->r2 == 0) {
        // 0x80800F20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F64;
    }
    goto skip_4;
    // 0x80800F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80800F24: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    // 0x80800F28: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800F2C: lui         $a0, 0x7FE7
    ctx->r4 = S32(0X7FE7 << 16);
    // 0x80800F30: srl         $t8, $t0, 10
    ctx->r24 = S32(U32(ctx->r8) >> 10);
    // 0x80800F34: bne         $t8, $at, L_80800F50
    if (ctx->r24 != ctx->r1) {
        // 0x80800F38: ori         $a0, $a0, 0xD612
        ctx->r4 = ctx->r4 | 0XD612;
            goto L_80800F50;
    }
    // 0x80800F38: ori         $a0, $a0, 0xD612
    ctx->r4 = ctx->r4 | 0XD612;
    // 0x80800F3C: lui         $a0, 0x7FE7
    ctx->r4 = S32(0X7FE7 << 16);
    // 0x80800F40: jal         0x800C3F48
    // 0x80800F44: ori         $a0, $a0, 0xD612
    ctx->r4 = ctx->r4 | 0XD612;
    func_800C3F48(rdram, ctx);
        goto after_18;
    // 0x80800F44: ori         $a0, $a0, 0xD612
    ctx->r4 = ctx->r4 | 0XD612;
    after_18:
    // 0x80800F48: b           L_80800F64
    // 0x80800F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800F64;
    // 0x80800F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F50:
    // 0x80800F50: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800F54: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800F58: jal         0x800C4140
    // 0x80800F5C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_19;
    // 0x80800F5C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_19:
L_80800F60:
    // 0x80800F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F64:
    // 0x80800F64: jal         0x80101E4C
    // 0x80800F68: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    func_80101E4C(rdram, ctx);
        goto after_20;
    // 0x80800F68: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    after_20:
    // 0x80800F6C: beq         $v0, $zero, L_808013C4
    if (ctx->r2 == 0) {
        // 0x80800F70: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808013C4;
    }
    // 0x80800F70: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800F74: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1618) << 16);
    // 0x80800F78: lwc1        $f12, 0x1618($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1618));
    // 0x80800F7C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X161C) << 16);
    // 0x80800F80: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x80800F84: sw          $t6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r14;
    // 0x80800F88: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80800F8C: jal         0x800DC178
    // 0x80800F90: lwc1        $f14, 0x161C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X161C));
    func_800DC178(rdram, ctx);
        goto after_21;
    // 0x80800F90: lwc1        $f14, 0x161C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X161C));
    after_21:
    // 0x80800F94: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1620) << 16);
    // 0x80800F98: lwc1        $f4, 0x1620($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1620));
    // 0x80800F9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800FA0: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800FA4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800FA8: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800FAC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800FB0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800FB4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800FB8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800FBC: nop

    // 0x80800FC0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800FC4: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800FC8: nop

    // 0x80800FCC: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800FD0: beql        $a0, $zero, L_80801020
    if (ctx->r4 == 0) {
        // 0x80800FD4: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_80801020;
    }
    goto skip_5;
    // 0x80800FD4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_5:
    // 0x80800FD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800FDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800FE0: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800FE4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800FE8: nop

    // 0x80800FEC: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80800FF0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800FF4: nop

    // 0x80800FF8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800FFC: bne         $a0, $zero, L_80801014
    if (ctx->r4 != 0) {
        // 0x80801000: nop
    
            goto L_80801014;
    }
    // 0x80801000: nop

    // 0x80801004: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80801008: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080100C: b           L_8080102C
    // 0x80801010: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_8080102C;
    // 0x80801010: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80801014:
    // 0x80801014: b           L_8080102C
    // 0x80801018: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_8080102C;
    // 0x80801018: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8080101C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_80801020:
    // 0x80801020: nop

    // 0x80801024: bltz        $a0, L_80801014
    if (SIGNED(ctx->r4) < 0) {
        // 0x80801028: nop
    
            goto L_80801014;
    }
    // 0x80801028: nop

L_8080102C:
    // 0x8080102C: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x80801030: lui         $at, 0x17
    ctx->r1 = S32(0X17 << 16);
    // 0x80801034: ori         $at, $at, 0x7450
    ctx->r1 = ctx->r1 | 0X7450;
    // 0x80801038: sll         $t4, $t1, 21
    ctx->r12 = S32(ctx->r9 << 21);
    // 0x8080103C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80801040: jal         0x800C4140
    // 0x80801044: addu        $a0, $t4, $at
    ctx->r4 = ADD32(ctx->r12, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_22;
    // 0x80801044: addu        $a0, $t4, $at
    ctx->r4 = ADD32(ctx->r12, ctx->r1);
    after_22:
    // 0x80801048: b           L_808013C8
    // 0x8080104C: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
        goto L_808013C8;
    // 0x8080104C: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
L_80801050:
    // 0x80801050: addiu       $t3, $t3, 0x1710
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(2228, 0X1710));
    // 0x80801054: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80801058: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x8080105C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801060: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80801064: lw          $t0, 0x4($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X4);
    // 0x80801068: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x8080106C: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80801070: jal         0x80101E4C
    // 0x80801074: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    func_80101E4C(rdram, ctx);
        goto after_23;
    // 0x80801074: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    after_23:
    // 0x80801078: beq         $v0, $zero, L_808013C4
    if (ctx->r2 == 0) {
        // 0x8080107C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_808013C4;
    }
    // 0x8080107C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801080: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1624) << 16);
    // 0x80801084: lwc1        $f12, 0x1624($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1624));
    // 0x80801088: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1628) << 16);
    // 0x8080108C: sw          $t8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r24;
    // 0x80801090: jal         0x800DC178
    // 0x80801094: lwc1        $f14, 0x1628($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1628));
    func_800DC178(rdram, ctx);
        goto after_24;
    // 0x80801094: lwc1        $f14, 0x1628($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1628));
    after_24:
    // 0x80801098: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X162C) << 16);
    // 0x8080109C: lwc1        $f10, 0x162C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X162C));
    // 0x808010A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808010A4: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x808010A8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808010AC: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x808010B0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808010B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808010B8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x808010BC: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808010C0: nop

    // 0x808010C4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x808010C8: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808010CC: nop

    // 0x808010D0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808010D4: beql        $a0, $zero, L_80801124
    if (ctx->r4 == 0) {
        // 0x808010D8: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_80801124;
    }
    goto skip_6;
    // 0x808010D8: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_6:
    // 0x808010DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808010E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808010E4: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x808010E8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808010EC: nop

    // 0x808010F0: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x808010F4: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808010F8: nop

    // 0x808010FC: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801100: bne         $a0, $zero, L_80801118
    if (ctx->r4 != 0) {
        // 0x80801104: nop
    
            goto L_80801118;
    }
    // 0x80801104: nop

    // 0x80801108: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8080110C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801110: b           L_80801130
    // 0x80801114: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80801130;
    // 0x80801114: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80801118:
    // 0x80801118: b           L_80801130
    // 0x8080111C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80801130;
    // 0x8080111C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80801120: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_80801124:
    // 0x80801124: nop

    // 0x80801128: bltz        $a0, L_80801118
    if (SIGNED(ctx->r4) < 0) {
        // 0x8080112C: nop
    
            goto L_80801118;
    }
    // 0x8080112C: nop

L_80801130:
    // 0x80801130: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x80801134: lui         $at, 0x11
    ctx->r1 = S32(0X11 << 16);
    // 0x80801138: ori         $at, $at, 0x9451
    ctx->r1 = ctx->r1 | 0X9451;
    // 0x8080113C: sll         $t9, $t7, 21
    ctx->r25 = S32(ctx->r15 << 21);
    // 0x80801140: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80801144: jal         0x800C4140
    // 0x80801148: addu        $a0, $t9, $at
    ctx->r4 = ADD32(ctx->r25, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_25;
    // 0x80801148: addu        $a0, $t9, $at
    ctx->r4 = ADD32(ctx->r25, ctx->r1);
    after_25:
    // 0x8080114C: b           L_808013C8
    // 0x80801150: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
        goto L_808013C8;
    // 0x80801150: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
L_80801154:
    // 0x80801154: addiu       $t1, $t1, 0x171C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2228, 0X171C));
    // 0x80801158: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8080115C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80801160: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2228, 0X1738) << 16);
    // 0x80801164: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80801168: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8080116C: addiu       $t0, $t0, 0x1738
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2228, 0X1738));
    // 0x80801170: addiu       $t3, $sp, 0x50
    ctx->r11 = ADD32(ctx->r29, 0X50);
    // 0x80801174: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x80801178: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x8080117C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801180: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x80801184: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80801188: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x8080118C: lw          $at, 0x10($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X10);
    // 0x80801190: sw          $at, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r1;
    // 0x80801194: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80801198: sw          $t2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r10;
    // 0x8080119C: lw          $at, 0x18($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X18);
    // 0x808011A0: sw          $at, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r1;
    // 0x808011A4: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x808011A8: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x808011AC: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x808011B0: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x808011B4: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x808011B8: jal         0x80101E4C
    // 0x808011BC: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    func_80101E4C(rdram, ctx);
        goto after_26;
    // 0x808011BC: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    after_26:
    // 0x808011C0: beq         $v0, $zero, L_808013C4
    if (ctx->r2 == 0) {
        // 0x808011C4: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_808013C4;
    }
    // 0x808011C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808011C8: sw          $t9, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r25;
    // 0x808011CC: addiu       $a0, $zero, 0x36B0
    ctx->r4 = ADD32(0, 0X36B0);
    // 0x808011D0: jal         0x800DC128
    // 0x808011D4: addiu       $a1, $zero, 0x3E81
    ctx->r5 = ADD32(0, 0X3E81);
    func_800DC128(rdram, ctx);
        goto after_27;
    // 0x808011D4: addiu       $a1, $zero, 0x3E81
    ctx->r5 = ADD32(0, 0X3E81);
    after_27:
    // 0x808011D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1630) << 16);
    // 0x808011DC: lwc1        $f12, 0x1630($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1630));
    // 0x808011E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1634) << 16);
    // 0x808011E4: lwc1        $f14, 0x1634($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1634));
    // 0x808011E8: jal         0x800DC178
    // 0x808011EC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800DC178(rdram, ctx);
        goto after_28;
    // 0x808011EC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_28:
    // 0x808011F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1638) << 16);
    // 0x808011F4: lwc1        $f4, 0x1638($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1638));
    // 0x808011F8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808011FC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80801200: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801204: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80801208: sra         $t6, $v1, 5
    ctx->r14 = S32(SIGNED(ctx->r3) >> 5);
    // 0x8080120C: andi        $t8, $t6, 0x3FF
    ctx->r24 = ctx->r14 & 0X3FF;
    // 0x80801210: sll         $t3, $t8, 11
    ctx->r11 = S32(ctx->r24 << 11);
    // 0x80801214: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80801218: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080121C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80801220: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80801224: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801228: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8080122C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80801230: nop

    // 0x80801234: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80801238: beql        $t4, $zero, L_80801288
    if (ctx->r12 == 0) {
        // 0x8080123C: mfc1        $t4, $f8
        ctx->r12 = (int32_t)ctx->f8.u32l;
            goto L_80801288;
    }
    goto skip_7;
    // 0x8080123C: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    skip_7:
    // 0x80801240: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801244: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80801248: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8080124C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80801250: nop

    // 0x80801254: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80801258: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8080125C: nop

    // 0x80801260: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80801264: bne         $t4, $zero, L_8080127C
    if (ctx->r12 != 0) {
        // 0x80801268: nop
    
            goto L_8080127C;
    }
    // 0x80801268: nop

    // 0x8080126C: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x80801270: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801274: b           L_80801294
    // 0x80801278: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_80801294;
    // 0x80801278: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_8080127C:
    // 0x8080127C: b           L_80801294
    // 0x80801280: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_80801294;
    // 0x80801280: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80801284: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
L_80801288:
    // 0x80801288: nop

    // 0x8080128C: bltz        $t4, L_8080127C
    if (SIGNED(ctx->r12) < 0) {
        // 0x80801290: nop
    
            goto L_8080127C;
    }
    // 0x80801290: nop

L_80801294:
    // 0x80801294: sll         $t2, $t4, 21
    ctx->r10 = S32(ctx->r12 << 21);
    // 0x80801298: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x8080129C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x808012A0: jal         0x800C4140
    // 0x808012A4: addiu       $a0, $a0, 0x451
    ctx->r4 = ADD32(ctx->r4, 0X451);
    func_800C4140(rdram, ctx);
        goto after_29;
    // 0x808012A4: addiu       $a0, $a0, 0x451
    ctx->r4 = ADD32(ctx->r4, 0X451);
    after_29:
    // 0x808012A8: b           L_808013C8
    // 0x808012AC: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
        goto L_808013C8;
    // 0x808012AC: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
L_808012B0:
    // 0x808012B0: lui         $a1, 0x3D8F
    ctx->r5 = S32(0X3D8F << 16);
    // 0x808012B4: jal         0x80101E14
    // 0x808012B8: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    func_80101E14(rdram, ctx);
        goto after_30;
    // 0x808012B8: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    after_30:
    // 0x808012BC: beq         $v0, $zero, L_808012E4
    if (ctx->r2 == 0) {
        // 0x808012C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808012E4;
    }
    // 0x808012C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012C4: lui         $a0, 0x7FF1
    ctx->r4 = S32(0X7FF1 << 16);
    // 0x808012C8: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x808012CC: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x808012D0: ori         $a0, $a0, 0x9612
    ctx->r4 = ctx->r4 | 0X9612;
    // 0x808012D4: jal         0x800C4140
    // 0x808012D8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_31;
    // 0x808012D8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_31:
    // 0x808012DC: b           L_808013C8
    // 0x808012E0: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
        goto L_808013C8;
    // 0x808012E0: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
L_808012E4:
    // 0x808012E4: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x808012E8: jal         0x80101E14
    // 0x808012EC: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    func_80101E14(rdram, ctx);
        goto after_32;
    // 0x808012EC: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    after_32:
    // 0x808012F0: beq         $v0, $zero, L_808013C4
    if (ctx->r2 == 0) {
        // 0x808012F4: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_808013C4;
    }
    // 0x808012F4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808012F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X163C) << 16);
    // 0x808012FC: lwc1        $f12, 0x163C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X163C));
    // 0x80801300: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1640) << 16);
    // 0x80801304: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
    // 0x80801308: jal         0x800DC178
    // 0x8080130C: lwc1        $f14, 0x1640($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1640));
    func_800DC178(rdram, ctx);
        goto after_33;
    // 0x8080130C: lwc1        $f14, 0x1640($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1640));
    after_33:
    // 0x80801310: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1644) << 16);
    // 0x80801314: lwc1        $f10, 0x1644($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1644));
    // 0x80801318: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080131C: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80801320: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80801324: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80801328: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080132C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801330: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80801334: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801338: nop

    // 0x8080133C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80801340: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801344: nop

    // 0x80801348: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8080134C: beql        $a0, $zero, L_8080139C
    if (ctx->r4 == 0) {
        // 0x80801350: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_8080139C;
    }
    goto skip_8;
    // 0x80801350: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_8:
    // 0x80801354: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801358: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080135C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80801360: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801364: nop

    // 0x80801368: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8080136C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801370: nop

    // 0x80801374: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801378: bne         $a0, $zero, L_80801390
    if (ctx->r4 != 0) {
        // 0x8080137C: nop
    
            goto L_80801390;
    }
    // 0x8080137C: nop

    // 0x80801380: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80801384: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801388: b           L_808013A8
    // 0x8080138C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_808013A8;
    // 0x8080138C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80801390:
    // 0x80801390: b           L_808013A8
    // 0x80801394: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_808013A8;
    // 0x80801394: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80801398: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_8080139C:
    // 0x8080139C: nop

    // 0x808013A0: bltz        $a0, L_80801390
    if (SIGNED(ctx->r4) < 0) {
        // 0x808013A4: nop
    
            goto L_80801390;
    }
    // 0x808013A4: nop

L_808013A8:
    // 0x808013A8: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x808013AC: lui         $at, 0x9
    ctx->r1 = S32(0X9 << 16);
    // 0x808013B0: ori         $at, $at, 0xC451
    ctx->r1 = ctx->r1 | 0XC451;
    // 0x808013B4: sll         $t5, $t9, 21
    ctx->r13 = S32(ctx->r25 << 21);
    // 0x808013B8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x808013BC: jal         0x800C4140
    // 0x808013C0: addu        $a0, $t5, $at
    ctx->r4 = ADD32(ctx->r13, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_34;
    // 0x808013C0: addu        $a0, $t5, $at
    ctx->r4 = ADD32(ctx->r13, ctx->r1);
    after_34:
L_808013C4:
    // 0x808013C4: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
L_808013C8:
    // 0x808013C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013CC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x808013D0: beql        $t4, $zero, L_8080142C
    if (ctx->r12 == 0) {
        // 0x808013D4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080142C;
    }
    goto skip_9;
    // 0x808013D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_9:
    // 0x808013D8: jal         0x8008A0D0
    // 0x808013DC: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_35;
    // 0x808013DC: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_35:
    // 0x808013E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013E4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808013E8: jal         0x8008A0D0
    // 0x808013EC: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_36;
    // 0x808013EC: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_36:
    // 0x808013F0: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2228, 0X1744) << 16);
    // 0x808013F4: addiu       $s0, $s0, 0x1744
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2228, 0X1744));
    // 0x808013F8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x808013FC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80801400: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801404: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801408: jal         0x800BBCB8
    // 0x8080140C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_37;
    // 0x8080140C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_37:
    // 0x80801410: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80801414: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801418: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080141C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801420: jal         0x800BBCB8
    // 0x80801424: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_800BBCB8(rdram, ctx);
        goto after_38;
    // 0x80801424: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_38:
    // 0x80801428: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080142C:
    // 0x8080142C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801430: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x80801434: jr          $ra
    // 0x80801438: nop

    return;
    // 0x80801438: nop

;}
RECOMP_FUNC void bsrest_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800430: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800438: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080043C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800440: jal         0x80084688
    // 0x80800444: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    _badata_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800444: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80800448: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080044C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800450: jal         0x8080020C
    // 0x80800454: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    static_344_8080020C(rdram, ctx);
        goto after_1;
    // 0x80800454: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080045C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800460: jr          $ra
    // 0x80800464: nop

    return;
    // 0x80800464: nop

;}
RECOMP_FUNC void suegg_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A6C: jr          $ra
    // 0x80800A70: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800A70: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
