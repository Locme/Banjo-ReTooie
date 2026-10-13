#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800A51E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A51E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A51EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A51F0: jal         0x800F54E4
    // 0x800A51F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800A51F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A51F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A51FC: jal         0x800878C8
    // 0x800A5200: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _plcamera_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x800A5200: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800A5204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A520C: jr          $ra
    // 0x800A5210: nop

    return;
    // 0x800A5210: nop

;}
RECOMP_FUNC void bsbwhirl_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800714: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080071C: jal         0x8080017C
    // 0x80800720: nop

    func_8080017C_bsbwhirl(rdram, ctx);
        goto after_0;
    // 0x80800720: nop

    after_0:
    // 0x80800724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080072C: jr          $ra
    // 0x80800730: nop

    return;
    // 0x80800730: nop

;}
RECOMP_FUNC void func_800E6BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6BAC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800E6BB0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800E6BB4: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x800E6BB8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800E6BBC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E6BC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E6BC4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800E6BC8: jal         0x800E6B7C
    // 0x800E6BCC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_800E6B7C(rdram, ctx);
        goto after_0;
    // 0x800E6BCC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x800E6BD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E6BD4: beq         $v0, $at, L_800E6C08
    if (ctx->r2 == ctx->r1) {
        // 0x800E6BD8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800E6C08;
    }
    // 0x800E6BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E6BDC: beq         $v0, $zero, L_800E6BF8
    if (ctx->r2 == 0) {
        // 0x800E6BE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800E6BF8;
    }
    // 0x800E6BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E6BE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E6BE8: beql        $v0, $at, L_800E6C1C
    if (ctx->r2 == ctx->r1) {
        // 0x800E6BEC: trunc.w.s   $f4, $f20
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = TRUNC_W_S(ctx->f20.fl);
            goto L_800E6C1C;
    }
    goto skip_0;
    // 0x800E6BEC: trunc.w.s   $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = TRUNC_W_S(ctx->f20.fl);
    skip_0:
    // 0x800E6BF0: b           L_800E6C98
    // 0x800E6BF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800E6C98;
    // 0x800E6BF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E6BF8:
    // 0x800E6BF8: jal         0x800E6A10
    // 0x800E6BFC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800E6A10(rdram, ctx);
        goto after_1;
    // 0x800E6BFC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x800E6C00: b           L_800E6C98
    // 0x800E6C04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800E6C98;
    // 0x800E6C04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E6C08:
    // 0x800E6C08: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800E6C0C: jal         0x800E6A10
    // 0x800E6C10: addiu       $a1, $a1, 0x5DC4
    ctx->r5 = ADD32(ctx->r5, 0X5DC4);
    func_800E6A10(rdram, ctx);
        goto after_2;
    // 0x800E6C10: addiu       $a1, $a1, 0x5DC4
    ctx->r5 = ADD32(ctx->r5, 0X5DC4);
    after_2:
    // 0x800E6C14: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x800E6C18: trunc.w.s   $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = TRUNC_W_S(ctx->f20.fl);
L_800E6C1C:
    // 0x800E6C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E6C20: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800E6C24: jal         0x800E6DB4
    // 0x800E6C28: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_800E6DB4(rdram, ctx);
        goto after_3;
    // 0x800E6C28: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_3:
    // 0x800E6C2C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800E6C30: addiu       $a1, $a1, 0x5DC8
    ctx->r5 = ADD32(ctx->r5, 0X5DC8);
    // 0x800E6C34: jal         0x800E6A10
    // 0x800E6C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E6A10(rdram, ctx);
        goto after_4;
    // 0x800E6C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800E6C3C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800E6C40: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800E6C44: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800E6C48: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800E6C4C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800E6C50: addiu       $a1, $a1, 0x5DCC
    ctx->r5 = ADD32(ctx->r5, 0X5DCC);
    // 0x800E6C54: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E6C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E6C5C: sub.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x800E6C60: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800E6C64: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800E6C68: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800E6C6C: nop

    // 0x800E6C70: slti        $at, $a2, 0xA
    ctx->r1 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x800E6C74: beql        $at, $zero, L_800E6C8C
    if (ctx->r1 == 0) {
        // 0x800E6C78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800E6C8C;
    }
    goto skip_1;
    // 0x800E6C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x800E6C7C: jal         0x800E6A10
    // 0x800E6C80: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_800E6A10(rdram, ctx);
        goto after_5;
    // 0x800E6C80: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_5:
    // 0x800E6C84: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800E6C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800E6C8C:
    // 0x800E6C8C: jal         0x800E6DB4
    // 0x800E6C90: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800E6DB4(rdram, ctx);
        goto after_6;
    // 0x800E6C90: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_6:
    // 0x800E6C94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E6C98:
    // 0x800E6C98: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800E6C9C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800E6CA0: jr          $ra
    // 0x800E6CA4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800E6CA4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8080000C_chchompaslunch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x80088848
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080001C: bnel        $v0, $zero, L_80800030
    if (ctx->r2 != 0) {
        // 0x80800020: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_80800030;
    }
    goto skip_0;
    // 0x80800020: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    skip_0:
    // 0x80800024: jal         0x800FFAB0
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080002C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
L_80800030:
    // 0x80800030: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800034: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800038: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080003C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800040: jal         0x800DC128
    // 0x80800044: swc1        $f4, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f4.u32l;
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x80800044: swc1        $f4, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f4.u32l;
    after_2:
    // 0x80800048: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8080004C: andi        $t8, $v0, 0x1FF
    ctx->r24 = ctx->r2 & 0X1FF;
    // 0x80800050: lhu         $t0, 0x6E($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6E);
    // 0x80800054: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x80800058: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x8080005C: sh          $t2, 0x6E($t9)
    MEM_H(0X6E, ctx->r25) = ctx->r10;
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void func_800EE100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE100: jr          $ra
    // 0x800EE104: sh          $a1, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = ctx->r5;
    return;
    // 0x800EE104: sh          $a1, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void _bsbtrot_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082CC8: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082CC8);
    return;
    // 0x80082CCC: addi        $t0, $zero, 0x84
    ctx->r8 = ADD32(0, 0X84);
;}
RECOMP_FUNC void _bswalk_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800841D8: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x800841D8);
    return;
    // 0x800841DC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void sumumbofx_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012E8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808012EC: lbu         $t6, 0x60($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X60);
    // 0x808012F0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x808012F4: andi        $t7, $t6, 0xFF01
    ctx->r15 = ctx->r14 & 0XFF01;
    // 0x808012F8: jal         0x8080134C
    // 0x808012FC: sb          $t7, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r15;
    sumumbofx_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x808012FC: sb          $t7, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r15;
    after_0:
    // 0x80801300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801308: jr          $ra
    // 0x8080130C: nop

    return;
    // 0x8080130C: nop

;}
RECOMP_FUNC void func_800133A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800133A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800133A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800133A8: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800133AC: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800133B0: addiu       $a1, $a1, 0x69F8
    ctx->r5 = ADD32(ctx->r5, 0X69F8);
    // 0x800133B4: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    // 0x800133B8: jal         0x8002E070
    // 0x800133BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800133BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800133C0: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800133C4: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800133C8: addiu       $a1, $a1, 0x6A18
    ctx->r5 = ADD32(ctx->r5, 0X6A18);
    // 0x800133CC: addiu       $a0, $a0, 0x6A00
    ctx->r4 = ADD32(ctx->r4, 0X6A00);
    // 0x800133D0: jal         0x8002E070
    // 0x800133D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x800133D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800133D8: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x800133DC: addiu       $t6, $t6, 0x73E0
    ctx->r14 = ADD32(ctx->r14, 0X73E0);
    // 0x800133E0: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800133E4: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800133E8: lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // 0x800133EC: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x800133F0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800133F4: addiu       $a3, $a3, 0x3544
    ctx->r7 = ADD32(ctx->r7, 0X3544);
    // 0x800133F8: addiu       $a1, $a1, 0x6BD0
    ctx->r5 = ADD32(ctx->r5, 0X6BD0);
    // 0x800133FC: addiu       $a0, $a0, 0x6A20
    ctx->r4 = ADD32(ctx->r4, 0X6A20);
    // 0x80013400: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80013404: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80013408: jal         0x8001DCB0
    // 0x8001340C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001DCB0(rdram, ctx);
        goto after_2;
    // 0x8001340C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80013410: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80013414: jal         0x8002E510
    // 0x80013418: addiu       $a0, $a0, 0x6A20
    ctx->r4 = ADD32(ctx->r4, 0X6A20);
    osStartThread_recomp(rdram, ctx);
        goto after_3;
    // 0x80013418: addiu       $a0, $a0, 0x6A20
    ctx->r4 = ADD32(ctx->r4, 0X6A20);
    after_3:
    // 0x8001341C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80013420: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013424: sw          $zero, 0x73E0($at)
    MEM_W(0X73E0, ctx->r1) = 0;
    // 0x80013428: jr          $ra
    // 0x8001342C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001342C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800900D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800900D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800900D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800900D8: jal         0x800F54E4
    // 0x800900DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800900DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800900E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800900E4: jal         0x800F63B4
    // 0x800900E8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F63B4(rdram, ctx);
        goto after_1;
    // 0x800900E8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800900EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800900F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800900F4: jr          $ra
    // 0x800900F8: nop

    return;
    // 0x800900F8: nop

;}
RECOMP_FUNC void func_80104170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104170: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104178: jal         0x8008B4F4
    // 0x8010417C: nop

    func_8008B4F4(rdram, ctx);
        goto after_0;
    // 0x8010417C: nop

    after_0:
    // 0x80104180: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80104184: jal         0x800B3268
    // 0x80104188: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    freelist_new(rdram, ctx);
        goto after_1;
    // 0x80104188: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_1:
    // 0x8010418C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104190: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80104194: sw          $v0, 0x6E70($at)
    MEM_W(0X6E70, ctx->r1) = ctx->r2;
    // 0x80104198: jr          $ra
    // 0x8010419C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010419C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _subaddiefind_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C48: syscall     807
    recomp_syscall_handler(rdram, ctx, 0x80089C48);
    return;
    // 0x80089C4C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800FC3D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC3D8: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800FC3DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FC3E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FC3E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FC3E8: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x800FC3EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FC3F0: bc1f        L_800FC400
    if (!c1cs) {
        // 0x800FC3F4: nop
    
            goto L_800FC400;
    }
    // 0x800FC3F4: nop

    // 0x800FC3F8: b           L_800FC4A0
    // 0x800FC3FC: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
        goto L_800FC4A0;
    // 0x800FC3FC: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
L_800FC400:
    // 0x800FC400: bne         $a2, $at, L_800FC420
    if (ctx->r6 != ctx->r1) {
        // 0x800FC404: nop
    
            goto L_800FC420;
    }
    // 0x800FC404: nop

    // 0x800FC408: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800FC40C: jal         0x80017764
    // 0x800FC410: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_80017764(rdram, ctx);
        goto after_0;
    // 0x800FC410: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800FC414: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC418: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800FC41C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800FC420:
    // 0x800FC420: bnel        $a1, $a2, L_800FC434
    if (ctx->r5 != ctx->r6) {
        // 0x800FC424: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_800FC434;
    }
    goto skip_0;
    // 0x800FC424: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_0:
    // 0x800FC428: b           L_800FC4A0
    // 0x800FC42C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800FC4A0;
    // 0x800FC42C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800FC430: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_800FC434:
    // 0x800FC434: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800FC438: c.eq.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl == ctx->f6.fl;
    // 0x800FC43C: nop

    // 0x800FC440: bc1fl       L_800FC454
    if (!c1cs) {
        // 0x800FC444: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_800FC454;
    }
    goto skip_1;
    // 0x800FC444: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_1:
    // 0x800FC448: b           L_800FC49C
    // 0x800FC44C: subu        $v1, $a1, $a2
    ctx->r3 = SUB32(ctx->r5, ctx->r6);
        goto L_800FC49C;
    // 0x800FC44C: subu        $v1, $a1, $a2
    ctx->r3 = SUB32(ctx->r5, ctx->r6);
    // 0x800FC450: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_800FC454:
    // 0x800FC454: subu        $t6, $a1, $a2
    ctx->r14 = SUB32(ctx->r5, ctx->r6);
    // 0x800FC458: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800FC45C: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800FC460: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FC464: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FC468: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800FC46C: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800FC470: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800FC474: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800FC478: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800FC47C: nop

    // 0x800FC480: bgez        $v0, L_800FC490
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800FC484: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800FC490;
    }
    // 0x800FC484: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800FC488: b           L_800FC49C
    // 0x800FC48C: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_800FC49C;
    // 0x800FC48C: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_800FC490:
    // 0x800FC490: bnel        $v0, $zero, L_800FC4A0
    if (ctx->r2 != 0) {
        // 0x800FC494: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800FC4A0;
    }
    goto skip_2;
    // 0x800FC494: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_2:
    // 0x800FC498: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800FC49C:
    // 0x800FC49C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800FC4A0:
    // 0x800FC4A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FC4A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FC4A8: jr          $ra
    // 0x800FC4AC: nop

    return;
    // 0x800FC4AC: nop

;}
RECOMP_FUNC void func_80804AA4_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804AA4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80804AA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804AAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804AB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80804AB4: jal         0x80100094
    // 0x80804AB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804AB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804ABC: jal         0x800D8FF8
    // 0x80804AC0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80804AC0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_1:
    // 0x80804AC4: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x80804AC8: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80804ACC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804AD0: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80804AD4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80804AD8: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x80804ADC: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80804AE0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80804AE4: bnel        $t7, $at, L_80804C5C
    if (ctx->r15 != ctx->r1) {
        // 0x80804AE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80804C5C;
    }
    goto skip_0;
    // 0x80804AE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80804AEC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80804AF0: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80804AF4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80804AF8: nop

    // 0x80804AFC: bc1tl       L_80804B14
    if (c1cs) {
        // 0x80804B00: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_80804B14;
    }
    goto skip_1;
    // 0x80804B00: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    skip_1:
    // 0x80804B04: jal         0x808048AC
    // 0x80804B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808048AC_chdragonbrothers(rdram, ctx);
        goto after_2;
    // 0x80804B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80804B0C: bne         $v0, $zero, L_80804C58
    if (ctx->r2 != 0) {
        // 0x80804B10: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_80804C58;
    }
    // 0x80804B10: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
L_80804B14:
    // 0x80804B14: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80804B18: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80804B1C: jal         0x800EE7F8
    // 0x80804B20: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80804B20: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_3:
    // 0x80804B24: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80804B28: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80804B2C: jal         0x800EFA20
    // 0x80804B30: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    func_800EFA20(rdram, ctx);
        goto after_4;
    // 0x80804B30: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    after_4:
    // 0x80804B34: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80804B38: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80804B3C: jal         0x800EE780
    // 0x80804B40: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    func_800EE780(rdram, ctx);
        goto after_5;
    // 0x80804B40: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_5:
    // 0x80804B44: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80804B48: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80804B4C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80804B50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80804B54: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80804B58: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80804B5C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80804B60: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80804B64: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80804B68: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x80804B6C: bc1f        L_80804B84
    if (!c1cs) {
        // 0x80804B70: swc1        $f4, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
            goto L_80804B84;
    }
    // 0x80804B70: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80804B74: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80804B78: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80804B7C: b           L_80804BA8
    // 0x80804B80: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80804BA8;
    // 0x80804B80: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_80804B84:
    // 0x80804B84: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80804B88: jal         0x800C6A7C
    // 0x80804B8C: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    func_800C6A7C(rdram, ctx);
        goto after_6;
    // 0x80804B8C: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    after_6:
    // 0x80804B90: beql        $v0, $zero, L_80804BAC
    if (ctx->r2 == 0) {
        // 0x80804B94: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80804BAC;
    }
    goto skip_2;
    // 0x80804B94: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80804B98: jal         0x808049D4
    // 0x80804B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808049D4_chdragonbrothers(rdram, ctx);
        goto after_7;
    // 0x80804B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80804BA0: jal         0x800FFAB0
    // 0x80804BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_8;
    // 0x80804BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80804BA8:
    // 0x80804BA8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_80804BAC:
    // 0x80804BAC: jal         0x800EE7F8
    // 0x80804BB0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x80804BB0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_9:
    // 0x80804BB4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80804BB8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80804BBC: jal         0x800EFA20
    // 0x80804BC0: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    func_800EFA20(rdram, ctx);
        goto after_10;
    // 0x80804BC0: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    after_10:
    // 0x80804BC4: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x80804BC8: jal         0x800EF04C
    // 0x80804BCC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x80804BCC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_11:
    // 0x80804BD0: jal         0x80804610
    // 0x80804BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804610_chdragonbrothers(rdram, ctx);
        goto after_12;
    // 0x80804BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80804BD8: jal         0x808046CC
    // 0x80804BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808046CC_chdragonbrothers(rdram, ctx);
        goto after_13;
    // 0x80804BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80804BE0: lbu         $t8, 0x79($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X79);
    // 0x80804BE4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804BEC: srl         $t9, $t8, 4
    ctx->r25 = S32(U32(ctx->r24) >> 4);
    // 0x80804BF0: bne         $t9, $at, L_80804C08
    if (ctx->r25 != ctx->r1) {
        // 0x80804BF4: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80804C08;
    }
    // 0x80804BF4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80804BF8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1852, 0X59EC) << 16);
    // 0x80804BFC: addiu       $a3, $a3, 0x59EC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1852, 0X59EC));
    // 0x80804C00: jal         0x80089D50
    // 0x80804C04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_14;
    // 0x80804C04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
L_80804C08:
    // 0x80804C08: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x80804C0C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80804C10: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80804C14: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80804C18: nop

    // 0x80804C1C: bc1fl       L_80804C5C
    if (!c1cs) {
        // 0x80804C20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80804C5C;
    }
    goto skip_3;
    // 0x80804C20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80804C24: jal         0x80106790
    // 0x80804C28: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_15;
    // 0x80804C28: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_15:
    // 0x80804C2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80804C30: jal         0x80100094
    // 0x80804C34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_16;
    // 0x80804C34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80804C38: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80804C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804C40: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x80804C44: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80804C48: lb          $t2, 0x60($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X60);
    // 0x80804C4C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80804C50: jal         0x80089CA8
    // 0x80804C54: sb          $t3, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r11;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_17;
    // 0x80804C54: sb          $t3, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r11;
    after_17:
L_80804C58:
    // 0x80804C58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804C5C:
    // 0x80804C5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804C60: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80804C64: jr          $ra
    // 0x80804C68: nop

    return;
    // 0x80804C68: nop

;}
RECOMP_FUNC void func_808014C8_chcaptainblubber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808014CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808014D0: jal         0x800897C8
    // 0x808014D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808014D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808014D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808014DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808014E0: jr          $ra
    // 0x808014E4: nop

    return;
    // 0x808014E4: nop

;}
RECOMP_FUNC void func_80800278_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800278: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080027C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800280: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800284: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800288: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8080028C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800290: jal         0x80098140
    // 0x80800294: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bainput_enable(rdram, ctx);
        goto after_0;
    // 0x80800294: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80800298: lui         $a1, 0x3E38
    ctx->r5 = S32(0X3E38 << 16);
    // 0x8080029C: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x808002A0: jal         0x8008CB10
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_1;
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808002A8: beq         $v0, $zero, L_808002BC
    if (ctx->r2 == 0) {
        // 0x808002AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002BC;
    }
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B0: addiu       $a1, $zero, 0x58C
    ctx->r5 = ADD32(0, 0X58C);
    // 0x808002B4: jal         0x8009DF58
    // 0x808002B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DF58(rdram, ctx);
        goto after_2;
    // 0x808002B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_2:
L_808002BC:
    // 0x808002BC: lui         $a1, 0x3E61
    ctx->r5 = S32(0X3E61 << 16);
    // 0x808002C0: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    // 0x808002C4: jal         0x8008CB10
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_3;
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002CC: beq         $v0, $zero, L_808002E4
    if (ctx->r2 == 0) {
        // 0x808002D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002E4;
    }
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D4: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x808002D8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808002DC: jal         0x8009DB04
    // 0x808002E0: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DB04(rdram, ctx);
        goto after_4;
    // 0x808002E0: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_4:
L_808002E4:
    // 0x808002E4: lui         $a1, 0x3DF2
    ctx->r5 = S32(0X3DF2 << 16);
    // 0x808002E8: ori         $a1, $a1, 0x7BB3
    ctx->r5 = ctx->r5 | 0X7BB3;
    // 0x808002EC: jal         0x8008CB10
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_5;
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808002F4: beq         $v0, $zero, L_80800310
    if (ctx->r2 == 0) {
        // 0x808002F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800310;
    }
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002FC: jal         0x800A0CD0
    // 0x80800300: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CD0(rdram, ctx);
        goto after_6;
    // 0x80800300: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800308: jal         0x80084538
    // 0x8080030C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _babackpack_set_state(rdram, ctx);
        goto after_7;
    // 0x8080030C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
L_80800310:
    // 0x80800310: lui         $a1, 0x3EBD
    ctx->r5 = S32(0X3EBD << 16);
    // 0x80800314: ori         $a1, $a1, 0x97F6
    ctx->r5 = ctx->r5 | 0X97F6;
    // 0x80800318: jal         0x8008CB10
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_8;
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800320: beq         $v0, $zero, L_80800334
    if (ctx->r2 == 0) {
        // 0x80800324: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800334;
    }
    // 0x80800324: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800328: sb          $t6, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = ctx->r14;
    // 0x8080032C: jal         0x80800098
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800098_bsbansnooze(rdram, ctx);
        goto after_9;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80800334:
    // 0x80800334: jal         0x8008CAEC
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_10;
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080033C: beq         $v0, $zero, L_8080034C
    if (ctx->r2 == 0) {
        // 0x80800340: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080034C;
    }
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800344: addiu       $t7, $zero, 0x16F
    ctx->r15 = ADD32(0, 0X16F);
    // 0x80800348: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_8080034C:
    // 0x8080034C: jal         0x8009E5C8
    // 0x80800350: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_11;
    // 0x80800350: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x80800354: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800358: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080035C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800360: jr          $ra
    // 0x80800364: nop

    return;
    // 0x80800364: nop

;}
RECOMP_FUNC void _glhittableDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088608: syscall     696
    recomp_syscall_handler(rdram, ctx, 0x80088608);
    return;
    // 0x8008860C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800000_cadbio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800014: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800018: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080001C: jal         0x800825C8
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800024: bne         $v0, $zero, L_80800390
    if (ctx->r2 != 0) {
        // 0x80800028: addiu       $s3, $sp, 0x30
        ctx->r19 = ADD32(ctx->r29, 0X30);
            goto L_80800390;
    }
    // 0x80800028: addiu       $s3, $sp, 0x30
    ctx->r19 = ADD32(ctx->r29, 0X30);
    // 0x8080002C: addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
    // 0x80800030: addiu       $s1, $sp, 0x3C
    ctx->r17 = ADD32(ctx->r29, 0X3C);
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800038:
    // 0x80800038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080003C: jal         0x800825F0
    // 0x80800040: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    _gsmaker_entrypoint_21(rdram, ctx);
        goto after_1;
    // 0x80800040: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80800044: bne         $v0, $zero, L_8080037C
    if (ctx->r2 != 0) {
        // 0x80800048: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080037C;
    }
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800050: jal         0x800825F0
    // 0x80800054: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _gsmaker_entrypoint_21(rdram, ctx);
        goto after_2;
    // 0x80800054: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80800058: beq         $v0, $zero, L_80800074
    if (ctx->r2 == 0) {
        // 0x8080005C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800074;
    }
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800064: jal         0x800A58A8
    // 0x80800068: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800A58A8(rdram, ctx);
        goto after_3;
    // 0x80800068: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8080006C: b           L_80800380
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800074:
    // 0x80800074: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800078: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8080007C: jal         0x800825E8
    // 0x80800080: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _gsmaker_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x80800080: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_4:
    // 0x80800084: beq         $v0, $zero, L_808000A4
    if (ctx->r2 == 0) {
        // 0x80800088: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000A4;
    }
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: jal         0x80085588
    // 0x80800090: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _cadbfunc_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800090: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80800094: bnel        $v0, $zero, L_80800380
    if (ctx->r2 != 0) {
        // 0x80800098: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    goto skip_0;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080009C: b           L_80800380
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000A4:
    // 0x808000A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808000A8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808000AC: jal         0x800825E8
    // 0x808000B0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _gsmaker_entrypoint_20(rdram, ctx);
        goto after_6;
    // 0x808000B0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x808000B4: beq         $v0, $zero, L_808000D4
    if (ctx->r2 == 0) {
        // 0x808000B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D4;
    }
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: jal         0x80085598
    // 0x808000C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _cadbfunc_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x808000C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x808000C4: bnel        $v0, $zero, L_80800380
    if (ctx->r2 != 0) {
        // 0x808000C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    goto skip_1;
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808000CC: b           L_80800380
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000D4:
    // 0x808000D4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808000D8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808000DC: jal         0x800825E8
    // 0x808000E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _gsmaker_entrypoint_20(rdram, ctx);
        goto after_8;
    // 0x808000E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_8:
    // 0x808000E4: beq         $v0, $zero, L_80800104
    if (ctx->r2 == 0) {
        // 0x808000E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800104;
    }
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: jal         0x800855A8
    // 0x808000F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _cadbfunc_entrypoint_5(rdram, ctx);
        goto after_9;
    // 0x808000F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x808000F4: bnel        $v0, $zero, L_80800380
    if (ctx->r2 != 0) {
        // 0x808000F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    goto skip_2;
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808000FC: b           L_80800380
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800104:
    // 0x80800104: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800108: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8080010C: jal         0x800825E8
    // 0x80800110: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _gsmaker_entrypoint_20(rdram, ctx);
        goto after_10;
    // 0x80800110: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_10:
    // 0x80800114: beq         $v0, $zero, L_80800138
    if (ctx->r2 == 0) {
        // 0x80800118: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800138;
    }
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800120: jal         0x800855B8
    // 0x80800124: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    _cadbfunc_entrypoint_7(rdram, ctx);
        goto after_11;
    // 0x80800124: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    after_11:
    // 0x80800128: bnel        $v0, $zero, L_80800380
    if (ctx->r2 != 0) {
        // 0x8080012C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    goto skip_3;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800130: b           L_80800380
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800138:
    // 0x80800138: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8080013C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800140: jal         0x800825E8
    // 0x80800144: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _gsmaker_entrypoint_20(rdram, ctx);
        goto after_12;
    // 0x80800144: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_12:
    // 0x80800148: beq         $v0, $zero, L_8080016C
    if (ctx->r2 == 0) {
        // 0x8080014C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080016C;
    }
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800154: jal         0x800855C8
    // 0x80800158: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    _cadbfunc_entrypoint_9(rdram, ctx);
        goto after_13;
    // 0x80800158: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    after_13:
    // 0x8080015C: bnel        $v0, $zero, L_80800380
    if (ctx->r2 != 0) {
        // 0x80800160: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    goto skip_4;
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80800164: b           L_80800380
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080016C:
    // 0x8080016C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800170: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80800174: jal         0x800825E8
    // 0x80800178: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _gsmaker_entrypoint_20(rdram, ctx);
        goto after_14;
    // 0x80800178: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // 0x8080017C: beq         $v0, $zero, L_8080019C
    if (ctx->r2 == 0) {
        // 0x80800180: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080019C;
    }
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: jal         0x800855D8
    // 0x80800188: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    _cadbfunc_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x80800188: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_15:
    // 0x8080018C: bnel        $v0, $zero, L_80800380
    if (ctx->r2 != 0) {
        // 0x80800190: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    goto skip_5;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x80800194: b           L_80800380
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080019C:
    // 0x8080019C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x808001A0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x808001A4: jal         0x800825E8
    // 0x808001A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _gsmaker_entrypoint_20(rdram, ctx);
        goto after_16;
    // 0x808001A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_16:
    // 0x808001AC: beq         $v0, $zero, L_808001CC
    if (ctx->r2 == 0) {
        // 0x808001B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001CC;
    }
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B4: jal         0x800855E8
    // 0x808001B8: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    _cadbfunc_entrypoint_13(rdram, ctx);
        goto after_17;
    // 0x808001B8: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_17:
    // 0x808001BC: bnel        $v0, $zero, L_80800380
    if (ctx->r2 != 0) {
        // 0x808001C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    goto skip_6;
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_6:
    // 0x808001C4: b           L_80800380
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001CC:
    // 0x808001CC: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x808001D0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x808001D4: jal         0x800825E8
    // 0x808001D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _gsmaker_entrypoint_20(rdram, ctx);
        goto after_18;
    // 0x808001D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_18:
    // 0x808001DC: beq         $v0, $zero, L_808001FC
    if (ctx->r2 == 0) {
        // 0x808001E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001FC;
    }
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: jal         0x800855F8
    // 0x808001E8: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    _cadbfunc_entrypoint_15(rdram, ctx);
        goto after_19;
    // 0x808001E8: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_19:
    // 0x808001EC: bnel        $v0, $zero, L_80800380
    if (ctx->r2 != 0) {
        // 0x808001F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    goto skip_7;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_7:
    // 0x808001F4: b           L_80800380
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001FC:
    // 0x808001FC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800200: jal         0x80082608
    // 0x80800204: addiu       $a2, $sp, 0x36
    ctx->r6 = ADD32(ctx->r29, 0X36);
    _gsmaker_entrypoint_24(rdram, ctx);
        goto after_20;
    // 0x80800204: addiu       $a2, $sp, 0x36
    ctx->r6 = ADD32(ctx->r29, 0X36);
    after_20:
    // 0x80800208: beq         $v0, $zero, L_80800228
    if (ctx->r2 == 0) {
        // 0x8080020C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800228;
    }
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: jal         0x80085608
    // 0x80800214: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    _cadbfunc_entrypoint_17(rdram, ctx);
        goto after_21;
    // 0x80800214: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    after_21:
    // 0x80800218: bnel        $v0, $zero, L_80800380
    if (ctx->r2 != 0) {
        // 0x8080021C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    goto skip_8;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_8:
    // 0x80800220: b           L_80800380
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800228:
    // 0x80800228: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8080022C: jal         0x800825E0
    // 0x80800230: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    _gsmaker_entrypoint_19(rdram, ctx);
        goto after_22;
    // 0x80800230: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_22:
    // 0x80800234: beq         $v0, $zero, L_80800254
    if (ctx->r2 == 0) {
        // 0x80800238: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800254;
    }
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x80085618
    // 0x80800240: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    _cadbfunc_entrypoint_19(rdram, ctx);
        goto after_23;
    // 0x80800240: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_23:
    // 0x80800244: bnel        $v0, $zero, L_80800380
    if (ctx->r2 != 0) {
        // 0x80800248: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    goto skip_9;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_9:
    // 0x8080024C: b           L_80800380
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800254:
    // 0x80800254: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80800258: jal         0x800825E0
    // 0x8080025C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    _gsmaker_entrypoint_19(rdram, ctx);
        goto after_24;
    // 0x8080025C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_24:
    // 0x80800260: beq         $v0, $zero, L_80800280
    if (ctx->r2 == 0) {
        // 0x80800264: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800280;
    }
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800268: jal         0x80085628
    // 0x8080026C: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    _cadbfunc_entrypoint_21(rdram, ctx);
        goto after_25;
    // 0x8080026C: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_25:
    // 0x80800270: bnel        $v0, $zero, L_80800380
    if (ctx->r2 != 0) {
        // 0x80800274: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    goto skip_10;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_10:
    // 0x80800278: b           L_80800380
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800280:
    // 0x80800280: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80800284: jal         0x800825F0
    // 0x80800288: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    _gsmaker_entrypoint_21(rdram, ctx);
        goto after_26;
    // 0x80800288: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_26:
    // 0x8080028C: beq         $v0, $zero, L_808002AC
    if (ctx->r2 == 0) {
        // 0x80800290: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002AC;
    }
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: jal         0x80085678
    // 0x80800298: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _cadbfunc_entrypoint_31(rdram, ctx);
        goto after_27;
    // 0x80800298: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_27:
    // 0x8080029C: bnel        $v0, $zero, L_80800380
    if (ctx->r2 != 0) {
        // 0x808002A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    goto skip_11;
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_11:
    // 0x808002A4: b           L_80800380
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002AC:
    // 0x808002AC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x808002B0: jal         0x800825F0
    // 0x808002B4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    _gsmaker_entrypoint_21(rdram, ctx);
        goto after_28;
    // 0x808002B4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_28:
    // 0x808002B8: beq         $v0, $zero, L_808002D8
    if (ctx->r2 == 0) {
        // 0x808002BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002D8;
    }
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C0: jal         0x80085638
    // 0x808002C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _cadbfunc_entrypoint_23(rdram, ctx);
        goto after_29;
    // 0x808002C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_29:
    // 0x808002C8: bnel        $v0, $zero, L_80800380
    if (ctx->r2 != 0) {
        // 0x808002CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    goto skip_12;
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_12:
    // 0x808002D0: b           L_80800380
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002D8:
    // 0x808002D8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x808002DC: jal         0x800825F0
    // 0x808002E0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    _gsmaker_entrypoint_21(rdram, ctx);
        goto after_30;
    // 0x808002E0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_30:
    // 0x808002E4: beq         $v0, $zero, L_80800304
    if (ctx->r2 == 0) {
        // 0x808002E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800304;
    }
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002EC: jal         0x80085648
    // 0x808002F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _cadbfunc_entrypoint_25(rdram, ctx);
        goto after_31;
    // 0x808002F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_31:
    // 0x808002F4: bnel        $v0, $zero, L_80800380
    if (ctx->r2 != 0) {
        // 0x808002F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    goto skip_13;
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_13:
    // 0x808002FC: b           L_80800380
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800304:
    // 0x80800304: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80800308: jal         0x800825F0
    // 0x8080030C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    _gsmaker_entrypoint_21(rdram, ctx);
        goto after_32;
    // 0x8080030C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_32:
    // 0x80800310: beq         $v0, $zero, L_80800330
    if (ctx->r2 == 0) {
        // 0x80800314: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800330;
    }
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: jal         0x80085658
    // 0x8080031C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _cadbfunc_entrypoint_27(rdram, ctx);
        goto after_33;
    // 0x8080031C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_33:
    // 0x80800320: bnel        $v0, $zero, L_80800380
    if (ctx->r2 != 0) {
        // 0x80800324: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    goto skip_14;
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_14:
    // 0x80800328: b           L_80800380
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800330:
    // 0x80800330: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80800334: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80800338: jal         0x800825E8
    // 0x8080033C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _gsmaker_entrypoint_20(rdram, ctx);
        goto after_34;
    // 0x8080033C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_34:
    // 0x80800340: beq         $v0, $zero, L_80800360
    if (ctx->r2 == 0) {
        // 0x80800344: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800360;
    }
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800348: jal         0x80085688
    // 0x8080034C: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    _cadbfunc_entrypoint_33(rdram, ctx);
        goto after_35;
    // 0x8080034C: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_35:
    // 0x80800350: bnel        $v0, $zero, L_80800380
    if (ctx->r2 != 0) {
        // 0x80800354: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    goto skip_15;
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_15:
    // 0x80800358: b           L_80800380
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800380;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800360:
    // 0x80800360: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80800364: jal         0x800825F0
    // 0x80800368: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    _gsmaker_entrypoint_21(rdram, ctx);
        goto after_36;
    // 0x80800368: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_36:
    // 0x8080036C: beql        $v0, $zero, L_80800380
    if (ctx->r2 == 0) {
        // 0x80800370: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800380;
    }
    goto skip_16;
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_16:
    // 0x80800374: jal         0x80085698
    // 0x80800378: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _cadbfunc_entrypoint_35(rdram, ctx);
        goto after_37;
    // 0x80800378: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_37:
L_8080037C:
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800380:
    // 0x80800380: jal         0x800825C8
    // 0x80800384: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_38;
    // 0x80800384: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_38:
    // 0x80800388: beql        $v0, $zero, L_80800038
    if (ctx->r2 == 0) {
        // 0x8080038C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800038;
    }
    goto skip_17;
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_17:
L_80800390:
    // 0x80800390: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800394: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800398: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080039C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808003A0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808003A4: jr          $ra
    // 0x808003A8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808003A8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80800360_chfireicestorm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800368: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080036C: jal         0x800DA524
    // 0x80800370: addiu       $a0, $zero, 0x9FB
    ctx->r4 = ADD32(0, 0X9FB);
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x80800370: addiu       $a0, $zero, 0x9FB
    ctx->r4 = ADD32(0, 0X9FB);
    after_0:
    // 0x80800374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080037C: jr          $ra
    // 0x80800380: nop

    return;
    // 0x80800380: nop

;}
RECOMP_FUNC void bainput_func_80097F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097F08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097F0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097F10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80097F14: jal         0x80091A58
    // 0x80097F18: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80097F18: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80097F1C: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097F20: beq         $t6, $zero, L_80097F38
    if (ctx->r14 == 0) {
        // 0x80097F24: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80097F38;
    }
    // 0x80097F24: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80097F28: jal         0x8008D5C4
    // 0x80097F2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008D5C4(rdram, ctx);
        goto after_1;
    // 0x80097F2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80097F30: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097F34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80097F38:
    // 0x80097F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097F3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097F40: jr          $ra
    // 0x80097F44: nop

    return;
    // 0x80097F44: nop

;}
RECOMP_FUNC void func_80800174_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800174: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800178: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080017C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800180: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800184: jal         0x8009E69C
    // 0x80800188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E69C(rdram, ctx);
        goto after_0;
    // 0x80800188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080018C: bne         $v0, $zero, L_808001B0
    if (ctx->r2 != 0) {
        // 0x80800190: nop
    
            goto L_808001B0;
    }
    // 0x80800190: nop

    // 0x80800194: jal         0x8009BC90
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_1;
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080019C: jal         0x8009BC6C
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_2;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: jal         0x800961AC
    // 0x808001AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_3;
    // 0x808001AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_808001B0:
    // 0x808001B0: jal         0x80084120
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsvan_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001C4: jr          $ra
    // 0x808001C8: nop

    return;
    // 0x808001C8: nop

;}
RECOMP_FUNC void func_8009086C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009086C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090870: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090874: jal         0x800F54E4
    // 0x80090878: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090878: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009087C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80090880: jal         0x800F8150
    // 0x80090884: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F8150(rdram, ctx);
        goto after_1;
    // 0x80090884: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80090888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009088C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090890: jr          $ra
    // 0x80090894: nop

    return;
    // 0x80090894: nop

    // 0x80090898: nop

    // 0x8009089C: nop

;}
RECOMP_FUNC void func_800F468C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F468C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4694: lw          $t6, 0x17C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X17C);
    // 0x800F4698: beql        $t6, $zero, L_800F46CC
    if (ctx->r14 == 0) {
        // 0x800F469C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F46CC;
    }
    goto skip_0;
    // 0x800F469C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800F46A0: lw          $t7, 0x180($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X180);
    // 0x800F46A4: bnel        $t7, $zero, L_800F46CC
    if (ctx->r15 != 0) {
        // 0x800F46A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F46CC;
    }
    goto skip_1;
    // 0x800F46A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800F46AC: jal         0x800EA09C
    // 0x800F46B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA09C(rdram, ctx);
        goto after_0;
    // 0x800F46B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F46B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800F46B8: bne         $v0, $at, L_800F46C8
    if (ctx->r2 != ctx->r1) {
        // 0x800F46BC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800F46C8;
    }
    // 0x800F46BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800F46C0: jal         0x800991B0
    // 0x800F46C4: nop

    func_800991B0(rdram, ctx);
        goto after_1;
    // 0x800F46C4: nop

    after_1:
L_800F46C8:
    // 0x800F46C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F46CC:
    // 0x800F46CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F46D0: jr          $ra
    // 0x800F46D4: nop

    return;
    // 0x800F46D4: nop

;}
RECOMP_FUNC void bainput_should_dive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097F48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097F4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097F50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80097F54: jal         0x80091A58
    // 0x80097F58: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80097F58: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80097F5C: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097F60: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80097F64: beq         $t6, $zero, L_80097FA8
    if (ctx->r14 == 0) {
        // 0x80097F68: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80097FA8;
    }
    // 0x80097F68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80097F6C: lw          $t7, 0xA4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XA4);
    // 0x80097F70: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80097F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80097F78: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80097F7C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80097F80: nop

    // 0x80097F84: bc1f        L_80097F90
    if (!c1cs) {
        // 0x80097F88: nop
    
            goto L_80097F90;
    }
    // 0x80097F88: nop

    // 0x80097F8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80097F90:
    // 0x80097F90: beql        $v0, $zero, L_80097FAC
    if (ctx->r2 == 0) {
        // 0x80097F94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80097FAC;
    }
    goto skip_0;
    // 0x80097F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80097F98: jal         0x8008D214
    // 0x80097F9C: nop

    func_8008D214(rdram, ctx);
        goto after_1;
    // 0x80097F9C: nop

    after_1:
    // 0x80097FA0: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097FA4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80097FA8:
    // 0x80097FA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80097FAC:
    // 0x80097FAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097FB0: jr          $ra
    // 0x80097FB4: nop

    return;
    // 0x80097FB4: nop

;}
RECOMP_FUNC void func_80094E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094E98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80094E9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094EA0: jal         0x80094E78
    // 0x80094EA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80094E78(rdram, ctx);
        goto after_0;
    // 0x80094EA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80094EA8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80094EAC: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80094EB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80094EB4: lw          $v1, 0x74($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X74);
    // 0x80094EB8: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
    // 0x80094EBC: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80094EC0: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x80094EC4: beq         $t8, $zero, L_80094ED4
    if (ctx->r24 == 0) {
        // 0x80094EC8: nop
    
            goto L_80094ED4;
    }
    // 0x80094EC8: nop

    // 0x80094ECC: b           L_80094EDC
    // 0x80094ED0: lwc1        $f0, 0x8($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X8);
        goto L_80094EDC;
    // 0x80094ED0: lwc1        $f0, 0x8($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X8);
L_80094ED4:
    // 0x80094ED4: jal         0x800D8840
    // 0x80094ED8: nop

    func_800D8840(rdram, ctx);
        goto after_1;
    // 0x80094ED8: nop

    after_1:
L_80094EDC:
    // 0x80094EDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094EE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80094EE4: jr          $ra
    // 0x80094EE8: nop

    return;
    // 0x80094EE8: nop

;}
RECOMP_FUNC void chweldarbossfusebox_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1380, 0X670) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x670
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1380, 0X670));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x670
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1380, 0X670));
;}
RECOMP_FUNC void func_800C6A68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6A68: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6A6C: addiu       $v0, $v0, -0x55C0
    ctx->r2 = ADD32(ctx->r2, -0X55C0);
    // 0x800C6A70: sw          $v0, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r2;
    // 0x800C6A74: jr          $ra
    // 0x800C6A78: sw          $zero, 0x84($v0)
    MEM_W(0X84, ctx->r2) = 0;
    return;
    // 0x800C6A78: sw          $zero, 0x84($v0)
    MEM_W(0X84, ctx->r2) = 0;
;}
RECOMP_FUNC void func_800C9E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9E64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9E68: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800C9E6C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C9E70: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C9E74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9E78: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C9E7C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800C9E80: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800C9E84: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x800C9E88: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9E8C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800C9E90: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C9E94: jal         0x800C9750
    // 0x800C9E98: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    func_800C9750(rdram, ctx);
        goto after_0;
    // 0x800C9E98: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_0:
    // 0x800C9E9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C9EA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C9EA4: jr          $ra
    // 0x800C9EA8: nop

    return;
    // 0x800C9EA8: nop

;}
RECOMP_FUNC void func_808014B8_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808014BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808014C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808014C4: jal         0x808009B0
    // 0x808014C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808009B0_bssub(rdram, ctx);
        goto after_0;
    // 0x808014C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808014CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014D0: jal         0x8009BF5C
    // 0x808014D4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x808014D4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x808014D8: jal         0x800839C8
    // 0x808014DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_2;
    // 0x808014DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808014E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014E4: jal         0x8009B94C
    // 0x808014E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009B94C(rdram, ctx);
        goto after_3;
    // 0x808014E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808014EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014F0: jal         0x8009BA9C
    // 0x808014F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_4;
    // 0x808014F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808014F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808014FC: nop

    // 0x80801500: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    // 0x80801504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801508: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080150C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801510: jr          $ra
    // 0x80801514: nop

    return;
    // 0x80801514: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800EFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F00: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800F04: jal         0x80800060
    // 0x80800F08: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800060_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x80800F08: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800F0C: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800F10: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800F14: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800F18: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F20: jal         0x8008CC34
    // 0x80800F24: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    baanim_playForDuration_loopStartingAt(rdram, ctx);
        goto after_1;
    // 0x80800F24: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    after_1:
    // 0x80800F28: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800F2C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800F38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800F3C: jal         0x8009FFD8
    // 0x80800F40: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800F40: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800F44: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(376, 0X1628) << 16);
    // 0x80800F48: lwc1        $f4, 0x1628($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(376, 0X1628));
    // 0x80800F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F50: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80800F54: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    // 0x80800F58: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800F5C: jal         0x8008C9F0
    // 0x80800F60: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_3;
    // 0x80800F60: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800F64: jal         0x800909CC
    // 0x80800F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909CC(rdram, ctx);
        goto after_4;
    // 0x80800F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800F6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800F70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800F74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F78: jr          $ra
    // 0x80800F7C: nop

    return;
    // 0x80800F7C: nop

;}
RECOMP_FUNC void func_808002A8_chdiggerbossdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002B0: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x808002B4: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x808002B8: beql        $t7, $zero, L_808002DC
    if (ctx->r15 == 0) {
        // 0x808002BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002DC;
    }
    goto skip_0;
    // 0x808002BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808002C0: jal         0x80085750
    // 0x808002C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _capod_entrypoint_22(rdram, ctx);
        goto after_0;
    // 0x808002C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002CC: lhu         $t8, 0x6E($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X6E);
    // 0x808002D0: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x808002D4: sh          $t9, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r25;
    // 0x808002D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002DC:
    // 0x808002DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002E0: jr          $ra
    // 0x808002E4: nop

    return;
    // 0x808002E4: nop

;}
RECOMP_FUNC void func_80800000_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800010: jal         0x80100074
    // 0x80800014: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x80800014: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800018: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080001C: addiu       $a0, $zero, 0x6A8
    ctx->r4 = ADD32(0, 0X6A8);
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800024: jal         0x800DA3B8
    // 0x80800028: sw          $zero, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = 0;
    func_800DA3B8(rdram, ctx);
        goto after_1;
    // 0x80800028: sw          $zero, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = 0;
    after_1:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void func_80800100_chstoneballcoach(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800108: jal         0x8010CD28
    // 0x8080010C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010CD28(rdram, ctx);
        goto after_0;
    // 0x8080010C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800110: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800114: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800118: jal         0x80102CF4
    // 0x8080011C: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    func_80102CF4(rdram, ctx);
        goto after_1;
    // 0x8080011C: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    after_1:
    // 0x80800120: bne         $v0, $zero, L_80800130
    if (ctx->r2 != 0) {
        // 0x80800124: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800130;
    }
    // 0x80800124: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800128: jal         0x80102B2C
    // 0x8080012C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102B2C(rdram, ctx);
        goto after_2;
    // 0x8080012C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
L_80800130:
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void func_8009E9FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E9FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EA00: jr          $ra
    // 0x8009EA04: swc1        $f12, 0x7040($at)
    MEM_W(0X7040, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x8009EA04: swc1        $f12, 0x7040($at)
    MEM_W(0X7040, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void _chgobicommon_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086770: syscall     368
    recomp_syscall_handler(rdram, ctx, 0x80086770);
    return;
    // 0x80086774: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _glrecord_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800886B0: syscall     698
    recomp_syscall_handler(rdram, ctx, 0x800886B0);
    return;
    // 0x800886B4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800EBF8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBF8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EBF90: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800EBF94: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800EBF98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EBF9C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800EBFA0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800EBFA4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800EBFA8: jal         0x800EE904
    // 0x800EBFAC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EE904(rdram, ctx);
        goto after_0;
    // 0x800EBFAC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800EBFB0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800EBFB4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800EBFB8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800EBFBC: jal         0x800EBED4
    // 0x800EBFC0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_800EBED4(rdram, ctx);
        goto after_1;
    // 0x800EBFC0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x800EBFC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EBFC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800EBFCC: jr          $ra
    // 0x800EBFD0: nop

    return;
    // 0x800EBFD0: nop

;}
RECOMP_FUNC void func_800EBFD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBFD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EBFD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EBFDC: jal         0x800EBF8C
    // 0x800EBFE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800EBF8C(rdram, ctx);
        goto after_0;
    // 0x800EBFE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800EBFE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EBFE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EBFEC: jr          $ra
    // 0x800EBFF0: nop

    return;
    // 0x800EBFF0: nop

;}
RECOMP_FUNC void ncpoddialog_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802958: beq         $a2, $zero, L_80802970
    if (ctx->r6 == 0) {
        // 0x8080295C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80802970;
    }
    // 0x8080295C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802960: beq         $a2, $v0, L_80802988
    if (ctx->r6 == ctx->r2) {
        // 0x80802964: nop
    
            goto L_80802988;
    }
    // 0x80802964: nop

    // 0x80802968: jr          $ra
    // 0x8080296C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8080296C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802970:
    // 0x80802970: beq         $a0, $zero, L_80802980
    if (ctx->r4 == 0) {
        // 0x80802974: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80802980;
    }
    // 0x80802974: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80802978: bnel        $a0, $at, L_808029B4
    if (ctx->r4 != ctx->r1) {
        // 0x8080297C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808029B4;
    }
    goto skip_0;
    // 0x8080297C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80802980:
    // 0x80802980: jr          $ra
    // 0x80802984: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80802984: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802988:
    // 0x80802988: bnel        $a1, $v0, L_808029B4
    if (ctx->r5 != ctx->r2) {
        // 0x8080298C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808029B4;
    }
    goto skip_1;
    // 0x8080298C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80802990: beq         $a0, $zero, L_808029A0
    if (ctx->r4 == 0) {
        // 0x80802994: nop
    
            goto L_808029A0;
    }
    // 0x80802994: nop

    // 0x80802998: bnel        $a0, $v0, L_808029B4
    if (ctx->r4 != ctx->r2) {
        // 0x8080299C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808029B4;
    }
    goto skip_2;
    // 0x8080299C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
L_808029A0:
    // 0x808029A0: jr          $ra
    // 0x808029A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808029A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808029A8: jr          $ra
    // 0x808029AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808029AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808029B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808029B4:
    // 0x808029B4: jr          $ra
    // 0x808029B8: nop

    return;
    // 0x808029B8: nop

    // 0x808029BC: nop

;}
RECOMP_FUNC void _bskazstilt_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083710: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083710);
    return;
    // 0x80083714: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void chlavaslabswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1884, 0XA0) << 16);
    // 0x8080008C: jr          $ra
    // 0x80800090: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1884, 0XA0));
    return;
    // 0x80800090: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1884, 0XA0));
    // 0x80800094: nop

    // 0x80800098: nop

    // 0x8080009C: nop

;}
RECOMP_FUNC void gcsectionDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800094: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80800098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080009C: beq         $a0, $zero, L_808000B8
    if (ctx->r4 == 0) {
        // 0x808000A0: lbu         $v0, 0x762C($v0)
        ctx->r2 = MEM_BU(ctx->r2, 0X762C);
            goto L_808000B8;
    }
    // 0x808000A0: lbu         $v0, 0x762C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X762C);
    // 0x808000A4: jal         0x800D389C
    // 0x808000A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800D389C(rdram, ctx);
        goto after_0;
    // 0x808000A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x808000AC: jal         0x800886D0
    // 0x808000B0: nop

    _glglobalsettings_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808000B0: nop

    after_1:
    // 0x808000B4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_808000B8:
    // 0x808000B8: blez        $v0, L_808000D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808000BC: slti        $at, $v0, 0x20
        ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
            goto L_808000D0;
    }
    // 0x808000BC: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x808000C0: beq         $at, $zero, L_808000D0
    if (ctx->r1 == 0) {
        // 0x808000C4: nop
    
            goto L_808000D0;
    }
    // 0x808000C4: nop

    // 0x808000C8: jal         0x8001A63C
    // 0x808000CC: nop

    func_8001A63C(rdram, ctx);
        goto after_2;
    // 0x808000CC: nop

    after_2:
L_808000D0:
    // 0x808000D0: jal         0x80018634
    // 0x808000D4: nop

    func_80018634(rdram, ctx);
        goto after_3;
    // 0x808000D4: nop

    after_3:
    // 0x808000D8: jal         0x800C0A2C
    // 0x808000DC: nop

    func_800C0A2C(rdram, ctx);
        goto after_4;
    // 0x808000DC: nop

    after_4:
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089540: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089540);
    return;
    // 0x80089544: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_80802D00_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802D00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802D04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802D08: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80802D0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802D10: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80802D14: jal         0x80100094
    // 0x80802D18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802D18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802D1C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80802D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802D24: jal         0x80100094
    // 0x80802D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80802D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80802D2C: lbu         $t6, 0x40($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X40);
    // 0x80802D30: addiu       $a2, $v0, 0x10C
    ctx->r6 = ADD32(ctx->r2, 0X10C);
    // 0x80802D34: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x80802D38: beq         $at, $zero, L_80802EE0
    if (ctx->r1 == 0) {
        // 0x80802D3C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80802EE0;
    }
    // 0x80802D3C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80802D40: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9A38) << 16);
    // 0x80802D44: addu        $at, $at, $t6
    gpr jr_addend_80802D4C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80802D48: lw          $t6, -0x65C8($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9A38));
    // 0x80802D4C: jr          $t6
    // 0x80802D50: nop

    switch (jr_addend_80802D4C >> 2) {
        case 0: goto L_80802EE0; break;
        case 1: goto L_80802D54; break;
        case 2: goto L_80802D64; break;
        case 3: goto L_80802D74; break;
        case 4: goto L_80802DA4; break;
        case 5: goto L_80802E74; break;
        case 6: goto L_80802EC0; break;
        default: switch_error(__func__, 0x80802D4C, 0x80809A38);
    }
    // 0x80802D50: nop

L_80802D54:
    // 0x80802D54: jal         0x80803224
    // 0x80802D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803224_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80802D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802D5C: b           L_80802EE4
    // 0x80802D60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802EE4;
    // 0x80802D60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802D64:
    // 0x80802D64: jal         0x80087C98
    // 0x80802D68: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    _gcnewoption_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80802D68: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80802D6C: b           L_80802EE4
    // 0x80802D70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802EE4;
    // 0x80802D70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802D74:
    // 0x80802D74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80802D78: jal         0x80087C98
    // 0x80802D7C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _gcnewoption_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80802D7C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x80802D80: jal         0x800D9078
    // 0x80802D84: addiu       $a0, $s1, 0x4C
    ctx->r4 = ADD32(ctx->r17, 0X4C);
    func_800D9078(rdram, ctx);
        goto after_5;
    // 0x80802D84: addiu       $a0, $s1, 0x4C
    ctx->r4 = ADD32(ctx->r17, 0X4C);
    after_5:
    // 0x80802D88: beq         $v0, $zero, L_80802EE0
    if (ctx->r2 == 0) {
        // 0x80802D8C: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80802EE0;
    }
    // 0x80802D8C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80802D90: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80802D94: jal         0x80087DC0
    // 0x80802D98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_37(rdram, ctx);
        goto after_6;
    // 0x80802D98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80802D9C: b           L_80802EE4
    // 0x80802DA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802EE4;
    // 0x80802DA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802DA4:
    // 0x80802DA4: jal         0x80087CD0
    // 0x80802DA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    _gcnewoption_entrypoint_7(rdram, ctx);
        goto after_7;
    // 0x80802DA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_7:
    // 0x80802DAC: sb          $zero, 0x42($s1)
    MEM_B(0X42, ctx->r17) = 0;
    // 0x80802DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802DB4: jal         0x8010A828
    // 0x80802DB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A828(rdram, ctx);
        goto after_8;
    // 0x80802DB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80802DBC: lbu         $t7, 0x41($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X41);
    // 0x80802DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802DC4: beql        $t7, $zero, L_80802E10
    if (ctx->r15 == 0) {
        // 0x80802DC8: lbu         $t0, 0x41($s1)
        ctx->r8 = MEM_BU(ctx->r17, 0X41);
            goto L_80802E10;
    }
    goto skip_0;
    // 0x80802DC8: lbu         $t0, 0x41($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X41);
    skip_0:
    // 0x80802DCC: jal         0x80802170
    // 0x80802DD0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80802170_chdiggerboss(rdram, ctx);
        goto after_9;
    // 0x80802DD0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80802DD4: bne         $v0, $zero, L_80802E0C
    if (ctx->r2 != 0) {
        // 0x80802DD8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802E0C;
    }
    // 0x80802DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802DDC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80802DE0: jal         0x80802878
    // 0x80802DE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_10;
    // 0x80802DE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x80802DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802DEC: addiu       $a1, $zero, 0x172F
    ctx->r5 = ADD32(0, 0X172F);
    // 0x80802DF0: jal         0x80803660
    // 0x80802DF4: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_11;
    // 0x80802DF4: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    after_11:
    // 0x80802DF8: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80802DFC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80802E00: sb          $t8, 0x40($s1)
    MEM_B(0X40, ctx->r17) = ctx->r24;
    // 0x80802E04: b           L_80802EE0
    // 0x80802E08: sh          $t9, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r25;
        goto L_80802EE0;
    // 0x80802E08: sh          $t9, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r25;
L_80802E0C:
    // 0x80802E0C: lbu         $t0, 0x41($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X41);
L_80802E10:
    // 0x80802E10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802E14: bnel        $t0, $zero, L_80802E60
    if (ctx->r8 != 0) {
        // 0x80802E18: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802E60;
    }
    goto skip_1;
    // 0x80802E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80802E1C: jal         0x80802170
    // 0x80802E20: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80802170_chdiggerboss(rdram, ctx);
        goto after_12;
    // 0x80802E20: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x80802E24: bne         $v0, $zero, L_80802E5C
    if (ctx->r2 != 0) {
        // 0x80802E28: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802E5C;
    }
    // 0x80802E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802E2C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80802E30: jal         0x80802878
    // 0x80802E34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_13;
    // 0x80802E34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x80802E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802E3C: addiu       $a1, $zero, 0x1730
    ctx->r5 = ADD32(0, 0X1730);
    // 0x80802E40: jal         0x80803660
    // 0x80802E44: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_14;
    // 0x80802E44: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    after_14:
    // 0x80802E48: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80802E4C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80802E50: sb          $t1, 0x40($s1)
    MEM_B(0X40, ctx->r17) = ctx->r9;
    // 0x80802E54: b           L_80802EE0
    // 0x80802E58: sh          $t2, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r10;
        goto L_80802EE0;
    // 0x80802E58: sh          $t2, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r10;
L_80802E5C:
    // 0x80802E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802E60:
    // 0x80802E60: jal         0x80800180
    // 0x80802E64: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800180_chdiggerboss(rdram, ctx);
        goto after_15;
    // 0x80802E64: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_15:
    // 0x80802E68: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80802E6C: b           L_80802EE0
    // 0x80802E70: sb          $t3, 0x40($s1)
    MEM_B(0X40, ctx->r17) = ctx->r11;
        goto L_80802EE0;
    // 0x80802E70: sb          $t3, 0x40($s1)
    MEM_B(0X40, ctx->r17) = ctx->r11;
L_80802E74:
    // 0x80802E74: jal         0x80101DDC
    // 0x80802E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_16;
    // 0x80802E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80802E7C: beql        $v0, $zero, L_80802EE4
    if (ctx->r2 == 0) {
        // 0x80802E80: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80802EE4;
    }
    goto skip_2;
    // 0x80802E80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80802E84: jal         0x800F54E4
    // 0x80802E88: nop

    func_800F54E4(rdram, ctx);
        goto after_17;
    // 0x80802E88: nop

    after_17:
    // 0x80802E8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802E90: jal         0x800F82D4
    // 0x80802E94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_18;
    // 0x80802E94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80802E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802EA0: jal         0x80800618
    // 0x80802EA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800618_chdiggerboss(rdram, ctx);
        goto after_19;
    // 0x80802EA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x80802EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802EAC: jal         0x80800180
    // 0x80802EB0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800180_chdiggerboss(rdram, ctx);
        goto after_20;
    // 0x80802EB0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_20:
    // 0x80802EB4: sb          $zero, 0x40($s1)
    MEM_B(0X40, ctx->r17) = 0;
    // 0x80802EB8: b           L_80802EE4
    // 0x80802EBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802EE4;
    // 0x80802EBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802EC0:
    // 0x80802EC0: lh          $t4, 0x46($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X46);
    // 0x80802EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802EC8: bnel        $t4, $zero, L_80802EE4
    if (ctx->r12 != 0) {
        // 0x80802ECC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80802EE4;
    }
    goto skip_3;
    // 0x80802ECC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x80802ED0: jal         0x80800180
    // 0x80802ED4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800180_chdiggerboss(rdram, ctx);
        goto after_21;
    // 0x80802ED4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_21:
    // 0x80802ED8: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80802EDC: sb          $t5, 0x40($s1)
    MEM_B(0X40, ctx->r17) = ctx->r13;
L_80802EE0:
    // 0x80802EE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802EE4:
    // 0x80802EE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802EE8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80802EEC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80802EF0: jr          $ra
    // 0x80802EF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80802EF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bsbwhirl_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DF0: jal         0x800839B8
    // 0x80800DF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800DF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800DF8: jal         0x8080017C
    // 0x80800DFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080017C_bsbwhirl(rdram, ctx);
        goto after_1;
    // 0x80800DFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800E00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E08: jr          $ra
    // 0x80800E0C: nop

    return;
    // 0x80800E0C: nop

;}
RECOMP_FUNC void _ncbaspiral_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089178: syscall     764
    recomp_syscall_handler(rdram, ctx, 0x80089178);
    return;
    // 0x8008917C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bastatetimer_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800917A8: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800917AC: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800917B0: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800917B4: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x800917B8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800917BC: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800917C0: swc1        $f12, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f12.u32l;
    // 0x800917C4: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x800917C8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800917CC: jr          $ra
    // 0x800917D0: swc1        $f12, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f12.u32l;
    return;
    // 0x800917D0: swc1        $f12, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_808026CC_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808026CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808026D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808026D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808026D8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1240, 0X3C54) << 16);
    // 0x808026DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808026E0: jal         0x80101E4C
    // 0x808026E4: addiu       $a1, $a1, 0x3C54
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1240, 0X3C54));
    func_80101E4C(rdram, ctx);
        goto after_0;
    // 0x808026E4: addiu       $a1, $a1, 0x3C54
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1240, 0X3C54));
    after_0:
    // 0x808026E8: beq         $v0, $zero, L_80802738
    if (ctx->r2 == 0) {
        // 0x808026EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802738;
    }
    // 0x808026EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808026F0: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x808026F4: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x808026F8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808026FC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80802700: jal         0x80018820
    // 0x80802704: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80018820(rdram, ctx);
        goto after_1;
    // 0x80802704: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80802708: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x8080270C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80802710: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802714: jal         0x800E15CC
    // 0x80802718: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    func_800E15CC(rdram, ctx);
        goto after_2;
    // 0x80802718: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_2:
    // 0x8080271C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3C3C) << 16);
    // 0x80802720: addiu       $a2, $a2, 0x3C3C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3C3C));
    // 0x80802724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802728: jal         0x80089D18
    // 0x8080272C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x8080272C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80802730: b           L_80802788
    // 0x80802734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802788;
    // 0x80802734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802738:
    // 0x80802738: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x8080273C: jal         0x80101E14
    // 0x80802740: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_80101E14(rdram, ctx);
        goto after_4;
    // 0x80802740: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_4:
    // 0x80802744: beq         $v0, $zero, L_80802784
    if (ctx->r2 == 0) {
        // 0x80802748: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80802784;
    }
    // 0x80802748: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080274C: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80802750: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80802754: jal         0x80018820
    // 0x80802758: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80018820(rdram, ctx);
        goto after_5;
    // 0x80802758: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
    // 0x8080275C: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80802760: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80802764: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802768: jal         0x800E15CC
    // 0x8080276C: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_800E15CC(rdram, ctx);
        goto after_6;
    // 0x8080276C: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_6:
    // 0x80802770: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3C3C) << 16);
    // 0x80802774: addiu       $a2, $a2, 0x3C3C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3C3C));
    // 0x80802778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080277C: jal         0x80089D18
    // 0x80802780: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80802780: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
L_80802784:
    // 0x80802784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802788:
    // 0x80802788: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080278C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802790: jr          $ra
    // 0x80802794: nop

    return;
    // 0x80802794: nop

;}
RECOMP_FUNC void func_800D3EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3EC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3ECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3ED0: jal         0x800D3E14
    // 0x800D3ED4: nop

    func_800D3E14(rdram, ctx);
        goto after_0;
    // 0x800D3ED4: nop

    after_0:
    // 0x800D3ED8: beq         $v0, $zero, L_800D3EE8
    if (ctx->r2 == 0) {
        // 0x800D3EDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3EE8;
    }
    // 0x800D3EDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D3EE0: b           L_800D3EEC
    // 0x800D3EE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D3EEC;
    // 0x800D3EE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D3EE8:
    // 0x800D3EE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D3EEC:
    // 0x800D3EEC: jr          $ra
    // 0x800D3EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D3EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800D3574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3574: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800D3578: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D357C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800D3580: lbu         $t7, -0x4A9E($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X4A9E);
    // 0x800D3584: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D3588: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800D358C: bgez        $t7, L_800D35A0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800D3590: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800D35A0;
    }
    // 0x800D3590: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D3594: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D3598: nop

    // 0x800D359C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800D35A0:
    // 0x800D35A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D35A4: lwc1        $f10, 0x5B10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5B10);
    // 0x800D35A8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D35AC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800D35B0: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x800D35B4: jr          $ra
    // 0x800D35B8: nop

    return;
    // 0x800D35B8: nop

;}
