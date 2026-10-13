#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800D4564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D4568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D456C: jal         0x800AAD28
    // 0x800D4570: nop

    func_800AAD28(rdram, ctx);
        goto after_0;
    // 0x800D4570: nop

    after_0:
    // 0x800D4574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D4578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D457C: jr          $ra
    // 0x800D4580: nop

    return;
    // 0x800D4580: nop

;}
RECOMP_FUNC void func_800BF8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF8BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BF8C0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800BF8C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF8C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BF8CC: jal         0x80088128
    // 0x800BF8D0: addiu       $a0, $a0, -0x7A50
    ctx->r4 = ADD32(ctx->r4, -0X7A50);
    _gcmapDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x800BF8D0: addiu       $a0, $a0, -0x7A50
    ctx->r4 = ADD32(ctx->r4, -0X7A50);
    after_0:
    // 0x800BF8D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BF8D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BF8DC: jr          $ra
    // 0x800BF8E0: nop

    return;
    // 0x800BF8E0: nop

;}
RECOMP_FUNC void func_80800000_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x80800004: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x80800008: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x8080000C: jr          $ra
    // 0x80800010: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    return;
    // 0x80800010: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
;}
RECOMP_FUNC void _bsfirstp_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800842F0: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x800842F0);
    return;
    // 0x800842F4: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_800D4FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4FB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D4FBC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800D4FC0: bne         $a0, $at, L_800D4FCC
    if (ctx->r4 != ctx->r1) {
        // 0x800D4FC4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800D4FCC;
    }
    // 0x800D4FC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D4FC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800D4FCC:
    // 0x800D4FCC: jal         0x800D4DD0
    // 0x800D4FD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D4DD0(rdram, ctx);
        goto after_0;
    // 0x800D4FD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D4FD4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4FD8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800D4FDC: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800D4FE0: bgez        $a1, L_800D5004
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800D4FE4: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800D5004;
    }
    // 0x800D4FE4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800D4FE8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800D4FEC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D4FF0: addiu       $t7, $t7, -0x49C0
    ctx->r15 = ADD32(ctx->r15, -0X49C0);
    // 0x800D4FF4: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800D4FF8: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800D4FFC: b           L_800D5020
    // 0x800D5000: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_800D5020;
    // 0x800D5000: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800D5004:
    // 0x800D5004: addiu       $t9, $t9, -0x49C0
    ctx->r25 = ADD32(ctx->r25, -0X49C0);
    // 0x800D5008: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800D500C: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x800D5010: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800D5014: beql        $at, $zero, L_800D5024
    if (ctx->r1 == 0) {
        // 0x800D5018: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D5024;
    }
    goto skip_0;
    // 0x800D5018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D501C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_800D5020:
    // 0x800D5020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D5024:
    // 0x800D5024: sb          $a1, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r5;
    // 0x800D5028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D502C: jr          $ra
    // 0x800D5030: nop

    return;
    // 0x800D5030: nop

;}
RECOMP_FUNC void _subaddiemulti_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A0B0: syscall     826
    recomp_syscall_handler(rdram, ctx, 0x8008A0B0);
    return;
    // 0x8008A0B4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800398_chloggo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800398: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080039C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003A4: jal         0x800F54E4
    // 0x808003A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808003A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808003AC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808003B0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808003B4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x808003B8: jal         0x800EE7F8
    // 0x808003BC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808003BC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x808003C0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808003C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003C8: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808003CC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808003D0: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x808003D4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808003D8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808003DC: jal         0x800EF1B8
    // 0x808003E0: nop

    func_800EF1B8(rdram, ctx);
        goto after_2;
    // 0x808003E0: nop

    after_2:
    // 0x808003E4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808003E8: jal         0x800F77E8
    // 0x808003EC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F77E8(rdram, ctx);
        goto after_3;
    // 0x808003EC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x808003F0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808003F4: jal         0x800F64A4
    // 0x808003F8: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    func_800F64A4(rdram, ctx);
        goto after_4;
    // 0x808003F8: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    after_4:
    // 0x808003FC: beq         $v0, $zero, L_8080040C
    if (ctx->r2 == 0) {
        // 0x80800400: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_8080040C;
    }
    // 0x80800400: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800404: b           L_80800410
    // 0x80800408: addiu       $a1, $zero, 0x1343
    ctx->r5 = ADD32(0, 0X1343);
        goto L_80800410;
    // 0x80800408: addiu       $a1, $zero, 0x1343
    ctx->r5 = ADD32(0, 0X1343);
L_8080040C:
    // 0x8080040C: addiu       $a1, $zero, 0x1380
    ctx->r5 = ADD32(0, 0X1380);
L_80800410:
    // 0x80800410: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800414: addiu       $t6, $zero, 0xAD
    ctx->r14 = ADD32(0, 0XAD);
    // 0x80800418: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080041C: jal         0x8008A208
    // 0x80800420: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800420: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800428: jal         0x80102424
    // 0x8080042C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x8080042C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800430: jal         0x8010A570
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_7;
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800438: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080043C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800440: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800444: jal         0x80085708
    // 0x80800448: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    _capod_entrypoint_13(rdram, ctx);
        goto after_8;
    // 0x80800448: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_8:
    // 0x8080044C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800450: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800454: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800458: jr          $ra
    // 0x8080045C: nop

    return;
    // 0x8080045C: nop

;}
RECOMP_FUNC void func_80803B68_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803B68: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80803B6C: jr          $ra
    // 0x80803B70: lwc1        $f0, 0x110($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X110);
    return;
    // 0x80803B70: lwc1        $f0, 0x110($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X110);
;}
RECOMP_FUNC void func_808002B8_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808002C4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808002C8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808002CC: jal         0x8008CABC
    // 0x808002D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808002D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808002D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808002D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808002DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002E0: beq         $a1, $zero, L_80800310
    if (ctx->r5 == 0) {
        // 0x808002E4: sw          $a1, 0x15C($s1)
        MEM_W(0X15C, ctx->r17) = ctx->r5;
            goto L_80800310;
    }
    // 0x808002E4: sw          $a1, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->r5;
    // 0x808002E8: beq         $a1, $at, L_80800320
    if (ctx->r5 == ctx->r1) {
        // 0x808002EC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800320;
    }
    // 0x808002EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002F4: beq         $a1, $at, L_808003AC
    if (ctx->r5 == ctx->r1) {
        // 0x808002F8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808003AC;
    }
    // 0x808002F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800300: beq         $a1, $at, L_808003EC
    if (ctx->r5 == ctx->r1) {
        // 0x80800304: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808003EC;
    }
    // 0x80800304: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800308: b           L_80800418
    // 0x8080030C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800418;
    // 0x8080030C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800310:
    // 0x80800310: jal         0x80085230
    // 0x80800314: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _basudie_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800314: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800318: b           L_80800418
    // 0x8080031C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800418;
    // 0x8080031C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800320:
    // 0x80800320: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800324: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800328: lui         $a2, 0x4402
    ctx->r6 = S32(0X4402 << 16);
    // 0x8080032C: lui         $a3, 0xC496
    ctx->r7 = S32(0XC496 << 16);
    // 0x80800330: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800334: jal         0x80085210
    // 0x80800338: swc1        $f0, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f0.u32l;
    _basudie_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800338: swc1        $f0, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f0.u32l;
    after_2:
    // 0x8080033C: jal         0x8008AF24
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_3;
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800348: jal         0x8008B1A0
    // 0x8080034C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_4;
    // 0x8080034C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800354: jal         0x8008AED4
    // 0x80800358: addiu       $a1, $zero, 0xB8
    ctx->r5 = ADD32(0, 0XB8);
    anctrl_setIndex(rdram, ctx);
        goto after_5;
    // 0x80800358: addiu       $a1, $zero, 0xB8
    ctx->r5 = ADD32(0, 0XB8);
    after_5:
    // 0x8080035C: lui         $a2, 0x3EDF
    ctx->r6 = S32(0X3EDF << 16);
    // 0x80800360: ori         $a2, $a2, 0x2E49
    ctx->r6 = ctx->r6 | 0X2E49;
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800368: jal         0x8008B1D4
    // 0x8080036C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_6;
    // 0x8080036C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80800370: lui         $a1, 0x3FF3
    ctx->r5 = S32(0X3FF3 << 16);
    // 0x80800374: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800378: jal         0x8008B1BC
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_7;
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800384: jal         0x8008B134
    // 0x80800388: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x80800388: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8080038C: jal         0x8008B064
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800394: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800398: addiu       $a1, $zero, 0x50E
    ctx->r5 = ADD32(0, 0X50E);
    // 0x8080039C: jal         0x8009DE38
    // 0x808003A0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_10;
    // 0x808003A0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_10:
    // 0x808003A4: b           L_80800418
    // 0x808003A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800418;
    // 0x808003A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003AC:
    // 0x808003AC: lui         $a1, 0x3F4F
    ctx->r5 = S32(0X3F4F << 16);
    // 0x808003B0: jal         0x8008CED4
    // 0x808003B4: ori         $a1, $a1, 0xDF3B
    ctx->r5 = ctx->r5 | 0XDF3B;
    baanim_setEnd(rdram, ctx);
        goto after_11;
    // 0x808003B4: ori         $a1, $a1, 0xDF3B
    ctx->r5 = ctx->r5 | 0XDF3B;
    after_11:
    // 0x808003B8: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808003BC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808003C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003C4: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x808003C8: jal         0x8009DF94
    // 0x808003CC: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF94(rdram, ctx);
        goto after_12;
    // 0x808003CC: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_12:
    // 0x808003D0: jal         0x80800040
    // 0x808003D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800040_bsmum(rdram, ctx);
        goto after_13;
    // 0x808003D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x808003D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003DC: jal         0x8009BA58
    // 0x808003E0: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_14;
    // 0x808003E0: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_14:
    // 0x808003E4: b           L_80800418
    // 0x808003E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800418;
    // 0x808003E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003EC:
    // 0x808003EC: jal         0x8008CED4
    // 0x808003F0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEnd(rdram, ctx);
        goto after_15;
    // 0x808003F0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_15:
    // 0x808003F4: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808003F8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808003FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800400: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x80800404: jal         0x8009DF94
    // 0x80800408: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF94(rdram, ctx);
        goto after_16;
    // 0x80800408: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_16:
    // 0x8080040C: jal         0x80800040
    // 0x80800410: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800040_bsmum(rdram, ctx);
        goto after_17;
    // 0x80800410: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80800414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800418:
    // 0x80800418: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080041C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800420: jr          $ra
    // 0x80800424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80801398_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080139C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808013A4: jal         0x80100094
    // 0x808013A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808013A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808013AC: jal         0x8008A040
    // 0x808013B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808013B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808013B4: beql        $v0, $zero, L_808013D0
    if (ctx->r2 == 0) {
        // 0x808013B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808013D0;
    }
    goto skip_0;
    // 0x808013B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808013BC: jal         0x80801458
    // 0x808013C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80801458_chevilspirit(rdram, ctx);
        goto after_2;
    // 0x808013C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808013C4: jal         0x808013DC
    // 0x808013C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808013DC_chevilspirit(rdram, ctx);
        goto after_3;
    // 0x808013C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808013CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808013D0:
    // 0x808013D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808013D4: jr          $ra
    // 0x808013D8: nop

    return;
    // 0x808013D8: nop

;}
RECOMP_FUNC void __baroll_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C2D8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009C2DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009C2E0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8009C2E4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8009C2E8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8009C2EC: jal         0x800D8FF8
    // 0x8009C2F0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8009C2F0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x8009C2F4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8009C2F8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8009C2FC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009C300: lw          $v0, 0xF4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0XF4);
    // 0x8009C304: mul.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8009C308: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8009C30C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8009C310: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8009C314: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8009C318: jal         0x800F2100
    // 0x8009C31C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x8009C31C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x8009C320: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8009C324: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009C328: lui         $a2, 0xBDCC
    ctx->r6 = S32(0XBDCC << 16);
    // 0x8009C32C: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8009C330: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8009C334: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8009C338: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8009C33C: bc1f        L_8009C378
    if (!c1cs) {
        // 0x8009C340: nop
    
            goto L_8009C378;
    }
    // 0x8009C340: nop

    // 0x8009C344: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8009C348: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x8009C34C: c.lt.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl < ctx->f18.fl;
    // 0x8009C350: nop

    // 0x8009C354: bc1fl       L_8009C370
    if (!c1cs) {
        // 0x8009C358: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8009C370;
    }
    goto skip_0;
    // 0x8009C358: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x8009C35C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8009C360: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009C364: b           L_8009C378
    // 0x8009C368: add.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f2.fl;
        goto L_8009C378;
    // 0x8009C368: add.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f2.fl;
    // 0x8009C36C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8009C370:
    // 0x8009C370: nop

    // 0x8009C374: add.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f2.fl;
L_8009C378:
    // 0x8009C378: mul.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8009C37C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8009C380: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8009C384: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C388: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009C38C: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x8009C390: nop

    // 0x8009C394: bc1fl       L_8009C3B0
    if (!c1cs) {
        // 0x8009C398: mfc1        $a2, $f16
        ctx->r6 = (int32_t)ctx->f16.u32l;
            goto L_8009C3B0;
    }
    goto skip_1;
    // 0x8009C398: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x8009C39C: jal         0x800F0D50
    // 0x8009C3A0: neg.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = -ctx->f16.fl;
    func_800F0D50(rdram, ctx);
        goto after_2;
    // 0x8009C3A0: neg.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = -ctx->f16.fl;
    after_2:
    // 0x8009C3A4: b           L_8009C3BC
    // 0x8009C3A8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_8009C3BC;
    // 0x8009C3A8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8009C3AC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
L_8009C3B0:
    // 0x8009C3B0: jal         0x800F0D50
    // 0x8009C3B4: lwc1        $f14, 0x5340($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X5340);
    func_800F0D50(rdram, ctx);
        goto after_3;
    // 0x8009C3B4: lwc1        $f14, 0x5340($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X5340);
    after_3:
    // 0x8009C3B8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_8009C3BC:
    // 0x8009C3BC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x8009C3C0: jal         0x800F2100
    // 0x8009C3C4: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x8009C3C4: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    after_4:
    // 0x8009C3C8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8009C3CC: jal         0x800F2100
    // 0x8009C3D0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    mlAbsF(rdram, ctx);
        goto after_5;
    // 0x8009C3D0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8009C3D4: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8009C3D8: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8009C3DC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8009C3E0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8009C3E4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8009C3E8: bc1fl       L_8009C408
    if (!c1cs) {
        // 0x8009C3EC: lw          $v0, 0xF4($t8)
        ctx->r2 = MEM_W(ctx->r24, 0XF4);
            goto L_8009C408;
    }
    goto skip_2;
    // 0x8009C3EC: lw          $v0, 0xF4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0XF4);
    skip_2:
    // 0x8009C3F0: lw          $v0, 0xF4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0XF4);
    // 0x8009C3F4: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8009C3F8: add.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x8009C3FC: b           L_8009C410
    // 0x8009C400: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
        goto L_8009C410;
    // 0x8009C400: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8009C404: lw          $v0, 0xF4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0XF4);
L_8009C408:
    // 0x8009C408: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8009C40C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_8009C410:
    // 0x8009C410: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8009C414: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8009C418: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009C41C: lw          $v0, 0xF4($t9)
    ctx->r2 = MEM_W(ctx->r25, 0XF4);
    // 0x8009C420: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8009C424: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8009C428: nop

    // 0x8009C42C: bc1fl       L_8009C45C
    if (!c1cs) {
        // 0x8009C430: sub.s       $f18, $f0, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8009C45C;
    }
    goto skip_3;
    // 0x8009C430: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    skip_3:
    // 0x8009C434: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8009C438: nop

    // 0x8009C43C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8009C440: nop

    // 0x8009C444: bc1fl       L_8009C464
    if (!c1cs) {
        // 0x8009C448: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009C464;
    }
    goto skip_4;
    // 0x8009C448: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8009C44C: add.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8009C450: b           L_8009C460
    // 0x8009C454: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
        goto L_8009C460;
    // 0x8009C454: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8009C458: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
L_8009C45C:
    // 0x8009C45C: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_8009C460:
    // 0x8009C460: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009C464:
    // 0x8009C464: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8009C468: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8009C46C: jr          $ra
    // 0x8009C470: nop

    return;
    // 0x8009C470: nop

;}
RECOMP_FUNC void chpotogoldbits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800804: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2344, 0X988) << 16);
    // 0x80800808: jr          $ra
    // 0x8080080C: addiu       $v0, $v0, 0x988
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2344, 0X988));
    return;
    // 0x8080080C: addiu       $v0, $v0, 0x988
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2344, 0X988));
;}
RECOMP_FUNC void func_80800884_chfirefx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800884: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80800888: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8080088C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80800890: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800894: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80800898: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8080089C: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x808008A0: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x808008A4: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x808008A8: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x808008AC: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x808008B0: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x808008B4: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808008B8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808008BC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808008C0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808008C4: jal         0x80100094
    // 0x808008C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008CC: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x808008D0: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x808008D4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808008D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808008DC: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x808008E0: bnel        $at, $zero, L_808008F4
    if (ctx->r1 != 0) {
        // 0x808008E4: lh          $t8, 0xE($v0)
        ctx->r24 = MEM_H(ctx->r2, 0XE);
            goto L_808008F4;
    }
    goto skip_0;
    // 0x808008E4: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    skip_0:
    // 0x808008E8: b           L_80800A68
    // 0x808008EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A68;
    // 0x808008EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808008F0: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
L_808008F4:
    // 0x808008F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008F8: addiu       $s6, $sp, 0x8C
    ctx->r22 = ADD32(ctx->r29, 0X8C);
    // 0x808008FC: bne         $t8, $at, L_80800930
    if (ctx->r24 != ctx->r1) {
        // 0x80800900: nop
    
            goto L_80800930;
    }
    // 0x80800900: nop

    // 0x80800904: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800908: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080090C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1104, 0X11DC) << 16);
    // 0x80800910: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800914: nop

    // 0x80800918: bc1t        L_80800928
    if (c1cs) {
        // 0x8080091C: nop
    
            goto L_80800928;
    }
    // 0x8080091C: nop

    // 0x80800920: b           L_80800A68
    // 0x80800924: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A68;
    // 0x80800924: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800928:
    // 0x80800928: lwc1        $f8, 0x11DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1104, 0X11DC));
    // 0x8080092C: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80800930:
    // 0x80800930: jal         0x800E3980
    // 0x80800934: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800E3980(rdram, ctx);
        goto after_1;
    // 0x80800934: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x80800938: lh          $v0, 0x8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X8);
    // 0x8080093C: lh          $t9, 0xA($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XA);
    // 0x80800940: addiu       $s4, $s0, 0x4
    ctx->r20 = ADD32(ctx->r16, 0X4);
    // 0x80800944: addiu       $s5, $zero, 0x14
    ctx->r21 = ADD32(0, 0X14);
    // 0x80800948: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8080094C: beq         $at, $zero, L_80800A64
    if (ctx->r1 == 0) {
        // 0x80800950: addiu       $s3, $sp, 0x80
        ctx->r19 = ADD32(ctx->r29, 0X80);
            goto L_80800A64;
    }
    // 0x80800950: addiu       $s3, $sp, 0x80
    ctx->r19 = ADD32(ctx->r29, 0X80);
    // 0x80800954: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80800958: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8080095C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800960: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800964: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1104, 0X11E0) << 16);
    // 0x80800968: lwc1        $f26, 0x11E0($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1104, 0X11E0));
    // 0x8080096C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1104, 0X11E4) << 16);
    // 0x80800970: lwc1        $f24, 0x11E4($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1104, 0X11E4));
L_80800974:
    // 0x80800974: multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800978: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8080097C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80800980: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80800984: mflo        $t0
    ctx->r8 = lo;
    // 0x80800988: addu        $s0, $s1, $t0
    ctx->r16 = ADD32(ctx->r17, ctx->r8);
    // 0x8080098C: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x80800990: jal         0x800DC128
    // 0x80800994: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x80800994: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x80800998: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8080099C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x808009A0: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x808009A4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808009A8: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    // 0x808009AC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808009B0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808009B4: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x808009B8: jal         0x800DC178
    // 0x808009BC: sh          $t2, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r10;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x808009BC: sh          $t2, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r10;
    after_3:
    // 0x808009C0: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x808009C4: jal         0x800DC298
    // 0x808009C8: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    func_800DC298(rdram, ctx);
        goto after_4;
    // 0x808009C8: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    after_4:
    // 0x808009CC: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x808009D0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808009D4: jal         0x800F1DF4
    // 0x808009D8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_5;
    // 0x808009D8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_5:
    // 0x808009DC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808009E0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808009E4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808009E8: jal         0x800DC178
    // 0x808009EC: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x808009EC: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    after_6:
    // 0x808009F0: lh          $t3, 0x12($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X12);
    // 0x808009F4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808009F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808009FC: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80800A00: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80800A04: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800A08: mul.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80800A0C: jal         0x800DC178
    // 0x80800A10: nop

    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80800A10: nop

    after_7:
    // 0x80800A14: add.s       $f18, $f22, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f22.fl + ctx->f20.fl;
    // 0x80800A18: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800A1C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800A20: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800A24: jal         0x800EEB9C
    // 0x80800A28: nop

    func_800EEB9C(rdram, ctx);
        goto after_8;
    // 0x80800A28: nop

    after_8:
    // 0x80800A2C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80800A30: jal         0x800EE940
    // 0x80800A34: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EE940(rdram, ctx);
        goto after_9;
    // 0x80800A34: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_9:
    // 0x80800A38: lh          $t4, 0x8($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X8);
    // 0x80800A3C: lh          $t6, 0xA($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XA);
    // 0x80800A40: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800A44: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80800A48: sh          $t5, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r13;
    // 0x80800A4C: lh          $v0, 0x8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X8);
    // 0x80800A50: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80800A54: beq         $at, $zero, L_80800A64
    if (ctx->r1 == 0) {
        // 0x80800A58: slti        $at, $s2, 0x2
        ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
            goto L_80800A64;
    }
    // 0x80800A58: slti        $at, $s2, 0x2
    ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x80800A5C: bne         $at, $zero, L_80800974
    if (ctx->r1 != 0) {
        // 0x80800A60: nop
    
            goto L_80800974;
    }
    // 0x80800A60: nop

L_80800A64:
    // 0x80800A64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A68:
    // 0x80800A68: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80800A6C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800A70: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800A74: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800A78: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800A7C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80800A80: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80800A84: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80800A88: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80800A8C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80800A90: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80800A94: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80800A98: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80800A9C: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80800AA0: jr          $ra
    // 0x80800AA4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80800AA4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_8001B798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B798: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8001B79C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001B7A0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8001B7A4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001B7A8: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8001B7AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001B7B0: jr          $ra
    // 0x8001B7B4: lw          $v0, -0x40F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X40F0);
    return;
    // 0x8001B7B4: lw          $v0, -0x40F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X40F0);
;}
RECOMP_FUNC void ncbaspline_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _glintrosyncDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800885F0: syscall     695
    recomp_syscall_handler(rdram, ctx, 0x800885F0);
    return;
    // 0x800885F4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80803218_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803218: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080321C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803220: lw          $t6, 0x7C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X7C);
    // 0x80803224: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80803228: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8080322C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80803230: beq         $t7, $zero, L_8080324C
    if (ctx->r15 == 0) {
        // 0x80803234: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8080324C;
    }
    // 0x80803234: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803238: jal         0x80105AE8
    // 0x8080323C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80105AE8(rdram, ctx);
        goto after_0;
    // 0x8080323C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80803240: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80803244: b           L_80803254
    // 0x80803248: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80803254;
    // 0x80803248: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_8080324C:
    // 0x8080324C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80803250: nop

L_80803254:
    // 0x80803254: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80803258: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080325C: jal         0x80105AE8
    // 0x80803260: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80105AE8(rdram, ctx);
        goto after_1;
    // 0x80803260: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80803264: jal         0x800D8FF8
    // 0x80803268: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80803268: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8080326C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4580) << 16);
    // 0x80803270: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80803274: lwc1        $f4, 0x4580($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4580));
    // 0x80803278: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8080327C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80803280: sub.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x80803284: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x80803288: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080328C: c.le.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl <= ctx->f6.fl;
    // 0x80803290: sll         $t8, $v0, 12
    ctx->r24 = S32(ctx->r2 << 12);
    // 0x80803294: srl         $v0, $t8, 31
    ctx->r2 = S32(U32(ctx->r24) >> 31);
    // 0x80803298: bc1f        L_808032B0
    if (!c1cs) {
        // 0x8080329C: nop
    
            goto L_808032B0;
    }
    // 0x8080329C: nop

    // 0x808032A0: jal         0x808031D0
    // 0x808032A4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_3;
    // 0x808032A4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_3:
    // 0x808032A8: b           L_8080343C
    // 0x808032AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080343C;
    // 0x808032AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808032B0:
    // 0x808032B0: beq         $v0, $zero, L_808032C4
    if (ctx->r2 == 0) {
        // 0x808032B4: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1632, 0X4588) << 16);
            goto L_808032C4;
    }
    // 0x808032B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4588) << 16);
    // 0x808032B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4584) << 16);
    // 0x808032BC: b           L_808032C8
    // 0x808032C0: lwc1        $f2, 0x4584($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4584));
        goto L_808032C8;
    // 0x808032C0: lwc1        $f2, 0x4584($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4584));
L_808032C4:
    // 0x808032C4: lwc1        $f2, 0x4588($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4588));
L_808032C8:
    // 0x808032C8: sub.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x808032CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X458C) << 16);
    // 0x808032D0: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x808032D4: nop

    // 0x808032D8: bc1f        L_80803350
    if (!c1cs) {
        // 0x808032DC: nop
    
            goto L_80803350;
    }
    // 0x808032DC: nop

    // 0x808032E0: beq         $v0, $zero, L_808032F8
    if (ctx->r2 == 0) {
        // 0x808032E4: lui         $at, 0x4296
        ctx->r1 = S32(0X4296 << 16);
            goto L_808032F8;
    }
    // 0x808032E4: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x808032E8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808032EC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808032F0: b           L_80803304
    // 0x808032F4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
        goto L_80803304;
    // 0x808032F4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_808032F8:
    // 0x808032F8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808032FC: nop

    // 0x80803300: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_80803304:
    // 0x80803304: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80803308: lwc1        $f12, 0x24($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X24);
    // 0x8080330C: sub.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80803310: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x80803314: nop

    // 0x80803318: bc1fl       L_8080343C
    if (!c1cs) {
        // 0x8080331C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080343C;
    }
    goto skip_0;
    // 0x8080331C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80803320: beq         $v0, $zero, L_80803338
    if (ctx->r2 == 0) {
        // 0x80803324: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_80803338;
    }
    // 0x80803324: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80803328: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080332C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80803330: b           L_80803340
    // 0x80803334: nop

        goto L_80803340;
    // 0x80803334: nop

L_80803338:
    // 0x80803338: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080333C: nop

L_80803340:
    // 0x80803340: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80803344: sub.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80803348: b           L_80803438
    // 0x8080334C: swc1        $f4, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f4.u32l;
        goto L_80803438;
    // 0x8080334C: swc1        $f4, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f4.u32l;
L_80803350:
    // 0x80803350: lwc1        $f6, 0x458C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X458C));
    // 0x80803354: add.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x80803358: c.le.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl <= ctx->f12.fl;
    // 0x8080335C: nop

    // 0x80803360: bc1f        L_808033D8
    if (!c1cs) {
        // 0x80803364: nop
    
            goto L_808033D8;
    }
    // 0x80803364: nop

    // 0x80803368: beq         $v0, $zero, L_80803380
    if (ctx->r2 == 0) {
        // 0x8080336C: lui         $at, 0x4296
        ctx->r1 = S32(0X4296 << 16);
            goto L_80803380;
    }
    // 0x8080336C: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80803370: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80803374: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80803378: b           L_8080338C
    // 0x8080337C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
        goto L_8080338C;
    // 0x8080337C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_80803380:
    // 0x80803380: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80803384: nop

    // 0x80803388: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_8080338C:
    // 0x8080338C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80803390: lwc1        $f12, 0x24($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X24);
    // 0x80803394: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80803398: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8080339C: nop

    // 0x808033A0: bc1fl       L_8080343C
    if (!c1cs) {
        // 0x808033A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080343C;
    }
    goto skip_1;
    // 0x808033A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808033A8: beq         $v0, $zero, L_808033C0
    if (ctx->r2 == 0) {
        // 0x808033AC: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_808033C0;
    }
    // 0x808033AC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808033B0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808033B4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808033B8: b           L_808033C8
    // 0x808033BC: nop

        goto L_808033C8;
    // 0x808033BC: nop

L_808033C0:
    // 0x808033C0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808033C4: nop

L_808033C8:
    // 0x808033C8: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x808033CC: add.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f18.fl;
    // 0x808033D0: b           L_80803438
    // 0x808033D4: swc1        $f4, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f4.u32l;
        goto L_80803438;
    // 0x808033D4: swc1        $f4, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f4.u32l;
L_808033D8:
    // 0x808033D8: beq         $v0, $zero, L_808033F0
    if (ctx->r2 == 0) {
        // 0x808033DC: lui         $at, 0x4296
        ctx->r1 = S32(0X4296 << 16);
            goto L_808033F0;
    }
    // 0x808033DC: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x808033E0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808033E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808033E8: b           L_808033FC
    // 0x808033EC: lwc1        $f12, 0x24($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X24);
        goto L_808033FC;
    // 0x808033EC: lwc1        $f12, 0x24($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X24);
L_808033F0:
    // 0x808033F0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808033F4: nop

    // 0x808033F8: lwc1        $f12, 0x24($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X24);
L_808033FC:
    // 0x808033FC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80803400: nop

    // 0x80803404: bc1fl       L_8080343C
    if (!c1cs) {
        // 0x80803408: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080343C;
    }
    goto skip_2;
    // 0x80803408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8080340C: beq         $v0, $zero, L_80803424
    if (ctx->r2 == 0) {
        // 0x80803410: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_80803424;
    }
    // 0x80803410: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80803414: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80803418: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080341C: b           L_8080342C
    // 0x80803420: nop

        goto L_8080342C;
    // 0x80803420: nop

L_80803424:
    // 0x80803424: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80803428: nop

L_8080342C:
    // 0x8080342C: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80803430: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80803434: swc1        $f8, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f8.u32l;
L_80803438:
    // 0x80803438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080343C:
    // 0x8080343C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803440: jr          $ra
    // 0x80803444: nop

    return;
    // 0x80803444: nop

;}
RECOMP_FUNC void func_80800000_chjinjovillagecamera1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: addiu       $at, $zero, 0x1522
    ctx->r1 = ADD32(0, 0X1522);
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800010: beq         $a1, $at, L_80800040
    if (ctx->r5 == ctx->r1) {
        // 0x80800014: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800040;
    }
    // 0x80800014: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800018: addiu       $at, $zero, 0x1523
    ctx->r1 = ADD32(0, 0X1523);
    // 0x8080001C: beq         $a1, $at, L_80800050
    if (ctx->r5 == ctx->r1) {
        // 0x80800020: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800050;
    }
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: addiu       $at, $zero, 0x1524
    ctx->r1 = ADD32(0, 0X1524);
    // 0x80800028: beq         $a1, $at, L_80800050
    if (ctx->r5 == ctx->r1) {
        // 0x8080002C: addiu       $at, $zero, 0x1565
        ctx->r1 = ADD32(0, 0X1565);
            goto L_80800050;
    }
    // 0x8080002C: addiu       $at, $zero, 0x1565
    ctx->r1 = ADD32(0, 0X1565);
    // 0x80800030: beq         $a1, $at, L_80800050
    if (ctx->r5 == ctx->r1) {
        // 0x80800034: nop
    
            goto L_80800050;
    }
    // 0x80800034: nop

    // 0x80800038: b           L_8080006C
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080006C;
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800040:
    // 0x80800040: jal         0x80088830
    // 0x80800044: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_0;
    // 0x80800044: nop

    after_0:
    // 0x80800048: b           L_8080006C
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080006C;
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800050:
    // 0x80800050: jal         0x80101FDC
    // 0x80800054: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800054: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800058: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8080005C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800060: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800064: swc1        $f4, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f4.u32l;
    // 0x80800068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080006C:
    // 0x8080006C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082DB8: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082DB8);
    return;
    // 0x80082DBC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void chhumba_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802228: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1688, 0X2738) << 16);
    // 0x8080222C: jr          $ra
    // 0x80802230: addiu       $v0, $v0, 0x2738
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1688, 0X2738));
    return;
    // 0x80802230: addiu       $v0, $v0, 0x2738
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1688, 0X2738));
;}
RECOMP_FUNC void _bskazjump_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083430: syscall     62
    recomp_syscall_handler(rdram, ctx, 0x80083430);
    return;
    // 0x80083434: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800BE3F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE3F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BE3FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BE400: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800BE404: jal         0x800EE904
    // 0x800BE408: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EE904(rdram, ctx);
        goto after_0;
    // 0x800BE408: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800BE40C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BE410: addiu       $a0, $a0, -0x7B38
    ctx->r4 = ADD32(ctx->r4, -0X7B38);
    // 0x800BE414: jal         0x800BE09C
    // 0x800BE418: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800BE09C(rdram, ctx);
        goto after_1;
    // 0x800BE418: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x800BE41C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BE420: addiu       $v1, $v1, -0x7B38
    ctx->r3 = ADD32(ctx->r3, -0X7B38);
    // 0x800BE424: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800BE428: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800BE42C: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x800BE430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BE434: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BE438: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800BE43C: jr          $ra
    // 0x800BE440: nop

    return;
    // 0x800BE440: nop

;}
RECOMP_FUNC void func_800D7908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7908: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D790C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D7910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D7914: addiu       $a2, $a3, 0x4
    ctx->r6 = ADD32(ctx->r7, 0X4);
    // 0x800D7918: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800D791C: jal         0x800A516C
    // 0x800D7920: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800A516C(rdram, ctx);
        goto after_0;
    // 0x800D7920: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800D7924: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800D7928: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800D792C: swc1        $f4, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->f4.u32l;
    // 0x800D7930: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800D7934: swc1        $f6, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f6.u32l;
    // 0x800D7938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D793C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D7940: jr          $ra
    // 0x800D7944: nop

    return;
    // 0x800D7944: nop

;}
RECOMP_FUNC void chlagoonufoint_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(748, 0X1948) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1948
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X1948));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1948
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X1948));
;}
RECOMP_FUNC void bsbkflamethrower_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800250: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800258: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    // 0x8080025C: jal         0x80800094
    // 0x80800260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800094_bsbkflamethrower(rdram, ctx);
        goto after_0;
    // 0x80800260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080026C: jr          $ra
    // 0x80800270: nop

    return;
    // 0x80800270: nop

;}
RECOMP_FUNC void func_800CB698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB698: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800CB69C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800CB6A0: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800CB6A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CB6A8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800CB6AC: jr          $ra
    // 0x800CB6B0: sb          $a1, -0x548F($at)
    MEM_B(-0X548F, ctx->r1) = ctx->r5;
    return;
    // 0x800CB6B0: sb          $a1, -0x548F($at)
    MEM_B(-0X548F, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void func_800EFD24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFD24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EFD28: nop

    // 0x800EFD2C: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x800EFD30: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x800EFD34: jr          $ra
    // 0x800EFD38: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x800EFD38: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_808003B4_cheggclockwork(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003BC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808003C0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x808003C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003CC: jal         0x80100094
    // 0x808003D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808003D4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x808003D8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808003DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003E0: beq         $a3, $at, L_8080040C
    if (ctx->r7 == ctx->r1) {
        // 0x808003E4: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_8080040C;
    }
    // 0x808003E4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808003E8: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x808003EC: beq         $a3, $at, L_8080044C
    if (ctx->r7 == ctx->r1) {
        // 0x808003F0: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_8080044C;
    }
    // 0x808003F0: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x808003F4: beq         $a3, $at, L_8080041C
    if (ctx->r7 == ctx->r1) {
        // 0x808003F8: addiu       $at, $zero, 0x9F
        ctx->r1 = ADD32(0, 0X9F);
            goto L_8080041C;
    }
    // 0x808003F8: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x808003FC: beq         $a3, $at, L_8080045C
    if (ctx->r7 == ctx->r1) {
        // 0x80800400: nop
    
            goto L_8080045C;
    }
    // 0x80800400: nop

    // 0x80800404: b           L_80800478
    // 0x80800408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800478;
    // 0x80800408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080040C:
    // 0x8080040C: jal         0x808002DC
    // 0x80800410: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808002DC_cheggclockwork(rdram, ctx);
        goto after_1;
    // 0x80800410: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800414: b           L_80800478
    // 0x80800418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800478;
    // 0x80800418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080041C:
    // 0x8080041C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800420: bne         $a2, $at, L_8080043C
    if (ctx->r6 != ctx->r1) {
        // 0x80800424: nop
    
            goto L_8080043C;
    }
    // 0x80800424: nop

    // 0x80800428: lw          $t6, 0x38($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X38);
    // 0x8080042C: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800430: bltz        $t8, L_8080043C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800434: nop
    
            goto L_8080043C;
    }
    // 0x80800434: nop

    // 0x80800438: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_8080043C:
    // 0x8080043C: jal         0x808002DC
    // 0x80800440: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_808002DC_cheggclockwork(rdram, ctx);
        goto after_2;
    // 0x80800440: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x80800444: b           L_80800478
    // 0x80800448: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800478;
    // 0x80800448: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080044C:
    // 0x8080044C: jal         0x808002DC
    // 0x80800450: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808002DC_cheggclockwork(rdram, ctx);
        goto after_3;
    // 0x80800450: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800454: b           L_80800478
    // 0x80800458: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800478;
    // 0x80800458: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080045C:
    // 0x8080045C: jal         0x808002DC
    // 0x80800460: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808002DC_cheggclockwork(rdram, ctx);
        goto after_4;
    // 0x80800460: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800464: b           L_80800478
    // 0x80800468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800478;
    // 0x80800468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080046C: b           L_80800478
    // 0x80800470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800478;
    // 0x80800470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800478:
    // 0x80800478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080047C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800480: jr          $ra
    // 0x80800484: nop

    return;
    // 0x80800484: nop

;}
RECOMP_FUNC void func_80800414_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080041C: jal         0x800EA05C
    // 0x80800420: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800420: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800424: addiu       $at, $zero, 0x122
    ctx->r1 = ADD32(0, 0X122);
    // 0x80800428: bne         $v0, $at, L_80800438
    if (ctx->r2 != ctx->r1) {
        // 0x8080042C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800438;
    }
    // 0x8080042C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800430: b           L_80800448
    // 0x80800434: addiu       $v0, $zero, 0x346
    ctx->r2 = ADD32(0, 0X346);
        goto L_80800448;
    // 0x80800434: addiu       $v0, $zero, 0x346
    ctx->r2 = ADD32(0, 0X346);
L_80800438:
    // 0x80800438: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080043C: lw          $v0, 0x6C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X6C);
    // 0x80800440: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x80800444: addiu       $v0, $t7, 0x346
    ctx->r2 = ADD32(ctx->r15, 0X346);
L_80800448:
    // 0x80800448: jr          $ra
    // 0x8080044C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8080044C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _gctransitionDll_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800881E8: syscall     674
    recomp_syscall_handler(rdram, ctx, 0x800881E8);
    return;
    // 0x800881EC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_808005B0_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005B8: jal         0x80082FE8
    // 0x808005BC: nop

    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808005BC: nop

    after_0:
    // 0x808005C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005C8: jr          $ra
    // 0x808005CC: nop

    return;
    // 0x808005CC: nop

;}
RECOMP_FUNC void func_800E8E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8E70: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800E8E74: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800E8E78: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800E8E7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E8E80: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800E8E84: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800E8E88: bne         $a3, $zero, L_800E8EF4
    if (ctx->r7 != 0) {
        // 0x800E8E8C: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_800E8EF4;
    }
    // 0x800E8E8C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800E8E90: jal         0x8002E660
    // 0x800E8E94: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x800E8E94: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800E8E98: jal         0x80012F6C
    // 0x800E8E9C: nop

    func_80012F6C(rdram, ctx);
        goto after_1;
    // 0x800E8E9C: nop

    after_1:
    // 0x800E8EA0: jal         0x80012F60
    // 0x800E8EA4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_80012F60(rdram, ctx);
        goto after_2;
    // 0x800E8EA4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_2:
    // 0x800E8EA8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800E8EAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800E8EB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E8EB4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800E8EB8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800E8EBC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800E8EC0: jal         0x8002E450
    // 0x800E8EC4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    osPiStartDma_recomp(rdram, ctx);
        goto after_3;
    // 0x800E8EC4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_3:
    // 0x800E8EC8: jal         0x80012F60
    // 0x800E8ECC: nop

    func_80012F60(rdram, ctx);
        goto after_4;
    // 0x800E8ECC: nop

    after_4:
    // 0x800E8ED0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E8ED4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800E8ED8: jal         0x8002E1F0
    // 0x800E8EDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x800E8EDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800E8EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E8EE4: jal         0x8002E6E0
    // 0x800E8EE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_6;
    // 0x800E8EE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x800E8EEC: b           L_800E8F58
    // 0x800E8EF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800E8F58;
    // 0x800E8EF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800E8EF4:
    // 0x800E8EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E8EF8: jal         0x8002E660
    // 0x800E8EFC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_7;
    // 0x800E8EFC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x800E8F00: jal         0x80012EF4
    // 0x800E8F04: nop

    func_80012EF4(rdram, ctx);
        goto after_8;
    // 0x800E8F04: nop

    after_8:
    // 0x800E8F08: jal         0x80012EE8
    // 0x800E8F0C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_80012EE8(rdram, ctx);
        goto after_9;
    // 0x800E8F0C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_9:
    // 0x800E8F10: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800E8F14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800E8F18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E8F1C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800E8F20: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800E8F24: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800E8F28: jal         0x8002E450
    // 0x800E8F2C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    osPiStartDma_recomp(rdram, ctx);
        goto after_10;
    // 0x800E8F2C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_10:
    // 0x800E8F30: jal         0x80012EE8
    // 0x800E8F34: nop

    func_80012EE8(rdram, ctx);
        goto after_11;
    // 0x800E8F34: nop

    after_11:
    // 0x800E8F38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E8F3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800E8F40: jal         0x8002E1F0
    // 0x800E8F44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_12;
    // 0x800E8F44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x800E8F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E8F4C: jal         0x8002E6E0
    // 0x800E8F50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_13;
    // 0x800E8F50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_13:
    // 0x800E8F54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800E8F58:
    // 0x800E8F58: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800E8F5C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800E8F60: jr          $ra
    // 0x800E8F64: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800E8F64: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800EA0_bsbwhirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800EAC: jal         0x8009E6EC
    // 0x80800EB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800EB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800EB4: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800EB8: beq         $v0, $at, L_80800EEC
    if (ctx->r2 == ctx->r1) {
        // 0x80800EBC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800EEC;
    }
    // 0x80800EBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800EC0: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80800EC4: beq         $v0, $at, L_80800EEC
    if (ctx->r2 == ctx->r1) {
        // 0x80800EC8: addiu       $at, $zero, 0x21
        ctx->r1 = ADD32(0, 0X21);
            goto L_80800EEC;
    }
    // 0x80800EC8: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80800ECC: beq         $v0, $at, L_80800EEC
    if (ctx->r2 == ctx->r1) {
        // 0x80800ED0: addiu       $at, $zero, 0x4E
        ctx->r1 = ADD32(0, 0X4E);
            goto L_80800EEC;
    }
    // 0x80800ED0: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x80800ED4: beq         $v0, $at, L_80800EEC
    if (ctx->r2 == ctx->r1) {
        // 0x80800ED8: addiu       $at, $zero, 0x51
        ctx->r1 = ADD32(0, 0X51);
            goto L_80800EEC;
    }
    // 0x80800ED8: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80800EDC: beq         $v0, $at, L_80800EEC
    if (ctx->r2 == ctx->r1) {
        // 0x80800EE0: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80800EEC;
    }
    // 0x80800EE0: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800EE4: bne         $v0, $at, L_80800EFC
    if (ctx->r2 != ctx->r1) {
        // 0x80800EE8: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_80800EFC;
    }
    // 0x80800EE8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
L_80800EEC:
    // 0x80800EEC: jal         0x8009E830
    // 0x80800EF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E830(rdram, ctx);
        goto after_1;
    // 0x80800EF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800EF4: b           L_80800F08
    // 0x80800EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800F08;
    // 0x80800EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800EFC:
    // 0x80800EFC: jalr        $t9
    // 0x80800F00: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80800F00: nop

    after_2:
    // 0x80800F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F08:
    // 0x80800F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F0C: jr          $ra
    // 0x80800F10: nop

    return;
    // 0x80800F10: nop

;}
RECOMP_FUNC void _bsclaw_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082EB0: syscall     33
    recomp_syscall_handler(rdram, ctx, 0x80082EB0);
    return;
    // 0x80082EB4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080458C_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080458C: lbu         $v0, 0x79($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X79);
    // 0x80804590: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804594: srl         $t6, $v0, 4
    ctx->r14 = S32(U32(ctx->r2) >> 4);
    // 0x80804598: beql        $t6, $zero, L_808045C8
    if (ctx->r14 == 0) {
        // 0x8080459C: lw          $t7, 0x6C($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X6C);
            goto L_808045C8;
    }
    goto skip_0;
    // 0x8080459C: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
    skip_0:
    // 0x808045A0: beq         $t6, $at, L_808045C4
    if (ctx->r14 == ctx->r1) {
        // 0x808045A4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808045C4;
    }
    // 0x808045A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808045A8: beq         $t6, $at, L_808045C4
    if (ctx->r14 == ctx->r1) {
        // 0x808045AC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808045C4;
    }
    // 0x808045AC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808045B0: beql        $t6, $at, L_808045F8
    if (ctx->r14 == ctx->r1) {
        // 0x808045B4: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_808045F8;
    }
    goto skip_1;
    // 0x808045B4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    skip_1:
    // 0x808045B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808045BC: b           L_80804604
    // 0x808045C0: nop

        goto L_80804604;
    // 0x808045C0: nop

L_808045C4:
    // 0x808045C4: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
L_808045C8:
    // 0x808045C8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808045CC: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x808045D0: bnel        $t8, $zero, L_808045EC
    if (ctx->r24 != 0) {
        // 0x808045D4: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_808045EC;
    }
    goto skip_2;
    // 0x808045D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_2:
    // 0x808045D8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808045DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808045E0: jr          $ra
    // 0x808045E4: nop

    return;
    // 0x808045E4: nop

    // 0x808045E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_808045EC:
    // 0x808045EC: jr          $ra
    // 0x808045F0: nop

    return;
    // 0x808045F0: nop

    // 0x808045F4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
L_808045F8:
    // 0x808045F8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808045FC: jr          $ra
    // 0x80804600: nop

    return;
    // 0x80804600: nop

L_80804604:
    // 0x80804604: jr          $ra
    // 0x80804608: nop

    return;
    // 0x80804608: nop

;}
RECOMP_FUNC void func_80800000_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: jal         0x8009E74C
    // 0x80800014: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x80800018: beq         $v0, $zero, L_80800044
    if (ctx->r2 == 0) {
        // 0x8080001C: nop
    
            goto L_80800044;
    }
    // 0x8080001C: nop

    // 0x80800020: jal         0x80084508
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babackpack_get_state(rdram, ctx);
        goto after_1;
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800028: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8080002C: beq         $v0, $at, L_80800084
    if (ctx->r2 == ctx->r1) {
        // 0x80800030: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800084;
    }
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800034: jal         0x80084538
    // 0x80800038: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _babackpack_set_state(rdram, ctx);
        goto after_2;
    // 0x80800038: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x8080003C: b           L_80800088
    // 0x80800040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800088;
    // 0x80800040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800044:
    // 0x80800044: jal         0x80084508
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babackpack_get_state(rdram, ctx);
        goto after_3;
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080004C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800050: beq         $v0, $at, L_80800060
    if (ctx->r2 == ctx->r1) {
        // 0x80800054: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800060;
    }
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: jal         0x80084538
    // 0x8080005C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babackpack_set_state(rdram, ctx);
        goto after_4;
    // 0x8080005C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_80800060:
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800064: jal         0x800A0CD0
    // 0x80800068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CD0(rdram, ctx);
        goto after_5;
    // 0x80800068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080006C: jal         0x80095A40
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_6;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800074: jal         0x8009EF60
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_popZone(rdram, ctx);
        goto after_7;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080007C: jal         0x800A4E30
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4E30(rdram, ctx);
        goto after_8;
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80800084:
    // 0x80800084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800088:
    // 0x80800088: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080008C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void badrone_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800604: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080060C: lw          $a0, 0x54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54);
    // 0x80800610: jal         0x800EE7F8
    // 0x80800614: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800614: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_0:
    // 0x80800618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080061C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800620: jr          $ra
    // 0x80800624: nop

    return;
    // 0x80800624: nop

    // 0x80800628: nop

    // 0x8080062C: nop

;}
RECOMP_FUNC void func_800EBE24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBE24: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800EBE28: addiu       $a1, $a1, 0x2ED0
    ctx->r5 = ADD32(ctx->r5, 0X2ED0);
    // 0x800EBE2C: subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // 0x800EBE30: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800EBE34: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800EBE38: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
    // 0x800EBE3C: mflo        $t8
    ctx->r24 = lo;
    // 0x800EBE40: andi        $t0, $t8, 0x7
    ctx->r8 = ctx->r24 & 0X7;
    // 0x800EBE44: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800EBE48: sh          $t7, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r15;
    // 0x800EBE4C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800EBE50: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800EBE54: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800EBE58: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800EBE5C: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x800EBE60: lbu         $t3, 0x2580($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X2580);
    // 0x800EBE64: lw          $t2, 0x3554($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3554);
    // 0x800EBE68: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x800EBE6C: jr          $ra
    // 0x800EBE70: sb          $t4, 0x2580($v1)
    MEM_B(0X2580, ctx->r3) = ctx->r12;
    return;
    // 0x800EBE70: sb          $t4, 0x2580($v1)
    MEM_B(0X2580, ctx->r3) = ctx->r12;
;}
RECOMP_FUNC void func_8080015C_chstinger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800160: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800164: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800168: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080016C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800170: jal         0x80100094
    // 0x80800174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800178: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x8080017C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800188: beql        $a1, $t7, L_80800208
    if (ctx->r5 == ctx->r15) {
        // 0x8080018C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800208;
    }
    goto skip_0;
    // 0x8080018C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800190: jal         0x80101FDC
    // 0x80800194: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800194: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800198: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x8080019C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001A0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808001A4: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x808001A8: beq         $t8, $at, L_808001C4
    if (ctx->r24 == ctx->r1) {
        // 0x808001AC: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_808001C4;
    }
    // 0x808001AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808001B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001B4: beq         $t8, $at, L_808001CC
    if (ctx->r24 == ctx->r1) {
        // 0x808001B8: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_808001CC;
    }
    // 0x808001B8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808001BC: b           L_80800208
    // 0x808001C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800208;
    // 0x808001C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001C4:
    // 0x808001C4: b           L_80800204
    // 0x808001C8: sb          $t9, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r25;
        goto L_80800204;
    // 0x808001C8: sb          $t9, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r25;
L_808001CC:
    // 0x808001CC: jal         0x800CB840
    // 0x808001D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800CB840(rdram, ctx);
        goto after_2;
    // 0x808001D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x808001D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808001D8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x808001DC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808001E0: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    // 0x808001E4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808001E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808001EC: jal         0x80109BEC
    // 0x808001F0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_80109BEC(rdram, ctx);
        goto after_3;
    // 0x808001F0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_3:
    // 0x808001F4: jal         0x800CB870
    // 0x808001F8: nop

    func_800CB870(rdram, ctx);
        goto after_4;
    // 0x808001F8: nop

    after_4:
    // 0x808001FC: jal         0x80800000
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chstinger(rdram, ctx);
        goto after_5;
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80800204:
    // 0x80800204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800208:
    // 0x80800208: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080020C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800210: jr          $ra
    // 0x80800214: nop

    return;
    // 0x80800214: nop

;}
RECOMP_FUNC void chmasterjiggy_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801194: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080119C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808011A0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808011A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808011A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808011AC: jal         0x80106790
    // 0x808011B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808011B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808011B4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808011B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808011BC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808011C0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x808011C4: addu        $a3, $t7, $a1
    ctx->r7 = ADD32(ctx->r15, ctx->r5);
    // 0x808011C8: sltu        $at, $a1, $a3
    ctx->r1 = ctx->r5 < ctx->r7 ? 1 : 0;
    // 0x808011CC: beq         $at, $zero, L_80801438
    if (ctx->r1 == 0) {
        // 0x808011D0: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_80801438;
    }
    // 0x808011D0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_808011D4:
    // 0x808011D4: lbu         $v1, 0xC($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XC);
    // 0x808011D8: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x808011DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808011E0: subu        $t8, $a0, $v1
    ctx->r24 = SUB32(ctx->r4, ctx->r3);
    // 0x808011E4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x808011E8: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x808011EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808011F0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808011F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808011F8: bgezl       $v1, L_80801210
    if (SIGNED(ctx->r3) >= 0) {
        // 0x808011FC: add.s       $f6, $f10, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
            goto L_80801210;
    }
    goto skip_0;
    // 0x808011FC: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    skip_0:
    // 0x80801200: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801204: nop

    // 0x80801208: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8080120C: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
L_80801210:
    // 0x80801210: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801214: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801218: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8080121C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80801220: nop

    // 0x80801224: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801228: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8080122C: nop

    // 0x80801230: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80801234: beql        $t0, $zero, L_80801284
    if (ctx->r8 == 0) {
        // 0x80801238: mfc1        $t0, $f8
        ctx->r8 = (int32_t)ctx->f8.u32l;
            goto L_80801284;
    }
    goto skip_1;
    // 0x80801238: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x8080123C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801240: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801244: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80801248: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8080124C: nop

    // 0x80801250: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80801254: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80801258: nop

    // 0x8080125C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80801260: bne         $t0, $zero, L_80801278
    if (ctx->r8 != 0) {
        // 0x80801264: nop
    
            goto L_80801278;
    }
    // 0x80801264: nop

    // 0x80801268: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8080126C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801270: b           L_80801290
    // 0x80801274: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80801290;
    // 0x80801274: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80801278:
    // 0x80801278: b           L_80801290
    // 0x8080127C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80801290;
    // 0x8080127C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80801280: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
L_80801284:
    // 0x80801284: nop

    // 0x80801288: bltz        $t0, L_80801278
    if (SIGNED(ctx->r8) < 0) {
        // 0x8080128C: nop
    
            goto L_80801278;
    }
    // 0x8080128C: nop

L_80801290:
    // 0x80801290: sb          $t0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r8;
    // 0x80801294: lbu         $t1, 0xD($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0XD);
    // 0x80801298: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8080129C: lbu         $t3, 0xC($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0XC);
    // 0x808012A0: subu        $t2, $a0, $t1
    ctx->r10 = SUB32(ctx->r4, ctx->r9);
    // 0x808012A4: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x808012A8: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x808012AC: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x808012B0: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808012B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808012B8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808012BC: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x808012C0: bgezl       $t3, L_808012D8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808012C4: add.s       $f4, $f18, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
            goto L_808012D8;
    }
    goto skip_2;
    // 0x808012C4: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    skip_2:
    // 0x808012C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808012CC: nop

    // 0x808012D0: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x808012D4: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
L_808012D8:
    // 0x808012D8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x808012DC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808012E0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x808012E4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x808012E8: nop

    // 0x808012EC: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x808012F0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x808012F4: nop

    // 0x808012F8: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x808012FC: beql        $t5, $zero, L_8080134C
    if (ctx->r13 == 0) {
        // 0x80801300: mfc1        $t5, $f10
        ctx->r13 = (int32_t)ctx->f10.u32l;
            goto L_8080134C;
    }
    goto skip_3;
    // 0x80801300: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    skip_3:
    // 0x80801304: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801308: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8080130C: sub.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80801310: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80801314: nop

    // 0x80801318: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8080131C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80801320: nop

    // 0x80801324: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80801328: bne         $t5, $zero, L_80801340
    if (ctx->r13 != 0) {
        // 0x8080132C: nop
    
            goto L_80801340;
    }
    // 0x8080132C: nop

    // 0x80801330: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80801334: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801338: b           L_80801358
    // 0x8080133C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80801358;
    // 0x8080133C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80801340:
    // 0x80801340: b           L_80801358
    // 0x80801344: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80801358;
    // 0x80801344: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80801348: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
L_8080134C:
    // 0x8080134C: nop

    // 0x80801350: bltz        $t5, L_80801340
    if (SIGNED(ctx->r13) < 0) {
        // 0x80801354: nop
    
            goto L_80801340;
    }
    // 0x80801354: nop

L_80801358:
    // 0x80801358: sb          $t5, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r13;
    // 0x8080135C: lbu         $t6, 0xE($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XE);
    // 0x80801360: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80801364: lbu         $t8, 0xC($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XC);
    // 0x80801368: subu        $t7, $a0, $t6
    ctx->r15 = SUB32(ctx->r4, ctx->r14);
    // 0x8080136C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80801370: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80801374: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80801378: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080137C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80801380: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80801384: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801388: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080138C: bgezl       $t8, L_808013A4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801390: add.s       $f16, $f8, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
            goto L_808013A4;
    }
    goto skip_4;
    // 0x80801390: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    skip_4:
    // 0x80801394: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801398: nop

    // 0x8080139C: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x808013A0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
L_808013A4:
    // 0x808013A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808013A8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808013AC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x808013B0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x808013B4: nop

    // 0x808013B8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x808013BC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x808013C0: nop

    // 0x808013C4: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x808013C8: beql        $t0, $zero, L_80801418
    if (ctx->r8 == 0) {
        // 0x808013CC: mfc1        $t0, $f18
        ctx->r8 = (int32_t)ctx->f18.u32l;
            goto L_80801418;
    }
    goto skip_5;
    // 0x808013CC: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    skip_5:
    // 0x808013D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808013D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808013D8: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x808013DC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x808013E0: nop

    // 0x808013E4: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x808013E8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x808013EC: nop

    // 0x808013F0: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x808013F4: bne         $t0, $zero, L_8080140C
    if (ctx->r8 != 0) {
        // 0x808013F8: nop
    
            goto L_8080140C;
    }
    // 0x808013F8: nop

    // 0x808013FC: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80801400: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801404: b           L_80801424
    // 0x80801408: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80801424;
    // 0x80801408: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_8080140C:
    // 0x8080140C: b           L_80801424
    // 0x80801410: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80801424;
    // 0x80801410: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80801414: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
L_80801418:
    // 0x80801418: nop

    // 0x8080141C: bltz        $t0, L_8080140C
    if (SIGNED(ctx->r8) < 0) {
        // 0x80801420: nop
    
            goto L_8080140C;
    }
    // 0x80801420: nop

L_80801424:
    // 0x80801424: sltu        $at, $a1, $a3
    ctx->r1 = ctx->r5 < ctx->r7 ? 1 : 0;
    // 0x80801428: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8080142C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80801430: bne         $at, $zero, L_808011D4
    if (ctx->r1 != 0) {
        // 0x80801434: sb          $t0, -0x2($a2)
        MEM_B(-0X2, ctx->r6) = ctx->r8;
            goto L_808011D4;
    }
    // 0x80801434: sb          $t0, -0x2($a2)
    MEM_B(-0X2, ctx->r6) = ctx->r8;
L_80801438:
    // 0x80801438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080143C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801440: jr          $ra
    // 0x80801444: nop

    return;
    // 0x80801444: nop

;}
RECOMP_FUNC void bsbee_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000C4: jal         0x8009E77C
    // 0x808000C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x808000C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808000CC: bnel        $v0, $zero, L_808001B8
    if (ctx->r2 != 0) {
        // 0x808000D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001B8;
    }
    goto skip_0;
    // 0x808000D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000D4: jal         0x80084560
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babee_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E0: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808000E4: jal         0x8009BFE4
    // 0x808000E8: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_2;
    // 0x808000E8: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_2:
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808000F4: jal         0x8009C554
    // 0x808000F8: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_3;
    // 0x808000F8: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_3:
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x80800104: jal         0x800959C8
    // 0x80800108: lui         $a2, 0x41C8
    ctx->r6 = S32(0X41C8 << 16);
    func_800959C8(rdram, ctx);
        goto after_4;
    // 0x80800108: lui         $a2, 0x41C8
    ctx->r6 = S32(0X41C8 << 16);
    after_4:
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800110: jal         0x80095760
    // 0x80800114: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baflag_set(rdram, ctx);
        goto after_5;
    // 0x80800114: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: jal         0x80095760
    // 0x80800120: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    baflag_set(rdram, ctx);
        goto after_6;
    // 0x80800120: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x80800124: jal         0x8009EFA8
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_7;
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080012C: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x80800130: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: jal         0x8009F1C8
    // 0x8080013C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_8;
    // 0x8080013C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800144: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800148: jal         0x8009F1C8
    // 0x8080014C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_9;
    // 0x8080014C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_9:
    // 0x80800150: jal         0x8009E4AC
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_10;
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800160: jal         0x8009E55C
    // 0x80800164: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    func_8009E55C(rdram, ctx);
        goto after_11;
    // 0x80800164: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_11:
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080016C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800170: jal         0x8009E55C
    // 0x80800174: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_8009E55C(rdram, ctx);
        goto after_12;
    // 0x80800174: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_12:
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080017C: lui         $a1, 0x4296
    ctx->r5 = S32(0X4296 << 16);
    // 0x80800180: jal         0x800959C8
    // 0x80800184: lui         $a2, 0x422C
    ctx->r6 = S32(0X422C << 16);
    func_800959C8(rdram, ctx);
        goto after_13;
    // 0x80800184: lui         $a2, 0x422C
    ctx->r6 = S32(0X422C << 16);
    after_13:
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: jal         0x8009590C
    // 0x80800190: lui         $a1, 0x4296
    ctx->r5 = S32(0X4296 << 16);
    func_8009590C(rdram, ctx);
        goto after_14;
    // 0x80800190: lui         $a1, 0x4296
    ctx->r5 = S32(0X4296 << 16);
    after_14:
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080019C: jal         0x800947EC
    // 0x808001A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_15;
    // 0x808001A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x808001A4: lui         $a1, 0x3F8C
    ctx->r5 = S32(0X3F8C << 16);
    // 0x808001A8: ori         $a1, $a1, 0xCC80
    ctx->r5 = ctx->r5 | 0XCC80;
    // 0x808001AC: jal         0x80092864
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092864(rdram, ctx);
        goto after_16;
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808001B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001B8:
    // 0x808001B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001C0: jr          $ra
    // 0x808001C4: nop

    return;
    // 0x808001C4: nop

;}
RECOMP_FUNC void fxleaves_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808003C4: jal         0x8001ACCC
    // 0x808003C8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x808003C8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_0:
    // 0x808003CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808003D0: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x808003D4: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x808003D8: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x808003DC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x808003E0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x808003E4: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x808003E8: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x808003EC: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x808003F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808003F4: jal         0x800B2D70
    // 0x808003F8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    vector_new(rdram, ctx);
        goto after_1;
    // 0x808003F8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808003FC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800400: addiu       $t7, $zero, 0x9ED
    ctx->r15 = ADD32(0, 0X9ED);
    // 0x80800404: addiu       $t8, $zero, 0x9EE
    ctx->r24 = ADD32(0, 0X9EE);
    // 0x80800408: sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
    // 0x8080040C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800410: addiu       $t9, $zero, 0x9EF
    ctx->r25 = ADD32(0, 0X9EF);
    // 0x80800414: addiu       $t0, $zero, 0x9F0
    ctx->r8 = ADD32(0, 0X9F0);
    // 0x80800418: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2802, 0X790) << 16);
    // 0x8080041C: sb          $zero, 0x22($v1)
    MEM_B(0X22, ctx->r3) = 0;
    // 0x80800420: sw          $t7, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r15;
    // 0x80800424: sw          $t8, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r24;
    // 0x80800428: sw          $t9, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r25;
    // 0x8080042C: sw          $t0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r8;
    // 0x80800430: sb          $zero, 0x34($v1)
    MEM_B(0X34, ctx->r3) = 0;
    // 0x80800434: sh          $t6, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r14;
    // 0x80800438: lwc1        $f4, 0x790($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2802, 0X790));
    // 0x8080043C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800440: swc1        $f4, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f4.u32l;
    // 0x80800444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800448: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080044C: jr          $ra
    // 0x80800450: nop

    return;
    // 0x80800450: nop

;}
RECOMP_FUNC void func_80800B74_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B78: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B7C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800B80: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800B84: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800B88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800B90: jal         0x80100094
    // 0x80800B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B98: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80800B9C: addiu       $s1, $v0, 0x1
    ctx->r17 = ADD32(ctx->r2, 0X1);
    // 0x80800BA0: addiu       $s2, $zero, 0x16
    ctx->r18 = ADD32(0, 0X16);
L_80800BA4:
    // 0x80800BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BA8: jal         0x800DF744
    // 0x80800BAC: lbu         $a1, 0x0($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X0);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80800BAC: lbu         $a1, 0x0($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X0);
    after_1:
    // 0x80800BB0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800BB4: bne         $s0, $s2, L_80800BA4
    if (ctx->r16 != ctx->r18) {
        // 0x80800BB8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800BA4;
    }
    // 0x80800BB8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800BBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800BC0: jal         0x80101870
    // 0x80800BC4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80101870(rdram, ctx);
        goto after_2;
    // 0x80800BC4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80800BC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800BCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800BD0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BD4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800BD8: jr          $ra
    // 0x80800BDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800BDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80015F0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015F0C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80015F10: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80015F14: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80015F18: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80015F1C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80015F20: jr          $ra
    // 0x80015F24: lw          $v0, -0x6640($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6640);
    return;
    // 0x80015F24: lw          $v0, -0x6640($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6640);
;}
RECOMP_FUNC void bsow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x800845D8
    // 0x80800010: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800014: lui         $a2, 0x3F08
    ctx->r6 = S32(0X3F08 << 16);
    // 0x80800018: ori         $a2, $a2, 0xCE70
    ctx->r6 = ctx->r6 | 0XCE70;
    // 0x8080001C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800020: jal         0x800845E0
    // 0x80800024: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800024: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    after_1:
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080002C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800030: jr          $ra
    // 0x80800034: nop

    return;
    // 0x80800034: nop

;}
RECOMP_FUNC void choildrill_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801230: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2412, 0X14F0) << 16);
    // 0x80801234: jr          $ra
    // 0x80801238: addiu       $v0, $v0, 0x14F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2412, 0X14F0));
    return;
    // 0x80801238: addiu       $v0, $v0, 0x14F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2412, 0X14F0));
    // 0x8080123C: nop

;}
RECOMP_FUNC void bafly_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000FC: lw          $t6, 0x8C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8C);
    // 0x80800100: jr          $ra
    // 0x80800104: lbu         $v0, 0x8($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X8);
    return;
    // 0x80800104: lbu         $v0, 0x8($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X8);
;}
RECOMP_FUNC void func_800C122C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C122C: beq         $a3, $zero, L_800C1254
    if (ctx->r7 == 0) {
        // 0x800C1230: nop
    
            goto L_800C1254;
    }
    // 0x800C1230: nop

    // 0x800C1234: beq         $a1, $zero, L_800C1244
    if (ctx->r5 == 0) {
        // 0x800C1238: nop
    
            goto L_800C1244;
    }
    // 0x800C1238: nop

    // 0x800C123C: bne         $a2, $zero, L_800C124C
    if (ctx->r6 != 0) {
        // 0x800C1240: nop
    
            goto L_800C124C;
    }
    // 0x800C1240: nop

L_800C1244:
    // 0x800C1244: jr          $ra
    // 0x800C1248: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800C1248: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800C124C:
    // 0x800C124C: jr          $ra
    // 0x800C1250: addiu       $v0, $a0, 0x80
    ctx->r2 = ADD32(ctx->r4, 0X80);
    return;
    // 0x800C1250: addiu       $v0, $a0, 0x80
    ctx->r2 = ADD32(ctx->r4, 0X80);
L_800C1254:
    // 0x800C1254: beq         $a1, $zero, L_800C1264
    if (ctx->r5 == 0) {
        // 0x800C1258: lui         $at, 0x42FE
        ctx->r1 = S32(0X42FE << 16);
            goto L_800C1264;
    }
    // 0x800C1258: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800C125C: bnel        $a2, $zero, L_800C1300
    if (ctx->r6 != 0) {
        // 0x800C1260: lui         $at, 0x42FE
        ctx->r1 = S32(0X42FE << 16);
            goto L_800C1300;
    }
    goto skip_0;
    // 0x800C1260: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    skip_0:
L_800C1264:
    // 0x800C1264: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C1268: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C126C: lwc1        $f8, -0x5790($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5790);
    // 0x800C1270: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800C1274: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C1278: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800C127C: lwc1        $f18, -0x578C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X578C);
    // 0x800C1280: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C1284: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C1288: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C128C: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C1290: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800C1294: nop

    // 0x800C1298: bc1fl       L_800C12AC
    if (!c1cs) {
        // 0x800C129C: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800C12AC;
    }
    goto skip_1;
    // 0x800C129C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_1:
    // 0x800C12A0: b           L_800C12AC
    // 0x800C12A4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_800C12AC;
    // 0x800C12A4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x800C12A8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800C12AC:
    // 0x800C12AC: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x800C12B0: nop

    // 0x800C12B4: bc1fl       L_800C12D0
    if (!c1cs) {
        // 0x800C12B8: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_800C12D0;
    }
    goto skip_2;
    // 0x800C12B8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_2:
    // 0x800C12BC: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800C12C0: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800C12C4: jr          $ra
    // 0x800C12C8: nop

    return;
    // 0x800C12C8: nop

    // 0x800C12CC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_800C12D0:
    // 0x800C12D0: nop

    // 0x800C12D4: bc1fl       L_800C12E8
    if (!c1cs) {
        // 0x800C12D8: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800C12E8;
    }
    goto skip_3;
    // 0x800C12D8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_3:
    // 0x800C12DC: b           L_800C12E8
    // 0x800C12E0: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_800C12E8;
    // 0x800C12E0: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x800C12E4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800C12E8:
    // 0x800C12E8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800C12EC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C12F0: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800C12F4: jr          $ra
    // 0x800C12F8: nop

    return;
    // 0x800C12F8: nop

    // 0x800C12FC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
L_800C1300:
    // 0x800C1300: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C1304: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C1308: lwc1        $f10, -0x5790($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5790);
    // 0x800C130C: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800C1310: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C1314: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800C1318: lwc1        $f4, -0x578C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X578C);
    // 0x800C131C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800C1320: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C1324: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C1328: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C132C: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800C1330: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C1334: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800C1338: nop

    // 0x800C133C: bc1fl       L_800C1350
    if (!c1cs) {
        // 0x800C1340: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800C1350;
    }
    goto skip_4;
    // 0x800C1340: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_4:
    // 0x800C1344: b           L_800C1350
    // 0x800C1348: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_800C1350;
    // 0x800C1348: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x800C134C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800C1350:
    // 0x800C1350: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x800C1354: nop

    // 0x800C1358: bc1fl       L_800C136C
    if (!c1cs) {
        // 0x800C135C: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_800C136C;
    }
    goto skip_5;
    // 0x800C135C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_5:
    // 0x800C1360: b           L_800C1388
    // 0x800C1364: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_800C1388;
    // 0x800C1364: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x800C1368: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_800C136C:
    // 0x800C136C: nop

    // 0x800C1370: bc1fl       L_800C1384
    if (!c1cs) {
        // 0x800C1374: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800C1384;
    }
    goto skip_6;
    // 0x800C1374: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_6:
    // 0x800C1378: b           L_800C1384
    // 0x800C137C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_800C1384;
    // 0x800C137C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x800C1380: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800C1384:
    // 0x800C1384: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800C1388:
    // 0x800C1388: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800C138C: trunc.w.s   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800C1390: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800C1394: nop

    // 0x800C1398: jr          $ra
    // 0x800C139C: nop

    return;
    // 0x800C139C: nop

;}
RECOMP_FUNC void _idtwinklecolour_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088EE0: syscall     747
    recomp_syscall_handler(rdram, ctx, 0x80088EE0);
    return;
    // 0x80088EE4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80111DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111DB0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80111DB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80111DB8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80111DBC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80111DC0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80111DC4: jal         0x800EFB24
    // 0x80111DC8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x80111DC8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80111DCC: jal         0x800EEF94
    // 0x80111DD0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EEF94(rdram, ctx);
        goto after_1;
    // 0x80111DD0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x80111DD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80111DD8: lwc1        $f4, 0x655C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X655C);
    // 0x80111DDC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80111DE0: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80111DE4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80111DE8: nop

    // 0x80111DEC: bc1fl       L_80111E70
    if (!c1cs) {
        // 0x80111DF0: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_80111E70;
    }
    goto skip_0;
    // 0x80111DF0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_0:
    // 0x80111DF4: jal         0x800D8FF8
    // 0x80111DF8: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80111DF8: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x80111DFC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80111E00: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80111E04: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80111E08: lw          $v0, 0x34($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X34);
    // 0x80111E0C: lwc1        $f6, 0x7C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x80111E10: lw          $a2, 0x80($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X80);
    // 0x80111E14: lw          $a3, 0x84($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X84);
    // 0x80111E18: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80111E1C: jal         0x800FF060
    // 0x80111E20: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800FF060(rdram, ctx);
        goto after_3;
    // 0x80111E20: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80111E24: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80111E28: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80111E2C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80111E30: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80111E34: nop

    // 0x80111E38: bc1fl       L_80111E50
    if (!c1cs) {
        // 0x80111E3C: div.s       $f10, $f2, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
            goto L_80111E50;
    }
    goto skip_1;
    // 0x80111E3C: div.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
    skip_1:
    // 0x80111E40: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80111E44: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80111E48: swc1        $f8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f8.u32l;
    // 0x80111E4C: div.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
L_80111E50:
    // 0x80111E50: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80111E54: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80111E58: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80111E5C: jal         0x800EF174
    // 0x80111E60: nop

    func_800EF174(rdram, ctx);
        goto after_4;
    // 0x80111E60: nop

    after_4:
    // 0x80111E64: b           L_80111E7C
    // 0x80111E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80111E7C;
    // 0x80111E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80111E6C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_80111E70:
    // 0x80111E70: nop

    // 0x80111E74: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x80111E78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80111E7C:
    // 0x80111E7C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80111E80: jr          $ra
    // 0x80111E84: nop

    return;
    // 0x80111E84: nop

;}
