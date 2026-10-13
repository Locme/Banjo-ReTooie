#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800DE03C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE03C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DE044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE048: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800DE04C: lbu         $a2, 0xA($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0XA);
    // 0x800DE050: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DE054: lw          $a0, -0x3690($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3690);
    // 0x800DE058: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800DE05C: jal         0x80087930
    // 0x800DE060: addiu       $a1, $a1, 0xD
    ctx->r5 = ADD32(ctx->r5, 0XD);
    _dbzone_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800DE060: addiu       $a1, $a1, 0xD
    ctx->r5 = ADD32(ctx->r5, 0XD);
    after_0:
    // 0x800DE064: bne         $v0, $zero, L_800DE07C
    if (ctx->r2 != 0) {
        // 0x800DE068: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_800DE07C;
    }
    // 0x800DE068: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800DE06C: lbu         $t6, 0xB($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XB);
    // 0x800DE070: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800DE074: bne         $t7, $zero, L_800DE090
    if (ctx->r15 != 0) {
        // 0x800DE078: nop
    
            goto L_800DE090;
    }
    // 0x800DE078: nop

L_800DE07C:
    // 0x800DE07C: beql        $v0, $zero, L_800DE0CC
    if (ctx->r2 == 0) {
        // 0x800DE080: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DE0CC;
    }
    goto skip_0;
    // 0x800DE080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800DE084: lbu         $t8, 0xB($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0XB);
    // 0x800DE088: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x800DE08C: beq         $t9, $zero, L_800DE0C8
    if (ctx->r25 == 0) {
        // 0x800DE090: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DE0C8;
    }
L_800DE090:
    // 0x800DE090: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DE094: lw          $a0, -0x37B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X37B8);
    // 0x800DE098: beql        $a0, $zero, L_800DE0BC
    if (ctx->r4 == 0) {
        // 0x800DE09C: lh          $t0, 0x8($a3)
        ctx->r8 = MEM_H(ctx->r7, 0X8);
            goto L_800DE0BC;
    }
    goto skip_1;
    // 0x800DE09C: lh          $t0, 0x8($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X8);
    skip_1:
    // 0x800DE0A0: lbu         $v0, 0xC($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0XC);
    // 0x800DE0A4: beq         $v0, $zero, L_800DE0B8
    if (ctx->r2 == 0) {
        // 0x800DE0A8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800DE0B8;
    }
    // 0x800DE0A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800DE0AC: jal         0x80088778
    // 0x800DE0B0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    _glzone_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x800DE0B0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x800DE0B4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_800DE0B8:
    // 0x800DE0B8: lh          $t0, 0x8($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X8);
L_800DE0BC:
    // 0x800DE0BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800DE0C0: jal         0x800DE2A4
    // 0x800DE0C4: addu        $a1, $a3, $t0
    ctx->r5 = ADD32(ctx->r7, ctx->r8);
    func_800DE2A4(rdram, ctx);
        goto after_2;
    // 0x800DE0C4: addu        $a1, $a3, $t0
    ctx->r5 = ADD32(ctx->r7, ctx->r8);
    after_2:
L_800DE0C8:
    // 0x800DE0C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DE0CC:
    // 0x800DE0CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DE0D0: jr          $ra
    // 0x800DE0D4: nop

    return;
    // 0x800DE0D4: nop

;}
RECOMP_FUNC void _bainvisible_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800854B0: syscall     164
    recomp_syscall_handler(rdram, ctx, 0x800854B0);
    return;
    // 0x800854B4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800380_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800388: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8080038C: lhu         $t8, 0x76($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X76);
    // 0x80800390: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800394: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80800398: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x8080039C: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x808003A0: jal         0x800DA298
    // 0x808003A4: addiu       $a0, $a0, 0x379
    ctx->r4 = ADD32(ctx->r4, 0X379);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808003A4: addiu       $a0, $a0, 0x379
    ctx->r4 = ADD32(ctx->r4, 0X379);
    after_0:
    // 0x808003A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003B0: jr          $ra
    // 0x808003B4: nop

    return;
    // 0x808003B4: nop

;}
RECOMP_FUNC void glidmake_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800048: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8080004C: jal         0x808000F0
    // 0x80800050: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    glidmake_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800050: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80800054: lh          $t6, 0x18($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X18);
    // 0x80800058: lh          $t7, 0x20($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X20);
    // 0x8080005C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80800060: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800064: bgez        $t8, L_80800074
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800068: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_80800074;
    }
    // 0x80800068: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8080006C: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x80800070: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80800074:
    // 0x80800074: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x80800078: lh          $t1, 0x22($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X22);
    // 0x8080007C: lh          $t0, 0x1A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X1A);
    // 0x80800080: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80800084: bgez        $t2, L_80800094
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800088: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80800094;
    }
    // 0x80800088: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8080008C: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80800090: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80800094:
    // 0x80800094: sh          $t3, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r11;
    // 0x80800098: lh          $t5, 0x24($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X24);
    // 0x8080009C: lh          $t4, 0x1C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X1C);
    // 0x808000A0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x808000A4: bgez        $t6, L_808000B4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808000A8: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_808000B4;
    }
    // 0x808000A8: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x808000AC: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x808000B0: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_808000B4:
    // 0x808000B4: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x808000B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000C0: jr          $ra
    // 0x808000C4: nop

    return;
    // 0x808000C4: nop

;}
RECOMP_FUNC void _bavan_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085398: syscall     159
    recomp_syscall_handler(rdram, ctx, 0x80085398);
    return;
    // 0x8008539C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void dbanim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800004: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800008: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80800014: or          $fp, $a2, $zero
    ctx->r30 = ctx->r6 | 0;
    // 0x80800018: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8080001C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800020: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800024: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800028: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080002C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800030: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800034: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800038: jal         0x800B2190
    // 0x8080003C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800B2190(rdram, ctx);
        goto after_0;
    // 0x8080003C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800040: lh          $t6, 0x2($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X2);
    // 0x80800044: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800048: addiu       $s2, $s6, 0x4
    ctx->r18 = ADD32(ctx->r22, 0X4);
    // 0x8080004C: blez        $t6, L_80800124
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800050: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_80800124;
    }
    // 0x80800050: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80800054: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x80800058: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x8080005C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_80800060:
    // 0x80800060: jal         0x80100480
    // 0x80800064: lh          $a1, 0x2($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X2);
    func_80100480(rdram, ctx);
        goto after_1;
    // 0x80800064: lh          $a1, 0x2($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X2);
    after_1:
    // 0x80800068: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080006C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80800070: jal         0x800ADE2C
    // 0x80800074: lh          $a1, 0x0($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X0);
    func_800ADE2C(rdram, ctx);
        goto after_2;
    // 0x80800074: lh          $a1, 0x0($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X0);
    after_2:
    // 0x80800078: addiu       $s4, $s2, 0x6
    ctx->r20 = ADD32(ctx->r18, 0X6);
    // 0x8080007C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800080: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800084: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800088: jal         0x80116568
    // 0x8080008C: lh          $a3, 0x2($s2)
    ctx->r7 = MEM_H(ctx->r18, 0X2);
    func_80116568(rdram, ctx);
        goto after_3;
    // 0x8080008C: lh          $a3, 0x2($s2)
    ctx->r7 = MEM_H(ctx->r18, 0X2);
    after_3:
    // 0x80800090: lh          $t7, 0x2($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X2);
    // 0x80800094: lh          $t0, 0x0($s6)
    ctx->r8 = MEM_H(ctx->r22, 0X0);
    // 0x80800098: multu       $t7, $s7
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080009C: mflo        $t8
    ctx->r24 = lo;
    // 0x808000A0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x808000A4: beq         $t0, $zero, L_808000B8
    if (ctx->r8 == 0) {
        // 0x808000A8: addu        $a0, $s4, $t9
        ctx->r4 = ADD32(ctx->r20, ctx->r25);
            goto L_808000B8;
    }
    // 0x808000A8: addu        $a0, $s4, $t9
    ctx->r4 = ADD32(ctx->r20, ctx->r25);
    // 0x808000AC: lh          $t2, 0x4($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X4);
    // 0x808000B0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x808000B4: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
L_808000B8:
    // 0x808000B8: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x808000BC: slti        $at, $v1, -0x1
    ctx->r1 = SIGNED(ctx->r3) < -0X1 ? 1 : 0;
    // 0x808000C0: bnel        $at, $zero, L_80800110
    if (ctx->r1 != 0) {
        // 0x808000C4: lh          $t8, 0x2($s6)
        ctx->r24 = MEM_H(ctx->r22, 0X2);
            goto L_80800110;
    }
    goto skip_0;
    // 0x808000C4: lh          $t8, 0x2($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X2);
    skip_0:
L_808000C8:
    // 0x808000C8: bnel        $s1, $v1, L_808000DC
    if (ctx->r17 != ctx->r3) {
        // 0x808000CC: lh          $t5, 0x0($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X0);
            goto L_808000DC;
    }
    goto skip_1;
    // 0x808000CC: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    skip_1:
    // 0x808000D0: b           L_808000F8
    // 0x808000D4: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
        goto L_808000F8;
    // 0x808000D4: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x808000D8: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
L_808000DC:
    // 0x808000DC: sll         $t4, $v1, 4
    ctx->r12 = S32(ctx->r3 << 4);
    // 0x808000E0: addu        $v0, $t4, $s3
    ctx->r2 = ADD32(ctx->r12, ctx->r19);
    // 0x808000E4: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x808000E8: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x808000EC: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x808000F0: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x808000F4: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
L_808000F8:
    // 0x808000F8: lh          $v1, 0x2($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X2);
    // 0x808000FC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80800100: slti        $at, $v1, -0x1
    ctx->r1 = SIGNED(ctx->r3) < -0X1 ? 1 : 0;
    // 0x80800104: beq         $at, $zero, L_808000C8
    if (ctx->r1 == 0) {
        // 0x80800108: nop
    
            goto L_808000C8;
    }
    // 0x80800108: nop

    // 0x8080010C: lh          $t8, 0x2($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X2);
L_80800110:
    // 0x80800110: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80800114: addiu       $s2, $a0, 0x2
    ctx->r18 = ADD32(ctx->r4, 0X2);
    // 0x80800118: slt         $at, $s5, $t8
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8080011C: bnel        $at, $zero, L_80800060
    if (ctx->r1 != 0) {
        // 0x80800120: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_80800060;
    }
    goto skip_2;
    // 0x80800120: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    skip_2:
L_80800124:
    // 0x80800124: jal         0x800B2344
    // 0x80800128: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800B2344(rdram, ctx);
        goto after_4;
    // 0x80800128: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_4:
    // 0x8080012C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800130: jal         0x8002E660
    // 0x80800134: sll         $a1, $v0, 4
    ctx->r5 = S32(ctx->r2 << 4);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_5;
    // 0x80800134: sll         $a1, $v0, 4
    ctx->r5 = S32(ctx->r2 << 4);
    after_5:
    // 0x80800138: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8080013C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800140: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800144: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800148: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080014C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800150: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800154: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800158: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8080015C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80800160: jr          $ra
    // 0x80800164: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800164: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _suflamefx_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089958: syscall     798
    recomp_syscall_handler(rdram, ctx, 0x80089958);
    return;
    // 0x8008995C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800F8C_sumumbofx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800F90: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(3146, 0X14DC) << 16);
    // 0x80800F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F98: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800F9C: addiu       $t6, $t6, 0x14DC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(3146, 0X14DC));
    // 0x80800FA0: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80800FA4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80800FA8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800FAC: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80800FB0: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80800FB4: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80800FB8: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80800FBC: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x80800FC0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80800FC4: addiu       $a2, $t0, 0x3C
    ctx->r6 = ADD32(ctx->r8, 0X3C);
    // 0x80800FC8: jal         0x800F3214
    // 0x80800FCC: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    func_800F3214(rdram, ctx);
        goto after_0;
    // 0x80800FCC: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    after_0:
    // 0x80800FD0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80800FD4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800FD8: jal         0x800C8E84
    // 0x80800FDC: lh          $a0, 0x5E($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X5E);
    func_800C8E84(rdram, ctx);
        goto after_1;
    // 0x80800FDC: lh          $a0, 0x5E($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X5E);
    after_1:
    // 0x80800FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FE4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800FE8: jr          $ra
    // 0x80800FEC: nop

    return;
    // 0x80800FEC: nop

;}
RECOMP_FUNC void _chcactusofstrength_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C40: syscall     211
    recomp_syscall_handler(rdram, ctx, 0x80085C40);
    return;
    // 0x80085C44: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8001D4C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D4C4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8001D4C8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8001D4CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001D4D0: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8001D4D4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001D4D8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8001D4DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001D4E0: bgez        $t6, L_8001D4F8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8001D4E4: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8001D4F8;
    }
    // 0x8001D4E4: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001D4E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001D4EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001D4F0: nop

    // 0x8001D4F4: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_8001D4F8:
    // 0x8001D4F8: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x8001D4FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001D500: bgez        $a1, L_8001D514
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8001D504: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8001D514;
    }
    // 0x8001D504: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001D508: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001D50C: nop

    // 0x8001D510: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8001D514:
    // 0x8001D514: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8001D518: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001D51C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8001D520: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8001D524: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8001D528: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001D52C: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8001D530: nop

    // 0x8001D534: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001D538: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8001D53C: nop

    // 0x8001D540: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8001D544: beql        $v0, $zero, L_8001D5AC
    if (ctx->r2 == 0) {
        // 0x8001D548: mfc1        $v0, $f8
        ctx->r2 = (int32_t)ctx->f8.u32l;
            goto L_8001D5AC;
    }
    goto skip_0;
    // 0x8001D548: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x8001D54C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D550: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001D554: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8001D558: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8001D55C: nop

    // 0x8001D560: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001D564: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8001D568: nop

    // 0x8001D56C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8001D570: bnel        $v0, $zero, L_8001D598
    if (ctx->r2 != 0) {
        // 0x8001D574: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8001D598;
    }
    goto skip_1;
    // 0x8001D574: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x8001D578: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8001D57C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D580: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001D584: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x8001D588: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8001D58C: jr          $ra
    // 0x8001D590: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    return;
    // 0x8001D590: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8001D594:
    // 0x8001D594: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001D598:
    // 0x8001D598: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8001D59C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001D5A0: jr          $ra
    // 0x8001D5A4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    return;
    // 0x8001D5A4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8001D5A8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
L_8001D5AC:
    // 0x8001D5AC: nop

    // 0x8001D5B0: bltz        $v0, L_8001D594
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001D5B4: andi        $t9, $v0, 0xFF
        ctx->r25 = ctx->r2 & 0XFF;
            goto L_8001D594;
    }
    // 0x8001D5B4: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8001D5B8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001D5BC: jr          $ra
    // 0x8001D5C0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    return;
    // 0x8001D5C0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
;}
RECOMP_FUNC void gcgoto_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080059C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005A4: jal         0x8080011C
    // 0x808005A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8080011C_gcgoto(rdram, ctx);
        goto after_0;
    // 0x808005A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x808005AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005B4: jr          $ra
    // 0x808005B8: nop

    return;
    // 0x808005B8: nop

;}
RECOMP_FUNC void _bscrouch_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F60: syscall     36
    recomp_syscall_handler(rdram, ctx, 0x80082F60);
    return;
    // 0x80082F64: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bsbtrot_entrypoint_40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802484: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080248C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802490: jal         0x80802380
    // 0x80802494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802380_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80802494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802498: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080249C: jal         0x80085008
    // 0x808024A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bashoes_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808024A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808024A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808024A8: jal         0x80085000
    // 0x808024AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bashoes_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x808024AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808024B0: jal         0x8080061C
    // 0x808024B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080061C_bsbtrot(rdram, ctx);
        goto after_3;
    // 0x808024B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808024B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808024BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808024C0: jr          $ra
    // 0x808024C4: nop

    return;
    // 0x808024C4: nop

;}
RECOMP_FUNC void func_800A96F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A96F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A96F4: addiu       $v0, $v0, 0x76D0
    ctx->r2 = ADD32(ctx->r2, 0X76D0);
    // 0x800A96F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A96FC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_800A9700:
    // 0x800A9700: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x800A9704: bnel        $a0, $t6, L_800A9718
    if (ctx->r4 != ctx->r14) {
        // 0x800A9708: lh          $t7, 0xA($v0)
        ctx->r15 = MEM_H(ctx->r2, 0XA);
            goto L_800A9718;
    }
    goto skip_0;
    // 0x800A9708: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    skip_0:
    // 0x800A970C: jr          $ra
    // 0x800A9710: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800A9710: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800A9714: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
L_800A9718:
    // 0x800A9718: bnel        $a0, $t7, L_800A972C
    if (ctx->r4 != ctx->r15) {
        // 0x800A971C: lh          $t8, 0xC($v0)
        ctx->r24 = MEM_H(ctx->r2, 0XC);
            goto L_800A972C;
    }
    goto skip_1;
    // 0x800A971C: lh          $t8, 0xC($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XC);
    skip_1:
    // 0x800A9720: jr          $ra
    // 0x800A9724: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    return;
    // 0x800A9724: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800A9728: lh          $t8, 0xC($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XC);
L_800A972C:
    // 0x800A972C: bnel        $a0, $t8, L_800A9740
    if (ctx->r4 != ctx->r24) {
        // 0x800A9730: lh          $t9, 0xE($v0)
        ctx->r25 = MEM_H(ctx->r2, 0XE);
            goto L_800A9740;
    }
    goto skip_2;
    // 0x800A9730: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    skip_2:
    // 0x800A9734: jr          $ra
    // 0x800A9738: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    return;
    // 0x800A9738: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x800A973C: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
L_800A9740:
    // 0x800A9740: bnel        $a0, $t9, L_800A9754
    if (ctx->r4 != ctx->r25) {
        // 0x800A9744: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800A9754;
    }
    goto skip_3;
    // 0x800A9744: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_3:
    // 0x800A9748: jr          $ra
    // 0x800A974C: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    return;
    // 0x800A974C: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // 0x800A9750: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800A9754:
    // 0x800A9754: bne         $v1, $a1, L_800A9700
    if (ctx->r3 != ctx->r5) {
        // 0x800A9758: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_800A9700;
    }
    // 0x800A9758: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800A975C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800A9760: jr          $ra
    // 0x800A9764: nop

    return;
    // 0x800A9764: nop

;}
RECOMP_FUNC void func_808004A8_ch2dbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004B0: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808004B4: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x808004B8: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808004BC: beq         $t6, $at, L_808004DC
    if (ctx->r14 == ctx->r1) {
        // 0x808004C0: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_808004DC;
    }
    // 0x808004C0: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x808004C4: bnel        $t6, $at, L_808004E8
    if (ctx->r14 != ctx->r1) {
        // 0x808004C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004E8;
    }
    goto skip_0;
    // 0x808004C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808004CC: jal         0x8008A148
    // 0x808004D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x808004D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x808004D4: b           L_808004E8
    // 0x808004D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808004E8;
    // 0x808004D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004DC:
    // 0x808004DC: jal         0x80800700
    // 0x808004E0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80800700_ch2dbaddy(rdram, ctx);
        goto after_1;
    // 0x808004E0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_1:
    // 0x808004E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004E8:
    // 0x808004E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004EC: jr          $ra
    // 0x808004F0: nop

    return;
    // 0x808004F0: nop

;}
RECOMP_FUNC void func_800E7324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7324: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800E7328: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800E732C: beq         $t6, $zero, L_800E7360
    if (ctx->r14 == 0) {
        // 0x800E7330: nop
    
            goto L_800E7360;
    }
    // 0x800E7330: nop

    // 0x800E7334: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800E7338: slti        $at, $v1, 0x41
    ctx->r1 = SIGNED(ctx->r3) < 0X41 ? 1 : 0;
L_800E733C:
    // 0x800E733C: bne         $at, $zero, L_800E7350
    if (ctx->r1 != 0) {
        // 0x800E7340: slti        $at, $v1, 0x5B
        ctx->r1 = SIGNED(ctx->r3) < 0X5B ? 1 : 0;
            goto L_800E7350;
    }
    // 0x800E7340: slti        $at, $v1, 0x5B
    ctx->r1 = SIGNED(ctx->r3) < 0X5B ? 1 : 0;
    // 0x800E7344: beq         $at, $zero, L_800E7350
    if (ctx->r1 == 0) {
        // 0x800E7348: addiu       $t7, $v1, 0x20
        ctx->r15 = ADD32(ctx->r3, 0X20);
            goto L_800E7350;
    }
    // 0x800E7348: addiu       $t7, $v1, 0x20
    ctx->r15 = ADD32(ctx->r3, 0X20);
    // 0x800E734C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_800E7350:
    // 0x800E7350: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x800E7354: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800E7358: bnel        $v1, $zero, L_800E733C
    if (ctx->r3 != 0) {
        // 0x800E735C: slti        $at, $v1, 0x41
        ctx->r1 = SIGNED(ctx->r3) < 0X41 ? 1 : 0;
            goto L_800E733C;
    }
    goto skip_0;
    // 0x800E735C: slti        $at, $v1, 0x41
    ctx->r1 = SIGNED(ctx->r3) < 0X41 ? 1 : 0;
    skip_0:
L_800E7360:
    // 0x800E7360: jr          $ra
    // 0x800E7364: nop

    return;
    // 0x800E7364: nop

;}
RECOMP_FUNC void bsbshock_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800504: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800508: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080050C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800510: jal         0x8008CABC
    // 0x80800514: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800514: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800518: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080051C: jal         0x8008AF24
    // 0x80800520: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800520: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800524: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800528: jal         0x8008B1A0
    // 0x8080052C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x8080052C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800530: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800534: jal         0x8008AED4
    // 0x80800538: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80800538: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    after_3:
    // 0x8080053C: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800540: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800544: jal         0x8008B1BC
    // 0x80800548: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x80800548: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x8080054C: lui         $a1, 0x3F2C
    ctx->r5 = S32(0X3F2C << 16);
    // 0x80800550: ori         $a1, $a1, 0x84B6
    ctx->r5 = ctx->r5 | 0X84B6;
    // 0x80800554: jal         0x8008B24C
    // 0x80800558: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setStart(rdram, ctx);
        goto after_5;
    // 0x80800558: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x8080055C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800560: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800564: jal         0x8008B1D4
    // 0x80800568: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_6;
    // 0x80800568: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_6:
    // 0x8080056C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800570: jal         0x8008B134
    // 0x80800574: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x80800574: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800578: jal         0x8008B064
    // 0x8080057C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x8080057C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_8:
    // 0x80800580: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800584: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080058C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800590: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800594: jal         0x8009FFD8
    // 0x80800598: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_9;
    // 0x80800598: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_9:
    // 0x8080059C: jal         0x8009EF04
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_10;
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808005A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808005A8: nop

    // 0x808005AC: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808005B0: nop

    // 0x808005B4: bc1t        L_808005D0
    if (c1cs) {
        // 0x808005B8: nop
    
            goto L_808005D0;
    }
    // 0x808005B8: nop

    // 0x808005BC: jal         0x8009EEB8
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_11;
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808005C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005C8: jal         0x8009C914
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_12;
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_808005D0:
    // 0x808005D0: jal         0x8009C990
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_13;
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808005D8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005DC: jal         0x8009B9C0
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_14;
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808005E4: jal         0x800841D8
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_15;
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808005EC: jal         0x8009C990
    // 0x808005F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_16;
    // 0x808005F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808005F4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808005F8: jal         0x8009BB00
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_17;
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800600: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800608: jal         0x8009BA68
    // 0x8080060C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x8080060C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_18:
    // 0x80800610: lui         $a1, 0x449C
    ctx->r5 = S32(0X449C << 16);
    // 0x80800614: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x80800618: jal         0x8009BA58
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_19;
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800624: jal         0x8009BCB4
    // 0x80800628: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_20;
    // 0x80800628: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_20:
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800630: addiu       $a1, $zero, 0x408
    ctx->r5 = ADD32(0, 0X408);
    // 0x80800634: jal         0x8009DBF0
    // 0x80800638: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DBF0(rdram, ctx);
        goto after_21;
    // 0x80800638: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_21:
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800640: jal         0x800A0CE8
    // 0x80800644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CE8(rdram, ctx);
        goto after_22;
    // 0x80800644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080064C: jal         0x800A0CF4
    // 0x80800650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_23;
    // 0x80800650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80800654: jal         0x800C6DA0
    // 0x80800658: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    func_800C6DA0(rdram, ctx);
        goto after_24;
    // 0x80800658: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    after_24:
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800660: jal         0x80093300
    // 0x80800664: lui         $a1, 0xC2AE
    ctx->r5 = S32(0XC2AE << 16);
    func_80093300(rdram, ctx);
        goto after_25;
    // 0x80800664: lui         $a1, 0xC2AE
    ctx->r5 = S32(0XC2AE << 16);
    after_25:
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080066C: jal         0x8009C1B4
    // 0x80800670: lui         $a1, 0xC2AE
    ctx->r5 = S32(0XC2AE << 16);
    func_8009C1B4(rdram, ctx);
        goto after_26;
    // 0x80800670: lui         $a1, 0xC2AE
    ctx->r5 = S32(0XC2AE << 16);
    after_26:
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800678: addiu       $a1, $zero, 0x43A
    ctx->r5 = ADD32(0, 0X43A);
    // 0x8080067C: jal         0x8009DF58
    // 0x80800680: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DF58(rdram, ctx);
        goto after_27;
    // 0x80800680: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_27:
    // 0x80800684: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x80800688: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080068C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800690: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800694: jr          $ra
    // 0x80800698: nop

    return;
    // 0x80800698: nop

;}
RECOMP_FUNC void suegg_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080014C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800150: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800154: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800158: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080015C: jal         0x80100094
    // 0x80800160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800164: lw          $t6, 0x3C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X3C);
    // 0x80800168: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080016C: beq         $t6, $zero, L_808001B8
    if (ctx->r14 == 0) {
        // 0x80800170: nop
    
            goto L_808001B8;
    }
    // 0x80800170: nop

    // 0x80800174: lw          $t7, 0x38($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X38);
    // 0x80800178: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080017C: sll         $t9, $t7, 10
    ctx->r25 = S32(ctx->r15 << 10);
    // 0x80800180: bgez        $t9, L_80800198
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800184: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80800198;
    }
    // 0x80800184: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800188: jal         0x800C8B84
    // 0x8080018C: lw          $a0, 0x3C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X3C);
    func_800C8B84(rdram, ctx);
        goto after_1;
    // 0x8080018C: lw          $a0, 0x3C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X3C);
    after_1:
    // 0x80800190: b           L_808001B8
    // 0x80800194: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
        goto L_808001B8;
    // 0x80800194: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
L_80800198:
    // 0x80800198: jal         0x800C8CB8
    // 0x8080019C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_800C8CB8(rdram, ctx);
        goto after_2;
    // 0x8080019C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_2:
    // 0x808001A0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x808001A4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808001A8: jal         0x800863E8
    // 0x808001AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808001AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x808001B0: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x808001B4: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
L_808001B8:
    // 0x808001B8: jal         0x80800A6C
    // 0x808001BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    suegg_entrypoint_15(rdram, ctx);
        goto after_4;
    // 0x808001BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808001C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001CC: jr          $ra
    // 0x808001D0: nop

    return;
    // 0x808001D0: nop

;}
RECOMP_FUNC void func_800F4CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4CC0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4CC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4CC8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4CD0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4CD4: jal         0x80091E6C
    // 0x800F4CD8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_80091E6C(rdram, ctx);
        goto after_0;
    // 0x800F4CD8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F4CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4CE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4CE4: jr          $ra
    // 0x800F4CE8: nop

    return;
    // 0x800F4CE8: nop

;}
RECOMP_FUNC void func_8002628C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002628C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026290: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80026294: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80026298: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002629C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800262A0: lbu         $t7, 0x2B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2B);
    // 0x800262A4: addiu       $t6, $zero, 0x41
    ctx->r14 = ADD32(0, 0X41);
    // 0x800262A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800262AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800262B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800262B4: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x800262B8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800262BC: jal         0x8002ACE0
    // 0x800262C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_8002ACE0(rdram, ctx);
        goto after_0;
    // 0x800262C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x800262C4: b           L_800262CC
    // 0x800262C8: nop

        goto L_800262CC;
    // 0x800262C8: nop

L_800262CC:
    // 0x800262CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800262D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800262D4: jr          $ra
    // 0x800262D8: nop

    return;
    // 0x800262D8: nop

;}
RECOMP_FUNC void _chfactoryflypad_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086498: syscall     328
    recomp_syscall_handler(rdram, ctx, 0x80086498);
    return;
    // 0x8008649C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800121AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800121AC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800121B0: lui         $t7, 0x8001
    ctx->r15 = S32(0X8001 << 16);
    // 0x800121B4: addiu       $t7, $t7, 0x2030
    ctx->r15 = ADD32(ctx->r15, 0X2030);
    // 0x800121B8: addiu       $t6, $t6, 0x7390
    ctx->r14 = ADD32(ctx->r14, 0X7390);
    // 0x800121BC: lui         $at, 0xFFF2
    ctx->r1 = S32(0XFFF2 << 16);
    // 0x800121C0: ori         $at, $at, 0x1DD0
    ctx->r1 = ctx->r1 | 0X1DD0;
    // 0x800121C4: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x800121C8: jr          $ra
    // 0x800121CC: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
    return;
    // 0x800121CC: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
;}
RECOMP_FUNC void func_808009E4_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009EC: jal         0x800DA298
    // 0x808009F0: addiu       $a0, $zero, 0x433
    ctx->r4 = ADD32(0, 0X433);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808009F0: addiu       $a0, $zero, 0x433
    ctx->r4 = ADD32(0, 0X433);
    after_0:
    // 0x808009F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009FC: jr          $ra
    // 0x80800A00: nop

    return;
    // 0x80800A00: nop

;}
RECOMP_FUNC void _bskazstilt_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083668: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083668);
    return;
    // 0x8008366C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80090708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090708: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009070C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090710: jal         0x800F54E4
    // 0x80090714: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090714: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80090718: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009071C: jal         0x800F82D4
    // 0x80090720: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F82D4(rdram, ctx);
        goto after_1;
    // 0x80090720: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80090724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009072C: jr          $ra
    // 0x80090730: nop

    return;
    // 0x80090730: nop

;}
RECOMP_FUNC void func_801150F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801150F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801150FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80115100: jal         0x8001B084
    // 0x80115104: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x80115104: nop

    after_0:
    // 0x80115108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8011510C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80115110: jr          $ra
    // 0x80115114: nop

    return;
    // 0x80115114: nop

;}
RECOMP_FUNC void _chelectricfence_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800862C0: syscall     301
    recomp_syscall_handler(rdram, ctx, 0x800862C0);
    return;
    // 0x800862C4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void gcnewoption_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080146C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80801470: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80801474: jr          $ra
    // 0x80801478: lh          $v0, 0xB0($t7)
    ctx->r2 = MEM_H(ctx->r15, 0XB0);
    return;
    // 0x80801478: lh          $v0, 0xB0($t7)
    ctx->r2 = MEM_H(ctx->r15, 0XB0);
;}
RECOMP_FUNC void chstoneballcoach_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800388: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1616, 0X3D4) << 16);
    // 0x8080038C: jr          $ra
    // 0x80800390: addiu       $v0, $v0, 0x3D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1616, 0X3D4));
    return;
    // 0x80800390: addiu       $v0, $v0, 0x3D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1616, 0X3D4));
    // 0x80800394: nop

    // 0x80800398: nop

    // 0x8080039C: nop

;}
RECOMP_FUNC void func_80800778_chfactorylight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800778: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x8080077C: lui         $v0, 0xFFFF
    ctx->r2 = S32(0XFFFF << 16);
    // 0x80800780: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
    // 0x80800784: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800788: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x8080078C: beq         $at, $zero, L_80800800
    if (ctx->r1 == 0) {
        // 0x80800790: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800800;
    }
    // 0x80800790: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800794: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1100, 0XB60) << 16);
    // 0x80800798: addu        $at, $at, $t7
    gpr jr_addend_808007A0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080079C: lw          $t7, 0xB60($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1100, 0XB60));
    // 0x808007A0: jr          $t7
    // 0x808007A4: nop

    switch (jr_addend_808007A0 >> 2) {
        case 0: goto L_808007A8; break;
        case 1: goto L_808007B4; break;
        case 2: goto L_808007BC; break;
        case 3: goto L_808007C8; break;
        case 4: goto L_808007D4; break;
        case 5: goto L_808007E0; break;
        case 6: goto L_808007EC; break;
        case 7: goto L_808007F8; break;
        default: switch_error(__func__, 0x808007A0, 0x80800B60);
    }
    // 0x808007A4: nop

L_808007A8:
    // 0x808007A8: lui         $v0, 0xFFFF
    ctx->r2 = S32(0XFFFF << 16);
    // 0x808007AC: b           L_80800800
    // 0x808007B0: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
        goto L_80800800;
    // 0x808007B0: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
L_808007B4:
    // 0x808007B4: b           L_80800800
    // 0x808007B8: lui         $v0, 0x20FF
    ctx->r2 = S32(0X20FF << 16);
        goto L_80800800;
    // 0x808007B8: lui         $v0, 0x20FF
    ctx->r2 = S32(0X20FF << 16);
L_808007BC:
    // 0x808007BC: lui         $v0, 0xFF20
    ctx->r2 = S32(0XFF20 << 16);
    // 0x808007C0: b           L_80800800
    // 0x808007C4: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
        goto L_80800800;
    // 0x808007C4: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
L_808007C8:
    // 0x808007C8: lui         $v0, 0x96
    ctx->r2 = S32(0X96 << 16);
    // 0x808007CC: b           L_80800800
    // 0x808007D0: ori         $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 | 0XFF00;
        goto L_80800800;
    // 0x808007D0: ori         $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 | 0XFF00;
L_808007D4:
    // 0x808007D4: lui         $v0, 0x20FF
    ctx->r2 = S32(0X20FF << 16);
    // 0x808007D8: b           L_80800800
    // 0x808007DC: ori         $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 | 0XFF00;
        goto L_80800800;
    // 0x808007DC: ori         $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 | 0XFF00;
L_808007E0:
    // 0x808007E0: lui         $v0, 0xFF80
    ctx->r2 = S32(0XFF80 << 16);
    // 0x808007E4: b           L_80800800
    // 0x808007E8: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
        goto L_80800800;
    // 0x808007E8: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
L_808007EC:
    // 0x808007EC: lui         $v0, 0xFF60
    ctx->r2 = S32(0XFF60 << 16);
    // 0x808007F0: b           L_80800800
    // 0x808007F4: ori         $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 | 0XFF00;
        goto L_80800800;
    // 0x808007F4: ori         $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 | 0XFF00;
L_808007F8:
    // 0x808007F8: b           L_80800800
    // 0x808007FC: addiu       $v0, $zero, -0x100
    ctx->r2 = ADD32(0, -0X100);
        goto L_80800800;
    // 0x808007FC: addiu       $v0, $zero, -0x100
    ctx->r2 = ADD32(0, -0X100);
L_80800800:
    // 0x80800800: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80800804: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x80800808: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8080080C: and         $t0, $v0, $at
    ctx->r8 = ctx->r2 & ctx->r1;
    // 0x80800810: andi        $t2, $v0, 0xFF00
    ctx->r10 = ctx->r2 & 0XFF00;
    // 0x80800814: srl         $t3, $t2, 8
    ctx->r11 = S32(U32(ctx->r10) >> 8);
    // 0x80800818: srl         $t1, $t0, 16
    ctx->r9 = S32(U32(ctx->r8) >> 16);
    // 0x8080081C: srl         $t9, $t8, 24
    ctx->r25 = S32(U32(ctx->r24) >> 24);
    // 0x80800820: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80800824: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x80800828: jr          $ra
    // 0x8080082C: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    return;
    // 0x8080082C: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
;}
RECOMP_FUNC void _sujiggy_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A710: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A710);
    return;
    // 0x8008A714: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void basudie_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808003F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003F4: jal         0x80091E48
    // 0x808003F8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80091E48(rdram, ctx);
        goto after_0;
    // 0x808003F8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x808003FC: jal         0x80800020
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    basudie_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800404: jal         0x8008E944
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_2;
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800410: jal         0x800A4DFC
    // 0x80800414: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800A4DFC(rdram, ctx);
        goto after_3;
    // 0x80800414: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_3:
    // 0x80800418: jal         0x800A4C68
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_4;
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800420: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800424: jal         0x800C52F4
    // 0x80800428: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C52F4(rdram, ctx);
        goto after_5;
    // 0x80800428: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8080042C: jal         0x800A4CA8
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_6;
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800434: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800438: jal         0x80089288
    // 0x8080043C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _ncbadie_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x8080043C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x80800440: jal         0x800A0180
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0180(rdram, ctx);
        goto after_8;
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800448: lui         $a2, 0x4066
    ctx->r6 = S32(0X4066 << 16);
    // 0x8080044C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800454: jal         0x80085338
    // 0x80800458: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    _batimer_set(rdram, ctx);
        goto after_9;
    // 0x80800458: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_9:
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800460: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800464: jal         0x80084FC8
    // 0x80800468: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _bashake_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x80800468: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_10:
    // 0x8080046C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800470: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800474: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800478: jr          $ra
    // 0x8080047C: nop

    return;
    // 0x8080047C: nop

;}
RECOMP_FUNC void _idtwinkle_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E10: syscall     742
    recomp_syscall_handler(rdram, ctx, 0x80088E10);
    return;
    // 0x80088E14: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80802618_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802618: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8080261C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80802620: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80802624: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802628: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8080262C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80802630: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    // 0x80802634: jal         0x80100094
    // 0x80802638: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802638: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080263C: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80802640: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80802644: slti        $at, $a2, 0x91
    ctx->r1 = SIGNED(ctx->r6) < 0X91 ? 1 : 0;
    // 0x80802648: bne         $at, $zero, L_8080266C
    if (ctx->r1 != 0) {
        // 0x8080264C: addiu       $t6, $a2, -0xB
        ctx->r14 = ADD32(ctx->r6, -0XB);
            goto L_8080266C;
    }
    // 0x8080264C: addiu       $t6, $a2, -0xB
    ctx->r14 = ADD32(ctx->r6, -0XB);
    // 0x80802650: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x80802654: beq         $a2, $at, L_808026BC
    if (ctx->r6 == ctx->r1) {
        // 0x80802658: addiu       $at, $zero, 0x9F
        ctx->r1 = ADD32(0, 0X9F);
            goto L_808026BC;
    }
    // 0x80802658: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x8080265C: beq         $a2, $at, L_808026E8
    if (ctx->r6 == ctx->r1) {
        // 0x80802660: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_808026E8;
    }
    // 0x80802660: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80802664: b           L_80802FF0
    // 0x80802668: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802FF0;
    // 0x80802668: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080266C:
    // 0x8080266C: slti        $at, $a2, 0x58
    ctx->r1 = SIGNED(ctx->r6) < 0X58 ? 1 : 0;
    // 0x80802670: bne         $at, $zero, L_80802688
    if (ctx->r1 != 0) {
        // 0x80802674: addiu       $at, $zero, 0x90
        ctx->r1 = ADD32(0, 0X90);
            goto L_80802688;
    }
    // 0x80802674: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80802678: beq         $a2, $at, L_80802AFC
    if (ctx->r6 == ctx->r1) {
        // 0x8080267C: nop
    
            goto L_80802AFC;
    }
    // 0x8080267C: nop

    // 0x80802680: b           L_80802FF0
    // 0x80802684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802FF0;
    // 0x80802684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802688:
    // 0x80802688: sltiu       $at, $t6, 0x4D
    ctx->r1 = ctx->r14 < 0X4D ? 1 : 0;
    // 0x8080268C: beq         $at, $zero, L_80802FE4
    if (ctx->r1 == 0) {
        // 0x80802690: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80802FE4;
    }
    // 0x80802690: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80802694: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3E88) << 16);
    // 0x80802698: addu        $at, $at, $t6
    gpr jr_addend_808026A0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080269C: lw          $t6, 0x3E88($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3E88));
    // 0x808026A0: jr          $t6
    // 0x808026A4: nop

    switch (jr_addend_808026A0 >> 2) {
        case 0: goto L_80802874; break;
        case 1: goto L_80802FE4; break;
        case 2: goto L_80802FE4; break;
        case 3: goto L_80802FE4; break;
        case 4: goto L_80802FE4; break;
        case 5: goto L_80802FE4; break;
        case 6: goto L_80802FE4; break;
        case 7: goto L_80802FE4; break;
        case 8: goto L_80802FE4; break;
        case 9: goto L_80802FE4; break;
        case 10: goto L_80802FE4; break;
        case 11: goto L_80802FE4; break;
        case 12: goto L_80802FE4; break;
        case 13: goto L_80802FE4; break;
        case 14: goto L_80802FE4; break;
        case 15: goto L_80802FE4; break;
        case 16: goto L_80802FE4; break;
        case 17: goto L_80802FE4; break;
        case 18: goto L_80802FE4; break;
        case 19: goto L_80802FE4; break;
        case 20: goto L_80802E74; break;
        case 21: goto L_80802FE4; break;
        case 22: goto L_80802FE4; break;
        case 23: goto L_80802FE4; break;
        case 24: goto L_80802FE4; break;
        case 25: goto L_80802FE4; break;
        case 26: goto L_80802FE4; break;
        case 27: goto L_80802FE4; break;
        case 28: goto L_80802FE4; break;
        case 29: goto L_80802FE4; break;
        case 30: goto L_80802FE4; break;
        case 31: goto L_80802FE4; break;
        case 32: goto L_80802FE4; break;
        case 33: goto L_80802FE4; break;
        case 34: goto L_80802FE4; break;
        case 35: goto L_808026F8; break;
        case 36: goto L_80802FE4; break;
        case 37: goto L_80802FE4; break;
        case 38: goto L_80802FE4; break;
        case 39: goto L_808026A8; break;
        case 40: goto L_80802FE4; break;
        case 41: goto L_80802FE4; break;
        case 42: goto L_80802FE4; break;
        case 43: goto L_80802FE4; break;
        case 44: goto L_80802FE4; break;
        case 45: goto L_80802FE4; break;
        case 46: goto L_80802FE4; break;
        case 47: goto L_80802FE4; break;
        case 48: goto L_80802FE4; break;
        case 49: goto L_80802FE4; break;
        case 50: goto L_80802A20; break;
        case 51: goto L_80802FE4; break;
        case 52: goto L_80802FE4; break;
        case 53: goto L_80802978; break;
        case 54: goto L_80802FE4; break;
        case 55: goto L_80802FE4; break;
        case 56: goto L_80802FE4; break;
        case 57: goto L_80802FE4; break;
        case 58: goto L_80802FE4; break;
        case 59: goto L_80802FE4; break;
        case 60: goto L_80802FE4; break;
        case 61: goto L_80802FE4; break;
        case 62: goto L_80802FE4; break;
        case 63: goto L_80802FE4; break;
        case 64: goto L_80802FE4; break;
        case 65: goto L_80802FE4; break;
        case 66: goto L_80802FE4; break;
        case 67: goto L_80802FE4; break;
        case 68: goto L_80802FE4; break;
        case 69: goto L_80802FE4; break;
        case 70: goto L_80802FE4; break;
        case 71: goto L_808028F4; break;
        case 72: goto L_80802FE4; break;
        case 73: goto L_80802FE4; break;
        case 74: goto L_80802FE4; break;
        case 75: goto L_80802FE4; break;
        case 76: goto L_80802934; break;
        default: switch_error(__func__, 0x808026A0, 0x80803E88);
    }
    // 0x808026A4: nop

L_808026A8:
    // 0x808026A8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808026AC: jal         0x808003DC
    // 0x808026B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808003DC_chevilmumbo(rdram, ctx);
        goto after_1;
    // 0x808026B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808026B4: b           L_80802FF0
    // 0x808026B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x808026B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808026BC:
    // 0x808026BC: jal         0x800D395C
    // 0x808026C0: nop

    func_800D395C(rdram, ctx);
        goto after_2;
    // 0x808026C0: nop

    after_2:
    // 0x808026C4: bne         $v0, $zero, L_808026D4
    if (ctx->r2 != 0) {
        // 0x808026C8: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_808026D4;
    }
    // 0x808026C8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808026CC: b           L_80802FF0
    // 0x808026D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802FF0;
    // 0x808026D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808026D4:
    // 0x808026D4: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x808026D8: jal         0x80800354
    // 0x808026DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800354_chevilmumbo(rdram, ctx);
        goto after_3;
    // 0x808026DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x808026E0: b           L_80802FF0
    // 0x808026E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x808026E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808026E8:
    // 0x808026E8: jal         0x808007C4
    // 0x808026EC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_4;
    // 0x808026EC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_4:
    // 0x808026F0: b           L_80802FF0
    // 0x808026F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x808026F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808026F8:
    // 0x808026F8: addiu       $v1, $sp, 0x60
    ctx->r3 = ADD32(ctx->r29, 0X60);
    // 0x808026FC: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80802700: slti        $at, $v0, 0xCEC
    ctx->r1 = SIGNED(ctx->r2) < 0XCEC ? 1 : 0;
    // 0x80802704: bne         $at, $zero, L_8080272C
    if (ctx->r1 != 0) {
        // 0x80802708: addiu       $t7, $v0, -0x11DF
        ctx->r15 = ADD32(ctx->r2, -0X11DF);
            goto L_8080272C;
    }
    // 0x80802708: addiu       $t7, $v0, -0x11DF
    ctx->r15 = ADD32(ctx->r2, -0X11DF);
    // 0x8080270C: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x80802710: beq         $at, $zero, L_80802860
    if (ctx->r1 == 0) {
        // 0x80802714: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80802860;
    }
    // 0x80802714: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80802718: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3FBC) << 16);
    // 0x8080271C: addu        $at, $at, $t7
    gpr jr_addend_80802724 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80802720: lw          $t7, 0x3FBC($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3FBC));
    // 0x80802724: jr          $t7
    // 0x80802728: nop

    switch (jr_addend_80802724 >> 2) {
        case 0: goto L_80802740; break;
        case 1: goto L_80802788; break;
        case 2: goto L_808027B4; break;
        case 3: goto L_80802754; break;
        case 4: goto L_808027F8; break;
        case 5: goto L_80802860; break;
        case 6: goto L_8080281C; break;
        default: switch_error(__func__, 0x80802724, 0x80803FBC);
    }
    // 0x80802728: nop

L_8080272C:
    // 0x8080272C: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x80802730: beql        $v0, $at, L_8080283C
    if (ctx->r2 == ctx->r1) {
        // 0x80802734: lh          $t4, 0x2($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X2);
            goto L_8080283C;
    }
    goto skip_0;
    // 0x80802734: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    skip_0:
    // 0x80802738: b           L_80802864
    // 0x8080273C: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
        goto L_80802864;
    // 0x8080273C: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
L_80802740:
    // 0x80802740: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80802744: jal         0x808007C4
    // 0x80802748: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_5;
    // 0x80802748: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x8080274C: b           L_80802864
    // 0x80802750: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
        goto L_80802864;
    // 0x80802750: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
L_80802754:
    // 0x80802754: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80802758: sb          $t8, 0x92($a3)
    MEM_B(0X92, ctx->r7) = ctx->r24;
    // 0x8080275C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80802760: jal         0x80800ECC
    // 0x80802764: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800ECC_chevilmumbo(rdram, ctx);
        goto after_6;
    // 0x80802764: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80802768: jal         0x80090708
    // 0x8080276C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_7;
    // 0x8080276C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x80802770: jal         0x800FDC28
    // 0x80802774: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800FDC28(rdram, ctx);
        goto after_8;
    // 0x80802774: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_8:
    // 0x80802778: jal         0x808000BC
    // 0x8080277C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_808000BC_chevilmumbo(rdram, ctx);
        goto after_9;
    // 0x8080277C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_9:
    // 0x80802780: b           L_80802864
    // 0x80802784: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
        goto L_80802864;
    // 0x80802784: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
L_80802788:
    // 0x80802788: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8080278C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80802790: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80802794: lbu         $t1, 0x65($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X65);
    // 0x80802798: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x8080279C: sb          $t2, 0x65($t9)
    MEM_B(0X65, ctx->r25) = ctx->r10;
    // 0x808027A0: sb          $t3, 0x92($a3)
    MEM_B(0X92, ctx->r7) = ctx->r11;
    // 0x808027A4: jal         0x808003DC
    // 0x808027A8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_808003DC_chevilmumbo(rdram, ctx);
        goto after_10;
    // 0x808027A8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_10:
    // 0x808027AC: b           L_80802864
    // 0x808027B0: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
        goto L_80802864;
    // 0x808027B0: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
L_808027B4:
    // 0x808027B4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808027B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808027BC: jal         0x80800144
    // 0x808027C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800144_chevilmumbo(rdram, ctx);
        goto after_11;
    // 0x808027C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x808027C4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808027C8: jal         0x808003DC
    // 0x808027CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808003DC_chevilmumbo(rdram, ctx);
        goto after_12;
    // 0x808027CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x808027D0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808027D4: jal         0x808007C4
    // 0x808027D8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_13;
    // 0x808027D8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_13:
    // 0x808027DC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808027E0: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x808027E4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x808027E8: jal         0x808001F4
    // 0x808027EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808001F4_chevilmumbo(rdram, ctx);
        goto after_14;
    // 0x808027EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x808027F0: b           L_80802864
    // 0x808027F4: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
        goto L_80802864;
    // 0x808027F4: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
L_808027F8:
    // 0x808027F8: jal         0x800A51C0
    // 0x808027FC: nop

    func_800A51C0(rdram, ctx);
        goto after_15;
    // 0x808027FC: nop

    after_15:
    // 0x80802800: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80802804: jal         0x808003DC
    // 0x80802808: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808003DC_chevilmumbo(rdram, ctx);
        goto after_16;
    // 0x80802808: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x8080280C: jal         0x808000BC
    // 0x80802810: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_808000BC_chevilmumbo(rdram, ctx);
        goto after_17;
    // 0x80802810: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_17:
    // 0x80802814: b           L_80802864
    // 0x80802818: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
        goto L_80802864;
    // 0x80802818: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
L_8080281C:
    // 0x8080281C: jal         0x808000BC
    // 0x80802820: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_808000BC_chevilmumbo(rdram, ctx);
        goto after_18;
    // 0x80802820: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_18:
    // 0x80802824: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80802828: jal         0x808007C4
    // 0x8080282C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_19;
    // 0x8080282C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_19:
    // 0x80802830: b           L_80802864
    // 0x80802834: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
        goto L_80802864;
    // 0x80802834: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80802838: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
L_8080283C:
    // 0x8080283C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802840: bne         $t4, $at, L_80802858
    if (ctx->r12 != ctx->r1) {
        // 0x80802844: nop
    
            goto L_80802858;
    }
    // 0x80802844: nop

    // 0x80802848: jal         0x80088188
    // 0x8080284C: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_20;
    // 0x8080284C: nop

    after_20:
    // 0x80802850: b           L_80802864
    // 0x80802854: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
        goto L_80802864;
    // 0x80802854: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
L_80802858:
    // 0x80802858: jal         0x80088180
    // 0x8080285C: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_21;
    // 0x8080285C: nop

    after_21:
L_80802860:
    // 0x80802860: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
L_80802864:
    // 0x80802864: lbu         $t6, 0x74($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X74);
    // 0x80802868: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x8080286C: b           L_80802FEC
    // 0x80802870: sb          $t7, 0x74($t5)
    MEM_B(0X74, ctx->r13) = ctx->r15;
        goto L_80802FEC;
    // 0x80802870: sb          $t7, 0x74($t5)
    MEM_B(0X74, ctx->r13) = ctx->r15;
L_80802874:
    // 0x80802874: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80802878: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x8080287C: sltiu       $at, $t0, 0xF
    ctx->r1 = ctx->r8 < 0XF ? 1 : 0;
    // 0x80802880: beq         $at, $zero, L_808028EC
    if (ctx->r1 == 0) {
        // 0x80802884: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_808028EC;
    }
    // 0x80802884: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80802888: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3FD8) << 16);
    // 0x8080288C: addu        $at, $at, $t0
    gpr jr_addend_80802894 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80802890: lw          $t0, 0x3FD8($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3FD8));
    // 0x80802894: jr          $t0
    // 0x80802898: nop

    switch (jr_addend_80802894 >> 2) {
        case 0: goto L_8080289C; break;
        case 1: goto L_808028EC; break;
        case 2: goto L_808028B4; break;
        case 3: goto L_808028EC; break;
        case 4: goto L_808028EC; break;
        case 5: goto L_808028EC; break;
        case 6: goto L_808028EC; break;
        case 7: goto L_808028EC; break;
        case 8: goto L_808028D8; break;
        case 9: goto L_808028EC; break;
        case 10: goto L_808028EC; break;
        case 11: goto L_808028EC; break;
        case 12: goto L_808028EC; break;
        case 13: goto L_808028EC; break;
        case 14: goto L_808028C4; break;
        default: switch_error(__func__, 0x80802894, 0x80803FD8);
    }
    // 0x80802898: nop

L_8080289C:
    // 0x8080289C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808028A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808028A4: jal         0x80800144
    // 0x808028A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800144_chevilmumbo(rdram, ctx);
        goto after_22;
    // 0x808028A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_22:
    // 0x808028AC: b           L_80802FF0
    // 0x808028B0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80802FF0;
    // 0x808028B0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808028B4:
    // 0x808028B4: jal         0x80800290
    // 0x808028B8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_80800290_chevilmumbo(rdram, ctx);
        goto after_23;
    // 0x808028B8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_23:
    // 0x808028BC: b           L_80802FF0
    // 0x808028C0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80802FF0;
    // 0x808028C0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808028C4:
    // 0x808028C4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808028C8: jal         0x808003DC
    // 0x808028CC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808003DC_chevilmumbo(rdram, ctx);
        goto after_24;
    // 0x808028CC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_24:
    // 0x808028D0: b           L_80802FF0
    // 0x808028D4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80802FF0;
    // 0x808028D4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808028D8:
    // 0x808028D8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808028DC: jal         0x808003DC
    // 0x808028E0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808003DC_chevilmumbo(rdram, ctx);
        goto after_25;
    // 0x808028E0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_25:
    // 0x808028E4: b           L_80802FF0
    // 0x808028E8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80802FF0;
    // 0x808028E8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808028EC:
    // 0x808028EC: b           L_80802FF0
    // 0x808028F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80802FF0;
    // 0x808028F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808028F4:
    // 0x808028F4: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x808028F8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1676, 0X43E4) << 16);
    // 0x808028FC: addiu       $a0, $a0, 0x43E4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1676, 0X43E4));
    // 0x80802900: jal         0x80088090
    // 0x80802904: lw          $a1, 0x38($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_26;
    // 0x80802904: lw          $a1, 0x38($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X38);
    after_26:
    // 0x80802908: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8080290C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1676, 0X43F4) << 16);
    // 0x80802910: lhu         $t9, 0x72($t2)
    ctx->r25 = MEM_HU(ctx->r10, 0X72);
    // 0x80802914: srl         $t3, $t9, 10
    ctx->r11 = S32(U32(ctx->r25) >> 10);
    // 0x80802918: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x8080291C: beql        $at, $zero, L_80802FF0
    if (ctx->r1 == 0) {
        // 0x80802920: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80802FF0;
    }
    goto skip_1;
    // 0x80802920: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80802924: jal         0x80088098
    // 0x80802928: addiu       $a0, $a0, 0x43F4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1676, 0X43F4));
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_27;
    // 0x80802928: addiu       $a0, $a0, 0x43F4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1676, 0X43F4));
    after_27:
    // 0x8080292C: b           L_80802FF0
    // 0x80802930: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x80802930: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802934:
    // 0x80802934: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x80802938: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x8080293C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80802940: and         $t6, $a2, $at
    ctx->r14 = ctx->r6 & ctx->r1;
    // 0x80802944: srl         $a1, $t6, 16
    ctx->r5 = S32(U32(ctx->r14) >> 16);
    // 0x80802948: andi        $a0, $a3, 0xFFFF
    ctx->r4 = ctx->r7 & 0XFFFF;
    // 0x8080294C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80802950: jal         0x80088078
    // 0x80802954: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_28;
    // 0x80802954: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_28:
    // 0x80802958: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8080295C: beq         $v0, $zero, L_80802FEC
    if (ctx->r2 == 0) {
        // 0x80802960: lw          $a3, 0x50($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X50);
            goto L_80802FEC;
    }
    // 0x80802960: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80802964: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80802968: jal         0x80800144
    // 0x8080296C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80800144_chevilmumbo(rdram, ctx);
        goto after_29;
    // 0x8080296C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_29:
    // 0x80802970: b           L_80802FF0
    // 0x80802974: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x80802974: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802978:
    // 0x80802978: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x8080297C: lhu         $t8, 0x72($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X72);
    // 0x80802980: srl         $t0, $t8, 10
    ctx->r8 = S32(U32(ctx->r24) >> 10);
    // 0x80802984: addiu       $t1, $t0, -0x7
    ctx->r9 = ADD32(ctx->r8, -0X7);
    // 0x80802988: sltiu       $at, $t1, 0xD
    ctx->r1 = ctx->r9 < 0XD ? 1 : 0;
    // 0x8080298C: beq         $at, $zero, L_80802FEC
    if (ctx->r1 == 0) {
        // 0x80802990: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80802FEC;
    }
    // 0x80802990: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80802994: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X4014) << 16);
    // 0x80802998: addu        $at, $at, $t1
    gpr jr_addend_808029A0 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8080299C: lw          $t1, 0x4014($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1676, 0X4014));
    // 0x808029A0: jr          $t1
    // 0x808029A4: nop

    switch (jr_addend_808029A0 >> 2) {
        case 0: goto L_808029A8; break;
        case 1: goto L_808029A8; break;
        case 2: goto L_808029A8; break;
        case 3: goto L_808029B8; break;
        case 4: goto L_80802FEC; break;
        case 5: goto L_808029EC; break;
        case 6: goto L_80802FEC; break;
        case 7: goto L_80802FEC; break;
        case 8: goto L_80802FEC; break;
        case 9: goto L_80802FEC; break;
        case 10: goto L_80802FEC; break;
        case 11: goto L_80802FEC; break;
        case 12: goto L_808029A8; break;
        default: switch_error(__func__, 0x808029A0, 0x80804014);
    }
    // 0x808029A4: nop

L_808029A8:
    // 0x808029A8: jal         0x80800C50
    // 0x808029AC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_80800C50_chevilmumbo(rdram, ctx);
        goto after_30;
    // 0x808029AC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_30:
    // 0x808029B0: b           L_80802FF0
    // 0x808029B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x808029B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808029B8:
    // 0x808029B8: jal         0x80101F24
    // 0x808029BC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_80101F24(rdram, ctx);
        goto after_31;
    // 0x808029BC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_31:
    // 0x808029C0: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808029C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808029C8: nop

    // 0x808029CC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808029D0: nop

    // 0x808029D4: bc1fl       L_80802FF0
    if (!c1cs) {
        // 0x808029D8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80802FF0;
    }
    goto skip_2;
    // 0x808029D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x808029DC: jal         0x80800C50
    // 0x808029E0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_80800C50_chevilmumbo(rdram, ctx);
        goto after_32;
    // 0x808029E0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_32:
    // 0x808029E4: b           L_80802FF0
    // 0x808029E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x808029E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808029EC:
    // 0x808029EC: jal         0x80101F24
    // 0x808029F0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_80101F24(rdram, ctx);
        goto after_33;
    // 0x808029F0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_33:
    // 0x808029F4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808029F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808029FC: nop

    // 0x80802A00: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80802A04: nop

    // 0x80802A08: bc1fl       L_80802FF0
    if (!c1cs) {
        // 0x80802A0C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80802FF0;
    }
    goto skip_3;
    // 0x80802A0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x80802A10: jal         0x80800C50
    // 0x80802A14: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_80800C50_chevilmumbo(rdram, ctx);
        goto after_34;
    // 0x80802A14: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_34:
    // 0x80802A18: b           L_80802FF0
    // 0x80802A1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x80802A1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802A20:
    // 0x80802A20: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x80802A24: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X4400) << 16);
    // 0x80802A28: addiu       $a1, $a1, 0x4400
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4400));
    // 0x80802A2C: beq         $v0, $zero, L_80802AE0
    if (ctx->r2 == 0) {
        // 0x80802A30: addiu       $a0, $zero, 0x37E
        ctx->r4 = ADD32(0, 0X37E);
            goto L_80802AE0;
    }
    // 0x80802A30: addiu       $a0, $zero, 0x37E
    ctx->r4 = ADD32(0, 0X37E);
    // 0x80802A34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802A38: beq         $v0, $at, L_80802A78
    if (ctx->r2 == ctx->r1) {
        // 0x80802A3C: lw          $t5, 0x58($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X58);
            goto L_80802A78;
    }
    // 0x80802A3C: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80802A40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802A44: bne         $v0, $at, L_80802FEC
    if (ctx->r2 != ctx->r1) {
        // 0x80802A48: lw          $t2, 0x58($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X58);
            goto L_80802FEC;
    }
    // 0x80802A48: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80802A4C: lw          $t9, 0x7C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X7C);
    // 0x80802A50: addiu       $a0, $zero, 0x380
    ctx->r4 = ADD32(0, 0X380);
    // 0x80802A54: sll         $t4, $t9, 19
    ctx->r12 = S32(ctx->r25 << 19);
    // 0x80802A58: bgezl       $t4, L_80802FF0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80802A5C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80802FF0;
    }
    goto skip_4;
    // 0x80802A5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x80802A60: jal         0x801084B0
    // 0x80802A64: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_801084B0(rdram, ctx);
        goto after_35;
    // 0x80802A64: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_35:
    // 0x80802A68: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80802A6C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80802A70: b           L_80802FEC
    // 0x80802A74: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
        goto L_80802FEC;
    // 0x80802A74: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
L_80802A78:
    // 0x80802A78: lw          $t8, 0x7C($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X7C);
    // 0x80802A7C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80802A80: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80802A84: sll         $t1, $t8, 19
    ctx->r9 = S32(ctx->r24 << 19);
    // 0x80802A88: bgez        $t1, L_80802AA0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80802A8C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80802AA0;
    }
    // 0x80802A8C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80802A90: jal         0x800EE7F8
    // 0x80802A94: addiu       $a1, $a3, 0x78
    ctx->r5 = ADD32(ctx->r7, 0X78);
    func_800EE7F8(rdram, ctx);
        goto after_36;
    // 0x80802A94: addiu       $a1, $a3, 0x78
    ctx->r5 = ADD32(ctx->r7, 0X78);
    after_36:
    // 0x80802A98: b           L_80802AC0
    // 0x80802A9C: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
        goto L_80802AC0;
    // 0x80802A9C: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
L_80802AA0:
    // 0x80802AA0: jal         0x800EE7F8
    // 0x80802AA4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_37;
    // 0x80802AA4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_37:
    // 0x80802AA8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80802AAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802AB0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80802AB4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80802AB8: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x80802ABC: addiu       $a0, $zero, 0x37D
    ctx->r4 = ADD32(0, 0X37D);
L_80802AC0:
    // 0x80802AC0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80802AC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802AC8: jal         0x80108528
    // 0x80802ACC: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    func_80108528(rdram, ctx);
        goto after_38;
    // 0x80802ACC: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_38:
    // 0x80802AD0: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80802AD4: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80802AD8: b           L_80802FEC
    // 0x80802ADC: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
        goto L_80802FEC;
    // 0x80802ADC: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
L_80802AE0:
    // 0x80802AE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802AE4: jal         0x80108528
    // 0x80802AE8: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    func_80108528(rdram, ctx);
        goto after_39;
    // 0x80802AE8: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_39:
    // 0x80802AEC: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80802AF0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80802AF4: b           L_80802FEC
    // 0x80802AF8: sw          $t4, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r12;
        goto L_80802FEC;
    // 0x80802AF8: sw          $t4, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r12;
L_80802AFC:
    // 0x80802AFC: jal         0x80101080
    // 0x80802B00: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_80101080(rdram, ctx);
        goto after_40;
    // 0x80802B00: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_40:
    // 0x80802B04: jal         0x80106790
    // 0x80802B08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_41;
    // 0x80802B08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_41:
    // 0x80802B0C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80802B10: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80802B14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802B18: lbu         $t5, 0x65($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X65);
    // 0x80802B1C: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x80802B20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802B24: ori         $t8, $t5, 0x1
    ctx->r24 = ctx->r13 | 0X1;
    // 0x80802B28: jal         0x800866A0
    // 0x80802B2C: sb          $t8, 0x65($t6)
    MEM_B(0X65, ctx->r14) = ctx->r24;
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_42;
    // 0x80802B2C: sb          $t8, 0x65($t6)
    MEM_B(0X65, ctx->r14) = ctx->r24;
    after_42:
    // 0x80802B30: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80802B34: lbu         $t1, 0x94($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X94);
    // 0x80802B38: sltiu       $at, $t1, 0x9
    ctx->r1 = ctx->r9 < 0X9 ? 1 : 0;
    // 0x80802B3C: beq         $at, $zero, L_80802FEC
    if (ctx->r1 == 0) {
        // 0x80802B40: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80802FEC;
    }
    // 0x80802B40: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80802B44: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X4048) << 16);
    // 0x80802B48: addu        $at, $at, $t1
    gpr jr_addend_80802B50 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80802B4C: lw          $t1, 0x4048($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1676, 0X4048));
    // 0x80802B50: jr          $t1
    // 0x80802B54: nop

    switch (jr_addend_80802B50 >> 2) {
        case 0: goto L_80802B58; break;
        case 1: goto L_80802B90; break;
        case 2: goto L_80802BC8; break;
        case 3: goto L_80802C00; break;
        case 4: goto L_80802C38; break;
        case 5: goto L_80802C70; break;
        case 6: goto L_80802CA8; break;
        case 7: goto L_80802CE4; break;
        case 8: goto L_80802D74; break;
        default: switch_error(__func__, 0x80802B50, 0x80804048);
    }
    // 0x80802B54: nop

L_80802B58:
    // 0x80802B58: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X440C) << 16);
    // 0x80802B5C: addiu       $a1, $a1, 0x440C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X440C));
    // 0x80802B60: jal         0x800866A8
    // 0x80802B64: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _chexploder_entrypoint_10(rdram, ctx);
        goto after_43;
    // 0x80802B64: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_43:
    // 0x80802B68: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802B6C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80802B70: jal         0x800866A0
    // 0x80802B74: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_44;
    // 0x80802B74: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_44:
    // 0x80802B78: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802B7C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80802B80: jal         0x800866D0
    // 0x80802B84: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_45;
    // 0x80802B84: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_45:
    // 0x80802B88: b           L_80802FF0
    // 0x80802B8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x80802B8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802B90:
    // 0x80802B90: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X4414) << 16);
    // 0x80802B94: addiu       $a1, $a1, 0x4414
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4414));
    // 0x80802B98: jal         0x800866A8
    // 0x80802B9C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _chexploder_entrypoint_10(rdram, ctx);
        goto after_46;
    // 0x80802B9C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_46:
    // 0x80802BA0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802BA4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80802BA8: jal         0x800866A0
    // 0x80802BAC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_47;
    // 0x80802BAC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_47:
    // 0x80802BB0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802BB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80802BB8: jal         0x800866D0
    // 0x80802BBC: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_48;
    // 0x80802BBC: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_48:
    // 0x80802BC0: b           L_80802FF0
    // 0x80802BC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x80802BC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802BC8:
    // 0x80802BC8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X441C) << 16);
    // 0x80802BCC: addiu       $a1, $a1, 0x441C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X441C));
    // 0x80802BD0: jal         0x800866A8
    // 0x80802BD4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _chexploder_entrypoint_10(rdram, ctx);
        goto after_49;
    // 0x80802BD4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_49:
    // 0x80802BD8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802BDC: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80802BE0: jal         0x800866A0
    // 0x80802BE4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_50;
    // 0x80802BE4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_50:
    // 0x80802BE8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802BEC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80802BF0: jal         0x800866D0
    // 0x80802BF4: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_51;
    // 0x80802BF4: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_51:
    // 0x80802BF8: b           L_80802FF0
    // 0x80802BFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x80802BFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802C00:
    // 0x80802C00: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X4428) << 16);
    // 0x80802C04: addiu       $a1, $a1, 0x4428
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4428));
    // 0x80802C08: jal         0x800866A8
    // 0x80802C0C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _chexploder_entrypoint_10(rdram, ctx);
        goto after_52;
    // 0x80802C0C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_52:
    // 0x80802C10: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802C14: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80802C18: jal         0x800866A0
    // 0x80802C1C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_53;
    // 0x80802C1C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_53:
    // 0x80802C20: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802C24: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80802C28: jal         0x800866D0
    // 0x80802C2C: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_54;
    // 0x80802C2C: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_54:
    // 0x80802C30: b           L_80802FF0
    // 0x80802C34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x80802C34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802C38:
    // 0x80802C38: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X4430) << 16);
    // 0x80802C3C: addiu       $a1, $a1, 0x4430
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4430));
    // 0x80802C40: jal         0x800866A8
    // 0x80802C44: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _chexploder_entrypoint_10(rdram, ctx);
        goto after_55;
    // 0x80802C44: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_55:
    // 0x80802C48: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802C4C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80802C50: jal         0x800866A0
    // 0x80802C54: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_56;
    // 0x80802C54: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_56:
    // 0x80802C58: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802C5C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80802C60: jal         0x800866D0
    // 0x80802C64: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_57;
    // 0x80802C64: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_57:
    // 0x80802C68: b           L_80802FF0
    // 0x80802C6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x80802C6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802C70:
    // 0x80802C70: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X4434) << 16);
    // 0x80802C74: addiu       $a1, $a1, 0x4434
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4434));
    // 0x80802C78: jal         0x800866A8
    // 0x80802C7C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _chexploder_entrypoint_10(rdram, ctx);
        goto after_58;
    // 0x80802C7C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_58:
    // 0x80802C80: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802C84: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80802C88: jal         0x800866A0
    // 0x80802C8C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_59;
    // 0x80802C8C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_59:
    // 0x80802C90: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802C94: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80802C98: jal         0x800866D0
    // 0x80802C9C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_60;
    // 0x80802C9C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_60:
    // 0x80802CA0: b           L_80802FF0
    // 0x80802CA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x80802CA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802CA8:
    // 0x80802CA8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X4438) << 16);
    // 0x80802CAC: addiu       $a1, $a1, 0x4438
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4438));
    // 0x80802CB0: jal         0x800866A8
    // 0x80802CB4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _chexploder_entrypoint_10(rdram, ctx);
        goto after_61;
    // 0x80802CB4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_61:
    // 0x80802CB8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802CBC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80802CC0: jal         0x800866A0
    // 0x80802CC4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_62;
    // 0x80802CC4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_62:
    // 0x80802CC8: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80802CCC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80802CD0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802CD4: jal         0x800866D0
    // 0x80802CD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_63;
    // 0x80802CD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_63:
    // 0x80802CDC: b           L_80802FF0
    // 0x80802CE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x80802CE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802CE4:
    // 0x80802CE4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802CE8: jal         0x800866D8
    // 0x80802CEC: addiu       $a1, $zero, 0x697
    ctx->r5 = ADD32(0, 0X697);
    _chexploder_entrypoint_16(rdram, ctx);
        goto after_64;
    // 0x80802CEC: addiu       $a1, $zero, 0x697
    ctx->r5 = ADD32(0, 0X697);
    after_64:
    // 0x80802CF0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X443C) << 16);
    // 0x80802CF4: addiu       $a1, $a1, 0x443C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X443C));
    // 0x80802CF8: jal         0x800866A8
    // 0x80802CFC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _chexploder_entrypoint_10(rdram, ctx);
        goto after_65;
    // 0x80802CFC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_65:
    // 0x80802D00: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80802D04: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80802D08: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802D0C: jal         0x800866D0
    // 0x80802D10: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_66;
    // 0x80802D10: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_66:
    // 0x80802D14: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802D18: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    // 0x80802D1C: jal         0x80086688
    // 0x80802D20: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_67;
    // 0x80802D20: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    after_67:
    // 0x80802D24: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802D28: jal         0x800866C0
    // 0x80802D2C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    _chexploder_entrypoint_13(rdram, ctx);
        goto after_68;
    // 0x80802D2C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_68:
    // 0x80802D30: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802D34: jal         0x800866C8
    // 0x80802D38: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _chexploder_entrypoint_14(rdram, ctx);
        goto after_69;
    // 0x80802D38: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_69:
    // 0x80802D3C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802D40: jal         0x800866B8
    // 0x80802D44: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    _chexploder_entrypoint_12(rdram, ctx);
        goto after_70;
    // 0x80802D44: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_70:
    // 0x80802D48: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80802D4C: lui         $a0, 0x7FF1
    ctx->r4 = S32(0X7FF1 << 16);
    // 0x80802D50: lui         $a2, 0x1388
    ctx->r6 = S32(0X1388 << 16);
    // 0x80802D54: ori         $a2, $a2, 0x1F4
    ctx->r6 = ctx->r6 | 0X1F4;
    // 0x80802D58: ori         $a0, $a0, 0x9413
    ctx->r4 = ctx->r4 | 0X9413;
    // 0x80802D5C: jal         0x800C4140
    // 0x80802D60: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800C4140(rdram, ctx);
        goto after_71;
    // 0x80802D60: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_71:
    // 0x80802D64: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80802D68: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80802D6C: b           L_80802FEC
    // 0x80802D70: sb          $t2, 0x94($t9)
    MEM_B(0X94, ctx->r25) = ctx->r10;
        goto L_80802FEC;
    // 0x80802D70: sb          $t2, 0x94($t9)
    MEM_B(0X94, ctx->r25) = ctx->r10;
L_80802D74:
    // 0x80802D74: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80802D78: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x80802D7C: lui         $a2, 0x1388
    ctx->r6 = S32(0X1388 << 16);
    // 0x80802D80: ori         $a2, $a2, 0x1F4
    ctx->r6 = ctx->r6 | 0X1F4;
    // 0x80802D84: ori         $a0, $a0, 0x4413
    ctx->r4 = ctx->r4 | 0X4413;
    // 0x80802D88: jal         0x800C4140
    // 0x80802D8C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800C4140(rdram, ctx);
        goto after_72;
    // 0x80802D8C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_72:
    // 0x80802D90: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802D94: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80802D98: jal         0x800866A0
    // 0x80802D9C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_73;
    // 0x80802D9C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_73:
    // 0x80802DA0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802DA4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80802DA8: jal         0x800866A0
    // 0x80802DAC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_74;
    // 0x80802DAC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_74:
    // 0x80802DB0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802DB4: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80802DB8: jal         0x800866A0
    // 0x80802DBC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_75;
    // 0x80802DBC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_75:
    // 0x80802DC0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802DC4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80802DC8: jal         0x800866A0
    // 0x80802DCC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_76;
    // 0x80802DCC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_76:
    // 0x80802DD0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802DD4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80802DD8: jal         0x800866A0
    // 0x80802DDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_77;
    // 0x80802DDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_77:
    // 0x80802DE0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802DE4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80802DE8: jal         0x800866A0
    // 0x80802DEC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_78;
    // 0x80802DEC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_78:
    // 0x80802DF0: lui         $a2, 0x3EB3
    ctx->r6 = S32(0X3EB3 << 16);
    // 0x80802DF4: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80802DF8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802DFC: jal         0x800866D0
    // 0x80802E00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_79;
    // 0x80802E00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_79:
    // 0x80802E04: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X4440) << 16);
    // 0x80802E08: addiu       $a1, $a1, 0x4440
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4440));
    // 0x80802E0C: jal         0x800866A8
    // 0x80802E10: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _chexploder_entrypoint_10(rdram, ctx);
        goto after_80;
    // 0x80802E10: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_80:
    // 0x80802E14: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80802E18: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    // 0x80802E1C: jal         0x80086688
    // 0x80802E20: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_81;
    // 0x80802E20: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    after_81:
    // 0x80802E24: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X406C) << 16);
    // 0x80802E28: lwc1        $f12, 0x406C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X406C));
    // 0x80802E2C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80802E30: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80802E34: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80802E38: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X4070) << 16);
    // 0x80802E3C: lwc1        $f4, 0x4070($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X4070));
    // 0x80802E40: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x80802E44: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80802E48: addiu       $a1, $zero, 0x5F3
    ctx->r5 = ADD32(0, 0X5F3);
    // 0x80802E4C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80802E50: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    // 0x80802E54: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80802E58: jal         0x800C9C70
    // 0x80802E5C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    func_800C9C70(rdram, ctx);
        goto after_82;
    // 0x80802E5C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_82:
    // 0x80802E60: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80802E64: lbu         $t5, 0x65($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X65);
    // 0x80802E68: andi        $t8, $t5, 0xFFFE
    ctx->r24 = ctx->r13 & 0XFFFE;
    // 0x80802E6C: b           L_80802FEC
    // 0x80802E70: sb          $t8, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r24;
        goto L_80802FEC;
    // 0x80802E70: sb          $t8, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r24;
L_80802E74:
    // 0x80802E74: jal         0x800DF3E0
    // 0x80802E78: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_800DF3E0(rdram, ctx);
        goto after_83;
    // 0x80802E78: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_83:
    // 0x80802E7C: jal         0x801015D0
    // 0x80802E80: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_801015D0(rdram, ctx);
        goto after_84;
    // 0x80802E80: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_84:
    // 0x80802E84: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80802E88: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80802E8C: lw          $t0, 0x64($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X64);
    // 0x80802E90: sll         $t2, $t0, 11
    ctx->r10 = S32(ctx->r8 << 11);
    // 0x80802E94: bgezl       $t2, L_80802F6C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80802E98: lbu         $t5, 0x8F($t4)
        ctx->r13 = MEM_BU(ctx->r12, 0X8F);
            goto L_80802F6C;
    }
    goto skip_5;
    // 0x80802E98: lbu         $t5, 0x8F($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X8F);
    skip_5:
    // 0x80802E9C: lw          $a1, 0x78($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X78);
    // 0x80802EA0: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x80802EA4: sll         $t9, $a1, 20
    ctx->r25 = S32(ctx->r5 << 20);
    // 0x80802EA8: srl         $t3, $t9, 29
    ctx->r11 = S32(U32(ctx->r25) >> 29);
    // 0x80802EAC: jal         0x800DF744
    // 0x80802EB0: addiu       $a1, $t3, 0x1
    ctx->r5 = ADD32(ctx->r11, 0X1);
    func_800DF744(rdram, ctx);
        goto after_85;
    // 0x80802EB0: addiu       $a1, $t3, 0x1
    ctx->r5 = ADD32(ctx->r11, 0X1);
    after_85:
    // 0x80802EB4: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80802EB8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80802EBC: jal         0x800DF744
    // 0x80802EC0: lbu         $a1, 0x84($t4)
    ctx->r5 = MEM_BU(ctx->r12, 0X84);
    func_800DF744(rdram, ctx);
        goto after_86;
    // 0x80802EC0: lbu         $a1, 0x84($t4)
    ctx->r5 = MEM_BU(ctx->r12, 0X84);
    after_86:
    // 0x80802EC4: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80802EC8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80802ECC: jal         0x800DF744
    // 0x80802ED0: lbu         $a1, 0x85($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X85);
    func_800DF744(rdram, ctx);
        goto after_87;
    // 0x80802ED0: lbu         $a1, 0x85($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X85);
    after_87:
    // 0x80802ED4: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80802ED8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80802EDC: jal         0x800DF744
    // 0x80802EE0: lbu         $a1, 0x86($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X86);
    func_800DF744(rdram, ctx);
        goto after_88;
    // 0x80802EE0: lbu         $a1, 0x86($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X86);
    after_88:
    // 0x80802EE4: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80802EE8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80802EEC: jal         0x800DF744
    // 0x80802EF0: lbu         $a1, 0x87($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X87);
    func_800DF744(rdram, ctx);
        goto after_89;
    // 0x80802EF0: lbu         $a1, 0x87($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X87);
    after_89:
    // 0x80802EF4: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80802EF8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80802EFC: jal         0x800DF744
    // 0x80802F00: lbu         $a1, 0x88($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X88);
    func_800DF744(rdram, ctx);
        goto after_90;
    // 0x80802F00: lbu         $a1, 0x88($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X88);
    after_90:
    // 0x80802F04: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80802F08: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x80802F0C: jal         0x800DF744
    // 0x80802F10: lbu         $a1, 0x89($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X89);
    func_800DF744(rdram, ctx);
        goto after_91;
    // 0x80802F10: lbu         $a1, 0x89($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X89);
    after_91:
    // 0x80802F14: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80802F18: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80802F1C: jal         0x800DF744
    // 0x80802F20: lbu         $a1, 0x8A($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X8A);
    func_800DF744(rdram, ctx);
        goto after_92;
    // 0x80802F20: lbu         $a1, 0x8A($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X8A);
    after_92:
    // 0x80802F24: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80802F28: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80802F2C: jal         0x800DF744
    // 0x80802F30: lbu         $a1, 0x8B($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X8B);
    func_800DF744(rdram, ctx);
        goto after_93;
    // 0x80802F30: lbu         $a1, 0x8B($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X8B);
    after_93:
    // 0x80802F34: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80802F38: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80802F3C: jal         0x800DF744
    // 0x80802F40: lbu         $a1, 0x8C($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X8C);
    func_800DF744(rdram, ctx);
        goto after_94;
    // 0x80802F40: lbu         $a1, 0x8C($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X8C);
    after_94:
    // 0x80802F44: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80802F48: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x80802F4C: jal         0x800DF744
    // 0x80802F50: lbu         $a1, 0x8D($t3)
    ctx->r5 = MEM_BU(ctx->r11, 0X8D);
    func_800DF744(rdram, ctx);
        goto after_95;
    // 0x80802F50: lbu         $a1, 0x8D($t3)
    ctx->r5 = MEM_BU(ctx->r11, 0X8D);
    after_95:
    // 0x80802F54: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80802F58: jal         0x800DF744
    // 0x80802F5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_96;
    // 0x80802F5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_96:
    // 0x80802F60: b           L_80802FF0
    // 0x80802F64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x80802F64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802F68: lbu         $t5, 0x8F($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X8F);
L_80802F6C:
    // 0x80802F6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802F70: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80802F74: beq         $t5, $zero, L_80802F98
    if (ctx->r13 == 0) {
        // 0x80802F78: nop
    
            goto L_80802F98;
    }
    // 0x80802F78: nop

    // 0x80802F7C: jal         0x800DF744
    // 0x80802F80: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800DF744(rdram, ctx);
        goto after_97;
    // 0x80802F80: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_97:
    // 0x80802F84: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80802F88: jal         0x800DF744
    // 0x80802F8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_98;
    // 0x80802F8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_98:
    // 0x80802F90: b           L_80802FB0
    // 0x80802F94: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
        goto L_80802FB0;
    // 0x80802F94: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
L_80802F98:
    // 0x80802F98: jal         0x800DF744
    // 0x80802F9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_99;
    // 0x80802F9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_99:
    // 0x80802FA0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80802FA4: jal         0x800DF744
    // 0x80802FA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_100;
    // 0x80802FA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_100:
    // 0x80802FAC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
L_80802FB0:
    // 0x80802FB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802FB4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80802FB8: lbu         $t7, 0x8E($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X8E);
    // 0x80802FBC: beq         $t7, $zero, L_80802FD4
    if (ctx->r15 == 0) {
        // 0x80802FC0: nop
    
            goto L_80802FD4;
    }
    // 0x80802FC0: nop

    // 0x80802FC4: jal         0x800DF744
    // 0x80802FC8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800DF744(rdram, ctx);
        goto after_101;
    // 0x80802FC8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_101:
    // 0x80802FCC: b           L_80802FF0
    // 0x80802FD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x80802FD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802FD4:
    // 0x80802FD4: jal         0x800DF744
    // 0x80802FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_102;
    // 0x80802FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_102:
    // 0x80802FDC: b           L_80802FF0
    // 0x80802FE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802FF0;
    // 0x80802FE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802FE4:
    // 0x80802FE4: b           L_80802FF0
    // 0x80802FE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802FF0;
    // 0x80802FE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802FEC:
    // 0x80802FEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802FF0:
    // 0x80802FF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802FF4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80802FF8: jr          $ra
    // 0x80802FFC: nop

    return;
    // 0x80802FFC: nop

;}
RECOMP_FUNC void func_8080000C_chattract(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: jr          $ra
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _idscroll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088DB0: syscall     740
    recomp_syscall_handler(rdram, ctx, 0x80088DB0);
    return;
    // 0x80088DB4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800C04C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C04C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C04CC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C04D0: lbu         $t6, -0x75D0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X75D0);
    // 0x800C04D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C04D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C04DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C04E0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C04E4: beq         $t6, $zero, L_800C051C
    if (ctx->r14 == 0) {
        // 0x800C04E8: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_800C051C;
    }
    // 0x800C04E8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800C04EC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800C04F0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800C04F4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C04F8: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    // 0x800C04FC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800C0500: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800C0504: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800C0508: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C050C: jal         0x80087E40
    // 0x800C0510: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    _gcdialogexec_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x800C0510: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x800C0514: b           L_800C0520
    // 0x800C0518: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800C0520;
    // 0x800C0518: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800C051C:
    // 0x800C051C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C0520:
    // 0x800C0520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0524: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C0528: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C052C: jr          $ra
    // 0x800C0530: nop

    return;
    // 0x800C0530: nop

;}
RECOMP_FUNC void bsjump_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800E60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800E64: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800E68: lui         $a2, 0x3EB3
    ctx->r6 = S32(0X3EB3 << 16);
    // 0x80800E6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E70: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800E74: jal         0x8008CBB0
    // 0x80800E78: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    baanim_playForDuration_loop(rdram, ctx);
        goto after_0;
    // 0x80800E78: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    after_0:
    // 0x80800E7C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800E80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800E90: jal         0x8009FFD8
    // 0x80800E94: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800E94: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E9C: jal         0x80093360
    // 0x80800EA0: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    func_80093360(rdram, ctx);
        goto after_2;
    // 0x80800EA0: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    after_2:
    // 0x80800EA4: jal         0x8009557C
    // 0x80800EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009557C(rdram, ctx);
        goto after_3;
    // 0x80800EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800EAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800EB0: bne         $v0, $at, L_80800EF8
    if (ctx->r2 != ctx->r1) {
        // 0x80800EB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EF8;
    }
    // 0x80800EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800EC0: jal         0x80085338
    // 0x80800EC4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    _batimer_set(rdram, ctx);
        goto after_4;
    // 0x80800EC4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_4:
    // 0x80800EC8: lui         $a2, 0x3ED1
    ctx->r6 = S32(0X3ED1 << 16);
    // 0x80800ECC: ori         $a2, $a2, 0xEB85
    ctx->r6 = ctx->r6 | 0XEB85;
    // 0x80800ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ED4: jal         0x80085338
    // 0x80800ED8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_set(rdram, ctx);
        goto after_5;
    // 0x80800ED8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EE0: addiu       $a1, $zero, 0x439
    ctx->r5 = ADD32(0, 0X439);
    // 0x80800EE4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800EE8: jal         0x8009DF18
    // 0x80800EEC: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF18(rdram, ctx);
        goto after_6;
    // 0x80800EEC: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_6:
    // 0x80800EF0: b           L_80800F1C
    // 0x80800EF4: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
        goto L_80800F1C;
    // 0x80800EF4: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
L_80800EF8:
    // 0x80800EF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800EFC: jal         0x80085338
    // 0x80800F00: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _batimer_set(rdram, ctx);
        goto after_7;
    // 0x80800F00: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_7:
    // 0x80800F04: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80800F08: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80800F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F10: jal         0x80085338
    // 0x80800F14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_set(rdram, ctx);
        goto after_8;
    // 0x80800F14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800F18: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
L_80800F1C:
    // 0x80800F1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800F20: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800F24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F28: jr          $ra
    // 0x80800F2C: nop

    return;
    // 0x80800F2C: nop

;}
RECOMP_FUNC void func_80800000_chdinofamilymissing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x800EA05C
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: addiu       $at, $zero, 0x114
    ctx->r1 = ADD32(0, 0X114);
    // 0x80800014: beq         $v0, $at, L_8080002C
    if (ctx->r2 == ctx->r1) {
        // 0x80800018: addiu       $at, $zero, 0x118
        ctx->r1 = ADD32(0, 0X118);
            goto L_8080002C;
    }
    // 0x80800018: addiu       $at, $zero, 0x118
    ctx->r1 = ADD32(0, 0X118);
    // 0x8080001C: beq         $v0, $at, L_8080004C
    if (ctx->r2 == ctx->r1) {
        // 0x80800020: nop
    
            goto L_8080004C;
    }
    // 0x80800020: nop

    // 0x80800024: b           L_808000EC
    // 0x80800028: nop

        goto L_808000EC;
    // 0x80800028: nop

L_8080002C:
    // 0x8080002C: jal         0x80088840
    // 0x80800030: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80800030: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_1:
    // 0x80800034: bnel        $v0, $zero, L_808000F8
    if (ctx->r2 != 0) {
        // 0x80800038: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000F8;
    }
    goto skip_0;
    // 0x80800038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080003C: jal         0x800FFAB0
    // 0x80800040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800044: b           L_808000F8
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000F8;
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080004C:
    // 0x8080004C: jal         0x80088848
    // 0x80800050: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80800050: nop

    after_3:
    // 0x80800054: beq         $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x80800058: nop
    
            goto L_8080008C;
    }
    // 0x80800058: nop

    // 0x8080005C: jal         0x80105494
    // 0x80800060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80105494(rdram, ctx);
        goto after_4;
    // 0x80800060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80800064: beq         $v0, $zero, L_8080007C
    if (ctx->r2 == 0) {
        // 0x80800068: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080007C;
    }
    // 0x80800068: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080006C: jal         0x800FFAB0
    // 0x80800070: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800070: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x80800074: b           L_808000F8
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000F8;
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080007C:
    // 0x8080007C: jal         0x80102424
    // 0x80800080: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800080: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_6:
    // 0x80800084: b           L_808000F8
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000F8;
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080008C:
    // 0x8080008C: jal         0x80088840
    // 0x80800090: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_7;
    // 0x80800090: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_7:
    // 0x80800094: beq         $v0, $zero, L_808000AC
    if (ctx->r2 == 0) {
        // 0x80800098: nop
    
            goto L_808000AC;
    }
    // 0x80800098: nop

    // 0x8080009C: jal         0x80105494
    // 0x808000A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80105494(rdram, ctx);
        goto after_8;
    // 0x808000A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_8:
    // 0x808000A4: bnel        $v0, $zero, L_808000F8
    if (ctx->r2 != 0) {
        // 0x808000A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000F8;
    }
    goto skip_1;
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_808000AC:
    // 0x808000AC: jal         0x800DA298
    // 0x808000B0: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808000B0: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_9:
    // 0x808000B4: beq         $v0, $zero, L_808000DC
    if (ctx->r2 == 0) {
        // 0x808000B8: nop
    
            goto L_808000DC;
    }
    // 0x808000B8: nop

    // 0x808000BC: jal         0x80105494
    // 0x808000C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80105494(rdram, ctx);
        goto after_10;
    // 0x808000C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_10:
    // 0x808000C4: bne         $v0, $zero, L_808000DC
    if (ctx->r2 != 0) {
        // 0x808000C8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808000DC;
    }
    // 0x808000C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000CC: jal         0x80102424
    // 0x808000D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x808000D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_11:
    // 0x808000D4: b           L_808000F8
    // 0x808000D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000F8;
    // 0x808000D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000DC:
    // 0x808000DC: jal         0x800FFAB0
    // 0x808000E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_12;
    // 0x808000E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_12:
    // 0x808000E4: b           L_808000F8
    // 0x808000E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000F8;
    // 0x808000E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000EC:
    // 0x808000EC: jal         0x800FFAB0
    // 0x808000F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_13;
    // 0x808000F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_13:
    // 0x808000F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000F8:
    // 0x808000F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

;}
RECOMP_FUNC void func_808003A8_chnicecavemenguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003AC: addiu       $t6, $a1, -0x1B
    ctx->r14 = ADD32(ctx->r5, -0X1B);
    // 0x808003B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003B4: sltiu       $at, $t6, 0x14
    ctx->r1 = ctx->r14 < 0X14 ? 1 : 0;
    // 0x808003B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003C0: beq         $at, $zero, L_808004DC
    if (ctx->r1 == 0) {
        // 0x808003C4: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808004DC;
    }
    // 0x808003C4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808003C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808003CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1272, 0X858) << 16);
    // 0x808003D0: addu        $at, $at, $t6
    gpr jr_addend_808003D8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808003D4: lw          $t6, 0x858($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1272, 0X858));
    // 0x808003D8: jr          $t6
    // 0x808003DC: nop

    switch (jr_addend_808003D8 >> 2) {
        case 0: goto L_80800440; break;
        case 1: goto L_808004DC; break;
        case 2: goto L_808003F8; break;
        case 3: goto L_808003F8; break;
        case 4: goto L_808004CC; break;
        case 5: goto L_808004DC; break;
        case 6: goto L_808004DC; break;
        case 7: goto L_808004DC; break;
        case 8: goto L_808004DC; break;
        case 9: goto L_808004DC; break;
        case 10: goto L_808004DC; break;
        case 11: goto L_808004DC; break;
        case 12: goto L_808004DC; break;
        case 13: goto L_808004DC; break;
        case 14: goto L_808004AC; break;
        case 15: goto L_808004BC; break;
        case 16: goto L_808004DC; break;
        case 17: goto L_808004DC; break;
        case 18: goto L_808004DC; break;
        case 19: goto L_808003E0; break;
        default: switch_error(__func__, 0x808003D8, 0x80800858);
    }
    // 0x808003DC: nop

L_808003E0:
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E4: lh          $a1, 0x28($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X28);
    // 0x808003E8: jal         0x808005D4
    // 0x808003EC: lh          $a2, 0x2A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2A);
    func_808005D4_chnicecavemenguard(rdram, ctx);
        goto after_0;
    // 0x808003EC: lh          $a2, 0x2A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2A);
    after_0:
    // 0x808003F0: b           L_808004E8
    // 0x808003F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004E8;
    // 0x808003F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003F8:
    // 0x808003F8: jal         0x800F54E4
    // 0x808003FC: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808003FC: nop

    after_1:
    // 0x80800400: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800404: jal         0x800F52B8
    // 0x80800408: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800F52B8(rdram, ctx);
        goto after_2;
    // 0x80800408: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x8080040C: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80800410: bnel        $v0, $at, L_808004E8
    if (ctx->r2 != ctx->r1) {
        // 0x80800414: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808004E8;
    }
    goto skip_0;
    // 0x80800414: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800418: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x8080041C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800424: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800428: bnel        $t8, $at, L_808004E8
    if (ctx->r24 != ctx->r1) {
        // 0x8080042C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808004E8;
    }
    goto skip_1;
    // 0x8080042C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800430: jal         0x80102424
    // 0x80800434: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800434: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800438: b           L_808004E8
    // 0x8080043C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004E8;
    // 0x8080043C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800440:
    // 0x80800440: jal         0x800F54E4
    // 0x80800444: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80800444: nop

    after_4:
    // 0x80800448: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080044C: jal         0x800F52B8
    // 0x80800450: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800F52B8(rdram, ctx);
        goto after_5;
    // 0x80800450: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x80800454: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x80800458: bnel        $v0, $at, L_808004E8
    if (ctx->r2 != ctx->r1) {
        // 0x8080045C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808004E8;
    }
    goto skip_2;
    // 0x8080045C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x80800460: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x80800464: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800468: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080046C: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800470: bne         $t0, $at, L_808004E4
    if (ctx->r8 != ctx->r1) {
        // 0x80800474: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_808004E4;
    }
    // 0x80800474: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800478: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080047C: jal         0x80085708
    // 0x80800480: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    _capod_entrypoint_13(rdram, ctx);
        goto after_6;
    // 0x80800480: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_6:
    // 0x80800484: jal         0x800F54E4
    // 0x80800488: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800488: nop

    after_7:
    // 0x8080048C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800490: jal         0x800F7F98
    // 0x80800494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_8;
    // 0x80800494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080049C: jal         0x80102424
    // 0x808004A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x808004A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x808004A4: b           L_808004E8
    // 0x808004A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004E8;
    // 0x808004A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004AC:
    // 0x808004AC: jal         0x808007A8
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007A8_chnicecavemenguard(rdram, ctx);
        goto after_10;
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808004B4: b           L_808004E8
    // 0x808004B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004E8;
    // 0x808004B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004BC:
    // 0x808004BC: jal         0x8080080C
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080080C_chnicecavemenguard(rdram, ctx);
        goto after_11;
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808004C4: b           L_808004E8
    // 0x808004C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004E8;
    // 0x808004C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004CC:
    // 0x808004CC: jal         0x808004FC
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004FC_chnicecavemenguard(rdram, ctx);
        goto after_12;
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808004D4: b           L_808004E8
    // 0x808004D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004E8;
    // 0x808004D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004DC:
    // 0x808004DC: b           L_808004E8
    // 0x808004E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004E8;
    // 0x808004E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004E4:
    // 0x808004E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004E8:
    // 0x808004E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004F4: jr          $ra
    // 0x808004F8: nop

    return;
    // 0x808004F8: nop

;}
RECOMP_FUNC void func_80108474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108474: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80108478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010847C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80108480: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80108484: jal         0x800EE904
    // 0x80108488: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EE904(rdram, ctx);
        goto after_0;
    // 0x80108488: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8010848C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80108490: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80108494: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80108498: jal         0x80108C90
    // 0x8010849C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80108C90(rdram, ctx);
        goto after_1;
    // 0x8010849C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x801084A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801084A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801084A8: jr          $ra
    // 0x801084AC: nop

    return;
    // 0x801084AC: nop

;}
RECOMP_FUNC void _chpotogoldgame_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800875C8: syscall     592
    recomp_syscall_handler(rdram, ctx, 0x800875C8);
    return;
    // 0x800875CC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800080_chlinkpipefan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800084: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800088: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080008C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800090: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800094: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800098: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080009C: beq         $t6, $at, L_808000CC
    if (ctx->r14 == ctx->r1) {
        // 0x808000A0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000CC;
    }
    // 0x808000A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000A4: beq         $t6, $at, L_808000FC
    if (ctx->r14 == ctx->r1) {
        // 0x808000A8: addiu       $a0, $s0, 0x34
        ctx->r4 = ADD32(ctx->r16, 0X34);
            goto L_808000FC;
    }
    // 0x808000A8: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x808000AC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000B0: beq         $t6, $at, L_80800140
    if (ctx->r14 == ctx->r1) {
        // 0x808000B4: addiu       $a0, $s0, 0x34
        ctx->r4 = ADD32(ctx->r16, 0X34);
            goto L_80800140;
    }
    // 0x808000B4: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x808000B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808000BC: beq         $t6, $at, L_80800194
    if (ctx->r14 == ctx->r1) {
        // 0x808000C0: nop
    
            goto L_80800194;
    }
    // 0x808000C0: nop

    // 0x808000C4: b           L_808001F0
    // 0x808000C8: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
        goto L_808001F0;
    // 0x808000C8: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
L_808000CC:
    // 0x808000CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2248, 0X8F0) << 16);
    // 0x808000D0: lwc1        $f0, 0x8F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2248, 0X8F0));
    // 0x808000D4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808000D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000DC: lwc1        $f12, 0x4C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808000E0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808000E4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000E8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808000EC: jal         0x800F1FF0
    // 0x808000F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_0;
    // 0x808000F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x808000F4: b           L_808001EC
    // 0x808000F8: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
        goto L_808001EC;
    // 0x808000F8: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
L_808000FC:
    // 0x808000FC: jal         0x800D91EC
    // 0x80800100: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    func_800D91EC(rdram, ctx);
        goto after_1;
    // 0x80800100: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_1:
    // 0x80800104: beq         $v0, $zero, L_8080011C
    if (ctx->r2 == 0) {
        // 0x80800108: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_8080011C;
    }
    // 0x80800108: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8080010C: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x80800110: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800114: b           L_808001EC
    // 0x80800118: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
        goto L_808001EC;
    // 0x80800118: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
L_8080011C:
    // 0x8080011C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800120: lwc1        $f12, 0x34($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800124: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800128: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080012C: lui         $a3, 0x43E1
    ctx->r7 = S32(0X43E1 << 16);
    // 0x80800130: jal         0x800F10B4
    // 0x80800134: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800134: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80800138: b           L_808001EC
    // 0x8080013C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
        goto L_808001EC;
    // 0x8080013C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_80800140:
    // 0x80800140: jal         0x800D90F8
    // 0x80800144: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_800D90F8(rdram, ctx);
        goto after_3;
    // 0x80800144: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_3:
    // 0x80800148: beq         $v0, $zero, L_80800170
    if (ctx->r2 == 0) {
        // 0x8080014C: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_80800170;
    }
    // 0x8080014C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800150: jal         0x800D90A4
    // 0x80800154: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_4;
    // 0x80800154: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_4:
    // 0x80800158: beq         $v0, $zero, L_808001EC
    if (ctx->r2 == 0) {
        // 0x8080015C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001EC;
    }
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800160: jal         0x808003B4
    // 0x80800164: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808003B4_chlinkpipefan(rdram, ctx);
        goto after_5;
    // 0x80800164: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800168: b           L_808001F0
    // 0x8080016C: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
        goto L_808001F0;
    // 0x8080016C: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
L_80800170:
    // 0x80800170: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800174: lwc1        $f12, 0x34($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800178: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080017C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800180: lui         $a3, 0x43E1
    ctx->r7 = S32(0X43E1 << 16);
    // 0x80800184: jal         0x800F10B4
    // 0x80800188: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80800188: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x8080018C: b           L_808001EC
    // 0x80800190: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
        goto L_808001EC;
    // 0x80800190: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_80800194:
    // 0x80800194: jal         0x800D90A4
    // 0x80800198: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    func_800D90A4(rdram, ctx);
        goto after_7;
    // 0x80800198: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    after_7:
    // 0x8080019C: beq         $v0, $zero, L_808001CC
    if (ctx->r2 == 0) {
        // 0x808001A0: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_808001CC;
    }
    // 0x808001A0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808001A4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808001A8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x808001AC: jal         0x800D90A4
    // 0x808001B0: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    func_800D90A4(rdram, ctx);
        goto after_8;
    // 0x808001B0: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    after_8:
    // 0x808001B4: beq         $v0, $zero, L_808001EC
    if (ctx->r2 == 0) {
        // 0x808001B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001EC;
    }
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: jal         0x808003B4
    // 0x808001C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808003B4_chlinkpipefan(rdram, ctx);
        goto after_9;
    // 0x808001C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x808001C4: b           L_808001F0
    // 0x808001C8: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
        goto L_808001F0;
    // 0x808001C8: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
L_808001CC:
    // 0x808001CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808001D0: lwc1        $f12, 0x34($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808001D4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001D8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001DC: lui         $a3, 0x43E1
    ctx->r7 = S32(0X43E1 << 16);
    // 0x808001E0: jal         0x800F10B4
    // 0x808001E4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_10;
    // 0x808001E4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x808001E8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_808001EC:
    // 0x808001EC: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
L_808001F0:
    // 0x808001F0: jal         0x800D8FF8
    // 0x808001F4: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_11;
    // 0x808001F4: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    after_11:
    // 0x808001F8: lwc1        $f16, 0x54($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808001FC: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800200: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800204: jal         0x800136E4
    // 0x80800208: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_12;
    // 0x80800208: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_12:
    // 0x8080020C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800210: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800214: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80800218: jal         0x800F13C4
    // 0x8080021C: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    func_800F13C4(rdram, ctx);
        goto after_13;
    // 0x8080021C: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    after_13:
    // 0x80800220: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800224: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800228: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8080022C: jal         0x800F13C4
    // 0x80800230: lwc1        $f12, 0x4C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4C);
    func_800F13C4(rdram, ctx);
        goto after_14;
    // 0x80800230: lwc1        $f12, 0x4C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4C);
    after_14:
    // 0x80800234: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800238: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x8080023C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800240: nop

    // 0x80800244: bc1fl       L_808002D4
    if (!c1cs) {
        // 0x80800248: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_808002D4;
    }
    goto skip_0;
    // 0x80800248: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x8080024C: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800250: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800254: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80800258: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    // 0x8080025C: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80800260: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x80800264: bc1fl       L_808002D4
    if (!c1cs) {
        // 0x80800268: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_808002D4;
    }
    goto skip_1;
    // 0x80800268: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_1:
    // 0x8080026C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800270: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2248, 0X8F4) << 16);
    // 0x80800274: lwc1        $f10, 0x8F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2248, 0X8F4));
    // 0x80800278: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8080027C: jal         0x800F10B4
    // 0x80800280: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_15;
    // 0x80800280: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_15:
    // 0x80800284: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2248, 0X8F8) << 16);
    // 0x80800288: lwc1        $f12, 0x8F8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2248, 0X8F8));
    // 0x8080028C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2248, 0X8FC) << 16);
    // 0x80800290: lwc1        $f14, 0x8FC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2248, 0X8FC));
    // 0x80800294: jal         0x800DC178
    // 0x80800298: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_16;
    // 0x80800298: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_16:
    // 0x8080029C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808002A0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808002A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002A8: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x808002AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2248, 0X900) << 16);
    // 0x808002B0: lwc1        $f6, 0x900($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2248, 0X900));
    // 0x808002B4: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    // 0x808002B8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808002BC: addiu       $a2, $zero, 0x4A38
    ctx->r6 = ADD32(0, 0X4A38);
    // 0x808002C0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x808002C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x808002C8: jal         0x800C4208
    // 0x808002CC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C4208(rdram, ctx);
        goto after_17;
    // 0x808002CC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_17:
    // 0x808002D0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_808002D4:
    // 0x808002D4: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808002E0: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x808002E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808002E8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2248, 0X910) << 16);
    // 0x808002EC: bc1tl       L_80800334
    if (c1cs) {
        // 0x808002F0: lw          $v0, 0x6C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X6C);
            goto L_80800334;
    }
    goto skip_2;
    // 0x808002F0: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    skip_2:
    // 0x808002F4: jal         0x80089D50
    // 0x808002F8: addiu       $a3, $a3, 0x910
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2248, 0X910));
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_18;
    // 0x808002F8: addiu       $a3, $a3, 0x910
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2248, 0X910));
    after_18:
    // 0x808002FC: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80800300: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800304: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2248, 0X904) << 16);
    // 0x80800308: lwc1        $f16, 0x904($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2248, 0X904));
    // 0x8080030C: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800310: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800314: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800318: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    // 0x8080031C: jal         0x800F10B4
    // 0x80800320: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_19;
    // 0x80800320: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_19:
    // 0x80800324: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800328: jal         0x80089D30
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_20;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800330: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
L_80800334:
    // 0x80800334: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x80800338: beq         $t7, $zero, L_80800358
    if (ctx->r15 == 0) {
        // 0x8080033C: nop
    
            goto L_80800358;
    }
    // 0x8080033C: nop

    // 0x80800340: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800344: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800348: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x8080034C: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x80800350: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800354: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
L_80800358:
    // 0x80800358: jal         0x801065A4
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801065A4(rdram, ctx);
        goto after_21;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800360: beql        $v0, $zero, L_8080038C
    if (ctx->r2 == 0) {
        // 0x80800364: lhu         $a1, 0x72($s0)
        ctx->r5 = MEM_HU(ctx->r16, 0X72);
            goto L_8080038C;
    }
    goto skip_3;
    // 0x80800364: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    skip_3:
    // 0x80800368: jal         0x801065A4
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801065A4(rdram, ctx);
        goto after_22;
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800370: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800374: addiu       $a2, $a2, 0x7420
    ctx->r6 = ADD32(ctx->r6, 0X7420);
    // 0x80800378: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080037C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800380: jal         0x80088660
    // 0x80800384: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_23;
    // 0x80800384: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_23:
    // 0x80800388: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
L_8080038C:
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: srl         $t3, $a1, 10
    ctx->r11 = S32(U32(ctx->r5) >> 10);
    // 0x80800394: xori        $t4, $t3, 0x4
    ctx->r12 = ctx->r11 ^ 0X4;
    // 0x80800398: jal         0x8010A654
    // 0x8080039C: sltiu       $a1, $t4, 0x1
    ctx->r5 = ctx->r12 < 0X1 ? 1 : 0;
    func_8010A654(rdram, ctx);
        goto after_24;
    // 0x8080039C: sltiu       $a1, $t4, 0x1
    ctx->r5 = ctx->r12 < 0X1 ? 1 : 0;
    after_24:
    // 0x808003A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808003AC: jr          $ra
    // 0x808003B0: nop

    return;
    // 0x808003B0: nop

;}
RECOMP_FUNC void func_80803538_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803538: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080353C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80803540: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80803544: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80803548: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8080354C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80803550: jal         0x80106790
    // 0x80803554: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80803554: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80803558: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080355C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803560: jal         0x80100094
    // 0x80803564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80803564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80803568: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080356C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803570: jal         0x80089AC8
    // 0x80803574: lbu         $a1, 0x20($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X20);
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80803574: lbu         $a1, 0x20($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X20);
    after_2:
    // 0x80803578: beq         $v0, $zero, L_808035D0
    if (ctx->r2 == 0) {
        // 0x8080357C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808035D0;
    }
    // 0x8080357C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803580: jal         0x800F5F24
    // 0x80803584: lbu         $a0, 0x20($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X20);
    func_800F5F24(rdram, ctx);
        goto after_3;
    // 0x80803584: lbu         $a0, 0x20($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X20);
    after_3:
    // 0x80803588: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x8080358C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803590: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
    // 0x80803594: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80803598: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080359C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808035A0: lui         $a3, 0x43E1
    ctx->r7 = S32(0X43E1 << 16);
    // 0x808035A4: jal         0x800F10B4
    // 0x808035A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x808035A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x808035AC: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x808035B0: lbu         $a0, 0x20($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X20);
    // 0x808035B4: jal         0x800F4F98
    // 0x808035B8: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_800F4F98(rdram, ctx);
        goto after_5;
    // 0x808035B8: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_5:
    // 0x808035BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808035C0: jal         0x80089AF0
    // 0x808035C4: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    _sukickball_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x808035C4: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    after_6:
    // 0x808035C8: b           L_80803630
    // 0x808035CC: lbu         $t7, 0x72($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X72);
        goto L_80803630;
    // 0x808035CC: lbu         $t7, 0x72($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X72);
L_808035D0:
    // 0x808035D0: jal         0x80089AD8
    // 0x808035D4: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    _sukickball_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x808035D4: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    after_7:
    // 0x808035D8: jal         0x80106790
    // 0x808035DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_8;
    // 0x808035DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x808035E0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808035E4: lwc1        $f6, 0x48($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X48);
    // 0x808035E8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808035EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808035F0: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x808035F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808035F8: swc1        $f6, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f6.u32l;
    // 0x808035FC: lwc1        $f12, 0x58($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80803600: lui         $a2, 0x4180
    ctx->r6 = S32(0X4180 << 16);
    // 0x80803604: lui         $a3, 0x43E1
    ctx->r7 = S32(0X43E1 << 16);
    // 0x80803608: jal         0x800F10B4
    // 0x8080360C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x8080360C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x80803610: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x80803614: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80803618: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8080361C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803620: swc1        $f10, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f10.u32l;
    // 0x80803624: jal         0x80089AF0
    // 0x80803628: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    _sukickball_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x80803628: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    after_10:
    // 0x8080362C: lbu         $t7, 0x72($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X72);
L_80803630:
    // 0x80803630: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80803634: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x80803638: andi        $t8, $t7, 0xFF03
    ctx->r24 = ctx->r15 & 0XFF03;
    // 0x8080363C: ori         $t9, $t8, 0xC
    ctx->r25 = ctx->r24 | 0XC;
    // 0x80803640: sb          $t9, 0x72($s1)
    MEM_B(0X72, ctx->r17) = ctx->r25;
    // 0x80803644: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x80803648: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    // 0x8080364C: sb          $t0, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r8;
    // 0x80803650: ori         $a2, $a2, 0x640
    ctx->r6 = ctx->r6 | 0X640;
    // 0x80803654: ori         $a0, $a0, 0x453C
    ctx->r4 = ctx->r4 | 0X453C;
    // 0x80803658: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x8080365C: jal         0x800C4140
    // 0x80803660: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    func_800C4140(rdram, ctx);
        goto after_11;
    // 0x80803660: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    after_11:
    // 0x80803664: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80803668: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080366C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80803670: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80803674: jr          $ra
    // 0x80803678: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80803678: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _baeggsetup_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A88: syscall     126
    recomp_syscall_handler(rdram, ctx, 0x80084A88);
    return;
    // 0x80084A8C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void dbid_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: lh          $a2, 0x0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X0);
    // 0x808000CC: addiu       $v1, $a0, 0x2
    ctx->r3 = ADD32(ctx->r4, 0X2);
    // 0x808000D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000D4: blezl       $a2, L_80800110
    if (SIGNED(ctx->r6) <= 0) {
        // 0x808000D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800110;
    }
    goto skip_0;
    // 0x808000D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_808000DC:
    // 0x808000DC: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x808000E0: bnel        $a1, $t6, L_808000F4
    if (ctx->r5 != ctx->r14) {
        // 0x808000E4: lh          $t7, 0x2($v1)
        ctx->r15 = MEM_H(ctx->r3, 0X2);
            goto L_808000F4;
    }
    goto skip_1;
    // 0x808000E4: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    skip_1:
    // 0x808000E8: jr          $ra
    // 0x808000EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808000EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808000F0: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
L_808000F4:
    // 0x808000F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808000F8: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x808000FC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80800100: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x80800104: bne         $at, $zero, L_808000DC
    if (ctx->r1 != 0) {
        // 0x80800108: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_808000DC;
    }
    // 0x80800108: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080010C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800110:
    // 0x80800110: jr          $ra
    // 0x80800114: nop

    return;
    // 0x80800114: nop

;}
RECOMP_FUNC void func_800DF540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF540: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DF544: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800DF548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DF54C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800DF550: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF554: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DF558: sw          $t6, -0x3648($at)
    MEM_W(-0X3648, ctx->r1) = ctx->r14;
    // 0x800DF55C: jal         0x800F293C
    // 0x800DF560: addiu       $a0, $a0, -0x3638
    ctx->r4 = ADD32(ctx->r4, -0X3638);
    func_800F293C(rdram, ctx);
        goto after_0;
    // 0x800DF560: addiu       $a0, $a0, -0x3638
    ctx->r4 = ADD32(ctx->r4, -0X3638);
    after_0:
    // 0x800DF564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DF568: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DF56C: jr          $ra
    // 0x800DF570: nop

    return;
    // 0x800DF570: nop

;}
RECOMP_FUNC void _sulights_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A8B0: syscall     854
    recomp_syscall_handler(rdram, ctx, 0x8008A8B0);
    return;
    // 0x8008A8B4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80804C6C_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804C6C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80804C70: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80804C74: beq         $a1, $at, L_80804C84
    if (ctx->r5 == ctx->r1) {
        // 0x80804C78: sw          $a2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r6;
            goto L_80804C84;
    }
    // 0x80804C78: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80804C7C: jr          $ra
    // 0x80804C80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80804C80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80804C84:
    // 0x80804C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80804C88: jr          $ra
    // 0x80804C8C: nop

    return;
    // 0x80804C8C: nop

;}
RECOMP_FUNC void basnowball_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800624: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80800628: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8080062C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800630: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800634: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80800638: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8080063C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800640: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800644: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800648: jal         0x800B5BE4
    // 0x8080064C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x8080064C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // 0x80800650: lw          $t6, 0x110($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X110);
    // 0x80800654: addiu       $s4, $sp, 0x5C
    ctx->r20 = ADD32(ctx->r29, 0X5C);
    // 0x80800658: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080065C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800660: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800664: jal         0x8009C128
    // 0x80800668: lwc1        $f20, 0x1C($t6)
    ctx->f20.u32l = MEM_W(ctx->r14, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x80800668: lwc1        $f20, 0x1C($t6)
    ctx->f20.u32l = MEM_W(ctx->r14, 0X1C);
    after_1:
    // 0x8080066C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800670: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800674: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800678: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(604, 0X1098) << 16);
    // 0x8080067C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80800680: addiu       $t7, $t7, 0x1098
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(604, 0X1098));
    // 0x80800684: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080068C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800690: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800694: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800698: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8080069C: jal         0x800BABB8
    // 0x808006A0: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x808006A0: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x808006A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808006A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808006AC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808006B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006B4: mul.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x808006B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808006BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808006C0: jal         0x800BA7C4
    // 0x808006C4: nop

    func_800BA7C4(rdram, ctx);
        goto after_3;
    // 0x808006C4: nop

    after_3:
    // 0x808006C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(604, 0XFF8) << 16);
    // 0x808006CC: lwc1        $f18, 0xFF8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0XFF8));
    // 0x808006D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006D4: mul.s       $f0, $f18, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x808006D8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808006DC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808006E0: jal         0x800BA7FC
    // 0x808006E4: nop

    func_800BA7FC(rdram, ctx);
        goto after_4;
    // 0x808006E4: nop

    after_4:
    // 0x808006E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(604, 0XFFC) << 16);
    // 0x808006EC: lwc1        $f6, 0xFFC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0XFFC));
    // 0x808006F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(604, 0X1000) << 16);
    // 0x808006F4: lwc1        $f8, 0x1000($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X1000));
    // 0x808006F8: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x808006FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800700: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800704: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800708: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080070C: jal         0x800BA8F8
    // 0x80800710: nop

    func_800BA8F8(rdram, ctx);
        goto after_5;
    // 0x80800710: nop

    after_5:
    // 0x80800714: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(604, 0X10C0) << 16);
    // 0x80800718: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(604, 0X10F0) << 16);
    // 0x8080071C: addiu       $s3, $s3, 0x10F0
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(604, 0X10F0));
    // 0x80800720: addiu       $s0, $s0, 0x10C0
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(604, 0X10C0));
    // 0x80800724: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x80800728: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8080072C:
    // 0x8080072C: jal         0x800EE7F8
    // 0x80800730: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800730: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_6:
    // 0x80800734: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800738: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8080073C: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800740: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80800744: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800748: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080074C: mul.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80800750: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800754: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80800758: add.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8080075C: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x80800760: jal         0x800BA75C
    // 0x80800764: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    func_800BA75C(rdram, ctx);
        goto after_7;
    // 0x80800764: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x80800768: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080076C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800770: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800774: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800778: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080077C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800780: nop

    // 0x80800784: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x80800788: jal         0x800BA77C
    // 0x8080078C: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    func_800BA77C(rdram, ctx);
        goto after_8;
    // 0x8080078C: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    after_8:
    // 0x80800790: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800794: jal         0x800BA22C
    // 0x80800798: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_9;
    // 0x80800798: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x8080079C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x808007A0: bnel        $s0, $s3, L_8080072C
    if (ctx->r16 != ctx->r19) {
        // 0x808007A4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080072C;
    }
    goto skip_0;
    // 0x808007A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x808007A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x808007AC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808007B0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808007B4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808007B8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808007BC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x808007C0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x808007C4: jr          $ra
    // 0x808007C8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x808007C8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
