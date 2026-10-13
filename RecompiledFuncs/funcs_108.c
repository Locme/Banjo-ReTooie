#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bsbkflamethrower_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800829A0: syscall     23
    recomp_syscall_handler(rdram, ctx, 0x800829A0);
    return;
    // 0x800829A4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80024E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024E70: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80024E74: sb          $a1, 0x88($a0)
    MEM_B(0X88, ctx->r4) = ctx->r5;
    // 0x80024E78: jr          $ra
    // 0x80024E7C: nop

    return;
    // 0x80024E7C: nop

;}
RECOMP_FUNC void bamoveledge_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chtntbox_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1892, 0X988) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x988
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1892, 0X988));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x988
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1892, 0X988));
;}
RECOMP_FUNC void func_80800F84_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F84: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800F88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F8C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800F90: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800F94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F98: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80800F9C: jal         0x80100094
    // 0x80800FA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800FA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800FA4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800FA8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800FAC: jal         0x80102424
    // 0x80800FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800FB4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80800FB8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800FBC: beq         $a2, $at, L_80800FE8
    if (ctx->r6 == ctx->r1) {
        // 0x80800FC0: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80800FE8;
    }
    // 0x80800FC0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80800FC4: beq         $a2, $at, L_80801024
    if (ctx->r6 == ctx->r1) {
        // 0x80800FC8: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80801024;
    }
    // 0x80800FC8: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80800FCC: beq         $a2, $at, L_8080104C
    if (ctx->r6 == ctx->r1) {
        // 0x80800FD0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080104C;
    }
    // 0x80800FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FD4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80800FD8: beql        $a2, $at, L_808010A0
    if (ctx->r6 == ctx->r1) {
        // 0x80800FDC: lbu         $t1, 0x65($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X65);
            goto L_808010A0;
    }
    goto skip_0;
    // 0x80800FDC: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    skip_0:
    // 0x80800FE0: b           L_808010AC
    // 0x80800FE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808010AC;
    // 0x80800FE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800FE8:
    // 0x80800FE8: jal         0x80104248
    // 0x80800FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_2;
    // 0x80800FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800FF0: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800FF4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800FF8: jal         0x8008B1C8
    // 0x80800FFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_3;
    // 0x80800FFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80801000: jal         0x80801C7C
    // 0x80801004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C7C_chinflatableboss(rdram, ctx);
        goto after_4;
    // 0x80801004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801008: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8080100C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(832, 0X2D8C) << 16);
    // 0x80801010: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80801014: lh          $t7, 0x2D8C($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(832, 0X2D8C));
    // 0x80801018: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8080101C: b           L_808010A8
    // 0x80801020: sb          $t7, 0x495($t8)
    MEM_B(0X495, ctx->r24) = ctx->r15;
        goto L_808010A8;
    // 0x80801020: sb          $t7, 0x495($t8)
    MEM_B(0X495, ctx->r24) = ctx->r15;
L_80801024:
    // 0x80801024: jal         0x80104248
    // 0x80801028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_5;
    // 0x80801028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080102C: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80801030: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801034: jal         0x8008B1C8
    // 0x80801038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_6;
    // 0x80801038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x8080103C: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801040: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80801044: b           L_808010A8
    // 0x80801048: swc1        $f4, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f4.u32l;
        goto L_808010A8;
    // 0x80801048: swc1        $f4, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f4.u32l;
L_8080104C:
    // 0x8080104C: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x80801050: jal         0x80802A00
    // 0x80801054: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80802A00_chinflatableboss(rdram, ctx);
        goto after_7;
    // 0x80801054: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_7:
    // 0x80801058: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080105C: addiu       $t0, $zero, 0x3A
    ctx->r8 = ADD32(0, 0X3A);
    // 0x80801060: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801064: addiu       $a1, $zero, 0x1084
    ctx->r5 = ADD32(0, 0X1084);
    // 0x80801068: addiu       $a2, $zero, 0x10C
    ctx->r6 = ADD32(0, 0X10C);
    // 0x8080106C: jal         0x8008A208
    // 0x80801070: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80801070: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x80801074: jal         0x8010A570
    // 0x80801078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_9;
    // 0x80801078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080107C: jal         0x80104248
    // 0x80801080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_10;
    // 0x80801080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801084: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80801088: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080108C: jal         0x8008B1C8
    // 0x80801090: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_11;
    // 0x80801090: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x80801094: b           L_808010AC
    // 0x80801098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808010AC;
    // 0x80801098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080109C: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
L_808010A0:
    // 0x808010A0: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x808010A4: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_808010A8:
    // 0x808010A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808010AC:
    // 0x808010AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808010B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808010B4: jr          $ra
    // 0x808010B8: nop

    return;
    // 0x808010B8: nop

;}
RECOMP_FUNC void suexpression_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AE8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800AEC: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x80800AF0: lh          $t9, 0x8($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X8);
    // 0x80800AF4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3138, 0XD48) << 16);
    // 0x80800AF8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800AFC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80800B00: lwc1        $f0, 0xD48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3138, 0XD48));
    // 0x80800B04: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800B08: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800B0C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800B10: nop

    // 0x80800B14: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800B18: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800B1C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800B20: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80800B24: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80800B28: sh          $t8, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r24;
    // 0x80800B2C: jr          $ra
    // 0x80800B30: sh          $t1, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r9;
    return;
    // 0x80800B30: sh          $t1, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void chfantasysafe_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800928: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2380, 0XAA0) << 16);
    // 0x8080092C: jr          $ra
    // 0x80800930: addiu       $v0, $v0, 0xAA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2380, 0XAA0));
    return;
    // 0x80800930: addiu       $v0, $v0, 0xAA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2380, 0XAA0));
;}
RECOMP_FUNC void func_808009D0_chkingjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009D8: jal         0x80800C18
    // 0x808009DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800C18_chkingjinjo(rdram, ctx);
        goto after_0;
    // 0x808009DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808009E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808009E4: jal         0x800897C8
    // 0x808009E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808009E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808009EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009F4: jr          $ra
    // 0x808009F8: nop

    return;
    // 0x808009F8: nop

;}
RECOMP_FUNC void ncfixposrot_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800108: jal         0x800EE7F8
    // 0x8080010C: nop

    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080010C: nop

    after_0:
    // 0x80800110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800118: jr          $ra
    // 0x8080011C: nop

    return;
    // 0x8080011C: nop

;}
RECOMP_FUNC void chdinotraindoorswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2052, 0X80) << 16);
    // 0x80800074: jr          $ra
    // 0x80800078: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2052, 0X80));
    return;
    // 0x80800078: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2052, 0X80));
    // 0x8080007C: nop

;}
RECOMP_FUNC void func_8010C878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010C87C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C880: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010C884: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010C888: lh          $t6, 0x8A($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8A);
    // 0x8010C88C: lh          $t7, 0x88($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X88);
    // 0x8010C890: lwc1        $f0, 0x38($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8010C894: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8010C898: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8010C89C: lhu         $v0, 0x62($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X62);
    // 0x8010C8A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010C8A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8010C8A8: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8010C8AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010C8B0: mul.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8010C8B4: nop

    // 0x8010C8B8: mul.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8010C8BC: bgez        $v0, L_8010C8D0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8010C8C0: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8010C8D0;
    }
    // 0x8010C8C0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010C8C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010C8C8: nop

    // 0x8010C8CC: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8010C8D0:
    // 0x8010C8D0: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8010C8D4: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8010C8D8: mul.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8010C8DC: beql        $v0, $zero, L_8010C8FC
    if (ctx->r2 == 0) {
        // 0x8010C8E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010C8FC;
    }
    goto skip_0;
    // 0x8010C8E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8010C8E4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8010C8E8: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8010C8EC: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8010C8F0: jal         0x8010C788
    // 0x8010C8F4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8010C788(rdram, ctx);
        goto after_0;
    // 0x8010C8F4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x8010C8F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010C8FC:
    // 0x8010C8FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010C900: jr          $ra
    // 0x8010C904: nop

    return;
    // 0x8010C904: nop

;}
RECOMP_FUNC void cheggice_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800290: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800294: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800298: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080029C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808002A0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808002A4: jal         0x8008A488
    // 0x808002A8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    _sueggmove_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x808002A8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808002AC: addiu       $a0, $zero, 0x15C
    ctx->r4 = ADD32(0, 0X15C);
    // 0x808002B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808002B4: jal         0x8008A3D0
    // 0x808002B8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    _suegg_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808002B8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x808002BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2120, 0X3D4) << 16);
    // 0x808002C0: lwc1        $f4, 0x3D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2120, 0X3D4));
    // 0x808002C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808002C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002CC: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x808002D0: jal         0x8008A380
    // 0x808002D4: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    _suegg_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808002D4: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    after_2:
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002DC: jal         0x8008A460
    // 0x808002E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sueggmove_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808002E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808002E4: lui         $a1, 0xC509
    ctx->r5 = S32(0XC509 << 16);
    // 0x808002E8: lui         $a2, 0xC6AB
    ctx->r6 = S32(0XC6AB << 16);
    // 0x808002EC: ori         $a2, $a2, 0xE000
    ctx->r6 = ctx->r6 | 0XE000;
    // 0x808002F0: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x808002F4: jal         0x8008A468
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmove_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: jal         0x8008A470
    // 0x80800304: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _sueggmove_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x80800304: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800308: lbu         $t6, 0x72($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X72);
    // 0x8080030C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800310: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x80800314: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80800318: sb          $t8, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r24;
    // 0x8080031C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800320: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800324: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800328: jr          $ra
    // 0x8080032C: nop

    return;
    // 0x8080032C: nop

;}
RECOMP_FUNC void func_800CE49C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE49C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CE4A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CE4A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800CE4A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800CE4AC: lh          $t6, 0x10($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X10);
    // 0x800CE4B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CE4B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800CE4B8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800CE4BC: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    // 0x800CE4C0: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800CE4C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CE4C8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800CE4CC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800CE4D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CE4D4: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800CE4D8: jal         0x800F10B4
    // 0x800CE4DC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x800CE4DC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800CE4E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CE4E4: lwc1        $f10, 0x59C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X59C0);
    // 0x800CE4E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800CE4EC: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800CE4F0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800CE4F4: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800CE4F8: nop

    // 0x800CE4FC: sh          $t8, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r24;
    // 0x800CE500: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800CE504: beql        $t9, $zero, L_800CE518
    if (ctx->r25 == 0) {
        // 0x800CE508: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800CE518;
    }
    goto skip_0;
    // 0x800CE508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800CE50C: jal         0x800CE3F4
    // 0x800CE510: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800CE3F4(rdram, ctx);
        goto after_1;
    // 0x800CE510: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800CE514: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800CE518:
    // 0x800CE518: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CE51C: jr          $ra
    // 0x800CE520: nop

    return;
    // 0x800CE520: nop

;}
RECOMP_FUNC void func_800123BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800123BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800123C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800123C4: jal         0x800A7D84
    // 0x800123C8: nop

    func_800A7D84(rdram, ctx);
        goto after_0;
    // 0x800123C8: nop

    after_0:
    // 0x800123CC: beq         $v0, $zero, L_800123DC
    if (ctx->r2 == 0) {
        // 0x800123D0: nop
    
            goto L_800123DC;
    }
    // 0x800123D0: nop

    // 0x800123D4: jal         0x800A7840
    // 0x800123D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A7840(rdram, ctx);
        goto after_1;
    // 0x800123D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
L_800123DC:
    // 0x800123DC: jal         0x800A5D1C
    // 0x800123E0: nop

    func_800A5D1C(rdram, ctx);
        goto after_2;
    // 0x800123E0: nop

    after_2:
    // 0x800123E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800123E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800123EC: jr          $ra
    // 0x800123F0: nop

    return;
    // 0x800123F0: nop

;}
RECOMP_FUNC void func_800CA79C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA79C: jr          $ra
    // 0x800CA7A0: lwc1        $f0, 0xF4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XF4);
    return;
    // 0x800CA7A0: lwc1        $f0, 0xF4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XF4);
;}
RECOMP_FUNC void func_80800048_susplinet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: lh          $t6, 0x32($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X32);
    // 0x8080004C: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80800050: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x80800054: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80800058: lh          $v0, 0x0($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X0);
    // 0x8080005C: andi        $t9, $v0, 0x4
    ctx->r25 = ctx->r2 & 0X4;
    // 0x80800060: jr          $ra
    // 0x80800064: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    return;
    // 0x80800064: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
;}
RECOMP_FUNC void func_80801494_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801494: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801498: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080149C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x808014A0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808014A4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x808014A8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x808014AC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x808014B0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808014B4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808014B8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808014BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808014C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808014C4: jal         0x80100094
    // 0x808014C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808014C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808014CC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x808014D0: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x808014D4: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x808014D8: addiu       $s5, $zero, 0x5
    ctx->r21 = ADD32(0, 0X5);
L_808014DC:
    // 0x808014DC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x808014E0: or          $s6, $fp, $zero
    ctx->r22 = ctx->r30 | 0;
L_808014E4:
    // 0x808014E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808014E8: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
L_808014EC:
    // 0x808014EC: sb          $s2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r18;
    // 0x808014F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808014F4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x808014F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808014FC: jal         0x80801870
    // 0x80801500: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_80801870_chpotogoldgame(rdram, ctx);
        goto after_1;
    // 0x80801500: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_1:
    // 0x80801504: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801508: bne         $s0, $s5, L_808014EC
    if (ctx->r16 != ctx->r21) {
        // 0x8080150C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808014EC;
    }
    // 0x8080150C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801510: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80801514: bne         $s3, $s7, L_808014E4
    if (ctx->r19 != ctx->r23) {
        // 0x80801518: addiu       $s6, $s6, 0x5
        ctx->r22 = ADD32(ctx->r22, 0X5);
            goto L_808014E4;
    }
    // 0x80801518: addiu       $s6, $s6, 0x5
    ctx->r22 = ADD32(ctx->r22, 0X5);
    // 0x8080151C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80801520: bne         $s4, $s5, L_808014DC
    if (ctx->r20 != ctx->r21) {
        // 0x80801524: addiu       $fp, $fp, 0x14
        ctx->r30 = ADD32(ctx->r30, 0X14);
            goto L_808014DC;
    }
    // 0x80801524: addiu       $fp, $fp, 0x14
    ctx->r30 = ADD32(ctx->r30, 0X14);
    // 0x80801528: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8080152C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801530: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801534: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801538: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080153C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80801540: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80801544: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80801548: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8080154C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80801550: jr          $ra
    // 0x80801554: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80801554: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void bsdronebubbled_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800244: jr          $ra
    // 0x80800248: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800248: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800CF67C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF67C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CF680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF684: jal         0x800CEA60
    // 0x800CF688: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CEA60(rdram, ctx);
        goto after_0;
    // 0x800CF688: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800CF68C: jal         0x800CF640
    // 0x800CF690: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800CF640(rdram, ctx);
        goto after_1;
    // 0x800CF690: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800CF694: jal         0x800CEF00
    // 0x800CF698: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800CEF00(rdram, ctx);
        goto after_2;
    // 0x800CF698: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800CF69C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF6A0: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800CF6A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CF6A8: jr          $ra
    // 0x800CF6AC: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    return;
    // 0x800CF6AC: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
;}
RECOMP_FUNC void func_80801220_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801220: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801224: addiu       $at, $zero, 0x12A0
    ctx->r1 = ADD32(0, 0X12A0);
    // 0x80801228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080122C: bne         $a1, $at, L_80801244
    if (ctx->r5 != ctx->r1) {
        // 0x80801230: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801244;
    }
    // 0x80801230: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801234: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1364, 0X281C) << 16);
    // 0x80801238: addiu       $a2, $a2, 0x281C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1364, 0X281C));
    // 0x8080123C: jal         0x80089D18
    // 0x80801240: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801240: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
L_80801244:
    // 0x80801244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080124C: jr          $ra
    // 0x80801250: nop

    return;
    // 0x80801250: nop

;}
RECOMP_FUNC void ncbastring_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    return;
    // 0x80800004: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _chblink_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800857C0: syscall     175
    recomp_syscall_handler(rdram, ctx, 0x800857C0);
    return;
    // 0x800857C4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800D60_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800D6C: bne         $a1, $zero, L_80800D84
    if (ctx->r5 != 0) {
        // 0x80800D70: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800D84;
    }
    // 0x80800D70: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800D74: jal         0x800D395C
    // 0x80800D78: nop

    func_800D395C(rdram, ctx);
        goto after_0;
    // 0x80800D78: nop

    after_0:
    // 0x80800D7C: beq         $v0, $zero, L_80800DB4
    if (ctx->r2 == 0) {
        // 0x80800D80: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_80800DB4;
    }
    // 0x80800D80: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
L_80800D84:
    // 0x80800D84: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800D88: addiu       $a0, $zero, 0x18B5
    ctx->r4 = ADD32(0, 0X18B5);
    // 0x80800D8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800D90: lbu         $t8, 0x65($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X65);
    // 0x80800D94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800D98: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80800D9C: sb          $t9, 0x65($t6)
    MEM_B(0X65, ctx->r14) = ctx->r25;
    // 0x80800DA0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800DA4: jal         0x800861A0
    // 0x80800DA8: addiu       $a1, $a1, 0xE
    ctx->r5 = ADD32(ctx->r5, 0XE);
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800DA8: addiu       $a1, $a1, 0xE
    ctx->r5 = ADD32(ctx->r5, 0XE);
    after_1:
    // 0x80800DAC: b           L_80800DCC
    // 0x80800DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800DCC;
    // 0x80800DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800DB4:
    // 0x80800DB4: lbu         $t0, 0x65($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X65);
    // 0x80800DB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800DBC: andi        $t1, $t0, 0xFFF7
    ctx->r9 = ctx->r8 & 0XFFF7;
    // 0x80800DC0: jal         0x800861A8
    // 0x80800DC4: sb          $t1, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r9;
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800DC4: sb          $t1, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r9;
    after_2:
    // 0x80800DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800DCC:
    // 0x80800DCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DD0: jr          $ra
    // 0x80800DD4: nop

    return;
    // 0x80800DD4: nop

;}
RECOMP_FUNC void func_8080013C_chglowbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080013C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800140: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800144: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800148: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080014C: jal         0x80100094
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800154: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800158: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080015C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800160: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800164: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1628, 0X136C) << 16);
    // 0x80800168: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8080016C: nop

    // 0x80800170: bc1fl       L_8080018C
    if (!c1cs) {
        // 0x80800174: lbu         $t9, 0x74($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X74);
            goto L_8080018C;
    }
    goto skip_0;
    // 0x80800174: lbu         $t9, 0x74($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X74);
    skip_0:
    // 0x80800178: lbu         $t7, 0x74($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X74);
    // 0x8080017C: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80800180: b           L_80800194
    // 0x80800184: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
        goto L_80800194;
    // 0x80800184: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
    // 0x80800188: lbu         $t9, 0x74($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X74);
L_8080018C:
    // 0x8080018C: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x80800190: sb          $t0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r8;
L_80800194:
    // 0x80800194: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80800198: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8080019C: bgez        $t3, L_808001C0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808001A0: nop
    
            goto L_808001C0;
    }
    // 0x808001A0: nop

    // 0x808001A4: lbu         $t5, 0x75($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X75);
    // 0x808001A8: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808001AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001B0: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x808001B4: sb          $t6, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r14;
    // 0x808001B8: b           L_808001C8
    // 0x808001BC: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
        goto L_808001C8;
    // 0x808001BC: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
L_808001C0:
    // 0x808001C0: lwc1        $f10, 0x136C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X136C));
    // 0x808001C4: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
L_808001C8:
    // 0x808001C8: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x808001CC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x808001D0: bgez        $t9, L_808001F8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808001D4: nop
    
            goto L_808001F8;
    }
    // 0x808001D4: nop

    // 0x808001D8: jal         0x800DA298
    // 0x808001DC: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808001DC: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    after_1:
    // 0x808001E0: beq         $v0, $zero, L_808001F8
    if (ctx->r2 == 0) {
        // 0x808001E4: nop
    
            goto L_808001F8;
    }
    // 0x808001E4: nop

    // 0x808001E8: jal         0x800FFAB0
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001F0: b           L_808002E4
    // 0x808001F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002E4;
    // 0x808001F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001F8:
    // 0x808001F8: jal         0x8008A498
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800200: bne         $v0, $zero, L_80800230
    if (ctx->r2 != 0) {
        // 0x80800204: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800230;
    }
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8080020C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800210: jal         0x80101FDC
    // 0x80800214: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800214: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    after_4:
    // 0x80800218: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080021C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800220: jal         0x800EE7F8
    // 0x80800224: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800224: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_5:
    // 0x80800228: b           L_80800280
    // 0x8080022C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
        goto L_80800280;
    // 0x8080022C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_80800230:
    // 0x80800230: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x80800234: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1628, 0X146C) << 16);
    // 0x80800238: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8080023C: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80800240: bgezl       $t2, L_80800260
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800244: lw          $t5, 0x0($t4)
        ctx->r13 = MEM_W(ctx->r12, 0X0);
            goto L_80800260;
    }
    goto skip_1;
    // 0x80800244: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    skip_1:
    // 0x80800248: lwc1        $f18, 0x146C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X146C));
    // 0x8080024C: addiu       $t3, $s0, 0x4
    ctx->r11 = ADD32(ctx->r16, 0X4);
    // 0x80800250: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x80800254: b           L_8080027C
    // 0x80800258: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
        goto L_8080027C;
    // 0x80800258: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8080025C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
L_80800260:
    // 0x80800260: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1628, 0X146C) << 16);
    // 0x80800264: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x80800268: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8080026C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800270: lwc1        $f4, 0x146C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X146C));
    // 0x80800274: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80800278: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_8080027C:
    // 0x8080027C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_80800280:
    // 0x80800280: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800284: jal         0x800EA05C
    // 0x80800288: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    func_800EA05C(rdram, ctx);
        goto after_6;
    // 0x80800288: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    after_6:
    // 0x8080028C: addiu       $at, $zero, 0x1A7
    ctx->r1 = ADD32(0, 0X1A7);
    // 0x80800290: beq         $v0, $at, L_808002A8
    if (ctx->r2 == ctx->r1) {
        // 0x80800294: addiu       $at, $zero, 0x1A8
        ctx->r1 = ADD32(0, 0X1A8);
            goto L_808002A8;
    }
    // 0x80800294: addiu       $at, $zero, 0x1A8
    ctx->r1 = ADD32(0, 0X1A8);
    // 0x80800298: beq         $v0, $at, L_808002A8
    if (ctx->r2 == ctx->r1) {
        // 0x8080029C: addiu       $at, $zero, 0x1A9
        ctx->r1 = ADD32(0, 0X1A9);
            goto L_808002A8;
    }
    // 0x8080029C: addiu       $at, $zero, 0x1A9
    ctx->r1 = ADD32(0, 0X1A9);
    // 0x808002A0: bnel        $v0, $at, L_808002C8
    if (ctx->r2 != ctx->r1) {
        // 0x808002A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002C8;
    }
    goto skip_2;
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
L_808002A8:
    // 0x808002A8: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B0: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x808002B4: jal         0x80089F48
    // 0x808002B8: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x808002B8: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    after_7:
    // 0x808002BC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x808002C0: sb          $v0, 0x17($t1)
    MEM_B(0X17, ctx->r9) = ctx->r2;
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002C8:
    // 0x808002C8: jal         0x80100094
    // 0x808002CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_8;
    // 0x808002CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808002D8: jal         0x80089F70
    // 0x808002DC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x808002DC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x808002E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002E4:
    // 0x808002E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002EC: jr          $ra
    // 0x808002F0: nop

    return;
    // 0x808002F0: nop

;}
RECOMP_FUNC void func_808011B4_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808011C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808011C4: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808011C8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x808011CC: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x808011D0: beq         $t7, $at, L_808011E8
    if (ctx->r15 == ctx->r1) {
        // 0x808011D4: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_808011E8;
    }
    // 0x808011D4: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x808011D8: beq         $t7, $at, L_808011E8
    if (ctx->r15 == ctx->r1) {
        // 0x808011DC: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_808011E8;
    }
    // 0x808011DC: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x808011E0: bne         $t7, $at, L_808011F8
    if (ctx->r15 != ctx->r1) {
        // 0x808011E4: nop
    
            goto L_808011F8;
    }
    // 0x808011E4: nop

L_808011E8:
    // 0x808011E8: jal         0x800DF440
    // 0x808011EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF440(rdram, ctx);
        goto after_0;
    // 0x808011EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x808011F0: b           L_80801200
    // 0x808011F4: nop

        goto L_80801200;
    // 0x808011F4: nop

L_808011F8:
    // 0x808011F8: jal         0x800DF440
    // 0x808011FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF440(rdram, ctx);
        goto after_1;
    // 0x808011FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_80801200:
    // 0x80801200: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80801204: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    // 0x80801208: jal         0x80101808
    // 0x8080120C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80101808(rdram, ctx);
        goto after_2;
    // 0x8080120C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801218: jr          $ra
    // 0x8080121C: nop

    return;
    // 0x8080121C: nop

;}
RECOMP_FUNC void func_808017AC_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808017B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808017B4: jal         0x80106790
    // 0x808017B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808017B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808017BC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808017C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808017C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808017C8: beq         $v1, $zero, L_808017E0
    if (ctx->r3 == 0) {
        // 0x808017CC: nop
    
            goto L_808017E0;
    }
    // 0x808017CC: nop

    // 0x808017D0: beq         $v1, $at, L_808017F0
    if (ctx->r3 == ctx->r1) {
        // 0x808017D4: nop
    
            goto L_808017F0;
    }
    // 0x808017D4: nop

    // 0x808017D8: b           L_808017FC
    // 0x808017DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808017FC;
    // 0x808017DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808017E0:
    // 0x808017E0: jal         0x80800B4C
    // 0x808017E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_1;
    // 0x808017E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808017E8: b           L_808017FC
    // 0x808017EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808017FC;
    // 0x808017EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808017F0:
    // 0x808017F0: jal         0x80800B4C
    // 0x808017F4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_2;
    // 0x808017F4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_2:
    // 0x808017F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808017FC:
    // 0x808017FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801800: jr          $ra
    // 0x80801804: nop

    return;
    // 0x80801804: nop

;}
RECOMP_FUNC void func_80800E6C_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E6C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800E70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E74: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800E78: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800E7C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800E80: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80800E84: jal         0x8001BBA0
    // 0x80800E88: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    rare_memcpy(rdram, ctx);
        goto after_0;
    // 0x80800E88: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_0:
    // 0x80800E8C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800E90: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800E94: jal         0x8001BBA0
    // 0x80800E98: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    rare_memcpy(rdram, ctx);
        goto after_1;
    // 0x80800E98: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_1:
    // 0x80800E9C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800EA0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80800EA4: jal         0x8001BBA0
    // 0x80800EA8: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    rare_memcpy(rdram, ctx);
        goto after_2;
    // 0x80800EA8: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_2:
    // 0x80800EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800EB4: jr          $ra
    // 0x80800EB8: nop

    return;
    // 0x80800EB8: nop

;}
RECOMP_FUNC void func_808005B8_chjigsawcollect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808005C0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1476, 0X6D0) << 16);
    // 0x808005C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808005CC: addiu       $t6, $t6, 0x6D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1476, 0X6D0));
    // 0x808005D0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808005D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808005D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808005DC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808005E0: jal         0x800BBCB8
    // 0x808005E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x808005E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x808005E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005F0: jr          $ra
    // 0x808005F4: nop

    return;
    // 0x808005F4: nop

;}
RECOMP_FUNC void _gccubesearch_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800882A8: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x800882A8);
    return;
    // 0x800882AC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void bsstonehead_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008B8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808008BC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(376, 0X1650) << 16);
    // 0x808008C0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808008C4: jr          $ra
    // 0x808008C8: lw          $v0, 0x1650($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X1650));
    return;
    // 0x808008C8: lw          $v0, 0x1650($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X1650));
;}
RECOMP_FUNC void func_800C7010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7010: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C7014: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C7018: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C701C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C7020: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800C7024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C7028:
    // 0x800C7028: jal         0x800C70B0
    // 0x800C702C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_0;
    // 0x800C702C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800C7030: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C7034: slti        $at, $s0, 0x3C
    ctx->r1 = SIGNED(ctx->r16) < 0X3C ? 1 : 0;
    // 0x800C7038: bnel        $at, $zero, L_800C7028
    if (ctx->r1 != 0) {
        // 0x800C703C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C7028;
    }
    goto skip_0;
    // 0x800C703C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800C7040: addiu       $s0, $zero, 0x3C
    ctx->r16 = ADD32(0, 0X3C);
    // 0x800C7044: addiu       $s1, $zero, 0x50
    ctx->r17 = ADD32(0, 0X50);
    // 0x800C7048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C704C:
    // 0x800C704C: jal         0x800C70D0
    // 0x800C7050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70D0(rdram, ctx);
        goto after_1;
    // 0x800C7050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800C7054: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C7058: bnel        $s0, $s1, L_800C704C
    if (ctx->r16 != ctx->r17) {
        // 0x800C705C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C704C;
    }
    goto skip_1;
    // 0x800C705C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x800C7060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7064: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C7068: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C706C: jr          $ra
    // 0x800C7070: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C7070: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800DFC60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFC60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DFC64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DFC68: jal         0x8001B084
    // 0x800DFC6C: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x800DFC6C: nop

    after_0:
    // 0x800DFC70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DFC74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DFC78: jr          $ra
    // 0x800DFC7C: nop

    return;
    // 0x800DFC7C: nop

;}
RECOMP_FUNC void func_8009CF98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CF98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009CF9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009CFA0: jal         0x8009C830
    // 0x8009CFA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    yaw_init(rdram, ctx);
        goto after_0;
    // 0x8009CFA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009CFA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009CFAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009CFB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009CFB4: lw          $t6, 0xFC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XFC);
    // 0x8009CFB8: swc1        $f4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f4.u32l;
    // 0x8009CFBC: lw          $t7, 0xFC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XFC);
    // 0x8009CFC0: jal         0x8009D2D8
    // 0x8009CFC4: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    func_8009D2D8(rdram, ctx);
        goto after_1;
    // 0x8009CFC4: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    after_1:
    // 0x8009CFC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009CFCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009CFD0: jr          $ra
    // 0x8009CFD4: nop

    return;
    // 0x8009CFD4: nop

;}
RECOMP_FUNC void func_80800AB8_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800ABC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800AC0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800AC4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800AC8: jal         0x80100094
    // 0x80800ACC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800ACC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800AD0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AD4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800AD8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800ADC: beq         $a3, $at, L_80800BDC
    if (ctx->r7 == ctx->r1) {
        // 0x80800AE0: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80800BDC;
    }
    // 0x80800AE0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800AE4: beq         $a3, $at, L_80800B38
    if (ctx->r7 == ctx->r1) {
        // 0x80800AE8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800B38;
    }
    // 0x80800AE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800AEC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800AF0: beq         $a3, $at, L_80800B0C
    if (ctx->r7 == ctx->r1) {
        // 0x80800AF4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800B0C;
    }
    // 0x80800AF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800AF8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800AFC: beq         $a3, $at, L_80800B28
    if (ctx->r7 == ctx->r1) {
        // 0x80800B00: nop
    
            goto L_80800B28;
    }
    // 0x80800B00: nop

    // 0x80800B04: b           L_80800BE0
    // 0x80800B08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_80800BE0;
    // 0x80800B08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800B0C:
    // 0x80800B0C: jal         0x801021BC
    // 0x80800B10: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_801021BC(rdram, ctx);
        goto after_1;
    // 0x80800B10: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_1:
    // 0x80800B14: beq         $v0, $zero, L_80800B24
    if (ctx->r2 == 0) {
        // 0x80800B18: addiu       $t6, $zero, 0xC
        ctx->r14 = ADD32(0, 0XC);
            goto L_80800B24;
    }
    // 0x80800B18: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80800B1C: b           L_80800BDC
    // 0x80800B20: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BDC;
    // 0x80800B20: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
L_80800B24:
    // 0x80800B24: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_80800B28:
    // 0x80800B28: jal         0x80800C6C
    // 0x80800B2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800C6C_chnicecavemen(rdram, ctx);
        goto after_2;
    // 0x80800B2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800B30: b           L_80800BDC
    // 0x80800B34: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BDC;
    // 0x80800B34: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
L_80800B38:
    // 0x80800B38: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80800B3C: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800B40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B44: srl         $t7, $v0, 7
    ctx->r15 = S32(U32(ctx->r2) >> 7);
    // 0x80800B48: beq         $t7, $at, L_80800B68
    if (ctx->r15 == ctx->r1) {
        // 0x80800B4C: addiu       $at, $zero, 0x33
        ctx->r1 = ADD32(0, 0X33);
            goto L_80800B68;
    }
    // 0x80800B4C: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80800B50: beq         $t7, $at, L_80800B70
    if (ctx->r15 == ctx->r1) {
        // 0x80800B54: addiu       $at, $zero, 0x34
        ctx->r1 = ADD32(0, 0X34);
            goto L_80800B70;
    }
    // 0x80800B54: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x80800B58: beql        $t7, $at, L_80800B7C
    if (ctx->r15 == ctx->r1) {
        // 0x80800B5C: addiu       $a1, $zero, 0x9
        ctx->r5 = ADD32(0, 0X9);
            goto L_80800B7C;
    }
    goto skip_0;
    // 0x80800B5C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    skip_0:
    // 0x80800B60: b           L_80800B7C
    // 0x80800B64: nop

        goto L_80800B7C;
    // 0x80800B64: nop

L_80800B68:
    // 0x80800B68: b           L_80800B7C
    // 0x80800B6C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
        goto L_80800B7C;
    // 0x80800B6C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
L_80800B70:
    // 0x80800B70: b           L_80800B7C
    // 0x80800B74: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
        goto L_80800B7C;
    // 0x80800B74: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80800B78: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_80800B7C:
    // 0x80800B7C: jal         0x80801508
    // 0x80800B80: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    func_80801508_chnicecavemen(rdram, ctx);
        goto after_3;
    // 0x80800B80: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_3:
    // 0x80800B84: jal         0x800F54E4
    // 0x80800B88: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80800B88: nop

    after_4:
    // 0x80800B8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B90: jal         0x800F7F98
    // 0x80800B94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_5;
    // 0x80800B94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800B98: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800B9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800BA0: addiu       $a2, $zero, 0x7E7
    ctx->r6 = ADD32(0, 0X7E7);
    // 0x80800BA4: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80800BA8: jal         0x8008A070
    // 0x80800BAC: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    _subaddiepalette_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800BAC: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_6:
    // 0x80800BB0: beq         $v0, $zero, L_80800BD8
    if (ctx->r2 == 0) {
        // 0x80800BB4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800BD8;
    }
    // 0x80800BB4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800BB8: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1096, 0X18E8) << 16);
    // 0x80800BBC: addiu       $t8, $t8, 0x18E8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1096, 0X18E8));
    // 0x80800BC0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800BC4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800BC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800BCC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800BD0: jal         0x800BBCB8
    // 0x80800BD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_7;
    // 0x80800BD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
L_80800BD8:
    // 0x80800BD8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
L_80800BDC:
    // 0x80800BDC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800BE0:
    // 0x80800BE0: jal         0x80102424
    // 0x80800BE4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800BE4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_8:
    // 0x80800BE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800BF0: jr          $ra
    // 0x80800BF4: nop

    return;
    // 0x80800BF4: nop

;}
RECOMP_FUNC void func_80092224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092224: lw          $t7, 0x50($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X50);
    // 0x80092228: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009222C: jr          $ra
    // 0x80092230: sb          $t6, 0x1A($t7)
    MEM_B(0X1A, ctx->r15) = ctx->r14;
    return;
    // 0x80092230: sb          $t6, 0x1A($t7)
    MEM_B(0X1A, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void func_80801E20_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801E24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801E28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801E2C: jal         0x80801980
    // 0x80801E30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801980_bstnt(rdram, ctx);
        goto after_0;
    // 0x80801E30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801E34: jal         0x80800E54
    // 0x80801E38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstnt_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80801E38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801E40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801E44: jr          $ra
    // 0x80801E48: nop

    return;
    // 0x80801E48: nop

;}
RECOMP_FUNC void func_8009AB78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AB78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009AB7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009AB80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009AB84: jal         0x800A3274
    // 0x8009AB88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x8009AB88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8009AB8C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009AB90: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8009AB94: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8009AB98: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8009AB9C: jal         0x8009E6EC
    // 0x8009ABA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_1;
    // 0x8009ABA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8009ABA4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8009ABA8: beq         $v0, $at, L_8009AC18
    if (ctx->r2 == ctx->r1) {
        // 0x8009ABAC: addiu       $t8, $zero, 0x3C
        ctx->r24 = ADD32(0, 0X3C);
            goto L_8009AC18;
    }
    // 0x8009ABAC: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8009ABB0: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8009ABB4: bne         $v0, $at, L_8009AC28
    if (ctx->r2 != ctx->r1) {
        // 0x8009ABB8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AC28;
    }
    // 0x8009ABB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009ABBC: jal         0x80095748
    // 0x8009ABC0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isFalse(rdram, ctx);
        goto after_2;
    // 0x8009ABC0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_2:
    // 0x8009ABC4: beq         $v0, $zero, L_8009AC40
    if (ctx->r2 == 0) {
        // 0x8009ABC8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AC40;
    }
    // 0x8009ABC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009ABCC: jal         0x800915AC
    // 0x8009ABD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastatetimer_isDone(rdram, ctx);
        goto after_3;
    // 0x8009ABD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8009ABD4: beql        $v0, $zero, L_8009AC44
    if (ctx->r2 == 0) {
        // 0x8009ABD8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AC44;
    }
    goto skip_0;
    // 0x8009ABD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8009ABDC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8009ABE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009ABE4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8009ABE8: beq         $v0, $at, L_8009ABFC
    if (ctx->r2 == ctx->r1) {
        // 0x8009ABEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009ABFC;
    }
    // 0x8009ABEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009ABF0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8009ABF4: bnel        $v0, $at, L_8009AC44
    if (ctx->r2 != ctx->r1) {
        // 0x8009ABF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AC44;
    }
    goto skip_1;
    // 0x8009ABF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_8009ABFC:
    // 0x8009ABFC: jal         0x8008E9AC
    // 0x8009AC00: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    func_8008E9AC(rdram, ctx);
        goto after_4;
    // 0x8009AC00: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    after_4:
    // 0x8009AC04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009AC08: jal         0x8008F6B8
    // 0x8009AC0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8008F6B8(rdram, ctx);
        goto after_5;
    // 0x8009AC0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8009AC10: b           L_8009AC44
    // 0x8009AC14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8009AC44;
    // 0x8009AC14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8009AC18:
    // 0x8009AC18: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8009AC1C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8009AC20: b           L_8009AC40
    // 0x8009AC24: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
        goto L_8009AC40;
    // 0x8009AC24: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
L_8009AC28:
    // 0x8009AC28: jal         0x80084D38
    // 0x8009AC2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bahold_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x8009AC2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8009AC30: jal         0x80099B94
    // 0x8009AC34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_7;
    // 0x8009AC34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8009AC38: b           L_8009AC5C
    // 0x8009AC3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009AC5C;
    // 0x8009AC3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009AC40:
    // 0x8009AC40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8009AC44:
    // 0x8009AC44: jal         0x8009E5C8
    // 0x8009AC48: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_8;
    // 0x8009AC48: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x8009AC4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009AC50: jal         0x8009E830
    // 0x8009AC54: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8009E830(rdram, ctx);
        goto after_9;
    // 0x8009AC54: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_9:
    // 0x8009AC58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009AC5C:
    // 0x8009AC5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009AC60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8009AC64: jr          $ra
    // 0x8009AC68: nop

    return;
    // 0x8009AC68: nop

;}
RECOMP_FUNC void bsvan_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E4C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800E50: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(427, 0X1CBC) << 16);
    // 0x80800E54: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800E58: jr          $ra
    // 0x80800E5C: lw          $v0, 0x1CBC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1CBC));
    return;
    // 0x80800E5C: lw          $v0, 0x1CBC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1CBC));
;}
RECOMP_FUNC void _susubgame_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A2D8: syscall     834
    recomp_syscall_handler(rdram, ctx, 0x8008A2D8);
    return;
    // 0x8008A2DC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _chhellterskelter_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E30: syscall     246
    recomp_syscall_handler(rdram, ctx, 0x80085E30);
    return;
    // 0x80085E34: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801088_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080108C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801090: jal         0x808006F0
    // 0x80801094: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstrexlarge_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801094: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801098: jal         0x800839C8
    // 0x8080109C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x8080109C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808010A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808010A8: jr          $ra
    // 0x808010AC: nop

    return;
    // 0x808010AC: nop

;}
RECOMP_FUNC void func_80800014_chkingjinjobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800018: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080001C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800020: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x80800024: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800028: addiu       $t9, $t8, -0x2
    ctx->r25 = ADD32(ctx->r24, -0X2);
    // 0x8080002C: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x80800030: beq         $at, $zero, L_8080028C
    if (ctx->r1 == 0) {
        // 0x80800034: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8080028C;
    }
    // 0x80800034: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800038: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1464, 0X9E0) << 16);
    // 0x8080003C: addu        $at, $at, $t9
    gpr jr_addend_80800044 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800040: lw          $t9, 0x9E0($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1464, 0X9E0));
    // 0x80800044: jr          $t9
    // 0x80800048: nop

    switch (jr_addend_80800044 >> 2) {
        case 0: goto L_8080004C; break;
        case 1: goto L_808000C0; break;
        case 2: goto L_80800128; break;
        case 3: goto L_8080015C; break;
        case 4: goto L_808001B8; break;
        case 5: goto L_80800208; break;
        default: switch_error(__func__, 0x80800044, 0x808009E0);
    }
    // 0x80800048: nop

L_8080004C:
    // 0x8080004C: jal         0x8010D23C
    // 0x80800050: nop

    func_8010D23C(rdram, ctx);
        goto after_0;
    // 0x80800050: nop

    after_0:
    // 0x80800054: beql        $v0, $zero, L_80800290
    if (ctx->r2 == 0) {
        // 0x80800058: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800290;
    }
    goto skip_0;
    // 0x80800058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080005C: jal         0x8010C500
    // 0x80800060: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8010C500(rdram, ctx);
        goto after_1;
    // 0x80800060: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800064: beql        $v0, $zero, L_80800290
    if (ctx->r2 == 0) {
        // 0x80800068: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800290;
    }
    goto skip_1;
    // 0x80800068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080006C: jal         0x800DA544
    // 0x80800070: addiu       $a0, $zero, 0x367
    ctx->r4 = ADD32(0, 0X367);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800070: addiu       $a0, $zero, 0x367
    ctx->r4 = ADD32(0, 0X367);
    after_2:
    // 0x80800074: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80800078: addiu       $t1, $zero, 0x97
    ctx->r9 = ADD32(0, 0X97);
    // 0x8080007C: addiu       $a1, $zero, 0x1537
    ctx->r5 = ADD32(0, 0X1537);
    // 0x80800080: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80800084: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800088: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x8080008C: jal         0x8008A208
    // 0x80800090: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80800090: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80800094: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80800098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080009C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x808000A0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x808000A4: jal         0x80085708
    // 0x808000A8: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x808000A8: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_4:
    // 0x808000AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000B0: jal         0x80101FDC
    // 0x808000B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x808000B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808000B8: b           L_80800290
    // 0x808000BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800290;
    // 0x808000BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000C0:
    // 0x808000C0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x808000C4: lw          $v0, 0x64($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X64);
    // 0x808000C8: sll         $t5, $v0, 12
    ctx->r13 = S32(ctx->r2 << 12);
    // 0x808000CC: bgez        $t5, L_8080028C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808000D0: sll         $t7, $v0, 11
        ctx->r15 = S32(ctx->r2 << 11);
            goto L_8080028C;
    }
    // 0x808000D0: sll         $t7, $v0, 11
    ctx->r15 = S32(ctx->r2 << 11);
    // 0x808000D4: bgezl       $t7, L_80800290
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808000D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800290;
    }
    goto skip_2;
    // 0x808000D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808000DC: jal         0x800F54E4
    // 0x808000E0: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x808000E0: nop

    after_6:
    // 0x808000E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000E8: jal         0x800F82D4
    // 0x808000EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_7;
    // 0x808000EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808000F0: jal         0x80085710
    // 0x808000F4: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_8;
    // 0x808000F4: nop

    after_8:
    // 0x808000F8: jal         0x800887A8
    // 0x808000FC: nop

    _glcutDll_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x808000FC: nop

    after_9:
    // 0x80800100: jal         0x800887E0
    // 0x80800104: addiu       $a0, $zero, 0x18E
    ctx->r4 = ADD32(0, 0X18E);
    _glcutDll_entrypoint_7(rdram, ctx);
        goto after_10;
    // 0x80800104: addiu       $a0, $zero, 0x18E
    ctx->r4 = ADD32(0, 0X18E);
    after_10:
    // 0x80800108: jal         0x80088858
    // 0x8080010C: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    _glcutDll_entrypoint_22(rdram, ctx);
        goto after_11;
    // 0x8080010C: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    after_11:
    // 0x80800110: jal         0x80088808
    // 0x80800114: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _glcutDll_entrypoint_12(rdram, ctx);
        goto after_12;
    // 0x80800114: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x80800118: jal         0x80088828
    // 0x8080011C: nop

    _glcutDll_entrypoint_16(rdram, ctx);
        goto after_13;
    // 0x8080011C: nop

    after_13:
    // 0x80800120: b           L_80800290
    // 0x80800124: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800290;
    // 0x80800124: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800128:
    // 0x80800128: jal         0x800DA298
    // 0x8080012C: addiu       $a0, $zero, 0x67A
    ctx->r4 = ADD32(0, 0X67A);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x8080012C: addiu       $a0, $zero, 0x67A
    ctx->r4 = ADD32(0, 0X67A);
    after_14:
    // 0x80800130: beq         $v0, $zero, L_8080028C
    if (ctx->r2 == 0) {
        // 0x80800134: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_8080028C;
    }
    // 0x80800134: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800138: jal         0x800BF744
    // 0x8080013C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_15;
    // 0x8080013C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800140: jal         0x800DA544
    // 0x80800144: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA544(rdram, ctx);
        goto after_16;
    // 0x80800144: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_16:
    // 0x80800148: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080014C: jal         0x80101FDC
    // 0x80800150: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_17;
    // 0x80800150: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_17:
    // 0x80800154: b           L_80800290
    // 0x80800158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800290;
    // 0x80800158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080015C:
    // 0x8080015C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800160: jal         0x800D9078
    // 0x80800164: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_18;
    // 0x80800164: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_18:
    // 0x80800168: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080016C: jal         0x800BEA88
    // 0x80800170: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_19;
    // 0x80800170: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
    // 0x80800174: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800178: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8080017C: addiu       $a2, $a2, 0x6798
    ctx->r6 = ADD32(ctx->r6, 0X6798);
    // 0x80800180: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800184: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800188: jal         0x80088660
    // 0x8080018C: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_20;
    // 0x8080018C: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    after_20:
    // 0x80800190: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800194: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800198: beql        $t9, $zero, L_80800290
    if (ctx->r25 == 0) {
        // 0x8080019C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800290;
    }
    goto skip_3;
    // 0x8080019C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x808001A0: jal         0x800BF744
    // 0x808001A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_21;
    // 0x808001A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x808001A8: jal         0x800FFAB0
    // 0x808001AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800FFAB0(rdram, ctx);
        goto after_22;
    // 0x808001AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_22:
    // 0x808001B0: b           L_80800290
    // 0x808001B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800290;
    // 0x808001B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001B8:
    // 0x808001B8: jal         0x800DA298
    // 0x808001BC: addiu       $a0, $zero, 0x67B
    ctx->r4 = ADD32(0, 0X67B);
    func_800DA298(rdram, ctx);
        goto after_23;
    // 0x808001BC: addiu       $a0, $zero, 0x67B
    ctx->r4 = ADD32(0, 0X67B);
    after_23:
    // 0x808001C0: beq         $v0, $zero, L_808001DC
    if (ctx->r2 == 0) {
        // 0x808001C4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808001DC;
    }
    // 0x808001C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001C8: jal         0x80101FDC
    // 0x808001CC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80101FDC(rdram, ctx);
        goto after_24;
    // 0x808001CC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_24:
    // 0x808001D0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808001D4: jal         0x800BF744
    // 0x808001D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_25;
    // 0x808001D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
L_808001DC:
    // 0x808001DC: jal         0x800BEA88
    // 0x808001E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_26;
    // 0x808001E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_26:
    // 0x808001E4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x808001E8: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x808001EC: addiu       $a2, $a2, 0x6798
    ctx->r6 = ADD32(ctx->r6, 0X6798);
    // 0x808001F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001F8: jal         0x80088660
    // 0x808001FC: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_27;
    // 0x808001FC: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    after_27:
    // 0x80800200: b           L_80800290
    // 0x80800204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800290;
    // 0x80800204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800208:
    // 0x80800208: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080020C: jal         0x800D9078
    // 0x80800210: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_28;
    // 0x80800210: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_28:
    // 0x80800214: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800218: jal         0x800BEA88
    // 0x8080021C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_29;
    // 0x8080021C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_29:
    // 0x80800220: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80800224: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800228: addiu       $a2, $a2, 0x6798
    ctx->r6 = ADD32(ctx->r6, 0X6798);
    // 0x8080022C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800230: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800234: jal         0x80088660
    // 0x80800238: lw          $a3, 0x0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_30;
    // 0x80800238: lw          $a3, 0x0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X0);
    after_30:
    // 0x8080023C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80800240: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800244: beql        $t2, $zero, L_80800290
    if (ctx->r10 == 0) {
        // 0x80800248: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800290;
    }
    goto skip_4;
    // 0x80800248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8080024C: jal         0x800BF744
    // 0x80800250: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_31;
    // 0x80800250: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x80800254: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800258: jal         0x800BF744
    // 0x8080025C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_32;
    // 0x8080025C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x80800260: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800264: jal         0x800BF744
    // 0x80800268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_33;
    // 0x80800268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x8080026C: jal         0x800DA524
    // 0x80800270: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA524(rdram, ctx);
        goto after_34;
    // 0x80800270: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_34:
    // 0x80800274: jal         0x800DA544
    // 0x80800278: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA544(rdram, ctx);
        goto after_35;
    // 0x80800278: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_35:
    // 0x8080027C: jal         0x800DA524
    // 0x80800280: addiu       $a0, $zero, 0x1A5
    ctx->r4 = ADD32(0, 0X1A5);
    func_800DA524(rdram, ctx);
        goto after_36;
    // 0x80800280: addiu       $a0, $zero, 0x1A5
    ctx->r4 = ADD32(0, 0X1A5);
    after_36:
    // 0x80800284: jal         0x800FFAB0
    // 0x80800288: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800FFAB0(rdram, ctx);
        goto after_37;
    // 0x80800288: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_37:
L_8080028C:
    // 0x8080028C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800290:
    // 0x80800290: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800294: jr          $ra
    // 0x80800298: nop

    return;
    // 0x80800298: nop

;}
RECOMP_FUNC void bsbwhirl_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D30: jal         0x8080017C
    // 0x80800D34: nop

    func_8080017C_bsbwhirl(rdram, ctx);
        goto after_0;
    // 0x80800D34: nop

    after_0:
    // 0x80800D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D40: jr          $ra
    // 0x80800D44: nop

    return;
    // 0x80800D44: nop

;}
RECOMP_FUNC void func_80803388_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803388: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080338C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80803390: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80803394: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80803398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080339C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808033A0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808033A4: jal         0x800EE7F8
    // 0x808033A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808033A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808033AC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808033B0: jal         0x800EE7F8
    // 0x808033B4: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808033B4: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x808033B8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808033BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808033C0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808033C4: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808033C8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x808033CC: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808033D0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808033D4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808033D8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x808033DC: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x808033E0: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x808033E4: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x808033E8: jal         0x800C6A7C
    // 0x808033EC: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    func_800C6A7C(rdram, ctx);
        goto after_2;
    // 0x808033EC: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    after_2:
    // 0x808033F0: beql        $v0, $zero, L_8080340C
    if (ctx->r2 == 0) {
        // 0x808033F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080340C;
    }
    goto skip_0;
    // 0x808033F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808033F8: jal         0x800C84B0
    // 0x808033FC: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    func_800C84B0(rdram, ctx);
        goto after_3;
    // 0x808033FC: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    after_3:
    // 0x80803400: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80803404: sw          $v0, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->r2;
    // 0x80803408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080340C:
    // 0x8080340C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80803410: jr          $ra
    // 0x80803414: nop

    return;
    // 0x80803414: nop

;}
RECOMP_FUNC void gcstatusDll_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80800110: jr          $ra
    // 0x80800114: lbu         $v0, -0x4BFC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4BFC);
    return;
    // 0x80800114: lbu         $v0, -0x4BFC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4BFC);
;}
RECOMP_FUNC void _bsjig_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083220: syscall     51
    recomp_syscall_handler(rdram, ctx, 0x80083220);
    return;
    // 0x80083224: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80081E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081E30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80081E34: sdc1        $f0, 0x0($sp)
    CHECK_FR(ctx, 0);
    SD(ctx->f0.u64, 0X0, ctx->r29);
    // 0x80081E38: sdc1        $f2, 0x8($sp)
    CHECK_FR(ctx, 2);
    SD(ctx->f2.u64, 0X8, ctx->r29);
    // 0x80081E3C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80081E40: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x80081E44: lw          $t0, 0x0($ra)
    ctx->r8 = MEM_W(ctx->r31, 0X0);
    // 0x80081E48: addiu       $a0, $ra, -0x20
    ctx->r4 = ADD32(ctx->r31, -0X20);
    // 0x80081E4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80081E50: jal         0x800819E4
    // 0x80081E54: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    ovl_unload(rdram, ctx);
        goto after_0;
    // 0x80081E54: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_0:
    // 0x80081E58: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80081E5C: ldc1        $f0, 0x0($sp)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r29, 0X0);
    // 0x80081E60: ldc1        $f2, 0x8($sp)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r29, 0X8);
    // 0x80081E64: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80081E68: lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X14);
    // 0x80081E6C: jr          $ra
    // 0x80081E70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80081E70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void gczoombox_entrypoint_34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808038C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808038C8: beq         $a0, $zero, L_808038F0
    if (ctx->r4 == 0) {
        // 0x808038CC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808038F0;
    }
    // 0x808038CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808038D0: lbu         $v0, 0x171($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X171);
    // 0x808038D4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808038D8: beq         $v0, $zero, L_808038F0
    if (ctx->r2 == 0) {
        // 0x808038DC: nop
    
            goto L_808038F0;
    }
    // 0x808038DC: nop

    // 0x808038E0: beq         $v0, $at, L_808038F0
    if (ctx->r2 == ctx->r1) {
        // 0x808038E4: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_808038F0;
    }
    // 0x808038E4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x808038E8: bne         $v0, $at, L_808038F8
    if (ctx->r2 != ctx->r1) {
        // 0x808038EC: nop
    
            goto L_808038F8;
    }
    // 0x808038EC: nop

L_808038F0:
    // 0x808038F0: b           L_80803914
    // 0x808038F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803914;
    // 0x808038F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808038F8:
    // 0x808038F8: jal         0x80803390
    // 0x808038FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gczoombox_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x808038FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80803900: jal         0x808033C0
    // 0x80803904: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gczoombox_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80803904: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80803908: jal         0x808004D0
    // 0x8080390C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808004D0_gczoombox(rdram, ctx);
        goto after_2;
    // 0x8080390C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80803910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803914:
    // 0x80803914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080391C: jr          $ra
    // 0x80803920: nop

    return;
    // 0x80803920: nop

;}
RECOMP_FUNC void _ncbajig_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089300: syscall     772
    recomp_syscall_handler(rdram, ctx, 0x80089300);
    return;
    // 0x80089304: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chbottlesfamily_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800864D0: syscall     331
    recomp_syscall_handler(rdram, ctx, 0x800864D0);
    return;
    // 0x800864D4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
