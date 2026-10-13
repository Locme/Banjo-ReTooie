#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bainvisible_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080074C: lwc1        $f12, 0x10($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80800750: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800754: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800758: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8080075C: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x80800760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800764: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x80800768: andi        $t7, $a1, 0x2
    ctx->r15 = ctx->r5 & 0X2;
    // 0x8080076C: bc1t        L_8080077C
    if (c1cs) {
        // 0x80800770: nop
    
            goto L_8080077C;
    }
    // 0x80800770: nop

    // 0x80800774: b           L_8080077C
    // 0x80800778: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080077C;
    // 0x80800778: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080077C:
    // 0x8080077C: beq         $t6, $zero, L_808007A0
    if (ctx->r14 == 0) {
        // 0x80800780: nop
    
            goto L_808007A0;
    }
    // 0x80800780: nop

    // 0x80800784: lw          $v1, 0xA8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XA8);
    // 0x80800788: sb          $v0, 0x38($v1)
    MEM_B(0X38, ctx->r3) = ctx->r2;
    // 0x8080078C: swc1        $f12, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f12.u32l;
    // 0x80800790: swc1        $f14, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f14.u32l;
    // 0x80800794: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80800798: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8080079C: swc1        $f6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f6.u32l;
L_808007A0:
    // 0x808007A0: beq         $t7, $zero, L_808007C4
    if (ctx->r15 == 0) {
        // 0x808007A4: nop
    
            goto L_808007C4;
    }
    // 0x808007A4: nop

    // 0x808007A8: lw          $v1, 0xA8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XA8);
    // 0x808007AC: sb          $v0, 0x68($v1)
    MEM_B(0X68, ctx->r3) = ctx->r2;
    // 0x808007B0: swc1        $f12, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f12.u32l;
    // 0x808007B4: swc1        $f14, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f14.u32l;
    // 0x808007B8: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x808007BC: addiu       $v1, $v1, 0x4C
    ctx->r3 = ADD32(ctx->r3, 0X4C);
    // 0x808007C0: swc1        $f8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f8.u32l;
L_808007C4:
    // 0x808007C4: jr          $ra
    // 0x808007C8: nop

    return;
    // 0x808007C8: nop

;}
RECOMP_FUNC void func_800C6A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6A08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C6A0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C6A10: jal         0x800C6A28
    // 0x800C6A14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C6A28(rdram, ctx);
        goto after_0;
    // 0x800C6A14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800C6A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C6A1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C6A20: jr          $ra
    // 0x800C6A24: nop

    return;
    // 0x800C6A24: nop

;}
RECOMP_FUNC void func_800E0050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0050: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800E0054: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800E0058: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800E005C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800E0060: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800E0064: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800E0068: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800E006C: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x800E0070: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800E0074: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x800E0078: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800E007C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800E0080: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800E0084: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800E0088: jal         0x800E0414
    // 0x800E008C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800E0414(rdram, ctx);
        goto after_0;
    // 0x800E008C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x800E0090: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800E0094: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E0098: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800E009C: swc1        $f2, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->f2.u32l;
    // 0x800E00A0: swc1        $f2, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->f2.u32l;
    // 0x800E00A4: swc1        $f2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f2.u32l;
    // 0x800E00A8: swc1        $f2, 0x20($s4)
    MEM_W(0X20, ctx->r20) = ctx->f2.u32l;
    // 0x800E00AC: swc1        $f2, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = ctx->f2.u32l;
    // 0x800E00B0: swc1        $f2, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->f2.u32l;
    // 0x800E00B4: swc1        $f12, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->f12.u32l;
    // 0x800E00B8: swc1        $f12, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->f12.u32l;
    // 0x800E00BC: swc1        $f12, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->f12.u32l;
    // 0x800E00C0: lh          $v1, 0x4($s5)
    ctx->r3 = MEM_H(ctx->r21, 0X4);
    // 0x800E00C4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800E00C8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800E00CC: addiu       $s1, $s5, 0x8
    ctx->r17 = ADD32(ctx->r21, 0X8);
    // 0x800E00D0: blez        $v1, L_800E0144
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800E00D4: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800E0144;
    }
    // 0x800E00D4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800E00D8:
    // 0x800E00D8: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800E00DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E00E0: srl         $t6, $v0, 4
    ctx->r14 = S32(U32(ctx->r2) >> 4);
    // 0x800E00E4: beq         $s6, $t6, L_800E00FC
    if (ctx->r22 == ctx->r14) {
        // 0x800E00E8: andi        $s0, $v0, 0xF
        ctx->r16 = ctx->r2 & 0XF;
            goto L_800E00FC;
    }
    // 0x800E00E8: andi        $s0, $v0, 0xF
    ctx->r16 = ctx->r2 & 0XF;
    // 0x800E00EC: beql        $s3, $zero, L_800E012C
    if (ctx->r19 == 0) {
        // 0x800E00F0: lh          $t9, 0x2($s1)
        ctx->r25 = MEM_H(ctx->r17, 0X2);
            goto L_800E012C;
    }
    goto skip_0;
    // 0x800E00F0: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
    skip_0:
    // 0x800E00F4: b           L_800E0148
    // 0x800E00F8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800E0148;
    // 0x800E00F8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800E00FC:
    // 0x800E00FC: slti        $at, $s0, 0x9
    ctx->r1 = SIGNED(ctx->r16) < 0X9 ? 1 : 0;
    // 0x800E0100: bne         $at, $zero, L_800E010C
    if (ctx->r1 != 0) {
        // 0x800E0104: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_800E010C;
    }
    // 0x800E0104: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800E0108: addiu       $s0, $s0, -0x9
    ctx->r16 = ADD32(ctx->r16, -0X9);
L_800E010C:
    // 0x800E010C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800E0110: jal         0x800E04C0
    // 0x800E0114: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800E04C0(rdram, ctx);
        goto after_1;
    // 0x800E0114: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800E0118: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x800E011C: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x800E0120: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    // 0x800E0124: lh          $v1, 0x4($s5)
    ctx->r3 = MEM_H(ctx->r21, 0X4);
    // 0x800E0128: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
L_800E012C:
    // 0x800E012C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800E0130: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800E0134: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800E0138: addu        $s1, $s1, $t0
    ctx->r17 = ADD32(ctx->r17, ctx->r8);
    // 0x800E013C: bne         $at, $zero, L_800E00D8
    if (ctx->r1 != 0) {
        // 0x800E0140: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800E00D8;
    }
    // 0x800E0140: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800E0144:
    // 0x800E0144: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800E0148:
    // 0x800E0148: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800E014C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800E0150: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800E0154: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800E0158: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800E015C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800E0160: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800E0164: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800E0168: jr          $ra
    // 0x800E016C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800E016C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _chminelobbydoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087378: syscall     557
    recomp_syscall_handler(rdram, ctx, 0x80087378);
    return;
    // 0x8008737C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _glsplinefuncs_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088478: syscall     686
    recomp_syscall_handler(rdram, ctx, 0x80088478);
    return;
    // 0x8008847C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800B3C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3C40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B3C44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B3C48: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B3C4C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800B3C50: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800B3C54: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x800B3C58: lh          $v0, 0x2($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X2);
    // 0x800B3C5C: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x800B3C60: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800B3C64: addu        $v1, $v0, $a2
    ctx->r3 = ADD32(ctx->r2, ctx->r6);
    // 0x800B3C68: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3C6C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x800B3C70: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800B3C74: mflo        $a1
    ctx->r5 = lo;
    // 0x800B3C78: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800B3C7C: jal         0x8001B208
    // 0x800B3C80: nop

    heap_realloc(rdram, ctx);
        goto after_0;
    // 0x800B3C80: nop

    after_0:
    // 0x800B3C84: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800B3C88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B3C8C: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x800B3C90: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800B3C94: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x800B3C98: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800B3C9C: jal         0x800B39D0
    // 0x800B3CA0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800B39D0(rdram, ctx);
        goto after_1;
    // 0x800B3CA0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x800B3CA4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B3CA8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3CAC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B3CB0: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x800B3CB4: jal         0x800B39D0
    // 0x800B3CB8: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    func_800B39D0(rdram, ctx);
        goto after_2;
    // 0x800B3CB8: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    after_2:
    // 0x800B3CBC: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800B3CC0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800B3CC4: sh          $t1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r9;
    // 0x800B3CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3CCC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3CD0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B3CD4: jr          $ra
    // 0x800B3CD8: nop

    return;
    // 0x800B3CD8: nop

;}
RECOMP_FUNC void _bstnt_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083FA0: syscall     99
    recomp_syscall_handler(rdram, ctx, 0x80083FA0);
    return;
    // 0x80083FA4: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _bswasher_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800843D0: syscall     109
    recomp_syscall_handler(rdram, ctx, 0x800843D0);
    return;
    // 0x800843D4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _chfactoryliftdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800861F8: syscall     289
    recomp_syscall_handler(rdram, ctx, 0x800861F8);
    return;
    // 0x800861FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bafly_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800578: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080057C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800580: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800584: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800588: jal         0x8009EF34
    // 0x8080058C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    bastick_getY(rdram, ctx);
        goto after_0;
    // 0x8080058C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800590: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800594: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800598: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080059C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808005A0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808005A4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808005A8: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808005AC: bc1fl       L_808005E8
    if (!c1cs) {
        // 0x808005B0: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_808005E8;
    }
    goto skip_0;
    // 0x808005B0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_0:
    // 0x808005B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808005B8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808005BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005C0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808005C4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x808005C8: jal         0x800F10B4
    // 0x808005CC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x808005CC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x808005D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005D4: jal         0x8009BF5C
    // 0x808005D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8009BF5C(rdram, ctx);
        goto after_2;
    // 0x808005D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808005DC: b           L_80800600
    // 0x808005E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800600;
    // 0x808005E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005E4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_808005E8:
    // 0x808005E8: jal         0x800F10B4
    // 0x808005EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x808005EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x808005F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005F4: jal         0x8009BF5C
    // 0x808005F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8009BF5C(rdram, ctx);
        goto after_4;
    // 0x808005F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808005FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800600:
    // 0x80800600: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800604: jr          $ra
    // 0x80800608: nop

    return;
    // 0x80800608: nop

;}
RECOMP_FUNC void bsdronelook_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080020C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800210: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800214: jal         0x80099B94
    // 0x80800218: nop

    func_80099B94(rdram, ctx);
        goto after_0;
    // 0x80800218: nop

    after_0:
    // 0x8080021C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800224: jr          $ra
    // 0x80800228: nop

    return;
    // 0x80800228: nop

    // 0x8080022C: nop

;}
RECOMP_FUNC void func_8008D1B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D1B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D1B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D1B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D1BC: jal         0x800C6E38
    // 0x8008D1C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D1C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x8008D1C4: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D1C8: beq         $t6, $zero, L_8008D1E0
    if (ctx->r14 == 0) {
        // 0x8008D1CC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D1E0;
    }
    // 0x8008D1CC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D1D0: jal         0x800A3304
    // 0x8008D1D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3304(rdram, ctx);
        goto after_1;
    // 0x8008D1D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008D1D8: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D1DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008D1E0:
    // 0x8008D1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D1E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D1E8: jr          $ra
    // 0x8008D1EC: nop

    return;
    // 0x8008D1EC: nop

;}
RECOMP_FUNC void func_8010A6B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A6B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8010A6B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010A6B8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8010A6BC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8010A6C0: jal         0x800F4B4C
    // 0x8010A6C4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800F4B4C(rdram, ctx);
        goto after_0;
    // 0x8010A6C4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8010A6C8: bne         $v0, $zero, L_8010A6D8
    if (ctx->r2 != 0) {
        // 0x8010A6CC: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_8010A6D8;
    }
    // 0x8010A6CC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8010A6D0: b           L_8010A718
    // 0x8010A6D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010A718;
    // 0x8010A6D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010A6D8:
    // 0x8010A6D8: jal         0x800F57F0
    // 0x8010A6DC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F57F0(rdram, ctx);
        goto after_1;
    // 0x8010A6DC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x8010A6E0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8010A6E4: jal         0x80103DFC
    // 0x8010A6E8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80103DFC(rdram, ctx);
        goto after_2;
    // 0x8010A6E8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x8010A6EC: lui         $a3, 0x4A
    ctx->r7 = S32(0X4A << 16);
    // 0x8010A6F0: ori         $a3, $a3, 0x21
    ctx->r7 = ctx->r7 | 0X21;
    // 0x8010A6F4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8010A6F8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8010A6FC: jal         0x800C6A7C
    // 0x8010A700: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800C6A7C(rdram, ctx);
        goto after_3;
    // 0x8010A700: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x8010A704: beql        $v0, $zero, L_8010A718
    if (ctx->r2 == 0) {
        // 0x8010A708: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8010A718;
    }
    goto skip_0;
    // 0x8010A708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8010A70C: b           L_8010A718
    // 0x8010A710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010A718;
    // 0x8010A710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010A714: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010A718:
    // 0x8010A718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010A71C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8010A720: jr          $ra
    // 0x8010A724: nop

    return;
    // 0x8010A724: nop

    // 0x8010A728: nop

    // 0x8010A72C: nop

;}
RECOMP_FUNC void _bsdronejump_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800830F0: syscall     44
    recomp_syscall_handler(rdram, ctx, 0x800830F0);
    return;
    // 0x800830F4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _gsworldDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B68: syscall     726
    recomp_syscall_handler(rdram, ctx, 0x80088B68);
    return;
    // 0x80088B6C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void sumumbofx_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C60: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80800C64: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(3146, 0X14D0) << 16);
    // 0x80800C68: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80800C6C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80800C70: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80800C74: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80800C78: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80800C7C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80800C80: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800C84: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800C88: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800C8C: addiu       $t7, $t7, 0x14D0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(3146, 0X14D0));
    // 0x80800C90: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800C94: addiu       $t6, $sp, 0x74
    ctx->r14 = ADD32(ctx->r29, 0X74);
    // 0x80800C98: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80800C9C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800CA0: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800CA4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800CA8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80800CAC: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80800CB0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800CB4: sb          $t1, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r9;
    // 0x80800CB8: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80800CBC: jal         0x800D674C
    // 0x80800CC0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x80800CC0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80800CC4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800CC8: jal         0x800E2588
    // 0x80800CCC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800E2588(rdram, ctx);
        goto after_1;
    // 0x80800CCC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80800CD0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800CD4: jal         0x800E2594
    // 0x80800CD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800E2594(rdram, ctx);
        goto after_2;
    // 0x80800CD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80800CDC: jal         0x800E24D8
    // 0x80800CE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E24D8(rdram, ctx);
        goto after_3;
    // 0x80800CE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800CE4: lh          $v1, 0x58($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X58);
    // 0x80800CE8: addiu       $s0, $s3, 0x64
    ctx->r16 = ADD32(ctx->r19, 0X64);
    // 0x80800CEC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800CF0: blez        $v1, L_80800D7C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80800CF4: lui         $at, 0x4300
        ctx->r1 = S32(0X4300 << 16);
            goto L_80800D7C;
    }
    // 0x80800CF4: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80800CF8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800CFC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80800D00: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800D04: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X14B8) << 16);
    // 0x80800D08: lwc1        $f20, 0x14B8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X14B8));
    // 0x80800D0C: addiu       $s2, $sp, 0x68
    ctx->r18 = ADD32(ctx->r29, 0X68);
L_80800D10:
    // 0x80800D10: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800D14: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80800D18: nop

    // 0x80800D1C: bc1fl       L_80800D70
    if (!c1cs) {
        // 0x80800D20: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800D70;
    }
    goto skip_0;
    // 0x80800D20: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80800D24: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800D28: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800D2C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800D30: jal         0x800EFA4C
    // 0x80800D34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80800D34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x80800D38: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80800D3C: lwc1        $f4, 0x4($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80800D40: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800D44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800D48: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80800D4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800D50: addiu       $a3, $s0, 0x10
    ctx->r7 = ADD32(ctx->r16, 0X10);
    // 0x80800D54: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x80800D58: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800D5C: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80800D60: jal         0x800E2720
    // 0x80800D64: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    func_800E2720(rdram, ctx);
        goto after_5;
    // 0x80800D64: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_5:
    // 0x80800D68: lh          $v1, 0x58($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X58);
    // 0x80800D6C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800D70:
    // 0x80800D70: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800D74: bne         $at, $zero, L_80800D10
    if (ctx->r1 != 0) {
        // 0x80800D78: addiu       $s0, $s0, 0x2C
        ctx->r16 = ADD32(ctx->r16, 0X2C);
            goto L_80800D10;
    }
    // 0x80800D78: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
L_80800D7C:
    // 0x80800D7C: jal         0x800E2A14
    // 0x80800D80: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800E2A14(rdram, ctx);
        goto after_6;
    // 0x80800D80: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x80800D84: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80800D88: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800D8C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800D90: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800D94: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80800D98: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80800D9C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80800DA0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80800DA4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80800DA8: jr          $ra
    // 0x80800DAC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80800DAC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void _chbigtopticket_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086278: syscall     296
    recomp_syscall_handler(rdram, ctx, 0x80086278);
    return;
    // 0x8008627C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chfactoryroofbits_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800834: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2280, 0XAEC) << 16);
    // 0x80800838: jr          $ra
    // 0x8080083C: addiu       $v0, $v0, 0xAEC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2280, 0XAEC));
    return;
    // 0x8080083C: addiu       $v0, $v0, 0xAEC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2280, 0XAEC));
;}
RECOMP_FUNC void func_80800D00_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D00: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800D04: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800D08: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80800D0C: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80800D10: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800D14: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800D18: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800D1C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800D20: jal         0x80100094
    // 0x80800D24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D28: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800D2C: jal         0x80088368
    // 0x80800D30: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800D30: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_1:
    // 0x80800D34: blez        $v0, L_80800DBC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800D38: lw          $t6, 0x4C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X4C);
            goto L_80800DBC;
    }
    // 0x80800D38: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80800D3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1308, 0X2184) << 16);
    // 0x80800D40: lwc1        $f26, 0x2184($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1308, 0X2184));
    // 0x80800D44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800D48: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800D4C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80800D50: subu        $t7, $t7, $s1
    ctx->r15 = SUB32(ctx->r15, ctx->r17);
    // 0x80800D54: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800D58: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800D5C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800D60: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800D64: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80800D68: lw          $t8, 0x48($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X48);
L_80800D6C:
    // 0x80800D6C: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x80800D70: lw          $t1, 0x44($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X44);
    // 0x80800D74: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800D78: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80800D7C: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80800D80: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800D84: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800D88: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x80800D8C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80800D90: jal         0x800F10B4
    // 0x80800D94: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800D94: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_2:
    // 0x80800D98: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800D9C: jal         0x800F849C
    // 0x80800DA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F849C(rdram, ctx);
        goto after_3;
    // 0x80800DA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80800DA4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800DA8: jal         0x80088368
    // 0x80800DAC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800DAC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    after_4:
    // 0x80800DB0: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800DB4: bnel        $at, $zero, L_80800D6C
    if (ctx->r1 != 0) {
        // 0x80800DB8: lw          $t8, 0x48($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X48);
            goto L_80800D6C;
    }
    goto skip_0;
    // 0x80800DB8: lw          $t8, 0x48($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X48);
    skip_0:
L_80800DBC:
    // 0x80800DBC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800DC0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800DC4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800DC8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800DCC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800DD0: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x80800DD4: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80800DD8: jr          $ra
    // 0x80800DDC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800DDC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void chseaweedbaddy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1024, 0XEB4) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xEB4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1024, 0XEB4));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xEB4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1024, 0XEB4));
;}
RECOMP_FUNC void _bskazshock_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083560: syscall     66
    recomp_syscall_handler(rdram, ctx, 0x80083560);
    return;
    // 0x80083564: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808008B4_chdinofamilysmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808008B8: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x808008BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008C0: sltiu       $at, $t7, 0xA
    ctx->r1 = ctx->r15 < 0XA ? 1 : 0;
    // 0x808008C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008CC: beq         $at, $zero, L_80800AD4
    if (ctx->r1 == 0) {
        // 0x808008D0: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_80800AD4;
    }
    // 0x808008D0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x808008D4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808008D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2404, 0XE68) << 16);
    // 0x808008DC: addu        $at, $at, $t7
    gpr jr_addend_808008E4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808008E0: lw          $t7, 0xE68($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2404, 0XE68));
    // 0x808008E4: jr          $t7
    // 0x808008E8: nop

    switch (jr_addend_808008E4 >> 2) {
        case 0: goto L_808008EC; break;
        case 1: goto L_80800AD4; break;
        case 2: goto L_808008FC; break;
        case 3: goto L_808009B8; break;
        case 4: goto L_808009E0; break;
        case 5: goto L_80800A00; break;
        case 6: goto L_80800A44; break;
        case 7: goto L_80800A84; break;
        case 8: goto L_80800AC4; break;
        case 9: goto L_80800AC4; break;
        default: switch_error(__func__, 0x808008E4, 0x80800E68);
    }
    // 0x808008E8: nop

L_808008EC:
    // 0x808008EC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808008F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808008F4: b           L_80800AD4
    // 0x808008F8: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
        goto L_80800AD4;
    // 0x808008F8: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
L_808008FC:
    // 0x808008FC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80800900: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80800904: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80800908: jal         0x80086C68
    // 0x8080090C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    _chmumbopad_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080090C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // 0x80800910: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x80800914: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80800918: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8080091C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800920: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800924: jal         0x80089840
    // 0x80800928: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    _sumumbofx_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800928: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_1:
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800930: jal         0x80100094
    // 0x80800934: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800934: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800938: jal         0x80089850
    // 0x8080093C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x8080093C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800944: jal         0x80100094
    // 0x80800948: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800948: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8080094C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800950: addiu       $a1, $zero, 0x7D
    ctx->r5 = ADD32(0, 0X7D);
    // 0x80800954: jal         0x80089908
    // 0x80800958: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _sumumbofx_entrypoint_25(rdram, ctx);
        goto after_5;
    // 0x80800958: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800960: jal         0x80100094
    // 0x80800964: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_6;
    // 0x80800964: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800968: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8080096C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800970: jal         0x80089900
    // 0x80800974: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_24(rdram, ctx);
        goto after_7;
    // 0x80800974: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080097C: jal         0x80100094
    // 0x80800980: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_8;
    // 0x80800980: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800984: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800988: jal         0x800898B8
    // 0x8080098C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_15(rdram, ctx);
        goto after_9;
    // 0x8080098C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_9:
    // 0x80800990: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800994: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800998: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x8080099C: jal         0x80085708
    // 0x808009A0: addiu       $a3, $zero, 0x210
    ctx->r7 = ADD32(0, 0X210);
    _capod_entrypoint_13(rdram, ctx);
        goto after_10;
    // 0x808009A0: addiu       $a3, $zero, 0x210
    ctx->r7 = ADD32(0, 0X210);
    after_10:
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009A8: jal         0x8010A800
    // 0x808009AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_11;
    // 0x808009AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x808009B0: b           L_80800AD8
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800AD8;
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808009B8:
    // 0x808009B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009BC: jal         0x80100094
    // 0x808009C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_12;
    // 0x808009C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x808009C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009C8: jal         0x800898D0
    // 0x808009CC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _sumumbofx_entrypoint_18(rdram, ctx);
        goto after_13;
    // 0x808009CC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_13:
    // 0x808009D0: jal         0x80086AF0
    // 0x808009D4: nop

    _chglowbo_entrypoint_6(rdram, ctx);
        goto after_14;
    // 0x808009D4: nop

    after_14:
    // 0x808009D8: b           L_80800AD8
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800AD8;
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808009E0:
    // 0x808009E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009E4: jal         0x80100094
    // 0x808009E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_15;
    // 0x808009E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x808009EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009F0: jal         0x800898C8
    // 0x808009F4: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_16;
    // 0x808009F4: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_16:
    // 0x808009F8: b           L_80800AD8
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800AD8;
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A00:
    // 0x80800A00: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A0C: andi        $t1, $t9, 0xFFF7
    ctx->r9 = ctx->r25 & 0XFFF7;
    // 0x80800A10: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80800A14: andi        $t2, $t1, 0xEF
    ctx->r10 = ctx->r9 & 0XEF;
    // 0x80800A18: jal         0x80100094
    // 0x80800A1C: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    func_80100094(rdram, ctx);
        goto after_17;
    // 0x80800A1C: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    after_17:
    // 0x80800A20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A24: jal         0x800898E0
    // 0x80800A28: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    _sumumbofx_entrypoint_20(rdram, ctx);
        goto after_18;
    // 0x80800A28: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_18:
    // 0x80800A2C: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800A30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800A34: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800A38: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800A3C: b           L_80800AD4
    // 0x80800A40: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
        goto L_80800AD4;
    // 0x80800A40: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_80800A44:
    // 0x80800A44: lbu         $t3, 0x74($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X74);
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A50: andi        $t4, $t3, 0xFFBF
    ctx->r12 = ctx->r11 & 0XFFBF;
    // 0x80800A54: jal         0x80100094
    // 0x80800A58: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
    func_80100094(rdram, ctx);
        goto after_19;
    // 0x80800A58: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
    after_19:
    // 0x80800A5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A60: jal         0x800898C0
    // 0x80800A64: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_16(rdram, ctx);
        goto after_20;
    // 0x80800A64: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_20:
    // 0x80800A68: lbu         $t5, 0x77($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X77);
    // 0x80800A6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800A70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800A74: andi        $t6, $t5, 0xFFF0
    ctx->r14 = ctx->r13 & 0XFFF0;
    // 0x80800A78: sb          $t6, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r14;
    // 0x80800A7C: b           L_80800AD4
    // 0x80800A80: swc1        $f16, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f16.u32l;
        goto L_80800AD4;
    // 0x80800A80: swc1        $f16, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f16.u32l;
L_80800A84:
    // 0x80800A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A88: jal         0x80089848
    // 0x80800A8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_21;
    // 0x80800A8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A94: jal         0x8010A800
    // 0x80800A98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_22;
    // 0x80800A98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x80800A9C: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800AA0: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    // 0x80800AA4: jal         0x800DA524
    // 0x80800AA8: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    func_800DA524(rdram, ctx);
        goto after_23;
    // 0x80800AA8: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    after_23:
    // 0x80800AAC: jal         0x800DA544
    // 0x80800AB0: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    func_800DA544(rdram, ctx);
        goto after_24;
    // 0x80800AB0: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    after_24:
    // 0x80800AB4: jal         0x800DA544
    // 0x80800AB8: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    func_800DA544(rdram, ctx);
        goto after_25;
    // 0x80800AB8: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    after_25:
    // 0x80800ABC: b           L_80800AD8
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800AD8;
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800AC4:
    // 0x80800AC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800AC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800ACC: nop

    // 0x80800AD0: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
L_80800AD4:
    // 0x80800AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800AD8:
    // 0x80800AD8: jal         0x80102424
    // 0x80800ADC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80102424(rdram, ctx);
        goto after_26;
    // 0x80800ADC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_26:
    // 0x80800AE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800AEC: jr          $ra
    // 0x80800AF0: nop

    return;
    // 0x80800AF0: nop

;}
RECOMP_FUNC void func_800B8C8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8C8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8C90: jr          $ra
    // 0x800B8C94: sb          $a0, -0x7D3D($at)
    MEM_B(-0X7D3D, ctx->r1) = ctx->r4;
    return;
    // 0x800B8C94: sb          $a0, -0x7D3D($at)
    MEM_B(-0X7D3D, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_800A0D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0D14: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800A0D18: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A0D1C: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800A0D20: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x800A0D24: swc1        $f12, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f12.u32l;
    // 0x800A0D28: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    // 0x800A0D2C: bc1f        L_800A0D3C
    if (!c1cs) {
        // 0x800A0D30: sb          $a1, 0xC($t7)
        MEM_B(0XC, ctx->r15) = ctx->r5;
            goto L_800A0D3C;
    }
    // 0x800A0D30: sb          $a1, 0xC($t7)
    MEM_B(0XC, ctx->r15) = ctx->r5;
    // 0x800A0D34: lw          $t8, 0x138($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X138);
    // 0x800A0D38: sb          $a1, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r5;
L_800A0D3C:
    // 0x800A0D3C: jr          $ra
    // 0x800A0D40: nop

    return;
    // 0x800A0D40: nop

;}
RECOMP_FUNC void func_8008DDEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DDEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008DDF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DDF4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8008DDF8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8008DDFC: jal         0x8009C128
    // 0x8008DE00: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8008DE00: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8008DE04: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8008DE08: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8008DE0C: jal         0x800F0064
    // 0x8008DE10: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800F0064(rdram, ctx);
        goto after_1;
    // 0x8008DE10: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8008DE14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DE18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008DE1C: jr          $ra
    // 0x8008DE20: nop

    return;
    // 0x8008DE20: nop

;}
RECOMP_FUNC void func_800F72DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F72DC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F72E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F72E4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F72E8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F72EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F72F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F72F4: jal         0x8009640C
    // 0x800F72F8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009640C(rdram, ctx);
        goto after_0;
    // 0x800F72F8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F72FC: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F7300: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800F7304: bne         $t7, $zero, L_800F731C
    if (ctx->r15 != 0) {
        // 0x800F7308: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800F731C;
    }
    // 0x800F7308: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F730C: jal         0x80095738
    // 0x800F7310: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    baflag_isTrue(rdram, ctx);
        goto after_1;
    // 0x800F7310: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_1:
    // 0x800F7314: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F7318: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800F731C:
    // 0x800F731C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7320: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F7324: jr          $ra
    // 0x800F7328: nop

    return;
    // 0x800F7328: nop

;}
RECOMP_FUNC void cosectionstor_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808001AC: slti        $at, $a0, 0xA0
    ctx->r1 = SIGNED(ctx->r4) < 0XA0 ? 1 : 0;
    // 0x808001B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001B4: bne         $at, $zero, L_80800230
    if (ctx->r1 != 0) {
        // 0x808001B8: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80800230;
    }
    // 0x808001B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001BC: addiu       $a0, $a0, -0xA0
    ctx->r4 = ADD32(ctx->r4, -0XA0);
    // 0x808001C0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x808001C4: addiu       $t7, $t7, 0x7198
    ctx->r15 = ADD32(ctx->r15, 0X7198);
    // 0x808001C8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808001CC: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x808001D0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x808001D4: beql        $t8, $zero, L_80800234
    if (ctx->r24 == 0) {
        // 0x808001D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800234;
    }
    goto skip_0;
    // 0x808001D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808001DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x808001E0: jal         0x800DAA28
    // 0x808001E4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800DAA28(rdram, ctx);
        goto after_0;
    // 0x808001E4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x808001E8: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x808001EC: sra         $t9, $v1, 5
    ctx->r25 = S32(SIGNED(ctx->r3) >> 5);
    // 0x808001F0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x808001F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001F8: jal         0x80088048
    // 0x808001FC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _gccollectDll_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x808001FC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800200: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800204: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80800208: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080020C: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x80800210: addiu       $t2, $t1, 0x7F
    ctx->r10 = ADD32(ctx->r9, 0X7F);
    // 0x80800214: sra         $t4, $t2, 7
    ctx->r12 = S32(SIGNED(ctx->r10) >> 7);
    // 0x80800218: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8080021C: jal         0x80089F10
    // 0x80800220: addu        $a1, $v0, $t5
    ctx->r5 = ADD32(ctx->r2, ctx->r13);
    _subaddiestore_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800220: addu        $a1, $v0, $t5
    ctx->r5 = ADD32(ctx->r2, ctx->r13);
    after_2:
    // 0x80800224: jal         0x8001B084
    // 0x80800228: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    heap_free(rdram, ctx);
        goto after_3;
    // 0x80800228: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x8080022C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_80800230:
    // 0x80800230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800234:
    // 0x80800234: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800238: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080023C: jr          $ra
    // 0x80800240: nop

    return;
    // 0x80800240: nop

    // 0x80800244: nop

    // 0x80800248: nop

    // 0x8080024C: nop

;}
RECOMP_FUNC void func_80800D50_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800D5C: jal         0x800839E8
    // 0x80800D60: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800D60: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800D64: beq         $v0, $zero, L_80800D78
    if (ctx->r2 == 0) {
        // 0x80800D68: nop
    
            goto L_80800D78;
    }
    // 0x80800D68: nop

    // 0x80800D6C: jal         0x800839B0
    // 0x80800D70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsrest_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800D70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800D74: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80800D78:
    // 0x80800D78: jal         0x808002F8
    // 0x80800D7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bssnowball_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800D7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800D80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800D84: jal         0x8009E5C8
    // 0x80800D88: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80800D88: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D94: jr          $ra
    // 0x80800D98: nop

    return;
    // 0x80800D98: nop

;}
RECOMP_FUNC void chfishshootgame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080134C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(740, 0X1A00) << 16);
    // 0x80801350: jr          $ra
    // 0x80801354: addiu       $v0, $v0, 0x1A00
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(740, 0X1A00));
    return;
    // 0x80801354: addiu       $v0, $v0, 0x1A00
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(740, 0X1A00));
;}
RECOMP_FUNC void func_80801E9C_chfactoryempspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801EA0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801EA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801EA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801EAC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80801EB0: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
    // 0x80801EB4: lbu         $a0, 0x28($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X28);
    // 0x80801EB8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2304, 0X2408) << 16);
    // 0x80801EBC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80801EC0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801EC4: addiu       $a3, $a3, 0x2408
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2304, 0X2408));
    // 0x80801EC8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801ECC: jal         0x80089D68
    // 0x80801ED0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80801ED0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80801ED4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801ED8: sb          $v0, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r2;
    // 0x80801EDC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801EE0: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80801EE4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801EE8: jal         0x800F1214
    // 0x80801EEC: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    func_800F1214(rdram, ctx);
        goto after_1;
    // 0x80801EEC: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80801EF0: jal         0x800DC0C0
    // 0x80801EF4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x80801EF4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80801EF8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X2168) << 16);
    // 0x80801EFC: lwc1        $f4, 0x2168($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2168));
    // 0x80801F00: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801F04: lbu         $a0, 0x28($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X28);
    // 0x80801F08: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801F0C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80801F10: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80801F14: jal         0x800C31DC
    // 0x80801F18: nop

    func_800C31DC(rdram, ctx);
        goto after_3;
    // 0x80801F18: nop

    after_3:
    // 0x80801F1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801F20: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801F24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801F28: jr          $ra
    // 0x80801F2C: nop

    return;
    // 0x80801F2C: nop

;}
RECOMP_FUNC void _gcgoto_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A68: syscall     652
    recomp_syscall_handler(rdram, ctx, 0x80087A68);
    return;
    // 0x80087A6C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void sumultiscore_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F18: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80800F1C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80800F20: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80800F24: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x80800F28: lw          $v1, 0x4($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X4);
    // 0x80800F2C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80800F30: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80800F34: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800F38: addu        $v0, $a0, $t8
    ctx->r2 = ADD32(ctx->r4, ctx->r24);
    // 0x80800F3C: sll         $t0, $v1, 5
    ctx->r8 = S32(ctx->r3 << 5);
    // 0x80800F40: addu        $t9, $v0, $t0
    ctx->r25 = ADD32(ctx->r2, ctx->r8);
    // 0x80800F44: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800F48: bne         $a2, $at, L_80800F60
    if (ctx->r6 != ctx->r1) {
        // 0x80800F4C: sh          $a3, 0x48($t9)
        MEM_H(0X48, ctx->r25) = ctx->r7;
            goto L_80800F60;
    }
    // 0x80800F4C: sh          $a3, 0x48($t9)
    MEM_H(0X48, ctx->r25) = ctx->r7;
    // 0x80800F50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800F54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800F58: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80800F5C: swc1        $f4, 0x54($t1)
    MEM_W(0X54, ctx->r9) = ctx->f4.u32l;
L_80800F60:
    // 0x80800F60: jr          $ra
    // 0x80800F64: nop

    return;
    // 0x80800F64: nop

;}
RECOMP_FUNC void func_808000E0_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808000EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808000F0: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x808000F4: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(384, 0XB90) << 16);
    // 0x808000F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000FC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80800100: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80800104: lh          $t8, 0xB90($t8)
    ctx->r24 = MEM_H(ctx->r24, (int16_t)RELOC_LO16(384, 0XB90));
    // 0x80800108: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8080010C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800110: jal         0x8008B264
    // 0x80800114: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    anctrl_getIndex(rdram, ctx);
        goto after_0;
    // 0x80800114: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    after_0:
    // 0x80800118: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8080011C: beql        $v0, $t9, L_80800150
    if (ctx->r2 == ctx->r25) {
        // 0x80800120: lw          $t0, 0x15C($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X15C);
            goto L_80800150;
    }
    goto skip_0;
    // 0x80800120: lw          $t0, 0x15C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X15C);
    skip_0:
    // 0x80800124: jal         0x8008B2B4
    // 0x80800128: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_1;
    // 0x80800128: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8080012C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800130: jal         0x8008B24C
    // 0x80800134: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_2;
    // 0x80800134: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800138: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080013C: jal         0x8008AED4
    // 0x80800140: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80800140: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80800144: jal         0x8008B064
    // 0x80800148: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_start(rdram, ctx);
        goto after_4;
    // 0x80800148: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8080014C: lw          $t0, 0x15C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X15C);
L_80800150:
    // 0x80800150: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80800154: sltiu       $at, $t1, 0xA
    ctx->r1 = ctx->r9 < 0XA ? 1 : 0;
    // 0x80800158: bne         $at, $zero, L_80800164
    if (ctx->r1 != 0) {
        // 0x8080015C: sw          $t1, 0x15C($s0)
        MEM_W(0X15C, ctx->r16) = ctx->r9;
            goto L_80800164;
    }
    // 0x8080015C: sw          $t1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r9;
    // 0x80800160: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
L_80800164:
    // 0x80800164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800168: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080016C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800170: jr          $ra
    // 0x80800174: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800174: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800528_chpickups(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800528: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080052C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800530: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800534: jal         0x8008FDEC
    // 0x80800538: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8008FDEC(rdram, ctx);
        goto after_0;
    // 0x80800538: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080053C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80800540: beql        $v0, $t6, L_80800578
    if (ctx->r2 == ctx->r14) {
        // 0x80800544: lw          $t9, 0x64($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X64);
            goto L_80800578;
    }
    goto skip_0;
    // 0x80800544: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x80800548: jal         0x800F54E4
    // 0x8080054C: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x8080054C: nop

    after_1:
    // 0x80800550: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80800554: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800558: sll         $t7, $a1, 11
    ctx->r15 = S32(ctx->r5 << 11);
    // 0x8080055C: jal         0x800F63E0
    // 0x80800560: srl         $a1, $t7, 20
    ctx->r5 = S32(U32(ctx->r15) >> 20);
    func_800F63E0(rdram, ctx);
        goto after_2;
    // 0x80800560: srl         $a1, $t7, 20
    ctx->r5 = S32(U32(ctx->r15) >> 20);
    after_2:
    // 0x80800564: jal         0x800FFAB0
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080056C: b           L_808005A8
    // 0x80800570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808005A8;
    // 0x80800570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800574: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
L_80800578:
    // 0x80800578: sll         $t1, $t9, 9
    ctx->r9 = S32(ctx->r25 << 9);
    // 0x8080057C: bgezl       $t1, L_808005A8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800580: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808005A8;
    }
    goto skip_1;
    // 0x80800580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800584: jal         0x800F54E4
    // 0x80800588: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80800588: nop

    after_4:
    // 0x8080058C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800590: jal         0x800F5D44
    // 0x80800594: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F5D44(rdram, ctx);
        goto after_5;
    // 0x80800594: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x80800598: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080059C: jal         0x808001A0
    // 0x808005A0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_808001A0_chpickups(rdram, ctx);
        goto after_6;
    // 0x808005A0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x808005A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005A8:
    // 0x808005A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808005B0: jr          $ra
    // 0x808005B4: nop

    return;
    // 0x808005B4: nop

;}
RECOMP_FUNC void _bsbbilldrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082790: syscall     12
    recomp_syscall_handler(rdram, ctx, 0x80082790);
    return;
    // 0x80082794: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bsblongleg_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013C0: jal         0x8080013C
    // 0x808013C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080013C_bsblongleg(rdram, ctx);
        goto after_0;
    // 0x808013C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808013C8: jal         0x80082FE0
    // 0x808013CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808013CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808013D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808013D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808013D8: jr          $ra
    // 0x808013DC: nop

    return;
    // 0x808013DC: nop

;}
RECOMP_FUNC void func_808067E8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808067E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808067EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808067F0: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x808067F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808067F8: jal         0x80802458
    // 0x808067FC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80802458_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808067FC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80806800: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80806804: addiu       $a0, $v0, 0x54
    ctx->r4 = ADD32(ctx->r2, 0X54);
    // 0x80806808: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8080680C: jal         0x80031BF0
    // 0x80806810: addiu       $a1, $a1, 0x1E8
    ctx->r5 = ADD32(ctx->r5, 0X1E8);
    _bcopy(rdram, ctx);
        goto after_1;
    // 0x80806810: addiu       $a1, $a1, 0x1E8
    ctx->r5 = ADD32(ctx->r5, 0X1E8);
    after_1:
    // 0x80806814: jal         0x808067B0
    // 0x80806818: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808067B0_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80806818: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8080681C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806820: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80806824: jr          $ra
    // 0x80806828: nop

    return;
    // 0x80806828: nop

;}
RECOMP_FUNC void func_808001D0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D8: jal         0x80808C48
    // 0x808001DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80808C48_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808001DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001E4: jal         0x80800858
    // 0x808001E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800858_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808001E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808001EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001F4: jr          $ra
    // 0x808001F8: nop

    return;
    // 0x808001F8: nop

;}
RECOMP_FUNC void func_808011A8_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011AC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808011B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011B4: beq         $a1, $at, L_808011F4
    if (ctx->r5 == ctx->r1) {
        // 0x808011B8: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808011F4;
    }
    // 0x808011B8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808011BC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808011C0: beq         $a1, $at, L_80801260
    if (ctx->r5 == ctx->r1) {
        // 0x808011C4: addiu       $at, $zero, 0x49
        ctx->r1 = ADD32(0, 0X49);
            goto L_80801260;
    }
    // 0x808011C4: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x808011C8: beq         $a1, $at, L_808011E4
    if (ctx->r5 == ctx->r1) {
        // 0x808011CC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808011E4;
    }
    // 0x808011CC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808011D0: addiu       $at, $zero, 0x77
    ctx->r1 = ADD32(0, 0X77);
    // 0x808011D4: beq         $a1, $at, L_8080127C
    if (ctx->r5 == ctx->r1) {
        // 0x808011D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080127C;
    }
    // 0x808011D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808011DC: b           L_808012CC
    // 0x808011E0: nop

        goto L_808012CC;
    // 0x808011E0: nop

L_808011E4:
    // 0x808011E4: jal         0x8080100C
    // 0x808011E8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8080100C_chclinker(rdram, ctx);
        goto after_0;
    // 0x808011E8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x808011EC: b           L_808012CC
    // 0x808011F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808012CC;
    // 0x808011F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808011F4:
    // 0x808011F4: lhu         $t6, 0x72($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X72);
    // 0x808011F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808011FC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801200: bne         $t7, $at, L_80801258
    if (ctx->r15 != ctx->r1) {
        // 0x80801204: nop
    
            goto L_80801258;
    }
    // 0x80801204: nop

    // 0x80801208: jal         0x800F54E4
    // 0x8080120C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x8080120C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80801210: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801214: jal         0x800F7F98
    // 0x80801218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_2;
    // 0x80801218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080121C: jal         0x800F54E4
    // 0x80801220: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80801220: nop

    after_3:
    // 0x80801224: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801228: jal         0x800F7B9C
    // 0x8080122C: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    func_800F7B9C(rdram, ctx);
        goto after_4;
    // 0x8080122C: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    after_4:
    // 0x80801230: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801234: jal         0x80101FDC
    // 0x80801238: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80801238: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080123C: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x80801240: jal         0x800D0A9C
    // 0x80801244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_6;
    // 0x80801244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80801248: bne         $v0, $zero, L_80801258
    if (ctx->r2 != 0) {
        // 0x8080124C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801258;
    }
    // 0x8080124C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801250: jal         0x80800BDC
    // 0x80801254: addiu       $a1, $zero, 0x1373
    ctx->r5 = ADD32(0, 0X1373);
    func_80800BDC_chclinker(rdram, ctx);
        goto after_7;
    // 0x80801254: addiu       $a1, $zero, 0x1373
    ctx->r5 = ADD32(0, 0X1373);
    after_7:
L_80801258:
    // 0x80801258: b           L_808012CC
    // 0x8080125C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808012CC;
    // 0x8080125C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80801260:
    // 0x80801260: jal         0x800F54E4
    // 0x80801264: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x80801264: nop

    after_8:
    // 0x80801268: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080126C: jal         0x800F7F98
    // 0x80801270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_9;
    // 0x80801270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80801274: b           L_808012CC
    // 0x80801278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808012CC;
    // 0x80801278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080127C:
    // 0x8080127C: lhu         $t8, 0x72($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X72);
    // 0x80801280: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801284: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80801288: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x8080128C: bne         $t9, $at, L_808012CC
    if (ctx->r25 != ctx->r1) {
        // 0x80801290: addiu       $a1, $zero, 0x73
        ctx->r5 = ADD32(0, 0X73);
            goto L_808012CC;
    }
    // 0x80801290: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x80801294: jal         0x800F7B9C
    // 0x80801298: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800F7B9C(rdram, ctx);
        goto after_10;
    // 0x80801298: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_10:
    // 0x8080129C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808012A0: jal         0x80101FDC
    // 0x808012A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x808012A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808012A8: jal         0x80085710
    // 0x808012AC: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_12;
    // 0x808012AC: nop

    after_12:
    // 0x808012B0: jal         0x800F54E4
    // 0x808012B4: nop

    func_800F54E4(rdram, ctx);
        goto after_13;
    // 0x808012B4: nop

    after_13:
    // 0x808012B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808012BC: jal         0x800F7B9C
    // 0x808012C0: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    func_800F7B9C(rdram, ctx);
        goto after_14;
    // 0x808012C0: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    after_14:
    // 0x808012C4: b           L_808012CC
    // 0x808012C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808012CC;
    // 0x808012C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808012CC:
    // 0x808012CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808012D4: jr          $ra
    // 0x808012D8: nop

    return;
    // 0x808012D8: nop

;}
RECOMP_FUNC void _capod_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085728: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x80085728);
    return;
    // 0x8008572C: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_80081AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081AA4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80081AA8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80081AAC: addiu       $v1, $v1, 0x2540
    ctx->r3 = ADD32(ctx->r3, 0X2540);
    // 0x80081AB0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80081AB4: sltu        $at, $a0, $v1
    ctx->r1 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x80081AB8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80081ABC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80081AC0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80081AC4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80081AC8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80081ACC: bne         $at, $zero, L_80081B3C
    if (ctx->r1 != 0) {
        // 0x80081AD0: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80081B3C;
    }
    // 0x80081AD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80081AD4: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80081AD8: addiu       $t6, $t6, -0x5678
    ctx->r14 = ADD32(ctx->r14, -0X5678);
    // 0x80081ADC: sltu        $at, $a0, $t6
    ctx->r1 = ctx->r4 < ctx->r14 ? 1 : 0;
    // 0x80081AE0: beq         $at, $zero, L_80081B3C
    if (ctx->r1 == 0) {
        // 0x80081AE4: subu        $t7, $a0, $v1
        ctx->r15 = SUB32(ctx->r4, ctx->r3);
            goto L_80081B3C;
    }
    // 0x80081AE4: subu        $t7, $a0, $v1
    ctx->r15 = SUB32(ctx->r4, ctx->r3);
    // 0x80081AE8: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80081AEC: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80081AF0: addu        $a0, $t8, $v1
    ctx->r4 = ADD32(ctx->r24, ctx->r3);
    // 0x80081AF4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80081AF8: lui         $at, 0xFC00
    ctx->r1 = S32(0XFC00 << 16);
    // 0x80081AFC: ori         $at, $at, 0x3F
    ctx->r1 = ctx->r1 | 0X3F;
    // 0x80081B00: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80081B04: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80081B08: bnel        $t0, $at, L_80081B1C
    if (ctx->r8 != ctx->r1) {
        // 0x80081B0C: lw          $s0, 0x0($a0)
        ctx->r16 = MEM_W(ctx->r4, 0X0);
            goto L_80081B1C;
    }
    goto skip_0;
    // 0x80081B0C: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80081B10: b           L_80081BA0
    // 0x80081B14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80081BA0;
    // 0x80081B14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80081B18: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
L_80081B1C:
    // 0x80081B1C: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x80081B20: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80081B24: and         $t1, $s0, $at
    ctx->r9 = ctx->r16 & ctx->r1;
    // 0x80081B28: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80081B2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081B30: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80081B34: b           L_80081BA0
    // 0x80081B38: addiu       $v0, $t3, -0x10
    ctx->r2 = ADD32(ctx->r11, -0X10);
        goto L_80081BA0;
    // 0x80081B38: addiu       $v0, $t3, -0x10
    ctx->r2 = ADD32(ctx->r11, -0X10);
L_80081B3C:
    // 0x80081B3C: lui         $s4, 0x8011
    ctx->r20 = S32(0X8011 << 16);
    // 0x80081B40: addiu       $s4, $s4, 0x7C60
    ctx->r20 = ADD32(ctx->r20, 0X7C60);
    // 0x80081B44: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80081B48: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80081B4C: addiu       $s1, $s1, 0x6738
    ctx->r17 = ADD32(ctx->r17, 0X6738);
    // 0x80081B50: blez        $t4, L_80081B9C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80081B54: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80081B9C;
    }
    // 0x80081B54: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80081B58: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_80081B5C:
    // 0x80081B5C: jal         0x8001B388
    // 0x80081B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    heap_get_allocation_size(rdram, ctx);
        goto after_0;
    // 0x80081B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80081B64: sltu        $at, $s3, $s0
    ctx->r1 = ctx->r19 < ctx->r16 ? 1 : 0;
    // 0x80081B68: bne         $at, $zero, L_80081B84
    if (ctx->r1 != 0) {
        // 0x80081B6C: addu        $t5, $v0, $s0
        ctx->r13 = ADD32(ctx->r2, ctx->r16);
            goto L_80081B84;
    }
    // 0x80081B6C: addu        $t5, $v0, $s0
    ctx->r13 = ADD32(ctx->r2, ctx->r16);
    // 0x80081B70: sltu        $at, $t5, $s3
    ctx->r1 = ctx->r13 < ctx->r19 ? 1 : 0;
    // 0x80081B74: bnel        $at, $zero, L_80081B88
    if (ctx->r1 != 0) {
        // 0x80081B78: lw          $t6, 0x0($s4)
        ctx->r14 = MEM_W(ctx->r20, 0X0);
            goto L_80081B88;
    }
    goto skip_1;
    // 0x80081B78: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    skip_1:
    // 0x80081B7C: b           L_80081BA0
    // 0x80081B80: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80081BA0;
    // 0x80081B80: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80081B84:
    // 0x80081B84: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
L_80081B88:
    // 0x80081B88: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80081B8C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80081B90: slt         $at, $s2, $t6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80081B94: bnel        $at, $zero, L_80081B5C
    if (ctx->r1 != 0) {
        // 0x80081B98: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_80081B5C;
    }
    goto skip_2;
    // 0x80081B98: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_2:
L_80081B9C:
    // 0x80081B9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80081BA0:
    // 0x80081BA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80081BA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80081BA8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80081BAC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80081BB0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80081BB4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80081BB8: jr          $ra
    // 0x80081BBC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80081BBC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void bsbreegullbash_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002FC: lui         $a1, 0x3E61
    ctx->r5 = S32(0X3E61 << 16);
    // 0x80800300: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800304: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80800308: jal         0x8008CB10
    // 0x8080030C: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x8080030C: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    after_0:
    // 0x80800310: beql        $v0, $zero, L_8080036C
    if (ctx->r2 == 0) {
        // 0x80800314: lui         $a1, 0x3DF3
        ctx->r5 = S32(0X3DF3 << 16);
            goto L_8080036C;
    }
    goto skip_0;
    // 0x80800314: lui         $a1, 0x3DF3
    ctx->r5 = S32(0X3DF3 << 16);
    skip_0:
    // 0x80800318: jal         0x80084508
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babackpack_get_state(rdram, ctx);
        goto after_1;
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800320: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800324: bne         $v0, $at, L_80800368
    if (ctx->r2 != ctx->r1) {
        // 0x80800328: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800368;
    }
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080032C: jal         0x80095760
    // 0x80800330: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    baflag_set(rdram, ctx);
        goto after_2;
    // 0x80800330: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_2:
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800338: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080033C: jal         0x8009E55C
    // 0x80800340: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    func_8009E55C(rdram, ctx);
        goto after_3;
    // 0x80800340: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    after_3:
    // 0x80800344: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800348: addiu       $a2, $a2, 0x4510
    ctx->r6 = ADD32(ctx->r6, 0X4510);
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800350: jal         0x8009E4E0
    // 0x80800354: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E4E0(rdram, ctx);
        goto after_4;
    // 0x80800354: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080035C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800360: jal         0x8009E5A4
    // 0x80800364: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8009E5A4(rdram, ctx);
        goto after_5;
    // 0x80800364: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
L_80800368:
    // 0x80800368: lui         $a1, 0x3DF3
    ctx->r5 = S32(0X3DF3 << 16);
L_8080036C:
    // 0x8080036C: ori         $a1, $a1, 0x4D6A
    ctx->r5 = ctx->r5 | 0X4D6A;
    // 0x80800370: jal         0x8008CB10
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_6;
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800378: beql        $v0, $zero, L_8080038C
    if (ctx->r2 == 0) {
        // 0x8080037C: lui         $a1, 0x3E57
        ctx->r5 = S32(0X3E57 << 16);
            goto L_8080038C;
    }
    goto skip_1;
    // 0x8080037C: lui         $a1, 0x3E57
    ctx->r5 = S32(0X3E57 << 16);
    skip_1:
    // 0x80800380: jal         0x808001B4
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001B4_bsbreegullbash(rdram, ctx);
        goto after_7;
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800388: lui         $a1, 0x3E57
    ctx->r5 = S32(0X3E57 << 16);
L_8080038C:
    // 0x8080038C: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    // 0x80800390: jal         0x8008CB10
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_8;
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800398: beq         $v0, $zero, L_808003C4
    if (ctx->r2 == 0) {
        // 0x8080039C: lui         $a3, 0x3F8C
        ctx->r7 = S32(0X3F8C << 16);
            goto L_808003C4;
    }
    // 0x8080039C: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x808003A0: addiu       $t6, $zero, 0x55F0
    ctx->r14 = ADD32(0, 0X55F0);
    // 0x808003A4: addiu       $t7, $zero, 0x55F0
    ctx->r15 = ADD32(0, 0X55F0);
    // 0x808003A8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808003AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808003B0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B8: addiu       $a1, $zero, 0x4595
    ctx->r5 = ADD32(0, 0X4595);
    // 0x808003BC: jal         0x8009DFD4
    // 0x808003C0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DFD4(rdram, ctx);
        goto after_9;
    // 0x808003C0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_9:
L_808003C4:
    // 0x808003C4: lui         $a1, 0x3EB8
    ctx->r5 = S32(0X3EB8 << 16);
    // 0x808003C8: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x808003CC: jal         0x8008CB10
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_10;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808003D4: beq         $v0, $zero, L_808003EC
    if (ctx->r2 == 0) {
        // 0x808003D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003EC;
    }
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003DC: addiu       $a1, $zero, 0x416
    ctx->r5 = ADD32(0, 0X416);
    // 0x808003E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808003E4: jal         0x8009DB04
    // 0x808003E8: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DB04(rdram, ctx);
        goto after_11;
    // 0x808003E8: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_11:
L_808003EC:
    // 0x808003EC: lui         $a1, 0x3EBD
    ctx->r5 = S32(0X3EBD << 16);
    // 0x808003F0: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    // 0x808003F4: jal         0x8008CB10
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_12;
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808003FC: beq         $v0, $zero, L_80800428
    if (ctx->r2 == 0) {
        // 0x80800400: lui         $a3, 0x3F8C
        ctx->r7 = S32(0X3F8C << 16);
            goto L_80800428;
    }
    // 0x80800400: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x80800404: addiu       $t8, $zero, 0x7FFF
    ctx->r24 = ADD32(0, 0X7FFF);
    // 0x80800408: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x8080040C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800410: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800414: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080041C: addiu       $a1, $zero, 0x4596
    ctx->r5 = ADD32(0, 0X4596);
    // 0x80800420: jal         0x8009DFD4
    // 0x80800424: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DFD4(rdram, ctx);
        goto after_13;
    // 0x80800424: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_13:
L_80800428:
    // 0x80800428: lui         $a1, 0x3F2B
    ctx->r5 = S32(0X3F2B << 16);
    // 0x8080042C: ori         $a1, $a1, 0xE0DF
    ctx->r5 = ctx->r5 | 0XE0DF;
    // 0x80800430: jal         0x8008CB10
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_14;
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800438: beq         $v0, $zero, L_80800450
    if (ctx->r2 == 0) {
        // 0x8080043C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800450;
    }
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800440: addiu       $a1, $zero, 0x3EA
    ctx->r5 = ADD32(0, 0X3EA);
    // 0x80800444: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800448: jal         0x8009DF18
    // 0x8080044C: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF18(rdram, ctx);
        goto after_15;
    // 0x8080044C: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_15:
L_80800450:
    // 0x80800450: lui         $a1, 0x3EAB
    ctx->r5 = S32(0X3EAB << 16);
    // 0x80800454: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x80800458: jal         0x8008CB10
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_16;
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800460: beq         $v0, $zero, L_8080048C
    if (ctx->r2 == 0) {
        // 0x80800464: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080048C;
    }
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800468: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080046C: jal         0x80084FC8
    // 0x80800470: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _bashake_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x80800470: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_17:
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800478: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080047C: jal         0x8009E55C
    // 0x80800480: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    func_8009E55C(rdram, ctx);
        goto after_18;
    // 0x80800480: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    after_18:
    // 0x80800484: jal         0x808000A4
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000A4_bsbreegullbash(rdram, ctx);
        goto after_19;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
L_8080048C:
    // 0x8080048C: lui         $a1, 0x3EC2
    ctx->r5 = S32(0X3EC2 << 16);
    // 0x80800490: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x80800494: jal         0x8008CB10
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_20;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8080049C: beq         $v0, $zero, L_808004BC
    if (ctx->r2 == 0) {
        // 0x808004A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004BC;
    }
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808004A8: jal         0x8009E55C
    // 0x808004AC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E55C(rdram, ctx);
        goto after_21;
    // 0x808004AC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_21:
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B4: jal         0x80095774
    // 0x808004B8: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    baflag_clear(rdram, ctx);
        goto after_22;
    // 0x808004B8: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_22:
L_808004BC:
    // 0x808004BC: lui         $a1, 0x3F64
    ctx->r5 = S32(0X3F64 << 16);
    // 0x808004C0: ori         $a1, $a1, 0x1F21
    ctx->r5 = ctx->r5 | 0X1F21;
    // 0x808004C4: jal         0x8008CB10
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_23;
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808004CC: beq         $v0, $zero, L_808004DC
    if (ctx->r2 == 0) {
        // 0x808004D0: nop
    
            goto L_808004DC;
    }
    // 0x808004D0: nop

    // 0x808004D4: jal         0x808001D4
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001D4_bsbreegullbash(rdram, ctx);
        goto after_24;
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
L_808004DC:
    // 0x808004DC: jal         0x8008CAEC
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_25;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808004E4: beq         $v0, $zero, L_808004F0
    if (ctx->r2 == 0) {
        // 0x808004E8: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_808004F0;
    }
    // 0x808004E8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808004EC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_808004F0:
    // 0x808004F0: jal         0x8008E35C
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_26;
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x808004F8: beq         $v0, $zero, L_80800508
    if (ctx->r2 == 0) {
        // 0x808004FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800508;
    }
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800500: addiu       $t1, $zero, 0x4C
    ctx->r9 = ADD32(0, 0X4C);
    // 0x80800504: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_80800508:
    // 0x80800508: jal         0x8009E5C8
    // 0x8080050C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_27;
    // 0x8080050C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_27:
    // 0x80800510: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800514: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800518: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080051C: jr          $ra
    // 0x80800520: nop

    return;
    // 0x80800520: nop

;}
RECOMP_FUNC void func_8080024C_bsmumstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800254: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800258: jal         0x8008CAEC
    // 0x8080025C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    baanim_isStopped(rdram, ctx);
        goto after_0;
    // 0x8080025C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800260: beq         $v0, $zero, L_8080026C
    if (ctx->r2 == 0) {
        // 0x80800264: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8080026C;
    }
    // 0x80800264: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800268: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
L_8080026C:
    // 0x8080026C: jal         0x80800000
    // 0x80800270: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800000_bsmumstill(rdram, ctx);
        goto after_1;
    // 0x80800270: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800274: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800278: jal         0x8009E5C8
    // 0x8080027C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x8080027C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80800280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800284: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800288: jr          $ra
    // 0x8080028C: nop

    return;
    // 0x8080028C: nop

;}
RECOMP_FUNC void func_80800114_bssplat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800118: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080011C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800120: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800124: jal         0x8008CABC
    // 0x80800128: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800128: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x8080012C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800130: jal         0x8009BB00
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_1;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800138: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8080013C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800140: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800144: jal         0x800F0E00
    // 0x80800148: sub.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f4.fl;
    func_800F0E00(rdram, ctx);
        goto after_2;
    // 0x80800148: sub.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f4.fl;
    after_2:
    // 0x8080014C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800150: jal         0x8009B9B0
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800158: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x8080015C: beq         $v0, $zero, L_80800174
    if (ctx->r2 == 0) {
        // 0x80800160: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800174;
    }
    // 0x80800160: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800164: beq         $v0, $at, L_808001DC
    if (ctx->r2 == ctx->r1) {
        // 0x80800168: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808001DC;
    }
    // 0x80800168: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080016C: b           L_8080021C
    // 0x80800170: nop

        goto L_8080021C;
    // 0x80800170: nop

L_80800174:
    // 0x80800174: jal         0x8009BB00
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080017C: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80800180: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800184: nop

    // 0x80800188: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8080018C: nop

    // 0x80800190: bc1f        L_808001A0
    if (!c1cs) {
        // 0x80800194: nop
    
            goto L_808001A0;
    }
    // 0x80800194: nop

    // 0x80800198: jal         0x80084A10
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_808001A0:
    // 0x808001A0: jal         0x8008DD04
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_6;
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808001A8: beq         $v0, $zero, L_808001B4
    if (ctx->r2 == 0) {
        // 0x808001AC: addiu       $t6, $zero, 0x2F
        ctx->r14 = ADD32(0, 0X2F);
            goto L_808001B4;
    }
    // 0x808001AC: addiu       $t6, $zero, 0x2F
    ctx->r14 = ADD32(0, 0X2F);
    // 0x808001B0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_808001B4:
    // 0x808001B4: jal         0x8008B324
    // 0x808001B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_7;
    // 0x808001B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x808001BC: beq         $v0, $zero, L_8080021C
    if (ctx->r2 == 0) {
        // 0x808001C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080021C;
    }
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C4: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    // 0x808001C8: jal         0x8008CCBC
    // 0x808001CC: lui         $a2, 0x4010
    ctx->r6 = S32(0X4010 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_8;
    // 0x808001CC: lui         $a2, 0x4010
    ctx->r6 = S32(0X4010 << 16);
    after_8:
    // 0x808001D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808001D4: b           L_8080021C
    // 0x808001D8: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_8080021C;
    // 0x808001D8: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_808001DC:
    // 0x808001DC: lui         $a1, 0x3F21
    ctx->r5 = S32(0X3F21 << 16);
    // 0x808001E0: jal         0x8008B348
    // 0x808001E4: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    anctrl_isAt(rdram, ctx);
        goto after_9;
    // 0x808001E4: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    after_9:
    // 0x808001E8: beq         $v0, $zero, L_808001F4
    if (ctx->r2 == 0) {
        // 0x808001EC: addiu       $t8, $zero, 0x20
        ctx->r24 = ADD32(0, 0X20);
            goto L_808001F4;
    }
    // 0x808001EC: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x808001F0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_808001F4:
    // 0x808001F4: jal         0x8008B324
    // 0x808001F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_10;
    // 0x808001F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_10:
    // 0x808001FC: beq         $v0, $zero, L_80800208
    if (ctx->r2 == 0) {
        // 0x80800200: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80800208;
    }
    // 0x80800200: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800204: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80800208:
    // 0x80800208: jal         0x8008DD04
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_11;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800210: beq         $v0, $zero, L_8080021C
    if (ctx->r2 == 0) {
        // 0x80800214: addiu       $t0, $zero, 0x2F
        ctx->r8 = ADD32(0, 0X2F);
            goto L_8080021C;
    }
    // 0x80800214: addiu       $t0, $zero, 0x2F
    ctx->r8 = ADD32(0, 0X2F);
    // 0x80800218: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_8080021C:
    // 0x8080021C: jal         0x8008E078
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_12;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800224: bne         $v0, $zero, L_80800240
    if (ctx->r2 != 0) {
        // 0x80800228: nop
    
            goto L_80800240;
    }
    // 0x80800228: nop

    // 0x8080022C: jal         0x8008E35C
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_13;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800234: beq         $v0, $zero, L_80800240
    if (ctx->r2 == 0) {
        // 0x80800238: addiu       $t1, $zero, 0x2D
        ctx->r9 = ADD32(0, 0X2D);
            goto L_80800240;
    }
    // 0x80800238: addiu       $t1, $zero, 0x2D
    ctx->r9 = ADD32(0, 0X2D);
    // 0x8080023C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80800240:
    // 0x80800240: jal         0x800A1718
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_14;
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800248: bne         $v0, $zero, L_80800258
    if (ctx->r2 != 0) {
        // 0x8080024C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800258;
    }
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800250: addiu       $t2, $zero, 0x41
    ctx->r10 = ADD32(0, 0X41);
    // 0x80800254: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_80800258:
    // 0x80800258: jal         0x8009E5C8
    // 0x8080025C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_15;
    // 0x8080025C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x80800260: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800264: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800268: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080026C: jr          $ra
    // 0x80800270: nop

    return;
    // 0x80800270: nop

;}
RECOMP_FUNC void _ncbastring_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089160: syscall     763
    recomp_syscall_handler(rdram, ctx, 0x80089160);
    return;
    // 0x80089164: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800144_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800144: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080014C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800150: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800154: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800158: jal         0x80100094
    // 0x8080015C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080015C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800160: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800164: lbu         $v1, 0x95($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X95);
    // 0x80800168: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080016C: beql        $v1, $zero, L_808001A0
    if (ctx->r3 == 0) {
        // 0x80800170: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_808001A0;
    }
    goto skip_0;
    // 0x80800170: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80800174: beq         $v1, $at, L_808001B0
    if (ctx->r3 == ctx->r1) {
        // 0x80800178: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808001B0;
    }
    // 0x80800178: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080017C: beq         $v1, $at, L_808001D8
    if (ctx->r3 == ctx->r1) {
        // 0x80800180: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808001D8;
    }
    // 0x80800180: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800184: bnel        $v1, $at, L_808001E8
    if (ctx->r3 != ctx->r1) {
        // 0x80800188: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001E8;
    }
    goto skip_1;
    // 0x80800188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8080018C: jal         0x800F54E4
    // 0x80800190: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800190: nop

    after_1:
    // 0x80800194: jal         0x800F4B20
    // 0x80800198: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4B20(rdram, ctx);
        goto after_2;
    // 0x80800198: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080019C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
L_808001A0:
    // 0x808001A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808001A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001A8: jal         0x800856B0
    // 0x808001AC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808001AC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_3:
L_808001B0:
    // 0x808001B0: jal         0x800856E0
    // 0x808001B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x808001B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x808001B8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x808001BC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808001C0: sb          $t7, 0x95($t8)
    MEM_B(0X95, ctx->r24) = ctx->r15;
    // 0x808001C4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808001C8: jal         0x800880A8
    // 0x808001CC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    _gcdialogcamera_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x808001CC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_5:
    // 0x808001D0: jal         0x800880B8
    // 0x808001D4: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808001D4: nop

    after_6:
L_808001D8:
    // 0x808001D8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808001DC: jal         0x800856D8
    // 0x808001E0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_7(rdram, ctx);
        goto after_7;
    // 0x808001E0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x808001E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001E8:
    // 0x808001E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001EC: jr          $ra
    // 0x808001F0: nop

    return;
    // 0x808001F0: nop

;}
RECOMP_FUNC void func_800967C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800967C8: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800967CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800967D0: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x800967D4: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x800967D8: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x800967DC: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x800967E0: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x800967E4: jal         0x800EFB24
    // 0x800967E8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800967E8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x800967EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800967F0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800967F4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800967F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800967FC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80096800: jal         0x800EFA4C
    // 0x80096804: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x80096804: nop

    after_1:
    // 0x80096808: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8009680C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80096810: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80096814: jal         0x800EFA4C
    // 0x80096818: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x80096818: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x8009681C: jal         0x800EF2A0
    // 0x80096820: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800EF2A0(rdram, ctx);
        goto after_3;
    // 0x80096820: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_3:
    // 0x80096824: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80096828: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8009682C: jal         0x800EE97C
    // 0x80096830: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    func_800EE97C(rdram, ctx);
        goto after_4;
    // 0x80096830: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_4:
    // 0x80096834: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    // 0x80096838: jal         0x800EEAA4
    // 0x8009683C: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_800EEAA4(rdram, ctx);
        goto after_5;
    // 0x8009683C: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_5:
    // 0x80096840: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80096844: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x80096848: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8009684C: nop

    // 0x80096850: bc1tl       L_80096AC0
    if (c1cs) {
        // 0x80096854: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80096AC0;
    }
    goto skip_0;
    // 0x80096854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80096858: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8009685C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80096860: bc1tl       L_80096AC0
    if (c1cs) {
        // 0x80096864: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80096AC0;
    }
    goto skip_1;
    // 0x80096864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80096868: jal         0x800EEAA4
    // 0x8009686C: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    func_800EEAA4(rdram, ctx);
        goto after_6;
    // 0x8009686C: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    after_6:
    // 0x80096870: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80096874: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x80096878: jal         0x800EEAA4
    // 0x8009687C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_800EEAA4(rdram, ctx);
        goto after_7;
    // 0x8009687C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x80096880: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80096884: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80096888: addiu       $v0, $sp, 0x7C
    ctx->r2 = ADD32(ctx->r29, 0X7C);
    // 0x8009688C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80096890: lw          $v1, 0xA4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA4);
    // 0x80096894: sub.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80096898: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8009689C: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x800968A0: bc1t        L_80096ABC
    if (c1cs) {
        // 0x800968A4: div.s       $f2, $f4, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
            goto L_80096ABC;
    }
    // 0x800968A4: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800968A8: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800968AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800968B0: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800968B4: mul.s       $f18, $f14, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800968B8: beql        $v0, $a1, L_800968EC
    if (ctx->r2 == ctx->r5) {
        // 0x800968BC: add.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
            goto L_800968EC;
    }
    goto skip_2;
    // 0x800968BC: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    skip_2:
    // 0x800968C0: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
L_800968C4:
    // 0x800968C4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800968C8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800968CC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800968D0: swc1        $f14, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f14.u32l;
    // 0x800968D4: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800968D8: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800968DC: mul.s       $f18, $f14, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800968E0: bnel        $v0, $a1, L_800968C4
    if (ctx->r2 != ctx->r5) {
        // 0x800968E4: add.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
            goto L_800968C4;
    }
    goto skip_3;
    // 0x800968E4: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    skip_3:
    // 0x800968E8: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
L_800968EC:
    // 0x800968EC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800968F0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800968F4: swc1        $f14, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f14.u32l;
    // 0x800968F8: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x800968FC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80096900: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80096904: jal         0x800EFA4C
    // 0x80096908: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_800EFA4C(rdram, ctx);
        goto after_8;
    // 0x80096908: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_8:
    // 0x8009690C: jal         0x800EF2A0
    // 0x80096910: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    func_800EF2A0(rdram, ctx);
        goto after_9;
    // 0x80096910: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    after_9:
    // 0x80096914: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x80096918: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8009691C: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80096920: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80096924: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80096928: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8009692C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80096930: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80096934: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80096938: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8009693C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80096940: jal         0x800EFA4C
    // 0x80096944: nop

    func_800EFA4C(rdram, ctx);
        goto after_10;
    // 0x80096944: nop

    after_10:
    // 0x80096948: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8009694C: jal         0x800EEAA4
    // 0x80096950: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800EEAA4(rdram, ctx);
        goto after_11;
    // 0x80096950: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_11:
    // 0x80096954: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80096958: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8009695C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80096960: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80096964: nop

    // 0x80096968: bc1tl       L_80096AC0
    if (c1cs) {
        // 0x8009696C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80096AC0;
    }
    goto skip_4;
    // 0x8009696C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80096970: jal         0x800EEF94
    // 0x80096974: swc1        $f2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f2.u32l;
    func_800EEF94(rdram, ctx);
        goto after_12;
    // 0x80096974: swc1        $f2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f2.u32l;
    after_12:
    // 0x80096978: lwc1        $f2, 0x88($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8009697C: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    // 0x80096980: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x80096984: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80096988: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    // 0x8009698C: lui         $a3, 0x3CE5
    ctx->r7 = S32(0X3CE5 << 16);
    // 0x80096990: bc1tl       L_80096AC0
    if (c1cs) {
        // 0x80096994: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80096AC0;
    }
    goto skip_5;
    // 0x80096994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x80096998: jal         0x800BEE40
    // 0x8009699C: ori         $a3, $a3, 0x6042
    ctx->r7 = ctx->r7 | 0X6042;
    func_800BEE40(rdram, ctx);
        goto after_13;
    // 0x8009699C: ori         $a3, $a3, 0x6042
    ctx->r7 = ctx->r7 | 0X6042;
    after_13:
    // 0x800969A0: beq         $v0, $zero, L_80096ABC
    if (ctx->r2 == 0) {
        // 0x800969A4: lw          $a0, 0xA0($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XA0);
            goto L_80096ABC;
    }
    // 0x800969A4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800969A8: jal         0x800EEAD4
    // 0x800969AC: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    func_800EEAD4(rdram, ctx);
        goto after_14;
    // 0x800969AC: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    after_14:
    // 0x800969B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800969B4: addiu       $v0, $v0, 0x6E30
    ctx->r2 = ADD32(ctx->r2, 0X6E30);
    // 0x800969B8: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800969BC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800969C0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800969C4: nop

    // 0x800969C8: bc1tl       L_80096AC0
    if (c1cs) {
        // 0x800969CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80096AC0;
    }
    goto skip_6;
    // 0x800969CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x800969D0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800969D4: nop

    // 0x800969D8: bc1fl       L_800969E8
    if (!c1cs) {
        // 0x800969DC: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_800969E8;
    }
    goto skip_7;
    // 0x800969DC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_7:
    // 0x800969E0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800969E4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_800969E8:
    // 0x800969E8: addiu       $v1, $zero, 0x34
    ctx->r3 = ADD32(0, 0X34);
    // 0x800969EC: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800969F0: mflo        $t7
    ctx->r15 = lo;
    // 0x800969F4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800969F8: swc1        $f12, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f12.u32l;
    // 0x800969FC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80096A00: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x80096A04: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096A08: mflo        $t0
    ctx->r8 = lo;
    // 0x80096A0C: addu        $a0, $v0, $t0
    ctx->r4 = ADD32(ctx->r2, ctx->r8);
    // 0x80096A10: jal         0x800EE7F8
    // 0x80096A14: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x80096A14: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_15:
    // 0x80096A18: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80096A1C: addiu       $v0, $v0, 0x6E30
    ctx->r2 = ADD32(ctx->r2, 0X6E30);
    // 0x80096A20: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80096A24: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x80096A28: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80096A2C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80096A30: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80096A34: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80096A38: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80096A3C: addu        $a0, $v0, $t2
    ctx->r4 = ADD32(ctx->r2, ctx->r10);
    // 0x80096A40: jal         0x800EE7F8
    // 0x80096A44: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_800EE7F8(rdram, ctx);
        goto after_16;
    // 0x80096A44: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_16:
    // 0x80096A48: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80096A4C: addiu       $v0, $v0, 0x6E30
    ctx->r2 = ADD32(ctx->r2, 0X6E30);
    // 0x80096A50: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80096A54: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80096A58: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80096A5C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80096A60: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80096A64: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80096A68: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80096A6C: addu        $a0, $v0, $t4
    ctx->r4 = ADD32(ctx->r2, ctx->r12);
    // 0x80096A70: jal         0x800EE7F8
    // 0x80096A74: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_17;
    // 0x80096A74: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_17:
    // 0x80096A78: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80096A7C: addiu       $v0, $v0, 0x6E30
    ctx->r2 = ADD32(ctx->r2, 0X6E30);
    // 0x80096A80: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80096A84: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x80096A88: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80096A8C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80096A90: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80096A94: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80096A98: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80096A9C: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x80096AA0: jal         0x800EE7F8
    // 0x80096AA4: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_18;
    // 0x80096AA4: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_18:
    // 0x80096AA8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80096AAC: addiu       $v0, $v0, 0x6E30
    ctx->r2 = ADD32(ctx->r2, 0X6E30);
    // 0x80096AB0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80096AB4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80096AB8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_80096ABC:
    // 0x80096ABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80096AC0:
    // 0x80096AC0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x80096AC4: jr          $ra
    // 0x80096AC8: nop

    return;
    // 0x80096AC8: nop

;}
RECOMP_FUNC void chbosskogsdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2292, 0X918) << 16);
    // 0x808004EC: jr          $ra
    // 0x808004F0: addiu       $v0, $v0, 0x918
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2292, 0X918));
    return;
    // 0x808004F0: addiu       $v0, $v0, 0x918
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2292, 0X918));
;}
RECOMP_FUNC void bsfirstp_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805108: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080510C: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB540) << 16);
    // 0x80805110: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80805114: jr          $ra
    // 0x80805118: lw          $v0, -0x4AC0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB540));
    return;
    // 0x80805118: lw          $v0, -0x4AC0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB540));
;}
RECOMP_FUNC void _badata_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800846D8: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x800846D8);
    return;
    // 0x800846DC: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
