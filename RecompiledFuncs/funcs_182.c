#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bskazjump_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083470: syscall     62
    recomp_syscall_handler(rdram, ctx, 0x80083470);
    return;
    // 0x80083474: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_8008FD98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FD98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FD9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FDA0: jal         0x800F54E4
    // 0x8008FDA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FDA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008FDA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FDAC: jal         0x800F549C
    // 0x8008FDB0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F549C(rdram, ctx);
        goto after_1;
    // 0x8008FDB0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008FDB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FDB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FDBC: jr          $ra
    // 0x8008FDC0: nop

    return;
    // 0x8008FDC0: nop

;}
RECOMP_FUNC void chstarspinnerctrl_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(960, 0X974) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x974
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(960, 0X974));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x974
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(960, 0X974));
;}
RECOMP_FUNC void func_808090D8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808090D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808090DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808090E0: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x808090E4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x808090E8: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x808090EC: jal         0x80808DB0
    // 0x808090F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80808DB0_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808090F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808090F4: jal         0x8008E95C
    // 0x808090F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E95C(rdram, ctx);
        goto after_1;
    // 0x808090F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808090FC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80809100: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80809104: jal         0x800F7F98
    // 0x80809108: lw          $a0, 0x184($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X184);
    func_800F7F98(rdram, ctx);
        goto after_2;
    // 0x80809108: lw          $a0, 0x184($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X184);
    after_2:
    // 0x8080910C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80809110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80809114: jr          $ra
    // 0x80809118: nop

    return;
    // 0x80809118: nop

;}
RECOMP_FUNC void func_800D7900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7900: jr          $ra
    // 0x800D7904: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800D7904: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800D90A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D90A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D90A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D90AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D90B0: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800D90B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D90B8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800D90BC: nop

    // 0x800D90C0: bc1fl       L_800D90E8
    if (!c1cs) {
        // 0x800D90C4: swc1        $f0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
            goto L_800D90E8;
    }
    goto skip_0;
    // 0x800D90C4: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    skip_0:
    // 0x800D90C8: jal         0x800D8FF8
    // 0x800D90CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800D90CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D90D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800D90D4: jal         0x800F1574
    // 0x800D90D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F1574(rdram, ctx);
        goto after_1;
    // 0x800D90D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800D90DC: b           L_800D90EC
    // 0x800D90E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D90EC;
    // 0x800D90E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D90E4: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
L_800D90E8:
    // 0x800D90E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D90EC:
    // 0x800D90EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D90F0: jr          $ra
    // 0x800D90F4: nop

    return;
    // 0x800D90F4: nop

;}
RECOMP_FUNC void chegggolden_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800298: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080029C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002A4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808002A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808002AC: jal         0x8008A488
    // 0x808002B0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    _sueggmove_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x808002B0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808002B4: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    // 0x808002B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808002BC: jal         0x8008A3D0
    // 0x808002C0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    _suegg_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808002C0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x808002C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2112, 0X3E4) << 16);
    // 0x808002C8: lwc1        $f4, 0x3E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2112, 0X3E4));
    // 0x808002CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808002D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002D4: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x808002D8: jal         0x8008A380
    // 0x808002DC: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    _suegg_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808002DC: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    after_2:
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E4: jal         0x8008A460
    // 0x808002E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sueggmove_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808002E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808002EC: lui         $a1, 0xC509
    ctx->r5 = S32(0XC509 << 16);
    // 0x808002F0: lui         $a2, 0xC6AB
    ctx->r6 = S32(0XC6AB << 16);
    // 0x808002F4: ori         $a2, $a2, 0xE000
    ctx->r6 = ctx->r6 | 0XE000;
    // 0x808002F8: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x808002FC: jal         0x8008A468
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmove_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800308: jal         0x8008A470
    // 0x8080030C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _sueggmove_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x8080030C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800310: lbu         $t6, 0x72($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X72);
    // 0x80800314: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800318: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x8080031C: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80800320: sb          $t8, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r24;
    // 0x80800324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800328: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080032C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800330: jr          $ra
    // 0x80800334: nop

    return;
    // 0x80800334: nop

;}
RECOMP_FUNC void gctransitionDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D0: lbu         $v0, 0x1C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1C);
    // 0x808008D4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x808008D8: jr          $ra
    // 0x808008DC: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
    return;
    // 0x808008DC: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
;}
RECOMP_FUNC void func_800C57F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C57F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C57F4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800C57F8: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C57FC: addiu       $s1, $s1, -0x55E0
    ctx->r17 = ADD32(ctx->r17, -0X55E0);
    // 0x800C5800: lbu         $t6, 0x11($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X11);
    // 0x800C5804: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C5808: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800C580C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800C5810: beq         $t6, $zero, L_800C594C
    if (ctx->r14 == 0) {
        // 0x800C5814: sdc1        $f20, 0x20($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
            goto L_800C594C;
    }
    // 0x800C5814: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800C5818: jal         0x800D8FF8
    // 0x800C581C: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800C581C: nop

    after_0:
    // 0x800C5820: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800C5824: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800C5828: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800C582C: jal         0x800F0E00
    // 0x800C5830: sub.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f0.fl;
    func_800F0E00(rdram, ctx);
        goto after_1;
    // 0x800C5830: sub.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f0.fl;
    after_1:
    // 0x800C5834: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C5838: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800C583C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x800C5840: addiu       $s2, $s2, -0x55DD
    ctx->r18 = ADD32(ctx->r18, -0X55DD);
    // 0x800C5844: addiu       $s0, $s0, -0x55E0
    ctx->r16 = ADD32(ctx->r16, -0X55E0);
L_800C5848:
    // 0x800C5848: lbu         $t7, 0xE($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XE);
    // 0x800C584C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800C5850: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800C5854: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800C5858: lwc1        $f14, 0x4($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800C585C: bgez        $t7, L_800C5874
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800C5860: cvt.s.w     $f6, $f6
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800C5874;
    }
    // 0x800C5860: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C5864: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C5868: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C586C: nop

    // 0x800C5870: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800C5874:
    // 0x800C5874: lbu         $t8, 0xB($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XB);
    // 0x800C5878: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800C587C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C5880: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800C5884: bgez        $t8, L_800C5898
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800C5888: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800C5898;
    }
    // 0x800C5888: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C588C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C5890: nop

    // 0x800C5894: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800C5898:
    // 0x800C5898: jal         0x800F10B4
    // 0x800C589C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x800C589C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x800C58A0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800C58A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C58A8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800C58AC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800C58B0: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800C58B4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800C58B8: nop

    // 0x800C58BC: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800C58C0: beql        $t0, $zero, L_800C5910
    if (ctx->r8 == 0) {
        // 0x800C58C4: mfc1        $t0, $f4
        ctx->r8 = (int32_t)ctx->f4.u32l;
            goto L_800C5910;
    }
    goto skip_0;
    // 0x800C58C4: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x800C58C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C58CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C58D0: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800C58D4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800C58D8: nop

    // 0x800C58DC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800C58E0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800C58E4: nop

    // 0x800C58E8: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800C58EC: bne         $t0, $zero, L_800C5904
    if (ctx->r8 != 0) {
        // 0x800C58F0: nop
    
            goto L_800C5904;
    }
    // 0x800C58F0: nop

    // 0x800C58F4: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x800C58F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C58FC: b           L_800C591C
    // 0x800C5900: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_800C591C;
    // 0x800C5900: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_800C5904:
    // 0x800C5904: b           L_800C591C
    // 0x800C5908: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800C591C;
    // 0x800C5908: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800C590C: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
L_800C5910:
    // 0x800C5910: nop

    // 0x800C5914: bltz        $t0, L_800C5904
    if (SIGNED(ctx->r8) < 0) {
        // 0x800C5918: nop
    
            goto L_800C5904;
    }
    // 0x800C5918: nop

L_800C591C:
    // 0x800C591C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C5920: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800C5924: bne         $s0, $s2, L_800C5848
    if (ctx->r16 != ctx->r18) {
        // 0x800C5928: sb          $t0, 0x7($s0)
        MEM_B(0X7, ctx->r16) = ctx->r8;
            goto L_800C5848;
    }
    // 0x800C5928: sb          $t0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r8;
    // 0x800C592C: jal         0x800C57C0
    // 0x800C5930: nop

    func_800C57C0(rdram, ctx);
        goto after_3;
    // 0x800C5930: nop

    after_3:
    // 0x800C5934: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800C5938: c.eq.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl == ctx->f6.fl;
    // 0x800C593C: nop

    // 0x800C5940: bc1fl       L_800C5950
    if (!c1cs) {
        // 0x800C5944: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800C5950;
    }
    goto skip_1;
    // 0x800C5944: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x800C5948: sb          $zero, 0x11($s1)
    MEM_B(0X11, ctx->r17) = 0;
L_800C594C:
    // 0x800C594C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800C5950:
    // 0x800C5950: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800C5954: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800C5958: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800C595C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800C5960: jr          $ra
    // 0x800C5964: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C5964: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void cothemedll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800250: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800254: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800258: jal         0x800EA05C
    // 0x8080025C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080025C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800260: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800264: jal         0x80800000
    // 0x80800268: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80800000_cothemedll(rdram, ctx);
        goto after_1;
    // 0x80800268: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080026C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800270: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80800274: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800278: sb          $zero, 0x41($s0)
    MEM_B(0X41, ctx->r16) = 0;
    // 0x8080027C: sw          $a1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r5;
    // 0x80800280: sw          $a1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r5;
    // 0x80800284: sb          $v1, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r3;
    // 0x80800288: jal         0x800FE890
    // 0x8080028C: sb          $v1, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r3;
    func_800FE890(rdram, ctx);
        goto after_2;
    // 0x8080028C: sb          $v1, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r3;
    after_2:
    // 0x80800290: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800294: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800298: beq         $v0, $at, L_80800374
    if (ctx->r2 == ctx->r1) {
        // 0x8080029C: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_80800374;
    }
    // 0x8080029C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808002A0: lbu         $t6, 0x16($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X16);
    // 0x808002A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808002B0: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x808002B4: sh          $zero, 0x22($s0)
    MEM_H(0X22, ctx->r16) = 0;
    // 0x808002B8: sh          $zero, 0x20($s0)
    MEM_H(0X20, ctx->r16) = 0;
    // 0x808002BC: sb          $zero, 0x12($s0)
    MEM_B(0X12, ctx->r16) = 0;
    // 0x808002C0: sb          $zero, 0x13($s0)
    MEM_B(0X13, ctx->r16) = 0;
    // 0x808002C4: sb          $v0, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r2;
    // 0x808002C8: sb          $v0, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r2;
    // 0x808002CC: beq         $t6, $zero, L_80800374
    if (ctx->r14 == 0) {
        // 0x808002D0: swc1        $f4, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
            goto L_80800374;
    }
    // 0x808002D0: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x808002D4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808002D8: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2508, 0X730) << 16);
    // 0x808002DC: addiu       $t9, $t9, 0x730
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2508, 0X730));
    // 0x808002E0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808002E4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x808002E8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x808002EC: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x808002F0: lhu         $t0, 0x2($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X2);
    // 0x808002F4: addiu       $t4, $zero, 0x4E20
    ctx->r12 = ADD32(0, 0X4E20);
    // 0x808002F8: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x808002FC: sh          $t1, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r9;
    // 0x80800300: lh          $t2, 0x2($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X2);
    // 0x80800304: sra         $t3, $t2, 2
    ctx->r11 = S32(SIGNED(ctx->r10) >> 2);
    // 0x80800308: sh          $t3, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r11;
    // 0x8080030C: lh          $a0, 0x8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X8);
    // 0x80800310: beql        $a1, $a0, L_80800334
    if (ctx->r5 == ctx->r4) {
        // 0x80800314: sh          $t4, 0xA($s0)
        MEM_H(0XA, ctx->r16) = ctx->r12;
            goto L_80800334;
    }
    goto skip_0;
    // 0x80800314: sh          $t4, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r12;
    skip_0:
    // 0x80800318: jal         0x80017764
    // 0x8080031C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80017764(rdram, ctx);
        goto after_3;
    // 0x8080031C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x80800320: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800324: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x80800328: b           L_80800334
    // 0x8080032C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_80800334;
    // 0x8080032C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800330: sh          $t4, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r12;
L_80800334:
    // 0x80800334: sh          $zero, 0x24($s0)
    MEM_H(0X24, ctx->r16) = 0;
    // 0x80800338: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2508, 0XCB4) << 16);
    // 0x8080033C: lh          $t5, 0xCB4($t5)
    ctx->r13 = MEM_H(ctx->r13, (int16_t)RELOC_LO16(2508, 0XCB4));
    // 0x80800340: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2508, 0XCB4) << 16);
    // 0x80800344: addiu       $v0, $t6, 0xCB4
    ctx->r2 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2508, 0XCB4));
    // 0x80800348: beql        $a1, $t5, L_80800378
    if (ctx->r5 == ctx->r13) {
        // 0x8080034C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800378;
    }
    goto skip_1;
    // 0x8080034C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800350: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
L_80800354:
    // 0x80800354: bnel        $a2, $v1, L_80800368
    if (ctx->r6 != ctx->r3) {
        // 0x80800358: lh          $v1, 0x4($v0)
        ctx->r3 = MEM_H(ctx->r2, 0X4);
            goto L_80800368;
    }
    goto skip_2;
    // 0x80800358: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    skip_2:
    // 0x8080035C: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80800360: sh          $t7, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r15;
    // 0x80800364: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
L_80800368:
    // 0x80800368: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080036C: bne         $a1, $v1, L_80800354
    if (ctx->r5 != ctx->r3) {
        // 0x80800370: nop
    
            goto L_80800354;
    }
    // 0x80800370: nop

L_80800374:
    // 0x80800374: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800378:
    // 0x80800378: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080037C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800380: jr          $ra
    // 0x80800384: nop

    return;
    // 0x80800384: nop

;}
RECOMP_FUNC void _badata_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084690: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084690);
    return;
    // 0x80084694: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _chlavaarchgrillswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086FD8: syscall     490
    recomp_syscall_handler(rdram, ctx, 0x80086FD8);
    return;
    // 0x80086FDC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080095C_charmouredcaveman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080095C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800960: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800964: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800968: lbu         $t6, 0x65($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X65);
    // 0x8080096C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800970: andi        $t7, $t6, 0xFFF7
    ctx->r15 = ctx->r14 & 0XFFF7;
    // 0x80800974: sb          $t7, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r15;
    // 0x80800978: jal         0x800DA298
    // 0x8080097C: addiu       $a0, $zero, 0x66C
    ctx->r4 = ADD32(0, 0X66C);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080097C: addiu       $a0, $zero, 0x66C
    ctx->r4 = ADD32(0, 0X66C);
    after_0:
    // 0x80800980: bne         $v0, $zero, L_808009B4
    if (ctx->r2 != 0) {
        // 0x80800984: addiu       $a1, $zero, 0x17E2
        ctx->r5 = ADD32(0, 0X17E2);
            goto L_808009B4;
    }
    // 0x80800984: addiu       $a1, $zero, 0x17E2
    ctx->r5 = ADD32(0, 0X17E2);
    // 0x80800988: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080098C: addiu       $t8, $zero, 0xA6
    ctx->r24 = ADD32(0, 0XA6);
    // 0x80800990: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800994: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800998: jal         0x8008A208
    // 0x8080099C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x8080099C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x808009A0: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009A8: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x808009AC: jal         0x8010A570
    // 0x808009B0: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x808009B0: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    after_2:
L_808009B4:
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B8: jal         0x80102424
    // 0x808009BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x808009BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x808009C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808009C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808009C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009CC: jr          $ra
    // 0x808009D0: nop

    return;
    // 0x808009D0: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A38: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800A3C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800A40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800A44: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800A48: addiu       $a2, $zero, 0x260
    ctx->r6 = ADD32(0, 0X260);
    // 0x80800A4C: jal         0x80100074
    // 0x80800A50: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x80800A50: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    after_0:
    // 0x80800A54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800A58: jal         0x80100094
    // 0x80800A5C: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800A5C: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    after_1:
    // 0x80800A60: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800A64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A68: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800A6C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800A70: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A74: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800A78: jal         0x80800A90
    // 0x80800A7C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    gcnewoption_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800A7C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
    // 0x80800A80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A88: jr          $ra
    // 0x80800A8C: nop

    return;
    // 0x80800A8C: nop

;}
RECOMP_FUNC void func_8009E0B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E0B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E0BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E0C0: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009E0C4: jal         0x800C3CE8
    // 0x8009E0C8: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    func_800C3CE8(rdram, ctx);
        goto after_0;
    // 0x8009E0C8: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    after_0:
    // 0x8009E0CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E0D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E0D4: jr          $ra
    // 0x8009E0D8: nop

    return;
    // 0x8009E0D8: nop

;}
RECOMP_FUNC void func_80800CC0_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CC0: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x80800CC4: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x80800CC8: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80800CCC: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80800CD0: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x80800CD4: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x80800CD8: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80800CDC: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80800CE0: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80800CE4: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80800CE8: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80800CEC: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80800CF0: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80800CF4: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80800CF8: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80800CFC: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800D00: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800D04: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800D08: jal         0x80100094
    // 0x80800D0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D10: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800D14: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x80800D18: jal         0x8010262C
    // 0x80800D1C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_8010262C(rdram, ctx);
        goto after_1;
    // 0x80800D1C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_1:
    // 0x80800D20: beq         $v0, $zero, L_80801998
    if (ctx->r2 == 0) {
        // 0x80800D24: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80801998;
    }
    // 0x80800D24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D28: jal         0x800E0ACC
    // 0x80800D2C: sw          $v0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r2;
    func_800E0ACC(rdram, ctx);
        goto after_2;
    // 0x80800D2C: sw          $v0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800D30: lw          $a0, 0xFC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XFC);
    // 0x80800D34: jal         0x800E0AF0
    // 0x80800D38: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800E0AF0(rdram, ctx);
        goto after_3;
    // 0x80800D38: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x80800D3C: lui         $fp, 0x8080
    ctx->r30 = S32(RELOC_HI16(772, 0X3CC0) << 16);
    // 0x80800D40: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X39B8) << 16);
    // 0x80800D44: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80800D48: lwc1        $f30, 0x39B8($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X39B8));
    // 0x80800D4C: addiu       $fp, $fp, 0x3CC0
    ctx->r30 = ADD32(ctx->r30, (int16_t)RELOC_LO16(772, 0X3CC0));
    // 0x80800D50: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80800D54: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x80800D58: lwc1        $f28, 0xE4($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80800D5C: lwc1        $f26, 0xF8($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80800D60: lwc1        $f22, 0xF4($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80800D64: addiu       $s7, $zero, 0xC
    ctx->r23 = ADD32(0, 0XC);
    // 0x80800D68: addiu       $s3, $sp, 0xE8
    ctx->r19 = ADD32(ctx->r29, 0XE8);
L_80800D6C:
    // 0x80800D6C: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x80800D70: slti        $at, $v0, 0x3001
    ctx->r1 = SIGNED(ctx->r2) < 0X3001 ? 1 : 0;
    // 0x80800D74: bne         $at, $zero, L_80800DD4
    if (ctx->r1 != 0) {
        // 0x80800D78: addiu       $at, $zero, 0x32D4
        ctx->r1 = ADD32(0, 0X32D4);
            goto L_80800DD4;
    }
    // 0x80800D78: addiu       $at, $zero, 0x32D4
    ctx->r1 = ADD32(0, 0X32D4);
    // 0x80800D7C: beq         $v0, $at, L_80801548
    if (ctx->r2 == ctx->r1) {
        // 0x80800D80: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_80801548;
    }
    // 0x80800D80: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80800D84: addiu       $at, $zero, 0x6B54
    ctx->r1 = ADD32(0, 0X6B54);
    // 0x80800D88: beq         $v0, $at, L_80800F5C
    if (ctx->r2 == ctx->r1) {
        // 0x80800D8C: sll         $t3, $s4, 2
        ctx->r11 = S32(ctx->r20 << 2);
            goto L_80800F5C;
    }
    // 0x80800D8C: sll         $t3, $s4, 2
    ctx->r11 = S32(ctx->r20 << 2);
    // 0x80800D90: ori         $at, $zero, 0xA000
    ctx->r1 = 0 | 0XA000;
    // 0x80800D94: beq         $v0, $at, L_8080172C
    if (ctx->r2 == ctx->r1) {
        // 0x80800D98: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8080172C;
    }
    // 0x80800D98: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800D9C: ori         $at, $zero, 0xB41D
    ctx->r1 = 0 | 0XB41D;
    // 0x80800DA0: beq         $v0, $at, L_8080179C
    if (ctx->r2 == ctx->r1) {
        // 0x80800DA4: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_8080179C;
    }
    // 0x80800DA4: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80800DA8: ori         $at, $zero, 0xB825
    ctx->r1 = 0 | 0XB825;
    // 0x80800DAC: beq         $v0, $at, L_8080162C
    if (ctx->r2 == ctx->r1) {
        // 0x80800DB0: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_8080162C;
    }
    // 0x80800DB0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80800DB4: ori         $at, $zero, 0xE825
    ctx->r1 = 0 | 0XE825;
    // 0x80800DB8: beq         $v0, $at, L_8080189C
    if (ctx->r2 == ctx->r1) {
        // 0x80800DBC: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_8080189C;
    }
    // 0x80800DBC: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80800DC0: ori         $at, $zero, 0xF018
    ctx->r1 = 0 | 0XF018;
    // 0x80800DC4: beq         $v0, $at, L_8080123C
    if (ctx->r2 == ctx->r1) {
        // 0x80800DC8: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_8080123C;
    }
    // 0x80800DC8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80800DCC: b           L_80801910
    // 0x80800DD0: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
        goto L_80801910;
    // 0x80800DD0: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
L_80800DD4:
    // 0x80800DD4: beq         $v0, $zero, L_80801330
    if (ctx->r2 == 0) {
        // 0x80800DD8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80801330;
    }
    // 0x80800DD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800DDC: beq         $v0, $s7, L_80801150
    if (ctx->r2 == ctx->r23) {
        // 0x80800DE0: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_80801150;
    }
    // 0x80800DE0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80800DE4: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80800DE8: beq         $v0, $at, L_80800E28
    if (ctx->r2 == ctx->r1) {
        // 0x80800DEC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800E28;
    }
    // 0x80800DEC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800DF0: addiu       $at, $zero, 0x2A1
    ctx->r1 = ADD32(0, 0X2A1);
    // 0x80800DF4: beq         $v0, $at, L_80800FFC
    if (ctx->r2 == ctx->r1) {
        // 0x80800DF8: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_80800FFC;
    }
    // 0x80800DF8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80800DFC: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x80800E00: beq         $v0, $at, L_80801470
    if (ctx->r2 == ctx->r1) {
        // 0x80800E04: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_80801470;
    }
    // 0x80800E04: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80800E08: addiu       $at, $zero, 0x1FFF
    ctx->r1 = ADD32(0, 0X1FFF);
    // 0x80800E0C: beq         $v0, $at, L_80801394
    if (ctx->r2 == ctx->r1) {
        // 0x80800E10: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_80801394;
    }
    // 0x80800E10: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80800E14: addiu       $at, $zero, 0x3000
    ctx->r1 = ADD32(0, 0X3000);
    // 0x80800E18: beq         $v0, $at, L_80800E50
    if (ctx->r2 == ctx->r1) {
        // 0x80800E1C: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_80800E50;
    }
    // 0x80800E1C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80800E20: b           L_80801910
    // 0x80800E24: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
        goto L_80801910;
    // 0x80800E24: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
L_80800E28:
    // 0x80800E28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800E2C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800E30: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80800E34: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800E38: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800E3C: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x80800E40: jal         0x800EFA4C
    // 0x80800E44: mov.s       $f28, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    ctx->f28.fl = ctx->f24.fl;
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80800E44: mov.s       $f28, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    ctx->f28.fl = ctx->f24.fl;
    after_4:
    // 0x80800E48: b           L_80801910
    // 0x80800E4C: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
        goto L_80801910;
    // 0x80800E4C: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
L_80800E50:
    // 0x80800E50: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x80800E54: subu        $t6, $t6, $s4
    ctx->r14 = SUB32(ctx->r14, ctx->r20);
    // 0x80800E58: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(772, 0X3AE0) << 16);
    // 0x80800E5C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800E60: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800E64: addiu       $t7, $t7, 0x3AE0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(772, 0X3AE0));
    // 0x80800E68: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800E6C: jal         0x800D90A4
    // 0x80800E70: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    func_800D90A4(rdram, ctx);
        goto after_5;
    // 0x80800E70: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    after_5:
    // 0x80800E74: beq         $v0, $zero, L_80800E88
    if (ctx->r2 == 0) {
        // 0x80800E78: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80800E88;
    }
    // 0x80800E78: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800E7C: addiu       $a1, $zero, 0x844
    ctx->r5 = ADD32(0, 0X844);
    // 0x80800E80: jal         0x808007E4
    // 0x80800E84: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_6;
    // 0x80800E84: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_6:
L_80800E88:
    // 0x80800E88: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800E8C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800E90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800E94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800E98: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800E9C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800EA0: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800EA4: jal         0x800F12D4
    // 0x80800EA8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_7;
    // 0x80800EA8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x80800EAC: lb          $t8, 0x1($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1);
    // 0x80800EB0: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(772, 0X3BD0) << 16);
    // 0x80800EB4: addiu       $t0, $t0, 0x3BD0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(772, 0X3BD0));
    // 0x80800EB8: multu       $t8, $s7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800EBC: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x80800EC0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800EC4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800EC8: mflo        $t9
    ctx->r25 = lo;
    // 0x80800ECC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x80800ED0: jal         0x800EFB24
    // 0x80800ED4: nop

    func_800EFB24(rdram, ctx);
        goto after_8;
    // 0x80800ED4: nop

    after_8:
    // 0x80800ED8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800EDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800EE0: nop

    // 0x80800EE4: mul.s       $f12, $f28, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f28.fl, ctx->f6.fl);
    // 0x80800EE8: jal         0x80013970
    // 0x80800EEC: nop

    func_80013970(rdram, ctx);
        goto after_9;
    // 0x80800EEC: nop

    after_9:
    // 0x80800EF0: lbu         $t1, 0x2($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2);
    // 0x80800EF4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800EF8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800EFC: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80800F00: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800F04: bgez        $t1, L_80800F18
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800F08: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80800F18;
    }
    // 0x80800F08: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800F0C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800F10: nop

    // 0x80800F14: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80800F18:
    // 0x80800F18: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80800F1C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800F20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800F24: lwc1        $f8, 0xE8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80800F28: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800F2C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80800F30: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800F34: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800F38: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80800F3C: swc1        $f16, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f16.u32l;
    // 0x80800F40: lb          $t2, 0x0($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X0);
    // 0x80800F44: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80800F48: nop

    // 0x80800F4C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800F50: mul.s       $f22, $f4, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80800F54: b           L_80801910
    // 0x80800F58: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
        goto L_80801910;
    // 0x80800F58: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
L_80800F5C:
    // 0x80800F5C: lb          $t6, 0x1($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1);
    // 0x80800F60: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800F64: lw          $t5, 0x20($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X20);
    // 0x80800F68: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800F6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800F70: subu        $t3, $t3, $s4
    ctx->r11 = SUB32(ctx->r11, ctx->r20);
    // 0x80800F74: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(772, 0X3AE0) << 16);
    // 0x80800F78: addiu       $t4, $t4, 0x3AE0
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(772, 0X3AE0));
    // 0x80800F7C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80800F80: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800F84: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800F88: bne         $t5, $t7, L_80800FB0
    if (ctx->r13 != ctx->r15) {
        // 0x80800F8C: addu        $s1, $t3, $t4
        ctx->r17 = ADD32(ctx->r11, ctx->r12);
            goto L_80800FB0;
    }
    // 0x80800F8C: addu        $s1, $t3, $t4
    ctx->r17 = ADD32(ctx->r11, ctx->r12);
    // 0x80800F90: jal         0x8080363C
    // 0x80800F94: lw          $a0, 0x3C($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X3C);
    func_8080363C_chjiggygamenew(rdram, ctx);
        goto after_10;
    // 0x80800F94: lw          $a0, 0x3C($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X3C);
    after_10:
    // 0x80800F98: beq         $v0, $zero, L_80800FB0
    if (ctx->r2 == 0) {
        // 0x80800F9C: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80800FB0;
    }
    // 0x80800F9C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800FA0: swc1        $f24, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f24.u32l;
    // 0x80800FA4: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    // 0x80800FA8: jal         0x808007E4
    // 0x80800FAC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_11;
    // 0x80800FAC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_11:
L_80800FB0:
    // 0x80800FB0: lb          $t8, 0x1($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1);
    // 0x80800FB4: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(772, 0X3BD0) << 16);
    // 0x80800FB8: addiu       $t0, $t0, 0x3BD0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(772, 0X3BD0));
    // 0x80800FBC: multu       $t8, $s7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800FC0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800FC4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800FC8: mflo        $t9
    ctx->r25 = lo;
    // 0x80800FCC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x80800FD0: jal         0x800EFB24
    // 0x80800FD4: nop

    func_800EFB24(rdram, ctx);
        goto after_12;
    // 0x80800FD4: nop

    after_12:
    // 0x80800FD8: lb          $t1, 0x0($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X0);
    // 0x80800FDC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800FE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800FE4: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80800FE8: nop

    // 0x80800FEC: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800FF0: mul.s       $f22, $f18, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80800FF4: b           L_80801910
    // 0x80800FF8: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
        goto L_80801910;
    // 0x80800FF8: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
L_80800FFC:
    // 0x80800FFC: sll         $t2, $s4, 2
    ctx->r10 = S32(ctx->r20 << 2);
    // 0x80801000: subu        $t2, $t2, $s4
    ctx->r10 = SUB32(ctx->r10, ctx->r20);
    // 0x80801004: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(772, 0X3AE0) << 16);
    // 0x80801008: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8080100C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80801010: addiu       $t3, $t3, 0x3AE0
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(772, 0X3AE0));
    // 0x80801014: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80801018: lwc1        $f20, 0x8($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080101C: addu        $s1, $t2, $t3
    ctx->r17 = ADD32(ctx->r10, ctx->r11);
    // 0x80801020: jal         0x800D90A4
    // 0x80801024: addiu       $s2, $s0, 0xC
    ctx->r18 = ADD32(ctx->r16, 0XC);
    func_800D90A4(rdram, ctx);
        goto after_13;
    // 0x80801024: addiu       $s2, $s0, 0xC
    ctx->r18 = ADD32(ctx->r16, 0XC);
    after_13:
    // 0x80801028: beq         $v0, $zero, L_80801050
    if (ctx->r2 == 0) {
        // 0x8080102C: lui         $at, 0x3F40
        ctx->r1 = S32(0X3F40 << 16);
            goto L_80801050;
    }
    // 0x8080102C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801030: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80801034: addiu       $a1, $zero, 0x934
    ctx->r5 = ADD32(0, 0X934);
    // 0x80801038: jal         0x808007E4
    // 0x8080103C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_14;
    // 0x8080103C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_14:
    // 0x80801040: jal         0x80800B88
    // 0x80801044: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80800B88_chjiggygamenew(rdram, ctx);
        goto after_15;
    // 0x80801044: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_15:
    // 0x80801048: b           L_8080108C
    // 0x8080104C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
        goto L_8080108C;
    // 0x8080104C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_80801050:
    // 0x80801050: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801054: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801058: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x8080105C: nop

    // 0x80801060: bc1fl       L_8080108C
    if (!c1cs) {
        // 0x80801064: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_8080108C;
    }
    goto skip_0;
    // 0x80801064: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    skip_0:
    // 0x80801068: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080106C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801070: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x80801074: nop

    // 0x80801078: bc1fl       L_8080108C
    if (!c1cs) {
        // 0x8080107C: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_8080108C;
    }
    goto skip_1;
    // 0x8080107C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    skip_1:
    // 0x80801080: jal         0x80800B88
    // 0x80801084: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80800B88_chjiggygamenew(rdram, ctx);
        goto after_16;
    // 0x80801084: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_16:
    // 0x80801088: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_8080108C:
    // 0x8080108C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801090: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801094: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80801098: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8080109C: jal         0x800F12D4
    // 0x808010A0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800F12D4(rdram, ctx);
        goto after_17;
    // 0x808010A0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_17:
    // 0x808010A4: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x808010A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808010AC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808010B0: jal         0x800EFB24
    // 0x808010B4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_18;
    // 0x808010B4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_18:
    // 0x808010B8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808010BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808010C0: nop

    // 0x808010C4: mul.s       $f20, $f28, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f28.fl, ctx->f8.fl);
    // 0x808010C8: jal         0x80013970
    // 0x808010CC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80013970(rdram, ctx);
        goto after_19;
    // 0x808010CC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_19:
    // 0x808010D0: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x808010D4: jal         0x80013970
    // 0x808010D8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80013970(rdram, ctx);
        goto after_20;
    // 0x808010D8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_20:
    // 0x808010DC: lbu         $t4, 0x2($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X2);
    // 0x808010E0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808010E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808010E8: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x808010EC: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x808010F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808010F4: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x808010F8: bgez        $t4, L_8080110C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x808010FC: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080110C;
    }
    // 0x808010FC: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801100: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801104: nop

    // 0x80801108: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_8080110C:
    // 0x8080110C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801110: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80801114: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801118: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x8080111C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80801120: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80801124: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80801128: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080112C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80801130: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
    // 0x80801134: lb          $t6, 0x0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X0);
    // 0x80801138: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8080113C: nop

    // 0x80801140: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80801144: mul.s       $f22, $f4, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80801148: b           L_80801910
    // 0x8080114C: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
        goto L_80801910;
    // 0x8080114C: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
L_80801150:
    // 0x80801150: sll         $t5, $s4, 2
    ctx->r13 = S32(ctx->r20 << 2);
    // 0x80801154: subu        $t5, $t5, $s4
    ctx->r13 = SUB32(ctx->r13, ctx->r20);
    // 0x80801158: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(772, 0X3AE0) << 16);
    // 0x8080115C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801160: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80801164: addiu       $t7, $t7, 0x3AE0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(772, 0X3AE0));
    // 0x80801168: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8080116C: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x80801170: jal         0x800D91EC
    // 0x80801174: addu        $s1, $t5, $t7
    ctx->r17 = ADD32(ctx->r13, ctx->r15);
    func_800D91EC(rdram, ctx);
        goto after_21;
    // 0x80801174: addu        $s1, $t5, $t7
    ctx->r17 = ADD32(ctx->r13, ctx->r15);
    after_21:
    // 0x80801178: beql        $v0, $zero, L_808011A8
    if (ctx->r2 == 0) {
        // 0x8080117C: lb          $t1, 0x1($s0)
        ctx->r9 = MEM_B(ctx->r16, 0X1);
            goto L_808011A8;
    }
    goto skip_2;
    // 0x8080117C: lb          $t1, 0x1($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1);
    skip_2:
    // 0x80801180: lb          $t9, 0x1($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1);
    // 0x80801184: swc1        $f24, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f24.u32l;
    // 0x80801188: lw          $t8, 0x20($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X20);
    // 0x8080118C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80801190: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80801194: beq         $t8, $t0, L_808011A4
    if (ctx->r24 == ctx->r8) {
        // 0x80801198: addiu       $a1, $zero, 0x844
        ctx->r5 = ADD32(0, 0X844);
            goto L_808011A4;
    }
    // 0x80801198: addiu       $a1, $zero, 0x844
    ctx->r5 = ADD32(0, 0X844);
    // 0x8080119C: jal         0x808007E4
    // 0x808011A0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_22;
    // 0x808011A0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_22:
L_808011A4:
    // 0x808011A4: lb          $t1, 0x1($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1);
L_808011A8:
    // 0x808011A8: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(772, 0X3BD0) << 16);
    // 0x808011AC: addiu       $t3, $t3, 0x3BD0
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(772, 0X3BD0));
    // 0x808011B0: multu       $t1, $s7
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808011B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808011B8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808011BC: mflo        $t2
    ctx->r10 = lo;
    // 0x808011C0: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    // 0x808011C4: jal         0x800EFB24
    // 0x808011C8: nop

    func_800EFB24(rdram, ctx);
        goto after_23;
    // 0x808011C8: nop

    after_23:
    // 0x808011CC: lb          $t4, 0x0($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X0);
    // 0x808011D0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808011D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808011D8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x808011DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808011E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808011E4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808011E8: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808011EC: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x808011F0: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x808011F4: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x808011F8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x808011FC: mul.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80801200: jal         0x800F10B4
    // 0x80801204: nop

    func_800F10B4(rdram, ctx);
        goto after_24;
    // 0x80801204: nop

    after_24:
    // 0x80801208: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8080120C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801210: nop

    // 0x80801214: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801218: jal         0x80013970
    // 0x8080121C: nop

    func_80013970(rdram, ctx);
        goto after_25;
    // 0x8080121C: nop

    after_25:
    // 0x80801220: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X39BC) << 16);
    // 0x80801224: lwc1        $f18, 0x39BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X39BC));
    // 0x80801228: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8080122C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801230: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80801234: b           L_8080190C
    // 0x80801238: add.s       $f26, $f6, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f8.fl;
        goto L_8080190C;
    // 0x80801238: add.s       $f26, $f6, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f8.fl;
L_8080123C:
    // 0x8080123C: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x80801240: subu        $t6, $t6, $s4
    ctx->r14 = SUB32(ctx->r14, ctx->r20);
    // 0x80801244: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(772, 0X3AE0) << 16);
    // 0x80801248: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080124C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80801250: addiu       $t5, $t5, 0x3AE0
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(772, 0X3AE0));
    // 0x80801254: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801258: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x8080125C: jal         0x800D91EC
    // 0x80801260: addu        $s1, $t6, $t5
    ctx->r17 = ADD32(ctx->r14, ctx->r13);
    func_800D91EC(rdram, ctx);
        goto after_26;
    // 0x80801260: addu        $s1, $t6, $t5
    ctx->r17 = ADD32(ctx->r14, ctx->r13);
    after_26:
    // 0x80801264: beq         $v0, $zero, L_80801278
    if (ctx->r2 == 0) {
        // 0x80801268: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80801278;
    }
    // 0x80801268: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080126C: addiu       $a1, $zero, 0x470
    ctx->r5 = ADD32(0, 0X470);
    // 0x80801270: jal         0x808007E4
    // 0x80801274: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_27;
    // 0x80801274: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_27:
L_80801278:
    // 0x80801278: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080127C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801280: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801284: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x80801288: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8080128C: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x80801290: jal         0x800F10B4
    // 0x80801294: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_28;
    // 0x80801294: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_28:
    // 0x80801298: lb          $t7, 0x1($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1);
    // 0x8080129C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(772, 0X3BD0) << 16);
    // 0x808012A0: addiu       $t8, $t8, 0x3BD0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(772, 0X3BD0));
    // 0x808012A4: multu       $t7, $s7
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808012A8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808012AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808012B0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808012B4: mflo        $t9
    ctx->r25 = lo;
    // 0x808012B8: addu        $a1, $t9, $t8
    ctx->r5 = ADD32(ctx->r25, ctx->r24);
    // 0x808012BC: jal         0x800EFB24
    // 0x808012C0: nop

    func_800EFB24(rdram, ctx);
        goto after_29;
    // 0x808012C0: nop

    after_29:
    // 0x808012C4: lw          $a0, 0x3C($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X3C);
    // 0x808012C8: jal         0x808035C4
    // 0x808012CC: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    func_808035C4_chjiggygamenew(rdram, ctx);
        goto after_30;
    // 0x808012CC: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    after_30:
    // 0x808012D0: addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // 0x808012D4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808012D8: jal         0x800EFB24
    // 0x808012DC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_31;
    // 0x808012DC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_31:
    // 0x808012E0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808012E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808012E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808012EC: jal         0x800EFE50
    // 0x808012F0: addiu       $a2, $sp, 0xD0
    ctx->r6 = ADD32(ctx->r29, 0XD0);
    func_800EFE50(rdram, ctx);
        goto after_32;
    // 0x808012F0: addiu       $a2, $sp, 0xD0
    ctx->r6 = ADD32(ctx->r29, 0XD0);
    after_32:
    // 0x808012F4: lb          $t0, 0x0($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X0);
    // 0x808012F8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808012FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801300: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80801304: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801308: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080130C: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80801310: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x80801314: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801318: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8080131C: mul.s       $f22, $f4, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80801320: jal         0x800F1214
    // 0x80801324: nop

    func_800F1214(rdram, ctx);
        goto after_33;
    // 0x80801324: nop

    after_33:
    // 0x80801328: b           L_8080190C
    // 0x8080132C: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
        goto L_8080190C;
    // 0x8080132C: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
L_80801330:
    // 0x80801330: sll         $t1, $s4, 2
    ctx->r9 = S32(ctx->r20 << 2);
    // 0x80801334: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80801338: subu        $t1, $t1, $s4
    ctx->r9 = SUB32(ctx->r9, ctx->r20);
    // 0x8080133C: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(772, 0X3AE0) << 16);
    // 0x80801340: addiu       $t2, $t2, 0x3AE0
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(772, 0X3AE0));
    // 0x80801344: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80801348: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X39C0) << 16);
    // 0x8080134C: lwc1        $f26, 0x39C0($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X39C0));
    // 0x80801350: addu        $s1, $t1, $t2
    ctx->r17 = ADD32(ctx->r9, ctx->r10);
    // 0x80801354: lw          $a0, 0x3C($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X3C);
    // 0x80801358: jal         0x808035C4
    // 0x8080135C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_808035C4_chjiggygamenew(rdram, ctx);
        goto after_34;
    // 0x8080135C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_34:
    // 0x80801360: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801364: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80801368: jal         0x800EFB24
    // 0x8080136C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_35;
    // 0x8080136C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_35:
    // 0x80801370: lb          $t3, 0x0($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X0);
    // 0x80801374: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80801378: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080137C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80801380: nop

    // 0x80801384: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80801388: mul.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080138C: b           L_80801910
    // 0x80801390: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
        goto L_80801910;
    // 0x80801390: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
L_80801394:
    // 0x80801394: sll         $t4, $s4, 2
    ctx->r12 = S32(ctx->r20 << 2);
    // 0x80801398: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080139C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808013A0: subu        $t4, $t4, $s4
    ctx->r12 = SUB32(ctx->r12, ctx->r20);
    // 0x808013A4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(772, 0X3AE0) << 16);
    // 0x808013A8: addiu       $t6, $t6, 0x3AE0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(772, 0X3AE0));
    // 0x808013AC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x808013B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X39C4) << 16);
    // 0x808013B4: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x808013B8: lwc1        $f26, 0x39C4($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X39C4));
    // 0x808013BC: jal         0x800D91EC
    // 0x808013C0: addu        $s1, $t4, $t6
    ctx->r17 = ADD32(ctx->r12, ctx->r14);
    func_800D91EC(rdram, ctx);
        goto after_36;
    // 0x808013C0: addu        $s1, $t4, $t6
    ctx->r17 = ADD32(ctx->r12, ctx->r14);
    after_36:
    // 0x808013C4: beq         $v0, $zero, L_80801408
    if (ctx->r2 == 0) {
        // 0x808013C8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80801408;
    }
    // 0x808013C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808013CC: swc1        $f24, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f24.u32l;
    // 0x808013D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808013D4: addiu       $a1, $zero, 0x470
    ctx->r5 = ADD32(0, 0X470);
    // 0x808013D8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x808013DC: jal         0x808007E4
    // 0x808013E0: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_37;
    // 0x808013E0: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    after_37:
    // 0x808013E4: lb          $t5, 0x0($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X0);
    // 0x808013E8: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x808013EC: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x808013F0: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x808013F4: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x808013F8: bne         $at, $zero, L_80801428
    if (ctx->r1 != 0) {
        // 0x808013FC: addiu       $t9, $v0, -0x4
        ctx->r25 = ADD32(ctx->r2, -0X4);
            goto L_80801428;
    }
    // 0x808013FC: addiu       $t9, $v0, -0x4
    ctx->r25 = ADD32(ctx->r2, -0X4);
    // 0x80801400: b           L_80801428
    // 0x80801404: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
        goto L_80801428;
    // 0x80801404: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
L_80801408:
    // 0x80801408: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080140C: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801410: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x80801414: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80801418: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x8080141C: jal         0x800F10B4
    // 0x80801420: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_38;
    // 0x80801420: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_38:
    // 0x80801424: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80801428:
    // 0x80801428: lw          $a0, 0x3C($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X3C);
    // 0x8080142C: jal         0x808035C4
    // 0x80801430: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_808035C4_chjiggygamenew(rdram, ctx);
        goto after_39;
    // 0x80801430: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_39:
    // 0x80801434: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801438: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8080143C: jal         0x800EFB24
    // 0x80801440: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_40;
    // 0x80801440: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_40:
    // 0x80801444: lb          $t8, 0x0($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X0);
    // 0x80801448: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080144C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801450: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80801454: nop

    // 0x80801458: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080145C: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80801460: nop

    // 0x80801464: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80801468: b           L_8080190C
    // 0x8080146C: sub.s       $f22, $f6, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f8.fl;
        goto L_8080190C;
    // 0x8080146C: sub.s       $f22, $f6, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f8.fl;
L_80801470:
    // 0x80801470: sll         $t0, $s4, 2
    ctx->r8 = S32(ctx->r20 << 2);
    // 0x80801474: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801478: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8080147C: subu        $t0, $t0, $s4
    ctx->r8 = SUB32(ctx->r8, ctx->r20);
    // 0x80801480: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(772, 0X3AE0) << 16);
    // 0x80801484: addiu       $t1, $t1, 0x3AE0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(772, 0X3AE0));
    // 0x80801488: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8080148C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X39C8) << 16);
    // 0x80801490: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x80801494: lwc1        $f26, 0x39C8($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X39C8));
    // 0x80801498: jal         0x800D91EC
    // 0x8080149C: addu        $s1, $t0, $t1
    ctx->r17 = ADD32(ctx->r8, ctx->r9);
    func_800D91EC(rdram, ctx);
        goto after_41;
    // 0x8080149C: addu        $s1, $t0, $t1
    ctx->r17 = ADD32(ctx->r8, ctx->r9);
    after_41:
    // 0x808014A0: beq         $v0, $zero, L_808014E0
    if (ctx->r2 == 0) {
        // 0x808014A4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808014E0;
    }
    // 0x808014A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808014A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808014AC: addiu       $a1, $zero, 0x470
    ctx->r5 = ADD32(0, 0X470);
    // 0x808014B0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x808014B4: jal         0x808007E4
    // 0x808014B8: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_42;
    // 0x808014B8: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    after_42:
    // 0x808014BC: lb          $t2, 0x0($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X0);
    // 0x808014C0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x808014C4: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    // 0x808014C8: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x808014CC: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x808014D0: bne         $at, $zero, L_80801500
    if (ctx->r1 != 0) {
        // 0x808014D4: addiu       $t4, $v0, -0x4
        ctx->r12 = ADD32(ctx->r2, -0X4);
            goto L_80801500;
    }
    // 0x808014D4: addiu       $t4, $v0, -0x4
    ctx->r12 = ADD32(ctx->r2, -0X4);
    // 0x808014D8: b           L_80801500
    // 0x808014DC: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
        goto L_80801500;
    // 0x808014DC: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
L_808014E0:
    // 0x808014E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808014E4: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808014E8: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x808014EC: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x808014F0: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x808014F4: jal         0x800F10B4
    // 0x808014F8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_43;
    // 0x808014F8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_43:
    // 0x808014FC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80801500:
    // 0x80801500: lw          $a0, 0x3C($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X3C);
    // 0x80801504: jal         0x808035C4
    // 0x80801508: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_808035C4_chjiggygamenew(rdram, ctx);
        goto after_44;
    // 0x80801508: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_44:
    // 0x8080150C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801510: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80801514: jal         0x800EFB24
    // 0x80801518: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_45;
    // 0x80801518: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_45:
    // 0x8080151C: lb          $t6, 0x0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X0);
    // 0x80801520: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80801524: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801528: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8080152C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801530: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80801534: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80801538: nop

    // 0x8080153C: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80801540: b           L_8080190C
    // 0x80801544: add.s       $f22, $f6, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f10.fl;
        goto L_8080190C;
    // 0x80801544: add.s       $f22, $f6, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f10.fl;
L_80801548:
    // 0x80801548: sll         $t5, $s4, 2
    ctx->r13 = S32(ctx->r20 << 2);
    // 0x8080154C: subu        $t5, $t5, $s4
    ctx->r13 = SUB32(ctx->r13, ctx->r20);
    // 0x80801550: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(772, 0X3AE0) << 16);
    // 0x80801554: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801558: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8080155C: addiu       $t7, $t7, 0x3AE0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(772, 0X3AE0));
    // 0x80801560: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80801564: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x80801568: addu        $s1, $t5, $t7
    ctx->r17 = ADD32(ctx->r13, ctx->r15);
    // 0x8080156C: jal         0x800D91EC
    // 0x80801570: addiu       $s2, $s0, 0xC
    ctx->r18 = ADD32(ctx->r16, 0XC);
    func_800D91EC(rdram, ctx);
        goto after_46;
    // 0x80801570: addiu       $s2, $s0, 0xC
    ctx->r18 = ADD32(ctx->r16, 0XC);
    after_46:
    // 0x80801574: beq         $v0, $zero, L_80801588
    if (ctx->r2 == 0) {
        // 0x80801578: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80801588;
    }
    // 0x80801578: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080157C: addiu       $a1, $zero, 0x844
    ctx->r5 = ADD32(0, 0X844);
    // 0x80801580: jal         0x808007E4
    // 0x80801584: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_47;
    // 0x80801584: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_47:
L_80801588:
    // 0x80801588: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080158C: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x80801590: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x80801594: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x80801598: jal         0x800F10B4
    // 0x8080159C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800F10B4(rdram, ctx);
        goto after_48;
    // 0x8080159C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_48:
    // 0x808015A0: lb          $t9, 0x1($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1);
    // 0x808015A4: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(772, 0X3BD0) << 16);
    // 0x808015A8: addiu       $t0, $t0, 0x3BD0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(772, 0X3BD0));
    // 0x808015AC: multu       $t9, $s7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808015B0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808015B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808015B8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808015BC: mflo        $t8
    ctx->r24 = lo;
    // 0x808015C0: addu        $a1, $t8, $t0
    ctx->r5 = ADD32(ctx->r24, ctx->r8);
    // 0x808015C4: jal         0x800EFB24
    // 0x808015C8: nop

    func_800EFB24(rdram, ctx);
        goto after_49;
    // 0x808015C8: nop

    after_49:
    // 0x808015CC: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x808015D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808015D4: jal         0x800EFB24
    // 0x808015D8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_50;
    // 0x808015D8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_50:
    // 0x808015DC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808015E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808015E4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808015E8: jal         0x800EFE50
    // 0x808015EC: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    func_800EFE50(rdram, ctx);
        goto after_51;
    // 0x808015EC: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    after_51:
    // 0x808015F0: lb          $t1, 0x0($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X0);
    // 0x808015F4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808015F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808015FC: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80801600: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801604: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801608: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8080160C: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x80801610: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801614: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80801618: mul.s       $f22, $f4, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8080161C: jal         0x800F1214
    // 0x80801620: nop

    func_800F1214(rdram, ctx);
        goto after_52;
    // 0x80801620: nop

    after_52:
    // 0x80801624: b           L_8080190C
    // 0x80801628: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
        goto L_8080190C;
    // 0x80801628: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
L_8080162C:
    // 0x8080162C: sll         $t2, $s4, 2
    ctx->r10 = S32(ctx->r20 << 2);
    // 0x80801630: subu        $t2, $t2, $s4
    ctx->r10 = SUB32(ctx->r10, ctx->r20);
    // 0x80801634: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(772, 0X3AE0) << 16);
    // 0x80801638: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080163C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80801640: addiu       $t3, $t3, 0x3AE0
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(772, 0X3AE0));
    // 0x80801644: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80801648: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x8080164C: addu        $s1, $t2, $t3
    ctx->r17 = ADD32(ctx->r10, ctx->r11);
    // 0x80801650: jal         0x800D91EC
    // 0x80801654: addiu       $s2, $s0, 0xC
    ctx->r18 = ADD32(ctx->r16, 0XC);
    func_800D91EC(rdram, ctx);
        goto after_53;
    // 0x80801654: addiu       $s2, $s0, 0xC
    ctx->r18 = ADD32(ctx->r16, 0XC);
    after_53:
    // 0x80801658: beq         $v0, $zero, L_8080166C
    if (ctx->r2 == 0) {
        // 0x8080165C: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8080166C;
    }
    // 0x8080165C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80801660: addiu       $a1, $zero, 0x19C
    ctx->r5 = ADD32(0, 0X19C);
    // 0x80801664: jal         0x808007E4
    // 0x80801668: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_54;
    // 0x80801668: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_54:
L_8080166C:
    // 0x8080166C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801670: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801674: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801678: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x8080167C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80801680: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x80801684: jal         0x800F10B4
    // 0x80801688: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_55;
    // 0x80801688: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_55:
    // 0x8080168C: lbu         $t4, 0x3($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X3);
    // 0x80801690: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(772, 0X3AE0) << 16);
    // 0x80801694: addiu       $t5, $t5, 0x3AE0
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(772, 0X3AE0));
    // 0x80801698: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8080169C: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x808016A0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808016A4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808016A8: addu        $a1, $t6, $t5
    ctx->r5 = ADD32(ctx->r14, ctx->r13);
    // 0x808016AC: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x808016B0: jal         0x800EFB24
    // 0x808016B4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_56;
    // 0x808016B4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_56:
    // 0x808016B8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808016BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808016C0: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x808016C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808016C8: mul.s       $f16, $f20, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x808016CC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808016D0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808016D4: sub.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x808016D8: jal         0x800EFB24
    // 0x808016DC: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    func_800EFB24(rdram, ctx);
        goto after_57;
    // 0x808016DC: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    after_57:
    // 0x808016E0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808016E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808016E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808016EC: jal         0x800EFE50
    // 0x808016F0: addiu       $a2, $sp, 0xA8
    ctx->r6 = ADD32(ctx->r29, 0XA8);
    func_800EFE50(rdram, ctx);
        goto after_58;
    // 0x808016F0: addiu       $a2, $sp, 0xA8
    ctx->r6 = ADD32(ctx->r29, 0XA8);
    after_58:
    // 0x808016F4: lb          $t7, 0x0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X0);
    // 0x808016F8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808016FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801700: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80801704: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X39CC) << 16);
    // 0x80801708: lwc1        $f14, 0x39CC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X39CC));
    // 0x8080170C: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80801710: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80801714: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801718: mul.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080171C: jal         0x800F1214
    // 0x80801720: nop

    func_800F1214(rdram, ctx);
        goto after_59;
    // 0x80801720: nop

    after_59:
    // 0x80801724: b           L_8080190C
    // 0x80801728: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
        goto L_8080190C;
    // 0x80801728: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
L_8080172C:
    // 0x8080172C: multu       $s4, $s7
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80801730: lbu         $t9, 0x3($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X3);
    // 0x80801734: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801738: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(772, 0X3AE0) << 16);
    // 0x8080173C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80801740: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x80801744: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80801748: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080174C: addiu       $t0, $t0, 0x3AE0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(772, 0X3AE0));
    // 0x80801750: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80801754: mflo        $t1
    ctx->r9 = lo;
    // 0x80801758: addu        $a2, $t1, $t0
    ctx->r6 = ADD32(ctx->r9, ctx->r8);
    // 0x8080175C: jal         0x800EFB24
    // 0x80801760: addu        $a1, $t8, $t0
    ctx->r5 = ADD32(ctx->r24, ctx->r8);
    func_800EFB24(rdram, ctx);
        goto after_60;
    // 0x80801760: addu        $a1, $t8, $t0
    ctx->r5 = ADD32(ctx->r24, ctx->r8);
    after_60:
    // 0x80801764: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80801768: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080176C: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80801770: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80801774: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801778: sub.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8080177C: swc1        $f4, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f4.u32l;
    // 0x80801780: lb          $t2, 0x0($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X0);
    // 0x80801784: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80801788: nop

    // 0x8080178C: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80801790: mul.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80801794: b           L_80801910
    // 0x80801798: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
        goto L_80801910;
    // 0x80801798: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
L_8080179C:
    // 0x8080179C: sll         $t3, $s4, 2
    ctx->r11 = S32(ctx->r20 << 2);
    // 0x808017A0: subu        $t3, $t3, $s4
    ctx->r11 = SUB32(ctx->r11, ctx->r20);
    // 0x808017A4: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(772, 0X3AE0) << 16);
    // 0x808017A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808017AC: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808017B0: addiu       $t4, $t4, 0x3AE0
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(772, 0X3AE0));
    // 0x808017B4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x808017B8: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x808017BC: jal         0x800D91EC
    // 0x808017C0: addu        $s1, $t3, $t4
    ctx->r17 = ADD32(ctx->r11, ctx->r12);
    func_800D91EC(rdram, ctx);
        goto after_61;
    // 0x808017C0: addu        $s1, $t3, $t4
    ctx->r17 = ADD32(ctx->r11, ctx->r12);
    after_61:
    // 0x808017C4: beq         $v0, $zero, L_808017D8
    if (ctx->r2 == 0) {
        // 0x808017C8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_808017D8;
    }
    // 0x808017C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808017CC: addiu       $a1, $zero, 0x470
    ctx->r5 = ADD32(0, 0X470);
    // 0x808017D0: jal         0x808007E4
    // 0x808017D4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_62;
    // 0x808017D4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_62:
L_808017D8:
    // 0x808017D8: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808017DC: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x808017E0: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x808017E4: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x808017E8: jal         0x800F10B4
    // 0x808017EC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800F10B4(rdram, ctx);
        goto after_63;
    // 0x808017EC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_63:
    // 0x808017F0: lbu         $t6, 0x3($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X3);
    // 0x808017F4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(772, 0X3AE0) << 16);
    // 0x808017F8: addiu       $t7, $t7, 0x3AE0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(772, 0X3AE0));
    // 0x808017FC: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x80801800: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x80801804: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80801808: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8080180C: addu        $a1, $t5, $t7
    ctx->r5 = ADD32(ctx->r13, ctx->r15);
    // 0x80801810: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x80801814: jal         0x800EFB24
    // 0x80801818: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_64;
    // 0x80801818: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_64:
    // 0x8080181C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80801820: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801824: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80801828: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8080182C: mul.s       $f4, $f20, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x80801830: sub.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80801834: swc1        $f18, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f18.u32l;
    // 0x80801838: jal         0x808035C4
    // 0x8080183C: lw          $a0, 0x3C($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X3C);
    func_808035C4_chjiggygamenew(rdram, ctx);
        goto after_65;
    // 0x8080183C: lw          $a0, 0x3C($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X3C);
    after_65:
    // 0x80801840: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801844: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80801848: jal         0x800EFB24
    // 0x8080184C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_66;
    // 0x8080184C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_66:
    // 0x80801850: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80801854: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801858: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8080185C: jal         0x800EFE50
    // 0x80801860: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    func_800EFE50(rdram, ctx);
        goto after_67;
    // 0x80801860: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    after_67:
    // 0x80801864: lb          $t9, 0x0($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X0);
    // 0x80801868: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080186C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801870: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80801874: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X39D0) << 16);
    // 0x80801878: lwc1        $f14, 0x39D0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X39D0));
    // 0x8080187C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80801880: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80801884: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801888: mul.s       $f22, $f10, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8080188C: jal         0x800F1214
    // 0x80801890: nop

    func_800F1214(rdram, ctx);
        goto after_68;
    // 0x80801890: nop

    after_68:
    // 0x80801894: b           L_8080190C
    // 0x80801898: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
        goto L_8080190C;
    // 0x80801898: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
L_8080189C:
    // 0x8080189C: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x808018A0: subu        $t8, $t8, $s4
    ctx->r24 = SUB32(ctx->r24, ctx->r20);
    // 0x808018A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808018A8: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(772, 0X3AE0) << 16);
    // 0x808018AC: addiu       $t1, $t1, 0x3AE0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(772, 0X3AE0));
    // 0x808018B0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808018B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808018B8: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x808018BC: addu        $s1, $t8, $t1
    ctx->r17 = ADD32(ctx->r24, ctx->r9);
    // 0x808018C0: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x808018C4: jal         0x800D91EC
    // 0x808018C8: addiu       $s2, $s0, 0xC
    ctx->r18 = ADD32(ctx->r16, 0XC);
    func_800D91EC(rdram, ctx);
        goto after_69;
    // 0x808018C8: addiu       $s2, $s0, 0xC
    ctx->r18 = ADD32(ctx->r16, 0XC);
    after_69:
    // 0x808018CC: beq         $v0, $zero, L_808018E0
    if (ctx->r2 == 0) {
        // 0x808018D0: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_808018E0;
    }
    // 0x808018D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808018D4: addiu       $a1, $zero, 0x934
    ctx->r5 = ADD32(0, 0X934);
    // 0x808018D8: jal         0x808007E4
    // 0x808018DC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_70;
    // 0x808018DC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_70:
L_808018E0:
    // 0x808018E0: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808018E4: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x808018E8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x808018EC: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x808018F0: jal         0x800F10B4
    // 0x808018F4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800F10B4(rdram, ctx);
        goto after_71;
    // 0x808018F4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_71:
    // 0x808018F8: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x808018FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801900: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80801904: jal         0x800EFB24
    // 0x80801908: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_72;
    // 0x80801908: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_72:
L_8080190C:
    // 0x8080190C: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
L_80801910:
    // 0x80801910: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80801914: jal         0x800EF334
    // 0x80801918: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EF334(rdram, ctx);
        goto after_73;
    // 0x80801918: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_73:
    // 0x8080191C: lwc1        $f6, 0xEC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80801920: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80801924: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x80801928: lw          $a0, 0xFC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XFC);
    // 0x8080192C: lbu         $a1, 0x3($fp)
    ctx->r5 = MEM_BU(ctx->r30, 0X3);
    // 0x80801930: lw          $a3, 0xE8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XE8);
    // 0x80801934: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80801938: jal         0x800E0C20
    // 0x8080193C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800E0C20(rdram, ctx);
        goto after_74;
    // 0x8080193C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_74:
    // 0x80801940: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x80801944: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80801948: lw          $a0, 0xFC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XFC);
    // 0x8080194C: lbu         $a1, 0x3($fp)
    ctx->r5 = MEM_BU(ctx->r30, 0X3);
    // 0x80801950: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x80801954: jal         0x800E0AFC
    // 0x80801958: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_75;
    // 0x80801958: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    after_75:
    // 0x8080195C: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x80801960: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80801964: lw          $a0, 0xFC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XFC);
    // 0x80801968: lbu         $a1, 0x3($fp)
    ctx->r5 = MEM_BU(ctx->r30, 0X3);
    // 0x8080196C: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x80801970: jal         0x800E0B8C
    // 0x80801974: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_76;
    // 0x80801974: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    after_76:
    // 0x80801978: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8080197C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80801980: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80801984: bne         $s4, $at, L_80800D6C
    if (ctx->r20 != ctx->r1) {
        // 0x80801988: addiu       $fp, $fp, 0x4
        ctx->r30 = ADD32(ctx->r30, 0X4);
            goto L_80800D6C;
    }
    // 0x80801988: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x8080198C: swc1        $f28, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f28.u32l;
    // 0x80801990: swc1        $f26, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f26.u32l;
    // 0x80801994: swc1        $f22, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f22.u32l;
L_80801998:
    // 0x80801998: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8080199C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808019A0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x808019A4: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x808019A8: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x808019AC: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x808019B0: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x808019B4: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x808019B8: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x808019BC: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x808019C0: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x808019C4: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x808019C8: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x808019CC: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x808019D0: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x808019D4: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x808019D8: jr          $ra
    // 0x808019DC: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x808019DC: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void func_8080000C_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800010: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800018: addiu       $a2, $a3, 0x4
    ctx->r6 = ADD32(ctx->r7, 0X4);
    // 0x8080001C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80800020: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800024: jal         0x800882D8
    // 0x80800028: addiu       $a1, $zero, 0x28C
    ctx->r5 = ADD32(0, 0X28C);
    _gccubesearch_entrypoint_12(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a1, $zero, 0x28C
    ctx->r5 = ADD32(0, 0X28C);
    after_0:
    // 0x8080002C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800030: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800034: jal         0x800EE7F8
    // 0x80800038: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800038: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800040: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80800044: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800048: jr          $ra
    // 0x8080004C: nop

    return;
    // 0x8080004C: nop

;}
RECOMP_FUNC void func_808018B0_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808018B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018B8: jal         0x80082FF0
    // 0x808018BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808018BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808018C0: jal         0x80800104
    // 0x808018C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800104_bsbswim(rdram, ctx);
        goto after_1;
    // 0x808018C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808018C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808018D0: jr          $ra
    // 0x808018D4: nop

    return;
    // 0x808018D4: nop

;}
RECOMP_FUNC void _badeathmatch_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085540: syscall     165
    recomp_syscall_handler(rdram, ctx, 0x80085540);
    return;
    // 0x80085544: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_8008AA0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AA0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008AA10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008AA14: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x8008AA18: sll         $t8, $t6, 25
    ctx->r24 = S32(ctx->r14 << 25);
    // 0x8008AA1C: bgezl       $t8, L_8008AAB4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8008AA20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008AAB4;
    }
    goto skip_0;
    // 0x8008AA20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8008AA24: jal         0x8008AEDC
    // 0x8008AA28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8008AEDC(rdram, ctx);
        goto after_0;
    // 0x8008AA28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008AA2C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8008AA30: jal         0x8008C0D0
    // 0x8008AA34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008C0D0(rdram, ctx);
        goto after_1;
    // 0x8008AA34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008AA38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008AA3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008AA40: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8008AA44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008AA48: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8008AA4C: nop

    // 0x8008AA50: bc1fl       L_8008AAB4
    if (!c1cs) {
        // 0x8008AA54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008AAB4;
    }
    goto skip_1;
    // 0x8008AA54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8008AA58: jal         0x8008A990
    // 0x8008AA5C: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_8008A990(rdram, ctx);
        goto after_2;
    // 0x8008AA5C: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x8008AA60: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8008AA64: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8008AA68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008AA6C: lwc1        $f6, 0x10($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8008AA70: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008AA74: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AA78: div.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8008AA7C: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8008AA80: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x8008AA84: nop

    // 0x8008AA88: bc1fl       L_8008AAA8
    if (!c1cs) {
        // 0x8008AA8C: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_8008AAA8;
    }
    goto skip_2;
    // 0x8008AA8C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_2:
    // 0x8008AA90: jal         0x8008C1F0
    // 0x8008AA94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008C1F0(rdram, ctx);
        goto after_3;
    // 0x8008AA94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8008AA98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008AA9C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8008AAA0: nop

    // 0x8008AAA4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_8008AAA8:
    // 0x8008AAA8: jal         0x8008C1E4
    // 0x8008AAAC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8008C1E4(rdram, ctx);
        goto after_4;
    // 0x8008AAAC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x8008AAB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008AAB4:
    // 0x8008AAB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008AAB8: jr          $ra
    // 0x8008AABC: nop

    return;
    // 0x8008AABC: nop

;}
RECOMP_FUNC void func_80098218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098218: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8009821C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80098220: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80098224: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80098228: jal         0x80092B80
    // 0x8009822C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_80092B80(rdram, ctx);
        goto after_0;
    // 0x8009822C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80098230: addiu       $at, $zero, 0x607
    ctx->r1 = ADD32(0, 0X607);
    // 0x80098234: beq         $v0, $at, L_8009825C
    if (ctx->r2 == ctx->r1) {
        // 0x80098238: addiu       $at, $zero, 0x608
        ctx->r1 = ADD32(0, 0X608);
            goto L_8009825C;
    }
    // 0x80098238: addiu       $at, $zero, 0x608
    ctx->r1 = ADD32(0, 0X608);
    // 0x8009823C: beq         $v0, $at, L_8009825C
    if (ctx->r2 == ctx->r1) {
        // 0x80098240: addiu       $at, $zero, 0x61C
        ctx->r1 = ADD32(0, 0X61C);
            goto L_8009825C;
    }
    // 0x80098240: addiu       $at, $zero, 0x61C
    ctx->r1 = ADD32(0, 0X61C);
    // 0x80098244: beq         $v0, $at, L_800983F4
    if (ctx->r2 == ctx->r1) {
        // 0x80098248: addiu       $at, $zero, 0x623
        ctx->r1 = ADD32(0, 0X623);
            goto L_800983F4;
    }
    // 0x80098248: addiu       $at, $zero, 0x623
    ctx->r1 = ADD32(0, 0X623);
    // 0x8009824C: beql        $v0, $at, L_800983F8
    if (ctx->r2 == ctx->r1) {
        // 0x80098250: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800983F8;
    }
    goto skip_0;
    // 0x80098250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80098254: b           L_800983F8
    // 0x80098258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800983F8;
    // 0x80098258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009825C:
    // 0x8009825C: lw          $v0, 0xAC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XAC);
    // 0x80098260: lbu         $t6, 0x28($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X28);
    // 0x80098264: beql        $t6, $zero, L_800982EC
    if (ctx->r14 == 0) {
        // 0x80098268: lbu         $t1, 0x2A($v0)
        ctx->r9 = MEM_BU(ctx->r2, 0X2A);
            goto L_800982EC;
    }
    goto skip_1;
    // 0x80098268: lbu         $t1, 0x2A($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2A);
    skip_1:
    // 0x8009826C: jal         0x800EFD24
    // 0x80098270: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x80098270: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x80098274: lw          $t7, 0xAC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XAC);
    // 0x80098278: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8009827C: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80098280: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80098284: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80098288: jal         0x800DFFDC
    // 0x8009828C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    func_800DFFDC(rdram, ctx);
        goto after_2;
    // 0x8009828C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80098290: lw          $t8, 0xAC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XAC);
    // 0x80098294: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80098298: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x8009829C: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800982A0: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800982A4: jal         0x800DFFDC
    // 0x800982A8: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    func_800DFFDC(rdram, ctx);
        goto after_3;
    // 0x800982A8: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x800982AC: lw          $t9, 0xAC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XAC);
    // 0x800982B0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800982B4: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x800982B8: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800982BC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800982C0: jal         0x800DFFDC
    // 0x800982C4: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    func_800DFFDC(rdram, ctx);
        goto after_4;
    // 0x800982C4: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x800982C8: lw          $t0, 0xAC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XAC);
    // 0x800982CC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800982D0: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    // 0x800982D4: lwc1        $f10, 0xC($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XC);
    // 0x800982D8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800982DC: jal         0x800DFFDC
    // 0x800982E0: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    func_800DFFDC(rdram, ctx);
        goto after_5;
    // 0x800982E0: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x800982E4: lw          $v0, 0xAC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XAC);
    // 0x800982E8: lbu         $t1, 0x2A($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2A);
L_800982EC:
    // 0x800982EC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800982F0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x800982F4: beql        $t1, $zero, L_8009830C
    if (ctx->r9 == 0) {
        // 0x800982F8: lbu         $t2, 0x29($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0X29);
            goto L_8009830C;
    }
    goto skip_2;
    // 0x800982F8: lbu         $t2, 0x29($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X29);
    skip_2:
    // 0x800982FC: jal         0x800DFFA0
    // 0x80098300: addiu       $a2, $v0, 0x1C
    ctx->r6 = ADD32(ctx->r2, 0X1C);
    func_800DFFA0(rdram, ctx);
        goto after_6;
    // 0x80098300: addiu       $a2, $v0, 0x1C
    ctx->r6 = ADD32(ctx->r2, 0X1C);
    after_6:
    // 0x80098304: lw          $v0, 0xAC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XAC);
    // 0x80098308: lbu         $t2, 0x29($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X29);
L_8009830C:
    // 0x8009830C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80098310: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80098314: beql        $t2, $zero, L_8009837C
    if (ctx->r10 == 0) {
        // 0x80098318: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8009837C;
    }
    goto skip_3;
    // 0x80098318: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_3:
    // 0x8009831C: jal         0x800DFF64
    // 0x80098320: addiu       $a2, $v0, 0x10
    ctx->r6 = ADD32(ctx->r2, 0X10);
    func_800DFF64(rdram, ctx);
        goto after_7;
    // 0x80098320: addiu       $a2, $v0, 0x10
    ctx->r6 = ADD32(ctx->r2, 0X10);
    after_7:
    // 0x80098324: lw          $v0, 0xAC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XAC);
    // 0x80098328: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8009832C: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80098330: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x80098334: nop

    // 0x80098338: bc1fl       L_8009837C
    if (!c1cs) {
        // 0x8009833C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8009837C;
    }
    goto skip_4;
    // 0x8009833C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_4:
    // 0x80098340: lwc1        $f2, 0x18($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80098344: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80098348: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8009834C: nop

    // 0x80098350: bc1fl       L_8009837C
    if (!c1cs) {
        // 0x80098354: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8009837C;
    }
    goto skip_5;
    // 0x80098354: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_5:
    // 0x80098358: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009835C: nop

    // 0x80098360: c.eq.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl == ctx->f2.fl;
    // 0x80098364: nop

    // 0x80098368: bc1fl       L_8009837C
    if (!c1cs) {
        // 0x8009836C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8009837C;
    }
    goto skip_6;
    // 0x8009836C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_6:
    // 0x80098370: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80098374: lw          $v0, 0xAC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XAC);
    // 0x80098378: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8009837C:
    // 0x8009837C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80098380: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80098384: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80098388: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    // 0x8009838C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80098390: nop

    // 0x80098394: bc1tl       L_800983F8
    if (c1cs) {
        // 0x80098398: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800983F8;
    }
    goto skip_7;
    // 0x80098398: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8009839C: jal         0x800DFC20
    // 0x800983A0: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800DFC20(rdram, ctx);
        goto after_8;
    // 0x800983A0: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_8:
    // 0x800983A4: lw          $t3, 0xAC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XAC);
    // 0x800983A8: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800983AC: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800983B0: lwc1        $f0, 0x2C($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X2C);
    // 0x800983B4: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800983B8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800983BC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800983C0: nop

    // 0x800983C4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800983C8: nop

    // 0x800983CC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800983D0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800983D4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800983D8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800983DC: jal         0x800EFA4C
    // 0x800983E0: nop

    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x800983E0: nop

    after_9:
    // 0x800983E4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800983E8: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    // 0x800983EC: jal         0x800DFFA0
    // 0x800983F0: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800DFFA0(rdram, ctx);
        goto after_10;
    // 0x800983F0: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_10:
L_800983F4:
    // 0x800983F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800983F8:
    // 0x800983F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800983FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80098400: jr          $ra
    // 0x80098404: nop

    return;
    // 0x80098404: nop

;}
RECOMP_FUNC void func_8080162C_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080162C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801634: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80801638: sb          $a1, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r5;
    // 0x8080163C: sb          $t6, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r14;
    // 0x80801640: sb          $zero, 0xF($a0)
    MEM_B(0XF, ctx->r4) = 0;
    // 0x80801644: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80801648: jal         0x800880D8
    // 0x8080164C: addiu       $a1, $zero, 0x4650
    ctx->r5 = ADD32(0, 0X4650);
    _gcaudiolist_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080164C: addiu       $a1, $zero, 0x4650
    ctx->r5 = ADD32(0, 0X4650);
    after_0:
    // 0x80801650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801658: jr          $ra
    // 0x8080165C: nop

    return;
    // 0x8080165C: nop

;}
RECOMP_FUNC void func_808011CC_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011D4: jal         0x80800ECC
    // 0x808011D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstnt_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808011D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808011DC: jal         0x80082FE0
    // 0x808011E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808011E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808011E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011EC: jr          $ra
    // 0x808011F0: nop

    return;
    // 0x808011F0: nop

;}
RECOMP_FUNC void _bskazpaddle_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083520: syscall     65
    recomp_syscall_handler(rdram, ctx, 0x80083520);
    return;
    // 0x80083524: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800168_chmineproplight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080016C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800170: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800174: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800178: jal         0x800EB854
    // 0x8080017C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_800EB854(rdram, ctx);
        goto after_0;
    // 0x8080017C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800180: beq         $v0, $zero, L_8080020C
    if (ctx->r2 == 0) {
        // 0x80800184: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080020C;
    }
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080018C: bnel        $v0, $at, L_80800218
    if (ctx->r2 != ctx->r1) {
        // 0x80800190: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800218;
    }
    goto skip_0;
    // 0x80800190: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800194: jal         0x800DF830
    // 0x80800198: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_1;
    // 0x80800198: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8080019C: jal         0x800D674C
    // 0x808001A0: addiu       $a0, $zero, 0x695
    ctx->r4 = ADD32(0, 0X695);
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x808001A0: addiu       $a0, $zero, 0x695
    ctx->r4 = ADD32(0, 0X695);
    after_2:
    // 0x808001A4: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x808001A8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808001AC: addiu       $a2, $s0, 0x44
    ctx->r6 = ADD32(ctx->r16, 0X44);
    // 0x808001B0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808001B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808001B8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x808001BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808001C0: jal         0x800DE498
    // 0x808001C4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800DE498(rdram, ctx);
        goto after_3;
    // 0x808001C4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_3:
    // 0x808001C8: jal         0x800D731C
    // 0x808001CC: addiu       $a0, $zero, 0x696
    ctx->r4 = ADD32(0, 0X696);
    func_800D731C(rdram, ctx);
        goto after_4;
    // 0x808001CC: addiu       $a0, $zero, 0x696
    ctx->r4 = ADD32(0, 0X696);
    after_4:
    // 0x808001D0: jal         0x800DF7E8
    // 0x808001D4: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    func_800DF7E8(rdram, ctx);
        goto after_5;
    // 0x808001D4: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    after_5:
    // 0x808001D8: jal         0x800DF830
    // 0x808001DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_6;
    // 0x808001DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x808001E0: jal         0x800D674C
    // 0x808001E4: addiu       $a0, $zero, 0x696
    ctx->r4 = ADD32(0, 0X696);
    func_800D674C(rdram, ctx);
        goto after_7;
    // 0x808001E4: addiu       $a0, $zero, 0x696
    ctx->r4 = ADD32(0, 0X696);
    after_7:
    // 0x808001E8: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x808001EC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x808001F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808001F4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808001F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808001FC: jal         0x800DE498
    // 0x80800200: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800DE498(rdram, ctx);
        goto after_8;
    // 0x80800200: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x80800204: b           L_80800218
    // 0x80800208: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800218;
    // 0x80800208: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080020C:
    // 0x8080020C: jal         0x80101870
    // 0x80800210: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80101870(rdram, ctx);
        goto after_9;
    // 0x80800210: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_9:
    // 0x80800214: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800218:
    // 0x80800218: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080021C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800220: jr          $ra
    // 0x80800224: nop

    return;
    // 0x80800224: nop

;}
RECOMP_FUNC void func_800CF190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF198: jal         0x800CF67C
    // 0x800CF19C: nop

    func_800CF67C(rdram, ctx);
        goto after_0;
    // 0x800CF19C: nop

    after_0:
    // 0x800CF1A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CF1A4: nop

    // 0x800CF1A8: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800CF1AC: nop

    // 0x800CF1B0: bc1t        L_800CF1C8
    if (c1cs) {
        // 0x800CF1B4: nop
    
            goto L_800CF1C8;
    }
    // 0x800CF1B4: nop

    // 0x800CF1B8: jal         0x800CF184
    // 0x800CF1BC: nop

    func_800CF184(rdram, ctx);
        goto after_1;
    // 0x800CF1BC: nop

    after_1:
    // 0x800CF1C0: b           L_800CF258
    // 0x800CF1C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CF258;
    // 0x800CF1C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CF1C8:
    // 0x800CF1C8: jal         0x800CF580
    // 0x800CF1CC: nop

    func_800CF580(rdram, ctx);
        goto after_2;
    // 0x800CF1CC: nop

    after_2:
    // 0x800CF1D0: beql        $v0, $zero, L_800CF258
    if (ctx->r2 == 0) {
        // 0x800CF1D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CF258;
    }
    goto skip_0;
    // 0x800CF1D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800CF1D8: jal         0x800CF7F4
    // 0x800CF1DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CF7F4(rdram, ctx);
        goto after_3;
    // 0x800CF1DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800CF1E0: jal         0x8008FBE0
    // 0x800CF1E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008FBE0(rdram, ctx);
        goto after_4;
    // 0x800CF1E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x800CF1E8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800CF1EC: jal         0x800D9078
    // 0x800CF1F0: addiu       $a0, $a0, -0x4E88
    ctx->r4 = ADD32(ctx->r4, -0X4E88);
    func_800D9078(rdram, ctx);
        goto after_5;
    // 0x800CF1F0: addiu       $a0, $a0, -0x4E88
    ctx->r4 = ADD32(ctx->r4, -0X4E88);
    after_5:
    // 0x800CF1F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CF1F8: lwc1        $f8, -0x4E88($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4E88);
    // 0x800CF1FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CF200: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CF204: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x800CF208: nop

    // 0x800CF20C: bc1fl       L_800CF258
    if (!c1cs) {
        // 0x800CF210: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CF258;
    }
    goto skip_1;
    // 0x800CF210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800CF214: lwc1        $f10, -0x4E8C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4E8C);
    // 0x800CF218: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CF21C: jal         0x8008FBC0
    // 0x800CF220: swc1        $f10, -0x4E88($at)
    MEM_W(-0X4E88, ctx->r1) = ctx->f10.u32l;
    func_8008FBC0(rdram, ctx);
        goto after_6;
    // 0x800CF220: swc1        $f10, -0x4E88($at)
    MEM_W(-0X4E88, ctx->r1) = ctx->f10.u32l;
    after_6:
    // 0x800CF224: jal         0x8008FC00
    // 0x800CF228: nop

    func_8008FC00(rdram, ctx);
        goto after_7;
    // 0x800CF228: nop

    after_7:
    // 0x800CF22C: bnel        $v0, $zero, L_800CF258
    if (ctx->r2 != 0) {
        // 0x800CF230: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CF258;
    }
    goto skip_2;
    // 0x800CF230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800CF234: jal         0x800F54E4
    // 0x800CF238: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x800CF238: nop

    after_8:
    // 0x800CF23C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800CF240: lw          $a1, -0x4E84($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4E84);
    // 0x800CF244: jal         0x800F7B9C
    // 0x800CF248: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F7B9C(rdram, ctx);
        goto after_9;
    // 0x800CF248: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x800CF24C: jal         0x800CF184
    // 0x800CF250: nop

    func_800CF184(rdram, ctx);
        goto after_10;
    // 0x800CF250: nop

    after_10:
    // 0x800CF254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CF258:
    // 0x800CF258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CF25C: jr          $ra
    // 0x800CF260: nop

    return;
    // 0x800CF260: nop

;}
RECOMP_FUNC void sueggmisc_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lhu         $t6, 0x18($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X18);
    // 0x8080000C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800010: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80800014: bnel        $t7, $zero, L_80800028
    if (ctx->r15 != 0) {
        // 0x80800018: lw          $v0, 0x24($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X24);
            goto L_80800028;
    }
    goto skip_0;
    // 0x80800018: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
    skip_0:
    // 0x8080001C: b           L_808000A4
    // 0x80800020: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000A4;
    // 0x80800020: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800024: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
L_80800028:
    // 0x80800028: srl         $t8, $v0, 22
    ctx->r24 = S32(U32(ctx->r2) >> 22);
    // 0x8080002C: slti        $at, $t8, 0x16E
    ctx->r1 = SIGNED(ctx->r24) < 0X16E ? 1 : 0;
    // 0x80800030: bne         $at, $zero, L_8080005C
    if (ctx->r1 != 0) {
        // 0x80800034: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8080005C;
    }
    // 0x80800034: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80800038: addiu       $t9, $t8, -0x26C
    ctx->r25 = ADD32(ctx->r24, -0X26C);
    // 0x8080003C: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x80800040: beq         $at, $zero, L_808000A0
    if (ctx->r1 == 0) {
        // 0x80800044: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808000A0;
    }
    // 0x80800044: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800048: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3306, 0X190) << 16);
    // 0x8080004C: addu        $at, $at, $t9
    gpr jr_addend_80800054 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800050: lw          $t9, 0x190($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3306, 0X190));
    // 0x80800054: jr          $t9
    // 0x80800058: nop

    switch (jr_addend_80800054 >> 2) {
        case 0: goto L_80800068; break;
        case 1: goto L_80800068; break;
        case 2: goto L_80800068; break;
        case 3: goto L_80800070; break;
        case 4: goto L_80800070; break;
        default: switch_error(__func__, 0x80800054, 0x80800190);
    }
    // 0x80800058: nop

L_8080005C:
    // 0x8080005C: addiu       $at, $zero, 0x16D
    ctx->r1 = ADD32(0, 0X16D);
    // 0x80800060: bnel        $v0, $at, L_808000A4
    if (ctx->r2 != ctx->r1) {
        // 0x80800064: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808000A4;
    }
    goto skip_1;
    // 0x80800064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
L_80800068:
    // 0x80800068: b           L_808000A4
    // 0x8080006C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000A4;
    // 0x8080006C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800070:
    // 0x80800070: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800074: jal         0x80106790
    // 0x80800078: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800078: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080007C: jal         0x80100368
    // 0x80800080: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80100368(rdram, ctx);
        goto after_1;
    // 0x80800080: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800084: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800088: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x8080008C: lw          $t0, 0x24($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X24);
    // 0x80800090: srl         $t1, $t0, 22
    ctx->r9 = S32(U32(ctx->r8) >> 22);
    // 0x80800094: xor         $v0, $t1, $t2
    ctx->r2 = ctx->r9 ^ ctx->r10;
    // 0x80800098: b           L_808000A4
    // 0x8080009C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_808000A4;
    // 0x8080009C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_808000A0:
    // 0x808000A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000A4:
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_80095380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095380: jr          $ra
    // 0x80095384: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    return;
    // 0x80095384: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800000_chjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: lbu         $t6, 0x79($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X79);
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x80800018: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x8080001C: sb          $t8, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r24;
    // 0x80800020: jal         0x800DA298
    // 0x80800024: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800024: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    after_0:
    // 0x80800028: beql        $v0, $zero, L_8080003C
    if (ctx->r2 == 0) {
        // 0x8080002C: lw          $v0, 0x6C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X6C);
            goto L_8080003C;
    }
    goto skip_0;
    // 0x8080002C: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x80800030: jal         0x800FFAB0
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800038: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
L_8080003C:
    // 0x8080003C: addiu       $at, $zero, 0x48F
    ctx->r1 = ADD32(0, 0X48F);
    // 0x80800040: sll         $t9, $v0, 11
    ctx->r25 = S32(ctx->r2 << 11);
    // 0x80800044: srl         $t0, $t9, 20
    ctx->r8 = S32(U32(ctx->r25) >> 20);
    // 0x80800048: bne         $t0, $at, L_80800060
    if (ctx->r8 != ctx->r1) {
        // 0x8080004C: nop
    
            goto L_80800060;
    }
    // 0x8080004C: nop

    // 0x80800050: jal         0x808001A0
    // 0x80800054: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    chjinjo_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800054: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_2:
    // 0x80800058: b           L_8080006C
    // 0x8080005C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8080006C;
    // 0x8080005C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80800060:
    // 0x80800060: jal         0x800D0CC8
    // 0x80800064: andi        $a0, $v0, 0x1FF
    ctx->r4 = ctx->r2 & 0X1FF;
    func_800D0CC8(rdram, ctx);
        goto after_3;
    // 0x80800064: andi        $a0, $v0, 0x1FF
    ctx->r4 = ctx->r2 & 0X1FF;
    after_3:
    // 0x80800068: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8080006C:
    // 0x8080006C: lw          $t1, 0x6C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X6C);
    // 0x80800070: addiu       $at, $zero, 0x48F
    ctx->r1 = ADD32(0, 0X48F);
    // 0x80800074: sll         $t2, $t1, 11
    ctx->r10 = S32(ctx->r9 << 11);
    // 0x80800078: srl         $t3, $t2, 20
    ctx->r11 = S32(U32(ctx->r10) >> 20);
    // 0x8080007C: bnel        $t3, $at, L_808000B4
    if (ctx->r11 != ctx->r1) {
        // 0x80800080: lw          $t4, 0x64($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X64);
            goto L_808000B4;
    }
    goto skip_1;
    // 0x80800080: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    skip_1:
    // 0x80800084: jal         0x800D1338
    // 0x80800088: nop

    func_800D1338(rdram, ctx);
        goto after_4;
    // 0x80800088: nop

    after_4:
    // 0x8080008C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80800090: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800094: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800098: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x8080009C: nop

    // 0x808000A0: bc1fl       L_808000B4
    if (!c1cs) {
        // 0x808000A4: lw          $t4, 0x64($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X64);
            goto L_808000B4;
    }
    goto skip_2;
    // 0x808000A4: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    skip_2:
    // 0x808000A8: jal         0x800FFAB0
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000B0: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
L_808000B4:
    // 0x808000B4: sll         $t6, $t4, 11
    ctx->r14 = S32(ctx->r12 << 11);
    // 0x808000B8: bgezl       $t6, L_808000CC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808000BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000CC;
    }
    goto skip_3;
    // 0x808000BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x808000C0: jal         0x800FC660
    // 0x808000C4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800FC660(rdram, ctx);
        goto after_6;
    // 0x808000C4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_6:
    // 0x808000C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000CC:
    // 0x808000CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000D4: jr          $ra
    // 0x808000D8: nop

    return;
    // 0x808000D8: nop

;}
RECOMP_FUNC void func_800A791C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A791C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7924: jal         0x800A79D4
    // 0x800A7928: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800A79D4(rdram, ctx);
        goto after_0;
    // 0x800A7928: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A792C: jal         0x800A7A90
    // 0x800A7930: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800A7A90(rdram, ctx);
        goto after_1;
    // 0x800A7930: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800A7934: jal         0x800A7B18
    // 0x800A7938: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A7B18(rdram, ctx);
        goto after_2;
    // 0x800A7938: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x800A793C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7940: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A7944: jr          $ra
    // 0x800A7948: nop

    return;
    // 0x800A7948: nop

;}
RECOMP_FUNC void _basub_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085188: syscall     154
    recomp_syscall_handler(rdram, ctx, 0x80085188);
    return;
    // 0x8008518C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void sucoasterdata_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800134: sltiu       $at, $a0, 0x9
    ctx->r1 = ctx->r4 < 0X9 ? 1 : 0;
    // 0x80800138: beq         $at, $zero, L_808001A0
    if (ctx->r1 == 0) {
        // 0x8080013C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808001A0;
    }
    // 0x8080013C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800140: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800144: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3282, 0X354) << 16);
    // 0x80800148: addu        $at, $at, $t6
    gpr jr_addend_80800150 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080014C: lw          $t6, 0x354($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3282, 0X354));
    // 0x80800150: jr          $t6
    // 0x80800154: nop

    switch (jr_addend_80800150 >> 2) {
        case 0: goto L_80800158; break;
        case 1: goto L_80800160; break;
        case 2: goto L_80800168; break;
        case 3: goto L_80800170; break;
        case 4: goto L_80800178; break;
        case 5: goto L_80800180; break;
        case 6: goto L_80800188; break;
        case 7: goto L_80800190; break;
        case 8: goto L_80800198; break;
        default: switch_error(__func__, 0x80800150, 0x80800354);
    }
    // 0x80800154: nop

L_80800158:
    // 0x80800158: jr          $ra
    // 0x8080015C: addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    return;
    // 0x8080015C: addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
L_80800160:
    // 0x80800160: jr          $ra
    // 0x80800164: addiu       $v0, $zero, 0xD2
    ctx->r2 = ADD32(0, 0XD2);
    return;
    // 0x80800164: addiu       $v0, $zero, 0xD2
    ctx->r2 = ADD32(0, 0XD2);
L_80800168:
    // 0x80800168: jr          $ra
    // 0x8080016C: addiu       $v0, $zero, 0xB4
    ctx->r2 = ADD32(0, 0XB4);
    return;
    // 0x8080016C: addiu       $v0, $zero, 0xB4
    ctx->r2 = ADD32(0, 0XB4);
L_80800170:
    // 0x80800170: jr          $ra
    // 0x80800174: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    return;
    // 0x80800174: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
L_80800178:
    // 0x80800178: jr          $ra
    // 0x8080017C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    return;
    // 0x8080017C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
L_80800180:
    // 0x80800180: jr          $ra
    // 0x80800184: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    return;
    // 0x80800184: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
L_80800188:
    // 0x80800188: jr          $ra
    // 0x8080018C: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
    return;
    // 0x8080018C: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
L_80800190:
    // 0x80800190: jr          $ra
    // 0x80800194: addiu       $v0, $zero, 0xAA
    ctx->r2 = ADD32(0, 0XAA);
    return;
    // 0x80800194: addiu       $v0, $zero, 0xAA
    ctx->r2 = ADD32(0, 0XAA);
L_80800198:
    // 0x80800198: jr          $ra
    // 0x8080019C: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
    return;
    // 0x8080019C: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
L_808001A0:
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

;}
RECOMP_FUNC void func_808051C4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808051C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808051C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808051CC: jal         0x80082FE8
    // 0x808051D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808051D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808051D4: jal         0x80807D48
    // 0x808051D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807D48_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808051D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808051DC: jal         0x80809D24
    // 0x808051E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80809D24_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x808051E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808051E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808051E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808051EC: jr          $ra
    // 0x808051F0: nop

    return;
    // 0x808051F0: nop

;}
RECOMP_FUNC void func_80026F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026F40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026F44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026F48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80026F4C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80026F50: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80026F54: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80026F58: beq         $t7, $zero, L_80026FD8
    if (ctx->r15 == 0) {
        // 0x80026F5C: nop
    
            goto L_80026FD8;
    }
    // 0x80026F5C: nop

    // 0x80026F60: jal         0x80021794
    // 0x80026F64: nop

    func_80021794(rdram, ctx);
        goto after_0;
    // 0x80026F64: nop

    after_0:
    // 0x80026F68: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80026F6C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80026F70: bne         $t8, $zero, L_80026F80
    if (ctx->r24 != 0) {
        // 0x80026F74: nop
    
            goto L_80026F80;
    }
    // 0x80026F74: nop

    // 0x80026F78: b           L_80026FE0
    // 0x80026F7C: nop

        goto L_80026FE0;
    // 0x80026F7C: nop

L_80026F80:
    // 0x80026F80: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80026F84: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80026F88: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x80026F8C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80026F90: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80026F94: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x80026F98: lw          $t3, 0x88($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X88);
    // 0x80026F9C: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x80026FA0: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x80026FA4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80026FA8: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x80026FAC: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x80026FB0: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x80026FB4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80026FB8: sw          $t8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r24;
    // 0x80026FBC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80026FC0: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80026FC4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80026FC8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80026FCC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80026FD0: jal         0x8002B684
    // 0x80026FD4: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    func_8002B684(rdram, ctx);
        goto after_1;
    // 0x80026FD4: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    after_1:
L_80026FD8:
    // 0x80026FD8: b           L_80026FE0
    // 0x80026FDC: nop

        goto L_80026FE0;
    // 0x80026FDC: nop

L_80026FE0:
    // 0x80026FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026FE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026FE8: jr          $ra
    // 0x80026FEC: nop

    return;
    // 0x80026FEC: nop

;}
RECOMP_FUNC void _basnowball_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085108: syscall     151
    recomp_syscall_handler(rdram, ctx, 0x80085108);
    return;
    // 0x8008510C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80081D28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081D28: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80081D2C: jr          $ra
    // 0x80081D30: lw          $v0, 0x6CBC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CBC);
    return;
    // 0x80081D30: lw          $v0, 0x6CBC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CBC);
;}
RECOMP_FUNC void func_80800018_chcablecar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080001C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800024: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800028: jal         0x80100094
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800030: jal         0x800D8FF8
    // 0x80800034: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800034: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800038: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: jal         0x80800598
    // 0x80800044: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    func_80800598_chcablecar(rdram, ctx);
        goto after_2;
    // 0x80800044: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80800048: jal         0x8080069C
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080069C_chcablecar(rdram, ctx);
        goto after_3;
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800050: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800054: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800058: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080005C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800060: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x80800064: beq         $at, $zero, L_808002A8
    if (ctx->r1 == 0) {
        // 0x80800068: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808002A8;
    }
    // 0x80800068: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080006C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(972, 0XE60) << 16);
    // 0x80800070: addu        $at, $at, $t8
    gpr jr_addend_80800078 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800074: lw          $t8, 0xE60($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(972, 0XE60));
    // 0x80800078: jr          $t8
    // 0x8080007C: nop

    switch (jr_addend_80800078 >> 2) {
        case 0: goto L_80800080; break;
        case 1: goto L_808000AC; break;
        case 2: goto L_808000D8; break;
        case 3: goto L_80800180; break;
        case 4: goto L_808001E0; break;
        case 5: goto L_8080024C; break;
        case 6: goto L_808002A0; break;
        default: switch_error(__func__, 0x80800078, 0x80800E60);
    }
    // 0x8080007C: nop

L_80800080:
    // 0x80800080: jal         0x800DA298
    // 0x80800084: addiu       $a0, $zero, 0xD4
    ctx->r4 = ADD32(0, 0XD4);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800084: addiu       $a0, $zero, 0xD4
    ctx->r4 = ADD32(0, 0XD4);
    after_4:
    // 0x80800088: beq         $v0, $zero, L_8080009C
    if (ctx->r2 == 0) {
        // 0x8080008C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080009C;
    }
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800090: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800094: jal         0x808007C8
    // 0x80800098: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_808007C8_chcablecar(rdram, ctx);
        goto after_5;
    // 0x80800098: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
L_8080009C:
    // 0x8080009C: jal         0x808005E0
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005E0_chcablecar(rdram, ctx);
        goto after_6;
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000A4: b           L_808002AC
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808002AC;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000AC:
    // 0x808000AC: jal         0x80800BD0
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BD0_chcablecar(rdram, ctx);
        goto after_7;
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000B4: beq         $v0, $zero, L_808000C8
    if (ctx->r2 == 0) {
        // 0x808000B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000C8;
    }
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808000C0: jal         0x808007C8
    // 0x808000C4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_808007C8_chcablecar(rdram, ctx);
        goto after_8;
    // 0x808000C4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_8:
L_808000C8:
    // 0x808000C8: jal         0x808005E0
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005E0_chcablecar(rdram, ctx);
        goto after_9;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808000D0: b           L_808002AC
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808002AC;
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000D8:
    // 0x808000D8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x808000DC: lw          $t0, 0x28($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X28);
    // 0x808000E0: sll         $t2, $t0, 19
    ctx->r10 = S32(ctx->r8 << 19);
    // 0x808000E4: bltz        $t2, L_80800154
    if (SIGNED(ctx->r10) < 0) {
        // 0x808000E8: nop
    
            goto L_80800154;
    }
    // 0x808000E8: nop

    // 0x808000EC: jal         0x8010D254
    // 0x808000F0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_8010D254(rdram, ctx);
        goto after_10;
    // 0x808000F0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_10:
    // 0x808000F4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808000F8: jal         0x800EE7F8
    // 0x808000FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x808000FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_11:
    // 0x80800100: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80800104: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800108: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080010C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800110: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800114: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800118: jal         0x800EEB40
    // 0x8080011C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    func_800EEB40(rdram, ctx);
        goto after_12;
    // 0x8080011C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_12:
    // 0x80800120: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(972, 0XE7C) << 16);
    // 0x80800124: lwc1        $f10, 0xE7C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(972, 0XE7C));
    // 0x80800128: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8080012C: nop

    // 0x80800130: bc1f        L_80800170
    if (!c1cs) {
        // 0x80800134: nop
    
            goto L_80800170;
    }
    // 0x80800134: nop

    // 0x80800138: jal         0x800DA524
    // 0x8080013C: addiu       $a0, $zero, 0x67E
    ctx->r4 = ADD32(0, 0X67E);
    func_800DA524(rdram, ctx);
        goto after_13;
    // 0x8080013C: addiu       $a0, $zero, 0x67E
    ctx->r4 = ADD32(0, 0X67E);
    after_13:
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800144: jal         0x80101FDC
    // 0x80800148: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80101FDC(rdram, ctx);
        goto after_14;
    // 0x80800148: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_14:
    // 0x8080014C: b           L_80800170
    // 0x80800150: nop

        goto L_80800170;
    // 0x80800150: nop

L_80800154:
    // 0x80800154: jal         0x80800BD0
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BD0_chcablecar(rdram, ctx);
        goto after_15;
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8080015C: beq         $v0, $zero, L_80800170
    if (ctx->r2 == 0) {
        // 0x80800160: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800170;
    }
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800164: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800168: jal         0x808007C8
    // 0x8080016C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_808007C8_chcablecar(rdram, ctx);
        goto after_16;
    // 0x8080016C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_16:
L_80800170:
    // 0x80800170: jal         0x808005E0
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005E0_chcablecar(rdram, ctx);
        goto after_17;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800178: b           L_808002AC
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808002AC;
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800180:
    // 0x80800180: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(972, 0XE80) << 16);
    // 0x80800184: lwc1        $f18, 0xE80($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(972, 0XE80));
    // 0x80800188: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8080018C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800190: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80800194: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x80800198: lwc1        $f16, 0xC($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A0: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x808001A4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808001A8: jal         0x8080070C
    // 0x808001AC: nop

    func_8080070C_chcablecar(rdram, ctx);
        goto after_18;
    // 0x808001AC: nop

    after_18:
    // 0x808001B0: beq         $v0, $zero, L_808002A8
    if (ctx->r2 == 0) {
        // 0x808001B4: lw          $a1, 0x44($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X44);
            goto L_808002A8;
    }
    // 0x808001B4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: jal         0x8008A2C0
    // 0x808001C0: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_19;
    // 0x808001C0: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    after_19:
    // 0x808001C4: jal         0x800DA524
    // 0x808001C8: addiu       $a0, $zero, 0x67E
    ctx->r4 = ADD32(0, 0X67E);
    func_800DA524(rdram, ctx);
        goto after_20;
    // 0x808001C8: addiu       $a0, $zero, 0x67E
    ctx->r4 = ADD32(0, 0X67E);
    after_20:
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: jal         0x80800AF4
    // 0x808001D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800AF4_chcablecar(rdram, ctx);
        goto after_21;
    // 0x808001D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_21:
    // 0x808001D8: b           L_808002AC
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808002AC;
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001E0:
    // 0x808001E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(972, 0XE84) << 16);
    // 0x808001E4: lwc1        $f10, 0xE84($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(972, 0XE84));
    // 0x808001E8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x808001EC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x808001F0: mul.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x808001F4: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x808001F8: lwc1        $f8, 0xC($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XC);
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800200: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80800204: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800208: jal         0x8080070C
    // 0x8080020C: nop

    func_8080070C_chcablecar(rdram, ctx);
        goto after_22;
    // 0x8080020C: nop

    after_22:
    // 0x80800210: beq         $v0, $zero, L_808002A8
    if (ctx->r2 == 0) {
        // 0x80800214: lw          $a1, 0x44($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X44);
            goto L_808002A8;
    }
    // 0x80800214: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x8008A2C0
    // 0x80800220: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_23;
    // 0x80800220: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    after_23:
    // 0x80800224: jal         0x800DA544
    // 0x80800228: addiu       $a0, $zero, 0x67E
    ctx->r4 = ADD32(0, 0X67E);
    func_800DA544(rdram, ctx);
        goto after_24;
    // 0x80800228: addiu       $a0, $zero, 0x67E
    ctx->r4 = ADD32(0, 0X67E);
    after_24:
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800230: jal         0x80800AF4
    // 0x80800234: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800AF4_chcablecar(rdram, ctx);
        goto after_25;
    // 0x80800234: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_25:
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x8008A4B0
    // 0x80800240: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_26;
    // 0x80800240: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80800244: b           L_808002AC
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808002AC;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080024C:
    // 0x8080024C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(972, 0XE88) << 16);
    // 0x80800250: lwc1        $f6, 0xE88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(972, 0XE88));
    // 0x80800254: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80800258: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080025C: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80800260: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80800264: lwc1        $f4, 0xC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80800270: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800274: jal         0x8080070C
    // 0x80800278: nop

    func_8080070C_chcablecar(rdram, ctx);
        goto after_27;
    // 0x80800278: nop

    after_27:
    // 0x8080027C: beq         $v0, $zero, L_808002A8
    if (ctx->r2 == 0) {
        // 0x80800280: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A8;
    }
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: jal         0x8008A4B0
    // 0x80800288: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_28;
    // 0x80800288: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_28:
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: jal         0x80101FDC
    // 0x80800294: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_29;
    // 0x80800294: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_29:
    // 0x80800298: b           L_808002AC
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808002AC;
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002A0:
    // 0x808002A0: jal         0x808005E0
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005E0_chcablecar(rdram, ctx);
        goto after_30;
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
L_808002A8:
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002AC:
    // 0x808002AC: jal         0x80800D14
    // 0x808002B0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80800D14_chcablecar(rdram, ctx);
        goto after_31;
    // 0x808002B0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_31:
    // 0x808002B4: jal         0x80800914
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800914_chcablecar(rdram, ctx);
        goto after_32;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x808002BC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x808002C0: lbu         $t9, 0x2A($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2A);
    // 0x808002C4: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x808002C8: sb          $t0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r8;
    // 0x808002CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002D4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808002D8: jr          $ra
    // 0x808002DC: nop

    return;
    // 0x808002DC: nop

;}
RECOMP_FUNC void func_8010FC38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_camera_controller_step(rdram, ctx);
    // 0x8010FC38: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8010FC3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010FC40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010FC44: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x8010FC48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010FC4C: lh          $v0, 0x16($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X16);
    // 0x8010FC50: bne         $t6, $zero, L_8010FC68
    if (ctx->r14 != 0) {
        // 0x8010FC54: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8010FC68;
    }
    // 0x8010FC54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8010FC58: lbu         $t7, 0x19($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X19);
    // 0x8010FC5C: bne         $t7, $zero, L_8010FC68
    if (ctx->r15 != 0) {
        // 0x8010FC60: nop
    
            goto L_8010FC68;
    }
    // 0x8010FC60: nop

    // 0x8010FC64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010FC68:
    // 0x8010FC68: beq         $v0, $at, L_8010FC8C
    if (ctx->r2 == ctx->r1) {
        // 0x8010FC6C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8010FC8C;
    }
    // 0x8010FC6C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8010FC70: beq         $v0, $at, L_8010FC9C
    if (ctx->r2 == ctx->r1) {
        // 0x8010FC74: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8010FC9C;
    }
    // 0x8010FC74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8010FC78: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8010FC7C: beq         $v0, $at, L_8010FCAC
    if (ctx->r2 == ctx->r1) {
        // 0x8010FC80: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8010FCAC;
    }
    // 0x8010FC80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8010FC84: b           L_8010FCB8
    // 0x8010FC88: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
        goto L_8010FCB8;
    // 0x8010FC88: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8010FC8C:
    // 0x8010FC8C: jal         0x80110588
    // 0x8010FC90: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_80110588(rdram, ctx);
        goto after_0;
    // 0x8010FC90: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_0:
    // 0x8010FC94: b           L_8010FCB8
    // 0x8010FC98: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
        goto L_8010FCB8;
    // 0x8010FC98: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8010FC9C:
    // 0x8010FC9C: jal         0x80089208
    // 0x8010FCA0: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    _ncfixposrot_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x8010FCA0: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    after_1:
    // 0x8010FCA4: b           L_8010FCB8
    // 0x8010FCA8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
        goto L_8010FCB8;
    // 0x8010FCA8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8010FCAC:
    // 0x8010FCAC: jal         0x80089530
    // 0x8010FCB0: lh          $a0, 0x14($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X14);
    _ncpod_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x8010FCB0: lh          $a0, 0x14($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X14);
    after_2:
    // 0x8010FCB4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8010FCB8:
    tooie_free_camera(rdram, ctx);
    // 0x8010FCB8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8010FCBC: jal         0x800CA8B4
    // 0x8010FCC0: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_800CA8B4(rdram, ctx);
        goto after_3;
    // 0x8010FCC0: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x8010FCC4: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8010FCC8: jal         0x800E1A58
    // 0x8010FCCC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800E1A58(rdram, ctx);
        goto after_4;
    // 0x8010FCCC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x8010FCD0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8010FCD4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8010FCD8: jal         0x800CA628
    // 0x8010FCDC: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_800CA628(rdram, ctx);
        goto after_5;
    // 0x8010FCDC: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x8010FCE0: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x8010FCE4: beql        $a0, $zero, L_8010FCF8
    if (ctx->r4 == 0) {
        // 0x8010FCE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8010FCF8;
    }
    goto skip_0;
    // 0x8010FCE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8010FCEC: jal         0x801151C4
    // 0x8010FCF0: nop

    func_801151C4(rdram, ctx);
        goto after_6;
    // 0x8010FCF0: nop

    after_6:
    // 0x8010FCF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8010FCF8:
    // 0x8010FCF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010FCFC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8010FD00: jr          $ra
    // 0x8010FD04: nop

    return;
    // 0x8010FD04: nop

;}
RECOMP_FUNC void _bashoes_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084FE8: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80084FE8);
    return;
    // 0x80084FEC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8080682C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080682C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80806830: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80806834: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80806838: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080683C: lw          $s0, 0x188($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X188);
    // 0x80806840: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80806844: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80806848: beq         $v0, $zero, L_80806860
    if (ctx->r2 == 0) {
        // 0x8080684C: nop
    
            goto L_80806860;
    }
    // 0x8080684C: nop

    // 0x80806850: beq         $v0, $at, L_80806870
    if (ctx->r2 == ctx->r1) {
        // 0x80806854: nop
    
            goto L_80806870;
    }
    // 0x80806854: nop

    // 0x80806858: b           L_80806880
    // 0x8080685C: lwc1        $f4, 0x20C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20C);
        goto L_80806880;
    // 0x8080685C: lwc1        $f4, 0x20C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20C);
L_80806860:
    // 0x80806860: jal         0x808068E8
    // 0x80806864: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808068E8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80806864: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x80806868: b           L_8080687C
    // 0x8080686C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
        goto L_8080687C;
    // 0x8080686C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
L_80806870:
    // 0x80806870: jal         0x80806928
    // 0x80806874: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80806928_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80806874: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80806878: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
L_8080687C:
    // 0x8080687C: lwc1        $f4, 0x20C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20C);
L_80806880:
    // 0x80806880: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80806884: jal         0x80013728
    // 0x80806888: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_80013728(rdram, ctx);
        goto after_2;
    // 0x80806888: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_2:
    // 0x8080688C: swc1        $f0, 0x20C($s0)
    MEM_W(0X20C, ctx->r16) = ctx->f0.u32l;
    // 0x80806890: jal         0x80809D94
    // 0x80806894: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80809D94_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80806894: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80806898: lwc1        $f8, 0x1EC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1EC);
    // 0x8080689C: lwc1        $f2, 0x20C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20C);
    // 0x808068A0: lwc1        $f14, 0x1E8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X1E8);
    // 0x808068A4: add.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x808068A8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x808068AC: nop

    // 0x808068B0: bc1fl       L_808068C4
    if (!c1cs) {
        // 0x808068B4: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_808068C4;
    }
    goto skip_0;
    // 0x808068B4: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_0:
    // 0x808068B8: swc1        $f12, 0x20C($s0)
    MEM_W(0X20C, ctx->r16) = ctx->f12.u32l;
    // 0x808068BC: lwc1        $f2, 0x20C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20C);
    // 0x808068C0: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_808068C4:
    // 0x808068C4: nop

    // 0x808068C8: bc1fl       L_808068D8
    if (!c1cs) {
        // 0x808068CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808068D8;
    }
    goto skip_1;
    // 0x808068CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808068D0: swc1        $f14, 0x20C($s0)
    MEM_W(0X20C, ctx->r16) = ctx->f14.u32l;
    // 0x808068D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808068D8:
    // 0x808068D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808068DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808068E0: jr          $ra
    // 0x808068E4: nop

    return;
    // 0x808068E4: nop

;}
RECOMP_FUNC void func_80802F14_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802F14: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80802F18: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80802F1C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80802F20: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80802F24: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80802F28: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80802F2C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80802F30: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80802F34: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80802F38: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80802F3C: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80802F40: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80802F44: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80802F48: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80802F4C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80802F50: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80802F54: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80802F58: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80802F5C: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
L_80802F60:
    // 0x80802F60: jal         0x800F6438
    // 0x80802F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_0;
    // 0x80802F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80802F68: beql        $v0, $zero, L_80802FB4
    if (ctx->r2 == 0) {
        // 0x80802F6C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80802FB4;
    }
    goto skip_0;
    // 0x80802F6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80802F70: bnel        $s2, $zero, L_80802F9C
    if (ctx->r18 != 0) {
        // 0x80802F74: mfc1        $a2, $f20
        ctx->r6 = (int32_t)ctx->f20.u32l;
            goto L_80802F9C;
    }
    goto skip_1;
    // 0x80802F74: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    skip_1:
    // 0x80802F78: jal         0x800F682C
    // 0x80802F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F682C(rdram, ctx);
        goto after_1;
    // 0x80802F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80802F80: beql        $v0, $zero, L_80802F9C
    if (ctx->r2 == 0) {
        // 0x80802F84: mfc1        $a2, $f20
        ctx->r6 = (int32_t)ctx->f20.u32l;
            goto L_80802F9C;
    }
    goto skip_2;
    // 0x80802F84: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    skip_2:
    // 0x80802F88: jal         0x800F6AA4
    // 0x80802F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6AA4(rdram, ctx);
        goto after_2;
    // 0x80802F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802F90: beql        $v0, $zero, L_80802FB4
    if (ctx->r2 == 0) {
        // 0x80802F94: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80802FB4;
    }
    goto skip_3;
    // 0x80802F94: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x80802F98: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
L_80802F9C:
    // 0x80802F9C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80802FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802FA4: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    // 0x80802FA8: jal         0x800F4EC8
    // 0x80802FAC: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_800F4EC8(rdram, ctx);
        goto after_3;
    // 0x80802FAC: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_3:
    // 0x80802FB0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80802FB4:
    // 0x80802FB4: bne         $s0, $s1, L_80802F60
    if (ctx->r16 != ctx->r17) {
        // 0x80802FB8: nop
    
            goto L_80802F60;
    }
    // 0x80802FB8: nop

    // 0x80802FBC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80802FC0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80802FC4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80802FC8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80802FCC: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80802FD0: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80802FD4: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80802FD8: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80802FDC: jr          $ra
    // 0x80802FE0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80802FE0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80800258_bsclimb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080025C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800260: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800264: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800268: jal         0x800DC0C0
    // 0x8080026C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x8080026C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800270: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800274: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800278: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080027C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800280: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800284: swc1        $f10, 0x16C($t6)
    MEM_W(0X16C, ctx->r14) = ctx->f10.u32l;
    // 0x80800288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080028C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800290: jr          $ra
    // 0x80800294: nop

    return;
    // 0x80800294: nop

;}
RECOMP_FUNC void _cothemedll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087868: syscall     635
    recomp_syscall_handler(rdram, ctx, 0x80087868);
    return;
    // 0x8008786C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chtoxicroombits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087538: syscall     585
    recomp_syscall_handler(rdram, ctx, 0x80087538);
    return;
    // 0x8008753C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080014C_chfactoryentrydoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080014C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800158: jal         0x800DA298
    // 0x8080015C: addiu       $a0, $zero, 0x397
    ctx->r4 = ADD32(0, 0X397);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080015C: addiu       $a0, $zero, 0x397
    ctx->r4 = ADD32(0, 0X397);
    after_0:
    // 0x80800160: bne         $v0, $zero, L_80800178
    if (ctx->r2 != 0) {
        // 0x80800164: nop
    
            goto L_80800178;
    }
    // 0x80800164: nop

    // 0x80800168: jal         0x800D3E40
    // 0x8080016C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800D3E40(rdram, ctx);
        goto after_1;
    // 0x8080016C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_1:
    // 0x80800170: beql        $v0, $zero, L_80800194
    if (ctx->r2 == 0) {
        // 0x80800174: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800194;
    }
    goto skip_0;
    // 0x80800174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80800178:
    // 0x80800178: jal         0x80088840
    // 0x8080017C: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_2;
    // 0x8080017C: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    after_2:
    // 0x80800180: bnel        $v0, $zero, L_80800194
    if (ctx->r2 != 0) {
        // 0x80800184: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800194;
    }
    goto skip_1;
    // 0x80800184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800188: jal         0x800FFAB0
    // 0x8080018C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x8080018C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800194:
    // 0x80800194: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800198: jr          $ra
    // 0x8080019C: nop

    return;
    // 0x8080019C: nop

;}
RECOMP_FUNC void _charmouredcaveman_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086190: syscall     284
    recomp_syscall_handler(rdram, ctx, 0x80086190);
    return;
    // 0x80086194: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bskazjump_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083488: syscall     62
    recomp_syscall_handler(rdram, ctx, 0x80083488);
    return;
    // 0x8008348C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80801C18_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801C24: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80801C28: jal         0x80102424
    // 0x80801C2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80801C2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801C30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801C34: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801C38: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80801C3C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801C40: bnel        $t7, $at, L_80801C54
    if (ctx->r15 != ctx->r1) {
        // 0x80801C44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801C54;
    }
    goto skip_0;
    // 0x80801C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801C48: jal         0x80089CB8
    // 0x80801C4C: nop

    _subaddiefade_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80801C4C: nop

    after_1:
    // 0x80801C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801C54:
    // 0x80801C54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801C58: jr          $ra
    // 0x80801C5C: nop

    return;
    // 0x80801C5C: nop

;}
RECOMP_FUNC void _chfactoryprop_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800861C8: syscall     287
    recomp_syscall_handler(rdram, ctx, 0x800861C8);
    return;
    // 0x800861CC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void gczoombox_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808018D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808018D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808018DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808018E0: beq         $a0, $zero, L_80801B1C
    if (ctx->r4 == 0) {
        // 0x808018E4: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_80801B1C;
    }
    // 0x808018E4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808018E8: lw          $v1, 0x1E4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E4);
    // 0x808018EC: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x808018F0: bgezl       $t7, L_80801B20
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808018F4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801B20;
    }
    goto skip_0;
    // 0x808018F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808018F8: lbu         $t8, 0x171($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X171);
    // 0x808018FC: sll         $t0, $v1, 25
    ctx->r8 = S32(ctx->r3 << 25);
    // 0x80801900: beql        $t8, $zero, L_80801B20
    if (ctx->r24 == 0) {
        // 0x80801904: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801B20;
    }
    goto skip_1;
    // 0x80801904: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80801908: bgez        $t0, L_8080191C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8080190C: addiu       $t2, $zero, 0x80
        ctx->r10 = ADD32(0, 0X80);
            goto L_8080191C;
    }
    // 0x8080190C: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80801910: addiu       $t1, $zero, 0xAA
    ctx->r9 = ADD32(0, 0XAA);
    // 0x80801914: b           L_80801920
    // 0x80801918: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
        goto L_80801920;
    // 0x80801918: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_8080191C:
    // 0x8080191C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_80801920:
    // 0x80801920: jal         0x80800FE0
    // 0x80801924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800FE0_gczoombox(rdram, ctx);
        goto after_0;
    // 0x80801924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80801928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080192C: jal         0x80801424
    // 0x80801930: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80801424_gczoombox(rdram, ctx);
        goto after_1;
    // 0x80801930: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80801934: lbu         $t3, 0x176($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X176);
    // 0x80801938: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080193C: beql        $t3, $at, L_80801964
    if (ctx->r11 == ctx->r1) {
        // 0x80801940: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801964;
    }
    goto skip_2;
    // 0x80801940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80801944: jal         0x800A819C
    // 0x80801948: nop

    func_800A819C(rdram, ctx);
        goto after_2;
    // 0x80801948: nop

    after_2:
    // 0x8080194C: bnel        $v0, $zero, L_80801978
    if (ctx->r2 != 0) {
        // 0x80801950: lbu         $a1, 0x1E5($s0)
        ctx->r5 = MEM_BU(ctx->r16, 0X1E5);
            goto L_80801978;
    }
    goto skip_3;
    // 0x80801950: lbu         $a1, 0x1E5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1E5);
    skip_3:
    // 0x80801954: jal         0x800DA298
    // 0x80801958: addiu       $a0, $zero, 0x650
    ctx->r4 = ADD32(0, 0X650);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80801958: addiu       $a0, $zero, 0x650
    ctx->r4 = ADD32(0, 0X650);
    after_3:
    // 0x8080195C: bne         $v0, $zero, L_80801974
    if (ctx->r2 != 0) {
        // 0x80801960: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801974;
    }
    // 0x80801960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801964:
    // 0x80801964: jal         0x8080156C
    // 0x80801968: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080156C_gczoombox(rdram, ctx);
        goto after_4;
    // 0x80801968: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8080196C: b           L_8080198C
    // 0x80801970: lw          $t5, 0x1E4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1E4);
        goto L_8080198C;
    // 0x80801970: lw          $t5, 0x1E4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1E4);
L_80801974:
    // 0x80801974: lbu         $a1, 0x1E5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1E5);
L_80801978:
    // 0x80801978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080197C: srl         $t4, $a1, 7
    ctx->r12 = S32(U32(ctx->r5) >> 7);
    // 0x80801980: jal         0x8080156C
    // 0x80801984: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    func_8080156C_gczoombox(rdram, ctx);
        goto after_5;
    // 0x80801984: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    after_5:
    // 0x80801988: lw          $t5, 0x1E4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1E4);
L_8080198C:
    // 0x8080198C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801990: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80801994: sll         $t7, $t5, 18
    ctx->r15 = S32(ctx->r13 << 18);
    // 0x80801998: bltz        $t7, L_808019C8
    if (SIGNED(ctx->r15) < 0) {
        // 0x8080199C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808019C8;
    }
    // 0x8080199C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808019A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808019A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808019A8: lhu         $t8, 0x140($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X140);
    // 0x808019AC: lb          $a2, 0x1B7($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X1B7);
    // 0x808019B0: lb          $a3, 0x1B8($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X1B8);
    // 0x808019B4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x808019B8: jal         0x808014A8
    // 0x808019BC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_808014A8_gczoombox(rdram, ctx);
        goto after_6;
    // 0x808019BC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_6:
    // 0x808019C0: b           L_80801A1C
    // 0x808019C4: lw          $v1, 0x1E4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E4);
        goto L_80801A1C;
    // 0x808019C4: lw          $v1, 0x1E4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E4);
L_808019C8:
    // 0x808019C8: lhu         $t9, 0x140($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X140);
    // 0x808019CC: lb          $a2, 0x1B7($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X1B7);
    // 0x808019D0: lb          $a3, 0x1B8($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X1B8);
    // 0x808019D4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808019D8: lwc1        $f8, 0x1C0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C0);
    // 0x808019DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808019E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019E4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808019E8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808019EC: jal         0x808014A8
    // 0x808019F0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_808014A8_gczoombox(rdram, ctx);
        goto after_7;
    // 0x808019F0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x808019F4: lhu         $t0, 0x142($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X142);
    // 0x808019F8: lb          $a2, 0x1B9($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X1B9);
    // 0x808019FC: lb          $a3, 0x1BA($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X1BA);
    // 0x80801A00: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801A04: lwc1        $f16, 0x1C0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C0);
    // 0x80801A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A0C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80801A10: jal         0x808014A8
    // 0x80801A14: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_808014A8_gczoombox(rdram, ctx);
        goto after_8;
    // 0x80801A14: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x80801A18: lw          $v1, 0x1E4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E4);
L_80801A1C:
    // 0x80801A1C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80801A20: sll         $a0, $v1, 13
    ctx->r4 = S32(ctx->r3 << 13);
    // 0x80801A24: srl         $t1, $a0, 31
    ctx->r9 = S32(U32(ctx->r4) >> 31);
    // 0x80801A28: bne         $t1, $zero, L_80801A80
    if (ctx->r9 != 0) {
        // 0x80801A2C: or          $a0, $t1, $zero
        ctx->r4 = ctx->r9 | 0;
            goto L_80801A80;
    }
    // 0x80801A2C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80801A30: lh          $v0, 0x1AC($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1AC);
    // 0x80801A34: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801A38: beq         $at, $zero, L_80801A80
    if (ctx->r1 == 0) {
        // 0x80801A3C: addiu       $t2, $v0, -0x10
        ctx->r10 = ADD32(ctx->r2, -0X10);
            goto L_80801A80;
    }
    // 0x80801A3C: addiu       $t2, $v0, -0x10
    ctx->r10 = ADD32(ctx->r2, -0X10);
    // 0x80801A40: sh          $t2, 0x1AC($s0)
    MEM_H(0X1AC, ctx->r16) = ctx->r10;
    // 0x80801A44: lh          $v0, 0x1AC($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1AC);
    // 0x80801A48: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801A4C: beql        $at, $zero, L_80801A70
    if (ctx->r1 == 0) {
        // 0x80801A50: lw          $v1, 0x1E4($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X1E4);
            goto L_80801A70;
    }
    goto skip_4;
    // 0x80801A50: lw          $v1, 0x1E4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E4);
    skip_4:
    // 0x80801A54: lw          $v1, 0x1E4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E4);
    // 0x80801A58: sh          $v0, 0x1AC($s0)
    MEM_H(0X1AC, ctx->r16) = ctx->r2;
    // 0x80801A5C: sll         $a0, $v1, 13
    ctx->r4 = S32(ctx->r3 << 13);
    // 0x80801A60: srl         $t3, $a0, 31
    ctx->r11 = S32(U32(ctx->r4) >> 31);
    // 0x80801A64: b           L_80801A80
    // 0x80801A68: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
        goto L_80801A80;
    // 0x80801A68: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80801A6C: lw          $v1, 0x1E4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E4);
L_80801A70:
    // 0x80801A70: sh          $a1, 0x1AC($s0)
    MEM_H(0X1AC, ctx->r16) = ctx->r5;
    // 0x80801A74: sll         $a0, $v1, 13
    ctx->r4 = S32(ctx->r3 << 13);
    // 0x80801A78: srl         $t4, $a0, 31
    ctx->r12 = S32(U32(ctx->r4) >> 31);
    // 0x80801A7C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
L_80801A80:
    // 0x80801A80: beq         $a0, $zero, L_80801AF8
    if (ctx->r4 == 0) {
        // 0x80801A84: lh          $v0, 0x1AC($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X1AC);
            goto L_80801AF8;
    }
    // 0x80801A84: lh          $v0, 0x1AC($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1AC);
    // 0x80801A88: sll         $a0, $v1, 26
    ctx->r4 = S32(ctx->r3 << 26);
    // 0x80801A8C: srl         $t5, $a0, 31
    ctx->r13 = S32(U32(ctx->r4) >> 31);
    // 0x80801A90: beq         $t5, $zero, L_80801AA0
    if (ctx->r13 == 0) {
        // 0x80801A94: or          $a0, $t5, $zero
        ctx->r4 = ctx->r13 | 0;
            goto L_80801AA0;
    }
    // 0x80801A94: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x80801A98: b           L_80801AA4
    // 0x80801A9C: addiu       $v1, $zero, 0xAA
    ctx->r3 = ADD32(0, 0XAA);
        goto L_80801AA4;
    // 0x80801A9C: addiu       $v1, $zero, 0xAA
    ctx->r3 = ADD32(0, 0XAA);
L_80801AA0:
    // 0x80801AA0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_80801AA4:
    // 0x80801AA4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80801AA8: beq         $at, $zero, L_80801AF8
    if (ctx->r1 == 0) {
        // 0x80801AAC: addiu       $t6, $v0, 0x10
        ctx->r14 = ADD32(ctx->r2, 0X10);
            goto L_80801AF8;
    }
    // 0x80801AAC: addiu       $t6, $v0, 0x10
    ctx->r14 = ADD32(ctx->r2, 0X10);
    // 0x80801AB0: beq         $a0, $zero, L_80801AC0
    if (ctx->r4 == 0) {
        // 0x80801AB4: sh          $t6, 0x1AC($s0)
        MEM_H(0X1AC, ctx->r16) = ctx->r14;
            goto L_80801AC0;
    }
    // 0x80801AB4: sh          $t6, 0x1AC($s0)
    MEM_H(0X1AC, ctx->r16) = ctx->r14;
    // 0x80801AB8: b           L_80801AC4
    // 0x80801ABC: addiu       $v1, $zero, 0xAA
    ctx->r3 = ADD32(0, 0XAA);
        goto L_80801AC4;
    // 0x80801ABC: addiu       $v1, $zero, 0xAA
    ctx->r3 = ADD32(0, 0XAA);
L_80801AC0:
    // 0x80801AC0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_80801AC4:
    // 0x80801AC4: lh          $v0, 0x1AC($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1AC);
    // 0x80801AC8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80801ACC: beq         $at, $zero, L_80801AE0
    if (ctx->r1 == 0) {
        // 0x80801AD0: nop
    
            goto L_80801AE0;
    }
    // 0x80801AD0: nop

    // 0x80801AD4: sh          $v0, 0x1AC($s0)
    MEM_H(0X1AC, ctx->r16) = ctx->r2;
    // 0x80801AD8: b           L_80801AF8
    // 0x80801ADC: lh          $v0, 0x1AC($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1AC);
        goto L_80801AF8;
    // 0x80801ADC: lh          $v0, 0x1AC($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1AC);
L_80801AE0:
    // 0x80801AE0: beq         $a0, $zero, L_80801AF0
    if (ctx->r4 == 0) {
        // 0x80801AE4: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_80801AF0;
    }
    // 0x80801AE4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80801AE8: b           L_80801AF0
    // 0x80801AEC: addiu       $v1, $zero, 0xAA
    ctx->r3 = ADD32(0, 0XAA);
        goto L_80801AF0;
    // 0x80801AEC: addiu       $v1, $zero, 0xAA
    ctx->r3 = ADD32(0, 0XAA);
L_80801AF0:
    // 0x80801AF0: sh          $v1, 0x1AC($s0)
    MEM_H(0X1AC, ctx->r16) = ctx->r3;
    // 0x80801AF4: lh          $v0, 0x1AC($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1AC);
L_80801AF8:
    // 0x80801AF8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80801AFC: bnel        $v0, $at, L_80801B20
    if (ctx->r2 != ctx->r1) {
        // 0x80801B00: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801B20;
    }
    goto skip_5;
    // 0x80801B00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80801B04: lw          $t7, 0x1E4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E4);
    // 0x80801B08: addiu       $t0, $zero, 0xAA
    ctx->r8 = ADD32(0, 0XAA);
    // 0x80801B0C: sll         $t9, $t7, 26
    ctx->r25 = S32(ctx->r15 << 26);
    // 0x80801B10: bgezl       $t9, L_80801B20
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80801B14: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801B20;
    }
    goto skip_6;
    // 0x80801B14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x80801B18: sh          $t0, 0x1AC($s0)
    MEM_H(0X1AC, ctx->r16) = ctx->r8;
L_80801B1C:
    // 0x80801B1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801B20:
    // 0x80801B20: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801B24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801B28: jr          $ra
    // 0x80801B2C: nop

    return;
    // 0x80801B2C: nop

;}
