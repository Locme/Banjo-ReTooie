#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800F0E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0E7C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800F0E80: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800F0E84: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800F0E88: add.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x800F0E8C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800F0E90: nop

    // 0x800F0E94: bc1fl       L_800F0EBC
    if (!c1cs) {
        // 0x800F0E98: sub.s       $f0, $f14, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f2.fl;
            goto L_800F0EBC;
    }
    goto skip_0;
    // 0x800F0E98: sub.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f2.fl;
    skip_0:
    // 0x800F0E9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800F0EA0: nop

    // 0x800F0EA4: sub.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f16.fl;
L_800F0EA8:
    // 0x800F0EA8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800F0EAC: nop

    // 0x800F0EB0: bc1tl       L_800F0EA8
    if (c1cs) {
        // 0x800F0EB4: sub.s       $f12, $f12, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f16.fl;
            goto L_800F0EA8;
    }
    goto skip_1;
    // 0x800F0EB4: sub.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f16.fl;
    skip_1:
    // 0x800F0EB8: sub.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f2.fl;
L_800F0EBC:
    // 0x800F0EBC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800F0EC0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800F0EC4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800F0EC8: nop

    // 0x800F0ECC: bc1f        L_800F0EE8
    if (!c1cs) {
        // 0x800F0ED0: nop
    
            goto L_800F0EE8;
    }
    // 0x800F0ED0: nop

    // 0x800F0ED4: add.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f16.fl;
L_800F0ED8:
    // 0x800F0ED8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800F0EDC: nop

    // 0x800F0EE0: bc1tl       L_800F0ED8
    if (c1cs) {
        // 0x800F0EE4: add.s       $f12, $f12, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f16.fl;
            goto L_800F0ED8;
    }
    goto skip_2;
    // 0x800F0EE4: add.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f16.fl;
    skip_2:
L_800F0EE8:
    // 0x800F0EE8: jr          $ra
    // 0x800F0EEC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x800F0EEC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
;}
RECOMP_FUNC void func_80024A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024A5C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80024A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024A64: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80024A68: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80024A6C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80024A70: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x80024A74: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80024A78: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80024A7C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80024A80: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80024A84: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80024A88: lbu         $t9, 0x8($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X8);
    // 0x80024A8C: bne         $t9, $at, L_80024C84
    if (ctx->r25 != ctx->r1) {
        // 0x80024A90: nop
    
            goto L_80024C84;
    }
    // 0x80024A90: nop

    // 0x80024A94: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80024A98: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80024A9C: lbu         $t1, 0x9($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X9);
    // 0x80024AA0: bne         $t1, $at, L_80024C84
    if (ctx->r9 != ctx->r1) {
        // 0x80024AA4: nop
    
            goto L_80024C84;
    }
    // 0x80024AA4: nop

    // 0x80024AA8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80024AAC: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x80024AB0: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80024AB4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80024AB8: lbu         $t5, 0x7($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X7);
    // 0x80024ABC: lbu         $t7, 0x8($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X8);
    // 0x80024AC0: lbu         $t0, 0x9($t4)
    ctx->r8 = MEM_BU(ctx->r12, 0X9);
    // 0x80024AC4: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80024AC8: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80024ACC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80024AD0: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x80024AD4: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80024AD8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80024ADC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80024AE0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80024AE4: nop

    // 0x80024AE8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80024AEC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80024AF0: jal         0x80024D90
    // 0x80024AF4: nop

    func_80024D90(rdram, ctx);
        goto after_0;
    // 0x80024AF4: nop

    after_0:
    // 0x80024AF8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80024AFC: lw          $t5, 0x50($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X50);
    // 0x80024B00: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80024B04: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80024B08: beq         $t7, $zero, L_80024BE4
    if (ctx->r15 == 0) {
        // 0x80024B0C: nop
    
            goto L_80024BE4;
    }
    // 0x80024B0C: nop

L_80024B10:
    // 0x80024B10: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80024B14: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80024B18: lw          $t4, 0x8($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X8);
    // 0x80024B1C: addu        $t9, $t6, $t4
    ctx->r25 = ADD32(ctx->r14, ctx->r12);
    // 0x80024B20: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80024B24: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80024B28: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80024B2C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80024B30: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80024B34: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80024B38: lh          $t3, 0xC($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XC);
    // 0x80024B3C: bne         $t3, $at, L_80024BD0
    if (ctx->r11 != ctx->r1) {
        // 0x80024B40: nop
    
            goto L_80024BD0;
    }
    // 0x80024B40: nop

    // 0x80024B44: jal         0x80020E74
    // 0x80024B48: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80020E74(rdram, ctx);
        goto after_1;
    // 0x80024B48: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80024B4C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80024B50: beq         $t5, $zero, L_80024B6C
    if (ctx->r13 == 0) {
        // 0x80024B54: nop
    
            goto L_80024B6C;
    }
    // 0x80024B54: nop

    // 0x80024B58: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80024B5C: jal         0x80020E40
    // 0x80024B60: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80020E40(rdram, ctx);
        goto after_2;
    // 0x80024B60: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80024B64: b           L_80024B84
    // 0x80024B68: nop

        goto L_80024B84;
    // 0x80024B68: nop

L_80024B6C:
    // 0x80024B6C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80024B70: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x80024B74: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80024B78: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80024B7C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80024B80: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80024B84:
    // 0x80024B84: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80024B88: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80024B8C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80024B90: beq         $t9, $zero, L_80024BC4
    if (ctx->r25 == 0) {
        // 0x80024B94: nop
    
            goto L_80024BC4;
    }
    // 0x80024B94: nop

    // 0x80024B98: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80024B9C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80024BA0: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80024BA4: subu        $t3, $t0, $t2
    ctx->r11 = SUB32(ctx->r8, ctx->r10);
    // 0x80024BA8: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80024BAC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80024BB0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80024BB4: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x80024BB8: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x80024BBC: addu        $t4, $t7, $t6
    ctx->r12 = ADD32(ctx->r15, ctx->r14);
    // 0x80024BC0: sw          $t4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r12;
L_80024BC4:
    // 0x80024BC4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80024BC8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80024BCC: sw          $t9, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r25;
L_80024BD0:
    // 0x80024BD0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80024BD4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80024BD8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80024BDC: bne         $t2, $zero, L_80024B10
    if (ctx->r10 != 0) {
        // 0x80024BE0: nop
    
            goto L_80024B10;
    }
    // 0x80024BE0: nop

L_80024BE4:
    // 0x80024BE4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80024BE8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80024BEC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80024BF0: beq         $t8, $zero, L_80024C84
    if (ctx->r24 == 0) {
        // 0x80024BF4: nop
    
            goto L_80024C84;
    }
    // 0x80024BF4: nop

L_80024BF8:
    // 0x80024BF8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80024BFC: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80024C00: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80024C04: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80024C08: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80024C0C: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80024C10: div         $zero, $t5, $t9
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r25)));
    // 0x80024C14: mflo        $t1
    ctx->r9 = lo;
    // 0x80024C18: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80024C1C: bne         $t9, $zero, L_80024C28
    if (ctx->r25 != 0) {
        // 0x80024C20: nop
    
            goto L_80024C28;
    }
    // 0x80024C20: nop

    // 0x80024C24: break       7
    do_break(2147634212);
L_80024C28:
    // 0x80024C28: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024C2C: bne         $t9, $at, L_80024C40
    if (ctx->r25 != ctx->r1) {
        // 0x80024C30: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80024C40;
    }
    // 0x80024C30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024C34: bne         $t5, $at, L_80024C40
    if (ctx->r13 != ctx->r1) {
        // 0x80024C38: nop
    
            goto L_80024C40;
    }
    // 0x80024C38: nop

    // 0x80024C3C: break       6
    do_break(2147634236);
L_80024C40:
    // 0x80024C40: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80024C44: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80024C48: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80024C4C: lw          $t2, 0x24($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X24);
    // 0x80024C50: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024C54: mflo        $t8
    ctx->r24 = lo;
    // 0x80024C58: sw          $t8, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r24;
    // 0x80024C5C: nop

    // 0x80024C60: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80024C64: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80024C68: jal         0x80024C9C
    // 0x80024C6C: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80024C9C(rdram, ctx);
        goto after_3;
    // 0x80024C6C: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_3:
    // 0x80024C70: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80024C74: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80024C78: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80024C7C: bne         $t4, $zero, L_80024BF8
    if (ctx->r12 != 0) {
        // 0x80024C80: nop
    
            goto L_80024BF8;
    }
    // 0x80024C80: nop

L_80024C84:
    // 0x80024C84: b           L_80024C8C
    // 0x80024C88: nop

        goto L_80024C8C;
    // 0x80024C88: nop

L_80024C8C:
    // 0x80024C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024C90: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80024C94: jr          $ra
    // 0x80024C98: nop

    return;
    // 0x80024C98: nop

;}
RECOMP_FUNC void func_80801390_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801390: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801394: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801398: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080139C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808013A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808013A4: jal         0x800845C8
    // 0x808013A8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    _babounce_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808013A8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x808013AC: beq         $v0, $zero, L_808013BC
    if (ctx->r2 == 0) {
        // 0x808013B0: nop
    
            goto L_808013BC;
    }
    // 0x808013B0: nop

    // 0x808013B4: jal         0x808001D4
    // 0x808013B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001D4_bsbansack(rdram, ctx);
        goto after_1;
    // 0x808013B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_808013BC:
    // 0x808013BC: jal         0x80084608
    // 0x808013C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x808013C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808013C4: jal         0x8080119C
    // 0x808013C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080119C_bsbansack(rdram, ctx);
        goto after_3;
    // 0x808013C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808013CC: beq         $v0, $zero, L_808013D8
    if (ctx->r2 == 0) {
        // 0x808013D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808013D8;
    }
    // 0x808013D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013D4: addiu       $s1, $zero, 0x165
    ctx->r17 = ADD32(0, 0X165);
L_808013D8:
    // 0x808013D8: jal         0x8008DF8C
    // 0x808013DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008DF8C(rdram, ctx);
        goto after_4;
    // 0x808013DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808013E0: beql        $v0, $zero, L_8080140C
    if (ctx->r2 == 0) {
        // 0x808013E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080140C;
    }
    goto skip_0;
    // 0x808013E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808013E8: jal         0x8009EF10
    // 0x808013EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_5;
    // 0x808013EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808013F0: blez        $v0, L_808013FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808013F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808013FC;
    }
    // 0x808013F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013F8: addiu       $s1, $zero, 0x166
    ctx->r17 = ADD32(0, 0X166);
L_808013FC:
    // 0x808013FC: jal         0x80800084
    // 0x80801400: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800084_bsbansack(rdram, ctx);
        goto after_6;
    // 0x80801400: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x80801404: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080140C:
    // 0x8080140C: jal         0x8009E5C8
    // 0x80801410: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x80801410: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x80801414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801418: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080141C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801420: jr          $ra
    // 0x80801424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80801424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _bsbansack_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800826D8: syscall     7
    recomp_syscall_handler(rdram, ctx, 0x800826D8);
    return;
    // 0x800826DC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _bsmum_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083808: syscall     75
    recomp_syscall_handler(rdram, ctx, 0x80083808);
    return;
    // 0x8008380C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_801041A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801041A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801041A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801041A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801041AC: jal         0x800B3248
    // 0x801041B0: lw          $a0, 0x6E70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6E70);
    freelist_free(rdram, ctx);
        goto after_0;
    // 0x801041B0: lw          $a0, 0x6E70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6E70);
    after_0:
    // 0x801041B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801041B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801041BC: sw          $zero, 0x6E70($at)
    MEM_W(0X6E70, ctx->r1) = 0;
    // 0x801041C0: jr          $ra
    // 0x801041C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801041C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _chdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086240: syscall     293
    recomp_syscall_handler(rdram, ctx, 0x80086240);
    return;
    // 0x80086244: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8002D328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D328: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002D32C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002D330: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8002D334: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002D338: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8002D33C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002D340: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x8002D344: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8002D348: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D34C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002D350: beq         $s0, $at, L_8002D384
    if (ctx->r16 == ctx->r1) {
        // 0x8002D354: nop
    
            goto L_8002D384;
    }
    // 0x8002D354: nop

    // 0x8002D358: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8002D35C: beq         $s0, $at, L_8002D3FC
    if (ctx->r16 == ctx->r1) {
        // 0x8002D360: nop
    
            goto L_8002D3FC;
    }
    // 0x8002D360: nop

    // 0x8002D364: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8002D368: beq         $s0, $at, L_8002D3A4
    if (ctx->r16 == ctx->r1) {
        // 0x8002D36C: nop
    
            goto L_8002D3A4;
    }
    // 0x8002D36C: nop

    // 0x8002D370: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8002D374: beq         $s0, $at, L_8002D3C8
    if (ctx->r16 == ctx->r1) {
        // 0x8002D378: nop
    
            goto L_8002D3C8;
    }
    // 0x8002D378: nop

    // 0x8002D37C: b           L_8002D410
    // 0x8002D380: nop

        goto L_8002D410;
    // 0x8002D380: nop

L_8002D384:
    // 0x8002D384: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8002D388: sh          $zero, 0x92($t7)
    MEM_H(0X92, ctx->r15) = 0;
    // 0x8002D38C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8002D390: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8002D394: jal         0x8002CC9C
    // 0x8002D398: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_8002CC9C(rdram, ctx);
        goto after_0;
    // 0x8002D398: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x8002D39C: b           L_8002D428
    // 0x8002D3A0: nop

        goto L_8002D428;
    // 0x8002D3A0: nop

L_8002D3A4:
    // 0x8002D3A4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8002D3A8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8002D3AC: sh          $t8, 0x92($t9)
    MEM_H(0X92, ctx->r25) = ctx->r24;
    // 0x8002D3B0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8002D3B4: lw          $t1, 0xB8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XB8);
    // 0x8002D3B8: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x8002D3BC: sw          $t2, 0xB8($t0)
    MEM_W(0XB8, ctx->r8) = ctx->r10;
    // 0x8002D3C0: b           L_8002D428
    // 0x8002D3C4: nop

        goto L_8002D428;
    // 0x8002D3C4: nop

L_8002D3C8:
    // 0x8002D3C8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8002D3CC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8002D3D0: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8002D3D4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8002D3D8: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8002D3DC: nop

    // 0x8002D3E0: sh          $t5, 0x90($t6)
    MEM_H(0X90, ctx->r14) = ctx->r13;
    // 0x8002D3E4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8002D3E8: lw          $t8, 0xB8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XB8);
    // 0x8002D3EC: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x8002D3F0: sw          $t9, 0xB8($t7)
    MEM_W(0XB8, ctx->r15) = ctx->r25;
    // 0x8002D3F4: b           L_8002D428
    // 0x8002D3F8: nop

        goto L_8002D428;
    // 0x8002D3F8: nop

L_8002D3FC:
    // 0x8002D3FC: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8002D400: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8002D404: sb          $t1, 0x8C($t2)
    MEM_B(0X8C, ctx->r10) = ctx->r9;
    // 0x8002D408: b           L_8002D428
    // 0x8002D40C: nop

        goto L_8002D428;
    // 0x8002D40C: nop

L_8002D410:
    // 0x8002D410: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8002D414: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D418: jal         0x8002CC9C
    // 0x8002D41C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_8002CC9C(rdram, ctx);
        goto after_1;
    // 0x8002D41C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8002D420: b           L_8002D428
    // 0x8002D424: nop

        goto L_8002D428;
    // 0x8002D424: nop

L_8002D428:
    // 0x8002D428: b           L_8002D438
    // 0x8002D42C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002D438;
    // 0x8002D42C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002D430: b           L_8002D438
    // 0x8002D434: nop

        goto L_8002D438;
    // 0x8002D434: nop

L_8002D438:
    // 0x8002D438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D43C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002D440: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002D444: jr          $ra
    // 0x8002D448: nop

    return;
    // 0x8002D448: nop

    // 0x8002D44C: nop

;}
RECOMP_FUNC void chanemone_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1032, 0X8D8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x8D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1032, 0X8D8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x8D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1032, 0X8D8));
;}
RECOMP_FUNC void gccubesearch_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006A8: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x808006AC: jal         0x80800590
    // 0x808006B0: addiu       $a3, $a3, -0x384
    ctx->r7 = ADD32(ctx->r7, -0X384);
    func_80800590_gccubesearch(rdram, ctx);
        goto after_0;
    // 0x808006B0: addiu       $a3, $a3, -0x384
    ctx->r7 = ADD32(ctx->r7, -0X384);
    after_0:
    // 0x808006B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006BC: jr          $ra
    // 0x808006C0: nop

    return;
    // 0x808006C0: nop

;}
RECOMP_FUNC void func_800A824C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A824C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A8250: jr          $ra
    // 0x800A8254: lh          $v0, 0x7636($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7636);
    return;
    // 0x800A8254: lh          $v0, 0x7636($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7636);
;}
RECOMP_FUNC void vpmodule_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800224: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800228: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080022C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800230: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800234: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800238: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080023C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800240: lw          $t7, 0x2C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X2C);
    // 0x80800244: addiu       $s0, $a0, 0x8
    ctx->r16 = ADD32(ctx->r4, 0X8);
    // 0x80800248: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(3002, 0X8C0) << 16);
    // 0x8080024C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80800250: addu        $s1, $t8, $a0
    ctx->r17 = ADD32(ctx->r24, ctx->r4);
    // 0x80800254: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80800258: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x8080025C: beq         $at, $zero, L_80800298
    if (ctx->r1 == 0) {
        // 0x80800260: addiu       $s3, $zero, 0x14
        ctx->r19 = ADD32(0, 0X14);
            goto L_80800298;
    }
    // 0x80800260: addiu       $s3, $zero, 0x14
    ctx->r19 = ADD32(0, 0X14);
    // 0x80800264: addiu       $s2, $s2, 0x8C0
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(3002, 0X8C0));
    // 0x80800268: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
L_8080026C:
    // 0x8080026C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80800270: multu       $t9, $s3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800274: mflo        $t0
    ctx->r8 = lo;
    // 0x80800278: addu        $t1, $s2, $t0
    ctx->r9 = ADD32(ctx->r18, ctx->r8);
    // 0x8080027C: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    // 0x80800280: jalr        $t9
    // 0x80800284: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80800284: nop

    after_0:
    // 0x80800288: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8080028C: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80800290: bnel        $at, $zero, L_8080026C
    if (ctx->r1 != 0) {
        // 0x80800294: lbu         $t9, 0x0($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X0);
            goto L_8080026C;
    }
    goto skip_0;
    // 0x80800294: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    skip_0:
L_80800298:
    // 0x80800298: jal         0x8001B084
    // 0x8080029C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    heap_free(rdram, ctx);
        goto after_1;
    // 0x8080029C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x808002A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808002A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808002A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808002AC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808002B0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808002B4: jr          $ra
    // 0x808002B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808002B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80801098_chjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801098: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080109C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808010A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808010A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808010A8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808010AC: lw          $a0, 0x6C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C);
    // 0x808010B0: andi        $t6, $a0, 0x1FF
    ctx->r14 = ctx->r4 & 0X1FF;
    // 0x808010B4: jal         0x800D0CC8
    // 0x808010B8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800D0CC8(rdram, ctx);
        goto after_0;
    // 0x808010B8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x808010BC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808010C0: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808010C4: lbu         $t9, 0x74($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X74);
    // 0x808010C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808010CC: andi        $t8, $t7, 0xFFF7
    ctx->r24 = ctx->r15 & 0XFFF7;
    // 0x808010D0: andi        $t0, $t9, 0xFFBF
    ctx->r8 = ctx->r25 & 0XFFBF;
    // 0x808010D4: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x808010D8: sb          $t0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r8;
    // 0x808010DC: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x808010E0: jal         0x800D1338
    // 0x808010E4: sw          $t1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r9;
    func_800D1338(rdram, ctx);
        goto after_1;
    // 0x808010E4: sw          $t1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r9;
    after_1:
    // 0x808010E8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808010EC: jal         0x800D129C
    // 0x808010F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800D129C(rdram, ctx);
        goto after_2;
    // 0x808010F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x808010F4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x808010F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808010FC: xor         $t3, $v0, $t2
    ctx->r11 = ctx->r2 ^ ctx->r10;
    // 0x80801100: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80801104: jal         0x800D035C
    // 0x80801108: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    func_800D035C(rdram, ctx);
        goto after_3;
    // 0x80801108: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_3:
    // 0x8080110C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801110: bne         $v0, $at, L_80801140
    if (ctx->r2 != ctx->r1) {
        // 0x80801114: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_80801140;
    }
    // 0x80801114: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80801118: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x8080111C: andi        $t4, $a0, 0x1FF
    ctx->r12 = ctx->r4 & 0X1FF;
    // 0x80801120: jal         0x800D0CC8
    // 0x80801124: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_800D0CC8(rdram, ctx);
        goto after_4;
    // 0x80801124: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_4:
    // 0x80801128: addiu       $a0, $zero, 0x6D0
    ctx->r4 = ADD32(0, 0X6D0);
    // 0x8080112C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801130: jal         0x800DA7A8
    // 0x80801134: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800DA7A8(rdram, ctx);
        goto after_5;
    // 0x80801134: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x80801138: b           L_80801190
    // 0x8080113C: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
        goto L_80801190;
    // 0x8080113C: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
L_80801140:
    // 0x80801140: beql        $t5, $zero, L_80801190
    if (ctx->r13 == 0) {
        // 0x80801144: lw          $v0, 0x74($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X74);
            goto L_80801190;
    }
    goto skip_0;
    // 0x80801144: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    skip_0:
    // 0x80801148: lbu         $t7, 0x74($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X74);
    // 0x8080114C: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    // 0x80801150: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x80801154: jal         0x800DA298
    // 0x80801158: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80801158: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
    after_6:
    // 0x8080115C: bne         $v0, $zero, L_80801184
    if (ctx->r2 != 0) {
        // 0x80801160: nop
    
            goto L_80801184;
    }
    // 0x80801160: nop

    // 0x80801164: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80801168: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x8080116C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801170: ori         $t1, $t0, 0x8
    ctx->r9 = ctx->r8 | 0X8;
    // 0x80801174: jal         0x800F82D4
    // 0x80801178: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    func_800F82D4(rdram, ctx);
        goto after_7;
    // 0x80801178: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    after_7:
    // 0x8080117C: b           L_80801190
    // 0x80801180: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
        goto L_80801190;
    // 0x80801180: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
L_80801184:
    // 0x80801184: jal         0x80800FC4
    // 0x80801188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800FC4_chjinjo(rdram, ctx);
        goto after_8;
    // 0x80801188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080118C: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
L_80801190:
    // 0x80801190: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801194: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801198: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x8080119C: srl         $v0, $t2, 31
    ctx->r2 = S32(U32(ctx->r10) >> 31);
    // 0x808011A0: jr          $ra
    // 0x808011A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808011A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _fxgenlist_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B08: syscall     723
    recomp_syscall_handler(rdram, ctx, 0x80088B08);
    return;
    // 0x80088B0C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8008EE88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EE88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008EE8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008EE90: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8008EE94: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008EE98: jal         0x8009C128
    // 0x8008EE9C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8008EE9C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8008EEA0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008EEA4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8008EEA8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EEAC: jal         0x8008EEC4
    // 0x8008EEB0: addiu       $a3, $zero, 0x270
    ctx->r7 = ADD32(0, 0X270);
    func_8008EEC4(rdram, ctx);
        goto after_1;
    // 0x8008EEB0: addiu       $a3, $zero, 0x270
    ctx->r7 = ADD32(0, 0X270);
    after_1:
    // 0x8008EEB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008EEB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008EEBC: jr          $ra
    // 0x8008EEC0: nop

    return;
    // 0x8008EEC0: nop

;}
RECOMP_FUNC void func_800BDC90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDC90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BDC94: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800BDC98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BDC9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BDCA0: jal         0x80087C70
    // 0x800BDCA4: addiu       $a0, $a0, -0x7BF0
    ctx->r4 = ADD32(ctx->r4, -0X7BF0);
    _gccubeDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x800BDCA4: addiu       $a0, $a0, -0x7BF0
    ctx->r4 = ADD32(ctx->r4, -0X7BF0);
    after_0:
    // 0x800BDCA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BDCAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BDCB0: jr          $ra
    // 0x800BDCB4: nop

    return;
    // 0x800BDCB4: nop

;}
RECOMP_FUNC void bsmumstill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800290: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800294: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(328, 0X404) << 16);
    // 0x80800298: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080029C: jr          $ra
    // 0x808002A0: lw          $v0, 0x404($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(328, 0X404));
    return;
    // 0x808002A0: lw          $v0, 0x404($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(328, 0X404));
;}
RECOMP_FUNC void _mlspline_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089120: syscall     762
    recomp_syscall_handler(rdram, ctx, 0x80089120);
    return;
    // 0x80089124: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void glhittableDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D0: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x808002D4: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x808002D8: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x808002DC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x808002E0: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2742, 0X530) << 16);
    // 0x808002E4: addiu       $t9, $t9, 0x530
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2742, 0X530));
    // 0x808002E8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808002EC: andi        $t0, $a0, 0xFFFF
    ctx->r8 = ctx->r4 & 0XFFFF;
    // 0x808002F0: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x808002F4: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x808002F8: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x808002FC: lhu         $t3, 0x4($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4);
    // 0x80800300: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    // 0x80800304: sll         $t4, $t3, 20
    ctx->r12 = S32(ctx->r11 << 20);
    // 0x80800308: sll         $t7, $t6, 20
    ctx->r15 = S32(ctx->r14 << 20);
    // 0x8080030C: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80800310: srl         $t5, $t4, 30
    ctx->r13 = S32(U32(ctx->r12) >> 30);
    // 0x80800314: jr          $ra
    // 0x80800318: or          $v0, $t5, $t8
    ctx->r2 = ctx->r13 | ctx->r24;
    return;
    // 0x80800318: or          $v0, $t5, $t8
    ctx->r2 = ctx->r13 | ctx->r24;
;}
RECOMP_FUNC void func_808008CC_bafpctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808008D8: jal         0x808005FC
    // 0x808008DC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_808005FC_bafpctrl(rdram, ctx);
        goto after_0;
    // 0x808008DC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x808008E0: jal         0x800A4CA8
    // 0x808008E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800A4CA8(rdram, ctx);
        goto after_1;
    // 0x808008E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x808008E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008EC: jal         0x800893F8
    // 0x808008F0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    _ncba1p_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808008F0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x808008F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808008FC: jr          $ra
    // 0x80800900: nop

    return;
    // 0x80800900: nop

;}
RECOMP_FUNC void func_800C37E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C37E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C37E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C37E8: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C37EC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C37F0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800C37F4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C37F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C37FC: beq         $t6, $zero, L_800C3858
    if (ctx->r14 == 0) {
        // 0x800C3800: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_800C3858;
    }
    // 0x800C3800: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C3804: sb          $t6, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r14;
    // 0x800C3808: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x800C380C: jal         0x800C1414
    // 0x800C3810: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3810: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800C3814: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C3818: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C381C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800C3820: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C3824: add.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x800C3828: lhu         $t7, 0x7A($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X7A);
    // 0x800C382C: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C3830: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C3834: andi        $t8, $t7, 0xFC3F
    ctx->r24 = ctx->r15 & 0XFC3F;
    // 0x800C3838: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x800C383C: sh          $t9, 0x7A($v0)
    MEM_H(0X7A, ctx->r2) = ctx->r25;
    // 0x800C3840: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3844: swc1        $f12, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f12.u32l;
    // 0x800C3848: swc1        $f14, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f14.u32l;
    // 0x800C384C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800C3850: jal         0x800C31DC
    // 0x800C3854: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    func_800C31DC(rdram, ctx);
        goto after_1;
    // 0x800C3854: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    after_1:
L_800C3858:
    // 0x800C3858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C385C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3860: jr          $ra
    // 0x800C3864: nop

    return;
    // 0x800C3864: nop

;}
RECOMP_FUNC void boot___ull_rem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000283C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80002840: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80002844: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80002848: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8000284C: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x80002850: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x80002854: ddivu       $zero, $t6, $t7
    DDIVU(U64(ctx->r14), U64(ctx->r15), &lo, &hi);
    // 0x80002858: bne         $t7, $zero, L_80002864
    if (ctx->r15 != 0) {
        // 0x8000285C: nop
    
            goto L_80002864;
    }
    // 0x8000285C: nop

    // 0x80002860: break       7
    do_break(2147493984);
L_80002864:
    // 0x80002864: mfhi        $v0
    ctx->r2 = hi;
    // 0x80002868: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x8000286C: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x80002870: jr          $ra
    // 0x80002874: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x80002874: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void func_808002E4_chfaircoinbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808002E8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x808002EC: lw          $t9, 0x3E4($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(2132, 0X3E4));
    // 0x808002F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808002F4: jal         0x80800000
    // 0x808002F8: sh          $t9, 0x494($at)
    MEM_H((int16_t)RELOC_LO16(2132, 0X494), ctx->r1) = ctx->r25;
    func_80800000_chfaircoinbox(rdram, ctx);
        goto after_0;
    // 0x808002F8: sh          $t9, 0x494($at)
    MEM_H((int16_t)RELOC_LO16(2132, 0X494), ctx->r1) = ctx->r25;
    after_0:
    // 0x808002FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2132, 0X490) << 16);
    // 0x80800300: sh          $v0, 0x490($at)
    MEM_H((int16_t)RELOC_LO16(2132, 0X490), ctx->r1) = ctx->r2;
    // 0x80800304: jal         0x800DA298
    // 0x80800308: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800308: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_1:
    // 0x8080030C: bne         $v0, $zero, L_80800348
    if (ctx->r2 != 0) {
        // 0x80800310: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80800348;
    }
    // 0x80800310: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800314: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80800318: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2132, 0X490) << 16);
    // 0x8080031C: addiu       $a2, $a2, 0x490
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2132, 0X490));
    // 0x80800320: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80800324: jal         0x8008A1E8
    // 0x80800328: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800328: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x8080032C: beq         $v0, $zero, L_80800348
    if (ctx->r2 == 0) {
        // 0x80800330: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80800348;
    }
    // 0x80800330: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800334: addiu       $at, $zero, 0x10B5
    ctx->r1 = ADD32(0, 0X10B5);
    // 0x80800338: beq         $v0, $at, L_80800340
    if (ctx->r2 == ctx->r1) {
        // 0x8080033C: nop
    
            goto L_80800340;
    }
    // 0x8080033C: nop

L_80800340:
    // 0x80800340: jal         0x80090734
    // 0x80800344: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090734(rdram, ctx);
        goto after_3;
    // 0x80800344: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
L_80800348:
    // 0x80800348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080034C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800350: jr          $ra
    // 0x80800354: nop

    return;
    // 0x80800354: nop

;}
RECOMP_FUNC void chhotwaterpoolbits_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1268, 0XA08) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0xA08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1268, 0XA08));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0xA08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1268, 0XA08));
;}
RECOMP_FUNC void _bsbflap_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082920: syscall     20
    recomp_syscall_handler(rdram, ctx, 0x80082920);
    return;
    // 0x80082924: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bzero(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D6E0: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x8002D6E4: bne         $at, $zero, L_8002D75C
    if (ctx->r1 != 0) {
        // 0x8002D6E8: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_8002D75C;
    }
    // 0x8002D6E8: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x8002D6EC: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x8002D6F0: beq         $v1, $zero, L_8002D700
    if (ctx->r3 == 0) {
        // 0x8002D6F4: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_8002D700;
    }
    // 0x8002D6F4: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x8002D6F8: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x8002D6FC: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_8002D700:
    // 0x8002D700: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x8002D704: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x8002D708: beq         $a3, $zero, L_8002D73C
    if (ctx->r7 == 0) {
        // 0x8002D70C: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8002D73C;
    }
    // 0x8002D70C: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x8002D710: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8002D714:
    // 0x8002D714: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8002D718: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x8002D71C: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x8002D720: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x8002D724: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x8002D728: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x8002D72C: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x8002D730: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x8002D734: bne         $a0, $a3, L_8002D714
    if (ctx->r4 != ctx->r7) {
        // 0x8002D738: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_8002D714;
    }
    // 0x8002D738: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8002D73C:
    // 0x8002D73C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002D740: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x8002D744: beq         $a3, $zero, L_8002D75C
    if (ctx->r7 == 0) {
        // 0x8002D748: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8002D75C;
    }
    // 0x8002D748: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x8002D74C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8002D750:
    // 0x8002D750: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8002D754: bne         $a0, $a3, L_8002D750
    if (ctx->r4 != ctx->r7) {
        // 0x8002D758: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_8002D750;
    }
    // 0x8002D758: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8002D75C:
    // 0x8002D75C: blez        $a1, L_8002D774
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8002D760: nop
    
            goto L_8002D774;
    }
    // 0x8002D760: nop

    // 0x8002D764: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_8002D768:
    // 0x8002D768: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002D76C: bne         $a0, $a1, L_8002D768
    if (ctx->r4 != ctx->r5) {
        // 0x8002D770: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_8002D768;
    }
    // 0x8002D770: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_8002D774:
    // 0x8002D774: jr          $ra
    // 0x8002D778: nop

    return;
    // 0x8002D778: nop

;}
RECOMP_FUNC void cheggclockwork_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800494: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800498: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080049C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004A0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808004A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808004A8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808004AC: jal         0x8008A488
    // 0x808004B0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    _sueggmove_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x808004B0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x808004B4: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    // 0x808004B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004BC: jal         0x8008A3D0
    // 0x808004C0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    _suegg_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808004C0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x808004C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808004C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004CC: jal         0x80100094
    // 0x808004D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808004D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808004DC: jal         0x808007DC
    // 0x808004E0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_808007DC_cheggclockwork(rdram, ctx);
        goto after_3;
    // 0x808004E0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x808004E4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x808004E8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x808004EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2104, 0X8B4) << 16);
    // 0x808004F0: lbu         $t0, 0x39($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X39);
    // 0x808004F4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x808004F8: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x808004FC: andi        $t1, $t0, 0xFFF7
    ctx->r9 = ctx->r8 & 0XFFF7;
    // 0x80800500: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800504: sb          $t2, 0x39($v1)
    MEM_B(0X39, ctx->r3) = ctx->r10;
    // 0x80800508: lwc1        $f4, 0x8B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2104, 0X8B4));
    // 0x8080050C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800510: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80800514: jal         0x8008A380
    // 0x80800518: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    _suegg_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800518: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800520: jal         0x8008A460
    // 0x80800524: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sueggmove_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800524: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800528: lui         $a1, 0xC509
    ctx->r5 = S32(0XC509 << 16);
    // 0x8080052C: lui         $a2, 0xC7C3
    ctx->r6 = S32(0XC7C3 << 16);
    // 0x80800530: ori         $a2, $a2, 0x5000
    ctx->r6 = ctx->r6 | 0X5000;
    // 0x80800534: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800538: jal         0x8008A468
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmove_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800544: jal         0x8008A470
    // 0x80800548: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _sueggmove_entrypoint_7(rdram, ctx);
        goto after_7;
    // 0x80800548: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x8080054C: lbu         $t3, 0x72($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X72);
    // 0x80800550: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800554: andi        $t4, $t3, 0xFF03
    ctx->r12 = ctx->r11 & 0XFF03;
    // 0x80800558: ori         $t5, $t4, 0x8
    ctx->r13 = ctx->r12 | 0X8;
    // 0x8080055C: sb          $t5, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r13;
    // 0x80800560: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800564: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800568: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080056C: jr          $ra
    // 0x80800570: nop

    return;
    // 0x80800570: nop

;}
RECOMP_FUNC void _bafly_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084BF8: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084BF8);
    return;
    // 0x80084BFC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80017244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017244: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80017248: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001724C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80017250: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80017254: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80017258: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001725C: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    // 0x80017260: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_80017264:
    // 0x80017264: jal         0x80016ED0
    // 0x80017268: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80016ED0(rdram, ctx);
        goto after_0;
    // 0x80017268: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x8001726C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80017270: bnel        $s0, $s2, L_80017264
    if (ctx->r16 != ctx->r18) {
        // 0x80017274: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80017264;
    }
    goto skip_0;
    // 0x80017274: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    skip_0:
    // 0x80017278: jal         0x800305B0
    // 0x8001727C: nop

    osGetTime_recomp(rdram, ctx);
        goto after_1;
    // 0x8001727C: nop

    after_1:
    // 0x80017280: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80017284: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80017288: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001728C:
    // 0x8001728C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80017290:
    // 0x80017290: jal         0x80017210
    // 0x80017294: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_80017210(rdram, ctx);
        goto after_2;
    // 0x80017294: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_2:
    // 0x80017298: beq         $v0, $zero, L_800172A4
    if (ctx->r2 == 0) {
        // 0x8001729C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800172A4;
    }
    // 0x8001729C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800172A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800172A4:
    // 0x800172A4: bne         $s0, $s2, L_80017290
    if (ctx->r16 != ctx->r18) {
        // 0x800172A8: nop
    
            goto L_80017290;
    }
    // 0x800172A8: nop

    // 0x800172AC: jal         0x800305B0
    // 0x800172B0: nop

    osGetTime_recomp(rdram, ctx);
        goto after_3;
    // 0x800172B0: nop

    after_3:
    // 0x800172B4: bnel        $s1, $zero, L_8001728C
    if (ctx->r17 != 0) {
        // 0x800172B8: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8001728C;
    }
    goto skip_1;
    // 0x800172B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    skip_1:
    // 0x800172BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800172C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800172C4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800172C8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800172CC: jr          $ra
    // 0x800172D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800172D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800F5BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5BC4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5BC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5BCC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5BD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5BD4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5BD8: jal         0x80092B8C
    // 0x800F5BDC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_80092B8C(rdram, ctx);
        goto after_0;
    // 0x800F5BDC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5BE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5BE8: jr          $ra
    // 0x800F5BEC: nop

    return;
    // 0x800F5BEC: nop

;}
RECOMP_FUNC void func_80800024_chboggykidshome(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800030: jal         0x800DA298
    // 0x80800034: addiu       $a0, $zero, 0x1CD
    ctx->r4 = ADD32(0, 0X1CD);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800034: addiu       $a0, $zero, 0x1CD
    ctx->r4 = ADD32(0, 0X1CD);
    after_0:
    // 0x80800038: bnel        $v0, $zero, L_8080005C
    if (ctx->r2 != 0) {
        // 0x8080003C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080005C;
    }
    goto skip_0;
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800040: jal         0x80088848
    // 0x80800044: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800044: nop

    after_1:
    // 0x80800048: bnel        $v0, $zero, L_8080005C
    if (ctx->r2 != 0) {
        // 0x8080004C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080005C;
    }
    goto skip_1;
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800050: jal         0x800FFAB0
    // 0x80800054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080005C:
    // 0x8080005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void func_80098628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098628: lw          $t6, 0xE0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE0);
    // 0x8009862C: jr          $ra
    // 0x80098630: lwc1        $f0, 0x18($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X18);
    return;
    // 0x80098630: lwc1        $f0, 0x18($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X18);
;}
RECOMP_FUNC void bsmum_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E64: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800E68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E70: jal         0x8009EF1C
    // 0x80800E74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x80800E74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800E78: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800E7C: jal         0x8009EF10
    // 0x80800E80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x80800E80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E88: jal         0x8008DE24
    // 0x80800E8C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_8008DE24(rdram, ctx);
        goto after_2;
    // 0x80800E8C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800E90: beq         $v0, $zero, L_80800EF4
    if (ctx->r2 == 0) {
        // 0x80800E94: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_80800EF4;
    }
    // 0x80800E94: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E9C: jal         0x8008E078
    // 0x80800EA0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    player_isStable(rdram, ctx);
        goto after_3;
    // 0x80800EA0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_3:
    // 0x80800EA4: beq         $v0, $zero, L_80800EF4
    if (ctx->r2 == 0) {
        // 0x80800EA8: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_80800EF4;
    }
    // 0x80800EA8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800EAC: bne         $v1, $zero, L_80800EC4
    if (ctx->r3 != 0) {
        // 0x80800EB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EC4;
    }
    // 0x80800EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EB4: jal         0x8009B9B0
    // 0x80800EB8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800EB8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800EBC: b           L_80800F94
    // 0x80800EC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800F94;
    // 0x80800EC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EC4:
    // 0x80800EC4: jal         0x8009EF04
    // 0x80800EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_5;
    // 0x80800EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800ECC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800ED0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800ED4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800ED8: jal         0x800F1214
    // 0x80800EDC: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    func_800F1214(rdram, ctx);
        goto after_6;
    // 0x80800EDC: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    after_6:
    // 0x80800EE0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800EE4: jal         0x8009B9B0
    // 0x80800EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_7;
    // 0x80800EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800EEC: b           L_80800F94
    // 0x80800EF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800F94;
    // 0x80800EF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EF4:
    // 0x80800EF4: beq         $v1, $zero, L_80800F18
    if (ctx->r3 == 0) {
        // 0x80800EF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F18;
    }
    // 0x80800EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800F00: beq         $v1, $at, L_80800F28
    if (ctx->r3 == ctx->r1) {
        // 0x80800F04: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800F28;
    }
    // 0x80800F04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800F08: beq         $v1, $at, L_80800F60
    if (ctx->r3 == ctx->r1) {
        // 0x80800F0C: nop
    
            goto L_80800F60;
    }
    // 0x80800F0C: nop

    // 0x80800F10: b           L_80800F94
    // 0x80800F14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800F94;
    // 0x80800F14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F18:
    // 0x80800F18: jal         0x8009B9B0
    // 0x80800F1C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_8;
    // 0x80800F1C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x80800F20: b           L_80800F94
    // 0x80800F24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800F94;
    // 0x80800F24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F28:
    // 0x80800F28: jal         0x800838B0
    // 0x80800F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsmummove_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800F30: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80800F34: jal         0x800838A8
    // 0x80800F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsmummove_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80800F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800F3C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800F40: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800F44: jal         0x800F1214
    // 0x80800F48: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    func_800F1214(rdram, ctx);
        goto after_11;
    // 0x80800F48: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    after_11:
    // 0x80800F4C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800F50: jal         0x8009B9B0
    // 0x80800F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_12;
    // 0x80800F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800F58: b           L_80800F94
    // 0x80800F5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800F94;
    // 0x80800F5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F60:
    // 0x80800F60: jal         0x800838A8
    // 0x80800F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsmummove_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x80800F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800F68: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80800F6C: jal         0x800838A0
    // 0x80800F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsmummove_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x80800F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800F74: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800F78: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800F7C: jal         0x800F1214
    // 0x80800F80: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    func_800F1214(rdram, ctx);
        goto after_15;
    // 0x80800F80: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    after_15:
    // 0x80800F84: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800F88: jal         0x8009B9B0
    // 0x80800F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_16;
    // 0x80800F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F94:
    // 0x80800F94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F98: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800F9C: jr          $ra
    // 0x80800FA0: nop

    return;
    // 0x80800FA0: nop

;}
RECOMP_FUNC void func_800E0464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0464: jr          $ra
    // 0x800E0468: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
    return;
    // 0x800E0468: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
;}
RECOMP_FUNC void bainvisible_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080080C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800810: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x80800814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800818: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080081C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800820: beq         $t7, $zero, L_8080083C
    if (ctx->r15 == 0) {
        // 0x80800824: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_8080083C;
    }
    // 0x80800824: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800828: lw          $a1, 0xA8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XA8);
    // 0x8080082C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800830: jal         0x808007CC
    // 0x80800834: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    func_808007CC_bainvisible(rdram, ctx);
        goto after_0;
    // 0x80800834: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_0:
    // 0x80800838: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8080083C:
    // 0x8080083C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80800840: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800844: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x80800848: beql        $t9, $zero, L_80800864
    if (ctx->r25 == 0) {
        // 0x8080084C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800864;
    }
    goto skip_0;
    // 0x8080084C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800850: lw          $a1, 0xA8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XA8);
    // 0x80800854: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800858: jal         0x808007CC
    // 0x8080085C: addiu       $a1, $a1, 0x4C
    ctx->r5 = ADD32(ctx->r5, 0X4C);
    func_808007CC_bainvisible(rdram, ctx);
        goto after_1;
    // 0x8080085C: addiu       $a1, $a1, 0x4C
    ctx->r5 = ADD32(ctx->r5, 0X4C);
    after_1:
    // 0x80800860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800864:
    // 0x80800864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800868: jr          $ra
    // 0x8080086C: nop

    return;
    // 0x8080086C: nop

;}
RECOMP_FUNC void func_800EB210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EB214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EB218: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800EB21C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800EB220: jal         0x800EB15C
    // 0x800EB224: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EB15C(rdram, ctx);
        goto after_0;
    // 0x800EB224: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800EB228: beq         $v0, $zero, L_800EB2CC
    if (ctx->r2 == 0) {
        // 0x800EB22C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800EB2CC;
    }
    // 0x800EB22C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800EB230: jal         0x800EC3C4
    // 0x800EB234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EC3C4(rdram, ctx);
        goto after_1;
    // 0x800EB234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x800EB238: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800EB23C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800EB240: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800EB244: beq         $a1, $zero, L_800EB268
    if (ctx->r5 == 0) {
        // 0x800EB248: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800EB268;
    }
    // 0x800EB248: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800EB24C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800EB250: beq         $a1, $at, L_800EB28C
    if (ctx->r5 == ctx->r1) {
        // 0x800EB254: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800EB28C;
    }
    // 0x800EB254: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800EB258: beql        $a1, $at, L_800EB2B4
    if (ctx->r5 == ctx->r1) {
        // 0x800EB25C: lw          $t8, 0x8($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X8);
            goto L_800EB2B4;
    }
    goto skip_0;
    // 0x800EB25C: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x800EB260: b           L_800EB2D0
    // 0x800EB264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800EB2D0;
    // 0x800EB264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EB268:
    // 0x800EB268: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800EB26C: beql        $t6, $zero, L_800EB2D0
    if (ctx->r14 == 0) {
        // 0x800EB270: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EB2D0;
    }
    goto skip_1;
    // 0x800EB270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800EB274: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800EB278: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800EB27C: jalr        $t9
    // 0x800EB280: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800EB280: nop

    after_2:
    // 0x800EB284: b           L_800EB2D0
    // 0x800EB288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800EB2D0;
    // 0x800EB288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EB28C:
    // 0x800EB28C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800EB290: beql        $t7, $zero, L_800EB2D0
    if (ctx->r15 == 0) {
        // 0x800EB294: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EB2D0;
    }
    goto skip_2;
    // 0x800EB294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800EB298: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x800EB29C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800EB2A0: jalr        $t9
    // 0x800EB2A4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800EB2A4: nop

    after_3:
    // 0x800EB2A8: b           L_800EB2D0
    // 0x800EB2AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800EB2D0;
    // 0x800EB2AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EB2B0: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
L_800EB2B4:
    // 0x800EB2B4: beql        $t8, $zero, L_800EB2D0
    if (ctx->r24 == 0) {
        // 0x800EB2B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EB2D0;
    }
    goto skip_3;
    // 0x800EB2B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x800EB2BC: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x800EB2C0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800EB2C4: jalr        $t9
    // 0x800EB2C8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800EB2C8: nop

    after_4:
L_800EB2CC:
    // 0x800EB2CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EB2D0:
    // 0x800EB2D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EB2D4: jr          $ra
    // 0x800EB2D8: nop

    return;
    // 0x800EB2D8: nop

;}
RECOMP_FUNC void bskazmove_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800790: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800794: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800798: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080079C: jal         0x8008CABC
    // 0x808007A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808007A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808007A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(260, 0XC54) << 16);
    // 0x808007A8: lwc1        $f4, 0xC54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(260, 0XC54));
    // 0x808007AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(260, 0XC58) << 16);
    // 0x808007B0: lwc1        $f6, 0xC58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(260, 0XC58));
    // 0x808007B4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808007B8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808007BC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x808007C8: jal         0x80084FE0
    // 0x808007CC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    _bashoes_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808007CC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x808007D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808007D4: beq         $v0, $at, L_808007F4
    if (ctx->r2 == ctx->r1) {
        // 0x808007D8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808007F4;
    }
    // 0x808007D8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808007DC: beq         $v0, $at, L_80800804
    if (ctx->r2 == ctx->r1) {
        // 0x808007E0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80800804;
    }
    // 0x808007E0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808007E4: beq         $v0, $at, L_8080080C
    if (ctx->r2 == ctx->r1) {
        // 0x808007E8: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_8080080C;
    }
    // 0x808007E8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808007EC: b           L_80800868
    // 0x808007F0: lui         $a1, 0x3E58
    ctx->r5 = S32(0X3E58 << 16);
        goto L_80800868;
    // 0x808007F0: lui         $a1, 0x3E58
    ctx->r5 = S32(0X3E58 << 16);
L_808007F4:
    // 0x808007F4: jal         0x80085078
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808007FC: b           L_80800898
    // 0x80800800: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
        goto L_80800898;
    // 0x80800800: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
L_80800804:
    // 0x80800804: b           L_80800894
    // 0x80800808: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
        goto L_80800894;
    // 0x80800808: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_8080080C:
    // 0x8080080C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(260, 0XC5C) << 16);
    // 0x80800810: lwc1        $f0, 0xC5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(260, 0XC5C));
    // 0x80800814: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(260, 0XC60) << 16);
    // 0x80800818: lwc1        $f8, 0xC60($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(260, 0XC60));
    // 0x8080081C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800820: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800824: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800828: jal         0x8008B348
    // 0x8080082C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x8080082C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80800830: beql        $v0, $zero, L_80800844
    if (ctx->r2 == 0) {
        // 0x80800834: lui         $a1, 0x3DCC
        ctx->r5 = S32(0X3DCC << 16);
            goto L_80800844;
    }
    goto skip_0;
    // 0x80800834: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    skip_0:
    // 0x80800838: jal         0x80085070
    // 0x8080083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x8080083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800840: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
L_80800844:
    // 0x80800844: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800848: jal         0x8008B348
    // 0x8080084C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x8080084C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80800850: beql        $v0, $zero, L_80800898
    if (ctx->r2 == 0) {
        // 0x80800854: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_80800898;
    }
    goto skip_1;
    // 0x80800854: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x80800858: jal         0x80085068
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_18(rdram, ctx);
        goto after_6;
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800860: b           L_80800898
    // 0x80800864: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
        goto L_80800898;
    // 0x80800864: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
L_80800868:
    // 0x80800868: jal         0x8008B348
    // 0x8080086C: ori         $a1, $a1, 0x9375
    ctx->r5 = ctx->r5 | 0X9375;
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x8080086C: ori         $a1, $a1, 0x9375
    ctx->r5 = ctx->r5 | 0X9375;
    after_7:
    // 0x80800870: bne         $v0, $zero, L_8080088C
    if (ctx->r2 != 0) {
        // 0x80800874: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_8080088C;
    }
    // 0x80800874: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800878: lui         $a1, 0x3F36
    ctx->r5 = S32(0X3F36 << 16);
    // 0x8080087C: jal         0x8008B348
    // 0x80800880: ori         $a1, $a1, 0x24DD
    ctx->r5 = ctx->r5 | 0X24DD;
    anctrl_isAt(rdram, ctx);
        goto after_8;
    // 0x80800880: ori         $a1, $a1, 0x24DD
    ctx->r5 = ctx->r5 | 0X24DD;
    after_8:
    // 0x80800884: beql        $v0, $zero, L_80800898
    if (ctx->r2 == 0) {
        // 0x80800888: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_80800898;
    }
    goto skip_2;
    // 0x80800888: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    skip_2:
L_8080088C:
    // 0x8080088C: jal         0x800849D0
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80800894:
    // 0x80800894: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
L_80800898:
    // 0x80800898: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A0: beq         $t7, $zero, L_808008CC
    if (ctx->r15 == 0) {
        // 0x808008A4: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_808008CC;
    }
    // 0x808008A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008AC: jal         0x800A2CE8
    // 0x808008B0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800A2CE8(rdram, ctx);
        goto after_10;
    // 0x808008B0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x808008B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808008BC: jal         0x800A2CE8
    // 0x808008C0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_11;
    // 0x808008C0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_11:
    // 0x808008C4: b           L_808008E8
    // 0x808008C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808008E8;
    // 0x808008C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008CC:
    // 0x808008CC: jal         0x800A2D2C
    // 0x808008D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2D2C(rdram, ctx);
        goto after_12;
    // 0x808008D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_12:
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808008DC: jal         0x800A2D2C
    // 0x808008E0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2D2C(rdram, ctx);
        goto after_13;
    // 0x808008E0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_13:
    // 0x808008E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008E8:
    // 0x808008E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808008F0: jr          $ra
    // 0x808008F4: nop

    return;
    // 0x808008F4: nop

;}
RECOMP_FUNC void func_80800018_chklungodoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080001C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800020: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800024: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800028: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8080002C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800030: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1252, 0X490) << 16);
    // 0x80800034: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800038: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080003C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80800040: addiu       $s1, $s1, 0x490
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1252, 0X490));
    // 0x80800044: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800048: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_8080004C:
    // 0x8080004C: jal         0x800EA05C
    // 0x80800050: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800050: nop

    after_0:
    // 0x80800054: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x80800058: bnel        $v0, $t6, L_80800070
    if (ctx->r2 != ctx->r14) {
        // 0x8080005C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800070;
    }
    goto skip_0;
    // 0x8080005C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80800060: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
    // 0x80800064: b           L_80800078
    // 0x80800068: sw          $s0, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->r16;
        goto L_80800078;
    // 0x80800068: sw          $s0, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->r16;
    // 0x8080006C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800070:
    // 0x80800070: bne         $s0, $s2, L_8080004C
    if (ctx->r16 != ctx->r18) {
        // 0x80800074: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_8080004C;
    }
    // 0x80800074: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_80800078:
    // 0x80800078: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080007C: jal         0x80102FDC
    // 0x80800080: lw          $a1, 0x4($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X4);
    func_80102FDC(rdram, ctx);
        goto after_1;
    // 0x80800080: lw          $a1, 0x4($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X4);
    after_1:
    // 0x80800084: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800088: jal         0x8010A800
    // 0x8080008C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_2;
    // 0x8080008C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800090: lw          $t7, 0x6C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X6C);
    // 0x80800094: addiu       $at, $zero, 0x420
    ctx->r1 = ADD32(0, 0X420);
    // 0x80800098: sll         $t8, $t7, 11
    ctx->r24 = S32(ctx->r15 << 11);
    // 0x8080009C: srl         $t9, $t8, 20
    ctx->r25 = S32(U32(ctx->r24) >> 20);
    // 0x808000A0: bnel        $t9, $at, L_80800148
    if (ctx->r25 != ctx->r1) {
        // 0x808000A4: lbu         $t4, 0xE($s4)
        ctx->r12 = MEM_BU(ctx->r20, 0XE);
            goto L_80800148;
    }
    goto skip_1;
    // 0x808000A4: lbu         $t4, 0xE($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0XE);
    skip_1:
    // 0x808000A8: lbu         $t0, 0xE($s4)
    ctx->r8 = MEM_BU(ctx->r20, 0XE);
    // 0x808000AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808000B0: beql        $t0, $zero, L_808000DC
    if (ctx->r8 == 0) {
        // 0x808000B4: lh          $t1, 0x2($s4)
        ctx->r9 = MEM_H(ctx->r20, 0X2);
            goto L_808000DC;
    }
    goto skip_2;
    // 0x808000B4: lh          $t1, 0x2($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X2);
    skip_2:
    // 0x808000B8: jal         0x80103110
    // 0x808000BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_3;
    // 0x808000BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808000C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808000C4: ori         $a1, $zero, 0xA82A
    ctx->r5 = 0 | 0XA82A;
    // 0x808000C8: jal         0x800868A0
    // 0x808000CC: lhu         $a2, 0xC($s4)
    ctx->r6 = MEM_HU(ctx->r20, 0XC);
    _chdoormake_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808000CC: lhu         $a2, 0xC($s4)
    ctx->r6 = MEM_HU(ctx->r20, 0XC);
    after_4:
    // 0x808000D0: b           L_80800110
    // 0x808000D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80800110;
    // 0x808000D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808000D8: lh          $t1, 0x2($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X2);
L_808000DC:
    // 0x808000DC: addiu       $t2, $zero, 0x122
    ctx->r10 = ADD32(0, 0X122);
    // 0x808000E0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808000E4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x808000E8: lhu         $t3, 0xC($s4)
    ctx->r11 = MEM_HU(ctx->r20, 0XC);
    // 0x808000EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808000F0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808000F4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808000F8: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x808000FC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80800100: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800104: jal         0x80086898
    // 0x80800108: nop

    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80800108: nop

    after_5:
    // 0x8080010C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800110:
    // 0x80800110: beq         $v0, $zero, L_808001D8
    if (ctx->r2 == 0) {
        // 0x80800114: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_808001D8;
    }
    // 0x80800114: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800118: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x8080011C: jal         0x800868A8
    // 0x80800120: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x80800120: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_6:
    // 0x80800124: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800128: jal         0x800868B0
    // 0x8080012C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x8080012C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_7:
    // 0x80800130: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800134: jal         0x800868C0
    // 0x80800138: lbu         $a1, 0xF($s4)
    ctx->r5 = MEM_BU(ctx->r20, 0XF);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_8;
    // 0x80800138: lbu         $a1, 0xF($s4)
    ctx->r5 = MEM_BU(ctx->r20, 0XF);
    after_8:
    // 0x8080013C: b           L_808001DC
    // 0x80800140: lbu         $t8, 0xE($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0XE);
        goto L_808001DC;
    // 0x80800140: lbu         $t8, 0xE($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0XE);
    // 0x80800144: lbu         $t4, 0xE($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0XE);
L_80800148:
    // 0x80800148: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080014C: beql        $t4, $zero, L_80800178
    if (ctx->r12 == 0) {
        // 0x80800150: lh          $t5, 0x2($s4)
        ctx->r13 = MEM_H(ctx->r20, 0X2);
            goto L_80800178;
    }
    goto skip_3;
    // 0x80800150: lh          $t5, 0x2($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X2);
    skip_3:
    // 0x80800154: jal         0x80103110
    // 0x80800158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_9;
    // 0x80800158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x8080015C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800160: ori         $a1, $zero, 0xA82A
    ctx->r5 = 0 | 0XA82A;
    // 0x80800164: jal         0x800868A0
    // 0x80800168: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    _chdoormake_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x80800168: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_10:
    // 0x8080016C: b           L_808001AC
    // 0x80800170: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_808001AC;
    // 0x80800170: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800174: lh          $t5, 0x2($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X2);
L_80800178:
    // 0x80800178: addiu       $t6, $zero, 0x122
    ctx->r14 = ADD32(0, 0X122);
    // 0x8080017C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800180: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80800184: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800188: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080018C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800190: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800194: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800198: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x8080019C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x808001A0: jal         0x80086898
    // 0x808001A4: nop

    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x808001A4: nop

    after_11:
    // 0x808001A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808001AC:
    // 0x808001AC: beq         $v0, $zero, L_808001D8
    if (ctx->r2 == 0) {
        // 0x808001B0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_808001D8;
    }
    // 0x808001B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808001B4: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x808001B8: jal         0x800868A8
    // 0x808001BC: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_12;
    // 0x808001BC: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_12:
    // 0x808001C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808001C4: jal         0x800868B0
    // 0x808001C8: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_13;
    // 0x808001C8: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_13:
    // 0x808001CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808001D0: jal         0x800868C0
    // 0x808001D4: lbu         $a1, 0xF($s4)
    ctx->r5 = MEM_BU(ctx->r20, 0XF);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_14;
    // 0x808001D4: lbu         $a1, 0xF($s4)
    ctx->r5 = MEM_BU(ctx->r20, 0XF);
    after_14:
L_808001D8:
    // 0x808001D8: lbu         $t8, 0xE($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0XE);
L_808001DC:
    // 0x808001DC: beql        $t8, $zero, L_80800218
    if (ctx->r24 == 0) {
        // 0x808001E0: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80800218;
    }
    goto skip_4;
    // 0x808001E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_4:
    // 0x808001E4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x808001E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001F0: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x808001F4: andi        $t0, $t9, 0x3F
    ctx->r8 = ctx->r25 & 0X3F;
    // 0x808001F8: ori         $t1, $t0, 0xCC40
    ctx->r9 = ctx->r8 | 0XCC40;
    // 0x808001FC: jal         0x80103110
    // 0x80800200: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    func_80103110(rdram, ctx);
        goto after_15;
    // 0x80800200: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    after_15:
    // 0x80800204: xori        $a1, $s0, 0x1
    ctx->r5 = ctx->r16 ^ 0X1;
    // 0x80800208: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x8080020C: jal         0x8010A5B0
    // 0x80800210: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8010A5B0(rdram, ctx);
        goto after_16;
    // 0x80800210: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_16:
    // 0x80800214: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800218:
    // 0x80800218: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080021C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800220: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800224: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800228: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8080022C: jr          $ra
    // 0x80800230: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800230: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800FFDBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFDBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FFDC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FFDC4: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x800FFDC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FFDCC: jal         0x801067C4
    // 0x800FFDD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x800FFDD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800FFDD4: beq         $v0, $zero, L_800FFDF4
    if (ctx->r2 == 0) {
        // 0x800FFDD8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800FFDF4;
    }
    // 0x800FFDD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800FFDDC:
    // 0x800FFDDC: jal         0x8010381C
    // 0x800FFDE0: nop

    func_8010381C(rdram, ctx);
        goto after_1;
    // 0x800FFDE0: nop

    after_1:
    // 0x800FFDE4: jal         0x8010682C
    // 0x800FFDE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010682C(rdram, ctx);
        goto after_2;
    // 0x800FFDE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FFDEC: bne         $v0, $zero, L_800FFDDC
    if (ctx->r2 != 0) {
        // 0x800FFDF0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800FFDDC;
    }
    // 0x800FFDF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800FFDF4:
    // 0x800FFDF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FFDF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FFDFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800FFE00: jr          $ra
    // 0x800FFE04: nop

    return;
    // 0x800FFE04: nop

;}
RECOMP_FUNC void func_80801394_subaddiedialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801394: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801398: andi        $t6, $a1, 0x40
    ctx->r14 = ctx->r5 & 0X40;
    // 0x8080139C: beq         $t6, $zero, L_808013B8
    if (ctx->r14 == 0) {
        // 0x808013A0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808013B8;
    }
    // 0x808013A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013A4: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x808013A8: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x808013AC: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x808013B0: b           L_808013D4
    // 0x808013B4: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
        goto L_808013D4;
    // 0x808013B4: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
L_808013B8:
    // 0x808013B8: sltu        $v0, $zero, $a2
    ctx->r2 = 0 < ctx->r6 ? 1 : 0;
    // 0x808013BC: beql        $v0, $zero, L_808013D8
    if (ctx->r2 == 0) {
        // 0x808013C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808013D8;
    }
    goto skip_0;
    // 0x808013C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808013C4: jal         0x800DA298
    // 0x808013C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808013C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x808013CC: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808013D0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_808013D4:
    // 0x808013D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808013D8:
    // 0x808013D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808013DC: jr          $ra
    // 0x808013E0: nop

    return;
    // 0x808013E0: nop

;}
RECOMP_FUNC void scinfobar_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800598: jr          $ra
    // 0x8080059C: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
    return;
    // 0x8080059C: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
;}
RECOMP_FUNC void func_80108658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108658: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010865C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108660: lbu         $t6, 0x96($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X96);
    // 0x80108664: lbu         $t2, 0x74($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X74);
    // 0x80108668: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x8010866C: sb          $t7, 0x96($a0)
    MEM_B(0X96, ctx->r4) = ctx->r15;
    // 0x80108670: lhu         $v0, 0x96($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X96);
    // 0x80108674: lbu         $t6, 0x77($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X77);
    // 0x80108678: andi        $t3, $t2, 0xFFFD
    ctx->r11 = ctx->r10 & 0XFFFD;
    // 0x8010867C: srl         $t9, $v0, 15
    ctx->r25 = S32(U32(ctx->r2) >> 15);
    // 0x80108680: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80108684: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x80108688: lbu         $t0, 0x7B($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X7B);
    // 0x8010868C: sll         $v1, $t9, 6
    ctx->r3 = S32(ctx->r25 << 6);
    // 0x80108690: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80108694: andi        $t5, $v1, 0x40
    ctx->r13 = ctx->r3 & 0X40;
    // 0x80108698: andi        $t9, $v1, 0xC0
    ctx->r25 = ctx->r3 & 0XC0;
    // 0x8010869C: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x801086A0: andi        $t2, $t0, 0xFF3F
    ctx->r10 = ctx->r8 & 0XFF3F;
    // 0x801086A4: or          $t1, $t9, $t2
    ctx->r9 = ctx->r25 | ctx->r10;
    // 0x801086A8: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x801086AC: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x801086B0: sb          $t8, 0x77($a0)
    MEM_B(0X77, ctx->r4) = ctx->r24;
    // 0x801086B4: sb          $t1, 0x7B($a0)
    MEM_B(0X7B, ctx->r4) = ctx->r9;
    // 0x801086B8: bgez        $t3, L_80108700
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801086BC: sb          $t4, 0x74($a0)
        MEM_B(0X74, ctx->r4) = ctx->r12;
            goto L_80108700;
    }
    // 0x801086BC: sb          $t4, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r12;
    // 0x801086C0: lw          $t2, 0x70($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X70);
    // 0x801086C4: srl         $t4, $t1, 6
    ctx->r12 = S32(U32(ctx->r9) >> 6);
    // 0x801086C8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x801086CC: sll         $t8, $t5, 6
    ctx->r24 = S32(ctx->r13 << 6);
    // 0x801086D0: andi        $t0, $t1, 0xFF3F
    ctx->r8 = ctx->r9 & 0XFF3F;
    // 0x801086D4: or          $t9, $t8, $t0
    ctx->r25 = ctx->r24 | ctx->r8;
    // 0x801086D8: sll         $t3, $t2, 10
    ctx->r11 = S32(ctx->r10 << 10);
    // 0x801086DC: bltz        $t3, L_80108700
    if (SIGNED(ctx->r11) < 0) {
        // 0x801086E0: sb          $t9, 0x7B($a0)
        MEM_B(0X7B, ctx->r4) = ctx->r25;
            goto L_80108700;
    }
    // 0x801086E0: sb          $t9, 0x7B($a0)
    MEM_B(0X7B, ctx->r4) = ctx->r25;
    // 0x801086E4: lbu         $t4, 0x70($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X70);
    // 0x801086E8: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x801086EC: bnel        $t6, $zero, L_80108704
    if (ctx->r14 != 0) {
        // 0x801086F0: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_80108704;
    }
    goto skip_0;
    // 0x801086F0: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    skip_0:
    // 0x801086F4: lbu         $t7, 0x71($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X71);
    // 0x801086F8: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x801086FC: sb          $t8, 0x71($a0)
    MEM_B(0X71, ctx->r4) = ctx->r24;
L_80108700:
    // 0x80108700: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
L_80108704:
    // 0x80108704: bgezl       $t0, L_80108754
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80108708: andi        $t6, $a1, 0x2000
        ctx->r14 = ctx->r5 & 0X2000;
            goto L_80108754;
    }
    goto skip_1;
    // 0x80108708: andi        $t6, $a1, 0x2000
    ctx->r14 = ctx->r5 & 0X2000;
    skip_1:
    // 0x8010870C: lbu         $v0, 0x7B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7B);
    // 0x80108710: lw          $t7, 0x70($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X70);
    // 0x80108714: srl         $t9, $v0, 6
    ctx->r25 = S32(U32(ctx->r2) >> 6);
    // 0x80108718: addiu       $t1, $t9, 0x2
    ctx->r9 = ADD32(ctx->r25, 0X2);
    // 0x8010871C: sll         $t4, $t1, 6
    ctx->r12 = S32(ctx->r9 << 6);
    // 0x80108720: andi        $t6, $v0, 0xFF3F
    ctx->r14 = ctx->r2 & 0XFF3F;
    // 0x80108724: or          $t5, $t4, $t6
    ctx->r13 = ctx->r12 | ctx->r14;
    // 0x80108728: sll         $t0, $t7, 10
    ctx->r8 = S32(ctx->r15 << 10);
    // 0x8010872C: bltz        $t0, L_80108750
    if (SIGNED(ctx->r8) < 0) {
        // 0x80108730: sb          $t5, 0x7B($a0)
        MEM_B(0X7B, ctx->r4) = ctx->r13;
            goto L_80108750;
    }
    // 0x80108730: sb          $t5, 0x7B($a0)
    MEM_B(0X7B, ctx->r4) = ctx->r13;
    // 0x80108734: lbu         $t9, 0x70($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X70);
    // 0x80108738: andi        $t2, $t9, 0x1
    ctx->r10 = ctx->r25 & 0X1;
    // 0x8010873C: bnel        $t2, $zero, L_80108754
    if (ctx->r10 != 0) {
        // 0x80108740: andi        $t6, $a1, 0x2000
        ctx->r14 = ctx->r5 & 0X2000;
            goto L_80108754;
    }
    goto skip_2;
    // 0x80108740: andi        $t6, $a1, 0x2000
    ctx->r14 = ctx->r5 & 0X2000;
    skip_2:
    // 0x80108744: lbu         $t3, 0x71($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X71);
    // 0x80108748: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x8010874C: sb          $t4, 0x71($a0)
    MEM_B(0X71, ctx->r4) = ctx->r12;
L_80108750:
    // 0x80108750: andi        $t6, $a1, 0x2000
    ctx->r14 = ctx->r5 & 0X2000;
L_80108754:
    // 0x80108754: beq         $t6, $zero, L_80108780
    if (ctx->r14 == 0) {
        // 0x80108758: lui         $at, 0x3000
        ctx->r1 = S32(0X3000 << 16);
            goto L_80108780;
    }
    // 0x80108758: lui         $at, 0x3000
    ctx->r1 = S32(0X3000 << 16);
    // 0x8010875C: lbu         $v0, 0x7B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7B);
    // 0x80108760: srl         $t5, $v0, 6
    ctx->r13 = S32(U32(ctx->r2) >> 6);
    // 0x80108764: bne         $t5, $zero, L_80108774
    if (ctx->r13 != 0) {
        // 0x80108768: andi        $t7, $v0, 0xFF3F
        ctx->r15 = ctx->r2 & 0XFF3F;
            goto L_80108774;
    }
    // 0x80108768: andi        $t7, $v0, 0xFF3F
    ctx->r15 = ctx->r2 & 0XFF3F;
    // 0x8010876C: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x80108770: sb          $t8, 0x7B($a0)
    MEM_B(0X7B, ctx->r4) = ctx->r24;
L_80108774:
    // 0x80108774: lbu         $t9, 0x77($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X77);
    // 0x80108778: ori         $t2, $t9, 0x40
    ctx->r10 = ctx->r25 | 0X40;
    // 0x8010877C: sb          $t2, 0x77($a0)
    MEM_B(0X77, ctx->r4) = ctx->r10;
L_80108780:
    // 0x80108780: lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // 0x80108784: and         $t1, $a2, $v0
    ctx->r9 = ctx->r6 & ctx->r2;
    // 0x80108788: bne         $v0, $t1, L_8010879C
    if (ctx->r2 != ctx->r9) {
        // 0x8010878C: ori         $at, $at, 0x2000
        ctx->r1 = ctx->r1 | 0X2000;
            goto L_8010879C;
    }
    // 0x8010878C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80108790: lbu         $t4, 0x74($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X74);
    // 0x80108794: ori         $t6, $t4, 0x2
    ctx->r14 = ctx->r12 | 0X2;
    // 0x80108798: sb          $t6, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r14;
L_8010879C:
    // 0x8010879C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x801087A0: and         $t5, $a2, $v0
    ctx->r13 = ctx->r6 & ctx->r2;
    // 0x801087A4: bne         $v0, $t5, L_801087B8
    if (ctx->r2 != ctx->r13) {
        // 0x801087A8: and         $t9, $a1, $at
        ctx->r25 = ctx->r5 & ctx->r1;
            goto L_801087B8;
    }
    // 0x801087A8: and         $t9, $a1, $at
    ctx->r25 = ctx->r5 & ctx->r1;
    // 0x801087AC: lbu         $t8, 0x96($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X96);
    // 0x801087B0: ori         $t0, $t8, 0x80
    ctx->r8 = ctx->r24 | 0X80;
    // 0x801087B4: sb          $t0, 0x96($a0)
    MEM_B(0X96, ctx->r4) = ctx->r8;
L_801087B8:
    // 0x801087B8: beql        $a3, $zero, L_80108874
    if (ctx->r7 == 0) {
        // 0x801087BC: lbu         $t6, 0x7B($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X7B);
            goto L_80108874;
    }
    goto skip_3;
    // 0x801087BC: lbu         $t6, 0x7B($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X7B);
    skip_3:
    // 0x801087C0: beql        $t9, $zero, L_801087E8
    if (ctx->r25 == 0) {
        // 0x801087C4: lw          $t4, 0x10($a3)
        ctx->r12 = MEM_W(ctx->r7, 0X10);
            goto L_801087E8;
    }
    goto skip_4;
    // 0x801087C4: lw          $t4, 0x10($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X10);
    skip_4:
    // 0x801087C8: lw          $t2, 0x10($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X10);
    // 0x801087CC: sll         $t1, $t2, 28
    ctx->r9 = S32(ctx->r10 << 28);
    // 0x801087D0: srl         $t3, $t1, 30
    ctx->r11 = S32(U32(ctx->r9) >> 30);
    // 0x801087D4: beql        $t3, $zero, L_80108874
    if (ctx->r11 == 0) {
        // 0x801087D8: lbu         $t6, 0x7B($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X7B);
            goto L_80108874;
    }
    goto skip_5;
    // 0x801087D8: lbu         $t6, 0x7B($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X7B);
    skip_5:
    // 0x801087DC: b           L_80108874
    // 0x801087E0: lbu         $t6, 0x7B($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X7B);
        goto L_80108874;
    // 0x801087E0: lbu         $t6, 0x7B($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X7B);
    // 0x801087E4: lw          $t4, 0x10($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X10);
L_801087E8:
    // 0x801087E8: lbu         $t9, 0x7B($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X7B);
    // 0x801087EC: sll         $t6, $t4, 28
    ctx->r14 = S32(ctx->r12 << 28);
    // 0x801087F0: srl         $t7, $t6, 30
    ctx->r15 = S32(U32(ctx->r14) >> 30);
    // 0x801087F4: sll         $t0, $t7, 6
    ctx->r8 = S32(ctx->r15 << 6);
    // 0x801087F8: andi        $t2, $t9, 0xFF3F
    ctx->r10 = ctx->r25 & 0XFF3F;
    // 0x801087FC: or          $t1, $t0, $t2
    ctx->r9 = ctx->r8 | ctx->r10;
    // 0x80108800: sb          $t1, 0x7B($a0)
    MEM_B(0X7B, ctx->r4) = ctx->r9;
    // 0x80108804: lw          $t3, 0x10($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X10);
    // 0x80108808: lbu         $t9, 0x77($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X77);
    // 0x8010880C: andi        $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 & 0XFF;
    // 0x80108810: sll         $t4, $t3, 27
    ctx->r12 = S32(ctx->r11 << 27);
    // 0x80108814: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x80108818: sll         $t7, $t5, 6
    ctx->r15 = S32(ctx->r13 << 6);
    // 0x8010881C: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x80108820: andi        $t0, $t9, 0xFFBF
    ctx->r8 = ctx->r25 & 0XFFBF;
    // 0x80108824: or          $t2, $t8, $t0
    ctx->r10 = ctx->r24 | ctx->r8;
    // 0x80108828: srl         $t3, $t1, 6
    ctx->r11 = S32(U32(ctx->r9) >> 6);
    // 0x8010882C: bne         $t3, $zero, L_80108844
    if (ctx->r11 != 0) {
        // 0x80108830: sb          $t2, 0x77($a0)
        MEM_B(0X77, ctx->r4) = ctx->r10;
            goto L_80108844;
    }
    // 0x80108830: sb          $t2, 0x77($a0)
    MEM_B(0X77, ctx->r4) = ctx->r10;
    // 0x80108834: lw          $t4, 0x74($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X74);
    // 0x80108838: sll         $t5, $t4, 25
    ctx->r13 = S32(ctx->r12 << 25);
    // 0x8010883C: bgezl       $t5, L_80108874
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80108840: lbu         $t6, 0x7B($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X7B);
            goto L_80108874;
    }
    goto skip_6;
    // 0x80108840: lbu         $t6, 0x7B($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X7B);
    skip_6:
L_80108844:
    // 0x80108844: lw          $t7, 0x70($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X70);
    // 0x80108848: sll         $t8, $t7, 10
    ctx->r24 = S32(ctx->r15 << 10);
    // 0x8010884C: bltzl       $t8, L_80108874
    if (SIGNED(ctx->r24) < 0) {
        // 0x80108850: lbu         $t6, 0x7B($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X7B);
            goto L_80108874;
    }
    goto skip_7;
    // 0x80108850: lbu         $t6, 0x7B($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X7B);
    skip_7:
    // 0x80108854: lbu         $t0, 0x70($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X70);
    // 0x80108858: andi        $t2, $t0, 0x1
    ctx->r10 = ctx->r8 & 0X1;
    // 0x8010885C: bnel        $t2, $zero, L_80108874
    if (ctx->r10 != 0) {
        // 0x80108860: lbu         $t6, 0x7B($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X7B);
            goto L_80108874;
    }
    goto skip_8;
    // 0x80108860: lbu         $t6, 0x7B($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X7B);
    skip_8:
    // 0x80108864: lbu         $t3, 0x71($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X71);
    // 0x80108868: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x8010886C: sb          $t4, 0x71($a0)
    MEM_B(0X71, ctx->r4) = ctx->r12;
    // 0x80108870: lbu         $t6, 0x7B($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X7B);
L_80108874:
    // 0x80108874: srl         $t5, $t6, 6
    ctx->r13 = S32(U32(ctx->r14) >> 6);
    // 0x80108878: beql        $t5, $zero, L_8010889C
    if (ctx->r13 == 0) {
        // 0x8010887C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010889C;
    }
    goto skip_9;
    // 0x8010887C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x80108880: lw          $t7, 0x70($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X70);
    // 0x80108884: sll         $t8, $t7, 28
    ctx->r24 = S32(ctx->r15 << 28);
    // 0x80108888: bgezl       $t8, L_8010889C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8010888C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010889C;
    }
    goto skip_10;
    // 0x8010888C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_10:
    // 0x80108890: jal         0x8010381C
    // 0x80108894: nop

    func_8010381C(rdram, ctx);
        goto after_0;
    // 0x80108894: nop

    after_0:
    // 0x80108898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010889C:
    // 0x8010889C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801088A0: jr          $ra
    // 0x801088A4: nop

    return;
    // 0x801088A4: nop

;}
RECOMP_FUNC void chlakemonster_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F3C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1748, 0X2328) << 16);
    // 0x80801F40: jr          $ra
    // 0x80801F44: addiu       $v0, $v0, 0x2328
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1748, 0X2328));
    return;
    // 0x80801F44: addiu       $v0, $v0, 0x2328
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1748, 0X2328));
    // 0x80801F48: nop

    // 0x80801F4C: nop

;}
RECOMP_FUNC void _chhoopswoop_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F00: syscall     259
    recomp_syscall_handler(rdram, ctx, 0x80085F00);
    return;
    // 0x80085F04: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800000_cheggfire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80100094
    // 0x80800010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800014: jal         0x800D8FF8
    // 0x80800018: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800018: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080001C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800020: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2108, 0X3A0) << 16);
    // 0x80800024: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800028: lwc1        $f4, 0x28($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X28);
    // 0x8080002C: lui         $a3, 0x3D08
    ctx->r7 = S32(0X3D08 << 16);
    // 0x80800030: lwc1        $f12, 0x30($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80800034: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80800038: ori         $a3, $a3, 0x6595
    ctx->r7 = ctx->r7 | 0X6595;
    // 0x8080003C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80800040: swc1        $f6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f6.u32l;
    // 0x80800044: lwc1        $f8, 0x3A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2108, 0X3A0));
    // 0x80800048: jal         0x800F10B4
    // 0x8080004C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x8080004C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800050: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800054: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800058: lwc1        $f2, 0x28($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X28);
    // 0x8080005C: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x80800060: nop

    // 0x80800064: bc1f        L_80800088
    if (!c1cs) {
        // 0x80800068: nop
    
            goto L_80800088;
    }
    // 0x80800068: nop

    // 0x8080006C: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
L_80800070:
    // 0x80800070: swc1        $f10, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f10.u32l;
    // 0x80800074: lwc1        $f2, 0x28($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X28);
    // 0x80800078: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x8080007C: nop

    // 0x80800080: bc1tl       L_80800070
    if (c1cs) {
        // 0x80800084: add.s       $f10, $f2, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
            goto L_80800070;
    }
    goto skip_0;
    // 0x80800084: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
    skip_0:
L_80800088:
    // 0x80800088: jal         0x8001210C
    // 0x8080008C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_3;
    // 0x8080008C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800090: bnel        $v0, $zero, L_808000AC
    if (ctx->r2 != 0) {
        // 0x80800094: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000AC;
    }
    goto skip_1;
    // 0x80800094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800098: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8080009C: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x808000A0: jal         0x80088A78
    // 0x808000A4: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    _fxegg_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x808000A4: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    after_4:
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000AC:
    // 0x808000AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
RECOMP_FUNC void func_80800848_chdinoswitches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800848: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080084C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800850: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800854: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800858: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080085C: beq         $a1, $at, L_80800878
    if (ctx->r5 == ctx->r1) {
        // 0x80800860: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800878;
    }
    // 0x80800860: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800864: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800868: beql        $a1, $at, L_808008AC
    if (ctx->r5 == ctx->r1) {
        // 0x8080086C: lhu         $a2, 0x76($s0)
        ctx->r6 = MEM_HU(ctx->r16, 0X76);
            goto L_808008AC;
    }
    goto skip_0;
    // 0x8080086C: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
    skip_0:
    // 0x80800870: b           L_808008DC
    // 0x80800874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008DC;
    // 0x80800874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800878:
    // 0x80800878: jal         0x800880D0
    // 0x8080087C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcaudiolist_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080087C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800884: jal         0x80102424
    // 0x80800888: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800888: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8080088C: jal         0x8010A570
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800898: jal         0x80103110
    // 0x8080089C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_3;
    // 0x8080089C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808008A0: b           L_808008DC
    // 0x808008A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008DC;
    // 0x808008A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808008A8: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
L_808008AC:
    // 0x808008AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B0: addiu       $a1, $zero, 0x364
    ctx->r5 = ADD32(0, 0X364);
    // 0x808008B4: srl         $t6, $a2, 7
    ctx->r14 = S32(U32(ctx->r6) >> 7);
    // 0x808008B8: jal         0x80089C70
    // 0x808008BC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    _subaddiefind_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x808008BC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_4:
    // 0x808008C0: jal         0x80800270
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800270_chdinoswitches(rdram, ctx);
        goto after_5;
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808008C8: b           L_808008DC
    // 0x808008CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008DC;
    // 0x808008CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808008D0: b           L_808008DC
    // 0x808008D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008DC;
    // 0x808008D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808008D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008DC:
    // 0x808008DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008E8: jr          $ra
    // 0x808008EC: nop

    return;
    // 0x808008EC: nop

;}
RECOMP_FUNC void func_800DBBF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DBBF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DBBFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DBC00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DBC04: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800DBC08: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800DBC0C: jal         0x800DB9D0
    // 0x800DBC10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DB9D0(rdram, ctx);
        goto after_0;
    // 0x800DBC10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800DBC14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800DBC18: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800DBC1C: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    // 0x800DBC20: jal         0x8001BBA0
    // 0x800DBC24: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    rare_memcpy(rdram, ctx);
        goto after_1;
    // 0x800DBC24: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800DBC28: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800DBC2C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800DBC30: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800DBC34: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800DBC38: addu        $v0, $v1, $t7
    ctx->r2 = ADD32(ctx->r3, ctx->r15);
    // 0x800DBC3C: swc1        $f0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f0.u32l;
    // 0x800DBC40: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x800DBC44: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x800DBC48: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x800DBC4C: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x800DBC50: swc1        $f0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f0.u32l;
    // 0x800DBC54: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x800DBC58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DBC5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DBC60: jr          $ra
    // 0x800DBC64: nop

    return;
    // 0x800DBC64: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801484: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080148C: jal         0x80800000
    // 0x80801490: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x80801490: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801494: jal         0x80090A2C
    // 0x80801498: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80090A2C(rdram, ctx);
        goto after_1;
    // 0x80801498: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080149C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808014A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808014A4: jr          $ra
    // 0x808014A8: nop

    return;
    // 0x808014A8: nop

;}
RECOMP_FUNC void func_80800E40_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800E44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E4C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800E50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E54: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800E58: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800E5C: jal         0x80100094
    // 0x80800E60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800E60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800E64: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800E6C: beq         $a3, $at, L_80800ED0
    if (ctx->r7 == ctx->r1) {
        // 0x80800E70: addiu       $at, $zero, 0x38
        ctx->r1 = ADD32(0, 0X38);
            goto L_80800ED0;
    }
    // 0x80800E70: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80800E74: beq         $a3, $at, L_80800FA8
    if (ctx->r7 == ctx->r1) {
        // 0x80800E78: addiu       $at, $zero, 0x3E
        ctx->r1 = ADD32(0, 0X3E);
            goto L_80800FA8;
    }
    // 0x80800E78: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800E7C: beq         $a3, $at, L_80800EF0
    if (ctx->r7 == ctx->r1) {
        // 0x80800E80: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80800EF0;
    }
    // 0x80800E80: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800E84: beq         $a3, $at, L_80800EC0
    if (ctx->r7 == ctx->r1) {
        // 0x80800E88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EC0;
    }
    // 0x80800E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E8C: addiu       $at, $zero, 0x8F
    ctx->r1 = ADD32(0, 0X8F);
    // 0x80800E90: beq         $a3, $at, L_80800FB8
    if (ctx->r7 == ctx->r1) {
        // 0x80800E94: lw          $t2, 0x30($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X30);
            goto L_80800FB8;
    }
    // 0x80800E94: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80800E98: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800E9C: beq         $a3, $at, L_80800F34
    if (ctx->r7 == ctx->r1) {
        // 0x80800EA0: addiu       $at, $zero, 0x93
        ctx->r1 = ADD32(0, 0X93);
            goto L_80800F34;
    }
    // 0x80800EA0: addiu       $at, $zero, 0x93
    ctx->r1 = ADD32(0, 0X93);
    // 0x80800EA4: beq         $a3, $at, L_80800F88
    if (ctx->r7 == ctx->r1) {
        // 0x80800EA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F88;
    }
    // 0x80800EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EAC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800EB0: beq         $a3, $at, L_80800F98
    if (ctx->r7 == ctx->r1) {
        // 0x80800EB4: nop
    
            goto L_80800F98;
    }
    // 0x80800EB4: nop

    // 0x80800EB8: b           L_80800FE8
    // 0x80800EBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FE8;
    // 0x80800EBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800EC0:
    // 0x80800EC0: jal         0x80801160
    // 0x80800EC4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80801160_chfactoryrobot(rdram, ctx);
        goto after_1;
    // 0x80800EC4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x80800EC8: b           L_80800FE8
    // 0x80800ECC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800FE8;
    // 0x80800ECC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800ED0:
    // 0x80800ED0: jal         0x8008A4A8
    // 0x80800ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800ED8: bne         $v0, $zero, L_80800FE4
    if (ctx->r2 != 0) {
        // 0x80800EDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FE4;
    }
    // 0x80800EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EE0: jal         0x80107070
    // 0x80800EE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80107070(rdram, ctx);
        goto after_3;
    // 0x80800EE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800EE8: b           L_80800FE8
    // 0x80800EEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800FE8;
    // 0x80800EEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EF0:
    // 0x80800EF0: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800EF4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800EF8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80800EFC: bgezl       $t8, L_80800F18
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800F00: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80800F18;
    }
    goto skip_0;
    // 0x80800F00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x80800F04: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800F08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800F0C: b           L_80800F20
    // 0x80800F10: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
        goto L_80800F20;
    // 0x80800F10: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x80800F14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80800F18:
    // 0x80800F18: nop

    // 0x80800F1C: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
L_80800F20:
    // 0x80800F20: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80800F24: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80800F28: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x80800F2C: b           L_80800FE4
    // 0x80800F30: sh          $t1, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r9;
        goto L_80800FE4;
    // 0x80800F30: sh          $t1, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r9;
L_80800F34:
    // 0x80800F34: jal         0x80101080
    // 0x80800F38: nop

    func_80101080(rdram, ctx);
        goto after_4;
    // 0x80800F38: nop

    after_4:
    // 0x80800F3C: jal         0x80106790
    // 0x80800F40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80800F40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80800F44: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800F48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F4C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800F50: jal         0x800866A0
    // 0x80800F54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x80800F54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800F58: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800F5C: jal         0x800866C0
    // 0x80800F60: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    _chexploder_entrypoint_13(rdram, ctx);
        goto after_7;
    // 0x80800F60: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_7:
    // 0x80800F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F68: jal         0x80107070
    // 0x80800F6C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80107070(rdram, ctx);
        goto after_8;
    // 0x80800F6C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x80800F70: bnel        $v0, $zero, L_80800FE8
    if (ctx->r2 != 0) {
        // 0x80800F74: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800FE8;
    }
    goto skip_1;
    // 0x80800F74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800F78: jal         0x800FFAB0
    // 0x80800F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x80800F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800F80: b           L_80800FE8
    // 0x80800F84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800FE8;
    // 0x80800F84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F88:
    // 0x80800F88: jal         0x80802470
    // 0x80800F8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802470_chfactoryrobot(rdram, ctx);
        goto after_10;
    // 0x80800F8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80800F90: b           L_80800FE8
    // 0x80800F94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800FE8;
    // 0x80800F94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F98:
    // 0x80800F98: jal         0x8080183C
    // 0x80800F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080183C_chfactoryrobot(rdram, ctx);
        goto after_11;
    // 0x80800F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800FA0: b           L_80800FE8
    // 0x80800FA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800FE8;
    // 0x80800FA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800FA8:
    // 0x80800FA8: jal         0x80801C50
    // 0x80800FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C50_chfactoryrobot(rdram, ctx);
        goto after_12;
    // 0x80800FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800FB0: b           L_80800FEC
    // 0x80800FB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FEC;
    // 0x80800FB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800FB8:
    // 0x80800FB8: bnel        $t2, $zero, L_80800FE8
    if (ctx->r10 != 0) {
        // 0x80800FBC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800FE8;
    }
    goto skip_2;
    // 0x80800FBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x80800FC0: jal         0x8010A590
    // 0x80800FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_13;
    // 0x80800FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FCC: jal         0x80109FE8
    // 0x80800FD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_14;
    // 0x80800FD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800FD4: b           L_80800FE8
    // 0x80800FD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800FE8;
    // 0x80800FD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800FDC: b           L_80800FE8
    // 0x80800FE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FE8;
    // 0x80800FE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800FE4:
    // 0x80800FE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800FE8:
    // 0x80800FE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800FEC:
    // 0x80800FEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800FF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800FF4: jr          $ra
    // 0x80800FF8: nop

    return;
    // 0x80800FF8: nop

;}
RECOMP_FUNC void func_80803A58_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803A58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803A5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803A60: jal         0x80088330
    // 0x80803A64: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    _gcstatusDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80803A64: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x80803A68: jal         0x80803940
    // 0x80803A6C: nop

    func_80803940_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80803A6C: nop

    after_1:
    // 0x80803A70: jal         0x80803988
    // 0x80803A74: nop

    func_80803988_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80803A74: nop

    after_2:
    // 0x80803A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803A7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803A80: jr          $ra
    // 0x80803A84: nop

    return;
    // 0x80803A84: nop

;}
