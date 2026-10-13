#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chlagoonufoint_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A58: syscall     190
    recomp_syscall_handler(rdram, ctx, 0x80085A58);
    return;
    // 0x80085A5C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _sukickball_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089AD0: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089AD0);
    return;
    // 0x80089AD4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80800000_chtemplebrokendoorpiece(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800C0090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0090: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C0094: bnel        $a1, $at, L_800C00A8
    if (ctx->r5 != ctx->r1) {
        // 0x800C0098: lhu         $t6, 0x12($a0)
        ctx->r14 = MEM_HU(ctx->r4, 0X12);
            goto L_800C00A8;
    }
    goto skip_0;
    // 0x800C0098: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
    skip_0:
    // 0x800C009C: jr          $ra
    // 0x800C00A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C00A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C00A4: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
L_800C00A8:
    // 0x800C00A8: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x800C00AC: xor         $v1, $a1, $t7
    ctx->r3 = ctx->r5 ^ ctx->r15;
    // 0x800C00B0: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800C00B4: jr          $ra
    // 0x800C00B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C00B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8001DD28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DD28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001DD2C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001DD30: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001DD34: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8001DD38: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8001DD3C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001DD40: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8001DD44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001DD48: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8001DD4C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8001DD50: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8001DD54: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001DD58: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001DD5C: jal         0x80031810
    // 0x8001DD60: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x8001DD60: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x8001DD64: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001DD68: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001DD6C: beq         $s0, $zero, L_8001DD84
    if (ctx->r16 == 0) {
        // 0x8001DD70: sw          $s0, 0x1C($a0)
        MEM_W(0X1C, ctx->r4) = ctx->r16;
            goto L_8001DD84;
    }
    // 0x8001DD70: sw          $s0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r16;
    // 0x8001DD74: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001DD78: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
    // 0x8001DD7C: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8001DD80: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_8001DD84:
    // 0x8001DD84: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8001DD88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001DD8C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001DD90: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8001DD94: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8001DD98: sw          $a0, -0x27E0($at)
    MEM_W(-0X27E0, ctx->r1) = ctx->r4;
    // 0x8001DD9C: jr          $ra
    // 0x8001DDA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001DDA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800B90C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B90C8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800B90CC: lw          $v0, 0x7128($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7128);
    // 0x800B90D0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B90D4: beq         $v0, $zero, L_800B90E0
    if (ctx->r2 == 0) {
        // 0x800B90D8: nop
    
            goto L_800B90E0;
    }
    // 0x800B90D8: nop

    // 0x800B90DC: sb          $t6, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r14;
L_800B90E0:
    // 0x800B90E0: jr          $ra
    // 0x800B90E4: nop

    return;
    // 0x800B90E4: nop

;}
RECOMP_FUNC void _sujiggy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A6A0: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A6A0);
    return;
    // 0x8008A6A4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808003DC_bsdronexform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003DC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808003E0: lw          $t6, 0x18C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18C);
    // 0x808003E4: jr          $ra
    // 0x808003E8: swc1        $f12, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x808003E8: swc1        $f12, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void _sucoaster_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A100: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A100);
    return;
    // 0x8008A104: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void glid_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808000FC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800100: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800104: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800108: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8080010C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80800110: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800114: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800118: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8080011C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800120: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800124: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x80800128: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x8080012C: jal         0x800B2190
    // 0x80800130: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    func_800B2190(rdram, ctx);
        goto after_0;
    // 0x80800130: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    after_0:
    // 0x80800134: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800138: jal         0x800B2190
    // 0x8080013C: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    func_800B2190(rdram, ctx);
        goto after_1;
    // 0x8080013C: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    after_1:
    // 0x80800140: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x80800144: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800148: addiu       $v1, $s1, 0x1C
    ctx->r3 = ADD32(ctx->r17, 0X1C);
    // 0x8080014C: blez        $a1, L_808001D4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80800150: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808001D4;
    }
    // 0x80800150: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800154:
    // 0x80800154: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80800158: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8080015C: bnel        $s0, $t6, L_808001C8
    if (ctx->r16 != ctx->r14) {
        // 0x80800160: lw          $t2, 0x4($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X4);
            goto L_808001C8;
    }
    goto skip_0;
    // 0x80800160: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x80800164: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x80800168: addiu       $s0, $v1, 0x8
    ctx->r16 = ADD32(ctx->r3, 0X8);
    // 0x8080016C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800170: addu        $s2, $t8, $v1
    ctx->r18 = ADD32(ctx->r24, ctx->r3);
    // 0x80800174: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80800178: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x8080017C: beq         $at, $zero, L_808001D4
    if (ctx->r1 == 0) {
        // 0x80800180: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_808001D4;
    }
    // 0x80800180: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_80800184:
    // 0x80800184: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x80800188: lh          $a3, 0x2($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X2);
    // 0x8080018C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80800190: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x80800194: addu        $a1, $t9, $s3
    ctx->r5 = ADD32(ctx->r25, ctx->r19);
    // 0x80800198: addu        $a2, $t9, $s4
    ctx->r6 = ADD32(ctx->r25, ctx->r20);
    // 0x8080019C: jalr        $s6
    // 0x808001A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_2;
    // 0x808001A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x808001A4: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x808001A8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808001AC: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x808001B0: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x808001B4: bne         $at, $zero, L_80800184
    if (ctx->r1 != 0) {
        // 0x808001B8: addu        $s1, $s1, $t1
        ctx->r17 = ADD32(ctx->r17, ctx->r9);
            goto L_80800184;
    }
    // 0x808001B8: addu        $s1, $s1, $t1
    ctx->r17 = ADD32(ctx->r17, ctx->r9);
    // 0x808001BC: b           L_808001D8
    // 0x808001C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_808001D8;
    // 0x808001C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x808001C4: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
L_808001C8:
    // 0x808001C8: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x808001CC: bne         $at, $zero, L_80800154
    if (ctx->r1 != 0) {
        // 0x808001D0: addu        $v1, $v1, $t2
        ctx->r3 = ADD32(ctx->r3, ctx->r10);
            goto L_80800154;
    }
    // 0x808001D0: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
L_808001D4:
    // 0x808001D4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_808001D8:
    // 0x808001D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001DC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808001E0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808001E4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x808001E8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x808001EC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x808001F0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x808001F4: jr          $ra
    // 0x808001F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808001F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80110898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110898: jr          $ra
    // 0x8011089C: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    return;
    // 0x8011089C: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
;}
RECOMP_FUNC void func_80800000_chquizexitdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800018: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080001C: beq         $t6, $at, L_80800038
    if (ctx->r14 == ctx->r1) {
        // 0x80800020: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800038;
    }
    // 0x80800020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800024: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800028: beq         $t6, $at, L_80800048
    if (ctx->r14 == ctx->r1) {
        // 0x8080002C: nop
    
            goto L_80800048;
    }
    // 0x8080002C: nop

    // 0x80800030: b           L_80800114
    // 0x80800034: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800114;
    // 0x80800034: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800038:
    // 0x80800038: jal         0x80103110
    // 0x8080003C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_0;
    // 0x8080003C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800040: b           L_80800114
    // 0x80800044: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800114;
    // 0x80800044: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800048:
    // 0x80800048: jal         0x800D90A4
    // 0x8080004C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x8080004C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x80800050: beql        $v0, $zero, L_8080006C
    if (ctx->r2 == 0) {
        // 0x80800054: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8080006C;
    }
    goto skip_0;
    // 0x80800054: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80800058: jal         0x800DA544
    // 0x8080005C: addiu       $a0, $zero, 0x440
    ctx->r4 = ADD32(0, 0X440);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x8080005C: addiu       $a0, $zero, 0x440
    ctx->r4 = ADD32(0, 0X440);
    after_2:
    // 0x80800060: jal         0x800FFAB0
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800068: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8080006C:
    // 0x8080006C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800070: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800074: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800078: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080007C: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x80800080: jal         0x800F10B4
    // 0x80800084: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80800084: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80800088: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8080008C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800090: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80800094: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800098: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8080009C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x808000A0: nop

    // 0x808000A4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x808000A8: beql        $t8, $zero, L_808000F8
    if (ctx->r24 == 0) {
        // 0x808000AC: mfc1        $t8, $f4
        ctx->r24 = (int32_t)ctx->f4.u32l;
            goto L_808000F8;
    }
    goto skip_1;
    // 0x808000AC: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x808000B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808000B8: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x808000BC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x808000C0: nop

    // 0x808000C4: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x808000C8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x808000CC: nop

    // 0x808000D0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x808000D4: bne         $t8, $zero, L_808000EC
    if (ctx->r24 != 0) {
        // 0x808000D8: nop
    
            goto L_808000EC;
    }
    // 0x808000D8: nop

    // 0x808000DC: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x808000E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808000E4: b           L_80800104
    // 0x808000E8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80800104;
    // 0x808000E8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_808000EC:
    // 0x808000EC: b           L_80800104
    // 0x808000F0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80800104;
    // 0x808000F0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x808000F4: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
L_808000F8:
    // 0x808000F8: nop

    // 0x808000FC: bltz        $t8, L_808000EC
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800100: nop
    
            goto L_808000EC;
    }
    // 0x80800100: nop

L_80800104:
    // 0x80800104: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800108: sb          $t8, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r24;
    // 0x8080010C: nop

    // 0x80800110: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800114:
    // 0x80800114: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080011C: jr          $ra
    // 0x80800120: nop

    return;
    // 0x80800120: nop

;}
RECOMP_FUNC void func_800C15BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C15BC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
L_800C15C0:
    // 0x800C15C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C15C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C15C8: addiu       $a0, $a0, -0x74F0
    ctx->r4 = ADD32(ctx->r4, -0X74F0);
    // 0x800C15CC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C15D0:
    // 0x800C15D0: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800C15D4: beql        $t6, $zero, L_800C15E8
    if (ctx->r14 == 0) {
        // 0x800C15D8: lw          $t7, 0x0($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X0);
            goto L_800C15E8;
    }
    goto skip_0;
    // 0x800C15D8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800C15DC: b           L_800C15FC
    // 0x800C15E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800C15FC;
    // 0x800C15E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C15E4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
L_800C15E8:
    // 0x800C15E8: bne         $t7, $zero, L_800C15FC
    if (ctx->r15 != 0) {
        // 0x800C15EC: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800C15FC;
    }
    // 0x800C15EC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C15F0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800C15F4: jr          $ra
    // 0x800C15F8: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    return;
    // 0x800C15F8: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_800C15FC:
    // 0x800C15FC: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x800C1600: beql        $t9, $zero, L_800C1614
    if (ctx->r25 == 0) {
        // 0x800C1604: lw          $t0, 0x8($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X8);
            goto L_800C1614;
    }
    goto skip_1;
    // 0x800C1604: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    skip_1:
    // 0x800C1608: b           L_800C1628
    // 0x800C160C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800C1628;
    // 0x800C160C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C1610: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
L_800C1614:
    // 0x800C1614: bne         $t0, $zero, L_800C1628
    if (ctx->r8 != 0) {
        // 0x800C1618: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_800C1628;
    }
    // 0x800C1618: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C161C: sw          $t1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r9;
    // 0x800C1620: jr          $ra
    // 0x800C1624: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    return;
    // 0x800C1624: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
L_800C1628:
    // 0x800C1628: lw          $t2, 0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X14);
    // 0x800C162C: beql        $t2, $zero, L_800C1640
    if (ctx->r10 == 0) {
        // 0x800C1630: lw          $t3, 0x10($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X10);
            goto L_800C1640;
    }
    goto skip_2;
    // 0x800C1630: lw          $t3, 0x10($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X10);
    skip_2:
    // 0x800C1634: b           L_800C1654
    // 0x800C1638: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800C1654;
    // 0x800C1638: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C163C: lw          $t3, 0x10($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X10);
L_800C1640:
    // 0x800C1640: bne         $t3, $zero, L_800C1654
    if (ctx->r11 != 0) {
        // 0x800C1644: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800C1654;
    }
    // 0x800C1644: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800C1648: sw          $t4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r12;
    // 0x800C164C: jr          $ra
    // 0x800C1650: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    return;
    // 0x800C1650: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
L_800C1654:
    // 0x800C1654: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x800C1658: beql        $t5, $zero, L_800C166C
    if (ctx->r13 == 0) {
        // 0x800C165C: lw          $t6, 0x18($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X18);
            goto L_800C166C;
    }
    goto skip_3;
    // 0x800C165C: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    skip_3:
    // 0x800C1660: b           L_800C1680
    // 0x800C1664: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800C1680;
    // 0x800C1664: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C1668: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
L_800C166C:
    // 0x800C166C: bne         $t6, $zero, L_800C1680
    if (ctx->r14 != 0) {
        // 0x800C1670: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800C1680;
    }
    // 0x800C1670: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C1674: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x800C1678: jr          $ra
    // 0x800C167C: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    return;
    // 0x800C167C: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
L_800C1680:
    // 0x800C1680: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C1684: bne         $v1, $a1, L_800C15D0
    if (ctx->r3 != ctx->r5) {
        // 0x800C1688: addiu       $a0, $a0, 0x20
        ctx->r4 = ADD32(ctx->r4, 0X20);
            goto L_800C15D0;
    }
    // 0x800C1688: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800C168C: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x800C1690: bne         $at, $zero, L_800C15C0
    if (ctx->r1 != 0) {
        // 0x800C1694: nop
    
            goto L_800C15C0;
    }
    // 0x800C1694: nop

    // 0x800C1698: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C169C: jr          $ra
    // 0x800C16A0: nop

    return;
    // 0x800C16A0: nop

;}
RECOMP_FUNC void chlagoonbilldrillcover_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1444, 0X330) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x330
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1444, 0X330));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x330
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1444, 0X330));
;}
RECOMP_FUNC void func_80800774_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080077C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800780: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800784: jal         0x8008FB58
    // 0x80800788: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    func_8008FB58(rdram, ctx);
        goto after_0;
    // 0x80800788: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    after_0:
    // 0x8080078C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800790: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800794: jr          $ra
    // 0x80800798: nop

    return;
    // 0x80800798: nop

;}
RECOMP_FUNC void func_80017404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017404: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80017408: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001740C: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x80017410: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80017414: addiu       $t0, $t0, -0x6060
    ctx->r8 = ADD32(ctx->r8, -0X6060);
    // 0x80017418: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001741C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80017420: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80017424: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80017428: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001742C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80017430: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80017434: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80017438: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8001743C: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80017440: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80017444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017448: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // 0x8001744C: sh          $a1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r5;
    // 0x80017450: addiu       $a0, $v0, 0x1E0
    ctx->r4 = ADD32(ctx->r2, 0X1E0);
    // 0x80017454: jal         0x80025ED0
    // 0x80017458: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80025ED0(rdram, ctx);
        goto after_0;
    // 0x80017458: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8001745C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80017460: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    // 0x80017464: lbu         $v1, 0x3($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X3);
    // 0x80017468: beq         $v1, $zero, L_80017488
    if (ctx->r3 == 0) {
        // 0x8001746C: nop
    
            goto L_80017488;
    }
    // 0x8001746C: nop

    // 0x80017470: beq         $a1, $zero, L_80017488
    if (ctx->r5 == 0) {
        // 0x80017474: nop
    
            goto L_80017488;
    }
    // 0x80017474: nop

    // 0x80017478: jal         0x800173B0
    // 0x8001747C: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    func_800173B0(rdram, ctx);
        goto after_1;
    // 0x8001747C: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    after_1:
    // 0x80017480: b           L_800174B4
    // 0x80017484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800174B4;
    // 0x80017484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80017488:
    // 0x80017488: bnel        $v1, $zero, L_800174B4
    if (ctx->r3 != 0) {
        // 0x8001748C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800174B4;
    }
    goto skip_0;
    // 0x8001748C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80017490: bnel        $a1, $zero, L_800174B4
    if (ctx->r5 != 0) {
        // 0x80017494: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800174B4;
    }
    goto skip_1;
    // 0x80017494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80017498: jal         0x80017778
    // 0x8001749C: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    func_80017778(rdram, ctx);
        goto after_2;
    // 0x8001749C: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    after_2:
    // 0x800174A0: bnel        $v0, $zero, L_800174B4
    if (ctx->r2 != 0) {
        // 0x800174A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800174B4;
    }
    goto skip_2;
    // 0x800174A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800174A8: jal         0x80017330
    // 0x800174AC: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    func_80017330(rdram, ctx);
        goto after_3;
    // 0x800174AC: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    after_3:
    // 0x800174B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800174B4:
    // 0x800174B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800174B8: jr          $ra
    // 0x800174BC: nop

    return;
    // 0x800174BC: nop

;}
RECOMP_FUNC void func_808006C8_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808006CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808006D4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808006D8: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x808006DC: jal         0x80100094
    // 0x808006E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006E4: jal         0x800D8FF8
    // 0x808006E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808006E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x808006EC: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x808006F0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808006F4: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x808006F8: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x808006FC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80800700: bgezl       $t9, L_808008B8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800704: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808008B8;
    }
    goto skip_0;
    // 0x80800704: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800708: jal         0x800F5A00
    // 0x8080070C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x8080070C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_2:
    // 0x80800710: jal         0x8080063C
    // 0x80800714: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    func_8080063C_chdragonbrothers(rdram, ctx);
        goto after_3;
    // 0x80800714: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_3:
    // 0x80800718: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8080071C: lwc1        $f14, 0x3C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80800720: jal         0x800F1DCC
    // 0x80800724: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_4;
    // 0x80800724: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x80800728: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8080072C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X4FFC) << 16);
    // 0x80800730: lwc1        $f6, 0x4FFC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X4FFC));
    // 0x80800734: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80800738: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8080073C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800740: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800744: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800748: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8080074C: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x80800750: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800754: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800758: jal         0x80016B54
    // 0x8080075C: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    func_80016B54(rdram, ctx);
        goto after_5;
    // 0x8080075C: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    after_5:
    // 0x80800760: bne         $v0, $zero, L_808007F0
    if (ctx->r2 != 0) {
        // 0x80800764: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808007F0;
    }
    // 0x80800764: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800768: jal         0x80016B30
    // 0x8080076C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80016B30(rdram, ctx);
        goto after_6;
    // 0x8080076C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800770: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800774: bnel        $v0, $v1, L_808007F4
    if (ctx->r2 != ctx->r3) {
        // 0x80800778: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_808007F4;
    }
    goto skip_1;
    // 0x80800778: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_1:
    // 0x8080077C: lbu         $a1, 0x55($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X55);
    // 0x80800780: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80800784: addiu       $a0, $zero, 0x487
    ctx->r4 = ADD32(0, 0X487);
    // 0x80800788: beq         $a1, $zero, L_808007D8
    if (ctx->r5 == 0) {
        // 0x8080078C: addiu       $a2, $zero, 0x2EE0
        ctx->r6 = ADD32(0, 0X2EE0);
            goto L_808007D8;
    }
    // 0x8080078C: addiu       $a2, $zero, 0x2EE0
    ctx->r6 = ADD32(0, 0X2EE0);
    // 0x80800790: beq         $a1, $v1, L_808007C0
    if (ctx->r5 == ctx->r3) {
        // 0x80800794: addiu       $a0, $zero, 0x488
        ctx->r4 = ADD32(0, 0X488);
            goto L_808007C0;
    }
    // 0x80800794: addiu       $a0, $zero, 0x488
    ctx->r4 = ADD32(0, 0X488);
    // 0x80800798: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080079C: bne         $a1, $at, L_808007E8
    if (ctx->r5 != ctx->r1) {
        // 0x808007A0: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_808007E8;
    }
    // 0x808007A0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808007A4: sb          $t0, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r8;
    // 0x808007A8: addiu       $a0, $zero, 0x488
    ctx->r4 = ADD32(0, 0X488);
    // 0x808007AC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808007B0: jal         0x800C3FC0
    // 0x808007B4: addiu       $a2, $zero, 0x2EE0
    ctx->r6 = ADD32(0, 0X2EE0);
    func_800C3FC0(rdram, ctx);
        goto after_7;
    // 0x808007B4: addiu       $a2, $zero, 0x2EE0
    ctx->r6 = ADD32(0, 0X2EE0);
    after_7:
    // 0x808007B8: b           L_808007E8
    // 0x808007BC: lbu         $a1, 0x55($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X55);
        goto L_808007E8;
    // 0x808007BC: lbu         $a1, 0x55($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X55);
L_808007C0:
    // 0x808007C0: sb          $zero, 0x55($s0)
    MEM_B(0X55, ctx->r16) = 0;
    // 0x808007C4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808007C8: jal         0x800C3FC0
    // 0x808007CC: addiu       $a2, $zero, 0x2EE0
    ctx->r6 = ADD32(0, 0X2EE0);
    func_800C3FC0(rdram, ctx);
        goto after_8;
    // 0x808007CC: addiu       $a2, $zero, 0x2EE0
    ctx->r6 = ADD32(0, 0X2EE0);
    after_8:
    // 0x808007D0: b           L_808007E8
    // 0x808007D4: lbu         $a1, 0x55($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X55);
        goto L_808007E8;
    // 0x808007D4: lbu         $a1, 0x55($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X55);
L_808007D8:
    // 0x808007D8: sb          $t1, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r9;
    // 0x808007DC: jal         0x800C3FC0
    // 0x808007E0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800C3FC0(rdram, ctx);
        goto after_9;
    // 0x808007E0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_9:
    // 0x808007E4: lbu         $a1, 0x55($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X55);
L_808007E8:
    // 0x808007E8: jal         0x808005A4
    // 0x808007EC: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    func_808005A4_chdragonbrothers(rdram, ctx);
        goto after_10;
    // 0x808007EC: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    after_10:
L_808007F0:
    // 0x808007F0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_808007F4:
    // 0x808007F4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808007F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808007FC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800800: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800804: lwc1        $f12, 0x30($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80800808: lwc1        $f18, 0x24($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8080080C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800810: sub.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80800814: mul.s       $f16, $f12, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80800818: beq         $v1, $a0, L_8080084C
    if (ctx->r3 == ctx->r4) {
        // 0x8080081C: nop
    
            goto L_8080084C;
    }
    // 0x8080081C: nop

L_80800820:
    // 0x80800820: mul.s       $f14, $f16, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80800824: lwc1        $f12, 0x34($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80800828: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8080082C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800830: add.s       $f14, $f18, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x80800834: lwc1        $f18, 0x24($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80800838: sub.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8080083C: swc1        $f14, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f14.u32l;
    // 0x80800840: mul.s       $f16, $f12, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80800844: bne         $v1, $a0, L_80800820
    if (ctx->r3 != ctx->r4) {
        // 0x80800848: nop
    
            goto L_80800820;
    }
    // 0x80800848: nop

L_8080084C:
    // 0x8080084C: mul.s       $f14, $f16, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80800850: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800854: add.s       $f14, $f18, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x80800858: swc1        $f14, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f14.u32l;
    // 0x8080085C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800860: lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X40);
    // 0x80800864: jal         0x800EFCD8
    // 0x80800868: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    func_800EFCD8(rdram, ctx);
        goto after_11;
    // 0x80800868: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    after_11:
    // 0x8080086C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800870: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800874: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x80800878: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080087C: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x80800880: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80800884: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x80800888: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x8080088C: jal         0x800F5EF8
    // 0x80800890: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_800F5EF8(rdram, ctx);
        goto after_12;
    // 0x80800890: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_12:
    // 0x80800894: jal         0x80110024
    // 0x80800898: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110024(rdram, ctx);
        goto after_13;
    // 0x80800898: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x8080089C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008A0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x808008A4: jal         0x80089500
    // 0x808008A8: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    _ncpod_entrypoint_8(rdram, ctx);
        goto after_14;
    // 0x808008A8: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_14:
    // 0x808008AC: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808008B0: swc1        $f16, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f16.u32l;
    // 0x808008B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008B8:
    // 0x808008B8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808008BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008C0: jr          $ra
    // 0x808008C4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x808008C4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800DF944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF944: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800DF948: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DF94C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800DF950: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800DF954: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800DF958: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800DF95C: jal         0x800E42F0
    // 0x800DF960: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_800E42F0(rdram, ctx);
        goto after_0;
    // 0x800DF960: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_0:
    // 0x800DF964: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x800DF968: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800DF96C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800DF970: beq         $v0, $zero, L_800DF9C8
    if (ctx->r2 == 0) {
        // 0x800DF974: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_800DF9C8;
    }
    // 0x800DF974: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800DF978: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800DF97C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800DF980: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DF984: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DF988: lui         $at, 0x4418
    ctx->r1 = S32(0X4418 << 16);
    // 0x800DF98C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800DF990: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800DF994: lui         $at, 0x43E4
    ctx->r1 = S32(0X43E4 << 16);
    // 0x800DF998: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800DF99C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800DF9A0: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800DF9A4: lui         $a3, 0xC120
    ctx->r7 = S32(0XC120 << 16);
    // 0x800DF9A8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800DF9AC: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800DF9B0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800DF9B4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800DF9B8: jal         0x800EFA4C
    // 0x800DF9BC: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x800DF9BC: nop

    after_1:
    // 0x800DF9C0: b           L_800DF9D4
    // 0x800DF9C4: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
        goto L_800DF9D4;
    // 0x800DF9C4: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
L_800DF9C8:
    // 0x800DF9C8: jal         0x800EFA4C
    // 0x800DF9CC: lui         $a3, 0xC120
    ctx->r7 = S32(0XC120 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x800DF9CC: lui         $a3, 0xC120
    ctx->r7 = S32(0XC120 << 16);
    after_2:
    // 0x800DF9D0: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
L_800DF9D4:
    // 0x800DF9D4: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x800DF9D8: beql        $t6, $zero, L_800DFA18
    if (ctx->r14 == 0) {
        // 0x800DF9DC: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800DFA18;
    }
    goto skip_0;
    // 0x800DF9DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x800DF9E0: lh          $t7, -0x6648($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6648);
    // 0x800DF9E4: beql        $t7, $zero, L_800DFA18
    if (ctx->r15 == 0) {
        // 0x800DF9E8: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800DFA18;
    }
    goto skip_1;
    // 0x800DF9E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_1:
    // 0x800DF9EC: jal         0x800A89F8
    // 0x800DF9F0: nop

    func_800A89F8(rdram, ctx);
        goto after_3;
    // 0x800DF9F0: nop

    after_3:
    // 0x800DF9F4: jal         0x800A8AF0
    // 0x800DF9F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A8AF0(rdram, ctx);
        goto after_4;
    // 0x800DF9F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800DF9FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800DFA00: lwc1        $f10, 0x5D68($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5D68);
    // 0x800DFA04: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800DFA08: div.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800DFA0C: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800DFA10: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x800DFA14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800DFA18:
    // 0x800DFA18: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800DFA1C: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x800DFA20: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800DFA24: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800DFA28: jal         0x800EFA4C
    // 0x800DFA2C: nop

    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x800DFA2C: nop

    after_5:
    // 0x800DFA30: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x800DFA34: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800DFA38: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x800DFA3C: beq         $v0, $zero, L_800DFA58
    if (ctx->r2 == 0) {
        // 0x800DFA40: nop
    
            goto L_800DFA58;
    }
    // 0x800DFA40: nop

    // 0x800DFA44: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800DFA48: jal         0x800EFA4C
    // 0x800DFA4C: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    func_800EFA4C(rdram, ctx);
        goto after_6;
    // 0x800DFA4C: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    after_6:
    // 0x800DFA50: b           L_800DFA60
    // 0x800DFA54: nop

        goto L_800DFA60;
    // 0x800DFA54: nop

L_800DFA58:
    // 0x800DFA58: jal         0x800EFD24
    // 0x800DFA5C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EFD24(rdram, ctx);
        goto after_7;
    // 0x800DFA5C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_7:
L_800DFA60:
    // 0x800DFA60: jal         0x800DF830
    // 0x800DFA64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF830(rdram, ctx);
        goto after_8;
    // 0x800DFA64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x800DFA68: jal         0x800DF440
    // 0x800DFA6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF440(rdram, ctx);
        goto after_9;
    // 0x800DFA6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x800DFA70: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800DFA74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800DFA78: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800DFA7C: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x800DFA80: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x800DFA84: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800DFA88: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800DFA8C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800DFA90: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800DFA94: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800DFA98: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800DFA9C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800DFAA0: jal         0x800DE498
    // 0x800DFAA4: nop

    func_800DE498(rdram, ctx);
        goto after_10;
    // 0x800DFAA4: nop

    after_10:
    // 0x800DFAA8: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x800DFAAC: jal         0x800E4640
    // 0x800DFAB0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800E4640(rdram, ctx);
        goto after_11;
    // 0x800DFAB0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_11:
    // 0x800DFAB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DFAB8: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x800DFABC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800DFAC0: jr          $ra
    // 0x800DFAC4: nop

    return;
    // 0x800DFAC4: nop

    // 0x800DFAC8: nop

    // 0x800DFACC: nop

;}
RECOMP_FUNC void func_80800B38_bsstonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B38: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800B3C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800B40: sltiu       $at, $a1, 0x5
    ctx->r1 = ctx->r5 < 0X5 ? 1 : 0;
    // 0x80800B44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B48: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B4C: beq         $at, $zero, L_80800CFC
    if (ctx->r1 == 0) {
        // 0x80800B50: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_80800CFC;
    }
    // 0x80800B50: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800B54: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80800B58: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(376, 0X1614) << 16);
    // 0x80800B5C: addu        $at, $at, $t6
    gpr jr_addend_80800B64 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800B60: lw          $t6, 0x1614($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(376, 0X1614));
    // 0x80800B64: jr          $t6
    // 0x80800B68: nop

    switch (jr_addend_80800B64 >> 2) {
        case 0: goto L_80800B6C; break;
        case 1: goto L_80800B88; break;
        case 2: goto L_80800CBC; break;
        case 3: goto L_80800CD8; break;
        case 4: goto L_80800CF4; break;
        default: switch_error(__func__, 0x80800B64, 0x80801614);
    }
    // 0x80800B68: nop

L_80800B6C:
    // 0x80800B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B70: jal         0x8009B9B0
    // 0x80800B74: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_0;
    // 0x80800B74: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x80800B78: jal         0x8009BC6C
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_1;
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800B80: b           L_80800D00
    // 0x80800B84: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
        goto L_80800D00;
    // 0x80800B84: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
L_80800B88:
    // 0x80800B88: jal         0x8008CABC
    // 0x80800B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_2;
    // 0x80800B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800B90: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B98: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800B9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800BA0: jal         0x80084468
    // 0x80800BA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _baattach_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800BA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80800BA8: jal         0x8008AF24
    // 0x80800BAC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_reset(rdram, ctx);
        goto after_4;
    // 0x80800BAC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x80800BB0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800BB4: jal         0x8008AED4
    // 0x80800BB8: addiu       $a1, $zero, 0x122
    ctx->r5 = ADD32(0, 0X122);
    anctrl_setIndex(rdram, ctx);
        goto after_5;
    // 0x80800BB8: addiu       $a1, $zero, 0x122
    ctx->r5 = ADD32(0, 0X122);
    after_5:
    // 0x80800BBC: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800BC0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800BC4: jal         0x8008B1BC
    // 0x80800BC8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setDuration(rdram, ctx);
        goto after_6;
    // 0x80800BC8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x80800BCC: lui         $a2, 0x3F22
    ctx->r6 = S32(0X3F22 << 16);
    // 0x80800BD0: ori         $a2, $a2, 0xEB1C
    ctx->r6 = ctx->r6 | 0XEB1C;
    // 0x80800BD4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800BD8: jal         0x8008B1D4
    // 0x80800BDC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_7;
    // 0x80800BDC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_7:
    // 0x80800BE0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800BE4: jal         0x8008B134
    // 0x80800BE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x80800BE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800BEC: jal         0x8008B064
    // 0x80800BF0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x80800BF0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_9:
    // 0x80800BF4: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80800BF8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800C08: jal         0x8009FFD8
    // 0x80800C0C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_10;
    // 0x80800C0C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_10:
    // 0x80800C10: jal         0x8009EF04
    // 0x80800C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_11;
    // 0x80800C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800C18: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800C1C: nop

    // 0x80800C20: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800C24: nop

    // 0x80800C28: bc1t        L_80800C44
    if (c1cs) {
        // 0x80800C2C: nop
    
            goto L_80800C44;
    }
    // 0x80800C2C: nop

    // 0x80800C30: jal         0x8009EEB8
    // 0x80800C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_12;
    // 0x80800C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800C38: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800C3C: jal         0x8009C914
    // 0x80800C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_13;
    // 0x80800C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
L_80800C44:
    // 0x80800C44: jal         0x8009C990
    // 0x80800C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_14;
    // 0x80800C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800C4C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800C50: jal         0x8009B9C0
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_15;
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800C58: jal         0x808000CC
    // 0x80800C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000CC_bsstonehead(rdram, ctx);
        goto after_16;
    // 0x80800C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800C60: jal         0x8009C990
    // 0x80800C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_17;
    // 0x80800C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800C68: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800C6C: jal         0x8009BB00
    // 0x80800C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x80800C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800C74: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C7C: jal         0x8009BA68
    // 0x80800C80: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_19;
    // 0x80800C80: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_19:
    // 0x80800C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C88: jal         0x8009BA58
    // 0x80800C8C: lui         $a1, 0x4410
    ctx->r5 = S32(0X4410 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_20;
    // 0x80800C8C: lui         $a1, 0x4410
    ctx->r5 = S32(0X4410 << 16);
    after_20:
    // 0x80800C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C94: jal         0x8009BCB4
    // 0x80800C98: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_21;
    // 0x80800C98: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_21:
    // 0x80800C9C: lui         $a1, 0x3FAC
    ctx->r5 = S32(0X3FAC << 16);
    // 0x80800CA0: lui         $a2, 0x3FB9
    ctx->r6 = S32(0X3FB9 << 16);
    // 0x80800CA4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800CA8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800CAC: jal         0x8009D7A4
    // 0x80800CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D7A4(rdram, ctx);
        goto after_22;
    // 0x80800CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800CB4: b           L_80800D00
    // 0x80800CB8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
        goto L_80800D00;
    // 0x80800CB8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
L_80800CBC:
    // 0x80800CBC: lui         $a1, 0x3F41
    ctx->r5 = S32(0X3F41 << 16);
    // 0x80800CC0: ori         $a1, $a1, 0xF213
    ctx->r5 = ctx->r5 | 0XF213;
    // 0x80800CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CC8: jal         0x8008CF1C
    // 0x80800CCC: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_23;
    // 0x80800CCC: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_23:
    // 0x80800CD0: b           L_80800D00
    // 0x80800CD4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
        goto L_80800D00;
    // 0x80800CD4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
L_80800CD8:
    // 0x80800CD8: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800CDC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CE4: jal         0x8008CF1C
    // 0x80800CE8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_24;
    // 0x80800CE8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_24:
    // 0x80800CEC: b           L_80800D00
    // 0x80800CF0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
        goto L_80800D00;
    // 0x80800CF0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
L_80800CF4:
    // 0x80800CF4: jal         0x800A2E18
    // 0x80800CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2E18(rdram, ctx);
        goto after_25;
    // 0x80800CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
L_80800CFC:
    // 0x80800CFC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
L_80800D00:
    // 0x80800D00: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
    // 0x80800D04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800D08: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800D0C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800D10: jr          $ra
    // 0x80800D14: nop

    return;
    // 0x80800D14: nop

;}
RECOMP_FUNC void _chpickups_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085860: syscall     177
    recomp_syscall_handler(rdram, ctx, 0x80085860);
    return;
    // 0x80085864: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800560_chmusicmenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800564: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800568: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080056C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800570: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800574: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800578: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x8080057C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800580: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1824, 0X14F4) << 16);
    // 0x80800584: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80800588: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8080058C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800590: bc1f        L_808005B8
    if (!c1cs) {
        // 0x80800594: lw          $v0, 0x14F4($v0)
        ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(1824, 0X14F4));
            goto L_808005B8;
    }
    // 0x80800594: lw          $v0, 0x14F4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(1824, 0X14F4));
    // 0x80800598: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x8080059C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808005A0: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x808005A4: lh          $a0, 0x0($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X0);
    // 0x808005A8: jal         0x800FC660
    // 0x808005AC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800FC660(rdram, ctx);
        goto after_0;
    // 0x808005AC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x808005B0: b           L_808005DC
    // 0x808005B4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
        goto L_808005DC;
    // 0x808005B4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_808005B8:
    // 0x808005B8: lw          $t1, 0x18($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X18);
    // 0x808005BC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808005C0: addiu       $a2, $zero, 0x14D
    ctx->r6 = ADD32(0, 0X14D);
    // 0x808005C4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x808005C8: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x808005CC: lh          $a0, 0x0($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X0);
    // 0x808005D0: jal         0x800FCAE0
    // 0x808005D4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800FCAE0(rdram, ctx);
        goto after_1;
    // 0x808005D4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x808005D8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_808005DC:
    // 0x808005DC: lbu         $t4, 0x74($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X74);
    // 0x808005E0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808005E4: andi        $t6, $t4, 0xFFBF
    ctx->r14 = ctx->r12 & 0XFFBF;
    // 0x808005E8: sb          $t6, 0x74($a3)
    MEM_B(0X74, ctx->r7) = ctx->r14;
    // 0x808005EC: andi        $t7, $t6, 0xDF
    ctx->r15 = ctx->r14 & 0XDF;
    // 0x808005F0: sb          $t7, 0x74($a3)
    MEM_B(0X74, ctx->r7) = ctx->r15;
    // 0x808005F4: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808005F8: jal         0x80800400
    // 0x808005FC: swc1        $f8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f8.u32l;
    func_80800400_chmusicmenu(rdram, ctx);
        goto after_2;
    // 0x808005FC: swc1        $f8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f8.u32l;
    after_2:
    // 0x80800600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800604: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800608: jr          $ra
    // 0x8080060C: nop

    return;
    // 0x8080060C: nop

;}
RECOMP_FUNC void baswim_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001C0: jal         0x808001D8
    // 0x808001C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    baswim_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808001C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808001C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001D0: jr          $ra
    // 0x808001D4: nop

    return;
    // 0x808001D4: nop

;}
RECOMP_FUNC void func_80800898_chmrsicecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800898: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080089C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008A0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1204, 0XAB8) << 16);
    // 0x808008A4: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808008A8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808008AC: addiu       $a2, $a2, 0xAB8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1204, 0XAB8));
    // 0x808008B0: jal         0x80089D20
    // 0x808008B4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808008B4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x808008B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008C0: jr          $ra
    // 0x808008C4: nop

    return;
    // 0x808008C4: nop

    // 0x808008C8: nop

    // 0x808008CC: nop

;}
RECOMP_FUNC void func_80801AEC_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801AF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801AF4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801AF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801AFC: jal         0x8008CABC
    // 0x80801B00: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80801B00: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x80801B04: lui         $a1, 0x3E0B
    ctx->r5 = S32(0X3E0B << 16);
    // 0x80801B08: ori         $a1, $a1, 0xF28
    ctx->r5 = ctx->r5 | 0XF28;
    // 0x80801B0C: jal         0x8008B348
    // 0x80801B10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x80801B10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801B14: beq         $v0, $zero, L_80801B44
    if (ctx->r2 == 0) {
        // 0x80801B18: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B44;
    }
    // 0x80801B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B1C: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80801B20: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x80801B24: addiu       $t6, $zero, 0x2710
    ctx->r14 = ADD32(0, 0X2710);
    // 0x80801B28: addiu       $t7, $zero, 0x2EE0
    ctx->r15 = ADD32(0, 0X2EE0);
    // 0x80801B2C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801B30: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801B34: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80801B38: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801B3C: jal         0x8009DEC0
    // 0x80801B40: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    func_8009DEC0(rdram, ctx);
        goto after_2;
    // 0x80801B40: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    after_2:
L_80801B44:
    // 0x80801B44: jal         0x8009CC68
    // 0x80801B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009CC68(rdram, ctx);
        goto after_3;
    // 0x80801B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801B4C: bne         $v0, $zero, L_80801B58
    if (ctx->r2 != 0) {
        // 0x80801B50: addiu       $t8, $zero, 0x24
        ctx->r24 = ADD32(0, 0X24);
            goto L_80801B58;
    }
    // 0x80801B50: addiu       $t8, $zero, 0x24
    ctx->r24 = ADD32(0, 0X24);
    // 0x80801B54: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_80801B58:
    // 0x80801B58: jal         0x800A0024
    // 0x80801B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0024(rdram, ctx);
        goto after_4;
    // 0x80801B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B64: jal         0x8009E5C8
    // 0x80801B68: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_5;
    // 0x80801B68: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80801B6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801B70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801B74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801B78: jr          $ra
    // 0x80801B7C: nop

    return;
    // 0x80801B7C: nop

;}
RECOMP_FUNC void bamovespline_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080071C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800720: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800724: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800728: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8080072C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800730: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800734: lbu         $v0, 0x90($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X90);
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080073C: beq         $v0, $at, L_8080075C
    if (ctx->r2 == ctx->r1) {
        // 0x80800740: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080075C;
    }
    // 0x80800740: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800744: beq         $v0, $at, L_80800798
    if (ctx->r2 == ctx->r1) {
        // 0x80800748: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800798;
    }
    // 0x80800748: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080074C: beq         $v0, $at, L_808007A8
    if (ctx->r2 == ctx->r1) {
        // 0x80800750: nop
    
            goto L_808007A8;
    }
    // 0x80800750: nop

    // 0x80800754: b           L_808007B4
    // 0x80800758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007B4;
    // 0x80800758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080075C:
    // 0x8080075C: jal         0x8009C128
    // 0x80800760: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800760: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80800764: lw          $t7, 0xC8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC8);
    // 0x80800768: jal         0x800D7520
    // 0x8080076C: lh          $a0, 0x94($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X94);
    func_800D7520(rdram, ctx);
        goto after_1;
    // 0x8080076C: lh          $a0, 0x94($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X94);
    after_1:
    // 0x80800770: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800774: jal         0x800C82CC
    // 0x80800778: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800C82CC(rdram, ctx);
        goto after_2;
    // 0x80800778: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x8080077C: lw          $t8, 0xC8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC8);
    // 0x80800780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800784: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800788: jal         0x808000F4
    // 0x8080078C: swc1        $f0, 0x98($t8)
    MEM_W(0X98, ctx->r24) = ctx->f0.u32l;
    func_808000F4_bamovespline(rdram, ctx);
        goto after_3;
    // 0x8080078C: swc1        $f0, 0x98($t8)
    MEM_W(0X98, ctx->r24) = ctx->f0.u32l;
    after_3:
    // 0x80800790: b           L_808007B4
    // 0x80800794: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007B4;
    // 0x80800794: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800798:
    // 0x80800798: jal         0x80800374
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800374_bamovespline(rdram, ctx);
        goto after_4;
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808007A0: b           L_808007B4
    // 0x808007A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007B4;
    // 0x808007A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007A8:
    // 0x808007A8: jal         0x8080057C
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080057C_bamovespline(rdram, ctx);
        goto after_5;
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808007B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007B4:
    // 0x808007B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808007BC: jr          $ra
    // 0x808007C0: nop

    return;
    // 0x808007C0: nop

    // 0x808007C4: nop

    // 0x808007C8: nop

    // 0x808007CC: nop

;}
RECOMP_FUNC void func_800932BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800932BC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800932C0: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x800932C4: jr          $ra
    // 0x800932C8: swc1        $f12, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x800932C8: swc1        $f12, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void _chdumbwaiterlift_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086310: syscall     306
    recomp_syscall_handler(rdram, ctx, 0x80086310);
    return;
    // 0x80086314: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chbilldrillboulder_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1908, 0X5D0) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x5D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1908, 0X5D0));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x5D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1908, 0X5D0));
;}
RECOMP_FUNC void func_80800E94_chamazongoldhordeofficial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E94: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800E98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800EA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800EA4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800EA8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1860, 0X11D0) << 16);
    // 0x80800EAC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1860, 0X1368) << 16);
    // 0x80800EB0: addiu       $a3, $a3, 0x1368
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1860, 0X1368));
    // 0x80800EB4: addiu       $a2, $a2, 0x11D0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1860, 0X11D0));
    // 0x80800EB8: jal         0x80089D28
    // 0x80800EBC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800EBC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EC4: jal         0x80101E14
    // 0x80800EC8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101E14(rdram, ctx);
        goto after_1;
    // 0x80800EC8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_1:
    // 0x80800ECC: beq         $v0, $zero, L_80800F2C
    if (ctx->r2 == 0) {
        // 0x80800ED0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F2C;
    }
    // 0x80800ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ED4: jal         0x80100094
    // 0x80800ED8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800ED8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800EDC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800EE0: lbu         $t6, 0x68($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X68);
    // 0x80800EE4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800EE8: jal         0x80088848
    // 0x80800EEC: sb          $t7, 0x68($v0)
    MEM_B(0X68, ctx->r2) = ctx->r15;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80800EEC: sb          $t7, 0x68($v0)
    MEM_B(0X68, ctx->r2) = ctx->r15;
    after_3:
    // 0x80800EF0: beq         $v0, $zero, L_80800F00
    if (ctx->r2 == 0) {
        // 0x80800EF4: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_80800F00;
    }
    // 0x80800EF4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80800EF8: b           L_80800F04
    // 0x80800EFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800EFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F00:
    // 0x80800F00: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80800F04:
    // 0x80800F04: lbu         $t9, 0x68($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X68);
    // 0x80800F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F0C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800F10: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80800F14: beq         $at, $zero, L_80800F2C
    if (ctx->r1 == 0) {
        // 0x80800F18: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1860, 0X1380) << 16);
            goto L_80800F2C;
    }
    // 0x80800F18: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1860, 0X1380) << 16);
    // 0x80800F1C: jal         0x80089D18
    // 0x80800F20: addiu       $a2, $a2, 0x1380
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1860, 0X1380));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800F20: addiu       $a2, $a2, 0x1380
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1860, 0X1380));
    after_4:
    // 0x80800F24: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F28: sb          $zero, 0x68($t0)
    MEM_B(0X68, ctx->r8) = 0;
L_80800F2C:
    // 0x80800F2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F34: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800F38: jr          $ra
    // 0x80800F3C: nop

    return;
    // 0x80800F3C: nop

;}
RECOMP_FUNC void _bsclimb_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082EE8: syscall     34
    recomp_syscall_handler(rdram, ctx, 0x80082EE8);
    return;
    // 0x80082EEC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _badrone_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084800: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084800);
    return;
    // 0x80084804: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800034_bscrouch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080003C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800040: addiu       $a1, $zero, 0x116
    ctx->r5 = ADD32(0, 0X116);
    // 0x80800044: jal         0x8008CCBC
    // 0x80800048: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_0;
    // 0x80800048: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_0:
    // 0x8080004C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800050: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800054: sw          $t6, 0x15C($t7)
    MEM_W(0X15C, ctx->r15) = ctx->r14;
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void func_808012C8_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012D0: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808012D4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808012D8: slti        $at, $t6, 0xB
    ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
    // 0x808012DC: beq         $at, $zero, L_808013B4
    if (ctx->r1 == 0) {
        // 0x808012E0: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_808013B4;
    }
    // 0x808012E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808012E4: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x808012E8: bnel        $at, $zero, L_8080130C
    if (ctx->r1 != 0) {
        // 0x808012EC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8080130C;
    }
    goto skip_0;
    // 0x808012EC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_0:
    // 0x808012F0: jal         0x80800E64
    // 0x808012F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800E64_chboilerboss(rdram, ctx);
        goto after_0;
    // 0x808012F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808012F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808012FC: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80801300: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x80801304: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80801308: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
L_8080130C:
    // 0x8080130C: beq         $v0, $at, L_808013B4
    if (ctx->r2 == ctx->r1) {
        // 0x80801310: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_808013B4;
    }
    // 0x80801310: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80801314: beq         $v0, $at, L_808013B4
    if (ctx->r2 == ctx->r1) {
        // 0x80801318: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_808013B4;
    }
    // 0x80801318: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8080131C: beql        $v0, $at, L_808013B8
    if (ctx->r2 == ctx->r1) {
        // 0x80801320: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808013B8;
    }
    goto skip_1;
    // 0x80801320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80801324: lbu         $v1, 0x5E($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X5E);
    // 0x80801328: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x8080132C: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80801330: beql        $at, $zero, L_808013B8
    if (ctx->r1 == 0) {
        // 0x80801334: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808013B8;
    }
    goto skip_2;
    // 0x80801334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80801338: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8080133C: sw          $v1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r3;
    // 0x80801340: slti        $at, $v1, 0x29
    ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
    // 0x80801344: lw          $v0, 0x28($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X28);
    // 0x80801348: sll         $t1, $v0, 18
    ctx->r9 = S32(ctx->r2 << 18);
    // 0x8080134C: bgez        $t1, L_8080136C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80801350: sll         $t4, $v0, 19
        ctx->r12 = S32(ctx->r2 << 19);
            goto L_8080136C;
    }
    // 0x80801350: sll         $t4, $v0, 19
    ctx->r12 = S32(ctx->r2 << 19);
    // 0x80801354: beq         $at, $zero, L_8080136C
    if (ctx->r1 == 0) {
        // 0x80801358: nop
    
            goto L_8080136C;
    }
    // 0x80801358: nop

    // 0x8080135C: jal         0x80800F34
    // 0x80801360: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_1;
    // 0x80801360: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x80801364: b           L_808013B8
    // 0x80801368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808013B8;
    // 0x80801368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080136C:
    // 0x8080136C: bgez        $t4, L_80801394
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80801370: sll         $t7, $v0, 20
        ctx->r15 = S32(ctx->r2 << 20);
            goto L_80801394;
    }
    // 0x80801370: sll         $t7, $v0, 20
    ctx->r15 = S32(ctx->r2 << 20);
    // 0x80801374: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x80801378: slti        $at, $t5, 0x1F
    ctx->r1 = SIGNED(ctx->r13) < 0X1F ? 1 : 0;
    // 0x8080137C: beq         $at, $zero, L_80801394
    if (ctx->r1 == 0) {
        // 0x80801380: nop
    
            goto L_80801394;
    }
    // 0x80801380: nop

    // 0x80801384: jal         0x80800F34
    // 0x80801388: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_2;
    // 0x80801388: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x8080138C: b           L_808013B8
    // 0x80801390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808013B8;
    // 0x80801390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801394:
    // 0x80801394: bgezl       $t7, L_808013B8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80801398: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808013B8;
    }
    goto skip_3;
    // 0x80801398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8080139C: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x808013A0: slti        $at, $t8, 0x10
    ctx->r1 = SIGNED(ctx->r24) < 0X10 ? 1 : 0;
    // 0x808013A4: beql        $at, $zero, L_808013B8
    if (ctx->r1 == 0) {
        // 0x808013A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808013B8;
    }
    goto skip_4;
    // 0x808013A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x808013AC: jal         0x80800F34
    // 0x808013B0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_3;
    // 0x808013B0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_3:
L_808013B4:
    // 0x808013B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808013B8:
    // 0x808013B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808013BC: jr          $ra
    // 0x808013C0: nop

    return;
    // 0x808013C0: nop

;}
RECOMP_FUNC void func_80804158_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804158: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x8080415C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80804160: addu        $v0, $s0, $t6
    ctx->r2 = ADD32(ctx->r16, ctx->r14);
    // 0x80804164: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80804168: lwc1        $f10, 0xD8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x8080416C: sll         $t0, $a1, 1
    ctx->r8 = S32(ctx->r5 << 1);
    // 0x80804170: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x80804174: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80804178: nop

    // 0x8080417C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80804180: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80804184: swc1        $f16, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f16.u32l;
    // 0x80804188: lwc1        $f0, 0xD8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x8080418C: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80804190: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80804194: nop

    // 0x80804198: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    // 0x8080419C: bne         $at, $zero, L_808041CC
    if (ctx->r1 != 0) {
        // 0x808041A0: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_808041CC;
    }
    // 0x808041A0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x808041A4: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x808041A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808041AC: nop

    // 0x808041B0: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x808041B4: swc1        $f6, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f6.u32l;
    // 0x808041B8: lwc1        $f10, 0xD8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x808041BC: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808041C0: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x808041C4: b           L_808041F8
    // 0x808041C8: sh          $v1, 0xE0($t1)
    MEM_H(0XE0, ctx->r9) = ctx->r3;
        goto L_808041F8;
    // 0x808041C8: sh          $v1, 0xE0($t1)
    MEM_H(0XE0, ctx->r9) = ctx->r3;
L_808041CC:
    // 0x808041CC: bgez        $a0, L_808041F4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x808041D0: lui         $at, 0x4600
        ctx->r1 = S32(0X4600 << 16);
            goto L_808041F4;
    }
    // 0x808041D0: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x808041D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808041D8: nop

    // 0x808041DC: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x808041E0: swc1        $f18, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f18.u32l;
    // 0x808041E4: lwc1        $f4, 0xD8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x808041E8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808041EC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x808041F0: nop

L_808041F4:
    // 0x808041F4: sh          $v1, 0xE0($t1)
    MEM_H(0XE0, ctx->r9) = ctx->r3;
L_808041F8:
    // 0x808041F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1732, 0X477C) << 16);
    // 0x808041FC: lwc1        $f10, 0x477C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1732, 0X477C));
    // 0x80804200: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1732, 0X4780) << 16);
    // 0x80804204: lwc1        $f18, 0x4780($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1732, 0X4780));
    // 0x80804208: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8080420C: lwc1        $f6, 0xD0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XD0);
    // 0x80804210: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80804214: nop

    // 0x80804218: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080421C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80804220: swc1        $f10, 0xD0($v0)
    MEM_W(0XD0, ctx->r2) = ctx->f10.u32l;
    // 0x80804224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804228: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080422C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80804230: jr          $ra
    // 0x80804234: nop

    return;
    // 0x80804234: nop

;}
RECOMP_FUNC void glzone_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80800068: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // 0x8080006C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800070: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800074: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80800078: beq         $at, $zero, L_8080008C
    if (ctx->r1 == 0) {
        // 0x8080007C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8080008C;
    }
L_8080007C:
    // 0x8080007C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800080: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80800084: bne         $at, $zero, L_8080007C
    if (ctx->r1 != 0) {
        // 0x80800088: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_8080007C;
    }
    // 0x80800088: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_8080008C:
    // 0x8080008C: jr          $ra
    // 0x80800090: nop

    return;
    // 0x80800090: nop

;}
RECOMP_FUNC void _badata_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084658: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084658);
    return;
    // 0x8008465C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80111A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111A38: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80111A3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80111A40: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80111A44: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80111A48: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80111A4C: jal         0x80112550
    // 0x80111A50: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80112550(rdram, ctx);
        goto after_0;
    // 0x80111A50: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80111A54: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80111A58: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80111A5C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80111A60: lw          $v0, 0x34($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X34);
    // 0x80111A64: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80111A68: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80111A6C: addiu       $t7, $v0, 0x38
    ctx->r15 = ADD32(ctx->r2, 0X38);
    // 0x80111A70: addiu       $a3, $v0, 0x24
    ctx->r7 = ADD32(ctx->r2, 0X24);
    // 0x80111A74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80111A78: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80111A7C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80111A80: jal         0x80111680
    // 0x80111A84: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80111680(rdram, ctx);
        goto after_1;
    // 0x80111A84: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80111A88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80111A8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80111A90: jr          $ra
    // 0x80111A94: nop

    return;
    // 0x80111A94: nop

;}
RECOMP_FUNC void sucoaster_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080000C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800010: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800014: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800018: addiu       $a2, $a3, 0x1C
    ctx->r6 = ADD32(ctx->r7, 0X1C);
    // 0x8080001C: jal         0x80100074
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800024: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800028: jal         0x8008A238
    // 0x8080002C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _sucoasterdata_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080002C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800030: lbu         $t9, 0x18($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X18);
    // 0x80800034: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x80800038: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080003C: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x80800040: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800044: jal         0x80089F48
    // 0x80800048: sb          $t1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r9;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800048: sb          $t1, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r9;
    after_2:
    // 0x8080004C: sb          $v0, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r2;
    // 0x80800050: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800054: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800058: jal         0x80089F70
    // 0x8080005C: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x8080005C: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    after_3:
    // 0x80800060: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800064: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800068: jal         0x80802130
    // 0x8080006C: addiu       $a2, $zero, 0x190
    ctx->r6 = ADD32(0, 0X190);
    func_80802130_sucoaster(rdram, ctx);
        goto after_4;
    // 0x8080006C: addiu       $a2, $zero, 0x190
    ctx->r6 = ADD32(0, 0X190);
    after_4:
    // 0x80800070: lbu         $t3, 0x19($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X19);
    // 0x80800074: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x80800078: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080007C: ori         $t6, $t3, 0x80
    ctx->r14 = ctx->r11 | 0X80;
    // 0x80800080: sb          $t6, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r14;
    // 0x80800084: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x80800088: sb          $t7, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r15;
    // 0x8080008C: lwc1        $f4, 0x38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800090: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800094: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800098: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080009C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x808000A0: jal         0x80107200
    // 0x808000A4: sh          $t8, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r24;
    func_80107200(rdram, ctx);
        goto after_5;
    // 0x808000A4: sh          $t8, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r24;
    after_5:
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000B8: jr          $ra
    // 0x808000BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808000BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void _baeggcursor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084AB0: syscall     128
    recomp_syscall_handler(rdram, ctx, 0x80084AB0);
    return;
    // 0x80084AB4: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_800A8D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8D00: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A8D04: addiu       $v0, $v0, 0x7670
    ctx->r2 = ADD32(ctx->r2, 0X7670);
    // 0x800A8D08: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x800A8D0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A8D10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A8D14: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800A8D18: bne         $a0, $t7, L_800A8D30
    if (ctx->r4 != ctx->r15) {
        // 0x800A8D1C: nop
    
            goto L_800A8D30;
    }
    // 0x800A8D1C: nop

    // 0x800A8D20: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x800A8D24: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800A8D28: beql        $a1, $t9, L_800A8D60
    if (ctx->r5 == ctx->r25) {
        // 0x800A8D2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A8D60;
    }
    goto skip_0;
    // 0x800A8D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_800A8D30:
    // 0x800A8D30: bgez        $a0, L_800A8D40
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800A8D34: sra         $t0, $a0, 1
        ctx->r8 = S32(SIGNED(ctx->r4) >> 1);
            goto L_800A8D40;
    }
    // 0x800A8D34: sra         $t0, $a0, 1
    ctx->r8 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800A8D38: addiu       $at, $a0, 0x1
    ctx->r1 = ADD32(ctx->r4, 0X1);
    // 0x800A8D3C: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_800A8D40:
    // 0x800A8D40: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
    // 0x800A8D44: bgez        $a1, L_800A8D54
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800A8D48: sra         $t1, $a1, 1
        ctx->r9 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800A8D54;
    }
    // 0x800A8D48: sra         $t1, $a1, 1
    ctx->r9 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800A8D4C: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x800A8D50: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_800A8D54:
    // 0x800A8D54: jal         0x800A85A8
    // 0x800A8D58: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    func_800A85A8(rdram, ctx);
        goto after_0;
    // 0x800A8D58: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    after_0:
    // 0x800A8D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A8D60:
    // 0x800A8D60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A8D64: jr          $ra
    // 0x800A8D68: nop

    return;
    // 0x800A8D68: nop

    // 0x800A8D6C: nop

;}
RECOMP_FUNC void func_80800000_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080000C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80800010: jal         0x800856B0
    // 0x80800014: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800014: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080001C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800020: jr          $ra
    // 0x80800024: nop

    return;
    // 0x80800024: nop

;}
RECOMP_FUNC void func_80800B9C_chbilldrillplate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B9C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800BA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BA4: jal         0x800EA05C
    // 0x80800BA8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800BA8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800BAC: addiu       $at, $zero, 0x101
    ctx->r1 = ADD32(0, 0X101);
    // 0x80800BB0: beq         $v0, $at, L_80800BC8
    if (ctx->r2 == ctx->r1) {
        // 0x80800BB4: addiu       $at, $zero, 0x107
        ctx->r1 = ADD32(0, 0X107);
            goto L_80800BC8;
    }
    // 0x80800BB4: addiu       $at, $zero, 0x107
    ctx->r1 = ADD32(0, 0X107);
    // 0x80800BB8: beql        $v0, $at, L_80800C30
    if (ctx->r2 == ctx->r1) {
        // 0x80800BBC: lui         $at, 0x4302
        ctx->r1 = S32(0X4302 << 16);
            goto L_80800C30;
    }
    goto skip_0;
    // 0x80800BBC: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    skip_0:
    // 0x80800BC0: b           L_80800C8C
    // 0x80800BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C8C;
    // 0x80800BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BC8:
    // 0x80800BC8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800BCC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800BD0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800BD4: lui         $a2, 0x442A
    ctx->r6 = S32(0X442A << 16);
    // 0x80800BD8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800BDC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800BE0: jal         0x800EFA4C
    // 0x80800BE4: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x80800BE4: nop

    after_1:
    // 0x80800BE8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800BEC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800BF0: jal         0x800EF04C
    // 0x80800BF4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x80800BF4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x80800BF8: jal         0x80101010
    // 0x80800BFC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_80101010(rdram, ctx);
        goto after_3;
    // 0x80800BFC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80800C00: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    // 0x80800C04: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800C08: jal         0x80101180
    // 0x80800C0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_4;
    // 0x80800C0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800C10: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1192, 0X1220) << 16);
    // 0x80800C14: addiu       $a2, $a2, 0x1220
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1192, 0X1220));
    // 0x80800C18: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800C1C: jal         0x80089D18
    // 0x80800C20: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800C20: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x80800C24: b           L_80800C8C
    // 0x80800C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C8C;
    // 0x80800C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C2C: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
L_80800C30:
    // 0x80800C30: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800C34: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80800C38: lui         $a2, 0x435C
    ctx->r6 = S32(0X435C << 16);
    // 0x80800C3C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800C40: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800C44: jal         0x800EFA4C
    // 0x80800C48: nop

    func_800EFA4C(rdram, ctx);
        goto after_6;
    // 0x80800C48: nop

    after_6:
    // 0x80800C4C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800C50: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80800C54: jal         0x800EF04C
    // 0x80800C58: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x80800C58: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_7:
    // 0x80800C5C: jal         0x80101010
    // 0x80800C60: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_80101010(rdram, ctx);
        goto after_8;
    // 0x80800C60: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_8:
    // 0x80800C64: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    // 0x80800C68: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800C6C: jal         0x80101180
    // 0x80800C70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_9;
    // 0x80800C70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80800C74: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1192, 0X1220) << 16);
    // 0x80800C78: addiu       $a2, $a2, 0x1220
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1192, 0X1220));
    // 0x80800C7C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800C80: jal         0x80089D18
    // 0x80800C84: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800C84: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_10:
    // 0x80800C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C8C:
    // 0x80800C8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800C90: jr          $ra
    // 0x80800C94: nop

    return;
    // 0x80800C94: nop

;}
RECOMP_FUNC void func_80098538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098538: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009853C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80098540: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80098544: lw          $a0, 0xE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE0);
    // 0x80098548: jal         0x800EFD24
    // 0x8009854C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x8009854C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80098550: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80098554: lw          $a0, 0xE0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XE0);
    // 0x80098558: jal         0x800EFD24
    // 0x8009855C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x8009855C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_1:
    // 0x80098560: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80098564: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80098568: lw          $t6, 0xE0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XE0);
    // 0x8009856C: sb          $zero, 0x2C($t6)
    MEM_B(0X2C, ctx->r14) = 0;
    // 0x80098570: lw          $t7, 0xE0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XE0);
    // 0x80098574: swc1        $f4, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f4.u32l;
    // 0x80098578: lw          $t8, 0xE0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XE0);
    // 0x8009857C: sb          $zero, 0x2F($t8)
    MEM_B(0X2F, ctx->r24) = 0;
    // 0x80098580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80098588: jr          $ra
    // 0x8009858C: nop

    return;
    // 0x8009858C: nop

;}
RECOMP_FUNC void bstrexsmall_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005E4: lbu         $a1, 0x160($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X160);
    // 0x808005E8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808005EC: beql        $a1, $zero, L_80800674
    if (ctx->r5 == 0) {
        // 0x808005F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800674;
    }
    goto skip_0;
    // 0x808005F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808005F4: lbu         $t6, 0x15E($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X15E);
    // 0x808005F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808005FC: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80800600: bnel        $t6, $at, L_80800674
    if (ctx->r14 != ctx->r1) {
        // 0x80800604: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800674;
    }
    goto skip_1;
    // 0x80800604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800608: jal         0x800C3920
    // 0x8080060C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800C3920(rdram, ctx);
        goto after_0;
    // 0x8080060C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800610: jal         0x800D8FF8
    // 0x80800614: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800614: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800618: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8080061C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(416, 0X1AD0) << 16);
    // 0x80800620: lwc1        $f8, 0x1AD0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(416, 0X1AD0));
    // 0x80800624: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800628: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080062C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800630: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800634: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80800638: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8080063C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800640: jal         0x800F0E28
    // 0x80800644: nop

    func_800F0E28(rdram, ctx);
        goto after_2;
    // 0x80800644: nop

    after_2:
    // 0x80800648: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8080064C: beq         $v0, $zero, L_80800664
    if (ctx->r2 == 0) {
        // 0x80800650: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800664;
    }
    // 0x80800650: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800654: jal         0x800C3058
    // 0x80800658: lbu         $a0, 0x160($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X160);
    func_800C3058(rdram, ctx);
        goto after_3;
    // 0x80800658: lbu         $a0, 0x160($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X160);
    after_3:
    // 0x8080065C: b           L_80800674
    // 0x80800660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800674;
    // 0x80800660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800664:
    // 0x80800664: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800668: jal         0x808000C8
    // 0x8080066C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808000C8_bstrexsmall(rdram, ctx);
        goto after_4;
    // 0x8080066C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800674:
    // 0x80800674: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800678: jr          $ra
    // 0x8080067C: nop

    return;
    // 0x8080067C: nop

;}
RECOMP_FUNC void func_80800F60_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800F68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F6C: beq         $a2, $at, L_80800FF8
    if (ctx->r6 == ctx->r1) {
        // 0x80800F70: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80800FF8;
    }
    // 0x80800F70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800F74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800F78: beq         $a2, $at, L_80800F98
    if (ctx->r6 == ctx->r1) {
        // 0x80800F7C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800F98;
    }
    // 0x80800F7C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800F80: beq         $a2, $at, L_80800FF8
    if (ctx->r6 == ctx->r1) {
        // 0x80800F84: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80800FF8;
    }
    // 0x80800F84: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800F88: beql        $a2, $at, L_80800FBC
    if (ctx->r6 == ctx->r1) {
        // 0x80800F8C: lbu         $t7, 0x15C($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X15C);
            goto L_80800FBC;
    }
    goto skip_0;
    // 0x80800F8C: lbu         $t7, 0x15C($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X15C);
    skip_0:
    // 0x80800F90: b           L_80800FFC
    // 0x80800F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800FFC;
    // 0x80800F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F98:
    // 0x80800F98: lbu         $t6, 0x15C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X15C);
    // 0x80800F9C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800FA0: bnel        $t6, $at, L_80800FFC
    if (ctx->r14 != ctx->r1) {
        // 0x80800FA4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800FFC;
    }
    goto skip_1;
    // 0x80800FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800FA8: jal         0x80800A50
    // 0x80800FAC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_0;
    // 0x80800FAC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80800FB0: b           L_80800FFC
    // 0x80800FB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800FFC;
    // 0x80800FB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FB8: lbu         $t7, 0x15C($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X15C);
L_80800FBC:
    // 0x80800FBC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800FC0: bnel        $t7, $at, L_80800FFC
    if (ctx->r15 != ctx->r1) {
        // 0x80800FC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800FFC;
    }
    goto skip_2;
    // 0x80800FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80800FC8: lhu         $t8, 0x15E($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X15E);
    // 0x80800FCC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800FD0: srl         $t9, $t8, 15
    ctx->r25 = S32(U32(ctx->r24) >> 15);
    // 0x80800FD4: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80800FD8: lbu         $t1, 0x11C($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X11C);
    // 0x80800FDC: srl         $t2, $t1, 6
    ctx->r10 = S32(U32(ctx->r9) >> 6);
    // 0x80800FE0: beq         $t2, $zero, L_80800FF0
    if (ctx->r10 == 0) {
        // 0x80800FE4: nop
    
            goto L_80800FF0;
    }
    // 0x80800FE4: nop

    // 0x80800FE8: b           L_80800FF0
    // 0x80800FEC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
        goto L_80800FF0;
    // 0x80800FEC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_80800FF0:
    // 0x80800FF0: jal         0x80800A50
    // 0x80800FF4: nop

    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_1;
    // 0x80800FF4: nop

    after_1:
L_80800FF8:
    // 0x80800FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800FFC:
    // 0x80800FFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801000: jr          $ra
    // 0x80801004: nop

    return;
    // 0x80801004: nop

;}
RECOMP_FUNC void func_80800264_chnewmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800264: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800268: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080026C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800270: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800274: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800278: jal         0x80100094
    // 0x8080027C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080027C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800280: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800284: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800288: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080028C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800290: bne         $t7, $at, L_808002A8
    if (ctx->r15 != ctx->r1) {
        // 0x80800294: addiu       $a0, $zero, 0x9C6
        ctx->r4 = ADD32(0, 0X9C6);
            goto L_808002A8;
    }
    // 0x80800294: addiu       $a0, $zero, 0x9C6
    ctx->r4 = ADD32(0, 0X9C6);
    // 0x80800298: lbu         $t8, 0x77($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X77);
    // 0x8080029C: andi        $t9, $t8, 0xFFF0
    ctx->r25 = ctx->r24 & 0XFFF0;
    // 0x808002A0: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x808002A4: sb          $t0, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r8;
L_808002A8:
    // 0x808002A8: jal         0x800DA298
    // 0x808002AC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808002AC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x808002B0: beq         $v0, $zero, L_808004D4
    if (ctx->r2 == 0) {
        // 0x808002B4: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_808004D4;
    }
    // 0x808002B4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808002C0: jal         0x80102424
    // 0x808002C4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x808002C4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x808002C8: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    // 0x808002CC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808002D0: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x808002D4: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x808002D8: sltiu       $at, $t3, 0x13
    ctx->r1 = ctx->r11 < 0X13 ? 1 : 0;
    // 0x808002DC: beq         $at, $zero, L_808004D4
    if (ctx->r1 == 0) {
        // 0x808002E0: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_808004D4;
    }
    // 0x808002E0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x808002E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1584, 0X1880) << 16);
    // 0x808002E8: addu        $at, $at, $t3
    gpr jr_addend_808002F0 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x808002EC: lw          $t3, 0x1880($at)
    ctx->r11 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1584, 0X1880));
    // 0x808002F0: jr          $t3
    // 0x808002F4: nop

    switch (jr_addend_808002F0 >> 2) {
        case 0: goto L_808002F8; break;
        case 1: goto L_80800308; break;
        case 2: goto L_80800308; break;
        case 3: goto L_80800308; break;
        case 4: goto L_80800318; break;
        case 5: goto L_80800344; break;
        case 6: goto L_80800388; break;
        case 7: goto L_808003F4; break;
        case 8: goto L_808004D4; break;
        case 9: goto L_808004C0; break;
        case 10: goto L_808004C0; break;
        case 11: goto L_808004D4; break;
        case 12: goto L_808004D4; break;
        case 13: goto L_8080045C; break;
        case 14: goto L_808004D4; break;
        case 15: goto L_808004D4; break;
        case 16: goto L_808004D4; break;
        case 17: goto L_80800430; break;
        case 18: goto L_8080044C; break;
        default: switch_error(__func__, 0x808002F0, 0x80801880);
    }
    // 0x808002F4: nop

L_808002F8:
    // 0x808002F8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808002FC: sb          $t4, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r12;
    // 0x80800300: b           L_808004D4
    // 0x80800304: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
        goto L_808004D4;
    // 0x80800304: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
L_80800308:
    // 0x80800308: jal         0x80800210
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800210_chnewmumbo(rdram, ctx);
        goto after_3;
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800310: b           L_808004D8
    // 0x80800314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004D8;
    // 0x80800314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800318:
    // 0x80800318: jal         0x80090178
    // 0x8080031C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090178(rdram, ctx);
        goto after_4;
    // 0x8080031C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800324: jal         0x8080073C
    // 0x80800328: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8080073C_chnewmumbo(rdram, ctx);
        goto after_5;
    // 0x80800328: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800330: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800334: jal         0x80800000
    // 0x80800338: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800000_chnewmumbo(rdram, ctx);
        goto after_6;
    // 0x80800338: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8080033C: b           L_808004D8
    // 0x80800340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004D8;
    // 0x80800340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800344:
    // 0x80800344: lbu         $t5, 0x77($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X77);
    // 0x80800348: lbu         $t8, 0x7A($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X7A);
    // 0x8080034C: lhu         $t4, 0x6E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800350: andi        $t6, $t5, 0xFFF0
    ctx->r14 = ctx->r13 & 0XFFF0;
    // 0x80800354: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80800358: sb          $t7, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r15;
    // 0x8080035C: lbu         $t7, 0x71($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X71);
    // 0x80800360: andi        $t9, $t8, 0xFFF1
    ctx->r25 = ctx->r24 & 0XFFF1;
    // 0x80800364: ori         $t2, $t9, 0x6
    ctx->r10 = ctx->r25 | 0X6;
    // 0x80800368: sb          $t2, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r10;
    // 0x8080036C: ori         $t3, $t2, 0x30
    ctx->r11 = ctx->r10 | 0X30;
    // 0x80800370: andi        $t5, $t4, 0xFE00
    ctx->r13 = ctx->r12 & 0XFE00;
    // 0x80800374: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x80800378: sb          $t3, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r11;
    // 0x8080037C: sh          $t5, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r13;
    // 0x80800380: b           L_808004D4
    // 0x80800384: sb          $t8, 0x71($s0)
    MEM_B(0X71, ctx->r16) = ctx->r24;
        goto L_808004D4;
    // 0x80800384: sb          $t8, 0x71($s0)
    MEM_B(0X71, ctx->r16) = ctx->r24;
L_80800388:
    // 0x80800388: lbu         $t9, 0x77($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X77);
    // 0x8080038C: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    // 0x80800390: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800394: andi        $t0, $t9, 0xFFF0
    ctx->r8 = ctx->r25 & 0XFFF0;
    // 0x80800398: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8080039C: jal         0x800DA9E4
    // 0x808003A0: sb          $t1, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r9;
    func_800DA9E4(rdram, ctx);
        goto after_7;
    // 0x808003A0: sb          $t1, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r9;
    after_7:
    // 0x808003A4: bne         $v0, $zero, L_808003C4
    if (ctx->r2 != 0) {
        // 0x808003A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003C4;
    }
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B0: addiu       $a1, $zero, 0x11D6
    ctx->r5 = ADD32(0, 0X11D6);
    // 0x808003B4: jal         0x808000DC
    // 0x808003B8: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_808000DC_chnewmumbo(rdram, ctx);
        goto after_8;
    // 0x808003B8: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_8:
    // 0x808003BC: b           L_808003D4
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808003D4;
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003C4:
    // 0x808003C4: addiu       $a1, $zero, 0x11E4
    ctx->r5 = ADD32(0, 0X11E4);
    // 0x808003C8: jal         0x808000DC
    // 0x808003CC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_808000DC_chnewmumbo(rdram, ctx);
        goto after_9;
    // 0x808003CC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_9:
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003D4:
    // 0x808003D4: jal         0x80100094
    // 0x808003D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_10;
    // 0x808003D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808003DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003E0: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x808003E4: jal         0x800897E8
    // 0x808003E8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_11;
    // 0x808003E8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_11:
    // 0x808003EC: b           L_808004D8
    // 0x808003F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004D8;
    // 0x808003F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003F4:
    // 0x808003F4: jal         0x800D1A04
    // 0x808003F8: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    func_800D1A04(rdram, ctx);
        goto after_12;
    // 0x808003F8: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_12:
    // 0x808003FC: blez        $v0, L_8080041C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800400: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080041C;
    }
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800408: addiu       $a1, $zero, 0x11D7
    ctx->r5 = ADD32(0, 0X11D7);
    // 0x8080040C: jal         0x808000DC
    // 0x80800410: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_808000DC_chnewmumbo(rdram, ctx);
        goto after_13;
    // 0x80800410: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_13:
    // 0x80800414: b           L_808004D8
    // 0x80800418: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004D8;
    // 0x80800418: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080041C:
    // 0x8080041C: addiu       $a1, $zero, 0x11DA
    ctx->r5 = ADD32(0, 0X11DA);
    // 0x80800420: jal         0x808000DC
    // 0x80800424: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_808000DC_chnewmumbo(rdram, ctx);
        goto after_14;
    // 0x80800424: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_14:
    // 0x80800428: b           L_808004D8
    // 0x8080042C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004D8;
    // 0x8080042C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800430:
    // 0x80800430: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1584, 0X19F4) << 16);
    // 0x80800434: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x80800438: addiu       $a1, $a1, 0x19F4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1584, 0X19F4));
    // 0x8080043C: jal         0x800EE7F8
    // 0x80800440: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x80800440: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_15:
    // 0x80800444: b           L_808004D8
    // 0x80800448: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004D8;
    // 0x80800448: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080044C:
    // 0x8080044C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800450: sb          $t2, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r10;
    // 0x80800454: b           L_808004D4
    // 0x80800458: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
        goto L_808004D4;
    // 0x80800458: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
L_8080045C:
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800460: jal         0x8080009C
    // 0x80800464: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8080009C_chnewmumbo(rdram, ctx);
        goto after_16;
    // 0x80800464: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_16:
    // 0x80800468: jal         0x800904C8
    // 0x8080046C: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    func_800904C8(rdram, ctx);
        goto after_17;
    // 0x8080046C: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_17:
    // 0x80800470: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x80800474: jal         0x80090590
    // 0x80800478: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_80090590(rdram, ctx);
        goto after_18;
    // 0x80800478: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_18:
    // 0x8080047C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800480: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800484: addiu       $a0, $zero, 0x429
    ctx->r4 = ADD32(0, 0X429);
    // 0x80800488: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080048C: jal         0x800DA9E4
    // 0x80800490: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    func_800DA9E4(rdram, ctx);
        goto after_19;
    // 0x80800490: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    after_19:
    // 0x80800494: bne         $v0, $zero, L_808004D4
    if (ctx->r2 != 0) {
        // 0x80800498: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004D4;
    }
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080049C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808004A0: jal         0x80800000
    // 0x808004A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800000_chnewmumbo(rdram, ctx);
        goto after_20;
    // 0x808004A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_20:
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004AC: addiu       $a1, $zero, 0x11E6
    ctx->r5 = ADD32(0, 0X11E6);
    // 0x808004B0: jal         0x808000DC
    // 0x808004B4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_808000DC_chnewmumbo(rdram, ctx);
        goto after_21;
    // 0x808004B4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_21:
    // 0x808004B8: b           L_808004D8
    // 0x808004BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004D8;
    // 0x808004BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004C0:
    // 0x808004C0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808004C4: sb          $t4, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r12;
    // 0x808004C8: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x808004CC: jal         0x8080009C
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chnewmumbo(rdram, ctx);
        goto after_22;
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
L_808004D4:
    // 0x808004D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004D8:
    // 0x808004D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004E0: jr          $ra
    // 0x808004E4: nop

    return;
    // 0x808004E4: nop

;}
RECOMP_FUNC void dblight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080000C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800010: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80800014: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80800018: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8080001C: bne         $v0, $t6, L_8080003C
    if (ctx->r2 != ctx->r14) {
        // 0x80800020: or          $s1, $a0, $zero
        ctx->r17 = ctx->r4 | 0;
            goto L_8080003C;
    }
    // 0x80800020: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800024: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x80800028: bnel        $v0, $t7, L_80800040
    if (ctx->r2 != ctx->r15) {
        // 0x8080002C: lhu         $t9, 0x10($s1)
        ctx->r25 = MEM_HU(ctx->r17, 0X10);
            goto L_80800040;
    }
    goto skip_0;
    // 0x8080002C: lhu         $t9, 0x10($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X10);
    skip_0:
    // 0x80800030: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x80800034: beql        $v0, $t8, L_808000C4
    if (ctx->r2 == ctx->r24) {
        // 0x80800038: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000C4;
    }
    goto skip_1;
    // 0x80800038: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_8080003C:
    // 0x8080003C: lhu         $t9, 0x10($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X10);
L_80800040:
    // 0x80800040: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800044: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80800048: addu        $t0, $t2, $s1
    ctx->r8 = ADD32(ctx->r10, ctx->r17);
    // 0x8080004C: addiu       $t0, $t0, 0x18
    ctx->r8 = ADD32(ctx->r8, 0X18);
    // 0x80800050: jal         0x800B2190
    // 0x80800054: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_800B2190(rdram, ctx);
        goto after_0;
    // 0x80800054: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_0:
    // 0x80800058: lw          $t3, 0x14($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X14);
    // 0x8080005C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800060: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80800064: blez        $t3, L_808000C0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80800068: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_808000C0;
    }
    // 0x80800068: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080006C: lh          $t4, 0x0($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X0);
L_80800070:
    // 0x80800070: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800074: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800078: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8080007C: addu        $v1, $t5, $v0
    ctx->r3 = ADD32(ctx->r13, ctx->r2);
L_80800080:
    // 0x80800080: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80800084: lbu         $t7, 0xC($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XC);
    // 0x80800088: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8080008C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800090: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800094: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800098: mflo        $t8
    ctx->r24 = lo;
    // 0x8080009C: sra         $t9, $t8, 8
    ctx->r25 = S32(SIGNED(ctx->r24) >> 8);
    // 0x808000A0: bne         $a0, $a2, L_80800080
    if (ctx->r4 != ctx->r6) {
        // 0x808000A4: sb          $t9, 0xB($v1)
        MEM_B(0XB, ctx->r3) = ctx->r25;
            goto L_80800080;
    }
    // 0x808000A4: sb          $t9, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r25;
    // 0x808000A8: lw          $t2, 0x14($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X14);
    // 0x808000AC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x808000B0: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x808000B4: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x808000B8: bnel        $at, $zero, L_80800070
    if (ctx->r1 != 0) {
        // 0x808000BC: lh          $t4, 0x0($t0)
        ctx->r12 = MEM_H(ctx->r8, 0X0);
            goto L_80800070;
    }
    goto skip_2;
    // 0x808000BC: lh          $t4, 0x0($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X0);
    skip_2:
L_808000C0:
    // 0x808000C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000C4:
    // 0x808000C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000CC: jr          $ra
    // 0x808000D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808000D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _chfantasyeyeball_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800876D0: syscall     608
    recomp_syscall_handler(rdram, ctx, 0x800876D0);
    return;
    // 0x800876D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bashake_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080009C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808000A0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808000A4: jal         0x8009C128
    // 0x808000A8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x808000A8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x808000AC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808000B0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x808000B4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(588, 0X100) << 16);
    // 0x808000B8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x808000BC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x808000C0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808000C4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(588, 0X13C) << 16);
    // 0x808000C8: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x808000CC: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x808000D0: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x808000D4: lw          $a1, 0x100($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(588, 0X100));
    // 0x808000D8: lw          $a2, 0x13C($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(588, 0X13C));
    // 0x808000DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000E0: jal         0x800E1610
    // 0x808000E4: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    func_800E1610(rdram, ctx);
        goto after_1;
    // 0x808000E4: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x808000E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000F0: jr          $ra
    // 0x808000F4: nop

    return;
    // 0x808000F4: nop

    // 0x808000F8: nop

    // 0x808000FC: nop

;}
RECOMP_FUNC void func_800E9E4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9E4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9E50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9E54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E9E58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800E9E5C: jal         0x800B4290
    // 0x800E9E60: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800B4290(rdram, ctx);
        goto after_0;
    // 0x800E9E60: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x800E9E64: jal         0x800B4290
    // 0x800E9E68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800B4290(rdram, ctx);
        goto after_1;
    // 0x800E9E68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800E9E6C: jal         0x800BE5C4
    // 0x800E9E70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800BE5C4(rdram, ctx);
        goto after_2;
    // 0x800E9E70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800E9E74: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800E9E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9E7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9E80: jr          $ra
    // 0x800E9E84: nop

    return;
    // 0x800E9E84: nop

;}
