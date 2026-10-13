#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _glidmake_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800888A0: syscall     707
    recomp_syscall_handler(rdram, ctx, 0x800888A0);
    return;
    // 0x800888A4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chevilmumbo_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803980: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1676, 0X4544) << 16);
    // 0x80803984: jr          $ra
    // 0x80803988: addiu       $v0, $v0, 0x4544
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1676, 0X4544));
    return;
    // 0x80803988: addiu       $v0, $v0, 0x4544
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1676, 0X4544));
;}
RECOMP_FUNC void baroll_resetAngularVelocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C578: lui         $a1, 0x442F
    ctx->r5 = S32(0X442F << 16);
    // 0x8009C57C: jal         0x8009C554
    // 0x8009C580: lui         $a2, 0x40F0
    ctx->r6 = S32(0X40F0 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_0;
    // 0x8009C580: lui         $a2, 0x40F0
    ctx->r6 = S32(0X40F0 << 16);
    after_0:
    // 0x8009C584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C58C: jr          $ra
    // 0x8009C590: nop

    return;
    // 0x8009C590: nop

;}
RECOMP_FUNC void func_80800308_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800308: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080030C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800310: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800314: jal         0x8009E6EC
    // 0x80800318: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800318: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080031C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80800320: beq         $v0, $at, L_80800344
    if (ctx->r2 == ctx->r1) {
        // 0x80800324: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800344;
    }
    // 0x80800324: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800328: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x8080032C: beq         $v0, $at, L_80800364
    if (ctx->r2 == ctx->r1) {
        // 0x80800330: addiu       $at, $zero, 0x8D
        ctx->r1 = ADD32(0, 0X8D);
            goto L_80800364;
    }
    // 0x80800330: addiu       $at, $zero, 0x8D
    ctx->r1 = ADD32(0, 0X8D);
    // 0x80800334: beq         $v0, $at, L_8080034C
    if (ctx->r2 == ctx->r1) {
        // 0x80800338: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8080034C;
    }
    // 0x80800338: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080033C: b           L_808003D4
    // 0x80800340: nop

        goto L_808003D4;
    // 0x80800340: nop

L_80800344:
    // 0x80800344: b           L_808003DC
    // 0x80800348: sw          $t6, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r14;
        goto L_808003DC;
    // 0x80800348: sw          $t6, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r14;
L_8080034C:
    // 0x8080034C: sw          $t7, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r15;
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800354: jal         0x8009E830
    // 0x80800358: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_1;
    // 0x80800358: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8080035C: b           L_808003E0
    // 0x80800360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003E0;
    // 0x80800360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800364:
    // 0x80800364: lw          $t8, 0x160($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X160);
    // 0x80800368: bnel        $t8, $zero, L_808003E0
    if (ctx->r24 != 0) {
        // 0x8080036C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003E0;
    }
    goto skip_0;
    // 0x8080036C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800370: jal         0x8008E40C
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E40C(rdram, ctx);
        goto after_2;
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800378: beql        $v0, $zero, L_808003E0
    if (ctx->r2 == 0) {
        // 0x8080037C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003E0;
    }
    goto skip_1;
    // 0x8080037C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800380: jal         0x8009E6F8
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_3;
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800388: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8080038C: beq         $v0, $at, L_808003A0
    if (ctx->r2 == ctx->r1) {
        // 0x80800390: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003A0;
    }
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800394: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800398: bnel        $v0, $at, L_808003E0
    if (ctx->r2 != ctx->r1) {
        // 0x8080039C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003E0;
    }
    goto skip_2;
    // 0x8080039C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_808003A0:
    // 0x808003A0: jal         0x80099A7C
    // 0x808003A4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80099A7C(rdram, ctx);
        goto after_4;
    // 0x808003A4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: jal         0x800850A8
    // 0x808003B0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _bashoessuck_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x808003B0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x808003B4: beq         $v0, $zero, L_808003DC
    if (ctx->r2 == 0) {
        // 0x808003B8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_808003DC;
    }
    // 0x808003B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808003BC: sw          $t9, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r25;
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C4: jal         0x8009E5C8
    // 0x808003C8: addiu       $a1, $zero, 0x17C
    ctx->r5 = ADD32(0, 0X17C);
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x808003C8: addiu       $a1, $zero, 0x17C
    ctx->r5 = ADD32(0, 0X17C);
    after_6:
    // 0x808003CC: b           L_808003E0
    // 0x808003D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003E0;
    // 0x808003D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003D4:
    // 0x808003D4: jal         0x80099B94
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_7;
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_808003DC:
    // 0x808003DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003E0:
    // 0x808003E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003E8: jr          $ra
    // 0x808003EC: nop

    return;
    // 0x808003EC: nop

;}
RECOMP_FUNC void func_800A3BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3BA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A3BAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A3BB0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A3BB4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800A3BB8: jal         0x800A4CA8
    // 0x800A3BBC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800A4CA8(rdram, ctx);
        goto after_0;
    // 0x800A3BBC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A3BC0: beq         $v0, $zero, L_800A3D64
    if (ctx->r2 == 0) {
        // 0x800A3BC4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800A3D64;
    }
    // 0x800A3BC4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A3BC8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800A3BCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A3BD0: lw          $v0, 0x38($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X38);
    // 0x800A3BD4: lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2);
    // 0x800A3BD8: beq         $v1, $at, L_800A3C00
    if (ctx->r3 == ctx->r1) {
        // 0x800A3BDC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800A3C00;
    }
    // 0x800A3BDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A3BE0: beq         $v1, $at, L_800A3C64
    if (ctx->r3 == ctx->r1) {
        // 0x800A3BE4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A3C64;
    }
    // 0x800A3BE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A3BE8: beq         $v1, $at, L_800A3CC8
    if (ctx->r3 == ctx->r1) {
        // 0x800A3BEC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A3CC8;
    }
    // 0x800A3BEC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A3BF0: beql        $v1, $at, L_800A3D30
    if (ctx->r3 == ctx->r1) {
        // 0x800A3BF4: lh          $t9, 0x34($v0)
        ctx->r25 = MEM_H(ctx->r2, 0X34);
            goto L_800A3D30;
    }
    goto skip_0;
    // 0x800A3BF4: lh          $t9, 0x34($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X34);
    skip_0:
    // 0x800A3BF8: b           L_800A3D54
    // 0x800A3BFC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_800A3D54;
    // 0x800A3BFC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_800A3C00:
    // 0x800A3C00: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x800A3C04: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x800A3C08: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800A3C0C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800A3C10: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800A3C14: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x800A3C18: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A3C1C: lh          $t0, 0x34($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X34);
    // 0x800A3C20: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800A3C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3C28: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A3C2C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800A3C30: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A3C34: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800A3C38: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800A3C3C: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800A3C40: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800A3C44: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A3C48: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800A3C4C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A3C50: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800A3C54: jal         0x80110CC0
    // 0x800A3C58: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80110CC0(rdram, ctx);
        goto after_1;
    // 0x800A3C58: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x800A3C5C: b           L_800A3D54
    // 0x800A3C60: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_800A3D54;
    // 0x800A3C60: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_800A3C64:
    // 0x800A3C64: lw          $t1, 0x14($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X14);
    // 0x800A3C68: lw          $t2, 0x18($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X18);
    // 0x800A3C6C: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800A3C70: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800A3C74: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800A3C78: lw          $t3, 0x1C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1C);
    // 0x800A3C7C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A3C80: lh          $t4, 0x34($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X34);
    // 0x800A3C84: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800A3C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3C8C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A3C90: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800A3C94: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A3C98: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800A3C9C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800A3CA0: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800A3CA4: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800A3CA8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A3CAC: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800A3CB0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A3CB4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800A3CB8: jal         0x80110CC0
    // 0x800A3CBC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80110CC0(rdram, ctx);
        goto after_2;
    // 0x800A3CBC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x800A3CC0: b           L_800A3D54
    // 0x800A3CC4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_800A3D54;
    // 0x800A3CC4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_800A3CC8:
    // 0x800A3CC8: lw          $t5, 0x20($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X20);
    // 0x800A3CCC: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x800A3CD0: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800A3CD4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800A3CD8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800A3CDC: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
    // 0x800A3CE0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A3CE4: lh          $t8, 0x34($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X34);
    // 0x800A3CE8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800A3CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3CF0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A3CF4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800A3CF8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A3CFC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800A3D00: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800A3D04: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800A3D08: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800A3D0C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A3D10: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800A3D14: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A3D18: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800A3D1C: jal         0x80110CC0
    // 0x800A3D20: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80110CC0(rdram, ctx);
        goto after_3;
    // 0x800A3D20: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x800A3D24: b           L_800A3D54
    // 0x800A3D28: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_800A3D54;
    // 0x800A3D28: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3D2C: lh          $t9, 0x34($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X34);
L_800A3D30:
    // 0x800A3D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3D34: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    // 0x800A3D38: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800A3D3C: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x800A3D40: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x800A3D44: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A3D48: jal         0x80110CC0
    // 0x800A3D4C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_80110CC0(rdram, ctx);
        goto after_4;
    // 0x800A3D4C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x800A3D50: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_800A3D54:
    // 0x800A3D54: beql        $t0, $zero, L_800A3D68
    if (ctx->r8 == 0) {
        // 0x800A3D58: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A3D68;
    }
    goto skip_1;
    // 0x800A3D58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800A3D5C: jal         0x80115564
    // 0x800A3D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80115564(rdram, ctx);
        goto after_5;
    // 0x800A3D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_800A3D64:
    // 0x800A3D64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A3D68:
    // 0x800A3D68: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A3D6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A3D70: jr          $ra
    // 0x800A3D74: nop

    return;
    // 0x800A3D74: nop

;}
RECOMP_FUNC void subaddiejoy_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002E8: lw          $a0, 0x64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X64);
    // 0x808002EC: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x808002F0: jal         0x80016B30
    // 0x808002F4: srl         $a0, $t6, 30
    ctx->r4 = S32(U32(ctx->r14) >> 30);
    func_80016B30(rdram, ctx);
        goto after_0;
    // 0x808002F4: srl         $a0, $t6, 30
    ctx->r4 = S32(U32(ctx->r14) >> 30);
    after_0:
    // 0x808002F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800300: jr          $ra
    // 0x80800304: nop

    return;
    // 0x80800304: nop

;}
RECOMP_FUNC void func_800E2440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E2444: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800E2448: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E244C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E2450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E2454: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800E2458: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E245C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800E2460: jal         0x800F31DC
    // 0x800E2464: addiu       $a0, $a0, -0x2B8C
    ctx->r4 = ADD32(ctx->r4, -0X2B8C);
    func_800F31DC(rdram, ctx);
        goto after_0;
    // 0x800E2464: addiu       $a0, $a0, -0x2B8C
    ctx->r4 = ADD32(ctx->r4, -0X2B8C);
    after_0:
    // 0x800E2468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E246C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E2470: jr          $ra
    // 0x800E2474: nop

    return;
    // 0x800E2474: nop

;}
RECOMP_FUNC void _bsdronevanish_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083180: syscall     48
    recomp_syscall_handler(rdram, ctx, 0x80083180);
    return;
    // 0x80083184: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void gcboundDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800478: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080047C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80800480: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80800484: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800488: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8080048C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80800490: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80800494: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800498: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8080049C: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x808004A0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x808004A4: jal         0x8080141C
    // 0x808004A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080141C_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x808004A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808004AC: beq         $v0, $zero, L_808004E8
    if (ctx->r2 == 0) {
        // 0x808004B0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808004E8;
    }
    // 0x808004B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808004B4:
    // 0x808004B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808004B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004BC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808004C0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x808004C4: jal         0x80801484
    // 0x808004C8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_80801484_gcboundDll(rdram, ctx);
        goto after_1;
    // 0x808004C8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_1:
    // 0x808004CC: bne         $v0, $zero, L_808004E8
    if (ctx->r2 != 0) {
        // 0x808004D0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808004E8;
    }
    // 0x808004D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808004D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808004D8: jal         0x8080141C
    // 0x808004DC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8080141C_gcboundDll(rdram, ctx);
        goto after_2;
    // 0x808004DC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x808004E0: bne         $v0, $zero, L_808004B4
    if (ctx->r2 != 0) {
        // 0x808004E4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808004B4;
    }
    // 0x808004E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808004E8:
    // 0x808004E8: bne         $s0, $zero, L_80800500
    if (ctx->r16 != 0) {
        // 0x808004EC: addiu       $a0, $s2, 0x8
        ctx->r4 = ADD32(ctx->r18, 0X8);
            goto L_80800500;
    }
    // 0x808004EC: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x808004F0: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x808004F4: jal         0x80800280
    // 0x808004F8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80800280_gcboundDll(rdram, ctx);
        goto after_3;
    // 0x808004F8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_3:
    // 0x808004FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800500:
    // 0x80800500: jal         0x8080132C
    // 0x80800504: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_8080132C_gcboundDll(rdram, ctx);
        goto after_4;
    // 0x80800504: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_4:
    // 0x80800508: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8080050C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800510: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800514: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80800518: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x8080051C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800520: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80800524: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80800528: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8080052C: jal         0x808001A8
    // 0x80800530: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_808001A8_gcboundDll(rdram, ctx);
        goto after_5;
    // 0x80800530: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_5:
    // 0x80800534: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800538: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8080053C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80800540: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80800544: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80800548: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8080054C: jr          $ra
    // 0x80800550: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800550: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80802400_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802400: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802408: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080240C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80802410: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80802414: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80802418: jal         0x800EE7F8
    // 0x8080241C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080241C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80802420: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80802424: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802428: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080242C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80802430: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80802434: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80802438: beq         $a2, $zero, L_80802450
    if (ctx->r6 == 0) {
        // 0x8080243C: swc1        $f8, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
            goto L_80802450;
    }
    // 0x8080243C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80802440: beq         $a2, $at, L_80802450
    if (ctx->r6 == ctx->r1) {
        // 0x80802444: addiu       $at, $zero, 0x1F
        ctx->r1 = ADD32(0, 0X1F);
            goto L_80802450;
    }
    // 0x80802444: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80802448: bnel        $a2, $at, L_8080245C
    if (ctx->r6 != ctx->r1) {
        // 0x8080244C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080245C;
    }
    goto skip_0;
    // 0x8080244C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80802450:
    // 0x80802450: jal         0x80085738
    // 0x80802454: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    _capod_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80802454: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80802458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080245C:
    // 0x8080245C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802460: jr          $ra
    // 0x80802464: nop

    return;
    // 0x80802464: nop

;}
RECOMP_FUNC void _suegg_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A3A8: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A3A8);
    return;
    // 0x8008A3AC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _subaddierouteDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F78: syscall     818
    recomp_syscall_handler(rdram, ctx, 0x80089F78);
    return;
    // 0x80089F7C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8009BE28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BE28: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009BE2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009BE30: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8009BE34: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8009BE38: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8009BE3C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8009BE40: jal         0x800D8FF8
    // 0x8009BE44: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8009BE44: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x8009BE48: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8009BE4C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8009BE50: lw          $s0, 0xDC($t6)
    ctx->r16 = MEM_W(ctx->r14, 0XDC);
    // 0x8009BE54: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8009BE58: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8009BE5C: jal         0x80013728
    // 0x8009BE60: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80013728(rdram, ctx);
        goto after_1;
    // 0x8009BE60: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x8009BE64: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8009BE68: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8009BE6C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8009BE70: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8009BE74: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x8009BE78: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x8009BE7C: bc1tl       L_8009BEC8
    if (c1cs) {
        // 0x8009BE80: lwc1        $f10, 0x28($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
            goto L_8009BEC8;
    }
    goto skip_0;
    // 0x8009BE80: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x8009BE84: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8009BE88: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8009BE8C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8009BE90: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009BE94: bc1fl       L_8009BEB8
    if (!c1cs) {
        // 0x8009BE98: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_8009BEB8;
    }
    goto skip_1;
    // 0x8009BE98: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_1:
    // 0x8009BE9C: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8009BEA0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x8009BEA4: jal         0x800F0D50
    // 0x8009BEA8: lui         $a2, 0xC040
    ctx->r6 = S32(0XC040 << 16);
    func_800F0D50(rdram, ctx);
        goto after_2;
    // 0x8009BEA8: lui         $a2, 0xC040
    ctx->r6 = S32(0XC040 << 16);
    after_2:
    // 0x8009BEAC: b           L_8009BEC4
    // 0x8009BEB0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_8009BEC4;
    // 0x8009BEB0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8009BEB4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_8009BEB8:
    // 0x8009BEB8: jal         0x800F0D50
    // 0x8009BEBC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800F0D50(rdram, ctx);
        goto after_3;
    // 0x8009BEBC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x8009BEC0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_8009BEC4:
    // 0x8009BEC4: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
L_8009BEC8:
    // 0x8009BEC8: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8009BECC: mul.s       $f12, $f20, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x8009BED0: jal         0x800F212C
    // 0x8009BED4: nop

    func_800F212C(rdram, ctx);
        goto after_4;
    // 0x8009BED4: nop

    after_4:
    // 0x8009BED8: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8009BEDC: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8009BEE0: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x8009BEE4: jal         0x800136E4
    // 0x8009BEE8: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    func_800136E4(rdram, ctx);
        goto after_5;
    // 0x8009BEE8: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x8009BEEC: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8009BEF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009BEF4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8009BEF8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8009BEFC: jr          $ra
    // 0x8009BF00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8009BF00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void bashoes_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808008BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008C0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808008C4: jal         0x800B53A4
    // 0x808008C8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x808008C8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_0:
    // 0x808008CC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808008D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808008D4: jal         0x8009C128
    // 0x808008D8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x808008D8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x808008DC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(592, 0XB4C) << 16);
    // 0x808008E0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808008E4: addiu       $t6, $t6, 0xB4C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(592, 0XB4C));
    // 0x808008E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808008EC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808008F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008F4: jal         0x800BABB8
    // 0x808008F8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x808008F8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x808008FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800900: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800904: jr          $ra
    // 0x80800908: nop

    return;
    // 0x80800908: nop

;}
RECOMP_FUNC void func_808008F8_chmayafarmer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808008FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800900: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800904: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800908: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080090C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800910: bne         $a1, $at, L_80800984
    if (ctx->r5 != ctx->r1) {
        // 0x80800914: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_80800984;
    }
    // 0x80800914: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800918: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080091C: jal         0x800EC398
    // 0x80800920: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EC398(rdram, ctx);
        goto after_0;
    // 0x80800920: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80800924: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800928: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080092C: jal         0x800F1DF4
    // 0x80800930: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800F1DF4(rdram, ctx);
        goto after_1;
    // 0x80800930: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80800934: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800938: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8080093C: jal         0x800EFCD8
    // 0x80800940: lui         $a2, 0x41C8
    ctx->r6 = S32(0X41C8 << 16);
    func_800EFCD8(rdram, ctx);
        goto after_2;
    // 0x80800940: lui         $a2, 0x41C8
    ctx->r6 = S32(0X41C8 << 16);
    after_2:
    // 0x80800944: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1612, 0X1230) << 16);
    // 0x80800948: addiu       $a2, $a2, 0x1230
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1612, 0X1230));
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800950: jal         0x80089D18
    // 0x80800954: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800954: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80800958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080095C: jal         0x80102424
    // 0x80800960: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80800960: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800964: jal         0x8010A570
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_5;
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080096C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800970: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800974: jal         0x8010114C
    // 0x80800978: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    func_8010114C(rdram, ctx);
        goto after_6;
    // 0x80800978: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_6:
    // 0x8080097C: b           L_8080098C
    // 0x80800980: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080098C;
    // 0x80800980: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800984:
    // 0x80800984: b           L_8080098C
    // 0x80800988: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080098C;
    // 0x80800988: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080098C:
    // 0x8080098C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800990: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800994: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800998: jr          $ra
    // 0x8080099C: nop

    return;
    // 0x8080099C: nop

;}
RECOMP_FUNC void func_808006A8_chseaweedbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808006B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808006B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006BC: jal         0x800DF744
    // 0x808006C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x808006C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x808006C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808006C8: jal         0x800DF744
    // 0x808006CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x808006CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808006D0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808006D4: jal         0x800DF744
    // 0x808006D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x808006D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808006DC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808006E0: jal         0x800DF744
    // 0x808006E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x808006E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808006E8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x808006EC: jal         0x800DF744
    // 0x808006F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x808006F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808006F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808006F8: jal         0x80101870
    // 0x808006FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_5;
    // 0x808006FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_5:
    // 0x80800700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800704: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800708: jr          $ra
    // 0x8080070C: nop

    return;
    // 0x8080070C: nop

;}
RECOMP_FUNC void func_80802690_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802690: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80802694: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802698: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080269C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808026A0: jal         0x80100094
    // 0x808026A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808026A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808026A8: jal         0x800D8FF8
    // 0x808026AC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808026AC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808026B0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x808026B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808026B8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808026BC: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808026C0: jal         0x801022E4
    // 0x808026C4: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    func_801022E4(rdram, ctx);
        goto after_2;
    // 0x808026C4: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    after_2:
    // 0x808026C8: addiu       $t6, $v0, -0x7D
    ctx->r14 = ADD32(ctx->r2, -0X7D);
    // 0x808026CC: sltiu       $at, $t6, 0xE
    ctx->r1 = ctx->r14 < 0XE ? 1 : 0;
    // 0x808026D0: beq         $at, $zero, L_80802818
    if (ctx->r1 == 0) {
        // 0x808026D4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80802818;
    }
    // 0x808026D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808026D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X44D8) << 16);
    // 0x808026DC: addu        $at, $at, $t6
    gpr jr_addend_808026E4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808026E0: lw          $t6, 0x44D8($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1632, 0X44D8));
    // 0x808026E4: jr          $t6
    // 0x808026E8: nop

    switch (jr_addend_808026E4 >> 2) {
        case 0: goto L_808026EC; break;
        case 1: goto L_80802818; break;
        case 2: goto L_80802818; break;
        case 3: goto L_808027DC; break;
        case 4: goto L_80802818; break;
        case 5: goto L_80802818; break;
        case 6: goto L_80802818; break;
        case 7: goto L_80802818; break;
        case 8: goto L_808027B8; break;
        case 9: goto L_80802818; break;
        case 10: goto L_80802818; break;
        case 11: goto L_80802818; break;
        case 12: goto L_80802770; break;
        case 13: goto L_80802794; break;
        default: switch_error(__func__, 0x808026E4, 0x808044D8);
    }
    // 0x808026E8: nop

L_808026EC:
    // 0x808026EC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808026F0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1632, 0X46C0) << 16);
    // 0x808026F4: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808026F8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808026FC: addiu       $a2, $a2, 0x46C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1632, 0X46C0));
    // 0x80802700: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802704: jal         0x80089D20
    // 0x80802708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80802708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080270C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80802710: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80802714: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4510) << 16);
    // 0x80802718: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8080271C: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80802720: nop

    // 0x80802724: bc1fl       L_8080281C
    if (!c1cs) {
        // 0x80802728: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080281C;
    }
    goto skip_0;
    // 0x80802728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080272C: jal         0x800DC298
    // 0x80802730: lwc1        $f12, 0x4510($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4510));
    func_800DC298(rdram, ctx);
        goto after_4;
    // 0x80802730: lwc1        $f12, 0x4510($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4510));
    after_4:
    // 0x80802734: beql        $v0, $zero, L_8080281C
    if (ctx->r2 == 0) {
        // 0x80802738: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080281C;
    }
    goto skip_1;
    // 0x80802738: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080273C: jal         0x800C0638
    // 0x80802740: nop

    func_800C0638(rdram, ctx);
        goto after_5;
    // 0x80802740: nop

    after_5:
    // 0x80802744: bne         $v0, $zero, L_80802818
    if (ctx->r2 != 0) {
        // 0x80802748: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802818;
    }
    // 0x80802748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080274C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1632, 0X46D4) << 16);
    // 0x80802750: addiu       $a2, $a2, 0x46D4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1632, 0X46D4));
    // 0x80802754: jal         0x80089D18
    // 0x80802758: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80802758: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x8080275C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80802760: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80802764: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80802768: b           L_80802818
    // 0x8080276C: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
        goto L_80802818;
    // 0x8080276C: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
L_80802770:
    // 0x80802770: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1632, 0X46C0) << 16);
    // 0x80802774: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1632, 0X4E0C) << 16);
    // 0x80802778: addiu       $a3, $a3, 0x4E0C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1632, 0X4E0C));
    // 0x8080277C: addiu       $a2, $a2, 0x46C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1632, 0X46C0));
    // 0x80802780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802784: jal         0x80089D28
    // 0x80802788: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80802788: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x8080278C: b           L_8080281C
    // 0x80802790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080281C;
    // 0x80802790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802794:
    // 0x80802794: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1632, 0X46C0) << 16);
    // 0x80802798: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1632, 0X4E18) << 16);
    // 0x8080279C: addiu       $a3, $a3, 0x4E18
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1632, 0X4E18));
    // 0x808027A0: addiu       $a2, $a2, 0x46C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1632, 0X46C0));
    // 0x808027A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808027A8: jal         0x80089D28
    // 0x808027AC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x808027AC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x808027B0: b           L_8080281C
    // 0x808027B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080281C;
    // 0x808027B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808027B8:
    // 0x808027B8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1632, 0X46E8) << 16);
    // 0x808027BC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1632, 0X4E2C) << 16);
    // 0x808027C0: addiu       $a3, $a3, 0x4E2C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1632, 0X4E2C));
    // 0x808027C4: addiu       $a2, $a2, 0x46E8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1632, 0X46E8));
    // 0x808027C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808027CC: jal         0x80089D28
    // 0x808027D0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x808027D0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x808027D4: b           L_8080281C
    // 0x808027D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080281C;
    // 0x808027D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808027DC:
    // 0x808027DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808027E0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1632, 0X46C0) << 16);
    // 0x808027E4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1632, 0X4E38) << 16);
    // 0x808027E8: addiu       $a3, $a3, 0x4E38
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1632, 0X4E38));
    // 0x808027EC: addiu       $a2, $a2, 0x46C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1632, 0X46C0));
    // 0x808027F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808027F4: jal         0x80089D28
    // 0x808027F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x808027F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808027FC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1632, 0X46E8) << 16);
    // 0x80802800: lui         $a3, 0x3F66
    ctx->r7 = S32(0X3F66 << 16);
    // 0x80802804: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80802808: addiu       $a2, $a2, 0x46E8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1632, 0X46E8));
    // 0x8080280C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802810: jal         0x80089D20
    // 0x80802814: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x80802814: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_11:
L_80802818:
    // 0x80802818: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080281C:
    // 0x8080281C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802820: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80802824: jr          $ra
    // 0x80802828: nop

    return;
    // 0x80802828: nop

;}
RECOMP_FUNC void bstrexsmall_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801244: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801248: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(416, 0X1B78) << 16);
    // 0x8080124C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801250: jr          $ra
    // 0x80801254: lw          $v0, 0x1B78($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B78));
    return;
    // 0x80801254: lw          $v0, 0x1B78($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B78));
;}
RECOMP_FUNC void chdoormake_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800824: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080082C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800830: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800834: jal         0x80100094
    // 0x80800838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080083C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800840: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80800844: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80800848: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x8080084C: lhu         $t1, 0x22($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X22);
    // 0x80800850: andi        $t0, $t9, 0x7FFF
    ctx->r8 = ctx->r25 & 0X7FFF;
    // 0x80800854: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x80800858: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x8080085C: sh          $t3, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r11;
    // 0x80800860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800868: jr          $ra
    // 0x8080086C: nop

    return;
    // 0x8080086C: nop

;}
RECOMP_FUNC void glgamestore_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080021C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800224: jal         0x80800038
    // 0x80800228: nop

    func_80800038_glgamestore(rdram, ctx);
        goto after_0;
    // 0x80800228: nop

    after_0:
    // 0x8080022C: jal         0x808001E0
    // 0x80800230: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808001E0_glgamestore(rdram, ctx);
        goto after_1;
    // 0x80800230: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080023C: jr          $ra
    // 0x80800240: nop

    return;
    // 0x80800240: nop

;}
RECOMP_FUNC void sccustom_banjo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080020C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800210: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800214: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800218: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080021C: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80800220: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800224: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80800228: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8080022C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80800230: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80800234: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80800238: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8080023C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800240: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800244: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800248: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x8080024C: jal         0x800D674C
    // 0x80800250: addiu       $a0, $zero, 0x9DA
    ctx->r4 = ADD32(0, 0X9DA);
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x80800250: addiu       $a0, $zero, 0x9DA
    ctx->r4 = ADD32(0, 0X9DA);
    after_0:
    // 0x80800254: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x80800258: jal         0x8008A5D8
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800260: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800264: jal         0x8008A610
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_18(rdram, ctx);
        goto after_2;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080026C: jal         0x800CF6B0
    // 0x80800270: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800CF6B0(rdram, ctx);
        goto after_3;
    // 0x80800270: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_3:
    // 0x80800274: jal         0x800CF6D0
    // 0x80800278: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    func_800CF6D0(rdram, ctx);
        goto after_4;
    // 0x80800278: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    after_4:
    // 0x8080027C: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x80800280: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800284: sll         $s4, $s7, 2
    ctx->r20 = S32(ctx->r23 << 2);
    // 0x80800288: addu        $s4, $s4, $s7
    ctx->r20 = ADD32(ctx->r20, ctx->r23);
    // 0x8080028C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800290: sll         $s4, $s4, 2
    ctx->r20 = S32(ctx->r20 << 2);
    // 0x80800294: addiu       $fp, $zero, 0x100
    ctx->r30 = ADD32(0, 0X100);
    // 0x80800298: addiu       $s4, $s4, 0x28
    ctx->r20 = ADD32(ctx->r20, 0X28);
    // 0x8080029C: sll         $s5, $s2, 2
    ctx->r21 = S32(ctx->r18 << 2);
    // 0x808002A0: addiu       $s6, $sp, 0x5C
    ctx->r22 = ADD32(ctx->r29, 0X5C);
    // 0x808002A4: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x808002A8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808002AC: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x808002B0: nop

    // 0x808002B4: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x808002B8: beq         $at, $zero, L_808002FC
    if (ctx->r1 == 0) {
        // 0x808002BC: subu        $t8, $v1, $s3
        ctx->r24 = SUB32(ctx->r3, ctx->r19);
            goto L_808002FC;
    }
    // 0x808002BC: subu        $t8, $v1, $s3
    ctx->r24 = SUB32(ctx->r3, ctx->r19);
    // 0x808002C0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x808002C4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x808002C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002CC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808002D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002D4: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x808002D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808002DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002E0: div.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x808002E4: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x808002E8: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x808002EC: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808002F0: mfc1        $fp, $f6
    ctx->r30 = (int32_t)ctx->f6.u32l;
    // 0x808002F4: b           L_80800300
    // 0x808002F8: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
        goto L_80800300;
    // 0x808002F8: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
L_808002FC:
    // 0x808002FC: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
L_80800300:
    // 0x80800300: bltz        $v1, L_808003BC
    if (SIGNED(ctx->r3) < 0) {
        // 0x80800304: sll         $s1, $v1, 2
        ctx->r17 = S32(ctx->r3 << 2);
            goto L_808003BC;
    }
    // 0x80800304: sll         $s1, $v1, 2
    ctx->r17 = S32(ctx->r3 << 2);
    // 0x80800308: addu        $s1, $s1, $v1
    ctx->r17 = ADD32(ctx->r17, ctx->r3);
    // 0x8080030C: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x80800310: addiu       $s1, $s1, 0x28
    ctx->r17 = ADD32(ctx->r17, 0X28);
    // 0x80800314: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
L_80800318:
    // 0x80800318: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x8080031C: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80800320: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800324: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80800328: addiu       $s0, $zero, 0x78
    ctx->r16 = ADD32(0, 0X78);
    // 0x8080032C: mul.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80800330: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800334: mfc1        $s2, $f4
    ctx->r18 = (int32_t)ctx->f4.u32l;
    // 0x80800338: nop

    // 0x8080033C: slt         $at, $s3, $s2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80800340: beql        $at, $zero, L_80800350
    if (ctx->r1 == 0) {
        // 0x80800344: slt         $at, $s1, $s4
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_80800350;
    }
    goto skip_0;
    // 0x80800344: slt         $at, $s1, $s4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    skip_0:
    // 0x80800348: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x8080034C: slt         $at, $s1, $s4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
L_80800350:
    // 0x80800350: beq         $at, $zero, L_80800368
    if (ctx->r1 == 0) {
        // 0x80800354: nop
    
            goto L_80800368;
    }
    // 0x80800354: nop

    // 0x80800358: jal         0x800E24F8
    // 0x8080035C: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    func_800E24F8(rdram, ctx);
        goto after_5;
    // 0x8080035C: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    after_5:
    // 0x80800360: b           L_80800368
    // 0x80800364: nop

        goto L_80800368;
    // 0x80800364: nop

L_80800368:
    // 0x80800368: multu       $s0, $fp
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080036C: mflo        $a0
    ctx->r4 = lo;
    // 0x80800370: sra         $t1, $a0, 8
    ctx->r9 = S32(SIGNED(ctx->r4) >> 8);
    // 0x80800374: jal         0x800E257C
    // 0x80800378: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_800E257C(rdram, ctx);
        goto after_6;
    // 0x80800378: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_6:
    // 0x8080037C: jal         0x800E253C
    // 0x80800380: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800E253C(rdram, ctx);
        goto after_7;
    // 0x80800380: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_7:
    // 0x80800384: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x80800388: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8080038C: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80800390: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x80800394: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80800398: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x8080039C: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x808003A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808003A4: jal         0x800E30E0
    // 0x808003A8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    func_800E30E0(rdram, ctx);
        goto after_8;
    // 0x808003A8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_8:
    // 0x808003AC: addiu       $s1, $s1, -0x14
    ctx->r17 = ADD32(ctx->r17, -0X14);
    // 0x808003B0: slti        $at, $s1, 0x28
    ctx->r1 = SIGNED(ctx->r17) < 0X28 ? 1 : 0;
    // 0x808003B4: beql        $at, $zero, L_80800318
    if (ctx->r1 == 0) {
        // 0x808003B8: mtc1        $s1, $f10
        ctx->f10.u32l = ctx->r17;
            goto L_80800318;
    }
    goto skip_1;
    // 0x808003B8: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    skip_1:
L_808003BC:
    // 0x808003BC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x808003C0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808003C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003C8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808003CC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808003D0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x808003D4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x808003D8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x808003DC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x808003E0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x808003E4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x808003E8: jr          $ra
    // 0x808003EC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x808003EC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void _bsbfly_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082970: syscall     22
    recomp_syscall_handler(rdram, ctx, 0x80082970);
    return;
    // 0x80082974: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80801C0C_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801C18: jal         0x80091104
    // 0x80801C1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80091104(rdram, ctx);
        goto after_0;
    // 0x80801C1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801C20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801C24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801C28: jal         0x800852A0
    // 0x80801C2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _baswim_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80801C2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80801C30: jal         0x8009679C
    // 0x80801C34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8009679C(rdram, ctx);
        goto after_2;
    // 0x80801C34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801C38: jal         0x80800104
    // 0x80801C3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800104_bsbswim(rdram, ctx);
        goto after_3;
    // 0x80801C3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80801C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801C48: jr          $ra
    // 0x80801C4C: nop

    return;
    // 0x80801C4C: nop

;}
RECOMP_FUNC void func_8008D630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D630: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D638: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D63C: jal         0x80095738
    // 0x8008D640: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    baflag_isTrue(rdram, ctx);
        goto after_0;
    // 0x8008D640: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x8008D644: bne         $v0, $zero, L_8008D65C
    if (ctx->r2 != 0) {
        // 0x8008D648: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8008D65C;
    }
    // 0x8008D648: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008D64C: jal         0x80095738
    // 0x8008D650: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    baflag_isTrue(rdram, ctx);
        goto after_1;
    // 0x8008D650: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_1:
    // 0x8008D654: beq         $v0, $zero, L_8008D664
    if (ctx->r2 == 0) {
        // 0x8008D658: nop
    
            goto L_8008D664;
    }
    // 0x8008D658: nop

L_8008D65C:
    // 0x8008D65C: b           L_8008D684
    // 0x8008D660: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D684;
    // 0x8008D660: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008D664:
    // 0x8008D664: jal         0x8009E6F8
    // 0x8008D668: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bs_getCurrentState(rdram, ctx);
        goto after_2;
    // 0x8008D668: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8008D66C: addiu       $at, $zero, 0x56
    ctx->r1 = ADD32(0, 0X56);
    // 0x8008D670: bnel        $v0, $at, L_8008D684
    if (ctx->r2 != ctx->r1) {
        // 0x8008D674: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8008D684;
    }
    goto skip_0;
    // 0x8008D674: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8008D678: b           L_8008D684
    // 0x8008D67C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D684;
    // 0x8008D67C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008D680: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008D684:
    // 0x8008D684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D68C: jr          $ra
    // 0x8008D690: nop

    return;
    // 0x8008D690: nop

;}
RECOMP_FUNC void func_800D542C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D542C: jr          $ra
    // 0x800D5430: addiu       $v0, $a0, 0x9A
    ctx->r2 = ADD32(ctx->r4, 0X9A);
    return;
    // 0x800D5430: addiu       $v0, $a0, 0x9A
    ctx->r2 = ADD32(ctx->r4, 0X9A);
    // 0x800D5434: nop

    // 0x800D5438: nop

    // 0x800D543C: nop

;}
RECOMP_FUNC void func_80800100_chfactoryworkerwear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800108: jal         0x80100094
    // 0x8080010C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080010C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800110: sb          $zero, 0x24($v0)
    MEM_B(0X24, ctx->r2) = 0;
    // 0x80800114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080011C: jr          $ra
    // 0x80800120: nop

    return;
    // 0x80800120: nop

;}
RECOMP_FUNC void _bssnowball_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A28: syscall     87
    recomp_syscall_handler(rdram, ctx, 0x80083A28);
    return;
    // 0x80083A2C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chbadshad_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085770: syscall     173
    recomp_syscall_handler(rdram, ctx, 0x80085770);
    return;
    // 0x80085774: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800DF470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF470: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF474: jr          $ra
    // 0x800DF478: sw          $a0, -0x37CC($at)
    MEM_W(-0X37CC, ctx->r1) = ctx->r4;
    return;
    // 0x800DF478: sw          $a0, -0x37CC($at)
    MEM_W(-0X37CC, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80800428_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800428: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080042C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800430: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800434: jal         0x808002B8
    // 0x80800438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808002B8_bsmum(rdram, ctx);
        goto after_0;
    // 0x80800438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080043C: jal         0x8080016C
    // 0x80800440: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsmum_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800440: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080044C: jr          $ra
    // 0x80800450: nop

    return;
    // 0x80800450: nop

;}
RECOMP_FUNC void func_80101DDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101DDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101DE4: jal         0x80104248
    // 0x80101DE8: nop

    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80101DE8: nop

    after_0:
    // 0x80101DEC: bne         $v0, $zero, L_80101DFC
    if (ctx->r2 != 0) {
        // 0x80101DF0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80101DFC;
    }
    // 0x80101DF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101DF4: b           L_80101E04
    // 0x80101DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80101E04;
    // 0x80101DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101DFC:
    // 0x80101DFC: jal         0x8008B324
    // 0x80101E00: nop

    anctrl_isStopped(rdram, ctx);
        goto after_1;
    // 0x80101E00: nop

    after_1:
L_80101E04:
    // 0x80101E04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101E08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101E0C: jr          $ra
    // 0x80101E10: nop

    return;
    // 0x80101E10: nop

;}
RECOMP_FUNC void gspropsDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: beq         $a0, $zero, L_80800090
    if (ctx->r4 == 0) {
        // 0x80800008: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800090;
    }
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x80800010: beql        $t6, $zero, L_80800094
    if (ctx->r14 == 0) {
        // 0x80800014: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800094;
    }
    goto skip_0;
    // 0x80800014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800018: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080001C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800020: jal         0x800E9D68
    // 0x80800024: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800E9D68(rdram, ctx);
        goto after_0;
    // 0x80800024: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800028: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080002C: jal         0x800E9D90
    // 0x80800030: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800E9D90(rdram, ctx);
        goto after_1;
    // 0x80800030: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800034: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800038: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080003C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800040: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80800044: beq         $at, $zero, L_80800090
    if (ctx->r1 == 0) {
        // 0x80800048: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800090;
    }
    // 0x80800048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080004C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80800050: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
L_80800054:
    // 0x80800054: sll         $t8, $t7, 25
    ctx->r24 = S32(ctx->r15 << 25);
    // 0x80800058: srl         $t9, $t8, 26
    ctx->r25 = S32(U32(ctx->r24) >> 26);
    // 0x8080005C: bnel        $v0, $t9, L_80800084
    if (ctx->r2 != ctx->r25) {
        // 0x80800060: addiu       $v1, $v1, 0x14
        ctx->r3 = ADD32(ctx->r3, 0X14);
            goto L_80800084;
    }
    goto skip_1;
    // 0x80800060: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    skip_1:
    // 0x80800064: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80800068: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8080006C: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x80800070: sw          $v1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r3;
    // 0x80800074: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80800078: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8080007C: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x80800080: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
L_80800084:
    // 0x80800084: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80800088: bnel        $at, $zero, L_80800054
    if (ctx->r1 != 0) {
        // 0x8080008C: lw          $t7, 0x4($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X4);
            goto L_80800054;
    }
    goto skip_2;
    // 0x8080008C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    skip_2:
L_80800090:
    // 0x80800090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800094:
    // 0x80800094: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800098: jr          $ra
    // 0x8080009C: nop

    return;
    // 0x8080009C: nop

;}
RECOMP_FUNC void _gcdialogcamera_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800880C8: syscall     669
    recomp_syscall_handler(rdram, ctx, 0x800880C8);
    return;
    // 0x800880CC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80800438_chjiggytemple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800438: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080043C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800440: bne         $a1, $at, L_80800458
    if (ctx->r5 != ctx->r1) {
        // 0x80800444: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800458;
    }
    // 0x80800444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800448: jal         0x80086248
    // 0x8080044C: nop

    _chdoor_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080044C: nop

    after_0:
    // 0x80800450: b           L_80800464
    // 0x80800454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800464;
    // 0x80800454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800458:
    // 0x80800458: jal         0x80086248
    // 0x8080045C: nop

    _chdoor_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080045C: nop

    after_1:
    // 0x80800460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800464:
    // 0x80800464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800468: jr          $ra
    // 0x8080046C: nop

    return;
    // 0x8080046C: nop

;}
RECOMP_FUNC void func_80804A3C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804A3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804A40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804A44: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80804A48: lw          $a1, 0x184($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X184);
    // 0x80804A4C: jal         0x80101238
    // 0x80804A50: addiu       $a0, $zero, 0x77
    ctx->r4 = ADD32(0, 0X77);
    func_80101238(rdram, ctx);
        goto after_0;
    // 0x80804A50: addiu       $a0, $zero, 0x77
    ctx->r4 = ADD32(0, 0X77);
    after_0:
    // 0x80804A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804A5C: jr          $ra
    // 0x80804A60: nop

    return;
    // 0x80804A60: nop

;}
RECOMP_FUNC void bskazfly_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019B4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808019B8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(236, 0X1CA8) << 16);
    // 0x808019BC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808019C0: jr          $ra
    // 0x808019C4: lw          $v0, 0x1CA8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1CA8));
    return;
    // 0x808019C4: lw          $v0, 0x1CA8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1CA8));
;}
RECOMP_FUNC void func_808000D0_chiciclebits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000DC: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808000E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000E8: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808000EC: beq         $t6, $at, L_8080022C
    if (ctx->r14 == ctx->r1) {
        // 0x808000F0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080022C;
    }
    // 0x808000F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000F4: beq         $t6, $at, L_80800110
    if (ctx->r14 == ctx->r1) {
        // 0x808000F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800110;
    }
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800100: beq         $t6, $at, L_8080017C
    if (ctx->r14 == ctx->r1) {
        // 0x80800104: nop
    
            goto L_8080017C;
    }
    // 0x80800104: nop

    // 0x80800108: b           L_80800230
    // 0x8080010C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800230;
    // 0x8080010C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800110:
    // 0x80800110: jal         0x8008A4C8
    // 0x80800114: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _subaddieDll_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800114: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80800118: jal         0x800D9078
    // 0x8080011C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x8080011C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x80800120: beq         $v0, $zero, L_8080022C
    if (ctx->r2 == 0) {
        // 0x80800124: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080022C;
    }
    // 0x80800124: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800128: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1228, 0X430) << 16);
    // 0x8080012C: addiu       $t7, $t7, 0x430
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1228, 0X430));
    // 0x80800130: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800134: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800138: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080013C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80800140: jal         0x800BBCB8
    // 0x80800144: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x80800144: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800148: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080014C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1228, 0X468) << 16);
    // 0x80800150: addiu       $t8, $t8, 0x468
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1228, 0X468));
    // 0x80800154: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800158: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080015C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80800160: jal         0x800BBCB8
    // 0x80800164: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x80800164: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_3:
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080016C: jal         0x80101FDC
    // 0x80800170: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800170: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800174: b           L_80800230
    // 0x80800178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800230;
    // 0x80800178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080017C:
    // 0x8080017C: jal         0x800D8FF8
    // 0x80800180: nop

    func_800D8FF8(rdram, ctx);
        goto after_5;
    // 0x80800180: nop

    after_5:
    // 0x80800184: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800188: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080018C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1228, 0X394) << 16);
    // 0x80800190: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80800194: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800198: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1228, 0X4A8) << 16);
    // 0x8080019C: addiu       $a2, $a2, 0x4A8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1228, 0X4A8));
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808001A8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808001AC: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x808001B0: lwc1        $f10, 0x394($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1228, 0X394));
    // 0x808001B4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808001B8: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x808001BC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x808001C0: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x808001C4: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x808001C8: bc1f        L_8080022C
    if (!c1cs) {
        // 0x808001CC: swc1        $f18, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
            goto L_8080022C;
    }
    // 0x808001CC: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
    // 0x808001D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001D4: swc1        $f12, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f12.u32l;
    // 0x808001D8: jal         0x80089D18
    // 0x808001DC: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x808001DC: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    after_6:
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: jal         0x80101FDC
    // 0x808001E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x808001E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: jal         0x80103110
    // 0x808001F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_8;
    // 0x808001F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808001F8: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    // 0x808001FC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1228, 0X3EE) << 16);
    // 0x80800200: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80800204: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80800208: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8080020C: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x80800210: jal         0x800DA544
    // 0x80800214: lhu         $a0, 0x3EE($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(1228, 0X3EE));
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x80800214: lhu         $a0, 0x3EE($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(1228, 0X3EE));
    after_9:
    // 0x80800218: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8080021C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800220: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800224: jal         0x80018820
    // 0x80800228: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    func_80018820(rdram, ctx);
        goto after_10;
    // 0x80800228: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_10:
L_8080022C:
    // 0x8080022C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800230:
    // 0x80800230: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800234: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800238: jr          $ra
    // 0x8080023C: nop

    return;
    // 0x8080023C: nop

;}
RECOMP_FUNC void bahitspline_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: jr          $ra
    // 0x80800118: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800118: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _gcnewoption_entrypoint_39(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087DD0: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087DD0);
    return;
    // 0x80087DD4: addi        $t0, $zero, 0x9C
    ctx->r8 = ADD32(0, 0X9C);
;}
RECOMP_FUNC void suspline_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3202, 0XEA0) << 16);
    // 0x808000F8: lwc1        $f6, 0xEA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3202, 0XEA0));
    // 0x808000FC: lwc1        $f4, 0x58($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80800100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800104: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800108: nop

    // 0x8080010C: bc1f        L_80800118
    if (!c1cs) {
        // 0x80800110: nop
    
            goto L_80800118;
    }
    // 0x80800110: nop

    // 0x80800114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800118:
    // 0x80800118: jr          $ra
    // 0x8080011C: nop

    return;
    // 0x8080011C: nop

;}
RECOMP_FUNC void func_80808EF0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808EF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80808EF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80808EF8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80808EFC: jal         0x80091A58
    // 0x80808F00: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80808F00: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80808F04: beq         $v0, $zero, L_80808F28
    if (ctx->r2 == 0) {
        // 0x80808F08: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80808F28;
    }
    // 0x80808F08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80808F0C: jal         0x8009C128
    // 0x80808F10: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x80808F10: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x80808F14: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80808F18: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80808F1C: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x80808F20: jal         0x801013A8
    // 0x80808F24: lw          $a2, 0x184($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X184);
    func_801013A8(rdram, ctx);
        goto after_2;
    // 0x80808F24: lw          $a2, 0x184($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X184);
    after_2:
L_80808F28:
    // 0x80808F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80808F2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80808F30: jr          $ra
    // 0x80808F34: nop

    return;
    // 0x80808F34: nop

;}
RECOMP_FUNC void gcmapsects_lagoontop_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8080000C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800010: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800014: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800018: jal         0x80087F50
    // 0x8080001C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    _gcmapsects_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x80800020: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2614, 0X630) << 16);
    // 0x80800024: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2614, 0X63C) << 16);
    // 0x80800028: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2614, 0X648) << 16);
    // 0x8080002C: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2614, 0X724) << 16);
    // 0x80800030: addiu       $s2, $s2, 0x724
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2614, 0X724));
    // 0x80800034: addiu       $s1, $s1, 0x648
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2614, 0X648));
    // 0x80800038: addiu       $s3, $s3, 0x63C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2614, 0X63C));
    // 0x8080003C: addiu       $s0, $s0, 0x630
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2614, 0X630));
L_80800040:
    // 0x80800040: lh          $t6, 0x24($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X24);
    // 0x80800044: lh          $a0, 0x26($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X26);
    // 0x80800048: lh          $a1, 0x28($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X28);
    // 0x8080004C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800050: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800054: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80800058: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080005C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80800060: jal         0x80087F00
    // 0x80800064: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    _gcmapsects_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800064: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80800068: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // 0x8080006C: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x80800070: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    // 0x80800074: bne         $at, $zero, L_80800040
    if (ctx->r1 != 0) {
        // 0x80800078: addiu       $s3, $s3, 0x2C
        ctx->r19 = ADD32(ctx->r19, 0X2C);
            goto L_80800040;
    }
    // 0x80800078: addiu       $s3, $s3, 0x2C
    ctx->r19 = ADD32(ctx->r19, 0X2C);
    // 0x8080007C: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2614, 0X70C) << 16);
    // 0x80800080: addiu       $s0, $s0, 0x70C
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2614, 0X70C));
    // 0x80800084: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80800088:
    // 0x80800088: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8080008C: jal         0x80087F18
    // 0x80800090: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    _gcmapsects_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800090: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    after_2:
    // 0x80800094: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800098: sltiu       $at, $s2, 0x4
    ctx->r1 = ctx->r18 < 0X4 ? 1 : 0;
    // 0x8080009C: bne         $at, $zero, L_80800088
    if (ctx->r1 != 0) {
        // 0x808000A0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80800088;
    }
    // 0x808000A0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808000A4: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2614, 0X71C) << 16);
    // 0x808000A8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2614, 0X720) << 16);
    // 0x808000AC: addiu       $s1, $s1, 0x720
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2614, 0X720));
    // 0x808000B0: addiu       $s0, $s0, 0x71C
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2614, 0X71C));
    // 0x808000B4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_808000B8:
    // 0x808000B8: jal         0x80087F08
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcmapsects_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808000C0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x808000C4: jal         0x80087F10
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcmapsects_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808000CC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x808000D0: bnel        $s0, $s1, L_808000B8
    if (ctx->r16 != ctx->r17) {
        // 0x808000D4: lh          $a0, 0x0($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X0);
            goto L_808000B8;
    }
    goto skip_0;
    // 0x808000D4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    skip_0:
    // 0x808000D8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808000DC: jal         0x80087F60
    // 0x808000E0: addiu       $a0, $a0, 0x7FE8
    ctx->r4 = ADD32(ctx->r4, 0X7FE8);
    _gcmapsects_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x808000E0: addiu       $a0, $a0, 0x7FE8
    ctx->r4 = ADD32(ctx->r4, 0X7FE8);
    after_5:
    // 0x808000E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808000E8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808000EC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808000F0: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808000F4: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x808000F8: jr          $ra
    // 0x808000FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808000FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800D674C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D674C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800D6750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D6754: jal         0x800D6254
    // 0x800D6758: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_800D6254(rdram, ctx);
        goto after_0;
    // 0x800D6758: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D675C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D6760: beq         $v0, $at, L_800D68D0
    if (ctx->r2 == ctx->r1) {
        // 0x800D6764: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D68D0;
    }
    // 0x800D6764: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D6768: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800D676C: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800D6770: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D6774: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800D6778: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800D677C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800D6780: lw          $t8, -0x4800($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4800);
    // 0x800D6784: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D6788: sh          $v0, -0x46F0($at)
    MEM_H(-0X46F0, ctx->r1) = ctx->r2;
    // 0x800D678C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D6790: sh          $t6, -0x419C($at)
    MEM_H(-0X419C, ctx->r1) = ctx->r14;
    // 0x800D6794: sll         $t9, $t8, 27
    ctx->r25 = S32(ctx->r24 << 27);
    // 0x800D6798: srl         $t0, $t9, 28
    ctx->r8 = S32(U32(ctx->r25) >> 28);
    // 0x800D679C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D67A0: bnel        $t0, $at, L_800D6884
    if (ctx->r8 != ctx->r1) {
        // 0x800D67A4: sll         $t2, $a0, 2
        ctx->r10 = S32(ctx->r4 << 2);
            goto L_800D6884;
    }
    goto skip_0;
    // 0x800D67A4: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    skip_0:
    // 0x800D67A8: jal         0x8001211C
    // 0x800D67AC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_8001211C(rdram, ctx);
        goto after_1;
    // 0x800D67AC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x800D67B0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800D67B4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800D67B8: addiu       $t2, $t2, -0x4800
    ctx->r10 = ADD32(ctx->r10, -0X4800);
    // 0x800D67BC: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x800D67C0: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x800D67C4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800D67C8: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x800D67CC: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800D67D0: srl         $t4, $t3, 5
    ctx->r12 = S32(U32(ctx->r11) >> 5);
    // 0x800D67D4: bnel        $v0, $t4, L_800D6810
    if (ctx->r2 != ctx->r12) {
        // 0x800D67D8: sw          $v1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r3;
            goto L_800D6810;
    }
    goto skip_1;
    // 0x800D67D8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    skip_1:
    // 0x800D67DC: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800D67E0: sll         $t7, $t5, 14
    ctx->r15 = S32(ctx->r13 << 14);
    // 0x800D67E4: bgezl       $t7, L_800D6800
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800D67E8: lbu         $t2, 0x9($v1)
        ctx->r10 = MEM_BU(ctx->r3, 0X9);
            goto L_800D6800;
    }
    goto skip_2;
    // 0x800D67E8: lbu         $t2, 0x9($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X9);
    skip_2:
    // 0x800D67EC: lbu         $t9, 0x9($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X9);
    // 0x800D67F0: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x800D67F4: b           L_800D6880
    // 0x800D67F8: sb          $t0, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r8;
        goto L_800D6880;
    // 0x800D67F8: sb          $t0, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r8;
    // 0x800D67FC: lbu         $t2, 0x9($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X9);
L_800D6800:
    // 0x800D6800: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x800D6804: b           L_800D6880
    // 0x800D6808: sb          $t3, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r11;
        goto L_800D6880;
    // 0x800D6808: sb          $t3, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r11;
    // 0x800D680C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_800D6810:
    // 0x800D6810: jal         0x8001211C
    // 0x800D6814: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    func_8001211C(rdram, ctx);
        goto after_2;
    // 0x800D6814: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_2:
    // 0x800D6818: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800D681C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800D6820: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800D6824: srl         $t5, $t4, 5
    ctx->r13 = S32(U32(ctx->r12) >> 5);
    // 0x800D6828: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800D682C: bnel        $v0, $t6, L_800D6870
    if (ctx->r2 != ctx->r14) {
        // 0x800D6830: lbu         $t8, 0x9($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X9);
            goto L_800D6870;
    }
    goto skip_3;
    // 0x800D6830: lbu         $t8, 0x9($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X9);
    skip_3:
    // 0x800D6834: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800D6838: sll         $t7, $v0, 14
    ctx->r15 = S32(ctx->r2 << 14);
    // 0x800D683C: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x800D6840: sltu        $v0, $zero, $t8
    ctx->r2 = 0 < ctx->r24 ? 1 : 0;
    // 0x800D6844: bnel        $v0, $zero, L_800D685C
    if (ctx->r2 != 0) {
        // 0x800D6848: lbu         $t4, 0x3($v1)
        ctx->r12 = MEM_BU(ctx->r3, 0X3);
            goto L_800D685C;
    }
    goto skip_4;
    // 0x800D6848: lbu         $t4, 0x3($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X3);
    skip_4:
    // 0x800D684C: lhu         $v0, 0x8($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X8);
    // 0x800D6850: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x800D6854: sltu        $v0, $zero, $t0
    ctx->r2 = 0 < ctx->r8 ? 1 : 0;
    // 0x800D6858: lbu         $t4, 0x3($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X3);
L_800D685C:
    // 0x800D685C: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x800D6860: andi        $t5, $t4, 0xFFFE
    ctx->r13 = ctx->r12 & 0XFFFE;
    // 0x800D6864: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x800D6868: sb          $t6, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r14;
    // 0x800D686C: lbu         $t8, 0x9($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X9);
L_800D6870:
    // 0x800D6870: ori         $t0, $t8, 0x2
    ctx->r8 = ctx->r24 | 0X2;
    // 0x800D6874: sb          $t0, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r8;
    // 0x800D6878: andi        $t1, $t0, 0xFE
    ctx->r9 = ctx->r8 & 0XFE;
    // 0x800D687C: sb          $t1, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r9;
L_800D6880:
    // 0x800D6880: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
L_800D6884:
    // 0x800D6884: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x800D6888: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800D688C: addiu       $t4, $t4, -0x4800
    ctx->r12 = ADD32(ctx->r12, -0X4800);
    // 0x800D6890: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800D6894: addu        $v1, $t2, $t4
    ctx->r3 = ADD32(ctx->r10, ctx->r12);
    // 0x800D6898: jal         0x8001211C
    // 0x800D689C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8001211C(rdram, ctx);
        goto after_3;
    // 0x800D689C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_3:
    // 0x800D68A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800D68A4: lui         $at, 0x7FF
    ctx->r1 = S32(0X7FF << 16);
    // 0x800D68A8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D68AC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800D68B0: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x800D68B4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800D68B8: srl         $t5, $a0, 5
    ctx->r13 = S32(U32(ctx->r4) >> 5);
    // 0x800D68BC: xor         $t6, $t3, $t5
    ctx->r14 = ctx->r11 ^ ctx->r13;
    // 0x800D68C0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800D68C4: xor         $t8, $t7, $a0
    ctx->r24 = ctx->r15 ^ ctx->r4;
    // 0x800D68C8: b           L_800D6AFC
    // 0x800D68CC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_800D6AFC;
    // 0x800D68CC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_800D68D0:
    // 0x800D68D0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800D68D4: lh          $t9, -0x419E($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X419E);
    // 0x800D68D8: sltiu       $at, $t9, 0x87
    ctx->r1 = ctx->r25 < 0X87 ? 1 : 0;
    // 0x800D68DC: bne         $at, $zero, L_800D68EC
    if (ctx->r1 != 0) {
        // 0x800D68E0: nop
    
            goto L_800D68EC;
    }
    // 0x800D68E0: nop

    // 0x800D68E4: b           L_800D6AFC
    // 0x800D68E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D6AFC;
    // 0x800D68E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D68EC:
    // 0x800D68EC: jal         0x800D58FC
    // 0x800D68F0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800D58FC(rdram, ctx);
        goto after_4;
    // 0x800D68F0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x800D68F4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800D68F8: jal         0x800D5B34
    // 0x800D68FC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800D5B34(rdram, ctx);
        goto after_5;
    // 0x800D68FC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x800D6900: bne         $v0, $zero, L_800D6918
    if (ctx->r2 != 0) {
        // 0x800D6904: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_800D6918;
    }
    // 0x800D6904: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800D6908: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D690C: sh          $zero, -0x419C($at)
    MEM_H(-0X419C, ctx->r1) = 0;
    // 0x800D6910: b           L_800D6AFC
    // 0x800D6914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D6AFC;
    // 0x800D6914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D6918:
    // 0x800D6918: jal         0x800D6060
    // 0x800D691C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800D6060(rdram, ctx);
        goto after_6;
    // 0x800D691C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x800D6920: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D6924: addiu       $a0, $a0, -0x419E
    ctx->r4 = ADD32(ctx->r4, -0X419E);
    // 0x800D6928: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x800D692C: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x800D6930: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x800D6934: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800D6938: addiu       $t1, $t1, -0x4800
    ctx->r9 = ADD32(ctx->r9, -0X4800);
    // 0x800D693C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800D6940: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x800D6944: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x800D6948: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x800D694C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D6950: sh          $v0, -0x46F0($at)
    MEM_H(-0X46F0, ctx->r1) = ctx->r2;
    // 0x800D6954: jal         0x8001211C
    // 0x800D6958: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_8001211C(rdram, ctx);
        goto after_7;
    // 0x800D6958: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_7:
    // 0x800D695C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800D6960: lui         $at, 0x7FF
    ctx->r1 = S32(0X7FF << 16);
    // 0x800D6964: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D6968: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800D696C: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x800D6970: lbu         $t0, 0xA($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0XA);
    // 0x800D6974: srl         $t5, $a0, 5
    ctx->r13 = S32(U32(ctx->r4) >> 5);
    // 0x800D6978: xor         $t6, $t3, $t5
    ctx->r14 = ctx->r11 ^ ctx->r13;
    // 0x800D697C: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800D6980: xor         $t8, $t7, $a0
    ctx->r24 = ctx->r15 ^ ctx->r4;
    // 0x800D6984: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800D6988: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800D698C: andi        $t2, $t0, 0xFF0F
    ctx->r10 = ctx->r8 & 0XFF0F;
    // 0x800D6990: andi        $t4, $t2, 0xF0
    ctx->r12 = ctx->r10 & 0XF0;
    // 0x800D6994: sb          $t2, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r10;
    // 0x800D6998: sb          $t4, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r12;
    // 0x800D699C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800D69A0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800D69A4: lhu         $t8, 0x8($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X8);
    // 0x800D69A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D69AC: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800D69B0: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x800D69B4: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x800D69B8: sh          $t0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r8;
    // 0x800D69BC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800D69C0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800D69C4: sh          $t1, -0x419C($at)
    MEM_H(-0X419C, ctx->r1) = ctx->r9;
    // 0x800D69C8: sltiu       $at, $t2, 0xB
    ctx->r1 = ctx->r10 < 0XB ? 1 : 0;
    // 0x800D69CC: beq         $at, $zero, L_800D6AF8
    if (ctx->r1 == 0) {
        // 0x800D69D0: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_800D6AF8;
    }
    // 0x800D69D0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800D69D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D69D8: addu        $at, $at, $t2
    gpr jr_addend_800D69E0 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800D69DC: lw          $t2, 0x5C9C($at)
    ctx->r10 = ADD32(ctx->r1, 0X5C9C);
    // 0x800D69E0: jr          $t2
    // 0x800D69E4: nop

    switch (jr_addend_800D69E0 >> 2) {
        case 0: goto L_800D69E8; break;
        case 1: goto L_800D6A5C; break;
        case 2: goto L_800D6AD4; break;
        case 3: goto L_800D6A70; break;
        case 4: goto L_800D6AF8; break;
        case 5: goto L_800D6A84; break;
        case 6: goto L_800D6A98; break;
        case 7: goto L_800D6AAC; break;
        case 8: goto L_800D6AC0; break;
        case 9: goto L_800D6AE8; break;
        case 10: goto L_800D6A70; break;
        default: switch_error(__func__, 0x800D69E0, 0x80125C9C);
    }
    // 0x800D69E4: nop

L_800D69E8:
    // 0x800D69E8: lbu         $t8, 0x9($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X9);
    // 0x800D69EC: lbu         $t4, 0x3($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X3);
    // 0x800D69F0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800D69F4: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x800D69F8: andi        $t3, $t4, 0xFFE1
    ctx->r11 = ctx->r12 & 0XFFE1;
    // 0x800D69FC: ori         $t5, $t3, 0x4
    ctx->r13 = ctx->r11 | 0X4;
    // 0x800D6A00: sb          $t9, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r25;
    // 0x800D6A04: andi        $t0, $t9, 0xFE
    ctx->r8 = ctx->r25 & 0XFE;
    // 0x800D6A08: sb          $t5, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r13;
    // 0x800D6A0C: sb          $t0, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r8;
    // 0x800D6A10: sb          $zero, 0xB($v1)
    MEM_B(0XB, ctx->r3) = 0;
    // 0x800D6A14: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    // 0x800D6A18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D6A1C: beq         $a0, $zero, L_800D6A2C
    if (ctx->r4 == 0) {
        // 0x800D6A20: nop
    
            goto L_800D6A2C;
    }
    // 0x800D6A20: nop

    // 0x800D6A24: b           L_800D6A2C
    // 0x800D6A28: addu        $a1, $v0, $a0
    ctx->r5 = ADD32(ctx->r2, ctx->r4);
        goto L_800D6A2C;
    // 0x800D6A28: addu        $a1, $v0, $a0
    ctx->r5 = ADD32(ctx->r2, ctx->r4);
L_800D6A2C:
    // 0x800D6A2C: beql        $a1, $zero, L_800D6AFC
    if (ctx->r5 == 0) {
        // 0x800D6A30: lw          $v0, 0x28($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X28);
            goto L_800D6AFC;
    }
    goto skip_5;
    // 0x800D6A30: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    skip_5:
    // 0x800D6A34: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800D6A38: jal         0x800DBA84
    // 0x800D6A3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DBA84(rdram, ctx);
        goto after_8;
    // 0x800D6A3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_8:
    // 0x800D6A40: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800D6A44: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800D6A48: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x800D6A4C: jal         0x800DBBF8
    // 0x800D6A50: sb          $v0, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r2;
    func_800DBBF8(rdram, ctx);
        goto after_9;
    // 0x800D6A50: sb          $v0, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r2;
    after_9:
    // 0x800D6A54: b           L_800D6AFC
    // 0x800D6A58: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_800D6AFC;
    // 0x800D6A58: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_800D6A5C:
    // 0x800D6A5C: lbu         $t1, 0x3($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X3);
    // 0x800D6A60: andi        $t2, $t1, 0xFFE1
    ctx->r10 = ctx->r9 & 0XFFE1;
    // 0x800D6A64: ori         $t4, $t2, 0x2
    ctx->r12 = ctx->r10 | 0X2;
    // 0x800D6A68: b           L_800D6AF8
    // 0x800D6A6C: sb          $t4, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r12;
        goto L_800D6AF8;
    // 0x800D6A6C: sb          $t4, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r12;
L_800D6A70:
    // 0x800D6A70: lbu         $t3, 0x3($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X3);
    // 0x800D6A74: andi        $t5, $t3, 0xFFE1
    ctx->r13 = ctx->r11 & 0XFFE1;
    // 0x800D6A78: ori         $t6, $t5, 0x8
    ctx->r14 = ctx->r13 | 0X8;
    // 0x800D6A7C: b           L_800D6AF8
    // 0x800D6A80: sb          $t6, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r14;
        goto L_800D6AF8;
    // 0x800D6A80: sb          $t6, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r14;
L_800D6A84:
    // 0x800D6A84: lbu         $t8, 0x3($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3);
    // 0x800D6A88: andi        $t7, $t8, 0xFFE1
    ctx->r15 = ctx->r24 & 0XFFE1;
    // 0x800D6A8C: ori         $t9, $t7, 0x6
    ctx->r25 = ctx->r15 | 0X6;
    // 0x800D6A90: b           L_800D6AF8
    // 0x800D6A94: sb          $t9, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r25;
        goto L_800D6AF8;
    // 0x800D6A94: sb          $t9, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r25;
L_800D6A98:
    // 0x800D6A98: lbu         $t0, 0x3($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X3);
    // 0x800D6A9C: andi        $t1, $t0, 0xFFE1
    ctx->r9 = ctx->r8 & 0XFFE1;
    // 0x800D6AA0: ori         $t2, $t1, 0xA
    ctx->r10 = ctx->r9 | 0XA;
    // 0x800D6AA4: b           L_800D6AF8
    // 0x800D6AA8: sb          $t2, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r10;
        goto L_800D6AF8;
    // 0x800D6AA8: sb          $t2, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r10;
L_800D6AAC:
    // 0x800D6AAC: lbu         $t4, 0x3($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X3);
    // 0x800D6AB0: andi        $t3, $t4, 0xFFE1
    ctx->r11 = ctx->r12 & 0XFFE1;
    // 0x800D6AB4: ori         $t5, $t3, 0xC
    ctx->r13 = ctx->r11 | 0XC;
    // 0x800D6AB8: b           L_800D6AF8
    // 0x800D6ABC: sb          $t5, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r13;
        goto L_800D6AF8;
    // 0x800D6ABC: sb          $t5, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r13;
L_800D6AC0:
    // 0x800D6AC0: lbu         $t6, 0x3($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3);
    // 0x800D6AC4: andi        $t8, $t6, 0xFFE1
    ctx->r24 = ctx->r14 & 0XFFE1;
    // 0x800D6AC8: ori         $t7, $t8, 0xE
    ctx->r15 = ctx->r24 | 0XE;
    // 0x800D6ACC: b           L_800D6AF8
    // 0x800D6AD0: sb          $t7, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r15;
        goto L_800D6AF8;
    // 0x800D6AD0: sb          $t7, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r15;
L_800D6AD4:
    // 0x800D6AD4: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
    // 0x800D6AD8: andi        $t0, $t9, 0xFFE1
    ctx->r8 = ctx->r25 & 0XFFE1;
    // 0x800D6ADC: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x800D6AE0: b           L_800D6AF8
    // 0x800D6AE4: sb          $t1, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r9;
        goto L_800D6AF8;
    // 0x800D6AE4: sb          $t1, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r9;
L_800D6AE8:
    // 0x800D6AE8: lbu         $t2, 0x3($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X3);
    // 0x800D6AEC: andi        $t4, $t2, 0xFFE1
    ctx->r12 = ctx->r10 & 0XFFE1;
    // 0x800D6AF0: ori         $t3, $t4, 0x12
    ctx->r11 = ctx->r12 | 0X12;
    // 0x800D6AF4: sb          $t3, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r11;
L_800D6AF8:
    // 0x800D6AF8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_800D6AFC:
    // 0x800D6AFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D6B00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800D6B04: jr          $ra
    // 0x800D6B08: nop

    return;
    // 0x800D6B08: nop

;}
RECOMP_FUNC void inantab_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808065B4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x808065B8: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x808065BC: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2958, 0X6E30) << 16);
    // 0x808065C0: addiu       $t7, $t7, 0x6E30
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2958, 0X6E30));
    // 0x808065C4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x808065C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808065CC: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x808065D0: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x808065D4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808065D8: lbu         $a0, 0x15($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X15);
    // 0x808065DC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808065E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808065E4: beq         $v0, $zero, L_80806610
    if (ctx->r2 == 0) {
        // 0x808065E8: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80806610;
    }
    // 0x808065E8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808065EC: lbu         $t8, 0x14($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X14);
    // 0x808065F0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x808065F4: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
    // 0x808065F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808065FC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80806600: jal         0x800E1664
    // 0x80806604: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_800E1664(rdram, ctx);
        goto after_0;
    // 0x80806604: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x80806608: b           L_808066B4
    // 0x8080660C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808066B4;
    // 0x8080660C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80806610:
    // 0x80806610: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80806614: jal         0x800E1540
    // 0x80806618: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800E1540(rdram, ctx);
        goto after_1;
    // 0x80806618: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x8080661C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80806620: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80806624: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80806628: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8080662C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80806630: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80806634: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x80806638: nop

    // 0x8080663C: bc1tl       L_80806658
    if (c1cs) {
        // 0x80806640: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80806658;
    }
    goto skip_0;
    // 0x80806640: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_0:
    // 0x80806644: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80806648: jal         0x800E13F0
    // 0x8080664C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800E13F0(rdram, ctx);
        goto after_2;
    // 0x8080664C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x80806650: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80806654: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_80806658:
    // 0x80806658: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080665C: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80806660: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80806664: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x80806668: nop

    // 0x8080666C: bc1tl       L_8080668C
    if (c1cs) {
        // 0x80806670: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8080668C;
    }
    goto skip_1;
    // 0x80806670: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_1:
    // 0x80806674: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80806678: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
    // 0x8080667C: jal         0x800E1410
    // 0x80806680: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800E1410(rdram, ctx);
        goto after_3;
    // 0x80806680: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x80806684: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80806688: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_8080668C:
    // 0x8080668C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80806690: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80806694: c.eq.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl == ctx->f0.fl;
    // 0x80806698: nop

    // 0x8080669C: bc1tl       L_808066B4
    if (c1cs) {
        // 0x808066A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808066B4;
    }
    goto skip_2;
    // 0x808066A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808066A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808066A8: jal         0x800E144C
    // 0x808066AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800E144C(rdram, ctx);
        goto after_4;
    // 0x808066AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x808066B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808066B4:
    // 0x808066B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808066B8: jr          $ra
    // 0x808066BC: nop

    return;
    // 0x808066BC: nop

;}
RECOMP_FUNC void baeggsetup_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003F8: jal         0x800F53D0
    // 0x808003FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x808003FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800400: lw          $a2, 0x70($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X70);
    // 0x80800404: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800408: lbu         $a1, 0x24($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X24);
    // 0x8080040C: addiu       $t6, $a2, 0x18
    ctx->r14 = ADD32(ctx->r6, 0X18);
    // 0x80800410: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800414: jal         0x808002B4
    // 0x80800418: addiu       $a3, $a2, 0xC
    ctx->r7 = ADD32(ctx->r6, 0XC);
    baeggsetup_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800418: addiu       $a3, $a2, 0xC
    ctx->r7 = ADD32(ctx->r6, 0XC);
    after_1:
    // 0x8080041C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800420: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800424: jr          $ra
    // 0x80800428: nop

    return;
    // 0x80800428: nop

;}
RECOMP_FUNC void basetup_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B20: jr          $ra
    // 0x80800B24: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800B24: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80092EA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092EA4: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092EA8: jr          $ra
    // 0x80092EAC: lbu         $v0, 0x17($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X17);
    return;
    // 0x80092EAC: lbu         $v0, 0x17($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X17);
;}
RECOMP_FUNC void chweather_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(732, 0X4D0) << 16);
    // 0x808000F4: jr          $ra
    // 0x808000F8: addiu       $v0, $v0, 0x4D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(732, 0X4D0));
    return;
    // 0x808000F8: addiu       $v0, $v0, 0x4D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(732, 0X4D0));
;}
RECOMP_FUNC void _chcablecar_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E50: syscall     248
    recomp_syscall_handler(rdram, ctx, 0x80085E50);
    return;
    // 0x80085E54: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void suquiz_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DF0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80800DF4: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80800DF8: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80800DFC: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80800E00: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80800E04: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800E08: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(3370, 0X10FC) << 16);
    // 0x80800E0C: addiu       $t9, $t9, 0x10FC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(3370, 0X10FC));
    // 0x80800E10: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800E14: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80800E18: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3370, 0XF60) << 16);
    // 0x80800E1C: lwc1        $f6, 0xF60($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3370, 0XF60));
    // 0x80800E20: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800E24: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E2C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800E30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800E38: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800E3C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800E40: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80800E44: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80800E48: nop

    // 0x80800E4C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80800E50: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80800E54: nop

    // 0x80800E58: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80800E5C: beql        $t1, $zero, L_80800EAC
    if (ctx->r9 == 0) {
        // 0x80800E60: mfc1        $t1, $f10
        ctx->r9 = (int32_t)ctx->f10.u32l;
            goto L_80800EAC;
    }
    goto skip_0;
    // 0x80800E60: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x80800E64: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800E68: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800E6C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800E70: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80800E74: nop

    // 0x80800E78: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800E7C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80800E80: nop

    // 0x80800E84: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80800E88: bne         $t1, $zero, L_80800EA0
    if (ctx->r9 != 0) {
        // 0x80800E8C: nop
    
            goto L_80800EA0;
    }
    // 0x80800E8C: nop

    // 0x80800E90: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80800E94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800E98: b           L_80800EB8
    // 0x80800E9C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80800EB8;
    // 0x80800E9C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80800EA0:
    // 0x80800EA0: b           L_80800EB8
    // 0x80800EA4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80800EB8;
    // 0x80800EA4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80800EA8: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
L_80800EAC:
    // 0x80800EAC: nop

    // 0x80800EB0: bltz        $t1, L_80800EA0
    if (SIGNED(ctx->r9) < 0) {
        // 0x80800EB4: nop
    
            goto L_80800EA0;
    }
    // 0x80800EB4: nop

L_80800EB8:
    // 0x80800EB8: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80800EBC: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80800EC0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80800EC4: sra         $t7, $t6, 5
    ctx->r15 = S32(SIGNED(ctx->r14) >> 5);
    // 0x80800EC8: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80800ECC: sll         $t9, $t8, 11
    ctx->r25 = S32(ctx->r24 << 11);
    // 0x80800ED0: andi        $t5, $t4, 0x7FF
    ctx->r13 = ctx->r12 & 0X7FF;
    // 0x80800ED4: addu        $t0, $t5, $t9
    ctx->r8 = ADD32(ctx->r13, ctx->r25);
    // 0x80800ED8: sll         $t3, $t1, 21
    ctx->r11 = S32(ctx->r9 << 21);
    // 0x80800EDC: jal         0x800C3F48
    // 0x80800EE0: addu        $a0, $t3, $t0
    ctx->r4 = ADD32(ctx->r11, ctx->r8);
    func_800C3F48(rdram, ctx);
        goto after_0;
    // 0x80800EE0: addu        $a0, $t3, $t0
    ctx->r4 = ADD32(ctx->r11, ctx->r8);
    after_0:
    // 0x80800EE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800EEC: jr          $ra
    // 0x80800EF0: nop

    return;
    // 0x80800EF0: nop

    // 0x80800EF4: nop

    // 0x80800EF8: nop

    // 0x80800EFC: nop

;}
