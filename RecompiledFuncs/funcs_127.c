#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8001BE94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BE94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001BE98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001BE9C: jal         0x8001B3E8
    // 0x8001BEA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    heap_bytes_allocated(rdram, ctx);
        goto after_0;
    // 0x8001BEA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001BEA4: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001BEA8: lw          $t6, -0x1670($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1670);
    // 0x8001BEAC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8001BEB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001BEB4: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8001BEB8: blez        $v1, L_8001BEC8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001BEBC: lw          $a1, -0x20($t7)
        ctx->r5 = MEM_W(ctx->r15, -0X20);
            goto L_8001BEC8;
    }
    // 0x8001BEBC: lw          $a1, -0x20($t7)
    ctx->r5 = MEM_W(ctx->r15, -0X20);
    // 0x8001BEC0: b           L_8001BEC8
    // 0x8001BEC4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_8001BEC8;
    // 0x8001BEC4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_8001BEC8:
    // 0x8001BEC8: jal         0x8001BD30
    // 0x8001BECC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8001BD30(rdram, ctx);
        goto after_1;
    // 0x8001BECC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8001BED0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8001BED4: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8001BED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001BEDC: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x8001BEE0: subu        $a0, $t8, $a1
    ctx->r4 = SUB32(ctx->r24, ctx->r5);
    // 0x8001BEE4: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x8001BEE8: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8001BEEC: bne         $at, $zero, L_8001BF04
    if (ctx->r1 != 0) {
        // 0x8001BEF0: nop
    
            goto L_8001BF04;
    }
    // 0x8001BEF0: nop

    // 0x8001BEF4: lbu         $t9, 0xF($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XF);
    // 0x8001BEF8: srl         $t0, $t9, 6
    ctx->r8 = S32(U32(ctx->r25) >> 6);
    // 0x8001BEFC: beql        $t0, $zero, L_8001BF50
    if (ctx->r8 == 0) {
        // 0x8001BF00: lbu         $t4, 0xF($a1)
        ctx->r12 = MEM_BU(ctx->r5, 0XF);
            goto L_8001BF50;
    }
    goto skip_0;
    // 0x8001BF00: lbu         $t4, 0xF($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XF);
    skip_0:
L_8001BF04:
    // 0x8001BF04: lw          $a2, -0x1670($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X1670);
    // 0x8001BF08: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8001BF0C: beql        $a2, $v1, L_8001BF50
    if (ctx->r6 == ctx->r3) {
        // 0x8001BF10: lbu         $t4, 0xF($a1)
        ctx->r12 = MEM_BU(ctx->r5, 0XF);
            goto L_8001BF50;
    }
    goto skip_1;
    // 0x8001BF10: lbu         $t4, 0xF($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XF);
    skip_1:
    // 0x8001BF14: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
L_8001BF18:
    // 0x8001BF18: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8001BF1C: subu        $a0, $t1, $v1
    ctx->r4 = SUB32(ctx->r9, ctx->r3);
    // 0x8001BF20: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x8001BF24: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8001BF28: bnel        $at, $zero, L_8001BF44
    if (ctx->r1 != 0) {
        // 0x8001BF2C: lw          $v1, 0x0($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X0);
            goto L_8001BF44;
    }
    goto skip_2;
    // 0x8001BF2C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    skip_2:
    // 0x8001BF30: lbu         $t2, 0xF($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XF);
    // 0x8001BF34: srl         $t3, $t2, 6
    ctx->r11 = S32(U32(ctx->r10) >> 6);
    // 0x8001BF38: beql        $t3, $zero, L_8001BF50
    if (ctx->r11 == 0) {
        // 0x8001BF3C: lbu         $t4, 0xF($a1)
        ctx->r12 = MEM_BU(ctx->r5, 0XF);
            goto L_8001BF50;
    }
    goto skip_3;
    // 0x8001BF3C: lbu         $t4, 0xF($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XF);
    skip_3:
    // 0x8001BF40: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
L_8001BF44:
    // 0x8001BF44: bnel        $a2, $v1, L_8001BF18
    if (ctx->r6 != ctx->r3) {
        // 0x8001BF48: lw          $t1, 0x4($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X4);
            goto L_8001BF18;
    }
    goto skip_4;
    // 0x8001BF48: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    skip_4:
    // 0x8001BF4C: lbu         $t4, 0xF($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XF);
L_8001BF50:
    // 0x8001BF50: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8001BF54: srl         $t5, $t4, 6
    ctx->r13 = S32(U32(ctx->r12) >> 6);
    // 0x8001BF58: beq         $t5, $zero, L_8001BF68
    if (ctx->r13 == 0) {
        // 0x8001BF5C: nop
    
            goto L_8001BF68;
    }
    // 0x8001BF5C: nop

    // 0x8001BF60: b           L_8001BF78
    // 0x8001BF64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001BF78;
    // 0x8001BF64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BF68:
    // 0x8001BF68: beq         $at, $zero, L_8001BF78
    if (ctx->r1 == 0) {
        // 0x8001BF6C: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8001BF78;
    }
    // 0x8001BF6C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8001BF70: b           L_8001BF78
    // 0x8001BF74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001BF78;
    // 0x8001BF74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BF78:
    // 0x8001BF78: jr          $ra
    // 0x8001BF7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001BF7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800914_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080091C: jal         0x80800068
    // 0x80800920: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800068_bskazpaddle(rdram, ctx);
        goto after_0;
    // 0x80800920: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800924: jal         0x800839C8
    // 0x80800928: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80800928: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080092C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800930: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800934: jr          $ra
    // 0x80800938: nop

    return;
    // 0x80800938: nop

;}
RECOMP_FUNC void func_800ECD60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECD60: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800ECD64: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800ECD68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800ECD6C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800ECD70: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800ECD74: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800ECD78: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800ECD7C: lwc1        $f6, 0x48($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X48);
    // 0x800ECD80: lwc1        $f4, 0x44($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X44);
    // 0x800ECD84: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800ECD88: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800ECD8C: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ECD90: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800ECD94: addiu       $a2, $t6, 0x38
    ctx->r6 = ADD32(ctx->r14, 0X38);
    // 0x800ECD98: addiu       $a1, $t6, 0x2C
    ctx->r5 = ADD32(ctx->r14, 0X2C);
    // 0x800ECD9C: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800ECDA0: nop

    // 0x800ECDA4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800ECDA8: nop

    // 0x800ECDAC: mul.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800ECDB0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800ECDB4: jal         0x800EFE50
    // 0x800ECDB8: nop

    func_800EFE50(rdram, ctx);
        goto after_0;
    // 0x800ECDB8: nop

    after_0:
    // 0x800ECDBC: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800ECDC0: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800ECDC4: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
    // 0x800ECDC8: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800ECDCC: beq         $at, $zero, L_800ECED8
    if (ctx->r1 == 0) {
        // 0x800ECDD0: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800ECED8;
    }
    // 0x800ECDD0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800ECDD4: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800ECDD8: beq         $at, $zero, L_800ECE64
    if (ctx->r1 == 0) {
        // 0x800ECDDC: lh          $t9, -0x10($s0)
        ctx->r25 = MEM_H(ctx->r16, -0X10);
            goto L_800ECE64;
    }
    // 0x800ECDDC: lh          $t9, -0x10($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X10);
L_800ECDE0:
    // 0x800ECDE0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800ECDE4: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800ECDE8: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800ECDEC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800ECDF0: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800ECDF4: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800ECDF8: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ECDFC: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800ECE00: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800ECE04: nop

    // 0x800ECE08: sh          $t1, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = ctx->r9;
    // 0x800ECE0C: lh          $t2, -0x1E($s0)
    ctx->r10 = MEM_H(ctx->r16, -0X1E);
    // 0x800ECE10: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800ECE14: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800ECE18: nop

    // 0x800ECE1C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800ECE20: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800ECE24: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800ECE28: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x800ECE2C: nop

    // 0x800ECE30: sh          $t4, -0xE($s1)
    MEM_H(-0XE, ctx->r17) = ctx->r12;
    // 0x800ECE34: lh          $t5, -0x1C($s0)
    ctx->r13 = MEM_H(ctx->r16, -0X1C);
    // 0x800ECE38: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800ECE3C: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800ECE40: nop

    // 0x800ECE44: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800ECE48: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ECE4C: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800ECE50: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800ECE54: nop

    // 0x800ECE58: sh          $t7, -0xC($s1)
    MEM_H(-0XC, ctx->r17) = ctx->r15;
    // 0x800ECE5C: bne         $at, $zero, L_800ECDE0
    if (ctx->r1 != 0) {
        // 0x800ECE60: lh          $t9, -0x10($s0)
        ctx->r25 = MEM_H(ctx->r16, -0X10);
            goto L_800ECDE0;
    }
    // 0x800ECE60: lh          $t9, -0x10($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X10);
L_800ECE64:
    // 0x800ECE64: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800ECE68: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800ECE6C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800ECE70: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800ECE74: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ECE78: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800ECE7C: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800ECE80: nop

    // 0x800ECE84: sh          $t1, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = ctx->r9;
    // 0x800ECE88: lh          $t2, -0xE($s0)
    ctx->r10 = MEM_H(ctx->r16, -0XE);
    // 0x800ECE8C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800ECE90: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800ECE94: nop

    // 0x800ECE98: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800ECE9C: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800ECEA0: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800ECEA4: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x800ECEA8: nop

    // 0x800ECEAC: sh          $t4, -0xE($s1)
    MEM_H(-0XE, ctx->r17) = ctx->r12;
    // 0x800ECEB0: lh          $t5, -0xC($s0)
    ctx->r13 = MEM_H(ctx->r16, -0XC);
    // 0x800ECEB4: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800ECEB8: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800ECEBC: nop

    // 0x800ECEC0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800ECEC4: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ECEC8: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800ECECC: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800ECED0: nop

    // 0x800ECED4: sh          $t7, -0xC($s1)
    MEM_H(-0XC, ctx->r17) = ctx->r15;
L_800ECED8:
    // 0x800ECED8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800ECEDC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800ECEE0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800ECEE4: jr          $ra
    // 0x800ECEE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800ECEE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _bsstonehead_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C60: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C60);
    return;
    // 0x80083C64: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void bssub_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080147C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801480: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(380, 0X18E0) << 16);
    // 0x80801484: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801488: jr          $ra
    // 0x8080148C: lw          $v0, 0x18E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(380, 0X18E0));
    return;
    // 0x8080148C: lw          $v0, 0x18E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(380, 0X18E0));
;}
RECOMP_FUNC void func_80106A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106A28: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106A2C: lw          $a0, 0x6EF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EF0);
    // 0x80106A30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106A38: beql        $a0, $zero, L_80106A54
    if (ctx->r4 == 0) {
        // 0x80106A3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80106A54;
    }
    goto skip_0;
    // 0x80106A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80106A40: jal         0x800B3370
    // 0x80106A44: nop

    func_800B3370(rdram, ctx);
        goto after_0;
    // 0x80106A44: nop

    after_0:
    // 0x80106A48: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106A4C: sw          $zero, 0x6EF0($at)
    MEM_W(0X6EF0, ctx->r1) = 0;
    // 0x80106A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106A54:
    // 0x80106A54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106A58: jr          $ra
    // 0x80106A5C: nop

    return;
    // 0x80106A5C: nop

;}
RECOMP_FUNC void _badrone_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084888: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084888);
    return;
    // 0x8008488C: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_80014DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014DD4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80014DD8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80014DDC: lui         $t9, 0xDF00
    ctx->r25 = S32(0XDF00 << 16);
    // 0x80014DE0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80014DE4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80014DE8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80014DEC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80014DF0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80014DF4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80014DF8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80014DFC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80014E00: jr          $ra
    // 0x80014E04: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    return;
    // 0x80014E04: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
;}
RECOMP_FUNC void _gcfrontend_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088198: syscall     673
    recomp_syscall_handler(rdram, ctx, 0x80088198);
    return;
    // 0x8008819C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void bsstatue_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010A0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808010A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(372, 0X15F0) << 16);
    // 0x808010A8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808010AC: jr          $ra
    // 0x808010B0: lw          $v0, 0x15F0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(372, 0X15F0));
    return;
    // 0x808010B0: lw          $v0, 0x15F0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(372, 0X15F0));
;}
RECOMP_FUNC void func_800D1C38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1C38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D1C3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1C40: jal         0x800D1A04
    // 0x800D1C44: nop

    func_800D1A04(rdram, ctx);
        goto after_0;
    // 0x800D1C44: nop

    after_0:
    // 0x800D1C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1C4C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800D1C50: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800D1C54: jr          $ra
    // 0x800D1C58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D1C58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800000_gclightsDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80800084
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gclightsDll_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: jal         0x80087E88
    // 0x80800014: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _gclightsDll_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800014: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080001C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800020: jr          $ra
    // 0x80800024: nop

    return;
    // 0x80800024: nop

;}
RECOMP_FUNC void _glcutDll_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800887F0: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x800887F0);
    return;
    // 0x800887F4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800590_chgruntyfireballbig(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800590: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800594: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800598: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080059C: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808005A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005A4: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x808005A8: bltzl       $t8, L_80800658
    if (SIGNED(ctx->r24) < 0) {
        // 0x808005AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800658;
    }
    goto skip_0;
    // 0x808005AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808005B0: lw          $a0, 0x6C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C);
    // 0x808005B4: andi        $t9, $a0, 0x1FF
    ctx->r25 = ctx->r4 & 0X1FF;
    // 0x808005B8: jal         0x800F6438
    // 0x808005BC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800F6438(rdram, ctx);
        goto after_0;
    // 0x808005BC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x808005C0: beql        $v0, $zero, L_80800658
    if (ctx->r2 == 0) {
        // 0x808005C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800658;
    }
    goto skip_1;
    // 0x808005C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808005C8: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x808005CC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808005D0: andi        $t0, $a0, 0x1FF
    ctx->r8 = ctx->r4 & 0X1FF;
    // 0x808005D4: jal         0x800F5A00
    // 0x808005D8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x808005D8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_1:
    // 0x808005DC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808005E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005E4: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808005E8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808005EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808005F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808005F4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808005F8: jal         0x800EEB40
    // 0x808005FC: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    func_800EEB40(rdram, ctx);
        goto after_2;
    // 0x808005FC: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800600: lwc1        $f2, 0x18($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800604: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800608: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8080060C: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80800610: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800614: nop

    // 0x80800618: bc1f        L_80800630
    if (!c1cs) {
        // 0x8080061C: nop
    
            goto L_80800630;
    }
    // 0x8080061C: nop

    // 0x80800620: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80800624: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x80800628: b           L_80800654
    // 0x8080062C: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
        goto L_80800654;
    // 0x8080062C: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_80800630:
    // 0x80800630: jal         0x800F18FC
    // 0x80800634: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800F18FC(rdram, ctx);
        goto after_3;
    // 0x80800634: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80800638: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8080063C: jal         0x800EEF94
    // 0x80800640: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800EEF94(rdram, ctx);
        goto after_4;
    // 0x80800640: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_4:
    // 0x80800644: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800648: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080064C: jal         0x800EEBF0
    // 0x80800650: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EEBF0(rdram, ctx);
        goto after_5;
    // 0x80800650: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_5:
L_80800654:
    // 0x80800654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800658:
    // 0x80800658: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080065C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800660: jr          $ra
    // 0x80800664: nop

    return;
    // 0x80800664: nop

    // 0x80800668: nop

    // 0x8080066C: nop

;}
RECOMP_FUNC void func_80800014_chpumproomgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800018: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080001C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800020: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800028: beq         $a1, $at, L_80800044
    if (ctx->r5 == ctx->r1) {
        // 0x8080002C: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_80800044;
    }
    // 0x8080002C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800030: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800034: beq         $a1, $at, L_80800080
    if (ctx->r5 == ctx->r1) {
        // 0x80800038: nop
    
            goto L_80800080;
    }
    // 0x80800038: nop

    // 0x8080003C: b           L_8080009C
    // 0x80800040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080009C;
    // 0x80800040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800044:
    // 0x80800044: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800048: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x8080004C: jal         0x800EE7F8
    // 0x80800050: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800050: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800054: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800058: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8080005C: lui         $a2, 0xC3C8
    ctx->r6 = S32(0XC3C8 << 16);
    // 0x80800060: jal         0x800EF1B8
    // 0x80800064: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x80800064: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    after_1:
    // 0x80800068: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080006C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800070: jal         0x80086670
    // 0x80800074: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800074: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_2:
    // 0x80800078: b           L_8080009C
    // 0x8080007C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080009C;
    // 0x8080007C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800080:
    // 0x80800080: jal         0x808000AC
    // 0x80800084: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_808000AC_chpumproomgrill(rdram, ctx);
        goto after_3;
    // 0x80800084: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80800088: b           L_8080009C
    // 0x8080008C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080009C;
    // 0x8080008C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800090: b           L_8080009C
    // 0x80800094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080009C;
    // 0x80800094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800098: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080009C:
    // 0x8080009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void _bsbansack_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800826F8: syscall     7
    recomp_syscall_handler(rdram, ctx, 0x800826F8);
    return;
    // 0x800826FC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_800172D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800172D4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800172D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800172DC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800172E0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800172E4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800172E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800172EC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800172F0: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x800172F4: addiu       $t8, $t8, -0x6060
    ctx->r24 = ADD32(ctx->r24, -0X6060);
    // 0x800172F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800172FC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80017300: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80017304: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x80017308: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8001730C: sh          $a1, 0x26E($v0)
    MEM_H(0X26E, ctx->r2) = ctx->r5;
    // 0x80017310: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // 0x80017314: sb          $v1, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r3;
    // 0x80017318: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x8001731C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80017320: lhu         $t0, -0xA00($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0XA00);
    // 0x80017324: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80017328: jr          $ra
    // 0x8001732C: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    return;
    // 0x8001732C: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
;}
RECOMP_FUNC void func_80804644_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804644: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80804648: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8080464C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80804650: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80804654: nop

    // 0x80804658: bc1f        L_80804678
    if (!c1cs) {
        // 0x8080465C: nop
    
            goto L_80804678;
    }
    // 0x8080465C: nop

    // 0x80804660: c.le.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl <= ctx->f4.fl;
    // 0x80804664: nop

    // 0x80804668: bc1f        L_80804678
    if (!c1cs) {
        // 0x8080466C: nop
    
            goto L_80804678;
    }
    // 0x8080466C: nop

    // 0x80804670: jr          $ra
    // 0x80804674: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80804674: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804678:
    // 0x80804678: jr          $ra
    // 0x8080467C: nop

    return;
    // 0x8080467C: nop

;}
RECOMP_FUNC void chlakemonster_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808018B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808018C0: jal         0x800889A0
    // 0x808018C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _fxripple_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808018C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x808018C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808018D0: jr          $ra
    // 0x808018D4: nop

    return;
    // 0x808018D4: nop

;}
RECOMP_FUNC void _bsmum_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083828: syscall     75
    recomp_syscall_handler(rdram, ctx, 0x80083828);
    return;
    // 0x8008382C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _bswasher_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800843B8: syscall     109
    recomp_syscall_handler(rdram, ctx, 0x800843B8);
    return;
    // 0x800843BC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bstrexsmall_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800840D8: syscall     102
    recomp_syscall_handler(rdram, ctx, 0x800840D8);
    return;
    // 0x800840DC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_808008F0_chfactorycrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808008F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008F8: jal         0x800F54E4
    // 0x808008FC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808008FC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800900: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800904: jal         0x80800898
    // 0x80800908: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80800898_chfactorycrusher(rdram, ctx);
        goto after_1;
    // 0x80800908: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x8080090C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800910: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80800914: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800918: lwc1        $f0, 0xC($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8080091C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800920: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x80800924: jal         0x800F5A00
    // 0x80800928: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80800928: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8080092C: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800930: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800934: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800938: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8080093C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80800940: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800944: bc1fl       L_80800960
    if (!c1cs) {
        // 0x80800948: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_80800960;
    }
    goto skip_0;
    // 0x80800948: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_0:
    // 0x8080094C: jal         0x800F8418
    // 0x80800950: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_800F8418(rdram, ctx);
        goto after_3;
    // 0x80800950: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x80800954: b           L_80800978
    // 0x80800958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800978;
    // 0x80800958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080095C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_80800960:
    // 0x80800960: nop

    // 0x80800964: bc1fl       L_80800978
    if (!c1cs) {
        // 0x80800968: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800978;
    }
    goto skip_1;
    // 0x80800968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8080096C: jal         0x800F8418
    // 0x80800970: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800F8418(rdram, ctx);
        goto after_4;
    // 0x80800970: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80800974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800978:
    // 0x80800978: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080097C: jr          $ra
    // 0x80800980: nop

    return;
    // 0x80800980: nop

;}
RECOMP_FUNC void chiciclebits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1228, 0X3A0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x3A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1228, 0X3A0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x3A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1228, 0X3A0));
;}
RECOMP_FUNC void gccubesearch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: beq         $a1, $zero, L_80800048
    if (ctx->r5 == 0) {
        // 0x80800008: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800048;
    }
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80800010: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800014: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80800018: nop

    // 0x8080001C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80800020: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80800024: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800028: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8080002C: nop

    // 0x80800030: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80800034: lwc1        $f16, 0xC($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80800038: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8080003C: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80800040: nop

    // 0x80800044: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80800048:
    // 0x80800048: bnel        $a1, $zero, L_8080005C
    if (ctx->r5 != 0) {
        // 0x8080004C: addiu       $a1, $sp, 0x1C
        ctx->r5 = ADD32(ctx->r29, 0X1C);
            goto L_8080005C;
    }
    goto skip_0;
    // 0x8080004C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    skip_0:
    // 0x80800050: b           L_8080005C
    // 0x80800054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_8080005C;
    // 0x80800054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800058: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
L_8080005C:
    // 0x8080005C: jal         0x808006C4
    // 0x80800060: nop

    gccubesearch_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800060: nop

    after_0:
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800068: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080006C: jr          $ra
    // 0x80800070: nop

    return;
    // 0x80800070: nop

;}
RECOMP_FUNC void func_80801110_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801110: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801114: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801118: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080111C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801120: jal         0x8009C128
    // 0x80801124: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80801124: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80801128: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080112C: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80801130: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801134: jal         0x800E1610
    // 0x80801138: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    func_800E1610(rdram, ctx);
        goto after_1;
    // 0x80801138: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8080113C: sw          $v0, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r2;
    // 0x80801140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801144: addiu       $a1, $zero, 0x56C
    ctx->r5 = ADD32(0, 0X56C);
    // 0x80801148: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080114C: jal         0x8009DF18
    // 0x80801150: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DF18(rdram, ctx);
        goto after_2;
    // 0x80801150: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_2:
    // 0x80801154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801158: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080115C: jal         0x8009E5A4
    // 0x80801160: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009E5A4(rdram, ctx);
        goto after_3;
    // 0x80801160: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80801164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801168: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080116C: jal         0x8009E55C
    // 0x80801170: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    func_8009E55C(rdram, ctx);
        goto after_4;
    // 0x80801170: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    after_4:
    // 0x80801174: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801178: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080117C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801180: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80801184: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801188: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080118C: jal         0x80085490
    // 0x80801190: nop

    _bamotor_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80801190: nop

    after_5:
    // 0x80801194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080119C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808011A0: jr          $ra
    // 0x808011A4: nop

    return;
    // 0x808011A4: nop

;}
RECOMP_FUNC void func_80107750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107750: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107758: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010775C: jal         0x80089CB8
    // 0x80107760: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    _subaddiefade_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80107760: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80107764: jal         0x8010A570
    // 0x80107768: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x80107768: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8010776C: jal         0x8010A624
    // 0x80107770: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A624(rdram, ctx);
        goto after_2;
    // 0x80107770: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80107774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107778: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010777C: jr          $ra
    // 0x80107780: nop

    return;
    // 0x80107780: nop

;}
RECOMP_FUNC void _bafpctrl_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084CF8: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084CF8);
    return;
    // 0x80084CFC: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_808039C0_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808039C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808039C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808039C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808039CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808039D0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x808039D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808039D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808039DC: jal         0x80802228
    // 0x808039E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_0;
    // 0x808039E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808039E4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808039E8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808039EC: addiu       $t7, $t6, -0x1720
    ctx->r15 = ADD32(ctx->r14, -0X1720);
    // 0x808039F0: sltiu       $at, $t7, 0x15
    ctx->r1 = ctx->r15 < 0X15 ? 1 : 0;
    // 0x808039F4: beq         $at, $zero, L_80803BD0
    if (ctx->r1 == 0) {
        // 0x808039F8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80803BD0;
    }
    // 0x808039F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808039FC: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9AEC) << 16);
    // 0x80803A00: addu        $at, $at, $t7
    gpr jr_addend_80803A08 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80803A04: lw          $t7, -0x6514($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9AEC));
    // 0x80803A08: jr          $t7
    // 0x80803A0C: nop

    switch (jr_addend_80803A08 >> 2) {
        case 0: goto L_80803A10; break;
        case 1: goto L_80803A38; break;
        case 2: goto L_80803BD0; break;
        case 3: goto L_80803A64; break;
        case 4: goto L_80803A78; break;
        case 5: goto L_80803A8C; break;
        case 6: goto L_80803AE0; break;
        case 7: goto L_80803BD0; break;
        case 8: goto L_80803BD0; break;
        case 9: goto L_80803BD0; break;
        case 10: goto L_80803B70; break;
        case 11: goto L_80803BB0; break;
        case 12: goto L_80803BD0; break;
        case 13: goto L_80803BD0; break;
        case 14: goto L_80803BD0; break;
        case 15: goto L_80803BD0; break;
        case 16: goto L_80803BD0; break;
        case 17: goto L_80803BD0; break;
        case 18: goto L_80803BD0; break;
        case 19: goto L_80803BD0; break;
        case 20: goto L_80803AFC; break;
        default: switch_error(__func__, 0x80803A08, 0x80809AEC);
    }
    // 0x80803A0C: nop

L_80803A10:
    // 0x80803A10: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80803A18: jal         0x80805448
    // 0x80803A1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80803A1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80803A20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803A24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80803A28: jal         0x80805448
    // 0x80803A2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80803A2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80803A30: b           L_80803BD4
    // 0x80803A34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803BD4;
    // 0x80803A34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803A38:
    // 0x80803A38: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80803A3C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80803A40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803A44:
    // 0x80803A44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80803A48: jal         0x80805448
    // 0x80803A4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80803A4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80803A50: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80803A54: bnel        $s0, $s1, L_80803A44
    if (ctx->r16 != ctx->r17) {
        // 0x80803A58: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803A44;
    }
    goto skip_0;
    // 0x80803A58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x80803A5C: b           L_80803BD4
    // 0x80803A60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803BD4;
    // 0x80803A60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803A64:
    // 0x80803A64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803A68: jal         0x8080041C
    // 0x80803A6C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8080041C_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x80803A6C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_4:
    // 0x80803A70: b           L_80803BD4
    // 0x80803A74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803BD4;
    // 0x80803A74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803A78:
    // 0x80803A78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803A7C: jal         0x8080041C
    // 0x80803A80: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8080041C_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x80803A80: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_5:
    // 0x80803A84: b           L_80803BD4
    // 0x80803A88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803BD4;
    // 0x80803A88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803A8C:
    // 0x80803A8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803A90: beq         $s0, $at, L_80803AAC
    if (ctx->r16 == ctx->r1) {
        // 0x80803A94: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803AAC;
    }
    // 0x80803A94: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803A98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803A9C: beq         $s0, $at, L_80803ABC
    if (ctx->r16 == ctx->r1) {
        // 0x80803AA0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803ABC;
    }
    // 0x80803AA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803AA4: b           L_80803BD4
    // 0x80803AA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803BD4;
    // 0x80803AA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803AAC:
    // 0x80803AAC: jal         0x8080041C
    // 0x80803AB0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_8080041C_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x80803AB0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_6:
    // 0x80803AB4: b           L_80803BD4
    // 0x80803AB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803BD4;
    // 0x80803AB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803ABC:
    // 0x80803ABC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80803AC0: jal         0x80805448
    // 0x80803AC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x80803AC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80803AC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803ACC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80803AD0: jal         0x80805448
    // 0x80803AD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_8;
    // 0x80803AD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80803AD8: b           L_80803BD4
    // 0x80803ADC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803BD4;
    // 0x80803ADC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803AE0:
    // 0x80803AE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803AE4: bne         $s0, $at, L_80803BD0
    if (ctx->r16 != ctx->r1) {
        // 0x80803AE8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803BD0;
    }
    // 0x80803AE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803AEC: jal         0x80804A50
    // 0x80803AF0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80804A50_chdiggerboss(rdram, ctx);
        goto after_9;
    // 0x80803AF0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80803AF4: b           L_80803BD4
    // 0x80803AF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803BD4;
    // 0x80803AF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803AFC:
    // 0x80803AFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803B00: beq         $s0, $at, L_80803B28
    if (ctx->r16 == ctx->r1) {
        // 0x80803B04: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803B28;
    }
    // 0x80803B04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803B08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803B0C: beq         $s0, $at, L_80803B38
    if (ctx->r16 == ctx->r1) {
        // 0x80803B10: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_80803B38;
    }
    // 0x80803B10: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80803B14: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80803B18: beq         $s0, $at, L_80803B60
    if (ctx->r16 == ctx->r1) {
        // 0x80803B1C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803B60;
    }
    // 0x80803B1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803B20: b           L_80803BD4
    // 0x80803B24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803BD4;
    // 0x80803B24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803B28:
    // 0x80803B28: jal         0x80804A50
    // 0x80803B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80804A50_chdiggerboss(rdram, ctx);
        goto after_10;
    // 0x80803B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80803B30: b           L_80803BD4
    // 0x80803B34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803BD4;
    // 0x80803B34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803B38:
    // 0x80803B38: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80803B3C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803B40:
    // 0x80803B40: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80803B44: jal         0x80805448
    // 0x80803B48: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_11;
    // 0x80803B48: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_11:
    // 0x80803B4C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80803B50: bnel        $s0, $s1, L_80803B40
    if (ctx->r16 != ctx->r17) {
        // 0x80803B54: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803B40;
    }
    goto skip_1;
    // 0x80803B54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x80803B58: b           L_80803BD4
    // 0x80803B5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803BD4;
    // 0x80803B5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803B60:
    // 0x80803B60: jal         0x808041E4
    // 0x80803B64: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808041E4_chdiggerboss(rdram, ctx);
        goto after_12;
    // 0x80803B64: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x80803B68: b           L_80803BD4
    // 0x80803B6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803BD4;
    // 0x80803B6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803B70:
    // 0x80803B70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803B74: beq         $s0, $at, L_80803B90
    if (ctx->r16 == ctx->r1) {
        // 0x80803B78: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803B90;
    }
    // 0x80803B78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803B7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803B80: beq         $s0, $at, L_80803BA0
    if (ctx->r16 == ctx->r1) {
        // 0x80803B84: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80803BA0;
    }
    // 0x80803B84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803B88: b           L_80803BD4
    // 0x80803B8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803BD4;
    // 0x80803B8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803B90:
    // 0x80803B90: jal         0x8080041C
    // 0x80803B94: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_8080041C_chdiggerboss(rdram, ctx);
        goto after_13;
    // 0x80803B94: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_13:
    // 0x80803B98: b           L_80803BD4
    // 0x80803B9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803BD4;
    // 0x80803B9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803BA0:
    // 0x80803BA0: jal         0x80807DC0
    // 0x80803BA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80807DC0_chdiggerboss(rdram, ctx);
        goto after_14;
    // 0x80803BA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80803BA8: b           L_80803BD4
    // 0x80803BAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803BD4;
    // 0x80803BAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803BB0:
    // 0x80803BB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803BB4: bnel        $s0, $at, L_80803BD4
    if (ctx->r16 != ctx->r1) {
        // 0x80803BB8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80803BD4;
    }
    goto skip_2;
    // 0x80803BB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80803BBC: jal         0x80802228
    // 0x80803BC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_15;
    // 0x80803BC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80803BC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803BC8: jal         0x808080C0
    // 0x80803BCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808080C0_chdiggerboss(rdram, ctx);
        goto after_16;
    // 0x80803BCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
L_80803BD0:
    // 0x80803BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803BD4:
    // 0x80803BD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803BD8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80803BDC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80803BE0: jr          $ra
    // 0x80803BE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80803BE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chswitch_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085830: syscall     176
    recomp_syscall_handler(rdram, ctx, 0x80085830);
    return;
    // 0x80085834: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _subaddietaxi_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A500: syscall     844
    recomp_syscall_handler(rdram, ctx, 0x8008A500);
    return;
    // 0x8008A504: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808005F0_chgoldfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808005F4: addiu       $t6, $a1, -0x3
    ctx->r14 = ADD32(ctx->r5, -0X3);
    // 0x808005F8: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x808005FC: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x80800600: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800604: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800608: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x8080060C: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80800610: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80800614: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80800618: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8080061C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800620: beq         $at, $zero, L_808008F0
    if (ctx->r1 == 0) {
        // 0x80800624: sdc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
            goto L_808008F0;
    }
    // 0x80800624: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800628: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080062C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2312, 0XC9C) << 16);
    // 0x80800630: addu        $at, $at, $t6
    gpr jr_addend_80800638 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800634: lw          $t6, 0xC9C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2312, 0XC9C));
    // 0x80800638: jr          $t6
    // 0x8080063C: nop

    switch (jr_addend_80800638 >> 2) {
        case 0: goto L_80800640; break;
        case 1: goto L_80800660; break;
        case 2: goto L_80800680; break;
        case 3: goto L_808006D8; break;
        case 4: goto L_80800704; break;
        case 5: goto L_80800854; break;
        case 6: goto L_80800890; break;
        case 7: goto L_808008C0; break;
        default: switch_error(__func__, 0x80800638, 0x80800C9C);
    }
    // 0x8080063C: nop

L_80800640:
    // 0x80800640: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800644: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080064C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800650: jal         0x80102424
    // 0x80800654: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800654: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_0:
    // 0x80800658: b           L_808008FC
    // 0x8080065C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_808008FC;
    // 0x8080065C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800660:
    // 0x80800660: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800664: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080066C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800670: jal         0x80102424
    // 0x80800674: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800674: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x80800678: b           L_808008FC
    // 0x8080067C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_808008FC;
    // 0x8080067C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800680:
    // 0x80800680: jal         0x800FC6B0
    // 0x80800684: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC6B0(rdram, ctx);
        goto after_2;
    // 0x80800684: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_2:
    // 0x80800688: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080068C: jal         0x8008FE94
    // 0x80800690: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_8008FE94(rdram, ctx);
        goto after_3;
    // 0x80800690: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_3:
    // 0x80800694: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800698: jal         0x800EE7F8
    // 0x8080069C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x8080069C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x808006A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808006A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808006A8: jal         0x80090010
    // 0x808006AC: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    func_80090010(rdram, ctx);
        goto after_5;
    // 0x808006AC: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    after_5:
    // 0x808006B0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808006B4: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808006B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808006BC: jal         0x80090708
    // 0x808006C0: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    func_80090708(rdram, ctx);
        goto after_6;
    // 0x808006C0: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    after_6:
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C8: jal         0x80102424
    // 0x808006CC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x808006CC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_7:
    // 0x808006D0: b           L_808008FC
    // 0x808006D4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_808008FC;
    // 0x808006D4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808006D8:
    // 0x808006D8: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808006DC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808006E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808006E4: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x808006E8: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808006F4: jal         0x80102424
    // 0x808006F8: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x808006F8: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    after_8:
    // 0x808006FC: b           L_808008FC
    // 0x80800700: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_808008FC;
    // 0x80800700: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800704:
    // 0x80800704: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800708: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080070C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80800710: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800714: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x80800718: jal         0x8008FE94
    // 0x8080071C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    func_8008FE94(rdram, ctx);
        goto after_9;
    // 0x8080071C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_9:
    // 0x80800720: jal         0x80090010
    // 0x80800724: nop

    func_80090010(rdram, ctx);
        goto after_10;
    // 0x80800724: nop

    after_10:
    // 0x80800728: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8080072C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800730: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800734: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800738: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8080073C: addiu       $s1, $s0, 0x18
    ctx->r17 = ADD32(ctx->r16, 0X18);
    // 0x80800740: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x80800744: addiu       $s4, $sp, 0x60
    ctx->r20 = ADD32(ctx->r29, 0X60);
    // 0x80800748: addiu       $s2, $sp, 0x6C
    ctx->r18 = ADD32(ctx->r29, 0X6C);
    // 0x8080074C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800750:
    // 0x80800750: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    // 0x80800754: jal         0x800EFCD8
    // 0x80800758: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    func_800EFCD8(rdram, ctx);
        goto after_11;
    // 0x80800758: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    after_11:
    // 0x8080075C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800760: jal         0x800EF04C
    // 0x80800764: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_800EF04C(rdram, ctx);
        goto after_12;
    // 0x80800764: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_12:
    // 0x80800768: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080076C: jal         0x800EE7F8
    // 0x80800770: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_13;
    // 0x80800770: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_13:
    // 0x80800774: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800778: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080077C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800780: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80800784: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80800788: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080078C: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x80800790: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800794: swc1        $f22, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f22.u32l;
    // 0x80800798: swc1        $f22, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f22.u32l;
    // 0x8080079C: sub.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x808007A0: jal         0x800BEF00
    // 0x808007A4: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    func_800BEF00(rdram, ctx);
        goto after_14;
    // 0x808007A4: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    after_14:
    // 0x808007A8: beql        $v0, $zero, L_80800844
    if (ctx->r2 == 0) {
        // 0x808007AC: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80800844;
    }
    goto skip_0;
    // 0x808007AC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_0:
    // 0x808007B0: jal         0x800C84B0
    // 0x808007B4: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    func_800C84B0(rdram, ctx);
        goto after_15;
    // 0x808007B4: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    after_15:
    // 0x808007B8: bne         $v0, $s5, L_8080082C
    if (ctx->r2 != ctx->r21) {
        // 0x808007BC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080082C;
    }
    // 0x808007BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808007C0: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808007C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808007C8: jal         0x800EE7F8
    // 0x808007CC: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_16;
    // 0x808007CC: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    after_16:
    // 0x808007D0: jal         0x80103EF4
    // 0x808007D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_17;
    // 0x808007D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808007D8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808007DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007E0: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808007E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808007E8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808007EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808007F0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x808007F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808007F8: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x808007FC: jal         0x800BEF00
    // 0x80800800: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    func_800BEF00(rdram, ctx);
        goto after_18;
    // 0x80800800: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    after_18:
    // 0x80800804: bnel        $v0, $zero, L_80800830
    if (ctx->r2 != 0) {
        // 0x80800808: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80800830;
    }
    goto skip_1;
    // 0x80800808: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    skip_1:
    // 0x8080080C: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800814: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800818: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8080081C: jal         0x80102424
    // 0x80800820: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    func_80102424(rdram, ctx);
        goto after_19;
    // 0x80800820: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    after_19:
    // 0x80800824: b           L_808008FC
    // 0x80800828: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_808008FC;
    // 0x80800828: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8080082C:
    // 0x8080082C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
L_80800830:
    // 0x80800830: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800834: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800838: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080083C: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x80800840: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80800844:
    // 0x80800844: bnel        $s3, $s5, L_80800750
    if (ctx->r19 != ctx->r21) {
        // 0x80800848: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800750;
    }
    goto skip_2;
    // 0x80800848: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_2:
    // 0x8080084C: b           L_808008FC
    // 0x80800850: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_808008FC;
    // 0x80800850: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800854:
    // 0x80800854: jal         0x800FC6B0
    // 0x80800858: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC6B0(rdram, ctx);
        goto after_20;
    // 0x80800858: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_20:
    // 0x8080085C: jal         0x8010CD28
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_21;
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800864: jal         0x800F54E4
    // 0x80800868: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    func_800F54E4(rdram, ctx);
        goto after_22;
    // 0x80800868: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    after_22:
    // 0x8080086C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800870: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800874: jal         0x800F8300
    // 0x80800878: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800F8300(rdram, ctx);
        goto after_23;
    // 0x80800878: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_23:
    // 0x8080087C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800880: jal         0x80102424
    // 0x80800884: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_24;
    // 0x80800884: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_24:
    // 0x80800888: b           L_808008FC
    // 0x8080088C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_808008FC;
    // 0x8080088C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800890:
    // 0x80800890: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800894: addiu       $t2, $zero, 0x67
    ctx->r10 = ADD32(0, 0X67);
    // 0x80800898: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8080089C: addiu       $a1, $zero, 0x15C0
    ctx->r5 = ADD32(0, 0X15C0);
    // 0x808008A0: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x808008A4: jal         0x8008A208
    // 0x808008A8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_25;
    // 0x808008A8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_25:
    // 0x808008AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B0: jal         0x80102424
    // 0x808008B4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_26;
    // 0x808008B4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_26:
    // 0x808008B8: b           L_808008FC
    // 0x808008BC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_808008FC;
    // 0x808008BC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808008C0:
    // 0x808008C0: jal         0x800F54E4
    // 0x808008C4: nop

    func_800F54E4(rdram, ctx);
        goto after_27;
    // 0x808008C4: nop

    after_27:
    // 0x808008C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008CC: jal         0x800F82D4
    // 0x808008D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_28;
    // 0x808008D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_28:
    // 0x808008D4: jal         0x80089CA8
    // 0x808008D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_29;
    // 0x808008D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E0: jal         0x80102424
    // 0x808008E4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80102424(rdram, ctx);
        goto after_30;
    // 0x808008E4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_30:
    // 0x808008E8: b           L_808008FC
    // 0x808008EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_808008FC;
    // 0x808008EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808008F0:
    // 0x808008F0: jal         0x80102424
    // 0x808008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_31;
    // 0x808008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x808008F8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808008FC:
    // 0x808008FC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800900: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800904: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80800908: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8080090C: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80800910: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80800914: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80800918: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x8080091C: jr          $ra
    // 0x80800920: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80800920: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_8080063C_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080063C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800644: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800648: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080064C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800650: jal         0x800DF744
    // 0x80800654: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x80800654: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80800658: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8080065C: jal         0x800DF744
    // 0x80800660: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80800660: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800664: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800668: jal         0x80101870
    // 0x8080066C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_2;
    // 0x8080066C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800674: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800678: jr          $ra
    // 0x8080067C: nop

    return;
    // 0x8080067C: nop

;}
RECOMP_FUNC void func_800CA7BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA7BC: lwc1        $f4, 0xE4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XE4);
    // 0x800CA7C0: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800CA7C4: lwc1        $f6, 0xE8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XE8);
    // 0x800CA7C8: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x800CA7CC: lwc1        $f8, 0xEC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x800CA7D0: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x800CA7D4: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800CA7D8: lwc1        $f10, 0xF0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XF0);
    // 0x800CA7DC: jr          $ra
    // 0x800CA7E0: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    return;
    // 0x800CA7E0: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_808002FC_chexploder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002FC: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x80800300: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80800304: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80800308: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8080030C: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80800310: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80800314: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80800318: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8080031C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80800320: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80800324: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80800328: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8080032C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800330: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800334: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800338: jal         0x80100094
    // 0x8080033C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080033C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800340: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800344: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800348: jal         0x80100094
    // 0x8080034C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080034C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800350: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800354: jal         0x800D8FF8
    // 0x80800358: sw          $zero, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = 0;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80800358: sw          $zero, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = 0;
    after_2:
    // 0x8080035C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80800360: jal         0x8001210C
    // 0x80800364: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_3;
    // 0x80800364: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800368: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // 0x8080036C: lwc1        $f4, 0x5C($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X5C);
    // 0x80800370: lh          $v1, 0xE($s5)
    ctx->r3 = MEM_H(ctx->r21, 0XE);
    // 0x80800374: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80800378: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x8080037C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1392, 0X1AC0) << 16);
    // 0x80800380: addiu       $fp, $sp, 0x90
    ctx->r30 = ADD32(ctx->r29, 0X90);
    // 0x80800384: blez        $v1, L_8080063C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80800388: swc1        $f6, 0x5C($s5)
        MEM_W(0X5C, ctx->r21) = ctx->f6.u32l;
            goto L_8080063C;
    }
    // 0x80800388: swc1        $f6, 0x5C($s5)
    MEM_W(0X5C, ctx->r21) = ctx->f6.u32l;
    // 0x8080038C: lwc1        $f24, 0x1AC0($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1392, 0X1AC0));
    // 0x80800390: addiu       $s4, $sp, 0x9C
    ctx->r20 = ADD32(ctx->r29, 0X9C);
    // 0x80800394: addiu       $s3, $sp, 0x6C
    ctx->r19 = ADD32(ctx->r29, 0X6C);
L_80800398:
    // 0x80800398: lw          $t6, 0x34($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X34);
    // 0x8080039C: sll         $t8, $t6, 17
    ctx->r24 = S32(ctx->r14 << 17);
    // 0x808003A0: bgezl       $t8, L_80800630
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808003A4: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_80800630;
    }
    goto skip_0;
    // 0x808003A4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    skip_0:
    // 0x808003A8: lh          $t9, 0x30($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X30);
    // 0x808003AC: lh          $t0, 0x32($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X32);
    // 0x808003B0: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808003B4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x808003B8: lh          $t1, 0x34($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X34);
    // 0x808003BC: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808003C0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808003C4: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x808003C8: addiu       $s1, $s0, 0x18
    ctx->r17 = ADD32(ctx->r16, 0X18);
    // 0x808003CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808003D0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x808003D4: addiu       $s2, $s6, 0x4
    ctx->r18 = ADD32(ctx->r22, 0X4);
    // 0x808003D8: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x808003DC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808003E0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x808003E4: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x808003E8: mul.s       $f8, $f16, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x808003EC: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x808003F0: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808003F4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808003F8: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808003FC: mul.s       $f6, $f22, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x80800400: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x80800404: add.s       $f18, $f22, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f22.fl + ctx->f22.fl;
    // 0x80800408: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080040C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800410: jal         0x800EFA20
    // 0x80800414: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    func_800EFA20(rdram, ctx);
        goto after_4;
    // 0x80800414: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x80800418: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8080041C: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80800420: jal         0x800EFA20
    // 0x80800424: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFA20(rdram, ctx);
        goto after_5;
    // 0x80800424: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x80800428: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080042C: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x80800430: jal         0x800EFA20
    // 0x80800434: lw          $a2, 0x38($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X38);
    func_800EFA20(rdram, ctx);
        goto after_6;
    // 0x80800434: lw          $a2, 0x38($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X38);
    after_6:
    // 0x80800438: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080043C: jal         0x800EF04C
    // 0x80800440: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x80800440: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80800444: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800448: jal         0x800EF04C
    // 0x8080044C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x8080044C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_8:
    // 0x80800450: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x80800454: jal         0x800EE7F8
    // 0x80800458: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x80800458: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_9:
    // 0x8080045C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800460: jal         0x800EE7F8
    // 0x80800464: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x80800464: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_10:
    // 0x80800468: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080046C: jal         0x800EF04C
    // 0x80800470: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x80800470: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_11:
    // 0x80800474: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800478: jal         0x800EEB40
    // 0x8080047C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EEB40(rdram, ctx);
        goto after_12;
    // 0x8080047C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_12:
    // 0x80800480: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1392, 0X1AC4) << 16);
    // 0x80800484: lwc1        $f10, 0x1AC4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1392, 0X1AC4));
    // 0x80800488: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8080048C: nop

    // 0x80800490: bc1fl       L_808004B0
    if (!c1cs) {
        // 0x80800494: lh          $t5, 0x36($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X36);
            goto L_808004B0;
    }
    goto skip_1;
    // 0x80800494: lh          $t5, 0x36($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X36);
    skip_1:
    // 0x80800498: lbu         $t2, 0x36($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X36);
    // 0x8080049C: andi        $t3, $t2, 0xFFBF
    ctx->r11 = ctx->r10 & 0XFFBF;
    // 0x808004A0: sb          $t3, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r11;
    // 0x808004A4: b           L_8080062C
    // 0x808004A8: lh          $v1, 0xE($s5)
    ctx->r3 = MEM_H(ctx->r21, 0XE);
        goto L_8080062C;
    // 0x808004A8: lh          $v1, 0xE($s5)
    ctx->r3 = MEM_H(ctx->r21, 0XE);
    // 0x808004AC: lh          $t5, 0x36($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X36);
L_808004B0:
    // 0x808004B0: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x808004B4: andi        $t7, $s7, 0x1
    ctx->r15 = ctx->r23 & 0X1;
    // 0x808004B8: bltzl       $t5, L_80800604
    if (SIGNED(ctx->r13) < 0) {
        // 0x808004BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800604;
    }
    goto skip_2;
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808004C0: bne         $t6, $t7, L_808004F4
    if (ctx->r14 != ctx->r15) {
        // 0x808004C4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_808004F4;
    }
    // 0x808004C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808004C8: lh          $t8, 0xC($s5)
    ctx->r24 = MEM_H(ctx->r21, 0XC);
    // 0x808004CC: lw          $a3, 0x14($s6)
    ctx->r7 = MEM_W(ctx->r22, 0X14);
    // 0x808004D0: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x808004D4: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x808004D8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808004DC: addiu       $a2, $sp, 0xB4
    ctx->r6 = ADD32(ctx->r29, 0XB4);
    // 0x808004E0: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808004E4: jal         0x800BF340
    // 0x808004E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800BF340(rdram, ctx);
        goto after_13;
    // 0x808004E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_13:
    // 0x808004EC: b           L_808004F4
    // 0x808004F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_808004F4;
    // 0x808004F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808004F4:
    // 0x808004F4: beql        $v1, $zero, L_808005E8
    if (ctx->r3 == 0) {
        // 0x808004F8: lw          $t4, 0x34($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X34);
            goto L_808005E8;
    }
    goto skip_3;
    // 0x808004F8: lw          $t4, 0x34($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X34);
    skip_3:
    // 0x808004FC: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x80800500: sll         $t1, $t9, 18
    ctx->r9 = S32(ctx->r25 << 18);
    // 0x80800504: bgezl       $t1, L_80800604
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800508: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800604;
    }
    goto skip_4;
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x8080050C: jal         0x800EEF94
    // 0x80800510: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EEF94(rdram, ctx);
        goto after_14;
    // 0x80800510: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80800514: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080051C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800520: jal         0x800EFDE8
    // 0x80800524: addiu       $a2, $sp, 0xB4
    ctx->r6 = ADD32(ctx->r29, 0XB4);
    func_800EFDE8(rdram, ctx);
        goto after_15;
    // 0x80800524: addiu       $a2, $sp, 0xB4
    ctx->r6 = ADD32(ctx->r29, 0XB4);
    after_15:
    // 0x80800528: mul.s       $f6, $f20, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x8080052C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800530: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800534: jal         0x800EF368
    // 0x80800538: nop

    func_800EF368(rdram, ctx);
        goto after_16;
    // 0x80800538: nop

    after_16:
    // 0x8080053C: lh          $t2, 0x30($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X30);
    // 0x80800540: lh          $t5, 0x32($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X32);
    // 0x80800544: lbu         $t8, 0x38($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X38);
    // 0x80800548: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8080054C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80800550: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80800554: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800558: sb          $t9, 0x38($s0)
    MEM_B(0X38, ctx->r16) = ctx->r25;
    // 0x8080055C: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x80800560: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800564: mul.s       $f10, $f18, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x80800568: nop

    // 0x8080056C: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80800570: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800574: trunc.w.s   $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800578: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x8080057C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80800580: sh          $t4, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r12;
    // 0x80800584: sh          $t7, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r15;
    // 0x80800588: lh          $t0, 0x10($s5)
    ctx->r8 = MEM_H(ctx->r21, 0X10);
    // 0x8080058C: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800590: bne         $at, $zero, L_808005C0
    if (ctx->r1 != 0) {
        // 0x80800594: nop
    
            goto L_808005C0;
    }
    // 0x80800594: nop

    // 0x80800598: mul.s       $f0, $f22, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x8080059C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808005A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808005A4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808005A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808005AC: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x808005B0: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x808005B4: nop

    // 0x808005B8: bc1f        L_808005D4
    if (!c1cs) {
        // 0x808005BC: nop
    
            goto L_808005D4;
    }
    // 0x808005BC: nop

L_808005C0:
    // 0x808005C0: lbu         $t2, 0x36($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X36);
    // 0x808005C4: andi        $t3, $t2, 0xFFBF
    ctx->r11 = ctx->r10 & 0XFFBF;
    // 0x808005C8: sb          $t3, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r11;
    // 0x808005CC: b           L_8080062C
    // 0x808005D0: lh          $v1, 0xE($s5)
    ctx->r3 = MEM_H(ctx->r21, 0XE);
        goto L_8080062C;
    // 0x808005D0: lh          $v1, 0xE($s5)
    ctx->r3 = MEM_H(ctx->r21, 0XE);
L_808005D4:
    // 0x808005D4: jal         0x8080067C
    // 0x808005D8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8080067C_chexploder(rdram, ctx);
        goto after_17;
    // 0x808005D8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_17:
    // 0x808005DC: b           L_80800604
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800604;
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E4: lw          $t4, 0x34($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X34);
L_808005E8:
    // 0x808005E8: sll         $t6, $t4, 18
    ctx->r14 = S32(ctx->r12 << 18);
    // 0x808005EC: bltzl       $t6, L_80800604
    if (SIGNED(ctx->r14) < 0) {
        // 0x808005F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800604;
    }
    goto skip_5;
    // 0x808005F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x808005F4: lbu         $t8, 0x36($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X36);
    // 0x808005F8: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x808005FC: sb          $t9, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r25;
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800604:
    // 0x80800604: jal         0x800EF04C
    // 0x80800608: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    func_800EF04C(rdram, ctx);
        goto after_18;
    // 0x80800608: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    after_18:
    // 0x8080060C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800610: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800614: jal         0x80800834
    // 0x80800618: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_80800834_chexploder(rdram, ctx);
        goto after_19;
    // 0x80800618: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_19:
    // 0x8080061C: lw          $t0, 0xC0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC0);
    // 0x80800620: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80800624: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80800628: lh          $v1, 0xE($s5)
    ctx->r3 = MEM_H(ctx->r21, 0XE);
L_8080062C:
    // 0x8080062C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_80800630:
    // 0x80800630: slt         $at, $s7, $v1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800634: bne         $at, $zero, L_80800398
    if (ctx->r1 != 0) {
        // 0x80800638: addiu       $s0, $s0, 0x3C
        ctx->r16 = ADD32(ctx->r16, 0X3C);
            goto L_80800398;
    }
    // 0x80800638: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
L_8080063C:
    // 0x8080063C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80800640: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
    // 0x80800644: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800648: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8080064C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800650: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80800654: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80800658: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8080065C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80800660: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80800664: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80800668: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8080066C: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80800670: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80800674: jr          $ra
    // 0x80800678: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x80800678: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void chfactoryprop_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1124, 0XC20) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xC20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1124, 0XC20));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xC20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1124, 0XC20));
;}
RECOMP_FUNC void func_800F3320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3320: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F3324: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800F3328: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800F332C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800F3330: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800F3334: nop

    // 0x800F3338: bc1fl       L_800F3348
    if (!c1cs) {
        // 0x800F333C: lbu         $v1, 0x0($a1)
        ctx->r3 = MEM_BU(ctx->r5, 0X0);
            goto L_800F3348;
    }
    goto skip_0;
    // 0x800F333C: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    skip_0:
    // 0x800F3340: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800F3344: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
L_800F3348:
    // 0x800F3348: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x800F334C: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800F3350: subu        $t7, $t6, $v1
    ctx->r15 = SUB32(ctx->r14, ctx->r3);
    // 0x800F3354: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800F3358: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F335C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F3360: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800F3364: bgezl       $v1, L_800F337C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800F3368: add.s       $f4, $f8, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
            goto L_800F337C;
    }
    goto skip_1;
    // 0x800F3368: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    skip_1:
    // 0x800F336C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800F3370: nop

    // 0x800F3374: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800F3378: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
L_800F337C:
    // 0x800F337C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800F3380: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800F3384: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800F3388: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800F338C: nop

    // 0x800F3390: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800F3394: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800F3398: nop

    // 0x800F339C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800F33A0: beql        $t9, $zero, L_800F33F0
    if (ctx->r25 == 0) {
        // 0x800F33A4: mfc1        $t9, $f6
        ctx->r25 = (int32_t)ctx->f6.u32l;
            goto L_800F33F0;
    }
    goto skip_2;
    // 0x800F33A4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x800F33A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F33AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800F33B0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800F33B4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800F33B8: nop

    // 0x800F33BC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800F33C0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800F33C4: nop

    // 0x800F33C8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800F33CC: bne         $t9, $zero, L_800F33E4
    if (ctx->r25 != 0) {
        // 0x800F33D0: nop
    
            goto L_800F33E4;
    }
    // 0x800F33D0: nop

    // 0x800F33D4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800F33D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F33DC: b           L_800F33FC
    // 0x800F33E0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800F33FC;
    // 0x800F33E0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800F33E4:
    // 0x800F33E4: b           L_800F33FC
    // 0x800F33E8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800F33FC;
    // 0x800F33E8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800F33EC: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
L_800F33F0:
    // 0x800F33F0: nop

    // 0x800F33F4: bltz        $t9, L_800F33E4
    if (SIGNED(ctx->r25) < 0) {
        // 0x800F33F8: nop
    
            goto L_800F33E4;
    }
    // 0x800F33F8: nop

L_800F33FC:
    // 0x800F33FC: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x800F3400: lbu         $t1, 0x1($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X1);
    // 0x800F3404: lbu         $a3, 0x1($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X1);
    // 0x800F3408: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800F340C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800F3410: subu        $t2, $t1, $a3
    ctx->r10 = SUB32(ctx->r9, ctx->r7);
    // 0x800F3414: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800F3418: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800F341C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F3420: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F3424: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800F3428: bgezl       $a3, L_800F3440
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800F342C: add.s       $f10, $f8, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
            goto L_800F3440;
    }
    goto skip_3;
    // 0x800F342C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    skip_3:
    // 0x800F3430: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F3434: nop

    // 0x800F3438: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F343C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
L_800F3440:
    // 0x800F3440: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800F3444: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800F3448: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800F344C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800F3450: nop

    // 0x800F3454: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800F3458: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800F345C: nop

    // 0x800F3460: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800F3464: beql        $t4, $zero, L_800F34B4
    if (ctx->r12 == 0) {
        // 0x800F3468: mfc1        $t4, $f18
        ctx->r12 = (int32_t)ctx->f18.u32l;
            goto L_800F34B4;
    }
    goto skip_4;
    // 0x800F3468: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    skip_4:
    // 0x800F346C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800F3470: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800F3474: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800F3478: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800F347C: nop

    // 0x800F3480: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800F3484: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800F3488: nop

    // 0x800F348C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800F3490: bne         $t4, $zero, L_800F34A8
    if (ctx->r12 != 0) {
        // 0x800F3494: nop
    
            goto L_800F34A8;
    }
    // 0x800F3494: nop

    // 0x800F3498: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800F349C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F34A0: b           L_800F34C0
    // 0x800F34A4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_800F34C0;
    // 0x800F34A4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_800F34A8:
    // 0x800F34A8: b           L_800F34C0
    // 0x800F34AC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_800F34C0;
    // 0x800F34AC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800F34B0: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
L_800F34B4:
    // 0x800F34B4: nop

    // 0x800F34B8: bltz        $t4, L_800F34A8
    if (SIGNED(ctx->r12) < 0) {
        // 0x800F34BC: nop
    
            goto L_800F34A8;
    }
    // 0x800F34BC: nop

L_800F34C0:
    // 0x800F34C0: sb          $t4, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r12;
    // 0x800F34C4: lbu         $t5, 0x2($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X2);
    // 0x800F34C8: lbu         $t0, 0x2($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X2);
    // 0x800F34CC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800F34D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800F34D4: subu        $t6, $t5, $t0
    ctx->r14 = SUB32(ctx->r13, ctx->r8);
    // 0x800F34D8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800F34DC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800F34E0: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F34E4: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F34E8: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800F34EC: bgezl       $t0, L_800F3504
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800F34F0: add.s       $f16, $f8, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
            goto L_800F3504;
    }
    goto skip_5;
    // 0x800F34F0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    skip_5:
    // 0x800F34F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800F34F8: nop

    // 0x800F34FC: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800F3500: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
L_800F3504:
    // 0x800F3504: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800F3508: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800F350C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800F3510: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800F3514: nop

    // 0x800F3518: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800F351C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800F3520: nop

    // 0x800F3524: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800F3528: beql        $t8, $zero, L_800F3578
    if (ctx->r24 == 0) {
        // 0x800F352C: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_800F3578;
    }
    goto skip_6;
    // 0x800F352C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_6:
    // 0x800F3530: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F3534: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800F3538: sub.s       $f6, $f16, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800F353C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800F3540: nop

    // 0x800F3544: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800F3548: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800F354C: nop

    // 0x800F3550: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800F3554: bne         $t8, $zero, L_800F356C
    if (ctx->r24 != 0) {
        // 0x800F3558: nop
    
            goto L_800F356C;
    }
    // 0x800F3558: nop

    // 0x800F355C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800F3560: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F3564: b           L_800F3584
    // 0x800F3568: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800F3584;
    // 0x800F3568: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800F356C:
    // 0x800F356C: b           L_800F3584
    // 0x800F3570: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800F3584;
    // 0x800F3570: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800F3574: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_800F3578:
    // 0x800F3578: nop

    // 0x800F357C: bltz        $t8, L_800F356C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800F3580: nop
    
            goto L_800F356C;
    }
    // 0x800F3580: nop

L_800F3584:
    // 0x800F3584: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800F3588: sb          $t8, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r24;
    // 0x800F358C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F3590: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x800F3594: nop

    // 0x800F3598: bc1f        L_800F35A4
    if (!c1cs) {
        // 0x800F359C: nop
    
            goto L_800F35A4;
    }
    // 0x800F359C: nop

    // 0x800F35A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F35A4:
    // 0x800F35A4: jr          $ra
    // 0x800F35A8: nop

    return;
    // 0x800F35A8: nop

;}
RECOMP_FUNC void _baeggcursor_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B08: syscall     128
    recomp_syscall_handler(rdram, ctx, 0x80084B08);
    return;
    // 0x80084B0C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void _batimer_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085338: syscall     157
    recomp_syscall_handler(rdram, ctx, 0x80085338);
    return;
    // 0x8008533C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_800A16A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A16A4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A16A8: jr          $ra
    // 0x800A16AC: lbu         $v0, 0x7097($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7097);
    return;
    // 0x800A16AC: lbu         $v0, 0x7097($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7097);
;}
RECOMP_FUNC void func_80094574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094574: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80094578: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009457C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80094580: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80094584: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80094588: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x8009458C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80094590: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80094594: jal         0x80094510
    // 0x80094598: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    func_80094510(rdram, ctx);
        goto after_0;
    // 0x80094598: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    after_0:
    // 0x8009459C: beq         $v0, $zero, L_800945DC
    if (ctx->r2 == 0) {
        // 0x800945A0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800945DC;
    }
    // 0x800945A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800945A4:
    // 0x800945A4: jal         0x800883E8
    // 0x800945A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcegg_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x800945A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800945AC: beql        $v0, $zero, L_800945C0
    if (ctx->r2 == 0) {
        // 0x800945B0: lw          $v0, 0x64($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X64);
            goto L_800945C0;
    }
    goto skip_0;
    // 0x800945B0: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    skip_0:
    // 0x800945B4: beql        $s0, $s2, L_80094630
    if (ctx->r16 == ctx->r18) {
        // 0x800945B8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80094630;
    }
    goto skip_1;
    // 0x800945B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800945BC: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
L_800945C0:
    // 0x800945C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800945C4: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    // 0x800945C8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800945CC: jal         0x80094510
    // 0x800945D0: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    func_80094510(rdram, ctx);
        goto after_2;
    // 0x800945D0: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    after_2:
    // 0x800945D4: bne         $v0, $zero, L_800945A4
    if (ctx->r2 != 0) {
        // 0x800945D8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800945A4;
    }
    // 0x800945D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800945DC:
    // 0x800945DC: lw          $t9, 0x64($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X64);
    // 0x800945E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800945E4: jal         0x80094510
    // 0x800945E8: sb          $zero, 0x1($t9)
    MEM_B(0X1, ctx->r25) = 0;
    func_80094510(rdram, ctx);
        goto after_3;
    // 0x800945E8: sb          $zero, 0x1($t9)
    MEM_B(0X1, ctx->r25) = 0;
    after_3:
    // 0x800945EC: beq         $v0, $zero, L_80094624
    if (ctx->r2 == 0) {
        // 0x800945F0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80094624;
    }
    // 0x800945F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800945F4:
    // 0x800945F4: jal         0x800883E8
    // 0x800945F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcegg_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x800945F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800945FC: bnel        $v0, $zero, L_80094630
    if (ctx->r2 != 0) {
        // 0x80094600: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80094630;
    }
    goto skip_2;
    // 0x80094600: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80094604: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x80094608: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009460C: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
    // 0x80094610: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80094614: jal         0x80094510
    // 0x80094618: sb          $t1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r9;
    func_80094510(rdram, ctx);
        goto after_5;
    // 0x80094618: sb          $t1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r9;
    after_5:
    // 0x8009461C: bne         $v0, $zero, L_800945F4
    if (ctx->r2 != 0) {
        // 0x80094620: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800945F4;
    }
    // 0x80094620: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80094624:
    // 0x80094624: lw          $t2, 0x64($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X64);
    // 0x80094628: sb          $zero, 0x1($t2)
    MEM_B(0X1, ctx->r10) = 0;
    // 0x8009462C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80094630:
    // 0x80094630: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80094634: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80094638: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009463C: jr          $ra
    // 0x80094640: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80094640: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chsabreman_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086380: syscall     314
    recomp_syscall_handler(rdram, ctx, 0x80086380);
    return;
    // 0x80086384: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chjadesnake_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F18: syscall     474
    recomp_syscall_handler(rdram, ctx, 0x80086F18);
    return;
    // 0x80086F1C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bskazmove_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002B8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808002BC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808002C0: jal         0x8008CABC
    // 0x808002C4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808002C4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x808002C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808002CC: jal         0x800832E0
    // 0x808002D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808002D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808002D4: jal         0x8009E710
    // 0x808002D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_2;
    // 0x808002D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x808002DC: addiu       $at, $zero, 0xC7
    ctx->r1 = ADD32(0, 0XC7);
    // 0x808002E0: bnel        $v0, $at, L_808002FC
    if (ctx->r2 != ctx->r1) {
        // 0x808002E4: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_808002FC;
    }
    goto skip_0;
    // 0x808002E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x808002E8: jal         0x8008CAC8
    // 0x808002EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_3;
    // 0x808002EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x808002F0: b           L_80800304
    // 0x808002F4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
        goto L_80800304;
    // 0x808002F4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808002F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_808002FC:
    // 0x808002FC: nop

    // 0x80800300: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
L_80800304:
    // 0x80800304: jal         0x8008AF24
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_4;
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800310: jal         0x8008AED4
    // 0x80800314: addiu       $a1, $zero, 0xA7
    ctx->r5 = ADD32(0, 0XA7);
    anctrl_setIndex(rdram, ctx);
        goto after_5;
    // 0x80800314: addiu       $a1, $zero, 0xA7
    ctx->r5 = ADD32(0, 0XA7);
    after_5:
    // 0x80800318: lui         $a1, 0x3EDC
    ctx->r5 = S32(0X3EDC << 16);
    // 0x8080031C: ori         $a1, $a1, 0x28F6
    ctx->r5 = ctx->r5 | 0X28F6;
    // 0x80800320: jal         0x8008B1BC
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_6;
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080032C: jal         0x8008B24C
    // 0x80800330: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    anctrl_setStart(rdram, ctx);
        goto after_7;
    // 0x80800330: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800338: jal         0x8008B134
    // 0x8080033C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x8080033C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80800340: jal         0x8008B064
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800348: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8080034C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800350: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800354: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800358: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080035C: jal         0x8009FFD8
    // 0x80800360: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_10;
    // 0x80800360: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x80800364: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800368: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080036C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800370: jal         0x8008C9BC
    // 0x80800374: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_11;
    // 0x80800374: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_11:
    // 0x80800378: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(260, 0XC40) << 16);
    // 0x8080037C: lwc1        $f6, 0xC40($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(260, 0XC40));
    // 0x80800380: lui         $a3, 0x3FA6
    ctx->r7 = S32(0X3FA6 << 16);
    // 0x80800384: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080038C: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80800390: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    // 0x80800394: jal         0x8008C9F0
    // 0x80800398: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_12;
    // 0x80800398: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x8080039C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003A0: jal         0x8008CA30
    // 0x808003A4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_13;
    // 0x808003A4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_13:
    // 0x808003A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003AC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808003B0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808003B4: jr          $ra
    // 0x808003B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808003B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800704_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800704: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800708: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080070C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800710: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800714: jal         0x80085710
    // 0x80800718: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _capod_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800718: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080071C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800720: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800724: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800728: addiu       $a3, $zero, 0x2030
    ctx->r7 = ADD32(0, 0X2030);
    // 0x8080072C: jal         0x80085708
    // 0x80800730: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800730: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x80800734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800738: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080073C: jr          $ra
    // 0x80800740: nop

    return;
    // 0x80800740: nop

;}
RECOMP_FUNC void func_80804A34_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804A34: jr          $ra
    // 0x80804A38: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80804A38: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800A509C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A509C: lw          $t7, 0x38($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X38);
    // 0x800A50A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A50A4: jr          $ra
    // 0x800A50A8: sb          $t6, 0x3B($t7)
    MEM_B(0X3B, ctx->r15) = ctx->r14;
    return;
    // 0x800A50A8: sb          $t6, 0x3B($t7)
    MEM_B(0X3B, ctx->r15) = ctx->r14;
    // 0x800A50AC: nop

;}
RECOMP_FUNC void func_808032CC_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808032CC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808032D0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1840, 0X5098) << 16);
    // 0x808032D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808032D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808032DC: addiu       $t7, $t7, 0x5098
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1840, 0X5098));
    // 0x808032E0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x808032E4: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x808032E8: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x808032EC: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x808032F0: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x808032F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808032F8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x808032FC: bne         $a1, $zero, L_80803328
    if (ctx->r5 != 0) {
        // 0x80803300: sw          $at, 0x8($t6)
        MEM_W(0X8, ctx->r14) = ctx->r1;
            goto L_80803328;
    }
    // 0x80803300: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80803304: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x80803308: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080330C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80803310: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80803314: jal         0x800DC178
    // 0x80803318: nop

    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x80803318: nop

    after_0:
    // 0x8080331C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80803320: b           L_80803350
    // 0x80803324: add.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f4.fl;
        goto L_80803350;
    // 0x80803324: add.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f4.fl;
L_80803328:
    // 0x80803328: jal         0x80102D78
    // 0x8080332C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102D78(rdram, ctx);
        goto after_1;
    // 0x8080332C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80803330: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x80803334: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80803338: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8080333C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80803340: jal         0x800DC178
    // 0x80803344: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80803344: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80803348: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080334C: add.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f6.fl;
L_80803350:
    // 0x80803350: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80803354: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80803358: jal         0x800EFCD8
    // 0x8080335C: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    func_800EFCD8(rdram, ctx);
        goto after_3;
    // 0x8080335C: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    after_3:
    // 0x80803360: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80803364: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80803368: jal         0x800EE780
    // 0x8080336C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800EE780(rdram, ctx);
        goto after_4;
    // 0x8080336C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x80803370: jal         0x8080009C
    // 0x80803374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chcollballcontrol(rdram, ctx);
        goto after_5;
    // 0x80803374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80803378: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x8080337C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80803380: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80803384: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80803388: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
    // 0x8080338C: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80803390: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80803394: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80803398: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080339C: bc1f        L_808033A8
    if (!c1cs) {
        // 0x808033A0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808033A8;
    }
    // 0x808033A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808033A4: swc1        $f2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f2.u32l;
L_808033A8:
    // 0x808033A8: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x808033AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808033B0: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x808033B4: nop

    // 0x808033B8: bc1fl       L_808033C8
    if (!c1cs) {
        // 0x808033BC: lwc1        $f16, 0x18($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
            goto L_808033C8;
    }
    goto skip_0;
    // 0x808033BC: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    skip_0:
    // 0x808033C0: swc1        $f2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f2.u32l;
    // 0x808033C4: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
L_808033C8:
    // 0x808033C8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x808033CC: nop

    // 0x808033D0: bc1fl       L_808033E0
    if (!c1cs) {
        // 0x808033D4: lwc1        $f18, 0x20($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
            goto L_808033E0;
    }
    goto skip_1;
    // 0x808033D4: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    skip_1:
    // 0x808033D8: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x808033DC: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
L_808033E0:
    // 0x808033E0: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x808033E4: nop

    // 0x808033E8: bc1f        L_808033F4
    if (!c1cs) {
        // 0x808033EC: nop
    
            goto L_808033F4;
    }
    // 0x808033EC: nop

    // 0x808033F0: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
L_808033F4:
    // 0x808033F4: jal         0x800DC178
    // 0x808033F8: nop

    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x808033F8: nop

    after_6:
    // 0x808033FC: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80803400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803404: jal         0x8080324C
    // 0x80803408: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_7;
    // 0x80803408: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_7:
    // 0x8080340C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803410: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803414: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80803418: jr          $ra
    // 0x8080341C: nop

    return;
    // 0x8080341C: nop

;}
RECOMP_FUNC void func_80101E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101E14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101E18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101E1C: jal         0x80104248
    // 0x80101E20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80101E20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80101E24: bne         $v0, $zero, L_80101E34
    if (ctx->r2 != 0) {
        // 0x80101E28: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80101E34;
    }
    // 0x80101E28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101E2C: b           L_80101E3C
    // 0x80101E30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80101E3C;
    // 0x80101E30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101E34:
    // 0x80101E34: jal         0x8008B348
    // 0x80101E38: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x80101E38: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_80101E3C:
    // 0x80101E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101E40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101E44: jr          $ra
    // 0x80101E48: nop

    return;
    // 0x80101E48: nop

;}
RECOMP_FUNC void func_80800BD4_chnutsnbolts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BDC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1304, 0XCC0) << 16);
    // 0x80800BE0: lui         $a3, 0x3F26
    ctx->r7 = S32(0X3F26 << 16);
    // 0x80800BE4: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800BE8: addiu       $a2, $a2, 0xCC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1304, 0XCC0));
    // 0x80800BEC: jal         0x80089D20
    // 0x80800BF0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800BF0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BFC: jr          $ra
    // 0x80800C00: nop

    return;
    // 0x80800C00: nop

;}
