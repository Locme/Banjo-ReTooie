#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800FF01C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF01C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FF020: addiu       $v0, $v0, 0x59C0
    ctx->r2 = ADD32(ctx->r2, 0X59C0);
    // 0x800FF024: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800FF028: sb          $v1, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r3;
    // 0x800FF02C: sb          $v1, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r3;
    // 0x800FF030: jr          $ra
    // 0x800FF034: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    return;
    // 0x800FF034: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
;}
RECOMP_FUNC void chfantasytrashcanbits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080021C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2352, 0X288) << 16);
    // 0x80800220: jr          $ra
    // 0x80800224: addiu       $v0, $v0, 0x288
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2352, 0X288));
    return;
    // 0x80800224: addiu       $v0, $v0, 0x288
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2352, 0X288));
    // 0x80800228: nop

    // 0x8080022C: nop

;}
RECOMP_FUNC void bainput_isEnabled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098024: lw          $t6, 0xA4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA4);
    // 0x80098028: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009802C: sllv        $t9, $t8, $a1
    ctx->r25 = S32(ctx->r24 << (ctx->r5 & 31));
    // 0x80098030: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80098034: jr          $ra
    // 0x80098038: and         $v0, $t7, $t9
    ctx->r2 = ctx->r15 & ctx->r25;
    return;
    // 0x80098038: and         $v0, $t7, $t9
    ctx->r2 = ctx->r15 & ctx->r25;
;}
RECOMP_FUNC void func_800DBF74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DBF74: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800DBF78: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DBF7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DBF80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DBF84: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800DBF88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DBF8C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800DBF90: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800DBF94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DBF98: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800DBF9C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800DBFA0: mflo        $t8
    ctx->r24 = lo;
    // 0x800DBFA4: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
    // 0x800DBFA8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800DBFAC: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DBFB0: mflo        $t0
    ctx->r8 = lo;
    // 0x800DBFB4: addu        $a2, $t6, $t0
    ctx->r6 = ADD32(ctx->r14, ctx->r8);
    // 0x800DBFB8: jal         0x800EFB24
    // 0x800DBFBC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800DBFBC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_0:
    // 0x800DBFC0: jal         0x800EF2A0
    // 0x800DBFC4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800EF2A0(rdram, ctx);
        goto after_1;
    // 0x800DBFC4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800DBFC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DBFCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DBFD0: jr          $ra
    // 0x800DBFD4: nop

    return;
    // 0x800DBFD4: nop

;}
RECOMP_FUNC void func_80800154_chexploder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800154: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80800158: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8080015C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800160: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800164: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800168: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8080016C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800170: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800174: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800178: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080017C: jal         0x800B27E0
    // 0x80800180: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800B27E0(rdram, ctx);
        goto after_0;
    // 0x80800180: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800184: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800188: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080018C: jal         0x80100094
    // 0x80800190: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800190: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800194: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800198: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080019C: jal         0x80100094
    // 0x808001A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808001A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808001A4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808001A8: jal         0x801015D0
    // 0x808001AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_801015D0(rdram, ctx);
        goto after_3;
    // 0x808001AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x808001B0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x808001B4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x808001B8: jal         0x800ADD80
    // 0x808001BC: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    func_800ADD80(rdram, ctx);
        goto after_4;
    // 0x808001BC: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    after_4:
    // 0x808001C0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x808001C4: jal         0x800AE080
    // 0x808001C8: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    func_800AE080(rdram, ctx);
        goto after_5;
    // 0x808001C8: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    after_5:
    // 0x808001CC: lh          $t8, 0xE($s3)
    ctx->r24 = MEM_H(ctx->r19, 0XE);
    // 0x808001D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001D8: lwc1        $f6, 0x38($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X38);
    // 0x808001DC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808001E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808001E4: blez        $t8, L_80800298
    if (SIGNED(ctx->r24) <= 0) {
        // 0x808001E8: div.s       $f20, $f4, $f6
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
            goto L_80800298;
    }
    // 0x808001E8: div.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808001EC: addiu       $s2, $sp, 0x54
    ctx->r18 = ADD32(ctx->r29, 0X54);
L_808001F0:
    // 0x808001F0: jal         0x80019CD4
    // 0x808001F4: nop

    func_80019CD4(rdram, ctx);
        goto after_6;
    // 0x808001F4: nop

    after_6:
    // 0x808001F8: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808001FC: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80800200: jal         0x80019C84
    // 0x80800204: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    mlMtxTranslate(rdram, ctx);
        goto after_7;
    // 0x80800204: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    after_7:
    // 0x80800208: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8080020C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800210: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800214: mul.s       $f12, $f8, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80800218: nop

    // 0x8080021C: mul.s       $f14, $f10, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80800220: nop

    // 0x80800224: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80800228: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8080022C: jal         0x80019C84
    // 0x80800230: nop

    mlMtxTranslate(rdram, ctx);
        goto after_8;
    // 0x80800230: nop

    after_8:
    // 0x80800234: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800238: lwc1        $f14, 0x28($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080023C: jal         0x80019110
    // 0x80800240: lw          $a2, 0x2C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2C);
    mlMtxRotatePYR(rdram, ctx);
        goto after_9;
    // 0x80800240: lw          $a2, 0x2C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2C);
    after_9:
    // 0x80800244: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80800248: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8080024C: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80800250: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80800254: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80800258: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8080025C: jal         0x80019C84
    // 0x80800260: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    mlMtxTranslate(rdram, ctx);
        goto after_10;
    // 0x80800260: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_10:
    // 0x80800264: jal         0x80018AD0
    // 0x80800268: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mlMtxGet(rdram, ctx);
        goto after_11;
    // 0x80800268: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_11:
    // 0x8080026C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800270: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800274: lbu         $a2, 0x39($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X39);
    // 0x80800278: jal         0x800ADEC4
    // 0x8080027C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_800ADEC4(rdram, ctx);
        goto after_12;
    // 0x8080027C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_12:
    // 0x80800280: lh          $t9, 0xE($s3)
    ctx->r25 = MEM_H(ctx->r19, 0XE);
    // 0x80800284: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800288: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x8080028C: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80800290: bne         $at, $zero, L_808001F0
    if (ctx->r1 != 0) {
        // 0x80800294: nop
    
            goto L_808001F0;
    }
    // 0x80800294: nop

L_80800298:
    // 0x80800298: jal         0x800DF72C
    // 0x8080029C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800DF72C(rdram, ctx);
        goto after_13;
    // 0x8080029C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_13:
    // 0x808002A0: lbu         $t0, 0x18($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X18);
    // 0x808002A4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x808002A8: addiu       $s0, $s3, 0x1
    ctx->r16 = ADD32(ctx->r19, 0X1);
    // 0x808002AC: blez        $t0, L_808002D4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x808002B0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808002D4;
    }
    // 0x808002B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808002B4:
    // 0x808002B4: jal         0x800DF744
    // 0x808002B8: lbu         $a1, 0x18($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X18);
    func_800DF744(rdram, ctx);
        goto after_14;
    // 0x808002B8: lbu         $a1, 0x18($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X18);
    after_14:
    // 0x808002BC: lbu         $t1, 0x18($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X18);
    // 0x808002C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808002C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808002C8: slt         $at, $t1, $s1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x808002CC: beql        $at, $zero, L_808002B4
    if (ctx->r1 == 0) {
        // 0x808002D0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808002B4;
    }
    goto skip_0;
    // 0x808002D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_808002D4:
    // 0x808002D4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808002D8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808002DC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808002E0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808002E4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808002E8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x808002EC: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x808002F0: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x808002F4: jr          $ra
    // 0x808002F8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x808002F8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void _chbilldrillboulder_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F88: syscall     485
    recomp_syscall_handler(rdram, ctx, 0x80086F88);
    return;
    // 0x80086F8C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chswappy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800872D8: syscall     547
    recomp_syscall_handler(rdram, ctx, 0x800872D8);
    return;
    // 0x800872DC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800EE0_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800EEC: jal         0x80800D78
    // 0x80800EF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800D78_bsledge(rdram, ctx);
        goto after_0;
    // 0x80800EF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800EF4: jal         0x808001A8
    // 0x80800EF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808001A8_bsledge(rdram, ctx);
        goto after_1;
    // 0x80800EF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800EFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F04: jr          $ra
    // 0x80800F08: nop

    return;
    // 0x80800F08: nop

;}
RECOMP_FUNC void func_80800068_gztrace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8080006C: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x80800070: beql        $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x80800074: lbu         $v0, 0x0($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X0);
            goto L_8080008C;
    }
    goto skip_0;
    // 0x80800074: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    skip_0:
    // 0x80800078: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
L_8080007C:
    // 0x8080007C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800080: bnel        $v0, $zero, L_8080007C
    if (ctx->r2 != 0) {
        // 0x80800084: lbu         $v0, 0x0($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X0);
            goto L_8080007C;
    }
    goto skip_1;
    // 0x80800084: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    skip_1:
    // 0x80800088: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
L_8080008C:
    // 0x8080008C: addiu       $v1, $v1, 0x0
    ctx->r3 = ADD32(ctx->r3, 0X0);
    // 0x80800090: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800094: beq         $v0, $zero, L_808000B0
    if (ctx->r2 == 0) {
        // 0x80800098: sb          $v0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r2;
            goto L_808000B0;
    }
    // 0x80800098: sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
L_8080009C:
    // 0x8080009C: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x808000A0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808000A4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x808000A8: bne         $v0, $zero, L_8080009C
    if (ctx->r2 != 0) {
        // 0x808000AC: sb          $v0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r2;
            goto L_8080009C;
    }
    // 0x808000AC: sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
L_808000B0:
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
RECOMP_FUNC void _subaddieitem_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089FD8: syscall     821
    recomp_syscall_handler(rdram, ctx, 0x80089FD8);
    return;
    // 0x80089FDC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800C395C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C395C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3960: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C3964: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3968: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C396C: bne         $t6, $zero, L_800C3984
    if (ctx->r14 != 0) {
        // 0x800C3970: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C3984;
    }
    // 0x800C3970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3974: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C3978: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C397C: b           L_800C3994
    // 0x800C3980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C3994;
    // 0x800C3980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C3984:
    // 0x800C3984: jal         0x800C1414
    // 0x800C3988: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3988: nop

    after_0:
    // 0x800C398C: lwc1        $f0, 0x6C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x800C3990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C3994:
    // 0x800C3994: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3998: jr          $ra
    // 0x800C399C: nop

    return;
    // 0x800C399C: nop

;}
RECOMP_FUNC void func_80800B20_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800B24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B28: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800B2C: jal         0x8080108C
    // 0x80800B30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8080108C_chvolcanobits(rdram, ctx);
        goto after_0;
    // 0x80800B30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800B34: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800B38: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800B3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B40: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800B44: beq         $t6, $at, L_80800B5C
    if (ctx->r14 == ctx->r1) {
        // 0x80800B48: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800B5C;
    }
    // 0x80800B48: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B4C: beq         $t6, $at, L_80800B94
    if (ctx->r14 == ctx->r1) {
        // 0x80800B50: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800B94;
    }
    // 0x80800B50: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800B54: bne         $t6, $at, L_80800C40
    if (ctx->r14 != ctx->r1) {
        // 0x80800B58: nop
    
            goto L_80800C40;
    }
    // 0x80800B58: nop

L_80800B5C:
    // 0x80800B5C: lbu         $v1, 0x79($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X79);
    // 0x80800B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B64: srl         $v0, $v1, 4
    ctx->r2 = S32(U32(ctx->r3) >> 4);
    // 0x80800B68: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80800B6C: andi        $t7, $v0, 0xF
    ctx->r15 = ctx->r2 & 0XF;
    // 0x80800B70: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x80800B74: andi        $t0, $v1, 0xFF0F
    ctx->r8 = ctx->r3 & 0XFF0F;
    // 0x80800B78: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x80800B7C: bne         $t7, $zero, L_80800C40
    if (ctx->r15 != 0) {
        // 0x80800B80: sb          $t1, 0x79($s0)
        MEM_B(0X79, ctx->r16) = ctx->r9;
            goto L_80800C40;
    }
    // 0x80800B80: sb          $t1, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r9;
    // 0x80800B84: jal         0x80103110
    // 0x80800B88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x80800B88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800B8C: b           L_80800C40
    // 0x80800B90: nop

        goto L_80800C40;
    // 0x80800B90: nop

L_80800B94:
    // 0x80800B94: jal         0x800D9078
    // 0x80800B98: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x80800B98: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_2:
    // 0x80800B9C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BA0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800BA4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800BA8: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800BAC: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80800BB0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800BB4: jal         0x800F12D4
    // 0x80800BB8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F12D4(rdram, ctx);
        goto after_3;
    // 0x80800BB8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x80800BBC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800BC0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800BC4: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80800BC8: jal         0x800EFE50
    // 0x80800BCC: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800EFE50(rdram, ctx);
        goto after_4;
    // 0x80800BCC: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_4:
    // 0x80800BD0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800BD4: beql        $a0, $zero, L_80800BF8
    if (ctx->r4 == 0) {
        // 0x80800BD8: lw          $t3, 0x28($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X28);
            goto L_80800BF8;
    }
    goto skip_0;
    // 0x80800BD8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80800BDC: jal         0x80106790
    // 0x80800BE0: nop

    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80800BE0: nop

    after_5:
    // 0x80800BE4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800BE8: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800BEC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800BF0: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80800BF4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_80800BF8:
    // 0x80800BF8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BFC: beq         $t3, $zero, L_80800C38
    if (ctx->r11 == 0) {
        // 0x80800C00: nop
    
            goto L_80800C38;
    }
    // 0x80800C00: nop

    // 0x80800C04: jal         0x800DA544
    // 0x80800C08: lh          $a0, 0x6($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X6);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x80800C08: lh          $a0, 0x6($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X6);
    after_6:
    // 0x80800C0C: lbu         $t5, 0x79($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X79);
    // 0x80800C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C14: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800C18: andi        $t6, $t5, 0xFF0F
    ctx->r14 = ctx->r13 & 0XFF0F;
    // 0x80800C1C: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x80800C20: jal         0x80101FDC
    // 0x80800C24: sb          $t7, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r15;
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x80800C24: sb          $t7, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r15;
    after_7:
    // 0x80800C28: jal         0x800C2FDC
    // 0x80800C2C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C2FDC(rdram, ctx);
        goto after_8;
    // 0x80800C2C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_8:
    // 0x80800C30: b           L_80800C40
    // 0x80800C34: sb          $zero, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = 0;
        goto L_80800C40;
    // 0x80800C34: sb          $zero, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = 0;
L_80800C38:
    // 0x80800C38: jal         0x80800D6C
    // 0x80800C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D6C_chvolcanobits(rdram, ctx);
        goto after_9;
    // 0x80800C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80800C40:
    // 0x80800C40: jal         0x80801040
    // 0x80800C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801040_chvolcanobits(rdram, ctx);
        goto after_10;
    // 0x80800C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800C48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800C4C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800C50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800C54: jr          $ra
    // 0x80800C58: nop

    return;
    // 0x80800C58: nop

;}
RECOMP_FUNC void func_80800000_gcgoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800004: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x80800008: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8080000C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80800010: beq         $a3, $t8, L_8080003C
    if (ctx->r7 == ctx->r24) {
        // 0x80800014: sra         $a1, $t6, 16
        ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
            goto L_8080003C;
    }
    // 0x80800014: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80800018: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8080001C: lb          $a2, 0x0($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X0);
L_80800020:
    // 0x80800020: bne         $a1, $a2, L_80800030
    if (ctx->r5 != ctx->r6) {
        // 0x80800024: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80800030;
    }
    // 0x80800024: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8080002C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800030:
    // 0x80800030: lb          $a2, 0x0($v1)
    ctx->r6 = MEM_B(ctx->r3, 0X0);
    // 0x80800034: bne         $a3, $a2, L_80800020
    if (ctx->r7 != ctx->r6) {
        // 0x80800038: nop
    
            goto L_80800020;
    }
    // 0x80800038: nop

L_8080003C:
    // 0x8080003C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800040: jr          $ra
    // 0x80800044: nop

    return;
    // 0x80800044: nop

;}
RECOMP_FUNC void func_808007D0_susplinet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D0: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x808007D4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x808007D8: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x808007DC: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x808007E0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x808007E4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x808007E8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x808007EC: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x808007F0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x808007F4: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x808007F8: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x808007FC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800800: lh          $t7, 0x34($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X34);
    // 0x80800804: lh          $t6, 0x30($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X30);
    // 0x80800808: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080080C: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80800810: sw          $t8, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r24;
    // 0x80800814: lh          $t9, 0x4($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X4);
    // 0x80800818: addu        $s5, $a0, $t6
    ctx->r21 = ADD32(ctx->r4, ctx->r14);
    // 0x8080081C: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x80800820: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80800824: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x80800828: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8080082C: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80800830: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3206, 0X1304) << 16);
    // 0x80800834: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80800838: nop

    // 0x8080083C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800840: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x80800844: nop

    // 0x80800848: bc1fl       L_8080085C
    if (!c1cs) {
        // 0x8080084C: lh          $t3, 0x2($s6)
        ctx->r11 = MEM_H(ctx->r22, 0X2);
            goto L_8080085C;
    }
    goto skip_0;
    // 0x8080084C: lh          $t3, 0x2($s6)
    ctx->r11 = MEM_H(ctx->r22, 0X2);
    skip_0:
    // 0x80800850: b           L_80800D08
    // 0x80800854: lwc1        $f0, 0x1304($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3206, 0X1304));
        goto L_80800D08;
    // 0x80800854: lwc1        $f0, 0x1304($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3206, 0X1304));
    // 0x80800858: lh          $t3, 0x2($s6)
    ctx->r11 = MEM_H(ctx->r22, 0X2);
L_8080085C:
    // 0x8080085C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3206, 0X1308) << 16);
    // 0x80800860: addiu       $a0, $s4, 0xC
    ctx->r4 = ADD32(ctx->r20, 0XC);
    // 0x80800864: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80800868: addu        $t5, $s5, $t4
    ctx->r13 = ADD32(ctx->r21, ctx->r12);
    // 0x8080086C: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80800870: addiu       $a1, $s4, 0x18
    ctx->r5 = ADD32(ctx->r20, 0X18);
    // 0x80800874: lui         $a2, 0x41C8
    ctx->r6 = S32(0X41C8 << 16);
    // 0x80800878: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8080087C: nop

    // 0x80800880: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800884: c.le.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl <= ctx->f10.fl;
    // 0x80800888: nop

    // 0x8080088C: bc1f        L_8080089C
    if (!c1cs) {
        // 0x80800890: nop
    
            goto L_8080089C;
    }
    // 0x80800890: nop

    // 0x80800894: b           L_80800D08
    // 0x80800898: lwc1        $f0, 0x1308($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3206, 0X1308));
        goto L_80800D08;
    // 0x80800898: lwc1        $f0, 0x1308($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3206, 0X1308));
L_8080089C:
    // 0x8080089C: jal         0x800EEDE8
    // 0x808008A0: swc1        $f12, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f12.u32l;
    func_800EEDE8(rdram, ctx);
        goto after_0;
    // 0x808008A0: swc1        $f12, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x808008A4: beq         $v0, $zero, L_80800908
    if (ctx->r2 == 0) {
        // 0x808008A8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800908;
    }
    // 0x808008A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808008AC: lh          $t1, 0x4($s6)
    ctx->r9 = MEM_H(ctx->r22, 0X4);
    // 0x808008B0: lh          $t7, 0x2($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X2);
    // 0x808008B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3206, 0X130C) << 16);
    // 0x808008B8: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x808008BC: addu        $t3, $s5, $t2
    ctx->r11 = ADD32(ctx->r21, ctx->r10);
    // 0x808008C0: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x808008C4: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x808008C8: lwc1        $f22, 0x130C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3206, 0X130C));
    // 0x808008CC: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x808008D0: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x808008D4: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x808008D8: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808008DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3206, 0X1310) << 16);
    // 0x808008E0: lwc1        $f24, 0x1310($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3206, 0X1310));
    // 0x808008E4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x808008E8: lwc1        $f12, 0x13C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x808008EC: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x808008F0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808008F4: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x808008F8: jal         0x800F10B4
    // 0x808008FC: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x808008FC: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_1:
    // 0x80800900: b           L_80800D0C
    // 0x80800904: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_80800D0C;
    // 0x80800904: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80800908:
    // 0x80800908: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3206, 0X1314) << 16);
    // 0x8080090C: lwc1        $f24, 0x1314($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3206, 0X1314));
    // 0x80800910: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3206, 0X1318) << 16);
    // 0x80800914: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800918: lwc1        $f22, 0x1318($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3206, 0X1318));
    // 0x8080091C: addiu       $s1, $sp, 0xB4
    ctx->r17 = ADD32(ctx->r29, 0XB4);
    // 0x80800920: addiu       $s3, $sp, 0x98
    ctx->r19 = ADD32(ctx->r29, 0X98);
    // 0x80800924: addiu       $s2, $sp, 0xA4
    ctx->r18 = ADD32(ctx->r29, 0XA4);
L_80800928:
    // 0x80800928: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x8080092C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800930: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80800934: lui         $a2, 0x41E8
    ctx->r6 = S32(0X41E8 << 16);
    // 0x80800938: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8080093C: jal         0x800F10B4
    // 0x80800940: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800940: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_2:
    // 0x80800944: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800948: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080094C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80800950: jal         0x800890F8
    // 0x80800954: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    _mlspline_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800954: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_3:
    // 0x80800958: blez        $s0, L_80800978
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8080095C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800978;
    }
    // 0x8080095C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800960: jal         0x800EEAD4
    // 0x80800964: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_4;
    // 0x80800964: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x80800968: lwc1        $f10, -0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, -0X4);
    // 0x8080096C: add.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80800970: b           L_8080097C
    // 0x80800974: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
        goto L_8080097C;
    // 0x80800974: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
L_80800978:
    // 0x80800978: swc1        $f20, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f20.u32l;
L_8080097C:
    // 0x8080097C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800980: jal         0x800EE7F8
    // 0x80800984: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800984: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x80800988: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080098C: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80800990: bne         $s0, $at, L_80800928
    if (ctx->r16 != ctx->r1) {
        // 0x80800994: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80800928;
    }
    // 0x80800994: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800998: lh          $v1, 0x2($s6)
    ctx->r3 = MEM_H(ctx->r22, 0X2);
    // 0x8080099C: lw          $a0, 0x130($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X130);
    // 0x808009A0: lh          $v0, 0x4($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X4);
    // 0x808009A4: sll         $t5, $v1, 1
    ctx->r13 = S32(ctx->r3 << 1);
    // 0x808009A8: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x808009AC: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x808009B0: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x808009B4: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x808009B8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x808009BC: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x808009C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3206, 0X131C) << 16);
    // 0x808009C4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808009C8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x808009CC: lwc1        $f10, 0x131C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3206, 0X131C));
    // 0x808009D0: addu        $t1, $s5, $t8
    ctx->r9 = ADD32(ctx->r21, ctx->r24);
    // 0x808009D4: addu        $t3, $s5, $t5
    ctx->r11 = ADD32(ctx->r21, ctx->r13);
    // 0x808009D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808009DC: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808009E0: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x808009E4: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x808009E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3206, 0X1320) << 16);
    // 0x808009EC: lwc1        $f8, 0x1320($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3206, 0X1320));
    // 0x808009F0: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x808009F4: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x808009F8: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808009FC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800A00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800A04: lwc1        $f6, 0x128($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X128);
    // 0x80800A08: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800A0C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800A10: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800A14: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x80800A18: swc1        $f2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f2.u32l;
    // 0x80800A1C: lwc1        $f12, 0x13C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x80800A20: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800A24: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800A28: sub.s       $f18, $f0, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80800A2C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800A30: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800A34: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800A38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800A3C: swc1        $f18, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
    // 0x80800A40: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80800A44: sub.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80800A48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A4C: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800A50: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80800A54: jal         0x800F10B4
    // 0x80800A58: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80800A58: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80800A5C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800A60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800A64: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80800A68: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x80800A6C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800A70: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80800A74: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800A78: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80800A7C: bc1fl       L_80800B20
    if (!c1cs) {
        // 0x80800A80: lh          $t7, 0x4($s6)
        ctx->r15 = MEM_H(ctx->r22, 0X4);
            goto L_80800B20;
    }
    goto skip_1;
    // 0x80800A80: lh          $t7, 0x4($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X4);
    skip_1:
    // 0x80800A84: lh          $t5, 0x2($s6)
    ctx->r13 = MEM_H(ctx->r22, 0X2);
    // 0x80800A88: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800A8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A90: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80800A94: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x80800A98: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80800A9C: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800AA0: lwc1        $f12, 0x13C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x80800AA4: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80800AA8: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x80800AAC: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800AB0: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80800AB4: swc1        $f2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f2.u32l;
    // 0x80800AB8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80800ABC: add.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x80800AC0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800AC4: jal         0x800F10B4
    // 0x80800AC8: nop

    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x80800AC8: nop

    after_7:
    // 0x80800ACC: lh          $t9, 0x2($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X2);
    // 0x80800AD0: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800AD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800AD8: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80800ADC: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x80800AE0: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80800AE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800AE8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800AEC: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80800AF0: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x80800AF4: lwc1        $f12, 0x13C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x80800AF8: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800AFC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80800B00: add.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x80800B04: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800B08: jal         0x800F10B4
    // 0x80800B0C: nop

    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x80800B0C: nop

    after_8:
    // 0x80800B10: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80800B14: b           L_80800BD0
    // 0x80800B18: lwc1        $f2, 0x88($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X88);
        goto L_80800BD0;
    // 0x80800B18: lwc1        $f2, 0x88($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80800B1C: lh          $t7, 0x4($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X4);
L_80800B20:
    // 0x80800B20: lh          $t3, 0x2($s6)
    ctx->r11 = MEM_H(ctx->r22, 0X2);
    // 0x80800B24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800B28: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80800B2C: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x80800B30: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80800B34: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80800B38: addu        $t5, $s5, $t4
    ctx->r13 = ADD32(ctx->r21, ctx->r12);
    // 0x80800B3C: mul.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80800B40: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80800B44: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80800B48: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80800B4C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80800B50: lwc1        $f12, 0x13C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x80800B54: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800B58: swc1        $f2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f2.u32l;
    // 0x80800B5C: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x80800B60: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800B64: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800B68: jal         0x800F10B4
    // 0x80800B6C: add.s       $f14, $f8, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f2.fl;
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x80800B6C: add.s       $f14, $f8, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f2.fl;
    after_9:
    // 0x80800B70: lh          $t5, 0x4($s6)
    ctx->r13 = MEM_H(ctx->r22, 0X4);
    // 0x80800B74: lh          $t1, 0x2($s6)
    ctx->r9 = MEM_H(ctx->r22, 0X2);
    // 0x80800B78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800B7C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80800B80: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x80800B84: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80800B88: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80800B8C: addu        $t3, $s5, $t2
    ctx->r11 = ADD32(ctx->r21, ctx->r10);
    // 0x80800B90: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80800B94: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80800B98: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800B9C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80800BA0: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800BA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800BA8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800BAC: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x80800BB0: lwc1        $f12, 0x13C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x80800BB4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800BB8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800BBC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80800BC0: jal         0x800F10B4
    // 0x80800BC4: add.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f2.fl;
    func_800F10B4(rdram, ctx);
        goto after_10;
    // 0x80800BC4: add.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f2.fl;
    after_10:
    // 0x80800BC8: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80800BCC: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
L_80800BD0:
    // 0x80800BD0: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80800BD4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800BD8: addiu       $v1, $sp, 0xB4
    ctx->r3 = ADD32(ctx->r29, 0XB4);
    // 0x80800BDC: bc1fl       L_80800C14
    if (!c1cs) {
        // 0x80800BE0: add.s       $f4, $f16, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f2.fl;
            goto L_80800C14;
    }
    goto skip_2;
    // 0x80800BE0: add.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f2.fl;
    skip_2:
    // 0x80800BE4: add.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x80800BE8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800BEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800BF0: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80800BF4: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80800BF8: nop

    // 0x80800BFC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800C00: nop

    // 0x80800C04: mul.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80800C08: b           L_80800C34
    // 0x80800C0C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_80800C34;
    // 0x80800C0C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x80800C10: add.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f2.fl;
L_80800C14:
    // 0x80800C14: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800C18: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80800C1C: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80800C20: nop

    // 0x80800C24: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800C28: nop

    // 0x80800C2C: mul.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80800C30: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_80800C34:
    // 0x80800C34: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800C38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800C3C: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80800C40: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80800C44: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80800C48: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800C4C: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80800C50: bc1fl       L_80800C70
    if (!c1cs) {
        // 0x80800C54: lwc1        $f6, 0xB8($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
            goto L_80800C70;
    }
    goto skip_3;
    // 0x80800C54: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    skip_3:
    // 0x80800C58: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800C5C: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80800C60: nop

    // 0x80800C64: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80800C68: add.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80800C6C: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
L_80800C70:
    // 0x80800C70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800C74: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80800C78: nop

    // 0x80800C7C: bc1fl       L_80800CB0
    if (!c1cs) {
        // 0x80800C80: mtc1        $v0, $f4
        ctx->f4.u32l = ctx->r2;
            goto L_80800CB0;
    }
    goto skip_4;
    // 0x80800C80: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    skip_4:
    // 0x80800C84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80800C88:
    // 0x80800C88: slti        $at, $v0, 0x1C
    ctx->r1 = SIGNED(ctx->r2) < 0X1C ? 1 : 0;
    // 0x80800C8C: beq         $at, $zero, L_80800CAC
    if (ctx->r1 == 0) {
        // 0x80800C90: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_80800CAC;
    }
    // 0x80800C90: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80800C94: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x80800C98: lwc1        $f8, 0x4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80800C9C: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80800CA0: nop

    // 0x80800CA4: bc1tl       L_80800C88
    if (c1cs) {
        // 0x80800CA8: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80800C88;
    }
    goto skip_5;
    // 0x80800CA8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_5:
L_80800CAC:
    // 0x80800CAC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
L_80800CB0:
    // 0x80800CB0: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80800CB4: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80800CB8: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800CBC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3206, 0X1324) << 16);
    // 0x80800CC0: lwc1        $f0, 0x1324($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3206, 0X1324));
    // 0x80800CC4: addiu       $v1, $sp, 0xB4
    ctx->r3 = ADD32(ctx->r29, 0XB4);
    // 0x80800CC8: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80800CCC: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800CD0: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80800CD4: addu        $a0, $v1, $t1
    ctx->r4 = ADD32(ctx->r3, ctx->r9);
    // 0x80800CD8: lwc1        $f14, 0x0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80800CDC: lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X4);
    // 0x80800CE0: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80800CE4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800CE8: jal         0x800F10B4
    // 0x80800CEC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_11;
    // 0x80800CEC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x80800CF0: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800CF4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800CF8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80800CFC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800D00: jal         0x800F10B4
    // 0x80800D04: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    func_800F10B4(rdram, ctx);
        goto after_12;
    // 0x80800D04: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_12:
L_80800D08:
    // 0x80800D08: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80800D0C:
    // 0x80800D0C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800D10: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800D14: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800D18: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80800D1C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80800D20: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80800D24: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80800D28: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80800D2C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80800D30: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80800D34: jr          $ra
    // 0x80800D38: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    return;
    // 0x80800D38: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
;}
RECOMP_FUNC void bsbanswim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A10: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800A14: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(53, 0XA60) << 16);
    // 0x80800A18: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800A1C: jr          $ra
    // 0x80800A20: lw          $v0, 0xA60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(53, 0XA60));
    return;
    // 0x80800A20: lw          $v0, 0xA60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(53, 0XA60));
    // 0x80800A24: nop

    // 0x80800A28: nop

    // 0x80800A2C: nop

;}
RECOMP_FUNC void chmonsterinterior_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1320, 0X1EC8) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x1EC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1320, 0X1EC8));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x1EC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1320, 0X1EC8));
;}
RECOMP_FUNC void func_80801460_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801460: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80801464: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801468: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080146C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801470: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80801474: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80801478: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8080147C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801480: lwc1        $f12, 0x58($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80801484: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801488: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8080148C: jal         0x800F12D4
    // 0x80801490: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F12D4(rdram, ctx);
        goto after_0;
    // 0x80801490: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80801494: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80801498: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8080149C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808014A0: jal         0x80801A9C
    // 0x808014A4: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_80801A9C_chfactorymagnet(rdram, ctx);
        goto after_1;
    // 0x808014A4: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x808014A8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808014AC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808014B0: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x808014B4: jal         0x800EFE50
    // 0x808014B8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    func_800EFE50(rdram, ctx);
        goto after_2;
    // 0x808014B8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x808014BC: jal         0x80103EAC
    // 0x808014C0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_80103EAC(rdram, ctx);
        goto after_3;
    // 0x808014C0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_3:
    // 0x808014C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2284, 0X28E8) << 16);
    // 0x808014C8: lwc1        $f4, 0x28E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2284, 0X28E8));
    // 0x808014CC: addiu       $t7, $sp, 0x4C
    ctx->r15 = ADD32(ctx->r29, 0X4C);
    // 0x808014D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808014D4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808014D8: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x808014DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808014E0: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x808014E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808014E8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x808014EC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808014F0: jal         0x80089878
    // 0x808014F4: nop

    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x808014F4: nop

    after_4:
    // 0x808014F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808014FC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80801500: jr          $ra
    // 0x80801504: nop

    return;
    // 0x80801504: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803B68: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80803B6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803B70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803B74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803B78: beq         $a0, $zero, L_80803CDC
    if (ctx->r4 == 0) {
        // 0x80803B7C: sw          $a1, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r5;
            goto L_80803CDC;
    }
    // 0x80803B7C: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80803B80: lw          $v0, 0x1E4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E4);
    // 0x80803B84: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80803B88: bgezl       $t7, L_80803C48
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80803B8C: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80803C48;
    }
    goto skip_0;
    // 0x80803B8C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    skip_0:
    // 0x80803B90: beq         $a1, $zero, L_80803C04
    if (ctx->r5 == 0) {
        // 0x80803B94: sll         $t0, $v0, 28
        ctx->r8 = S32(ctx->r2 << 28);
            goto L_80803C04;
    }
    // 0x80803B94: sll         $t0, $v0, 28
    ctx->r8 = S32(ctx->r2 << 28);
    // 0x80803B98: bltzl       $t0, L_80803C08
    if (SIGNED(ctx->r8) < 0) {
        // 0x80803B9C: lw          $t8, 0x8C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X8C);
            goto L_80803C08;
    }
    goto skip_1;
    // 0x80803B9C: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    skip_1:
    // 0x80803BA0: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
    // 0x80803BA4: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    // 0x80803BA8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80803BAC: bne         $t1, $at, L_80803BC0
    if (ctx->r9 != ctx->r1) {
        // 0x80803BB0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80803BC0;
    }
    // 0x80803BB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80803BB4: addiu       $t2, $zero, 0x68
    ctx->r10 = ADD32(0, 0X68);
    // 0x80803BB8: b           L_80803BF0
    // 0x80803BBC: sb          $t2, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r10;
        goto L_80803BF0;
    // 0x80803BBC: sb          $t2, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r10;
L_80803BC0:
    // 0x80803BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803BC4: jal         0x8080014C
    // 0x80803BC8: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8080014C_gczoombox(rdram, ctx);
        goto after_0;
    // 0x80803BC8: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_0:
    // 0x80803BCC: addiu       $t3, $zero, 0xFD
    ctx->r11 = ADD32(0, 0XFD);
    // 0x80803BD0: addiu       $t4, $zero, 0x68
    ctx->r12 = ADD32(0, 0X68);
    // 0x80803BD4: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    // 0x80803BD8: sb          $t4, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r12;
    // 0x80803BDC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80803BE0: addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // 0x80803BE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80803BE8: jal         0x8080014C
    // 0x80803BEC: addiu       $a3, $zero, 0x2E
    ctx->r7 = ADD32(0, 0X2E);
    func_8080014C_gczoombox(rdram, ctx);
        goto after_1;
    // 0x80803BEC: addiu       $a3, $zero, 0x2E
    ctx->r7 = ADD32(0, 0X2E);
    after_1:
L_80803BF0:
    // 0x80803BF0: lbu         $t6, 0x1E7($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1E7);
    // 0x80803BF4: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80803BF8: sb          $t7, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r15;
    // 0x80803BFC: b           L_80803C44
    // 0x80803C00: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
        goto L_80803C44;
    // 0x80803C00: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
L_80803C04:
    // 0x80803C04: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
L_80803C08:
    // 0x80803C08: sll         $t0, $v0, 28
    ctx->r8 = S32(ctx->r2 << 28);
    // 0x80803C0C: bnel        $t8, $zero, L_80803C48
    if (ctx->r24 != 0) {
        // 0x80803C10: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80803C48;
    }
    goto skip_2;
    // 0x80803C10: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    skip_2:
    // 0x80803C14: bgezl       $t0, L_80803C48
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80803C18: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80803C48;
    }
    goto skip_3;
    // 0x80803C18: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    skip_3:
    // 0x80803C1C: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x80803C20: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    // 0x80803C24: addiu       $t2, $zero, 0x6C
    ctx->r10 = ADD32(0, 0X6C);
    // 0x80803C28: bnel        $t1, $at, L_80803C38
    if (ctx->r9 != ctx->r1) {
        // 0x80803C2C: lbu         $t3, 0x1E7($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X1E7);
            goto L_80803C38;
    }
    goto skip_4;
    // 0x80803C2C: lbu         $t3, 0x1E7($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1E7);
    skip_4:
    // 0x80803C30: sb          $t2, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r10;
    // 0x80803C34: lbu         $t3, 0x1E7($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1E7);
L_80803C38:
    // 0x80803C38: andi        $t4, $t3, 0xFFF7
    ctx->r12 = ctx->r11 & 0XFFF7;
    // 0x80803C3C: sb          $t4, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r12;
    // 0x80803C40: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
L_80803C44:
    // 0x80803C44: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
L_80803C48:
    // 0x80803C48: bgez        $t6, L_80803CDC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80803C4C: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_80803CDC;
    }
    // 0x80803C4C: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x80803C50: beql        $t7, $zero, L_80803CBC
    if (ctx->r15 == 0) {
        // 0x80803C54: lbu         $t5, 0x30($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X30);
            goto L_80803CBC;
    }
    goto skip_5;
    // 0x80803C54: lbu         $t5, 0x30($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X30);
    skip_5:
    // 0x80803C58: lbu         $t8, 0x30($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X30);
    // 0x80803C5C: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    // 0x80803C60: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    // 0x80803C64: bne         $t8, $at, L_80803C78
    if (ctx->r24 != ctx->r1) {
        // 0x80803C68: addiu       $a1, $sp, 0x28
        ctx->r5 = ADD32(ctx->r29, 0X28);
            goto L_80803C78;
    }
    // 0x80803C68: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80803C6C: addiu       $t9, $zero, 0x68
    ctx->r25 = ADD32(0, 0X68);
    // 0x80803C70: b           L_80803CA8
    // 0x80803C74: sb          $t9, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r25;
        goto L_80803CA8;
    // 0x80803C74: sb          $t9, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r25;
L_80803C78:
    // 0x80803C78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80803C7C: jal         0x8080014C
    // 0x80803C80: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8080014C_gczoombox(rdram, ctx);
        goto after_2;
    // 0x80803C80: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_2:
    // 0x80803C84: addiu       $t0, $zero, 0xFD
    ctx->r8 = ADD32(0, 0XFD);
    // 0x80803C88: addiu       $t1, $zero, 0x68
    ctx->r9 = ADD32(0, 0X68);
    // 0x80803C8C: sb          $t0, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r8;
    // 0x80803C90: sb          $t1, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r9;
    // 0x80803C94: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80803C98: addiu       $a1, $s0, 0x32
    ctx->r5 = ADD32(ctx->r16, 0X32);
    // 0x80803C9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80803CA0: jal         0x8080014C
    // 0x80803CA4: addiu       $a3, $zero, 0x2E
    ctx->r7 = ADD32(0, 0X2E);
    func_8080014C_gczoombox(rdram, ctx);
        goto after_3;
    // 0x80803CA4: addiu       $a3, $zero, 0x2E
    ctx->r7 = ADD32(0, 0X2E);
    after_3:
L_80803CA8:
    // 0x80803CA8: lbu         $t3, 0x1E7($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1E7);
    // 0x80803CAC: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x80803CB0: b           L_80803CDC
    // 0x80803CB4: sb          $t4, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r12;
        goto L_80803CDC;
    // 0x80803CB4: sb          $t4, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r12;
    // 0x80803CB8: lbu         $t5, 0x30($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X30);
L_80803CBC:
    // 0x80803CBC: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    // 0x80803CC0: addiu       $t6, $zero, 0x6C
    ctx->r14 = ADD32(0, 0X6C);
    // 0x80803CC4: bnel        $t5, $at, L_80803CD4
    if (ctx->r13 != ctx->r1) {
        // 0x80803CC8: lbu         $t7, 0x1E7($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X1E7);
            goto L_80803CD4;
    }
    goto skip_6;
    // 0x80803CC8: lbu         $t7, 0x1E7($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1E7);
    skip_6:
    // 0x80803CCC: sb          $t6, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r14;
    // 0x80803CD0: lbu         $t7, 0x1E7($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1E7);
L_80803CD4:
    // 0x80803CD4: andi        $t8, $t7, 0xFFF7
    ctx->r24 = ctx->r15 & 0XFFF7;
    // 0x80803CD8: sb          $t8, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r24;
L_80803CDC:
    // 0x80803CDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803CE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803CE4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80803CE8: jr          $ra
    // 0x80803CEC: nop

    return;
    // 0x80803CEC: nop

;}
RECOMP_FUNC void func_800F68B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F68B8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F68BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F68C0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F68C4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F68C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F68CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F68D0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800F68D4: jal         0x8009E674
    // 0x800F68D8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009E674(rdram, ctx);
        goto after_0;
    // 0x800F68D8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F68DC: beq         $v0, $zero, L_800F68F8
    if (ctx->r2 == 0) {
        // 0x800F68E0: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800F68F8;
    }
    // 0x800F68E0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F68E4: jal         0x80084800
    // 0x800F68E8: nop

    _badrone_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x800F68E8: nop

    after_1:
    // 0x800F68EC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800F68F0: b           L_800F68FC
    // 0x800F68F4: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
        goto L_800F68FC;
    // 0x800F68F4: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
L_800F68F8:
    // 0x800F68F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F68FC:
    // 0x800F68FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6900: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F6904: jr          $ra
    // 0x800F6908: nop

    return;
    // 0x800F6908: nop

;}
RECOMP_FUNC void _sumumbofx_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800898B8: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x800898B8);
    return;
    // 0x800898BC: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_800B5BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5BE4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800B5BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B5BEC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B5BF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B5BF4: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x800B5BF8: jal         0x800B56D0
    // 0x800B5BFC: lbu         $a0, -0x7EB0($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X7EB0);
    func_800B56D0(rdram, ctx);
        goto after_0;
    // 0x800B5BFC: lbu         $a0, -0x7EB0($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X7EB0);
    after_0:
    // 0x800B5C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B5C04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B5C08: jr          $ra
    // 0x800B5C0C: nop

    return;
    // 0x800B5C0C: nop

;}
RECOMP_FUNC void sumultiscore_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800214: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80800218: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8080021C: lw          $s4, 0xA8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA8);
    // 0x80800220: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800224: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800228: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080022C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800230: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80800234: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800238: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080023C: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x80800240: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x80800244: blez        $s4, L_80800334
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80800248: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80800334;
    }
    // 0x80800248: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080024C: andi        $a3, $s4, 0x3
    ctx->r7 = ctx->r20 & 0X3;
    // 0x80800250: beq         $a3, $zero, L_808002A8
    if (ctx->r7 == 0) {
        // 0x80800254: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_808002A8;
    }
    // 0x80800254: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80800258: sll         $a1, $zero, 2
    ctx->r5 = S32(0 << 2);
    // 0x8080025C: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x80800260: addiu       $t6, $sp, 0x88
    ctx->r14 = ADD32(ctx->r29, 0X88);
    // 0x80800264: addiu       $t7, $sp, 0x68
    ctx->r15 = ADD32(ctx->r29, 0X68);
    // 0x80800268: addiu       $t9, $sp, 0x58
    ctx->r25 = ADD32(ctx->r29, 0X58);
    // 0x8080026C: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x80800270: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
    // 0x80800274: addu        $v0, $a1, $t6
    ctx->r2 = ADD32(ctx->r5, ctx->r14);
    // 0x80800278: addu        $s0, $t8, $a1
    ctx->r16 = ADD32(ctx->r24, ctx->r5);
L_8080027C:
    // 0x8080027C: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80800280: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80800284: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800288: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8080028C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800290: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800294: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800298: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080029C: bne         $a2, $s1, L_8080027C
    if (ctx->r6 != ctx->r17) {
        // 0x808002A0: sw          $t0, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->r8;
            goto L_8080027C;
    }
    // 0x808002A0: sw          $t0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r8;
    // 0x808002A4: beq         $s1, $s4, L_80800330
    if (ctx->r17 == ctx->r20) {
        // 0x808002A8: sll         $a1, $s1, 2
        ctx->r5 = S32(ctx->r17 << 2);
            goto L_80800330;
    }
L_808002A8:
    // 0x808002A8: sll         $a1, $s1, 2
    ctx->r5 = S32(ctx->r17 << 2);
    // 0x808002AC: lw          $t3, 0x98($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X98);
    // 0x808002B0: addiu       $t1, $sp, 0x88
    ctx->r9 = ADD32(ctx->r29, 0X88);
    // 0x808002B4: addiu       $t2, $sp, 0x68
    ctx->r10 = ADD32(ctx->r29, 0X68);
    // 0x808002B8: addiu       $t4, $sp, 0x58
    ctx->r12 = ADD32(ctx->r29, 0X58);
    // 0x808002BC: addu        $v1, $a1, $t4
    ctx->r3 = ADD32(ctx->r5, ctx->r12);
    // 0x808002C0: addu        $a0, $a1, $t2
    ctx->r4 = ADD32(ctx->r5, ctx->r10);
    // 0x808002C4: addu        $v0, $a1, $t1
    ctx->r2 = ADD32(ctx->r5, ctx->r9);
    // 0x808002C8: addu        $s0, $t3, $a1
    ctx->r16 = ADD32(ctx->r11, ctx->r5);
L_808002CC:
    // 0x808002CC: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x808002D0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x808002D4: addiu       $t6, $s1, 0x1
    ctx->r14 = ADD32(ctx->r17, 0X1);
    // 0x808002D8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x808002DC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x808002E0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x808002E4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x808002E8: addiu       $t8, $s1, 0x2
    ctx->r24 = ADD32(ctx->r17, 0X2);
    // 0x808002EC: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x808002F0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x808002F4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x808002F8: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x808002FC: addiu       $t0, $s1, 0x3
    ctx->r8 = ADD32(ctx->r17, 0X3);
    // 0x80800300: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
    // 0x80800304: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x80800308: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8080030C: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x80800310: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800314: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x80800318: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8080031C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80800320: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80800324: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80800328: bne         $s1, $s4, L_808002CC
    if (ctx->r17 != ctx->r20) {
        // 0x8080032C: sw          $t1, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->r9;
            goto L_808002CC;
    }
    // 0x8080032C: sw          $t1, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r9;
L_80800330:
    // 0x80800330: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80800334:
    // 0x80800334: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x80800338: addiu       $s0, $sp, 0x68
    ctx->r16 = ADD32(ctx->r29, 0X68);
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800340: bne         $t2, $zero, L_8080036C
    if (ctx->r10 != 0) {
        // 0x80800344: addiu       $a1, $sp, 0x88
        ctx->r5 = ADD32(ctx->r29, 0X88);
            goto L_8080036C;
    }
    // 0x80800344: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x80800348: addiu       $s0, $sp, 0x68
    ctx->r16 = ADD32(ctx->r29, 0X68);
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800350: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x80800354: jal         0x80800000
    // 0x80800358: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    sumultiscore_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800358: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_0:
    // 0x8080035C: jal         0x800AA200
    // 0x80800360: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800AA200(rdram, ctx);
        goto after_1;
    // 0x80800360: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800364: b           L_80800380
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080036C:
    // 0x8080036C: jal         0x808000A0
    // 0x80800370: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    sumultiscore_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800370: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_2:
    // 0x80800374: jal         0x800AA200
    // 0x80800378: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800AA200(rdram, ctx);
        goto after_3;
    // 0x80800378: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800380:
    // 0x80800380: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80800384: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x80800388: jal         0x80800140
    // 0x8080038C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_80800140_sumultiscore(rdram, ctx);
        goto after_4;
    // 0x8080038C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_4:
    // 0x80800390: blez        $s4, L_808004D0
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80800394: andi        $a3, $s4, 0x3
        ctx->r7 = ctx->r20 & 0X3;
            goto L_808004D0;
    }
    // 0x80800394: andi        $a3, $s4, 0x3
    ctx->r7 = ctx->r20 & 0X3;
    // 0x80800398: beq         $a3, $zero, L_808003FC
    if (ctx->r7 == 0) {
        // 0x8080039C: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_808003FC;
    }
    // 0x8080039C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x808003A0: sll         $a1, $s1, 2
    ctx->r5 = S32(ctx->r17 << 2);
    // 0x808003A4: addiu       $t3, $sp, 0x88
    ctx->r11 = ADD32(ctx->r29, 0X88);
    // 0x808003A8: addiu       $t4, $sp, 0x58
    ctx->r12 = ADD32(ctx->r29, 0X58);
    // 0x808003AC: addiu       $t5, $sp, 0x78
    ctx->r13 = ADD32(ctx->r29, 0X78);
    // 0x808003B0: addu        $a0, $a1, $t5
    ctx->r4 = ADD32(ctx->r5, ctx->r13);
    // 0x808003B4: addu        $v1, $a1, $t4
    ctx->r3 = ADD32(ctx->r5, ctx->r12);
    // 0x808003B8: addu        $v0, $a1, $t3
    ctx->r2 = ADD32(ctx->r5, ctx->r11);
L_808003BC:
    // 0x808003BC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x808003C0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x808003C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808003C8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808003CC: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x808003D0: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x808003D4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x808003D8: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x808003DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808003E0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x808003E4: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x808003E8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808003EC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808003F0: bne         $a2, $s1, L_808003BC
    if (ctx->r6 != ctx->r17) {
        // 0x808003F4: sw          $t0, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r8;
            goto L_808003BC;
    }
    // 0x808003F4: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x808003F8: beq         $s1, $s4, L_808004D0
    if (ctx->r17 == ctx->r20) {
        // 0x808003FC: sll         $a1, $s1, 2
        ctx->r5 = S32(ctx->r17 << 2);
            goto L_808004D0;
    }
L_808003FC:
    // 0x808003FC: sll         $a1, $s1, 2
    ctx->r5 = S32(ctx->r17 << 2);
    // 0x80800400: addiu       $t7, $sp, 0x78
    ctx->r15 = ADD32(ctx->r29, 0X78);
    // 0x80800404: addiu       $t4, $sp, 0x88
    ctx->r12 = ADD32(ctx->r29, 0X88);
    // 0x80800408: addiu       $t5, $sp, 0x58
    ctx->r13 = ADD32(ctx->r29, 0X58);
    // 0x8080040C: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x80800410: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x80800414: addu        $v1, $a1, $t5
    ctx->r3 = ADD32(ctx->r5, ctx->r13);
    // 0x80800418: addu        $v0, $a1, $t4
    ctx->r2 = ADD32(ctx->r5, ctx->r12);
    // 0x8080041C: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
L_80800420:
    // 0x80800420: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80800424: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800428: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8080042C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80800430: addu        $t2, $s2, $t1
    ctx->r10 = ADD32(ctx->r18, ctx->r9);
    // 0x80800434: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80800438: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8080043C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80800440: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80800444: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80800448: addu        $t5, $s3, $t4
    ctx->r13 = ADD32(ctx->r19, ctx->r12);
    // 0x8080044C: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    // 0x80800450: lw          $t7, -0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, -0XC);
    // 0x80800454: lw          $t8, -0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, -0XC);
    // 0x80800458: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8080045C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80800460: addu        $t1, $s2, $t9
    ctx->r9 = ADD32(ctx->r18, ctx->r25);
    // 0x80800464: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80800468: lw          $t2, -0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, -0XC);
    // 0x8080046C: lw          $t6, -0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XC);
    // 0x80800470: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80800474: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x80800478: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8080047C: lw          $t5, -0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X8);
    // 0x80800480: lw          $t0, -0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, -0X8);
    // 0x80800484: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80800488: addu        $t9, $s2, $t7
    ctx->r25 = ADD32(ctx->r18, ctx->r15);
    // 0x8080048C: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x80800490: lw          $t1, -0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, -0X8);
    // 0x80800494: lw          $t8, -0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X8);
    // 0x80800498: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8080049C: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x808004A0: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x808004A4: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x808004A8: lw          $t6, -0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, -0X4);
    // 0x808004AC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x808004B0: addu        $t7, $s2, $t5
    ctx->r15 = ADD32(ctx->r18, ctx->r13);
    // 0x808004B4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x808004B8: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x808004BC: lw          $t0, -0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, -0X4);
    // 0x808004C0: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x808004C4: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x808004C8: bne         $a0, $a2, L_80800420
    if (ctx->r4 != ctx->r6) {
        // 0x808004CC: sw          $t0, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r8;
            goto L_80800420;
    }
    // 0x808004CC: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
L_808004D0:
    // 0x808004D0: jal         0x800D3948
    // 0x808004D4: nop

    func_800D3948(rdram, ctx);
        goto after_5;
    // 0x808004D4: nop

    after_5:
    // 0x808004D8: beql        $v0, $zero, L_80800514
    if (ctx->r2 == 0) {
        // 0x808004DC: lw          $t8, 0x78($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X78);
            goto L_80800514;
    }
    goto skip_0;
    // 0x808004DC: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    skip_0:
    // 0x808004E0: jal         0x80088368
    // 0x808004E4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x808004E4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_6:
    // 0x808004E8: blez        $v0, L_80800510
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808004EC: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80800510;
    }
    // 0x808004EC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808004F0: lw          $s0, 0x98($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X98);
L_808004F4:
    // 0x808004F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004F8: jal         0x800AA20C
    // 0x808004FC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800AA20C(rdram, ctx);
        goto after_7;
    // 0x808004FC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x80800500: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800504: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80800508: bne         $at, $zero, L_808004F4
    if (ctx->r1 != 0) {
        // 0x8080050C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808004F4;
    }
    // 0x8080050C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80800510:
    // 0x80800510: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
L_80800514:
    // 0x80800514: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80800518: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080051C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800520: bne         $t8, $t3, L_80800530
    if (ctx->r24 != ctx->r11) {
        // 0x80800524: lw          $s2, 0x20($sp)
        ctx->r18 = MEM_W(ctx->r29, 0X20);
            goto L_80800530;
    }
    // 0x80800524: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800528: b           L_80800538
    // 0x8080052C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800538;
    // 0x8080052C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800530:
    // 0x80800530: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x80800534: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80800538:
    // 0x80800538: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080053C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800540: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800544: jr          $ra
    // 0x80800548: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80800548: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_8080025C_chstinger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080025C: jr          $ra
    // 0x80800260: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800260: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808000A8_chminelobbydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B0: jal         0x808000D0
    // 0x808000B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808000D0_chminelobbydoor(rdram, ctx);
        goto after_0;
    // 0x808000B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000B8: jal         0x80086240
    // 0x808000BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chdoor_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808000BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808000C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000C8: jr          $ra
    // 0x808000CC: nop

    return;
    // 0x808000CC: nop

;}
RECOMP_FUNC void bswasher_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002B4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808002B8: jal         0x800B5BE4
    // 0x808002BC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x808002BC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x808002C0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808002C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808002C8: jal         0x8009C128
    // 0x808002CC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x808002CC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x808002D0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(443, 0X1D60) << 16);
    // 0x808002D4: addiu       $t6, $t6, 0x1D60
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(443, 0X1D60));
    // 0x808002D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808002DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002E0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808002E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808002E8: jal         0x800BABB8
    // 0x808002EC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x808002EC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x808002F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002F8: jr          $ra
    // 0x808002FC: nop

    return;
    // 0x808002FC: nop

;}
RECOMP_FUNC void func_8080016C_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080016C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800170: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800174: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800178: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8080017C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800180: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800184: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800188: jal         0x80100094
    // 0x8080018C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080018C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800190: lhu         $t6, 0x72($s3)
    ctx->r14 = MEM_HU(ctx->r19, 0X72);
    // 0x80800194: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800198: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080019C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808001A0: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x808001A4: beq         $at, $zero, L_80800304
    if (ctx->r1 == 0) {
        // 0x808001A8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800304;
    }
    // 0x808001A8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808001AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1016, 0X1E60) << 16);
    // 0x808001B0: addu        $at, $at, $t8
    gpr jr_addend_808001B8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808001B4: lw          $t8, 0x1E60($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1016, 0X1E60));
    // 0x808001B8: jr          $t8
    // 0x808001BC: nop

    switch (jr_addend_808001B8 >> 2) {
        case 0: goto L_80800304; break;
        case 1: goto L_80800304; break;
        case 2: goto L_808001C0; break;
        case 3: goto L_808002A8; break;
        case 4: goto L_80800304; break;
        case 5: goto L_80800304; break;
        default: switch_error(__func__, 0x808001B8, 0x80801E60);
    }
    // 0x808001BC: nop

L_808001C0:
    // 0x808001C0: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x808001C4: addiu       $a0, $zero, 0xC2
    ctx->r4 = ADD32(0, 0XC2);
    // 0x808001C8: jal         0x800D24E8
    // 0x808001CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D24E8(rdram, ctx);
        goto after_1;
    // 0x808001CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808001D0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x808001D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808001D8: addiu       $s1, $s2, 0x1C
    ctx->r17 = ADD32(ctx->r18, 0X1C);
    // 0x808001DC: blezl       $t9, L_80800208
    if (SIGNED(ctx->r25) <= 0) {
        // 0x808001E0: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800208;
    }
    goto skip_0;
    // 0x808001E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_0:
L_808001E4:
    // 0x808001E4: jal         0x800D90A4
    // 0x808001E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D90A4(rdram, ctx);
        goto after_2;
    // 0x808001E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x808001EC: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x808001F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808001F4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x808001F8: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x808001FC: bne         $at, $zero, L_808001E4
    if (ctx->r1 != 0) {
        // 0x80800200: nop
    
            goto L_808001E4;
    }
    // 0x80800200: nop

    // 0x80800204: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80800208:
    // 0x80800208: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080020C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800210: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800214: jal         0x800DC178
    // 0x80800218: nop

    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800218: nop

    after_3:
    // 0x8080021C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800220: jal         0x800D9154
    // 0x80800224: addiu       $a0, $s3, 0x58
    ctx->r4 = ADD32(ctx->r19, 0X58);
    func_800D9154(rdram, ctx);
        goto after_4;
    // 0x80800224: addiu       $a0, $s3, 0x58
    ctx->r4 = ADD32(ctx->r19, 0X58);
    after_4:
    // 0x80800228: beq         $v0, $zero, L_80800238
    if (ctx->r2 == 0) {
        // 0x8080022C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800238;
    }
    // 0x8080022C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800230: jal         0x80108B04
    // 0x80800234: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80108B04(rdram, ctx);
        goto after_5;
    // 0x80800234: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_5:
L_80800238:
    // 0x80800238: lw          $a0, 0x6C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X6C);
    // 0x8080023C: andi        $t1, $a0, 0x1FF
    ctx->r9 = ctx->r4 & 0X1FF;
    // 0x80800240: jal         0x800CEAD0
    // 0x80800244: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_6;
    // 0x80800244: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_6:
    // 0x80800248: beq         $v0, $zero, L_80800304
    if (ctx->r2 == 0) {
        // 0x8080024C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800304;
    }
    // 0x8080024C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800250: jal         0x808007A4
    // 0x80800254: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    func_808007A4_chhoopswoop(rdram, ctx);
        goto after_7;
    // 0x80800254: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    after_7:
    // 0x80800258: jal         0x800F54E4
    // 0x8080025C: sw          $v0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x8080025C: sw          $v0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r2;
    after_8:
    // 0x80800260: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800264: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800268: jal         0x800F7ECC
    // 0x8080026C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800F7ECC(rdram, ctx);
        goto after_9;
    // 0x8080026C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_9:
    // 0x80800270: jal         0x800F54E4
    // 0x80800274: nop

    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x80800274: nop

    after_10:
    // 0x80800278: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080027C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800280: jal         0x800F8300
    // 0x80800284: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F8300(rdram, ctx);
        goto after_11;
    // 0x80800284: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x80800288: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8080028C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800290: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800294: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800298: jal         0x80101FDC
    // 0x8080029C: swc1        $f4, 0x9F8($s2)
    MEM_W(0X9F8, ctx->r18) = ctx->f4.u32l;
    func_80101FDC(rdram, ctx);
        goto after_12;
    // 0x8080029C: swc1        $f4, 0x9F8($s2)
    MEM_W(0X9F8, ctx->r18) = ctx->f4.u32l;
    after_12:
    // 0x808002A0: b           L_80800308
    // 0x808002A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800308;
    // 0x808002A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808002A8:
    // 0x808002A8: jal         0x8008A2E8
    // 0x808002AC: nop

    _susubgame_entrypoint_9(rdram, ctx);
        goto after_13;
    // 0x808002AC: nop

    after_13:
    // 0x808002B0: bnel        $v0, $zero, L_808002C8
    if (ctx->r2 != 0) {
        // 0x808002B4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_808002C8;
    }
    goto skip_1;
    // 0x808002B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_1:
    // 0x808002B8: jal         0x800D9078
    // 0x808002BC: addiu       $a0, $s2, 0x9F8
    ctx->r4 = ADD32(ctx->r18, 0X9F8);
    func_800D9078(rdram, ctx);
        goto after_14;
    // 0x808002BC: addiu       $a0, $s2, 0x9F8
    ctx->r4 = ADD32(ctx->r18, 0X9F8);
    after_14:
    // 0x808002C0: beq         $v0, $zero, L_80800304
    if (ctx->r2 == 0) {
        // 0x808002C4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800304;
    }
    // 0x808002C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_808002C8:
    // 0x808002C8: addiu       $a1, $s2, 0x4C4
    ctx->r5 = ADD32(ctx->r18, 0X4C4);
    // 0x808002CC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808002D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808002D4: jal         0x8008A2C8
    // 0x808002D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_15;
    // 0x808002D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_15:
    // 0x808002DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808002E0: jal         0x80101FDC
    // 0x808002E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_16;
    // 0x808002E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_16:
    // 0x808002E8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x808002EC: lw          $a1, 0xC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XC);
    // 0x808002F0: lw          $a2, 0x10($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X10);
    // 0x808002F4: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x808002F8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808002FC: jal         0x8008A208
    // 0x80800300: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_17;
    // 0x80800300: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_17:
L_80800304:
    // 0x80800304: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800308:
    // 0x80800308: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080030C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800310: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800314: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800318: jr          $ra
    // 0x8080031C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080031C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void bsblongleg_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012E0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808012E4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(104, 0X14C0) << 16);
    // 0x808012E8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808012EC: jr          $ra
    // 0x808012F0: lw          $v0, 0x14C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X14C0));
    return;
    // 0x808012F0: lw          $v0, 0x14C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X14C0));
;}
RECOMP_FUNC void chfreezy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080028C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800290: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800294: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800298: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8080029C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002A0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808002A4: sll         $t6, $v0, 14
    ctx->r14 = S32(ctx->r2 << 14);
    // 0x808002A8: srl         $v0, $t6, 31
    ctx->r2 = S32(U32(ctx->r14) >> 31);
    // 0x808002AC: bnel        $v0, $zero, L_80800374
    if (ctx->r2 != 0) {
        // 0x808002B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800374;
    }
    goto skip_0;
    // 0x808002B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808002B4: lbu         $v1, 0x74($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X74);
    // 0x808002B8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808002BC: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x808002C0: beq         $t8, $zero, L_808002E0
    if (ctx->r24 == 0) {
        // 0x808002C4: andi        $t9, $v1, 0xFFFE
        ctx->r25 = ctx->r3 & 0XFFFE;
            goto L_808002E0;
    }
    // 0x808002C4: andi        $t9, $v1, 0xFFFE
    ctx->r25 = ctx->r3 & 0XFFFE;
    // 0x808002C8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1044, 0X748) << 16);
    // 0x808002CC: sb          $t9, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r25;
    // 0x808002D0: jal         0x80089D18
    // 0x808002D4: addiu       $a2, $a2, 0x748
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1044, 0X748));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808002D4: addiu       $a2, $a2, 0x748
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1044, 0X748));
    after_0:
    // 0x808002D8: b           L_80800374
    // 0x808002DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800374;
    // 0x808002DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002E0:
    // 0x808002E0: bnel        $v0, $zero, L_80800374
    if (ctx->r2 != 0) {
        // 0x808002E4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800374;
    }
    goto skip_1;
    // 0x808002E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808002E8: lw          $t0, 0x78($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X78);
    // 0x808002EC: sll         $t2, $t0, 29
    ctx->r10 = S32(ctx->r8 << 29);
    // 0x808002F0: bltzl       $t2, L_80800374
    if (SIGNED(ctx->r10) < 0) {
        // 0x808002F4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800374;
    }
    goto skip_2;
    // 0x808002F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808002F8: lh          $t3, 0x0($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X0);
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800304: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80800308: lh          $t4, 0x2($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X2);
    // 0x8080030C: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80800310: lh          $t5, 0x4($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X4);
    // 0x80800314: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80800318: lbu         $t7, 0x7B($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X7B);
    // 0x8080031C: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x80800320: jal         0x80102190
    // 0x80800324: sb          $t8, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r24;
    func_80102190(rdram, ctx);
        goto after_1;
    // 0x80800324: sb          $t8, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r24;
    after_1:
    // 0x80800328: jal         0x8010A570
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800334: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800338: jal         0x8010108C
    // 0x8080033C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_3;
    // 0x8080033C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800340: jal         0x80089B80
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sufreezy_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800348: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8080034C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800350: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800354: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800358: addiu       $a0, $a0, 0x5F88
    ctx->r4 = ADD32(ctx->r4, 0X5F88);
    // 0x8080035C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800360: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80800364: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800368: jal         0x80086D50
    // 0x8080036C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x8080036C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_5:
    // 0x80800370: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800374:
    // 0x80800374: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800378: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080037C: jr          $ra
    // 0x80800380: nop

    return;
    // 0x80800380: nop

;}
RECOMP_FUNC void bsmumswim_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A5C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800A60: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(332, 0XB60) << 16);
    // 0x80800A64: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800A68: jr          $ra
    // 0x80800A6C: lw          $v0, 0xB60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(332, 0XB60));
    return;
    // 0x80800A6C: lw          $v0, 0xB60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(332, 0XB60));
;}
RECOMP_FUNC void suautobaddies_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808000B4: jal         0x80088838
    // 0x808000B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    _glcutDll_entrypoint_18(rdram, ctx);
        goto after_0;
    // 0x808000B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x808000BC: addiu       $s1, $sp, 0x28
    ctx->r17 = ADD32(ctx->r29, 0X28);
    // 0x808000C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808000C4: jal         0x801067C4
    // 0x808000C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_801067C4(rdram, ctx);
        goto after_1;
    // 0x808000C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808000CC: beq         $v0, $zero, L_808000F0
    if (ctx->r2 == 0) {
        // 0x808000D0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808000F0;
    }
    // 0x808000D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_808000D4:
    // 0x808000D4: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    // 0x808000D8: jal         0x8010108C
    // 0x808000DC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8010108C(rdram, ctx);
        goto after_2;
    // 0x808000DC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x808000E0: jal         0x8010682C
    // 0x808000E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010682C(rdram, ctx);
        goto after_3;
    // 0x808000E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x808000E8: bne         $v0, $zero, L_808000D4
    if (ctx->r2 != 0) {
        // 0x808000EC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808000D4;
    }
    // 0x808000EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_808000F0:
    // 0x808000F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000FC: jr          $ra
    // 0x80800100: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800100: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80099AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099AA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80099AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80099AB0: jal         0x8009E6EC
    // 0x80099AB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80099AB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80099AB8: slti        $at, $v0, 0x34
    ctx->r1 = SIGNED(ctx->r2) < 0X34 ? 1 : 0;
    // 0x80099ABC: bne         $at, $zero, L_80099AE8
    if (ctx->r1 != 0) {
        // 0x80099AC0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80099AE8;
    }
    // 0x80099AC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80099AC4: addiu       $t6, $v0, -0x4D
    ctx->r14 = ADD32(ctx->r2, -0X4D);
    // 0x80099AC8: sltiu       $at, $t6, 0x4E
    ctx->r1 = ctx->r14 < 0X4E ? 1 : 0;
    // 0x80099ACC: beq         $at, $zero, L_80099B2C
    if (ctx->r1 == 0) {
        // 0x80099AD0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80099B2C;
    }
    // 0x80099AD0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80099AD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099AD8: addu        $at, $at, $t6
    gpr jr_addend_80099AE0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80099ADC: lw          $t6, 0x4E70($at)
    ctx->r14 = ADD32(ctx->r1, 0X4E70);
    // 0x80099AE0: jr          $t6
    // 0x80099AE4: nop

    switch (jr_addend_80099AE0 >> 2) {
        case 0: goto L_80099B1C; break;
        case 1: goto L_80099B2C; break;
        case 2: goto L_80099B2C; break;
        case 3: goto L_80099B2C; break;
        case 4: goto L_80099B2C; break;
        case 5: goto L_80099B2C; break;
        case 6: goto L_80099B2C; break;
        case 7: goto L_80099B2C; break;
        case 8: goto L_80099B2C; break;
        case 9: goto L_80099B2C; break;
        case 10: goto L_80099B2C; break;
        case 11: goto L_80099B2C; break;
        case 12: goto L_80099B2C; break;
        case 13: goto L_80099B2C; break;
        case 14: goto L_80099B2C; break;
        case 15: goto L_80099B2C; break;
        case 16: goto L_80099B2C; break;
        case 17: goto L_80099B2C; break;
        case 18: goto L_80099B2C; break;
        case 19: goto L_80099B2C; break;
        case 20: goto L_80099B2C; break;
        case 21: goto L_80099B1C; break;
        case 22: goto L_80099B1C; break;
        case 23: goto L_80099B2C; break;
        case 24: goto L_80099B2C; break;
        case 25: goto L_80099B2C; break;
        case 26: goto L_80099B2C; break;
        case 27: goto L_80099B2C; break;
        case 28: goto L_80099B2C; break;
        case 29: goto L_80099B2C; break;
        case 30: goto L_80099B1C; break;
        case 31: goto L_80099B1C; break;
        case 32: goto L_80099B2C; break;
        case 33: goto L_80099B2C; break;
        case 34: goto L_80099B2C; break;
        case 35: goto L_80099B2C; break;
        case 36: goto L_80099B2C; break;
        case 37: goto L_80099B2C; break;
        case 38: goto L_80099B2C; break;
        case 39: goto L_80099B2C; break;
        case 40: goto L_80099B2C; break;
        case 41: goto L_80099B2C; break;
        case 42: goto L_80099B2C; break;
        case 43: goto L_80099B2C; break;
        case 44: goto L_80099B2C; break;
        case 45: goto L_80099B2C; break;
        case 46: goto L_80099B2C; break;
        case 47: goto L_80099B1C; break;
        case 48: goto L_80099B1C; break;
        case 49: goto L_80099B2C; break;
        case 50: goto L_80099B2C; break;
        case 51: goto L_80099B2C; break;
        case 52: goto L_80099B1C; break;
        case 53: goto L_80099B2C; break;
        case 54: goto L_80099B2C; break;
        case 55: goto L_80099B2C; break;
        case 56: goto L_80099B2C; break;
        case 57: goto L_80099B2C; break;
        case 58: goto L_80099B2C; break;
        case 59: goto L_80099B2C; break;
        case 60: goto L_80099B1C; break;
        case 61: goto L_80099B2C; break;
        case 62: goto L_80099B2C; break;
        case 63: goto L_80099B2C; break;
        case 64: goto L_80099B2C; break;
        case 65: goto L_80099B2C; break;
        case 66: goto L_80099B2C; break;
        case 67: goto L_80099B2C; break;
        case 68: goto L_80099B1C; break;
        case 69: goto L_80099B2C; break;
        case 70: goto L_80099B2C; break;
        case 71: goto L_80099B2C; break;
        case 72: goto L_80099B2C; break;
        case 73: goto L_80099B2C; break;
        case 74: goto L_80099B2C; break;
        case 75: goto L_80099B1C; break;
        case 76: goto L_80099B2C; break;
        case 77: goto L_80099B1C; break;
        default: switch_error(__func__, 0x80099AE0, 0x80124E70);
    }
    // 0x80099AE4: nop

L_80099AE8:
    // 0x80099AE8: addiu       $t7, $v0, -0xF
    ctx->r15 = ADD32(ctx->r2, -0XF);
    // 0x80099AEC: sltiu       $at, $t7, 0x25
    ctx->r1 = ctx->r15 < 0X25 ? 1 : 0;
    // 0x80099AF0: beq         $at, $zero, L_80099B2C
    if (ctx->r1 == 0) {
        // 0x80099AF4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80099B2C;
    }
    // 0x80099AF4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80099AF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099AFC: addu        $at, $at, $t7
    gpr jr_addend_80099B04 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80099B00: lw          $t7, 0x4FA8($at)
    ctx->r15 = ADD32(ctx->r1, 0X4FA8);
    // 0x80099B04: jr          $t7
    // 0x80099B08: nop

    switch (jr_addend_80099B04 >> 2) {
        case 0: goto L_80099B0C; break;
        case 1: goto L_80099B2C; break;
        case 2: goto L_80099B2C; break;
        case 3: goto L_80099B2C; break;
        case 4: goto L_80099B0C; break;
        case 5: goto L_80099B2C; break;
        case 6: goto L_80099B2C; break;
        case 7: goto L_80099B2C; break;
        case 8: goto L_80099B2C; break;
        case 9: goto L_80099B2C; break;
        case 10: goto L_80099B2C; break;
        case 11: goto L_80099B2C; break;
        case 12: goto L_80099B2C; break;
        case 13: goto L_80099B2C; break;
        case 14: goto L_80099B2C; break;
        case 15: goto L_80099B2C; break;
        case 16: goto L_80099B2C; break;
        case 17: goto L_80099B2C; break;
        case 18: goto L_80099B2C; break;
        case 19: goto L_80099B2C; break;
        case 20: goto L_80099B2C; break;
        case 21: goto L_80099B2C; break;
        case 22: goto L_80099B2C; break;
        case 23: goto L_80099B0C; break;
        case 24: goto L_80099B1C; break;
        case 25: goto L_80099B2C; break;
        case 26: goto L_80099B2C; break;
        case 27: goto L_80099B0C; break;
        case 28: goto L_80099B2C; break;
        case 29: goto L_80099B2C; break;
        case 30: goto L_80099B2C; break;
        case 31: goto L_80099B2C; break;
        case 32: goto L_80099B2C; break;
        case 33: goto L_80099B0C; break;
        case 34: goto L_80099B1C; break;
        case 35: goto L_80099B1C; break;
        case 36: goto L_80099B1C; break;
        default: switch_error(__func__, 0x80099B04, 0x80124FA8);
    }
    // 0x80099B08: nop

L_80099B0C:
    // 0x80099B0C: jal         0x8009989C
    // 0x80099B10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8009989C(rdram, ctx);
        goto after_1;
    // 0x80099B10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80099B14: b           L_80099B30
    // 0x80099B18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80099B30;
    // 0x80099B18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80099B1C:
    // 0x80099B1C: jal         0x80099B94
    // 0x80099B20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099B94(rdram, ctx);
        goto after_2;
    // 0x80099B20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80099B24: b           L_80099B48
    // 0x80099B28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80099B48;
    // 0x80099B28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80099B2C:
    // 0x80099B2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80099B30:
    // 0x80099B30: jal         0x8009E830
    // 0x80099B34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E830(rdram, ctx);
        goto after_3;
    // 0x80099B34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80099B38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80099B3C: jal         0x8009E5C8
    // 0x80099B40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80099B40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80099B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80099B48:
    // 0x80099B48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80099B4C: jr          $ra
    // 0x80099B50: nop

    return;
    // 0x80099B50: nop

;}
RECOMP_FUNC void gccubesearch_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808000D8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x808000DC: jal         0x808006C4
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gccubesearch_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000E4: beq         $v0, $zero, L_8080010C
    if (ctx->r2 == 0) {
        // 0x808000E8: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_8080010C;
    }
    // 0x808000E8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808000EC: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x808000F0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x808000F4: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x808000F8: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x808000FC: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x80800100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800104: b           L_80800110
    // 0x80800108: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
        goto L_80800110;
    // 0x80800108: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
L_8080010C:
    // 0x8080010C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800110:
    // 0x80800110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800118: jr          $ra
    // 0x8080011C: nop

    return;
    // 0x8080011C: nop

;}
RECOMP_FUNC void _chexploder_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800866B0: syscall     354
    recomp_syscall_handler(rdram, ctx, 0x800866B0);
    return;
    // 0x800866B4: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_800CA6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA6F0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800CA6F4: jr          $ra
    // 0x800CA6F8: swc1        $f12, 0x164($a0)
    MEM_W(0X164, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x800CA6F8: swc1        $f12, 0x164($a0)
    MEM_W(0X164, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800000_glsplineDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800014: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80800018: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080001C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80800020: bne         $t6, $zero, L_808000AC
    if (ctx->r14 != 0) {
        // 0x80800024: sll         $t7, $v0, 25
        ctx->r15 = S32(ctx->r2 << 25);
            goto L_808000AC;
    }
    // 0x80800024: sll         $t7, $v0, 25
    ctx->r15 = S32(ctx->r2 << 25);
    // 0x80800028: srl         $t8, $t7, 26
    ctx->r24 = S32(U32(ctx->r15) >> 26);
    // 0x8080002C: bnel        $t8, $at, L_808000B0
    if (ctx->r24 != ctx->r1) {
        // 0x80800030: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808000B0;
    }
    goto skip_0;
    // 0x80800030: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800034: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80800038: sll         $t0, $t9, 22
    ctx->r8 = S32(ctx->r25 << 22);
    // 0x8080003C: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x80800040: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80800044: lbu         $t3, 0xA($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XA);
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80800050: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80800054: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x80800058: sll         $t6, $t5, 18
    ctx->r14 = S32(ctx->r13 << 18);
    // 0x8080005C: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x80800060: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80800064: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80800068: sll         $t9, $t8, 18
    ctx->r25 = S32(ctx->r24 << 18);
    // 0x8080006C: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x80800070: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x80800074: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x80800078: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8080007C: srl         $t2, $t1, 23
    ctx->r10 = S32(U32(ctx->r9) >> 23);
    // 0x80800080: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80800084: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x80800088: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8080008C: sll         $t5, $t4, 9
    ctx->r13 = S32(ctx->r12 << 9);
    // 0x80800090: srl         $t6, $t5, 23
    ctx->r14 = S32(U32(ctx->r13) >> 23);
    // 0x80800094: jal         0x80088BD8
    // 0x80800098: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    _gspropctrl_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800098: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    after_0:
    // 0x8080009C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x808000A0: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x808000A4: b           L_808000B0
    // 0x808000A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000B0;
    // 0x808000A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000AC:
    // 0x808000AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000B0:
    // 0x808000B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000BC: jr          $ra
    // 0x808000C0: nop

    return;
    // 0x808000C0: nop

;}
RECOMP_FUNC void _baeggsetup_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A70: syscall     126
    recomp_syscall_handler(rdram, ctx, 0x80084A70);
    return;
    // 0x80084A74: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void bsfirstp_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806B84: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80806B88: lw          $t6, 0x184($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X184);
    // 0x80806B8C: lw          $v1, 0x188($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X188);
    // 0x80806B90: sw          $t6, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->r14;
    // 0x80806B94: lw          $t7, 0x184($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X184);
    // 0x80806B98: jr          $ra
    // 0x80806B9C: sw          $t7, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r15;
    return;
    // 0x80806B9C: sw          $t7, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r15;
;}
RECOMP_FUNC void bsbabykaz_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009B0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808009B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(68, 0X1750) << 16);
    // 0x808009B8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808009BC: jr          $ra
    // 0x808009C0: lw          $v0, 0x1750($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(68, 0X1750));
    return;
    // 0x808009C0: lw          $v0, 0x1750($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(68, 0X1750));
;}
RECOMP_FUNC void func_80802E80_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802E80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80802E84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802E88: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80802E8C: jal         0x80802F14
    // 0x80802E90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802F14_chweldarboss(rdram, ctx);
        goto after_0;
    // 0x80802E90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80802E94: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80802E98: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80802E9C: jal         0x800EE7F8
    // 0x80802EA0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80802EA0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80802EA4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80802EA8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80802EAC: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    // 0x80802EB0: jal         0x800EF1B8
    // 0x80802EB4: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_2;
    // 0x80802EB4: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    after_2:
    // 0x80802EB8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80802EBC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802EC0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80802EC4: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80802EC8: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    // 0x80802ECC: jal         0x80089F20
    // 0x80802ED0: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80802ED0: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    after_3:
    // 0x80802ED4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80802ED8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80802EDC: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x80802EE0: jal         0x800EF1B8
    // 0x80802EE4: lw          $a1, 0x48($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_4;
    // 0x80802EE4: lw          $a1, 0x48($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X48);
    after_4:
    // 0x80802EE8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80802EEC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80802EF0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80802EF4: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80802EF8: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    // 0x80802EFC: jal         0x80089F20
    // 0x80802F00: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80802F00: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    after_5:
    // 0x80802F04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802F08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80802F0C: jr          $ra
    // 0x80802F10: nop

    return;
    // 0x80802F10: nop

;}
RECOMP_FUNC void baduo_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800058: jal         0x800A3274
    // 0x8080005C: nop

    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x8080005C: nop

    after_0:
    // 0x80800060: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800064: beq         $v0, $at, L_8080007C
    if (ctx->r2 == ctx->r1) {
        // 0x80800068: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8080007C;
    }
    // 0x80800068: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080006C: beq         $v0, $at, L_8080008C
    if (ctx->r2 == ctx->r1) {
        // 0x80800070: nop
    
            goto L_8080008C;
    }
    // 0x80800070: nop

    // 0x80800074: b           L_8080009C
    // 0x80800078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080009C;
    // 0x80800078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080007C:
    // 0x8080007C: jal         0x800878A0
    // 0x80800080: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800080: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_1:
    // 0x80800084: b           L_808000A0
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000A0;
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080008C:
    // 0x8080008C: jal         0x800878A0
    // 0x80800090: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800090: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_2:
    // 0x80800094: b           L_808000A0
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000A0;
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080009C:
    // 0x8080009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000A0:
    // 0x808000A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void func_80091030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091030: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80091034: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x80091038: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009103C: swc1        $f0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f0.u32l;
    // 0x80091040: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    // 0x80091044: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x80091048: lw          $t9, 0x30($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X30);
    // 0x8009104C: jr          $ra
    // 0x80091050: sb          $t8, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r24;
    return;
    // 0x80091050: sb          $t8, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r24;
;}
RECOMP_FUNC void func_800E7DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7DE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E7DE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E7DEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800E7DF0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800E7DF4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800E7DF8: jal         0x8001A0A8
    // 0x800E7DFC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8001A0A8(rdram, ctx);
        goto after_0;
    // 0x800E7DFC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800E7E00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E7E04: beq         $v0, $zero, L_800E7E60
    if (ctx->r2 == 0) {
        // 0x800E7E08: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_800E7E60;
    }
    // 0x800E7E08: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800E7E0C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800E7E10: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800E7E14: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x800E7E18: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800E7E1C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800E7E20: lh          $t7, 0x7750($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7750);
    // 0x800E7E24: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800E7E28: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800E7E2C: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x800E7E30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E7E34: addu        $t2, $t0, $at
    ctx->r10 = ADD32(ctx->r8, ctx->r1);
    // 0x800E7E38: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800E7E3C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800E7E40: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800E7E44: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800E7E48: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800E7E4C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800E7E50: jal         0x800BC5B0
    // 0x800E7E54: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_800BC5B0(rdram, ctx);
        goto after_1;
    // 0x800E7E54: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_1:
    // 0x800E7E58: jal         0x800E7CF4
    // 0x800E7E5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800E7CF4(rdram, ctx);
        goto after_2;
    // 0x800E7E5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
L_800E7E60:
    // 0x800E7E60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E7E64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E7E68: jr          $ra
    // 0x800E7E6C: nop

    return;
    // 0x800E7E6C: nop

;}
RECOMP_FUNC void func_800C775C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C775C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800C7760: addiu       $a2, $a2, 0x760C
    ctx->r6 = ADD32(ctx->r6, 0X760C);
    // 0x800C7764: lb          $v1, 0x1($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X1);
    // 0x800C7768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C776C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C7770: bne         $a1, $v1, L_800C77B4
    if (ctx->r5 != ctx->r3) {
        // 0x800C7774: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C77B4;
    }
    // 0x800C7774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7778: lbu         $a0, 0x0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X0);
    // 0x800C777C: beql        $a0, $zero, L_800C77B8
    if (ctx->r4 == 0) {
        // 0x800C7780: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_800C77B8;
    }
    goto skip_0;
    // 0x800C7780: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x800C7784: beql        $a0, $a1, L_800C77B8
    if (ctx->r4 == ctx->r5) {
        // 0x800C7788: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_800C77B8;
    }
    goto skip_1;
    // 0x800C7788: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    skip_1:
    // 0x800C778C: jal         0x800C75A0
    // 0x800C7790: nop

    func_800C75A0(rdram, ctx);
        goto after_0;
    // 0x800C7790: nop

    after_0:
    // 0x800C7794: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C7798: jal         0x800C7618
    // 0x800C779C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800C7618(rdram, ctx);
        goto after_1;
    // 0x800C779C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x800C77A0: jal         0x800FEC60
    // 0x800C77A4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800FEC60(rdram, ctx);
        goto after_2;
    // 0x800C77A4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_2:
    // 0x800C77A8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800C77AC: addiu       $a2, $a2, 0x760C
    ctx->r6 = ADD32(ctx->r6, 0X760C);
    // 0x800C77B0: lb          $v1, 0x1($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X1);
L_800C77B4:
    // 0x800C77B4: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
L_800C77B8:
    // 0x800C77B8: sb          $t6, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r14;
    // 0x800C77BC: lb          $t7, 0x1($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X1);
    // 0x800C77C0: bgezl       $t7, L_800C77D0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800C77C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C77D0;
    }
    goto skip_2;
    // 0x800C77C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800C77C8: sb          $zero, 0x1($a2)
    MEM_B(0X1, ctx->r6) = 0;
    // 0x800C77CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C77D0:
    // 0x800C77D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C77D4: jr          $ra
    // 0x800C77D8: nop

    return;
    // 0x800C77D8: nop

;}
RECOMP_FUNC void bsbflip_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005EC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808005F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(93, 0X620) << 16);
    // 0x808005F4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808005F8: jr          $ra
    // 0x808005FC: lw          $v0, 0x620($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(93, 0X620));
    return;
    // 0x808005FC: lw          $v0, 0x620($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(93, 0X620));
;}
RECOMP_FUNC void func_80110730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80110734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110738: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8011073C: sb          $a1, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r5;
    // 0x80110740: jal         0x80113410
    // 0x80110744: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80113410(rdram, ctx);
        goto after_0;
    // 0x80110744: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80110748: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8011074C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80110750: bnel        $t7, $zero, L_80110764
    if (ctx->r15 != 0) {
        // 0x80110754: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80110764;
    }
    goto skip_0;
    // 0x80110754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80110758: jal         0x8011337C
    // 0x8011075C: nop

    func_8011337C(rdram, ctx);
        goto after_1;
    // 0x8011075C: nop

    after_1:
    // 0x80110760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80110764:
    // 0x80110764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110768: jr          $ra
    // 0x8011076C: nop

    return;
    // 0x8011076C: nop

;}
RECOMP_FUNC void _bsmumswim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800838F0: syscall     81
    recomp_syscall_handler(rdram, ctx, 0x800838F0);
    return;
    // 0x800838F4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80013620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013620: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80013624: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80013628: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001362C: addiu       $t6, $t6, 0x75F0
    ctx->r14 = ADD32(ctx->r14, 0X75F0);
    // 0x80013630: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80013634: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80013638: lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // 0x8001363C: addiu       $a3, $a3, 0x3678
    ctx->r7 = ADD32(ctx->r7, 0X3678);
    // 0x80013640: addiu       $a1, $a1, 0x77A0
    ctx->r5 = ADD32(ctx->r5, 0X77A0);
    // 0x80013644: addiu       $a0, $a0, 0x75F0
    ctx->r4 = ADD32(ctx->r4, 0X75F0);
    // 0x80013648: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8001364C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80013650: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80013654: jal         0x8001DCB0
    // 0x80013658: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8001DCB0(rdram, ctx);
        goto after_0;
    // 0x80013658: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8001365C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80013660: jal         0x8002E510
    // 0x80013664: addiu       $a0, $a0, 0x75F0
    ctx->r4 = ADD32(ctx->r4, 0X75F0);
    osStartThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80013664: addiu       $a0, $a0, 0x75F0
    ctx->r4 = ADD32(ctx->r4, 0X75F0);
    after_1:
    // 0x80013668: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001366C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80013670: jr          $ra
    // 0x80013674: nop

    return;
    // 0x80013674: nop

;}
RECOMP_FUNC void func_80800000_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8009C128
    // 0x8080000C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8080000C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80800010: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80800014: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800018: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080001C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800020: jal         0x800DC178
    // 0x80800024: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800024: nop

    after_1:
    // 0x80800028: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080002C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800030: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800034: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800038: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8080003C: jal         0x800DC178
    // 0x80800040: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800040: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80800044: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800048: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080004C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800050: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80800054: add.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x80800058: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080005C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800060: jal         0x800DC178
    // 0x80800064: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800064: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80800068: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080006C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(76, 0XDC0) << 16);
    // 0x80800070: addiu       $t6, $t6, 0xDC0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(76, 0XDC0));
    // 0x80800074: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80800078: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080007C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800084: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80800088: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080008C: jal         0x800BBCB8
    // 0x80800090: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x80800090: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80800094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800098: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080009C: jr          $ra
    // 0x808000A0: nop

    return;
    // 0x808000A0: nop

;}
RECOMP_FUNC void func_80800988_chfactoryprop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800988: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080098C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800990: jal         0x800DB9B0
    // 0x80800994: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    func_800DB9B0(rdram, ctx);
        goto after_0;
    // 0x80800994: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800998: bne         $v0, $zero, L_808009B0
    if (ctx->r2 != 0) {
        // 0x8080099C: nop
    
            goto L_808009B0;
    }
    // 0x8080099C: nop

    // 0x808009A0: jal         0x8008FE68
    // 0x808009A4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_8008FE68(rdram, ctx);
        goto after_1;
    // 0x808009A4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x808009A8: b           L_808009BC
    // 0x808009AC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_808009BC;
    // 0x808009AC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_808009B0:
    // 0x808009B0: jal         0x800E3980
    // 0x808009B4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800E3980(rdram, ctx);
        goto after_2;
    // 0x808009B4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x808009B8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_808009BC:
    // 0x808009BC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808009C0: jal         0x800EE7F8
    // 0x808009C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808009C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
    // 0x808009C8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808009CC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x808009D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808009D4: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x808009D8: lbu         $t7, 0x5F($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5F);
    // 0x808009DC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808009E0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1124, 0XD24) << 16);
    // 0x808009E4: bne         $t7, $zero, L_808009FC
    if (ctx->r15 != 0) {
        // 0x808009E8: nop
    
            goto L_808009FC;
    }
    // 0x808009E8: nop

    // 0x808009EC: jal         0x800C4350
    // 0x808009F0: addiu       $a2, $a2, 0xD24
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1124, 0XD24));
    func_800C4350(rdram, ctx);
        goto after_4;
    // 0x808009F0: addiu       $a2, $a2, 0xD24
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1124, 0XD24));
    after_4:
    // 0x808009F4: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x808009F8: sb          $v0, 0x5F($t8)
    MEM_B(0X5F, ctx->r24) = ctx->r2;
L_808009FC:
    // 0x808009FC: jal         0x800EA05C
    // 0x80800A00: nop

    func_800EA05C(rdram, ctx);
        goto after_5;
    // 0x80800A00: nop

    after_5:
    // 0x80800A04: addiu       $at, $zero, 0x10F
    ctx->r1 = ADD32(0, 0X10F);
    // 0x80800A08: beq         $v0, $at, L_80800A24
    if (ctx->r2 == ctx->r1) {
        // 0x80800A0C: lwc1        $f8, 0x30($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
            goto L_80800A24;
    }
    // 0x80800A0C: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800A10: addiu       $at, $zero, 0x110
    ctx->r1 = ADD32(0, 0X110);
    // 0x80800A14: beq         $v0, $at, L_80800A7C
    if (ctx->r2 == ctx->r1) {
        // 0x80800A18: lw          $t0, 0x48($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X48);
            goto L_80800A7C;
    }
    // 0x80800A18: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80800A1C: b           L_80800AD4
    // 0x80800A20: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
        goto L_80800AD4;
    // 0x80800A20: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
L_80800A24:
    // 0x80800A24: lui         $at, 0xC496
    ctx->r1 = S32(0XC496 << 16);
    // 0x80800A28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A2C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800A30: lui         $a3, 0x469C
    ctx->r7 = S32(0X469C << 16);
    // 0x80800A34: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800A38: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80800A3C: lui         $a2, 0xC448
    ctx->r6 = S32(0XC448 << 16);
    // 0x80800A40: addiu       $a1, $zero, 0x4E20
    ctx->r5 = ADD32(0, 0X4E20);
    // 0x80800A44: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x80800A48: nop

    // 0x80800A4C: bc1f        L_80800A74
    if (!c1cs) {
        // 0x80800A50: nop
    
            goto L_80800A74;
    }
    // 0x80800A50: nop

    // 0x80800A54: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800A58: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800A5C: jal         0x800F10B4
    // 0x80800A60: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80800A60: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x80800A64: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800A68: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800A6C: b           L_80800A74
    // 0x80800A70: nop

        goto L_80800A74;
    // 0x80800A70: nop

L_80800A74:
    // 0x80800A74: b           L_80800AD0
    // 0x80800A78: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
        goto L_80800AD0;
    // 0x80800A78: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
L_80800A7C:
    // 0x80800A7C: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80800A80: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800A84: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800A88: lui         $a3, 0x469C
    ctx->r7 = S32(0X469C << 16);
    // 0x80800A8C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800A90: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80800A94: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    // 0x80800A98: addiu       $a1, $zero, 0x4E20
    ctx->r5 = ADD32(0, 0X4E20);
    // 0x80800A9C: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80800AA0: nop

    // 0x80800AA4: bc1f        L_80800ACC
    if (!c1cs) {
        // 0x80800AA8: nop
    
            goto L_80800ACC;
    }
    // 0x80800AA8: nop

    // 0x80800AAC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800AB0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800AB4: jal         0x800F10B4
    // 0x80800AB8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x80800AB8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x80800ABC: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800AC0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800AC4: b           L_80800AD0
    // 0x80800AC8: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
        goto L_80800AD0;
    // 0x80800AC8: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
L_80800ACC:
    // 0x80800ACC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
L_80800AD0:
    // 0x80800AD0: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
L_80800AD4:
    // 0x80800AD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800AD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800ADC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800AE0: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800AE4: lwc1        $f12, 0x28($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X28);
    // 0x80800AE8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800AEC: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    // 0x80800AF0: jal         0x800F12D4
    // 0x80800AF4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F12D4(rdram, ctx);
        goto after_8;
    // 0x80800AF4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_8:
    // 0x80800AF8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800AFC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80800B00: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80800B04: lbu         $a0, 0x5F($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X5F);
    // 0x80800B08: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800B0C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800B10: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800B14: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800B18: jal         0x800C3058
    // 0x80800B1C: nop

    func_800C3058(rdram, ctx);
        goto after_9;
    // 0x80800B1C: nop

    after_9:
    // 0x80800B20: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80800B24: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800B28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B2C: jal         0x800C4350
    // 0x80800B30: lbu         $a0, 0x5F($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X5F);
    func_800C4350(rdram, ctx);
        goto after_10;
    // 0x80800B30: lbu         $a0, 0x5F($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X5F);
    after_10:
    // 0x80800B34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B38: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800B3C: jr          $ra
    // 0x80800B40: nop

    return;
    // 0x80800B40: nop

;}
RECOMP_FUNC void chmayafarmer_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801108: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1612, 0X12FC) << 16);
    // 0x8080110C: jr          $ra
    // 0x80801110: addiu       $v0, $v0, 0x12FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1612, 0X12FC));
    return;
    // 0x80801110: addiu       $v0, $v0, 0x12FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1612, 0X12FC));
    // 0x80801114: nop

    // 0x80801118: nop

    // 0x8080111C: nop

;}
