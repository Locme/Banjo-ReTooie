#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _badrone_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800848E8: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x800848E8);
    return;
    // 0x800848EC: addi        $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
;}
RECOMP_FUNC void func_808002D4_chtimetable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002DC: jal         0x808000B0
    // 0x808002E0: nop

    func_808000B0_chtimetable(rdram, ctx);
        goto after_0;
    // 0x808002E0: nop

    after_0:
    // 0x808002E4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x808002E8: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x808002EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808002F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1592, 0X738) << 16);
    // 0x808002F8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808002FC: lw          $v0, 0x738($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(1592, 0X738));
    // 0x80800300: jr          $ra
    // 0x80800304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void gclevel_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C0: jal         0x800A824C
    // 0x808000C4: nop

    func_800A824C(rdram, ctx);
        goto after_0;
    // 0x808000C4: nop

    after_0:
    // 0x808000C8: bnel        $v0, $zero, L_808000FC
    if (ctx->r2 != 0) {
        // 0x808000CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000FC;
    }
    goto skip_0;
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000D0: jal         0x8009E9A0
    // 0x808000D4: nop

    func_8009E9A0(rdram, ctx);
        goto after_1;
    // 0x808000D4: nop

    after_1:
    // 0x808000D8: jal         0x800CF2B0
    // 0x808000DC: nop

    func_800CF2B0(rdram, ctx);
        goto after_2;
    // 0x808000DC: nop

    after_2:
    // 0x808000E0: jal         0x800CE7DC
    // 0x808000E4: nop

    func_800CE7DC(rdram, ctx);
        goto after_3;
    // 0x808000E4: nop

    after_3:
    // 0x808000E8: jal         0x80087838
    // 0x808000EC: nop

    _cosectionstor_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x808000EC: nop

    after_4:
    // 0x808000F0: jal         0x800C75C0
    // 0x808000F4: nop

    func_800C75C0(rdram, ctx);
        goto after_5;
    // 0x808000F4: nop

    after_5:
    // 0x808000F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000FC:
    // 0x808000FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800100: jr          $ra
    // 0x80800104: nop

    return;
    // 0x80800104: nop

;}
RECOMP_FUNC void func_80800980_chflowerbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800980: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800984: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800988: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080098C: jal         0x80101E4C
    // 0x80800990: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80101E4C(rdram, ctx);
        goto after_0;
    // 0x80800990: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800994: beql        $v0, $zero, L_808009E0
    if (ctx->r2 == 0) {
        // 0x80800998: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808009E0;
    }
    goto skip_0;
    // 0x80800998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080099C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x808009A0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808009A4: bne         $a0, $zero, L_808009D4
    if (ctx->r4 != 0) {
        // 0x808009A8: nop
    
            goto L_808009D4;
    }
    // 0x808009A8: nop

    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B0: jal         0x80089D10
    // 0x808009B4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _subaddieaudioquick_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808009B4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x808009B8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808009BC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1388, 0XD28) << 16);
    // 0x808009C0: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
    // 0x808009C4: addiu       $a2, $a2, 0xD28
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1388, 0XD28));
    // 0x808009C8: jal         0x800C4350
    // 0x808009CC: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    func_800C4350(rdram, ctx);
        goto after_2;
    // 0x808009CC: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    after_2:
    // 0x808009D0: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
L_808009D4:
    // 0x808009D4: jal         0x800C3BDC
    // 0x808009D8: nop

    func_800C3BDC(rdram, ctx);
        goto after_3;
    // 0x808009D8: nop

    after_3:
    // 0x808009DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009E0:
    // 0x808009E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009E8: jr          $ra
    // 0x808009EC: nop

    return;
    // 0x808009EC: nop

;}
RECOMP_FUNC void func_80801848_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080184C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801850: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801854: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801858: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080185C: jal         0x80100094
    // 0x80801860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801864: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801868: addiu       $a1, $v0, 0x88
    ctx->r5 = ADD32(ctx->r2, 0X88);
    // 0x8080186C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80801870: jal         0x8008A2B8
    // 0x80801874: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    _susubgame_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80801874: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80801878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080187C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801880: jr          $ra
    // 0x80801884: nop

    return;
    // 0x80801884: nop

;}
RECOMP_FUNC void bsbbarge_setSubstate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800018: beq         $at, $zero, L_80800164
    if (ctx->r1 == 0) {
        // 0x8080001C: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80800164;
    }
    // 0x8080001C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800020: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800024: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(57, 0X600) << 16);
    // 0x80800028: addu        $at, $at, $t7
    gpr jr_addend_80800030 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080002C: lw          $t7, 0x600($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(57, 0X600));
    // 0x80800030: jr          $t7
    // 0x80800034: nop

    switch (jr_addend_80800030 >> 2) {
        case 0: goto L_80800164; break;
        case 1: goto L_80800038; break;
        case 2: goto L_80800090; break;
        case 3: goto L_80800118; break;
        case 4: goto L_80800148; break;
        default: switch_error(__func__, 0x80800030, 0x80800600);
    }
    // 0x80800034: nop

L_80800038:
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080003C: jal         0x80095748
    // 0x80800040: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    baflag_isFalse(rdram, ctx);
        goto after_0;
    // 0x80800040: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x80800044: beq         $v0, $zero, L_80800068
    if (ctx->r2 == 0) {
        // 0x80800048: lui         $at, 0x43FA
        ctx->r1 = S32(0X43FA << 16);
            goto L_80800068;
    }
    // 0x80800048: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800050: jal         0x80095760
    // 0x80800054: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    baflag_set(rdram, ctx);
        goto after_1;
    // 0x80800054: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_1:
    // 0x80800058: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(57, 0X614) << 16);
    // 0x8080005C: lwc1        $f4, 0x614($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(57, 0X614));
    // 0x80800060: b           L_80800074
    // 0x80800064: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
        goto L_80800074;
    // 0x80800064: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
L_80800068:
    // 0x80800068: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080006C: nop

    // 0x80800070: swc1        $f6, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f6.u32l;
L_80800074:
    // 0x80800074: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80800078: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: jal         0x80085338
    // 0x80800084: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_set(rdram, ctx);
        goto after_2;
    // 0x80800084: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800088: b           L_80800168
    // 0x8080008C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
        goto L_80800168;
    // 0x8080008C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_80800090:
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800094: jal         0x8009D2D8
    // 0x80800098: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D2D8(rdram, ctx);
        goto after_3;
    // 0x80800098: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080009C: lui         $a1, 0x3F10
    ctx->r5 = S32(0X3F10 << 16);
    // 0x808000A0: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: jal         0x8008CF1C
    // 0x808000AC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_4;
    // 0x808000AC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: jal         0x8009B9B0
    // 0x808000B8: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_5;
    // 0x808000B8: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_5:
    // 0x808000BC: jal         0x8009C990
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_6;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000C4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x808000C8: jal         0x8009BB00
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_7;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D8: jal         0x8009BA68
    // 0x808000DC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_8;
    // 0x808000DC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x808000E0: lui         $a2, 0x3F0E
    ctx->r6 = S32(0X3F0E << 16);
    // 0x808000E4: ori         $a2, $a2, 0xD917
    ctx->r6 = ctx->r6 | 0XD917;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x808000F0: jal         0x8009DF18
    // 0x808000F4: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF18(rdram, ctx);
        goto after_9;
    // 0x808000F4: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_9:
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: jal         0x80084A28
    // 0x80800100: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _badust_entrypoint_12(rdram, ctx);
        goto after_10;
    // 0x80800100: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: jal         0x80095760
    // 0x8080010C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    baflag_set(rdram, ctx);
        goto after_11;
    // 0x8080010C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_11:
    // 0x80800110: b           L_80800168
    // 0x80800114: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
        goto L_80800168;
    // 0x80800114: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_80800118:
    // 0x80800118: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x8080011C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800124: jal         0x8008CF1C
    // 0x80800128: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_12;
    // 0x80800128: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_12:
    // 0x8080012C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80800130: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: jal         0x80085338
    // 0x8080013C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_13;
    // 0x8080013C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80800140: b           L_80800168
    // 0x80800144: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
        goto L_80800168;
    // 0x80800144: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_80800148:
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800150: jal         0x8008CF1C
    // 0x80800154: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_14;
    // 0x80800154: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_14:
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x80084A28
    // 0x80800160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _badust_entrypoint_12(rdram, ctx);
        goto after_15;
    // 0x80800160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
L_80800164:
    // 0x80800164: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_80800168:
    // 0x80800168: sw          $t8, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r24;
    // 0x8080016C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800170: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800174: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800178: jr          $ra
    // 0x8080017C: nop

    return;
    // 0x8080017C: nop

;}
RECOMP_FUNC void func_8080029C_chbigterrysbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080029C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002AC: jal         0x800DA298
    // 0x808002B0: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808002B0: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    after_0:
    // 0x808002B4: jal         0x800D395C
    // 0x808002B8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800D395C(rdram, ctx);
        goto after_1;
    // 0x808002B8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808002BC: jal         0x80088848
    // 0x808002C0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x808002C0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_2:
    // 0x808002C4: beq         $v0, $zero, L_808002DC
    if (ctx->r2 == 0) {
        // 0x808002C8: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_808002DC;
    }
    // 0x808002C8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808002CC: jal         0x800FFAB0
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002D4: b           L_80800364
    // 0x808002D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800364;
    // 0x808002D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002DC:
    // 0x808002DC: beq         $t6, $zero, L_808002F4
    if (ctx->r14 == 0) {
        // 0x808002E0: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_808002F4;
    }
    // 0x808002E0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808002E4: bne         $t7, $zero, L_808002F4
    if (ctx->r15 != 0) {
        // 0x808002E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002F4;
    }
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002EC: jal         0x80101FDC
    // 0x808002F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808002F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
L_808002F4:
    // 0x808002F4: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x808002F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800304: jal         0x8010A800
    // 0x80800308: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    func_8010A800(rdram, ctx);
        goto after_5;
    // 0x80800308: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    after_5:
    // 0x8080030C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800310: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800314: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800318: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x8080031C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80800320: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800324: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80800328: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8080032C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800330: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800338: jal         0x80086898
    // 0x8080033C: lui         $a3, 0xC3C8
    ctx->r7 = S32(0XC3C8 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x8080033C: lui         $a3, 0xC3C8
    ctx->r7 = S32(0XC3C8 << 16);
    after_6:
    // 0x80800340: beq         $v0, $zero, L_80800360
    if (ctx->r2 == 0) {
        // 0x80800344: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800360;
    }
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800348: jal         0x800868A8
    // 0x8080034C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x8080034C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_7:
    // 0x80800350: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800354: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800358: jal         0x800868B0
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80800360:
    // 0x80800360: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800364:
    // 0x80800364: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800368: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080036C: jr          $ra
    // 0x80800370: nop

    return;
    // 0x80800370: nop

    // 0x80800374: nop

    // 0x80800378: nop

    // 0x8080037C: nop

;}
RECOMP_FUNC void func_80803F90_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803F90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803F94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80803F98: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80803F9C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80803FA0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80803FA4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80803FA8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80803FAC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80803FB0: jal         0x800E73D4
    // 0x80803FB4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_800E73D4(rdram, ctx);
        goto after_0;
    // 0x80803FB4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80803FB8: blez        $s3, L_80804000
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80803FBC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80804000;
    }
    // 0x80803FBC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80803FC0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
L_80803FC4:
    // 0x80803FC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80803FC8: jal         0x80088718
    // 0x80803FCC: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    _gldbstring_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80803FCC: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    after_1:
    // 0x80803FD0: beq         $v0, $zero, L_80803FEC
    if (ctx->r2 == 0) {
        // 0x80803FD4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80803FEC;
    }
    // 0x80803FD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803FD8: jal         0x80088720
    // 0x80803FDC: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80803FDC: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    after_2:
    // 0x80803FE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803FE4: jal         0x800E6A10
    // 0x80803FE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800E6A10(rdram, ctx);
        goto after_3;
    // 0x80803FE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
L_80803FEC:
    // 0x80803FEC: jal         0x80088728
    // 0x80803FF0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    _gldbstring_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80803FF0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_4:
    // 0x80803FF4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80803FF8: bne         $s1, $s3, L_80803FC4
    if (ctx->r17 != ctx->r19) {
        // 0x80803FFC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80803FC4;
    }
    // 0x80803FFC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80804000:
    // 0x80804000: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80804004: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80804008: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080400C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80804010: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80804014: jr          $ra
    // 0x80804018: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80804018: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800394_chlavagargoyle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800394: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800398: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080039C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003A0: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x808003A4: beq         $a1, $at, L_80800544
    if (ctx->r5 == ctx->r1) {
        // 0x808003A8: sw          $a2, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r6;
            goto L_80800544;
    }
    // 0x808003A8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x808003AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808003B0: beq         $a1, $at, L_80800568
    if (ctx->r5 == ctx->r1) {
        // 0x808003B4: lw          $a0, 0x68($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X68);
            goto L_80800568;
    }
    // 0x808003B4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x808003B8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x808003BC: beq         $a1, $at, L_808005BC
    if (ctx->r5 == ctx->r1) {
        // 0x808003C0: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_808005BC;
    }
    // 0x808003C0: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x808003C4: beq         $a1, $at, L_808003EC
    if (ctx->r5 == ctx->r1) {
        // 0x808003C8: addiu       $a0, $zero, 0x402
        ctx->r4 = ADD32(0, 0X402);
            goto L_808003EC;
    }
    // 0x808003C8: addiu       $a0, $zero, 0x402
    ctx->r4 = ADD32(0, 0X402);
    // 0x808003CC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808003D0: beq         $a1, $at, L_808004D8
    if (ctx->r5 == ctx->r1) {
        // 0x808003D4: lw          $t0, 0x68($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X68);
            goto L_808004D8;
    }
    // 0x808003D4: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x808003D8: addiu       $at, $zero, 0x97
    ctx->r1 = ADD32(0, 0X97);
    // 0x808003DC: beq         $a1, $at, L_80800578
    if (ctx->r5 == ctx->r1) {
        // 0x808003E0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800578;
    }
    // 0x808003E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003E4: b           L_8080063C
    // 0x808003E8: nop

        goto L_8080063C;
    // 0x808003E8: nop

L_808003EC:
    // 0x808003EC: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x808003F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808003F4: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    // 0x808003F8: jal         0x80108528
    // 0x808003FC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80108528(rdram, ctx);
        goto after_0;
    // 0x808003FC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x80800400: jal         0x800F54E4
    // 0x80800404: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800404: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800408: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080040C: jal         0x800F5A00
    // 0x80800410: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80800410: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_2:
    // 0x80800414: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80800418: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8080041C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800420: jal         0x800EEAD4
    // 0x80800424: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800EEAD4(rdram, ctx);
        goto after_3;
    // 0x80800424: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_3:
    // 0x80800428: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2324, 0XCD4) << 16);
    // 0x8080042C: lwc1        $f4, 0xCD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2324, 0XCD4));
    // 0x80800430: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80800434: div.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800438: jal         0x800F54E4
    // 0x8080043C: swc1        $f6, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f6.u32l;
    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x8080043C: swc1        $f6, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f6.u32l;
    after_4:
    // 0x80800440: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80800444: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800448: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8080044C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800450: jal         0x8010D12C
    // 0x80800454: lw          $a2, 0x58($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X58);
    func_8010D12C(rdram, ctx);
        goto after_5;
    // 0x80800454: lw          $a2, 0x58($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X58);
    after_5:
    // 0x80800458: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080045C: jal         0x800EEAD4
    // 0x80800460: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800EEAD4(rdram, ctx);
        goto after_6;
    // 0x80800460: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_6:
    // 0x80800464: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2324, 0XCD8) << 16);
    // 0x80800468: lwc1        $f8, 0xCD8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2324, 0XCD8));
    // 0x8080046C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800470: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80800474: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800478: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080047C: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800480: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800484: lui         $a2, 0x453B
    ctx->r6 = S32(0X453B << 16);
    // 0x80800488: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8080048C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800490: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80800494: swc1        $f10, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f10.u32l;
    // 0x80800498: jal         0x800F10B4
    // 0x8080049C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x8080049C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x808004A0: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x808004A4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x808004A8: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x808004AC: swc1        $f0, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f0.u32l;
    // 0x808004B0: jal         0x800F18FC
    // 0x808004B4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F18FC(rdram, ctx);
        goto after_8;
    // 0x808004B4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x808004B8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x808004BC: lui         $a2, 0x4489
    ctx->r6 = S32(0X4489 << 16);
    // 0x808004C0: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x808004C4: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x808004C8: jal         0x800EEBF0
    // 0x808004CC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EEBF0(rdram, ctx);
        goto after_9;
    // 0x808004CC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_9:
    // 0x808004D0: b           L_8080063C
    // 0x808004D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080063C;
    // 0x808004D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004D8:
    // 0x808004D8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808004DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004E0: lwc1        $f18, 0x48($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X48);
    // 0x808004E4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808004E8: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    // 0x808004EC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x808004F0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808004F4: jal         0x800EEB9C
    // 0x808004F8: nop

    func_800EEB9C(rdram, ctx);
        goto after_10;
    // 0x808004F8: nop

    after_10:
    // 0x808004FC: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80800500: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800504: jal         0x800EF04C
    // 0x80800508: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x80800508: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_11:
    // 0x8080050C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80800510: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800514: addiu       $a2, $zero, 0x902
    ctx->r6 = ADD32(0, 0X902);
    // 0x80800518: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8080051C: jal         0x80086E18
    // 0x80800520: lhu         $a3, 0x16($t2)
    ctx->r7 = MEM_HU(ctx->r10, 0X16);
    _chskeletonexplode_entrypoint_6(rdram, ctx);
        goto after_12;
    // 0x80800520: lhu         $a3, 0x16($t2)
    ctx->r7 = MEM_HU(ctx->r10, 0X16);
    after_12:
    // 0x80800524: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80800528: jal         0x80107070
    // 0x8080052C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80107070(rdram, ctx);
        goto after_13;
    // 0x8080052C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
    // 0x80800530: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80800534: jal         0x80102424
    // 0x80800538: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x80800538: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
    // 0x8080053C: b           L_8080063C
    // 0x80800540: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080063C;
    // 0x80800540: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800544:
    // 0x80800544: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800548: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080054C: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x80800550: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800554: swc1        $f8, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->f8.u32l;
    // 0x80800558: jal         0x80102424
    // 0x8080055C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    func_80102424(rdram, ctx);
        goto after_15;
    // 0x8080055C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_15:
    // 0x80800560: b           L_8080063C
    // 0x80800564: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080063C;
    // 0x80800564: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800568:
    // 0x80800568: jal         0x80102424
    // 0x8080056C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_16;
    // 0x8080056C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80800570: b           L_8080063C
    // 0x80800574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080063C;
    // 0x80800574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800578:
    // 0x80800578: jal         0x80103EAC
    // 0x8080057C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    func_80103EAC(rdram, ctx);
        goto after_17;
    // 0x8080057C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_17:
    // 0x80800580: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80800584: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800588: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080058C: lw          $a1, 0x48($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X48);
    // 0x80800590: jal         0x800EEB9C
    // 0x80800594: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800EEB9C(rdram, ctx);
        goto after_18;
    // 0x80800594: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_18:
    // 0x80800598: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080059C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808005A0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808005A4: add.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x808005A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808005AC: jal         0x80101010
    // 0x808005B0: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    func_80101010(rdram, ctx);
        goto after_19;
    // 0x808005B0: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_19:
    // 0x808005B4: b           L_8080063C
    // 0x808005B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080063C;
    // 0x808005B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005BC:
    // 0x808005BC: jal         0x80101080
    // 0x808005C0: nop

    func_80101080(rdram, ctx);
        goto after_20;
    // 0x808005C0: nop

    after_20:
    // 0x808005C4: jal         0x80106790
    // 0x808005C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_21;
    // 0x808005C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_21:
    // 0x808005CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005D0: jal         0x80086E08
    // 0x808005D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _chskeletonexplode_entrypoint_4(rdram, ctx);
        goto after_22;
    // 0x808005D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_22:
    // 0x808005D8: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x808005DC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2324, 0XD3C) << 16);
    // 0x808005E0: addiu       $t6, $t6, 0xD3C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2324, 0XD3C));
    // 0x808005E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808005E8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808005EC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x808005F0: addiu       $a0, $t5, 0x4
    ctx->r4 = ADD32(ctx->r13, 0X4);
    // 0x808005F4: jal         0x800BBCB8
    // 0x808005F8: addiu       $a1, $t5, 0x18
    ctx->r5 = ADD32(ctx->r13, 0X18);
    func_800BBCB8(rdram, ctx);
        goto after_23;
    // 0x808005F8: addiu       $a1, $t5, 0x18
    ctx->r5 = ADD32(ctx->r13, 0X18);
    after_23:
    // 0x808005FC: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80800600: lui         $a0, 0x7FFB
    ctx->r4 = S32(0X7FFB << 16);
    // 0x80800604: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800608: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x8080060C: ori         $a0, $a0, 0x5C13
    ctx->r4 = ctx->r4 | 0X5C13;
    // 0x80800610: jal         0x800C4140
    // 0x80800614: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800C4140(rdram, ctx);
        goto after_24;
    // 0x80800614: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_24:
    // 0x80800618: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8080061C: lui         $a0, 0x7FFB
    ctx->r4 = S32(0X7FFB << 16);
    // 0x80800620: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800624: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800628: ori         $a0, $a0, 0x5C17
    ctx->r4 = ctx->r4 | 0X5C17;
    // 0x8080062C: jal         0x800C4140
    // 0x80800630: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800C4140(rdram, ctx);
        goto after_25;
    // 0x80800630: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_25:
    // 0x80800634: b           L_8080063C
    // 0x80800638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080063C;
    // 0x80800638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080063C:
    // 0x8080063C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800640: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80800644: jr          $ra
    // 0x80800648: nop

    return;
    // 0x80800648: nop

;}
RECOMP_FUNC void func_80013324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013324: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80013328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001332C: jal         0x80013224
    // 0x80013330: nop

    func_80013224(rdram, ctx);
        goto after_0;
    // 0x80013330: nop

    after_0:
    // 0x80013334: jal         0x800132BC
    // 0x80013338: nop

    func_800132BC(rdram, ctx);
        goto after_1;
    // 0x80013338: nop

    after_1:
    // 0x8001333C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80013344: jr          $ra
    // 0x80013348: nop

    return;
    // 0x80013348: nop

;}
RECOMP_FUNC void sumumbofx_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801408: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080140C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801414: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801418: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8080141C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801420: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80801424: sb          $t6, 0x63($a0)
    MEM_B(0X63, ctx->r4) = ctx->r14;
    // 0x80801428: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8080142C: jal         0x800EE7F8
    // 0x80801430: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80801430: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x80801434: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80801438: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080143C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80801440: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80801444: nop

    // 0x80801448: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8080144C: swc1        $f4, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->f4.u32l;
    // 0x80801450: swc1        $f6, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->f6.u32l;
    // 0x80801454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080145C: jr          $ra
    // 0x80801460: nop

    return;
    // 0x80801460: nop

    // 0x80801464: nop

    // 0x80801468: nop

    // 0x8080146C: nop

;}
RECOMP_FUNC void _bsjump_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800832C0: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x800832C0);
    return;
    // 0x800832C4: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_808004C8_basub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C8: lw          $t6, 0x130($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X130);
    // 0x808004CC: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x808004D0: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x808004D4: sw          $zero, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = 0;
    // 0x808004D8: lw          $t7, 0x130($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X130);
    // 0x808004DC: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
L_808004E0:
    // 0x808004E0: lw          $t8, 0x130($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X130);
    // 0x808004E4: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x808004E8: sw          $zero, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = 0;
    // 0x808004EC: lw          $t0, 0x130($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X130);
    // 0x808004F0: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x808004F4: sw          $zero, 0x30($t1)
    MEM_W(0X30, ctx->r9) = 0;
    // 0x808004F8: lw          $t2, 0x130($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X130);
    // 0x808004FC: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80800500: sw          $zero, 0x34($t3)
    MEM_W(0X34, ctx->r11) = 0;
    // 0x80800504: lw          $t4, 0x130($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X130);
    // 0x80800508: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x8080050C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80800510: bne         $v1, $v0, L_808004E0
    if (ctx->r3 != ctx->r2) {
        // 0x80800514: sw          $zero, 0x38($t5)
        MEM_W(0X38, ctx->r13) = 0;
            goto L_808004E0;
    }
    // 0x80800514: sw          $zero, 0x38($t5)
    MEM_W(0X38, ctx->r13) = 0;
    // 0x80800518: lw          $t6, 0x130($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X130);
    // 0x8080051C: jr          $ra
    // 0x80800520: sw          $zero, 0x28($t6)
    MEM_W(0X28, ctx->r14) = 0;
    return;
    // 0x80800520: sw          $zero, 0x28($t6)
    MEM_W(0X28, ctx->r14) = 0;
;}
RECOMP_FUNC void _bsbtrot_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C70: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C70);
    return;
    // 0x80082C74: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void fxstep_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080052C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80800530: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80800534: jr          $ra
    // 0x80800538: swc1        $f12, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x80800538: swc1        $f12, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800955CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800955CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800955D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800955D4: lw          $a1, 0x7C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X7C);
    // 0x800955D8: jal         0x8009C128
    // 0x800955DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x800955DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800955E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800955E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800955E8: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x800955EC: jal         0x80095588
    // 0x800955F0: sb          $zero, 0xC($t6)
    MEM_B(0XC, ctx->r14) = 0;
    func_80095588(rdram, ctx);
        goto after_1;
    // 0x800955F0: sb          $zero, 0xC($t6)
    MEM_B(0XC, ctx->r14) = 0;
    after_1:
    // 0x800955F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800955F8: lw          $t7, 0x7C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X7C);
    // 0x800955FC: sw          $zero, 0x10($t7)
    MEM_W(0X10, ctx->r15) = 0;
    // 0x80095600: lw          $v0, 0x7C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X7C);
    // 0x80095604: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x80095608: sw          $t8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r24;
    // 0x8009560C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80095610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80095614: jr          $ra
    // 0x80095618: nop

    return;
    // 0x80095618: nop

;}
RECOMP_FUNC void func_8080008C_chlavaentrancebridge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800090: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800094: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800098: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080009C: jal         0x80088F08
    // 0x808000A0: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    _idworld_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    after_0:
    // 0x808000A4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808000A8: jal         0x80088F08
    // 0x808000AC: addiu       $a0, $zero, 0x191
    ctx->r4 = ADD32(0, 0X191);
    _idworld_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808000AC: addiu       $a0, $zero, 0x191
    ctx->r4 = ADD32(0, 0X191);
    after_1:
    // 0x808000B0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808000B4: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x808000B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1980, 0X214) << 16);
    // 0x808000BC: lwc1        $f0, 0x214($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1980, 0X214));
    // 0x808000C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000C4: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x808000C8: beq         $t6, $at, L_808000E4
    if (ctx->r14 == ctx->r1) {
        // 0x808000CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000E4;
    }
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808000D4: beql        $t6, $at, L_80800190
    if (ctx->r14 == ctx->r1) {
        // 0x808000D8: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80800190;
    }
    goto skip_0;
    // 0x808000D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x808000DC: b           L_80800198
    // 0x808000E0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
        goto L_80800198;
    // 0x808000E0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_808000E4:
    // 0x808000E4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808000E8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1980, 0X220) << 16);
    // 0x808000EC: addiu       $a3, $a3, 0x220
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1980, 0X220));
    // 0x808000F0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x808000F4: jal         0x80089D50
    // 0x808000F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808000F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x808000FC: jal         0x800D8FF8
    // 0x80800100: nop

    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x80800100: nop

    after_3:
    // 0x80800104: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x80800108: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080010C: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800110: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800114: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800120: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800124: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x80800128: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080012C: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80800130: nop

    // 0x80800134: bc1f        L_80800184
    if (!c1cs) {
        // 0x80800138: nop
    
            goto L_80800184;
    }
    // 0x80800138: nop

    // 0x8080013C: jal         0x80101FDC
    // 0x80800140: swc1        $f12, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f12.u32l;
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800140: swc1        $f12, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f12.u32l;
    after_4:
    // 0x80800144: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1980, 0X228) << 16);
    // 0x80800148: addiu       $a2, $a2, 0x228
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1980, 0X228));
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: jal         0x80089D18
    // 0x80800154: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800154: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80800158: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x8080015C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800160: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800164: jal         0x800E15CC
    // 0x80800168: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    func_800E15CC(rdram, ctx);
        goto after_6;
    // 0x80800168: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    after_6:
    // 0x8080016C: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80800170: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800174: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800178: jal         0x80018820
    // 0x8080017C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80018820(rdram, ctx);
        goto after_7;
    // 0x8080017C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_7:
    // 0x80800180: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
L_80800184:
    // 0x80800184: b           L_80800194
    // 0x80800188: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80800194;
    // 0x80800188: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8080018C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80800190:
    // 0x80800190: nop

L_80800194:
    // 0x80800194: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_80800198:
    // 0x80800198: beql        $a0, $zero, L_808001B4
    if (ctx->r4 == 0) {
        // 0x8080019C: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_808001B4;
    }
    goto skip_1;
    // 0x8080019C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    skip_1:
    // 0x808001A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001A4: jal         0x800EDCEC
    // 0x808001A8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800EDCEC(rdram, ctx);
        goto after_8;
    // 0x808001A8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x808001AC: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808001B0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_808001B4:
    // 0x808001B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1980, 0X218) << 16);
    // 0x808001B8: beql        $t7, $zero, L_808001F0
    if (ctx->r15 == 0) {
        // 0x808001BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001F0;
    }
    goto skip_2;
    // 0x808001BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808001C0: lwc1        $f12, 0x218($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1980, 0X218));
    // 0x808001C4: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x808001C8: nop

    // 0x808001CC: bc1fl       L_808001E0
    if (!c1cs) {
        // 0x808001D0: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_808001E0;
    }
    goto skip_3;
    // 0x808001D0: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    skip_3:
    // 0x808001D4: b           L_808001E0
    // 0x808001D8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_808001E0;
    // 0x808001D8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808001DC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_808001E0:
    // 0x808001E0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808001E4: jal         0x800EDCEC
    // 0x808001E8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800EDCEC(rdram, ctx);
        goto after_9;
    // 0x808001E8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_9:
    // 0x808001EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001F0:
    // 0x808001F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808001F8: jr          $ra
    // 0x808001FC: nop

    return;
    // 0x808001FC: nop

;}
RECOMP_FUNC void func_808005C4_gztrace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808005C8: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x808005CC: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x808005D0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x808005D4: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x808005D8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808005DC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x808005E0: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x808005E4: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x808005E8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x808005EC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x808005F0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808005F4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808005F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808005FC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80800600: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80800604: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x80800608: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    // 0x8080060C: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x80800610: jal         0x808004B0
    // 0x80800614: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_808004B0_gztrace(rdram, ctx);
        goto after_0;
    // 0x80800614: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80800618: beq         $v0, $zero, L_80800810
    if (ctx->r2 == 0) {
        // 0x8080061C: lui         $s6, 0x8080
        ctx->r22 = S32(RELOC_HI16(3390, 0XACD) << 16);
            goto L_80800810;
    }
    // 0x8080061C: lui         $s6, 0x8080
    ctx->r22 = S32(RELOC_HI16(3390, 0XACD) << 16);
    // 0x80800620: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(3390, 0XA70) << 16);
    // 0x80800624: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(3390, 0XAA8) << 16);
    // 0x80800628: addiu       $s1, $s1, 0xAA8
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(3390, 0XAA8));
    // 0x8080062C: addiu       $s3, $s3, 0xA70
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(3390, 0XA70));
    // 0x80800630: addiu       $s6, $s6, 0xACD
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(3390, 0XACD));
    // 0x80800634: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_80800638:
    // 0x80800638: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8080063C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800640: beq         $v0, $zero, L_80800650
    if (ctx->r2 == 0) {
        // 0x80800644: or          $s2, $v1, $zero
        ctx->r18 = ctx->r3 | 0;
            goto L_80800650;
    }
    // 0x80800644: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x80800648: b           L_80800654
    // 0x8080064C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80800654;
    // 0x8080064C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80800650:
    // 0x80800650: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80800654:
    // 0x80800654: jal         0x80081AA4
    // 0x80800658: nop

    func_80081AA4(rdram, ctx);
        goto after_1;
    // 0x80800658: nop

    after_1:
    // 0x8080065C: beq         $v0, $zero, L_808006CC
    if (ctx->r2 == 0) {
        // 0x80800660: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808006CC;
    }
    // 0x80800660: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800664: jal         0x808003D0
    // 0x80800668: nop

    func_808003D0_gztrace(rdram, ctx);
        goto after_2;
    // 0x80800668: nop

    after_2:
    // 0x8080066C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800670: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800674: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800678: lw          $a1, 0x1C($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X1C);
    // 0x8080067C: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80800680: jal         0x808000E8
    // 0x80800684: addiu       $a3, $zero, 0x7E
    ctx->r7 = ADD32(0, 0X7E);
    func_808000E8_gztrace(rdram, ctx);
        goto after_3;
    // 0x80800684: addiu       $a3, $zero, 0x7E
    ctx->r7 = ADD32(0, 0X7E);
    after_3:
    // 0x80800688: bne         $s5, $zero, L_808006EC
    if (ctx->r21 != 0) {
        // 0x8080068C: nop
    
            goto L_808006EC;
    }
    // 0x8080068C: nop

    // 0x80800690: beq         $s0, $zero, L_808006C0
    if (ctx->r16 == 0) {
        // 0x80800694: lui         $t8, 0x8008
        ctx->r24 = S32(0X8008 << 16);
            goto L_808006C0;
    }
    // 0x80800694: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80800698: addiu       $t8, $t8, 0x2540
    ctx->r24 = ADD32(ctx->r24, 0X2540);
    // 0x8080069C: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x808006A0: bne         $at, $zero, L_808006B8
    if (ctx->r1 != 0) {
        // 0x808006A4: lui         $t9, 0x8009
        ctx->r25 = S32(0X8009 << 16);
            goto L_808006B8;
    }
    // 0x808006A4: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x808006A8: addiu       $t9, $t9, -0x5678
    ctx->r25 = ADD32(ctx->r25, -0X5678);
    // 0x808006AC: slt         $at, $t9, $s0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x808006B0: beql        $at, $zero, L_808006C4
    if (ctx->r1 == 0) {
        // 0x808006B4: lw          $t1, 0x20($s3)
        ctx->r9 = MEM_W(ctx->r19, 0X20);
            goto L_808006C4;
    }
    goto skip_0;
    // 0x808006B4: lw          $t1, 0x20($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X20);
    skip_0:
L_808006B8:
    // 0x808006B8: lw          $t0, 0x20($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X20);
    // 0x808006BC: subu        $s0, $s0, $t0
    ctx->r16 = SUB32(ctx->r16, ctx->r8);
L_808006C0:
    // 0x808006C0: lw          $t1, 0x20($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X20);
L_808006C4:
    // 0x808006C4: b           L_808006EC
    // 0x808006C8: subu        $s2, $s2, $t1
    ctx->r18 = SUB32(ctx->r18, ctx->r9);
        goto L_808006EC;
    // 0x808006C8: subu        $s2, $s2, $t1
    ctx->r18 = SUB32(ctx->r18, ctx->r9);
L_808006CC:
    // 0x808006CC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3390, 0X970) << 16);
    // 0x808006D0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x808006D4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808006D8: addiu       $a1, $a1, 0x970
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3390, 0X970));
    // 0x808006DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006E0: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x808006E4: jal         0x808000E8
    // 0x808006E8: addiu       $a3, $zero, 0x7E
    ctx->r7 = ADD32(0, 0X7E);
    func_808000E8_gztrace(rdram, ctx);
        goto after_4;
    // 0x808006E8: addiu       $a3, $zero, 0x7E
    ctx->r7 = ADD32(0, 0X7E);
    after_4:
L_808006EC:
    // 0x808006EC: beq         $s5, $zero, L_80800708
    if (ctx->r21 == 0) {
        // 0x808006F0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800708;
    }
    // 0x808006F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006F8: beq         $s5, $at, L_8080074C
    if (ctx->r21 == ctx->r1) {
        // 0x808006FC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080074C;
    }
    // 0x808006FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800700: b           L_80800770
    // 0x80800704: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
        goto L_80800770;
    // 0x80800704: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_80800708:
    // 0x80800708: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3390, 0X978) << 16);
    // 0x8080070C: jal         0x80800068
    // 0x80800710: addiu       $a1, $a1, 0x978
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3390, 0X978));
    func_80800068_gztrace(rdram, ctx);
        goto after_5;
    // 0x80800710: addiu       $a1, $a1, 0x978
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3390, 0X978));
    after_5:
    // 0x80800714: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80800718: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3390, 0XABA) << 16);
    // 0x8080071C: addiu       $a2, $a2, 0xABA
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3390, 0XABA));
    // 0x80800720: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800724: jal         0x80800290
    // 0x80800728: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    func_80800290_gztrace(rdram, ctx);
        goto after_6;
    // 0x80800728: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_6:
    // 0x8080072C: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x80800730: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3390, 0XAC3) << 16);
    // 0x80800734: addiu       $a2, $a2, 0xAC3
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3390, 0XAC3));
    // 0x80800738: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080073C: jal         0x80800290
    // 0x80800740: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    func_80800290_gztrace(rdram, ctx);
        goto after_7;
    // 0x80800740: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    after_7:
    // 0x80800744: b           L_80800770
    // 0x80800748: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
        goto L_80800770;
    // 0x80800748: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_8080074C:
    // 0x8080074C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3390, 0X990) << 16);
    // 0x80800750: jal         0x80800068
    // 0x80800754: addiu       $a1, $a1, 0x990
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3390, 0X990));
    func_80800068_gztrace(rdram, ctx);
        goto after_8;
    // 0x80800754: addiu       $a1, $a1, 0x990
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3390, 0X990));
    after_8:
    // 0x80800758: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3390, 0XABD) << 16);
    // 0x8080075C: addiu       $a2, $a2, 0xABD
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3390, 0XABD));
    // 0x80800760: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80800764: jal         0x80800290
    // 0x80800768: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800290_gztrace(rdram, ctx);
        goto after_9;
    // 0x80800768: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x8080076C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_80800770:
    // 0x80800770: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800774: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800778: beq         $v0, $zero, L_80800794
    if (ctx->r2 == 0) {
        // 0x8080077C: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(3390, 0X9A8) << 16);
            goto L_80800794;
    }
    // 0x8080077C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3390, 0X9A8) << 16);
    // 0x80800780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800784: jal         0x80800290
    // 0x80800788: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800290_gztrace(rdram, ctx);
        goto after_10;
    // 0x80800788: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
    // 0x8080078C: b           L_8080079C
    // 0x80800790: nop

        goto L_8080079C;
    // 0x80800790: nop

L_80800794:
    // 0x80800794: jal         0x80800068
    // 0x80800798: addiu       $a1, $a1, 0x9A8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3390, 0X9A8));
    func_80800068_gztrace(rdram, ctx);
        goto after_11;
    // 0x80800798: addiu       $a1, $a1, 0x9A8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3390, 0X9A8));
    after_11:
L_8080079C:
    // 0x8080079C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3390, 0XAD5) << 16);
    // 0x808007A0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3390, 0X9B4) << 16);
    // 0x808007A4: addiu       $a1, $a1, 0x9B4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3390, 0X9B4));
    // 0x808007A8: jal         0x80800068
    // 0x808007AC: addiu       $a0, $a0, 0xAD5
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3390, 0XAD5));
    func_80800068_gztrace(rdram, ctx);
        goto after_12;
    // 0x808007AC: addiu       $a0, $a0, 0xAD5
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3390, 0XAD5));
    after_12:
    // 0x808007B0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3390, 0XAD6) << 16);
    // 0x808007B4: addiu       $a2, $a2, 0xAD6
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3390, 0XAD6));
    // 0x808007B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808007BC: jal         0x80800290
    // 0x808007C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800290_gztrace(rdram, ctx);
        goto after_13;
    // 0x808007C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_13:
    // 0x808007C4: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x808007C8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3390, 0X9C0) << 16);
    // 0x808007CC: sb          $zero, 0x36($s1)
    MEM_B(0X36, ctx->r17) = 0;
    // 0x808007D0: bne         $t5, $zero, L_808007E0
    if (ctx->r13 != 0) {
        // 0x808007D4: addiu       $a0, $a0, 0x9C0
        ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3390, 0X9C0));
            goto L_808007E0;
    }
    // 0x808007D4: addiu       $a0, $a0, 0x9C0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3390, 0X9C0));
    // 0x808007D8: jal         0x8001D37C
    // 0x808007DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8001D37C(rdram, ctx);
        goto after_14;
    // 0x808007DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_14:
L_808007E0:
    // 0x808007E0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x808007E4: slti        $at, $s4, 0x10
    ctx->r1 = SIGNED(ctx->r20) < 0X10 ? 1 : 0;
    // 0x808007E8: beq         $at, $zero, L_80800810
    if (ctx->r1 == 0) {
        // 0x808007EC: addiu       $a0, $sp, 0x64
        ctx->r4 = ADD32(ctx->r29, 0X64);
            goto L_80800810;
    }
    // 0x808007EC: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x808007F0: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x808007F4: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x808007F8: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x808007FC: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    // 0x80800800: jal         0x808004B0
    // 0x80800804: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_808004B0_gztrace(rdram, ctx);
        goto after_15;
    // 0x80800804: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_15:
    // 0x80800808: bnel        $v0, $zero, L_80800638
    if (ctx->r2 != 0) {
        // 0x8080080C: lw          $v0, 0x5C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X5C);
            goto L_80800638;
    }
    goto skip_1;
    // 0x8080080C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    skip_1:
L_80800810:
    // 0x80800810: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800814: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800818: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8080081C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800820: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800824: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80800828: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8080082C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80800830: jr          $ra
    // 0x80800834: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800834: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_808001FC_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800200: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800204: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800208: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080020C: jal         0x8009E77C
    // 0x80800210: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x80800210: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x80800214: bne         $v0, $zero, L_8080033C
    if (ctx->r2 != 0) {
        // 0x80800218: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080033C;
    }
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x80095774
    // 0x80800220: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    baflag_clear(rdram, ctx);
        goto after_1;
    // 0x80800220: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x80800224: jal         0x8009E4AC
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_2;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800230: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800234: jal         0x8009E55C
    // 0x80800238: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    func_8009E55C(rdram, ctx);
        goto after_3;
    // 0x80800238: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    after_3:
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800244: jal         0x8009E53C
    // 0x80800248: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    func_8009E53C(rdram, ctx);
        goto after_4;
    // 0x80800248: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_4:
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800250: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800254: jal         0x8009E55C
    // 0x80800258: lui         $a2, 0x4320
    ctx->r6 = S32(0X4320 << 16);
    func_8009E55C(rdram, ctx);
        goto after_5;
    // 0x80800258: lui         $a2, 0x4320
    ctx->r6 = S32(0X4320 << 16);
    after_5:
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800264: jal         0x8009E53C
    // 0x80800268: lui         $a2, 0xC2B4
    ctx->r6 = S32(0XC2B4 << 16);
    func_8009E53C(rdram, ctx);
        goto after_6;
    // 0x80800268: lui         $a2, 0xC2B4
    ctx->r6 = S32(0XC2B4 << 16);
    after_6:
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80800274: jal         0x800A4D6C
    // 0x80800278: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800A4D6C(rdram, ctx);
        goto after_7;
    // 0x80800278: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_7:
    // 0x8080027C: jal         0x8009EFA8
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_8;
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800284: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x80800288: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: jal         0x8009F1C8
    // 0x80800294: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_9;
    // 0x80800294: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080029C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002A0: jal         0x8009F1C8
    // 0x808002A4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_10;
    // 0x808002A4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_10:
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x808002B0: jal         0x800959C8
    // 0x808002B4: lui         $a2, 0x42DC
    ctx->r6 = S32(0X42DC << 16);
    func_800959C8(rdram, ctx);
        goto after_11;
    // 0x808002B4: lui         $a2, 0x42DC
    ctx->r6 = S32(0X42DC << 16);
    after_11:
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002BC: jal         0x8009590C
    // 0x808002C0: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    func_8009590C(rdram, ctx);
        goto after_12;
    // 0x808002C0: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    after_12:
    // 0x808002C4: lui         $a1, 0x4066
    ctx->r5 = S32(0X4066 << 16);
    // 0x808002C8: ori         $a1, $a1, 0x6640
    ctx->r5 = ctx->r5 | 0X6640;
    // 0x808002CC: jal         0x80092864
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092864(rdram, ctx);
        goto after_13;
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808002D4: jal         0x8080009C
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_bsstatue(rdram, ctx);
        goto after_14;
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808002DC: bnel        $v0, $zero, L_808002FC
    if (ctx->r2 != 0) {
        // 0x808002E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002FC;
    }
    goto skip_0;
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808002E4: jal         0x8009EA7C
    // 0x808002E8: nop

    func_8009EA7C(rdram, ctx);
        goto after_15;
    // 0x808002E8: nop

    after_15:
    // 0x808002EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002F0: jal         0x808000C0
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C0_bsstatue(rdram, ctx);
        goto after_16;
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002FC:
    // 0x808002FC: jal         0x80095964
    // 0x80800300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80095964(rdram, ctx);
        goto after_17;
    // 0x80800300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800308: jal         0x800A25DC
    // 0x8080030C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A25DC(rdram, ctx);
        goto after_18;
    // 0x8080030C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800314: jal         0x800A2018
    // 0x80800318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A2018(rdram, ctx);
        goto after_19;
    // 0x80800318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800324: jal         0x800947EC
    // 0x80800328: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_20;
    // 0x80800328: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_20:
    // 0x8080032C: jal         0x8001211C
    // 0x80800330: nop

    func_8001211C(rdram, ctx);
        goto after_21;
    // 0x80800330: nop

    after_21:
    // 0x80800334: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80800338: sw          $t6, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r14;
L_8080033C:
    // 0x8080033C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800340: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800344: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800348: jr          $ra
    // 0x8080034C: nop

    return;
    // 0x8080034C: nop

;}
RECOMP_FUNC void func_800E6FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6FEC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800E6FF0: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x800E6FF4: addiu       $t9, $zero, 0x2E
    ctx->r25 = ADD32(0, 0X2E);
    // 0x800E6FF8: beq         $t6, $zero, L_800E7010
    if (ctx->r14 == 0) {
        // 0x800E6FFC: addiu       $v1, $zero, 0x1C
        ctx->r3 = ADD32(0, 0X1C);
            goto L_800E7010;
    }
    // 0x800E6FFC: addiu       $v1, $zero, 0x1C
    ctx->r3 = ADD32(0, 0X1C);
    // 0x800E7000: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
L_800E7004:
    // 0x800E7004: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E7008: bnel        $t7, $zero, L_800E7004
    if (ctx->r15 != 0) {
        // 0x800E700C: lbu         $t7, 0x1($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X1);
            goto L_800E7004;
    }
    goto skip_0;
    // 0x800E700C: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    skip_0:
L_800E7010:
    // 0x800E7010: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x800E7014: sb          $t9, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r25;
    // 0x800E7018: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_800E701C:
    // 0x800E701C: srlv        $v0, $a1, $v1
    ctx->r2 = S32(U32(ctx->r5) >> (ctx->r3 & 31));
    // 0x800E7020: andi        $t0, $v0, 0xF
    ctx->r8 = ctx->r2 & 0XF;
    // 0x800E7024: slti        $t1, $t0, 0xA
    ctx->r9 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x800E7028: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800E702C: beq         $t2, $zero, L_800E7040
    if (ctx->r10 == 0) {
        // 0x800E7030: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_800E7040;
    }
    // 0x800E7030: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800E7034: addiu       $t3, $t0, 0x30
    ctx->r11 = ADD32(ctx->r8, 0X30);
    // 0x800E7038: b           L_800E7048
    // 0x800E703C: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
        goto L_800E7048;
    // 0x800E703C: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
L_800E7040:
    // 0x800E7040: addiu       $t4, $v0, 0x37
    ctx->r12 = ADD32(ctx->r2, 0X37);
    // 0x800E7044: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
L_800E7048:
    // 0x800E7048: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800E704C: bgez        $v1, L_800E701C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800E7050: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800E701C;
    }
    // 0x800E7050: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E7054: jr          $ra
    // 0x800E7058: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    return;
    // 0x800E7058: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void _chfairgroundworker_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C60: syscall     215
    recomp_syscall_handler(rdram, ctx, 0x80085C60);
    return;
    // 0x80085C64: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808004F8_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808004FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800500: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800504: jal         0x800EE7F8
    // 0x80800508: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800508: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8080050C: jal         0x800A4C48
    // 0x80800510: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800A4C48(rdram, ctx);
        goto after_1;
    // 0x80800510: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80800514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800518: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8080051C: jal         0x800CA3F4
    // 0x80800520: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    func_800CA3F4(rdram, ctx);
        goto after_2;
    // 0x80800520: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_2:
    // 0x80800524: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(404, 0X22FC) << 16);
    // 0x80800528: addiu       $t6, $t6, 0x22FC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(404, 0X22FC));
    // 0x8080052C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800530: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800538: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080053C: jal         0x800BBCB8
    // 0x80800540: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x80800540: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80800544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800548: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080054C: jr          $ra
    // 0x80800550: nop

    return;
    // 0x80800550: nop

;}
RECOMP_FUNC void func_800C5E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5E14: lbu         $v0, 0x8F($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8F);
    // 0x800C5E18: bne         $v0, $zero, L_800C5E28
    if (ctx->r2 != 0) {
        // 0x800C5E1C: nop
    
            goto L_800C5E28;
    }
    // 0x800C5E1C: nop

    // 0x800C5E20: jr          $ra
    // 0x800C5E24: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800C5E24: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800C5E28:
    // 0x800C5E28: beql        $v0, $zero, L_800C5E48
    if (ctx->r2 == 0) {
        // 0x800C5E2C: lwc1        $f0, 0x74($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X74);
            goto L_800C5E48;
    }
    goto skip_0;
    // 0x800C5E2C: lwc1        $f0, 0x74($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X74);
    skip_0:
    // 0x800C5E30: lbu         $t6, 0x8E($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8E);
    // 0x800C5E34: bnel        $t6, $zero, L_800C5E48
    if (ctx->r14 != 0) {
        // 0x800C5E38: lwc1        $f0, 0x74($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X74);
            goto L_800C5E48;
    }
    goto skip_1;
    // 0x800C5E38: lwc1        $f0, 0x74($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X74);
    skip_1:
    // 0x800C5E3C: jr          $ra
    // 0x800C5E40: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x800C5E40: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800C5E44: lwc1        $f0, 0x74($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X74);
L_800C5E48:
    // 0x800C5E48: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800C5E4C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800C5E50: nop

    // 0x800C5E54: bc1fl       L_800C5E68
    if (!c1cs) {
        // 0x800C5E58: lwc1        $f6, 0x70($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
            goto L_800C5E68;
    }
    goto skip_2;
    // 0x800C5E58: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    skip_2:
    // 0x800C5E5C: jr          $ra
    // 0x800C5E60: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800C5E60: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C5E64: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
L_800C5E68:
    // 0x800C5E68: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x800C5E6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C5E70: sub.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800C5E74: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800C5E78: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x800C5E7C: nop

    // 0x800C5E80: bc1fl       L_800C5E94
    if (!c1cs) {
        // 0x800C5E84: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_800C5E94;
    }
    goto skip_3;
    // 0x800C5E84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_3:
    // 0x800C5E88: jr          $ra
    // 0x800C5E8C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800C5E8C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C5E90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_800C5E94:
    // 0x800C5E94: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800C5E98: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x800C5E9C: nop

    // 0x800C5EA0: bc1f        L_800C5EB0
    if (!c1cs) {
        // 0x800C5EA4: nop
    
            goto L_800C5EB0;
    }
    // 0x800C5EA4: nop

    // 0x800C5EA8: jr          $ra
    // 0x800C5EAC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x800C5EAC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800C5EB0:
    // 0x800C5EB0: jr          $ra
    // 0x800C5EB4: nop

    return;
    // 0x800C5EB4: nop

;}
RECOMP_FUNC void func_80091F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091F38: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x80091F3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80091F40: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80091F44: bnel        $t7, $at, L_80091F68
    if (ctx->r15 != ctx->r1) {
        // 0x80091F48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80091F68;
    }
    goto skip_0;
    // 0x80091F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80091F4C: jal         0x80091FE4
    // 0x80091F50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80091FE4(rdram, ctx);
        goto after_0;
    // 0x80091F50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80091F54: beq         $v0, $zero, L_80091F64
    if (ctx->r2 == 0) {
        // 0x80091F58: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80091F64;
    }
    // 0x80091F58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80091F5C: jal         0x80091F74
    // 0x80091F60: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80091F74(rdram, ctx);
        goto after_1;
    // 0x80091F60: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
L_80091F64:
    // 0x80091F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80091F68:
    // 0x80091F68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091F6C: jr          $ra
    // 0x80091F70: nop

    return;
    // 0x80091F70: nop

;}
RECOMP_FUNC void func_80800064_bsblongleg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080006C: jal         0x8009EF1C
    // 0x80800070: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x80800070: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800074: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800078: jal         0x8009EF10
    // 0x8080007C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x8080007C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800080: bne         $v0, $zero, L_8080009C
    if (ctx->r2 != 0) {
        // 0x80800084: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_8080009C;
    }
    // 0x80800084: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800088: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080008C: jal         0x8009B9B0
    // 0x80800090: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800090: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800094: b           L_808000BC
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000BC;
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080009C:
    // 0x8080009C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808000A0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000A4: jal         0x800F1214
    // 0x808000A8: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x808000A8: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    after_3:
    // 0x808000AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000B0: jal         0x8009B9B0
    // 0x808000B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x808000B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808000B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000BC:
    // 0x808000BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C0: jr          $ra
    // 0x808000C4: nop

    return;
    // 0x808000C4: nop

;}
RECOMP_FUNC void func_80800FB8_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800FBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FC0: jal         0x8009BC6C
    // 0x80800FC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x80800FC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800FC8: jal         0x800A4E30
    // 0x80800FCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4E30(rdram, ctx);
        goto after_1;
    // 0x80800FCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800FD0: jal         0x800951B4
    // 0x80800FD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800951B4(rdram, ctx);
        goto after_2;
    // 0x80800FD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800FD8: jal         0x80082830
    // 0x80800FDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsbee_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800FDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FE8: jr          $ra
    // 0x80800FEC: nop

    return;
    // 0x80800FEC: nop

;}
RECOMP_FUNC void chpowerhut_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808008C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808008CC: jal         0x80100094
    // 0x808008D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008D4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808008D8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808008DC: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808008E0: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x808008E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808008E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808008EC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808008F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008F4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808008F8: nop

    // 0x808008FC: bc1f        L_80800908
    if (!c1cs) {
        // 0x80800900: nop
    
            goto L_80800908;
    }
    // 0x80800900: nop

    // 0x80800904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800908:
    // 0x80800908: beq         $v0, $zero, L_8080092C
    if (ctx->r2 == 0) {
        // 0x8080090C: nop
    
            goto L_8080092C;
    }
    // 0x8080090C: nop

    // 0x80800910: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800918: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x8080091C: nop

    // 0x80800920: bc1f        L_8080092C
    if (!c1cs) {
        // 0x80800924: nop
    
            goto L_8080092C;
    }
    // 0x80800924: nop

    // 0x80800928: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080092C:
    // 0x8080092C: jr          $ra
    // 0x80800930: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800930: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800934: nop

    // 0x80800938: nop

    // 0x8080093C: nop

;}
RECOMP_FUNC void func_80806540_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806540: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80806544: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80806548: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080654C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80806550: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80806554: jal         0x800AA074
    // 0x80806558: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800AA074(rdram, ctx);
        goto after_0;
    // 0x80806558: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080655C: jal         0x80088150
    // 0x80806560: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _gcfrontend_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80806560: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x80806564: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80806568: jal         0x80088158
    // 0x8080656C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _gcfrontend_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x8080656C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x80806570: blez        $s2, L_808065A0
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80806574: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_808065A0;
    }
    // 0x80806574: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80806578: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8080657C:
    // 0x8080657C: jal         0x80088148
    // 0x80806580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcfrontend_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80806580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80806584: beql        $v0, $zero, L_80806598
    if (ctx->r2 == 0) {
        // 0x80806588: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80806598;
    }
    goto skip_0;
    // 0x80806588: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8080658C: jal         0x800AA054
    // 0x80806590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800AA054(rdram, ctx);
        goto after_4;
    // 0x80806590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80806594: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80806598:
    // 0x80806598: bne         $s1, $s2, L_8080657C
    if (ctx->r17 != ctx->r18) {
        // 0x8080659C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8080657C;
    }
    // 0x8080659C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808065A0:
    // 0x808065A0: jal         0x80806744
    // 0x808065A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80806744_chgameselect(rdram, ctx);
        goto after_5;
    // 0x808065A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x808065A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808065AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808065B0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808065B4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808065B8: jr          $ra
    // 0x808065BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808065BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _idwave_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D18: syscall     736
    recomp_syscall_handler(rdram, ctx, 0x80088D18);
    return;
    // 0x80088D1C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bssnowball_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800558: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080055C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(356, 0X1064) << 16);
    // 0x80800560: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800564: jr          $ra
    // 0x80800568: lw          $v0, 0x1064($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X1064));
    return;
    // 0x80800568: lw          $v0, 0x1064($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X1064));
;}
RECOMP_FUNC void func_80800EF8_gcsectionskip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800EFC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800F00: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800F0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800F10: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800F14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800F18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800F1C: jal         0x800C05B8
    // 0x80800F20: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_800C05B8(rdram, ctx);
        goto after_0;
    // 0x80800F20: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x80800F24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800F28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F2C: jr          $ra
    // 0x80800F30: nop

    return;
    // 0x80800F30: nop

    // 0x80800F34: nop

    // 0x80800F38: nop

    // 0x80800F3C: nop

;}
RECOMP_FUNC void bskazfly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800418: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080041C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(236, 0X1C38) << 16);
    // 0x80800420: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800424: jr          $ra
    // 0x80800428: lw          $v0, 0x1C38($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1C38));
    return;
    // 0x80800428: lw          $v0, 0x1C38($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1C38));
;}
RECOMP_FUNC void bssplitup_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000E4: jal         0x80084950
    // 0x808000E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _baduo_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808000E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x808000EC: jal         0x8009E704
    // 0x808000F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bs_getNextState(rdram, ctx);
        goto after_1;
    // 0x808000F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808000F4: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x808000F8: beq         $v0, $at, L_80800108
    if (ctx->r2 == ctx->r1) {
        // 0x808000FC: addiu       $a0, $zero, 0x4F5
        ctx->r4 = ADD32(0, 0X4F5);
            goto L_80800108;
    }
    // 0x808000FC: addiu       $a0, $zero, 0x4F5
    ctx->r4 = ADD32(0, 0X4F5);
    // 0x80800100: jal         0x8008A298
    // 0x80800104: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    _sudialog_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800104: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_2:
L_80800108:
    // 0x80800108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080010C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800110: jr          $ra
    // 0x80800114: nop

    return;
    // 0x80800114: nop

;}
RECOMP_FUNC void _chfaircoin_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087268: syscall     540
    recomp_syscall_handler(rdram, ctx, 0x80087268);
    return;
    // 0x8008726C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bsbshock_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B08: syscall     27
    recomp_syscall_handler(rdram, ctx, 0x80082B08);
    return;
    // 0x80082B0C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chbubbleelevator_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BBC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2368, 0XC58) << 16);
    // 0x80800BC0: jr          $ra
    // 0x80800BC4: addiu       $v0, $v0, 0xC58
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2368, 0XC58));
    return;
    // 0x80800BC4: addiu       $v0, $v0, 0xC58
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2368, 0XC58));
;}
RECOMP_FUNC void func_8080154C_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080154C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801550: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801554: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80801558: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8080155C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80801560: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801564: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801568: jal         0x800D3948
    // 0x8080156C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x8080156C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80801570: beq         $v0, $zero, L_808015D8
    if (ctx->r2 == 0) {
        // 0x80801574: nop
    
            goto L_808015D8;
    }
    // 0x80801574: nop

    // 0x80801578: jal         0x80088398
    // 0x8080157C: nop

    _gcstatusDll_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x8080157C: nop

    after_1:
    // 0x80801580: beq         $v0, $zero, L_80801598
    if (ctx->r2 == 0) {
        // 0x80801584: nop
    
            goto L_80801598;
    }
    // 0x80801584: nop

    // 0x80801588: jal         0x8008A838
    // 0x8080158C: nop

    _suquiz_entrypoint_16(rdram, ctx);
        goto after_2;
    // 0x8080158C: nop

    after_2:
    // 0x80801590: b           L_808015E4
    // 0x80801594: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808015E4;
    // 0x80801594: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80801598:
    // 0x80801598: jal         0x800883A0
    // 0x8080159C: nop

    _gcstatusDll_entrypoint_18(rdram, ctx);
        goto after_3;
    // 0x8080159C: nop

    after_3:
    // 0x808015A0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808015A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808015A8: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x808015AC: addiu       $s3, $zero, 0x7
    ctx->r19 = ADD32(0, 0X7);
L_808015B0:
    // 0x808015B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808015B4: jal         0x80801784
    // 0x808015B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80801784_chquiz(rdram, ctx);
        goto after_4;
    // 0x808015B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x808015BC: slt         $t6, $v0, $s2
    ctx->r14 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x808015C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808015C4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x808015C8: bne         $s0, $s3, L_808015B0
    if (ctx->r16 != ctx->r19) {
        // 0x808015CC: or          $s1, $s1, $t6
        ctx->r17 = ctx->r17 | ctx->r14;
            goto L_808015B0;
    }
    // 0x808015CC: or          $s1, $s1, $t6
    ctx->r17 = ctx->r17 | ctx->r14;
    // 0x808015D0: b           L_808015E0
    // 0x808015D4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_808015E0;
    // 0x808015D4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_808015D8:
    // 0x808015D8: jal         0x8008A838
    // 0x808015DC: nop

    _suquiz_entrypoint_16(rdram, ctx);
        goto after_5;
    // 0x808015DC: nop

    after_5:
L_808015E0:
    // 0x808015E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808015E4:
    // 0x808015E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808015E8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808015EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808015F0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808015F4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808015F8: jr          $ra
    // 0x808015FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808015FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8080230C_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080230C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802310: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802314: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802318: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080231C: lb          $v0, 0x211($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X211);
    // 0x80802320: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802324: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80802328: beq         $v0, $at, L_8080234C
    if (ctx->r2 == ctx->r1) {
        // 0x8080232C: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_8080234C;
    }
    // 0x8080232C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80802330: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80802334: beq         $v0, $at, L_8080234C
    if (ctx->r2 == ctx->r1) {
        // 0x80802338: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8080234C;
    }
    // 0x80802338: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8080233C: beq         $v0, $at, L_8080234C
    if (ctx->r2 == ctx->r1) {
        // 0x80802340: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8080234C;
    }
    // 0x80802340: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80802344: bnel        $v0, $at, L_8080236C
    if (ctx->r2 != ctx->r1) {
        // 0x80802348: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080236C;
    }
    goto skip_0;
    // 0x80802348: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
L_8080234C:
    // 0x8080234C: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80802350: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802354: addiu       $a3, $a0, 0x28
    ctx->r7 = ADD32(ctx->r4, 0X28);
    // 0x80802358: jal         0x80802048
    // 0x8080235C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80802048_ncpoddialog(rdram, ctx);
        goto after_0;
    // 0x8080235C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80802360: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802364: lb          $v0, 0x211($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X211);
    // 0x80802368: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8080236C:
    // 0x8080236C: beq         $v0, $at, L_80802390
    if (ctx->r2 == ctx->r1) {
        // 0x80802370: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80802390;
    }
    // 0x80802370: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80802374: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802378: beq         $v0, $at, L_80802390
    if (ctx->r2 == ctx->r1) {
        // 0x8080237C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80802390;
    }
    // 0x8080237C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802380: beq         $v0, $at, L_80802390
    if (ctx->r2 == ctx->r1) {
        // 0x80802384: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80802390;
    }
    // 0x80802384: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80802388: bnel        $v0, $at, L_808023A8
    if (ctx->r2 != ctx->r1) {
        // 0x8080238C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808023A8;
    }
    goto skip_1;
    // 0x8080238C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_80802390:
    // 0x80802390: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80802394: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80802398: addiu       $a3, $a0, 0x34
    ctx->r7 = ADD32(ctx->r4, 0X34);
    // 0x8080239C: jal         0x80802048
    // 0x808023A0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_80802048_ncpoddialog(rdram, ctx);
        goto after_1;
    // 0x808023A0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x808023A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808023A8:
    // 0x808023A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808023AC: jr          $ra
    // 0x808023B0: nop

    return;
    // 0x808023B0: nop

;}
RECOMP_FUNC void func_80800E44_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E44: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800E48: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800E4C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800E50: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800E54: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800E58: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800E5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E60: lh          $t6, 0x1AC($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1AC);
    // 0x80800E64: lbu         $t7, 0x1B4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1B4);
    // 0x80800E68: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800E6C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800E70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800E74: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80800E78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800E7C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800E80: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800E84: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800E88: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80800E8C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800E90: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800E94: bgez        $t7, L_80800EA8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800E98: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80800EA8;
    }
    // 0x80800E98: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800E9C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800EA0: nop

    // 0x80800EA4: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80800EA8:
    // 0x80800EA8: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80800EAC: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2578, 0X3F3E) << 16);
    // 0x80800EB0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800EB4: addiu       $s4, $s4, 0x3F3E
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2578, 0X3F3E));
    // 0x80800EB8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800EBC: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80800EC0: nop

    // 0x80800EC4: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80800EC8: lbu         $t0, 0x1B5($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X1B5);
    // 0x80800ECC: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80800ED0: bgez        $t0, L_80800EE4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800ED4: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80800EE4;
    }
    // 0x80800ED4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800ED8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800EDC: nop

    // 0x80800EE0: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_80800EE4:
    // 0x80800EE4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80800EE8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800EEC: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800EF0: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x80800EF4: nop

    // 0x80800EF8: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80800EFC: lbu         $t3, 0x1B6($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X1B6);
    // 0x80800F00: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80800F04: bgez        $t3, L_80800F18
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800F08: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80800F18;
    }
    // 0x80800F08: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800F0C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800F10: nop

    // 0x80800F14: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_80800F18:
    // 0x80800F18: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80800F1C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800F20: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80800F24: nop

    // 0x80800F28: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x80800F2C: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x80800F30: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x80800F34: beql        $t6, $zero, L_80800FC0
    if (ctx->r14 == 0) {
        // 0x80800F38: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_80800FC0;
    }
    goto skip_0;
    // 0x80800F38: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    skip_0:
    // 0x80800F3C: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
L_80800F40:
    // 0x80800F40: jal         0x80800E24
    // 0x80800F44: nop

    func_80800E24_gczoombox(rdram, ctx);
        goto after_0;
    // 0x80800F44: nop

    after_0:
    // 0x80800F48: beq         $v0, $zero, L_80800FA0
    if (ctx->r2 == 0) {
        // 0x80800F4C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800FA0;
    }
    // 0x80800F4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800F50: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80800F54: lwc1        $f4, 0x1E8($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X1E8);
    // 0x80800F58: lbu         $t7, 0x0($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X0);
    // 0x80800F5C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80800F60: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800F64: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80800F68: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80800F6C: addu        $t0, $s4, $t9
    ctx->r8 = ADD32(ctx->r20, ctx->r25);
    // 0x80800F70: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800F74: jal         0x80088990
    // 0x80800F78: lh          $a1, 0x0($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X0);
    _fxfontstring_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800F78: lh          $a1, 0x0($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X0);
    after_1:
    // 0x80800F7C: lbu         $t2, 0x0($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X0);
    // 0x80800F80: beql        $t2, $zero, L_80800FB0
    if (ctx->r10 == 0) {
        // 0x80800F84: lbu         $a0, 0x1($s1)
        ctx->r4 = MEM_BU(ctx->r17, 0X1);
            goto L_80800FB0;
    }
    goto skip_1;
    // 0x80800F84: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    skip_1:
    // 0x80800F88: lbu         $t3, 0x1($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1);
L_80800F8C:
    // 0x80800F8C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800F90: bnel        $t3, $zero, L_80800F8C
    if (ctx->r11 != 0) {
        // 0x80800F94: lbu         $t3, 0x1($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X1);
            goto L_80800F8C;
    }
    goto skip_2;
    // 0x80800F94: lbu         $t3, 0x1($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1);
    skip_2:
    // 0x80800F98: b           L_80800FB0
    // 0x80800F9C: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
        goto L_80800FB0;
    // 0x80800F9C: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
L_80800FA0:
    // 0x80800FA0: lbu         $t4, 0x0($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X0);
    // 0x80800FA4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800FA8: sb          $t4, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r12;
    // 0x80800FAC: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
L_80800FB0:
    // 0x80800FB0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800FB4: bne         $a0, $zero, L_80800F40
    if (ctx->r4 != 0) {
        // 0x80800FB8: nop
    
            goto L_80800F40;
    }
    // 0x80800FB8: nop

    // 0x80800FBC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80800FC0:
    // 0x80800FC0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800FC4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800FC8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800FCC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800FD0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800FD8: jr          $ra
    // 0x80800FDC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800FDC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void bskaztorpedo_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080136C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801370: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(296, 0X1884) << 16);
    // 0x80801374: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801378: jr          $ra
    // 0x8080137C: lw          $v0, 0x1884($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(296, 0X1884));
    return;
    // 0x8080137C: lw          $v0, 0x1884($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(296, 0X1884));
;}
RECOMP_FUNC void _fxfontstring_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088980: syscall     713
    recomp_syscall_handler(rdram, ctx, 0x80088980);
    return;
    // 0x80088984: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80113410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113410: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80113414: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80113418: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8011341C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80113420: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80113424: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80113428: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8011342C: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x80113430: lw          $t6, 0x28($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X28);
L_80113434:
    // 0x80113434: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80113438: lbu         $a0, 0x34($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X34);
    // 0x8011343C: beql        $a0, $zero, L_8011345C
    if (ctx->r4 == 0) {
        // 0x80113440: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8011345C;
    }
    goto skip_0;
    // 0x80113440: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80113444: jal         0x800E87E0
    // 0x80113448: nop

    func_800E87E0(rdram, ctx);
        goto after_0;
    // 0x80113448: nop

    after_0:
    // 0x8011344C: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x80113450: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80113454: sb          $zero, 0x34($t9)
    MEM_B(0X34, ctx->r25) = 0;
    // 0x80113458: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8011345C:
    // 0x8011345C: bnel        $s0, $s2, L_80113434
    if (ctx->r16 != ctx->r18) {
        // 0x80113460: lw          $t6, 0x28($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X28);
            goto L_80113434;
    }
    goto skip_1;
    // 0x80113460: lw          $t6, 0x28($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X28);
    skip_1:
    // 0x80113464: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80113468: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8011346C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80113470: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80113474: jr          $ra
    // 0x80113478: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80113478: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80016928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016928: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001692C: jr          $ra
    // 0x80016930: addiu       $v0, $v0, -0x6488
    ctx->r2 = ADD32(ctx->r2, -0X6488);
    return;
    // 0x80016930: addiu       $v0, $v0, -0x6488
    ctx->r2 = ADD32(ctx->r2, -0X6488);
;}
RECOMP_FUNC void _babee_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084580: syscall     114
    recomp_syscall_handler(rdram, ctx, 0x80084580);
    return;
    // 0x80084584: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800280_chvandoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800280: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800284: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080028C: beq         $a1, $at, L_80800314
    if (ctx->r5 == ctx->r1) {
        // 0x80800290: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800314;
    }
    // 0x80800290: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800294: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800298: beq         $a1, $at, L_80800340
    if (ctx->r5 == ctx->r1) {
        // 0x8080029C: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_80800340;
    }
    // 0x8080029C: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x808002A0: bne         $a1, $at, L_8080036C
    if (ctx->r5 != ctx->r1) {
        // 0x808002A4: nop
    
            goto L_8080036C;
    }
    // 0x808002A4: nop

    // 0x808002A8: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808002AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002B0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808002B4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808002B8: bne         $t7, $at, L_80800374
    if (ctx->r15 != ctx->r1) {
        // 0x808002BC: addiu       $a1, $sp, 0x1C
        ctx->r5 = ADD32(ctx->r29, 0X1C);
            goto L_80800374;
    }
    // 0x808002BC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808002C0: jal         0x800F5A00
    // 0x808002C4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800F5A00(rdram, ctx);
        goto after_0;
    // 0x808002C4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x808002C8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808002CC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x808002D0: jal         0x800EEB40
    // 0x808002D4: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_1;
    // 0x808002D4: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    after_1:
    // 0x808002D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1168, 0X630) << 16);
    // 0x808002DC: lwc1        $f4, 0x630($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1168, 0X630));
    // 0x808002E0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808002E4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808002E8: nop

    // 0x808002EC: bc1fl       L_80800378
    if (!c1cs) {
        // 0x808002F0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800378;
    }
    goto skip_0;
    // 0x808002F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808002F4: lhu         $a2, 0x76($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0X76);
    // 0x808002F8: addiu       $a0, $zero, 0x3CC
    ctx->r4 = ADD32(0, 0X3CC);
    // 0x808002FC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800300: srl         $t8, $a2, 7
    ctx->r24 = S32(U32(ctx->r6) >> 7);
    // 0x80800304: jal         0x80101180
    // 0x80800308: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    func_80101180(rdram, ctx);
        goto after_2;
    // 0x80800308: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_2:
    // 0x8080030C: b           L_80800378
    // 0x80800310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800378;
    // 0x80800310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800314:
    // 0x80800314: lhu         $t9, 0x76($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X76);
    // 0x80800318: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080031C: srl         $t0, $t9, 7
    ctx->r8 = S32(U32(ctx->r25) >> 7);
    // 0x80800320: beq         $a2, $t0, L_80800330
    if (ctx->r6 == ctx->r8) {
        // 0x80800324: nop
    
            goto L_80800330;
    }
    // 0x80800324: nop

    // 0x80800328: b           L_80800378
    // 0x8080032C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800378;
    // 0x8080032C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800330:
    // 0x80800330: jal         0x80800388
    // 0x80800334: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800388_chvandoor(rdram, ctx);
        goto after_3;
    // 0x80800334: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800338: b           L_80800378
    // 0x8080033C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800378;
    // 0x8080033C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800340:
    // 0x80800340: lhu         $t1, 0x76($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X76);
    // 0x80800344: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800348: srl         $t2, $t1, 7
    ctx->r10 = S32(U32(ctx->r9) >> 7);
    // 0x8080034C: beq         $a2, $t2, L_8080035C
    if (ctx->r6 == ctx->r10) {
        // 0x80800350: nop
    
            goto L_8080035C;
    }
    // 0x80800350: nop

    // 0x80800354: b           L_80800378
    // 0x80800358: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800378;
    // 0x80800358: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080035C:
    // 0x8080035C: jal         0x80800388
    // 0x80800360: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800388_chvandoor(rdram, ctx);
        goto after_4;
    // 0x80800360: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80800364: b           L_80800378
    // 0x80800368: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800378;
    // 0x80800368: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080036C:
    // 0x8080036C: b           L_80800378
    // 0x80800370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800378;
    // 0x80800370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800374:
    // 0x80800374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800378:
    // 0x80800378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080037C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800380: jr          $ra
    // 0x80800384: nop

    return;
    // 0x80800384: nop

;}
RECOMP_FUNC void func_800B37B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B37B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B37BC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800B37C0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800B37C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B37C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B37CC: jal         0x800EE830
    // 0x800B37D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800EE830(rdram, ctx);
        goto after_0;
    // 0x800B37D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800B37D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B37D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B37DC: jr          $ra
    // 0x800B37E0: nop

    return;
    // 0x800B37E0: nop

;}
RECOMP_FUNC void func_8010DA70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010DA70: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8010DA74: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // 0x8010DA78: lbu         $a1, 0x4730($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X4730);
    // 0x8010DA7C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8010DA80: addiu       $t7, $t7, 0x6F90
    ctx->r15 = ADD32(ctx->r15, 0X6F90);
    // 0x8010DA84: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x8010DA88: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x8010DA8C: bne         $at, $zero, L_8010DAD0
    if (ctx->r1 != 0) {
        // 0x8010DA90: addu        $v1, $t6, $t7
        ctx->r3 = ADD32(ctx->r14, ctx->r15);
            goto L_8010DAD0;
    }
    // 0x8010DA90: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8010DA94: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x8010DA98: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8010DA9C: addu        $a2, $t9, $t7
    ctx->r6 = ADD32(ctx->r25, ctx->r15);
    // 0x8010DAA0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8010DAA4: sll         $a3, $a1, 3
    ctx->r7 = S32(ctx->r5 << 3);
L_8010DAA8:
    // 0x8010DAA8: lw          $t0, 0x4($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X4);
    // 0x8010DAAC: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x8010DAB0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8010DAB4: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8010DAB8: beql        $at, $zero, L_8010DAC8
    if (ctx->r1 == 0) {
        // 0x8010DABC: slt         $at, $v0, $a3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_8010DAC8;
    }
    goto skip_0;
    // 0x8010DABC: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    skip_0:
    // 0x8010DAC0: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8010DAC4: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
L_8010DAC8:
    // 0x8010DAC8: bne         $at, $zero, L_8010DAA8
    if (ctx->r1 != 0) {
        // 0x8010DACC: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_8010DAA8;
    }
    // 0x8010DACC: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_8010DAD0:
    // 0x8010DAD0: jr          $ra
    // 0x8010DAD4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8010DAD4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8010DAD8: nop

    // 0x8010DADC: nop

;}
RECOMP_FUNC void _glzone_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088760: syscall     703
    recomp_syscall_handler(rdram, ctx, 0x80088760);
    return;
    // 0x80088764: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void gcgamefix_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800054: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800058: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080005C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800060: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800064: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800068: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080006C: addiu       $s2, $zero, 0x9
    ctx->r18 = ADD32(0, 0X9);
L_80800070:
    // 0x80800070: jal         0x800D1338
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D1338(rdram, ctx);
        goto after_0;
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800078: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080007C: jal         0x800D129C
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D129C(rdram, ctx);
        goto after_1;
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800084: bne         $v0, $s1, L_808000AC
    if (ctx->r2 != ctx->r17) {
        // 0x80800088: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_808000AC;
    }
    // 0x80800088: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080008C: addiu       $s1, $s0, 0x51
    ctx->r17 = ADD32(ctx->r16, 0X51);
    // 0x80800090: jal         0x800D0B68
    // 0x80800094: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x80800094: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800098: bne         $v0, $zero, L_808000AC
    if (ctx->r2 != 0) {
        // 0x8080009C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808000AC;
    }
    // 0x8080009C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000A4: jal         0x800D0C78
    // 0x808000A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800D0C78(rdram, ctx);
        goto after_3;
    // 0x808000A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
L_808000AC:
    // 0x808000AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808000B0: bne         $s0, $s2, L_80800070
    if (ctx->r16 != ctx->r18) {
        // 0x808000B4: nop
    
            goto L_80800070;
    }
    // 0x808000B4: nop

    // 0x808000B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000C0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808000C4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808000C8: jr          $ra
    // 0x808000CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808000CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800DCEC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DCEC8: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x800DCECC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800DCED0: beq         $v0, $at, L_800DCEE8
    if (ctx->r2 == ctx->r1) {
        // 0x800DCED4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800DCEE8;
    }
    // 0x800DCED4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800DCED8: beql        $v0, $at, L_800DCF1C
    if (ctx->r2 == ctx->r1) {
        // 0x800DCEDC: lw          $v1, 0x0($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X0);
            goto L_800DCF1C;
    }
    goto skip_0;
    // 0x800DCEDC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800DCEE0: jr          $ra
    // 0x800DCEE4: nop

    return;
    // 0x800DCEE4: nop

L_800DCEE8:
    // 0x800DCEE8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800DCEEC: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800DCEF0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800DCEF4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800DCEF8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800DCEFC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800DCF00: lw          $t8, -0x37E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X37E0);
    // 0x800DCF04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DCF08: ori         $at, $at, 0x68
    ctx->r1 = ctx->r1 | 0X68;
    // 0x800DCF0C: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800DCF10: jr          $ra
    // 0x800DCF14: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    return;
    // 0x800DCF14: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800DCF18: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_800DCF1C:
    // 0x800DCF1C: lui         $t1, 0xDE00
    ctx->r9 = S32(0XDE00 << 16);
    // 0x800DCF20: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800DCF24: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x800DCF28: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800DCF2C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800DCF30: lw          $t2, -0x37E0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X37E0);
    // 0x800DCF34: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DCF38: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x800DCF3C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800DCF40: jr          $ra
    // 0x800DCF44: nop

    return;
    // 0x800DCF44: nop

;}
