#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800880_bafpctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800888: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x8080088C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800890: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800894: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80800898: beql        $t8, $zero, L_808008C0
    if (ctx->r24 == 0) {
        // 0x8080089C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808008C0;
    }
    goto skip_0;
    // 0x8080089C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808008A0: jal         0x800A4CA8
    // 0x808008A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800A4CA8(rdram, ctx);
        goto after_0;
    // 0x808008A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808008A8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808008AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008B0: lw          $a1, 0x90($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X90);
    // 0x808008B4: jal         0x80089400
    // 0x808008B8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _ncba1p_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x808008B8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x808008BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008C0:
    // 0x808008C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008C4: jr          $ra
    // 0x808008C8: nop

    return;
    // 0x808008C8: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A70: jal         0x8080061C
    // 0x80801A74: nop

    func_8080061C_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80801A74: nop

    after_0:
    // 0x80801A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A80: jr          $ra
    // 0x80801A84: nop

    return;
    // 0x80801A84: nop

;}
RECOMP_FUNC void _gcgamefix_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088450: syscall     683
    recomp_syscall_handler(rdram, ctx, 0x80088450);
    return;
    // 0x80088454: xori        $t0, $zero, 0x4
    ctx->r8 = 0 ^ 0X4;
;}
RECOMP_FUNC void _bskazstill_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083630: syscall     70
    recomp_syscall_handler(rdram, ctx, 0x80083630);
    return;
    // 0x80083634: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void glglobaldata_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80800200: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x80800204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800208:
    // 0x80800208: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080020C: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x80800210: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80800214: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80800218: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080021C: bne         $v0, $a0, L_80800208
    if (ctx->r2 != ctx->r4) {
        // 0x80800220: sb          $zero, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = 0;
            goto L_80800208;
    }
    // 0x80800220: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x80800224: jr          $ra
    // 0x80800228: nop

    return;
    // 0x80800228: nop

    // 0x8080022C: nop

;}
RECOMP_FUNC void func_800D2188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D218C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2190: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D2194: addiu       $a1, $a1, -0x4DA0
    ctx->r5 = ADD32(ctx->r5, -0X4DA0);
    // 0x800D2198: jal         0x8001BBA0
    // 0x800D219C: addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    rare_memcpy(rdram, ctx);
        goto after_0;
    // 0x800D219C: addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    after_0:
    // 0x800D21A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D21A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D21A8: jr          $ra
    // 0x800D21AC: nop

    return;
    // 0x800D21AC: nop

;}
RECOMP_FUNC void func_80110164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110164: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80110168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011016C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80110170: lw          $a2, 0x1C($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X1C);
    // 0x80110174: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    // 0x80110178: jal         0x8011490C
    // 0x8011017C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_8011490C(rdram, ctx);
        goto after_0;
    // 0x8011017C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x80110180: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80110184: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80110188: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x8011018C: jal         0x80114C9C
    // 0x80110190: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    func_80114C9C(rdram, ctx);
        goto after_1;
    // 0x80110190: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    after_1:
    // 0x80110194: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80110198: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8011019C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801101A0: jal         0x800CA6C0
    // 0x801101A4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    func_800CA6C0(rdram, ctx);
        goto after_2;
    // 0x801101A4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    after_2:
    // 0x801101A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801101AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801101B0: jr          $ra
    // 0x801101B4: nop

    return;
    // 0x801101B4: nop

    // 0x801101B8: nop

    // 0x801101BC: nop

;}
RECOMP_FUNC void func_801053D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801053D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801053D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801053DC: jal         0x8010518C
    // 0x801053E0: nop

    func_8010518C(rdram, ctx);
        goto after_0;
    // 0x801053E0: nop

    after_0:
    // 0x801053E4: jal         0x800C84B0
    // 0x801053E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C84B0(rdram, ctx);
        goto after_1;
    // 0x801053E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x801053EC: bne         $v0, $zero, L_801053F8
    if (ctx->r2 != 0) {
        // 0x801053F0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801053F8;
    }
    // 0x801053F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801053F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801053F8:
    // 0x801053F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801053FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105400: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80105404: jr          $ra
    // 0x80105408: nop

    return;
    // 0x80105408: nop

    // 0x8010540C: nop

;}
RECOMP_FUNC void _glglobaldata_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800885C8: syscall     694
    recomp_syscall_handler(rdram, ctx, 0x800885C8);
    return;
    // 0x800885CC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80805404_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805404: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80805408: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080540C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80805410: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80805414: jal         0x80100094
    // 0x80805418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80805418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080541C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80805420: lw          $t6, 0x34($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X34);
    // 0x80805424: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80805428: sltiu       $at, $t7, 0x37
    ctx->r1 = ctx->r15 < 0X37 ? 1 : 0;
    // 0x8080542C: beq         $at, $zero, L_808057FC
    if (ctx->r1 == 0) {
        // 0x80805430: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808057FC;
    }
    // 0x80805430: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80805434: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X68EC) << 16);
    // 0x80805438: addu        $at, $at, $t7
    gpr jr_addend_80805440 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080543C: lw          $t7, 0x68EC($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X68EC));
    // 0x80805440: jr          $t7
    // 0x80805444: nop

    switch (jr_addend_80805440 >> 2) {
        case 0: goto L_80805448; break;
        case 1: goto L_808057FC; break;
        case 2: goto L_808057FC; break;
        case 3: goto L_808057FC; break;
        case 4: goto L_808057FC; break;
        case 5: goto L_808057FC; break;
        case 6: goto L_808057FC; break;
        case 7: goto L_808057FC; break;
        case 8: goto L_808057FC; break;
        case 9: goto L_808057FC; break;
        case 10: goto L_8080546C; break;
        case 11: goto L_8080547C; break;
        case 12: goto L_808054D0; break;
        case 13: goto L_80805534; break;
        case 14: goto L_8080555C; break;
        case 15: goto L_8080555C; break;
        case 16: goto L_80805648; break;
        case 17: goto L_80805648; break;
        case 18: goto L_80805648; break;
        case 19: goto L_80805648; break;
        case 20: goto L_80805648; break;
        case 21: goto L_80805648; break;
        case 22: goto L_80805658; break;
        case 23: goto L_80805658; break;
        case 24: goto L_80805680; break;
        case 25: goto L_80805690; break;
        case 26: goto L_808056A0; break;
        case 27: goto L_808057FC; break;
        case 28: goto L_808056CC; break;
        case 29: goto L_80805774; break;
        case 30: goto L_808057FC; break;
        case 31: goto L_808057FC; break;
        case 32: goto L_808057FC; break;
        case 33: goto L_808057FC; break;
        case 34: goto L_80805794; break;
        case 35: goto L_808057BC; break;
        case 36: goto L_808057FC; break;
        case 37: goto L_808057FC; break;
        case 38: goto L_808057FC; break;
        case 39: goto L_808057FC; break;
        case 40: goto L_808057FC; break;
        case 41: goto L_808057FC; break;
        case 42: goto L_808057FC; break;
        case 43: goto L_808057FC; break;
        case 44: goto L_808057FC; break;
        case 45: goto L_808057FC; break;
        case 46: goto L_808057FC; break;
        case 47: goto L_808057FC; break;
        case 48: goto L_808057FC; break;
        case 49: goto L_808057FC; break;
        case 50: goto L_808057FC; break;
        case 51: goto L_808057FC; break;
        case 52: goto L_808057FC; break;
        case 53: goto L_808057E0; break;
        case 54: goto L_808057FC; break;
        default: switch_error(__func__, 0x80805440, 0x808068EC);
    }
    // 0x80805444: nop

L_80805448:
    // 0x80805448: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X69C8) << 16);
    // 0x8080544C: jal         0x80085728
    // 0x80805450: lwc1        $f12, 0x69C8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X69C8));
    _capod_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x80805450: lwc1        $f12, 0x69C8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X69C8));
    after_1:
    // 0x80805454: beq         $v0, $zero, L_808057FC
    if (ctx->r2 == 0) {
        // 0x80805458: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808057FC;
    }
    // 0x80805458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080545C: jal         0x80804170
    // 0x80805460: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80804170_chquiz(rdram, ctx);
        goto after_2;
    // 0x80805460: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80805464: b           L_808057FC
    // 0x80805468: nop

        goto L_808057FC;
    // 0x80805468: nop

L_8080546C:
    // 0x8080546C: jal         0x80801794
    // 0x80805470: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80801794_chquiz(rdram, ctx);
        goto after_3;
    // 0x80805470: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80805474: b           L_808057FC
    // 0x80805478: nop

        goto L_808057FC;
    // 0x80805478: nop

L_8080547C:
    // 0x8080547C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805480: jal         0x808013E0
    // 0x80805484: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_808013E0_chquiz(rdram, ctx);
        goto after_4;
    // 0x80805484: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80805488: beq         $v0, $zero, L_808054C0
    if (ctx->r2 == 0) {
        // 0x8080548C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808054C0;
    }
    // 0x8080548C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805490: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80805494: jal         0x80800CE8
    // 0x80805498: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_80800CE8_chquiz(rdram, ctx);
        goto after_5;
    // 0x80805498: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x8080549C: jal         0x8008A850
    // 0x808054A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _suquiz_entrypoint_19(rdram, ctx);
        goto after_6;
    // 0x808054A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x808054A4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x808054A8: addiu       $a0, $t8, 0x38
    ctx->r4 = ADD32(ctx->r24, 0X38);
    // 0x808054AC: jal         0x8008A868
    // 0x808054B0: addiu       $a1, $t8, 0x44
    ctx->r5 = ADD32(ctx->r24, 0X44);
    _suquiz_entrypoint_22(rdram, ctx);
        goto after_7;
    // 0x808054B0: addiu       $a1, $t8, 0x44
    ctx->r5 = ADD32(ctx->r24, 0X44);
    after_7:
    // 0x808054B4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808054B8: jal         0x8008A878
    // 0x808054BC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _suquiz_entrypoint_24(rdram, ctx);
        goto after_8;
    // 0x808054BC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_8:
L_808054C0:
    // 0x808054C0: jal         0x80801794
    // 0x808054C4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80801794_chquiz(rdram, ctx);
        goto after_9;
    // 0x808054C4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_9:
    // 0x808054C8: b           L_808057FC
    // 0x808054CC: nop

        goto L_808057FC;
    // 0x808054CC: nop

L_808054D0:
    // 0x808054D0: jal         0x8008A7D8
    // 0x808054D4: nop

    _suquiz_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x808054D4: nop

    after_10:
    // 0x808054D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808054DC: bne         $v0, $at, L_8080550C
    if (ctx->r2 != ctx->r1) {
        // 0x808054E0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080550C;
    }
    // 0x808054E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808054E4: jal         0x80016B54
    // 0x808054E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80016B54(rdram, ctx);
        goto after_11;
    // 0x808054E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x808054EC: beq         $v0, $zero, L_8080550C
    if (ctx->r2 == 0) {
        // 0x808054F0: nop
    
            goto L_8080550C;
    }
    // 0x808054F0: nop

    // 0x808054F4: jal         0x8080171C
    // 0x808054F8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8080171C_chquiz(rdram, ctx);
        goto after_12;
    // 0x808054F8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_12:
    // 0x808054FC: beq         $v0, $zero, L_8080550C
    if (ctx->r2 == 0) {
        // 0x80805500: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080550C;
    }
    // 0x80805500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805504: jal         0x80804170
    // 0x80805508: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_80804170_chquiz(rdram, ctx);
        goto after_13;
    // 0x80805508: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_13:
L_8080550C:
    // 0x8080550C: jal         0x80801600
    // 0x80805510: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80801600_chquiz(rdram, ctx);
        goto after_14;
    // 0x80805510: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_14:
    // 0x80805514: beq         $v0, $zero, L_80805524
    if (ctx->r2 == 0) {
        // 0x80805518: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805524;
    }
    // 0x80805518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080551C: jal         0x80804170
    // 0x80805520: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_80804170_chquiz(rdram, ctx);
        goto after_15;
    // 0x80805520: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_15:
L_80805524:
    // 0x80805524: jal         0x80801794
    // 0x80805528: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80801794_chquiz(rdram, ctx);
        goto after_16;
    // 0x80805528: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_16:
    // 0x8080552C: b           L_808057FC
    // 0x80805530: nop

        goto L_808057FC;
    // 0x80805530: nop

L_80805534:
    // 0x80805534: jal         0x80801600
    // 0x80805538: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80801600_chquiz(rdram, ctx);
        goto after_17;
    // 0x80805538: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_17:
    // 0x8080553C: beq         $v0, $zero, L_8080554C
    if (ctx->r2 == 0) {
        // 0x80805540: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080554C;
    }
    // 0x80805540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805544: jal         0x80804170
    // 0x80805548: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_80804170_chquiz(rdram, ctx);
        goto after_18;
    // 0x80805548: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_18:
L_8080554C:
    // 0x8080554C: jal         0x80801794
    // 0x80805550: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80801794_chquiz(rdram, ctx);
        goto after_19;
    // 0x80805550: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_19:
    // 0x80805554: b           L_808057FC
    // 0x80805558: nop

        goto L_808057FC;
    // 0x80805558: nop

L_8080555C:
    // 0x8080555C: jal         0x8008A7D8
    // 0x80805560: nop

    _suquiz_entrypoint_4(rdram, ctx);
        goto after_20;
    // 0x80805560: nop

    after_20:
    // 0x80805564: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805568: bne         $v0, $at, L_80805590
    if (ctx->r2 != ctx->r1) {
        // 0x8080556C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80805590;
    }
    // 0x8080556C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80805570: jal         0x80016B54
    // 0x80805574: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80016B54(rdram, ctx);
        goto after_21;
    // 0x80805574: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80805578: beq         $v0, $zero, L_80805604
    if (ctx->r2 == 0) {
        // 0x8080557C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805604;
    }
    // 0x8080557C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805580: jal         0x80804170
    // 0x80805584: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_80804170_chquiz(rdram, ctx);
        goto after_22;
    // 0x80805584: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_22:
    // 0x80805588: b           L_80805604
    // 0x8080558C: nop

        goto L_80805604;
    // 0x8080558C: nop

L_80805590:
    // 0x80805590: jal         0x8008A7E8
    // 0x80805594: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_23;
    // 0x80805594: nop

    after_23:
    // 0x80805598: jal         0x8008A810
    // 0x8080559C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _suquiz_entrypoint_11(rdram, ctx);
        goto after_24;
    // 0x8080559C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_24:
    // 0x808055A0: bne         $v0, $zero, L_80805604
    if (ctx->r2 != 0) {
        // 0x808055A4: nop
    
            goto L_80805604;
    }
    // 0x808055A4: nop

    // 0x808055A8: jal         0x800D90A4
    // 0x808055AC: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800D90A4(rdram, ctx);
        goto after_25;
    // 0x808055AC: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_25:
    // 0x808055B0: beq         $v0, $zero, L_80805604
    if (ctx->r2 == 0) {
        // 0x808055B4: nop
    
            goto L_80805604;
    }
    // 0x808055B4: nop

    // 0x808055B8: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x808055BC: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x808055C0: bltz        $t1, L_808055EC
    if (SIGNED(ctx->r9) < 0) {
        // 0x808055C4: nop
    
            goto L_808055EC;
    }
    // 0x808055C4: nop

    // 0x808055C8: jal         0x8008A7E8
    // 0x808055CC: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_26;
    // 0x808055CC: nop

    after_26:
    // 0x808055D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808055D4: jal         0x80800728
    // 0x808055D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800728_chquiz(rdram, ctx);
        goto after_27;
    // 0x808055D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_27:
    // 0x808055DC: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x808055E0: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x808055E4: b           L_80805604
    // 0x808055E8: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
        goto L_80805604;
    // 0x808055E8: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_808055EC:
    // 0x808055EC: jal         0x800D90A4
    // 0x808055F0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    func_800D90A4(rdram, ctx);
        goto after_28;
    // 0x808055F0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    after_28:
    // 0x808055F4: beq         $v0, $zero, L_80805604
    if (ctx->r2 == 0) {
        // 0x808055F8: nop
    
            goto L_80805604;
    }
    // 0x808055F8: nop

    // 0x808055FC: jal         0x8080085C
    // 0x80805600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080085C_chquiz(rdram, ctx);
        goto after_29;
    // 0x80805600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
L_80805604:
    // 0x80805604: jal         0x80801600
    // 0x80805608: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80801600_chquiz(rdram, ctx);
        goto after_30;
    // 0x80805608: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_30:
    // 0x8080560C: beq         $v0, $zero, L_80805638
    if (ctx->r2 == 0) {
        // 0x80805610: nop
    
            goto L_80805638;
    }
    // 0x80805610: nop

    // 0x80805614: lw          $t5, 0x34($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X34);
    // 0x80805618: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8080561C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80805620: bne         $t5, $at, L_80805630
    if (ctx->r13 != ctx->r1) {
        // 0x80805624: nop
    
            goto L_80805630;
    }
    // 0x80805624: nop

    // 0x80805628: b           L_80805630
    // 0x8080562C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
        goto L_80805630;
    // 0x8080562C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_80805630:
    // 0x80805630: jal         0x80804170
    // 0x80805634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804170_chquiz(rdram, ctx);
        goto after_31;
    // 0x80805634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
L_80805638:
    // 0x80805638: jal         0x80801794
    // 0x8080563C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80801794_chquiz(rdram, ctx);
        goto after_32;
    // 0x8080563C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_32:
    // 0x80805640: b           L_808057FC
    // 0x80805644: nop

        goto L_808057FC;
    // 0x80805644: nop

L_80805648:
    // 0x80805648: jal         0x80801794
    // 0x8080564C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80801794_chquiz(rdram, ctx);
        goto after_33;
    // 0x8080564C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_33:
    // 0x80805650: b           L_808057FC
    // 0x80805654: nop

        goto L_808057FC;
    // 0x80805654: nop

L_80805658:
    // 0x80805658: jal         0x80101DDC
    // 0x8080565C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_34;
    // 0x8080565C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80805660: beq         $v0, $zero, L_80805670
    if (ctx->r2 == 0) {
        // 0x80805664: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805670;
    }
    // 0x80805664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805668: jal         0x80804170
    // 0x8080566C: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    func_80804170_chquiz(rdram, ctx);
        goto after_35;
    // 0x8080566C: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_35:
L_80805670:
    // 0x80805670: jal         0x80801794
    // 0x80805674: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80801794_chquiz(rdram, ctx);
        goto after_36;
    // 0x80805674: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_36:
    // 0x80805678: b           L_808057FC
    // 0x8080567C: nop

        goto L_808057FC;
    // 0x8080567C: nop

L_80805680:
    // 0x80805680: jal         0x80801794
    // 0x80805684: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80801794_chquiz(rdram, ctx);
        goto after_37;
    // 0x80805684: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_37:
    // 0x80805688: b           L_808057FC
    // 0x8080568C: nop

        goto L_808057FC;
    // 0x8080568C: nop

L_80805690:
    // 0x80805690: jal         0x80801794
    // 0x80805694: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80801794_chquiz(rdram, ctx);
        goto after_38;
    // 0x80805694: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_38:
    // 0x80805698: b           L_808057FC
    // 0x8080569C: nop

        goto L_808057FC;
    // 0x8080569C: nop

L_808056A0:
    // 0x808056A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808056A4: jal         0x808013E0
    // 0x808056A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_808013E0_chquiz(rdram, ctx);
        goto after_39;
    // 0x808056A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_39:
    // 0x808056AC: beq         $v0, $zero, L_808057FC
    if (ctx->r2 == 0) {
        // 0x808056B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808057FC;
    }
    // 0x808056B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808056B4: jal         0x80804170
    // 0x808056B8: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80804170_chquiz(rdram, ctx);
        goto after_40;
    // 0x808056B8: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_40:
    // 0x808056BC: jal         0x80801794
    // 0x808056C0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80801794_chquiz(rdram, ctx);
        goto after_41;
    // 0x808056C0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_41:
    // 0x808056C4: b           L_808057FC
    // 0x808056C8: nop

        goto L_808057FC;
    // 0x808056C8: nop

L_808056CC:
    // 0x808056CC: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x808056D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808056D4: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x808056D8: beq         $t7, $at, L_808057FC
    if (ctx->r15 == ctx->r1) {
        // 0x808056DC: nop
    
            goto L_808057FC;
    }
    // 0x808056DC: nop

    // 0x808056E0: jal         0x800D90A4
    // 0x808056E4: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800D90A4(rdram, ctx);
        goto after_42;
    // 0x808056E4: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_42:
    // 0x808056E8: beq         $v0, $zero, L_808057FC
    if (ctx->r2 == 0) {
        // 0x808056EC: nop
    
            goto L_808057FC;
    }
    // 0x808056EC: nop

    // 0x808056F0: jal         0x800D395C
    // 0x808056F4: nop

    func_800D395C(rdram, ctx);
        goto after_43;
    // 0x808056F4: nop

    after_43:
    // 0x808056F8: beq         $v0, $zero, L_80805710
    if (ctx->r2 == 0) {
        // 0x808056FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805710;
    }
    // 0x808056FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805700: jal         0x80804170
    // 0x80805704: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_80804170_chquiz(rdram, ctx);
        goto after_44;
    // 0x80805704: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_44:
    // 0x80805708: b           L_808057FC
    // 0x8080570C: nop

        goto L_808057FC;
    // 0x8080570C: nop

L_80805710:
    // 0x80805710: jal         0x8008A7D8
    // 0x80805714: nop

    _suquiz_entrypoint_4(rdram, ctx);
        goto after_45;
    // 0x80805714: nop

    after_45:
    // 0x80805718: beq         $v0, $zero, L_8080573C
    if (ctx->r2 == 0) {
        // 0x8080571C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080573C;
    }
    // 0x8080571C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805720: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80805724: beq         $v0, $at, L_8080574C
    if (ctx->r2 == ctx->r1) {
        // 0x80805728: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080574C;
    }
    // 0x80805728: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080572C: beq         $v0, $at, L_808057FC
    if (ctx->r2 == ctx->r1) {
        // 0x80805730: nop
    
            goto L_808057FC;
    }
    // 0x80805730: nop

    // 0x80805734: b           L_808057FC
    // 0x80805738: nop

        goto L_808057FC;
    // 0x80805738: nop

L_8080573C:
    // 0x8080573C: jal         0x80804170
    // 0x80805740: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80804170_chquiz(rdram, ctx);
        goto after_46;
    // 0x80805740: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_46:
    // 0x80805744: b           L_808057FC
    // 0x80805748: nop

        goto L_808057FC;
    // 0x80805748: nop

L_8080574C:
    // 0x8080574C: jal         0x800DA298
    // 0x80805750: addiu       $a0, $zero, 0x586
    ctx->r4 = ADD32(0, 0X586);
    func_800DA298(rdram, ctx);
        goto after_47;
    // 0x80805750: addiu       $a0, $zero, 0x586
    ctx->r4 = ADD32(0, 0X586);
    after_47:
    // 0x80805754: beq         $v0, $zero, L_80805764
    if (ctx->r2 == 0) {
        // 0x80805758: addiu       $a1, $zero, 0x9
        ctx->r5 = ADD32(0, 0X9);
            goto L_80805764;
    }
    // 0x80805758: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8080575C: b           L_80805764
    // 0x80805760: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
        goto L_80805764;
    // 0x80805760: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
L_80805764:
    // 0x80805764: jal         0x80804170
    // 0x80805768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804170_chquiz(rdram, ctx);
        goto after_48;
    // 0x80805768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x8080576C: b           L_808057FC
    // 0x80805770: nop

        goto L_808057FC;
    // 0x80805770: nop

L_80805774:
    // 0x80805774: jal         0x80101DDC
    // 0x80805778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_49;
    // 0x80805778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x8080577C: beq         $v0, $zero, L_808057FC
    if (ctx->r2 == 0) {
        // 0x80805780: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808057FC;
    }
    // 0x80805780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805784: jal         0x80804170
    // 0x80805788: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    func_80804170_chquiz(rdram, ctx);
        goto after_50;
    // 0x80805788: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_50:
    // 0x8080578C: b           L_808057FC
    // 0x80805790: nop

        goto L_808057FC;
    // 0x80805790: nop

L_80805794:
    // 0x80805794: jal         0x800D90A4
    // 0x80805798: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800D90A4(rdram, ctx);
        goto after_51;
    // 0x80805798: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_51:
    // 0x8080579C: beq         $v0, $zero, L_808057FC
    if (ctx->r2 == 0) {
        // 0x808057A0: nop
    
            goto L_808057FC;
    }
    // 0x808057A0: nop

    // 0x808057A4: jal         0x80801C7C
    // 0x808057A8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80801C7C_chquiz(rdram, ctx);
        goto after_52;
    // 0x808057A8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_52:
    // 0x808057AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X69CC) << 16);
    // 0x808057B0: lwc1        $f4, 0x69CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X69CC));
    // 0x808057B4: b           L_808057FC
    // 0x808057B8: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
        goto L_808057FC;
    // 0x808057B8: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
L_808057BC:
    // 0x808057BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808057C0: jal         0x808013E0
    // 0x808057C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_808013E0_chquiz(rdram, ctx);
        goto after_53;
    // 0x808057C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_53:
    // 0x808057C8: beq         $v0, $zero, L_808057FC
    if (ctx->r2 == 0) {
        // 0x808057CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808057FC;
    }
    // 0x808057CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808057D0: jal         0x80804170
    // 0x808057D4: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    func_80804170_chquiz(rdram, ctx);
        goto after_54;
    // 0x808057D4: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    after_54:
    // 0x808057D8: b           L_808057FC
    // 0x808057DC: nop

        goto L_808057FC;
    // 0x808057DC: nop

L_808057E0:
    // 0x808057E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808057E4: jal         0x808013E0
    // 0x808057E8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_808013E0_chquiz(rdram, ctx);
        goto after_55;
    // 0x808057E8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_55:
    // 0x808057EC: beq         $v0, $zero, L_808057FC
    if (ctx->r2 == 0) {
        // 0x808057F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808057FC;
    }
    // 0x808057F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808057F4: jal         0x80804170
    // 0x808057F8: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    func_80804170_chquiz(rdram, ctx);
        goto after_56;
    // 0x808057F8: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_56:
L_808057FC:
    // 0x808057FC: jal         0x800D3948
    // 0x80805800: nop

    func_800D3948(rdram, ctx);
        goto after_57;
    // 0x80805800: nop

    after_57:
    // 0x80805804: beq         $v0, $zero, L_80805814
    if (ctx->r2 == 0) {
        // 0x80805808: nop
    
            goto L_80805814;
    }
    // 0x80805808: nop

    // 0x8080580C: jal         0x801039E4
    // 0x80805810: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_58;
    // 0x80805810: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_58:
L_80805814:
    // 0x80805814: jal         0x8008A7C0
    // 0x80805818: nop

    _suquiz_entrypoint_1(rdram, ctx);
        goto after_59;
    // 0x80805818: nop

    after_59:
    // 0x8080581C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805820: jal         0x80801170
    // 0x80805824: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80801170_chquiz(rdram, ctx);
        goto after_60;
    // 0x80805824: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_60:
    // 0x80805828: jal         0x80800298
    // 0x8080582C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800298_chquiz(rdram, ctx);
        goto after_61;
    // 0x8080582C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_61:
    // 0x80805830: jal         0x80803BFC
    // 0x80805834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803BFC_chquiz(rdram, ctx);
        goto after_62;
    // 0x80805834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_62:
    // 0x80805838: lw          $t8, 0x70($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X70);
    // 0x8080583C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805840: sll         $t0, $t8, 28
    ctx->r8 = S32(ctx->r24 << 28);
    // 0x80805844: bgezl       $t0, L_80805868
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80805848: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80805868;
    }
    goto skip_0;
    // 0x80805848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080584C: jal         0x80100094
    // 0x80805850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_63;
    // 0x80805850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_63:
    // 0x80805854: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80805858: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8080585C: jal         0x800897D8
    // 0x80805860: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_64;
    // 0x80805860: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_64:
    // 0x80805864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80805868:
    // 0x80805868: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080586C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80805870: jr          $ra
    // 0x80805874: nop

    return;
    // 0x80805874: nop

;}
RECOMP_FUNC void func_80103BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103BBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103BC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103BC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80103BC8: jal         0x801039A4
    // 0x80103BCC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_801039A4(rdram, ctx);
        goto after_0;
    // 0x80103BCC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80103BD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80103BD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80103BD8: jal         0x80103B24
    // 0x80103BDC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80103B24(rdram, ctx);
        goto after_1;
    // 0x80103BDC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_1:
    // 0x80103BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103BE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103BE8: jr          $ra
    // 0x80103BEC: nop

    return;
    // 0x80103BEC: nop

;}
RECOMP_FUNC void func_80801904_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080190C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801910: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801914: jal         0x80100094
    // 0x80801918: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801918: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080191C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801920: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    // 0x80801924: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80801928: bne         $at, $zero, L_80801940
    if (ctx->r1 != 0) {
        // 0x8080192C: slti        $at, $v1, 0x6
        ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
            goto L_80801940;
    }
    // 0x8080192C: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x80801930: beq         $at, $zero, L_80801940
    if (ctx->r1 == 0) {
        // 0x80801934: nop
    
            goto L_80801940;
    }
    // 0x80801934: nop

    // 0x80801938: b           L_80801940
    // 0x8080193C: addiu       $a1, $v0, 0x34
    ctx->r5 = ADD32(ctx->r2, 0X34);
        goto L_80801940;
    // 0x8080193C: addiu       $a1, $v0, 0x34
    ctx->r5 = ADD32(ctx->r2, 0X34);
L_80801940:
    // 0x80801940: jal         0x800EE7F8
    // 0x80801944: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80801944: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80801948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080194C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801950: jr          $ra
    // 0x80801954: nop

    return;
    // 0x80801954: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801808: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080180C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801810: jal         0x8009E6EC
    // 0x80801814: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80801814: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801818: addiu       $t6, $v0, -0x15
    ctx->r14 = ADD32(ctx->r2, -0X15);
    // 0x8080181C: sltiu       $at, $t6, 0x5A
    ctx->r1 = ctx->r14 < 0X5A ? 1 : 0;
    // 0x80801820: beq         $at, $zero, L_80801920
    if (ctx->r1 == 0) {
        // 0x80801824: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801920;
    }
    // 0x80801824: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801828: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080182C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(392, 0X1F4C) << 16);
    // 0x80801830: addu        $at, $at, $t6
    gpr jr_addend_80801838 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801834: lw          $t6, 0x1F4C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(392, 0X1F4C));
    // 0x80801838: jr          $t6
    // 0x8080183C: nop

    switch (jr_addend_80801838 >> 2) {
        case 0: goto L_80801884; break;
        case 1: goto L_80801920; break;
        case 2: goto L_80801920; break;
        case 3: goto L_80801920; break;
        case 4: goto L_80801920; break;
        case 5: goto L_80801920; break;
        case 6: goto L_80801920; break;
        case 7: goto L_80801884; break;
        case 8: goto L_80801884; break;
        case 9: goto L_80801884; break;
        case 10: goto L_80801840; break;
        case 11: goto L_80801840; break;
        case 12: goto L_80801840; break;
        case 13: goto L_80801920; break;
        case 14: goto L_80801920; break;
        case 15: goto L_80801840; break;
        case 16: goto L_80801884; break;
        case 17: goto L_80801920; break;
        case 18: goto L_80801920; break;
        case 19: goto L_80801920; break;
        case 20: goto L_80801920; break;
        case 21: goto L_80801920; break;
        case 22: goto L_80801920; break;
        case 23: goto L_80801920; break;
        case 24: goto L_80801840; break;
        case 25: goto L_80801840; break;
        case 26: goto L_80801920; break;
        case 27: goto L_80801920; break;
        case 28: goto L_80801920; break;
        case 29: goto L_80801920; break;
        case 30: goto L_80801920; break;
        case 31: goto L_80801920; break;
        case 32: goto L_80801920; break;
        case 33: goto L_80801920; break;
        case 34: goto L_80801920; break;
        case 35: goto L_80801920; break;
        case 36: goto L_80801920; break;
        case 37: goto L_80801920; break;
        case 38: goto L_80801920; break;
        case 39: goto L_80801920; break;
        case 40: goto L_80801920; break;
        case 41: goto L_80801920; break;
        case 42: goto L_80801920; break;
        case 43: goto L_80801920; break;
        case 44: goto L_80801920; break;
        case 45: goto L_80801920; break;
        case 46: goto L_80801884; break;
        case 47: goto L_80801920; break;
        case 48: goto L_80801840; break;
        case 49: goto L_80801920; break;
        case 50: goto L_80801920; break;
        case 51: goto L_808018AC; break;
        case 52: goto L_80801920; break;
        case 53: goto L_80801920; break;
        case 54: goto L_80801920; break;
        case 55: goto L_80801920; break;
        case 56: goto L_80801920; break;
        case 57: goto L_80801840; break;
        case 58: goto L_80801920; break;
        case 59: goto L_80801920; break;
        case 60: goto L_80801840; break;
        case 61: goto L_80801840; break;
        case 62: goto L_80801920; break;
        case 63: goto L_80801920; break;
        case 64: goto L_80801920; break;
        case 65: goto L_80801920; break;
        case 66: goto L_80801920; break;
        case 67: goto L_80801920; break;
        case 68: goto L_80801840; break;
        case 69: goto L_80801840; break;
        case 70: goto L_80801840; break;
        case 71: goto L_80801840; break;
        case 72: goto L_80801920; break;
        case 73: goto L_80801920; break;
        case 74: goto L_80801920; break;
        case 75: goto L_80801920; break;
        case 76: goto L_80801920; break;
        case 77: goto L_80801920; break;
        case 78: goto L_80801920; break;
        case 79: goto L_80801920; break;
        case 80: goto L_80801920; break;
        case 81: goto L_80801920; break;
        case 82: goto L_80801920; break;
        case 83: goto L_80801920; break;
        case 84: goto L_80801920; break;
        case 85: goto L_80801920; break;
        case 86: goto L_80801920; break;
        case 87: goto L_80801920; break;
        case 88: goto L_80801920; break;
        case 89: goto L_80801900; break;
        default: switch_error(__func__, 0x80801838, 0x80801F4C);
    }
    // 0x8080183C: nop

L_80801840:
    // 0x80801840: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801844: lwc1        $f6, 0x16C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X16C);
    // 0x80801848: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080184C: nop

    // 0x80801850: bc1fl       L_8080186C
    if (!c1cs) {
        // 0x80801854: lw          $t7, 0x160($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X160);
            goto L_8080186C;
    }
    goto skip_0;
    // 0x80801854: lw          $t7, 0x160($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X160);
    skip_0:
    // 0x80801858: jal         0x808004A8
    // 0x8080185C: nop

    func_808004A8_bstaxi(rdram, ctx);
        goto after_1;
    // 0x8080185C: nop

    after_1:
    // 0x80801860: b           L_8080192C
    // 0x80801864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080192C;
    // 0x80801864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801868: lw          $t7, 0x160($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X160);
L_8080186C:
    // 0x8080186C: bnel        $t7, $zero, L_8080192C
    if (ctx->r15 != 0) {
        // 0x80801870: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080192C;
    }
    goto skip_1;
    // 0x80801870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80801874: jal         0x80099B94
    // 0x80801878: nop

    func_80099B94(rdram, ctx);
        goto after_2;
    // 0x80801878: nop

    after_2:
    // 0x8080187C: b           L_8080192C
    // 0x80801880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080192C;
    // 0x80801880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801884:
    // 0x80801884: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80801888: lwc1        $f10, 0x16C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X16C);
    // 0x8080188C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80801890: nop

    // 0x80801894: bc1fl       L_8080192C
    if (!c1cs) {
        // 0x80801898: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080192C;
    }
    goto skip_2;
    // 0x80801898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8080189C: jal         0x808004A8
    // 0x808018A0: nop

    func_808004A8_bstaxi(rdram, ctx);
        goto after_3;
    // 0x808018A0: nop

    after_3:
    // 0x808018A4: b           L_8080192C
    // 0x808018A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080192C;
    // 0x808018A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808018AC:
    // 0x808018AC: lw          $t8, 0x160($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X160);
    // 0x808018B0: beq         $t8, $zero, L_808018C8
    if (ctx->r24 == 0) {
        // 0x808018B4: nop
    
            goto L_808018C8;
    }
    // 0x808018B4: nop

    // 0x808018B8: jal         0x8009E830
    // 0x808018BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E830(rdram, ctx);
        goto after_4;
    // 0x808018BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808018C0: b           L_8080192C
    // 0x808018C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080192C;
    // 0x808018C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808018C8:
    // 0x808018C8: jal         0x80099A4C
    // 0x808018CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80099A4C(rdram, ctx);
        goto after_5;
    // 0x808018CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_5:
    // 0x808018D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808018D4: jal         0x80099A58
    // 0x808018D8: sw          $v0, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r2;
    func_80099A58(rdram, ctx);
        goto after_6;
    // 0x808018D8: sw          $v0, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r2;
    after_6:
    // 0x808018DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808018E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808018E4: jal         0x80801600
    // 0x808018E8: sb          $v0, 0x164($a0)
    MEM_B(0X164, ctx->r4) = ctx->r2;
    func_80801600_bstaxi(rdram, ctx);
        goto after_7;
    // 0x808018E8: sb          $v0, 0x164($a0)
    MEM_B(0X164, ctx->r4) = ctx->r2;
    after_7:
    // 0x808018EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808018F0: jal         0x8009E830
    // 0x808018F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_8;
    // 0x808018F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x808018F8: b           L_8080192C
    // 0x808018FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080192C;
    // 0x808018FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801900:
    // 0x80801900: jal         0x80099A34
    // 0x80801904: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80099A34(rdram, ctx);
        goto after_9;
    // 0x80801904: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_9:
    // 0x80801908: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080190C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801910: jal         0x8009E830
    // 0x80801914: swc1        $f0, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = ctx->f0.u32l;
    func_8009E830(rdram, ctx);
        goto after_10;
    // 0x80801914: swc1        $f0, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = ctx->f0.u32l;
    after_10:
    // 0x80801918: b           L_8080192C
    // 0x8080191C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080192C;
    // 0x8080191C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801920:
    // 0x80801920: jal         0x80099B94
    // 0x80801924: nop

    func_80099B94(rdram, ctx);
        goto after_11;
    // 0x80801924: nop

    after_11:
    // 0x80801928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080192C:
    // 0x8080192C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801930: jr          $ra
    // 0x80801934: nop

    return;
    // 0x80801934: nop

;}
RECOMP_FUNC void func_800A9F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9F80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A9F84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9F88: jal         0x800DA298
    // 0x800A9F8C: addiu       $a0, $a0, 0xD1B
    ctx->r4 = ADD32(ctx->r4, 0XD1B);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x800A9F8C: addiu       $a0, $a0, 0xD1B
    ctx->r4 = ADD32(ctx->r4, 0XD1B);
    after_0:
    // 0x800A9F90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A9F94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9F98: jr          $ra
    // 0x800A9F9C: nop

    return;
    // 0x800A9F9C: nop

;}
RECOMP_FUNC void func_800DC380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC380: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DC384: addiu       $a0, $a0, -0x3800
    ctx->r4 = ADD32(ctx->r4, -0X3800);
    // 0x800DC388: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC38C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC390: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x800DC394: addiu       $t7, $zero, 0x100
    ctx->r15 = ADD32(0, 0X100);
    // 0x800DC398: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x800DC39C: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x800DC3A0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800DC3A4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800DC3A8: sh          $t8, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r24;
    // 0x800DC3AC: jal         0x80012EDC
    // 0x800DC3B0: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    func_80012EDC(rdram, ctx);
        goto after_0;
    // 0x800DC3B0: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    after_0:
    // 0x800DC3B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DC3B8: addiu       $a0, $a0, -0x3800
    ctx->r4 = ADD32(ctx->r4, -0X3800);
    // 0x800DC3BC: jal         0x8001EB10
    // 0x800DC3C0: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    func_8001EB10(rdram, ctx);
        goto after_1;
    // 0x800DC3C0: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    after_1:
    // 0x800DC3C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC3C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC3CC: jr          $ra
    // 0x800DC3D0: nop

    return;
    // 0x800DC3D0: nop

;}
RECOMP_FUNC void func_80800754_chdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800754: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800758: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080075C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800760: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800764: jal         0x80100094
    // 0x80800768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080076C: lh          $t6, 0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC);
    // 0x80800770: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800774: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800778: beq         $t6, $zero, L_80800788
    if (ctx->r14 == 0) {
        // 0x8080077C: addiu       $a0, $zero, 0x9CC
        ctx->r4 = ADD32(0, 0X9CC);
            goto L_80800788;
    }
    // 0x8080077C: addiu       $a0, $zero, 0x9CC
    ctx->r4 = ADD32(0, 0X9CC);
    // 0x80800780: b           L_80800788
    // 0x80800784: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_80800788;
    // 0x80800784: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80800788:
    // 0x80800788: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8080078C: jal         0x800DA298
    // 0x80800790: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800790: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800794: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800798: beq         $v0, $zero, L_8080088C
    if (ctx->r2 == 0) {
        // 0x8080079C: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_8080088C;
    }
    // 0x8080079C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808007A0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x808007A4: andi        $t7, $v0, 0x4000
    ctx->r15 = ctx->r2 & 0X4000;
    // 0x808007A8: beq         $t7, $zero, L_808007E0
    if (ctx->r15 == 0) {
        // 0x808007AC: andi        $t8, $v0, 0x80
        ctx->r24 = ctx->r2 & 0X80;
            goto L_808007E0;
    }
    // 0x808007AC: andi        $t8, $v0, 0x80
    ctx->r24 = ctx->r2 & 0X80;
    // 0x808007B0: beql        $t8, $zero, L_808007E0
    if (ctx->r24 == 0) {
        // 0x808007B4: addiu       $a1, $zero, 0x7
        ctx->r5 = ADD32(0, 0X7);
            goto L_808007E0;
    }
    goto skip_0;
    // 0x808007B4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    skip_0:
    // 0x808007B8: lhu         $a0, 0x22($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X22);
    // 0x808007BC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x808007C0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x808007C4: andi        $t9, $a0, 0x7FFF
    ctx->r25 = ctx->r4 & 0X7FFF;
    // 0x808007C8: jal         0x800DA298
    // 0x808007CC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808007CC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_2:
    // 0x808007D0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808007D4: bne         $v0, $zero, L_808007E0
    if (ctx->r2 != 0) {
        // 0x808007D8: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_808007E0;
    }
    // 0x808007D8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808007DC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
L_808007E0:
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007E4: jal         0x80800B14
    // 0x808007E8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80800B14_chdoor(rdram, ctx);
        goto after_3;
    // 0x808007E8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x808007EC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808007F0: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x808007F4: srl         $t1, $t0, 26
    ctx->r9 = S32(U32(ctx->r8) >> 26);
    // 0x808007F8: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x808007FC: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x80800800: beq         $at, $zero, L_80800884
    if (ctx->r1 == 0) {
        // 0x80800804: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80800884;
    }
    // 0x80800804: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80800808: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1148, 0X1544) << 16);
    // 0x8080080C: addu        $at, $at, $t2
    gpr jr_addend_80800814 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80800810: lw          $t2, 0x1544($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1148, 0X1544));
    // 0x80800814: jr          $t2
    // 0x80800818: nop

    switch (jr_addend_80800814 >> 2) {
        case 0: goto L_8080081C; break;
        case 1: goto L_80800834; break;
        case 2: goto L_80800848; break;
        case 3: goto L_80800860; break;
        case 4: goto L_80800878; break;
        default: switch_error(__func__, 0x80800814, 0x80801544);
    }
    // 0x80800818: nop

L_8080081C:
    // 0x8080081C: lh          $t3, 0x12($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X12);
    // 0x80800820: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80800824: nop

    // 0x80800828: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080082C: b           L_80800884
    // 0x80800830: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
        goto L_80800884;
    // 0x80800830: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
L_80800834:
    // 0x80800834: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800838: jal         0x800EE88C
    // 0x8080083C: addiu       $a1, $v1, 0x10
    ctx->r5 = ADD32(ctx->r3, 0X10);
    func_800EE88C(rdram, ctx);
        goto after_4;
    // 0x8080083C: addiu       $a1, $v1, 0x10
    ctx->r5 = ADD32(ctx->r3, 0X10);
    after_4:
    // 0x80800840: b           L_80800884
    // 0x80800844: nop

        goto L_80800884;
    // 0x80800844: nop

L_80800848:
    // 0x80800848: lh          $t4, 0x12($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X12);
    // 0x8080084C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80800850: nop

    // 0x80800854: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800858: b           L_80800884
    // 0x8080085C: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
        goto L_80800884;
    // 0x8080085C: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
L_80800860:
    // 0x80800860: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800864: jal         0x800EE88C
    // 0x80800868: addiu       $a1, $v1, 0x10
    ctx->r5 = ADD32(ctx->r3, 0X10);
    func_800EE88C(rdram, ctx);
        goto after_5;
    // 0x80800868: addiu       $a1, $v1, 0x10
    ctx->r5 = ADD32(ctx->r3, 0X10);
    after_5:
    // 0x8080086C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800870: b           L_80800884
    // 0x80800874: swc1        $f16, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f16.u32l;
        goto L_80800884;
    // 0x80800874: swc1        $f16, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f16.u32l;
L_80800878:
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080087C: jal         0x80089C98
    // 0x80800880: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x80800880: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_6:
L_80800884:
    // 0x80800884: jal         0x80103014
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_7;
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_8080088C:
    // 0x8080088C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800890: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800894: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800898: jr          $ra
    // 0x8080089C: nop

    return;
    // 0x8080089C: nop

;}
RECOMP_FUNC void _chtorpedo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800872E8: syscall     548
    recomp_syscall_handler(rdram, ctx, 0x800872E8);
    return;
    // 0x800872EC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800D6254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6254: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D6258: lh          $v0, -0x419E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X419E);
    // 0x800D625C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D6260: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D6264: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800D6268: bltz        $v0, L_800D62D8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800D626C: addiu       $t1, $zero, 0xC
        ctx->r9 = ADD32(0, 0XC);
            goto L_800D62D8;
    }
    // 0x800D626C: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800D6270: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800D6274: addiu       $t0, $t0, -0x4800
    ctx->r8 = ADD32(ctx->r8, -0X4800);
    // 0x800D6278: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
L_800D627C:
    // 0x800D627C: sra         $t6, $a1, 1
    ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800D6280: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6284: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800D6288: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800D628C: mflo        $t7
    ctx->r15 = lo;
    // 0x800D6290: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x800D6294: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    // 0x800D6298: srl         $t9, $a2, 18
    ctx->r25 = S32(U32(ctx->r6) >> 18);
    // 0x800D629C: slt         $at, $t9, $a3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800D62A0: beq         $at, $zero, L_800D62B0
    if (ctx->r1 == 0) {
        // 0x800D62A4: or          $a2, $t9, $zero
        ctx->r6 = ctx->r25 | 0;
            goto L_800D62B0;
    }
    // 0x800D62A4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800D62A8: b           L_800D62CC
    // 0x800D62AC: addiu       $v1, $t6, 0x1
    ctx->r3 = ADD32(ctx->r14, 0X1);
        goto L_800D62CC;
    // 0x800D62AC: addiu       $v1, $t6, 0x1
    ctx->r3 = ADD32(ctx->r14, 0X1);
L_800D62B0:
    // 0x800D62B0: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800D62B4: beq         $at, $zero, L_800D62C4
    if (ctx->r1 == 0) {
        // 0x800D62B8: nop
    
            goto L_800D62C4;
    }
    // 0x800D62B8: nop

    // 0x800D62BC: b           L_800D62CC
    // 0x800D62C0: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
        goto L_800D62CC;
    // 0x800D62C0: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
L_800D62C4:
    // 0x800D62C4: jr          $ra
    // 0x800D62C8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800D62C8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800D62CC:
    // 0x800D62CC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800D62D0: beql        $at, $zero, L_800D627C
    if (ctx->r1 == 0) {
        // 0x800D62D4: addu        $a1, $v0, $v1
        ctx->r5 = ADD32(ctx->r2, ctx->r3);
            goto L_800D627C;
    }
    goto skip_0;
    // 0x800D62D4: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    skip_0:
L_800D62D8:
    // 0x800D62D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800D62DC: jr          $ra
    // 0x800D62E0: nop

    return;
    // 0x800D62E0: nop

;}
RECOMP_FUNC void chfantasybounce_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(820, 0X60) << 16);
    // 0x80800040: jr          $ra
    // 0x80800044: addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(820, 0X60));
    return;
    // 0x80800044: addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(820, 0X60));
;}
RECOMP_FUNC void _bsbabykaz_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800827C8: syscall     14
    recomp_syscall_handler(rdram, ctx, 0x800827C8);
    return;
    // 0x800827CC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801CE4_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801CE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801CEC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80801CF0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801CF4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x80801CF8: jal         0x800F1A88
    // 0x80801CFC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_800F1A88(rdram, ctx);
        goto after_0;
    // 0x80801CFC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80801D00: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80801D04: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80801D08: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80801D0C: swc1        $f6, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f6.u32l;
    // 0x80801D10: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80801D14: swc1        $f8, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->f8.u32l;
    // 0x80801D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801D1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801D20: jr          $ra
    // 0x80801D24: nop

    return;
    // 0x80801D24: nop

;}
RECOMP_FUNC void func_8008E6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E6F0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8008E6F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008E6F8: addiu       $s0, $sp, 0x4C
    ctx->r16 = ADD32(ctx->r29, 0X4C);
    // 0x8008E6FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008E700: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008E704: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8008E708: jal         0x8009C128
    // 0x8008E70C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8008E70C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8008E710: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x8008E714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008E718: jal         0x800EC0EC
    // 0x8008E71C: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_800EC0EC(rdram, ctx);
        goto after_1;
    // 0x8008E71C: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x8008E720: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008E724: jal         0x80095774
    // 0x8008E728: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    baflag_clear(rdram, ctx);
        goto after_2;
    // 0x8008E728: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x8008E72C: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    // 0x8008E730: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008E734: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8008E738: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x8008E73C: sll         $t1, $t9, 22
    ctx->r9 = S32(ctx->r25 << 22);
    // 0x8008E740: bgezl       $t1, L_8008E91C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8008E744: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008E91C;
    }
    goto skip_0;
    // 0x8008E744: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8008E748: jal         0x80091E80
    // 0x8008E74C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80091E80(rdram, ctx);
        goto after_3;
    // 0x8008E74C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x8008E750: beql        $v0, $zero, L_8008E91C
    if (ctx->r2 == 0) {
        // 0x8008E754: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008E91C;
    }
    goto skip_1;
    // 0x8008E754: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8008E758: jal         0x800EA068
    // 0x8008E75C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_800EA068(rdram, ctx);
        goto after_4;
    // 0x8008E75C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_4:
    // 0x8008E760: bne         $v0, $zero, L_8008E7EC
    if (ctx->r2 != 0) {
        // 0x8008E764: nop
    
            goto L_8008E7EC;
    }
    // 0x8008E764: nop

    // 0x8008E768: jal         0x8008DAA8
    // 0x8008E76C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008DAA8(rdram, ctx);
        goto after_5;
    // 0x8008E76C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8008E770: bnel        $v0, $zero, L_8008E834
    if (ctx->r2 != 0) {
        // 0x8008E774: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8008E834;
    }
    goto skip_2;
    // 0x8008E774: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_2:
    // 0x8008E778: jal         0x800F54E4
    // 0x8008E77C: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x8008E77C: nop

    after_6:
    // 0x8008E780: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008E784: jal         0x800F5410
    // 0x8008E788: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_7;
    // 0x8008E788: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x8008E78C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8008E790: beq         $v0, $at, L_8008E830
    if (ctx->r2 == ctx->r1) {
        // 0x8008E794: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8008E830;
    }
    // 0x8008E794: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8008E798: beq         $v0, $at, L_8008E7C0
    if (ctx->r2 == ctx->r1) {
        // 0x8008E79C: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_8008E7C0;
    }
    // 0x8008E79C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8008E7A0: bnel        $v0, $at, L_8008E91C
    if (ctx->r2 != ctx->r1) {
        // 0x8008E7A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008E91C;
    }
    goto skip_3;
    // 0x8008E7A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8008E7A8: jal         0x800F6D24
    // 0x8008E7AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6D24(rdram, ctx);
        goto after_8;
    // 0x8008E7AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8008E7B0: beql        $v0, $zero, L_8008E834
    if (ctx->r2 == 0) {
        // 0x8008E7B4: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8008E834;
    }
    goto skip_4;
    // 0x8008E7B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_4:
    // 0x8008E7B8: b           L_8008E91C
    // 0x8008E7BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008E91C;
    // 0x8008E7BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008E7C0:
    // 0x8008E7C0: jal         0x800F8B88
    // 0x8008E7C4: nop

    func_800F8B88(rdram, ctx);
        goto after_9;
    // 0x8008E7C4: nop

    after_9:
    // 0x8008E7C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008E7CC: bnel        $v0, $at, L_8008E91C
    if (ctx->r2 != ctx->r1) {
        // 0x8008E7D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008E91C;
    }
    goto skip_5;
    // 0x8008E7D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8008E7D4: jal         0x800F6D24
    // 0x8008E7D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6D24(rdram, ctx);
        goto after_10;
    // 0x8008E7D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8008E7DC: beql        $v0, $zero, L_8008E834
    if (ctx->r2 == 0) {
        // 0x8008E7E0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8008E834;
    }
    goto skip_6;
    // 0x8008E7E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_6:
    // 0x8008E7E4: b           L_8008E91C
    // 0x8008E7E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008E91C;
    // 0x8008E7E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008E7EC:
    // 0x8008E7EC: jal         0x800EA068
    // 0x8008E7F0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800EA068(rdram, ctx);
        goto after_11;
    // 0x8008E7F0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_11:
    // 0x8008E7F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008E7F8: jal         0x800EA068
    // 0x8008E7FC: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    func_800EA068(rdram, ctx);
        goto after_12;
    // 0x8008E7FC: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_12:
    // 0x8008E800: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8008E804: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008E808: jal         0x80095738
    // 0x8008E80C: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    baflag_isTrue(rdram, ctx);
        goto after_13;
    // 0x8008E80C: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    after_13:
    // 0x8008E810: beq         $s0, $zero, L_8008E830
    if (ctx->r16 == 0) {
        // 0x8008E814: lw          $t2, 0x3C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X3C);
            goto L_8008E830;
    }
    // 0x8008E814: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8008E818: beql        $t2, $zero, L_8008E834
    if (ctx->r10 == 0) {
        // 0x8008E81C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8008E834;
    }
    goto skip_7;
    // 0x8008E81C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_7:
    // 0x8008E820: beql        $v0, $zero, L_8008E834
    if (ctx->r2 == 0) {
        // 0x8008E824: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8008E834;
    }
    goto skip_8;
    // 0x8008E824: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_8:
    // 0x8008E828: jal         0x800842F8
    // 0x8008E82C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bsfirstp_entrypoint_14(rdram, ctx);
        goto after_14;
    // 0x8008E82C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
L_8008E830:
    // 0x8008E830: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8008E834:
    // 0x8008E834: jal         0x800CB840
    // 0x8008E838: lw          $a1, 0x184($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X184);
    func_800CB840(rdram, ctx);
        goto after_15;
    // 0x8008E838: lw          $a1, 0x184($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X184);
    after_15:
    // 0x8008E83C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008E840: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8008E844:
    // 0x8008E844: jal         0x8009E138
    // 0x8008E848: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8009E138(rdram, ctx);
        goto after_16;
    // 0x8008E848: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
    // 0x8008E84C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008E850: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x8008E854: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E858: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8008E85C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8008E860: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8008E864: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008E868: bc1t        L_8008E8A0
    if (c1cs) {
        // 0x8008E86C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8008E8A0;
    }
    // 0x8008E86C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8008E870: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x8008E874: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x8008E878: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008E87C: addiu       $t5, $t5, 0x6CE0
    ctx->r13 = ADD32(ctx->r13, 0X6CE0);
    // 0x8008E880: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008E884: swc1        $f2, 0x6D08($at)
    MEM_W(0X6D08, ctx->r1) = ctx->f2.u32l;
    // 0x8008E888: jal         0x8009E154
    // 0x8008E88C: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    func_8009E154(rdram, ctx);
        goto after_17;
    // 0x8008E88C: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    after_17:
    // 0x8008E890: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008E894: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008E898: bnel        $s0, $at, L_8008E844
    if (ctx->r16 != ctx->r1) {
        // 0x8008E89C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8008E844;
    }
    goto skip_9;
    // 0x8008E89C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_9:
L_8008E8A0:
    // 0x8008E8A0: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x8008E8A4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008E8A8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008E8AC: addiu       $a2, $a2, 0x6D08
    ctx->r6 = ADD32(ctx->r6, 0X6D08);
    // 0x8008E8B0: addiu       $a1, $a1, 0x6CE0
    ctx->r5 = ADD32(ctx->r5, 0X6CE0);
    // 0x8008E8B4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8008E8B8: jal         0x800CDBA8
    // 0x8008E8BC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800CDBA8(rdram, ctx);
        goto after_18;
    // 0x8008E8BC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_18:
    // 0x8008E8C0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8008E8C4: blez        $v0, L_8008E904
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008E8C8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8008E904;
    }
    // 0x8008E8C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008E8CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8008E8D0:
    // 0x8008E8D0: jal         0x800CDFA8
    // 0x8008E8D4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800CDFA8(rdram, ctx);
        goto after_19;
    // 0x8008E8D4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_19:
    // 0x8008E8D8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8008E8DC: lw          $t8, 0xC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC);
    // 0x8008E8E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008E8E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8008E8E8: jal         0x8008E530
    // 0x8008E8EC: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
    func_8008E530(rdram, ctx);
        goto after_20;
    // 0x8008E8EC: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
    after_20:
    // 0x8008E8F0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8008E8F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008E8F8: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8008E8FC: bnel        $at, $zero, L_8008E8D0
    if (ctx->r1 != 0) {
        // 0x8008E900: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8008E8D0;
    }
    goto skip_10;
    // 0x8008E900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_10:
L_8008E904:
    // 0x8008E904: jal         0x800CB870
    // 0x8008E908: nop

    func_800CB870(rdram, ctx);
        goto after_21;
    // 0x8008E908: nop

    after_21:
    // 0x8008E90C: lw          $t1, 0xC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XC);
    // 0x8008E910: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8008E914: sw          $t0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r8;
    // 0x8008E918: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008E91C:
    // 0x8008E91C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8008E920: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8008E924: jr          $ra
    // 0x8008E928: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8008E928: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void bababykaz_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x80800184: jr          $ra
    // 0x80800188: sb          $a1, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r5;
    return;
    // 0x80800188: sb          $a1, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_800F4CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4CEC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4CF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4CF4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4CF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4CFC: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4D00: jal         0x80091E48
    // 0x800F4D04: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_80091E48(rdram, ctx);
        goto after_0;
    // 0x800F4D04: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F4D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4D0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4D10: jr          $ra
    // 0x800F4D14: nop

    return;
    // 0x800F4D14: nop

;}
RECOMP_FUNC void boot___osSetGlobalIntMask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80021E1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021E1C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80021E20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80021E24: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80021E28: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80021E2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80021E30: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80021E34: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80021E38: addiu       $t7, $zero, 0x3E80
    ctx->r15 = ADD32(0, 0X3E80);
    // 0x80021E3C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80021E40: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80021E44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80021E48: lbu         $s0, 0x4($t8)
    ctx->r16 = MEM_BU(ctx->r24, 0X4);
    // 0x80021E4C: beq         $s0, $at, L_80021E68
    if (ctx->r16 == ctx->r1) {
        // 0x80021E50: nop
    
            goto L_80021E68;
    }
    // 0x80021E50: nop

    // 0x80021E54: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80021E58: beq         $s0, $at, L_80021F6C
    if (ctx->r16 == ctx->r1) {
        // 0x80021E5C: nop
    
            goto L_80021F6C;
    }
    // 0x80021E5C: nop

    // 0x80021E60: b           L_80022034
    // 0x80021E64: nop

        goto L_80022034;
    // 0x80021E64: nop

L_80021E68:
    // 0x80021E68: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80021E6C: lhu         $t0, 0x24($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X24);
    // 0x80021E70: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80021E74: sh          $t1, 0x24($t9)
    MEM_H(0X24, ctx->r25) = ctx->r9;
    // 0x80021E78: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80021E7C: lhu         $t3, 0x24($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X24);
    // 0x80021E80: lhu         $t4, 0x22($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X22);
    // 0x80021E84: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80021E88: bne         $at, $zero, L_80021E98
    if (ctx->r1 != 0) {
        // 0x80021E8C: nop
    
            goto L_80021E98;
    }
    // 0x80021E8C: nop

    // 0x80021E90: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80021E94: sh          $zero, 0x24($t5)
    MEM_H(0X24, ctx->r13) = 0;
L_80021E98:
    // 0x80021E98: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80021E9C: lhu         $t7, 0x24($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X24);
    // 0x80021EA0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80021EA4: bgez        $t7, L_80021EBC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80021EA8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80021EBC;
    }
    // 0x80021EA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80021EAC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80021EB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80021EB4: nop

    // 0x80021EB8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80021EBC:
    // 0x80021EBC: lhu         $t8, 0x22($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X22);
    // 0x80021EC0: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80021EC4: bgez        $t8, L_80021EDC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80021EC8: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80021EDC;
    }
    // 0x80021EC8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80021ECC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80021ED0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80021ED4: nop

    // 0x80021ED8: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80021EDC:
    // 0x80021EDC: div.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80021EE0: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80021EE4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80021EE8: lwc1        $f10, 0x1994($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1994);
    // 0x80021EEC: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80021EF0: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80021EF4: jal         0x8001395C
    // 0x80021EF8: nop

    func_8001395C(rdram, ctx);
        goto after_0;
    // 0x80021EF8: nop

    after_0:
    // 0x80021EFC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80021F00: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80021F04: lbu         $t1, 0x28($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X28);
    // 0x80021F08: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80021F0C: bgez        $t1, L_80021F24
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80021F10: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80021F24;
    }
    // 0x80021F10: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80021F14: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80021F18: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80021F1C: nop

    // 0x80021F20: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_80021F24:
    // 0x80021F24: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80021F28: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80021F2C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80021F30: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80021F34: lbu         $t2, 0x29($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X29);
    // 0x80021F38: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80021F3C: bgez        $t2, L_80021F54
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80021F40: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80021F54;
    }
    // 0x80021F40: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80021F44: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80021F48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80021F4C: nop

    // 0x80021F50: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
L_80021F54:
    // 0x80021F54: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80021F58: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80021F5C: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80021F60: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x80021F64: b           L_8002203C
    // 0x80021F68: nop

        goto L_8002203C;
    // 0x80021F68: nop

L_80021F6C:
    // 0x80021F6C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80021F70: lhu         $t5, 0x24($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X24);
    // 0x80021F74: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80021F78: sh          $t7, 0x24($t4)
    MEM_H(0X24, ctx->r12) = ctx->r15;
    // 0x80021F7C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80021F80: lhu         $t8, 0x24($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X24);
    // 0x80021F84: lhu         $t0, 0x22($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X22);
    // 0x80021F88: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80021F8C: bne         $at, $zero, L_80021F9C
    if (ctx->r1 != 0) {
        // 0x80021F90: nop
    
            goto L_80021F9C;
    }
    // 0x80021F90: nop

    // 0x80021F94: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80021F98: sh          $zero, 0x24($t1)
    MEM_H(0X24, ctx->r9) = 0;
L_80021F9C:
    // 0x80021F9C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80021FA0: lhu         $t2, 0x24($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X24);
    // 0x80021FA4: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80021FA8: bgez        $t2, L_80021FC0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80021FAC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80021FC0;
    }
    // 0x80021FAC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021FB0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80021FB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80021FB8: nop

    // 0x80021FBC: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80021FC0:
    // 0x80021FC0: lhu         $t3, 0x22($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X22);
    // 0x80021FC4: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80021FC8: bgez        $t3, L_80021FE0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80021FCC: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80021FE0;
    }
    // 0x80021FCC: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80021FD0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80021FD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80021FD8: nop

    // 0x80021FDC: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_80021FE0:
    // 0x80021FE0: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80021FE4: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80021FE8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80021FEC: lwc1        $f18, 0x1998($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1998);
    // 0x80021FF0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80021FF4: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80021FF8: jal         0x8001395C
    // 0x80021FFC: nop

    func_8001395C(rdram, ctx);
        goto after_1;
    // 0x80021FFC: nop

    after_1:
    // 0x80022000: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80022004: lwc1        $f4, 0x28($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X28);
    // 0x80022008: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8002200C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80022010: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80022014: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80022018: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8002201C: jal         0x80027170
    // 0x80022020: nop

    func_80027170(rdram, ctx);
        goto after_2;
    // 0x80022020: nop

    after_2:
    // 0x80022024: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80022028: swc1        $f0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f0.u32l;
    // 0x8002202C: b           L_8002203C
    // 0x80022030: nop

        goto L_8002203C;
    // 0x80022030: nop

L_80022034:
    // 0x80022034: b           L_8002203C
    // 0x80022038: nop

        goto L_8002203C;
    // 0x80022038: nop

L_8002203C:
    // 0x8002203C: b           L_8002204C
    // 0x80022040: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_8002204C;
    // 0x80022040: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80022044: b           L_8002204C
    // 0x80022048: nop

        goto L_8002204C;
    // 0x80022048: nop

L_8002204C:
    // 0x8002204C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80022050: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80022054: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80022058: jr          $ra
    // 0x8002205C: nop

    return;
    // 0x8002205C: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_46(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802F14: jr          $ra
    // 0x80802F18: sb          $a1, 0x250($a0)
    MEM_B(0X250, ctx->r4) = ctx->r5;
    return;
    // 0x80802F18: sb          $a1, 0x250($a0)
    MEM_B(0X250, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_80800074_bsbanpackwhack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080007C: jal         0x8009C984
    // 0x80800080: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    yaw_get(rdram, ctx);
        goto after_0;
    // 0x80800080: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800084: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800088: jal         0x80800000
    // 0x8080008C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80800000_bsbanpackwhack(rdram, ctx);
        goto after_1;
    // 0x8080008C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800090: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800094: jal         0x800BA22C
    // 0x80800098: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_2;
    // 0x80800098: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8080009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void func_80800368_chdinofamilysick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800368: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080036C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800370: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800374: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800378: jal         0x800EA05C
    // 0x8080037C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080037C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800380: addiu       $at, $zero, 0x121
    ctx->r1 = ADD32(0, 0X121);
    // 0x80800384: bne         $v0, $at, L_8080039C
    if (ctx->r2 != ctx->r1) {
        // 0x80800388: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080039C;
    }
    // 0x80800388: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080038C: jal         0x808001FC
    // 0x80800390: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_808001FC_chdinofamilysick(rdram, ctx);
        goto after_1;
    // 0x80800390: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800394: b           L_808003A0
    // 0x80800398: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808003A0;
    // 0x80800398: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8080039C:
    // 0x8080039C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003A0:
    // 0x808003A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003A8: jr          $ra
    // 0x808003AC: nop

    return;
    // 0x808003AC: nop

;}
RECOMP_FUNC void chjinjo_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800250: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1672, 0X1302) << 16);
    // 0x80800254: lh          $t6, 0x1302($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(1672, 0X1302));
    // 0x80800258: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1672, 0X1304) << 16);
    // 0x8080025C: addiu       $v1, $v1, 0x1304
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(1672, 0X1304));
    // 0x80800260: bne         $a0, $t6, L_80800274
    if (ctx->r4 != ctx->r14) {
        // 0x80800264: lui         $v0, 0x8080
        ctx->r2 = S32(RELOC_HI16(1672, 0X1324) << 16);
            goto L_80800274;
    }
    // 0x80800264: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1672, 0X1324) << 16);
    // 0x80800268: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1672, 0X1300) << 16);
    // 0x8080026C: jr          $ra
    // 0x80800270: lh          $v0, 0x1300($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1672, 0X1300));
    return;
    // 0x80800270: lh          $v0, 0x1300($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1672, 0X1300));
L_80800274:
    // 0x80800274: addiu       $v0, $v0, 0x1324
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1672, 0X1324));
    // 0x80800278: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
L_8080027C:
    // 0x8080027C: bnel        $a0, $t7, L_80800290
    if (ctx->r4 != ctx->r15) {
        // 0x80800280: lh          $t8, 0x6($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X6);
            goto L_80800290;
    }
    goto skip_0;
    // 0x80800280: lh          $t8, 0x6($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X6);
    skip_0:
    // 0x80800284: jr          $ra
    // 0x80800288: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    return;
    // 0x80800288: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8080028C: lh          $t8, 0x6($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X6);
L_80800290:
    // 0x80800290: bnel        $a0, $t8, L_808002A4
    if (ctx->r4 != ctx->r24) {
        // 0x80800294: lh          $t9, 0xA($v1)
        ctx->r25 = MEM_H(ctx->r3, 0XA);
            goto L_808002A4;
    }
    goto skip_1;
    // 0x80800294: lh          $t9, 0xA($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XA);
    skip_1:
    // 0x80800298: jr          $ra
    // 0x8080029C: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    return;
    // 0x8080029C: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x808002A0: lh          $t9, 0xA($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XA);
L_808002A4:
    // 0x808002A4: bnel        $a0, $t9, L_808002B8
    if (ctx->r4 != ctx->r25) {
        // 0x808002A8: lh          $t0, 0xE($v1)
        ctx->r8 = MEM_H(ctx->r3, 0XE);
            goto L_808002B8;
    }
    goto skip_2;
    // 0x808002A8: lh          $t0, 0xE($v1)
    ctx->r8 = MEM_H(ctx->r3, 0XE);
    skip_2:
    // 0x808002AC: jr          $ra
    // 0x808002B0: lh          $v0, 0x8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X8);
    return;
    // 0x808002B0: lh          $v0, 0x8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X8);
    // 0x808002B4: lh          $t0, 0xE($v1)
    ctx->r8 = MEM_H(ctx->r3, 0XE);
L_808002B8:
    // 0x808002B8: bnel        $a0, $t0, L_808002CC
    if (ctx->r4 != ctx->r8) {
        // 0x808002BC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_808002CC;
    }
    goto skip_3;
    // 0x808002BC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    skip_3:
    // 0x808002C0: jr          $ra
    // 0x808002C4: lh          $v0, 0xC($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XC);
    return;
    // 0x808002C4: lh          $v0, 0xC($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XC);
    // 0x808002C8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_808002CC:
    // 0x808002CC: bnel        $v1, $v0, L_8080027C
    if (ctx->r3 != ctx->r2) {
        // 0x808002D0: lh          $t7, 0x2($v1)
        ctx->r15 = MEM_H(ctx->r3, 0X2);
            goto L_8080027C;
    }
    goto skip_4;
    // 0x808002D0: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    skip_4:
    // 0x808002D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x808002D8: jr          $ra
    // 0x808002DC: nop

    return;
    // 0x808002DC: nop

;}
RECOMP_FUNC void func_8080000C_chfloaty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800010: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800014: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80800018: jr          $ra
    // 0x8080001C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8080001C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80800018_chstarspinnerplanet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080001C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800020: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800028: jal         0x800DA298
    // 0x8080002C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080002C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800030: beq         $v0, $zero, L_808000B0
    if (ctx->r2 == 0) {
        // 0x80800034: nop
    
            goto L_808000B0;
    }
    // 0x80800034: nop

    // 0x80800038: jal         0x800D8FF8
    // 0x8080003C: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8080003C: nop

    after_1:
    // 0x80800040: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800044: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800048: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080004C: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800050: jal         0x800F15F8
    // 0x80800054: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_800F15F8(rdram, ctx);
        goto after_2;
    // 0x80800054: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_2:
    // 0x80800058: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8080005C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800060: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800064: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80800068: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080006C: jal         0x800F15F8
    // 0x80800070: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    func_800F15F8(rdram, ctx);
        goto after_3;
    // 0x80800070: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    after_3:
    // 0x80800074: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80800078: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080007C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800080: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800084: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800088: jal         0x800136E4
    // 0x8080008C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x8080008C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_4:
    // 0x80800090: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80800094: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800098: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080009C: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808000A0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808000A4: jal         0x800136E4
    // 0x808000A8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_5;
    // 0x808000A8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_5:
    // 0x808000AC: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
L_808000B0:
    // 0x808000B0: jal         0x800DA298
    // 0x808000B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x808000B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x808000B8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(952, 0X2F0) << 16);
    // 0x808000BC: addiu       $a3, $a3, 0x2F0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(952, 0X2F0));
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808000C8: jal         0x80089D50
    // 0x808000CC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x808000CC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_7:
    // 0x808000D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000DC: jr          $ra
    // 0x808000E0: nop

    return;
    // 0x808000E0: nop

;}
RECOMP_FUNC void func_80800D84_chdippy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D84: lbu         $t6, 0x65($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X65);
    // 0x80800D88: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80800D8C: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80800D90: sb          $t7, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r15;
    // 0x80800D94: jr          $ra
    // 0x80800D98: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80800D98: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void _bstntswim_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083FF0: syscall     100
    recomp_syscall_handler(rdram, ctx, 0x80083FF0);
    return;
    // 0x80083FF4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800CA5D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA5D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA5DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA5E0: jal         0x800EE84C
    // 0x800CA5E4: nop

    func_800EE84C(rdram, ctx);
        goto after_0;
    // 0x800CA5E4: nop

    after_0:
    // 0x800CA5E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA5EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA5F0: jr          $ra
    // 0x800CA5F4: nop

    return;
    // 0x800CA5F4: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E88: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E88);
    return;
    // 0x80083E8C: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void func_800F89E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F89E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F89E8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800F89EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F89F0: bne         $a0, $at, L_800F8A18
    if (ctx->r4 != ctx->r1) {
        // 0x800F89F4: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800F8A18;
    }
    // 0x800F89F4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800F89F8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800F89FC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800F8A00: jal         0x800EE7F8
    // 0x800F8A04: addiu       $a1, $a1, 0x5500
    ctx->r5 = ADD32(ctx->r5, 0X5500);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800F8A04: addiu       $a1, $a1, 0x5500
    ctx->r5 = ADD32(ctx->r5, 0X5500);
    after_0:
    // 0x800F8A08: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F8A0C: lw          $t6, 0x551C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X551C);
    // 0x800F8A10: b           L_800F8A3C
    // 0x800F8A14: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
        goto L_800F8A3C;
    // 0x800F8A14: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_800F8A18:
    // 0x800F8A18: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800F8A1C: bne         $a0, $at, L_800F8A3C
    if (ctx->r4 != ctx->r1) {
        // 0x800F8A20: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_800F8A3C;
    }
    // 0x800F8A20: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800F8A24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800F8A28: jal         0x800EE7F8
    // 0x800F8A2C: addiu       $a1, $a1, 0x5510
    ctx->r5 = ADD32(ctx->r5, 0X5510);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800F8A2C: addiu       $a1, $a1, 0x5510
    ctx->r5 = ADD32(ctx->r5, 0X5510);
    after_1:
    // 0x800F8A30: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F8A34: lw          $t7, 0x551C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X551C);
    // 0x800F8A38: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_800F8A3C:
    // 0x800F8A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8A40: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800F8A44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F8A48: jr          $ra
    // 0x800F8A4C: nop

    return;
    // 0x800F8A4C: nop

;}
RECOMP_FUNC void func_800E32CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E32CC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800E32D0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E32D4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800E32D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E32DC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800E32E0: addiu       $s0, $s0, -0x2B90
    ctx->r16 = ADD32(ctx->r16, -0X2B90);
    // 0x800E32E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E32E8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800E32EC: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x800E32F0: jal         0x800AF5FC
    // 0x800E32F4: lw          $a0, 0x84($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84);
    func_800AF5FC(rdram, ctx);
        goto after_0;
    // 0x800E32F4: lw          $a0, 0x84($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84);
    after_0:
    // 0x800E32F8: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800E32FC: lh          $t6, 0x1C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1C);
    // 0x800E3300: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x800E3304: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800E3308: beql        $a0, $t6, L_800E3364
    if (ctx->r4 == ctx->r14) {
        // 0x800E330C: lh          $v1, 0x0($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X0);
            goto L_800E3364;
    }
    goto skip_0;
    // 0x800E330C: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    skip_0:
    // 0x800E3310: sh          $a0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r4;
    // 0x800E3314: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800E3318: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800E331C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800E3320: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800E3324: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800E3328: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x800E332C: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x800E3330: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
    // 0x800E3334: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800E3338: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x800E333C: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800E3340: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800E3344: lh          $t4, 0x1C($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1C);
    // 0x800E3348: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
    // 0x800E334C: sll         $t5, $t3, 16
    ctx->r13 = S32(ctx->r11 << 16);
    // 0x800E3350: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800E3354: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x800E3358: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800E335C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800E3360: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800E3364:
    // 0x800E3364: beql        $v1, $zero, L_800E3380
    if (ctx->r3 == 0) {
        // 0x800E3368: lw          $v0, 0x84($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X84);
            goto L_800E3380;
    }
    goto skip_1;
    // 0x800E3368: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    skip_1:
    // 0x800E336C: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    // 0x800E3370: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x800E3374: b           L_800E338C
    // 0x800E3378: lh          $t0, 0x8($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X8);
        goto L_800E338C;
    // 0x800E3378: lh          $t0, 0x8($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X8);
    // 0x800E337C: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
L_800E3380:
    // 0x800E3380: lh          $t0, 0x8($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X8);
    // 0x800E3384: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x800E3388: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
L_800E338C:
    // 0x800E338C: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x800E3390: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800E3394: beq         $a0, $zero, L_800E33A8
    if (ctx->r4 == 0) {
        // 0x800E3398: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800E33A8;
    }
    // 0x800E3398: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800E339C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800E33A0: b           L_800E33B4
    // 0x800E33A4: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
        goto L_800E33B4;
    // 0x800E33A4: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
L_800E33A8:
    // 0x800E33A8: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
    // 0x800E33AC: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800E33B0: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
L_800E33B4:
    // 0x800E33B4: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800E33B8: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800E33BC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800E33C0: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800E33C4: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x800E33C8: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800E33CC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E33D0: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800E33D4: addiu       $t9, $t7, -0x260
    ctx->r25 = ADD32(ctx->r15, -0X260);
    // 0x800E33D8: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800E33DC: addiu       $t8, $zero, 0x1C8
    ctx->r24 = ADD32(0, 0X1C8);
    // 0x800E33E0: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800E33E4: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800E33E8: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800E33EC: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x800E33F0: subu        $t5, $t8, $t3
    ctx->r13 = SUB32(ctx->r24, ctx->r11);
    // 0x800E33F4: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x800E33F8: lui         $a3, 0xC120
    ctx->r7 = S32(0XC120 << 16);
    // 0x800E33FC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E3400: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800E3404: div.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800E3408: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800E340C: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800E3410: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E3414: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800E3418: div.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800E341C: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x800E3420: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E3424: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800E3428: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E342C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800E3430: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800E3434: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x800E3438: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E343C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800E3440: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E3444: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800E3448: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800E344C: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800E3450: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800E3454: jal         0x800EFA4C
    // 0x800E3458: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x800E3458: nop

    after_1:
    // 0x800E345C: jal         0x80019CD4
    // 0x800E3460: nop

    func_80019CD4(rdram, ctx);
        goto after_2;
    // 0x800E3460: nop

    after_2:
    // 0x800E3464: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800E3468: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800E346C: jal         0x800191F8
    // 0x800E3470: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    func_800191F8(rdram, ctx);
        goto after_3;
    // 0x800E3470: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    after_3:
    // 0x800E3474: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800E3478: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800E347C: nop

    // 0x800E3480: c.eq.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl == ctx->f12.fl;
    // 0x800E3484: nop

    // 0x800E3488: bc1tl       L_800E349C
    if (c1cs) {
        // 0x800E348C: lw          $v0, 0x84($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X84);
            goto L_800E349C;
    }
    goto skip_2;
    // 0x800E348C: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    skip_2:
    // 0x800E3490: jal         0x8001907C
    // 0x800E3494: nop

    mlMtxRotRoll(rdram, ctx);
        goto after_4;
    // 0x800E3494: nop

    after_4:
    // 0x800E3498: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
L_800E349C:
    // 0x800E349C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800E34A0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800E34A4: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800E34A8: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800E34AC: bnel        $t6, $v1, L_800E34F4
    if (ctx->r14 != ctx->r3) {
        // 0x800E34B0: lh          $t8, 0x8($v0)
        ctx->r24 = MEM_H(ctx->r2, 0X8);
            goto L_800E34F4;
    }
    goto skip_3;
    // 0x800E34B0: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    skip_3:
    // 0x800E34B4: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x800E34B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E34BC: bnel        $t7, $t9, L_800E34F4
    if (ctx->r15 != ctx->r25) {
        // 0x800E34C0: lh          $t8, 0x8($v0)
        ctx->r24 = MEM_H(ctx->r2, 0X8);
            goto L_800E34F4;
    }
    goto skip_4;
    // 0x800E34C0: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    skip_4:
    // 0x800E34C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E34C8: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800E34CC: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x800E34D0: nop

    // 0x800E34D4: bc1fl       L_800E34F4
    if (!c1cs) {
        // 0x800E34D8: lh          $t8, 0x8($v0)
        ctx->r24 = MEM_H(ctx->r2, 0X8);
            goto L_800E34F4;
    }
    goto skip_5;
    // 0x800E34D8: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    skip_5:
    // 0x800E34DC: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800E34E0: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x800E34E4: nop

    // 0x800E34E8: bc1t        L_800E3544
    if (c1cs) {
        // 0x800E34EC: nop
    
            goto L_800E3544;
    }
    // 0x800E34EC: nop

    // 0x800E34F0: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
L_800E34F4:
    // 0x800E34F4: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800E34F8: lh          $t3, 0xA($v0)
    ctx->r11 = MEM_H(ctx->r2, 0XA);
    // 0x800E34FC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800E3500: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E3504: lh          $t5, 0x6($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X6);
    // 0x800E3508: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E350C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E3510: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800E3514: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800E3518: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800E351C: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800E3520: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800E3524: nop

    // 0x800E3528: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E352C: div.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800E3530: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800E3534: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800E3538: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E353C: jal         0x80019D30
    // 0x800E3540: div.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    mlMtxScale_xyz(rdram, ctx);
        goto after_5;
    // 0x800E3540: div.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    after_5:
L_800E3544:
    // 0x800E3544: jal         0x80018C28
    // 0x800E3548: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    mlMtxApply(rdram, ctx);
        goto after_6;
    // 0x800E3548: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    after_6:
    // 0x800E354C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800E3550: lui         $t6, 0xDA38
    ctx->r14 = S32(0XDA38 << 16);
    // 0x800E3554: ori         $t6, $t6, 0x2
    ctx->r14 = ctx->r14 | 0X2;
    // 0x800E3558: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800E355C: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x800E3560: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800E3564: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x800E3568: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800E356C: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x800E3570: addiu       $t8, $t9, 0x40
    ctx->r24 = ADD32(ctx->r25, 0X40);
    // 0x800E3574: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x800E3578: jal         0x800AF5F0
    // 0x800E357C: lw          $a0, 0x84($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84);
    func_800AF5F0(rdram, ctx);
        goto after_7;
    // 0x800E357C: lw          $a0, 0x84($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84);
    after_7:
    // 0x800E3580: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800E3584: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800E3588: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800E358C: lh          $t5, 0x4($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X4);
    // 0x800E3590: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800E3594: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800E3598: sll         $t4, $t5, 3
    ctx->r12 = S32(ctx->r13 << 3);
    // 0x800E359C: addu        $a0, $v0, $t4
    ctx->r4 = ADD32(ctx->r2, ctx->r12);
    // 0x800E35A0: jal         0x8002E330
    // 0x800E35A4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_8;
    // 0x800E35A4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    after_8:
    // 0x800E35A8: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800E35AC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800E35B0: lui         $t8, 0xD838
    ctx->r24 = S32(0XD838 << 16);
    // 0x800E35B4: ori         $t8, $t8, 0x2
    ctx->r24 = ctx->r24 | 0X2;
    // 0x800E35B8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800E35BC: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800E35C0: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x800E35C4: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800E35C8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800E35CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E35D0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E35D4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E35D8: jr          $ra
    // 0x800E35DC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800E35DC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80800018_chweldarbossdoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080001C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800024: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800028: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8080002C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800030: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800034: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80800038: bne         $t7, $at, L_80800050
    if (ctx->r15 != ctx->r1) {
        // 0x8080003C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800050;
    }
    // 0x8080003C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800040: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800044: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800048: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080004C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
L_80800050:
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800054: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800058: jal         0x80089D00
    // 0x8080005C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    _subaddiefade_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x8080005C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80800060: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800064: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800068: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080006C: lui         $a3, 0x443B
    ctx->r7 = S32(0X443B << 16);
    // 0x80800070: addiu       $t8, $zero, 0x102
    ctx->r24 = ADD32(0, 0X102);
    // 0x80800074: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800078: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8080007C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800080: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800084: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800088: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800090: jal         0x80086898
    // 0x80800094: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800094: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_1:
    // 0x80800098: beq         $v0, $zero, L_808000CC
    if (ctx->r2 == 0) {
        // 0x8080009C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000CC;
    }
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A0: jal         0x800868A8
    // 0x808000A4: lui         $a1, 0x4108
    ctx->r5 = S32(0X4108 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x808000A4: lui         $a1, 0x4108
    ctx->r5 = S32(0X4108 << 16);
    after_2:
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: jal         0x800868B0
    // 0x808000B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x808000B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x808000B4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: beql        $t0, $zero, L_808000D0
    if (ctx->r8 == 0) {
        // 0x808000C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000D0;
    }
    goto skip_0;
    // 0x808000C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000C4: jal         0x800868C0
    // 0x808000C8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x808000C8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
L_808000CC:
    // 0x808000CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000D0:
    // 0x808000D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000D8: jr          $ra
    // 0x808000DC: nop

    return;
    // 0x808000DC: nop

;}
RECOMP_FUNC void func_800CB598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB59C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB5A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CB5A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CB5A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CB5AC: jal         0x800CB698
    // 0x800CB5B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800CB698(rdram, ctx);
        goto after_0;
    // 0x800CB5B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x800CB5B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800CB5B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB5BC: jal         0x800CB534
    // 0x800CB5C0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_800CB534(rdram, ctx);
        goto after_1;
    // 0x800CB5C0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800CB5C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB5C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB5CC: jr          $ra
    // 0x800CB5D0: nop

    return;
    // 0x800CB5D0: nop

;}
RECOMP_FUNC void func_800FC9B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC9B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FC9B8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800FC9BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800FC9C0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800FC9C4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800FC9C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FC9CC: beq         $a0, $zero, L_800FC9F8
    if (ctx->r4 == 0) {
        // 0x800FC9D0: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FC9F8;
    }
    // 0x800FC9D0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FC9D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FC9D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FC9DC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800FC9E0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800FC9E4: addiu       $s2, $s2, 0x59B8
    ctx->r18 = ADD32(ctx->r18, 0X59B8);
    // 0x800FC9E8: addiu       $s1, $s1, 0x59B4
    ctx->r17 = ADD32(ctx->r17, 0X59B4);
    // 0x800FC9EC: swc1        $f12, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f12.u32l;
    // 0x800FC9F0: b           L_800FCA1C
    // 0x800FC9F4: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
        goto L_800FCA1C;
    // 0x800FC9F4: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
L_800FC9F8:
    // 0x800FC9F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FC9FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800FCA00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FCA04: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800FCA08: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800FCA0C: addiu       $s2, $s2, 0x59B8
    ctx->r18 = ADD32(ctx->r18, 0X59B8);
    // 0x800FCA10: addiu       $s1, $s1, 0x59B4
    ctx->r17 = ADD32(ctx->r17, 0X59B4);
    // 0x800FCA14: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x800FCA18: swc1        $f8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f8.u32l;
L_800FCA1C:
    // 0x800FCA1C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FCA20: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800FCA24: addiu       $s3, $s3, 0x5960
    ctx->r19 = ADD32(ctx->r19, 0X5960);
    // 0x800FCA28: addiu       $s0, $s0, 0x57D0
    ctx->r16 = ADD32(ctx->r16, 0X57D0);
    // 0x800FCA2C: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
L_800FCA30:
    // 0x800FCA30: bltzl       $a0, L_800FCA6C
    if (SIGNED(ctx->r4) < 0) {
        // 0x800FCA34: addiu       $s0, $s0, 0x50
        ctx->r16 = ADD32(ctx->r16, 0X50);
            goto L_800FCA6C;
    }
    goto skip_0;
    // 0x800FCA34: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    skip_0:
    // 0x800FCA38: jal         0x800FE7A8
    // 0x800FCA3C: nop

    func_800FE7A8(rdram, ctx);
        goto after_0;
    // 0x800FCA3C: nop

    after_0:
    // 0x800FCA40: bnel        $v0, $zero, L_800FCA6C
    if (ctx->r2 != 0) {
        // 0x800FCA44: addiu       $s0, $s0, 0x50
        ctx->r16 = ADD32(ctx->r16, 0X50);
            goto L_800FCA6C;
    }
    goto skip_1;
    // 0x800FCA44: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    skip_1:
    // 0x800FCA48: lbu         $t6, 0x30($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X30);
    // 0x800FCA4C: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x800FCA50: bnel        $t7, $zero, L_800FCA6C
    if (ctx->r15 != 0) {
        // 0x800FCA54: addiu       $s0, $s0, 0x50
        ctx->r16 = ADD32(ctx->r16, 0X50);
            goto L_800FCA6C;
    }
    goto skip_2;
    // 0x800FCA54: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    skip_2:
    // 0x800FCA58: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800FCA5C: lwc1        $f16, 0x0($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800FCA60: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x800FCA64: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x800FCA68: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
L_800FCA6C:
    // 0x800FCA6C: bnel        $s0, $s3, L_800FCA30
    if (ctx->r16 != ctx->r19) {
        // 0x800FCA70: lh          $a0, 0x28($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X28);
            goto L_800FCA30;
    }
    goto skip_3;
    // 0x800FCA70: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
    skip_3:
    // 0x800FCA74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800FCA78: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FCA7C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FCA80: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800FCA84: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800FCA88: jr          $ra
    // 0x800FCA8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800FCA8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bashoes_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: lw          $t6, 0x10C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10C);
    // 0x80800018: jr          $ra
    // 0x8080001C: lbu         $v0, 0x10($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X10);
    return;
    // 0x8080001C: lbu         $v0, 0x10($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X10);
;}
RECOMP_FUNC void func_800A0DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0DB8: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800A0DBC: jr          $ra
    // 0x800A0DC0: sb          $a1, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r5;
    return;
    // 0x800A0DC0: sb          $a1, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_80803000_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803008: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080300C: jal         0x80100094
    // 0x80803010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803014: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80803018: lh          $t6, 0x46($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X46);
    // 0x8080301C: bne         $t6, $zero, L_80803044
    if (ctx->r14 != 0) {
        // 0x80803020: nop
    
            goto L_80803044;
    }
    // 0x80803020: nop

    // 0x80803024: jal         0x800F54E4
    // 0x80803028: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80803028: nop

    after_1:
    // 0x8080302C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803030: jal         0x800F4AF4
    // 0x80803034: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_800F4AF4(rdram, ctx);
        goto after_2;
    // 0x80803034: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_2:
    // 0x80803038: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8080303C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80803040: sh          $t7, 0x46($t8)
    MEM_H(0X46, ctx->r24) = ctx->r15;
L_80803044:
    // 0x80803044: jal         0x808030A4
    // 0x80803048: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808030A4_chklungo(rdram, ctx);
        goto after_3;
    // 0x80803048: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8080304C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803050: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803054: jr          $ra
    // 0x80803058: nop

    return;
    // 0x80803058: nop

;}
RECOMP_FUNC void func_80801224_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801224: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080122C: jal         0x800845D0
    // 0x80801230: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801230: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801234: jal         0x808000F0
    // 0x80801238: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsvan_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801238: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080123C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801244: jr          $ra
    // 0x80801248: nop

    return;
    // 0x80801248: nop

;}
RECOMP_FUNC void _bsdronebitten_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083010: syscall     39
    recomp_syscall_handler(rdram, ctx, 0x80083010);
    return;
    // 0x80083014: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801210_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801210: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80801214: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080121C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80801220: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x80801224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801228: bc1tl       L_80801244
    if (c1cs) {
        // 0x8080122C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801244;
    }
    goto skip_0;
    // 0x8080122C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801230: div.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80801234: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80801238: jal         0x800EF334
    // 0x8080123C: nop

    func_800EF334(rdram, ctx);
        goto after_0;
    // 0x8080123C: nop

    after_0:
    // 0x80801240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801244:
    // 0x80801244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801248: jr          $ra
    // 0x8080124C: nop

    return;
    // 0x8080124C: nop

;}
RECOMP_FUNC void func_800EEDE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EEDE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EEDEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EEDF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800EEDF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800EEDF8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800EEDFC: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EEE00: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EEE04: jal         0x800F2100
    // 0x800EEE08: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    mlAbsF(rdram, ctx);
        goto after_0;
    // 0x800EEE08: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_0:
    // 0x800EEE0C: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EEE10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EEE14: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800EEE18: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800EEE1C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800EEE20: bc1f        L_800EEE2C
    if (!c1cs) {
        // 0x800EEE24: nop
    
            goto L_800EEE2C;
    }
    // 0x800EEE24: nop

    // 0x800EEE28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EEE2C:
    // 0x800EEE2C: beql        $v0, $zero, L_800EEE9C
    if (ctx->r2 == 0) {
        // 0x800EEE30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EEE9C;
    }
    goto skip_0;
    // 0x800EEE30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800EEE34: lwc1        $f10, 0x4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800EEE38: lwc1        $f16, 0x4($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X4);
    // 0x800EEE3C: jal         0x800F2100
    // 0x800EEE40: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x800EEE40: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    after_1:
    // 0x800EEE44: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EEE48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EEE4C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800EEE50: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800EEE54: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800EEE58: bc1f        L_800EEE64
    if (!c1cs) {
        // 0x800EEE5C: nop
    
            goto L_800EEE64;
    }
    // 0x800EEE5C: nop

    // 0x800EEE60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EEE64:
    // 0x800EEE64: beql        $v0, $zero, L_800EEE9C
    if (ctx->r2 == 0) {
        // 0x800EEE68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EEE9C;
    }
    goto skip_1;
    // 0x800EEE68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800EEE6C: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800EEE70: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800EEE74: jal         0x800F2100
    // 0x800EEE78: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    mlAbsF(rdram, ctx);
        goto after_2;
    // 0x800EEE78: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_2:
    // 0x800EEE7C: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EEE80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EEE84: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800EEE88: nop

    // 0x800EEE8C: bc1fl       L_800EEE9C
    if (!c1cs) {
        // 0x800EEE90: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EEE9C;
    }
    goto skip_2;
    // 0x800EEE90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800EEE94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EEE98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EEE9C:
    // 0x800EEE9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EEEA0: jr          $ra
    // 0x800EEEA4: nop

    return;
    // 0x800EEEA4: nop

;}
RECOMP_FUNC void _bsthrow_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F00: syscall     97
    recomp_syscall_handler(rdram, ctx, 0x80083F00);
    return;
    // 0x80083F04: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800C8BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8BF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8BF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8BFC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8C00: jal         0x800B2928
    // 0x800C8C04: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    vector_size(rdram, ctx);
        goto after_0;
    // 0x800C8C04: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    after_0:
    // 0x800C8C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8C10: jr          $ra
    // 0x800C8C14: nop

    return;
    // 0x800C8C14: nop

;}
