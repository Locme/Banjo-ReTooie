#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chlagoonbits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085FC0: syscall     268
    recomp_syscall_handler(rdram, ctx, 0x80085FC0);
    return;
    // 0x80085FC4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bsmummove_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800004: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800008: jr          $ra
    // 0x8080000C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080000C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8080061C_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080061C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800620: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800624: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800628: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080062C: jal         0x80090178
    // 0x80800630: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    func_80090178(rdram, ctx);
        goto after_0;
    // 0x80800630: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_0:
    // 0x80800634: beq         $v0, $zero, L_80800674
    if (ctx->r2 == 0) {
        // 0x80800638: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(2168, 0XFEC) << 16);
            goto L_80800674;
    }
    // 0x80800638: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2168, 0XFEC) << 16);
    // 0x8080063C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2168, 0XFD0) << 16);
    // 0x80800640: addiu       $a2, $a2, 0xFD0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2168, 0XFD0));
    // 0x80800644: jal         0x808009C0
    // 0x80800648: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_808009C0_chfactoryworkerdirty(rdram, ctx);
        goto after_1;
    // 0x80800648: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_1:
    // 0x8080064C: beq         $v0, $zero, L_80800664
    if (ctx->r2 == 0) {
        // 0x80800650: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_80800664;
    }
    // 0x80800650: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800654: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2168, 0XFD6) << 16);
    // 0x80800658: lhu         $t6, 0xFD6($t6)
    ctx->r14 = MEM_HU(ctx->r14, (int16_t)RELOC_LO16(2168, 0XFD6));
    // 0x8080065C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2168, 0XFD4) << 16);
    // 0x80800660: sh          $t6, 0xFD4($at)
    MEM_H((int16_t)RELOC_LO16(2168, 0XFD4), ctx->r1) = ctx->r14;
L_80800664:
    // 0x80800664: lbu         $t7, 0x74($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X74);
    // 0x80800668: andi        $t8, $t7, 0xFFBF
    ctx->r24 = ctx->r15 & 0XFFBF;
    // 0x8080066C: b           L_80800678
    // 0x80800670: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
        goto L_80800678;
    // 0x80800670: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
L_80800674:
    // 0x80800674: addiu       $a2, $a2, 0xFEC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2168, 0XFEC));
L_80800678:
    // 0x80800678: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080067C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800680: jal         0x8008A1E8
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800688: beq         $v0, $zero, L_808006EC
    if (ctx->r2 == 0) {
        // 0x8080068C: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_808006EC;
    }
    // 0x8080068C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800690: addiu       $at, $zero, 0x134C
    ctx->r1 = ADD32(0, 0X134C);
    // 0x80800694: beq         $v0, $at, L_808006AC
    if (ctx->r2 == ctx->r1) {
        // 0x80800698: addiu       $at, $zero, 0x134D
        ctx->r1 = ADD32(0, 0X134D);
            goto L_808006AC;
    }
    // 0x80800698: addiu       $at, $zero, 0x134D
    ctx->r1 = ADD32(0, 0X134D);
    // 0x8080069C: beq         $v0, $at, L_808006C8
    if (ctx->r2 == ctx->r1) {
        // 0x808006A0: nop
    
            goto L_808006C8;
    }
    // 0x808006A0: nop

    // 0x808006A4: b           L_808006E4
    // 0x808006A8: nop

        goto L_808006E4;
    // 0x808006A8: nop

L_808006AC:
    // 0x808006AC: jal         0x80090734
    // 0x808006B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090734(rdram, ctx);
        goto after_3;
    // 0x808006B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B8: jal         0x808000AC
    // 0x808006BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808000AC_chfactoryworkerdirty(rdram, ctx);
        goto after_4;
    // 0x808006BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808006C0: b           L_808006F0
    // 0x808006C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808006F0;
    // 0x808006C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006C8:
    // 0x808006C8: jal         0x80090734
    // 0x808006CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090734(rdram, ctx);
        goto after_5;
    // 0x808006CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D4: jal         0x808000AC
    // 0x808006D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808000AC_chfactoryworkerdirty(rdram, ctx);
        goto after_6;
    // 0x808006D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808006DC: b           L_808006F0
    // 0x808006E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808006F0;
    // 0x808006E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006E4:
    // 0x808006E4: jal         0x80090734
    // 0x808006E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090734(rdram, ctx);
        goto after_7;
    // 0x808006E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
L_808006EC:
    // 0x808006EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006F0:
    // 0x808006F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808006F8: jr          $ra
    // 0x808006FC: nop

    return;
    // 0x808006FC: nop

;}
RECOMP_FUNC void func_8001B84C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B84C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001B850: jr          $ra
    // 0x8001B854: sw          $zero, -0x3908($at)
    MEM_W(-0X3908, ctx->r1) = 0;
    return;
    // 0x8001B854: sw          $zero, -0x3908($at)
    MEM_W(-0X3908, ctx->r1) = 0;
;}
RECOMP_FUNC void func_8010588C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010588C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105894: jal         0x8010A570
    // 0x80105898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010A570(rdram, ctx);
        goto after_0;
    // 0x80105898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010589C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801058A0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801058A4: lbu         $t7, 0x2A($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2A);
    // 0x801058A8: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x801058AC: jal         0x801054D4
    // 0x801058B0: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    func_801054D4(rdram, ctx);
        goto after_1;
    // 0x801058B0: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    after_1:
    // 0x801058B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801058B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801058BC: jr          $ra
    // 0x801058C0: nop

    return;
    // 0x801058C0: nop

;}
RECOMP_FUNC void func_808009B4_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009B4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808009B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808009BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808009C4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x808009C8: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x808009CC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808009D0: jal         0x8008A0E8
    // 0x808009D4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808009D4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x808009D8: beq         $v0, $zero, L_808009F0
    if (ctx->r2 == 0) {
        // 0x808009DC: lw          $a1, 0x30($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X30);
            goto L_808009F0;
    }
    // 0x808009DC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808009E0: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808009E4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808009E8: jal         0x80085770
    // 0x808009EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chbadshad_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808009EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_808009F0:
    // 0x808009F0: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808009F4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808009F8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808009FC: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x80800A00: beq         $at, $zero, L_80800C20
    if (ctx->r1 == 0) {
        // 0x80800A04: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800C20;
    }
    // 0x80800A04: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800A08: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1020, 0X1344) << 16);
    // 0x80800A0C: addu        $at, $at, $t8
    gpr jr_addend_80800A14 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800A10: lw          $t8, 0x1344($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1020, 0X1344));
    // 0x80800A14: jr          $t8
    // 0x80800A18: nop

    switch (jr_addend_80800A14 >> 2) {
        case 0: goto L_80800C5C; break;
        case 1: goto L_80800A1C; break;
        case 2: goto L_80800A88; break;
        case 3: goto L_80800AF4; break;
        case 4: goto L_80800BB0; break;
        case 5: goto L_80800C00; break;
        case 6: goto L_80800A88; break;
        default: switch_error(__func__, 0x80800A14, 0x80801344);
    }
    // 0x80800A18: nop

L_80800A1C:
    // 0x80800A1C: jal         0x80800E2C
    // 0x80800A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E2C_chtiptup(rdram, ctx);
        goto after_2;
    // 0x80800A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800A24: jal         0x80101DDC
    // 0x80800A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_3;
    // 0x80800A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800A2C: beq         $v0, $zero, L_80800C20
    if (ctx->r2 == 0) {
        // 0x80800A30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C20;
    }
    // 0x80800A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A34: jal         0x80102424
    // 0x80800A38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80800A38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800A3C: jal         0x8010A590
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_5;
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800A44: jal         0x80106790
    // 0x80800A48: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_6;
    // 0x80800A48: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_6:
    // 0x80800A4C: jal         0x800F54E4
    // 0x80800A50: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800A50: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_7:
    // 0x80800A54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A58: jal         0x800F82D4
    // 0x80800A5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_8;
    // 0x80800A5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800A60: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800A64: addiu       $t9, $zero, 0x54
    ctx->r25 = ADD32(0, 0X54);
    // 0x80800A68: addiu       $a1, $zero, 0xFF9
    ctx->r5 = ADD32(0, 0XFF9);
    // 0x80800A6C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80800A70: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800A74: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800A78: jal         0x8008A208
    // 0x80800A7C: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x80800A7C: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    after_9:
    // 0x80800A80: b           L_80800C20
    // 0x80800A84: nop

        goto L_80800C20;
    // 0x80800A84: nop

L_80800A88:
    // 0x80800A88: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800A8C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800A90: jal         0x80101E14
    // 0x80800A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_10;
    // 0x80800A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800A98: beq         $v0, $zero, L_80800C20
    if (ctx->r2 == 0) {
        // 0x80800A9C: nop
    
            goto L_80800C20;
    }
    // 0x80800A9C: nop

    // 0x80800AA0: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x80800AA4: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AAC: sll         $t1, $t0, 12
    ctx->r9 = S32(ctx->r8 << 12);
    // 0x80800AB0: srl         $t2, $t1, 31
    ctx->r10 = S32(U32(ctx->r9) >> 31);
    // 0x80800AB4: xori        $t4, $t2, 0x1
    ctx->r12 = ctx->r10 ^ 0X1;
    // 0x80800AB8: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80800ABC: andi        $t6, $t5, 0x8
    ctx->r14 = ctx->r13 & 0X8;
    // 0x80800AC0: andi        $t8, $t7, 0xFFF7
    ctx->r24 = ctx->r15 & 0XFFF7;
    // 0x80800AC4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80800AC8: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    // 0x80800ACC: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x80800AD0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800AD4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1020, 0X1620) << 16);
    // 0x80800AD8: sll         $t2, $t0, 12
    ctx->r10 = S32(ctx->r8 << 12);
    // 0x80800ADC: bgez        $t2, L_80800C20
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800AE0: nop
    
            goto L_80800C20;
    }
    // 0x80800AE0: nop

    // 0x80800AE4: jal         0x80089D18
    // 0x80800AE8: addiu       $a2, $a2, 0x1620
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1020, 0X1620));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800AE8: addiu       $a2, $a2, 0x1620
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1020, 0X1620));
    after_11:
    // 0x80800AEC: b           L_80800C20
    // 0x80800AF0: nop

        goto L_80800C20;
    // 0x80800AF0: nop

L_80800AF4:
    // 0x80800AF4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1020, 0X162C) << 16);
    // 0x80800AF8: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800AFC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800B00: addiu       $a2, $a2, 0x162C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1020, 0X162C));
    // 0x80800B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B08: jal         0x80089D20
    // 0x80800B0C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x80800B0C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_12:
    // 0x80800B10: jal         0x80101DDC
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_13;
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800B18: beq         $v0, $zero, L_80800C20
    if (ctx->r2 == 0) {
        // 0x80800B1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C20;
    }
    // 0x80800B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B20: jal         0x80102424
    // 0x80800B24: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x80800B24: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_14:
    // 0x80800B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B2C: jal         0x8008A4B0
    // 0x80800B30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_15;
    // 0x80800B30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800B34: jal         0x800DA544
    // 0x80800B38: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    func_800DA544(rdram, ctx);
        goto after_16;
    // 0x80800B38: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    after_16:
    // 0x80800B3C: jal         0x80106790
    // 0x80800B40: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_17;
    // 0x80800B40: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_17:
    // 0x80800B44: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80800B48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B4C: jal         0x80102424
    // 0x80800B50: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_18;
    // 0x80800B50: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_18:
    // 0x80800B54: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800B58: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1020, 0X1638) << 16);
    // 0x80800B5C: addiu       $a2, $a2, 0x1638
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1020, 0X1638));
    // 0x80800B60: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800B64: jal         0x80089D18
    // 0x80800B68: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_19;
    // 0x80800B68: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_19:
    // 0x80800B6C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800B70: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800B74: jal         0x80800808
    // 0x80800B78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800808_chtiptup(rdram, ctx);
        goto after_20;
    // 0x80800B78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_20:
    // 0x80800B7C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80800B80: addiu       $t4, $zero, 0x54
    ctx->r12 = ADD32(0, 0X54);
    // 0x80800B84: addiu       $a1, $zero, 0xFFA
    ctx->r5 = ADD32(0, 0XFFA);
    // 0x80800B88: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80800B8C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800B90: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x80800B94: jal         0x8008A208
    // 0x80800B98: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_21;
    // 0x80800B98: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_21:
    // 0x80800B9C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800BA0: jal         0x8008A4B0
    // 0x80800BA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_22;
    // 0x80800BA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x80800BA8: b           L_80800C20
    // 0x80800BAC: nop

        goto L_80800C20;
    // 0x80800BAC: nop

L_80800BB0:
    // 0x80800BB0: jal         0x80800E9C
    // 0x80800BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E9C_chtiptup(rdram, ctx);
        goto after_23;
    // 0x80800BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800BB8: jal         0x80101F24
    // 0x80800BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_24;
    // 0x80800BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800BC0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1020, 0X1644) << 16);
    // 0x80800BC4: addiu       $a1, $a1, 0x1644
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1020, 0X1644));
    // 0x80800BC8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800BCC: jal         0x800F3780
    // 0x80800BD0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800F3780(rdram, ctx);
        goto after_25;
    // 0x80800BD0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_25:
    // 0x80800BD4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800BD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BE0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800BE4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800BE8: jal         0x80105A9C
    // 0x80800BEC: nop

    func_80105A9C(rdram, ctx);
        goto after_26;
    // 0x80800BEC: nop

    after_26:
    // 0x80800BF0: jal         0x80105854
    // 0x80800BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105854(rdram, ctx);
        goto after_27;
    // 0x80800BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80800BF8: b           L_80800C20
    // 0x80800BFC: nop

        goto L_80800C20;
    // 0x80800BFC: nop

L_80800C00:
    // 0x80800C00: jal         0x80800E2C
    // 0x80800C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E2C_chtiptup(rdram, ctx);
        goto after_28;
    // 0x80800C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800C08: jal         0x80101DDC
    // 0x80800C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_29;
    // 0x80800C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80800C10: beq         $v0, $zero, L_80800C20
    if (ctx->r2 == 0) {
        // 0x80800C14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C20;
    }
    // 0x80800C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C18: jal         0x80102424
    // 0x80800C1C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_30;
    // 0x80800C1C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_30:
L_80800C20:
    // 0x80800C20: jal         0x800F54E4
    // 0x80800C24: nop

    func_800F54E4(rdram, ctx);
        goto after_31;
    // 0x80800C24: nop

    after_31:
    // 0x80800C28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C2C: jal         0x800F52B8
    // 0x80800C30: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800F52B8(rdram, ctx);
        goto after_32;
    // 0x80800C30: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_32:
    // 0x80800C34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C38: beql        $v0, $at, L_80800C60
    if (ctx->r2 == ctx->r1) {
        // 0x80800C3C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800C60;
    }
    goto skip_0;
    // 0x80800C3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800C40: jal         0x800F54E4
    // 0x80800C44: nop

    func_800F54E4(rdram, ctx);
        goto after_33;
    // 0x80800C44: nop

    after_33:
    // 0x80800C48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C4C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800C50: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800C54: jal         0x800F4F34
    // 0x80800C58: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    func_800F4F34(rdram, ctx);
        goto after_34;
    // 0x80800C58: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    after_34:
L_80800C5C:
    // 0x80800C5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C60:
    // 0x80800C60: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800C64: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800C68: jr          $ra
    // 0x80800C6C: nop

    return;
    // 0x80800C6C: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A78: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A78);
    return;
    // 0x80082A7C: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void func_80800BB8_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BBC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800BC0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800BC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BC8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80800BCC: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
L_80800BD0:
    // 0x80800BD0: jal         0x800D3DD0
    // 0x80800BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D3DD0(rdram, ctx);
        goto after_0;
    // 0x80800BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800BD8: bnel        $v0, $zero, L_80800BEC
    if (ctx->r2 != 0) {
        // 0x80800BDC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800BEC;
    }
    goto skip_0;
    // 0x80800BDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80800BE0: b           L_80800BF8
    // 0x80800BE4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80800BF8;
    // 0x80800BE4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800BE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800BEC:
    // 0x80800BEC: bne         $s0, $s1, L_80800BD0
    if (ctx->r16 != ctx->r17) {
        // 0x80800BF0: nop
    
            goto L_80800BD0;
    }
    // 0x80800BF0: nop

    // 0x80800BF4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800BF8:
    // 0x80800BF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BFC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800C00: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800C04: jr          $ra
    // 0x80800C08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800C08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800114_glglobalsettings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800118: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080011C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800120: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800124: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800128: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080012C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800130: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_80800134:
    // 0x80800134: beql        $s0, $s1, L_80800148
    if (ctx->r16 == ctx->r17) {
        // 0x80800138: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800148;
    }
    goto skip_0;
    // 0x80800138: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8080013C: jal         0x800884D0
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _glgamestore_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800144: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800148:
    // 0x80800148: bne         $s0, $s2, L_80800134
    if (ctx->r16 != ctx->r18) {
        // 0x8080014C: nop
    
            goto L_80800134;
    }
    // 0x8080014C: nop

    // 0x80800150: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800154: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800158: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080015C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800160: jr          $ra
    // 0x80800164: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800164: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void gcmapsects_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801A58: jal         0x800BF704
    // 0x80801A5C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800BF704(rdram, ctx);
        goto after_0;
    // 0x80801A5C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801A60: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80801A64: sb          $t6, 0x79($v0)
    MEM_B(0X79, ctx->r2) = ctx->r14;
    // 0x80801A68: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A6C: sb          $t7, 0x7D($v0)
    MEM_B(0X7D, ctx->r2) = ctx->r15;
    // 0x80801A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A78: jr          $ra
    // 0x80801A7C: nop

    return;
    // 0x80801A7C: nop

;}
RECOMP_FUNC void func_8080006C_glgamestore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080006C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800074: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800078: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080007C: jal         0x80088510
    // 0x80800080: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _gleeprom_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800080: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800084: beq         $v0, $zero, L_80800090
    if (ctx->r2 == 0) {
        // 0x80800088: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800090;
    }
    // 0x80800088: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080008C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80800090:
    // 0x80800090: bne         $v1, $zero, L_808000A4
    if (ctx->r3 != 0) {
        // 0x80800094: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_808000A4;
    }
    // 0x80800094: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800098: jal         0x80800000
    // 0x8080009C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800000_glgamestore(rdram, ctx);
        goto after_1;
    // 0x8080009C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x808000A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808000A4:
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
RECOMP_FUNC void func_80800514_chbanjocurrent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800514: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800518: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080051C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800520: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800524: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800528: jal         0x800EEF94
    // 0x8080052C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_800EEF94(rdram, ctx);
        goto after_0;
    // 0x8080052C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800530: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800534: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(756, 0X7B8) << 16);
    // 0x80800538: lwc1        $f8, 0x7B8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(756, 0X7B8));
    // 0x8080053C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80800540: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800544: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800548: jal         0x800136D0
    // 0x8080054C: nop

    func_800136D0(rdram, ctx);
        goto after_1;
    // 0x8080054C: nop

    after_1:
    // 0x80800550: jal         0x800137D4
    // 0x80800554: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800137D4(rdram, ctx);
        goto after_2;
    // 0x80800554: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x80800558: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8080055C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800560: nop

    // 0x80800564: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800568: jal         0x80013788
    // 0x8080056C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_80013788(rdram, ctx);
        goto after_3;
    // 0x8080056C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80800570: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800574: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800578: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(756, 0X7BC) << 16);
    // 0x8080057C: lwc1        $f6, 0x7BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(756, 0X7BC));
    // 0x80800580: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800584: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800588: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080058C: nop

    // 0x80800590: c.eq.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl == ctx->f8.fl;
    // 0x80800594: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800598: bc1t        L_808005C4
    if (c1cs) {
        // 0x8080059C: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_808005C4;
    }
    // 0x8080059C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x808005A0: div.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    // 0x808005A4: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808005A8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x808005AC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x808005B0: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x808005B4: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808005B8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x808005BC: b           L_808005E0
    // 0x808005C0: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
        goto L_808005E0;
    // 0x808005C0: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
L_808005C4:
    // 0x808005C4: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808005C8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x808005CC: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x808005D0: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x808005D4: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808005D8: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x808005DC: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
L_808005E0:
    // 0x808005E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005E4: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808005E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005EC: jr          $ra
    // 0x808005F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808005F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800A8EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8EF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A8EF4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A8EF8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A8EFC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A8F00: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800A8F04: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A8F08: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A8F0C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800A8F10: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800A8F14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A8F18: addiu       $s1, $s1, 0x76F0
    ctx->r17 = ADD32(ctx->r17, 0X76F0);
    // 0x800A8F1C: addiu       $s0, $s0, 0x76D0
    ctx->r16 = ADD32(ctx->r16, 0X76D0);
    // 0x800A8F20: lw          $a1, 0x58($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X58);
L_800A8F24:
    // 0x800A8F24: beql        $a1, $zero, L_800A8F44
    if (ctx->r5 == 0) {
        // 0x800A8F28: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800A8F44;
    }
    goto skip_0;
    // 0x800A8F28: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800A8F2C: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x800A8F30: bnel        $s2, $t6, L_800A8F44
    if (ctx->r18 != ctx->r14) {
        // 0x800A8F34: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800A8F44;
    }
    goto skip_1;
    // 0x800A8F34: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x800A8F38: jal         0x8010FAEC
    // 0x800A8F3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8010FAEC(rdram, ctx);
        goto after_0;
    // 0x800A8F3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x800A8F40: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800A8F44:
    // 0x800A8F44: bnel        $s0, $s1, L_800A8F24
    if (ctx->r16 != ctx->r17) {
        // 0x800A8F48: lw          $a1, 0x58($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X58);
            goto L_800A8F24;
    }
    goto skip_2;
    // 0x800A8F48: lw          $a1, 0x58($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X58);
    skip_2:
    // 0x800A8F4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A8F50: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A8F54: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A8F58: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800A8F5C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800A8F60: jr          $ra
    // 0x800A8F64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A8F64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _suflamefx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089928: syscall     798
    recomp_syscall_handler(rdram, ctx, 0x80089928);
    return;
    // 0x8008992C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void subaddietaxi_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AC4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800AC8: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80800ACC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800AD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800AD4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800AD8: nop

    // 0x80800ADC: bc1f        L_80800AE8
    if (!c1cs) {
        // 0x80800AE0: nop
    
            goto L_80800AE8;
    }
    // 0x80800AE0: nop

    // 0x80800AE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AE8:
    // 0x80800AE8: jr          $ra
    // 0x80800AEC: nop

    return;
    // 0x80800AEC: nop

;}
RECOMP_FUNC void func_808003D0_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003D8: jal         0x808004B8
    // 0x808003DC: nop

    bsbabykaz_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808003DC: nop

    after_0:
    // 0x808003E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003E8: jr          $ra
    // 0x808003EC: nop

    return;
    // 0x808003EC: nop

;}
RECOMP_FUNC void func_800FA874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA874: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800FA878: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800FA87C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800FA880: addiu       $t7, $t7, 0x3880
    ctx->r15 = ADD32(ctx->r15, 0X3880);
    // 0x800FA884: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800FA888: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800FA88C: lw          $a2, 0x18($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X18);
    // 0x800FA890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FA894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FA898: beq         $a2, $zero, L_800FA8AC
    if (ctx->r6 == 0) {
        // 0x800FA89C: nop
    
            goto L_800FA8AC;
    }
    // 0x800FA89C: nop

    // 0x800FA8A0: lb          $t8, 0xE($v1)
    ctx->r24 = MEM_B(ctx->r3, 0XE);
    // 0x800FA8A4: beql        $a1, $t8, L_800FA8B8
    if (ctx->r5 == ctx->r24) {
        // 0x800FA8A8: lbu         $v0, 0xC($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0XC);
            goto L_800FA8B8;
    }
    goto skip_0;
    // 0x800FA8A8: lbu         $v0, 0xC($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XC);
    skip_0:
L_800FA8AC:
    // 0x800FA8AC: b           L_800FA8D8
    // 0x800FA8B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FA8D8;
    // 0x800FA8B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FA8B4: lbu         $v0, 0xC($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XC);
L_800FA8B8:
    // 0x800FA8B8: xori        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 ^ 0X2;
    // 0x800FA8BC: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800FA8C0: beql        $v0, $zero, L_800FA8DC
    if (ctx->r2 == 0) {
        // 0x800FA8C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FA8DC;
    }
    goto skip_1;
    // 0x800FA8C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800FA8C8: jal         0x8008A630
    // 0x800FA8CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    _scinfobar_entrypoint_22(rdram, ctx);
        goto after_0;
    // 0x800FA8CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800FA8D0: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x800FA8D4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_800FA8D8:
    // 0x800FA8D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FA8DC:
    // 0x800FA8DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FA8E0: jr          $ra
    // 0x800FA8E4: nop

    return;
    // 0x800FA8E4: nop

;}
RECOMP_FUNC void func_800BDCDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDCDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BDCE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BDCE4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BDCE8: jal         0x80087C78
    // 0x800BDCEC: addiu       $a0, $a0, -0x7BF0
    ctx->r4 = ADD32(ctx->r4, -0X7BF0);
    _gccubeDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x800BDCEC: addiu       $a0, $a0, -0x7BF0
    ctx->r4 = ADD32(ctx->r4, -0X7BF0);
    after_0:
    // 0x800BDCF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BDCF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BDCF8: jr          $ra
    // 0x800BDCFC: nop

    return;
    // 0x800BDCFC: nop

;}
RECOMP_FUNC void func_801121D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801121D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801121DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801121E0: jal         0x80110840
    // 0x801121E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x801121E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801121E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801121EC: jal         0x800F5A00
    // 0x801121F0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x801121F0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x801121F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801121F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801121FC: jr          $ra
    // 0x80112200: nop

    return;
    // 0x80112200: nop

;}
RECOMP_FUNC void func_80800124_cheggclockwork(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800128: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080012C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800130: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800134: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800138: jal         0x80100094
    // 0x8080013C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080013C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800140: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800144: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800148: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080014C: jal         0x8008A3C0
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _suegg_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800154: beq         $v0, $zero, L_80800180
    if (ctx->r2 == 0) {
        // 0x80800158: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80800180;
    }
    // 0x80800158: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8080015C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800160: jal         0x800F693C
    // 0x80800164: lh          $a0, 0x3A($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X3A);
    func_800F693C(rdram, ctx);
        goto after_2;
    // 0x80800164: lh          $a0, 0x3A($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X3A);
    after_2:
    // 0x80800168: beq         $v0, $zero, L_80800178
    if (ctx->r2 == 0) {
        // 0x8080016C: nop
    
            goto L_80800178;
    }
    // 0x8080016C: nop

    // 0x80800170: b           L_80800214
    // 0x80800174: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
        goto L_80800214;
    // 0x80800174: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_80800178:
    // 0x80800178: b           L_80800214
    // 0x8080017C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80800214;
    // 0x8080017C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80800180:
    // 0x80800180: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800184: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800188: lwc1        $f12, 0x30($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X30);
    // 0x8080018C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800190: lui         $a2, 0x3E09
    ctx->r6 = S32(0X3E09 << 16);
    // 0x80800194: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80800198: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080019C: ori         $a2, $a2, 0x374C
    ctx->r6 = ctx->r6 | 0X374C;
    // 0x808001A0: jal         0x800F10B4
    // 0x808001A4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x808001A4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x808001A8: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
    // 0x808001AC: jal         0x8008A450
    // 0x808001B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _sueggmove_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x808001B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x808001B4: beq         $v0, $zero, L_808001C8
    if (ctx->r2 == 0) {
        // 0x808001B8: nop
    
            goto L_808001C8;
    }
    // 0x808001B8: nop

    // 0x808001BC: jal         0x8008A430
    // 0x808001C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _suegg_entrypoint_23(rdram, ctx);
        goto after_5;
    // 0x808001C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x808001C4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_808001C8:
    // 0x808001C8: jal         0x800EEEA8
    // 0x808001CC: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    func_800EEEA8(rdram, ctx);
        goto after_6;
    // 0x808001CC: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    after_6:
    // 0x808001D0: beq         $v0, $zero, L_808001DC
    if (ctx->r2 == 0) {
        // 0x808001D4: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_808001DC;
    }
    // 0x808001D4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x808001D8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_808001DC:
    // 0x808001DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001E4: lwc1        $f8, 0x30($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X30);
    // 0x808001E8: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x808001EC: nop

    // 0x808001F0: bc1f        L_80800204
    if (!c1cs) {
        // 0x808001F4: nop
    
            goto L_80800204;
    }
    // 0x808001F4: nop

    // 0x808001F8: jal         0x8008A390
    // 0x808001FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _suegg_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x808001FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80800200: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_80800204:
    // 0x80800204: jal         0x80800048
    // 0x80800208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800048_cheggclockwork(rdram, ctx);
        goto after_8;
    // 0x80800208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8080020C: jal         0x8008A3F8
    // 0x80800210: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _suegg_entrypoint_16(rdram, ctx);
        goto after_9;
    // 0x80800210: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
L_80800214:
    // 0x80800214: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800218: beq         $s0, $at, L_80800228
    if (ctx->r16 == ctx->r1) {
        // 0x8080021C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800228;
    }
    // 0x8080021C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800220: bne         $s0, $at, L_8080023C
    if (ctx->r16 != ctx->r1) {
        // 0x80800224: nop
    
            goto L_8080023C;
    }
    // 0x80800224: nop

L_80800228:
    // 0x80800228: jal         0x80800270
    // 0x8080022C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800270_cheggclockwork(rdram, ctx);
        goto after_10;
    // 0x8080022C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80800230: bne         $v0, $zero, L_8080023C
    if (ctx->r2 != 0) {
        // 0x80800234: nop
    
            goto L_8080023C;
    }
    // 0x80800234: nop

    // 0x80800238: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_8080023C:
    // 0x8080023C: beq         $s0, $zero, L_80800254
    if (ctx->r16 == 0) {
        // 0x80800240: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800254;
    }
    // 0x80800240: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800244: jal         0x80108B04
    // 0x80800248: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80108B04(rdram, ctx);
        goto after_11;
    // 0x80800248: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x8080024C: b           L_80800260
    // 0x80800250: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800260;
    // 0x80800250: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800254:
    // 0x80800254: jal         0x80800850
    // 0x80800258: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800850_cheggclockwork(rdram, ctx);
        goto after_12;
    // 0x80800258: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x8080025C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800260:
    // 0x80800260: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800264: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800268: jr          $ra
    // 0x8080026C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080026C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _bainvisible_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800854E0: syscall     164
    recomp_syscall_handler(rdram, ctx, 0x800854E0);
    return;
    // 0x800854E4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _bavan_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800853A8: syscall     159
    recomp_syscall_handler(rdram, ctx, 0x800853A8);
    return;
    // 0x800853AC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800024_chbilldrillplate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: jal         0x80800FCC
    // 0x80800030: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800FCC_chbilldrillplate(rdram, ctx);
        goto after_0;
    // 0x80800030: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800034: jal         0x800DA298
    // 0x80800038: lhu         $a0, 0xC($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XC);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800038: lhu         $a0, 0xC($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XC);
    after_1:
    // 0x8080003C: beq         $v0, $zero, L_80800054
    if (ctx->r2 == 0) {
        // 0x80800040: nop
    
            goto L_80800054;
    }
    // 0x80800040: nop

    // 0x80800044: jal         0x800FFAB0
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080004C: b           L_808000A4
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000A4;
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800054:
    // 0x80800054: jal         0x80089D00
    // 0x80800058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _subaddiefade_entrypoint_14(rdram, ctx);
        goto after_3;
    // 0x80800058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8080005C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800060: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800064: jal         0x800DC298
    // 0x80800068: nop

    func_800DC298(rdram, ctx);
        goto after_4;
    // 0x80800068: nop

    after_4:
    // 0x8080006C: beq         $v0, $zero, L_80800084
    if (ctx->r2 == 0) {
        // 0x80800070: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800084;
    }
    // 0x80800070: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800074: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800078: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080007C: b           L_80800090
    // 0x80800080: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
        goto L_80800090;
    // 0x80800080: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
L_80800084:
    // 0x80800084: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800088: nop

    // 0x8080008C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
L_80800090:
    // 0x80800090: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800094: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800098: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080009C: swc1        $f6, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f6.u32l;
    // 0x808000A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000A4:
    // 0x808000A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A8: jr          $ra
    // 0x808000AC: nop

    return;
    // 0x808000AC: nop

;}
RECOMP_FUNC void _baswim_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085288: syscall     156
    recomp_syscall_handler(rdram, ctx, 0x80085288);
    return;
    // 0x8008528C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bskaztorpedo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083760: syscall     72
    recomp_syscall_handler(rdram, ctx, 0x80083760);
    return;
    // 0x80083764: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80809EF8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809EF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80809EFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80809F00: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80809F04: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80809F08: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80809F0C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80809F10: jal         0x800EE7F8
    // 0x80809F14: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80809F14: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80809F18: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80809F1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80809F20: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80809F24: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80809F28: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80809F2C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80809F30: jal         0x800EE7F8
    // 0x80809F34: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80809F34: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80809F38: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80809F3C: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x80809F40: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80809F44: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80809F48: lui         $a3, 0x802
    ctx->r7 = S32(0X802 << 16);
    // 0x80809F4C: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x80809F50: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80809F54: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80809F58: swc1        $f18, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f18.u32l;
    // 0x80809F5C: jal         0x800BEF00
    // 0x80809F60: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_800BEF00(rdram, ctx);
        goto after_2;
    // 0x80809F60: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80809F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80809F68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80809F6C: jr          $ra
    // 0x80809F70: nop

    return;
    // 0x80809F70: nop

;}
RECOMP_FUNC void gcgoto_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080004C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800050: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800054: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800058: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080005C: addiu       $at, $zero, 0xFB
    ctx->r1 = ADD32(0, 0XFB);
    // 0x80800060: bne         $t6, $at, L_8080010C
    if (ctx->r14 != ctx->r1) {
        // 0x80800064: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(2570, 0X710) << 16);
            goto L_8080010C;
    }
    // 0x80800064: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2570, 0X710) << 16);
    // 0x80800068: lh          $a1, 0x2($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X2);
    // 0x8080006C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800070: jal         0x80800000
    // 0x80800074: addiu       $a0, $a0, 0x710
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2570, 0X710));
    func_80800000_gcgoto(rdram, ctx);
        goto after_0;
    // 0x80800074: addiu       $a0, $a0, 0x710
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2570, 0X710));
    after_0:
    // 0x80800078: beq         $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x8080007C: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8080008C;
    }
    // 0x8080007C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800080: addiu       $t8, $zero, 0x1A7
    ctx->r24 = ADD32(0, 0X1A7);
    // 0x80800084: b           L_8080010C
    // 0x80800088: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
        goto L_8080010C;
    // 0x80800088: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_8080008C:
    // 0x8080008C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800090: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2570, 0X720) << 16);
    // 0x80800094: addiu       $a0, $a0, 0x720
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2570, 0X720));
    // 0x80800098: lh          $a1, 0x2($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X2);
    // 0x8080009C: jal         0x80800000
    // 0x808000A0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80800000_gcgoto(rdram, ctx);
        goto after_1;
    // 0x808000A0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x808000A4: beq         $v0, $zero, L_808000B8
    if (ctx->r2 == 0) {
        // 0x808000A8: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_808000B8;
    }
    // 0x808000A8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808000AC: addiu       $t0, $zero, 0x1A8
    ctx->r8 = ADD32(0, 0X1A8);
    // 0x808000B0: b           L_8080010C
    // 0x808000B4: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
        goto L_8080010C;
    // 0x808000B4: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
L_808000B8:
    // 0x808000B8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x808000BC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2570, 0X72C) << 16);
    // 0x808000C0: addiu       $a0, $a0, 0x72C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2570, 0X72C));
    // 0x808000C4: lh          $a1, 0x2($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X2);
    // 0x808000C8: jal         0x80800000
    // 0x808000CC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80800000_gcgoto(rdram, ctx);
        goto after_2;
    // 0x808000CC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x808000D0: beq         $v0, $zero, L_808000E4
    if (ctx->r2 == 0) {
        // 0x808000D4: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_808000E4;
    }
    // 0x808000D4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808000D8: addiu       $t2, $zero, 0x1A9
    ctx->r10 = ADD32(0, 0X1A9);
    // 0x808000DC: b           L_8080010C
    // 0x808000E0: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
        goto L_8080010C;
    // 0x808000E0: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
L_808000E4:
    // 0x808000E4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x808000E8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2570, 0X73C) << 16);
    // 0x808000EC: addiu       $a0, $a0, 0x73C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2570, 0X73C));
    // 0x808000F0: lh          $a1, 0x2($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X2);
    // 0x808000F4: jal         0x80800000
    // 0x808000F8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80800000_gcgoto(rdram, ctx);
        goto after_3;
    // 0x808000F8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_3:
    // 0x808000FC: beq         $v0, $zero, L_8080010C
    if (ctx->r2 == 0) {
        // 0x80800100: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8080010C;
    }
    // 0x80800100: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800104: addiu       $t4, $zero, 0x1A6
    ctx->r12 = ADD32(0, 0X1A6);
    // 0x80800108: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
L_8080010C:
    // 0x8080010C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800114: jr          $ra
    // 0x80800118: nop

    return;
    // 0x80800118: nop

;}
RECOMP_FUNC void _ncbafly_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800892E8: syscall     771
    recomp_syscall_handler(rdram, ctx, 0x800892E8);
    return;
    // 0x800892EC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void bskazjump_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A44: jal         0x800A042C
    // 0x80800A48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A042C(rdram, ctx);
        goto after_0;
    // 0x80800A48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800A50: jal         0x80093360
    // 0x80800A54: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80093360(rdram, ctx);
        goto after_1;
    // 0x80800A54: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800A58: jal         0x8009E0DC
    // 0x80800A5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8009E0DC(rdram, ctx);
        goto after_2;
    // 0x80800A5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800A60: jal         0x800832E8
    // 0x80800A64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800A64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A70: jr          $ra
    // 0x80800A74: nop

    return;
    // 0x80800A74: nop

;}
RECOMP_FUNC void _chcactusofstrength_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C30: syscall     211
    recomp_syscall_handler(rdram, ctx, 0x80085C30);
    return;
    // 0x80085C34: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80114EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114EEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80114EF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80114EF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80114EF8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80114EFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80114F00: jal         0x80013970
    // 0x80114F04: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    func_80013970(rdram, ctx);
        goto after_0;
    // 0x80114F04: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    after_0:
    // 0x80114F08: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80114F0C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80114F10: nop

    // 0x80114F14: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80114F18: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80114F1C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80114F20: mul.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80114F24: jal         0x80013970
    // 0x80114F28: nop

    func_80013970(rdram, ctx);
        goto after_1;
    // 0x80114F28: nop

    after_1:
    // 0x80114F2C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80114F30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80114F34: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80114F38: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80114F3C: jal         0x800EA068
    // 0x80114F40: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    func_800EA068(rdram, ctx);
        goto after_2;
    // 0x80114F40: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80114F44: bnel        $v0, $zero, L_80114F94
    if (ctx->r2 != 0) {
        // 0x80114F48: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80114F94;
    }
    goto skip_0;
    // 0x80114F48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80114F4C: jal         0x80110014
    // 0x80114F50: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_80110014(rdram, ctx);
        goto after_3;
    // 0x80114F50: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x80114F54: jal         0x80110840
    // 0x80114F58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110840(rdram, ctx);
        goto after_4;
    // 0x80114F58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80114F5C: jal         0x800A940C
    // 0x80114F60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A940C(rdram, ctx);
        goto after_5;
    // 0x80114F60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80114F64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80114F68: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80114F6C: jal         0x800C4B90
    // 0x80114F70: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800C4B90(rdram, ctx);
        goto after_6;
    // 0x80114F70: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80114F74: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80114F78: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80114F7C: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80114F80: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80114F84: sb          $t6, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r14;
    // 0x80114F88: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80114F8C: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x80114F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80114F94:
    // 0x80114F94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80114F98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80114F9C: jr          $ra
    // 0x80114FA0: nop

    return;
    // 0x80114FA0: nop

;}
RECOMP_FUNC void func_800A57EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A57EC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A57F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A57F4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800A57F8: jr          $ra
    // 0x800A57FC: lw          $v0, -0x6AE4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6AE4);
    return;
    // 0x800A57FC: lw          $v0, -0x6AE4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6AE4);
;}
RECOMP_FUNC void func_8080000C_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lw          $v0, 0x168($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X168);
    // 0x80800010: blez        $v0, L_8080001C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800014: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8080001C;
    }
    // 0x80800014: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80800018: sw          $t6, 0x168($a0)
    MEM_W(0X168, ctx->r4) = ctx->r14;
L_8080001C:
    // 0x8080001C: jr          $ra
    // 0x80800020: nop

    return;
    // 0x80800020: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800829D0: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x800829D0);
    return;
    // 0x800829D4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800C316C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C316C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3170: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C3174: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3178: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C317C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3180: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C3184: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C3188: beq         $t6, $zero, L_800C31CC
    if (ctx->r14 == 0) {
        // 0x800C318C: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_800C31CC;
    }
    // 0x800C318C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C3190: jal         0x800C1414
    // 0x800C3194: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3194: nop

    after_0:
    // 0x800C3198: lbu         $t8, 0x7B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7B);
    // 0x800C319C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C31A0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800C31A4: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x800C31A8: sb          $t9, 0x7B($v0)
    MEM_B(0X7B, ctx->r2) = ctx->r25;
    // 0x800C31AC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800C31B0: sh          $t0, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r8;
    // 0x800C31B4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800C31B8: sh          $t1, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r9;
    // 0x800C31BC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C31C0: sh          $zero, 0x5A($v0)
    MEM_H(0X5A, ctx->r2) = 0;
    // 0x800C31C4: jal         0x800C13A0
    // 0x800C31C8: swc1        $f4, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f4.u32l;
    func_800C13A0(rdram, ctx);
        goto after_1;
    // 0x800C31C8: swc1        $f4, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f4.u32l;
    after_1:
L_800C31CC:
    // 0x800C31CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C31D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C31D4: jr          $ra
    // 0x800C31D8: nop

    return;
    // 0x800C31D8: nop

;}
RECOMP_FUNC void func_800A0DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0DD0: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800A0DD4: jr          $ra
    // 0x800A0DD8: sb          $a1, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r5;
    return;
    // 0x800A0DD8: sb          $a1, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void _gcegg_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800883B8: syscall     680
    recomp_syscall_handler(rdram, ctx, 0x800883B8);
    return;
    // 0x800883BC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808004FC_chwallsnakebaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800500: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800504: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800508: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8080050C: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x80800510: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800514: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80800518: jal         0x8010A570
    // 0x8080051C: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    func_8010A570(rdram, ctx);
        goto after_0;
    // 0x8080051C: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    after_0:
    // 0x80800520: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x80800524: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800528: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080052C: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800530: bne         $t0, $at, L_80800540
    if (ctx->r8 != ctx->r1) {
        // 0x80800534: nop
    
            goto L_80800540;
    }
    // 0x80800534: nop

    // 0x80800538: b           L_80800540
    // 0x8080053C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
        goto L_80800540;
    // 0x8080053C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80800540:
    // 0x80800540: jal         0x80102424
    // 0x80800544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800548: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080054C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1856, 0X79C) << 16);
    // 0x80800550: addiu       $a2, $a2, 0x79C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1856, 0X79C));
    // 0x80800554: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800558: jal         0x80089D18
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800560: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1856, 0X7A8) << 16);
    // 0x80800564: addiu       $a2, $a2, 0x7A8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1856, 0X7A8));
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080056C: jal         0x80089D18
    // 0x80800570: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800570: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80800574: jal         0x8010A430
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A430(rdram, ctx);
        goto after_4;
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080057C: beq         $v0, $zero, L_808005C4
    if (ctx->r2 == 0) {
        // 0x80800580: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_808005C4;
    }
    // 0x80800580: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800584: jal         0x800EE7F8
    // 0x80800588: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800588: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x8080058C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800590: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800594: jal         0x800EF1B8
    // 0x80800598: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x80800598: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    after_6:
    // 0x8080059C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x808005A0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808005A4: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x808005A8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808005AC: lw          $t2, 0x48($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X48);
    // 0x808005B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808005B4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808005B8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x808005BC: jal         0x80086D50
    // 0x808005C0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x808005C0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_7:
L_808005C4:
    // 0x808005C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808005D0: jr          $ra
    // 0x808005D4: nop

    return;
    // 0x808005D4: nop

;}
RECOMP_FUNC void func_80095C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095C34: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80095C38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80095C3C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80095C40: mov.s       $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    ctx->f20.fl = ctx->f14.fl;
    // 0x80095C44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80095C48: bc1f        L_80095C64
    if (!c1cs) {
        // 0x80095C4C: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80095C64;
    }
    // 0x80095C4C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80095C50: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80095C54: jal         0x800F13F0
    // 0x80095C58: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
    func_800F13F0(rdram, ctx);
        goto after_0;
    // 0x80095C58: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
    after_0:
    // 0x80095C5C: b           L_80095C80
    // 0x80095C60: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_80095C80;
    // 0x80095C60: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80095C64:
    // 0x80095C64: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
    // 0x80095C68: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80095C6C: bc1fl       L_80095C84
    if (!c1cs) {
        // 0x80095C70: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80095C84;
    }
    goto skip_0;
    // 0x80095C70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80095C74: jal         0x800F0E00
    // 0x80095C78: sub.s       $f14, $f20, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f6.fl;
    func_800F0E00(rdram, ctx);
        goto after_1;
    // 0x80095C78: sub.s       $f14, $f20, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f6.fl;
    after_1:
    // 0x80095C7C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80095C80:
    // 0x80095C80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80095C84:
    // 0x80095C84: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x80095C88: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80095C8C: jr          $ra
    // 0x80095C90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80095C90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _bsrest_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800839A8: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x800839A8);
    return;
    // 0x800839AC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_808000E0_chLagoonInnBlockedWall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808000E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000E8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808000EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000F4: beq         $a1, $at, L_80800164
    if (ctx->r5 == ctx->r1) {
        // 0x808000F8: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_80800164;
    }
    // 0x808000F8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x808000FC: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800100: beq         $a1, $at, L_80800118
    if (ctx->r5 == ctx->r1) {
        // 0x80800104: addiu       $at, $zero, 0x90
        ctx->r1 = ADD32(0, 0X90);
            goto L_80800118;
    }
    // 0x80800104: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800108: beq         $a1, $at, L_808001BC
    if (ctx->r5 == ctx->r1) {
        // 0x8080010C: nop
    
            goto L_808001BC;
    }
    // 0x8080010C: nop

    // 0x80800110: b           L_8080023C
    // 0x80800114: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080023C;
    // 0x80800114: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800118:
    // 0x80800118: jal         0x80088840
    // 0x8080011C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x8080011C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_0:
    // 0x80800120: beq         $v0, $zero, L_80800238
    if (ctx->r2 == 0) {
        // 0x80800124: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2020, 0X3E0) << 16);
            goto L_80800238;
    }
    // 0x80800124: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2020, 0X3E0) << 16);
    // 0x80800128: lwc1        $f4, 0x3E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2020, 0X3E0));
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800134: jal         0x80103110
    // 0x80800138: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x80800138: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800140: jal         0x80101FDC
    // 0x80800144: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800144: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800148: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080014C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800150: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80800154: jal         0x80085708
    // 0x80800158: addiu       $a3, $zero, 0x910
    ctx->r7 = ADD32(0, 0X910);
    _capod_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80800158: addiu       $a3, $zero, 0x910
    ctx->r7 = ADD32(0, 0X910);
    after_3:
    // 0x8080015C: b           L_8080023C
    // 0x80800160: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080023C;
    // 0x80800160: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800164:
    // 0x80800164: jal         0x8010A570
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080016C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800170: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800174: jal         0x800EE7F8
    // 0x80800178: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800178: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x8080017C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800180: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800184: jal         0x800EF1B8
    // 0x80800188: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x80800188: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_6:
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800190: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800194: jal         0x80086670
    // 0x80800198: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x80800198: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_7:
    // 0x8080019C: jal         0x800F54E4
    // 0x808001A0: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x808001A0: nop

    after_8:
    // 0x808001A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808001AC: jal         0x800F8300
    // 0x808001B0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800F8300(rdram, ctx);
        goto after_9;
    // 0x808001B0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_9:
    // 0x808001B4: b           L_8080023C
    // 0x808001B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080023C;
    // 0x808001B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001BC:
    // 0x808001BC: jal         0x800EA05C
    // 0x808001C0: nop

    func_800EA05C(rdram, ctx);
        goto after_10;
    // 0x808001C0: nop

    after_10:
    // 0x808001C4: addiu       $at, $zero, 0xED
    ctx->r1 = ADD32(0, 0XED);
    // 0x808001C8: bne         $v0, $at, L_808001F4
    if (ctx->r2 != ctx->r1) {
        // 0x808001CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F4;
    }
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: jal         0x80101FDC
    // 0x808001D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x808001D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: jal         0x80103110
    // 0x808001E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_12;
    // 0x808001E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x808001E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2020, 0X3E4) << 16);
    // 0x808001E8: lwc1        $f6, 0x3E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2020, 0X3E4));
    // 0x808001EC: b           L_808001FC
    // 0x808001F0: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_808001FC;
    // 0x808001F0: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_808001F4:
    // 0x808001F4: jal         0x800FFAB0
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_13;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
L_808001FC:
    // 0x808001FC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2020, 0X400) << 16);
    // 0x80800200: addiu       $t6, $t6, 0x400
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2020, 0X400));
    // 0x80800204: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800208: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x8080020C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800210: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800214: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800218: jal         0x800BABB8
    // 0x8080021C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_14;
    // 0x8080021C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x80800220: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2020, 0X46C) << 16);
    // 0x80800224: addiu       $a1, $a1, 0x46C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2020, 0X46C));
    // 0x80800228: jal         0x800C4AF0
    // 0x8080022C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800C4AF0(rdram, ctx);
        goto after_15;
    // 0x8080022C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_15:
    // 0x80800230: b           L_8080023C
    // 0x80800234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080023C;
    // 0x80800234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800238:
    // 0x80800238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080023C:
    // 0x8080023C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800240: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800244: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800248: jr          $ra
    // 0x8080024C: nop

    return;
    // 0x8080024C: nop

;}
RECOMP_FUNC void func_800E7CF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7CF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E7CF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E7CFC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800E7D00: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800E7D04: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x800E7D08: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800E7D0C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800E7D10: lh          $t7, 0x7750($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7750);
    // 0x800E7D14: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800E7D18: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800E7D1C: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x800E7D20: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800E7D24: jal         0x800A989C
    // 0x800E7D28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800A989C(rdram, ctx);
        goto after_0;
    // 0x800E7D28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800E7D2C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800E7D30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E7D34: addu        $t1, $v0, $at
    ctx->r9 = ADD32(ctx->r2, ctx->r1);
    // 0x800E7D38: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800E7D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E7D40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E7D44: jr          $ra
    // 0x800E7D48: nop

    return;
    // 0x800E7D48: nop

;}
RECOMP_FUNC void func_800BFC54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFC54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BFC58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BFC5C: jal         0x800D6B0C
    // 0x800BFC60: nop

    func_800D6B0C(rdram, ctx);
        goto after_0;
    // 0x800BFC60: nop

    after_0:
    // 0x800BFC64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BFC68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BFC6C: jr          $ra
    // 0x800BFC70: nop

    return;
    // 0x800BFC70: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800894E8: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x800894E8);
    return;
    // 0x800894EC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800D517C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D517C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D5180: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800D5184: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D5188: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D518C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D5190: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D5194: jal         0x800883F8
    // 0x800D5198: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    _gcextra_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800D5198: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800D519C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D51A0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800D51A4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D51A8: sw          $zero, -0x4BE0($at)
    MEM_W(-0X4BE0, ctx->r1) = 0;
    // 0x800D51AC: addiu       $s2, $s2, -0x49C0
    ctx->r18 = ADD32(ctx->r18, -0X49C0);
    // 0x800D51B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800D51B4: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
L_800D51B8:
    // 0x800D51B8: jal         0x800D4EF4
    // 0x800D51BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D4EF4(rdram, ctx);
        goto after_1;
    // 0x800D51BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800D51C0: beq         $v0, $zero, L_800D51DC
    if (ctx->r2 == 0) {
        // 0x800D51C4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800D51DC;
    }
    // 0x800D51C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D51C8: jal         0x800D4F9C
    // 0x800D51CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D4F9C(rdram, ctx);
        goto after_2;
    // 0x800D51CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x800D51D0: beql        $v0, $zero, L_800D51E0
    if (ctx->r2 == 0) {
        // 0x800D51D4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800D51E0;
    }
    goto skip_0;
    // 0x800D51D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800D51D8: addu        $s0, $s0, $s3
    ctx->r16 = ADD32(ctx->r16, ctx->r19);
L_800D51DC:
    // 0x800D51DC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800D51E0:
    // 0x800D51E0: addiu       $s2, $s2, 0x3
    ctx->r18 = ADD32(ctx->r18, 0X3);
    // 0x800D51E4: sb          $s0, -0x1($s2)
    MEM_B(-0X1, ctx->r18) = ctx->r16;
    // 0x800D51E8: bne         $s1, $s4, L_800D51B8
    if (ctx->r17 != ctx->r20) {
        // 0x800D51EC: sb          $s0, -0x2($s2)
        MEM_B(-0X2, ctx->r18) = ctx->r16;
            goto L_800D51B8;
    }
    // 0x800D51EC: sb          $s0, -0x2($s2)
    MEM_B(-0X2, ctx->r18) = ctx->r16;
    // 0x800D51F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800D51F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D51F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D51FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D5200: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D5204: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D5208: jr          $ra
    // 0x800D520C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800D520C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _chwitchytents_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C10: syscall     209
    recomp_syscall_handler(rdram, ctx, 0x80085C10);
    return;
    // 0x80085C14: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _sujiggy_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A720: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A720);
    return;
    // 0x8008A724: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_80800630_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800630: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800634: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800638: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080063C: jal         0x80800114
    // 0x80800640: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800114_bstntswim(rdram, ctx);
        goto after_0;
    // 0x80800640: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800644: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800648: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800650: jal         0x8008CB3C
    // 0x80800654: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800654: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    after_1:
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080065C: jal         0x8008CA4C
    // 0x80800660: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008CA4C(rdram, ctx);
        goto after_2;
    // 0x80800660: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800664: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800668: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800670: jal         0x8008C9BC
    // 0x80800674: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_3;
    // 0x80800674: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_3:
    // 0x80800678: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(408, 0X9A4) << 16);
    // 0x8080067C: lwc1        $f4, 0x9A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(408, 0X9A4));
    // 0x80800680: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80800684: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080068C: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80800690: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80800694: jal         0x8008C9F0
    // 0x80800698: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_4;
    // 0x80800698: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A0: jal         0x8009C908
    // 0x808006A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    yaw_setUpdateType(rdram, ctx);
        goto after_5;
    // 0x808006A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006AC: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808006B0: jal         0x8009C99C
    // 0x808006B4: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_6;
    // 0x808006B4: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_6:
    // 0x808006B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006BC: jal         0x8009D2D8
    // 0x808006C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D2D8(rdram, ctx);
        goto after_7;
    // 0x808006C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C8: jal         0x8009B800
    // 0x808006CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baphysics_set_type(rdram, ctx);
        goto after_8;
    // 0x808006CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x808006D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808006DC: jr          $ra
    // 0x808006E0: nop

    return;
    // 0x808006E0: nop

;}
RECOMP_FUNC void func_80800180_chmayafarmer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800184: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800188: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080018C: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x80800190: ori         $t6, $a2, 0x4
    ctx->r14 = ctx->r6 | 0X4;
    // 0x80800194: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800198: addiu       $t8, $zero, 0x2A
    ctx->r24 = ADD32(0, 0X2A);
    // 0x8080019C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x808001A0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808001A4: jal         0x8008A208
    // 0x808001A8: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x808001A8: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    after_0:
    // 0x808001AC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x808001B0: lbu         $t0, 0x74($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X74);
    // 0x808001B4: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x808001B8: sb          $t1, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r9;
    // 0x808001BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001C4: jr          $ra
    // 0x808001C8: nop

    return;
    // 0x808001C8: nop

;}
RECOMP_FUNC void glgamedata_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800274: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800278: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080027C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800280: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800284: jal         0x808001E4
    // 0x80800288: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_808001E4_glgamedata(rdram, ctx);
        goto after_0;
    // 0x80800288: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x8080028C: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x80800290: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800294: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800298: jal         0x808001F0
    // 0x8080029C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808001F0_glgamedata(rdram, ctx);
        goto after_1;
    // 0x8080029C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808002A0: beq         $v0, $zero, L_808002B8
    if (ctx->r2 == 0) {
        // 0x808002A4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808002B8;
    }
    // 0x808002A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808002A8:
    // 0x808002A8: jal         0x808001F0
    // 0x808002AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_808001F0_glgamedata(rdram, ctx);
        goto after_2;
    // 0x808002AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x808002B0: bnel        $v0, $zero, L_808002A8
    if (ctx->r2 != 0) {
        // 0x808002B4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808002A8;
    }
    goto skip_0;
    // 0x808002B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_808002B8:
    // 0x808002B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808002C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808002C4: jr          $ra
    // 0x808002C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808002C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
