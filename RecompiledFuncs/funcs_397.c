#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chbigterrysbits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085FF8: syscall     269
    recomp_syscall_handler(rdram, ctx, 0x80085FF8);
    return;
    // 0x80085FFC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void suegg_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800D90: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800D94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D98: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(3322, 0XE64) << 16);
    // 0x80800D9C: addiu       $a3, $a3, 0xE64
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(3322, 0XE64));
    // 0x80800DA0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800DA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800DA8: jal         0x8010D930
    // 0x80800DAC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_8010D930(rdram, ctx);
        goto after_0;
    // 0x80800DAC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_0:
    // 0x80800DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DB8: jr          $ra
    // 0x80800DBC: nop

    return;
    // 0x80800DBC: nop

;}
RECOMP_FUNC void func_80806218_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806218: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080621C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806220: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80806224: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80806228: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080622C: jal         0x80087D58
    // 0x80806230: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    _gcnewoption_entrypoint_24(rdram, ctx);
        goto after_0;
    // 0x80806230: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80806234: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80806238: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8080623C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80806240: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80806244: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80806248: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8080624C: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x80806250: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80806254: jal         0x80087CF8
    // 0x80806258: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x80806258: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    after_1:
    // 0x8080625C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80806260: lui         $t1, 0x8081
    ctx->r9 = S32(RELOC_HI16(804, 0X841C) << 16);
    // 0x80806264: addiu       $t1, $t1, -0x7BE4
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(804, 0X841C));
    // 0x80806268: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8080626C: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x80806270: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80806274: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80806278: jal         0x80087D90
    // 0x8080627C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_2;
    // 0x8080627C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80806280: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80806284: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80806288: beql        $t2, $zero, L_8080629C
    if (ctx->r10 == 0) {
        // 0x8080628C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080629C;
    }
    goto skip_0;
    // 0x8080628C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80806290: jal         0x80088410
    // 0x80806294: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    _gczoomboxdata_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80806294: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    after_3:
    // 0x80806298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080629C:
    // 0x8080629C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808062A0: jr          $ra
    // 0x808062A4: nop

    return;
    // 0x808062A4: nop

;}
RECOMP_FUNC void _sumole_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A18: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x80089A18);
    return;
    // 0x80089A1C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void badrone_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080053C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800540: jal         0x80095774
    // 0x80800544: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    baflag_clear(rdram, ctx);
        goto after_0;
    // 0x80800544: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_0:
    // 0x80800548: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080054C: jal         0x80800348
    // 0x80800550: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800348_badrone(rdram, ctx);
        goto after_1;
    // 0x80800550: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80800554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800558: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080055C: jr          $ra
    // 0x80800560: nop

    return;
    // 0x80800560: nop

;}
RECOMP_FUNC void sueggmove_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E0: jal         0x80106790
    // 0x808000E4: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808000E4: nop

    after_0:
    // 0x808000E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000EC: jal         0x80100094
    // 0x808000F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808000F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808000F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F8: lw          $v0, 0x34($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X34);
    // 0x808000FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800100: jr          $ra
    // 0x80800104: nop

    return;
    // 0x80800104: nop

;}
RECOMP_FUNC void func_800CB6B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB6B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CB6B8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800CB6BC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800CB6C0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800CB6C4: addiu       $t7, $t7, -0x5490
    ctx->r15 = ADD32(ctx->r15, -0X5490);
    // 0x800CB6C8: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800CB6CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB6D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CB6D4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800CB6D8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800CB6DC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800CB6E0: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x800CB6E4: jal         0x800EE7F8
    // 0x800CB6E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800CB6E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800CB6EC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB6F4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800CB6F8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB6FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CB700: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
    // 0x800CB704: jr          $ra
    // 0x800CB708: sh          $t8, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r24;
    return;
    // 0x800CB708: sh          $t8, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void badata_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E20: jal         0x80800000
    // 0x80800E24: nop

    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x80800E24: nop

    after_0:
    // 0x80800E28: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80800E2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E30: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(473, 0X2138) << 16);
    // 0x80800E34: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800E38: lh          $v0, 0x2138($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(473, 0X2138));
    // 0x80800E3C: jr          $ra
    // 0x80800E40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800E40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800FFC3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFC3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FFC40: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FFC44: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x800FFC48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FFC4C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FFC50: jal         0x801067C4
    // 0x800FFC54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x800FFC54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800FFC58: beq         $v0, $zero, L_800FFC7C
    if (ctx->r2 == 0) {
        // 0x800FFC5C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FFC7C;
    }
    // 0x800FFC5C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800FFC60:
    // 0x800FFC60: lbu         $t6, 0x7E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7E);
    // 0x800FFC64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800FFC68: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x800FFC6C: jal         0x8010682C
    // 0x800FFC70: sb          $t7, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r15;
    func_8010682C(rdram, ctx);
        goto after_1;
    // 0x800FFC70: sb          $t7, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r15;
    after_1:
    // 0x800FFC74: bne         $v0, $zero, L_800FFC60
    if (ctx->r2 != 0) {
        // 0x800FFC78: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FFC60;
    }
    // 0x800FFC78: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800FFC7C:
    // 0x800FFC7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FFC80: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FFC84: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FFC88: jr          $ra
    // 0x800FFC8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800FFC8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chbabydino_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C88: syscall     217
    recomp_syscall_handler(rdram, ctx, 0x80085C88);
    return;
    // 0x80085C8C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808017F0_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808017F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808017F8: jal         0x80100094
    // 0x808017FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808017FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801800: lbu         $t6, 0xC2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC2);
    // 0x80801804: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801808: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080180C: blez        $t6, L_80801834
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80801810: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80801834;
    }
    // 0x80801810: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80801814:
    // 0x80801814: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x80801818: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8080181C: lbu         $t7, 0xC2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XC2);
    // 0x80801820: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80801824: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80801828: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8080182C: bne         $at, $zero, L_80801814
    if (ctx->r1 != 0) {
        // 0x80801830: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80801814;
    }
    // 0x80801830: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80801834:
    // 0x80801834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080183C: jr          $ra
    // 0x80801840: nop

    return;
    // 0x80801840: nop

;}
RECOMP_FUNC void chjiggygamenew_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(772, 0X3D44) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x3D44
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(772, 0X3D44));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x3D44
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(772, 0X3D44));
;}
RECOMP_FUNC void func_800DA104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DA108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DA10C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800DA110: jal         0x800DA054
    // 0x800DA114: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800DA054(rdram, ctx);
        goto after_0;
    // 0x800DA114: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x800DA118: jal         0x800888B0
    // 0x800DA11C: nop

    _gldbDll_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x800DA11C: nop

    after_1:
    // 0x800DA120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DA124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DA128: jr          $ra
    // 0x800DA12C: nop

    return;
    // 0x800DA12C: nop

;}
RECOMP_FUNC void func_800A22A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A22A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A22AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A22B0: jal         0x800A25DC
    // 0x800A22B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A25DC(rdram, ctx);
        goto after_0;
    // 0x800A22B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800A22B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A22BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A22C0: jr          $ra
    // 0x800A22C4: nop

    return;
    // 0x800A22C4: nop

;}
RECOMP_FUNC void subaddiedialog_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808002DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808002E4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808002E8: jal         0x80800000
    // 0x808002EC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_80800000_subaddiedialog(rdram, ctx);
        goto after_0;
    // 0x808002EC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x808002F0: bne         $v0, $zero, L_80800300
    if (ctx->r2 != 0) {
        // 0x808002F4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800300;
    }
    // 0x808002F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002F8: b           L_80800350
    // 0x808002FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800350;
    // 0x808002FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800300:
    // 0x80800300: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800304: jal         0x8080110C
    // 0x80800308: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_8080110C_subaddiedialog(rdram, ctx);
        goto after_1;
    // 0x80800308: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080030C: bne         $v0, $zero, L_8080031C
    if (ctx->r2 != 0) {
        // 0x80800310: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080031C;
    }
    // 0x80800310: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800314: b           L_80800350
    // 0x80800318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800350;
    // 0x80800318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080031C:
    // 0x8080031C: jal         0x80016B30
    // 0x80800320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_2;
    // 0x80800320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800324: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800328: beq         $v0, $at, L_80800338
    if (ctx->r2 == ctx->r1) {
        // 0x8080032C: nop
    
            goto L_80800338;
    }
    // 0x8080032C: nop

    // 0x80800330: b           L_80800350
    // 0x80800334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800350;
    // 0x80800334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800338:
    // 0x80800338: jal         0x800F54E4
    // 0x8080033C: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x8080033C: nop

    after_3:
    // 0x80800340: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800344: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800348: jal         0x800F4BB8
    // 0x8080034C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800F4BB8(rdram, ctx);
        goto after_4;
    // 0x8080034C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_4:
L_80800350:
    // 0x80800350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800358: jr          $ra
    // 0x8080035C: nop

    return;
    // 0x8080035C: nop

;}
RECOMP_FUNC void _chchompaslunch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800868E8: syscall     394
    recomp_syscall_handler(rdram, ctx, 0x800868E8);
    return;
    // 0x800868EC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800D78_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D80: jal         0x808002D4
    // 0x80800D84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808002D4_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80800D84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800D90: sb          $zero, 0x15D($a0)
    MEM_B(0X15D, ctx->r4) = 0;
    // 0x80800D94: jal         0x80800AF4
    // 0x80800D98: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    func_80800AF4_bsbansack(rdram, ctx);
        goto after_1;
    // 0x80800D98: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    after_1:
    // 0x80800D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DA4: jr          $ra
    // 0x80800DA8: nop

    return;
    // 0x80800DA8: nop

;}
RECOMP_FUNC void func_808003D4_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003DC: jal         0x80090080
    // 0x808003E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80090080(rdram, ctx);
        goto after_0;
    // 0x808003E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003E4: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x808003E8: beq         $t6, $zero, L_80800404
    if (ctx->r14 == 0) {
        // 0x808003EC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800404;
    }
    // 0x808003EC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808003F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808003F4: jal         0x80016B30
    // 0x808003F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_1;
    // 0x808003F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808003FC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80800400: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
L_80800404:
    // 0x80800404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800408: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080040C: jr          $ra
    // 0x80800410: nop

    return;
    // 0x80800410: nop

;}
RECOMP_FUNC void func_800D731C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D731C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D7320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D7324: jal         0x800D6254
    // 0x800D7328: nop

    func_800D6254(rdram, ctx);
        goto after_0;
    // 0x800D7328: nop

    after_0:
    // 0x800D732C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D7330: beq         $v0, $at, L_800D7378
    if (ctx->r2 == ctx->r1) {
        // 0x800D7334: addiu       $a1, $zero, 0xC
        ctx->r5 = ADD32(0, 0XC);
            goto L_800D7378;
    }
    // 0x800D7334: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x800D7338: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D733C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D7340: addiu       $a0, $a0, -0x4800
    ctx->r4 = ADD32(ctx->r4, -0X4800);
    // 0x800D7344: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D7348: mflo        $t6
    ctx->r14 = lo;
    // 0x800D734C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800D7350: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800D7354: sll         $t9, $t8, 27
    ctx->r25 = S32(ctx->r24 << 27);
    // 0x800D7358: srl         $t0, $t9, 28
    ctx->r8 = S32(U32(ctx->r25) >> 28);
    // 0x800D735C: bnel        $t0, $at, L_800D737C
    if (ctx->r8 != ctx->r1) {
        // 0x800D7360: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D737C;
    }
    goto skip_0;
    // 0x800D7360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800D7364: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D7368: mflo        $t1
    ctx->r9 = lo;
    // 0x800D736C: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x800D7370: b           L_800D737C
    // 0x800D7374: lbu         $v0, 0xB($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0XB);
        goto L_800D737C;
    // 0x800D7374: lbu         $v0, 0xB($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0XB);
L_800D7378:
    // 0x800D7378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D737C:
    // 0x800D737C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D7380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D7384: jr          $ra
    // 0x800D7388: nop

    return;
    // 0x800D7388: nop

;}
RECOMP_FUNC void anctrl_getPlaybackType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B284: jr          $ra
    // 0x8008B288: lbu         $v0, 0x1A($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1A);
    return;
    // 0x8008B288: lbu         $v0, 0x1A($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1A);
;}
RECOMP_FUNC void _chfactorydrums_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087440: syscall     571
    recomp_syscall_handler(rdram, ctx, 0x80087440);
    return;
    // 0x80087444: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800B58_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B58: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800B5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B60: jal         0x80100094
    // 0x80800B64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B68: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800B6C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800B70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800B74: jal         0x800D1218
    // 0x80800B78: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800D1218(rdram, ctx);
        goto after_1;
    // 0x80800B78: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80800B7C: jal         0x80088AF0
    // 0x80800B80: nop

    _fxgenlist_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800B80: nop

    after_2:
    // 0x80800B84: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800B88: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800B8C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800B90: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    // 0x80800B94: jal         0x800BBCB8
    // 0x80800B98: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x80800B98: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800B9C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800BA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800BA4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800BA8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800BAC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800BB0: jal         0x80800BDC
    // 0x80800BB4: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    func_80800BDC_chstonepillar(rdram, ctx);
        goto after_4;
    // 0x80800BB4: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80800BB8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800BBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800BC0: jal         0x800D1254
    // 0x80800BC4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800D1254(rdram, ctx);
        goto after_5;
    // 0x80800BC4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800BC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BCC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800BD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800BD4: jr          $ra
    // 0x80800BD8: nop

    return;
    // 0x80800BD8: nop

;}
RECOMP_FUNC void sucoasterfly_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808021C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808021C8: jal         0x80101870
    // 0x808021CC: nop

    func_80101870(rdram, ctx);
        goto after_0;
    // 0x808021CC: nop

    after_0:
    // 0x808021D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808021D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808021D8: jr          $ra
    // 0x808021DC: nop

    return;
    // 0x808021DC: nop

;}
RECOMP_FUNC void subaddiefade_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002F8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808002FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800300: jal         0x800F0D90
    // 0x80800304: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800F0D90(rdram, ctx);
        goto after_0;
    // 0x80800304: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_0:
    // 0x80800308: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080030C: sb          $v0, 0x9B($t6)
    MEM_B(0X9B, ctx->r14) = ctx->r2;
    // 0x80800310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800318: jr          $ra
    // 0x8080031C: nop

    return;
    // 0x8080031C: nop

;}
RECOMP_FUNC void func_80801E84_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801E88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801E8C: lh          $t6, 0x82($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X82);
    // 0x80801E90: beql        $t6, $zero, L_80801EA4
    if (ctx->r14 == 0) {
        // 0x80801E94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801EA4;
    }
    goto skip_0;
    // 0x80801E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801E98: jal         0x80089848
    // 0x80801E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801EA4:
    // 0x80801EA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801EA8: jr          $ra
    // 0x80801EAC: nop

    return;
    // 0x80801EAC: nop

;}
RECOMP_FUNC void func_800F7150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7150: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7154: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F7158: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F715C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7160: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7164: jal         0x80094510
    // 0x800F7168: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_80094510(rdram, ctx);
        goto after_0;
    // 0x800F7168: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F716C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7170: xori        $t7, $v0, 0x7
    ctx->r15 = ctx->r2 ^ 0X7;
    // 0x800F7174: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800F7178: jr          $ra
    // 0x800F717C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F717C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _chcrate_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086FB0: syscall     486
    recomp_syscall_handler(rdram, ctx, 0x80086FB0);
    return;
    // 0x80086FB4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8001D9AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D9AC: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8001D9B0: slti        $at, $t6, 0x1E
    ctx->r1 = SIGNED(ctx->r14) < 0X1E ? 1 : 0;
    // 0x8001D9B4: beq         $at, $zero, L_8001D9C4
    if (ctx->r1 == 0) {
        // 0x8001D9B8: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_8001D9C4;
    }
    // 0x8001D9B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001D9BC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001D9C0: sw          $t6, -0x27FC($at)
    MEM_W(-0X27FC, ctx->r1) = ctx->r14;
L_8001D9C4:
    // 0x8001D9C4: jr          $ra
    // 0x8001D9C8: nop

    return;
    // 0x8001D9C8: nop

;}
RECOMP_FUNC void func_808009C8_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808009CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808009D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808009D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009D8: jal         0x8008CABC
    // 0x808009DC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808009DC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x808009E0: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x808009E4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808009E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808009EC: beq         $v1, $zero, L_80800A1C
    if (ctx->r3 == 0) {
        // 0x808009F0: nop
    
            goto L_80800A1C;
    }
    // 0x808009F0: nop

    // 0x808009F4: beq         $v1, $at, L_80800A38
    if (ctx->r3 == ctx->r1) {
        // 0x808009F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A38;
    }
    // 0x808009F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A00: beq         $v1, $at, L_80800B4C
    if (ctx->r3 == ctx->r1) {
        // 0x80800A04: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B4C;
    }
    // 0x80800A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A08: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800A0C: beql        $v1, $at, L_80800BC8
    if (ctx->r3 == ctx->r1) {
        // 0x80800A10: sw          $v1, 0x160($s0)
        MEM_W(0X160, ctx->r16) = ctx->r3;
            goto L_80800BC8;
    }
    goto skip_0;
    // 0x80800A10: sw          $v1, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r3;
    skip_0:
    // 0x80800A14: b           L_80800BC8
    // 0x80800A18: sw          $v1, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r3;
        goto L_80800BC8;
    // 0x80800A18: sw          $v1, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r3;
L_80800A1C:
    // 0x80800A1C: jal         0x8009E0DC
    // 0x80800A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E0DC(rdram, ctx);
        goto after_1;
    // 0x80800A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A28: jal         0x80095774
    // 0x80800A2C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    baflag_clear(rdram, ctx);
        goto after_2;
    // 0x80800A2C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_2:
    // 0x80800A30: b           L_80800BC4
    // 0x80800A34: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
        goto L_80800BC4;
    // 0x80800A34: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
L_80800A38:
    // 0x80800A38: addiu       $a1, $zero, 0x29D
    ctx->r5 = ADD32(0, 0X29D);
    // 0x80800A3C: jal         0x8008CCBC
    // 0x80800A40: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_3;
    // 0x80800A40: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x80800A44: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80800A48: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800A58: jal         0x8009FFD8
    // 0x80800A5C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_4;
    // 0x80800A5C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_4:
    // 0x80800A60: lw          $a1, 0x188($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X188);
    // 0x80800A64: lui         $a3, 0x4583
    ctx->r7 = S32(0X4583 << 16);
    // 0x80800A68: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80800A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A70: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800A74: jal         0x80084BD0
    // 0x80800A78: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    _bafly_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800A78: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_5:
    // 0x80800A7C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800A80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A84: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A8C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800A90: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800A94: jal         0x8009C914
    // 0x80800A98: nop

    yaw_setIdeal(rdram, ctx);
        goto after_6;
    // 0x80800A98: nop

    after_6:
    // 0x80800A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA0: jal         0x8009BF5C
    // 0x80800AA4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8009BF5C(rdram, ctx);
        goto after_7;
    // 0x80800AA4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AAC: jal         0x8009C4CC
    // 0x80800AB0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_8;
    // 0x80800AB0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x80800AB4: lw          $a1, 0x188($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X188);
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ABC: jal         0x8009BA9C
    // 0x80800AC0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_8009BA9C(rdram, ctx);
        goto after_9;
    // 0x80800AC0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_9:
    // 0x80800AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC8: jal         0x800A0CF4
    // 0x80800ACC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_10;
    // 0x80800ACC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD4: jal         0x800A4DA4
    // 0x80800AD8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800A4DA4(rdram, ctx);
        goto after_11;
    // 0x80800AD8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x80800ADC: jal         0x800A4CA8
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_12;
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800AE4: lw          $a1, 0x188($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X188);
    // 0x80800AE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800AEC: jal         0x800892B8
    // 0x80800AF0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    _ncbadive_entrypoint_4(rdram, ctx);
        goto after_13;
    // 0x80800AF0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_13:
    // 0x80800AF4: jal         0x800A4CA8
    // 0x80800AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_14;
    // 0x80800AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800AFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B00: jal         0x800892E8
    // 0x80800B04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _ncbafly_entrypoint_5(rdram, ctx);
        goto after_15;
    // 0x80800B04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B0C: addiu       $a1, $zero, 0x442E
    ctx->r5 = ADD32(0, 0X442E);
    // 0x80800B10: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800B14: jal         0x8009DF94
    // 0x80800B18: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    func_8009DF94(rdram, ctx);
        goto after_16;
    // 0x80800B18: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    after_16:
    // 0x80800B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B20: jal         0x80095774
    // 0x80800B24: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    baflag_clear(rdram, ctx);
        goto after_17;
    // 0x80800B24: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_17:
    // 0x80800B28: lw          $a1, 0x188($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X188);
    // 0x80800B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B30: jal         0x8009C128
    // 0x80800B34: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_8009C128(rdram, ctx);
        goto after_18;
    // 0x80800B34: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_18:
    // 0x80800B38: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x80800B3C: jal         0x80085948
    // 0x80800B40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _chusefeather_entrypoint_1(rdram, ctx);
        goto after_19;
    // 0x80800B40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80800B44: b           L_80800BC4
    // 0x80800B48: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
        goto L_80800BC4;
    // 0x80800B48: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
L_80800B4C:
    // 0x80800B4C: jal         0x8009B800
    // 0x80800B50: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    baphysics_set_type(rdram, ctx);
        goto after_20;
    // 0x80800B50: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_20:
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B58: jal         0x800A4DA4
    // 0x80800B5C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800A4DA4(rdram, ctx);
        goto after_21;
    // 0x80800B5C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_21:
    // 0x80800B60: jal         0x800A4CA8
    // 0x80800B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_22;
    // 0x80800B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800B68: lw          $a1, 0x188($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X188);
    // 0x80800B6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B70: jal         0x800892B8
    // 0x80800B74: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    _ncbadive_entrypoint_4(rdram, ctx);
        goto after_23;
    // 0x80800B74: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_23:
    // 0x80800B78: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80800B7C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800B80: jal         0x8008B1BC
    // 0x80800B84: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_setDuration(rdram, ctx);
        goto after_24;
    // 0x80800B84: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_24:
    // 0x80800B88: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x80800B8C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B94: addiu       $a1, $zero, 0x4437
    ctx->r5 = ADD32(0, 0X4437);
    // 0x80800B98: jal         0x8009DF94
    // 0x80800B9C: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DF94(rdram, ctx);
        goto after_25;
    // 0x80800B9C: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_25:
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BA4: jal         0x80095760
    // 0x80800BA8: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    baflag_set(rdram, ctx);
        goto after_26;
    // 0x80800BA8: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_26:
    // 0x80800BAC: lui         $a2, 0x38D1
    ctx->r6 = S32(0X38D1 << 16);
    // 0x80800BB0: ori         $a2, $a2, 0xB717
    ctx->r6 = ctx->r6 | 0XB717;
    // 0x80800BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BB8: jal         0x80085338
    // 0x80800BBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_set(rdram, ctx);
        goto after_27;
    // 0x80800BBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x80800BC0: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
L_80800BC4:
    // 0x80800BC4: sw          $v1, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r3;
L_80800BC8:
    // 0x80800BC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800BCC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800BD0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800BD4: jr          $ra
    // 0x80800BD8: nop

    return;
    // 0x80800BD8: nop

;}
RECOMP_FUNC void func_80801424_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801424: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801428: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080142C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80801430: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801434: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80801438: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8080143C: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x80801440: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801444: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801448: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x8080144C: beql        $a1, $t8, L_80801558
    if (ctx->r5 == ctx->r24) {
        // 0x80801450: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801558;
    }
    goto skip_0;
    // 0x80801450: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80801454: beq         $a1, $at, L_80801484
    if (ctx->r5 == ctx->r1) {
        // 0x80801458: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_80801484;
    }
    // 0x80801458: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x8080145C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801460: beq         $a1, $at, L_80801534
    if (ctx->r5 == ctx->r1) {
        // 0x80801464: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80801534;
    }
    // 0x80801464: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801468: beq         $a1, $at, L_808014D4
    if (ctx->r5 == ctx->r1) {
        // 0x8080146C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_808014D4;
    }
    // 0x8080146C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80801470: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801474: beq         $a1, $at, L_80801528
    if (ctx->r5 == ctx->r1) {
        // 0x80801478: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80801528;
    }
    // 0x80801478: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8080147C: b           L_80801538
    // 0x80801480: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80801538;
    // 0x80801480: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801484:
    // 0x80801484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801488: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x8080148C: lw          $a2, 0x50($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X50);
    // 0x80801490: jal         0x800889D0
    // 0x80801494: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    _fxairbub_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801494: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    after_0:
    // 0x80801498: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(740, 0X1A48) << 16);
    // 0x8080149C: addiu       $t0, $t0, 0x1A48
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(740, 0X1A48));
    // 0x808014A0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808014A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808014A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808014AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808014B0: jal         0x800BABB8
    // 0x808014B4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x808014B4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x808014B8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(740, 0X1A64) << 16);
    // 0x808014BC: addiu       $a2, $a2, 0x1A64
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(740, 0X1A64));
    // 0x808014C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808014C4: jal         0x80089D18
    // 0x808014C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808014C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x808014CC: b           L_80801538
    // 0x808014D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80801538;
    // 0x808014D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808014D4:
    // 0x808014D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014D8: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x808014DC: lw          $a2, 0x50($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X50);
    // 0x808014E0: jal         0x800889D0
    // 0x808014E4: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    _fxairbub_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808014E4: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    after_3:
    // 0x808014E8: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(740, 0X1A48) << 16);
    // 0x808014EC: addiu       $t1, $t1, 0x1A48
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(740, 0X1A48));
    // 0x808014F0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808014F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808014F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808014FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801500: jal         0x800BABB8
    // 0x80801504: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80801504: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x80801508: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(740, 0X1A6C) << 16);
    // 0x8080150C: addiu       $a2, $a2, 0x1A6C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(740, 0X1A6C));
    // 0x80801510: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801514: jal         0x80089D18
    // 0x80801518: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80801518: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x8080151C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80801520: b           L_80801534
    // 0x80801524: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
        goto L_80801534;
    // 0x80801524: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_80801528:
    // 0x80801528: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8080152C: jal         0x80089CA8
    // 0x80801530: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80801530: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
L_80801534:
    // 0x80801534: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801538:
    // 0x80801538: jal         0x80102424
    // 0x8080153C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x8080153C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x80801540: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80801544: beql        $t4, $zero, L_80801558
    if (ctx->r12 == 0) {
        // 0x80801548: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801558;
    }
    goto skip_1;
    // 0x80801548: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8080154C: jal         0x8010A570
    // 0x80801550: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010A570(rdram, ctx);
        goto after_8;
    // 0x80801550: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80801554: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801558:
    // 0x80801558: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080155C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801560: jr          $ra
    // 0x80801564: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801564: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void sumole_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808015D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808015D4: jal         0x80106790
    // 0x808015D8: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808015D8: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808015DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808015E0: jal         0x80086918
    // 0x808015E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _chmolehill_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808015E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808015E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808015EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808015F0: jr          $ra
    // 0x808015F4: nop

    return;
    // 0x808015F4: nop

;}
RECOMP_FUNC void func_8080005C_chlavaentrancebridgeswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800068: jal         0x80085808
    // 0x8080006C: addiu       $a1, $zero, 0x391
    ctx->r5 = ADD32(0, 0X391);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x8080006C: addiu       $a1, $zero, 0x391
    ctx->r5 = ADD32(0, 0X391);
    after_0:
    // 0x80800070: jal         0x80085818
    // 0x80800074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080007C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800080: jr          $ra
    // 0x80800084: nop

    return;
    // 0x80800084: nop

;}
RECOMP_FUNC void func_8002C5C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C5C0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8002C5C4: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8002C5C8: bne         $t6, $t7, L_8002C5E0
    if (ctx->r14 != ctx->r15) {
        // 0x8002C5CC: nop
    
            goto L_8002C5E0;
    }
    // 0x8002C5CC: nop

    // 0x8002C5D0: jr          $ra
    // 0x8002C5D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002C5D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002C5D8: b           L_8002C5E8
    // 0x8002C5DC: nop

        goto L_8002C5E8;
    // 0x8002C5DC: nop

L_8002C5E0:
    // 0x8002C5E0: jr          $ra
    // 0x8002C5E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8002C5E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002C5E8:
    // 0x8002C5E8: jr          $ra
    // 0x8002C5EC: nop

    return;
    // 0x8002C5EC: nop

;}
RECOMP_FUNC void chpodiumbankaz_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2148, 0X500) << 16);
    // 0x808004E0: jr          $ra
    // 0x808004E4: addiu       $v0, $v0, 0x500
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2148, 0X500));
    return;
    // 0x808004E4: addiu       $v0, $v0, 0x500
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2148, 0X500));
;}
RECOMP_FUNC void susplinet_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: beq         $a2, $zero, L_808000C4
    if (ctx->r6 == 0) {
        // 0x8080008C: andi        $t4, $a1, 0x7
        ctx->r12 = ctx->r5 & 0X7;
            goto L_808000C4;
    }
    // 0x8080008C: andi        $t4, $a1, 0x7
    ctx->r12 = ctx->r5 & 0X7;
    // 0x80800090: bgez        $a1, L_808000A0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80800094: sra         $t6, $a1, 3
        ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
            goto L_808000A0;
    }
    // 0x80800094: sra         $t6, $a1, 3
    ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
    // 0x80800098: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x8080009C: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_808000A0:
    // 0x808000A0: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x808000A4: lbu         $t7, 0x50($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X50);
    // 0x808000A8: andi        $t8, $a1, 0x7
    ctx->r24 = ctx->r5 & 0X7;
    // 0x808000AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808000B0: sllv        $t0, $t9, $t8
    ctx->r8 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x808000B4: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x808000B8: sb          $t1, 0x50($v0)
    MEM_B(0X50, ctx->r2) = ctx->r9;
    // 0x808000BC: jr          $ra
    // 0x808000C0: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    return;
    // 0x808000C0: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
L_808000C4:
    // 0x808000C4: bgez        $a1, L_808000D4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x808000C8: sra         $t2, $a1, 3
        ctx->r10 = S32(SIGNED(ctx->r5) >> 3);
            goto L_808000D4;
    }
    // 0x808000C8: sra         $t2, $a1, 3
    ctx->r10 = S32(SIGNED(ctx->r5) >> 3);
    // 0x808000CC: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x808000D0: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_808000D4:
    // 0x808000D4: addu        $v0, $a0, $t2
    ctx->r2 = ADD32(ctx->r4, ctx->r10);
    // 0x808000D8: lbu         $t3, 0x50($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X50);
    // 0x808000DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x808000E0: sllv        $t6, $t5, $t4
    ctx->r14 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x808000E4: nor         $t9, $t6, $zero
    ctx->r25 = ~(ctx->r14 | 0);
    // 0x808000E8: and         $t8, $t3, $t9
    ctx->r24 = ctx->r11 & ctx->r25;
    // 0x808000EC: sb          $t8, 0x50($v0)
    MEM_B(0X50, ctx->r2) = ctx->r24;
    // 0x808000F0: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x808000F4: jr          $ra
    // 0x808000F8: nop

    return;
    // 0x808000F8: nop

;}
RECOMP_FUNC void chstarspinnerplanet_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(952, 0X2A8) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x2A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(952, 0X2A8));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x2A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(952, 0X2A8));
;}
RECOMP_FUNC void _gsmaker_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082588: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x80082588);
    return;
    // 0x8008258C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_8080000C_chfireimp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x80089EC8
    // 0x8080001C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _sucoasterfly_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80800020: beql        $v0, $zero, L_80800040
    if (ctx->r2 == 0) {
        // 0x80800024: lui         $a1, 0x3F26
        ctx->r5 = S32(0X3F26 << 16);
            goto L_80800040;
    }
    goto skip_0;
    // 0x80800024: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    skip_0:
    // 0x80800028: jal         0x80089EE8
    // 0x8080002C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _sucoasterfly_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x8080002C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800030: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1348, 0X140) << 16);
    // 0x80800034: lwc1        $f4, 0x140($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1348, 0X140));
    // 0x80800038: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8080003C: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
L_80800040:
    // 0x80800040: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800044: jal         0x8010A3E8
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A3E8(rdram, ctx);
        goto after_2;
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void func_80800168_chboxingglove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080016C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800170: lbu         $t6, 0x65($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X65);
    // 0x80800174: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800178: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080017C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80800180: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80800184: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800188: sb          $t7, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r15;
    // 0x8080018C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x80800190: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    // 0x80800194: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800198: addiu       $a0, $zero, 0x36E
    ctx->r4 = ADD32(0, 0X36E);
    // 0x8080019C: jal         0x80089C30
    // 0x808001A0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808001A0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x808001A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001A8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x808001AC: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x808001B0: sw          $t8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r24;
    // 0x808001B4: jal         0x80800630
    // 0x808001B8: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
    func_80800630_chboxingglove(rdram, ctx);
        goto after_1;
    // 0x808001B8: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
    after_1:
    // 0x808001BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001C4: jr          $ra
    // 0x808001C8: nop

    return;
    // 0x808001C8: nop

;}
RECOMP_FUNC void func_808002D4_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002E4: jal         0x8009E77C
    // 0x808002E8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x808002E8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_0:
    // 0x808002EC: bne         $v0, $zero, L_80800354
    if (ctx->r2 != 0) {
        // 0x808002F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800354;
    }
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F4: jal         0x800A0CD0
    // 0x808002F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CD0(rdram, ctx);
        goto after_1;
    // 0x808002F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: jal         0x80084538
    // 0x80800304: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _babackpack_set_state(rdram, ctx);
        goto after_2;
    // 0x80800304: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80800308: jal         0x8009EFA8
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_3;
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800310: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x80800314: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080031C: jal         0x8009F1C8
    // 0x80800320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_4;
    // 0x80800320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080032C: jal         0x8009F1C8
    // 0x80800330: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_5;
    // 0x80800330: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800338: lui         $a1, 0xC120
    ctx->r5 = S32(0XC120 << 16);
    // 0x8080033C: jal         0x800A106C
    // 0x80800340: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_800A106C(rdram, ctx);
        goto after_6;
    // 0x80800340: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_6:
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800348: jal         0x8009B9B0
    // 0x8080034C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_7;
    // 0x8080034C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_7:
    // 0x80800350: sb          $zero, 0x15F($s0)
    MEM_B(0X15F, ctx->r16) = 0;
L_80800354:
    // 0x80800354: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800358: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080035C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800360: jr          $ra
    // 0x80800364: nop

    return;
    // 0x80800364: nop

;}
RECOMP_FUNC void func_8001A63C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A63C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001A640: lw          $a0, -0x4318($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4318);
    // 0x8001A644: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001A648: lw          $t6, -0x4310($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4310);
    // 0x8001A64C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001A650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A654: beq         $a0, $zero, L_8001A678
    if (ctx->r4 == 0) {
        // 0x8001A658: sw          $t6, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r14;
            goto L_8001A678;
    }
    // 0x8001A658: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8001A65C: jal         0x8001B084
    // 0x8001A660: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x8001A660: nop

    after_0:
    // 0x8001A664: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001A668: jal         0x8001B084
    // 0x8001A66C: lw          $a0, -0x4314($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4314);
    heap_free(rdram, ctx);
        goto after_1;
    // 0x8001A66C: lw          $a0, -0x4314($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4314);
    after_1:
    // 0x8001A670: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001A674: sw          $zero, -0x4318($at)
    MEM_W(-0X4318, ctx->r1) = 0;
L_8001A678:
    // 0x8001A678: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8001A67C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001A680: beql        $t7, $zero, L_8001A6A8
    if (ctx->r15 == 0) {
        // 0x8001A684: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001A6A8;
    }
    goto skip_0;
    // 0x8001A684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001A688: jal         0x8001B084
    // 0x8001A68C: lw          $a0, -0x4310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4310);
    heap_free(rdram, ctx);
        goto after_2;
    // 0x8001A68C: lw          $a0, -0x4310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4310);
    after_2:
    // 0x8001A690: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001A694: jal         0x8001B084
    // 0x8001A698: lw          $a0, -0x430C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X430C);
    heap_free(rdram, ctx);
        goto after_3;
    // 0x8001A698: lw          $a0, -0x430C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X430C);
    after_3:
    // 0x8001A69C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001A6A0: sw          $zero, -0x4310($at)
    MEM_W(-0X4310, ctx->r1) = 0;
    // 0x8001A6A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001A6A8:
    // 0x8001A6A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001A6AC: jr          $ra
    // 0x8001A6B0: nop

    return;
    // 0x8001A6B0: nop

    // 0x8001A6B4: nop

    // 0x8001A6B8: nop

    // 0x8001A6BC: nop

;}
RECOMP_FUNC void func_800D16C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D16C4: jr          $ra
    // 0x800D16C8: addiu       $v0, $a0, -0x40
    ctx->r2 = ADD32(ctx->r4, -0X40);
    return;
    // 0x800D16C8: addiu       $v0, $a0, -0x40
    ctx->r2 = ADD32(ctx->r4, -0X40);
;}
RECOMP_FUNC void func_80800610_chnewshovel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800610: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800618: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080061C: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x80800620: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80800624: bgez        $t9, L_80800634
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800628: nop
    
            goto L_80800634;
    }
    // 0x80800628: nop

    // 0x8080062C: b           L_808006A0
    // 0x80800630: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006A0;
    // 0x80800630: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800634:
    // 0x80800634: jal         0x8010D290
    // 0x80800638: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    func_8010D290(rdram, ctx);
        goto after_0;
    // 0x80800638: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    after_0:
    // 0x8080063C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800640: bne         $v0, $at, L_80800650
    if (ctx->r2 != ctx->r1) {
        // 0x80800644: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800650;
    }
    // 0x80800644: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800648: b           L_808006A0
    // 0x8080064C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006A0;
    // 0x8080064C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800650:
    // 0x80800650: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800654: jal         0x800F6478
    // 0x80800658: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F6478(rdram, ctx);
        goto after_1;
    // 0x80800658: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8080065C: bne         $v0, $zero, L_8080066C
    if (ctx->r2 != 0) {
        // 0x80800660: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8080066C;
    }
    // 0x80800660: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800664: b           L_808006A0
    // 0x80800668: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006A0;
    // 0x80800668: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080066C:
    // 0x8080066C: jal         0x8010C550
    // 0x80800670: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8010C550(rdram, ctx);
        goto after_2;
    // 0x80800670: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800674: bne         $v0, $zero, L_80800684
    if (ctx->r2 != 0) {
        // 0x80800678: nop
    
            goto L_80800684;
    }
    // 0x80800678: nop

    // 0x8080067C: b           L_808006A0
    // 0x80800680: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006A0;
    // 0x80800680: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800684:
    // 0x80800684: jal         0x80089F00
    // 0x80800688: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _suchase_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800688: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8080068C: bnel        $v0, $zero, L_808006A0
    if (ctx->r2 != 0) {
        // 0x80800690: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808006A0;
    }
    goto skip_0;
    // 0x80800690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800694: b           L_808006A0
    // 0x80800698: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006A0;
    // 0x80800698: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080069C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006A0:
    // 0x808006A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006A8: jr          $ra
    // 0x808006AC: nop

    return;
    // 0x808006AC: nop

;}
RECOMP_FUNC void func_8000062C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000062C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000634: lui         $a2, 0x8001
    ctx->r6 = S32(0X8001 << 16);
    // 0x80000638: jal         0x800006D4
    // 0x8000063C: addiu       $a2, $a2, -0x1800
    ctx->r6 = ADD32(ctx->r6, -0X1800);
    func_800006D4(rdram, ctx);
        goto after_0;
    // 0x8000063C: addiu       $a2, $a2, -0x1800
    ctx->r6 = ADD32(ctx->r6, -0X1800);
    after_0:
    // 0x80000640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000644: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80000648: sw          $v0, 0x64F0($at)
    MEM_W(0X64F0, ctx->r1) = ctx->r2;
    // 0x8000064C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80000650: jr          $ra
    // 0x80000654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80000654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800906B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800906B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800906B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800906B8: jal         0x800F54E4
    // 0x800906BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800906BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800906C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800906C4: jal         0x800F8294
    // 0x800906C8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F8294(rdram, ctx);
        goto after_1;
    // 0x800906C8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800906CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800906D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800906D4: jr          $ra
    // 0x800906D8: nop

    return;
    // 0x800906D8: nop

;}
RECOMP_FUNC void chflysaucerdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1764, 0X160) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x160
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1764, 0X160));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x160
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1764, 0X160));
;}
RECOMP_FUNC void func_80019AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019AA0: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80019AA4: addiu       $t0, $t0, -0x4350
    ctx->r8 = ADD32(ctx->r8, -0X4350);
    // 0x80019AA8: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x80019AAC: addiu       $a2, $a2, 0x40
    ctx->r6 = ADD32(ctx->r6, 0X40);
    // 0x80019AB0: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
    // 0x80019AB4: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x80019AB8: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x80019ABC: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x80019AC0: nop

    // 0x80019AC4: mtc0        $t0, Status
    cop0_status_write(ctx, ctx->r8);    // 0x80019AC8: nop

    // 0x80019ACC: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80019AD0: lwc1        $f1, 0x4($a1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r5, 0X4);
    // 0x80019AD4: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80019AD8: lwc1        $f3, 0x10($a1)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r5, 0X10);
    // 0x80019ADC: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80019AE0: lwc1        $f5, 0x18($a1)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r5, 0X18);
    // 0x80019AE4: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80019AE8: lwc1        $f7, 0x24($a1)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r5, 0X24);
    // 0x80019AEC: lwc1        $f8, 0x28($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X28);
    // 0x80019AF0: lwc1        $f9, 0x30($a1)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r5, 0X30);
    // 0x80019AF4: lwc1        $f10, 0x34($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X34);
    // 0x80019AF8: lwc1        $f11, 0x38($a1)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r5, 0X38);
    // 0x80019AFC: addiu       $t0, $a0, 0xC
    ctx->r8 = ADD32(ctx->r4, 0XC);
L_80019B00:
    // 0x80019B00: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019B04: lwc1        $f13, 0x10($a0)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r4, 0X10);
    // 0x80019B08: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80019B0C: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80019B10: mul.s       $f17, $f1, $f13
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 13);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f13.fl); 
    ctx->f17.fl = MUL_S(ctx->f1.fl, ctx->f13.fl);
    // 0x80019B14: lwc1        $f15, 0x30($a0)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r4, 0X30);
    // 0x80019B18: mul.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80019B1C: add.s       $f17, $f17, $f16
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f17.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f17.fl = ctx->f17.fl + ctx->f16.fl;
    // 0x80019B20: mul.s       $f16, $f3, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f3.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f3.fl, ctx->f12.fl);
    // 0x80019B24: add.s       $f18, $f18, $f17
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 17);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f17.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f17.fl;
    // 0x80019B28: mul.s       $f17, $f4, $f13
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 13);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f13.fl); 
    ctx->f17.fl = MUL_S(ctx->f4.fl, ctx->f13.fl);
    // 0x80019B2C: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    // 0x80019B30: mul.s       $f18, $f5, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 5);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f5.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f5.fl, ctx->f14.fl);
    // 0x80019B34: add.s       $f17, $f17, $f16
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f17.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f17.fl = ctx->f17.fl + ctx->f16.fl;
    // 0x80019B38: mul.s       $f16, $f6, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80019B3C: add.s       $f18, $f18, $f17
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 17);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f17.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f17.fl;
    // 0x80019B40: mul.s       $f17, $f7, $f13
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 7);
    CHECK_FR(ctx, 13);
    NAN_CHECK(ctx->f7.fl); NAN_CHECK(ctx->f13.fl); 
    ctx->f17.fl = MUL_S(ctx->f7.fl, ctx->f13.fl);
    // 0x80019B44: swc1        $f18, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f18.u32l;
    // 0x80019B48: mul.s       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80019B4C: add.s       $f17, $f17, $f16
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f17.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f17.fl = ctx->f17.fl + ctx->f16.fl;
    // 0x80019B50: mul.s       $f16, $f9, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 9);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f9.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f9.fl, ctx->f12.fl);
    // 0x80019B54: add.s       $f18, $f18, $f17
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 17);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f17.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f17.fl;
    // 0x80019B58: mul.s       $f17, $f10, $f13
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 13);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f13.fl); 
    ctx->f17.fl = MUL_S(ctx->f10.fl, ctx->f13.fl);
    // 0x80019B5C: swc1        $f18, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f18.u32l;
    // 0x80019B60: mul.s       $f18, $f11, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 11);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f11.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f11.fl, ctx->f14.fl);
    // 0x80019B64: add.s       $f17, $f17, $f16
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f17.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f17.fl = ctx->f17.fl + ctx->f16.fl;
    // 0x80019B68: add.s       $f18, $f18, $f17
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 17);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f17.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f17.fl;
    // 0x80019B6C: add.s       $f18, $f18, $f15
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 15);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f15.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f15.fl;
    // 0x80019B70: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80019B74: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80019B78: bne         $a0, $t0, L_80019B00
    if (ctx->r4 != ctx->r8) {
        // 0x80019B7C: swc1        $f18, 0x2C($a2)
        MEM_W(0X2C, ctx->r6) = ctx->f18.u32l;
            goto L_80019B00;
    }
    // 0x80019B7C: swc1        $f18, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f18.u32l;
    // 0x80019B80: lui         $t0, 0x3F80
    ctx->r8 = S32(0X3F80 << 16);
    // 0x80019B84: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80019B88: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x80019B8C: sw          $zero, 0x20($a2)
    MEM_W(0X20, ctx->r6) = 0;
    // 0x80019B90: sw          $t0, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r8;
    // 0x80019B94: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x80019B98: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x80019B9C: nor         $t1, $t1, $zero
    ctx->r9 = ~(ctx->r9 | 0);
    // 0x80019BA0: and         $t0, $t0, $t1
    ctx->r8 = ctx->r8 & ctx->r9;
    // 0x80019BA4: nop

    // 0x80019BA8: mtc0        $t0, Status
    cop0_status_write(ctx, ctx->r8);    // 0x80019BAC: nop

    // 0x80019BB0: jr          $ra
    // 0x80019BB4: nop

    return;
    // 0x80019BB4: nop

;}
RECOMP_FUNC void func_8080208C_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080208C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802094: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802098: jal         0x800839E8
    // 0x8080209C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x8080209C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808020A0: beq         $v0, $zero, L_808020B4
    if (ctx->r2 == 0) {
        // 0x808020A4: nop
    
            goto L_808020B4;
    }
    // 0x808020A4: nop

    // 0x808020A8: jal         0x800839B0
    // 0x808020AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsrest_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x808020AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808020B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_808020B4:
    // 0x808020B4: jal         0x80800F94
    // 0x808020B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bstnt_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808020B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808020BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808020C0: jal         0x8009E5C8
    // 0x808020C4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x808020C4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x808020C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808020CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808020D0: jr          $ra
    // 0x808020D4: nop

    return;
    // 0x808020D4: nop

;}
RECOMP_FUNC void ncpod_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D8: jr          $ra
    // 0x808002DC: sh          $a1, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r5;
    return;
    // 0x808002DC: sh          $a1, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void _scinfobar_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A5D0: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A5D0);
    return;
    // 0x8008A5D4: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
