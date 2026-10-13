#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void chsignpost_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1656, 0X2E0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x2E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1656, 0X2E0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x2E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1656, 0X2E0));
;}
RECOMP_FUNC void bskazstilt_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007E4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808007E8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(292, 0X1220) << 16);
    // 0x808007EC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808007F0: jr          $ra
    // 0x808007F4: lw          $v0, 0x1220($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(292, 0X1220));
    return;
    // 0x808007F4: lw          $v0, 0x1220($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(292, 0X1220));
;}
RECOMP_FUNC void badrone_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080047C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800480: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800484: lw          $a0, 0x54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54);
    // 0x80800488: jal         0x800EE7F8
    // 0x8080048C: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080048C: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    after_0:
    // 0x80800490: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800494: jal         0x80800348
    // 0x80800498: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800348_badrone(rdram, ctx);
        goto after_1;
    // 0x80800498: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_1:
    // 0x8080049C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004A4: jr          $ra
    // 0x808004A8: nop

    return;
    // 0x808004A8: nop

;}
RECOMP_FUNC void _ncbapan_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800891B0: syscall     765
    recomp_syscall_handler(rdram, ctx, 0x800891B0);
    return;
    // 0x800891B4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void badata_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DF4: jal         0x80800000
    // 0x80800DF8: nop

    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x80800DF8: nop

    after_0:
    // 0x80800DFC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800E00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E04: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(473, 0X1688) << 16);
    // 0x80800E08: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800E0C: lw          $v0, 0x1688($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(473, 0X1688));
    // 0x80800E10: jr          $ra
    // 0x80800E14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800E14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_808000F0_chmrsboggyhome(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000F4: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808000F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000FC: beq         $a1, $at, L_80800118
    if (ctx->r5 == ctx->r1) {
        // 0x80800100: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800118;
    }
    // 0x80800100: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800104: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800108: beq         $a1, $at, L_80800128
    if (ctx->r5 == ctx->r1) {
        // 0x8080010C: addiu       $a2, $zero, 0x3E
        ctx->r6 = ADD32(0, 0X3E);
            goto L_80800128;
    }
    // 0x8080010C: addiu       $a2, $zero, 0x3E
    ctx->r6 = ADD32(0, 0X3E);
    // 0x80800110: b           L_80800164
    // 0x80800114: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800164;
    // 0x80800114: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800118:
    // 0x80800118: jal         0x80102424
    // 0x8080011C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x8080011C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800120: b           L_80800164
    // 0x80800124: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800164;
    // 0x80800124: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800128:
    // 0x80800128: jal         0x800897C0
    // 0x8080012C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x8080012C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800130: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800134: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800138: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x8080013C: jal         0x800897E8
    // 0x80800140: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800140: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_2:
    // 0x80800144: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800148: jal         0x80089810
    // 0x8080014C: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_3;
    // 0x8080014C: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_3:
    // 0x80800150: b           L_80800164
    // 0x80800154: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800164;
    // 0x80800154: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800158: b           L_80800164
    // 0x8080015C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800164;
    // 0x8080015C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800160: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800164:
    // 0x80800164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800168: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080016C: jr          $ra
    // 0x80800170: nop

    return;
    // 0x80800170: nop

;}
RECOMP_FUNC void freelist_clear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2FE0: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800B2FE4: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x800B2FE8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B2FEC: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800B2FF0: bne         $at, $zero, L_800B3014
    if (ctx->r1 != 0) {
        // 0x800B2FF4: nop
    
            goto L_800B3014;
    }
    // 0x800B2FF4: nop

L_800B2FF8:
    // 0x800B2FF8: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x800B2FFC: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x800B3000: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x800B3004: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B3008: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B300C: bne         $at, $zero, L_800B2FF8
    if (ctx->r1 != 0) {
        // 0x800B3010: addu        $v0, $v0, $t7
        ctx->r2 = ADD32(ctx->r2, ctx->r15);
            goto L_800B2FF8;
    }
    // 0x800B3010: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
L_800B3014:
    // 0x800B3014: jr          $ra
    // 0x800B3018: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    return;
    // 0x800B3018: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
;}
RECOMP_FUNC void sueggmove_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808002E0: jal         0x80100094
    // 0x808002E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002E8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808002EC: sb          $t6, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r14;
    // 0x808002F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002F8: jr          $ra
    // 0x808002FC: nop

    return;
    // 0x808002FC: nop

;}
RECOMP_FUNC void func_800F2F60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2F60: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800F2F64: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800F2F68: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800F2F6C: nop

    // 0x800F2F70: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F2F74: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800F2F78: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800F2F7C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800F2F80: nop

    // 0x800F2F84: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800F2F88: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x800F2F8C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800F2F90: nop

    // 0x800F2F94: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F2F98: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800F2F9C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800F2FA0: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x800F2FA4: nop

    // 0x800F2FA8: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x800F2FAC: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x800F2FB0: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800F2FB4: nop

    // 0x800F2FB8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F2FBC: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800F2FC0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800F2FC4: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800F2FC8: jr          $ra
    // 0x800F2FCC: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
    return;
    // 0x800F2FCC: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
;}
RECOMP_FUNC void func_80800680_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800680: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800688: jal         0x80089828
    // 0x8080068C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x8080068C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800690: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800694: beq         $v0, $zero, L_80800734
    if (ctx->r2 == 0) {
        // 0x80800698: sw          $zero, 0x18($sp)
        MEM_W(0X18, ctx->r29) = 0;
            goto L_80800734;
    }
    // 0x80800698: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8080069C: jal         0x801022E4
    // 0x808006A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_801022E4(rdram, ctx);
        goto after_1;
    // 0x808006A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808006A4: addiu       $at, $zero, 0x4AD
    ctx->r1 = ADD32(0, 0X4AD);
    // 0x808006A8: bnel        $v0, $at, L_8080070C
    if (ctx->r2 != ctx->r1) {
        // 0x808006AC: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_8080070C;
    }
    goto skip_0;
    // 0x808006AC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x808006B0: jal         0x80101F24
    // 0x808006B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80101F24(rdram, ctx);
        goto after_2;
    // 0x808006B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808006B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(800, 0XFD0) << 16);
    // 0x808006BC: lwc1        $f4, 0xFD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(800, 0XFD0));
    // 0x808006C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(800, 0XFD4) << 16);
    // 0x808006C4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808006C8: nop

    // 0x808006CC: bc1tl       L_80800704
    if (c1cs) {
        // 0x808006D0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800704;
    }
    goto skip_1;
    // 0x808006D0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_1:
    // 0x808006D4: lwc1        $f6, 0xFD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(800, 0XFD4));
    // 0x808006D8: lui         $a1, 0x3F0C
    ctx->r5 = S32(0X3F0C << 16);
    // 0x808006DC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808006E0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808006E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006E8: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x808006EC: bc1tl       L_80800704
    if (c1cs) {
        // 0x808006F0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800704;
    }
    goto skip_2;
    // 0x808006F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_2:
    // 0x808006F4: jal         0x80102320
    // 0x808006F8: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    func_80102320(rdram, ctx);
        goto after_3;
    // 0x808006F8: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    after_3:
    // 0x808006FC: beq         $v0, $zero, L_80800708
    if (ctx->r2 == 0) {
        // 0x80800700: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800708;
    }
    // 0x80800700: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_80800704:
    // 0x80800704: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
L_80800708:
    // 0x80800708: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
L_8080070C:
    // 0x8080070C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800710: beql        $t7, $zero, L_80800724
    if (ctx->r15 == 0) {
        // 0x80800714: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_80800724;
    }
    goto skip_3;
    // 0x80800714: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    skip_3:
    // 0x80800718: jal         0x80089818
    // 0x8080071C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_18(rdram, ctx);
        goto after_4;
    // 0x8080071C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800720: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
L_80800724:
    // 0x80800724: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800728: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080072C: jal         0x800897D8
    // 0x80800730: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x80800730: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    after_5:
L_80800734:
    // 0x80800734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800738: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080073C: jr          $ra
    // 0x80800740: nop

    return;
    // 0x80800740: nop

;}
RECOMP_FUNC void func_80800068_susplinet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: lh          $t6, 0x32($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X32);
    // 0x8080006C: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80800070: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x80800074: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80800078: lh          $v0, 0x0($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X0);
    // 0x8080007C: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x80800080: jr          $ra
    // 0x80800084: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    return;
    // 0x80800084: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
;}
RECOMP_FUNC void func_800D90F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D90F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D90FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D9100: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D9104: jal         0x800D8FF8
    // 0x800D9108: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800D9108: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D910C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800D9110: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800D9114: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D9118: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800D911C: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800D9120: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800D9124: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800D9128: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x800D912C: nop

    // 0x800D9130: bc1f        L_800D9144
    if (!c1cs) {
        // 0x800D9134: nop
    
            goto L_800D9144;
    }
    // 0x800D9134: nop

    // 0x800D9138: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    // 0x800D913C: b           L_800D9144
    // 0x800D9140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D9144;
    // 0x800D9140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D9144:
    // 0x800D9144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D9148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D914C: jr          $ra
    // 0x800D9150: nop

    return;
    // 0x800D9150: nop

;}
RECOMP_FUNC void func_80800080_chfactoryflypad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: jr          $ra
    // 0x80800084: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800084: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800D1F34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1F34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D1F38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1F3C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D1F40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800D1F44: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800D1F48: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x800D1F4C: jal         0x80088588
    // 0x800D1F50: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    _glgamedata_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x800D1F50: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800D1F54: beq         $v0, $zero, L_800D1FA0
    if (ctx->r2 == 0) {
        // 0x800D1F58: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_800D1FA0;
    }
    // 0x800D1F58: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800D1F5C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800D1F60: addiu       $a1, $a1, -0x40
    ctx->r5 = ADD32(ctx->r5, -0X40);
    // 0x800D1F64: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800D1F68: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x800D1F6C: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800D1F70: beq         $at, $zero, L_800D1F80
    if (ctx->r1 == 0) {
        // 0x800D1F74: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_800D1F80;
    }
    // 0x800D1F74: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800D1F78: b           L_800D1FA4
    // 0x800D1F7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800D1FA4;
    // 0x800D1F7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800D1F80:
    // 0x800D1F80: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800D1F84: sll         $t1, $a1, 1
    ctx->r9 = S32(ctx->r5 << 1);
    // 0x800D1F88: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x800D1F8C: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x800D1F90: lbu         $t2, 0x1($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X1);
    // 0x800D1F94: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x800D1F98: b           L_800D1FA4
    // 0x800D1F9C: or          $v0, $t2, $t4
    ctx->r2 = ctx->r10 | ctx->r12;
        goto L_800D1FA4;
    // 0x800D1F9C: or          $v0, $t2, $t4
    ctx->r2 = ctx->r10 | ctx->r12;
L_800D1FA0:
    // 0x800D1FA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800D1FA4:
    // 0x800D1FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1FA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D1FAC: jr          $ra
    // 0x800D1FB0: nop

    return;
    // 0x800D1FB0: nop

    // 0x800D1FB4: nop

    // 0x800D1FB8: nop

    // 0x800D1FBC: nop

;}
RECOMP_FUNC void _chnests_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A90: syscall     191
    recomp_syscall_handler(rdram, ctx, 0x80085A90);
    return;
    // 0x80085A94: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void sumole_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C78: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801C7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801C80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801C84: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80801C88: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80801C8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801C90: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80801C94: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80801C98: beq         $t6, $at, L_80801CA8
    if (ctx->r14 == ctx->r1) {
        // 0x80801C9C: addiu       $s0, $sp, 0x2C
        ctx->r16 = ADD32(ctx->r29, 0X2C);
            goto L_80801CA8;
    }
    // 0x80801C9C: addiu       $s0, $sp, 0x2C
    ctx->r16 = ADD32(ctx->r29, 0X2C);
    // 0x80801CA0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801CA4: bne         $t6, $at, L_80801D28
    if (ctx->r14 != ctx->r1) {
        // 0x80801CA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801D28;
    }
L_80801CA8:
    // 0x80801CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CAC: jal         0x8010D254
    // 0x80801CB0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x80801CB0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80801CB4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80801CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CBC: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80801CC0: jal         0x800EF3DC
    // 0x80801CC4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800EF3DC(rdram, ctx);
        goto after_1;
    // 0x80801CC4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x80801CC8: jal         0x800EEF94
    // 0x80801CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EEF94(rdram, ctx);
        goto after_2;
    // 0x80801CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801CD0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801CD4: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801CD8: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80801CDC: nop

    // 0x80801CE0: bc1tl       L_80801D2C
    if (c1cs) {
        // 0x80801CE4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801D2C;
    }
    goto skip_0;
    // 0x80801CE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801CE8: div.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80801CEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801CF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801CF4: nop

    // 0x80801CF8: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80801CFC: nop

    // 0x80801D00: bc1fl       L_80801D2C
    if (!c1cs) {
        // 0x80801D04: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801D2C;
    }
    goto skip_1;
    // 0x80801D04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80801D08: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80801D0C: jal         0x800EF334
    // 0x80801D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x80801D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D18: jal         0x800EF04C
    // 0x80801D1C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x80801D1C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80801D20: jal         0x800907C0
    // 0x80801D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800907C0(rdram, ctx);
        goto after_5;
    // 0x80801D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80801D28:
    // 0x80801D28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801D2C:
    // 0x80801D2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801D30: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801D34: jr          $ra
    // 0x80801D38: nop

    return;
    // 0x80801D38: nop

;}
RECOMP_FUNC void _susubgame_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A2F8: syscall     834
    recomp_syscall_handler(rdram, ctx, 0x8008A2F8);
    return;
    // 0x8008A2FC: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void subaddiedialog_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800268: beq         $a0, $zero, L_80800288
    if (ctx->r4 == 0) {
        // 0x8080026C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800288;
    }
    // 0x8080026C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800270: jal         0x80800000
    // 0x80800274: nop

    func_80800000_subaddiedialog(rdram, ctx);
        goto after_0;
    // 0x80800274: nop

    after_0:
    // 0x80800278: bnel        $v0, $zero, L_8080028C
    if (ctx->r2 != 0) {
        // 0x8080027C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080028C;
    }
    goto skip_0;
    // 0x8080027C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
    // 0x80800280: b           L_808002C0
    // 0x80800284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002C0;
    // 0x80800284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800288:
    // 0x80800288: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8080028C:
    // 0x8080028C: jal         0x80016B30
    // 0x80800290: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_1;
    // 0x80800290: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800294: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800298: beq         $v0, $at, L_808002A8
    if (ctx->r2 == ctx->r1) {
        // 0x8080029C: nop
    
            goto L_808002A8;
    }
    // 0x8080029C: nop

    // 0x808002A0: b           L_808002C0
    // 0x808002A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002C0;
    // 0x808002A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002A8:
    // 0x808002A8: jal         0x800F54E4
    // 0x808002AC: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808002AC: nop

    after_2:
    // 0x808002B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002B4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808002B8: jal         0x800F4BB8
    // 0x808002BC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_800F4BB8(rdram, ctx);
        goto after_3;
    // 0x808002BC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_3:
L_808002C0:
    // 0x808002C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002C8: jr          $ra
    // 0x808002CC: nop

    return;
    // 0x808002CC: nop

;}
RECOMP_FUNC void func_800CF160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF160: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800CF164: addiu       $v0, $v0, -0x4EA0
    ctx->r2 = ADD32(ctx->r2, -0X4EA0);
    // 0x800CF168: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CF16C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CF170: sb          $t6, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r14;
    // 0x800CF174: swc1        $f12, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f12.u32l;
    // 0x800CF178: sw          $a1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r5;
    // 0x800CF17C: jr          $ra
    // 0x800CF180: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x800CF180: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_808000B4_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000BC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808000C0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808000C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C8: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
    // 0x808000CC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808000D0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808000D4: blez        $t6, L_80800108
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808000D8: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_80800108;
    }
    // 0x808000D8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x808000DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808000E0:
    // 0x808000E0: jal         0x80800064
    // 0x808000E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800064_chwarppad(rdram, ctx);
        goto after_0;
    // 0x808000E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x808000E8: beql        $v0, $zero, L_808000F8
    if (ctx->r2 == 0) {
        // 0x808000EC: lw          $t7, 0x1C($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X1C);
            goto L_808000F8;
    }
    goto skip_0;
    // 0x808000EC: lw          $t7, 0x1C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X1C);
    skip_0:
    // 0x808000F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808000F4: lw          $t7, 0x1C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X1C);
L_808000F8:
    // 0x808000F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808000FC: slt         $at, $t7, $s0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80800100: beql        $at, $zero, L_808000E0
    if (ctx->r1 == 0) {
        // 0x80800104: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808000E0;
    }
    goto skip_1;
    // 0x80800104: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
L_80800108:
    // 0x80800108: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080010C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80800110: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800114: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800118: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080011C: jr          $ra
    // 0x80800120: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800120: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8080007C_chpotogoldbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800080: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800084: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800088: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080008C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800090: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800094: jal         0x800EE7F8
    // 0x80800098: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800098: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x8080009C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808000A0: jal         0x800EE7F8
    // 0x808000A4: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808000A4: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_1:
    // 0x808000A8: jal         0x800EA05C
    // 0x808000AC: nop

    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x808000AC: nop

    after_2:
    // 0x808000B0: addiu       $at, $zero, 0x136
    ctx->r1 = ADD32(0, 0X136);
    // 0x808000B4: bne         $v0, $at, L_808000E8
    if (ctx->r2 != ctx->r1) {
        // 0x808000B8: nop
    
            goto L_808000E8;
    }
    // 0x808000B8: nop

    // 0x808000BC: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808000C0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808000C4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808000C8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000CC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808000D0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000D4: sub.s       $f14, $f18, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x808000D8: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    // 0x808000DC: swc1        $f12, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f12.u32l;
    // 0x808000E0: b           L_80800174
    // 0x808000E4: swc1        $f14, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f14.u32l;
        goto L_80800174;
    // 0x808000E4: swc1        $f14, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f14.u32l;
L_808000E8:
    // 0x808000E8: jal         0x800F54E4
    // 0x808000EC: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x808000EC: nop

    after_3:
    // 0x808000F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000F4: jal         0x800F5A00
    // 0x808000F8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F5A00(rdram, ctx);
        goto after_4;
    // 0x808000F8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x808000FC: jal         0x800EA090
    // 0x80800100: nop

    func_800EA090(rdram, ctx);
        goto after_5;
    // 0x80800100: nop

    after_5:
    // 0x80800104: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800108: bne         $v0, $at, L_8080016C
    if (ctx->r2 != ctx->r1) {
        // 0x8080010C: lwc1        $f18, 0x30($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
            goto L_8080016C;
    }
    // 0x8080010C: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800110: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800114: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x80800120: nop

    // 0x80800124: bc1f        L_8080016C
    if (!c1cs) {
        // 0x80800128: nop
    
            goto L_8080016C;
    }
    // 0x80800128: nop

    // 0x8080012C: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800130: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800134: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800138: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8080013C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800140: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800144: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80800148: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    // 0x8080014C: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x80800150: jal         0x80101FDC
    // 0x80800154: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x80800154: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    after_6:
    // 0x80800158: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080015C: jal         0x800CE88C
    // 0x80800160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_7;
    // 0x80800160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800164: b           L_80800178
    // 0x80800168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800178;
    // 0x80800168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080016C:
    // 0x8080016C: jal         0x800FFA88
    // 0x80800170: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_8;
    // 0x80800170: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_8:
L_80800174:
    // 0x80800174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800178:
    // 0x80800178: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080017C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800180: jr          $ra
    // 0x80800184: nop

    return;
    // 0x80800184: nop

;}
RECOMP_FUNC void _subaddieskeleton_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A0D8: syscall     828
    recomp_syscall_handler(rdram, ctx, 0x8008A0D8);
    return;
    // 0x8008A0DC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _sukickball_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089AF0: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089AF0);
    return;
    // 0x80089AF4: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_808000E4_chstarspinnerplanet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000F0: jal         0x800DA298
    // 0x808000F4: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808000F4: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    after_0:
    // 0x808000F8: bne         $v0, $zero, L_80800110
    if (ctx->r2 != 0) {
        // 0x808000FC: nop
    
            goto L_80800110;
    }
    // 0x808000FC: nop

    // 0x80800100: jal         0x80088848
    // 0x80800104: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800104: nop

    after_1:
    // 0x80800108: beql        $v0, $zero, L_8080011C
    if (ctx->r2 == 0) {
        // 0x8080010C: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_8080011C;
    }
    goto skip_0;
    // 0x8080010C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    skip_0:
L_80800110:
    // 0x80800110: jal         0x800DA544
    // 0x80800114: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800114: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800118: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
L_8080011C:
    // 0x8080011C: addiu       $a0, $zero, 0x335
    ctx->r4 = ADD32(0, 0X335);
    // 0x80800120: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800124: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x80800128: jal         0x80108A30
    // 0x8080012C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80108A30(rdram, ctx);
        goto after_3;
    // 0x8080012C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
    // 0x80800130: jal         0x800EA05C
    // 0x80800134: nop

    func_800EA05C(rdram, ctx);
        goto after_4;
    // 0x80800134: nop

    after_4:
    // 0x80800138: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x8080013C: beql        $v0, $at, L_80800150
    if (ctx->r2 == ctx->r1) {
        // 0x80800140: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800150;
    }
    goto skip_1;
    // 0x80800140: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x80800144: jal         0x8010A624
    // 0x80800148: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A624(rdram, ctx);
        goto after_5;
    // 0x80800148: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x8080014C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800150:
    // 0x80800150: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80800154: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x80800158: jal         0x80089CF0
    // 0x8080015C: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    _subaddiefade_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x8080015C: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    after_6:
    // 0x80800160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800168: jr          $ra
    // 0x8080016C: nop

    return;
    // 0x8080016C: nop

;}
RECOMP_FUNC void func_80801884_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801884: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801888: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080188C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801890: jal         0x80100094
    // 0x80801894: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801894: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801898: jal         0x800DC0C0
    // 0x8080189C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x8080189C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808018A0: jal         0x800EA05C
    // 0x808018A4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x808018A4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x808018A8: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x808018AC: bne         $v0, $at, L_808018CC
    if (ctx->r2 != ctx->r1) {
        // 0x808018B0: lwc1        $f2, 0x18($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
            goto L_808018CC;
    }
    // 0x808018B0: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x808018B4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808018B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808018BC: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x808018C0: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808018C4: beql        $t8, $at, L_8080192C
    if (ctx->r24 == ctx->r1) {
        // 0x808018C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080192C;
    }
    goto skip_0;
    // 0x808018C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_808018CC:
    // 0x808018CC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x808018D0: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1608, 0X5010) << 16);
    // 0x808018D4: addiu       $t2, $t2, 0x5010
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1608, 0X5010));
    // 0x808018D8: lbu         $t0, 0x39($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X39);
    // 0x808018DC: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x808018E0: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x808018E4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808018E8: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x808018EC: nop

    // 0x808018F0: bc1fl       L_80801904
    if (!c1cs) {
        // 0x808018F4: lwc1        $f6, 0x4($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
            goto L_80801904;
    }
    goto skip_1;
    // 0x808018F4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x808018F8: b           L_80801920
    // 0x808018FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80801920;
    // 0x808018FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801900: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
L_80801904:
    // 0x80801904: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801908: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8080190C: nop

    // 0x80801910: bc1f        L_80801920
    if (!c1cs) {
        // 0x80801914: nop
    
            goto L_80801920;
    }
    // 0x80801914: nop

    // 0x80801918: b           L_80801920
    // 0x8080191C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_80801920;
    // 0x8080191C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80801920:
    // 0x80801920: jal         0x80108B04
    // 0x80801924: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80108B04(rdram, ctx);
        goto after_3;
    // 0x80801924: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80801928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080192C:
    // 0x8080192C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801930: jr          $ra
    // 0x80801934: nop

    return;
    // 0x80801934: nop

;}
RECOMP_FUNC void _badust_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800849E8: syscall     125
    recomp_syscall_handler(rdram, ctx, 0x800849E8);
    return;
    // 0x800849EC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800F6640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6640: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6644: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6648: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F664C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F6650: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F6654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6658: jal         0x80092EA4
    // 0x800F665C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80092EA4(rdram, ctx);
        goto after_0;
    // 0x800F665C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F6660: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F6664: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800F6668: beq         $t7, $zero, L_800F6680
    if (ctx->r15 == 0) {
        // 0x800F666C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800F6680;
    }
    // 0x800F666C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F6670: jal         0x80091E80
    // 0x800F6674: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80091E80(rdram, ctx);
        goto after_1;
    // 0x800F6674: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800F6678: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F667C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800F6680:
    // 0x800F6680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6684: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F6688: jr          $ra
    // 0x800F668C: nop

    return;
    // 0x800F668C: nop

;}
RECOMP_FUNC void func_80803918_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803918: jr          $ra
    // 0x8080391C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080391C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void subaddieaudioquick_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800058: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080005C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3194, 0X1D0) << 16);
    // 0x80800060: addiu       $a2, $a2, 0x1D0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3194, 0X1D0));
    // 0x80800064: jal         0x800C4350
    // 0x80800068: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_0;
    // 0x80800068: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8080006C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800070: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x80800074: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80800078: lw          $a1, 0x70($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X70);
    // 0x8080007C: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x80800080: jal         0x80800000
    // 0x80800084: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    subaddieaudioquick_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800084: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_1:
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080008C: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x80800090: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void _gcmapDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800880F8: syscall     672
    recomp_syscall_handler(rdram, ctx, 0x800880F8);
    return;
    // 0x800880FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800BDC68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDC68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BDC6C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800BDC70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BDC74: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BDC78: jal         0x80087C68
    // 0x800BDC7C: addiu       $a0, $a0, -0x7BF0
    ctx->r4 = ADD32(ctx->r4, -0X7BF0);
    _gccubeDll_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x800BDC7C: addiu       $a0, $a0, -0x7BF0
    ctx->r4 = ADD32(ctx->r4, -0X7BF0);
    after_0:
    // 0x800BDC80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BDC84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BDC88: jr          $ra
    // 0x800BDC8C: nop

    return;
    // 0x800BDC8C: nop

;}
RECOMP_FUNC void func_80800D48_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800D54: jal         0x80100094
    // 0x80800D58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800D5C: bne         $v0, $zero, L_80800DA4
    if (ctx->r2 != 0) {
        // 0x80800D60: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800DA4;
    }
    // 0x80800D60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800D68: jal         0x800897C0
    // 0x80800D6C: addiu       $a2, $zero, 0x8F
    ctx->r6 = ADD32(0, 0X8F);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800D6C: addiu       $a2, $zero, 0x8F
    ctx->r6 = ADD32(0, 0X8F);
    after_1:
    // 0x80800D70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D74: jal         0x80100094
    // 0x80800D78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800D78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800D7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D80: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800D84: jal         0x800897E8
    // 0x80800D88: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80800D88: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_3:
    // 0x80800D8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D90: jal         0x80100094
    // 0x80800D94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800D94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800D98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D9C: jal         0x80089810
    // 0x80800DA0: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x80800DA0: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    after_5:
L_80800DA4:
    // 0x80800DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DAC: jr          $ra
    // 0x80800DB0: nop

    return;
    // 0x80800DB0: nop

;}
RECOMP_FUNC void chtrashcangame_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802CB4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2384, 0X33E8) << 16);
    // 0x80802CB8: jr          $ra
    // 0x80802CBC: addiu       $v0, $v0, 0x33E8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2384, 0X33E8));
    return;
    // 0x80802CBC: addiu       $v0, $v0, 0x33E8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2384, 0X33E8));
;}
RECOMP_FUNC void func_80800404_chweldarbossfireball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800404: jr          $ra
    // 0x80800408: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800408: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8080040C: nop

;}
RECOMP_FUNC void func_800A5CFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5CFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5D00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5D04: jal         0x800FF62C
    // 0x800A5D08: nop

    func_800FF62C(rdram, ctx);
        goto after_0;
    // 0x800A5D08: nop

    after_0:
    // 0x800A5D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5D10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5D14: jr          $ra
    // 0x800A5D18: nop

    return;
    // 0x800A5D18: nop

;}
RECOMP_FUNC void boot__bzero(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002B30: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x80002B34: bne         $at, $zero, L_80002BAC
    if (ctx->r1 != 0) {
        // 0x80002B38: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_80002BAC;
    }
    // 0x80002B38: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x80002B3C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x80002B40: beq         $v1, $zero, L_80002B50
    if (ctx->r3 == 0) {
        // 0x80002B44: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_80002B50;
    }
    // 0x80002B44: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x80002B48: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x80002B4C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_80002B50:
    // 0x80002B50: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x80002B54: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x80002B58: beq         $a3, $zero, L_80002B8C
    if (ctx->r7 == 0) {
        // 0x80002B5C: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_80002B8C;
    }
    // 0x80002B5C: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x80002B60: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_80002B64:
    // 0x80002B64: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80002B68: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x80002B6C: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x80002B70: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x80002B74: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x80002B78: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x80002B7C: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x80002B80: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x80002B84: bne         $a0, $a3, L_80002B64
    if (ctx->r4 != ctx->r7) {
        // 0x80002B88: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_80002B64;
    }
    // 0x80002B88: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_80002B8C:
    // 0x80002B8C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80002B90: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x80002B94: beq         $a3, $zero, L_80002BAC
    if (ctx->r7 == 0) {
        // 0x80002B98: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_80002BAC;
    }
    // 0x80002B98: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x80002B9C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_80002BA0:
    // 0x80002BA0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80002BA4: bne         $a0, $a3, L_80002BA0
    if (ctx->r4 != ctx->r7) {
        // 0x80002BA8: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_80002BA0;
    }
    // 0x80002BA8: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_80002BAC:
    // 0x80002BAC: blez        $a1, L_80002BC4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80002BB0: nop
    
            goto L_80002BC4;
    }
    // 0x80002BB0: nop

    // 0x80002BB4: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_80002BB8:
    // 0x80002BB8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80002BBC: bne         $a0, $a1, L_80002BB8
    if (ctx->r4 != ctx->r5) {
        // 0x80002BC0: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_80002BB8;
    }
    // 0x80002BC0: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_80002BC4:
    // 0x80002BC4: jr          $ra
    // 0x80002BC8: nop

    return;
    // 0x80002BC8: nop

;}
RECOMP_FUNC void chbottlesparty_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1508, 0X458) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x458
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1508, 0X458));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x458
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1508, 0X458));
;}
RECOMP_FUNC void func_801022E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801022E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801022E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801022EC: jal         0x80104248
    // 0x801022F0: nop

    func_80104248(rdram, ctx);
        goto after_0;
    // 0x801022F0: nop

    after_0:
    // 0x801022F4: beq         $v0, $zero, L_8010230C
    if (ctx->r2 == 0) {
        // 0x801022F8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8010230C;
    }
    // 0x801022F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801022FC: jal         0x8008B264
    // 0x80102300: nop

    anctrl_getIndex(rdram, ctx);
        goto after_1;
    // 0x80102300: nop

    after_1:
    // 0x80102304: b           L_80102314
    // 0x80102308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80102314;
    // 0x80102308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010230C:
    // 0x8010230C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80102310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80102314:
    // 0x80102314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102318: jr          $ra
    // 0x8010231C: nop

    return;
    // 0x8010231C: nop

;}
RECOMP_FUNC void func_80804B84_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804B84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804B88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804B8C: jal         0x80807C8C
    // 0x80804B90: nop

    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80804B90: nop

    after_0:
    // 0x80804B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804B98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804B9C: jr          $ra
    // 0x80804BA0: nop

    return;
    // 0x80804BA0: nop

;}
RECOMP_FUNC void func_800B58D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B58D4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800B58D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B58DC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B58E0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800B58E4: addiu       $t8, $t8, 0x7F28
    ctx->r24 = ADD32(ctx->r24, 0X7F28);
    // 0x800B58E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B58EC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800B58F0: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x800B58F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B58F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B58FC: beq         $a1, $zero, L_800B5914
    if (ctx->r5 == 0) {
        // 0x800B5900: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_800B5914;
    }
    // 0x800B5900: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B5904: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800B5908: jal         0x800B5450
    // 0x800B590C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800B5450(rdram, ctx);
        goto after_0;
    // 0x800B590C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800B5910: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800B5914:
    // 0x800B5914: lbu         $t9, 0x8($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X8);
    // 0x800B5918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B591C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B5920: andi        $t0, $t9, 0xFF7F
    ctx->r8 = ctx->r25 & 0XFF7F;
    // 0x800B5924: jr          $ra
    // 0x800B5928: sb          $t0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r8;
    return;
    // 0x800B5928: sb          $t0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r8;
;}
RECOMP_FUNC void func_8009C118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C118: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009C11C: lw          $t6, 0xE4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE4);
    // 0x8009C120: jr          $ra
    // 0x8009C124: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x8009C124: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800FF8_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800FFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801000: jal         0x800EA05C
    // 0x80801004: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80801004: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801008: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(924, 0X22E4) << 16);
    // 0x8080100C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(924, 0X22E8) << 16);
    // 0x80801010: addiu       $a0, $a0, 0x22E8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(924, 0X22E8));
    // 0x80801014: addiu       $v1, $v1, 0x22E4
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(924, 0X22E4));
    // 0x80801018: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
L_8080101C:
    // 0x8080101C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80801020: bne         $v0, $t6, L_80801030
    if (ctx->r2 != ctx->r14) {
        // 0x80801024: nop
    
            goto L_80801030;
    }
    // 0x80801024: nop

    // 0x80801028: b           L_8080103C
    // 0x8080102C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080103C;
    // 0x8080102C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801030:
    // 0x80801030: bnel        $v1, $a0, L_8080101C
    if (ctx->r3 != ctx->r4) {
        // 0x80801034: lhu         $t6, 0x0($v1)
        ctx->r14 = MEM_HU(ctx->r3, 0X0);
            goto L_8080101C;
    }
    goto skip_0;
    // 0x80801034: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    skip_0:
    // 0x80801038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080103C:
    // 0x8080103C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801044: jr          $ra
    // 0x80801048: nop

    return;
    // 0x80801048: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801908: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080190C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801910: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801914: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801918: jal         0x808004B4
    // 0x8080191C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    func_808004B4_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x8080191C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_0:
    // 0x80801920: jal         0x8008E3E8
    // 0x80801924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E3E8(rdram, ctx);
        goto after_1;
    // 0x80801924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801928: beq         $v0, $zero, L_80801938
    if (ctx->r2 == 0) {
        // 0x8080192C: nop
    
            goto L_80801938;
    }
    // 0x8080192C: nop

    // 0x80801930: jal         0x80085078
    // 0x80801934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80801934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_80801938:
    // 0x80801938: jal         0x8009D658
    // 0x8080193C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_3;
    // 0x8080193C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801940: jal         0x800D8FF8
    // 0x80801944: nop

    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x80801944: nop

    after_4:
    // 0x80801948: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x8080194C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801950: jal         0x800F0E00
    // 0x80801954: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    func_800F0E00(rdram, ctx);
        goto after_5;
    // 0x80801954: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    after_5:
    // 0x80801958: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x8080195C: jal         0x8008DF18
    // 0x80801960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DF18(rdram, ctx);
        goto after_6;
    // 0x80801960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801964: beq         $v0, $zero, L_808019E8
    if (ctx->r2 == 0) {
        // 0x80801968: addiu       $t6, $zero, 0x15
        ctx->r14 = ADD32(0, 0X15);
            goto L_808019E8;
    }
    // 0x80801968: addiu       $t6, $zero, 0x15
    ctx->r14 = ADD32(0, 0X15);
    // 0x8080196C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801970: jal         0x800963C0
    // 0x80801974: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800963C0(rdram, ctx);
        goto after_7;
    // 0x80801974: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_7:
    // 0x80801978: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8080197C: jal         0x800F1EA4
    // 0x80801980: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F1EA4(rdram, ctx);
        goto after_8;
    // 0x80801980: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_8:
    // 0x80801984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801988: jal         0x8009D3A8
    // 0x8080198C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_9;
    // 0x8080198C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80801990: jal         0x8009BFD8
    // 0x80801994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BFD8(rdram, ctx);
        goto after_10;
    // 0x80801994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801998: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8080199C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808019A0: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x808019A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808019A8: lui         $a3, 0x4409
    ctx->r7 = S32(0X4409 << 16);
    // 0x808019AC: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x808019B0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808019B4: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x808019B8: jal         0x800F10B4
    // 0x808019BC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_11;
    // 0x808019BC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x808019C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808019C4: jal         0x8009B9B0
    // 0x808019C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_12;
    // 0x808019C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808019CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019D0: jal         0x8009B9C0
    // 0x808019D4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_13;
    // 0x808019D4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_13:
    // 0x808019D8: jal         0x800849D0
    // 0x808019DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x808019DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808019E0: b           L_808019EC
    // 0x808019E4: nop

        goto L_808019EC;
    // 0x808019E4: nop

L_808019E8:
    // 0x808019E8: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_808019EC:
    // 0x808019EC: jal         0x8008E35C
    // 0x808019F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_15;
    // 0x808019F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808019F4: beq         $v0, $zero, L_80801A00
    if (ctx->r2 == 0) {
        // 0x808019F8: addiu       $t7, $zero, 0x2D
        ctx->r15 = ADD32(0, 0X2D);
            goto L_80801A00;
    }
    // 0x808019F8: addiu       $t7, $zero, 0x2D
    ctx->r15 = ADD32(0, 0X2D);
    // 0x808019FC: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_80801A00:
    // 0x80801A00: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80801A04: lwc1        $f10, 0x16C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80801A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A0C: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80801A10: nop

    // 0x80801A14: bc1fl       L_80801A4C
    if (!c1cs) {
        // 0x80801A18: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801A4C;
    }
    goto skip_0;
    // 0x80801A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80801A1C: jal         0x80091A58
    // 0x80801A20: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_16;
    // 0x80801A20: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_16:
    // 0x80801A24: beql        $v0, $zero, L_80801A4C
    if (ctx->r2 == 0) {
        // 0x80801A28: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801A4C;
    }
    goto skip_1;
    // 0x80801A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80801A2C: jal         0x8008E078
    // 0x80801A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_17;
    // 0x80801A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801A34: beq         $v0, $zero, L_80801A48
    if (ctx->r2 == 0) {
        // 0x80801A38: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801A48;
    }
    // 0x80801A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A3C: jal         0x8080075C
    // 0x80801A40: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_8080075C_bsbtrot(rdram, ctx);
        goto after_18;
    // 0x80801A40: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_18:
    // 0x80801A44: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
L_80801A48:
    // 0x80801A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801A4C:
    // 0x80801A4C: jal         0x8009E5C8
    // 0x80801A50: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    bs_setState(rdram, ctx);
        goto after_19;
    // 0x80801A50: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_19:
    // 0x80801A54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801A58: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801A5C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80801A60: jr          $ra
    // 0x80801A64: nop

    return;
    // 0x80801A64: nop

;}
RECOMP_FUNC void _glglobaldata_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800885B0: syscall     694
    recomp_syscall_handler(rdram, ctx, 0x800885B0);
    return;
    // 0x800885B4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void glglobaldata_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80800080: xori        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 ^ 0X8;
    // 0x80800084: jr          $ra
    // 0x80800088: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    return;
    // 0x80800088: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_80800030_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080003C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800040: jal         0x8009E77C
    // 0x80800044: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x80800044: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_0:
    // 0x80800048: bnel        $v0, $zero, L_808000F4
    if (ctx->r2 != 0) {
        // 0x8080004C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000F4;
    }
    goto skip_0;
    // 0x8080004C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800050: jal         0x80085290
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800058: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x8080005C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800064: jal         0x8009C554
    // 0x80800068: lui         $a1, 0x4302
    ctx->r5 = S32(0X4302 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_2;
    // 0x80800068: lui         $a1, 0x4302
    ctx->r5 = S32(0X4302 << 16);
    after_2:
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: jal         0x8009BCB4
    // 0x80800074: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_gravity(rdram, ctx);
        goto after_3;
    // 0x80800074: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800078: lui         $a1, 0xC3C7
    ctx->r5 = S32(0XC3C7 << 16);
    // 0x8080007C: ori         $a1, $a1, 0xFEB8
    ctx->r5 = ctx->r5 | 0XFEB8;
    // 0x80800080: jal         0x8009BCC4
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800088: jal         0x800F8B88
    // 0x8080008C: nop

    func_800F8B88(rdram, ctx);
        goto after_5;
    // 0x8080008C: nop

    after_5:
    // 0x80800090: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800094: beq         $v0, $at, L_808000A4
    if (ctx->r2 == ctx->r1) {
        // 0x80800098: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000A4;
    }
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080009C: jal         0x800A0CF4
    // 0x808000A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_6;
    // 0x808000A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
L_808000A4:
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: jal         0x800961AC
    // 0x808000AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800961AC(rdram, ctx);
        goto after_7;
    // 0x808000AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: jal         0x80093360
    // 0x808000B8: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    func_80093360(rdram, ctx);
        goto after_8;
    // 0x808000B8: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    after_8:
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C0: jal         0x8009BC5C
    // 0x808000C4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_8009BC5C(rdram, ctx);
        goto after_9;
    // 0x808000C4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_9:
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: jal         0x80085298
    // 0x808000D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _baswim_entrypoint_6(rdram, ctx);
        goto after_10;
    // 0x808000D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808000D4: jal         0x8009E6F8
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_11;
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808000DC: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x808000E0: beq         $v0, $at, L_808000F0
    if (ctx->r2 == ctx->r1) {
        // 0x808000E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000F0;
    }
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: jal         0x80085558
    // 0x808000EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _baairbar_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x808000EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
L_808000F0:
    // 0x808000F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F4:
    // 0x808000F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

;}
RECOMP_FUNC void func_80800438_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800438: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080043C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800440: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800444: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800448: jal         0x80800694
    // 0x8080044C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    bsbabykaz_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x8080044C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800450: jal         0x8008CAEC
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_1;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800458: beq         $v0, $zero, L_80800464
    if (ctx->r2 == 0) {
        // 0x8080045C: addiu       $t6, $zero, 0x136
        ctx->r14 = ADD32(0, 0X136);
            goto L_80800464;
    }
    // 0x8080045C: addiu       $t6, $zero, 0x136
    ctx->r14 = ADD32(0, 0X136);
    // 0x80800460: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800464:
    // 0x80800464: jal         0x8008DD04
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_2;
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080046C: beq         $v0, $zero, L_8080047C
    if (ctx->r2 == 0) {
        // 0x80800470: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080047C;
    }
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800474: addiu       $t7, $zero, 0x133
    ctx->r15 = ADD32(0, 0X133);
    // 0x80800478: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_8080047C:
    // 0x8080047C: jal         0x808001A8
    // 0x80800480: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808001A8_bsbabykaz(rdram, ctx);
        goto after_3;
    // 0x80800480: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800488: jal         0x8009E5C8
    // 0x8080048C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x8080048C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80800490: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800494: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800498: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080049C: jr          $ra
    // 0x808004A0: nop

    return;
    // 0x808004A0: nop

;}
RECOMP_FUNC void func_80020298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020298: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002029C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800202A0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800202A4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800202A8: jal         0x8002FEC0
    // 0x800202AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800202AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800202B0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800202B4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800202B8: lw          $t6, 0x11D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11D0);
    // 0x800202BC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800202C0: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800202C4: lw          $t7, 0x11D8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11D8);
    // 0x800202C8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800202CC: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800202D0: lw          $t8, 0x11D4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11D4);
    // 0x800202D4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800202D8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800202DC: sh          $zero, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = 0;
    // 0x800202E0: beq         $t9, $zero, L_80020304
    if (ctx->r25 == 0) {
        // 0x800202E4: nop
    
            goto L_80020304;
    }
    // 0x800202E4: nop

L_800202E8:
    // 0x800202E8: lhu         $t0, 0x2A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2A);
    // 0x800202EC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800202F0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800202F4: sh          $t1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r9;
    // 0x800202F8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800202FC: bne         $t3, $zero, L_800202E8
    if (ctx->r11 != 0) {
        // 0x80020300: sw          $t3, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r11;
            goto L_800202E8;
    }
    // 0x80020300: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
L_80020304:
    // 0x80020304: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80020308: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    // 0x8002030C: beq         $t4, $zero, L_80020330
    if (ctx->r12 == 0) {
        // 0x80020310: nop
    
            goto L_80020330;
    }
    // 0x80020310: nop

L_80020314:
    // 0x80020314: lhu         $t5, 0x28($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X28);
    // 0x80020318: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8002031C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80020320: sh          $t6, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r14;
    // 0x80020324: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80020328: bne         $t8, $zero, L_80020314
    if (ctx->r24 != 0) {
        // 0x8002032C: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_80020314;
    }
    // 0x8002032C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_80020330:
    // 0x80020330: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80020334: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
    // 0x80020338: beq         $t9, $zero, L_8002035C
    if (ctx->r25 == 0) {
        // 0x8002033C: nop
    
            goto L_8002035C;
    }
    // 0x8002033C: nop

L_80020340:
    // 0x80020340: lhu         $t0, 0x26($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X26);
    // 0x80020344: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80020348: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8002034C: sh          $t1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r9;
    // 0x80020350: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80020354: bne         $t3, $zero, L_80020340
    if (ctx->r11 != 0) {
        // 0x80020358: sw          $t3, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r11;
            goto L_80020340;
    }
    // 0x80020358: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
L_8002035C:
    // 0x8002035C: lhu         $t4, 0x28($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X28);
    // 0x80020360: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80020364: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x80020368: lhu         $t6, 0x2A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2A);
    // 0x8002036C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80020370: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x80020374: jal         0x8002FEC0
    // 0x80020378: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80020378: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x8002037C: b           L_8002038C
    // 0x80020380: lhu         $v0, 0x26($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X26);
        goto L_8002038C;
    // 0x80020380: lhu         $v0, 0x26($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X26);
    // 0x80020384: b           L_8002038C
    // 0x80020388: nop

        goto L_8002038C;
    // 0x80020388: nop

L_8002038C:
    // 0x8002038C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020390: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80020394: jr          $ra
    // 0x80020398: nop

    return;
    // 0x80020398: nop

;}
RECOMP_FUNC void func_800EEDA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EEDA0: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800EEDA4: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x800EEDA8: xor         $v0, $t6, $t7
    ctx->r2 = ctx->r14 ^ ctx->r15;
    // 0x800EEDAC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800EEDB0: beq         $v0, $zero, L_800EEDE0
    if (ctx->r2 == 0) {
        // 0x800EEDB4: nop
    
            goto L_800EEDE0;
    }
    // 0x800EEDB4: nop

    // 0x800EEDB8: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x800EEDBC: lh          $t9, 0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2);
    // 0x800EEDC0: xor         $v0, $t8, $t9
    ctx->r2 = ctx->r24 ^ ctx->r25;
    // 0x800EEDC4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800EEDC8: beq         $v0, $zero, L_800EEDE0
    if (ctx->r2 == 0) {
        // 0x800EEDCC: nop
    
            goto L_800EEDE0;
    }
    // 0x800EEDCC: nop

    // 0x800EEDD0: lh          $t0, 0x4($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4);
    // 0x800EEDD4: lh          $t1, 0x4($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X4);
    // 0x800EEDD8: xor         $v0, $t0, $t1
    ctx->r2 = ctx->r8 ^ ctx->r9;
    // 0x800EEDDC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_800EEDE0:
    // 0x800EEDE0: jr          $ra
    // 0x800EEDE4: nop

    return;
    // 0x800EEDE4: nop

;}
RECOMP_FUNC void func_800E6DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6DD8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800E6DDC: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x800E6DE0: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x800E6DE4: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x800E6DE8: beq         $t7, $zero, L_800E6E00
    if (ctx->r15 == 0) {
        // 0x800E6DEC: lui         $v1, 0x3B9A
        ctx->r3 = S32(0X3B9A << 16);
            goto L_800E6E00;
    }
    // 0x800E6DEC: lui         $v1, 0x3B9A
    ctx->r3 = S32(0X3B9A << 16);
    // 0x800E6DF0: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
L_800E6DF4:
    // 0x800E6DF4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E6DF8: bnel        $t8, $zero, L_800E6DF4
    if (ctx->r24 != 0) {
        // 0x800E6DFC: lbu         $t8, 0x1($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X1);
            goto L_800E6DF4;
    }
    goto skip_0;
    // 0x800E6DFC: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    skip_0:
L_800E6E00:
    // 0x800E6E00: bgez        $a1, L_800E6E1C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800E6E04: ori         $v0, $v1, 0xCA00
        ctx->r2 = ctx->r3 | 0XCA00;
            goto L_800E6E1C;
    }
    // 0x800E6E04: ori         $v0, $v1, 0xCA00
    ctx->r2 = ctx->r3 | 0XCA00;
    // 0x800E6E08: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800E6E0C: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x800E6E10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E6E14: b           L_800E6E2C
    // 0x800E6E18: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
        goto L_800E6E2C;
    // 0x800E6E18: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_800E6E1C:
    // 0x800E6E1C: beql        $a2, $zero, L_800E6E30
    if (ctx->r6 == 0) {
        // 0x800E6E20: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800E6E30;
    }
    goto skip_1;
    // 0x800E6E20: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    skip_1:
    // 0x800E6E24: sb          $a2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r6;
    // 0x800E6E28: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800E6E2C:
    // 0x800E6E2C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_800E6E30:
    // 0x800E6E30: beq         $at, $zero, L_800E6E70
    if (ctx->r1 == 0) {
        // 0x800E6E34: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_800E6E70;
    }
    // 0x800E6E34: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_800E6E38:
    // 0x800E6E38: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x800E6E3C: bne         $v1, $zero, L_800E6E48
    if (ctx->r3 != 0) {
        // 0x800E6E40: nop
    
            goto L_800E6E48;
    }
    // 0x800E6E40: nop

    // 0x800E6E44: break       7
    do_break(2148429380);
L_800E6E48:
    // 0x800E6E48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E6E4C: bne         $v1, $at, L_800E6E60
    if (ctx->r3 != ctx->r1) {
        // 0x800E6E50: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E6E60;
    }
    // 0x800E6E50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E6E54: bne         $v0, $at, L_800E6E60
    if (ctx->r2 != ctx->r1) {
        // 0x800E6E58: nop
    
            goto L_800E6E60;
    }
    // 0x800E6E58: nop

    // 0x800E6E5C: break       6
    do_break(2148429404);
L_800E6E60:
    // 0x800E6E60: mflo        $v0
    ctx->r2 = lo;
    // 0x800E6E64: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E6E68: bne         $at, $zero, L_800E6E38
    if (ctx->r1 != 0) {
        // 0x800E6E6C: nop
    
            goto L_800E6E38;
    }
    // 0x800E6E6C: nop

L_800E6E70:
    // 0x800E6E70: bne         $v0, $zero, L_800E6E88
    if (ctx->r2 != 0) {
        // 0x800E6E74: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_800E6E88;
    }
    // 0x800E6E74: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800E6E78: addiu       $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
    // 0x800E6E7C: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
    // 0x800E6E80: b           L_800E6F74
    // 0x800E6E84: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_800E6F74;
    // 0x800E6E84: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800E6E88:
    // 0x800E6E88: blez        $v0, L_800E6F74
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800E6E8C: nop
    
            goto L_800E6F74;
    }
    // 0x800E6E8C: nop

L_800E6E90:
    // 0x800E6E90: beq         $a3, $zero, L_800E6ED4
    if (ctx->r7 == 0) {
        // 0x800E6E94: nop
    
            goto L_800E6ED4;
    }
    // 0x800E6E94: nop

    // 0x800E6E98: div         $zero, $a1, $v0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r2)));
    // 0x800E6E9C: mflo        $t1
    ctx->r9 = lo;
    // 0x800E6EA0: addiu       $t2, $t1, 0x10
    ctx->r10 = ADD32(ctx->r9, 0X10);
    // 0x800E6EA4: bne         $v0, $zero, L_800E6EB0
    if (ctx->r2 != 0) {
        // 0x800E6EA8: nop
    
            goto L_800E6EB0;
    }
    // 0x800E6EA8: nop

    // 0x800E6EAC: break       7
    do_break(2148429484);
L_800E6EB0:
    // 0x800E6EB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E6EB4: bne         $v0, $at, L_800E6EC8
    if (ctx->r2 != ctx->r1) {
        // 0x800E6EB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E6EC8;
    }
    // 0x800E6EB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E6EBC: bne         $a1, $at, L_800E6EC8
    if (ctx->r5 != ctx->r1) {
        // 0x800E6EC0: nop
    
            goto L_800E6EC8;
    }
    // 0x800E6EC0: nop

    // 0x800E6EC4: break       6
    do_break(2148429508);
L_800E6EC8:
    // 0x800E6EC8: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
    // 0x800E6ECC: b           L_800E6F0C
    // 0x800E6ED0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_800E6F0C;
    // 0x800E6ED0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800E6ED4:
    // 0x800E6ED4: div         $zero, $a1, $v0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r2)));
    // 0x800E6ED8: mflo        $t3
    ctx->r11 = lo;
    // 0x800E6EDC: addiu       $t4, $t3, 0x30
    ctx->r12 = ADD32(ctx->r11, 0X30);
    // 0x800E6EE0: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x800E6EE4: bne         $v0, $zero, L_800E6EF0
    if (ctx->r2 != 0) {
        // 0x800E6EE8: nop
    
            goto L_800E6EF0;
    }
    // 0x800E6EE8: nop

    // 0x800E6EEC: break       7
    do_break(2148429548);
L_800E6EF0:
    // 0x800E6EF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E6EF4: bne         $v0, $at, L_800E6F08
    if (ctx->r2 != ctx->r1) {
        // 0x800E6EF8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E6F08;
    }
    // 0x800E6EF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E6EFC: bne         $a1, $at, L_800E6F08
    if (ctx->r5 != ctx->r1) {
        // 0x800E6F00: nop
    
            goto L_800E6F08;
    }
    // 0x800E6F00: nop

    // 0x800E6F04: break       6
    do_break(2148429572);
L_800E6F08:
    // 0x800E6F08: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800E6F0C:
    // 0x800E6F0C: div         $zero, $a1, $v0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r2)));
    // 0x800E6F10: bne         $v0, $zero, L_800E6F1C
    if (ctx->r2 != 0) {
        // 0x800E6F14: nop
    
            goto L_800E6F1C;
    }
    // 0x800E6F14: nop

    // 0x800E6F18: break       7
    do_break(2148429592);
L_800E6F1C:
    // 0x800E6F1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E6F20: bne         $v0, $at, L_800E6F34
    if (ctx->r2 != ctx->r1) {
        // 0x800E6F24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E6F34;
    }
    // 0x800E6F24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E6F28: bne         $a1, $at, L_800E6F34
    if (ctx->r5 != ctx->r1) {
        // 0x800E6F2C: nop
    
            goto L_800E6F34;
    }
    // 0x800E6F2C: nop

    // 0x800E6F30: break       6
    do_break(2148429616);
L_800E6F34:
    // 0x800E6F34: mfhi        $a1
    ctx->r5 = hi;
    // 0x800E6F38: nop

    // 0x800E6F3C: nop

    // 0x800E6F40: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x800E6F44: bne         $v1, $zero, L_800E6F50
    if (ctx->r3 != 0) {
        // 0x800E6F48: nop
    
            goto L_800E6F50;
    }
    // 0x800E6F48: nop

    // 0x800E6F4C: break       7
    do_break(2148429644);
L_800E6F50:
    // 0x800E6F50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E6F54: bne         $v1, $at, L_800E6F68
    if (ctx->r3 != ctx->r1) {
        // 0x800E6F58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E6F68;
    }
    // 0x800E6F58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E6F5C: bne         $v0, $at, L_800E6F68
    if (ctx->r2 != ctx->r1) {
        // 0x800E6F60: nop
    
            goto L_800E6F68;
    }
    // 0x800E6F60: nop

    // 0x800E6F64: break       6
    do_break(2148429668);
L_800E6F68:
    // 0x800E6F68: mflo        $v0
    ctx->r2 = lo;
    // 0x800E6F6C: bgtz        $v0, L_800E6E90
    if (SIGNED(ctx->r2) > 0) {
        // 0x800E6F70: nop
    
            goto L_800E6E90;
    }
    // 0x800E6F70: nop

L_800E6F74:
    // 0x800E6F74: jr          $ra
    // 0x800E6F78: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    return;
    // 0x800E6F78: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
;}
