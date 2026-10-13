#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void suexpression_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003E4: jal         0x80100094
    // 0x808003E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808003EC: beq         $v0, $zero, L_80800400
    if (ctx->r2 == 0) {
        // 0x808003F0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800400;
    }
    // 0x808003F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808003F8: jal         0x80100074
    // 0x808003FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_1;
    // 0x808003FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_80800400:
    // 0x80800400: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800404: lbu         $t7, 0x95($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X95);
    // 0x80800408: andi        $t8, $t7, 0xFFF3
    ctx->r24 = ctx->r15 & 0XFFF3;
    // 0x8080040C: sb          $t8, 0x95($t6)
    MEM_B(0X95, ctx->r14) = ctx->r24;
    // 0x80800410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800418: jr          $ra
    // 0x8080041C: nop

    return;
    // 0x8080041C: nop

;}
RECOMP_FUNC void func_80801C7C_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801C80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C84: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801C88: jal         0x80089C78
    // 0x80801C8C: addiu       $a0, $zero, 0x52C
    ctx->r4 = ADD32(0, 0X52C);
    _subaddiefind_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80801C8C: addiu       $a0, $zero, 0x52C
    ctx->r4 = ADD32(0, 0X52C);
    after_0:
    // 0x80801C90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801C94: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801C98: jal         0x80102424
    // 0x80801C9C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80801C9C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801CA0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801CA4: lbu         $t7, 0x65($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X65);
    // 0x80801CA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80801CAC: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80801CB0: sb          $t8, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r24;
    // 0x80801CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801CB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801CBC: jr          $ra
    // 0x80801CC0: nop

    return;
    // 0x80801CC0: nop

;}
RECOMP_FUNC void cosectionstor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800044: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800048: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080004C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80800050: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80800054: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800058: addiu       $s1, $s1, 0x75C0
    ctx->r17 = ADD32(ctx->r17, 0X75C0);
    // 0x8080005C: addiu       $s0, $s0, 0x7198
    ctx->r16 = ADD32(ctx->r16, 0X7198);
    // 0x80800060: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80800064:
    // 0x80800064: beql        $a0, $zero, L_8080007C
    if (ctx->r4 == 0) {
        // 0x80800068: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8080007C;
    }
    goto skip_0;
    // 0x80800068: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x8080006C: jal         0x8001B084
    // 0x80800070: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x80800070: nop

    after_0:
    // 0x80800074: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80800078: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8080007C:
    // 0x8080007C: bnel        $s0, $s1, L_80800064
    if (ctx->r16 != ctx->r17) {
        // 0x80800080: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80800064;
    }
    goto skip_1;
    // 0x80800080: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80800084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800088: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080008C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800090: jr          $ra
    // 0x80800094: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800094: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800000_glgamedata(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
;}
RECOMP_FUNC void gczoombox_entrypoint_42(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803D0C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80803D10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803D14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803D18: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80803D1C: jal         0x80800358
    // 0x80803D20: nop

    func_80800358_gczoombox(rdram, ctx);
        goto after_0;
    // 0x80803D20: nop

    after_0:
    // 0x80803D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803D28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803D2C: jr          $ra
    // 0x80803D30: nop

    return;
    // 0x80803D30: nop

;}
RECOMP_FUNC void chmonsterinterior_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1320, 0X1F58) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0x1F58
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1320, 0X1F58));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0x1F58
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1320, 0X1F58));
;}
RECOMP_FUNC void func_80800DB8_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800DBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800DC0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800DC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800DC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800DCC: beq         $a1, $at, L_80800DF4
    if (ctx->r5 == ctx->r1) {
        // 0x80800DD0: sb          $a1, 0x15C($a0)
        MEM_B(0X15C, ctx->r4) = ctx->r5;
            goto L_80800DF4;
    }
    // 0x80800DD0: sb          $a1, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = ctx->r5;
    // 0x80800DD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800DD8: beq         $a1, $at, L_80800E40
    if (ctx->r5 == ctx->r1) {
        // 0x80800DDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E40;
    }
    // 0x80800DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800DE4: beq         $a1, $at, L_80800E90
    if (ctx->r5 == ctx->r1) {
        // 0x80800DE8: nop
    
            goto L_80800E90;
    }
    // 0x80800DE8: nop

    // 0x80800DEC: b           L_80800E9C
    // 0x80800DF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E9C;
    // 0x80800DF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800DF4:
    // 0x80800DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DF8: addiu       $a1, $zero, 0x1EE
    ctx->r5 = ADD32(0, 0X1EE);
    // 0x80800DFC: jal         0x8008CB3C
    // 0x80800E00: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x80800E00: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_0:
    // 0x80800E04: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800E08: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800E18: jal         0x8009FFD8
    // 0x80800E1C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800E1C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
    // 0x80800E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E24: jal         0x8009B9B0
    // 0x80800E28: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800E28: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E30: jal         0x8009BA9C
    // 0x80800E34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_3;
    // 0x80800E34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800E38: b           L_80800E98
    // 0x80800E3C: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
        goto L_80800E98;
    // 0x80800E3C: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
L_80800E40:
    // 0x80800E40: addiu       $a1, $zero, 0x1F1
    ctx->r5 = ADD32(0, 0X1F1);
    // 0x80800E44: jal         0x8008CCBC
    // 0x80800E48: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_4;
    // 0x80800E48: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_4:
    // 0x80800E4C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800E50: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800E60: jal         0x8009FFD8
    // 0x80800E64: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_5;
    // 0x80800E64: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_5:
    // 0x80800E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E6C: jal         0x8009B9B0
    // 0x80800E70: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x80800E70: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80800E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E78: jal         0x8009BA9C
    // 0x80800E7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_7;
    // 0x80800E7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800E80: jal         0x800FC660
    // 0x80800E84: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC660(rdram, ctx);
        goto after_8;
    // 0x80800E84: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_8:
    // 0x80800E88: b           L_80800E9C
    // 0x80800E8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E9C;
    // 0x80800E8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E90:
    // 0x80800E90: jal         0x80800D84
    // 0x80800E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D84_bsstatue(rdram, ctx);
        goto after_9;
    // 0x80800E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80800E98:
    // 0x80800E98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E9C:
    // 0x80800E9C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800EA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800EA4: jr          $ra
    // 0x80800EA8: nop

    return;
    // 0x80800EA8: nop

;}
RECOMP_FUNC void func_80096440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80096444: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80096448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009644C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80096450: lw          $a1, 0x94($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X94);
    // 0x80096454: jal         0x800EE7F8
    // 0x80096458: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80096458: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    after_0:
    // 0x8009645C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80096464: jr          $ra
    // 0x80096468: nop

    return;
    // 0x80096468: nop

;}
RECOMP_FUNC void func_80807264_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80807268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080726C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80807270: jal         0x800852F0
    // 0x80807274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_0;
    // 0x80807274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80807278: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080727C: jal         0x80085330
    // 0x80807280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_isZero(rdram, ctx);
        goto after_1;
    // 0x80807280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80807284: beql        $v0, $zero, L_808072A8
    if (ctx->r2 == 0) {
        // 0x80807288: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808072A8;
    }
    goto skip_0;
    // 0x80807288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080728C: jal         0x80084490
    // 0x80807290: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bababykaz_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80807290: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80807294: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80807298: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080729C: jal         0x800F9AAC
    // 0x808072A0: lw          $a0, 0x184($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X184);
    func_800F9AAC(rdram, ctx);
        goto after_3;
    // 0x808072A0: lw          $a0, 0x184($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X184);
    after_3:
    // 0x808072A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808072A8:
    // 0x808072A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808072AC: jr          $ra
    // 0x808072B0: nop

    return;
    // 0x808072B0: nop

;}
RECOMP_FUNC void func_800A1968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1968: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x800A196C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800A1970: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A1974: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800A1978: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800A197C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A1980: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800A1984: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800A1988: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800A198C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800A1990: sw          $a0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r4;
    // 0x800A1994: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800A1998: swc1        $f24, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f24.u32l;
    // 0x800A199C: swc1        $f24, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f24.u32l;
    // 0x800A19A0: swc1        $f24, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f24.u32l;
    // 0x800A19A4: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    // 0x800A19A8: jal         0x80091E80
    // 0x800A19AC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80091E80(rdram, ctx);
        goto after_0;
    // 0x800A19AC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x800A19B0: beq         $v0, $zero, L_800A1EE8
    if (ctx->r2 == 0) {
        // 0x800A19B4: lw          $a0, 0x128($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X128);
            goto L_800A1EE8;
    }
    // 0x800A19B4: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    // 0x800A19B8: jal         0x8009C128
    // 0x800A19BC: addiu       $a1, $sp, 0x11C
    ctx->r5 = ADD32(ctx->r29, 0X11C);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x800A19BC: addiu       $a1, $sp, 0x11C
    ctx->r5 = ADD32(ctx->r29, 0X11C);
    after_1:
    // 0x800A19C0: jal         0x80096364
    // 0x800A19C4: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    func_80096364(rdram, ctx);
        goto after_2;
    // 0x800A19C4: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    after_2:
    // 0x800A19C8: lwc1        $f6, 0x120($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800A19CC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800A19D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A19D4: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800A19D8: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x800A19DC: nop

    // 0x800A19E0: bc1tl       L_800A1EEC
    if (c1cs) {
        // 0x800A19E4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800A1EEC;
    }
    goto skip_0;
    // 0x800A19E4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x800A19E8: jal         0x80096628
    // 0x800A19EC: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    func_80096628(rdram, ctx);
        goto after_3;
    // 0x800A19EC: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    after_3:
    // 0x800A19F0: sll         $t6, $v0, 10
    ctx->r14 = S32(ctx->r2 << 10);
    // 0x800A19F4: bltz        $t6, L_800A1EE8
    if (SIGNED(ctx->r14) < 0) {
        // 0x800A19F8: sw          $v0, 0xF4($sp)
        MEM_W(0XF4, ctx->r29) = ctx->r2;
            goto L_800A1EE8;
    }
    // 0x800A19F8: sw          $v0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r2;
    // 0x800A19FC: addiu       $s1, $sp, 0x6C
    ctx->r17 = ADD32(ctx->r29, 0X6C);
    // 0x800A1A00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A1A04: jal         0x80096604
    // 0x800A1A08: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    func_80096604(rdram, ctx);
        goto after_4;
    // 0x800A1A08: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    after_4:
    // 0x800A1A0C: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    // 0x800A1A10: jal         0x800965E0
    // 0x800A1A14: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    func_800965E0(rdram, ctx);
        goto after_5;
    // 0x800A1A14: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    after_5:
    // 0x800A1A18: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800A1A1C: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    // 0x800A1A20: addiu       $t0, $sp, 0x9C
    ctx->r8 = ADD32(ctx->r29, 0X9C);
    // 0x800A1A24: addiu       $a2, $sp, 0xC0
    ctx->r6 = ADD32(ctx->r29, 0XC0);
    // 0x800A1A28: addiu       $t1, $sp, 0xCC
    ctx->r9 = ADD32(ctx->r29, 0XCC);
    // 0x800A1A2C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_800A1A30:
    // 0x800A1A30: swc1        $f22, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f22.u32l;
    // 0x800A1A34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A1A38: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800A1A3C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_800A1A40:
    // 0x800A1A40: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x800A1A44: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800A1A48: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A1A4C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A1A50: bne         $v0, $a1, L_800A1A40
    if (ctx->r2 != ctx->r5) {
        // 0x800A1A54: sw          $t7, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r15;
            goto L_800A1A40;
    }
    // 0x800A1A54: sw          $t7, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r15;
    // 0x800A1A58: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800A1A5C: sltu        $at, $a2, $t1
    ctx->r1 = ctx->r6 < ctx->r9 ? 1 : 0;
    // 0x800A1A60: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x800A1A64: bne         $at, $zero, L_800A1A30
    if (ctx->r1 != 0) {
        // 0x800A1A68: addiu       $t0, $t0, 0xC
        ctx->r8 = ADD32(ctx->r8, 0XC);
            goto L_800A1A30;
    }
    // 0x800A1A68: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x800A1A6C: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x800A1A70: jal         0x800F36D4
    // 0x800A1A74: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    func_800F36D4(rdram, ctx);
        goto after_6;
    // 0x800A1A74: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    after_6:
    // 0x800A1A78: beq         $v0, $zero, L_800A1AA4
    if (ctx->r2 == 0) {
        // 0x800A1A7C: addiu       $s0, $sp, 0x9C
        ctx->r16 = ADD32(ctx->r29, 0X9C);
            goto L_800A1AA4;
    }
    // 0x800A1A7C: addiu       $s0, $sp, 0x9C
    ctx->r16 = ADD32(ctx->r29, 0X9C);
    // 0x800A1A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A1A84: jal         0x800F36D4
    // 0x800A1A88: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    func_800F36D4(rdram, ctx);
        goto after_7;
    // 0x800A1A88: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    after_7:
    // 0x800A1A8C: beq         $v0, $zero, L_800A1AA4
    if (ctx->r2 == 0) {
        // 0x800A1A90: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800A1AA4;
    }
    // 0x800A1A90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A1A94: jal         0x800EE84C
    // 0x800A1A98: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE84C(rdram, ctx);
        goto after_8;
    // 0x800A1A98: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800A1A9C: b           L_800A1CC4
    // 0x800A1AA0: nop

        goto L_800A1CC4;
    // 0x800A1AA0: nop

L_800A1AA4:
    // 0x800A1AA4: swc1        $f22, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f22.u32l;
    // 0x800A1AA8: addiu       $a0, $sp, 0x110
    ctx->r4 = ADD32(ctx->r29, 0X110);
    // 0x800A1AAC: addiu       $a1, $sp, 0x11C
    ctx->r5 = ADD32(ctx->r29, 0X11C);
    // 0x800A1AB0: jal         0x800EFB24
    // 0x800A1AB4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_9;
    // 0x800A1AB4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_9:
    // 0x800A1AB8: swc1        $f22, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f22.u32l;
    // 0x800A1ABC: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x800A1AC0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A1AC4: jal         0x800EFB24
    // 0x800A1AC8: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    func_800EFB24(rdram, ctx);
        goto after_10;
    // 0x800A1AC8: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    after_10:
    // 0x800A1ACC: addiu       $s0, $sp, 0xE4
    ctx->r16 = ADD32(ctx->r29, 0XE4);
    // 0x800A1AD0: swc1        $f22, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f22.u32l;
    // 0x800A1AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A1AD8: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x800A1ADC: jal         0x800EFB24
    // 0x800A1AE0: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    func_800EFB24(rdram, ctx);
        goto after_11;
    // 0x800A1AE0: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    after_11:
    // 0x800A1AE4: lwc1        $f10, 0xEC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800A1AE8: lwc1        $f0, 0xE4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800A1AEC: swc1        $f22, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f22.u32l;
    // 0x800A1AF0: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800A1AF4: addiu       $a0, $sp, 0x110
    ctx->r4 = ADD32(ctx->r29, 0X110);
    // 0x800A1AF8: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    // 0x800A1AFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800A1B00: jal         0x800EEAA4
    // 0x800A1B04: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    func_800EEAA4(rdram, ctx);
        goto after_12;
    // 0x800A1B04: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x800A1B08: c.eq.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl == ctx->f22.fl;
    // 0x800A1B0C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800A1B10: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x800A1B14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800A1B18: bc1f        L_800A1B24
    if (!c1cs) {
        // 0x800A1B1C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800A1B24;
    }
    // 0x800A1B1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A1B20: lwc1        $f12, 0x54A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X54A0);
L_800A1B24:
    // 0x800A1B24: jal         0x800EEAA4
    // 0x800A1B28: swc1        $f12, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f12.u32l;
    func_800EEAA4(rdram, ctx);
        goto after_13;
    // 0x800A1B28: swc1        $f12, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f12.u32l;
    after_13:
    // 0x800A1B2C: lwc1        $f12, 0x100($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800A1B30: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x800A1B34: lwc1        $f6, 0x110($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800A1B38: div.s       $f2, $f18, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800A1B3C: lwc1        $f16, 0x118($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800A1B40: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A1B44: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x800A1B48: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800A1B4C: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800A1B50: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800A1B54: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800A1B58: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800A1B5C: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800A1B60: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A1B64: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800A1B68: jal         0x800EFA4C
    // 0x800A1B6C: nop

    func_800EFA4C(rdram, ctx);
        goto after_14;
    // 0x800A1B6C: nop

    after_14:
    // 0x800A1B70: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    // 0x800A1B74: addiu       $a1, $sp, 0xCC
    ctx->r5 = ADD32(ctx->r29, 0XCC);
    // 0x800A1B78: jal         0x800EFB24
    // 0x800A1B7C: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    func_800EFB24(rdram, ctx);
        goto after_15;
    // 0x800A1B7C: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    after_15:
    // 0x800A1B80: jal         0x800EEF94
    // 0x800A1B84: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    func_800EEF94(rdram, ctx);
        goto after_16;
    // 0x800A1B84: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    after_16:
    // 0x800A1B88: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800A1B8C: jal         0x800EEF94
    // 0x800A1B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EEF94(rdram, ctx);
        goto after_17;
    // 0x800A1B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x800A1B94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A1B98: lwc1        $f8, 0x54A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X54A4);
    // 0x800A1B9C: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800A1BA0: addiu       $v0, $sp, 0x9C
    ctx->r2 = ADD32(ctx->r29, 0X9C);
    // 0x800A1BA4: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800A1BA8: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x800A1BAC: div.s       $f2, $f20, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f10.fl);
    // 0x800A1BB0: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800A1BB4: lw          $t8, 0x18($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X18);
    // 0x800A1BB8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A1BBC: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x800A1BC0: beq         $at, $zero, L_800A1C00
    if (ctx->r1 == 0) {
        // 0x800A1BC4: subu        $t9, $t8, $a0
        ctx->r25 = SUB32(ctx->r24, ctx->r4);
            goto L_800A1C00;
    }
    // 0x800A1BC4: subu        $t9, $t8, $a0
    ctx->r25 = SUB32(ctx->r24, ctx->r4);
L_800A1BC8:
    // 0x800A1BC8: mtc1        $t9, $f20
    ctx->f20.u32l = ctx->r25;
    // 0x800A1BCC: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x800A1BD0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A1BD4: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x800A1BD8: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x800A1BDC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A1BE0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A1BE4: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800A1BE8: add.s       $f18, $f20, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x800A1BEC: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800A1BF0: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x800A1BF4: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x800A1BF8: bne         $at, $zero, L_800A1BC8
    if (ctx->r1 != 0) {
        // 0x800A1BFC: subu        $t9, $t8, $a0
        ctx->r25 = SUB32(ctx->r24, ctx->r4);
            goto L_800A1BC8;
    }
    // 0x800A1BFC: subu        $t9, $t8, $a0
    ctx->r25 = SUB32(ctx->r24, ctx->r4);
L_800A1C00:
    // 0x800A1C00: mtc1        $t9, $f20
    ctx->f20.u32l = ctx->r25;
    // 0x800A1C04: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x800A1C08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A1C0C: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x800A1C10: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A1C14: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800A1C18: add.s       $f18, $f20, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x800A1C1C: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800A1C20: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    // 0x800A1C24: addiu       $a1, $sp, 0xCC
    ctx->r5 = ADD32(ctx->r29, 0XCC);
    // 0x800A1C28: jal         0x800EFB24
    // 0x800A1C2C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_18;
    // 0x800A1C2C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_18:
    // 0x800A1C30: jal         0x800EEF94
    // 0x800A1C34: addiu       $a0, $sp, 0x110
    ctx->r4 = ADD32(ctx->r29, 0X110);
    func_800EEF94(rdram, ctx);
        goto after_19;
    // 0x800A1C34: addiu       $a0, $sp, 0x110
    ctx->r4 = ADD32(ctx->r29, 0X110);
    after_19:
    // 0x800A1C38: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800A1C3C: jal         0x800EEF94
    // 0x800A1C40: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    func_800EEF94(rdram, ctx);
        goto after_20;
    // 0x800A1C40: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    after_20:
    // 0x800A1C44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A1C48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A1C4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A1C50: lwc1        $f18, 0x54A8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X54A8);
    // 0x800A1C54: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800A1C58: addiu       $v0, $sp, 0x9C
    ctx->r2 = ADD32(ctx->r29, 0X9C);
    // 0x800A1C5C: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x800A1C60: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x800A1C64: div.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f20.fl, ctx->f4.fl);
    // 0x800A1C68: sub.s       $f2, $f16, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800A1C6C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A1C70: beq         $v0, $a0, L_800A1CA4
    if (ctx->r2 == ctx->r4) {
        // 0x800A1C74: lw          $t2, -0x4($v0)
        ctx->r10 = MEM_W(ctx->r2, -0X4);
            goto L_800A1CA4;
    }
    // 0x800A1C74: lw          $t2, -0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, -0X4);
L_800A1C78:
    // 0x800A1C78: mtc1        $t2, $f20
    ctx->f20.u32l = ctx->r10;
    // 0x800A1C7C: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800A1C80: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A1C84: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x800A1C88: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A1C8C: sub.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f18.fl;
    // 0x800A1C90: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800A1C94: add.s       $f18, $f20, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x800A1C98: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800A1C9C: bne         $v0, $a0, L_800A1C78
    if (ctx->r2 != ctx->r4) {
        // 0x800A1CA0: lw          $t2, -0x4($v0)
        ctx->r10 = MEM_W(ctx->r2, -0X4);
            goto L_800A1C78;
    }
    // 0x800A1CA0: lw          $t2, -0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, -0X4);
L_800A1CA4:
    // 0x800A1CA4: mtc1        $t2, $f20
    ctx->f20.u32l = ctx->r10;
    // 0x800A1CA8: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800A1CAC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A1CB0: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x800A1CB4: sub.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f18.fl;
    // 0x800A1CB8: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800A1CBC: add.s       $f18, $f20, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x800A1CC0: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
L_800A1CC4:
    // 0x800A1CC4: jal         0x800962D4
    // 0x800A1CC8: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    func_800962D4(rdram, ctx);
        goto after_21;
    // 0x800A1CC8: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    after_21:
    // 0x800A1CCC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800A1CD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A1CD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A1CD8: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800A1CDC: div.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
L_800A1CE0:
    // 0x800A1CE0: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800A1CE4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A1CE8: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x800A1CEC: sub.s       $f8, $f24, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x800A1CF0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A1CF4: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800A1CF8: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800A1CFC: bne         $at, $zero, L_800A1CE0
    if (ctx->r1 != 0) {
        // 0x800A1D00: swc1        $f18, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
            goto L_800A1CE0;
    }
    // 0x800A1D00: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800A1D04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A1D08: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_800A1D0C:
    // 0x800A1D0C: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800A1D10: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A1D14: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x800A1D18: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x800A1D1C: nop

    // 0x800A1D20: bc1fl       L_800A1D34
    if (!c1cs) {
        // 0x800A1D24: c.lt.s      $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
            goto L_800A1D34;
    }
    goto skip_1;
    // 0x800A1D24: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    skip_1:
    // 0x800A1D28: swc1        $f24, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f24.u32l;
    // 0x800A1D2C: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800A1D30: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
L_800A1D34:
    // 0x800A1D34: nop

    // 0x800A1D38: bc1f        L_800A1D44
    if (!c1cs) {
        // 0x800A1D3C: nop
    
            goto L_800A1D44;
    }
    // 0x800A1D3C: nop

    // 0x800A1D40: swc1        $f22, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f22.u32l;
L_800A1D44:
    // 0x800A1D44: bne         $at, $zero, L_800A1D0C
    if (ctx->r1 != 0) {
        // 0x800A1D48: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800A1D0C;
    }
    // 0x800A1D48: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A1D4C: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    // 0x800A1D50: jal         0x80091E80
    // 0x800A1D54: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80091E80(rdram, ctx);
        goto after_22;
    // 0x800A1D54: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_22:
    // 0x800A1D58: beql        $v0, $zero, L_800A1DFC
    if (ctx->r2 == 0) {
        // 0x800A1D5C: lw          $t8, 0x128($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X128);
            goto L_800A1DFC;
    }
    goto skip_2;
    // 0x800A1D5C: lw          $t8, 0x128($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X128);
    skip_2:
    // 0x800A1D60: jal         0x800965D4
    // 0x800A1D64: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    func_800965D4(rdram, ctx);
        goto after_23;
    // 0x800A1D64: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    after_23:
    // 0x800A1D68: beq         $v0, $zero, L_800A1DF8
    if (ctx->r2 == 0) {
        // 0x800A1D6C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800A1DF8;
    }
    // 0x800A1D6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A1D70: jal         0x80106790
    // 0x800A1D74: nop

    func_80106790(rdram, ctx);
        goto after_24;
    // 0x800A1D74: nop

    after_24:
    // 0x800A1D78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A1D7C: jal         0x80089CD8
    // 0x800A1D80: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    _subaddiefade_entrypoint_9(rdram, ctx);
        goto after_25;
    // 0x800A1D80: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_25:
    // 0x800A1D84: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800A1D88: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
    // 0x800A1D8C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x800A1D90: lwc1        $f22, 0x0($v1)
    ctx->f22.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800A1D94: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800A1D98: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A1D9C: trunc.w.s   $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    ctx->f22.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x800A1DA0: mfc1        $t5, $f22
    ctx->r13 = (int32_t)ctx->f22.u32l;
    // 0x800A1DA4: beq         $v0, $a0, L_800A1DE0
    if (ctx->r2 == ctx->r4) {
        // 0x800A1DA8: multu       $t3, $t5
        result = U64(U32(ctx->r11)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
            goto L_800A1DE0;
    }
    // 0x800A1DA8: multu       $t3, $t5
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
L_800A1DAC:
    // 0x800A1DAC: mflo        $t6
    ctx->r14 = lo;
    // 0x800A1DB0: lwc1        $f22, 0x4($v1)
    ctx->f22.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800A1DB4: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800A1DB8: mtc1        $t7, $f20
    ctx->f20.u32l = ctx->r15;
    // 0x800A1DBC: trunc.w.s   $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    ctx->f22.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x800A1DC0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A1DC4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A1DC8: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x800A1DCC: mfc1        $t5, $f22
    ctx->r13 = (int32_t)ctx->f22.u32l;
    // 0x800A1DD0: swc1        $f20, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f20.u32l;
    // 0x800A1DD4: lw          $t3, -0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, -0X4);
    // 0x800A1DD8: bne         $v0, $a0, L_800A1DAC
    if (ctx->r2 != ctx->r4) {
        // 0x800A1DDC: multu       $t3, $t5
        result = U64(U32(ctx->r11)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
            goto L_800A1DAC;
    }
    // 0x800A1DDC: multu       $t3, $t5
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
L_800A1DE0:
    // 0x800A1DE0: mflo        $t6
    ctx->r14 = lo;
    // 0x800A1DE4: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800A1DE8: mtc1        $t7, $f20
    ctx->f20.u32l = ctx->r15;
    // 0x800A1DEC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A1DF0: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x800A1DF4: swc1        $f20, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f20.u32l;
L_800A1DF8:
    // 0x800A1DF8: lw          $t8, 0x128($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X128);
L_800A1DFC:
    // 0x800A1DFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A1E00: lw          $t9, 0x108($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X108);
    // 0x800A1E04: lbu         $t2, 0x0($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X0);
    // 0x800A1E08: bne         $t2, $at, L_800A1E18
    if (ctx->r10 != ctx->r1) {
        // 0x800A1E0C: nop
    
            goto L_800A1E18;
    }
    // 0x800A1E0C: nop

    // 0x800A1E10: b           L_800A1E34
    // 0x800A1E14: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
        goto L_800A1E34;
    // 0x800A1E14: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_800A1E18:
    // 0x800A1E18: jal         0x800F40EC
    // 0x800A1E1C: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    func_800F40EC(rdram, ctx);
        goto after_26;
    // 0x800A1E1C: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    after_26:
    // 0x800A1E20: bnel        $v0, $zero, L_800A1E34
    if (ctx->r2 != 0) {
        // 0x800A1E24: addiu       $v0, $zero, 0xFA
        ctx->r2 = ADD32(0, 0XFA);
            goto L_800A1E34;
    }
    goto skip_3;
    // 0x800A1E24: addiu       $v0, $zero, 0xFA
    ctx->r2 = ADD32(0, 0XFA);
    skip_3:
    // 0x800A1E28: b           L_800A1E34
    // 0x800A1E2C: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
        goto L_800A1E34;
    // 0x800A1E2C: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
    // 0x800A1E30: addiu       $v0, $zero, 0xFA
    ctx->r2 = ADD32(0, 0XFA);
L_800A1E34:
    // 0x800A1E34: lw          $t4, 0xF4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF4);
    // 0x800A1E38: sll         $t3, $t4, 5
    ctx->r11 = S32(ctx->r12 << 5);
    // 0x800A1E3C: bgezl       $t3, L_800A1E94
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800A1E40: mtc1        $v0, $f8
        ctx->f8.u32l = ctx->r2;
            goto L_800A1E94;
    }
    goto skip_4;
    // 0x800A1E40: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    skip_4:
    // 0x800A1E44: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800A1E48: lwc1        $f18, 0x0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800A1E4C: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800A1E50: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A1E54: lwc1        $f6, 0x8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800A1E58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A1E5C: add.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800A1E60: lwc1        $f4, 0x54AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X54AC);
    // 0x800A1E64: sub.s       $f10, $f24, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x800A1E68: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800A1E6C: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A1E70: nop

    // 0x800A1E74: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A1E78: add.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A1E7C: swc1        $f16, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f16.u32l;
    // 0x800A1E80: lwc1        $f2, 0x0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800A1E84: swc1        $f2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f2.u32l;
    // 0x800A1E88: b           L_800A1EE8
    // 0x800A1E8C: swc1        $f2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f2.u32l;
        goto L_800A1EE8;
    // 0x800A1E8C: swc1        $f2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f2.u32l;
    // 0x800A1E90: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
L_800A1E94:
    // 0x800A1E94: lwc1        $f10, 0x0($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800A1E98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A1E9C: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A1EA0: lwc1        $f12, 0x54B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X54B0);
    // 0x800A1EA4: lwc1        $f16, 0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800A1EA8: sub.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x800A1EAC: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800A1EB0: nop

    // 0x800A1EB4: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800A1EB8: nop

    // 0x800A1EBC: mul.s       $f8, $f16, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800A1EC0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A1EC4: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800A1EC8: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800A1ECC: swc1        $f6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f6.u32l;
    // 0x800A1ED0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800A1ED4: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800A1ED8: mul.s       $f16, $f6, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800A1EDC: swc1        $f18, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f18.u32l;
    // 0x800A1EE0: add.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A1EE4: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
L_800A1EE8:
    // 0x800A1EE8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800A1EEC:
    // 0x800A1EEC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800A1EF0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800A1EF4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800A1EF8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800A1EFC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800A1F00: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800A1F04: jr          $ra
    // 0x800A1F08: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x800A1F08: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void func_808013CC_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808013D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808013D8: jal         0x800839E8
    // 0x808013DC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x808013DC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808013E0: beq         $v0, $zero, L_808013F4
    if (ctx->r2 == 0) {
        // 0x808013E4: nop
    
            goto L_808013F4;
    }
    // 0x808013E4: nop

    // 0x808013E8: jal         0x800839B0
    // 0x808013EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsrest_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x808013EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808013F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_808013F4:
    // 0x808013F4: jal         0x80800300
    // 0x808013F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800300_bswasher(rdram, ctx);
        goto after_2;
    // 0x808013F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808013FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801400: jal         0x8009E5C8
    // 0x80801404: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80801404: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80801408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080140C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801410: jr          $ra
    // 0x80801414: nop

    return;
    // 0x80801414: nop

;}
RECOMP_FUNC void gcegg_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x808000F4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x808000F8: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x808000FC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2678, 0X202) << 16);
    // 0x80800100: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800104: jr          $ra
    // 0x80800108: lh          $v0, 0x202($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(2678, 0X202));
    return;
    // 0x80800108: lh          $v0, 0x202($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(2678, 0X202));
;}
RECOMP_FUNC void func_80800CDC_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CE0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800CE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CE8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80800CEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800CF0: jal         0x80101808
    // 0x80800CF4: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    func_80101808(rdram, ctx);
        goto after_0;
    // 0x80800CF4: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    after_0:
    // 0x80800CF8: beq         $v0, $zero, L_80800D20
    if (ctx->r2 == 0) {
        // 0x80800CFC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800D20;
    }
    // 0x80800CFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D00: jal         0x80100094
    // 0x80800D04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800D04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800D08: jal         0x8008A040
    // 0x80800D0C: addiu       $a0, $v0, 0x810
    ctx->r4 = ADD32(ctx->r2, 0X810);
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800D0C: addiu       $a0, $v0, 0x810
    ctx->r4 = ADD32(ctx->r2, 0X810);
    after_2:
    // 0x80800D10: beq         $v0, $zero, L_80800D20
    if (ctx->r2 == 0) {
        // 0x80800D14: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800D20;
    }
    // 0x80800D14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D18: jal         0x8010A764
    // 0x80800D1C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8010A764(rdram, ctx);
        goto after_3;
    // 0x80800D1C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
L_80800D20:
    // 0x80800D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D28: jr          $ra
    // 0x80800D2C: nop

    return;
    // 0x80800D2C: nop

;}
RECOMP_FUNC void func_80800870_chpowerhut(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800870: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800874: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800878: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080087C: jal         0x8001210C
    // 0x80800880: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x80800880: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80800884: bne         $v0, $zero, L_808008AC
    if (ctx->r2 != 0) {
        // 0x80800888: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808008AC;
    }
    // 0x80800888: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080088C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1076, 0X9C0) << 16);
    // 0x80800890: addiu       $t6, $t6, 0x9C0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1076, 0X9C0));
    // 0x80800894: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x80800898: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080089C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808008A0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808008A4: jal         0x800BBCB8
    // 0x808008A8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x808008A8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
L_808008AC:
    // 0x808008AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008B4: jr          $ra
    // 0x808008B8: nop

    return;
    // 0x808008B8: nop

;}
RECOMP_FUNC void gcmapDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080009C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A8: jal         0x800C87DC
    // 0x808000AC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800C87DC(rdram, ctx);
        goto after_0;
    // 0x808000AC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x808000B0: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x808000B4: beql        $t6, $zero, L_808000E4
    if (ctx->r14 == 0) {
        // 0x808000B8: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_808000E4;
    }
    goto skip_0;
    // 0x808000B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    skip_0:
    // 0x808000BC: jal         0x800A946C
    // 0x808000C0: nop

    func_800A946C(rdram, ctx);
        goto after_1;
    // 0x808000C0: nop

    after_1:
    // 0x808000C4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x808000C8: beql        $at, $zero, L_808000E4
    if (ctx->r1 == 0) {
        // 0x808000CC: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_808000E4;
    }
    goto skip_1;
    // 0x808000CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    skip_1:
    // 0x808000D0: jal         0x800B27BC
    // 0x808000D4: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    func_800B27BC(rdram, ctx);
        goto after_2;
    // 0x808000D4: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_2:
    // 0x808000D8: b           L_808000E4
    // 0x808000DC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_808000E4;
    // 0x808000DC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x808000E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_808000E4:
    // 0x808000E4: beq         $a3, $zero, L_8080011C
    if (ctx->r7 == 0) {
        // 0x808000E8: nop
    
            goto L_8080011C;
    }
    // 0x808000E8: nop

    // 0x808000EC: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x808000F0: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x808000F4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808000F8: jal         0x800879E0
    // 0x808000FC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    _dblight_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808000FC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80800100: jal         0x800B27A0
    // 0x80800104: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    func_800B27A0(rdram, ctx);
        goto after_4;
    // 0x80800104: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_4:
    // 0x80800108: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080010C: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x80800110: jal         0x800879E8
    // 0x80800114: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _dblight_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800114: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x80800118: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_8080011C:
    // 0x8080011C: beql        $a3, $zero, L_8080014C
    if (ctx->r7 == 0) {
        // 0x80800120: sw          $zero, 0x8($s0)
        MEM_W(0X8, ctx->r16) = 0;
            goto L_8080014C;
    }
    goto skip_2;
    // 0x80800120: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    skip_2:
    // 0x80800124: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80800128: jal         0x800B27A0
    // 0x8080012C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_800B27A0(rdram, ctx);
        goto after_6;
    // 0x8080012C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_6:
    // 0x80800130: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800134: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x80800138: jal         0x800890A0
    // 0x8080013C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _rtlight_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x8080013C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_7:
    // 0x80800140: b           L_8080014C
    // 0x80800144: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
        goto L_8080014C;
    // 0x80800144: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80800148: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
L_8080014C:
    // 0x8080014C: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x80800150: beql        $t7, $zero, L_80800180
    if (ctx->r15 == 0) {
        // 0x80800154: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80800180;
    }
    goto skip_3;
    // 0x80800154: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    skip_3:
    // 0x80800158: jal         0x800A946C
    // 0x8080015C: nop

    func_800A946C(rdram, ctx);
        goto after_8;
    // 0x8080015C: nop

    after_8:
    // 0x80800160: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80800164: beql        $at, $zero, L_80800180
    if (ctx->r1 == 0) {
        // 0x80800168: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80800180;
    }
    goto skip_4;
    // 0x80800168: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    skip_4:
    // 0x8080016C: jal         0x800B27BC
    // 0x80800170: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    func_800B27BC(rdram, ctx);
        goto after_9;
    // 0x80800170: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    after_9:
    // 0x80800174: b           L_80800180
    // 0x80800178: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_80800180;
    // 0x80800178: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8080017C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80800180:
    // 0x80800180: beq         $a3, $zero, L_808001B8
    if (ctx->r7 == 0) {
        // 0x80800184: nop
    
            goto L_808001B8;
    }
    // 0x80800184: nop

    // 0x80800188: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x8080018C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80800190: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800194: jal         0x800879E0
    // 0x80800198: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    _dblight_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x80800198: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_10:
    // 0x8080019C: jal         0x800B27A0
    // 0x808001A0: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    func_800B27A0(rdram, ctx);
        goto after_11;
    // 0x808001A0: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    after_11:
    // 0x808001A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808001A8: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x808001AC: jal         0x800879E8
    // 0x808001B0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _dblight_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x808001B0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_12:
    // 0x808001B4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_808001B8:
    // 0x808001B8: beql        $a3, $zero, L_808001E8
    if (ctx->r7 == 0) {
        // 0x808001BC: sw          $zero, 0x34($s0)
        MEM_W(0X34, ctx->r16) = 0;
            goto L_808001E8;
    }
    goto skip_5;
    // 0x808001BC: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    skip_5:
    // 0x808001C0: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x808001C4: jal         0x800B27A0
    // 0x808001C8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_800B27A0(rdram, ctx);
        goto after_13;
    // 0x808001C8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_13:
    // 0x808001CC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808001D0: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x808001D4: jal         0x800890A0
    // 0x808001D8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _rtlight_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x808001D8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_14:
    // 0x808001DC: b           L_808001E8
    // 0x808001E0: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
        goto L_808001E8;
    // 0x808001E0: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x808001E4: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
L_808001E8:
    // 0x808001E8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x808001EC: beql        $t8, $zero, L_80800234
    if (ctx->r24 == 0) {
        // 0x808001F0: sw          $zero, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = 0;
            goto L_80800234;
    }
    goto skip_6;
    // 0x808001F0: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    skip_6:
    // 0x808001F4: jal         0x800A946C
    // 0x808001F8: nop

    func_800A946C(rdram, ctx);
        goto after_15;
    // 0x808001F8: nop

    after_15:
    // 0x808001FC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80800200: beql        $at, $zero, L_80800234
    if (ctx->r1 == 0) {
        // 0x80800204: sw          $zero, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = 0;
            goto L_80800234;
    }
    goto skip_7;
    // 0x80800204: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    skip_7:
    // 0x80800208: jal         0x800B2868
    // 0x8080020C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    func_800B2868(rdram, ctx);
        goto after_16;
    // 0x8080020C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_16:
    // 0x80800210: beq         $v0, $zero, L_80800230
    if (ctx->r2 == 0) {
        // 0x80800214: sw          $v0, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r2;
            goto L_80800230;
    }
    // 0x80800214: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x80800218: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080021C: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x80800220: jal         0x800890B0
    // 0x80800224: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    _vpmodule_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x80800224: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_17:
    // 0x80800228: b           L_80800234
    // 0x8080022C: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
        goto L_80800234;
    // 0x8080022C: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_80800230:
    // 0x80800230: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
L_80800234:
    // 0x80800234: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x80800238: beql        $t9, $zero, L_80800280
    if (ctx->r25 == 0) {
        // 0x8080023C: sw          $zero, 0x48($s0)
        MEM_W(0X48, ctx->r16) = 0;
            goto L_80800280;
    }
    goto skip_8;
    // 0x8080023C: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    skip_8:
    // 0x80800240: jal         0x800A946C
    // 0x80800244: nop

    func_800A946C(rdram, ctx);
        goto after_18;
    // 0x80800244: nop

    after_18:
    // 0x80800248: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8080024C: beql        $at, $zero, L_80800280
    if (ctx->r1 == 0) {
        // 0x80800250: sw          $zero, 0x48($s0)
        MEM_W(0X48, ctx->r16) = 0;
            goto L_80800280;
    }
    goto skip_9;
    // 0x80800250: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    skip_9:
    // 0x80800254: jal         0x800B2868
    // 0x80800258: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    func_800B2868(rdram, ctx);
        goto after_19;
    // 0x80800258: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    after_19:
    // 0x8080025C: beq         $v0, $zero, L_8080027C
    if (ctx->r2 == 0) {
        // 0x80800260: sw          $v0, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r2;
            goto L_8080027C;
    }
    // 0x80800260: sw          $v0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r2;
    // 0x80800264: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800268: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x8080026C: jal         0x800890B0
    // 0x80800270: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    _vpmodule_entrypoint_0(rdram, ctx);
        goto after_20;
    // 0x80800270: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_20:
    // 0x80800274: b           L_80800280
    // 0x80800278: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
        goto L_80800280;
    // 0x80800278: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
L_8080027C:
    // 0x8080027C: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
L_80800280:
    // 0x80800280: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x80800284: beql        $t0, $zero, L_808002B8
    if (ctx->r8 == 0) {
        // 0x80800288: lw          $t3, 0x38($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X38);
            goto L_808002B8;
    }
    goto skip_10;
    // 0x80800288: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    skip_10:
    // 0x8080028C: lw          $t1, 0x18($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18);
    // 0x80800290: bnel        $t1, $zero, L_808002B8
    if (ctx->r9 != 0) {
        // 0x80800294: lw          $t3, 0x38($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X38);
            goto L_808002B8;
    }
    goto skip_11;
    // 0x80800294: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    skip_11:
    // 0x80800298: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x8080029C: bnel        $t2, $zero, L_808002B8
    if (ctx->r10 != 0) {
        // 0x808002A0: lw          $t3, 0x38($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X38);
            goto L_808002B8;
    }
    goto skip_12;
    // 0x808002A0: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    skip_12:
    // 0x808002A4: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x808002A8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808002AC: jal         0x800B2464
    // 0x808002B0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_800B2464(rdram, ctx);
        goto after_21;
    // 0x808002B0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_21:
    // 0x808002B4: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
L_808002B8:
    // 0x808002B8: beql        $t3, $zero, L_808002EC
    if (ctx->r11 == 0) {
        // 0x808002BC: lw          $t6, 0xC($s0)
        ctx->r14 = MEM_W(ctx->r16, 0XC);
            goto L_808002EC;
    }
    goto skip_13;
    // 0x808002BC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    skip_13:
    // 0x808002C0: lw          $t4, 0x44($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X44);
    // 0x808002C4: bnel        $t4, $zero, L_808002EC
    if (ctx->r12 != 0) {
        // 0x808002C8: lw          $t6, 0xC($s0)
        ctx->r14 = MEM_W(ctx->r16, 0XC);
            goto L_808002EC;
    }
    goto skip_14;
    // 0x808002C8: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    skip_14:
    // 0x808002CC: lw          $t5, 0x34($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X34);
    // 0x808002D0: bnel        $t5, $zero, L_808002EC
    if (ctx->r13 != 0) {
        // 0x808002D4: lw          $t6, 0xC($s0)
        ctx->r14 = MEM_W(ctx->r16, 0XC);
            goto L_808002EC;
    }
    goto skip_15;
    // 0x808002D4: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    skip_15:
    // 0x808002D8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x808002DC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808002E0: jal         0x800B2464
    // 0x808002E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_800B2464(rdram, ctx);
        goto after_22;
    // 0x808002E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_22:
    // 0x808002E8: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_808002EC:
    // 0x808002EC: beql        $t6, $zero, L_8080031C
    if (ctx->r14 == 0) {
        // 0x808002F0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8080031C;
    }
    goto skip_16;
    // 0x808002F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_16:
    // 0x808002F4: jal         0x800A946C
    // 0x808002F8: nop

    func_800A946C(rdram, ctx);
        goto after_23;
    // 0x808002F8: nop

    after_23:
    // 0x808002FC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80800300: beql        $at, $zero, L_8080031C
    if (ctx->r1 == 0) {
        // 0x80800304: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8080031C;
    }
    goto skip_17;
    // 0x80800304: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_17:
    // 0x80800308: jal         0x800B274C
    // 0x8080030C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    func_800B274C(rdram, ctx);
        goto after_24;
    // 0x8080030C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_24:
    // 0x80800310: b           L_8080031C
    // 0x80800314: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8080031C;
    // 0x80800314: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800318: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8080031C:
    // 0x8080031C: beq         $v1, $zero, L_80800334
    if (ctx->r3 == 0) {
        // 0x80800320: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800334;
    }
    // 0x80800320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800324: jal         0x800888A0
    // 0x80800328: lhu         $a0, 0x5A($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X5A);
    _glidmake_entrypoint_5(rdram, ctx);
        goto after_25;
    // 0x80800328: lhu         $a0, 0x5A($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X5A);
    after_25:
    // 0x8080032C: b           L_80800338
    // 0x80800330: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_80800338;
    // 0x80800330: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_80800334:
    // 0x80800334: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_80800338:
    // 0x80800338: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8080033C: beql        $a0, $zero, L_80800350
    if (ctx->r4 == 0) {
        // 0x80800340: lw          $t7, 0x38($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X38);
            goto L_80800350;
    }
    goto skip_18;
    // 0x80800340: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    skip_18:
    // 0x80800344: jal         0x80088F20
    // 0x80800348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _idworldmake_entrypoint_0(rdram, ctx);
        goto after_26;
    // 0x80800348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x8080034C: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
L_80800350:
    // 0x80800350: beql        $t7, $zero, L_80800380
    if (ctx->r15 == 0) {
        // 0x80800354: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800380;
    }
    goto skip_19;
    // 0x80800354: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_19:
    // 0x80800358: jal         0x800A946C
    // 0x8080035C: nop

    func_800A946C(rdram, ctx);
        goto after_27;
    // 0x8080035C: nop

    after_27:
    // 0x80800360: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80800364: beql        $at, $zero, L_80800380
    if (ctx->r1 == 0) {
        // 0x80800368: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800380;
    }
    goto skip_20;
    // 0x80800368: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_20:
    // 0x8080036C: jal         0x800B274C
    // 0x80800370: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    func_800B274C(rdram, ctx);
        goto after_28;
    // 0x80800370: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    after_28:
    // 0x80800374: b           L_80800380
    // 0x80800378: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80800380;
    // 0x80800378: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080037C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800380:
    // 0x80800380: beq         $v1, $zero, L_80800398
    if (ctx->r3 == 0) {
        // 0x80800384: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800398;
    }
    // 0x80800384: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800388: jal         0x800888A0
    // 0x8080038C: lhu         $a0, 0x5C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X5C);
    _glidmake_entrypoint_5(rdram, ctx);
        goto after_29;
    // 0x8080038C: lhu         $a0, 0x5C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X5C);
    after_29:
    // 0x80800390: b           L_8080039C
    // 0x80800394: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
        goto L_8080039C;
    // 0x80800394: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
L_80800398:
    // 0x80800398: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
L_8080039C:
    // 0x8080039C: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x808003A0: beql        $a0, $zero, L_808003B4
    if (ctx->r4 == 0) {
        // 0x808003A4: lw          $a0, 0x10($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X10);
            goto L_808003B4;
    }
    goto skip_21;
    // 0x808003A4: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    skip_21:
    // 0x808003A8: jal         0x80088F20
    // 0x808003AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _idworldmake_entrypoint_0(rdram, ctx);
        goto after_30;
    // 0x808003AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x808003B0: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
L_808003B4:
    // 0x808003B4: beql        $a0, $zero, L_808003DC
    if (ctx->r4 == 0) {
        // 0x808003B8: sw          $zero, 0x14($s0)
        MEM_W(0X14, ctx->r16) = 0;
            goto L_808003DC;
    }
    goto skip_22;
    // 0x808003B8: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    skip_22:
    // 0x808003BC: lbu         $t8, 0x64($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X64);
    // 0x808003C0: beql        $t8, $zero, L_808003DC
    if (ctx->r24 == 0) {
        // 0x808003C4: sw          $zero, 0x14($s0)
        MEM_W(0X14, ctx->r16) = 0;
            goto L_808003DC;
    }
    goto skip_23;
    // 0x808003C4: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    skip_23:
    // 0x808003C8: jal         0x800B2400
    // 0x808003CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800B2400(rdram, ctx);
        goto after_31;
    // 0x808003CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x808003D0: b           L_808003DC
    // 0x808003D4: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
        goto L_808003DC;
    // 0x808003D4: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x808003D8: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
L_808003DC:
    // 0x808003DC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x808003E0: beql        $a0, $zero, L_80800408
    if (ctx->r4 == 0) {
        // 0x808003E4: sw          $zero, 0x40($s0)
        MEM_W(0X40, ctx->r16) = 0;
            goto L_80800408;
    }
    goto skip_24;
    // 0x808003E4: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    skip_24:
    // 0x808003E8: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x808003EC: beql        $t9, $zero, L_80800408
    if (ctx->r25 == 0) {
        // 0x808003F0: sw          $zero, 0x40($s0)
        MEM_W(0X40, ctx->r16) = 0;
            goto L_80800408;
    }
    goto skip_25;
    // 0x808003F0: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    skip_25:
    // 0x808003F4: jal         0x800B2400
    // 0x808003F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800B2400(rdram, ctx);
        goto after_32;
    // 0x808003F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x808003FC: b           L_80800408
    // 0x80800400: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
        goto L_80800408;
    // 0x80800400: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x80800404: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
L_80800408:
    // 0x80800408: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8080040C: beql        $a0, $zero, L_8080042C
    if (ctx->r4 == 0) {
        // 0x80800410: lw          $a0, 0x30($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X30);
            goto L_8080042C;
    }
    goto skip_26;
    // 0x80800410: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    skip_26:
    // 0x80800414: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x80800418: beql        $a1, $zero, L_8080042C
    if (ctx->r5 == 0) {
        // 0x8080041C: lw          $a0, 0x30($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X30);
            goto L_8080042C;
    }
    goto skip_27;
    // 0x8080041C: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    skip_27:
    // 0x80800420: jal         0x80088690
    // 0x80800424: nop

    _glid_entrypoint_6(rdram, ctx);
        goto after_33;
    // 0x80800424: nop

    after_33:
    // 0x80800428: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
L_8080042C:
    // 0x8080042C: beql        $a0, $zero, L_8080044C
    if (ctx->r4 == 0) {
        // 0x80800430: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080044C;
    }
    goto skip_28;
    // 0x80800430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_28:
    // 0x80800434: lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X40);
    // 0x80800438: beql        $a1, $zero, L_8080044C
    if (ctx->r5 == 0) {
        // 0x8080043C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080044C;
    }
    goto skip_29;
    // 0x8080043C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_29:
    // 0x80800440: jal         0x80088690
    // 0x80800444: nop

    _glid_entrypoint_6(rdram, ctx);
        goto after_34;
    // 0x80800444: nop

    after_34:
    // 0x80800448: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080044C:
    // 0x8080044C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800450: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800454: jr          $ra
    // 0x80800458: nop

    return;
    // 0x80800458: nop

;}
RECOMP_FUNC void bsmumcast_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808001C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001D0: jal         0x80083808
    // 0x808001D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bsmum_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808001D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808001D8: jal         0x8008E944
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_1;
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: jal         0x80099A7C
    // 0x808001E8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80099A7C(rdram, ctx);
        goto after_2;
    // 0x808001E8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: jal         0x800A00CC
    // 0x808001F4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800A00CC(rdram, ctx);
        goto after_3;
    // 0x808001F4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x808001F8: jal         0x8009EA20
    // 0x808001FC: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    func_8009EA20(rdram, ctx);
        goto after_4;
    // 0x808001FC: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    after_4:
    // 0x80800200: beq         $v0, $zero, L_8080021C
    if (ctx->r2 == 0) {
        // 0x80800204: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080021C;
    }
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: jal         0x80800000
    // 0x80800210: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800000_bsmumcast(rdram, ctx);
        goto after_5;
    // 0x80800210: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x80800214: b           L_80800228
    // 0x80800218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800228;
    // 0x80800218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080021C:
    // 0x8080021C: jal         0x80800000
    // 0x80800220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800000_bsmumcast(rdram, ctx);
        goto after_6;
    // 0x80800220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800228:
    // 0x80800228: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080022C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800230: jr          $ra
    // 0x80800234: nop

    return;
    // 0x80800234: nop

;}
RECOMP_FUNC void _bamovegoto_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084DC8: syscall     137
    recomp_syscall_handler(rdram, ctx, 0x80084DC8);
    return;
    // 0x80084DCC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _baeggsetup_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A80: syscall     126
    recomp_syscall_handler(rdram, ctx, 0x80084A80);
    return;
    // 0x80084A84: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800000_chmumbohealspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x800DA298
    // 0x80800010: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    after_0:
    // 0x80800014: beq         $v0, $zero, L_80800040
    if (ctx->r2 == 0) {
        // 0x80800018: nop
    
            goto L_80800040;
    }
    // 0x80800018: nop

    // 0x8080001C: jal         0x800EA05C
    // 0x80800020: nop

    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x80800020: nop

    after_1:
    // 0x80800024: addiu       $at, $zero, 0x155
    ctx->r1 = ADD32(0, 0X155);
    // 0x80800028: bne         $v0, $at, L_80800040
    if (ctx->r2 != ctx->r1) {
        // 0x8080002C: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80800040;
    }
    // 0x8080002C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800030: jal         0x800FFA88
    // 0x80800034: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_2;
    // 0x80800034: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x80800038: b           L_8080005C
    // 0x8080003C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_8080005C;
    // 0x8080003C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800040:
    // 0x80800040: jal         0x800DA298
    // 0x80800044: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800044: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    after_3:
    // 0x80800048: bne         $v0, $zero, L_80800058
    if (ctx->r2 != 0) {
        // 0x8080004C: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80800058;
    }
    // 0x8080004C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800050: jal         0x800FFA88
    // 0x80800054: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_4;
    // 0x80800054: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_4:
L_80800058:
    // 0x80800058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8080005C:
    // 0x8080005C: jal         0x80103110
    // 0x80800060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_5;
    // 0x80800060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080006C: jr          $ra
    // 0x80800070: nop

    return;
    // 0x80800070: nop

;}
RECOMP_FUNC void func_80800224_cadbfunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800224: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080022C: jal         0x800A587C
    // 0x80800230: nop

    func_800A587C(rdram, ctx);
        goto after_0;
    // 0x80800230: nop

    after_0:
    // 0x80800234: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800238: beq         $v0, $at, L_80800250
    if (ctx->r2 == ctx->r1) {
        // 0x8080023C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800250;
    }
    // 0x8080023C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800240: beq         $v0, $at, L_80800260
    if (ctx->r2 == ctx->r1) {
        // 0x80800244: nop
    
            goto L_80800260;
    }
    // 0x80800244: nop

    // 0x80800248: b           L_80800270
    // 0x8080024C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800270;
    // 0x8080024C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800250:
    // 0x80800250: jal         0x800A586C
    // 0x80800254: nop

    func_800A586C(rdram, ctx);
        goto after_1;
    // 0x80800254: nop

    after_1:
    // 0x80800258: b           L_80800270
    // 0x8080025C: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
        goto L_80800270;
    // 0x8080025C: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
L_80800260:
    // 0x80800260: jal         0x800A586C
    // 0x80800264: nop

    func_800A586C(rdram, ctx);
        goto after_2;
    // 0x80800264: nop

    after_2:
    // 0x80800268: b           L_80800270
    // 0x8080026C: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
        goto L_80800270;
    // 0x8080026C: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
L_80800270:
    // 0x80800270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800278: jr          $ra
    // 0x8080027C: nop

    return;
    // 0x8080027C: nop

;}
RECOMP_FUNC void gccubesearch_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800380: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800384: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800388: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080038C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800390: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    // 0x80800394: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800398: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8080039C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808003A0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x808003A4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808003A8: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x808003AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808003B0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808003B4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x808003B8: jal         0x800EE904
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EE904(rdram, ctx);
        goto after_0;
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808003C0: jal         0x800BDD24
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BDD24(rdram, ctx);
        goto after_1;
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808003C8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x808003CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808003D0: beq         $t6, $zero, L_80800404
    if (ctx->r14 == 0) {
        // 0x808003D4: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_80800404;
    }
    // 0x808003D4: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x808003D8: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
L_808003DC:
    // 0x808003DC: addu        $a2, $t7, $s4
    ctx->r6 = ADD32(ctx->r15, ctx->r20);
    // 0x808003E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003E4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808003E8: jal         0x80088C40
    // 0x808003EC: subu        $a3, $s5, $s2
    ctx->r7 = SUB32(ctx->r21, ctx->r18);
    _gspropmarker_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808003EC: subu        $a3, $s5, $s2
    ctx->r7 = SUB32(ctx->r21, ctx->r18);
    after_2:
    // 0x808003F0: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x808003F4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808003F8: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x808003FC: bnel        $s1, $zero, L_808003DC
    if (ctx->r17 != 0) {
        // 0x80800400: sll         $t7, $s2, 2
        ctx->r15 = S32(ctx->r18 << 2);
            goto L_808003DC;
    }
    goto skip_0;
    // 0x80800400: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    skip_0:
L_80800404:
    // 0x80800404: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800408: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8080040C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800410: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800414: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800418: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8080041C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800420: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80800424: jr          $ra
    // 0x80800428: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800428: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _badata_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800846C0: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x800846C0);
    return;
    // 0x800846C4: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_80801900_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801900: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80801904: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801908: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080190C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80801910: jal         0x80100094
    // 0x80801914: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801914: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801918: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8080191C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80801920: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80801924: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x80801928: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8080192C: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80801930: bnel        $t8, $at, L_8080194C
    if (ctx->r24 != ctx->r1) {
        // 0x80801934: lw          $t9, 0x120($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X120);
            goto L_8080194C;
    }
    goto skip_0;
    // 0x80801934: lw          $t9, 0x120($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X120);
    skip_0:
    // 0x80801938: jal         0x80801A44
    // 0x8080193C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80801A44_chdinoboss(rdram, ctx);
        goto after_1;
    // 0x8080193C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x80801940: b           L_80801978
    // 0x80801944: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
        goto L_80801978;
    // 0x80801944: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801948: lw          $t9, 0x120($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X120);
L_8080194C:
    // 0x8080194C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80801950: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80801954: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x80801958: lh          $t2, 0xF4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XF4);
    // 0x8080195C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80801960: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80801964: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80801968: addu        $a1, $v1, $t3
    ctx->r5 = ADD32(ctx->r3, ctx->r11);
    // 0x8080196C: jal         0x800EE7F8
    // 0x80801970: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80801970: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x80801974: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
L_80801978:
    // 0x80801978: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080197C: jal         0x8008A0D8
    // 0x80801980: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    _subaddieskeleton_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80801980: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_3:
    // 0x80801984: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80801988: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8080198C: jal         0x800F18FC
    // 0x80801990: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800F18FC(rdram, ctx);
        goto after_4;
    // 0x80801990: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x80801994: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801998: addiu       $a0, $zero, 0x398
    ctx->r4 = ADD32(0, 0X398);
    // 0x8080199C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808019A0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808019A4: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // 0x808019A8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808019AC: jal         0x80108528
    // 0x808019B0: nop

    func_80108528(rdram, ctx);
        goto after_5;
    // 0x808019B0: nop

    after_5:
    // 0x808019B4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808019B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808019BC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808019C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808019C4: jal         0x800DC178
    // 0x808019C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x808019C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_6:
    // 0x808019CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808019D0: jal         0x80102FDC
    // 0x808019D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_7;
    // 0x808019D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808019D8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808019DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808019E0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808019E4: jal         0x800EFB24
    // 0x808019E8: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800EFB24(rdram, ctx);
        goto after_8;
    // 0x808019E8: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_8:
    // 0x808019EC: lui         $a1, 0x455A
    ctx->r5 = S32(0X455A << 16);
    // 0x808019F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808019F4: jal         0x800EF368
    // 0x808019F8: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    func_800EF368(rdram, ctx);
        goto after_9;
    // 0x808019F8: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    after_9:
    // 0x808019FC: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80801A00: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80801A04: lhu         $t7, 0x72($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X72);
    // 0x80801A08: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80801A0C: bnel        $t8, $at, L_80801A28
    if (ctx->r24 != ctx->r1) {
        // 0x80801A10: lbu         $t1, 0x65($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X65);
            goto L_80801A28;
    }
    goto skip_1;
    // 0x80801A10: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    skip_1:
    // 0x80801A14: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80801A18: andi        $t9, $t6, 0xFFEF
    ctx->r25 = ctx->r14 & 0XFFEF;
    // 0x80801A1C: b           L_80801A30
    // 0x80801A20: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
        goto L_80801A30;
    // 0x80801A20: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    // 0x80801A24: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
L_80801A28:
    // 0x80801A28: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80801A2C: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_80801A30:
    // 0x80801A30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801A38: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80801A3C: jr          $ra
    // 0x80801A40: nop

    return;
    // 0x80801A40: nop

;}
RECOMP_FUNC void func_80800188_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080018C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800190: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800194: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800198: jal         0x8009E74C
    // 0x8080019C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x8080019C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x808001A0: bnel        $v0, $zero, L_80800238
    if (ctx->r2 != 0) {
        // 0x808001A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800238;
    }
    goto skip_0;
    // 0x808001A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808001A8: jal         0x80084BE8
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001B0: jal         0x80085168
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bastatemem_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001B8: jal         0x8009BC6C
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_3;
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001C0: jal         0x8009BC90
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_4;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: jal         0x800A0CF4
    // 0x808001D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_5;
    // 0x808001D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D8: jal         0x80093360
    // 0x808001DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80093360(rdram, ctx);
        goto after_6;
    // 0x808001DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x808001E0: jal         0x800A042C
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A042C(rdram, ctx);
        goto after_7;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001EC: jal         0x8009C908
    // 0x808001F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    yaw_setUpdateType(rdram, ctx);
        goto after_8;
    // 0x808001F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808001F4: jal         0x800A4E30
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4E30(rdram, ctx);
        goto after_9;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808001FC: jal         0x80095A40
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_10;
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: jal         0x800961AC
    // 0x8080020C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_11;
    // 0x8080020C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800214: jal         0x800845A8
    // 0x80800218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _baboost_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x80800218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800220: jal         0x80095774
    // 0x80800224: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    baflag_clear(rdram, ctx);
        goto after_13;
    // 0x80800224: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    after_13:
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080022C: jal         0x80095774
    // 0x80800230: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    baflag_clear(rdram, ctx);
        goto after_14;
    // 0x80800230: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_14:
    // 0x80800234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800238:
    // 0x80800238: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080023C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800240: jr          $ra
    // 0x80800244: nop

    return;
    // 0x80800244: nop

;}
RECOMP_FUNC void bsbabykaz_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800270: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800274: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800278: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080027C: jal         0x8009E6EC
    // 0x80800280: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800280: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800284: slti        $at, $v0, 0x88
    ctx->r1 = SIGNED(ctx->r2) < 0X88 ? 1 : 0;
    // 0x80800288: bne         $at, $zero, L_808002B0
    if (ctx->r1 != 0) {
        // 0x8080028C: addiu       $t6, $v0, -0x1F
        ctx->r14 = ADD32(ctx->r2, -0X1F);
            goto L_808002B0;
    }
    // 0x8080028C: addiu       $t6, $v0, -0x1F
    ctx->r14 = ADD32(ctx->r2, -0X1F);
    // 0x80800290: addiu       $at, $zero, 0x8E
    ctx->r1 = ADD32(0, 0X8E);
    // 0x80800294: beq         $v0, $at, L_80800384
    if (ctx->r2 == ctx->r1) {
        // 0x80800298: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800384;
    }
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080029C: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x808002A0: beql        $v0, $at, L_8080030C
    if (ctx->r2 == ctx->r1) {
        // 0x808002A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080030C;
    }
    goto skip_0;
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808002A8: b           L_808003B4
    // 0x808002AC: nop

        goto L_808003B4;
    // 0x808002AC: nop

L_808002B0:
    // 0x808002B0: slti        $at, $v0, 0x87
    ctx->r1 = SIGNED(ctx->r2) < 0X87 ? 1 : 0;
    // 0x808002B4: bne         $at, $zero, L_808002CC
    if (ctx->r1 != 0) {
        // 0x808002B8: addiu       $at, $zero, 0x87
        ctx->r1 = ADD32(0, 0X87);
            goto L_808002CC;
    }
    // 0x808002B8: addiu       $at, $zero, 0x87
    ctx->r1 = ADD32(0, 0X87);
    // 0x808002BC: beq         $v0, $at, L_8080033C
    if (ctx->r2 == ctx->r1) {
        // 0x808002C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080033C;
    }
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C4: b           L_808003B4
    // 0x808002C8: nop

        goto L_808003B4;
    // 0x808002C8: nop

L_808002CC:
    // 0x808002CC: slti        $at, $v0, 0x67
    ctx->r1 = SIGNED(ctx->r2) < 0X67 ? 1 : 0;
    // 0x808002D0: bne         $at, $zero, L_808002E8
    if (ctx->r1 != 0) {
        // 0x808002D4: addiu       $at, $zero, 0x86
        ctx->r1 = ADD32(0, 0X86);
            goto L_808002E8;
    }
    // 0x808002D4: addiu       $at, $zero, 0x86
    ctx->r1 = ADD32(0, 0X86);
    // 0x808002D8: beq         $v0, $at, L_80800368
    if (ctx->r2 == ctx->r1) {
        // 0x808002DC: nop
    
            goto L_80800368;
    }
    // 0x808002DC: nop

    // 0x808002E0: b           L_808003B4
    // 0x808002E4: nop

        goto L_808003B4;
    // 0x808002E4: nop

L_808002E8:
    // 0x808002E8: sltiu       $at, $t6, 0x48
    ctx->r1 = ctx->r14 < 0X48 ? 1 : 0;
    // 0x808002EC: beq         $at, $zero, L_808003B4
    if (ctx->r1 == 0) {
        // 0x808002F0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808003B4;
    }
    // 0x808002F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808002F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(68, 0X1600) << 16);
    // 0x808002F8: addu        $at, $at, $t6
    gpr jr_addend_80800300 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808002FC: lw          $t6, 0x1600($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(68, 0X1600));
    // 0x80800300: jr          $t6
    // 0x80800304: nop

    switch (jr_addend_80800300 >> 2) {
        case 0: goto L_80800308; break;
        case 1: goto L_80800308; break;
        case 2: goto L_80800308; break;
        case 3: goto L_808003B4; break;
        case 4: goto L_80800308; break;
        case 5: goto L_80800308; break;
        case 6: goto L_808003B4; break;
        case 7: goto L_808003B4; break;
        case 8: goto L_808003B4; break;
        case 9: goto L_808003B4; break;
        case 10: goto L_808003B4; break;
        case 11: goto L_808003B4; break;
        case 12: goto L_808003B4; break;
        case 13: goto L_808003B4; break;
        case 14: goto L_80800308; break;
        case 15: goto L_80800308; break;
        case 16: goto L_808003B4; break;
        case 17: goto L_808003B4; break;
        case 18: goto L_808003B4; break;
        case 19: goto L_808003B4; break;
        case 20: goto L_808003B4; break;
        case 21: goto L_808003B4; break;
        case 22: goto L_808003B4; break;
        case 23: goto L_808003B4; break;
        case 24: goto L_808003B4; break;
        case 25: goto L_808003B4; break;
        case 26: goto L_808003B4; break;
        case 27: goto L_808003B4; break;
        case 28: goto L_808003B4; break;
        case 29: goto L_808003B4; break;
        case 30: goto L_808003B4; break;
        case 31: goto L_808003B4; break;
        case 32: goto L_808003B4; break;
        case 33: goto L_808003B4; break;
        case 34: goto L_808003B4; break;
        case 35: goto L_808003B4; break;
        case 36: goto L_808003B4; break;
        case 37: goto L_808003B4; break;
        case 38: goto L_80800308; break;
        case 39: goto L_808003B4; break;
        case 40: goto L_808003B4; break;
        case 41: goto L_808003B4; break;
        case 42: goto L_808003B4; break;
        case 43: goto L_808003B4; break;
        case 44: goto L_808003B4; break;
        case 45: goto L_808003B4; break;
        case 46: goto L_808003B4; break;
        case 47: goto L_80800308; break;
        case 48: goto L_808003B4; break;
        case 49: goto L_808003B4; break;
        case 50: goto L_80800308; break;
        case 51: goto L_80800308; break;
        case 52: goto L_808003B4; break;
        case 53: goto L_808003B4; break;
        case 54: goto L_808003B4; break;
        case 55: goto L_808003B4; break;
        case 56: goto L_808003B4; break;
        case 57: goto L_808003B4; break;
        case 58: goto L_80800308; break;
        case 59: goto L_80800308; break;
        case 60: goto L_80800308; break;
        case 61: goto L_80800308; break;
        case 62: goto L_808003B4; break;
        case 63: goto L_808003B4; break;
        case 64: goto L_808003B4; break;
        case 65: goto L_808003B4; break;
        case 66: goto L_808003B4; break;
        case 67: goto L_808003B4; break;
        case 68: goto L_808003B4; break;
        case 69: goto L_808003B4; break;
        case 70: goto L_808003B4; break;
        case 71: goto L_80800328; break;
        default: switch_error(__func__, 0x80800300, 0x80801600);
    }
    // 0x80800304: nop

L_80800308:
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080030C:
    // 0x8080030C: jal         0x8009E5C8
    // 0x80800310: addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x80800310: addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    after_1:
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: jal         0x8009E830
    // 0x8080031C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_2;
    // 0x8080031C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800320: b           L_808003C0
    // 0x80800324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003C0;
    // 0x80800324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800328:
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080032C: jal         0x8009E830
    // 0x80800330: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E830(rdram, ctx);
        goto after_3;
    // 0x80800330: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800334: b           L_808003C0
    // 0x80800338: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003C0;
    // 0x80800338: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080033C:
    // 0x8080033C: jal         0x8009E5C8
    // 0x80800340: addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80800340: addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    after_4:
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800348: jal         0x8009E830
    // 0x8080034C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_5;
    // 0x8080034C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800354: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800358: jal         0x80085338
    // 0x8080035C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _batimer_set(rdram, ctx);
        goto after_6;
    // 0x8080035C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_6:
    // 0x80800360: b           L_808003C0
    // 0x80800364: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003C0;
    // 0x80800364: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800368:
    // 0x80800368: jal         0x80800214
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800214_bsbabykaz(rdram, ctx);
        goto after_7;
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800374: jal         0x8009E830
    // 0x80800378: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_8;
    // 0x80800378: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x8080037C: b           L_808003C0
    // 0x80800380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003C0;
    // 0x80800380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800384:
    // 0x80800384: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x80800388: jal         0x8009E5C8
    // 0x8080038C: addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    bs_setState(rdram, ctx);
        goto after_9;
    // 0x8080038C: addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    after_9:
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800394: jal         0x8009E830
    // 0x80800398: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_10;
    // 0x80800398: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003A4: jal         0x80085338
    // 0x808003A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _batimer_set(rdram, ctx);
        goto after_11;
    // 0x808003A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_11:
    // 0x808003AC: b           L_808003C0
    // 0x808003B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003C0;
    // 0x808003B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003B4:
    // 0x808003B4: jal         0x80099B94
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_12;
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808003BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003C0:
    // 0x808003C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003C8: jr          $ra
    // 0x808003CC: nop

    return;
    // 0x808003CC: nop

;}
RECOMP_FUNC void func_8080056C_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080056C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800570: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800574: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1036, 0X1430) << 16);
    // 0x80800578: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1036, 0X143C) << 16);
    // 0x8080057C: addiu       $a3, $a3, 0x143C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1036, 0X143C));
    // 0x80800580: addiu       $a2, $a2, 0x1430
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1036, 0X1430));
    // 0x80800584: jal         0x80089D28
    // 0x80800588: addiu       $a1, $a0, 0x18
    ctx->r5 = ADD32(ctx->r4, 0X18);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800588: addiu       $a1, $a0, 0x18
    ctx->r5 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x8080058C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800590: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800594: jr          $ra
    // 0x80800598: nop

    return;
    // 0x80800598: nop

;}
RECOMP_FUNC void _bskazfly_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800833B0: syscall     57
    recomp_syscall_handler(rdram, ctx, 0x800833B0);
    return;
    // 0x800833B4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_800C4E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4E58: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800C4E5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C4E60: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800C4E64: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800C4E68: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800C4E6C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800C4E70: jal         0x800A8984
    // 0x800C4E74: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    func_800A8984(rdram, ctx);
        goto after_0;
    // 0x800C4E74: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C4E78: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x800C4E7C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C4E80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C4E84: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800C4E88: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800C4E8C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x800C4E90: jal         0x800A8A04
    // 0x800C4E94: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    func_800A8A04(rdram, ctx);
        goto after_1;
    // 0x800C4E94: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x800C4E98: jal         0x800CA79C
    // 0x800C4E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800CA79C(rdram, ctx);
        goto after_2;
    // 0x800C4E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800C4EA0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800C4EA4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800C4EA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C4EAC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800C4EB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C4EB4: lwc1        $f14, 0x5898($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X5898);
    // 0x800C4EB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C4EBC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800C4EC0: nop

    // 0x800C4EC4: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C4EC8: jal         0x800F214C
    // 0x800C4ECC: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    func_800F214C(rdram, ctx);
        goto after_3;
    // 0x800C4ECC: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x800C4ED0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C4ED4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4ED8: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C4EDC: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x800C4EE0: nop

    // 0x800C4EE4: bc1fl       L_800C4F00
    if (!c1cs) {
        // 0x800C4EE8: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_800C4F00;
    }
    goto skip_0;
    // 0x800C4EE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_0:
    // 0x800C4EEC: jal         0x800EFD24
    // 0x800C4EF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EFD24(rdram, ctx);
        goto after_4;
    // 0x800C4EF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800C4EF4: b           L_800C4FF8
    // 0x800C4EF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C4FF8;
    // 0x800C4EF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C4EFC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_800C4F00:
    // 0x800C4F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C4F04: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C4F08: jal         0x800CA6FC
    // 0x800C4F0C: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    func_800CA6FC(rdram, ctx);
        goto after_5;
    // 0x800C4F0C: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x800C4F10: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800C4F14: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800C4F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C4F1C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800C4F20: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800C4F24: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C4F28: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800C4F2C: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800C4F30: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800C4F34: jal         0x800CA7B4
    // 0x800C4F38: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    func_800CA7B4(rdram, ctx);
        goto after_6;
    // 0x800C4F38: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x800C4F3C: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x800C4F40: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x800C4F44: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800C4F48: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800C4F4C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800C4F50: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C4F54: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800C4F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C4F5C: swc1        $f10, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f10.u32l;
    // 0x800C4F60: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800C4F64: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800C4F68: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800C4F6C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800C4F70: nop

    // 0x800C4F74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C4F78: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800C4F7C: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800C4F80: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800C4F84: nop

    // 0x800C4F88: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800C4F8C: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x800C4F90: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800C4F94: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C4F98: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800C4F9C: nop

    // 0x800C4FA0: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C4FA4: mul.s       $f16, $f8, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800C4FA8: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800C4FAC: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C4FB0: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800C4FB4: mul.s       $f18, $f2, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800C4FB8: nop

    // 0x800C4FBC: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800C4FC0: div.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800C4FC4: jal         0x800CA7A4
    // 0x800C4FC8: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    func_800CA7A4(rdram, ctx);
        goto after_7;
    // 0x800C4FC8: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    after_7:
    // 0x800C4FCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C4FD0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C4FD4: jal         0x800F23D0
    // 0x800C4FD8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800F23D0(rdram, ctx);
        goto after_8;
    // 0x800C4FD8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_8:
    // 0x800C4FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C4FE0: jal         0x800CA7E4
    // 0x800C4FE4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800CA7E4(rdram, ctx);
        goto after_9;
    // 0x800C4FE4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_9:
    // 0x800C4FE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C4FEC: jal         0x800EF04C
    // 0x800C4FF0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800EF04C(rdram, ctx);
        goto after_10;
    // 0x800C4FF0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_10:
    // 0x800C4FF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C4FF8:
    // 0x800C4FF8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4FFC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800C5000: jr          $ra
    // 0x800C5004: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800C5004: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800AAAE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AAAE0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AAAE4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AAAE8: addiu       $v0, $v0, 0x7968
    ctx->r2 = ADD32(ctx->r2, 0X7968);
    // 0x800AAAEC: addiu       $a1, $a1, 0x7938
    ctx->r5 = ADD32(ctx->r5, 0X7938);
    // 0x800AAAF0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800AAAF4:
    // 0x800AAAF4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AAAF8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AAAFC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AAB00: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800AAB04: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AAB08: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AAB0C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AAB10: nop

    // 0x800AAB14: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800AAB18: beql        $t7, $zero, L_800AAB68
    if (ctx->r15 == 0) {
        // 0x800AAB1C: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_800AAB68;
    }
    goto skip_0;
    // 0x800AAB1C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x800AAB20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AAB24: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AAB28: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AAB2C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AAB30: nop

    // 0x800AAB34: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AAB38: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AAB3C: nop

    // 0x800AAB40: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800AAB44: bne         $t7, $zero, L_800AAB5C
    if (ctx->r15 != 0) {
        // 0x800AAB48: nop
    
            goto L_800AAB5C;
    }
    // 0x800AAB48: nop

    // 0x800AAB4C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800AAB50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AAB54: b           L_800AAB74
    // 0x800AAB58: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800AAB74;
    // 0x800AAB58: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800AAB5C:
    // 0x800AAB5C: b           L_800AAB74
    // 0x800AAB60: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800AAB74;
    // 0x800AAB60: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800AAB64: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_800AAB68:
    // 0x800AAB68: nop

    // 0x800AAB6C: bltz        $t7, L_800AAB5C
    if (SIGNED(ctx->r15) < 0) {
        // 0x800AAB70: nop
    
            goto L_800AAB5C;
    }
    // 0x800AAB70: nop

L_800AAB74:
    // 0x800AAB74: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AAB78: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AAB7C: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x800AAB80: lwc1        $f8, 0x28($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800AAB84: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AAB88: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AAB8C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AAB90: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AAB94: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AAB98: nop

    // 0x800AAB9C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800AABA0: beql        $t9, $zero, L_800AABF0
    if (ctx->r25 == 0) {
        // 0x800AABA4: mfc1        $t9, $f10
        ctx->r25 = (int32_t)ctx->f10.u32l;
            goto L_800AABF0;
    }
    goto skip_1;
    // 0x800AABA4: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x800AABA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AABAC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AABB0: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800AABB4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AABB8: nop

    // 0x800AABBC: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AABC0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AABC4: nop

    // 0x800AABC8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800AABCC: bne         $t9, $zero, L_800AABE4
    if (ctx->r25 != 0) {
        // 0x800AABD0: nop
    
            goto L_800AABE4;
    }
    // 0x800AABD0: nop

    // 0x800AABD4: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800AABD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AABDC: b           L_800AABFC
    // 0x800AABE0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800AABFC;
    // 0x800AABE0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800AABE4:
    // 0x800AABE4: b           L_800AABFC
    // 0x800AABE8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800AABFC;
    // 0x800AABE8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800AABEC: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
L_800AABF0:
    // 0x800AABF0: nop

    // 0x800AABF4: bltz        $t9, L_800AABE4
    if (SIGNED(ctx->r25) < 0) {
        // 0x800AABF8: nop
    
            goto L_800AABE4;
    }
    // 0x800AABF8: nop

L_800AABFC:
    // 0x800AABFC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AAC00: sb          $t9, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r25;
    // 0x800AAC04: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800AAC08: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800AAC0C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AAC10: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800AAC14: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AAC18: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AAC1C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800AAC20: nop

    // 0x800AAC24: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800AAC28: beql        $t1, $zero, L_800AAC78
    if (ctx->r9 == 0) {
        // 0x800AAC2C: mfc1        $t1, $f18
        ctx->r9 = (int32_t)ctx->f18.u32l;
            goto L_800AAC78;
    }
    goto skip_2;
    // 0x800AAC2C: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    skip_2:
    // 0x800AAC30: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AAC34: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800AAC38: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800AAC3C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800AAC40: nop

    // 0x800AAC44: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AAC48: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800AAC4C: nop

    // 0x800AAC50: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800AAC54: bne         $t1, $zero, L_800AAC6C
    if (ctx->r9 != 0) {
        // 0x800AAC58: nop
    
            goto L_800AAC6C;
    }
    // 0x800AAC58: nop

    // 0x800AAC5C: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800AAC60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AAC64: b           L_800AAC84
    // 0x800AAC68: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_800AAC84;
    // 0x800AAC68: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_800AAC6C:
    // 0x800AAC6C: b           L_800AAC84
    // 0x800AAC70: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_800AAC84;
    // 0x800AAC70: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800AAC74: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
L_800AAC78:
    // 0x800AAC78: nop

    // 0x800AAC7C: bltz        $t1, L_800AAC6C
    if (SIGNED(ctx->r9) < 0) {
        // 0x800AAC80: nop
    
            goto L_800AAC6C;
    }
    // 0x800AAC80: nop

L_800AAC84:
    // 0x800AAC84: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AAC88: sb          $t1, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r9;
    // 0x800AAC8C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AAC90: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800AAC94: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800AAC98: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AAC9C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800AACA0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AACA4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AACA8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AACAC: nop

    // 0x800AACB0: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800AACB4: beql        $t3, $zero, L_800AAD04
    if (ctx->r11 == 0) {
        // 0x800AACB8: mfc1        $t3, $f6
        ctx->r11 = (int32_t)ctx->f6.u32l;
            goto L_800AAD04;
    }
    goto skip_3;
    // 0x800AACB8: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x800AACBC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AACC0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AACC4: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AACC8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AACCC: nop

    // 0x800AACD0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AACD4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AACD8: nop

    // 0x800AACDC: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800AACE0: bne         $t3, $zero, L_800AACF8
    if (ctx->r11 != 0) {
        // 0x800AACE4: nop
    
            goto L_800AACF8;
    }
    // 0x800AACE4: nop

    // 0x800AACE8: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800AACEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AACF0: b           L_800AAD10
    // 0x800AACF4: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_800AAD10;
    // 0x800AACF4: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_800AACF8:
    // 0x800AACF8: b           L_800AAD10
    // 0x800AACFC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_800AAD10;
    // 0x800AACFC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800AAD00: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
L_800AAD04:
    // 0x800AAD04: nop

    // 0x800AAD08: bltz        $t3, L_800AACF8
    if (SIGNED(ctx->r11) < 0) {
        // 0x800AAD0C: nop
    
            goto L_800AACF8;
    }
    // 0x800AAD0C: nop

L_800AAD10:
    // 0x800AAD10: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800AAD14: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AAD18: bne         $a1, $v0, L_800AAAF4
    if (ctx->r5 != ctx->r2) {
        // 0x800AAD1C: sb          $t3, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r11;
            goto L_800AAAF4;
    }
    // 0x800AAD1C: sb          $t3, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r11;
    // 0x800AAD20: jr          $ra
    // 0x800AAD24: nop

    return;
    // 0x800AAD24: nop

;}
RECOMP_FUNC void baduo_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800288: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080028C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800290: lw          $a0, 0x58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X58);
    // 0x80800294: jal         0x800EE7F8
    // 0x80800298: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800298: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x8080029C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002A4: jr          $ra
    // 0x808002A8: nop

    return;
    // 0x808002A8: nop

;}
RECOMP_FUNC void func_80801D54_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801D58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801D5C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801D60: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801D64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801D68: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80801D6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801D70: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80801D74: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80801D78: beq         $t6, $at, L_80801DA0
    if (ctx->r14 == ctx->r1) {
        // 0x80801D7C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801DA0;
    }
    // 0x80801D7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801D80: beq         $t6, $at, L_80801ED0
    if (ctx->r14 == ctx->r1) {
        // 0x80801D84: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801ED0;
    }
    // 0x80801D84: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801D88: beq         $t6, $at, L_80801DD0
    if (ctx->r14 == ctx->r1) {
        // 0x80801D8C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80801DD0;
    }
    // 0x80801D8C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801D90: beq         $t6, $at, L_80801E78
    if (ctx->r14 == ctx->r1) {
        // 0x80801D94: nop
    
            goto L_80801E78;
    }
    // 0x80801D94: nop

    // 0x80801D98: b           L_80801ED4
    // 0x80801D9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801ED4;
    // 0x80801D9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801DA0:
    // 0x80801DA0: jal         0x800C954C
    // 0x80801DA4: nop

    func_800C954C(rdram, ctx);
        goto after_0;
    // 0x80801DA4: nop

    after_0:
    // 0x80801DA8: bnel        $v0, $zero, L_80801ED4
    if (ctx->r2 != 0) {
        // 0x80801DAC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801ED4;
    }
    goto skip_0;
    // 0x80801DAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80801DB0: jal         0x800DA298
    // 0x80801DB4: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80801DB4: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_1:
    // 0x80801DB8: bne         $v0, $zero, L_80801ED0
    if (ctx->r2 != 0) {
        // 0x80801DBC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801ED0;
    }
    // 0x80801DBC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801DC0: jal         0x80801EE8
    // 0x80801DC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801EE8_chtrashcangame(rdram, ctx);
        goto after_2;
    // 0x80801DC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80801DC8: b           L_80801ED4
    // 0x80801DCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801ED4;
    // 0x80801DCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801DD0:
    // 0x80801DD0: lw          $v0, 0x70($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X70);
    // 0x80801DD4: sll         $a1, $v0, 22
    ctx->r5 = S32(ctx->r2 << 22);
    // 0x80801DD8: srl         $t7, $a1, 26
    ctx->r15 = S32(U32(ctx->r5) >> 26);
    // 0x80801DDC: srl         $a0, $v0, 25
    ctx->r4 = S32(U32(ctx->r2) >> 25);
    // 0x80801DE0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80801DE4: jal         0x800CC63C
    // 0x80801DE8: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    func_800CC63C(rdram, ctx);
        goto after_3;
    // 0x80801DE8: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    after_3:
    // 0x80801DEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801DF0: jal         0x8008A0B8
    // 0x80801DF4: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    _subaddiemulti_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80801DF4: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    after_4:
    // 0x80801DF8: jal         0x80088368
    // 0x80801DFC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80801DFC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_5:
    // 0x80801E00: blez        $v0, L_80801E34
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801E04: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801E34;
    }
    // 0x80801E04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80801E08:
    // 0x80801E08: jal         0x80800014
    // 0x80801E0C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_6;
    // 0x80801E0C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80801E10: addiu       $a0, $s0, 0xC3
    ctx->r4 = ADD32(ctx->r16, 0XC3);
    // 0x80801E14: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801E18: jal         0x800D2498
    // 0x80801E1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_7;
    // 0x80801E1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80801E20: jal         0x80088368
    // 0x80801E24: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80801E24: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_8:
    // 0x80801E28: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801E2C: bnel        $at, $zero, L_80801E08
    if (ctx->r1 != 0) {
        // 0x80801E30: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801E08;
    }
    goto skip_1;
    // 0x80801E30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
L_80801E34:
    // 0x80801E34: jal         0x800D90A4
    // 0x80801E38: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_9;
    // 0x80801E38: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    after_9:
    // 0x80801E3C: beq         $v0, $zero, L_80801E58
    if (ctx->r2 == 0) {
        // 0x80801E40: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2384, 0X2F98) << 16);
            goto L_80801E58;
    }
    // 0x80801E40: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2F98) << 16);
    // 0x80801E44: lwc1        $f4, 0x2F98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2F98));
    // 0x80801E48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801E4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801E50: jal         0x80108B04
    // 0x80801E54: swc1        $f4, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f4.u32l;
    func_80108B04(rdram, ctx);
        goto after_10;
    // 0x80801E54: swc1        $f4, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f4.u32l;
    after_10:
L_80801E58:
    // 0x80801E58: jal         0x800CEAD0
    // 0x80801E5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_11;
    // 0x80801E5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x80801E60: beq         $v0, $zero, L_80801ED0
    if (ctx->r2 == 0) {
        // 0x80801E64: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801ED0;
    }
    // 0x80801E64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801E68: jal         0x80801EE8
    // 0x80801E6C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80801EE8_chtrashcangame(rdram, ctx);
        goto after_12;
    // 0x80801E6C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x80801E70: b           L_80801ED4
    // 0x80801E74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801ED4;
    // 0x80801E74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801E78:
    // 0x80801E78: jal         0x80088368
    // 0x80801E7C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x80801E7C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_13:
    // 0x80801E80: blezl       $v0, L_80801ED4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801E84: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801ED4;
    }
    goto skip_2;
    // 0x80801E84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80801E88: lw          $t8, 0x20($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X20);
L_80801E8C:
    // 0x80801E8C: bnel        $s0, $t8, L_80801EA0
    if (ctx->r16 != ctx->r24) {
        // 0x80801E90: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801EA0;
    }
    goto skip_3;
    // 0x80801E90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_3:
    // 0x80801E94: jal         0x800D28A0
    // 0x80801E98: addiu       $a0, $s0, 0xC3
    ctx->r4 = ADD32(ctx->r16, 0XC3);
    func_800D28A0(rdram, ctx);
        goto after_14;
    // 0x80801E98: addiu       $a0, $s0, 0xC3
    ctx->r4 = ADD32(ctx->r16, 0XC3);
    after_14:
    // 0x80801E9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80801EA0:
    // 0x80801EA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801EA4: jal         0x80800014
    // 0x80801EA8: addiu       $s1, $s0, 0xC3
    ctx->r17 = ADD32(ctx->r16, 0XC3);
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_15;
    // 0x80801EA8: addiu       $s1, $s0, 0xC3
    ctx->r17 = ADD32(ctx->r16, 0XC3);
    after_15:
    // 0x80801EAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801EB0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801EB4: jal         0x800D2498
    // 0x80801EB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_16;
    // 0x80801EB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x80801EBC: jal         0x80088368
    // 0x80801EC0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_17;
    // 0x80801EC0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_17:
    // 0x80801EC4: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801EC8: bnel        $at, $zero, L_80801E8C
    if (ctx->r1 != 0) {
        // 0x80801ECC: lw          $t8, 0x20($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X20);
            goto L_80801E8C;
    }
    goto skip_4;
    // 0x80801ECC: lw          $t8, 0x20($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X20);
    skip_4:
L_80801ED0:
    // 0x80801ED0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801ED4:
    // 0x80801ED4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801ED8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801EDC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801EE0: jr          $ra
    // 0x80801EE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801EE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800638_chpickups(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800638: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080063C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800640: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800644: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800648: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080064C: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x80800650: bltzl       $t8, L_80800724
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800654: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800724;
    }
    goto skip_0;
    // 0x80800654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800658: lhu         $t9, 0x72($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X72);
    // 0x8080065C: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800660: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80800664: sltiu       $at, $t1, 0x5
    ctx->r1 = ctx->r9 < 0X5 ? 1 : 0;
    // 0x80800668: beq         $at, $zero, L_808006BC
    if (ctx->r1 == 0) {
        // 0x8080066C: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_808006BC;
    }
    // 0x8080066C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800670: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(700, 0X770) << 16);
    // 0x80800674: addu        $at, $at, $t1
    gpr jr_addend_8080067C = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80800678: lw          $t1, 0x770($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(700, 0X770));
    // 0x8080067C: jr          $t1
    // 0x80800680: nop

    switch (jr_addend_8080067C >> 2) {
        case 0: goto L_80800694; break;
        case 1: goto L_808006BC; break;
        case 2: goto L_808006A4; break;
        case 3: goto L_808006B4; break;
        case 4: goto L_80800684; break;
        default: switch_error(__func__, 0x8080067C, 0x80800770);
    }
    // 0x80800680: nop

L_80800684:
    // 0x80800684: jal         0x80800344
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800344_chpickups(rdram, ctx);
        goto after_0;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080068C: b           L_808006C0
    // 0x80800690: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
        goto L_808006C0;
    // 0x80800690: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
L_80800694:
    // 0x80800694: jal         0x80800364
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800364_chpickups(rdram, ctx);
        goto after_1;
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080069C: b           L_808006C0
    // 0x808006A0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
        goto L_808006C0;
    // 0x808006A0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
L_808006A4:
    // 0x808006A4: jal         0x80800528
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800528_chpickups(rdram, ctx);
        goto after_2;
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808006AC: b           L_808006C0
    // 0x808006B0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
        goto L_808006C0;
    // 0x808006B0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
L_808006B4:
    // 0x808006B4: jal         0x80800364
    // 0x808006B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800364_chpickups(rdram, ctx);
        goto after_3;
    // 0x808006B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_808006BC:
    // 0x808006BC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
L_808006C0:
    // 0x808006C0: addiu       $at, $zero, 0x1DD
    ctx->r1 = ADD32(0, 0X1DD);
    // 0x808006C4: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x808006C8: srl         $t4, $t3, 22
    ctx->r12 = S32(U32(ctx->r11) >> 22);
    // 0x808006CC: bnel        $t4, $at, L_80800724
    if (ctx->r12 != ctx->r1) {
        // 0x808006D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800724;
    }
    goto skip_1;
    // 0x808006D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808006D4: jal         0x800DA298
    // 0x808006D8: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x808006D8: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_4:
    // 0x808006DC: beq         $v0, $zero, L_808006F4
    if (ctx->r2 == 0) {
        // 0x808006E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006F4;
    }
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E4: jal         0x808005B8
    // 0x808006E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808005B8_chpickups(rdram, ctx);
        goto after_5;
    // 0x808006E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808006EC: b           L_80800724
    // 0x808006F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800724;
    // 0x808006F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006F4:
    // 0x808006F4: jal         0x80090178
    // 0x808006F8: addiu       $a0, $zero, 0x201
    ctx->r4 = ADD32(0, 0X201);
    func_80090178(rdram, ctx);
        goto after_6;
    // 0x808006F8: addiu       $a0, $zero, 0x201
    ctx->r4 = ADD32(0, 0X201);
    after_6:
    // 0x808006FC: beq         $v0, $zero, L_80800718
    if (ctx->r2 == 0) {
        // 0x80800700: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800718;
    }
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800708: jal         0x808005B8
    // 0x8080070C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808005B8_chpickups(rdram, ctx);
        goto after_7;
    // 0x8080070C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800710: b           L_80800724
    // 0x80800714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800724;
    // 0x80800714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800718:
    // 0x80800718: jal         0x808005B8
    // 0x8080071C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808005B8_chpickups(rdram, ctx);
        goto after_8;
    // 0x8080071C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800724:
    // 0x80800724: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800728: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080072C: jr          $ra
    // 0x80800730: nop

    return;
    // 0x80800730: nop

;}
RECOMP_FUNC void func_8009919C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009919C: lw          $t6, 0xB8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB8);
    // 0x800991A0: sw          $a1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r5;
    // 0x800991A4: lw          $t7, 0xB8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB8);
    // 0x800991A8: jr          $ra
    // 0x800991AC: sw          $a2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r6;
    return;
    // 0x800991AC: sw          $a2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r6;
;}
RECOMP_FUNC void chlagoonufoint_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080072C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(748, 0X1A28) << 16);
    // 0x80800730: jr          $ra
    // 0x80800734: addiu       $v0, $v0, 0x1A28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X1A28));
    return;
    // 0x80800734: addiu       $v0, $v0, 0x1A28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X1A28));
;}
RECOMP_FUNC void _bsfirstp_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800842E0: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x800842E0);
    return;
    // 0x800842E4: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_8009C21C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C21C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C224: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009C228: lw          $a2, 0xE4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE4);
    // 0x8009C22C: addiu       $a0, $a2, 0x18
    ctx->r4 = ADD32(ctx->r6, 0X18);
    // 0x8009C230: jal         0x800EE7F8
    // 0x8009C234: addiu       $a1, $a2, 0xC
    ctx->r5 = ADD32(ctx->r6, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009C234: addiu       $a1, $a2, 0xC
    ctx->r5 = ADD32(ctx->r6, 0XC);
    after_0:
    // 0x8009C238: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8009C23C: lw          $a2, 0xE4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XE4);
    // 0x8009C240: addiu       $a0, $a2, 0xC
    ctx->r4 = ADD32(ctx->r6, 0XC);
    // 0x8009C244: jal         0x800EE7F8
    // 0x8009C248: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8009C248: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
    // 0x8009C24C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C254: jr          $ra
    // 0x8009C258: nop

    return;
    // 0x8009C258: nop

;}
RECOMP_FUNC void chtntblockage_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(900, 0X240) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x240
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(900, 0X240));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x240
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(900, 0X240));
;}
RECOMP_FUNC void func_808003B0_chstinger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808003B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003B8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808003BC: jal         0x800EA068
    // 0x808003C0: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    func_800EA068(rdram, ctx);
        goto after_0;
    // 0x808003C0: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_0:
    // 0x808003C4: beq         $v0, $zero, L_8080040C
    if (ctx->r2 == 0) {
        // 0x808003C8: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_8080040C;
    }
    // 0x808003C8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808003CC: jal         0x80800264
    // 0x808003D0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80800264_chstinger(rdram, ctx);
        goto after_1;
    // 0x808003D0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x808003D4: bltz        $v0, L_8080040C
    if (SIGNED(ctx->r2) < 0) {
        // 0x808003D8: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_8080040C;
    }
    // 0x808003D8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808003DC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808003E0: jal         0x80100094
    // 0x808003E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808003E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808003E8: lb          $a1, 0x0($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X0);
    // 0x808003EC: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x808003F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808003F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808003F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808003FC: jal         0x800F7A7C
    // 0x80800400: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800F7A7C(rdram, ctx);
        goto after_3;
    // 0x80800400: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_3:
    // 0x80800404: b           L_80800410
    // 0x80800408: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800410;
    // 0x80800408: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080040C:
    // 0x8080040C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800410:
    // 0x80800410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800414: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800418: jr          $ra
    // 0x8080041C: nop

    return;
    // 0x8080041C: nop

;}
RECOMP_FUNC void func_80800084_basnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800088: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(604, 0X1020) << 16);
    // 0x8080008C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800090: jr          $ra
    // 0x80800094: lwc1        $f0, 0x1020($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X1020));
    return;
    // 0x80800094: lwc1        $f0, 0x1020($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X1020));
;}
RECOMP_FUNC void func_8008AFCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AFCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008AFD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008AFD4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008AFD8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008AFDC: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x8008AFE0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8008AFE4: addiu       $s0, $s1, 0x1C
    ctx->r16 = ADD32(ctx->r17, 0X1C);
    // 0x8008AFE8: sll         $t8, $t6, 26
    ctx->r24 = S32(ctx->r14 << 26);
    // 0x8008AFEC: bgezl       $t8, L_8008B03C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8008AFF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8008B03C;
    }
    goto skip_0;
    // 0x8008AFF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8008AFF4: lbu         $t9, 0x1B($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1B);
    // 0x8008AFF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008AFFC: addiu       $s0, $s1, 0x1C
    ctx->r16 = ADD32(ctx->r17, 0X1C);
    // 0x8008B000: srl         $t0, $t9, 7
    ctx->r8 = S32(U32(ctx->r25) >> 7);
    // 0x8008B004: bne         $t0, $at, L_8008B024
    if (ctx->r8 != ctx->r1) {
        // 0x8008B008: lui         $a1, 0x3F7F
        ctx->r5 = S32(0X3F7F << 16);
            goto L_8008B024;
    }
    // 0x8008B008: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x8008B00C: addiu       $s0, $a0, 0x1C
    ctx->r16 = ADD32(ctx->r4, 0X1C);
    // 0x8008B010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008B014: jal         0x8008C1C0
    // 0x8008B018: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8008C1C0(rdram, ctx);
        goto after_0;
    // 0x8008B018: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x8008B01C: b           L_8008B044
    // 0x8008B020: nop

        goto L_8008B044;
    // 0x8008B020: nop

L_8008B024:
    // 0x8008B024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008B028: jal         0x8008C1C0
    // 0x8008B02C: ori         $a1, $a1, 0xFFEF
    ctx->r5 = ctx->r5 | 0XFFEF;
    func_8008C1C0(rdram, ctx);
        goto after_1;
    // 0x8008B02C: ori         $a1, $a1, 0xFFEF
    ctx->r5 = ctx->r5 | 0XFFEF;
    after_1:
    // 0x8008B030: b           L_8008B044
    // 0x8008B034: nop

        goto L_8008B044;
    // 0x8008B034: nop

    // 0x8008B038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8008B03C:
    // 0x8008B03C: jal         0x8008C1C0
    // 0x8008B040: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    func_8008C1C0(rdram, ctx);
        goto after_2;
    // 0x8008B040: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    after_2:
L_8008B044:
    // 0x8008B044: jal         0x8008C0C8
    // 0x8008B048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008C0C8(rdram, ctx);
        goto after_3;
    // 0x8008B048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8008B04C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x8008B050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B054: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8008B058: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8008B05C: jr          $ra
    // 0x8008B060: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8008B060: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80114444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80114448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011444C: jal         0x800F5410
    // 0x80114450: nop

    func_800F5410(rdram, ctx);
        goto after_0;
    // 0x80114450: nop

    after_0:
    // 0x80114454: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80114458: bne         $v0, $at, L_8011446C
    if (ctx->r2 != ctx->r1) {
        // 0x8011445C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8011446C;
    }
    // 0x8011445C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80114460: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80114464: b           L_80114474
    // 0x80114468: lwc1        $f0, 0x65E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X65E4);
        goto L_80114474;
    // 0x80114468: lwc1        $f0, 0x65E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X65E4);
L_8011446C:
    // 0x8011446C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80114470: lwc1        $f0, 0x65E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X65E8);
L_80114474:
    // 0x80114474: jr          $ra
    // 0x80114478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80114478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800CAB70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAB70: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800CAB74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800CAB78: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CAB7C: addiu       $t0, $a0, 0x24
    ctx->r8 = ADD32(ctx->r4, 0X24);
    // 0x800CAB80: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
L_800CAB84:
    // 0x800CAB84: lwc1        $f0, 0x24($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X24);
    // 0x800CAB88: lwc1        $f12, 0x28($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X28);
    // 0x800CAB8C: lwc1        $f16, 0x2C($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x800CAB90: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x800CAB94: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x800CAB98: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x800CAB9C: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x800CABA0: bc1fl       L_800CABB4
    if (!c1cs) {
        // 0x800CABA4: lh          $v0, 0x0($a2)
        ctx->r2 = MEM_H(ctx->r6, 0X0);
            goto L_800CABB4;
    }
    goto skip_0;
    // 0x800CABA4: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    skip_0:
    // 0x800CABA8: b           L_800CABB4
    // 0x800CABAC: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
        goto L_800CABB4;
    // 0x800CABAC: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
    // 0x800CABB0: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
L_800CABB4:
    // 0x800CABB4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800CABB8: c.le.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl <= ctx->f12.fl;
    // 0x800CABBC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CABC0: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800CABC4: bc1fl       L_800CABD8
    if (!c1cs) {
        // 0x800CABC8: lh          $v0, 0x2($a2)
        ctx->r2 = MEM_H(ctx->r6, 0X2);
            goto L_800CABD8;
    }
    goto skip_1;
    // 0x800CABC8: lh          $v0, 0x2($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X2);
    skip_1:
    // 0x800CABCC: b           L_800CABD8
    // 0x800CABD0: lh          $v0, 0x2($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X2);
        goto L_800CABD8;
    // 0x800CABD0: lh          $v0, 0x2($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X2);
    // 0x800CABD4: lh          $v0, 0x2($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X2);
L_800CABD8:
    // 0x800CABD8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800CABDC: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x800CABE0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CABE4: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800CABE8: bc1fl       L_800CABFC
    if (!c1cs) {
        // 0x800CABEC: lh          $v0, 0x4($a2)
        ctx->r2 = MEM_H(ctx->r6, 0X4);
            goto L_800CABFC;
    }
    goto skip_2;
    // 0x800CABEC: lh          $v0, 0x4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4);
    skip_2:
    // 0x800CABF0: b           L_800CABFC
    // 0x800CABF4: lh          $v0, 0x4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X4);
        goto L_800CABFC;
    // 0x800CABF4: lh          $v0, 0x4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X4);
    // 0x800CABF8: lh          $v0, 0x4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4);
L_800CABFC:
    // 0x800CABFC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800CAC00: add.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800CAC04: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x800CAC08: addiu       $t0, $t0, 0x20
    ctx->r8 = ADD32(ctx->r8, 0X20);
    // 0x800CAC0C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CAC10: mul.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x800CAC14: add.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x800CAC18: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800CAC1C: c.le.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl <= ctx->f6.fl;
    // 0x800CAC20: nop

    // 0x800CAC24: bc1fl       L_800CAC38
    if (!c1cs) {
        // 0x800CAC28: lwc1        $f0, 0x34($a3)
        ctx->f0.u32l = MEM_W(ctx->r7, 0X34);
            goto L_800CAC38;
    }
    goto skip_3;
    // 0x800CAC28: lwc1        $f0, 0x34($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X34);
    skip_3:
    // 0x800CAC2C: jr          $ra
    // 0x800CAC30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CAC30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CAC34: lwc1        $f0, 0x34($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X34);
L_800CAC38:
    // 0x800CAC38: lwc1        $f2, 0x38($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X38);
    // 0x800CAC3C: lwc1        $f14, 0x3C($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x800CAC40: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x800CAC44: addiu       $a0, $a3, 0x34
    ctx->r4 = ADD32(ctx->r7, 0X34);
    // 0x800CAC48: bc1fl       L_800CAC5C
    if (!c1cs) {
        // 0x800CAC4C: lh          $v0, 0x0($a2)
        ctx->r2 = MEM_H(ctx->r6, 0X0);
            goto L_800CAC5C;
    }
    goto skip_4;
    // 0x800CAC4C: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    skip_4:
    // 0x800CAC50: b           L_800CAC5C
    // 0x800CAC54: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
        goto L_800CAC5C;
    // 0x800CAC54: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
    // 0x800CAC58: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
L_800CAC5C:
    // 0x800CAC5C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800CAC60: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x800CAC64: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CAC68: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800CAC6C: bc1fl       L_800CAC80
    if (!c1cs) {
        // 0x800CAC70: lh          $v0, 0x2($a2)
        ctx->r2 = MEM_H(ctx->r6, 0X2);
            goto L_800CAC80;
    }
    goto skip_5;
    // 0x800CAC70: lh          $v0, 0x2($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X2);
    skip_5:
    // 0x800CAC74: b           L_800CAC80
    // 0x800CAC78: lh          $v0, 0x2($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X2);
        goto L_800CAC80;
    // 0x800CAC78: lh          $v0, 0x2($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X2);
    // 0x800CAC7C: lh          $v0, 0x2($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X2);
L_800CAC80:
    // 0x800CAC80: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800CAC84: c.le.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl <= ctx->f14.fl;
    // 0x800CAC88: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CAC8C: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800CAC90: bc1fl       L_800CACA4
    if (!c1cs) {
        // 0x800CAC94: lh          $v0, 0x4($a2)
        ctx->r2 = MEM_H(ctx->r6, 0X4);
            goto L_800CACA4;
    }
    goto skip_6;
    // 0x800CAC94: lh          $v0, 0x4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4);
    skip_6:
    // 0x800CAC98: b           L_800CACA4
    // 0x800CAC9C: lh          $v0, 0x4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X4);
        goto L_800CACA4;
    // 0x800CAC9C: lh          $v0, 0x4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X4);
    // 0x800CACA0: lh          $v0, 0x4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4);
L_800CACA4:
    // 0x800CACA4: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800CACA8: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800CACAC: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800CACB0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CACB4: mul.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x800CACB8: add.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x800CACBC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800CACC0: c.le.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl <= ctx->f8.fl;
    // 0x800CACC4: nop

    // 0x800CACC8: bc1f        L_800CACD8
    if (!c1cs) {
        // 0x800CACCC: nop
    
            goto L_800CACD8;
    }
    // 0x800CACCC: nop

    // 0x800CACD0: jr          $ra
    // 0x800CACD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CACD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CACD8:
    // 0x800CACD8: bne         $v1, $t1, L_800CAB84
    if (ctx->r3 != ctx->r9) {
        // 0x800CACDC: addiu       $a3, $a3, 0x20
        ctx->r7 = ADD32(ctx->r7, 0X20);
            goto L_800CAB84;
    }
    // 0x800CACDC: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x800CACE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CACE4: jr          $ra
    // 0x800CACE8: nop

    return;
    // 0x800CACE8: nop

;}
RECOMP_FUNC void func_80108A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108A8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80108A90: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80108A94: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80108A98: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80108A9C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80108AA0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80108AA4: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80108AA8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80108AAC: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80108AB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108AB4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80108AB8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80108ABC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80108AC0: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80108AC4: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80108AC8: jal         0x80108474
    // 0x80108ACC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    func_80108474(rdram, ctx);
        goto after_0;
    // 0x80108ACC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80108AD0: beq         $v0, $zero, L_80108AF4
    if (ctx->r2 == 0) {
        // 0x80108AD4: lwc1        $f0, 0x20($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
            goto L_80108AF4;
    }
    // 0x80108AD4: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80108AD8: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x80108ADC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80108AE0: lhu         $t1, 0x76($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X76);
    // 0x80108AE4: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x80108AE8: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x80108AEC: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80108AF0: sh          $t3, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r11;
L_80108AF4:
    // 0x80108AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80108AF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80108AFC: jr          $ra
    // 0x80108B00: nop

    return;
    // 0x80108B00: nop

;}
RECOMP_FUNC void func_800DC310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC310: lui         $t6, 0xEA
    ctx->r14 = S32(0XEA << 16);
    // 0x800DC314: ori         $t6, $t6, 0xA0C7
    ctx->r14 = ctx->r14 | 0XA0C7;
    // 0x800DC318: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DC31C: jr          $ra
    // 0x800DC320: sw          $t6, -0x3810($at)
    MEM_W(-0X3810, ctx->r1) = ctx->r14;
    return;
    // 0x800DC320: sw          $t6, -0x3810($at)
    MEM_W(-0X3810, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void heap_init_empty_block(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A7B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001A7B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001A7B8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001A7BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001A7C0: lbu         $t6, 0xF($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XF);
    // 0x8001A7C4: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8001A7C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001A7CC: andi        $t8, $t6, 0xFF3F
    ctx->r24 = ctx->r14 & 0XFF3F;
    // 0x8001A7D0: andi        $t0, $t8, 0xF7
    ctx->r8 = ctx->r24 & 0XF7;
    // 0x8001A7D4: sb          $t8, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r24;
    // 0x8001A7D8: andi        $t2, $t0, 0xFB
    ctx->r10 = ctx->r8 & 0XFB;
    // 0x8001A7DC: sb          $t0, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r8;
    // 0x8001A7E0: sb          $t2, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r10;
    // 0x8001A7E4: andi        $t3, $t2, 0xFC
    ctx->r11 = ctx->r10 & 0XFC;
    // 0x8001A7E8: sb          $t3, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r11;
    // 0x8001A7EC: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8001A7F0: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x8001A7F4: slti        $at, $t8, 0x2710
    ctx->r1 = SIGNED(ctx->r24) < 0X2710 ? 1 : 0;
    // 0x8001A7F8: srl         $t4, $v0, 8
    ctx->r12 = S32(U32(ctx->r2) >> 8);
    // 0x8001A7FC: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x8001A800: xor         $t6, $t5, $v0
    ctx->r14 = ctx->r13 ^ ctx->r2;
    // 0x8001A804: beq         $at, $zero, L_8001A840
    if (ctx->r1 == 0) {
        // 0x8001A808: sw          $t6, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->r14;
            goto L_8001A840;
    }
    // 0x8001A808: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x8001A80C: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8001A810: addiu       $s1, $s1, -0x1670
    ctx->r17 = ADD32(ctx->r17, -0X1670);
    // 0x8001A814: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8001A818: sw          $t9, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r25;
    // 0x8001A81C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8001A820: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x8001A824: sw          $t1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r9;
    // 0x8001A828: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8001A82C: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x8001A830: sw          $a0, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r4;
    // 0x8001A834: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8001A838: b           L_8001A898
    // 0x8001A83C: sw          $a0, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r4;
        goto L_8001A898;
    // 0x8001A83C: sw          $a0, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r4;
L_8001A840:
    // 0x8001A840: jal         0x8001B3E8
    // 0x8001A844: nop

    heap_bytes_allocated(rdram, ctx);
        goto after_0;
    // 0x8001A844: nop

    after_0:
    // 0x8001A848: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8001A84C: addiu       $s1, $s1, -0x1670
    ctx->r17 = ADD32(ctx->r17, -0X1670);
    // 0x8001A850: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8001A854: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8001A858: lw          $t7, -0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X10);
    // 0x8001A85C: jal         0x8001B3E8
    // 0x8001A860: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
    heap_bytes_allocated(rdram, ctx);
        goto after_1;
    // 0x8001A860: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
    after_1:
    // 0x8001A864: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8001A868: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8001A86C: addiu       $t0, $t9, -0x20
    ctx->r8 = ADD32(ctx->r25, -0X20);
    // 0x8001A870: jal         0x8001B3E8
    // 0x8001A874: sw          $t0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r8;
    heap_bytes_allocated(rdram, ctx);
        goto after_2;
    // 0x8001A874: sw          $t0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r8;
    after_2:
    // 0x8001A878: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8001A87C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8001A880: lw          $t3, -0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X10);
    // 0x8001A884: jal         0x8001B3E8
    // 0x8001A888: sw          $s0, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r16;
    heap_bytes_allocated(rdram, ctx);
        goto after_3;
    // 0x8001A888: sw          $s0, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r16;
    after_3:
    // 0x8001A88C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8001A890: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8001A894: sw          $s0, -0x10($t5)
    MEM_W(-0X10, ctx->r13) = ctx->r16;
L_8001A898:
    // 0x8001A898: jal         0x8001A6EC
    // 0x8001A89C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    heap_update_empty_block(rdram, ctx);
        goto after_4;
    // 0x8001A89C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8001A8A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A8A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001A8A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001A8AC: jr          $ra
    // 0x8001A8B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001A8B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _mlspline_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089138: syscall     762
    recomp_syscall_handler(rdram, ctx, 0x80089138);
    return;
    // 0x8008913C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80800AF0_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AF8: jal         0x80800448
    // 0x80800AFC: nop

    bstrexsmall_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800AFC: nop

    after_0:
    // 0x80800B00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B08: jr          $ra
    // 0x80800B0C: nop

    return;
    // 0x80800B0C: nop

;}
RECOMP_FUNC void func_80800DF8_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DF8: jr          $ra
    // 0x80800DFC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800DFC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80801CFC_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CFC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80801D00: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80801D04: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80801D08: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801D0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801D10: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x80801D14: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80801D18: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80801D1C: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80801D20: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80801D24: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80801D28: jal         0x801018A4
    // 0x80801D2C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    func_801018A4(rdram, ctx);
        goto after_0;
    // 0x80801D2C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    after_0:
    // 0x80801D30: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x80801D34: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80801D38: bgezl       $t8, L_80801DF8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801D3C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80801DF8;
    }
    goto skip_0;
    // 0x80801D3C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x80801D40: jal         0x800D674C
    // 0x80801D44: addiu       $a0, $zero, 0x9E2
    ctx->r4 = ADD32(0, 0X9E2);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x80801D44: addiu       $a0, $zero, 0x9E2
    ctx->r4 = ADD32(0, 0X9E2);
    after_1:
    // 0x80801D48: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D50: jal         0x80100094
    // 0x80801D54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80801D54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80801D58: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80801D5C: jal         0x800E2588
    // 0x80801D60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800E2588(rdram, ctx);
        goto after_3;
    // 0x80801D60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80801D64: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80801D68: jal         0x800E2594
    // 0x80801D6C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800E2594(rdram, ctx);
        goto after_4;
    // 0x80801D6C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80801D70: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801D74: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x80801D78: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x80801D7C: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x80801D80: addiu       $s3, $sp, 0x50
    ctx->r19 = ADD32(ctx->r29, 0X50);
L_80801D84:
    // 0x80801D84: lbu         $t9, 0xF0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XF0);
    // 0x80801D88: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80801D8C: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x80801D90: bne         $s5, $t9, L_80801DE0
    if (ctx->r21 != ctx->r25) {
        // 0x80801D94: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80801DE0;
    }
    // 0x80801D94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801D98: lwc1        $f0, 0xAC($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0XAC);
    // 0x80801D9C: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x80801DA0: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x80801DA4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80801DA8: addu        $s2, $s4, $t2
    ctx->r18 = ADD32(ctx->r20, ctx->r10);
    // 0x80801DAC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801DB0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801DB4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80801DB8: jal         0x800EFA4C
    // 0x80801DBC: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x80801DBC: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    after_5:
    // 0x80801DC0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80801DC4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80801DC8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80801DCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801DD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801DD4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80801DD8: jal         0x800E2720
    // 0x80801DDC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_800E2720(rdram, ctx);
        goto after_6;
    // 0x80801DDC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_6:
L_80801DE0:
    // 0x80801DE0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801DE4: bne         $s0, $s6, L_80801D84
    if (ctx->r16 != ctx->r22) {
        // 0x80801DE8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80801D84;
    }
    // 0x80801DE8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801DEC: jal         0x800E2A14
    // 0x80801DF0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800E2A14(rdram, ctx);
        goto after_7;
    // 0x80801DF0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_7:
    // 0x80801DF4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80801DF8:
    // 0x80801DF8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801DFC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801E00: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80801E04: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80801E08: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80801E0C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80801E10: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80801E14: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80801E18: jr          $ra
    // 0x80801E1C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80801E1C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_808003F4_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808003F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003FC: jal         0x8009FBB0
    // 0x80800400: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_8009FBB0(rdram, ctx);
        goto after_0;
    // 0x80800400: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_0:
    // 0x80800404: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80800408: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080040C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800410: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800414: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800418: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8080041C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800420: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800424: jal         0x800BA930
    // 0x80800428: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800BA930(rdram, ctx);
        goto after_1;
    // 0x80800428: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_1:
    // 0x8080042C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800430: jal         0x800BA22C
    // 0x80800434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_2;
    // 0x80800434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800438: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080043C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800440: jr          $ra
    // 0x80800444: nop

    return;
    // 0x80800444: nop

;}
