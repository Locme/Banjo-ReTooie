#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800458_basub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800458: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080045C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800460: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800464: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800468: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080046C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800470: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800474: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800478: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080047C: addiu       $s3, $zero, 0x28
    ctx->r19 = ADD32(0, 0X28);
    // 0x80800480: lw          $t6, 0x130($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X130);
L_80800484:
    // 0x80800484: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800488: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8080048C: lw          $a0, 0x2C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X2C);
    // 0x80800490: beql        $a0, $zero, L_808004A4
    if (ctx->r4 == 0) {
        // 0x80800494: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808004A4;
    }
    goto skip_0;
    // 0x80800494: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80800498: jal         0x8010114C
    // 0x8080049C: lw          $a2, 0x184($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X184);
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x8080049C: lw          $a2, 0x184($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X184);
    after_0:
    // 0x808004A0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_808004A4:
    // 0x808004A4: bnel        $s0, $s3, L_80800484
    if (ctx->r16 != ctx->r19) {
        // 0x808004A8: lw          $t6, 0x130($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X130);
            goto L_80800484;
    }
    goto skip_1;
    // 0x808004A8: lw          $t6, 0x130($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X130);
    skip_1:
    // 0x808004AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808004B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808004B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808004B8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808004BC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808004C0: jr          $ra
    // 0x808004C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808004C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E18: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087E18);
    return;
    // 0x80087E1C: addi        $t0, $zero, 0xC0
    ctx->r8 = ADD32(0, 0XC0);
;}
RECOMP_FUNC void func_80800F60_chkingjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F60: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800F64: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800F68: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80800F6C: jr          $ra
    // 0x80800F70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800F70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_808010CC_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808010D8: jal         0x800DA298
    // 0x808010DC: addiu       $a0, $zero, 0x9D9
    ctx->r4 = ADD32(0, 0X9D9);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808010DC: addiu       $a0, $zero, 0x9D9
    ctx->r4 = ADD32(0, 0X9D9);
    after_0:
    // 0x808010E0: bnel        $v0, $zero, L_80801120
    if (ctx->r2 != 0) {
        // 0x808010E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801120;
    }
    goto skip_0;
    // 0x808010E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808010E8: jal         0x800EA05C
    // 0x808010EC: nop

    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x808010EC: nop

    after_1:
    // 0x808010F0: addiu       $at, $zero, 0xB9
    ctx->r1 = ADD32(0, 0XB9);
    // 0x808010F4: beql        $v0, $at, L_80801120
    if (ctx->r2 == ctx->r1) {
        // 0x808010F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801120;
    }
    goto skip_1;
    // 0x808010F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808010FC: jal         0x800F54E4
    // 0x80801100: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80801100: nop

    after_2:
    // 0x80801104: jal         0x800F6CC8
    // 0x80801108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6CC8(rdram, ctx);
        goto after_3;
    // 0x80801108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8080110C: bne         $v0, $zero, L_8080111C
    if (ctx->r2 != 0) {
        // 0x80801110: addiu       $a0, $zero, 0xB9
        ctx->r4 = ADD32(0, 0XB9);
            goto L_8080111C;
    }
    // 0x80801110: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    // 0x80801114: jal         0x800887D8
    // 0x80801118: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80801118: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_4:
L_8080111C:
    // 0x8080111C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801120:
    // 0x80801120: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801124: jr          $ra
    // 0x80801128: nop

    return;
    // 0x80801128: nop

;}
RECOMP_FUNC void func_800B2784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2784: lw          $v1, 0x3C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3C);
    // 0x800B2788: bne         $v1, $zero, L_800B2798
    if (ctx->r3 != 0) {
        // 0x800B278C: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_800B2798;
    }
    // 0x800B278C: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x800B2790: jr          $ra
    // 0x800B2794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B2794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B2798:
    // 0x800B2798: jr          $ra
    // 0x800B279C: nop

    return;
    // 0x800B279C: nop

;}
RECOMP_FUNC void func_8080005C_chintrocam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800068: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x8080006C: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x80800070: sltiu       $at, $t7, 0xAD
    ctx->r1 = ctx->r15 < 0XAD ? 1 : 0;
    // 0x80800074: bne         $at, $zero, L_808000A0
    if (ctx->r1 != 0) {
        // 0x80800078: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_808000A0;
    }
    // 0x80800078: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8080007C: addiu       $t8, $t7, -0x17E
    ctx->r24 = ADD32(ctx->r15, -0X17E);
    // 0x80800080: sltiu       $at, $t8, 0x1C
    ctx->r1 = ctx->r24 < 0X1C ? 1 : 0;
    // 0x80800084: beq         $at, $zero, L_808008DC
    if (ctx->r1 == 0) {
        // 0x80800088: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808008DC;
    }
    // 0x80800088: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080008C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X910) << 16);
    // 0x80800090: addu        $at, $at, $t8
    gpr jr_addend_80800098 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800094: lw          $t8, 0x910($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1736, 0X910));
    // 0x80800098: jr          $t8
    // 0x8080009C: nop

    switch (jr_addend_80800098 >> 2) {
        case 0: goto L_808008DC; break;
        case 1: goto L_808008DC; break;
        case 2: goto L_808008DC; break;
        case 3: goto L_808008DC; break;
        case 4: goto L_808008DC; break;
        case 5: goto L_808008DC; break;
        case 6: goto L_808008DC; break;
        case 7: goto L_808008DC; break;
        case 8: goto L_808008DC; break;
        case 9: goto L_808008DC; break;
        case 10: goto L_808008DC; break;
        case 11: goto L_808008DC; break;
        case 12: goto L_808008DC; break;
        case 13: goto L_808008DC; break;
        case 14: goto L_808004A8; break;
        case 15: goto L_808008DC; break;
        case 16: goto L_80800478; break;
        case 17: goto L_8080058C; break;
        case 18: goto L_808005E0; break;
        case 19: goto L_808008DC; break;
        case 20: goto L_808008DC; break;
        case 21: goto L_8080085C; break;
        case 22: goto L_80800610; break;
        case 23: goto L_808007A0; break;
        case 24: goto L_808008B4; break;
        case 25: goto L_808006CC; break;
        case 26: goto L_80800748; break;
        case 27: goto L_808008DC; break;
        default: switch_error(__func__, 0x80800098, 0x80800910);
    }
    // 0x8080009C: nop

L_808000A0:
    // 0x808000A0: addiu       $t9, $v0, -0xA1
    ctx->r25 = ADD32(ctx->r2, -0XA1);
    // 0x808000A4: sltiu       $at, $t9, 0xC
    ctx->r1 = ctx->r25 < 0XC ? 1 : 0;
    // 0x808000A8: beq         $at, $zero, L_808008DC
    if (ctx->r1 == 0) {
        // 0x808000AC: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808008DC;
    }
    // 0x808000AC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808000B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X980) << 16);
    // 0x808000B4: addu        $at, $at, $t9
    gpr jr_addend_808000BC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808000B8: lw          $t9, 0x980($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1736, 0X980));
    // 0x808000BC: jr          $t9
    // 0x808000C0: nop

    switch (jr_addend_808000BC >> 2) {
        case 0: goto L_808000C4; break;
        case 1: goto L_808000F4; break;
        case 2: goto L_8080014C; break;
        case 3: goto L_808001F0; break;
        case 4: goto L_8080028C; break;
        case 5: goto L_808002E0; break;
        case 6: goto L_808008DC; break;
        case 7: goto L_808008DC; break;
        case 8: goto L_80800380; break;
        case 9: goto L_808008DC; break;
        case 10: goto L_808008DC; break;
        case 11: goto L_808003B0; break;
        default: switch_error(__func__, 0x808000BC, 0x80800980);
    }
    // 0x808000C0: nop

L_808000C4:
    // 0x808000C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000C8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000CC: jal         0x80085728
    // 0x808000D0: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_0;
    // 0x808000D0: nop

    after_0:
    // 0x808000D4: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x808000D8: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x808000D8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x808000DC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x808000E0: addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // 0x808000E4: jal         0x80088F98
    // 0x808000E8: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808000E8: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_1:
    // 0x808000EC: b           L_808008E0
    // 0x808000F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x808000F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000F4:
    // 0x808000F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000F8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000FC: jal         0x80085728
    // 0x80800100: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_2;
    // 0x80800100: nop

    after_2:
    // 0x80800104: beq         $v0, $zero, L_8080011C
    if (ctx->r2 == 0) {
        // 0x80800108: lw          $t1, 0x18($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X18);
            goto L_8080011C;
    }
    // 0x80800108: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8080010C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80800110: addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // 0x80800114: jal         0x80088F98
    // 0x80800118: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800118: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_3:
L_8080011C:
    // 0x8080011C: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x80800120: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800124: jal         0x80085728
    // 0x80800128: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_4;
    // 0x80800128: nop

    after_4:
    // 0x8080012C: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x80800130: lw          $t2, 0x18($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x80800130: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80800134: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80800138: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x8080013C: jal         0x80088F98
    // 0x80800140: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800140: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_5:
    // 0x80800144: b           L_808008E0
    // 0x80800148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x80800148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080014C:
    // 0x8080014C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800150: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800154: jal         0x80085728
    // 0x80800158: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_6;
    // 0x80800158: nop

    after_6:
    // 0x8080015C: beq         $v0, $zero, L_80800174
    if (ctx->r2 == 0) {
        // 0x80800160: lw          $t3, 0x18($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X18);
            goto L_80800174;
    }
    // 0x80800160: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80800164: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80800168: addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // 0x8080016C: jal         0x80088F98
    // 0x80800170: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80800170: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_7:
L_80800174:
    // 0x80800174: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800178: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080017C: jal         0x80085728
    // 0x80800180: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_8;
    // 0x80800180: nop

    after_8:
    // 0x80800184: beq         $v0, $zero, L_8080019C
    if (ctx->r2 == 0) {
        // 0x80800188: lw          $t4, 0x18($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X18);
            goto L_8080019C;
    }
    // 0x80800188: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8080018C: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80800190: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    // 0x80800194: jal         0x80088F98
    // 0x80800198: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x80800198: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_9:
L_8080019C:
    // 0x8080019C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9B0) << 16);
    // 0x808001A0: jal         0x80085728
    // 0x808001A4: lwc1        $f12, 0x9B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9B0));
    _capod_entrypoint_17(rdram, ctx);
        goto after_10;
    // 0x808001A4: lwc1        $f12, 0x9B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9B0));
    after_10:
    // 0x808001A8: beq         $v0, $zero, L_808001C0
    if (ctx->r2 == 0) {
        // 0x808001AC: lw          $t5, 0x18($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X18);
            goto L_808001C0;
    }
    // 0x808001AC: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x808001B0: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x808001B4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x808001B8: jal         0x80088F98
    // 0x808001BC: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x808001BC: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_11:
L_808001C0:
    // 0x808001C0: lui         $at, 0x452F
    ctx->r1 = S32(0X452F << 16);
    // 0x808001C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001C8: jal         0x80085728
    // 0x808001CC: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_12;
    // 0x808001CC: nop

    after_12:
    // 0x808001D0: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x808001D4: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x808001D4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808001D8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x808001DC: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x808001E0: jal         0x80088F98
    // 0x808001E4: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_13;
    // 0x808001E4: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_13:
    // 0x808001E8: b           L_808008E0
    // 0x808001EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x808001EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001F0:
    // 0x808001F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001F8: jal         0x80085728
    // 0x808001FC: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_14;
    // 0x808001FC: nop

    after_14:
    // 0x80800200: beq         $v0, $zero, L_80800218
    if (ctx->r2 == 0) {
        // 0x80800204: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80800218;
    }
    // 0x80800204: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800208: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8080020C: addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // 0x80800210: jal         0x80088F98
    // 0x80800214: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_15;
    // 0x80800214: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_15:
L_80800218:
    // 0x80800218: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9B4) << 16);
    // 0x8080021C: jal         0x80085728
    // 0x80800220: lwc1        $f12, 0x9B4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9B4));
    _capod_entrypoint_17(rdram, ctx);
        goto after_16;
    // 0x80800220: lwc1        $f12, 0x9B4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9B4));
    after_16:
    // 0x80800224: beq         $v0, $zero, L_8080023C
    if (ctx->r2 == 0) {
        // 0x80800228: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_8080023C;
    }
    // 0x80800228: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8080022C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80800230: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    // 0x80800234: jal         0x80088F98
    // 0x80800238: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x80800238: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_17:
L_8080023C:
    // 0x8080023C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9B8) << 16);
    // 0x80800240: jal         0x80085728
    // 0x80800244: lwc1        $f12, 0x9B8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9B8));
    _capod_entrypoint_17(rdram, ctx);
        goto after_18;
    // 0x80800244: lwc1        $f12, 0x9B8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9B8));
    after_18:
    // 0x80800248: beq         $v0, $zero, L_80800260
    if (ctx->r2 == 0) {
        // 0x8080024C: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_80800260;
    }
    // 0x8080024C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800250: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80800254: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    // 0x80800258: jal         0x80088F98
    // 0x8080025C: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_19;
    // 0x8080025C: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_19:
L_80800260:
    // 0x80800260: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9BC) << 16);
    // 0x80800264: jal         0x80085728
    // 0x80800268: lwc1        $f12, 0x9BC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9BC));
    _capod_entrypoint_17(rdram, ctx);
        goto after_20;
    // 0x80800268: lwc1        $f12, 0x9BC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9BC));
    after_20:
    // 0x8080026C: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x80800270: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x80800270: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80800274: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80800278: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x8080027C: jal         0x80088F98
    // 0x80800280: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_21;
    // 0x80800280: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_21:
    // 0x80800284: b           L_808008E0
    // 0x80800288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x80800288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080028C:
    // 0x8080028C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800290: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800294: jal         0x80085728
    // 0x80800298: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_22;
    // 0x80800298: nop

    after_22:
    // 0x8080029C: beq         $v0, $zero, L_808002B4
    if (ctx->r2 == 0) {
        // 0x808002A0: lw          $t1, 0x18($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X18);
            goto L_808002B4;
    }
    // 0x808002A0: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x808002A4: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x808002A8: addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // 0x808002AC: jal         0x80088F98
    // 0x808002B0: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_23;
    // 0x808002B0: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_23:
L_808002B4:
    // 0x808002B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9C0) << 16);
    // 0x808002B8: jal         0x80085728
    // 0x808002BC: lwc1        $f12, 0x9C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9C0));
    _capod_entrypoint_17(rdram, ctx);
        goto after_24;
    // 0x808002BC: lwc1        $f12, 0x9C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9C0));
    after_24:
    // 0x808002C0: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x808002C4: lw          $t2, 0x18($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x808002C4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x808002C8: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x808002CC: addiu       $a1, $zero, 0x56
    ctx->r5 = ADD32(0, 0X56);
    // 0x808002D0: jal         0x80088F98
    // 0x808002D4: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_25;
    // 0x808002D4: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_25:
    // 0x808002D8: b           L_808008E0
    // 0x808002DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x808002DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002E0:
    // 0x808002E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808002E8: jal         0x80085728
    // 0x808002EC: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_26;
    // 0x808002EC: nop

    after_26:
    // 0x808002F0: beq         $v0, $zero, L_80800308
    if (ctx->r2 == 0) {
        // 0x808002F4: lw          $t3, 0x18($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X18);
            goto L_80800308;
    }
    // 0x808002F4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x808002F8: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x808002FC: addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // 0x80800300: jal         0x80088F98
    // 0x80800304: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_27;
    // 0x80800304: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_27:
L_80800308:
    // 0x80800308: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9C4) << 16);
    // 0x8080030C: jal         0x80085728
    // 0x80800310: lwc1        $f12, 0x9C4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9C4));
    _capod_entrypoint_17(rdram, ctx);
        goto after_28;
    // 0x80800310: lwc1        $f12, 0x9C4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9C4));
    after_28:
    // 0x80800314: beq         $v0, $zero, L_8080032C
    if (ctx->r2 == 0) {
        // 0x80800318: lw          $t4, 0x18($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X18);
            goto L_8080032C;
    }
    // 0x80800318: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8080031C: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80800320: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    // 0x80800324: jal         0x80088F98
    // 0x80800328: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_29;
    // 0x80800328: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_29:
L_8080032C:
    // 0x8080032C: lui         $at, 0x4548
    ctx->r1 = S32(0X4548 << 16);
    // 0x80800330: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800334: jal         0x80085728
    // 0x80800338: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_30;
    // 0x80800338: nop

    after_30:
    // 0x8080033C: beq         $v0, $zero, L_80800354
    if (ctx->r2 == 0) {
        // 0x80800340: lw          $t5, 0x18($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X18);
            goto L_80800354;
    }
    // 0x80800340: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80800344: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80800348: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x8080034C: jal         0x80088F98
    // 0x80800350: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_31;
    // 0x80800350: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_31:
L_80800354:
    // 0x80800354: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9C8) << 16);
    // 0x80800358: jal         0x80085728
    // 0x8080035C: lwc1        $f12, 0x9C8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9C8));
    _capod_entrypoint_17(rdram, ctx);
        goto after_32;
    // 0x8080035C: lwc1        $f12, 0x9C8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9C8));
    after_32:
    // 0x80800360: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x80800364: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x80800364: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800368: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8080036C: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x80800370: jal         0x80088F98
    // 0x80800374: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_33;
    // 0x80800374: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_33:
    // 0x80800378: b           L_808008E0
    // 0x8080037C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x8080037C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800380:
    // 0x80800380: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800384: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800388: jal         0x80085728
    // 0x8080038C: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_34;
    // 0x8080038C: nop

    after_34:
    // 0x80800390: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x80800394: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x80800394: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800398: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8080039C: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    // 0x808003A0: jal         0x80088F98
    // 0x808003A4: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_35;
    // 0x808003A4: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_35:
    // 0x808003A8: b           L_808008E0
    // 0x808003AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x808003AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003B0:
    // 0x808003B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9CC) << 16);
    // 0x808003B4: jal         0x80085728
    // 0x808003B8: lwc1        $f12, 0x9CC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9CC));
    _capod_entrypoint_17(rdram, ctx);
        goto after_36;
    // 0x808003B8: lwc1        $f12, 0x9CC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9CC));
    after_36:
    // 0x808003BC: beq         $v0, $zero, L_808003D4
    if (ctx->r2 == 0) {
        // 0x808003C0: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_808003D4;
    }
    // 0x808003C0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808003C4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x808003C8: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    // 0x808003CC: jal         0x80088F98
    // 0x808003D0: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_37;
    // 0x808003D0: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_37:
L_808003D4:
    // 0x808003D4: lui         $at, 0x4525
    ctx->r1 = S32(0X4525 << 16);
    // 0x808003D8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808003DC: jal         0x80085728
    // 0x808003E0: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_38;
    // 0x808003E0: nop

    after_38:
    // 0x808003E4: beq         $v0, $zero, L_808003FC
    if (ctx->r2 == 0) {
        // 0x808003E8: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_808003FC;
    }
    // 0x808003E8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x808003EC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x808003F0: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x808003F4: jal         0x80088F98
    // 0x808003F8: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_39;
    // 0x808003F8: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_39:
L_808003FC:
    // 0x808003FC: lui         $at, 0x4525
    ctx->r1 = S32(0X4525 << 16);
    // 0x80800400: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800404: jal         0x80085728
    // 0x80800408: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_40;
    // 0x80800408: nop

    after_40:
    // 0x8080040C: beq         $v0, $zero, L_80800424
    if (ctx->r2 == 0) {
        // 0x80800410: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_80800424;
    }
    // 0x80800410: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80800414: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80800418: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x8080041C: jal         0x80088F98
    // 0x80800420: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_41;
    // 0x80800420: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_41:
L_80800424:
    // 0x80800424: lui         $at, 0x4525
    ctx->r1 = S32(0X4525 << 16);
    // 0x80800428: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080042C: jal         0x80085728
    // 0x80800430: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_42;
    // 0x80800430: nop

    after_42:
    // 0x80800434: beq         $v0, $zero, L_8080044C
    if (ctx->r2 == 0) {
        // 0x80800438: lw          $t1, 0x18($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X18);
            goto L_8080044C;
    }
    // 0x80800438: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8080043C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80800440: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    // 0x80800444: jal         0x80088F98
    // 0x80800448: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_43;
    // 0x80800448: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_43:
L_8080044C:
    // 0x8080044C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9D0) << 16);
    // 0x80800450: jal         0x80085728
    // 0x80800454: lwc1        $f12, 0x9D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9D0));
    _capod_entrypoint_17(rdram, ctx);
        goto after_44;
    // 0x80800454: lwc1        $f12, 0x9D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9D0));
    after_44:
    // 0x80800458: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x8080045C: lw          $t2, 0x18($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x8080045C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80800460: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80800464: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    // 0x80800468: jal         0x80088F98
    // 0x8080046C: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_45;
    // 0x8080046C: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_45:
    // 0x80800470: b           L_808008E0
    // 0x80800474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x80800474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800478:
    // 0x80800478: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8080047C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800480: jal         0x80085728
    // 0x80800484: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_46;
    // 0x80800484: nop

    after_46:
    // 0x80800488: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x8080048C: lw          $t3, 0x18($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x8080048C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80800490: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80800494: addiu       $a1, $zero, 0x6B
    ctx->r5 = ADD32(0, 0X6B);
    // 0x80800498: jal         0x80088F98
    // 0x8080049C: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_47;
    // 0x8080049C: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_47:
    // 0x808004A0: b           L_808008E0
    // 0x808004A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x808004A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004A8:
    // 0x808004A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808004AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808004B0: jal         0x80085728
    // 0x808004B4: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_48;
    // 0x808004B4: nop

    after_48:
    // 0x808004B8: beq         $v0, $zero, L_808004D0
    if (ctx->r2 == 0) {
        // 0x808004BC: lw          $t4, 0x18($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X18);
            goto L_808004D0;
    }
    // 0x808004BC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x808004C0: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x808004C4: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    // 0x808004C8: jal         0x80088F98
    // 0x808004CC: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_49;
    // 0x808004CC: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_49:
L_808004D0:
    // 0x808004D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9D4) << 16);
    // 0x808004D4: jal         0x80085728
    // 0x808004D8: lwc1        $f12, 0x9D4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9D4));
    _capod_entrypoint_17(rdram, ctx);
        goto after_50;
    // 0x808004D8: lwc1        $f12, 0x9D4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9D4));
    after_50:
    // 0x808004DC: beq         $v0, $zero, L_808004F4
    if (ctx->r2 == 0) {
        // 0x808004E0: lw          $t5, 0x18($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X18);
            goto L_808004F4;
    }
    // 0x808004E0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x808004E4: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x808004E8: addiu       $a1, $zero, 0x6D
    ctx->r5 = ADD32(0, 0X6D);
    // 0x808004EC: jal         0x80088F98
    // 0x808004F0: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_51;
    // 0x808004F0: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_51:
L_808004F4:
    // 0x808004F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9D8) << 16);
    // 0x808004F8: jal         0x80085728
    // 0x808004FC: lwc1        $f12, 0x9D8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9D8));
    _capod_entrypoint_17(rdram, ctx);
        goto after_52;
    // 0x808004FC: lwc1        $f12, 0x9D8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9D8));
    after_52:
    // 0x80800500: beq         $v0, $zero, L_80800518
    if (ctx->r2 == 0) {
        // 0x80800504: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80800518;
    }
    // 0x80800504: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800508: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8080050C: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    // 0x80800510: jal         0x80088F98
    // 0x80800514: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_53;
    // 0x80800514: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_53:
L_80800518:
    // 0x80800518: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9DC) << 16);
    // 0x8080051C: jal         0x80085728
    // 0x80800520: lwc1        $f12, 0x9DC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9DC));
    _capod_entrypoint_17(rdram, ctx);
        goto after_54;
    // 0x80800520: lwc1        $f12, 0x9DC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9DC));
    after_54:
    // 0x80800524: beq         $v0, $zero, L_8080053C
    if (ctx->r2 == 0) {
        // 0x80800528: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_8080053C;
    }
    // 0x80800528: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8080052C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80800530: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x80800534: jal         0x80088F98
    // 0x80800538: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_55;
    // 0x80800538: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_55:
L_8080053C:
    // 0x8080053C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9E0) << 16);
    // 0x80800540: jal         0x80085728
    // 0x80800544: lwc1        $f12, 0x9E0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9E0));
    _capod_entrypoint_17(rdram, ctx);
        goto after_56;
    // 0x80800544: lwc1        $f12, 0x9E0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9E0));
    after_56:
    // 0x80800548: beq         $v0, $zero, L_80800560
    if (ctx->r2 == 0) {
        // 0x8080054C: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_80800560;
    }
    // 0x8080054C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800550: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80800554: addiu       $a1, $zero, 0x75
    ctx->r5 = ADD32(0, 0X75);
    // 0x80800558: jal         0x80088F98
    // 0x8080055C: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_57;
    // 0x8080055C: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_57:
L_80800560:
    // 0x80800560: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9E4) << 16);
    // 0x80800564: jal         0x80085728
    // 0x80800568: lwc1        $f12, 0x9E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9E4));
    _capod_entrypoint_17(rdram, ctx);
        goto after_58;
    // 0x80800568: lwc1        $f12, 0x9E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9E4));
    after_58:
    // 0x8080056C: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x80800570: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x80800570: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800574: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80800578: addiu       $a1, $zero, 0x76
    ctx->r5 = ADD32(0, 0X76);
    // 0x8080057C: jal         0x80088F98
    // 0x80800580: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_59;
    // 0x80800580: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_59:
    // 0x80800584: b           L_808008E0
    // 0x80800588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x80800588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080058C:
    // 0x8080058C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800590: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800594: jal         0x80085728
    // 0x80800598: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_60;
    // 0x80800598: nop

    after_60:
    // 0x8080059C: beq         $v0, $zero, L_808005B4
    if (ctx->r2 == 0) {
        // 0x808005A0: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_808005B4;
    }
    // 0x808005A0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x808005A4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x808005A8: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x808005AC: jal         0x80088F98
    // 0x808005B0: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_61;
    // 0x808005B0: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_61:
L_808005B4:
    // 0x808005B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9E8) << 16);
    // 0x808005B8: jal         0x80085728
    // 0x808005BC: lwc1        $f12, 0x9E8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9E8));
    _capod_entrypoint_17(rdram, ctx);
        goto after_62;
    // 0x808005BC: lwc1        $f12, 0x9E8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9E8));
    after_62:
    // 0x808005C0: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x808005C4: lw          $t1, 0x18($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x808005C4: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x808005C8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x808005CC: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    // 0x808005D0: jal         0x80088F98
    // 0x808005D4: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_63;
    // 0x808005D4: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_63:
    // 0x808005D8: b           L_808008E0
    // 0x808005DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x808005DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005E0:
    // 0x808005E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808005E8: jal         0x80085728
    // 0x808005EC: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_64;
    // 0x808005EC: nop

    after_64:
    // 0x808005F0: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x808005F4: lw          $t2, 0x18($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x808005F4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x808005F8: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x808005FC: addiu       $a1, $zero, 0x72
    ctx->r5 = ADD32(0, 0X72);
    // 0x80800600: jal         0x80088F98
    // 0x80800604: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_65;
    // 0x80800604: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_65:
    // 0x80800608: b           L_808008E0
    // 0x8080060C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x8080060C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800610:
    // 0x80800610: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9EC) << 16);
    // 0x80800614: jal         0x80085728
    // 0x80800618: lwc1        $f12, 0x9EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9EC));
    _capod_entrypoint_17(rdram, ctx);
        goto after_66;
    // 0x80800618: lwc1        $f12, 0x9EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9EC));
    after_66:
    // 0x8080061C: beq         $v0, $zero, L_80800634
    if (ctx->r2 == 0) {
        // 0x80800620: lw          $t3, 0x18($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X18);
            goto L_80800634;
    }
    // 0x80800620: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80800624: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80800628: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x8080062C: jal         0x80088F98
    // 0x80800630: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_67;
    // 0x80800630: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_67:
L_80800634:
    // 0x80800634: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9F0) << 16);
    // 0x80800638: jal         0x80085728
    // 0x8080063C: lwc1        $f12, 0x9F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9F0));
    _capod_entrypoint_17(rdram, ctx);
        goto after_68;
    // 0x8080063C: lwc1        $f12, 0x9F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9F0));
    after_68:
    // 0x80800640: beq         $v0, $zero, L_80800658
    if (ctx->r2 == 0) {
        // 0x80800644: lw          $t4, 0x18($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X18);
            goto L_80800658;
    }
    // 0x80800644: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80800648: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8080064C: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    // 0x80800650: jal         0x80088F98
    // 0x80800654: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_69;
    // 0x80800654: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_69:
L_80800658:
    // 0x80800658: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9F4) << 16);
    // 0x8080065C: jal         0x80085728
    // 0x80800660: lwc1        $f12, 0x9F4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9F4));
    _capod_entrypoint_17(rdram, ctx);
        goto after_70;
    // 0x80800660: lwc1        $f12, 0x9F4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9F4));
    after_70:
    // 0x80800664: beq         $v0, $zero, L_8080067C
    if (ctx->r2 == 0) {
        // 0x80800668: lw          $t5, 0x18($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X18);
            goto L_8080067C;
    }
    // 0x80800668: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8080066C: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80800670: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x80800674: jal         0x80088F98
    // 0x80800678: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_71;
    // 0x80800678: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_71:
L_8080067C:
    // 0x8080067C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9F8) << 16);
    // 0x80800680: jal         0x80085728
    // 0x80800684: lwc1        $f12, 0x9F8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9F8));
    _capod_entrypoint_17(rdram, ctx);
        goto after_72;
    // 0x80800684: lwc1        $f12, 0x9F8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9F8));
    after_72:
    // 0x80800688: beq         $v0, $zero, L_808006A0
    if (ctx->r2 == 0) {
        // 0x8080068C: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_808006A0;
    }
    // 0x8080068C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800690: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80800694: addiu       $a1, $zero, 0x75
    ctx->r5 = ADD32(0, 0X75);
    // 0x80800698: jal         0x80088F98
    // 0x8080069C: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_73;
    // 0x8080069C: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_73:
L_808006A0:
    // 0x808006A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0X9FC) << 16);
    // 0x808006A4: jal         0x80085728
    // 0x808006A8: lwc1        $f12, 0x9FC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9FC));
    _capod_entrypoint_17(rdram, ctx);
        goto after_74;
    // 0x808006A8: lwc1        $f12, 0x9FC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0X9FC));
    after_74:
    // 0x808006AC: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x808006B0: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x808006B0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808006B4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x808006B8: addiu       $a1, $zero, 0x76
    ctx->r5 = ADD32(0, 0X76);
    // 0x808006BC: jal         0x80088F98
    // 0x808006C0: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_75;
    // 0x808006C0: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_75:
    // 0x808006C4: b           L_808008E0
    // 0x808006C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x808006C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006CC:
    // 0x808006CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808006D0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808006D4: jal         0x80085728
    // 0x808006D8: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_76;
    // 0x808006D8: nop

    after_76:
    // 0x808006DC: beq         $v0, $zero, L_808006F4
    if (ctx->r2 == 0) {
        // 0x808006E0: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_808006F4;
    }
    // 0x808006E0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808006E4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x808006E8: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x808006EC: jal         0x80088F98
    // 0x808006F0: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_77;
    // 0x808006F0: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_77:
L_808006F4:
    // 0x808006F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808006F8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808006FC: jal         0x80085728
    // 0x80800700: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_78;
    // 0x80800700: nop

    after_78:
    // 0x80800704: beq         $v0, $zero, L_8080071C
    if (ctx->r2 == 0) {
        // 0x80800708: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_8080071C;
    }
    // 0x80800708: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8080070C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80800710: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    // 0x80800714: jal         0x80088F98
    // 0x80800718: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_79;
    // 0x80800718: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_79:
L_8080071C:
    // 0x8080071C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0XA00) << 16);
    // 0x80800720: jal         0x80085728
    // 0x80800724: lwc1        $f12, 0xA00($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0XA00));
    _capod_entrypoint_17(rdram, ctx);
        goto after_80;
    // 0x80800724: lwc1        $f12, 0xA00($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0XA00));
    after_80:
    // 0x80800728: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x8080072C: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x8080072C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80800730: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80800734: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    // 0x80800738: jal         0x80088F98
    // 0x8080073C: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_81;
    // 0x8080073C: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_81:
    // 0x80800740: b           L_808008E0
    // 0x80800744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x80800744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800748:
    // 0x80800748: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080074C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800750: jal         0x80085728
    // 0x80800754: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_82;
    // 0x80800754: nop

    after_82:
    // 0x80800758: beq         $v0, $zero, L_80800770
    if (ctx->r2 == 0) {
        // 0x8080075C: lw          $t1, 0x18($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X18);
            goto L_80800770;
    }
    // 0x8080075C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80800760: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80800764: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    // 0x80800768: jal         0x80088F98
    // 0x8080076C: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_83;
    // 0x8080076C: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_83:
L_80800770:
    // 0x80800770: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80800774: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800778: jal         0x80085728
    // 0x8080077C: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_84;
    // 0x8080077C: nop

    after_84:
    // 0x80800780: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x80800784: lw          $t2, 0x18($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x80800784: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80800788: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8080078C: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    // 0x80800790: jal         0x80088F98
    // 0x80800794: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_85;
    // 0x80800794: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_85:
    // 0x80800798: b           L_808008E0
    // 0x8080079C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x8080079C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007A0:
    // 0x808007A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0XA04) << 16);
    // 0x808007A4: jal         0x80085728
    // 0x808007A8: lwc1        $f12, 0xA04($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0XA04));
    _capod_entrypoint_17(rdram, ctx);
        goto after_86;
    // 0x808007A8: lwc1        $f12, 0xA04($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0XA04));
    after_86:
    // 0x808007AC: beq         $v0, $zero, L_808007C4
    if (ctx->r2 == 0) {
        // 0x808007B0: lw          $t3, 0x18($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X18);
            goto L_808007C4;
    }
    // 0x808007B0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x808007B4: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x808007B8: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x808007BC: jal         0x80088F98
    // 0x808007C0: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_87;
    // 0x808007C0: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_87:
L_808007C4:
    // 0x808007C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0XA08) << 16);
    // 0x808007C8: jal         0x80085728
    // 0x808007CC: lwc1        $f12, 0xA08($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0XA08));
    _capod_entrypoint_17(rdram, ctx);
        goto after_88;
    // 0x808007CC: lwc1        $f12, 0xA08($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0XA08));
    after_88:
    // 0x808007D0: beq         $v0, $zero, L_808007E8
    if (ctx->r2 == 0) {
        // 0x808007D4: lw          $t4, 0x18($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X18);
            goto L_808007E8;
    }
    // 0x808007D4: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x808007D8: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x808007DC: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    // 0x808007E0: jal         0x80088F98
    // 0x808007E4: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_89;
    // 0x808007E4: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_89:
L_808007E8:
    // 0x808007E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0XA0C) << 16);
    // 0x808007EC: jal         0x80085728
    // 0x808007F0: lwc1        $f12, 0xA0C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0XA0C));
    _capod_entrypoint_17(rdram, ctx);
        goto after_90;
    // 0x808007F0: lwc1        $f12, 0xA0C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0XA0C));
    after_90:
    // 0x808007F4: beq         $v0, $zero, L_8080080C
    if (ctx->r2 == 0) {
        // 0x808007F8: lw          $t5, 0x18($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X18);
            goto L_8080080C;
    }
    // 0x808007F8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x808007FC: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80800800: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x80800804: jal         0x80088F98
    // 0x80800808: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_91;
    // 0x80800808: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_91:
L_8080080C:
    // 0x8080080C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0XA10) << 16);
    // 0x80800810: jal         0x80085728
    // 0x80800814: lwc1        $f12, 0xA10($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0XA10));
    _capod_entrypoint_17(rdram, ctx);
        goto after_92;
    // 0x80800814: lwc1        $f12, 0xA10($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0XA10));
    after_92:
    // 0x80800818: beq         $v0, $zero, L_80800830
    if (ctx->r2 == 0) {
        // 0x8080081C: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80800830;
    }
    // 0x8080081C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800820: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80800824: addiu       $a1, $zero, 0x75
    ctx->r5 = ADD32(0, 0X75);
    // 0x80800828: jal         0x80088F98
    // 0x8080082C: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_93;
    // 0x8080082C: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_93:
L_80800830:
    // 0x80800830: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1736, 0XA14) << 16);
    // 0x80800834: jal         0x80085728
    // 0x80800838: lwc1        $f12, 0xA14($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0XA14));
    _capod_entrypoint_17(rdram, ctx);
        goto after_94;
    // 0x80800838: lwc1        $f12, 0xA14($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1736, 0XA14));
    after_94:
    // 0x8080083C: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x80800840: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x80800840: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800844: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80800848: addiu       $a1, $zero, 0x76
    ctx->r5 = ADD32(0, 0X76);
    // 0x8080084C: jal         0x80088F98
    // 0x80800850: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_95;
    // 0x80800850: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_95:
    // 0x80800854: b           L_808008E0
    // 0x80800858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x80800858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080085C:
    // 0x8080085C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800860: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800864: jal         0x80085728
    // 0x80800868: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_96;
    // 0x80800868: nop

    after_96:
    // 0x8080086C: beq         $v0, $zero, L_80800884
    if (ctx->r2 == 0) {
        // 0x80800870: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_80800884;
    }
    // 0x80800870: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800874: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80800878: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x8080087C: jal         0x80088F98
    // 0x80800880: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_97;
    // 0x80800880: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_97:
L_80800884:
    // 0x80800884: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800888: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080088C: jal         0x80085728
    // 0x80800890: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_98;
    // 0x80800890: nop

    after_98:
    // 0x80800894: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x80800898: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x80800898: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8080089C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x808008A0: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x808008A4: jal         0x80088F98
    // 0x808008A8: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_99;
    // 0x808008A8: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_99:
    // 0x808008AC: b           L_808008E0
    // 0x808008B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x808008B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008B4:
    // 0x808008B4: lui         $at, 0x4596
    ctx->r1 = S32(0X4596 << 16);
    // 0x808008B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808008BC: jal         0x80085728
    // 0x808008C0: nop

    _capod_entrypoint_17(rdram, ctx);
        goto after_100;
    // 0x808008C0: nop

    after_100:
    // 0x808008C4: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x808008C8: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_808008DC;
    }
    // 0x808008C8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x808008CC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x808008D0: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    // 0x808008D4: jal         0x80088F98
    // 0x808008D8: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    _indrv_audio_entrypoint_0(rdram, ctx);
        goto after_101;
    // 0x808008D8: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    after_101:
L_808008DC:
    // 0x808008DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008E0:
    // 0x808008E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008E4: jr          $ra
    // 0x808008E8: nop

    return;
    // 0x808008E8: nop

;}
RECOMP_FUNC void func_80800388_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800388: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080038C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800390: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800394: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800398: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080039C: jal         0x80100094
    // 0x808003A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808003A8: lbu         $v1, 0x28($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X28);
    // 0x808003AC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808003B0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808003B4: beq         $v1, $zero, L_808003D8
    if (ctx->r3 == 0) {
        // 0x808003B8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_808003D8;
    }
    // 0x808003B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808003BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003C0: beq         $v1, $at, L_80800408
    if (ctx->r3 == ctx->r1) {
        // 0x808003C4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800408;
    }
    // 0x808003C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808003C8: beq         $v1, $at, L_808003E0
    if (ctx->r3 == ctx->r1) {
        // 0x808003CC: nop
    
            goto L_808003E0;
    }
    // 0x808003CC: nop

    // 0x808003D0: b           L_80800418
    // 0x808003D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800418;
    // 0x808003D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003D8:
    // 0x808003D8: jal         0x800856B0
    // 0x808003DC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808003DC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
L_808003E0:
    // 0x808003E0: jal         0x800856E0
    // 0x808003E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x808003E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x808003E8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x808003EC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808003F0: sb          $t7, 0x28($t8)
    MEM_B(0X28, ctx->r24) = ctx->r15;
    // 0x808003F4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808003F8: jal         0x800880A8
    // 0x808003FC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    _gcdialogcamera_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x808003FC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_3:
    // 0x80800400: jal         0x800880B8
    // 0x80800404: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80800404: nop

    after_4:
L_80800408:
    // 0x80800408: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080040C: jal         0x800856D8
    // 0x80800410: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x80800410: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800418:
    // 0x80800418: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080041C: jr          $ra
    // 0x80800420: nop

    return;
    // 0x80800420: nop

;}
RECOMP_FUNC void func_800E3A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3A08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3A0C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E3A10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3A14: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3A18: jal         0x800CA810
    // 0x800E3A1C: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA810(rdram, ctx);
        goto after_0;
    // 0x800E3A1C: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E3A20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3A24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3A28: jr          $ra
    // 0x800E3A2C: nop

    return;
    // 0x800E3A2C: nop

;}
RECOMP_FUNC void func_808007E0_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808007EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808007F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007F4: jal         0x8009EF10
    // 0x808007F8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    bastick_getZone(rdram, ctx);
        goto after_0;
    // 0x808007F8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    after_0:
    // 0x808007FC: blez        $v0, L_8080081C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800800: nop
    
            goto L_8080081C;
    }
    // 0x80800800: nop

    // 0x80800804: lw          $t6, 0x160($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X160);
    // 0x80800808: addiu       $s1, $zero, 0x16
    ctx->r17 = ADD32(0, 0X16);
    // 0x8080080C: beq         $t6, $zero, L_8080081C
    if (ctx->r14 == 0) {
        // 0x80800810: nop
    
            goto L_8080081C;
    }
    // 0x80800810: nop

    // 0x80800814: b           L_8080081C
    // 0x80800818: addiu       $s1, $zero, 0x17C
    ctx->r17 = ADD32(0, 0X17C);
        goto L_8080081C;
    // 0x80800818: addiu       $s1, $zero, 0x17C
    ctx->r17 = ADD32(0, 0X17C);
L_8080081C:
    // 0x8080081C: jal         0x80097AD0
    // 0x80800820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_1;
    // 0x80800820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800824: beql        $v0, $zero, L_8080083C
    if (ctx->r2 == 0) {
        // 0x80800828: lw          $t7, 0x160($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X160);
            goto L_8080083C;
    }
    goto skip_0;
    // 0x80800828: lw          $t7, 0x160($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X160);
    skip_0:
    // 0x8080082C: jal         0x800848A8
    // 0x80800830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_2;
    // 0x80800830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800834: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800838: lw          $t7, 0x160($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X160);
L_8080083C:
    // 0x8080083C: bne         $t7, $zero, L_80800858
    if (ctx->r15 != 0) {
        // 0x80800840: nop
    
            goto L_80800858;
    }
    // 0x80800840: nop

    // 0x80800844: jal         0x8008DD04
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_3;
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080084C: beq         $v0, $zero, L_80800858
    if (ctx->r2 == 0) {
        // 0x80800850: nop
    
            goto L_80800858;
    }
    // 0x80800850: nop

    // 0x80800854: addiu       $s1, $zero, 0x71
    ctx->r17 = ADD32(0, 0X71);
L_80800858:
    // 0x80800858: jal         0x80800710
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800710_bsbtrot(rdram, ctx);
        goto after_4;
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800860: beq         $v0, $zero, L_8080086C
    if (ctx->r2 == 0) {
        // 0x80800864: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080086C;
    }
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800868: addiu       $s1, $zero, 0x17
    ctx->r17 = ADD32(0, 0X17);
L_8080086C:
    // 0x8080086C: jal         0x80091A58
    // 0x80800870: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_5;
    // 0x80800870: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
    // 0x80800874: beq         $v0, $zero, L_80800888
    if (ctx->r2 == 0) {
        // 0x80800878: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800888;
    }
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080087C: jal         0x8080075C
    // 0x80800880: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8080075C_bsbtrot(rdram, ctx);
        goto after_6;
    // 0x80800880: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x80800884: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80800888:
    // 0x80800888: lw          $t8, 0x160($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X160);
    // 0x8080088C: bne         $t8, $zero, L_808008A8
    if (ctx->r24 != 0) {
        // 0x80800890: nop
    
            goto L_808008A8;
    }
    // 0x80800890: nop

    // 0x80800894: jal         0x8008DF18
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DF18(rdram, ctx);
        goto after_7;
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080089C: beq         $v0, $zero, L_808008A8
    if (ctx->r2 == 0) {
        // 0x808008A0: nop
    
            goto L_808008A8;
    }
    // 0x808008A0: nop

    // 0x808008A4: addiu       $s1, $zero, 0x45
    ctx->r17 = ADD32(0, 0X45);
L_808008A8:
    // 0x808008A8: jal         0x8008E35C
    // 0x808008AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_8;
    // 0x808008AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808008B0: beq         $v0, $zero, L_808008BC
    if (ctx->r2 == 0) {
        // 0x808008B4: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_808008BC;
    }
    // 0x808008B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808008B8: addiu       $s1, $zero, 0x2D
    ctx->r17 = ADD32(0, 0X2D);
L_808008BC:
    // 0x808008BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008C0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x808008C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808008C8: jr          $ra
    // 0x808008CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808008CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800962B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800962B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800962B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800962B8: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x800962BC: jal         0x800C68D4
    // 0x800962C0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C68D4(rdram, ctx);
        goto after_0;
    // 0x800962C0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x800962C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800962C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800962CC: jr          $ra
    // 0x800962D0: nop

    return;
    // 0x800962D0: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084298: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084298);
    return;
    // 0x8008429C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void badrone_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: lw          $v0, 0x54($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X54);
    // 0x8080005C: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80800060: jr          $ra
    // 0x80800064: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    return;
    // 0x80800064: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_800D9154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9154: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D9158: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D915C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D9160: jal         0x800D8FF8
    // 0x800D9164: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800D9164: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D9168: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800D916C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800D9170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D9174: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800D9178: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800D917C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800D9180: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800D9184: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800D9188: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x800D918C: nop

    // 0x800D9190: bc1f        L_800D91A8
    if (!c1cs) {
        // 0x800D9194: nop
    
            goto L_800D91A8;
    }
    // 0x800D9194: nop

    // 0x800D9198: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x800D919C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D91A0: b           L_800D91A8
    // 0x800D91A4: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
        goto L_800D91A8;
    // 0x800D91A4: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
L_800D91A8:
    // 0x800D91A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D91AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D91B0: jr          $ra
    // 0x800D91B4: nop

    return;
    // 0x800D91B4: nop

;}
RECOMP_FUNC void func_800BBD60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BBD60: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800BBD64: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800BBD68: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800BBD6C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800BBD70: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800BBD74: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800BBD78: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800BBD7C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800BBD80: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800BBD84: jal         0x800D674C
    // 0x800BBD88: lhu         $a0, 0x2($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X2);
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x800BBD88: lhu         $a0, 0x2($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X2);
    after_0:
    // 0x800BBD8C: lw          $s0, 0x8C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8C);
    // 0x800BBD90: lw          $t6, 0x90($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X90);
    // 0x800BBD94: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800BBD98: sltu        $at, $s0, $t6
    ctx->r1 = ctx->r16 < ctx->r14 ? 1 : 0;
    // 0x800BBD9C: beq         $at, $zero, L_800BBEB8
    if (ctx->r1 == 0) {
        // 0x800BBDA0: lui         $at, 0x3B80
        ctx->r1 = S32(0X3B80 << 16);
            goto L_800BBEB8;
    }
    // 0x800BBDA0: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x800BBDA4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800BBDA8: addiu       $s3, $sp, 0x40
    ctx->r19 = ADD32(ctx->r29, 0X40);
    // 0x800BBDAC: lh          $t7, 0xC($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XC);
L_800BBDB0:
    // 0x800BBDB0: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x800BBDB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BBDB8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800BBDBC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800BBDC0: nop

    // 0x800BBDC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BBDC8: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x800BBDCC: lh          $t1, 0x8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X8);
    // 0x800BBDD0: lh          $t0, 0xE($s1)
    ctx->r8 = MEM_H(ctx->r17, 0XE);
    // 0x800BBDD4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800BBDD8: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800BBDDC: nop

    // 0x800BBDE0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BBDE4: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x800BBDE8: lh          $t4, 0xA($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XA);
    // 0x800BBDEC: lh          $t3, 0x10($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X10);
    // 0x800BBDF0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800BBDF4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x800BBDF8: nop

    // 0x800BBDFC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BBE00: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x800BBE04: lbu         $t6, 0x83($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X83);
    // 0x800BBE08: lbu         $a2, 0x82($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X82);
    // 0x800BBE0C: lbu         $a1, 0x81($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X81);
    // 0x800BBE10: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800BBE14: lbu         $a0, 0x80($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X80);
    // 0x800BBE18: bgez        $t6, L_800BBE2C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800BBE1C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800BBE2C;
    }
    // 0x800BBE1C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BBE20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BBE24: nop

    // 0x800BBE28: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800BBE2C:
    // 0x800BBE2C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800BBE30: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800BBE34: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800BBE38: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800BBE3C: jal         0x800DF5D8
    // 0x800BBE40: nop

    func_800DF5D8(rdram, ctx);
        goto after_1;
    // 0x800BBE40: nop

    after_1:
    // 0x800BBE44: jal         0x800DF830
    // 0x800BBE48: lbu         $a0, 0x53($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X53);
    func_800DF830(rdram, ctx);
        goto after_2;
    // 0x800BBE48: lbu         $a0, 0x53($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X53);
    after_2:
    // 0x800BBE4C: lh          $t8, 0x30($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X30);
    // 0x800BBE50: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800BBE54: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800BBE58: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800BBE5C: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x800BBE60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BBE64: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BBE68: mul.s       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800BBE6C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800BBE70: jal         0x800DE448
    // 0x800BBE74: nop

    func_800DE448(rdram, ctx);
        goto after_3;
    // 0x800BBE74: nop

    after_3:
    // 0x800BBE78: beq         $v0, $zero, L_800BBE88
    if (ctx->r2 == 0) {
        // 0x800BBE7C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BBE88;
    }
    // 0x800BBE7C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BBE80: b           L_800BBE88
    // 0x800BBE84: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBE88;
    // 0x800BBE84: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BBE88:
    // 0x800BBE88: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x800BBE8C: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x800BBE90: srl         $t9, $v0, 7
    ctx->r25 = S32(U32(ctx->r2) >> 7);
    // 0x800BBE94: or          $t1, $t9, $v1
    ctx->r9 = ctx->r25 | ctx->r3;
    // 0x800BBE98: sll         $t3, $t1, 7
    ctx->r11 = S32(ctx->r9 << 7);
    // 0x800BBE9C: andi        $t4, $v0, 0xFF7F
    ctx->r12 = ctx->r2 & 0XFF7F;
    // 0x800BBEA0: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x800BBEA4: sb          $t5, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r13;
    // 0x800BBEA8: lw          $t6, 0x90($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X90);
    // 0x800BBEAC: sltu        $at, $s0, $t6
    ctx->r1 = ctx->r16 < ctx->r14 ? 1 : 0;
    // 0x800BBEB0: bnel        $at, $zero, L_800BBDB0
    if (ctx->r1 != 0) {
        // 0x800BBEB4: lh          $t7, 0xC($s1)
        ctx->r15 = MEM_H(ctx->r17, 0XC);
            goto L_800BBDB0;
    }
    goto skip_0;
    // 0x800BBEB4: lh          $t7, 0xC($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XC);
    skip_0:
L_800BBEB8:
    // 0x800BBEB8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800BBEBC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800BBEC0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800BBEC4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800BBEC8: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800BBECC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800BBED0: jr          $ra
    // 0x800BBED4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800BBED4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800070_chexplodingchainlinks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800074: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080007C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800080: beq         $a1, $at, L_8080009C
    if (ctx->r5 == ctx->r1) {
        // 0x80800084: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_8080009C;
    }
    // 0x80800084: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800088: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x8080008C: beq         $a1, $at, L_808000C8
    if (ctx->r5 == ctx->r1) {
        // 0x80800090: nop
    
            goto L_808000C8;
    }
    // 0x80800090: nop

    // 0x80800094: b           L_808000FC
    // 0x80800098: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000FC;
    // 0x80800098: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080009C:
    // 0x8080009C: jal         0x80101038
    // 0x808000A0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_80101038(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x808000A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808000A8: jal         0x8080010C
    // 0x808000AC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8080010C_chexplodingchainlinks(rdram, ctx);
        goto after_1;
    // 0x808000AC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x808000B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808000B4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808000B8: jal         0x80086670
    // 0x808000BC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808000BC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x808000C0: b           L_808000FC
    // 0x808000C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000FC;
    // 0x808000C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000C8:
    // 0x808000C8: jal         0x80101080
    // 0x808000CC: nop

    func_80101080(rdram, ctx);
        goto after_3;
    // 0x808000CC: nop

    after_3:
    // 0x808000D0: jal         0x80106790
    // 0x808000D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x808000D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808000D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000DC: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x808000E0: jal         0x80086688
    // 0x808000E4: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x808000E4: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    after_5:
    // 0x808000E8: b           L_808000FC
    // 0x808000EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000FC;
    // 0x808000EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808000F0: b           L_808000FC
    // 0x808000F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000FC;
    // 0x808000F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000FC:
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800100: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void bsbansnooze_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A14: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800A18: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(49, 0XAA8) << 16);
    // 0x80800A1C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800A20: jr          $ra
    // 0x80800A24: lw          $v0, 0xAA8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(49, 0XAA8));
    return;
    // 0x80800A24: lw          $v0, 0xAA8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(49, 0XAA8));
    // 0x80800A28: nop

    // 0x80800A2C: nop

;}
RECOMP_FUNC void func_800F7C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7C9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7CA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F7CA4: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800F7CA8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7CAC: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800F7CB0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7CB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7CB8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F7CBC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800F7CC0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800F7CC4: jal         0x8009AD20
    // 0x800F7CC8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009AD20(rdram, ctx);
        goto after_0;
    // 0x800F7CC8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F7CCC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7CD0: jal         0x8009AD2C
    // 0x800F7CD4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8009AD2C(rdram, ctx);
        goto after_1;
    // 0x800F7CD4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800F7CD8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7CDC: jal         0x8009E7C8
    // 0x800F7CE0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009E7C8(rdram, ctx);
        goto after_2;
    // 0x800F7CE0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x800F7CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7CE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F7CEC: jr          $ra
    // 0x800F7CF0: nop

    return;
    // 0x800F7CF0: nop

;}
RECOMP_FUNC void _ncpoddialog_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089600: syscall     784
    recomp_syscall_handler(rdram, ctx, 0x80089600);
    return;
    // 0x80089604: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800F80_chjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F88: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800F8C: addiu       $at, $zero, 0x48F
    ctx->r1 = ADD32(0, 0X48F);
    // 0x80800F90: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800F94: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x80800F98: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80800F9C: beq         $t8, $at, L_80800FB4
    if (ctx->r24 == ctx->r1) {
        // 0x80800FA0: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1672, 0X1330) << 16);
            goto L_80800FB4;
    }
    // 0x80800FA0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1672, 0X1330) << 16);
    // 0x80800FA4: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80800FA8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800FAC: jal         0x80089D20
    // 0x80800FB0: addiu       $a2, $a2, 0x1330
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1672, 0X1330));
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800FB0: addiu       $a2, $a2, 0x1330
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1672, 0X1330));
    after_0:
L_80800FB4:
    // 0x80800FB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FBC: jr          $ra
    // 0x80800FC0: nop

    return;
    // 0x80800FC0: nop

;}
RECOMP_FUNC void func_800A2848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2848: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A284C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A2850: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800A2854: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800A2858: jal         0x800F53D0
    // 0x800A285C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x800A285C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800A2860: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800A2864: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A2868: xori        $v1, $a1, 0x4
    ctx->r3 = ctx->r5 ^ 0X4;
    // 0x800A286C: sltiu       $a2, $v1, 0x1
    ctx->r6 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800A2870: bne         $a2, $zero, L_800A2894
    if (ctx->r6 != 0) {
        // 0x800A2874: xori        $v0, $a1, 0xB
        ctx->r2 = ctx->r5 ^ 0XB;
            goto L_800A2894;
    }
    // 0x800A2874: xori        $v0, $a1, 0xB
    ctx->r2 = ctx->r5 ^ 0XB;
    // 0x800A2878: sltiu       $a2, $v0, 0x1
    ctx->r6 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800A287C: bnel        $a2, $zero, L_800A2898
    if (ctx->r6 != 0) {
        // 0x800A2880: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_800A2898;
    }
    goto skip_0;
    // 0x800A2880: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    skip_0:
    // 0x800A2884: xori        $a2, $a1, 0x15
    ctx->r6 = ctx->r5 ^ 0X15;
    // 0x800A2888: sltiu       $a2, $a2, 0x1
    ctx->r6 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x800A288C: sltu        $t6, $zero, $a2
    ctx->r14 = 0 < ctx->r6 ? 1 : 0;
    // 0x800A2890: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
L_800A2894:
    // 0x800A2894: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
L_800A2898:
    // 0x800A2898: jal         0x8008E35C
    // 0x800A289C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    player_inWater(rdram, ctx);
        goto after_1;
    // 0x800A289C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x800A28A0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800A28A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A28A8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800A28AC: beq         $a2, $zero, L_800A28D0
    if (ctx->r6 == 0) {
        // 0x800A28B0: lw          $a1, 0x34($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X34);
            goto L_800A28D0;
    }
    // 0x800A28B0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800A28B4: xori        $t7, $a1, 0x15
    ctx->r15 = ctx->r5 ^ 0X15;
    // 0x800A28B8: sltiu       $a1, $t7, 0x1
    ctx->r5 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800A28BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A28C0: jal         0x800A275C
    // 0x800A28C4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_800A275C(rdram, ctx);
        goto after_2;
    // 0x800A28C4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_2:
    // 0x800A28C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A28CC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_800A28D0:
    // 0x800A28D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A28D4: jal         0x8008FD48
    // 0x800A28D8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_8008FD48(rdram, ctx);
        goto after_3;
    // 0x800A28D8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_3:
    // 0x800A28DC: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800A28E0: sltiu       $at, $t8, 0x13
    ctx->r1 = ctx->r24 < 0X13 ? 1 : 0;
    // 0x800A28E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A28E8: beq         $at, $zero, L_800A29F0
    if (ctx->r1 == 0) {
        // 0x800A28EC: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_800A29F0;
    }
    // 0x800A28EC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800A28F0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A28F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A28F8: addu        $at, $at, $t8
    gpr jr_addend_800A2900 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800A28FC: lw          $t8, 0x54C0($at)
    ctx->r24 = ADD32(ctx->r1, 0X54C0);
    // 0x800A2900: jr          $t8
    // 0x800A2904: nop

    switch (jr_addend_800A2900 >> 2) {
        case 0: goto L_800A299C; break;
        case 1: goto L_800A29F0; break;
        case 2: goto L_800A29F0; break;
        case 3: goto L_800A29F0; break;
        case 4: goto L_800A29F0; break;
        case 5: goto L_800A29F0; break;
        case 6: goto L_800A29F0; break;
        case 7: goto L_800A29F0; break;
        case 8: goto L_800A29F0; break;
        case 9: goto L_800A29F0; break;
        case 10: goto L_800A299C; break;
        case 11: goto L_800A29F0; break;
        case 12: goto L_800A29F0; break;
        case 13: goto L_800A2940; break;
        case 14: goto L_800A2908; break;
        case 15: goto L_800A29F0; break;
        case 16: goto L_800A29F0; break;
        case 17: goto L_800A29F0; break;
        case 18: goto L_800A297C; break;
        default: switch_error(__func__, 0x800A2900, 0x801254C0);
    }
    // 0x800A2904: nop

L_800A2908:
    // 0x800A2908: bne         $a2, $zero, L_800A2918
    if (ctx->r6 != 0) {
        // 0x800A290C: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_800A2918;
    }
    // 0x800A290C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800A2910: beq         $t9, $zero, L_800A292C
    if (ctx->r25 == 0) {
        // 0x800A2914: addiu       $a1, $zero, 0x448
        ctx->r5 = ADD32(0, 0X448);
            goto L_800A292C;
    }
    // 0x800A2914: addiu       $a1, $zero, 0x448
    ctx->r5 = ADD32(0, 0X448);
L_800A2918:
    // 0x800A2918: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800A291C: jal         0x80088A48
    // 0x800A2920: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    _fxstep_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x800A2920: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_4:
    // 0x800A2924: b           L_800A29F4
    // 0x800A2928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A29F4;
    // 0x800A2928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A292C:
    // 0x800A292C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800A2930: jal         0x8009DB04
    // 0x800A2934: addiu       $a3, $zero, 0x1388
    ctx->r7 = ADD32(0, 0X1388);
    func_8009DB04(rdram, ctx);
        goto after_5;
    // 0x800A2934: addiu       $a3, $zero, 0x1388
    ctx->r7 = ADD32(0, 0X1388);
    after_5:
    // 0x800A2938: b           L_800A29F4
    // 0x800A293C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A29F4;
    // 0x800A293C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2940:
    // 0x800A2940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A2944: jal         0x80084FC8
    // 0x800A2948: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _bashake_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x800A2948: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x800A294C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800A2950: jal         0x80088A48
    // 0x800A2954: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    _fxstep_entrypoint_13(rdram, ctx);
        goto after_7;
    // 0x800A2954: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_7:
    // 0x800A2958: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800A295C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800A2960: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800A2964: bnel        $t0, $at, L_800A29F4
    if (ctx->r8 != ctx->r1) {
        // 0x800A2968: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A29F4;
    }
    goto skip_1;
    // 0x800A2968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800A296C: jal         0x80088A48
    // 0x800A2970: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    _fxstep_entrypoint_13(rdram, ctx);
        goto after_8;
    // 0x800A2970: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_8:
    // 0x800A2974: b           L_800A29F4
    // 0x800A2978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A29F4;
    // 0x800A2978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A297C:
    // 0x800A297C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A2980: jal         0x80084FC8
    // 0x800A2984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _bashake_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x800A2984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x800A2988: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800A298C: jal         0x80088A48
    // 0x800A2990: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    _fxstep_entrypoint_13(rdram, ctx);
        goto after_10;
    // 0x800A2990: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_10:
    // 0x800A2994: b           L_800A29F4
    // 0x800A2998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A29F4;
    // 0x800A2998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A299C:
    // 0x800A299C: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800A29A0: jal         0x8009E674
    // 0x800A29A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8009E674(rdram, ctx);
        goto after_11;
    // 0x800A29A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_11:
    // 0x800A29A8: beq         $v0, $zero, L_800A29F0
    if (ctx->r2 == 0) {
        // 0x800A29AC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800A29F0;
    }
    // 0x800A29AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A29B0: jal         0x80084FE0
    // 0x800A29B4: nop

    _bashoes_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x800A29B4: nop

    after_12:
    // 0x800A29B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A29BC: beq         $v0, $at, L_800A29D8
    if (ctx->r2 == ctx->r1) {
        // 0x800A29C0: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_800A29D8;
    }
    // 0x800A29C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800A29C4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800A29C8: beq         $v0, $at, L_800A29E8
    if (ctx->r2 == ctx->r1) {
        // 0x800A29CC: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_800A29E8;
    }
    // 0x800A29CC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800A29D0: b           L_800A29F4
    // 0x800A29D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A29F4;
    // 0x800A29D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A29D8:
    // 0x800A29D8: jal         0x80088A48
    // 0x800A29DC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    _fxstep_entrypoint_13(rdram, ctx);
        goto after_13;
    // 0x800A29DC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_13:
    // 0x800A29E0: b           L_800A29F4
    // 0x800A29E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A29F4;
    // 0x800A29E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A29E8:
    // 0x800A29E8: jal         0x80088A48
    // 0x800A29EC: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    _fxstep_entrypoint_13(rdram, ctx);
        goto after_14;
    // 0x800A29EC: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_14:
L_800A29F0:
    // 0x800A29F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A29F4:
    // 0x800A29F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A29F8: jr          $ra
    // 0x800A29FC: nop

    return;
    // 0x800A29FC: nop

;}
RECOMP_FUNC void func_80801220_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801220: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801224: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801228: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080122C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801230: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801234: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80801238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080123C: jal         0x80100094
    // 0x80801240: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801240: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801244: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80801248: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8080124C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80801250: slti        $at, $a2, 0x96
    ctx->r1 = SIGNED(ctx->r6) < 0X96 ? 1 : 0;
    // 0x80801254: bne         $at, $zero, L_80801278
    if (ctx->r1 != 0) {
        // 0x80801258: addiu       $t6, $a2, -0xA
        ctx->r14 = ADD32(ctx->r6, -0XA);
            goto L_80801278;
    }
    // 0x80801258: addiu       $t6, $a2, -0xA
    ctx->r14 = ADD32(ctx->r6, -0XA);
    // 0x8080125C: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x80801260: beq         $a2, $at, L_80801594
    if (ctx->r6 == ctx->r1) {
        // 0x80801264: addiu       $at, $zero, 0x9F
        ctx->r1 = ADD32(0, 0X9F);
            goto L_80801594;
    }
    // 0x80801264: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x80801268: beql        $a2, $at, L_808015D4
    if (ctx->r6 == ctx->r1) {
        // 0x8080126C: lh          $t5, 0x1A($v0)
        ctx->r13 = MEM_H(ctx->r2, 0X1A);
            goto L_808015D4;
    }
    goto skip_0;
    // 0x8080126C: lh          $t5, 0x1A($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X1A);
    skip_0:
    // 0x80801270: b           L_8080161C
    // 0x80801274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080161C;
    // 0x80801274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801278:
    // 0x80801278: slti        $at, $a2, 0x58
    ctx->r1 = SIGNED(ctx->r6) < 0X58 ? 1 : 0;
    // 0x8080127C: bne         $at, $zero, L_80801294
    if (ctx->r1 != 0) {
        // 0x80801280: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80801294;
    }
    // 0x80801280: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80801284: beq         $a2, $at, L_808014AC
    if (ctx->r6 == ctx->r1) {
        // 0x80801288: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808014AC;
    }
    // 0x80801288: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080128C: b           L_8080161C
    // 0x80801290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080161C;
    // 0x80801290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801294:
    // 0x80801294: sltiu       $at, $t6, 0x4E
    ctx->r1 = ctx->r14 < 0X4E ? 1 : 0;
    // 0x80801298: beq         $at, $zero, L_80801610
    if (ctx->r1 == 0) {
        // 0x8080129C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801610;
    }
    // 0x8080129C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808012A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1240, 0X3624) << 16);
    // 0x808012A4: addu        $at, $at, $t6
    gpr jr_addend_808012AC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808012A8: lw          $t6, 0x3624($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1240, 0X3624));
    // 0x808012AC: jr          $t6
    // 0x808012B0: nop

    switch (jr_addend_808012AC >> 2) {
        case 0: goto L_808013DC; break;
        case 1: goto L_808012D0; break;
        case 2: goto L_80801610; break;
        case 3: goto L_80801610; break;
        case 4: goto L_80801610; break;
        case 5: goto L_80801610; break;
        case 6: goto L_80801610; break;
        case 7: goto L_80801610; break;
        case 8: goto L_80801610; break;
        case 9: goto L_80801610; break;
        case 10: goto L_80801610; break;
        case 11: goto L_80801610; break;
        case 12: goto L_80801610; break;
        case 13: goto L_80801610; break;
        case 14: goto L_80801610; break;
        case 15: goto L_80801610; break;
        case 16: goto L_80801610; break;
        case 17: goto L_80801610; break;
        case 18: goto L_80801610; break;
        case 19: goto L_80801610; break;
        case 20: goto L_80801610; break;
        case 21: goto L_8080157C; break;
        case 22: goto L_80801610; break;
        case 23: goto L_80801610; break;
        case 24: goto L_80801610; break;
        case 25: goto L_80801610; break;
        case 26: goto L_80801610; break;
        case 27: goto L_80801610; break;
        case 28: goto L_80801610; break;
        case 29: goto L_80801610; break;
        case 30: goto L_80801610; break;
        case 31: goto L_80801518; break;
        case 32: goto L_8080155C; break;
        case 33: goto L_80801610; break;
        case 34: goto L_80801358; break;
        case 35: goto L_80801610; break;
        case 36: goto L_808012B4; break;
        case 37: goto L_80801610; break;
        case 38: goto L_80801610; break;
        case 39: goto L_80801610; break;
        case 40: goto L_80801460; break;
        case 41: goto L_80801610; break;
        case 42: goto L_80801610; break;
        case 43: goto L_80801610; break;
        case 44: goto L_80801610; break;
        case 45: goto L_80801610; break;
        case 46: goto L_80801610; break;
        case 47: goto L_80801610; break;
        case 48: goto L_80801610; break;
        case 49: goto L_80801610; break;
        case 50: goto L_80801610; break;
        case 51: goto L_80801344; break;
        case 52: goto L_80801610; break;
        case 53: goto L_80801610; break;
        case 54: goto L_8080132C; break;
        case 55: goto L_80801610; break;
        case 56: goto L_80801610; break;
        case 57: goto L_80801610; break;
        case 58: goto L_80801610; break;
        case 59: goto L_80801610; break;
        case 60: goto L_80801610; break;
        case 61: goto L_80801610; break;
        case 62: goto L_80801610; break;
        case 63: goto L_80801610; break;
        case 64: goto L_80801610; break;
        case 65: goto L_80801610; break;
        case 66: goto L_80801610; break;
        case 67: goto L_80801610; break;
        case 68: goto L_80801610; break;
        case 69: goto L_80801610; break;
        case 70: goto L_80801610; break;
        case 71: goto L_80801610; break;
        case 72: goto L_80801448; break;
        case 73: goto L_80801610; break;
        case 74: goto L_80801610; break;
        case 75: goto L_80801610; break;
        case 76: goto L_80801610; break;
        case 77: goto L_80801480; break;
        default: switch_error(__func__, 0x808012AC, 0x80803624);
    }
    // 0x808012B0: nop

L_808012B4:
    // 0x808012B4: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x808012B8: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808012BC: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x808012C0: jal         0x80801744
    // 0x808012C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80801744_chklungo(rdram, ctx);
        goto after_1;
    // 0x808012C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x808012C8: b           L_8080161C
    // 0x808012CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080161C;
    // 0x808012CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808012D0:
    // 0x808012D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808012D4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808012D8: jal         0x80802480
    // 0x808012DC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80802480_chklungo(rdram, ctx);
        goto after_2;
    // 0x808012DC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x808012E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808012E4: beq         $v0, $at, L_80801300
    if (ctx->r2 == ctx->r1) {
        // 0x808012E8: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80801300;
    }
    // 0x808012E8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808012EC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808012F0: beq         $v0, $at, L_80801314
    if (ctx->r2 == ctx->r1) {
        // 0x808012F4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80801314;
    }
    // 0x808012F4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808012F8: b           L_8080161C
    // 0x808012FC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080161C;
    // 0x808012FC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80801300:
    // 0x80801300: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801304: jal         0x80801964
    // 0x80801308: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80801964_chklungo(rdram, ctx);
        goto after_3;
    // 0x80801308: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_3:
    // 0x8080130C: b           L_8080161C
    // 0x80801310: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8080161C;
    // 0x80801310: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80801314:
    // 0x80801314: jal         0x80801964
    // 0x80801318: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    func_80801964_chklungo(rdram, ctx);
        goto after_4;
    // 0x80801318: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_4:
    // 0x8080131C: b           L_8080161C
    // 0x80801320: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8080161C;
    // 0x80801320: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80801324: b           L_8080161C
    // 0x80801328: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080161C;
    // 0x80801328: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8080132C:
    // 0x8080132C: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80801330: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801334: jal         0x80801680
    // 0x80801338: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80801680_chklungo(rdram, ctx);
        goto after_5;
    // 0x80801338: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_5:
    // 0x8080133C: b           L_8080161C
    // 0x80801340: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080161C;
    // 0x80801340: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801344:
    // 0x80801344: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801348: jal         0x80802B84
    // 0x8080134C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80802B84_chklungo(rdram, ctx);
        goto after_6;
    // 0x8080134C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80801350: b           L_8080161C
    // 0x80801354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080161C;
    // 0x80801354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801358:
    // 0x80801358: lh          $t7, 0x1A($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X1A);
    // 0x8080135C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801364: beql        $t7, $zero, L_80801384
    if (ctx->r15 == 0) {
        // 0x80801368: sw          $v1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r3;
            goto L_80801384;
    }
    goto skip_1;
    // 0x80801368: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    skip_1:
    // 0x8080136C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801370: jal         0x80801964
    // 0x80801374: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    func_80801964_chklungo(rdram, ctx);
        goto after_7;
    // 0x80801374: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_7:
    // 0x80801378: b           L_8080161C
    // 0x8080137C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080161C;
    // 0x8080137C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801380: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_80801384:
    // 0x80801384: jal         0x8010A800
    // 0x80801388: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8010A800(rdram, ctx);
        goto after_8;
    // 0x80801388: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_8:
    // 0x8080138C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80801390: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801394: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80801398: bnel        $t8, $zero, L_8080161C
    if (ctx->r24 != 0) {
        // 0x8080139C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080161C;
    }
    goto skip_2;
    // 0x8080139C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x808013A0: lh          $t9, 0x28($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X28);
    // 0x808013A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808013A8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808013AC: bne         $t9, $zero, L_808013C8
    if (ctx->r25 != 0) {
        // 0x808013B0: addiu       $a1, $zero, 0x1631
        ctx->r5 = ADD32(0, 0X1631);
            goto L_808013C8;
    }
    // 0x808013B0: addiu       $a1, $zero, 0x1631
    ctx->r5 = ADD32(0, 0X1631);
    // 0x808013B4: sh          $t0, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r8;
    // 0x808013B8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x808013BC: jal         0x80803158
    // 0x808013C0: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    func_80803158_chklungo(rdram, ctx);
        goto after_9;
    // 0x808013C0: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_9:
    // 0x808013C4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_808013C8:
    // 0x808013C8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808013CC: jal         0x80801964
    // 0x808013D0: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_80801964_chklungo(rdram, ctx);
        goto after_10;
    // 0x808013D0: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_10:
    // 0x808013D4: b           L_8080161C
    // 0x808013D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080161C;
    // 0x808013D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808013DC:
    // 0x808013DC: lh          $t1, 0x1A($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1A);
    // 0x808013E0: beql        $t1, $zero, L_808013F4
    if (ctx->r9 == 0) {
        // 0x808013E4: lh          $t2, 0x1C($v0)
        ctx->r10 = MEM_H(ctx->r2, 0X1C);
            goto L_808013F4;
    }
    goto skip_3;
    // 0x808013E4: lh          $t2, 0x1C($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X1C);
    skip_3:
    // 0x808013E8: b           L_8080161C
    // 0x808013EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080161C;
    // 0x808013EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808013F0: lh          $t2, 0x1C($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X1C);
L_808013F4:
    // 0x808013F4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808013F8: bnel        $t2, $zero, L_8080142C
    if (ctx->r10 != 0) {
        // 0x808013FC: lh          $t3, 0x1C($v1)
        ctx->r11 = MEM_H(ctx->r3, 0X1C);
            goto L_8080142C;
    }
    goto skip_4;
    // 0x808013FC: lh          $t3, 0x1C($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X1C);
    skip_4:
    // 0x80801400: jal         0x80802558
    // 0x80801404: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80802558_chklungo(rdram, ctx);
        goto after_11;
    // 0x80801404: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_11:
    // 0x80801408: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080140C: jal         0x80801964
    // 0x80801410: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    func_80801964_chklungo(rdram, ctx);
        goto after_12;
    // 0x80801410: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_12:
    // 0x80801414: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801418: jal         0x8010A800
    // 0x8080141C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_13;
    // 0x8080141C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80801420: b           L_8080161C
    // 0x80801424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080161C;
    // 0x80801424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801428: lh          $t3, 0x1C($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X1C);
L_8080142C:
    // 0x8080142C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801430: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801434: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80801438: jal         0x80108B04
    // 0x8080143C: sh          $t4, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r12;
    func_80108B04(rdram, ctx);
        goto after_14;
    // 0x8080143C: sh          $t4, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r12;
    after_14:
    // 0x80801440: b           L_8080161C
    // 0x80801444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080161C;
    // 0x80801444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801448:
    // 0x80801448: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1240, 0X3A3C) << 16);
    // 0x8080144C: addiu       $a0, $a0, 0x3A3C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1240, 0X3A3C));
    // 0x80801450: jal         0x80088090
    // 0x80801454: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x80801454: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_15:
    // 0x80801458: b           L_8080161C
    // 0x8080145C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080161C;
    // 0x8080145C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801460:
    // 0x80801460: lh          $t5, 0x40($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X40);
    // 0x80801464: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801468: bnel        $t5, $zero, L_8080161C
    if (ctx->r13 != 0) {
        // 0x8080146C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080161C;
    }
    goto skip_5;
    // 0x8080146C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_5:
    // 0x80801470: jal         0x80801964
    // 0x80801474: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80801964_chklungo(rdram, ctx);
        goto after_16;
    // 0x80801474: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_16:
    // 0x80801478: b           L_8080161C
    // 0x8080147C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080161C;
    // 0x8080147C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801480:
    // 0x80801480: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801484: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80801488: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8080148C: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80801490: and         $t7, $a2, $at
    ctx->r15 = ctx->r6 & ctx->r1;
    // 0x80801494: srl         $a2, $t7, 16
    ctx->r6 = S32(U32(ctx->r15) >> 16);
    // 0x80801498: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8080149C: jal         0x80801848
    // 0x808014A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80801848_chklungo(rdram, ctx);
        goto after_17;
    // 0x808014A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_17:
    // 0x808014A4: b           L_80801620
    // 0x808014A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801620;
    // 0x808014A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808014AC:
    // 0x808014AC: lh          $t9, 0x8($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X8);
    // 0x808014B0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1240, 0X38A6) << 16);
    // 0x808014B4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x808014B8: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x808014BC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x808014C0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808014C4: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x808014C8: lhu         $a1, 0x38A6($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1240, 0X38A6));
    // 0x808014CC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x808014D0: jal         0x801032B0
    // 0x808014D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_801032B0(rdram, ctx);
        goto after_18;
    // 0x808014D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x808014D8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808014DC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808014E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808014E4: lh          $t1, 0x2A($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X2A);
    // 0x808014E8: beq         $t1, $zero, L_80801508
    if (ctx->r9 == 0) {
        // 0x808014EC: nop
    
            goto L_80801508;
    }
    // 0x808014EC: nop

    // 0x808014F0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x808014F4: jal         0x800FDC28
    // 0x808014F8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800FDC28(rdram, ctx);
        goto after_19;
    // 0x808014F8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_19:
    // 0x808014FC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801500: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80801504: sh          $zero, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = 0;
L_80801508:
    // 0x80801508: jal         0x80089F60
    // 0x8080150C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_20;
    // 0x8080150C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_20:
    // 0x80801510: b           L_8080161C
    // 0x80801514: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080161C;
    // 0x80801514: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801518:
    // 0x80801518: lh          $t2, 0x1A($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X1A);
    // 0x8080151C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801524: bnel        $t2, $zero, L_8080161C
    if (ctx->r10 != 0) {
        // 0x80801528: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080161C;
    }
    goto skip_6;
    // 0x80801528: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_6:
    // 0x8080152C: jal         0x800897C0
    // 0x80801530: addiu       $a2, $zero, 0xAB
    ctx->r6 = ADD32(0, 0XAB);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_21;
    // 0x80801530: addiu       $a2, $zero, 0xAB
    ctx->r6 = ADD32(0, 0XAB);
    after_21:
    // 0x80801534: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80801538: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080153C: lui         $a1, 0x428C
    ctx->r5 = S32(0X428C << 16);
    // 0x80801540: jal         0x800897E8
    // 0x80801544: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_22;
    // 0x80801544: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_22:
    // 0x80801548: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080154C: jal         0x80089810
    // 0x80801550: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_23;
    // 0x80801550: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_23:
    // 0x80801554: b           L_8080161C
    // 0x80801558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080161C;
    // 0x80801558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080155C:
    // 0x8080155C: lh          $t3, 0x1A($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X1A);
    // 0x80801560: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801564: bnel        $t3, $zero, L_8080161C
    if (ctx->r11 != 0) {
        // 0x80801568: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080161C;
    }
    goto skip_7;
    // 0x80801568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_7:
    // 0x8080156C: jal         0x800897C8
    // 0x80801570: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_24;
    // 0x80801570: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80801574: b           L_8080161C
    // 0x80801578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080161C;
    // 0x80801578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080157C:
    // 0x8080157C: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80801580: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801584: jal         0x808010E0
    // 0x80801588: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_808010E0_chklungo(rdram, ctx);
        goto after_25;
    // 0x80801588: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_25:
    // 0x8080158C: b           L_8080161C
    // 0x80801590: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080161C;
    // 0x80801590: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801594:
    // 0x80801594: lh          $t4, 0x1A($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X1A);
    // 0x80801598: bne         $t4, $zero, L_808015B0
    if (ctx->r12 != 0) {
        // 0x8080159C: nop
    
            goto L_808015B0;
    }
    // 0x8080159C: nop

    // 0x808015A0: jal         0x800D395C
    // 0x808015A4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800D395C(rdram, ctx);
        goto after_26;
    // 0x808015A4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_26:
    // 0x808015A8: bne         $v0, $zero, L_808015B8
    if (ctx->r2 != 0) {
        // 0x808015AC: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_808015B8;
    }
    // 0x808015AC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_808015B0:
    // 0x808015B0: b           L_8080161C
    // 0x808015B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080161C;
    // 0x808015B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808015B8:
    // 0x808015B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808015BC: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x808015C0: jal         0x80803158
    // 0x808015C4: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    func_80803158_chklungo(rdram, ctx);
        goto after_27;
    // 0x808015C4: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    after_27:
    // 0x808015C8: b           L_8080161C
    // 0x808015CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080161C;
    // 0x808015CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808015D0: lh          $t5, 0x1A($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X1A);
L_808015D4:
    // 0x808015D4: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x808015D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808015DC: beq         $t5, $zero, L_808015F4
    if (ctx->r13 == 0) {
        // 0x808015E0: nop
    
            goto L_808015F4;
    }
    // 0x808015E0: nop

    // 0x808015E4: jal         0x80801964
    // 0x808015E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80801964_chklungo(rdram, ctx);
        goto after_28;
    // 0x808015E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_28:
    // 0x808015EC: b           L_8080161C
    // 0x808015F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080161C;
    // 0x808015F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808015F4:
    // 0x808015F4: jal         0x800FDC28
    // 0x808015F8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800FDC28(rdram, ctx);
        goto after_29;
    // 0x808015F8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_29:
    // 0x808015FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801600: jal         0x80801964
    // 0x80801604: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80801964_chklungo(rdram, ctx);
        goto after_30;
    // 0x80801604: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_30:
    // 0x80801608: b           L_8080161C
    // 0x8080160C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080161C;
    // 0x8080160C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801610:
    // 0x80801610: b           L_8080161C
    // 0x80801614: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080161C;
    // 0x80801614: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801618: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080161C:
    // 0x8080161C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801620:
    // 0x80801620: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801624: jr          $ra
    // 0x80801628: nop

    return;
    // 0x80801628: nop

;}
RECOMP_FUNC void chdoubloon_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800274: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2256, 0X2A0) << 16);
    // 0x80800278: jr          $ra
    // 0x8080027C: addiu       $v0, $v0, 0x2A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2256, 0X2A0));
    return;
    // 0x8080027C: addiu       $v0, $v0, 0x2A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2256, 0X2A0));
;}
RECOMP_FUNC void func_800D27C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D27C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D27CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D27D0: jal         0x800D21D0
    // 0x800D27D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D21D0(rdram, ctx);
        goto after_0;
    // 0x800D27D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D27D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800D27DC: jal         0x800D21F0
    // 0x800D27E0: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    func_800D21F0(rdram, ctx);
        goto after_1;
    // 0x800D27E0: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    after_1:
    // 0x800D27E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D27E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D27EC: jr          $ra
    // 0x800D27F0: nop

    return;
    // 0x800D27F0: nop

;}
RECOMP_FUNC void func_80800000_chgoldfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x800DA298
    // 0x80800014: addiu       $a0, $zero, 0x1BF
    ctx->r4 = ADD32(0, 0X1BF);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a0, $zero, 0x1BF
    ctx->r4 = ADD32(0, 0X1BF);
    after_0:
    // 0x80800018: beq         $v0, $zero, L_80800030
    if (ctx->r2 == 0) {
        // 0x8080001C: nop
    
            goto L_80800030;
    }
    // 0x8080001C: nop

    // 0x80800020: jal         0x800FFA88
    // 0x80800024: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_1;
    // 0x80800024: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x80800028: b           L_8080008C
    // 0x8080002C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080008C;
    // 0x8080002C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800030:
    // 0x80800030: jal         0x800DA298
    // 0x80800034: addiu       $a0, $zero, 0x1DA
    ctx->r4 = ADD32(0, 0X1DA);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800034: addiu       $a0, $zero, 0x1DA
    ctx->r4 = ADD32(0, 0X1DA);
    after_2:
    // 0x80800038: beq         $v0, $zero, L_80800050
    if (ctx->r2 == 0) {
        // 0x8080003C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800050;
    }
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: jal         0x808005F0
    // 0x80800044: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808005F0_chgoldfish(rdram, ctx);
        goto after_3;
    // 0x80800044: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x80800048: b           L_8080006C
    // 0x8080004C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
        goto L_8080006C;
    // 0x8080004C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
L_80800050:
    // 0x80800050: jal         0x800DA298
    // 0x80800054: addiu       $a0, $zero, 0x51E
    ctx->r4 = ADD32(0, 0X51E);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800054: addiu       $a0, $zero, 0x51E
    ctx->r4 = ADD32(0, 0X51E);
    after_4:
    // 0x80800058: beq         $v0, $zero, L_80800068
    if (ctx->r2 == 0) {
        // 0x8080005C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800068;
    }
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: jal         0x808005F0
    // 0x80800064: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808005F0_chgoldfish(rdram, ctx);
        goto after_5;
    // 0x80800064: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
L_80800068:
    // 0x80800068: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
L_8080006C:
    // 0x8080006C: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800070: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800078: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080007C: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x80800080: jal         0x80800BA8
    // 0x80800084: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    func_80800BA8_chgoldfish(rdram, ctx);
        goto after_6;
    // 0x80800084: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    after_6:
    // 0x80800088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080008C:
    // 0x8080008C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800090: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void func_800C4B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4B90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C4B94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C4B98: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800C4B9C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C4BA0: jal         0x800A8984
    // 0x800C4BA4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_800A8984(rdram, ctx);
        goto after_0;
    // 0x800C4BA4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C4BA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C4BAC: jal         0x800A89A0
    // 0x800C4BB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800A89A0(rdram, ctx);
        goto after_1;
    // 0x800C4BB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800C4BB4: beq         $v0, $zero, L_800C4C24
    if (ctx->r2 == 0) {
        // 0x800C4BB8: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_800C4C24;
    }
    // 0x800C4BB8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4BBC: beq         $t6, $zero, L_800C4C24
    if (ctx->r14 == 0) {
        // 0x800C4BC0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800C4C24;
    }
    // 0x800C4BC0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C4BC4: jal         0x800A8AD4
    // 0x800C4BC8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800A8AD4(rdram, ctx);
        goto after_2;
    // 0x800C4BC8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x800C4BCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C4BD0: jal         0x80015D14
    // 0x800C4BD4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_80015D14(rdram, ctx);
        goto after_3;
    // 0x800C4BD4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800C4BD8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C4BDC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C4BE0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800C4BE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C4BE8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C4BEC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C4BF0: addiu       $v0, $v0, -0x5660
    ctx->r2 = ADD32(ctx->r2, -0X5660);
    // 0x800C4BF4: lwc1        $f18, 0x7C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x800C4BF8: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C4BFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C4C00: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C4C04: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800C4C08: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800C4C0C: lwc1        $f16, 0x78($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X78);
    // 0x800C4C10: swc1        $f4, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f4.u32l;
    // 0x800C4C14: lwc1        $f10, 0x5890($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5890);
    // 0x800C4C18: div.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C4C1C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800C4C20: swc1        $f4, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f4.u32l;
L_800C4C24:
    // 0x800C4C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C4C28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C4C2C: jr          $ra
    // 0x800C4C30: nop

    return;
    // 0x800C4C30: nop

;}
RECOMP_FUNC void baduo_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B68: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800B6C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800B70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B78: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800B7C: jal         0x800F911C
    // 0x80800B80: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800F911C(rdram, ctx);
        goto after_0;
    // 0x80800B80: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80800B84: jal         0x800F6224
    // 0x80800B88: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F6224(rdram, ctx);
        goto after_1;
    // 0x80800B88: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_1:
    // 0x80800B8C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800B90: jal         0x800F53D0
    // 0x80800B94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_2;
    // 0x80800B94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800B98: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BA0: jal         0x8009C128
    // 0x80800BA4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_3;
    // 0x80800BA4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80800BA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800BAC: jal         0x800F452C
    // 0x80800BB0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F452C(rdram, ctx);
        goto after_4;
    // 0x80800BB0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80800BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BB8: jal         0x800A3410
    // 0x80800BBC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800A3410(rdram, ctx);
        goto after_5;
    // 0x80800BBC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_5:
    // 0x80800BC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800BC4: jal         0x800A3410
    // 0x80800BC8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_800A3410(rdram, ctx);
        goto after_6;
    // 0x80800BC8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_6:
    // 0x80800BCC: jal         0x80092778
    // 0x80800BD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80092778(rdram, ctx);
        goto after_7;
    // 0x80800BD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80800BD4: jal         0x8009C984
    // 0x80800BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_8;
    // 0x80800BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800BDC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800BE0: jal         0x8009C914
    // 0x80800BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_9;
    // 0x80800BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800BE8: jal         0x8009C984
    // 0x80800BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_10;
    // 0x80800BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800BF0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800BF4: jal         0x8009C914
    // 0x80800BF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_11;
    // 0x80800BF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80800BFC: jal         0x8009C974
    // 0x80800C00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_12;
    // 0x80800C00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80800C04: jal         0x800F80D8
    // 0x80800C08: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800F80D8(rdram, ctx);
        goto after_13;
    // 0x80800C08: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_13:
    // 0x80800C0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800C10: jal         0x8009E5C8
    // 0x80800C14: addiu       $a1, $zero, 0x153
    ctx->r5 = ADD32(0, 0X153);
    bs_setState(rdram, ctx);
        goto after_14;
    // 0x80800C14: addiu       $a1, $zero, 0x153
    ctx->r5 = ADD32(0, 0X153);
    after_14:
    // 0x80800C18: jal         0x800A91A8
    // 0x80800C1C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800A91A8(rdram, ctx);
        goto after_15;
    // 0x80800C1C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_15:
    // 0x80800C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C24: jal         0x80800008
    // 0x80800C28: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800008_baduo(rdram, ctx);
        goto after_16;
    // 0x80800C28: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_16:
    // 0x80800C2C: jal         0x800F8EE4
    // 0x80800C30: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F8EE4(rdram, ctx);
        goto after_17;
    // 0x80800C30: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_17:
    // 0x80800C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C3C: jal         0x800A38F0
    // 0x80800C40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A38F0(rdram, ctx);
        goto after_18;
    // 0x80800C40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_18:
    // 0x80800C44: jal         0x800D5234
    // 0x80800C48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D5234(rdram, ctx);
        goto after_19;
    // 0x80800C48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x80800C4C: jal         0x800A16BC
    // 0x80800C50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A16BC(rdram, ctx);
        goto after_20;
    // 0x80800C50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_20:
    // 0x80800C54: jal         0x800A1694
    // 0x80800C58: nop

    func_800A1694(rdram, ctx);
        goto after_21;
    // 0x80800C58: nop

    after_21:
    // 0x80800C5C: jal         0x80084D88
    // 0x80800C60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bakaztorpedo_entrypoint_3(rdram, ctx);
        goto after_22;
    // 0x80800C60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x80800C64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C68: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800C6C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800C70: jr          $ra
    // 0x80800C74: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800C74: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800A2C_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A34: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800A38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A40: beq         $a1, $at, L_80800A9C
    if (ctx->r5 == ctx->r1) {
        // 0x80800A44: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800A9C;
    }
    // 0x80800A44: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800A48: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800A4C: beq         $a1, $at, L_80800A70
    if (ctx->r5 == ctx->r1) {
        // 0x80800A50: addiu       $at, $zero, 0x44
        ctx->r1 = ADD32(0, 0X44);
            goto L_80800A70;
    }
    // 0x80800A50: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x80800A54: beq         $a1, $at, L_80800AB8
    if (ctx->r5 == ctx->r1) {
        // 0x80800A58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AB8;
    }
    // 0x80800A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A5C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800A60: beq         $a1, $at, L_80800AC8
    if (ctx->r5 == ctx->r1) {
        // 0x80800A64: nop
    
            goto L_80800AC8;
    }
    // 0x80800A64: nop

    // 0x80800A68: b           L_80800BBC
    // 0x80800A6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800BBC;
    // 0x80800A6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A70:
    // 0x80800A70: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x80800A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A78: srl         $t6, $a1, 7
    ctx->r14 = S32(U32(ctx->r5) >> 7);
    // 0x80800A7C: jal         0x8008A508
    // 0x80800A80: addiu       $a1, $t6, -0x2B
    ctx->r5 = ADD32(ctx->r14, -0X2B);
    _subaddietaxi_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800A80: addiu       $a1, $t6, -0x2B
    ctx->r5 = ADD32(ctx->r14, -0X2B);
    after_0:
    // 0x80800A84: beq         $v0, $zero, L_80800BB8
    if (ctx->r2 == 0) {
        // 0x80800A88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BB8;
    }
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A8C: jal         0x80102424
    // 0x80800A90: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800A90: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x80800A94: b           L_80800BBC
    // 0x80800A98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BBC;
    // 0x80800A98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A9C:
    // 0x80800A9C: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80800AA0: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800AA4: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800AA8: jal         0x80800BD0
    // 0x80800AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BD0_chterryegg(rdram, ctx);
        goto after_2;
    // 0x80800AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800AB0: b           L_80800BBC
    // 0x80800AB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BBC;
    // 0x80800AB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AB8:
    // 0x80800AB8: jal         0x80800E88
    // 0x80800ABC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800E88_chterryegg(rdram, ctx);
        goto after_3;
    // 0x80800ABC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800AC0: b           L_80800BBC
    // 0x80800AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BBC;
    // 0x80800AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AC8:
    // 0x80800AC8: jal         0x80088840
    // 0x80800ACC: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x80800ACC: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    after_4:
    // 0x80800AD0: beq         $v0, $zero, L_80800AE0
    if (ctx->r2 == 0) {
        // 0x80800AD4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AE0;
    }
    // 0x80800AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD8: jal         0x8008A4B0
    // 0x80800ADC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800ADC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_80800AE0:
    // 0x80800AE0: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x80800AE4: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800AE8: addiu       $a2, $a2, 0x6170
    ctx->r6 = ADD32(ctx->r6, 0X6170);
    // 0x80800AEC: srl         $t7, $a1, 7
    ctx->r15 = S32(U32(ctx->r5) >> 7);
    // 0x80800AF0: addiu       $a1, $t7, -0x2B
    ctx->r5 = ADD32(ctx->r15, -0X2B);
    // 0x80800AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF8: jal         0x8008A560
    // 0x80800AFC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _subaddietaxi_entrypoint_13(rdram, ctx);
        goto after_6;
    // 0x80800AFC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x80800B00: beql        $v0, $zero, L_80800B94
    if (ctx->r2 == 0) {
        // 0x80800B04: lw          $t7, 0x78($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X78);
            goto L_80800B94;
    }
    goto skip_0;
    // 0x80800B04: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    skip_0:
    // 0x80800B08: jal         0x80800C08
    // 0x80800B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C08_chterryegg(rdram, ctx);
        goto after_7;
    // 0x80800B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800B10: jal         0x80801138
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801138_chterryegg(rdram, ctx);
        goto after_8;
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800B18: beq         $v0, $zero, L_80800B5C
    if (ctx->r2 == 0) {
        // 0x80800B1C: nop
    
            goto L_80800B5C;
    }
    // 0x80800B1C: nop

    // 0x80800B20: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800B24: lbu         $t5, 0x75($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X75);
    // 0x80800B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B2C: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80800B30: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80800B34: lhu         $t2, 0x64($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X64);
    // 0x80800B38: andi        $t6, $t5, 0xFFEF
    ctx->r14 = ctx->r13 & 0XFFEF;
    // 0x80800B3C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800B40: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80800B44: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x80800B48: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80800B4C: jal         0x80102424
    // 0x80800B50: sb          $t7, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r15;
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800B50: sb          $t7, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r15;
    after_9:
    // 0x80800B54: b           L_80800BBC
    // 0x80800B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BBC;
    // 0x80800B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B5C:
    // 0x80800B5C: jal         0x8010A570
    // 0x80800B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_10;
    // 0x80800B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800B64: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800B68: lbu         $t5, 0x75($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X75);
    // 0x80800B6C: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x80800B70: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    // 0x80800B74: lhu         $t1, 0x64($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X64);
    // 0x80800B78: andi        $t4, $t5, 0xFFEF
    ctx->r12 = ctx->r13 & 0XFFEF;
    // 0x80800B7C: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80800B80: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x80800B84: or          $t6, $t3, $t4
    ctx->r14 = ctx->r11 | ctx->r12;
    // 0x80800B88: b           L_80800BB8
    // 0x80800B8C: sb          $t6, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r14;
        goto L_80800BB8;
    // 0x80800B8C: sb          $t6, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r14;
    // 0x80800B90: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
L_80800B94:
    // 0x80800B94: sll         $t9, $t7, 26
    ctx->r25 = S32(ctx->r15 << 26);
    // 0x80800B98: bgezl       $t9, L_80800BBC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800B9C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800BBC;
    }
    goto skip_1;
    // 0x80800B9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800BA0: jal         0x800FFAB0
    // 0x80800BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_11;
    // 0x80800BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800BA8: b           L_80800BBC
    // 0x80800BAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BBC;
    // 0x80800BAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800BB0: b           L_80800BBC
    // 0x80800BB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800BBC;
    // 0x80800BB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800BB8:
    // 0x80800BB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BBC:
    // 0x80800BBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800BC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800BC8: jr          $ra
    // 0x80800BCC: nop

    return;
    // 0x80800BCC: nop

;}
RECOMP_FUNC void func_80800138_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800138: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080013C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800140: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800144: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800148: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080014C: jal         0x800F5898
    // 0x80800150: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_0;
    // 0x80800150: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x80800154: blezl       $v0, L_8080018C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800158: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080018C;
    }
    goto skip_0;
    // 0x80800158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8080015C:
    // 0x8080015C: jal         0x800F6BE4
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6BE4(rdram, ctx);
        goto after_1;
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800164: beq         $v0, $zero, L_80800174
    if (ctx->r2 == 0) {
        // 0x80800168: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800174;
    }
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080016C: jal         0x800F7F98
    // 0x80800170: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F7F98(rdram, ctx);
        goto after_2;
    // 0x80800170: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
L_80800174:
    // 0x80800174: jal         0x800F5898
    // 0x80800178: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800F5898(rdram, ctx);
        goto after_3;
    // 0x80800178: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_3:
    // 0x8080017C: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800180: bne         $at, $zero, L_8080015C
    if (ctx->r1 != 0) {
        // 0x80800184: nop
    
            goto L_8080015C;
    }
    // 0x80800184: nop

    // 0x80800188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080018C:
    // 0x8080018C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800190: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800194: jr          $ra
    // 0x80800198: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800198: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800000_bsdrone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80084800
    // 0x8080000C: nop

    _badrone_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(160, 0X180) << 16);
    // 0x80800014: lbu         $t6, 0x180($t6)
    ctx->r14 = MEM_BU(ctx->r14, (int16_t)RELOC_LO16(160, 0X180));
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080001C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(160, 0X180) << 16);
    // 0x80800020: beq         $t6, $zero, L_80800054
    if (ctx->r14 == 0) {
        // 0x80800024: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800054;
    }
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800028: addiu       $v1, $t7, 0x180
    ctx->r3 = ADD32(ctx->r15, (int16_t)RELOC_LO16(160, 0X180));
    // 0x8080002C: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
L_80800030:
    // 0x80800030: bnel        $v0, $a0, L_80800044
    if (ctx->r2 != ctx->r4) {
        // 0x80800034: lbu         $a0, 0x14($v1)
        ctx->r4 = MEM_BU(ctx->r3, 0X14);
            goto L_80800044;
    }
    goto skip_0;
    // 0x80800034: lbu         $a0, 0x14($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X14);
    skip_0:
    // 0x80800038: b           L_80800058
    // 0x8080003C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_80800058;
    // 0x8080003C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80800040: lbu         $a0, 0x14($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X14);
L_80800044:
    // 0x80800044: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800048: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // 0x8080004C: bne         $a0, $zero, L_80800030
    if (ctx->r4 != 0) {
        // 0x80800050: nop
    
            goto L_80800030;
    }
    // 0x80800050: nop

L_80800054:
    // 0x80800054: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800058:
    // 0x80800058: jr          $ra
    // 0x8080005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8080005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800058_chlaundry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8080005C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800060: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800064: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800068: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080006C: jal         0x80100094
    // 0x80800070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800074: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800078: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8080007C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800080: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800084: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800088: nop

    // 0x8080008C: bc1fl       L_808000C0
    if (!c1cs) {
        // 0x80800090: addiu       $t7, $s0, 0x4
        ctx->r15 = ADD32(ctx->r16, 0X4);
            goto L_808000C0;
    }
    goto skip_0;
    // 0x80800090: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80800094: jal         0x800B5BE4
    // 0x80800098: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_800B5BE4(rdram, ctx);
        goto after_1;
    // 0x80800098: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_1:
    // 0x8080009C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2140, 0X488) << 16);
    // 0x808000A0: addiu       $t6, $t6, 0x488
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2140, 0X488));
    // 0x808000A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000AC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808000B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000B4: jal         0x800BABB8
    // 0x808000B8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x808000B8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x808000BC: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
L_808000C0:
    // 0x808000C0: jal         0x800D8FF8
    // 0x808000C4: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x808000C4: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    after_3:
    // 0x808000C8: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x808000CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000D0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x808000D4: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808000D8: lwc1        $f16, 0x18($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X18);
    // 0x808000DC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808000E0: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x808000E4: jal         0x800EC3E8
    // 0x808000E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800EC3E8(rdram, ctx);
        goto after_4;
    // 0x808000E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x808000EC: jal         0x800AF5A0
    // 0x808000F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800AF5A0(rdram, ctx);
        goto after_5;
    // 0x808000F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808000F4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x808000F8: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808000FC: jal         0x800F13C4
    // 0x80800100: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_800F13C4(rdram, ctx);
        goto after_6;
    // 0x80800100: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_6:
    // 0x80800104: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80800108: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800110: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    // 0x80800114: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80800118: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8080011C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80800120: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x80800124: lbu         $t6, 0xA($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XA);
    // 0x80800128: andi        $t7, $t6, 0xFF07
    ctx->r15 = ctx->r14 & 0XFF07;
    // 0x8080012C: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80800130: sb          $t8, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r24;
    // 0x80800134: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80800138: jal         0x8010A590
    // 0x8080013C: sh          $zero, 0x20($t9)
    MEM_H(0X20, ctx->r25) = 0;
    func_8010A590(rdram, ctx);
        goto after_7;
    // 0x8080013C: sh          $zero, 0x20($t9)
    MEM_H(0X20, ctx->r25) = 0;
    after_7:
    // 0x80800140: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800144: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800148: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8080014C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80800150: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800154: jal         0x800CD820
    // 0x80800158: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    func_800CD820(rdram, ctx);
        goto after_8;
    // 0x80800158: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_8:
    // 0x8080015C: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800160: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800164: beq         $v0, $zero, L_80800174
    if (ctx->r2 == 0) {
        // 0x80800168: sw          $t0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r8;
            goto L_80800174;
    }
    // 0x80800168: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8080016C: jal         0x80088610
    // 0x80800170: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _glhittableDll_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80800170: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_9:
L_80800174:
    // 0x80800174: jal         0x8010A570
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_10;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080017C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800180: jal         0x800EE7F8
    // 0x80800184: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x80800184: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_11:
    // 0x80800188: lui         $a1, 0x10
    ctx->r5 = S32(0X10 << 16);
    // 0x8080018C: ori         $a1, $a1, 0x4
    ctx->r5 = ctx->r5 | 0X4;
    // 0x80800190: jal         0x8010B990
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_12;
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800198: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8080019C: bne         $v0, $at, L_808001B4
    if (ctx->r2 != ctx->r1) {
        // 0x808001A0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808001B4;
    }
    // 0x808001A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808001A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808001A8: jal         0x8010AA78
    // 0x808001AC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    func_8010AA78(rdram, ctx);
        goto after_13;
    // 0x808001AC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_13:
    // 0x808001B0: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
L_808001B4:
    // 0x808001B4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x808001B8: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x808001BC: bnel        $t1, $zero, L_808001FC
    if (ctx->r9 != 0) {
        // 0x808001C0: lw          $t4, 0x3C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X3C);
            goto L_808001FC;
    }
    goto skip_1;
    // 0x808001C0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x808001C4: beql        $v1, $at, L_808001FC
    if (ctx->r3 == ctx->r1) {
        // 0x808001C8: lw          $t4, 0x3C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X3C);
            goto L_808001FC;
    }
    goto skip_2;
    // 0x808001C8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x808001CC: jal         0x8080000C
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080000C_chlaundry(rdram, ctx);
        goto after_14;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808001D4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808001D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001DC: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x808001E0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808001E4: lwc1        $f16, 0x4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X4);
    // 0x808001E8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x808001EC: nop

    // 0x808001F0: bc1fl       L_80800208
    if (!c1cs) {
        // 0x808001F4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800208;
    }
    goto skip_3;
    // 0x808001F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x808001F8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
L_808001FC:
    // 0x808001FC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800200: sb          $t3, 0x1($t4)
    MEM_B(0X1, ctx->r12) = ctx->r11;
    // 0x80800204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800208:
    // 0x80800208: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080020C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800210: jr          $ra
    // 0x80800214: nop

    return;
    // 0x80800214: nop

;}
RECOMP_FUNC void func_800F7C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7C58: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7C5C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7C60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7C64: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7C68: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7C6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7C70: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F7C74: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800F7C78: jal         0x8009AD20
    // 0x800F7C7C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009AD20(rdram, ctx);
        goto after_0;
    // 0x800F7C7C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F7C80: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7C84: jal         0x8009E7C8
    // 0x800F7C88: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009E7C8(rdram, ctx);
        goto after_1;
    // 0x800F7C88: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800F7C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7C90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F7C94: jr          $ra
    // 0x800F7C98: nop

    return;
    // 0x800F7C98: nop

;}
RECOMP_FUNC void func_808000A4_glglobalsettings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808000AC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808000B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000B4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808000B8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x808000BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000C0: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x808000C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808000C8:
    // 0x808000C8: jal         0x800884B0
    // 0x808000CC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _glgamestore_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808000CC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x808000D0: beq         $v0, $zero, L_808000E4
    if (ctx->r2 == 0) {
        // 0x808000D4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808000E4;
    }
    // 0x808000D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808000D8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x808000DC: bnel        $s0, $zero, L_808000C8
    if (ctx->r16 != 0) {
        // 0x808000E0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808000C8;
    }
    goto skip_0;
    // 0x808000E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_808000E4:
    // 0x808000E4: beq         $v0, $zero, L_808000F8
    if (ctx->r2 == 0) {
        // 0x808000E8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808000F8;
    }
    // 0x808000E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000EC: jal         0x800885C8
    // 0x808000F0: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    _glglobaldata_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808000F0: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_1:
    // 0x808000F4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_808000F8:
    // 0x808000F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800100: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800104: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800108: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080010C: jr          $ra
    // 0x80800110: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800110: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void subaddierouteDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800624: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800628: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x8080062C: andi        $t6, $a2, 0x4
    ctx->r14 = ctx->r6 & 0X4;
    // 0x80800630: beq         $t6, $zero, L_80800654
    if (ctx->r14 == 0) {
        // 0x80800634: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80800654;
    }
    // 0x80800634: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800638: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080063C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80800640: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800644: jal         0x808005B0
    // 0x80800648: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_808005B0_subaddierouteDll(rdram, ctx);
        goto after_0;
    // 0x80800648: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8080064C: b           L_80800668
    // 0x80800650: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800668;
    // 0x80800650: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800654:
    // 0x80800654: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800658: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8080065C: jal         0x80102BF8
    // 0x80800660: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_80102BF8(rdram, ctx);
        goto after_1;
    // 0x80800660: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80800664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800668:
    // 0x80800668: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080066C: jr          $ra
    // 0x80800670: nop

    return;
    // 0x80800670: nop

;}
RECOMP_FUNC void func_808001DC_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001E4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808001E8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808001EC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808001F0: jal         0x800EA05C
    // 0x808001F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808001F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x808001F8: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1700, 0X247C) << 16);
    // 0x808001FC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800200: addiu       $s0, $s0, 0x247C
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1700, 0X247C));
    // 0x80800204: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800208: addiu       $s3, $zero, 0x7
    ctx->r19 = ADD32(0, 0X7);
L_8080020C:
    // 0x8080020C: jal         0x8080000C
    // 0x80800210: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8080000C_chchuffy(rdram, ctx);
        goto after_1;
    // 0x80800210: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800214: bne         $v0, $s2, L_80800234
    if (ctx->r2 != ctx->r18) {
        // 0x80800218: nop
    
            goto L_80800234;
    }
    // 0x80800218: nop

    // 0x8080021C: jal         0x800DA544
    // 0x80800220: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800220: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_2:
    // 0x80800224: jal         0x800DA524
    // 0x80800228: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    func_800DA524(rdram, ctx);
        goto after_3;
    // 0x80800228: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    after_3:
    // 0x8080022C: b           L_80800240
    // 0x80800230: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80800240;
    // 0x80800230: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800234:
    // 0x80800234: jal         0x800DA524
    // 0x80800238: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_800DA524(rdram, ctx);
        goto after_4;
    // 0x80800238: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_4:
    // 0x8080023C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800240:
    // 0x80800240: bne         $s1, $s3, L_8080020C
    if (ctx->r17 != ctx->r19) {
        // 0x80800244: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_8080020C;
    }
    // 0x80800244: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80800248: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080024C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800250: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800254: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800258: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8080025C: jr          $ra
    // 0x80800260: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800260: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800D3C_chpoolkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D40: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D48: bne         $a1, $at, L_80800D60
    if (ctx->r5 != ctx->r1) {
        // 0x80800D4C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800D60;
    }
    // 0x80800D4C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800D50: jal         0x80800D74
    // 0x80800D54: nop

    func_80800D74_chpoolkids(rdram, ctx);
        goto after_0;
    // 0x80800D54: nop

    after_0:
    // 0x80800D58: b           L_80800D64
    // 0x80800D5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D64;
    // 0x80800D5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D60:
    // 0x80800D60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D64:
    // 0x80800D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D6C: jr          $ra
    // 0x80800D70: nop

    return;
    // 0x80800D70: nop

;}
RECOMP_FUNC void dbvpl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lw          $v1, 0x2C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X2C);
    // 0x80800004: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800008: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080000C: blez        $v1, L_80800040
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80800010: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80800040;
    }
    // 0x80800010: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_80800014:
    // 0x80800014: lw          $t6, 0x30($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X30);
    // 0x80800018: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8080001C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800020: addu        $a1, $t6, $a0
    ctx->r5 = ADD32(ctx->r14, ctx->r4);
    // 0x80800024: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80800028: bne         $a3, $t7, L_80800038
    if (ctx->r7 != ctx->r15) {
        // 0x8080002C: nop
    
            goto L_80800038;
    }
    // 0x8080002C: nop

    // 0x80800030: jr          $ra
    // 0x80800034: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x80800034: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80800038:
    // 0x80800038: bne         $at, $zero, L_80800014
    if (ctx->r1 != 0) {
        // 0x8080003C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80800014;
    }
    // 0x8080003C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_80800040:
    // 0x80800040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800044: jr          $ra
    // 0x80800048: nop

    return;
    // 0x80800048: nop

;}
RECOMP_FUNC void chmusicmenu_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080123C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1824, 0X160C) << 16);
    // 0x80801240: jr          $ra
    // 0x80801244: addiu       $v0, $v0, 0x160C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1824, 0X160C));
    return;
    // 0x80801244: addiu       $v0, $v0, 0x160C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1824, 0X160C));
    // 0x80801248: nop

    // 0x8080124C: nop

;}
RECOMP_FUNC void chfiregen_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C14: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1588, 0X184C) << 16);
    // 0x80800C18: jr          $ra
    // 0x80800C1C: addiu       $v0, $v0, 0x184C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X184C));
    return;
    // 0x80800C1C: addiu       $v0, $v0, 0x184C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X184C));
;}
RECOMP_FUNC void bsbwhirl_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800598: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080059C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808005A4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x808005A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005AC: jal         0x80098140
    // 0x808005B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bainput_enable(rdram, ctx);
        goto after_0;
    // 0x808005B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x808005B4: jal         0x8008CABC
    // 0x808005B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_1;
    // 0x808005B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808005BC: jal         0x8008B324
    // 0x808005C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_2;
    // 0x808005C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808005C4: beq         $v0, $zero, L_808005D0
    if (ctx->r2 == 0) {
        // 0x808005C8: addiu       $t6, $zero, 0x1B
        ctx->r14 = ADD32(0, 0X1B);
            goto L_808005D0;
    }
    // 0x808005C8: addiu       $t6, $zero, 0x1B
    ctx->r14 = ADD32(0, 0X1B);
    // 0x808005CC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_808005D0:
    // 0x808005D0: jal         0x80800008
    // 0x808005D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800008_bsbwhirl(rdram, ctx);
        goto after_3;
    // 0x808005D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808005D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808005DC: jal         0x8009E5C8
    // 0x808005E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x808005E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x808005E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005EC: jr          $ra
    // 0x808005F0: nop

    return;
    // 0x808005F0: nop

;}
RECOMP_FUNC void func_800F6E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6E40: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6E44: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6E48: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6E4C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F6E50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F6E54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6E58: jal         0x8009E6F8
    // 0x800F6E5C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x800F6E5C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F6E60: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F6E64: jal         0x8009CBDC
    // 0x800F6E68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8009CBDC(rdram, ctx);
        goto after_1;
    // 0x800F6E68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800F6E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6E70: xori        $t7, $v0, 0x13
    ctx->r15 = ctx->r2 ^ 0X13;
    // 0x800F6E74: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800F6E78: jr          $ra
    // 0x800F6E7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F6E7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void chnicecavemen_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1096, 0X1B34) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0x1B34
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1096, 0X1B34));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0x1B34
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1096, 0X1B34));
;}
RECOMP_FUNC void sumumbofx_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800FF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800FF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800FFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801000: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801004: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801008: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8080100C: jal         0x800EE830
    // 0x80801010: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    func_800EE830(rdram, ctx);
        goto after_0;
    // 0x80801010: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_0:
    // 0x80801014: jal         0x800C8A98
    // 0x80801018: nop

    func_800C8A98(rdram, ctx);
        goto after_1;
    // 0x80801018: nop

    after_1:
    // 0x8080101C: sh          $v0, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r2;
    // 0x80801020: jal         0x80800F8C
    // 0x80801024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F8C_sumumbofx(rdram, ctx);
        goto after_2;
    // 0x80801024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080102C: jal         0x80800F6C
    // 0x80801030: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    sumumbofx_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80801030: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80801034: lh          $a0, 0x5E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X5E);
    // 0x80801038: jal         0x800C8D4C
    // 0x8080103C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800C8D4C(rdram, ctx);
        goto after_4;
    // 0x8080103C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80801040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801044: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801048: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080104C: jr          $ra
    // 0x80801050: nop

    return;
    // 0x80801050: nop

;}
RECOMP_FUNC void func_808004D0_chhellterskelter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004D8: jal         0x80105494
    // 0x808004DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x808004DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808004E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(964, 0X7A8) << 16);
    // 0x808004E4: lwc1        $f4, 0x7A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(964, 0X7A8));
    // 0x808004E8: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x808004EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(964, 0X7AC) << 16);
    // 0x808004F0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808004F4: nop

    // 0x808004F8: bc1tl       L_80800534
    if (c1cs) {
        // 0x808004FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800534;
    }
    goto skip_0;
    // 0x808004FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800500: jal         0x800DC298
    // 0x80800504: lwc1        $f12, 0x7AC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(964, 0X7AC));
    func_800DC298(rdram, ctx);
        goto after_1;
    // 0x80800504: lwc1        $f12, 0x7AC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(964, 0X7AC));
    after_1:
    // 0x80800508: beq         $v0, $zero, L_80800530
    if (ctx->r2 == 0) {
        // 0x8080050C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800530;
    }
    // 0x8080050C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800510: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(964, 0X8C0) << 16);
    // 0x80800514: addiu       $t6, $t6, 0x8C0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(964, 0X8C0));
    // 0x80800518: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080051C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800524: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800528: jal         0x800BBCB8
    // 0x8080052C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x8080052C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
L_80800530:
    // 0x80800530: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800534:
    // 0x80800534: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800538: jr          $ra
    // 0x8080053C: nop

    return;
    // 0x8080053C: nop

;}
RECOMP_FUNC void _bswalk_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800841F0: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x800841F0);
    return;
    // 0x800841F4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void gccubeDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800824: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800828: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080082C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800830: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800834: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800838: jal         0x80800230
    // 0x8080083C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800230_gccubeDll(rdram, ctx);
        goto after_0;
    // 0x8080083C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800840: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800844: jal         0x800825C8
    // 0x80800848: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80800848: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080084C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800850: jal         0x80800868
    // 0x80800854: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80800868_gccubeDll(rdram, ctx);
        goto after_2;
    // 0x80800854: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080085C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800860: jr          $ra
    // 0x80800864: nop

    return;
    // 0x80800864: nop

;}
RECOMP_FUNC void func_80103D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103D00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103D04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103D08: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80103D0C: jal         0x80103B24
    // 0x80103D10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103B24(rdram, ctx);
        goto after_0;
    // 0x80103D10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80103D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103D18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103D1C: jr          $ra
    // 0x80103D20: nop

    return;
    // 0x80103D20: nop

;}
RECOMP_FUNC void func_80801254_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801258: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080125C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801260: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80801264: jal         0x80088078
    // 0x80801268: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80801268: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x8080126C: beq         $v0, $zero, L_80801298
    if (ctx->r2 == 0) {
        // 0x80801270: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801298;
    }
    // 0x80801270: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801274: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
    // 0x80801278: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080127C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801280: beq         $t6, $at, L_80801290
    if (ctx->r14 == ctx->r1) {
        // 0x80801284: nop
    
            goto L_80801290;
    }
    // 0x80801284: nop

    // 0x80801288: jal         0x80801C9C
    // 0x8080128C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80801C9C_chaliendad(rdram, ctx);
        goto after_1;
    // 0x8080128C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_80801290:
    // 0x80801290: b           L_8080129C
    // 0x80801294: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8080129C;
    // 0x80801294: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80801298:
    // 0x80801298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080129C:
    // 0x8080129C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808012A4: jr          $ra
    // 0x808012A8: nop

    return;
    // 0x808012A8: nop

;}
RECOMP_FUNC void func_800DE2A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE2A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800DE2A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800DE2AC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800DE2B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DE2B4: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800DE2B8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800DE2BC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800DE2C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DE2C4: addiu       $s2, $s2, -0x3074
    ctx->r18 = ADD32(ctx->r18, -0X3074);
L_800DE2C8:
    // 0x800DE2C8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800DE2CC: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800DE2D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DE2D4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800DE2D8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800DE2DC: lw          $t9, 0x0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X0);
    // 0x800DE2E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800DE2E4: jalr        $t9
    // 0x800DE2E8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800DE2E8: nop

    after_0:
    // 0x800DE2EC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800DE2F0: beql        $v0, $zero, L_800DE304
    if (ctx->r2 == 0) {
        // 0x800DE2F4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800DE304;
    }
    goto skip_0;
    // 0x800DE2F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800DE2F8: b           L_800DE2C8
    // 0x800DE2FC: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
        goto L_800DE2C8;
    // 0x800DE2FC: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800DE300: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800DE304:
    // 0x800DE304: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DE308: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800DE30C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800DE310: jr          $ra
    // 0x800DE314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800DE314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bamovespline_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084EA0: syscall     140
    recomp_syscall_handler(rdram, ctx, 0x80084EA0);
    return;
    // 0x80084EA4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _chusefeather_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085940: syscall     182
    recomp_syscall_handler(rdram, ctx, 0x80085940);
    return;
    // 0x80085944: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
