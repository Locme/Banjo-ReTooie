#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800A58F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A58F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A58F4: lw          $t6, -0x6AC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6AC0);
    // 0x800A58F8: lw          $v0, 0x38($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X38);
    // 0x800A58FC: jr          $ra
    // 0x800A5900: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    return;
    // 0x800A5900: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
;}
RECOMP_FUNC void ncbajig_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: jr          $ra
    // 0x808000C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808000C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80014128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001412C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014130: jal         0x80013D94
    // 0x80014134: nop

    func_80013D94(rdram, ctx);
        goto after_0;
    // 0x80014134: nop

    after_0:
    // 0x80014138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001413C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80014140: jr          $ra
    // 0x80014144: nop

    return;
    // 0x80014144: nop

;}
RECOMP_FUNC void func_800C01A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C01A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C01AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C01B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C01B4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C01B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C01BC: lh          $a1, 0x1A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1A);
    // 0x800C01C0: jal         0x800880C8
    // 0x800C01C4: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    _gcdialogcamera_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x800C01C4: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    after_0:
    // 0x800C01C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C01CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C01D0: jr          $ra
    // 0x800C01D4: nop

    return;
    // 0x800C01D4: nop

;}
RECOMP_FUNC void _chbaddiesetup_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D30: syscall     449
    recomp_syscall_handler(rdram, ctx, 0x80086D30);
    return;
    // 0x80086D34: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800FB650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB650: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FB654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FB658: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800FB65C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800FB660: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800FB664: lw          $a0, 0x38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38);
    // 0x800FB668: jal         0x800B2FE0
    // 0x800FB66C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    freelist_clear(rdram, ctx);
        goto after_0;
    // 0x800FB66C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x800FB670: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800FB674: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800FB678: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800FB67C: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x800FB680: addu        $v0, $a3, $t6
    ctx->r2 = ADD32(ctx->r7, ctx->r14);
    // 0x800FB684: sw          $zero, 0x40($v0)
    MEM_W(0X40, ctx->r2) = 0;
    // 0x800FB688: sw          $zero, 0x44($v0)
    MEM_W(0X44, ctx->r2) = 0;
    // 0x800FB68C: sw          $zero, 0x48($v0)
    MEM_W(0X48, ctx->r2) = 0;
    // 0x800FB690: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x800FB694: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800FB698: jal         0x800B3044
    // 0x800FB69C: addiu       $a0, $a3, 0x38
    ctx->r4 = ADD32(ctx->r7, 0X38);
    freelist_next(rdram, ctx);
        goto after_1;
    // 0x800FB69C: addiu       $a0, $a3, 0x38
    ctx->r4 = ADD32(ctx->r7, 0X38);
    after_1:
    // 0x800FB6A0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800FB6A4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800FB6A8: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800FB6AC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800FB6B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FB6B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800FB6B8: jr          $ra
    // 0x800FB6BC: nop

    return;
    // 0x800FB6BC: nop

;}
RECOMP_FUNC void func_800F45E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F45E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F45E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F45E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F45EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F45F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800F45F4: jal         0x8009BF5C
    // 0x800F45F8: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_0;
    // 0x800F45F8: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    after_0:
    // 0x800F45FC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800F4600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F4604: jal         0x8009C914
    // 0x800F4608: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    yaw_setIdeal(rdram, ctx);
        goto after_1;
    // 0x800F4608: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    after_1:
    // 0x800F460C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800F4610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F4614: jal         0x8009C4CC
    // 0x800F4618: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    baroll_setIdeal(rdram, ctx);
        goto after_2;
    // 0x800F4618: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    after_2:
    // 0x800F461C: jal         0x8009BFBC
    // 0x800F4620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BFBC(rdram, ctx);
        goto after_3;
    // 0x800F4620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800F4624: jal         0x8009C974
    // 0x800F4628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_4;
    // 0x800F4628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800F462C: jal         0x8009C52C
    // 0x800F4630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baroll_applyIdeal(rdram, ctx);
        goto after_5;
    // 0x800F4630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800F4634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F4638: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F463C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F4640: jr          $ra
    // 0x800F4644: nop

    return;
    // 0x800F4644: nop

;}
RECOMP_FUNC void func_8001B840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B840: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001B844: jr          $ra
    // 0x8001B848: sw          $zero, -0x3910($at)
    MEM_W(-0X3910, ctx->r1) = 0;
    return;
    // 0x8001B848: sw          $zero, -0x3910($at)
    MEM_W(-0X3910, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80800008_ncbatarget(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800014: jal         0x80112524
    // 0x80800018: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080001C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800020: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800024: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800028: jal         0x800EFB24
    // 0x8080002C: lw          $a1, 0x58($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X58);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x8080002C: lw          $a1, 0x58($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X58);
    after_1:
    // 0x80800030: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800034: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800038: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8080003C: lw          $t8, 0x58($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X58);
    // 0x80800040: jal         0x800EF174
    // 0x80800044: lw          $a2, 0xC($t8)
    ctx->r6 = MEM_W(ctx->r24, 0XC);
    func_800EF174(rdram, ctx);
        goto after_2;
    // 0x80800044: lw          $a2, 0xC($t8)
    ctx->r6 = MEM_W(ctx->r24, 0XC);
    after_2:
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080004C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void _gspropctrl_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C00: syscall     728
    recomp_syscall_handler(rdram, ctx, 0x80088C00);
    return;
    // 0x80088C04: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void anctrl_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B064: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B068: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008B06C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008B070: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008B074: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x8008B078: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008B07C: addiu       $s1, $a0, 0x1C
    ctx->r17 = ADD32(ctx->r4, 0X1C);
    // 0x8008B080: sll         $t8, $t6, 25
    ctx->r24 = S32(ctx->r14 << 25);
    // 0x8008B084: bgezl       $t8, L_8008B0D0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8008B088: addiu       $s1, $s0, 0x1C
        ctx->r17 = ADD32(ctx->r16, 0X1C);
            goto L_8008B0D0;
    }
    goto skip_0;
    // 0x8008B088: addiu       $s1, $s0, 0x1C
    ctx->r17 = ADD32(ctx->r16, 0X1C);
    skip_0:
    // 0x8008B08C: jal         0x8008C0C0
    // 0x8008B090: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008C0C0(rdram, ctx);
        goto after_0;
    // 0x8008B090: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8008B094: beql        $v0, $zero, L_8008B0D0
    if (ctx->r2 == 0) {
        // 0x8008B098: addiu       $s1, $s0, 0x1C
        ctx->r17 = ADD32(ctx->r16, 0X1C);
            goto L_8008B0D0;
    }
    goto skip_1;
    // 0x8008B098: addiu       $s1, $s0, 0x1C
    ctx->r17 = ADD32(ctx->r16, 0X1C);
    skip_1:
    // 0x8008B09C: jal         0x8008C0AC
    // 0x8008B0A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008C0AC(rdram, ctx);
        goto after_1;
    // 0x8008B0A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8008B0A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008B0A8: jal         0x8008C1B8
    // 0x8008B0AC: lh          $a1, 0x18($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X18);
    func_8008C1B8(rdram, ctx);
        goto after_2;
    // 0x8008B0AC: lh          $a1, 0x18($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X18);
    after_2:
    // 0x8008B0B0: jal         0x8008AFCC
    // 0x8008B0B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008AFCC(rdram, ctx);
        goto after_3;
    // 0x8008B0B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8008B0B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008B0BC: jal         0x8008C1E4
    // 0x8008B0C0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8008C1E4(rdram, ctx);
        goto after_4;
    // 0x8008B0C0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x8008B0C4: b           L_8008B0FC
    // 0x8008B0C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008B0FC;
    // 0x8008B0C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B0CC: addiu       $s1, $s0, 0x1C
    ctx->r17 = ADD32(ctx->r16, 0X1C);
L_8008B0D0:
    // 0x8008B0D0: jal         0x8008C270
    // 0x8008B0D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008C270(rdram, ctx);
        goto after_5;
    // 0x8008B0D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8008B0D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008B0DC: jal         0x8008C1B8
    // 0x8008B0E0: lh          $a1, 0x18($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X18);
    func_8008C1B8(rdram, ctx);
        goto after_6;
    // 0x8008B0E0: lh          $a1, 0x18($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X18);
    after_6:
    // 0x8008B0E4: jal         0x8008AFCC
    // 0x8008B0E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008AFCC(rdram, ctx);
        goto after_7;
    // 0x8008B0E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8008B0EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008B0F0: jal         0x8008C1E4
    // 0x8008B0F4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008C1E4(rdram, ctx);
        goto after_8;
    // 0x8008B0F4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_8:
    // 0x8008B0F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008B0FC:
    // 0x8008B0FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8008B100: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8008B104: jr          $ra
    // 0x8008B108: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8008B108: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bskazstilt_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011D4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808011D8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(292, 0X1270) << 16);
    // 0x808011DC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808011E0: jr          $ra
    // 0x808011E4: lw          $v0, 0x1270($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(292, 0X1270));
    return;
    // 0x808011E4: lw          $v0, 0x1270($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(292, 0X1270));
;}
RECOMP_FUNC void func_80800078_fxstep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080007C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800080: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800084: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800088: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080008C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800090: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800094: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800098: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080009C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808000A0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808000A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808000A8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808000AC: sub.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x808000B0: jal         0x800DC178
    // 0x808000B4: add.s       $f14, $f8, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f0.fl;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x808000B4: add.s       $f14, $f8, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f0.fl;
    after_0:
    // 0x808000B8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x808000BC: lbu         $t6, 0x26($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X26);
    // 0x808000C0: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x808000C4: beql        $t6, $zero, L_808000D8
    if (ctx->r14 == 0) {
        // 0x808000C8: lbu         $s0, 0x25($s1)
        ctx->r16 = MEM_BU(ctx->r17, 0X25);
            goto L_808000D8;
    }
    goto skip_0;
    // 0x808000C8: lbu         $s0, 0x25($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X25);
    skip_0:
    // 0x808000CC: b           L_808000D8
    // 0x808000D0: lbu         $s0, 0x24($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X24);
        goto L_808000D8;
    // 0x808000D0: lbu         $s0, 0x24($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X24);
    // 0x808000D4: lbu         $s0, 0x25($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X25);
L_808000D8:
    // 0x808000D8: jal         0x800C35E8
    // 0x808000DC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C35E8(rdram, ctx);
        goto after_1;
    // 0x808000DC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_1:
    // 0x808000E0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x808000E4: jal         0x800C301C
    // 0x808000E8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800C301C(rdram, ctx);
        goto after_2;
    // 0x808000E8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x808000EC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x808000F0: jal         0x800C31DC
    // 0x808000F4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800C31DC(rdram, ctx);
        goto after_3;
    // 0x808000F4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808000F8: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x808000FC: jal         0x800C3058
    // 0x80800100: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800C3058(rdram, ctx);
        goto after_4;
    // 0x80800100: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x80800104: jal         0x800C3BDC
    // 0x80800108: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C3BDC(rdram, ctx);
        goto after_5;
    // 0x80800108: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_5:
    // 0x8080010C: lbu         $t7, 0x26($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X26);
    // 0x80800110: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x80800114: sb          $t8, 0x26($s1)
    MEM_B(0X26, ctx->r17) = ctx->r24;
    // 0x80800118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080011C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800120: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800124: jr          $ra
    // 0x80800128: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800128: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8080042C_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080042C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800430: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800434: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800438: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080043C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800440: beq         $a1, $at, L_80800474
    if (ctx->r5 == ctx->r1) {
        // 0x80800444: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80800474;
    }
    // 0x80800444: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800448: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080044C: beq         $a1, $at, L_808004EC
    if (ctx->r5 == ctx->r1) {
        // 0x80800450: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004EC;
    }
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800454: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800458: beq         $a1, $at, L_8080053C
    if (ctx->r5 == ctx->r1) {
        // 0x8080045C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080053C;
    }
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800460: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800464: beql        $a1, $at, L_80800578
    if (ctx->r5 == ctx->r1) {
        // 0x80800468: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80800578;
    }
    goto skip_0;
    // 0x80800468: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8080046C: b           L_80800578
    // 0x80800470: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_80800578;
    // 0x80800470: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_80800474:
    // 0x80800474: jal         0x8008CABC
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080047C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800480: jal         0x8008AF24
    // 0x80800484: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800484: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800488: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080048C: jal         0x8008B1A0
    // 0x80800490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x80800490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800494: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800498: jal         0x8008AED4
    // 0x8080049C: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x8080049C: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_3:
    // 0x808004A0: lui         $a2, 0x3E82
    ctx->r6 = S32(0X3E82 << 16);
    // 0x808004A4: ori         $a2, $a2, 0x1965
    ctx->r6 = ctx->r6 | 0X1965;
    // 0x808004A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808004AC: jal         0x8008B1D4
    // 0x808004B0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_4;
    // 0x808004B0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x808004B4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808004B8: jal         0x8008B1BC
    // 0x808004BC: lui         $a1, 0x4020
    ctx->r5 = S32(0X4020 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x808004BC: lui         $a1, 0x4020
    ctx->r5 = S32(0X4020 << 16);
    after_5:
    // 0x808004C0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808004C4: jal         0x8008B134
    // 0x808004C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x808004C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808004CC: jal         0x8008B064
    // 0x808004D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x808004D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x808004D4: lui         $a1, 0x3FE6
    ctx->r5 = S32(0X3FE6 << 16);
    // 0x808004D8: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808004DC: jal         0x8009D820
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D820(rdram, ctx);
        goto after_8;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808004E4: b           L_80800578
    // 0x808004E8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_80800578;
    // 0x808004E8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_808004EC:
    // 0x808004EC: lui         $a1, 0x3F12
    ctx->r5 = S32(0X3F12 << 16);
    // 0x808004F0: jal         0x8008CED4
    // 0x808004F4: ori         $a1, $a1, 0xF838
    ctx->r5 = ctx->r5 | 0XF838;
    baanim_setEnd(rdram, ctx);
        goto after_9;
    // 0x808004F4: ori         $a1, $a1, 0xF838
    ctx->r5 = ctx->r5 | 0XF838;
    after_9:
    // 0x808004F8: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808004FC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800504: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x80800508: jal         0x8009DF94
    // 0x8080050C: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF94(rdram, ctx);
        goto after_10;
    // 0x8080050C: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_10:
    // 0x80800510: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80800514: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080051C: addiu       $a1, $zero, 0x428
    ctx->r5 = ADD32(0, 0X428);
    // 0x80800520: jal         0x8009DF18
    // 0x80800524: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_11;
    // 0x80800524: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_11:
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080052C: jal         0x8009BA58
    // 0x80800530: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_12;
    // 0x80800530: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_12:
    // 0x80800534: b           L_80800578
    // 0x80800538: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_80800578;
    // 0x80800538: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_8080053C:
    // 0x8080053C: jal         0x8008CED4
    // 0x80800540: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEnd(rdram, ctx);
        goto after_13;
    // 0x80800540: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_13:
    // 0x80800544: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800548: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800550: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x80800554: jal         0x8009DF94
    // 0x80800558: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF94(rdram, ctx);
        goto after_14;
    // 0x80800558: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_14:
    // 0x8080055C: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80800560: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800568: addiu       $a1, $zero, 0x428
    ctx->r5 = ADD32(0, 0X428);
    // 0x8080056C: jal         0x8009DF18
    // 0x80800570: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_15;
    // 0x80800570: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_15:
    // 0x80800574: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_80800578:
    // 0x80800578: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
    // 0x8080057C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800580: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800584: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800588: jr          $ra
    // 0x8080058C: nop

    return;
    // 0x8080058C: nop

;}
RECOMP_FUNC void func_80800678_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800678: lw          $v1, 0x6C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6C);
    // 0x8080067C: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80800680: srl         $v0, $v1, 21
    ctx->r2 = S32(U32(ctx->r3) >> 21);
    // 0x80800684: beq         $v0, $zero, L_808006D4
    if (ctx->r2 == 0) {
        // 0x80800688: nop
    
            goto L_808006D4;
    }
    // 0x80800688: nop

    // 0x8080068C: beq         $v0, $at, L_808006B4
    if (ctx->r2 == ctx->r1) {
        // 0x80800690: addiu       $at, $zero, 0x5C
        ctx->r1 = ADD32(0, 0X5C);
            goto L_808006B4;
    }
    // 0x80800690: addiu       $at, $zero, 0x5C
    ctx->r1 = ADD32(0, 0X5C);
    // 0x80800694: beq         $v0, $at, L_808006BC
    if (ctx->r2 == ctx->r1) {
        // 0x80800698: addiu       $at, $zero, 0x63
        ctx->r1 = ADD32(0, 0X63);
            goto L_808006BC;
    }
    // 0x80800698: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x8080069C: beq         $v0, $at, L_808006C4
    if (ctx->r2 == ctx->r1) {
        // 0x808006A0: addiu       $at, $zero, 0x65
        ctx->r1 = ADD32(0, 0X65);
            goto L_808006C4;
    }
    // 0x808006A0: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x808006A4: beq         $v0, $at, L_808006CC
    if (ctx->r2 == ctx->r1) {
        // 0x808006A8: nop
    
            goto L_808006CC;
    }
    // 0x808006A8: nop

    // 0x808006AC: b           L_808006DC
    // 0x808006B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006DC;
    // 0x808006B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006B4:
    // 0x808006B4: jr          $ra
    // 0x808006B8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x808006B8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808006BC:
    // 0x808006BC: jr          $ra
    // 0x808006C0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x808006C0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808006C4:
    // 0x808006C4: jr          $ra
    // 0x808006C8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x808006C8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_808006CC:
    // 0x808006CC: jr          $ra
    // 0x808006D0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x808006D0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_808006D4:
    // 0x808006D4: jr          $ra
    // 0x808006D8: andi        $v0, $v1, 0x1FF
    ctx->r2 = ctx->r3 & 0X1FF;
    return;
    // 0x808006D8: andi        $v0, $v1, 0x1FF
    ctx->r2 = ctx->r3 & 0X1FF;
L_808006DC:
    // 0x808006DC: jr          $ra
    // 0x808006E0: nop

    return;
    // 0x808006E0: nop

;}
RECOMP_FUNC void func_80092CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092CE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80092CE8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80092CEC: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092CF0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80092CF4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80092CF8: jal         0x800DBEFC
    // 0x80092CFC: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_0;
    // 0x80092CFC: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    after_0:
    // 0x80092D00: jal         0x800EEF24
    // 0x80092D04: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800EEF24(rdram, ctx);
        goto after_1;
    // 0x80092D04: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80092D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092D0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092D10: jr          $ra
    // 0x80092D14: nop

    return;
    // 0x80092D14: nop

;}
RECOMP_FUNC void func_8009E0AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E0AC: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009E0B0: jr          $ra
    // 0x8009E0B4: sb          $a1, 0x1C($t6)
    MEM_B(0X1C, ctx->r14) = ctx->r5;
    return;
    // 0x8009E0B4: sb          $a1, 0x1C($t6)
    MEM_B(0X1C, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void _bsbansack_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800826B8: syscall     7
    recomp_syscall_handler(rdram, ctx, 0x800826B8);
    return;
    // 0x800826BC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800DAA34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAA34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DAA38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DAA3C: addiu       $a0, $a0, 0x1F
    ctx->r4 = ADD32(ctx->r4, 0X1F);
    // 0x800DAA40: sra         $t6, $a0, 5
    ctx->r14 = S32(SIGNED(ctx->r4) >> 5);
    // 0x800DAA44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DAA48: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800DAA4C: jal         0x8001ACCC
    // 0x800DAA50: addiu       $a0, $t7, 0x4
    ctx->r4 = ADD32(ctx->r15, 0X4);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800DAA50: addiu       $a0, $t7, 0x4
    ctx->r4 = ADD32(ctx->r15, 0X4);
    after_0:
    // 0x800DAA54: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800DAA58: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800DAA5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DAA60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DAA64: jr          $ra
    // 0x800DAA68: nop

    return;
    // 0x800DAA68: nop

;}
RECOMP_FUNC void func_80101F64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101F64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80101F68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101F6C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80101F70: jal         0x80102394
    // 0x80101F74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80102394(rdram, ctx);
        goto after_0;
    // 0x80101F74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80101F78: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80101F7C: jal         0x80104248
    // 0x80101F80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80104248(rdram, ctx);
        goto after_1;
    // 0x80101F80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80101F84: bne         $v0, $zero, L_80101F94
    if (ctx->r2 != 0) {
        // 0x80101F88: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80101F94;
    }
    // 0x80101F88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101F8C: b           L_80101FCC
    // 0x80101F90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80101FCC;
    // 0x80101F90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80101F94:
    // 0x80101F94: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80101F98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80101F9C: beq         $t6, $zero, L_80101FCC
    if (ctx->r14 == 0) {
        // 0x80101FA0: nop
    
            goto L_80101FCC;
    }
    // 0x80101FA0: nop

    // 0x80101FA4: jal         0x8008B264
    // 0x80101FA8: nop

    anctrl_getIndex(rdram, ctx);
        goto after_2;
    // 0x80101FA8: nop

    after_2:
    // 0x80101FAC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80101FB0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80101FB4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80101FB8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80101FBC: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x80101FC0: xor         $v0, $v0, $t1
    ctx->r2 = ctx->r2 ^ ctx->r9;
    // 0x80101FC4: b           L_80101FCC
    // 0x80101FC8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
        goto L_80101FCC;
    // 0x80101FC8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_80101FCC:
    // 0x80101FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101FD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80101FD4: jr          $ra
    // 0x80101FD8: nop

    return;
    // 0x80101FD8: nop

;}
RECOMP_FUNC void _glcutDll_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088830: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x80088830);
    return;
    // 0x80088834: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_8080138C_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080138C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801394: jal         0x80800A50
    // 0x80801398: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80800A50_chhumba(rdram, ctx);
        goto after_0;
    // 0x80801398: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080139C: beql        $v0, $zero, L_80801440
    if (ctx->r2 == 0) {
        // 0x808013A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801440;
    }
    goto skip_0;
    // 0x808013A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808013A4: jal         0x80090270
    // 0x808013A8: nop

    func_80090270(rdram, ctx);
        goto after_1;
    // 0x808013A8: nop

    after_1:
    // 0x808013AC: bnel        $v0, $zero, L_80801440
    if (ctx->r2 != 0) {
        // 0x808013B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801440;
    }
    goto skip_1;
    // 0x808013B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808013B4: jal         0x8008FD48
    // 0x808013B8: nop

    func_8008FD48(rdram, ctx);
        goto after_2;
    // 0x808013B8: nop

    after_2:
    // 0x808013BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808013C0: bne         $v0, $at, L_808013FC
    if (ctx->r2 != ctx->r1) {
        // 0x808013C4: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_808013FC;
    }
    // 0x808013C4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808013C8: jal         0x8009EA2C
    // 0x808013CC: nop

    func_8009EA2C(rdram, ctx);
        goto after_3;
    // 0x808013CC: nop

    after_3:
    // 0x808013D0: beq         $v0, $zero, L_808013E8
    if (ctx->r2 == 0) {
        // 0x808013D4: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_808013E8;
    }
    // 0x808013D4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808013D8: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x808013DC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x808013E0: bltz        $t9, L_808013FC
    if (SIGNED(ctx->r25) < 0) {
        // 0x808013E4: nop
    
            goto L_808013FC;
    }
    // 0x808013E4: nop

L_808013E8:
    // 0x808013E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808013EC: jal         0x80800E44
    // 0x808013F0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800E44_chhumba(rdram, ctx);
        goto after_4;
    // 0x808013F0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x808013F4: b           L_80801440
    // 0x808013F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801440;
    // 0x808013F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808013FC:
    // 0x808013FC: jal         0x80800384
    // 0x80801400: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800384_chhumba(rdram, ctx);
        goto after_5;
    // 0x80801400: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80801404: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80801408: beql        $v0, $t0, L_80801434
    if (ctx->r2 == ctx->r8) {
        // 0x8080140C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80801434;
    }
    goto skip_2;
    // 0x8080140C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_2:
    // 0x80801410: jal         0x8009EA2C
    // 0x80801414: nop

    func_8009EA2C(rdram, ctx);
        goto after_6;
    // 0x80801414: nop

    after_6:
    // 0x80801418: beq         $v0, $zero, L_8080143C
    if (ctx->r2 == 0) {
        // 0x8080141C: lw          $t1, 0x20($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X20);
            goto L_8080143C;
    }
    // 0x8080141C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80801420: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    // 0x80801424: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80801428: bgezl       $t4, L_80801440
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8080142C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801440;
    }
    goto skip_3;
    // 0x8080142C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80801430: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80801434:
    // 0x80801434: jal         0x80800E44
    // 0x80801438: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80800E44_chhumba(rdram, ctx);
        goto after_7;
    // 0x80801438: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_7:
L_8080143C:
    // 0x8080143C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801440:
    // 0x80801440: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801444: jr          $ra
    // 0x80801448: nop

    return;
    // 0x80801448: nop

;}
RECOMP_FUNC void func_80803C88_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803C88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803C8C: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80803C90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803C94: bne         $a1, $at, L_80803CDC
    if (ctx->r5 != ctx->r1) {
        // 0x80803C98: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80803CDC;
    }
    // 0x80803C98: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80803C9C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803CA0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80803CA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803CA8: lwc1        $f12, 0x2C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80803CAC: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80803CB0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80803CB4: jal         0x800F10B4
    // 0x80803CB8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x80803CB8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80803CBC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80803CC0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80803CC4: jal         0x800DF410
    // 0x80803CC8: nop

    func_800DF410(rdram, ctx);
        goto after_1;
    // 0x80803CC8: nop

    after_1:
    // 0x80803CCC: jal         0x800DF830
    // 0x80803CD0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_2;
    // 0x80803CD0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80803CD4: b           L_80803CE4
    // 0x80803CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803CE4;
    // 0x80803CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803CDC:
    // 0x80803CDC: b           L_80803CE4
    // 0x80803CE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803CE4;
    // 0x80803CE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803CE4:
    // 0x80803CE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803CE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803CEC: jr          $ra
    // 0x80803CF0: nop

    return;
    // 0x80803CF0: nop

;}
RECOMP_FUNC void chlavatraindoorswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1904, 0X80) << 16);
    // 0x8080006C: jr          $ra
    // 0x80800070: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1904, 0X80));
    return;
    // 0x80800070: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1904, 0X80));
    // 0x80800074: nop

    // 0x80800078: nop

    // 0x8080007C: nop

;}
RECOMP_FUNC void chcollballcontrol_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802C44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802C48: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802C4C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80802C50: jal         0x80106790
    // 0x80802C54: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802C54: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80802C58: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802C5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802C60: jal         0x80100094
    // 0x80802C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80802C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80802C68: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80802C6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802C70: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80802C74: beq         $a0, $at, L_80802C94
    if (ctx->r4 == ctx->r1) {
        // 0x80802C78: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80802C94;
    }
    // 0x80802C78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802C7C: bne         $a0, $at, L_80802CD0
    if (ctx->r4 != ctx->r1) {
        // 0x80802C80: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80802CD0;
    }
    // 0x80802C80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802C84: jal         0x80801764
    // 0x80802C88: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80801764_chcollballcontrol(rdram, ctx);
        goto after_2;
    // 0x80802C88: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80802C8C: b           L_80802CD4
    // 0x80802C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802CD4;
    // 0x80802C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802C94:
    // 0x80802C94: jal         0x800D8FF8
    // 0x80802C98: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x80802C98: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_3:
    // 0x80802C9C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80802CA0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80802CA4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80802CA8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80802CAC: bgez        $t6, L_80802CC0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80802CB0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80802CC0;
    }
    // 0x80802CB0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80802CB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802CB8: nop

    // 0x80802CBC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80802CC0:
    // 0x80802CC0: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80802CC4: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x80802CC8: jal         0x808030D0
    // 0x80802CCC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_808030D0_chcollballcontrol(rdram, ctx);
        goto after_4;
    // 0x80802CCC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
L_80802CD0:
    // 0x80802CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802CD4:
    // 0x80802CD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802CD8: jr          $ra
    // 0x80802CDC: nop

    return;
    // 0x80802CDC: nop

;}
RECOMP_FUNC void func_80015FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015FA0: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80015FA4: lbu         $t6, -0x6297($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X6297);
    // 0x80015FA8: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80015FAC: beq         $t6, $zero, L_80015FC0
    if (ctx->r14 == 0) {
        // 0x80015FB0: nop
    
            goto L_80015FC0;
    }
    // 0x80015FB0: nop

    // 0x80015FB4: lbu         $t7, -0x646D($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X646D);
    // 0x80015FB8: beq         $t7, $zero, L_80015FC8
    if (ctx->r15 == 0) {
        // 0x80015FBC: nop
    
            goto L_80015FC8;
    }
    // 0x80015FBC: nop

L_80015FC0:
    // 0x80015FC0: jr          $ra
    // 0x80015FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80015FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80015FC8:
    // 0x80015FC8: beq         $a0, $zero, L_80015FEC
    if (ctx->r4 == 0) {
        // 0x80015FCC: lui         $v1, 0x8008
        ctx->r3 = S32(0X8008 << 16);
            goto L_80015FEC;
    }
    // 0x80015FCC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80015FD0: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x80015FD4: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x80015FD8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80015FDC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80015FE0: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x80015FE4: b           L_80015FF0
    // 0x80015FE8: lw          $v1, -0x65EC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X65EC);
        goto L_80015FF0;
    // 0x80015FE8: lw          $v1, -0x65EC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X65EC);
L_80015FEC:
    // 0x80015FEC: lw          $v1, -0x650C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X650C);
L_80015FF0:
    // 0x80015FF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80015FF4: jr          $ra
    // 0x80015FF8: nop

    return;
    // 0x80015FF8: nop

;}
RECOMP_FUNC void func_8008D0A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D0A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D0A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D0A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D0AC: jal         0x800C6E38
    // 0x8008D0B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D0B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8008D0B4: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D0B8: beq         $t6, $zero, L_8008D0D0
    if (ctx->r14 == 0) {
        // 0x8008D0BC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D0D0;
    }
    // 0x8008D0BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D0C0: jal         0x800A3304
    // 0x8008D0C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3304(rdram, ctx);
        goto after_1;
    // 0x8008D0C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008D0C8: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D0CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008D0D0:
    // 0x8008D0D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D0D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D0D8: jr          $ra
    // 0x8008D0DC: nop

    return;
    // 0x8008D0DC: nop

;}
RECOMP_FUNC void func_80800EBC_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800EC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800EC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800EC8: jal         0x800D8FF8
    // 0x80800ECC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800ECC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800ED0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800ED4: jal         0x800D90A4
    // 0x80800ED8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x80800ED8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x80800EDC: beql        $v0, $zero, L_80800F24
    if (ctx->r2 == 0) {
        // 0x80800EE0: lwc1        $f4, 0x24($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80800F24;
    }
    goto skip_0;
    // 0x80800EE0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800EE4: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x80800EE8: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800EEC: bltzl       $t8, L_80800F24
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800EF0: lwc1        $f4, 0x24($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80800F24;
    }
    goto skip_1;
    // 0x80800EF0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800EF4: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80800EF8: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x80800EFC: bltzl       $t1, L_80800F24
    if (SIGNED(ctx->r9) < 0) {
        // 0x80800F00: lwc1        $f4, 0x24($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80800F24;
    }
    goto skip_2;
    // 0x80800F00: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800F04: jal         0x8010A570
    // 0x80800F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x80800F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800F0C: jal         0x80089CA8
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800F14: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x80800F18: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x80800F1C: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    // 0x80800F20: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
L_80800F24:
    // 0x80800F24: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800F28: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800F2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800F30: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800F34: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80800F38: jal         0x8001210C
    // 0x80800F3C: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
    func_8001210C(rdram, ctx);
        goto after_4;
    // 0x80800F3C: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
    after_4:
    // 0x80800F40: beql        $v0, $zero, L_80800F54
    if (ctx->r2 == 0) {
        // 0x80800F44: lhu         $t5, 0x72($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X72);
            goto L_80800F54;
    }
    goto skip_3;
    // 0x80800F44: lhu         $t5, 0x72($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X72);
    skip_3:
    // 0x80800F48: jal         0x80801114
    // 0x80800F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801114_chonearmbandit(rdram, ctx);
        goto after_5;
    // 0x80800F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800F50: lhu         $t5, 0x72($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X72);
L_80800F54:
    // 0x80800F54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800F58: srl         $t6, $t5, 10
    ctx->r14 = S32(U32(ctx->r13) >> 10);
    // 0x80800F5C: bnel        $t6, $at, L_80800F70
    if (ctx->r14 != ctx->r1) {
        // 0x80800F60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800F70;
    }
    goto skip_4;
    // 0x80800F60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80800F64: jal         0x80801154
    // 0x80800F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801154_chonearmbandit(rdram, ctx);
        goto after_6;
    // 0x80800F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800F6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F70:
    // 0x80800F70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F78: jr          $ra
    // 0x80800F7C: nop

    return;
    // 0x80800F7C: nop

;}
RECOMP_FUNC void func_80801E3C_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E3C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80801E40: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801E44: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801E48: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80801E4C: jal         0x80100094
    // 0x80801E50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801E50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801E54: lh          $a0, 0x128($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X128);
    // 0x80801E58: jal         0x800F5A00
    // 0x80801E5C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x80801E5C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_1:
    // 0x80801E60: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80801E64: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x80801E68: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801E6C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80801E70: jal         0x8008A0E0
    // 0x80801E74: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80801E74: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x80801E78: beq         $v0, $zero, L_80801F40
    if (ctx->r2 == 0) {
        // 0x80801E7C: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_80801F40;
    }
    // 0x80801E7C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80801E80: jal         0x80100094
    // 0x80801E84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80801E84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80801E88: addiu       $a0, $zero, 0x45F
    ctx->r4 = ADD32(0, 0X45F);
    // 0x80801E8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801E90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801E94: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    // 0x80801E98: jal         0x80108528
    // 0x80801E9C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    func_80108528(rdram, ctx);
        goto after_4;
    // 0x80801E9C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_4:
    // 0x80801EA0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801EA4: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    // 0x80801EA8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80801EAC: jal         0x800EFB24
    // 0x80801EB0: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    func_800EFB24(rdram, ctx);
        goto after_5;
    // 0x80801EB0: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    after_5:
    // 0x80801EB4: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80801EB8: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
    // 0x80801EBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801EC0: lh          $t8, 0x128($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X128);
    // 0x80801EC4: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x80801EC8: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x80801ECC: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80801ED0: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80801ED4: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
    // 0x80801ED8: lh          $t3, 0x92($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X92);
    // 0x80801EDC: bnel        $t3, $zero, L_80801EF8
    if (ctx->r11 != 0) {
        // 0x80801EE0: lh          $t4, 0x96($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X96);
            goto L_80801EF8;
    }
    goto skip_0;
    // 0x80801EE0: lh          $t4, 0x96($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X96);
    skip_0:
    // 0x80801EE4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80801EE8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80801EEC: b           L_80801F2C
    // 0x80801EF0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
        goto L_80801F2C;
    // 0x80801EF0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80801EF4: lh          $t4, 0x96($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X96);
L_80801EF8:
    // 0x80801EF8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801EFC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2D60) << 16);
    // 0x80801F00: lwc1        $f6, 0x2D60($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2D60));
    // 0x80801F04: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80801F08: lui         $a3, 0x44FA
    ctx->r7 = S32(0X44FA << 16);
    // 0x80801F0C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80801F10: jal         0x800F10B4
    // 0x80801F14: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80801F14: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_6:
    // 0x80801F18: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80801F1C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80801F20: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x80801F24: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    // 0x80801F28: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_80801F2C:
    // 0x80801F2C: jal         0x800EF368
    // 0x80801F30: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EF368(rdram, ctx);
        goto after_7;
    // 0x80801F30: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_7:
    // 0x80801F34: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80801F38: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80801F3C: sw          $t0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r8;
L_80801F40:
    // 0x80801F40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801F44: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801F48: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80801F4C: jr          $ra
    // 0x80801F50: nop

    return;
    // 0x80801F50: nop

;}
RECOMP_FUNC void func_80800930_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800930: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800934: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800938: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080093C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800940: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800944: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80800948: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080094C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800950: lui         $a1, 0x4366
    ctx->r5 = S32(0X4366 << 16);
    // 0x80800954: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800958: jal         0x80089F20
    // 0x8080095C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080095C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_0:
    // 0x80800960: jal         0x80089828
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800968: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080096C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800970: jal         0x800897D8
    // 0x80800974: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800974: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800978: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x8080097C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800980: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x80800984: beq         $t7, $at, L_808009B0
    if (ctx->r15 == ctx->r1) {
        // 0x80800988: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808009B0;
    }
    // 0x80800988: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080098C: beq         $t7, $at, L_80800A58
    if (ctx->r15 == ctx->r1) {
        // 0x80800990: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800A58;
    }
    // 0x80800990: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800994: beq         $t7, $at, L_80800A78
    if (ctx->r15 == ctx->r1) {
        // 0x80800998: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A78;
    }
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080099C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808009A0: beq         $t7, $at, L_80800AB8
    if (ctx->r15 == ctx->r1) {
        // 0x808009A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AB8;
    }
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009A8: b           L_80800ADC
    // 0x808009AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800ADC;
    // 0x808009AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009B0:
    // 0x808009B0: jal         0x800F54E4
    // 0x808009B4: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x808009B4: nop

    after_3:
    // 0x808009B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009BC: jal         0x800F64A4
    // 0x808009C0: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    func_800F64A4(rdram, ctx);
        goto after_4;
    // 0x808009C0: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    after_4:
    // 0x808009C4: beq         $v0, $zero, L_80800AD8
    if (ctx->r2 == 0) {
        // 0x808009C8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800AD8;
    }
    // 0x808009C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808009CC: jal         0x8010CA74
    // 0x808009D0: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    func_8010CA74(rdram, ctx);
        goto after_5;
    // 0x808009D0: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    after_5:
    // 0x808009D4: beq         $v0, $zero, L_80800AD8
    if (ctx->r2 == 0) {
        // 0x808009D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AD8;
    }
    // 0x808009D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009DC: jal         0x80102424
    // 0x808009E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x808009E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808009EC: jal         0x80800F3C
    // 0x808009F0: addiu       $a2, $zero, 0x220
    ctx->r6 = ADD32(0, 0X220);
    func_80800F3C_chjollyroger(rdram, ctx);
        goto after_7;
    // 0x808009F0: addiu       $a2, $zero, 0x220
    ctx->r6 = ADD32(0, 0X220);
    after_7:
    // 0x808009F4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808009F8: jal         0x800EE7F8
    // 0x808009FC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x808009FC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x80800A00: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800A04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A08: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800A0C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800A10: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    // 0x80800A14: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800A18: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800A1C: jal         0x800EF1B8
    // 0x80800A20: nop

    func_800EF1B8(rdram, ctx);
        goto after_9;
    // 0x80800A20: nop

    after_9:
    // 0x80800A24: jal         0x8008F8B0
    // 0x80800A28: nop

    func_8008F8B0(rdram, ctx);
        goto after_10;
    // 0x80800A28: nop

    after_10:
    // 0x80800A2C: jal         0x8008F8D8
    // 0x80800A30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F8D8(rdram, ctx);
        goto after_11;
    // 0x80800A30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x80800A34: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80800A38: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x80800A3C: jal         0x8008F904
    // 0x80800A40: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_8008F904(rdram, ctx);
        goto after_12;
    // 0x80800A40: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_12:
    // 0x80800A44: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800A48: jal         0x8008F990
    // 0x80800A4C: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    func_8008F990(rdram, ctx);
        goto after_13;
    // 0x80800A4C: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    after_13:
    // 0x80800A50: b           L_80800ADC
    // 0x80800A54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800ADC;
    // 0x80800A54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A58:
    // 0x80800A58: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80800A5C: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x80800A60: bgezl       $t0, L_80800ADC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800A64: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800ADC;
    }
    goto skip_0;
    // 0x80800A64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800A68: jal         0x80800CC4
    // 0x80800A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CC4_chjollyroger(rdram, ctx);
        goto after_14;
    // 0x80800A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800A70: b           L_80800ADC
    // 0x80800A74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800ADC;
    // 0x80800A74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A78:
    // 0x80800A78: jal         0x80105230
    // 0x80800A7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80105230(rdram, ctx);
        goto after_15;
    // 0x80800A7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80800A80: jal         0x80105854
    // 0x80800A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105854(rdram, ctx);
        goto after_16;
    // 0x80800A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800A88: jal         0x80105A5C
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_17;
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800A90: beql        $v0, $zero, L_80800ADC
    if (ctx->r2 == 0) {
        // 0x80800A94: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800ADC;
    }
    goto skip_1;
    // 0x80800A94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800A98: jal         0x800DA544
    // 0x80800A9C: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    func_800DA544(rdram, ctx);
        goto after_18;
    // 0x80800A9C: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_18:
    // 0x80800AA0: jal         0x800DA524
    // 0x80800AA4: addiu       $a0, $zero, 0xC3
    ctx->r4 = ADD32(0, 0XC3);
    func_800DA524(rdram, ctx);
        goto after_19;
    // 0x80800AA4: addiu       $a0, $zero, 0xC3
    ctx->r4 = ADD32(0, 0XC3);
    after_19:
    // 0x80800AA8: jal         0x80800E30
    // 0x80800AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E30_chjollyroger(rdram, ctx);
        goto after_20;
    // 0x80800AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800AB0: b           L_80800ADC
    // 0x80800AB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800ADC;
    // 0x80800AB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800AB8:
    // 0x80800AB8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1036, 0X1458) << 16);
    // 0x80800ABC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1036, 0X1270) << 16);
    // 0x80800AC0: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80800AC4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800AC8: addiu       $a3, $a3, 0x1270
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1036, 0X1270));
    // 0x80800ACC: addiu       $a2, $a2, 0x1458
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1036, 0X1458));
    // 0x80800AD0: jal         0x8008A1F0
    // 0x80800AD4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_21;
    // 0x80800AD4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_21:
L_80800AD8:
    // 0x80800AD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800ADC:
    // 0x80800ADC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800AE0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800AE4: jr          $ra
    // 0x80800AE8: nop

    return;
    // 0x80800AE8: nop

;}
RECOMP_FUNC void func_80800030_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080003C: jal         0x80088848
    // 0x80800040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800044: beq         $v0, $zero, L_8080005C
    if (ctx->r2 == 0) {
        // 0x80800048: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080005C;
    }
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: jal         0x80102424
    // 0x80800050: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800050: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x80800054: b           L_8080007C
    // 0x80800058: lhu         $a1, 0x64($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X64);
        goto L_8080007C;
    // 0x80800058: lhu         $a1, 0x64($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X64);
L_8080005C:
    // 0x8080005C: jal         0x800DA298
    // 0x80800060: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800060: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    after_2:
    // 0x80800064: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800068: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x8080006C: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x80800070: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80800074: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80800078: lhu         $a1, 0x64($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X64);
L_8080007C:
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: andi        $t1, $a1, 0x1
    ctx->r9 = ctx->r5 & 0X1;
    // 0x80800084: jal         0x80103110
    // 0x80800088: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    func_80103110(rdram, ctx);
        goto after_3;
    // 0x80800088: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_3:
    // 0x8080008C: addiu       $a0, $zero, 0x331
    ctx->r4 = ADD32(0, 0X331);
    // 0x80800090: jal         0x80089C30
    // 0x80800094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800098: beq         $v0, $zero, L_808000B0
    if (ctx->r2 == 0) {
        // 0x8080009C: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_808000B0;
    }
    // 0x8080009C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808000A0: jal         0x800EE7F8
    // 0x808000A4: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x808000A4: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_5:
    // 0x808000A8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808000AC: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
L_808000B0:
    // 0x808000B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000BC: jr          $ra
    // 0x808000C0: nop

    return;
    // 0x808000C0: nop

;}
RECOMP_FUNC void func_808016B8_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016B8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808016BC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808016C0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808016C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808016C8: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x808016CC: jal         0x8009C128
    // 0x808016D0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x808016D0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x808016D4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808016D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808016DC: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808016E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016E4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808016E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808016EC: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x808016F0: jal         0x8009FBB0
    // 0x808016F4: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    func_8009FBB0(rdram, ctx);
        goto after_1;
    // 0x808016F4: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x808016F8: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x808016FC: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80801700: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80801704: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80801708: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8080170C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801710: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801714: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801718: addiu       $a1, $zero, -0x1E
    ctx->r5 = ADD32(0, -0X1E);
    // 0x8080171C: addiu       $a2, $zero, -0x1E
    ctx->r6 = ADD32(0, -0X1E);
    // 0x80801720: jal         0x800BA930
    // 0x80801724: addiu       $a3, $zero, -0x1E
    ctx->r7 = ADD32(0, -0X1E);
    func_800BA930(rdram, ctx);
        goto after_2;
    // 0x80801724: addiu       $a3, $zero, -0x1E
    ctx->r7 = ADD32(0, -0X1E);
    after_2:
    // 0x80801728: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8080172C: jal         0x800BA22C
    // 0x80801730: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x80801730: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80801734: lwc1        $f12, 0x178($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X178);
    // 0x80801738: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8080173C: nop

    // 0x80801740: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x80801744: nop

    // 0x80801748: bc1f        L_8080178C
    if (!c1cs) {
        // 0x8080174C: nop
    
            goto L_8080178C;
    }
    // 0x8080174C: nop

    // 0x80801750: jal         0x800F2100
    // 0x80801754: nop

    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x80801754: nop

    after_4:
    // 0x80801758: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(120, 0X1D70) << 16);
    // 0x8080175C: lwc1        $f16, 0x1D70($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(120, 0X1D70));
    // 0x80801760: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80801764: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801768: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8080176C: jal         0x800F0E00
    // 0x80801770: nop

    func_800F0E00(rdram, ctx);
        goto after_5;
    // 0x80801770: nop

    after_5:
    // 0x80801774: lwc1        $f18, 0x178($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X178);
    // 0x80801778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080177C: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80801780: swc1        $f4, 0x178($s0)
    MEM_W(0X178, ctx->r16) = ctx->f4.u32l;
    // 0x80801784: jal         0x8009BA58
    // 0x80801788: lw          $a1, 0x178($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X178);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_6;
    // 0x80801788: lw          $a1, 0x178($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X178);
    after_6:
L_8080178C:
    // 0x8080178C: jal         0x8008E078
    // 0x80801790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_7;
    // 0x80801790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801794: beq         $v0, $zero, L_808017A0
    if (ctx->r2 == 0) {
        // 0x80801798: addiu       $t9, $zero, 0x2D
        ctx->r25 = ADD32(0, 0X2D);
            goto L_808017A0;
    }
    // 0x80801798: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x8080179C: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
L_808017A0:
    // 0x808017A0: jal         0x8008E35C
    // 0x808017A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_8;
    // 0x808017A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808017A8: bne         $v0, $zero, L_808017B4
    if (ctx->r2 != 0) {
        // 0x808017AC: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_808017B4;
    }
    // 0x808017AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808017B0: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_808017B4:
    // 0x808017B4: jal         0x8009BB50
    // 0x808017B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_9;
    // 0x808017B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808017BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808017C0: addiu       $t1, $zero, 0x2D
    ctx->r9 = ADD32(0, 0X2D);
    // 0x808017C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017C8: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x808017CC: nop

    // 0x808017D0: bc1f        L_808017DC
    if (!c1cs) {
        // 0x808017D4: nop
    
            goto L_808017DC;
    }
    // 0x808017D4: nop

    // 0x808017D8: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
L_808017DC:
    // 0x808017DC: jal         0x8009E5C8
    // 0x808017E0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    bs_setState(rdram, ctx);
        goto after_10;
    // 0x808017E0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_10:
    // 0x808017E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808017E8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808017EC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808017F0: jr          $ra
    // 0x808017F4: nop

    return;
    // 0x808017F4: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A80: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A80);
    return;
    // 0x80082A84: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void _sucoasterflydata_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A288: syscall     832
    recomp_syscall_handler(rdram, ctx, 0x8008A288);
    return;
    // 0x8008A28C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800C1210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1210: lbu         $t9, 0x7A($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X7A);
    // 0x800C1214: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C1218: andi        $t8, $t7, 0x1C
    ctx->r24 = ctx->r15 & 0X1C;
    // 0x800C121C: andi        $t0, $t9, 0xFFE3
    ctx->r8 = ctx->r25 & 0XFFE3;
    // 0x800C1220: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x800C1224: jr          $ra
    // 0x800C1228: sb          $t1, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r9;
    return;
    // 0x800C1228: sb          $t1, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80800D14_sudeflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D14: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800D18: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80800D1C: lui         $s7, 0x8080
    ctx->r23 = S32(RELOC_HI16(3222, 0X1020) << 16);
    // 0x80800D20: lw          $s7, 0x1020($s7)
    ctx->r23 = MEM_W(ctx->r23, (int16_t)RELOC_LO16(3222, 0X1020));
    // 0x80800D24: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800D28: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80800D2C: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800D30: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80800D34: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800D38: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800D3C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800D40: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800D44: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800D48: lw          $a2, 0x0($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X0);
    // 0x80800D4C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800D50: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80800D54: beq         $a2, $zero, L_80800E10
    if (ctx->r6 == 0) {
        // 0x80800D58: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80800E10;
    }
    // 0x80800D58: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800D5C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800D60: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800D64: addiu       $s6, $zero, 0x27A
    ctx->r22 = ADD32(0, 0X27A);
L_80800D68:
    // 0x80800D68: jal         0x800E9E88
    // 0x80800D6C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800E9E88(rdram, ctx);
        goto after_0;
    // 0x80800D6C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80800D70: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800D74: jal         0x800E9EB4
    // 0x80800D78: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_1;
    // 0x80800D78: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    after_1:
    // 0x80800D7C: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80800D80: beq         $at, $zero, L_80800E00
    if (ctx->r1 == 0) {
        // 0x80800D84: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80800E00;
    }
    // 0x80800D84: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800D88: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
L_80800D8C:
    // 0x80800D8C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80800D90: beql        $t7, $zero, L_80800DF4
    if (ctx->r15 == 0) {
        // 0x80800D94: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80800DF4;
    }
    goto skip_0;
    // 0x80800D94: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_0:
    // 0x80800D98: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80800D9C: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x80800DA0: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x80800DA4: bnel        $s6, $t9, L_80800DF4
    if (ctx->r22 != ctx->r25) {
        // 0x80800DA8: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80800DF4;
    }
    goto skip_1;
    // 0x80800DA8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_1:
    // 0x80800DAC: jal         0x80106790
    // 0x80800DB0: nop

    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80800DB0: nop

    after_2:
    // 0x80800DB4: lw          $t0, 0x64($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X64);
    // 0x80800DB8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800DBC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800DC0: sll         $t2, $t0, 14
    ctx->r10 = S32(ctx->r8 << 14);
    // 0x80800DC4: bltz        $t2, L_80800DF0
    if (SIGNED(ctx->r10) < 0) {
        // 0x80800DC8: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_80800DF0;
    }
    // 0x80800DC8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800DCC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800DD0: jal         0x80800ECC
    // 0x80800DD4: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    func_80800ECC_sudeflect(rdram, ctx);
        goto after_3;
    // 0x80800DD4: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    after_3:
    // 0x80800DD8: beq         $v0, $zero, L_80800DF0
    if (ctx->r2 == 0) {
        // 0x80800DDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DF0;
    }
    // 0x80800DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DE0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800DE4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800DE8: jal         0x8010108C
    // 0x80800DEC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_8010108C(rdram, ctx);
        goto after_4;
    // 0x80800DEC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_4:
L_80800DF0:
    // 0x80800DF0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_80800DF4:
    // 0x80800DF4: sltu        $at, $s1, $s3
    ctx->r1 = ctx->r17 < ctx->r19 ? 1 : 0;
    // 0x80800DF8: bnel        $at, $zero, L_80800D8C
    if (ctx->r1 != 0) {
        // 0x80800DFC: lw          $t6, 0x8($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X8);
            goto L_80800D8C;
    }
    goto skip_2;
    // 0x80800DFC: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    skip_2:
L_80800E00:
    // 0x80800E00: lw          $a2, 0x4($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X4);
    // 0x80800E04: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80800E08: bne         $a2, $zero, L_80800D68
    if (ctx->r6 != 0) {
        // 0x80800E0C: nop
    
            goto L_80800D68;
    }
    // 0x80800E0C: nop

L_80800E10:
    // 0x80800E10: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800E14: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80800E18: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800E1C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800E20: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E24: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800E28: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800E2C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E30: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800E34: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80800E38: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80800E3C: jr          $ra
    // 0x80800E40: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800E40: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800B21CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B21CC: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800B21D0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B21D4: nop

    // 0x800B21D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B21DC: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x800B21E0: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x800B21E4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800B21E8: nop

    // 0x800B21EC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B21F0: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x800B21F4: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x800B21F8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800B21FC: nop

    // 0x800B2200: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B2204: swc1        $f18, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f18.u32l;
    // 0x800B2208: lh          $t9, 0x6($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X6);
    // 0x800B220C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800B2210: nop

    // 0x800B2214: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B2218: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x800B221C: lh          $t0, 0x8($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X8);
    // 0x800B2220: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800B2224: nop

    // 0x800B2228: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B222C: swc1        $f10, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f10.u32l;
    // 0x800B2230: lh          $t1, 0xA($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XA);
    // 0x800B2234: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800B2238: nop

    // 0x800B223C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B2240: jr          $ra
    // 0x800B2244: swc1        $f18, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f18.u32l;
    return;
    // 0x800B2244: swc1        $f18, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_8009BFBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BFBC: lw          $v0, 0xDC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XDC);
    // 0x8009BFC0: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8009BFC4: jr          $ra
    // 0x8009BFC8: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x8009BFC8: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void glsplineDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x808000C8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x808000CC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x808000D0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x808000D4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x808000D8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x808000DC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x808000E0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x808000E4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x808000E8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x808000EC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808000F0: jal         0x800E6A00
    // 0x808000F4: sw          $a0, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r4;
    func_800E6A00(rdram, ctx);
        goto after_0;
    // 0x808000F4: sw          $a0, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000F8: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x808000FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800100: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800104: jal         0x8001B668
    // 0x80800108: sb          $v0, 0x1A8($t6)
    MEM_B(0X1A8, ctx->r14) = ctx->r2;
    func_8001B668(rdram, ctx);
        goto after_1;
    // 0x80800108: sb          $v0, 0x1A8($t6)
    MEM_B(0X1A8, ctx->r14) = ctx->r2;
    after_1:
    // 0x8080010C: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    // 0x80800110: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800118: jal         0x8001B668
    // 0x8080011C: sh          $v0, 0x184($t7)
    MEM_H(0X184, ctx->r15) = ctx->r2;
    func_8001B668(rdram, ctx);
        goto after_2;
    // 0x8080011C: sh          $v0, 0x184($t7)
    MEM_H(0X184, ctx->r15) = ctx->r2;
    after_2:
    // 0x80800120: lw          $v1, 0x148($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X148);
    // 0x80800124: sh          $v0, 0x186($v1)
    MEM_H(0X186, ctx->r3) = ctx->r2;
    // 0x80800128: jal         0x80087C88
    // 0x8080012C: sw          $zero, 0x188($v1)
    MEM_W(0X188, ctx->r3) = 0;
    _gccubeDll_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x8080012C: sw          $zero, 0x188($v1)
    MEM_W(0X188, ctx->r3) = 0;
    after_3:
    // 0x80800130: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80800134: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80800138: bne         $at, $zero, L_80800A88
    if (ctx->r1 != 0) {
        // 0x8080013C: sll         $a0, $v1, 4
        ctx->r4 = S32(ctx->r3 << 4);
            goto L_80800A88;
    }
    // 0x8080013C: sll         $a0, $v1, 4
    ctx->r4 = S32(ctx->r3 << 4);
    // 0x80800140: jal         0x8001ACCC
    // 0x80800144: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    heap_alloc(rdram, ctx);
        goto after_4;
    // 0x80800144: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    after_4:
    // 0x80800148: lw          $t0, 0x144($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X144);
    // 0x8080014C: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x80800150: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800154: blez        $t0, L_808001CC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80800158: addiu       $a2, $sp, 0x128
        ctx->r6 = ADD32(ctx->r29, 0X128);
            goto L_808001CC;
    }
    // 0x80800158: addiu       $a2, $sp, 0x128
    ctx->r6 = ADD32(ctx->r29, 0X128);
    // 0x8080015C: andi        $a1, $t0, 0x3
    ctx->r5 = ctx->r8 & 0X3;
    // 0x80800160: beq         $a1, $zero, L_80800184
    if (ctx->r5 == 0) {
        // 0x80800164: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80800184;
    }
    // 0x80800164: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800168: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_8080016C:
    // 0x8080016C: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x80800170: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80800174: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800178: bne         $a0, $v1, L_8080016C
    if (ctx->r4 != ctx->r3) {
        // 0x8080017C: sh          $s2, 0x0($t9)
        MEM_H(0X0, ctx->r25) = ctx->r18;
            goto L_8080016C;
    }
    // 0x8080017C: sh          $s2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r18;
    // 0x80800180: beq         $v1, $t0, L_808001CC
    if (ctx->r3 == ctx->r8) {
        // 0x80800184: addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
            goto L_808001CC;
    }
L_80800184:
    // 0x80800184: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_80800188:
    // 0x80800188: sll         $t3, $v1, 4
    ctx->r11 = S32(ctx->r3 << 4);
    // 0x8080018C: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x80800190: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80800194: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80800198: addiu       $t8, $v1, 0x2
    ctx->r24 = ADD32(ctx->r3, 0X2);
    // 0x8080019C: sh          $s2, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r18;
    // 0x808001A0: addiu       $t4, $v1, 0x3
    ctx->r12 = ADD32(ctx->r3, 0X3);
    // 0x808001A4: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x808001A8: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x808001AC: sh          $s2, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r18;
    // 0x808001B0: addu        $t3, $v0, $t9
    ctx->r11 = ADD32(ctx->r2, ctx->r25);
    // 0x808001B4: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x808001B8: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x808001BC: sh          $s2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r18;
    // 0x808001C0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808001C4: bne         $v1, $t0, L_80800188
    if (ctx->r3 != ctx->r8) {
        // 0x808001C8: sh          $s2, 0x0($t6)
        MEM_H(0X0, ctx->r14) = ctx->r18;
            goto L_80800188;
    }
    // 0x808001C8: sh          $s2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r18;
L_808001CC:
    // 0x808001CC: addiu       $t7, $sp, 0x118
    ctx->r15 = ADD32(ctx->r29, 0X118);
    // 0x808001D0: addiu       $t8, $sp, 0x114
    ctx->r24 = ADD32(ctx->r29, 0X114);
    // 0x808001D4: addiu       $t9, $sp, 0x110
    ctx->r25 = ADD32(ctx->r29, 0X110);
    // 0x808001D8: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x808001DC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x808001E0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808001E4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808001E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808001EC: addiu       $a1, $sp, 0x12C
    ctx->r5 = ADD32(ctx->r29, 0X12C);
    // 0x808001F0: jal         0x80088308
    // 0x808001F4: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    _gccubesearch_entrypoint_18(rdram, ctx);
        goto after_5;
    // 0x808001F4: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    after_5:
    // 0x808001F8: addiu       $s7, $sp, 0xFC
    ctx->r23 = ADD32(ctx->r29, 0XFC);
    // 0x808001FC: addiu       $s6, $sp, 0x100
    ctx->r22 = ADD32(ctx->r29, 0X100);
    // 0x80800200: addiu       $s5, $sp, 0x104
    ctx->r21 = ADD32(ctx->r29, 0X104);
    // 0x80800204: addiu       $s4, $sp, 0x108
    ctx->r20 = ADD32(ctx->r29, 0X108);
    // 0x80800208: addiu       $s3, $sp, 0x10C
    ctx->r19 = ADD32(ctx->r29, 0X10C);
    // 0x8080020C: addiu       $t3, $sp, 0x118
    ctx->r11 = ADD32(ctx->r29, 0X118);
L_80800210:
    // 0x80800210: addiu       $t4, $sp, 0x114
    ctx->r12 = ADD32(ctx->r29, 0X114);
    // 0x80800214: addiu       $t5, $sp, 0x110
    ctx->r13 = ADD32(ctx->r29, 0X110);
    // 0x80800218: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8080021C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80800220: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800224: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800228: addiu       $a1, $sp, 0x12C
    ctx->r5 = ADD32(ctx->r29, 0X12C);
    // 0x8080022C: addiu       $a2, $sp, 0x128
    ctx->r6 = ADD32(ctx->r29, 0X128);
    // 0x80800230: jal         0x80088308
    // 0x80800234: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    _gccubesearch_entrypoint_18(rdram, ctx);
        goto after_6;
    // 0x80800234: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    after_6:
    // 0x80800238: bltz        $v0, L_80800398
    if (SIGNED(ctx->r2) < 0) {
        // 0x8080023C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80800398;
    }
    // 0x8080023C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800240: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80800244: addu        $s0, $fp, $t6
    ctx->r16 = ADD32(ctx->r30, ctx->r14);
    // 0x80800248: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x8080024C: lw          $t7, 0x128($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X128);
    // 0x80800250: lbu         $t5, 0x8($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X8);
    // 0x80800254: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800258: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x8080025C: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x80800260: andi        $t6, $t5, 0xFFDF
    ctx->r14 = ctx->r13 & 0XFFDF;
    // 0x80800264: addiu       $t5, $sp, 0xF8
    ctx->r13 = ADD32(ctx->r29, 0XF8);
    // 0x80800268: sll         $t3, $t9, 5
    ctx->r11 = S32(ctx->r25 << 5);
    // 0x8080026C: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x80800270: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80800274: sb          $t7, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r15;
    // 0x80800278: lw          $t8, 0x12C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X12C);
    // 0x8080027C: addiu       $t4, $sp, 0xF4
    ctx->r12 = ADD32(ctx->r29, 0XF4);
    // 0x80800280: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800284: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x80800288: lw          $t9, 0x130($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X130);
    // 0x8080028C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80800290: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x80800294: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x80800298: lw          $t3, 0x134($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X134);
    // 0x8080029C: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
    // 0x808002A0: lw          $t6, 0x110($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X110);
    // 0x808002A4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x808002A8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x808002AC: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x808002B0: jal         0x80800000
    // 0x808002B4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80800000_glsplineDll(rdram, ctx);
        goto after_7;
    // 0x808002B4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_7:
    // 0x808002B8: beql        $v0, $zero, L_80800390
    if (ctx->r2 == 0) {
        // 0x808002BC: lbu         $t9, 0xC($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0XC);
            goto L_80800390;
    }
    goto skip_0;
    // 0x808002BC: lbu         $t9, 0xC($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XC);
    skip_0:
    // 0x808002C0: lbu         $t7, 0xC($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XC);
    // 0x808002C4: andi        $t8, $t7, 0xFF03
    ctx->r24 = ctx->r15 & 0XFF03;
    // 0x808002C8: ori         $t9, $t8, 0x2C
    ctx->r25 = ctx->r24 | 0X2C;
    // 0x808002CC: sb          $t9, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r25;
    // 0x808002D0: lw          $t5, 0x10C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10C);
    // 0x808002D4: lbu         $t7, 0x9($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X9);
    // 0x808002D8: sll         $t4, $t5, 1
    ctx->r12 = S32(ctx->r13 << 1);
    // 0x808002DC: andi        $t6, $t4, 0x2
    ctx->r14 = ctx->r12 & 0X2;
    // 0x808002E0: andi        $t8, $t7, 0xFFFD
    ctx->r24 = ctx->r15 & 0XFFFD;
    // 0x808002E4: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x808002E8: sb          $t7, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r15;
    // 0x808002EC: lw          $t5, 0x108($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X108);
    // 0x808002F0: andi        $t6, $t7, 0xFE
    ctx->r14 = ctx->r15 & 0XFE;
    // 0x808002F4: andi        $t4, $t5, 0x1
    ctx->r12 = ctx->r13 & 0X1;
    // 0x808002F8: or          $t8, $t4, $t6
    ctx->r24 = ctx->r12 | ctx->r14;
    // 0x808002FC: sb          $t8, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r24;
    // 0x80800300: lw          $t3, 0x104($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X104);
    // 0x80800304: lhu         $t4, 0x8($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X8);
    // 0x80800308: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x8080030C: andi        $t7, $t5, 0x1FF8
    ctx->r15 = ctx->r13 & 0X1FF8;
    // 0x80800310: andi        $t6, $t4, 0xE007
    ctx->r14 = ctx->r12 & 0XE007;
    // 0x80800314: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80800318: sh          $t8, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r24;
    // 0x8080031C: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x80800320: lbu         $t7, 0x9($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X9);
    // 0x80800324: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80800328: andi        $t4, $t5, 0x4
    ctx->r12 = ctx->r13 & 0X4;
    // 0x8080032C: andi        $t6, $t7, 0xFFFB
    ctx->r14 = ctx->r15 & 0XFFFB;
    // 0x80800330: or          $t8, $t4, $t6
    ctx->r24 = ctx->r12 | ctx->r14;
    // 0x80800334: sb          $t8, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r24;
    // 0x80800338: lw          $t3, 0xFC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XFC);
    // 0x8080033C: lhu         $t4, 0xC($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XC);
    // 0x80800340: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x80800344: andi        $t7, $t5, 0x3FE
    ctx->r15 = ctx->r13 & 0X3FE;
    // 0x80800348: andi        $t6, $t4, 0xFC01
    ctx->r14 = ctx->r12 & 0XFC01;
    // 0x8080034C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80800350: sh          $t8, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r24;
    // 0x80800354: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x80800358: lhu         $t7, 0xE($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XE);
    // 0x8080035C: sll         $t4, $t3, 7
    ctx->r12 = S32(ctx->r11 << 7);
    // 0x80800360: andi        $t6, $t7, 0x7F
    ctx->r14 = ctx->r15 & 0X7F;
    // 0x80800364: or          $t8, $t4, $t6
    ctx->r24 = ctx->r12 | ctx->r14;
    // 0x80800368: sh          $t8, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r24;
    // 0x8080036C: lw          $t3, 0xF4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF4);
    // 0x80800370: lbu         $t4, 0xF($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XF);
    // 0x80800374: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80800378: andi        $t7, $t5, 0x7C
    ctx->r15 = ctx->r13 & 0X7C;
    // 0x8080037C: andi        $t6, $t4, 0xFF83
    ctx->r14 = ctx->r12 & 0XFF83;
    // 0x80800380: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80800384: b           L_80800398
    // 0x80800388: sb          $t8, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r24;
        goto L_80800398;
    // 0x80800388: sb          $t8, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r24;
    // 0x8080038C: lbu         $t9, 0xC($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XC);
L_80800390:
    // 0x80800390: andi        $t3, $t9, 0xFF03
    ctx->r11 = ctx->r25 & 0XFF03;
    // 0x80800394: sb          $t3, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r11;
L_80800398:
    // 0x80800398: bgezl       $s1, L_80800210
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8080039C: addiu       $t3, $sp, 0x118
        ctx->r11 = ADD32(ctx->r29, 0X118);
            goto L_80800210;
    }
    goto skip_1;
    // 0x8080039C: addiu       $t3, $sp, 0x118
    ctx->r11 = ADD32(ctx->r29, 0X118);
    skip_1:
    // 0x808003A0: lw          $a2, 0x144($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X144);
    // 0x808003A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808003A8: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x808003AC: bne         $at, $zero, L_808004C8
    if (ctx->r1 != 0) {
        // 0x808003B0: addiu       $v1, $a2, -0x1
        ctx->r3 = ADD32(ctx->r6, -0X1);
            goto L_808004C8;
    }
    // 0x808003B0: addiu       $v1, $a2, -0x1
    ctx->r3 = ADD32(ctx->r6, -0X1);
    // 0x808003B4: andi        $t5, $v1, 0x3
    ctx->r13 = ctx->r3 & 0X3;
    // 0x808003B8: beq         $t5, $zero, L_808003FC
    if (ctx->r13 == 0) {
        // 0x808003BC: addiu       $a1, $t5, 0x1
        ctx->r5 = ADD32(ctx->r13, 0X1);
            goto L_808003FC;
    }
    // 0x808003BC: addiu       $a1, $t5, 0x1
    ctx->r5 = ADD32(ctx->r13, 0X1);
    // 0x808003C0: sll         $t4, $a0, 4
    ctx->r12 = S32(ctx->r4 << 4);
L_808003C4:
    // 0x808003C4: addu        $v1, $fp, $t4
    ctx->r3 = ADD32(ctx->r30, ctx->r12);
    // 0x808003C8: lbu         $t7, 0x8($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X8);
    // 0x808003CC: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x808003D0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x808003D4: andi        $t6, $t7, 0xFF7F
    ctx->r14 = ctx->r15 & 0XFF7F;
    // 0x808003D8: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x808003DC: beq         $at, $zero, L_808003EC
    if (ctx->r1 == 0) {
        // 0x808003E0: sb          $t6, 0x8($v1)
        MEM_B(0X8, ctx->r3) = ctx->r14;
            goto L_808003EC;
    }
    // 0x808003E0: sb          $t6, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r14;
    // 0x808003E4: bne         $s2, $v0, L_808003F0
    if (ctx->r18 != ctx->r2) {
        // 0x808003E8: nop
    
            goto L_808003F0;
    }
    // 0x808003E8: nop

L_808003EC:
    // 0x808003EC: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_808003F0:
    // 0x808003F0: bnel        $a1, $a0, L_808003C4
    if (ctx->r5 != ctx->r4) {
        // 0x808003F4: sll         $t4, $a0, 4
        ctx->r12 = S32(ctx->r4 << 4);
            goto L_808003C4;
    }
    goto skip_2;
    // 0x808003F4: sll         $t4, $a0, 4
    ctx->r12 = S32(ctx->r4 << 4);
    skip_2:
    // 0x808003F8: beq         $a0, $a2, L_808004C4
    if (ctx->r4 == ctx->r6) {
        // 0x808003FC: sll         $t8, $a0, 4
        ctx->r24 = S32(ctx->r4 << 4);
            goto L_808004C4;
    }
L_808003FC:
    // 0x808003FC: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
L_80800400:
    // 0x80800400: addu        $v1, $fp, $t8
    ctx->r3 = ADD32(ctx->r30, ctx->r24);
    // 0x80800404: lbu         $t9, 0x8($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X8);
    // 0x80800408: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8080040C: addiu       $t5, $a0, 0x1
    ctx->r13 = ADD32(ctx->r4, 0X1);
    // 0x80800410: andi        $t3, $t9, 0xFF7F
    ctx->r11 = ctx->r25 & 0XFF7F;
    // 0x80800414: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80800418: beq         $at, $zero, L_80800428
    if (ctx->r1 == 0) {
        // 0x8080041C: sb          $t3, 0x8($v1)
        MEM_B(0X8, ctx->r3) = ctx->r11;
            goto L_80800428;
    }
    // 0x8080041C: sb          $t3, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r11;
    // 0x80800420: bnel        $s2, $v0, L_80800430
    if (ctx->r18 != ctx->r2) {
        // 0x80800424: sll         $t4, $t5, 4
        ctx->r12 = S32(ctx->r13 << 4);
            goto L_80800430;
    }
    goto skip_3;
    // 0x80800424: sll         $t4, $t5, 4
    ctx->r12 = S32(ctx->r13 << 4);
    skip_3:
L_80800428:
    // 0x80800428: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8080042C: sll         $t4, $t5, 4
    ctx->r12 = S32(ctx->r13 << 4);
L_80800430:
    // 0x80800430: addu        $v1, $fp, $t4
    ctx->r3 = ADD32(ctx->r30, ctx->r12);
    // 0x80800434: lbu         $t7, 0x8($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X8);
    // 0x80800438: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8080043C: addiu       $t8, $a0, 0x2
    ctx->r24 = ADD32(ctx->r4, 0X2);
    // 0x80800440: andi        $t6, $t7, 0xFF7F
    ctx->r14 = ctx->r15 & 0XFF7F;
    // 0x80800444: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80800448: beq         $at, $zero, L_80800458
    if (ctx->r1 == 0) {
        // 0x8080044C: sb          $t6, 0x8($v1)
        MEM_B(0X8, ctx->r3) = ctx->r14;
            goto L_80800458;
    }
    // 0x8080044C: sb          $t6, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r14;
    // 0x80800450: bnel        $s2, $v0, L_80800460
    if (ctx->r18 != ctx->r2) {
        // 0x80800454: sll         $t9, $t8, 4
        ctx->r25 = S32(ctx->r24 << 4);
            goto L_80800460;
    }
    goto skip_4;
    // 0x80800454: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    skip_4:
L_80800458:
    // 0x80800458: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8080045C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
L_80800460:
    // 0x80800460: addu        $v1, $fp, $t9
    ctx->r3 = ADD32(ctx->r30, ctx->r25);
    // 0x80800464: lbu         $t3, 0x8($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X8);
    // 0x80800468: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8080046C: addiu       $t4, $a0, 0x3
    ctx->r12 = ADD32(ctx->r4, 0X3);
    // 0x80800470: andi        $t5, $t3, 0xFF7F
    ctx->r13 = ctx->r11 & 0XFF7F;
    // 0x80800474: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80800478: beq         $at, $zero, L_80800488
    if (ctx->r1 == 0) {
        // 0x8080047C: sb          $t5, 0x8($v1)
        MEM_B(0X8, ctx->r3) = ctx->r13;
            goto L_80800488;
    }
    // 0x8080047C: sb          $t5, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r13;
    // 0x80800480: bnel        $s2, $v0, L_80800490
    if (ctx->r18 != ctx->r2) {
        // 0x80800484: sll         $t7, $t4, 4
        ctx->r15 = S32(ctx->r12 << 4);
            goto L_80800490;
    }
    goto skip_5;
    // 0x80800484: sll         $t7, $t4, 4
    ctx->r15 = S32(ctx->r12 << 4);
    skip_5:
L_80800488:
    // 0x80800488: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8080048C: sll         $t7, $t4, 4
    ctx->r15 = S32(ctx->r12 << 4);
L_80800490:
    // 0x80800490: addu        $v1, $fp, $t7
    ctx->r3 = ADD32(ctx->r30, ctx->r15);
    // 0x80800494: lbu         $t6, 0x8($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X8);
    // 0x80800498: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8080049C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808004A0: andi        $t8, $t6, 0xFF7F
    ctx->r24 = ctx->r14 & 0XFF7F;
    // 0x808004A4: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x808004A8: beq         $at, $zero, L_808004B8
    if (ctx->r1 == 0) {
        // 0x808004AC: sb          $t8, 0x8($v1)
        MEM_B(0X8, ctx->r3) = ctx->r24;
            goto L_808004B8;
    }
    // 0x808004AC: sb          $t8, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r24;
    // 0x808004B0: bne         $s2, $v0, L_808004BC
    if (ctx->r18 != ctx->r2) {
        // 0x808004B4: nop
    
            goto L_808004BC;
    }
    // 0x808004B4: nop

L_808004B8:
    // 0x808004B8: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_808004BC:
    // 0x808004BC: bnel        $a0, $a2, L_80800400
    if (ctx->r4 != ctx->r6) {
        // 0x808004C0: sll         $t8, $a0, 4
        ctx->r24 = S32(ctx->r4 << 4);
            goto L_80800400;
    }
    goto skip_6;
    // 0x808004C0: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    skip_6:
L_808004C4:
    // 0x808004C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_808004C8:
    // 0x808004C8: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x808004CC: bne         $at, $zero, L_808005C0
    if (ctx->r1 != 0) {
        // 0x808004D0: addiu       $v1, $a2, -0x1
        ctx->r3 = ADD32(ctx->r6, -0X1);
            goto L_808005C0;
    }
    // 0x808004D0: addiu       $v1, $a2, -0x1
    ctx->r3 = ADD32(ctx->r6, -0X1);
    // 0x808004D4: andi        $t9, $v1, 0x3
    ctx->r25 = ctx->r3 & 0X3;
    // 0x808004D8: beq         $t9, $zero, L_80800514
    if (ctx->r25 == 0) {
        // 0x808004DC: addiu       $a1, $t9, 0x1
        ctx->r5 = ADD32(ctx->r25, 0X1);
            goto L_80800514;
    }
    // 0x808004DC: addiu       $a1, $t9, 0x1
    ctx->r5 = ADD32(ctx->r25, 0X1);
    // 0x808004E0: sll         $t3, $a0, 4
    ctx->r11 = S32(ctx->r4 << 4);
L_808004E4:
    // 0x808004E4: addu        $t5, $t3, $fp
    ctx->r13 = ADD32(ctx->r11, ctx->r30);
    // 0x808004E8: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x808004EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x808004F0: blez        $v0, L_80800508
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808004F4: sll         $t4, $v0, 4
        ctx->r12 = S32(ctx->r2 << 4);
            goto L_80800508;
    }
    // 0x808004F4: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x808004F8: addu        $v1, $fp, $t4
    ctx->r3 = ADD32(ctx->r30, ctx->r12);
    // 0x808004FC: lbu         $t6, 0x8($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X8);
    // 0x80800500: ori         $t8, $t6, 0x80
    ctx->r24 = ctx->r14 | 0X80;
    // 0x80800504: sb          $t8, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r24;
L_80800508:
    // 0x80800508: bnel        $a1, $a0, L_808004E4
    if (ctx->r5 != ctx->r4) {
        // 0x8080050C: sll         $t3, $a0, 4
        ctx->r11 = S32(ctx->r4 << 4);
            goto L_808004E4;
    }
    goto skip_7;
    // 0x8080050C: sll         $t3, $a0, 4
    ctx->r11 = S32(ctx->r4 << 4);
    skip_7:
    // 0x80800510: beq         $a0, $a2, L_808005BC
    if (ctx->r4 == ctx->r6) {
        // 0x80800514: sll         $t9, $a0, 4
        ctx->r25 = S32(ctx->r4 << 4);
            goto L_808005BC;
    }
L_80800514:
    // 0x80800514: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
L_80800518:
    // 0x80800518: addu        $t3, $t9, $fp
    ctx->r11 = ADD32(ctx->r25, ctx->r30);
    // 0x8080051C: lh          $v0, 0x0($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X0);
    // 0x80800520: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x80800524: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800528: blez        $v0, L_80800544
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080052C: addu        $t3, $t9, $fp
        ctx->r11 = ADD32(ctx->r25, ctx->r30);
            goto L_80800544;
    }
    // 0x8080052C: addu        $t3, $t9, $fp
    ctx->r11 = ADD32(ctx->r25, ctx->r30);
    // 0x80800530: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x80800534: addu        $v1, $fp, $t5
    ctx->r3 = ADD32(ctx->r30, ctx->r13);
    // 0x80800538: lbu         $t7, 0x8($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X8);
    // 0x8080053C: ori         $t6, $t7, 0x80
    ctx->r14 = ctx->r15 | 0X80;
    // 0x80800540: sb          $t6, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r14;
L_80800544:
    // 0x80800544: lh          $v0, 0x0($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X0);
    // 0x80800548: addiu       $t8, $a0, 0x2
    ctx->r24 = ADD32(ctx->r4, 0X2);
    // 0x8080054C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800550: blez        $v0, L_8080056C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800554: addu        $t3, $t9, $fp
        ctx->r11 = ADD32(ctx->r25, ctx->r30);
            goto L_8080056C;
    }
    // 0x80800554: addu        $t3, $t9, $fp
    ctx->r11 = ADD32(ctx->r25, ctx->r30);
    // 0x80800558: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x8080055C: addu        $v1, $fp, $t5
    ctx->r3 = ADD32(ctx->r30, ctx->r13);
    // 0x80800560: lbu         $t7, 0x8($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X8);
    // 0x80800564: ori         $t6, $t7, 0x80
    ctx->r14 = ctx->r15 | 0X80;
    // 0x80800568: sb          $t6, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r14;
L_8080056C:
    // 0x8080056C: lh          $v0, 0x0($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X0);
    // 0x80800570: addiu       $t8, $a0, 0x3
    ctx->r24 = ADD32(ctx->r4, 0X3);
    // 0x80800574: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800578: blez        $v0, L_80800594
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080057C: addu        $t3, $t9, $fp
        ctx->r11 = ADD32(ctx->r25, ctx->r30);
            goto L_80800594;
    }
    // 0x8080057C: addu        $t3, $t9, $fp
    ctx->r11 = ADD32(ctx->r25, ctx->r30);
    // 0x80800580: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x80800584: addu        $v1, $fp, $t5
    ctx->r3 = ADD32(ctx->r30, ctx->r13);
    // 0x80800588: lbu         $t7, 0x8($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X8);
    // 0x8080058C: ori         $t6, $t7, 0x80
    ctx->r14 = ctx->r15 | 0X80;
    // 0x80800590: sb          $t6, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r14;
L_80800594:
    // 0x80800594: lh          $v0, 0x0($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X0);
    // 0x80800598: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080059C: blez        $v0, L_808005B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808005A0: sll         $t5, $v0, 4
        ctx->r13 = S32(ctx->r2 << 4);
            goto L_808005B4;
    }
    // 0x808005A0: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x808005A4: addu        $v1, $fp, $t5
    ctx->r3 = ADD32(ctx->r30, ctx->r13);
    // 0x808005A8: lbu         $t7, 0x8($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X8);
    // 0x808005AC: ori         $t6, $t7, 0x80
    ctx->r14 = ctx->r15 | 0X80;
    // 0x808005B0: sb          $t6, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r14;
L_808005B4:
    // 0x808005B4: bnel        $a0, $a2, L_80800518
    if (ctx->r4 != ctx->r6) {
        // 0x808005B8: sll         $t9, $a0, 4
        ctx->r25 = S32(ctx->r4 << 4);
            goto L_80800518;
    }
    goto skip_8;
    // 0x808005B8: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
    skip_8:
L_808005BC:
    // 0x808005BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_808005C0:
    // 0x808005C0: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x808005C4: bne         $at, $zero, L_8080065C
    if (ctx->r1 != 0) {
        // 0x808005C8: sll         $t8, $a0, 4
        ctx->r24 = S32(ctx->r4 << 4);
            goto L_8080065C;
    }
    // 0x808005C8: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
L_808005CC:
    // 0x808005CC: addu        $a1, $t8, $fp
    ctx->r5 = ADD32(ctx->r24, ctx->r30);
    // 0x808005D0: lhu         $v1, 0x8($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X8);
    // 0x808005D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005D8: sll         $t9, $v1, 18
    ctx->r25 = S32(ctx->r3 << 18);
    // 0x808005DC: srl         $t3, $t9, 31
    ctx->r11 = S32(U32(ctx->r25) >> 31);
    // 0x808005E0: bne         $t3, $at, L_8080064C
    if (ctx->r11 != ctx->r1) {
        // 0x808005E4: srl         $v0, $v1, 15
        ctx->r2 = S32(U32(ctx->r3) >> 15);
            goto L_8080064C;
    }
    // 0x808005E4: srl         $v0, $v1, 15
    ctx->r2 = S32(U32(ctx->r3) >> 15);
    // 0x808005E8: bne         $v0, $zero, L_808005FC
    if (ctx->r2 != 0) {
        // 0x808005EC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808005FC;
    }
    // 0x808005EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005F0: lh          $t5, 0x0($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X0);
    // 0x808005F4: bgtzl       $t5, L_80800650
    if (SIGNED(ctx->r13) > 0) {
        // 0x808005F8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80800650;
    }
    goto skip_9;
    // 0x808005F8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_9:
L_808005FC:
    // 0x808005FC: bnel        $v0, $at, L_80800610
    if (ctx->r2 != ctx->r1) {
        // 0x80800600: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800610;
    }
    goto skip_10;
    // 0x80800600: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_10:
    // 0x80800604: lh          $t4, 0x0($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X0);
    // 0x80800608: bgtz        $t4, L_8080064C
    if (SIGNED(ctx->r12) > 0) {
        // 0x8080060C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8080064C;
    }
    // 0x8080060C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80800610:
    // 0x80800610: bnel        $v0, $at, L_80800628
    if (ctx->r2 != ctx->r1) {
        // 0x80800614: sw          $a0, 0x140($sp)
        MEM_W(0X140, ctx->r29) = ctx->r4;
            goto L_80800628;
    }
    goto skip_11;
    // 0x80800614: sw          $a0, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r4;
    skip_11:
    // 0x80800618: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x8080061C: beql        $t7, $zero, L_80800650
    if (ctx->r15 == 0) {
        // 0x80800620: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80800650;
    }
    goto skip_12;
    // 0x80800620: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_12:
    // 0x80800624: sw          $a0, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r4;
L_80800628:
    // 0x80800628: jal         0x800E9EE8
    // 0x8080062C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    func_800E9EE8(rdram, ctx);
        goto after_8;
    // 0x8080062C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_8:
    // 0x80800630: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80800634: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x80800638: sh          $s2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r18;
    // 0x8080063C: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80800640: sb          $t8, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r24;
    // 0x80800644: lw          $a0, 0x140($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X140);
    // 0x80800648: lw          $a2, 0x144($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X144);
L_8080064C:
    // 0x8080064C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80800650:
    // 0x80800650: bnel        $a0, $a2, L_808005CC
    if (ctx->r4 != ctx->r6) {
        // 0x80800654: sll         $t8, $a0, 4
        ctx->r24 = S32(ctx->r4 << 4);
            goto L_808005CC;
    }
    goto skip_13;
    // 0x80800654: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    skip_13:
    // 0x80800658: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8080065C:
    // 0x8080065C: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x80800660: bne         $at, $zero, L_80800A80
    if (ctx->r1 != 0) {
        // 0x80800664: addiu       $s5, $sp, 0x9C
        ctx->r21 = ADD32(ctx->r29, 0X9C);
            goto L_80800A80;
    }
    // 0x80800664: addiu       $s5, $sp, 0x9C
    ctx->r21 = ADD32(ctx->r29, 0X9C);
    // 0x80800668: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
L_8080066C:
    // 0x8080066C: addu        $t1, $t9, $fp
    ctx->r9 = ADD32(ctx->r25, ctx->r30);
    // 0x80800670: lh          $v0, 0x0($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X0);
    // 0x80800674: blezl       $v0, L_80800A78
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800678: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80800A78;
    }
    goto skip_14;
    // 0x80800678: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_14:
    // 0x8080067C: lhu         $v1, 0x8($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X8);
    // 0x80800680: srl         $t3, $v1, 15
    ctx->r11 = S32(U32(ctx->r3) >> 15);
    // 0x80800684: bne         $t3, $zero, L_80800A74
    if (ctx->r11 != 0) {
        // 0x80800688: sll         $t4, $v1, 18
        ctx->r12 = S32(ctx->r3 << 18);
            goto L_80800A74;
    }
    // 0x80800688: sll         $t4, $v1, 18
    ctx->r12 = S32(ctx->r3 << 18);
    // 0x8080068C: bltz        $t4, L_80800A74
    if (SIGNED(ctx->r12) < 0) {
        // 0x80800690: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_80800A74;
    }
    // 0x80800690: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80800694: lw          $t0, 0x144($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X144);
    // 0x80800698: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8080069C: sw          $a0, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r4;
    // 0x808006A0: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x808006A4: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x808006A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808006AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808006B0: bne         $at, $zero, L_80800750
    if (ctx->r1 != 0) {
        // 0x808006B4: sw          $zero, 0xCC($sp)
        MEM_W(0XCC, ctx->r29) = 0;
            goto L_80800750;
    }
    // 0x808006B4: sw          $zero, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = 0;
    // 0x808006B8: addiu       $v1, $t0, -0x1
    ctx->r3 = ADD32(ctx->r8, -0X1);
    // 0x808006BC: andi        $t6, $v1, 0x3
    ctx->r14 = ctx->r3 & 0X3;
    // 0x808006C0: beq         $t6, $zero, L_808006E8
    if (ctx->r14 == 0) {
        // 0x808006C4: addiu       $v0, $t6, 0x1
        ctx->r2 = ADD32(ctx->r14, 0X1);
            goto L_808006E8;
    }
    // 0x808006C4: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
L_808006C8:
    // 0x808006C8: sll         $t8, $s4, 4
    ctx->r24 = S32(ctx->r20 << 4);
    // 0x808006CC: addu        $v1, $fp, $t8
    ctx->r3 = ADD32(ctx->r30, ctx->r24);
    // 0x808006D0: lbu         $t9, 0x8($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X8);
    // 0x808006D4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x808006D8: andi        $t3, $t9, 0xFFBF
    ctx->r11 = ctx->r25 & 0XFFBF;
    // 0x808006DC: bne         $v0, $s4, L_808006C8
    if (ctx->r2 != ctx->r20) {
        // 0x808006E0: sb          $t3, 0x8($v1)
        MEM_B(0X8, ctx->r3) = ctx->r11;
            goto L_808006C8;
    }
    // 0x808006E0: sb          $t3, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r11;
    // 0x808006E4: beq         $s4, $t0, L_8080074C
    if (ctx->r20 == ctx->r8) {
        // 0x808006E8: sll         $t5, $s4, 4
        ctx->r13 = S32(ctx->r20 << 4);
            goto L_8080074C;
    }
L_808006E8:
    // 0x808006E8: sll         $t5, $s4, 4
    ctx->r13 = S32(ctx->r20 << 4);
    // 0x808006EC: addu        $v1, $fp, $t5
    ctx->r3 = ADD32(ctx->r30, ctx->r13);
    // 0x808006F0: lbu         $t4, 0x8($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X8);
    // 0x808006F4: addiu       $t6, $s4, 0x1
    ctx->r14 = ADD32(ctx->r20, 0X1);
    // 0x808006F8: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x808006FC: andi        $t7, $t4, 0xFFBF
    ctx->r15 = ctx->r12 & 0XFFBF;
    // 0x80800700: addu        $v0, $fp, $t8
    ctx->r2 = ADD32(ctx->r30, ctx->r24);
    // 0x80800704: sb          $t7, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r15;
    // 0x80800708: lbu         $t9, 0x8($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X8);
    // 0x8080070C: addiu       $t5, $s4, 0x2
    ctx->r13 = ADD32(ctx->r20, 0X2);
    // 0x80800710: sll         $t4, $t5, 4
    ctx->r12 = S32(ctx->r13 << 4);
    // 0x80800714: andi        $t3, $t9, 0xFFBF
    ctx->r11 = ctx->r25 & 0XFFBF;
    // 0x80800718: sb          $t3, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r11;
    // 0x8080071C: addu        $a0, $fp, $t4
    ctx->r4 = ADD32(ctx->r30, ctx->r12);
    // 0x80800720: lbu         $t7, 0x8($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X8);
    // 0x80800724: addiu       $t8, $s4, 0x3
    ctx->r24 = ADD32(ctx->r20, 0X3);
    // 0x80800728: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8080072C: andi        $t6, $t7, 0xFFBF
    ctx->r14 = ctx->r15 & 0XFFBF;
    // 0x80800730: sb          $t6, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r14;
    // 0x80800734: addu        $a1, $fp, $t9
    ctx->r5 = ADD32(ctx->r30, ctx->r25);
    // 0x80800738: lbu         $t3, 0x8($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X8);
    // 0x8080073C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80800740: andi        $t5, $t3, 0xFFBF
    ctx->r13 = ctx->r11 & 0XFFBF;
    // 0x80800744: bne         $s4, $t0, L_808006E8
    if (ctx->r20 != ctx->r8) {
        // 0x80800748: sb          $t5, 0x8($a1)
        MEM_B(0X8, ctx->r5) = ctx->r13;
            goto L_808006E8;
    }
    // 0x80800748: sb          $t5, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r13;
L_8080074C:
    // 0x8080074C: lh          $v0, 0x0($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X0);
L_80800750:
    // 0x80800750: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x80800754: beq         $v0, $zero, L_808007E0
    if (ctx->r2 == 0) {
        // 0x80800758: or          $s4, $t2, $zero
        ctx->r20 = ctx->r10 | 0;
            goto L_808007E0;
    }
    // 0x80800758: or          $s4, $t2, $zero
    ctx->r20 = ctx->r10 | 0;
    // 0x8080075C: lhu         $t4, 0x8($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X8);
    // 0x80800760: sll         $t8, $s4, 4
    ctx->r24 = S32(ctx->r20 << 4);
    // 0x80800764: addu        $v1, $fp, $t8
    ctx->r3 = ADD32(ctx->r30, ctx->r24);
    // 0x80800768: sll         $t6, $t4, 17
    ctx->r14 = S32(ctx->r12 << 17);
    // 0x8080076C: bltzl       $t6, L_808007E4
    if (SIGNED(ctx->r14) < 0) {
        // 0x80800770: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808007E4;
    }
    goto skip_15;
    // 0x80800770: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_15:
    // 0x80800774: lbu         $t3, 0x8($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X8);
L_80800778:
    // 0x80800778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080077C: ori         $t5, $t3, 0x40
    ctx->r13 = ctx->r11 | 0X40;
    // 0x80800780: sb          $t5, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r13;
    // 0x80800784: lhu         $a0, 0x8($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X8);
    // 0x80800788: sll         $t4, $a0, 18
    ctx->r12 = S32(ctx->r4 << 18);
    // 0x8080078C: srl         $a0, $t4, 31
    ctx->r4 = S32(U32(ctx->r12) >> 31);
    // 0x80800790: bne         $a0, $zero, L_808007A0
    if (ctx->r4 != 0) {
        // 0x80800794: nop
    
            goto L_808007A0;
    }
    // 0x80800794: nop

    // 0x80800798: b           L_808007A0
    // 0x8080079C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007A0;
    // 0x8080079C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007A0:
    // 0x808007A0: bne         $a0, $zero, L_808007B0
    if (ctx->r4 != 0) {
        // 0x808007A4: addu        $a2, $a2, $v0
        ctx->r6 = ADD32(ctx->r6, ctx->r2);
            goto L_808007B0;
    }
    // 0x808007A4: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x808007A8: b           L_808007B4
    // 0x808007AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808007B4;
    // 0x808007AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007B0:
    // 0x808007B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007B4:
    // 0x808007B4: lh          $s4, 0x0($v1)
    ctx->r20 = MEM_H(ctx->r3, 0X0);
    // 0x808007B8: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x808007BC: sll         $t6, $s4, 4
    ctx->r14 = S32(ctx->r20 << 4);
    // 0x808007C0: addu        $v1, $t6, $fp
    ctx->r3 = ADD32(ctx->r14, ctx->r30);
    // 0x808007C4: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x808007C8: beql        $t8, $zero, L_808007E4
    if (ctx->r24 == 0) {
        // 0x808007CC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808007E4;
    }
    goto skip_16;
    // 0x808007CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_16:
    // 0x808007D0: lhu         $t9, 0x8($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X8);
    // 0x808007D4: sll         $t5, $t9, 17
    ctx->r13 = S32(ctx->r25 << 17);
    // 0x808007D8: bgezl       $t5, L_80800778
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808007DC: lbu         $t3, 0x8($v1)
        ctx->r11 = MEM_BU(ctx->r3, 0X8);
            goto L_80800778;
    }
    goto skip_17;
    // 0x808007DC: lbu         $t3, 0x8($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X8);
    skip_17:
L_808007E0:
    // 0x808007E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_808007E4:
    // 0x808007E4: sll         $a1, $a2, 2
    ctx->r5 = S32(ctx->r6 << 2);
    // 0x808007E8: or          $s4, $t2, $zero
    ctx->r20 = ctx->r10 | 0;
    // 0x808007EC: sw          $a2, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r6;
    // 0x808007F0: jal         0x8001B668
    // 0x808007F4: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    func_8001B668(rdram, ctx);
        goto after_9;
    // 0x808007F4: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    after_9:
    // 0x808007F8: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x808007FC: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80800800: sh          $v0, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r2;
    // 0x80800804: jal         0x8001B798
    // 0x80800808: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_8001B798(rdram, ctx);
        goto after_10;
    // 0x80800808: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_10:
    // 0x8080080C: lw          $v1, 0xEC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XEC);
    // 0x80800810: sw          $v0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r2;
    // 0x80800814: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800818: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8080081C: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80800820: sll         $a1, $t6, 2
    ctx->r5 = S32(ctx->r14 << 2);
    // 0x80800824: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    // 0x80800828: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8080082C: jal         0x8001B668
    // 0x80800830: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    func_8001B668(rdram, ctx);
        goto after_11;
    // 0x80800830: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    after_11:
    // 0x80800834: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80800838: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8080083C: sh          $v0, 0xC8($sp)
    MEM_H(0XC8, ctx->r29) = ctx->r2;
    // 0x80800840: jal         0x8001B798
    // 0x80800844: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_8001B798(rdram, ctx);
        goto after_12;
    // 0x80800844: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_12:
    // 0x80800848: sll         $s3, $s0, 2
    ctx->r19 = S32(ctx->r16 << 2);
    // 0x8080084C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800850: lw          $t9, 0xEC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XEC);
    // 0x80800854: sw          $v0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r2;
    // 0x80800858: addu        $s3, $s3, $s0
    ctx->r19 = ADD32(ctx->r19, ctx->r16);
    // 0x8080085C: sll         $s3, $s3, 2
    ctx->r19 = S32(ctx->r19 << 2);
    // 0x80800860: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80800864: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80800868: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x8080086C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800870: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800874: sb          $t9, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r25;
    // 0x80800878: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8080087C: jal         0x8001B668
    // 0x80800880: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    func_8001B668(rdram, ctx);
        goto after_13;
    // 0x80800880: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    after_13:
    // 0x80800884: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80800888: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8080088C: sh          $v0, 0xC6($sp)
    MEM_H(0XC6, ctx->r29) = ctx->r2;
    // 0x80800890: jal         0x8001B798
    // 0x80800894: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_8001B798(rdram, ctx);
        goto after_14;
    // 0x80800894: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_14:
    // 0x80800898: sw          $v0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r2;
    // 0x8080089C: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x808008A0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808008A4: addiu       $s1, $v0, 0x4
    ctx->r17 = ADD32(ctx->r2, 0X4);
    // 0x808008A8: lw          $a0, 0x140($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X140);
    // 0x808008AC: beq         $s3, $at, L_80800908
    if (ctx->r19 == ctx->r1) {
        // 0x808008B0: or          $s2, $s0, $zero
        ctx->r18 = ctx->r16 | 0;
            goto L_80800908;
    }
    // 0x808008B0: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
L_808008B4:
    // 0x808008B4: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    // 0x808008B8: addu        $s0, $t5, $fp
    ctx->r16 = ADD32(ctx->r13, ctx->r30);
    // 0x808008BC: lhu         $t4, 0x8($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X8);
    // 0x808008C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008C4: sll         $t7, $t4, 18
    ctx->r15 = S32(ctx->r12 << 18);
    // 0x808008C8: srl         $t6, $t7, 31
    ctx->r14 = S32(U32(ctx->r15) >> 31);
    // 0x808008CC: bne         $t6, $at, L_80800900
    if (ctx->r14 != ctx->r1) {
        // 0x808008D0: nop
    
            goto L_80800900;
    }
    // 0x808008D0: nop

    // 0x808008D4: jal         0x80088300
    // 0x808008D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gccubesearch_entrypoint_17(rdram, ctx);
        goto after_15;
    // 0x808008D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x808008DC: lw          $t8, 0x148($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X148);
    // 0x808008E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808008E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808008E8: lw          $t9, 0x188($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X188);
    // 0x808008EC: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x808008F0: jal         0x8001BBA0
    // 0x808008F4: sb          $t9, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r25;
    rare_memcpy(rdram, ctx);
        goto after_16;
    // 0x808008F4: sb          $t9, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r25;
    after_16:
    // 0x808008F8: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x808008FC: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80800900:
    // 0x80800900: bne         $s2, $zero, L_808008B4
    if (ctx->r18 != 0) {
        // 0x80800904: lh          $a0, 0x0($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X0);
            goto L_808008B4;
    }
    // 0x80800904: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_80800908:
    // 0x80800908: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
    // 0x8080090C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80800910: addiu       $s6, $v0, 0x4
    ctx->r22 = ADD32(ctx->r2, 0X4);
    // 0x80800914: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80800918: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8080091C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80800920: addu        $s3, $t5, $v0
    ctx->r19 = ADD32(ctx->r13, ctx->r2);
    // 0x80800924: addiu       $s3, $s3, -0x10
    ctx->r19 = ADD32(ctx->r19, -0X10);
    // 0x80800928: sltu        $at, $s6, $s3
    ctx->r1 = ctx->r22 < ctx->r19 ? 1 : 0;
L_8080092C:
    // 0x8080092C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800930: beq         $at, $zero, L_80800998
    if (ctx->r1 == 0) {
        // 0x80800934: or          $s0, $s6, $zero
        ctx->r16 = ctx->r22 | 0;
            goto L_80800998;
    }
    // 0x80800934: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
    // 0x80800938: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
L_8080093C:
    // 0x8080093C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800940: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800944: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800948: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080094C: nop

    // 0x80800950: bc1fl       L_8080098C
    if (!c1cs) {
        // 0x80800954: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_8080098C;
    }
    goto skip_18;
    // 0x80800954: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    skip_18:
    // 0x80800958: jal         0x8001BBA0
    // 0x8080095C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    rare_memcpy(rdram, ctx);
        goto after_17;
    // 0x8080095C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_17:
    // 0x80800960: addiu       $s1, $s0, 0x14
    ctx->r17 = ADD32(ctx->r16, 0X14);
    // 0x80800964: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080096C: jal         0x8001BBA0
    // 0x80800970: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    rare_memcpy(rdram, ctx);
        goto after_18;
    // 0x80800970: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_18:
    // 0x80800974: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800978: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8080097C: jal         0x8001BBA0
    // 0x80800980: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    rare_memcpy(rdram, ctx);
        goto after_19;
    // 0x80800980: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_19:
    // 0x80800984: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800988: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_8080098C:
    // 0x8080098C: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x80800990: bnel        $at, $zero, L_8080093C
    if (ctx->r1 != 0) {
        // 0x80800994: lwc1        $f4, 0x14($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
            goto L_8080093C;
    }
    goto skip_19;
    // 0x80800994: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    skip_19:
L_80800998:
    // 0x80800998: bnel        $s2, $zero, L_8080092C
    if (ctx->r18 != 0) {
        // 0x8080099C: sltu        $at, $s6, $s3
        ctx->r1 = ctx->r22 < ctx->r19 ? 1 : 0;
            goto L_8080092C;
    }
    goto skip_20;
    // 0x8080099C: sltu        $at, $s6, $s3
    ctx->r1 = ctx->r22 < ctx->r19 ? 1 : 0;
    skip_20:
    // 0x808009A0: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x808009A4: lh          $t7, 0xA($t4)
    ctx->r15 = MEM_H(ctx->r12, 0XA);
    // 0x808009A8: sh          $t7, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r15;
    // 0x808009AC: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x808009B0: lbu         $t8, 0x1A8($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X1A8);
    // 0x808009B4: sb          $t8, 0x4($s7)
    MEM_B(0X4, ctx->r23) = ctx->r24;
    // 0x808009B8: lh          $t9, 0xCA($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XCA);
    // 0x808009BC: sh          $t9, 0x10($s7)
    MEM_H(0X10, ctx->r23) = ctx->r25;
    // 0x808009C0: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x808009C4: lw          $a3, 0xC0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC0);
    // 0x808009C8: lw          $t0, 0xD0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD0);
    // 0x808009CC: beq         $t3, $zero, L_80800A60
    if (ctx->r11 == 0) {
        // 0x808009D0: lw          $a0, 0xEC($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XEC);
            goto L_80800A60;
    }
    // 0x808009D0: lw          $a0, 0xEC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XEC);
    // 0x808009D4: lw          $a2, 0xDC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XDC);
    // 0x808009D8: lw          $a1, 0xCC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XCC);
L_808009DC:
    // 0x808009DC: sll         $t5, $s4, 4
    ctx->r13 = S32(ctx->r20 << 4);
    // 0x808009E0: addu        $v1, $t5, $fp
    ctx->r3 = ADD32(ctx->r13, ctx->r30);
    // 0x808009E4: lhu         $t4, 0x8($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X8);
    // 0x808009E8: sll         $t6, $t4, 18
    ctx->r14 = S32(ctx->r12 << 18);
    // 0x808009EC: bltz        $t6, L_80800A50
    if (SIGNED(ctx->r14) < 0) {
        // 0x808009F0: nop
    
            goto L_80800A50;
    }
    // 0x808009F0: nop

    // 0x808009F4: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x808009F8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x808009FC: addu        $v0, $a3, $t8
    ctx->r2 = ADD32(ctx->r7, ctx->r24);
    // 0x80800A00: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80800A04: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80800A08: addu        $t6, $t0, $t7
    ctx->r14 = ADD32(ctx->r8, ctx->r15);
    // 0x80800A0C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800A10: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x80800A14: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80800A18: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800A1C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80800A20: lh          $t3, 0x4($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X4);
    // 0x80800A24: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80800A28: nop

    // 0x80800A2C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800A30: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x80800A34: lh          $t5, 0x6($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X6);
    // 0x80800A38: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80800A3C: nop

    // 0x80800A40: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800A44: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80800A48: lh          $t4, 0xA($v1)
    ctx->r12 = MEM_H(ctx->r3, 0XA);
    // 0x80800A4C: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
L_80800A50:
    // 0x80800A50: bne         $a0, $zero, L_808009DC
    if (ctx->r4 != 0) {
        // 0x80800A54: lh          $s4, 0x0($v1)
        ctx->r20 = MEM_H(ctx->r3, 0X0);
            goto L_808009DC;
    }
    // 0x80800A54: lh          $s4, 0x0($v1)
    ctx->r20 = MEM_H(ctx->r3, 0X0);
    // 0x80800A58: sw          $a2, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r6;
    // 0x80800A5C: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
L_80800A60:
    // 0x80800A60: lh          $a0, 0xC8($sp)
    ctx->r4 = MEM_H(ctx->r29, 0XC8);
    // 0x80800A64: jal         0x800D7488
    // 0x80800A68: lh          $a1, 0xC6($sp)
    ctx->r5 = MEM_H(ctx->r29, 0XC6);
    func_800D7488(rdram, ctx);
        goto after_20;
    // 0x80800A68: lh          $a1, 0xC6($sp)
    ctx->r5 = MEM_H(ctx->r29, 0XC6);
    after_20:
    // 0x80800A6C: lw          $a2, 0x144($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X144);
    // 0x80800A70: lw          $a0, 0x140($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X140);
L_80800A74:
    // 0x80800A74: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80800A78:
    // 0x80800A78: bnel        $a0, $a2, L_8080066C
    if (ctx->r4 != ctx->r6) {
        // 0x80800A7C: sll         $t9, $a0, 4
        ctx->r25 = S32(ctx->r4 << 4);
            goto L_8080066C;
    }
    goto skip_21;
    // 0x80800A7C: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
    skip_21:
L_80800A80:
    // 0x80800A80: jal         0x8001B084
    // 0x80800A84: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    heap_free(rdram, ctx);
        goto after_21;
    // 0x80800A84: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_21:
L_80800A88:
    // 0x80800A88: lw          $t8, 0x148($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X148);
    // 0x80800A8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800A90: sw          $zero, 0x198($t8)
    MEM_W(0X198, ctx->r24) = 0;
    // 0x80800A94: sw          $zero, 0x19C($t8)
    MEM_W(0X19C, ctx->r24) = 0;
    // 0x80800A98: sw          $zero, 0x1A0($t8)
    MEM_W(0X1A0, ctx->r24) = 0;
    // 0x80800A9C: swc1        $f0, 0x190($t8)
    MEM_W(0X190, ctx->r24) = ctx->f0.u32l;
    // 0x80800AA0: jal         0x800D87B0
    // 0x80800AA4: swc1        $f0, 0x194($t8)
    MEM_W(0X194, ctx->r24) = ctx->f0.u32l;
    func_800D87B0(rdram, ctx);
        goto after_22;
    // 0x80800AA4: swc1        $f0, 0x194($t8)
    MEM_W(0X194, ctx->r24) = ctx->f0.u32l;
    after_22:
    // 0x80800AA8: lw          $t9, 0x148($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X148);
    // 0x80800AAC: lw          $t3, 0x19C($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X19C);
    // 0x80800AB0: beq         $t3, $zero, L_80800B8C
    if (ctx->r11 == 0) {
        // 0x80800AB4: nop
    
            goto L_80800B8C;
    }
    // 0x80800AB4: nop

    // 0x80800AB8: jal         0x800D674C
    // 0x80800ABC: lw          $a0, 0x198($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X198);
    func_800D674C(rdram, ctx);
        goto after_23;
    // 0x80800ABC: lw          $a0, 0x198($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X198);
    after_23:
    // 0x80800AC0: lw          $t5, 0x148($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X148);
    // 0x80800AC4: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2714, 0XFC0) << 16);
    // 0x80800AC8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800ACC: lw          $t7, 0x188($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X188);
    // 0x80800AD0: addiu       $s0, $s0, 0xFC0
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2714, 0XFC0));
    // 0x80800AD4: blez        $t7, L_80800B8C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80800AD8: nop
    
            goto L_80800B8C;
    }
    // 0x80800AD8: nop

    // 0x80800ADC: sw          $zero, 0x140($sp)
    MEM_W(0X140, ctx->r29) = 0;
L_80800AE0:
    // 0x80800AE0: jal         0x800D7570
    // 0x80800AE4: lw          $a0, 0x140($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X140);
    func_800D7570(rdram, ctx);
        goto after_24;
    // 0x80800AE4: lw          $a0, 0x140($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X140);
    after_24:
    // 0x80800AE8: beql        $v0, $zero, L_80800B70
    if (ctx->r2 == 0) {
        // 0x80800AEC: lw          $t7, 0x140($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X140);
            goto L_80800B70;
    }
    goto skip_22;
    // 0x80800AEC: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    skip_22:
    // 0x80800AF0: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80800AF4: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x80800AF8: beql        $t6, $zero, L_80800B70
    if (ctx->r14 == 0) {
        // 0x80800AFC: lw          $t7, 0x140($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X140);
            goto L_80800B70;
    }
    goto skip_23;
    // 0x80800AFC: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    skip_23:
    // 0x80800B00: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x80800B04: andi        $t3, $t8, 0x1
    ctx->r11 = ctx->r24 & 0X1;
    // 0x80800B08: beql        $t3, $zero, L_80800B70
    if (ctx->r11 == 0) {
        // 0x80800B0C: lw          $t7, 0x140($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X140);
            goto L_80800B70;
    }
    goto skip_24;
    // 0x80800B0C: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    skip_24:
    // 0x80800B10: lbu         $a1, 0xC($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0XC);
    // 0x80800B14: lw          $t9, 0x148($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X148);
    // 0x80800B18: beql        $a1, $zero, L_80800B70
    if (ctx->r5 == 0) {
        // 0x80800B1C: lw          $t7, 0x140($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X140);
            goto L_80800B70;
    }
    goto skip_25;
    // 0x80800B1C: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    skip_25:
    // 0x80800B20: lw          $t5, 0x19C($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X19C);
    // 0x80800B24: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x80800B28: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80800B2C: addu        $t4, $t5, $t7
    ctx->r12 = ADD32(ctx->r13, ctx->r15);
    // 0x80800B30: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80800B34: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80800B38: addu        $a0, $t6, $s1
    ctx->r4 = ADD32(ctx->r14, ctx->r17);
    // 0x80800B3C: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80800B40: bnel        $t8, $t3, L_80800B70
    if (ctx->r24 != ctx->r11) {
        // 0x80800B44: lw          $t7, 0x140($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X140);
            goto L_80800B70;
    }
    goto skip_26;
    // 0x80800B44: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    skip_26:
    // 0x80800B48: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80800B4C: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80800B50: bnel        $t9, $t5, L_80800B70
    if (ctx->r25 != ctx->r13) {
        // 0x80800B54: lw          $t7, 0x140($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X140);
            goto L_80800B70;
    }
    goto skip_27;
    // 0x80800B54: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    skip_27:
    // 0x80800B58: jal         0x800D7520
    // 0x80800B5C: lw          $a0, 0x140($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X140);
    func_800D7520(rdram, ctx);
        goto after_25;
    // 0x80800B5C: lw          $a0, 0x140($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X140);
    after_25:
    // 0x80800B60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B64: jal         0x800C84A4
    // 0x80800B68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C84A4(rdram, ctx);
        goto after_26;
    // 0x80800B68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80800B6C: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
L_80800B70:
    // 0x80800B70: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x80800B74: addiu       $t4, $t7, 0x1
    ctx->r12 = ADD32(ctx->r15, 0X1);
    // 0x80800B78: sw          $t4, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r12;
    // 0x80800B7C: lw          $t8, 0x188($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X188);
    // 0x80800B80: slt         $at, $t4, $t8
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80800B84: bne         $at, $zero, L_80800AE0
    if (ctx->r1 != 0) {
        // 0x80800B88: nop
    
            goto L_80800AE0;
    }
    // 0x80800B88: nop

L_80800B8C:
    // 0x80800B8C: jal         0x8001ACCC
    // 0x80800B90: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    heap_alloc(rdram, ctx);
        goto after_27;
    // 0x80800B90: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_27:
    // 0x80800B94: lw          $t3, 0x148($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X148);
    // 0x80800B98: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800B9C: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80800BA0: sw          $v0, 0x1A4($t3)
    MEM_W(0X1A4, ctx->r11) = ctx->r2;
    // 0x80800BA4: lb          $t9, 0x0($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X0);
    // 0x80800BA8: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80800BAC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80800BB0: andi        $t5, $t9, 0xFF7F
    ctx->r13 = ctx->r25 & 0XFF7F;
    // 0x80800BB4: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x80800BB8: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    // 0x80800BBC: lw          $v0, 0x1A4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X1A4);
    // 0x80800BC0: lb          $t6, 0xC($v0)
    ctx->r14 = MEM_B(ctx->r2, 0XC);
    // 0x80800BC4: andi        $t4, $t6, 0xFF7F
    ctx->r12 = ctx->r14 & 0XFF7F;
    // 0x80800BC8: sb          $t4, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r12;
    // 0x80800BCC: lw          $t8, 0x148($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X148);
    // 0x80800BD0: lw          $v0, 0x1A4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X1A4);
    // 0x80800BD4: lb          $t3, 0x18($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X18);
    // 0x80800BD8: andi        $t9, $t3, 0xFF7F
    ctx->r25 = ctx->r11 & 0XFF7F;
    // 0x80800BDC: sb          $t9, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r25;
    // 0x80800BE0: lw          $t5, 0x148($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X148);
    // 0x80800BE4: lw          $t7, 0x1A4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X1A4);
    // 0x80800BE8: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x80800BEC: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x80800BF0: andi        $t4, $t6, 0xFF7F
    ctx->r12 = ctx->r14 & 0XFF7F;
    // 0x80800BF4: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
    // 0x80800BF8: lw          $t8, 0x148($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X148);
    // 0x80800BFC: lw          $t3, 0x1A4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X1A4);
    // 0x80800C00: addu        $v0, $t3, $v1
    ctx->r2 = ADD32(ctx->r11, ctx->r3);
    // 0x80800C04: lb          $t9, 0xC($v0)
    ctx->r25 = MEM_B(ctx->r2, 0XC);
    // 0x80800C08: andi        $t5, $t9, 0xFF7F
    ctx->r13 = ctx->r25 & 0XFF7F;
    // 0x80800C0C: sb          $t5, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r13;
    // 0x80800C10: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    // 0x80800C14: lw          $t6, 0x1A4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X1A4);
    // 0x80800C18: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x80800C1C: lb          $t4, 0x18($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X18);
    // 0x80800C20: andi        $t8, $t4, 0xFF7F
    ctx->r24 = ctx->r12 & 0XFF7F;
    // 0x80800C24: sb          $t8, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r24;
    // 0x80800C28: lw          $t3, 0x148($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X148);
    // 0x80800C2C: lw          $t9, 0x1A4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X1A4);
    // 0x80800C30: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x80800C34: lb          $t5, 0x24($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X24);
    // 0x80800C38: andi        $t7, $t5, 0xFF7F
    ctx->r15 = ctx->r13 & 0XFF7F;
    // 0x80800C3C: sb          $t7, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r15;
    // 0x80800C40: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80800C44: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80800C48: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80800C4C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80800C50: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80800C54: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80800C58: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80800C5C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80800C60: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C64: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800C68: jr          $ra
    // 0x80800C6C: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // 0x80800C6C: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
RECOMP_FUNC void func_80802108_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802108: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080210C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80802110: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80802114: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80802118: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080211C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80802120: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802124: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80802128: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080212C: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
L_80802130:
    // 0x80802130: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    // 0x80802134: beql        $a0, $zero, L_80802148
    if (ctx->r4 == 0) {
        // 0x80802138: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80802148;
    }
    goto skip_0;
    // 0x80802138: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x8080213C: jal         0x800C8FE0
    // 0x80802140: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800C8FE0(rdram, ctx);
        goto after_0;
    // 0x80802140: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x80802144: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80802148:
    // 0x80802148: bne         $s0, $s3, L_80802130
    if (ctx->r16 != ctx->r19) {
        // 0x8080214C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80802130;
    }
    // 0x8080214C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80802150: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802154: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80802158: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080215C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80802160: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80802164: jr          $ra
    // 0x80802168: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80802168: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800A7108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7108: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A710C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7110: jal         0x80106790
    // 0x800A7114: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x800A7114: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A7118: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A711C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x800A7120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A7128: jr          $ra
    // 0x800A712C: nop

    return;
    // 0x800A712C: nop

;}
RECOMP_FUNC void func_800BDC44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDC44: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BDC48: jr          $ra
    // 0x800BDC4C: addiu       $v0, $v0, -0x7BBC
    ctx->r2 = ADD32(ctx->r2, -0X7BBC);
    return;
    // 0x800BDC4C: addiu       $v0, $v0, -0x7BBC
    ctx->r2 = ADD32(ctx->r2, -0X7BBC);
;}
RECOMP_FUNC void func_80800210_chspotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800210: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800214: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800218: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080021C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800220: jal         0x80100094
    // 0x80800224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800228: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080022C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800230: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800234: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800238: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x8080023C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800240: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800244: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80800248: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080024C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800250: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800254: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800258: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080025C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800260: jal         0x80089F20
    // 0x80800264: nop

    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800264: nop

    after_1:
    // 0x80800268: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x8080026C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800270: srl         $t7, $v1, 10
    ctx->r15 = S32(U32(ctx->r3) >> 10);
    // 0x80800274: beq         $t7, $at, L_808002A0
    if (ctx->r15 == ctx->r1) {
        // 0x80800278: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808002A0;
    }
    // 0x80800278: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080027C: beq         $t7, $at, L_80800300
    if (ctx->r15 == ctx->r1) {
        // 0x80800280: lw          $v0, 0x34($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X34);
            goto L_80800300;
    }
    // 0x80800280: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80800284: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800288: beq         $t7, $at, L_808003C4
    if (ctx->r15 == ctx->r1) {
        // 0x8080028C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808003C4;
    }
    // 0x8080028C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800290: beq         $t7, $at, L_808003E4
    if (ctx->r15 == ctx->r1) {
        // 0x80800294: nop
    
            goto L_808003E4;
    }
    // 0x80800294: nop

    // 0x80800298: b           L_8080046C
    // 0x8080029C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080046C;
    // 0x8080029C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002A0:
    // 0x808002A0: lhu         $t8, 0x76($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X76);
    // 0x808002A4: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x808002A8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808002AC: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x808002B0: bne         $t9, $at, L_808002C0
    if (ctx->r25 != ctx->r1) {
        // 0x808002B4: nop
    
            goto L_808002C0;
    }
    // 0x808002B4: nop

    // 0x808002B8: b           L_808002C0
    // 0x808002BC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_808002C0;
    // 0x808002BC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_808002C0:
    // 0x808002C0: jal         0x800DA298
    // 0x808002C4: nop

    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808002C4: nop

    after_2:
    // 0x808002C8: beq         $v0, $zero, L_80800468
    if (ctx->r2 == 0) {
        // 0x808002CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800468;
    }
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D0: jal         0x80101FDC
    // 0x808002D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x808002D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808002D8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x808002DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808002E0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x808002E4: sw          $t0, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r8;
    // 0x808002E8: beql        $a0, $zero, L_8080046C
    if (ctx->r4 == 0) {
        // 0x808002EC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080046C;
    }
    goto skip_0;
    // 0x808002EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808002F0: jal         0x800C8FE0
    // 0x808002F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8FE0(rdram, ctx);
        goto after_4;
    // 0x808002F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808002F8: b           L_8080046C
    // 0x808002FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080046C;
    // 0x808002FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800300:
    // 0x80800300: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800304: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800308: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1004, 0X974) << 16);
    // 0x8080030C: lwc1        $f2, 0x20($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80800310: lwc1        $f16, 0x974($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1004, 0X974));
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080031C: add.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x80800320: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1004, 0X978) << 16);
    // 0x80800324: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800328: nop

    // 0x8080032C: bc1fl       L_8080034C
    if (!c1cs) {
        // 0x80800330: swc1        $f2, 0x20($v0)
        MEM_W(0X20, ctx->r2) = ctx->f2.u32l;
            goto L_8080034C;
    }
    goto skip_1;
    // 0x80800330: swc1        $f2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f2.u32l;
    skip_1:
    // 0x80800334: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80800338: jal         0x80101FDC
    // 0x8080033C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x8080033C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80800340: b           L_808003B0
    // 0x80800344: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
        goto L_808003B0;
    // 0x80800344: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800348: swc1        $f2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f2.u32l;
L_8080034C:
    // 0x8080034C: lwc1        $f18, 0x978($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1004, 0X978));
    // 0x80800350: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1004, 0X97C) << 16);
    // 0x80800354: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80800358: nop

    // 0x8080035C: bc1fl       L_808003A8
    if (!c1cs) {
        // 0x80800360: lw          $v0, 0x34($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X34);
            goto L_808003A8;
    }
    goto skip_2;
    // 0x80800360: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80800364: lwc1        $f12, 0x97C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1004, 0X97C));
    // 0x80800368: jal         0x800DC298
    // 0x8080036C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_800DC298(rdram, ctx);
        goto after_6;
    // 0x8080036C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x80800370: beq         $v0, $zero, L_808003A4
    if (ctx->r2 == 0) {
        // 0x80800374: lwc1        $f2, 0x2C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_808003A4;
    }
    // 0x80800374: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800378: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8080037C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800380: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800384: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800388: jal         0x800DC178
    // 0x8080038C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x8080038C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_7:
    // 0x80800390: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800394: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80800398: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8080039C: b           L_808003B0
    // 0x808003A0: sw          $zero, 0x24($t2)
    MEM_W(0X24, ctx->r10) = 0;
        goto L_808003B0;
    // 0x808003A0: sw          $zero, 0x24($t2)
    MEM_W(0X24, ctx->r10) = 0;
L_808003A4:
    // 0x808003A4: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
L_808003A8:
    // 0x808003A8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808003AC: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
L_808003B0:
    // 0x808003B0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808003B4: jal         0x808007F4
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007F4_chspotlight(rdram, ctx);
        goto after_8;
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808003BC: b           L_8080046C
    // 0x808003C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080046C;
    // 0x808003C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003C4:
    // 0x808003C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003D4: jal         0x808007F4
    // 0x808003D8: nop

    func_808007F4_chspotlight(rdram, ctx);
        goto after_9;
    // 0x808003D8: nop

    after_9:
    // 0x808003DC: b           L_8080046C
    // 0x808003E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080046C;
    // 0x808003E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003E4:
    // 0x808003E4: jal         0x800D8FF8
    // 0x808003E8: nop

    func_800D8FF8(rdram, ctx);
        goto after_10;
    // 0x808003E8: nop

    after_10:
    // 0x808003EC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808003F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808003FC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800400: jal         0x80102B2C
    // 0x80800404: nop

    func_80102B2C(rdram, ctx);
        goto after_11;
    // 0x80800404: nop

    after_11:
    // 0x80800408: jal         0x800D8FF8
    // 0x8080040C: nop

    func_800D8FF8(rdram, ctx);
        goto after_12;
    // 0x8080040C: nop

    after_12:
    // 0x80800410: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800414: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080041C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800420: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800424: jal         0x80102B6C
    // 0x80800428: nop

    func_80102B6C(rdram, ctx);
        goto after_13;
    // 0x80800428: nop

    after_13:
    // 0x8080042C: jal         0x80102CCC
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102CCC(rdram, ctx);
        goto after_14;
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800434: beql        $v0, $zero, L_8080046C
    if (ctx->r2 == 0) {
        // 0x80800438: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080046C;
    }
    goto skip_3;
    // 0x80800438: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8080043C: jal         0x80102CA4
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102CA4(rdram, ctx);
        goto after_15;
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800444: beq         $v0, $zero, L_80800468
    if (ctx->r2 == 0) {
        // 0x80800448: lw          $t4, 0x34($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X34);
            goto L_80800468;
    }
    // 0x80800448: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8080044C: lwc1        $f16, 0x1C($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x80800450: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800458: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080045C: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x80800460: jal         0x80101FDC
    // 0x80800464: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    func_80101FDC(rdram, ctx);
        goto after_16;
    // 0x80800464: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    after_16:
L_80800468:
    // 0x80800468: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080046C:
    // 0x8080046C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800470: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800474: jr          $ra
    // 0x80800478: nop

    return;
    // 0x80800478: nop

;}
RECOMP_FUNC void func_8008E23C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E23C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E240: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E244: jal         0x800F8B88
    // 0x8008E248: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F8B88(rdram, ctx);
        goto after_0;
    // 0x8008E248: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008E24C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E250: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x8008E254: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8008E258: jr          $ra
    // 0x8008E25C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008E25C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800FED90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FED90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FED94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FED98: jal         0x800FED0C
    // 0x800FED9C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800FED0C(rdram, ctx);
        goto after_0;
    // 0x800FED9C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x800FEDA0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800FEDA4: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
    // 0x800FEDA8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800FEDAC:
    // 0x800FEDAC: bnel        $v0, $v1, L_800FEDAC
    if (ctx->r2 != ctx->r3) {
        // 0x800FEDB0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800FEDAC;
    }
    goto skip_0;
    // 0x800FEDB0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_0:
    // 0x800FEDB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FEDB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FEDBC: jr          $ra
    // 0x800FEDC0: nop

    return;
    // 0x800FEDC0: nop

;}
RECOMP_FUNC void func_808008D8_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808008DC: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x808008E0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808008E4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808008E8: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x808008EC: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808008F0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x808008F4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808008F8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808008FC: beq         $a2, $zero, L_80800C38
    if (ctx->r6 == 0) {
        // 0x80800900: sdc1        $f20, 0x10($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
            goto L_80800C38;
    }
    // 0x80800900: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800904: beq         $a1, $zero, L_80800C38
    if (ctx->r5 == 0) {
        // 0x80800908: sll         $t6, $a1, 3
        ctx->r14 = S32(ctx->r5 << 3);
            goto L_80800C38;
    }
    // 0x80800908: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x8080090C: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80800910: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800914: addu        $s5, $t6, $a2
    ctx->r21 = ADD32(ctx->r14, ctx->r6);
    // 0x80800918: sltu        $at, $a2, $s5
    ctx->r1 = ctx->r6 < ctx->r21 ? 1 : 0;
    // 0x8080091C: beq         $at, $zero, L_80800C38
    if (ctx->r1 == 0) {
        // 0x80800920: or          $s2, $a2, $zero
        ctx->r18 = ctx->r6 | 0;
            goto L_80800C38;
    }
    // 0x80800920: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80800924: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800928: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8080092C: nop

L_80800930:
    // 0x80800930: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2606, 0X15B0) << 16);
    // 0x80800934: addiu       $t8, $t8, 0x15B0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2606, 0X15B0));
    // 0x80800938: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8080093C: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x80800940: addiu       $t7, $sp, 0x60
    ctx->r15 = ADD32(ctx->r29, 0X60);
    // 0x80800944: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2606, 0X15B8) << 16);
    // 0x80800948: addiu       $t2, $t2, 0x15B8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2606, 0X15B8));
    // 0x8080094C: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x80800950: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x80800954: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x80800958: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8080095C: addiu       $t1, $sp, 0x58
    ctx->r9 = ADD32(ctx->r29, 0X58);
    // 0x80800960: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2606, 0X15C0) << 16);
    // 0x80800964: addiu       $t6, $t6, 0x15C0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2606, 0X15C0));
    // 0x80800968: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x8080096C: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80800970: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80800974: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80800978: addiu       $t5, $sp, 0x50
    ctx->r13 = ADD32(ctx->r29, 0X50);
    // 0x8080097C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2606, 0X15C8) << 16);
    // 0x80800980: addiu       $t0, $t0, 0x15C8
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2606, 0X15C8));
    // 0x80800984: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80800988: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x8080098C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80800990: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80800994: addiu       $t8, $sp, 0x48
    ctx->r24 = ADD32(ctx->r29, 0X48);
    // 0x80800998: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080099C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808009A0: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x808009A4: jal         0x80800688
    // 0x808009A8: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    func_80800688_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x808009A8: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    after_0:
    // 0x808009AC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808009B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808009B4: jal         0x808006A8
    // 0x808009B8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_808006A8_gcboundDll(rdram, ctx);
        goto after_1;
    // 0x808009B8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x808009BC: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x808009C0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808009C4: beq         $at, $zero, L_80800AF0
    if (ctx->r1 == 0) {
        // 0x808009C8: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80800AF0;
    }
    // 0x808009C8: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_808009CC:
    // 0x808009CC: lh          $t2, 0xC($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XC);
    // 0x808009D0: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808009D4: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x808009D8: nop

    // 0x808009DC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808009E0: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x808009E4: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x808009E8: lh          $t4, 0xC($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XC);
    // 0x808009EC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808009F0: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x808009F4: nop

    // 0x808009F8: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808009FC: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80800A00: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x80800A04: lh          $t9, 0xC($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XC);
    // 0x80800A08: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800A0C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80800A10: nop

    // 0x80800A14: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800A18: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80800A1C: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800A20: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x80800A24: lh          $t5, 0xC($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XC);
    // 0x80800A28: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800A2C: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800A30: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80800A34: nop

    // 0x80800A38: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800A3C: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800A40: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80800A44: beq         $s0, $s1, L_80800A5C
    if (ctx->r16 == ctx->r17) {
        // 0x80800A48: swc1        $f8, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
            goto L_80800A5C;
    }
    // 0x80800A48: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80800A4C: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80800A50: nop

    // 0x80800A54: bc1f        L_80800A60
    if (!c1cs) {
        // 0x80800A58: nop
    
            goto L_80800A60;
    }
    // 0x80800A58: nop

L_80800A5C:
    // 0x80800A5C: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
L_80800A60:
    // 0x80800A60: beq         $s0, $s1, L_80800A7C
    if (ctx->r16 == ctx->r17) {
        // 0x80800A64: lwc1        $f6, 0x54($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
            goto L_80800A7C;
    }
    // 0x80800A64: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800A68: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80800A6C: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80800A70: nop

    // 0x80800A74: bc1f        L_80800A84
    if (!c1cs) {
        // 0x80800A78: nop
    
            goto L_80800A84;
    }
    // 0x80800A78: nop

L_80800A7C:
    // 0x80800A7C: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800A80: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
L_80800A84:
    // 0x80800A84: beq         $s0, $s1, L_80800AA0
    if (ctx->r16 == ctx->r17) {
        // 0x80800A88: lwc1        $f18, 0x58($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
            goto L_80800AA0;
    }
    // 0x80800A88: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800A8C: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800A90: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80800A94: nop

    // 0x80800A98: bc1f        L_80800AA8
    if (!c1cs) {
        // 0x80800A9C: nop
    
            goto L_80800AA8;
    }
    // 0x80800A9C: nop

L_80800AA0:
    // 0x80800AA0: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800AA4: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
L_80800AA8:
    // 0x80800AA8: beq         $s0, $s1, L_80800AC4
    if (ctx->r16 == ctx->r17) {
        // 0x80800AAC: lwc1        $f6, 0x5C($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
            goto L_80800AC4;
    }
    // 0x80800AAC: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800AB0: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800AB4: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80800AB8: nop

    // 0x80800ABC: bc1fl       L_80800AD0
    if (!c1cs) {
        // 0x80800AC0: lh          $t6, 0xC($s0)
        ctx->r14 = MEM_H(ctx->r16, 0XC);
            goto L_80800AD0;
    }
    goto skip_0;
    // 0x80800AC0: lh          $t6, 0xC($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XC);
    skip_0:
L_80800AC4:
    // 0x80800AC4: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800AC8: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x80800ACC: lh          $t6, 0xC($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XC);
L_80800AD0:
    // 0x80800AD0: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80800AD4: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x80800AD8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80800ADC: nop

    // 0x80800AE0: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800AE4: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80800AE8: bne         $at, $zero, L_808009CC
    if (ctx->r1 != 0) {
        // 0x80800AEC: swc1        $f16, -0x8($s0)
        MEM_W(-0X8, ctx->r16) = ctx->f16.u32l;
            goto L_808009CC;
    }
    // 0x80800AEC: swc1        $f16, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->f16.u32l;
L_80800AF0:
    // 0x80800AF0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800AF4: jal         0x80800700
    // 0x80800AF8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80800700_gcboundDll(rdram, ctx);
        goto after_2;
    // 0x80800AF8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80800AFC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800B00: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800B04: jal         0x808006E0
    // 0x80800B08: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_808006E0_gcboundDll(rdram, ctx);
        goto after_3;
    // 0x80800B08: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80800B0C: sltu        $at, $v0, $s3
    ctx->r1 = ctx->r2 < ctx->r19 ? 1 : 0;
    // 0x80800B10: beq         $at, $zero, L_80800B5C
    if (ctx->r1 == 0) {
        // 0x80800B14: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800B5C;
    }
    // 0x80800B14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800B18: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x80800B1C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80800B20: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x80800B24: mtc1        $t7, $f14
    ctx->f14.u32l = ctx->r15;
    // 0x80800B28: beq         $at, $zero, L_80800B54
    if (ctx->r1 == 0) {
        // 0x80800B2C: cvt.s.w     $f18, $f14
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = CVT_S_W(ctx->f14.u32l);
            goto L_80800B54;
    }
    // 0x80800B2C: cvt.s.w     $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = CVT_S_W(ctx->f14.u32l);
L_80800B30:
    // 0x80800B30: mul.s       $f16, $f18, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80800B34: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x80800B38: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80800B3C: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x80800B40: mtc1        $t7, $f14
    ctx->f14.u32l = ctx->r15;
    // 0x80800B44: nop

    // 0x80800B48: cvt.s.w     $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80800B4C: bne         $at, $zero, L_80800B30
    if (ctx->r1 != 0) {
        // 0x80800B50: swc1        $f16, -0x20($s0)
        MEM_W(-0X20, ctx->r16) = ctx->f16.u32l;
            goto L_80800B30;
    }
    // 0x80800B50: swc1        $f16, -0x20($s0)
    MEM_W(-0X20, ctx->r16) = ctx->f16.u32l;
L_80800B54:
    // 0x80800B54: mul.s       $f16, $f18, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80800B58: swc1        $f16, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->f16.u32l;
L_80800B5C:
    // 0x80800B5C: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800B60: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800B64: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800B68: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800B6C: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80800B70: mul.s       $f16, $f18, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80800B74: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800B78: swc1        $f16, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f16.u32l;
    // 0x80800B7C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800B80: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80800B84: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800B88: swc1        $f18, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f18.u32l;
    // 0x80800B8C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800B90: swc1        $f16, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f16.u32l;
    // 0x80800B94: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80800B98: jal         0x808006A8
    // 0x80800B9C: swc1        $f8, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f8.u32l;
    func_808006A8_gcboundDll(rdram, ctx);
        goto after_4;
    // 0x80800B9C: swc1        $f8, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f8.u32l;
    after_4:
    // 0x80800BA0: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80800BA4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800BA8: beq         $at, $zero, L_80800C28
    if (ctx->r1 == 0) {
        // 0x80800BAC: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80800C28;
    }
    // 0x80800BAC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80800BB0: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
L_80800BB4:
    // 0x80800BB4: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80800BB8: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800BBC: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x80800BC0: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80800BC4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800BC8: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800BCC: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80800BD0: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x80800BD4: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800BD8: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80800BDC: nop

    // 0x80800BE0: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80800BE4: jal         0x8002DCA0
    // 0x80800BE8: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x80800BE8: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_5:
    // 0x80800BEC: lh          $t3, 0xC($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XC);
    // 0x80800BF0: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80800BF4: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80800BF8: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80800BFC: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x80800C00: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800C04: add.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80800C08: mul.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80800C0C: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80800C10: nop

    // 0x80800C14: bc1f        L_80800C20
    if (!c1cs) {
        // 0x80800C18: nop
    
            goto L_80800C20;
    }
    // 0x80800C18: nop

    // 0x80800C1C: swc1        $f12, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f12.u32l;
L_80800C20:
    // 0x80800C20: bnel        $at, $zero, L_80800BB4
    if (ctx->r1 != 0) {
        // 0x80800C24: lwc1        $f4, 0x0($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
            goto L_80800BB4;
    }
    goto skip_1;
    // 0x80800C24: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    skip_1:
L_80800C28:
    // 0x80800C28: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    // 0x80800C2C: sltu        $at, $s2, $s5
    ctx->r1 = ctx->r18 < ctx->r21 ? 1 : 0;
    // 0x80800C30: bne         $at, $zero, L_80800930
    if (ctx->r1 != 0) {
        // 0x80800C34: nop
    
            goto L_80800930;
    }
    // 0x80800C34: nop

L_80800C38:
    // 0x80800C38: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800C3C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800C40: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C44: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800C48: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800C4C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800C50: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C54: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800C58: jr          $ra
    // 0x80800C5C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80800C5C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80800C08_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800C14: jal         0x80100094
    // 0x80800C18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C1C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800C20: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800C24: addiu       $a0, $zero, 0x357
    ctx->r4 = ADD32(0, 0X357);
    // 0x80800C28: jal         0x80088480
    // 0x80800C2C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800C2C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80800C30: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C34: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x80800C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C40: jr          $ra
    // 0x80800C44: nop

    return;
    // 0x80800C44: nop

;}
RECOMP_FUNC void func_80801E68_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E68: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80801E6C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801E70: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80801E74: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80801E78: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80801E7C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80801E80: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80801E84: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80801E88: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80801E8C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801E90: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801E94: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x80801E98: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x80801E9C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801EA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801EA4: blez        $t7, L_80802018
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80801EA8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80802018;
    }
    // 0x80801EA8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80801EAC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80801EB0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80801EB4: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x80801EB8: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x80801EBC: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_80801EC0:
    // 0x80801EC0: jal         0x80087AF8
    // 0x80801EC4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801EC4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_0:
    // 0x80801EC8: beq         $v0, $zero, L_80801EF0
    if (ctx->r2 == 0) {
        // 0x80801ECC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80801EF0;
    }
    // 0x80801ECC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80801ED0: beql        $v0, $s4, L_80801FD8
    if (ctx->r2 == ctx->r20) {
        // 0x80801ED4: lw          $a0, 0x3C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X3C);
            goto L_80801FD8;
    }
    goto skip_0;
    // 0x80801ED4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    skip_0:
    // 0x80801ED8: beql        $v0, $s5, L_80801FF0
    if (ctx->r2 == ctx->r21) {
        // 0x80801EDC: sb          $v0, 0x94($s2)
        MEM_B(0X94, ctx->r18) = ctx->r2;
            goto L_80801FF0;
    }
    goto skip_1;
    // 0x80801EDC: sb          $v0, 0x94($s2)
    MEM_B(0X94, ctx->r18) = ctx->r2;
    skip_1:
    // 0x80801EE0: beql        $v0, $s6, L_80801FF0
    if (ctx->r2 == ctx->r22) {
        // 0x80801EE4: sb          $v0, 0x94($s2)
        MEM_B(0X94, ctx->r18) = ctx->r2;
            goto L_80801FF0;
    }
    goto skip_2;
    // 0x80801EE4: sb          $v0, 0x94($s2)
    MEM_B(0X94, ctx->r18) = ctx->r2;
    skip_2:
    // 0x80801EE8: b           L_80801FF4
    // 0x80801EEC: lb          $t8, 0x94($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X94);
        goto L_80801FF4;
    // 0x80801EEC: lb          $t8, 0x94($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X94);
L_80801EF0:
    // 0x80801EF0: bne         $s3, $zero, L_80801F6C
    if (ctx->r19 != 0) {
        // 0x80801EF4: nop
    
            goto L_80801F6C;
    }
    // 0x80801EF4: nop

    // 0x80801EF8: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80801EFC: beq         $a0, $zero, L_80801F44
    if (ctx->r4 == 0) {
        // 0x80801F00: nop
    
            goto L_80801F44;
    }
    // 0x80801F00: nop

    // 0x80801F04: jal         0x80087AF8
    // 0x80801F08: nop

    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80801F08: nop

    after_1:
    // 0x80801F0C: beq         $v0, $s4, L_80801F44
    if (ctx->r2 == ctx->r20) {
        // 0x80801F10: nop
    
            goto L_80801F44;
    }
    // 0x80801F10: nop

    // 0x80801F14: jal         0x80087AF8
    // 0x80801F18: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80801F18: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    after_2:
    // 0x80801F1C: beq         $v0, $s5, L_80801F44
    if (ctx->r2 == ctx->r21) {
        // 0x80801F20: nop
    
            goto L_80801F44;
    }
    // 0x80801F20: nop

    // 0x80801F24: jal         0x80087AF8
    // 0x80801F28: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80801F28: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    after_3:
    // 0x80801F2C: beq         $v0, $s6, L_80801F44
    if (ctx->r2 == ctx->r22) {
        // 0x80801F30: nop
    
            goto L_80801F44;
    }
    // 0x80801F30: nop

    // 0x80801F34: jal         0x800D9078
    // 0x80801F38: addiu       $a0, $s1, 0x38
    ctx->r4 = ADD32(ctx->r17, 0X38);
    func_800D9078(rdram, ctx);
        goto after_4;
    // 0x80801F38: addiu       $a0, $s1, 0x38
    ctx->r4 = ADD32(ctx->r17, 0X38);
    after_4:
    // 0x80801F3C: beql        $v0, $zero, L_80801FF4
    if (ctx->r2 == 0) {
        // 0x80801F40: lb          $t8, 0x94($s2)
        ctx->r24 = MEM_B(ctx->r18, 0X94);
            goto L_80801FF4;
    }
    goto skip_3;
    // 0x80801F40: lb          $t8, 0x94($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X94);
    skip_3:
L_80801F44:
    // 0x80801F44: jal         0x80087B28
    // 0x80801F48: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80801F48: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_5:
    // 0x80801F4C: lwc1        $f4, 0x9C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80801F50: c.eq.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl == ctx->f4.fl;
    // 0x80801F54: nop

    // 0x80801F58: bc1fl       L_80801FF4
    if (!c1cs) {
        // 0x80801F5C: lb          $t8, 0x94($s2)
        ctx->r24 = MEM_B(ctx->r18, 0X94);
            goto L_80801FF4;
    }
    goto skip_4;
    // 0x80801F5C: lb          $t8, 0x94($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X94);
    skip_4:
    // 0x80801F60: lwc1        $f6, 0x18($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80801F64: b           L_80801FF0
    // 0x80801F68: swc1        $f6, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f6.u32l;
        goto L_80801FF0;
    // 0x80801F68: swc1        $f6, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f6.u32l;
L_80801F6C:
    // 0x80801F6C: jal         0x80087AF8
    // 0x80801F70: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80801F70: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x80801F74: beq         $v0, $s4, L_80801FAC
    if (ctx->r2 == ctx->r20) {
        // 0x80801F78: nop
    
            goto L_80801FAC;
    }
    // 0x80801F78: nop

    // 0x80801F7C: jal         0x80087AF8
    // 0x80801F80: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x80801F80: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    after_7:
    // 0x80801F84: beq         $v0, $s5, L_80801FAC
    if (ctx->r2 == ctx->r21) {
        // 0x80801F88: nop
    
            goto L_80801FAC;
    }
    // 0x80801F88: nop

    // 0x80801F8C: jal         0x80087AF8
    // 0x80801F90: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x80801F90: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    after_8:
    // 0x80801F94: beq         $v0, $s6, L_80801FAC
    if (ctx->r2 == ctx->r22) {
        // 0x80801F98: nop
    
            goto L_80801FAC;
    }
    // 0x80801F98: nop

    // 0x80801F9C: jal         0x800D9078
    // 0x80801FA0: addiu       $a0, $s0, 0x98
    ctx->r4 = ADD32(ctx->r16, 0X98);
    func_800D9078(rdram, ctx);
        goto after_9;
    // 0x80801FA0: addiu       $a0, $s0, 0x98
    ctx->r4 = ADD32(ctx->r16, 0X98);
    after_9:
    // 0x80801FA4: beql        $v0, $zero, L_80801FF4
    if (ctx->r2 == 0) {
        // 0x80801FA8: lb          $t8, 0x94($s2)
        ctx->r24 = MEM_B(ctx->r18, 0X94);
            goto L_80801FF4;
    }
    goto skip_5;
    // 0x80801FA8: lb          $t8, 0x94($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X94);
    skip_5:
L_80801FAC:
    // 0x80801FAC: jal         0x80087B28
    // 0x80801FB0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_9(rdram, ctx);
        goto after_10;
    // 0x80801FB0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_10:
    // 0x80801FB4: lwc1        $f8, 0x9C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80801FB8: c.eq.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl == ctx->f8.fl;
    // 0x80801FBC: nop

    // 0x80801FC0: bc1fl       L_80801FF4
    if (!c1cs) {
        // 0x80801FC4: lb          $t8, 0x94($s2)
        ctx->r24 = MEM_B(ctx->r18, 0X94);
            goto L_80801FF4;
    }
    goto skip_6;
    // 0x80801FC4: lb          $t8, 0x94($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X94);
    skip_6:
    // 0x80801FC8: lwc1        $f10, 0x18($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80801FCC: b           L_80801FF0
    // 0x80801FD0: swc1        $f10, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f10.u32l;
        goto L_80801FF0;
    // 0x80801FD0: swc1        $f10, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f10.u32l;
    // 0x80801FD4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
L_80801FD8:
    // 0x80801FD8: jal         0x80087B38
    // 0x80801FDC: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    _gczoombox_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x80801FDC: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_11:
    // 0x80801FE0: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80801FE4: b           L_80801FF0
    // 0x80801FE8: sb          $v1, 0x94($s2)
    MEM_B(0X94, ctx->r18) = ctx->r3;
        goto L_80801FF0;
    // 0x80801FE8: sb          $v1, 0x94($s2)
    MEM_B(0X94, ctx->r18) = ctx->r3;
    // 0x80801FEC: sb          $v0, 0x94($s2)
    MEM_B(0X94, ctx->r18) = ctx->r2;
L_80801FF0:
    // 0x80801FF0: lb          $t8, 0x94($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X94);
L_80801FF4:
    // 0x80801FF4: bgtzl       $t8, L_80802004
    if (SIGNED(ctx->r24) > 0) {
        // 0x80801FF8: lh          $t9, 0x2($s1)
        ctx->r25 = MEM_H(ctx->r17, 0X2);
            goto L_80802004;
    }
    goto skip_7;
    // 0x80801FF8: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
    skip_7:
    // 0x80801FFC: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80802000: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
L_80802004:
    // 0x80802004: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80802008: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8080200C: slt         $at, $s3, $t9
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80802010: bne         $at, $zero, L_80801EC0
    if (ctx->r1 != 0) {
        // 0x80802014: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80801EC0;
    }
    // 0x80802014: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80802018:
    // 0x80802018: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x8080201C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80802020: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x80802024: beq         $a0, $zero, L_80802094
    if (ctx->r4 == 0) {
        // 0x80802028: addiu       $s6, $zero, 0x3
        ctx->r22 = ADD32(0, 0X3);
            goto L_80802094;
    }
    // 0x80802028: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x8080202C: jal         0x80087AF8
    // 0x80802030: nop

    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x80802030: nop

    after_12:
    // 0x80802034: beq         $v0, $zero, L_80802054
    if (ctx->r2 == 0) {
        // 0x80802038: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80802054;
    }
    // 0x80802038: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080203C: beql        $v0, $s5, L_80802094
    if (ctx->r2 == ctx->r21) {
        // 0x80802040: sb          $s0, 0x24($s1)
        MEM_B(0X24, ctx->r17) = ctx->r16;
            goto L_80802094;
    }
    goto skip_8;
    // 0x80802040: sb          $s0, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r16;
    skip_8:
    // 0x80802044: beql        $v0, $s6, L_80802094
    if (ctx->r2 == ctx->r22) {
        // 0x80802048: sb          $s0, 0x24($s1)
        MEM_B(0X24, ctx->r17) = ctx->r16;
            goto L_80802094;
    }
    goto skip_9;
    // 0x80802048: sb          $s0, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r16;
    skip_9:
    // 0x8080204C: b           L_80802094
    // 0x80802050: sb          $s0, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r16;
        goto L_80802094;
    // 0x80802050: sb          $s0, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r16;
L_80802054:
    // 0x80802054: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80802058: lbu         $t0, 0x24($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X24);
    // 0x8080205C: beql        $v0, $t0, L_80802094
    if (ctx->r2 == ctx->r8) {
        // 0x80802060: sb          $s0, 0x24($s1)
        MEM_B(0X24, ctx->r17) = ctx->r16;
            goto L_80802094;
    }
    goto skip_10;
    // 0x80802060: sb          $s0, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r16;
    skip_10:
    // 0x80802064: jal         0x80087B28
    // 0x80802068: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    _gczoombox_entrypoint_9(rdram, ctx);
        goto after_13;
    // 0x80802068: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    after_13:
    // 0x8080206C: jal         0x80087B38
    // 0x80802070: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    _gczoombox_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x80802070: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    after_14:
    // 0x80802074: lwc1        $f16, 0x38($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80802078: c.eq.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl == ctx->f16.fl;
    // 0x8080207C: nop

    // 0x80802080: bc1fl       L_80802094
    if (!c1cs) {
        // 0x80802084: sb          $s0, 0x24($s1)
        MEM_B(0X24, ctx->r17) = ctx->r16;
            goto L_80802094;
    }
    goto skip_11;
    // 0x80802084: sb          $s0, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r16;
    skip_11:
    // 0x80802088: lwc1        $f18, 0x18($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8080208C: swc1        $f18, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f18.u32l;
    // 0x80802090: sb          $s0, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r16;
L_80802094:
    // 0x80802094: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80802098: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8080209C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808020A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808020A4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808020A8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808020AC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x808020B0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x808020B4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x808020B8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x808020BC: jr          $ra
    // 0x808020C0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808020C0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _bstrexlarge_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083FF8: syscall     101
    recomp_syscall_handler(rdram, ctx, 0x80083FF8);
    return;
    // 0x80083FFC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800CD8_chamazongoldhordeofficial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800CDC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800CE0: addiu       $at, $zero, 0xF0D
    ctx->r1 = ADD32(0, 0XF0D);
    // 0x80800CE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800CE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800CEC: beq         $a1, $at, L_80800D64
    if (ctx->r5 == ctx->r1) {
        // 0x80800CF0: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800D64;
    }
    // 0x80800CF0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800CF4: addiu       $at, $zero, 0xF2D
    ctx->r1 = ADD32(0, 0XF2D);
    // 0x80800CF8: beq         $a1, $at, L_80800D1C
    if (ctx->r5 == ctx->r1) {
        // 0x80800CFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D1C;
    }
    // 0x80800CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D00: addiu       $at, $zero, 0xF2E
    ctx->r1 = ADD32(0, 0XF2E);
    // 0x80800D04: beq         $a1, $at, L_80800DA0
    if (ctx->r5 == ctx->r1) {
        // 0x80800D08: addiu       $at, $zero, 0xF59
        ctx->r1 = ADD32(0, 0XF59);
            goto L_80800DA0;
    }
    // 0x80800D08: addiu       $at, $zero, 0xF59
    ctx->r1 = ADD32(0, 0XF59);
    // 0x80800D0C: beql        $a1, $at, L_80800D68
    if (ctx->r5 == ctx->r1) {
        // 0x80800D10: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D68;
    }
    goto skip_0;
    // 0x80800D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800D14: b           L_80800D98
    // 0x80800D18: nop

        goto L_80800D98;
    // 0x80800D18: nop

L_80800D1C:
    // 0x80800D1C: jal         0x80100094
    // 0x80800D20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D28: jal         0x8008A2C0
    // 0x80800D2C: addiu       $a1, $v0, 0x6C
    ctx->r5 = ADD32(ctx->r2, 0X6C);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800D2C: addiu       $a1, $v0, 0x6C
    ctx->r5 = ADD32(ctx->r2, 0X6C);
    after_1:
    // 0x80800D30: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800D34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800D38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800D3C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800D40: jal         0x800D1000
    // 0x80800D44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_2;
    // 0x80800D44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80800D48: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800D4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800D50: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800D54: jal         0x80085708
    // 0x80800D58: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    _capod_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80800D58: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    after_3:
    // 0x80800D5C: b           L_80800DA4
    // 0x80800D60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800DA4;
    // 0x80800D60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D64:
    // 0x80800D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D68:
    // 0x80800D68: jal         0x80100094
    // 0x80800D6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800D6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D74: jal         0x8008A2C0
    // 0x80800D78: addiu       $a1, $v0, 0x6C
    ctx->r5 = ADD32(ctx->r2, 0X6C);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800D78: addiu       $a1, $v0, 0x6C
    ctx->r5 = ADD32(ctx->r2, 0X6C);
    after_5:
    // 0x80800D7C: jal         0x800DA544
    // 0x80800D80: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x80800D80: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    after_6:
    // 0x80800D84: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    // 0x80800D88: jal         0x800887D8
    // 0x80800D8C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x80800D8C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_7:
    // 0x80800D90: b           L_80800DA4
    // 0x80800D94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800DA4;
    // 0x80800D94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D98:
    // 0x80800D98: jal         0x80800E18
    // 0x80800D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E18_chamazongoldhordeofficial(rdram, ctx);
        goto after_8;
    // 0x80800D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80800DA0:
    // 0x80800DA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800DA4:
    // 0x80800DA4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800DA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800DAC: jr          $ra
    // 0x80800DB0: nop

    return;
    // 0x80800DB0: nop

;}
