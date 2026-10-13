#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080082C_chmadamegrunty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080082C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800830: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800834: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800838: jal         0x80101FDC
    // 0x8080083C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x8080083C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800840: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800844: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800848: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080084C: bnel        $t6, $at, L_8080088C
    if (ctx->r14 != ctx->r1) {
        // 0x80800850: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080088C;
    }
    goto skip_0;
    // 0x80800850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800854: jal         0x8008A4B0
    // 0x80800858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080085C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800860: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800864: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800868: addiu       $t8, $zero, 0x43
    ctx->r24 = ADD32(0, 0X43);
    // 0x8080086C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80800870: swc1        $f4, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f4.u32l;
    // 0x80800874: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800878: addiu       $a1, $zero, 0x10CA
    ctx->r5 = ADD32(0, 0X10CA);
    // 0x8080087C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800880: jal         0x8008A208
    // 0x80800884: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800884: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80800888: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080088C:
    // 0x8080088C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800890: jr          $ra
    // 0x80800894: nop

    return;
    // 0x80800894: nop

;}
RECOMP_FUNC void _babee_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084558: syscall     114
    recomp_syscall_handler(rdram, ctx, 0x80084558);
    return;
    // 0x8008455C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800BDC_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BE0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(880, 0X1498) << 16);
    // 0x80800BE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BE8: addiu       $t6, $t6, 0x1498
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(880, 0X1498));
    // 0x80800BEC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800BF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800BF4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800BF8: jal         0x800BBCB8
    // 0x80800BFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800BFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80800C00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C08: jr          $ra
    // 0x80800C0C: nop

    return;
    // 0x80800C0C: nop

;}
RECOMP_FUNC void bskazfly_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013A8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808013AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(236, 0X1C68) << 16);
    // 0x808013B0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808013B4: jr          $ra
    // 0x808013B8: lw          $v0, 0x1C68($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1C68));
    return;
    // 0x808013B8: lw          $v0, 0x1C68($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1C68));
;}
RECOMP_FUNC void func_80802E80_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802E80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802E84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802E88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802E8C: jal         0x800169A8
    // 0x80802E90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800169A8(rdram, ctx);
        goto after_0;
    // 0x80802E90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80802E94: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80802E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802E9C: jal         0x80100094
    // 0x80802EA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80802EA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80802EA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802EA8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80802EAC: jal         0x800EE7F8
    // 0x80802EB0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80802EB0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80802EB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802EB8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80802EBC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X3AA4) << 16);
    // 0x80802EC0: lwc1        $f4, 0x3AA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X3AA4));
    // 0x80802EC4: lui         $at, 0x426C
    ctx->r1 = S32(0X426C << 16);
    // 0x80802EC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802ECC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80802ED0: lui         $at, 0x427C
    ctx->r1 = S32(0X427C << 16);
    // 0x80802ED4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802ED8: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80802EDC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802EE0: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    // 0x80802EE4: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x80802EE8: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
    // 0x80802EEC: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    // 0x80802EF0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80802EF4: swc1        $f0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f0.u32l;
    // 0x80802EF8: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x80802EFC: sw          $v0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r2;
    // 0x80802F00: sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
    // 0x80802F04: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80802F08: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80802F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802F10: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80802F14: addiu       $a1, $zero, 0xB9
    ctx->r5 = ADD32(0, 0XB9);
    // 0x80802F18: swc1        $f2, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f2.u32l;
    // 0x80802F1C: swc1        $f2, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f2.u32l;
    // 0x80802F20: jal         0x80089C98
    // 0x80802F24: sw          $t7, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r15;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80802F24: sw          $t7, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r15;
    after_3:
    // 0x80802F28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802F2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802F30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802F34: jr          $ra
    // 0x80802F38: nop

    return;
    // 0x80802F38: nop

;}
RECOMP_FUNC void func_800E084C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E084C: sll         $t0, $a2, 5
    ctx->r8 = S32(ctx->r6 << 5);
    // 0x800E0850: sll         $t1, $a2, 3
    ctx->r9 = S32(ctx->r6 << 3);
    // 0x800E0854: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x800E0858: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800E085C: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x800E0860: lw          $t0, 0xC($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XC);
    // 0x800E0864: lw          $t1, 0x10($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X10);
    // 0x800E0868: lw          $t2, 0x14($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X14);
    // 0x800E086C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    // 0x800E0870: sw          $t1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r9;
    // 0x800E0874: sw          $t2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r10;
    // 0x800E0878: lw          $t0, 0x18($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X18);
    // 0x800E087C: lw          $t1, 0x1C($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X1C);
    // 0x800E0880: lw          $t2, 0x20($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X20);
    // 0x800E0884: sw          $t0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r8;
    // 0x800E0888: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x800E088C: sw          $t2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r10;
    // 0x800E0890: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E0894: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x800E0898: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x800E089C: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x800E08A0: sdc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X20, ctx->r29);
    // 0x800E08A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800E08A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E08AC: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800E08B0: lwc1        $f20, 0x4($a1)
    ctx->f20.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800E08B4: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800E08B8: lwc1        $f22, 0x8($a1)
    ctx->f22.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800E08BC: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800E08C0: sw          $ra, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r31;
    // 0x800E08C4: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800E08C8: jal         0x800137AC
    // 0x800E08CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    func_800137AC(rdram, ctx);
        goto after_0;
    // 0x800E08CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    after_0:
    // 0x800E08D0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800E08D4: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x800E08D8: jal         0x800137AC
    // 0x800E08DC: mov.s       $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    ctx->f26.fl = ctx->f2.fl;
    func_800137AC(rdram, ctx);
        goto after_1;
    // 0x800E08DC: mov.s       $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    ctx->f26.fl = ctx->f2.fl;
    after_1:
    // 0x800E08E0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x800E08E4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800E08E8: jal         0x800137AC
    // 0x800E08EC: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    func_800137AC(rdram, ctx);
        goto after_2;
    // 0x800E08EC: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    after_2:
    // 0x800E08F0: mul.s       $f4, $f24, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x800E08F4: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x800E08F8: mul.s       $f8, $f26, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x800E08FC: lw          $ra, 0x4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4);
    // 0x800E0900: mul.s       $f6, $f24, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f22.fl);
    // 0x800E0904: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x800E0908: mul.s       $f10, $f26, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f22.fl);
    // 0x800E090C: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x800E0910: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800E0914: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x800E0918: mul.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800E091C: ldc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X20);
    // 0x800E0920: mul.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800E0924: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800E0928: mul.s       $f18, $f8, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800E092C: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x800E0930: mul.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800E0934: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800E0938: mul.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800E093C: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x800E0940: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800E0944: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800E0948: mul.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800E094C: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
    // 0x800E0950: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800E0954: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
    // 0x800E0958: jr          $ra
    // 0x800E095C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800E095C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800194_changlerbossbubble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080019C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001A0: jal         0x800F64A4
    // 0x808001A4: addiu       $a1, $zero, 0xA01
    ctx->r5 = ADD32(0, 0XA01);
    func_800F64A4(rdram, ctx);
        goto after_0;
    // 0x808001A4: addiu       $a1, $zero, 0xA01
    ctx->r5 = ADD32(0, 0XA01);
    after_0:
    // 0x808001A8: bne         $v0, $zero, L_808001B8
    if (ctx->r2 != 0) {
        // 0x808001AC: nop
    
            goto L_808001B8;
    }
    // 0x808001AC: nop

    // 0x808001B0: b           L_808001F0
    // 0x808001B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001F0;
    // 0x808001B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001B8:
    // 0x808001B8: jal         0x800F6D24
    // 0x808001BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F6D24(rdram, ctx);
        goto after_1;
    // 0x808001BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808001C0: bne         $v0, $zero, L_808001D0
    if (ctx->r2 != 0) {
        // 0x808001C4: nop
    
            goto L_808001D0;
    }
    // 0x808001C4: nop

    // 0x808001C8: b           L_808001F0
    // 0x808001CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001F0;
    // 0x808001CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001D0:
    // 0x808001D0: jal         0x800F8B88
    // 0x808001D4: nop

    func_800F8B88(rdram, ctx);
        goto after_2;
    // 0x808001D4: nop

    after_2:
    // 0x808001D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001DC: bnel        $v0, $at, L_808001F0
    if (ctx->r2 != ctx->r1) {
        // 0x808001E0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808001F0;
    }
    goto skip_0;
    // 0x808001E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808001E4: b           L_808001F0
    // 0x808001E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001F0;
    // 0x808001E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808001EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001F0:
    // 0x808001F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001F8: jr          $ra
    // 0x808001FC: nop

    return;
    // 0x808001FC: nop

;}
RECOMP_FUNC void func_80801114_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801118: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x8080111C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801120: beq         $a1, $at, L_80801144
    if (ctx->r5 == ctx->r1) {
        // 0x80801124: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801144;
    }
    // 0x80801124: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801128: addiu       $at, $zero, 0x17F8
    ctx->r1 = ADD32(0, 0X17F8);
    // 0x8080112C: beq         $a1, $at, L_80801154
    if (ctx->r5 == ctx->r1) {
        // 0x80801130: addiu       $at, $zero, 0x17F9
        ctx->r1 = ADD32(0, 0X17F9);
            goto L_80801154;
    }
    // 0x80801130: addiu       $at, $zero, 0x17F9
    ctx->r1 = ADD32(0, 0X17F9);
    // 0x80801134: beq         $a1, $at, L_80801154
    if (ctx->r5 == ctx->r1) {
        // 0x80801138: nop
    
            goto L_80801154;
    }
    // 0x80801138: nop

    // 0x8080113C: b           L_80801174
    // 0x80801140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801174;
    // 0x80801140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801144:
    // 0x80801144: jal         0x8080068C
    // 0x80801148: nop

    func_8080068C_chmonsterinterior(rdram, ctx);
        goto after_0;
    // 0x80801148: nop

    after_0:
    // 0x8080114C: b           L_80801174
    // 0x80801150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801174;
    // 0x80801150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801154:
    // 0x80801154: jal         0x8008A098
    // 0x80801158: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddiemulti_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80801158: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8080115C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801160: jal         0x80101FDC
    // 0x80801164: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80801164: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x80801168: jal         0x80088180
    // 0x8080116C: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x8080116C: nop

    after_3:
    // 0x80801170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801174:
    // 0x80801174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801178: jr          $ra
    // 0x8080117C: nop

    return;
    // 0x8080117C: nop

;}
RECOMP_FUNC void func_8010DA30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010DA30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010DA34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010DA38: lbu         $a2, 0x0($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X0);
    // 0x8010DA3C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8010DA40: beq         $a2, $zero, L_8010DA58
    if (ctx->r6 == 0) {
        // 0x8010DA44: andi        $a0, $a2, 0xFF
        ctx->r4 = ctx->r6 & 0XFF;
            goto L_8010DA58;
    }
    // 0x8010DA44: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x8010DA48: jal         0x800C2FDC
    // 0x8010DA4C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x8010DA4C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010DA50: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8010DA54: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
L_8010DA58:
    // 0x8010DA58: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8010DA5C: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8010DA60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010DA64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010DA68: jr          $ra
    // 0x8010DA6C: nop

    return;
    // 0x8010DA6C: nop

;}
RECOMP_FUNC void _subaddiejoy_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089BE0: syscall     805
    recomp_syscall_handler(rdram, ctx, 0x80089BE0);
    return;
    // 0x80089BE4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _glreflight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088458: syscall     684
    recomp_syscall_handler(rdram, ctx, 0x80088458);
    return;
    // 0x8008845C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_80016A48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016A48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80016A4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016A50: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80016A54: addiu       $a0, $a0, -0x6090
    ctx->r4 = ADD32(ctx->r4, -0X6090);
    // 0x80016A58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80016A5C: jal         0x8002EAD0
    // 0x80016A60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80016A60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80016A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80016A6C: jr          $ra
    // 0x80016A70: nop

    return;
    // 0x80016A70: nop

;}
RECOMP_FUNC void func_800F83E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F83E4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800F83E8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F83EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F83F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F83F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F83F8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F83FC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800F8400: jal         0x8009BA58
    // 0x800F8404: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_0;
    // 0x800F8404: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F8408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F840C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8410: jr          $ra
    // 0x800F8414: nop

    return;
    // 0x800F8414: nop

;}
RECOMP_FUNC void func_8080017C_bsbwhirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080017C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800184: jal         0x8009E704
    // 0x80800188: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bs_getNextState(rdram, ctx);
        goto after_0;
    // 0x80800188: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080018C: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80800190: beq         $v0, $at, L_808001E4
    if (ctx->r2 == ctx->r1) {
        // 0x80800194: addiu       $at, $zero, 0x1C
        ctx->r1 = ADD32(0, 0X1C);
            goto L_808001E4;
    }
    // 0x80800194: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80800198: beq         $v0, $at, L_808001E4
    if (ctx->r2 == ctx->r1) {
        // 0x8080019C: addiu       $at, $zero, 0x1D
        ctx->r1 = ADD32(0, 0X1D);
            goto L_808001E4;
    }
    // 0x8080019C: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x808001A0: beq         $v0, $at, L_808001E4
    if (ctx->r2 == ctx->r1) {
        // 0x808001A4: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_808001E4;
    }
    // 0x808001A4: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x808001A8: beq         $v0, $at, L_808001E4
    if (ctx->r2 == ctx->r1) {
        // 0x808001AC: addiu       $at, $zero, 0xA4
        ctx->r1 = ADD32(0, 0XA4);
            goto L_808001E4;
    }
    // 0x808001AC: addiu       $at, $zero, 0xA4
    ctx->r1 = ADD32(0, 0XA4);
    // 0x808001B0: beq         $v0, $at, L_808001E4
    if (ctx->r2 == ctx->r1) {
        // 0x808001B4: addiu       $at, $zero, 0xA5
        ctx->r1 = ADD32(0, 0XA5);
            goto L_808001E4;
    }
    // 0x808001B4: addiu       $at, $zero, 0xA5
    ctx->r1 = ADD32(0, 0XA5);
    // 0x808001B8: beql        $v0, $at, L_808001E8
    if (ctx->r2 == ctx->r1) {
        // 0x808001BC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808001E8;
    }
    goto skip_0;
    // 0x808001BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x808001C0: jal         0x8009F1E0
    // 0x808001C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bastick_resetZones(rdram, ctx);
        goto after_1;
    // 0x808001C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808001C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001CC: jal         0x800A0CF4
    // 0x808001D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_2;
    // 0x808001D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808001D4: jal         0x800FC74C
    // 0x808001D8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_800FC74C(rdram, ctx);
        goto after_3;
    // 0x808001D8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_3:
    // 0x808001DC: jal         0x808000D8
    // 0x808001E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000D8_bsbwhirl(rdram, ctx);
        goto after_4;
    // 0x808001E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
L_808001E4:
    // 0x808001E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808001E8:
    // 0x808001E8: jal         0x8008CA4C
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_5;
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808001F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001F8: jr          $ra
    // 0x808001FC: nop

    return;
    // 0x808001FC: nop

;}
RECOMP_FUNC void syscall_handler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081E74: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80081E78: sdc1        $f12, 0x0($sp)
    CHECK_FR(ctx, 12);
    SD(ctx->f12.u64, 0X0, ctx->r29);
    // 0x80081E7C: sdc1        $f14, 0x8($sp)
    CHECK_FR(ctx, 14);
    SD(ctx->f14.u64, 0X8, ctx->r29);
    // 0x80081E80: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80081E84: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x80081E88: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80081E8C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80081E90: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80081E94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80081E98: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80081E9C: sll         $a0, $t1, 7
    ctx->r4 = S32(ctx->r9 << 7);
    // 0x80081EA0: sll         $a1, $t1, 6
    ctx->r5 = S32(ctx->r9 << 6);
    // 0x80081EA4: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x80081EA8: srl         $a0, $a0, 13
    ctx->r4 = S32(U32(ctx->r4) >> 13);
    // 0x80081EAC: srl         $a1, $a1, 31
    ctx->r5 = S32(U32(ctx->r5) >> 31);
    // 0x80081EB0: sll         $a2, $t1, 1
    ctx->r6 = S32(ctx->r9 << 1);
    // 0x80081EB4: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80081EB8: subu        $a2, $t0, $a2
    ctx->r6 = SUB32(ctx->r8, ctx->r6);
    // 0x80081EBC: addiu       $t1, $t1, 0x2540
    ctx->r9 = ADD32(ctx->r9, 0X2540);
    // 0x80081EC0: subu        $a3, $a2, $t1
    ctx->r7 = SUB32(ctx->r6, ctx->r9);
    // 0x80081EC4: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x80081EC8: srl         $a3, $a3, 3
    ctx->r7 = S32(U32(ctx->r7) >> 3);
    // 0x80081ECC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80081ED0: sll         $t1, $t1, 19
    ctx->r9 = S32(ctx->r9 << 19);
    // 0x80081ED4: srl         $t1, $t1, 31
    ctx->r9 = S32(U32(ctx->r9) >> 31);
    // 0x80081ED8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80081EDC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80081EE0: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80081EE4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80081EE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80081EEC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80081EF0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80081EF4: jal         0x80081798
    // 0x80081EF8: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    ovl_load(rdram, ctx);
        goto after_0;
    // 0x80081EF8: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    after_0:
    // 0x80081EFC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80081F00: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80081F04: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80081F08: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80081F0C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80081F10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80081F14: sh          $t0, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r8;
    // 0x80081F18: sh          $t1, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r9;
    // 0x80081F1C: jal         0x80082088
    // 0x80081F20: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_80082088(rdram, ctx);
        goto after_1;
    // 0x80081F20: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x80081F24: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80081F28: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80081F2C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80081F30: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80081F34: jal         0x80081F64
    // 0x80081F38: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    func_80081F64(rdram, ctx);
        goto after_2;
    // 0x80081F38: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80081F3C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80081F40: ldc1        $f12, 0x0($sp)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r29, 0X0);
    // 0x80081F44: ldc1        $f14, 0x8($sp)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r29, 0X8);
    // 0x80081F48: lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10);
    // 0x80081F4C: lw          $a1, 0x14($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14);
    // 0x80081F50: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80081F54: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80081F58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80081F5C: jr          $t0
    // 0x80081F60: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
    return;
    // 0x80081F60: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800E47CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E47CC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E47D0: lw          $v0, -0x2AA0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AA0);
    // 0x800E47D4: bnel        $v0, $zero, L_800E47E8
    if (ctx->r2 != 0) {
        // 0x800E47D8: lh          $t6, 0x3A($v0)
        ctx->r14 = MEM_H(ctx->r2, 0X3A);
            goto L_800E47E8;
    }
    goto skip_0;
    // 0x800E47D8: lh          $t6, 0x3A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X3A);
    skip_0:
    // 0x800E47DC: jr          $ra
    // 0x800E47E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800E47E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E47E4: lh          $t6, 0x3A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X3A);
L_800E47E8:
    // 0x800E47E8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800E47EC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E47F0: bne         $v1, $t6, L_800E4800
    if (ctx->r3 != ctx->r14) {
        // 0x800E47F4: nop
    
            goto L_800E4800;
    }
    // 0x800E47F4: nop

    // 0x800E47F8: jr          $ra
    // 0x800E47FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800E47FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E4800:
    // 0x800E4800: lw          $v0, -0x2A9C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2A9C);
    // 0x800E4804: bnel        $v0, $zero, L_800E4818
    if (ctx->r2 != 0) {
        // 0x800E4808: lh          $t7, 0x3A($v0)
        ctx->r15 = MEM_H(ctx->r2, 0X3A);
            goto L_800E4818;
    }
    goto skip_1;
    // 0x800E4808: lh          $t7, 0x3A($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X3A);
    skip_1:
    // 0x800E480C: jr          $ra
    // 0x800E4810: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800E4810: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E4814: lh          $t7, 0x3A($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X3A);
L_800E4818:
    // 0x800E4818: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E481C: bne         $v1, $t7, L_800E482C
    if (ctx->r3 != ctx->r15) {
        // 0x800E4820: nop
    
            goto L_800E482C;
    }
    // 0x800E4820: nop

    // 0x800E4824: jr          $ra
    // 0x800E4828: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800E4828: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E482C:
    // 0x800E482C: lw          $v0, -0x2A98($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2A98);
    // 0x800E4830: bnel        $v0, $zero, L_800E4844
    if (ctx->r2 != 0) {
        // 0x800E4834: lh          $t8, 0x3A($v0)
        ctx->r24 = MEM_H(ctx->r2, 0X3A);
            goto L_800E4844;
    }
    goto skip_2;
    // 0x800E4834: lh          $t8, 0x3A($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X3A);
    skip_2:
    // 0x800E4838: jr          $ra
    // 0x800E483C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800E483C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800E4840: lh          $t8, 0x3A($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X3A);
L_800E4844:
    // 0x800E4844: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E4848: bne         $v1, $t8, L_800E4858
    if (ctx->r3 != ctx->r24) {
        // 0x800E484C: nop
    
            goto L_800E4858;
    }
    // 0x800E484C: nop

    // 0x800E4850: jr          $ra
    // 0x800E4854: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800E4854: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800E4858:
    // 0x800E4858: lw          $v0, -0x2A94($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2A94);
    // 0x800E485C: bnel        $v0, $zero, L_800E4870
    if (ctx->r2 != 0) {
        // 0x800E4860: lh          $t9, 0x3A($v0)
        ctx->r25 = MEM_H(ctx->r2, 0X3A);
            goto L_800E4870;
    }
    goto skip_3;
    // 0x800E4860: lh          $t9, 0x3A($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X3A);
    skip_3:
    // 0x800E4864: jr          $ra
    // 0x800E4868: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x800E4868: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800E486C: lh          $t9, 0x3A($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X3A);
L_800E4870:
    // 0x800E4870: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800E4874: bne         $v1, $t9, L_800E4884
    if (ctx->r3 != ctx->r25) {
        // 0x800E4878: nop
    
            goto L_800E4884;
    }
    // 0x800E4878: nop

    // 0x800E487C: jr          $ra
    // 0x800E4880: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x800E4880: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800E4884:
    // 0x800E4884: jr          $ra
    // 0x800E4888: nop

    return;
    // 0x800E4888: nop

;}
RECOMP_FUNC void func_8080025C_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080025C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800260: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800264: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800268: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080026C: jal         0x8008CABC
    // 0x80800270: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800270: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800274: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800278: lbu         $v1, 0x164($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X164);
    // 0x8080027C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: beq         $v1, $zero, L_8080029C
    if (ctx->r3 == 0) {
        // 0x80800288: nop
    
            goto L_8080029C;
    }
    // 0x80800288: nop

    // 0x8080028C: beq         $v1, $at, L_808002F8
    if (ctx->r3 == ctx->r1) {
        // 0x80800290: nop
    
            goto L_808002F8;
    }
    // 0x80800290: nop

    // 0x80800294: b           L_80800328
    // 0x80800298: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
        goto L_80800328;
    // 0x80800298: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
L_8080029C:
    // 0x8080029C: jal         0x8009BF5C
    // 0x808002A0: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x808002A0: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    after_1:
    // 0x808002A4: lui         $a1, 0x3EBD
    ctx->r5 = S32(0X3EBD << 16);
    // 0x808002A8: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    // 0x808002AC: jal         0x8008B348
    // 0x808002B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_2;
    // 0x808002B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808002B4: beql        $v0, $zero, L_80800328
    if (ctx->r2 == 0) {
        // 0x808002B8: lui         $a1, 0x3F19
        ctx->r5 = S32(0X3F19 << 16);
            goto L_80800328;
    }
    goto skip_0;
    // 0x808002B8: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    skip_0:
    // 0x808002BC: jal         0x80085270
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002C4: beql        $v0, $zero, L_808002D8
    if (ctx->r2 == 0) {
        // 0x808002C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002D8;
    }
    goto skip_1;
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808002CC: jal         0x800A0E64
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0E64(rdram, ctx);
        goto after_4;
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002D8:
    // 0x808002D8: jal         0x800852B8
    // 0x808002DC: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    _baswim_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x808002DC: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_5:
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E4: jal         0x800852A8
    // 0x808002E8: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    _baswim_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808002E8: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    after_6:
    // 0x808002EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808002F0: b           L_80800324
    // 0x808002F4: sb          $t6, 0x164($s0)
    MEM_B(0X164, ctx->r16) = ctx->r14;
        goto L_80800324;
    // 0x808002F4: sb          $t6, 0x164($s0)
    MEM_B(0X164, ctx->r16) = ctx->r14;
L_808002F8:
    // 0x808002F8: jal         0x800852C0
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800300: jal         0x800852D0
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_13(rdram, ctx);
        goto after_8;
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800308: lui         $a1, 0x3F42
    ctx->r5 = S32(0X3F42 << 16);
    // 0x8080030C: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x80800310: jal         0x8008B348
    // 0x80800314: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_9;
    // 0x80800314: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x80800318: beq         $v0, $zero, L_80800324
    if (ctx->r2 == 0) {
        // 0x8080031C: addiu       $t7, $zero, 0x2B
        ctx->r15 = ADD32(0, 0X2B);
            goto L_80800324;
    }
    // 0x8080031C: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x80800320: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800324:
    // 0x80800324: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
L_80800328:
    // 0x80800328: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080032C: jal         0x8008B348
    // 0x80800330: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_10;
    // 0x80800330: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_10:
    // 0x80800334: beq         $v0, $zero, L_80800348
    if (ctx->r2 == 0) {
        // 0x80800338: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800348;
    }
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080033C: addiu       $a1, $zero, 0x3FD
    ctx->r5 = ADD32(0, 0X3FD);
    // 0x80800340: jal         0x8009DE38
    // 0x80800344: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_11;
    // 0x80800344: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_11:
L_80800348:
    // 0x80800348: jal         0x8008E35C
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_12;
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800350: bne         $v0, $zero, L_80800360
    if (ctx->r2 != 0) {
        // 0x80800354: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800360;
    }
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8080035C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80800360:
    // 0x80800360: jal         0x8009E5C8
    // 0x80800364: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_13;
    // 0x80800364: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x80800368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080036C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800370: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800374: jr          $ra
    // 0x80800378: nop

    return;
    // 0x80800378: nop

;}
RECOMP_FUNC void func_808008EC_chintrocam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x808008F0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x808008F4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808008F8: jr          $ra
    // 0x808008FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808008FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80800128_chgate1doors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080012C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800130: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800134: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800138: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080013C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800140: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800144: beq         $t6, $at, L_80800168
    if (ctx->r14 == ctx->r1) {
        // 0x80800148: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800168;
    }
    // 0x80800148: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080014C: beq         $t6, $at, L_80800238
    if (ctx->r14 == ctx->r1) {
        // 0x80800150: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800238;
    }
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800158: beql        $t6, $at, L_808002A0
    if (ctx->r14 == ctx->r1) {
        // 0x8080015C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808002A0;
    }
    goto skip_0;
    // 0x8080015C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800160: b           L_808002A0
    // 0x80800164: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808002A0;
    // 0x80800164: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800168:
    // 0x80800168: jal         0x800DA298
    // 0x8080016C: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080016C: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    after_0:
    // 0x80800170: beq         $v0, $zero, L_8080029C
    if (ctx->r2 == 0) {
        // 0x80800174: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8080029C;
    }
    // 0x80800174: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800178: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080017C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800180: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800184: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    // 0x80800188: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8080018C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800190: jal         0x800EEB9C
    // 0x80800194: nop

    func_800EEB9C(rdram, ctx);
        goto after_1;
    // 0x80800194: nop

    after_1:
    // 0x80800198: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080019C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808001A0: jal         0x800EF04C
    // 0x808001A4: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x808001A4: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x808001A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1916, 0X470) << 16);
    // 0x808001AC: lwc1        $f10, 0x470($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1916, 0X470));
    // 0x808001B0: addiu       $t7, $zero, 0xB4
    ctx->r15 = ADD32(0, 0XB4);
    // 0x808001B4: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x808001B8: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x808001BC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x808001C0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x808001C4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808001C8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808001CC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808001D0: addiu       $a2, $zero, -0x28
    ctx->r6 = ADD32(0, -0X28);
    // 0x808001D4: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x808001D8: jal         0x80109748
    // 0x808001DC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80109748(rdram, ctx);
        goto after_3;
    // 0x808001DC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x808001E0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1916, 0X480) << 16);
    // 0x808001E4: addiu       $a2, $a2, 0x480
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1916, 0X480));
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001EC: jal         0x80089D18
    // 0x808001F0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808001F0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x808001F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1916, 0X494) << 16);
    // 0x808001F8: addiu       $a2, $a2, 0x494
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1916, 0X494));
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800200: jal         0x80089D18
    // 0x80800204: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800204: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: jal         0x80101FDC
    // 0x80800210: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x80800210: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: jal         0x8008A4B0
    // 0x8080021C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x8080021C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800220: lbu         $t0, 0x74($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X74);
    // 0x80800224: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800228: andi        $t1, $t0, 0xFFBF
    ctx->r9 = ctx->r8 & 0XFFBF;
    // 0x8080022C: sb          $t1, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r9;
    // 0x80800230: b           L_8080029C
    // 0x80800234: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
        goto L_8080029C;
    // 0x80800234: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_80800238:
    // 0x80800238: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080023C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800240: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1916, 0X4A8) << 16);
    // 0x80800244: addiu       $a3, $a3, 0x4A8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1916, 0X4A8));
    // 0x80800248: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080024C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800250: jal         0x80089D50
    // 0x80800254: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800254: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    after_8:
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: jal         0x80102CF4
    // 0x80800260: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80102CF4(rdram, ctx);
        goto after_9;
    // 0x80800260: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_9:
    // 0x80800264: beq         $v0, $zero, L_80800294
    if (ctx->r2 == 0) {
        // 0x80800268: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800294;
    }
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: jal         0x80101FDC
    // 0x80800274: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x80800274: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: jal         0x80103110
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_11;
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800284: jal         0x80089D40
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080028C: b           L_808002A0
    // 0x80800290: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808002A0;
    // 0x80800290: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800294:
    // 0x80800294: jal         0x80102B2C
    // 0x80800298: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102B2C(rdram, ctx);
        goto after_13;
    // 0x80800298: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_13:
L_8080029C:
    // 0x8080029C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808002A0:
    // 0x808002A0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808002A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808002A8: jr          $ra
    // 0x808002AC: nop

    return;
    // 0x808002AC: nop

;}
RECOMP_FUNC void _babackpack_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084518: syscall     113
    recomp_syscall_handler(rdram, ctx, 0x80084518);
    return;
    // 0x8008451C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_808013E8_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013F0: jal         0x8008F8B0
    // 0x808013F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008F8B0(rdram, ctx);
        goto after_0;
    // 0x808013F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808013F8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1748, 0X20D4) << 16);
    // 0x808013FC: jal         0x8008F964
    // 0x80801400: addiu       $a0, $a0, 0x20D4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1748, 0X20D4));
    func_8008F964(rdram, ctx);
        goto after_1;
    // 0x80801400: addiu       $a0, $a0, 0x20D4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1748, 0X20D4));
    after_1:
    // 0x80801404: jal         0x8008F8D8
    // 0x80801408: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8008F8D8(rdram, ctx);
        goto after_2;
    // 0x80801408: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8080140C: jal         0x8008F938
    // 0x80801410: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F938(rdram, ctx);
        goto after_3;
    // 0x80801410: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80801414: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80801418: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8080141C: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x80801420: jal         0x8008F904
    // 0x80801424: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_8008F904(rdram, ctx);
        goto after_4;
    // 0x80801424: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_4:
    // 0x80801428: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1748, 0X20D4) << 16);
    // 0x8080142C: addiu       $a0, $a0, 0x20D4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1748, 0X20D4));
    // 0x80801430: jal         0x8008F9C4
    // 0x80801434: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_8008F9C4(rdram, ctx);
        goto after_5;
    // 0x80801434: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_5:
    // 0x80801438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080143C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801440: jr          $ra
    // 0x80801444: nop

    return;
    // 0x80801444: nop

;}
RECOMP_FUNC void func_80806A30_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806A30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80806A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806A38: jal         0x80088388
    // 0x80806A3C: nop

    _gcstatusDll_entrypoint_15(rdram, ctx);
        goto after_0;
    // 0x80806A3C: nop

    after_0:
    // 0x80806A40: bgez        $v0, L_80806A50
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80806A44: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80806A50;
    }
    // 0x80806A44: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80806A48: b           L_80806A74
    // 0x80806A4C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80806A74;
    // 0x80806A4C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80806A50:
    // 0x80806A50: jal         0x80088360
    // 0x80806A54: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    _gcstatusDll_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80806A54: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80806A58: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80806A5C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80806A60: bnel        $at, $zero, L_80806A78
    if (ctx->r1 != 0) {
        // 0x80806A64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80806A78;
    }
    goto skip_0;
    // 0x80806A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80806A68: jal         0x80088360
    // 0x80806A6C: nop

    _gcstatusDll_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80806A6C: nop

    after_2:
    // 0x80806A70: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
L_80806A74:
    // 0x80806A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806A78:
    // 0x80806A78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80806A7C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80806A80: jr          $ra
    // 0x80806A84: nop

    return;
    // 0x80806A84: nop

;}
RECOMP_FUNC void bavan_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080016C: lw          $t6, 0x144($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X144);
    // 0x80800170: jr          $ra
    // 0x80800174: swc1        $f12, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x80800174: swc1        $f12, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_808002B8_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002BC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808002C0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808002C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002C8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808002CC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808002D0: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x808002D4: jal         0x80100094
    // 0x808002D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002DC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808002E0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808002E4: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x808002E8: beq         $a2, $at, L_8080032C
    if (ctx->r6 == ctx->r1) {
        // 0x808002EC: addiu       $a0, $sp, 0x38
        ctx->r4 = ADD32(ctx->r29, 0X38);
            goto L_8080032C;
    }
    // 0x808002EC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808002F0: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x808002F4: beq         $a2, $at, L_80800348
    if (ctx->r6 == ctx->r1) {
        // 0x808002F8: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80800348;
    }
    // 0x808002F8: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808002FC: beq         $a2, $at, L_80800408
    if (ctx->r6 == ctx->r1) {
        // 0x80800300: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_80800408;
    }
    // 0x80800300: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80800304: beq         $a2, $at, L_808005F0
    if (ctx->r6 == ctx->r1) {
        // 0x80800308: addiu       $a0, $sp, 0x38
        ctx->r4 = ADD32(ctx->r29, 0X38);
            goto L_808005F0;
    }
    // 0x80800308: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8080030C: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800310: beq         $a2, $at, L_8080062C
    if (ctx->r6 == ctx->r1) {
        // 0x80800314: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8080062C;
    }
    // 0x80800314: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800318: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x8080031C: beql        $a2, $at, L_80800640
    if (ctx->r6 == ctx->r1) {
        // 0x80800320: lbu         $v1, 0x39($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X39);
            goto L_80800640;
    }
    goto skip_0;
    // 0x80800320: lbu         $v1, 0x39($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X39);
    skip_0:
    // 0x80800324: b           L_808006EC
    // 0x80800328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006EC;
    // 0x80800328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080032C:
    // 0x8080032C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800330: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80800334: lbu         $t7, 0x79($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X79);
    // 0x80800338: andi        $t8, $t7, 0xFF0F
    ctx->r24 = ctx->r15 & 0XFF0F;
    // 0x8080033C: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x80800340: b           L_808006EC
    // 0x80800344: sb          $t9, 0x79($t6)
    MEM_B(0X79, ctx->r14) = ctx->r25;
        goto L_808006EC;
    // 0x80800344: sb          $t9, 0x79($t6)
    MEM_B(0X79, ctx->r14) = ctx->r25;
L_80800348:
    // 0x80800348: lbu         $v1, 0x39($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X39);
    // 0x8080034C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800350: beql        $v1, $zero, L_80800378
    if (ctx->r3 == 0) {
        // 0x80800354: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80800378;
    }
    goto skip_1;
    // 0x80800354: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_1:
    // 0x80800358: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080035C: beq         $v1, $at, L_80800380
    if (ctx->r3 == ctx->r1) {
        // 0x80800360: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800380;
    }
    // 0x80800360: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800364: beql        $v1, $at, L_80800394
    if (ctx->r3 == ctx->r1) {
        // 0x80800368: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800394;
    }
    goto skip_2;
    // 0x80800368: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_2:
    // 0x8080036C: b           L_808003A4
    // 0x80800370: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
        goto L_808003A4;
    // 0x80800370: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800374: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80800378:
    // 0x80800378: b           L_808003A0
    // 0x8080037C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
        goto L_808003A0;
    // 0x8080037C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
L_80800380:
    // 0x80800380: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800384: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800388: b           L_808003A0
    // 0x8080038C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
        goto L_808003A0;
    // 0x8080038C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80800390: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80800394:
    // 0x80800394: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800398: nop

    // 0x8080039C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
L_808003A0:
    // 0x808003A0: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
L_808003A4:
    // 0x808003A4: jal         0x80085728
    // 0x808003A8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    _capod_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x808003A8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_1:
    // 0x808003AC: beq         $v0, $zero, L_80800400
    if (ctx->r2 == 0) {
        // 0x808003B0: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_80800400;
    }
    // 0x808003B0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808003B4: lbu         $t1, 0x39($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X39);
    // 0x808003B8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x808003BC: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x808003C0: lw          $a0, 0x14($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X14);
    // 0x808003C4: jal         0x80106790
    // 0x808003C8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x808003C8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_2:
    // 0x808003CC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808003D0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x808003D4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808003D8: lbu         $a1, 0x39($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X39);
    // 0x808003DC: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x808003E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808003E4: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    // 0x808003E8: jal         0x8008A208
    // 0x808003EC: addiu       $a1, $a1, 0x12C7
    ctx->r5 = ADD32(ctx->r5, 0X12C7);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x808003EC: addiu       $a1, $a1, 0x12C7
    ctx->r5 = ADD32(ctx->r5, 0X12C7);
    after_3:
    // 0x808003F0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808003F4: lbu         $t7, 0x65($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X65);
    // 0x808003F8: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808003FC: sb          $t8, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r24;
L_80800400:
    // 0x80800400: b           L_808006EC
    // 0x80800404: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808006EC;
    // 0x80800404: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800408:
    // 0x80800408: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x8080040C: slti        $at, $v1, 0x1280
    ctx->r1 = SIGNED(ctx->r3) < 0X1280 ? 1 : 0;
    // 0x80800410: bne         $at, $zero, L_80800454
    if (ctx->r1 != 0) {
        // 0x80800414: addiu       $t9, $v1, -0x12C7
        ctx->r25 = ADD32(ctx->r3, -0X12C7);
            goto L_80800454;
    }
    // 0x80800414: addiu       $t9, $v1, -0x12C7
    ctx->r25 = ADD32(ctx->r3, -0X12C7);
    // 0x80800418: slti        $at, $v1, 0x1281
    ctx->r1 = SIGNED(ctx->r3) < 0X1281 ? 1 : 0;
    // 0x8080041C: bne         $at, $zero, L_80800440
    if (ctx->r1 != 0) {
        // 0x80800420: sltiu       $at, $t9, 0xE
        ctx->r1 = ctx->r25 < 0XE ? 1 : 0;
            goto L_80800440;
    }
    // 0x80800420: sltiu       $at, $t9, 0xE
    ctx->r1 = ctx->r25 < 0XE ? 1 : 0;
    // 0x80800424: beq         $at, $zero, L_808006E8
    if (ctx->r1 == 0) {
        // 0x80800428: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808006E8;
    }
    // 0x80800428: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8080042C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4B30) << 16);
    // 0x80800430: addu        $at, $at, $t9
    gpr jr_addend_80800438 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800434: lw          $t9, 0x4B30($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4B30));
    // 0x80800438: jr          $t9
    // 0x8080043C: nop

    switch (jr_addend_80800438 >> 2) {
        case 0: goto L_808005DC; break;
        case 1: goto L_808005DC; break;
        case 2: goto L_808005DC; break;
        case 3: goto L_808006E8; break;
        case 4: goto L_808006E8; break;
        case 5: goto L_8080047C; break;
        case 6: goto L_8080047C; break;
        case 7: goto L_808006E8; break;
        case 8: goto L_808006E8; break;
        case 9: goto L_808006E8; break;
        case 10: goto L_808005CC; break;
        case 11: goto L_808005CC; break;
        case 12: goto L_808006E8; break;
        case 13: goto L_808004B4; break;
        default: switch_error(__func__, 0x80800438, 0x80804B30);
    }
    // 0x8080043C: nop

L_80800440:
    // 0x80800440: addiu       $at, $zero, 0x1280
    ctx->r1 = ADD32(0, 0X1280);
    // 0x80800444: beql        $v1, $at, L_808004B8
    if (ctx->r3 == ctx->r1) {
        // 0x80800448: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808004B8;
    }
    goto skip_3;
    // 0x80800448: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    skip_3:
    // 0x8080044C: b           L_808006EC
    // 0x80800450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006EC;
    // 0x80800450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800454:
    // 0x80800454: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x80800458: beq         $v1, $at, L_808004CC
    if (ctx->r3 == ctx->r1) {
        // 0x8080045C: addiu       $at, $zero, 0x127A
        ctx->r1 = ADD32(0, 0X127A);
            goto L_808004CC;
    }
    // 0x8080045C: addiu       $at, $zero, 0x127A
    ctx->r1 = ADD32(0, 0X127A);
    // 0x80800460: beq         $v1, $at, L_8080054C
    if (ctx->r3 == ctx->r1) {
        // 0x80800464: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_8080054C;
    }
    // 0x80800464: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80800468: addiu       $at, $zero, 0x127F
    ctx->r1 = ADD32(0, 0X127F);
    // 0x8080046C: beql        $v1, $at, L_808004B8
    if (ctx->r3 == ctx->r1) {
        // 0x80800470: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808004B8;
    }
    goto skip_4;
    // 0x80800470: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    skip_4:
    // 0x80800474: b           L_808006EC
    // 0x80800478: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006EC;
    // 0x80800478: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080047C:
    // 0x8080047C: lbu         $a1, 0x39($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X39);
    // 0x80800480: lw          $a2, 0x20($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X20);
    // 0x80800484: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800488: addiu       $a1, $a1, 0x91
    ctx->r5 = ADD32(ctx->r5, 0X91);
    // 0x8080048C: jal         0x800D2054
    // 0x80800490: addiu       $a2, $a2, 0x3E80
    ctx->r6 = ADD32(ctx->r6, 0X3E80);
    func_800D2054(rdram, ctx);
        goto after_4;
    // 0x80800490: addiu       $a2, $a2, 0x3E80
    ctx->r6 = ADD32(ctx->r6, 0X3E80);
    after_4:
    // 0x80800494: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800498: bne         $v0, $at, L_808004B4
    if (ctx->r2 != ctx->r1) {
        // 0x8080049C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808004B4;
    }
    // 0x8080049C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808004A0: addiu       $a1, $zero, 0x12D4
    ctx->r5 = ADD32(0, 0X12D4);
    // 0x808004A4: jal         0x80800000
    // 0x808004A8: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_80800000_chcollballcontrol(rdram, ctx);
        goto after_5;
    // 0x808004A8: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_5:
    // 0x808004AC: b           L_808006EC
    // 0x808004B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006EC;
    // 0x808004B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004B4:
    // 0x808004B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_808004B8:
    // 0x808004B8: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x808004BC: jal         0x80800000
    // 0x808004C0: addiu       $a2, $zero, 0x240
    ctx->r6 = ADD32(0, 0X240);
    func_80800000_chcollballcontrol(rdram, ctx);
        goto after_6;
    // 0x808004C0: addiu       $a2, $zero, 0x240
    ctx->r6 = ADD32(0, 0X240);
    after_6:
    // 0x808004C4: b           L_808006EC
    // 0x808004C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006EC;
    // 0x808004C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004CC:
    // 0x808004CC: jal         0x800D395C
    // 0x808004D0: nop

    func_800D395C(rdram, ctx);
        goto after_7;
    // 0x808004D0: nop

    after_7:
    // 0x808004D4: beq         $v0, $zero, L_8080050C
    if (ctx->r2 == 0) {
        // 0x808004D8: addiu       $a0, $sp, 0x38
        ctx->r4 = ADD32(ctx->r29, 0X38);
            goto L_8080050C;
    }
    // 0x808004D8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808004DC: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x808004E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808004E4: bne         $t6, $at, L_808004FC
    if (ctx->r14 != ctx->r1) {
        // 0x808004E8: nop
    
            goto L_808004FC;
    }
    // 0x808004E8: nop

    // 0x808004EC: jal         0x80088188
    // 0x808004F0: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x808004F0: nop

    after_8:
    // 0x808004F4: b           L_808006EC
    // 0x808004F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006EC;
    // 0x808004F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004FC:
    // 0x808004FC: jal         0x80088180
    // 0x80800500: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_9;
    // 0x80800500: nop

    after_9:
    // 0x80800504: b           L_808006EC
    // 0x80800508: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006EC;
    // 0x80800508: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080050C:
    // 0x8080050C: lh          $t1, 0x2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2);
    // 0x80800510: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800514: addiu       $a0, $zero, 0x12D
    ctx->r4 = ADD32(0, 0X12D);
    // 0x80800518: bne         $t1, $at, L_8080053C
    if (ctx->r9 != ctx->r1) {
        // 0x8080051C: nop
    
            goto L_8080053C;
    }
    // 0x8080051C: nop

    // 0x80800520: jal         0x800EA05C
    // 0x80800524: nop

    func_800EA05C(rdram, ctx);
        goto after_10;
    // 0x80800524: nop

    after_10:
    // 0x80800528: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080052C: jal         0x80087A58
    // 0x80800530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80800530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800534: b           L_808006EC
    // 0x80800538: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006EC;
    // 0x80800538: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080053C:
    // 0x8080053C: jal         0x80087A58
    // 0x80800540: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x80800540: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_12:
    // 0x80800544: b           L_808006EC
    // 0x80800548: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006EC;
    // 0x80800548: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080054C:
    // 0x8080054C: jal         0x800FDC28
    // 0x80800550: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_800FDC28(rdram, ctx);
        goto after_13;
    // 0x80800550: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_13:
    // 0x80800554: jal         0x8080014C
    // 0x80800558: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8080014C_chcollballcontrol(rdram, ctx);
        goto after_14;
    // 0x80800558: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_14:
    // 0x8080055C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800560: jal         0x80800138
    // 0x80800564: lbu         $a0, 0x39($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X39);
    func_80800138_chcollballcontrol(rdram, ctx);
        goto after_15;
    // 0x80800564: lbu         $a0, 0x39($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X39);
    after_15:
    // 0x80800568: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8080056C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800570: jal         0x80800138
    // 0x80800574: lbu         $a0, 0x39($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X39);
    func_80800138_chcollballcontrol(rdram, ctx);
        goto after_16;
    // 0x80800574: lbu         $a0, 0x39($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X39);
    after_16:
    // 0x80800578: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8080057C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800580: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800584: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80800588: nop

    // 0x8080058C: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800590: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800594: jal         0x800CE8D8
    // 0x80800598: nop

    func_800CE8D8(rdram, ctx);
        goto after_17;
    // 0x80800598: nop

    after_17:
    // 0x8080059C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005A0: jal         0x800CE88C
    // 0x808005A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_18;
    // 0x808005A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x808005A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808005AC: jal         0x80801500
    // 0x808005B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801500_chcollballcontrol(rdram, ctx);
        goto after_19;
    // 0x808005B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x808005B4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x808005B8: lbu         $t3, 0x72($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X72);
    // 0x808005BC: andi        $t4, $t3, 0xFF03
    ctx->r12 = ctx->r11 & 0XFF03;
    // 0x808005C0: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x808005C4: b           L_808006E8
    // 0x808005C8: sb          $t5, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r13;
        goto L_808006E8;
    // 0x808005C8: sb          $t5, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r13;
L_808005CC:
    // 0x808005CC: jal         0x80088180
    // 0x808005D0: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_20;
    // 0x808005D0: nop

    after_20:
    // 0x808005D4: b           L_808006EC
    // 0x808005D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006EC;
    // 0x808005D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005DC:
    // 0x808005DC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x808005E0: lbu         $t7, 0x65($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X65);
    // 0x808005E4: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x808005E8: b           L_808006E8
    // 0x808005EC: sb          $t8, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r24;
        goto L_808006E8;
    // 0x808005EC: sb          $t8, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r24;
L_808005F0:
    // 0x808005F0: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x808005F4: addiu       $at, $zero, 0x12D1
    ctx->r1 = ADD32(0, 0X12D1);
    // 0x808005F8: beq         $v1, $at, L_80800610
    if (ctx->r3 == ctx->r1) {
        // 0x808005FC: addiu       $at, $zero, 0x12D4
        ctx->r1 = ADD32(0, 0X12D4);
            goto L_80800610;
    }
    // 0x808005FC: addiu       $at, $zero, 0x12D4
    ctx->r1 = ADD32(0, 0X12D4);
    // 0x80800600: beql        $v1, $at, L_8080061C
    if (ctx->r3 == ctx->r1) {
        // 0x80800604: lbu         $a0, 0x39($t0)
        ctx->r4 = MEM_BU(ctx->r8, 0X39);
            goto L_8080061C;
    }
    goto skip_5;
    // 0x80800604: lbu         $a0, 0x39($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X39);
    skip_5:
    // 0x80800608: b           L_808006EC
    // 0x8080060C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006EC;
    // 0x8080060C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800610:
    // 0x80800610: b           L_808006EC
    // 0x80800614: lbu         $v0, 0x3B($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X3B);
        goto L_808006EC;
    // 0x80800614: lbu         $v0, 0x3B($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X3B);
    // 0x80800618: lbu         $a0, 0x39($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X39);
L_8080061C:
    // 0x8080061C: jal         0x800D211C
    // 0x80800620: addiu       $a0, $a0, 0x91
    ctx->r4 = ADD32(ctx->r4, 0X91);
    func_800D211C(rdram, ctx);
        goto after_21;
    // 0x80800620: addiu       $a0, $a0, 0x91
    ctx->r4 = ADD32(ctx->r4, 0X91);
    after_21:
    // 0x80800624: b           L_808006EC
    // 0x80800628: addiu       $v0, $v0, -0x3E80
    ctx->r2 = ADD32(ctx->r2, -0X3E80);
        goto L_808006EC;
    // 0x80800628: addiu       $v0, $v0, -0x3E80
    ctx->r2 = ADD32(ctx->r2, -0X3E80);
L_8080062C:
    // 0x8080062C: jal         0x808001B8
    // 0x80800630: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_808001B8_chcollballcontrol(rdram, ctx);
        goto after_22;
    // 0x80800630: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_22:
    // 0x80800634: b           L_808006EC
    // 0x80800638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006EC;
    // 0x80800638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080063C: lbu         $v1, 0x39($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X39);
L_80800640:
    // 0x80800640: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800644: beq         $v1, $zero, L_8080066C
    if (ctx->r3 == 0) {
        // 0x80800648: nop
    
            goto L_8080066C;
    }
    // 0x80800648: nop

    // 0x8080064C: beq         $v1, $at, L_8080066C
    if (ctx->r3 == ctx->r1) {
        // 0x80800650: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080066C;
    }
    // 0x80800650: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800654: beq         $v1, $at, L_8080066C
    if (ctx->r3 == ctx->r1) {
        // 0x80800658: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080066C;
    }
    // 0x80800658: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080065C: beq         $v1, $at, L_808006D0
    if (ctx->r3 == ctx->r1) {
        // 0x80800660: nop
    
            goto L_808006D0;
    }
    // 0x80800660: nop

    // 0x80800664: b           L_808006EC
    // 0x80800668: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006EC;
    // 0x80800668: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080066C:
    // 0x8080066C: jal         0x800D395C
    // 0x80800670: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_800D395C(rdram, ctx);
        goto after_23;
    // 0x80800670: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_23:
    // 0x80800674: bne         $v0, $zero, L_808006C0
    if (ctx->r2 != 0) {
        // 0x80800678: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_808006C0;
    }
    // 0x80800678: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8080067C: lbu         $a0, 0x39($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X39);
    // 0x80800680: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800684: jal         0x800DA9E4
    // 0x80800688: addiu       $a0, $a0, 0x41F
    ctx->r4 = ADD32(ctx->r4, 0X41F);
    func_800DA9E4(rdram, ctx);
        goto after_24;
    // 0x80800688: addiu       $a0, $a0, 0x41F
    ctx->r4 = ADD32(ctx->r4, 0X41F);
    after_24:
    // 0x8080068C: bne         $v0, $zero, L_808006C0
    if (ctx->r2 != 0) {
        // 0x80800690: lw          $t9, 0x30($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X30);
            goto L_808006C0;
    }
    // 0x80800690: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800694: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80800698: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080069C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808006A0: jal         0x80085708
    // 0x808006A4: addiu       $a3, $zero, 0x2020
    ctx->r7 = ADD32(0, 0X2020);
    _capod_entrypoint_13(rdram, ctx);
        goto after_25;
    // 0x808006A4: addiu       $a3, $zero, 0x2020
    ctx->r7 = ADD32(0, 0X2020);
    after_25:
    // 0x808006A8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808006AC: lbu         $t6, 0x79($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X79);
    // 0x808006B0: andi        $t1, $t6, 0xFF0F
    ctx->r9 = ctx->r14 & 0XFF0F;
    // 0x808006B4: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x808006B8: b           L_808006E8
    // 0x808006BC: sb          $t2, 0x79($v1)
    MEM_B(0X79, ctx->r3) = ctx->r10;
        goto L_808006E8;
    // 0x808006BC: sb          $t2, 0x79($v1)
    MEM_B(0X79, ctx->r3) = ctx->r10;
L_808006C0:
    // 0x808006C0: jal         0x800A54F8
    // 0x808006C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A54F8(rdram, ctx);
        goto after_26;
    // 0x808006C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_26:
    // 0x808006C8: b           L_808006EC
    // 0x808006CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006EC;
    // 0x808006CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006D0:
    // 0x808006D0: jal         0x8008A0A8
    // 0x808006D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _subaddiemulti_entrypoint_4(rdram, ctx);
        goto after_27;
    // 0x808006D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_27:
    // 0x808006D8: b           L_808006EC
    // 0x808006DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006EC;
    // 0x808006DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808006E0: b           L_808006EC
    // 0x808006E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006EC;
    // 0x808006E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006E8:
    // 0x808006E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006EC:
    // 0x808006EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808006F4: jr          $ra
    // 0x808006F8: nop

    return;
    // 0x808006F8: nop

;}
RECOMP_FUNC void func_808004F4_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800500: jal         0x80082FE8
    // 0x80800504: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800504: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800508: jal         0x80800078
    // 0x8080050C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800078_bsstatue(rdram, ctx);
        goto after_1;
    // 0x8080050C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800510: beq         $v0, $zero, L_8080051C
    if (ctx->r2 == 0) {
        // 0x80800514: addiu       $t6, $zero, 0xFD
        ctx->r14 = ADD32(0, 0XFD);
            goto L_8080051C;
    }
    // 0x80800514: addiu       $t6, $zero, 0xFD
    ctx->r14 = ADD32(0, 0XFD);
    // 0x80800518: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_8080051C:
    // 0x8080051C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800520: jal         0x8009E5C8
    // 0x80800524: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800524: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080052C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800530: jr          $ra
    // 0x80800534: nop

    return;
    // 0x80800534: nop

;}
RECOMP_FUNC void func_80800000_chcrashmat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x800878B0
    // 0x80800014: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    _plsu_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800014: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80800018: bne         $v0, $zero, L_8080005C
    if (ctx->r2 != 0) {
        // 0x8080001C: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_8080005C;
    }
    // 0x8080001C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800020: jal         0x800D90A4
    // 0x80800024: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x80800024: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x80800028: beql        $v0, $zero, L_80800060
    if (ctx->r2 == 0) {
        // 0x8080002C: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_80800060;
    }
    goto skip_0;
    // 0x8080002C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800030: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800034: lui         $a0, 0x599C
    ctx->r4 = S32(0X599C << 16);
    // 0x80800038: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x8080003C: bltzl       $t8, L_80800060
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800040: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_80800060;
    }
    goto skip_1;
    // 0x80800040: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800044: jal         0x800C3F48
    // 0x80800048: ori         $a0, $a0, 0x5699
    ctx->r4 = ctx->r4 | 0X5699;
    func_800C3F48(rdram, ctx);
        goto after_2;
    // 0x80800048: ori         $a0, $a0, 0x5699
    ctx->r4 = ctx->r4 | 0X5699;
    after_2:
    // 0x8080004C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800050: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800054: nop

    // 0x80800058: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_8080005C:
    // 0x8080005C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_80800060:
    // 0x80800060: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80800064: sltiu       $t1, $t9, 0x1
    ctx->r9 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80800068: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8080006C: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x80800070: andi        $t5, $t4, 0xFFEF
    ctx->r13 = ctx->r12 & 0XFFEF;
    // 0x80800074: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80800078: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    // 0x8080007C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800080: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800084: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void bstimeout_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C8: jal         0x8008CABC
    // 0x808000CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808000CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000D0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808000D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000D8: jal         0x8008B348
    // 0x808000DC: lui         $a1, 0x3D80
    ctx->r5 = S32(0X3D80 << 16);
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x808000DC: lui         $a1, 0x3D80
    ctx->r5 = S32(0X3D80 << 16);
    after_1:
    // 0x808000E0: beql        $v0, $zero, L_808000F4
    if (ctx->r2 == 0) {
        // 0x808000E4: lui         $a1, 0x3E38
        ctx->r5 = S32(0X3E38 << 16);
            goto L_808000F4;
    }
    goto skip_0;
    // 0x808000E4: lui         $a1, 0x3E38
    ctx->r5 = S32(0X3E38 << 16);
    skip_0:
    // 0x808000E8: jal         0x8009514C
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009514C(rdram, ctx);
        goto after_2;
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000F0: lui         $a1, 0x3E38
    ctx->r5 = S32(0X3E38 << 16);
L_808000F4:
    // 0x808000F4: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x808000F8: jal         0x8008B348
    // 0x808000FC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x808000FC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80800100: beq         $v0, $zero, L_80800118
    if (ctx->r2 == 0) {
        // 0x80800104: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800118;
    }
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: addiu       $a1, $zero, 0x3EB
    ctx->r5 = ADD32(0, 0X3EB);
    // 0x8080010C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800110: jal         0x8009DF18
    // 0x80800114: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_4;
    // 0x80800114: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_4:
L_80800118:
    // 0x80800118: lui         $a1, 0x3F57
    ctx->r5 = S32(0X3F57 << 16);
    // 0x8080011C: ori         $a1, $a1, 0x93DE
    ctx->r5 = ctx->r5 | 0X93DE;
    // 0x80800120: jal         0x8008B348
    // 0x80800124: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x80800124: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80800128: beq         $v0, $zero, L_80800154
    if (ctx->r2 == 0) {
        // 0x8080012C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800154;
    }
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80800134: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800138: jal         0x8009518C
    // 0x8080013C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009518C(rdram, ctx);
        goto after_6;
    // 0x8080013C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800140: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80800144: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: jal         0x8009518C
    // 0x80800150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009518C(rdram, ctx);
        goto after_7;
    // 0x80800150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
L_80800154:
    // 0x80800154: lui         $a1, 0x3F57
    ctx->r5 = S32(0X3F57 << 16);
    // 0x80800158: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    // 0x8080015C: jal         0x8008B348
    // 0x80800160: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_8;
    // 0x80800160: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x80800164: beql        $v0, $zero, L_80800178
    if (ctx->r2 == 0) {
        // 0x80800168: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800178;
    }
    goto skip_1;
    // 0x80800168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080016C: jal         0x800A05DC
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A05DC(rdram, ctx);
        goto after_9;
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800178:
    // 0x80800178: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080017C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800180: jr          $ra
    // 0x80800184: nop

    return;
    // 0x80800184: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808012DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808012E4: jal         0x800839E8
    // 0x808012E8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x808012E8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808012EC: beq         $v0, $zero, L_80801300
    if (ctx->r2 == 0) {
        // 0x808012F0: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80801300;
    }
    // 0x808012F0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808012F4: jal         0x800839B0
    // 0x808012F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsrest_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x808012F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808012FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80801300:
    // 0x80801300: jal         0x8009E5C8
    // 0x80801304: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80801304: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80801308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080130C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801310: jr          $ra
    // 0x80801314: nop

    return;
    // 0x80801314: nop

;}
RECOMP_FUNC void func_80800180_bashoes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800184: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800188: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080018C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800190: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800194: jal         0x80091554
    // 0x80800198: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bastatetimer_getPrevious(rdram, ctx);
        goto after_0;
    // 0x80800198: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x8080019C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: jal         0x80091538
    // 0x808001A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bastatetimer_get(rdram, ctx);
        goto after_1;
    // 0x808001A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x808001AC: lw          $t6, 0x10C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10C);
    // 0x808001B0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x808001BC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808001C0: bnel        $t7, $zero, L_8080023C
    if (ctx->r15 != 0) {
        // 0x808001C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080023C;
    }
    goto skip_0;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808001C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001CC: jal         0x80084430
    // 0x808001D0: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    _baalarm_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808001D0: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x808001D4: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808001D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808001DC: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808001E0: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x808001E4: nop

    // 0x808001E8: bc1fl       L_8080023C
    if (!c1cs) {
        // 0x808001EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080023C;
    }
    goto skip_1;
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808001F0: c.eq.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl == ctx->f2.fl;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: bc1tl       L_8080023C
    if (c1cs) {
        // 0x808001FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080023C;
    }
    goto skip_2;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800200: jal         0x80095748
    // 0x80800204: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    baflag_isFalse(rdram, ctx);
        goto after_3;
    // 0x80800204: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
    // 0x80800208: beql        $v0, $zero, L_8080023C
    if (ctx->r2 == 0) {
        // 0x8080020C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080023C;
    }
    goto skip_3;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800210: jal         0x800A3274
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_4;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800218: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080021C: bne         $v0, $at, L_8080022C
    if (ctx->r2 != ctx->r1) {
        // 0x80800220: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080022C;
    }
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800224: b           L_80800230
    // 0x80800228: addiu       $a1, $zero, 0x459D
    ctx->r5 = ADD32(0, 0X459D);
        goto L_80800230;
    // 0x80800228: addiu       $a1, $zero, 0x459D
    ctx->r5 = ADD32(0, 0X459D);
L_8080022C:
    // 0x8080022C: addiu       $a1, $zero, 0x3EB
    ctx->r5 = ADD32(0, 0X3EB);
L_80800230:
    // 0x80800230: jal         0x8009DE38
    // 0x80800234: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_5;
    // 0x80800234: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080023C:
    // 0x8080023C: jal         0x80095738
    // 0x80800240: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baflag_isTrue(rdram, ctx);
        goto after_6;
    // 0x80800240: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80800244: beq         $v0, $zero, L_80800270
    if (ctx->r2 == 0) {
        // 0x80800248: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800270;
    }
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080024C: jal         0x80095774
    // 0x80800250: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baflag_clear(rdram, ctx);
        goto after_7;
    // 0x80800250: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80800254: jal         0x80800020
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800020_bashoes(rdram, ctx);
        goto after_8;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080025C: lw          $t8, 0x10C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10C);
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800268: jal         0x800917A8
    // 0x8080026C: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    bastatetimer_set(rdram, ctx);
        goto after_9;
    // 0x8080026C: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    after_9:
L_80800270:
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800274: jal         0x800915AC
    // 0x80800278: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bastatetimer_isDone(rdram, ctx);
        goto after_10;
    // 0x80800278: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x8080027C: beql        $v0, $zero, L_808002A4
    if (ctx->r2 == 0) {
        // 0x80800280: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002A4;
    }
    goto skip_4;
    // 0x80800280: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80800284: lw          $t9, 0x10C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10C);
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: lbu         $t0, 0x5($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X5);
    // 0x80800290: bnel        $t0, $zero, L_808002A4
    if (ctx->r8 != 0) {
        // 0x80800294: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002A4;
    }
    goto skip_5;
    // 0x80800294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80800298: jal         0x80800384
    // 0x8080029C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bashoes_entrypoint_6(rdram, ctx);
        goto after_11;
    // 0x8080029C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x808002A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002A4:
    // 0x808002A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002AC: jr          $ra
    // 0x808002B0: nop

    return;
    // 0x808002B0: nop

;}
RECOMP_FUNC void func_800F2EBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2EBC: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800F2EC0: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x800F2EC4: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x800F2EC8: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x800F2ECC: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x800F2ED0: sb          $t8, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r24;
    // 0x800F2ED4: lbu         $t9, 0x3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X3);
    // 0x800F2ED8: jr          $ra
    // 0x800F2EDC: sb          $t9, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r25;
    return;
    // 0x800F2EDC: sb          $t9, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void _gcnewpause_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088210: syscall     675
    recomp_syscall_handler(rdram, ctx, 0x80088210);
    return;
    // 0x80088214: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800C9598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C959C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C95A0: jal         0x800C91C8
    // 0x800C95A4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800C91C8(rdram, ctx);
        goto after_0;
    // 0x800C95A4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x800C95A8: bne         $v0, $zero, L_800C95BC
    if (ctx->r2 != 0) {
        // 0x800C95AC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800C95BC;
    }
    // 0x800C95AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C95B0: jal         0x800C9150
    // 0x800C95B4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800C9150(rdram, ctx);
        goto after_1;
    // 0x800C95B4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x800C95B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800C95BC:
    // 0x800C95BC: jal         0x800881B0
    // 0x800C95C0: nop

    _gctransitionDll_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x800C95C0: nop

    after_2:
    // 0x800C95C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C95C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C95CC: jr          $ra
    // 0x800C95D0: nop

    return;
    // 0x800C95D0: nop

;}
RECOMP_FUNC void func_800F4BB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4BB8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4BBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4BC0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4BC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4BC8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4BCC: jal         0x800F3A78
    // 0x800F4BD0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800F3A78(rdram, ctx);
        goto after_0;
    // 0x800F4BD0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F4BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4BD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4BDC: jr          $ra
    // 0x800F4BE0: nop

    return;
    // 0x800F4BE0: nop

;}
RECOMP_FUNC void _bsdronexform_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800831B8: syscall     50
    recomp_syscall_handler(rdram, ctx, 0x800831B8);
    return;
    // 0x800831BC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _plcamera_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087920: syscall     639
    recomp_syscall_handler(rdram, ctx, 0x80087920);
    return;
    // 0x80087924: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void _chwaspstatue_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087630: syscall     599
    recomp_syscall_handler(rdram, ctx, 0x80087630);
    return;
    // 0x80087634: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800B8C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8C98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8C9C: jr          $ra
    // 0x800B8CA0: sb          $a0, -0x7D3A($at)
    MEM_B(-0X7D3A, ctx->r1) = ctx->r4;
    return;
    // 0x800B8CA0: sb          $a0, -0x7D3A($at)
    MEM_B(-0X7D3A, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void anseq_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080029C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002A0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808002A4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x808002A8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x808002AC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x808002B0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x808002B4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x808002B8: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x808002BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002C0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808002C4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x808002C8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x808002CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808002D0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808002D4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x808002D8: jal         0x80800134
    // 0x808002DC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80800134_anseq(rdram, ctx);
        goto after_0;
    // 0x808002DC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x808002E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808002E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002E8: jr          $ra
    // 0x808002EC: nop

    return;
    // 0x808002EC: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803410: lbu         $t6, 0x177($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X177);
    // 0x80803414: andi        $t7, $t6, 0xFE
    ctx->r15 = ctx->r14 & 0XFE;
    // 0x80803418: jr          $ra
    // 0x8080341C: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
    return;
    // 0x8080341C: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_8080419C_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080419C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808041A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808041A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808041A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808041AC: jal         0x80106790
    // 0x808041B0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808041B0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808041B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808041B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808041BC: jal         0x80089AC8
    // 0x808041C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808041C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x808041C4: beq         $v0, $zero, L_808041E4
    if (ctx->r2 == 0) {
        // 0x808041C8: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_808041E4;
    }
    // 0x808041C8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808041CC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808041D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808041D4: jal         0x800F5A00
    // 0x808041D8: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x808041D8: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_2:
    // 0x808041DC: b           L_8080420C
    // 0x808041E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080420C;
    // 0x808041E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808041E4:
    // 0x808041E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808041E8: jal         0x80089AD8
    // 0x808041EC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _sukickball_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x808041EC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x808041F0: jal         0x80106790
    // 0x808041F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x808041F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808041F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808041FC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80804200: jal         0x800EE7F8
    // 0x80804204: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80804204: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_5:
    // 0x80804208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080420C:
    // 0x8080420C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804210: jr          $ra
    // 0x80804214: nop

    return;
    // 0x80804214: nop

;}
RECOMP_FUNC void _gcdialogcamera_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800880C0: syscall     669
    recomp_syscall_handler(rdram, ctx, 0x800880C0);
    return;
    // 0x800880C4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void bsblongleg_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800BFC: jal         0x800C2FDC
    // 0x80800C00: lbu         $a0, 0x160($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X160);
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x80800C00: lbu         $a0, 0x160($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X160);
    after_0:
    // 0x80800C04: jal         0x80800204
    // 0x80800C08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800204_bsblongleg(rdram, ctx);
        goto after_1;
    // 0x80800C08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C14: jr          $ra
    // 0x80800C18: nop

    return;
    // 0x80800C18: nop

;}
RECOMP_FUNC void func_8001C2AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C2AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C2B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C2B4: lui         $a2, 0x8001
    ctx->r6 = S32(0X8001 << 16);
    // 0x8001C2B8: jal         0x8001C324
    // 0x8001C2BC: addiu       $a2, $a2, -0x1800
    ctx->r6 = ADD32(ctx->r6, -0X1800);
    func_8001C324(rdram, ctx);
        goto after_0;
    // 0x8001C2BC: addiu       $a2, $a2, -0x1800
    ctx->r6 = ADD32(ctx->r6, -0X1800);
    after_0:
    // 0x8001C2C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C2C4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001C2C8: sw          $v0, -0x3900($at)
    MEM_W(-0X3900, ctx->r1) = ctx->r2;
    // 0x8001C2CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001C2D0: jr          $ra
    // 0x8001C2D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001C2D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001E304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E304: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E30C: jal         0x8001D96C
    // 0x8001E310: nop

    func_8001D96C(rdram, ctx);
        goto after_0;
    // 0x8001E310: nop

    after_0:
    // 0x8001E314: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001E318: jal         0x8001D37C
    // 0x8001E31C: addiu       $a0, $a0, 0x1868
    ctx->r4 = ADD32(ctx->r4, 0X1868);
    func_8001D37C(rdram, ctx);
        goto after_1;
    // 0x8001E31C: addiu       $a0, $a0, 0x1868
    ctx->r4 = ADD32(ctx->r4, 0X1868);
    after_1:
    // 0x8001E320: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001E324: jal         0x8001D9CC
    // 0x8001E328: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8001D9CC(rdram, ctx);
        goto after_2;
    // 0x8001E328: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_2:
    // 0x8001E32C: jal         0x8008A960
    // 0x8001E330: nop

    _gzreg_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x8001E330: nop

    after_3:
    // 0x8001E334: jal         0x8001E2A0
    // 0x8001E338: nop

    func_8001E2A0(rdram, ctx);
        goto after_4;
    // 0x8001E338: nop

    after_4:
    // 0x8001E33C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E344: jr          $ra
    // 0x8001E348: nop

    return;
    // 0x8001E348: nop

;}
RECOMP_FUNC void func_8009F440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F440: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8009F444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009F448: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8009F44C: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x8009F450: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8009F454: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x8009F458: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x8009F45C: jal         0x800A30B4
    // 0x8009F460: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800A30B4(rdram, ctx);
        goto after_0;
    // 0x8009F460: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x8009F464: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009F468: jal         0x800F4200
    // 0x8009F46C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_800F4200(rdram, ctx);
        goto after_1;
    // 0x8009F46C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_1:
    // 0x8009F470: jal         0x80019CD4
    // 0x8009F474: nop

    func_80019CD4(rdram, ctx);
        goto after_2;
    // 0x8009F474: nop

    after_2:
    // 0x8009F478: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x8009F47C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x8009F480: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8009F484: jal         0x8001980C
    // 0x8009F488: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8001980C(rdram, ctx);
        goto after_3;
    // 0x8009F488: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8009F48C: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8009F490: jal         0x800193C4
    // 0x8009F494: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_800193C4(rdram, ctx);
        goto after_4;
    // 0x8009F494: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_4:
    // 0x8009F498: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8009F49C: jal         0x800EF04C
    // 0x8009F4A0: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x8009F4A0: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_5:
    // 0x8009F4A4: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8009F4A8: jal         0x800EF04C
    // 0x8009F4AC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x8009F4AC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_6:
    // 0x8009F4B0: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x8009F4B4: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8009F4B8: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    // 0x8009F4BC: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8009F4C0: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8009F4C4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8009F4C8: nop

    // 0x8009F4CC: bc1t        L_8009F4E8
    if (c1cs) {
        // 0x8009F4D0: nop
    
            goto L_8009F4E8;
    }
    // 0x8009F4D0: nop

    // 0x8009F4D4: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8009F4D8: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8009F4DC: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8009F4E0: bc1fl       L_8009F4F4
    if (!c1cs) {
        // 0x8009F4E4: lwc1        $f6, 0x0($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
            goto L_8009F4F4;
    }
    goto skip_0;
    // 0x8009F4E4: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    skip_0:
L_8009F4E8:
    // 0x8009F4E8: b           L_8009F668
    // 0x8009F4EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009F668;
    // 0x8009F4EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009F4F0: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
L_8009F4F4:
    // 0x8009F4F4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009F4F8: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8009F4FC: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8009F500: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8009F504: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x8009F508: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8009F50C: bc1t        L_8009F524
    if (c1cs) {
        // 0x8009F510: nop
    
            goto L_8009F524;
    }
    // 0x8009F510: nop

    // 0x8009F514: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x8009F518: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8009F51C: bc1fl       L_8009F530
    if (!c1cs) {
        // 0x8009F520: neg.s       $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
            goto L_8009F530;
    }
    goto skip_1;
    // 0x8009F520: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    skip_1:
L_8009F524:
    // 0x8009F524: b           L_8009F668
    // 0x8009F528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009F668;
    // 0x8009F528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009F52C: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
L_8009F530:
    // 0x8009F530: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8009F534: nop

    // 0x8009F538: bc1fl       L_8009F54C
    if (!c1cs) {
        // 0x8009F53C: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_8009F54C;
    }
    goto skip_2;
    // 0x8009F53C: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_2:
    // 0x8009F540: b           L_8009F54C
    // 0x8009F544: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_8009F54C;
    // 0x8009F544: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8009F548: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_8009F54C:
    // 0x8009F54C: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8009F550: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8009F554: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8009F558: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8009F55C: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8009F560: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x8009F564: nop

    // 0x8009F568: bc1t        L_8009F580
    if (c1cs) {
        // 0x8009F56C: nop
    
            goto L_8009F580;
    }
    // 0x8009F56C: nop

    // 0x8009F570: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x8009F574: nop

    // 0x8009F578: bc1fl       L_8009F58C
    if (!c1cs) {
        // 0x8009F57C: neg.s       $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
            goto L_8009F58C;
    }
    goto skip_3;
    // 0x8009F57C: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    skip_3:
L_8009F580:
    // 0x8009F580: b           L_8009F668
    // 0x8009F584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009F668;
    // 0x8009F584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009F588: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
L_8009F58C:
    // 0x8009F58C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8009F590: nop

    // 0x8009F594: bc1fl       L_8009F5A8
    if (!c1cs) {
        // 0x8009F598: swc1        $f2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
            goto L_8009F5A8;
    }
    goto skip_4;
    // 0x8009F598: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    skip_4:
    // 0x8009F59C: b           L_8009F5A8
    // 0x8009F5A0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
        goto L_8009F5A8;
    // 0x8009F5A0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8009F5A4: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
L_8009F5A8:
    // 0x8009F5A8: jal         0x800D8FF8
    // 0x8009F5AC: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_7;
    // 0x8009F5AC: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_7:
    // 0x8009F5B0: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8009F5B4: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8009F5B8: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8009F5BC: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8009F5C0: jal         0x800F1660
    // 0x8009F5C4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_800F1660(rdram, ctx);
        goto after_8;
    // 0x8009F5C4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x8009F5C8: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8009F5CC: beq         $v0, $zero, L_8009F600
    if (ctx->r2 == 0) {
        // 0x8009F5D0: lwc1        $f14, 0x28($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
            goto L_8009F600;
    }
    // 0x8009F5D0: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8009F5D4: jal         0x800F0DC0
    // 0x8009F5D8: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    func_800F0DC0(rdram, ctx);
        goto after_9;
    // 0x8009F5D8: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x8009F5DC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009F5E0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8009F5E4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8009F5E8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8009F5EC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8009F5F0: jal         0x800EFA4C
    // 0x8009F5F4: nop

    func_800EFA4C(rdram, ctx);
        goto after_10;
    // 0x8009F5F4: nop

    after_10:
    // 0x8009F5F8: b           L_8009F628
    // 0x8009F5FC: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
        goto L_8009F628;
    // 0x8009F5FC: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
L_8009F600:
    // 0x8009F600: jal         0x800F0DC0
    // 0x8009F604: nop

    func_800F0DC0(rdram, ctx);
        goto after_11;
    // 0x8009F604: nop

    after_11:
    // 0x8009F608: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009F60C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009F610: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8009F614: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8009F618: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8009F61C: jal         0x800EFA4C
    // 0x8009F620: nop

    func_800EFA4C(rdram, ctx);
        goto after_12;
    // 0x8009F620: nop

    after_12:
    // 0x8009F624: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
L_8009F628:
    // 0x8009F628: jal         0x800EF04C
    // 0x8009F62C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EF04C(rdram, ctx);
        goto after_13;
    // 0x8009F62C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_13:
    // 0x8009F630: jal         0x80019CD4
    // 0x8009F634: nop

    func_80019CD4(rdram, ctx);
        goto after_14;
    // 0x8009F634: nop

    after_14:
    // 0x8009F638: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x8009F63C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x8009F640: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8009F644: jal         0x80019750
    // 0x8009F648: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80019750(rdram, ctx);
        goto after_15;
    // 0x8009F648: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x8009F64C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8009F650: jal         0x800193C4
    // 0x8009F654: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800193C4(rdram, ctx);
        goto after_16;
    // 0x8009F654: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_16:
    // 0x8009F658: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009F65C: jal         0x800F4648
    // 0x8009F660: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_800F4648(rdram, ctx);
        goto after_17;
    // 0x8009F660: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_17:
    // 0x8009F664: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009F668:
    // 0x8009F668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009F66C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8009F670: jr          $ra
    // 0x8009F674: nop

    return;
    // 0x8009F674: nop

;}
RECOMP_FUNC void _chbaddiesetup_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D68: syscall     449
    recomp_syscall_handler(rdram, ctx, 0x80086D68);
    return;
    // 0x80086D6C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _basnowball_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085138: syscall     151
    recomp_syscall_handler(rdram, ctx, 0x80085138);
    return;
    // 0x8008513C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_808003C4_chpodiumbankaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003C8: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x808003CC: bne         $a1, $at, L_808003DC
    if (ctx->r5 != ctx->r1) {
        // 0x808003D0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808003DC;
    }
    // 0x808003D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003D4: jal         0x80089C98
    // 0x808003D8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808003D8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_0:
L_808003DC:
    // 0x808003DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003E4: jr          $ra
    // 0x808003E8: nop

    return;
    // 0x808003E8: nop

;}
RECOMP_FUNC void func_80800BA4_chfantasycannon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BAC: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800BB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800BB4: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80800BB8: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800BBC: bne         $t7, $at, L_80800BCC
    if (ctx->r15 != ctx->r1) {
        // 0x80800BC0: swc1        $f4, 0x48($a0)
        MEM_W(0X48, ctx->r4) = ctx->f4.u32l;
            goto L_80800BCC;
    }
    // 0x80800BC0: swc1        $f4, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f4.u32l;
    // 0x80800BC4: jal         0x800FFAB0
    // 0x80800BC8: nop

    func_800FFAB0(rdram, ctx);
        goto after_0;
    // 0x80800BC8: nop

    after_0:
L_80800BCC:
    // 0x80800BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BD4: jr          $ra
    // 0x80800BD8: nop

    return;
    // 0x80800BD8: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808A10: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80808A14: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB5B0) << 16);
    // 0x80808A18: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80808A1C: jr          $ra
    // 0x80808A20: lw          $v0, -0x4A50($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB5B0));
    return;
    // 0x80808A20: lw          $v0, -0x4A50($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB5B0));
;}
