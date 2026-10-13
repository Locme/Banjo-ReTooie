#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080000C_chsquits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: lhu         $t6, 0x6E($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X6E);
    // 0x80800018: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080001C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800020: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x80800024: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800028: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8080002C: sh          $t8, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r24;
    // 0x80800030: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800034: jal         0x800DC178
    // 0x80800038: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x80800038: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080003C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800040: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080004C: jr          $ra
    // 0x80800050: nop

    return;
    // 0x80800050: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805044: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80805048: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB530) << 16);
    // 0x8080504C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80805050: jr          $ra
    // 0x80805054: lw          $v0, -0x4AD0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB530));
    return;
    // 0x80805054: lw          $v0, -0x4AD0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB530));
;}
RECOMP_FUNC void func_8080142C_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080142C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801434: lw          $v1, 0x78($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X78);
    // 0x80801438: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080143C: sll         $v0, $v1, 18
    ctx->r2 = S32(ctx->r3 << 18);
    // 0x80801440: srl         $t6, $v0, 30
    ctx->r14 = S32(U32(ctx->r2) >> 30);
    // 0x80801444: beq         $t6, $zero, L_80801468
    if (ctx->r14 == 0) {
        // 0x80801448: nop
    
            goto L_80801468;
    }
    // 0x80801448: nop

    // 0x8080144C: beq         $t6, $at, L_808014A0
    if (ctx->r14 == ctx->r1) {
        // 0x80801450: sll         $v0, $v1, 20
        ctx->r2 = S32(ctx->r3 << 20);
            goto L_808014A0;
    }
    // 0x80801450: sll         $v0, $v1, 20
    ctx->r2 = S32(ctx->r3 << 20);
    // 0x80801454: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801458: beq         $t6, $at, L_808014E0
    if (ctx->r14 == ctx->r1) {
        // 0x8080145C: sll         $t0, $v1, 20
        ctx->r8 = S32(ctx->r3 << 20);
            goto L_808014E0;
    }
    // 0x8080145C: sll         $t0, $v1, 20
    ctx->r8 = S32(ctx->r3 << 20);
    // 0x80801460: b           L_80801520
    // 0x80801464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801520;
    // 0x80801464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801468:
    // 0x80801468: jal         0x800DC0C0
    // 0x8080146C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x8080146C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801470: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X2584) << 16);
    // 0x80801474: lwc1        $f4, 0x2584($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1364, 0X2584));
    // 0x80801478: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080147C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80801480: nop

    // 0x80801484: bc1fl       L_80801520
    if (!c1cs) {
        // 0x80801488: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801520;
    }
    goto skip_0;
    // 0x80801488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080148C: lbu         $t7, 0x7A($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X7A);
    // 0x80801490: andi        $t8, $t7, 0xFFCF
    ctx->r24 = ctx->r15 & 0XFFCF;
    // 0x80801494: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80801498: b           L_8080151C
    // 0x8080149C: sb          $t9, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r25;
        goto L_8080151C;
    // 0x8080149C: sb          $t9, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r25;
L_808014A0:
    // 0x808014A0: srl         $t0, $v0, 29
    ctx->r8 = S32(U32(ctx->r2) >> 29);
    // 0x808014A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808014A8: bne         $t0, $at, L_808014C0
    if (ctx->r8 != ctx->r1) {
        // 0x808014AC: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_808014C0;
    }
    // 0x808014AC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x808014B0: lbu         $t2, 0x7A($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X7A);
    // 0x808014B4: ori         $t3, $t2, 0x30
    ctx->r11 = ctx->r10 | 0X30;
    // 0x808014B8: b           L_8080151C
    // 0x808014BC: sb          $t3, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r11;
        goto L_8080151C;
    // 0x808014BC: sb          $t3, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r11;
L_808014C0:
    // 0x808014C0: lbu         $t7, 0x7A($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X7A);
    // 0x808014C4: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x808014C8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x808014CC: andi        $t6, $t5, 0xE
    ctx->r14 = ctx->r13 & 0XE;
    // 0x808014D0: andi        $t8, $t7, 0xFFF1
    ctx->r24 = ctx->r15 & 0XFFF1;
    // 0x808014D4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x808014D8: b           L_8080151C
    // 0x808014DC: sb          $t9, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r25;
        goto L_8080151C;
    // 0x808014DC: sb          $t9, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r25;
L_808014E0:
    // 0x808014E0: lbu         $t5, 0x7A($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X7A);
    // 0x808014E4: srl         $t1, $t0, 29
    ctx->r9 = S32(U32(ctx->r8) >> 29);
    // 0x808014E8: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x808014EC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x808014F0: andi        $t4, $t3, 0xE
    ctx->r12 = ctx->r11 & 0XE;
    // 0x808014F4: andi        $t7, $t5, 0xFFF1
    ctx->r15 = ctx->r13 & 0XFFF1;
    // 0x808014F8: or          $t6, $t4, $t7
    ctx->r14 = ctx->r12 | ctx->r15;
    // 0x808014FC: sb          $t6, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r14;
    // 0x80801500: lw          $t8, 0x78($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X78);
    // 0x80801504: andi        $t2, $t6, 0xCF
    ctx->r10 = ctx->r14 & 0XCF;
    // 0x80801508: sll         $t9, $t8, 20
    ctx->r25 = S32(ctx->r24 << 20);
    // 0x8080150C: srl         $t0, $t9, 29
    ctx->r8 = S32(U32(ctx->r25) >> 29);
    // 0x80801510: bnel        $t0, $zero, L_80801520
    if (ctx->r8 != 0) {
        // 0x80801514: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801520;
    }
    goto skip_1;
    // 0x80801514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80801518: sb          $t2, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r10;
L_8080151C:
    // 0x8080151C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801520:
    // 0x80801520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801524: jr          $ra
    // 0x80801528: nop

    return;
    // 0x80801528: nop

;}
RECOMP_FUNC void _bskazfly_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083390: syscall     57
    recomp_syscall_handler(rdram, ctx, 0x80083390);
    return;
    // 0x80083394: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void glcutDll_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808004D0: jr          $ra
    // 0x808004D4: sh          $a0, 0x75EA($at)
    MEM_H(0X75EA, ctx->r1) = ctx->r4;
    return;
    // 0x808004D4: sh          $a0, 0x75EA($at)
    MEM_H(0X75EA, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void chmoley_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800918: lbu         $t9, 0x79($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X79);
    // 0x8080091C: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x80800920: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x80800924: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800928: jr          $ra
    // 0x8080092C: sb          $t1, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r9;
    return;
    // 0x8080092C: sb          $t1, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void _gczoombox_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B30: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B30);
    return;
    // 0x80087B34: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80800AA4_chnewfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AA4: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80800AA8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800AAC: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80800AB0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800AB4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800AB8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80800ABC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80800AC0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80800AC4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800AC8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800ACC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800AD0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800AD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800AD8: jal         0x80100094
    // 0x80800ADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800ADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800AE0: jal         0x800DF324
    // 0x80800AE4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    func_800DF324(rdram, ctx);
        goto after_1;
    // 0x80800AE4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_1:
    // 0x80800AE8: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x80800AEC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800AF0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800AF4: jal         0x800AE40C
    // 0x80800AF8: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    func_800AE40C(rdram, ctx);
        goto after_2;
    // 0x80800AF8: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    after_2:
    // 0x80800AFC: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x80800B00: jal         0x800AE080
    // 0x80800B04: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    func_800AE080(rdram, ctx);
        goto after_3;
    // 0x80800B04: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    after_3:
    // 0x80800B08: lw          $t8, 0x6C($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X6C);
    // 0x80800B0C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800B10: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800B14: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80800B18: beq         $t9, $zero, L_80800BCC
    if (ctx->r25 == 0) {
        // 0x80800B1C: addiu       $fp, $sp, 0x48
        ctx->r30 = ADD32(ctx->r29, 0X48);
            goto L_80800BCC;
    }
    // 0x80800B1C: addiu       $fp, $sp, 0x48
    ctx->r30 = ADD32(ctx->r29, 0X48);
    // 0x80800B20: lui         $s7, 0x8080
    ctx->r23 = S32(RELOC_HI16(1812, 0X1950) << 16);
    // 0x80800B24: addiu       $s7, $s7, 0x1950
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(1812, 0X1950));
    // 0x80800B28: addiu       $s3, $sp, 0x60
    ctx->r19 = ADD32(ctx->r29, 0X60);
    // 0x80800B2C: addiu       $s2, $sp, 0x54
    ctx->r18 = ADD32(ctx->r29, 0X54);
    // 0x80800B30: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80800B34:
    // 0x80800B34: jal         0x80087A28
    // 0x80800B38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _dbskeleton_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800B38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80800B3C: lw          $at, 0x0($s7)
    ctx->r1 = MEM_W(ctx->r23, 0X0);
    // 0x80800B40: lw          $t1, 0x4($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X4);
    // 0x80800B44: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800B48: sw          $at, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r1;
    // 0x80800B4C: lw          $at, 0x8($s7)
    ctx->r1 = MEM_W(ctx->r23, 0X8);
    // 0x80800B50: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800B54: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800B58: sw          $t1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r9;
    // 0x80800B5C: jal         0x800ADE50
    // 0x80800B60: sw          $at, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r1;
    func_800ADE50(rdram, ctx);
        goto after_5;
    // 0x80800B60: sw          $at, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r1;
    after_5:
    // 0x80800B64: jal         0x80018EFC
    // 0x80800B68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mlMtxSet(rdram, ctx);
        goto after_6;
    // 0x80800B68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800B6C: jal         0x80018AD0
    // 0x80800B70: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mlMtxGet(rdram, ctx);
        goto after_7;
    // 0x80800B70: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x80800B74: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800B78: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80800B7C: jal         0x800F23D0
    // 0x80800B80: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800F23D0(rdram, ctx);
        goto after_8;
    // 0x80800B80: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_8:
    // 0x80800B84: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800B88: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800B8C: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800B90: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80800B94: nop

    // 0x80800B98: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80800B9C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800BA0: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80800BA4: jal         0x8002DCA0
    // 0x80800BA8: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_9;
    // 0x80800BA8: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_9:
    // 0x80800BAC: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
    // 0x80800BB0: lw          $t2, 0x6C($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X6C);
    // 0x80800BB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800BB8: addiu       $s1, $s1, 0x60
    ctx->r17 = ADD32(ctx->r17, 0X60);
    // 0x80800BBC: andi        $t3, $t2, 0x1FF
    ctx->r11 = ctx->r10 & 0X1FF;
    // 0x80800BC0: sltu        $at, $s0, $t3
    ctx->r1 = ctx->r16 < ctx->r11 ? 1 : 0;
    // 0x80800BC4: bnel        $at, $zero, L_80800B34
    if (ctx->r1 != 0) {
        // 0x80800BC8: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80800B34;
    }
    goto skip_0;
    // 0x80800BC8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
L_80800BCC:
    // 0x80800BCC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800BD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800BD4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BD8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800BDC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800BE0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800BE4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BE8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800BEC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80800BF0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80800BF4: jr          $ra
    // 0x80800BF8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80800BF8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_808006BC_chhotwaterpoolbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006C4: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x808006C8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808006CC: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x808006D0: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808006D4: bne         $t7, $at, L_808006FC
    if (ctx->r15 != ctx->r1) {
        // 0x808006D8: addiu       $a0, $zero, 0x31B
        ctx->r4 = ADD32(0, 0X31B);
            goto L_808006FC;
    }
    // 0x808006D8: addiu       $a0, $zero, 0x31B
    ctx->r4 = ADD32(0, 0X31B);
    // 0x808006DC: jal         0x800DA298
    // 0x808006E0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808006E0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808006E4: beq         $v0, $zero, L_808006FC
    if (ctx->r2 == 0) {
        // 0x808006E8: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_808006FC;
    }
    // 0x808006E8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808006EC: jal         0x800FFAB0
    // 0x808006F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x808006F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x808006F4: b           L_8080070C
    // 0x808006F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080070C;
    // 0x808006F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006FC:
    // 0x808006FC: addiu       $a0, $a2, 0x18
    ctx->r4 = ADD32(ctx->r6, 0X18);
    // 0x80800700: jal         0x800EE7F8
    // 0x80800704: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800704: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    after_2:
    // 0x80800708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080070C:
    // 0x8080070C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800710: jr          $ra
    // 0x80800714: nop

    return;
    // 0x80800714: nop

;}
RECOMP_FUNC void func_80800908_chlagoonfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800908: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080090C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800910: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800914: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800918: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8080091C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800920: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800924: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800928: jal         0x80100094
    // 0x8080092C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080092C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800930: beq         $v0, $zero, L_808009E0
    if (ctx->r2 == 0) {
        // 0x80800934: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_808009E0;
    }
    // 0x80800934: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800938: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080093C: addiu       $s2, $sp, 0x34
    ctx->r18 = ADD32(ctx->r29, 0X34);
L_80800940:
    // 0x80800940: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80800944: lhu         $t7, 0x14($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X14);
    // 0x80800948: jal         0x800D674C
    // 0x8080094C: addu        $a0, $t7, $s0
    ctx->r4 = ADD32(ctx->r15, ctx->r16);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x8080094C: addu        $a0, $t7, $s0
    ctx->r4 = ADD32(ctx->r15, ctx->r16);
    after_1:
    // 0x80800950: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800954: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80800958: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8080095C: bne         $at, $zero, L_80800940
    if (ctx->r1 != 0) {
        // 0x80800960: sw          $v0, -0x4($s2)
        MEM_W(-0X4, ctx->r18) = ctx->r2;
            goto L_80800940;
    }
    // 0x80800960: sw          $v0, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->r2;
    // 0x80800964: lw          $v1, 0x6C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X6C);
    // 0x80800968: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080096C: addiu       $s2, $sp, 0x34
    ctx->r18 = ADD32(ctx->r29, 0X34);
    // 0x80800970: andi        $t8, $v1, 0x1FF
    ctx->r24 = ctx->r3 & 0X1FF;
    // 0x80800974: beq         $t8, $zero, L_808009E0
    if (ctx->r24 == 0) {
        // 0x80800978: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_808009E0;
    }
    // 0x80800978: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8080097C:
    // 0x8080097C: lbu         $t9, 0x2C($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X2C);
    // 0x80800980: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80800984: addu        $t1, $s2, $t0
    ctx->r9 = ADD32(ctx->r18, ctx->r8);
    // 0x80800988: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8080098C: beql        $t2, $zero, L_808009D4
    if (ctx->r10 == 0) {
        // 0x80800990: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808009D4;
    }
    goto skip_0;
    // 0x80800990: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80800994: jal         0x800DF830
    // 0x80800998: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_2;
    // 0x80800998: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8080099C: lbu         $t3, 0x2C($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X2C);
    // 0x808009A0: lw          $a2, 0x24($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X24);
    // 0x808009A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009A8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x808009AC: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x808009B0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x808009B4: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x808009B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808009BC: jal         0x800DE448
    // 0x808009C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800DE448(rdram, ctx);
        goto after_3;
    // 0x808009C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
    // 0x808009C4: lw          $v1, 0x6C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X6C);
    // 0x808009C8: andi        $t7, $v1, 0x1FF
    ctx->r15 = ctx->r3 & 0X1FF;
    // 0x808009CC: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x808009D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808009D4:
    // 0x808009D4: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x808009D8: bne         $at, $zero, L_8080097C
    if (ctx->r1 != 0) {
        // 0x808009DC: addiu       $s1, $s1, 0x30
        ctx->r17 = ADD32(ctx->r17, 0X30);
            goto L_8080097C;
    }
    // 0x808009DC: addiu       $s1, $s1, 0x30
    ctx->r17 = ADD32(ctx->r17, 0X30);
L_808009E0:
    // 0x808009E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808009E4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808009E8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808009EC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808009F0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x808009F4: jr          $ra
    // 0x808009F8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808009F8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800A4A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4A74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A4A78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A4A7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A4A80: jal         0x800A4338
    // 0x800A4A84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A4338(rdram, ctx);
        goto after_0;
    // 0x800A4A84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800A4A88: bnel        $v0, $zero, L_800A4AC0
    if (ctx->r2 != 0) {
        // 0x800A4A8C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A4AC0;
    }
    goto skip_0;
    // 0x800A4A8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800A4A90: jal         0x800A4978
    // 0x800A4A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4978(rdram, ctx);
        goto after_1;
    // 0x800A4A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800A4A98: bnel        $v0, $zero, L_800A4AC0
    if (ctx->r2 != 0) {
        // 0x800A4A9C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A4AC0;
    }
    goto skip_1;
    // 0x800A4A9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800A4AA0: jal         0x800A4190
    // 0x800A4AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4190(rdram, ctx);
        goto after_2;
    // 0x800A4AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800A4AA8: jal         0x800A4878
    // 0x800A4AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4878(rdram, ctx);
        goto after_3;
    // 0x800A4AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800A4AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4AB4: jal         0x800A3F14
    // 0x800A4AB8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800A3F14(rdram, ctx);
        goto after_4;
    // 0x800A4AB8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x800A4ABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A4AC0:
    // 0x800A4AC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A4AC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A4AC8: jr          $ra
    // 0x800A4ACC: nop

    return;
    // 0x800A4ACC: nop

;}
RECOMP_FUNC void _chmolehill_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086940: syscall     397
    recomp_syscall_handler(rdram, ctx, 0x80086940);
    return;
    // 0x80086944: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80099544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099544: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80099548: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009954C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80099550: lw          $t6, 0xB8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB8);
    // 0x80099554: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80099558: lbu         $t7, 0x8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8);
    // 0x8009955C: beql        $t7, $zero, L_80099598
    if (ctx->r15 == 0) {
        // 0x80099560: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80099598;
    }
    goto skip_0;
    // 0x80099560: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80099564: jal         0x8008C924
    // 0x80099568: nop

    baanim_defrag(rdram, ctx);
        goto after_0;
    // 0x80099568: nop

    after_0:
    // 0x8009956C: jal         0x800934C4
    // 0x80099570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800934C4(rdram, ctx);
        goto after_1;
    // 0x80099570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80099574: jal         0x80096728
    // 0x80099578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096728(rdram, ctx);
        goto after_2;
    // 0x80099578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8009957C: jal         0x800A300C
    // 0x80099580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A300C(rdram, ctx);
        goto after_3;
    // 0x80099580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80099584: jal         0x80091ADC
    // 0x80099588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bakey_defrag(rdram, ctx);
        goto after_4;
    // 0x80099588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8009958C: jal         0x800A266C
    // 0x80099590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A266C(rdram, ctx);
        goto after_5;
    // 0x80099590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80099594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80099598:
    // 0x80099598: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009959C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800995A0: jr          $ra
    // 0x800995A4: nop

    return;
    // 0x800995A4: nop

    // 0x800995A8: nop

    // 0x800995AC: nop

;}
RECOMP_FUNC void bsbabykaz_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801120: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801124: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(68, 0X1790) << 16);
    // 0x80801128: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080112C: jr          $ra
    // 0x80801130: lw          $v0, 0x1790($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(68, 0X1790));
    return;
    // 0x80801130: lw          $v0, 0x1790($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(68, 0X1790));
;}
RECOMP_FUNC void func_80801380_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801388: jal         0x80085148
    // 0x8080138C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _baspin_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080138C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801390: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801394: jal         0x80084DA0
    // 0x80801398: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bakaztorpedo_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80801398: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8080139C: jal         0x80800508
    // 0x808013A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800508_bskaztorpedo(rdram, ctx);
        goto after_2;
    // 0x808013A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808013A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808013A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808013AC: jr          $ra
    // 0x808013B0: nop

    return;
    // 0x808013B0: nop

;}
RECOMP_FUNC void chdinoswitches_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1048, 0XC78) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0xC78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1048, 0XC78));
    return;
    // 0x80800014: addiu       $v0, $v0, 0xC78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1048, 0XC78));
;}
RECOMP_FUNC void _subaddiemulti_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A0A0: syscall     826
    recomp_syscall_handler(rdram, ctx, 0x8008A0A0);
    return;
    // 0x8008A0A4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _ch1pfreeze_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800873E8: syscall     564
    recomp_syscall_handler(rdram, ctx, 0x800873E8);
    return;
    // 0x800873EC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chegggrenade_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087210: syscall     537
    recomp_syscall_handler(rdram, ctx, 0x80087210);
    return;
    // 0x80087214: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _idtwinklecolour_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088ED0: syscall     747
    recomp_syscall_handler(rdram, ctx, 0x80088ED0);
    return;
    // 0x80088ED4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800AA194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA194: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AA198: jr          $ra
    // 0x800AA19C: lbu         $v0, 0x7782($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7782);
    return;
    // 0x800AA19C: lbu         $v0, 0x7782($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7782);
;}
RECOMP_FUNC void chfactorylinkgrill_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2316, 0X298) << 16);
    // 0x808001A8: jr          $ra
    // 0x808001AC: addiu       $v0, $v0, 0x298
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2316, 0X298));
    return;
    // 0x808001AC: addiu       $v0, $v0, 0x298
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2316, 0X298));
;}
RECOMP_FUNC void func_800EE940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE940: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EE944: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800EE948: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800EE94C: nop

    // 0x800EE950: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x800EE954: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EE958: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800EE95C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800EE960: nop

    // 0x800EE964: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
    // 0x800EE968: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EE96C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800EE970: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800EE974: jr          $ra
    // 0x800EE978: sh          $t1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r9;
    return;
    // 0x800EE978: sh          $t1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8080005C_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800064: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800068: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080006C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800070: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80800074: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    // 0x80800078: jal         0x80089C30
    // 0x8080007C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080007C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800080: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800084: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800088: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080008C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80800090: nop

    // 0x80800094: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800098: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8080009C: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x808000A0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x808000A4: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
    // 0x808000A8: jal         0x8080003C
    // 0x808000AC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8080003C_chprisonbits(rdram, ctx);
        goto after_1;
    // 0x808000AC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808000B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000B8: jr          $ra
    // 0x808000BC: nop

    return;
    // 0x808000BC: nop

;}
RECOMP_FUNC void _chfactoryroofbits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800874A8: syscall     578
    recomp_syscall_handler(rdram, ctx, 0x800874A8);
    return;
    // 0x800874AC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808001B0_chbadjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808001B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001B8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808001BC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808001C0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808001C4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x808001C8: jal         0x800B53A4
    // 0x808001CC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x808001CC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x808001D0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808001D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001D8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808001DC: jal         0x8080000C
    // 0x808001E0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_8080000C_chbadjinjo(rdram, ctx);
        goto after_1;
    // 0x808001E0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x808001E4: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x808001E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001EC: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808001F0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808001F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808001F8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808001FC: addiu       $t9, $zero, -0x5
    ctx->r25 = ADD32(0, -0X5);
    // 0x80800200: addiu       $t2, $zero, 0x96
    ctx->r10 = ADD32(0, 0X96);
    // 0x80800204: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80800208: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8080020C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800210: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800214: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800218: addiu       $a1, $zero, -0xF
    ctx->r5 = ADD32(0, -0XF);
    // 0x8080021C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800220: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800224: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x80800228: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x8080022C: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x80800230: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80800234: jal         0x800BA994
    // 0x80800238: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    func_800BA994(rdram, ctx);
        goto after_2;
    // 0x80800238: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_2:
    // 0x8080023C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800240: jal         0x800BA22C
    // 0x80800244: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x80800244: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80800248: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1576, 0X1168) << 16);
    // 0x8080024C: jal         0x800DC298
    // 0x80800250: lwc1        $f12, 0x1168($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1576, 0X1168));
    func_800DC298(rdram, ctx);
        goto after_4;
    // 0x80800250: lwc1        $f12, 0x1168($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1576, 0X1168));
    after_4:
    // 0x80800254: beq         $v0, $zero, L_80800268
    if (ctx->r2 == 0) {
        // 0x80800258: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800268;
    }
    // 0x80800258: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080025C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1576, 0X12D0) << 16);
    // 0x80800260: jal         0x80801090
    // 0x80800264: addiu       $a1, $a1, 0x12D0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1576, 0X12D0));
    func_80801090_chbadjinjo(rdram, ctx);
        goto after_5;
    // 0x80800264: addiu       $a1, $a1, 0x12D0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1576, 0X12D0));
    after_5:
L_80800268:
    // 0x80800268: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080026C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800270: jr          $ra
    // 0x80800274: nop

    return;
    // 0x80800274: nop

;}
RECOMP_FUNC void func_808001C0_chjadestatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808001CC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808001D0: jal         0x800888C8
    // 0x808001D4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808001D4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x808001D8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808001DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808001E0: lhu         $a0, 0x76($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X76);
    // 0x808001E4: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x808001E8: jal         0x800D0BD4
    // 0x808001EC: addiu       $a0, $t7, -0x32
    ctx->r4 = ADD32(ctx->r15, -0X32);
    func_800D0BD4(rdram, ctx);
        goto after_1;
    // 0x808001EC: addiu       $a0, $t7, -0x32
    ctx->r4 = ADD32(ctx->r15, -0X32);
    after_1:
    // 0x808001F0: jal         0x800D035C
    // 0x808001F4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800D035C(rdram, ctx);
        goto after_2;
    // 0x808001F4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_2:
    // 0x808001F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808001FC: addiu       $a0, $zero, 0xEE
    ctx->r4 = ADD32(0, 0XEE);
    // 0x80800200: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800204: jal         0x800D24E8
    // 0x80800208: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D24E8(rdram, ctx);
        goto after_3;
    // 0x80800208: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8080020C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80800210: jal         0x800FC63C
    // 0x80800214: addiu       $a1, $zero, 0x3E80
    ctx->r5 = ADD32(0, 0X3E80);
    func_800FC63C(rdram, ctx);
        goto after_4;
    // 0x80800214: addiu       $a1, $zero, 0x3E80
    ctx->r5 = ADD32(0, 0X3E80);
    after_4:
    // 0x80800218: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8080021C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800220: addiu       $a0, $zero, 0x2B4
    ctx->r4 = ADD32(0, 0X2B4);
    // 0x80800224: beq         $v0, $at, L_80800240
    if (ctx->r2 == ctx->r1) {
        // 0x80800228: addiu       $a1, $zero, 0x7
        ctx->r5 = ADD32(0, 0X7);
            goto L_80800240;
    }
    // 0x80800228: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8080022C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80800230: beq         $v0, $at, L_80800250
    if (ctx->r2 == ctx->r1) {
        // 0x80800234: addiu       $a0, $zero, 0x2B4
        ctx->r4 = ADD32(0, 0X2B4);
            goto L_80800250;
    }
    // 0x80800234: addiu       $a0, $zero, 0x2B4
    ctx->r4 = ADD32(0, 0X2B4);
    // 0x80800238: b           L_80800260
    // 0x8080023C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800260;
    // 0x8080023C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800240:
    // 0x80800240: jal         0x80101180
    // 0x80800244: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_5;
    // 0x80800244: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80800248: b           L_80800260
    // 0x8080024C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800260;
    // 0x8080024C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800250:
    // 0x80800250: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800254: jal         0x80101180
    // 0x80800258: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x80800258: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8080025C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800260:
    // 0x80800260: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800264: jr          $ra
    // 0x80800268: nop

    return;
    // 0x80800268: nop

;}
RECOMP_FUNC void _chflysaucer_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C00: syscall     430
    recomp_syscall_handler(rdram, ctx, 0x80086C00);
    return;
    // 0x80086C04: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800A8AD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8AD4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A8AD8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A8ADC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A8AE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8AE4: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800A8AE8: jr          $ra
    // 0x800A8AEC: lwc1        $f0, 0x7690($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7690);
    return;
    // 0x800A8AEC: lwc1        $f0, 0x7690($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7690);
;}
RECOMP_FUNC void func_80800018_bamum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8080001C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800020: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800024: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800028: jal         0x800B5BE4
    // 0x8080002C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x8080002C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x80800030: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800034: lw          $t6, 0xD0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XD0);
    // 0x80800038: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80800044: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800048: nop

    // 0x8080004C: bc1tl       L_808001B4
    if (c1cs) {
        // 0x80800050: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808001B4;
    }
    goto skip_0;
    // 0x80800050: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800054: jal         0x8009C128
    // 0x80800058: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x80800058: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_1:
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: jal         0x8009C15C
    // 0x80800064: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_8009C15C(rdram, ctx);
        goto after_2;
    // 0x80800064: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_2:
    // 0x80800068: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8080006C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80800070: jal         0x800EFB24
    // 0x80800074: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x80800074: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_3:
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080007C: jal         0x80092C6C
    // 0x80800080: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_80092C6C(rdram, ctx);
        goto after_4;
    // 0x80800080: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_4:
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800088: jal         0x80092C48
    // 0x8080008C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_80092C48(rdram, ctx);
        goto after_5;
    // 0x8080008C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x80800090: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800094: jal         0x800EF04C
    // 0x80800098: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x80800098: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_6:
    // 0x8080009C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808000A0: jal         0x800EF04C
    // 0x808000A4: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x808000A4: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_7:
    // 0x808000A8: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x808000AC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x808000B0: jal         0x800EFB24
    // 0x808000B4: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_800EFB24(rdram, ctx);
        goto after_8;
    // 0x808000B4: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_8:
    // 0x808000B8: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x808000BC: jal         0x800F1A88
    // 0x808000C0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F1A88(rdram, ctx);
        goto after_9;
    // 0x808000C0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_9:
    // 0x808000C4: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808000C8: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x808000CC: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x808000D0: jal         0x800EFD24
    // 0x808000D4: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    func_800EFD24(rdram, ctx);
        goto after_10;
    // 0x808000D4: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    after_10:
    // 0x808000D8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808000DC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x808000E0: jal         0x800EE780
    // 0x808000E4: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    func_800EE780(rdram, ctx);
        goto after_11;
    // 0x808000E4: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    after_11:
    // 0x808000E8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808000EC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808000F0: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808000F4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808000F8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000FC: sub.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x80800100: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800104: addiu       $t7, $zero, 0x190
    ctx->r15 = ADD32(0, 0X190);
    // 0x80800108: add.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8080010C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80800110: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800114: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800118: addiu       $a3, $zero, 0x190
    ctx->r7 = ADD32(0, 0X190);
    // 0x8080011C: sub.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80800120: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800124: add.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80800128: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8080012C: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80800130: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800134: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800138: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8080013C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800140: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80800144: sll         $t1, $a2, 16
    ctx->r9 = S32(ctx->r6 << 16);
    // 0x80800148: sra         $a2, $t1, 16
    ctx->r6 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8080014C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80800150: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800154: jal         0x800BA994
    // 0x80800158: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800BA994(rdram, ctx);
        goto after_12;
    // 0x80800158: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_12:
    // 0x8080015C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(568, 0X280) << 16);
    // 0x80800160: addiu       $t8, $t8, 0x280
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(568, 0X280));
    // 0x80800164: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800168: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080016C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800170: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800174: jal         0x800BABB8
    // 0x80800178: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_13;
    // 0x80800178: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_13:
    // 0x8080017C: lw          $t9, 0xD0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XD0);
    // 0x80800180: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800184: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800188: lwc1        $f16, 0x4($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8080018C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800190: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800194: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800198: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080019C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808001A0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808001A4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808001A8: jal         0x800BA22C
    // 0x808001AC: nop

    func_800BA22C(rdram, ctx);
        goto after_14;
    // 0x808001AC: nop

    after_14:
    // 0x808001B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808001B4:
    // 0x808001B4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808001B8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x808001BC: jr          $ra
    // 0x808001C0: nop

    return;
    // 0x808001C0: nop

;}
RECOMP_FUNC void chlagoonufoint_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801614: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801618: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080161C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801620: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80801624: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801628: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080162C: jal         0x80106790
    // 0x80801630: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801630: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80801634: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80801638: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X192C) << 16);
    // 0x8080163C: lwc1        $f6, 0x192C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X192C));
    // 0x80801640: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80801644: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80801648: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8080164C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80801650: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801654: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X1930) << 16);
    // 0x80801658: lwc1        $f10, 0x1930($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X1930));
    // 0x8080165C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80801660: addu        $a0, $t5, $a1
    ctx->r4 = ADD32(ctx->r13, ctx->r5);
    // 0x80801664: sltu        $at, $a1, $a0
    ctx->r1 = ctx->r5 < ctx->r4 ? 1 : 0;
    // 0x80801668: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8080166C: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80801670: bgez        $t7, L_80801684
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80801674: andi        $t8, $t7, 0x3
        ctx->r24 = ctx->r15 & 0X3;
            goto L_80801684;
    }
    // 0x80801674: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x80801678: beq         $t8, $zero, L_80801684
    if (ctx->r24 == 0) {
        // 0x8080167C: nop
    
            goto L_80801684;
    }
    // 0x8080167C: nop

    // 0x80801680: addiu       $t8, $t8, -0x4
    ctx->r24 = ADD32(ctx->r24, -0X4);
L_80801684:
    // 0x80801684: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80801688: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x8080168C: lwc1        $f16, 0x14($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80801690: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80801694: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80801698: nop

    // 0x8080169C: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x808016A0: beq         $at, $zero, L_808018C8
    if (ctx->r1 == 0) {
        // 0x808016A4: sra         $v1, $t2, 16
        ctx->r3 = S32(SIGNED(ctx->r10) >> 16);
            goto L_808018C8;
    }
    // 0x808016A4: sra         $v1, $t2, 16
    ctx->r3 = S32(SIGNED(ctx->r10) >> 16);
L_808016A8:
    // 0x808016A8: lbu         $t6, 0xC($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XC);
    // 0x808016AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808016B0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x808016B4: bgez        $t6, L_808016C8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808016B8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808016C8;
    }
    // 0x808016B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808016BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808016C0: nop

    // 0x808016C4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_808016C8:
    // 0x808016C8: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808016CC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808016D0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808016D4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x808016D8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x808016DC: nop

    // 0x808016E0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x808016E4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x808016E8: nop

    // 0x808016EC: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x808016F0: beql        $t8, $zero, L_80801740
    if (ctx->r24 == 0) {
        // 0x808016F4: mfc1        $t8, $f16
        ctx->r24 = (int32_t)ctx->f16.u32l;
            goto L_80801740;
    }
    goto skip_0;
    // 0x808016F4: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x808016F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808016FC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801700: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80801704: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80801708: nop

    // 0x8080170C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80801710: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80801714: nop

    // 0x80801718: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8080171C: bne         $t8, $zero, L_80801734
    if (ctx->r24 != 0) {
        // 0x80801720: nop
    
            goto L_80801734;
    }
    // 0x80801720: nop

    // 0x80801724: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80801728: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080172C: b           L_8080174C
    // 0x80801730: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8080174C;
    // 0x80801730: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80801734:
    // 0x80801734: b           L_8080174C
    // 0x80801738: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8080174C;
    // 0x80801738: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8080173C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
L_80801740:
    // 0x80801740: nop

    // 0x80801744: bltz        $t8, L_80801734
    if (SIGNED(ctx->r24) < 0) {
        // 0x80801748: nop
    
            goto L_80801734;
    }
    // 0x80801748: nop

L_8080174C:
    // 0x8080174C: sb          $t8, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r24;
    // 0x80801750: lbu         $t9, 0xD($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XD);
    // 0x80801754: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80801758: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080175C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80801760: bgez        $t9, L_80801774
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80801764: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80801774;
    }
    // 0x80801764: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80801768: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080176C: nop

    // 0x80801770: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_80801774:
    // 0x80801774: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80801778: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8080177C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801780: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80801784: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80801788: nop

    // 0x8080178C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801790: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80801794: nop

    // 0x80801798: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8080179C: beql        $t1, $zero, L_808017EC
    if (ctx->r9 == 0) {
        // 0x808017A0: mfc1        $t1, $f10
        ctx->r9 = (int32_t)ctx->f10.u32l;
            goto L_808017EC;
    }
    goto skip_1;
    // 0x808017A0: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x808017A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808017A8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808017AC: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x808017B0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x808017B4: nop

    // 0x808017B8: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x808017BC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x808017C0: nop

    // 0x808017C4: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x808017C8: bne         $t1, $zero, L_808017E0
    if (ctx->r9 != 0) {
        // 0x808017CC: nop
    
            goto L_808017E0;
    }
    // 0x808017CC: nop

    // 0x808017D0: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x808017D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808017D8: b           L_808017F8
    // 0x808017DC: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_808017F8;
    // 0x808017DC: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_808017E0:
    // 0x808017E0: b           L_808017F8
    // 0x808017E4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_808017F8;
    // 0x808017E4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x808017E8: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
L_808017EC:
    // 0x808017EC: nop

    // 0x808017F0: bltz        $t1, L_808017E0
    if (SIGNED(ctx->r9) < 0) {
        // 0x808017F4: nop
    
            goto L_808017E0;
    }
    // 0x808017F4: nop

L_808017F8:
    // 0x808017F8: sb          $t1, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r9;
    // 0x808017FC: lbu         $t2, 0xE($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XE);
    // 0x80801800: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80801804: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80801808: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8080180C: bgez        $t2, L_80801820
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80801810: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80801820;
    }
    // 0x80801810: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80801814: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801818: nop

    // 0x8080181C: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_80801820:
    // 0x80801820: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80801824: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80801828: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080182C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80801830: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80801834: nop

    // 0x80801838: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8080183C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80801840: nop

    // 0x80801844: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80801848: beql        $t4, $zero, L_80801898
    if (ctx->r12 == 0) {
        // 0x8080184C: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_80801898;
    }
    goto skip_2;
    // 0x8080184C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x80801850: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801854: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80801858: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8080185C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80801860: nop

    // 0x80801864: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801868: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8080186C: nop

    // 0x80801870: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80801874: bne         $t4, $zero, L_8080188C
    if (ctx->r12 != 0) {
        // 0x80801878: nop
    
            goto L_8080188C;
    }
    // 0x80801878: nop

    // 0x8080187C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80801880: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801884: b           L_808018A4
    // 0x80801888: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_808018A4;
    // 0x80801888: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_8080188C:
    // 0x8080188C: b           L_808018A4
    // 0x80801890: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_808018A4;
    // 0x80801890: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80801894: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_80801898:
    // 0x80801898: nop

    // 0x8080189C: bltz        $t4, L_8080188C
    if (SIGNED(ctx->r12) < 0) {
        // 0x808018A0: nop
    
            goto L_8080188C;
    }
    // 0x808018A0: nop

L_808018A4:
    // 0x808018A4: sb          $t4, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r12;
    // 0x808018A8: lh          $t5, 0xA($a1)
    ctx->r13 = MEM_H(ctx->r5, 0XA);
    // 0x808018AC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x808018B0: sltu        $at, $a1, $a0
    ctx->r1 = ctx->r5 < ctx->r4 ? 1 : 0;
    // 0x808018B4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x808018B8: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x808018BC: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x808018C0: bne         $at, $zero, L_808016A8
    if (ctx->r1 != 0) {
        // 0x808018C4: sh          $t6, -0x6($a2)
        MEM_H(-0X6, ctx->r6) = ctx->r14;
            goto L_808016A8;
    }
    // 0x808018C4: sh          $t6, -0x6($a2)
    MEM_H(-0X6, ctx->r6) = ctx->r14;
L_808018C8:
    // 0x808018C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808018D0: jr          $ra
    // 0x808018D4: nop

    return;
    // 0x808018D4: nop

    // 0x808018D8: nop

    // 0x808018DC: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800C74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800C78: jal         0x80100094
    // 0x80800C7C: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C7C: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    after_0:
    // 0x80800C80: jal         0x80800CA8
    // 0x80800C84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    gcnewoption_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800C84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800C88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C8C: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    // 0x80800C90: jal         0x80100074
    // 0x80800C94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_2;
    // 0x80800C94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CA0: jr          $ra
    // 0x80800CA4: nop

    return;
    // 0x80800CA4: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800895B0: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x800895B0);
    return;
    // 0x800895B4: addi        $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
;}
RECOMP_FUNC void bsbkflamethrower_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800010: jal         0x8009BFCC
    // 0x80800014: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_8009BFCC(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800018: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8080001C: jal         0x8009C984
    // 0x80800020: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x80800020: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80800024: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800028: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080002C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800030: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80800034: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800038: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080003C: jal         0x800EEC30
    // 0x80800040: nop

    func_800EEC30(rdram, ctx);
        goto after_2;
    // 0x80800040: nop

    after_2:
    // 0x80800044: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800048: jal         0x8009C128
    // 0x8080004C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8009C128(rdram, ctx);
        goto after_3;
    // 0x8080004C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80800050: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800054: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800058: jal         0x800EFA98
    // 0x8080005C: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_800EFA98(rdram, ctx);
        goto after_4;
    // 0x8080005C: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_4:
    // 0x80800060: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800064: jal         0x800EF04C
    // 0x80800068: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80800068: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x8080006C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800070: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x80800074: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800078: lwc1        $f8, 0x4($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8080007C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800080: swc1        $f16, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f16.u32l;
    // 0x80800084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800088: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080008C: jr          $ra
    // 0x80800090: nop

    return;
    // 0x80800090: nop

;}
RECOMP_FUNC void func_800CE21C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE21C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800CE220: lhu         $t6, -0x55F0($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X55F0);
    // 0x800CE224: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CE228: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800CE22C: bne         $a0, $t6, L_800CE23C
    if (ctx->r4 != ctx->r14) {
        // 0x800CE230: nop
    
            goto L_800CE23C;
    }
    // 0x800CE230: nop

    // 0x800CE234: jr          $ra
    // 0x800CE238: lhu         $v0, -0x55EE($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X55EE);
    return;
    // 0x800CE238: lhu         $v0, -0x55EE($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X55EE);
L_800CE23C:
    // 0x800CE23C: lhu         $t7, -0x55EC($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X55EC);
    // 0x800CE240: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CE244: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800CE248: bne         $a0, $t7, L_800CE258
    if (ctx->r4 != ctx->r15) {
        // 0x800CE24C: nop
    
            goto L_800CE258;
    }
    // 0x800CE24C: nop

    // 0x800CE250: jr          $ra
    // 0x800CE254: lhu         $v0, -0x55EA($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X55EA);
    return;
    // 0x800CE254: lhu         $v0, -0x55EA($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X55EA);
L_800CE258:
    // 0x800CE258: lhu         $t8, -0x55E8($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X55E8);
    // 0x800CE25C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800CE260: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800CE264: bne         $a0, $t8, L_800CE278
    if (ctx->r4 != ctx->r24) {
        // 0x800CE268: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800CE278;
    }
    // 0x800CE268: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800CE26C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800CE270: jr          $ra
    // 0x800CE274: lhu         $v0, -0x55E6($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X55E6);
    return;
    // 0x800CE274: lhu         $v0, -0x55E6($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X55E6);
L_800CE278:
    // 0x800CE278: addiu       $t0, $t0, -0x55F0
    ctx->r8 = ADD32(ctx->r8, -0X55F0);
    // 0x800CE27C: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x800CE280: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x800CE284: bnel        $a0, $t1, L_800CE298
    if (ctx->r4 != ctx->r9) {
        // 0x800CE288: lhu         $t2, 0x4($v1)
        ctx->r10 = MEM_HU(ctx->r3, 0X4);
            goto L_800CE298;
    }
    goto skip_0;
    // 0x800CE288: lhu         $t2, 0x4($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X4);
    skip_0:
    // 0x800CE28C: jr          $ra
    // 0x800CE290: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    return;
    // 0x800CE290: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x800CE294: lhu         $t2, 0x4($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X4);
L_800CE298:
    // 0x800CE298: bnel        $a0, $t2, L_800CE2AC
    if (ctx->r4 != ctx->r10) {
        // 0x800CE29C: lhu         $t3, 0x8($v1)
        ctx->r11 = MEM_HU(ctx->r3, 0X8);
            goto L_800CE2AC;
    }
    goto skip_1;
    // 0x800CE29C: lhu         $t3, 0x8($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X8);
    skip_1:
    // 0x800CE2A0: jr          $ra
    // 0x800CE2A4: lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6);
    return;
    // 0x800CE2A4: lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6);
    // 0x800CE2A8: lhu         $t3, 0x8($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X8);
L_800CE2AC:
    // 0x800CE2AC: bnel        $a0, $t3, L_800CE2C0
    if (ctx->r4 != ctx->r11) {
        // 0x800CE2B0: lhu         $t4, 0xC($v1)
        ctx->r12 = MEM_HU(ctx->r3, 0XC);
            goto L_800CE2C0;
    }
    goto skip_2;
    // 0x800CE2B0: lhu         $t4, 0xC($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0XC);
    skip_2:
    // 0x800CE2B4: jr          $ra
    // 0x800CE2B8: lhu         $v0, 0xA($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XA);
    return;
    // 0x800CE2B8: lhu         $v0, 0xA($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XA);
    // 0x800CE2BC: lhu         $t4, 0xC($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0XC);
L_800CE2C0:
    // 0x800CE2C0: bnel        $a0, $t4, L_800CE2D4
    if (ctx->r4 != ctx->r12) {
        // 0x800CE2C4: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800CE2D4;
    }
    goto skip_3;
    // 0x800CE2C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_3:
    // 0x800CE2C8: jr          $ra
    // 0x800CE2CC: lhu         $v0, 0xE($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XE);
    return;
    // 0x800CE2CC: lhu         $v0, 0xE($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XE);
    // 0x800CE2D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800CE2D4:
    // 0x800CE2D4: jr          $ra
    // 0x800CE2D8: nop

    return;
    // 0x800CE2D8: nop

;}
RECOMP_FUNC void _cothemedll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087858: syscall     635
    recomp_syscall_handler(rdram, ctx, 0x80087858);
    return;
    // 0x8008785C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80802284_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802284: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080228C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80802290: jal         0x80103DFC
    // 0x80802294: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80103DFC(rdram, ctx);
        goto after_0;
    // 0x80802294: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802298: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080229C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1364, 0X2834) << 16);
    // 0x808022A0: addiu       $a3, $a3, 0x2834
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1364, 0X2834));
    // 0x808022A4: lhu         $a2, 0x72($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X72);
    // 0x808022A8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808022AC: srl         $t6, $a2, 10
    ctx->r14 = S32(U32(ctx->r6) >> 10);
    // 0x808022B0: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x808022B4: jal         0x80089D50
    // 0x808022B8: sltu        $a2, $zero, $t7
    ctx->r6 = 0 < ctx->r15 ? 1 : 0;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808022B8: sltu        $a2, $zero, $t7
    ctx->r6 = 0 < ctx->r15 ? 1 : 0;
    after_1:
    // 0x808022BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808022C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808022C4: jr          $ra
    // 0x808022C8: nop

    return;
    // 0x808022C8: nop

;}
RECOMP_FUNC void inflate_codes_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CF00: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x8001CF04: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8001CF08: mfc1        $s4, $f17
    ctx->r20 = (int32_t)ctx->f_odd[(17 - 1) * 2];
    // 0x8001CF0C: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8001CF10: addiu       $s0, $s0, 0x1750
    ctx->r16 = ADD32(ctx->r16, 0X1750);
    // 0x8001CF14: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x8001CF18: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x8001CF1C: lhu         $t2, 0x0($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X0);
    // 0x8001CF20: sll         $t7, $a3, 1
    ctx->r15 = S32(ctx->r7 << 1);
    // 0x8001CF24: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x8001CF28: lhu         $t0, 0x0($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X0);
L_8001CF2C:
    // 0x8001CF2C: slt         $at, $fp, $a2
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r6) ? 1 : 0;
L_8001CF30:
    // 0x8001CF30: beq         $at, $zero, L_8001CF58
    if (ctx->r1 == 0) {
        // 0x8001CF34: and         $s5, $gp, $t2
        ctx->r21 = ctx->r28 & ctx->r10;
            goto L_8001CF58;
    }
    // 0x8001CF34: and         $s5, $gp, $t2
    ctx->r21 = ctx->r28 & ctx->r10;
L_8001CF38:
    // 0x8001CF38: lbu         $s5, 0x0($s7)
    ctx->r21 = MEM_BU(ctx->r23, 0X0);
    // 0x8001CF3C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001CF40: sllv        $s5, $s5, $fp
    ctx->r21 = S32(ctx->r21 << (ctx->r30 & 31));
    // 0x8001CF44: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x8001CF48: slt         $at, $fp, $a2
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001CF4C: bne         $at, $zero, L_8001CF38
    if (ctx->r1 != 0) {
        // 0x8001CF50: or          $gp, $gp, $s5
        ctx->r28 = ctx->r28 | ctx->r21;
            goto L_8001CF38;
    }
    // 0x8001CF50: or          $gp, $gp, $s5
    ctx->r28 = ctx->r28 | ctx->r21;
    // 0x8001CF54: and         $s5, $gp, $t2
    ctx->r21 = ctx->r28 & ctx->r10;
L_8001CF58:
    // 0x8001CF58: sll         $s5, $s5, 2
    ctx->r21 = S32(ctx->r21 << 2);
    // 0x8001CF5C: addu        $s5, $s5, $a0
    ctx->r21 = ADD32(ctx->r21, ctx->r4);
    // 0x8001CF60: lbu         $s1, 0x0($s5)
    ctx->r17 = MEM_BU(ctx->r21, 0X0);
    // 0x8001CF64: slti        $at, $s1, 0x11
    ctx->r1 = SIGNED(ctx->r17) < 0X11 ? 1 : 0;
    // 0x8001CF68: bne         $at, $zero, L_8001CFD8
    if (ctx->r1 != 0) {
        // 0x8001CF6C: addiu       $t9, $zero, 0x63
        ctx->r25 = ADD32(0, 0X63);
            goto L_8001CFD8;
    }
    // 0x8001CF6C: addiu       $t9, $zero, 0x63
    ctx->r25 = ADD32(0, 0X63);
    // 0x8001CF70: lbu         $t7, 0x1($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X1);
L_8001CF74:
    // 0x8001CF74: beq         $s1, $t9, L_8001D1D8
    if (ctx->r17 == ctx->r25) {
        // 0x8001CF78: addiu       $s1, $s1, -0x10
        ctx->r17 = ADD32(ctx->r17, -0X10);
            goto L_8001D1D8;
    }
    // 0x8001CF78: addiu       $s1, $s1, -0x10
    ctx->r17 = ADD32(ctx->r17, -0X10);
    // 0x8001CF7C: subu        $fp, $fp, $t7
    ctx->r30 = SUB32(ctx->r30, ctx->r15);
    // 0x8001CF80: slt         $at, $fp, $s1
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8001CF84: beq         $at, $zero, L_8001CFA8
    if (ctx->r1 == 0) {
        // 0x8001CF88: srlv        $gp, $gp, $t7
        ctx->r28 = S32(U32(ctx->r28) >> (ctx->r15 & 31));
            goto L_8001CFA8;
    }
    // 0x8001CF88: srlv        $gp, $gp, $t7
    ctx->r28 = S32(U32(ctx->r28) >> (ctx->r15 & 31));
L_8001CF8C:
    // 0x8001CF8C: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    // 0x8001CF90: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001CF94: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x8001CF98: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x8001CF9C: slt         $t7, $fp, $s1
    ctx->r15 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8001CFA0: bne         $t7, $zero, L_8001CF8C
    if (ctx->r15 != 0) {
        // 0x8001CFA4: or          $gp, $gp, $at
        ctx->r28 = ctx->r28 | ctx->r1;
            goto L_8001CF8C;
    }
    // 0x8001CFA4: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
L_8001CFA8:
    // 0x8001CFA8: sll         $t7, $s1, 1
    ctx->r15 = S32(ctx->r17 << 1);
    // 0x8001CFAC: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x8001CFB0: lhu         $t7, 0x0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X0);
    // 0x8001CFB4: lhu         $t8, 0x2($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X2);
    // 0x8001CFB8: and         $t7, $t7, $gp
    ctx->r15 = ctx->r15 & ctx->r28;
    // 0x8001CFBC: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8001CFC0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001CFC4: addu        $s5, $s6, $t7
    ctx->r21 = ADD32(ctx->r22, ctx->r15);
    // 0x8001CFC8: lbu         $s1, 0x0($s5)
    ctx->r17 = MEM_BU(ctx->r21, 0X0);
    // 0x8001CFCC: slti        $at, $s1, 0x11
    ctx->r1 = SIGNED(ctx->r17) < 0X11 ? 1 : 0;
    // 0x8001CFD0: beql        $at, $zero, L_8001CF74
    if (ctx->r1 == 0) {
        // 0x8001CFD4: lbu         $t7, 0x1($s5)
        ctx->r15 = MEM_BU(ctx->r21, 0X1);
            goto L_8001CF74;
    }
    goto skip_0;
    // 0x8001CFD4: lbu         $t7, 0x1($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X1);
    skip_0:
L_8001CFD8:
    // 0x8001CFD8: lbu         $t7, 0x1($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X1);
    // 0x8001CFDC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8001CFE0: srlv        $gp, $gp, $t7
    ctx->r28 = S32(U32(ctx->r28) >> (ctx->r15 & 31));
    // 0x8001CFE4: bne         $s1, $at, L_8001D024
    if (ctx->r17 != ctx->r1) {
        // 0x8001CFE8: subu        $fp, $fp, $t7
        ctx->r30 = SUB32(ctx->r30, ctx->r15);
            goto L_8001D024;
    }
    // 0x8001CFE8: subu        $fp, $fp, $t7
    ctx->r30 = SUB32(ctx->r30, ctx->r15);
    // 0x8001CFEC: lhu         $t7, 0x2($s5)
    ctx->r15 = MEM_HU(ctx->r21, 0X2);
    // 0x8001CFF0: addu        $t8, $t3, $s4
    ctx->r24 = ADD32(ctx->r11, ctx->r20);
    // 0x8001CFF4: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8001CFF8: lw          $t8, 0xA84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA84);
    // 0x8001CFFC: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x8001D000: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x8001D004: sw          $t8, 0xA84($sp)
    MEM_W(0XA84, ctx->r29) = ctx->r24;
    // 0x8001D008: andi        $t8, $t8, 0x17
    ctx->r24 = ctx->r24 & 0X17;
    // 0x8001D00C: sllv        $t9, $t9, $t8
    ctx->r25 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x8001D010: lw          $t8, 0xA88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA88);
    // 0x8001D014: xor         $t8, $t8, $t9
    ctx->r24 = ctx->r24 ^ ctx->r25;
    // 0x8001D018: sw          $t8, 0xA88($sp)
    MEM_W(0XA88, ctx->r29) = ctx->r24;
    // 0x8001D01C: j           L_8001CF2C
    // 0x8001D020: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_8001CF2C;
    // 0x8001D020: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8001D024:
    // 0x8001D024: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8001D028: beq         $s1, $at, L_8001D1CC
    if (ctx->r17 == ctx->r1) {
        // 0x8001D02C: slt         $at, $fp, $s1
        ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
            goto L_8001D1CC;
    }
    // 0x8001D02C: slt         $at, $fp, $s1
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8001D030: beq         $at, $zero, L_8001D054
    if (ctx->r1 == 0) {
        // 0x8001D034: sll         $t7, $s1, 1
        ctx->r15 = S32(ctx->r17 << 1);
            goto L_8001D054;
    }
    // 0x8001D034: sll         $t7, $s1, 1
    ctx->r15 = S32(ctx->r17 << 1);
L_8001D038:
    // 0x8001D038: lbu         $t9, 0x0($s7)
    ctx->r25 = MEM_BU(ctx->r23, 0X0);
    // 0x8001D03C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001D040: sllv        $t9, $t9, $fp
    ctx->r25 = S32(ctx->r25 << (ctx->r30 & 31));
    // 0x8001D044: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x8001D048: slt         $at, $fp, $s1
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8001D04C: bne         $at, $zero, L_8001D038
    if (ctx->r1 != 0) {
        // 0x8001D050: or          $gp, $gp, $t9
        ctx->r28 = ctx->r28 | ctx->r25;
            goto L_8001D038;
    }
    // 0x8001D050: or          $gp, $gp, $t9
    ctx->r28 = ctx->r28 | ctx->r25;
L_8001D054:
    // 0x8001D054: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x8001D058: lhu         $t7, 0x0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X0);
    // 0x8001D05C: lhu         $t8, 0x2($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X2);
    // 0x8001D060: and         $t7, $t7, $gp
    ctx->r15 = ctx->r15 & ctx->r28;
    // 0x8001D064: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x8001D068: subu        $fp, $fp, $s1
    ctx->r30 = SUB32(ctx->r30, ctx->r17);
    // 0x8001D06C: slt         $at, $fp, $a3
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001D070: beq         $at, $zero, L_8001D094
    if (ctx->r1 == 0) {
        // 0x8001D074: srlv        $gp, $gp, $s1
        ctx->r28 = S32(U32(ctx->r28) >> (ctx->r17 & 31));
            goto L_8001D094;
    }
    // 0x8001D074: srlv        $gp, $gp, $s1
    ctx->r28 = S32(U32(ctx->r28) >> (ctx->r17 & 31));
L_8001D078:
    // 0x8001D078: lbu         $t7, 0x0($s7)
    ctx->r15 = MEM_BU(ctx->r23, 0X0);
    // 0x8001D07C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001D080: sllv        $t7, $t7, $fp
    ctx->r15 = S32(ctx->r15 << (ctx->r30 & 31));
    // 0x8001D084: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x8001D088: slt         $at, $fp, $a3
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001D08C: bne         $at, $zero, L_8001D078
    if (ctx->r1 != 0) {
        // 0x8001D090: or          $gp, $gp, $t7
        ctx->r28 = ctx->r28 | ctx->r15;
            goto L_8001D078;
    }
    // 0x8001D090: or          $gp, $gp, $t7
    ctx->r28 = ctx->r28 | ctx->r15;
L_8001D094:
    // 0x8001D094: and         $t7, $gp, $t0
    ctx->r15 = ctx->r28 & ctx->r8;
    // 0x8001D098: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001D09C: addu        $s5, $a1, $t7
    ctx->r21 = ADD32(ctx->r5, ctx->r15);
    // 0x8001D0A0: lbu         $s1, 0x0($s5)
    ctx->r17 = MEM_BU(ctx->r21, 0X0);
    // 0x8001D0A4: slti        $at, $s1, 0x11
    ctx->r1 = SIGNED(ctx->r17) < 0X11 ? 1 : 0;
    // 0x8001D0A8: bne         $at, $zero, L_8001D120
    if (ctx->r1 != 0) {
        // 0x8001D0AC: addiu       $t7, $zero, 0x63
        ctx->r15 = ADD32(0, 0X63);
            goto L_8001D120;
    }
    // 0x8001D0AC: addiu       $t7, $zero, 0x63
    ctx->r15 = ADD32(0, 0X63);
L_8001D0B0:
    // 0x8001D0B0: beq         $s1, $t7, L_8001D1D8
    if (ctx->r17 == ctx->r15) {
        // 0x8001D0B4: lbu         $t7, 0x1($s5)
        ctx->r15 = MEM_BU(ctx->r21, 0X1);
            goto L_8001D1D8;
    }
    // 0x8001D0B4: lbu         $t7, 0x1($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X1);
    // 0x8001D0B8: addiu       $s1, $s1, -0x10
    ctx->r17 = ADD32(ctx->r17, -0X10);
    // 0x8001D0BC: srlv        $gp, $gp, $t7
    ctx->r28 = S32(U32(ctx->r28) >> (ctx->r15 & 31));
    // 0x8001D0C0: subu        $fp, $fp, $t7
    ctx->r30 = SUB32(ctx->r30, ctx->r15);
    // 0x8001D0C4: slt         $at, $fp, $s1
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8001D0C8: beq         $at, $zero, L_8001D0F0
    if (ctx->r1 == 0) {
        // 0x8001D0CC: nop
    
            goto L_8001D0F0;
    }
    // 0x8001D0CC: nop

    // 0x8001D0D0: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_8001D0D4:
    // 0x8001D0D4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001D0D8: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x8001D0DC: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x8001D0E0: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x8001D0E4: slt         $at, $fp, $s1
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8001D0E8: bnel        $at, $zero, L_8001D0D4
    if (ctx->r1 != 0) {
        // 0x8001D0EC: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_8001D0D4;
    }
    goto skip_1;
    // 0x8001D0EC: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_1:
L_8001D0F0:
    // 0x8001D0F0: sll         $t7, $s1, 1
    ctx->r15 = S32(ctx->r17 << 1);
    // 0x8001D0F4: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x8001D0F8: lhu         $t7, 0x0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X0);
    // 0x8001D0FC: lhu         $t8, 0x2($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X2);
    // 0x8001D100: and         $t7, $t7, $gp
    ctx->r15 = ctx->r15 & ctx->r28;
    // 0x8001D104: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8001D108: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001D10C: addu        $s5, $s6, $t7
    ctx->r21 = ADD32(ctx->r22, ctx->r15);
    // 0x8001D110: lbu         $s1, 0x0($s5)
    ctx->r17 = MEM_BU(ctx->r21, 0X0);
    // 0x8001D114: slti        $at, $s1, 0x11
    ctx->r1 = SIGNED(ctx->r17) < 0X11 ? 1 : 0;
    // 0x8001D118: beq         $at, $zero, L_8001D0B0
    if (ctx->r1 == 0) {
        // 0x8001D11C: addiu       $t7, $zero, 0x63
        ctx->r15 = ADD32(0, 0X63);
            goto L_8001D0B0;
    }
    // 0x8001D11C: addiu       $t7, $zero, 0x63
    ctx->r15 = ADD32(0, 0X63);
L_8001D120:
    // 0x8001D120: lbu         $t7, 0x1($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X1);
    // 0x8001D124: sll         $t8, $s1, 1
    ctx->r24 = S32(ctx->r17 << 1);
    // 0x8001D128: subu        $fp, $fp, $t7
    ctx->r30 = SUB32(ctx->r30, ctx->r15);
    // 0x8001D12C: slt         $at, $fp, $s1
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8001D130: beq         $at, $zero, L_8001D154
    if (ctx->r1 == 0) {
        // 0x8001D134: srlv        $gp, $gp, $t7
        ctx->r28 = S32(U32(ctx->r28) >> (ctx->r15 & 31));
            goto L_8001D154;
    }
    // 0x8001D134: srlv        $gp, $gp, $t7
    ctx->r28 = S32(U32(ctx->r28) >> (ctx->r15 & 31));
L_8001D138:
    // 0x8001D138: lbu         $t7, 0x0($s7)
    ctx->r15 = MEM_BU(ctx->r23, 0X0);
    // 0x8001D13C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001D140: sllv        $t7, $t7, $fp
    ctx->r15 = S32(ctx->r15 << (ctx->r30 & 31));
    // 0x8001D144: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x8001D148: slt         $at, $fp, $s1
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8001D14C: bne         $at, $zero, L_8001D138
    if (ctx->r1 != 0) {
        // 0x8001D150: or          $gp, $gp, $t7
        ctx->r28 = ctx->r28 | ctx->r15;
            goto L_8001D138;
    }
    // 0x8001D150: or          $gp, $gp, $t7
    ctx->r28 = ctx->r28 | ctx->r15;
L_8001D154:
    // 0x8001D154: addu        $t7, $t8, $s0
    ctx->r15 = ADD32(ctx->r24, ctx->r16);
    // 0x8001D158: lhu         $t7, 0x0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X0);
    // 0x8001D15C: lhu         $t8, 0x2($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X2);
    // 0x8001D160: and         $t7, $t7, $gp
    ctx->r15 = ctx->r15 & ctx->r28;
    // 0x8001D164: subu        $s3, $s4, $t7
    ctx->r19 = SUB32(ctx->r20, ctx->r15);
    // 0x8001D168: subu        $s3, $s3, $t8
    ctx->r19 = SUB32(ctx->r19, ctx->r24);
    // 0x8001D16C: srlv        $gp, $gp, $s1
    ctx->r28 = S32(U32(ctx->r28) >> (ctx->r17 & 31));
    // 0x8001D170: subu        $fp, $fp, $s1
    ctx->r30 = SUB32(ctx->r30, ctx->r17);
    // 0x8001D174: addu        $t7, $s4, $s2
    ctx->r15 = ADD32(ctx->r20, ctx->r18);
    // 0x8001D178: slt         $at, $t7, $t5
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001D17C: beq         $at, $zero, L_8001D1D8
    if (ctx->r1 == 0) {
        // 0x8001D180: addu        $t8, $t3, $s3
        ctx->r24 = ADD32(ctx->r11, ctx->r19);
            goto L_8001D1D8;
    }
    // 0x8001D180: addu        $t8, $t3, $s3
    ctx->r24 = ADD32(ctx->r11, ctx->r19);
    // 0x8001D184: addu        $t9, $t3, $s4
    ctx->r25 = ADD32(ctx->r11, ctx->r20);
    // 0x8001D188: addu        $s4, $s4, $s2
    ctx->r20 = ADD32(ctx->r20, ctx->r18);
    // 0x8001D18C: lw          $v0, 0xA84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA84);
    // 0x8001D190: lw          $v1, 0xA88($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA88);
L_8001D194:
    // 0x8001D194: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x8001D198: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x8001D19C: sb          $t7, -0x1($t9)
    MEM_B(-0X1, ctx->r25) = ctx->r15;
    // 0x8001D1A0: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8001D1A4: andi        $at, $v0, 0x17
    ctx->r1 = ctx->r2 & 0X17;
    // 0x8001D1A8: sllv        $t7, $t7, $at
    ctx->r15 = S32(ctx->r15 << (ctx->r1 & 31));
    // 0x8001D1AC: xor         $v1, $v1, $t7
    ctx->r3 = ctx->r3 ^ ctx->r15;
    // 0x8001D1B0: addu        $at, $t3, $s4
    ctx->r1 = ADD32(ctx->r11, ctx->r20);
    // 0x8001D1B4: bne         $t9, $at, L_8001D194
    if (ctx->r25 != ctx->r1) {
        // 0x8001D1B8: addiu       $t8, $t8, 0x1
        ctx->r24 = ADD32(ctx->r24, 0X1);
            goto L_8001D194;
    }
    // 0x8001D1B8: addiu       $t8, $t8, 0x1
    ctx->r24 = ADD32(ctx->r24, 0X1);
    // 0x8001D1BC: sw          $v0, 0xA84($sp)
    MEM_W(0XA84, ctx->r29) = ctx->r2;
    // 0x8001D1C0: sw          $v1, 0xA88($sp)
    MEM_W(0XA88, ctx->r29) = ctx->r3;
    // 0x8001D1C4: j           L_8001CF30
    // 0x8001D1C8: slt         $at, $fp, $a2
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r6) ? 1 : 0;
        goto L_8001CF30;
    // 0x8001D1C8: slt         $at, $fp, $a2
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r6) ? 1 : 0;
L_8001D1CC:
    // 0x8001D1CC: mtc1        $s4, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r20;
    // 0x8001D1D0: jr          $ra
    // 0x8001D1D4: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    return;
    // 0x8001D1D4: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
L_8001D1D8:
    // 0x8001D1D8: jr          $ra
    // 0x8001D1DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8001D1DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void _cheggnormal_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087248: syscall     539
    recomp_syscall_handler(rdram, ctx, 0x80087248);
    return;
    // 0x8008724C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void batimer_isAt_rising(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B4: lw          $t6, 0x13C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X13C);
    // 0x808001B8: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x808001BC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x808001C0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x808001C4: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x808001C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808001CC: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x808001D0: nop

    // 0x808001D4: bc1f        L_808001E0
    if (!c1cs) {
        // 0x808001D8: nop
    
            goto L_808001E0;
    }
    // 0x808001D8: nop

    // 0x808001DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001E0:
    // 0x808001E0: beq         $v0, $zero, L_80800204
    if (ctx->r2 == 0) {
        // 0x808001E4: nop
    
            goto L_80800204;
    }
    // 0x808001E4: nop

    // 0x808001E8: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808001EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808001F0: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x808001F4: nop

    // 0x808001F8: bc1f        L_80800204
    if (!c1cs) {
        // 0x808001FC: nop
    
            goto L_80800204;
    }
    // 0x808001FC: nop

    // 0x80800200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800204:
    // 0x80800204: jr          $ra
    // 0x80800208: nop

    return;
    // 0x80800208: nop

;}
RECOMP_FUNC void _glintrosyncDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800885E0: syscall     695
    recomp_syscall_handler(rdram, ctx, 0x800885E0);
    return;
    // 0x800885E4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bskazshoesspringjump_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080010C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800110: jal         0x80800000
    // 0x80800114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800000_bskazshoesspringjump(rdram, ctx);
        goto after_0;
    // 0x80800114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800118: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080011C: jal         0x80085008
    // 0x80800120: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bashoes_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800120: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800124: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800128: jal         0x80085000
    // 0x8080012C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bashoes_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x8080012C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800130: jal         0x800832E8
    // 0x80800134: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800134: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080013C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800140: jr          $ra
    // 0x80800144: nop

    return;
    // 0x80800144: nop

;}
RECOMP_FUNC void func_8010AA78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AA78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010AA7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010AA80: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010AA84: jal         0x800EE7F8
    // 0x8010AA88: addiu       $a1, $a1, 0x6F20
    ctx->r5 = ADD32(ctx->r5, 0X6F20);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8010AA88: addiu       $a1, $a1, 0x6F20
    ctx->r5 = ADD32(ctx->r5, 0X6F20);
    after_0:
    // 0x8010AA8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010AA90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010AA94: jr          $ra
    // 0x8010AA98: nop

    return;
    // 0x8010AA98: nop

;}
RECOMP_FUNC void func_800CB618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB618: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CB61C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800CB620: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800CB624: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800CB628: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800CB62C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800CB630: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800CB634: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800CB638: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800CB63C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800CB640: addiu       $s2, $s2, -0x5488
    ctx->r18 = ADD32(ctx->r18, -0X5488);
    // 0x800CB644: addiu       $s0, $s0, -0x5490
    ctx->r16 = ADD32(ctx->r16, -0X5490);
    // 0x800CB648: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800CB64C: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
L_800CB650:
    // 0x800CB650: sb          $s1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r17;
    // 0x800CB654: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x800CB658: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800CB65C: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
    // 0x800CB660: jal         0x800EFD24
    // 0x800CB664: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x800CB664: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x800CB668: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CB66C: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x800CB670: bne         $s1, $s3, L_800CB650
    if (ctx->r17 != ctx->r19) {
        // 0x800CB674: addiu       $s2, $s2, 0x30
        ctx->r18 = ADD32(ctx->r18, 0X30);
            goto L_800CB650;
    }
    // 0x800CB674: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
    // 0x800CB678: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB67C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800CB680: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB684: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800CB688: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800CB68C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800CB690: jr          $ra
    // 0x800CB694: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800CB694: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80105834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105834: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010583C: jal         0x801054D4
    // 0x80105840: nop

    func_801054D4(rdram, ctx);
        goto after_0;
    // 0x80105840: nop

    after_0:
    // 0x80105844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105848: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010584C: jr          $ra
    // 0x80105850: nop

    return;
    // 0x80105850: nop

;}
RECOMP_FUNC void func_80800270_chfactorytoxicpools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800270: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800278: jal         0x80100094
    // 0x8080027C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080027C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800280: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800284: jal         0x800BEA88
    // 0x80800288: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEA88(rdram, ctx);
        goto after_1;
    // 0x80800288: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8080028C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800290: jal         0x80088F10
    // 0x80800294: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _idworld_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800294: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800298: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080029C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002A0: jal         0x80088E98
    // 0x808002A4: lh          $a1, 0x0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X0);
    _idwibble_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808002A4: lh          $a1, 0x0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X0);
    after_3:
    // 0x808002A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002B0: jr          $ra
    // 0x808002B4: nop

    return;
    // 0x808002B4: nop

;}
RECOMP_FUNC void func_8009E880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E880: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8009E884: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009E888: addiu       $a0, $a0, 0x7040
    ctx->r4 = ADD32(ctx->r4, 0X7040);
    // 0x8009E88C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009E890: addiu       $v0, $v0, 0x7068
    ctx->r2 = ADD32(ctx->r2, 0X7068);
    // 0x8009E894: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8009E898: sb          $v1, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r3;
    // 0x8009E89C: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    // 0x8009E8A0: sb          $v1, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r3;
    // 0x8009E8A4: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x8009E8A8: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8009E8AC: jr          $ra
    // 0x8009E8B0: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8009E8B0: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_800964D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800964D0: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x800964D4: jr          $ra
    // 0x800964D8: lw          $v0, 0xA8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0XA8);
    return;
    // 0x800964D8: lw          $v0, 0xA8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0XA8);
;}
RECOMP_FUNC void func_808011B4_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011BC: jal         0x80085148
    // 0x808011C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _baspin_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808011C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808011C4: jal         0x808000F0
    // 0x808011C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000F0_bswasher(rdram, ctx);
        goto after_1;
    // 0x808011C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808011CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011D4: jr          $ra
    // 0x808011D8: nop

    return;
    // 0x808011D8: nop

;}
RECOMP_FUNC void func_80801658_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801658: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8080165C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801660: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801664: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801668: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080166C: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x80801670: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80801674: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80801678: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080167C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80801680: jal         0x800D0A9C
    // 0x80801684: sw          $t7, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r15;
    func_800D0A9C(rdram, ctx);
        goto after_0;
    // 0x80801684: sw          $t7, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r15;
    after_0:
    // 0x80801688: beql        $v0, $zero, L_808016A4
    if (ctx->r2 == 0) {
        // 0x8080168C: addiu       $a0, $zero, 0x2BA
        ctx->r4 = ADD32(0, 0X2BA);
            goto L_808016A4;
    }
    goto skip_0;
    // 0x8080168C: addiu       $a0, $zero, 0x2BA
    ctx->r4 = ADD32(0, 0X2BA);
    skip_0:
    // 0x80801690: jal         0x800D395C
    // 0x80801694: nop

    func_800D395C(rdram, ctx);
        goto after_1;
    // 0x80801694: nop

    after_1:
    // 0x80801698: beq         $v0, $zero, L_808016B8
    if (ctx->r2 == 0) {
        // 0x8080169C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_808016B8;
    }
    // 0x8080169C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808016A0: addiu       $a0, $zero, 0x2BA
    ctx->r4 = ADD32(0, 0X2BA);
L_808016A4:
    // 0x808016A4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808016A8: jal         0x800882C0
    // 0x808016AC: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x808016AC: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_2:
    // 0x808016B0: b           L_808016B8
    // 0x808016B4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_808016B8;
    // 0x808016B4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_808016B8:
    // 0x808016B8: blez        $s2, L_808016E8
    if (SIGNED(ctx->r18) <= 0) {
        // 0x808016BC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_808016E8;
    }
    // 0x808016BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808016C0: addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
L_808016C4:
    // 0x808016C4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x808016C8: addiu       $a0, $zero, 0x2BE
    ctx->r4 = ADD32(0, 0X2BE);
    // 0x808016CC: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x808016D0: srl         $t8, $a2, 23
    ctx->r24 = S32(U32(ctx->r6) >> 23);
    // 0x808016D4: jal         0x801085CC
    // 0x808016D8: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    func_801085CC(rdram, ctx);
        goto after_3;
    // 0x808016D8: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_3:
    // 0x808016DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808016E0: bne         $s0, $s2, L_808016C4
    if (ctx->r16 != ctx->r18) {
        // 0x808016E4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_808016C4;
    }
    // 0x808016E4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_808016E8:
    // 0x808016E8: jal         0x80106790
    // 0x808016EC: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x808016EC: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    after_4:
    // 0x808016F0: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x808016F4: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x808016F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808016FC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80801700: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801704: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801708: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080170C: jr          $ra
    // 0x80801710: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80801710: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
