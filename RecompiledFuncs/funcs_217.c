#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800F34_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800F38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800F40: jal         0x800A89F8
    // 0x80800F44: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x80800F44: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800F48: jal         0x800A9478
    // 0x80800F4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A9478(rdram, ctx);
        goto after_1;
    // 0x80800F4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800F50: jal         0x800F5EF8
    // 0x80800F54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_2;
    // 0x80800F54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800F58: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800F5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800F60: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800F64: sb          $t6, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = ctx->r14;
    // 0x80800F68: sh          $zero, 0x50($v1)
    MEM_H(0X50, ctx->r3) = 0;
    // 0x80800F6C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800F70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F74: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    // 0x80800F78: addiu       $a3, $zero, 0x804
    ctx->r7 = ADD32(0, 0X804);
    // 0x80800F7C: jal         0x80089540
    // 0x80800F80: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    _ncpod_entrypoint_16(rdram, ctx);
        goto after_3;
    // 0x80800F80: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    after_3:
    // 0x80800F84: jal         0x80110024
    // 0x80800F88: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80110024(rdram, ctx);
        goto after_4;
    // 0x80800F88: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x80800F8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F90: jal         0x80089520
    // 0x80800F94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _ncpod_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x80800F94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800F98: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800F9C: jal         0x80801170
    // 0x80800FA0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80801170_chquiz(rdram, ctx);
        goto after_6;
    // 0x80800FA0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80800FA4: jal         0x8010FD88
    // 0x80800FA8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8010FD88(rdram, ctx);
        goto after_7;
    // 0x80800FA8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_7:
    // 0x80800FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800FB4: jr          $ra
    // 0x80800FB8: nop

    return;
    // 0x80800FB8: nop

;}
RECOMP_FUNC void vpscroll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    // 0x80800010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800014: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80800018: jal         0x8001ACCC
    // 0x8080001C: addiu       $a0, $t7, 0x10
    ctx->r4 = ADD32(ctx->r15, 0X10);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a0, $t7, 0x10
    ctx->r4 = ADD32(ctx->r15, 0X10);
    after_0:
    // 0x80800020: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800028: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080002C: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x80800030: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80800034: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80800038: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8080003C: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x80800040: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80800044: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80800048: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x8080004C: mfhi        $t2
    ctx->r10 = hi;
    // 0x80800050: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80800054: addu        $a1, $t0, $a2
    ctx->r5 = ADD32(ctx->r8, ctx->r6);
    // 0x80800058: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    // 0x8080005C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800060: addiu       $a0, $a2, 0x14
    ctx->r4 = ADD32(ctx->r6, 0X14);
    // 0x80800064: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80800068: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8080006C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80800070: beq         $at, $zero, L_808000B8
    if (ctx->r1 == 0) {
        // 0x80800074: swc1        $f8, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
            goto L_808000B8;
    }
    // 0x80800074: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80800078: lhu         $t3, 0x2($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X2);
L_8080007C:
    // 0x8080007C: beql        $t3, $zero, L_808000AC
    if (ctx->r11 == 0) {
        // 0x80800080: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_808000AC;
    }
    goto skip_0;
    // 0x80800080: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_0:
    // 0x80800084: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80800088: subu        $t4, $v1, $a0
    ctx->r12 = SUB32(ctx->r3, ctx->r4);
    // 0x8080008C: sra         $t5, $t4, 2
    ctx->r13 = S32(SIGNED(ctx->r12) >> 2);
    // 0x80800090: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80800094: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80800098: sh          $t5, 0x10($t8)
    MEM_H(0X10, ctx->r24) = ctx->r13;
    // 0x8080009C: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x808000A0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x808000A4: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
    // 0x808000A8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_808000AC:
    // 0x808000AC: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x808000B0: bnel        $at, $zero, L_8080007C
    if (ctx->r1 != 0) {
        // 0x808000B4: lhu         $t3, 0x2($v1)
        ctx->r11 = MEM_HU(ctx->r3, 0X2);
            goto L_8080007C;
    }
    goto skip_1;
    // 0x808000B4: lhu         $t3, 0x2($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X2);
    skip_1:
L_808000B8:
    // 0x808000B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000C0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x808000C4: jr          $ra
    // 0x808000C8: nop

    return;
    // 0x808000C8: nop

;}
RECOMP_FUNC void func_800BEC1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEC1C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BEC20: jr          $ra
    // 0x800BEC24: lw          $v0, -0x78D4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X78D4);
    return;
    // 0x800BEC24: lw          $v0, -0x78D4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X78D4);
;}
RECOMP_FUNC void func_80115864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115864: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80115868: jr          $ra
    // 0x8011586C: sb          $a1, 0x1C($t6)
    MEM_B(0X1C, ctx->r14) = ctx->r5;
    return;
    // 0x8011586C: sb          $a1, 0x1C($t6)
    MEM_B(0X1C, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_8080105C_chfiregen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080105C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801064: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80801068: addiu       $at, $zero, 0x2AA
    ctx->r1 = ADD32(0, 0X2AA);
    // 0x8080106C: addiu       $t8, $zero, 0x1AD
    ctx->r24 = ADD32(0, 0X1AD);
    // 0x80801070: sll         $t6, $v0, 11
    ctx->r14 = S32(ctx->r2 << 11);
    // 0x80801074: srl         $t7, $t6, 20
    ctx->r15 = S32(U32(ctx->r14) >> 20);
    // 0x80801078: beq         $t7, $at, L_80801090
    if (ctx->r15 == ctx->r1) {
        // 0x8080107C: addiu       $at, $zero, 0x2AB
        ctx->r1 = ADD32(0, 0X2AB);
            goto L_80801090;
    }
    // 0x8080107C: addiu       $at, $zero, 0x2AB
    ctx->r1 = ADD32(0, 0X2AB);
    // 0x80801080: beq         $t7, $at, L_80801098
    if (ctx->r15 == ctx->r1) {
        // 0x80801084: addiu       $t9, $zero, 0x1AE
        ctx->r25 = ADD32(0, 0X1AE);
            goto L_80801098;
    }
    // 0x80801084: addiu       $t9, $zero, 0x1AE
    ctx->r25 = ADD32(0, 0X1AE);
    // 0x80801088: b           L_8080109C
    // 0x8080108C: nop

        goto L_8080109C;
    // 0x8080108C: nop

L_80801090:
    // 0x80801090: b           L_8080109C
    // 0x80801094: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
        goto L_8080109C;
    // 0x80801094: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_80801098:
    // 0x80801098: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_8080109C:
    // 0x8080109C: jal         0x80088F08
    // 0x808010A0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _idworld_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808010A0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x808010A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808010AC: jr          $ra
    // 0x808010B0: nop

    return;
    // 0x808010B0: nop

;}
RECOMP_FUNC void func_8080193C_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080193C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801940: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801944: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801948: jal         0x80100094
    // 0x8080194C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080194C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801950: bne         $v0, $zero, L_80801984
    if (ctx->r2 != 0) {
        // 0x80801954: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80801984;
    }
    // 0x80801954: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801958: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080195C: jal         0x800897C0
    // 0x80801960: addiu       $a2, $zero, 0xB7
    ctx->r6 = ADD32(0, 0XB7);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80801960: addiu       $a2, $zero, 0xB7
    ctx->r6 = ADD32(0, 0XB7);
    after_1:
    // 0x80801964: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801968: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080196C: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80801970: jal         0x800897E8
    // 0x80801974: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80801974: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_2:
    // 0x80801978: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080197C: jal         0x80089810
    // 0x80801980: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_3;
    // 0x80801980: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_3:
L_80801984:
    // 0x80801984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801988: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080198C: jr          $ra
    // 0x80801990: nop

    return;
    // 0x80801990: nop

;}
RECOMP_FUNC void _baflameline_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B78: syscall     130
    recomp_syscall_handler(rdram, ctx, 0x80084B78);
    return;
    // 0x80084B7C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800D7C_chexploder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D7C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800D80: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80800D84: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80800D88: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80800D8C: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80800D90: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80800D94: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80800D98: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80800D9C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80800DA0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80800DA4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800DA8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800DAC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800DB0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800DB4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800DB8: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80800DBC: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x80800DC0: jal         0x80100094
    // 0x80800DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800DC8: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x80800DCC: jal         0x801039E4
    // 0x80800DD0: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    func_801039E4(rdram, ctx);
        goto after_1;
    // 0x80800DD0: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    after_1:
    // 0x80800DD4: jal         0x800B27E0
    // 0x80800DD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27E0(rdram, ctx);
        goto after_2;
    // 0x80800DD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800DDC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800DE0: jal         0x80087A08
    // 0x80800DE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _dbskeleton_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800DE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800DE8: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x80800DEC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80800DF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800DF4: sh          $v0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r2;
    // 0x80800DF8: lh          $a2, 0xE($v1)
    ctx->r6 = MEM_H(ctx->r3, 0XE);
    // 0x80800DFC: sll         $t6, $a2, 4
    ctx->r14 = S32(ctx->r6 << 4);
    // 0x80800E00: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80800E04: jal         0x80100074
    // 0x80800E08: sll         $a2, $t6, 2
    ctx->r6 = S32(ctx->r14 << 2);
    func_80100074(rdram, ctx);
        goto after_4;
    // 0x80800E08: sll         $a2, $t6, 2
    ctx->r6 = S32(ctx->r14 << 2);
    after_4:
    // 0x80800E0C: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x80800E10: lw          $s7, 0x94($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X94);
    // 0x80800E14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800E18: lh          $t8, 0xE($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XE);
    // 0x80800E1C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800E20: addiu       $s6, $fp, 0x4
    ctx->r22 = ADD32(ctx->r30, 0X4);
    // 0x80800E24: blez        $t8, L_80800F24
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80800E28: andi        $t9, $s7, 0x10
        ctx->r25 = ctx->r23 & 0X10;
            goto L_80800F24;
    }
    // 0x80800E28: andi        $t9, $s7, 0x10
    ctx->r25 = ctx->r23 & 0X10;
    // 0x80800E2C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800E30: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800E34: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800E38: or          $s7, $t9, $zero
    ctx->r23 = ctx->r25 | 0;
    // 0x80800E3C: addiu       $s4, $sp, 0x6C
    ctx->r20 = ADD32(ctx->r29, 0X6C);
    // 0x80800E40: addiu       $s3, $sp, 0x60
    ctx->r19 = ADD32(ctx->r29, 0X60);
    // 0x80800E44: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80800E48:
    // 0x80800E48: jal         0x80087A28
    // 0x80800E4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _dbskeleton_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800E4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x80800E50: addiu       $s1, $s0, 0xC
    ctx->r17 = ADD32(ctx->r16, 0XC);
    // 0x80800E54: sb          $v0, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r2;
    // 0x80800E58: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800E5C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800E60: jal         0x80087A18
    // 0x80800E64: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    _dbskeleton_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800E64: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_6:
    // 0x80800E68: jal         0x800EFD24
    // 0x80800E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFD24(rdram, ctx);
        goto after_7;
    // 0x80800E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800E70: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800E74: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800E78: jal         0x800EE780
    // 0x80800E7C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_800EE780(rdram, ctx);
        goto after_8;
    // 0x80800E7C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_8:
    // 0x80800E80: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x80800E84: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800E88: jal         0x800F18FC
    // 0x80800E8C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800F18FC(rdram, ctx);
        goto after_9;
    // 0x80800E8C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_9:
    // 0x80800E90: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800E94: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800E98: jal         0x800EEBF0
    // 0x80800E9C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EEBF0(rdram, ctx);
        goto after_10;
    // 0x80800E9C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_10:
    // 0x80800EA0: swc1        $f20, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f20.u32l;
    // 0x80800EA4: lwc1        $f4, 0x48($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X48);
    // 0x80800EA8: swc1        $f20, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f20.u32l;
    // 0x80800EAC: beq         $s7, $zero, L_80800EC0
    if (ctx->r23 == 0) {
        // 0x80800EB0: swc1        $f4, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
            goto L_80800EC0;
    }
    // 0x80800EB0: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x80800EB4: lbu         $t1, 0x36($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X36);
    // 0x80800EB8: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x80800EBC: sb          $t2, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r10;
L_80800EC0:
    // 0x80800EC0: lbu         $t3, 0x39($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X39);
    // 0x80800EC4: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x80800EC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800ECC: bne         $t3, $at, L_80800EFC
    if (ctx->r11 != ctx->r1) {
        // 0x80800ED0: andi        $t4, $v0, 0x20
        ctx->r12 = ctx->r2 & 0X20;
            goto L_80800EFC;
    }
    // 0x80800ED0: andi        $t4, $v0, 0x20
    ctx->r12 = ctx->r2 & 0X20;
    // 0x80800ED4: beql        $t4, $zero, L_80800EF0
    if (ctx->r12 == 0) {
        // 0x80800ED8: lbu         $t8, 0x36($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X36);
            goto L_80800EF0;
    }
    goto skip_0;
    // 0x80800ED8: lbu         $t8, 0x36($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X36);
    skip_0:
    // 0x80800EDC: lbu         $t6, 0x36($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X36);
    // 0x80800EE0: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x80800EE4: b           L_80800F08
    // 0x80800EE8: sb          $t7, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r15;
        goto L_80800F08;
    // 0x80800EE8: sb          $t7, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r15;
    // 0x80800EEC: lbu         $t8, 0x36($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X36);
L_80800EF0:
    // 0x80800EF0: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x80800EF4: b           L_80800F08
    // 0x80800EF8: sb          $t9, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r25;
        goto L_80800F08;
    // 0x80800EF8: sb          $t9, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r25;
L_80800EFC:
    // 0x80800EFC: lbu         $t1, 0x36($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X36);
    // 0x80800F00: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x80800F04: sb          $t2, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r10;
L_80800F08:
    // 0x80800F08: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x80800F0C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800F10: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x80800F14: lh          $t4, 0xE($t3)
    ctx->r12 = MEM_H(ctx->r11, 0XE);
    // 0x80800F18: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80800F1C: bnel        $at, $zero, L_80800E48
    if (ctx->r1 != 0) {
        // 0x80800F20: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80800E48;
    }
    goto skip_1;
    // 0x80800F20: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_1:
L_80800F24:
    // 0x80800F24: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1392, 0X1AD4) << 16);
    // 0x80800F28: lwc1        $f6, 0x1AD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1392, 0X1AD4));
    // 0x80800F2C: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x80800F30: addiu       $a0, $fp, 0x44
    ctx->r4 = ADD32(ctx->r30, 0X44);
    // 0x80800F34: jal         0x800EFD24
    // 0x80800F38: swc1        $f6, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f6.u32l;
    func_800EFD24(rdram, ctx);
        goto after_11;
    // 0x80800F38: swc1        $f6, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f6.u32l;
    after_11:
    // 0x80800F3C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80800F40: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800F44: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800F48: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800F4C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F50: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80800F54: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80800F58: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80800F5C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80800F60: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80800F64: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80800F68: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80800F6C: jr          $ra
    // 0x80800F70: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80800F70: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80800064_chdinocoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800068: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080006C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800070: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800074: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800078: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8080007C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800080: beq         $t6, $at, L_80800148
    if (ctx->r14 == ctx->r1) {
        // 0x80800084: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800148;
    }
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800088: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8080008C: beq         $t6, $at, L_808000A4
    if (ctx->r14 == ctx->r1) {
        // 0x80800090: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_808000A4;
    }
    // 0x80800090: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80800094: beq         $t6, $at, L_808000D8
    if (ctx->r14 == ctx->r1) {
        // 0x80800098: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D8;
    }
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080009C: b           L_80800178
    // 0x808000A0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
        goto L_80800178;
    // 0x808000A0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
L_808000A4:
    // 0x808000A4: jal         0x8010CD28
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_0;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808000AC: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808000B0: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808000B4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    // 0x808000C0: jal         0x80102BF8
    // 0x808000C4: lui         $a3, 0x43C8
    ctx->r7 = S32(0X43C8 << 16);
    func_80102BF8(rdram, ctx);
        goto after_1;
    // 0x808000C4: lui         $a3, 0x43C8
    ctx->r7 = S32(0X43C8 << 16);
    after_1:
    // 0x808000C8: jal         0x8008A1A8
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_22(rdram, ctx);
        goto after_2;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000D0: b           L_808001AC
    // 0x808000D4: nop

        goto L_808001AC;
    // 0x808000D4: nop

L_808000D8:
    // 0x808000D8: jal         0x800D8FF8
    // 0x808000DC: nop

    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x808000DC: nop

    after_3:
    // 0x808000E0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808000E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000E8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808000EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000F0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808000F4: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808000F8: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808000FC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800100: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x80800104: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800108: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8080010C: jal         0x800F1FF0
    // 0x80800110: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_4;
    // 0x80800110: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x80800114: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80800118: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080011C: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800120: jal         0x800F20BC
    // 0x80800124: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    func_800F20BC(rdram, ctx);
        goto after_5;
    // 0x80800124: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_5:
    // 0x80800128: beq         $v0, $zero, L_80800138
    if (ctx->r2 == 0) {
        // 0x8080012C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800138;
    }
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: jal         0x8008A148
    // 0x80800134: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80800134: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
L_80800138:
    // 0x80800138: jal         0x8008A1A8
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_22(rdram, ctx);
        goto after_7;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800140: b           L_808001AC
    // 0x80800144: nop

        goto L_808001AC;
    // 0x80800144: nop

L_80800148:
    // 0x80800148: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x8080014C: jal         0x80101E14
    // 0x80800150: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_8;
    // 0x80800150: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_8:
    // 0x80800154: beq         $v0, $zero, L_80800168
    if (ctx->r2 == 0) {
        // 0x80800158: lui         $at, 0x4448
        ctx->r1 = S32(0X4448 << 16);
            goto L_80800168;
    }
    // 0x80800158: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x8080015C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800160: nop

    // 0x80800164: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
L_80800168:
    // 0x80800168: jal         0x8008A108
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800170: b           L_808001AC
    // 0x80800174: nop

        goto L_808001AC;
    // 0x80800174: nop

L_80800178:
    // 0x80800178: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1072, 0X528) << 16);
    // 0x8080017C: jal         0x8008A1E8
    // 0x80800180: addiu       $a2, $a2, 0x528
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1072, 0X528));
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_10;
    // 0x80800180: addiu       $a2, $a2, 0x528
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1072, 0X528));
    after_10:
    // 0x80800184: bnel        $v0, $zero, L_808001A0
    if (ctx->r2 != 0) {
        // 0x80800188: lwc1        $f18, 0x48($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
            goto L_808001A0;
    }
    goto skip_0;
    // 0x80800188: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    skip_0:
    // 0x8080018C: jal         0x8008A108
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800194: b           L_808001AC
    // 0x80800198: nop

        goto L_808001AC;
    // 0x80800198: nop

    // 0x8080019C: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
L_808001A0:
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: jal         0x8010A570
    // 0x808001A8: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    func_8010A570(rdram, ctx);
        goto after_12;
    // 0x808001A8: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    after_12:
L_808001AC:
    // 0x808001AC: jal         0x808002CC
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002CC_chdinocoaster(rdram, ctx);
        goto after_13;
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001C0: jr          $ra
    // 0x808001C4: nop

    return;
    // 0x808001C4: nop

;}
RECOMP_FUNC void func_8080000C_chnewshovel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x80100094
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800028: jal         0x80089F70
    // 0x8080002C: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800034: jal         0x808007F8
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808007F8_chnewshovel(rdram, ctx);
        goto after_2;
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800044: jr          $ra
    // 0x80800048: nop

    return;
    // 0x80800048: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B0: jal         0x80800000
    // 0x808000B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x808000B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000B8: bne         $v0, $zero, L_808000C8
    if (ctx->r2 != 0) {
        // 0x808000BC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_808000C8;
    }
    // 0x808000BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808000C0: b           L_808000D4
    // 0x808000C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000D4;
    // 0x808000C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000C8:
    // 0x808000C8: jal         0x800EE7F8
    // 0x808000CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808000CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808000D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000D4:
    // 0x808000D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000DC: jr          $ra
    // 0x808000E0: nop

    return;
    // 0x808000E0: nop

;}
RECOMP_FUNC void func_80801B90_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801B94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801B98: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x80801B9C: sb          $t6, 0x171($a0)
    MEM_B(0X171, ctx->r4) = ctx->r14;
    // 0x80801BA0: jal         0x80803420
    // 0x80801BA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gczoombox_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x80801BA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801BA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801BAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801BB0: nop

    // 0x80801BB4: swc1        $f4, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->f4.u32l;
    // 0x80801BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801BBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801BC0: jr          $ra
    // 0x80801BC4: nop

    return;
    // 0x80801BC4: nop

;}
RECOMP_FUNC void _baduo_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084960: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x80084960);
    return;
    // 0x80084964: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_808003EC_chbadjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003EC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808003F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003FC: jal         0x80100094
    // 0x80800400: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800400: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800404: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800408: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8080040C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800410: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800414: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800418: nop

    // 0x8080041C: bc1fl       L_80800444
    if (!c1cs) {
        // 0x80800420: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_80800444;
    }
    goto skip_0;
    // 0x80800420: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_0:
    // 0x80800424: jal         0x800D8FF8
    // 0x80800428: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800428: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8080042C: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80800430: lwc1        $f8, 0x1C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80800434: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800438: b           L_80800588
    // 0x8080043C: swc1        $f10, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f10.u32l;
        goto L_80800588;
    // 0x8080043C: swc1        $f10, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f10.u32l;
    // 0x80800440: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_80800444:
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800448: jal         0x8010CD28
    // 0x8080044C: swc1        $f16, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f16.u32l;
    func_8010CD28(rdram, ctx);
        goto after_2;
    // 0x8080044C: swc1        $f16, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f16.u32l;
    after_2:
    // 0x80800450: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800454: jal         0x800F2094
    // 0x80800458: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F2094(rdram, ctx);
        goto after_3;
    // 0x80800458: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_3:
    // 0x8080045C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800460: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800464: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800468: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x8080046C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80800470: nop

    // 0x80800474: bc1tl       L_8080058C
    if (c1cs) {
        // 0x80800478: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080058C;
    }
    goto skip_1;
    // 0x80800478: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080047C: jal         0x8010C9B0
    // 0x80800480: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_8010C9B0(rdram, ctx);
        goto after_4;
    // 0x80800480: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_4:
    // 0x80800484: beq         $v0, $zero, L_8080051C
    if (ctx->r2 == 0) {
        // 0x80800488: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080051C;
    }
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800490: jal         0x80100094
    // 0x80800494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x80800494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800498: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1576, 0X1330) << 16);
    // 0x8080049C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x808004A0: addiu       $t6, $t6, 0x1330
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1576, 0X1330));
    // 0x808004A4: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x808004A8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808004AC: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x808004B0: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x808004B4: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x808004B8: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x808004BC: sw          $at, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r1;
    // 0x808004C0: jal         0x800EF04C
    // 0x808004C4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x808004C4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x808004C8: jal         0x8010CD28
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_7;
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808004D0: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x808004D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004D8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808004DC: jal         0x8080010C
    // 0x808004E0: lbu         $a2, 0x24($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X24);
    func_8080010C_chbadjinjo(rdram, ctx);
        goto after_8;
    // 0x808004E0: lbu         $a2, 0x24($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X24);
    after_8:
    // 0x808004E4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1576, 0X12D0) << 16);
    // 0x808004E8: addiu       $a1, $a1, 0x12D0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1576, 0X12D0));
    // 0x808004EC: jal         0x80801090
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801090_chbadjinjo(rdram, ctx);
        goto after_9;
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808004F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808004F8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800500: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800504: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800508: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8080050C: jal         0x80800E28
    // 0x80800510: swc1        $f0, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f0.u32l;
    func_80800E28_chbadjinjo(rdram, ctx);
        goto after_10;
    // 0x80800510: swc1        $f0, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f0.u32l;
    after_10:
    // 0x80800514: b           L_8080058C
    // 0x80800518: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080058C;
    // 0x80800518: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080051C:
    // 0x8080051C: jal         0x80100094
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800524: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1576, 0X133C) << 16);
    // 0x80800528: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8080052C: addiu       $t2, $t2, 0x133C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1576, 0X133C));
    // 0x80800530: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80800534: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800538: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x8080053C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80800540: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x80800544: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x80800548: sw          $at, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r1;
    // 0x8080054C: jal         0x800EF04C
    // 0x80800550: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EF04C(rdram, ctx);
        goto after_12;
    // 0x80800550: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_12:
    // 0x80800554: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080055C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800560: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800564: jal         0x808001B0
    // 0x80800568: lbu         $a3, 0x24($t8)
    ctx->r7 = MEM_BU(ctx->r24, 0X24);
    func_808001B0_chbadjinjo(rdram, ctx);
        goto after_13;
    // 0x80800568: lbu         $a3, 0x24($t8)
    ctx->r7 = MEM_BU(ctx->r24, 0X24);
    after_13:
    // 0x8080056C: jal         0x8001210C
    // 0x80800570: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001210C(rdram, ctx);
        goto after_14;
    // 0x80800570: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_14:
    // 0x80800574: beq         $v0, $zero, L_80800588
    if (ctx->r2 == 0) {
        // 0x80800578: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800588;
    }
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080057C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1576, 0X12DC) << 16);
    // 0x80800580: jal         0x80801090
    // 0x80800584: addiu       $a1, $a1, 0x12DC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1576, 0X12DC));
    func_80801090_chbadjinjo(rdram, ctx);
        goto after_15;
    // 0x80800584: addiu       $a1, $a1, 0x12DC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1576, 0X12DC));
    after_15:
L_80800588:
    // 0x80800588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080058C:
    // 0x8080058C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800590: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800594: jr          $ra
    // 0x80800598: nop

    return;
    // 0x80800598: nop

;}
RECOMP_FUNC void gspropctrl_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80800034: sll         $t6, $v0, 25
    ctx->r14 = S32(ctx->r2 << 25);
    // 0x80800038: jr          $ra
    // 0x8080003C: srl         $v0, $t6, 26
    ctx->r2 = S32(U32(ctx->r14) >> 26);
    return;
    // 0x8080003C: srl         $v0, $t6, 26
    ctx->r2 = S32(U32(ctx->r14) >> 26);
;}
RECOMP_FUNC void bstnt_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E4C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801E50: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(404, 0X258C) << 16);
    // 0x80801E54: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801E58: jr          $ra
    // 0x80801E5C: lw          $v0, 0x258C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X258C));
    return;
    // 0x80801E5C: lw          $v0, 0x258C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X258C));
;}
RECOMP_FUNC void func_808010E4_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010E4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808010E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808010EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808010F0: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x808010F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808010F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808010FC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80801100: nop

    // 0x80801104: bc1fl       L_80801184
    if (!c1cs) {
        // 0x80801108: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801184;
    }
    goto skip_0;
    // 0x80801108: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080110C: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80801110: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80801114: bgezl       $t8, L_80801184
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801118: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801184;
    }
    goto skip_1;
    // 0x80801118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8080111C: lw          $a0, 0x2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C);
    // 0x80801120: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(768, 0X17E0) << 16);
    // 0x80801124: addiu       $a2, $a2, 0x17E0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(768, 0X17E0));
    // 0x80801128: bne         $a0, $zero, L_80801178
    if (ctx->r4 != 0) {
        // 0x8080112C: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_80801178;
    }
    // 0x8080112C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801130: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80801134: jal         0x800EE780
    // 0x80801138: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800EE780(rdram, ctx);
        goto after_0;
    // 0x80801138: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080113C: jal         0x800B53A4
    // 0x80801140: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    func_800B53A4(rdram, ctx);
        goto after_1;
    // 0x80801140: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_1:
    // 0x80801144: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // 0x80801148: jal         0x800B5534
    // 0x8080114C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B5534(rdram, ctx);
        goto after_2;
    // 0x8080114C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80801150: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(768, 0X179C) << 16);
    // 0x80801154: addiu       $t9, $t9, 0x179C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(768, 0X179C));
    // 0x80801158: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x8080115C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801160: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801164: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80801168: jal         0x800BABB8
    // 0x8080116C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x8080116C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80801170: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // 0x80801174: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80801178:
    // 0x80801178: jal         0x800BA22C
    // 0x8080117C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800BA22C(rdram, ctx);
        goto after_4;
    // 0x8080117C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80801180: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801184:
    // 0x80801184: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801188: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080118C: jr          $ra
    // 0x80801190: nop

    return;
    // 0x80801190: nop

;}
RECOMP_FUNC void func_80800034_chtntminecelldoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800038: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080003C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800040: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800044: beq         $a1, $at, L_80800068
    if (ctx->r5 == ctx->r1) {
        // 0x80800048: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800068;
    }
    // 0x80800048: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080004C: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800050: beq         $a1, $at, L_808000B8
    if (ctx->r5 == ctx->r1) {
        // 0x80800054: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808000B8;
    }
    // 0x80800054: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800058: beq         $a1, $at, L_808000C8
    if (ctx->r5 == ctx->r1) {
        // 0x8080005C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808000C8;
    }
    // 0x8080005C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800060: b           L_808000E4
    // 0x80800064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000E4;
    // 0x80800064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800068:
    // 0x80800068: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8080006C: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80800070: jal         0x800EE7F8
    // 0x80800074: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800074: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800078: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8080007C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800080: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80800084: jal         0x800EF1B8
    // 0x80800088: lw          $a1, 0x48($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x80800088: lw          $a1, 0x48($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X48);
    after_1:
    // 0x8080008C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800090: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800094: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800098: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080009C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808000A0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808000A4: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x808000A8: jal         0x80086670
    // 0x808000AC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808000AC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x808000B0: b           L_808000E4
    // 0x808000B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000E4;
    // 0x808000B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000B8:
    // 0x808000B8: jal         0x808000F4
    // 0x808000BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_808000F4_chtntminecelldoor(rdram, ctx);
        goto after_3;
    // 0x808000BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x808000C0: b           L_808000E4
    // 0x808000C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000E4;
    // 0x808000C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000C8:
    // 0x808000C8: jal         0x80085D28
    // 0x808000CC: addiu       $a1, $zero, 0x85
    ctx->r5 = ADD32(0, 0X85);
    _chtntdetonator_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x808000CC: addiu       $a1, $zero, 0x85
    ctx->r5 = ADD32(0, 0X85);
    after_4:
    // 0x808000D0: b           L_808000E4
    // 0x808000D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000E4;
    // 0x808000D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808000D8: b           L_808000E4
    // 0x808000DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000E4;
    // 0x808000DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000E4:
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000EC: jr          $ra
    // 0x808000F0: nop

    return;
    // 0x808000F0: nop

;}
RECOMP_FUNC void func_80801AC4_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801AC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801ACC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80801AD0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1312, 0X27F8) << 16);
    // 0x80801AD4: addiu       $a3, $a3, 0x27F8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1312, 0X27F8));
    // 0x80801AD8: jal         0x80089D50
    // 0x80801ADC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80801ADC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80801AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801AE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801AE8: jr          $ra
    // 0x80801AEC: nop

    return;
    // 0x80801AEC: nop

;}
RECOMP_FUNC void bs_getTypeOfJump(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009FE84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009FE88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009FE8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009FE90: jal         0x800919F4
    // 0x8009FE94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_0;
    // 0x8009FE94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8009FE98: beql        $v0, $zero, L_8009FEBC
    if (ctx->r2 == 0) {
        // 0x8009FE9C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8009FEBC;
    }
    goto skip_0;
    // 0x8009FE9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x8009FEA0: jal         0x8008D370
    // 0x8009FEA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008D370(rdram, ctx);
        goto after_1;
    // 0x8009FEA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8009FEA8: beql        $v0, $zero, L_8009FEBC
    if (ctx->r2 == 0) {
        // 0x8009FEAC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8009FEBC;
    }
    goto skip_1;
    // 0x8009FEAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x8009FEB0: b           L_8009FEF0
    // 0x8009FEB4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_8009FEF0;
    // 0x8009FEB4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x8009FEB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8009FEBC:
    // 0x8009FEBC: jal         0x80095738
    // 0x8009FEC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x8009FEC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8009FEC4: beq         $v0, $zero, L_8009FED4
    if (ctx->r2 == 0) {
        // 0x8009FEC8: nop
    
            goto L_8009FED4;
    }
    // 0x8009FEC8: nop

    // 0x8009FECC: b           L_8009FEF0
    // 0x8009FED0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_8009FEF0;
    // 0x8009FED0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8009FED4:
    // 0x8009FED4: jal         0x8008D3B0
    // 0x8009FED8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008D3B0(rdram, ctx);
        goto after_3;
    // 0x8009FED8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8009FEDC: beql        $v0, $zero, L_8009FEF0
    if (ctx->r2 == 0) {
        // 0x8009FEE0: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8009FEF0;
    }
    goto skip_2;
    // 0x8009FEE0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    skip_2:
    // 0x8009FEE4: b           L_8009FEF0
    // 0x8009FEE8: addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
        goto L_8009FEF0;
    // 0x8009FEE8: addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
    // 0x8009FEEC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8009FEF0:
    // 0x8009FEF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009FEF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009FEF8: jr          $ra
    // 0x8009FEFC: nop

    return;
    // 0x8009FEFC: nop

;}
RECOMP_FUNC void func_8080135C_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080135C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801364: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801368: jal         0x80100094
    // 0x8080136C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080136C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801370: jal         0x80088380
    // 0x80801374: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _gcstatusDll_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80801374: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801378: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080137C: bnel        $v0, $at, L_808013D0
    if (ctx->r2 != ctx->r1) {
        // 0x80801380: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808013D0;
    }
    goto skip_0;
    // 0x80801380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801384: jal         0x800D8FF8
    // 0x80801388: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80801388: nop

    after_2:
    // 0x8080138C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80801390: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801394: jal         0x800F1574
    // 0x80801398: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800F1574(rdram, ctx);
        goto after_3;
    // 0x80801398: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_3:
    // 0x8080139C: beql        $v0, $zero, L_808013D0
    if (ctx->r2 == 0) {
        // 0x808013A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808013D0;
    }
    goto skip_1;
    // 0x808013A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808013A4: jal         0x800FC660
    // 0x808013A8: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_4;
    // 0x808013A8: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_4:
    // 0x808013AC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808013B0: lwc1        $f4, 0x10($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X10);
    // 0x808013B4: jal         0x80088388
    // 0x808013B8: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    _gcstatusDll_entrypoint_15(rdram, ctx);
        goto after_5;
    // 0x808013B8: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    after_5:
    // 0x808013BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808013C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808013C4: jal         0x80800BCC
    // 0x808013C8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_80800BCC_chfpsgame(rdram, ctx);
        goto after_6;
    // 0x808013C8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_6:
    // 0x808013CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808013D0:
    // 0x808013D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808013D4: jr          $ra
    // 0x808013D8: nop

    return;
    // 0x808013D8: nop

;}
RECOMP_FUNC void func_80800364_chstonedartgunhead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800364: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800368: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080036C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800370: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800374: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x80800378: jal         0x8010C820
    // 0x8080037C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_8010C820(rdram, ctx);
        goto after_0;
    // 0x8080037C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_0:
    // 0x80800380: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80800384: lbu         $t7, 0x2A($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2A);
    // 0x80800388: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x8080038C: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    // 0x80800390: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x80800394: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800398: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8080039C: sltiu       $at, $t1, 0x8
    ctx->r1 = ctx->r9 < 0X8 ? 1 : 0;
    // 0x808003A0: beq         $at, $zero, L_80800874
    if (ctx->r1 == 0) {
        // 0x808003A4: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80800874;
    }
    // 0x808003A4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x808003A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1872, 0XDD0) << 16);
    // 0x808003AC: addu        $at, $at, $t1
    gpr jr_addend_808003B4 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x808003B0: lw          $t1, 0xDD0($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1872, 0XDD0));
    // 0x808003B4: jr          $t1
    // 0x808003B8: nop

    switch (jr_addend_808003B4 >> 2) {
        case 0: goto L_808003BC; break;
        case 1: goto L_808003F4; break;
        case 2: goto L_8080041C; break;
        case 3: goto L_808005C4; break;
        case 4: goto L_80800744; break;
        case 5: goto L_8080076C; break;
        case 6: goto L_808007D4; break;
        case 7: goto L_80800840; break;
        default: switch_error(__func__, 0x808003B4, 0x80800DD0);
    }
    // 0x808003B8: nop

L_808003BC:
    // 0x808003BC: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x808003C0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808003C4: addiu       $a2, $zero, 0x190
    ctx->r6 = ADD32(0, 0X190);
    // 0x808003C8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808003CC: addiu       $a3, $zero, -0x190
    ctx->r7 = ADD32(0, -0X190);
    // 0x808003D0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808003D4: jal         0x8010CB0C
    // 0x808003D8: nop

    func_8010CB0C(rdram, ctx);
        goto after_1;
    // 0x808003D8: nop

    after_1:
    // 0x808003DC: beq         $v0, $zero, L_80800874
    if (ctx->r2 == 0) {
        // 0x808003E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800874;
    }
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E4: jal         0x80800224
    // 0x808003E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800224_chstonedartgunhead(rdram, ctx);
        goto after_2;
    // 0x808003E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808003EC: b           L_80800878
    // 0x808003F0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800878;
    // 0x808003F0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_808003F4:
    // 0x808003F4: lui         $a1, 0x3F5B
    ctx->r5 = S32(0X3F5B << 16);
    // 0x808003F8: ori         $a1, $a1, 0x22D1
    ctx->r5 = ctx->r5 | 0X22D1;
    // 0x808003FC: jal         0x80101E14
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_3;
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800404: beq         $v0, $zero, L_80800874
    if (ctx->r2 == 0) {
        // 0x80800408: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800874;
    }
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080040C: jal         0x80800224
    // 0x80800410: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800224_chstonedartgunhead(rdram, ctx);
        goto after_4;
    // 0x80800410: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800414: b           L_80800878
    // 0x80800418: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800878;
    // 0x80800418: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_8080041C:
    // 0x8080041C: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800420: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800424: addiu       $a2, $zero, 0x190
    ctx->r6 = ADD32(0, 0X190);
    // 0x80800428: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080042C: addiu       $a3, $zero, -0x190
    ctx->r7 = ADD32(0, -0X190);
    // 0x80800430: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800434: jal         0x8010CB0C
    // 0x80800438: nop

    func_8010CB0C(rdram, ctx);
        goto after_5;
    // 0x80800438: nop

    after_5:
    // 0x8080043C: bne         $v0, $zero, L_80800454
    if (ctx->r2 != 0) {
        // 0x80800440: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800454;
    }
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800444: jal         0x80800224
    // 0x80800448: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800224_chstonedartgunhead(rdram, ctx);
        goto after_6;
    // 0x80800448: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x8080044C: b           L_80800878
    // 0x80800450: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800878;
    // 0x80800450: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800454:
    // 0x80800454: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800458: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8080045C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800460: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80800464: nop

    // 0x80800468: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x8080046C: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80800470: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80800474: bgez        $t7, L_808004A8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800478: sll         $a0, $v0, 3
        ctx->r4 = S32(ctx->r2 << 3);
            goto L_808004A8;
    }
    // 0x80800478: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    // 0x8080047C: srl         $t8, $a0, 30
    ctx->r24 = S32(U32(ctx->r4) >> 30);
    // 0x80800480: jal         0x80016068
    // 0x80800484: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80016068(rdram, ctx);
        goto after_7;
    // 0x80800484: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_7:
    // 0x80800488: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8080048C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800490: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800494: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800498: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8080049C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808004A0: b           L_808004C0
    // 0x808004A4: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
        goto L_808004C0;
    // 0x808004A4: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
L_808004A8:
    // 0x808004A8: jal         0x8010CD28
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_8;
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808004B0: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808004B4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808004B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808004BC: nop

L_808004C0:
    // 0x808004C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004C4: jal         0x80102B2C
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102B2C(rdram, ctx);
        goto after_9;
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808004CC: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808004D0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x808004D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1872, 0XDF0) << 16);
    // 0x808004D8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E0: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x808004E4: nop

    // 0x808004E8: beql        $t9, $t1, L_808004FC
    if (ctx->r25 == ctx->r9) {
        // 0x808004EC: lw          $t2, 0x64($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X64);
            goto L_808004FC;
    }
    goto skip_0;
    // 0x808004EC: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x808004F0: lwc1        $f4, 0xDF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1872, 0XDF0));
    // 0x808004F4: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x808004F8: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
L_808004FC:
    // 0x808004FC: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80800500: bgezl       $t4, L_80800548
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800504: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80800548;
    }
    goto skip_1;
    // 0x80800504: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_1:
    // 0x80800508: jal         0x80089BD8
    // 0x8080050C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_10;
    // 0x8080050C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800510: beql        $v0, $zero, L_80800878
    if (ctx->r2 == 0) {
        // 0x80800514: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80800878;
    }
    goto skip_2;
    // 0x80800514: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_2:
    // 0x80800518: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080051C: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800524: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80800528: nop

    // 0x8080052C: bc1fl       L_80800878
    if (!c1cs) {
        // 0x80800530: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80800878;
    }
    goto skip_3;
    // 0x80800530: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_3:
    // 0x80800534: jal         0x80800224
    // 0x80800538: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800224_chstonedartgunhead(rdram, ctx);
        goto after_11;
    // 0x80800538: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x8080053C: b           L_80800878
    // 0x80800540: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800878;
    // 0x80800540: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800544: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80800548:
    // 0x80800548: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800550: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80800554: nop

    // 0x80800558: bc1fl       L_80800878
    if (!c1cs) {
        // 0x8080055C: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80800878;
    }
    goto skip_4;
    // 0x8080055C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_4:
    // 0x80800560: jal         0x80102CF4
    // 0x80800564: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    func_80102CF4(rdram, ctx);
        goto after_12;
    // 0x80800564: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    after_12:
    // 0x80800568: beql        $v0, $zero, L_80800878
    if (ctx->r2 == 0) {
        // 0x8080056C: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80800878;
    }
    goto skip_5;
    // 0x8080056C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_5:
    // 0x80800570: jal         0x8010D248
    // 0x80800574: nop

    func_8010D248(rdram, ctx);
        goto after_13;
    // 0x80800574: nop

    after_13:
    // 0x80800578: beq         $v0, $zero, L_80800874
    if (ctx->r2 == 0) {
        // 0x8080057C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800874;
    }
    // 0x8080057C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800580: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800584: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800588: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800590: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800594: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x80800598: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8080059C: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x808005A0: nop

    // 0x808005A4: bc1fl       L_80800878
    if (!c1cs) {
        // 0x808005A8: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80800878;
    }
    goto skip_6;
    // 0x808005A8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_6:
    // 0x808005AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808005B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808005B4: jal         0x80800224
    // 0x808005B8: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    func_80800224_chstonedartgunhead(rdram, ctx);
        goto after_14;
    // 0x808005B8: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    after_14:
    // 0x808005BC: b           L_80800878
    // 0x808005C0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800878;
    // 0x808005C0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_808005C4:
    // 0x808005C4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808005C8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1872, 0XE80) << 16);
    // 0x808005CC: lui         $a3, 0x3EE6
    ctx->r7 = S32(0X3EE6 << 16);
    // 0x808005D0: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x808005D4: addiu       $a2, $a2, 0xE80
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1872, 0XE80));
    // 0x808005D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808005DC: jal         0x80089D20
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808005E4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1872, 0XE8C) << 16);
    // 0x808005E8: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x808005EC: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x808005F0: addiu       $a2, $a2, 0xE8C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1872, 0XE8C));
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F8: jal         0x80089D20
    // 0x808005FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x808005FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_16:
    // 0x80800600: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1872, 0XE9C) << 16);
    // 0x80800604: lui         $a3, 0x3F7D
    ctx->r7 = S32(0X3F7D << 16);
    // 0x80800608: ori         $a3, $a3, 0x2F1B
    ctx->r7 = ctx->r7 | 0X2F1B;
    // 0x8080060C: addiu       $a2, $a2, 0xE9C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1872, 0XE9C));
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800614: jal         0x80089D20
    // 0x80800618: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_17;
    // 0x80800618: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_17:
    // 0x8080061C: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    // 0x80800620: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80800624: bgezl       $t7, L_808006F8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800628: lui         $a1, 0x3F7F
        ctx->r5 = S32(0X3F7F << 16);
            goto L_808006F8;
    }
    goto skip_7;
    // 0x80800628: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    skip_7:
    // 0x8080062C: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800634: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800638: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x8080063C: jal         0x80101F24
    // 0x80800640: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    func_80101F24(rdram, ctx);
        goto after_18;
    // 0x80800640: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_18:
    // 0x80800644: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1872, 0XDF4) << 16);
    // 0x80800648: lwc1        $f6, 0xDF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1872, 0XDF4));
    // 0x8080064C: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80800650: nop

    // 0x80800654: bc1fl       L_80800694
    if (!c1cs) {
        // 0x80800658: lw          $a0, 0x64($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X64);
            goto L_80800694;
    }
    goto skip_8;
    // 0x80800658: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
    skip_8:
    // 0x8080065C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800660: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800668: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8080066C: nop

    // 0x80800670: bc1fl       L_80800694
    if (!c1cs) {
        // 0x80800674: lw          $a0, 0x64($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X64);
            goto L_80800694;
    }
    goto skip_9;
    // 0x80800674: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
    skip_9:
    // 0x80800678: jal         0x80089BD8
    // 0x8080067C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_19;
    // 0x8080067C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80800680: beq         $v0, $zero, L_80800690
    if (ctx->r2 == 0) {
        // 0x80800684: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800690;
    }
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800688: jal         0x80800224
    // 0x8080068C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800224_chstonedartgunhead(rdram, ctx);
        goto after_20;
    // 0x8080068C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_20:
L_80800690:
    // 0x80800690: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
L_80800694:
    // 0x80800694: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800698: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8080069C: jal         0x80016068
    // 0x808006A0: srl         $a0, $t9, 30
    ctx->r4 = S32(U32(ctx->r25) >> 30);
    func_80016068(rdram, ctx);
        goto after_21;
    // 0x808006A0: srl         $a0, $t9, 30
    ctx->r4 = S32(U32(ctx->r25) >> 30);
    after_21:
    // 0x808006A4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808006A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808006AC: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808006B0: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808006B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808006B8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x808006C4: jal         0x80102B2C
    // 0x808006C8: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    func_80102B2C(rdram, ctx);
        goto after_22;
    // 0x808006C8: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    after_22:
    // 0x808006CC: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808006D0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x808006D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1872, 0XDF8) << 16);
    // 0x808006D8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808006DC: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x808006E0: nop

    // 0x808006E4: beql        $t2, $t4, L_808006F8
    if (ctx->r10 == ctx->r12) {
        // 0x808006E8: lui         $a1, 0x3F7F
        ctx->r5 = S32(0X3F7F << 16);
            goto L_808006F8;
    }
    goto skip_10;
    // 0x808006E8: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    skip_10:
    // 0x808006EC: lwc1        $f16, 0xDF8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1872, 0XDF8));
    // 0x808006F0: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x808006F4: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
L_808006F8:
    // 0x808006F8: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x808006FC: jal         0x80101E14
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_23;
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800704: beq         $v0, $zero, L_80800720
    if (ctx->r2 == 0) {
        // 0x80800708: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800720;
    }
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800710: jal         0x80800224
    // 0x80800714: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800224_chstonedartgunhead(rdram, ctx);
        goto after_24;
    // 0x80800714: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_24:
    // 0x80800718: b           L_80800878
    // 0x8080071C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800878;
    // 0x8080071C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800720:
    // 0x80800720: lui         $a1, 0x3D54
    ctx->r5 = S32(0X3D54 << 16);
    // 0x80800724: jal         0x80101E14
    // 0x80800728: ori         $a1, $a1, 0xFDF4
    ctx->r5 = ctx->r5 | 0XFDF4;
    func_80101E14(rdram, ctx);
        goto after_25;
    // 0x80800728: ori         $a1, $a1, 0xFDF4
    ctx->r5 = ctx->r5 | 0XFDF4;
    after_25:
    // 0x8080072C: beq         $v0, $zero, L_80800874
    if (ctx->r2 == 0) {
        // 0x80800730: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800874;
    }
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800734: jal         0x80108B04
    // 0x80800738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_26;
    // 0x80800738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x8080073C: b           L_80800878
    // 0x80800740: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800878;
    // 0x80800740: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800744:
    // 0x80800744: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800748: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x8080074C: jal         0x80101E14
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_27;
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80800754: beq         $v0, $zero, L_80800874
    if (ctx->r2 == 0) {
        // 0x80800758: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800874;
    }
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080075C: jal         0x80800224
    // 0x80800760: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800224_chstonedartgunhead(rdram, ctx);
        goto after_28;
    // 0x80800760: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x80800764: b           L_80800878
    // 0x80800768: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800878;
    // 0x80800768: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_8080076C:
    // 0x8080076C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800774: lbu         $t5, 0x2A($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2A);
    // 0x80800778: andi        $t6, $t5, 0xFFDF
    ctx->r14 = ctx->r13 & 0XFFDF;
    // 0x8080077C: jal         0x808001B4
    // 0x80800780: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    func_808001B4_chstonedartgunhead(rdram, ctx);
        goto after_29;
    // 0x80800780: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    after_29:
    // 0x80800784: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1872, 0XDFC) << 16);
    // 0x80800788: lwc1        $f4, 0xDFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1872, 0XDFC));
    // 0x8080078C: lwc1        $f18, 0x30($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800790: lui         $at, 0x42AE
    ctx->r1 = S32(0X42AE << 16);
    // 0x80800794: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800798: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8080079C: lui         $at, 0x42AE
    ctx->r1 = S32(0X42AE << 16);
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A4: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    // 0x808007A8: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808007AC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808007B0: nop

    // 0x808007B4: bc1fl       L_80800878
    if (!c1cs) {
        // 0x808007B8: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80800878;
    }
    goto skip_11;
    // 0x808007B8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_11:
    // 0x808007BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808007C0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808007C4: jal         0x80800224
    // 0x808007C8: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    func_80800224_chstonedartgunhead(rdram, ctx);
        goto after_30;
    // 0x808007C8: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    after_30:
    // 0x808007CC: b           L_80800878
    // 0x808007D0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800878;
    // 0x808007D0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_808007D4:
    // 0x808007D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007DC: lbu         $t7, 0x2A($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2A);
    // 0x808007E0: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x808007E4: jal         0x808001B4
    // 0x808007E8: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    func_808001B4_chstonedartgunhead(rdram, ctx);
        goto after_31;
    // 0x808007E8: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    after_31:
    // 0x808007EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808007F0: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808007F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1872, 0XE00) << 16);
    // 0x808007F8: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x808007FC: nop

    // 0x80800800: bc1fl       L_80800878
    if (!c1cs) {
        // 0x80800804: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80800878;
    }
    goto skip_12;
    // 0x80800804: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_12:
    // 0x80800808: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8080080C: lwc1        $f6, 0xE00($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1872, 0XE00));
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800814: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800818: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    // 0x8080081C: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800820: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800824: nop

    // 0x80800828: bc1fl       L_80800878
    if (!c1cs) {
        // 0x8080082C: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80800878;
    }
    goto skip_13;
    // 0x8080082C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_13:
    // 0x80800830: jal         0x80800224
    // 0x80800834: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800224_chstonedartgunhead(rdram, ctx);
        goto after_32;
    // 0x80800834: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_32:
    // 0x80800838: b           L_80800878
    // 0x8080083C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800878;
    // 0x8080083C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800840:
    // 0x80800840: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80800844: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080084C: lbu         $t0, 0x2A($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X2A);
    // 0x80800850: andi        $t9, $t0, 0xFFDF
    ctx->r25 = ctx->r8 & 0XFFDF;
    // 0x80800854: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
    // 0x80800858: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080085C: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80800860: nop

    // 0x80800864: bc1fl       L_80800878
    if (!c1cs) {
        // 0x80800868: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80800878;
    }
    goto skip_14;
    // 0x80800868: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_14:
    // 0x8080086C: jal         0x80800224
    // 0x80800870: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800224_chstonedartgunhead(rdram, ctx);
        goto after_33;
    // 0x80800870: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
L_80800874:
    // 0x80800874: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800878:
    // 0x80800878: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8080087C: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x80800880: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80800884: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x80800888: lui         $a2, 0x42AE
    ctx->r6 = S32(0X42AE << 16);
    // 0x8080088C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800890: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
    // 0x80800894: bc1f        L_808008EC
    if (!c1cs) {
        // 0x80800898: nop
    
            goto L_808008EC;
    }
    // 0x80800898: nop

    // 0x8080089C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008A0: lwc1        $f12, 0x30($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808008A4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x808008A8: jal         0x800F11E4
    // 0x808008AC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F11E4(rdram, ctx);
        goto after_34;
    // 0x808008AC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_34:
    // 0x808008B0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1872, 0XEAC) << 16);
    // 0x808008B4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x808008B8: addiu       $a3, $a3, 0xEAC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1872, 0XEAC));
    // 0x808008BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808008C4: jal         0x80089D50
    // 0x808008C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_35;
    // 0x808008C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_35:
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D0: jal         0x80089D30
    // 0x808008D4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_36;
    // 0x808008D4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_36:
    // 0x808008D8: jal         0x800D8FF8
    // 0x808008DC: nop

    func_800D8FF8(rdram, ctx);
        goto after_37;
    // 0x808008DC: nop

    after_37:
    // 0x808008E0: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808008E4: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x808008E8: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
L_808008EC:
    // 0x808008EC: jal         0x800D9078
    // 0x808008F0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_38;
    // 0x808008F0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_38:
    // 0x808008F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808008F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008FC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800900: jr          $ra
    // 0x80800904: nop

    return;
    // 0x80800904: nop

;}
RECOMP_FUNC void _chfactoryworkerdirty_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087320: syscall     550
    recomp_syscall_handler(rdram, ctx, 0x80087320);
    return;
    // 0x80087324: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bacough_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000EC: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x808000F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000F4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x808000F8: bnel        $t7, $at, L_808002C0
    if (ctx->r15 != ctx->r1) {
        // 0x808000FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002C0;
    }
    goto skip_0;
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800100: jal         0x800F424C
    // 0x80800104: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800F424C(rdram, ctx);
        goto after_0;
    // 0x80800104: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800108: beq         $v0, $zero, L_808002BC
    if (ctx->r2 == 0) {
        // 0x8080010C: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_808002BC;
    }
    // 0x8080010C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800110: lw          $a0, 0x44($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X44);
    // 0x80800114: jal         0x800D9078
    // 0x80800118: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x80800118: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x8080011C: beql        $v0, $zero, L_808002C0
    if (ctx->r2 == 0) {
        // 0x80800120: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002C0;
    }
    goto skip_1;
    // 0x80800120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800124: jal         0x800DC0C0
    // 0x80800128: nop

    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x80800128: nop

    after_2:
    // 0x8080012C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(470, 0X2D0) << 16);
    // 0x80800130: lwc1        $f12, 0x2D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(470, 0X2D0));
    // 0x80800134: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(470, 0X2D4) << 16);
    // 0x80800138: lwc1        $f14, 0x2D4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(470, 0X2D4));
    // 0x8080013C: jal         0x800DC178
    // 0x80800140: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800140: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80800144: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800148: jal         0x800A3274
    // 0x8080014C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800A3274(rdram, ctx);
        goto after_4;
    // 0x8080014C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80800150: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800154: beq         $v0, $at, L_80800180
    if (ctx->r2 == ctx->r1) {
        // 0x80800158: lwc1        $f2, 0x20($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
            goto L_80800180;
    }
    // 0x80800158: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080015C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800160: beq         $v0, $at, L_80800180
    if (ctx->r2 == ctx->r1) {
        // 0x80800164: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80800180;
    }
    // 0x80800164: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800168: beq         $v0, $at, L_808001C8
    if (ctx->r2 == ctx->r1) {
        // 0x8080016C: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_808001C8;
    }
    // 0x8080016C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80800170: beql        $v0, $at, L_808001F8
    if (ctx->r2 == ctx->r1) {
        // 0x80800174: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_808001F8;
    }
    goto skip_2;
    // 0x80800174: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_2:
    // 0x80800178: b           L_80800218
    // 0x8080017C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80800218;
    // 0x8080017C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800180:
    // 0x80800180: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(470, 0X2D8) << 16);
    // 0x80800184: lwc1        $f4, 0x2D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(470, 0X2D8));
    // 0x80800188: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(470, 0X2DC) << 16);
    // 0x8080018C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80800190: nop

    // 0x80800194: bc1f        L_808001A4
    if (!c1cs) {
        // 0x80800198: nop
    
            goto L_808001A4;
    }
    // 0x80800198: nop

    // 0x8080019C: b           L_80800218
    // 0x808001A0: addiu       $a1, $zero, 0x571
    ctx->r5 = ADD32(0, 0X571);
        goto L_80800218;
    // 0x808001A0: addiu       $a1, $zero, 0x571
    ctx->r5 = ADD32(0, 0X571);
L_808001A4:
    // 0x808001A4: lwc1        $f6, 0x2DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(470, 0X2DC));
    // 0x808001A8: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x808001AC: nop

    // 0x808001B0: bc1f        L_808001C0
    if (!c1cs) {
        // 0x808001B4: nop
    
            goto L_808001C0;
    }
    // 0x808001B4: nop

    // 0x808001B8: b           L_80800218
    // 0x808001BC: addiu       $a1, $zero, 0x572
    ctx->r5 = ADD32(0, 0X572);
        goto L_80800218;
    // 0x808001BC: addiu       $a1, $zero, 0x572
    ctx->r5 = ADD32(0, 0X572);
L_808001C0:
    // 0x808001C0: b           L_80800218
    // 0x808001C4: addiu       $a1, $zero, 0x573
    ctx->r5 = ADD32(0, 0X573);
        goto L_80800218;
    // 0x808001C4: addiu       $a1, $zero, 0x573
    ctx->r5 = ADD32(0, 0X573);
L_808001C8:
    // 0x808001C8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808001CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001D0: nop

    // 0x808001D4: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x808001D8: nop

    // 0x808001DC: bc1f        L_808001EC
    if (!c1cs) {
        // 0x808001E0: nop
    
            goto L_808001EC;
    }
    // 0x808001E0: nop

    // 0x808001E4: b           L_80800218
    // 0x808001E8: addiu       $a1, $zero, 0x45B
    ctx->r5 = ADD32(0, 0X45B);
        goto L_80800218;
    // 0x808001E8: addiu       $a1, $zero, 0x45B
    ctx->r5 = ADD32(0, 0X45B);
L_808001EC:
    // 0x808001EC: b           L_80800218
    // 0x808001F0: addiu       $a1, $zero, 0x59F
    ctx->r5 = ADD32(0, 0X59F);
        goto L_80800218;
    // 0x808001F0: addiu       $a1, $zero, 0x59F
    ctx->r5 = ADD32(0, 0X59F);
    // 0x808001F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_808001F8:
    // 0x808001F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808001FC: addiu       $a1, $zero, 0x510
    ctx->r5 = ADD32(0, 0X510);
    // 0x80800200: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80800204: nop

    // 0x80800208: bc1f        L_80800218
    if (!c1cs) {
        // 0x8080020C: nop
    
            goto L_80800218;
    }
    // 0x8080020C: nop

    // 0x80800210: b           L_80800218
    // 0x80800214: addiu       $a1, $zero, 0x50F
    ctx->r5 = ADD32(0, 0X50F);
        goto L_80800218;
    // 0x80800214: addiu       $a1, $zero, 0x50F
    ctx->r5 = ADD32(0, 0X50F);
L_80800218:
    // 0x80800218: beq         $a1, $zero, L_8080022C
    if (ctx->r5 == 0) {
        // 0x8080021C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8080022C;
    }
    // 0x8080021C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800220: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800224: jal         0x8009DB04
    // 0x80800228: addiu       $a3, $zero, 0x5DC0
    ctx->r7 = ADD32(0, 0X5DC0);
    func_8009DB04(rdram, ctx);
        goto after_5;
    // 0x80800228: addiu       $a3, $zero, 0x5DC0
    ctx->r7 = ADD32(0, 0X5DC0);
    after_5:
L_8080022C:
    // 0x8080022C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(470, 0X2E0) << 16);
    // 0x80800230: jal         0x800DC298
    // 0x80800234: lwc1        $f12, 0x2E0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(470, 0X2E0));
    func_800DC298(rdram, ctx);
        goto after_6;
    // 0x80800234: lwc1        $f12, 0x2E0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(470, 0X2E0));
    after_6:
    // 0x80800238: beq         $v0, $zero, L_80800264
    if (ctx->r2 == 0) {
        // 0x8080023C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(470, 0X2EC) << 16);
            goto L_80800264;
    }
    // 0x8080023C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(470, 0X2EC) << 16);
    // 0x80800240: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(470, 0X2E4) << 16);
    // 0x80800244: lwc1        $f12, 0x2E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(470, 0X2E4));
    // 0x80800248: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(470, 0X2E8) << 16);
    // 0x8080024C: jal         0x800DC178
    // 0x80800250: lwc1        $f14, 0x2E8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(470, 0X2E8));
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80800250: lwc1        $f14, 0x2E8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(470, 0X2E8));
    after_7:
    // 0x80800254: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800258: lw          $t0, 0x44($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X44);
    // 0x8080025C: b           L_808002BC
    // 0x80800260: swc1        $f0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f0.u32l;
        goto L_808002BC;
    // 0x80800260: swc1        $f0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f0.u32l;
L_80800264:
    // 0x80800264: jal         0x800DC298
    // 0x80800268: lwc1        $f12, 0x2EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(470, 0X2EC));
    func_800DC298(rdram, ctx);
        goto after_8;
    // 0x80800268: lwc1        $f12, 0x2EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(470, 0X2EC));
    after_8:
    // 0x8080026C: beq         $v0, $zero, L_8080029C
    if (ctx->r2 == 0) {
        // 0x80800270: lui         $at, 0x4060
        ctx->r1 = S32(0X4060 << 16);
            goto L_8080029C;
    }
    // 0x80800270: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80800274: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800278: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080027C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800280: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800284: jal         0x800DC178
    // 0x80800288: nop

    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x80800288: nop

    after_9:
    // 0x8080028C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80800290: lw          $t2, 0x44($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X44);
    // 0x80800294: b           L_808002BC
    // 0x80800298: swc1        $f0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f0.u32l;
        goto L_808002BC;
    // 0x80800298: swc1        $f0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f0.u32l;
L_8080029C:
    // 0x8080029C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808002A0: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x808002A4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808002A8: jal         0x800DC178
    // 0x808002AC: nop

    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x808002AC: nop

    after_10:
    // 0x808002B0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x808002B4: lw          $t4, 0x44($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X44);
    // 0x808002B8: swc1        $f0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f0.u32l;
L_808002BC:
    // 0x808002BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002C0:
    // 0x808002C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002C4: jr          $ra
    // 0x808002C8: nop

    return;
    // 0x808002C8: nop

;}
RECOMP_FUNC void func_8008F828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F82C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F830: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008F834: jal         0x800D1B34
    // 0x8008F838: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800D1B34(rdram, ctx);
        goto after_0;
    // 0x8008F838: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8008F83C: jal         0x800D1A04
    // 0x8008F840: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D1A04(rdram, ctx);
        goto after_1;
    // 0x8008F840: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008F844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F848: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008F84C: jr          $ra
    // 0x8008F850: nop

    return;
    // 0x8008F850: nop

;}
RECOMP_FUNC void func_80800000_trangler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800004: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800010: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800014: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800018: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080001C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80800020: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80800024: jal         0x8010E810
    // 0x80800028: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    func_8010E810(rdram, ctx);
        goto after_0;
    // 0x80800028: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080002C: bgez        $s0, L_8080003C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80800030: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8080003C;
    }
    // 0x80800030: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800034: b           L_80800040
    // 0x80800038: negu        $v0, $s0
    ctx->r2 = SUB32(0, ctx->r16);
        goto L_80800040;
    // 0x80800038: negu        $v0, $s0
    ctx->r2 = SUB32(0, ctx->r16);
L_8080003C:
    // 0x8080003C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80800040:
    // 0x80800040: lw          $t6, 0x14($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X14);
    // 0x80800044: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80800048: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8080004C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80800050: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800054: sw          $t8, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r24;
    // 0x80800058: jal         0x800DF8B4
    // 0x8080005C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800DF8B4(rdram, ctx);
        goto after_1;
    // 0x8080005C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x80800060: addiu       $s1, $sp, 0x48
    ctx->r17 = ADD32(ctx->r29, 0X48);
    // 0x80800064: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800068: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080006C: jal         0x800B237C
    // 0x80800070: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_800B237C(rdram, ctx);
        goto after_2;
    // 0x80800070: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_2:
    // 0x80800074: jal         0x800DF8C4
    // 0x80800078: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800DF8C4(rdram, ctx);
        goto after_3;
    // 0x80800078: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_3:
    // 0x8080007C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800080: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800084: jal         0x80019224
    // 0x80800088: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80019224(rdram, ctx);
        goto after_4;
    // 0x80800088: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8080008C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800090: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800094: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80800098: jal         0x800DF900
    // 0x8080009C: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    func_800DF900(rdram, ctx);
        goto after_5;
    // 0x8080009C: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x808000A0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x808000A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808000A8: beql        $a0, $zero, L_808000D0
    if (ctx->r4 == 0) {
        // 0x808000AC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808000D0;
    }
    goto skip_0;
    // 0x808000AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
    // 0x808000B0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808000B4: jal         0x8010E924
    // 0x808000B8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_8010E924(rdram, ctx);
        goto after_6;
    // 0x808000B8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_6:
    // 0x808000BC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808000C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000C4: nop

    // 0x808000C8: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    // 0x808000CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_808000D0:
    // 0x808000D0: jal         0x800C8760
    // 0x808000D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8760(rdram, ctx);
        goto after_7;
    // 0x808000D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808000D8: beq         $v0, $zero, L_8080010C
    if (ctx->r2 == 0) {
        // 0x808000DC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8080010C;
    }
    // 0x808000DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808000E0:
    // 0x808000E0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808000EC: jal         0x8010E924
    // 0x808000F0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_8010E924(rdram, ctx);
        goto after_8;
    // 0x808000F0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_8:
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000FC: jal         0x800C878C
    // 0x80800100: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800C878C(rdram, ctx);
        goto after_9;
    // 0x80800100: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80800104: bne         $v0, $zero, L_808000E0
    if (ctx->r2 != 0) {
        // 0x80800108: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808000E0;
    }
    // 0x80800108: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8080010C:
    // 0x8080010C: lw          $t9, 0x14($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X14);
    // 0x80800110: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80800114: subu        $t0, $t9, $s2
    ctx->r8 = SUB32(ctx->r25, ctx->r18);
    // 0x80800118: addiu       $t1, $t0, -0x1C
    ctx->r9 = ADD32(ctx->r8, -0X1C);
    // 0x8080011C: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x80800120: mflo        $t2
    ctx->r10 = lo;
    // 0x80800124: sb          $t2, 0x11($s2)
    MEM_B(0X11, ctx->r18) = ctx->r10;
    // 0x80800128: jal         0x80018DAC
    // 0x8080012C: nop

    mlMtxPop(rdram, ctx);
        goto after_10;
    // 0x8080012C: nop

    after_10:
    // 0x80800130: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800134: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800138: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080013C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800140: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800144: jr          $ra
    // 0x80800148: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800148: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800D5A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5A04: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D5A08: lbu         $v1, -0x481C($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X481C);
    // 0x800D5A0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D5A10: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D5A14: blezl       $v1, L_800D5A54
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800D5A18: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800D5A54;
    }
    goto skip_0;
    // 0x800D5A18: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_0:
    // 0x800D5A1C: lh          $t6, -0x4920($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4920);
    // 0x800D5A20: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D5A24: addiu       $a1, $a1, -0x4920
    ctx->r5 = ADD32(ctx->r5, -0X4920);
    // 0x800D5A28: beql        $a0, $t6, L_800D5A54
    if (ctx->r4 == ctx->r14) {
        // 0x800D5A2C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800D5A54;
    }
    goto skip_1;
    // 0x800D5A2C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_1:
    // 0x800D5A30: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800D5A34:
    // 0x800D5A34: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800D5A38: beq         $at, $zero, L_800D5A50
    if (ctx->r1 == 0) {
        // 0x800D5A3C: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_800D5A50;
    }
    // 0x800D5A3C: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800D5A40: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800D5A44: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800D5A48: bnel        $a0, $t9, L_800D5A34
    if (ctx->r4 != ctx->r25) {
        // 0x800D5A4C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800D5A34;
    }
    goto skip_2;
    // 0x800D5A4C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
L_800D5A50:
    // 0x800D5A50: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_800D5A54:
    // 0x800D5A54: beq         $at, $zero, L_800D5A64
    if (ctx->r1 == 0) {
        // 0x800D5A58: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D5A64;
    }
    // 0x800D5A58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D5A5C: jr          $ra
    // 0x800D5A60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800D5A60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D5A64:
    // 0x800D5A64: jr          $ra
    // 0x800D5A68: nop

    return;
    // 0x800D5A68: nop

;}
RECOMP_FUNC void func_808012EC_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808012F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808012F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808012F8: jal         0x8080055C
    // 0x808012FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bsbabykaz_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808012FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801300: jal         0x80084498
    // 0x80801304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bababykaz_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80801304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801308: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080130C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801310: jal         0x800844C0
    // 0x80801314: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _bababykaz_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80801314: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80801318: jal         0x80800000
    // 0x8080131C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsbabykaz_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x8080131C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801320: jal         0x800844B8
    // 0x80801324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bababykaz_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80801324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080132C: jal         0x80091E48
    // 0x80801330: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80091E48(rdram, ctx);
        goto after_5;
    // 0x80801330: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_5:
    // 0x80801334: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801338: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080133C: bgez        $a0, L_80801354
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80801340: nop
    
            goto L_80801354;
    }
    // 0x80801340: nop

    // 0x80801344: jal         0x80801134
    // 0x80801348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801134_bsbabykaz(rdram, ctx);
        goto after_6;
    // 0x80801348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080134C: b           L_80801374
    // 0x80801350: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801374;
    // 0x80801350: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801354:
    // 0x80801354: jal         0x800F80D8
    // 0x80801358: nop

    func_800F80D8(rdram, ctx);
        goto after_7;
    // 0x80801358: nop

    after_7:
    // 0x8080135C: jal         0x800F8EBC
    // 0x80801360: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F8EBC(rdram, ctx);
        goto after_8;
    // 0x80801360: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x80801364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801368: jal         0x80801134
    // 0x8080136C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801134_bsbabykaz(rdram, ctx);
        goto after_9;
    // 0x8080136C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80801370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801374:
    // 0x80801374: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801378: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080137C: jr          $ra
    // 0x80801380: nop

    return;
    // 0x80801380: nop

;}
RECOMP_FUNC void func_808018E4_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018E4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808018E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808018EC: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808018F0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808018F4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808018F8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808018FC: beq         $t7, $at, L_808019DC
    if (ctx->r15 == ctx->r1) {
        // 0x80801900: addiu       $a0, $a0, 0x24
        ctx->r4 = ADD32(ctx->r4, 0X24);
            goto L_808019DC;
    }
    // 0x80801900: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    // 0x80801904: jal         0x800D90A4
    // 0x80801908: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x80801908: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080190C: beq         $v0, $zero, L_808019DC
    if (ctx->r2 == 0) {
        // 0x80801910: lui         $t9, 0x8080
        ctx->r25 = S32(RELOC_HI16(2384, 0X3164) << 16);
            goto L_808019DC;
    }
    // 0x80801910: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2384, 0X3164) << 16);
    // 0x80801914: addiu       $t9, $t9, 0x3164
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2384, 0X3164));
    // 0x80801918: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x8080191C: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80801920: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x80801924: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x80801928: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x8080192C: lw          $t1, 0xC($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XC);
    // 0x80801930: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x80801934: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80801938: sw          $t1, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r9;
    // 0x8080193C: sw          $at, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r1;
    // 0x80801940: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80801944: lw          $a0, 0x70($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X70);
    // 0x80801948: srl         $t3, $a0, 25
    ctx->r11 = S32(U32(ctx->r4) >> 25);
    // 0x8080194C: jal         0x800CD08C
    // 0x80801950: addiu       $a0, $t3, -0x1
    ctx->r4 = ADD32(ctx->r11, -0X1);
    func_800CD08C(rdram, ctx);
        goto after_1;
    // 0x80801950: addiu       $a0, $t3, -0x1
    ctx->r4 = ADD32(ctx->r11, -0X1);
    after_1:
    // 0x80801954: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80801958: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x8080195C: lui         $a2, 0xC47A
    ctx->r6 = S32(0XC47A << 16);
    // 0x80801960: jal         0x800C6920
    // 0x80801964: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C6920(rdram, ctx);
        goto after_2;
    // 0x80801964: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80801968: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2384, 0X3174) << 16);
    // 0x8080196C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80801970: addiu       $t4, $t4, 0x3174
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2384, 0X3174));
    // 0x80801974: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80801978: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8080197C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80801980: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801984: jal         0x800BABB8
    // 0x80801988: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x80801988: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x8080198C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80801990: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801994: jal         0x800DC128
    // 0x80801998: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DC128(rdram, ctx);
        goto after_4;
    // 0x80801998: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x8080199C: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x808019A0: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x808019A4: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x808019A8: jal         0x800BAB80
    // 0x808019AC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800BAB80(rdram, ctx);
        goto after_5;
    // 0x808019AC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x808019B0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808019B4: jal         0x800BA22C
    // 0x808019B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_6;
    // 0x808019B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808019BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808019C0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808019C4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808019C8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808019CC: jal         0x800DC178
    // 0x808019D0: nop

    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x808019D0: nop

    after_7:
    // 0x808019D4: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x808019D8: swc1        $f0, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f0.u32l;
L_808019DC:
    // 0x808019DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808019E0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808019E4: jr          $ra
    // 0x808019E8: nop

    return;
    // 0x808019E8: nop

;}
RECOMP_FUNC void func_8080038C_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080038C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800394: jal         0x800EA05C
    // 0x80800398: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800398: nop

    after_0:
    // 0x8080039C: addiu       $at, $zero, 0x19C
    ctx->r1 = ADD32(0, 0X19C);
    // 0x808003A0: beq         $v0, $at, L_808003B0
    if (ctx->r2 == ctx->r1) {
        // 0x808003A4: addiu       $at, $zero, 0x19D
        ctx->r1 = ADD32(0, 0X19D);
            goto L_808003B0;
    }
    // 0x808003A4: addiu       $at, $zero, 0x19D
    ctx->r1 = ADD32(0, 0X19D);
    // 0x808003A8: bnel        $v0, $at, L_808003DC
    if (ctx->r2 != ctx->r1) {
        // 0x808003AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808003DC;
    }
    goto skip_0;
    // 0x808003AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_808003B0:
    // 0x808003B0: jal         0x800D395C
    // 0x808003B4: nop

    func_800D395C(rdram, ctx);
        goto after_1;
    // 0x808003B4: nop

    after_1:
    // 0x808003B8: beq         $v0, $zero, L_808003D0
    if (ctx->r2 == 0) {
        // 0x808003BC: addiu       $a0, $zero, 0x194
        ctx->r4 = ADD32(0, 0X194);
            goto L_808003D0;
    }
    // 0x808003BC: addiu       $a0, $zero, 0x194
    ctx->r4 = ADD32(0, 0X194);
    // 0x808003C0: jal         0x80088180
    // 0x808003C4: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x808003C4: nop

    after_2:
    // 0x808003C8: b           L_808003DC
    // 0x808003CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003DC;
    // 0x808003CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003D0:
    // 0x808003D0: jal         0x80087A58
    // 0x808003D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808003D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808003D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003DC:
    // 0x808003DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003E0: jr          $ra
    // 0x808003E4: nop

    return;
    // 0x808003E4: nop

;}
RECOMP_FUNC void bsbbilldrill_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007AC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808007B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808007B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808007B8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x808007BC: lbu         $t6, 0x15C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X15C);
    // 0x808007C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007C4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x808007C8: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x808007CC: beq         $at, $zero, L_80800A2C
    if (ctx->r1 == 0) {
        // 0x808007D0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800A2C;
    }
    // 0x808007D0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808007D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(61, 0XA94) << 16);
    // 0x808007D8: addu        $at, $at, $t7
    gpr jr_addend_808007E0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808007DC: lw          $t7, 0xA94($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(61, 0XA94));
    // 0x808007E0: jr          $t7
    // 0x808007E4: nop

    switch (jr_addend_808007E0 >> 2) {
        case 0: goto L_808007E8; break;
        case 1: goto L_80800880; break;
        case 2: goto L_808008B4; break;
        case 3: goto L_80800990; break;
        case 4: goto L_808009E8; break;
        default: switch_error(__func__, 0x808007E0, 0x80800A94);
    }
    // 0x808007E4: nop

L_808007E8:
    // 0x808007E8: jal         0x80800298
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800298_bsbbilldrill(rdram, ctx);
        goto after_0;
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F4: jal         0x80085300
    // 0x808007F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_get(rdram, ctx);
        goto after_1;
    // 0x808007F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808007FC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800800: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800804: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800808: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8080080C: lui         $a3, 0x44BB
    ctx->r7 = S32(0X44BB << 16);
    // 0x80800810: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80800814: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80800818: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080081C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800820: jal         0x800F10B4
    // 0x80800824: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800824: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80800828: swc1        $f0, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f0.u32l;
    // 0x8080082C: jal         0x808005C0
    // 0x80800830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005C0_bsbbilldrill(rdram, ctx);
        goto after_3;
    // 0x80800830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800834: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800838: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8080083C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800840: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800844: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800848: jal         0x800F10B4
    // 0x8080084C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x8080084C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_4:
    // 0x80800850: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800854: jal         0x80098520
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80098520(rdram, ctx);
        goto after_5;
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800860: jal         0x800852F0
    // 0x80800864: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_6;
    // 0x80800864: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800868: beq         $v0, $zero, L_80800A2C
    if (ctx->r2 == 0) {
        // 0x8080086C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A2C;
    }
    // 0x8080086C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800870: jal         0x808002DC
    // 0x80800874: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808002DC_bsbbilldrill(rdram, ctx);
        goto after_7;
    // 0x80800874: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800878: b           L_80800A30
    // 0x8080087C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800A30;
    // 0x8080087C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800880:
    // 0x80800880: jal         0x80800298
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800298_bsbbilldrill(rdram, ctx);
        goto after_8;
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800888: jal         0x808005C0
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005C0_bsbbilldrill(rdram, ctx);
        goto after_9;
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800894: jal         0x800852F0
    // 0x80800898: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_10;
    // 0x80800898: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8080089C: beq         $v0, $zero, L_80800A2C
    if (ctx->r2 == 0) {
        // 0x808008A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A2C;
    }
    // 0x808008A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A4: jal         0x808002DC
    // 0x808008A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808002DC_bsbbilldrill(rdram, ctx);
        goto after_11;
    // 0x808008A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x808008AC: b           L_80800A30
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800A30;
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008B4:
    // 0x808008B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B8: jal         0x80096394
    // 0x808008BC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80096394(rdram, ctx);
        goto after_12;
    // 0x808008BC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_12:
    // 0x808008C0: jal         0x800F2100
    // 0x808008C4: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    mlAbsF(rdram, ctx);
        goto after_13;
    // 0x808008C4: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_13:
    // 0x808008C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808008CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008D0: nop

    // 0x808008D4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808008D8: nop

    // 0x808008DC: bc1fl       L_808008F8
    if (!c1cs) {
        // 0x808008E0: sb          $zero, 0x15D($s0)
        MEM_B(0X15D, ctx->r16) = 0;
            goto L_808008F8;
    }
    goto skip_0;
    // 0x808008E0: sb          $zero, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = 0;
    skip_0:
    // 0x808008E4: lbu         $t8, 0x15D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X15D);
    // 0x808008E8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x808008EC: b           L_808008F8
    // 0x808008F0: sb          $t9, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = ctx->r25;
        goto L_808008F8;
    // 0x808008F0: sb          $t9, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = ctx->r25;
    // 0x808008F4: sb          $zero, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = 0;
L_808008F8:
    // 0x808008F8: jal         0x808005C0
    // 0x808008FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005C0_bsbbilldrill(rdram, ctx);
        goto after_14;
    // 0x808008FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800900: jal         0x8009BB50
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_15;
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800908: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080090C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800910: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800914: nop

    // 0x80800918: bc1f        L_80800928
    if (!c1cs) {
        // 0x8080091C: nop
    
            goto L_80800928;
    }
    // 0x8080091C: nop

    // 0x80800920: jal         0x80095760
    // 0x80800924: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    baflag_set(rdram, ctx);
        goto after_16;
    // 0x80800924: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_16:
L_80800928:
    // 0x80800928: jal         0x8008E35C
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_17;
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800930: beq         $v0, $zero, L_80800944
    if (ctx->r2 == 0) {
        // 0x80800934: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800944;
    }
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800938: addiu       $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
    // 0x8080093C: b           L_80800A2C
    // 0x80800940: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
        goto L_80800A2C;
    // 0x80800940: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
L_80800944:
    // 0x80800944: jal         0x8008DF8C
    // 0x80800948: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    func_8008DF8C(rdram, ctx);
        goto after_18;
    // 0x80800948: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    after_18:
    // 0x8080094C: bne         $v0, $zero, L_80800964
    if (ctx->r2 != 0) {
        // 0x80800950: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800964;
    }
    // 0x80800950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800954: lbu         $t1, 0x15D($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X15D);
    // 0x80800958: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x8080095C: bnel        $at, $zero, L_80800A30
    if (ctx->r1 != 0) {
        // 0x80800960: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A30;
    }
    goto skip_1;
    // 0x80800960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_80800964:
    // 0x80800964: jal         0x800954E8
    // 0x80800968: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800954E8(rdram, ctx);
        goto after_19;
    // 0x80800968: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_19:
    // 0x8080096C: beq         $v0, $zero, L_80800980
    if (ctx->r2 == 0) {
        // 0x80800970: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800980;
    }
    // 0x80800970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800974: addiu       $t2, $zero, 0x72
    ctx->r10 = ADD32(0, 0X72);
    // 0x80800978: b           L_80800A2C
    // 0x8080097C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
        goto L_80800A2C;
    // 0x8080097C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_80800980:
    // 0x80800980: jal         0x808002DC
    // 0x80800984: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808002DC_bsbbilldrill(rdram, ctx);
        goto after_20;
    // 0x80800984: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_20:
    // 0x80800988: b           L_80800A30
    // 0x8080098C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800A30;
    // 0x8080098C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800990:
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800994: jal         0x80095774
    // 0x80800998: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    baflag_clear(rdram, ctx);
        goto after_21;
    // 0x80800998: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_21:
    // 0x8080099C: jal         0x808005C0
    // 0x808009A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005C0_bsbbilldrill(rdram, ctx);
        goto after_22;
    // 0x808009A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808009A4: jal         0x80800250
    // 0x808009A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800250_bsbbilldrill(rdram, ctx);
        goto after_23;
    // 0x808009A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808009AC: jal         0x80800100
    // 0x808009B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800100_bsbbilldrill(rdram, ctx);
        goto after_24;
    // 0x808009B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808009B4: jal         0x8080019C
    // 0x808009B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080019C_bsbbilldrill(rdram, ctx);
        goto after_25;
    // 0x808009B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808009BC: jal         0x80800008
    // 0x808009C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800008_bsbbilldrill(rdram, ctx);
        goto after_26;
    // 0x808009C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009C8: jal         0x800852F0
    // 0x808009CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_27;
    // 0x808009CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x808009D0: beq         $v0, $zero, L_80800A2C
    if (ctx->r2 == 0) {
        // 0x808009D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A2C;
    }
    // 0x808009D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D8: jal         0x808002DC
    // 0x808009DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808002DC_bsbbilldrill(rdram, ctx);
        goto after_28;
    // 0x808009DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_28:
    // 0x808009E0: b           L_80800A30
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800A30;
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808009E8:
    // 0x808009E8: jal         0x800841D8
    // 0x808009EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_29;
    // 0x808009EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x808009F0: jal         0x8008E35C
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_30;
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x808009F8: beq         $v0, $zero, L_80800A04
    if (ctx->r2 == 0) {
        // 0x808009FC: addiu       $t3, $zero, 0x4C
        ctx->r11 = ADD32(0, 0X4C);
            goto L_80800A04;
    }
    // 0x808009FC: addiu       $t3, $zero, 0x4C
    ctx->r11 = ADD32(0, 0X4C);
    // 0x80800A00: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_80800A04:
    // 0x80800A04: jal         0x8008E078
    // 0x80800A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_31;
    // 0x80800A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800A0C: beq         $v0, $zero, L_80800A2C
    if (ctx->r2 == 0) {
        // 0x80800A10: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A2C;
    }
    // 0x80800A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A14: lui         $a2, 0x3FF3
    ctx->r6 = S32(0X3FF3 << 16);
    // 0x80800A18: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800A1C: jal         0x8008CF1C
    // 0x80800A20: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_32;
    // 0x80800A20: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_32:
    // 0x80800A24: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x80800A28: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80800A2C:
    // 0x80800A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A30:
    // 0x80800A30: jal         0x8009E5C8
    // 0x80800A34: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    bs_setState(rdram, ctx);
        goto after_33;
    // 0x80800A34: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_33:
    // 0x80800A38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800A3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800A40: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800A44: jr          $ra
    // 0x80800A48: nop

    return;
    // 0x80800A48: nop

;}
RECOMP_FUNC void _sumissilehome_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A780: syscall     850
    recomp_syscall_handler(rdram, ctx, 0x8008A780);
    return;
    // 0x8008A784: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _chquiz_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800877F0: syscall     629
    recomp_syscall_handler(rdram, ctx, 0x800877F0);
    return;
    // 0x800877F4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8010D278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D278: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010D27C: jr          $ra
    // 0x8010D280: lw          $v0, 0x6F60($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6F60);
    return;
    // 0x8010D280: lw          $v0, 0x6F60($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6F60);
;}
RECOMP_FUNC void func_800C5F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5F40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C5F44: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800C5F48: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800C5F4C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C5F50: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800C5F54: lh          $a3, 0x14($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X14);
    // 0x800C5F58: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x800C5F5C: lw          $a1, 0xC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XC);
    // 0x800C5F60: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C5F64: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x800C5F68: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800C5F6C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800C5F70: jal         0x800C5EB8
    // 0x800C5F74: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_800C5EB8(rdram, ctx);
        goto after_0;
    // 0x800C5F74: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x800C5F78: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5F7C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800C5F80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C5F84: jr          $ra
    // 0x800C5F88: nop

    return;
    // 0x800C5F88: nop

;}
RECOMP_FUNC void func_80800100_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800108: jal         0x8009EF1C
    // 0x8080010C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x8080010C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800110: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800114: jal         0x8009EF10
    // 0x80800118: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x80800118: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080011C: bne         $v0, $zero, L_80800138
    if (ctx->r2 != 0) {
        // 0x80800120: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_80800138;
    }
    // 0x80800120: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800124: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800128: jal         0x8009B9B0
    // 0x8080012C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x8080012C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800130: b           L_80800158
    // 0x80800134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800158;
    // 0x80800134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800138:
    // 0x80800138: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080013C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800140: jal         0x800F1214
    // 0x80800144: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x80800144: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    after_3:
    // 0x80800148: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080014C: jal         0x8009B9B0
    // 0x80800150: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800150: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800158:
    // 0x80800158: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080015C: jr          $ra
    // 0x80800160: nop

    return;
    // 0x80800160: nop

;}
RECOMP_FUNC void bsrest_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007D0: jal         0x80800718
    // 0x808007D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bsrest_entrypoint_15(rdram, ctx);
        goto after_0;
    // 0x808007D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808007D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007E0: jr          $ra
    // 0x808007E4: nop

    return;
    // 0x808007E4: nop

;}
RECOMP_FUNC void func_800E35E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E35E0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800E35E4: addiu       $t0, $t0, -0x2B90
    ctx->r8 = ADD32(ctx->r8, -0X2B90);
    // 0x800E35E8: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x800E35EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800E35F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E35F4: beq         $v0, $zero, L_800E3604
    if (ctx->r2 == 0) {
        // 0x800E35F8: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_800E3604;
    }
    // 0x800E35F8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800E35FC: b           L_800E3614
    // 0x800E3600: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
        goto L_800E3614;
    // 0x800E3600: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_800E3604:
    // 0x800E3604: lw          $t6, 0x84($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X84);
    // 0x800E3608: lh          $t1, 0x8($t6)
    ctx->r9 = MEM_H(ctx->r14, 0X8);
    // 0x800E360C: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x800E3610: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
L_800E3614:
    // 0x800E3614: lh          $v0, 0x2($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X2);
    // 0x800E3618: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800E361C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800E3620: beql        $v0, $zero, L_800E3634
    if (ctx->r2 == 0) {
        // 0x800E3624: lw          $t8, 0x84($t0)
        ctx->r24 = MEM_W(ctx->r8, 0X84);
            goto L_800E3634;
    }
    goto skip_0;
    // 0x800E3624: lw          $t8, 0x84($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X84);
    skip_0:
    // 0x800E3628: b           L_800E3640
    // 0x800E362C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800E3640;
    // 0x800E362C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800E3630: lw          $t8, 0x84($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X84);
L_800E3634:
    // 0x800E3634: lh          $v1, 0xA($t8)
    ctx->r3 = MEM_H(ctx->r24, 0XA);
    // 0x800E3638: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800E363C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_800E3640:
    // 0x800E3640: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800E3644: bgez        $t1, L_800E3654
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800E3648: sra         $t4, $t1, 1
        ctx->r12 = S32(SIGNED(ctx->r9) >> 1);
            goto L_800E3654;
    }
    // 0x800E3648: sra         $t4, $t1, 1
    ctx->r12 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800E364C: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x800E3650: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_800E3654:
    // 0x800E3654: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800E3658: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800E365C: lw          $t6, 0x4($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X4);
    // 0x800E3660: bgez        $v1, L_800E3670
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800E3664: sra         $t7, $v1, 1
        ctx->r15 = S32(SIGNED(ctx->r3) >> 1);
            goto L_800E3670;
    }
    // 0x800E3664: sra         $t7, $v1, 1
    ctx->r15 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800E3668: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x800E366C: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_800E3670:
    // 0x800E3670: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800E3674: jal         0x800E32CC
    // 0x800E3678: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    func_800E32CC(rdram, ctx);
        goto after_0;
    // 0x800E3678: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    after_0:
    // 0x800E367C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3680: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800E3684: jr          $ra
    // 0x800E3688: nop

    return;
    // 0x800E3688: nop

;}
RECOMP_FUNC void func_808013C4_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808013C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808013D0: jal         0x80100094
    // 0x808013D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808013D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808013D8: lbu         $t6, 0x55($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X55);
    // 0x808013DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808013E0: beql        $t6, $at, L_80801458
    if (ctx->r14 == ctx->r1) {
        // 0x808013E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801458;
    }
    goto skip_0;
    // 0x808013E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808013E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808013EC: lwc1        $f6, 0x48($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X48);
    // 0x808013F0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x808013F4: nop

    // 0x808013F8: bc1fl       L_80801458
    if (!c1cs) {
        // 0x808013FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801458;
    }
    goto skip_1;
    // 0x808013FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80801400: jal         0x800C0638
    // 0x80801404: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800C0638(rdram, ctx);
        goto after_1;
    // 0x80801404: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801408: bne         $v0, $zero, L_80801454
    if (ctx->r2 != 0) {
        // 0x8080140C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80801454;
    }
    // 0x8080140C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801410: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801414: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80801418: jal         0x80800F34
    // 0x8080141C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_2;
    // 0x8080141C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80801420: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801424: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801428: addiu       $a1, $zero, 0xF9C
    ctx->r5 = ADD32(0, 0XF9C);
    // 0x8080142C: lbu         $t7, 0x54($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X54);
    // 0x80801430: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801434: bnel        $t7, $zero, L_80801458
    if (ctx->r15 != 0) {
        // 0x80801438: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801458;
    }
    goto skip_2;
    // 0x80801438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8080143C: jal         0x8080238C
    // 0x80801440: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8080238C_chboilerboss(rdram, ctx);
        goto after_3;
    // 0x80801440: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_3:
    // 0x80801444: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801448: lbu         $t8, 0x54($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X54);
    // 0x8080144C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80801450: sb          $t9, 0x54($v1)
    MEM_B(0X54, ctx->r3) = ctx->r25;
L_80801454:
    // 0x80801454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801458:
    // 0x80801458: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080145C: jr          $ra
    // 0x80801460: nop

    return;
    // 0x80801460: nop

;}
RECOMP_FUNC void func_800FE7A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE7A8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FE7AC: lh          $t6, 0x59C8($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X59C8);
    // 0x800FE7B0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800FE7B4: bne         $a0, $t6, L_800FE7C4
    if (ctx->r4 != ctx->r14) {
        // 0x800FE7B8: nop
    
            goto L_800FE7C4;
    }
    // 0x800FE7B8: nop

    // 0x800FE7BC: jr          $ra
    // 0x800FE7C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800FE7C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FE7C4:
    // 0x800FE7C4: lw          $t7, 0x5A40($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5A40);
    // 0x800FE7C8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FE7CC: addiu       $v1, $v1, 0x5A3C
    ctx->r3 = ADD32(ctx->r3, 0X5A3C);
    // 0x800FE7D0: blez        $t7, L_800FE814
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800FE7D4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800FE814;
    }
    // 0x800FE7D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FE7D8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800FE7DC: addiu       $a1, $a1, 0x5A20
    ctx->r5 = ADD32(ctx->r5, 0X5A20);
    // 0x800FE7E0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_800FE7E4:
    // 0x800FE7E4: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x800FE7E8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800FE7EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800FE7F0: beq         $t8, $zero, L_800FE80C
    if (ctx->r24 == 0) {
        // 0x800FE7F4: addu        $t0, $a1, $t9
        ctx->r8 = ADD32(ctx->r5, ctx->r25);
            goto L_800FE80C;
    }
    // 0x800FE7F4: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x800FE7F8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800FE7FC: bne         $a0, $t1, L_800FE80C
    if (ctx->r4 != ctx->r9) {
        // 0x800FE800: nop
    
            goto L_800FE80C;
    }
    // 0x800FE800: nop

    // 0x800FE804: jr          $ra
    // 0x800FE808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800FE808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FE80C:
    // 0x800FE80C: bne         $v0, $a2, L_800FE7E4
    if (ctx->r2 != ctx->r6) {
        // 0x800FE810: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800FE7E4;
    }
    // 0x800FE810: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800FE814:
    // 0x800FE814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FE818: jr          $ra
    // 0x800FE81C: nop

    return;
    // 0x800FE81C: nop

;}
RECOMP_FUNC void func_8001EB10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EB10: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001EB14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001EB18: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8001EB1C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8001EB20: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8001EB24: lw          $t8, 0x11DC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11DC);
    // 0x8001EB28: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8001EB2C: sw          $t7, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->r15;
    // 0x8001EB30: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8001EB34: lw          $t9, 0x11DC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11DC);
    // 0x8001EB38: sw          $zero, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = 0;
    // 0x8001EB3C: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8001EB40: lw          $t1, 0x11DC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X11DC);
    // 0x8001EB44: addiu       $t0, $zero, 0x3E80
    ctx->r8 = ADD32(0, 0X3E80);
    // 0x8001EB48: sw          $t0, 0x48($t1)
    MEM_W(0X48, ctx->r9) = ctx->r8;
    // 0x8001EB4C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8001EB50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001EB54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001EB58: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8001EB5C: lw          $a2, 0xC($t2)
    ctx->r6 = MEM_W(ctx->r10, 0XC);
    // 0x8001EB60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001EB64: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8001EB68: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8001EB6C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8001EB70: jal         0x80020EE4
    // 0x8001EB74: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_80020EE4(rdram, ctx);
        goto after_0;
    // 0x8001EB74: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_0:
    // 0x8001EB78: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8001EB7C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8001EB80: lw          $t6, 0x11DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11DC);
    // 0x8001EB84: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8001EB88: sw          $t5, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->r13;
    // 0x8001EB8C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8001EB90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001EB94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001EB98: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8001EB9C: lw          $a2, 0xC($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XC);
    // 0x8001EBA0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001EBA4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8001EBA8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001EBAC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001EBB0: jal         0x80020EE4
    // 0x8001EBB4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_80020EE4(rdram, ctx);
        goto after_1;
    // 0x8001EBB4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x8001EBB8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8001EBBC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001EBC0: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x8001EBC4: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8001EBC8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8001EBCC: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x8001EBD0: jal         0x800263C0
    // 0x8001EBD4: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    func_800263C0(rdram, ctx);
        goto after_2;
    // 0x8001EBD4: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    after_2:
    // 0x8001EBD8: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8001EBDC: lw          $t1, 0x11DC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X11DC);
    // 0x8001EBE0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001EBE4: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x8001EBE8: sw          $t2, 0x11D8($at)
    MEM_W(0X11D8, ctx->r1) = ctx->r10;
    // 0x8001EBEC: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8001EBF0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8001EBF4: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x8001EBF8: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8001EBFC: sltiu       $at, $t5, 0x2
    ctx->r1 = ctx->r13 < 0X2 ? 1 : 0;
    // 0x8001EC00: bne         $at, $zero, L_8001EC5C
    if (ctx->r1 != 0) {
        // 0x8001EC04: nop
    
            goto L_8001EC5C;
    }
    // 0x8001EC04: nop

L_8001EC08:
    // 0x8001EC08: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8001EC0C: lw          $t6, 0x11DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11DC);
    // 0x8001EC10: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8001EC14: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8001EC18: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8001EC1C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8001EC20: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8001EC24: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8001EC28: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8001EC2C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8001EC30: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8001EC34: jal         0x80020E40
    // 0x8001EC38: addiu       $a1, $t1, -0x48
    ctx->r5 = ADD32(ctx->r9, -0X48);
    func_80020E40(rdram, ctx);
        goto after_3;
    // 0x8001EC38: addiu       $a1, $t1, -0x48
    ctx->r5 = ADD32(ctx->r9, -0X48);
    after_3:
    // 0x8001EC3C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8001EC40: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8001EC44: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8001EC48: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x8001EC4C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8001EC50: sltu        $at, $t3, $t5
    ctx->r1 = ctx->r11 < ctx->r13 ? 1 : 0;
    // 0x8001EC54: bne         $at, $zero, L_8001EC08
    if (ctx->r1 != 0) {
        // 0x8001EC58: nop
    
            goto L_8001EC08;
    }
    // 0x8001EC58: nop

L_8001EC5C:
    // 0x8001EC5C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8001EC60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001EC64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001EC68: lhu         $t7, 0x10($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X10);
    // 0x8001EC6C: lw          $a2, 0xC($t6)
    ctx->r6 = MEM_W(ctx->r14, 0XC);
    // 0x8001EC70: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8001EC74: jal         0x80020EE4
    // 0x8001EC78: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_80020EE4(rdram, ctx);
        goto after_4;
    // 0x8001EC78: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_4:
    // 0x8001EC7C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001EC80: sw          $v0, -0x15DC($at)
    MEM_W(-0X15DC, ctx->r1) = ctx->r2;
    // 0x8001EC84: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8001EC88: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8001EC8C: lhu         $t9, 0x10($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X10);
    // 0x8001EC90: beq         $t9, $zero, L_8001ECD4
    if (ctx->r25 == 0) {
        // 0x8001EC94: nop
    
            goto L_8001ECD4;
    }
    // 0x8001EC94: nop

L_8001EC98:
    // 0x8001EC98: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8001EC9C: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8001ECA0: lw          $t1, -0x15DC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X15DC);
    // 0x8001ECA4: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x8001ECA8: addiu       $t0, $zero, 0x7FFF
    ctx->r8 = ADD32(0, 0X7FFF);
    // 0x8001ECAC: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x8001ECB0: sh          $t0, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r8;
    // 0x8001ECB4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8001ECB8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8001ECBC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001ECC0: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8001ECC4: lhu         $t8, 0x10($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X10);
    // 0x8001ECC8: sltu        $at, $t6, $t8
    ctx->r1 = ctx->r14 < ctx->r24 ? 1 : 0;
    // 0x8001ECCC: bne         $at, $zero, L_8001EC98
    if (ctx->r1 != 0) {
        // 0x8001ECD0: nop
    
            goto L_8001EC98;
    }
    // 0x8001ECD0: nop

L_8001ECD4:
    // 0x8001ECD4: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8001ECD8: lw          $t9, 0x11DC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11DC);
    // 0x8001ECDC: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x8001ECE0: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8001ECE4: lw          $t1, 0x11DC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X11DC);
    // 0x8001ECE8: lui         $t2, 0x8002
    ctx->r10 = S32(0X8002 << 16);
    // 0x8001ECEC: addiu       $t2, $t2, -0x1298
    ctx->r10 = ADD32(ctx->r10, -0X1298);
    // 0x8001ECF0: sw          $t2, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r10;
    // 0x8001ECF4: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x8001ECF8: lw          $t4, 0x11DC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X11DC);
    // 0x8001ECFC: sw          $t4, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r12;
    // 0x8001ED00: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001ED04: jal         0x800267F0
    // 0x8001ED08: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    func_800267F0(rdram, ctx);
        goto after_5;
    // 0x8001ED08: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    after_5:
    // 0x8001ED0C: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x8001ED10: sh          $t0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r8;
    // 0x8001ED14: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8001ED18: lw          $t3, 0x11DC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X11DC);
    // 0x8001ED1C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8001ED20: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001ED24: addiu       $a0, $t3, 0x14
    ctx->r4 = ADD32(ctx->r11, 0X14);
    // 0x8001ED28: jal         0x80026500
    // 0x8001ED2C: lw          $a2, 0x48($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X48);
    func_80026500(rdram, ctx);
        goto after_6;
    // 0x8001ED2C: lw          $a2, 0x48($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X48);
    after_6:
    // 0x8001ED30: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x8001ED34: lw          $t5, 0x11DC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X11DC);
    // 0x8001ED38: addiu       $a0, $t5, 0x14
    ctx->r4 = ADD32(ctx->r13, 0X14);
    // 0x8001ED3C: jal         0x8002645C
    // 0x8001ED40: addiu       $a1, $t5, 0x28
    ctx->r5 = ADD32(ctx->r13, 0X28);
    func_8002645C(rdram, ctx);
        goto after_7;
    // 0x8001ED40: addiu       $a1, $t5, 0x28
    ctx->r5 = ADD32(ctx->r13, 0X28);
    after_7:
    // 0x8001ED44: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001ED48: lw          $t7, 0x11DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11DC);
    // 0x8001ED4C: sw          $v0, 0x4C($t7)
    MEM_W(0X4C, ctx->r15) = ctx->r2;
    // 0x8001ED50: b           L_8001ED58
    // 0x8001ED54: nop

        goto L_8001ED58;
    // 0x8001ED54: nop

L_8001ED58:
    // 0x8001ED58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001ED5C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8001ED60: jr          $ra
    // 0x8001ED64: nop

    return;
    // 0x8001ED64: nop

;}
RECOMP_FUNC void func_800F5378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5378: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F537C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5380: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5388: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F538C: jal         0x8008CABC
    // 0x800F5390: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x800F5390: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F539C: jr          $ra
    // 0x800F53A0: nop

    return;
    // 0x800F53A0: nop

;}
RECOMP_FUNC void _glsplinefind_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088480: syscall     687
    recomp_syscall_handler(rdram, ctx, 0x80088480);
    return;
    // 0x80088484: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _subaddiefade_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089CA0: syscall     808
    recomp_syscall_handler(rdram, ctx, 0x80089CA0);
    return;
    // 0x80089CA4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void sucoaster_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801054: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801058: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080105C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801060: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80801064: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801068: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080106C: jal         0x80100094
    // 0x80801070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801074: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080107C: jal         0x80102424
    // 0x80801080: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80801080: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80801084: lbu         $t7, 0x19($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X19);
    // 0x80801088: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x8080108C: sb          $t8, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r24;
    // 0x80801090: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80801094: addiu       $t0, $t9, -0x2
    ctx->r8 = ADD32(ctx->r25, -0X2);
    // 0x80801098: sltiu       $at, $t0, 0x11
    ctx->r1 = ctx->r8 < 0X11 ? 1 : 0;
    // 0x8080109C: beq         $at, $zero, L_808014AC
    if (ctx->r1 == 0) {
        // 0x808010A0: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_808014AC;
    }
    // 0x808010A0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808010A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X281C) << 16);
    // 0x808010A8: addu        $at, $at, $t0
    gpr jr_addend_808010B0 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x808010AC: lw          $t0, 0x281C($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3274, 0X281C));
    // 0x808010B0: jr          $t0
    // 0x808010B4: nop

    switch (jr_addend_808010B0 >> 2) {
        case 0: goto L_808010B8; break;
        case 1: goto L_808010FC; break;
        case 2: goto L_80801184; break;
        case 3: goto L_8080120C; break;
        case 4: goto L_80801234; break;
        case 5: goto L_80801280; break;
        case 6: goto L_8080129C; break;
        case 7: goto L_80801310; break;
        case 8: goto L_80801334; break;
        case 9: goto L_80801398; break;
        case 10: goto L_808013A4; break;
        case 11: goto L_808014AC; break;
        case 12: goto L_808013B8; break;
        case 13: goto L_80801408; break;
        case 14: goto L_808014AC; break;
        case 15: goto L_808014AC; break;
        case 16: goto L_80801424; break;
        default: switch_error(__func__, 0x808010B0, 0x8080281C);
    }
    // 0x808010B4: nop

L_808010B8:
    // 0x808010B8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808010BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808010C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X2860) << 16);
    // 0x808010C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010C8: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x808010CC: lw          $t1, 0x18($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X18);
    // 0x808010D0: sll         $t3, $t1, 6
    ctx->r11 = S32(ctx->r9 << 6);
    // 0x808010D4: bgez        $t3, L_808010EC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808010D8: nop
    
            goto L_808010EC;
    }
    // 0x808010D8: nop

    // 0x808010DC: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808010E0: lwc1        $f8, 0x2860($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2860));
    // 0x808010E4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808010E8: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_808010EC:
    // 0x808010EC: jal         0x80800D1C
    // 0x808010F0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    sucoaster_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808010F0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x808010F4: b           L_808014B0
    // 0x808010F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014B0;
    // 0x808010F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808010FC:
    // 0x808010FC: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80801100: srl         $t4, $a0, 28
    ctx->r12 = S32(U32(ctx->r4) >> 28);
    // 0x80801104: jal         0x8008A248
    // 0x80801108: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    _sucoasterdata_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80801108: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_3:
    // 0x8080110C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80801110: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80801114: srl         $t5, $a0, 28
    ctx->r13 = S32(U32(ctx->r4) >> 28);
    // 0x80801118: jal         0x8008A250
    // 0x8080111C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    _sucoasterdata_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x8080111C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_4:
    // 0x80801120: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80801124: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80801128: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8080112C: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80801130: jal         0x800DC178
    // 0x80801134: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80801134: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    after_5:
    // 0x80801138: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080113C: jal         0x80800D1C
    // 0x80801140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x80801140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801144: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801148: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080114C: nop

    // 0x80801150: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80801154: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80801158: srl         $t7, $a0, 28
    ctx->r15 = S32(U32(ctx->r4) >> 28);
    // 0x8080115C: jal         0x8008A248
    // 0x80801160: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    _sucoasterdata_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80801160: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_7:
    // 0x80801164: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80801168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080116C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80801170: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80801174: jal         0x808014C4
    // 0x80801178: nop

    sucoaster_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80801178: nop

    after_8:
    // 0x8080117C: b           L_808014B0
    // 0x80801180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014B0;
    // 0x80801180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801184:
    // 0x80801184: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80801188: srl         $t8, $a0, 28
    ctx->r24 = S32(U32(ctx->r4) >> 28);
    // 0x8080118C: jal         0x8008A250
    // 0x80801190: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    _sucoasterdata_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x80801190: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_9:
    // 0x80801194: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80801198: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x8080119C: srl         $t9, $a0, 28
    ctx->r25 = S32(U32(ctx->r4) >> 28);
    // 0x808011A0: jal         0x8008A258
    // 0x808011A4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    _sucoasterdata_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x808011A4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_10:
    // 0x808011A8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x808011AC: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x808011B0: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x808011B4: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808011B8: jal         0x800DC178
    // 0x808011BC: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x808011BC: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_11:
    // 0x808011C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808011C4: jal         0x80800D1C
    // 0x808011C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_6(rdram, ctx);
        goto after_12;
    // 0x808011C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808011CC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808011D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808011D4: nop

    // 0x808011D8: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x808011DC: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x808011E0: srl         $t1, $a0, 28
    ctx->r9 = S32(U32(ctx->r4) >> 28);
    // 0x808011E4: jal         0x8008A250
    // 0x808011E8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    _sucoasterdata_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x808011E8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_13:
    // 0x808011EC: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x808011F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011F4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808011F8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808011FC: jal         0x808014C4
    // 0x80801200: nop

    sucoaster_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x80801200: nop

    after_14:
    // 0x80801204: b           L_808014B0
    // 0x80801208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014B0;
    // 0x80801208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080120C:
    // 0x8080120C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801214: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801218: jal         0x80800D1C
    // 0x8080121C: nop

    sucoaster_entrypoint_6(rdram, ctx);
        goto after_15;
    // 0x8080121C: nop

    after_15:
    // 0x80801220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801224: jal         0x8080264C
    // 0x80801228: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8080264C_sucoaster(rdram, ctx);
        goto after_16;
    // 0x80801228: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_16:
    // 0x8080122C: b           L_808014AC
    // 0x80801230: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
        goto L_808014AC;
    // 0x80801230: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_80801234:
    // 0x80801234: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801238: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080123C: jal         0x800D9058
    // 0x80801240: nop

    func_800D9058(rdram, ctx);
        goto after_17;
    // 0x80801240: nop

    after_17:
    // 0x80801244: lhu         $t4, 0x6E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6E);
    // 0x80801248: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080124C: andi        $t3, $v0, 0x1FF
    ctx->r11 = ctx->r2 & 0X1FF;
    // 0x80801250: andi        $t5, $t4, 0xFE00
    ctx->r13 = ctx->r12 & 0XFE00;
    // 0x80801254: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80801258: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
    // 0x8080125C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80801260: lbu         $t8, 0x18($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X18);
    // 0x80801264: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080126C: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x80801270: jal         0x80800D1C
    // 0x80801274: sb          $t9, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r25;
    sucoaster_entrypoint_6(rdram, ctx);
        goto after_18;
    // 0x80801274: sb          $t9, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r25;
    after_18:
    // 0x80801278: b           L_808014AC
    // 0x8080127C: sb          $zero, 0x16($s1)
    MEM_B(0X16, ctx->r17) = 0;
        goto L_808014AC;
    // 0x8080127C: sb          $zero, 0x16($s1)
    MEM_B(0X16, ctx->r17) = 0;
L_80801280:
    // 0x80801280: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801288: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080128C: jal         0x80800D1C
    // 0x80801290: nop

    sucoaster_entrypoint_6(rdram, ctx);
        goto after_19;
    // 0x80801290: nop

    after_19:
    // 0x80801294: b           L_808014B0
    // 0x80801298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014B0;
    // 0x80801298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080129C:
    // 0x8080129C: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x808012A0: srl         $t0, $a0, 28
    ctx->r8 = S32(U32(ctx->r4) >> 28);
    // 0x808012A4: jal         0x8008A258
    // 0x808012A8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    _sucoasterdata_entrypoint_4(rdram, ctx);
        goto after_20;
    // 0x808012A8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_20:
    // 0x808012AC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x808012B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012B4: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808012B8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808012BC: jal         0x80800D1C
    // 0x808012C0: nop

    sucoaster_entrypoint_6(rdram, ctx);
        goto after_21;
    // 0x808012C0: nop

    after_21:
    // 0x808012C4: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x808012C8: srl         $t1, $a0, 28
    ctx->r9 = S32(U32(ctx->r4) >> 28);
    // 0x808012CC: jal         0x8008A250
    // 0x808012D0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    _sucoasterdata_entrypoint_3(rdram, ctx);
        goto after_22;
    // 0x808012D0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_22:
    // 0x808012D4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x808012D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012DC: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808012E0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808012E4: jal         0x808014C4
    // 0x808012E8: nop

    sucoaster_entrypoint_11(rdram, ctx);
        goto after_23;
    // 0x808012E8: nop

    after_23:
    // 0x808012EC: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x808012F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012F4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x808012F8: bltzl       $t3, L_808014B0
    if (SIGNED(ctx->r11) < 0) {
        // 0x808012FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808014B0;
    }
    goto skip_0;
    // 0x808012FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801300: jal         0x8080264C
    // 0x80801304: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8080264C_sucoaster(rdram, ctx);
        goto after_24;
    // 0x80801304: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_24:
    // 0x80801308: b           L_808014AC
    // 0x8080130C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
        goto L_808014AC;
    // 0x8080130C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_80801310:
    // 0x80801310: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801314: lbu         $t5, 0x19($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X19);
    // 0x80801318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080131C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801320: andi        $t6, $t5, 0xFFDF
    ctx->r14 = ctx->r13 & 0XFFDF;
    // 0x80801324: jal         0x80800D1C
    // 0x80801328: sb          $t6, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r14;
    sucoaster_entrypoint_6(rdram, ctx);
        goto after_25;
    // 0x80801328: sb          $t6, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r14;
    after_25:
    // 0x8080132C: b           L_808014B0
    // 0x80801330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014B0;
    // 0x80801330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801334:
    // 0x80801334: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80801338: srl         $t7, $a0, 28
    ctx->r15 = S32(U32(ctx->r4) >> 28);
    // 0x8080133C: jal         0x8008A258
    // 0x80801340: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    _sucoasterdata_entrypoint_4(rdram, ctx);
        goto after_26;
    // 0x80801340: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_26:
    // 0x80801344: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80801348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080134C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80801350: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80801354: jal         0x80800D1C
    // 0x80801358: nop

    sucoaster_entrypoint_6(rdram, ctx);
        goto after_27;
    // 0x80801358: nop

    after_27:
    // 0x8080135C: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80801360: srl         $t8, $a0, 28
    ctx->r24 = S32(U32(ctx->r4) >> 28);
    // 0x80801364: jal         0x8008A250
    // 0x80801368: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    _sucoasterdata_entrypoint_3(rdram, ctx);
        goto after_28;
    // 0x80801368: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_28:
    // 0x8080136C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80801370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801374: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80801378: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8080137C: jal         0x808014C4
    // 0x80801380: nop

    sucoaster_entrypoint_11(rdram, ctx);
        goto after_29;
    // 0x80801380: nop

    after_29:
    // 0x80801384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801388: jal         0x8080230C
    // 0x8080138C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8080230C_sucoaster(rdram, ctx);
        goto after_30;
    // 0x8080138C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_30:
    // 0x80801390: b           L_808014AC
    // 0x80801394: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
        goto L_808014AC;
    // 0x80801394: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_80801398:
    // 0x80801398: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080139C: b           L_808014AC
    // 0x808013A0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
        goto L_808014AC;
    // 0x808013A0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_808013A4:
    // 0x808013A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013A8: jal         0x80802260
    // 0x808013AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80802260_sucoaster(rdram, ctx);
        goto after_31;
    // 0x808013AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_31:
    // 0x808013B0: b           L_808014B0
    // 0x808013B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014B0;
    // 0x808013B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808013B8:
    // 0x808013B8: jal         0x8010A570
    // 0x808013BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_32;
    // 0x808013BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x808013C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013C4: jal         0x80800D1C
    // 0x808013C8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    sucoaster_entrypoint_6(rdram, ctx);
        goto after_33;
    // 0x808013C8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_33:
    // 0x808013CC: lbu         $t0, 0x18($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X18);
    // 0x808013D0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808013D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808013D8: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x808013DC: sb          $t1, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r9;
    // 0x808013E0: lbu         $t2, 0x64($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X64);
    // 0x808013E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808013E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013EC: andi        $t4, $t2, 0xFFFE
    ctx->r12 = ctx->r10 & 0XFFFE;
    // 0x808013F0: sb          $t4, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r12;
    // 0x808013F4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808013F8: jal         0x80089CB8
    // 0x808013FC: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    _subaddiefade_entrypoint_5(rdram, ctx);
        goto after_34;
    // 0x808013FC: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    after_34:
    // 0x80801400: b           L_808014B0
    // 0x80801404: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014B0;
    // 0x80801404: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801408:
    // 0x80801408: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8080140C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X2864) << 16);
    // 0x80801410: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x80801414: lwc1        $f4, 0x2864($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2864));
    // 0x80801418: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x8080141C: b           L_808014AC
    // 0x80801420: sb          $zero, 0x14($s1)
    MEM_B(0X14, ctx->r17) = 0;
        goto L_808014AC;
    // 0x80801420: sb          $zero, 0x14($s1)
    MEM_B(0X14, ctx->r17) = 0;
L_80801424:
    // 0x80801424: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801428: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080142C: jal         0x800DC298
    // 0x80801430: nop

    func_800DC298(rdram, ctx);
        goto after_35;
    // 0x80801430: nop

    after_35:
    // 0x80801434: lbu         $t6, 0x18($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X18);
    // 0x80801438: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080143C: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x80801440: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80801444: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80801448: sb          $t8, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r24;
    // 0x8080144C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x80801450: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80801454: srl         $t9, $a0, 28
    ctx->r25 = S32(U32(ctx->r4) >> 28);
    // 0x80801458: jal         0x8008A258
    // 0x8080145C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    _sucoasterdata_entrypoint_4(rdram, ctx);
        goto after_36;
    // 0x8080145C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_36:
    // 0x80801460: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80801464: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X2868) << 16);
    // 0x80801468: lwc1        $f16, 0x2868($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2868));
    // 0x8080146C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80801470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801474: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80801478: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080147C: jal         0x80800D1C
    // 0x80801480: nop

    sucoaster_entrypoint_6(rdram, ctx);
        goto after_37;
    // 0x80801480: nop

    after_37:
    // 0x80801484: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80801488: srl         $t0, $a0, 28
    ctx->r8 = S32(U32(ctx->r4) >> 28);
    // 0x8080148C: jal         0x8008A250
    // 0x80801490: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    _sucoasterdata_entrypoint_3(rdram, ctx);
        goto after_38;
    // 0x80801490: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_38:
    // 0x80801494: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80801498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080149C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808014A0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808014A4: jal         0x808014C4
    // 0x808014A8: nop

    sucoaster_entrypoint_11(rdram, ctx);
        goto after_39;
    // 0x808014A8: nop

    after_39:
L_808014AC:
    // 0x808014AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808014B0:
    // 0x808014B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808014B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808014B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808014BC: jr          $ra
    // 0x808014C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808014C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_808002A4_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002A8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x808002AC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808002B0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x808002B4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808002B8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808002BC: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x808002C0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808002C4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x808002C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808002CC: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_808002D0:
    // 0x808002D0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x808002D4: jal         0x800F2094
    // 0x808002D8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F2094(rdram, ctx);
        goto after_0;
    // 0x808002D8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x808002DC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x808002E0: addiu       $s0, $s0, 0x5A
    ctx->r16 = ADD32(ctx->r16, 0X5A);
    // 0x808002E4: slti        $at, $s0, 0x168
    ctx->r1 = SIGNED(ctx->r16) < 0X168 ? 1 : 0;
    // 0x808002E8: bc1f        L_808002F8
    if (!c1cs) {
        // 0x808002EC: nop
    
            goto L_808002F8;
    }
    // 0x808002EC: nop

    // 0x808002F0: b           L_80800344
    // 0x808002F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800344;
    // 0x808002F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002F8:
    // 0x808002F8: bnel        $at, $zero, L_808002D0
    if (ctx->r1 != 0) {
        // 0x808002FC: mtc1        $s0, $f4
        ctx->f4.u32l = ctx->r16;
            goto L_808002D0;
    }
    goto skip_0;
    // 0x808002FC: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    skip_0:
    // 0x80800300: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80800304: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800308: addiu       $s0, $zero, 0x2D
    ctx->r16 = ADD32(0, 0X2D);
    // 0x8080030C: addiu       $s1, $zero, 0x195
    ctx->r17 = ADD32(0, 0X195);
    // 0x80800310: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
L_80800314:
    // 0x80800314: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80800318: jal         0x800F2094
    // 0x8080031C: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    func_800F2094(rdram, ctx);
        goto after_1;
    // 0x8080031C: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_1:
    // 0x80800320: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80800324: addiu       $s0, $s0, 0x5A
    ctx->r16 = ADD32(ctx->r16, 0X5A);
    // 0x80800328: bc1f        L_80800338
    if (!c1cs) {
        // 0x8080032C: nop
    
            goto L_80800338;
    }
    // 0x8080032C: nop

    // 0x80800330: b           L_80800344
    // 0x80800334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800344;
    // 0x80800334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800338:
    // 0x80800338: bnel        $s0, $s1, L_80800314
    if (ctx->r16 != ctx->r17) {
        // 0x8080033C: mtc1        $s0, $f6
        ctx->f6.u32l = ctx->r16;
            goto L_80800314;
    }
    goto skip_1;
    // 0x8080033C: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    skip_1:
    // 0x80800340: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800344:
    // 0x80800344: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800348: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8080034C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800350: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800354: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800358: jr          $ra
    // 0x8080035C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080035C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _basub_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800851F0: syscall     154
    recomp_syscall_handler(rdram, ctx, 0x800851F0);
    return;
    // 0x800851F4: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void subaddieDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800084: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800088: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080008C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80800090: jal         0x800CBC3C
    // 0x80800094: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800CBC3C(rdram, ctx);
        goto after_0;
    // 0x80800094: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800098: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8080009C: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x808000A0: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x808000A4: lbu         $t0, 0x70($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X70);
    // 0x808000A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000AC: andi        $t1, $t0, 0xFF01
    ctx->r9 = ctx->r8 & 0XFF01;
    // 0x808000B0: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x808000B4: sb          $t2, 0x70($a3)
    MEM_B(0X70, ctx->r7) = ctx->r10;
    // 0x808000B8: lw          $v1, 0x70($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X70);
    // 0x808000BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808000C0: srl         $t3, $v1, 25
    ctx->r11 = S32(U32(ctx->r3) >> 25);
    // 0x808000C4: bne         $t3, $zero, L_808000D4
    if (ctx->r11 != 0) {
        // 0x808000C8: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_808000D4;
    }
    // 0x808000C8: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x808000CC: b           L_80800104
    // 0x808000D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800104;
    // 0x808000D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000D4:
    // 0x808000D4: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    // 0x808000D8: jal         0x800CC338
    // 0x808000DC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800CC338(rdram, ctx);
        goto after_1;
    // 0x808000DC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x808000E0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808000E4: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x808000E8: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x808000EC: lhu         $t8, 0x72($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X72);
    // 0x808000F0: andi        $t7, $t6, 0x3F0
    ctx->r15 = ctx->r14 & 0X3F0;
    // 0x808000F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808000F8: andi        $t0, $t8, 0xFC0F
    ctx->r8 = ctx->r24 & 0XFC0F;
    // 0x808000FC: or          $t9, $t7, $t0
    ctx->r25 = ctx->r15 | ctx->r8;
    // 0x80800100: sh          $t9, 0x72($a3)
    MEM_H(0X72, ctx->r7) = ctx->r25;
L_80800104:
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080010C: jr          $ra
    // 0x80800110: nop

    return;
    // 0x80800110: nop

;}
RECOMP_FUNC void func_80800000_chlavaentrancebridge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1980, 0X210) << 16);
    // 0x80800004: lwc1        $f4, 0x210($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1980, 0X210));
    // 0x80800008: jr          $ra
    // 0x8080000C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8080000C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_800F1418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1418: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800F141C: beq         $at, $zero, L_800F142C
    if (ctx->r1 == 0) {
        // 0x800F1420: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_800F142C;
    }
    // 0x800F1420: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800F1424: jr          $ra
    // 0x800F1428: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800F1428: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800F142C:
    // 0x800F142C: jr          $ra
    // 0x800F1430: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800F1430: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
