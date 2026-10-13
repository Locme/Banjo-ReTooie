#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800874_cheggproximity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800874: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80800878: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8080087C: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80800880: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80800884: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x80800888: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x8080088C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80800890: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80800894: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80800898: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8080089C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x808008A0: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x808008A4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808008A8: jal         0x80100094
    // 0x808008AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008B0: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x808008B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808008B8: jal         0x80100094
    // 0x808008BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808008BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808008C0: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x808008C4: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x808008C8: jal         0x800F5898
    // 0x808008CC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_2;
    // 0x808008CC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_2:
    // 0x808008D0: blez        $v0, L_80800AC4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808008D4: lui         $at, 0x43C8
        ctx->r1 = S32(0X43C8 << 16);
            goto L_80800AC4;
    }
    // 0x808008D4: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808008D8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808008DC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808008E0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808008E4: addiu       $s7, $sp, 0x60
    ctx->r23 = ADD32(ctx->r29, 0X60);
    // 0x808008E8: lhu         $t6, 0x72($s5)
    ctx->r14 = MEM_HU(ctx->r21, 0X72);
L_808008EC:
    // 0x808008EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808008F0: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x808008F4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808008F8: bne         $t7, $at, L_8080090C
    if (ctx->r15 != ctx->r1) {
        // 0x808008FC: lw          $t8, 0x7C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X7C);
            goto L_8080090C;
    }
    // 0x808008FC: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x80800900: lh          $t9, 0x3A($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X3A);
    // 0x80800904: beq         $s2, $t9, L_80800AB0
    if (ctx->r18 == ctx->r25) {
        // 0x80800908: nop
    
            goto L_80800AB0;
    }
    // 0x80800908: nop

L_8080090C:
    // 0x8080090C: lw          $t0, 0xA4($s6)
    ctx->r8 = MEM_W(ctx->r22, 0XA4);
    // 0x80800910: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800914: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x80800918: bne         $t0, $zero, L_80800AB0
    if (ctx->r8 != 0) {
        // 0x8080091C: nop
    
            goto L_80800AB0;
    }
    // 0x8080091C: nop

    // 0x80800920: jal         0x800F6438
    // 0x80800924: addu        $s3, $s6, $t1
    ctx->r19 = ADD32(ctx->r22, ctx->r9);
    func_800F6438(rdram, ctx);
        goto after_3;
    // 0x80800924: addu        $s3, $s6, $t1
    ctx->r19 = ADD32(ctx->r22, ctx->r9);
    after_3:
    // 0x80800928: beql        $v0, $zero, L_80800AA8
    if (ctx->r2 == 0) {
        // 0x8080092C: lw          $t4, 0x40($s3)
        ctx->r12 = MEM_W(ctx->r19, 0X40);
            goto L_80800AA8;
    }
    goto skip_0;
    // 0x8080092C: lw          $t4, 0x40($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X40);
    skip_0:
    // 0x80800930: jal         0x800F6CC8
    // 0x80800934: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800F6CC8(rdram, ctx);
        goto after_4;
    // 0x80800934: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x80800938: bne         $v0, $zero, L_80800AA4
    if (ctx->r2 != 0) {
        // 0x8080093C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800AA4;
    }
    // 0x8080093C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800940: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80800944: jal         0x800F5A00
    // 0x80800948: addiu       $s1, $s5, 0x4
    ctx->r17 = ADD32(ctx->r21, 0X4);
    func_800F5A00(rdram, ctx);
        goto after_5;
    // 0x80800948: addiu       $s1, $s5, 0x4
    ctx->r17 = ADD32(ctx->r21, 0X4);
    after_5:
    // 0x8080094C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800950: jal         0x800EFC7C
    // 0x80800954: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_6;
    // 0x80800954: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x80800958: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8080095C: lwc1        $f6, 0x8($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X8);
    // 0x80800960: swc1        $f0, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->f0.u32l;
    // 0x80800964: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2220, 0XCD8) << 16);
    // 0x80800968: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8080096C: swc1        $f2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
    // 0x80800970: lwc1        $f8, 0xCD8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2220, 0XCD8));
    // 0x80800974: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2220, 0XCDC) << 16);
    // 0x80800978: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8080097C: nop

    // 0x80800980: bc1t        L_808009C8
    if (c1cs) {
        // 0x80800984: nop
    
            goto L_808009C8;
    }
    // 0x80800984: nop

    // 0x80800988: lwc1        $f10, 0xCDC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2220, 0XCDC));
    // 0x8080098C: lui         $at, 0x4561
    ctx->r1 = S32(0X4561 << 16);
    // 0x80800990: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800994: nop

    // 0x80800998: bc1fl       L_808009AC
    if (!c1cs) {
        // 0x8080099C: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_808009AC;
    }
    goto skip_1;
    // 0x8080099C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_1:
    // 0x808009A0: b           L_808009C8
    // 0x808009A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_808009C8;
    // 0x808009A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808009A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_808009AC:
    // 0x808009AC: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x808009B0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x808009B4: nop

    // 0x808009B8: bc1f        L_808009C8
    if (!c1cs) {
        // 0x808009BC: nop
    
            goto L_808009C8;
    }
    // 0x808009BC: nop

    // 0x808009C0: b           L_808009C8
    // 0x808009C4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_808009C8;
    // 0x808009C4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_808009C8:
    // 0x808009C8: beq         $s0, $zero, L_80800A40
    if (ctx->r16 == 0) {
        // 0x808009CC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800A40;
    }
    // 0x808009CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808009D0: beq         $s0, $at, L_80800A18
    if (ctx->r16 == ctx->r1) {
        // 0x808009D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800A18;
    }
    // 0x808009D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808009D8: bne         $s0, $at, L_80800A68
    if (ctx->r16 != ctx->r1) {
        // 0x808009DC: lui         $at, 0x432F
        ctx->r1 = S32(0X432F << 16);
            goto L_80800A68;
    }
    // 0x808009DC: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x808009E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808009E4: neg.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = -ctx->f2.fl;
    // 0x808009E8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808009EC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x808009F0: nop

    // 0x808009F4: bc1fl       L_80800A18
    if (!c1cs) {
        // 0x808009F8: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_80800A18;
    }
    goto skip_2;
    // 0x808009F8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    skip_2:
    // 0x808009FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A00: nop

    // 0x80800A04: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80800A08: nop

    // 0x80800A0C: bc1tl       L_80800A6C
    if (c1cs) {
        // 0x80800A10: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80800A6C;
    }
    goto skip_3;
    // 0x80800A10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_3:
    // 0x80800A14: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80800A18:
    // 0x80800A18: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x80800A1C: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x80800A20: nop

    // 0x80800A24: bc1fl       L_80800A40
    if (!c1cs) {
        // 0x80800A28: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800A40;
    }
    goto skip_4;
    // 0x80800A28: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_4:
    // 0x80800A2C: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x80800A30: nop

    // 0x80800A34: bc1tl       L_80800A6C
    if (c1cs) {
        // 0x80800A38: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80800A6C;
    }
    goto skip_5;
    // 0x80800A38: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_5:
    // 0x80800A3C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800A40:
    // 0x80800A40: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x80800A44: c.lt.s      $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f10.fl < ctx->f22.fl;
    // 0x80800A48: nop

    // 0x80800A4C: bc1fl       L_80800A68
    if (!c1cs) {
        // 0x80800A50: addiu       $s0, $zero, -0x1
        ctx->r16 = ADD32(0, -0X1);
            goto L_80800A68;
    }
    goto skip_6;
    // 0x80800A50: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    skip_6:
    // 0x80800A54: c.lt.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl < ctx->f22.fl;
    // 0x80800A58: nop

    // 0x80800A5C: bc1tl       L_80800A6C
    if (c1cs) {
        // 0x80800A60: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80800A6C;
    }
    goto skip_7;
    // 0x80800A60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_7:
    // 0x80800A64: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_80800A68:
    // 0x80800A68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80800A6C:
    // 0x80800A6C: beql        $s0, $at, L_80800AA8
    if (ctx->r16 == ctx->r1) {
        // 0x80800A70: lw          $t4, 0x40($s3)
        ctx->r12 = MEM_W(ctx->r19, 0X40);
            goto L_80800AA8;
    }
    goto skip_8;
    // 0x80800A70: lw          $t4, 0x40($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X40);
    skip_8:
    // 0x80800A74: bgez        $s4, L_80800A84
    if (SIGNED(ctx->r20) >= 0) {
        // 0x80800A78: sll         $t2, $s4, 2
        ctx->r10 = S32(ctx->r20 << 2);
            goto L_80800A84;
    }
    // 0x80800A78: sll         $t2, $s4, 2
    ctx->r10 = S32(ctx->r20 << 2);
    // 0x80800A7C: b           L_80800AA4
    // 0x80800A80: or          $s4, $s2, $zero
    ctx->r20 = ctx->r18 | 0;
        goto L_80800AA4;
    // 0x80800A80: or          $s4, $s2, $zero
    ctx->r20 = ctx->r18 | 0;
L_80800A84:
    // 0x80800A84: addu        $t3, $s6, $t2
    ctx->r11 = ADD32(ctx->r22, ctx->r10);
    // 0x80800A88: lwc1        $f18, 0x20($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X20);
    // 0x80800A8C: lwc1        $f16, 0x20($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X20);
    // 0x80800A90: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80800A94: nop

    // 0x80800A98: bc1fl       L_80800AA8
    if (!c1cs) {
        // 0x80800A9C: lw          $t4, 0x40($s3)
        ctx->r12 = MEM_W(ctx->r19, 0X40);
            goto L_80800AA8;
    }
    goto skip_9;
    // 0x80800A9C: lw          $t4, 0x40($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X40);
    skip_9:
    // 0x80800AA0: or          $s4, $s2, $zero
    ctx->r20 = ctx->r18 | 0;
L_80800AA4:
    // 0x80800AA4: lw          $t4, 0x40($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X40);
L_80800AA8:
    // 0x80800AA8: sw          $s0, 0x40($s3)
    MEM_W(0X40, ctx->r19) = ctx->r16;
    // 0x80800AAC: sw          $t4, 0x60($s3)
    MEM_W(0X60, ctx->r19) = ctx->r12;
L_80800AB0:
    // 0x80800AB0: jal         0x800F5898
    // 0x80800AB4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    func_800F5898(rdram, ctx);
        goto after_7;
    // 0x80800AB4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    after_7:
    // 0x80800AB8: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800ABC: bnel        $at, $zero, L_808008EC
    if (ctx->r1 != 0) {
        // 0x80800AC0: lhu         $t6, 0x72($s5)
        ctx->r14 = MEM_HU(ctx->r21, 0X72);
            goto L_808008EC;
    }
    goto skip_10;
    // 0x80800AC0: lhu         $t6, 0x72($s5)
    ctx->r14 = MEM_HU(ctx->r21, 0X72);
    skip_10:
L_80800AC4:
    // 0x80800AC4: sw          $s4, 0xA0($s6)
    MEM_W(0XA0, ctx->r22) = ctx->r20;
    // 0x80800AC8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800ACC: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x80800AD0: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x80800AD4: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80800AD8: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80800ADC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80800AE0: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AE4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800AE8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800AEC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800AF0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800AF4: jr          $ra
    // 0x80800AF8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80800AF8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_80800368_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800368: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080036C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800370: jal         0x80106790
    // 0x80800374: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800374: nop

    after_0:
    // 0x80800378: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080037C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800380: jal         0x80100094
    // 0x80800384: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800384: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800388: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080038C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800390: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x80800394: lw          $a2, 0x24($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X24);
    // 0x80800398: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080039C: addiu       $a1, $zero, 0x55C
    ctx->r5 = ADD32(0, 0X55C);
    // 0x808003A0: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x808003A4: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x808003A8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x808003AC: addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
    // 0x808003B0: lhu         $a0, 0x4($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X4);
    // 0x808003B4: addu        $t4, $a3, $t0
    ctx->r12 = ADD32(ctx->r7, ctx->r8);
    // 0x808003B8: beq         $a0, $at, L_808003D8
    if (ctx->r4 == ctx->r1) {
        // 0x808003BC: addiu       $at, $zero, 0x1FFF
        ctx->r1 = ADD32(0, 0X1FFF);
            goto L_808003D8;
    }
    // 0x808003BC: addiu       $at, $zero, 0x1FFF
    ctx->r1 = ADD32(0, 0X1FFF);
    // 0x808003C0: bnel        $a0, $at, L_808003E8
    if (ctx->r4 != ctx->r1) {
        // 0x808003C4: lb          $a0, 0x0($v1)
        ctx->r4 = MEM_B(ctx->r3, 0X0);
            goto L_808003E8;
    }
    goto skip_0;
    // 0x808003C4: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    skip_0:
    // 0x808003C8: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x808003CC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808003D0: b           L_808003E4
    // 0x808003D4: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
        goto L_808003E4;
    // 0x808003D4: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_808003D8:
    // 0x808003D8: lb          $t9, 0x0($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X0);
    // 0x808003DC: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x808003E0: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
L_808003E4:
    // 0x808003E4: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
L_808003E8:
    // 0x808003E8: bgez        $a0, L_808003F8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x808003EC: addiu       $t2, $a0, 0x4
        ctx->r10 = ADD32(ctx->r4, 0X4);
            goto L_808003F8;
    }
    // 0x808003EC: addiu       $t2, $a0, 0x4
    ctx->r10 = ADD32(ctx->r4, 0X4);
    // 0x808003F0: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x808003F4: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
L_808003F8:
    // 0x808003F8: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x808003FC: bne         $at, $zero, L_80800408
    if (ctx->r1 != 0) {
        // 0x80800400: addiu       $t3, $a0, -0x4
        ctx->r11 = ADD32(ctx->r4, -0X4);
            goto L_80800408;
    }
    // 0x80800400: addiu       $t3, $a0, -0x4
    ctx->r11 = ADD32(ctx->r4, -0X4);
    // 0x80800404: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
L_80800408:
    // 0x80800408: swc1        $f4, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f4.u32l;
    // 0x8080040C: jal         0x808007E4
    // 0x80800410: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_2;
    // 0x80800410: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x80800414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800418: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080041C: jr          $ra
    // 0x80800420: nop

    return;
    // 0x80800420: nop

;}
RECOMP_FUNC void gsmaker_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F8: jal         0x80800058
    // 0x808000FC: addiu       $a0, $a0, 0x955
    ctx->r4 = ADD32(ctx->r4, 0X955);
    gsmaker_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808000FC: addiu       $a0, $a0, 0x955
    ctx->r4 = ADD32(ctx->r4, 0X955);
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
RECOMP_FUNC void func_8010CEF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CEF8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8010CEFC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8010CF00: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8010CF04: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8010CF08: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8010CF0C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8010CF10: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8010CF14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8010CF18: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010CF1C: jal         0x800F54E4
    // 0x8010CF20: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8010CF20: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010CF24: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8010CF28: jal         0x800F57C0
    // 0x8010CF2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F57C0(rdram, ctx);
        goto after_1;
    // 0x8010CF2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8010CF30: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8010CF34: blez        $v0, L_8010CF94
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8010CF38: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8010CF94;
    }
    // 0x8010CF38: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8010CF3C: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8010CF40: addiu       $s2, $s1, 0x4
    ctx->r18 = ADD32(ctx->r17, 0X4);
    // 0x8010CF44: addiu       $s1, $sp, 0x54
    ctx->r17 = ADD32(ctx->r29, 0X54);
    // 0x8010CF48: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8010CF4C: nop

    // 0x8010CF50: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010CF54: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_8010CF58:
    // 0x8010CF58: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8010CF5C: jal         0x800F5794
    // 0x8010CF60: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800F5794(rdram, ctx);
        goto after_2;
    // 0x8010CF60: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x8010CF64: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010CF68: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8010CF6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8010CF70: jal         0x800F0008
    // 0x8010CF74: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800F0008(rdram, ctx);
        goto after_3;
    // 0x8010CF74: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_3:
    // 0x8010CF78: beq         $v0, $zero, L_8010CF88
    if (ctx->r2 == 0) {
        // 0x8010CF7C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8010CF88;
    }
    // 0x8010CF7C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8010CF80: b           L_8010CF98
    // 0x8010CF84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010CF98;
    // 0x8010CF84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010CF88:
    // 0x8010CF88: slt         $at, $s0, $s4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8010CF8C: bnel        $at, $zero, L_8010CF58
    if (ctx->r1 != 0) {
        // 0x8010CF90: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8010CF58;
    }
    goto skip_0;
    // 0x8010CF90: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
L_8010CF94:
    // 0x8010CF94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010CF98:
    // 0x8010CF98: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8010CF9C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010CFA0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8010CFA4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8010CFA8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8010CFAC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8010CFB0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8010CFB4: jr          $ra
    // 0x8010CFB8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8010CFB8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _subaddiefade_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089CC0: syscall     808
    recomp_syscall_handler(rdram, ctx, 0x80089CC0);
    return;
    // 0x80089CC4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void mlMtxApply(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018C28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018C2C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80018C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018C34: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80018C38: jal         0x8002ED00
    // 0x80018C3C: lw          $a0, -0x4350($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4350);
    guMtxF2L(rdram, ctx);
        goto after_0;
    // 0x80018C3C: lw          $a0, -0x4350($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4350);
    after_0:
    // 0x80018C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80018C48: jr          $ra
    // 0x80018C4C: nop

    return;
    // 0x80018C4C: nop

;}
RECOMP_FUNC void func_80802340_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802340: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802344: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802348: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080234C: jal         0x801022E4
    // 0x80802350: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_801022E4(rdram, ctx);
        goto after_0;
    // 0x80802350: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80802354: addiu       $at, $zero, 0x330
    ctx->r1 = ADD32(0, 0X330);
    // 0x80802358: beq         $v0, $at, L_808023B0
    if (ctx->r2 == ctx->r1) {
        // 0x8080235C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808023B0;
    }
    // 0x8080235C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802360: addiu       $at, $zero, 0x33F
    ctx->r1 = ADD32(0, 0X33F);
    // 0x80802364: beq         $v0, $at, L_80802400
    if (ctx->r2 == ctx->r1) {
        // 0x80802368: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802400;
    }
    // 0x80802368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080236C: addiu       $at, $zero, 0x3EC
    ctx->r1 = ADD32(0, 0X3EC);
    // 0x80802370: bne         $v0, $at, L_8080241C
    if (ctx->r2 != ctx->r1) {
        // 0x80802374: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080241C;
    }
    // 0x80802374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802378: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8080237C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80802380: jal         0x80102320
    // 0x80802384: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_80102320(rdram, ctx);
        goto after_1;
    // 0x80802384: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_1:
    // 0x80802388: beq         $v0, $zero, L_8080241C
    if (ctx->r2 == 0) {
        // 0x8080238C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1332, 0X2D6C) << 16);
            goto L_8080241C;
    }
    // 0x8080238C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2D6C) << 16);
    // 0x80802390: jal         0x800DC298
    // 0x80802394: lwc1        $f12, 0x2D6C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2D6C));
    func_800DC298(rdram, ctx);
        goto after_2;
    // 0x80802394: lwc1        $f12, 0x2D6C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2D6C));
    after_2:
    // 0x80802398: beql        $v0, $zero, L_80802420
    if (ctx->r2 == 0) {
        // 0x8080239C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802420;
    }
    goto skip_0;
    // 0x8080239C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808023A0: jal         0x80802430
    // 0x808023A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802430_changlerboss(rdram, ctx);
        goto after_3;
    // 0x808023A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808023A8: b           L_80802420
    // 0x808023AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802420;
    // 0x808023AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808023B0:
    // 0x808023B0: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    // 0x808023B4: jal         0x80102320
    // 0x808023B8: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    func_80102320(rdram, ctx);
        goto after_4;
    // 0x808023B8: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    after_4:
    // 0x808023BC: beq         $v0, $zero, L_808023DC
    if (ctx->r2 == 0) {
        // 0x808023C0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1332, 0X2D70) << 16);
            goto L_808023DC;
    }
    // 0x808023C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2D70) << 16);
    // 0x808023C4: jal         0x800DC298
    // 0x808023C8: lwc1        $f12, 0x2D70($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2D70));
    func_800DC298(rdram, ctx);
        goto after_5;
    // 0x808023C8: lwc1        $f12, 0x2D70($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2D70));
    after_5:
    // 0x808023CC: beq         $v0, $zero, L_808023DC
    if (ctx->r2 == 0) {
        // 0x808023D0: nop
    
            goto L_808023DC;
    }
    // 0x808023D0: nop

    // 0x808023D4: jal         0x80802430
    // 0x808023D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802430_changlerboss(rdram, ctx);
        goto after_6;
    // 0x808023D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_808023DC:
    // 0x808023DC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1332, 0X2FF8) << 16);
    // 0x808023E0: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x808023E4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808023E8: addiu       $a2, $a2, 0x2FF8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1332, 0X2FF8));
    // 0x808023EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808023F0: jal         0x80089D20
    // 0x808023F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x808023F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x808023F8: b           L_80802420
    // 0x808023FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802420;
    // 0x808023FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802400:
    // 0x80802400: lui         $a1, 0x3F59
    ctx->r5 = S32(0X3F59 << 16);
    // 0x80802404: jal         0x80101E14
    // 0x80802408: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_80101E14(rdram, ctx);
        goto after_8;
    // 0x80802408: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_8:
    // 0x8080240C: beql        $v0, $zero, L_80802420
    if (ctx->r2 == 0) {
        // 0x80802410: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802420;
    }
    goto skip_1;
    // 0x80802410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80802414: jal         0x80802430
    // 0x80802418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802430_changlerboss(rdram, ctx);
        goto after_9;
    // 0x80802418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_8080241C:
    // 0x8080241C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802420:
    // 0x80802420: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802428: jr          $ra
    // 0x8080242C: nop

    return;
    // 0x8080242C: nop

;}
RECOMP_FUNC void func_80800838_chblackeye(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800838: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080083C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800840: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800844: lw          $t6, 0x70($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X70);
    // 0x80800848: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080084C: sll         $t8, $t6, 28
    ctx->r24 = S32(ctx->r14 << 28);
    // 0x80800850: bgezl       $t8, L_80800BB4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800854: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800BB4;
    }
    goto skip_0;
    // 0x80800854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800858: jal         0x80100094
    // 0x8080085C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080085C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800860: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800864: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800868: jal         0x800897D8
    // 0x8080086C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x8080086C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800870: jal         0x8080003C
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080003C_chblackeye(rdram, ctx);
        goto after_2;
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800878: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x8080087C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800880: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x80800884: beq         $t9, $at, L_808008A4
    if (ctx->r25 == ctx->r1) {
        // 0x80800888: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808008A4;
    }
    // 0x80800888: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080088C: beq         $t9, $at, L_80800960
    if (ctx->r25 == ctx->r1) {
        // 0x80800890: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800960;
    }
    // 0x80800890: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800894: beq         $t9, $at, L_80800A90
    if (ctx->r25 == ctx->r1) {
        // 0x80800898: addiu       $a0, $s0, 0x28
        ctx->r4 = ADD32(ctx->r16, 0X28);
            goto L_80800A90;
    }
    // 0x80800898: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8080089C: b           L_80800A9C
    // 0x808008A0: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
        goto L_80800A9C;
    // 0x808008A0: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
L_808008A4:
    // 0x808008A4: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008AC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1796, 0XFB8) << 16);
    // 0x808008B0: sll         $t2, $t0, 19
    ctx->r10 = S32(ctx->r8 << 19);
    // 0x808008B4: bgez        $t2, L_808008D4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x808008B8: nop
    
            goto L_808008D4;
    }
    // 0x808008B8: nop

    // 0x808008BC: jal         0x80101E4C
    // 0x808008C0: addiu       $a1, $a1, 0xFB8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0XFB8));
    func_80101E4C(rdram, ctx);
        goto after_3;
    // 0x808008C0: addiu       $a1, $a1, 0xFB8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0XFB8));
    after_3:
    // 0x808008C4: beq         $v0, $zero, L_808008D4
    if (ctx->r2 == 0) {
        // 0x808008C8: nop
    
            goto L_808008D4;
    }
    // 0x808008C8: nop

    // 0x808008CC: jal         0x8080061C
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080061C_chblackeye(rdram, ctx);
        goto after_4;
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_808008D4:
    // 0x808008D4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1796, 0XFF8) << 16);
    // 0x808008D8: addiu       $a1, $a1, 0xFF8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0XFF8));
    // 0x808008DC: jal         0x80101E4C
    // 0x808008E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_5;
    // 0x808008E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808008E4: beq         $v0, $zero, L_80800904
    if (ctx->r2 == 0) {
        // 0x808008E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800904;
    }
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008EC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1796, 0XE00) << 16);
    // 0x808008F0: addiu       $a1, $a1, 0xE00
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0XE00));
    // 0x808008F4: jal         0x80800000
    // 0x808008F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chblackeye(rdram, ctx);
        goto after_6;
    // 0x808008F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808008FC: b           L_80800928
    // 0x80800900: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
        goto L_80800928;
    // 0x80800900: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
L_80800904:
    // 0x80800904: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1796, 0X1004) << 16);
    // 0x80800908: jal         0x80101E4C
    // 0x8080090C: addiu       $a1, $a1, 0x1004
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0X1004));
    func_80101E4C(rdram, ctx);
        goto after_7;
    // 0x8080090C: addiu       $a1, $a1, 0x1004
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0X1004));
    after_7:
    // 0x80800910: beq         $v0, $zero, L_80800924
    if (ctx->r2 == 0) {
        // 0x80800914: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800924;
    }
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800918: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1796, 0XE50) << 16);
    // 0x8080091C: jal         0x80800000
    // 0x80800920: addiu       $a1, $a1, 0xE50
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0XE50));
    func_80800000_chblackeye(rdram, ctx);
        goto after_8;
    // 0x80800920: addiu       $a1, $a1, 0xE50
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0XE50));
    after_8:
L_80800924:
    // 0x80800924: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
L_80800928:
    // 0x80800928: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080092C: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800930: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800934: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800938: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080093C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800940: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800944: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800948: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080094C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800950: jal         0x8008FB10
    // 0x80800954: nop

    func_8008FB10(rdram, ctx);
        goto after_9;
    // 0x80800954: nop

    after_9:
    // 0x80800958: b           L_80800A9C
    // 0x8080095C: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
        goto L_80800A9C;
    // 0x8080095C: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
L_80800960:
    // 0x80800960: jal         0x80101F24
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_10;
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800968: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1796, 0X101C) << 16);
    // 0x8080096C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80800970: addiu       $a1, $a1, 0x101C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0X101C));
    // 0x80800974: jal         0x80101E4C
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_11;
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080097C: beq         $v0, $zero, L_8080099C
    if (ctx->r2 == 0) {
        // 0x80800980: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080099C;
    }
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800984: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1796, 0XE00) << 16);
    // 0x80800988: addiu       $a1, $a1, 0xE00
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0XE00));
    // 0x8080098C: jal         0x80800000
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chblackeye(rdram, ctx);
        goto after_12;
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800994: b           L_80800A34
    // 0x80800998: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
        goto L_80800A34;
    // 0x80800998: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
L_8080099C:
    // 0x8080099C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1796, 0X1024) << 16);
    // 0x808009A0: jal         0x80101E4C
    // 0x808009A4: addiu       $a1, $a1, 0x1024
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0X1024));
    func_80101E4C(rdram, ctx);
        goto after_13;
    // 0x808009A4: addiu       $a1, $a1, 0x1024
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0X1024));
    after_13:
    // 0x808009A8: beq         $v0, $zero, L_808009C8
    if (ctx->r2 == 0) {
        // 0x808009AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009C8;
    }
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1796, 0XE50) << 16);
    // 0x808009B4: addiu       $a1, $a1, 0xE50
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0XE50));
    // 0x808009B8: jal         0x80800000
    // 0x808009BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chblackeye(rdram, ctx);
        goto after_14;
    // 0x808009BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808009C0: b           L_80800A34
    // 0x808009C4: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
        goto L_80800A34;
    // 0x808009C4: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
L_808009C8:
    // 0x808009C8: lui         $a1, 0x3D23
    ctx->r5 = S32(0X3D23 << 16);
    // 0x808009CC: jal         0x80101E14
    // 0x808009D0: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    func_80101E14(rdram, ctx);
        goto after_15;
    // 0x808009D0: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    after_15:
    // 0x808009D4: beq         $v0, $zero, L_808009F0
    if (ctx->r2 == 0) {
        // 0x808009D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009F0;
    }
    // 0x808009D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009DC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1796, 0XE60) << 16);
    // 0x808009E0: jal         0x80800000
    // 0x808009E4: addiu       $a1, $a1, 0xE60
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0XE60));
    func_80800000_chblackeye(rdram, ctx);
        goto after_16;
    // 0x808009E4: addiu       $a1, $a1, 0xE60
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0XE60));
    after_16:
    // 0x808009E8: b           L_80800A34
    // 0x808009EC: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
        goto L_80800A34;
    // 0x808009EC: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
L_808009F0:
    // 0x808009F0: jal         0x80101DDC
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_17;
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808009F8: beq         $v0, $zero, L_80800A14
    if (ctx->r2 == 0) {
        // 0x808009FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A14;
    }
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A04: jal         0x80800314
    // 0x80800A08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800314_chblackeye(rdram, ctx);
        goto after_18;
    // 0x80800A08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_18:
    // 0x80800A0C: b           L_80800A34
    // 0x80800A10: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
        goto L_80800A34;
    // 0x80800A10: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
L_80800A14:
    // 0x80800A14: lui         $a1, 0x3F50
    ctx->r5 = S32(0X3F50 << 16);
    // 0x80800A18: jal         0x80101E14
    // 0x80800A1C: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    func_80101E14(rdram, ctx);
        goto after_19;
    // 0x80800A1C: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    after_19:
    // 0x80800A20: beql        $v0, $zero, L_80800A34
    if (ctx->r2 == 0) {
        // 0x80800A24: lw          $t3, 0x7C($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X7C);
            goto L_80800A34;
    }
    goto skip_1;
    // 0x80800A24: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
    skip_1:
    // 0x80800A28: jal         0x80800774
    // 0x80800A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800774_chblackeye(rdram, ctx);
        goto after_20;
    // 0x80800A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800A30: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
L_80800A34:
    // 0x80800A34: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800A38: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1796, 0XDD8) << 16);
    // 0x80800A3C: sll         $t5, $t3, 19
    ctx->r13 = S32(ctx->r11 << 19);
    // 0x80800A40: bgezl       $t5, L_80800A80
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800A44: addiu       $a0, $s0, 0x28
        ctx->r4 = ADD32(ctx->r16, 0X28);
            goto L_80800A80;
    }
    goto skip_2;
    // 0x80800A44: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    skip_2:
    // 0x80800A48: lwc1        $f16, 0xDD8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1796, 0XDD8));
    // 0x80800A4C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1796, 0XDDC) << 16);
    // 0x80800A50: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800A54: nop

    // 0x80800A58: bc1fl       L_80800A80
    if (!c1cs) {
        // 0x80800A5C: addiu       $a0, $s0, 0x28
        ctx->r4 = ADD32(ctx->r16, 0X28);
            goto L_80800A80;
    }
    goto skip_3;
    // 0x80800A5C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    skip_3:
    // 0x80800A60: lwc1        $f18, 0xDDC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1796, 0XDDC));
    // 0x80800A64: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800A68: nop

    // 0x80800A6C: bc1fl       L_80800A80
    if (!c1cs) {
        // 0x80800A70: addiu       $a0, $s0, 0x28
        ctx->r4 = ADD32(ctx->r16, 0X28);
            goto L_80800A80;
    }
    goto skip_4;
    // 0x80800A70: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    skip_4:
    // 0x80800A74: jal         0x80800478
    // 0x80800A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800478_chblackeye(rdram, ctx);
        goto after_21;
    // 0x80800A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800A7C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
L_80800A80:
    // 0x80800A80: jal         0x8008FA94
    // 0x80800A84: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_8008FA94(rdram, ctx);
        goto after_22;
    // 0x80800A84: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_22:
    // 0x80800A88: b           L_80800A9C
    // 0x80800A8C: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
        goto L_80800A9C;
    // 0x80800A8C: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
L_80800A90:
    // 0x80800A90: jal         0x8008FA94
    // 0x80800A94: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_8008FA94(rdram, ctx);
        goto after_23;
    // 0x80800A94: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_23:
    // 0x80800A98: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
L_80800A9C:
    // 0x80800A9C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800AA0: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800AA4: bgezl       $t8, L_80800AD4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800AA8: lw          $t0, 0x74($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X74);
            goto L_80800AD4;
    }
    goto skip_5;
    // 0x80800AA8: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    skip_5:
    // 0x80800AAC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80800AB0: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80800AB4: jal         0x800DBEFC
    // 0x80800AB8: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_24;
    // 0x80800AB8: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    after_24:
    // 0x80800ABC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800AC0: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x80800AC4: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    // 0x80800AC8: jal         0x8008FB10
    // 0x80800ACC: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    func_8008FB10(rdram, ctx);
        goto after_25;
    // 0x80800ACC: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    after_25:
    // 0x80800AD0: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
L_80800AD4:
    // 0x80800AD4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800AD8: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x80800ADC: bltzl       $t2, L_80800B78
    if (SIGNED(ctx->r10) < 0) {
        // 0x80800AE0: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80800B78;
    }
    goto skip_6;
    // 0x80800AE0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_6:
    // 0x80800AE4: jal         0x8010CAC0
    // 0x80800AE8: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    func_8010CAC0(rdram, ctx);
        goto after_26;
    // 0x80800AE8: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    after_26:
    // 0x80800AEC: beq         $v0, $zero, L_80800B74
    if (ctx->r2 == 0) {
        // 0x80800AF0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800B74;
    }
    // 0x80800AF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800AF4: jal         0x8008FA60
    // 0x80800AF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008FA60(rdram, ctx);
        goto after_27;
    // 0x80800AF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x80800AFC: beql        $v0, $zero, L_80800B78
    if (ctx->r2 == 0) {
        // 0x80800B00: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80800B78;
    }
    goto skip_7;
    // 0x80800B00: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_7:
    // 0x80800B04: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800B08: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800B0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800B10: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80800B14: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800B18: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800B1C: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    // 0x80800B20: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800B24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B28: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x80800B2C: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800B30: jal         0x8008A1D0
    // 0x80800B34: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    _subaddiedialog_entrypoint_4(rdram, ctx);
        goto after_28;
    // 0x80800B34: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    after_28:
    // 0x80800B38: beq         $v0, $zero, L_80800B50
    if (ctx->r2 == 0) {
        // 0x80800B3C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B50;
    }
    // 0x80800B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B40: jal         0x80800128
    // 0x80800B44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800128_chblackeye(rdram, ctx);
        goto after_29;
    // 0x80800B44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x80800B48: b           L_80800B78
    // 0x80800B4C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_80800B78;
    // 0x80800B4C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80800B50:
    // 0x80800B50: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800B54: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B5C: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x80800B60: nop

    // 0x80800B64: bc1fl       L_80800B78
    if (!c1cs) {
        // 0x80800B68: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80800B78;
    }
    goto skip_8;
    // 0x80800B68: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_8:
    // 0x80800B6C: jal         0x80800128
    // 0x80800B70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800128_chblackeye(rdram, ctx);
        goto after_30;
    // 0x80800B70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_30:
L_80800B74:
    // 0x80800B74: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80800B78:
    // 0x80800B78: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800B7C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800B80: nop

    // 0x80800B84: bc1fl       L_80800BB4
    if (!c1cs) {
        // 0x80800B88: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800BB4;
    }
    goto skip_9;
    // 0x80800B88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x80800B8C: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80800B90: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x80800B94: bltzl       $t5, L_80800BB4
    if (SIGNED(ctx->r13) < 0) {
        // 0x80800B98: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800BB4;
    }
    goto skip_10;
    // 0x80800B98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x80800B9C: jal         0x800D8FF8
    // 0x80800BA0: nop

    func_800D8FF8(rdram, ctx);
        goto after_31;
    // 0x80800BA0: nop

    after_31:
    // 0x80800BA4: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800BA8: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80800BAC: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x80800BB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BB4:
    // 0x80800BB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800BB8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800BBC: jr          $ra
    // 0x80800BC0: nop

    return;
    // 0x80800BC0: nop

;}
RECOMP_FUNC void func_80800038_chklungoleave(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080003C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800040: jal         0x80105834
    // 0x80800044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80105834(rdram, ctx);
        goto after_0;
    // 0x80800044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800048: jal         0x808000F0
    // 0x8080004C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000F0_chklungoleave(rdram, ctx);
        goto after_1;
    // 0x8080004C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800058: jr          $ra
    // 0x8080005C: nop

    return;
    // 0x8080005C: nop

;}
RECOMP_FUNC void _subaddiepalette_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A068: syscall     825
    recomp_syscall_handler(rdram, ctx, 0x8008A068);
    return;
    // 0x8008A06C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800D64_sumultiscore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D6C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800D70: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800D74: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800D78: jal         0x800F53D0
    // 0x80800D7C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x80800D7C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800D80: jal         0x80085528
    // 0x80800D84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _badeathmatch_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800D84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800D88: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800D8C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(3154, 0X14B0) << 16);
    // 0x80800D90: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80800D94: lw          $t7, 0x14B0($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(3154, 0X14B0));
    // 0x80800D98: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800D9C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800DA0: sh          $t7, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r15;
    // 0x80800DA4: jal         0x800F53D0
    // 0x80800DA8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F53D0(rdram, ctx);
        goto after_2;
    // 0x80800DA8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800DAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DB0: jal         0x80085540
    // 0x80800DB4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _badeathmatch_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80800DB4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800DB8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800DBC: sh          $v0, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r2;
    // 0x80800DC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800DC8: jr          $ra
    // 0x80800DCC: nop

    return;
    // 0x80800DCC: nop

;}
RECOMP_FUNC void bscrashout_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800200: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800204: jal         0x80099A34
    // 0x80800208: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80099A34(rdram, ctx);
        goto after_0;
    // 0x80800208: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080020C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800210: jal         0x8009C914
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_1;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800218: jal         0x8009C974
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_2;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800224: jal         0x8009D89C
    // 0x80800228: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009D89C(rdram, ctx);
        goto after_3;
    // 0x80800228: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x8080022C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800230: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8080023C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800240: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800244: jal         0x80085490
    // 0x80800248: nop

    _bamotor_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800248: nop

    after_4:
    // 0x8080024C: jal         0x8008E944
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_5;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800254: jal         0x8009514C
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009514C(rdram, ctx);
        goto after_6;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080025C: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800260: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800264: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800270: jal         0x808000B0
    // 0x80800274: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    func_808000B0_bscrashout(rdram, ctx);
        goto after_7;
    // 0x80800274: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    after_7:
    // 0x80800278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080027C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800280: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800284: jr          $ra
    // 0x80800288: nop

    return;
    // 0x80800288: nop

;}
RECOMP_FUNC void func_80800DB8_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800DBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800DC0: addiu       $at, $zero, 0x1284
    ctx->r1 = ADD32(0, 0X1284);
    // 0x80800DC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800DC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800DCC: beq         $a1, $at, L_80800E00
    if (ctx->r5 == ctx->r1) {
        // 0x80800DD0: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800E00;
    }
    // 0x80800DD0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800DD4: addiu       $at, $zero, 0x1285
    ctx->r1 = ADD32(0, 0X1285);
    // 0x80800DD8: beq         $a1, $at, L_80800E48
    if (ctx->r5 == ctx->r1) {
        // 0x80800DDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E48;
    }
    // 0x80800DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DE0: addiu       $at, $zero, 0x1286
    ctx->r1 = ADD32(0, 0X1286);
    // 0x80800DE4: beq         $a1, $at, L_80800E9C
    if (ctx->r5 == ctx->r1) {
        // 0x80800DE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E9C;
    }
    // 0x80800DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DEC: addiu       $at, $zero, 0x12CE
    ctx->r1 = ADD32(0, 0X12CE);
    // 0x80800DF0: beq         $a1, $at, L_80800ED0
    if (ctx->r5 == ctx->r1) {
        // 0x80800DF4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800ED0;
    }
    // 0x80800DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DF8: b           L_80800EE0
    // 0x80800DFC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1324, 0X1E60) << 16);
        goto L_80800EE0;
    // 0x80800DFC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1324, 0X1E60) << 16);
L_80800E00:
    // 0x80800E00: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800E04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E0C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80800E10: jal         0x80102424
    // 0x80800E14: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800E14: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    after_0:
    // 0x80800E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E1C: jal         0x8008A4B0
    // 0x80800E20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800E20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800E24: jal         0x80085710
    // 0x80800E28: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x80800E28: nop

    after_2:
    // 0x80800E2C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800E30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E34: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80800E38: jal         0x80085708
    // 0x80800E3C: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    _capod_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80800E3C: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    after_3:
    // 0x80800E40: b           L_80800F94
    // 0x80800E44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800F94;
    // 0x80800E44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E48:
    // 0x80800E48: lhu         $t6, 0x6E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800E4C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800E50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800E54: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x80800E58: ori         $t8, $t7, 0x5
    ctx->r24 = ctx->r15 | 0X5;
    // 0x80800E5C: sh          $t8, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r24;
    // 0x80800E60: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80800E64: jal         0x80102424
    // 0x80800E68: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80800E68: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x80800E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E70: jal         0x8008A4B0
    // 0x80800E74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800E74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800E78: jal         0x80085710
    // 0x80800E7C: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_6;
    // 0x80800E7C: nop

    after_6:
    // 0x80800E80: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800E84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E88: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80800E8C: jal         0x80085708
    // 0x80800E90: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    _capod_entrypoint_13(rdram, ctx);
        goto after_7;
    // 0x80800E90: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    after_7:
    // 0x80800E94: b           L_80800F94
    // 0x80800E98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800F94;
    // 0x80800E98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E9C:
    // 0x80800E9C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1324, 0X2234) << 16);
    // 0x80800EA0: addiu       $a2, $a2, 0x2234
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1324, 0X2234));
    // 0x80800EA4: jal         0x80089D18
    // 0x80800EA8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800EA8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x80800EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EB0: jal         0x80102424
    // 0x80800EB4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800EB4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_9:
    // 0x80800EB8: jal         0x80089CB8
    // 0x80800EBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_5(rdram, ctx);
        goto after_10;
    // 0x80800EBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800EC0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800EC4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800EC8: b           L_80800F90
    // 0x80800ECC: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_80800F90;
    // 0x80800ECC: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80800ED0:
    // 0x80800ED0: jal         0x80085710
    // 0x80800ED4: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_11;
    // 0x80800ED4: nop

    after_11:
    // 0x80800ED8: b           L_80800F94
    // 0x80800EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800F94;
    // 0x80800EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EE0:
    // 0x80800EE0: addiu       $a2, $a2, 0x1E60
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1324, 0X1E60));
    // 0x80800EE4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80800EE8: jal         0x8008A1F8
    // 0x80800EEC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x80800EEC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_12:
    // 0x80800EF0: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800EF4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1324, 0X1E80) << 16);
    // 0x80800EF8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80800EFC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F00: addiu       $a2, $a2, 0x1E80
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1324, 0X1E80));
    // 0x80800F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F08: jal         0x8008A1F8
    // 0x80800F0C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_13;
    // 0x80800F0C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_13:
    // 0x80800F10: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800F14: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F18: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800F1C: bne         $t0, $zero, L_80800F2C
    if (ctx->r8 != 0) {
        // 0x80800F20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F2C;
    }
    // 0x80800F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F24: beq         $t1, $zero, L_80800F3C
    if (ctx->r9 == 0) {
        // 0x80800F28: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1324, 0X1EA8) << 16);
            goto L_80800F3C;
    }
    // 0x80800F28: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1324, 0X1EA8) << 16);
L_80800F2C:
    // 0x80800F2C: jal         0x80102424
    // 0x80800F30: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x80800F30: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_14:
    // 0x80800F34: b           L_80800F94
    // 0x80800F38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800F94;
    // 0x80800F38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F3C:
    // 0x80800F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F40: addiu       $a2, $a2, 0x1EA8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1324, 0X1EA8));
    // 0x80800F44: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800F48: jal         0x8008A1F8
    // 0x80800F4C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_15;
    // 0x80800F4C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_15:
    // 0x80800F50: beq         $v0, $zero, L_80800F6C
    if (ctx->r2 == 0) {
        // 0x80800F54: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_80800F6C;
    }
    // 0x80800F54: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F5C: jal         0x80102424
    // 0x80800F60: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80102424(rdram, ctx);
        goto after_16;
    // 0x80800F60: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_16:
    // 0x80800F64: b           L_80800F94
    // 0x80800F68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800F94;
    // 0x80800F68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F6C:
    // 0x80800F6C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1324, 0X1E98) << 16);
    // 0x80800F70: addiu       $a2, $a2, 0x1E98
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1324, 0X1E98));
    // 0x80800F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F78: jal         0x8008A1F8
    // 0x80800F7C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_17;
    // 0x80800F7C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_17:
    // 0x80800F80: beq         $v0, $zero, L_80800F90
    if (ctx->r2 == 0) {
        // 0x80800F84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F90;
    }
    // 0x80800F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F88: jal         0x80102424
    // 0x80800F8C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_18;
    // 0x80800F8C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_18:
L_80800F90:
    // 0x80800F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F94:
    // 0x80800F94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F9C: jr          $ra
    // 0x80800FA0: nop

    return;
    // 0x80800FA0: nop

;}
RECOMP_FUNC void func_80800188_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080018C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800190: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800194: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800198: jal         0x8009E74C
    // 0x8080019C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x8080019C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x808001A0: bnel        $v0, $zero, L_80800238
    if (ctx->r2 != 0) {
        // 0x808001A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800238;
    }
    goto skip_0;
    // 0x808001A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808001A8: jal         0x80084BE8
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001B0: jal         0x80085168
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bastatemem_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001B8: jal         0x8009BC6C
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_3;
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001C0: jal         0x8009BC90
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_4;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: jal         0x800A0CF4
    // 0x808001D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_5;
    // 0x808001D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D8: jal         0x80093360
    // 0x808001DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80093360(rdram, ctx);
        goto after_6;
    // 0x808001DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x808001E0: jal         0x800A042C
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A042C(rdram, ctx);
        goto after_7;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001EC: jal         0x8009C908
    // 0x808001F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    yaw_setUpdateType(rdram, ctx);
        goto after_8;
    // 0x808001F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808001F4: jal         0x800A4E30
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4E30(rdram, ctx);
        goto after_9;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808001FC: jal         0x80095A40
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_10;
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: jal         0x800961AC
    // 0x8080020C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_11;
    // 0x8080020C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800214: jal         0x800845A8
    // 0x80800218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _baboost_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x80800218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800220: jal         0x80095774
    // 0x80800224: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    baflag_clear(rdram, ctx);
        goto after_13;
    // 0x80800224: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    after_13:
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080022C: jal         0x80095774
    // 0x80800230: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    baflag_clear(rdram, ctx);
        goto after_14;
    // 0x80800230: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_14:
    // 0x80800234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800238:
    // 0x80800238: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080023C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800240: jr          $ra
    // 0x80800244: nop

    return;
    // 0x80800244: nop

;}
RECOMP_FUNC void func_80800E7C_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800E88: jal         0x80084600
    // 0x80800E8C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _babounce_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800E8C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800E90: beq         $v0, $zero, L_80800E9C
    if (ctx->r2 == 0) {
        // 0x80800E94: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800E9C;
    }
    // 0x80800E94: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E98: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
L_80800E9C:
    // 0x80800E9C: jal         0x8009E5C8
    // 0x80800EA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x80800EA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800EAC: jr          $ra
    // 0x80800EB0: nop

    return;
    // 0x80800EB0: nop

;}
RECOMP_FUNC void func_80800618_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800618: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080061C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800620: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800624: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800628: jal         0x80100094
    // 0x8080062C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080062C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800630: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800634: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800638: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8080063C: sb          $t6, 0xFC($t8)
    MEM_B(0XFC, ctx->r24) = ctx->r14;
    // 0x80800640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800644: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800648: jr          $ra
    // 0x8080064C: nop

    return;
    // 0x8080064C: nop

;}
RECOMP_FUNC void func_800EEC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EEC70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EEC74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EEC78: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800EEC7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800EEC80: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800EEC84: jal         0x800138D0
    // 0x800EEC88: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800138D0(rdram, ctx);
        goto after_0;
    // 0x800EEC88: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800EEC8C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800EEC90: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800EEC94: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800EEC98: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800EEC9C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800EECA0: swc1        $f8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f8.u32l;
    // 0x800EECA4: jal         0x800137F4
    // 0x800EECA8: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    func_800137F4(rdram, ctx);
        goto after_1;
    // 0x800EECA8: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800EECAC: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800EECB0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800EECB4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800EECB8: jal         0x80013788
    // 0x800EECBC: swc1        $f16, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
    func_80013788(rdram, ctx);
        goto after_2;
    // 0x800EECBC: swc1        $f16, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
    after_2:
    // 0x800EECC0: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800EECC4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800EECC8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800EECCC: swc1        $f4, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f4.u32l;
    // 0x800EECD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EECD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EECD8: jr          $ra
    // 0x800EECDC: nop

    return;
    // 0x800EECDC: nop

;}
RECOMP_FUNC void func_80800254_chbouncycastle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800254: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800258: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080025C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800260: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800264: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800268: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080026C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800270: bne         $t6, $at, L_808002BC
    if (ctx->r14 != ctx->r1) {
        // 0x80800274: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_808002BC;
    }
    // 0x80800274: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800278: jal         0x8080051C
    // 0x8080027C: nop

    func_8080051C_chbouncycastle(rdram, ctx);
        goto after_0;
    // 0x8080027C: nop

    after_0:
    // 0x80800280: jal         0x80101DDC
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_1;
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800288: beq         $v0, $zero, L_808002B0
    if (ctx->r2 == 0) {
        // 0x8080028C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002B0;
    }
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: jal         0x80102424
    // 0x80800294: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800294: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800298: jal         0x800DA544
    // 0x8080029C: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x8080029C: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    after_3:
    // 0x808002A0: lbu         $t7, 0x79($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X79);
    // 0x808002A4: andi        $t8, $t7, 0xFF0F
    ctx->r24 = ctx->r15 & 0XFF0F;
    // 0x808002A8: ori         $t9, $t8, 0x30
    ctx->r25 = ctx->r24 | 0X30;
    // 0x808002AC: sb          $t9, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r25;
L_808002B0:
    // 0x808002B0: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808002B4: srl         $t0, $v0, 10
    ctx->r8 = S32(U32(ctx->r2) >> 10);
    // 0x808002B8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_808002BC:
    // 0x808002BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002C0: beql        $v0, $at, L_808002DC
    if (ctx->r2 == ctx->r1) {
        // 0x808002C4: lbu         $t4, 0x75($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X75);
            goto L_808002DC;
    }
    goto skip_0;
    // 0x808002C4: lbu         $t4, 0x75($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X75);
    skip_0:
    // 0x808002C8: lbu         $t1, 0x79($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X79);
    // 0x808002CC: srl         $t2, $t1, 4
    ctx->r10 = S32(U32(ctx->r9) >> 4);
    // 0x808002D0: beql        $t2, $zero, L_808002EC
    if (ctx->r10 == 0) {
        // 0x808002D4: lbu         $t6, 0x75($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X75);
            goto L_808002EC;
    }
    goto skip_1;
    // 0x808002D4: lbu         $t6, 0x75($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X75);
    skip_1:
    // 0x808002D8: lbu         $t4, 0x75($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X75);
L_808002DC:
    // 0x808002DC: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x808002E0: b           L_808002F4
    // 0x808002E4: sb          $t5, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r13;
        goto L_808002F4;
    // 0x808002E4: sb          $t5, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r13;
    // 0x808002E8: lbu         $t6, 0x75($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X75);
L_808002EC:
    // 0x808002EC: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x808002F0: sb          $t7, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r15;
L_808002F4:
    // 0x808002F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800300: jr          $ra
    // 0x80800304: nop

    return;
    // 0x80800304: nop

;}
RECOMP_FUNC void subaddieDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002D0: jal         0x800F54E4
    // 0x808002D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808002D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808002D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808002DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002E0: jal         0x800F52B8
    // 0x808002E4: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_800F52B8(rdram, ctx);
        goto after_1;
    // 0x808002E4: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x808002E8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808002EC: beq         $v0, $at, L_808002FC
    if (ctx->r2 == ctx->r1) {
        // 0x808002F0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808002FC;
    }
    // 0x808002F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002F4: b           L_80800308
    // 0x808002F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800308;
    // 0x808002F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002FC:
    // 0x808002FC: jal         0x80800260
    // 0x80800300: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80800260_subaddieDll(rdram, ctx);
        goto after_2;
    // 0x80800300: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800308:
    // 0x80800308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080030C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800310: jr          $ra
    // 0x80800314: nop

    return;
    // 0x80800314: nop

;}
RECOMP_FUNC void _glsplinefind_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800884A0: syscall     687
    recomp_syscall_handler(rdram, ctx, 0x800884A0);
    return;
    // 0x800884A4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808003F4_gcmapsects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003F8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808003FC: sll         $s2, $a1, 2
    ctx->r18 = S32(ctx->r5 << 2);
    // 0x80800400: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800404: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800408: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080040C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800410: subu        $s2, $s2, $a1
    ctx->r18 = SUB32(ctx->r18, ctx->r5);
    // 0x80800414: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x80800418: sll         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18 << 2);
    // 0x8080041C: subu        $s2, $s2, $a1
    ctx->r18 = SUB32(ctx->r18, ctx->r5);
    // 0x80800420: sll         $s2, $s2, 3
    ctx->r18 = S32(ctx->r18 << 3);
    // 0x80800424: addu        $s0, $t6, $s2
    ctx->r16 = ADD32(ctx->r14, ctx->r18);
    // 0x80800428: lbu         $t7, 0x4C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X4C);
    // 0x8080042C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800430: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800434: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x80800438: sb          $t8, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r24;
    // 0x8080043C: lw          $t9, 0x68($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X68);
    // 0x80800440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800444: addu        $s0, $t9, $s2
    ctx->r16 = ADD32(ctx->r25, ctx->r18);
    // 0x80800448: lbu         $t0, 0x4C($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X4C);
    // 0x8080044C: andi        $t1, $t0, 0xFF7F
    ctx->r9 = ctx->r8 & 0XFF7F;
    // 0x80800450: sb          $t1, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r9;
    // 0x80800454: lw          $t2, 0x68($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X68);
    // 0x80800458: addu        $s0, $t2, $s2
    ctx->r16 = ADD32(ctx->r10, ctx->r18);
    // 0x8080045C: lw          $t3, 0x4C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4C);
    // 0x80800460: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x80800464: bgez        $t5, L_80800490
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800468: nop
    
            goto L_80800490;
    }
    // 0x80800468: nop

    // 0x8080046C: jal         0x800D70F8
    // 0x80800470: lhu         $a0, 0x40($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X40);
    func_800D70F8(rdram, ctx);
        goto after_0;
    // 0x80800470: lhu         $a0, 0x40($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X40);
    after_0:
    // 0x80800474: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
    // 0x80800478: addu        $s0, $t6, $s2
    ctx->r16 = ADD32(ctx->r14, ctx->r18);
    // 0x8080047C: lbu         $t7, 0x4C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X4C);
    // 0x80800480: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x80800484: sb          $t8, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r24;
    // 0x80800488: lw          $t9, 0x68($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X68);
    // 0x8080048C: addu        $s0, $t9, $s2
    ctx->r16 = ADD32(ctx->r25, ctx->r18);
L_80800490:
    // 0x80800490: jal         0x800D73CC
    // 0x80800494: lhu         $a0, 0x40($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X40);
    func_800D73CC(rdram, ctx);
        goto after_1;
    // 0x80800494: lhu         $a0, 0x40($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X40);
    after_1:
    // 0x80800498: beql        $v0, $zero, L_808004B4
    if (ctx->r2 == 0) {
        // 0x8080049C: lw          $t2, 0x68($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X68);
            goto L_808004B4;
    }
    goto skip_0;
    // 0x8080049C: lw          $t2, 0x68($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X68);
    skip_0:
    // 0x808004A0: lw          $t0, 0x68($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X68);
    // 0x808004A4: addu        $t1, $t0, $s2
    ctx->r9 = ADD32(ctx->r8, ctx->r18);
    // 0x808004A8: jal         0x800D6CEC
    // 0x808004AC: lhu         $a0, 0x40($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X40);
    func_800D6CEC(rdram, ctx);
        goto after_2;
    // 0x808004AC: lhu         $a0, 0x40($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X40);
    after_2:
    // 0x808004B0: lw          $t2, 0x68($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X68);
L_808004B4:
    // 0x808004B4: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x808004B8: lhu         $v0, 0x42($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X42);
    // 0x808004BC: beql        $v0, $zero, L_808004FC
    if (ctx->r2 == 0) {
        // 0x808004C0: lw          $t8, 0x68($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X68);
            goto L_808004FC;
    }
    goto skip_1;
    // 0x808004C0: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    skip_1:
    // 0x808004C4: jal         0x800D73CC
    // 0x808004C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D73CC(rdram, ctx);
        goto after_3;
    // 0x808004C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808004CC: beql        $v0, $zero, L_808004FC
    if (ctx->r2 == 0) {
        // 0x808004D0: lw          $t8, 0x68($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X68);
            goto L_808004FC;
    }
    goto skip_2;
    // 0x808004D0: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    skip_2:
    // 0x808004D4: lw          $t4, 0x68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X68);
    // 0x808004D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004DC: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x808004E0: jal         0x800D70F8
    // 0x808004E4: lhu         $a0, 0x42($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X42);
    func_800D70F8(rdram, ctx);
        goto after_4;
    // 0x808004E4: lhu         $a0, 0x42($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X42);
    after_4:
    // 0x808004E8: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
    // 0x808004EC: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x808004F0: jal         0x800D6CEC
    // 0x808004F4: lhu         $a0, 0x42($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X42);
    func_800D6CEC(rdram, ctx);
        goto after_5;
    // 0x808004F4: lhu         $a0, 0x42($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X42);
    after_5:
    // 0x808004F8: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
L_808004FC:
    // 0x808004FC: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x80800500: jal         0x800E4AF0
    // 0x80800504: lhu         $a0, 0x40($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X40);
    func_800E4AF0(rdram, ctx);
        goto after_6;
    // 0x80800504: lhu         $a0, 0x40($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X40);
    after_6:
    // 0x80800508: beql        $v0, $zero, L_80800524
    if (ctx->r2 == 0) {
        // 0x8080050C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800524;
    }
    goto skip_3;
    // 0x8080050C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_3:
    // 0x80800510: lw          $t0, 0x68($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X68);
    // 0x80800514: addu        $t1, $t0, $s2
    ctx->r9 = ADD32(ctx->r8, ctx->r18);
    // 0x80800518: jal         0x800E4BB8
    // 0x8080051C: lhu         $a0, 0x40($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X40);
    func_800E4BB8(rdram, ctx);
        goto after_7;
    // 0x8080051C: lhu         $a0, 0x40($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X40);
    after_7:
    // 0x80800520: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800524:
    // 0x80800524: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
    // 0x80800528: sll         $t3, $s3, 2
    ctx->r11 = S32(ctx->r19 << 2);
L_8080052C:
    // 0x8080052C: subu        $t3, $t3, $s3
    ctx->r11 = SUB32(ctx->r11, ctx->r19);
    // 0x80800530: lw          $t2, 0x68($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X68);
    // 0x80800534: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80800538: subu        $t3, $t3, $s3
    ctx->r11 = SUB32(ctx->r11, ctx->r19);
    // 0x8080053C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80800540: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80800544: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80800548: lw          $a0, 0x50($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X50);
    // 0x8080054C: beql        $a0, $zero, L_808005AC
    if (ctx->r4 == 0) {
        // 0x80800550: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808005AC;
    }
    goto skip_4;
    // 0x80800550: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_4:
    // 0x80800554: jal         0x80088F30
    // 0x80800558: nop

    _idworldmake_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800558: nop

    after_8:
    // 0x8080055C: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x80800560: subu        $t7, $t7, $s3
    ctx->r15 = SUB32(ctx->r15, ctx->r19);
    // 0x80800564: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
    // 0x80800568: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080056C: subu        $t7, $t7, $s3
    ctx->r15 = SUB32(ctx->r15, ctx->r19);
    // 0x80800570: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80800574: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800578: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8080057C: jal         0x80088898
    // 0x80800580: lw          $a0, 0x50($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X50);
    _glidmake_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x80800580: lw          $a0, 0x50($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X50);
    after_9:
    // 0x80800584: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x80800588: subu        $t1, $t1, $s3
    ctx->r9 = SUB32(ctx->r9, ctx->r19);
    // 0x8080058C: lw          $t0, 0x68($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X68);
    // 0x80800590: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800594: subu        $t1, $t1, $s3
    ctx->r9 = SUB32(ctx->r9, ctx->r19);
    // 0x80800598: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8080059C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x808005A0: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x808005A4: sw          $zero, 0x50($t3)
    MEM_W(0X50, ctx->r11) = 0;
    // 0x808005A8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_808005AC:
    // 0x808005AC: bnel        $s0, $s2, L_8080052C
    if (ctx->r16 != ctx->r18) {
        // 0x808005B0: sll         $t3, $s3, 2
        ctx->r11 = S32(ctx->r19 << 2);
            goto L_8080052C;
    }
    goto skip_5;
    // 0x808005B0: sll         $t3, $s3, 2
    ctx->r11 = S32(ctx->r19 << 2);
    skip_5:
    // 0x808005B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808005BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808005C0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808005C4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808005C8: jr          $ra
    // 0x808005CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808005CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _suexpressjoint_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089770: syscall     794
    recomp_syscall_handler(rdram, ctx, 0x80089770);
    return;
    // 0x80089774: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80802FE4_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802FE4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80802FE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802FEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802FF0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80802FF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802FF8: jal         0x80100094
    // 0x80802FFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802FFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803000: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80803004: jal         0x800D90A4
    // 0x80803008: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x80803008: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x8080300C: jal         0x800D8FF8
    // 0x80803010: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80803010: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_2:
    // 0x80803014: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80803018: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8080301C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803020: jal         0x8010CD50
    // 0x80803024: lh          $a1, 0x78($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X78);
    func_8010CD50(rdram, ctx);
        goto after_3;
    // 0x80803024: lh          $a1, 0x78($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X78);
    after_3:
    // 0x80803028: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x8080302C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80803030: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803034: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80803038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080303C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80803040: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80803044: jal         0x80102B2C
    // 0x80803048: nop

    func_80102B2C(rdram, ctx);
        goto after_4;
    // 0x80803048: nop

    after_4:
    // 0x8080304C: jal         0x80802E80
    // 0x80803050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802E80_chweldarboss(rdram, ctx);
        goto after_5;
    // 0x80803050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80803054: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80803058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080305C: beql        $t7, $zero, L_80803070
    if (ctx->r15 == 0) {
        // 0x80803060: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80803070;
    }
    goto skip_0;
    // 0x80803060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80803064: jal         0x80801AA0
    // 0x80803068: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_6;
    // 0x80803068: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x8080306C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803070:
    // 0x80803070: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803074: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80803078: jr          $ra
    // 0x8080307C: nop

    return;
    // 0x8080307C: nop

;}
RECOMP_FUNC void func_8009CC90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CC90: lw          $t6, 0xF0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XF0);
    // 0x8009CC94: sb          $zero, 0x81($t6)
    MEM_B(0X81, ctx->r14) = 0;
    // 0x8009CC98: lw          $t7, 0xF0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XF0);
    // 0x8009CC9C: jr          $ra
    // 0x8009CCA0: sb          $zero, 0x80($t7)
    MEM_B(0X80, ctx->r15) = 0;
    return;
    // 0x8009CCA0: sb          $zero, 0x80($t7)
    MEM_B(0X80, ctx->r15) = 0;
;}
RECOMP_FUNC void _bsride_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800839F0: syscall     85
    recomp_syscall_handler(rdram, ctx, 0x800839F0);
    return;
    // 0x800839F4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800FC348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC348: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FC34C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800FC350: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FC354: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800FC358: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800FC35C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800FC360: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FC364: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800FC368: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FC36C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800FC370: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800FC374: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800FC378: addiu       $s4, $s4, 0x5960
    ctx->r20 = ADD32(ctx->r20, 0X5960);
    // 0x800FC37C: addiu       $s0, $s0, 0x57D0
    ctx->r16 = ADD32(ctx->r16, 0X57D0);
    // 0x800FC380: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
L_800FC384:
    // 0x800FC384: bltzl       $a0, L_800FC3B0
    if (SIGNED(ctx->r4) < 0) {
        // 0x800FC388: addiu       $s0, $s0, 0x50
        ctx->r16 = ADD32(ctx->r16, 0X50);
            goto L_800FC3B0;
    }
    goto skip_0;
    // 0x800FC388: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    skip_0:
    // 0x800FC38C: jal         0x800FE7A8
    // 0x800FC390: nop

    func_800FE7A8(rdram, ctx);
        goto after_0;
    // 0x800FC390: nop

    after_0:
    // 0x800FC394: bne         $v0, $zero, L_800FC3AC
    if (ctx->r2 != 0) {
        // 0x800FC398: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800FC3AC;
    }
    // 0x800FC398: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800FC39C: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
    // 0x800FC3A0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800FC3A4: jal         0x800FCB00
    // 0x800FC3A8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_800FCB00(rdram, ctx);
        goto after_1;
    // 0x800FC3A8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_1:
L_800FC3AC:
    // 0x800FC3AC: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
L_800FC3B0:
    // 0x800FC3B0: bnel        $s0, $s4, L_800FC384
    if (ctx->r16 != ctx->r20) {
        // 0x800FC3B4: lh          $a0, 0x28($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X28);
            goto L_800FC384;
    }
    goto skip_1;
    // 0x800FC3B4: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
    skip_1:
    // 0x800FC3B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800FC3BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FC3C0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC3C4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800FC3C8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800FC3CC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800FC3D0: jr          $ra
    // 0x800FC3D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800FC3D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80801DD0_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801DD4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801DD8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801DDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801DE0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801DE4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801DE8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801DEC: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_80801DF0:
    // 0x80801DF0: jal         0x800DA298
    // 0x80801DF4: addiu       $a0, $s0, 0x372
    ctx->r4 = ADD32(ctx->r16, 0X372);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80801DF4: addiu       $a0, $s0, 0x372
    ctx->r4 = ADD32(ctx->r16, 0X372);
    after_0:
    // 0x80801DF8: beq         $v0, $zero, L_80801E04
    if (ctx->r2 == 0) {
        // 0x80801DFC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801E04;
    }
    // 0x80801DFC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801E00: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80801E04:
    // 0x80801E04: bne         $s0, $s2, L_80801DF0
    if (ctx->r16 != ctx->r18) {
        // 0x80801E08: nop
    
            goto L_80801DF0;
    }
    // 0x80801E08: nop

    // 0x80801E0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801E10: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80801E14: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801E18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801E1C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801E20: jr          $ra
    // 0x80801E24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801E24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chbounce_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085910: syscall     180
    recomp_syscall_handler(rdram, ctx, 0x80085910);
    return;
    // 0x80085914: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void bskazdie_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080044C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800450: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(240, 0X460) << 16);
    // 0x80800454: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800458: jr          $ra
    // 0x8080045C: lw          $v0, 0x460($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(240, 0X460));
    return;
    // 0x8080045C: lw          $v0, 0x460($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(240, 0X460));
;}
RECOMP_FUNC void func_800F849C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F849C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800F84A0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F84A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F84A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F84AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F84B0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F84B4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800F84B8: jal         0x8009BD18
    // 0x800F84BC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8009BD18(rdram, ctx);
        goto after_0;
    // 0x800F84BC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F84C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F84C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F84C8: jr          $ra
    // 0x800F84CC: nop

    return;
    // 0x800F84CC: nop

;}
RECOMP_FUNC void func_800EE7B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE7B4: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800EE7B8: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EE7BC: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EE7C0: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800EE7C4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800EE7C8: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x800EE7CC: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EE7D0: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EE7D4: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800EE7D8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800EE7DC: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800EE7E0: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EE7E4: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EE7E8: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800EE7EC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800EE7F0: jr          $ra
    // 0x800EE7F4: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x800EE7F4: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_80800270_chdinoswitches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800270: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800278: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8080027C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80800280: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1048, 0XB28) << 16);
    // 0x80800284: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800288: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8080028C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800290: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80800294: lhu         $a1, 0xB28($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1048, 0XB28));
    // 0x80800298: jal         0x801032B0
    // 0x8080029C: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    func_801032B0(rdram, ctx);
        goto after_0;
    // 0x8080029C: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    after_0:
    // 0x808002A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002A8: jr          $ra
    // 0x808002AC: nop

    return;
    // 0x808002AC: nop

;}
RECOMP_FUNC void _chcoderoombits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800862A0: syscall     299
    recomp_syscall_handler(rdram, ctx, 0x800862A0);
    return;
    // 0x800862A4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _gcstatusDll_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088350: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088350);
    return;
    // 0x80088354: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800000_fxleaves(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80800004: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800008: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800014: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80800018: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080001C: jal         0x800B2928
    // 0x80800020: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    vector_size(rdram, ctx);
        goto after_0;
    // 0x80800020: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    after_0:
    // 0x80800024: lh          $t6, 0x20($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X20);
    // 0x80800028: addiu       $s0, $sp, 0x74
    ctx->r16 = ADD32(ctx->r29, 0X74);
    // 0x8080002C: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80800030: beql        $at, $zero, L_80800270
    if (ctx->r1 == 0) {
        // 0x80800034: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800270;
    }
    goto skip_0;
    // 0x80800034: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800038: jal         0x8008FE68
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008FE68(rdram, ctx);
        goto after_1;
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800040: jal         0x800E3958
    // 0x80800044: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    func_800E3958(rdram, ctx);
        goto after_2;
    // 0x80800044: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_2:
    // 0x80800048: jal         0x800E3A58
    // 0x8080004C: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    func_800E3A58(rdram, ctx);
        goto after_3;
    // 0x8080004C: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    after_3:
    // 0x80800050: jal         0x800B2974
    // 0x80800054: addiu       $a0, $s1, 0x1C
    ctx->r4 = ADD32(ctx->r17, 0X1C);
    vector_push_back(rdram, ctx);
        goto after_4;
    // 0x80800054: addiu       $a0, $s1, 0x1C
    ctx->r4 = ADD32(ctx->r17, 0X1C);
    after_4:
    // 0x80800058: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8080005C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800060: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80800064: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800068: jal         0x800DC178
    // 0x8080006C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x8080006C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    after_5:
    // 0x80800070: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800074: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800078: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8080007C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800080: jal         0x800DC178
    // 0x80800084: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800084: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_6:
    // 0x80800088: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x8080008C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800090: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800094: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800098: jal         0x800EFA4C
    // 0x8080009C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x8080009C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_7:
    // 0x808000A0: jal         0x800EEFD4
    // 0x808000A4: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    func_800EEFD4(rdram, ctx);
        goto after_8;
    // 0x808000A4: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    after_8:
    // 0x808000A8: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x808000AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000B0: nop

    // 0x808000B4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808000B8: nop

    // 0x808000BC: bc1f        L_808000EC
    if (!c1cs) {
        // 0x808000C0: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_808000EC;
    }
    // 0x808000C0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808000C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000C8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808000CC: jal         0x800DC178
    // 0x808000D0: nop

    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x808000D0: nop

    after_9:
    // 0x808000D4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808000D8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000DC: jal         0x800EF934
    // 0x808000E0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800EF934(rdram, ctx);
        goto after_10;
    // 0x808000E0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_10:
    // 0x808000E4: b           L_80800124
    // 0x808000E8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
        goto L_80800124;
    // 0x808000E8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
L_808000EC:
    // 0x808000EC: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x808000F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000F4: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x808000F8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000FC: jal         0x800DC178
    // 0x80800100: nop

    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x80800100: nop

    after_11:
    // 0x80800104: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800108: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8080010C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800110: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800114: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800118: jal         0x800EF934
    // 0x8080011C: nop

    func_800EF934(rdram, ctx);
        goto after_12;
    // 0x8080011C: nop

    after_12:
    // 0x80800120: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
L_80800124:
    // 0x80800124: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800128: jal         0x800EE780
    // 0x8080012C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE780(rdram, ctx);
        goto after_13;
    // 0x8080012C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_13:
    // 0x80800130: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800134: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800138: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080013C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800140: c.lt.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl < ctx->f16.fl;
    // 0x80800144: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800148: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8080014C: bc1fl       L_808001A8
    if (!c1cs) {
        // 0x80800150: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_808001A8;
    }
    goto skip_1;
    // 0x80800150: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    skip_1:
    // 0x80800154: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800158: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8080015C: jal         0x800E3F8C
    // 0x80800160: sub.s       $f14, $f18, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f22.fl;
    func_800E3F8C(rdram, ctx);
        goto after_14;
    // 0x80800160: sub.s       $f14, $f18, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f22.fl;
    after_14:
    // 0x80800164: beq         $v0, $zero, L_808001A4
    if (ctx->r2 == 0) {
        // 0x80800168: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_808001A4;
    }
    // 0x80800168: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080016C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800170: nop

    // 0x80800174: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
L_80800178:
    // 0x80800178: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080017C: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80800180: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80800184: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800188: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8080018C: beq         $at, $zero, L_808001A4
    if (ctx->r1 == 0) {
        // 0x80800190: swc1        $f6, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
            goto L_808001A4;
    }
    // 0x80800190: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x80800194: jal         0x800E3F8C
    // 0x80800198: sub.s       $f14, $f6, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f22.fl;
    func_800E3F8C(rdram, ctx);
        goto after_15;
    // 0x80800198: sub.s       $f14, $f6, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f22.fl;
    after_15:
    // 0x8080019C: bnel        $v0, $zero, L_80800178
    if (ctx->r2 != 0) {
        // 0x808001A0: lwc1        $f4, 0x48($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
            goto L_80800178;
    }
    goto skip_2;
    // 0x808001A0: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    skip_2:
L_808001A4:
    // 0x808001A4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
L_808001A8:
    // 0x808001A8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x808001AC: jal         0x800EE7F8
    // 0x808001B0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_16;
    // 0x808001B0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_16:
    // 0x808001B4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x808001B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808001BC: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    // 0x808001C0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808001C4: jal         0x800EFA4C
    // 0x808001C8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EFA4C(rdram, ctx);
        goto after_17;
    // 0x808001C8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_17:
    // 0x808001CC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x808001D0: jal         0x800EFD24
    // 0x808001D4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_800EFD24(rdram, ctx);
        goto after_18;
    // 0x808001D4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_18:
    // 0x808001D8: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x808001DC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001E0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808001E4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001E8: jal         0x800DC178
    // 0x808001EC: nop

    func_800DC178(rdram, ctx);
        goto after_19;
    // 0x808001EC: nop

    after_19:
    // 0x808001F0: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x808001F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001F8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808001FC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800200: jal         0x800DC178
    // 0x80800204: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800DC178(rdram, ctx);
        goto after_20;
    // 0x80800204: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_20:
    // 0x80800208: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8080020C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800210: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800214: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800218: jal         0x800DC178
    // 0x8080021C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_800DC178(rdram, ctx);
        goto after_21;
    // 0x8080021C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_21:
    // 0x80800220: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800224: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800228: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8080022C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800230: jal         0x800EFA4C
    // 0x80800234: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EFA4C(rdram, ctx);
        goto after_22;
    // 0x80800234: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_22:
    // 0x80800238: lbu         $t8, 0x34($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X34);
    // 0x8080023C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80800240: andi        $v0, $t9, 0xFF
    ctx->r2 = ctx->r25 & 0XFF;
    // 0x80800244: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80800248: bne         $at, $zero, L_80800258
    if (ctx->r1 != 0) {
        // 0x8080024C: sb          $t9, 0x34($s1)
        MEM_B(0X34, ctx->r17) = ctx->r25;
            goto L_80800258;
    }
    // 0x8080024C: sb          $t9, 0x34($s1)
    MEM_B(0X34, ctx->r17) = ctx->r25;
    // 0x80800250: sb          $zero, 0x34($s1)
    MEM_B(0X34, ctx->r17) = 0;
    // 0x80800254: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
L_80800258:
    // 0x80800258: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8080025C: addu        $t1, $s1, $t0
    ctx->r9 = ADD32(ctx->r17, ctx->r8);
    // 0x80800260: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x80800264: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80800268: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8080026C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800270:
    // 0x80800270: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800274: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800278: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8080027C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800280: jr          $ra
    // 0x80800284: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80800284: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_808005B4_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808005B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005BC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808005C0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808005C4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808005C8: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x808005CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005D0: jal         0x80103EF4
    // 0x808005D4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_80103EF4(rdram, ctx);
        goto after_0;
    // 0x808005D4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x808005D8: addiu       $s0, $sp, 0x2C
    ctx->r16 = ADD32(ctx->r29, 0X2C);
    // 0x808005DC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808005E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808005E4: jal         0x80089C30
    // 0x808005E8: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808005E8: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_1:
    // 0x808005EC: beq         $v0, $zero, L_80800654
    if (ctx->r2 == 0) {
        // 0x808005F0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800654;
    }
    // 0x808005F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_808005F4:
    // 0x808005F4: jal         0x80100094
    // 0x808005F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808005F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808005FC: lh          $t6, 0x2C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2C);
    // 0x80800600: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    // 0x80800604: bne         $s1, $t6, L_80800644
    if (ctx->r17 != ctx->r14) {
        // 0x80800608: nop
    
            goto L_80800644;
    }
    // 0x80800608: nop

    // 0x8080060C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800610: jal         0x800EE7F8
    // 0x80800614: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800614: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    after_3:
    // 0x80800618: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x8080061C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800620: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800624: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800628: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080062C: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80800630: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800634: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80800638: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8080063C: b           L_80800694
    // 0x80800640: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
        goto L_80800694;
    // 0x80800640: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
L_80800644:
    // 0x80800644: jal         0x80089C38
    // 0x80800648: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddiefind_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800648: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8080064C: bne         $v0, $zero, L_808005F4
    if (ctx->r2 != 0) {
        // 0x80800650: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808005F4;
    }
    // 0x80800650: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80800654:
    // 0x80800654: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800658: jal         0x80100094
    // 0x8080065C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x8080065C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800660: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800664: jal         0x800EE7F8
    // 0x80800668: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800668: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    after_6:
    // 0x8080066C: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x80800670: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800674: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800678: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080067C: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800680: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80800684: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80800688: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8080068C: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80800690: swc1        $f16, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f16.u32l;
L_80800694:
    // 0x80800694: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800698: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080069C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808006A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808006A4: jr          $ra
    // 0x808006A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808006A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80805798_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805798: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080579C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808057A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808057A4: jal         0x80100094
    // 0x808057A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808057A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808057AC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808057B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808057B4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x808057B8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x808057BC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808057C0: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x808057C4: lh          $v0, 0x34($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X34);
    // 0x808057C8: jr          $ra
    // 0x808057CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808057CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void chlavahand_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E00: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2332, 0X13D0) << 16);
    // 0x80800E04: jr          $ra
    // 0x80800E08: addiu       $v0, $v0, 0x13D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2332, 0X13D0));
    return;
    // 0x80800E08: addiu       $v0, $v0, 0x13D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2332, 0X13D0));
;}
RECOMP_FUNC void func_80803D64_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803D64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803D68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803D6C: jal         0x80100094
    // 0x80803D70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803D70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803D74: lh          $t6, 0x72($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X72);
    // 0x80803D78: beql        $t6, $zero, L_80803D8C
    if (ctx->r14 == 0) {
        // 0x80803D7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80803D8C;
    }
    goto skip_0;
    // 0x80803D7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80803D80: jal         0x80085710
    // 0x80803D84: sh          $zero, 0x72($v0)
    MEM_H(0X72, ctx->r2) = 0;
    _capod_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80803D84: sh          $zero, 0x72($v0)
    MEM_H(0X72, ctx->r2) = 0;
    after_1:
    // 0x80803D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803D8C:
    // 0x80803D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803D90: jr          $ra
    // 0x80803D94: nop

    return;
    // 0x80803D94: nop

;}
RECOMP_FUNC void ncbafly_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800250: jr          $ra
    // 0x80800254: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800254: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800258: nop

    // 0x8080025C: nop

;}
RECOMP_FUNC void func_800FFA88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFA88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FFA8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FFA90: jal         0x80106790
    // 0x800FFA94: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x800FFA94: nop

    after_0:
    // 0x800FFA98: jal         0x800FFAB0
    // 0x800FFA9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x800FFA9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800FFAA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FFAA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FFAA8: jr          $ra
    // 0x800FFAAC: nop

    return;
    // 0x800FFAAC: nop

;}
RECOMP_FUNC void func_80800534_basetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800534: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800538: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080053C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800540: jal         0x800DB9B0
    // 0x80800544: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800DB9B0(rdram, ctx);
        goto after_0;
    // 0x80800544: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800548: bne         $v0, $zero, L_80800560
    if (ctx->r2 != 0) {
        // 0x8080054C: nop
    
            goto L_80800560;
    }
    // 0x8080054C: nop

    // 0x80800550: jal         0x800887B0
    // 0x80800554: nop

    _glcutDll_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800554: nop

    after_1:
    // 0x80800558: beq         $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x8080055C: nop
    
            goto L_80800570;
    }
    // 0x8080055C: nop

L_80800560:
    // 0x80800560: jal         0x80800394
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800394_basetup(rdram, ctx);
        goto after_2;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800568: b           L_808006DC
    // 0x8080056C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006DC;
    // 0x8080056C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800570:
    // 0x80800570: jal         0x8008DAA8
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DAA8(rdram, ctx);
        goto after_3;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800578: bne         $v0, $zero, L_808005E4
    if (ctx->r2 != 0) {
        // 0x8080057C: nop
    
            goto L_808005E4;
    }
    // 0x8080057C: nop

    // 0x80800580: jal         0x80800394
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800394_basetup(rdram, ctx);
        goto after_4;
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800588: jal         0x800F99FC
    // 0x8080058C: nop

    func_800F99FC(rdram, ctx);
        goto after_5;
    // 0x8080058C: nop

    after_5:
    // 0x80800590: bne         $v0, $zero, L_808005DC
    if (ctx->r2 != 0) {
        // 0x80800594: nop
    
            goto L_808005DC;
    }
    // 0x80800594: nop

    // 0x80800598: jal         0x800F99E8
    // 0x8080059C: nop

    func_800F99E8(rdram, ctx);
        goto after_6;
    // 0x8080059C: nop

    after_6:
    // 0x808005A0: bne         $v0, $zero, L_808005DC
    if (ctx->r2 != 0) {
        // 0x808005A4: nop
    
            goto L_808005DC;
    }
    // 0x808005A4: nop

    // 0x808005A8: jal         0x800F8B7C
    // 0x808005AC: nop

    func_800F8B7C(rdram, ctx);
        goto after_7;
    // 0x808005AC: nop

    after_7:
    // 0x808005B0: beq         $v0, $zero, L_808005DC
    if (ctx->r2 == 0) {
        // 0x808005B4: nop
    
            goto L_808005DC;
    }
    // 0x808005B4: nop

    // 0x808005B8: jal         0x8008E23C
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E23C(rdram, ctx);
        goto after_8;
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808005C0: beq         $v0, $zero, L_808005DC
    if (ctx->r2 == 0) {
        // 0x808005C4: nop
    
            goto L_808005DC;
    }
    // 0x808005C4: nop

    // 0x808005C8: jal         0x800F8A50
    // 0x808005CC: nop

    func_800F8A50(rdram, ctx);
        goto after_9;
    // 0x808005CC: nop

    after_9:
    // 0x808005D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005D4: jal         0x80087920
    // 0x808005D8: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    _plcamera_entrypoint_13(rdram, ctx);
        goto after_10;
    // 0x808005D8: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_10:
L_808005DC:
    // 0x808005DC: b           L_808006DC
    // 0x808005E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006DC;
    // 0x808005E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005E4:
    // 0x808005E4: jal         0x800F99FC
    // 0x808005E8: nop

    func_800F99FC(rdram, ctx);
        goto after_11;
    // 0x808005E8: nop

    after_11:
    // 0x808005EC: beq         $v0, $zero, L_80800618
    if (ctx->r2 == 0) {
        // 0x808005F0: nop
    
            goto L_80800618;
    }
    // 0x808005F0: nop

    // 0x808005F4: jal         0x800A3274
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_12;
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808005FC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800600: bne         $v0, $at, L_80800610
    if (ctx->r2 != ctx->r1) {
        // 0x80800604: nop
    
            goto L_80800610;
    }
    // 0x80800604: nop

    // 0x80800608: jal         0x808002D4
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002D4_basetup(rdram, ctx);
        goto after_13;
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
L_80800610:
    // 0x80800610: b           L_808006DC
    // 0x80800614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006DC;
    // 0x80800614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800618:
    // 0x80800618: jal         0x800F99E8
    // 0x8080061C: nop

    func_800F99E8(rdram, ctx);
        goto after_14;
    // 0x8080061C: nop

    after_14:
    // 0x80800620: beq         $v0, $zero, L_80800638
    if (ctx->r2 == 0) {
        // 0x80800624: nop
    
            goto L_80800638;
    }
    // 0x80800624: nop

    // 0x80800628: jal         0x80800394
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800394_basetup(rdram, ctx);
        goto after_15;
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800630: b           L_808006DC
    // 0x80800634: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006DC;
    // 0x80800634: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800638:
    // 0x80800638: jal         0x800F8B7C
    // 0x8080063C: nop

    func_800F8B7C(rdram, ctx);
        goto after_16;
    // 0x8080063C: nop

    after_16:
    // 0x80800640: beq         $v0, $zero, L_808006B8
    if (ctx->r2 == 0) {
        // 0x80800644: nop
    
            goto L_808006B8;
    }
    // 0x80800644: nop

    // 0x80800648: jal         0x8008E23C
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E23C(rdram, ctx);
        goto after_17;
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800650: beq         $v0, $zero, L_808006B8
    if (ctx->r2 == 0) {
        // 0x80800654: nop
    
            goto L_808006B8;
    }
    // 0x80800654: nop

    // 0x80800658: jal         0x800A3274
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_18;
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800660: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800664: jal         0x800F89E4
    // 0x80800668: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F89E4(rdram, ctx);
        goto after_19;
    // 0x80800668: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_19:
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800670: jal         0x800F452C
    // 0x80800674: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F452C(rdram, ctx);
        goto after_20;
    // 0x80800674: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_20:
    // 0x80800678: jal         0x800F8A50
    // 0x8080067C: nop

    func_800F8A50(rdram, ctx);
        goto after_21;
    // 0x8080067C: nop

    after_21:
    // 0x80800680: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800684: jal         0x8009C914
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_22;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8080068C: jal         0x8009C974
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_23;
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800694: jal         0x800F8A50
    // 0x80800698: nop

    func_800F8A50(rdram, ctx);
        goto after_24;
    // 0x80800698: nop

    after_24:
    // 0x8080069C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808006A0: jal         0x80087920
    // 0x808006A4: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    _plcamera_entrypoint_13(rdram, ctx);
        goto after_25;
    // 0x808006A4: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_25:
    // 0x808006A8: jal         0x80800394
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800394_basetup(rdram, ctx);
        goto after_26;
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x808006B0: b           L_808006DC
    // 0x808006B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006DC;
    // 0x808006B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006B8:
    // 0x808006B8: jal         0x8009EA64
    // 0x808006BC: nop

    func_8009EA64(rdram, ctx);
        goto after_27;
    // 0x808006BC: nop

    after_27:
    // 0x808006C0: beql        $v0, $zero, L_808006DC
    if (ctx->r2 == 0) {
        // 0x808006C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808006DC;
    }
    goto skip_0;
    // 0x808006C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808006C8: jal         0x80800394
    // 0x808006CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800394_basetup(rdram, ctx);
        goto after_28;
    // 0x808006CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x808006D0: b           L_808006DC
    // 0x808006D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006DC;
    // 0x808006D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808006D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006DC:
    // 0x808006DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808006E8: jr          $ra
    // 0x808006EC: nop

    return;
    // 0x808006EC: nop

;}
RECOMP_FUNC void func_80804B4C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804B4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804B50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804B54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80804B58: lw          $a0, 0x28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X28);
    // 0x80804B5C: jal         0x80801658
    // 0x80804B60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801658_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80804B60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80804B64: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80804B68: jal         0x80803D00
    // 0x80804B6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80803D00_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80804B6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80804B70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80804B74: jal         0x80804C30
    // 0x80804B78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80804C30_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80804B78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80804B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804B80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804B84: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80804B88: jr          $ra
    // 0x80804B8C: nop

    return;
    // 0x80804B8C: nop

;}
RECOMP_FUNC void func_80801794_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801794: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080179C: jal         0x800D3948
    // 0x808017A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x808017A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808017A4: beq         $v0, $zero, L_80801894
    if (ctx->r2 == 0) {
        // 0x808017A8: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80801894;
    }
    // 0x808017A8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808017AC: lw          $v0, 0x80($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X80);
    // 0x808017B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808017B4: slti        $t7, $v0, 0x0
    ctx->r15 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x808017B8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x808017BC: beq         $t7, $at, L_808017E4
    if (ctx->r15 == ctx->r1) {
        // 0x808017C0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808017E4;
    }
    // 0x808017C0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808017C4: beq         $t7, $at, L_808017F4
    if (ctx->r15 == ctx->r1) {
        // 0x808017C8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_808017F4;
    }
    // 0x808017C8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808017CC: beq         $t7, $at, L_80801804
    if (ctx->r15 == ctx->r1) {
        // 0x808017D0: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80801804;
    }
    // 0x808017D0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808017D4: beq         $t7, $at, L_80801814
    if (ctx->r15 == ctx->r1) {
        // 0x808017D8: nop
    
            goto L_80801814;
    }
    // 0x808017D8: nop

    // 0x808017DC: b           L_80801820
    // 0x808017E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80801820;
    // 0x808017E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808017E4:
    // 0x808017E4: jal         0x800D28A0
    // 0x808017E8: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    func_800D28A0(rdram, ctx);
        goto after_1;
    // 0x808017E8: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    after_1:
    // 0x808017EC: b           L_80801820
    // 0x808017F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80801820;
    // 0x808017F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808017F4:
    // 0x808017F4: jal         0x800D28A0
    // 0x808017F8: addiu       $a0, $zero, 0x114
    ctx->r4 = ADD32(0, 0X114);
    func_800D28A0(rdram, ctx);
        goto after_2;
    // 0x808017F8: addiu       $a0, $zero, 0x114
    ctx->r4 = ADD32(0, 0X114);
    after_2:
    // 0x808017FC: b           L_80801820
    // 0x80801800: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80801820;
    // 0x80801800: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80801804:
    // 0x80801804: jal         0x800D28A0
    // 0x80801808: addiu       $a0, $zero, 0x115
    ctx->r4 = ADD32(0, 0X115);
    func_800D28A0(rdram, ctx);
        goto after_3;
    // 0x80801808: addiu       $a0, $zero, 0x115
    ctx->r4 = ADD32(0, 0X115);
    after_3:
    // 0x8080180C: b           L_80801820
    // 0x80801810: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80801820;
    // 0x80801810: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80801814:
    // 0x80801814: jal         0x800D28A0
    // 0x80801818: addiu       $a0, $zero, 0x113
    ctx->r4 = ADD32(0, 0X113);
    func_800D28A0(rdram, ctx);
        goto after_4;
    // 0x80801818: addiu       $a0, $zero, 0x113
    ctx->r4 = ADD32(0, 0X113);
    after_4:
    // 0x8080181C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80801820:
    // 0x80801820: jal         0x80801784
    // 0x80801824: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801784_chquiz(rdram, ctx);
        goto after_5;
    // 0x80801824: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80801828: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    // 0x8080182C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801830: jal         0x800D2498
    // 0x80801834: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_6;
    // 0x80801834: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80801838: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080183C: jal         0x80801784
    // 0x80801840: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80801784_chquiz(rdram, ctx);
        goto after_7;
    // 0x80801840: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x80801844: addiu       $a0, $zero, 0x114
    ctx->r4 = ADD32(0, 0X114);
    // 0x80801848: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080184C: jal         0x800D2498
    // 0x80801850: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_8;
    // 0x80801850: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80801854: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801858: jal         0x80801784
    // 0x8080185C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80801784_chquiz(rdram, ctx);
        goto after_9;
    // 0x8080185C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
    // 0x80801860: addiu       $a0, $zero, 0x115
    ctx->r4 = ADD32(0, 0X115);
    // 0x80801864: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801868: jal         0x800D2498
    // 0x8080186C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_10;
    // 0x8080186C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80801870: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801874: jal         0x80801784
    // 0x80801878: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80801784_chquiz(rdram, ctx);
        goto after_11;
    // 0x80801878: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_11:
    // 0x8080187C: addiu       $a0, $zero, 0x113
    ctx->r4 = ADD32(0, 0X113);
    // 0x80801880: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801884: jal         0x800D2498
    // 0x80801888: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_12;
    // 0x80801888: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x8080188C: b           L_80801924
    // 0x80801890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801924;
    // 0x80801890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801894:
    // 0x80801894: jal         0x800DA298
    // 0x80801898: addiu       $a0, $zero, 0x582
    ctx->r4 = ADD32(0, 0X582);
    func_800DA298(rdram, ctx);
        goto after_13;
    // 0x80801898: addiu       $a0, $zero, 0x582
    ctx->r4 = ADD32(0, 0X582);
    after_13:
    // 0x8080189C: bne         $v0, $zero, L_808018BC
    if (ctx->r2 != 0) {
        // 0x808018A0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808018BC;
    }
    // 0x808018A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808018A4: jal         0x80801784
    // 0x808018A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801784_chquiz(rdram, ctx);
        goto after_14;
    // 0x808018A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x808018AC: addiu       $a0, $zero, 0x10F
    ctx->r4 = ADD32(0, 0X10F);
    // 0x808018B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808018B4: jal         0x800D2498
    // 0x808018B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_15;
    // 0x808018B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
L_808018BC:
    // 0x808018BC: jal         0x800DA298
    // 0x808018C0: addiu       $a0, $zero, 0x583
    ctx->r4 = ADD32(0, 0X583);
    func_800DA298(rdram, ctx);
        goto after_16;
    // 0x808018C0: addiu       $a0, $zero, 0x583
    ctx->r4 = ADD32(0, 0X583);
    after_16:
    // 0x808018C4: bne         $v0, $zero, L_808018E4
    if (ctx->r2 != 0) {
        // 0x808018C8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808018E4;
    }
    // 0x808018C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808018CC: jal         0x80801784
    // 0x808018D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801784_chquiz(rdram, ctx);
        goto after_17;
    // 0x808018D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x808018D4: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x808018D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808018DC: jal         0x800D2498
    // 0x808018E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_18;
    // 0x808018E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
L_808018E4:
    // 0x808018E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808018E8: jal         0x80801784
    // 0x808018EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801784_chquiz(rdram, ctx);
        goto after_19;
    // 0x808018EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_19:
    // 0x808018F0: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    // 0x808018F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808018F8: jal         0x800D2498
    // 0x808018FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_20;
    // 0x808018FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_20:
    // 0x80801900: jal         0x8008A7D8
    // 0x80801904: nop

    _suquiz_entrypoint_4(rdram, ctx);
        goto after_21;
    // 0x80801904: nop

    after_21:
    // 0x80801908: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080190C: bne         $v0, $at, L_80801920
    if (ctx->r2 != ctx->r1) {
        // 0x80801910: addiu       $a0, $zero, 0x118
        ctx->r4 = ADD32(0, 0X118);
            goto L_80801920;
    }
    // 0x80801910: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    // 0x80801914: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80801918: jal         0x800D2498
    // 0x8080191C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_22;
    // 0x8080191C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_22:
L_80801920:
    // 0x80801920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801924:
    // 0x80801924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801928: jr          $ra
    // 0x8080192C: nop

    return;
    // 0x8080192C: nop

;}
RECOMP_FUNC void _glpackvtx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088798: syscall     704
    recomp_syscall_handler(rdram, ctx, 0x80088798);
    return;
    // 0x8008879C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void badrone_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(488, 0X630) << 16);
    // 0x80800010: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80800014: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80800018: jr          $ra
    // 0x8080001C: lbu         $v0, 0x630($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(488, 0X630));
    return;
    // 0x8080001C: lbu         $v0, 0x630($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(488, 0X630));
;}
RECOMP_FUNC void _bsfirstp_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800842A0: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x800842A0);
    return;
    // 0x800842A4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808003EC_chboilerid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003F8: jal         0x800DA524
    // 0x808003FC: addiu       $a0, $zero, 0x66F
    ctx->r4 = ADD32(0, 0X66F);
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x808003FC: addiu       $a0, $zero, 0x66F
    ctx->r4 = ADD32(0, 0X66F);
    after_0:
    // 0x80800400: jal         0x800CF494
    // 0x80800404: nop

    func_800CF494(rdram, ctx);
        goto after_1;
    // 0x80800404: nop

    after_1:
    // 0x80800408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080040C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800410: jr          $ra
    // 0x80800414: nop

    return;
    // 0x80800414: nop

;}
RECOMP_FUNC void _bsdroneslide_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083140: syscall     46
    recomp_syscall_handler(rdram, ctx, 0x80083140);
    return;
    // 0x80083144: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808037B0_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808037B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808037B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808037B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808037BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808037C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808037C4: jal         0x80106790
    // 0x808037C8: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808037C8: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808037CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808037D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808037D4: jal         0x80100094
    // 0x808037D8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808037D8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x808037DC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808037E0: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x808037E4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808037E8: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808037EC: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x808037F0: lb          $t8, 0x8($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X8);
    // 0x808037F4: lbu         $t9, 0x4($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4);
    // 0x808037F8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x808037FC: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80803800: beql        $at, $zero, L_8080389C
    if (ctx->r1 == 0) {
        // 0x80803804: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080389C;
    }
    goto skip_0;
    // 0x80803804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80803808: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x8080380C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80803810: srl         $t1, $v0, 10
    ctx->r9 = S32(U32(ctx->r2) >> 10);
    // 0x80803814: beq         $t1, $at, L_80803824
    if (ctx->r9 == ctx->r1) {
        // 0x80803818: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80803824;
    }
    // 0x80803818: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080381C: bnel        $t1, $at, L_8080389C
    if (ctx->r9 != ctx->r1) {
        // 0x80803820: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080389C;
    }
    goto skip_1;
    // 0x80803820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_80803824:
    // 0x80803824: jal         0x808003F8
    // 0x80803828: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_808003F8_chdragonbrothers(rdram, ctx);
        goto after_2;
    // 0x80803828: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x8080382C: beq         $v0, $zero, L_80803898
    if (ctx->r2 == 0) {
        // 0x80803830: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803898;
    }
    // 0x80803830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803834: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1852, 0X543C) << 16);
    // 0x80803838: addiu       $a2, $a2, 0x543C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X543C));
    // 0x8080383C: jal         0x80089D18
    // 0x80803840: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80803840: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80803844: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80803848: lbu         $t7, 0x79($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X79);
    // 0x8080384C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803850: addiu       $t4, $t2, -0x26B
    ctx->r12 = ADD32(ctx->r10, -0X26B);
    // 0x80803854: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x80803858: andi        $t8, $t7, 0xFF0F
    ctx->r24 = ctx->r15 & 0XFF0F;
    // 0x8080385C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80803860: sb          $t9, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r25;
    // 0x80803864: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80803868: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8080386C: srl         $t1, $t0, 4
    ctx->r9 = S32(U32(ctx->r8) >> 4);
    // 0x80803870: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80803874: jal         0x808036EC
    // 0x80803878: sb          $t1, 0x5C($t2)
    MEM_B(0X5C, ctx->r10) = ctx->r9;
    func_808036EC_chdragonbrothers(rdram, ctx);
        goto after_4;
    // 0x80803878: sb          $t1, 0x5C($t2)
    MEM_B(0X5C, ctx->r10) = ctx->r9;
    after_4:
    // 0x8080387C: lhu         $t4, 0x76($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X76);
    // 0x80803880: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80803884: srl         $t5, $t4, 7
    ctx->r13 = S32(U32(ctx->r12) >> 7);
    // 0x80803888: addu        $v0, $t3, $t5
    ctx->r2 = ADD32(ctx->r11, ctx->r13);
    // 0x8080388C: lb          $t7, 0x8($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X8);
    // 0x80803890: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x80803894: sb          $t6, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r14;
L_80803898:
    // 0x80803898: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080389C:
    // 0x8080389C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808038A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808038A4: jr          $ra
    // 0x808038A8: nop

    return;
    // 0x808038A8: nop

;}
