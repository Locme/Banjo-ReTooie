#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800DFCE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFCE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DFCEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DFCF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DFCF4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800DFCF8: jal         0x8001B798
    // 0x800DFCFC: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x800DFCFC: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x800DFD00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DFD04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DFD08: jr          $ra
    // 0x800DFD0C: nop

    return;
    // 0x800DFD0C: nop

;}
RECOMP_FUNC void _glhittableDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088610: syscall     696
    recomp_syscall_handler(rdram, ctx, 0x80088610);
    return;
    // 0x80088614: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801724_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801724: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80801728: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8080172C: sw          $zero, 0x64($a0)
    MEM_W(0X64, ctx->r4) = 0;
    // 0x80801730: sw          $zero, 0x68($a0)
    MEM_W(0X68, ctx->r4) = 0;
    // 0x80801734: sw          $zero, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = 0;
    // 0x80801738: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x8080173C: sw          $zero, 0x68($v1)
    MEM_W(0X68, ctx->r3) = 0;
    // 0x80801740: sw          $zero, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = 0;
    // 0x80801744: sw          $zero, 0x70($v1)
    MEM_W(0X70, ctx->r3) = 0;
    // 0x80801748: sw          $zero, 0x64($v1)
    MEM_W(0X64, ctx->r3) = 0;
    // 0x8080174C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80801750: jr          $ra
    // 0x80801754: sw          $t7, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r15;
    return;
    // 0x80801754: sw          $t7, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_800E0448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0448: jr          $ra
    // 0x800E044C: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    return;
    // 0x800E044C: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
;}
RECOMP_FUNC void suexpressjoint_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080012C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800134: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800138: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8080013C: addiu       $a2, $a0, 0x20
    ctx->r6 = ADD32(ctx->r4, 0X20);
    // 0x80800140: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80800144: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80800148: jal         0x808000F4
    // 0x8080014C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    suexpressjoint_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080014C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800150: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800154: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3134, 0X1818) << 16);
    // 0x80800158: addiu       $a1, $a1, 0x1818
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3134, 0X1818));
    // 0x8080015C: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x80800160: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800164: sb          $zero, 0x8($a0)
    MEM_B(0X8, ctx->r4) = 0;
    // 0x80800168: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8080016C: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x80800170: lbu         $t0, 0xC($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XC);
    // 0x80800174: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800178: blezl       $t0, L_808001C4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8080017C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001C4;
    }
    goto skip_0;
    // 0x8080017C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800180: lbu         $t2, 0xA($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XA);
L_80800184:
    // 0x80800184: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80800188: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8080018C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80800190: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80800194: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80800198: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x8080019C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808001A0: sb          $t6, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r14;
    // 0x808001A4: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x808001A8: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x808001AC: addu        $v0, $a1, $t8
    ctx->r2 = ADD32(ctx->r5, ctx->r24);
    // 0x808001B0: lbu         $t9, 0xC($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XC);
    // 0x808001B4: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x808001B8: bnel        $at, $zero, L_80800184
    if (ctx->r1 != 0) {
        // 0x808001BC: lbu         $t2, 0xA($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0XA);
            goto L_80800184;
    }
    goto skip_1;
    // 0x808001BC: lbu         $t2, 0xA($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XA);
    skip_1:
    // 0x808001C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001C4:
    // 0x808001C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001C8: jr          $ra
    // 0x808001CC: nop

    return;
    // 0x808001CC: nop

;}
RECOMP_FUNC void func_80800FE0_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800FE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800FE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800FEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800FF0: jal         0x800D9078
    // 0x80800FF4: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80800FF4: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x80800FF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800FFC: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801004: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801008: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8080100C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1112, 0X1410) << 16);
    // 0x80801010: bc1fl       L_80801040
    if (!c1cs) {
        // 0x80801014: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801040;
    }
    goto skip_0;
    // 0x80801014: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801018: jal         0x80089D18
    // 0x8080101C: addiu       $a2, $a2, 0x1410
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1112, 0X1410));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080101C: addiu       $a2, $a2, 0x1410
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1112, 0X1410));
    after_1:
    // 0x80801020: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80801024: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801028: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8080102C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801030: jal         0x800DC178
    // 0x80801034: nop

    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80801034: nop

    after_2:
    // 0x80801038: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x8080103C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801040:
    // 0x80801040: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801044: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801048: jr          $ra
    // 0x8080104C: nop

    return;
    // 0x8080104C: nop

;}
RECOMP_FUNC void bskazstilt_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080043C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800440: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(292, 0X1200) << 16);
    // 0x80800444: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800448: jr          $ra
    // 0x8080044C: lw          $v0, 0x1200($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(292, 0X1200));
    return;
    // 0x8080044C: lw          $v0, 0x1200($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(292, 0X1200));
;}
RECOMP_FUNC void func_8009E964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E964: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009E968: jr          $ra
    // 0x8009E96C: lbu         $v0, 0x7078($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7078);
    return;
    // 0x8009E96C: lbu         $v0, 0x7078($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7078);
;}
RECOMP_FUNC void bsbeggass_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000AC: jal         0x8008CABC
    // 0x808000B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808000B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x808000B4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808000B8: jal         0x80094BC0
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094BC0(rdram, ctx);
        goto after_1;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000C0: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x808000C4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x808000C8: jal         0x80097BFC
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_poop_egg(rdram, ctx);
        goto after_2;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000D0: beql        $v0, $zero, L_80800108
    if (ctx->r2 == 0) {
        // 0x808000D4: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80800108;
    }
    goto skip_0;
    // 0x808000D4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000D8: jal         0x80094B14
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094B14(rdram, ctx);
        goto after_3;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000E0: beq         $v0, $zero, L_80800104
    if (ctx->r2 == 0) {
        // 0x808000E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800104;
    }
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: jal         0x800944E0
    // 0x808000EC: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    func_800944E0(rdram, ctx);
        goto after_4;
    // 0x808000EC: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    after_4:
    // 0x808000F0: lw          $a0, 0x15C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X15C);
    // 0x808000F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808000F8: jal         0x800F1418
    // 0x808000FC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    func_800F1418(rdram, ctx);
        goto after_5;
    // 0x808000FC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_5:
    // 0x80800100: sw          $v0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r2;
L_80800104:
    // 0x80800104: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80800108:
    // 0x80800108: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080010C: lui         $a1, 0x3EC4
    ctx->r5 = S32(0X3EC4 << 16);
    // 0x80800110: beq         $t7, $zero, L_8080019C
    if (ctx->r15 == 0) {
        // 0x80800114: nop
    
            goto L_8080019C;
    }
    // 0x80800114: nop

    // 0x80800118: jal         0x8008B348
    // 0x8080011C: ori         $a1, $a1, 0x7454
    ctx->r5 = ctx->r5 | 0X7454;
    anctrl_isAt(rdram, ctx);
        goto after_6;
    // 0x8080011C: ori         $a1, $a1, 0x7454
    ctx->r5 = ctx->r5 | 0X7454;
    after_6:
    // 0x80800120: beql        $v0, $zero, L_80800150
    if (ctx->r2 == 0) {
        // 0x80800124: lui         $a1, 0x3EFA
        ctx->r5 = S32(0X3EFA << 16);
            goto L_80800150;
    }
    goto skip_1;
    // 0x80800124: lui         $a1, 0x3EFA
    ctx->r5 = S32(0X3EFA << 16);
    skip_1:
    // 0x80800128: jal         0x80084A80
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggsetup_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    // 0x80800138: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x8080013C: jal         0x80084A48
    // 0x80800140: lui         $a3, 0xC190
    ctx->r7 = S32(0XC190 << 16);
    _baeggsetup_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800140: lui         $a3, 0xC190
    ctx->r7 = S32(0XC190 << 16);
    after_8:
    // 0x80800144: jal         0x800C6DA0
    // 0x80800148: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800C6DA0(rdram, ctx);
        goto after_9;
    // 0x80800148: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_9:
    // 0x8080014C: lui         $a1, 0x3EFA
    ctx->r5 = S32(0X3EFA << 16);
L_80800150:
    // 0x80800150: ori         $a1, $a1, 0x1CAC
    ctx->r5 = ctx->r5 | 0X1CAC;
    // 0x80800154: jal         0x8008B348
    // 0x80800158: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_10;
    // 0x80800158: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x8080015C: beq         $v0, $zero, L_8080019C
    if (ctx->r2 == 0) {
        // 0x80800160: nop
    
            goto L_8080019C;
    }
    // 0x80800160: nop

    // 0x80800164: lw          $t8, 0x160($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X160);
    // 0x80800168: lw          $t9, 0x15C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X15C);
    // 0x8080016C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800170: lui         $a1, 0x3EB2
    ctx->r5 = S32(0X3EB2 << 16);
    // 0x80800174: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80800178: beq         $at, $zero, L_8080019C
    if (ctx->r1 == 0) {
        // 0x8080017C: nop
    
            goto L_8080019C;
    }
    // 0x8080017C: nop

    // 0x80800180: jal         0x8008B24C
    // 0x80800184: ori         $a1, $a1, 0xB021
    ctx->r5 = ctx->r5 | 0XB021;
    anctrl_setStart(rdram, ctx);
        goto after_11;
    // 0x80800184: ori         $a1, $a1, 0xB021
    ctx->r5 = ctx->r5 | 0XB021;
    after_11:
    // 0x80800188: jal         0x8008B064
    // 0x8080018C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_start(rdram, ctx);
        goto after_12;
    // 0x8080018C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_12:
    // 0x80800190: lw          $t0, 0x160($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X160);
    // 0x80800194: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80800198: sw          $t1, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r9;
L_8080019C:
    // 0x8080019C: jal         0x8008DD04
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_13;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001A4: beq         $v0, $zero, L_808001B4
    if (ctx->r2 == 0) {
        // 0x808001A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001B4;
    }
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: addiu       $t2, $zero, 0x2F
    ctx->r10 = ADD32(0, 0X2F);
    // 0x808001B0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_808001B4:
    // 0x808001B4: jal         0x800919F4
    // 0x808001B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_14;
    // 0x808001B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x808001BC: beq         $v0, $zero, L_8080020C
    if (ctx->r2 == 0) {
        // 0x808001C0: nop
    
            goto L_8080020C;
    }
    // 0x808001C0: nop

    // 0x808001C4: jal         0x8008B324
    // 0x808001C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isStopped(rdram, ctx);
        goto after_15;
    // 0x808001C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_15:
    // 0x808001CC: beq         $v0, $zero, L_808001D8
    if (ctx->r2 == 0) {
        // 0x808001D0: addiu       $t3, $zero, 0x7
        ctx->r11 = ADD32(0, 0X7);
            goto L_808001D8;
    }
    // 0x808001D0: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x808001D4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_808001D8:
    // 0x808001D8: jal         0x8008B2B4
    // 0x808001DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_16;
    // 0x808001DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_16:
    // 0x808001E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(84, 0X290) << 16);
    // 0x808001E4: lwc1        $f4, 0x290($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(84, 0X290));
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001EC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808001F0: nop

    // 0x808001F4: bc1fl       L_80800224
    if (!c1cs) {
        // 0x808001F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800224;
    }
    goto skip_2;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808001FC: jal         0x80082F78
    // 0x80800200: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _bscrouch_entrypoint_4(rdram, ctx);
        goto after_17;
    // 0x80800200: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_17:
    // 0x80800204: b           L_80800220
    // 0x80800208: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_80800220;
    // 0x80800208: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_8080020C:
    // 0x8080020C: jal         0x8008B324
    // 0x80800210: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isStopped(rdram, ctx);
        goto after_18;
    // 0x80800210: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_18:
    // 0x80800214: beq         $v0, $zero, L_80800220
    if (ctx->r2 == 0) {
        // 0x80800218: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80800220;
    }
    // 0x80800218: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8080021C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_80800220:
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800224:
    // 0x80800224: jal         0x8009E5C8
    // 0x80800228: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_19;
    // 0x80800228: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_19:
    // 0x8080022C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800230: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800234: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800238: jr          $ra
    // 0x8080023C: nop

    return;
    // 0x8080023C: nop

;}
RECOMP_FUNC void func_800A3550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3550: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3554: jr          $ra
    // 0x800A3558: sb          $a1, 0x50($t6)
    MEM_B(0X50, ctx->r14) = ctx->r5;
    return;
    // 0x800A3558: sb          $a1, 0x50($t6)
    MEM_B(0X50, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_80800000_chjamjarsdummy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lbu         $t9, 0x79($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X79);
    // 0x8080000C: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x80800010: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800014: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x80800018: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8080001C: andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    // 0x80800020: srl         $t2, $v0, 4
    ctx->r10 = S32(U32(ctx->r2) >> 4);
    // 0x80800024: beq         $t2, $zero, L_80800048
    if (ctx->r10 == 0) {
        // 0x80800028: sb          $t1, 0x79($a0)
        MEM_B(0X79, ctx->r4) = ctx->r9;
            goto L_80800048;
    }
    // 0x80800028: sb          $t1, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r9;
    // 0x8080002C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800030: beq         $t2, $at, L_80800060
    if (ctx->r10 == ctx->r1) {
        // 0x80800034: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800060;
    }
    // 0x80800034: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800038: beql        $t2, $at, L_808000C0
    if (ctx->r10 == ctx->r1) {
        // 0x8080003C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_808000C0;
    }
    goto skip_0;
    // 0x8080003C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_0:
    // 0x80800040: b           L_808000D4
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000D4;
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800048:
    // 0x80800048: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080004C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80800050: jal         0x80089CD0
    // 0x80800054: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    _subaddiefade_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80800054: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x80800058: b           L_808000D4
    // 0x8080005C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000D4;
    // 0x8080005C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800060:
    // 0x80800060: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80800064: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800068: andi        $t3, $v0, 0x1FF
    ctx->r11 = ctx->r2 & 0X1FF;
    // 0x8080006C: beql        $t3, $zero, L_80800094
    if (ctx->r11 == 0) {
        // 0x80800070: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80800094;
    }
    goto skip_1;
    // 0x80800070: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x80800074: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800078: beq         $t3, $at, L_8080009C
    if (ctx->r11 == ctx->r1) {
        // 0x8080007C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080009C;
    }
    // 0x8080007C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800080: beql        $t3, $at, L_808000B0
    if (ctx->r11 == ctx->r1) {
        // 0x80800084: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_808000B0;
    }
    goto skip_2;
    // 0x80800084: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_2:
    // 0x80800088: b           L_808000D4
    // 0x8080008C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000D4;
    // 0x8080008C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800090: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80800094:
    // 0x80800094: b           L_808000D0
    // 0x80800098: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
        goto L_808000D0;
    // 0x80800098: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
L_8080009C:
    // 0x8080009C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808000A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000A4: b           L_808000D0
    // 0x808000A8: swc1        $f8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f8.u32l;
        goto L_808000D0;
    // 0x808000A8: swc1        $f8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f8.u32l;
    // 0x808000AC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_808000B0:
    // 0x808000B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808000B4: b           L_808000D0
    // 0x808000B8: swc1        $f10, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f10.u32l;
        goto L_808000D0;
    // 0x808000B8: swc1        $f10, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f10.u32l;
    // 0x808000BC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_808000C0:
    // 0x808000C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808000C4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808000C8: swc1        $f16, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f16.u32l;
    // 0x808000CC: swc1        $f18, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f18.u32l;
L_808000D0:
    // 0x808000D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000D4:
    // 0x808000D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D8: jr          $ra
    // 0x808000DC: nop

    return;
    // 0x808000DC: nop

;}
RECOMP_FUNC void func_8009E55C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E55C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8009E560: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009E564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E56C: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x8009E570: lw          $t6, 0x114($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X114);
    // 0x8009E574: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8009E578: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x8009E57C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8009E580: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8009E584: bc1f        L_8009E594
    if (!c1cs) {
        // 0x8009E588: swc1        $f12, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->f12.u32l;
            goto L_8009E594;
    }
    // 0x8009E588: swc1        $f12, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f12.u32l;
    // 0x8009E58C: jal         0x8009E4E0
    // 0x8009E590: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009E4E0(rdram, ctx);
        goto after_0;
    // 0x8009E590: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_8009E594:
    // 0x8009E594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E59C: jr          $ra
    // 0x8009E5A0: nop

    return;
    // 0x8009E5A0: nop

;}
RECOMP_FUNC void func_80800158_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800158: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080015C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800160: jal         0x80106790
    // 0x80800164: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800164: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800168: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080016C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800170: jal         0x80100094
    // 0x80800174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800178: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8080017C: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x80800180: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800184: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800188: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8080018C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800190: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80800194: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80800198: swc1        $f4, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f4.u32l;
    // 0x8080019C: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x808001A0: jal         0x808007E4
    // 0x808001A4: addiu       $a1, $zero, 0xEB0
    ctx->r5 = ADD32(0, 0XEB0);
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_2;
    // 0x808001A4: addiu       $a1, $zero, 0xEB0
    ctx->r5 = ADD32(0, 0XEB0);
    after_2:
    // 0x808001A8: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x808001AC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808001B0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x808001B4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x808001B8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x808001BC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x808001C0: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    // 0x808001C4: jal         0x808035C4
    // 0x808001C8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_808035C4_chjiggygamenew(rdram, ctx);
        goto after_3;
    // 0x808001C8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_3:
    // 0x808001CC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x808001D0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x808001D4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x808001D8: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x808001DC: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x808001E0: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x808001E4: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x808001E8: lb          $t4, 0x1($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X1);
    // 0x808001EC: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x808001F0: sb          $v0, 0x1F4($t5)
    MEM_B(0X1F4, ctx->r13) = ctx->r2;
    // 0x808001F4: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    // 0x808001F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800200: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800204: jr          $ra
    // 0x80800208: nop

    return;
    // 0x80800208: nop

;}
RECOMP_FUNC void func_80804DA0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804DA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804DA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804DA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804DAC: jal         0x80807D48
    // 0x80804DB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80807D48_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80804DB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80804DB4: jal         0x80809D24
    // 0x80804DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809D24_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80804DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80804DBC: jal         0x800A3404
    // 0x80804DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3404(rdram, ctx);
        goto after_2;
    // 0x80804DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80804DC4: beql        $v0, $zero, L_80804DF8
    if (ctx->r2 == 0) {
        // 0x80804DC8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80804DF8;
    }
    goto skip_0;
    // 0x80804DC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80804DCC: jal         0x80801928
    // 0x80804DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801928_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80804DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80804DD4: jal         0x808008B0
    // 0x80804DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008B0_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80804DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80804DDC: bne         $v0, $zero, L_80804DF4
    if (ctx->r2 != 0) {
        // 0x80804DE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804DF4;
    }
    // 0x80804DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804DE4: jal         0x8009E5C8
    // 0x80804DE8: addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
    bs_setState(rdram, ctx);
        goto after_5;
    // 0x80804DE8: addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
    after_5:
    // 0x80804DEC: jal         0x80804A3C
    // 0x80804DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804A3C_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x80804DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80804DF4:
    // 0x80804DF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804DF8:
    // 0x80804DF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804DFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804E00: jr          $ra
    // 0x80804E04: nop

    return;
    // 0x80804E04: nop

;}
RECOMP_FUNC void _chusefeather_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085950: syscall     182
    recomp_syscall_handler(rdram, ctx, 0x80085950);
    return;
    // 0x80085954: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800E90_chnastycavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E94: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800E98: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800E9C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800EA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EA4: beq         $a1, $at, L_80800FD8
    if (ctx->r5 == ctx->r1) {
        // 0x80800EA8: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80800FD8;
    }
    // 0x80800EA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800EAC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800EB0: beq         $a1, $at, L_80800F98
    if (ctx->r5 == ctx->r1) {
        // 0x80800EB4: lh          $v1, 0x28($sp)
        ctx->r3 = MEM_H(ctx->r29, 0X28);
            goto L_80800F98;
    }
    // 0x80800EB4: lh          $v1, 0x28($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X28);
    // 0x80800EB8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800EBC: bne         $a1, $at, L_80801020
    if (ctx->r5 != ctx->r1) {
        // 0x80800EC0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80801020;
    }
    // 0x80800EC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800EC4: jal         0x80100094
    // 0x80800EC8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800EC8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800ECC: jal         0x80800968
    // 0x80800ED0: nop

    func_80800968_chnastycavemen(rdram, ctx);
        goto after_1;
    // 0x80800ED0: nop

    after_1:
    // 0x80800ED4: jal         0x8080000C
    // 0x80800ED8: nop

    func_8080000C_chnastycavemen(rdram, ctx);
        goto after_2;
    // 0x80800ED8: nop

    after_2:
    // 0x80800EDC: beq         $v0, $zero, L_80800EF4
    if (ctx->r2 == 0) {
        // 0x80800EE0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800EF4;
    }
    // 0x80800EE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800EE4: jal         0x80102424
    // 0x80800EE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800EE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800EEC: b           L_80800F58
    // 0x80800EF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_80800F58;
    // 0x80800EF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800EF4:
    // 0x80800EF4: jal         0x800DA298
    // 0x80800EF8: addiu       $a0, $zero, 0x184
    ctx->r4 = ADD32(0, 0X184);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800EF8: addiu       $a0, $zero, 0x184
    ctx->r4 = ADD32(0, 0X184);
    after_4:
    // 0x80800EFC: beq         $v0, $zero, L_80800F38
    if (ctx->r2 == 0) {
        // 0x80800F00: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800F38;
    }
    // 0x80800F00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800F04: jal         0x8010573C
    // 0x80800F08: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8010573C(rdram, ctx);
        goto after_5;
    // 0x80800F08: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
    // 0x80800F0C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800F10: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800F14: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800F18: jal         0x800F1DCC
    // 0x80800F1C: lwc1        $f12, 0x48($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_6;
    // 0x80800F1C: lwc1        $f12, 0x48($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X48);
    after_6:
    // 0x80800F20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800F24: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800F28: jal         0x80102424
    // 0x80800F2C: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80800F2C: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    after_7:
    // 0x80800F30: b           L_80800F58
    // 0x80800F34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_80800F58;
    // 0x80800F34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800F38:
    // 0x80800F38: jal         0x800EA090
    // 0x80800F3C: nop

    func_800EA090(rdram, ctx);
        goto after_8;
    // 0x80800F3C: nop

    after_8:
    // 0x80800F40: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800F44: bne         $v0, $at, L_80800F54
    if (ctx->r2 != ctx->r1) {
        // 0x80800F48: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800F54;
    }
    // 0x80800F48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800F4C: jal         0x80102424
    // 0x80800F50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800F50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
L_80800F54:
    // 0x80800F54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800F58:
    // 0x80800F58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800F5C: jal         0x800897C0
    // 0x80800F60: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_10;
    // 0x80800F60: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_10:
    // 0x80800F64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800F68: jal         0x80100094
    // 0x80800F6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x80800F6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800F70: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800F74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F78: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800F7C: jal         0x800897E8
    // 0x80800F80: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_12;
    // 0x80800F80: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_12:
    // 0x80800F84: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F88: jal         0x80089810
    // 0x80800F8C: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_13;
    // 0x80800F8C: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    after_13:
    // 0x80800F90: b           L_8080102C
    // 0x80800F94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080102C;
    // 0x80800F94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F98:
    // 0x80800F98: addiu       $at, $zero, 0x17EF
    ctx->r1 = ADD32(0, 0X17EF);
    // 0x80800F9C: beq         $v1, $at, L_80800FAC
    if (ctx->r3 == ctx->r1) {
        // 0x80800FA0: addiu       $at, $zero, 0x17F0
        ctx->r1 = ADD32(0, 0X17F0);
            goto L_80800FAC;
    }
    // 0x80800FA0: addiu       $at, $zero, 0x17F0
    ctx->r1 = ADD32(0, 0X17F0);
    // 0x80800FA4: bne         $v1, $at, L_80800FBC
    if (ctx->r3 != ctx->r1) {
        // 0x80800FA8: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80800FBC;
    }
    // 0x80800FA8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_80800FAC:
    // 0x80800FAC: jal         0x8080010C
    // 0x80800FB0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8080010C_chnastycavemen(rdram, ctx);
        goto after_14;
    // 0x80800FB0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_14:
    // 0x80800FB4: b           L_8080102C
    // 0x80800FB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080102C;
    // 0x80800FB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800FBC:
    // 0x80800FBC: jal         0x80090708
    // 0x80800FC0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80090708(rdram, ctx);
        goto after_15;
    // 0x80800FC0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_15:
    // 0x80800FC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800FC8: jal         0x80102424
    // 0x80800FCC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_16;
    // 0x80800FCC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_16:
    // 0x80800FD0: b           L_8080102C
    // 0x80800FD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080102C;
    // 0x80800FD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800FD8:
    // 0x80800FD8: jal         0x801015D0
    // 0x80800FDC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_801015D0(rdram, ctx);
        goto after_17;
    // 0x80800FDC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_17:
    // 0x80800FE0: jal         0x800DF3E0
    // 0x80800FE4: nop

    func_800DF3E0(rdram, ctx);
        goto after_18;
    // 0x80800FE4: nop

    after_18:
    // 0x80800FE8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800FEC: jal         0x800DF744
    // 0x80800FF0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_19;
    // 0x80800FF0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_19:
    // 0x80800FF4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80800FF8: jal         0x800DF744
    // 0x80800FFC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_20;
    // 0x80800FFC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_20:
    // 0x80801000: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80801004: jal         0x800DF744
    // 0x80801008: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_21;
    // 0x80801008: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_21:
    // 0x8080100C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80801010: jal         0x800DF744
    // 0x80801014: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_22;
    // 0x80801014: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_22:
    // 0x80801018: b           L_8080102C
    // 0x8080101C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080102C;
    // 0x8080101C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801020:
    // 0x80801020: b           L_8080102C
    // 0x80801024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080102C;
    // 0x80801024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801028: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080102C:
    // 0x8080102C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801030: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801034: jr          $ra
    // 0x80801038: nop

    return;
    // 0x80801038: nop

;}
RECOMP_FUNC void _baalarm_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084420: syscall     110
    recomp_syscall_handler(rdram, ctx, 0x80084420);
    return;
    // 0x80084424: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8009630C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009630C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80096310: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096314: jal         0x8009C150
    // 0x80096318: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8009C150(rdram, ctx);
        goto after_0;
    // 0x80096318: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009631C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80096320: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80096324: lw          $t7, 0x94($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X94);
    // 0x80096328: jal         0x800C6784
    // 0x8009632C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_800C6784(rdram, ctx);
        goto after_1;
    // 0x8009632C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x80096330: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80096334: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80096338: lw          $t9, 0x94($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X94);
    // 0x8009633C: jal         0x800C67D8
    // 0x80096340: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_800C67D8(rdram, ctx);
        goto after_2;
    // 0x80096340: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_2:
    // 0x80096344: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80096348: jal         0x800F0E00
    // 0x8009634C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F0E00(rdram, ctx);
        goto after_3;
    // 0x8009634C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_3:
    // 0x80096350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096354: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80096358: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009635C: jr          $ra
    // 0x80096360: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    return;
    // 0x80096360: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
;}
RECOMP_FUNC void _cheggproximity_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800873D0: syscall     563
    recomp_syscall_handler(rdram, ctx, 0x800873D0);
    return;
    // 0x800873D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808014D8_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014D8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808014DC: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x808014E0: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x808014E4: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x808014E8: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x808014EC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x808014F0: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x808014F4: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x808014F8: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x808014FC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80801500: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80801504: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80801508: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8080150C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80801510: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80801514: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80801518: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8080151C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801520: jal         0x80100094
    // 0x80801524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801528: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8080152C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80801530: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80801534: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80801538: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8080153C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80801540: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x80801544: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80801548: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8080154C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80801550: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801554: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801558: addiu       $s7, $zero, 0x3C
    ctx->r23 = ADD32(0, 0X3C);
    // 0x8080155C: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x80801560: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
L_80801564:
    // 0x80801564: lbu         $t6, 0x87C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X87C);
    // 0x80801568: bnel        $t6, $zero, L_808015E8
    if (ctx->r14 != 0) {
        // 0x8080156C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808015E8;
    }
    goto skip_0;
    // 0x8080156C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80801570: multu       $s1, $s6
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80801574: sb          $s5, 0x87C($s0)
    MEM_B(0X87C, ctx->r16) = ctx->r21;
    // 0x80801578: sb          $fp, 0x8B8($s0)
    MEM_B(0X8B8, ctx->r16) = ctx->r30;
    // 0x8080157C: mflo        $t7
    ctx->r15 = lo;
    // 0x80801580: addu        $v0, $s4, $t7
    ctx->r2 = ADD32(ctx->r20, ctx->r15);
    // 0x80801584: addiu       $a0, $v0, 0xC
    ctx->r4 = ADD32(ctx->r2, 0XC);
    // 0x80801588: jal         0x800EFD24
    // 0x8080158C: addiu       $s3, $v0, 0x5AC
    ctx->r19 = ADD32(ctx->r2, 0X5AC);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x8080158C: addiu       $s3, $v0, 0x5AC
    ctx->r19 = ADD32(ctx->r2, 0X5AC);
    after_1:
    // 0x80801590: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x80801594: jal         0x800DC178
    // 0x80801598: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80801598: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_2:
    // 0x8080159C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808015A0: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x808015A4: jal         0x800DC178
    // 0x808015A8: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x808015A8: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    after_3:
    // 0x808015AC: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x808015B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808015B4: lui         $at, 0xC2AA
    ctx->r1 = S32(0XC2AA << 16);
    // 0x808015B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808015BC: jal         0x800DC178
    // 0x808015C0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x808015C0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_4:
    // 0x808015C4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808015C8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808015CC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808015D0: jal         0x800EFA4C
    // 0x808015D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x808015D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x808015D8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808015DC: slti        $at, $s2, 0x4
    ctx->r1 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x808015E0: beq         $at, $zero, L_808015F0
    if (ctx->r1 == 0) {
        // 0x808015E4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808015F0;
    }
    // 0x808015E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808015E8:
    // 0x808015E8: bne         $s1, $s7, L_80801564
    if (ctx->r17 != ctx->r23) {
        // 0x808015EC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801564;
    }
    // 0x808015EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808015F0:
    // 0x808015F0: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x808015F4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808015F8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808015FC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80801600: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80801604: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80801608: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8080160C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80801610: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80801614: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80801618: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8080161C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80801620: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80801624: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80801628: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x8080162C: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80801630: jr          $ra
    // 0x80801634: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80801634: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void _dbskeleton_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A18: syscall     649
    recomp_syscall_handler(rdram, ctx, 0x80087A18);
    return;
    // 0x80087A1C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chlavatraindoorswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F78: syscall     484
    recomp_syscall_handler(rdram, ctx, 0x80086F78);
    return;
    // 0x80086F7C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801930_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801938: jal         0x80800128
    // 0x8080193C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800128_bskazfly(rdram, ctx);
        goto after_0;
    // 0x8080193C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801940: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80801944: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801948: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080194C: jal         0x80084C48
    // 0x80801950: addiu       $a1, $zero, 0x120
    ctx->r5 = ADD32(0, 0X120);
    _bafly_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80801950: addiu       $a1, $zero, 0x120
    ctx->r5 = ADD32(0, 0X120);
    after_1:
    // 0x80801954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080195C: jr          $ra
    // 0x80801960: nop

    return;
    // 0x80801960: nop

;}
RECOMP_FUNC void chbounce_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F30: jal         0x80100094
    // 0x80800F34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800F34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F40: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80800F44: jr          $ra
    // 0x80800F48: nop

    return;
    // 0x80800F48: nop

;}
RECOMP_FUNC void func_808068E8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808068E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808068EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808068F0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808068F4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808068F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808068FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80806900: jal         0x80088360
    // 0x80806904: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    _gcstatusDll_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x80806904: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_0:
    // 0x80806908: jal         0x80806AA8
    // 0x8080690C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    func_80806AA8_chgameselect(rdram, ctx);
        goto after_1;
    // 0x8080690C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_1:
    // 0x80806910: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80806914: blez        $s3, L_8080694C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80806918: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8080694C;
    }
    // 0x80806918: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080691C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_80806920:
    // 0x80806920: jal         0x80088390
    // 0x80806924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcstatusDll_entrypoint_16(rdram, ctx);
        goto after_2;
    // 0x80806924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80806928: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8080692C: bne         $at, $zero, L_8080694C
    if (ctx->r1 != 0) {
        // 0x80806930: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8080694C;
    }
    // 0x80806930: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80806934: bne         $v0, $s1, L_80806940
    if (ctx->r2 != ctx->r17) {
        // 0x80806938: sllv        $t7, $t6, $s0
        ctx->r15 = S32(ctx->r14 << (ctx->r16 & 31));
            goto L_80806940;
    }
    // 0x80806938: sllv        $t7, $t6, $s0
    ctx->r15 = S32(ctx->r14 << (ctx->r16 & 31));
    // 0x8080693C: or          $s2, $s2, $t7
    ctx->r18 = ctx->r18 | ctx->r15;
L_80806940:
    // 0x80806940: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80806944: bne         $s0, $s3, L_80806920
    if (ctx->r16 != ctx->r19) {
        // 0x80806948: nop
    
            goto L_80806920;
    }
    // 0x80806948: nop

L_8080694C:
    // 0x8080694C: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80806950: beq         $at, $zero, L_80806988
    if (ctx->r1 == 0) {
        // 0x80806954: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80806988;
    }
    // 0x80806954: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80806958: jal         0x80088340
    // 0x8080695C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _gcstatusDll_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x8080695C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80806960: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80806964: jal         0x80088340
    // 0x80806968: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _gcstatusDll_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80806968: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
    // 0x8080696C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80806970: jal         0x80088340
    // 0x80806974: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _gcstatusDll_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x80806974: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x80806978: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8080697C: jal         0x80088340
    // 0x80806980: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _gcstatusDll_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x80806980: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x80806984: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80806988:
    // 0x80806988: bgtz        $s2, L_80806998
    if (SIGNED(ctx->r18) > 0) {
        // 0x8080698C: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_80806998;
    }
    // 0x8080698C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80806990: b           L_808069AC
    // 0x80806994: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_808069AC;
    // 0x80806994: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80806998:
    // 0x80806998: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8080699C: slt         $at, $t8, $s2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x808069A0: beql        $at, $zero, L_808069B0
    if (ctx->r1 == 0) {
        // 0x808069A4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808069B0;
    }
    goto skip_0;
    // 0x808069A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808069A8: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
L_808069AC:
    // 0x808069AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808069B0:
    // 0x808069B0: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x808069B4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808069B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808069BC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808069C0: jr          $ra
    // 0x808069C4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808069C4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800EC7D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    if (tooie_others_hidden()) { return; }
    // 0x800EC7D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EC7D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EC7DC: jal         0x80106790
    // 0x800EC7E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x800EC7E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800EC7E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800EC7E8: jal         0x8010A79C
    // 0x800EC7EC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8010A79C(rdram, ctx);
        goto after_1;
    // 0x800EC7EC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800EC7F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EC7F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EC7F8: jr          $ra
    // 0x800EC7FC: nop

    return;
    // 0x800EC7FC: nop

;}
RECOMP_FUNC void _bskazstilt_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083728: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083728);
    return;
    // 0x8008372C: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void func_80801330_cheel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801334: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80801338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080133C: beq         $a1, $at, L_80801384
    if (ctx->r5 == ctx->r1) {
        // 0x80801340: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80801384;
    }
    // 0x80801340: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80801344: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80801348: beq         $a1, $at, L_80801438
    if (ctx->r5 == ctx->r1) {
        // 0x8080134C: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_80801438;
    }
    // 0x8080134C: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80801350: beq         $a1, $at, L_808013F0
    if (ctx->r5 == ctx->r1) {
        // 0x80801354: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_808013F0;
    }
    // 0x80801354: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80801358: beq         $a1, $at, L_80801480
    if (ctx->r5 == ctx->r1) {
        // 0x8080135C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80801480;
    }
    // 0x8080135C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801360: addiu       $at, $zero, 0x8F
    ctx->r1 = ADD32(0, 0X8F);
    // 0x80801364: beq         $a1, $at, L_808014A8
    if (ctx->r5 == ctx->r1) {
        // 0x80801368: addiu       $at, $zero, 0x97
        ctx->r1 = ADD32(0, 0X97);
            goto L_808014A8;
    }
    // 0x80801368: addiu       $at, $zero, 0x97
    ctx->r1 = ADD32(0, 0X97);
    // 0x8080136C: bne         $a1, $at, L_808014C4
    if (ctx->r5 != ctx->r1) {
        // 0x80801370: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1792, 0X1638) << 16);
            goto L_808014C4;
    }
    // 0x80801370: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1792, 0X1638) << 16);
    // 0x80801374: jal         0x80101010
    // 0x80801378: addiu       $a0, $a0, 0x1638
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1792, 0X1638));
    func_80101010(rdram, ctx);
        goto after_0;
    // 0x80801378: addiu       $a0, $a0, 0x1638
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1792, 0X1638));
    after_0:
    // 0x8080137C: b           L_808014D0
    // 0x80801380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808014D0;
    // 0x80801380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801384:
    // 0x80801384: lw          $a1, 0x64($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X64);
    // 0x80801388: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8080138C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80801390: sll         $t6, $a1, 12
    ctx->r14 = S32(ctx->r5 << 12);
    // 0x80801394: jal         0x800DF744
    // 0x80801398: srl         $a1, $t6, 31
    ctx->r5 = S32(U32(ctx->r14) >> 31);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80801398: srl         $a1, $t6, 31
    ctx->r5 = S32(U32(ctx->r14) >> 31);
    after_1:
    // 0x8080139C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808013A0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x808013A4: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x808013A8: lw          $t9, 0x64($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X64);
    // 0x808013AC: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x808013B0: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x808013B4: sll         $t1, $t9, 12
    ctx->r9 = S32(ctx->r25 << 12);
    // 0x808013B8: bgez        $t1, L_808013D8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808013BC: nop
    
            goto L_808013D8;
    }
    // 0x808013BC: nop

    // 0x808013C0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x808013C4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x808013C8: jal         0x800DF5D8
    // 0x808013CC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800DF5D8(rdram, ctx);
        goto after_2;
    // 0x808013CC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_2:
    // 0x808013D0: b           L_808013E0
    // 0x808013D4: nop

        goto L_808013E0;
    // 0x808013D4: nop

L_808013D8:
    // 0x808013D8: jal         0x800DF5D8
    // 0x808013DC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800DF5D8(rdram, ctx);
        goto after_3;
    // 0x808013DC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
L_808013E0:
    // 0x808013E0: jal         0x801015D0
    // 0x808013E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_801015D0(rdram, ctx);
        goto after_4;
    // 0x808013E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x808013E8: b           L_808014D0
    // 0x808013EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808014D0;
    // 0x808013EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808013F0:
    // 0x808013F0: lw          $t2, 0x24($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X24);
    // 0x808013F4: addiu       $at, $zero, 0x26E
    ctx->r1 = ADD32(0, 0X26E);
    // 0x808013F8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808013FC: srl         $t3, $t2, 22
    ctx->r11 = S32(U32(ctx->r10) >> 22);
    // 0x80801400: bne         $t3, $at, L_80801428
    if (ctx->r11 != ctx->r1) {
        // 0x80801404: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80801428;
    }
    // 0x80801404: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801408: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080140C: jal         0x80801200
    // 0x80801410: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80801200_cheel(rdram, ctx);
        goto after_5;
    // 0x80801410: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_5:
    // 0x80801414: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801418: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080141C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80801420: b           L_808014CC
    // 0x80801424: swc1        $f4, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f4.u32l;
        goto L_808014CC;
    // 0x80801424: swc1        $f4, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f4.u32l;
L_80801428:
    // 0x80801428: jal         0x80801200
    // 0x8080142C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80801200_cheel(rdram, ctx);
        goto after_6;
    // 0x8080142C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_6:
    // 0x80801430: b           L_808014D0
    // 0x80801434: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808014D0;
    // 0x80801434: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801438:
    // 0x80801438: lw          $t5, 0x24($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X24);
    // 0x8080143C: srl         $t6, $t5, 22
    ctx->r14 = S32(U32(ctx->r13) >> 22);
    // 0x80801440: bnel        $t6, $zero, L_808014D0
    if (ctx->r14 != 0) {
        // 0x80801444: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808014D0;
    }
    goto skip_0;
    // 0x80801444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80801448: jal         0x8008FD48
    // 0x8080144C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8008FD48(rdram, ctx);
        goto after_7;
    // 0x8080144C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_7:
    // 0x80801450: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80801454: bne         $v0, $at, L_8080146C
    if (ctx->r2 != ctx->r1) {
        // 0x80801458: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_8080146C;
    }
    // 0x80801458: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8080145C: jal         0x800904C8
    // 0x80801460: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_800904C8(rdram, ctx);
        goto after_8;
    // 0x80801460: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_8:
    // 0x80801464: b           L_808014D0
    // 0x80801468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808014D0;
    // 0x80801468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080146C:
    // 0x8080146C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80801470: jal         0x80090460
    // 0x80801474: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    func_80090460(rdram, ctx);
        goto after_9;
    // 0x80801474: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    after_9:
    // 0x80801478: b           L_808014D0
    // 0x8080147C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808014D0;
    // 0x8080147C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801480:
    // 0x80801480: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1792, 0X15F4) << 16);
    // 0x80801484: addiu       $a2, $a2, 0x15F4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1792, 0X15F4));
    // 0x80801488: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x8080148C: jal         0x80089D18
    // 0x80801490: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80801490: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_10:
    // 0x80801494: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801498: jal         0x80801200
    // 0x8080149C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80801200_cheel(rdram, ctx);
        goto after_11;
    // 0x8080149C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_11:
    // 0x808014A0: b           L_808014D0
    // 0x808014A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808014D0;
    // 0x808014A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808014A8:
    // 0x808014A8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808014AC: bnel        $a2, $at, L_808014D0
    if (ctx->r6 != ctx->r1) {
        // 0x808014B0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808014D0;
    }
    goto skip_1;
    // 0x808014B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x808014B4: jal         0x80800000
    // 0x808014B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800000_cheel(rdram, ctx);
        goto after_12;
    // 0x808014B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_12:
    // 0x808014BC: b           L_808014D0
    // 0x808014C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808014D0;
    // 0x808014C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808014C4:
    // 0x808014C4: b           L_808014D0
    // 0x808014C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808014D0;
    // 0x808014C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808014CC:
    // 0x808014CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808014D0:
    // 0x808014D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808014D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808014D8: jr          $ra
    // 0x808014DC: nop

    return;
    // 0x808014DC: nop

;}
RECOMP_FUNC void badust_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C1C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80800C20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800C24: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80800C28: beq         $v0, $at, L_80800C40
    if (ctx->r2 == ctx->r1) {
        // 0x80800C2C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800C40;
    }
    // 0x80800C2C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800C30: beq         $v0, $at, L_80800C50
    if (ctx->r2 == ctx->r1) {
        // 0x80800C34: nop
    
            goto L_80800C50;
    }
    // 0x80800C34: nop

    // 0x80800C38: b           L_80800C5C
    // 0x80800C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C5C;
    // 0x80800C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C40:
    // 0x80800C40: jal         0x80800010
    // 0x80800C44: nop

    func_80800010_badust(rdram, ctx);
        goto after_0;
    // 0x80800C44: nop

    after_0:
    // 0x80800C48: b           L_80800C5C
    // 0x80800C4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C5C;
    // 0x80800C4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C50:
    // 0x80800C50: jal         0x80800008
    // 0x80800C54: nop

    func_80800008_badust(rdram, ctx);
        goto after_1;
    // 0x80800C54: nop

    after_1:
    // 0x80800C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C5C:
    // 0x80800C5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C60: jr          $ra
    // 0x80800C64: nop

    return;
    // 0x80800C64: nop

    // 0x80800C68: nop

    // 0x80800C6C: nop

;}
RECOMP_FUNC void func_80800034_chdeflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080003C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800040: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80800044: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800048: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080004C: lwc1        $f4, 0x38($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80800050: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800054: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800058: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080005C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80800060: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800064: jal         0x80089F18
    // 0x80800068: nop

    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800068: nop

    after_0:
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800074: jr          $ra
    // 0x80800078: nop

    return;
    // 0x80800078: nop

;}
RECOMP_FUNC void func_80800B44_chfactoryprop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B48: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B4C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800B50: jal         0x8010A63C
    // 0x80800B54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8010A63C(rdram, ctx);
        goto after_0;
    // 0x80800B54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800B58: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80800B5C: addiu       $t7, $zero, 0x18C
    ctx->r15 = ADD32(0, 0X18C);
    // 0x80800B60: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800B64: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B6C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800B70: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800B74: jal         0x80086898
    // 0x80800B78: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800B78: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    after_1:
    // 0x80800B7C: beq         $v0, $zero, L_80800BA8
    if (ctx->r2 == 0) {
        // 0x80800B80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BA8;
    }
    // 0x80800B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B84: jal         0x800868B0
    // 0x80800B88: lui         $a1, 0x4010
    ctx->r5 = S32(0X4010 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800B88: lui         $a1, 0x4010
    ctx->r5 = S32(0X4010 << 16);
    after_2:
    // 0x80800B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B94: jal         0x800868E0
    // 0x80800B98: addiu       $a2, $zero, 0x45
    ctx->r6 = ADD32(0, 0X45);
    _chdoormake_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80800B98: addiu       $a2, $zero, 0x45
    ctx->r6 = ADD32(0, 0X45);
    after_3:
    // 0x80800B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BA0: jal         0x800868C0
    // 0x80800BA4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80800BA4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_4:
L_80800BA8:
    // 0x80800BA8: jal         0x800DA298
    // 0x80800BAC: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800BAC: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    after_5:
    // 0x80800BB0: beql        $v0, $zero, L_80800BD4
    if (ctx->r2 == 0) {
        // 0x80800BB4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800BD4;
    }
    goto skip_0;
    // 0x80800BB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800BB8: jal         0x80088840
    // 0x80800BBC: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_6;
    // 0x80800BBC: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    after_6:
    // 0x80800BC0: bnel        $v0, $zero, L_80800BD4
    if (ctx->r2 != 0) {
        // 0x80800BC4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800BD4;
    }
    goto skip_1;
    // 0x80800BC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800BC8: jal         0x800FFAB0
    // 0x80800BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_7;
    // 0x80800BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800BD4:
    // 0x80800BD4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800BD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800BDC: jr          $ra
    // 0x80800BE0: nop

    return;
    // 0x80800BE0: nop

    // 0x80800BE4: nop

    // 0x80800BE8: nop

    // 0x80800BEC: nop

;}
RECOMP_FUNC void func_80804D44_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804D44: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80804D48: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80804D4C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80804D50: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80804D54: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80804D58: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80804D5C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80804D60: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80804D64: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80804D68: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80804D6C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80804D70: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80804D74: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80804D78: jal         0x80100094
    // 0x80804D7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804D7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804D80: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80804D84: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80804D88: jal         0x800D9078
    // 0x80804D8C: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x80804D8C: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    after_1:
    // 0x80804D90: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80804D94: lui         $s7, 0x8081
    ctx->r23 = S32(RELOC_HI16(1480, 0XA058) << 16);
    // 0x80804D98: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80804D9C: addiu       $s7, $s7, -0x5FA8
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(1480, 0XA058));
    // 0x80804DA0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80804DA4: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x80804DA8: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x80804DAC: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80804DB0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80804DB4:
    // 0x80804DB4: lh          $v0, 0x34($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X34);
    // 0x80804DB8: beql        $v0, $zero, L_80804E50
    if (ctx->r2 == 0) {
        // 0x80804DBC: lbu         $t6, 0x48($s2)
        ctx->r14 = MEM_BU(ctx->r18, 0X48);
            goto L_80804E50;
    }
    goto skip_0;
    // 0x80804DBC: lbu         $t6, 0x48($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X48);
    skip_0:
    // 0x80804DC0: beq         $v0, $s5, L_80804DD8
    if (ctx->r2 == ctx->r21) {
        // 0x80804DC4: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80804DD8;
    }
    // 0x80804DC4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80804DC8: beq         $v0, $s6, L_80804DFC
    if (ctx->r2 == ctx->r22) {
        // 0x80804DCC: addiu       $s0, $s2, 0x38
        ctx->r16 = ADD32(ctx->r18, 0X38);
            goto L_80804DFC;
    }
    // 0x80804DCC: addiu       $s0, $s2, 0x38
    ctx->r16 = ADD32(ctx->r18, 0X38);
    // 0x80804DD0: b           L_80804E50
    // 0x80804DD4: lbu         $t6, 0x48($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X48);
        goto L_80804E50;
    // 0x80804DD4: lbu         $t6, 0x48($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X48);
L_80804DD8:
    // 0x80804DD8: or          $s4, $s5, $zero
    ctx->r20 = ctx->r21 | 0;
    // 0x80804DDC: jal         0x800DC128
    // 0x80804DE0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x80804DE0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80804DE4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80804DE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804DEC: jal         0x80805960
    // 0x80804DF0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80805960_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80804DF0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x80804DF4: b           L_80804E50
    // 0x80804DF8: lbu         $t6, 0x48($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X48);
        goto L_80804E50;
    // 0x80804DF8: lbu         $t6, 0x48($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X48);
L_80804DFC:
    // 0x80804DFC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80804E00: jal         0x800DC298
    // 0x80804E04: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    func_800DC298(rdram, ctx);
        goto after_4;
    // 0x80804E04: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    after_4:
    // 0x80804E08: beq         $v0, $zero, L_80804E18
    if (ctx->r2 == 0) {
        // 0x80804E0C: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80804E18;
    }
    // 0x80804E0C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80804E10: b           L_80804E24
    // 0x80804E14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80804E24;
    // 0x80804E14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80804E18:
    // 0x80804E18: jal         0x800DC128
    // 0x80804E1C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800DC128(rdram, ctx);
        goto after_5;
    // 0x80804E1C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x80804E20: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80804E24:
    // 0x80804E24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80804E28: jal         0x80805960
    // 0x80804E2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80805960_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x80804E2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x80804E30: jal         0x800D9078
    // 0x80804E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D9078(rdram, ctx);
        goto after_7;
    // 0x80804E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80804E38: beq         $v0, $zero, L_80804E4C
    if (ctx->r2 == 0) {
        // 0x80804E3C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80804E4C;
    }
    // 0x80804E3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80804E40: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804E44: jal         0x80805448
    // 0x80804E48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_8;
    // 0x80804E48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
L_80804E4C:
    // 0x80804E4C: lbu         $t6, 0x48($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X48);
L_80804E50:
    // 0x80804E50: sll         $t7, $s1, 1
    ctx->r15 = S32(ctx->r17 << 1);
    // 0x80804E54: addu        $t8, $s7, $t7
    ctx->r24 = ADD32(ctx->r23, ctx->r15);
    // 0x80804E58: beq         $t6, $zero, L_80804E7C
    if (ctx->r14 == 0) {
        // 0x80804E5C: addiu       $s0, $s2, 0x3C
        ctx->r16 = ADD32(ctx->r18, 0X3C);
            goto L_80804E7C;
    }
    // 0x80804E5C: addiu       $s0, $s2, 0x3C
    ctx->r16 = ADD32(ctx->r18, 0X3C);
    // 0x80804E60: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80804E64: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    // 0x80804E68: jal         0x8008A0E0
    // 0x80804E6C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80804E6C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x80804E70: lbu         $a0, 0x48($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X48);
    // 0x80804E74: jal         0x800E8830
    // 0x80804E78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800E8830(rdram, ctx);
        goto after_10;
    // 0x80804E78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
L_80804E7C:
    // 0x80804E7C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80804E80: bne         $s1, $fp, L_80804DB4
    if (ctx->r17 != ctx->r30) {
        // 0x80804E84: addiu       $s2, $s2, 0x1C
        ctx->r18 = ADD32(ctx->r18, 0X1C);
            goto L_80804DB4;
    }
    // 0x80804E84: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    // 0x80804E88: jal         0x808056F8
    // 0x80804E8C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_808056F8_chdiggerboss(rdram, ctx);
        goto after_11;
    // 0x80804E8C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_11:
    // 0x80804E90: jal         0x808057D0
    // 0x80804E94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_808057D0_chdiggerboss(rdram, ctx);
        goto after_12;
    // 0x80804E94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_12:
    // 0x80804E98: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80804E9C: lw          $t0, 0x70($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X70);
    // 0x80804EA0: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(1480, 0XA040) << 16);
    // 0x80804EA4: lbu         $a0, 0x24($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X24);
    // 0x80804EA8: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80804EAC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80804EB0: addiu       $a3, $a3, -0x5FC0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1480, 0XA040));
    // 0x80804EB4: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    // 0x80804EB8: jal         0x80089D68
    // 0x80804EBC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_13;
    // 0x80804EBC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_13:
    // 0x80804EC0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80804EC4: sb          $v0, 0x24($t2)
    MEM_B(0X24, ctx->r10) = ctx->r2;
    // 0x80804EC8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80804ECC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80804ED0: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80804ED4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80804ED8: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80804EDC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80804EE0: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80804EE4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80804EE8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80804EEC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80804EF0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80804EF4: jr          $ra
    // 0x80804EF8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80804EF8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void _fxrain_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088910: syscall     710
    recomp_syscall_handler(rdram, ctx, 0x80088910);
    return;
    // 0x80088914: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _chdragonbrothers_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086EE0: syscall     470
    recomp_syscall_handler(rdram, ctx, 0x80086EE0);
    return;
    // 0x80086EE4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8001C28C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C28C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C294: jal         0x8001D32C
    // 0x8001C298: nop

    func_8001D32C(rdram, ctx);
        goto after_0;
    // 0x8001C298: nop

    after_0:
    // 0x8001C29C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C2A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001C2A4: jr          $ra
    // 0x8001C2A8: nop

    return;
    // 0x8001C2A8: nop

;}
RECOMP_FUNC void func_800CC61C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC61C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800CC620: lw          $t7, -0x517C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X517C);
    // 0x800CC624: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800CC628: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800CC62C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CC630: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800CC634: jr          $ra
    // 0x800CC638: lbu         $v0, 0x3($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X3);
    return;
    // 0x800CC638: lbu         $v0, 0x3($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X3);
;}
RECOMP_FUNC void suflamefx_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808002EC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x808002F0: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x808002F4: trunc.w.s   $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x808002F8: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x808002FC: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80800300: sh          $t7, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r15;
    // 0x80800304: jr          $ra
    // 0x80800308: sh          $t9, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r25;
    return;
    // 0x80800308: sh          $t9, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_8080094C_chdumbwaiterlift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080094C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800950: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800954: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800958: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080095C: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1200, 0XBC0) << 16);
    // 0x80800960: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800964: addiu       $s0, $s0, 0xBC0
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1200, 0XBC0));
    // 0x80800968: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080096C: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
L_80800970:
    // 0x80800970: jal         0x800DA298
    // 0x80800974: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800974: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    after_0:
    // 0x80800978: beql        $v0, $zero, L_80800994
    if (ctx->r2 == 0) {
        // 0x8080097C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800994;
    }
    goto skip_0;
    // 0x8080097C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80800980: jal         0x800DA524
    // 0x80800984: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    func_800DA524(rdram, ctx);
        goto after_1;
    // 0x80800984: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    after_1:
    // 0x80800988: b           L_808009A0
    // 0x8080098C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_808009A0;
    // 0x8080098C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80800990: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800994:
    // 0x80800994: bne         $s1, $s2, L_80800970
    if (ctx->r17 != ctx->r18) {
        // 0x80800998: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_80800970;
    }
    // 0x80800998: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8080099C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_808009A0:
    // 0x808009A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808009A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808009AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808009B0: jr          $ra
    // 0x808009B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808009B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808008A4_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808008A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008AC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x808008B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808008B4: jal         0x80100094
    // 0x808008B8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008B8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x808008BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808008C0: addiu       $a0, $zero, 0x152
    ctx->r4 = ADD32(0, 0X152);
    // 0x808008C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808008C8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x808008CC: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x808008D0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x808008D4: jal         0x8010856C
    // 0x808008D8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    func_8010856C(rdram, ctx);
        goto after_1;
    // 0x808008D8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x808008DC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808008E0: jal         0x80106790
    // 0x808008E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x808008E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x808008E8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808008EC: jal         0x80108944
    // 0x808008F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80108944(rdram, ctx);
        goto after_3;
    // 0x808008F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x808008F4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808008F8: jal         0x80105A9C
    // 0x808008FC: lui         $a1, 0x43E1
    ctx->r5 = S32(0X43E1 << 16);
    func_80105A9C(rdram, ctx);
        goto after_4;
    // 0x808008FC: lui         $a1, 0x43E1
    ctx->r5 = S32(0X43E1 << 16);
    after_4:
    // 0x80800900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800904: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800908: jr          $ra
    // 0x8080090C: nop

    return;
    // 0x8080090C: nop

;}
RECOMP_FUNC void _chdrips_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E58: syscall     461
    recomp_syscall_handler(rdram, ctx, 0x80086E58);
    return;
    // 0x80086E5C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808001A8_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001B8: jal         0x8009E74C
    // 0x808001BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x808001BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808001C0: bnel        $v0, $zero, L_80800228
    if (ctx->r2 != 0) {
        // 0x808001C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800228;
    }
    goto skip_0;
    // 0x808001C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808001C8: jal         0x8009E474
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E474(rdram, ctx);
        goto after_1;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001D0: jal         0x80096388
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096388(rdram, ctx);
        goto after_2;
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001D8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808001DC: bne         $v0, $at, L_808001EC
    if (ctx->r2 != ctx->r1) {
        // 0x808001E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001EC;
    }
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: jal         0x800961AC
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_3;
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_808001EC:
    // 0x808001EC: jal         0x8008E0E8
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E0E8(rdram, ctx);
        goto after_4;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001F4: beq         $v0, $zero, L_80800204
    if (ctx->r2 == 0) {
        // 0x808001F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800204;
    }
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: jal         0x80084788
    // 0x80800200: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800200: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
L_80800204:
    // 0x80800204: jal         0x800A4E30
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4E30(rdram, ctx);
        goto after_6;
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: jal         0x800A2018
    // 0x80800214: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800A2018(rdram, ctx);
        goto after_7;
    // 0x80800214: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_7:
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x80092880
    // 0x80800220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80092880(rdram, ctx);
        goto after_8;
    // 0x80800220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800228:
    // 0x80800228: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080022C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800230: jr          $ra
    // 0x80800234: nop

    return;
    // 0x80800234: nop

;}
RECOMP_FUNC void func_80082088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082088: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008208C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80082090: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80082094: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80082098: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8008209C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800820A0: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800820A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800820A8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800820AC: lh          $t1, 0x8($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X8);
    // 0x800820B0: addiu       $s0, $a0, 0x38
    ctx->r16 = ADD32(ctx->r4, 0X38);
    // 0x800820B4: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800820B8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800820BC: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
    // 0x800820C0: lbu         $t1, 0xE($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XE);
    // 0x800820C4: lh          $s3, 0x0($a0)
    ctx->r19 = MEM_H(ctx->r4, 0X0);
    // 0x800820C8: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
    // 0x800820CC: lh          $t1, 0xA($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XA);
    // 0x800820D0: addu        $s0, $s0, $t2
    ctx->r16 = ADD32(ctx->r16, ctx->r10);
    // 0x800820D4: and         $t3, $s0, $t2
    ctx->r11 = ctx->r16 & ctx->r10;
    // 0x800820D8: subu        $s0, $s0, $t3
    ctx->r16 = SUB32(ctx->r16, ctx->r11);
    // 0x800820DC: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x800820E0: addu        $s1, $s0, $t1
    ctx->r17 = ADD32(ctx->r16, ctx->r9);
    // 0x800820E4: lh          $t1, 0xC($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XC);
    // 0x800820E8: addu        $s1, $s1, $t2
    ctx->r17 = ADD32(ctx->r17, ctx->r10);
    // 0x800820EC: and         $t3, $s1, $t2
    ctx->r11 = ctx->r17 & ctx->r10;
    // 0x800820F0: subu        $s1, $s1, $t3
    ctx->r17 = SUB32(ctx->r17, ctx->r11);
    // 0x800820F4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800820F8: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x800820FC: addu        $s2, $s1, $t1
    ctx->r18 = ADD32(ctx->r17, ctx->r9);
    // 0x80082100: addu        $s2, $s2, $t2
    ctx->r18 = ADD32(ctx->r18, ctx->r10);
    // 0x80082104: and         $t3, $s2, $t2
    ctx->r11 = ctx->r18 & ctx->r10;
    // 0x80082108: subu        $s2, $s2, $t3
    ctx->r18 = SUB32(ctx->r18, ctx->r11);
    // 0x8008210C: or          $s4, $s2, $zero
    ctx->r20 = ctx->r18 | 0;
    // 0x80082110: beq         $a1, $zero, L_8008211C
    if (ctx->r5 == 0) {
        // 0x80082114: sll         $s3, $s3, 4
        ctx->r19 = S32(ctx->r19 << 4);
            goto L_8008211C;
    }
    // 0x80082114: sll         $s3, $s3, 4
    ctx->r19 = S32(ctx->r19 << 4);
    // 0x80082118: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
L_8008211C:
    // 0x8008211C: lhu         $t0, 0x2C($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X2C);
    // 0x80082120: lui         $s5, 0xB000
    ctx->r21 = S32(0XB000 << 16);
    // 0x80082124: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80082128: jal         0x80031B60
    // 0x8008212C: or          $s5, $s5, $t0
    ctx->r21 = ctx->r21 | ctx->r8;
    __osPiGetAccess_recomp(rdram, ctx);
        goto after_0;
    // 0x8008212C: or          $s5, $s5, $t0
    ctx->r21 = ctx->r21 | ctx->r8;
    after_0:
    // 0x80082130: lui         $t1, 0xA460
    ctx->r9 = S32(0XA460 << 16);
    // 0x80082134: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x80082138: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8008213C:
    // 0x8008213C: andi        $t2, $t2, 0x3
    ctx->r10 = ctx->r10 & 0X3;
    // 0x80082140: bnel        $t2, $zero, L_8008213C
    if (ctx->r10 != 0) {
        // 0x80082144: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_8008213C;
    }
    goto skip_0;
    // 0x80082144: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    skip_0:
    tooie_read_overlay_key(rdram, ctx);
    // 0x80082148: or          $s5, $s5, $zero
    ctx->r21 = ctx->r21 | 0;
    // 0x8008214C: jal         0x80031BA4
    // 0x80082150: andi        $s5, $s5, 0xFFFF
    ctx->r21 = ctx->r21 & 0XFFFF;
    __osPiRelAccess_recomp(rdram, ctx);
        goto after_1;
    // 0x80082150: andi        $s5, $s5, 0xFFFF
    ctx->r21 = ctx->r21 & 0XFFFF;
    after_1:
    // 0x80082154: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80082158: lh          $t1, 0x8($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X8);
    // 0x8008215C: addiu       $t0, $a0, 0x38
    ctx->r8 = ADD32(ctx->r4, 0X38);
    // 0x80082160: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80082164: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
L_80082168:
    // 0x80082168: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8008216C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80082170: addu        $t2, $t2, $s4
    ctx->r10 = ADD32(ctx->r10, ctx->r20);
    // 0x80082174: bne         $t0, $t1, L_80082168
    if (ctx->r8 != ctx->r9) {
        // 0x80082178: sw          $t2, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r10;
            goto L_80082168;
    }
    // 0x80082178: sw          $t2, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r10;
    // 0x8008217C: lw          $t1, 0x34($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X34);
    // 0x80082180: addu        $t1, $t1, $s4
    ctx->r9 = ADD32(ctx->r9, ctx->r20);
    // 0x80082184: sw          $t1, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r9;
    // 0x80082188: lh          $t3, 0xA($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XA);
    // 0x8008218C: beql        $t3, $zero, L_800821A8
    if (ctx->r11 == 0) {
        // 0x80082190: lh          $t3, 0xC($a0)
        ctx->r11 = MEM_H(ctx->r4, 0XC);
            goto L_800821A8;
    }
    goto skip_1;
    // 0x80082190: lh          $t3, 0xC($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XC);
    skip_1:
    // 0x80082194: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x80082198: or          $t1, $s4, $zero
    ctx->r9 = ctx->r20 | 0;
    // 0x8008219C: jal         0x800821FC
    // 0x800821A0: or          $t0, $s2, $zero
    ctx->r8 = ctx->r18 | 0;
    ovl_relocate(rdram, ctx);
        goto after_2;
    // 0x800821A0: or          $t0, $s2, $zero
    ctx->r8 = ctx->r18 | 0;
    after_2:
    // 0x800821A4: lh          $t3, 0xC($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XC);
L_800821A8:
    // 0x800821A8: beql        $t3, $zero, L_800821C4
    if (ctx->r11 == 0) {
        // 0x800821AC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800821C4;
    }
    goto skip_2;
    // 0x800821AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_2:
    // 0x800821B0: or          $t2, $s1, $zero
    ctx->r10 = ctx->r17 | 0;
    // 0x800821B4: or          $t1, $s4, $zero
    ctx->r9 = ctx->r20 | 0;
    // 0x800821B8: jal         0x800822C0
    // 0x800821BC: or          $t0, $s2, $zero
    ctx->r8 = ctx->r18 | 0;
    func_800822C0(rdram, ctx);
        goto after_3;
    // 0x800821BC: or          $t0, $s2, $zero
    ctx->r8 = ctx->r18 | 0;
    after_3:
    // 0x800821C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800821C4:
    // 0x800821C4: jal         0x8002E660
    // 0x800821C8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_4;
    // 0x800821C8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x800821CC: jal         0x80030AB0
    // 0x800821D0: nop

    osInvalICache_recomp(rdram, ctx);
        goto after_5;
    // 0x800821D0: nop

    after_5:
    tooie_overlay_placed(rdram, ctx);
    // 0x800821D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800821D8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800821DC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800821E0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800821E4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800821E8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800821EC: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800821F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800821F4: jr          $ra
    // 0x800821F8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800821F8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800094_chlagoonbilldrillcover(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080009C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808000A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000A4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x808000A8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000AC: bnel        $t7, $at, L_808000D0
    if (ctx->r15 != ctx->r1) {
        // 0x808000B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000D0;
    }
    goto skip_0;
    // 0x808000B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000B4: jal         0x8008A4C0
    // 0x808000B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x808000B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000BC: beq         $v0, $zero, L_808000CC
    if (ctx->r2 == 0) {
        // 0x808000C0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808000CC;
    }
    // 0x808000C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000C4: jal         0x8080024C
    // 0x808000C8: nop

    func_8080024C_chlagoonbilldrillcover(rdram, ctx);
        goto after_1;
    // 0x808000C8: nop

    after_1:
L_808000CC:
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000D0:
    // 0x808000D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D4: jr          $ra
    // 0x808000D8: nop

    return;
    // 0x808000D8: nop

;}
RECOMP_FUNC void func_800A8948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8948: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A894C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A8950: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A8954: addiu       $t7, $t7, 0x7688
    ctx->r15 = ADD32(ctx->r15, 0X7688);
    // 0x800A8958: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A895C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800A8960: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800A8964: bnel        $t8, $zero, L_800A8978
    if (ctx->r24 != 0) {
        // 0x800A8968: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_800A8978;
    }
    goto skip_0;
    // 0x800A8968: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x800A896C: jr          $ra
    // 0x800A8970: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800A8970: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A8974: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_800A8978:
    // 0x800A8978: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800A897C: jr          $ra
    // 0x800A8980: nop

    return;
    // 0x800A8980: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803460: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803464: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80803468: beq         $a0, $zero, L_808034E8
    if (ctx->r4 == 0) {
        // 0x8080346C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808034E8;
    }
    // 0x8080346C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803470: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803474: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803478: sb          $a2, 0x1CC($a0)
    MEM_B(0X1CC, ctx->r4) = ctx->r6;
    // 0x8080347C: sb          $a3, 0x1CD($a0)
    MEM_B(0X1CD, ctx->r4) = ctx->r7;
    // 0x80803480: div.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80803484: swc1        $f6, 0x1D8($a0)
    MEM_W(0X1D8, ctx->r4) = ctx->f6.u32l;
    // 0x80803488: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080348C: jal         0x80800358
    // 0x80803490: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800358_gczoombox(rdram, ctx);
        goto after_0;
    // 0x80803490: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x80803494: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80803498: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080349C: beql        $t6, $zero, L_808034B8
    if (ctx->r14 == 0) {
        // 0x808034A0: lbu         $t0, 0x1E6($a0)
        ctx->r8 = MEM_BU(ctx->r4, 0X1E6);
            goto L_808034B8;
    }
    goto skip_0;
    // 0x808034A0: lbu         $t0, 0x1E6($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X1E6);
    skip_0:
    // 0x808034A4: lbu         $t8, 0x1E6($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1E6);
    // 0x808034A8: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x808034AC: b           L_808034C0
    // 0x808034B0: sb          $t9, 0x1E6($a0)
    MEM_B(0X1E6, ctx->r4) = ctx->r25;
        goto L_808034C0;
    // 0x808034B0: sb          $t9, 0x1E6($a0)
    MEM_B(0X1E6, ctx->r4) = ctx->r25;
    // 0x808034B4: lbu         $t0, 0x1E6($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X1E6);
L_808034B8:
    // 0x808034B8: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x808034BC: sb          $t1, 0x1E6($a0)
    MEM_B(0X1E6, ctx->r4) = ctx->r9;
L_808034C0:
    // 0x808034C0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x808034C4: beql        $t2, $zero, L_808034E0
    if (ctx->r10 == 0) {
        // 0x808034C8: lbu         $t6, 0x1E6($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X1E6);
            goto L_808034E0;
    }
    goto skip_1;
    // 0x808034C8: lbu         $t6, 0x1E6($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1E6);
    skip_1:
    // 0x808034CC: lbu         $t4, 0x1E6($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X1E6);
    // 0x808034D0: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x808034D4: b           L_808034E8
    // 0x808034D8: sb          $t5, 0x1E6($a0)
    MEM_B(0X1E6, ctx->r4) = ctx->r13;
        goto L_808034E8;
    // 0x808034D8: sb          $t5, 0x1E6($a0)
    MEM_B(0X1E6, ctx->r4) = ctx->r13;
    // 0x808034DC: lbu         $t6, 0x1E6($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1E6);
L_808034E0:
    // 0x808034E0: andi        $t7, $t6, 0xFFFB
    ctx->r15 = ctx->r14 & 0XFFFB;
    // 0x808034E4: sb          $t7, 0x1E6($a0)
    MEM_B(0X1E6, ctx->r4) = ctx->r15;
L_808034E8:
    // 0x808034E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808034EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808034F0: jr          $ra
    // 0x808034F4: nop

    return;
    // 0x808034F4: nop

;}
RECOMP_FUNC void func_808003A8_chfactorymaindoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003AC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808003B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808003B8: bne         $a1, $at, L_808003F4
    if (ctx->r5 != ctx->r1) {
        // 0x808003BC: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_808003F4;
    }
    // 0x808003BC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808003C0: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x808003C4: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808003C8: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808003CC: bnel        $t7, $at, L_808003F8
    if (ctx->r15 != ctx->r1) {
        // 0x808003D0: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_808003F8;
    }
    goto skip_0;
    // 0x808003D0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    skip_0:
    // 0x808003D4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x808003D8: addiu       $a1, $zero, 0x7B8
    ctx->r5 = ADD32(0, 0X7B8);
    // 0x808003DC: lhu         $a2, 0x16($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X16);
    // 0x808003E0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x808003E4: jal         0x80103140
    // 0x808003E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x808003E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003F0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_808003F4:
    // 0x808003F4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_808003F8:
    // 0x808003F8: jal         0x80085820
    // 0x808003FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x808003FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800408: jr          $ra
    // 0x8080040C: nop

    return;
    // 0x8080040C: nop

;}
RECOMP_FUNC void suspline_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800218: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8080021C: jr          $ra
    // 0x80800220: sb          $a1, 0x8A($a0)
    MEM_B(0X8A, ctx->r4) = ctx->r5;
    return;
    // 0x80800220: sb          $a1, 0x8A($a0)
    MEM_B(0X8A, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_80809CB4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809CB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80809CB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80809CBC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80809CC0: jal         0x8009ADF0
    // 0x80809CC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009ADF0(rdram, ctx);
        goto after_0;
    // 0x80809CC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80809CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80809CCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80809CD0: jr          $ra
    // 0x80809CD4: nop

    return;
    // 0x80809CD4: nop

;}
RECOMP_FUNC void _badata_entrypoint_34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084750: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084750);
    return;
    // 0x80084754: addi        $t0, $zero, 0x88
    ctx->r8 = ADD32(0, 0X88);
;}
RECOMP_FUNC void _ncba1p_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800893D0: syscall     777
    recomp_syscall_handler(rdram, ctx, 0x800893D0);
    return;
    // 0x800893D4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
