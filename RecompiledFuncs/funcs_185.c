#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _plsu_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087898: syscall     638
    recomp_syscall_handler(rdram, ctx, 0x80087898);
    return;
    // 0x8008789C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800014_chbigtopticket(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080001C: jal         0x800D8FF8
    // 0x80800020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800024: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x80800028: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080002C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800034: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800038: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x8080003C: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80800040: jal         0x80103110
    // 0x80800044: swc1        $f10, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f10.u32l;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x80800044: swc1        $f10, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f10.u32l;
    after_1:
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080004C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void func_80801AB4_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AB4: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80801AB8: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80801ABC: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80801AC0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80801AC4: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80801AC8: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80801ACC: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80801AD0: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80801AD4: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80801AD8: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80801ADC: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80801AE0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80801AE4: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80801AE8: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80801AEC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80801AF0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80801AF4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80801AF8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801AFC: jal         0x80106790
    // 0x80801B00: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801B00: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80801B04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801B08: jal         0x80100094
    // 0x80801B0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801B0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801B10: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x80801B14: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80801B18: jal         0x80103F38
    // 0x80801B1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103F38(rdram, ctx);
        goto after_2;
    // 0x80801B1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80801B20: lw          $t6, 0x64($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X64);
    // 0x80801B24: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80801B28: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80801B2C: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80801B30: bgez        $t8, L_80801B40
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801B34: nop
    
            goto L_80801B40;
    }
    // 0x80801B34: nop

    // 0x80801B38: b           L_80801CD8
    // 0x80801B3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801CD8;
    // 0x80801B3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801B40:
    // 0x80801B40: jal         0x80100094
    // 0x80801B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80801B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80801B48: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80801B4C: jal         0x80088368
    // 0x80801B50: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80801B50: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_4:
    // 0x80801B54: blez        $v0, L_80801CD4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801B58: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80801CD4;
    }
    // 0x80801B58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801B5C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80801B60: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80801B64: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80801B68: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x80801B6C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80801B70: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80801B74: lw          $s4, 0xA0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA0);
    // 0x80801B78: addiu       $s3, $sp, 0x84
    ctx->r19 = ADD32(ctx->r29, 0X84);
    // 0x80801B7C: addiu       $s2, $sp, 0xA4
    ctx->r18 = ADD32(ctx->r29, 0XA4);
L_80801B80:
    // 0x80801B80: jal         0x800F6438
    // 0x80801B84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F6438(rdram, ctx);
        goto after_5;
    // 0x80801B84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80801B88: beq         $v0, $zero, L_80801CBC
    if (ctx->r2 == 0) {
        // 0x80801B8C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801CBC;
    }
    // 0x80801B8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801B90: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x80801B94: addu        $s0, $s7, $t9
    ctx->r16 = ADD32(ctx->r23, ctx->r25);
    // 0x80801B98: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80801B9C: jal         0x800F5A00
    // 0x80801BA0: addiu       $s5, $s6, 0x4
    ctx->r21 = ADD32(ctx->r22, 0X4);
    func_800F5A00(rdram, ctx);
        goto after_6;
    // 0x80801BA0: addiu       $s5, $s6, 0x4
    ctx->r21 = ADD32(ctx->r22, 0X4);
    after_6:
    // 0x80801BA4: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80801BA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801BAC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80801BB0: add.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f26.fl;
    // 0x80801BB4: jal         0x800EF3DC
    // 0x80801BB8: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    func_800EF3DC(rdram, ctx);
        goto after_7;
    // 0x80801BB8: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x80801BBC: lw          $t0, 0x20($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X20);
    // 0x80801BC0: beql        $t0, $zero, L_80801CB8
    if (ctx->r8 == 0) {
        // 0x80801BC4: sw          $fp, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->r30;
            goto L_80801CB8;
    }
    goto skip_0;
    // 0x80801BC4: sw          $fp, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r30;
    skip_0:
    // 0x80801BC8: mul.s       $f20, $f24, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x80801BCC: jal         0x800EEFD4
    // 0x80801BD0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EEFD4(rdram, ctx);
        goto after_8;
    // 0x80801BD0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x80801BD4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80801BD8: nop

    // 0x80801BDC: bc1fl       L_80801CB8
    if (!c1cs) {
        // 0x80801BE0: sw          $fp, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->r30;
            goto L_80801CB8;
    }
    goto skip_1;
    // 0x80801BE0: sw          $fp, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r30;
    skip_1:
    // 0x80801BE4: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80801BE8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80801BEC: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80801BF0: jal         0x800EFA4C
    // 0x80801BF4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x80801BF4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_9:
    // 0x80801BF8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801BFC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80801C00: jal         0x800EF934
    // 0x80801C04: lw          $a2, 0x48($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X48);
    func_800EF934(rdram, ctx);
        goto after_10;
    // 0x80801C04: lw          $a2, 0x48($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X48);
    after_10:
    // 0x80801C08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801C0C: jal         0x800EEAA4
    // 0x80801C10: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EEAA4(rdram, ctx);
        goto after_11;
    // 0x80801C10: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_11:
    // 0x80801C14: c.le.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl <= ctx->f0.fl;
    // 0x80801C18: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x80801C1C: bc1f        L_80801C2C
    if (!c1cs) {
        // 0x80801C20: nop
    
            goto L_80801C2C;
    }
    // 0x80801C20: nop

    // 0x80801C24: b           L_80801C2C
    // 0x80801C28: or          $s4, $fp, $zero
    ctx->r20 = ctx->r30 | 0;
        goto L_80801C2C;
    // 0x80801C28: or          $s4, $fp, $zero
    ctx->r20 = ctx->r30 | 0;
L_80801C2C:
    // 0x80801C2C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80801C30: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x80801C34: bnel        $s4, $t2, L_80801CB8
    if (ctx->r20 != ctx->r10) {
        // 0x80801C38: sw          $fp, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->r30;
            goto L_80801CB8;
    }
    goto skip_2;
    // 0x80801C38: sw          $fp, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r30;
    skip_2:
    // 0x80801C3C: lw          $s0, 0x40($s7)
    ctx->r16 = MEM_W(ctx->r23, 0X40);
    // 0x80801C40: jal         0x800D3948
    // 0x80801C44: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800D3948(rdram, ctx);
        goto after_12;
    // 0x80801C44: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_12:
    // 0x80801C48: beq         $v0, $zero, L_80801C6C
    if (ctx->r2 == 0) {
        // 0x80801C4C: lw          $a0, 0x94($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X94);
            goto L_80801C6C;
    }
    // 0x80801C4C: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x80801C50: addiu       $a0, $a0, 0x4DC
    ctx->r4 = ADD32(ctx->r4, 0X4DC);
    // 0x80801C54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801C58: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80801C5C: jal         0x800899A0
    // 0x80801C60: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _sumultiscore_entrypoint_7(rdram, ctx);
        goto after_13;
    // 0x80801C60: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_13:
    // 0x80801C64: b           L_80801C90
    // 0x80801C68: lbu         $t6, 0x65($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X65);
        goto L_80801C90;
    // 0x80801C68: lbu         $t6, 0x65($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X65);
L_80801C6C:
    // 0x80801C6C: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x80801C70: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80801C74: addiu       $a1, $zero, 0x9E2
    ctx->r5 = ADD32(0, 0X9E2);
    // 0x80801C78: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x80801C7C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80801C80: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80801C84: jal         0x80801D20
    // 0x80801C88: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    func_80801D20_chhoopswoop(rdram, ctx);
        goto after_14;
    // 0x80801C88: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    after_14:
    // 0x80801C8C: lbu         $t6, 0x65($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X65);
L_80801C90:
    // 0x80801C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C94: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801C98: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x80801C9C: sb          $t7, 0x65($s6)
    MEM_B(0X65, ctx->r22) = ctx->r15;
    // 0x80801CA0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80801CA4: jal         0x80086468
    // 0x80801CA8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _chscorepoints_entrypoint_2(rdram, ctx);
        goto after_15;
    // 0x80801CA8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_15:
    // 0x80801CAC: b           L_80801CD8
    // 0x80801CB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801CD8;
    // 0x80801CB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801CB4: sw          $fp, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r30;
L_80801CB8:
    // 0x80801CB8: sw          $s4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r20;
L_80801CBC:
    // 0x80801CBC: jal         0x80088368
    // 0x80801CC0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_16;
    // 0x80801CC0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_16:
    // 0x80801CC4: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801CC8: bne         $at, $zero, L_80801B80
    if (ctx->r1 != 0) {
        // 0x80801CCC: nop
    
            goto L_80801B80;
    }
    // 0x80801CCC: nop

    // 0x80801CD0: sw          $s4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r20;
L_80801CD4:
    // 0x80801CD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801CD8:
    // 0x80801CD8: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80801CDC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801CE0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80801CE4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80801CE8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80801CEC: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80801CF0: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80801CF4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80801CF8: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80801CFC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80801D00: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80801D04: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80801D08: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80801D0C: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80801D10: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80801D14: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80801D18: jr          $ra
    // 0x80801D1C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80801D1C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void ncpod_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808006A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808006AC: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x808006B0: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x808006B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006B8: jal         0x808002B0
    // 0x808006BC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    ncpod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808006BC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x808006C0: lbu         $v1, 0x41($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X41);
    // 0x808006C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006C8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808006CC: beq         $v1, $zero, L_80800728
    if (ctx->r3 == 0) {
        // 0x808006D0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800728;
    }
    // 0x808006D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006D4: beq         $v1, $at, L_808006FC
    if (ctx->r3 == ctx->r1) {
        // 0x808006D8: lw          $a1, 0x34($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X34);
            goto L_808006FC;
    }
    // 0x808006D8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808006DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808006E0: beq         $v1, $at, L_8080070C
    if (ctx->r3 == ctx->r1) {
        // 0x808006E4: lw          $a1, 0x34($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X34);
            goto L_8080070C;
    }
    // 0x808006E4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808006E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808006EC: beq         $v1, $at, L_8080071C
    if (ctx->r3 == ctx->r1) {
        // 0x808006F0: lw          $a1, 0x34($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X34);
            goto L_8080071C;
    }
    // 0x808006F0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808006F4: b           L_8080072C
    // 0x808006F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
        goto L_8080072C;
    // 0x808006F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_808006FC:
    // 0x808006FC: jal         0x800895D8
    // 0x80800700: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    _ncpoddialog_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800700: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_1:
    // 0x80800704: b           L_80800728
    // 0x80800708: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80800728;
    // 0x80800708: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8080070C:
    // 0x8080070C: jal         0x80089668
    // 0x80800710: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    _ncpoducam_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800710: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    after_2:
    // 0x80800714: b           L_80800728
    // 0x80800718: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80800728;
    // 0x80800718: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8080071C:
    // 0x8080071C: jal         0x800896C0
    // 0x80800720: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    _ncpodfixpos_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800720: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    after_3:
    // 0x80800724: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80800728:
    // 0x80800728: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_8080072C:
    // 0x8080072C: beql        $a0, $at, L_808007C8
    if (ctx->r4 == ctx->r1) {
        // 0x80800730: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808007C8;
    }
    goto skip_0;
    // 0x80800730: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800734: lbu         $t8, 0x40($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X40);
    // 0x80800738: beql        $t8, $zero, L_808007C8
    if (ctx->r24 == 0) {
        // 0x8080073C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808007C8;
    }
    goto skip_1;
    // 0x8080073C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800740: jal         0x800A940C
    // 0x80800744: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    func_800A940C(rdram, ctx);
        goto after_4;
    // 0x80800744: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x80800748: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080074C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800750: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800754: jal         0x8010FE14
    // 0x80800758: addiu       $a2, $s0, 0x24
    ctx->r6 = ADD32(ctx->r16, 0X24);
    func_8010FE14(rdram, ctx);
        goto after_5;
    // 0x80800758: addiu       $a2, $s0, 0x24
    ctx->r6 = ADD32(ctx->r16, 0X24);
    after_5:
    // 0x8080075C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800760: jal         0x800C5148
    // 0x80800764: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_800C5148(rdram, ctx);
        goto after_6;
    // 0x80800764: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_6:
    // 0x80800768: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8080076C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800770: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800774: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800778: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080077C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800780: nop

    // 0x80800784: bc1f        L_808007BC
    if (!c1cs) {
        // 0x80800788: nop
    
            goto L_808007BC;
    }
    // 0x80800788: nop

    // 0x8080078C: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800790: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800794: nop

    // 0x80800798: c.eq.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl == ctx->f0.fl;
    // 0x8080079C: nop

    // 0x808007A0: bc1t        L_808007BC
    if (c1cs) {
        // 0x808007A4: nop
    
            goto L_808007BC;
    }
    // 0x808007A4: nop

    // 0x808007A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808007AC: jal         0x800C51A4
    // 0x808007B0: nop

    func_800C51A4(rdram, ctx);
        goto after_7;
    // 0x808007B0: nop

    after_7:
    // 0x808007B4: b           L_808007C8
    // 0x808007B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007C8;
    // 0x808007B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007BC:
    // 0x808007BC: jal         0x800C51A4
    // 0x808007C0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800C51A4(rdram, ctx);
        goto after_8;
    // 0x808007C0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_8:
    // 0x808007C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007C8:
    // 0x808007C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808007D0: jr          $ra
    // 0x808007D4: nop

    return;
    // 0x808007D4: nop

;}
RECOMP_FUNC void func_80094D04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094D04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80094D08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80094D0C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80094D10: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80094D14: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80094D18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80094D1C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80094D20: jal         0x80094C64
    // 0x80094D24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80094C64(rdram, ctx);
        goto after_0;
    // 0x80094D24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80094D28: beq         $v0, $zero, L_80094D90
    if (ctx->r2 == 0) {
        // 0x80094D2C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80094D90;
    }
    // 0x80094D2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80094D30:
    // 0x80094D30: lw          $t6, 0x64($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X64);
    // 0x80094D34: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x80094D38: beql        $s1, $t7, L_80094D7C
    if (ctx->r17 == ctx->r15) {
        // 0x80094D3C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80094D7C;
    }
    goto skip_0;
    // 0x80094D3C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80094D40: jal         0x800883E8
    // 0x80094D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcegg_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80094D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80094D48: beql        $v0, $zero, L_80094D7C
    if (ctx->r2 == 0) {
        // 0x80094D4C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80094D7C;
    }
    goto skip_1;
    // 0x80094D4C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80094D50: jal         0x800883E0
    // 0x80094D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcegg_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80094D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80094D58: jal         0x800D1C5C
    // 0x80094D5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D1C5C(rdram, ctx);
        goto after_3;
    // 0x80094D5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80094D60: jal         0x800D27C8
    // 0x80094D64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D27C8(rdram, ctx);
        goto after_4;
    // 0x80094D64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80094D68: bltz        $v0, L_80094D78
    if (SIGNED(ctx->r2) < 0) {
        // 0x80094D6C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80094D78;
    }
    // 0x80094D6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80094D70: jal         0x800FAA34
    // 0x80094D74: nop

    func_800FAA34(rdram, ctx);
        goto after_5;
    // 0x80094D74: nop

    after_5:
L_80094D78:
    // 0x80094D78: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80094D7C:
    // 0x80094D7C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80094D80: jal         0x80094C64
    // 0x80094D84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80094C64(rdram, ctx);
        goto after_6;
    // 0x80094D84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80094D88: bne         $v0, $zero, L_80094D30
    if (ctx->r2 != 0) {
        // 0x80094D8C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80094D30;
    }
    // 0x80094D8C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80094D90:
    // 0x80094D90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80094D94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80094D98: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80094D9C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80094DA0: jr          $ra
    // 0x80094DA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80094DA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void idbounce_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800568: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8080056C: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80800570: lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X90);
    // 0x80800574: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80800578: sw          $s7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r23;
    // 0x8080057C: sw          $s6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r22;
    // 0x80800580: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x80800584: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x80800588: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8080058C: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80800590: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80800594: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x80800598: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8080059C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x808005A0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x808005A4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x808005A8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808005AC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808005B0: lwc1        $f30, 0x4($s0)
    ctx->f30.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808005B4: sll         $t7, $a3, 4
    ctx->r15 = S32(ctx->r7 << 4);
    // 0x808005B8: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x808005BC: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x808005C0: lwc1        $f24, 0x20($s0)
    ctx->f24.u32l = MEM_W(ctx->r16, 0X20);
    // 0x808005C4: addu        $s6, $t7, $a1
    ctx->r22 = ADD32(ctx->r15, ctx->r5);
    // 0x808005C8: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x808005CC: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808005D0: sltu        $at, $a1, $s6
    ctx->r1 = ctx->r5 < ctx->r22 ? 1 : 0;
    // 0x808005D4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808005D8: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x808005DC: lbu         $s5, 0x0($s0)
    ctx->r21 = MEM_BU(ctx->r16, 0X0);
    // 0x808005E0: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x808005E4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808005E8: xori        $t6, $s5, 0x2
    ctx->r14 = ctx->r21 ^ 0X2;
    // 0x808005EC: sltiu       $s5, $t6, 0x1
    ctx->r21 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x808005F0: beq         $at, $zero, L_80800830
    if (ctx->r1 == 0) {
        // 0x808005F4: lwc1        $f26, 0x1C($s0)
        ctx->f26.u32l = MEM_W(ctx->r16, 0X1C);
            goto L_80800830;
    }
    // 0x808005F4: lwc1        $f26, 0x1C($s0)
    ctx->f26.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808005F8: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x808005FC: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80800600: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800604: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800608: addiu       $s3, $s3, 0x5480
    ctx->r19 = ADD32(ctx->r19, 0X5480);
    // 0x8080060C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_80800610:
    // 0x80800610: lbu         $t8, 0x1($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X1);
    // 0x80800614: lwc1        $f12, 0x38($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800618: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x8080061C: beql        $t8, $zero, L_808006B4
    if (ctx->r24 == 0) {
        // 0x80800620: lh          $t1, 0x2($s4)
        ctx->r9 = MEM_H(ctx->r20, 0X2);
            goto L_808006B4;
    }
    goto skip_0;
    // 0x80800620: lh          $t1, 0x2($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X2);
    skip_0:
    // 0x80800624: lh          $t9, 0x0($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X0);
    // 0x80800628: lh          $t0, 0x4($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X4);
    // 0x8080062C: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80800630: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80800634: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80800638: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080063C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800640: sub.s       $f0, $f16, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f30.fl;
    // 0x80800644: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800648: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8080064C: nop

    // 0x80800650: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80800654: jal         0x8002DCA0
    // 0x80800658: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80800658: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8080065C: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800660: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800664: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800668: nop

    // 0x8080066C: bc1fl       L_80800680
    if (!c1cs) {
        // 0x80800670: lwc1        $f16, 0x38($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
            goto L_80800680;
    }
    goto skip_1;
    // 0x80800670: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    skip_1:
    // 0x80800674: b           L_808006B0
    // 0x80800678: sub.s       $f20, $f22, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f22.fl - ctx->f24.fl;
        goto L_808006B0;
    // 0x80800678: sub.s       $f20, $f22, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x8080067C: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
L_80800680:
    // 0x80800680: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80800684: nop

    // 0x80800688: bc1fl       L_808006B4
    if (!c1cs) {
        // 0x8080068C: lh          $t1, 0x2($s4)
        ctx->r9 = MEM_H(ctx->r20, 0X2);
            goto L_808006B4;
    }
    goto skip_2;
    // 0x8080068C: lh          $t1, 0x2($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X2);
    skip_2:
    // 0x80800690: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80800694: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80800698: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080069C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808006A0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808006A4: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x808006A8: mul.s       $f16, $f24, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f24.fl, ctx->f10.fl);
    // 0x808006AC: sub.s       $f20, $f22, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f22.fl - ctx->f16.fl;
L_808006B0:
    // 0x808006B0: lh          $t1, 0x2($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X2);
L_808006B4:
    // 0x808006B4: lh          $t2, 0x2($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X2);
    // 0x808006B8: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x808006BC: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x808006C0: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x808006C4: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x808006C8: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808006CC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808006D0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808006D4: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x808006D8: nop

    // 0x808006DC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808006E0: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x808006E4: add.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x808006E8: mul.s       $f4, $f20, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x808006EC: add.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808006F0: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x808006F4: lw          $t5, 0x28($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X28);
    // 0x808006F8: lh          $t4, 0x2($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X2);
    // 0x808006FC: lwc1        $f16, 0x0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80800700: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80800704: mul.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x80800708: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080070C: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80800710: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800714: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80800718: nop

    // 0x8080071C: sh          $t7, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r15;
    // 0x80800720: lbu         $t8, 0x1($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X1);
    // 0x80800724: beq         $t8, $zero, L_808007FC
    if (ctx->r24 == 0) {
        // 0x80800728: nop
    
            goto L_808007FC;
    }
    // 0x80800728: nop

    // 0x8080072C: lbu         $v0, 0x2($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X2);
    // 0x80800730: bne         $v0, $zero, L_808007FC
    if (ctx->r2 != 0) {
        // 0x80800734: nop
    
            goto L_808007FC;
    }
    // 0x80800734: nop

    // 0x80800738: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8080073C: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x80800740: nop

    // 0x80800744: bc1f        L_808007FC
    if (!c1cs) {
        // 0x80800748: nop
    
            goto L_808007FC;
    }
    // 0x80800748: nop

    // 0x8080074C: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    // 0x80800750: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800754: lwc1        $f0, 0x0($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80800758: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8080075C: nop

    // 0x80800760: bc1fl       L_80800778
    if (!c1cs) {
        // 0x80800764: lwc1        $f2, 0x50($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
            goto L_80800778;
    }
    goto skip_3;
    // 0x80800764: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
    skip_3:
    // 0x80800768: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8080076C: b           L_808007C8
    // 0x80800770: div.s       $f20, $f0, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
        goto L_808007C8;
    // 0x80800770: div.s       $f20, $f0, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800774: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
L_80800778:
    // 0x80800778: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080077C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800780: mul.s       $f18, $f6, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80800784: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800788: nop

    // 0x8080078C: bc1fl       L_808007A4
    if (!c1cs) {
        // 0x80800790: lwc1        $f4, 0x48($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
            goto L_808007A4;
    }
    goto skip_4;
    // 0x80800790: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    skip_4:
    // 0x80800794: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800798: b           L_808007C8
    // 0x8080079C: nop

        goto L_808007C8;
    // 0x8080079C: nop

    // 0x808007A0: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
L_808007A4:
    // 0x808007A4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808007A8: nop

    // 0x808007AC: bc1fl       L_808007C8
    if (!c1cs) {
        // 0x808007B0: div.s       $f20, $f0, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
            goto L_808007C8;
    }
    goto skip_5;
    // 0x808007B0: div.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    skip_5:
    // 0x808007B4: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808007B8: mul.s       $f20, $f0, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808007BC: b           L_808007C8
    // 0x808007C0: nop

        goto L_808007C8;
    // 0x808007C0: nop

    // 0x808007C4: div.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
L_808007C8:
    // 0x808007C8: bne         $v0, $zero, L_808007FC
    if (ctx->r2 != 0) {
        // 0x808007CC: nop
    
            goto L_808007FC;
    }
    // 0x808007CC: nop

    // 0x808007D0: c.lt.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl < ctx->f20.fl;
    // 0x808007D4: nop

    // 0x808007D8: bc1f        L_808007E4
    if (!c1cs) {
        // 0x808007DC: nop
    
            goto L_808007E4;
    }
    // 0x808007DC: nop

    // 0x808007E0: mov.s       $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    ctx->f20.fl = ctx->f28.fl;
L_808007E4:
    // 0x808007E4: jal         0x800F54E4
    // 0x808007E8: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808007E8: nop

    after_1:
    // 0x808007EC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808007F0: jal         0x800F83E4
    // 0x808007F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F83E4(rdram, ctx);
        goto after_2;
    // 0x808007F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808007F8: sb          $s7, 0x2($s3)
    MEM_B(0X2, ctx->r19) = ctx->r23;
L_808007FC:
    // 0x808007FC: beq         $s5, $zero, L_80800814
    if (ctx->r21 == 0) {
        // 0x80800800: addiu       $s4, $s4, 0x10
        ctx->r20 = ADD32(ctx->r20, 0X10);
            goto L_80800814;
    }
    // 0x80800800: addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    // 0x80800804: lh          $t0, 0x2($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X2);
    // 0x80800808: bgezl       $t0, L_80800818
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8080080C: lw          $t1, 0x28($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X28);
            goto L_80800818;
    }
    goto skip_6;
    // 0x8080080C: lw          $t1, 0x28($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X28);
    skip_6:
    // 0x80800810: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
L_80800814:
    // 0x80800814: lw          $t1, 0x28($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X28);
L_80800818:
    // 0x80800818: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8080081C: sltu        $at, $s1, $s6
    ctx->r1 = ctx->r17 < ctx->r22 ? 1 : 0;
    // 0x80800820: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x80800824: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80800828: bne         $at, $zero, L_80800610
    if (ctx->r1 != 0) {
        // 0x8080082C: sw          $t2, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->r10;
            goto L_80800610;
    }
    // 0x8080082C: sw          $t2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r10;
L_80800830:
    // 0x80800830: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80800834: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800838: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8080083C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80800840: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80800844: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80800848: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8080084C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80800850: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80800854: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80800858: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8080085C: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x80800860: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x80800864: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x80800868: lw          $s7, 0x60($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X60);
    // 0x8080086C: jr          $ra
    // 0x80800870: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80800870: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_808012E0_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012E0: lhu         $t8, 0x6E($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X6E);
    // 0x808012E4: andi        $t7, $a1, 0x1FF
    ctx->r15 = ctx->r5 & 0X1FF;
    // 0x808012E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808012EC: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x808012F0: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x808012F4: bne         $a1, $at, L_8080130C
    if (ctx->r5 != ctx->r1) {
        // 0x808012F8: sh          $t0, 0x6E($a0)
        MEM_H(0X6E, ctx->r4) = ctx->r8;
            goto L_8080130C;
    }
    // 0x808012F8: sh          $t0, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r8;
    // 0x808012FC: lbu         $t2, 0x64($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X64);
    // 0x80801300: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80801304: jr          $ra
    // 0x80801308: sb          $t3, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r11;
    return;
    // 0x80801308: sb          $t3, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r11;
L_8080130C:
    // 0x8080130C: lbu         $t4, 0x64($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X64);
    // 0x80801310: andi        $t5, $t4, 0xFFFE
    ctx->r13 = ctx->r12 & 0XFFFE;
    // 0x80801314: sb          $t5, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r13;
    // 0x80801318: jr          $ra
    // 0x8080131C: nop

    return;
    // 0x8080131C: nop

;}
RECOMP_FUNC void func_80800000_bsmumsplat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x80083808
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bsmum_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: lui         $a2, 0x4045
    ctx->r6 = S32(0X4045 << 16);
    // 0x80800018: lui         $a3, 0x3DAE
    ctx->r7 = S32(0X3DAE << 16);
    // 0x8080001C: ori         $a3, $a3, 0x147B
    ctx->r7 = ctx->r7 | 0X147B;
    // 0x80800020: ori         $a2, $a2, 0x1EB8
    ctx->r6 = ctx->r6 | 0X1EB8;
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800028: jal         0x8008CE3C
    // 0x8080002C: addiu       $a1, $zero, 0xCB
    ctx->r5 = ADD32(0, 0XCB);
    baanim_playForDuration_onceStartingAt(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a1, $zero, 0xCB
    ctx->r5 = ADD32(0, 0XCB);
    after_1:
    // 0x80800030: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800034: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080003C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800040: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800044: jal         0x8009FFD8
    // 0x80800048: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800048: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8080004C: jal         0x80083A78
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bssplat_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: addiu       $a1, $zero, 0x50F
    ctx->r5 = ADD32(0, 0X50F);
    // 0x8080005C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800060: jal         0x8009DF18
    // 0x80800064: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DF18(rdram, ctx);
        goto after_4;
    // 0x80800064: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_4:
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080006C: jal         0x8009BA9C
    // 0x80800070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_5;
    // 0x80800070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800078: jal         0x8009B9B0
    // 0x8080007C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x8080007C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80800080: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x80800084: jal         0x8008E944
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_7;
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080008C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800090: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800094: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800098: jr          $ra
    // 0x8080009C: nop

    return;
    // 0x8080009C: nop

;}
RECOMP_FUNC void _chglowbo_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086AD0: syscall     414
    recomp_syscall_handler(rdram, ctx, 0x80086AD0);
    return;
    // 0x80086AD4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chwaspnestgame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B48: syscall     198
    recomp_syscall_handler(rdram, ctx, 0x80085B48);
    return;
    // 0x80085B4C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chtntdetonator_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D20: syscall     231
    recomp_syscall_handler(rdram, ctx, 0x80085D20);
    return;
    // 0x80085D24: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800520_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800520: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800524: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800528: jal         0x80800208
    // 0x8080052C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80800208_bscarry(rdram, ctx);
        goto after_0;
    // 0x8080052C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800530: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800534: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800538: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080053C: jal         0x8008CB3C
    // 0x80800540: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800540: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    after_1:
    // 0x80800544: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800548: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080054C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800550: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800554: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800558: jal         0x8009FFD8
    // 0x8080055C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x8080055C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800560: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(132, 0X7A4) << 16);
    // 0x80800564: lwc1        $f4, 0x7A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(132, 0X7A4));
    // 0x80800568: lui         $a3, 0x3F57
    ctx->r7 = S32(0X3F57 << 16);
    // 0x8080056C: ori         $a3, $a3, 0xA3D
    ctx->r7 = ctx->r7 | 0XA3D;
    // 0x80800570: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800574: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800578: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x8080057C: jal         0x8008C9F0
    // 0x80800580: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_3;
    // 0x80800580: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800584: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800588: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080058C: jr          $ra
    // 0x80800590: nop

    return;
    // 0x80800590: nop

;}
RECOMP_FUNC void func_80802228_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802228: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080222C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802230: jal         0x80106790
    // 0x80802234: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802234: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80802238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080223C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802240: jr          $ra
    // 0x80802244: nop

    return;
    // 0x80802244: nop

;}
RECOMP_FUNC void func_80809938_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809938: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x8080993C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80809940: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80809944: lwc1        $f6, 0x230($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X230);
    // 0x80809948: lwc1        $f10, 0x24C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24C);
    // 0x8080994C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80809950: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80809954: jr          $ra
    // 0x80809958: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80809958: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_800D8648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8648: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D864C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D8650: jal         0x800D7520
    // 0x800D8654: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D7520(rdram, ctx);
        goto after_0;
    // 0x800D8654: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D8658: addiu       $a0, $v0, 0x14
    ctx->r4 = ADD32(ctx->r2, 0X14);
    // 0x800D865C: jal         0x800EE7F8
    // 0x800D8660: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800D8660: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800D8664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D8668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D866C: jr          $ra
    // 0x800D8670: nop

    return;
    // 0x800D8670: nop

;}
RECOMP_FUNC void func_80800000_chegggrenade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80800004: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8080000C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800010: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80800014: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80800018: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8080001C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800020: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800024: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800028: jal         0x80100094
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800030: jal         0x800D8FF8
    // 0x80800034: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800034: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_1:
    // 0x80800038: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X28);
    // 0x8080003C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2116, 0X440) << 16);
    // 0x80800040: lwc1        $f12, 0x30($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80800044: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80800048: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080004C: lui         $a3, 0x3D08
    ctx->r7 = S32(0X3D08 << 16);
    // 0x80800050: ori         $a3, $a3, 0x6595
    ctx->r7 = ctx->r7 | 0X6595;
    // 0x80800054: swc1        $f6, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f6.u32l;
    // 0x80800058: lwc1        $f8, 0x440($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2116, 0X440));
    // 0x8080005C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80800060: jal         0x800F10B4
    // 0x80800064: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800064: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800068: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
    // 0x8080006C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80800070: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800074: jal         0x8008A418
    // 0x80800078: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _suegg_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80800078: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x8080007C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800080: lwc1        $f0, 0x28($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80800084: addiu       $s0, $s3, 0x4
    ctx->r16 = ADD32(ctx->r19, 0X4);
    // 0x80800088: addiu       $s2, $sp, 0x64
    ctx->r18 = ADD32(ctx->r29, 0X64);
    // 0x8080008C: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x80800090: nop

    // 0x80800094: bc1fl       L_808000D8
    if (!c1cs) {
        // 0x80800098: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808000D8;
    }
    goto skip_0;
    // 0x80800098: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8080009C: add.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f22.fl;
L_808000A0:
    // 0x808000A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808000A8: jal         0x800EE7F8
    // 0x808000AC: swc1        $f10, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f10.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808000AC: swc1        $f10, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f10.u32l;
    after_4:
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x808000B8: jal         0x80088A88
    // 0x808000BC: lw          $a2, 0x38($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X38);
    _fxegg_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x808000BC: lw          $a2, 0x38($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X38);
    after_5:
    // 0x808000C0: lwc1        $f0, 0x28($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X28);
    // 0x808000C4: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x808000C8: nop

    // 0x808000CC: bc1tl       L_808000A0
    if (c1cs) {
        // 0x808000D0: add.s       $f10, $f0, $f22
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f22.fl;
            goto L_808000A0;
    }
    goto skip_1;
    // 0x808000D0: add.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f22.fl;
    skip_1:
    // 0x808000D4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808000D8:
    // 0x808000D8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808000DC: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x808000E0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x808000E4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x808000E8: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x808000EC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x808000F0: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x808000F4: jr          $ra
    // 0x808000F8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x808000F8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void bssplitup_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800580: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800588: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080058C: jal         0x8008CAEC
    // 0x80800590: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    baanim_isStopped(rdram, ctx);
        goto after_0;
    // 0x80800590: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800594: beq         $v0, $zero, L_808005A0
    if (ctx->r2 == 0) {
        // 0x80800598: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_808005A0;
    }
    // 0x80800598: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080059C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_808005A0:
    // 0x808005A0: jal         0x8009E5C8
    // 0x808005A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x808005A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808005A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005B0: jr          $ra
    // 0x808005B4: nop

    return;
    // 0x808005B4: nop

;}
RECOMP_FUNC void func_800E40DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E40DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E40E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E40E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E40E8: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x800E40EC: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x800E40F0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800E40F4: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    // 0x800E40F8: jal         0x800CA9D8
    // 0x800E40FC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_800CA9D8(rdram, ctx);
        goto after_0;
    // 0x800E40FC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x800E4100: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800E4104: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800E4108: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800E410C: jal         0x800EFA4C
    // 0x800E4110: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x800E4110: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    after_1:
    // 0x800E4114: jal         0x800A89F8
    // 0x800E4118: nop

    func_800A89F8(rdram, ctx);
        goto after_2;
    // 0x800E4118: nop

    after_2:
    // 0x800E411C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E4120: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800E4124: jal         0x800C4E58
    // 0x800E4128: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_800C4E58(rdram, ctx);
        goto after_3;
    // 0x800E4128: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x800E412C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E4130: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E4134: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E4138: jr          $ra
    // 0x800E413C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800E413C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ncba1p_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800854: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800858: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080085C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800860: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x80800864: jal         0x800EE7F8
    // 0x80800868: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800868: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    after_0:
    // 0x8080086C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800874: jr          $ra
    // 0x80800878: nop

    return;
    // 0x80800878: nop

;}
RECOMP_FUNC void func_8080030C_chdinofamilysick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080030C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800310: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800314: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800318: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080031C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800320: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800324: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800328: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8080032C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800330: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80800334: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x80800338: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x8080033C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80800340: addiu       $a0, $a0, -0x5A88
    ctx->r4 = ADD32(ctx->r4, -0X5A88);
    // 0x80800344: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800348: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8080034C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800350: jal         0x80086D58
    // 0x80800354: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _chbaddiesetup_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800354: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x80800358: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080035C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800360: jr          $ra
    // 0x80800364: nop

    return;
    // 0x80800364: nop

;}
RECOMP_FUNC void func_808001FC_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800200: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800204: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800208: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080020C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800210: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800214: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80800218: jal         0x80100094
    // 0x8080021C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080021C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800220: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800224: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800228: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080022C: slti        $at, $a2, 0x3E
    ctx->r1 = SIGNED(ctx->r6) < 0X3E ? 1 : 0;
    // 0x80800230: bne         $at, $zero, L_80800258
    if (ctx->r1 != 0) {
        // 0x80800234: addiu       $t6, $a2, -0x2E
        ctx->r14 = ADD32(ctx->r6, -0X2E);
            goto L_80800258;
    }
    // 0x80800234: addiu       $t6, $a2, -0x2E
    ctx->r14 = ADD32(ctx->r6, -0X2E);
    // 0x80800238: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x8080023C: beq         $a2, $at, L_8080037C
    if (ctx->r6 == ctx->r1) {
        // 0x80800240: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080037C;
    }
    // 0x80800240: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800244: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800248: beq         $a2, $at, L_808003A8
    if (ctx->r6 == ctx->r1) {
        // 0x8080024C: nop
    
            goto L_808003A8;
    }
    // 0x8080024C: nop

    // 0x80800250: b           L_808003B4
    // 0x80800254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003B4;
    // 0x80800254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800258:
    // 0x80800258: slti        $at, $a2, 0xF
    ctx->r1 = SIGNED(ctx->r6) < 0XF ? 1 : 0;
    // 0x8080025C: bne         $at, $zero, L_80800280
    if (ctx->r1 != 0) {
        // 0x80800260: sltiu       $at, $t6, 0x10
        ctx->r1 = ctx->r14 < 0X10 ? 1 : 0;
            goto L_80800280;
    }
    // 0x80800260: sltiu       $at, $t6, 0x10
    ctx->r1 = ctx->r14 < 0X10 ? 1 : 0;
    // 0x80800264: beq         $at, $zero, L_8080028C
    if (ctx->r1 == 0) {
        // 0x80800268: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8080028C;
    }
    // 0x80800268: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080026C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1008, 0X1BF8) << 16);
    // 0x80800270: addu        $at, $at, $t6
    gpr jr_addend_80800278 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800274: lw          $t6, 0x1BF8($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1008, 0X1BF8));
    // 0x80800278: jr          $t6
    // 0x8080027C: nop

    switch (jr_addend_80800278 >> 2) {
        case 0: goto L_80800294; break;
        case 1: goto L_808002B0; break;
        case 2: goto L_808002CC; break;
        case 3: goto L_8080028C; break;
        case 4: goto L_8080032C; break;
        case 5: goto L_8080028C; break;
        case 6: goto L_8080028C; break;
        case 7: goto L_8080028C; break;
        case 8: goto L_8080028C; break;
        case 9: goto L_8080028C; break;
        case 10: goto L_8080028C; break;
        case 11: goto L_8080028C; break;
        case 12: goto L_8080028C; break;
        case 13: goto L_8080028C; break;
        case 14: goto L_8080028C; break;
        case 15: goto L_808002E8; break;
        default: switch_error(__func__, 0x80800278, 0x80801BF8);
    }
    // 0x8080027C: nop

L_80800280:
    // 0x80800280: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80800284: beq         $a2, $at, L_808002FC
    if (ctx->r6 == ctx->r1) {
        // 0x80800288: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_808002FC;
    }
    // 0x80800288: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
L_8080028C:
    // 0x8080028C: b           L_808003B4
    // 0x80800290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003B4;
    // 0x80800290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800294:
    // 0x80800294: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80800298: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x8080029C: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x808002A0: jal         0x808003C4
    // 0x808002A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_808003C4_chballoonburst(rdram, ctx);
        goto after_1;
    // 0x808002A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x808002A8: b           L_808003B4
    // 0x808002AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003B4;
    // 0x808002AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002B0:
    // 0x808002B0: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x808002B4: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808002B8: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x808002BC: jal         0x80800704
    // 0x808002C0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800704_chballoonburst(rdram, ctx);
        goto after_2;
    // 0x808002C0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x808002C4: b           L_808003B4
    // 0x808002C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003B4;
    // 0x808002C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002CC:
    // 0x808002CC: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x808002D0: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808002D4: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x808002D8: jal         0x8080066C
    // 0x808002DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8080066C_chballoonburst(rdram, ctx);
        goto after_3;
    // 0x808002DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x808002E0: b           L_808003B8
    // 0x808002E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003B8;
    // 0x808002E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002E8:
    // 0x808002E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002EC: jal         0x80800BE8
    // 0x808002F0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800BE8_chballoonburst(rdram, ctx);
        goto after_4;
    // 0x808002F0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x808002F4: b           L_808003B4
    // 0x808002F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003B4;
    // 0x808002F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002FC:
    // 0x808002FC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800300: bne         $t7, $at, L_80800324
    if (ctx->r15 != ctx->r1) {
        // 0x80800304: nop
    
            goto L_80800324;
    }
    // 0x80800304: nop

    // 0x80800308: lw          $a0, 0x3C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X3C);
    // 0x8080030C: beq         $a0, $zero, L_80800324
    if (ctx->r4 == 0) {
        // 0x80800310: nop
    
            goto L_80800324;
    }
    // 0x80800310: nop

    // 0x80800314: jal         0x80106790
    // 0x80800318: nop

    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80800318: nop

    after_5:
    // 0x8080031C: jal         0x80085738
    // 0x80800320: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    _capod_entrypoint_19(rdram, ctx);
        goto after_6;
    // 0x80800320: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    after_6:
L_80800324:
    // 0x80800324: b           L_808003B4
    // 0x80800328: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808003B4;
    // 0x80800328: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8080032C:
    // 0x8080032C: jal         0x800D395C
    // 0x80800330: nop

    func_800D395C(rdram, ctx);
        goto after_7;
    // 0x80800330: nop

    after_7:
    // 0x80800334: beq         $v0, $zero, L_80800344
    if (ctx->r2 == 0) {
        // 0x80800338: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_80800344;
    }
    // 0x80800338: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8080033C: b           L_80800348
    // 0x80800340: addiu       $a1, $zero, 0x1118
    ctx->r5 = ADD32(0, 0X1118);
        goto L_80800348;
    // 0x80800340: addiu       $a1, $zero, 0x1118
    ctx->r5 = ADD32(0, 0X1118);
L_80800344:
    // 0x80800344: addiu       $a1, $zero, 0x10BE
    ctx->r5 = ADD32(0, 0X10BE);
L_80800348:
    // 0x80800348: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x8080034C: addiu       $t9, $zero, 0x22
    ctx->r25 = ADD32(0, 0X22);
    // 0x80800350: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800354: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x80800358: jal         0x8008A208
    // 0x8080035C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x8080035C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x80800360: jal         0x800F54E4
    // 0x80800364: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x80800364: nop

    after_9:
    // 0x80800368: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080036C: jal         0x800F82D4
    // 0x80800370: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_10;
    // 0x80800370: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80800374: b           L_808003B4
    // 0x80800378: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003B4;
    // 0x80800378: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080037C:
    // 0x8080037C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800380: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800384: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800388: andi        $t0, $a2, 0xFFFF
    ctx->r8 = ctx->r6 & 0XFFFF;
    // 0x8080038C: and         $t1, $a3, $at
    ctx->r9 = ctx->r7 & ctx->r1;
    // 0x80800390: srl         $a3, $t1, 16
    ctx->r7 = S32(U32(ctx->r9) >> 16);
    // 0x80800394: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x80800398: jal         0x8008A2B8
    // 0x8080039C: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    _susubgame_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x8080039C: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    after_11:
    // 0x808003A0: b           L_808003B8
    // 0x808003A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003B8;
    // 0x808003A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003A8:
    // 0x808003A8: jal         0x80800790
    // 0x808003AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800790_chballoonburst(rdram, ctx);
        goto after_12;
    // 0x808003AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_12:
    // 0x808003B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003B4:
    // 0x808003B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003B8:
    // 0x808003B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003BC: jr          $ra
    // 0x808003C0: nop

    return;
    // 0x808003C0: nop

;}
RECOMP_FUNC void _sucoasterplayer_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A310: syscall     835
    recomp_syscall_handler(rdram, ctx, 0x8008A310);
    return;
    // 0x8008A314: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bsjig_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002BC: jal         0x800A32F8
    // 0x808002C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A32F8(rdram, ctx);
        goto after_0;
    // 0x808002C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002C4: beq         $v0, $zero, L_808002EC
    if (ctx->r2 == 0) {
        // 0x808002C8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808002EC;
    }
    // 0x808002C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002CC: jal         0x80106790
    // 0x808002D0: nop

    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808002D0: nop

    after_1:
    // 0x808002D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002D8: jal         0x800858B8
    // 0x808002DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _chjigsawdance_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808002DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x808002E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002E4: jal         0x800A34D8
    // 0x808002E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A34D8(rdram, ctx);
        goto after_3;
    // 0x808002E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_808002EC:
    // 0x808002EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002F4: jr          $ra
    // 0x808002F8: nop

    return;
    // 0x808002F8: nop

;}
RECOMP_FUNC void gcgoto_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800704: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80800708: jr          $ra
    // 0x8080070C: lbu         $v0, 0x75C0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X75C0);
    return;
    // 0x8080070C: lbu         $v0, 0x75C0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X75C0);
;}
RECOMP_FUNC void func_80800AF8_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B00: jal         0x80800A04
    // 0x80800B04: nop

    func_80800A04_chfactoryworkerdirty(rdram, ctx);
        goto after_0;
    // 0x80800B04: nop

    after_0:
    // 0x80800B08: jal         0x800DA544
    // 0x80800B0C: addiu       $a0, $v0, 0x42D
    ctx->r4 = ADD32(ctx->r2, 0X42D);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800B0C: addiu       $a0, $v0, 0x42D
    ctx->r4 = ADD32(ctx->r2, 0X42D);
    after_1:
    // 0x80800B10: addiu       $a0, $zero, 0x42D
    ctx->r4 = ADD32(0, 0X42D);
    // 0x80800B14: jal         0x800DA564
    // 0x80800B18: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800DA564(rdram, ctx);
        goto after_2;
    // 0x80800B18: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x80800B1C: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80800B20: bnel        $v0, $at, L_80800B34
    if (ctx->r2 != ctx->r1) {
        // 0x80800B24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800B34;
    }
    goto skip_0;
    // 0x80800B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800B28: jal         0x800DA544
    // 0x80800B2C: addiu       $a0, $zero, 0x433
    ctx->r4 = ADD32(0, 0X433);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800B2C: addiu       $a0, $zero, 0x433
    ctx->r4 = ADD32(0, 0X433);
    after_3:
    // 0x80800B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B34:
    // 0x80800B34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B38: jr          $ra
    // 0x80800B3C: nop

    return;
    // 0x80800B3C: nop

;}
RECOMP_FUNC void func_800CB890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB894: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800CB898: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB89C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800CB8A0: lw          $a0, -0x50A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X50A0);
    // 0x800CB8A4: jal         0x800B42A0
    // 0x800CB8A8: addiu       $a1, $a2, 0x18
    ctx->r5 = ADD32(ctx->r6, 0X18);
    func_800B42A0(rdram, ctx);
        goto after_0;
    // 0x800CB8A8: addiu       $a1, $a2, 0x18
    ctx->r5 = ADD32(ctx->r6, 0X18);
    after_0:
    // 0x800CB8AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB8B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB8B4: jr          $ra
    // 0x800CB8B8: nop

    return;
    // 0x800CB8B8: nop

;}
RECOMP_FUNC void func_80802FBC_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802FBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802FC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802FC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802FC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802FCC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80802FD0: jal         0x80106790
    // 0x80802FD4: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802FD4: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80802FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802FDC: jal         0x80802F14
    // 0x80802FE0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80802F14_chstoneballcontrol(rdram, ctx);
        goto after_1;
    // 0x80802FE0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802FE4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80802FE8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80802FEC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80802FF0: lw          $v0, 0x24($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X24);
    // 0x80802FF4: addiu       $at, $zero, 0x253
    ctx->r1 = ADD32(0, 0X253);
    // 0x80802FF8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80802FFC: srl         $t7, $v0, 22
    ctx->r15 = S32(U32(ctx->r2) >> 22);
    // 0x80803000: beq         $t7, $at, L_80803044
    if (ctx->r15 == ctx->r1) {
        // 0x80803004: sll         $t1, $t0, 2
        ctx->r9 = S32(ctx->r8 << 2);
            goto L_80803044;
    }
    // 0x80803004: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80803008: addiu       $at, $zero, 0x254
    ctx->r1 = ADD32(0, 0X254);
    // 0x8080300C: beq         $t7, $at, L_80803060
    if (ctx->r15 == ctx->r1) {
        // 0x80803010: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80803060;
    }
    // 0x80803010: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80803014: addiu       $at, $zero, 0x267
    ctx->r1 = ADD32(0, 0X267);
    // 0x80803018: bne         $t7, $at, L_8080307C
    if (ctx->r15 != ctx->r1) {
        // 0x8080301C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8080307C;
    }
    // 0x8080301C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80803020: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80803024: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1608, 0X52A0) << 16);
    // 0x80803028: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080302C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80803030: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x80803034: jal         0x80089AE0
    // 0x80803038: lw          $a1, 0x52A0($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(1608, 0X52A0));
    _sukickball_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80803038: lw          $a1, 0x52A0($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(1608, 0X52A0));
    after_2:
    // 0x8080303C: b           L_80803080
    // 0x80803040: lbu         $t4, 0x72($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X72);
        goto L_80803080;
    // 0x80803040: lbu         $t4, 0x72($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X72);
L_80803044:
    // 0x80803044: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1608, 0X52A0) << 16);
    // 0x80803048: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x8080304C: lw          $a1, 0x52A0($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(1608, 0X52A0));
    // 0x80803050: jal         0x80089AE0
    // 0x80803054: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _sukickball_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80803054: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x80803058: b           L_80803080
    // 0x8080305C: lbu         $t4, 0x72($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X72);
        goto L_80803080;
    // 0x8080305C: lbu         $t4, 0x72($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X72);
L_80803060:
    // 0x80803060: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80803064: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1608, 0X52A0) << 16);
    // 0x80803068: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8080306C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80803070: addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
    // 0x80803074: jal         0x80089AE0
    // 0x80803078: lw          $a1, 0x52A0($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(1608, 0X52A0));
    _sukickball_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80803078: lw          $a1, 0x52A0($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(1608, 0X52A0));
    after_4:
L_8080307C:
    // 0x8080307C: lbu         $t4, 0x72($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X72);
L_80803080:
    // 0x80803080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803084: andi        $t5, $t4, 0xFF03
    ctx->r13 = ctx->r12 & 0XFF03;
    // 0x80803088: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x8080308C: jal         0x80089CA8
    // 0x80803090: sb          $t6, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r14;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80803090: sb          $t6, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r14;
    after_5:
    // 0x80803094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803098: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080309C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808030A0: jr          $ra
    // 0x808030A4: nop

    return;
    // 0x808030A4: nop

;}
RECOMP_FUNC void _chgameselect_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085BE0: syscall     205
    recomp_syscall_handler(rdram, ctx, 0x80085BE0);
    return;
    // 0x80085BE4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800BE0_cadbfunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BE8: jal         0x800A587C
    // 0x80800BEC: nop

    func_800A587C(rdram, ctx);
        goto after_0;
    // 0x80800BEC: nop

    after_0:
    // 0x80800BF0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800BF4: bnel        $v0, $at, L_80800C10
    if (ctx->r2 != ctx->r1) {
        // 0x80800BF8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800C10;
    }
    goto skip_0;
    // 0x80800BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800BFC: jal         0x800A586C
    // 0x80800C00: nop

    func_800A586C(rdram, ctx);
        goto after_1;
    // 0x80800C00: nop

    after_1:
    // 0x80800C04: b           L_80800C10
    // 0x80800C08: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
        goto L_80800C10;
    // 0x80800C08: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80800C0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C10:
    // 0x80800C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C18: jr          $ra
    // 0x80800C1C: nop

    return;
    // 0x80800C1C: nop

;}
RECOMP_FUNC void func_800F8830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8838: jal         0x8009E7C8
    // 0x800F883C: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    func_8009E7C8(rdram, ctx);
        goto after_0;
    // 0x800F883C: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    after_0:
    // 0x800F8840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8848: jr          $ra
    // 0x800F884C: nop

    return;
    // 0x800F884C: nop

;}
RECOMP_FUNC void chtoothyfish_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DF8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1776, 0X1870) << 16);
    // 0x80800DFC: jr          $ra
    // 0x80800E00: addiu       $v0, $v0, 0x1870
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1776, 0X1870));
    return;
    // 0x80800E00: addiu       $v0, $v0, 0x1870
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1776, 0X1870));
;}
RECOMP_FUNC void func_80802188_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802188: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080218C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802190: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802194: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80802198: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080219C: jal         0x80100094
    // 0x808021A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808021A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808021A4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808021A8: jal         0x80101970
    // 0x808021AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101970(rdram, ctx);
        goto after_1;
    // 0x808021AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808021B0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808021B4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808021B8: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x808021BC: lw          $a3, 0x4C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4C);
    // 0x808021C0: jal         0x800EFA4C
    // 0x808021C4: lw          $a2, 0x8($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X8);
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x808021C4: lw          $a2, 0x8($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X8);
    after_2:
    // 0x808021C8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x808021CC: addiu       $a0, $a0, 0x15D0
    ctx->r4 = ADD32(ctx->r4, 0X15D0);
    // 0x808021D0: jal         0x800DF47C
    // 0x808021D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800DF47C(rdram, ctx);
        goto after_3;
    // 0x808021D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x808021D8: jal         0x801018D8
    // 0x808021DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801018D8(rdram, ctx);
        goto after_4;
    // 0x808021DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808021E0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808021E4: jal         0x8010347C
    // 0x808021E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8010347C(rdram, ctx);
        goto after_5;
    // 0x808021E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x808021EC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x808021F0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x808021F4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808021F8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808021FC: jal         0x800DE448
    // 0x80802200: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_800DE448(rdram, ctx);
        goto after_6;
    // 0x80802200: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80802204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802208: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080220C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80802210: jr          $ra
    // 0x80802214: nop

    return;
    // 0x80802214: nop

;}
RECOMP_FUNC void func_800F5924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5924: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F592C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5934: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5938: jal         0x800A3360
    // 0x800F593C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A3360(rdram, ctx);
        goto after_0;
    // 0x800F593C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5948: jr          $ra
    // 0x800F594C: nop

    return;
    // 0x800F594C: nop

;}
RECOMP_FUNC void baduo_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002BC: lw          $t6, 0x58($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X58);
    // 0x808002C0: jr          $ra
    // 0x808002C4: sb          $a1, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r5;
    return;
    // 0x808002C4: sb          $a1, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void bstaxi_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080023C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800240: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800244: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800248: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080024C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80800250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800254: jal         0x80098140
    // 0x80800258: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bainput_enable(rdram, ctx);
        goto after_0;
    // 0x80800258: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800260: jal         0x8009D3A8
    // 0x80800264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_1;
    // 0x80800264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800268: lui         $a1, 0x3C83
    ctx->r5 = S32(0X3C83 << 16);
    // 0x8080026C: ori         $a1, $a1, 0xE426
    ctx->r5 = ctx->r5 | 0XE426;
    // 0x80800270: jal         0x8008CB10
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800278: beq         $v0, $zero, L_80800294
    if (ctx->r2 == 0) {
        // 0x8080027C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800294;
    }
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: jal         0x80084538
    // 0x80800284: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _babackpack_set_state(rdram, ctx);
        goto after_3;
    // 0x80800284: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: jal         0x800A0CD0
    // 0x80800290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CD0(rdram, ctx);
        goto after_4;
    // 0x80800290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_80800294:
    // 0x80800294: lui         $a1, 0x3EA8
    ctx->r5 = S32(0X3EA8 << 16);
    // 0x80800298: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x8080029C: jal         0x8008CB10
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_5;
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808002A4: beq         $v0, $zero, L_808002BC
    if (ctx->r2 == 0) {
        // 0x808002A8: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(392, 0X20D0) << 16);
            goto L_808002BC;
    }
    // 0x808002A8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(392, 0X20D0) << 16);
    // 0x808002AC: addiu       $a2, $a2, 0x20D0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(392, 0X20D0));
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B4: jal         0x8009D454
    // 0x808002B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D454(rdram, ctx);
        goto after_6;
    // 0x808002B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_808002BC:
    // 0x808002BC: lui         $a1, 0x3EDE
    ctx->r5 = S32(0X3EDE << 16);
    // 0x808002C0: ori         $a1, $a1, 0xB852
    ctx->r5 = ctx->r5 | 0XB852;
    // 0x808002C4: jal         0x8008CB10
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_7;
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808002CC: beq         $v0, $zero, L_808002E4
    if (ctx->r2 == 0) {
        // 0x808002D0: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(392, 0X20F0) << 16);
            goto L_808002E4;
    }
    // 0x808002D0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(392, 0X20F0) << 16);
    // 0x808002D4: addiu       $a2, $a2, 0x20F0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(392, 0X20F0));
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002DC: jal         0x8009D454
    // 0x808002E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D454(rdram, ctx);
        goto after_8;
    // 0x808002E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
L_808002E4:
    // 0x808002E4: lui         $a1, 0x3F0B
    ctx->r5 = S32(0X3F0B << 16);
    // 0x808002E8: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x808002EC: jal         0x8008CB10
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_9;
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808002F4: beq         $v0, $zero, L_8080030C
    if (ctx->r2 == 0) {
        // 0x808002F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080030C;
    }
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002FC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(392, 0X2110) << 16);
    // 0x80800300: addiu       $a2, $a2, 0x2110
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(392, 0X2110));
    // 0x80800304: jal         0x8009D454
    // 0x80800308: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D454(rdram, ctx);
        goto after_10;
    // 0x80800308: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
L_8080030C:
    // 0x8080030C: lui         $a1, 0x3F10
    ctx->r5 = S32(0X3F10 << 16);
    // 0x80800310: ori         $a1, $a1, 0xF27C
    ctx->r5 = ctx->r5 | 0XF27C;
    // 0x80800314: jal         0x8008CB10
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_11;
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080031C: beq         $v0, $zero, L_80800378
    if (ctx->r2 == 0) {
        // 0x80800320: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800378;
    }
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800324: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800328: jal         0x80084518
    // 0x8080032C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _babackpack_entrypoint_6(rdram, ctx);
        goto after_12;
    // 0x8080032C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80800330: jal         0x80084768
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bapackctrl_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800338: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800340: jal         0x80084780
    // 0x80800344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bapackctrl_entrypoint_4(rdram, ctx);
        goto after_14;
    // 0x80800344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80800348: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x8080034C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800354: addiu       $a1, $zero, 0x5C2
    ctx->r5 = ADD32(0, 0X5C2);
    // 0x80800358: jal         0x8009DB04
    // 0x8080035C: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DB04(rdram, ctx);
        goto after_15;
    // 0x8080035C: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_15:
    // 0x80800360: jal         0x8009C984
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_16;
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800368: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080036C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800370: jal         0x800CB598
    // 0x80800374: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800CB598(rdram, ctx);
        goto after_17;
    // 0x80800374: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_17:
L_80800378:
    // 0x80800378: lui         $a1, 0x3F50
    ctx->r5 = S32(0X3F50 << 16);
    // 0x8080037C: ori         $a1, $a1, 0xB780
    ctx->r5 = ctx->r5 | 0XB780;
    // 0x80800380: jal         0x8008CB10
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_18;
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800388: beq         $v0, $zero, L_808003A4
    if (ctx->r2 == 0) {
        // 0x8080038C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003A4;
    }
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: jal         0x80084538
    // 0x80800394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babackpack_set_state(rdram, ctx);
        goto after_19;
    // 0x80800394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080039C: jal         0x800A0CD0
    // 0x808003A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CD0(rdram, ctx);
        goto after_20;
    // 0x808003A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
L_808003A4:
    // 0x808003A4: jal         0x8008CAEC
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_21;
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808003AC: beq         $v0, $zero, L_808003B8
    if (ctx->r2 == 0) {
        // 0x808003B0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808003B8;
    }
    // 0x808003B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808003B4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_808003B8:
    // 0x808003B8: jal         0x8008CAC8
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_22;
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808003C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(392, 0X1DE0) << 16);
    // 0x808003C4: lwc1        $f4, 0x1DE0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(392, 0X1DE0));
    // 0x808003C8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808003CC: nop

    // 0x808003D0: bc1fl       L_808003F0
    if (!c1cs) {
        // 0x808003D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F0;
    }
    goto skip_0;
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808003D8: jal         0x8009EF10
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_23;
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808003E0: blez        $v0, L_808003EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808003E4: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_808003EC;
    }
    // 0x808003E4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808003E8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_808003EC:
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003F0:
    // 0x808003F0: jal         0x8009E5C8
    // 0x808003F4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_24;
    // 0x808003F4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_24:
    // 0x808003F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800400: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800404: jr          $ra
    // 0x80800408: nop

    return;
    // 0x80800408: nop

;}
RECOMP_FUNC void _bakaztorpedo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D78: syscall     136
    recomp_syscall_handler(rdram, ctx, 0x80084D78);
    return;
    // 0x80084D7C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _suspline_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E10: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089E10);
    return;
    // 0x80089E14: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_808000B4_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000BC: jal         0x80100094
    // 0x808000C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000C4: lbu         $v1, 0xF($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XF);
    // 0x808000C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000CC: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    // 0x808000D0: beq         $v1, $zero, L_80800104
    if (ctx->r3 == 0) {
        // 0x808000D4: nop
    
            goto L_80800104;
    }
    // 0x808000D4: nop

    // 0x808000D8: beq         $v1, $at, L_808000F4
    if (ctx->r3 == ctx->r1) {
        // 0x808000DC: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_808000F4;
    }
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000E4: beq         $v1, $at, L_80800104
    if (ctx->r3 == ctx->r1) {
        // 0x808000E8: nop
    
            goto L_80800104;
    }
    // 0x808000E8: nop

    // 0x808000EC: b           L_80800110
    // 0x808000F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800110;
    // 0x808000F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000F4:
    // 0x808000F4: jal         0x80087A58
    // 0x808000F8: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808000F8: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    after_1:
    // 0x808000FC: b           L_80800110
    // 0x80800100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800110;
    // 0x80800100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800104:
    // 0x80800104: jal         0x80087A58
    // 0x80800108: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800108: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_2:
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
RECOMP_FUNC void _batimer_decrement(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800852F0: syscall     157
    recomp_syscall_handler(rdram, ctx, 0x800852F0);
    return;
    // 0x800852F4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _baeggcursor_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084AC8: syscall     128
    recomp_syscall_handler(rdram, ctx, 0x80084AC8);
    return;
    // 0x80084ACC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808000A8_suchase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000AC: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x808000B0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808000B4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808000B8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808000BC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808000C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3214, 0X1C0) << 16);
    // 0x808000C4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x808000C8: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x808000CC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x808000D0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808000D4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808000D8: lwc1        $f20, 0x1C0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3214, 0X1C0));
    // 0x808000DC: jal         0x800BE444
    // 0x808000E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800BE444(rdram, ctx);
        goto after_0;
    // 0x808000E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808000E4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x808000E8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808000EC: beq         $t6, $zero, L_80800198
    if (ctx->r14 == 0) {
        // 0x808000F0: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80800198;
    }
    // 0x808000F0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_808000F4:
    // 0x808000F4: jal         0x800E9E88
    // 0x808000F8: nop

    func_800E9E88(rdram, ctx);
        goto after_1;
    // 0x808000F8: nop

    after_1:
    // 0x808000FC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800100: jal         0x800E9EB4
    // 0x80800104: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_2;
    // 0x80800104: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    after_2:
    // 0x80800108: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x8080010C: beq         $at, $zero, L_80800188
    if (ctx->r1 == 0) {
        // 0x80800110: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80800188;
    }
    // 0x80800110: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800114: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
L_80800118:
    // 0x80800118: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8080011C: beql        $t8, $zero, L_8080017C
    if (ctx->r24 == 0) {
        // 0x80800120: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8080017C;
    }
    goto skip_0;
    // 0x80800120: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_0:
    // 0x80800124: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80800128: lhu         $t9, 0x18($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X18);
    // 0x8080012C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80800130: beql        $t0, $zero, L_8080017C
    if (ctx->r8 == 0) {
        // 0x80800134: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8080017C;
    }
    goto skip_1;
    // 0x80800134: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_1:
    // 0x80800138: jal         0x80106790
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800140: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80800144: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80800148: bltz        $t2, L_80800178
    if (SIGNED(ctx->r10) < 0) {
        // 0x8080014C: sll         $t4, $v1, 1
        ctx->r12 = S32(ctx->r3 << 1);
            goto L_80800178;
    }
    // 0x8080014C: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x80800150: bgez        $t4, L_80800178
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800154: addiu       $a0, $v0, 0x4
        ctx->r4 = ADD32(ctx->r2, 0X4);
            goto L_80800178;
    }
    // 0x80800154: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80800158: jal         0x800EEB40
    // 0x8080015C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EEB40(rdram, ctx);
        goto after_4;
    // 0x8080015C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x80800160: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80800164: nop

    // 0x80800168: bc1fl       L_8080017C
    if (!c1cs) {
        // 0x8080016C: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8080017C;
    }
    goto skip_2;
    // 0x8080016C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_2:
    // 0x80800170: sw          $s0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r16;
    // 0x80800174: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80800178:
    // 0x80800178: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_8080017C:
    // 0x8080017C: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x80800180: bnel        $at, $zero, L_80800118
    if (ctx->r1 != 0) {
        // 0x80800184: lw          $t7, 0x8($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X8);
            goto L_80800118;
    }
    goto skip_3;
    // 0x80800184: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    skip_3:
L_80800188:
    // 0x80800188: lw          $a0, 0x4($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X4);
    // 0x8080018C: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80800190: bne         $a0, $zero, L_808000F4
    if (ctx->r4 != 0) {
        // 0x80800194: nop
    
            goto L_808000F4;
    }
    // 0x80800194: nop

L_80800198:
    // 0x80800198: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080019C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808001A0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808001A4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808001A8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808001AC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x808001B0: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x808001B4: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x808001B8: jr          $ra
    // 0x808001BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808001BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void gcnewoption_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808013F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013FC: beq         $a3, $at, L_80801414
    if (ctx->r7 == ctx->r1) {
        // 0x80801400: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80801414;
    }
    // 0x80801400: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801404: lw          $t9, 0x248($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X248);
    // 0x80801408: lw          $a0, 0x24C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X24C);
    // 0x8080140C: jalr        $t9
    // 0x80801410: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80801410: nop

    after_0:
L_80801414:
    // 0x80801414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080141C: jr          $ra
    // 0x80801420: nop

    return;
    // 0x80801420: nop

;}
RECOMP_FUNC void func_80800000_chchuffyglow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800004: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1772, 0X550) << 16);
    // 0x80800008: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8080000C: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80800010: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80800014: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800018: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8080001C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800020: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800024: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800028: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080002C: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80800030: addiu       $t7, $t7, 0x550
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1772, 0X550));
    // 0x80800034: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800038: addiu       $t6, $sp, 0x7C
    ctx->r14 = ADD32(ctx->r29, 0X7C);
    // 0x8080003C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80800040: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800044: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800048: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1772, 0X55C) << 16);
    // 0x8080004C: addiu       $t2, $t2, 0x55C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1772, 0X55C));
    // 0x80800050: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80800054: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80800058: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8080005C: addiu       $t1, $sp, 0x70
    ctx->r9 = ADD32(ctx->r29, 0X70);
    // 0x80800060: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80800064: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80800068: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x8080006C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80800070: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80800074: jal         0x80104248
    // 0x80800078: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80800078: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    after_0:
    // 0x8080007C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800080: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800084: jal         0x80100094
    // 0x80800088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080008C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800090: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800094: jal         0x80102780
    // 0x80800098: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    func_80102780(rdram, ctx);
        goto after_2;
    // 0x80800098: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    after_2:
    // 0x8080009C: jal         0x8008B304
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B304(rdram, ctx);
        goto after_3;
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000A4: jal         0x8008B4D4
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B4D4(rdram, ctx);
        goto after_4;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000AC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808000B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808000B8: jal         0x800DFFA0
    // 0x808000BC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800DFFA0(rdram, ctx);
        goto after_5;
    // 0x808000BC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_5:
    // 0x808000C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808000C4: addiu       $s1, $s3, 0xC
    ctx->r17 = ADD32(ctx->r19, 0XC);
    // 0x808000C8: addiu       $s2, $s3, 0x48
    ctx->r18 = ADD32(ctx->r19, 0X48);
    // 0x808000CC: addiu       $s6, $zero, 0x5
    ctx->r22 = ADD32(0, 0X5);
    // 0x808000D0: addiu       $s4, $sp, 0x60
    ctx->r20 = ADD32(ctx->r29, 0X60);
L_808000D4:
    // 0x808000D4: addiu       $s3, $s0, 0x2A
    ctx->r19 = ADD32(ctx->r16, 0X2A);
    // 0x808000D8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808000DC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808000E0: jal         0x800DFFA0
    // 0x808000E4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800DFFA0(rdram, ctx);
        goto after_6;
    // 0x808000E4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_6:
    // 0x808000E8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808000EC: jal         0x800D93A0
    // 0x808000F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800D93A0(rdram, ctx);
        goto after_7;
    // 0x808000F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x808000F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808000F8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808000FC: jal         0x800DFF2C
    // 0x80800100: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800DFF2C(rdram, ctx);
        goto after_8;
    // 0x80800100: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_8:
    // 0x80800104: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800108: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x8080010C: bne         $s0, $s6, L_808000D4
    if (ctx->r16 != ctx->r22) {
        // 0x80800110: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_808000D4;
    }
    // 0x80800110: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80800114: jal         0x800DF830
    // 0x80800118: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_9;
    // 0x80800118: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_9:
    // 0x8080011C: jal         0x80089C90
    // 0x80800120: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x80800120: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_10:
    // 0x80800124: jal         0x800DF410
    // 0x80800128: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF410(rdram, ctx);
        goto after_11;
    // 0x80800128: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x8080012C: jal         0x800DF41C
    // 0x80800130: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800DF41C(rdram, ctx);
        goto after_12;
    // 0x80800130: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_12:
    // 0x80800134: jal         0x8010347C
    // 0x80800138: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    func_8010347C(rdram, ctx);
        goto after_13;
    // 0x80800138: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    after_13:
    // 0x8080013C: lw          $a2, 0x38($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X38);
    // 0x80800140: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80800144: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x80800148: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8080014C: jal         0x800DE448
    // 0x80800150: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800DE448(rdram, ctx);
        goto after_14;
    // 0x80800150: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x80800154: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800158: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080015C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800160: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800164: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800168: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8080016C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800170: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80800174: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80800178: jr          $ra
    // 0x8080017C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8080017C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80800090_chdinofamilysmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80800094: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800098: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8080009C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808000A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000A4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000A8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808000AC: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x808000B0: beq         $at, $zero, L_808008A0
    if (ctx->r1 == 0) {
        // 0x808000B4: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808008A0;
    }
    // 0x808000B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808000B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2404, 0XE30) << 16);
    // 0x808000BC: addu        $at, $at, $t8
    gpr jr_addend_808000C4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808000C0: lw          $t8, 0xE30($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2404, 0XE30));
    // 0x808000C4: jr          $t8
    // 0x808000C8: nop

    switch (jr_addend_808000C4 >> 2) {
        case 0: goto L_808000CC; break;
        case 1: goto L_8080014C; break;
        case 2: goto L_80800174; break;
        case 3: goto L_80800204; break;
        case 4: goto L_808002A4; break;
        case 5: goto L_8080036C; break;
        case 6: goto L_80800674; break;
        case 7: goto L_80800804; break;
        case 8: goto L_80800818; break;
        case 9: goto L_80800898; break;
        default: switch_error(__func__, 0x808000C4, 0x80800E30);
    }
    // 0x808000C8: nop

L_808000CC:
    // 0x808000CC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808000D0: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x808000D4: addiu       $a1, $zero, 0x258
    ctx->r5 = ADD32(0, 0X258);
    // 0x808000D8: jal         0x8008A1D0
    // 0x808000DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiedialog_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808000DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808000E0: beq         $v0, $zero, L_80800100
    if (ctx->r2 == 0) {
        // 0x808000E4: addiu       $a1, $zero, 0x17CB
        ctx->r5 = ADD32(0, 0X17CB);
            goto L_80800100;
    }
    // 0x808000E4: addiu       $a1, $zero, 0x17CB
    ctx->r5 = ADD32(0, 0X17CB);
    // 0x808000E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808000EC: addiu       $t9, $zero, 0x39
    ctx->r25 = ADD32(0, 0X39);
    // 0x808000F0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808000F4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808000F8: jal         0x8008A208
    // 0x808000FC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808000FC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_1:
L_80800100:
    // 0x80800100: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
    // 0x80800104: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800108: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080010C: lui         $at, 0x4333
    ctx->r1 = S32(0X4333 << 16);
    // 0x80800110: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800114: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800118: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x8080011C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800120: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800124: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800128: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8080012C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800130: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800134: jal         0x80089F20
    // 0x80800138: nop

    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800138: nop

    after_2:
    // 0x8080013C: jal         0x80087738
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdinofamilyfx_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800144: b           L_808008A4
    // 0x80800148: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808008A4;
    // 0x80800148: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080014C:
    // 0x8080014C: jal         0x800DA298
    // 0x80800150: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800150: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_4:
    // 0x80800154: beq         $v0, $zero, L_80800164
    if (ctx->r2 == 0) {
        // 0x80800158: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800164;
    }
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x808008B4
    // 0x80800160: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808008B4_chdinofamilysmall(rdram, ctx);
        goto after_5;
    // 0x80800160: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
L_80800164:
    // 0x80800164: jal         0x80087738
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdinofamilyfx_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080016C: b           L_808008A4
    // 0x80800170: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808008A4;
    // 0x80800170: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800174:
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: jal         0x80103DFC
    // 0x8080017C: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    func_80103DFC(rdram, ctx);
        goto after_7;
    // 0x8080017C: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    after_7:
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: jal         0x80100094
    // 0x80800188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_8;
    // 0x80800188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8080018C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800190: jal         0x80103EAC
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_9;
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800198: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080019C: addiu       $t1, $sp, 0x84
    ctx->r9 = ADD32(ctx->r29, 0X84);
    // 0x808001A0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808001A4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808001A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001AC: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x808001B0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808001B4: jal         0x80089878
    // 0x808001B8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_10;
    // 0x808001B8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_10:
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C0: jal         0x80100094
    // 0x808001C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x808001C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808001C8: jal         0x800898B0
    // 0x808001CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_12;
    // 0x808001CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D4: jal         0x80100094
    // 0x808001D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_13;
    // 0x808001D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808001DC: jal         0x80089918
    // 0x808001E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_14;
    // 0x808001E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x808001E4: beq         $v0, $zero, L_808001F4
    if (ctx->r2 == 0) {
        // 0x808001E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F4;
    }
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001EC: jal         0x808008B4
    // 0x808001F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808008B4_chdinofamilysmall(rdram, ctx);
        goto after_15;
    // 0x808001F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_15:
L_808001F4:
    // 0x808001F4: jal         0x80087738
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdinofamilyfx_entrypoint_0(rdram, ctx);
        goto after_16;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808001FC: b           L_808008A4
    // 0x80800200: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808008A4;
    // 0x80800200: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800204:
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: jal         0x80103DFC
    // 0x8080020C: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    func_80103DFC(rdram, ctx);
        goto after_17;
    // 0x8080020C: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_17:
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800214: jal         0x80100094
    // 0x80800218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_18;
    // 0x80800218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x8080021C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800220: jal         0x80103EAC
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_19;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800228: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080022C: addiu       $t2, $sp, 0x78
    ctx->r10 = ADD32(ctx->r29, 0X78);
    // 0x80800230: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800234: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800238: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080023C: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x80800240: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800244: jal         0x80089878
    // 0x80800248: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_20;
    // 0x80800248: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_20:
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800250: jal         0x80100094
    // 0x80800254: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_21;
    // 0x80800254: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x80800258: jal         0x800898B0
    // 0x8080025C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_22;
    // 0x8080025C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_22:
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: jal         0x80100094
    // 0x80800268: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_23;
    // 0x80800268: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x8080026C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800270: jal         0x80089868
    // 0x80800274: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _sumumbofx_entrypoint_5(rdram, ctx);
        goto after_24;
    // 0x80800274: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_24:
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: jal         0x80100094
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_25;
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x80800284: jal         0x80089918
    // 0x80800288: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_26;
    // 0x80800288: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_26:
    // 0x8080028C: beq         $v0, $zero, L_808008A0
    if (ctx->r2 == 0) {
        // 0x80800290: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008A0;
    }
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: jal         0x808008B4
    // 0x80800298: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808008B4_chdinofamilysmall(rdram, ctx);
        goto after_27;
    // 0x80800298: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_27:
    // 0x8080029C: b           L_808008A4
    // 0x808002A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808008A4;
    // 0x808002A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808002A4:
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: jal         0x80103DFC
    // 0x808002AC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_80103DFC(rdram, ctx);
        goto after_28;
    // 0x808002AC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_28:
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B4: jal         0x80100094
    // 0x808002B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_29;
    // 0x808002B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x808002BC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x808002C0: jal         0x80103EAC
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_30;
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x808002C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002CC: addiu       $t3, $sp, 0x6C
    ctx->r11 = ADD32(ctx->r29, 0X6C);
    // 0x808002D0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808002D4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808002D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808002DC: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x808002E0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808002E4: jal         0x80089878
    // 0x808002E8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_31;
    // 0x808002E8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_31:
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F0: jal         0x80100094
    // 0x808002F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_32;
    // 0x808002F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x808002F8: jal         0x800898B0
    // 0x808002FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_33;
    // 0x808002FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_33:
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800304: jal         0x80100094
    // 0x80800308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_34;
    // 0x80800308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_34:
    // 0x8080030C: jal         0x80089910
    // 0x80800310: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_26(rdram, ctx);
        goto after_35;
    // 0x80800310: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_35:
    // 0x80800314: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800318: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080031C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800320: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800324: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800328: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8080032C: jal         0x800F12D4
    // 0x80800330: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F12D4(rdram, ctx);
        goto after_36;
    // 0x80800330: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_36:
    // 0x80800334: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080033C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800340: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80800344: jal         0x80100094
    // 0x80800348: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    func_80100094(rdram, ctx);
        goto after_37;
    // 0x80800348: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    after_37:
    // 0x8080034C: jal         0x80089918
    // 0x80800350: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_38;
    // 0x80800350: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_38:
    // 0x80800354: beq         $v0, $zero, L_808008A0
    if (ctx->r2 == 0) {
        // 0x80800358: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008A0;
    }
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080035C: jal         0x808008B4
    // 0x80800360: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808008B4_chdinofamilysmall(rdram, ctx);
        goto after_39;
    // 0x80800360: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_39:
    // 0x80800364: b           L_808008A4
    // 0x80800368: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808008A4;
    // 0x80800368: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080036C:
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800370: jal         0x80103DFC
    // 0x80800374: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_80103DFC(rdram, ctx);
        goto after_40;
    // 0x80800374: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_40:
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080037C: jal         0x80100094
    // 0x80800380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_41;
    // 0x80800380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_41:
    // 0x80800384: jal         0x800898E8
    // 0x80800388: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_42;
    // 0x80800388: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_42:
    // 0x8080038C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800390: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800394: nop

    // 0x80800398: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8080039C: nop

    // 0x808003A0: bc1fl       L_8080045C
    if (!c1cs) {
        // 0x808003A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080045C;
    }
    goto skip_0;
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808003A8: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808003B4: sll         $t6, $t4, 11
    ctx->r14 = S32(ctx->r12 << 11);
    // 0x808003B8: bltz        $t6, L_808003D4
    if (SIGNED(ctx->r14) < 0) {
        // 0x808003BC: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(2404, 0XEE8) << 16);
            goto L_808003D4;
    }
    // 0x808003BC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2404, 0XEE8) << 16);
    // 0x808003C0: jal         0x80089D18
    // 0x808003C4: addiu       $a2, $a2, 0xEE8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2404, 0XEE8));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_43;
    // 0x808003C4: addiu       $a2, $a2, 0xEE8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2404, 0XEE8));
    after_43:
    // 0x808003C8: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x808003CC: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x808003D0: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_808003D4:
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D8: jal         0x80100094
    // 0x808003DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_44;
    // 0x808003DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_44:
    // 0x808003E0: jal         0x800898E8
    // 0x808003E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_45;
    // 0x808003E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_45:
    // 0x808003E8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808003EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003F0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808003F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808003F8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808003FC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80800400: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80800404: jal         0x800F12D4
    // 0x80800408: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F12D4(rdram, ctx);
        goto after_46;
    // 0x80800408: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_46:
    // 0x8080040C: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800414: jal         0x80100094
    // 0x80800418: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_47;
    // 0x80800418: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_47:
    // 0x8080041C: jal         0x800898E8
    // 0x80800420: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_48;
    // 0x80800420: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_48:
    // 0x80800424: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800428: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080042C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800430: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800434: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800438: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x8080043C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800440: jal         0x800F12D4
    // 0x80800444: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F12D4(rdram, ctx);
        goto after_49;
    // 0x80800444: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_49:
    // 0x80800448: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x8080044C: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80800450: b           L_808005AC
    // 0x80800454: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
        goto L_808005AC;
    // 0x80800454: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080045C:
    // 0x8080045C: jal         0x80100094
    // 0x80800460: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_50;
    // 0x80800460: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_50:
    // 0x80800464: jal         0x800898E8
    // 0x80800468: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_51;
    // 0x80800468: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_51:
    // 0x8080046C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800470: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800474: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800478: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8080047C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800480: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800484: jal         0x800F10B4
    // 0x80800488: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800F10B4(rdram, ctx);
        goto after_52;
    // 0x80800488: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_52:
    // 0x8080048C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80800490: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080049C: sll         $t2, $t0, 12
    ctx->r10 = S32(ctx->r8 << 12);
    // 0x808004A0: bltz        $t2, L_808004BC
    if (SIGNED(ctx->r10) < 0) {
        // 0x808004A4: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(2404, 0XEFC) << 16);
            goto L_808004BC;
    }
    // 0x808004A4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2404, 0XEFC) << 16);
    // 0x808004A8: jal         0x80089D18
    // 0x808004AC: addiu       $a2, $a2, 0xEFC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2404, 0XEFC));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_53;
    // 0x808004AC: addiu       $a2, $a2, 0xEFC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2404, 0XEFC));
    after_53:
    // 0x808004B0: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x808004B4: ori         $t5, $t4, 0x8
    ctx->r13 = ctx->r12 | 0X8;
    // 0x808004B8: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
L_808004BC:
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C0: jal         0x80100094
    // 0x808004C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_54;
    // 0x808004C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_54:
    // 0x808004C8: jal         0x800898E8
    // 0x808004CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_55;
    // 0x808004CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_55:
    // 0x808004D0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808004D4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808004D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808004DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808004E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808004E4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808004E8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x808004EC: jal         0x800F12D4
    // 0x808004F0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F12D4(rdram, ctx);
        goto after_56;
    // 0x808004F0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_56:
    // 0x808004F4: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x808004F8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808004FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800500: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800504: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800508: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080050C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800510: nop

    // 0x80800514: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800518: jal         0x800138D0
    // 0x8080051C: nop

    func_800138D0(rdram, ctx);
        goto after_57;
    // 0x8080051C: nop

    after_57:
    // 0x80800520: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800524: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800528: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080052C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800530: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800534: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800538: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8080053C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800540: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80800544: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800548: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8080054C: jal         0x800138D0
    // 0x80800550: swc1        $f18, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f18.u32l;
    func_800138D0(rdram, ctx);
        goto after_58;
    // 0x80800550: swc1        $f18, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f18.u32l;
    after_58:
    // 0x80800554: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800558: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080055C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800560: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800564: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800568: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080056C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800570: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800574: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800578: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x8080057C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800580: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800584: nop

    // 0x80800588: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8080058C: jal         0x800138D0
    // 0x80800590: nop

    func_800138D0(rdram, ctx);
        goto after_59;
    // 0x80800590: nop

    after_59:
    // 0x80800594: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800598: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080059C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005A0: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808005A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808005A8: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
L_808005AC:
    // 0x808005AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B0: jal         0x80100094
    // 0x808005B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_60;
    // 0x808005B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_60:
    // 0x808005B8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808005BC: jal         0x80103EAC
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_61;
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_61:
    // 0x808005C4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005CC: jal         0x80100094
    // 0x808005D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_62;
    // 0x808005D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_62:
    // 0x808005D4: jal         0x80089910
    // 0x808005D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_26(rdram, ctx);
        goto after_63;
    // 0x808005D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_63:
    // 0x808005DC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808005E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808005E4: nop

    // 0x808005E8: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808005EC: jal         0x80013970
    // 0x808005F0: nop

    func_80013970(rdram, ctx);
        goto after_64;
    // 0x808005F0: nop

    after_64:
    // 0x808005F4: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x808005F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800600: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800604: addiu       $t6, $sp, 0x60
    ctx->r14 = ADD32(ctx->r29, 0X60);
    // 0x80800608: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8080060C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800610: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800614: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800618: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080061C: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x80800620: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800624: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80800628: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080062C: jal         0x80089878
    // 0x80800630: nop

    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_65;
    // 0x80800630: nop

    after_65:
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800638: jal         0x80100094
    // 0x8080063C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_66;
    // 0x8080063C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_66:
    // 0x80800640: jal         0x800898B0
    // 0x80800644: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_67;
    // 0x80800644: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_67:
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080064C: jal         0x80100094
    // 0x80800650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_68;
    // 0x80800650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_68:
    // 0x80800654: jal         0x80089918
    // 0x80800658: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_69;
    // 0x80800658: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_69:
    // 0x8080065C: beq         $v0, $zero, L_808008A0
    if (ctx->r2 == 0) {
        // 0x80800660: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008A0;
    }
    // 0x80800660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800664: jal         0x808008B4
    // 0x80800668: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808008B4_chdinofamilysmall(rdram, ctx);
        goto after_70;
    // 0x80800668: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_70:
    // 0x8080066C: b           L_808008A4
    // 0x80800670: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808008A4;
    // 0x80800670: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800674:
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800678: jal         0x80103DFC
    // 0x8080067C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_80103DFC(rdram, ctx);
        goto after_71;
    // 0x8080067C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_71:
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800684: jal         0x80100094
    // 0x80800688: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_72;
    // 0x80800688: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_72:
    // 0x8080068C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800690: jal         0x80103EAC
    // 0x80800694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_73;
    // 0x80800694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_73:
    // 0x80800698: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080069C: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x808006A0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808006A4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808006A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808006AC: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x808006B0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808006B4: jal         0x80089878
    // 0x808006B8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_74;
    // 0x808006B8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_74:
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C0: jal         0x80100094
    // 0x808006C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_75;
    // 0x808006C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_75:
    // 0x808006C8: jal         0x800898B0
    // 0x808006CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_76;
    // 0x808006CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_76:
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D4: jal         0x80100094
    // 0x808006D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_77;
    // 0x808006D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_77:
    // 0x808006DC: jal         0x800898E8
    // 0x808006E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_78;
    // 0x808006E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_78:
    // 0x808006E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2404, 0XE58) << 16);
    // 0x808006E8: lwc1        $f14, 0xE58($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2404, 0XE58));
    // 0x808006EC: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x808006F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2404, 0XE5C) << 16);
    // 0x808006F4: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x808006F8: nop

    // 0x808006FC: bc1f        L_80800754
    if (!c1cs) {
        // 0x80800700: nop
    
            goto L_80800754;
    }
    // 0x80800700: nop

    // 0x80800704: lwc1        $f2, 0xE5C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2404, 0XE5C));
    // 0x80800708: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080070C: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800710: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80800714: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800718: bc1f        L_80800754
    if (!c1cs) {
        // 0x8080071C: nop
    
            goto L_80800754;
    }
    // 0x8080071C: nop

    // 0x80800720: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800724: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800728: jal         0x800F10B4
    // 0x8080072C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_79;
    // 0x8080072C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_79:
    // 0x80800730: jal         0x800138D0
    // 0x80800734: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800138D0(rdram, ctx);
        goto after_80;
    // 0x80800734: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_80:
    // 0x80800738: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x8080073C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800740: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800744: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800748: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8080074C: b           L_808007D8
    // 0x80800750: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
        goto L_808007D8;
    // 0x80800750: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_80800754:
    // 0x80800754: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2404, 0XE60) << 16);
    // 0x80800758: lwc1        $f2, 0xE60($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2404, 0XE60));
    // 0x8080075C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800760: nop

    // 0x80800764: bc1fl       L_808007DC
    if (!c1cs) {
        // 0x80800768: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_808007DC;
    }
    goto skip_1;
    // 0x80800768: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_1:
    // 0x8080076C: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x80800770: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80800774: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800778: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x8080077C: bltz        $t0, L_808007D8
    if (SIGNED(ctx->r8) < 0) {
        // 0x80800780: addiu       $a0, $zero, 0x416
        ctx->r4 = ADD32(0, 0X416);
            goto L_808007D8;
    }
    // 0x80800780: addiu       $a0, $zero, 0x416
    ctx->r4 = ADD32(0, 0X416);
    // 0x80800784: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800788: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080078C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2404, 0XE64) << 16);
    // 0x80800790: lwc1        $f10, 0xE64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2404, 0XE64));
    // 0x80800794: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800798: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8080079C: addiu       $a2, $zero, 0x55F0
    ctx->r6 = ADD32(0, 0X55F0);
    // 0x808007A0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x808007A4: jal         0x800C4244
    // 0x808007A8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800C4244(rdram, ctx);
        goto after_81;
    // 0x808007A8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_81:
    // 0x808007AC: lbu         $t2, 0x74($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X74);
    // 0x808007B0: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x808007B4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808007B8: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x808007BC: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
    // 0x808007C0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808007C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808007C8: jal         0x800E1610
    // 0x808007CC: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    func_800E1610(rdram, ctx);
        goto after_82;
    // 0x808007CC: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_82:
    // 0x808007D0: lwc1        $f16, 0x34($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808007D4: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
L_808007D8:
    // 0x808007D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_808007DC:
    // 0x808007DC: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007E4: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x808007E8: nop

    // 0x808007EC: bc1fl       L_808008A4
    if (!c1cs) {
        // 0x808007F0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808008A4;
    }
    goto skip_2;
    // 0x808007F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x808007F4: jal         0x808008B4
    // 0x808007F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808008B4_chdinofamilysmall(rdram, ctx);
        goto after_83;
    // 0x808007F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_83:
    // 0x808007FC: b           L_808008A4
    // 0x80800800: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808008A4;
    // 0x80800800: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800804:
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800808: jal         0x808008B4
    // 0x8080080C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808008B4_chdinofamilysmall(rdram, ctx);
        goto after_84;
    // 0x8080080C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_84:
    // 0x80800810: b           L_808008A4
    // 0x80800814: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808008A4;
    // 0x80800814: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800818:
    // 0x80800818: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080081C: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80800820: addiu       $a1, $zero, 0x258
    ctx->r5 = ADD32(0, 0X258);
    // 0x80800824: jal         0x8008A1D0
    // 0x80800828: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiedialog_entrypoint_4(rdram, ctx);
        goto after_85;
    // 0x80800828: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_85:
    // 0x8080082C: beq         $v0, $zero, L_8080084C
    if (ctx->r2 == 0) {
        // 0x80800830: addiu       $a1, $zero, 0x17CC
        ctx->r5 = ADD32(0, 0X17CC);
            goto L_8080084C;
    }
    // 0x80800830: addiu       $a1, $zero, 0x17CC
    ctx->r5 = ADD32(0, 0X17CC);
    // 0x80800834: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800838: addiu       $t4, $zero, 0x39
    ctx->r12 = ADD32(0, 0X39);
    // 0x8080083C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800840: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800844: jal         0x8008A208
    // 0x80800848: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_86;
    // 0x80800848: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_86:
L_8080084C:
    // 0x8080084C: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
    // 0x80800850: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800854: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800858: lui         $at, 0x4333
    ctx->r1 = S32(0X4333 << 16);
    // 0x8080085C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800860: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800864: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x80800868: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8080086C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800870: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800874: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800878: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080087C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80800880: jal         0x80089F20
    // 0x80800884: nop

    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_87;
    // 0x80800884: nop

    after_87:
    // 0x80800888: jal         0x80087738
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdinofamilyfx_entrypoint_0(rdram, ctx);
        goto after_88;
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_88:
    // 0x80800890: b           L_808008A4
    // 0x80800894: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808008A4;
    // 0x80800894: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800898:
    // 0x80800898: jal         0x80087738
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdinofamilyfx_entrypoint_0(rdram, ctx);
        goto after_89;
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_89:
L_808008A0:
    // 0x808008A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808008A4:
    // 0x808008A4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808008A8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x808008AC: jr          $ra
    // 0x808008B0: nop

    return;
    // 0x808008B0: nop

;}
RECOMP_FUNC void _badust_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A20: syscall     125
    recomp_syscall_handler(rdram, ctx, 0x80084A20);
    return;
    // 0x80084A24: xori        $t0, $zero, 0x2C
    ctx->r8 = 0 ^ 0X2C;
;}
RECOMP_FUNC void sukickball_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800500: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800504: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800508: beq         $a0, $zero, L_80800534
    if (ctx->r4 == 0) {
        // 0x8080050C: swc1        $f4, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
            goto L_80800534;
    }
    // 0x8080050C: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    // 0x80800510: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800514: beq         $a0, $at, L_808005E8
    if (ctx->r4 == ctx->r1) {
        // 0x80800518: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808005E8;
    }
    // 0x80800518: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080051C: beq         $a0, $at, L_8080058C
    if (ctx->r4 == ctx->r1) {
        // 0x80800520: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080058C;
    }
    // 0x80800520: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800524: beql        $a0, $at, L_80800644
    if (ctx->r4 == ctx->r1) {
        // 0x80800528: lui         $at, 0xC2D8
        ctx->r1 = S32(0XC2D8 << 16);
            goto L_80800644;
    }
    goto skip_0;
    // 0x80800528: lui         $at, 0xC2D8
    ctx->r1 = S32(0XC2D8 << 16);
    skip_0:
    // 0x8080052C: b           L_8080069C
    // 0x80800530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080069C;
    // 0x80800530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800534:
    // 0x80800534: lui         $at, 0xC2D8
    ctx->r1 = S32(0XC2D8 << 16);
    // 0x80800538: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080053C: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80800540: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3166, 0X11D0) << 16);
    // 0x80800544: lwc1        $f6, 0x11D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3166, 0X11D0));
    // 0x80800548: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8080054C: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    // 0x80800550: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80800554: bc1tl       L_80800574
    if (c1cs) {
        // 0x80800558: lui         $at, 0x42D8
        ctx->r1 = S32(0X42D8 << 16);
            goto L_80800574;
    }
    goto skip_1;
    // 0x80800558: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    skip_1:
    // 0x8080055C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800560: nop

    // 0x80800564: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800568: nop

    // 0x8080056C: bc1f        L_80800698
    if (!c1cs) {
        // 0x80800570: lui         $at, 0x42D8
        ctx->r1 = S32(0X42D8 << 16);
            goto L_80800698;
    }
    // 0x80800570: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
L_80800574:
    // 0x80800574: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800578: jal         0x800DC178
    // 0x8080057C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x8080057C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800580: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800584: b           L_80800698
    // 0x80800588: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
        goto L_80800698;
    // 0x80800588: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
L_8080058C:
    // 0x8080058C: lui         $at, 0xC2D8
    ctx->r1 = S32(0XC2D8 << 16);
    // 0x80800590: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800594: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80800598: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    // 0x8080059C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x808005A0: nop

    // 0x808005A4: bc1tl       L_808005C4
    if (c1cs) {
        // 0x808005A8: lui         $at, 0x42D8
        ctx->r1 = S32(0X42D8 << 16);
            goto L_808005C4;
    }
    goto skip_2;
    // 0x808005A8: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    skip_2:
    // 0x808005AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808005B0: nop

    // 0x808005B4: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x808005B8: nop

    // 0x808005BC: bc1f        L_808005D8
    if (!c1cs) {
        // 0x808005C0: lui         $at, 0x42D8
        ctx->r1 = S32(0X42D8 << 16);
            goto L_808005D8;
    }
    // 0x808005C0: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
L_808005C4:
    // 0x808005C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808005C8: jal         0x800DC178
    // 0x808005CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x808005CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x808005D0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808005D4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_808005D8:
    // 0x808005D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3166, 0X11D4) << 16);
    // 0x808005DC: lwc1        $f16, 0x11D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3166, 0X11D4));
    // 0x808005E0: b           L_80800698
    // 0x808005E4: swc1        $f16, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
        goto L_80800698;
    // 0x808005E4: swc1        $f16, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
L_808005E8:
    // 0x808005E8: lui         $at, 0xC2D8
    ctx->r1 = S32(0XC2D8 << 16);
    // 0x808005EC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808005F0: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x808005F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3166, 0X11D8) << 16);
    // 0x808005F8: lwc1        $f18, 0x11D8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3166, 0X11D8));
    // 0x808005FC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80800600: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    // 0x80800604: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x80800608: bc1tl       L_80800628
    if (c1cs) {
        // 0x8080060C: lui         $at, 0x42D8
        ctx->r1 = S32(0X42D8 << 16);
            goto L_80800628;
    }
    goto skip_3;
    // 0x8080060C: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    skip_3:
    // 0x80800610: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800614: nop

    // 0x80800618: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8080061C: nop

    // 0x80800620: bc1f        L_80800698
    if (!c1cs) {
        // 0x80800624: lui         $at, 0x42D8
        ctx->r1 = S32(0X42D8 << 16);
            goto L_80800698;
    }
    // 0x80800624: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
L_80800628:
    // 0x80800628: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080062C: jal         0x800DC178
    // 0x80800630: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800630: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800634: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800638: b           L_80800698
    // 0x8080063C: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
        goto L_80800698;
    // 0x8080063C: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x80800640: lui         $at, 0xC2D8
    ctx->r1 = S32(0XC2D8 << 16);
L_80800644:
    // 0x80800644: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800648: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8080064C: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    // 0x80800650: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80800654: nop

    // 0x80800658: bc1tl       L_80800678
    if (c1cs) {
        // 0x8080065C: lui         $at, 0x42D8
        ctx->r1 = S32(0X42D8 << 16);
            goto L_80800678;
    }
    goto skip_4;
    // 0x8080065C: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    skip_4:
    // 0x80800660: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800664: nop

    // 0x80800668: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8080066C: nop

    // 0x80800670: bc1f        L_8080068C
    if (!c1cs) {
        // 0x80800674: lui         $at, 0x42D8
        ctx->r1 = S32(0X42D8 << 16);
            goto L_8080068C;
    }
    // 0x80800674: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
L_80800678:
    // 0x80800678: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080067C: jal         0x800DC178
    // 0x80800680: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800680: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_3:
    // 0x80800684: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800688: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_8080068C:
    // 0x8080068C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3166, 0X11DC) << 16);
    // 0x80800690: lwc1        $f8, 0x11DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3166, 0X11DC));
    // 0x80800694: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
L_80800698:
    // 0x80800698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080069C:
    // 0x8080069C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006A0: jr          $ra
    // 0x808006A4: nop

    return;
    // 0x808006A4: nop

;}
RECOMP_FUNC void _badrone_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084850: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084850);
    return;
    // 0x80084854: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void chmumbopadstatue_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1920, 0X120) << 16);
    // 0x8080008C: jr          $ra
    // 0x80800090: addiu       $v0, $v0, 0x120
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1920, 0X120));
    return;
    // 0x80800090: addiu       $v0, $v0, 0x120
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1920, 0X120));
    // 0x80800094: nop

    // 0x80800098: nop

    // 0x8080009C: nop

;}
RECOMP_FUNC void chmumboskulls_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1352, 0XC0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1352, 0XC0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1352, 0XC0));
;}
RECOMP_FUNC void _dblight_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800879E8: syscall     647
    recomp_syscall_handler(rdram, ctx, 0x800879E8);
    return;
    // 0x800879EC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
