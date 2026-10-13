#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chboggygirl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086868: syscall     391
    recomp_syscall_handler(rdram, ctx, 0x80086868);
    return;
    // 0x8008686C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800AEDA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEDA0: lhu         $t4, 0xC($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0XC);
    // 0x800AEDA4: srl         $t5, $t4, 5
    ctx->r13 = S32(U32(ctx->r12) >> 5);
    // 0x800AEDA8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800AEDAC: addu        $t5, $t5, $a3
    ctx->r13 = ADD32(ctx->r13, ctx->r7);
    // 0x800AEDB0: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x800AEDB4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800AEDB8: andi        $t4, $t4, 0x1F
    ctx->r12 = ctx->r12 & 0X1F;
    // 0x800AEDBC: sllv        $t5, $t5, $t4
    ctx->r13 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x800AEDC0: and         $t6, $t6, $t5
    ctx->r14 = ctx->r14 & ctx->r13;
    // 0x800AEDC4: beq         $t6, $zero, L_800AF044
    if (ctx->r14 == 0) {
        // 0x800AEDC8: nop
    
            goto L_800AF044;
    }
    // 0x800AEDC8: nop

    // 0x800AEDCC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AEDD0: addiu       $t4, $t4, -0x5B60
    ctx->r12 = ADD32(ctx->r12, -0X5B60);
    // 0x800AEDD4: swc1        $f0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f0.u32l;
    // 0x800AEDD8: swc1        $f1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f_odd[(1 - 1) * 2];
    // 0x800AEDDC: swc1        $f2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f2.u32l;
    // 0x800AEDE0: swc1        $f3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f_odd[(3 - 1) * 2];
    // 0x800AEDE4: swc1        $f4, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f4.u32l;
    // 0x800AEDE8: swc1        $f5, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f_odd[(5 - 1) * 2];
    // 0x800AEDEC: swc1        $f6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f6.u32l;
    // 0x800AEDF0: swc1        $f7, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f_odd[(7 - 1) * 2];
    // 0x800AEDF4: swc1        $f8, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f8.u32l;
    // 0x800AEDF8: swc1        $f9, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f_odd[(9 - 1) * 2];
    // 0x800AEDFC: swc1        $f10, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->f10.u32l;
    // 0x800AEE00: swc1        $f11, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f_odd[(11 - 1) * 2];
    // 0x800AEE04: swc1        $f12, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->f12.u32l;
    // 0x800AEE08: swc1        $f13, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->f_odd[(13 - 1) * 2];
    // 0x800AEE0C: swc1        $f14, 0x38($t4)
    MEM_W(0X38, ctx->r12) = ctx->f14.u32l;
    // 0x800AEE10: swc1        $f15, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->f_odd[(15 - 1) * 2];
    // 0x800AEE14: swc1        $f16, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f16.u32l;
    // 0x800AEE18: swc1        $f17, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f_odd[(17 - 1) * 2];
    // 0x800AEE1C: swc1        $f18, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f18.u32l;
    // 0x800AEE20: swc1        $f19, 0x4C($t4)
    MEM_W(0X4C, ctx->r12) = ctx->f_odd[(19 - 1) * 2];
    // 0x800AEE24: swc1        $f20, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->f20.u32l;
    // 0x800AEE28: swc1        $f21, 0x54($t4)
    MEM_W(0X54, ctx->r12) = ctx->f_odd[(21 - 1) * 2];
    // 0x800AEE2C: swc1        $f22, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f22.u32l;
    // 0x800AEE30: swc1        $f23, 0x5C($t4)
    MEM_W(0X5C, ctx->r12) = ctx->f_odd[(23 - 1) * 2];
    // 0x800AEE34: swc1        $f24, 0x60($t4)
    MEM_W(0X60, ctx->r12) = ctx->f24.u32l;
    // 0x800AEE38: swc1        $f25, 0x64($t4)
    MEM_W(0X64, ctx->r12) = ctx->f_odd[(25 - 1) * 2];
    // 0x800AEE3C: swc1        $f26, 0x68($t4)
    MEM_W(0X68, ctx->r12) = ctx->f26.u32l;
    // 0x800AEE40: swc1        $f27, 0x6C($t4)
    MEM_W(0X6C, ctx->r12) = ctx->f_odd[(27 - 1) * 2];
    // 0x800AEE44: swc1        $f28, 0x70($t4)
    MEM_W(0X70, ctx->r12) = ctx->f28.u32l;
    // 0x800AEE48: swc1        $f29, 0x74($t4)
    MEM_W(0X74, ctx->r12) = ctx->f_odd[(29 - 1) * 2];
    // 0x800AEE4C: swc1        $f30, 0x78($t4)
    MEM_W(0X78, ctx->r12) = ctx->f30.u32l;
    // 0x800AEE50: swc1        $f31, 0x7C($t4)
    MEM_W(0X7C, ctx->r12) = ctx->f_odd[(31 - 1) * 2];
    // 0x800AEE54: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800AEE58: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x800AEE5C: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x800AEE60: sw          $at, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r1;
    // 0x800AEE64: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x800AEE68: sw          $v1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r3;
    // 0x800AEE6C: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x800AEE70: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x800AEE74: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800AEE78: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800AEE7C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800AEE80: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800AEE84: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800AEE88: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800AEE8C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800AEE90: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800AEE94: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x800AEE98: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x800AEE9C: sw          $k0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r26;
    // 0x800AEEA0: sw          $k1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r27;
    // 0x800AEEA4: sw          $gp, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r28;
    // 0x800AEEA8: sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // 0x800AEEAC: sdc1        $f0, 0x58($sp)
    CHECK_FR(ctx, 0);
    SD(ctx->f0.u64, 0X58, ctx->r29);
    // 0x800AEEB0: sdc1        $f2, 0x60($sp)
    CHECK_FR(ctx, 2);
    SD(ctx->f2.u64, 0X60, ctx->r29);
    // 0x800AEEB4: sdc1        $f4, 0x68($sp)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X68, ctx->r29);
    // 0x800AEEB8: sdc1        $f6, 0x70($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X70, ctx->r29);
    // 0x800AEEBC: sdc1        $f8, 0x78($sp)
    CHECK_FR(ctx, 8);
    SD(ctx->f8.u64, 0X78, ctx->r29);
    // 0x800AEEC0: sdc1        $f10, 0x80($sp)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X80, ctx->r29);
    // 0x800AEEC4: sdc1        $f12, 0x88($sp)
    CHECK_FR(ctx, 12);
    SD(ctx->f12.u64, 0X88, ctx->r29);
    // 0x800AEEC8: sdc1        $f14, 0x90($sp)
    CHECK_FR(ctx, 14);
    SD(ctx->f14.u64, 0X90, ctx->r29);
    // 0x800AEECC: sdc1        $f16, 0x98($sp)
    CHECK_FR(ctx, 16);
    SD(ctx->f16.u64, 0X98, ctx->r29);
    // 0x800AEED0: sdc1        $f18, 0xA0($sp)
    CHECK_FR(ctx, 18);
    SD(ctx->f18.u64, 0XA0, ctx->r29);
    // 0x800AEED4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AEED8: lhu         $a1, 0xC($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0XC);
    // 0x800AEEDC: addiu       $a2, $a2, -0x5A60
    ctx->r6 = ADD32(ctx->r6, -0X5A60);
    // 0x800AEEE0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800AEEE4: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x800AEEE8: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x800AEEEC: sw          $t2, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r10;
    // 0x800AEEF0: sw          $t3, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r11;
    // 0x800AEEF4: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x800AEEF8: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x800AEEFC: nor         $t1, $t1, $zero
    ctx->r9 = ~(ctx->r9 | 0);
    // 0x800AEF00: and         $t0, $t0, $t1
    ctx->r8 = ctx->r8 & ctx->r9;
    // 0x800AEF04: mtc0        $t0, Status
    cop0_status_write(ctx, ctx->r8);    // 0x800AEF08: jal         0x800E0CB4
    // 0x800AEF0C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    func_800E0CB4(rdram, ctx);
        goto after_0;
    // 0x800AEF0C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    after_0:
    // 0x800AEF10: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800AEF14: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x800AEF18: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x800AEF1C: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x800AEF20: mtc0        $t0, Status
    cop0_status_write(ctx, ctx->r8);    // 0x800AEF24: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800AEF28: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AEF2C: addiu       $t4, $t4, -0x5B60
    ctx->r12 = ADD32(ctx->r12, -0X5B60);
    // 0x800AEF30: ldc1        $f0, 0x58($sp)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r29, 0X58);
    // 0x800AEF34: ldc1        $f2, 0x60($sp)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r29, 0X60);
    // 0x800AEF38: ldc1        $f4, 0x68($sp)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r29, 0X68);
    // 0x800AEF3C: ldc1        $f6, 0x70($sp)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r29, 0X70);
    // 0x800AEF40: ldc1        $f8, 0x78($sp)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r29, 0X78);
    // 0x800AEF44: ldc1        $f10, 0x80($sp)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r29, 0X80);
    // 0x800AEF48: ldc1        $f12, 0x88($sp)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r29, 0X88);
    // 0x800AEF4C: ldc1        $f14, 0x90($sp)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r29, 0X90);
    // 0x800AEF50: ldc1        $f16, 0x98($sp)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r29, 0X98);
    // 0x800AEF54: ldc1        $f18, 0xA0($sp)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r29, 0XA0);
    // 0x800AEF58: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800AEF5C: lwc1        $f1, 0x4($t4)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r12, 0X4);
    // 0x800AEF60: lwc1        $f2, 0x8($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800AEF64: lwc1        $f3, 0xC($t4)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r12, 0XC);
    // 0x800AEF68: lwc1        $f4, 0x10($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X10);
    // 0x800AEF6C: lwc1        $f5, 0x14($t4)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r12, 0X14);
    // 0x800AEF70: lwc1        $f6, 0x18($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X18);
    // 0x800AEF74: lwc1        $f7, 0x1C($t4)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r12, 0X1C);
    // 0x800AEF78: lwc1        $f8, 0x20($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X20);
    // 0x800AEF7C: lwc1        $f9, 0x24($t4)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r12, 0X24);
    // 0x800AEF80: lwc1        $f10, 0x28($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X28);
    // 0x800AEF84: lwc1        $f11, 0x2C($t4)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r12, 0X2C);
    // 0x800AEF88: lwc1        $f12, 0x30($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X30);
    // 0x800AEF8C: lwc1        $f13, 0x34($t4)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r12, 0X34);
    // 0x800AEF90: lwc1        $f14, 0x38($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X38);
    // 0x800AEF94: lwc1        $f15, 0x3C($t4)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r12, 0X3C);
    // 0x800AEF98: lwc1        $f16, 0x40($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X40);
    // 0x800AEF9C: lwc1        $f17, 0x44($t4)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r12, 0X44);
    // 0x800AEFA0: lwc1        $f18, 0x48($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X48);
    // 0x800AEFA4: lwc1        $f19, 0x4C($t4)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r12, 0X4C);
    // 0x800AEFA8: lwc1        $f20, 0x50($t4)
    ctx->f20.u32l = MEM_W(ctx->r12, 0X50);
    // 0x800AEFAC: lwc1        $f21, 0x54($t4)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r12, 0X54);
    // 0x800AEFB0: lwc1        $f22, 0x58($t4)
    ctx->f22.u32l = MEM_W(ctx->r12, 0X58);
    // 0x800AEFB4: lwc1        $f23, 0x5C($t4)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r12, 0X5C);
    // 0x800AEFB8: lwc1        $f24, 0x60($t4)
    ctx->f24.u32l = MEM_W(ctx->r12, 0X60);
    // 0x800AEFBC: lwc1        $f25, 0x64($t4)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r12, 0X64);
    // 0x800AEFC0: lwc1        $f26, 0x68($t4)
    ctx->f26.u32l = MEM_W(ctx->r12, 0X68);
    // 0x800AEFC4: lwc1        $f27, 0x6C($t4)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r12, 0X6C);
    // 0x800AEFC8: lwc1        $f28, 0x70($t4)
    ctx->f28.u32l = MEM_W(ctx->r12, 0X70);
    // 0x800AEFCC: lwc1        $f29, 0x74($t4)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r12, 0X74);
    // 0x800AEFD0: lwc1        $f30, 0x78($t4)
    ctx->f30.u32l = MEM_W(ctx->r12, 0X78);
    // 0x800AEFD4: lwc1        $f31, 0x7C($t4)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r12, 0X7C);
    // 0x800AEFD8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AEFDC: addiu       $t4, $t4, -0x5A60
    ctx->r12 = ADD32(ctx->r12, -0X5A60);
    // 0x800AEFE0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800AEFE4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800AEFE8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800AEFEC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800AEFF0: lw          $at, 0x0($sp)
    ctx->r1 = MEM_W(ctx->r29, 0X0);
    // 0x800AEFF4: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800AEFF8: lw          $v1, 0x8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8);
    // 0x800AEFFC: lw          $a0, 0xC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC);
    // 0x800AF000: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
    // 0x800AF004: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x800AF008: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800AF00C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800AF010: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800AF014: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800AF018: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800AF01C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800AF020: lw          $k0, 0x44($sp)
    ctx->r26 = MEM_W(ctx->r29, 0X44);
    // 0x800AF024: lw          $k1, 0x48($sp)
    ctx->r27 = MEM_W(ctx->r29, 0X48);
    // 0x800AF028: lw          $gp, 0x4C($sp)
    ctx->r28 = MEM_W(ctx->r29, 0X4C);
    // 0x800AF02C: lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X50);
    // 0x800AF030: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // 0x800AF034: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x800AF038: lw          $t1, 0x4($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X4);
    // 0x800AF03C: lw          $t2, 0x8($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X8);
    // 0x800AF040: lw          $t3, 0xC($t4)
    ctx->r11 = MEM_W(ctx->r12, 0XC);
L_800AF044:
    // 0x800AF044: jr          $ra
    // 0x800AF048: nop

    return;
    // 0x800AF048: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089538: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089538);
    return;
    // 0x8008953C: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void basnowball_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800614: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800618: lw          $t6, 0x110($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X110);
    // 0x8080061C: jr          $ra
    // 0x80800620: swc1        $f12, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x80800620: swc1        $f12, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80090A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090A0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090A10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090A14: jal         0x8009097C
    // 0x80090A18: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009097C(rdram, ctx);
        goto after_0;
    // 0x80090A18: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80090A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090A20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090A24: jr          $ra
    // 0x80090A28: nop

    return;
    // 0x80090A28: nop

;}
RECOMP_FUNC void func_800CBB80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBB80: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800CBB84: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800CBB88: lw          $t7, -0x5174($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5174);
    // 0x800CBB8C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800CBB90: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CBB94: beq         $a1, $zero, L_800CBBAC
    if (ctx->r5 == 0) {
        // 0x800CBB98: addu        $v0, $t6, $t7
        ctx->r2 = ADD32(ctx->r14, ctx->r15);
            goto L_800CBBAC;
    }
    // 0x800CBB98: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800CBB9C: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x800CBBA0: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x800CBBA4: jr          $ra
    // 0x800CBBA8: sb          $t0, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r8;
    return;
    // 0x800CBBA8: sb          $t0, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r8;
L_800CBBAC:
    // 0x800CBBAC: lbu         $t1, 0x2($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2);
    // 0x800CBBB0: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x800CBBB4: sb          $t2, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r10;
    // 0x800CBBB8: jr          $ra
    // 0x800CBBBC: nop

    return;
    // 0x800CBBBC: nop

;}
RECOMP_FUNC void func_800C8CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8CB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C8CBC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C8CC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8CC4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C8CC8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8CCC: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C8CD0: jal         0x800B28CC
    // 0x800C8CD4: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    vector_at(rdram, ctx);
        goto after_0;
    // 0x800C8CD4: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    after_0:
    // 0x800C8CD8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800C8CDC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800C8CE0: jal         0x800EE940
    // 0x800C8CE4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800EE940(rdram, ctx);
        goto after_1;
    // 0x800C8CE4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x800C8CE8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800C8CEC: lh          $t7, 0x1C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1C);
    // 0x800C8CF0: lh          $t9, 0x1E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X1E);
    // 0x800C8CF4: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x800C8CF8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800C8CFC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800C8D00: bne         $t6, $t7, L_800C8D24
    if (ctx->r14 != ctx->r15) {
        // 0x800C8D04: nop
    
            goto L_800C8D24;
    }
    // 0x800C8D04: nop

    // 0x800C8D08: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x800C8D0C: lh          $t1, 0x20($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X20);
    // 0x800C8D10: bne         $t8, $t9, L_800C8D24
    if (ctx->r24 != ctx->r25) {
        // 0x800C8D14: nop
    
            goto L_800C8D24;
    }
    // 0x800C8D14: nop

    // 0x800C8D18: lh          $t0, 0x4($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X4);
    // 0x800C8D1C: beql        $t0, $t1, L_800C8D40
    if (ctx->r8 == ctx->r9) {
        // 0x800C8D20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C8D40;
    }
    goto skip_0;
    // 0x800C8D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_800C8D24:
    // 0x800C8D24: jal         0x800EE814
    // 0x800C8D28: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_800EE814(rdram, ctx);
        goto after_2;
    // 0x800C8D28: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x800C8D2C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800C8D30: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C8D34: sb          $t3, 0x19($a2)
    MEM_B(0X19, ctx->r6) = ctx->r11;
    // 0x800C8D38: sb          $t3, 0x16($a2)
    MEM_B(0X16, ctx->r6) = ctx->r11;
    // 0x800C8D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C8D40:
    // 0x800C8D40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C8D44: jr          $ra
    // 0x800C8D48: nop

    return;
    // 0x800C8D48: nop

;}
RECOMP_FUNC void func_800B4428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4428: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B442C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B4430: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B4434: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800B4438: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800B443C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B4440: addiu       $s1, $s1, 0x7F03
    ctx->r17 = ADD32(ctx->r17, 0X7F03);
    // 0x800B4444: addiu       $s0, $s0, 0x7F00
    ctx->r16 = ADD32(ctx->r16, 0X7F00);
L_800B4448:
    // 0x800B4448: jal         0x800B58D4
    // 0x800B444C: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    func_800B58D4(rdram, ctx);
        goto after_0;
    // 0x800B444C: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    after_0:
    // 0x800B4450: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B4454: bne         $s0, $s1, L_800B4448
    if (ctx->r16 != ctx->r17) {
        // 0x800B4458: nop
    
            goto L_800B4448;
    }
    // 0x800B4458: nop

    // 0x800B445C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4460: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B4464: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B4468: jr          $ra
    // 0x800B446C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B446C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bskazstilt_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801168: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080116C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801170: jal         0x808000C8
    // 0x80801174: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808000C8_bskazstilt(rdram, ctx);
        goto after_0;
    // 0x80801174: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801178: jal         0x80082FE8
    // 0x8080117C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080117C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801180: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801184: jal         0x800915AC
    // 0x80801188: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_isDone(rdram, ctx);
        goto after_2;
    // 0x80801188: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8080118C: beq         $v0, $zero, L_8080119C
    if (ctx->r2 == 0) {
        // 0x80801190: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080119C;
    }
    // 0x80801190: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801194: jal         0x8009E5C8
    // 0x80801198: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80801198: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    after_3:
L_8080119C:
    // 0x8080119C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011A4: jr          $ra
    // 0x808011A8: nop

    return;
    // 0x808011A8: nop

;}
RECOMP_FUNC void func_801012D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801012D0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801012D4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801012D8: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x801012DC: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x801012E0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x801012E4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801012E8: addiu       $s5, $sp, 0x40
    ctx->r21 = ADD32(ctx->r29, 0X40);
    // 0x801012EC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801012F0: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x801012F4: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x801012F8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801012FC: mul.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80101300: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80101304: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x80101308: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8010130C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80101310: jal         0x801067C4
    // 0x80101314: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x80101314: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_0:
    // 0x80101318: beq         $v0, $zero, L_8010137C
    if (ctx->r2 == 0) {
        // 0x8010131C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8010137C;
    }
    // 0x8010131C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80101320:
    // 0x80101320: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    // 0x80101324: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80101328: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x8010132C: bltz        $t8, L_8010136C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80101330: nop
    
            goto L_8010136C;
    }
    // 0x80101330: nop

    // 0x80101334: jal         0x800EEB40
    // 0x80101338: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EEB40(rdram, ctx);
        goto after_1;
    // 0x80101338: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x8010133C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80101340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80101344: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80101348: bc1f        L_8010136C
    if (!c1cs) {
        // 0x8010134C: nop
    
            goto L_8010136C;
    }
    // 0x8010134C: nop

    // 0x80101350: jal         0x8010108C
    // 0x80101354: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_8010108C(rdram, ctx);
        goto after_2;
    // 0x80101354: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_2:
    // 0x80101358: blez        $v0, L_8010136C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8010135C: nop
    
            goto L_8010136C;
    }
    // 0x8010135C: nop

    // 0x80101360: bne         $s1, $zero, L_8010136C
    if (ctx->r17 != 0) {
        // 0x80101364: nop
    
            goto L_8010136C;
    }
    // 0x80101364: nop

    // 0x80101368: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8010136C:
    // 0x8010136C: jal         0x8010682C
    // 0x80101370: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8010682C(rdram, ctx);
        goto after_3;
    // 0x80101370: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x80101374: bne         $v0, $zero, L_80101320
    if (ctx->r2 != 0) {
        // 0x80101378: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80101320;
    }
    // 0x80101378: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8010137C:
    // 0x8010137C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80101380: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80101384: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80101388: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8010138C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80101390: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80101394: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80101398: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8010139C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x801013A0: jr          $ra
    // 0x801013A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801013A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8080815C_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080815C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80808160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80808164: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80808168: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080816C: jal         0x80100094
    // 0x80808170: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80808170: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80808174: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80808178: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080817C: addiu       $a0, $zero, 0x178
    ctx->r4 = ADD32(0, 0X178);
    // 0x80808180: bne         $t6, $at, L_8080819C
    if (ctx->r14 != ctx->r1) {
        // 0x80808184: addiu       $a1, $sp, 0x20
        ctx->r5 = ADD32(ctx->r29, 0X20);
            goto L_8080819C;
    }
    // 0x80808184: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80808188: jal         0x801084B0
    // 0x8080818C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x8080818C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80808190: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80808194: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80808198: sw          $t7, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->r15;
L_8080819C:
    // 0x8080819C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808081A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808081A4: jr          $ra
    // 0x808081A8: nop

    return;
    // 0x808081A8: nop

;}
RECOMP_FUNC void func_80800D4C_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800D58: jal         0x80800AF4
    // 0x80800D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800AF4_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80800D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D60: jal         0x80800238
    // 0x80800D64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800238_bsbansack(rdram, ctx);
        goto after_1;
    // 0x80800D64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D70: jr          $ra
    // 0x80800D74: nop

    return;
    // 0x80800D74: nop

;}
RECOMP_FUNC void _gccubesearch_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088300: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x80088300);
    return;
    // 0x80088304: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void plcamera_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800104: jal         0x800F5EF8
    // 0x80800108: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F5EF8(rdram, ctx);
        goto after_0;
    // 0x80800108: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080010C: jal         0x80110014
    // 0x80800110: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_1;
    // 0x80800110: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800114: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800118: jal         0x80110720
    // 0x8080011C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80110720(rdram, ctx);
        goto after_2;
    // 0x8080011C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800128: jr          $ra
    // 0x8080012C: nop

    return;
    // 0x8080012C: nop

;}
RECOMP_FUNC void badrone_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808002EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002F0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x808002F4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808002F8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808002FC: jal         0x8009C128
    // 0x80800300: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800300: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80800304: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80800308: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8080030C: jal         0x800EFB24
    // 0x80800310: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x80800310: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80800314: jal         0x800EEFFC
    // 0x80800318: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800EEFFC(rdram, ctx);
        goto after_2;
    // 0x80800318: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x8080031C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800320: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800324: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800328: div.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080032C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800330: jal         0x8080027C
    // 0x80800334: nop

    badrone_entrypoint_15(rdram, ctx);
        goto after_3;
    // 0x80800334: nop

    after_3:
    // 0x80800338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080033C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800340: jr          $ra
    // 0x80800344: nop

    return;
    // 0x80800344: nop

;}
RECOMP_FUNC void badata_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BE4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800BE8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800BEC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BF0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800BF4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800BF8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800BFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C00: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(473, 0X1298) << 16);
    // 0x80800C04: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800C08: addiu       $a1, $a1, 0x1298
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X1298));
    // 0x80800C0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800C10: jal         0x80800AA4
    // 0x80800C14: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_80800AA4_badata(rdram, ctx);
        goto after_0;
    // 0x80800C14: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x80800C18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C20: jr          $ra
    // 0x80800C24: nop

    return;
    // 0x80800C24: nop

;}
RECOMP_FUNC void _bssplitup_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083AE8: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083AE8);
    return;
    // 0x80083AEC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80800008_bawobble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080000C: beq         $a1, $at, L_80800024
    if (ctx->r5 == ctx->r1) {
        // 0x80800010: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800024;
    }
    // 0x80800010: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800014: beql        $a1, $at, L_80800038
    if (ctx->r5 == ctx->r1) {
        // 0x80800018: lw          $v0, 0x154($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X154);
            goto L_80800038;
    }
    goto skip_0;
    // 0x80800018: lw          $v0, 0x154($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X154);
    skip_0:
    // 0x8080001C: b           L_80800044
    // 0x80800020: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
        goto L_80800044;
    // 0x80800020: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
L_80800024:
    // 0x80800024: lw          $v0, 0x154($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X154);
    // 0x80800028: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8080002C: b           L_80800040
    // 0x80800030: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
        goto L_80800040;
    // 0x80800030: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x80800034: lw          $v0, 0x154($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X154);
L_80800038:
    // 0x80800038: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8080003C: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
L_80800040:
    // 0x80800040: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
L_80800044:
    // 0x80800044: jr          $ra
    // 0x80800048: sb          $a1, 0x1C($t6)
    MEM_B(0X1C, ctx->r14) = ctx->r5;
    return;
    // 0x80800048: sb          $a1, 0x1C($t6)
    MEM_B(0X1C, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_800FB2AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB2AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FB2B0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800FB2B4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800FB2B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FB2BC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800FB2C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800FB2C4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800FB2C8: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800FB2CC: jal         0x800EFA4C
    // 0x800FB2D0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x800FB2D0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800FB2D4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800FB2D8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800FB2DC: jal         0x800EE780
    // 0x800FB2E0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800EE780(rdram, ctx);
        goto after_1;
    // 0x800FB2E0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x800FB2E4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800FB2E8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800FB2EC: jal         0x800EFB24
    // 0x800FB2F0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x800FB2F0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x800FB2F4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800FB2F8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800FB2FC: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x800FB300: jal         0x800BEF00
    // 0x800FB304: addiu       $a3, $zero, 0x1F00
    ctx->r7 = ADD32(0, 0X1F00);
    func_800BEF00(rdram, ctx);
        goto after_3;
    // 0x800FB304: addiu       $a3, $zero, 0x1F00
    ctx->r7 = ADD32(0, 0X1F00);
    after_3:
    // 0x800FB308: beq         $v0, $zero, L_800FB324
    if (ctx->r2 == 0) {
        // 0x800FB30C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800FB324;
    }
    // 0x800FB30C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800FB310: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800FB314: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800FB318: jal         0x800EE7F8
    // 0x800FB31C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x800FB31C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_4:
    // 0x800FB320: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800FB324:
    // 0x800FB324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FB328: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800FB32C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800FB330: jr          $ra
    // 0x800FB334: nop

    return;
    // 0x800FB334: nop

;}
RECOMP_FUNC void func_80801070_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801070: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801074: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801078: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080107C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80801080: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801084: jal         0x80100094
    // 0x80801088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080108C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80801090: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    // 0x80801094: lw          $a1, 0x18($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X18);
    // 0x80801098: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080109C: sll         $t7, $a1, 11
    ctx->r15 = S32(ctx->r5 << 11);
    // 0x808010A0: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x808010A4: jal         0x800DA298
    // 0x808010A8: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808010A8: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    after_1:
    // 0x808010AC: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x808010B0: beq         $v0, $zero, L_80801108
    if (ctx->r2 == 0) {
        // 0x808010B4: lw          $a1, 0x38($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X38);
            goto L_80801108;
    }
    // 0x808010B4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x808010B8: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x808010BC: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x808010C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808010C4: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x808010C8: bnel        $t0, $at, L_808012D0
    if (ctx->r8 != ctx->r1) {
        // 0x808010CC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808012D0;
    }
    goto skip_0;
    // 0x808010CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808010D0: jal         0x800DC128
    // 0x808010D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x808010D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x808010D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808010DC: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
    // 0x808010E0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808010E4: addiu       $a1, $v0, 0x103B
    ctx->r5 = ADD32(ctx->r2, 0X103B);
    // 0x808010E8: addiu       $a2, $zero, 0x144
    ctx->r6 = ADD32(0, 0X144);
    // 0x808010EC: jal         0x8008A208
    // 0x808010F0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x808010F0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808010F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010F8: jal         0x808012E0
    // 0x808010FC: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_4;
    // 0x808010FC: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_4:
    // 0x80801100: b           L_808012D0
    // 0x80801104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808012D0;
    // 0x80801104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801108:
    // 0x80801108: lh          $t2, 0x92($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X92);
    // 0x8080110C: addiu       $a3, $a1, -0x1
    ctx->r7 = ADD32(ctx->r5, -0X1);
    // 0x80801110: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80801114: bne         $t2, $zero, L_808011F0
    if (ctx->r10 != 0) {
        // 0x80801118: nop
    
            goto L_808011F0;
    }
    // 0x80801118: nop

    // 0x8080111C: bltz        $a3, L_808012CC
    if (SIGNED(ctx->r7) < 0) {
        // 0x80801120: slti        $at, $a3, 0x6
        ctx->r1 = SIGNED(ctx->r7) < 0X6 ? 1 : 0;
            goto L_808012CC;
    }
    // 0x80801120: slti        $at, $a3, 0x6
    ctx->r1 = SIGNED(ctx->r7) < 0X6 ? 1 : 0;
    // 0x80801124: beq         $at, $zero, L_808012CC
    if (ctx->r1 == 0) {
        // 0x80801128: addu        $t3, $v1, $a3
        ctx->r11 = ADD32(ctx->r3, ctx->r7);
            goto L_808012CC;
    }
    // 0x80801128: addu        $t3, $v1, $a3
    ctx->r11 = ADD32(ctx->r3, ctx->r7);
    // 0x8080112C: lbu         $t4, 0x1B($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1B);
    // 0x80801130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801134: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80801138: bne         $t4, $zero, L_808012CC
    if (ctx->r12 != 0) {
        // 0x8080113C: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_808012CC;
    }
    // 0x8080113C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80801140: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80801144: jal         0x808015F4
    // 0x80801148: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_808015F4_changlerboss(rdram, ctx);
        goto after_5;
    // 0x80801148: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_5:
    // 0x8080114C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801150: jal         0x808012E0
    // 0x80801154: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_6;
    // 0x80801154: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_6:
    // 0x80801158: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8080115C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80801160: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801164: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801168: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x8080116C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1332, 0X2DAC) << 16);
    // 0x80801170: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x80801174: addiu       $a2, $a2, 0x2DAC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1332, 0X2DAC));
    // 0x80801178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080117C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801180: jal         0x80089D18
    // 0x80801184: swc1        $f4, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f4.u32l;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80801184: swc1        $f4, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f4.u32l;
    after_7:
    // 0x80801188: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8080118C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80801190: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1332, 0X2F70) << 16);
    // 0x80801194: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80801198: subu        $t7, $t7, $a3
    ctx->r15 = SUB32(ctx->r15, ctx->r7);
    // 0x8080119C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808011A0: addu        $a1, $v1, $t7
    ctx->r5 = ADD32(ctx->r3, ctx->r15);
    // 0x808011A4: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    // 0x808011A8: addiu       $a2, $a2, 0x2F70
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1332, 0X2F70));
    // 0x808011AC: jal         0x80089D18
    // 0x808011B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x808011B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808011B4: jal         0x80801C50
    // 0x808011B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C50_changlerboss(rdram, ctx);
        goto after_9;
    // 0x808011B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808011BC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808011C0: bne         $v0, $at, L_808012CC
    if (ctx->r2 != ctx->r1) {
        // 0x808011C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808012CC;
    }
    // 0x808011C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011C8: jal         0x80109FE8
    // 0x808011CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_10;
    // 0x808011CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x808011D0: jal         0x808027F8
    // 0x808011D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808027F8_changlerboss(rdram, ctx);
        goto after_11;
    // 0x808011D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808011D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011DC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x808011E0: jal         0x808021E4
    // 0x808011E4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_808021E4_changlerboss(rdram, ctx);
        goto after_12;
    // 0x808011E4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_12:
    // 0x808011E8: b           L_808012D0
    // 0x808011EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808012D0;
    // 0x808011EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808011F0:
    // 0x808011F0: bnel        $a1, $at, L_808012D0
    if (ctx->r5 != ctx->r1) {
        // 0x808011F4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808012D0;
    }
    goto skip_1;
    // 0x808011F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808011F8: lh          $t8, 0x96($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X96);
    // 0x808011FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801200: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801204: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80801208: sh          $t9, 0x96($v1)
    MEM_H(0X96, ctx->r3) = ctx->r25;
    // 0x8080120C: lh          $v0, 0x96($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X96);
    // 0x80801210: bne         $v0, $zero, L_80801234
    if (ctx->r2 != 0) {
        // 0x80801214: nop
    
            goto L_80801234;
    }
    // 0x80801214: nop

    // 0x80801218: jal         0x80109FE8
    // 0x8080121C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_13;
    // 0x8080121C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80801220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801224: jal         0x808012E0
    // 0x80801228: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_14;
    // 0x80801228: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_14:
    // 0x8080122C: b           L_808012D0
    // 0x80801230: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808012D0;
    // 0x80801230: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801234:
    // 0x80801234: bne         $v0, $at, L_80801284
    if (ctx->r2 != ctx->r1) {
        // 0x80801238: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801284;
    }
    // 0x80801238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080123C: jal         0x80109FE8
    // 0x80801240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_15;
    // 0x80801240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80801244: jal         0x808027F8
    // 0x80801248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808027F8_changlerboss(rdram, ctx);
        goto after_16;
    // 0x80801248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080124C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801250: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80801254: jal         0x808021E4
    // 0x80801258: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_808021E4_changlerboss(rdram, ctx);
        goto after_17;
    // 0x80801258: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_17:
    // 0x8080125C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801260: jal         0x808012E0
    // 0x80801264: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_18;
    // 0x80801264: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_18:
    // 0x80801268: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1332, 0X2DAC) << 16);
    // 0x8080126C: addiu       $a2, $a2, 0x2DAC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1332, 0X2DAC));
    // 0x80801270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801274: jal         0x80089D18
    // 0x80801278: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_19;
    // 0x80801278: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_19:
    // 0x8080127C: b           L_808012D0
    // 0x80801280: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808012D0;
    // 0x80801280: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801284:
    // 0x80801284: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801288: bne         $v0, $at, L_808012B0
    if (ctx->r2 != ctx->r1) {
        // 0x8080128C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808012B0;
    }
    // 0x8080128C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801294: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80801298: jal         0x808012E0
    // 0x8080129C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_808012E0_changlerboss(rdram, ctx);
        goto after_20;
    // 0x8080129C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_20:
    // 0x808012A0: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x808012A4: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x808012A8: b           L_808012CC
    // 0x808012AC: sh          $t0, 0x94($v1)
    MEM_H(0X94, ctx->r3) = ctx->r8;
        goto L_808012CC;
    // 0x808012AC: sh          $t0, 0x94($v1)
    MEM_H(0X94, ctx->r3) = ctx->r8;
L_808012B0:
    // 0x808012B0: jal         0x808012E0
    // 0x808012B4: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_21;
    // 0x808012B4: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_21:
    // 0x808012B8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1332, 0X2DAC) << 16);
    // 0x808012BC: addiu       $a2, $a2, 0x2DAC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1332, 0X2DAC));
    // 0x808012C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012C4: jal         0x80089D18
    // 0x808012C8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_22;
    // 0x808012C8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_22:
L_808012CC:
    // 0x808012CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808012D0:
    // 0x808012D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808012D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808012D8: jr          $ra
    // 0x808012DC: nop

    return;
    // 0x808012DC: nop

;}
RECOMP_FUNC void func_800EB15C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB15C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EB160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EB164: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x800EB168: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800EB16C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800EB170: beql        $t7, $zero, L_800EB184
    if (ctx->r15 == 0) {
        // 0x800EB174: lw          $t8, 0x24($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X24);
            goto L_800EB184;
    }
    goto skip_0;
    // 0x800EB174: lw          $t8, 0x24($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X24);
    skip_0:
    // 0x800EB178: b           L_800EB200
    // 0x800EB17C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EB200;
    // 0x800EB17C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EB180: lw          $t8, 0x24($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X24);
L_800EB184:
    // 0x800EB184: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x800EB188: bne         $t9, $zero, L_800EB198
    if (ctx->r25 != 0) {
        // 0x800EB18C: nop
    
            goto L_800EB198;
    }
    // 0x800EB18C: nop

    // 0x800EB190: b           L_800EB200
    // 0x800EB194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EB200;
    // 0x800EB194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EB198:
    // 0x800EB198: jal         0x800D3948
    // 0x800EB19C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x800EB19C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800EB1A0: bne         $v0, $zero, L_800EB1FC
    if (ctx->r2 != 0) {
        // 0x800EB1A4: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_800EB1FC;
    }
    // 0x800EB1A4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800EB1A8: jal         0x800F54E4
    // 0x800EB1AC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x800EB1AC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x800EB1B0: jal         0x800F6774
    // 0x800EB1B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6774(rdram, ctx);
        goto after_2;
    // 0x800EB1B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800EB1B8: bne         $v0, $zero, L_800EB1FC
    if (ctx->r2 != 0) {
        // 0x800EB1BC: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_800EB1FC;
    }
    // 0x800EB1BC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800EB1C0: lhu         $t0, 0x18($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X18);
    // 0x800EB1C4: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x800EB1C8: beq         $t1, $zero, L_800EB1F4
    if (ctx->r9 == 0) {
        // 0x800EB1CC: nop
    
            goto L_800EB1F4;
    }
    // 0x800EB1CC: nop

    // 0x800EB1D0: jal         0x80106790
    // 0x800EB1D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x800EB1D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x800EB1D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800EB1DC: jal         0x80102F74
    // 0x800EB1E0: lui         $a1, 0x8800
    ctx->r5 = S32(0X8800 << 16);
    func_80102F74(rdram, ctx);
        goto after_4;
    // 0x800EB1E0: lui         $a1, 0x8800
    ctx->r5 = S32(0X8800 << 16);
    after_4:
    // 0x800EB1E4: beq         $v0, $zero, L_800EB1F4
    if (ctx->r2 == 0) {
        // 0x800EB1E8: nop
    
            goto L_800EB1F4;
    }
    // 0x800EB1E8: nop

    // 0x800EB1EC: b           L_800EB200
    // 0x800EB1F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EB200;
    // 0x800EB1F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EB1F4:
    // 0x800EB1F4: b           L_800EB200
    // 0x800EB1F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EB200;
    // 0x800EB1F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EB1FC:
    // 0x800EB1FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EB200:
    // 0x800EB200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EB204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EB208: jr          $ra
    // 0x800EB20C: nop

    return;
    // 0x800EB20C: nop

;}
RECOMP_FUNC void _suspline_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D88: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089D88);
    return;
    // 0x80089D8C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bsdronevanish_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080050C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800510: jal         0x808001E4
    // 0x80800514: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808001E4_bsdronevanish(rdram, ctx);
        goto after_0;
    // 0x80800514: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800518: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080051C: jal         0x800961AC
    // 0x80800520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_1;
    // 0x80800520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800524: jal         0x80092778
    // 0x80800528: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80092778(rdram, ctx);
        goto after_2;
    // 0x80800528: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080052C: jal         0x80085168
    // 0x80800530: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bastatemem_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800530: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080053C: jr          $ra
    // 0x80800540: nop

    return;
    // 0x80800540: nop

    // 0x80800544: nop

    // 0x80800548: nop

    // 0x8080054C: nop

;}
RECOMP_FUNC void func_808006C4_sccustom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808006C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808006D0: jal         0x800E7188
    // 0x808006D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800E7188(rdram, ctx);
        goto after_0;
    // 0x808006D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808006D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006DC: jal         0x8008A610
    // 0x808006E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _scinfobar_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x808006E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808006E4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808006E8: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x808006EC: beql        $at, $zero, L_808006FC
    if (ctx->r1 == 0) {
        // 0x808006F0: lui         $at, 0x41C0
        ctx->r1 = S32(0X41C0 << 16);
            goto L_808006FC;
    }
    goto skip_0;
    // 0x808006F0: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    skip_0:
    // 0x808006F4: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x808006F8: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
L_808006FC:
    // 0x808006FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800700: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80800704: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x80800708: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8080070C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800710: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800714: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800718: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080071C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800720: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800724: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800728: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8080072C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80800730: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80800734: trunc.w.s   $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800738: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8080073C: jr          $ra
    // 0x80800740: nop

    return;
    // 0x80800740: nop

;}
RECOMP_FUNC void func_80105854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105854: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105858: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010585C: jal         0x801054D4
    // 0x80105860: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_801054D4(rdram, ctx);
        goto after_0;
    // 0x80105860: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80105864: jal         0x80105A5C
    // 0x80105868: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80105A5C(rdram, ctx);
        goto after_1;
    // 0x80105868: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8010586C: beql        $v0, $zero, L_80105880
    if (ctx->r2 == 0) {
        // 0x80105870: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80105880;
    }
    goto skip_0;
    // 0x80105870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80105874: jal         0x800FFAB0
    // 0x80105878: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80105878: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8010587C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80105880:
    // 0x80105880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105884: jr          $ra
    // 0x80105888: nop

    return;
    // 0x80105888: nop

;}
RECOMP_FUNC void func_80109CC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109CC4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80109CC8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80109CCC: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80109CD0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80109CD4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80109CD8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80109CDC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80109CE0: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80109CE4: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80109CE8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80109CEC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80109CF0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80109CF4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80109CF8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80109CFC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80109D00: jal         0x800BE444
    // 0x80109D04: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    func_800BE444(rdram, ctx);
        goto after_0;
    // 0x80109D04: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    after_0:
    // 0x80109D08: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80109D0C: jal         0x800CB854
    // 0x80109D10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CB854(rdram, ctx);
        goto after_1;
    // 0x80109D10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80109D14: beq         $v0, $zero, L_80109D34
    if (ctx->r2 == 0) {
        // 0x80109D18: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_80109D34;
    }
    // 0x80109D18: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80109D1C: jal         0x800CB854
    // 0x80109D20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CB854(rdram, ctx);
        goto after_2;
    // 0x80109D20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80109D24: addiu       $t6, $v0, 0x1F
    ctx->r14 = ADD32(ctx->r2, 0X1F);
    // 0x80109D28: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80109D2C: b           L_80109D34
    // 0x80109D30: sllv        $s6, $t7, $t6
    ctx->r22 = S32(ctx->r15 << (ctx->r14 & 31));
        goto L_80109D34;
    // 0x80109D30: sllv        $s6, $t7, $t6
    ctx->r22 = S32(ctx->r15 << (ctx->r14 & 31));
L_80109D34:
    // 0x80109D34: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80109D38: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // 0x80109D3C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80109D40: beql        $a0, $zero, L_80109EAC
    if (ctx->r4 == 0) {
        // 0x80109D44: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80109EAC;
    }
    goto skip_0;
    // 0x80109D44: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
L_80109D48:
    // 0x80109D48: jal         0x800E9E88
    // 0x80109D4C: nop

    func_800E9E88(rdram, ctx);
        goto after_3;
    // 0x80109D4C: nop

    after_3:
    // 0x80109D50: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80109D54: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80109D58: jal         0x800E9EB4
    // 0x80109D5C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_4;
    // 0x80109D5C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_4:
    // 0x80109D60: sltu        $at, $s2, $v0
    ctx->r1 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x80109D64: beq         $at, $zero, L_80109E90
    if (ctx->r1 == 0) {
        // 0x80109D68: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_80109E90;
    }
    // 0x80109D68: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80109D6C: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
L_80109D70:
    // 0x80109D70: sll         $t1, $v0, 27
    ctx->r9 = S32(ctx->r2 << 27);
    // 0x80109D74: bgez        $t1, L_80109E80
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80109D78: andi        $t2, $v0, 0x1
        ctx->r10 = ctx->r2 & 0X1;
            goto L_80109E80;
    }
    // 0x80109D78: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x80109D7C: beql        $t2, $zero, L_80109E84
    if (ctx->r10 == 0) {
        // 0x80109D80: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_80109E84;
    }
    goto skip_1;
    // 0x80109D80: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    skip_1:
    // 0x80109D84: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80109D88: beql        $s0, $s3, L_80109E84
    if (ctx->r16 == ctx->r19) {
        // 0x80109D8C: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_80109E84;
    }
    goto skip_2;
    // 0x80109D8C: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    skip_2:
    // 0x80109D90: lw          $t3, 0x28($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X28);
    // 0x80109D94: sll         $t5, $t3, 22
    ctx->r13 = S32(ctx->r11 << 22);
    // 0x80109D98: bgezl       $t5, L_80109E84
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80109D9C: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_80109E84;
    }
    goto skip_3;
    // 0x80109D9C: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    skip_3:
    // 0x80109DA0: lhu         $t7, 0x18($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X18);
    // 0x80109DA4: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x80109DA8: beql        $t6, $zero, L_80109E84
    if (ctx->r14 == 0) {
        // 0x80109DAC: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_80109E84;
    }
    goto skip_4;
    // 0x80109DAC: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    skip_4:
    // 0x80109DB0: lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X14);
    // 0x80109DB4: beql        $v0, $zero, L_80109E84
    if (ctx->r2 == 0) {
        // 0x80109DB8: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_80109E84;
    }
    goto skip_5;
    // 0x80109DB8: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    skip_5:
    // 0x80109DBC: beql        $s5, $v0, L_80109E84
    if (ctx->r21 == ctx->r2) {
        // 0x80109DC0: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_80109E84;
    }
    goto skip_6;
    // 0x80109DC0: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    skip_6:
    // 0x80109DC4: lw          $t8, 0x24($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X24);
    // 0x80109DC8: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x80109DCC: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x80109DD0: srl         $t1, $t0, 22
    ctx->r9 = S32(U32(ctx->r8) >> 22);
    // 0x80109DD4: beql        $t9, $t1, L_80109E84
    if (ctx->r25 == ctx->r9) {
        // 0x80109DD8: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_80109E84;
    }
    goto skip_7;
    // 0x80109DD8: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    skip_7:
    // 0x80109DDC: jal         0x80106790
    // 0x80109DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80109DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80109DE4: lw          $t2, 0x64($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X64);
    // 0x80109DE8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80109DEC: sll         $t4, $t2, 14
    ctx->r12 = S32(ctx->r10 << 14);
    // 0x80109DF0: bltzl       $t4, L_80109E84
    if (SIGNED(ctx->r12) < 0) {
        // 0x80109DF4: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_80109E84;
    }
    goto skip_8;
    // 0x80109DF4: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    skip_8:
    // 0x80109DF8: lhu         $t5, 0x66($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X66);
    // 0x80109DFC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80109E00: and         $t7, $t5, $s6
    ctx->r15 = ctx->r13 & ctx->r22;
    // 0x80109E04: bnel        $t7, $zero, L_80109E84
    if (ctx->r15 != 0) {
        // 0x80109E08: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_80109E84;
    }
    goto skip_9;
    // 0x80109E08: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    skip_9:
    // 0x80109E0C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80109E10: jal         0x801098D0
    // 0x80109E14: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_801098D0(rdram, ctx);
        goto after_6;
    // 0x80109E14: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_6:
    // 0x80109E18: beql        $v0, $zero, L_80109E84
    if (ctx->r2 == 0) {
        // 0x80109E1C: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_80109E84;
    }
    goto skip_10;
    // 0x80109E1C: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    skip_10:
    // 0x80109E20: jal         0x800EC3C4
    // 0x80109E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EC3C4(rdram, ctx);
        goto after_7;
    // 0x80109E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80109E28: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x80109E2C: beql        $t6, $zero, L_80109E54
    if (ctx->r14 == 0) {
        // 0x80109E30: lbu         $t0, 0x73($s1)
        ctx->r8 = MEM_BU(ctx->r17, 0X73);
            goto L_80109E54;
    }
    goto skip_11;
    // 0x80109E30: lbu         $t0, 0x73($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X73);
    skip_11:
    // 0x80109E34: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x80109E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80109E3C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80109E40: jalr        $t9
    // 0x80109E44: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x80109E44: nop

    after_8:
    // 0x80109E48: beql        $v0, $zero, L_80109E84
    if (ctx->r2 == 0) {
        // 0x80109E4C: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_80109E84;
    }
    goto skip_12;
    // 0x80109E4C: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    skip_12:
    // 0x80109E50: lbu         $t0, 0x73($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X73);
L_80109E54:
    // 0x80109E54: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80109E58: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80109E5C: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x80109E60: sb          $t1, 0x73($s1)
    MEM_B(0X73, ctx->r17) = ctx->r9;
    // 0x80109E64: jal         0x80088610
    // 0x80109E68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _glhittableDll_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80109E68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x80109E6C: bne         $v0, $zero, L_80109E80
    if (ctx->r2 != 0) {
        // 0x80109E70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80109E80;
    }
    // 0x80109E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80109E74: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80109E78: jal         0x800EB210
    // 0x80109E7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800EB210(rdram, ctx);
        goto after_10;
    // 0x80109E7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
L_80109E80:
    // 0x80109E80: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
L_80109E84:
    // 0x80109E84: sltu        $at, $s2, $s4
    ctx->r1 = ctx->r18 < ctx->r20 ? 1 : 0;
    // 0x80109E88: bnel        $at, $zero, L_80109D70
    if (ctx->r1 != 0) {
        // 0x80109E8C: lw          $v0, 0x8($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X8);
            goto L_80109D70;
    }
    goto skip_13;
    // 0x80109E8C: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    skip_13:
L_80109E90:
    // 0x80109E90: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x80109E94: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80109E98: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80109E9C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80109EA0: bne         $a0, $zero, L_80109D48
    if (ctx->r4 != 0) {
        // 0x80109EA4: nop
    
            goto L_80109D48;
    }
    // 0x80109EA4: nop

    // 0x80109EA8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80109EAC:
    // 0x80109EAC: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x80109EB0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80109EB4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80109EB8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80109EBC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80109EC0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80109EC4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80109EC8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80109ECC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80109ED0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80109ED4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80109ED8: jr          $ra
    // 0x80109EDC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80109EDC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800F44_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800F48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F4C: jal         0x80106790
    // 0x80800F50: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800F50: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800F54: lhu         $t6, 0x72($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X72);
    // 0x80800F58: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800F5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F60: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800F64: beql        $t7, $at, L_80800F9C
    if (ctx->r15 == ctx->r1) {
        // 0x80800F68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800F9C;
    }
    goto skip_0;
    // 0x80800F68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800F6C: lw          $t8, 0x78($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X78);
    // 0x80800F70: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800F74: sll         $t0, $t8, 29
    ctx->r8 = S32(ctx->r24 << 29);
    // 0x80800F78: bltzl       $t0, L_80800F9C
    if (SIGNED(ctx->r8) < 0) {
        // 0x80800F7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800F9C;
    }
    goto skip_1;
    // 0x80800F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800F80: jal         0x801021BC
    // 0x80800F84: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_801021BC(rdram, ctx);
        goto after_1;
    // 0x80800F84: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800F88: beq         $v0, $zero, L_80800F98
    if (ctx->r2 == 0) {
        // 0x80800F8C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80800F98;
    }
    // 0x80800F8C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F90: jal         0x808014AC
    // 0x80800F94: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_2;
    // 0x80800F94: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_2:
L_80800F98:
    // 0x80800F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F9C:
    // 0x80800F9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800FA0: jr          $ra
    // 0x80800FA4: nop

    return;
    // 0x80800FA4: nop

;}
RECOMP_FUNC void func_80800000_ncbasuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80112524
    // 0x8080000C: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800018: jr          $ra
    // 0x8080001C: nop

    return;
    // 0x8080001C: nop

;}
RECOMP_FUNC void func_800D5E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5E94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D5E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D5E9C: jal         0x800D54F0
    // 0x800D5EA0: nop

    func_800D54F0(rdram, ctx);
        goto after_0;
    // 0x800D5EA0: nop

    after_0:
    // 0x800D5EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D5EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D5EAC: jr          $ra
    // 0x800D5EB0: nop

    return;
    // 0x800D5EB0: nop

;}
RECOMP_FUNC void func_80801814_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801814: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801818: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080181C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801820: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801824: jal         0x80100094
    // 0x80801828: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801828: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080182C: jal         0x80088398
    // 0x80801830: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    _gcstatusDll_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x80801830: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x80801834: beq         $v0, $zero, L_80801880
    if (ctx->r2 == 0) {
        // 0x80801838: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80801880;
    }
    // 0x80801838: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080183C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80801840: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80801844: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801848: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080184C: sb          $v0, 0x55A($s0)
    MEM_B(0X55A, ctx->r16) = ctx->r2;
    // 0x80801850: sb          $zero, 0x55B($s0)
    MEM_B(0X55B, ctx->r16) = 0;
    // 0x80801854: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2216, 0X2188) << 16);
    // 0x80801858: lwc1        $f16, 0x2188($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2216, 0X2188));
    // 0x8080185C: lui         $a1, 0x412F
    ctx->r5 = S32(0X412F << 16);
    // 0x80801860: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801864: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80801868: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080186C: swc1        $f18, 0x55C($s0)
    MEM_W(0X55C, ctx->r16) = ctx->f18.u32l;
    // 0x80801870: jal         0x80801A8C
    // 0x80801874: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80801A8C_chfpsgame(rdram, ctx);
        goto after_2;
    // 0x80801874: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80801878: b           L_80801898
    // 0x8080187C: lwc1        $f6, 0x55C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X55C);
        goto L_80801898;
    // 0x8080187C: lwc1        $f6, 0x55C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X55C);
L_80801880:
    // 0x80801880: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801884: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80801888: swc1        $f4, 0x55C($s0)
    MEM_W(0X55C, ctx->r16) = ctx->f4.u32l;
    // 0x8080188C: jal         0x80801A8C
    // 0x80801890: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80801A8C_chfpsgame(rdram, ctx);
        goto after_3;
    // 0x80801890: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80801894: lwc1        $f6, 0x55C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X55C);
L_80801898:
    // 0x80801898: swc1        $f6, 0x560($s0)
    MEM_W(0X560, ctx->r16) = ctx->f6.u32l;
    // 0x8080189C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808018A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808018A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808018A8: jr          $ra
    // 0x808018AC: nop

    return;
    // 0x808018AC: nop

;}
RECOMP_FUNC void func_800F79DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F79DC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F79E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F79E4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F79E8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F79EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F79F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F79F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F79F8: jal         0x8009AD20
    // 0x800F79FC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009AD20(rdram, ctx);
        goto after_0;
    // 0x800F79FC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F7A00: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7A04: jal         0x8009AD14
    // 0x800F7A08: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8009AD14(rdram, ctx);
        goto after_1;
    // 0x800F7A08: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800F7A0C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7A10: jal         0x8009E7C8
    // 0x800F7A14: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    func_8009E7C8(rdram, ctx);
        goto after_2;
    // 0x800F7A14: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_2:
    // 0x800F7A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7A1C: xori        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 ^ 0X2;
    // 0x800F7A20: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800F7A24: jr          $ra
    // 0x800F7A28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F7A28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _chhandcart_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B08: syscall     415
    recomp_syscall_handler(rdram, ctx, 0x80086B08);
    return;
    // 0x80086B0C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chicekeydoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800634: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2468, 0X930) << 16);
    // 0x80800638: jr          $ra
    // 0x8080063C: addiu       $v0, $v0, 0x930
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2468, 0X930));
    return;
    // 0x8080063C: addiu       $v0, $v0, 0x930
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2468, 0X930));
;}
RECOMP_FUNC void _chballoonburst_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085EC8: syscall     257
    recomp_syscall_handler(rdram, ctx, 0x80085EC8);
    return;
    // 0x80085ECC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800F7A2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7A2C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7A30: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7A34: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7A38: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7A3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7A40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7A44: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F7A48: jal         0x8009AD20
    // 0x800F7A4C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009AD20(rdram, ctx);
        goto after_0;
    // 0x800F7A4C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F7A50: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7A54: jal         0x8009AD44
    // 0x800F7A58: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8009AD44(rdram, ctx);
        goto after_1;
    // 0x800F7A58: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800F7A5C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7A60: jal         0x8009E7C8
    // 0x800F7A64: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_8009E7C8(rdram, ctx);
        goto after_2;
    // 0x800F7A64: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_2:
    // 0x800F7A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7A6C: xori        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 ^ 0X2;
    // 0x800F7A70: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800F7A74: jr          $ra
    // 0x800F7A78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F7A78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _bsblongleg_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A20: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A20);
    return;
    // 0x80082A24: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80800518_chspotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800518: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080051C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800520: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800524: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800528: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080052C: jal         0x80102780
    // 0x80800530: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80102780(rdram, ctx);
        goto after_0;
    // 0x80800530: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80800534: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800538: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8080053C: addiu       $a0, $a0, 0x17D0
    ctx->r4 = ADD32(ctx->r4, 0X17D0);
    // 0x80800540: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800544: jal         0x800DF47C
    // 0x80800548: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    func_800DF47C(rdram, ctx);
        goto after_1;
    // 0x80800548: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8080054C: jal         0x8010347C
    // 0x80800550: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8010347C(rdram, ctx);
        goto after_2;
    // 0x80800550: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x80800554: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800558: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8080055C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800560: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800564: jal         0x800DE448
    // 0x80800568: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800DE448(rdram, ctx);
        goto after_3;
    // 0x80800568: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8080056C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800570: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800574: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800578: jr          $ra
    // 0x8080057C: nop

    return;
    // 0x8080057C: nop

;}
RECOMP_FUNC void func_808007D4_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007DC: jal         0x80800130
    // 0x808007E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800130_bsstatue(rdram, ctx);
        goto after_0;
    // 0x808007E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808007E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808007E8: jal         0x8080054C
    // 0x808007EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080054C_bsstatue(rdram, ctx);
        goto after_1;
    // 0x808007EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808007F0: jal         0x8009E704
    // 0x808007F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bs_getNextState(rdram, ctx);
        goto after_2;
    // 0x808007F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808007F8: addiu       $at, $zero, 0xF9
    ctx->r1 = ADD32(0, 0XF9);
    // 0x808007FC: bne         $v0, $at, L_8080080C
    if (ctx->r2 != ctx->r1) {
        // 0x80800800: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080080C;
    }
    // 0x80800800: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800804: jal         0x8009B9B0
    // 0x80800808: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800808: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
L_8080080C:
    // 0x8080080C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800810: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800814: jr          $ra
    // 0x80800818: nop

    return;
    // 0x80800818: nop

;}
RECOMP_FUNC void func_80096524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096524: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80096528: jr          $ra
    // 0x8009652C: lbu         $v0, 0xA0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XA0);
    return;
    // 0x8009652C: lbu         $v0, 0xA0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XA0);
;}
RECOMP_FUNC void func_80014F64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014F64: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80014F68: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014F6C: addiu       $v0, $v0, -0x7030
    ctx->r2 = ADD32(ctx->r2, -0X7030);
    // 0x80014F70: addiu       $v1, $v1, -0x7070
    ctx->r3 = ADD32(ctx->r3, -0X7070);
    // 0x80014F74: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_80014F78:
    // 0x80014F78: bnel        $t6, $zero, L_80014F90
    if (ctx->r14 != 0) {
        // 0x80014F7C: lw          $t7, 0x8($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X8);
            goto L_80014F90;
    }
    goto skip_0;
    // 0x80014F7C: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    skip_0:
    // 0x80014F80: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80014F84: jr          $ra
    // 0x80014F88: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    return;
    // 0x80014F88: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x80014F8C: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
L_80014F90:
    // 0x80014F90: bnel        $t7, $zero, L_80014FA8
    if (ctx->r15 != 0) {
        // 0x80014F94: lw          $t8, 0x10($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X10);
            goto L_80014FA8;
    }
    goto skip_1;
    // 0x80014F94: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    skip_1:
    // 0x80014F98: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x80014F9C: jr          $ra
    // 0x80014FA0: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    return;
    // 0x80014FA0: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x80014FA4: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
L_80014FA8:
    // 0x80014FA8: bnel        $t8, $zero, L_80014FC0
    if (ctx->r24 != 0) {
        // 0x80014FAC: lw          $t9, 0x18($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X18);
            goto L_80014FC0;
    }
    goto skip_2;
    // 0x80014FAC: lw          $t9, 0x18($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X18);
    skip_2:
    // 0x80014FB0: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
    // 0x80014FB4: jr          $ra
    // 0x80014FB8: sw          $a1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r5;
    return;
    // 0x80014FB8: sw          $a1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r5;
    // 0x80014FBC: lw          $t9, 0x18($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X18);
L_80014FC0:
    // 0x80014FC0: bnel        $t9, $zero, L_80014FD8
    if (ctx->r25 != 0) {
        // 0x80014FC4: addiu       $v1, $v1, 0x20
        ctx->r3 = ADD32(ctx->r3, 0X20);
            goto L_80014FD8;
    }
    goto skip_3;
    // 0x80014FC4: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    skip_3:
    // 0x80014FC8: sw          $a0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r4;
    // 0x80014FCC: jr          $ra
    // 0x80014FD0: sw          $a1, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r5;
    return;
    // 0x80014FD0: sw          $a1, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r5;
    // 0x80014FD4: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
L_80014FD8:
    // 0x80014FD8: bnel        $v1, $v0, L_80014F78
    if (ctx->r3 != ctx->r2) {
        // 0x80014FDC: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_80014F78;
    }
    goto skip_4;
    // 0x80014FDC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_4:
    // 0x80014FE0: jr          $ra
    // 0x80014FE4: nop

    return;
    // 0x80014FE4: nop

;}
RECOMP_FUNC void func_800D93A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D93A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D93A4: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x800D93A8: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x800D93AC: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x800D93B0: sdc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X20, ctx->r29);
    // 0x800D93B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800D93B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D93BC: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800D93C0: lwc1        $f20, 0x4($a1)
    ctx->f20.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800D93C4: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800D93C8: lwc1        $f22, 0x8($a1)
    ctx->f22.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800D93CC: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800D93D0: sw          $ra, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r31;
    // 0x800D93D4: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800D93D8: jal         0x800137AC
    // 0x800D93DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    func_800137AC(rdram, ctx);
        goto after_0;
    // 0x800D93DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D93E0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800D93E4: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x800D93E8: jal         0x800137AC
    // 0x800D93EC: mov.s       $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    ctx->f26.fl = ctx->f2.fl;
    func_800137AC(rdram, ctx);
        goto after_1;
    // 0x800D93EC: mov.s       $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    ctx->f26.fl = ctx->f2.fl;
    after_1:
    // 0x800D93F0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x800D93F4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800D93F8: jal         0x800137AC
    // 0x800D93FC: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    func_800137AC(rdram, ctx);
        goto after_2;
    // 0x800D93FC: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    after_2:
    // 0x800D9400: mul.s       $f4, $f24, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x800D9404: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x800D9408: mul.s       $f8, $f26, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x800D940C: lw          $ra, 0x4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4);
    // 0x800D9410: mul.s       $f6, $f24, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f22.fl);
    // 0x800D9414: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x800D9418: mul.s       $f10, $f26, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f22.fl);
    // 0x800D941C: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x800D9420: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800D9424: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x800D9428: mul.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800D942C: ldc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X20);
    // 0x800D9430: mul.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800D9434: add.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x800D9438: mul.s       $f18, $f8, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800D943C: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x800D9440: mul.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800D9444: sub.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800D9448: mul.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800D944C: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x800D9450: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800D9454: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800D9458: mul.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800D945C: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
    // 0x800D9460: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800D9464: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
    // 0x800D9468: jr          $ra
    // 0x800D946C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D946C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80801A10_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801A14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801A18: addiu       $at, $zero, 0x4F
    ctx->r1 = ADD32(0, 0X4F);
    // 0x80801A1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801A20: bne         $a1, $at, L_80801A7C
    if (ctx->r5 != ctx->r1) {
        // 0x80801A24: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80801A7C;
    }
    // 0x80801A24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801A28: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80801A2C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801A30: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801A34: beq         $t7, $at, L_80801A74
    if (ctx->r15 == ctx->r1) {
        // 0x80801A38: nop
    
            goto L_80801A74;
    }
    // 0x80801A38: nop

    // 0x80801A3C: beq         $a2, $zero, L_80801A60
    if (ctx->r6 == 0) {
        // 0x80801A40: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_80801A60;
    }
    // 0x80801A40: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80801A44: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80801A48: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1016, 0X1F98) << 16);
    // 0x80801A4C: addiu       $a3, $a3, 0x1F98
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1016, 0X1F98));
    // 0x80801A50: andi        $t8, $a1, 0x1
    ctx->r24 = ctx->r5 & 0X1;
    // 0x80801A54: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80801A58: jal         0x8010D930
    // 0x80801A5C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_8010D930(rdram, ctx);
        goto after_0;
    // 0x80801A5C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_0:
L_80801A60:
    // 0x80801A60: jal         0x80089CB8
    // 0x80801A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80801A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A6C: jal         0x80101FDC
    // 0x80801A70: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80801A70: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
L_80801A74:
    // 0x80801A74: b           L_80801A80
    // 0x80801A78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801A80;
    // 0x80801A78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801A7C:
    // 0x80801A7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801A80:
    // 0x80801A80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801A88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801A8C: jr          $ra
    // 0x80801A90: nop

    return;
    // 0x80801A90: nop

;}
RECOMP_FUNC void func_80800130_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800134: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1608, 0X5088) << 16);
    // 0x80800138: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080013C: jr          $ra
    // 0x80800140: lw          $v0, 0x5088($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(1608, 0X5088));
    return;
    // 0x80800140: lw          $v0, 0x5088($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(1608, 0X5088));
;}
RECOMP_FUNC void sukickball_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FF0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800FF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800FF8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800FFC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80801000: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80801004: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801008: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080100C: jal         0x80100094
    // 0x80801010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801014: lbu         $t6, 0x39($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X39);
    // 0x80801018: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080101C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801020: beq         $t6, $at, L_80801060
    if (ctx->r14 == ctx->r1) {
        // 0x80801024: addiu       $s3, $zero, 0x4
        ctx->r19 = ADD32(0, 0X4);
            goto L_80801060;
    }
    // 0x80801024: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x80801028: addiu       $s1, $sp, 0x2C
    ctx->r17 = ADD32(ctx->r29, 0X2C);
    // 0x8080102C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80801030:
    // 0x80801030: jal         0x80800988
    // 0x80801034: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    sukickball_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80801034: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80801038: beq         $v0, $zero, L_80801054
    if (ctx->r2 == 0) {
        // 0x8080103C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801054;
    }
    // 0x8080103C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801040: jal         0x80800F54
    // 0x80801044: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    sukickball_entrypoint_16(rdram, ctx);
        goto after_2;
    // 0x80801044: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80801048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080104C: jal         0x800F8294
    // 0x80801050: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F8294(rdram, ctx);
        goto after_3;
    // 0x80801050: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
L_80801054:
    // 0x80801054: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801058: bnel        $s0, $s3, L_80801030
    if (ctx->r16 != ctx->r19) {
        // 0x8080105C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801030;
    }
    goto skip_0;
    // 0x8080105C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
L_80801060:
    // 0x80801060: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801064: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801068: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080106C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801070: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801074: jr          $ra
    // 0x80801078: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80801078: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void subaddiepalette_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8080007C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80800080: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80800084: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80800088: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8080008C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80800090: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80800094: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80800098: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8080009C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x808000A0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808000A4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x808000A8: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x808000AC: lh          $v0, 0x4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X4);
    // 0x808000B0: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x808000B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000B8: beql        $v0, $zero, L_80800190
    if (ctx->r2 == 0) {
        // 0x808000BC: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80800190;
    }
    goto skip_0;
    // 0x808000BC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x808000C0: bnel        $v0, $at, L_80800190
    if (ctx->r2 != ctx->r1) {
        // 0x808000C4: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80800190;
    }
    goto skip_1;
    // 0x808000C4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x808000C8: jal         0x800D9078
    // 0x808000CC: addiu       $a0, $a1, 0x8
    ctx->r4 = ADD32(ctx->r5, 0X8);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x808000CC: addiu       $a0, $a1, 0x8
    ctx->r4 = ADD32(ctx->r5, 0X8);
    after_0:
    // 0x808000D0: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x808000D4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808000D8: lw          $a2, 0xC($fp)
    ctx->r6 = MEM_W(ctx->r30, 0XC);
    // 0x808000DC: lwc1        $f12, 0x8($fp)
    ctx->f12.u32l = MEM_W(ctx->r30, 0X8);
    // 0x808000E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808000E4: jal         0x800F12D4
    // 0x808000E8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F12D4(rdram, ctx);
        goto after_1;
    // 0x808000E8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x808000EC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808000F0: jal         0x800D674C
    // 0x808000F4: lhu         $a0, 0x2($fp)
    ctx->r4 = MEM_HU(ctx->r30, 0X2);
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x808000F4: lhu         $a0, 0x2($fp)
    ctx->r4 = MEM_HU(ctx->r30, 0X2);
    after_2:
    // 0x808000F8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808000FC: jal         0x800D674C
    // 0x80800100: lhu         $a0, 0x0($fp)
    ctx->r4 = MEM_HU(ctx->r30, 0X0);
    func_800D674C(rdram, ctx);
        goto after_3;
    // 0x80800100: lhu         $a0, 0x0($fp)
    ctx->r4 = MEM_HU(ctx->r30, 0X0);
    after_3:
    // 0x80800104: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80800108: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080010C: addiu       $s7, $fp, 0x10
    ctx->r23 = ADD32(ctx->r30, 0X10);
    // 0x80800110: addiu       $s4, $zero, 0x200
    ctx->r20 = ADD32(0, 0X200);
    // 0x80800114: addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
    // 0x80800118: addiu       $s2, $sp, 0x80
    ctx->r18 = ADD32(ctx->r29, 0X80);
    // 0x8080011C: addiu       $s1, $sp, 0x90
    ctx->r17 = ADD32(ctx->r29, 0X90);
    // 0x80800120: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80800124:
    // 0x80800124: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800128: jal         0x80087958
    // 0x8080012C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    _dbpalette_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x8080012C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_4:
    // 0x80800130: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800134: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800138: jal         0x80087958
    // 0x8080013C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    _dbpalette_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x8080013C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_5:
    // 0x80800140: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800144: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800148: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080014C: jal         0x800F3214
    // 0x80800150: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800F3214(rdram, ctx);
        goto after_6;
    // 0x80800150: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_6:
    // 0x80800154: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800158: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080015C: jal         0x80087960
    // 0x80800160: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    _dbpalette_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800160: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_7:
    // 0x80800164: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800168: bnel        $s0, $s4, L_80800124
    if (ctx->r16 != ctx->r20) {
        // 0x8080016C: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80800124;
    }
    goto skip_2;
    // 0x8080016C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_2:
    // 0x80800170: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80800174: jal         0x808002BC
    // 0x80800178: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    subaddiepalette_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800178: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_8:
    // 0x8080017C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80800180: beql        $t6, $zero, L_80800190
    if (ctx->r14 == 0) {
        // 0x80800184: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80800190;
    }
    goto skip_3;
    // 0x80800184: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_3:
    // 0x80800188: sh          $zero, 0x4($fp)
    MEM_H(0X4, ctx->r30) = 0;
    // 0x8080018C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80800190:
    // 0x80800190: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800194: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800198: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8080019C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808001A0: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x808001A4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x808001A8: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x808001AC: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x808001B0: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x808001B4: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x808001B8: jr          $ra
    // 0x808001BC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x808001BC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void _chphlegm_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086018: syscall     271
    recomp_syscall_handler(rdram, ctx, 0x80086018);
    return;
    // 0x8008601C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _suquiz_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A860: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A860);
    return;
    // 0x8008A864: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void mlMtxPop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018DAC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80018DB0: addiu       $v0, $v0, -0x4350
    ctx->r2 = ADD32(ctx->r2, -0X4350);
    // 0x80018DB4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80018DB8: addiu       $t7, $t6, -0x40
    ctx->r15 = ADD32(ctx->r14, -0X40);
    // 0x80018DBC: jr          $ra
    // 0x80018DC0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x80018DC0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void baflag_getStuctSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800956E0: jr          $ra
    // 0x800956E4: addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
    return;
    // 0x800956E4: addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
;}
RECOMP_FUNC void _bsjump_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083260: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x80083260);
    return;
    // 0x80083264: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
